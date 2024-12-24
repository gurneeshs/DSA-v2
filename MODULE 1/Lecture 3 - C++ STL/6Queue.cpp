#include <iostream>
#include <queue>
using namespace std;

void explainQueue(){
    // creating
    cout<<"-----------CREATING-----------"<<endl;
    queue<int> q;

    // Inserting
    cout<<"-----------INSERTING-----------"<<endl;
    q.push(4);
    q.emplace(5);

    // Traversing
    cout<<"-----------TRAVERSING-----------"<<endl;

    // Other Operations
    cout<<"-----------OTHER OPERATIONS-----------"<<endl;
    cout<<"Front: "<<q.front()<<endl;
    cout<<"Rear: "<<q.back()<<endl;
    cout<<"Empty: "<<q.empty()<<endl;
    cout<<"Size: "<<q.size()<<endl;

    // Deleting
    cout<<"-----------DELETING-----------"<<endl;
    q.pop();

}

int main(){
    explainQueue();
    return 0;
}