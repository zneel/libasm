#include <stddef.h>
#include <unistd.h>

extern size_t ft_strlen(const char *s);
extern char *ft_strcpy(char *restrict dst, const char *restrict src);

int main() {
  char *str1 = "Hello, World!\n";
  char *str2 = "This is the second string.\n";
  char *str3 = "Another string to test our ft_strlen...\n";
  char *str4 = "And one more!\n";

  write(1, str1, ft_strlen(str1));
  write(1, str2, ft_strlen(str2));
  write(1, str3, ft_strlen(str3));
  write(1, str4, ft_strlen(str4));

  char dst[100];
  ft_strcpy(dst, str1);
  write(1, dst, ft_strlen(dst));
  ft_strcpy(dst, str2);
  write(1, dst, ft_strlen(dst));
  ft_strcpy(dst, str3);
  write(1, dst, ft_strlen(dst));
  ft_strcpy(dst, str4);
  write(1, dst, ft_strlen(dst));

  return 0;
}