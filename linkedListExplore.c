
//Author: Chuanjing Guo
//compilation command : gcc -o list List.c

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

void sort(unsigned long  *arr, int n) {

    /* Sort the given array number, of length n */
    int j, i;
	unsigned long temp;

     for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (arr[i] > arr[j])
            {
                temp =  arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
////////////////////////////////////////////



int main(){

	unsigned int idData;
	char strData[50];
	int count=0;
	int entryInFile;
	int inputNumber=0;

	FILE * dataStream;	
	dataStream=fopen("/usr/class/cis660/Cse2421.Lab4.Data","r");
	rewind(dataStream);
	while(fscanf(dataStream," %s",&strData)!=EOF){
		count++;
		}
        entryInFile=count/2;

	unsigned long idArray[entryInFile];
	int entryInLink=0;

	rewind(dataStream);
	
	
	typedef struct node{
		char last[30];
		char first[20];
		unsigned int id;
		struct node *link;
	}ListNode;
/////////////////////////////////////////////////////////////////////////// return pointer functions
	ListNode *PointToMe(ListNode *here, unsigned long target){
		if(here==NULL){return NULL;}
		while(here->id!=target && here->link!=NULL){here=here->link;}
		if(here->id==target){return here;}
		return NULL;

		}
	ListNode *AfterMe(ListNode *here, unsigned long target){
		if(here==NULL){return NULL;}
		
		while(here->id<target && here->link!=NULL){
			here=here->link;
					}
		if(here->id>target){return here;}
		return NULL;

		}
	ListNode *BeforeMe(ListNode *here, ListNode *target){
		if(here==NULL){return NULL;}
		
		while(here->link!=target->link && here->link!=NULL){
			here=here->link;
					}
		if(here->link==target->link){return here;}
		return NULL;

		}
	
	ListNode *head;
	head= malloc(sizeof(ListNode));
	strcpy(head->last,"lastName");
	strcpy(head->first,"firstName");
	head->id=0;
	head->link=NULL;

	
	if(dataStream==NULL){
		printf("Error: The file does not exist. ");
		return 0;
		}
	else{
		while(fscanf(dataStream," %s %lu",&strData,&idData)!=EOF){
			inputNumber++;
			int k=0;
			while(strData[k]!='\0'){
					k++;
					}
			int boolVar=1;
			int i=0;
			int j=0;
			char firstTemp[]="                                      ";
			char lastTemp[]="                                       ";
			while(i<k){
				while(boolVar){
						if(strData[i]!=','){lastTemp[i]=strData[i];i++;}
						else{boolVar=0; lastTemp[i+1]='\0';}
						}
				firstTemp[j]=strData[i+1];
				j++;
				i++;
				}

				int pos=0;
				int found=0;
				while(pos<entryInFile){
					if(idData==idArray[pos]){found++;}	
				pos++;
				}
				if(found==0){
					idArray[entryInLink]=idData;
					entryInLink++;

					ListNode *tempNode;
					tempNode=malloc(sizeof(ListNode));
					strcpy(tempNode->last,lastTemp);
					strcpy(tempNode->first,firstTemp);
					tempNode->id=idData;
					tempNode->link=head;
					head=tempNode;
					

						}
				else{
					printf("Input: %d %s, %s its id=%lu already exists; Not added to the list !\n",inputNumber,lastTemp,firstTemp,idData);
						}
			}

	}
	printf("Number of nodes=%d\n",entryInLink);
//////////////////////////////////////////////////////////////////////////////////////////////////

	int k2=0;
		
	sort(idArray,entryInLink);

	ListNode *look;
	look=malloc(sizeof(ListNode));

	ListNode *update;
	update=malloc(sizeof(ListNode));

	ListNode *tempPtr;
	tempPtr=malloc(sizeof(ListNode));

	look=head;
	update=head;
	

	while(k2<entryInLink && update->link!=NULL){

		look=PointToMe(look, idArray[k2]);

		strcpy(tempPtr->last,update->last);
		strcpy(tempPtr->first,update->first);
		tempPtr->id=update->id;
		
		strcpy(update->last,look->last);
		strcpy(update->first,look->first);
		update->id=look->id;
		
		strcpy(look->last,tempPtr->last);
		strcpy(look->first,tempPtr->first);
		look->id=tempPtr->id;

		update=update->link;
		look=update;
		k2++;
		}
///////////////////////////////////////////////////
	printf("Enter p to print list, a to add node, d to delete node, e to exit: ");
	char decision;
	scanf(" %c",&decision);
	printf("You entered %c\n\n\n",decision);
	ListNode *tempPtr1;
	tempPtr1=malloc(sizeof(ListNode));

while(decision!='e'){

	if(decision=='p'){

		tempPtr1=head;
		int count3=0;
		while(tempPtr1->link!=NULL){
			count3++;
			printf("%d     %s    %s     %lu\n",count3,tempPtr1->last,tempPtr1->first,tempPtr1->id);
			tempPtr1=tempPtr1->link;
				}
			printf("Enter p to print list, a to add node, d to delete node, e to exit: ");
			scanf(" %c",&decision);
			printf("You entered %c\n\n\n",decision);
		}
	else if (decision=='a'){
		printf("Enter First, Last and id: ");
		char nlast[30];
		char nfirst[20];
		unsigned long newId;
		scanf(" %s %s %lu",&nfirst,&nlast,&newId);
		printf("You entered : %s %s %lu\n",nfirst, nlast,newId);
		char c;
		printf("Is it correct(y/n)?");
		scanf(" %c",&c);

		if(c=='y'){

				tempPtr1=head;
				while(tempPtr1->id!=newId && tempPtr1->link!=NULL){tempPtr1=tempPtr1->link;}
				if(tempPtr1->id==newId){printf("Input %s , %s  a node with its id=%lu already exists; Not added to the list!\n",nlast,nfirst,newId);}
				else{
					tempPtr1=head;
					tempPtr1=AfterMe(tempPtr1,newId);
					ListNode *newNode;
					newNode=malloc(sizeof(ListNode));
					strcpy(newNode->last,nlast);
					strcpy(newNode->first,nfirst);
					newNode->id=newId;
					newNode->link=tempPtr1->link;
					tempPtr1->link=newNode;
			
					ListNode *swap;
					swap=malloc(sizeof(ListNode));
			
					strcpy(swap->last,newNode->last);
					strcpy(swap->first,newNode->first);
					swap->id=newNode->id;
		
					strcpy(newNode->last,tempPtr1->last);
					strcpy(newNode->first,tempPtr1->first);
					newNode->id=tempPtr1->id;
		
					strcpy(tempPtr1->last,swap->last);
					strcpy(tempPtr1->first,swap->first);
					tempPtr1->id=swap->id;
			
					tempPtr1=head;

					int count3=0;
					while(tempPtr1->link!=NULL){
						count3++;
				
						tempPtr1=tempPtr1->link;
						}
						printf("Node added to the list; Number of nodes=%d\n",count3);
				}


		}
		printf("Enter p to print list, a to add node, d to delete node, e to exit: ");
		scanf(" %c",&decision);
		printf("You entered %c\n\n\n",decision);

	}//else if 
	else if(decision=='d'){

			printf("Enter node number to delete: ");
			int num;
			scanf(" %d",&num);
			printf("You entered: %d\n Is it correct(y/n)?",num);
			char c1;
			scanf(" %c",&c1);
			if(c1=='y'){
				int limit=0;
				tempPtr1=head;
				while(tempPtr1->link!=NULL){
						limit++;
						tempPtr1=tempPtr1->link;
						}
				tempPtr1=head;
				if(num==1){
					head=head->link;
					int count3=0;
						tempPtr1=head;
						while(tempPtr1->link!=NULL){
						count3++;
				
						tempPtr1=tempPtr1->link;
						}
						printf("Node deleted from the list; Number of nodes=%d\n",count3);
				}
				else if(num>limit){printf("Illegal Node number!\n");}

				else {
					int u=1;
					while(u<num-1){tempPtr1=tempPtr1->link;u++;}
						ListNode *before;
						before=malloc(sizeof(ListNode));
						before=head;
						before=BeforeMe(before,tempPtr1);
						
						tempPtr1=tempPtr1->link;
						
						before->link=tempPtr1->link;

						int count3=0;
						tempPtr1=head;
						while(tempPtr1->link!=NULL){
						count3++;
				
						tempPtr1=tempPtr1->link;
						}
						printf("Node deleted from the list; Number of nodes=%d\n",count3);
						}
				
				
					}

			printf("Enter p to print list, a to add node, d to delete node, e to exit: ");
			scanf(" %c",&decision);
			printf("You entered %c\n\n\n",decision);

			}

}//while e
			

fclose(dataStream);

return 0;
}

