#include <vector>
#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <limits>

using namespace std;

void printMatrix(vector<vector<double>> vecToPrint) {
	ofstream inFile;
	inFile.open("matrixABS.txt");
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			inFile << vecToPrint[i][j] << " ";
		}
		inFile << endl;
	}
	inFile << endl;
}


int main()
{
	vector<vector <double>> matrixP(100, vector <double>(100)); //size 100x100
	int row = 1;
	int column = 1;
	matrixP.clear();
	for (int i = 0; i < 100; ++i) 
	{		
		vector<double>temp;
		for (int j = 0; j < 100; ++j) 
		{
			temp.push_back(0.0);
		}
		matrixP.push_back(temp);
	}
	matrixP[0][0] = 1.0/1.0;  	//Abs state
	matrixP[99][99] = 1.0;	//Abs state
	for(int i = 1; i<99; ++i)
	{
		if(i<9) //top row
		{
			matrixP[i][i] = 1.0;
		}
		else if(i==9) //top right corner
		{
			matrixP[i][i] = 1.0;
		}
		else if(i==90) //bottom left corner
		{
			matrixP[i][i] = 1.0;
		}
		else if(i>90)//bottom row
		{
			matrixP[i][i] = 1.0;
		}
		else if(i % 10 ==9) //right column		
		{
			matrixP[i][i] = 1.0;
		}
		else if(i % 10 == 0) //left column
		{
			matrixP[i][i] = 1.0;

		}
		else //middle
		{
			matrixP[i][i+10] = 1.0/4.0;
			matrixP[i][i-10] = 1.0/4.0;
			matrixP[i][i+1] = 1.0/4.0;
			matrixP[i][i-1] = 1.0/4.0;

		}
	}
	printMatrix(matrixP);
}