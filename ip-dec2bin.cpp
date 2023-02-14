#include <stdio.h>
#include <stdlib.h>


//because prompt is repeatable it became a function
void continue_prompt(){
	int ch;
    
	
    //absorb previous input
	do {
		ch = getchar();
	} while( ch != EOF && ch != '\n' );
    
    
    printf("\n\n\n\n\n");
	printf("Press any key to continue\n");
	
	//Waiting for new input
	do {
		ch = getchar();
	} while( ch != EOF && ch != '\n' );


	

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
    printf("\n");
    printf(" 1. Decimal to binary\n");
    printf(" 2. Binary to decimal\n");
    printf(" 3. Exit\n");
    printf("\n");
    printf("\n");
    printf("Select one of the following options: ");
}



void bin2dec(){
	
	//
	int binary_ip[4];
	

	//
	int decimal_ip[4];
	

	
	printf("Enter 32-bit IP address in dotted binary notation (xxx.xxx.xxx.xxx)\n: ");
	scanf ("%d.%d.%d.%d",&binary_ip[0],&binary_ip[1],&binary_ip[2],&binary_ip[3]);
	
	printf("\n\n\n");
	
	
	//checks each binary ip for errors
	int d_repetions=4;
	int d_loop_counter=0;
	
	while ( d_loop_counter < d_repetions ){
			// additional check to make sure each octet is binary
		int temp = binary_ip[d_loop_counter];
		
		while (temp != 0) {
			int digit = temp % 10;
			
			//check if digit is either 0 or 1
			if (digit != 0 && digit != 1) {
				printf("Conversion failed: Invalid input string %d (non-binary number)\n",binary_ip[d_loop_counter]);
				continue_prompt();
				return;
			}
			temp = temp / 10;
			++d_loop_counter;
		}
		
		
		//check if binary ip is within range
		
		if ( binary_ip[d_loop_counter] > 11111111 || binary_ip[d_loop_counter] < 0){
			printf("Invalid input string (Incorrect range for IP address part %d)\n",binary_ip[d_loop_counter]);
			continue_prompt();
			return;
		}
	}
	
	//number of conversions
	int n_repetions=4;
	int n_loop_counter=0;
	
	while ( n_loop_counter < n_repetions ){
		

		//conversion variables
		int decimal=0;
		int base=1;
		int binary_num = binary_ip[n_loop_counter];
		int remainder;
		
		
		while ( binary_num > 0  ) {
		
		remainder  = binary_num % 10;
		decimal  = decimal + remainder * base;
		binary_num  = binary_num / 10;
		base = base * 2;
	
		}
	
		decimal_ip[n_loop_counter] = decimal;
		++n_loop_counter;
		
	
	}
    printf("\n\n\n\n\n");
	printf ("The binary ip : %d.%d.%d.%d\n",binary_ip[0],binary_ip[1],binary_ip[2],binary_ip[3]);
	printf ("The decimal ip: %d.%d.%d.%d",decimal_ip[0],decimal_ip[1],decimal_ip[2],decimal_ip[3]);

	
	//prompt
	continue_prompt();

}



void dec2bin(){
	

	//ip in decimal form
	int decimal_ip[4];
	

	
	printf("Enter 32-bit IP address in dotted decimal notation (xxx.xxx.xxx.xxx)\n: ");
	scanf ("%d.%d.%d.%d",&decimal_ip[0],&decimal_ip[1],&decimal_ip[2],&decimal_ip[3]);
    printf("\n\n\n\n\n");
	
	
	printf ("The decimal ip: %d.%d.%d.%d\n",decimal_ip[0],decimal_ip[1],decimal_ip[2],decimal_ip[3]);
	printf ("The binary ip :");
	
	//error checking loop
	int b_loop_repetions=4;
	int b_loop_counter=0;
	
	while( b_loop_counter < b_loop_repetions ) {
		
		//check ip validity
		if ( decimal_ip[b_loop_counter] > 255 || decimal_ip[b_loop_counter] < 0){
			printf("Invalid input string (incorrect numbers for IP address)\n");
			
			continue_prompt();
			return;
		}
	++b_loop_counter;
	}

	//loop variables
	int a_loop_repetions=4;
	int a_loop_counter=0;
	
	//Gets each part of the ip and converts it.
	while ( a_loop_counter < a_loop_repetions ){
		
		// Stores binary representation of number.
		int bin[32];      // Assuming 32 bit integer.
		int i=0;          // Loop Counter
		int dec=decimal_ip[a_loop_counter]; // Temporary Variable To Use In Conversion
		   
		while ( dec > 0 ){
			bin[i++] = dec % 2;
			dec = dec / 2;
		}
		   
		// Printing array in reverse order.
		int r_loop_counter = i-1;
			  
		while (r_loop_counter >= 0){
			printf("%d", bin[r_loop_counter]);
			r_loop_counter--;
		  }
		//prints ip dots for loop counter
		if (2 >= a_loop_counter){
		printf (".");
		}
		++a_loop_counter;
	
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





