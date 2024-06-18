==>> VARIAVLE SIZE SW(condition given such as len/cnt/target and have to find window size)
CONCEPT-->>
while(j<n){
 //calculation(e.g sum+=arr[j])
 //if(condn<k)j++;
 else if(condn==k){
 //calc for answer(e.g maxlen=max(maxlen,j-i+1))
  j++;
  }
else if(condn>k){
 while(condn>k){
  //remove caln for prev window i;
  e.g sum-=arr[i];
  i++;
}
if(condn==k)//again condn hit do calculation
//move pointer 
j++;
}


