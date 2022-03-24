#include "Notebook.hpp"
#include "Direction.hpp"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <string>
#include <cstring>

using ariel::Direction;

using namespace std;

namespace ariel
{
    const int DEFAULT_SIZE = 100;
    const int MAX_LINE_SIZE = 100;
    const char EMPTY_SPACE = '_';
    const char DEL = '~';
    const int MIN_SIZE = 1;

    // Default constructor
    Notebook::Notebook()
    {
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
        int len = data.length();
        if (colPos(col) && pagePos(page) && linePos(row) && legal(page, row, col, dir, len))
        {
            unsigned int p = (unsigned int)page;
            unsigned int r = (unsigned int)row;
            unsigned int c = (unsigned int)col;

            unsigned int pos = 100 * (r - 1) + c;
            unsigned int j = 0;
            if (dir == Direction::Horizontal)
            {
                while (j < len)
                {
                    Notebook::notebook[p][pos++] = data[j++];
                }
            }
            else
            {
                while (j < len)
                {
                    Notebook::notebook[p][pos += 100] = data[j++];
                }
            }
        }
    }
    string Notebook::read(int page, int row, int col, Direction dir, int len)
    {
        std::string ans;
        if (colPos(col) && pagePos(page) && linePos(row) && lenpos(len))
        {
            if (len + col < MAX_LINE_SIZE)
            {
                unsigned int p = (unsigned int)page;
                unsigned int r = (unsigned int)row;
                unsigned int c = (unsigned int)col;
                unsigned int j = 0;
                unsigned int pos = 100 * (r - 1) + c;

                if (dir == Direction::Horizontal)
                {
                    while (j++ < len)
                    {
                        ans = Notebook::notebook[p][pos++];
                    }
                    return ans;
                }
                else
                {
                    while (j++ < len)
                    {
                        ans = Notebook::notebook[p][pos += 100];
                    }
                    return ans;
                }
            }
            else
            {
                throw invalid_argument(" you can't go down line when you read data");
            }
        }
        return "";
    }

    void Notebook::erase(int page, int row, int col, Direction dir, int len)
    {

        if (colPos(col) && pagePos(page) && linePos(row) && lenpos(len))
        {
            if (len + col < MAX_LINE_SIZE)
            {
                unsigned int p = (unsigned int)page;
                unsigned int r = (unsigned int)row;
                unsigned int c = (unsigned int)col;
                unsigned int j = 0;
                unsigned int l = (unsigned int)len;
                unsigned int pos = 100 * (r - 1) + c;

                if (dir == Direction::Horizontal)
                {
                    while (j++ < l)
                    {
                        Notebook::notebook[p][pos++] = DEL;
                    }
                }
                else
                {
                    while (j++ < l)
                    {
                        Notebook::notebook[p][pos += 100] = DEL;
                    }
                }
            }
            else
            {
                throw invalid_argument(" you can't go down line when you erase data");
            }
        }
    }
    void Notebook::show(int page)
    {
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
    bool Notebook::linePos(int pos)
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
    /**
     * this method check if we can write in the places that recuired-
     * if there is datathat not _ trow false
     *
     * */
    bool Notebook::legal(int page, int row, int col, Direction dir, int len)
    {
        unsigned int p = (unsigned int)page;
        unsigned int r = (unsigned int)row;
        unsigned int c = (unsigned int)col;
        unsigned int l = (unsigned int)len;
        unsigned int pos = 100 * (r - 1) + c;
        unsigned int i;
        if (dir == Direction::Horizontal)
        {
            for (i = pos; i < pos + l; i++)
            {
                if (Notebook::notebook[p][i] != EMPTY_SPACE)
                {
                    throw invalid_argument("you can't write to place that already writhen or deleted");
                    return false;
                }
            }
            return true;
        }
        else
        {
            for (i = pos; i < pos + 100 * (l - 1); i += 100)
            {
                if (Notebook::notebook[p][i] != EMPTY_SPACE)
                {
                    return false;
                }
            }
            return true;
        }
    }
}

//     for (int i = 0; i < vec.size(); i++) {
//         for (int j = 0; j < vec[i].size(); j++)
//             cout << vec[i][j] << " ";
//         cout << endl;
//     }
//     return 0;
// }