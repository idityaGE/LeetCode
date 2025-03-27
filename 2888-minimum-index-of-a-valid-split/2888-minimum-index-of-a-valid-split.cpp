class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        const int n=nums.size();
        unordered_map<unsigned, unsigned> freq;
        freq.reserve(n);
        int maxF=1, xM=0;
        for(int x: nums){
            unsigned& f=freq[x];
            if(++f>n/2){
                maxF=f;
                xM=x;
            }
        }
    //    cout<<"maxF="<<maxF<<", xM="<<xM<<endl;
        int cntxM=0;
        for(int i=0; i<n; i++){
            cntxM+=nums[i]==xM;
            if (cntxM*2>(i+1) && ((maxF-cntxM)*2>(n-i-1)))
                return i;
        }
        return -1;
    }
};