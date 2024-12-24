#include <iostream>
#include <stack>
using namespace std;

void explainStack(){
    // creating
    cout<<"-----------CREATING-----------"<<endl;
    stack<int> st;

    // Inserting
    cout<<"-----------INSERTING-----------"<<endl;
    st.push(4);
    st.emplace(5);
    st.push(6);

    // Traversing
    cout<<"-----------TRAVERSING-----------"<<endl;
    // while(!st.empty()){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }
    // cout<<endl;

    // Other Operations
    cout<<"-----------OTHER OPERATIONS-----------"<<endl;
    cout<<"Top: "<<st.top()<<endl;
    cout<<"Empty: "<<st.empty()<<endl;
    cout<<"Size: "<<st.size()<<endl;


    // Deleting
    cout<<"-----------DELETING-----------"<<endl;
    st.pop();

}

int main(){
    explainStack();
    return 0;
}