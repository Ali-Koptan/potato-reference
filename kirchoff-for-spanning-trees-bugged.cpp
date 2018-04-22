#include <bits/stdc++.h>
using namespace std;
long long deg[50], arr[30][30], solve[30][30], xrr[30][30];
long long gosolve(long long a[30][30], int n){
    const double EPS = 1E-9;
    double det = 1;
    for (int i=0; i<n; ++i)
    {
        int k = i;
        for (int j=i+1; j<n; ++j)
            if (abs (a[j][i]) > abs (a[k][i]))
                k = j;
        if (abs (a[k][i]) < EPS)
        {
            det = 0;
            break;
        }
        swap (a[i], a[k]);
        if (i != k)
            det = -det;
        det *= a[i][i];
        for (int j=i+1; j<n; ++j)
            a[i][j] /= a[i][i];
        for (int j=0; j<n; ++j)
            if (j != i && abs (a[j][i]) > EPS)
                for (int k=i+1; k<n; ++k)
                    a[j][k] -= a[i][k] * a[j][i];
    }
    return det;
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i=0; i<m; i++){
            int a, b;
            scanf("%d%d", &a, &b);
            arr[b-1][a-1]=1;
            arr[a-1][b-1]=1;
            deg[a-1]++;
            deg[b-1]++;
        }
        for (int i=0; i<n; i++)
            arr[i][i]=deg[i];

        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                if (arr[i][j]==1 && i!=j)
                    arr[i][j]=-1;

        for (int i=1; i<n; i++)
            for (int j=1; j<n; j++)
                solve[i-1][j-1]=arr[i][j];

        for (int i=0; i<n-1; i++)
            for (int j=0; j<n-1; j++)
                xrr[i][j]=solve[i][j];

        cout<<gosolve(xrr, n-1)<<endl;
        memset(deg, 0, sizeof deg);
    }
    return 0;
}
