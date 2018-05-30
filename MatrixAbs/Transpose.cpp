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
	inFile.open("Transposeout.txt");
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
	string line;
	int row = 0;
	int column = 0;
	ifstream onFile ("composite2out.txt");
	while(onFile >> line)
	{
		double x;
		x = stod(line);	
		if(row == 100)
		{
			row = 0;
			column++;
			hold[row][column] = x;
			row++;
		}
		else 
		{
			hold[row][column] = x;
			row++;
		}
		
	}
	printMatrix(hold);
}