
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#include "php_phalcon.h"
#include "scanner.h"

#define YYCTYPE unsigned char
#define YYCURSOR (s->start)
#define YYLIMIT (s->end)
#define YYMARKER q

void phvolt_rtrim(phvolt_scanner_token *token) {

	char *cursor, *removed_str;
	int i;
	char ch;

	if (token->len > 0) {

		cursor = token->value;
		cursor += (token->len - 1);
		for (i = token->len; i > 0; i--) {
			ch = (*cursor);
			if (ch == '\t' || ch == '\n' || ch == '\r' || ch == ' ' || ch == '\v') {
				cursor--;
				continue;
			}
			break;
		}

        if (i >= 0) {
    		removed_str = emalloc(i + 1);
    		memcpy(removed_str, token->value, i);
    		removed_str[i] = '\0';

    		efree(token->value);
    		token->value = removed_str;
    		token->len = i;
        }
	}

}

void phvolt_ltrim(phvolt_scanner_token *token) {

	char *cursor, *removed_str;
	int i;

	if (token->len > 0) {

		cursor = token->value;
		for (i = 0; i < token->len; i++) {
			char ch = (*cursor);
			if (ch == '\t' || ch == '\n' || ch == '\r' || ch == ' ' || ch == '\v') {
				cursor++;
				continue;
			}
			break;
		}

        if (i >= 0) {
    		removed_str = emalloc(token->len - i + 1);
    		memcpy(removed_str, token->value + i, token->len - i);
    		removed_str[token->len - i] = '\0';

    		efree(token->value);
    		token->value = removed_str;
    		token->len = token->len - i;
        }
	}

}

int phvolt_get_token(phvolt_scanner_state *s, phvolt_scanner_token *token) {

	unsigned char next, double_next;
	char *q = YYCURSOR, *start = YYCURSOR;
	int status = PHVOLT_SCANNER_RETCODE_IMPOSSIBLE;

	while (PHVOLT_SCANNER_RETCODE_IMPOSSIBLE == status) {

		if (s->mode == PHVOLT_MODE_RAW || s->mode == PHVOLT_MODE_COMMENT) {

			next = '\0';
			double_next = '\0';

			if (*YYCURSOR == '\n') {
				s->active_line++;
			}

			if (*YYCURSOR != '\0') {
				next = *(YYCURSOR + 1);
				if (next != '\0') {
					double_next = *(YYCURSOR + 2);
				}
			}

			if (*YYCURSOR == '\0' || (*YYCURSOR == '{' && (next == '%' || next == '{' || next == '#'))) {

				if (next != '#') {

					s->mode = PHVOLT_MODE_CODE;

					if (s->raw_buffer_cursor > 0) {

						token->opcode = PHVOLT_T_RAW_FRAGMENT;
						token->value = emalloc(sizeof(char) * s->raw_buffer_cursor + 1);
						memcpy(token->value, s->raw_buffer, s->raw_buffer_cursor);
						token->value[s->raw_buffer_cursor] = 0;
						token->len = s->raw_buffer_cursor;

						if (s->whitespace_control == 1) {
							phvolt_ltrim(token);
							s->whitespace_control = 0;
						}

						if (double_next == '-') {
							phvolt_rtrim(token);
						}

						s->raw_buffer_cursor = 0;
						q = YYCURSOR;
					} else {
						token->opcode = PHVOLT_T_IGNORE;
					}

				} else {

					while ((next = *(++YYCURSOR))) {
						if (next == '#' && *(YYCURSOR + 1) == '}') {
							YYCURSOR+=2;
							token->opcode = PHVOLT_T_IGNORE;
							return 0;
						} else {
							if (next == '\n') {
								s->active_line++;
							}
						}
					}

					return PHVOLT_SCANNER_RETCODE_EOF;
				}

				return 0;

			} else {

				if (s->raw_buffer_cursor == s->raw_buffer_size) {
					s->raw_buffer_size += PHVOLT_RAW_BUFFER_SIZE;
					s->raw_buffer = erealloc(s->raw_buffer, s->raw_buffer_size);
				}

				memcpy(s->raw_buffer+s->raw_buffer_cursor, YYCURSOR, 1);
				s->raw_buffer_cursor++;

				++YYCURSOR;
			}

		} else {

		/*!re2c
		re2c:indent:top = 2;
		re2c:yyfill:enable = 0;

		INTEGER = [0-9]+;
		INTEGER {
			token->opcode = PHVOLT_T_INTEGER;
			token->value = estrndup(start, YYCURSOR - start);
			token->len = YYCURSOR - start;
			q = YYCURSOR;
			return 0;
		}

		DOUBLE = ([0-9]+[\.][0-9]+);
		DOUBLE {
			token->opcode = PHVOLT_T_DOUBLE;
			token->value = estrndup(start, YYCURSOR - start);
			token->len = YYCURSOR - start;
			q = YYCURSOR;
			return 0;
		}

		'if' {
			s->statement_position++;
			token->opcode = PHVOLT_T_IF;
			return 0;
		}

		'else' {
			token->opcode = PHVOLT_T_ELSE;
			return 0;
		}

		'elsefor' {
			token->opcode = PHVOLT_T_ELSEFOR;
			return 0;
		}

		'elseif' {
			token->opcode = PHVOLT_T_ELSEIF;
			return 0;
		}

		'endif' {
			token->opcode = PHVOLT_T_ENDIF;
			return 0;
		}

		'for' {
			s->statement_position++;
			token->opcode = PHVOLT_T_FOR;
			return 0;
		}

		'endfor' {
			token->opcode = PHVOLT_T_ENDFOR;
			return 0;
		}

		'in' {
			token->opcode = PHVOLT_T_IN;
			return 0;
		}

		'set' {
			token->opcode = PHVOLT_T_SET;
			return 0;
		}

		'null' {
			token->opcode = PHVOLT_T_NULL;
			return 0;
		}

		'false' {
			token->opcode = PHVOLT_T_FALSE;
			return 0;
		}

		'true' {
			token->opcode = PHVOLT_T_TRUE;
			return 0;
		}

		'and' {
			token->opcode = PHVOLT_T_AND;
			return 0;
		}

		'or' {
			token->opcode = PHVOLT_T_OR;
			return 0;
		}

		'block' {
			s->statement_position++;
			token->opcode = PHVOLT_T_BLOCK;
			return 0;
		}

		'endblock' {
			token->opcode = PHVOLT_T_ENDBLOCK;
			return 0;
		}

		'macro' {
			s->statement_position++;
			token->opcode = PHVOLT_T_MACRO;
			return 0;
		}

		'endmacro' {
			token->opcode = PHVOLT_T_ENDMACRO;
			return 0;
		}

		'call' {
			s->statement_position++;
			token->opcode = PHVOLT_T_CALL;
			return 0;
		}

		'endcall' {
			token->opcode = PHVOLT_T_ENDCALL;
			return 0;
		}

		'with' {
			token->opcode = PHVOLT_T_WITH;
			return 0;
		}

		'return' {
			token->opcode = PHVOLT_T_RETURN;
			return 0;
		}

		'extends' {
			s->statement_position++;
			token->opcode = PHVOLT_T_EXTENDS;
			return 0;
		}

		'is not' {
			s->statement_position++;
			token->opcode = PHVOLT_T_NOTEQUALS;
			return 0;
		}

		[i][s][ ]+[n][o][t] {
			s->statement_position++;
			token->opcode = PHVOLT_T_NOTEQUALS;
			return 0;
		}

		'is' {
			s->statement_position++;
			token->opcode = PHVOLT_T_IS;
			return 0;
		}

		'not' {
			s->statement_position++;
			token->opcode = PHVOLT_T_NOT;
			return 0;
		}

		'defined' {
			s->statement_position++;
			token->opcode = PHVOLT_T_DEFINED;
			return 0;
		}

		'include' {
			s->statement_position++;
			token->opcode = PHVOLT_T_INCLUDE;
			return 0;
		}

		'empty' {
			s->statement_position++;
			token->opcode = PHVOLT_T_EMPTY;
			return 0;
		}

		'even' {
			s->statement_position++;
			token->opcode = PHVOLT_T_EVEN;
			return 0;
		}

		'odd' {
			s->statement_position++;
			token->opcode = PHVOLT_T_ODD;
			return 0;
		}

		'numeric' {
			s->statement_position++;
			token->opcode = PHVOLT_T_NUMERIC;
			return 0;
		}

		'scalar' {
			s->statement_position++;
			token->opcode = PHVOLT_T_SCALAR;
			return 0;
		}

		'iterable' {
			s->statement_position++;
			token->opcode = PHVOLT_T_ITERABLE;
			return 0;
		}

		'cache' {
			s->statement_position++;
			token->opcode = PHVOLT_T_CACHE;
			return 0;
		}

		'endcache' {
			token->opcode = PHVOLT_T_ENDCACHE;
			return 0;
		}

		'do' {
			s->statement_position++;
			token->opcode = PHVOLT_T_DO;
			return 0;
		}

		'autoescape' {
			s->statement_position++;
			token->opcode = PHVOLT_T_AUTOESCAPE;
			return 0;
		}

		'endautoescape' {
			s->statement_position++;
			token->opcode = PHVOLT_T_ENDAUTOESCAPE;
			return 0;
		}

		'continue' {
			s->statement_position++;
			token->opcode = PHVOLT_T_CONTINUE;
			return 0;
		}

		'break' {
			s->statement_position++;
			token->opcode = PHVOLT_T_BREAK;
			return 0;
		}

		"{%" {
			s->whitespace_control = 0;
			token->opcode = PHVOLT_T_OPEN_DELIMITER;
			return 0;
		}

		"%}" {
			s->mode = PHVOLT_MODE_RAW;
			token->opcode = PHVOLT_T_CLOSE_DELIMITER;
			return 0;
		}

		"{%-" {
			s->whitespace_control = 0;
			token->opcode = PHVOLT_T_OPEN_DELIMITER;
			return 0;
		}

		"-%}" {
			s->mode = PHVOLT_MODE_RAW;
			s->whitespace_control = 1;
			token->opcode = PHVOLT_T_CLOSE_DELIMITER;
			return 0;
		}

		"{{" {
			s->whitespace_control = 0;
			s->statement_position++;
			token->opcode = PHVOLT_T_OPEN_EDELIMITER;
			return 0;
		}

		"}}" {
			s->mode = PHVOLT_MODE_RAW;
			token->opcode = PHVOLT_T_CLOSE_EDELIMITER;
			return 0;
		}

		"{{-" {
			s->whitespace_control = 0;
			s->statement_position++;
			token->opcode = PHVOLT_T_OPEN_EDELIMITER;
			return 0;
		}

		"-}}" {
			s->mode = PHVOLT_MODE_RAW;
			s->whitespace_control = 1;
			token->opcode = PHVOLT_T_CLOSE_EDELIMITER;
			return 0;
		}

		STRING = (["] ([\\]["]|[\\].|[\001-\377]\[\\"])* ["])|(['] ([\\][']|[\\].|[\001-\377]\[\\'])* [']);
		STRING {
			token->opcode = PHVOLT_T_STRING;
			token->value = estrndup(q, YYCURSOR - q - 1);
			token->len = YYCURSOR - q - 1;
			q = YYCURSOR;
			return 0;
		}

		IDENTIFIER = [\\]?[a-zA-Z\_][a-zA-Z0-9\_\\]*;
		IDENTIFIER {
			token->opcode = PHVOLT_T_IDENTIFIER;
			token->value = estrndup(start, YYCURSOR - start);
			token->len = YYCURSOR - start;
			q = YYCURSOR;
			return 0;
		}

		"+" {
			token->opcode = PHVOLT_T_ADD;
			return 0;
		}

		"-" {
			token->opcode = PHVOLT_T_SUB;
			return 0;
		}

		"*" {
			token->opcode = PHVOLT_T_MUL;
			return 0;
		}

		"/" {
			token->opcode = PHVOLT_T_DIV;
			return 0;
		}

		"%" {
			token->opcode = PHVOLT_T_MOD;
			return 0;
		}

		"++" {
			token->opcode = PHVOLT_T_INCR;
			return 0;
		}

		"--" {
			token->opcode = PHVOLT_T_DECR;
			return 0;
		}

		"~" {
			token->opcode = PHVOLT_T_CONCAT;
			return 0;
		}

		".." {
			token->opcode = PHVOLT_T_RANGE;
			return 0;
		}

		"." {
			token->opcode = PHVOLT_T_DOT;
			return 0;
		}

		"," {
			token->opcode = PHVOLT_T_COMMA;
			return 0;
		}

		"(" {
			token->opcode = PHVOLT_T_PARENTHESES_OPEN;
			return 0;
		}

		")" {
			token->opcode = PHVOLT_T_PARENTHESES_CLOSE;
			return 0;
		}

		"[" {
			token->opcode = PHVOLT_T_SBRACKET_OPEN;
			return 0;
		}

		"]" {
			token->opcode = PHVOLT_T_SBRACKET_CLOSE;
			return 0;
		}

		"{" {
			token->opcode = PHVOLT_T_CBRACKET_OPEN;
			return 0;
		}

		"}" {
			token->opcode = PHVOLT_T_CBRACKET_CLOSE;
			return 0;
		}

		"<=" {
			token->opcode = PHVOLT_T_LESSEQUAL;
			return 0;
		}

		"=" {
			token->opcode = PHVOLT_T_ASSIGN;
			return 0;
		}

		"+=" {
			token->opcode = PHVOLT_T_ADD_ASSIGN;
			return 0;
		}

		"-=" {
			token->opcode = PHVOLT_T_SUB_ASSIGN;
			return 0;
		}

		"*=" {
			token->opcode = PHVOLT_T_MUL_ASSIGN;
			return 0;
		}

		"/=" {
			token->opcode = PHVOLT_T_DIV_ASSIGN;
			return 0;
		}

		">=" {
			token->opcode = PHVOLT_T_GREATEREQUAL;
			return 0;
		}

		"==" {
			token->opcode = PHVOLT_T_EQUALS;
			return 0;
		}

		"!=" {
			token->opcode = PHVOLT_T_NOTEQUALS;
			return 0;
		}

		"<>" {
			token->opcode = PHVOLT_T_NOTEQUALS;
			return 0;
		}

		"===" {
			token->opcode = PHVOLT_T_IDENTICAL;
			return 0;
		}

		"!==" {
			token->opcode = PHVOLT_T_NOTIDENTICAL;
			return 0;
		}

		"!" {
			token->opcode = PHVOLT_T_NOT;
			return 0;
		}

		"<" {
			token->opcode = PHVOLT_T_LESS;
			return 0;
		}

		">" {
			token->opcode = PHVOLT_T_GREATER;
			return 0;
		}

		"|" {
			token->opcode = PHVOLT_T_PIPE;
			return 0;
		}

		":" {
			token->opcode = PHVOLT_T_COLON;
			return 0;
		}

		"?" {
			token->opcode = PHVOLT_T_QUESTION;
			return 0;
		}

		[ \t\r]+ {
			token->opcode = PHVOLT_T_IGNORE;
			return 0;
		}

		[\n] {
			s->active_line++;
			token->opcode = PHVOLT_T_IGNORE;
			return 0;
		}

		"\000" {
			status = PHVOLT_SCANNER_RETCODE_EOF;
			break;
		}

		[^] {
			status = PHVOLT_SCANNER_RETCODE_ERR;
			break;
		}

		*/

		}
	}

	return status;
}
