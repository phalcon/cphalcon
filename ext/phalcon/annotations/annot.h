
/*
	+------------------------------------------------------------------------+
	| Phalcon Framework                                                      |
	+------------------------------------------------------------------------+
	| Copyright (c) 2011-2016 Phalcon Team (http://www.phalconphp.com)       |
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

#ifndef PHALCON_ANNOTATIONS_ANNOT_H
#define PHALCON_ANNOTATIONS_ANNOT_H

#include <Zend/zend.h>
#include "scanner.h"

typedef struct _phannot_parser_token {
	char *token;
	int opcode;
	int token_len;
	int free_flag;
} phannot_parser_token;

typedef struct _phannot_parser_status {
#if PHP_VERSION_ID < 70000
	zval *ret;
#else
	zval ret;
#endif
	phannot_scanner_state *scanner_state;
	phannot_scanner_token *token;
	char *syntax_error;
	int status;
} phannot_parser_status;

#define PHANNOT_PARSING_OK 1
#define PHANNOT_PARSING_FAILED 0

int phannot_parse_annotations(zval *result, zval *comment, zval *file_path, zval *line TSRMLS_DC);
int phannot_internal_parse_annotations(zval **result, const char *comment, int comment_len, const char *file_path, int line, char **error_msg TSRMLS_DC);

#endif /* PHALCON_ANNOTATIONS_ANNOT_H */
