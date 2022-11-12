//Maximum value with the choice of either dividing or considering as it is

#include <bits/stdc++.h>
using namespace std;
 

int maxDP(int n)
{
    int res[n + 1];
    res[0] = 0;
    res[1] = 1;
 
    
    for (int i = 2; i <= n; i++)
        res[i] = max(i, (res[i / 2]
                         + res[i / 3]
                         + res[i / 4]
                         + res[i / 5]));
 
    return res[n];
}
 

int main()
{
    int n = 60;
    cout << "MaxSum =" << maxDP(n);
    return 0;
}
