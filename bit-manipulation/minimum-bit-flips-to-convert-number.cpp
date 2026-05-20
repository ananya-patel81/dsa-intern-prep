class Solution {
public:
    int minBitFlips(int start, int goal) {
        //do start^goal, and see the set bits, as those are the different bits and need to be flipped
        int xori= start^goal;
        int cnt=0;
        while(xori){
            xori&=(xori-1);
            cnt++;
        }
        return cnt;
        
    }
};
