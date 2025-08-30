#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
#define MOD 1000000007

int32_t main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string inFile =  "in.png";
    string outFile = "out";
    ifstream fin(inFile, ios::binary);
    ofstream fout(outFile, ios::binary);

    int t=1, n = 100, i=0;
    vector<int> ans(n);

    // ans = https://codeforces.com/problemset/problem/1712/B

    char c;
    while(fin.get(c)){
        char outc = c ^ ans[i];
        fout.put(outc);
        i++;
        i=i%n;
    }

    return 0;
}