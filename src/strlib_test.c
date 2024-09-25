#include <stdio.h>
#include <string.h>
#include "strlib.h"
#include "strlib_test.h"

int main() {
    run_tests();
    return 0;
}

void run_tests() {
    printf("Running tests...\n");

    test("length", test_str_length);
    test("copy", test_str_copy);
    test("append", test_str_append);
    test("compare", test_str_compare);
    test("find", test_str_find);
    test("char_toLowerCase", test_char_toLowerCase);
    test("char_toLowerCase", test_char_toLowerCase);

    test("charAt", test_str_charAt);
    test("at", test_str_at);
    test("concat", test_str_concat);
    test("endsWith", test_str_endsWith);
    test("startsWith", test_str_startsWith);
    test("includes", test_str_includes);
    test("indexOf", test_str_indexOf);
    test("lastIndexOf", test_str_lastIndexOf);
    test("localeCompare", test_str_localeCompare);
    test("padEnd", test_str_padEnd);
    test("padStart", test_str_padStart);
    test("repeat", test_str_repeat);
    test("slice", test_str_slice);
    test("substring", test_str_substring);
    test("iterator", test_str_iterator);
    test("toLocaleLowerCase", test_str_toLocaleLowerCase);
    test("toLocaleUpperCase", test_str_toLocaleUpperCase);
    test("toLowerCase", test_str_toLowerCase);
    test("toUpperCase", test_str_toUpperCase);
    test("trim", test_str_trim);
    test("trimEnd", test_str_trimEnd);
    test("trimStart", test_str_trimStart);

    test("toString_int", test_str_toString_int);
    test("toString_float", test_str_toString_float);
    test("toString_double", test_str_toString_double);
    test("toString_long", test_toString_long);
    test("toString_char", test_str_toString_char);
    test("toString_pointer", test_str_toString_pointer);

    test("valueOf_int", test_str_valueOf_int);
    test("valueOf_float", test_str_valueOf_float);
    test("value_of_double", test_str_valueOf_double);
    test("valueOf_double", test_str_valueOf_long);
    test("valueOf_char", test_str_valueOf_char);
    test("valueOf_pointer", test_str_valueOf_pointer);
}

// Tiny testing framework
void test(const char *test_name, int (*test_func)()) {
    printf("-------------------\n");
    printf("%s test\n", test_name);
    if (test_func()) {
        printf("%s: OK\n", test_name);
    } else {
        printf("%s: FAIL\n", test_name);
    }
    printf("\n");
}

int assert_eq(int expected, int actual) {
    if(expected != actual){
        printf("Expected: %d\n", expected);
        printf("Actual: %d\n", actual);
    }
    return expected == actual;
}

int assert_str_eq(const char *expected, const char *actual) {
    if(strcmp(expected, actual) != 0){
        printf("Expected: %s\n", expected);
        printf("Actual: %s\n", actual);
    }
    return strcmp(expected, actual) == 0;
}

// Tests
// Helper functions
int test_str_length() {
    return assert_eq(13, str_length("Hello, World!"));
}

int test_str_copy() {
    return assert_str_eq("Hello, World!", str_copy("Hello, World!"));
}

int test_str_append() {
    return assert_str_eq("Hello, World!", str_append("Hello, ", "World!"));
}

int test_str_compare() {
    return assert_eq(0, str_compare("Hello, World!", "Hello, World!"));
}

int test_str_find() {
    return assert_str_eq("World!", str_find("Hello, World!", "World!"));
}

int test_char_toLowerCase() {
    return assert_eq('a', str_char_toLowerCase('A'));
}

int test_char_toUpperCase() {
    return assert_eq('A', str_char_toUpperCase('a'));
}

// String.prototype functions.
int test_str_charAt() {
    return assert_str_eq("H", str_charAt(0, "Hello, World!"));
}

int test_str_at() {
    return assert_str_eq("H", str_at(0, "Hello, World!"));
}

int test_str_concat() {
    return assert_str_eq("Hello, World!", str_concat("Hello, ", "World!"));
}

int test_str_endsWith() {
    return assert_eq(1, str_endsWith("Hello, World!", "World!"));
}

int test_str_endsWith_position() {
    return assert_eq(0, str_endsWith_position("Hello, World!", "Hello", 5));
}

int test_str_startsWith() {
    return assert_eq(1, str_startsWith("Hello, World!", "Hello"));
}

int test_str_includes() {
    return assert_eq(1, str_includes("Hello, World!", "World!"));
}

int test_str_indexOf() {
    return assert_eq(7, str_indexOf("Hello, World!", "World!"));
}

int test_str_indexOf_position() {
    return assert_eq(-1, str_indexOf_position("Hello, World!", "Hello", 7));
}

int test_str_lastIndexOf() {
    return assert_eq(7, str_lastIndexOf("Hello, World!", "World!"));
}

int test_str_localeCompare() {
    return assert_eq(-1, str_localeCompare("Hello", "World"));
}

int test_str_padEnd() {
    return assert_str_eq("Hello, World!  ", str_padEnd("Hello, World!", 2));
}

int test_str_padStart() {
    return assert_str_eq("  Hello, World!", str_padStart("Hello, World!", 2));
}

int test_str_repeat() {
    return assert_str_eq("Hello, World!Hello, World!", str_repeat("Hello, World!", 2));
}

int test_str_slice() {
    return assert_str_eq("World!", str_slice("Hello, World!", 7, 13));
}

int test_str_substring() {
    return assert_str_eq("World!", str_substring("Hello, World!", 7, 13));
}

int test_str_iterator() {
    return assert_str_eq("Hello, World!", str_iterator("Hello, World!"));
}

int test_str_toLocaleLowerCase() {
    return assert_str_eq("hello, world!", str_toLocaleLowerCase("Hello, World!"));
}

int test_str_toLocaleUpperCase() {
    return assert_str_eq("HELLO, WORLD!", str_toLocaleUpperCase("Hello, World!"));
}

int test_str_toLowerCase() {
    return assert_str_eq("hello, world!", str_toLowerCase("Hello, World!"));
}

int test_str_toUpperCase() {
    return assert_str_eq("HELLO, WORLD!", str_toUpperCase("Hello, World!"));
}

int test_str_trim() {
    return assert_str_eq("Hello, World!", str_trim("  Hello, World!  "));
}

int test_str_trimEnd() {
    return assert_str_eq("  Hello, World!", str_trimEnd("  Hello, World!  "));
}

int test_str_trimStart() {
    return assert_str_eq("Hello, World!  ", str_trimStart("  Hello, World!  "));
}

// toString functions.
int test_str_toString_int() {
    return assert_str_eq("123", str_toString_int(123));
}

int test_str_toString_float() {
    return assert_str_eq("123.456001", str_toString_float(123.456));
}

int test_str_toString_double() {
    return assert_str_eq("123.456789", str_toString_double(123.456789));
}

int test_toString_long() {
    return assert_str_eq("1234567890", str_toString_long(1234567890));
}

int test_str_toString_char() {
    return assert_str_eq("A", str_toString_char('A'));
}

int test_str_toString_pointer() {
    return assert_str_eq("0x12345678", str_toString_pointer((void *)0x12345678));
}

// valueOf functions.
int test_str_valueOf_int() {
    return assert_str_eq("123", str_valueOf_int(123));
}

int test_str_valueOf_float() {
    return assert_str_eq("123.456001", str_valueOf_float(123.456));
}

int test_str_valueOf_double() {
    return assert_str_eq("123.456789", str_valueOf_double(123.456789));
}

int test_str_valueOf_long() {
    return assert_str_eq("1234567890", str_valueOf_long(1234567890));
}

int test_str_valueOf_char() {
    return assert_str_eq("A", str_valueOf_char('A'));
}

int test_str_valueOf_pointer() {
    return assert_str_eq("0x12345678", str_valueOf_pointer((void *)0x12345678));
}
