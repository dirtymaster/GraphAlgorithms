//
// Created by Curran Carr on 10/30/22.
//

#ifndef A2_SIMPLENAVIGATOR_V1_0_0_MASTER_TSMBRANCHANDBOUNDSOLVER_H
#define A2_SIMPLENAVIGATOR_V1_0_0_MASTER_TSMBRANCHANDBOUNDSOLVER_H

#include <vector>

#include "../../DataStructures/Matrix/Matrix.h"
#include "../AbstractTSMSolver.h"

namespace s21 {

class TSMBranchAndBoundSolver : public AbstractTSMSolver {
public:
    TSMBranchAndBoundSolver(S21Matrix &matrix);
    TsmResult GetAnswer();

private:
    int nmb_of_graph_;
    double final_res_;
    std::vector<bool> visited_;
    std::vector<int> final_path_;

    void TSP();
    void CopyToFinal(std::vector<int> &curr_path);
    int FirstMin(int i);
    int SecondMin(int i);
    void TSPRec(int curr_bound, int curr_weight, int level, std::vector<int> &curr_path);
};

}  // namespace s21
#endif  // A2_SIMPLENAVIGATOR_V1_0_0_MASTER_TSMBRANCHANDBOUNDSOLVER_H
