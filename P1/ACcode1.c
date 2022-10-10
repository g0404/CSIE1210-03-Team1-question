#include <stdio.h>
#define bingo 20

int main(){
  int i,j,k,x,t,line,m,min,mini,y=0;
  int sc=0,hc=0;
  int Bingo[20]={0};
  int Win[20]={0};
  int left[20]={0};
  int straight[4]={0};
  int horizontal[5]={0};
  int compare[20]={0};
  int bn[20]={0};

  //input Bingonumber、k and winnumber
  for(i=0;i<20;i++){scanf("%d",&Bingo[i]);}
  scanf("%d",&k);
  scanf("%d",&x);
  for(i=0;i<x;i++){scanf("%d",&Win[i]);}

  //check
  if (1==0){
    printf("\nBingo: ");
    for(t=0;t<20;t++){printf("%d ",Bingo[t]);}
    printf("\nk: %d",k);
    printf("\nx: %d",x);
    printf("\nWin: ");
    for(t=0;t<x;t++){printf("%d ",Win[t]);}
  }

  //delete Winnumber
  for(i=0;i<20;i++){
    for(j=0;j<x;j++){
      if(Bingo[i]!=Win[j]){left[i]=1;}
      else{left[i]=0;break;}
    }
  }

  //check
  if (1==0){
    printf("left: ");
    for(t=0;t<20;t++){printf("%d ",left[t]);}
    printf("\n");
  }


  //play game
  while (1==1){
    //count how much number needed in straight line
    //for(t=0;t<4;j++){straight[t]=0;}
    for(i=0;i<4;i++){for(j=i;j<20;j+=4){sc+=left[j];}straight[i]=sc;sc=0;}

    //count how much number needed in horiazontal line
    //for(t=0;t<5;j++){horizontal[t]=0;}
    for(i=0;i<20;i+=4){for(j=i;j<i+4;j++){hc+=left[j];}m=i/4;horizontal[m]=hc;hc=0;}

    //check
    if (1==0){
      printf("straight: ");
      for(t=0;t<4;t++){printf("%d ",straight[t]);}
      printf("\n");
      printf("horizontal: ");
      for(t=0;t<5;t++){printf("%d ",horizontal[t]);}
      printf("\n");
    }

    //check line and win or not
    line =0;
    for(i=0;i<5;i++){if (horizontal[i]==0){line+=1;}}
    for(i=0;i<4;i++){if (straight[i]==0){line+=1;}}

    //check
    if (1==0){
    printf("line: %d\n",line);
    }

    if (line >=k){
      printf("%d\n",y);
      for (i=0;i<y;i++){printf("%d",bn[i]);if(i==y-1){break;}printf(" ");}
      break;
      }

    //establish compare matrix
    for(i=0;i<20;i++){compare[i]=horizontal[i/4]*straight[i%4]*left[i];}

    //check
    if (1==0){
      printf("compare: ");
      for(t=0;t<20;t++){printf("%d ",compare[t]);}
      printf("\n");
    }

    //find the best point chose
    min = 999;
    for(i=0;i<20;i++){
      if (compare[i]<min&&compare[i]!=0){min=compare[i];mini=i;}
    }

    //check
    if (1==0){
      printf("min: %d\n",min);
      printf("mini: %d\n",mini);
    }

    //choose the point
    left[mini] = 0;
    bn[y]=Bingo[mini];
    y += 1;

    //check
    if (1==0){
      for (t=0;t<y;t++){printf("%d ",bn[t]);}
      printf("\n");
      printf("y: %d\n",y);
    }
  }
}
