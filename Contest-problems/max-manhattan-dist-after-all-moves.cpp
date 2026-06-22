class Solution {
public:
    int maxDistance(string moves) {
        int u=0,d=0,l=0,r=0,k=0;
        for(char ch : moves){
            if(ch=='U') u++;
            else if(ch=='D') d++;
            else if(ch=='L') l++;
            else if(ch=='R') r++;
            else k++;  //as every blank has an option to increase the distance by one;
        }

        int horizontal= abs(l-r);
        int vertical = abs(u-d);
        return horizontal+vertical+k;
        
    }
};
