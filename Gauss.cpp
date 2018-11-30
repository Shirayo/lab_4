#include "Gauss.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <cmath>
using namespace std;
using namespace std::chrono;

bool solve_by_Gauss(vector<vector<double>> &matrix, vector<double> &solution) 
{
	size_t size = matrix.size();
	const double eps = 0.000001;						// ��������
	for (size_t k = 0; k < size; k++) {
		size_t index = k;
		double max = fabs(matrix.at(k).at(k));
		for (size_t i = k + 1; i < matrix.size(); i++) {		// ����� ������ � ������������ a[i][k]
			if (fabs(matrix.at(i).at(k)) > max)
			{
				max = fabs(matrix.at(i).at(k));
				index = i;
			}
		}

		if (fabs(matrix.at(index).at(k)) < eps)				//���� �������� ������ ��������(�� ���� ����� ����), �� ������� ���
			return false;
		if (index != k)
			swap(matrix.at(index), matrix.at(k));
        
		for (size_t i = k; i < size; i++) {	// �������� � ����������� �������
			double temp = matrix.at(i).at(k);
            if (abs(temp) <= eps) continue;
			for (size_t j = k; j < size + 1; j++) {
				matrix.at(i).at(j) /= temp;
				if (i == k)  continue;					// ��������� �� �������� ���� �� ����
				matrix.at(i).at(j) -= matrix.at(k).at(j);
			}					
		}
	}

	for (int i = size - 1; i >= 0; i--) {				// �������� �����������
        solution.at(i) = matrix.at(i).at(size);
		for (size_t j = size - 1; j > i; j--) {
			solution.at(i) -= matrix.at(i).at(j) * solution.at(j);
		}
	}
	return true;
}

double residual_of_matrix(vector<vector<double>> &original_matrix, vector<double> &solution) {//������� ������� ������ � ������� ��� ����� � �������
	size_t size = original_matrix.size();
	vector<double> residual(size);
	double temp_resudual = 0;	//������������ ������ �������
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < size; j++) {
			temp_resudual += original_matrix[i][j] * solution[j];
		}
		temp_resudual -= original_matrix[i][size];						//�������� ��������� ���� ������
		residual[i] = temp_resudual;														//���������� � ������ ������� �������
		temp_resudual = 0;
	}
	double maxresidual = fabs(residual[0]);
	for (size_t i = 0; i < size; i++) {									//������� ������������ ������� ������� �������
		if (maxresidual < fabs(residual[i])) {
			maxresidual = fabs(residual[i]);
		}
	}
	return maxresidual;
}
