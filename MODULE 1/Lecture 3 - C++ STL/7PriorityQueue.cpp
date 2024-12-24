#include <iostream>
#include <queue>
using namespace std;

void explainPriorityQueue(){
    // creating
    cout<<"-----------CREATING-----------"<<endl;
    priority_queue<int> pq; // Max Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Inserting
    cout<<"-----------INSERTING-----------"<<endl;
    pq.push(4);
    pq.push(3);
    pq.push(0);
    pq.emplace(2);

    // Traversing
    cout<<"-----------TRAVERSING-----------"<<endl;
    pq.top();

    // Other Operations
    cout<<"-----------OTHER OPERATIONS-----------"<<endl;
    cout<<"Top: "<<pq.top()<<endl;
    cout<<"Size: "<<pq.size()<<endl;
    cout<<"Empty: "<<pq.empty()<<endl;


    // Deleting
    cout<<"-----------DELETING-----------"<<endl;
    pq.pop();

}

int main(){
    explainPriorityQueue();
    return 0;
}