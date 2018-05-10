#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "file_pgm.h"
#include "matrix.h"
#include "interpolation.h"
#include "other.h"


int main(void){

    typedef unsigned int gray;
    gray maxval=0,**image_val,**new_image;
    int cols=0,rows=0,i;
    //test用
    int n=3,cols2,rows2;
    double a,b,ang;
    double **matrix,**inv_a;

    //pgmファイルを読み込む関数を呼び出す 参照渡し
    read_pgm(&cols,&rows,&maxval,&image_val);

    //test start 拡大・縮小処理

    //matrixの領域確保
    matrix=(double **)malloc(3*sizeof(double *));
    for(i=0;i<3;i++){
        matrix[i]=(double *)malloc(3*sizeof(double));
    }
    //inv_aの領域確保
    inv_a=(double **)malloc(3*sizeof(double *));
    for(i=0;i<3;i++){
        inv_a[i]=(double *)malloc(3*sizeof(double));
    }

    //拡大する値確定→matrixの値を求める
    /*printf("x軸方向にいくつ拡大しますか？\n");
    scanf("%lf",&a);
    printf("y軸方向にいくつ拡大しますか？\n");
    scanf("%lf",&b);
    printf("now scaling start...\n");
    scaling(a,b,matrix); //matrixのみ参照渡し*/

    //回転
    /*
    printf("何度回転しますか？\n");
    scanf("%lf",&ang);

    rotation(ang,matrix);*/

    //せん断

    printf("何度せん断しますか？\n");
    scanf("%lf",&ang);

    skew_x(ang,matrix);

    //箱のサイズを計算 引数：matrix,cols,rows
    printf("now box start...\n");
    box(matrix,cols,rows,&cols2,&rows2);

    //逆行列の計算 matrixは値渡し、inv_aは参照渡し
    printf("now inverse start...\n");
    inverse(matrix,inv_a);

    //変換前から変換後の座標値を求めてimage_valに格納 image_valのみ参照渡し
    printf("now change start...\n");
    //new_imageの領域確保
    new_image=(gray **)malloc(rows2*sizeof(gray *));
    for(i=0;i<cols2;i++){
        new_image[i]=(gray *)malloc(rows2*sizeof(gray));
    }
    printf("new_image:領域確保...\n");
    change(image_val,cols2,rows2,inv_a,new_image,cols,rows);

    //matrix,inv_aの領域解放
    for(i=0;i<3;i++){
        free(matrix[i]);
    }free(matrix);
    for(i=0;i<3;i++){
        free(inv_a[i]);
    }free(inv_a);
    printf("matrix,inv_a:領域解放完了\n");

    //test finish
    printf("test finish\n");

    //pgmファイルを書き込む関数を呼び出す 値渡し
    write_pgm(cols2,rows2,maxval,new_image);

    //new_imageの領域解放
    for(i=0;i<cols2;i++){
        free(new_image[i]);
    }free(new_image);
    printf("new_image:領域解放完了\n");

    return 0;
}
