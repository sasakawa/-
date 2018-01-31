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
    
    int i,j;
    double x,y;
    int pixel=0;
    
    for(i=0;i<cols2;i++){
        for(j=0;j<rows2;j++){
            
            //元画像の座標値を計算
            x=j*inv_a[0][0]+i*inv_a[0][1];
            y=j*inv_a[1][0]+i*inv_a[1][1];
            if(x >= cols){
                x=cols-1;
            }if(y >= rows){
                y=rows-1;
            }
            
            //内挿処理スタート
            //nearest(x,y);
            pixel=bilinear(x,y,cols,rows,image_val);
            printf("[%d][%d]pixel:%d\n",i,j,pixel);
            //new_image[i][j]=image_val[(int)y][(int)x];
            new_image[i][j]=pixel;
        }
    }
    printf("change end ...\n");
    
}


