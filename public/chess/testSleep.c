#include <stdio.h>
#include <unistd.h>

int main()
{

      // This line will be executed first
    while (1) {
        printf("Hello\n");
        sleep(5);
    }
    // after 10 seconds this next line will be executed.
  
    printf("This line will be executed after 10 second.");

    return 0;
}