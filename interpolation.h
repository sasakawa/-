//最近内挿法
void nearest(double x,double y,int cols,int rows){

  if(x>0){
    x=x+0.5;
  }
  else{
    x=-1.0*floor(x+0.5);
  }
  if(y>0){
    y=y+0.5;
  }
  else{
    y=-1.0*floor(y+0.5);
  }

  printf("%lf\n",x);
}

//共１次内挿法
double bilinear(double x,double y,int cols,int rows,gray **image_val){
  //xとy付近の4点を計算
  //int p[2][2]={0};
  //double y_matrix[2][2]={0},x_matrix[2][2]={0};
  int i,j,k,l,pixel=0;
  int a,b;

  double P_value=0;

  k=(int)x;
  l=(int)y;

  if((k > 0) && (k < rows-1) && (l > 0) && (l < cols-1)){
    P_value = (k+1-x)*(l+1-y)*image_val[l][k] + (k+1-x)*(y-l)*image_val[l+1][k] + (x-k)*(l+1-y)*image_val[l][k+1] + (x-k)*(y-l)*image_val[l+1][k+1];
  }

  else P_value = 0;

  //pixel値を返す
  return P_value;
}

/*共3次内挿法
int bicubic(double x,double y,int cols,int rows,gray **image_val){
int i,k,l,pixel,x2,y2;
int y_matrix[4][4]={0},x_matrix={0},p[4][4]={0};

k=(int)x;
l=(int)y;

//この段階でk,lがcols,rows内に値あることを確認->ない時は？
if(k<0) k=0;
if(k>rows-1) k=rows;
if(l<0) l=0;
if(l>cols-1) l=cols;

//pの配列に値代入
for(i=-1;i<3;i++){
p[0][i+1]=image_val[l-1][k+i];
p[1][i+1]=image_val[l][k+i];
p[2][i+1]=image_val[l+1][k+i];
p[3][i+1]=image_val[l+2][k+i];
}

x2=x-k;
y2=y-l;




}*/
