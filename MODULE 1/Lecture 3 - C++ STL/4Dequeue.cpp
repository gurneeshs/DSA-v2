#include <iostream>
#include <deque>
using namespace std;

void explainDequeue(){
    // creating
    cout<<"-----------CREATING-----------"<<endl;
    deque<int> dq;

    // Inserting
    cout<<"-----------INSERTING-----------"<<endl;
    dq.push_back(4);
    dq.push_front(6);
    dq.emplace_back(8);
    dq.emplace_front(3);
    dq.insert(dq.end(), 101);

    // Traversing
    cout<<"-----------TRAVERSING-----------"<<endl;
    for(auto it:dq){
        cout<<it<<" ";
    }
    cout<<endl;

    // Other Operations
    cout<<"-----------OTHER OPERATIONS-----------"<<endl;
    cout<<"Front: "<<dq.front()<<endl;
    cout<<"Back: "<<dq.back()<<endl;
    cout<<"Size: "<<dq.size()<<endl;
    cout<<"Empty: "<<dq.empty()<<endl;
    cout<<"At: "<<dq.at(1)<<endl;

    // Deleting
    cout<<"-----------DELETING-----------"<<endl;
    dq.pop_back();
    dq.pop_front();
    dq.clear();

}

int main(){
    explainDequeue();
    return 0;
}