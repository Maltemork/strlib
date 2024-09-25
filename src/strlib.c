#include <stdio.h>
#include <stdlib.h>

//  _____________________________________________________________________
//  _____________________________________________________________________
//    ____  _        _                _     _ _                           
//   / ___|| |_ _ __(_)_ __   __ _   | |   (_) |__  _ __ __ _ _ __ _   _ 
//   \___ \| __| '__| | '_ \ / _` |  | |   | | '_ \| '__/ _` | '__| | | |
//    ___) | |_| |  | | | | | (_| |  | |___| | |_) | | | (_| | |  | |_| | 
//   |____/ \__|_|  |_|_| |_|\__, |  |_____|_|_.__/|_|  \__,_|_|   \__, |
//                           |___/                                 |___/ 
//  _____________________________________________________________________
//  _____________________________________________________________________

// ------------------------------------
// --------- Helper Functions ---------
// ------------------------------------
// Calculate the length of a string
int str_length(const char *src) {
    int length = 0;
    while (src[length] != '\0') {
        length++;
    }
    return length;
}

// Converts a character to lowercase.
char str_char_toLowerCase(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

// Converts a character to upper case.
char str_char_toUpperCase(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    }
    return c;
}

// Copy a string
char *str_copy(const char *src) {
    int len = str_length(src);
    char *dest = (char *)malloc((len + 1) * sizeof(char)); // Allocate memory for the destination
    for (int i = 0; i < len; i++) {
        dest[i] = src[i];
    }
    dest[len] = '\0';
    return dest;
}

// Append one string to another
char *str_append(const char *str1, const char *str2) {
    int len = str_length(str1);
    int append_len = str_length(str2);
    char *dest = (char *)malloc((len + append_len + 1) * sizeof(char)); // Allocate memory for the destination
    for (int i = 0; i < len; i++) {
        dest[i] = str1[i];
    }
    for (int i = 0; i < append_len; i++) {
        dest[len + i] = str2[i];
    }
    dest[len + append_len] = '\0';
    return dest;
}

// Compare two strings case-insensitively
int str_compare(const char *str1, const char *str2) {
    while (*str1 && *str2) {
        if (*str1 != *str2) {
            return -1; // Return -1 if characters are different
        }
        str1++;
        str2++;
    }
    return *str1 == *str2 ? 0 : -1; // Return 0 if strings are the same, -1 otherwise
}

// Find the first occurrence of a substring
const char *str_find(const char *haystack, const char *needle) {
    if (!*needle) return haystack;
    for (; *haystack; haystack++) {
        if ((*haystack == *needle) && !str_compare(haystack, needle)) {
            return haystack;
        }
    }
    return NULL;
}


// ------------------------------------
// --------- String Functions ---------
// ------------------------------------

// String.prototype.charAt() | Returns the character at the specified index.
char *str_charAt(int index, const char *src) {
    if (index < 0 || index >= str_length(src)) {
        char *empty = (char *)malloc(1);
        empty[0] = '\0';
        return empty; // Return an empty string if index is out of bounds
    }
    char *result = (char *)malloc(2 * sizeof(char)); // Allocate memory for the result
    result[0] = src[index];
    result[1] = '\0';
    return result;
}

// String.prototype.at() | Returns the character at the specified index, negative indices are allowed.
char *str_at(int index, const char *src) {
    int len = str_length(src);
    if (index < 0) {
        index = len + index;
    }
    if (index < 0 || index >= len) {
        char *empty = (char *)malloc(1);
        empty[0] = '\0';
        return empty; // Return an empty string if index is out of bounds
    }
    char *result = (char *)malloc(2 * sizeof(char)); // Allocate memory for the result
    result[0] = src[index];
    result[1] = '\0';
    return result;
}

// String.prototype.concat() | Concatenates two strings.
char *str_concat(const char *str1, const char *str2) {
    return str_append(str1, str2);
}

// String.prototype.endsWith() | Checks if a string ends with a specified value up to an optional end position.
int str_endsWith_position(const char *src, const char *search, int endPosition) {
    int len_src = str_length(src);
    int len_search = str_length(search);
    if (endPosition > len_src) {
        endPosition = len_src;
    }
    if (len_search > endPosition) {
        return 0;
    }
    return str_compare(src + endPosition - len_search, search) == 0;
}

int str_endsWith(const char *src, const char *search) {
    int len_src = str_length(src);
    int len_search = str_length(search);
    
    if (len_search > len_src) {
        return 0;
    }
    
    // Compare the end of src with search
    return str_compare(src + len_src - len_search, search) == 0;
}

// String.prototype.startsWith() | Checks if a string starts with another string.
int str_startsWith(const char *src, const char *search)
{
    const char *psrc = src;
    const char *pstart = search;
    while(*pstart != '\0'){
        if(*psrc != *pstart){
            return 0;
        }
        psrc++;
        pstart++;
    }
    return 1;
}

// String.prototype.includes() | Checks if a string contains a specified value.
int str_includes(const char *src, const char *search) {
    return str_find(src, search) != NULL;
}

// String.prototype.indexOf() | Returns the index of the first occurrence of a specified value in a string.
int str_indexOf_position(const char *src, const char *search, int fromIndex) {
    const char *pos = str_find(src + fromIndex, search);
    if (pos) {
        return pos - src;
    }
    return -1;
}

int str_indexOf(const char *src, const char *search) {
    const char *pos = str_find(src, search);
    if (pos) {
        return pos - src;
    }
    return -1;
}

// String.prototype.lastIndexOf() | Returns the index of the last occurrence of a specified value in a string.
int str_lastIndexOf(const char *src, const char *search) {
    const char *last_pos = NULL;
    const char *pos = src;
    while ((pos = str_find(pos, search)) != NULL) {
        last_pos = pos;
        pos++;
    }
    if (last_pos) {
        return last_pos - src;
    }
    return -1;
}

// String.prototype.localeCompare() | Compares two strings in the current locale.
int str_localeCompare(const char *src1, const char *src2) {
    return str_compare(src1, src2);
}

// String.prototype.padEnd() | Pads the current string with a given string (repeated, if needed) so that the resulting string reaches a given length.
char *str_padEnd(const char *str, int padding_amount) {
    int str_len = str_length(str); // Get the length of the input string

    // Calculate the total length after padding
    int total_length = str_len + padding_amount;

    // Allocate memory for the padded string (+1 for the null terminator)
    char *padded_str = (char *)malloc(total_length + 1);
    if (!padded_str) {
        return NULL; // Return NULL if memory allocation fails
    }

    // Copy the input string to the padded string
    for (int i = 0; i < str_len; i++) {
        padded_str[i] = str[i];
    }

    // Pad with spaces if necessary
    for (int i = str_len; i < total_length; i++) {
        padded_str[i] = ' ';
    }

    // Null-terminate the padded string
    padded_str[total_length] = '\0';

    return padded_str;
}

// String.prototype.padStart() | Pads the current string with a given string (repeated, if needed) so that the resulting string reaches a given length.
char *str_padStart(const char *str, int padding_amount) {
    int str_len = str_length(str); // Get the length of the input string

    // Calculate the total length after padding
    int total_length = str_len + padding_amount;

    // Allocate memory for the padded string (+1 for the null terminator)
    char *padded_str = (char *)malloc(total_length + 1);
    if (!padded_str) {
        return NULL; // Return NULL if memory allocation fails
    }

    // Pad with spaces if necessary
    for (int i = 0; i < padding_amount; i++) {
        padded_str[i] = ' ';
    }

    // Copy the input string to the padded string
    for (int i = 0; i < str_len; i++) {
        padded_str[i + padding_amount] = str[i];
    }

    // Null-terminate the padded string
    padded_str[total_length] = '\0';

    return padded_str;
}

// String.prototype.repeat() | Returns a new string with a specified number of copies of an existing string.
char *str_repeat(const char *src, int count) {

    int len = str_length(src);
    int new_len = len * count;

    char *result = (char *)malloc((new_len + 1) * sizeof(char)); // Allocate memory for the result

    for (int i = 0; i < new_len; i++) {
        result[i] = src[i % len];
    }
    result[new_len] = '\0';
    return result;
}

// String.prototype.slice() | Extracts a section of a string and returns a new string.
char *str_slice(const char *src, int start, int end) {
    int len = str_length(src);
    if (start < 0) start = len + start;
    if (end < 0) end = len + end;
    if (start > end) {
        char *empty = (char *)malloc(1);
        empty[0] = '\0';
        return empty; // Return an empty string if start is greater than end
    }
    int slice_len = end - start;
    char *result = (char *)malloc((slice_len + 1) * sizeof(char)); // Allocate memory for the result
    for (int i = 0; i < slice_len; i++) {
        result[i] = src[start + i];
    }
    result[slice_len] = '\0';
    return result;
}

// String.prototype.substring() | Extracts the characters from a string, between two specified indices.
char *str_substring(const char *src, int start, int end) {
    return str_slice(src, start, end);
}

// String.prototype[Symbol.iterator]() | Returns a new Iterator object that contains the values for each index in the string.
char *str_iterator(const char *src) {
    return str_copy(src);
}

// String.prototype.toLocaleLowerCase() | Converts a string to lowercase letters, according to the host's locale.
char *str_toLocaleLowerCase(const char *src) {
    int len = str_length(src);
    char *result = (char *)malloc((len + 1) * sizeof(char)); // Allocate memory for the result
    for (int i = 0; i < len; i++) {
        result[i] = str_char_toLowerCase(src[i]);
    }
    result[len] = '\0';
    return result;
}

// String.prototype.toLocaleUpperCase() | Converts a string to uppercase letters, according to the host's locale.
char *str_toLocaleUpperCase(const char *src) {
    int len = str_length(src);
    char *result = (char *)malloc((len + 1) * sizeof(char)); // Allocate memory for the result
    for (int i = 0; i < len; i++) {
        result[i] = str_char_toUpperCase(src[i]);
    }
    result[len] = '\0';
    return result;
}

// String.prototype.toLowerCase() | Converts a string to lowercase letters.
char *str_toLowerCase(char *src) {
    return str_toLocaleLowerCase(src);
}

// String.prototype.toUpperCase() | Converts a string to uppercase letters.
char *str_toUpperCase(char *src) {
    return str_toLocaleUpperCase(src);
}

// String.prototype.trim() | Removes whitespace from both ends of a string.
char *str_trim(const char *src) {
    int len = str_length(src);
    int start = 0;
    int end = len - 1;
    while (start < len && (src[start] == ' ' || src[start] == '\t' || src[start] == '\n' || src[start] == '\r')) {
        start++;
    }
    while (end > start && (src[end] == ' ' || src[end] == '\t' || src[end] == '\n' || src[end] == '\r')) {
        end--;
    }
    return str_slice(src, start, end + 1);
}

// String.prototype.trimStart() | Removes whitespace from the beginning of a string.
char *str_trimEnd(const char *src) {
    int len = str_length(src);
    int end = len - 1;
    while (end >= 0 && (src[end] == ' ' || src[end] == '\t' || src[end] == '\n' || src[end] == '\r')) {
        end--;
    }
    return str_slice(src, 0, end + 1);
}

// String.prototype.trimEnd() | Removes whitespace from the end of a string.
char *str_trimStart(const char *src) {
    int len = str_length(src);
    int start = 0;
    while (start < len && (src[start] == ' ' || src[start] == '\t' || src[start] == '\n' || src[start] == '\r')) {
        start++;
    }
    return str_slice(src, start, len);
}


// String.prototype.toString() | These functions convert values to strings.
// ------------------------------------
// Convert an integer to a string
char *str_toString_int(int value) {
    char *result = (char *)malloc(12 * sizeof(char)); // 12 is enough for a 32-bit integer
    int i = 0;
    int is_negative = 0;

    if (value < 0) {
        is_negative = 1;
        value = -value;
    }

    do {
        result[i++] = (value % 10) + '0';
        value /= 10;
    } while (value > 0);

    if (is_negative) {
        result[i++] = '-';
    }

    result[i] = '\0';

    for (int j = 0; j < i / 2; j++) {
        char temp = result[j];
        result[j] = result[i - j - 1];
        result[i - j - 1] = temp;
    }

    return result;
}

// Convert a float to a string
char *str_toString_float(float value) {
    char *result = (char *)malloc(32 * sizeof(char)); // 32 is enough for a 32-bit float
    sprintf(result, "%f", value);
    return result;
}

// Convert a double to a string
char *str_toString_double(double value) {
    char *result = (char *)malloc(32 * sizeof(char)); // 32 is enough for a 64-bit double
    sprintf(result, "%f", value);
    return result;
}

// Convert a long to a string
char *str_toString_long(long value) {
    char *result = (char *)malloc(24 * sizeof(char)); // 24 is enough for a 64-bit long
    sprintf(result, "%ld", value);
    return result;
}

// Convert a char to a string
char *str_toString_char(char value) {
    char *result = (char *)malloc(2 * sizeof(char)); // Allocate memory for the result
    result[0] = value;
    result[1] = '\0';
    return result;
}

// Converts a pointer to a string representation without leading zeros
char *str_toString_pointer(void *value) {
    char *result = (char *)malloc(19 * sizeof(char)); // 19 is enough for a 64-bit pointer with "0x" prefix
    if (!result) {
        return NULL; // Return NULL if memory allocation fails
    }

    // Use sprintf to format the pointer
    sprintf(result, "%p", value);

    // Find the position of the first non-zero digit after "0x"
    char *p = result + 2; // Skip the "0x" prefix
    while (*p == '0') {
        p++;
    }

    // If all digits were zero, we need to keep one zero
    if (*p == '\0') {
        p--;
    }

    // Shift the string to remove leading zeros
    char *q = result + 2; // Position after "0x"
    while (*p) {
        *q++ = *p++;
    }
    *q = '\0';

    // Add "0x" prefix
    result[0] = '0';
    result[1] = 'x';

    return result;
}
// ------------------------------------

// String.prototype.valueOf() | These functions convert values to strings.
char *str_valueOf_int(int value) {
    return str_toString_int(value);
}

char *str_valueOf_float(float value) {
    return str_toString_float(value);
}

char *str_valueOf_double(double value) {
    return str_toString_double(value);
}

char *str_valueOf_long(long value) {
    return str_toString_long(value);
}

char *str_valueOf_char(char value) {
    return str_toString_char(value);
}

char *str_valueOf_pointer(void *value) {
    return str_toString_pointer(value);
}