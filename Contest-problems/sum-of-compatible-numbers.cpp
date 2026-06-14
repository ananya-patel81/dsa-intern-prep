class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int sum=0;
        int start= max(0,n-k); //imprtant!!!1
        for(int x=start ; x<=k+n;x++){
            if((n&x)==0) sum+=x;

        }
        return sum;
        
    }
};
