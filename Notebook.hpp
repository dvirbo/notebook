// Header file for class Notebook
#pragma once
#include "Direction.hpp"
#include <string>
#include <vector>
using namespace std;
/*
// vector<vector<int>> M;
// int m = number of rows, n = number of columns;
// M.resize(m, vector<int>(n));
*/
namespace ariel
{
    class Notebook
    {

        unsigned int rows, cols;
        vector<vector<char>> notebook;

    public:
        // Constructors
        Notebook();
        Notebook(int rows, int cols);

        // Destructor
        ~Notebook();

        void write(int page, int row, int col, Direction dir, string const &data);
        string read(int page, int row, int col, Direction dir, int len);
        void erase(int page, int row, int col, Direction dir, int len);
        void show(int);
        bool colPos(int);
        bool pagePos(int);
        bool linePos(int);
        bool lenpos(int);

        // return the number of rows and columns of this Notebook
        unsigned int get_rows() const;
        unsigned int get_cols() const;
    };
}
