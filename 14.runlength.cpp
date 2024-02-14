string encode(string src)
{     
  //Your code here
  string ans="";
  int n=src.size();
  int i=0;
  int count=0;
  while(i<n)
  {
      char a=src[i];
      ans+=a;
      while(src[i]==a)
      {
          count++;
          i++;
      }
      ans+=to_string(count);
      count=0;
  }
  return ans;
}     
 
