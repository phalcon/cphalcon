
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

typedef struct _phql_parser_token {
    int opcode;	
	char *token;
	int token_len;
	int free_flag;
} phql_parser_token;

typedef struct _phql_parser_status {
    int status;
	zval *ret;  
	phql_scanner_state *scanner_state;
} phql_parser_status;

#define PHQL_PARSING_OK 1
#define PHQL_PARSING_FAILED 1

extern int phql_parse_sql(zval *result, zval *sql);
extern int phql_internal_parse_sql(zval **result, char *sql, zval **error_msg);
    