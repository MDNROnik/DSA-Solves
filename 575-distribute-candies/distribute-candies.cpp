#include <bits/stdc++.h>

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        map<int,int>mp;
        int n=candyType.size();
        for(int i=0;i<n;i++){
            mp[candyType[i]];
        }
        int can = n/2;
        int m=mp.size();
        
        return min(m,can);
    }
};