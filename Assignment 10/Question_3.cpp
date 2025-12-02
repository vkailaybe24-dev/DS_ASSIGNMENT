#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    vector<int> nums = {2, 3, 2, 4, 3, 2};
    unordered_map<int, int> freq;
    for(int i : nums) freq[i]++;
    for(auto x : freq){
        cout<<x.first<<" -> "<<x.second<<" times"<<endl;
    }
    return 0;
}
