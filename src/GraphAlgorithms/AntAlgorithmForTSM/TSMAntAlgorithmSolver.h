#ifndef GRAPHALGORITHMSCPP_ANTALGORITHMFORTSM_H
#define GRAPHALGORITHMSCPP_ANTALGORITHMFORTSM_H

#include <set>
#include <vector>

#include "../../DataStructures/Matrix/Matrix.h"
#include "../AbstractTSMSolver.h"

namespace s21 {

class TSMAntAlgorithmSolver : public AbstractTSMSolver {
public:
    TSMAntAlgorithmSolver(S21Matrix &matrix);
    TsmResult GetAnswer();

private:
    S21Matrix pheromones_, pheromones_delta_, event_;
    double count_of_nodes_, max_length_;
    TsmResult shortest_path_;

    void MainIteration();
    void ApplyDeltaToPheromones();
    TsmResult AntColonyAlgorithm();
    double GetEventPossibility(int rows, int cols, std::set<int> &nodes);
    int GetNextNode(int cur_pos, std::set<int> &nodes);
    double LastPositiveEvent(std::vector<double> &event_vec, int j);
    void IncreaseDelta(int path_of_cur, std::vector<int> &visited);
    TsmResult GetFullPath(std::vector<int> &visited);
    TsmResult GetShortestPath(int vertex1, int vertex2);
};
}  // namespace s21

#endif  // GRAPHALGORITHMSCPP_ANTALGORITHMFORTSM_H
