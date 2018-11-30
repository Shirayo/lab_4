//
//  method_of_least_squares.hpp
//  lab_4
//
//  Created by Vasily Mordus on 21/11/2018.
//  Copyright © 2018 Vasily Mordus. All rights reserved.
//

#ifndef method_of_least_squares_hpp
#define method_of_least_squares_hpp

#include <stdio.h>
#include <vector>
#include <string>

using std::string;
using std::vector;

void check_file_for_points(vector<vector<double>> &points, string &file_with_points);

double sum_x (vector<vector<double>> &points, size_t pwr);

double sum_xy(vector<vector<double>> &points, size_t pwr);

vector<double> mnk(vector<vector<double>> pts);

void find_h0_b(const vector<double> &solution, double &h0, double &b);

#endif /* method_of_least_squares_hpp */
