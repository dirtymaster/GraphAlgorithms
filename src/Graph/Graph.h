#ifndef A2_SIMPLENAVIGATOR_V1_0_0_MASTER_DOTFORMATHANDLER_H
#define A2_SIMPLENAVIGATOR_V1_0_0_MASTER_DOTFORMATHANDLER_H

#include <fstream>
#include <iostream>
#include <string>

#include "../DataStructures/Matrix/Matrix.h"

namespace s21 {

class Graph {
public:
    Graph();
    void WriteMatrixToFile(std::string filename);
    void GetMatrixFromFile(std::string filename);
    void ExportGraphToDot(std::string filename);
    bool IsEmpty();

    S21Matrix& GetMatrix();

private:
    S21Matrix matrix_;
};

}  // namespace s21

#endif  // A2_SIMPLENAVIGATOR_V1_0_0_MASTER_DOTFORMATHANDLER_H
