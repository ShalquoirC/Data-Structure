#include<stdio.h>
#include<stdlib.h>
void merge(int* ele,int* temp,int low,int n1,int n2)
{
	int i = low, j = low + n1;
	i = low, j = low + n1;
	while(i <= low + n1 - 1 && j <= low + n1 + n2 - 1)
	{
		if(ele[i] <= ele[j])
			*temp++ = ele[i++];
		else
			*temp++ = ele[j++];
	}
    
	while(i <= low + n1 - 1)
		*temp++ = ele[i++];
    
	while(j <= low + n1 + n2 - 1)
		*temp++=ele[j++]; 

}
int main()
{
	int len;
	int* ele;
	int i, j, *temp,low, n1,n2,size=1;
	scanf("%d", &len);

	ele = (int*)malloc(len * sizeof(int));
	temp=(int*)malloc(2*len*sizeof(int));
	for (i = 0; i < len; i++)
	{
		scanf("%d", &ele[i]);
	}
	while(size<len)
	{
		low=0;
		while(low+size<len)
		{
			n1=size;
			if(low+size*2<len)
				n2=size;
			else
			    n2=len-low-size; 

			merge(ele,temp+low,low,n1,n2);
			low += n1 + n2;
        }
        
        for(i = 0; i < low; i++)
            ele[i] = temp[i];
        
        size *= 2;
    }
	printf("%d",ele[0]);
	for(i=1;i<len;i++)
		printf(" %d",temp[i]);
	printf("\n");
}
