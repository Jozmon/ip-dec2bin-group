#include <stdio.h>






void menu()
{
    printf("############################################################################\n");
    printf("##                                                                        ##\n");
    printf("##                 Software Name:IP2BIN                                   ##\n");
    printf("##                 Author:Jozmon                                          ##\n");
    printf("##                 Function:Convert ip to and from binary                 ##\n");
    printf("##                                                                        ##\n");
    printf("############################################################################\n");
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

	printf ("The binary ip : %d.%d.%d.%d\n",binip[1],binip[2],binip[3],binip[4]);
	printf ("The decimal ip: %d.%d.%d.%d",decip[1],decip[2],decip[3],decip[4]);

	
	

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
	
	printf ("The decimal ip: %d.%d.%d.%d\n",decip[1],decip[2],decip[3],decip[4]);
	
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
		printf (".");

		++n;
	
	}
	

	//printf ("The binary ip : %d.%d.%d.%d\n",binip[1],binip[2],binip[3],binip[4]);
	
	

}



int main() {
 int mode = 0;

 
while ( mode == 0 ){
	 
	 menu();
	 
	 
	 scanf  ("%d",&mode);
	 
	 
if ( mode == 1 ){


bin2dec();
	 
}else if( mode == 2){
			
dec2bin();
	
}
		
	 
	 
}
  
  
  
  return 0;
  
  
}



