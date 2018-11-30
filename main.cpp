//
//  main.cpp
//  lab_4
//
//  Created by Vasily Mordus on 21/11/2018.
//  Copyright © 2018 Vasily Mordus. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include "method_of_least_squares.hpp"

using std::string;
using std::vector;


int main() {
	vector<vector<double>> points(11);

	for (size_t i = 0; i < 11; i++)
		points[i].resize(2);

	string file_with_points("galaxies.txt");

	check_file_for_points(points, file_with_points);

	vector<double> solution = mnk(points);
	double h0, b;
	find_h0_b(solution, h0, b);
	std::cout << "\n" << h0 << std::setw(10) << b;
	system("pause");
    return 0;
}