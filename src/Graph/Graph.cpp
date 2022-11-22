#include "Graph.h"

namespace s21 {

Graph::Graph() { matrix_ = S21Matrix(); }

void Graph::GetMatrixFromFile(std::string filename) {
    std::fstream file(filename);
    if (!file) {
        file.close();
        throw std::invalid_argument("Wrong path to the file!");
    }
    int rows, cols;
    char separator;
    file >> rows;
    matrix_ = S21Matrix(rows, rows);
    rows = cols = 0;
    while (!file.eof()) {
        file >> matrix_(rows, cols++);
        if (cols != matrix_.get_cols()) file >> separator;
        if (cols == matrix_.get_cols()) {
            cols = 0;
            rows++;
        }
    }
    file.close();
}

void Graph::WriteMatrixToFile(std::string filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        file.close();
        throw std::invalid_argument("Wrong path to the file!");
    }
    file << matrix_.get_rows() << std::endl;
    for (int i = 0; i < matrix_.get_cols(); i++) {
        for (int j = 0; j < matrix_.get_rows(); j++) {
            file << matrix_(i, j);
            if (j < matrix_.get_rows() - 1) file << ',';
        }
        if (i < matrix_.get_rows() - 1) file << std::endl;
    }
    file.close();
}

S21Matrix& Graph::GetMatrix() { return matrix_; }

void Graph::ExportGraphToDot(std::string filename) {
    std::ofstream file(filename);
    int start_j = 0;
    file << "graph " << filename << " {" << std::endl;
    for (int i = 0; i < matrix_.get_rows(); ++i) {
        file << "    " << (char)(i + 'a') << ";" << std::endl;
    }
    for (int i = 0; i < matrix_.get_rows(); ++i) {
        ++start_j;
        for (int j = start_j; j < matrix_.get_cols(); ++j) {
            if (matrix_(i, j)) {
                file << "    " << (char)(i + 'a') << " -- " << (char)(j + 'a') << ";" << std::endl;
            }
        }
    }
    file << "}";
    file.close();
}

bool Graph::IsEmpty() { return !matrix_.get_rows(); }
}  // namespace s21
