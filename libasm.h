
#pragma once

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

size_t ft_strlen(const char *s);
char *ft_strcpy(char *dst, const char *src);
char *ft_strdup(const char *s);
int ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buff, size_t count);
ssize_t ft_read(int fd, void *buff, size_t count);
