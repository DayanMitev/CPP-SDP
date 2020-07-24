#include <iostream>
#include <cassert>
using namespace std;


///pylno obhojdane samo na unikalni stoinosti

///[1,3,5,....,2n-1]
///srqda 13.00:15.00, petyk 12.00:17.00

void CountingSort(const char* arr, char* out, int n)
{
    const int size = 256;
    int count[size];
    for(int i = 0; i < size;++i)
    {
        count[i] = 0;
    }
    for(int i = 0; i < n; ++i)
    {
        int idx=  arr[i];
        ++count[idx];
    }
    int outidx = 0;
    for(int c = 0; c < size; ++c)
    {
        while(count[c])
        {
            out[outidx] = c;
            ++outidx;
            --count[c];
        }
    }
}
int main()
{
    const char* str = "aabzaz";
    char res[200];
    CountingSort(str, res, 6);
    for(int i = 0; i < 6; i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}
