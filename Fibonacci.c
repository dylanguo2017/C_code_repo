//Author: Chuanjing Guo//
#include<stdio.h>
#include<math.h>
#include <limits.h>

int main()
{
	unsigned long long first=1,second=1;
	int sizeN, count=2;
	unsigned long long temp=0;
	unsigned long long signal,signal2,signal3;
	unsigned long long max= LLONG_MAX;
	double median;
	char newLine='\n';

	FILE *FibonacciStream;
	FILE *EvenStream;
	FILE *OddStream;

	fopen("Fibonacci","w");
	fopen("Fibonacci.even","w");
	fopen("Fibonacci.odd","w");
	FibonacciStream=fopen("Fibonacci","a+");
	EvenStream=fopen("Fibonacci.even","a+");
	OddStream=fopen("Fibonacci.odd","a+");

	printf("Please enter the N for fibonacci numbers (N>=2): \n");
	scanf("%d",&sizeN);
	printf("You entered argument: %d\n", sizeN);
	
	if(sizeN<2){
		printf("The input N is illegal.");
		return 0;
			}
	else{
		fprintf(FibonacciStream,"%19llu %19llu ",first,second);
		printf("1.File Fibonacci content: \n");
		printf("%19llu %19llu ",first,second);
		if(sizeN!=2){
					
                     while(count<sizeN){
				temp=first+second;
				if(temp>first&&temp>second){
					first=second;
					second=temp;				
					fprintf(FibonacciStream,"%19llu ",temp);
					printf("%19llu ",temp);
					if((count+1)%4==0){
						fprintf(FibonacciStream,"%c",newLine);
						printf("%c",newLine);	
							}
					count++;
				}
				else{
					printf("\nunsigned overflow! cannot generate %d Fabonacci numbers.\n",sizeN);
					break;
					}
				
					}
							
				}
		printf("%c",newLine);
		printf("Total: %d numbers in Fibonacci\n",count);
		fflush(FibonacciStream);
		rewind(FibonacciStream);
			}
//Step 2 starts here//

		if(count%2==0){
			int des1=count/2;			
			unsigned long long t1, t2;
			while(des1>0){
				fscanf(FibonacciStream," %llu",&t1);
					des1--;
					}
			fscanf(FibonacciStream," %llu",&t2);
			
			median=(t1+t2)/2.0;
			}
		else{
			int des1=count/2+1;
			unsigned long long temp;
			while(des1>0){
				fscanf(FibonacciStream," %llu",&temp);
					des1--;
					}
			median=temp;
			}
	printf("\n2. The Fibonacci median: %.2f\n",median);

//Step 3
	int countEven=0;
	int countOdd=0;
	rewind(FibonacciStream);
	while(fscanf(FibonacciStream," %llu",&signal)!=EOF){
			if(signal%2==0){
					fprintf(EvenStream,"%19llu ",signal);
					countEven++;
					if((countEven)%4==0){
						fprintf(EvenStream,"%c",newLine);	
							}
					}
			else{
				fprintf(OddStream,"%19llu ",signal);
					countOdd++;
					if((countOdd)%4==0){
						fprintf(OddStream,"%c",newLine);	
							}
				}

				}
		printf("3. Total: %d numbers in Fibonacci.even\n",countEven);

		printf("   Total: %d numbers in Fibonacci.odd\n",countOdd);
		

		fflush(EvenStream);
		rewind(EvenStream);
		fflush(OddStream);
		rewind(OddStream);
		double resultME;
		double resultMO;
	if(countEven%2==0){
			int des1=countEven/2;			
			unsigned long long t1, t2;
			while(des1>0){
				fscanf(EvenStream," %llu",&t1);
					des1--;
					}
			fscanf(EvenStream," %llu",&t2);
			
			resultME=(t1+t2)/2.0;
			}
		else{
			int des1=countEven/2+1;
			unsigned long long temp;
			while(des1>0){
				fscanf(EvenStream," %llu",&temp);
					des1--;
					}
			resultME=temp;
			}
	if(countOdd%2==0){
			int des1=countOdd/2;			
			unsigned long long t1, t2;
			while(des1>0){
				fscanf(OddStream," %llu",&t1);
					des1--;
					}
			fscanf(OddStream," %llu",&t2);
			
			resultMO=(t1+t2)/2.0;
			}
		else{
			int des1=countOdd/2+1;
			unsigned long long temp;
			while(des1>0){
				fscanf(OddStream," %llu",&temp);
					des1--;
					}
			resultMO=temp;
			}
		printf("   Fibonacci.even median: %.2f\n", resultME);

		printf("   Fibonacci.odd median: %.2f\n", resultMO);
//Step 4

		rewind(EvenStream);
		fprintf(OddStream,"%c",newLine);
		int countEven2=0;
		while(fscanf(EvenStream," %llu",&signal2)!=EOF){
			
			fprintf(OddStream,"%19llu",signal2);
			countEven2++;
			if((countEven2)%6==0){
				fprintf(OddStream,"%c",newLine);	
							}
			
					}
		fflush(OddStream);
		rewind(OddStream);
		int countOdd2=0;
		while(fscanf(OddStream," %llu",&signal3)!=EOF){
		countOdd2++;
			}
		printf("\n4. Total count in Fibonacci.odd is now %d\n", countOdd2);
		rewind(OddStream);
		countOdd2=0;
		while(fscanf(OddStream," %llu",&signal3)!=EOF){
			printf("%9llu ",signal3);
			countOdd2++;
			if((countOdd2)%5==0){
				printf("%c",newLine);	
							}
		
			}
		fclose(FibonacciStream);
		fclose(EvenStream);
		fclose(OddStream);

	return 0;

}

