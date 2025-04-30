#include <stdio.h>
#include <string.h>
#define MAX 10000
typedef struct
{
  int arr[MAX];
  int nEff;
  int isNeg;
} tab;
int toInt(char c)
{
  return c - '0';
}

tab createTab()
{
  tab t;
  t.nEff = 0;
  t.isNeg = 0;
  return t;
}
int push(tab *t, int c)
{
  t->arr[t->nEff] = c;
  t->nEff += 1;
  // printf("tab[%d] = %d\n", t->nEff, c);
}

int read(int m, tab *t)
{
  for (int i = 0; i < m; i++)
  {
    char c;
    scanf("%c", &c);
    if (c == '\n' || c == ' ')
    {
      i -= 1;
      continue;
    }
    if (c == '-')
    {
      i -= 1;
      t->isNeg = 1;
      continue;
    }
    // is not "-"
    int num = toInt(c);
    push(t, num);
  }
}

void printTab(tab t)
{
  char neg = t.isNeg ? '-' : '\0';
  printf("%c", neg);
  int isLeadingz = 1;
  for (int i = 0; i < t.nEff; i++)
  {
    if (t.arr[i] != 0 && isLeadingz)
    {
      isLeadingz = 0;
    }
    if (!isLeadingz)
      printf("%d", t.arr[i]);
  }
  if (isLeadingz)
    printf("0");
  printf("\n");
}

tab add(tab a, tab b)
{
  tab t = createTab();
  tab biggest = a.nEff > b.nEff ? a : b;
  // adding everything
  for (int i = 0; i < biggest.nEff; i++)
  {
    int added;
    int ia = 0, ib = 0;
    if (i < a.nEff)
    {
      ia = a.arr[a.nEff - i - 1];
      if (a.isNeg)
        ia *= -1;
    }
    if (i < b.nEff)
    {
      ib = b.arr[b.nEff - i - 1];
      if (b.isNeg)
        ib *= -1;
    }
    added = ia + ib;
    t.arr[biggest.nEff - i - 1] = added;
    t.nEff++;
  }

  // formatting everything
  for (int i = t.nEff - 1; i >= 0; i--)
  {
    int current = t.arr[i];
    if (i > 0)
    {

      if (current < 0)
      {
        t.arr[i] *= -1;
        if (t.arr[i] >= 10)
        {
          t.arr[i - 1] -= 1;
          t.arr[i] -= 10;
        }
      }
      else if (t.arr[i] >= 10)
      {
        t.arr[i - 1] += 1;
        t.arr[i] -= 10;
      }
    }
  }
  if (t.arr[0] < 0)
  {
    t.arr[0] = t.arr[0] * (-1);
    t.isNeg = 1;
  }
  return t;
}

int main()
{
  int m, n;
  scanf("%d %d", &m, &n);

  tab first = createTab();
  tab second = createTab();
  read(m, &first);
  read(n, &second);
  // printTab(first);
  // printTab(second);
  tab result = add(first, second);
  printTab(result);
}