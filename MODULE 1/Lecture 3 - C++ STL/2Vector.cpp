#include <iostream>
#include <vector>
using namespace std;

void explainVector(){
    // creating
    cout<<"-----------CREATING-----------"<<endl;
    vector<int> v1;
    vector<int> v(10, 102);
    vector<int> v2(5,100);
    vector<pair<int,int>> v3;

    // Inserting
    cout<<"-----------INSERTING-----------"<<endl;
    v.push_back(1);
    v.emplace_back(2);
    v.insert(v.begin(), 100);
    v.insert(v.begin()+1, 200);
    
    // Traversing
    cout<<"-----------TRAVERSING-----------"<<endl;
    for(auto it : v){
        cout<<it<<" ";
    }
    cout<<endl;

    // Other Operations
    cout<<"-----------OTHERS-----------"<<endl;    
    cout<<v.at(0)<<endl;
    cout<<v.size()<<endl;
    cout<<v.back()<<endl;
    cout<<v.front()<<endl;
    cout<<v.empty()<<endl;
    
    // Deleting
    cout<<"-----------DELETING-----------"<<endl;
    v.pop_back();
    for(auto it : v){
        cout<<it<<" ";
    }
    cout<<endl;

    v.erase(v.begin()+1);
    for(auto it : v){
        cout<<it<<" ";
    }
    cout<<endl;

    v.erase(v.begin()+2, v.begin()+4);
    for(auto it : v){
        cout<<it<<" ";
    }
    cout<<endl;

    v.clear();
    for(auto it : v){
        cout<<it<<" ";
    }
    cout<<endl;

}

int main(){
    explainVector();
    return 0;
}