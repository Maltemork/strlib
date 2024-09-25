// Helper functions
int str_length(const char *src);
char *str_copy(const char *src);
char *str_append(const char *str1, const char *str2);
int str_compare(const char *str1, const char *str2);
char *str_find(const char *haystack, const char *needle);
char str_char_toLowerCase(char c);
char str_char_toUpperCase(char c);

// String.prototype functions.
char *str_charAt(int index, const char *src);
char *str_at(int index, const char *src);
char *str_concat(const char *src1, const char *src2);
int str_endsWith_position(const char *src, const char *end, int endPosition);
int str_endsWith(const char *src, const char *end);
int str_startsWith(const char *src, const char *start);
int str_includes(const char *src, const char *search);
int str_indexOf_position(const char *src, const char *search, int fromIndex);
int str_indexOf(const char *src, const char *search);
int str_lastIndexOf(const char *src, const char *search);
int str_localeCompare(const char *src1, const char *src2);
char *str_padEnd(const char *src, int targetLength);
char *str_padStart(const char *src, int targetLength);
char *str_repeat(const char *src, int count);
char *str_slice(const char *src, int start, int end);
char *str_substring(const char *src, int start, int end);
char *str_iterator(const char *src);
char *str_toLocaleLowerCase(const char *src);
char *str_toLocaleUpperCase(const char *src);
char *str_toLowerCase(const char *src);
char *str_toUpperCase(const char *src);
char *str_trim(const char *src);
char *str_trimEnd(const char *src);
char *str_trimStart(const char *src);

// toString functions.
char *str_toString_int(int value);
char *str_toString_float(float value);
char *str_toString_double(double value);
char *str_toString_long(long value);
char *str_toString_char(char value);
char *str_toString_pointer(void *value);

// valueOf functions.
char *str_valueOf_int(int value);
char *str_valueOf_float(float value);
char *str_valueOf_double(double value);
char *str_valueOf_long(long value);
char *str_valueOf_char(char value);
char *str_valueOf_pointer(void *value);