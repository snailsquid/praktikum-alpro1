#include "stack.h"

void CreateStack(Stack *s)
{
  s->idxTop = IDX_UNDEF;
}

boolean isEmpty(Stack s)
{
  return (s.idxTop == IDX_UNDEF);
}

boolean isFull(Stack s)
{
  return (s.idxTop == CAPACITY - 1);
}
int length(Stack s)
{
  return s.idxTop + 1;
}
void push(Stack *s, ElType val)
{
  s->buffer[s->idxTop + 1] = val;
  s->idxTop++;
}
void pop(Stack *s, ElType *val)
{
  *val = s->buffer[s->idxTop];
  s->idxTop--;
}
void SortirStack(Stack *S1, Stack *S2)
{
    int l = S1->idxTop+1;
    // printf("l = %d\n", l);
    for(int i = 0; i<l; i++)
    {
        int elmt;
        pop(S1,&elmt );
        // printf("elemtn : %d\n", elmt);

        if(isEmpty(*S2))
        {
            push(S2, elmt);
        }
        else
        {
            int q = 0;
            
            while(elmt>S2->buffer[q] && q<S2->idxTop+1)
            {
                // printf("elmt : %d, S2[%d] : %d\n", elmt, q, S2->buffer[q]);

                q++;
            }

                    for(int k = length(*S2); k>=q; k--)
                    {
                        // printf("[%d] to [%d]\n", k, k+1);
                        S2->buffer[k+1] = S2->buffer[k];
                    }
                    // for(int o=0; o<length(*S2); o++)
                    // {
                        // printf("%d,\n", S2->buffer[o]);
                    // }
                    // printf("[%d] inserting %d\n", q, elmt);
                S2->buffer[q] = elmt;
                S2->idxTop++;
            





            // for(int j=0; j<length(*S2);j++)
            // {
            //     if(elmt > S2->buffer[j])
            //     {
            //         continue;
            //     }
                
            // }

        }
    }
}