#include <gtest/gtest.h>

#include "../Graph/Graph.h"
#include "../GraphAlgorithms/GraphAlgorithms.h"

using namespace s21;

TEST(PartOneTests, DFS) {
    Graph graph;
    GraphAlgorithms graph_algorithms;
    graph.GetMatrixFromFile("DotFiles/DFS1.txt");
    std::vector<int> result = graph_algorithms.DepthFirstSearch(graph, 1);
    int expected_values[] = {1, 2, 3, 5, 4};
    EXPECT_EQ(result.size(), 5);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(result[i], expected_values[i]);
    }

    result = graph_algorithms.DepthFirstSearch(graph, 999);
    EXPECT_EQ(result.at(0), -1);

    Graph empty_graph;
    result = graph_algorithms.DepthFirstSearch(empty_graph, 2);
    EXPECT_EQ(result.at(0), -2);

    graph.GetMatrixFromFile("DotFiles/DFS2.txt");
    result = graph_algorithms.DepthFirstSearch(graph, 3);
    int expected_values2[] = {3, 1, 2, 4};
    EXPECT_EQ(result.size(), 4);
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(result[i], expected_values2[i]);
    }

    graph.GetMatrixFromFile("DotFiles/TreeGraph.txt");
    result = graph_algorithms.DepthFirstSearch(graph, 1);
    int expected_values3[] = {1, 2, 5, 9, 10, 6, 3, 4, 7, 11, 12, 8};
    EXPECT_EQ(result.size(), 12);
    for (int i = 0; i < 12; i++) {
        EXPECT_EQ(result[i], expected_values3[i]);
    }
}

TEST(PartOneTests, BFS) {
    Graph graph;
    GraphAlgorithms graph_algorithms;
    graph.GetMatrixFromFile("DotFiles/TreeGraph.txt");
    std::vector<int> result = graph_algorithms.BreadthFirstSearch(graph, 1);
    int expected_values3[] = {1, 4, 3, 2, 8, 7, 6, 5, 12, 11, 10, 9};
    EXPECT_EQ(result.size(), 12);
    for (int i = 0; i < 12; i++) {
        EXPECT_EQ(result[i], expected_values3[i]);
    }
}

TEST(PartOneTests, exportGraphToDot) {
    Graph graph;
    graph.GetMatrixFromFile("DotFiles/example.txt");
    graph.ExportGraphToDot("DotFiles/aboba.dot");
    std::ifstream file("DotFiles/aboba.dot");
    char c;
    if (!file.is_open() || !(file >> c)) {
        file.close();
        FAIL();
    }
    file.close();
}

TEST(PartTwoTests, GetShortestPathBetweenVertices) {
    Graph graph;
    GraphAlgorithms graph_algorithms;
    graph.GetMatrixFromFile("DotFiles/example.txt");
    EXPECT_EQ(graph_algorithms.GetShortestPathBetweenVertices(graph, 1, 4), 20);
    EXPECT_EQ(graph_algorithms.GetShortestPathBetweenVertices(graph, 3, 8), 9);
    EXPECT_EQ(graph_algorithms.GetShortestPathBetweenVertices(graph, 11, 2), 12);
    EXPECT_EQ(graph_algorithms.GetShortestPathBetweenVertices(graph, 4, 10), 13);
    EXPECT_EQ(graph_algorithms.GetShortestPathBetweenVertices(graph, 13, 14), -1);
}

TEST(PartTwoTests, GetShortestPathsBetweenAllVertices) {
    Graph graph, graph2, graph3;
    GraphAlgorithms graph_algorithms;
    graph.GetMatrixFromFile("DotFiles/example2.txt");
    s21::S21Matrix tmp_matrix = graph_algorithms.GetShortestPathsBetweenAllVertices(graph);
    graph2.GetMatrixFromFile("DotFiles/example3.txt");
    s21::S21Matrix expected_matrix = graph2.GetMatrix();
    EXPECT_TRUE(tmp_matrix == expected_matrix);
    EXPECT_EQ(graph_algorithms.GetShortestPathsBetweenAllVertices(graph3), s21::S21Matrix());
}

TEST(PartThreeTests, GetLeastSpanningTree) {
    Graph graph, graph2;
    GraphAlgorithms graph_algorithms;
    graph.GetMatrixFromFile("DotFiles/example4.txt");
    S21Matrix tmp_matrix(graph_algorithms.GetLeastSpanningTree(graph));
    graph2.GetMatrixFromFile("DotFiles/example5.txt");
    s21::S21Matrix expected_matrix = graph2.GetMatrix();
    EXPECT_TRUE(tmp_matrix == expected_matrix);
}

void SetupSolvers(AbstractTSMSolver *solvers[], S21Matrix &matrix) {
    solvers[0] = new TSMAntAlgorithmSolver(matrix);
    solvers[1] = new TSMBranchAndBoundSolver(matrix);
    solvers[2] = new TSMBruteForce(matrix);
}

TEST(TSMTest, AllAlgorithms) {
    Graph graph;
    AbstractTSMSolver *solvers[3];

    graph.GetMatrixFromFile("DotFiles/TSM6x6.txt");
    SetupSolvers(solvers, graph.GetMatrix());
    int expected_vertices[] = {1, 3, 5, 2, 6, 4, 1};
    for (int i = 0; i < 3; i++) {
        TsmResult result = solvers[i]->GetAnswer();
        EXPECT_DOUBLE_EQ(result.distance, 94.0);
        for (int i = 0; i < 7; i++) {
            EXPECT_EQ(expected_vertices[i], result.vertices[i]);
        }
        delete solvers[i];
    }

    graph.GetMatrixFromFile("DotFiles/TSM4x4.txt");
    SetupSolvers(solvers, graph.GetMatrix());
    int expected_vertices2[] = {1, 2, 4, 3, 1};
    for (int i = 0; i < 3; i++) {
        TsmResult result = solvers[i]->GetAnswer();
        EXPECT_DOUBLE_EQ(result.distance, 80.0);
        for (int i = 0; i < 5; i++) {
            EXPECT_EQ(expected_vertices2[i], result.vertices[i]);
        }
        delete solvers[i];
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
