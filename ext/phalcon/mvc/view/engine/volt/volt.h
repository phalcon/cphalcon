/* volt.h
 *
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

#ifndef PHALCON_MVC_VIEW_ENGINE_VOLT_VOLT_H
#define PHALCON_MVC_VIEW_ENGINE_VOLT_VOLT_H

typedef struct _phvolt_parser_token { /* {{{ */
	char *token;
	int opcode;
	int token_len;
	int free_flag;
} phvolt_parser_token;
/* }}} */

typedef struct _phvolt_parser_status { /* {{{ */
	zval ret;
	phvolt_scanner_state *scanner_state;
	int status;
	unsigned int syntax_error_len;
	char *syntax_error;
	phvolt_scanner_token *token;
} phvolt_parser_status;
/* }}} */

#define PHVOLT_PARSING_OK 1
#define PHVOLT_PARSING_FAILED 0

extern int phvolt_parse_view(zval *result, zval *view_code, zval *template_path);
int phvolt_internal_parse_view(zval **result, zval *view_code, zval *template_path, zval **error_msg);

#endif // PHALCON_MVC_VIEW_ENGINE_VOLT_VOLT_H

/* Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
