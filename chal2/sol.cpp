#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
#define MOD 1000000007

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string inFile =  "out";
    string outFile = "decoded.png";
    ifstream fin(inFile, ios::binary);
    ofstream fout(outFile, ios::binary);

    int n = 100, i = 0;
    vector<int> ans(n);

    for (int i = 1; i <= n; i += 2) {
        ans[i-1] = i+1;
        ans[i] = i;
    }

    char c;
    while(fin.get(c)){
        char outc = c ^ ans[i];
        fout.put(outc);
        i++;
        i %= n;
    }

    return 0;
}


// Sometimes, axios wings should collab too
