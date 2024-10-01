#include<bits/stdc++.h>
using namespace std;
int n, m, words[54];
string s;
int count(int mask){
    int cnt = 0;
    for(int word : words){
        if(word && (word & mask) == word) cnt++; 
    }
    return cnt;
}

int go(int index, int k, int mask){
    if(k < 0) return 0;
    if(index == 26) return count(mask);
    int ret = go(index + 1, k - 1, mask | (1 << index));
    if(index != 'a' - 'a' && index != 'n' - 'a' && index != 't' - 'a' && index != 'i' - 'a' && index != 'c' - 'a'){
        ret = max(ret, go(index + 1, k, mask));
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(char c : s){
            words[i] |= (1 << (c - 'a'));
        }
    }
    if(m < 5) cout << 0 << '\n';
    else cout << go(0, m, 0) << '\n';
}