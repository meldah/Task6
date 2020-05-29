#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

#define N 100 

int n, m;


int a[N][N];

vector<vector<int> > dp(N, vector<int>(N)),
visited(N, vector<int>(N));

int currentSum = 0;

int totalSum = 0;

void inputMatrix()
{
	n = 3;
	m = 3;
	a[0][0] = 500;
	a[0][1] = 100;
	a[0][2] = 230;
	a[1][0] = 1000;
	a[1][1] = 100;
	a[1][2] = 100;
	a[2][0] = 200;
	a[2][1] = 1000;
	a[2][2] = 200;
}

int maximumSumPath(int i, int j)
{
	if (i == n - 1 && j == m - 1)
		return a[i][j];

	if (visited[i][j])
		return dp[i][j];

	// Marking (i, j) is visited 
	visited[i][j] = 1;

	int& totalSum = dp[i][j];
 
	if (i < n - 1 && j < m - 1) 
	{
		int current_sum = max(maximumSumPath(i, j + 1), maximumSumPath(i + 1, j));
		totalSum = a[i][j] + current_sum;
	}	
	else if (i == n - 1)
	{
		totalSum = a[i][j] + maximumSumPath(i, j + 1);	
	}
	else
	{
		totalSum = a[i][j] + maximumSumPath(i + 1, j);
	}

	return totalSum;
}

int main()
{
	inputMatrix();

	// Calling the implemented function 
	int maximumSum = maximumSumPath(0, 0);

	cout << maximumSum << endl;
	system("pause");
	return 0;
}
