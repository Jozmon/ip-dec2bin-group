#include <stdio.h>
#include <stdlib.h>


//because prompt is repeatable it became a function
void continue_prompt(){
	int ch;
	
	
    //press any key to continue prompt
    while ( (ch = getchar()) != '\n' && ch != EOF) ;
    
    printf("\n\n\n\n\n");
	printf("Press any key to continue\n");
    while ( (ch = getchar()) != '\n' && ch != EOF);	
	
	
}



void print_menu()
{
    printf("############################################################\n");
    printf("##                                                        ##\n");
    printf("##         Software Name:IP2BIN                           ##\n");
    printf("##         Author:Jozmon                                  ##\n");
    printf("##         Function:Convert ip to and from binary         ##\n");
    printf("##                                                        ##\n");
    printf("############################################################\n");
    printf("\n");
    printf("\n");
    printf("Select one of the following options:\n");
    printf("\n");
    printf(" 1. Decimal to binary\n");
    printf(" 2. Binary to decimal\n");
    printf(" 3. Exit\n");
    
}



void bin2dec(){
	
	//
	int binip[4];
	

	//
	int decip[4];
	
	//number of conversions
	int rep=5;
	int n=1;
	
	printf("Enter 32-bit IP address in dotted binary notation (xxx.xxx.xxx.xxx)\n: ");
	scanf ("%d.%d.%d.%d",&binip[1],&binip[2],&binip[3],&binip[4]);
	
	printf("\n\n\n");
	
	while ( n < rep ){
		
		//check ip validity
		if ( binip[n] > 11111111 || binip[n] < 0){
			printf("Invalid input string (incorrect numbers for IP address)\n");
		}
		
		//conversion variables
		int dec=0;
		int base=1;
		int bin;
		int rem;
		
		bin = binip[n];
		int tmp = bin;
		
		while ( tmp > 0  ) {
		
		rem  = tmp % 10;
		dec  = dec + rem * base;
		tmp  = tmp / 10;
		base = base * 2;
	
		}
	
		decip[n] = dec;
		++n;
		
	
	}
    printf("\n\n\n\n\n");
	printf ("The binary ip : %d.%d.%d.%d\n",binip[1],binip[2],binip[3],binip[4]);
	printf ("The decimal ip: %d.%d.%d.%d",decip[1],decip[2],decip[3],decip[4]);

	
	//prompt
	continue_prompt();

}



void dec2bin(){
	
	//ip in binary form
	//int binip[4];
	

	//ip in decimal form
	int decip[4];
	
	//number of conversions
	int rep=5;
	int n=1;
	
	printf("Enter 32-bit IP address in dotted decimal notation (xxx.xxx.xxx.xxx)\n: ");
	scanf ("%d.%d.%d.%d",&decip[1],&decip[2],&decip[3],&decip[4]);
    printf("\n\n\n\n\n");
	
	
	printf ("The decimal ip: %d.%d.%d.%d\n",decip[1],decip[2],decip[3],decip[4]);
	printf ("The binary ip :");
	
	while ( n < rep ){
		
		//check ip validity
		if ( decip[n] > 255 || decip[n] < 0){
			printf("Invalid input string (incorrect numbers for IP address)\n");
		}

		//binip[n] = dec2bin(decip[n]);
		// Stores binary representation of number.
		int bin[32]; // Assuming 32 bit integer.
		int i=0;
		int dec=decip[n];
		   
		while ( dec > 0 ){
			bin[i++] = dec % 2;
			dec = dec / 2;
		}
		   
		// Printing array in reverse order.
		int j = i-1;
			  
		while (j >= 0){
			printf("%d", bin[j]);
			j--;
		  }
		if (3 >= n){
		printf (".");
		}
		++n;
	
	}
	


	//prompt
	continue_prompt();
	

}



int main() {

int choice;
 
    do
    {
        print_menu();
        scanf("%d",&choice);
 
        switch(choice)
        {
            case 1: dec2bin(); break;
            case 2: bin2dec(); break;
            case 3: printf("Exiting program!\n"); exit(0); break;
            default: printf("Invalid choice!\n"); break;
        }
  } while (choice != 3);




  
  return 0;
  
  
}





