#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>

void press_any_key_to_continue()
{
  printf("Press any key to continue, or press Enter to exit...\n\n");

  int key = getch();

  if (key == 13) // 13 is the ASCII code for Enter
  {
    printf("\nExiting the program.\n");
    exit(0);
  }
}

void generate_hex_key(char *key, int key_length)
{
  const char charset[] = "0123456789ABCDEF";
  const int charset_length = sizeof(charset) - 1;

  for (int i = 0; i < key_length; i++)
  {
    key[i] = charset[rand() % charset_length];
  }
  key[key_length] = '\0'; // Null-terminate the string
}

void generate_ras_key(char *key, int key_length)
{
  const char charset[] = "$ABCDEFGHIJKLMNOPQRSTUVWXYZ-_0123456789";
  const int charset_length = sizeof(charset) - 1;

  for (int i = 0; i < key_length; i++)
  {
    key[i] = charset[rand() % charset_length];
  }
  key[key_length] = '\0'; // Null-terminate the string
}

int main()
{
  // Set the seed only once outside the loop
  unsigned int seed = (unsigned int)time(NULL);
  srand(seed);

  // Increased size by 1 to accommodate the null terminator
  char arc4Key[11];
  char aes256Key[65];
  char plsTskKey[25];
  char rasKey[25];

  while (1)
  {
    generate_hex_key(arc4Key, 10);
    generate_hex_key(aes256Key, 64);
    generate_hex_key(plsTskKey, 24);
    generate_ras_key(rasKey, 24);

    printf("ARC4 Key: %s\n", arc4Key);
    printf("AES-256 Key: %s\n", aes256Key);
    printf("TSK-PLS Key: %s\n", plsTskKey);
    printf("RAS Key: %s\n", rasKey);

    press_any_key_to_continue();
  }

  return 0;
}
