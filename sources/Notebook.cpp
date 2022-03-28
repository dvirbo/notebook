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

    std::vector<char> new_line(100, EMPTY_SPACE);

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
        unsigned long i = 0;
        if (dir == Direction::Horizontal)
        {
            istr = to_string(page) + "_" + to_string(row);
            while (len--)
            {
                if (data[i] == DEL)
                {
                    throw("can't write to place that already deleted..");
                }
                Notebook::note[istr].at((unsigned int)col++) = data[i];
            }
        }
        else
        {
            while (len--)
            {
                istr = to_string(page) + "_" + to_string(row++);
                Notebook::note[istr].at((unsigned int)col) = data[i];
            }
        }
    }

    string Notebook::read(int page, int row, int col, Direction dir, int len)
    {
        Notebook::ckeck_args(page, row, col, len, dir);
        string ans;
        string line;
        if (dir == Direction::Horizontal)
        {
            line = to_string(page) + "_" + to_string(row);
            if (Notebook::note[line].size() == 0)
            {
                Notebook::note[line] = new_line;
            }
            while (len--)
            {
                ans += Notebook::note[line].at((unsigned int)col++);
            }
        }
        else
        {
            while (len--)
            {
                line = to_string(page) + "_" + to_string(row++);
                if (Notebook::note[line].size() == 0)
                {
                    Notebook::note[line] = new_line;
                }
                ans += Notebook::note[line].at((unsigned int)col);
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
            while (len--)
            {
                Notebook::note[line].at((unsigned int)col++) = DEL;
            }
        }
        else
        {
            line = to_string(page) + "_" + to_string(row++);
            while (len--)
            {
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
        unsigned long i = 0;
        int len = data.length();
        int wrong_chars = 32;
        char tmp;
        while (len--)
        {
            while (wrong_chars--)
            {
                tmp = wrong_chars;
                if (data[i] == tmp)
                {
                    cout << tmp << endl;
                    throw invalid_argument("invalid char");
                }
            }
            if (data[i] == 126 || data[i] == 127)
            {
                throw invalid_argument("invalid char");
            }
        }
    }
    

}
