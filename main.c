#include <stdio.h>
#include <stdlib.h>
int m=0;
void doicho(int arr[][10],int x1,int y1,int x2,int y2)
{
    int z=arr[x1][y1];
    arr[x1][y1]=arr[x2][y2];
    arr[x2][y2]=z;
}

int bool3(int a,int b)
{
    return 3-a-b;
}

void show(int arr[][10],int n)
{
    for(int j=0;j<n;j++)
    {
        printf("%d   %d   %d\n",arr[0][j],arr[1][j],arr[2][j]);
    }
    printf("C1  C2  C3\n");
    printf("\n");
}

void func(int arr[][10],int n,int j,int k)
{
    int kt=0;
    static int dem[3]={0};
    if(n==m) dem[0]=m;
    if(n==2&&dem[0]==m)
    {
        kt++;
        doicho(arr,j,0,bool3(j,k),m-1);
        show(arr,m);
        dem[j]--;
        dem[bool3(j,k)]++;

        doicho(arr,j,1,k,m-1);
        show(arr,m);
        dem[j]--;
        dem[k]++;

        doicho(arr,bool3(j,k),m-1,k,m-2);
        show(arr,m);
        dem[bool3(j,k)]--;
        dem[k]++;
    }
    if(n==2&&dem[0]!=m&&kt!=1)
    {
        doicho(arr,j,m-dem[j],bool3(j,k),m-dem[bool3(j,k)]-1);
        show(arr,m);
        dem[j]--;
        dem[bool3(j,k)]++;

        doicho(arr,j,m-dem[j],k,m-dem[k]-1);
        show(arr,m);
        dem[j]--;
        dem[k]++;

        doicho(arr,bool3(j,k),m-dem[bool3(j,k)],k,m-dem[k]-1);
        show(arr,m);
        dem[bool3(j,k)]--;
        dem[k]++;
    }
    if(n>2)
    {
    func(arr,n-1,j,bool3(j,k));
    {
        doicho(arr,j,m-dem[j],k,m-dem[k]-1);
        show(arr,m);
        dem[j]--;
        dem[k]++;
    }
    func(arr,n-1,bool3(j,k),k);
    }
}

int main()
{
    int arr[3][10]={0};
    int n;
    printf("Nhap so dia: ");
    scanf("%d",&n);
    m=n;
    for(int i=0;i<n;i++)
    {
        arr[0][i]=i+1;
    }
    printf("Vi tri ban dau:\n");
    show(arr,n);
    printf("\n");
    func(arr,n,0,1);
    return 0;
}






