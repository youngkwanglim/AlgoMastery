#include<bits/stdc++.h>
using namespace std;
string s1, s2;
int main(){
    cin >> s1;
    s2 = s1;
    reverse(s1.begin(), s1.end());

    if(s1 == s2) cout << 1;
    else cout << 0;

    return 0;
}