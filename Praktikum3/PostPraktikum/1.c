#include <stdio.h>
#include <string.h>

void FindAndCount(char a[], int count[], char target)
{
  for(int i = 0; i<26; i++)
  {
    if(a[i] == target)
    {
      count[i]++;
    }
  }
}


int CheckPalindrome(int count[], char a[])
{
  int result;
  int ganjil = 0;
  for(int i = 0; i<26; i++)
  {
//    printf("%c %d\n", a[i], count[i]);
    if(count[i]%2!=0)
    {
      ganjil++;
    }
  }
  if(ganjil>1)
  {
    result = 0;
  }
  else{
    result = 1;
  }
  return result;
}

int main(void)
{
  int count[26] ;
  for(int i = 0; i<26; i++)
  {
    count[i] = 0;
  }
  char alphabet[]="abcdefghijklmnopqrstuvwxyz";
  char s[1001];
  long len;
  scanf("%s", s);
  len = strlen(s);
   
  for(int i = 0; i<len; i++)
  {
    FindAndCount(alphabet,count,s[i]);
  }
  int result = CheckPalindrome(count, alphabet);
  if(result==1)
  {
    printf("YES\n");
  }
  else{
    printf("NO\n");
  }
  return 0;
}
