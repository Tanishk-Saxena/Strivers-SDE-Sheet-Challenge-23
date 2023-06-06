#include<iostream>
#include<vector>
using namespace std;

vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
  vector<vector<long long int>> result(n);
  for(int i = 0; i < n; i++){
    int row = i + 1;
    result[i].push_back(1);
    for(int j = 1; j < row-1; j++){
      result[i].push_back(result[i-1][j-1] + result[i-1][j]);
    }
    if(row > 1)
      result[i].push_back(1);
  }
  return result;
}


int main(){
    int n;
    cin >> n;
    vector<vector<long long int>> res = printPascal(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i+1; j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}