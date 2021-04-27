#include <stdio.h>
#include <stdlib.h>
 main(){
 float en,e=1;

 for(en=2;en<=200;en=en+2){
     if(e==1){
     e=e-(1/(en+1));
     en=2;
     }
     else{
    e=e+(1/en)-(1/(en+2));
    en=en+2;
 }}
 printf("A resposta de conta muito loka vai dar isso ó:%.2f",e);}
