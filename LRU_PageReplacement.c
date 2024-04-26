#include<stdio.h>

void lru(int n,int f,int p[]){
	
	int q[20],c=0,c1,d,i,j,k=0,r,t,b[20],c2[20];
	
	q[k]=p[k];
	printf("\n\t%d\n",q[k]);
	c++;
	k++;
	for(i=1;i<n;i++)
            {
                c1=0;
                    for(j=0;j<f;j++)
                    	{
                            if(p[i]!=q[j])
                            c1++;
                        }
                        if(c1==f)
                        {
                            c++;
                            if(k<f)
                            {
                                q[k]=p[i];
                                k++;
                                for(j=0;j<k;j++)
                                printf("\t%d",q[j]);
                                printf("\n");
                            }
                            else
                                {
                                    for(r=0;r<f;r++)
                                        {
                                        	c2[r]=0;
                                                for(j=i-1;j<n;j--)
                                            	{
                                                    if(q[r]!=p[j])
                                                    c2[r]++;
                                                	else
                                                    break;
                                                }
                                    }
                                    for(r=0;r<f;r++)
                                     b[r]=c2[r];
                                    for(r=0;r<f;r++)
                                    {
                                    	for(j=r;j<f;j++)
                                                {
                                                	if(b[r]<b[j])
                                                        {
                                                            t=b[r];
                                                            b[r]=b[j];
                                                            b[j]=t;
                                                        }
                                                }
                                    }
                                    for(r=0;r<f;r++)
                                    {
                                                if(c2[r]==b[0])
                                                q[r]=p[i];
                                                printf("\t%d",q[r]);
                                    }
                                    printf("\n");
                        }
            }
}
printf("\nThe no of page faults is %d",c);
}

void main()
{
	int p[50],np,frames;
	printf("Enter no of pages:");
	scanf("%d",&np);
	
	printf("Enter the reference string:");
	int i;
	for(i=0;i<np;i++)
        scanf("%d",&p[i]);
        
	printf("Enter no of frames:");
	scanf("%d",&frames);
	
	printf("LRU Algorithm:");
	lru(np,frames,p);
}
