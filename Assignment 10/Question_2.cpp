#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
void findCommon(vector<int>& A, vector<int>& B){
    unordered_set<int> s(A.begin(), A.end());
    cout<<"Output: ";
    for(int i : B){
        if(s.find(i) != s.end()){
            cout<<i<<" ";
            s.erase(i);
        }
    }
    cout<<endl;
}
int main(){
    vector<int> A = {1, 2, 3, 4};
    vector<int> B = {3, 4, 5, 6};
    findCommon(A, B);
    return 0;
}
