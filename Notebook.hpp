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
        std::vector< std::vector<char> > notebook;


    public:
        // Constructors
        Notebook();
        Notebook(unsigned int rows, unsigned int cols);

        // Destructor
        ~Notebook();

        void write(unsigned int page, unsigned int row, unsigned int col, Direction dir, string data);
        string read(unsigned int page, unsigned int row, unsigned int col, Direction dir, unsigned int len);
        void erase(unsigned int page, unsigned int row, unsigned int col, Direction dir, unsigned int len);
        void show(unsigned int);
        bool maxSizeLine(int);
        bool pagePos(int);
        bool linePos(int);



        // return the number of rows and columns of this Notebook
            unsigned int get_rows() const;
            unsigned int get_cols() const;
    };
}
