#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include<unistd.h>
#include <sys/types.h>
#include <fcntl.h>


int main() {
  // Open the file for reading.
  FILE *file = fopen("../text.txt", "r");
  if (file == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  // Get the file's modification time.
  struct stat st;
  stat("../text.txt", &st);
  time_t last_modified = st.st_mtime;

  // Read the file's contents.
  char buffer[100];
  while (fgets(buffer, sizeof(buffer), file) != NULL) {
    printf("%s", buffer);
  }
  // Close the file.
  fclose(file);
  // Wait for the file to be modified.
  while (last_modified == st.st_mtime) {
    printf("CHECK\n");
    stat("../text.txt", &st);
    sleep(2);
  }

  // The file has been modified, so read it again.
  main();

  return 0;
}