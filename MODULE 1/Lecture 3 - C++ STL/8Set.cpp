#include <iostream>
#include <set>
using namespace std;

void explainSet(){
    // creating
    cout<<"-----------CREATING-----------"<<endl;
    set<int> st;

    // Inserting
    cout<<"-----------INSERTING-----------"<<endl;
    st.insert(1);
    st.emplace(2);
    st.insert(0);
    st.insert(1);

    // Traversing
    cout<<"-----------TRAVERSING-----------"<<endl;
    for(auto it:st){
        cout<<it<<" ";
    }
    cout<<endl;

    // Other Operations
    cout<<"-----------OTHER OPERATIONS-----------"<<endl;
    cout<<"Find: "<<*(st.find(1)) <<endl;
    cout<<"Size: "<<st.size()<<endl;
    cout<<"Empty: "<<st.empty()<<endl;
    cout<<"Count: "<<st.count(4)<<endl;

    // Deleting
    cout<<"-----------DELETING-----------"<<endl;
    st.erase(st.begin());
    st.clear();

}

int main(){
    explainSet();
    return 0;
}