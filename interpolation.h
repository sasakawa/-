//最近内挿法
void nearest(double x,double y){
  if(x>0){
    x=floor(x+0.5);
  }
  else{
    x=-1.0*floor(x+0.5);
  }
  if(y>0){
    y=floor(y+0.5);
  }
  else{
    y=-1.0*floor(y+0.5);
  }
}

//共１次内挿法
int bilinear(double x,double y,int cols,int rows,gray **image_val){
  //xとy付近の4点を計算
  int p[2][2]={0};
  double y_matrix[2][2]={0},x_matrix[2][2]={0};
  int i,j,k,l,pixel=0;
  int a,b;

  k=(int)x;
  l=(int)y;

  //この段階でkとlがcolsとrows内に値あることを確認→ないときは範囲内に収まるように
  if(k < 0) k=0;
  if(k >= rows) k=rows-1;
  if(l < 0) l=0;
  if(l >= cols) l=cols-1;

  y_matrix[0][0]=(l+1)-y;
  y_matrix[0][1]=y-l;
  y_matrix[1][0]=(l+1)-y;
  y_matrix[1][1]=y-l;

  x_matrix[0][0]=(k+1)-x;
  x_matrix[0][1]=(k+1)-x;
  x_matrix[1][0]=x-k;
  x_matrix[1][1]=x-k;


  a=k+1;
  b=l+1;
  if(a >= cols){
    a=cols-1;
  }if(b >= rows){
    b=rows-1;
  }
  p[0][0]=image_val[l][k];
  p[0][1]=image_val[l][a];
  p[1][0]=image_val[b][k];
  p[1][1]=image_val[b][a];

    
  for(i=0;i<2;i++){
    for(j=0;j<2;j++){
      pixel+=x_matrix[i][j]*y_matrix[i][j]*p[i][j];
    }
  }


  if(pixel<0){
    pixel=0;
  }if(pixel>255){
    pixel=255;
  }
  
  //pixel値を返す
  return pixel;
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
