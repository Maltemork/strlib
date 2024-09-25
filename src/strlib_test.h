void run_tests();
void test(const char *test_name, int (*test_func)());
int assert_eq(int expected, int actual);
int assert_str_eq(const char *expected, const char *actual);
// Helper functions
int test_str_length();
int test_str_copy();
int test_str_append();
int test_str_compare();
int test_str_find();
int test_char_toLowerCase();
int test_char_toUpperCase();

// String.prototype functions.
int test_str_charAt();
int test_str_at();
int test_str_concat();
int test_str_endsWith();
int test_str_startsWith();
int test_str_includes();
int test_str_indexOf();
int test_str_lastIndexOf();
int test_str_localeCompare();
int test_str_padEnd();
int test_str_padStart();
int test_str_repeat();
int test_str_slice();
int test_str_substring();
int test_str_iterator();
int test_str_toLocaleUpperCase();
int test_str_toLocaleLowerCase();
int test_str_toLowerCase();
int test_str_toUpperCase();
int test_str_trim();
int test_str_trimEnd();
int test_str_trimStart();

// toString functions.
int test_str_toString_int();
int test_str_toString_float();
int test_str_toString_double();
int test_toString_long();
int test_str_toString_char();
int test_str_toString_pointer();

// valueOf functions.
int test_str_valueOf_int();
int test_str_valueOf_float();
int test_str_valueOf_double();
int test_str_valueOf_long();
int test_str_valueOf_char();
int test_str_valueOf_pointer();