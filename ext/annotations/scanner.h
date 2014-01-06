
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

#define PHANNOT_SCANNER_RETCODE_EOF -1
#define PHANNOT_SCANNER_RETCODE_ERR -2
#define PHANNOT_SCANNER_RETCODE_IMPOSSIBLE -3

/** Modes */
#define PHANNOT_MODE_RAW 0
#define PHANNOT_MODE_ANNOTATION 1

#define PHANNOT_T_IGNORE 297

#define PHANNOT_T_DOCBLOCK_ANNOTATION 299
#define PHANNOT_T_ANNOTATION 300

/* Literals & Identifiers */
#define PHANNOT_T_INTEGER 301
#define PHANNOT_T_DOUBLE 302
#define PHANNOT_T_STRING 303
#define PHANNOT_T_NULL 304
#define PHANNOT_T_FALSE 305
#define PHANNOT_T_TRUE 306
#define PHANNOT_T_IDENTIFIER 307
#define PHANNOT_T_ARRAY 308
#define PHANNOT_T_ARBITRARY_TEXT 309

/* Operators */
#define PHANNOT_T_AT '@'
#define PHANNOT_T_DOT '.'
#define PHANNOT_T_COMMA ','
#define PHANNOT_T_EQUALS '='
#define PHANNOT_T_COLON ':'
#define PHANNOT_T_BRACKET_OPEN '{'
#define PHANNOT_T_BRACKET_CLOSE '}'
#define PHANNOT_T_SBRACKET_OPEN '['
#define PHANNOT_T_SBRACKET_CLOSE ']'
#define PHANNOT_T_PARENTHESES_OPEN '('
#define PHANNOT_T_PARENTHESES_CLOSE ')'

/* List of tokens and their names */
typedef struct _phannot_token_names {
	char *name;
	unsigned int code;
} phannot_token_names;

/* Active token state */
typedef struct _phannot_scanner_state {
	char* start;
	char* end;
	int active_token;
	unsigned int start_length;
	int mode;
	unsigned int active_line;
	zval *active_file;
} phannot_scanner_state;

/* Extra information tokens */
typedef struct _phannot_scanner_token {
	char *value;
	int opcode;
	int len;
} phannot_scanner_token;

int phannot_get_token(phannot_scanner_state *s, phannot_scanner_token *token);

extern const phannot_token_names phannot_tokens[];
