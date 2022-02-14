#include <stdio.h>
#include <string.h>

void add(double number1, double number2)
{
    printf("Addition is %lf\n", number1+number2);
}
void subtract(double number1, double number2)
{
    printf("Subtraction is %lf\n", number1-number2);
}
void multiply(double number1, double number2)
{
    printf("Multiplication is %lf\n", number1*number2);
}

void divide(double number1, double number2)
{
    if(number2 == 0)
    {
        printf("Denominator can't be 0 in divide operation\n");
        return;
    }
    printf("Division is %lf\n",number1/number2);
}

int main()
{
    printf("Valid operations are :\n\"add\" for addition \n\"sub\" for subtraction\n\"mul\" for multiply \n\"div\" for divide\n");
    printf("Enter the operation you want to perform : ");
    // All operation are case insensitive i.e : add or Add or aDD or ADD etc. are valid;
    char operation[3];
    scanf("%s",&operation);

    printf("Enter two values to perform the operation : ");
    double number1, number2;
    scanf("%lf %lf",&number1,&number2);

    // Array of function pointer
    void (*fun_ptr_arr[])(double, double) = {add, subtract, multiply, divide};
    
    if(strcasecmp(operation,"add") == 0){
        (*fun_ptr_arr[0])(number1, number2);
    }
    else if(strcasecmp(operation,"sub") == 0){
        (*fun_ptr_arr[1])(number1, number2);
    }
    else if(strcasecmp(operation,"mul") == 0){
        (*fun_ptr_arr[2])(number1, number2);
    }
    else if(strcasecmp(operation,"div") == 0){
        (*fun_ptr_arr[3])(number1, number2);
    }
    else{
        printf("Invalid Operation\n");
    }
        
}