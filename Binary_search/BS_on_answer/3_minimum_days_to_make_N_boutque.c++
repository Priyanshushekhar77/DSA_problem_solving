/*
   Q. 1482. Leetcode(https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/)
 * You are given an integer array bloomDay, an integer m and an integer k.

   You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
   
   The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
   
   Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

   Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
Output: -1
Explanation: We need 3 bouquets each has 2 flowers, that means we need 6 flowers. We only have 5 flowers so it is impossible to get the needed bouquets and we return -1.
Example 3:

Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
Output: 12
Explanation: We need 2 bouquets each should have 3 flowers.
Here is the garden after the 7 and 12 days:
After day 7: [x, x, x, x, _, x, x]
We can make one bouquet of the first three flowers that bloomed. We cannot make another bouquet from the last three flowers that bloomed because they are not adjacent.
After day 12: [x, x, x, x, x, x, x]
It is obvious that we can make two bouquets in different ways.

 
 */

//here also answer lies between the range [minele,maxele] so apply the binary search for optimal solution o(NlogN) otherwise apply for loop solution o(N{pow(2)})

bool possible(vector<int>& bloomDay,int day, int a, int b){//b=colln of flower, a=no of boutique
int cnt=0;
int nofb=0;
for(int i=0;i< bloomDay.size();i++){
    if( bloomDay[i]<=day){
        cnt++;
    }
    else{
        nofb+=cnt/b;
        cnt=0;
    }
}
// after loop ended
 nofb+=cnt/b;
 
 if(nofb>=a) return true;
 else return false;
}

    int minDays(vector<int>& bloomDay, int m, int k) {
    long long val=k * 1LL * m * 1LL;  //handle overflow
	int n=bloomDay.size();
	if(val>n) return -1;// if(no. of boutique * colln of flower) > size
	int mini=INT_MAX, maxi=INT_MIN;
    //determine range
	for(int i=0;i<n;i++){
		mini=min(mini,bloomDay[i]);
		maxi=max(maxi,bloomDay[i]);
	}

	int low=mini;
	int high=maxi;
	int ans=0;
	while(low<=high){
		int mid=(low+high)/2;
		if(possible(bloomDay,mid,m,k)==true){
            ans=mid;
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	return ans;
        
    }