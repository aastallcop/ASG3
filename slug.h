
#ifndef SLUG_H_
#define SLUG_H_

/*You will need to add an argument to slug_malloc() and slug_free() to pass in FILE_POS.*/
#define malloc(s) slug_malloc((s), FILE_POS)
#define free(s) slug_free((s), FILE_POS)


/*To get the file and line number you might find the following macros helpful*/
#define FUNCTIONIZE(a,b) a(b)
#define STRINGIZE(a) #a
#define INT2STRING(i) FUNCTIONIZE(STRINGIZE,i)
#define FILE_POS __FILE__ ":" INT2STRING(__LINE__)


/*Each allocation report should include 
the size of the allocation, a timestamp for when the allocation took place, the actual address of
the allocation, and file and line number in the test program where the allocation happened.*/



struct slug {
   size_t size; /*current size*/
   time_t time; /*current timestamp*/
   char *addr; /*current address*/

   /*CHANGE LATER*/
   /*string f_name; /*name of file*/
   unsigned line_num; /*current line number*/

}slug;


void *slug_malloc(size_t size, char *WHERE);

void *slug_free(void *addr, char *WHERE);

void slug_memstats (void);

#endif
