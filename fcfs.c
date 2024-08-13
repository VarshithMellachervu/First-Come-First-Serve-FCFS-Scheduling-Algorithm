#include<stdio.h>
int n,at[10],bt[10],r=-1,f=-1,t=0,q[10],gc[10][3],abig,ct[10];
void gantt();
void big();
void time();
void compt();
int main()
{
	int i,j;
	printf("Enter the no.of processes\n");
	scanf("%d",&n);
	printf("Enter the arival time of all process\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&at[i]);
	}
    big();
	printf("Enter the burst time of all process\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
	}

	gantt();
     printf("\n");
	// for(i=0;i<=r;i++)
	// {
	// 	for(j=0;j<3;j++)
	// 	{
	// 		printf("%d  ",gc[i][j]);
	// 	}
	// 	printf("\n");
	// }
    // printf("\n");
    compt();
    // for(i=0;i<n;i++)
    // {
    //     printf("%d ",ct[i]);
    // }
    printf("at  bt  ct  tat wt  rt\n");
    for(i=0;i<n;i++)
    {
        printf("%d   %d   %d   %d   %d   %d\n",at[i],bt[i],ct[i],ct[i]-at[i],ct[i]-at[i]-bt[i],ct[i]-at[i]-bt[i]);
    }
}
void big()
{
    int i;
    abig=at[0];
    for(i=0;i<n;i++)
    {
        if(abig<at[i]);
        abig=at[i];
    }
}
void gantt()
{
	int i,j,x=0,k,temp,l;
	for(i=0;i<=abig;i++)
	{
		for(j=0;j<n;j++)
		{
			if(at[j]==i)
			{
                x++;
                if(r==-1&&f==-1)
                {
                    r=0;
                    f=0;
                    q[r]=j+1;
                }
                else
                {
                    r++;
                    q[r]=j+1;
                }
			}
		}
        if(x==0)
        {
            if(r==-1&&f==-1)
            {
                r=0; f=0;
                q[r]=100;
            }
            else if(q[r]!=100)
            {
                r++;
                q[r]=100;
            }
            f=r;
        }
        if(x==1)
        {
            x=0;
            f=r;
        }
        if(x>1)
        {
            for(k=f;k<=r;k++)
            {
                for(l=k+1;l<r-k-1;l++)
                {
                    if(bt[q[k]]>bt[q[l]])
                    {
                        temp=q[k];
                        q[k]=q[l];
                        q[l]=temp;
                    }
                }
            }
            x=0;
            f=r;
        }
	}
    f=0;
    time();
}
void time()
{
    int t=0,i=f,t1;
    while(i<=r)
    {
        if((q[i]==100) && (at[q[i+1]-1]==t+1))
        {
            gc[i][0]=q[i];
            gc[i][1]=t;
            t=t+1;
            gc[i][2]=t;
            i++;
        }
        else if((q[i]==100) && (at[q[i+1]-1]!=t+1))
        {
            t1=t;
            while(at[q[i+1]-1]!=t)
                t++;
            gc[i][0]=q[i];
		    gc[i][1]=t1;
	    	gc[i][2]=t;
            i++;
        }
        else
        {
            gc[i][0]=q[i];
		    gc[i][1]=t;
	    	t=t+bt[q[i]-1];
	    	gc[i][2]=t;
            i++;
        }
    }
}
void compt()
{
    int i;
    for(i=0;i<=r;i++)
    {
        ct[gc[i][0]-1]=gc[i][2];
    }
}