#include "chocolate.h"

/**
Function Name: gather_requirements
Input Params:  The starting address of the node where collected ingredients will be added
               one by one as collected
Return Type:   Updated starting address
Description:   Collect the input one by one and add the node to the end of the list.
               You need to add a routine that will check if we have required quantity
               of desired ingredients. Till then keep collecting the input.
**/
CF * insert_at_end(CF * newnode,int value,int q)
{
     CF *temp;
     static int q_i[5]={0};
     newnode=(CF *)malloc(sizeof(CF));
     if(newnode==NULL)
          printf("MEMORY ALLOCATION FAILED\n");    
     switch(value)
     {
          case 1:
               strcpy(newnode->choc_name,"beans_of_cocoa\0");

               newnode->quantity=q;
               q_i[0]+=q;
               if(q_i[0]>=200)
                    printf("REQUIRED QUANTITY COLLECTED\nDO NOT BUY AGIAN\n");
               break;
          case 2:
               strcpy(newnode->choc_name,"cups_of_cornstarch\0");
               newnode->quantity=q;
               q_i[1]+=q;
               if(q_i[1]>=10)
                    printf("REQUIRED QUANTITY COLLECTED\nDO NOT BUY AGIAN\n");
               break;
          case 3:
               strcpy(newnode->choc_name,"margarine_sticks\0");
               newnode->quantity=q;
               q_i[2]+=q;
               if(q_i[2]>=30)
                    printf("REQUIRED QUANTITY COLLECTED\nDO NOT BUY AGIAN\n");
               break;
          case 4:
               strcpy(newnode->choc_name,"yolks_of_egg\0");
               newnode->quantity=q;
               q_i[3]+=q;     
               if(q_i[3]>=100)
                    printf("REQUIRED QUANTITY COLLECTED\nDO NOT BUY AGIAN\n");
               break;
          case 5:
               strcpy(newnode->choc_name,"vanilla_strips\0");
               newnode->quantity=q;
               q_i[4]+=q;
               if(q_i[4]>=30)
                    printf("REQUIRED QUANTITY COLLECTED\nDO NOT BUY AGIAN\n");
               break;       
     }
     newnode->prev=NULL;
     newnode->next=NULL;
     return newnode;

     
}

CF * gather_requirements(CF * process )
{
     int q;
     int value;
     CF *newnode;
     CF *temp;
     while(1)
     {
          printf("ENTER YOUR CHOICE\n");
          printf("1-BEANS OF COCOA\n2-CUPS OF CORNSTARCH\n3-MARGARINE STICKS\n4-YOLKS OF EGG\n5-VANILLA STRIPS\n6-START PREPARING THE CHOCOLATE\n ");
          scanf("%d",&value);
          if(value!=6)
          {
               printf("ENTER THE QUANTITY REQUIRED\n");
               scanf("%d",&q);
          }
          else return process;
          newnode=insert_at_end(process,value,q);

          if(process==NULL)
               process=newnode;
          else
          {                    
               temp=process;
               while(temp->next!=NULL)
                    temp=temp->next;
               temp->next=newnode;
               newnode->prev=temp;
          }
          printf("INGRIDIENT COLLECTED\n");
     }
}


/**
Function Name: delete_node
Input Params:  The adress of the list to be removed
Return Type:   Updated starting address
Description:  Remove the node once the ingridients are added to the recepie
*/
CF * delete_node(CF *temp,CF * process)
{
	if(temp->prev==NULL)
	{
		temp->next->prev=NULL;
		process=temp->next;
	}
	else
	{
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
	}
	free(temp);
	return process;
}
/**
Function Name: add_cocoa
Input Params:  The starting address of the node where collected ingredients will be added
               one by one as collected
Return Type:   Integer
Description:   Add beans of cocoa to the recepie
*/
void add_cocoa(CF *process)
{
	CF *temp,*delete;
	int q=0;
	temp=process;
	while(temp->next!=NULL && q<=200 )
	{
		if((strcmp(temp->choc_name,"beans_of_cocoa\0"))==0)
		{
			if((q+temp->quantity)<=200)
				q+=temp->quantity;
			else
			{
				temp->quantity-=(200-q);
				q+=(200-q);

			}
			delete=temp;
			temp=temp->next;
			process=delete_node(delete,process);
		}
		else
			temp=temp->next;
	}	
	if(q<200)
	{
		printf("INSUFFICIENT INGRIDIENT QUANTITY\n");
		exit(1);
	}
}
/*
Function Name: add_cornstarch
Input Params:  The starting address of the node where collected ingredients will be added
               one by one as collected
Return Type:   Integer
Description:   Add cups of cornstarch to the recepie
*/

void add_cornstarch(CF *process)
{
	CF *temp,*delete;
	int q=0;
	temp=process;
	while(temp->next!=NULL && q<=10 )
	{
		if((strcmp(temp->choc_name,"cups_of_cornstarch\0"))==0)
		{

			if((q+temp->quantity)<=10)
				q+=temp->quantity;
			else
			{
				temp->quantity-=(10-q);
				q+=(10-q);

			}
			delete=temp;
			temp=temp->next;
			process=delete_node(delete,process);
		}
		else
			temp=temp->next;
	}	
	if(q<10)
	{
		printf("INSUFFICIENT INGRIDIENT QUANTITY\n");
		exit(1);
	}
}
/*
Function Name: add_sticks
Input Params:  The starting address of the node where collected ingredients will be added
               one by one as collected
Return Type:   Integer
Description:   Add margerine sticks to the recepie
*/
void add_sticks(CF *process)
{
	CF *temp,*delete;
	int q=0;
	temp=process;
	while(temp->next!=NULL && q<=30 )
	{
		if((strcmp(temp->choc_name,"margarine_sticks\0"))==0)
		{
			if((q+temp->quantity)<=30)
				q+=temp->quantity;
			else
			{
				temp->quantity-=(30-q);
				q+=(30-q);

			}
			delete=temp;
			temp=temp->next;
			process=delete_node(delete,process);
		}
		else
			temp=temp->next;
	}
	if(q<30)
	{
		printf("INSUFFICIENT INGRIDIENT QUANTITY\n");
		exit(1);
	}
}
/*
Function Name: add_egg
Input Params:  The starting address of the node where collected ingredients will be added
               one by one as collected
Return Type:   Integer
Description:   Add yolks of egg to the recepie
*/
void add_egg(CF *process)
{
	CF *temp,*delete;
	int q=0;
	temp=process;
	while(temp->next!=NULL && q<=100 )
	{
		if((strcmp(temp->choc_name,"yolks_of_egg\0"))==0)
		{
			if((q+temp->quantity)<=100)
				q+=temp->quantity;
			else
			{
				temp->quantity-=(100-q);
				q+=(100-q);

			}
			delete=temp;
			temp=temp->next;
			process=delete_node(delete,process);
		}
		else
			temp=temp->next;
	}
	if(q<100)
	{
		printf("INSUFFICIENT INGRIDIENT QUANTITY\n");
		exit(1);
	}
}
/*
Function Name: add_strips
Input Params:  The starting address of the node where collected ingredients will be added
               one by one as collected
Return Type:   Integer
Description:   Add vailla strips to the recepie
*/
void add_strips(CF *process)
{
	CF *temp,*delete;
	int q=0;
	temp=process;
	while(temp->next!=NULL && q<=30 )
	{
		if((strcmp(temp->choc_name,"vanilla_strips\0"))==0)
		{
			if((q+temp->quantity)<=30)
				q+=temp->quantity;
			else
			{
				temp->quantity-=(30-q);
				q+=(30-q);

			}
			delete=temp;
			temp=temp->next;
			process=delete_node(delete,process);
		}
		else
			temp=temp->next;
	}
	if(q<30)
	{
		printf("INSUFFICIENT INGRIDIENT QUANTITY\n");
		exit(1);
	}

}
/**
Function Name: melt_and_prepare
Input Params:  The starting address of the node where collected ingredients are available
Return Type:   NILL
Description:   Melt the ingredients in order as specified:
               200 Beans of Cocoa
               10 Cups of Cornstarch
               30 Margarine Sticks
               100 Yolks of egg
               30 Vanilla strips
               The ingredients may be available in different nodes at various positions
**/
void melt_and_prepare(CF * process)
{
	add_cocoa(process);
	printf("200 BEANS OF COCOA ADDED\n");
	add_cornstarch(process);
	printf("10 CUPS OF CORNSTARCH ADDED\n");
	add_sticks(process);
	printf("30 MARGARINE STICKS ADDED\n");
	add_egg(process);
	printf("100 YOLKS OF EGG ADDED\n");
	add_strips(process);
	printf("30 VANILLA STRIPS ADDED\n");
	printf("HAVE A FEAST!\n");
}
