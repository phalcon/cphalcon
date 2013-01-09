
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

int phql_get_token(phql_scanner_state *s, phql_scanner_token *token) {

	char *q = YYCURSOR;
	int status = PHQL_SCANNER_RETCODE_IMPOSSIBLE;

	while (PHQL_SCANNER_RETCODE_IMPOSSIBLE == status) {

		/*!re2c
		re2c:indent:top = 2;
		re2c:yyfill:enable = 0;

		INTEGER = [0-9]+;
		INTEGER {
			token->opcode = PHQL_T_INTEGER;
			token->value = estrndup(q, YYCURSOR - q);
			token->len = YYCURSOR - q;
			q = YYCURSOR;
			return 0;
		}

		DOUBLE = ([0-9]*[\.][0-9]+)|([0-9]+[\.][0-9]*);
		DOUBLE {
			token->opcode = PHQL_T_DOUBLE;
			token->value = estrndup(q, YYCURSOR - q);
			token->len = YYCURSOR - q;
			q = YYCURSOR;
			return 0;
		}

		NPLACEHOLDER = "?"[0-9]+;
		NPLACEHOLDER {
			token->opcode = PHQL_T_NPLACEHOLDER;
			token->value = estrndup(q, YYCURSOR - q);
			token->len = YYCURSOR - q;
			q = YYCURSOR;
			return 0;
		}

		SPLACEHOLDER = ":"[a-zA-Z0-9\_]+":";
		SPLACEHOLDER {
			token->opcode = PHQL_T_SPLACEHOLDER;
			token->value = estrndup(q, YYCURSOR - q - 1);
			token->len = YYCURSOR - q - 1;
			q = YYCURSOR;
			return 0;
		}

		'UPDATE' {
			token->opcode = PHQL_T_UPDATE;
			return 0;
		}

		'SET' {
			token->opcode = PHQL_T_SET;
			return 0;
		}

		'DELETE' {
			token->opcode = PHQL_T_DELETE;
			return 0;
		}

		'FROM' {
			token->opcode = PHQL_T_FROM;
			return 0;
		}

		'AS' {
			token->opcode = PHQL_T_AS;
			return 0;
		}

		'INSERT' {
			token->opcode = PHQL_T_INSERT;
			return 0;
		}

		'INTO' {
			token->opcode = PHQL_T_INTO;
			return 0;
		}

		'VALUES' {
			token->opcode = PHQL_T_VALUES;
			return 0;
		}

		'WHERE' {
			token->opcode = PHQL_T_WHERE;
			return 0;
		}

		'SELECT' {
			token->opcode = PHQL_T_SELECT;
			return 0;
		}

		'ORDER' {
			token->opcode = PHQL_T_ORDER;
			return 0;
		}

		'BY' {
			token->opcode = PHQL_T_BY;
			return 0;
		}

		'ASC' {
			token->opcode = PHQL_T_ASC;
			return 0;
		}

		'DESC' {
			token->opcode = PHQL_T_DESC;
			return 0;
		}

		'GROUP' {
			token->opcode = PHQL_T_GROUP;
			return 0;
		}

		'HAVING' {
			token->opcode = PHQL_T_HAVING;
			return 0;
		}

		'LIMIT' {
			token->opcode = PHQL_T_LIMIT;
			return 0;
		}

		'OFFSET' {
			token->opcode = PHQL_T_OFFSET;
			return 0;
		}

		'NOT' {
			token->opcode = PHQL_T_NOT;
			return 0;
		}

		'AND' {
			token->opcode = PHQL_T_AND;
			return 0;
		}

		'OR' {
			token->opcode = PHQL_T_OR;
			return 0;
		}

		'LIKE' {
			token->opcode = PHQL_T_LIKE;
			return 0;
		}

		'IN' {
			token->opcode = PHQL_T_IN;
			return 0;
		}

		'ON' {
			token->opcode = PHQL_T_ON;
			return 0;
		}

		'JOIN' {
			token->opcode = PHQL_T_JOIN;
			return 0;
		}

		'INNER' {
			token->opcode = PHQL_T_INNER;
			return 0;
		}

		'LEFT' {
			token->opcode = PHQL_T_LEFT;
			return 0;
		}

		'RIGHT' {
			token->opcode = PHQL_T_RIGHT;
			return 0;
		}

		'CROSS' {
			token->opcode = PHQL_T_CROSS;
			return 0;
		}

		'OUTER' {
			token->opcode = PHQL_T_OUTER;
			return 0;
		}

		'FULL' {
			token->opcode = PHQL_T_FULL;
			return 0;
		}

		'IS' {
			token->opcode = PHQL_T_IS;
			return 0;
		}

		'NULL' {
			token->opcode = PHQL_T_NULL;
			return 0;
		}

		'DISTINCT' {
			token->opcode = PHQL_T_DISTINCT;
			return 0;
		}

		'BETWEEN' {
			token->opcode = PHQL_T_BETWEEN;
			return 0;
		}

		STRING = (["] ([\\]["]|[\\].|[\001-\377]\[\\"])* ["])|(['] ([\\][']|[\\].|[\001-\377]\[\\'])* [']);
		STRING {
			token->opcode = PHQL_T_STRING;
			token->value = estrndup(q, YYCURSOR - q - 1);
			token->len = YYCURSOR - q - 1;
			q = YYCURSOR;
			return 0;
		}

		IDENTIFIER = [a-zA-Z][a-zA-Z0-9\_\\]*;
		IDENTIFIER {
			token->opcode = PHQL_T_IDENTIFIER;
			token->value = estrndup(q, YYCURSOR - q);
			token->len = YYCURSOR - q;
			q = YYCURSOR;
			return 0;
		}

		EIDENTIFIER = [\[] [a-zA-Z][a-zA-Z0-9\_\\]* [\]];
		EIDENTIFIER {
			token->opcode = PHQL_T_IDENTIFIER;
			token->value = estrndup(q, YYCURSOR - q - 1);
			token->len = YYCURSOR - q - 1;
			q = YYCURSOR;
			return 0;
		}

		"+" {
			token->opcode = PHQL_T_ADD;
			return 0;
		}

		"-" {
			token->opcode = PHQL_T_SUB;
			return 0;
		}

		"*" {
			token->opcode = PHQL_T_MUL;
			return 0;
		}

		"/" {
			token->opcode = PHQL_T_DIV;
			return 0;
		}

		"%" {
			token->opcode = PHQL_T_MOD;
			return 0;
		}

		"." {
			token->opcode = PHQL_T_DOT;
			return 0;
		}

		"," {
			token->opcode = PHQL_T_COMMA;
			return 0;
		}

		"(" {
			token->opcode = PHQL_T_BRACKET_OPEN;
			return 0;
		}

		")" {
			token->opcode = PHQL_T_BRACKET_CLOSE;
			return 0;
		}

		"!=" {
			token->opcode = PHQL_T_NOTEQUALS;
			return 0;
		}

		"<>" {
			token->opcode = PHQL_T_NOTEQUALS;
			return 0;
		}

		"<=" {
			token->opcode = PHQL_T_LESSEQUAL;
			return 0;
		}

		">=" {
			token->opcode = PHQL_T_GREATEREQUAL;
			return 0;
		}

		"=" {
			token->opcode = PHQL_T_EQUALS;
			return 0;
		}

		"!" {
			token->opcode = PHQL_T_NOT;
			return 0;
		}

		"<" {
			token->opcode = PHQL_T_LESS;
			return 0;
		}

		">" {
			token->opcode = PHQL_T_GREATER;
			return 0;
		}

		[ \t\n\r]+ {
			token->opcode = PHQL_T_IGNORE;
			return 0;
		}

		"\000" {
			status = PHQL_SCANNER_RETCODE_EOF;
			break;
		}

		[^] {
			status = PHQL_SCANNER_RETCODE_ERR;
			break;
		}

		*/
	}

	return status;
}
