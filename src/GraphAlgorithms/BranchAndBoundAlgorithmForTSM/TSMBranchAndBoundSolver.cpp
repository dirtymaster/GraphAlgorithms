

#include "TSMBranchAndBoundSolver.h"

namespace s21 {

TsmResult TSMBranchAndBoundSolver::GetAnswer() {
    TSP();
    return {final_path_, final_res_};
}

TSMBranchAndBoundSolver::TSMBranchAndBoundSolver(S21Matrix &matrix) : AbstractTSMSolver(matrix) {
    matrix_ = matrix;
    nmb_of_graph_ = matrix_.get_rows();
    final_path_ = std::vector<int>(nmb_of_graph_ + 1);
    visited_ = std::vector<bool>(nmb_of_graph_ + 1, false);
    final_res_ = INT32_MAX;
}

void TSMBranchAndBoundSolver::CopyToFinal(std::vector<int> &curr_path) {
    for (int i = 0; i < curr_path.size(); ++i) {
        final_path_[i] = curr_path[i] + 1;
    }
    final_path_[nmb_of_graph_] = curr_path[0] + 1;
}

int TSMBranchAndBoundSolver::FirstMin(int i) {
    int min = INT32_MAX;
    for (int j = 0; j < nmb_of_graph_; ++j) {
        if (matrix_(i, j) < min && i != j) {
            min = matrix_(i, j);
        }
    }
    return min;
}

int TSMBranchAndBoundSolver::SecondMin(int i) {
    int first = INT32_MAX, second = INT32_MAX;
    for (int j = 0; j < nmb_of_graph_; ++j) {
        if (i == j) continue;

        if (matrix_(i, j) <= first) {
            second = first;
            first = matrix_(i, j);
        } else if (matrix_(i, j) <= second && matrix_(i, j) != first) {
            second = matrix_(i, j);
        }
    }
    return second;
}

void TSMBranchAndBoundSolver::TSPRec(int curr_bound, int curr_weight, int level,
                                     std::vector<int> &curr_path) {
    if (level == nmb_of_graph_) {
        if (matrix_(curr_path[level - 1], curr_path[0]) != 0) {
            int curr_res = curr_weight + matrix_(curr_path[level - 1], curr_path[0]);
            if (curr_res < final_res_) {
                CopyToFinal(curr_path);
                final_res_ = curr_res;
            }
        }
        return;
    }

    for (int i = 0; i < nmb_of_graph_; ++i) {
        if (matrix_(curr_path[level - 1], i) != 0 && !visited_[i]) {
            int temp = curr_bound;
            curr_weight += matrix_(curr_path[level - 1], i);

            if (level == 1) {
                curr_bound -= ((FirstMin(curr_path[level - 1]) + FirstMin(i)) / 2);
            } else {
                curr_bound -= ((SecondMin(curr_path[level - 1]) + FirstMin(i)) / 2);
            }

            if (curr_bound + curr_weight < final_res_) {
                curr_path[level] = i;
                visited_[i] = true;
                TSPRec(curr_bound, curr_weight, level + 1, curr_path);
            }

            curr_weight -= matrix_(curr_path[level - 1], i);
            curr_bound = temp;

            for (auto it = visited_.begin(); it != visited_.end(); it++) {
                *it = false;
            }

            for (int j = 0; j <= level - 1; ++j) {
                visited_[curr_path[j]] = true;
            }
        }
    }
}

void TSMBranchAndBoundSolver::TSP() {
    std::vector<int> curr_path = std::vector<int>(nmb_of_graph_, -1);
    int curr_bound = 0;

    for (int i = 0; i < nmb_of_graph_; ++i) {
        curr_bound += (FirstMin(i) + SecondMin(i));
    }

    if (curr_bound == 1) {
        curr_bound = curr_bound / 2 + 1;
    } else {
        curr_bound = curr_bound / 2;
    }

    visited_[0] = true;
    curr_path[0] = 0;

    TSPRec(curr_bound, 0, 1, curr_path);
}

}  // namespace s21