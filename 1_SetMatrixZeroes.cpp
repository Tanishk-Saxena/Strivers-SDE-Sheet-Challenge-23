#include<iostream>
#include<vector>
using namespace std;

#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	int n = matrix.size(), m = matrix[0].size();
	int rowFlag = 0, colFlag = 0;

	for(int i = 0; i < n; i++)
		if(matrix[i][0] == 0){
			colFlag = 1;
			break;
		}
	for(int i = 0; i < m; i++)
		if(matrix[0][i] == 0){
			rowFlag = 1;
			break;
		}
	for(int i = 1; i < n; i++)
		for(int j = 1; j < m; j++)
			if(matrix[i][j] == 0){
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}
	
	for(int i = 1; i < n; i++)
		for(int j = 1; j < m; j++)
			if(!matrix[i][0] || !matrix[0][j])
				matrix[i][j] = 0;
	if(rowFlag)
		for(int i = 0; i < m; i++)
			matrix[0][i] = 0;
	if(colFlag)
		for(int i = 0; i < n; i++)
			matrix[i][0] = 0;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int> (m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> matrix[i][j];
    setZeros(matrix);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}