#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#define eps 0.0001

unsigned int method_select( void );
double f( double x );
void print_result(double a, double b, unsigned int n, double I);
double left_rectangle(double a, double b, unsigned int n);
double right_rectangle(double a, double b, unsigned int n);
double trap(double a, double b, unsigned int n);
double simpson(double a, double b, unsigned int n);
//void test_unit();


int main()
{

   // test_unit();
   //getch();
   // return 0;

    unsigned int num_of_method; //1 - left, 2 - right, 3 - trap, 4 - Simpson
    const double a = -1;
    const double b = 1;
    unsigned int n = 1976;
    double I;
    double I1, I2;
    unsigned int N;



    num_of_method  =  method_select();

    if ( num_of_method == 1 ){
        I=left_rectangle(a, b, n);
        print_result (a, b, n, I);

  N = 0;

       do{
         N = N + 2;
         I1 = left_rectangle(a, b, N);
         I2 = left_rectangle(a, b, N+2);
        }
        while( fabs(I2-I1) > eps );

        printf("\n N=%u, I1(N)=%.6lf", N, I1);

    }
        else if ( num_of_method == 2 ){
            I=right_rectangle(a, b, n);
            print_result (a, b, n, I);

  N = 0;

       do{
         N = N + 2;
         I1 = right_rectangle(a, b, N);
         I2 = right_rectangle(a, b, N+2);
        }
        while( fabs(I2-I1) > eps );

        printf("\n N=%u, I1(N)=%.6lf", N, I1);

    }
        else if ( num_of_method == 3 ){
            I=trap(a, b, n);
            print_result(a, b, n, I);

  N = 0;

       do{
         N = N + 2;
         I1 = trap(a, b, N);
         I2 = trap(a, b, N+2);
        }
        while( fabs(I2-I1) > eps );

        printf("\n N=%u, I1(N)=%.6lf", N, I1);

    }

       else{
            I=simpson(a, b, n);
            print_result(a, b, n, I);

  N = 0;

       do{
         N = N + 2;
         I1 = trap(a, b, N);
         I2 = trap(a, b, N+2);
        }
        while( fabs(I2-I1) > eps );

        printf("\n N=%u, I1(N)=%.6lf", N, I1);

    }


    return 0;
}


//----------------------------------------------------------
//Вибір методу

unsigned int method_select(void)
{
    unsigned int temp;


    printf("\n\n Choose your method:\n1 - LEFT RECTANGLE \n2 - RIGHT RECTANGLE \n3 - TRAPEZOID \n4 - SIMPSON \n>");
    scanf ("%u", &temp);

    while(  temp < 1  ||  temp > 4  ){
        printf("\n!!!!!!Invalid data. Method: 1, 2, 3 or 4:\n>");
        scanf("%u", &temp);
    }

    switch(temp){
        case 1:
                printf("\nYou choose method or LEFT RECTANGLE");
                break;

        case 2:
                printf("\nYou choose method or RIGHT RECTANGLE");
                break;

        case 3:
                printf("\nYou choose method or TRAPEZOID");
                break;

        case 4:
                printf("\nYou choose method or SIMPSON");
                break;


    }


    return temp;

}

//----------------------------------------------------------
//формула інтегралу

double f(double x)
{
    double y;


    y = x/pow(1.1+x,2);


    return y;

}

//-----------------------------------------------------------
//Метод лівих прямокутників

double left_rectangle(double a, double b, unsigned int n)
{
    double h;
    unsigned int k;
    double x;
    double sum = 0;

    h = ( b - a ) / n;
    x = a;

    for (k = 0; k <= n-1; k++ ){
        sum = sum + f(x);
        x = x + h;
    }
    return sum * h;

}

//------------------------------------------------
// Метод правих прямокутників

double right_rectangle(double a, double b, unsigned int n)
{
    double h;
    unsigned int k;
    double x;
    double sum = 0;

    h = ( b - a ) / n;
    x = a;

    for (k = 1; k <= n; k++ ){
        sum = sum + f(x);
        x = x + h;
    }
    return sum * h;


}

//-------------------------------------------------
//Метод трапеції

double trap(double a, double b, unsigned int n)
{
    double h;
    unsigned int k;
    double x;
    double sum = 0;

    h = ( b - a ) / n;
    x = a;

    for (k = 1; k <= n-1; k++ ){
        sum = sum + (f(x)+f(x + h))/2;
        x = x + h;
    }
    return sum * h;

}

//-------------------------------------------------
//Метод Сімпсона

double simpson(double a, double b, unsigned int n)
{
    double h;
    unsigned int k;
    double x;
    double sum = 0;


    h = ( b - a ) / n;
    x = a;

    for (k = 1; k < n-1; k++)
    {
      sum = sum + (f(x)+4*f(x+h/2)+f(x+h))/6;
      x = x + h;
    }

    return sum * h;

}
//-------------------------------------------------

void print_result(double a, double b, unsigned int n, double I)
{


    system("cls");
    printf("\n\n------------------------------------------");
    printf("\n|                  Resault               |");
    printf("\n------------------------------------------\n");
    printf("| a=%.2lf | b=%.2lf | n=%u | I=%.6lf|", a, b, n, I);


}

/*
void test_unit()
{

    printf("Hello world");

}*/

//-----------------------------------------
