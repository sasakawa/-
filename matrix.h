//matrixの値を計算する関数

//拡大・縮小
void scaling(double x,double y,double **matrix){
    int i,j;
    
    printf("scaling ...\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            matrix[i][j]=0;
        }
    }
    matrix[0][0]=x;
    matrix[1][1]=y;
    matrix[2][2]=1;
    
    printf("scaling end ...\n");
}

//回転
void rotation(double ang,double **matrix){
  int i,j;
  double rad;

  rad=ang*M_PI/180;
  
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      matrix[i][j]=0;
    }
  }
  matrix[0][0]=cos(rad);
  matrix[0][1]=sin(rad);
  matrix[1][0]=-sin(rad);
  matrix[1][1]=cos(rad);
  matrix[2][2]=1;

}

//せん断


//逆行列の計算関数
void inverse(double **a,double **inv_a){
    double buf;
    int i,j,k,n=3;
    
    //matrixの確認表示
    printf("matrix\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("[%.2lf]",a[i][j]);
        }printf("\n");
    }
    
    //単位行列を作る
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            inv_a[i][j]=(i==j)?1.0:0.0;
        }
    }
    //掃き出し法
    for(i=0;i<n;i++){
        buf=1/a[i][i];
        for(j=0;j<n;j++){
            a[i][j]*=buf;
            inv_a[i][j]*=buf;
        }
        for(j=0;j<n;j++){
            if(i!=j){
                buf=a[j][i];
                for(k=0;k<n;k++){
                    a[j][k]-=a[i][k]*buf;
                    inv_a[j][k]-=inv_a[i][k]*buf;
                }
            }
        }
    }
    
    //計算結果である逆行列の表示
    printf("inverse\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("[%.2lf]",inv_a[i][j]);
        }printf("\n");
    }
}


 
