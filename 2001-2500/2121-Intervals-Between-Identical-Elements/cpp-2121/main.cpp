/// Source : https://leetcode.com/problems/intervals-between-identical-elements/
/// Author : liuyubobobo
/// Time   : 2021-12-25

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Using Map and Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {

        int n = arr.size();
        map<int, vector<int>> table;
        for(int i = 0; i < n; i ++)
            table[arr[i]].push_back(i);

        vector<long long> res(n, 0);
        for(const pair<int, vector<int>>& p: table){
            const vector<int>& v = p.second;
            long long sum = 0ll;
            for(int i = 1; i < v.size(); i ++) sum += v[i] - v[0];
            res[v[0]] = sum;

            long long x = v.size() - 1, y = 1;
            for(int i = 1; i < v.size(); i ++){
                sum -= x * (v[i] - v[i - 1]);
                sum += y * (v[i] - v[i - 1]);
                res[v[i]] = sum;
                x --; y ++;
            }
        }
        return res;
    }
};


void print_vec(const vector<long long>& v){
    for(long long e: v) cout << e << ' ';
    cout << '\n';
}

int main() {

    vector<int> arr1 = {2,1,3,1,2,3,3};
    print_vec(Solution().getDistances(arr1));
    // 4 2 7 2 4 4 5

    vector<int> arr2 = {10,5,10,10};
    print_vec(Solution().getDistances(arr2));
    // 5 0 3 4

    return 0;
}
