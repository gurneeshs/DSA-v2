#include <iostream>
#include <unordered_map>
using namespace std;

void explainUnorderedMap(){
    // creating
    cout<<"-----------CREATING-----------"<<endl;
    unordered_map<int,int> m;
    unordered_map<int, pair<int,int>> m1;

    // Inserting
    cout<<"-----------INSERTING-----------"<<endl;
    m[1] = 10;
    m.insert({2,20});
    m.insert({3,30});
    m.insert({4,40});
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
    explainUnorderedMap();
    return 0;
}