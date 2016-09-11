/*2点間の距離を求める*/
double kyori(double x1,double y1,double x2,double y2){
double length;
length= sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
return length;
}
/*クラスタごとに中心を求める
（x or y座標,クラスタ番号を保存した配列,求めたい重心のクラスタ番号）*/
double center(double a[],int b[],int r){
int i;
int j;
int k;
int count =0;
double c  =0;
double cen;
for(i=0;i<100;i++){
if(b[i]==r){
c+=a[i];
count++;
}
}
cen=c/count;
return cen;
}

/*クラスタリング*/
void idle(void){
int i;
int j;
int class;
double cc,c0x,c0y,c1x,c1y,c2x,c2y,c3x,c3y,c4x,c4y,t1,t2;
cc=0;
/*各クラスタの重心を求める*/
c0x=center(t1,class,0);
c0y=center(t2,class,0);
c1x=center(t1,class,1);
c1y=center(t2,class,1);
c2x=center(t1,class,2);
c2y=center(t2,class,2);
c3x=center(t1,class,3);
c3y=center(t2,class,3);
c4x=center(t1,class,4);
c4y=center(t2,class,4);

for(i=0;i<100;i++){
/*クラスタの各重心との距離*/
k[0]=kyori(t1[i],t2[i],c0x,c0y);
k[1]=kyori(t1[i],t2[i],c1x,c1y);
k[2]=kyori(t1[i],t2[i],c2x,c2y);
k[3]=kyori(t1[i],t2[i],c3x,c3y);
k[4]=kyori(t1[i],t2[i],c4x,c4y);

/*一番近い重心を求める*/
double min=k[0];
int minnum=0;
for(j=1;j<5;j++){
if(min>k[j]){
min=k[j];
minnum=j;
cc++;
}
}

/*クラスタの変更*/
if(minnum==0)class[i]=0;
else if(minnum==1)class[i]=1;
else if(minnum==2)class[i]=2;
else if(minnum==3)class[i]=3;
else if(minnum==4)class[i]=4;
}
}