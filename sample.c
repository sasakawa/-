#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <netpbm/pgm.h>

int main(int argc, char *argv[]){

  typedef unsigned int gray;
  gray maxval=0,**image_val,**new_image;
  int cols=0,rows=0;
    int num,num2; //変換の選択
    FILE *infile;
    
    
    
    printf("%s\n",argv[1]);
    infile = fopen(argv[1],"rb");
    
    image_val=pgm_readpgm(infile,&cols,&rows,&maxval);
    
    printf("幅：%d,高さ：%d,最大輝度値：%d\n",cols,rows,maxval);
    printf("読込完了\n");
    
    printf("拡大；1,回転；2,水平方向のせん断；3,鉛直方向のせん断；4\n");
    scanf("%d",&num);
    switch (num) {
        case 1:
            printf("拡大処理\n");
            break;
        case 2:
            printf("回転処理\n");
            break;
        case 3:
            printf("水平方向のせん断処理\n");
            break;
        case 4:
            printf("えん直方向のせん断処理\n");
            break;
        default:
            printf("1から4を選択してください\n");
            break;
    }
    
    if(0<num && num<5){
        printf("最近隣内挿法；1,共1次内挿法；2,共3次内挿法；3\n");
        scanf("%d",&num2);
        switch (num2) {
            case 1:
                printf("最近隣内挿法\n");
                break;
            case 2:
                printf("共1次内挿法\n");
                break;
            case 3:
                printf("共3次内挿法\n");
                break;
            default:
                printf("1から3を選択してください\n");
                break;
        }
    }

  return 0;

}
