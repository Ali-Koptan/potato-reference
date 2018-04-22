#include <bits/stdc++.h>
using namespace std;
const int r = 1e7+7;
bool Prime[r];
void Generate(){
    memset(Prime, 1, sizeof Prime);
    Prime[0] = Prime[1] = 0;
    for (int i = 2; i <= r; i++)
        if (Prime[i])
            for (int j = i+i; j <= r; j += i)
                Prime[j] = 0;
}
int main(){
    Generate();
    for (int i = 0; i < 10; i++)
        cout << Prime[i] << ' ';
    return 0;
}

