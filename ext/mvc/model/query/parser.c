/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is include which follows the "include" declaration
** in the input file. */
#include <stdio.h>
/* #line 40 "parser.y" */


#include "php_phalcon.h"

#include "mvc/model/query/parser.h"
#include "mvc/model/query/scanner.h"
#include "mvc/model/query/phql.h"
#include "mvc/model/exception.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/array.h"

#include "kernel/framework/orm.h"

#include "interned-strings.h"

static zval *phql_ret_literal_zval(int type, phql_parser_token *T)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 2);
	add_assoc_long(ret, phalcon_interned_type, type);
	if (T) {
		add_assoc_stringl(ret, phalcon_interned_value, T->token, T->token_len, 0);
		efree(T);
	}

	return ret;
}

static zval *phql_ret_placeholder_zval(int type, phql_parser_token *T)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 2);
	add_assoc_long(ret, phalcon_interned_type, type);
	add_assoc_stringl(ret, phalcon_interned_value, T->token, T->token_len, 0);
	efree(T);

	return ret;
}

static zval *phql_ret_qualified_name(phql_parser_token *A, phql_parser_token *B, phql_parser_token *C)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	add_assoc_long(ret, phalcon_interned_type, PHQL_T_QUALIFIED);

	if (A != NULL) {
		add_assoc_stringl(ret, phalcon_interned_ns_alias, A->token, A->token_len, 0);
		efree(A);
	}

	if (B != NULL) {
		add_assoc_stringl(ret, phalcon_interned_domain, B->token, B->token_len, 0);
		efree(B);
	}

	add_assoc_stringl(ret, phalcon_interned_name, C->token, C->token_len, 0);
	efree(C);

	return ret;
}

static zval *phql_ret_raw_qualified_name(phql_parser_token *A, phql_parser_token *B)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	add_assoc_long(ret, phalcon_interned_type, PHQL_T_RAW_QUALIFIED);
	if (B != NULL) {
		add_assoc_stringl(ret, phalcon_interned_domain, A->token, A->token_len, 0);
		add_assoc_stringl(ret, phalcon_interned_name, B->token, B->token_len, 0);
		efree(B);
	} else {
		add_assoc_stringl(ret, phalcon_interned_name, A->token, A->token_len, 0);
	}
	efree(A);

	return ret;
}

static zval *phql_ret_select_statement(zval *S, zval *W, zval *O, zval *G, zval *H, zval *L, zval *F)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	add_assoc_long(ret, phalcon_interned_type, PHQL_T_SELECT);
	add_assoc_zval(ret, phalcon_interned_select, S);

	if (W != NULL) {
		add_assoc_zval(ret, phalcon_interned_where, W);
	}
	if (O != NULL) {
		add_assoc_zval(ret, phalcon_interned_orderBy, O);
	}
	if (G != NULL) {
		add_assoc_zval(ret, phalcon_interned_groupBy, G);
	}
	if (H != NULL) {
		add_assoc_zval(ret, phalcon_interned_having, H);
	}
	if (L != NULL) {
		add_assoc_zval(ret, phalcon_interned_limit, L);
	}
	if (F != NULL) {
		add_assoc_zval(ret, phalcon_interned_forupdate, F);
	}

	return ret;
}

static zval *phql_ret_select_clause(zval *distinct, zval *columns, zval *tables, zval *join_list)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 4);

	if (distinct) {
		add_assoc_zval(ret, phalcon_interned_distinct, distinct);
	}

	add_assoc_zval(ret, phalcon_interned_columns, columns);
	add_assoc_zval(ret, phalcon_interned_tables, tables);
	if (join_list) {
		add_assoc_zval(ret, phalcon_interned_joins, join_list);
	}

	return ret;
}

static zval *phql_ret_distinct_all(int distinct)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	ZVAL_LONG(ret, distinct);

	return ret;
}

static zval *phql_ret_distinct(void)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	ZVAL_TRUE(ret);

	return ret;
}

static zval *phql_ret_order_item(zval *column, int sort){

	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_zval(ret, phalcon_interned_column, column);
	if (sort != 0 ) {
		add_assoc_long(ret, phalcon_interned_sort, sort);
	}

	return ret;
}

static zval *phql_ret_limit_clause(zval *L, zval *O)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 2);

	add_assoc_zval(ret, phalcon_interned_number, L);

	if (O != NULL) {
		add_assoc_zval(ret, phalcon_interned_offset, O);
	}

	return ret;
}

static zval *phql_ret_forupdate_clause()
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	ZVAL_TRUE(ret);

	return ret;
}

static zval *phql_ret_insert_statement(zval *Q, zval *F, zval *V)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 4);

	add_assoc_long(ret, phalcon_interned_type, PHQL_T_INSERT);
	add_assoc_zval(ret, phalcon_interned_qualifiedName, Q);
	if (F != NULL) {
		add_assoc_zval(ret, phalcon_interned_fields, F);
	}
	add_assoc_zval(ret, phalcon_interned_values, V);

	return ret;
}

static zval *phql_ret_insert_statement2(zval *ret, zval *F, zval *V)
{
	zval *key1, *key2, *rows, *values;

	MAKE_STD_ZVAL(key1);
	ZVAL_STRING(key1, phalcon_interned_rows, 1);

	MAKE_STD_ZVAL(rows);
	if (!phalcon_array_isset_fetch(&rows, ret, key1)) {
		array_init_size(rows, 1);		

		MAKE_STD_ZVAL(key2);
		ZVAL_STRING(key2, phalcon_interned_values, 1);

		MAKE_STD_ZVAL(values);
		if (phalcon_array_isset_fetch(&values, ret, key2)) {
			Z_ADDREF_P(values);
			add_next_index_zval(rows, values);	
		}
	}

	add_next_index_zval(rows, V);
	Z_ADDREF_P(rows);
	add_assoc_zval(ret, phalcon_interned_rows, rows);

	return ret;
}

static zval *phql_ret_update_statement(zval *U, zval *W, zval *L)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	add_assoc_long(ret, phalcon_interned_type, PHQL_T_UPDATE);
	add_assoc_zval(ret, phalcon_interned_update, U);
	if (W != NULL) {
		add_assoc_zval(ret, phalcon_interned_where, W);
	}
	if (L != NULL) {
		add_assoc_zval(ret, phalcon_interned_limit, L);
	}

	return ret;
}

static zval *phql_ret_update_clause(zval *tables, zval *values)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 2);
	add_assoc_zval(ret, phalcon_interned_tables, tables);
	add_assoc_zval(ret, phalcon_interned_values, values);

	return ret;
}

static zval *phql_ret_update_item(zval *column, zval *expr)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 2);
	add_assoc_zval(ret, phalcon_interned_column, column);
	add_assoc_zval(ret, phalcon_interned_expr, expr);

	return ret;
}

static zval *phql_ret_delete_statement(zval *D, zval *W, zval *L)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	add_assoc_long(ret, phalcon_interned_type, PHQL_T_DELETE);
	add_assoc_zval(ret, phalcon_interned_delete, D);
	if (W != NULL) {
		add_assoc_zval(ret, phalcon_interned_where, W);
	}
	if (L != NULL) {
		add_assoc_zval(ret, phalcon_interned_limit, L);
	}

	return ret;
}

static zval *phql_ret_delete_clause(zval *tables)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 1);
	add_assoc_zval(ret, phalcon_interned_tables, tables);

	return ret;
}

static zval *phql_ret_zval_list(zval *list_left, zval *right_list)
{
	zval *ret;
	HashTable *list;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	list = Z_ARRVAL_P(list_left);
	if (zend_hash_index_exists(list, 0)) {
		HashPosition pos;
		zval **item;

		for (
			zend_hash_internal_pointer_reset_ex(list, &pos);
			zend_hash_get_current_data_ex(list, (void**)&item, &pos) != FAILURE;
			zend_hash_move_forward_ex(list, &pos)
		) {
			Z_ADDREF_PP(item);
			add_next_index_zval(ret, *item);
		}

		zval_ptr_dtor(&list_left);
	} else {
		add_next_index_zval(ret, list_left);
	}

	if (right_list) {
		add_next_index_zval(ret, right_list);
	}

	return ret;
}

static zval *phql_ret_column_item(int type, zval *column, phql_parser_token *identifier_column, phql_parser_token *alias)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 4);
	add_assoc_long(ret, phalcon_interned_type, type);
	if (column) {
		add_assoc_zval(ret, phalcon_interned_column, column);
	}
	if (identifier_column) {
		add_assoc_stringl(ret, phalcon_interned_column, identifier_column->token, identifier_column->token_len, 0);
		efree(identifier_column);
	}
	if (alias) {
		add_assoc_stringl(ret, phalcon_interned_alias, alias->token, alias->token_len, 0);
		efree(alias);
	}

	return ret;
}

static zval *phql_ret_assoc_name(zval *qualified_name, phql_parser_token *alias)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 2);
	add_assoc_zval(ret, phalcon_interned_qualifiedName, qualified_name);
	if (alias) {
		add_assoc_stringl(ret, phalcon_interned_alias, alias->token, alias->token_len, 0);
		efree(alias);
	}

	return ret;
}

static zval *phql_ret_join_type(int type)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	ZVAL_LONG(ret, type);

	return ret;
}

static zval *phql_ret_join_item(zval *type, zval *qualified, zval *alias, zval *conditions)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 4);
	add_assoc_zval(ret, phalcon_interned_type, type);

	if (qualified) {
		add_assoc_zval(ret, phalcon_interned_qualified, qualified);
	}

	if (alias) {
		add_assoc_zval(ret, phalcon_interned_alias, alias);
	}

	if (conditions) {
		add_assoc_zval(ret, phalcon_interned_conditions, conditions);
	}

	return ret;
}

static zval *phql_ret_expr(int type, zval *left, zval *right)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 2);
	add_assoc_long(ret, phalcon_interned_type, type);
	if (left) {
		add_assoc_zval(ret, phalcon_interned_left, left);
	}
	if (right) {
		add_assoc_zval(ret, phalcon_interned_right, right);
	}

	return ret;
}

static zval *phql_ret_func_call(phql_parser_token *name, zval *arguments, zval *distinct)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 4);
	add_assoc_long(ret, phalcon_interned_type, PHQL_T_FCALL);
	add_assoc_stringl(ret, phalcon_interned_name, name->token, name->token_len, 0);
	efree(name);

	if (arguments) {
		add_assoc_zval(ret, phalcon_interned_arguments, arguments);
	}
	
	if (distinct) {
		add_assoc_zval(ret, phalcon_interned_distinct, distinct);
	}

	return ret;
}


/* #line 474 "parser.c" */
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
**    phql_TOKENTYPE     is the data type used for minor tokens given 
**                       directly to the parser from the tokenizer.
**    YYMINORTYPE        is the data type used for all minor tokens.
**                       This is typically a union of many types, one of
**                       which is phql_TOKENTYPE.  The entry in the union
**                       for base tokens is called "yy0".
**    YYSTACKDEPTH       is the maximum depth of the parser's stack.
**    phql_ARG_SDECL     A static variable declaration for the %extra_argument
**    phql_ARG_PDECL     A parameter declaration for the %extra_argument
**    phql_ARG_STORE     Code to store %extra_argument into yypParser
**    phql_ARG_FETCH     Code to extract %extra_argument from yypParser
**    YYNSTATE           the combined number of states.
**    YYNRULE            the number of rules in the grammar
**    YYERRORSYMBOL      is the code number of the error symbol.  If not
**                       defined, then do no error processing.
*/
#define YYCODETYPE unsigned char
#define YYNOCODE 139
#define YYACTIONTYPE unsigned short int
#define phql_TOKENTYPE phql_parser_token*
typedef union {
  phql_TOKENTYPE yy0;
  zval* yy204;
  int yy277;
} YYMINORTYPE;
#define YYSTACKDEPTH 100
#define phql_ARG_SDECL phql_parser_status *status;
#define phql_ARG_PDECL ,phql_parser_status *status
#define phql_ARG_FETCH phql_parser_status *status = yypParser->status
#define phql_ARG_STORE yypParser->status = status
#define YYNSTATE 294
#define YYNRULE 161
#define YYERRORSYMBOL 86
#define YYERRSYMDT yy277
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
 /*     0 */    92,   98,   32,   34,   36,   38,   40,   54,   42,   44,
 /*    10 */    46,   48,   50,   52,   22,   24,   56,   61,   26,   28,
 /*    20 */    30,   18,   16,   20,   14,   11,   94,   63,   58,   32,
 /*    30 */    34,   36,   38,   40,   54,   42,   44,   46,   48,   50,
 /*    40 */    52,   22,   24,   56,   61,   26,   28,   30,   18,   16,
 /*    50 */    20,   14,   11,   94,   63,   58,  294,   90,   91,   92,
 /*    60 */    98,   32,   34,   36,   38,   40,   54,   42,   44,   46,
 /*    70 */    48,   50,   52,   22,   24,   56,   61,   26,   28,   30,
 /*    80 */    18,   16,   20,   14,   11,   94,   63,   58,   92,   98,
 /*    90 */    32,   34,   36,   38,   40,   54,   42,   44,   46,   48,
 /*   100 */    50,   52,   22,   24,   56,   61,   26,   28,   30,   18,
 /*   110 */    16,   20,   14,   11,   94,   63,   58,   14,   11,   94,
 /*   120 */    63,   58,  106,  218,  295,  216,  121,  207,  123,  124,
 /*   130 */    94,   63,   58,  151,  112,  184,  110,   92,   98,   32,
 /*   140 */    34,   36,   38,   40,   54,   42,   44,   46,   48,   50,
 /*   150 */    52,   22,   24,   56,   61,   26,   28,   30,   18,   16,
 /*   160 */    20,   14,   11,   94,   63,   58,   18,   16,   20,   14,
 /*   170 */    11,   94,   63,   58,  137,    5,   92,   98,   32,   34,
 /*   180 */    36,   38,   40,   54,   42,   44,   46,   48,   50,   52,
 /*   190 */    22,   24,   56,   61,   26,   28,   30,   18,   16,   20,
 /*   200 */    14,   11,   94,   63,   58,   92,   98,   32,   34,   36,
 /*   210 */    38,   40,   54,   42,   44,   46,   48,   50,   52,   22,
 /*   220 */    24,   56,   61,   26,   28,   30,   18,   16,   20,   14,
 /*   230 */    11,   94,   63,   58,   56,   61,   26,   28,   30,   18,
 /*   240 */    16,   20,   14,   11,   94,   63,   58,  143,   96,   92,
 /*   250 */    98,   32,   34,   36,   38,   40,   54,   42,   44,   46,
 /*   260 */    48,   50,   52,   22,   24,   56,   61,   26,   28,   30,
 /*   270 */    18,   16,   20,   14,   11,   94,   63,   58,  220,  221,
 /*   280 */   153,   22,   24,   56,   61,   26,   28,   30,   18,   16,
 /*   290 */    20,   14,   11,   94,   63,   58,  223,   95,   92,   98,
 /*   300 */    32,   34,   36,   38,   40,   54,   42,   44,   46,   48,
 /*   310 */    50,   52,   22,   24,   56,   61,   26,   28,   30,   18,
 /*   320 */    16,   20,   14,   11,   94,   63,   58,  165,  149,  151,
 /*   330 */    12,  184,   76,  166,  168,  197,  101,   89,  195,  107,
 /*   340 */   156,   78,   79,   80,   81,   59,  242,  190,  206,  192,
 /*   350 */   194,  100,  198,  202,  165,  170,  244,   12,   86,  226,
 /*   360 */   166,  168,  201,  108,   82,  199,  155,  156,  109,  171,
 /*   370 */   172,  178,  179,  130,  134,  140,  296,  146,  100,  428,
 /*   380 */   113,   58,  175,  173,  174,  176,  177,  180,  181,  190,
 /*   390 */   206,  192,  194,  119,  198,  202,  171,  172,  178,  179,
 /*   400 */   130,  134,  140,  157,  146,  125,  213,    4,   64,  175,
 /*   410 */   173,  174,  176,  177,  180,  181,  157,  113,  119,   42,
 /*   420 */    44,   46,   48,   50,   52,   22,   24,   56,   61,   26,
 /*   430 */    28,   30,   18,   16,   20,   14,   11,   94,   63,   58,
 /*   440 */    12,  115,    8,  166,  168,  159,  101,  163,  210,  215,
 /*   450 */   156,  122,  123,  124,  115,  209,  224,  104,  256,    7,
 /*   460 */    65,  100,  211,  170,  427,   12,  115,  170,  166,  168,
 /*   470 */   113,  162,  222,  250,  155,  212,  160,  182,  155,  171,
 /*   480 */   172,  178,  179,  130,  134,  140,  100,  146,  282,  283,
 /*   490 */   170,  170,  175,  173,  174,  176,  177,  180,  181,  236,
 /*   500 */   205,  155,  155,  203,  171,  172,  178,  179,  130,  134,
 /*   510 */   140,  240,  146,   66,  229,   65,  101,  175,  173,  174,
 /*   520 */   176,  177,  180,  181,  280,  287,  283,  159,  165,  214,
 /*   530 */   189,   12,  187,  254,  166,  168,  277,   10,  291,  105,
 /*   540 */   132,  156,  120,  208,   65,  170,    6,  103,  109,  251,
 /*   550 */   219,  215,  100,  238,   67,  170,  155,  227,   12,  182,
 /*   560 */   113,  166,  168,  148,  186,   68,  155,   84,  156,  170,
 /*   570 */   171,  172,  178,  179,  130,  134,  140,  159,  146,  100,
 /*   580 */   155,   74,   72,  175,  173,  174,  176,  177,  180,  181,
 /*   590 */   163,  278,   69,   75,   77,  170,  109,  171,  172,  178,
 /*   600 */   179,  130,  134,  140,   73,  146,  155,  239,  113,  164,
 /*   610 */   175,  173,  174,  176,  177,  180,  181,   26,   28,   30,
 /*   620 */    18,   16,   20,   14,   11,   94,   63,   58,  163,  456,
 /*   630 */     1,    2,    3,  252,  253,   65,  375,    8,   70,   13,
 /*   640 */    71,  234,  248,  261,   10,  247,   65,  257,   85,  268,
 /*   650 */    83,   10,  262,   89,  260,  271,    9,  170,  159,  170,
 /*   660 */   259,  272,  170,  251,  231,  235,  263,  288,  155,  170,
 /*   670 */   155,  170,   87,  155,   10,   88,  170,  234,  286,   97,
 /*   680 */   155,   15,  155,  266,  246,    8,  251,  155,  117,  114,
 /*   690 */   182,   17,  170,   19,   21,  170,  170,  285,  275,  170,
 /*   700 */   102,  233,  267,  155,  111,  126,  155,  155,   23,  170,
 /*   710 */   155,  170,  170,  116,  118,   25,   27,   29,   31,  128,
 /*   720 */   155,   33,  155,  155,   35,   37,  170,  127,  120,  133,
 /*   730 */    39,   41,  131,  170,  170,  170,  170,  155,   43,  170,
 /*   740 */    45,  101,  170,  170,  155,  155,  155,  155,  170,  170,
 /*   750 */   155,  138,   47,  155,  155,  135,  170,   49,  170,  155,
 /*   760 */   155,  141,   51,  144,   53,   55,   57,  155,  293,  155,
 /*   770 */   170,   60,  139,  109,   62,  170,  145,  150,  183,   93,
 /*   780 */   170,  155,  170,  170,  170,  113,  155,   99,  129,  170,
 /*   790 */   158,  155,  170,  155,  155,  155,  136,  170,  161,  188,
 /*   800 */   155,  142,  147,  155,  191,  170,  170,  322,  155,  152,
 /*   810 */   193,  323,  196,  324,  170,  154,  155,  155,  167,  170,
 /*   820 */   170,  169,  185,  228,  237,  155,  325,  170,  243,  200,
 /*   830 */   155,  155,  326,  170,  327,  204,  170,  328,  155,  170,
 /*   840 */   170,  170,  170,  329,  155,  330,  170,  155,  217,  230,
 /*   850 */   155,  155,  155,  155,  225,  232,  241,  155,  245,  297,
 /*   860 */   298,  249,  258,  270,  255,  265,  269,  264,  273,  274,
 /*   870 */   342,  276,  374,  279,  281,  289,  284,  290,  348,  292,
};
static YYCODETYPE yy_lookahead[] = {
 /*     0 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    10 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*    20 */    21,   22,   23,   24,   25,   26,   27,   28,   29,    3,
 /*    30 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*    40 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*    50 */    24,   25,   26,   27,   28,   29,    0,   58,   59,    1,
 /*    60 */     2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*    70 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*    80 */    22,   23,   24,   25,   26,   27,   28,   29,    1,    2,
 /*    90 */     3,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   100 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   110 */    23,   24,   25,   26,   27,   28,   29,   25,   26,   27,
 /*   120 */    28,   29,  103,   36,    0,   38,  107,  108,  109,  110,
 /*   130 */    27,   28,   29,   75,   36,   77,   38,    1,    2,    3,
 /*   140 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   150 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   160 */    24,   25,   26,   27,   28,   29,   22,   23,   24,   25,
 /*   170 */    26,   27,   28,   29,   38,   47,    1,    2,    3,    4,
 /*   180 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   190 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   24,
 /*   200 */    25,   26,   27,   28,   29,    1,    2,    3,    4,    5,
 /*   210 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   220 */    16,   17,   18,   19,   20,   21,   22,   23,   24,   25,
 /*   230 */    26,   27,   28,   29,   17,   18,   19,   20,   21,   22,
 /*   240 */    23,   24,   25,   26,   27,   28,   29,   72,   29,    1,
 /*   250 */     2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   260 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   270 */    22,   23,   24,   25,   26,   27,   28,   29,   34,   35,
 /*   280 */    76,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   290 */    24,   25,   26,   27,   28,   29,   48,   78,    1,    2,
 /*   300 */     3,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   310 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   320 */    23,   24,   25,   26,   27,   28,   29,   23,   74,   75,
 /*   330 */    26,   77,   31,   29,   30,   40,   32,  105,   43,   31,
 /*   340 */    36,   65,   66,   67,   68,   17,   18,   39,   40,   41,
 /*   350 */    42,   47,   44,   45,   23,  123,   28,   26,  126,  127,
 /*   360 */    29,   30,   40,  106,   63,   43,  134,   36,  111,   65,
 /*   370 */    66,   67,   68,   69,   70,   71,    0,   73,   47,   48,
 /*   380 */   123,   29,   78,   79,   80,   81,   82,   83,   84,   39,
 /*   390 */    40,   41,   42,   37,   44,   45,   65,   66,   67,   68,
 /*   400 */    69,   70,   71,   47,   73,  111,   37,   31,   47,   78,
 /*   410 */    79,   80,   81,   82,   83,   84,   47,  123,   37,    9,
 /*   420 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   430 */    20,   21,   22,   23,   24,   25,   26,   27,   28,   29,
 /*   440 */    26,   85,   31,   29,   30,  105,   32,   31,  104,  105,
 /*   450 */    36,  108,  109,  110,   85,   31,   89,   33,  111,   48,
 /*   460 */    93,   47,   23,  123,   48,   26,   85,  123,   29,   30,
 /*   470 */   123,  131,  105,  105,  134,   36,  136,  137,  134,   65,
 /*   480 */    66,   67,   68,   69,   70,   71,   47,   73,  122,  123,
 /*   490 */   123,  123,   78,   79,   80,   81,   82,   83,   84,   55,
 /*   500 */    40,  134,  134,   43,   65,   66,   67,   68,   69,   70,
 /*   510 */    71,   89,   73,   94,   60,   93,   32,   78,   79,   80,
 /*   520 */    81,   82,   83,   84,  121,  122,  123,  105,   23,   23,
 /*   530 */    36,   26,   38,   49,   29,   30,   52,  105,   54,  102,
 /*   540 */    89,   36,   36,  106,   93,  123,  114,  101,  111,  117,
 /*   550 */   104,  105,   47,  131,   95,  123,  134,   61,   26,  137,
 /*   560 */   123,   29,   30,  132,  133,   96,  134,   56,   36,  123,
 /*   570 */    65,   66,   67,   68,   69,   70,   71,  105,   73,   47,
 /*   580 */   134,   62,   64,   78,   79,   80,   81,   82,   83,   84,
 /*   590 */    31,  106,   97,  130,  130,  123,  111,   65,   66,   67,
 /*   600 */    68,   69,   70,   71,   52,   73,  134,   48,  123,  137,
 /*   610 */    78,   79,   80,   81,   82,   83,   84,   19,   20,   21,
 /*   620 */    22,   23,   24,   25,   26,   27,   28,   29,   31,   87,
 /*   630 */    88,   89,   90,   91,   92,   93,    0,   31,   98,  105,
 /*   640 */    99,  105,   89,   47,  105,   48,   93,   51,   57,   31,
 /*   650 */   130,  105,  115,  105,   48,  118,  117,  123,  105,  123,
 /*   660 */   114,  119,  123,  117,  128,  129,   48,  125,  134,  123,
 /*   670 */   134,  123,   31,  134,  105,  127,  123,  105,  105,   78,
 /*   680 */   134,  105,  134,  114,  131,   31,  117,  134,   37,   36,
 /*   690 */   137,  105,  123,  105,  105,  123,  123,  124,   62,  123,
 /*   700 */   100,  129,   48,  134,   36,  112,  134,  134,  105,  123,
 /*   710 */   134,  123,  123,   36,   36,  105,  105,  105,  105,   46,
 /*   720 */   134,  105,  134,  134,  105,  105,  123,  113,   36,   48,
 /*   730 */   105,  105,   47,  123,  123,  123,  123,  134,  105,  123,
 /*   740 */   105,   32,  123,  123,  134,  134,  134,  134,  123,  123,
 /*   750 */   134,   36,  105,  134,  134,   47,  123,  105,  123,  134,
 /*   760 */   134,   47,  105,   36,  105,  105,  105,  134,  106,  134,
 /*   770 */   123,  105,   48,  111,  105,  123,   48,  133,   34,  105,
 /*   780 */   123,  134,  123,  123,  123,  123,  134,  105,  105,  123,
 /*   790 */   135,  134,  123,  134,  134,  134,  105,  123,   48,   36,
 /*   800 */   134,  105,  105,  134,   40,  123,  123,   36,  134,  105,
 /*   810 */    40,   36,   40,   36,  123,  105,  134,  134,  105,  123,
 /*   820 */   123,  105,  105,  105,  105,  134,   36,  123,  105,   40,
 /*   830 */   134,  134,   36,  123,   36,   40,  123,   36,  134,  123,
 /*   840 */   123,  123,  123,   36,  134,   36,  123,  134,   36,   57,
 /*   850 */   134,  134,  134,  134,   48,   31,   48,  134,   47,    0,
 /*   860 */     0,   48,   47,   36,   50,   47,  118,   51,   94,  120,
 /*   870 */     0,  130,    0,   53,   31,   94,    3,  120,    0,   33,
};
#define YY_SHIFT_USE_DFLT (-2)
static short yy_shift_ofst[] = {
 /*     0 */   484,   56,  124,  376,  128,  532,  411,   -2,  532,   -2,
 /*    10 */   297,  532,  532,  103,  532,  103,  532,   92,  532,   92,
 /*    20 */   532,   92,  532,  217,  532,  217,  532,  144,  532,  144,
 /*    30 */   532,  144,  532,  410,  532,  410,  532,  410,  532,  410,
 /*    40 */   532,  410,  532,  266,  532,  266,  532,  266,  532,  266,
 /*    50 */   532,  266,  532,  266,  532,  410,  532,  598,  328,  532,
 /*    60 */   352,  532,  598,  361,  304,  444,  454,  496,  511,  519,
 /*    70 */   518,   -2,  552,   -2,  276,  301,  276,   -2,   -2,   -2,
 /*    80 */    -2,   -2,  276,   -2,  591,  532,  641,  532,   -2,   -1,
 /*    90 */    -2,   -2,  532,  297,  219,   -2,  601,   -2,  532,   26,
 /*   100 */   414,  244,  439,  424,  653,  308,   -2,  653,   -2,   98,
 /*   110 */   668,   -2,   -2,   -2,  381,  677,  651,  678,   -2,  692,
 /*   120 */    -2,  350,   -2,   -2,  653,  494,  673,   -2,  532,  297,
 /*   130 */   685,  709,  681,   -2,  708,  532,  136,  715,  724,   -2,
 /*   140 */   714,  532,  175,  727,  728,   -2,  532,   58,  254,   -2,
 /*   150 */    -2,  532,  204,  532,  297,   -2,  356,  744,  331,  297,
 /*   160 */   750,   -2,  416,  505,   -2,   -2,  532,  352,  532,  352,
 /*   170 */    -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,
 /*   180 */    -2,   -2,   -2,   -2,  532,  297,   -2,  763,   -2,   -2,
 /*   190 */   764,  771,  770,  775,  295,  772,  777,  790,  322,  789,
 /*   200 */   796,  798,  460,  795,  801,  807,  809,   -2,   -2,  439,
 /*   210 */    -2,   -2,  369,  506,   -2,   87,  812,   -2,   -2,   -2,
 /*   220 */    -2,   -2,  248,   -2,  806,   -2,   -2,  532,  297,  792,
 /*   230 */   532,  824,  532,   -2,  297,   -2,  532,  297,  559,   -2,
 /*   240 */   808,   -2,  532,  352,  811,  304,  597,   -2,  813,   -2,
 /*   250 */   103,   -2,  859,  860,  814,  653,  596,  815,  532,  606,
 /*   260 */    -2,  827,  618,  816,  818,  532,  654,   -2,  827,   -2,
 /*   270 */    -2,   -2,  444,  636,  870,  276,  872,  653,  820,  653,
 /*   280 */   843,  653,   -2,  873,  532,   -2,  297,   -2,  444,  636,
 /*   290 */   878,  846,  653,   -2,
};
#define YY_REDUCE_USE_DFLT (-1)
static short yy_reduce_ofst[] = {
 /*     0 */   542,   -1,   -1,   -1,   -1,  432,   -1,   -1,  539,   -1,
 /*    10 */    -1,  368,  534,   -1,  576,   -1,  586,   -1,  588,   -1,
 /*    20 */   589,   -1,  603,   -1,  610,   -1,  611,   -1,  612,   -1,
 /*    30 */   613,   -1,  616,   -1,  619,   -1,  620,   -1,  625,   -1,
 /*    40 */   626,   -1,  633,   -1,  635,   -1,  647,   -1,  652,   -1,
 /*    50 */   657,   -1,  659,   -1,  660,   -1,  661,   -1,   -1,  666,
 /*    60 */    -1,  669,   -1,   -1,  422,  419,  459,  469,  495,  540,
 /*    70 */   541,   -1,   -1,   -1,  463,   -1,  464,   -1,   -1,   -1,
 /*    80 */    -1,   -1,  520,   -1,   -1,  232,   -1,  548,   -1,   -1,
 /*    90 */    -1,   -1,  674,   -1,   -1,   -1,   -1,   -1,  682,   -1,
 /*   100 */   367,  600,  446,   -1,  437,   19,   -1,  257,   -1,   -1,
 /*   110 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   120 */    -1,  343,   -1,   -1,  294,  593,  614,   -1,  683,   -1,
 /*   130 */    -1,  451,   -1,   -1,   -1,  691,   -1,   -1,   -1,   -1,
 /*   140 */    -1,  696,   -1,   -1,   -1,   -1,  697,  431,  644,   -1,
 /*   150 */    -1,  704,   -1,  710,   -1,   -1,   -1,  655,  340,   -1,
 /*   160 */    -1,   -1,   -1,  472,   -1,   -1,  713,   -1,  716,   -1,
 /*   170 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   180 */    -1,   -1,   -1,   -1,  717,   -1,   -1,   -1,   -1,   -1,
 /*   190 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   200 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  344,
 /*   210 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   220 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,  718,   -1,   -1,
 /*   230 */   536,   -1,  572,   -1,   -1,   -1,  719,   -1,   -1,   -1,
 /*   240 */    -1,   -1,  723,   -1,   -1,  553,   -1,   -1,   -1,   -1,
 /*   250 */    -1,   -1,   -1,   -1,   -1,  347,   -1,   -1,  546,   -1,
 /*   260 */    -1,  537,   -1,   -1,   -1,  569,   -1,   -1,  748,   -1,
 /*   270 */    -1,   -1,  774,  749,   -1,  741,   -1,  485,   -1,  403,
 /*   280 */    -1,  366,   -1,   -1,  573,   -1,   -1,   -1,  781,  757,
 /*   290 */    -1,   -1,  662,   -1,
};
static YYACTIONTYPE yy_default[] = {
 /*     0 */   455,  455,  455,  455,  455,  455,  455,  333,  455,  336,
 /*    10 */   338,  455,  455,  382,  455,  384,  455,  385,  455,  386,
 /*    20 */   455,  387,  455,  388,  455,  389,  455,  390,  455,  391,
 /*    30 */   455,  392,  455,  393,  455,  394,  455,  395,  455,  396,
 /*    40 */   455,  397,  455,  398,  455,  399,  455,  400,  455,  401,
 /*    50 */   455,  402,  455,  403,  455,  404,  455,  405,  455,  455,
 /*    60 */   406,  455,  407,  455,  455,  355,  364,  369,  357,  373,
 /*    70 */   377,  299,  455,  376,  455,  370,  455,  371,  378,  379,
 /*    80 */   380,  381,  455,  372,  455,  455,  356,  455,  358,  360,
 /*    90 */   361,  362,  455,  415,  455,  433,  455,  434,  455,  435,
 /*   100 */   455,  303,  455,  455,  455,  314,  300,  455,  311,  352,
 /*   110 */   455,  350,  351,  353,  454,  455,  452,  455,  451,  455,
 /*   120 */   453,  313,  315,  317,  455,  321,  332,  318,  455,  331,
 /*   130 */   455,  455,  455,  414,  455,  455,  455,  455,  455,  416,
 /*   140 */   455,  455,  455,  455,  455,  417,  455,  455,  455,  418,
 /*   150 */   419,  455,  455,  455,  421,  423,  454,  426,  455,  432,
 /*   160 */   455,  424,  455,  455,  429,  431,  455,  436,  455,  437,
 /*   170 */   439,  440,  441,  442,  443,  444,  445,  446,  447,  448,
 /*   180 */   449,  450,  430,  425,  455,  422,  420,  455,  319,  320,
 /*   190 */   455,  455,  455,  455,  455,  455,  455,  455,  455,  455,
 /*   200 */   455,  455,  455,  455,  455,  455,  455,  316,  312,  455,
 /*   210 */   304,  306,  454,  455,  307,  310,  455,  308,  309,  305,
 /*   220 */   301,  302,  455,  438,  455,  411,  359,  455,  368,  455,
 /*   230 */   455,  363,  455,  365,  367,  366,  455,  354,  455,  409,
 /*   240 */   455,  412,  455,  408,  455,  455,  455,  410,  455,  413,
 /*   250 */   383,  337,  455,  455,  455,  455,  455,  455,  455,  455,
 /*   260 */   334,  455,  455,  455,  455,  455,  455,  335,  455,  339,
 /*   270 */   341,  340,  355,  455,  455,  455,  455,  455,  455,  455,
 /*   280 */   343,  455,  344,  455,  455,  346,  347,  345,  355,  455,
 /*   290 */   455,  455,  455,  349,
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
  phql_ARG_SDECL                /* A place to hold %extra_argument */
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
void phql_Trace(FILE *TraceFILE, char *zTracePrompt){
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
  "$",             "AGAINST",       "BETWEEN",       "EQUALS",      
  "NOTEQUALS",     "LESS",          "GREATER",       "GREATEREQUAL",
  "LESSEQUAL",     "TS_MATCHES",    "TS_OR",         "TS_AND",      
  "TS_NEGATE",     "TS_CONTAINS_ANOTHER",  "TS_CONTAINS_IN",  "AND",         
  "OR",            "LIKE",          "ILIKE",         "BITWISE_AND", 
  "BITWISE_OR",    "BITWISE_XOR",   "DIVIDE",        "TIMES",       
  "MOD",           "PLUS",          "MINUS",         "IS",          
  "IN",            "NOT",           "BITWISE_NOT",   "COMMA",       
  "SELECT",        "FROM",          "DISTINCT",      "ALL",         
  "IDENTIFIER",    "DOT",           "AS",            "INNER",       
  "JOIN",          "CROSS",         "LEFT",          "OUTER",       
  "RIGHT",         "FULL",          "ON",            "PARENTHESES_OPEN",
  "PARENTHESES_CLOSE",  "INSERT",        "INTO",          "VALUES",      
  "UPDATE",        "SET",           "DELETE",        "WHERE",       
  "ORDER",         "BY",            "ASC",           "DESC",        
  "GROUP",         "HAVING",        "LIMIT",         "OFFSET",      
  "FOR",           "HINTEGER",      "INTEGER",       "NPLACEHOLDER",
  "SPLACEHOLDER",  "EXISTS",        "CAST",          "CONVERT",     
  "USING",         "CASE",          "END",           "WHEN",        
  "THEN",          "ELSE",          "NULL",          "STRING",      
  "DOUBLE",        "TRUE",          "FALSE",         "NTPLACEHOLDER",
  "STPLACEHOLDER",  "COLON",         "error",         "program",     
  "query_language",  "select_statement",  "insert_statement",  "update_statement",
  "delete_statement",  "select_clause",  "where_clause",  "group_clause",
  "having_clause",  "order_clause",  "select_limit_clause",  "forupdate_clause",
  "distinct_all",  "column_list",   "associated_name_list",  "join_list_or_null",
  "column_item",   "expr",          "associated_name",  "join_list",   
  "join_item",     "join_clause",   "join_type",     "aliased_or_qualified_name",
  "join_associated_name",  "join_conditions",  "values_list",   "field_list",  
  "value_list",    "value_item",    "field_item",    "update_clause",
  "limit_clause",  "update_item_list",  "update_item",   "qualified_name",
  "new_value",     "delete_clause",  "order_list",    "order_item",  
  "group_list",    "group_item",    "integer_or_placeholder",  "argument_list",
  "when_clauses",  "when_clause",   "function_call",  "distinct_or_null",
  "argument_list_or_null",  "argument_item",
};
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing reduce actions, the names of all rules are required.
*/
static const char *yyRuleName[] = {
 /*   0 */ "program ::= query_language",
 /*   1 */ "query_language ::= select_statement",
 /*   2 */ "query_language ::= insert_statement",
 /*   3 */ "query_language ::= update_statement",
 /*   4 */ "query_language ::= delete_statement",
 /*   5 */ "select_statement ::= select_clause where_clause group_clause having_clause order_clause select_limit_clause forupdate_clause",
 /*   6 */ "select_clause ::= SELECT distinct_all column_list FROM associated_name_list join_list_or_null",
 /*   7 */ "distinct_all ::= DISTINCT",
 /*   8 */ "distinct_all ::= ALL",
 /*   9 */ "distinct_all ::=",
 /*  10 */ "column_list ::= column_list COMMA column_item",
 /*  11 */ "column_list ::= column_item",
 /*  12 */ "column_item ::= TIMES",
 /*  13 */ "column_item ::= IDENTIFIER DOT TIMES",
 /*  14 */ "column_item ::= expr AS IDENTIFIER",
 /*  15 */ "column_item ::= expr IDENTIFIER",
 /*  16 */ "column_item ::= expr",
 /*  17 */ "associated_name_list ::= associated_name_list COMMA associated_name",
 /*  18 */ "associated_name_list ::= associated_name",
 /*  19 */ "join_list_or_null ::= join_list",
 /*  20 */ "join_list_or_null ::=",
 /*  21 */ "join_list ::= join_list join_item",
 /*  22 */ "join_list ::= join_item",
 /*  23 */ "join_item ::= join_clause",
 /*  24 */ "join_clause ::= join_type aliased_or_qualified_name join_associated_name join_conditions",
 /*  25 */ "join_associated_name ::= AS IDENTIFIER",
 /*  26 */ "join_associated_name ::= IDENTIFIER",
 /*  27 */ "join_associated_name ::=",
 /*  28 */ "join_type ::= INNER JOIN",
 /*  29 */ "join_type ::= CROSS JOIN",
 /*  30 */ "join_type ::= LEFT OUTER JOIN",
 /*  31 */ "join_type ::= LEFT JOIN",
 /*  32 */ "join_type ::= RIGHT OUTER JOIN",
 /*  33 */ "join_type ::= RIGHT JOIN",
 /*  34 */ "join_type ::= FULL OUTER JOIN",
 /*  35 */ "join_type ::= FULL JOIN",
 /*  36 */ "join_type ::= JOIN",
 /*  37 */ "join_conditions ::= ON expr",
 /*  38 */ "join_conditions ::=",
 /*  39 */ "insert_statement ::= insert_statement COMMA PARENTHESES_OPEN values_list PARENTHESES_CLOSE",
 /*  40 */ "insert_statement ::= INSERT INTO aliased_or_qualified_name VALUES PARENTHESES_OPEN values_list PARENTHESES_CLOSE",
 /*  41 */ "insert_statement ::= INSERT INTO aliased_or_qualified_name PARENTHESES_OPEN field_list PARENTHESES_CLOSE VALUES PARENTHESES_OPEN values_list PARENTHESES_CLOSE",
 /*  42 */ "values_list ::= values_list COMMA value_item",
 /*  43 */ "values_list ::= value_item",
 /*  44 */ "value_item ::= expr",
 /*  45 */ "field_list ::= field_list COMMA field_item",
 /*  46 */ "field_list ::= field_item",
 /*  47 */ "field_item ::= IDENTIFIER",
 /*  48 */ "update_statement ::= update_clause where_clause limit_clause",
 /*  49 */ "update_clause ::= UPDATE associated_name SET update_item_list",
 /*  50 */ "update_item_list ::= update_item_list COMMA update_item",
 /*  51 */ "update_item_list ::= update_item",
 /*  52 */ "update_item ::= qualified_name EQUALS new_value",
 /*  53 */ "new_value ::= expr",
 /*  54 */ "delete_statement ::= delete_clause where_clause limit_clause",
 /*  55 */ "delete_clause ::= DELETE FROM associated_name",
 /*  56 */ "associated_name ::= aliased_or_qualified_name AS IDENTIFIER",
 /*  57 */ "associated_name ::= aliased_or_qualified_name IDENTIFIER",
 /*  58 */ "associated_name ::= aliased_or_qualified_name",
 /*  59 */ "aliased_or_qualified_name ::= qualified_name",
 /*  60 */ "where_clause ::= WHERE expr",
 /*  61 */ "where_clause ::=",
 /*  62 */ "order_clause ::= ORDER BY order_list",
 /*  63 */ "order_clause ::=",
 /*  64 */ "order_list ::= order_list COMMA order_item",
 /*  65 */ "order_list ::= order_item",
 /*  66 */ "order_item ::= expr",
 /*  67 */ "order_item ::= expr ASC",
 /*  68 */ "order_item ::= expr DESC",
 /*  69 */ "group_clause ::= GROUP BY group_list",
 /*  70 */ "group_clause ::=",
 /*  71 */ "group_list ::= group_list COMMA group_item",
 /*  72 */ "group_list ::= group_item",
 /*  73 */ "group_item ::= expr",
 /*  74 */ "having_clause ::= HAVING expr",
 /*  75 */ "having_clause ::=",
 /*  76 */ "select_limit_clause ::= LIMIT integer_or_placeholder",
 /*  77 */ "select_limit_clause ::= LIMIT integer_or_placeholder COMMA integer_or_placeholder",
 /*  78 */ "select_limit_clause ::= LIMIT integer_or_placeholder OFFSET integer_or_placeholder",
 /*  79 */ "select_limit_clause ::=",
 /*  80 */ "limit_clause ::= LIMIT integer_or_placeholder",
 /*  81 */ "limit_clause ::=",
 /*  82 */ "forupdate_clause ::= FOR UPDATE",
 /*  83 */ "forupdate_clause ::=",
 /*  84 */ "integer_or_placeholder ::= HINTEGER",
 /*  85 */ "integer_or_placeholder ::= INTEGER",
 /*  86 */ "integer_or_placeholder ::= NPLACEHOLDER",
 /*  87 */ "integer_or_placeholder ::= SPLACEHOLDER",
 /*  88 */ "expr ::= MINUS expr",
 /*  89 */ "expr ::= expr MINUS expr",
 /*  90 */ "expr ::= expr PLUS expr",
 /*  91 */ "expr ::= expr TIMES expr",
 /*  92 */ "expr ::= expr DIVIDE expr",
 /*  93 */ "expr ::= expr MOD expr",
 /*  94 */ "expr ::= expr AND expr",
 /*  95 */ "expr ::= expr OR expr",
 /*  96 */ "expr ::= expr BITWISE_AND expr",
 /*  97 */ "expr ::= expr BITWISE_OR expr",
 /*  98 */ "expr ::= expr BITWISE_XOR expr",
 /*  99 */ "expr ::= expr EQUALS expr",
 /* 100 */ "expr ::= expr NOTEQUALS expr",
 /* 101 */ "expr ::= expr LESS expr",
 /* 102 */ "expr ::= expr GREATER expr",
 /* 103 */ "expr ::= expr GREATEREQUAL expr",
 /* 104 */ "expr ::= expr TS_MATCHES expr",
 /* 105 */ "expr ::= expr TS_OR expr",
 /* 106 */ "expr ::= expr TS_AND expr",
 /* 107 */ "expr ::= expr TS_NEGATE expr",
 /* 108 */ "expr ::= expr TS_CONTAINS_ANOTHER expr",
 /* 109 */ "expr ::= expr TS_CONTAINS_IN expr",
 /* 110 */ "expr ::= expr LESSEQUAL expr",
 /* 111 */ "expr ::= expr LIKE expr",
 /* 112 */ "expr ::= expr NOT LIKE expr",
 /* 113 */ "expr ::= expr ILIKE expr",
 /* 114 */ "expr ::= expr NOT ILIKE expr",
 /* 115 */ "expr ::= expr IN PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 116 */ "expr ::= expr NOT IN PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 117 */ "expr ::= PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 118 */ "expr ::= expr IN PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 119 */ "expr ::= expr NOT IN PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 120 */ "expr ::= EXISTS PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 121 */ "expr ::= expr AGAINST expr",
 /* 122 */ "expr ::= CAST PARENTHESES_OPEN expr AS IDENTIFIER PARENTHESES_CLOSE",
 /* 123 */ "expr ::= CONVERT PARENTHESES_OPEN expr USING IDENTIFIER PARENTHESES_CLOSE",
 /* 124 */ "expr ::= CASE expr when_clauses END",
 /* 125 */ "when_clauses ::= when_clauses when_clause",
 /* 126 */ "when_clauses ::= when_clause",
 /* 127 */ "when_clause ::= WHEN expr THEN expr",
 /* 128 */ "when_clause ::= ELSE expr",
 /* 129 */ "expr ::= function_call",
 /* 130 */ "function_call ::= IDENTIFIER PARENTHESES_OPEN distinct_or_null argument_list_or_null PARENTHESES_CLOSE",
 /* 131 */ "distinct_or_null ::= DISTINCT",
 /* 132 */ "distinct_or_null ::=",
 /* 133 */ "argument_list_or_null ::= argument_list",
 /* 134 */ "argument_list_or_null ::=",
 /* 135 */ "argument_list ::= argument_list COMMA argument_item",
 /* 136 */ "argument_list ::= argument_item",
 /* 137 */ "argument_item ::= TIMES",
 /* 138 */ "argument_item ::= expr",
 /* 139 */ "expr ::= expr IS NULL",
 /* 140 */ "expr ::= expr IS NOT NULL",
 /* 141 */ "expr ::= expr BETWEEN expr",
 /* 142 */ "expr ::= NOT expr",
 /* 143 */ "expr ::= BITWISE_NOT expr",
 /* 144 */ "expr ::= PARENTHESES_OPEN expr PARENTHESES_CLOSE",
 /* 145 */ "expr ::= qualified_name",
 /* 146 */ "expr ::= HINTEGER",
 /* 147 */ "expr ::= INTEGER",
 /* 148 */ "expr ::= STRING",
 /* 149 */ "expr ::= DOUBLE",
 /* 150 */ "expr ::= NULL",
 /* 151 */ "expr ::= TRUE",
 /* 152 */ "expr ::= FALSE",
 /* 153 */ "expr ::= NPLACEHOLDER",
 /* 154 */ "expr ::= SPLACEHOLDER",
 /* 155 */ "expr ::= NTPLACEHOLDER",
 /* 156 */ "expr ::= STPLACEHOLDER",
 /* 157 */ "qualified_name ::= IDENTIFIER COLON IDENTIFIER DOT IDENTIFIER",
 /* 158 */ "qualified_name ::= IDENTIFIER COLON IDENTIFIER",
 /* 159 */ "qualified_name ::= IDENTIFIER DOT IDENTIFIER",
 /* 160 */ "qualified_name ::= IDENTIFIER",
};
#endif /* NDEBUG */

/*
** This function returns the symbolic name associated with a token
** value.
*/
const char *phql_TokenName(int tokenType){
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
** to phql_ and phql_Free.
*/
void *phql_Alloc(void *(*mallocProc)(size_t)){
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
    case 83:
    case 84:
    case 85:
/* #line 573 "parser.y" */
{
	if ((yypminor->yy0)) {
		if ((yypminor->yy0)->free_flag) {
			efree((yypminor->yy0)->token);
		}
		efree((yypminor->yy0));
	}
}
/* #line 1308 "parser.c" */
      break;
    case 88:
    case 89:
    case 90:
    case 91:
    case 92:
    case 93:
    case 101:
    case 102:
    case 104:
    case 105:
    case 106:
    case 107:
    case 108:
    case 109:
    case 110:
    case 111:
    case 115:
    case 116:
    case 118:
    case 119:
    case 121:
    case 122:
    case 123:
    case 125:
    case 126:
    case 127:
    case 128:
    case 129:
    case 131:
    case 134:
    case 137:
/* #line 586 "parser.y" */
{ zval_ptr_dtor(&(yypminor->yy204)); }
/* #line 1343 "parser.c" */
      break;
    case 94:
    case 95:
    case 96:
    case 97:
    case 98:
    case 99:
    case 100:
    case 112:
    case 113:
    case 120:
    case 135:
    case 136:
/* #line 878 "parser.y" */
{ phalcon_safe_zval_ptr_dtor((yypminor->yy204)); }
/* #line 1359 "parser.c" */
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
**       obtained from phql_Alloc.
** <li>  A pointer to a function used to reclaim memory obtained
**       from malloc.
** </ul>
*/
void phql_Free(
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
     phql_ARG_FETCH;
     yypParser->yyidx--;
#ifndef NDEBUG
     if( yyTraceFILE ){
       fprintf(yyTraceFILE,"%sStack Overflow!\n",yyTracePrompt);
     }
#endif
     while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
     /* Here code is inserted which will execute if the parser
     ** stack every overflows */
     phql_ARG_STORE; /* Suppress warning about unused %extra_argument var */
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
  { 87, 1 },
  { 88, 1 },
  { 88, 1 },
  { 88, 1 },
  { 88, 1 },
  { 89, 7 },
  { 93, 6 },
  { 100, 1 },
  { 100, 1 },
  { 100, 0 },
  { 101, 3 },
  { 101, 1 },
  { 104, 1 },
  { 104, 3 },
  { 104, 3 },
  { 104, 2 },
  { 104, 1 },
  { 102, 3 },
  { 102, 1 },
  { 103, 1 },
  { 103, 0 },
  { 107, 2 },
  { 107, 1 },
  { 108, 1 },
  { 109, 4 },
  { 112, 2 },
  { 112, 1 },
  { 112, 0 },
  { 110, 2 },
  { 110, 2 },
  { 110, 3 },
  { 110, 2 },
  { 110, 3 },
  { 110, 2 },
  { 110, 3 },
  { 110, 2 },
  { 110, 1 },
  { 113, 2 },
  { 113, 0 },
  { 90, 5 },
  { 90, 7 },
  { 90, 10 },
  { 114, 3 },
  { 114, 1 },
  { 117, 1 },
  { 115, 3 },
  { 115, 1 },
  { 118, 1 },
  { 91, 3 },
  { 119, 4 },
  { 121, 3 },
  { 121, 1 },
  { 122, 3 },
  { 124, 1 },
  { 92, 3 },
  { 125, 3 },
  { 106, 3 },
  { 106, 2 },
  { 106, 1 },
  { 111, 1 },
  { 94, 2 },
  { 94, 0 },
  { 97, 3 },
  { 97, 0 },
  { 126, 3 },
  { 126, 1 },
  { 127, 1 },
  { 127, 2 },
  { 127, 2 },
  { 95, 3 },
  { 95, 0 },
  { 128, 3 },
  { 128, 1 },
  { 129, 1 },
  { 96, 2 },
  { 96, 0 },
  { 98, 2 },
  { 98, 4 },
  { 98, 4 },
  { 98, 0 },
  { 120, 2 },
  { 120, 0 },
  { 99, 2 },
  { 99, 0 },
  { 130, 1 },
  { 130, 1 },
  { 130, 1 },
  { 130, 1 },
  { 105, 2 },
  { 105, 3 },
  { 105, 3 },
  { 105, 3 },
  { 105, 3 },
  { 105, 3 },
  { 105, 3 },
  { 105, 3 },
  { 105, 3 },
  { 105, 3 },
  { 105, 3 },
  { 105, 3 },
  { 105, 3 },
  { 105, 3 },
  { 105, 3 },
  { 105, 3 },
  { 105, 3 },
  { 105, 3 },
  { 105, 3 },
  { 105, 3 },
  { 105, 3 },
  { 105, 3 },
  { 105, 3 },
  { 105, 3 },
  { 105, 4 },
  { 105, 3 },
  { 105, 4 },
  { 105, 5 },
  { 105, 6 },
  { 105, 3 },
  { 105, 5 },
  { 105, 6 },
  { 105, 4 },
  { 105, 3 },
  { 105, 6 },
  { 105, 6 },
  { 105, 4 },
  { 132, 2 },
  { 132, 1 },
  { 133, 4 },
  { 133, 2 },
  { 105, 1 },
  { 134, 5 },
  { 135, 1 },
  { 135, 0 },
  { 136, 1 },
  { 136, 0 },
  { 131, 3 },
  { 131, 1 },
  { 137, 1 },
  { 137, 1 },
  { 105, 3 },
  { 105, 4 },
  { 105, 3 },
  { 105, 2 },
  { 105, 2 },
  { 105, 3 },
  { 105, 1 },
  { 105, 1 },
  { 105, 1 },
  { 105, 1 },
  { 105, 1 },
  { 105, 1 },
  { 105, 1 },
  { 105, 1 },
  { 105, 1 },
  { 105, 1 },
  { 105, 1 },
  { 105, 1 },
  { 123, 5 },
  { 123, 3 },
  { 123, 3 },
  { 123, 1 },
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
  phql_ARG_FETCH;
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
/* #line 582 "parser.y" */
{
	status->ret = yymsp[0].minor.yy204;
}
/* #line 1737 "parser.c" */
        break;
      case 1:
      case 2:
      case 3:
      case 4:
      case 18:
      case 19:
      case 22:
      case 23:
      case 44:
      case 51:
      case 53:
      case 59:
      case 65:
      case 72:
      case 73:
      case 129:
      case 133:
      case 138:
      case 145:
/* #line 588 "parser.y" */
{
	yygotominor.yy204 = yymsp[0].minor.yy204;
}
/* #line 1762 "parser.c" */
        break;
      case 5:
/* #line 606 "parser.y" */
{
	yygotominor.yy204 = phql_ret_select_statement(yymsp[-6].minor.yy204, yymsp[-5].minor.yy204, yymsp[-2].minor.yy204, yymsp[-4].minor.yy204, yymsp[-3].minor.yy204, yymsp[-1].minor.yy204, yymsp[0].minor.yy204);
}
/* #line 1769 "parser.c" */
        break;
      case 6:
/* #line 612 "parser.y" */
{
	yygotominor.yy204 = phql_ret_select_clause(yymsp[-4].minor.yy204, yymsp[-3].minor.yy204, yymsp[-1].minor.yy204, yymsp[0].minor.yy204);
  yy_destructor(32,&yymsp[-5].minor);
  yy_destructor(33,&yymsp[-2].minor);
}
/* #line 1778 "parser.c" */
        break;
      case 7:
/* #line 618 "parser.y" */
{
	yygotominor.yy204 = phql_ret_distinct_all(1);
  yy_destructor(34,&yymsp[0].minor);
}
/* #line 1786 "parser.c" */
        break;
      case 8:
/* #line 622 "parser.y" */
{
	yygotominor.yy204 = phql_ret_distinct_all(0);
  yy_destructor(35,&yymsp[0].minor);
}
/* #line 1794 "parser.c" */
        break;
      case 9:
      case 20:
      case 27:
      case 38:
      case 61:
      case 63:
      case 70:
      case 75:
      case 79:
      case 81:
      case 83:
      case 132:
      case 134:
/* #line 626 "parser.y" */
{
	yygotominor.yy204 = NULL;
}
/* #line 1813 "parser.c" */
        break;
      case 10:
      case 17:
      case 42:
      case 45:
      case 50:
      case 64:
      case 71:
      case 135:
/* #line 632 "parser.y" */
{
	yygotominor.yy204 = phql_ret_zval_list(yymsp[-2].minor.yy204, yymsp[0].minor.yy204);
  yy_destructor(31,&yymsp[-1].minor);
}
/* #line 1828 "parser.c" */
        break;
      case 11:
      case 43:
      case 46:
      case 126:
      case 136:
/* #line 636 "parser.y" */
{
	yygotominor.yy204 = phql_ret_zval_list(yymsp[0].minor.yy204, NULL);
}
/* #line 1839 "parser.c" */
        break;
      case 12:
      case 137:
/* #line 642 "parser.y" */
{
	yygotominor.yy204 = phql_ret_column_item(PHQL_T_STARALL, NULL, NULL, NULL);
  yy_destructor(23,&yymsp[0].minor);
}
/* #line 1848 "parser.c" */
        break;
      case 13:
/* #line 646 "parser.y" */
{
	yygotominor.yy204 = phql_ret_column_item(PHQL_T_DOMAINALL, NULL, yymsp[-2].minor.yy0, NULL);
  yy_destructor(37,&yymsp[-1].minor);
  yy_destructor(23,&yymsp[0].minor);
}
/* #line 1857 "parser.c" */
        break;
      case 14:
/* #line 650 "parser.y" */
{
	yygotominor.yy204 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-2].minor.yy204, NULL, yymsp[0].minor.yy0);
  yy_destructor(38,&yymsp[-1].minor);
}
/* #line 1865 "parser.c" */
        break;
      case 15:
/* #line 654 "parser.y" */
{
	yygotominor.yy204 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-1].minor.yy204, NULL, yymsp[0].minor.yy0);
}
/* #line 1872 "parser.c" */
        break;
      case 16:
/* #line 658 "parser.y" */
{
	yygotominor.yy204 = phql_ret_column_item(PHQL_T_EXPR, yymsp[0].minor.yy204, NULL, NULL);
}
/* #line 1879 "parser.c" */
        break;
      case 21:
      case 125:
/* #line 682 "parser.y" */
{
	yygotominor.yy204 = phql_ret_zval_list(yymsp[-1].minor.yy204, yymsp[0].minor.yy204);
}
/* #line 1887 "parser.c" */
        break;
      case 24:
/* #line 699 "parser.y" */
{
	yygotominor.yy204 = phql_ret_join_item(yymsp[-3].minor.yy204, yymsp[-2].minor.yy204, yymsp[-1].minor.yy204, yymsp[0].minor.yy204);
}
/* #line 1894 "parser.c" */
        break;
      case 25:
/* #line 705 "parser.y" */
{
	yygotominor.yy204 = phql_ret_qualified_name(NULL, NULL, yymsp[0].minor.yy0);
  yy_destructor(38,&yymsp[-1].minor);
}
/* #line 1902 "parser.c" */
        break;
      case 26:
      case 47:
      case 160:
/* #line 709 "parser.y" */
{
	yygotominor.yy204 = phql_ret_qualified_name(NULL, NULL, yymsp[0].minor.yy0);
}
/* #line 1911 "parser.c" */
        break;
      case 28:
/* #line 719 "parser.y" */
{
	yygotominor.yy204 = phql_ret_join_type(PHQL_T_INNERJOIN);
  yy_destructor(39,&yymsp[-1].minor);
  yy_destructor(40,&yymsp[0].minor);
}
/* #line 1920 "parser.c" */
        break;
      case 29:
/* #line 723 "parser.y" */
{
	yygotominor.yy204 = phql_ret_join_type(PHQL_T_CROSSJOIN);
  yy_destructor(41,&yymsp[-1].minor);
  yy_destructor(40,&yymsp[0].minor);
}
/* #line 1929 "parser.c" */
        break;
      case 30:
/* #line 727 "parser.y" */
{
	yygotominor.yy204 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  yy_destructor(42,&yymsp[-2].minor);
  yy_destructor(43,&yymsp[-1].minor);
  yy_destructor(40,&yymsp[0].minor);
}
/* #line 1939 "parser.c" */
        break;
      case 31:
/* #line 731 "parser.y" */
{
	yygotominor.yy204 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  yy_destructor(42,&yymsp[-1].minor);
  yy_destructor(40,&yymsp[0].minor);
}
/* #line 1948 "parser.c" */
        break;
      case 32:
/* #line 735 "parser.y" */
{
	yygotominor.yy204 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  yy_destructor(44,&yymsp[-2].minor);
  yy_destructor(43,&yymsp[-1].minor);
  yy_destructor(40,&yymsp[0].minor);
}
/* #line 1958 "parser.c" */
        break;
      case 33:
/* #line 739 "parser.y" */
{
	yygotominor.yy204 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  yy_destructor(44,&yymsp[-1].minor);
  yy_destructor(40,&yymsp[0].minor);
}
/* #line 1967 "parser.c" */
        break;
      case 34:
/* #line 743 "parser.y" */
{
	yygotominor.yy204 = phql_ret_join_type(PHQL_T_FULLJOIN);
  yy_destructor(45,&yymsp[-2].minor);
  yy_destructor(43,&yymsp[-1].minor);
  yy_destructor(40,&yymsp[0].minor);
}
/* #line 1977 "parser.c" */
        break;
      case 35:
/* #line 747 "parser.y" */
{
	yygotominor.yy204 = phql_ret_join_type(PHQL_T_FULLJOIN);
  yy_destructor(45,&yymsp[-1].minor);
  yy_destructor(40,&yymsp[0].minor);
}
/* #line 1986 "parser.c" */
        break;
      case 36:
/* #line 751 "parser.y" */
{
	yygotominor.yy204 = phql_ret_join_type(PHQL_T_INNERJOIN);
  yy_destructor(40,&yymsp[0].minor);
}
/* #line 1994 "parser.c" */
        break;
      case 37:
/* #line 757 "parser.y" */
{
	yygotominor.yy204 = yymsp[0].minor.yy204;
  yy_destructor(46,&yymsp[-1].minor);
}
/* #line 2002 "parser.c" */
        break;
      case 39:
/* #line 768 "parser.y" */
{
	yygotominor.yy204 = phql_ret_insert_statement2(yymsp[-4].minor.yy204, NULL, yymsp[-1].minor.yy204);
  yy_destructor(31,&yymsp[-3].minor);
  yy_destructor(47,&yymsp[-2].minor);
  yy_destructor(48,&yymsp[0].minor);
}
/* #line 2012 "parser.c" */
        break;
      case 40:
/* #line 772 "parser.y" */
{
	yygotominor.yy204 = phql_ret_insert_statement(yymsp[-4].minor.yy204, NULL, yymsp[-1].minor.yy204);
  yy_destructor(49,&yymsp[-6].minor);
  yy_destructor(50,&yymsp[-5].minor);
  yy_destructor(51,&yymsp[-3].minor);
  yy_destructor(47,&yymsp[-2].minor);
  yy_destructor(48,&yymsp[0].minor);
}
/* #line 2024 "parser.c" */
        break;
      case 41:
/* #line 776 "parser.y" */
{
	yygotominor.yy204 = phql_ret_insert_statement(yymsp[-7].minor.yy204, yymsp[-5].minor.yy204, yymsp[-1].minor.yy204);
  yy_destructor(49,&yymsp[-9].minor);
  yy_destructor(50,&yymsp[-8].minor);
  yy_destructor(47,&yymsp[-6].minor);
  yy_destructor(48,&yymsp[-4].minor);
  yy_destructor(51,&yymsp[-3].minor);
  yy_destructor(47,&yymsp[-2].minor);
  yy_destructor(48,&yymsp[0].minor);
}
/* #line 2038 "parser.c" */
        break;
      case 48:
/* #line 814 "parser.y" */
{
	yygotominor.yy204 = phql_ret_update_statement(yymsp[-2].minor.yy204, yymsp[-1].minor.yy204, yymsp[0].minor.yy204);
}
/* #line 2045 "parser.c" */
        break;
      case 49:
/* #line 820 "parser.y" */
{
	yygotominor.yy204 = phql_ret_update_clause(yymsp[-2].minor.yy204, yymsp[0].minor.yy204);
  yy_destructor(52,&yymsp[-3].minor);
  yy_destructor(53,&yymsp[-1].minor);
}
/* #line 2054 "parser.c" */
        break;
      case 52:
/* #line 836 "parser.y" */
{
	yygotominor.yy204 = phql_ret_update_item(yymsp[-2].minor.yy204, yymsp[0].minor.yy204);
  yy_destructor(3,&yymsp[-1].minor);
}
/* #line 2062 "parser.c" */
        break;
      case 54:
/* #line 848 "parser.y" */
{
	yygotominor.yy204 = phql_ret_delete_statement(yymsp[-2].minor.yy204, yymsp[-1].minor.yy204, yymsp[0].minor.yy204);
}
/* #line 2069 "parser.c" */
        break;
      case 55:
/* #line 854 "parser.y" */
{
	yygotominor.yy204 = phql_ret_delete_clause(yymsp[0].minor.yy204);
  yy_destructor(54,&yymsp[-2].minor);
  yy_destructor(33,&yymsp[-1].minor);
}
/* #line 2078 "parser.c" */
        break;
      case 56:
/* #line 860 "parser.y" */
{
	yygotominor.yy204 = phql_ret_assoc_name(yymsp[-2].minor.yy204, yymsp[0].minor.yy0);
  yy_destructor(38,&yymsp[-1].minor);
}
/* #line 2086 "parser.c" */
        break;
      case 57:
/* #line 864 "parser.y" */
{
	yygotominor.yy204 = phql_ret_assoc_name(yymsp[-1].minor.yy204, yymsp[0].minor.yy0);
}
/* #line 2093 "parser.c" */
        break;
      case 58:
/* #line 868 "parser.y" */
{
	yygotominor.yy204 = phql_ret_assoc_name(yymsp[0].minor.yy204, NULL);
}
/* #line 2100 "parser.c" */
        break;
      case 60:
/* #line 880 "parser.y" */
{
	yygotominor.yy204 = yymsp[0].minor.yy204;
  yy_destructor(55,&yymsp[-1].minor);
}
/* #line 2108 "parser.c" */
        break;
      case 62:
/* #line 890 "parser.y" */
{
	yygotominor.yy204 = yymsp[0].minor.yy204;
  yy_destructor(56,&yymsp[-2].minor);
  yy_destructor(57,&yymsp[-1].minor);
}
/* #line 2117 "parser.c" */
        break;
      case 66:
/* #line 910 "parser.y" */
{
	yygotominor.yy204 = phql_ret_order_item(yymsp[0].minor.yy204, 0);
}
/* #line 2124 "parser.c" */
        break;
      case 67:
/* #line 914 "parser.y" */
{
	yygotominor.yy204 = phql_ret_order_item(yymsp[-1].minor.yy204, PHQL_T_ASC);
  yy_destructor(58,&yymsp[0].minor);
}
/* #line 2132 "parser.c" */
        break;
      case 68:
/* #line 918 "parser.y" */
{
	yygotominor.yy204 = phql_ret_order_item(yymsp[-1].minor.yy204, PHQL_T_DESC);
  yy_destructor(59,&yymsp[0].minor);
}
/* #line 2140 "parser.c" */
        break;
      case 69:
/* #line 924 "parser.y" */
{
	yygotominor.yy204 = yymsp[0].minor.yy204;
  yy_destructor(60,&yymsp[-2].minor);
  yy_destructor(57,&yymsp[-1].minor);
}
/* #line 2149 "parser.c" */
        break;
      case 74:
/* #line 950 "parser.y" */
{
	yygotominor.yy204 = yymsp[0].minor.yy204;
  yy_destructor(61,&yymsp[-1].minor);
}
/* #line 2157 "parser.c" */
        break;
      case 76:
      case 80:
/* #line 960 "parser.y" */
{
	yygotominor.yy204 = phql_ret_limit_clause(yymsp[0].minor.yy204, NULL);
  yy_destructor(62,&yymsp[-1].minor);
}
/* #line 2166 "parser.c" */
        break;
      case 77:
/* #line 964 "parser.y" */
{
	yygotominor.yy204 = phql_ret_limit_clause(yymsp[0].minor.yy204, yymsp[-2].minor.yy204);
  yy_destructor(62,&yymsp[-3].minor);
  yy_destructor(31,&yymsp[-1].minor);
}
/* #line 2175 "parser.c" */
        break;
      case 78:
/* #line 968 "parser.y" */
{
	yygotominor.yy204 = phql_ret_limit_clause(yymsp[-2].minor.yy204, yymsp[0].minor.yy204);
  yy_destructor(62,&yymsp[-3].minor);
  yy_destructor(63,&yymsp[-1].minor);
}
/* #line 2184 "parser.c" */
        break;
      case 82:
/* #line 988 "parser.y" */
{
	yygotominor.yy204 = phql_ret_forupdate_clause();
  yy_destructor(64,&yymsp[-1].minor);
  yy_destructor(52,&yymsp[0].minor);
}
/* #line 2193 "parser.c" */
        break;
      case 84:
      case 146:
/* #line 996 "parser.y" */
{
	yygotominor.yy204 = phql_ret_literal_zval(PHQL_T_HINTEGER, yymsp[0].minor.yy0);
}
/* #line 2201 "parser.c" */
        break;
      case 85:
      case 147:
/* #line 1000 "parser.y" */
{
	yygotominor.yy204 = phql_ret_literal_zval(PHQL_T_INTEGER, yymsp[0].minor.yy0);
}
/* #line 2209 "parser.c" */
        break;
      case 86:
      case 153:
/* #line 1004 "parser.y" */
{
	yygotominor.yy204 = phql_ret_placeholder_zval(PHQL_T_NPLACEHOLDER, yymsp[0].minor.yy0);
}
/* #line 2217 "parser.c" */
        break;
      case 87:
      case 154:
/* #line 1008 "parser.y" */
{
	yygotominor.yy204 = phql_ret_placeholder_zval(PHQL_T_SPLACEHOLDER, yymsp[0].minor.yy0);
}
/* #line 2225 "parser.c" */
        break;
      case 88:
/* #line 1014 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_MINUS, NULL, yymsp[0].minor.yy204);
  yy_destructor(26,&yymsp[-1].minor);
}
/* #line 2233 "parser.c" */
        break;
      case 89:
/* #line 1018 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_SUB, yymsp[-2].minor.yy204, yymsp[0].minor.yy204);
  yy_destructor(26,&yymsp[-1].minor);
}
/* #line 2241 "parser.c" */
        break;
      case 90:
/* #line 1022 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_ADD, yymsp[-2].minor.yy204, yymsp[0].minor.yy204);
  yy_destructor(25,&yymsp[-1].minor);
}
/* #line 2249 "parser.c" */
        break;
      case 91:
/* #line 1026 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_MUL, yymsp[-2].minor.yy204, yymsp[0].minor.yy204);
  yy_destructor(23,&yymsp[-1].minor);
}
/* #line 2257 "parser.c" */
        break;
      case 92:
/* #line 1030 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_DIV, yymsp[-2].minor.yy204, yymsp[0].minor.yy204);
  yy_destructor(22,&yymsp[-1].minor);
}
/* #line 2265 "parser.c" */
        break;
      case 93:
/* #line 1034 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_MOD, yymsp[-2].minor.yy204, yymsp[0].minor.yy204);
  yy_destructor(24,&yymsp[-1].minor);
}
/* #line 2273 "parser.c" */
        break;
      case 94:
/* #line 1038 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_AND, yymsp[-2].minor.yy204, yymsp[0].minor.yy204);
  yy_destructor(15,&yymsp[-1].minor);
}
/* #line 2281 "parser.c" */
        break;
      case 95:
/* #line 1042 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_OR, yymsp[-2].minor.yy204, yymsp[0].minor.yy204);
  yy_destructor(16,&yymsp[-1].minor);
}
/* #line 2289 "parser.c" */
        break;
      case 96:
/* #line 1046 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_BITWISE_AND, yymsp[-2].minor.yy204, yymsp[0].minor.yy204);
  yy_destructor(19,&yymsp[-1].minor);
}
/* #line 2297 "parser.c" */
        break;
      case 97:
/* #line 1050 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_BITWISE_OR, yymsp[-2].minor.yy204, yymsp[0].minor.yy204);
  yy_destructor(20,&yymsp[-1].minor);
}
/* #line 2305 "parser.c" */
        break;
      case 98:
/* #line 1054 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_BITWISE_XOR, yymsp[-2].minor.yy204, yymsp[0].minor.yy204);
  yy_destructor(21,&yymsp[-1].minor);
}
/* #line 2313 "parser.c" */
        break;
      case 99:
/* #line 1058 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_EQUALS, yymsp[-2].minor.yy204, yymsp[0].minor.yy204);
  yy_destructor(3,&yymsp[-1].minor);
}
/* #line 2321 "parser.c" */
        break;
      case 100:
/* #line 1062 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_NOTEQUALS, yymsp[-2].minor.yy204, yymsp[0].minor.yy204);
  yy_destructor(4,&yymsp[-1].minor);
}
/* #line 2329 "parser.c" */
        break;
      case 101:
/* #line 1066 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_LESS, yymsp[-2].minor.yy204, yymsp[0].minor.yy204);
  yy_destructor(5,&yymsp[-1].minor);
}
/* #line 2337 "parser.c" */
        break;
      case 102:
/* #line 1070 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_GREATER, yymsp[-2].minor.yy204, yymsp[0].minor.yy204);
  yy_destructor(6,&yymsp[-1].minor);
}
/* #line 2345 "parser.c" */
        break;
      case 103:
/* #line 1074 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_GREATEREQUAL, yymsp[-2].minor.yy204, yymsp[0].minor.yy204);
  yy_destructor(7,&yymsp[-1].minor);
}
/* #line 2353 "parser.c" */
        break;
      case 104:
/* #line 1078 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_TS_MATCHES, yymsp[-2].minor.yy204, yymsp[0].minor.yy204);
  yy_destructor(9,&yymsp[-1].minor);
}
/* #line 2361 "parser.c" */
        break;
      case 105:
/* #line 1082 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_TS_OR, yymsp[-2].minor.yy204, yymsp[0].minor.yy204);
  yy_destructor(10,&yymsp[-1].minor);
}
/* #line 2369 "parser.c" */
        break;
      case 106:
/* #line 1086 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_TS_AND, yymsp[-2].minor.yy204, yymsp[0].minor.yy204);
  yy_destructor(11,&yymsp[-1].minor);
}
/* #line 2377 "parser.c" */
        break;
      case 107:
/* #line 1090 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_TS_NEGATE, yymsp[-2].minor.yy204, yymsp[0].minor.yy204);
  yy_destructor(12,&yymsp[-1].minor);
}
/* #line 2385 "parser.c" */
        break;
      case 108:
/* #line 1094 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_TS_CONTAINS_ANOTHER, yymsp[-2].minor.yy204, yymsp[0].minor.yy204);
  yy_destructor(13,&yymsp[-1].minor);
}
/* #line 2393 "parser.c" */
        break;
      case 109:
/* #line 1098 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_TS_CONTAINS_IN, yymsp[-2].minor.yy204, yymsp[0].minor.yy204);
  yy_destructor(14,&yymsp[-1].minor);
}
/* #line 2401 "parser.c" */
        break;
      case 110:
/* #line 1102 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_LESSEQUAL, yymsp[-2].minor.yy204, yymsp[0].minor.yy204);
  yy_destructor(8,&yymsp[-1].minor);
}
/* #line 2409 "parser.c" */
        break;
      case 111:
/* #line 1106 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_LIKE, yymsp[-2].minor.yy204, yymsp[0].minor.yy204);
  yy_destructor(17,&yymsp[-1].minor);
}
/* #line 2417 "parser.c" */
        break;
      case 112:
/* #line 1110 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_NLIKE, yymsp[-3].minor.yy204, yymsp[0].minor.yy204);
  yy_destructor(29,&yymsp[-2].minor);
  yy_destructor(17,&yymsp[-1].minor);
}
/* #line 2426 "parser.c" */
        break;
      case 113:
/* #line 1114 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_ILIKE, yymsp[-2].minor.yy204, yymsp[0].minor.yy204);
  yy_destructor(18,&yymsp[-1].minor);
}
/* #line 2434 "parser.c" */
        break;
      case 114:
/* #line 1118 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_NILIKE, yymsp[-3].minor.yy204, yymsp[0].minor.yy204);
  yy_destructor(29,&yymsp[-2].minor);
  yy_destructor(18,&yymsp[-1].minor);
}
/* #line 2443 "parser.c" */
        break;
      case 115:
      case 118:
/* #line 1122 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_IN, yymsp[-4].minor.yy204, yymsp[-1].minor.yy204);
  yy_destructor(28,&yymsp[-3].minor);
  yy_destructor(47,&yymsp[-2].minor);
  yy_destructor(48,&yymsp[0].minor);
}
/* #line 2454 "parser.c" */
        break;
      case 116:
      case 119:
/* #line 1126 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_NOTIN, yymsp[-5].minor.yy204, yymsp[-1].minor.yy204);
  yy_destructor(29,&yymsp[-4].minor);
  yy_destructor(28,&yymsp[-3].minor);
  yy_destructor(47,&yymsp[-2].minor);
  yy_destructor(48,&yymsp[0].minor);
}
/* #line 2466 "parser.c" */
        break;
      case 117:
/* #line 1130 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_SUBQUERY, yymsp[-1].minor.yy204, NULL);
  yy_destructor(47,&yymsp[-2].minor);
  yy_destructor(48,&yymsp[0].minor);
}
/* #line 2475 "parser.c" */
        break;
      case 120:
/* #line 1142 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_EXISTS, NULL, yymsp[-1].minor.yy204);
  yy_destructor(69,&yymsp[-3].minor);
  yy_destructor(47,&yymsp[-2].minor);
  yy_destructor(48,&yymsp[0].minor);
}
/* #line 2485 "parser.c" */
        break;
      case 121:
/* #line 1146 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_AGAINST, yymsp[-2].minor.yy204, yymsp[0].minor.yy204);
  yy_destructor(1,&yymsp[-1].minor);
}
/* #line 2493 "parser.c" */
        break;
      case 122:
/* #line 1150 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_CAST, yymsp[-3].minor.yy204, phql_ret_raw_qualified_name(yymsp[-1].minor.yy0, NULL));
  yy_destructor(70,&yymsp[-5].minor);
  yy_destructor(47,&yymsp[-4].minor);
  yy_destructor(38,&yymsp[-2].minor);
  yy_destructor(48,&yymsp[0].minor);
}
/* #line 2504 "parser.c" */
        break;
      case 123:
/* #line 1154 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_CONVERT, yymsp[-3].minor.yy204, phql_ret_raw_qualified_name(yymsp[-1].minor.yy0, NULL));
  yy_destructor(71,&yymsp[-5].minor);
  yy_destructor(47,&yymsp[-4].minor);
  yy_destructor(72,&yymsp[-2].minor);
  yy_destructor(48,&yymsp[0].minor);
}
/* #line 2515 "parser.c" */
        break;
      case 124:
/* #line 1158 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_CASE, yymsp[-2].minor.yy204, yymsp[-1].minor.yy204);
  yy_destructor(73,&yymsp[-3].minor);
  yy_destructor(74,&yymsp[0].minor);
}
/* #line 2524 "parser.c" */
        break;
      case 127:
/* #line 1170 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_WHEN, yymsp[-2].minor.yy204, yymsp[0].minor.yy204);
  yy_destructor(75,&yymsp[-3].minor);
  yy_destructor(76,&yymsp[-1].minor);
}
/* #line 2533 "parser.c" */
        break;
      case 128:
/* #line 1174 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_ELSE, yymsp[0].minor.yy204, NULL);
  yy_destructor(77,&yymsp[-1].minor);
}
/* #line 2541 "parser.c" */
        break;
      case 130:
/* #line 1184 "parser.y" */
{
	yygotominor.yy204 = phql_ret_func_call(yymsp[-4].minor.yy0, yymsp[-1].minor.yy204, yymsp[-2].minor.yy204);
  yy_destructor(47,&yymsp[-3].minor);
  yy_destructor(48,&yymsp[0].minor);
}
/* #line 2550 "parser.c" */
        break;
      case 131:
/* #line 1190 "parser.y" */
{
	yygotominor.yy204 = phql_ret_distinct();
  yy_destructor(34,&yymsp[0].minor);
}
/* #line 2558 "parser.c" */
        break;
      case 139:
/* #line 1228 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_ISNULL, yymsp[-2].minor.yy204, NULL);
  yy_destructor(27,&yymsp[-1].minor);
  yy_destructor(78,&yymsp[0].minor);
}
/* #line 2567 "parser.c" */
        break;
      case 140:
/* #line 1232 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_ISNOTNULL, yymsp[-3].minor.yy204, NULL);
  yy_destructor(27,&yymsp[-2].minor);
  yy_destructor(29,&yymsp[-1].minor);
  yy_destructor(78,&yymsp[0].minor);
}
/* #line 2577 "parser.c" */
        break;
      case 141:
/* #line 1236 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_BETWEEN, yymsp[-2].minor.yy204, yymsp[0].minor.yy204);
  yy_destructor(2,&yymsp[-1].minor);
}
/* #line 2585 "parser.c" */
        break;
      case 142:
/* #line 1240 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_NOT, NULL, yymsp[0].minor.yy204);
  yy_destructor(29,&yymsp[-1].minor);
}
/* #line 2593 "parser.c" */
        break;
      case 143:
/* #line 1244 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_BITWISE_NOT, NULL, yymsp[0].minor.yy204);
  yy_destructor(30,&yymsp[-1].minor);
}
/* #line 2601 "parser.c" */
        break;
      case 144:
/* #line 1248 "parser.y" */
{
	yygotominor.yy204 = phql_ret_expr(PHQL_T_ENCLOSED, yymsp[-1].minor.yy204, NULL);
  yy_destructor(47,&yymsp[-2].minor);
  yy_destructor(48,&yymsp[0].minor);
}
/* #line 2610 "parser.c" */
        break;
      case 148:
/* #line 1264 "parser.y" */
{
	yygotominor.yy204 = phql_ret_literal_zval(PHQL_T_STRING, yymsp[0].minor.yy0);
}
/* #line 2617 "parser.c" */
        break;
      case 149:
/* #line 1268 "parser.y" */
{
	yygotominor.yy204 = phql_ret_literal_zval(PHQL_T_DOUBLE, yymsp[0].minor.yy0);
}
/* #line 2624 "parser.c" */
        break;
      case 150:
/* #line 1272 "parser.y" */
{
	yygotominor.yy204 = phql_ret_literal_zval(PHQL_T_NULL, NULL);
  yy_destructor(78,&yymsp[0].minor);
}
/* #line 2632 "parser.c" */
        break;
      case 151:
/* #line 1276 "parser.y" */
{
	yygotominor.yy204 = phql_ret_literal_zval(PHQL_T_TRUE, NULL);
  yy_destructor(81,&yymsp[0].minor);
}
/* #line 2640 "parser.c" */
        break;
      case 152:
/* #line 1280 "parser.y" */
{
	yygotominor.yy204 = phql_ret_literal_zval(PHQL_T_FALSE, NULL);
  yy_destructor(82,&yymsp[0].minor);
}
/* #line 2648 "parser.c" */
        break;
      case 155:
/* #line 1292 "parser.y" */
{
	yygotominor.yy204 = phql_ret_placeholder_zval(PHQL_T_NTPLACEHOLDER, yymsp[0].minor.yy0);
}
/* #line 2655 "parser.c" */
        break;
      case 156:
/* #line 1296 "parser.y" */
{
	yygotominor.yy204 = phql_ret_placeholder_zval(PHQL_T_STPLACEHOLDER, yymsp[0].minor.yy0);
}
/* #line 2662 "parser.c" */
        break;
      case 157:
/* #line 1302 "parser.y" */
{
	yygotominor.yy204 = phql_ret_qualified_name(yymsp[-4].minor.yy0, yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(85,&yymsp[-3].minor);
  yy_destructor(37,&yymsp[-1].minor);
}
/* #line 2671 "parser.c" */
        break;
      case 158:
/* #line 1306 "parser.y" */
{
	yygotominor.yy204 = phql_ret_qualified_name(yymsp[-2].minor.yy0, NULL, yymsp[0].minor.yy0);
  yy_destructor(85,&yymsp[-1].minor);
}
/* #line 2679 "parser.c" */
        break;
      case 159:
/* #line 1310 "parser.y" */
{
	yygotominor.yy204 = phql_ret_qualified_name(NULL, yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(37,&yymsp[-1].minor);
}
/* #line 2687 "parser.c" */
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
  phql_ARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sFail!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser fails */
  phql_ARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following code executes when a syntax error first occurs.
*/
static void yy_syntax_error(
  yyParser *yypParser,           /* The parser */
  int yymajor,                   /* The major type of the error token */
  YYMINORTYPE yyminor            /* The minor type of the error token */
){
  phql_ARG_FETCH;
#define TOKEN (yyminor.yy0)
/* #line 506 "parser.y" */

	if (status->scanner_state->start_length) {
		{

			char *token_name = NULL;
			int token_found = 0;
			unsigned int token_length;
			const phql_token_names *tokens = phql_tokens;
			uint active_token = status->scanner_state->active_token;
			uint near_length = status->scanner_state->start_length;

			if (active_token) {

				do {
					if (tokens->code == active_token) {
						token_name = tokens->name;
						token_length = tokens->length;
						token_found = 1;
						break;
					}
					++tokens;
				} while (tokens[0].code != 0);

			}

			if (!token_name) {
				token_length = strlen("UNKNOWN");
				token_name = estrndup("UNKNOWN", token_length);
				token_found = 0;
			}

			status->syntax_error_len = 96 + status->token->len + token_length + near_length + status->phql_length;;
			status->syntax_error = emalloc(sizeof(char) * status->syntax_error_len);

			if (near_length > 0) {
				if (status->token->value) {
					snprintf(status->syntax_error, status->syntax_error_len, "Syntax error, unexpected token %s(%s), near to '%s', when parsing: %s (%d)", token_name, status->token->value, status->scanner_state->start, status->phql, status->phql_length);
				} else {
					snprintf(status->syntax_error, status->syntax_error_len, "Syntax error, unexpected token %s, near to '%s', when parsing: %s (%d)", token_name, status->scanner_state->start, status->phql, status->phql_length);
				}
			} else {
				if (active_token != PHQL_T_IGNORE) {
					if (status->token->value) {
						snprintf(status->syntax_error, status->syntax_error_len, "Syntax error, unexpected token %s(%s), at the end of query, when parsing: %s (%d)", token_name, status->token->value, status->phql, status->phql_length);
					} else {
						snprintf(status->syntax_error, status->syntax_error_len, "Syntax error, unexpected token %s, at the end of query, when parsing: %s (%d)", token_name, status->phql, status->phql_length);
					}
				} else {
					snprintf(status->syntax_error, status->syntax_error_len, "Syntax error, unexpected EOF, at the end of query");
				}
				status->syntax_error[status->syntax_error_len - 1] = '\0';
			}

			if (!token_found) {
				if (token_name) {
					efree(token_name);
				}
			}
		}
	} else {
		status->syntax_error_len = strlen("Syntax error, unexpected EOF");
		status->syntax_error = estrndup("Syntax error, unexpected EOF", status->syntax_error_len);
	}

	status->status = PHQL_PARSING_FAILED;

/* #line 2796 "parser.c" */
  phql_ARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following is executed when the parser accepts
*/
static void yy_accept(
  yyParser *yypParser           /* The parser */
){
  phql_ARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sAccept!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser accepts */
  phql_ARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/* The main parser program.
** The first argument is a pointer to a structure obtained from
** "phql_Alloc" which describes the current state of the parser.
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
void phql_(
  void *yyp,                   /* The parser */
  int yymajor,                 /* The major token code number */
  phql_TOKENTYPE yyminor       /* The value for the token */
  phql_ARG_PDECL               /* Optional %extra_argument parameter */
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
  phql_ARG_STORE;

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

const phql_token_names phql_tokens[] =
{
  { SL("INTEGER"),       PHQL_T_INTEGER },
  { SL("DOUBLE"),        PHQL_T_DOUBLE },
  { SL("STRING"),        PHQL_T_STRING },
  { SL("IDENTIFIER"),    PHQL_T_IDENTIFIER },
  { SL("MINUS"),         PHQL_T_MINUS },
  { SL("+"),             PHQL_T_ADD },
  { SL("-"),             PHQL_T_SUB },
  { SL("*"),             PHQL_T_MUL },
  { SL("/"),             PHQL_T_DIV },
  { SL("&"),             PHQL_T_BITWISE_AND },
  { SL("|"),             PHQL_T_BITWISE_OR },
  { SL("%%"),            PHQL_T_MOD },
  { SL("AND"),           PHQL_T_AND },
  { SL("OR"),            PHQL_T_OR },
  { SL("LIKE"),          PHQL_T_LIKE },
  { SL("ILIKE"),         PHQL_T_ILIKE },
  { SL("DOT"),           PHQL_T_DOT },
  { SL("COLON"),         PHQL_T_COLON },
  { SL("COMMA"),         PHQL_T_COMMA },
  { SL("EQUALS"),        PHQL_T_EQUALS },
  { SL("NOT EQUALS"),    PHQL_T_NOTEQUALS },
  { SL("NOT"),           PHQL_T_NOT },
  { SL("<"),             PHQL_T_LESS },
  { SL("<="),            PHQL_T_LESSEQUAL },
  { SL(">"),             PHQL_T_GREATER },
  { SL(">="),            PHQL_T_GREATEREQUAL },
  { SL("@@"),            PHQL_T_TS_MATCHES },
  { SL("||"),            PHQL_T_TS_OR },
  { SL("&&"),            PHQL_T_TS_AND },
  { SL("!!"),            PHQL_T_TS_NEGATE },
  { SL("@>"),            PHQL_T_TS_CONTAINS_ANOTHER },
  { SL("<@"),            PHQL_T_TS_CONTAINS_IN },
  { SL("("),             PHQL_T_PARENTHESES_OPEN },
  { SL(")"),             PHQL_T_PARENTHESES_CLOSE },
  { SL("NUMERIC PLACEHOLDER"), PHQL_T_NPLACEHOLDER },
  { SL("STRING PLACEHOLDER"),  PHQL_T_SPLACEHOLDER },
  { SL("UPDATE"),        PHQL_T_UPDATE },
  { SL("SET"),           PHQL_T_SET },
  { SL("WHERE"),         PHQL_T_WHERE },
  { SL("DELETE"),        PHQL_T_DELETE },
  { SL("FROM"),          PHQL_T_FROM },
  { SL("AS"),            PHQL_T_AS },
  { SL("INSERT"),        PHQL_T_INSERT },
  { SL("INTO"),          PHQL_T_INTO },
  { SL("VALUES"),        PHQL_T_VALUES },
  { SL("SELECT"),        PHQL_T_SELECT },
  { SL("ORDER"),         PHQL_T_ORDER },
  { SL("BY"),            PHQL_T_BY },
  { SL("LIMIT"),         PHQL_T_LIMIT },
  { SL("OFFSET"),        PHQL_T_OFFSET },
  { SL("GROUP"),         PHQL_T_GROUP },
  { SL("HAVING"),        PHQL_T_HAVING },
  { SL("IN"),            PHQL_T_IN },
  { SL("ON"),            PHQL_T_ON },
  { SL("INNER"),         PHQL_T_INNER },
  { SL("JOIN"),          PHQL_T_JOIN },
  { SL("LEFT"),          PHQL_T_LEFT },
  { SL("RIGHT"),         PHQL_T_RIGHT },
  { SL("IS"),            PHQL_T_IS },
  { SL("NULL"),          PHQL_T_NULL },
  { SL("NOT IN"),        PHQL_T_NOTIN },
  { SL("CROSS"),         PHQL_T_CROSS },
  { SL("OUTER"),         PHQL_T_OUTER },
  { SL("FULL"),          PHQL_T_FULL },
  { SL("ASC"),           PHQL_T_ASC },
  { SL("DESC"),          PHQL_T_DESC },
  { SL("BETWEEN"),       PHQL_T_BETWEEN },
  { SL("DISTINCT"),      PHQL_T_DISTINCT },
  { SL("AGAINST"),       PHQL_T_AGAINST },
  { SL("CAST"),          PHQL_T_CAST },
  { SL("CONVERT"),       PHQL_T_CONVERT },
  { SL("USING"),         PHQL_T_USING },
  { SL("ALL"),           PHQL_T_ALL },
  { SL("FOR"),           PHQL_T_FOR },
  { SL("EXISTS"),        PHQL_T_EXISTS },
  { SL("CASE"),          PHQL_T_CASE },
  { SL("WHEN"),          PHQL_T_WHEN },
  { SL("THEN"),          PHQL_T_THEN },
  { SL("ELSE"),          PHQL_T_ELSE },
  { SL("END"),           PHQL_T_END },
  { NULL, 0, 0 }
};

static void *phql_wrapper_alloc(size_t bytes){
	return emalloc(bytes);
}

static void phql_wrapper_free(void *pointer){
	efree(pointer);
}

static void phql_parse_with_token(void* phql_parser, int opcode, int parsercode, phql_scanner_token *token, phql_parser_status *parser_status){

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
static void phql_scanner_error_msg(phql_parser_status *parser_status, zval **error_msg TSRMLS_DC){

	char *error = NULL, *error_part;
	unsigned int length;
	phql_scanner_state *state = parser_status->scanner_state;

	MAKE_STD_ZVAL(*error_msg);
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
		ZVAL_STRING(*error_msg, error, 1);
	} else {
		ZVAL_STRING(*error_msg, "Scanning error near to EOF", 1);
	}

	if (error) {
		efree(error);
	}
}

/**
 * Executes the internal PHQL parser/tokenizer
 */
int phql_parse_phql(zval *result, zval *phql TSRMLS_DC) {

	zval *error_msg = NULL;

	ZVAL_NULL(result);

	if (phql_internal_parse_phql(&result, Z_STRVAL_P(phql), Z_STRLEN_P(phql), &error_msg TSRMLS_CC) == FAILURE) {
		if (likely(error_msg != NULL)) {
			PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, Z_STRVAL_P(error_msg));
			zval_ptr_dtor(&error_msg);
		}
		else {
			PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, "There was an error parsing PHQL");
		}

		return FAILURE;
	}

	return SUCCESS;
}

/**
 * Executes a PHQL parser/tokenizer
 */
int phql_internal_parse_phql(zval **result, char *phql, unsigned int phql_length, zval **error_msg TSRMLS_DC) {

	zend_phalcon_globals *phalcon_globals_ptr = PHALCON_VGLOBAL;
	phql_parser_status *parser_status = NULL;
	int scanner_status, status = SUCCESS, error_length;
	phql_scanner_state *state;
	phql_scanner_token token;
	void* phql_parser;
	char *error;
	zval *unique_id;

	if (!phql) {
		MAKE_STD_ZVAL(*error_msg);
		ZVAL_STRING(*error_msg, "PHQL statement cannot be NULL", 1);
		return FAILURE;
	}

	MAKE_STD_ZVAL(unique_id);
	ZVAL_LONG(unique_id, zend_inline_hash_func(phql, phql_length + 1));

	phalcon_orm_get_prepared_ast(result, unique_id TSRMLS_CC);

	if (Z_TYPE_PP(result) == IS_ARRAY) {
		zval_ptr_dtor(&unique_id);
		return SUCCESS;
	}

	phql_parser = phql_Alloc(phql_wrapper_alloc);
	if (unlikely(!phql_parser)) {
		MAKE_STD_ZVAL(*error_msg);
		ZVAL_STRING(*error_msg, "Memory allocation error", 1);
		return FAILURE;
	}

	parser_status = emalloc(sizeof(phql_parser_status));
	state = emalloc(sizeof(phql_scanner_state));

	parser_status->status = PHQL_PARSING_OK;
	parser_status->scanner_state = state;
	parser_status->ret = NULL;
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

			case PHQL_T_INTEGER:
				if (parser_status->enable_literals) {
					phql_parse_with_token(phql_parser, PHQL_T_INTEGER, PHQL_INTEGER, &token, parser_status);
				} else {
					MAKE_STD_ZVAL(*error_msg);
					ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements", 1);
					parser_status->status = PHQL_PARSING_FAILED;
				}
				break;
			case PHQL_T_DOUBLE:
				if (parser_status->enable_literals) {
					phql_parse_with_token(phql_parser, PHQL_T_DOUBLE, PHQL_DOUBLE, &token, parser_status);
				} else {
					MAKE_STD_ZVAL(*error_msg);
					ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements", 1);
					parser_status->status = PHQL_PARSING_FAILED;
				}
				break;
			case PHQL_T_STRING:
				if (parser_status->enable_literals) {
					phql_parse_with_token(phql_parser, PHQL_T_STRING, PHQL_STRING, &token, parser_status);
				} else {
					MAKE_STD_ZVAL(*error_msg);
					ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements", 1);
					parser_status->status = PHQL_PARSING_FAILED;
				}
				break;
			case PHQL_T_TRUE:
				if (parser_status->enable_literals) {
					phql_(phql_parser, PHQL_TRUE, NULL, parser_status);
				} else {
					MAKE_STD_ZVAL(*error_msg);
					ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements", 1);
					parser_status->status = PHQL_PARSING_FAILED;
				}
				break;
			case PHQL_T_FALSE:
				if (parser_status->enable_literals) {
					phql_(phql_parser, PHQL_FALSE, NULL, parser_status);
				} else {
					MAKE_STD_ZVAL(*error_msg);
					ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements", 1);
					parser_status->status = PHQL_PARSING_FAILED;
				}
				break;

			case PHQL_T_NPLACEHOLDER:
				phql_parse_with_token(phql_parser, PHQL_T_NPLACEHOLDER, PHQL_NPLACEHOLDER, &token, parser_status);
				break;
			case PHQL_T_SPLACEHOLDER:
				phql_parse_with_token(phql_parser, PHQL_T_SPLACEHOLDER, PHQL_SPLACEHOLDER, &token, parser_status);
				break;
            case PHQL_T_NTPLACEHOLDER:
    			phql_parse_with_token(phql_parser, PHQL_T_NTPLACEHOLDER, PHQL_NTPLACEHOLDER, &token, parser_status);
    			break;
    		case PHQL_T_STPLACEHOLDER:
    			phql_parse_with_token(phql_parser, PHQL_T_STPLACEHOLDER, PHQL_STPLACEHOLDER, &token, parser_status);
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
			case PHQL_T_TS_MATCHES:
				phql_(phql_parser, PHQL_TS_MATCHES, NULL, parser_status);
				break;
			case PHQL_T_TS_OR:
				phql_(phql_parser, PHQL_TS_OR, NULL, parser_status);
				break;
			case PHQL_T_TS_AND:
				phql_(phql_parser, PHQL_TS_AND, NULL, parser_status);
				break;
			case PHQL_T_TS_NEGATE:
				phql_(phql_parser, PHQL_TS_NEGATE, NULL, parser_status);
				break;
			case PHQL_T_TS_CONTAINS_ANOTHER:
				phql_(phql_parser, PHQL_TS_CONTAINS_ANOTHER, NULL, parser_status);
				break;
			case PHQL_T_TS_CONTAINS_IN:
				phql_(phql_parser, PHQL_TS_CONTAINS_IN, NULL, parser_status);
				break;
			case PHQL_T_FOR:
				phql_(phql_parser, PHQL_FOR, NULL, parser_status);
				break;
			default:
				parser_status->status = PHQL_PARSING_FAILED;
				error_length = sizeof(char) * 32;
				error = emalloc(error_length);
				snprintf(error, error_length, "Scanner: Unknown opcode %c", token.opcode);
				error[error_length - 1] = '\0';
				MAKE_STD_ZVAL(*error_msg);
				ZVAL_STRING(*error_msg, error, 1);
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
				if (!*error_msg) {
					if (!*error_msg) {
						phql_scanner_error_msg(parser_status, error_msg TSRMLS_CC);
					}
				}
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
			if (!*error_msg) {
				MAKE_STD_ZVAL(*error_msg);
				ZVAL_STRING(*error_msg, parser_status->syntax_error, 1);
			}
			efree(parser_status->syntax_error);
		}
	}

	phql_Free(phql_parser, phql_wrapper_free);

	if (status != FAILURE) {
		if (parser_status->status == PHQL_PARSING_OK) {
			if (parser_status->ret) {

				/**
				 * Set a unique id for the parsed ast
				 */
				if (phalcon_globals_ptr->orm.cache_level >= 1) {
					if (Z_TYPE_P(parser_status->ret) == IS_ARRAY) {
						add_assoc_long(parser_status->ret, "id", Z_LVAL_P(unique_id));
					}
				}

				ZVAL_ZVAL(*result, parser_status->ret, 0, 0);
				ZVAL_NULL(parser_status->ret);
				zval_ptr_dtor(&parser_status->ret);

				/**
				 * Store the parsed definition in the cache
				 */
				phalcon_orm_set_prepared_ast(unique_id, *result TSRMLS_CC);

			} else {
				efree(parser_status->ret);
			}
		}
	}

	zval_ptr_dtor(&unique_id);

	efree(parser_status);
	efree(state);

	return status;
}
