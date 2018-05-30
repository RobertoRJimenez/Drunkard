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

void Ii(vector<vector<double>> vecToPrint) {
	ofstream inFile;
	inFile.open("IAbs.txt");
	for (int i = 0; i < vecToPrint.size(); i++) {
		for (int j = 0; j < vecToPrint.size(); j++) {
			inFile << vecToPrint[i][j] << ' ';
		}
		inFile << endl;
	}
	inFile << endl;
}
void Oo(vector<vector<double>> vecToPrint, int num) {
	ofstream inFile;
	inFile.open("OAbs.txt");
	for (int i = 0; i < num; i++) {
		for (int j = num; j < vecToPrint.size(); j++) {
			inFile << vecToPrint[i][j] << ' ';
		}
		inFile << endl;
	}
	inFile << endl;
}
void Rr(vector<vector<double>> vecToPrint, int num) {
	ofstream inFile;
	inFile.open("RAbs.txt");
	for (int i = num; i < vecToPrint.size(); i++) {
		for (int j = 0; j < num; j++) {
			inFile << vecToPrint[i][j] << ' ';
		}
		inFile << endl;
	}
	inFile << endl;
}
void Qq(vector<vector<double>> vecToPrint, int num) {
	ofstream inFile;
	inFile.open("QAbs.txt");
	for (int i = num; i < vecToPrint.size(); i++) {
		for (int j = num; j < vecToPrint.size(); j++) {
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
	vector<double> counter;
	vector<double> counter1;
	string line;
	int row = 0;
	int column = 0;
	ifstream onFile ("Finalout.txt");
	while(onFile >> line)
	{
		double x;
		x = stod(line);
		if(x == 1)
		{
			counter.push_back(row);
			counter1.push_back(column);
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
	row = 0;
	column = 0;
	vector<vector <double>> I(counter.size(), vector <double>(counter.size()));
	while(row < counter.size())
	{
		I[row][column] = 1;
		column++;
		while(column<counter1.size())
		{
			I[row][column] = 0;
			++column;	
		}
		++row;
		column = row;
	}
	Ii(I);
	Oo(hold, counter.size());
	Rr(hold, counter.size());
	Qq(hold, counter.size());
}