#include <iostream>
#include <map>
using namespace std;

void explainMap(){
    // creating
    cout<<"-----------CREATING-----------"<<endl;
    map<int,int> m;
    map<int, pair<int,int>> m1;

    // Inserting
    cout<<"-----------INSERTING-----------"<<endl;
    m[1] = 10;
    m.insert({2,20});
    m1.insert({1, {2,20}});

    // Traversing
    cout<<"-----------TRAVERSING-----------"<<endl;
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    // Other Operations
    cout<<"-----------OTHER OPERATIONS-----------"<<endl;
    cout<<"Size: "<<m.size()<<endl;
    cout<<"Empty: "<<m.empty()<<endl;

    // Deleting
    cout<<"-----------DELETING-----------"<<endl;
    m.erase(m.begin());
    m.clear();

}

int main(){
    explainMap();
    return 0;
}