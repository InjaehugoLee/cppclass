#include <iostream>
#include <stdlib.h>
using namespace std;

// implement the functions : add, sub, mult, transpose
#define ROWS 1
#define COLS 2
#define COLX 3
class Matrix {
public:
    Matrix(int row, int col);
    ~Matrix();
    int GetData();
    int Display();
    Matrix* Transpose();
    Matrix& Add(Matrix& b);
    Matrix& Sub(Matrix& b);
    Matrix* Multiply(Matrix& b);
    Matrix* Multiply(Matrix* b);
    /*int CompareRowCol(Matrix b);
    int CompareRowRow(Matrix b);
    int CompareColCol(Matrix b);*/
private:
    int rows, cols;
    //Do not use "int Term[rows][cols];"
    int* Term;
};
// 생성자
Matrix::Matrix(int row, int col) : rows(row), cols(col)
{
    Term = new int[rows * cols];
    //memset(Term,0,sizeof(int)* (rows * cols));
}

Matrix::~Matrix()
{
    delete[] Term;
}
// 난수 생성해서 행렬 만들기
int Matrix::GetData() {
    
    for (int i = 0; i < rows * cols; i++)
    {
        Term[i] = rand() % (rows * cols);
    }
    return 0;
}

int Matrix::Display() {
   
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
           printf("%3d", Term[cols * i + j]);
        printf("\n");
    }
    return 0;
}

// 전치 행렬
Matrix* Matrix::Transpose() {

    Matrix* t=new Matrix(cols, rows);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            t->Term[j * rows + i] = Term[i * cols + j];
        }
    }
    return t;
}

Matrix* Matrix::Multiply(Matrix& b) {
   
    Matrix* d = new Matrix(rows, b.cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < b.cols; j++)
        {   
            d->Term[b.cols * i + j] = 0;
            for (int k = 0; k < b.rows; k++)
            { 
                d->Term[b.cols * i + j] += Term[rows * i + k] * b.Term[b.cols * k + j];
            }
        }
    }
    return d;
}

Matrix* Matrix::Multiply(Matrix* b) {

    Matrix* d = new Matrix(rows, b->cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < b->cols; j++)
        {
            d->Term[b->cols * i + j] = 0;
            for (int k = 0; k < b->rows; k++)
            {
                d->Term[b->cols * i + j] += Term[rows * i + k] * b->Term[b->cols * k + j];
            }
        }
    }
    return d;
}

Matrix& Matrix::Add(Matrix& b) {
   
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            b.Term[cols * i + j] = Term[cols * i + j] + b.Term[cols * i + j];
        }
    }
    return b;
}
Matrix& Matrix::Sub(Matrix& b) {
   
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            b.Term[cols * i + j] = Term[cols * i + j] - b.Term[cols * i + j];
        }
    }
    return b;
}

//int Matrix::CompareRowCol(Matrix b) {
//   
//}
//int Matrix::CompareColCol(Matrix b) {
//   
//}
//int Matrix::CompareRowRow(Matrix b) {
//   
//}

//void Matrix::Display() {
//
//    for (int i = 0; i < rows; i++)
//    {
//        for (int j = 0; j < cols; j++)
//            printf("%3d", Term[cols * i + j]);
//        printf("\n");
//    }
//}

int main()
{
    Matrix a(ROWS, COLS);
    Matrix b(COLS, COLX);
    Matrix c(ROWS, COLX);
    Matrix s(ROWS, COLS);
    Matrix t(ROWS, COLS);
    Matrix w(ROWS, COLS);
    Matrix e(ROWS, COLX);

    //cout << "Enter first matrix: " << endl;
    //cout << "Enter S matrix: " << endl;
    //s.GetData();
    //cout << "Enter T matrix: " << endl;
    //t.GetData();

    a.GetData();
    a.Display();
    cout << endl;
    b.GetData();
    b.Display();
    cout << endl;
    Matrix* f = a.Multiply(b);
    f->Display();
    cout << endl;
    Matrix* d = a.Multiply(&b);
    //Matrix* d = a.Multiply();*/
    d->Display();
    //s.Display();
    //t.Display();
    //w = a.Add(s.Add(t));
    //w.Display();
    //if (s.CompareRowRow(t) || s.CompareColCol(t))
    //{
    //    cout << "Error! columns and rows of first matrix is not equal to the columns and rows of the second.";
    //    cout << "Enter rows and columns for first matrix: ";
    //}
    //else
    //{
    //    w = a.Add(s.Add(t));
    //    w.Display();
    //}
    //if (a.CompareRowRow(s) || a.CompareColCol(s))
    //{
    //    cout << "Error! columns and rows of first matrix is not equal to the columns and rows of the second.";
    //    cout << "Enter rows and columns for first matrix: ";
    //}
    //else
    //{
    //    a = a.Add(s);
    //    cout << "Display first matrix: " << endl;
    //    a.Display();
    //}
    //cout << "Enter second matrix: " << endl;
    cout << endl;
    b.GetData();
    cout << "Display second matrix: " << endl;
    b.Display();
    cout << endl;
    Matrix *p = b.Transpose();
    p->Display();
    //cout << "Transpose() of Matrix b" << endl;
    //if (a.CompareRowCol(b))
    //{
    //    cout << "Error! column of first matrix not equal to row of second.";
    //    cout << "Enter rows and columns for first matrix: ";
    //}
    //else {
    //    c = a.Multiply(b);//not using transpose()
    //    //c = a.Add(b);
    //    cout << "Multiply of Matrix a,b" << endl;
    //    c.Display();
    //}
    //d = b.Transpose();
    //if (a.CompareRowCol(d))
    //{
    //    cout << "Error! column of first matrix not equal to row of second.";
    //    cout << "Enter rows and columns for first matrix: ";
    //}
    //else
    //{
    //    cout << "using transpose()" << endl;
    //    Matrix e(ROWS, COLS);
    //    e = a.Multiply(d);//using transpose()
    //    e.Display();
    //}
    system("pause");
    return 0;
}