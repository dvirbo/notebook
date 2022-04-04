#include "Notebook.hpp"
#include "Direction.hpp"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <string>

using ariel::Direction;

using namespace std;
const int MAX_LINE_SIZE = 100;
const char EMPTY_SPACE = '_';
const char DEL = '~';
const int low_bound = 32;
const int up_bound = 125;

namespace ariel
{
    // define new line:
    std::vector<char> new_line(MAX_LINE_SIZE, EMPTY_SPACE);
    /*
    write your text to the db
    if the args or the data invalid - throw eror..
    */
    void Notebook::write(int page, int row, int col, Direction dir, string const &data)
    {
        int len = data.length();
        Notebook::check_args(page, row, col, len, dir);
        string get_str = read(page, row, col, dir, len);
        if (get_str != string(data.length(), EMPTY_SPACE))
        {
            throw invalid_argument("can't write there..");
        }
        Notebook::valid_write(data);
        string istr;
        if (dir == Direction::Horizontal)
        {
            istr = to_string(page) + "_" + to_string(row);

            for (int i = 0; i < len; i++)
            {
                if (data[(unsigned long)i] == DEL)
                {
                    throw("can't write to place that already deleted..");
                }
                Notebook::note[istr].at((unsigned int)col++) = data[(unsigned long)i];
            }
        }
        else // dir == Direction::Vertical:
        {
            for (int i = 0; i < len; i++)
            {
                istr = to_string(page) + "_" + to_string(row++);
                Notebook::note[istr].at((unsigned int)col) = data[(unsigned long)i];
            }
        }
    }
    /*
    read the string fron the db (if it exist)
    in case the parameters wrong - throw eror
    */
    string Notebook::read(int page, int row, int col, Direction dir, int len) 
    {
        Notebook::check_args(page, row, col, len, dir);
        string ans;
        string line;
        if (dir == Direction::Horizontal)
        {
            line = to_string(page) + "_" + to_string(row);
            if (Notebook::note[line].empty())
            {
                Notebook::note[line] = new_line;
            }
            for (int i = 0; i < len; i++)
            {
                ans += Notebook::note[line].at((unsigned int)(col + i));
            }
        }
        else // dir == Direction::Vertical:
        {
            for (int i = 0; i < len; i++)
            {
                line = to_string(page) + "_" + to_string(row + i);
                if (Notebook::note[line].empty())
                {
                    Notebook::note[line] = new_line;
                }
                ans += Notebook::note[line].at((unsigned int)col);
            }
        }

        return ans;
    }
    /*
    erase the data from the db (put ~ on the place that been deleted)
    if the args invalid - throw eror..
    */
    void Notebook::erase(int page, int row, int col, Direction dir, int len)
    {
        Notebook::check_args(page, row, col, len, dir);
        string tmp = read(page, row, col, dir, len); // call read to check if the place can delete..
        string line;
        if (dir == Direction::Horizontal)
        {
            line = to_string(page) + "_" + to_string(row);
            for (int i = 0; i < len; i++)
            {
                Notebook::note[line].at((unsigned int)(col + i)) = DEL;
            }
        }
        else // dir == Direction::Vertical:
        {
            for (int i = 0; i < len; i++)
            {
                line = to_string(page) + "_" + to_string(row + i);
                Notebook::note[line].at((unsigned int)col) = DEL;
            }
        }
    }

    void Notebook::show(int page)
    {
        if (page < 0)
        {
            throw invalid_argument("unvalid args..");
        }
    }

    /**
     * this function check if the data is valid
     * if not - throw "invalid_argument"
     * */
    void Notebook::valid_write(string const &data)
    {
        for (int i = 0; i < data.length(); i++)
        {
           char tmp = data[(unsigned long)i];
            if (tmp < low_bound || tmp > up_bound)
            {
                throw invalid_argument("unvalid args..");
            }
        }
    }

    /*
    check if the args are valids
    if not - throw eror
    */
    void Notebook::check_args(int page, int row, int col, int len, Direction dir)
    {
        if ((page < 0 || row < 0 || col < 0 || len < 0) || (dir == Direction::Horizontal && len + col > MAX_LINE_SIZE))
        {
            throw invalid_argument("seg fault");
        }
    }

}
