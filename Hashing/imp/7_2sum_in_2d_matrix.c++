//Q18.2 SUM IN 2D MATRIX

for(i=0->n){
 for(j=0->n){
  mp[arr[i][j]]++;
}}
for(i=0->n){
 for(j=0->n) {
  int rem=target -arr[i][j];
 if(mp.find(rem)!=mp.end()){
  if(rem==arr[i][j] && mp[rem]>=2) return true;
  return true;
}
}}
return false;