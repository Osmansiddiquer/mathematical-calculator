#include <stdio.h>

int main()
{
	float a, b;
	char op;
	printf("\n/////////////  A Better Calculator  \\\\\\\\\\\\\\\\\\\\\\\\");
	printf("\nOperates using 7 arithmetic operators.\n");
    printf("\n\n ______________________________________________\n");
    printf("/                     MENU                     \\\n");
    printf("| Choose from the following options:           |\n");       
    printf("|                                              |\n");
    printf("|     Addition (+)           Subtraction(-)    |\n");       
    printf("|                                              |\n");   
    printf("|   Product (x or *)          Division (/)     |\n");   
	printf("|                                              |\n");   
    printf("|    Square Root (s)          Cube Root (c)    |\n");      
    printf("|                                              |\n");       
    printf("|      Power (^)                 Exit (0)      |\n");
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
			if(b == 0)	printf("\tUndefined (Division by Zero!)\n");
			else	printf("%15g / %g = %g\n", a, b, a/b);
		    break;
		case 's':
			printf("Enter the number to take Sqaure Root of: ");
			scanf(" %f", &a);
			printf("\n____________________________________________\n\n");
		    float sqrt=1;
			if(a<0)	printf("\t\t Undefined\n");
			else
			{
				while(sqrt*sqrt>a+1e-5 || sqrt*sqrt<a-1e-5)
			    		sqrt = sqrt - (sqrt*sqrt-a)/(2*sqrt);  //using newton's method to solve for sqrt^2-a=0
				if(a==0)
					sqrt = 0;
				printf("      Square Root of %g = %g\n", a, sqrt);
			}
		    break;
		case 'c':
			printf("Enter the number to take Cube Root of: ");
			scanf(" %f", &a);
			printf("\n____________________________________________\n\n");
		    float cbrt=1;
			while(cbrt*cbrt*cbrt>a+1e-5 || cbrt*cbrt*cbrt<a-1e-5)
		    		cbrt = cbrt - (cbrt*cbrt*cbrt-a)/(3*cbrt*cbrt);  //using newton's method to solve for cbrt^3-a=0
			if(a==0)
				cbrt = 0;
			printf("        Cube Root of %g = %g\n", a, cbrt);
		    break;
		case '^':
			printf("Enter the Base and Exponenet(integer only) (a e): ");
			int e;
			scanf(" %f %d", &a, &e);
			printf("\n____________________________________________\n\n");
			float power = 1;
			if(e>0)
				for(int i=1; i<=e; i++)
					power *= a;
			else if(e<0)
				for(int i=1; i<=-e; i++)
					power /= a;
			if((a == 0) && (e == 0)) printf("\t\tINDERMINATE\n");
			else	printf("%15g^%d = %g\n", a, e, power);
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