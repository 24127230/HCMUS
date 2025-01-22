#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
using namespace std;

bool readMatrix(const char *filename, int **&matrix, int &rows, int &cols);
void printMatrix(const char *filename, int **matrix, int rows, int cols);
bool multiplyMatrices(int **a, int aRows, int aCols,
                      int **b, int bRows, int bCols,
                      int **&res, int &resRows, int &resCols);
void transposeMatrix(int **matrix, int rows, int cols,
                     int **&res, int &resRows, int &resCols);

bool readMatrix(const char *filename, int **&matrix, int &rows, int &cols)
{
    ifstream fin(filename);
    if (!fin.is_open())
    {
        cout << "Can not open file " << filename << " to read!\n";
        return false;
    }
    vector<vector<int>> tempM;
    string line;
    while (getline(fin, line))
    {
        stringstream ss(line);
        vector<int> row;
        int number;
        while (ss >> number)
        {
            row.push_back(number);
        }
        if (!row.empty())
        {
            tempM.push_back(row);
        }
    }
    fin.close();
    rows = tempM.size();
    cols = (rows > 0) ? tempM[0].size() : 0;
    matrix = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = tempM[i][j];
        }
    }
    return true;
}
void printMatrix(const char *filename, int **matrix, int rows, int cols)
{
    ofstream fout(filename);
    if (!fout.is_open())
    {
        cout << "Can not open file " << filename << " to write!";
        return;
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            fout << matrix[i][j] << " ";
        }
        fout << '\n';
    }
    fout.close();
}
bool multiplyMatrices(int **a, int aRows, int aCols,
                      int **b, int bRows, int bCols,
                      int **&res, int &resRows, int &resCols)
{
    if (aCols != bRows)
    {
        cout << "Can not multiply these matrices!";
        return false;
    }
    resRows = aRows;
    resCols = bCols;
    res = new int *[resRows];
    for (int i = 0; i < resRows; i++)
    {
        res[i] = new int[resCols];
        for (int j = 0; j < resCols; j++)
        {
            res[i][j] = 0;
            for (int z = 0; z < aCols; z++)
            {
                res[i][j] += a[i][z] * b[z][j];
            }
        }
    }
    return true;
}
void transposeMatrix(int **matrix, int rows, int cols,
                     int **&res, int &resRows, int &resCols)
{
    resRows = cols;
    resCols = rows;
    res = new int *[resRows];
    for (int i = 0; i < resRows; i++)
    {
        res[i] = new int[resCols];
        for (int j = 0; j < resCols; j++)
        {
            res[i][j] = matrix[j][i];
        }
    }
}
int main()
{
    int **a;
    int rowsa, colsa;

    int **b;
    int rowsb, colsb;

    readMatrix("matrix_a.txt", a, rowsa, colsa);
    readMatrix("matrix_b.txt", b, rowsb, colsb);

    int **c;
    int rowsc, colsc;
    if (multiplyMatrices(a, rowsa, colsa, b, rowsb, colsb, c, rowsc, colsc))
    {
        printMatrix("matrix_c.txt", c, rowsc, colsc);
    }

    int **tc;
    int rowstc, colstc;
    transposeMatrix(c, rowsc, colsc, tc, rowstc, colstc);
    printMatrix("matrix_c_transposed.txt", tc, rowstc, colstc);

    for (int i = 0; i < rowsa; i++)
        delete[] a[i];
    delete[] a;
    for (int i = 0; i < rowsb; i++)
        delete[] b[i];
    delete[] b;
    for (int i = 0; i < rowsc; i++)
        delete[] c[i];
    delete[] c;
    for (int i = 0; i < rowstc; i++)
        delete[] tc[i];
    delete[] tc;
}
