#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

size_t ft_strlen(const char *s);
char *ft_strcpy(char *dst, const char *src);
int ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
// ssize_t ft_read(int fildes, void *buf, size_t nbyte);
// char *ft_strdup(const char *s1);

void red() { printf("\033[1;31m"); }

void green() { printf("\033[0;32m"); }

void reset() { printf("\033[0m"); }

void fail(int n) {
  reset();
  printf("test %d: ", n);
  red();
  printf("FAIL\n");
  reset();
}

void pass(int n) {
  reset();

  printf("test %d: ", n);
  green();
  printf("PASS\n");
  reset();
}

// void test_strdup() {
//   char str[6] = "salut";

//   if (strncmp(ft_strdup(str), strdup(str), 10) == 0)
//     pass(1);
//   else
//     fail(1);

//   str[2] = 0;

//   if (strncmp(ft_strdup(str + 1), strdup(str + 1), 10) == 0)
//     pass(2);
//   else
//     fail(2);
//   if (strncmp(ft_strdup(str + 2), strdup(str + 2), 10) == 0)
//     pass(3);
//   else
//     fail(3);
// }

void test_strcpy() {
  char dst1[17] = {1};
  char dst2[17] = {1};
  char src1[17] = "salut c'est cool";
  char src2[17] = "salut c'est cool";

  if (strcmp(ft_strcpy(dst1, src1), strcpy(dst2, src2)) == 0) // ret value
    pass(1);
  else
    fail(1);
  if (strcmp(dst1, dst2) == 0) // compare the copy
    pass(2);
  else
    fail(2);
}

void test_strcmp() {
  char str1[21] = "salut";
  char str2[21] = "salu";
  char str3[21] = "";

  if (ft_strcmp(str1, str1) == strcmp(str1, str1)) // same string
    pass(1);
  else
    fail(1);
  if (ft_strcmp(str1, str2) == strcmp(str1, str2)) // 1 char different
    pass(2);
  else
    fail(2);
  if (ft_strcmp(str2, str1) == strcmp(str2, str1)) // inverse
    pass(3);
  else
    fail(3);
  if (ft_strcmp(str1, str3) == strcmp(str1, str3)) // s2 empty
    pass(4);
  else
    fail(4);
  if (ft_strcmp(str3, str1) == strcmp(str3, str1)) // s1 empty
    pass(5);
  else
    fail(5);
}

void test_write() {
  if (ft_write(0, "salut\n", 7) == write(0, "salut\n", 7))
    pass(1);
  else
    fail(1);
  if (ft_write(1, "\nsalut", 1) == write(1, "\nsalut", 1))
    pass(2);
  else
    fail(2);
  if (ft_write(2, "salu\nt", 5) == write(2, "salu\nt", 5))
    pass(3);
  else
    fail(3);
  if (ft_write(1, "salut", 0) == write(1, "salut", 0))
    pass(4);
  else
    fail(4);
  if (ft_write(-1, "salut", 5) == write(-1, "salut", 5))
    pass(5);
  else
    fail(5);
  if (ft_write(4000, "salut", 5) == write(4000, "salut", 5))
    pass(6);
  else
    fail(6);
}

// void test_read() {
//   char str[21] = {0};

//   if (ft_read(-1, str, 21) == read(-1, str, 21))
//     pass(1);
//   else
//     fail(1);
//   printf("type something and press enter :\n");
//   ft_read(0, str, 21);
//   printf("\nyour word is : %s\n", str);
// }

int main() {
  printf("\n\tSTRLEN : \n\n");
  printf("ft_strlen(\"salut\") : %zu\n", ft_strlen("salut"));
  printf("ft_strlen(\"\") : %zu\n", ft_strlen(""));
  printf("\n\tSTRCPY : \n\n");
  test_strcpy();
  printf("\n\tSTRDUP : \n\n");
  // test_strdup();
  printf("\n\tSTRCMP : \n\n");
  test_strcmp();
  printf("\n\tWRITE : \n\n");
  test_write();
  printf("\n\tREAD : \n\n");
  // test_read();
  return (0);
}
