#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "slug.h"


/*128 MiB = 1024^2*/
#define MAX_SIZE (128 * 1024 * 1024)


/*This function will allocate memory by calling malloc(). It returns the address of allocated 
memory. In addition, it records the address, length, current timestamp, and location of the call
in an internal data structure. The parameter WHERE is 
a string constant that records the filename and line number of the caller.*/



void *slug_malloc(size_t size, char *WHERE){


   struct slug *s;
   void *pointer = malloc(size);

   /*If size is zero, this is not an error but should be reported on 
   stderr as an unusual operation.*/
   if(size == 0){
      fprintf(stderr, "Current size is %lu\n", size);
   }

   /*If the input is excessively large (more than 128 MiB) then this
   function should report an error in stderr and terminate the program.*/
   if(size > MAX_SIZE){
      fprintf(stderr, "The file is too large! The size is %lu\n", size);
      exit(1);
   }

   /*In addition, it records the address, length, current timestamp, and location of the call
    in an internal data structure.*/


    /*s->addr; updates address*/
    /*s->size = (char*)pointer; updates length/size*/
    /*s.time =(unsigned)time(NULL); updates timestamp*/
    /*s->line_num; updates location*/



   printf("The current allocation of the %i file is %p[%lu]\n", WHERE, pointer, size);

   /*It returns the address of allocated memory.*/
   return pointer;

}

/*This function first checks that the addr is the start of a valid memory region that is currently 
allocated by looking through the internal data structures. If not, an errors is shown and the 
program terminated. If it is valid then free() should be called and the internal data structures 
updated to indicate that the address is no longer actively allocated.
*/
void *slug_free(void *addr, char *WHERE){
   void *pointer = free(addr);

   if(addr == NULL){
      fprintf(stderr, "Not a valid memory region! Address at %d\n", *(int*)addr);
      exit(1);
   }

   printf("The address to be freed is %d from the %p file", *(int*)addr, WHERE);

   return pointer;
}


/*This function traverses the internal data structures kept by slug_malloc() and slug_free() 
and prints out information about all current allocations. Each allocation report should include 
the size of the allocation, a timestamp for when the allocation took place, the actual address of
the allocation, and file and line number in the test program where the allocation happened. 
In addition, a summary of all allocations should be reported that includes the total number of 
allocations done, the number of current active allocations, the total amount of memory 
currently allocated, and the mean and standard deviation of sizes that have been allocated.*/


/*
void slug_memstats (void){


    /*Initiziling
    /*alloc_ts = slug->time; timestamp for when allocation happened
    int alloc_size = slug->size; /*size of allocation
    alloc_addr = slug->addr;


   /*Print out each allocation
   printf("The current timestamp with a slug size of %lu at address %d",
          alloc_size, alloc_addr);



}*/



int main(int argc, const char* argv[]){
   int * test;
   /*struct slug *s;*/
  /*s.time =(unsigned)time(NULL); updates timestamp*/


   printf("TEST IT! RAN MAIN!\n");
   /*printf(s->time);*/


   /*Tests*/
   /*test = slug_malloc(10 * sizeof(int), "hi");
   printf("Test array is:%d\n", test);*/

   /*slug_free(test, "hi");*/



   return 0;
}
