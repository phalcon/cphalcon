/* scanner.re
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

#include "php_phalcon.h"

#include "scanner.h"

#define YYCTYPE unsigned char
#define YYCURSOR (s->start)
#define YYLIMIT (s->end)
#define YYMARKER q

int phannot_get_token(phannot_scanner_state *s, phannot_scanner_token *token) {

	char next, *q = YYCURSOR, *start = YYCURSOR;
	int status = PHANNOT_SCANNER_RETCODE_IMPOSSIBLE;

	while (PHANNOT_SCANNER_RETCODE_IMPOSSIBLE == status) {

		if (s->mode == PHANNOT_MODE_RAW) {

			if (*YYCURSOR == '\n') {
				s->active_line++;
			}

			next = *(YYCURSOR+1);

			if (*YYCURSOR == '\0' || *YYCURSOR == '@') {
				if ((next >= 'A' && next <= 'Z') || (next >= 'a' && next <= 'z')) {
					s->mode = PHANNOT_MODE_ANNOTATION;
					continue;
				}
			}

			++YYCURSOR;
			token->opcode = PHANNOT_T_IGNORE;
			return 0;

		} else {

		/*!re2c
		re2c:indent:top = 2;
		re2c:yyfill:enable = 0;

		INTEGER = [\-]?[0-9]+;
		INTEGER {
			token->opcode = PHANNOT_T_INTEGER;
			token->value = estrndup(start, YYCURSOR - start);
			token->len = YYCURSOR - start;
			q = YYCURSOR;
			return 0;
		}

		DOUBLE = ([\-]?[0-9]+[.][0-9]+);
		DOUBLE {
			token->opcode = PHANNOT_T_DOUBLE;
			token->value = estrndup(start, YYCURSOR - start);
			token->len = YYCURSOR - start;
			q = YYCURSOR;
			return 0;
		}

		'null' {
			token->opcode = PHANNOT_T_NULL;
			return 0;
		}

		'false' {
			token->opcode = PHANNOT_T_FALSE;
			return 0;
		}

		'true' {
			token->opcode = PHANNOT_T_TRUE;
			return 0;
		}

		STRING = (["] ([\\]["]|[\\].|[\001-\377]\[\\"])* ["])|(['] ([\\][']|[\\].|[\001-\377]\[\\'])* [']);
		STRING {
			token->opcode = PHANNOT_T_STRING;
			token->value = estrndup(q, YYCURSOR - q - 1);
			token->len = YYCURSOR - q - 1;
			q = YYCURSOR;
			return 0;
		}

		IDENTIFIER = ('\x5C'?[a-zA-Z_]([a-zA-Z0-9_]*)('\x5C'[a-zA-Z_]([a-zA-Z0-9_]*))*);
		IDENTIFIER {
			token->opcode = PHANNOT_T_IDENTIFIER;
			token->value = estrndup(start, YYCURSOR - start);
			token->len = YYCURSOR - start;
			q = YYCURSOR;
			return 0;
		}

		"(" {
			token->opcode = PHANNOT_T_PARENTHESES_OPEN;
			return 0;
		}

		")" {
			token->opcode = PHANNOT_T_PARENTHESES_CLOSE;
			return 0;
		}

		"{" {
			token->opcode = PHANNOT_T_BRACKET_OPEN;
			return 0;
		}

		"}" {
			token->opcode = PHANNOT_T_BRACKET_CLOSE;
			return 0;
		}

		"[" {
			token->opcode = PHANNOT_T_SBRACKET_OPEN;
			return 0;
		}

		"]" {
			token->opcode = PHANNOT_T_SBRACKET_CLOSE;
			return 0;
		}

		"@" {
			token->opcode = PHANNOT_T_AT;
			return 0;
		}

		"=" {
			token->opcode = PHANNOT_T_EQUALS;
			return 0;
		}

		":" {
			token->opcode = PHANNOT_T_COLON;
			return 0;
		}

		"," {
			token->opcode = PHANNOT_T_COMMA;
			return 0;
		}

		[ \t\r]+ {
			token->opcode = PHANNOT_T_IGNORE;
			return 0;
		}

		[\n] {
			s->active_line++;
			token->opcode = PHANNOT_T_IGNORE;
			return 0;
		}

		"\000" {
			status = PHANNOT_SCANNER_RETCODE_EOF;
			break;
		}

		[^] {
			status = PHANNOT_SCANNER_RETCODE_ERR;
			break;
		}

		*/

		}
	}

	return status;
}
