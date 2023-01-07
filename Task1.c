#include <stdio.h>

int main()
{
	float a, b;
	char op;
	printf("\n/////////////  A Simple Calculator  \\\\\\\\\\\\\\\\\\\\\\\\");
	printf("\nOperates using only 4 basic arithmetic operators.\n");
	printf("\t\t( +  -  *  / )\n");
	printf("\n\n ______________________________________________\n");
	printf("/                     MENU                     \\\n");
	printf("| Choose from the following options:           |\n");       
	printf("|                                              |\n");
	printf("|     Addition (+)           Subtraction(-)    |\n");       
	printf("|                                              |\n");   
	printf("|   Product (x or *)          Division (/)     |\n");       
	printf("|                                              |\n");       
	printf("|                   Exit (0)                   |\n");
	printf("\\______________________________________________/\n\n");
	printf("Enter Option: ");
	scanf(" %c", &op);
	switch(op)
	{
		case '+':
			printf("Enter the Two Operands to Add (a b): ");
			scanf(" %f %f", &a, &b);
			printf("\n____________________________________________\n\n");
		    printf("%15g + %g = %g\n", a, b, a+b);
		    break;
		case '-':
			printf("Enter the Two Operands to Subtract (a b): ");
			scanf(" %f %f", &a, &b);
			printf("\n____________________________________________\n\n");
		    printf("%15g - %g = %g\n", a, b, a-b);
		    break;
		case '*':
		case 'x':
			printf("Enter the Two Operands to Multiply (a b): ");
			scanf(" %f %f", &a, &b);
			printf("\n____________________________________________\n\n");
		    printf("%15g * %g = %g\n", a, b, a*b);
		    break;
		case '/':
			printf("Enter the Two Operands to Divide (a b): ");
			scanf(" %f %f", &a, &b);
			printf("\n____________________________________________\n\n");
			if(b == 0)	printf("\tUndefined (Division By Zero)\n");
			else	printf("%15g / %g = %g\n", a, b, a/b);
		    break;
		case '0':
			printf("\n____________________________________________\n\n");
		    printf("                  EXITING\n");
		    break;
		default:
			printf("\n____________________________________________\n\n");
			printf("\nInvalid Choice. Please select from the ones \n\t   given in the menu.\n\n");
	}
	printf("____________________________________________\n");
	printf("\n\n<<<<< Thank you for using the calculator! >>>>>>");
	return 0;
}