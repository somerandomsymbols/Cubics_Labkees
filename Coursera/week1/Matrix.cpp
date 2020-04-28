#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix
{
    public:
        int row,col;
    vector<vector<int>> M;

    Matrix()
    {
        row = 0;
        col = 0;
    }

    Matrix(int x, int y)
    {
        if (x < 0 || y < 0)
            throw std::out_of_range("");

        row = x;
        col = y;

        for (int i = 0; i < y; ++i)
        {
            vector<int> z;
            for (int j = 0; j < x; ++j)
                z.push_back(0);
            M.push_back(z);
        }
    }

    void Reset(int x, int y)
    {
        if (x < 0 || y < 0)
            throw std::out_of_range("");

        row = x;
        col = y;

        M.clear();

        for (int i = 0; i < y; ++i)
        {
            vector<int> z;
            for (int j = 0; j < x; ++j)
                z.push_back(0);
            M.push_back(z);
        }
    }

    int At(int x, int y) const
    {
        return M.at(y).at(x);
    }

    int& At(int x, int y)
    {
        return M.at(y).at(x);
    }

    int GetNumRows() const
    {
        return row;
    }

    int GetNumColumns() const
    {
        return col;
    }

    bool operator==(const Matrix x) const
    {
        if (col*row == 0 && x.col*x.row == 0)
            return true;
        if (GetNumRows() != x.GetNumRows() || GetNumColumns() != x.GetNumColumns())
            return false;
        return M == x.M;
    }

    Matrix operator+(const Matrix x) const
    {
        if (col*row != 0 || x.col*x.row)
        if (GetNumRows() != x.GetNumRows() || GetNumColumns() != x.GetNumColumns())
            throw std::invalid_argument("hhhh");

        Matrix y(GetNumRows(), GetNumColumns());

        for (int i = 0; i < GetNumRows(); ++i)
        {
            for (int j = 0; j < GetNumColumns(); ++j)
            {
                y.At(i,j) = At(i,j) + x.At(i,j);
            }
        }

        return y;
    }
};

std::istream & operator >> (std::istream &in, Matrix &c)
{
    int x, y;
    in >> x >> y;
    c.Reset(x,y);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            in >> c.At(i,j);
        }
    }

    return in;
}

std::ostream & operator << (std::ostream &out, const Matrix &c)
{
    out << c.GetNumRows() << ' ' << c.GetNumColumns() << endl;

    for (int i = 0; i < c.GetNumRows(); ++i)
    {
        for (int j = 0; j < c.GetNumColumns(); ++j)
        {
            out << c.At(i,j) << ' ';
        }

        out << endl;
    }

    return out;
}

int main()
{
    Matrix one;
    Matrix two;
    cin >> one >> two;
    cout << one + two << endl;
    return 0;
}
