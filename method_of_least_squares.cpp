//
//  method_of_least_squares.cpp
//  lab_4
//
//  Created by Vasily Mordus on 21/11/2018.
//  Copyright © 2018 Vasily Mordus. All rights reserved.
//
#include <iostream>
#include <cmath>
#include "method_of_least_squares.h"
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>

using std::ifstream;
using std::ofstream;
using std::setw;
using std::cout;

#include "Gauss.h"

void check_file_for_points(vector<vector<double>> &points, string &file_with_points)
{
	ifstream fin(file_with_points);
	if (!fin.is_open()) {
		cout << "\nCan't find this file  ";
		system("pause");
		exit(0);
	}
	string name;
	for (size_t i = 0; i < 11; i++) {
		fin >> name;
		fin >> name;
		for (size_t j = 0; j < 2; j++) {
			fin >> points[i][j];
			cout << setw(15) << points[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

double sum_x (vector<vector<double>> &points, size_t pwr) {
    double sum = 0;
    for(size_t i = 0; i < points.size(); i++)
        sum += pow(points[i][0], pwr);
    return sum;
}

double sum_xy(vector<vector<double>> &points, size_t pwr) {
    double sum = 0;
    for(size_t i = 0; i < points.size(); i++)
        sum += pow(points[i][0], pwr) * points[i][1];
    return sum;
}

vector<double> mnk(vector<vector<double>> points)
{
    size_t pol = 1;
    ofstream fin("glx.txt");
    vector<double> solution(pol + 1);

    vector<vector<double>> SLE(pol + 1);
    for(size_t i = 0; i < pol + 1; i++)
        SLE[i].resize(pol + 2);
 
	for (size_t i = 0; i < pol + 1; i++) {
		size_t pol2 = i;
		for (size_t j = 0; j < pol + 2; j++) {
			if (j == pol + 1) {
				SLE[i][j] = sum_xy(points, pol2 - j);
				break;
			}
			SLE[i][j] = sum_x(points, pol2);
			pol2 += 1;
		}
	}

	for (size_t i = 0; i < pol + 1; i++) {
		for (size_t j = 0; j < pol + 2; j++)
			cout << setw(15) << SLE[i][j];
		cout << "\n";
	}
	cout << "\n";

    solve_by_Gauss(SLE, solution);
	for (size_t i = 0; i < pol + 1; i++)
		cout << setw(10) << solution[i];
    return solution;
}

void find_h0_b(const vector<double> &solution, double &h0, double &b)
{
	double c = 299792458;
	h0 = c / solution[1];
	b = -h0 * solution[0];
}
