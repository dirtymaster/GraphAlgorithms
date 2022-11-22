#ifndef GRAPHALGORITHMSCPP_TSMBRUTEFORCE_H
#define GRAPHALGORITHMSCPP_TSMBRUTEFORCE_H

#include <algorithm>

#include "AbstractTSMSolver.h"

namespace s21 {
class TSMBruteForce : public AbstractTSMSolver {
public:
    TSMBruteForce(S21Matrix &matrix) : AbstractTSMSolver(matrix) {}
    TsmResult GetAnswer() { return BruteForceMethod(); };

private:
    TsmResult BruteForceMethod() {
        std::vector<int> vertex, min_path;
        for (int i = 1; i < matrix_.get_cols(); ++i) {
            vertex.push_back(i);
        }
        int min_weight = std::numeric_limits<int>::max();
        while (std::next_permutation(vertex.begin(), vertex.end())) {
            int cur_weight = 0;
            std::vector<int> cur_path;
            int k = 0;
            for (size_t i = 0; i < vertex.size(); i++) {
                cur_weight += matrix_(k, vertex[i]);
                cur_path.push_back(k + 1);
                k = vertex[i];
            }
            cur_weight += matrix_(k, 0);
            cur_path.push_back(k + 1);
            if (min_weight > cur_weight) {
                min_weight = cur_weight;
                min_path = cur_path;
            }
        }
        min_path.push_back(1);
        return TsmResult(min_path, min_weight);
    }
};
}  // namespace s21

#endif  // GRAPHALGORITHMSCPP_TSMBRUTEFORCE_H
