#ifndef UTILS_H
#define UTILS_H

char * my_strsep(char **stringp, const char *delim);
void tolower_string(char *str);
void trim(char *str, const char *trim_chars);
int counting_lines(FILE * f);

#endif