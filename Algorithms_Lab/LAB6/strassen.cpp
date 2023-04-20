#include <bits/stdc++.h>
using namespace std;

#define ROW_1 4
#define COL_1 4

#define ROW_2 4
#define COL_2 4

void print(string display, vector<vector<int>> matrix,
           int start_row, int start_column, int end_row,
           int end_column)
{
    cout << endl
         << display << " =>" << endl;
    for (int i = start_row; i <= end_row; i++)
    {
        for (int j = start_column; j <= end_column; j++)
        {
            cout << setw(10);
            cout << matrix[i][j];
        } 
        cout << endl;
    }
    cout << endl;
    return;
}

void add_matrix(vector<vector<int>> matrix_A,
                vector<vector<int>> matrix_B,
                vector<vector<int>> &matrix_C,
                int new_size)
{
    for (auto i = 0; i < new_size; i++)
        for (auto j = 0; j < new_size; j++)
            matrix_C[i][j] = matrix_A[i][j] + matrix_B[i][j];
}

vector<vector<int>>
multiply_matrix(vector<vector<int>> matrix_A,
                vector<vector<int>> matrix_B)
{
    int col_1 = matrix_A[0].size();
    int row_1 = matrix_A.size();
    int col_2 = matrix_B[0].size();
    int row_2 = matrix_B.size();

    if (col_1 != row_2)
    {
        cout << "\nError: The number of columns in Matrix "
                "A  must be equal to the number of rows in "
                "Matrix B\n";
        return {};
    }

    vector<int> result_matrix_row(col_2, 0);
    vector<vector<int>> result_matrix(row_1,
                                      result_matrix_row);

    if (col_1 == 1)
        result_matrix[0][0] = matrix_A[0][0] * matrix_B[0][0];
    else
    {
        int new_size = col_1 / 2;

        vector<int> row_vector(new_size, 0);
        vector<vector<int>> result_matrix_00(new_size,
                                             row_vector);
        vector<vector<int>> result_matrix_01(new_size,
                                             row_vector);
        vector<vector<int>> result_matrix_10(new_size,
                                             row_vector);
        vector<vector<int>> result_matrix_11(new_size,
                                             row_vector);

        vector<vector<int>> a00(new_size, row_vector);
        vector<vector<int>> a01(new_size, row_vector);
        vector<vector<int>> a10(new_size, row_vector);
        vector<vector<int>> a11(new_size, row_vector);
        vector<vector<int>> b00(new_size, row_vector);
        vector<vector<int>> b01(new_size, row_vector);
        vector<vector<int>> b10(new_size, row_vector);
        vector<vector<int>> b11(new_size, row_vector);

        for (auto i = 0; i < new_size; i++)
            for (auto j = 0; j < new_size; j++)
            {
                a00[i][j] = matrix_A[i][j];
                a01[i][j] = matrix_A[i][j + new_size];
                a10[i][j] = matrix_A[new_size + i][j];
                a11[i][j] = matrix_A[i + new_size]
                                    [j + new_size];
                b00[i][j] = matrix_B[i][j];
                b01[i][j] = matrix_B[i][j + new_size];
                b10[i][j] = matrix_B[new_size + i][j];
                b11[i][j] = matrix_B[i + new_size]
                                    [j + new_size];
            }

//this will give for the resultant matrix
        add_matrix(multiply_matrix(a00, b00), multiply_matrix(a01, b10),result_matrix_00, new_size);
        add_matrix(multiply_matrix(a00, b01),multiply_matrix(a01, b11),result_matrix_01, new_size);
        add_matrix(multiply_matrix(a10, b00),multiply_matrix(a11, b10),result_matrix_10, new_size);
        add_matrix(multiply_matrix(a10, b01),multiply_matrix(a11, b11),result_matrix_11, new_size);

        for (auto i = 0; i < new_size; i++)
            for (auto j = 0; j < new_size; j++)
            {
                result_matrix[i][j] = result_matrix_00[i][j];
                result_matrix[i][j + new_size] = result_matrix_01[i][j];
                result_matrix[new_size + i][j] = result_matrix_10[i][j];
                result_matrix[i + new_size]
                             [j + new_size] = result_matrix_11[i][j];
            }
        // here we will be clearing out the values as it may interfere with the values
        //  in next iteration
        result_matrix_00.clear();
        result_matrix_01.clear();
        result_matrix_10.clear();
        result_matrix_11.clear();
        a00.clear();
        a01.clear();
        a10.clear();
        a11.clear();
        b00.clear();
        b01.clear();
        b10.clear();
        b11.clear();
    }
    return result_matrix;
}

int main()
{

    vector<vector<int>> matrix_A(ROW_1, vector<int>(COL_1));
    cout << "Enter elements of matrix A:\n";
    for (int i = 0; i < ROW_1; i++)
    {
        for (int j = 0; j < COL_1; j++)
        {
            cin >> matrix_A[i][j];
        }
    }
    vector<vector<int>> matrix_B(ROW_2, vector<int>(COL_2));
    cout << "Enter elements of matrix B:\n";
    for (int i = 0; i < ROW_2; i++)
    {
        for (int j = 0; j < COL_2; j++)
        {
            cin >> matrix_B[i][j];
        }
    }
    print("Array A", matrix_A, 0, 0, ROW_1 - 1, COL_1 - 1);
    print("Array B", matrix_B, 0, 0, ROW_2 - 1, COL_2 - 1);

    vector<vector<int>> result_matrix(
        multiply_matrix(matrix_A, matrix_B));

    print("Result Array", result_matrix, 0, 0, ROW_1 - 1,
          COL_2 - 1);
}
