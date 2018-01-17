/* Author: Chuanjing Guo*/

#include<stdio.h>

int BinaryAdd(int in1, int in2){

	int carryIn=0;
	int carryOut=0;
	int sum=0;
	int digitA=0;
	int digitB=0;
	int result=0;
	int i=0;
	int finalCarryIn=0;

	for( i=0;i<32;i++){
		unsigned int uin1=in1;
		unsigned int uin2=in2;
		uin1=(uin1>>i);
		uin2=(uin2>>i);
		uin1=(uin1<<31);
		uin2=(uin2<<31);

	if(uin1==0){
 	digitA=0;
	}
	else{digitA=1;}

	if(uin2==0){
 	digitB=0;
	}
	else{digitB=1;}

				
if(digitA==0&&digitB==0&&carryIn==0){
sum=0;
carryOut=0;
}
else if (digitA==0&&digitB==0&&carryIn==1){
sum=1;
carryOut=0;
}
else if (digitA==0&&digitB==1&&carryIn==0){
sum=1;
carryOut=0;
}
else if (digitA==0&&digitB==1&&carryIn==1){
sum=0;
carryOut=1;
}
else if (digitA==1&&digitB==0&&carryIn==0){
sum=1;
carryOut=0;
}
else if (digitA==1&&digitB==0&&carryIn==1){
sum=0;
carryOut=1;
}
else if (digitA==1&&digitB==1&&carryIn==0){
sum=0;
carryOut=1;
}
else if (digitA==1&&digitB==1&&carryIn==1){
sum=1;
carryOut=1;
}


		
	sum=(sum<<i);
	result=(result|sum); 
	carryIn=carryOut;
	if(i==30){finalCarryIn=carryOut;}

}

printf("\nSum   =0x%08X As unsigned= %u As signed= %+d", result, result, result);


	if(carryOut==1){

	printf("\nUnsigned overflow.");

	}
	if(carryOut!=finalCarryIn){
	printf("\nsigned overflow.");
	
	}


	return result;

}






int main(){

int in1, in2;
printf("Give 2 integers in hex to add: ");
scanf(" %X %X",&in1,&in2);
unsigned int uin1=in1;
unsigned int uin2=in2;

printf("\nFirst = 0x%08X As unsigned= %u As signed= %+d",in1,uin1,in1);
printf("\nSecond =0x%08X As unsigned= %u As signed= %+d",in2,uin2,in2);

int result=BinaryAdd( in1,  in2);


return 0;
}