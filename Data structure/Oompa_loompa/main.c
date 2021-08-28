#include "chocolate.c"
#include "time.h"

int main()
{
    CF *process;
    process=NULL;

    printf("\nThe preparation has begin at...\n");
    time_t start;
    start = time(NULL);
    printf(ctime(&start));
    printf("\n\n");

    /// Call the functions to gather, melt and prepare
    process = gather_requirements(process);
    melt_and_prepare(process);
    
    printf("\nSecret Recipe Chocolate is now Ready\n");
    printf("\n\n");
    printf("\nThe preparation ended at...\n");
    time_t end;
    end = time(NULL);
    printf(ctime(&end));
    printf("\n\n");

    return 0;
}