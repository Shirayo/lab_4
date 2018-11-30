#pragma once
#include <string>
#include <vector>

using std::vector;
using std::string;

bool solve_by_Gauss(vector<vector<double>> &matrix, vector<double> &solution);

double residual_of_matrix(vector<vector<double>> &original_matrix, vector<double> &solution);
