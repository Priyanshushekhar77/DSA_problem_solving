// single number -->> counting method,hashing method and xor method
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {

        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans = ans ^ nums[i];
        }
        return ans;
        // unordered_map<int,int>mp;
        // for(int i=0;i<nums.size();i++){
        //     mp[nums[i]]++;
        // }
        // for(auto it:mp){
        //     if(it.second==1) return it.first;
        // }
    }
};