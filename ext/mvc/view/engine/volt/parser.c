/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is include which follows the "include" declaration
** in the input file. */
#include <stdio.h>
/* #line 42 "parser.y" */


#include "php_phalcon.h"
#include "mvc/view/engine/volt/parser.h"
#include "mvc/view/engine/volt/scanner.h"
#include "mvc/view/engine/volt/volt.h"
#include "mvc/view/exception.h"

#include <ext/standard/php_smart_str.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"

static zval *phvolt_ret_literal_zval(int type, phvolt_parser_token *T, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", type);
	if (T) {
		add_assoc_stringl(ret, "value", T->token, T->token_len, 0);
		efree(T);
	}

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_if_statement(zval *expr, zval *true_statements, zval *false_statements, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_IF);
	add_assoc_zval(ret, "expr", expr);

	if (true_statements) {
		add_assoc_zval(ret, "true_statements", true_statements);
	}
	if (false_statements) {
		add_assoc_zval(ret, "false_statements", false_statements);
	}

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_elseif_statement(zval *expr, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_ELSEIF);
	add_assoc_zval(ret, "expr", expr);

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_elsefor_statement(phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_ELSEFOR);

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_for_statement(phvolt_parser_token *variable, phvolt_parser_token *key, zval *expr, zval *if_expr, zval *block_statements, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_FOR);

	add_assoc_stringl(ret, "variable", variable->token, variable->token_len, 0);
	efree(variable);

	if (key) {
		add_assoc_stringl(ret, "key", key->token, key->token_len, 0);
		efree(key);
	}

	add_assoc_zval(ret, "expr", expr);

	if (if_expr) {
		add_assoc_zval(ret, "if_expr", if_expr);
	}

	add_assoc_zval(ret, "block_statements", block_statements);

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_cache_statement(zval *expr, phvolt_parser_token *lifetime, zval *block_statements, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	add_assoc_long(ret, "type", PHVOLT_T_CACHE);
	add_assoc_zval(ret, "expr", expr);

	if (lifetime) {
		add_assoc_stringl(ret, "lifetime", lifetime->token, lifetime->token_len, 0);
		efree(lifetime);
	}
	add_assoc_zval(ret, "block_statements", block_statements);

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_set_statement(zval *assignments)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 2);
	add_assoc_long(ret, "type", PHVOLT_T_SET);

	add_assoc_zval(ret, "assignments", assignments);

	return ret;
}

static zval *phvolt_ret_set_assignment(phvolt_parser_token *variable, int operator, zval *expr, phvolt_scanner_state *state)
{

	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 5);

	add_assoc_stringl(ret, "variable", variable->token, variable->token_len, 0);
	efree(variable);

	add_assoc_long(ret, "op", operator);

	add_assoc_zval(ret, "expr", expr);

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_echo_statement(zval *expr, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 4);
	add_assoc_long(ret, "type", PHVOLT_T_ECHO);
	add_assoc_zval(ret, "expr", expr);

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_block_statement(phvolt_parser_token *name, zval *block_statements, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	add_assoc_long(ret, "type", PHVOLT_T_BLOCK);

	add_assoc_stringl(ret, "name", name->token, name->token_len, 0);
	efree(name);

	if (block_statements) {
		add_assoc_zval(ret, "block_statements", block_statements);
	}

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_macro_statement(phvolt_parser_token *macro_name, zval *parameters, zval *block_statements, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_MACRO);

	add_assoc_stringl(ret, "name", macro_name->token, macro_name->token_len, 0);
	efree(macro_name);

	if (parameters) {
		add_assoc_zval(ret, "parameters", parameters);
	}

	if (block_statements) {
		add_assoc_zval(ret, "block_statements", block_statements);
	}

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_macro_parameter(phvolt_parser_token *variable, zval *default_value, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 5);

	add_assoc_stringl(ret, "variable", variable->token, variable->token_len, 0);
	efree(variable);

	if (default_value) {
		add_assoc_zval(ret, "default", default_value);
	}

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_extends_statement(phvolt_parser_token *P, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 4);

	add_assoc_long(ret, "type", PHVOLT_T_EXTENDS);
	add_assoc_stringl(ret, "path", P->token, P->token_len, 0);
	efree(P);

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_include_statement(zval *path, zval *params, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 4);

	add_assoc_long(ret, "type", PHVOLT_T_INCLUDE);

	add_assoc_zval(ret, "path", path);
	if (params) {
		add_assoc_zval(ret, "params", params);
	}

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_do_statement(zval *expr, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 4);

	add_assoc_long(ret, "type", PHVOLT_T_DO);

	add_assoc_zval(ret, "expr", expr);

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_return_statement(zval *expr, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 4);

	add_assoc_long(ret, "type", PHVOLT_T_RETURN);

	add_assoc_zval(ret, "expr", expr);

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_autoescape_statement(int enable, zval *block_statements, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 5);

	add_assoc_long(ret, "type", PHVOLT_T_AUTOESCAPE);
	add_assoc_long(ret, "enable", enable);
	add_assoc_zval(ret, "block_statements", block_statements);

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_empty_statement(phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 3);
	add_assoc_long(ret, "type", PHVOLT_T_EMPTY_STATEMENT);

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_break_statement(phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 3);
	add_assoc_long(ret, "type", PHVOLT_T_BREAK);

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_continue_statement(phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 3);
	add_assoc_long(ret, "type", PHVOLT_T_CONTINUE);

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_zval_list(zval *list_left, zval *right_list)
{

	zval *ret;
	HashPosition pos;
	HashTable *list;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	if (list_left) {

		list = Z_ARRVAL_P(list_left);
		if (zend_hash_index_exists(list, 0)) {
			zend_hash_internal_pointer_reset_ex(list, &pos);
			for (;; zend_hash_move_forward_ex(list, &pos)) {

				zval ** item;

				if (zend_hash_get_current_data_ex(list, (void**) &item, &pos) == FAILURE) {
					break;
				}

				Z_ADDREF_PP(item);
				add_next_index_zval(ret, *item);

			}
			zval_ptr_dtor(&list_left);
		} else {
			add_next_index_zval(ret, list_left);
		}
	}

	add_next_index_zval(ret, right_list);

	return ret;
}

static zval *phvolt_ret_named_item(phvolt_parser_token *name, zval *expr, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_zval(ret, "expr", expr);
	if (name != NULL) {
		add_assoc_stringl(ret, "name", name->token, name->token_len, 0);
		efree(name);
	}

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_expr(int type, zval *left, zval *right, zval *ternary, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", type);

	if (ternary) {
		add_assoc_zval(ret, "ternary", ternary);
	}

	if (left) {
		add_assoc_zval(ret, "left", left);
	}

	if (right) {
		add_assoc_zval(ret, "right", right);
	}

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_slice(zval *left, zval *start, zval *end, phvolt_scanner_state *state)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_SLICE);
	add_assoc_zval(ret, "left", left);

	if (start != NULL) {
		add_assoc_zval(ret, "start", start);
	}

	if (end != NULL) {
		add_assoc_zval(ret, "end", end);
	}

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_func_call(zval *expr, zval *arguments, phvolt_scanner_state *state)
{

	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_FCALL);
	add_assoc_zval(ret, "name", expr);

	if (arguments) {
		add_assoc_zval(ret, "arguments", arguments);
	}

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}

static zval *phvolt_ret_macro_call_statement(zval *expr, zval *arguments, zval *caller, phvolt_scanner_state *state)
{

	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", PHVOLT_T_CALL);
	add_assoc_zval(ret, "name", expr);

	if (arguments) {
		add_assoc_zval(ret, "arguments", arguments);
	}

	if (caller) {
		add_assoc_zval(ret, "caller", caller);
	}

	Z_ADDREF_P(state->active_file);
	add_assoc_zval(ret, "file", state->active_file);
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}


/* #line 565 "parser.c" */
/* Next is all token values, in a form suitable for use by makeheaders.
** This section will be null unless lemon is run with the -m switch.
*/
/* 
** These constants (all generated automatically by the parser generator)
** specify the various kinds of tokens (terminals) that the parser
** understands. 
**
** Each symbol here is a terminal symbol in the grammar.
*/
/* Make sure the INTERFACE macro is defined.
*/
#ifndef INTERFACE
# define INTERFACE 1
#endif
/* The next thing included is series of defines which control
** various aspects of the generated parser.
**    YYCODETYPE         is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 terminals
**                       and nonterminals.  "int" is used otherwise.
**    YYNOCODE           is a number of type YYCODETYPE which corresponds
**                       to no legal terminal or nonterminal number.  This
**                       number is used to fill in empty slots of the hash 
**                       table.
**    YYFALLBACK         If defined, this indicates that one or more tokens
**                       have fall-back values which should be used if the
**                       original value of the token will not parse.
**    YYACTIONTYPE       is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 rules and
**                       states combined.  "int" is used otherwise.
**    phvolt_TOKENTYPE     is the data type used for minor tokens given 
**                       directly to the parser from the tokenizer.
**    YYMINORTYPE        is the data type used for all minor tokens.
**                       This is typically a union of many types, one of
**                       which is phvolt_TOKENTYPE.  The entry in the union
**                       for base tokens is called "yy0".
**    YYSTACKDEPTH       is the maximum depth of the parser's stack.
**    phvolt_ARG_SDECL     A static variable declaration for the %extra_argument
**    phvolt_ARG_PDECL     A parameter declaration for the %extra_argument
**    phvolt_ARG_STORE     Code to store %extra_argument into yypParser
**    phvolt_ARG_FETCH     Code to extract %extra_argument from yypParser
**    YYNSTATE           the combined number of states.
**    YYNRULE            the number of rules in the grammar
**    YYERRORSYMBOL      is the code number of the error symbol.  If not
**                       defined, then do no error processing.
*/
#define YYCODETYPE unsigned char
#define YYNOCODE 120
#define YYACTIONTYPE unsigned short int
#define phvolt_TOKENTYPE phvolt_parser_token*
typedef union {
  phvolt_TOKENTYPE yy0;
  zval* yy92;
  int yy239;
} YYMINORTYPE;
#define YYSTACKDEPTH 100
#define phvolt_ARG_SDECL phvolt_parser_status *status;
#define phvolt_ARG_PDECL ,phvolt_parser_status *status
#define phvolt_ARG_FETCH phvolt_parser_status *status = yypParser->status
#define phvolt_ARG_STORE yypParser->status = status
#define YYNSTATE 334
#define YYNRULE 145
#define YYERRORSYMBOL 83
#define YYERRSYMDT yy239
#define YY_NO_ACTION      (YYNSTATE+YYNRULE+2)
#define YY_ACCEPT_ACTION  (YYNSTATE+YYNRULE+1)
#define YY_ERROR_ACTION   (YYNSTATE+YYNRULE)

/* Next are that tables used to determine what action to take based on the
** current state and lookahead token.  These tables are used to implement
** functions that take a state number and lookahead value and return an
** action integer.  
**
** Suppose the action integer is N.  Then the action is determined as
** follows
**
**   0 <= N < YYNSTATE                  Shift N.  That is, push the lookahead
**                                      token onto the stack and goto state N.
**
**   YYNSTATE <= N < YYNSTATE+YYNRULE   Reduce by rule N-YYNSTATE.
**
**   N == YYNSTATE+YYNRULE              A syntax error has occurred.
**
**   N == YYNSTATE+YYNRULE+1            The parser accepts its input.
**
**   N == YYNSTATE+YYNRULE+2            No such action.  Denotes unused
**                                      slots in the yy_action[] table.
**
** The action table is constructed as a single large table named yy_action[].
** Given state S and lookahead X, the action is computed as
**
**      yy_action[ yy_shift_ofst[S] + X ]
**
** If the index value yy_shift_ofst[S]+X is out of range or if the value
** yy_lookahead[yy_shift_ofst[S]+X] is not equal to X or if yy_shift_ofst[S]
** is equal to YY_SHIFT_USE_DFLT, it means that the action is not in the table
** and that yy_default[S] should be used instead.  
**
** The formula above is for computing the action when the lookahead is
** a terminal symbol.  If the lookahead is a non-terminal (as occurs after
** a reduce action) then the yy_reduce_ofst[] array is used in place of
** the yy_shift_ofst[] array and YY_REDUCE_USE_DFLT is used in place of
** YY_SHIFT_USE_DFLT.
**
** The following are the tables generated in this section:
**
**  yy_action[]        A single table containing all actions.
**  yy_lookahead[]     A table containing the lookahead for each entry in
**                     yy_action.  Used to detect hash collisions.
**  yy_shift_ofst[]    For each state, the offset into yy_action for
**                     shifting terminals.
**  yy_reduce_ofst[]   For each state, the offset into yy_action for
**                     shifting non-terminals after a reduce.
**  yy_default[]       Default action for each state.
*/
static YYACTIONTYPE yy_action[] = {
 /*     0 */    82,   92,   23,   60,   52,   54,   64,   62,   66,   72,
 /*    10 */    74,   76,   78,   68,   70,   48,   46,   50,   43,   40,
 /*    20 */    56,   89,   58,   84,   87,   88,   96,   80,  300,  174,
 /*    30 */    82,   92,  108,   60,   52,   54,   64,   62,   66,   72,
 /*    40 */    74,   76,   78,   68,   70,   48,   46,   50,   43,   40,
 /*    50 */    56,   89,   58,   84,   87,   88,   96,   80,  256,  225,
 /*    60 */    48,   46,   50,   43,   40,   56,   89,   58,   84,   87,
 /*    70 */    88,   96,   80,  259,  307,  172,  267,  180,  195,  334,
 /*    80 */    82,   92,   30,   60,   52,   54,   64,   62,   66,   72,
 /*    90 */    74,   76,   78,   68,   70,   48,   46,   50,   43,   40,
 /*   100 */    56,   89,   58,   84,   87,   88,   96,   80,   32,  235,
 /*   110 */    82,   92,  112,   60,   52,   54,   64,   62,   66,   72,
 /*   120 */    74,   76,   78,   68,   70,   48,   46,   50,   43,   40,
 /*   130 */    56,   89,   58,   84,   87,   88,   96,   80,  316,  311,
 /*   140 */    82,   92,  236,   60,   52,   54,   64,   62,   66,   72,
 /*   150 */    74,   76,   78,   68,   70,   48,   46,   50,   43,   40,
 /*   160 */    56,   89,   58,   84,   87,   88,   96,   80,  182,   26,
 /*   170 */    82,   92,   36,   60,   52,   54,   64,   62,   66,   72,
 /*   180 */    74,   76,   78,   68,   70,   48,   46,   50,   43,   40,
 /*   190 */    56,   89,   58,   84,   87,   88,   96,   80,  181,   39,
 /*   200 */    82,   92,  108,   60,   52,   54,   64,   62,   66,   72,
 /*   210 */    74,   76,   78,   68,   70,   48,   46,   50,   43,   40,
 /*   220 */    56,   89,   58,   84,   87,   88,   96,   80,   82,   92,
 /*   230 */    94,   60,   52,   54,   64,   62,   66,   72,   74,   76,
 /*   240 */    78,   68,   70,   48,   46,   50,   43,   40,   56,   89,
 /*   250 */    58,   84,   87,   88,   96,   80,   27,  260,    4,    5,
 /*   260 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   270 */    16,   17,   18,   19,   20,   21,   22,   91,  281,  299,
 /*   280 */   107,   82,   92,  128,   60,   52,   54,   64,   62,   66,
 /*   290 */    72,   74,   76,   78,   68,   70,   48,   46,   50,   43,
 /*   300 */    40,   56,   89,   58,   84,   87,   88,   96,   80,   43,
 /*   310 */    40,   56,   89,   58,   84,   87,   88,   96,   80,  293,
 /*   320 */   294,  295,  296,  297,  298,  102,  246,  261,  127,   82,
 /*   330 */    92,   85,   60,   52,   54,   64,   62,   66,   72,   74,
 /*   340 */    76,   78,   68,   70,   48,   46,   50,   43,   40,   56,
 /*   350 */    89,   58,   84,   87,   88,   96,   80,  115,  238,   82,
 /*   360 */    92,  136,   60,   52,   54,   64,   62,   66,   72,   74,
 /*   370 */    76,   78,   68,   70,   48,   46,   50,   43,   40,   56,
 /*   380 */    89,   58,   84,   87,   88,   96,   80,  131,  241,   82,
 /*   390 */    92,  137,   60,   52,   54,   64,   62,   66,   72,   74,
 /*   400 */    76,   78,   68,   70,   48,   46,   50,   43,   40,   56,
 /*   410 */    89,   58,   84,   87,   88,   96,   80,  459,  244,   82,
 /*   420 */    92,  460,   60,   52,   54,   64,   62,   66,   72,   74,
 /*   430 */    76,   78,   68,   70,   48,   46,   50,   43,   40,   56,
 /*   440 */    89,   58,   84,   87,   88,   96,   80,   92,  143,   60,
 /*   450 */    52,   54,   64,   62,   66,   72,   74,   76,   78,   68,
 /*   460 */    70,   48,   46,   50,   43,   40,   56,   89,   58,   84,
 /*   470 */    87,   88,   96,   80,  258,  141,  144,  459,   82,   92,
 /*   480 */   169,   60,   52,   54,   64,   62,   66,   72,   74,   76,
 /*   490 */    78,   68,   70,   48,   46,   50,   43,   40,   56,   89,
 /*   500 */    58,   84,   87,   88,   96,   80,  460,  302,   82,   92,
 /*   510 */   178,   60,   52,   54,   64,   62,   66,   72,   74,   76,
 /*   520 */    78,   68,   70,   48,   46,   50,   43,   40,   56,   89,
 /*   530 */    58,   84,   87,   88,   96,   80,  171,  318,   82,   92,
 /*   540 */   184,   60,   52,   54,   64,   62,   66,   72,   74,   76,
 /*   550 */    78,   68,   70,   48,   46,   50,   43,   40,   56,   89,
 /*   560 */    58,   84,   87,   88,   96,   80,   82,   92,  183,   60,
 /*   570 */    52,   54,   64,   62,   66,   72,   74,   76,   78,   68,
 /*   580 */    70,   48,   46,   50,   43,   40,   56,   89,   58,   84,
 /*   590 */    87,   88,  207,   80,   60,   52,   54,   64,   62,   66,
 /*   600 */    72,   74,   76,   78,   68,   70,   48,   46,   50,   43,
 /*   610 */    40,   56,   89,   58,   84,   87,   88,   96,   80,   52,
 /*   620 */    54,   64,   62,   66,   72,   74,   76,   78,   68,   70,
 /*   630 */    48,   46,   50,   43,   40,   56,   89,   58,   84,   87,
 /*   640 */    88,   96,   80,  480,    1,    2,  260,    4,    5,    6,
 /*   650 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   660 */    17,   18,   19,   20,   21,   22,   64,   62,   66,   72,
 /*   670 */    74,   76,   78,   68,   70,   48,   46,   50,   43,   40,
 /*   680 */    56,   89,   58,   84,   87,   88,   96,   80,   33,  260,
 /*   690 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   700 */    14,   15,   16,   17,   18,   19,   20,   21,   22,  175,
 /*   710 */   260,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   720 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   730 */   201,  260,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   740 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   750 */    22,  211,  260,    4,    5,    6,    7,    8,    9,   10,
 /*   760 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   770 */    21,   22,  219,  260,    4,    5,    6,    7,    8,    9,
 /*   780 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   790 */    20,   21,   22,  226,  260,    4,    5,    6,    7,    8,
 /*   800 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   810 */    19,   20,   21,   22,  248,  260,    4,    5,    6,    7,
 /*   820 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   830 */    18,   19,   20,   21,   22,  263,  260,    4,    5,    6,
 /*   840 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   850 */    17,   18,   19,   20,   21,   22,  269,  260,    4,    5,
 /*   860 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   870 */    16,   17,   18,   19,   20,   21,   22,  284,  260,    4,
 /*   880 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   890 */    15,   16,   17,   18,   19,   20,   21,   22,  303,  260,
 /*   900 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   910 */    14,   15,   16,   17,   18,   19,   20,   21,   22,  312,
 /*   920 */   260,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   930 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   940 */   319,  260,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   950 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   960 */    22,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   970 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   980 */    22,   44,   41,  197,  103,   90,  147,   25,  198,  100,
 /*   990 */   217,   44,   41,  140,  103,  117,   98,  117,  118,  100,
 /*  1000 */    89,   58,   84,   87,   88,   96,   80,  326,  118,  119,
 /*  1010 */   120,  121,  122,  123,  124,  200,  204,  128,  210,  119,
 /*  1020 */   120,  121,  122,  123,  124,   84,   87,   88,   96,   80,
 /*  1030 */    28,  231,   38,  155,  156,  157,  158,  159,  160,  161,
 /*  1040 */   167,  109,  117,  148,  149,  150,  151,  152,  153,  154,
 /*  1050 */   117,  109,   24,  215,   29,   31,   37,  168,  170,  335,
 /*  1060 */    23,  179,  209,  256,  104,   42,  139,  196,  185,  187,
 /*  1070 */   189,  191,  193,  125,  117,  117,  205,  138,  259,  288,
 /*  1080 */   216,  290,  223,  214,  230,  233,  256,  239,  242,  245,
 /*  1090 */   199,  252,  254,   24,  215,  327,  329,   37,  168,  170,
 /*  1100 */    97,  259,  179,   97,  218,  222,  126,  278,  196,   97,
 /*  1110 */   117,  134,  229,  117,  129,  208,  256,  205,  232,  117,
 /*  1120 */   134,  216,  323,  223,  282,  230,  233,  247,  239,  242,
 /*  1130 */   245,  259,  252,  254,   24,  215,   35,  104,   37,  168,
 /*  1140 */   170,  104,   34,  179,  106,  139,  113,  117,  111,  196,
 /*  1150 */   113,  117,  279,  176,  251,  166,  138,  290,  205,  253,
 /*  1160 */   255,  262,  216,  266,  223,  117,  230,  233,  268,  239,
 /*  1170 */   242,  245,  202,  252,  254,   24,  215,  272,  256,   37,
 /*  1180 */   168,  170,   45,  177,  179,   99,   47,  142,  275,  212,
 /*  1190 */   196,  277,  117,  259,   49,  117,  117,  280,  256,  205,
 /*  1200 */   283,  287,  289,  216,  117,  223,  292,  230,  233,  256,
 /*  1210 */   239,  242,  245,  259,  252,  254,   24,  215,  291,   51,
 /*  1220 */    37,  168,  170,  306,  259,  179,  309,   53,  256,  117,
 /*  1230 */   273,  196,  301,  203,  308,  220,  315,  117,  322,  325,
 /*  1240 */   205,  328,  117,  259,  216,  256,  223,  330,  230,  233,
 /*  1250 */   331,  239,  242,  245,  227,  252,  254,   24,  215,  333,
 /*  1260 */   259,   37,  168,  170,   55,  249,  179,  266,  332,  266,
 /*  1270 */    57,  266,  196,   59,  117,  266,  266,  266,  266,  266,
 /*  1280 */   117,  205,  213,  117,  266,  216,  256,  223,  266,  230,
 /*  1290 */   233,  256,  239,  242,  245,  264,  252,  254,   24,  215,
 /*  1300 */   266,  259,   37,  168,  170,  266,  259,  179,  266,  266,
 /*  1310 */   256,  266,  270,  196,  266,  266,  266,  266,  266,   61,
 /*  1320 */   266,  256,  205,  266,  266,  259,  216,  221,  223,  117,
 /*  1330 */   230,  233,  285,  239,  242,  245,  259,  252,  254,   24,
 /*  1340 */   215,  266,  266,   37,  168,  170,  266,  266,  179,  266,
 /*  1350 */   310,  256,   63,  304,  196,  266,  266,  266,  266,  266,
 /*  1360 */   117,  266,  117,  205,  266,  266,  259,  216,  256,  223,
 /*  1370 */   228,  230,  233,  313,  239,  242,  245,  320,  252,  254,
 /*  1380 */    24,  215,   65,  259,   37,  168,  170,  266,  256,  179,
 /*  1390 */    67,   69,  117,  266,  266,  196,  266,   71,  266,  266,
 /*  1400 */   117,  117,  266,  259,  205,  266,  266,  117,  216,  256,
 /*  1410 */   223,  266,  230,  233,  266,  239,  242,  245,  250,  252,
 /*  1420 */   254,   24,  215,  266,  259,   37,  168,  170,  266,  256,
 /*  1430 */   179,  266,  266,  256,  266,  266,  196,   73,  266,  266,
 /*  1440 */    75,  266,   77,  266,  259,  205,  266,  117,  259,  216,
 /*  1450 */   117,  223,  117,  230,  233,  266,  239,  242,  245,  265,
 /*  1460 */   252,  254,   24,  215,  266,  266,   37,  168,  170,  266,
 /*  1470 */    79,  179,  266,  266,   81,   83,  266,  196,   86,  266,
 /*  1480 */   117,   93,  266,  266,  117,  117,  205,  266,  117,  266,
 /*  1490 */   216,  117,  223,  271,  230,  233,   95,  239,  242,  245,
 /*  1500 */    99,  252,  254,   24,  215,  101,  117,   37,  168,  170,
 /*  1510 */   117,  116,  179,  266,  266,  117,  132,  266,  196,  266,
 /*  1520 */   163,  117,  266,  266,  165,  266,  117,  205,  266,  266,
 /*  1530 */   117,  216,  274,  223,  117,  230,  233,  173,  239,  242,
 /*  1540 */   245,  186,  252,  254,   24,  215,  266,  117,   37,  168,
 /*  1550 */   170,  117,  188,  179,  266,  190,  192,  194,  266,  196,
 /*  1560 */   206,  286,  117,  266,  266,  117,  117,  117,  205,  266,
 /*  1570 */   117,  266,  216,  266,  223,  266,  230,  233,  224,  239,
 /*  1580 */   242,  245,  234,  252,  254,   24,  215,  266,  117,   37,
 /*  1590 */   168,  170,  117,  305,  179,  266,  237,  266,  240,  266,
 /*  1600 */   196,  243,  257,  266,  317,  266,  117,  266,  117,  205,
 /*  1610 */   266,  117,  117,  216,  117,  223,  266,  230,  233,  266,
 /*  1620 */   239,  242,  245,  266,  252,  254,   24,  215,  266,  266,
 /*  1630 */    37,  168,  170,  266,  314,  179,  266,  266,  266,  266,
 /*  1640 */   266,  196,  266,  266,  266,  266,  266,  266,  266,  266,
 /*  1650 */   205,  266,  266,  266,  216,  266,  223,  266,  230,  233,
 /*  1660 */   266,  239,  242,  245,  266,  252,  254,   24,  215,  266,
 /*  1670 */   266,   37,  168,  170,  266,  321,  179,  266,  266,  266,
 /*  1680 */   266,  266,  196,  266,  266,  266,  266,  266,  266,  266,
 /*  1690 */   266,  205,  266,  266,  266,  216,  266,  223,  266,  230,
 /*  1700 */   233,  266,  239,  242,  245,  266,  252,  254,   24,  215,
 /*  1710 */   324,  266,   37,  168,  170,  266,  266,  179,  266,  266,
 /*  1720 */   266,  266,  266,  196,  266,  266,  266,  266,  266,  266,
 /*  1730 */   266,  266,  205,  266,  266,  266,  216,  266,  223,  266,
 /*  1740 */   230,  233,  266,  239,  242,  245,  266,  252,  254,   24,
 /*  1750 */   215,  266,  266,   37,  168,  170,  266,  266,  179,  266,
 /*  1760 */   266,  266,  266,  266,  196,  266,  266,  266,  266,  266,
 /*  1770 */   266,  266,  266,  205,  266,  266,  266,  216,  266,  223,
 /*  1780 */   266,  230,  233,  266,  239,  242,  245,  266,  252,  254,
 /*  1790 */   266,  266,  266,  164,  266,   44,   41,  266,  103,  266,
 /*  1800 */    98,  266,  266,  100,  266,  266,  266,  266,  266,  266,
 /*  1810 */   266,  266,  118,  266,  266,  266,  266,  266,  266,  266,
 /*  1820 */   266,  266,  266,  119,  120,  121,  122,  123,  124,  266,
 /*  1830 */   266,  162,  266,  266,   44,   41,  266,  103,  266,   98,
 /*  1840 */   266,  266,  100,  266,  266,  266,  266,  266,  266,  266,
 /*  1850 */   266,  118,  266,  266,  266,  109,  266,  135,  266,  266,
 /*  1860 */   266,  266,  119,  120,  121,  122,  123,  124,  266,  266,
 /*  1870 */   266,  266,  266,   44,   41,  266,  103,  266,   98,  266,
 /*  1880 */   266,  100,  266,  266,  266,  266,  266,  266,  266,  266,
 /*  1890 */   146,  266,  266,  266,  109,  266,  266,  266,  266,  266,
 /*  1900 */   266,  145,  120,  121,  122,  123,  124,  266,  266,  266,
 /*  1910 */   266,  266,   44,   41,  266,  103,  266,   98,  266,  266,
 /*  1920 */   100,  266,  266,  266,  266,  266,  266,  266,  266,  118,
 /*  1930 */   266,  266,  266,  109,  266,  266,  266,  266,  133,  266,
 /*  1940 */   119,  130,  121,  122,  123,  124,  266,  266,  266,  266,
 /*  1950 */   266,   44,   41,  266,  103,  266,   98,  266,  266,  100,
 /*  1960 */   266,  266,  266,  266,  266,  266,  266,  266,  118,  266,
 /*  1970 */   266,  266,  109,  266,  266,  266,  266,  266,  266,  119,
 /*  1980 */   114,  121,  122,  123,  124,  266,  266,  266,  266,  266,
 /*  1990 */    44,   41,  266,  103,  266,   98,  266,  266,  100,  266,
 /*  2000 */   266,  266,  266,  266,  266,  266,  266,  118,  266,  266,
 /*  2010 */   105,  109,  266,  266,  266,  266,  266,  266,  119,  114,
 /*  2020 */   121,  122,  123,  124,  266,  266,  266,  266,  266,   44,
 /*  2030 */    41,  266,  103,  266,   98,  266,  266,  100,  266,  266,
 /*  2040 */   266,  266,  266,  266,  266,  266,  118,  266,  266,  266,
 /*  2050 */   109,  110,  266,  266,  266,  276,  266,  119,  130,  121,
 /*  2060 */   122,  123,  124,  266,  266,  266,  266,  266,   44,   41,
 /*  2070 */   266,  103,  266,   98,  266,  266,  100,  266,  266,  266,
 /*  2080 */   266,  266,  266,  266,  266,  118,  266,  266,  266,  109,
 /*  2090 */   266,  266,  266,  266,  266,  266,  119,  120,  121,  122,
 /*  2100 */   123,  124,  266,  266,  266,  266,  266,   44,   41,  266,
 /*  2110 */   103,  266,   98,  266,  266,  100,  266,  266,  266,  266,
 /*  2120 */   266,  266,  266,  266,  118,  266,  266,  266,  109,  266,
 /*  2130 */   266,  266,  266,  266,  266,  119,  114,  121,  122,  123,
 /*  2140 */   124,  266,  266,  266,  266,  266,   44,   41,  266,  103,
 /*  2150 */   266,   98,  266,  266,  100,  266,  266,  266,  266,  266,
 /*  2160 */   266,  266,  266,  118,  266,  266,  266,  109,  266,  266,
 /*  2170 */   266,  266,  266,  266,  119,  130,  121,  122,  123,  124,
 /*  2180 */   266,  266,  266,  266,  266,  266,  266,  266,  266,  266,
 /*  2190 */   266,  266,  266,  266,  266,  266,  266,  266,  266,  266,
 /*  2200 */   266,  266,  266,  266,  266,  266,  109,
};
static YYCODETYPE yy_lookahead[] = {
 /*     0 */     3,    4,    1,    6,    7,    8,    9,   10,   11,   12,
 /*    10 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*    20 */    23,   24,   25,   26,   27,   28,   29,   30,   31,   32,
 /*    30 */     3,    4,    2,    6,    7,    8,    9,   10,   11,   12,
 /*    40 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*    50 */    23,   24,   25,   26,   27,   28,   29,   30,   57,   32,
 /*    60 */    18,   19,   20,   21,   22,   23,   24,   25,   26,   27,
 /*    70 */    28,   29,   30,   72,    2,    3,   49,  108,  109,    0,
 /*    80 */     3,    4,   32,    6,    7,    8,    9,   10,   11,   12,
 /*    90 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   100 */    23,   24,   25,   26,   27,   28,   29,   30,   32,   32,
 /*   110 */     3,    4,   82,    6,    7,    8,    9,   10,   11,   12,
 /*   120 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   130 */    23,   24,   25,   26,   27,   28,   29,   30,   31,   32,
 /*   140 */     3,    4,   65,    6,    7,    8,    9,   10,   11,   12,
 /*   150 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   160 */    23,   24,   25,   26,   27,   28,   29,   30,    2,   32,
 /*   170 */     3,    4,   32,    6,    7,    8,    9,   10,   11,   12,
 /*   180 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   190 */    23,   24,   25,   26,   27,   28,   29,   30,   32,   32,
 /*   200 */     3,    4,    2,    6,    7,    8,    9,   10,   11,   12,
 /*   210 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   220 */    23,   24,   25,   26,   27,   28,   29,   30,    3,    4,
 /*   230 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   240 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   24,
 /*   250 */    25,   26,   27,   28,   29,   30,   86,   87,   88,   89,
 /*   260 */    90,   91,   92,   93,   94,   95,   96,   97,   98,   99,
 /*   270 */   100,  101,  102,  103,  104,  105,  106,   80,  110,  111,
 /*   280 */    80,    3,    4,    2,    6,    7,    8,    9,   10,   11,
 /*   290 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   300 */    22,   23,   24,   25,   26,   27,   28,   29,   30,   21,
 /*   310 */    22,   23,   24,   25,   26,   27,   28,   29,   30,   49,
 /*   320 */    50,   51,   52,   53,   54,   47,   53,   54,   47,    3,
 /*   330 */     4,    3,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   340 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   350 */    24,   25,   26,   27,   28,   29,   30,    5,   32,    3,
 /*   360 */     4,  115,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   370 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   380 */    24,   25,   26,   27,   28,   29,   30,    5,   32,    3,
 /*   390 */     4,   80,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   400 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   410 */    24,   25,   26,   27,   28,   29,   30,   80,   32,    3,
 /*   420 */     4,   80,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   430 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   440 */    24,   25,   26,   27,   28,   29,   30,    4,  115,    6,
 /*   450 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   460 */    17,   18,   19,   20,   21,   22,   23,   24,   25,   26,
 /*   470 */    27,   28,   29,   30,   58,    5,   80,    5,    3,    4,
 /*   480 */    32,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   490 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   24,
 /*   500 */    25,   26,   27,   28,   29,   30,    5,   32,    3,    4,
 /*   510 */    32,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   520 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   24,
 /*   530 */    25,   26,   27,   28,   29,   30,   38,   32,    3,    4,
 /*   540 */    38,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   550 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   24,
 /*   560 */    25,   26,   27,   28,   29,   30,    3,    4,  109,    6,
 /*   570 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   580 */    17,   18,   19,   20,   21,   22,   23,   24,   25,   26,
 /*   590 */    27,   28,   29,   30,    6,    7,    8,    9,   10,   11,
 /*   600 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   610 */    22,   23,   24,   25,   26,   27,   28,   29,   30,    7,
 /*   620 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   630 */    18,   19,   20,   21,   22,   23,   24,   25,   26,   27,
 /*   640 */    28,   29,   30,   84,   85,   86,   87,   88,   89,   90,
 /*   650 */    91,   92,   93,   94,   95,   96,   97,   98,   99,  100,
 /*   660 */   101,  102,  103,  104,  105,  106,    9,   10,   11,   12,
 /*   670 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   680 */    23,   24,   25,   26,   27,   28,   29,   30,   86,   87,
 /*   690 */    88,   89,   90,   91,   92,   93,   94,   95,   96,   97,
 /*   700 */    98,   99,  100,  101,  102,  103,  104,  105,  106,   86,
 /*   710 */    87,   88,   89,   90,   91,   92,   93,   94,   95,   96,
 /*   720 */    97,   98,   99,  100,  101,  102,  103,  104,  105,  106,
 /*   730 */    86,   87,   88,   89,   90,   91,   92,   93,   94,   95,
 /*   740 */    96,   97,   98,   99,  100,  101,  102,  103,  104,  105,
 /*   750 */   106,   86,   87,   88,   89,   90,   91,   92,   93,   94,
 /*   760 */    95,   96,   97,   98,   99,  100,  101,  102,  103,  104,
 /*   770 */   105,  106,   86,   87,   88,   89,   90,   91,   92,   93,
 /*   780 */    94,   95,   96,   97,   98,   99,  100,  101,  102,  103,
 /*   790 */   104,  105,  106,   86,   87,   88,   89,   90,   91,   92,
 /*   800 */    93,   94,   95,   96,   97,   98,   99,  100,  101,  102,
 /*   810 */   103,  104,  105,  106,   86,   87,   88,   89,   90,   91,
 /*   820 */    92,   93,   94,   95,   96,   97,   98,   99,  100,  101,
 /*   830 */   102,  103,  104,  105,  106,   86,   87,   88,   89,   90,
 /*   840 */    91,   92,   93,   94,   95,   96,   97,   98,   99,  100,
 /*   850 */   101,  102,  103,  104,  105,  106,   86,   87,   88,   89,
 /*   860 */    90,   91,   92,   93,   94,   95,   96,   97,   98,   99,
 /*   870 */   100,  101,  102,  103,  104,  105,  106,   86,   87,   88,
 /*   880 */    89,   90,   91,   92,   93,   94,   95,   96,   97,   98,
 /*   890 */    99,  100,  101,  102,  103,  104,  105,  106,   86,   87,
 /*   900 */    88,   89,   90,   91,   92,   93,   94,   95,   96,   97,
 /*   910 */    98,   99,  100,  101,  102,  103,  104,  105,  106,   86,
 /*   920 */    87,   88,   89,   90,   91,   92,   93,   94,   95,   96,
 /*   930 */    97,   98,   99,  100,  101,  102,  103,  104,  105,  106,
 /*   940 */    86,   87,   88,   89,   90,   91,   92,   93,   94,   95,
 /*   950 */    96,   97,   98,   99,  100,  101,  102,  103,  104,  105,
 /*   960 */   106,   87,   88,   89,   90,   91,   92,   93,   94,   95,
 /*   970 */    96,   97,   98,   99,  100,  101,  102,  103,  104,  105,
 /*   980 */   106,   21,   22,   38,   24,  107,   26,  107,   29,   29,
 /*   990 */    38,   21,   22,  115,   24,  117,   26,  117,   38,   29,
 /*  1000 */    24,   25,   26,   27,   28,   29,   30,    1,   38,   49,
 /*  1010 */    50,   51,   52,   53,   54,   32,   32,    2,   32,   49,
 /*  1020 */    50,   51,   52,   53,   54,   26,   27,   28,   29,   30,
 /*  1030 */     1,   50,  107,   73,   74,   75,   76,   77,   78,   79,
 /*  1040 */   107,   81,  117,   73,   74,   75,   76,   77,   78,   79,
 /*  1050 */   117,   81,   31,   32,   33,   34,   35,   36,   37,    0,
 /*  1060 */     1,   40,   47,   57,  107,  107,   38,   46,   41,   42,
 /*  1070 */    43,   44,   45,  116,  117,  117,   55,   49,   72,    2,
 /*  1080 */    59,   38,   61,   32,   63,   64,   57,   66,   67,   68,
 /*  1090 */    47,   70,   71,   31,   32,   33,   34,   35,   36,   37,
 /*  1100 */   107,   72,   40,  107,   32,   32,  113,    1,   46,  107,
 /*  1110 */   117,  118,   32,  117,  118,  113,   57,   55,   32,  117,
 /*  1120 */   118,   59,    1,   61,   47,   63,   64,   32,   66,   67,
 /*  1130 */    68,   72,   70,   71,   31,   32,   33,  107,   35,   36,
 /*  1140 */    37,  107,    1,   40,  114,   38,  116,  117,  114,   46,
 /*  1150 */   116,  117,   56,    1,   32,  107,   49,   38,   55,   32,
 /*  1160 */    32,   32,   59,   32,   61,  117,   63,   64,   32,   66,
 /*  1170 */    67,   68,    1,   70,   71,   31,   32,   32,   57,   35,
 /*  1180 */    36,   37,  107,   39,   40,  107,  107,   80,   32,    1,
 /*  1190 */    46,   32,  117,   72,  107,  117,  117,   32,   57,   55,
 /*  1200 */    32,   32,  111,   59,  117,   61,  112,   63,   64,   57,
 /*  1210 */    66,   67,   68,   72,   70,   71,   31,   32,   41,  107,
 /*  1220 */    35,   36,   37,   32,   72,   40,    3,  107,   57,  117,
 /*  1230 */     1,   46,  107,   48,   38,    1,   32,  117,   32,   32,
 /*  1240 */    55,   32,  117,   72,   59,   57,   61,   32,   63,   64,
 /*  1250 */     1,   66,   67,   68,    1,   70,   71,   31,   32,   32,
 /*  1260 */    72,   35,   36,   37,  107,    1,   40,  119,   33,  119,
 /*  1270 */   107,  119,   46,  107,  117,  119,  119,  119,  119,  119,
 /*  1280 */   117,   55,   56,  117,  119,   59,   57,   61,  119,   63,
 /*  1290 */    64,   57,   66,   67,   68,    1,   70,   71,   31,   32,
 /*  1300 */   119,   72,   35,   36,   37,  119,   72,   40,  119,  119,
 /*  1310 */    57,  119,    1,   46,  119,  119,  119,  119,  119,  107,
 /*  1320 */   119,   57,   55,  119,  119,   72,   59,   60,   61,  117,
 /*  1330 */    63,   64,    1,   66,   67,   68,   72,   70,   71,   31,
 /*  1340 */    32,  119,  119,   35,   36,   37,  119,  119,   40,  119,
 /*  1350 */   107,   57,  107,    1,   46,  119,  119,  119,  119,  119,
 /*  1360 */   117,  119,  117,   55,  119,  119,   72,   59,   57,   61,
 /*  1370 */    62,   63,   64,    1,   66,   67,   68,    1,   70,   71,
 /*  1380 */    31,   32,  107,   72,   35,   36,   37,  119,   57,   40,
 /*  1390 */   107,  107,  117,  119,  119,   46,  119,  107,  119,  119,
 /*  1400 */   117,  117,  119,   72,   55,  119,  119,  117,   59,   57,
 /*  1410 */    61,  119,   63,   64,  119,   66,   67,   68,   69,   70,
 /*  1420 */    71,   31,   32,  119,   72,   35,   36,   37,  119,   57,
 /*  1430 */    40,  119,  119,   57,  119,  119,   46,  107,  119,  119,
 /*  1440 */   107,  119,  107,  119,   72,   55,  119,  117,   72,   59,
 /*  1450 */   117,   61,  117,   63,   64,  119,   66,   67,   68,   69,
 /*  1460 */    70,   71,   31,   32,  119,  119,   35,   36,   37,  119,
 /*  1470 */   107,   40,  119,  119,  107,  107,  119,   46,  107,  119,
 /*  1480 */   117,  107,  119,  119,  117,  117,   55,  119,  117,  119,
 /*  1490 */    59,  117,   61,   62,   63,   64,  107,   66,   67,   68,
 /*  1500 */   107,   70,   71,   31,   32,  107,  117,   35,   36,   37,
 /*  1510 */   117,  107,   40,  119,  119,  117,  107,  119,   46,  119,
 /*  1520 */   107,  117,  119,  119,  107,  119,  117,   55,  119,  119,
 /*  1530 */   117,   59,   60,   61,  117,   63,   64,  107,   66,   67,
 /*  1540 */    68,  107,   70,   71,   31,   32,  119,  117,   35,   36,
 /*  1550 */    37,  117,  107,   40,  119,  107,  107,  107,  119,   46,
 /*  1560 */   107,   48,  117,  119,  119,  117,  117,  117,   55,  119,
 /*  1570 */   117,  119,   59,  119,   61,  119,   63,   64,  107,   66,
 /*  1580 */    67,   68,  107,   70,   71,   31,   32,  119,  117,   35,
 /*  1590 */    36,   37,  117,   39,   40,  119,  107,  119,  107,  119,
 /*  1600 */    46,  107,  107,  119,  107,  119,  117,  119,  117,   55,
 /*  1610 */   119,  117,  117,   59,  117,   61,  119,   63,   64,  119,
 /*  1620 */    66,   67,   68,  119,   70,   71,   31,   32,  119,  119,
 /*  1630 */    35,   36,   37,  119,   39,   40,  119,  119,  119,  119,
 /*  1640 */   119,   46,  119,  119,  119,  119,  119,  119,  119,  119,
 /*  1650 */    55,  119,  119,  119,   59,  119,   61,  119,   63,   64,
 /*  1660 */   119,   66,   67,   68,  119,   70,   71,   31,   32,  119,
 /*  1670 */   119,   35,   36,   37,  119,   39,   40,  119,  119,  119,
 /*  1680 */   119,  119,   46,  119,  119,  119,  119,  119,  119,  119,
 /*  1690 */   119,   55,  119,  119,  119,   59,  119,   61,  119,   63,
 /*  1700 */    64,  119,   66,   67,   68,  119,   70,   71,   31,   32,
 /*  1710 */    33,  119,   35,   36,   37,  119,  119,   40,  119,  119,
 /*  1720 */   119,  119,  119,   46,  119,  119,  119,  119,  119,  119,
 /*  1730 */   119,  119,   55,  119,  119,  119,   59,  119,   61,  119,
 /*  1740 */    63,   64,  119,   66,   67,   68,  119,   70,   71,   31,
 /*  1750 */    32,  119,  119,   35,   36,   37,  119,  119,   40,  119,
 /*  1760 */   119,  119,  119,  119,   46,  119,  119,  119,  119,  119,
 /*  1770 */   119,  119,  119,   55,  119,  119,  119,   59,  119,   61,
 /*  1780 */   119,   63,   64,  119,   66,   67,   68,  119,   70,   71,
 /*  1790 */   119,  119,  119,   19,  119,   21,   22,  119,   24,  119,
 /*  1800 */    26,  119,  119,   29,  119,  119,  119,  119,  119,  119,
 /*  1810 */   119,  119,   38,  119,  119,  119,  119,  119,  119,  119,
 /*  1820 */   119,  119,  119,   49,   50,   51,   52,   53,   54,  119,
 /*  1830 */   119,   18,  119,  119,   21,   22,  119,   24,  119,   26,
 /*  1840 */   119,  119,   29,  119,  119,  119,  119,  119,  119,  119,
 /*  1850 */   119,   38,  119,  119,  119,   81,  119,    5,  119,  119,
 /*  1860 */   119,  119,   49,   50,   51,   52,   53,   54,  119,  119,
 /*  1870 */   119,  119,  119,   21,   22,  119,   24,  119,   26,  119,
 /*  1880 */   119,   29,  119,  119,  119,  119,  119,  119,  119,  119,
 /*  1890 */    38,  119,  119,  119,   81,  119,  119,  119,  119,  119,
 /*  1900 */   119,   49,   50,   51,   52,   53,   54,  119,  119,  119,
 /*  1910 */   119,  119,   21,   22,  119,   24,  119,   26,  119,  119,
 /*  1920 */    29,  119,  119,  119,  119,  119,  119,  119,  119,   38,
 /*  1930 */   119,  119,  119,   81,  119,  119,  119,  119,   47,  119,
 /*  1940 */    49,   50,   51,   52,   53,   54,  119,  119,  119,  119,
 /*  1950 */   119,   21,   22,  119,   24,  119,   26,  119,  119,   29,
 /*  1960 */   119,  119,  119,  119,  119,  119,  119,  119,   38,  119,
 /*  1970 */   119,  119,   81,  119,  119,  119,  119,  119,  119,   49,
 /*  1980 */    50,   51,   52,   53,   54,  119,  119,  119,  119,  119,
 /*  1990 */    21,   22,  119,   24,  119,   26,  119,  119,   29,  119,
 /*  2000 */   119,  119,  119,  119,  119,  119,  119,   38,  119,  119,
 /*  2010 */    80,   81,  119,  119,  119,  119,  119,  119,   49,   50,
 /*  2020 */    51,   52,   53,   54,  119,  119,  119,  119,  119,   21,
 /*  2030 */    22,  119,   24,  119,   26,  119,  119,   29,  119,  119,
 /*  2040 */   119,  119,  119,  119,  119,  119,   38,  119,  119,  119,
 /*  2050 */    81,   82,  119,  119,  119,   47,  119,   49,   50,   51,
 /*  2060 */    52,   53,   54,  119,  119,  119,  119,  119,   21,   22,
 /*  2070 */   119,   24,  119,   26,  119,  119,   29,  119,  119,  119,
 /*  2080 */   119,  119,  119,  119,  119,   38,  119,  119,  119,   81,
 /*  2090 */   119,  119,  119,  119,  119,  119,   49,   50,   51,   52,
 /*  2100 */    53,   54,  119,  119,  119,  119,  119,   21,   22,  119,
 /*  2110 */    24,  119,   26,  119,  119,   29,  119,  119,  119,  119,
 /*  2120 */   119,  119,  119,  119,   38,  119,  119,  119,   81,  119,
 /*  2130 */   119,  119,  119,  119,  119,   49,   50,   51,   52,   53,
 /*  2140 */    54,  119,  119,  119,  119,  119,   21,   22,  119,   24,
 /*  2150 */   119,   26,  119,  119,   29,  119,  119,  119,  119,  119,
 /*  2160 */   119,  119,  119,   38,  119,  119,  119,   81,  119,  119,
 /*  2170 */   119,  119,  119,  119,   49,   50,   51,   52,   53,   54,
 /*  2180 */   119,  119,  119,  119,  119,  119,  119,  119,  119,  119,
 /*  2190 */   119,  119,  119,  119,  119,  119,  119,  119,  119,  119,
 /*  2200 */   119,  119,  119,  119,  119,  119,   81,
};
#define YY_SHIFT_USE_DFLT (-4)
static short yy_shift_ofst[] = {
 /*     0 */     1,   79, 1059,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
 /*    10 */    -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
 /*    20 */    -4,   -4,   -4, 1718, 2047,  137, 1006, 1029, 1021,   50,
 /*    30 */    -4,   76, 1121, 1141, 1103,  140,   -4, 2047,  167,   -4,
 /*    40 */  2047, 2047,  976, 2047, 2047,  976, 1774,  288, 1813,  288,
 /*    50 */  2047,  288, 2047,  657, 2047,  657, 2047,  976, 2047,  999,
 /*    60 */  2047,  612, 2047,   42,  960,   42, 2047,   42, 2047,   42,
 /*    70 */  2047,   42, 2047,   42, 2047,   42, 2047,   42, 2047,   42,
 /*    80 */  2047,   -4, 2047,  443,  328, 2047,  999,   -4,   -4, 1852,
 /*    90 */   197,   -4, 2047,  225, 2047,  588, 1891,  535, 2047,  999,
 /*   100 */  2047,  278,   -4, 1930,  535,   -4,  200,   -4, 2086, 1969,
 /*   110 */    -4,   30,   -4,   -4,  352, 2047,  535,   -4,   -4,   -4,
 /*   120 */    -4,   -4,   -4,   -4,   -4,   -4,  281,   -4, 2125,   -4,
 /*   130 */   382, 2047,  535,   -4,   -4, 1028,  311,   -4,  337,  341,
 /*   140 */   470, 1107,   -4,  396,   -4,  472,  501,  970,   -4,   -4,
 /*   150 */    -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
 /*   160 */    -4,   -4, 2047,  288, 2047,  288,  976,  976,  448,   -4,
 /*   170 */   498,   72, 2047,   -3,    1, 1152, 1144,  478,   -4,  502,
 /*   180 */   166,   -4,  502,   -4, 1027, 2047,  535, 2047,  535, 2047,
 /*   190 */   535, 2047,  535, 2047,  535,   -4,  945,  959, 1043,  983,
 /*   200 */     1, 1171, 1185,  984,   -4, 2047,  563, 2008, 1015,  986,
 /*   210 */     1, 1188, 1226, 1051,   -4,   -4,  952, 1072, 1229, 1234,
 /*   220 */  1267, 1073,   -4, 2047,   27,    1, 1253, 1308, 1080,   -4,
 /*   230 */   981, 1086,   -4, 2047,   77,   -4, 2047,  326,   -4, 2047,
 /*   240 */   356,   -4, 2047,  386,   -4,  273, 1095,    1, 1264, 1349,
 /*   250 */  1122,   -4, 1127,   -4, 1128,   -4, 2047,  416,   -4,   -4,
 /*   260 */    -4, 1129,    1, 1294, 1390, 1131,   -4, 1136,    1, 1311,
 /*   270 */  1431, 1145,   -4, 1472, 1156,   -4, 1159, 1106, 1096, 1165,
 /*   280 */    -4, 1077, 1168,    1, 1331, 1513, 1169,   -4, 1119,   -4,
 /*   290 */  1177,  270,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
 /*   300 */  2047,  475,    1, 1352, 1554, 1191,   -4, 1196, 1223, 2047,
 /*   310 */   107,    1, 1372, 1595, 1204,   -4, 2047,  505,    1, 1376,
 /*   320 */  1636, 1206,   -4, 1677, 1207,   -4, 1062, 1209,   -4, 1215,
 /*   330 */  1249, 1235, 1227,   -4,
};
#define YY_REDUCE_USE_DFLT (-32)
static short yy_reduce_ofst[] = {
 /*     0 */   559,  -32,  874,  -32,  -32,  -32,  -32,  -32,  -32,  -32,
 /*    10 */   -32,  -32,  -32,  -32,  -32,  -32,  -32,  -32,  -32,  -32,
 /*    20 */   -32,  -32,  -32,  -32,  880,  -32,  170,  874,  -32,  -32,
 /*    30 */   -32,  -32,  602,  874,  -32,  -32,  -32,  925,  -32,  -32,
 /*    40 */   933,  958,  -32, 1048, 1075,  -32, 1079,  -32, 1087,  -32,
 /*    50 */  1112,  -32, 1120,  -32, 1157,  -32, 1163,  -32, 1166,  -32,
 /*    60 */  1212,  -32, 1245,  -32, 1275,  -32, 1283,  -32, 1284,  -32,
 /*    70 */  1290,  -32, 1330,  -32, 1333,  -32, 1335,  -32, 1363,  -32,
 /*    80 */  1367,  -32, 1368,  -32,  -32, 1371,  -32,  -32,  -32,  878,
 /*    90 */   -32,  -32, 1374,  -32, 1389,  -32,  993,  -32, 1393,  -32,
 /*   100 */  1398,  -32,  -32, 1030,  -32,  -32,  -32,  -32,  957, 1034,
 /*   110 */   -32,  -32,  -32,  -32,  -32, 1404,  -32,  -32,  -32,  -32,
 /*   120 */   -32,  -32,  -32,  -32,  -32,  -32,  -32,  -32,  996,  -32,
 /*   130 */   -32, 1409,  -32,  -32,  -32,  246,  -32,  -32,  -32,  -32,
 /*   140 */   -32,  333,  -32,  -32,  -32,  -32,  -32, 1078,  -32,  -32,
 /*   150 */   -32,  -32,  -32,  -32,  -32,  -32,  -32,  -32,  -32,  -32,
 /*   160 */   -32,  -32, 1413,  -32, 1417,  -32,  -32,  -32,  -32,  -32,
 /*   170 */   -32,  -32, 1430,  -32,  623,  874,  -32,  -32,  -32,  -31,
 /*   180 */   -32,  -32,  459,  -32,  -32, 1434,  -32, 1445,  -32, 1448,
 /*   190 */   -32, 1449,  -32, 1450,  -32,  -32,  -32,  -32,  168,  -32,
 /*   200 */   644,  874,  -32,  -32,  -32, 1453,  -32, 1002,  -32,  -32,
 /*   210 */   665,  874,  -32,  -32,  -32,  -32,  -32,  -32,  686,  874,
 /*   220 */   -32,  -32,  -32, 1471,  -32,  707,  874,  -32,  -32,  -32,
 /*   230 */   -32,  -32,  -32, 1475,  -32,  -32, 1489,  -32,  -32, 1491,
 /*   240 */   -32,  -32, 1494,  -32,  -32,  -32,  -32,  728,  874,  -32,
 /*   250 */   -32,  -32,  -32,  -32,  -32,  -32, 1495,  -32,  -32,  -32,
 /*   260 */   -32,  -32,  749,  874,  -32,  -32,  -32,  -32,  770,  874,
 /*   270 */   -32,  -32,  -32,  -32,  -32,  -32,  -32,  -32,  -32,  -32,
 /*   280 */   -32,  -32,  -32,  791,  874,  -32,  -32,  -32, 1091,  -32,
 /*   290 */   -32, 1094,  -32,  -32,  -32,  -32,  -32,  -32,  -32,  -32,
 /*   300 */  1125,  -32,  812,  874,  -32,  -32,  -32,  -32,  -32, 1243,
 /*   310 */   -32,  833,  874,  -32,  -32,  -32, 1497,  -32,  854,  874,
 /*   320 */   -32,  -32,  -32,  -32,  -32,  -32,  -32,  -32,  -32,  -32,
 /*   330 */   -32,  -32,  -32,  -32,
};
static YYACTIONTYPE yy_default[] = {
 /*     0 */   479,  479,  479,  336,  338,  339,  340,  341,  342,  343,
 /*    10 */   344,  345,  346,  347,  348,  349,  350,  351,  352,  353,
 /*    20 */   354,  355,  356,  479,  479,  479,  479,  479,  479,  479,
 /*    30 */   357,  479,  479,  479,  479,  479,  359,  479,  479,  362,
 /*    40 */   479,  479,  406,  479,  479,  407,  479,  410,  479,  412,
 /*    50 */   479,  414,  479,  415,  479,  416,  479,  417,  479,  418,
 /*    60 */   479,  419,  479,  420,  479,  435,  479,  436,  479,  437,
 /*    70 */   479,  438,  479,  439,  479,  440,  479,  441,  479,  442,
 /*    80 */   479,  443,  479,  444,  479,  479,  445,  447,  448,  479,
 /*    90 */   479,  454,  479,  479,  479,  455,  479,  470,  479,  446,
 /*   100 */   479,  479,  449,  479,  464,  450,  479,  451,  479,  479,
 /*   110 */   452,  479,  453,  462,  474,  479,  463,  465,  472,  473,
 /*   120 */   474,  475,  476,  477,  478,  461,  479,  466,  479,  468,
 /*   130 */   474,  479,  471,  467,  469,  479,  479,  456,  479,  479,
 /*   140 */   479,  479,  457,  479,  458,  473,  472,  479,  421,  423,
 /*   150 */   425,  427,  429,  431,  433,  422,  424,  426,  428,  430,
 /*   160 */   432,  434,  479,  413,  479,  411,  409,  408,  479,  363,
 /*   170 */   479,  479,  479,  479,  479,  479,  479,  479,  364,  479,
 /*   180 */   479,  368,  479,  369,  479,  479,  371,  479,  372,  479,
 /*   190 */   373,  479,  374,  479,  375,  370,  479,  479,  479,  479,
 /*   200 */   479,  479,  479,  479,  376,  479,  479,  479,  479,  466,
 /*   210 */   479,  479,  479,  479,  388,  390,  479,  479,  479,  479,
 /*   220 */   479,  479,  392,  479,  479,  479,  479,  479,  479,  394,
 /*   230 */   479,  479,  396,  479,  479,  397,  479,  479,  398,  479,
 /*   240 */   479,  399,  479,  479,  400,  479,  479,  479,  479,  479,
 /*   250 */   479,  401,  479,  403,  479,  404,  479,  479,  391,  405,
 /*   260 */   337,  479,  479,  479,  479,  479,  402,  479,  479,  479,
 /*   270 */   479,  479,  395,  479,  479,  393,  467,  479,  479,  479,
 /*   280 */   389,  479,  479,  479,  479,  479,  479,  377,  479,  378,
 /*   290 */   380,  479,  381,  382,  383,  384,  385,  386,  387,  379,
 /*   300 */   479,  479,  479,  479,  479,  479,  365,  479,  479,  479,
 /*   310 */   479,  479,  479,  479,  479,  366,  479,  479,  479,  479,
 /*   320 */   479,  479,  367,  479,  479,  360,  479,  479,  358,  479,
 /*   330 */   479,  479,  479,  361,
};
#define YY_SZ_ACTTAB (sizeof(yy_action)/sizeof(yy_action[0]))

/* The next table maps tokens into fallback tokens.  If a construct
** like the following:
** 
**      %fallback ID X Y Z.
**
** appears in the grammer, then ID becomes a fallback token for X, Y,
** and Z.  Whenever one of the tokens X, Y, or Z is input to the parser
** but it does not parse, the type of the token is changed to ID and
** the parse is retried before an error is thrown.
*/
#ifdef YYFALLBACK
static const YYCODETYPE yyFallback[] = {
};
#endif /* YYFALLBACK */

/* The following structure represents a single element of the
** parser's stack.  Information stored includes:
**
**   +  The state number for the parser at this level of the stack.
**
**   +  The value of the token stored at this level of the stack.
**      (In other words, the "major" token.)
**
**   +  The semantic value stored at this level of the stack.  This is
**      the information used by the action routines in the grammar.
**      It is sometimes called the "minor" token.
*/
struct yyStackEntry {
  int stateno;       /* The state-number */
  int major;         /* The major token value.  This is the code
                     ** number for the token at this stack level */
  YYMINORTYPE minor; /* The user-supplied minor token value.  This
                     ** is the value of the token  */
};
typedef struct yyStackEntry yyStackEntry;

/* The state of the parser is completely contained in an instance of
** the following structure */
struct yyParser {
  int yyidx;                    /* Index of top element in stack */
  int yyerrcnt;                 /* Shifts left before out of the error */
  phvolt_ARG_SDECL                /* A place to hold %extra_argument */
  yyStackEntry yystack[YYSTACKDEPTH];  /* The parser's stack */
};
typedef struct yyParser yyParser;

#ifndef NDEBUG
#include <stdio.h>
static FILE *yyTraceFILE = 0;
static char *yyTracePrompt = 0;
#endif /* NDEBUG */

#ifndef NDEBUG
/* 
** Turn parser tracing on by giving a stream to which to write the trace
** and a prompt to preface each trace message.  Tracing is turned off
** by making either argument NULL 
**
** Inputs:
** <ul>
** <li> A FILE* to which trace output should be written.
**      If NULL, then tracing is turned off.
** <li> A prefix string written at the beginning of every
**      line of trace output.  If NULL, then tracing is
**      turned off.
** </ul>
**
** Outputs:
** None.
*/
void phvolt_Trace(FILE *TraceFILE, char *zTracePrompt){
  yyTraceFILE = TraceFILE;
  yyTracePrompt = zTracePrompt;
  if( yyTraceFILE==0 ) yyTracePrompt = 0;
  else if( yyTracePrompt==0 ) yyTraceFILE = 0;
}
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing shifts, the names of all terminals and nonterminals
** are required.  The following table supplies these names */
static const char *yyTokenName[] = { 
  "$",             "OPEN_DELIMITER",  "COMMA",         "IN",          
  "QUESTION",      "COLON",         "RANGE",         "AND",         
  "OR",            "IS",            "EQUALS",        "NOTEQUALS",   
  "LESS",          "GREATER",       "GREATEREQUAL",  "LESSEQUAL",   
  "IDENTICAL",     "NOTIDENTICAL",  "DIVIDE",        "TIMES",       
  "MOD",           "PLUS",          "MINUS",         "CONCAT",      
  "SBRACKET_OPEN",  "PIPE",          "NOT",           "INCR",        
  "DECR",          "PARENTHESES_OPEN",  "DOT",           "IF",          
  "CLOSE_DELIMITER",  "ENDIF",         "ELSE",          "ELSEIF",      
  "ELSEFOR",       "FOR",           "IDENTIFIER",    "ENDFOR",      
  "SET",           "ASSIGN",        "ADD_ASSIGN",    "SUB_ASSIGN",  
  "MUL_ASSIGN",    "DIV_ASSIGN",    "MACRO",         "PARENTHESES_CLOSE",
  "ENDMACRO",      "INTEGER",       "STRING",        "DOUBLE",      
  "NULL",          "FALSE",         "TRUE",          "CALL",        
  "ENDCALL",       "OPEN_EDELIMITER",  "CLOSE_EDELIMITER",  "BLOCK",       
  "ENDBLOCK",      "CACHE",         "ENDCACHE",      "EXTENDS",     
  "INCLUDE",       "WITH",          "DO",            "RETURN",      
  "AUTOESCAPE",    "ENDAUTOESCAPE",  "BREAK",         "CONTINUE",    
  "RAW_FRAGMENT",  "DEFINED",       "EMPTY",         "EVEN",        
  "ODD",           "NUMERIC",       "SCALAR",        "ITERABLE",    
  "SBRACKET_CLOSE",  "CBRACKET_OPEN",  "CBRACKET_CLOSE",  "error",       
  "program",       "volt_language",  "statement_list",  "statement",   
  "raw_fragment",  "if_statement",  "elseif_statement",  "elsefor_statement",
  "for_statement",  "set_statement",  "echo_statement",  "block_statement",
  "cache_statement",  "extends_statement",  "include_statement",  "do_statement",
  "return_statement",  "autoescape_statement",  "break_statement",  "continue_statement",
  "macro_statement",  "empty_statement",  "macro_call_statement",  "expr",        
  "set_assignments",  "set_assignment",  "macro_parameters",  "macro_parameter",
  "macro_parameter_default",  "argument_list",  "array_list",    "slice_offset",
  "array_item",    "function_call",  "argument_item",
};
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing reduce actions, the names of all rules are required.
*/
static const char *yyRuleName[] = {
 /*   0 */ "program ::= volt_language",
 /*   1 */ "volt_language ::= statement_list",
 /*   2 */ "statement_list ::= statement_list statement",
 /*   3 */ "statement_list ::= statement",
 /*   4 */ "statement ::= raw_fragment",
 /*   5 */ "statement ::= if_statement",
 /*   6 */ "statement ::= elseif_statement",
 /*   7 */ "statement ::= elsefor_statement",
 /*   8 */ "statement ::= for_statement",
 /*   9 */ "statement ::= set_statement",
 /*  10 */ "statement ::= echo_statement",
 /*  11 */ "statement ::= block_statement",
 /*  12 */ "statement ::= cache_statement",
 /*  13 */ "statement ::= extends_statement",
 /*  14 */ "statement ::= include_statement",
 /*  15 */ "statement ::= do_statement",
 /*  16 */ "statement ::= return_statement",
 /*  17 */ "statement ::= autoescape_statement",
 /*  18 */ "statement ::= break_statement",
 /*  19 */ "statement ::= continue_statement",
 /*  20 */ "statement ::= macro_statement",
 /*  21 */ "statement ::= empty_statement",
 /*  22 */ "statement ::= macro_call_statement",
 /*  23 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  24 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  25 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ELSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  26 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ELSE CLOSE_DELIMITER OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  27 */ "if_statement ::= OPEN_DELIMITER IF expr CLOSE_DELIMITER OPEN_DELIMITER ELSE CLOSE_DELIMITER OPEN_DELIMITER ENDIF CLOSE_DELIMITER",
 /*  28 */ "elseif_statement ::= OPEN_DELIMITER ELSEIF expr CLOSE_DELIMITER",
 /*  29 */ "elsefor_statement ::= OPEN_DELIMITER ELSEFOR CLOSE_DELIMITER",
 /*  30 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER IN expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  31 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER IN expr IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  32 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER COMMA IDENTIFIER IN expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  33 */ "for_statement ::= OPEN_DELIMITER FOR IDENTIFIER COMMA IDENTIFIER IN expr IF expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDFOR CLOSE_DELIMITER",
 /*  34 */ "set_statement ::= OPEN_DELIMITER SET set_assignments CLOSE_DELIMITER",
 /*  35 */ "set_assignments ::= set_assignments COMMA set_assignment",
 /*  36 */ "set_assignments ::= set_assignment",
 /*  37 */ "set_assignment ::= IDENTIFIER ASSIGN expr",
 /*  38 */ "set_assignment ::= IDENTIFIER ADD_ASSIGN expr",
 /*  39 */ "set_assignment ::= IDENTIFIER SUB_ASSIGN expr",
 /*  40 */ "set_assignment ::= IDENTIFIER MUL_ASSIGN expr",
 /*  41 */ "set_assignment ::= IDENTIFIER DIV_ASSIGN expr",
 /*  42 */ "macro_statement ::= OPEN_DELIMITER MACRO IDENTIFIER PARENTHESES_OPEN PARENTHESES_CLOSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDMACRO CLOSE_DELIMITER",
 /*  43 */ "macro_statement ::= OPEN_DELIMITER MACRO IDENTIFIER PARENTHESES_OPEN macro_parameters PARENTHESES_CLOSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDMACRO CLOSE_DELIMITER",
 /*  44 */ "macro_parameters ::= macro_parameters COMMA macro_parameter",
 /*  45 */ "macro_parameters ::= macro_parameter",
 /*  46 */ "macro_parameter ::= IDENTIFIER",
 /*  47 */ "macro_parameter ::= IDENTIFIER ASSIGN macro_parameter_default",
 /*  48 */ "macro_parameter_default ::= INTEGER",
 /*  49 */ "macro_parameter_default ::= STRING",
 /*  50 */ "macro_parameter_default ::= DOUBLE",
 /*  51 */ "macro_parameter_default ::= NULL",
 /*  52 */ "macro_parameter_default ::= FALSE",
 /*  53 */ "macro_parameter_default ::= TRUE",
 /*  54 */ "macro_call_statement ::= OPEN_DELIMITER CALL expr PARENTHESES_OPEN argument_list PARENTHESES_CLOSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCALL CLOSE_DELIMITER",
 /*  55 */ "macro_call_statement ::= OPEN_DELIMITER CALL expr PARENTHESES_OPEN PARENTHESES_CLOSE CLOSE_DELIMITER OPEN_DELIMITER ENDCALL CLOSE_DELIMITER",
 /*  56 */ "empty_statement ::= OPEN_DELIMITER CLOSE_DELIMITER",
 /*  57 */ "echo_statement ::= OPEN_EDELIMITER expr CLOSE_EDELIMITER",
 /*  58 */ "block_statement ::= OPEN_DELIMITER BLOCK IDENTIFIER CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDBLOCK CLOSE_DELIMITER",
 /*  59 */ "block_statement ::= OPEN_DELIMITER BLOCK IDENTIFIER CLOSE_DELIMITER OPEN_DELIMITER ENDBLOCK CLOSE_DELIMITER",
 /*  60 */ "cache_statement ::= OPEN_DELIMITER CACHE expr CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCACHE CLOSE_DELIMITER",
 /*  61 */ "cache_statement ::= OPEN_DELIMITER CACHE expr INTEGER CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDCACHE CLOSE_DELIMITER",
 /*  62 */ "extends_statement ::= OPEN_DELIMITER EXTENDS STRING CLOSE_DELIMITER",
 /*  63 */ "include_statement ::= OPEN_DELIMITER INCLUDE expr CLOSE_DELIMITER",
 /*  64 */ "include_statement ::= OPEN_DELIMITER INCLUDE expr WITH expr CLOSE_DELIMITER",
 /*  65 */ "do_statement ::= OPEN_DELIMITER DO expr CLOSE_DELIMITER",
 /*  66 */ "return_statement ::= OPEN_DELIMITER RETURN expr CLOSE_DELIMITER",
 /*  67 */ "autoescape_statement ::= OPEN_DELIMITER AUTOESCAPE FALSE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDAUTOESCAPE CLOSE_DELIMITER",
 /*  68 */ "autoescape_statement ::= OPEN_DELIMITER AUTOESCAPE TRUE CLOSE_DELIMITER statement_list OPEN_DELIMITER ENDAUTOESCAPE CLOSE_DELIMITER",
 /*  69 */ "break_statement ::= OPEN_DELIMITER BREAK CLOSE_DELIMITER",
 /*  70 */ "continue_statement ::= OPEN_DELIMITER CONTINUE CLOSE_DELIMITER",
 /*  71 */ "raw_fragment ::= RAW_FRAGMENT",
 /*  72 */ "expr ::= MINUS expr",
 /*  73 */ "expr ::= PLUS expr",
 /*  74 */ "expr ::= expr MINUS expr",
 /*  75 */ "expr ::= expr PLUS expr",
 /*  76 */ "expr ::= expr TIMES expr",
 /*  77 */ "expr ::= expr TIMES TIMES expr",
 /*  78 */ "expr ::= expr DIVIDE expr",
 /*  79 */ "expr ::= expr DIVIDE DIVIDE expr",
 /*  80 */ "expr ::= expr MOD expr",
 /*  81 */ "expr ::= expr AND expr",
 /*  82 */ "expr ::= expr OR expr",
 /*  83 */ "expr ::= expr CONCAT expr",
 /*  84 */ "expr ::= expr PIPE expr",
 /*  85 */ "expr ::= expr RANGE expr",
 /*  86 */ "expr ::= expr EQUALS expr",
 /*  87 */ "expr ::= expr IS NOT DEFINED",
 /*  88 */ "expr ::= expr IS DEFINED",
 /*  89 */ "expr ::= expr IS NOT EMPTY",
 /*  90 */ "expr ::= expr IS EMPTY",
 /*  91 */ "expr ::= expr IS NOT EVEN",
 /*  92 */ "expr ::= expr IS EVEN",
 /*  93 */ "expr ::= expr IS NOT ODD",
 /*  94 */ "expr ::= expr IS ODD",
 /*  95 */ "expr ::= expr IS NOT NUMERIC",
 /*  96 */ "expr ::= expr IS NUMERIC",
 /*  97 */ "expr ::= expr IS NOT SCALAR",
 /*  98 */ "expr ::= expr IS SCALAR",
 /*  99 */ "expr ::= expr IS NOT ITERABLE",
 /* 100 */ "expr ::= expr IS ITERABLE",
 /* 101 */ "expr ::= expr IS expr",
 /* 102 */ "expr ::= expr NOTEQUALS expr",
 /* 103 */ "expr ::= expr IDENTICAL expr",
 /* 104 */ "expr ::= expr NOTIDENTICAL expr",
 /* 105 */ "expr ::= expr LESS expr",
 /* 106 */ "expr ::= expr GREATER expr",
 /* 107 */ "expr ::= expr GREATEREQUAL expr",
 /* 108 */ "expr ::= expr LESSEQUAL expr",
 /* 109 */ "expr ::= expr DOT expr",
 /* 110 */ "expr ::= expr IN expr",
 /* 111 */ "expr ::= expr NOT IN expr",
 /* 112 */ "expr ::= NOT expr",
 /* 113 */ "expr ::= expr INCR",
 /* 114 */ "expr ::= expr DECR",
 /* 115 */ "expr ::= PARENTHESES_OPEN expr PARENTHESES_CLOSE",
 /* 116 */ "expr ::= SBRACKET_OPEN SBRACKET_CLOSE",
 /* 117 */ "expr ::= SBRACKET_OPEN array_list SBRACKET_CLOSE",
 /* 118 */ "expr ::= CBRACKET_OPEN CBRACKET_CLOSE",
 /* 119 */ "expr ::= CBRACKET_OPEN array_list CBRACKET_CLOSE",
 /* 120 */ "expr ::= expr SBRACKET_OPEN expr SBRACKET_CLOSE",
 /* 121 */ "expr ::= expr QUESTION expr COLON expr",
 /* 122 */ "expr ::= expr SBRACKET_OPEN COLON slice_offset SBRACKET_CLOSE",
 /* 123 */ "expr ::= expr SBRACKET_OPEN slice_offset COLON SBRACKET_CLOSE",
 /* 124 */ "expr ::= expr SBRACKET_OPEN slice_offset COLON slice_offset SBRACKET_CLOSE",
 /* 125 */ "slice_offset ::= INTEGER",
 /* 126 */ "slice_offset ::= IDENTIFIER",
 /* 127 */ "array_list ::= array_list COMMA array_item",
 /* 128 */ "array_list ::= array_item",
 /* 129 */ "array_item ::= STRING COLON expr",
 /* 130 */ "array_item ::= expr",
 /* 131 */ "expr ::= function_call",
 /* 132 */ "function_call ::= expr PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 133 */ "function_call ::= expr PARENTHESES_OPEN PARENTHESES_CLOSE",
 /* 134 */ "argument_list ::= argument_list COMMA argument_item",
 /* 135 */ "argument_list ::= argument_item",
 /* 136 */ "argument_item ::= expr",
 /* 137 */ "argument_item ::= STRING COLON expr",
 /* 138 */ "expr ::= IDENTIFIER",
 /* 139 */ "expr ::= INTEGER",
 /* 140 */ "expr ::= STRING",
 /* 141 */ "expr ::= DOUBLE",
 /* 142 */ "expr ::= NULL",
 /* 143 */ "expr ::= FALSE",
 /* 144 */ "expr ::= TRUE",
};
#endif /* NDEBUG */

/*
** This function returns the symbolic name associated with a token
** value.
*/
const char *phvolt_TokenName(int tokenType){
#ifndef NDEBUG
  if( tokenType>0 && (size_t)tokenType<(sizeof(yyTokenName)/sizeof(yyTokenName[0])) ){
    return yyTokenName[tokenType];
  }else{
    return "Unknown";
  }
#else
  return "";
#endif
}

/* 
** This function allocates a new parser.
** The only argument is a pointer to a function which works like
** malloc.
**
** Inputs:
** A pointer to the function used to allocate memory.
**
** Outputs:
** A pointer to a parser.  This pointer is used in subsequent calls
** to phvolt_ and phvolt_Free.
*/
void *phvolt_Alloc(void *(*mallocProc)(size_t)){
  yyParser *pParser;
  pParser = (yyParser*)(*mallocProc)( (size_t)sizeof(yyParser) );
  if( pParser ){
    pParser->yyidx = -1;
  }
  return pParser;
}

/* The following function deletes the value associated with a
** symbol.  The symbol can be either a terminal or nonterminal.
** "yymajor" is the symbol code, and "yypminor" is a pointer to
** the value.
*/
static void yy_destructor(YYCODETYPE yymajor, YYMINORTYPE *yypminor){
  switch( yymajor ){
    /* Here is inserted the actions which take place when a
    ** terminal or non-terminal is destroyed.  This can happen
    ** when the symbol is popped from the stack during a
    ** reduce or during error processing or when a parser is 
    ** being destroyed before it is finished parsing.
    **
    ** Note: during a reduce, the only symbols destroyed are those
    ** which appear on the RHS of the rule, but which are not used
    ** inside the C code.
    */
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 47:
    case 48:
    case 49:
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
    case 56:
    case 57:
    case 58:
    case 59:
    case 60:
    case 61:
    case 62:
    case 63:
    case 64:
    case 65:
    case 66:
    case 67:
    case 68:
    case 69:
    case 70:
    case 71:
    case 72:
    case 73:
    case 74:
    case 75:
    case 76:
    case 77:
    case 78:
    case 79:
    case 80:
    case 81:
    case 82:
/* #line 697 "parser.y" */
{
	if ((yypminor->yy0)) {
		if ((yypminor->yy0)->free_flag) {
			efree((yypminor->yy0)->token);
		}
		efree((yypminor->yy0));
	}
}
/* #line 1653 "parser.c" */
      break;
    case 86:
    case 87:
    case 88:
    case 89:
    case 90:
    case 91:
    case 92:
    case 93:
    case 94:
    case 95:
    case 96:
    case 97:
    case 98:
    case 99:
    case 100:
    case 101:
    case 102:
    case 103:
    case 104:
    case 105:
    case 106:
    case 107:
    case 108:
    case 109:
    case 110:
    case 111:
    case 113:
    case 114:
    case 115:
    case 116:
    case 117:
    case 118:
/* #line 714 "parser.y" */
{ zval_ptr_dtor(&(yypminor->yy92)); }
/* #line 1689 "parser.c" */
      break;
    default:  break;   /* If no destructor action specified: do nothing */
  }
}

/*
** Pop the parser's stack once.
**
** If there is a destructor routine associated with the token which
** is popped from the stack, then call it.
**
** Return the major token number for the symbol popped.
*/
static int yy_pop_parser_stack(yyParser *pParser){
  YYCODETYPE yymajor;
  yyStackEntry *yytos = &pParser->yystack[pParser->yyidx];

  if( pParser->yyidx<0 ) return 0;
#ifndef NDEBUG
  if( yyTraceFILE && pParser->yyidx>=0 ){
    fprintf(yyTraceFILE,"%sPopping %s\n",
      yyTracePrompt,
      yyTokenName[yytos->major]);
  }
#endif
  yymajor = yytos->major;
  yy_destructor( yymajor, &yytos->minor);
  pParser->yyidx--;
  return yymajor;
}

/* 
** Deallocate and destroy a parser.  Destructors are all called for
** all stack elements before shutting the parser down.
**
** Inputs:
** <ul>
** <li>  A pointer to the parser.  This should be a pointer
**       obtained from phvolt_Alloc.
** <li>  A pointer to a function used to reclaim memory obtained
**       from malloc.
** </ul>
*/
void phvolt_Free(
  void *p,                    /* The parser to be deleted */
  void (*freeProc)(void*)     /* Function used to reclaim memory */
){
  yyParser *pParser = (yyParser*)p;
  if( pParser==0 ) return;
  while( pParser->yyidx>=0 ) yy_pop_parser_stack(pParser);
  (*freeProc)((void*)pParser);
}

/*
** Find the appropriate action for a parser given the terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is YYNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return YY_NO_ACTION.
*/
static int yy_find_shift_action(
  yyParser *pParser,        /* The parser */
  int iLookAhead            /* The look-ahead token */
){
  int i;
  int stateno = pParser->yystack[pParser->yyidx].stateno;
 
  /* if( pParser->yyidx<0 ) return YY_NO_ACTION;  */
  i = yy_shift_ofst[stateno];
  if( i==YY_SHIFT_USE_DFLT ){
    return yy_default[stateno];
  }
  if( iLookAhead==YYNOCODE ){
    return YY_NO_ACTION;
  }
  i += iLookAhead;
  if( i<0 || i>=(int)YY_SZ_ACTTAB || yy_lookahead[i]!=iLookAhead ){
#ifdef YYFALLBACK
    int iFallback;            /* Fallback token */
    if( iLookAhead<sizeof(yyFallback)/sizeof(yyFallback[0])
           && (iFallback = yyFallback[iLookAhead])!=0 ){
#ifndef NDEBUG
      if( yyTraceFILE ){
        fprintf(yyTraceFILE, "%sFALLBACK %s => %s\n",
           yyTracePrompt, yyTokenName[iLookAhead], yyTokenName[iFallback]);
      }
#endif
      return yy_find_shift_action(pParser, iFallback);
    }
#endif
    return yy_default[stateno];
  }else{
    return yy_action[i];
  }
}

/*
** Find the appropriate action for a parser given the non-terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is YYNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return YY_NO_ACTION.
*/
static int yy_find_reduce_action(
  yyParser *pParser,        /* The parser */
  int iLookAhead            /* The look-ahead token */
){
  int i;
  int stateno = pParser->yystack[pParser->yyidx].stateno;
 
  i = yy_reduce_ofst[stateno];
  if( i==YY_REDUCE_USE_DFLT ){
    return yy_default[stateno];
  }
  if( iLookAhead==YYNOCODE ){
    return YY_NO_ACTION;
  }
  i += iLookAhead;
  if( i<0 || i>=(int)YY_SZ_ACTTAB || yy_lookahead[i]!=iLookAhead ){
    return yy_default[stateno];
  }else{
    return yy_action[i];
  }
}

/*
** Perform a shift action.
*/
static void yy_shift(
  yyParser *yypParser,          /* The parser to be shifted */
  int yyNewState,               /* The new state to shift in */
  int yyMajor,                  /* The major token to shift in */
  YYMINORTYPE *yypMinor         /* Pointer ot the minor token to shift in */
){
  yyStackEntry *yytos;
  yypParser->yyidx++;
  if( yypParser->yyidx>=YYSTACKDEPTH ){
     phvolt_ARG_FETCH;
     yypParser->yyidx--;
#ifndef NDEBUG
     if( yyTraceFILE ){
       fprintf(yyTraceFILE,"%sStack Overflow!\n",yyTracePrompt);
     }
#endif
     while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
     /* Here code is inserted which will execute if the parser
     ** stack every overflows */
     phvolt_ARG_STORE; /* Suppress warning about unused %extra_argument var */
     return;
  }
  yytos = &yypParser->yystack[yypParser->yyidx];
  yytos->stateno = yyNewState;
  yytos->major = yyMajor;
  yytos->minor = *yypMinor;
#ifndef NDEBUG
  if( yyTraceFILE && yypParser->yyidx>0 ){
    int i;
    fprintf(yyTraceFILE,"%sShift %d\n",yyTracePrompt,yyNewState);
    fprintf(yyTraceFILE,"%sStack:",yyTracePrompt);
    for(i=1; i<=yypParser->yyidx; i++)
      fprintf(yyTraceFILE," %s",yyTokenName[yypParser->yystack[i].major]);
    fprintf(yyTraceFILE,"\n");
  }
#endif
}

/* The following table contains information about every rule that
** is used during the reduce.
*/
static struct {
  YYCODETYPE lhs;         /* Symbol on the left-hand side of the rule */
  unsigned char nrhs;     /* Number of right-hand side symbols in the rule */
} yyRuleInfo[] = {
  { 84, 1 },
  { 85, 1 },
  { 86, 2 },
  { 86, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 87, 1 },
  { 89, 8 },
  { 89, 7 },
  { 89, 12 },
  { 89, 11 },
  { 89, 10 },
  { 90, 4 },
  { 91, 3 },
  { 92, 10 },
  { 92, 12 },
  { 92, 12 },
  { 92, 14 },
  { 93, 4 },
  { 108, 3 },
  { 108, 1 },
  { 109, 3 },
  { 109, 3 },
  { 109, 3 },
  { 109, 3 },
  { 109, 3 },
  { 104, 10 },
  { 104, 11 },
  { 110, 3 },
  { 110, 1 },
  { 111, 1 },
  { 111, 3 },
  { 112, 1 },
  { 112, 1 },
  { 112, 1 },
  { 112, 1 },
  { 112, 1 },
  { 112, 1 },
  { 106, 11 },
  { 106, 9 },
  { 105, 2 },
  { 94, 3 },
  { 95, 8 },
  { 95, 7 },
  { 96, 8 },
  { 96, 9 },
  { 97, 4 },
  { 98, 4 },
  { 98, 6 },
  { 99, 4 },
  { 100, 4 },
  { 101, 8 },
  { 101, 8 },
  { 102, 3 },
  { 103, 3 },
  { 88, 1 },
  { 107, 2 },
  { 107, 2 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 4 },
  { 107, 3 },
  { 107, 4 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 4 },
  { 107, 3 },
  { 107, 4 },
  { 107, 3 },
  { 107, 4 },
  { 107, 3 },
  { 107, 4 },
  { 107, 3 },
  { 107, 4 },
  { 107, 3 },
  { 107, 4 },
  { 107, 3 },
  { 107, 4 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 3 },
  { 107, 4 },
  { 107, 2 },
  { 107, 2 },
  { 107, 2 },
  { 107, 3 },
  { 107, 2 },
  { 107, 3 },
  { 107, 2 },
  { 107, 3 },
  { 107, 4 },
  { 107, 5 },
  { 107, 5 },
  { 107, 5 },
  { 107, 6 },
  { 115, 1 },
  { 115, 1 },
  { 114, 3 },
  { 114, 1 },
  { 116, 3 },
  { 116, 1 },
  { 107, 1 },
  { 117, 4 },
  { 117, 3 },
  { 113, 3 },
  { 113, 1 },
  { 118, 1 },
  { 118, 3 },
  { 107, 1 },
  { 107, 1 },
  { 107, 1 },
  { 107, 1 },
  { 107, 1 },
  { 107, 1 },
  { 107, 1 },
};

static void yy_accept(yyParser*);  /* Forward Declaration */

/*
** Perform a reduce action and the shift that must immediately
** follow the reduce.
*/
static void yy_reduce(
  yyParser *yypParser,         /* The parser */
  int yyruleno                 /* Number of the rule by which to reduce */
){
  int yygoto;                     /* The next state */
  int yyact;                      /* The next action */
  YYMINORTYPE yygotominor;        /* The LHS of the rule reduced */
  yyStackEntry *yymsp;            /* The top of the parser's stack */
  int yysize;                     /* Amount to pop the stack */
  phvolt_ARG_FETCH;
  yymsp = &yypParser->yystack[yypParser->yyidx];
#ifndef NDEBUG
  if( yyTraceFILE && yyruleno>=0 
        && yyruleno<(int)(sizeof(yyRuleName)/sizeof(yyRuleName[0])) ){
    fprintf(yyTraceFILE, "%sReduce [%s].\n", yyTracePrompt,
      yyRuleName[yyruleno]);
  }
#endif /* NDEBUG */

  switch( yyruleno ){
  /* Beginning here are the reduction cases.  A typical example
  ** follows:
  **   case 0:
  **  #line <lineno> <grammarfile>
  **     { ... }           // User supplied code
  **  #line <lineno> <thisfile>
  **     break;
  */
      case 0:
/* #line 706 "parser.y" */
{
	status->ret = yymsp[0].minor.yy92;
}
/* #line 2051 "parser.c" */
        break;
      case 1:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
      case 10:
      case 11:
      case 12:
      case 13:
      case 14:
      case 15:
      case 16:
      case 17:
      case 18:
      case 19:
      case 20:
      case 21:
      case 22:
      case 131:
/* #line 710 "parser.y" */
{
	yygotominor.yy92 = yymsp[0].minor.yy92;
}
/* #line 2078 "parser.c" */
        break;
      case 2:
/* #line 716 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_zval_list(yymsp[-1].minor.yy92, yymsp[0].minor.yy92);
}
/* #line 2085 "parser.c" */
        break;
      case 3:
      case 36:
      case 45:
      case 128:
      case 135:
/* #line 720 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_zval_list(NULL, yymsp[0].minor.yy92);
}
/* #line 2096 "parser.c" */
        break;
      case 23:
/* #line 804 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_if_statement(yymsp[-5].minor.yy92, yymsp[-3].minor.yy92, NULL, status->scanner_state);
  yy_destructor(1,&yymsp[-7].minor);
  yy_destructor(31,&yymsp[-6].minor);
  yy_destructor(32,&yymsp[-4].minor);
  yy_destructor(1,&yymsp[-2].minor);
  yy_destructor(33,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
/* #line 2109 "parser.c" */
        break;
      case 24:
/* #line 808 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_if_statement(yymsp[-4].minor.yy92, NULL, NULL, status->scanner_state);
  yy_destructor(1,&yymsp[-6].minor);
  yy_destructor(31,&yymsp[-5].minor);
  yy_destructor(32,&yymsp[-3].minor);
  yy_destructor(1,&yymsp[-2].minor);
  yy_destructor(33,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
/* #line 2122 "parser.c" */
        break;
      case 25:
/* #line 812 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_if_statement(yymsp[-9].minor.yy92, yymsp[-7].minor.yy92, yymsp[-3].minor.yy92, status->scanner_state);
  yy_destructor(1,&yymsp[-11].minor);
  yy_destructor(31,&yymsp[-10].minor);
  yy_destructor(32,&yymsp[-8].minor);
  yy_destructor(1,&yymsp[-6].minor);
  yy_destructor(34,&yymsp[-5].minor);
  yy_destructor(32,&yymsp[-4].minor);
  yy_destructor(1,&yymsp[-2].minor);
  yy_destructor(33,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
/* #line 2138 "parser.c" */
        break;
      case 26:
/* #line 816 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_if_statement(yymsp[-8].minor.yy92, yymsp[-6].minor.yy92, NULL, status->scanner_state);
  yy_destructor(1,&yymsp[-10].minor);
  yy_destructor(31,&yymsp[-9].minor);
  yy_destructor(32,&yymsp[-7].minor);
  yy_destructor(1,&yymsp[-5].minor);
  yy_destructor(34,&yymsp[-4].minor);
  yy_destructor(32,&yymsp[-3].minor);
  yy_destructor(1,&yymsp[-2].minor);
  yy_destructor(33,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
/* #line 2154 "parser.c" */
        break;
      case 27:
/* #line 820 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_if_statement(yymsp[-7].minor.yy92, NULL, NULL, status->scanner_state);
  yy_destructor(1,&yymsp[-9].minor);
  yy_destructor(31,&yymsp[-8].minor);
  yy_destructor(32,&yymsp[-6].minor);
  yy_destructor(1,&yymsp[-5].minor);
  yy_destructor(34,&yymsp[-4].minor);
  yy_destructor(32,&yymsp[-3].minor);
  yy_destructor(1,&yymsp[-2].minor);
  yy_destructor(33,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
/* #line 2170 "parser.c" */
        break;
      case 28:
/* #line 826 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_elseif_statement(yymsp[-1].minor.yy92, status->scanner_state);
  yy_destructor(1,&yymsp[-3].minor);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(32,&yymsp[0].minor);
}
/* #line 2180 "parser.c" */
        break;
      case 29:
/* #line 832 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_elsefor_statement(status->scanner_state);
  yy_destructor(1,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
/* #line 2190 "parser.c" */
        break;
      case 30:
/* #line 838 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_for_statement(yymsp[-7].minor.yy0, NULL, yymsp[-5].minor.yy92, NULL, yymsp[-3].minor.yy92, status->scanner_state);
  yy_destructor(1,&yymsp[-9].minor);
  yy_destructor(37,&yymsp[-8].minor);
  yy_destructor(3,&yymsp[-6].minor);
  yy_destructor(32,&yymsp[-4].minor);
  yy_destructor(1,&yymsp[-2].minor);
  yy_destructor(39,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
/* #line 2204 "parser.c" */
        break;
      case 31:
/* #line 842 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_for_statement(yymsp[-9].minor.yy0, NULL, yymsp[-7].minor.yy92, yymsp[-5].minor.yy92, yymsp[-3].minor.yy92, status->scanner_state);
  yy_destructor(1,&yymsp[-11].minor);
  yy_destructor(37,&yymsp[-10].minor);
  yy_destructor(3,&yymsp[-8].minor);
  yy_destructor(31,&yymsp[-6].minor);
  yy_destructor(32,&yymsp[-4].minor);
  yy_destructor(1,&yymsp[-2].minor);
  yy_destructor(39,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
/* #line 2219 "parser.c" */
        break;
      case 32:
/* #line 846 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_for_statement(yymsp[-7].minor.yy0, yymsp[-9].minor.yy0, yymsp[-5].minor.yy92, NULL, yymsp[-3].minor.yy92, status->scanner_state);
  yy_destructor(1,&yymsp[-11].minor);
  yy_destructor(37,&yymsp[-10].minor);
  yy_destructor(2,&yymsp[-8].minor);
  yy_destructor(3,&yymsp[-6].minor);
  yy_destructor(32,&yymsp[-4].minor);
  yy_destructor(1,&yymsp[-2].minor);
  yy_destructor(39,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
/* #line 2234 "parser.c" */
        break;
      case 33:
/* #line 850 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_for_statement(yymsp[-9].minor.yy0, yymsp[-11].minor.yy0, yymsp[-7].minor.yy92, yymsp[-5].minor.yy92, yymsp[-3].minor.yy92, status->scanner_state);
  yy_destructor(1,&yymsp[-13].minor);
  yy_destructor(37,&yymsp[-12].minor);
  yy_destructor(2,&yymsp[-10].minor);
  yy_destructor(3,&yymsp[-8].minor);
  yy_destructor(31,&yymsp[-6].minor);
  yy_destructor(32,&yymsp[-4].minor);
  yy_destructor(1,&yymsp[-2].minor);
  yy_destructor(39,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
/* #line 2250 "parser.c" */
        break;
      case 34:
/* #line 856 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_set_statement(yymsp[-1].minor.yy92);
  yy_destructor(1,&yymsp[-3].minor);
  yy_destructor(40,&yymsp[-2].minor);
  yy_destructor(32,&yymsp[0].minor);
}
/* #line 2260 "parser.c" */
        break;
      case 35:
      case 44:
      case 127:
      case 134:
/* #line 862 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_zval_list(yymsp[-2].minor.yy92, yymsp[0].minor.yy92);
  yy_destructor(2,&yymsp[-1].minor);
}
/* #line 2271 "parser.c" */
        break;
      case 37:
/* #line 872 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_set_assignment(yymsp[-2].minor.yy0, PHVOLT_T_ASSIGN, yymsp[0].minor.yy92, status->scanner_state);
  yy_destructor(41,&yymsp[-1].minor);
}
/* #line 2279 "parser.c" */
        break;
      case 38:
/* #line 876 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_set_assignment(yymsp[-2].minor.yy0, PHVOLT_T_ADD_ASSIGN, yymsp[0].minor.yy92, status->scanner_state);
  yy_destructor(42,&yymsp[-1].minor);
}
/* #line 2287 "parser.c" */
        break;
      case 39:
/* #line 880 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_set_assignment(yymsp[-2].minor.yy0, PHVOLT_T_SUB_ASSIGN, yymsp[0].minor.yy92, status->scanner_state);
  yy_destructor(43,&yymsp[-1].minor);
}
/* #line 2295 "parser.c" */
        break;
      case 40:
/* #line 884 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_set_assignment(yymsp[-2].minor.yy0, PHVOLT_T_MUL_ASSIGN, yymsp[0].minor.yy92, status->scanner_state);
  yy_destructor(44,&yymsp[-1].minor);
}
/* #line 2303 "parser.c" */
        break;
      case 41:
/* #line 888 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_set_assignment(yymsp[-2].minor.yy0, PHVOLT_T_DIV_ASSIGN, yymsp[0].minor.yy92, status->scanner_state);
  yy_destructor(45,&yymsp[-1].minor);
}
/* #line 2311 "parser.c" */
        break;
      case 42:
/* #line 894 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_macro_statement(yymsp[-7].minor.yy0, NULL, yymsp[-3].minor.yy92, status->scanner_state);
  yy_destructor(1,&yymsp[-9].minor);
  yy_destructor(46,&yymsp[-8].minor);
  yy_destructor(29,&yymsp[-6].minor);
  yy_destructor(47,&yymsp[-5].minor);
  yy_destructor(32,&yymsp[-4].minor);
  yy_destructor(1,&yymsp[-2].minor);
  yy_destructor(48,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
/* #line 2326 "parser.c" */
        break;
      case 43:
/* #line 898 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_macro_statement(yymsp[-8].minor.yy0, yymsp[-6].minor.yy92, yymsp[-3].minor.yy92, status->scanner_state);
  yy_destructor(1,&yymsp[-10].minor);
  yy_destructor(46,&yymsp[-9].minor);
  yy_destructor(29,&yymsp[-7].minor);
  yy_destructor(47,&yymsp[-5].minor);
  yy_destructor(32,&yymsp[-4].minor);
  yy_destructor(1,&yymsp[-2].minor);
  yy_destructor(48,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
/* #line 2341 "parser.c" */
        break;
      case 46:
/* #line 914 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_macro_parameter(yymsp[0].minor.yy0, NULL, status->scanner_state);
}
/* #line 2348 "parser.c" */
        break;
      case 47:
/* #line 918 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_macro_parameter(yymsp[-2].minor.yy0, yymsp[0].minor.yy92, status->scanner_state);
  yy_destructor(41,&yymsp[-1].minor);
}
/* #line 2356 "parser.c" */
        break;
      case 48:
      case 125:
      case 139:
/* #line 922 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_literal_zval(PHVOLT_T_INTEGER, yymsp[0].minor.yy0, status->scanner_state);
}
/* #line 2365 "parser.c" */
        break;
      case 49:
      case 140:
/* #line 926 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_literal_zval(PHVOLT_T_STRING, yymsp[0].minor.yy0, status->scanner_state);
}
/* #line 2373 "parser.c" */
        break;
      case 50:
      case 141:
/* #line 930 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_literal_zval(PHVOLT_T_DOUBLE, yymsp[0].minor.yy0, status->scanner_state);
}
/* #line 2381 "parser.c" */
        break;
      case 51:
      case 142:
/* #line 934 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_literal_zval(PHVOLT_T_NULL, NULL, status->scanner_state);
  yy_destructor(52,&yymsp[0].minor);
}
/* #line 2390 "parser.c" */
        break;
      case 52:
      case 143:
/* #line 938 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_literal_zval(PHVOLT_T_FALSE, NULL, status->scanner_state);
  yy_destructor(53,&yymsp[0].minor);
}
/* #line 2399 "parser.c" */
        break;
      case 53:
      case 144:
/* #line 942 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_literal_zval(PHVOLT_T_TRUE, NULL, status->scanner_state);
  yy_destructor(54,&yymsp[0].minor);
}
/* #line 2408 "parser.c" */
        break;
      case 54:
/* #line 948 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_macro_call_statement(yymsp[-8].minor.yy92, yymsp[-6].minor.yy92, yymsp[-3].minor.yy92, status->scanner_state);
  yy_destructor(1,&yymsp[-10].minor);
  yy_destructor(55,&yymsp[-9].minor);
  yy_destructor(29,&yymsp[-7].minor);
  yy_destructor(47,&yymsp[-5].minor);
  yy_destructor(32,&yymsp[-4].minor);
  yy_destructor(1,&yymsp[-2].minor);
  yy_destructor(56,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
/* #line 2423 "parser.c" */
        break;
      case 55:
/* #line 952 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_macro_call_statement(yymsp[-6].minor.yy92, NULL, NULL, status->scanner_state);
  yy_destructor(1,&yymsp[-8].minor);
  yy_destructor(55,&yymsp[-7].minor);
  yy_destructor(29,&yymsp[-5].minor);
  yy_destructor(47,&yymsp[-4].minor);
  yy_destructor(32,&yymsp[-3].minor);
  yy_destructor(1,&yymsp[-2].minor);
  yy_destructor(56,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
/* #line 2438 "parser.c" */
        break;
      case 56:
/* #line 958 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_empty_statement(status->scanner_state);
  yy_destructor(1,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
/* #line 2447 "parser.c" */
        break;
      case 57:
/* #line 964 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_echo_statement(yymsp[-1].minor.yy92, status->scanner_state);
  yy_destructor(57,&yymsp[-2].minor);
  yy_destructor(58,&yymsp[0].minor);
}
/* #line 2456 "parser.c" */
        break;
      case 58:
/* #line 970 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_block_statement(yymsp[-5].minor.yy0, yymsp[-3].minor.yy92, status->scanner_state);
  yy_destructor(1,&yymsp[-7].minor);
  yy_destructor(59,&yymsp[-6].minor);
  yy_destructor(32,&yymsp[-4].minor);
  yy_destructor(1,&yymsp[-2].minor);
  yy_destructor(60,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
/* #line 2469 "parser.c" */
        break;
      case 59:
/* #line 974 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_block_statement(yymsp[-4].minor.yy0, NULL, status->scanner_state);
  yy_destructor(1,&yymsp[-6].minor);
  yy_destructor(59,&yymsp[-5].minor);
  yy_destructor(32,&yymsp[-3].minor);
  yy_destructor(1,&yymsp[-2].minor);
  yy_destructor(60,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
/* #line 2482 "parser.c" */
        break;
      case 60:
/* #line 980 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_cache_statement(yymsp[-5].minor.yy92, NULL, yymsp[-3].minor.yy92, status->scanner_state);
  yy_destructor(1,&yymsp[-7].minor);
  yy_destructor(61,&yymsp[-6].minor);
  yy_destructor(32,&yymsp[-4].minor);
  yy_destructor(1,&yymsp[-2].minor);
  yy_destructor(62,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
/* #line 2495 "parser.c" */
        break;
      case 61:
/* #line 984 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_cache_statement(yymsp[-6].minor.yy92, yymsp[-5].minor.yy0, yymsp[-3].minor.yy92, status->scanner_state);
  yy_destructor(1,&yymsp[-8].minor);
  yy_destructor(61,&yymsp[-7].minor);
  yy_destructor(32,&yymsp[-4].minor);
  yy_destructor(1,&yymsp[-2].minor);
  yy_destructor(62,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
/* #line 2508 "parser.c" */
        break;
      case 62:
/* #line 990 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_extends_statement(yymsp[-1].minor.yy0, status->scanner_state);
  yy_destructor(1,&yymsp[-3].minor);
  yy_destructor(63,&yymsp[-2].minor);
  yy_destructor(32,&yymsp[0].minor);
}
/* #line 2518 "parser.c" */
        break;
      case 63:
/* #line 996 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_include_statement(yymsp[-1].minor.yy92, NULL, status->scanner_state);
  yy_destructor(1,&yymsp[-3].minor);
  yy_destructor(64,&yymsp[-2].minor);
  yy_destructor(32,&yymsp[0].minor);
}
/* #line 2528 "parser.c" */
        break;
      case 64:
/* #line 1000 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_include_statement(yymsp[-3].minor.yy92, yymsp[-1].minor.yy92, status->scanner_state);
  yy_destructor(1,&yymsp[-5].minor);
  yy_destructor(64,&yymsp[-4].minor);
  yy_destructor(65,&yymsp[-2].minor);
  yy_destructor(32,&yymsp[0].minor);
}
/* #line 2539 "parser.c" */
        break;
      case 65:
/* #line 1006 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_do_statement(yymsp[-1].minor.yy92, status->scanner_state);
  yy_destructor(1,&yymsp[-3].minor);
  yy_destructor(66,&yymsp[-2].minor);
  yy_destructor(32,&yymsp[0].minor);
}
/* #line 2549 "parser.c" */
        break;
      case 66:
/* #line 1012 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_return_statement(yymsp[-1].minor.yy92, status->scanner_state);
  yy_destructor(1,&yymsp[-3].minor);
  yy_destructor(67,&yymsp[-2].minor);
  yy_destructor(32,&yymsp[0].minor);
}
/* #line 2559 "parser.c" */
        break;
      case 67:
/* #line 1018 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_autoescape_statement(0, yymsp[-3].minor.yy92, status->scanner_state);
  yy_destructor(1,&yymsp[-7].minor);
  yy_destructor(68,&yymsp[-6].minor);
  yy_destructor(53,&yymsp[-5].minor);
  yy_destructor(32,&yymsp[-4].minor);
  yy_destructor(1,&yymsp[-2].minor);
  yy_destructor(69,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
/* #line 2573 "parser.c" */
        break;
      case 68:
/* #line 1022 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_autoescape_statement(1, yymsp[-3].minor.yy92, status->scanner_state);
  yy_destructor(1,&yymsp[-7].minor);
  yy_destructor(68,&yymsp[-6].minor);
  yy_destructor(54,&yymsp[-5].minor);
  yy_destructor(32,&yymsp[-4].minor);
  yy_destructor(1,&yymsp[-2].minor);
  yy_destructor(69,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
/* #line 2587 "parser.c" */
        break;
      case 69:
/* #line 1028 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_break_statement(status->scanner_state);
  yy_destructor(1,&yymsp[-2].minor);
  yy_destructor(70,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
/* #line 2597 "parser.c" */
        break;
      case 70:
/* #line 1034 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_continue_statement(status->scanner_state);
  yy_destructor(1,&yymsp[-2].minor);
  yy_destructor(71,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
/* #line 2607 "parser.c" */
        break;
      case 71:
/* #line 1040 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_literal_zval(PHVOLT_T_RAW_FRAGMENT, yymsp[0].minor.yy0, status->scanner_state);
}
/* #line 2614 "parser.c" */
        break;
      case 72:
/* #line 1046 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_MINUS, NULL, yymsp[0].minor.yy92, NULL, status->scanner_state);
  yy_destructor(22,&yymsp[-1].minor);
}
/* #line 2622 "parser.c" */
        break;
      case 73:
/* #line 1050 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_PLUS, NULL, yymsp[0].minor.yy92, NULL, status->scanner_state);
  yy_destructor(21,&yymsp[-1].minor);
}
/* #line 2630 "parser.c" */
        break;
      case 74:
/* #line 1054 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_SUB, yymsp[-2].minor.yy92, yymsp[0].minor.yy92, NULL, status->scanner_state);
  yy_destructor(22,&yymsp[-1].minor);
}
/* #line 2638 "parser.c" */
        break;
      case 75:
/* #line 1058 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_ADD, yymsp[-2].minor.yy92, yymsp[0].minor.yy92, NULL, status->scanner_state);
  yy_destructor(21,&yymsp[-1].minor);
}
/* #line 2646 "parser.c" */
        break;
      case 76:
/* #line 1062 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_MUL, yymsp[-2].minor.yy92, yymsp[0].minor.yy92, NULL, status->scanner_state);
  yy_destructor(19,&yymsp[-1].minor);
}
/* #line 2654 "parser.c" */
        break;
      case 77:
/* #line 1066 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_POW, yymsp[-3].minor.yy92, yymsp[0].minor.yy92, NULL, status->scanner_state);
  yy_destructor(19,&yymsp[-2].minor);
  yy_destructor(19,&yymsp[-1].minor);
}
/* #line 2663 "parser.c" */
        break;
      case 78:
/* #line 1070 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_DIV, yymsp[-2].minor.yy92, yymsp[0].minor.yy92, NULL, status->scanner_state);
  yy_destructor(18,&yymsp[-1].minor);
}
/* #line 2671 "parser.c" */
        break;
      case 79:
/* #line 1074 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_MOD, yymsp[-3].minor.yy92, yymsp[0].minor.yy92, NULL, status->scanner_state);
  yy_destructor(18,&yymsp[-2].minor);
  yy_destructor(18,&yymsp[-1].minor);
}
/* #line 2680 "parser.c" */
        break;
      case 80:
/* #line 1078 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_MOD, yymsp[-2].minor.yy92, yymsp[0].minor.yy92, NULL, status->scanner_state);
  yy_destructor(20,&yymsp[-1].minor);
}
/* #line 2688 "parser.c" */
        break;
      case 81:
/* #line 1082 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_AND, yymsp[-2].minor.yy92, yymsp[0].minor.yy92, NULL, status->scanner_state);
  yy_destructor(7,&yymsp[-1].minor);
}
/* #line 2696 "parser.c" */
        break;
      case 82:
/* #line 1086 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_OR, yymsp[-2].minor.yy92, yymsp[0].minor.yy92, NULL, status->scanner_state);
  yy_destructor(8,&yymsp[-1].minor);
}
/* #line 2704 "parser.c" */
        break;
      case 83:
/* #line 1090 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_CONCAT, yymsp[-2].minor.yy92, yymsp[0].minor.yy92, NULL, status->scanner_state);
  yy_destructor(23,&yymsp[-1].minor);
}
/* #line 2712 "parser.c" */
        break;
      case 84:
/* #line 1094 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_PIPE, yymsp[-2].minor.yy92, yymsp[0].minor.yy92, NULL, status->scanner_state);
  yy_destructor(25,&yymsp[-1].minor);
}
/* #line 2720 "parser.c" */
        break;
      case 85:
/* #line 1098 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_RANGE, yymsp[-2].minor.yy92, yymsp[0].minor.yy92, NULL, status->scanner_state);
  yy_destructor(6,&yymsp[-1].minor);
}
/* #line 2728 "parser.c" */
        break;
      case 86:
/* #line 1102 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_EQUALS, yymsp[-2].minor.yy92, yymsp[0].minor.yy92, NULL, status->scanner_state);
  yy_destructor(10,&yymsp[-1].minor);
}
/* #line 2736 "parser.c" */
        break;
      case 87:
/* #line 1106 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_NOT_ISSET, yymsp[-3].minor.yy92, NULL, NULL, status->scanner_state);
  yy_destructor(9,&yymsp[-2].minor);
  yy_destructor(26,&yymsp[-1].minor);
  yy_destructor(73,&yymsp[0].minor);
}
/* #line 2746 "parser.c" */
        break;
      case 88:
/* #line 1110 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_ISSET, yymsp[-2].minor.yy92, NULL, NULL, status->scanner_state);
  yy_destructor(9,&yymsp[-1].minor);
  yy_destructor(73,&yymsp[0].minor);
}
/* #line 2755 "parser.c" */
        break;
      case 89:
/* #line 1114 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_NOT_ISEMPTY, yymsp[-3].minor.yy92, NULL, NULL, status->scanner_state);
  yy_destructor(9,&yymsp[-2].minor);
  yy_destructor(26,&yymsp[-1].minor);
  yy_destructor(74,&yymsp[0].minor);
}
/* #line 2765 "parser.c" */
        break;
      case 90:
/* #line 1118 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_ISEMPTY, yymsp[-2].minor.yy92, NULL, NULL, status->scanner_state);
  yy_destructor(9,&yymsp[-1].minor);
  yy_destructor(74,&yymsp[0].minor);
}
/* #line 2774 "parser.c" */
        break;
      case 91:
/* #line 1122 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_NOT_ISEVEN, yymsp[-3].minor.yy92, NULL, NULL, status->scanner_state);
  yy_destructor(9,&yymsp[-2].minor);
  yy_destructor(26,&yymsp[-1].minor);
  yy_destructor(75,&yymsp[0].minor);
}
/* #line 2784 "parser.c" */
        break;
      case 92:
/* #line 1126 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_ISEVEN, yymsp[-2].minor.yy92, NULL, NULL, status->scanner_state);
  yy_destructor(9,&yymsp[-1].minor);
  yy_destructor(75,&yymsp[0].minor);
}
/* #line 2793 "parser.c" */
        break;
      case 93:
/* #line 1130 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_NOT_ISODD, yymsp[-3].minor.yy92, NULL, NULL, status->scanner_state);
  yy_destructor(9,&yymsp[-2].minor);
  yy_destructor(26,&yymsp[-1].minor);
  yy_destructor(76,&yymsp[0].minor);
}
/* #line 2803 "parser.c" */
        break;
      case 94:
/* #line 1134 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_ISODD, yymsp[-2].minor.yy92, NULL, NULL, status->scanner_state);
  yy_destructor(9,&yymsp[-1].minor);
  yy_destructor(76,&yymsp[0].minor);
}
/* #line 2812 "parser.c" */
        break;
      case 95:
/* #line 1138 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_NOT_ISNUMERIC, yymsp[-3].minor.yy92, NULL, NULL, status->scanner_state);
  yy_destructor(9,&yymsp[-2].minor);
  yy_destructor(26,&yymsp[-1].minor);
  yy_destructor(77,&yymsp[0].minor);
}
/* #line 2822 "parser.c" */
        break;
      case 96:
/* #line 1142 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_ISNUMERIC, yymsp[-2].minor.yy92, NULL, NULL, status->scanner_state);
  yy_destructor(9,&yymsp[-1].minor);
  yy_destructor(77,&yymsp[0].minor);
}
/* #line 2831 "parser.c" */
        break;
      case 97:
/* #line 1146 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_NOT_ISSCALAR, yymsp[-3].minor.yy92, NULL, NULL, status->scanner_state);
  yy_destructor(9,&yymsp[-2].minor);
  yy_destructor(26,&yymsp[-1].minor);
  yy_destructor(78,&yymsp[0].minor);
}
/* #line 2841 "parser.c" */
        break;
      case 98:
/* #line 1150 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_ISSCALAR, yymsp[-2].minor.yy92, NULL, NULL, status->scanner_state);
  yy_destructor(9,&yymsp[-1].minor);
  yy_destructor(78,&yymsp[0].minor);
}
/* #line 2850 "parser.c" */
        break;
      case 99:
/* #line 1154 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_NOT_ISITERABLE, yymsp[-3].minor.yy92, NULL, NULL, status->scanner_state);
  yy_destructor(9,&yymsp[-2].minor);
  yy_destructor(26,&yymsp[-1].minor);
  yy_destructor(79,&yymsp[0].minor);
}
/* #line 2860 "parser.c" */
        break;
      case 100:
/* #line 1158 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_ISITERABLE, yymsp[-2].minor.yy92, NULL, NULL, status->scanner_state);
  yy_destructor(9,&yymsp[-1].minor);
  yy_destructor(79,&yymsp[0].minor);
}
/* #line 2869 "parser.c" */
        break;
      case 101:
/* #line 1162 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_IS, yymsp[-2].minor.yy92, yymsp[0].minor.yy92, NULL, status->scanner_state);
  yy_destructor(9,&yymsp[-1].minor);
}
/* #line 2877 "parser.c" */
        break;
      case 102:
/* #line 1166 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_NOTEQUALS, yymsp[-2].minor.yy92, yymsp[0].minor.yy92, NULL, status->scanner_state);
  yy_destructor(11,&yymsp[-1].minor);
}
/* #line 2885 "parser.c" */
        break;
      case 103:
/* #line 1170 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_IDENTICAL, yymsp[-2].minor.yy92, yymsp[0].minor.yy92, NULL, status->scanner_state);
  yy_destructor(16,&yymsp[-1].minor);
}
/* #line 2893 "parser.c" */
        break;
      case 104:
/* #line 1174 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_NOTIDENTICAL, yymsp[-2].minor.yy92, yymsp[0].minor.yy92, NULL, status->scanner_state);
  yy_destructor(17,&yymsp[-1].minor);
}
/* #line 2901 "parser.c" */
        break;
      case 105:
/* #line 1178 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_LESS, yymsp[-2].minor.yy92, yymsp[0].minor.yy92, NULL, status->scanner_state);
  yy_destructor(12,&yymsp[-1].minor);
}
/* #line 2909 "parser.c" */
        break;
      case 106:
/* #line 1182 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_GREATER, yymsp[-2].minor.yy92, yymsp[0].minor.yy92, NULL, status->scanner_state);
  yy_destructor(13,&yymsp[-1].minor);
}
/* #line 2917 "parser.c" */
        break;
      case 107:
/* #line 1186 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_GREATEREQUAL, yymsp[-2].minor.yy92, yymsp[0].minor.yy92, NULL, status->scanner_state);
  yy_destructor(14,&yymsp[-1].minor);
}
/* #line 2925 "parser.c" */
        break;
      case 108:
/* #line 1190 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_LESSEQUAL, yymsp[-2].minor.yy92, yymsp[0].minor.yy92, NULL, status->scanner_state);
  yy_destructor(15,&yymsp[-1].minor);
}
/* #line 2933 "parser.c" */
        break;
      case 109:
/* #line 1194 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_DOT, yymsp[-2].minor.yy92, yymsp[0].minor.yy92, NULL, status->scanner_state);
  yy_destructor(30,&yymsp[-1].minor);
}
/* #line 2941 "parser.c" */
        break;
      case 110:
/* #line 1198 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_IN, yymsp[-2].minor.yy92, yymsp[0].minor.yy92, NULL, status->scanner_state);
  yy_destructor(3,&yymsp[-1].minor);
}
/* #line 2949 "parser.c" */
        break;
      case 111:
/* #line 1202 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_NOT_IN, yymsp[-3].minor.yy92, yymsp[0].minor.yy92, NULL, status->scanner_state);
  yy_destructor(26,&yymsp[-2].minor);
  yy_destructor(3,&yymsp[-1].minor);
}
/* #line 2958 "parser.c" */
        break;
      case 112:
/* #line 1206 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_NOT, NULL, yymsp[0].minor.yy92, NULL, status->scanner_state);
  yy_destructor(26,&yymsp[-1].minor);
}
/* #line 2966 "parser.c" */
        break;
      case 113:
/* #line 1210 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_INCR, yymsp[-1].minor.yy92, NULL, NULL, status->scanner_state);
  yy_destructor(27,&yymsp[0].minor);
}
/* #line 2974 "parser.c" */
        break;
      case 114:
/* #line 1214 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_DECR, yymsp[-1].minor.yy92, NULL, NULL, status->scanner_state);
  yy_destructor(28,&yymsp[0].minor);
}
/* #line 2982 "parser.c" */
        break;
      case 115:
/* #line 1218 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_ENCLOSED, yymsp[-1].minor.yy92, NULL, NULL, status->scanner_state);
  yy_destructor(29,&yymsp[-2].minor);
  yy_destructor(47,&yymsp[0].minor);
}
/* #line 2991 "parser.c" */
        break;
      case 116:
/* #line 1222 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_ARRAY, NULL, NULL, NULL, status->scanner_state);
  yy_destructor(24,&yymsp[-1].minor);
  yy_destructor(80,&yymsp[0].minor);
}
/* #line 3000 "parser.c" */
        break;
      case 117:
/* #line 1226 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_ARRAY, yymsp[-1].minor.yy92, NULL, NULL, status->scanner_state);
  yy_destructor(24,&yymsp[-2].minor);
  yy_destructor(80,&yymsp[0].minor);
}
/* #line 3009 "parser.c" */
        break;
      case 118:
/* #line 1230 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_ARRAY, NULL, NULL, NULL, status->scanner_state);
  yy_destructor(81,&yymsp[-1].minor);
  yy_destructor(82,&yymsp[0].minor);
}
/* #line 3018 "parser.c" */
        break;
      case 119:
/* #line 1234 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_ARRAY, yymsp[-1].minor.yy92, NULL, NULL, status->scanner_state);
  yy_destructor(81,&yymsp[-2].minor);
  yy_destructor(82,&yymsp[0].minor);
}
/* #line 3027 "parser.c" */
        break;
      case 120:
/* #line 1238 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_ARRAYACCESS, yymsp[-3].minor.yy92, yymsp[-1].minor.yy92, NULL, status->scanner_state);
  yy_destructor(24,&yymsp[-2].minor);
  yy_destructor(80,&yymsp[0].minor);
}
/* #line 3036 "parser.c" */
        break;
      case 121:
/* #line 1242 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_expr(PHVOLT_T_TERNARY, yymsp[-2].minor.yy92, yymsp[0].minor.yy92, yymsp[-4].minor.yy92, status->scanner_state);
  yy_destructor(4,&yymsp[-3].minor);
  yy_destructor(5,&yymsp[-1].minor);
}
/* #line 3045 "parser.c" */
        break;
      case 122:
/* #line 1246 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_slice(yymsp[-4].minor.yy92, NULL, yymsp[-1].minor.yy92, status->scanner_state);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(5,&yymsp[-2].minor);
  yy_destructor(80,&yymsp[0].minor);
}
/* #line 3055 "parser.c" */
        break;
      case 123:
/* #line 1250 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_slice(yymsp[-4].minor.yy92, yymsp[-2].minor.yy92, NULL, status->scanner_state);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(5,&yymsp[-1].minor);
  yy_destructor(80,&yymsp[0].minor);
}
/* #line 3065 "parser.c" */
        break;
      case 124:
/* #line 1254 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_slice(yymsp[-5].minor.yy92, yymsp[-3].minor.yy92, yymsp[-1].minor.yy92, status->scanner_state);
  yy_destructor(24,&yymsp[-4].minor);
  yy_destructor(5,&yymsp[-2].minor);
  yy_destructor(80,&yymsp[0].minor);
}
/* #line 3075 "parser.c" */
        break;
      case 126:
      case 138:
/* #line 1264 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_literal_zval(PHVOLT_T_IDENTIFIER, yymsp[0].minor.yy0, status->scanner_state);
}
/* #line 3083 "parser.c" */
        break;
      case 129:
      case 137:
/* #line 1280 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_named_item(yymsp[-2].minor.yy0, yymsp[0].minor.yy92, status->scanner_state);
  yy_destructor(5,&yymsp[-1].minor);
}
/* #line 3092 "parser.c" */
        break;
      case 130:
      case 136:
/* #line 1284 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_named_item(NULL, yymsp[0].minor.yy92, status->scanner_state);
}
/* #line 3100 "parser.c" */
        break;
      case 132:
/* #line 1294 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_func_call(yymsp[-3].minor.yy92, yymsp[-1].minor.yy92, status->scanner_state);
  yy_destructor(29,&yymsp[-2].minor);
  yy_destructor(47,&yymsp[0].minor);
}
/* #line 3109 "parser.c" */
        break;
      case 133:
/* #line 1298 "parser.y" */
{
	yygotominor.yy92 = phvolt_ret_func_call(yymsp[-2].minor.yy92, NULL, status->scanner_state);
  yy_destructor(29,&yymsp[-1].minor);
  yy_destructor(47,&yymsp[0].minor);
}
/* #line 3118 "parser.c" */
        break;
  };
  yygoto = yyRuleInfo[yyruleno].lhs;
  yysize = yyRuleInfo[yyruleno].nrhs;
  yypParser->yyidx -= yysize;
  yyact = yy_find_reduce_action(yypParser,yygoto);
  if( yyact < YYNSTATE ){
    yy_shift(yypParser,yyact,yygoto,&yygotominor);
  }else if( yyact == YYNSTATE + YYNRULE + 1 ){
    yy_accept(yypParser);
  }
}

/*
** The following code executes when the parse fails
*/
static void yy_parse_failed(
  yyParser *yypParser           /* The parser */
){
  phvolt_ARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sFail!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser fails */
  phvolt_ARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following code executes when a syntax error first occurs.
*/
static void yy_syntax_error(
  yyParser *yypParser,           /* The parser */
  int yymajor,                   /* The major type of the error token */
  YYMINORTYPE yyminor            /* The minor type of the error token */
){
  phvolt_ARG_FETCH;
#define TOKEN (yyminor.yy0)
/* #line 599 "parser.y" */

	{

		smart_str error_str = {0};

		char *token_name = NULL;
		const phvolt_token_names *tokens = phvolt_tokens;
		int token_len = 0;
		uint active_token = status->scanner_state->active_token;

		if (status->scanner_state->start_length) {

			if (active_token) {

				do {
					if (tokens->code == active_token) {
						token_name = tokens->name;
						token_len = tokens->len;
						break;
					}
					++tokens;
				} while (tokens[0].code != 0);

			}

			smart_str_appendl(&error_str, "Syntax error, unexpected token ", sizeof("Syntax error, unexpected token ") - 1);
			if (!token_name) {
				smart_str_appendl(&error_str, "UNKNOWN", sizeof("UNKNOWN") - 1);
			} else {
				smart_str_appendl(&error_str, token_name, token_len);
			}
			if (status->token->value) {
				smart_str_appendc(&error_str, '(');
				smart_str_appendl(&error_str, status->token->value, status->token->len);
				smart_str_appendc(&error_str, ')');
			}
			smart_str_appendl(&error_str, " in ", sizeof(" in ") - 1);
			smart_str_appendl(&error_str, Z_STRVAL_P(status->scanner_state->active_file), Z_STRLEN_P(status->scanner_state->active_file));
			smart_str_appendl(&error_str, " on line ", sizeof(" on line ") - 1);
			{
				char stmp[MAX_LENGTH_OF_LONG + 1];
				int str_len;
				str_len = slprintf(stmp, sizeof(stmp), "%ld", status->scanner_state->active_line);
				smart_str_appendl(&error_str, stmp, str_len);
			}

		} else {

			smart_str_appendl(&error_str, "Syntax error, unexpected EOF in ", sizeof("Syntax error, unexpected EOF in ") - 1);
			smart_str_appendl(&error_str, Z_STRVAL_P(status->scanner_state->active_file), Z_STRLEN_P(status->scanner_state->active_file));

			/* Report unclosed 'if' blocks */
			if ((status->scanner_state->if_level + status->scanner_state->old_if_level) > 0) {
				if ((status->scanner_state->if_level + status->scanner_state->old_if_level) == 1) {
					smart_str_appendl(&error_str, ", there is one 'if' block without close", sizeof(", there is one 'if' block without close") - 1);
				} else {
					smart_str_appendl(&error_str, ", there are ", sizeof(", there are ") - 1);
					{
						char stmp[MAX_LENGTH_OF_LONG + 1];
						int str_len;
						str_len = slprintf(stmp, sizeof(stmp), "%ld", status->scanner_state->if_level + status->scanner_state->old_if_level);
						smart_str_appendl(&error_str, stmp, str_len);
					}
					smart_str_appendl(&error_str, " 'if' blocks without close", sizeof(" 'if' blocks without close") - 1);
				}
			}

			/* Report unclosed 'for' blocks */
			if (status->scanner_state->for_level > 0) {
				if (status->scanner_state->for_level == 1) {
					smart_str_appendl(&error_str, ", there is one 'for' block without close", sizeof(", there is one 'for' block without close") - 1);
				} else {
					smart_str_appendl(&error_str, ", there are ", sizeof(", there are ") - 1);
					{
						char stmp[MAX_LENGTH_OF_LONG + 1];
						int str_len;
						str_len = slprintf(stmp, sizeof(stmp), "%ld", status->scanner_state->if_level);
						smart_str_appendl(&error_str, stmp, str_len);
					}
					smart_str_appendl(&error_str, " 'for' blocks without close", sizeof(" 'for' blocks without close") - 1);
				}
			}
		}

		smart_str_0(&error_str);

		if (error_str.len) {
			status->syntax_error = error_str.c;
			status->syntax_error_len = error_str.len;
		} else {
			status->syntax_error = NULL;
		}

	}

	status->status = PHVOLT_PARSING_FAILED;

/* #line 3258 "parser.c" */
  phvolt_ARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following is executed when the parser accepts
*/
static void yy_accept(
  yyParser *yypParser           /* The parser */
){
  phvolt_ARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sAccept!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser accepts */
  phvolt_ARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/* The main parser program.
** The first argument is a pointer to a structure obtained from
** "phvolt_Alloc" which describes the current state of the parser.
** The second argument is the major token number.  The third is
** the minor token.  The fourth optional argument is whatever the
** user wants (and specified in the grammar) and is available for
** use by the action routines.
**
** Inputs:
** <ul>
** <li> A pointer to the parser (an opaque structure.)
** <li> The major token number.
** <li> The minor token number.
** <li> An option argument of a grammar-specified type.
** </ul>
**
** Outputs:
** None.
*/
void phvolt_(
  void *yyp,                   /* The parser */
  int yymajor,                 /* The major token code number */
  phvolt_TOKENTYPE yyminor       /* The value for the token */
  phvolt_ARG_PDECL               /* Optional %extra_argument parameter */
){
  YYMINORTYPE yyminorunion;
  int yyact;            /* The parser action. */
  int yyendofinput;     /* True if we are at the end of input */
  int yyerrorhit = 0;   /* True if yymajor has invoked an error */
  yyParser *yypParser;  /* The parser */

  /* (re)initialize the parser, if necessary */
  yypParser = (yyParser*)yyp;
  if( yypParser->yyidx<0 ){
    if( yymajor==0 ) return;
    yypParser->yyidx = 0;
    yypParser->yyerrcnt = -1;
    yypParser->yystack[0].stateno = 0;
    yypParser->yystack[0].major = 0;
  }
  yyminorunion.yy0 = yyminor;
  yyendofinput = (yymajor==0);
  phvolt_ARG_STORE;

#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sInput %s\n",yyTracePrompt,yyTokenName[yymajor]);
  }
#endif

  do{
    yyact = yy_find_shift_action(yypParser,yymajor);
    if( yyact<YYNSTATE ){
      yy_shift(yypParser,yyact,yymajor,&yyminorunion);
      yypParser->yyerrcnt--;
      if( yyendofinput && yypParser->yyidx>=0 ){
        yymajor = 0;
      }else{
        yymajor = YYNOCODE;
      }
    }else if( yyact < YYNSTATE + YYNRULE ){
      yy_reduce(yypParser,yyact-YYNSTATE);
    }else if( yyact == YY_ERROR_ACTION ){
      int yymx;
#ifndef NDEBUG
      if( yyTraceFILE ){
        fprintf(yyTraceFILE,"%sSyntax Error!\n",yyTracePrompt);
      }
#endif
#ifdef YYERRORSYMBOL
      /* A syntax error has occurred.
      ** The response to an error depends upon whether or not the
      ** grammar defines an error token "ERROR".  
      **
      ** This is what we do if the grammar does define ERROR:
      **
      **  * Call the %syntax_error function.
      **
      **  * Begin popping the stack until we enter a state where
      **    it is legal to shift the error symbol, then shift
      **    the error symbol.
      **
      **  * Set the error count to three.
      **
      **  * Begin accepting and shifting new tokens.  No new error
      **    processing will occur until three tokens have been
      **    shifted successfully.
      **
      */
      if( yypParser->yyerrcnt<0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion);
      }
      yymx = yypParser->yystack[yypParser->yyidx].major;
      if( yymx==YYERRORSYMBOL || yyerrorhit ){
#ifndef NDEBUG
        if( yyTraceFILE ){
          fprintf(yyTraceFILE,"%sDiscard input token %s\n",
             yyTracePrompt,yyTokenName[yymajor]);
        }
#endif
        yy_destructor(yymajor,&yyminorunion);
        yymajor = YYNOCODE;
      }else{
         while(
          yypParser->yyidx >= 0 &&
          yymx != YYERRORSYMBOL &&
          (yyact = yy_find_shift_action(yypParser,YYERRORSYMBOL)) >= YYNSTATE
        ){
          yy_pop_parser_stack(yypParser);
        }
        if( yypParser->yyidx < 0 || yymajor==0 ){
          yy_destructor(yymajor,&yyminorunion);
          yy_parse_failed(yypParser);
          yymajor = YYNOCODE;
        }else if( yymx!=YYERRORSYMBOL ){
          YYMINORTYPE u2;
          u2.YYERRSYMDT = 0;
          yy_shift(yypParser,yyact,YYERRORSYMBOL,&u2);
        }
      }
      yypParser->yyerrcnt = 3;
      yyerrorhit = 1;
#else  /* YYERRORSYMBOL is not defined */
      /* This is what we do if the grammar does not define ERROR:
      **
      **  * Report an error message, and throw away the input token.
      **
      **  * If the input token is $, then fail the parse.
      **
      ** As before, subsequent error messages are suppressed until
      ** three input tokens have been successfully shifted.
      */
      if( yypParser->yyerrcnt<=0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion);
      }
      yypParser->yyerrcnt = 3;
      yy_destructor(yymajor,&yyminorunion);
      if( yyendofinput ){
        yy_parse_failed(yypParser);
      }
      yymajor = YYNOCODE;
#endif
    }else{
      yy_accept(yypParser);
      yymajor = YYNOCODE;
    }
  }while( yymajor!=YYNOCODE && yypParser->yyidx>=0 );
  return;
}

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

const phvolt_token_names phvolt_tokens[] =
{
  { SL("INTEGER"),        PHVOLT_T_INTEGER },
  { SL("DOUBLE"),         PHVOLT_T_DOUBLE },
  { SL("STRING"),         PHVOLT_T_STRING },
  { SL("IDENTIFIER"),     PHVOLT_T_IDENTIFIER },
  { SL("MINUS"),          PHVOLT_T_MINUS },
  { SL("+"),              PHVOLT_T_ADD },
  { SL("-"),              PHVOLT_T_SUB },
  { SL("*"),              PHVOLT_T_MUL },
  { SL("/"),              PHVOLT_T_DIV },
  { SL("%%"),             PHVOLT_T_MOD },
  { SL("!"),              PHVOLT_T_NOT },
  { SL("~"),              PHVOLT_T_CONCAT },
  { SL("AND"),            PHVOLT_T_AND },
  { SL("OR"),             PHVOLT_T_OR },
  { SL("DOT"),            PHVOLT_T_DOT },
  { SL("COMMA"),          PHVOLT_T_COMMA },
  { SL("EQUALS"),         PHVOLT_T_EQUALS },
  { SL("NOT EQUALS"),     PHVOLT_T_NOTEQUALS },
  { SL("IDENTICAL"),      PHVOLT_T_IDENTICAL },
  { SL("NOT IDENTICAL"),  PHVOLT_T_NOTIDENTICAL },
  { SL("NOT"),            PHVOLT_T_NOT },
  { SL("RANGE"),          PHVOLT_T_RANGE },
  { SL("COLON"),          PHVOLT_T_COLON },
  { SL("QUESTION MARK"),  PHVOLT_T_QUESTION },
  { SL("<"),              PHVOLT_T_LESS },
  { SL("<="),             PHVOLT_T_LESSEQUAL },
  { SL(">"),              PHVOLT_T_GREATER },
  { SL(">="),             PHVOLT_T_GREATEREQUAL },
  { SL("("),              PHVOLT_T_PARENTHESES_OPEN },
  { SL(")"),              PHVOLT_T_PARENTHESES_CLOSE },
  { SL("["),              PHVOLT_T_SBRACKET_OPEN },
  { SL("]"),              PHVOLT_T_SBRACKET_CLOSE },
  { SL("{"),              PHVOLT_T_CBRACKET_OPEN },
  { SL("}"),              PHVOLT_T_CBRACKET_CLOSE },
  { SL("{%"),             PHVOLT_T_OPEN_DELIMITER },
  { SL("%}"),             PHVOLT_T_CLOSE_DELIMITER },
  { SL("{{"),             PHVOLT_T_OPEN_EDELIMITER },
  { SL("}}"),             PHVOLT_T_CLOSE_EDELIMITER },
  { SL("IF"),             PHVOLT_T_IF },
  { SL("ELSE"),           PHVOLT_T_ELSE },
  { SL("ELSEIF"),         PHVOLT_T_ELSEIF },
  { SL("ELSEFOR"),        PHVOLT_T_ELSEFOR },
  { SL("ENDIF"),          PHVOLT_T_ENDIF },
  { SL("FOR"),            PHVOLT_T_FOR },
  { SL("IN"),             PHVOLT_T_IN },
  { SL("ENDFOR"),         PHVOLT_T_ENDFOR },
  { SL("SET"),            PHVOLT_T_SET },
  { SL("ASSIGN"),         PHVOLT_T_ASSIGN },
  { SL("+="),             PHVOLT_T_ADD_ASSIGN },
  { SL("-="),             PHVOLT_T_SUB_ASSIGN },
  { SL("*="),             PHVOLT_T_MUL_ASSIGN },
  { SL("/="),             PHVOLT_T_DIV_ASSIGN },
  { SL("++"),             PHVOLT_T_INCR },
  { SL("--"),             PHVOLT_T_DECR },
  { SL("BLOCK"),          PHVOLT_T_BLOCK },
  { SL("ENDBLOCK"),       PHVOLT_T_ENDBLOCK },
  { SL("CACHE"),          PHVOLT_T_CACHE },
  { SL("ENDCACHE"),       PHVOLT_T_ENDCACHE },
  { SL("EXTENDS"),        PHVOLT_T_EXTENDS },
  { SL("IS"),             PHVOLT_T_IS },
  { SL("DEFINED"),        PHVOLT_T_DEFINED },
  { SL("EMPTY"),          PHVOLT_T_EMPTY },
  { SL("EVEN"),           PHVOLT_T_EVEN },
  { SL("ODD"),            PHVOLT_T_ODD },
  { SL("NUMERIC"),        PHVOLT_T_NUMERIC },
  { SL("SCALAR"),         PHVOLT_T_SCALAR },
  { SL("ITERABLE"),       PHVOLT_T_ITERABLE },
  { SL("INCLUDE"),        PHVOLT_T_INCLUDE },
  { SL("DO"),             PHVOLT_T_DO },
  { SL("WHITESPACE"),     PHVOLT_T_IGNORE },
  { SL("AUTOESCAPE"),     PHVOLT_T_AUTOESCAPE },
  { SL("ENDAUTOESCAPE"),  PHVOLT_T_ENDAUTOESCAPE },
  { SL("CONTINUE"),       PHVOLT_T_CONTINUE },
  { SL("BREAK"),          PHVOLT_T_BREAK },
  { SL("WITH"),           PHVOLT_T_WITH },
  { SL("RETURN"),         PHVOLT_T_RETURN },
  { SL("MACRO"),          PHVOLT_T_MACRO },
  { SL("ENDMACRO"),       PHVOLT_T_ENDMACRO },
  { SL("CALL"),           PHVOLT_T_CALL },
  { SL("WITH"),           PHVOLT_T_WITH },
  { NULL, 0, 0 }
};

/**
 * Wrapper to alloc memory within the parser
 */
static void *phvolt_wrapper_alloc(size_t bytes){
	return emalloc(bytes);
}

/**
 * Wrapper to free memory within the parser
 */
static void phvolt_wrapper_free(void *pointer){
	efree(pointer);
}

/**
 * Creates a parser_token to be passed to the parser
 */
static void phvolt_parse_with_token(void* phvolt_parser, int opcode, int parsercode, phvolt_scanner_token *token, phvolt_parser_status *parser_status){

	phvolt_parser_token *pToken;

	pToken = emalloc(sizeof(phvolt_parser_token));
	pToken->opcode = opcode;
	pToken->token = token->value;
	pToken->token_len = token->len;
	pToken->free_flag = 1;

	phvolt_(phvolt_parser, parsercode, pToken, parser_status);

	token->value = NULL;
	token->len = 0;
}

/**
 * Creates an error message
 */
static void phvolt_create_error_msg(phvolt_parser_status *parser_status, char *message){

	unsigned int length = (128 + Z_STRLEN_P(parser_status->scanner_state->active_file));
	char *str = emalloc(sizeof(char) * length);

	snprintf(str, length, "%s in %s on line %d", message, Z_STRVAL_P(parser_status->scanner_state->active_file), parser_status->scanner_state->active_line);
	str[length - 1] = '\0';

	parser_status->syntax_error = estrndup(str, strlen(str));
	efree(str);
}

/**
 * Creates an error message when it's triggered by the scanner
 */
static void phvolt_scanner_error_msg(phvolt_parser_status *parser_status, zval **error_msg TSRMLS_DC){

	char *error, *error_part;
	int length;
	phvolt_scanner_state *state = parser_status->scanner_state;

	MAKE_STD_ZVAL(*error_msg);
	if (state->start) {
		error = emalloc(sizeof(char) * 72 + state->start_length +  Z_STRLEN_P(state->active_file));
		if (state->start_length > 16) {
			length = 72 + Z_STRLEN_P(state->active_file);
			error_part = estrndup(state->start, 16);
			snprintf(error, length, "Scanning error before '%s...' in %s on line %d", error_part, Z_STRVAL_P(state->active_file), state->active_line);
			error[length - 1] = '\0';
		} else {
			length = 48 + state->start_length + Z_STRLEN_P(state->active_file);
			snprintf(error, length, "Scanning error before '%s' in %s on line %d", state->start, Z_STRVAL_P(state->active_file), state->active_line);
		}
	} else {
		error = emalloc(sizeof(char) * (32 + Z_STRLEN_P(state->active_file)));
		length = 32 + Z_STRLEN_P(state->active_file);
		snprintf(error, length, "Scanning error near to EOF in %s", Z_STRVAL_P(state->active_file));
	}

	error[length - 1] = '\0';
	ZVAL_STRING(*error_msg, error, 1);
	efree(error);
}

/**
 * Receives the volt code tokenizes and parses it
 */
int phvolt_parse_view(zval *result, zval *view_code, zval *template_path TSRMLS_DC){

	zval *error_msg = NULL;

	ZVAL_NULL(result);

	if (Z_TYPE_P(view_code) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "View code must be a string");
		return FAILURE;
	}

	if (phvolt_internal_parse_view(&result, view_code, template_path, &error_msg TSRMLS_CC) == FAILURE) {
		if (likely(error_msg != NULL)) {
			PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_view_exception_ce, Z_STRVAL_P(error_msg));
			zval_ptr_dtor(&error_msg);
		}
		else {
			PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_view_exception_ce, "Error parsing the view");
		}

		return FAILURE;
	}

	return SUCCESS;
}

/**
 * Checks whether the token has only blank characters
 */
int phvolt_is_blank_string(phvolt_scanner_token *token){

	char *marker = token->value;
	int i;

	for (i = 0; i < token->len; i++) {
		char ch = *marker;
		if (ch != ' ' && ch != '\t' && ch != '\n' && ch != '\r' && ch != 11) {
			return 0;
		}
		marker++;
	}

	return 1;
}

/**
 * Parses a volt template returning an intermediate array representation
 */
int phvolt_internal_parse_view(zval **result, zval *view_code, zval *template_path, zval **error_msg TSRMLS_DC) {

	char *error;
	phvolt_scanner_state *state;
	phvolt_scanner_token token;
	int scanner_status, status = SUCCESS;
	phvolt_parser_status *parser_status = NULL;
	void* phvolt_parser;

	/** Check if the view has code */
	if (!Z_STRVAL_P(view_code)) {
		MAKE_STD_ZVAL(*error_msg);
		ZVAL_STRING(*error_msg, "View code cannot be null", 1);
		return FAILURE;
	}

	if (!Z_STRLEN_P(view_code)) {
		array_init(*result);
		return SUCCESS;
	}

	/** Start the reentrant parser */
	phvolt_parser = phvolt_Alloc(phvolt_wrapper_alloc);
	if (unlikely(!phvolt_parser)) {
		MAKE_STD_ZVAL(*error_msg);
		ZVAL_STRING(*error_msg, "Memory allocation error", 1);
		return FAILURE;
	}

	parser_status = emalloc(sizeof(phvolt_parser_status));
	state = emalloc(sizeof(phvolt_scanner_state));

	parser_status->status = PHVOLT_PARSING_OK;
	parser_status->scanner_state = state;
	parser_status->ret = NULL;
	parser_status->token = &token;
	parser_status->syntax_error = NULL;

	/** Initialize the scanner state */
	state->active_token = 0;
	state->start = Z_STRVAL_P(view_code);
	state->mode = PHVOLT_MODE_RAW;
	state->raw_buffer = emalloc(sizeof(char) * PHVOLT_RAW_BUFFER_SIZE);
	state->raw_buffer_size = PHVOLT_RAW_BUFFER_SIZE;
	state->raw_buffer_cursor = 0;
	state->active_file = template_path;
	state->active_line = 1;
	state->statement_position = 0;
	state->extends_mode = 0;
	state->block_level = 0;
	state->macro_level = 0;
	state->start_length = 0;
	state->old_if_level = 0;
	state->if_level = 0;
	state->for_level = 0;
	state->whitespace_control = 0;

	state->end = state->start;

	token.value = NULL;
	token.len = 0;

	while (0 <= (scanner_status = phvolt_get_token(state, &token))) {

		state->active_token = token.opcode;

		state->start_length = (Z_STRVAL_P(view_code) + Z_STRLEN_P(view_code) - state->start);

		switch (token.opcode) {

			case PHVOLT_T_IGNORE:
				break;

			case PHVOLT_T_ADD:
				phvolt_(phvolt_parser, PHVOLT_PLUS, NULL, parser_status);
				break;
			case PHVOLT_T_SUB:
				phvolt_(phvolt_parser, PHVOLT_MINUS, NULL, parser_status);
				break;
			case PHVOLT_T_MUL:
				phvolt_(phvolt_parser, PHVOLT_TIMES, NULL, parser_status);
				break;
			case PHVOLT_T_DIV:
				phvolt_(phvolt_parser, PHVOLT_DIVIDE, NULL, parser_status);
				break;
			case PHVOLT_T_MOD:
				phvolt_(phvolt_parser, PHVOLT_MOD, NULL, parser_status);
				break;
			case PHVOLT_T_AND:
				phvolt_(phvolt_parser, PHVOLT_AND, NULL, parser_status);
				break;
			case PHVOLT_T_OR:
				phvolt_(phvolt_parser, PHVOLT_OR, NULL, parser_status);
				break;
			case PHVOLT_T_IS:
				phvolt_(phvolt_parser, PHVOLT_IS, NULL, parser_status);
				break;
			case PHVOLT_T_EQUALS:
				phvolt_(phvolt_parser, PHVOLT_EQUALS, NULL, parser_status);
				break;
			case PHVOLT_T_NOTEQUALS:
				phvolt_(phvolt_parser, PHVOLT_NOTEQUALS, NULL, parser_status);
				break;
			case PHVOLT_T_LESS:
				phvolt_(phvolt_parser, PHVOLT_LESS, NULL, parser_status);
				break;
			case PHVOLT_T_GREATER:
				phvolt_(phvolt_parser, PHVOLT_GREATER, NULL, parser_status);
				break;
			case PHVOLT_T_GREATEREQUAL:
				phvolt_(phvolt_parser, PHVOLT_GREATEREQUAL, NULL, parser_status);
				break;
			case PHVOLT_T_LESSEQUAL:
				phvolt_(phvolt_parser, PHVOLT_LESSEQUAL, NULL, parser_status);
				break;
			case PHVOLT_T_IDENTICAL:
				phvolt_(phvolt_parser, PHVOLT_IDENTICAL, NULL, parser_status);
				break;
			case PHVOLT_T_NOTIDENTICAL:
				phvolt_(phvolt_parser, PHVOLT_NOTIDENTICAL, NULL, parser_status);
				break;
			case PHVOLT_T_NOT:
				phvolt_(phvolt_parser, PHVOLT_NOT, NULL, parser_status);
				break;
			case PHVOLT_T_DOT:
				phvolt_(phvolt_parser, PHVOLT_DOT, NULL, parser_status);
				break;
			case PHVOLT_T_CONCAT:
				phvolt_(phvolt_parser, PHVOLT_CONCAT, NULL, parser_status);
				break;
			case PHVOLT_T_RANGE:
				phvolt_(phvolt_parser, PHVOLT_RANGE, NULL, parser_status);
				break;
			case PHVOLT_T_PIPE:
				phvolt_(phvolt_parser, PHVOLT_PIPE, NULL, parser_status);
				break;
			case PHVOLT_T_COMMA:
				phvolt_(phvolt_parser, PHVOLT_COMMA, NULL, parser_status);
				break;
			case PHVOLT_T_COLON:
				phvolt_(phvolt_parser, PHVOLT_COLON, NULL, parser_status);
				break;
			case PHVOLT_T_QUESTION:
				phvolt_(phvolt_parser, PHVOLT_QUESTION, NULL, parser_status);
				break;

			case PHVOLT_T_PARENTHESES_OPEN:
				phvolt_(phvolt_parser, PHVOLT_PARENTHESES_OPEN, NULL, parser_status);
				break;
			case PHVOLT_T_PARENTHESES_CLOSE:
				phvolt_(phvolt_parser, PHVOLT_PARENTHESES_CLOSE, NULL, parser_status);
				break;
			case PHVOLT_T_SBRACKET_OPEN:
				phvolt_(phvolt_parser, PHVOLT_SBRACKET_OPEN, NULL, parser_status);
				break;
			case PHVOLT_T_SBRACKET_CLOSE:
				phvolt_(phvolt_parser, PHVOLT_SBRACKET_CLOSE, NULL, parser_status);
				break;
			case PHVOLT_T_CBRACKET_OPEN:
				phvolt_(phvolt_parser, PHVOLT_CBRACKET_OPEN, NULL, parser_status);
				break;
			case PHVOLT_T_CBRACKET_CLOSE:
				phvolt_(phvolt_parser, PHVOLT_CBRACKET_CLOSE, NULL, parser_status);
				break;

			case PHVOLT_T_OPEN_DELIMITER:
				phvolt_(phvolt_parser, PHVOLT_OPEN_DELIMITER, NULL, parser_status);
				break;
			case PHVOLT_T_CLOSE_DELIMITER:
				phvolt_(phvolt_parser, PHVOLT_CLOSE_DELIMITER, NULL, parser_status);
				break;

			case PHVOLT_T_OPEN_EDELIMITER:
				if (state->extends_mode == 1 && state->block_level == 0) {
					phvolt_create_error_msg(parser_status, "Child templates only may contain blocks");
					parser_status->status = PHVOLT_PARSING_FAILED;
					break;
				}
				phvolt_(phvolt_parser, PHVOLT_OPEN_EDELIMITER, NULL, parser_status);
				break;
			case PHVOLT_T_CLOSE_EDELIMITER:
				phvolt_(phvolt_parser, PHVOLT_CLOSE_EDELIMITER, NULL, parser_status);
				break;

			case PHVOLT_T_NULL:
				phvolt_(phvolt_parser, PHVOLT_NULL, NULL, parser_status);
				break;
			case PHVOLT_T_TRUE:
				phvolt_(phvolt_parser, PHVOLT_TRUE, NULL, parser_status);
				break;
			case PHVOLT_T_FALSE:
				phvolt_(phvolt_parser, PHVOLT_FALSE, NULL, parser_status);
				break;

			case PHVOLT_T_INTEGER:
				phvolt_parse_with_token(phvolt_parser, PHVOLT_T_INTEGER, PHVOLT_INTEGER, &token, parser_status);
				break;
			case PHVOLT_T_DOUBLE:
				phvolt_parse_with_token(phvolt_parser, PHVOLT_T_DOUBLE, PHVOLT_DOUBLE, &token, parser_status);
				break;
			case PHVOLT_T_STRING:
				phvolt_parse_with_token(phvolt_parser, PHVOLT_T_STRING, PHVOLT_STRING, &token, parser_status);
				break;
			case PHVOLT_T_IDENTIFIER:
				phvolt_parse_with_token(phvolt_parser, PHVOLT_T_IDENTIFIER, PHVOLT_IDENTIFIER, &token, parser_status);
				break;

			case PHVOLT_T_IF:
				if (state->extends_mode == 1 && state->block_level == 0){
					phvolt_create_error_msg(parser_status, "Child templates only may contain blocks");
					parser_status->status = PHVOLT_PARSING_FAILED;
					break;
				} else {
					state->if_level++;
					state->block_level++;
				}
				phvolt_(phvolt_parser, PHVOLT_IF, NULL, parser_status);
				break;

			case PHVOLT_T_ELSE:
				if (state->if_level == 0 && state->for_level > 0) {
					phvolt_(phvolt_parser, PHVOLT_ELSEFOR, NULL, parser_status);
				} else {
					phvolt_(phvolt_parser, PHVOLT_ELSE, NULL, parser_status);
				}
				break;

			case PHVOLT_T_ELSEFOR:
				phvolt_(phvolt_parser, PHVOLT_ELSEFOR, NULL, parser_status);
				break;

			case PHVOLT_T_ELSEIF:
				if (state->if_level == 0) {
					phvolt_create_error_msg(parser_status, "Unexpected ENDIF");
					parser_status->status = PHVOLT_PARSING_FAILED;
					break;
				}
				phvolt_(phvolt_parser, PHVOLT_ELSEIF, NULL, parser_status);
				break;

			case PHVOLT_T_ENDIF:
				state->block_level--;
				state->if_level--;
				phvolt_(phvolt_parser, PHVOLT_ENDIF, NULL, parser_status);
				break;

			case PHVOLT_T_FOR:
				if (state->extends_mode == 1 && state->block_level == 0){
					phvolt_create_error_msg(parser_status, "Child templates only may contain blocks");
					parser_status->status = PHVOLT_PARSING_FAILED;
					break;
				} else {
					state->old_if_level = state->if_level;
					state->if_level = 0;
					state->for_level++;
					state->block_level++;
				}
				phvolt_(phvolt_parser, PHVOLT_FOR, NULL, parser_status);
				break;

			case PHVOLT_T_IN:
				phvolt_(phvolt_parser, PHVOLT_IN, NULL, parser_status);
				break;

			case PHVOLT_T_ENDFOR:
				state->block_level--;
				state->for_level--;
				state->if_level = state->old_if_level;
				phvolt_(phvolt_parser, PHVOLT_ENDFOR, NULL, parser_status);
				break;

			case PHVOLT_T_RAW_FRAGMENT:
				if (token.len > 0) {
					if (state->extends_mode == 1 && state->block_level == 0){
						if (!phvolt_is_blank_string(&token)) {
							phvolt_create_error_msg(parser_status, "Child templates only may contain blocks");
							parser_status->status = PHVOLT_PARSING_FAILED;
						}
						efree(token.value);
						break;
					} else {
						if (!phvolt_is_blank_string(&token)) {
							state->statement_position++;
						}
					}
					phvolt_parse_with_token(phvolt_parser, PHVOLT_T_RAW_FRAGMENT, PHVOLT_RAW_FRAGMENT, &token, parser_status);
				} else {
					efree(token.value);
				}
				break;

			case PHVOLT_T_SET:
				if (state->extends_mode == 1 && state->block_level == 0){
					phvolt_create_error_msg(parser_status, "Child templates only may contain blocks");
					parser_status->status = PHVOLT_PARSING_FAILED;
					break;
				}
				phvolt_(phvolt_parser, PHVOLT_SET, NULL, parser_status);
				break;
			case PHVOLT_T_ASSIGN:
				phvolt_(phvolt_parser, PHVOLT_ASSIGN, NULL, parser_status);
				break;
			case PHVOLT_T_ADD_ASSIGN:
				phvolt_(phvolt_parser, PHVOLT_ADD_ASSIGN, NULL, parser_status);
				break;
			case PHVOLT_T_SUB_ASSIGN:
				phvolt_(phvolt_parser, PHVOLT_SUB_ASSIGN, NULL, parser_status);
				break;
			case PHVOLT_T_MUL_ASSIGN:
				phvolt_(phvolt_parser, PHVOLT_MUL_ASSIGN, NULL, parser_status);
				break;
			case PHVOLT_T_DIV_ASSIGN:
				phvolt_(phvolt_parser, PHVOLT_DIV_ASSIGN, NULL, parser_status);
				break;

			case PHVOLT_T_INCR:
				phvolt_(phvolt_parser, PHVOLT_INCR, NULL, parser_status);
				break;
			case PHVOLT_T_DECR:
				phvolt_(phvolt_parser, PHVOLT_DECR, NULL, parser_status);
				break;

			case PHVOLT_T_BLOCK:
				if (state->block_level > 0) {
					phvolt_create_error_msg(parser_status, "Embedding blocks into other blocks is not supported");
					parser_status->status = PHVOLT_PARSING_FAILED;
					break;
				} else {
					state->block_level++;
				}
				phvolt_(phvolt_parser, PHVOLT_BLOCK, NULL, parser_status);
				break;
			case PHVOLT_T_ENDBLOCK:
				state->block_level--;
				phvolt_(phvolt_parser, PHVOLT_ENDBLOCK, NULL, parser_status);
				break;

			case PHVOLT_T_MACRO:
				if (state->macro_level > 0) {
					phvolt_create_error_msg(parser_status, "Embedding macros into other macros is not allowed");
					parser_status->status = PHVOLT_PARSING_FAILED;
					break;
				} else {
					state->macro_level++;
				}
				phvolt_(phvolt_parser, PHVOLT_MACRO, NULL, parser_status);
				break;
			case PHVOLT_T_ENDMACRO:
				state->macro_level--;
				phvolt_(phvolt_parser, PHVOLT_ENDMACRO, NULL, parser_status);
				break;

			case PHVOLT_T_CALL:
				phvolt_(phvolt_parser, PHVOLT_CALL, NULL, parser_status);
				break;
			case PHVOLT_T_ENDCALL:
				phvolt_(phvolt_parser, PHVOLT_ENDCALL, NULL, parser_status);
				break;

			case PHVOLT_T_CACHE:
				phvolt_(phvolt_parser, PHVOLT_CACHE, NULL, parser_status);
				break;
			case PHVOLT_T_ENDCACHE:
				phvolt_(phvolt_parser, PHVOLT_ENDCACHE, NULL, parser_status);
				break;

			case PHVOLT_T_INCLUDE:
				phvolt_(phvolt_parser, PHVOLT_INCLUDE, NULL, parser_status);
				break;

			case PHVOLT_T_WITH:
				phvolt_(phvolt_parser, PHVOLT_WITH, NULL, parser_status);
				break;

			case PHVOLT_T_DEFINED:
				phvolt_(phvolt_parser, PHVOLT_DEFINED, NULL, parser_status);
				break;

			case PHVOLT_T_EMPTY:
				phvolt_(phvolt_parser, PHVOLT_EMPTY, NULL, parser_status);
				break;

			case PHVOLT_T_EVEN:
				phvolt_(phvolt_parser, PHVOLT_EVEN, NULL, parser_status);
				break;

			case PHVOLT_T_ODD:
				phvolt_(phvolt_parser, PHVOLT_ODD, NULL, parser_status);
				break;

			case PHVOLT_T_NUMERIC:
				phvolt_(phvolt_parser, PHVOLT_NUMERIC, NULL, parser_status);
				break;

			case PHVOLT_T_SCALAR:
				phvolt_(phvolt_parser, PHVOLT_SCALAR, NULL, parser_status);
				break;

			case PHVOLT_T_ITERABLE:
				phvolt_(phvolt_parser, PHVOLT_ITERABLE, NULL, parser_status);
				break;

			case PHVOLT_T_DO:
				phvolt_(phvolt_parser, PHVOLT_DO, NULL, parser_status);
				break;
			case PHVOLT_T_RETURN:
				phvolt_(phvolt_parser, PHVOLT_RETURN, NULL, parser_status);
				break;

			case PHVOLT_T_AUTOESCAPE:
				phvolt_(phvolt_parser, PHVOLT_AUTOESCAPE, NULL, parser_status);
				break;

			case PHVOLT_T_ENDAUTOESCAPE:
				phvolt_(phvolt_parser, PHVOLT_ENDAUTOESCAPE, NULL, parser_status);
				break;

			case PHVOLT_T_BREAK:
				phvolt_(phvolt_parser, PHVOLT_BREAK, NULL, parser_status);
				break;

			case PHVOLT_T_CONTINUE:
				phvolt_(phvolt_parser, PHVOLT_CONTINUE, NULL, parser_status);
				break;

			case PHVOLT_T_EXTENDS:
				if (state->statement_position != 1) {
					phvolt_create_error_msg(parser_status, "Extends statement must be placed at the first line in the template");
					parser_status->status = PHVOLT_PARSING_FAILED;
					break;
				} else {
					state->extends_mode = 1;
				}
				phvolt_(phvolt_parser, PHVOLT_EXTENDS, NULL, parser_status);
				break;

			default:
				parser_status->status = PHVOLT_PARSING_FAILED;
				if (!*error_msg) {
					error = emalloc(sizeof(char) * (48 + Z_STRLEN_P(state->active_file)));
					snprintf(error, 48 + Z_STRLEN_P(state->active_file) + state->active_line, "Scanner: unknown opcode %d on in %s line %d", token.opcode, Z_STRVAL_P(state->active_file), state->active_line);
					MAKE_STD_ZVAL(*error_msg);
					ZVAL_STRING(*error_msg, error, 1);
					efree(error);
				}
				break;
		}

		if (parser_status->status != PHVOLT_PARSING_OK) {
			status = FAILURE;
			break;
		}

		state->end = state->start;
	}

	if (status != FAILURE) {
		switch (scanner_status) {
			case PHVOLT_SCANNER_RETCODE_ERR:
			case PHVOLT_SCANNER_RETCODE_IMPOSSIBLE:
				if (!*error_msg) {
					phvolt_scanner_error_msg(parser_status, error_msg TSRMLS_CC);
				}
				status = FAILURE;
				break;
			default:
				phvolt_(phvolt_parser, 0, NULL, parser_status);
		}
	}

	state->active_token = 0;
	state->start = NULL;
	efree(state->raw_buffer);

	if (parser_status->status != PHVOLT_PARSING_OK) {
		status = FAILURE;
		if (parser_status->syntax_error) {
			if (!*error_msg) {
				MAKE_STD_ZVAL(*error_msg);
				ZVAL_STRING(*error_msg, parser_status->syntax_error, 1);
			}
			efree(parser_status->syntax_error);
		}
	}

	phvolt_Free(phvolt_parser, phvolt_wrapper_free);

	if (status != FAILURE) {
		if (parser_status->status == PHVOLT_PARSING_OK) {
			if (parser_status->ret) {
				ZVAL_ZVAL(*result, parser_status->ret, 0, 0);
				ZVAL_NULL(parser_status->ret);
				zval_ptr_dtor(&parser_status->ret);
			} else {
				array_init(*result);
			}
		}
	}

	efree(parser_status);
	efree(state);

	return status;
}
