
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"

#include "scanner.h"

#define YYCTYPE unsigned char
#define YYCURSOR (s->start)
#define YYLIMIT (s->end)
#define YYMARKER q

int phvolt_get_token(phvolt_scanner_state *s, phvolt_scanner_token *token) {

	char next, *q = YYCURSOR, *start = YYCURSOR;
	int status = PHVOLT_SCANNER_RETCODE_IMPOSSIBLE;

	while (PHVOLT_SCANNER_RETCODE_IMPOSSIBLE == status) {

		if (s->mode == PHVOLT_MODE_RAW || s->mode == PHVOLT_MODE_COMMENT) {

			if (*YYCURSOR == '\n') {
				s->active_line++;
			}

			next = *(YYCURSOR+1);
			if (*YYCURSOR == '\0' || (*YYCURSOR == '{' && (next == '%' || next == '{' || next == '#'))) {

				if (next != '#') {

					s->mode = PHVOLT_MODE_CODE;

					if (s->raw_buffer_cursor > 0) {
						token->opcode = PHVOLT_T_RAW_FRAGMENT;
						token->value = emalloc(sizeof(char) * s->raw_buffer_cursor+1);
						memcpy(token->value, s->raw_buffer, s->raw_buffer_cursor);
						token->value[s->raw_buffer_cursor] = 0;
						token->len = s->raw_buffer_cursor;
						s->raw_buffer_cursor = 0;
						q = YYCURSOR;
					} else {
						token->opcode = PHVOLT_T_IGNORE;
					}

				} else {

					while ((next = *(++YYCURSOR))) {
						if (next == '#' && *(YYCURSOR+1) == '}') {
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

		'extends' {
			s->statement_position++;
			token->opcode = PHVOLT_T_EXTENDS;
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

		"{%" {
			token->opcode = PHVOLT_T_OPEN_DELIMITER;
			return 0;
		}

		"%}" {
			s->mode = PHVOLT_MODE_RAW;
			token->opcode = PHVOLT_T_CLOSE_DELIMITER;
			return 0;
		}

		"{{" {
			s->statement_position++;
			token->opcode = PHVOLT_T_OPEN_EDELIMITER;
			return 0;
		}

		"}}" {
			s->mode = PHVOLT_MODE_RAW;
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

		IDENTIFIER = [a-zA-Z][a-zA-Z0-9\_\\]*;
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
			token->opcode = PHVOLT_T_BRACKET_OPEN;
			return 0;
		}

		")" {
			token->opcode = PHVOLT_T_BRACKET_CLOSE;
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

		"<=" {
			token->opcode = PHVOLT_T_LESSEQUAL;
			return 0;
		}

		"=" {
			token->opcode = PHVOLT_T_ASSIGN;
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
			token->opcode = PHVOLT_T_DOUBLECOLON;
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
