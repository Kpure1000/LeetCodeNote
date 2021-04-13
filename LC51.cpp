#include <vector>
#include <iostream>
#include <unordered_set>
#include <fstream>
using namespace std;

class Solution
{
public:
   vector<vector<string>> solveNQueens(int n){
        vector<vector<string>> reStrV;
        queen = vector<int>(n, -1);
        dfs(reStrV, n, 0);
        return reStrV;
    }

    void dfs(vector<vector<string>> &reStrV, int n, int r){
        if (r >= n){
            // Output
            auto newStrV = vector<string>();
            for (int i = 0; i < n; i++){
                string newStr=string(n, '.');
                newStr[queen[i]]='Q';
                newStrV.push_back(newStr);
            }
            reStrV.push_back(newStrV);
        }
        for (int i = 0; i < n; i++){
            if ((cal.find(i) == cal.end()) &&
               (sum.find(r + i) == sum.end()) &&
               (sub.find(r - i) == sub.end())){
                // Push
                queen[r] = i;
                cal.insert(i);
                sum.insert(r + i);
                sub.insert(r - i);
                // dfs
                dfs(reStrV, n, r + 1);
                // Pop
                int c = queen[r];
                cal.erase(c);
                sum.erase(r + c);
                sub.erase(r - c);
                queen[r]=-1;
            }
        }
    }

    vector<int> queen;
    unordered_set<int> cal;
    unordered_set<int> sum;
    unordered_set<int> sub;

};

int main()
{
    Solution s;
    int n;
    cin >> n;
    auto v = s.solveNQueens(n);
    int i = 1;
    ofstream fout("QueenOut.txt");
    fout << "Queen numbers: " << n;
    for (auto &it : v)
    {
        fout << "Solution " << i++ << ": \n";
        for(auto& it1 : it)
        {
            fout << it1 << "\n";
        }
    }
    fout << "Total Solutions: " << v.size() << "\n";
    fout.flush();
    fout.close();
    cout << "Total Solutions: " << v.size() << "\n";
}