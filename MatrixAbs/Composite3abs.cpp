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
	inFile.open("composite3out.txt");
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
	ifstream onFile ("Transposeout.txt");
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
		for(int j = 0; j < 100; ++j)
		{
			if(hold[i][j] == 1)
			{
				counter1.push_back(i);
			}	
		}
	}
	row = 0;
	int key = 0;
	for(int i = 0; i < 100; ++i)
	{
		for(int j = 0; j < counter1.size(); ++j)
		{
			if(i == counter1.at(j))
			{
				++key;
			}
		}
		if(key == 0)
		{
			counter2.push_back(i);
		}
		key = 0;
	}
	
	
	
	row = 0;
	hold1 = hold;
	hold2 = hold;
	for(int i = 1; i < counter1.size(); ++i)
	{
		for(int j = 0; j <= 99; ++j)
		{
			hold1[i][j] = hold[counter1.at(i)][j];
			hold1[counter1.at(i)][j] = hold[i][j];
		}
		hold = hold1;
	}
	hold = hold2;
	for(int i = counter1.size(); i < 100; ++i)
	{
		for(int j = 0; j<100; ++j)
		{
			hold1[i][j] = hold[counter2.at(row)][j];
		}
		++row;
	}

	printMatrix(hold1);

}
