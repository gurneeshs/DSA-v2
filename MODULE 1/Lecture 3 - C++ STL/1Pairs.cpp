#include <iostream>
using namespace std;

void explainPairs(){
    pair<int, int> p = make_pair(1,2);
    cout<<p.first<<" "<<p.second<<endl;

    pair<int, pair<int,int>> p2 = {1, {2, 3}};
    cout<<p2.first<<" "<<p2.second.second<<endl;

    

}

int main(){

    cout<<"----------PAIRS-----------"<<endl;
    explainPairs();
    return 0;
}