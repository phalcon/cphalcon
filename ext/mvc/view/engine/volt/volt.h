
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

typedef struct _phvolt_parser_token {
	int opcode;
	char *token;
	int token_len;
	int free_flag;
} phvolt_parser_token;

typedef struct _phvolt_parser_status {
	int status;
	zval *ret;
	phvolt_scanner_state *scanner_state;
	char *syntax_error;
	zend_uint syntax_error_len;
} phvolt_parser_status;

#define PHVOLT_PARSING_OK 1
#define PHVOLT_PARSING_FAILED 0

extern int phvolt_parse_view(zval *result, zval *view_code, zval *template_path TSRMLS_DC);
int phvolt_internal_parse_view(zval **result, zval *view_code, zval *template_path, zval **error_msg TSRMLS_DC);
