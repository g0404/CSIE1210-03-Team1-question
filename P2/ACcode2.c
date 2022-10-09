#include<stdio.h>

int main(){
  int i,j,k,x,t,lineA,lineB,m,min,mini,y=0;
  int sc=0,hc=0;
  int BingoA[20]={0};
  int Win[20]={0};
  int leftA[20]={0};
  int straightA[4]={0};
  int horizontalA[5]={0};
  int compareA[20]={0};
  int BingoB[20]={0};
  int leftB[20]={0};
  int straightB[4]={0};
  int horizontalB[5]={0};
  int compareB[20]={0};
  for(i=0;i<20;i++){scanf("%d",&BingoA[i]);}
  for(i=0;i<20;i++){scanf("%d",&BingoB[i]);}
  scanf("%d",&k);
  scanf("%d",&x);
  for(i=0;i<x;i++){scanf("%d",&Win[i]);}
  for(i=0;i<20;i++){
    for(j=0;j<x;j++){
      if(BingoA[i]!=Win[j]){leftA[i]=1;}
      else{leftA[i]=0;break;}
    }
  }
  for(i=0;i<20;i++){
    for(j=0;j<x;j++){
      if(BingoB[i]!=Win[j]){leftB[i]=1;}
      else{leftB[i]=0;break;}
    }
  }
  while(1==1){
    for(i=0;i<4;i++){for(j=i;j<20;j+=4){sc+=leftA[j];}straightA[i]=sc;sc=0;}
    for(i=0;i<4;i++){for(j=i;j<20;j+=4){sc+=leftB[j];}straightB[i]=sc;sc=0;}
    for(i=0;i<20;i+=4){for(j=i;j<i+4;j++){hc+=leftA[j];}m=i/4;horizontalA[m]=hc;hc=0;}
    for(i=0;i<20;i+=4){for(j=i;j<i+4;j++){hc+=leftB[j];}m=i/4;horizontalB[m]=hc;hc=0;}
    for(i=0;i<20;i++){compareA[i]=horizontalA[i/4]*straightA[i%4]*leftA[i];}
    for(i=0;i<20;i++){compareB[i]=horizontalB[i/4]*straightB[i%4]*leftB[i];}
    min = 999;
    for(i=0;i<20;i++){
      if (compareA[i]<min&&compareA[i]!=0){min=compareA[i];mini=i;}
    }
    for(i=0;i<20;i++){
      if (BingoB[i]==BingoA[mini]){leftB[i]=0;break;}
    }
    leftA[mini] = 0;
    lineA =0;
    lineB =0;
    for(i=0;i<5;i++){if (horizontalA[i]==0){lineA+=1;}}
    for(i=0;i<4;i++){if (straightA[i]==0){lineA+=1;}}
    for(i=0;i<5;i++){if (horizontalB[i]==0){lineB+=1;}}
    for(i=0;i<4;i++){if (straightB[i]==0){lineB+=1;}}
    if(lineA>=k||lineB>=k){break;}
    for(i=0;i<4;i++){for(j=i;j<20;j+=4){sc+=leftA[j];}straightA[i]=sc;sc=0;}
    for(i=0;i<4;i++){for(j=i;j<20;j+=4){sc+=leftB[j];}straightB[i]=sc;sc=0;}
    for(i=0;i<20;i+=4){for(j=i;j<i+4;j++){hc+=leftA[j];}m=i/4;horizontalA[m]=hc;hc=0;}
    for(i=0;i<20;i+=4){for(j=i;j<i+4;j++){hc+=leftB[j];}m=i/4;horizontalB[m]=hc;hc=0;}
    for(i=0;i<20;i++){compareA[i]=horizontalA[i/4]*straightA[i%4]*leftA[i];}
    for(i=0;i<20;i++){compareB[i]=horizontalB[i/4]*straightB[i%4]*leftB[i];}
    min = 999;
    for(i=0;i<20;i++){
      if (compareB[i]<min&&compareB[i]!=0){min=compareB[i];mini=i;}
    }
    for(i=0;i<20;i++){
      if (BingoA[i]==BingoB[mini]){leftA[i]=0;break;}
    }
    leftB[mini] = 0;
    lineA =0;
    lineB =0;
    for(i=0;i<5;i++){if (horizontalA[i]==0){lineA+=1;}}
    for(i=0;i<4;i++){if (straightA[i]==0){lineA+=1;}}
    for(i=0;i<5;i++){if (horizontalB[i]==0){lineB+=1;}}
    for(i=0;i<4;i++){if (straightB[i]==0){lineB+=1;}}
    if(lineA>=k||lineB>=k){break;}
  }
  if(lineA>=k&&lineB>=k){printf("tie");}
  else if(lineA>=k){printf("CardA");}
  else{printf("CardB");}
  return 0;
}
