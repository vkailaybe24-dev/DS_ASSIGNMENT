#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
bool hasDuplicate(vector<int>& nums){
    unordered_set<int> s;
    for(int i : nums){
        if(s.find(i) != s.end()) return true;
        s.insert(i);
    }
    return false;
}
int main(){
    vector<int> nums = {1, 2, 3, 1};
    if(hasDuplicate(nums)) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    return 0;
}
