void * common_memcpy(void *pDestination, const void *pSource, size_t num);
void * common_memset(void *pBuffer, int value, size_t num);
void* common_memmove(void *s1, const void *s2, size_t n);
char * common_strchr(const char *pString, int character);
size_t common_strlen(const char *pString);
char * common_strrchr(const char *pString, int character);
char * common_strcpy(char *pDestination, const char *pSource);
int common_strncmp(const char *pString1, const char *pString2, size_t count);
char * common_strncpy(char *pDestination, const char *pSource, size_t count);
int common_strcmp(const char *s1, const char *s2);
char *strtok(char *s, const char *delim);
char *strtok_r(char *s, const char *delim, char **last);
