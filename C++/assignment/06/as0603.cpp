/*
 寻找矩阵的鞍点
 
    彭寒冰
    2019-4-29 21:12
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int max_point(int * max_index, double * row, int column)
{
    int i, max_count;
    double max = row[0];
    for (i = 1; i < column; i++)
        if (row[i] > max)
            max = row[i];

    for (i = 0, max_count = 0; i < column; i++)
        if (row[i] == max)
        {
            max_index[max_count] = i;
            max_count++;
        }
    return max_count;
}

int saddle_point(int saddle_index[][2], double matrix[], int row, int column)
{
    int r, c, i, j, max_count, saddle_count = 0;
    bool saddle_flag;
    int * max_index = new int[column];

    for (r = 0; r < row; r++)
    {
        // 确定每一行的最大值，最大值所在列存于index中
        max_count = max_point(max_index, matrix + column * r, column);
        for (i = 0; i < max_count; i++)
        {
            c = max_index[i];
            saddle_flag = true;
            // 确定每一个最大值是否是该列的最小值
            for (j = 0; j < row; j++)
                if (j != r && matrix[column * r + c] > matrix[column * j + c])
                {
                    saddle_flag = false; //matrix[r][c]不是鞍点
                    break;
                }
            if (saddle_flag)
            {
                saddle_index[saddle_count][0] = r;
                saddle_index[saddle_count][1] = c;
                saddle_count++;
            }
        }
    }

    delete[] max_index;

    return saddle_count;
}

int main()
{
    const int row = 5;
    const int column = 5;
    
    double matrix[row][column] = {
        {1, 2, 4, 1, 4},
        {2, 5, 7, 1, 2},
        {4, 1, 6, 8, 1},
        {0, 5, 5, 1, 6},
        {9, 1, 8, 4, 2}
    };
    int i, j;

    int (* saddle_index)[2] = (int (*)[2])new int[row*column*2];
    int saddle_count;

/*
    srand((unsigned int)time(NULL));
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            matrix[i][j] = rand() % 10;
            cout << left << setw(2) << matrix[i][j] << ' ';
        }
        cout << endl;
    }
    */
    saddle_count = saddle_point(saddle_index, (double *)matrix, row, column);
    if (saddle_count == 0)
        cout << "没有鞍点" << endl;
    else
        for (i = 0; i < saddle_count; i++)
            cout << "(" << saddle_index[i][0] + 1 << ", " << saddle_index[i][1] + 1 << ") "
                 << matrix[saddle_index[i][0]][saddle_index[i][1]] << endl;

    delete[] saddle_index;
    return 0;
}