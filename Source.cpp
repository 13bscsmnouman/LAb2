#include<iostream>
#include<vector>
#include<time.h>
#include "Header.h"
using namespace std;
void print( vector<vector<int>> A)
{
	for (int t = 0; t < A.size(); t++)
	{
		for (int j = 0; j < A[0].size(); j++)
			cout << A[t][j]<<"    ";
		cout << endl;
	}
}

int main()
{
	int rows = 4;
	int cols = 4;
	vector<int> tem(rows, 0);
	vector<vector<int> > A(cols, tem);
	vector<vector<int> > B(cols, tem);
	vector<vector<int> > ans(cols, tem);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			A[i][j] = rand() % 5;
			B[i][j] = rand() % 5;
		}
	}
	ans=SimpleMultiply(A, B);
	cout << "Matrix A is give By"<<endl;
	print(A);
	cout << "\nMatrix B is give By" << endl;
	print(B);
	cout << "\n\nMatrix A*B is give By Normal Multliplication" << endl;
	print(ans);

	cout << "\n\nMatrix A*B is give By Algorithm"<<endl;
	ans = AlgoMultiplication(A, B);
	print(ans);


	system("pause");
	return 0;
}
