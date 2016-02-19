#include<iostream>
#include<vector>
#include<time.h>
using namespace std;

vector<vector<int>> SimpleMultiply(vector<vector<int>> A, vector<vector<int>> B)
{
	vector<vector<int>> answer;
	answer = A;
	int x = 0;
	for (int i = 0; i < A.size(); i++)
	for (int j = 0; j < A[0].size(); j++) {
		for (int k = 0; k < A[0].size(); k++)
			//answer[i][j] = answer[i][j] + (A[i][k] * B[k][j]);
			x = x + (A[i][k] * B[k][j]);
		answer[i][j] = x;
		x = 0;
	}
	return answer;
}


vector<vector<int>> SumAndSub(vector<vector<int>> A, vector<vector<int>> B, char operation)
{

	vector<vector<int>> answer;
	answer = A;
	if (operation == '+')
	{

		for (int i = 0; i < A.size(); i++) {
			for (int j = 0; j < A[0].size(); j++) {
				answer[i][j] = A[i][j] + B[i][j];
			}
		}
	}
	if (operation == '-')
	{

		for (int i = 0; i < A.size(); i++) {
			for (int j = 0; j < A[0].size(); j++) {
				answer[i][j] = A[i][j] - B[i][j];
			}
		}
	}
	return answer;
}

vector<vector<int>> AlgoMultiplication(vector<vector<int>> A, vector<vector<int>> B)
{
	vector<vector<int>> answer;
	answer = A;
	if (A.size() == 1) {
		answer[0][0] = A[0][0] * B[0][0];
		return answer;
	}
	int size = A.size();

	//////    initiliazigng all the requires matrices 


	vector<int> tem(size/2, 0);
	vector<vector<int> > a11(size/2, tem);
	vector<vector<int> > a12(size / 2, tem);
	vector<vector<int> > a21(size / 2, tem);
	vector<vector<int> > a22(size / 2, tem);
	vector<vector<int> > b11(size / 2, tem);
	vector<vector<int> > b12(size / 2, tem);
	vector<vector<int> > b21(size / 2, tem);
	vector<vector<int> > b22(size / 2, tem);


	vector<vector<int> > c11(size / 2, tem);
	vector<vector<int> > c12(size / 2, tem);
	vector<vector<int> > c21(size / 2, tem);
	vector<vector<int> > c22(size / 2, tem);

	vector<vector<int> > M1(size / 2, tem);
	vector<vector<int> > M2(size / 2, tem);
	vector<vector<int> > M3(size / 2, tem);
	vector<vector<int> > M4(size / 2, tem);
	vector<vector<int> > M5(size / 2, tem);
	vector<vector<int> > M6(size / 2, tem);
	vector<vector<int> > M7(size / 2, tem);


	vector<vector<int> > temp1(size / 2, tem);
	vector<vector<int> > temp2(size / 2, tem);

	//converting matrix A and B in to submatrices
	for (int i = 0; i < size / 2; i++)
	{
		for (int j = 0; j < size / 2; j++)
		{
			a11[i][j] = A[i][j];
			a12[i][j] = A[i][j + size / 2];
			a21[i][j] = A[i + size / 2][j];
			a22[i][j] = A[i + size / 2][j + size / 2];
		}
	}

	for (int i = 0; i < size / 2; i++) 
	{
		for (int j = 0; j < size / 2; j++) 
		{

			b11[i][j] = B[i][j];
			b12[i][j] = B[i][j + size / 2];
			b21[i][j] = B[i + size / 2][j];
			b22[i][j] = B[i + size / 2][j + size / 2];
		}
	}
	temp1 = SumAndSub(a11, a22,'+');
	temp2 = SumAndSub(b11, b22,'+'); 
	M1 = SimpleMultiply(temp1, temp2);

	temp1 = SumAndSub(a21, a22,'+'); 
	M2 = SimpleMultiply(temp1, b11);

	temp2 = SumAndSub(b12, b22,'-');
	M3 = SimpleMultiply(a11, temp2);

	temp2 = SumAndSub(b21, b11,'-'); 
	M4 = SimpleMultiply(a22, temp2);

	temp1 = SumAndSub(a11, a12,'+'); 
	M5 = SimpleMultiply(temp1, b22);

	temp1 = SumAndSub(a21, a11,'-'); 
	temp2 = SumAndSub(b11, b12,'+'); 
	M6 = SimpleMultiply(temp1, temp2);

	temp1 = SumAndSub(a12, a22,'-'); 
	temp2 = SumAndSub(b21, b22,'+'); 
	M7 = SimpleMultiply(temp1, temp2);



	temp1 = SumAndSub(M1, M4, '+');
	temp2 = SumAndSub(temp1, M7, '+');
	c11 = SumAndSub(temp2, M5, '-');


	temp1 = SumAndSub(M1, M3, '+');
	temp2 = SumAndSub(temp1, M6, '+');
	c22 = SumAndSub(temp2, M2, '-');

	c12 = SumAndSub(M3, M5,'+'); 
	c21 = SumAndSub(M2, M4,'+'); 


	for (int i = 0; i < size / 2; i++) {
		for (int j = 0; j < size / 2; j++) {
			answer[i][j] = c11[i][j];
			answer[i][j + size / 2] = c12[i][j];
			answer[i + size / 2][j] = c21[i][j];
			answer[i + size / 2][j + size / 2] = c22[i][j];
		}
	}
	return answer;
}
