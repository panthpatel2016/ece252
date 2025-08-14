#include <stdio.h> /*for other C related needs*/ 
#include <stdbool.h> /*for the boolean type (c doesnt have bools)*/
#include <string.h>
#include <errno.h> //error number.h file 

#define BUFFER_SIZE 1000
#define VALUE (2 * 25 + 4) //always use brackets for computations because c is super literal

// this could be used as 
// char * buffer = malloc ( BUFFER_SIZE ); 



extern int errno; //it is used to declare a variable or function that is defined in another source file. for eg <errno.h>

/*we will use the c99 standard and above, making sure that we can declare any variables we want anywhere in the function*/



char g = '2'; /* global variable, but not recommended to do excessive use of global variable*/



/* structure is a group of variables, it is a forerunner of the class (basicaly a class but public)*/
typedef struct point {
    double x;
    double y;
    double z;
} point_t; /*typedef a struct point to point_t datatype*/
/*all elements of the structure dont have to be the same type*/



typedef int pid_t; /* u can use typedef for whatever */



void allocate_memory(){

    malloc( sizeof(int) ); /*allocate a size of an int (usually 4 but it is system dependent, x32 vs x64 etc)*/

    int *x = malloc( sizeof(point_t) ); 
    int *y = x; /*do not call free on y after calling free on x. (free of y is correct free of x is correct but not both together)*/

    /*a malloc returns a void pointer, which is a pointer with no type*/

    *x = 0; /*this deferences the pointer and assigns the new heap memory on that address to be specifically 0 */

    free( x ); /*free is the garbage collector and takes the variable to free as a parameter. DO NOT CALL free on one thing twice, and do not call it on a stack or global variable*/

    /* free just lets the computer know taht we are done with the memory but that doesnt mean it completely goes away*/





    point_t * p = malloc (sizeof( point_t));
    (*p).x = 99.9;
    p->x = 99.9; //these are the same things 
    memset( p, 99.9, sizeof( point_t)); //again the same thing

    free (p);






    int stack_array[10];
    stack_array[5] = 7;
    stack_array[-1] = 7; //this is gonna crash the program but the compiler itself wont stop you doing it lol
    stack_array[12]; /* same thing with this*/


    int * heap_array = malloc( 10 * sizeof( int ));
    heap_array[3] = 42;
    

    initialize_array(heap_array, 10);


    free ( heap_array); // you can just use this pretty easily


}

void initialize_array (int * a, int capacity){
    for (int i = 0; i < capacity; i++){
        a[i] = 0; /* THIS IS NOT RECOMMENEDED PLEASE DONT DO THIS*/
    }
} /*INSTEAD DO THE FOLLOWING FUNCTION*/

void initialize_array ( int *a, int capacity){
    memset( a, 0, capacity * sizeof(int)); /*this is in string.h #include*/
    /* this is recommended btw*/

}



/* 

./hello arg1 arg2     -> in this case the argc  = 3 

char** = (char*)* which means its an array of strings, the array is of size argc (capacity = argc)

*/

int main( int argc, char ** argv){
    //argv at index0 is ./hello as a string
    //argv at index1 is arg1
    //argv at index2 is arg2

    int count = atoi( argv[2] );

    //argv has all strings so you need to parse it to get an integer

    //you can use something called atoi() (which means anything to to int, it will return 0 if it unable to parse, if it is mixed numbers letters then it will find the first number, it will return the actual thing if it went fine)

    return 0;
    //everything went fine = 0 

}





//void pointer is somehting we dont know what the type of the pointer is, all that we need to know is that it is an pointer and the type does not matter, 

// this is used in memset and malloc, which means we can use pointers without knowing what the type on the other side is

//this will be helpful in the future, when we control our own types of results







void string_stuff ( ){
    printf("Hello World!\n"); // the compiler adds the null terminator for you already


    int z = -25;
    printf("the value of z is %d.\n", z); //explicit string with a format specifier in it. (%d) is a signed integer


    point_t p2;
    p2.x = 1.5;
    p2.y = -3.3;
    p2.z = 9.1;

    printf("(%f, %f, %f)\n", p2.x, p2.y, p2.z);







    //this writes to the console
    char null_term = '\0';
    char zero = '0';


}


void add_to_point (point_t t1, point_t t2){
//the first argument usually the one that gets changed
}




void do_work(){
    int *a = malloc (sizeof(int));
    *a = 5;
    int *b = malloc (sizeof( int));
    *b = 7;

    int c = work( *a, *b);
    free(a);
    free(b);
}

/*or we could also do the following*/

void do_work_2(){
    int a = 5;
    int b = 7;

    int c = work( &a, &b);

}



int work ( int x , int y ){
    return x + y;
}






int function_name( double arg1, int arg2, char arg3){
    int i;
    for (int i = 0; i < 10; i++){
/* C style comment is recommended, because "//"  doesnt exist everywhere*/
    }
    
    struct point p1; /*"struct point" is the TYPE of the variable p1*/
    p1.x = 1.9;
    p1.y = -2.5; /*the variable is stack allocated so it contains garbage until someone declares something*/
    p1.z = 0.3;
    /* we use the dot to refer to things inside the variable*/

    return 0;
}
/*stack allocated is local to a function, for example int i in function name above. the lifetime is as long as the function runs (reaches reuturn)

heap is explcitely asked for and explicitely deleted (malloc and free)

stack memory is somewhat limited, but comapred to that, heap space is much much larger. for example if you have an array that is really really big then you will have to allocate it toe the heap

*/



int bar (int v1, int v2); /*prototype function, just letting the compiler know that there will exist this function in the future so it finds it before operating on the function foo()*/







struct point add_points( point_t p1, point_t p2){
    
    point_t result; 
    result.x = p1.x +p2.x;
    result.y = p1.y + p2.y;
    result.z = p1.z + p2.z;

    return result;
}




int foo(){
    return bar(7,11);
}




int bar (int v1, int v2){
    return v1 *v2;
}

