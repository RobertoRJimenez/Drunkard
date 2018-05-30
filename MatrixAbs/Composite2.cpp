#include <vector>
#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <ctime>
#include <climits>
#include <limits>
using namespace std;

void printMatrix(vector<vector<double>> vecToPrint) {
	ofstream inFile;
	inFile.open("composite2out.txt");
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			inFile << vecToPrint[i][j] << ' ';
		}
		inFile << endl;
	}
	inFile << endl;
}
int main()
{
	vector<vector <double>> hold(100, vector <double>(100)); //size 100x100
	vector<vector <double>> hold1(100, vector <double>(100)); //size 100x100
	vector<vector <double>> hold2(100, vector <double>(100)); //size 100x100
	vector<vector <double>> hold3(100, vector <double>(100)); //size 100x100
	vector<double> counter;
	vector<double> counter1;
	vector<double> counter2;
	string line;
	int row = 0;
	int column = 0;
	ifstream onFile ("matrixABS.txt");
	while(onFile >> line)
	{
		double x;
		x = stod(line);
		if(x == 1)
		{
			counter.push_back(row);
		}
		if(column == 100)
		{
			column = 0;
			row++;
			hold[row][column] = x;
			column++;
		}
		else 
		{
			hold[row][column] = x;
			column++;
		}
		
	}
	for(int i = 0; i < 100; ++i)
	{
		if(hold[i][i] != 1)
		{
			counter1.push_back(i);
		}
	}
	row = 0;
	hold1 = hold;
	hold2 = hold;
	for(int i = 1; i < counter.size(); ++i)
	{
		for(int j = 0; j <= 99; ++j)
		{
			hold1[i][j] = hold[counter.at(i)][j];
			hold1[counter.at(i)][j] = hold[i][j];
		}
		hold = hold1;
	}
	hold = hold2;
	for(int i = counter.size(); i < 100; ++i)
	{
		for(int j = 0; j<100; ++j)
		{
			hold1[i][j] = hold[counter1.at(row)][j];
		}
		++row;
	}

	printMatrix(hold1);

}
