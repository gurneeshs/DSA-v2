#include <iostream>
#include <list>
using namespace std;

void explainList()
{
    // creating
    cout << "-----------CREATING-----------" << endl;
    list<int> l;

    // Inserting
    cout << "-----------INSERTING-----------" << endl;
    l.push_back(4);
    l.emplace_back(3);
    l.push_front(9);
    l.emplace_front(7);
    l.insert(l.begin(), 101);

    // Traversing
    cout << "-----------TRAVERSING-----------" << endl;
    for (auto it : l)
    {
        cout << it << " ";
    }
    cout << endl;

    // Other Operations
    cout << "-----------OTHER OPERATIONS-----------" << endl;
    cout << "Front: " << l.front() << endl;
    cout << "Back: " << l.back() << endl;
    cout << "Empty: " << l.empty() << endl;
    cout << "Size: " << l.size() << endl;

    // Deleting
    cout << "-----------DELETING-----------" << endl;
    l.pop_back();
    for (auto it : l)
    {
        cout << it << " ";
    }
    cout << endl;
    l.pop_front();
    for (auto it : l)
    {
        cout << it << " ";
    }
    cout << endl;
    l.clear();
    for (auto it : l)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    explainList();
    return 0;
}