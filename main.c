#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
void tr(float **a,int n,int i){
int k,j;
float max,t;
max=fabs(a[i][i]);
j=i;
for(k=i+1;k<n;k++){
  if(fabs(a[k][i])>max){
    j=k;
    max=fabs(a[k][i]);
  }
}
for(k=0;k<n+1;k++){
    t=a[i][k];
    a[i][k]=a[j][k];
    a[j][k]=t;
}
for(k=i;k<n;k++){
    if(a[k][i]!=0){
        for(j=i+1;j<n+1;j++){
            a[k][j]=1.0*(a[k][j]/a[k][i]);
        }
    a[k][i]=1;
    }
}
for(k=i+1;k<n;k++){
    if(a[k][i]!=0){
        for(j=0;j<n+1;j++){
            a[k][j]-=a[i][j];
        }
    }
}
    if(i<n-1){
    tr(a,n,i+1);
    }
}
int main()
{
    setlocale(LC_ALL,"Rus");
    float **a;
    float *x;
    int n,i,j;
    printf("Введите кол-во неизвестных и коэффициенты уравнений");
    scanf("%d",&n);
    x = (float**)malloc(n*sizeof(float*));
    a=(float**)malloc(n*sizeof(float*));
    for(i=0;i<n;i++){
        a[i]=(float*)malloc((n+1)*sizeof(float));
    }
    for(i=0;i<n;i++){
        for(j=0;j<n+1;j++){
            scanf("%f",&a[i][j]);
        }
    }
    printf("\nТреугольный вид:\n");
    tr(a,n,0);
    for(i=0;i<n;i++){
        x[n-1-i]=a[n-i-1][n];
        j = 0;
        while(j<i){
            x[n-1-i]-=x[n-1-j]*a[n-1-i][n-1-j];
            j++;
        }
    }

    for(i=0; i<n; i++, printf("\n")){
        for(j=0; j<n+1; j++)
            printf("%f ",a[i][j]);
}
printf("\nРешение:\n");
for(i=0;i<n;i++){
    printf("%f ",x[i]);
}
    return 0;
}
