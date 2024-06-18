/*
Q16.COUNT OF SUBSTRING HAVING ATLEAST K UNIQUE CHARACTER
only operate,
n=str.size();
return n(n-1)-atmostdistinct(str,k-1);

Q17.LONGEST SUBSTRING HAVING ATLEAST K UNIQUE CHARACTER
if map contains k distinct element or greater than k that than return the size because len of longest string   becomes equal to size otherwise returns 0;

for(int i=0;i<n;i++){
mp[str[i]]++;
if(mp.size()>=k)return size;
} return 0;

*/