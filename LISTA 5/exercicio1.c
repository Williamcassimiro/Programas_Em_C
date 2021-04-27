#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
main(){
    int x=1,n;
    srand(time(NULL));
    while(x<=6){
        n=(rand()%50)+1;
        printf("%d, ",n);
        x++;
    }
}
