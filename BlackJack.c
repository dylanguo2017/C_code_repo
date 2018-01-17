/*Author: Chuanjing Guo */


#include<stdio.h>

int getNumOfCards(){
	int result,number;
	printf("Please enter a number of cards(2-5): \n");
	scanf(" %d",&number);
	if(number==2||number==3||number==4||number==5){
		result=number;
		printf("Number of cards entered: %d\n",result);
	}
	else{
		result=0;
		printf("Number of cards entered is invalid.\n");
		}
	return result;
	
}

int checkFace(char f1,char f2, char f3, char f4, char f5){

	int result;
	if((f1=='2'||f1=='3'||f1=='4'||f1=='5'||f1=='6'||f1=='7'||f1=='8'||f1=='9'||f1=='t'||f1=='T'||f1=='j'||f1=='J'||f1=='q'||f1=='Q'||f1=='k'||f1=='K'||f1=='a'||f1=='A')                                               && 													(f2=='2'||f2=='3'||f2=='4'||f2=='5'||f2=='6'||f2=='7'||f2=='8'||f2=='9'||f2=='t'||f2=='T'||f2=='j'||f2=='J'||f2=='q'||f2=='Q'||f2=='k'||f2=='K'||f2=='a'||f2=='A')                                              && 													(f3=='2'||f3=='3'||f3=='4'||f3=='5'||f3=='6'||f3=='7'||f3=='8'||f3=='9'||f3=='t'||f3=='T'||f3=='j'||f3=='J'||f3=='q'||f3=='Q'||f3=='k'||f3=='K'||f3=='a'||f3=='A')                                              && 													(f4=='2'||f4=='3'||f4=='4'||f4=='5'||f4=='6'||f4=='7'||f4=='8'||f4=='9'||f4=='t'||f4=='T'||f4=='j'||f4=='J'||f4=='q'||f4=='Q'||f4=='k'||f4=='K'||f4=='a'||f4=='A')                                              && 													(f5=='2'||f5=='3'||f5=='4'||f5=='5'||f5=='6'||f5=='7'||f5=='8'||f5=='9'||f5=='t'||f5=='T'||f5=='j'||f5=='J'||f5=='q'||f5=='Q'||f5=='k'||f5=='K'||f5=='a'||f5=='A'))
	{
	result=1;
	}
	else{result=0;}
	
	return result;

}

int scoreCalculator(int numberOfCards, char f1, char f2, char f3, char f4, char f5){
	int sum=0;
	int n1=0, n2=0, n3=0, n4=0,n5=0, numberOfA=0;

	if(f1<=57&&f1>=50){
	n1=(int)(f1-48);
	}
	else if (f1=='a'||f1=='A'){
	numberOfA++;
	}
	else{n1=10;}

	if(f2<=57&&f2>=50){
	n2=(int)(f2-48);
	}
	else if (f2=='a'||f2=='A'){
	numberOfA++;
	}
	else{n2=10;}

	if(f3<=57&&f3>=50){
	n3=(int)(f3-48);
	}
	else if (f3=='a'||f3=='A'){
	numberOfA++;
	}
	else{n3=10;}

	if(f4<=57&&f4>=50){
	n4=(int)(f4-48);
	}
	else if (f4=='a'||f4=='A'){
	numberOfA++;
	}
	else{n4=10;}

	if(f5<=57&&f5>=50){
	n5=(int)(f5-48);
	}
	else if (f5=='a'||f5=='A'){
	numberOfA++;
	}
	else{n5=10;}
	
	if(numberOfCards==2){

		sum=n1+n2;
		while(numberOfA>0){
			if(21-sum>=11){
			sum=sum+11;
			}
			else{sum=sum+1;}
		numberOfA--;
		}
		
	}

	if(numberOfCards==3){

		sum=n1+n2+n3;
		while(numberOfA>0){
			if(21-sum>=11){
			sum=sum+11;
			}
			else{sum=sum+1;}
		numberOfA--;
		}
		
	}
	
	if(numberOfCards==4){

		sum=n1+n2+n3+n4;
		while(numberOfA>0){
			if(21-sum>=11){
			sum=sum+11;
			}
			else{sum=sum+1;}
		numberOfA--;
		}
		
	}

	if(numberOfCards==5){

		sum=n1+n2+n3+n4+n5;
		while(numberOfA>0){
			if(21-sum>=11){
			sum=sum+11;
			}
			else{sum=sum+1;}
		numberOfA--;
		}
		
	}



	return sum;
}


int getFaceAndScore(int numberOfCards)          {
	char f1='2',f2='2',f3='2',f4='2',f5='2';
	int numberOfCardsH=numberOfCards;
	int result;

	
	if(numberOfCardsH==2){
		printf("Please enter the faces of the cards,2-9,t,j,q,k,a: \n");
		scanf(" %c %c",&f1,&f2);
		if(checkFace(f1,f2,f3,f4,f5)){
			printf("Faces of cards entered= %c %c\n",f1,f2);
			result=scoreCalculator(numberOfCardsH, f1,f2,f3,f4,f5);

		}
		else{printf("The faces entered are invalid.\n");
			result=0;
			}
	
	}
	if(numberOfCardsH==3){
		printf("Please enter the faces of the cards,2-9,t,j,q,k,a: \n");
		scanf(" %c %c %c",&f1,&f2,&f3);
		if(checkFace(f1,f2,f3,f4,f5)){
			printf("Faces of cards entered= %c %c %c\n",f1,f2,f3);
			result=scoreCalculator(numberOfCardsH, f1,f2,f3,f4,f5);
		}
		else{printf("The faces entered are invalid.\n");
			result=0;
			}
	
	}
	if(numberOfCardsH==4){
		printf("Please enter the faces of the cards,2-9,t,j,q,k,a: \n");
		scanf(" %c %c %c %c",&f1,&f2,&f3,&f4);
		if(checkFace(f1,f2,f3,f4,f5)){
			printf("Faces of cards entered= %c %c %c %c\n",f1,f2,f3,f4);
			result=scoreCalculator(numberOfCardsH, f1,f2,f3,f4,f5);
		}
		else{printf("The faces entered are invalid.\n");
			result=0;
			}
	
	}
	if(numberOfCardsH==5){
		printf("Please enter the faces of the cards,2-9,t,j,q,k,a: \n");
		scanf(" %c %c %c %c %c",&f1,&f2,&f3,&f4,&f5);
		if(f1==f2&&f1==f2&&f1==f3&&f1==f4&&f1==f5){
			printf("Faces of cards entered= %c %c %c %c %c\n",f1,f2,f3,f4,f5);
			printf("You have 5 same faces, this is impossible. ");
			result=0;
		}
		else if(checkFace(f1,f2,f3,f4,f5)){
			printf("Faces of cards entered= %c %c %c %c %c\n",f1,f2,f3,f4,f5);
			result=scoreCalculator(numberOfCardsH, f1,f2,f3,f4,f5);
		}
		else{printf("The faces entered are invalid.\n");
			result=0;
			}
	
	}
	

return result;

}




int main(){

int ifContinue=1;
int numberOfCards;
int result;
char fk;

while(ifContinue){
	numberOfCards=getNumOfCards();
	if(numberOfCards==0){
		goto stop;
		}
	else{ result=getFaceAndScore(numberOfCards);

		if(result==0){goto stop;}
		else{
			if(result==21){printf("The value of your hand = %d -->BlackJack",result);}
			
			else if(result>21){printf("The value of your hand = %d -->Busted",result);}
			else{printf("The value of your hand = %d",result);}
			}
	 }
	

stop: printf("\nDo you want to continue? ('n' to quit, any other character to continue)\n");
	scanf(" %c",&fk);
	if(fk=='n'||fk=='N'){
		ifContinue=0;
	}

}




return 0;
}








