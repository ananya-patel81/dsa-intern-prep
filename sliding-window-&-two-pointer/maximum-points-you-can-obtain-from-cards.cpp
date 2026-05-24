class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int maxScore=0;
        
        int score=0;
        for(int i=0; i<k; i++){
            score+=cardPoints[i];
            

        }
        maxScore=score;
        for(int i=0;i<k;i++){
            score-=cardPoints[k-1-i];
            score+=cardPoints[n-1-i];
            maxScore=max(maxScore,score);
        }

        return maxScore;
        
    }
};
