#include<bits/stdc++.h>
using namespace std;
int n, ret, cnt, d[200004];
string s;
stack<int> st;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s;
    st.push(-1);
    for(int i = 0; i < n; i++){
        if (s[i] == '(') st.push(i);
        else {
            st.pop();
            if(!st.empty()){
                ret = max(ret, i - st.top());
            } else{
                st.push(i);
            }
        }
    }
    cout << ret << '\n';
}