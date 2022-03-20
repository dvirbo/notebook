#include "Notebook.hpp"
#include "Direction.hpp"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <string>
using ariel::Direction;

using namespace std;

namespace ariel
{
    // Default and minimal size of the Notebook
    const int DEFAULT_SIZE = 1;
    const int MAX_LINE_SIZE = 100;
    const char EMPTY_SPACE = '_';
    const int MIN_SIZE = 1;

    // Default constructor
    // Notebook::Notebook(){
    //     this->rows = DEFAULT_SIZE;
    //     this->cols = DEFAULT_SIZE;
    // }

    // constructor by Initialization list:
    Notebook ::Notebook() : rows(DEFAULT_SIZE), cols(DEFAULT_SIZE) {}

    // Constructor
    Notebook::Notebook(unsigned int rows, unsigned int cols)
    {

        if (rows < MIN_SIZE)
        {
            throw invalid_argument("Invalid input: " + to_string(rows));
        }

        if (cols < MIN_SIZE)
        {
            throw invalid_argument("Invalid input: " + to_string(cols));
        }

        this->rows = rows;
        this->cols = cols;
    }
    // Destructor
    Notebook::~Notebook() {}
    void write(unsigned int page, unsigned int row, unsigned int col, Direction dir, string data) {}
    string read(unsigned int page, unsigned int row, unsigned int col, Direction dir, unsigned int len)
    {
        return " ";
    }
    void erase(unsigned int page, unsigned int row, unsigned int col, Direction dir, unsigned int len) {}
    void show(unsigned int page) {}

/**
 * The next punctions check the input validation
 * */
    bool maxSizeLine(int pos)
    {
        if (pos < 0 || pos > 100)
        {
            throw runtime_error("the length of the line must be less than 100");
            return false;
        }
        return true;
    }
    bool pagePos(int pos)
    {
        if (pos < 0)
        {
            throw runtime_error("page number must be positive");
            return false;
        }
        return true;
    }
    bool linePos(int pos)
    {
        if (pos < 0)
        {
            throw runtime_error("line number must be positive");
            return false;
        }
        return true;
    }

}
