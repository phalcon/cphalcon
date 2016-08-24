
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework													  |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2016 Phalcon Team (http://www.phalconphp.com)	   |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled	   |
  | with this package in the file docs/LICENSE.txt.						   |
  |																	       |
  | If you did not receive a copy of the license and are unable to		   |
  | obtain it through the world-wide-web, please send an email			   |
  | to license@phalconphp.com so we can send you a copy immediately.	   |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>					   |
  |		  Eduar Carvajal <eduar@phalconphp.com>						       |
  +------------------------------------------------------------------------+
*/

const phql_token_names phql_tokens[] =
{
  { SL("INTEGER"),			   PHQL_T_INTEGER },
  { SL("DOUBLE"),			   PHQL_T_DOUBLE },
  { SL("STRING"),			   PHQL_T_STRING },
  { SL("IDENTIFIER"),		   PHQL_T_IDENTIFIER },
  { SL("HEXAINTEGER"),		   PHQL_T_HINTEGER },
  { SL("MINUS"),			   PHQL_T_MINUS },
  { SL("+"),				   PHQL_T_ADD },
  { SL("-"),				   PHQL_T_SUB },
  { SL("*"),				   PHQL_T_MUL },
  { SL("/"),				   PHQL_T_DIV },
  { SL("&"),				   PHQL_T_BITWISE_AND },
  { SL("|"),				   PHQL_T_BITWISE_OR },
  { SL("%%"),				   PHQL_T_MOD },
  { SL("AND"),				   PHQL_T_AND },
  { SL("OR"),				   PHQL_T_OR },
  { SL("LIKE"),				   PHQL_T_LIKE },
  { SL("ILIKE"),			   PHQL_T_ILIKE },
  { SL("DOT"),				   PHQL_T_DOT },
  { SL("COLON"),			   PHQL_T_COLON },
  { SL("COMMA"),			   PHQL_T_COMMA },
  { SL("EQUALS"),			   PHQL_T_EQUALS },
  { SL("NOT EQUALS"),		   PHQL_T_NOTEQUALS },
  { SL("NOT"),				   PHQL_T_NOT },
  { SL("<"),				   PHQL_T_LESS },
  { SL("<="),				   PHQL_T_LESSEQUAL },
  { SL(">"),				   PHQL_T_GREATER },
  { SL(">="),				   PHQL_T_GREATEREQUAL },
  { SL("("),				   PHQL_T_PARENTHESES_OPEN },
  { SL(")"),				   PHQL_T_PARENTHESES_CLOSE },
  { SL("NUMERIC PLACEHOLDER"), PHQL_T_NPLACEHOLDER },
  { SL("STRING PLACEHOLDER"),  PHQL_T_SPLACEHOLDER },
  { SL("UPDATE"),			   PHQL_T_UPDATE },
  { SL("SET"),				   PHQL_T_SET },
  { SL("WHERE"),			   PHQL_T_WHERE },
  { SL("DELETE"),			   PHQL_T_DELETE },
  { SL("FROM"),				   PHQL_T_FROM },
  { SL("AS"),				   PHQL_T_AS },
  { SL("INSERT"),			   PHQL_T_INSERT },
  { SL("INTO"),				   PHQL_T_INTO },
  { SL("VALUES"),			   PHQL_T_VALUES },
  { SL("SELECT"),			   PHQL_T_SELECT },
  { SL("ORDER"),			   PHQL_T_ORDER },
  { SL("BY"),			       PHQL_T_BY },
  { SL("LIMIT"),		       PHQL_T_LIMIT },
  { SL("OFFSET"),		       PHQL_T_OFFSET },
  { SL("GROUP"),		       PHQL_T_GROUP },
  { SL("HAVING"),		       PHQL_T_HAVING },
  { SL("IN"),			       PHQL_T_IN },
  { SL("ON"),			       PHQL_T_ON },
  { SL("INNER"),		       PHQL_T_INNER },
  { SL("JOIN"),		           PHQL_T_JOIN },
  { SL("LEFT"),		           PHQL_T_LEFT },
  { SL("RIGHT"),		       PHQL_T_RIGHT },
  { SL("IS"),			       PHQL_T_IS },
  { SL("NULL"),		           PHQL_T_NULL },
  { SL("NOT IN"),		       PHQL_T_NOTIN },
  { SL("CROSS"),		       PHQL_T_CROSS },
  { SL("OUTER"),		       PHQL_T_OUTER },
  { SL("FULL"),		           PHQL_T_FULL },
  { SL("ASC"),		           PHQL_T_ASC },
  { SL("DESC"),		           PHQL_T_DESC },
  { SL("BETWEEN"),	           PHQL_T_BETWEEN },
  { SL("DISTINCT"),	           PHQL_T_DISTINCT },
  { SL("AGAINST"),	           PHQL_T_AGAINST },
  { SL("CAST"),		           PHQL_T_CAST },
  { SL("CONVERT"),	           PHQL_T_CONVERT },
  { SL("USING"),		       PHQL_T_USING },
  { SL("ALL"),		           PHQL_T_ALL },
  { SL("EXISTS"),		       PHQL_T_EXISTS },
  { SL("CASE"),		           PHQL_T_CASE },
  { SL("WHEN"),		           PHQL_T_WHEN },
  { SL("THEN"),		           PHQL_T_THEN },
  { SL("ELSE"),		           PHQL_T_ELSE },
  { SL("END"),		           PHQL_T_END },
  { SL("FOR"),		           PHQL_T_FOR },
  { SL("WITH"),		           PHQL_T_WITH },
  { NULL, 0, 0 }
};

static void *phql_wrapper_alloc(size_t bytes)
{
	return emalloc(bytes);
}

static void phql_wrapper_free(void *pointer)
{
	efree(pointer);
}

static void phql_parse_with_token(void* phql_parser, int opcode, int parsercode, phql_scanner_token *token, phql_parser_status *parser_status)
{

	phql_parser_token *pToken;

	pToken = emalloc(sizeof(phql_parser_token));
	pToken->opcode = opcode;
	pToken->token = token->value;
	pToken->token_len = token->len;
	pToken->free_flag = 1;
	phql_(phql_parser, parsercode, pToken, parser_status);

	token->value = NULL;
	token->len = 0;
}

/**
 * Creates an error message when it's triggered by the scanner
 */
static void phql_scanner_error_msg(phql_parser_status *parser_status, zval **error_msg TSRMLS_DC)
{

	char *error = NULL, *error_part;
	unsigned int length;
	phql_scanner_state *state = parser_status->scanner_state;

#if PHP_VERSION_ID < 70000
	MAKE_STD_ZVAL(*error_msg);
#else
    ZVAL_UNDEF(*error_msg);
#endif

	if (state->start) {
		length = 64 + state->start_length + parser_status->phql_length;
		error = emalloc(sizeof(char) * length);
		if (state->start_length > 16) {
			error_part = estrndup(state->start, 16);
			snprintf(error, length, "Scanning error before '%s...' when parsing: %s (%d)", error_part, parser_status->phql, parser_status->phql_length);
			efree(error_part);
		} else {
			snprintf(error, length, "Scanning error before '%s' when parsing: %s (%d)", state->start, parser_status->phql, parser_status->phql_length);
		}
		error[length - 1] = '\0';
#if PHP_VERSION_ID < 70000
		ZVAL_STRING(*error_msg, error, 1);
#else
        ZVAL_STRING(*error_msg, error);
#endif
	} else {
#if PHP_VERSION_ID < 70000
		ZVAL_STRING(*error_msg, "Scanning error near to EOF", 1);
#else
		ZVAL_STRING(*error_msg, "Scanning error near to EOF");
#endif
	}

	if (error) {
		efree(error);
	}
}

/**
 * Executes the internal PHQL parser/tokenizer
 */
int phql_parse_phql(zval *result, zval *phql TSRMLS_DC)
{
#if PHP_VERSION_ID < 70000
	zval *error_msg = NULL;
#else
    zval err_msg, *error_msg = &err_msg;
    ZVAL_UNDEF(error_msg);
#endif

	ZVAL_NULL(result);

	if (phql_internal_parse_phql(&result, Z_STRVAL_P(phql), Z_STRLEN_P(phql), &error_msg TSRMLS_CC) == FAILURE) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, Z_STRVAL_P(error_msg));
		return FAILURE;
	}

	return SUCCESS;
}

/**
 * Executes a PHQL parser/tokenizer
 */
int phql_internal_parse_phql(zval **result, char *phql, unsigned int phql_length, zval **error_msg TSRMLS_DC)
{
	zend_phalcon_globals *phalcon_globals_ptr = ZEPHIR_VGLOBAL;
	phql_parser_status *parser_status = NULL;
	int scanner_status, status = SUCCESS, error_length, cache_level;
	phql_scanner_state *state;
	phql_scanner_token token;
	void* phql_parser;
	char *error;
    unsigned long phql_key = 0;
#if PHP_VERSION_ID < 70000
	zval **temp_ast;
#else
    zval *temp_ast;
#endif

	if (!phql) {
#if PHP_VERSION_ID < 70000
		MAKE_STD_ZVAL(*error_msg);
		ZVAL_STRING(*error_msg, "PHQL statement cannot be NULL", 1);
#else
		ZVAL_STRING(*error_msg, "PHQL statement cannot be NULL");
#endif
		return FAILURE;
	}

	cache_level = phalcon_globals_ptr->orm.cache_level;
	if (cache_level >= 0) {
		phql_key = zend_inline_hash_func(phql, phql_length + 1);
		if (phalcon_globals_ptr->orm.parser_cache != NULL) {
#if PHP_VERSION_ID < 70000
			if (zend_hash_index_find(phalcon_globals_ptr->orm.parser_cache, phql_key, (void**) &temp_ast) == SUCCESS) {
				ZVAL_ZVAL(*result, *temp_ast, 1, 0);
				Z_SET_REFCOUNT_P(*result, 1);
				return SUCCESS;
			}
#else
            if ((temp_ast = zend_hash_index_find(phalcon_globals_ptr->orm.parser_cache, phql_key)) != NULL) {
                ZVAL_ZVAL(*result, temp_ast, 1, 0);
                Z_TRY_ADDREF_P(*result);
                return SUCCESS;
            }
#endif
		}
	}

	phql_parser = phql_Alloc(phql_wrapper_alloc);

	parser_status = emalloc(sizeof(phql_parser_status));
	state = emalloc(sizeof(phql_scanner_state));

	parser_status->status = PHQL_PARSING_OK;
	parser_status->scanner_state = state;
#if PHP_VERSION_ID < 70000
	parser_status->ret = NULL;
#else
    ZVAL_UNDEF(&parser_status->ret);
#endif
	parser_status->syntax_error = NULL;
	parser_status->token = &token;
	parser_status->enable_literals = phalcon_globals_ptr->orm.enable_literals;
	parser_status->phql = phql;
	parser_status->phql_length = phql_length;

	state->active_token = 0;
	state->start = phql;
	state->start_length = 0;
	state->end = state->start;

	token.value = NULL;
	token.len = 0;

	while (0 <= (scanner_status = phql_get_token(state, &token))) {

		/* Calculate the 'start' length */
		state->start_length = (phql + phql_length - state->start);

		state->active_token = token.opcode;

		/* Parse the token found */
		switch (token.opcode) {

			case PHQL_T_IGNORE:
				break;

			case PHQL_T_ADD:
				phql_(phql_parser, PHQL_PLUS, NULL, parser_status);
				break;
			case PHQL_T_SUB:
				phql_(phql_parser, PHQL_MINUS, NULL, parser_status);
				break;
			case PHQL_T_MUL:
				phql_(phql_parser, PHQL_TIMES, NULL, parser_status);
				break;
			case PHQL_T_DIV:
				phql_(phql_parser, PHQL_DIVIDE, NULL, parser_status);
				break;
			case PHQL_T_MOD:
				phql_(phql_parser, PHQL_MOD, NULL, parser_status);
				break;
			case PHQL_T_AND:
				phql_(phql_parser, PHQL_AND, NULL, parser_status);
				break;
			case PHQL_T_OR:
				phql_(phql_parser, PHQL_OR, NULL, parser_status);
				break;
			case PHQL_T_EQUALS:
				phql_(phql_parser, PHQL_EQUALS, NULL, parser_status);
				break;
			case PHQL_T_NOTEQUALS:
				phql_(phql_parser, PHQL_NOTEQUALS, NULL, parser_status);
				break;
			case PHQL_T_LESS:
				phql_(phql_parser, PHQL_LESS, NULL, parser_status);
				break;
			case PHQL_T_GREATER:
				phql_(phql_parser, PHQL_GREATER, NULL, parser_status);
				break;
			case PHQL_T_GREATEREQUAL:
				phql_(phql_parser, PHQL_GREATEREQUAL, NULL, parser_status);
				break;
			case PHQL_T_LESSEQUAL:
				phql_(phql_parser, PHQL_LESSEQUAL, NULL, parser_status);
				break;

			case PHQL_T_IDENTIFIER:
				phql_parse_with_token(phql_parser, PHQL_T_IDENTIFIER, PHQL_IDENTIFIER, &token, parser_status);
				break;

			case PHQL_T_DOT:
				phql_(phql_parser, PHQL_DOT, NULL, parser_status);
				break;
			case PHQL_T_COMMA:
				phql_(phql_parser, PHQL_COMMA, NULL, parser_status);
				break;

			case PHQL_T_PARENTHESES_OPEN:
				phql_(phql_parser, PHQL_PARENTHESES_OPEN, NULL, parser_status);
				break;
			case PHQL_T_PARENTHESES_CLOSE:
				phql_(phql_parser, PHQL_PARENTHESES_CLOSE, NULL, parser_status);
				break;

			case PHQL_T_LIKE:
				phql_(phql_parser, PHQL_LIKE, NULL, parser_status);
				break;
			case PHQL_T_ILIKE:
				phql_(phql_parser, PHQL_ILIKE, NULL, parser_status);
				break;
			case PHQL_T_NOT:
				phql_(phql_parser, PHQL_NOT, NULL, parser_status);
				break;
			case PHQL_T_BITWISE_AND:
				phql_(phql_parser, PHQL_BITWISE_AND, NULL, parser_status);
				break;
			case PHQL_T_BITWISE_OR:
				phql_(phql_parser, PHQL_BITWISE_OR, NULL, parser_status);
				break;
			case PHQL_T_BITWISE_NOT:
				phql_(phql_parser, PHQL_BITWISE_NOT, NULL, parser_status);
				break;
			case PHQL_T_BITWISE_XOR:
				phql_(phql_parser, PHQL_BITWISE_XOR, NULL, parser_status);
				break;
			case PHQL_T_AGAINST:
				phql_(phql_parser, PHQL_AGAINST, NULL, parser_status);
				break;
			case PHQL_T_CASE:
				phql_(phql_parser, PHQL_CASE, NULL, parser_status);
				break;
			case PHQL_T_WHEN:
				phql_(phql_parser, PHQL_WHEN, NULL, parser_status);
				break;
			case PHQL_T_THEN:
				phql_(phql_parser, PHQL_THEN, NULL, parser_status);
				break;
			case PHQL_T_END:
				phql_(phql_parser, PHQL_END, NULL, parser_status);
				break;
			case PHQL_T_ELSE:
				phql_(phql_parser, PHQL_ELSE, NULL, parser_status);
				break;
			case PHQL_T_FOR:
				phql_(phql_parser, PHQL_FOR, NULL, parser_status);
				break;
            case PHQL_T_WITH:
    			phql_(phql_parser, PHQL_WITH, NULL, parser_status);
    			break;

			case PHQL_T_INTEGER:
				if (parser_status->enable_literals) {
					phql_parse_with_token(phql_parser, PHQL_T_INTEGER, PHQL_INTEGER, &token, parser_status);
				} else {
#if PHP_VERSION_ID < 70000
					MAKE_STD_ZVAL(*error_msg);
					ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements", 1);
#else
					ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements");
#endif
					parser_status->status = PHQL_PARSING_FAILED;
				}
				break;
			case PHQL_T_DOUBLE:
				if (parser_status->enable_literals) {
					phql_parse_with_token(phql_parser, PHQL_T_DOUBLE, PHQL_DOUBLE, &token, parser_status);
				} else {
#if PHP_VERSION_ID < 70000
					MAKE_STD_ZVAL(*error_msg);
					ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements", 1);
#else
                    ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements");
#endif
					parser_status->status = PHQL_PARSING_FAILED;
				}
				break;
			case PHQL_T_STRING:
				if (parser_status->enable_literals) {
					phql_parse_with_token(phql_parser, PHQL_T_STRING, PHQL_STRING, &token, parser_status);
				} else {
#if PHP_VERSION_ID < 70000
					MAKE_STD_ZVAL(*error_msg);
					ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements", 1);
#else
                    ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements");
#endif
					parser_status->status = PHQL_PARSING_FAILED;
				}
				break;
			case PHQL_T_TRUE:
				if (parser_status->enable_literals) {
					phql_(phql_parser, PHQL_TRUE, NULL, parser_status);
				} else {
#if PHP_VERSION_ID < 70000
					MAKE_STD_ZVAL(*error_msg);
					ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements", 1);
#else
                    ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements");
#endif
					parser_status->status = PHQL_PARSING_FAILED;
				}
				break;
			case PHQL_T_FALSE:
				if (parser_status->enable_literals) {
					phql_(phql_parser, PHQL_FALSE, NULL, parser_status);
				} else {
#if PHP_VERSION_ID < 70000
					MAKE_STD_ZVAL(*error_msg);
					ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements", 1);
#else
                    ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements");
#endif
					parser_status->status = PHQL_PARSING_FAILED;
				}
				break;
			case PHQL_T_HINTEGER:
				if (parser_status->enable_literals) {
					phql_parse_with_token(phql_parser, PHQL_T_HINTEGER, PHQL_HINTEGER, &token, parser_status);
				} else {
#if PHP_VERSION_ID < 70000
					MAKE_STD_ZVAL(*error_msg);
					ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements", 1);
#else
                    ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements");
#endif
					parser_status->status = PHQL_PARSING_FAILED;
				}
				break;

			case PHQL_T_NPLACEHOLDER:
				phql_parse_with_token(phql_parser, PHQL_T_NPLACEHOLDER, PHQL_NPLACEHOLDER, &token, parser_status);
				break;
			case PHQL_T_SPLACEHOLDER:
				phql_parse_with_token(phql_parser, PHQL_T_SPLACEHOLDER, PHQL_SPLACEHOLDER, &token, parser_status);
				break;
			case PHQL_T_BPLACEHOLDER:
				phql_parse_with_token(phql_parser, PHQL_T_BPLACEHOLDER, PHQL_BPLACEHOLDER, &token, parser_status);
				break;

			case PHQL_T_FROM:
				phql_(phql_parser, PHQL_FROM, NULL, parser_status);
				break;
			case PHQL_T_UPDATE:
				phql_(phql_parser, PHQL_UPDATE, NULL, parser_status);
				break;
			case PHQL_T_SET:
				phql_(phql_parser, PHQL_SET, NULL, parser_status);
				break;
			case PHQL_T_WHERE:
				phql_(phql_parser, PHQL_WHERE, NULL, parser_status);
				break;
			case PHQL_T_DELETE:
				phql_(phql_parser, PHQL_DELETE, NULL, parser_status);
				break;
			case PHQL_T_INSERT:
				phql_(phql_parser, PHQL_INSERT, NULL, parser_status);
				break;
			case PHQL_T_INTO:
				phql_(phql_parser, PHQL_INTO, NULL, parser_status);
				break;
			case PHQL_T_VALUES:
				phql_(phql_parser, PHQL_VALUES, NULL, parser_status);
				break;
			case PHQL_T_SELECT:
				phql_(phql_parser, PHQL_SELECT, NULL, parser_status);
				break;
			case PHQL_T_AS:
				phql_(phql_parser, PHQL_AS, NULL, parser_status);
				break;
			case PHQL_T_ORDER:
				phql_(phql_parser, PHQL_ORDER, NULL, parser_status);
				break;
			case PHQL_T_BY:
				phql_(phql_parser, PHQL_BY, NULL, parser_status);
				break;
			case PHQL_T_LIMIT:
				phql_(phql_parser, PHQL_LIMIT, NULL, parser_status);
				break;
			case PHQL_T_OFFSET:
				phql_(phql_parser, PHQL_OFFSET, NULL, parser_status);
				break;
			case PHQL_T_GROUP:
				phql_(phql_parser, PHQL_GROUP, NULL, parser_status);
				break;
			case PHQL_T_HAVING:
				phql_(phql_parser, PHQL_HAVING, NULL, parser_status);
				break;
			case PHQL_T_ASC:
				phql_(phql_parser, PHQL_ASC, NULL, parser_status);
				break;
			case PHQL_T_DESC:
				phql_(phql_parser, PHQL_DESC, NULL, parser_status);
				break;
			case PHQL_T_IN:
				phql_(phql_parser, PHQL_IN, NULL, parser_status);
				break;
			case PHQL_T_ON:
				phql_(phql_parser, PHQL_ON, NULL, parser_status);
				break;
			case PHQL_T_INNER:
				phql_(phql_parser, PHQL_INNER, NULL, parser_status);
				break;
			case PHQL_T_JOIN:
				phql_(phql_parser, PHQL_JOIN, NULL, parser_status);
				break;
			case PHQL_T_LEFT:
				phql_(phql_parser, PHQL_LEFT, NULL, parser_status);
				break;
			case PHQL_T_RIGHT:
				phql_(phql_parser, PHQL_RIGHT, NULL, parser_status);
				break;
			case PHQL_T_CROSS:
				phql_(phql_parser, PHQL_CROSS, NULL, parser_status);
				break;
			case PHQL_T_FULL:
				phql_(phql_parser, PHQL_FULL, NULL, parser_status);
				break;
			case PHQL_T_OUTER:
				phql_(phql_parser, PHQL_OUTER, NULL, parser_status);
				break;
			case PHQL_T_IS:
				phql_(phql_parser, PHQL_IS, NULL, parser_status);
				break;
			case PHQL_T_NULL:
				phql_(phql_parser, PHQL_NULL, NULL, parser_status);
				break;
			case PHQL_T_BETWEEN:
				phql_(phql_parser, PHQL_BETWEEN, NULL, parser_status);
				break;
			case PHQL_T_DISTINCT:
				phql_(phql_parser, PHQL_DISTINCT, NULL, parser_status);
				break;
			case PHQL_T_ALL:
				phql_(phql_parser, PHQL_ALL, NULL, parser_status);
				break;
			case PHQL_T_CAST:
				phql_(phql_parser, PHQL_CAST, NULL, parser_status);
				break;
			case PHQL_T_CONVERT:
				phql_(phql_parser, PHQL_CONVERT, NULL, parser_status);
				break;
			case PHQL_T_USING:
				phql_(phql_parser, PHQL_USING, NULL, parser_status);
				break;
			case PHQL_T_EXISTS:
				phql_(phql_parser, PHQL_EXISTS, NULL, parser_status);
				break;

			default:
				parser_status->status = PHQL_PARSING_FAILED;
				error_length = sizeof(char) * 32;
				error = emalloc(error_length);
				snprintf(error, error_length, "Scanner: Unknown opcode %d", token.opcode);
				error[error_length - 1] = '\0';
#if PHP_VERSION_ID < 70000
				MAKE_STD_ZVAL(*error_msg);
				ZVAL_STRING(*error_msg, error, 1);
#else
                ZVAL_STRING(*error_msg, error);
#endif
				efree(error);
				break;
		}

		if (parser_status->status != PHQL_PARSING_OK) {
			status = FAILURE;
			break;
		}

		state->end = state->start;
	}

	if (status != FAILURE) {
		switch (scanner_status) {

			case PHQL_SCANNER_RETCODE_ERR:
			case PHQL_SCANNER_RETCODE_IMPOSSIBLE:
#if PHP_VERSION_ID < 70000
				if (!*error_msg) {
					phql_scanner_error_msg(parser_status, error_msg TSRMLS_CC);
				}
#else
                if (Z_TYPE_P(*error_msg) == IS_UNDEF) {
                    phql_scanner_error_msg(parser_status, error_msg TSRMLS_CC);
                }
#endif
				status = FAILURE;
				break;

			default:
				phql_(phql_parser, 0, NULL, parser_status);
		}
	}

	state->active_token = 0;
	state->start = NULL;

	if (parser_status->status != PHQL_PARSING_OK) {
		status = FAILURE;
		if (parser_status->syntax_error) {
#if PHP_VERSION_ID < 70000
            if (!*error_msg) {
				MAKE_STD_ZVAL(*error_msg);
				ZVAL_STRING(*error_msg, parser_status->syntax_error, 1);
            }
#else
            if (Z_TYPE_P(*error_msg) == IS_UNDEF) {
                ZVAL_STRING(*error_msg, parser_status->syntax_error);
            }
#endif
			efree(parser_status->syntax_error);
		}
	}

	phql_Free(phql_parser, phql_wrapper_free);

	if (status != FAILURE) {
		if (parser_status->status == PHQL_PARSING_OK) {
#if PHP_VERSION_ID < 70000
			if (parser_status->ret) {
#else
			if (Z_TYPE_P(&parser_status->ret) == IS_ARRAY) {
#endif

				/**
				 * Set a unique id for the parsed ast
				 */
				if (phalcon_globals_ptr->orm.cache_level >= 1) {
#if PHP_VERSION_ID < 70000
					if (Z_TYPE_P(parser_status->ret) == IS_ARRAY) {
						add_assoc_long(parser_status->ret, "id", phalcon_globals_ptr->orm.unique_cache_id++);
					}
#else
                    if (Z_TYPE_P(&parser_status->ret) == IS_ARRAY) {
                        add_assoc_long(&parser_status->ret, "id", phalcon_globals_ptr->orm.unique_cache_id++);
                    }
#endif
				}

#if PHP_VERSION_ID < 70000
                ZVAL_ZVAL(*result, parser_status->ret, 0, 0);
                ZVAL_NULL(parser_status->ret);
				zval_ptr_dtor(&parser_status->ret);
#else
                ZVAL_ZVAL(*result, &parser_status->ret, 1, 1);
#endif

				/**
				 * Store the parsed definition in the cache
				 */
				if (cache_level >= 0) {

                    if (!phalcon_globals_ptr->orm.parser_cache) {
                        ALLOC_HASHTABLE(phalcon_globals_ptr->orm.parser_cache);
                        zend_hash_init(phalcon_globals_ptr->orm.parser_cache, 0, NULL, ZVAL_PTR_DTOR, 0);
                    }

#if PHP_VERSION_ID < 70000

					Z_ADDREF_PP(result);

					zend_hash_index_update(
						phalcon_globals_ptr->orm.parser_cache,
						phql_key,
						result,
						sizeof(zval *),
						NULL
					);
#else
                    Z_TRY_ADDREF_P(*result);

                    zend_hash_index_update(
                        phalcon_globals_ptr->orm.parser_cache,
                        phql_key,
                        *result
                    );
#endif
				}

			} else {
#if PHP_VERSION_ID < 70000
				efree(parser_status->ret);
#endif
			}
		}
	}

	efree(parser_status);
	efree(state);

	return status;
}
