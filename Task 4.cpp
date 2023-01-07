#include <stdio.h>
#include <iostream>

int main()
{
	while(1)
	{
	std::string expression, buffer;
	double op1, op2, result;
	int length = 0, dec_position = -1;
	printf("\n/////////////  A General Calculator  \\\\\\\\\\\\\\\\\\\\\\\\");
	printf("\n\tOperates using 7 arithmetic operators.\n");
	printf("\n ______________________________________________\n");
    printf("/             AVAILABLE OPERATIONS             \\\n");   
    printf("|                                              |\n");
    printf("|     Addition (+)           Subtraction(-)    |\n");       
    printf("|                                              |\n");   
    printf("|   Product (x or *)          Division (/)     |\n");   
	printf("|                                              |\n");   
    printf("|    Square Root (s)          Cube Root (c)    |\n");      
    printf("|                                              |\n");       
    printf("|                   Power (^)                  |\n");
    printf("|                Enter 0 to exit               |\n");
    printf("\\______________________________________________/\n\n");
    
    printf("Enter an Expression (without any spaces or brackets):\n");
    std::cin>>expression;
    printf("\n");
    if(expression == "0"){
    	printf("\n____________________________________________\n\n");
		printf("\t\tEXITING\n");
		printf("____________________________________________\n");
		goto end2;
	}
	//Some Error checking before proceeding and calculating length
	for(int i=0; expression[i]!='\0'; i++) 
	{
		if(!(expression[i] >= '0') || !(expression[i] <= '9'))
		{
			switch(expression[i])
			{
				case '*': case 'x': case '/': case '^':
					if(i==0)
					{
						printf("\n_____________________________________________\n\n");
						printf("SYNTAX ERROR: Expected number before %c at %d\n", expression[i], i+1);
						printf("_____________________________________________\n");
						goto end;
					}
					dec_position = -1;
					if(((expression[i+1] < '0') || (expression[i+1] > '9' ))
					 && (!(expression[i+1] == 's') && !(expression[i+1] == 'c') &&
					 !(expression[i+1] == '+') && !(expression[i+1] == '-')))
					{
						printf("\n_____________________________________________\n\n");
						printf("SYNTAX ERROR: Expected number at position %d\n", i+2);
						printf("_____________________________________________\n");
						goto end;
					}
					dec_position = -1;
					break;
				case '+': case '-':
					if((expression[i+1] < '0') || (expression[i+1] > '9' )
					 && (!(expression[i+1] == 's') && !(expression[i+1] == 'c')))
					{
						printf("\n_____________________________________________\n\n");
						printf("SYNTAX ERROR: Expected number at position %d\n", i+2);
						printf("_____________________________________________\n");
						goto end;
					}
					dec_position = -1;
					break;
				case 's': case 'c':
					if(i!=0 && (expression[i-1] >= '0') && (expression[i-1] <= '9'))
					{
						printf("\n_____________________________________________\n\n");
						printf("SYNTAX ERROR: Expected operator at position %d\n", i);
						printf("_____________________________________________\n");
						goto end;
					}
					if(!((expression[i+1] >= '0') || (expression[i] <= '9')) &&
					!((expression[i+1] == '+') || (expression[i+1] == '-')))
					{
						printf("\n_____________________________________________\n\n");
						printf("SYNTAX ERROR: Expected number at position %d\n", i+2);
						printf("_____________________________________________\n");
						goto end;
					}
					dec_position = -1;
					break;
				case '.':
					if(!((expression[i+1] >= '0') && (expression[i+1] <= '9'))){
						printf("\n_____________________________________________\n\n");
						printf(" SYNTAX ERROR: Expecting digits after Decimal \n\t  Point at position %d\n", i+1);
						printf("_____________________________________________\n");
						goto end;
					}
					if(dec_position != -1){
						printf("\n_____________________________________________\n\n");
						printf("    SYNTAX ERROR: Invalid Decimal Point \n\t\tat position %d\n", i+1);
						printf("_____________________________________________\n");
						goto end;
					}
					else
						dec_position = i;
					break;
				default:
				printf("\n_____________________________________________\n\n");
				printf("SYNTAX ERROR: Invalid Character at %d position\n", i+1);
				printf("_____________________________________________\n");
				goto end;
			}
		}
		length++;
	}
	
	for(int i=length-1; i>=0; i--)  //evaluating unary 's' and 'c' with right associativity
	{
		if(expression[i] == 's' || expression [i] == 'c'){
			op1 = 0;
			dec_position = -1;
			int Sign;
			Sign = 0;
			int j;
			for(j = i+1; (expression[j] >= '0') && (expression[j] <= '9') || (expression[j] == '.')
				|| ((expression[i+1] == '-' || expression[i+1] == '+') && (j==i+1)); j++){
				if((expression[i+1] == '+') && (j==i+1))
					Sign = 1;
				if((expression[i+1] == '-') && (j==i+1))
					Sign = -1;
				if(expression[j] == '.')
					dec_position = j;
			}
			int end = j;
			j--;
			for(;j>((Sign)?i+1:i);j--)
			{
				float multiplier = 1;
				if(dec_position==-1)
				{
					for(int i=j; i<end-1; i++)
						multiplier*=10;
					op1 += float(expression[j]-'0')*multiplier;
				}
				else{
					if(j==dec_position)
						continue;
					for(int i = 1; i<abs(j-dec_position); i++)
						multiplier*=10;
					if(j>dec_position && dec_position!=-1)
						op1 += float(expression[j]-'0')/multiplier/10;
					else
						op1 += float(expression[j]-'0')*multiplier;
				}
			}
			op1 = (Sign == -1)?-op1:op1;
			switch(expression[i])
			{
				case 's':
					if(op1<0)
					{
						printf("\n______________________________________________\n\n");
						printf("MATH ERROR: Negative Number inside Square Root\n", i+1);
						printf("______________________________________________\n");
						goto end;
					}
					else if(op1==0)
						result = 0;
					else
					{
						result = 1;
						while(result*result>op1+1e-5 || result*result<op1-1e-5)
				    		result = result - (result*result-op1)/(2*result);  //using newton's method to solve for result^2-op1=0
					}
					break;
	
				case 'c':
					if(op1==0)
						result = 0;
					else
					{
						result = 1;
						while(result*result*result>op1+1e-5 || result*result*result<op1-1e-5)
				    		result = result - (result*result*result-op1)/(3*result*result);  //using newton's method to solve for result^2-op1=0
					}
					break;
			}
			buffer = expression;
			expression = "";
			for(int k=0; k<i; k++){
				expression += buffer[k];
			}
			expression = expression + std::to_string(result);
			for(int k=end; k<length; k++){
				expression += buffer[k];
			}
			for(length=0; expression[length]!='\0'; length++){}
			i=length-1;
		}
	}
	
	for(int i=length-1; i>=0; i--)  //evaluating binary '^' with right associativity
	{
		if(expression[i] == '^'){
			op1 = 0;
			op2 = 0;
			dec_position = -1;
			int Sign;
			Sign = 0;
			int j;
			for(j = i+1; (expression[j] >= '0') && (expression[j] <= '9') || (expression[j] == '.')
				|| ((expression[i+1] == '-' || expression[i+1] == '+') && (j==i+1)); j++){
				if((expression[i+1] == '+') && (j==i+1))
					Sign = 1;
				if((expression[i+1] == '-') && (j==i+1))
					Sign = -1;
				if(expression[j] == '.')
					dec_position = j;
			}
			int end = j;
			j--;
			for(;j>((Sign)?i+1:i);j--)
			{
				float multiplier = 1;
				if(dec_position==-1)
				{
					for(int i=j; i<end-1; i++)
						multiplier*=10;
					op2 += float(expression[j]-'0')*multiplier;
				}
				else{
					if(j==dec_position)
						continue;
					for(int i = 1; i<abs(j-dec_position); i++)
						multiplier*=10;
					if(j>dec_position && dec_position!=-1)
						op2 += float(expression[j]-'0')/multiplier/10;
					else
						op2 += float(expression[j]-'0')*multiplier;
				}
			}
			op2 = (Sign == -1)?-op2:op2;
			
			dec_position = -1;
			for(j = i-1; (expression[j] >= '0') && (expression[j] <= '9') || (expression[j] == '.'); j--){
				if(expression[j] == '.')
					dec_position = j;
			}
			int start = j;
			j = i-1;
			for(;j>start;j--)
			{
				float multiplier = 1;
				if(dec_position==-1)
				{
					for(int k=j; k<i-1; k++)
						multiplier*=10;
					op1 += float(expression[j]-'0')*multiplier;
				}
				else{
					if(j==dec_position)
						continue;
					for(int i = 1; i<abs(j-dec_position); i++)
						multiplier*=10;
					if(j>dec_position && dec_position!=-1)
						op1 += float(expression[j]-'0')/multiplier/10;
					else
						op1 += float(expression[j]-'0')*multiplier;
				}
			}
			
			int exp = op2;
			if((op1 == 0) && (exp == 0)){
				printf("\n______________________________________________\n\n");
				printf("MATH ERROR: INDETERMINATE FORM at position %d\n", i+1);
				printf("______________________________________________\n");
				goto end;
			}
			result = 1;
			if(exp>0)
				for(int i=1; i<=exp; i++)
					result *= op1;
			else if(exp<0)
				for(int i=1; i<=-exp; i++)
					result /= op1;

			buffer = expression;
			expression = "";
			for(int k=0; k<=start; k++){
				expression += buffer[k];
			}
			expression = expression + std::to_string(result);
			for(int k=end; k<length; k++){
				expression += buffer[k];
			}
			for(length=0; expression[length]!='\0'; length++){}
			i=length-1;
		}
	}
	
	for(int i=0; i<length; i++)  //evaluating binary '*' and '/' with left associativity
	{
		if(expression[i] == '*' || expression [i] == 'x' || expression[i] == '/'){
			op1 = 0;
			op2 = 0;
			dec_position = -1;
			int Sign;
			Sign = 0;
			int j;
			for(j = i+1; (expression[j] >= '0') && (expression[j] <= '9') || (expression[j] == '.')
				|| ((expression[i+1] == '-' || expression[i+1] == '+') && (j==i+1)); j++){
				if((expression[i+1] == '+') && (j==i+1))
					Sign = 1;
				if((expression[i+1] == '-') && (j==i+1))
					Sign = -1;
				if(expression[j] == '.')
					dec_position = j;
			}
			int end = j;
			j--;
			for(;j>((Sign)?i+1:i);j--)
			{
				float multiplier = 1;
				if(dec_position==-1)
				{
					for(int i=j; i<end-1; i++)
						multiplier*=10;
					op2 += float(expression[j]-'0')*multiplier;
				}
				else{
					if(j==dec_position)
						continue;
					for(int i = 1; i<abs(j-dec_position); i++)
						multiplier*=10;
					if(j>dec_position && dec_position!=-1)
						op2 += float(expression[j]-'0')/multiplier/10;
					else
						op2 += float(expression[j]-'0')*multiplier;
				}
			}
			op2 = (Sign == -1)?-op2:op2;
			
			dec_position = -1;
			for(j = i-1; (expression[j] >= '0') && (expression[j] <= '9') || (expression[j] == '.'); j--){
				if(expression[j] == '.')
					dec_position = j;
			}
			int start = j;
			j = i-1;
			for(;j>start;j--)
			{
				float multiplier = 1;
				if(dec_position==-1)
				{
					for(int k=j; k<i-1; k++)
						multiplier*=10;
					op1 += float(expression[j]-'0')*multiplier;
				}
				else{
					if(j==dec_position)
						continue;
					for(int i = 1; i<abs(j-dec_position); i++)
						multiplier*=10;
					if(j>dec_position && dec_position!=-1)
						op1 += float(expression[j]-'0')/multiplier/10;
					else
						op1 += float(expression[j]-'0')*multiplier;
				}
			}
			
			switch(expression[i])
			{
				case '*': case'x':
					result = op1*op2;
					break;
				case '/':
					if(op2==0)
					{
						printf("\n______________________________________________\n\n");
						printf("   MATH ERROR: Division By 0 at position %d\n", i+2);
						printf("______________________________________________\n");
						goto end;
					}
					result = op1/op2;
					break;
			}
			buffer = expression;
			expression = "";
			for(int k=0; k<=start; k++){
				expression += buffer[k];
			}
			expression = expression + std::to_string(result);
			for(int k=end; k<length; k++){
				expression += buffer[k];
			}
			for(length=0; expression[length]!='\0'; length++){}
			i=0;
		}
	}
	
	for(int i=0; i<length; i++)  //evaluating binary '+' and '-' with left associativity
	{
		if(expression[i] == '+' || expression [i] == '-'){
			op1 = 0;
			op2 = 0;
			dec_position = -1;
			int Sign;
			Sign = 0;
			int j;
			for(j = i+1; (expression[j] >= '0') && (expression[j] <= '9') || (expression[j] == '.'); j++){
				if(expression[j] == '.')
					dec_position = j;
			}
			int end = j;
			j--;
			for(;j>((Sign)?i+1:i);j--)
			{
				float multiplier = 1;
				if(dec_position==-1)
				{
					for(int i=j; i<end-1; i++)
						multiplier*=10;
					op2 += float(expression[j]-'0')*multiplier;
				}
				else{
					if(j==dec_position)
						continue;
					for(int i = 1; i<abs(j-dec_position); i++)
						multiplier*=10;
					if(j>dec_position && dec_position!=-1)
						op2 += float(expression[j]-'0')/multiplier/10;
					else
						op2 += float(expression[j]-'0')*multiplier;
				}
			}
			op2 = (Sign == -1)?-op2:op2;
			
			dec_position = -1;
			for(j = i-1; (expression[j] >= '0') && (expression[j] <= '9') || (expression[j] == '.'); j--){
				if(expression[j] == '.')
					dec_position = j;
			}
			int start = j;
			j = i-1;
			for(;j>start;j--)
			{
				float multiplier = 1;
				if(dec_position==-1)
				{
					for(int k=j; k<i-1; k++)
						multiplier*=10;
					op1 += float(expression[j]-'0')*multiplier;
				}
				else{
					if(j==dec_position)
						continue;
					for(int i = 1; i<abs(j-dec_position); i++)
						multiplier*=10;
					if(j>dec_position && dec_position!=-1)
						op1 += float(expression[j]-'0')/multiplier/10;
					else
						op1 += float(expression[j]-'0')*multiplier;
				}
			}
			
			switch(expression[i])
			{
				case '+':
					result = op1+op2;
					break;
				case '-':
					result = op1-op2;
					break;
			}
			buffer = expression;
			expression = "";
			for(int k=0; k<=start; k++){
				expression += buffer[k];
			}
			expression = expression + std::to_string(result);
			for(int k=end; k<length; k++){
				expression += buffer[k];
			}
			for(length=0; expression[length]!='\0'; length++){}
			i=0;
		}
	}
	printf("\n_____________________________________________\n\n");
	std::cout<<"\t\t"<<expression<<std::endl;
	printf("_____________________________________________\n\n");
	end:
	system("PAUSE");
	}
	end2:
	printf("\n\n<<<<< Thank you for using the calculator! >>>>>>");
    return 0;
}