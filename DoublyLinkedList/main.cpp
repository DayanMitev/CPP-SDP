#include <iostream>

using namespace std;


class doubleLinkedList
{
private:
    doubleLinkedNode* first;
public:
    doubleLinkedList
    {
        first = null;
        last = null;
        size = 0;
    }
};

class doubleLinkedNode
{
public:
    int value;
    doubleLinkedNode *prev;
    doubleLinkedNode *next;

};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
