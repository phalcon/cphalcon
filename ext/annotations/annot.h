
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

typedef struct _phannot_parser_token {
	char *token;
	int opcode;
	int token_len;
	int free_flag;
} phannot_parser_token;

typedef struct _phannot_parser_status {
	zval *ret;
	phannot_scanner_state *scanner_state;
	phannot_scanner_token *token;
	int status;
	zend_uint syntax_error_len;
	char *syntax_error;
} phannot_parser_status;

#define PHANNOT_PARSING_OK 1
#define PHANNOT_PARSING_FAILED 0

extern int phannot_parse_annotations(zval *result, zval *view_code, zval *template_path, zval *line TSRMLS_DC);
int phannot_internal_parse_annotations(zval **result, zval *view_code, zval *template_path, zval *line, zval **error_msg TSRMLS_DC);
