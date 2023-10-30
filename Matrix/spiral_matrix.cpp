#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> res;
    int m = matrix.size();
    int n = matrix[0].size();
    int startingRow = 0;
    int endingRow = m - 1;
    int startingCol = 0;
    int endingCol = n - 1;
    int count = 0;
    int total_element = m * n;
    while (count < total_element)
    {
        for (int i = startingCol; i <= endingCol && count < total_element; i++)
        {
            res.push_back(matrix[startingRow][i]);
            count++;
        }
        startingRow++;
        for (int i = startingRow; i <= endingRow && count < total_element; i++)
        {
            res.push_back(matrix[i][endingCol]);
            count++;
        }
        endingCol--;
        for (int i = endingCol; i >= startingCol && count < total_element; i--)
        {
            res.push_back(matrix[endingRow][i]);
            count++;
        }
        endingRow--;
        for (int i = endingRow; i >= startingRow && count < total_element; i--)
        {
            res.push_back(matrix[i][startingCol]);
            count++;
        }
        startingCol++;
    }
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
    }
    return 0;
}
