#include<bits/stdc++.h>
using namespace std;
int a, b;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b;
    while(a != 0 && b != 0){
        cout << a + b << '\n';
        cin >> a >> b;
    }
}