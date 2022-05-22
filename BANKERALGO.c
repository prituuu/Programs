#include<stdio.h>
#define size 100
int n;
int m;
int i,j;
int avail[10];
int max[10][10];
int alloc[10][10];
int need[10][10];
int finish[10];
int work[10];
int safe[10];
int sp;
int req[10];
int preq;
int calafterreq();
void calneed();
int calsafe();
void getalloc();
void getavail();
void getmax();
void getreq();
void putalloc();
void putavail();
void putmax();
void putneed();
void putsafe();
void putwork();
main ()
{
char choice;
printf("enter no of process \t");
scanf("%d",&n);
printf("enter no of resources \t");
scanf("%d",&m);
getavail();
getalloc();
getmax();
calneed();
putavail();
putalloc();
putmax();
putneed();
if(!calsafe())
{
printf("ERROR: system is not in safe sequence \n");
return 1;
}
putsafe();
printf("do you want to add a request? ( y for yes) \t");
scanf("%c",&choice);
if(choice!='y' && choice!='y')
return 0;
getreq();
switch (calafterreq())
{
case 1 :
puts("ERROR: contradiction to condition request <= need \n");
return 1;
case 2:
puts("ERROR: contradiction to condition request <= available \n");
return 1;
}
puts("\n \n data after proceesing of request\n");
putavail();
if(!calsafe())
{
printf("ERROR: system is not in safe sequence \n");
return 1;
}
putsafe();
}
int calafterreq()
{
int i,j;
for(j=0;j<m;j++)
{
if(!(req[j]<=need[preq][j]))
return -1;
if(!(req[j]<=avail[j]))
return -2;
alloc[preq][j]+= req[j];
avail[j] -= req[j];
}
}
void calneed()
{
int i,j;
for(i=0;i<n;i++)
for(j=0;j<m;j++)
need[i][j] = max[i][j] - alloc[i][j];
 }
int calsafe()
{
int countunfinished()
{
int i,unfinished;
for(unfinished=0,i=0;i<n;i++)
	if(finish[i]==0)
	unfinished++;
return unfinished;
}
int i,j;
int oldunfinished;
int newunfinished;
for(j=0;j<m;j++)
work[j]=avail[j];
newunfinished - n;
while(1)
{
oldunfinished = newunfinished;
for(i=0;i<n;i++)
{
if(finish[i])
continue;
for(j=0;j<m;j++)
if(!(need[i][j]<=work[j]))
break;
if(j==m)
{
safe[sp++]=i;
for(j=0;j<m;j++)
work[j] = work[j] + alloc[i][j];

finish[i]=1;
}
}
newunfinished = countunfinished();
if(newunfinished == 0)
return 1;
else if(newunfinished == oldunfinished)
return 0;
}
}
void getalloc()
{
int i,j;
printf("\n enter allocations ([proc][res])\n");
for(i=0;i<n;i++)
for(j=0;j<m;j++)
{
printf(" alloc[%d][%d]:\t",i,j);
scanf("%d",&alloc[i][j]);
}
}




void getavail()
{
int j;
printf("\n enter avaliable ([res])\n");
for(j=0;j<m;j++)
{
printf(" avaliable[%d]:\t",j);
scanf("%d",&avail[j]);
}
}



void getmax()
{
int i,j;
printf("\n enter maxes ([proc][res])\n");
for(i=0;i<n;i++)
for(j=0;j<m;j++)
{
printf(" max[%d][%d]:\t",i,j);
scanf("%d",&max[i][j]);
}
}



void getreq()
{
int j;
printf("\n enter the index of process to add request for, (index starts from 0)\t");
scanf("%d",&preq);
printf(" enter the request: ([res])\n");
for(j=0;j<m;j++)

printf(" request[%d]:\t",j);
scanf("%d",&req[j]);
}







void putalloc()
{
int i,j;
printf("\n allocations are: \n");
for(i=0;i<n;i++)
{
printf(" p%d \t",i);
for(j=0;j<m;j++)
printf("\n %d \t",alloc[i][j]);
printf("\n");
}
}





void putavail()
{
int j;
printf("\n avaliables are: \n");
for(j=0;j<m;j++)
printf("\n %d \t",avail[j]);
printf("\n");
}




void putmax()
{
int i,j;
printf("\n maxes are: \n");
for(i=0;i<n;i++)
{
printf(" p%d \t",i);
for(j=0;j<m;j++)
printf("\n %d \t",max[i][j]);
printf("\n");
}
}




void putneed()
{
int i,j;
printf("\n needs are: \n");
for(i=0;i<n;i++)
{
printf(" p%d \t",i);
for(j=0;j<m;j++)
printf(" %d \t",need[i][j]);
printf("\n");
}
}






void putsafe()
{
int i;
printf("\n safe sequence is: \n");
for(i=0;i<sp;i++)
printf(" %d \t",safe[i]);
printf("\n");
}




void putwork()
{
int j;
printf("\n work \n");
for(j=0;j<m;j++)
printf("%d \t",work[j]);
printf("\n");
}

