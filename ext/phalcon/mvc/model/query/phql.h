/* phql.h
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

#ifndef PHALCON_MVC_MODEL_QUERY_PHQL_H
#define PHALCON_MVC_MODEL_QUERY_PHQL_H

typedef struct _phql_parser_token {
	char *token;
	int opcode;
	unsigned int token_len;
	int free_flag;
} phql_parser_token;

typedef struct _phql_parser_status {
	zval ret;
	char* phql;
	unsigned int phql_length;
	int status;
	phql_scanner_state *scanner_state;
	phql_scanner_token *token;
	char *syntax_error;
	unsigned int syntax_error_len;
	zend_bool enable_literals;
} phql_parser_status;

#define PHQL_PARSING_OK 1
#define PHQL_PARSING_FAILED 0

extern int phql_parse_phql(zval *result, zval *phql);
extern int phql_internal_parse_phql(zval **result, char *phql, unsigned int phql_length, zval **error_msg);

#endif /* PHALCON_MVC_MODEL_QUERY_PHQL_H */
