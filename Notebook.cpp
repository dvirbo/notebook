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
    const int DEFAULT_SIZE = 100;
    const int MAX_LINE_SIZE = 100;
    const char EMPTY_SPACE = '_';
    const int MIN_SIZE = 1;

    // Default constructor
    Notebook::Notebook()
    {
        // for( auto it = notebook.begin(); it != v.end(); ++it )

        this->rows = DEFAULT_SIZE;
        this->cols = DEFAULT_SIZE;
        this->notebook.resize(DEFAULT_SIZE);
        for (unsigned int i = 0; i < this->notebook.size(); i++)
        {
            notebook[i].resize(DEFAULT_SIZE, EMPTY_SPACE);
        }
    }

    // constructor by Initialization list:
    // Notebook ::Notebook() : rows(DEFAULT_SIZE), cols(DEFAULT_SIZE) {
    //     this->notebook.resize(rows);
    //         for (int i = 0; i < this->rows; i++)
    //     {
    //         notebook[i].resize(cols, EMPTY_SPACE);
    //     }

    // }

    // Constructor
    Notebook::Notebook(int rows, int cols)
    {

        if (rows < MIN_SIZE)
        {
            throw invalid_argument("Invalid input: " + to_string(rows));
        }

        if (cols < MIN_SIZE)
        {
            throw invalid_argument("Invalid input: " + to_string(cols));
        }

        this->rows = (unsigned int)rows;
        this->cols = (unsigned int)cols;
        this->notebook.resize(this->rows);
        for (unsigned int i = 0; i < this->rows; i++)
        {
            notebook[i].resize(this->cols, EMPTY_SPACE);
        }
    }
    // Destructor
    Notebook::~Notebook() {}
    unsigned int Notebook::get_rows() const
    {
        return this->rows;
    }

    unsigned int Notebook::get_cols() const
    {
        return this->cols;
    }

    void Notebook::write(int page, int row, int col, Direction dir, string const &data)
    {
        if (colPos(col) && pagePos(page) && linePos(row))
        {
        }
    }
    string Notebook::read(int page, int row, int col, Direction dir, int len) 
    {
        if (colPos(col) && pagePos(page) && linePos(row) && lenpos(len))
        {
            if (len + col < MAX_LINE_SIZE)
            {
            }
            else{
                throw invalid_argument(" you can't go down line when you read data");
            }
        }
        return " ";
    }

    void Notebook::erase(int page, int row, int col, Direction dir, int len) 
    {
 
        if (colPos(col) && pagePos(page) && linePos(row) && lenpos(len))
        {
            if (len + col < MAX_LINE_SIZE)
            {
            }
            else{
                throw invalid_argument(" you can't go down line when you erase data");
            }
        }
    }
    void Notebook::show(int page) {
    }

    /**
     * The next punctions check the input validation:
     * */
    bool Notebook::colPos(int pos)
    {
        if (pos < 0 || pos > DEFAULT_SIZE)
        {
            throw invalid_argument("the length of the line must be less than 100");
            return false;
        }
        return true;
    }
    bool Notebook::pagePos(int pos)
    {
        if (pos < 0)
        {
            throw invalid_argument("page number must be positive");
            return false;
        }
        return true;
    }
    bool Notebook:: linePos(int pos)
    {
        if (pos < 0)
        {
            throw invalid_argument("line number must be positive");
            return false;
        }
        return true;
    }
    bool Notebook::lenpos(int pos)
    {
        if (pos < 0)
        {
            throw invalid_argument("the length of the string that read must be positive");
            return false;
        }
        if (pos > MAX_LINE_SIZE)
        {
            throw invalid_argument("the length of the string that read must be less than 100");
            return false;
        }
        return true;
    }
}
