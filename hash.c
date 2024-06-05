#include<stdio.h>
int key,ht[50],i,size,value;
int main()
{
    printf("\n Enter the size of the table");
    scanf("%d",&size);
    
    for(i = 0; i < size; i++)
        	ht[i] = -1;
			
    printf("\n Enter the elements :");
    for(i=0;i<size;i++)
    {
        	scanf("%d",&value);
	key = value % size;
		
            if(ht[key] == -1)
	{   
		ht[key] = value;
        		printf("%d inserted at Hash Table[%d]\n", value,key);
    	}
    	else
    	{   
        		printf("Collision : Hash Table[%d] has element %d already!\n",   key,ht[key]);
        		printf("Unable to insert %d\n",value);
    	}
    }
	
printf("\n\n Hash table\n");
for(i = 0; i < size; i++)
        printf("Hash Table[%d] = %d\n",i,ht[i]);
    
	return 0;
    
}

