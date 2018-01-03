#include <iostream>
#include <string>
#include <stack>
//字母转换
using namespace std;
string src, dst, str_io;
void MatchString(void)
{
    stack<char> io;
    string temp;
    string::size_type i, j = 0;
    for (i = 0; i < str_io.size(); ++i)
    {
        if (str_io[i] == 'i')
            io.push(src[j++]);
        else
        {
            temp += io.top();
            io.pop();
        }
    }
    if (temp == dst)
    {
        for (i = 0; i < str_io.size(); ++i)
            cout << str_io[i] << " ";
        cout << endl;
    }
}
void ConvertString(int step, int count, int i_sum)
{
    if (step == src.size() * 2)            MatchString();
    else
    {
        if (i_sum < static_cast<int> (src.size()))
        {
            str_io += 'i';
            ++count;
            ++i_sum;
            ConvertString(step + 1, count, i_sum);
            --count;
            --i_sum;
            str_io.resize(str_io.size() - 1);
        }
        if (count > 0)
        {
            str_io += 'o';
            --count;
            ConvertString(step + 1, count, i_sum);
            str_io.resize(str_io.size() - 1);
            ++count;
        }
    }
}
int main(int argc, char *argv[])
{
    while (cin >> src >> dst)
    {
        cout << "[" << endl;
        ConvertString(0, 0, 0);
        cout << "]" << endl;
    }
    return 0;
}
