#include <stdio.h>
#include <stdlib.h>
int myDiv(int,int);
int main(int argc, char** argv) {
  
  int res, y, x=5; 

  for(y=1;y<10;y++)
    {
      res = myDiv(x,y);
      printf("%d %d %d\n",x,y,res);
    }
  return 0;
}

int myDiv(int x, int y) {
  return 1/((x-y)+20);
}
