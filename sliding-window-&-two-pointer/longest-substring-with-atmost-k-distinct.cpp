#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int kDistinctChars(int k, string &str)
{   
    if(k==0) return 0;
    int n=str.length();
    int len=0;
    int left=0;
    int maxLen=0;
    int right=0;
    unordered_map<char,int> mpp;
    while(right<n){
        mpp[str[right]]++;
        while(mpp.size()>k){
            mpp[str[left]]--;
            if(mpp[str[left]]==0) mpp.erase(str[left]);
            left++;
        }
        len=right-left+1;
        maxLen=max(maxLen,len);
        right++;
    }

    return maxLen;
}


