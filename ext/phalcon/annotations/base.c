
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

const phannot_token_names phannot_tokens[] =
{
	{ "INTEGER",        PHANNOT_T_INTEGER },
	{ "DOUBLE",         PHANNOT_T_DOUBLE },
	{ "STRING",         PHANNOT_T_STRING },
	{ "IDENTIFIER",     PHANNOT_T_IDENTIFIER },
	{ "@",              PHANNOT_T_AT },
	{ ",",              PHANNOT_T_COMMA },
	{ "=",              PHANNOT_T_EQUALS },
	{ ":",              PHANNOT_T_COLON },
	{ "(",              PHANNOT_T_PARENTHESES_OPEN },
	{ ")",              PHANNOT_T_PARENTHESES_CLOSE },
	{ "{",              PHANNOT_T_BRACKET_OPEN },
	{ "}",              PHANNOT_T_BRACKET_CLOSE },
 	{ "[",              PHANNOT_T_SBRACKET_OPEN },
	{ "]",              PHANNOT_T_SBRACKET_CLOSE },
	{ "ARBITRARY TEXT", PHANNOT_T_ARBITRARY_TEXT },
	{ NULL, 0 }
};

/**
 * Wrapper to alloc memory within the parser
 */
static void *phannot_wrapper_alloc(size_t bytes){
	return emalloc(bytes);
}

/**
 * Wrapper to free memory within the parser
 */
static void phannot_wrapper_free(void *pointer){
	efree(pointer);
}

/**
 * Creates a parser_token to be passed to the parser
 */
static void phannot_parse_with_token(void* phannot_parser, int opcode, int parsercode, phannot_scanner_token *token, phannot_parser_status *parser_status){

	phannot_parser_token *pToken;

	pToken = emalloc(sizeof(phannot_parser_token));
	pToken->opcode = opcode;
	pToken->token = token->value;
	pToken->token_len = token->len;
	pToken->free_flag = 1;

	phannot_(phannot_parser, parsercode, pToken, parser_status);

	token->value = NULL;
	token->len = 0;
}

/**
 * Creates an error message when it's triggered by the scanner
 */
static void phannot_scanner_error_msg(phannot_parser_status *parser_status, zval **error_msg TSRMLS_DC){

	int error_length;
	char *error, *error_part;
	phannot_scanner_state *state = parser_status->scanner_state;

	PHALCON_INIT_VAR(*error_msg);
	if (state->start) {
		error_length = 128 + state->start_length +  Z_STRLEN_P(state->active_file);
		error = emalloc(sizeof(char) * error_length);
		if (state->start_length > 16) {
			error_part = estrndup(state->start, 16);
			snprintf(error, 64 + state->start_length, "Scanning error before '%s...' in %s on line %d", error_part, Z_STRVAL_P(state->active_file), state->active_line);
			efree(error_part);
		} else {
			snprintf(error, error_length - 1, "Scanning error before '%s' in %s on line %d", state->start, Z_STRVAL_P(state->active_file), state->active_line);
		}
		error[error_length - 1] = '\0';
		ZVAL_STRING(*error_msg, error, 1);
	} else {
		error_length = sizeof(char) * (64 + Z_STRLEN_P(state->active_file));
		error = emalloc(error_length);
		snprintf(error, error_length - 1, "Scanning error near to EOF in %s", Z_STRVAL_P(state->active_file));
		ZVAL_STRING(*error_msg, error, 1);
		error[error_length - 1] = '\0';
	}
	efree(error);
}

/**
 * Receives the comment tokenizes and parses it
 */
int phannot_parse_annotations(zval *result, zval *comment, zval *file_path, zval *line TSRMLS_DC){

	zval *error_msg = NULL;

	ZVAL_NULL(result);

	if (Z_TYPE_P(comment) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_annotations_exception_ce, "Comment must be a string");
		return FAILURE;
	}

	if(phannot_internal_parse_annotations(&result, comment, file_path, line, &error_msg TSRMLS_CC) == FAILURE){
		PHALCON_THROW_EXCEPTION_STR(phalcon_annotations_exception_ce, Z_STRVAL_P(error_msg));
		return FAILURE;
	}

	return SUCCESS;
}

/**
 * Remove comment separators from a docblock
 */
void phannot_remove_comment_separators(zval *return_value, char *comment, int length, int *start_lines) {

	int start_mode = 1, j, i, open_parentheses;
	smart_str processed_str = {0};
	char ch;

	(*start_lines) = 0;

	for (i = 0; i < length; i++) {

		ch = comment[i];

		if (start_mode) {
			if (ch == ' ' || ch == '*' || ch == '/' || ch == '\t' || ch == 11) {
				continue;
			}
			start_mode = 0;
		}

		if (ch == '@') {

			smart_str_appendc(&processed_str, ch);
			i++;

			open_parentheses = 0;
			for (j = i; j < length; j++) {

				ch = comment[j];

				if (start_mode) {
					if (ch == ' ' || ch == '*' || ch == '/' || ch == '\t' || ch == 11) {
						continue;
					}
					start_mode = 0;
				}

				if (open_parentheses == 0) {

					if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
						smart_str_appendc(&processed_str, ch);
						continue;
					}

					if (ch == '(') {
						smart_str_appendc(&processed_str, ch);
						open_parentheses++;
						continue;
					}

				} else {

					smart_str_appendc(&processed_str, ch);

					if (ch == '(') {
						open_parentheses++;
					} else {
						if (ch == ')') {
							open_parentheses--;
						} else {
							if (ch == '\n') {
								(*start_lines)++;
								start_mode = 1;
							}
						}
					}

					if (open_parentheses > 0) {
						continue;
					}
				}

				i = j;
				smart_str_appendc(&processed_str, ' ');
				break;
			}
		}

		if (ch == '\n') {
			(*start_lines)++;
			start_mode = 1;
		}
	}

	smart_str_0(&processed_str);

	if (processed_str.len) {
		RETURN_STRINGL(processed_str.c, processed_str.len, 0);
	} else {
		RETURN_EMPTY_STRING();
	}
}

/**
 * Parses a comment returning an intermediate array representation
 */
int phannot_internal_parse_annotations(zval **result, zval *comment, zval *file_path, zval *line, zval **error_msg TSRMLS_DC) {

	char *error;
	phannot_scanner_state *state;
	phannot_scanner_token token;
	int scanner_status, status = SUCCESS, start_lines, error_length;
	phannot_parser_status *parser_status = NULL;
	void* phannot_parser;
	zval processed_comment;

	/**
	 * Check if the comment has content
	 */
	if (!Z_STRVAL_P(comment)) {
		ZVAL_BOOL(*result, 0);
		return FAILURE;
	}

	if (Z_STRLEN_P(comment) < 2) {
		ZVAL_BOOL(*result, 0);
		return SUCCESS;
	}

	/**
	 * Remove comment separators
	 */
	phannot_remove_comment_separators(&processed_comment, Z_STRVAL_P(comment), Z_STRLEN_P(comment), &start_lines);

	if (Z_STRLEN(processed_comment) < 2) {
		ZVAL_BOOL(*result, 0);
		efree(Z_STRVAL(processed_comment));
		return SUCCESS;
	}

	/**
	 * Start the reentrant parser
	 */
	phannot_parser = phannot_Alloc(phannot_wrapper_alloc);

	parser_status = emalloc(sizeof(phannot_parser_status));
	state = emalloc(sizeof(phannot_scanner_state));

	parser_status->status = PHANNOT_PARSING_OK;
	parser_status->scanner_state = state;
	parser_status->ret = NULL;
	parser_status->token = &token;
	parser_status->syntax_error = NULL;

	/**
	 * Initialize the scanner state
	 */
	state->active_token = 0;
	state->start = Z_STRVAL(processed_comment);
	state->start_length = 0;
	state->mode = PHANNOT_MODE_RAW;
	state->active_file = file_path;

	token.value = NULL;
	token.len = 0;

	/**
	 * Possible start line
	 */
	if (Z_TYPE_P(line) == IS_LONG) {
		state->active_line = Z_LVAL_P(line) - start_lines;
	} else {
		state->active_line = 1;
	}

	state->end = state->start;

	while(0 <= (scanner_status = phannot_get_token(state, &token))) {

		state->active_token = token.opcode;

		state->start_length = (Z_STRVAL(processed_comment) + Z_STRLEN(processed_comment) - state->start);

		switch (token.opcode) {

			case PHANNOT_T_IGNORE:
				break;

			case PHANNOT_T_AT:
				phannot_(phannot_parser, PHANNOT_AT, NULL, parser_status);
				break;
			case PHANNOT_T_COMMA:
				phannot_(phannot_parser, PHANNOT_COMMA, NULL, parser_status);
				break;
			case PHANNOT_T_EQUALS:
				phannot_(phannot_parser, PHANNOT_EQUALS, NULL, parser_status);
				break;
			case PHANNOT_T_COLON:
				phannot_(phannot_parser, PHANNOT_COLON, NULL, parser_status);
				break;

			case PHANNOT_T_PARENTHESES_OPEN:
				phannot_(phannot_parser, PHANNOT_PARENTHESES_OPEN, NULL, parser_status);
				break;
			case PHANNOT_T_PARENTHESES_CLOSE:
				phannot_(phannot_parser, PHANNOT_PARENTHESES_CLOSE, NULL, parser_status);
				break;

			case PHANNOT_T_BRACKET_OPEN:
				phannot_(phannot_parser, PHANNOT_BRACKET_OPEN, NULL, parser_status);
				break;
			case PHANNOT_T_BRACKET_CLOSE:
				phannot_(phannot_parser, PHANNOT_BRACKET_CLOSE, NULL, parser_status);
				break;

			case PHANNOT_T_SBRACKET_OPEN:
				phannot_(phannot_parser, PHANNOT_SBRACKET_OPEN, NULL, parser_status);
				break;
			case PHANNOT_T_SBRACKET_CLOSE:
				phannot_(phannot_parser, PHANNOT_SBRACKET_CLOSE, NULL, parser_status);
				break;

			case PHANNOT_T_NULL:
				phannot_(phannot_parser, PHANNOT_NULL, NULL, parser_status);
				break;
			case PHANNOT_T_TRUE:
				phannot_(phannot_parser, PHANNOT_TRUE, NULL, parser_status);
				break;
			case PHANNOT_T_FALSE:
				phannot_(phannot_parser, PHANNOT_FALSE, NULL, parser_status);
				break;

			case PHANNOT_T_INTEGER:
				phannot_parse_with_token(phannot_parser, PHANNOT_T_INTEGER, PHANNOT_INTEGER, &token, parser_status);
				break;
			case PHANNOT_T_DOUBLE:
				phannot_parse_with_token(phannot_parser, PHANNOT_T_DOUBLE, PHANNOT_DOUBLE, &token, parser_status);
				break;
			case PHANNOT_T_STRING:
				phannot_parse_with_token(phannot_parser, PHANNOT_T_STRING, PHANNOT_STRING, &token, parser_status);
				break;
			case PHANNOT_T_IDENTIFIER:
				phannot_parse_with_token(phannot_parser, PHANNOT_T_IDENTIFIER, PHANNOT_IDENTIFIER, &token, parser_status);
				break;
			/*case PHANNOT_T_ARBITRARY_TEXT:
				phannot_parse_with_token(phannot_parser, PHANNOT_T_ARBITRARY_TEXT, PHANNOT_ARBITRARY_TEXT, &token, parser_status);
				break;*/

			default:
				parser_status->status = PHANNOT_PARSING_FAILED;
				if (!*error_msg) {
					error_length = sizeof(char) * (48 + Z_STRLEN_P(state->active_file));
					error = emalloc(error_length);
					snprintf(error, error_length - 1, "Scanner: unknown opcode %d on in %s line %d", token.opcode, Z_STRVAL_P(state->active_file), state->active_line);
					error[error_length - 1] = '\0';
					PHALCON_INIT_VAR(*error_msg);
					ZVAL_STRING(*error_msg, error, 1);
					efree(error);
				}
				break;
		}

		if (parser_status->status != PHANNOT_PARSING_OK) {
			status = FAILURE;
			break;
		}

		state->end = state->start;
	}

	if (status != FAILURE) {
		switch (scanner_status) {
			case PHANNOT_SCANNER_RETCODE_ERR:
			case PHANNOT_SCANNER_RETCODE_IMPOSSIBLE:
				if (!*error_msg) {
					phannot_scanner_error_msg(parser_status, error_msg TSRMLS_CC);
				}
				status = FAILURE;
				break;
			default:
				phannot_(phannot_parser, 0, NULL, parser_status);
		}
	}

	state->active_token = 0;
	state->start = NULL;

	if (parser_status->status != PHANNOT_PARSING_OK) {
		status = FAILURE;
		if (parser_status->syntax_error) {
			if (!*error_msg) {
				PHALCON_INIT_VAR(*error_msg);
				ZVAL_STRING(*error_msg, parser_status->syntax_error, 1);
			}
			efree(parser_status->syntax_error);
		}
	}

	phannot_Free(phannot_parser, phannot_wrapper_free);

	if (status != FAILURE) {
		if (parser_status->status == PHANNOT_PARSING_OK) {
			if (parser_status->ret) {
				ZVAL_ZVAL(*result, parser_status->ret, 0, 0);
				ZVAL_NULL(parser_status->ret);
				zval_ptr_dtor(&parser_status->ret);
			} else {
				array_init(*result);
			}
		}
	}

	efree(Z_STRVAL(processed_comment));

	efree(parser_status);
	efree(state);

	return status;
}
