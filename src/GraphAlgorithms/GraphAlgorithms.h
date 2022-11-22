#ifndef A2_SIMPLENAVIGATOR_V1_0_0_MASTER_GRAPHALGORITHMS_H
#define A2_SIMPLENAVIGATOR_V1_0_0_MASTER_GRAPHALGORITHMS_H

#include <set>
#include <vector>

#include "../DataStructures/Queue/Queue.h"
#include "../DataStructures/Stack/Stack.h"
#include "../Graph/Graph.h"
#include "../GraphAlgorithms/TSMBruteForce.h"
#include "AntAlgorithmForTSM/TSMAntAlgorithmSolver.h"
#include "BranchAndBoundAlgorithmForTSM/TSMBranchAndBoundSolver.h"

namespace s21 {

enum Status { WRONG_VERTEX_NUMBER = -1, EMPTY_GRAPH_ERROR = -2, OUT_OF_RANGE = -3 };

enum SearchType { DepthFirstSearch = 1, BreadthFirstSearch = 2 };

class GraphAlgorithms {
public:
    std::vector<int> DepthFirstSearch(Graph &graph, int start_vertex);
    std::vector<int> BreadthFirstSearch(Graph &graph, int start_vertex);

    int GetShortestPathBetweenVertices(Graph &graph, int vertex1, int vertex2);
    S21Matrix GetShortestPathsBetweenAllVertices(Graph &graph);
    S21Matrix GetLeastSpanningTree(Graph &graph);
    TsmResult SolveTravelingSalesmanProblem(Graph &graph);
    TsmResult SolveTSMBruteForceMethod(Graph &graph);
    TsmResult SolveTSMBranchAndBoundMethod(Graph &graph);

private:
    AbstractList *list;
    void debug_print_vector(std::vector<int> vector);
    void debug_print_stack(Stack stack);
    std::vector<int> SearchAlgo(Graph &graph, int start_vertex, SearchType search_type);
    int big_number_ = 1000000;
};

}  // namespace s21

#endif  // A2_SIMPLENAVIGATOR_V1_0_0_MASTER_GRAPHALGORITHMS_H
