fixed size SW(window size given and sum/cnt/len find)
CONCEPT-->>i=0,j=0;
while(j<n){
 //calculation(e.g-sum+=arr[i])
 if(j-i+1<k)j++;/k=window size
 else if(j-i+1==k){
  //calculation for ans(e.g maxi=max(maxi,sum))
  //removing prev window cal(e.g sum-=arr[i]
  //moving pointer for next window;i++,j++
}
Q1. max sum subarray of size 'k'(if negative and zero is there than apply map method)
