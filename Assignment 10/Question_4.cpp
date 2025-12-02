#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    vector<int> nums = {4, 5, 1, 2, 0, 4};
    unordered_map<int, int> freq;
    for(int i : nums) freq[i]++;
    for(int i : nums){
        if(freq[i] == 1){
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}
