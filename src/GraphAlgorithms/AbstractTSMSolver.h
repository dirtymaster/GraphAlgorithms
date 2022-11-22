#pragma once
#include <vector>

#include "../DataStructures/Matrix/Matrix.h"

namespace s21 {
struct TsmResult {
    std::vector<int> vertices;
    double distance;

    TsmResult() = default;

    TsmResult(std::vector<int> path, double distance) {
        this->distance = distance;
        vertices = path;
    }
};

class AbstractTSMSolver {
public:
    AbstractTSMSolver(S21Matrix &matrix) : matrix_(matrix) { FillEmptyElements(); }
    virtual TsmResult GetAnswer() = 0;
    virtual ~AbstractTSMSolver() {}

protected:
    S21Matrix &matrix_;

    void FillEmptyElements() {
        double max = matrix_(0, 0);
        for (int i = 0; i < matrix_.get_rows(); i++) {
            for (int j = 0; j < matrix_.get_cols(); j++) {
                max = std::max(max, matrix_(i, j));
            }
        }
        for (int i = 0; i < matrix_.get_rows(); i++) {
            for (int j = 0; j < matrix_.get_cols(); j++) {
                if (i != j && matrix_(i, j) == 0.0) {
                    matrix_(i, j) = max;
                    max += 5.0;
                }
            }
        }
    }
};
}  // namespace s21
