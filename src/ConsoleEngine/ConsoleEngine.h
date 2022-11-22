#ifndef A2_SIMPLENAVIGATOR_V1_0_0_MASTER_CONSOLEENGINE_H
#define A2_SIMPLENAVIGATOR_V1_0_0_MASTER_CONSOLEENGINE_H

#include <ctime>
#include <iostream>

#include "../Graph/Graph.h"
#include "../GraphAlgorithms/GraphAlgorithms.h"

namespace s21 {

using std::cin;
using std::cout;
using std::endl;

class ConsoleEngine {
public:
    ConsoleEngine();
    void start();

private:
    Graph graph_;
    GraphAlgorithms graph_algorithms_;
    std::string read_path_, write_path_;

    int RequestNmbFromUser(std::string message);

    void PrintResultVector(std::vector<int> result);
    void PrintTSM(TsmResult result);
    void PrintResultMatrix(S21Matrix result);
    void PrintResultInt(int result);

    void ResearchTSMAlgorithmsPerformance(Graph &graph, int count);

    enum MenuOptions {
        EXIT = 0,
        LOAD_GRAPH_FROM_FILE = 1,
        PERFORM_DFS = 2,
        PERFORM_BFS = 3,
        FIND_SHORTEST_PATH_BETWEEN_TWO_V = 4,
        FIND_SHORTEST_PATH_BETWEEN_ALL_V = 5,
        FIND_MINIMAL_SPANNING_TREE = 6,
        SOLVE_TSM_ANT_METHOD = 7,
        DO_RESEARCH_ON_TSM_ALGORITHMS = 8,
        WRITE_GRAPH_TO_FILE = 9
    };

    std::string menu_options_ =
        ("Menu options:\n"
         "\t 1. Load graph from a file.\n"
         "\t 2. Perform a depth traversal of the graph.\n"
         "\t 3. Perform a breadth traversal of the graph.\n"
         "\t 4. Search the shortest path between any two vertices of the graph.\n"
         "\t 5. Search shortest paths between all pairs of vertices of the graph.\n"
         "\t 6. Search the minimal spanning tree in the graph.\n"
         "\t 7. Solve salesman problem.\n"
         "\t 8. Do research of TSM algorithms performance.\n"
         "\t 9. Write graph to the file\n"
         "\t 0. Close the application.\n");
};

}  // namespace s21

#endif  // A2_SIMPLENAVIGATOR_V1_0_0_MASTER_CONSOLEENGINE_H
