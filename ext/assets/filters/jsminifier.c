/* jsmin.c
   2013-03-29

Copyright (c) 2002 Douglas Crockford  (www.crockford.com)

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

The Software shall be used for Good, not Evil.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"
#include "ext/standard/php_smart_str.h"

#define JSMIN_ACTION_OUTPUT_NEXT 1
#define JSMIN_ACTION_NEXT_DELETE 2
#define JSMIN_ACTION_NEXT 3

typedef struct _jsmin_parser {
    char theA;
    char theB;
    char theC;
    char theX;
    char theY;
    zval *script;
    int script_pointer;
    smart_str    *minified;
} jsmin_parser;

static void jsmin_error(char* s) {
    fputs("JSMIN Error: ", stderr);
    fputs(s, stderr);
    fputc('\n', stderr);
    exit(1);
}

/* isAlphanum -- return true if the character is a letter, digit, underscore,
        dollar sign, or non-ASCII character.
*/

static int jsmin_isAlphanum(int c) {
    return ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') ||
        (c >= 'A' && c <= 'Z') || c == '_' || c == '$' || c == '\\' || c > 126);
}


/* get -- return the next character from stdin. Watch out for lookahead. If
        the character is a control character, translate it to a space or
        linefeed.
*/

static char jsmin_peek(jsmin_parser *parser){
    char ch;
    if (parser->script_pointer < Z_STRLEN_P(parser->script)) {
        ch = Z_STRVAL_P(parser->script)[parser->script_pointer];
        return ch;
    }
    return EOF;
}

static char jsmin_get(jsmin_parser *parser) {

    char c;

    if (parser->script_pointer < Z_STRLEN_P(parser->script)) {
        c = Z_STRVAL_P(parser->script)[parser->script_pointer];
        parser->script_pointer++;
    } else {
        c = EOF;
    }

    parser->theC = c;

    if (c >= ' ' || c == '\n' || c == EOF) {
        return c;
    }
    if (c == '\r') {
        return '\n';
    }
    return ' ';
}


/* next -- get the next character, excluding comments. peek() is used to see
        if a '/' is followed by a '/' or '*'.
*/

static int jsmin_next(jsmin_parser *parser) {
    char c = jsmin_get(parser);
    if  (c == '/') {
        switch (jsmin_peek(parser)) {
            case '/':
                for (;;) {
                    c = jsmin_get(parser);
                    if (c <= '\n') {
                        break;
                    }
                }
                break;
        case '*':
            jsmin_get(parser);
            while (c != ' ') {
                switch (jsmin_get(parser)) {
                    case '*':
                        if (jsmin_peek(parser) == '/') {
                            jsmin_get(parser);
                            c = ' ';
                        }
                        break;
                    case EOF:
                        jsmin_error("Unterminated comment.");
                }
            }
            break;
        }
    }
    parser->theY = parser->theX;
    parser->theX = c;
    return c;
}

/* action -- do something! What you do is determined by the argument:
        1   Output A. Copy B to A. Get the next B.
        2   Copy B to A. Get the next B. (Delete A).
        3   Get the next B. (Delete B).
   action treats a string as a single character. Wow!
   action recognizes a regular expression if it is preceded by ( or , or =.
*/

static void jsmin_action(jsmin_parser *parser, char d) {
    switch (d) {
        case JSMIN_ACTION_OUTPUT_NEXT:
            smart_str_appendc(parser->minified, parser->theA);
            if (
                (parser->theY == '\n' || parser->theY == ' ') &&
                (parser->theA == '+' || parser->theA == '-' || parser->theA == '*' || parser->theA == '/') &&
                (parser->theB == '+' || parser->theB == '-' || parser->theB == '*' || parser->theB == '/')
            ) {
                smart_str_appendc(parser->minified, parser->theY);
            }
        case JSMIN_ACTION_NEXT_DELETE:
            parser->theA = parser->theB;
            if (parser->theA == '\'' || parser->theA == '"' || parser->theA == '`') {
                for (;;) {
                    smart_str_appendc(parser->minified, parser->theA);
                    parser->theA = jsmin_get(parser);
                    if (parser->theA == parser->theB) {
                        break;
                    }
                    if (parser->theA == '\\') {
                        smart_str_appendc(parser->minified, parser->theA);
                        parser->theA = jsmin_get(parser);
                    }
                    if (parser->theA == EOF) {
                        jsmin_error("Unterminated string literal.");
                    }
                }
            }
        case JSMIN_ACTION_NEXT:
            parser->theB = jsmin_next(parser);
            if (parser->theB == '/' && (
                parser->theA == '(' || parser->theA == ',' || parser->theA == '=' || parser->theA == ':' ||
                parser->theA == '[' || parser->theA == '!' || parser->theA == '&' || parser->theA == '|' ||
                parser->theA == '?' || parser->theA == '+' || parser->theA == '-' || parser->theA == '~' ||
                parser->theA == '*' || parser->theA == '/' || parser->theA == '{' || parser->theA == '\n'
            )) {
                smart_str_appendc(parser->minified, parser->theA);
                if (parser->theA == '/' || parser->theA == '*') {
                    smart_str_appendc(parser->minified, ' ');
                }
                smart_str_appendc(parser->minified, parser->theB);
                for (;;) {
                    parser->theA = jsmin_get(parser);
                    if (parser->theA == '[') {
                        for (;;) {
                            smart_str_appendc(parser->minified, parser->theA);
                            parser->theA = jsmin_get(parser);
                            if (parser->theA == ']') {
                                break;
                            }
                            if (parser->theA == '\\') {
                                smart_str_appendc(parser->minified, parser->theA);
                                parser->theA = jsmin_get(parser);
                            }
                            if (parser->theA == EOF) {
                                jsmin_error("Unterminated set in Regular Expression literal.");
                            }
                        }
                    } else {
                        if (parser->theA == '/') {
                            switch (jsmin_peek(parser)) {
                                case '/':
                                case '*':
                                    jsmin_error("Unterminated set in Regular Expression literal.");
                            }
                            break;
                        } else {
                            if (parser->theA == '\\') {
                                smart_str_appendc(parser->minified, parser->theA);
                                parser->theA = jsmin_get(parser);
                            }
                        }
                    }
                    if (parser->theA == EOF) {
                        jsmin_error("Unterminated Regular Expression literal.");
                    }
                    smart_str_appendc(parser->minified, parser->theA);
                }
                parser->theB = jsmin_next(parser);
            }
    }
}


/* jsmin -- Copy the input to the output, deleting the characters which are
        insignificant to JavaScript. Comments will be removed. Tabs will be
        replaced with spaces. Carriage returns will be replaced with linefeeds.
        Most spaces and linefeeds will be removed.
*/

extern void phalcon_jsmin(zval *return_value, zval *script) {

    jsmin_parser parser;
    smart_str minified = {0};

    parser.theA = '\n';
    parser.theX = EOF;
    parser.theY = EOF;
    parser.script = script;
    parser.script_pointer = 0;
    parser.minified = &minified;

    jsmin_action(&parser, JSMIN_ACTION_NEXT);
    while (parser.theA != EOF) {
        switch (parser.theA) {
            case ' ':
                jsmin_action(&parser, jsmin_isAlphanum(parser.theB) ? JSMIN_ACTION_OUTPUT_NEXT : JSMIN_ACTION_NEXT_DELETE);
                break;
            case '\n':
                switch (parser.theB) {
                    case '{':
                    case '[':
                    case '(':
                    case '+':
                    case '-':
                    case '!':
                    case '~':
                        jsmin_action(&parser, JSMIN_ACTION_OUTPUT_NEXT);
                        break;
                    case ' ':
                        jsmin_action(&parser, JSMIN_ACTION_NEXT);
                        break;
                    default:
                        jsmin_action(&parser, jsmin_isAlphanum(parser.theB) ? JSMIN_ACTION_OUTPUT_NEXT : JSMIN_ACTION_NEXT_DELETE);
                }
                break;
            default:
                switch (parser.theB) {
                    case ' ':
                        jsmin_action(&parser, jsmin_isAlphanum(parser.theA) ? JSMIN_ACTION_OUTPUT_NEXT : JSMIN_ACTION_NEXT);
                        break;
                    case '\n':
                        switch (parser.theA) {
                            case '}':
                            case ']':
                            case ')':
                            case '+':
                            case '-':
                            case '"':
                            case '\'':
                            case '`':
                                jsmin_action(&parser, JSMIN_ACTION_OUTPUT_NEXT);
                                break;
                            default:
                                jsmin_action(&parser, jsmin_isAlphanum(parser.theA) ? JSMIN_ACTION_OUTPUT_NEXT : JSMIN_ACTION_NEXT);
                            }
                            break;
                    default:
                        jsmin_action(&parser, JSMIN_ACTION_OUTPUT_NEXT);
                        break;
                }
        }
    }

    smart_str_0(&minified);

    if (minified.len) {
        RETURN_STRINGL(minified.c, minified.len, 0);
    } else {
        RETURN_EMPTY_STRING();
    }
}

