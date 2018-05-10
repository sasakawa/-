//箱のサイズ求める関数
void box(double **matrix,int cols,int rows,int *cols2,int *rows2){
    double x[4]={0,0,cols,cols};
    double y[4]={0,rows,0,rows};
    double u[4]={0},v[4]={0};
    double u_max=0,u_min=0,v_max=0,v_min=0;
    int i;

    //同順で変換後の値を求める
    for(i=0;i<4;i++){
        u[i]=x[i]*matrix[0][0]+y[i]*matrix[0][1];
        v[i]=x[i]*matrix[1][0]+y[i]*matrix[1][1];
    }

    //端４点でxとyの最大値と最小値を求める
    for(i=0;i<4;i++){
        //u_maxを求める
        if(u_max<u[i]){
            u_max=u[i];
        }
        //u_minを求める
        if(u[i]<u_min){
            u_min=u[i];
        }
        //v_maxを求める
        if(v_max<v[i]){
            v_max=v[i];
        }
        //v_minを求める
        if(v[i]<v_min){
            v_min=v[i];
        }
        printf("(%lf,%lf)\n",u[i],v[i]);
    }
    //箱のサイズを決める
    *cols2=u_max-u_min;
    *rows2=v_max-v_min;

    //結果出力
    printf("cols:%d,rows:%d\n",cols,rows);
    printf("cols2:%d,rows2:%d\n",*cols2,*rows2);

}

//座標計算の関数
void change(gray **image_val,int cols2,int rows2,double **inv_a,gray **new_image,int cols,int rows){

    int i,j,num;
    int xx,yy; //test
    double x,y;
    double pixel=0;


    printf("最近隣内挿法；1,共1次内挿法；2,共3次内挿法；3\n");
    scanf("%d",&num);
    for(i=0;i<cols2;i++){
        for(j=0;j<rows2;j++){

            //元画像の座標値を計算
            x=j*inv_a[0][0]+i*inv_a[0][1];
            y=j*inv_a[1][0]+i*inv_a[1][1];

            //型の変換
            xx=(int)x;
            yy=(int)y;


            //内挿処理スタート
            switch (num) {
                case 1:
                    //printf("最近隣内挿法\n");
                    if((xx > 0) && (xx < rows) && (yy > 0) && (yy < cols)){
                      new_image[i][j]=image_val[yy][xx];
                    }
                    else{
                      new_image[i][j]=0;
                    }
                    break;
                case 2:
                    //printf("共1次内挿法\n");

                    pixel=bilinear(x,y,cols,rows,image_val);
                    //printf("[%d][%d]pixel:%d\n",i,j,pixel);
                    new_image[i][j]=(int)pixel;

                    break;
                case 3:
                    //printf("共3次内挿法\n");
                    break;
                default:
                    printf("1から3を選択してください\n");
                    break;
            }
        }
    }
    printf("change end ...\n");

}
