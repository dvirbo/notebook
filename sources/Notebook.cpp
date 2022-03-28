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

namespace ariel
{

    std::vector<char> new_line(MAX_LINE_SIZE, EMPTY_SPACE);

    void Notebook::write(int page, int row, int col, Direction dir, string const &data)
    {
        int len = data.length();
        Notebook::ckeck_args(page, row, col, len, dir);
        string get_str = read(page, row, col, dir, len);
        if (get_str != string(data.length(), EMPTY_SPACE))
        {
            throw invalid_argument("can't write there..");
        }
        Notebook::valid_write(data);
        string istr;
         int i = 0;
        if (dir == Direction::Horizontal)
        {
            istr = to_string(page) + "_" + to_string(row);
            while (len != 0)
            {
                if (data[(unsigned long)i] == DEL)
                {
                    throw("can't write to place that already deleted..");
                }
                Notebook::note[istr].at((unsigned int)col++) = data[(unsigned long)i];
                i++;
                len--;
            }
        }
        else
        {
            while (len != 0)
            {
                istr = to_string(page) + "_" + to_string(row++);
                Notebook::note[istr].at((unsigned int)col) = data[(unsigned long)i];
                len--;
            }
        }
    }

    string Notebook::read(int page, int row, int col, Direction dir, int len)
    {
        Notebook::ckeck_args(page, row, col, len, dir);
        string ans;
        string line;
        int i = 0; 
        if (dir == Direction::Horizontal)
        {
            line = to_string(page) + "_" + to_string(row);
            if (Notebook::note[line].empty())
            {
                Notebook::note[line] = new_line;
            }
            while (len != 0)
            {
                ans += Notebook::note[line].at((unsigned int)(col + i));
                i++;
                len--;
            }
        }
        else
        {
            while (len != 0)
            {
                line = to_string(page) + "_" + to_string(row + i);
                if (Notebook::note[line].empty())
                {
                    Notebook::note[line] = new_line;
                }
                ans += Notebook::note[line].at((unsigned int)col);
                i++;
                len--;
            }
        }

        return ans;
    }

    void Notebook::erase(int page, int row, int col, Direction dir, int len)
    {
        Notebook::ckeck_args(page, row, col, len, dir);
        string line;
        if (dir == Direction::Horizontal)
        {
            line = to_string(page) + "_" + to_string(row);
            while (len != 0)
            {
                Notebook::note[line].at((unsigned int)col++) = DEL;
                len--;
            }
        }
        else
        {
            line = to_string(page) + "_" + to_string(row++);
            while (len != 0)
            {
                Notebook::note[line].at((unsigned int)col) = DEL;
                len--;
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

    /*
    check if the args are valids
    if not - throw eror
    */
    void Notebook::ckeck_args(int page, int row, int col, int len, Direction dir)
    {
        if ((page < 0 || row < 0 || col < 0) || (dir == Direction::Horizontal && len + col > MAX_LINE_SIZE))
        {
            throw invalid_argument("seg fault");
        }
    }

    /**
     * this method check if we can write in the places that recuired-
     * if there is data that not _ trow false
     *
     * */
    void Notebook::valid_write(string const &data)
    {
        int len = data.length();
        int upper = 32;
        for (int i = 0; i <len ; i++)
        {
            for (int j = 0; j < upper; j++)
            {
                char tmp = j;
                if (data[(unsigned long)i] == tmp)
                {
            throw invalid_argument("wrong input");
                }
            }
            if (data[(unsigned long)i] == 126 || data[(unsigned long)i] == 127)
            {
            throw invalid_argument("wrong input");
            }

        }
    }
}
