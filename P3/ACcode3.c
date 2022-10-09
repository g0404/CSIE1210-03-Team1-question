#include <stdio.h>
#define bingo 20

int main(){
  int i,j,k,x,t,lineA=0,lineB=0,m,minA,minB,miniA,miniB,y=0;
  int turn=0;
  int stop=1;
  int sc=0,hc=0;
  int BingoA[20]={0},BingoB[20]={0};
  int Win[20]={0};
  int leftA[20]={0},leftB[20]={0};
  int straightA[4]={0},straightB[4]={0};
  int horizontalA[5]={0},horizontalB[5]={0};
  int compareA[20]={0},compareB[20]={0};
  int bn[20]={0};
  int ti=1;
  int a=0,b=0;

  //input Bingonumber、k and winnumber
  for(i=0;i<20;i++){scanf("%d",&BingoA[i]);}
  for(i=0;i<20;i++){scanf("%d",&BingoB[i]);}
  scanf("%d",&k);
  scanf("%d",&x);
  for(i=0;i<x;i++){scanf("%d",&Win[i]);}
  
  //delete Winnumber for A
  for(i=0;i<20;i++){leftA[i]=1;}

  //delete Winnumber for B
  for(i=0;i<20;i++){
    for(j=0;j<x;j++){
      if(BingoB[i]!=Win[j]){leftB[i]=1;}
      else{leftB[i]=0;break;}
    }
  }

  //play game
  while (stop!=0){
    //count how much number needed in straight line
    for(i=0;i<4;i++){for(j=i;j<20;j+=4){sc+=leftA[j];}straightA[i]=sc;sc=0;}
    for(i=0;i<4;i++){for(j=i;j<20;j+=4){sc+=leftB[j];}straightB[i]=sc;sc=0;}

    //count how much number needed in horiazontal line
    for(i=0;i<20;i+=4){for(j=i;j<i+4;j++){hc+=leftA[j];}m=i/4;horizontalA[m]=hc;hc=0;}
    for(i=0;i<20;i+=4){for(j=i;j<i+4;j++){hc+=leftB[j];}m=i/4;horizontalB[m]=hc;hc=0;}

    //check line 
    lineA = 0;
    lineB = 0;
    //A
    for(i=0;i<5;i++){
        a=0;
        if (horizontalA[i]==0){
            for (t=0;t<x;t++){
                if (BingoA[i*4]==Win[t]||BingoA[i*4+1]==Win[t]||BingoA[i*4+2]==Win[t]||BingoA[i*4+3]==Win[t]){
                    a+=1;
                    break;
                }
            }
            if (a==0){lineA += 1;}
        }
    }
    for(i=0;i<4;i++){
        b=0;
        if (straightA[i]==0){
            for (t=0;t<x;t++){
                if (BingoA[i]==Win[t]||BingoA[i+1]==Win[t]||BingoA[i+2]==Win[t]||BingoA[i+3]==Win[t]||BingoA[i+4]==Win[t]){
                    b+=1;
                    break;
                }
            }
            if(b==0){lineB+=1;}    
        }
    }

    //B
    for(i=0;i<5;i++){if (horizontalB[i]==0){lineB+=1;}}
    for(i=0;i<4;i++){if (straightB[i]==0){lineB+=1;}}

    //Win or loose or tie
    if (lineA==lineB && lineA==k){printf("tie");ti=0;break;}
    else if (lineA >=k){printf("PlayerA");ti=0;break;}
    else if (lineB >=k ){printf("PlayerB");ti=0;break;}

    //establish compare matrix
    for(i=0;i<20;i++){compareA[i]=horizontalA[i/4]*straightA[i%4]*leftA[i];}
    for(i=0;i<20;i++){compareB[i]=horizontalB[i/4]*straightB[i%4]*leftB[i];}

    //find the best point chose for A
    minA = 999;
    for(i=0;i<20;i++){
      if (compareA[i]<minA&&compareA[i]!=0){minA=compareA[i];miniA=i;}
    }
    //find the best point chose for B
    minB = 999;
    for(i=0;i<20;i++){
      if (compareB[i]<minB&&compareB[i]!=0){minB=compareB[i];miniB=i;}
    }

    //circle the point
    //A's turn
    if (turn==0){
        for (t=0;t<20;t++){if (BingoA[t]==BingoA[miniA]){leftA[t]=0;}}
        for (t=0;t<20;t++){if (BingoB[t]==BingoA[miniA]){leftB[t]=0;}}
        turn = 1;
        }
    //B's turn
    else if (turn==1){
        for (t=0;t<20;t++){if (BingoA[t]==BingoB[miniB]){leftA[t]=0;}}
        for (t=0;t<20;t++){if (BingoB[t]==BingoB[miniB]){leftB[t]=0;}}
        turn = 0;
        }
    //count A is sufficient to play or not:0 will stop
    stop = 0;
    for (t=0;t<20;t++){stop +=leftA[t];}
  }
  //final check win or loss or tie
    if (ti==1){
        //count how much number needed in straight line
        for(i=0;i<4;i++){for(j=i;j<20;j+=4){sc+=leftA[j];}straightA[i]=sc;sc=0;}
        for(i=0;i<4;i++){for(j=i;j<20;j+=4){sc+=leftB[j];}straightB[i]=sc;sc=0;}

        //count how much number needed in horiazontal line
        for(i=0;i<20;i+=4){for(j=i;j<i+4;j++){hc+=leftA[j];}m=i/4;horizontalA[m]=hc;hc=0;}
        for(i=0;i<20;i+=4){for(j=i;j<i+4;j++){hc+=leftB[j];}m=i/4;horizontalB[m]=hc;hc=0;}

        //check line and win or not
        lineA = 0;
        lineB = 0;
        for(i=0;i<5;i++){
            a=0;
            if (horizontalA[i]==0){
                for (t=0;t<x;t++){
                    if (BingoA[i*4]==Win[t]||BingoA[i*4+1]==Win[t]||BingoA[i*4+2]==Win[t]||BingoA[i*4+3]==Win[t]){
                        a+=1;
                        break;
                    }
                }
                if (a==0){lineA += 1;}
            }
        }
        for(i=0;i<4;i++){
            b=0;
            if (straightA[i]==0){
                for (t=0;t<x;t++){
                    if (BingoA[i]==Win[t]||BingoA[i+1]==Win[t]||BingoA[i+2]==Win[t]||BingoA[i+3]==Win[t]||BingoA[i+4]==Win[t]){
                        b+=1;
                        break;
                    }
                }
                if(b==0){lineB+=1;}    
            }
        }
        for(i=0;i<5;i++){if (horizontalB[i]==0){lineB+=1;}}
        for(i=0;i<4;i++){if (straightB[i]==0){lineB+=1;}}
        if (lineA==lineB && lineA==k){printf("tie");}
        else if (lineA >=k){printf("PlayerA");}
        else if (lineB >=k ){printf("PlayerB");}
        else{printf("tie");}
    }
}