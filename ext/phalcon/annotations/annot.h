/* annot.h
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
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
	zval ret;
	phannot_scanner_state *scanner_state;
	phannot_scanner_token *token;
	char *syntax_error;
	int status;
} phannot_parser_status;

#define PHANNOT_PARSING_OK 1
#define PHANNOT_PARSING_FAILED 0

int phannot_parse_annotations(zval *result, zval *comment, zval *file_path, zval *line);
int phannot_internal_parse_annotations(zval **result, const char *comment, int comment_len, const char *file_path, int line, char **error_msg);

#endif /* PHALCON_ANNOTATIONS_ANNOT_H */
