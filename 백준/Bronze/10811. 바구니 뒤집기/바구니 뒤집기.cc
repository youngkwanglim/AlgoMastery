#include<bits/stdc++.h>
using namespace std;
int n, m, a[104], b, c;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        a[i] = i;
    }
    for(int i = 1; i <= m; i++){
        cin >> b >> c;
        reverse(a + b, a + c + 1);
    }
    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
}