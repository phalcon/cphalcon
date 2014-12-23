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
	array_init(ret);
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

static zval *phql_ret_select_statement(zval *S, zval *W, zval *O, zval *G, zval *H, zval *L)
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


/* #line 461 "parser.c" */
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
#define YYNOCODE 126
#define YYACTIONTYPE unsigned short int
#define phql_TOKENTYPE phql_parser_token*
typedef union {
  phql_TOKENTYPE yy0;
  zval* yy158;
  int yy251;
} YYMINORTYPE;
#define YYSTACKDEPTH 100
#define phql_ARG_SDECL phql_parser_status *status;
#define phql_ARG_PDECL ,phql_parser_status *status
#define phql_ARG_FETCH phql_parser_status *status = yypParser->status
#define phql_ARG_STORE yypParser->status = status
#define YYNSTATE 265
#define YYNRULE 146
#define YYERRORSYMBOL 76
#define YYERRSYMDT yy251
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
 /*     0 */    66,   72,   32,   34,   36,   38,   40,   54,   42,   44,
 /*    10 */    46,   48,   50,   52,   22,   24,   56,   61,   26,   28,
 /*    20 */    30,   18,   16,   20,   14,   11,   68,   63,   58,   32,
 /*    30 */    34,   36,   38,   40,   54,   42,   44,   46,   48,   50,
 /*    40 */    52,   22,   24,   56,   61,   26,   28,   30,   18,   16,
 /*    50 */    20,   14,   11,   68,   63,   58,   70,  153,  154,   66,
 /*    60 */    72,   32,   34,   36,   38,   40,   54,   42,   44,   46,
 /*    70 */    48,   50,   52,   22,   24,   56,   61,   26,   28,   30,
 /*    80 */    18,   16,   20,   14,   11,   68,   63,   58,   14,   11,
 /*    90 */    68,   63,   58,  212,  221,  170,  219,   69,   66,   72,
 /*   100 */    32,   34,   36,   38,   40,   54,   42,   44,   46,   48,
 /*   110 */    50,   52,   22,   24,   56,   61,   26,   28,   30,   18,
 /*   120 */    16,   20,   14,   11,   68,   63,   58,   18,   16,   20,
 /*   130 */    14,   11,   68,   63,   58,   77,    5,   66,   72,   32,
 /*   140 */    34,   36,   38,   40,   54,   42,   44,   46,   48,   50,
 /*   150 */    52,   22,   24,   56,   61,   26,   28,   30,   18,   16,
 /*   160 */    20,   14,   11,   68,   63,   58,   66,   72,   32,   34,
 /*   170 */    36,   38,   40,   54,   42,   44,   46,   48,   50,   52,
 /*   180 */    22,   24,   56,   61,   26,   28,   30,   18,   16,   20,
 /*   190 */    14,   11,   68,   63,   58,  172,  223,  224,  173,  181,
 /*   200 */   210,  183,  184,   59,  122,   83,  193,  209,  195,  197,
 /*   210 */   265,  201,  205,  102,  124,   66,   72,   32,   34,   36,
 /*   220 */    38,   40,   54,   42,   44,   46,   48,   50,   52,   22,
 /*   230 */    24,   56,   61,   26,   28,   30,   18,   16,   20,   14,
 /*   240 */    11,   68,   63,   58,   42,   44,   46,   48,   50,   52,
 /*   250 */    22,   24,   56,   61,   26,   28,   30,   18,   16,   20,
 /*   260 */    14,   11,   68,   63,   58,   95,  118,  266,   12,   65,
 /*   270 */    65,   96,   98,  216,    8,   65,   88,  200,   87,   95,
 /*   280 */   198,  118,   12,   88,   58,   96,   98,  103,  103,  100,
 /*   290 */   387,    7,   87,  103,  344,   92,   86,   86,   90,  112,
 /*   300 */    94,  120,   86,  100,  114,  112,  104,  110,  111,   74,
 /*   310 */    80,  114,  107,  105,  106,  108,  109,   64,  152,  114,
 /*   320 */   104,  110,  111,   74,   80,  163,  107,  105,  106,  108,
 /*   330 */   109,  214,   71,  178,   12,  176,  103,   96,   98,  149,
 /*   340 */   155,  174,   10,  103,  215,   86,  175,   12,  160,  164,
 /*   350 */    96,   98,   86,  185,    9,  100,  138,   87,  179,  267,
 /*   360 */   103,  193,  209,  195,  197,  179,  201,  205,  100,   86,
 /*   370 */   217,   75,  104,  110,  111,   74,   80,   78,  107,  105,
 /*   380 */   106,  108,  109,  119,   79,  104,  110,  111,   74,   80,
 /*   390 */     4,  107,  105,  106,  108,  109,   22,   24,   56,   61,
 /*   400 */    26,   28,   30,   18,   16,   20,   14,   11,   68,   63,
 /*   410 */    58,   56,   61,   26,   28,   30,   18,   16,   20,   14,
 /*   420 */    11,   68,   63,   58,   26,   28,   30,   18,   16,   20,
 /*   430 */    14,   11,   68,   63,   58,  412,    1,    2,    3,  130,
 /*   440 */   131,  132,   10,  169,   10,  232,  222,  218,   81,  228,
 /*   450 */    65,    6,  204,  230,  129,  202,  129,   68,   63,   58,
 /*   460 */   103,   10,  103,  227,  167,  103,  243,  152,  103,   86,
 /*   470 */   237,   86,  259,  129,   86,  179,  126,   86,   84,  103,
 /*   480 */   112,  225,  163,  171,  248,  103,  262,  211,   86,  151,
 /*   490 */   128,  113,  175,  257,   86,  213,  218,   13,   15,  208,
 /*   500 */   103,   17,  206,   19,  179,  249,  162,   89,  103,   86,
 /*   510 */   175,  103,  256,   21,  103,  103,  103,   86,   23,  103,
 /*   520 */    86,  103,  179,   86,   86,   86,  253,  254,   86,   25,
 /*   530 */    86,  103,   27,   29,   31,   33,  103,   35,  233,   37,
 /*   540 */    86,  242,  142,  143,  144,   86,   93,  103,  346,   39,
 /*   550 */   103,  103,  103,  103,   41,  103,   86,  103,  125,   86,
 /*   560 */    86,   86,   86,  386,   86,   43,   86,  103,   45,   47,
 /*   570 */    85,   49,  103,   91,  115,   51,   86,  116,  117,   53,
 /*   580 */   119,   86,   55,  103,  268,   57,  103,  103,   93,  103,
 /*   590 */    60,  269,   86,  103,  165,   86,   86,  103,   86,  134,
 /*   600 */   103,   62,   86,  103,   67,  121,   86,   73,  103,   86,
 /*   610 */   246,   76,   86,  133,   82,   97,  341,   86,   99,  103,
 /*   620 */   156,  158,  103,  135,  270,  103,  101,  147,   86,  103,
 /*   630 */   123,   86,  103,  103,   86,   93,  103,  157,   86,    8,
 /*   640 */   166,   86,   86,  136,  103,   86,  137,  140,  103,  182,
 /*   650 */   183,  184,  127,   86,  189,  103,  231,   86,  103,  342,
 /*   660 */   251,  258,  254,  264,   86,  239,    8,   86,  175,  192,
 /*   670 */   139,  190,  103,  141,  146,  343,  148,  150,  159,  145,
 /*   680 */   179,   86,  234,  238,  161,  168,  180,  177,  186,  188,
 /*   690 */   187,  191,  194,  293,  196,  226,  294,  295,  199,  296,
 /*   700 */   297,  298,  203,  299,  300,  301,  207,  220,  241,  240,
 /*   710 */   244,  313,  245,  247,  345,  252,  255,  229,  261,  319,
 /*   720 */   260,  236,  263,  273,  235,  273,  273,  273,  273,  250,
};
static YYCODETYPE yy_lookahead[] = {
 /*     0 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    10 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*    20 */    21,   22,   23,   24,   25,   26,   27,   28,   29,    3,
 /*    30 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*    40 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*    50 */    24,   25,   26,   27,   28,   29,   29,   58,   59,    1,
 /*    60 */     2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*    70 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*    80 */    22,   23,   24,   25,   26,   27,   28,   29,   25,   26,
 /*    90 */    27,   28,   29,   31,   36,   33,   38,   70,    1,    2,
 /*   100 */     3,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   110 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   120 */    23,   24,   25,   26,   27,   28,   29,   22,   23,   24,
 /*   130 */    25,   26,   27,   28,   29,   38,   47,    1,    2,    3,
 /*   140 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   150 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   160 */    24,   25,   26,   27,   28,   29,    1,    2,    3,    4,
 /*   170 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   180 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   24,
 /*   190 */    25,   26,   27,   28,   29,   92,   34,   35,   31,   96,
 /*   200 */    97,   98,   99,   17,   18,   69,   39,   40,   41,   42,
 /*   210 */     0,   44,   45,   48,   28,    1,    2,    3,    4,    5,
 /*   220 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   230 */    16,   17,   18,   19,   20,   21,   22,   23,   24,   25,
 /*   240 */    26,   27,   28,   29,    9,   10,   11,   12,   13,   14,
 /*   250 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   24,
 /*   260 */    25,   26,   27,   28,   29,   23,   37,    0,   26,   94,
 /*   270 */    94,   29,   30,   37,   31,   94,   47,   40,   36,   23,
 /*   280 */    43,   37,   26,   47,   29,   29,   30,  112,  112,   47,
 /*   290 */    48,   48,   36,  112,    0,  120,  121,  121,  123,  124,
 /*   300 */   124,  120,  121,   47,   75,  124,   64,   65,   66,   67,
 /*   310 */    68,   75,   70,   71,   72,   73,   74,   47,   94,   75,
 /*   320 */    64,   65,   66,   67,   68,   94,   70,   71,   72,   73,
 /*   330 */    74,   23,   70,   36,   26,   38,  112,   29,   30,  115,
 /*   340 */   116,   95,   94,  112,   36,  121,  100,   26,  117,  118,
 /*   350 */    29,   30,  121,  100,  106,   47,   62,   36,  112,    0,
 /*   360 */   112,   39,   40,   41,   42,  112,   44,   45,   47,  121,
 /*   370 */    23,   47,   64,   65,   66,   67,   68,   36,   70,   71,
 /*   380 */    72,   73,   74,   36,   48,   64,   65,   66,   67,   68,
 /*   390 */    31,   70,   71,   72,   73,   74,   15,   16,   17,   18,
 /*   400 */    19,   20,   21,   22,   23,   24,   25,   26,   27,   28,
 /*   410 */    29,   17,   18,   19,   20,   21,   22,   23,   24,   25,
 /*   420 */    26,   27,   28,   29,   19,   20,   21,   22,   23,   24,
 /*   430 */    25,   26,   27,   28,   29,   77,   78,   79,   80,   81,
 /*   440 */    82,   83,   94,   90,   94,   47,   93,   94,   47,   51,
 /*   450 */    94,  103,   40,  103,  106,   43,  106,   27,   28,   29,
 /*   460 */   112,   94,  112,  100,   32,  112,  108,   94,  112,  121,
 /*   470 */   103,  121,  114,  106,  121,  112,  120,  121,   36,  112,
 /*   480 */   124,   49,   94,   91,   52,  112,   54,   95,  121,  116,
 /*   490 */    94,   34,  100,   94,  121,   93,   94,   94,   94,   40,
 /*   500 */   112,   94,   43,   94,  112,   95,  118,  122,  112,  121,
 /*   510 */   100,  112,  113,   94,  112,  112,  112,  121,   94,  112,
 /*   520 */   121,  112,  112,  121,  121,  121,  111,  112,  121,   94,
 /*   530 */   121,  112,   94,   94,   94,   94,  112,   94,  104,   94,
 /*   540 */   121,  107,   64,   65,   66,  121,   31,  112,    0,   94,
 /*   550 */   112,  112,  112,  112,   94,  112,  121,  112,   47,  121,
 /*   560 */   121,  121,  121,   48,  121,   94,  121,  112,   94,   94,
 /*   570 */    48,   94,  112,   48,   36,   94,  121,   37,   36,   94,
 /*   580 */    36,  121,   94,  112,    0,   94,  112,  112,   31,  112,
 /*   590 */    94,    0,  121,  112,   55,  121,  121,  112,  121,   85,
 /*   600 */   112,   94,  121,  112,   94,   48,  121,   94,  112,  121,
 /*   610 */    62,   94,  121,   84,   94,   94,    0,  121,   94,  112,
 /*   620 */    61,   60,  112,   86,    0,  112,   94,   56,  121,  112,
 /*   630 */    94,  121,  112,  112,  121,   31,  112,   94,  121,   31,
 /*   640 */    94,  121,  121,   87,  112,  121,   88,   31,  112,   97,
 /*   650 */    98,   99,   48,  121,   94,  112,   48,  121,  112,    0,
 /*   660 */   110,  111,  112,   95,  121,   31,   31,  121,  100,   36,
 /*   670 */   119,   38,  112,  119,  119,    0,   57,   31,   57,   63,
 /*   680 */   112,  121,   48,   48,   31,   89,   36,   36,  101,   46,
 /*   690 */   102,   36,   40,   36,   40,   50,   36,   36,   40,   36,
 /*   700 */    36,   36,   40,   36,   36,   36,   40,   36,   36,  107,
 /*   710 */    84,    0,  109,  119,    0,   31,    3,   47,  109,    0,
 /*   720 */    84,   47,   33,  125,   51,  125,  125,  125,  125,   53,
};
#define YY_SHIFT_USE_DFLT (-2)
static short yy_shift_ofst[] = {
 /*     0 */   432,  210,  267,  359,   89,  321,  243,   -2,  321,   -2,
 /*    10 */   214,  321,  321,  430,  321,  430,  321,   63,  321,   63,
 /*    20 */   321,   63,  321,  394,  321,  394,  321,  105,  321,  105,
 /*    30 */   321,  105,  321,  235,  321,  235,  321,  235,  321,  235,
 /*    40 */   321,  235,  321,  381,  321,  381,  321,  381,  321,  381,
 /*    50 */   321,  381,  321,  381,  321,  235,  321,  405,  186,  321,
 /*    60 */   255,  321,  405,  270,  256,  214,  321,  214,   27,   -2,
 /*    70 */   262,   -2,  321,   26,  324,  321,   97,  341,  336,   -2,
 /*    80 */   401,  321,  136,  442,  522,   -2,   -2,  229,  457,  242,
 /*    90 */   525,   -2,  515,  256,   -2,   -2,  321,  255,  321,  255,
 /*   100 */   321,  165,   -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,
 /*   110 */    -2,   -2,   -2,   -2,  538,  540,  542,   -2,  544,   -2,
 /*   120 */   557,   -2,  321,  255,  511,  256,  604,   -2,  430,   -2,
 /*   130 */   584,  591,  539,  561,  559,  571,  294,  624,  478,  616,
 /*   140 */   478,  659,   -2,   -2,   -2,  478,  675,  619,  321,  646,
 /*   150 */   321,   -2,   -1,   -2,   -2,   -2,  321,  214,  621,  321,
 /*   160 */   653,  321,   -2,  214,   -2,  321,  214,  162,  308,   62,
 /*   170 */   650,  167,   -2,  650,   -2,  297,  651,   -2,   -2,   -2,
 /*   180 */   244,  322,   -2,   -2,  650,  633,  643,   -2,  321,  214,
 /*   190 */   655,   -2,   -2,  652,  657,  654,  660,  237,  658,  661,
 /*   200 */   663,  412,  662,  664,  665,  459,  666,  667,  668,  669,
 /*   210 */    -2,   -2,  308,   -2,   -2,  236,  347,   -2,   58,  671,
 /*   220 */    -2,   -2,   -2,   -2,   -2,  645,  650,  398,  670,  321,
 /*   230 */   608,   -2,  672,  634,  673,  674,  321,  635,   -2,  672,
 /*   240 */    -2,   -2,   -2,  539,  548,  711,  478,  714,  650,  676,
 /*   250 */   650,  684,  650,   -2,  713,  321,   -2,  214,   -2,  539,
 /*   260 */   548,  719,  689,  650,   -2,
};
#define YY_REDUCE_USE_DFLT (-1)
static short yy_reduce_ofst[] = {
 /*     0 */   358,   -1,   -1,   -1,   -1,  348,   -1,   -1,  248,   -1,
 /*    10 */    -1,  396,  403,   -1,  404,   -1,  407,   -1,  409,   -1,
 /*    20 */   419,   -1,  424,   -1,  435,   -1,  438,   -1,  439,   -1,
 /*    30 */   440,   -1,  441,   -1,  443,   -1,  445,   -1,  455,   -1,
 /*    40 */   460,   -1,  471,   -1,  474,   -1,  475,   -1,  477,   -1,
 /*    50 */   481,   -1,  485,   -1,  488,   -1,  491,   -1,   -1,  496,
 /*    60 */    -1,  507,   -1,   -1,  181,   -1,  510,   -1,   -1,   -1,
 /*    70 */    -1,   -1,  513,   -1,   -1,  517,   -1,   -1,   -1,   -1,
 /*    80 */    -1,  520,   -1,   -1,   -1,   -1,   -1,   -1,  385,  175,
 /*    90 */    -1,   -1,   -1,  176,   -1,   -1,  521,   -1,  524,   -1,
 /*   100 */   532,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   110 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   120 */    -1,   -1,  536,   -1,   -1,  356,   -1,   -1,   -1,   -1,
 /*   130 */    -1,   -1,  529,  514,  537,  556,  558,   -1,  551,   -1,
 /*   140 */   554,   -1,   -1,   -1,   -1,  555,   -1,   -1,  224,   -1,
 /*   150 */   373,   -1,   -1,   -1,   -1,   -1,  543,   -1,   -1,  231,
 /*   160 */    -1,  388,   -1,   -1,   -1,  546,   -1,  596,  353,   -1,
 /*   170 */   392,  103,   -1,  246,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   180 */    -1,  552,   -1,   -1,  253,  587,  588,   -1,  560,   -1,
 /*   190 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   200 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   210 */    -1,   -1,  402,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   220 */    -1,   -1,   -1,   -1,   -1,   -1,  363,   -1,   -1,  350,
 /*   230 */    -1,   -1,  434,   -1,   -1,   -1,  367,   -1,   -1,  602,
 /*   240 */    -1,   -1,   -1,  626,  603,   -1,  594,   -1,  410,   -1,
 /*   250 */   550,   -1,  415,   -1,   -1,  399,   -1,   -1,   -1,  636,
 /*   260 */   609,   -1,   -1,  568,   -1,
};
static YYACTIONTYPE yy_default[] = {
 /*     0 */   411,  411,  411,  411,  411,  411,  411,  304,  411,  307,
 /*    10 */   309,  411,  411,  350,  411,  352,  411,  353,  411,  354,
 /*    20 */   411,  355,  411,  356,  411,  357,  411,  358,  411,  359,
 /*    30 */   411,  360,  411,  361,  411,  362,  411,  363,  411,  364,
 /*    40 */   411,  365,  411,  366,  411,  367,  411,  368,  411,  369,
 /*    50 */   411,  370,  411,  371,  411,  372,  411,  373,  411,  411,
 /*    60 */   374,  411,  375,  411,  411,  391,  411,  379,  411,  392,
 /*    70 */   411,  393,  411,  394,  411,  411,  411,  411,  411,  380,
 /*    80 */   411,  411,  411,  411,  411,  381,  382,  410,  385,  411,
 /*    90 */   411,  383,  411,  411,  388,  390,  411,  395,  411,  396,
 /*   100 */   411,  411,  397,  398,  399,  400,  401,  402,  403,  404,
 /*   110 */   405,  406,  389,  384,  411,  408,  411,  407,  411,  409,
 /*   120 */   411,  377,  411,  376,  411,  411,  411,  378,  351,  308,
 /*   130 */   411,  411,  326,  335,  340,  328,  411,  411,  411,  411,
 /*   140 */   411,  411,  347,  348,  349,  411,  411,  411,  411,  327,
 /*   150 */   411,  329,  331,  332,  333,  330,  411,  339,  411,  411,
 /*   160 */   334,  411,  336,  338,  337,  411,  325,  274,  411,  411,
 /*   170 */   411,  285,  271,  411,  282,  323,  411,  321,  322,  324,
 /*   180 */   410,  284,  286,  288,  411,  292,  303,  289,  411,  302,
 /*   190 */   411,  290,  291,  411,  411,  411,  411,  411,  411,  411,
 /*   200 */   411,  411,  411,  411,  411,  411,  411,  411,  411,  411,
 /*   210 */   287,  283,  411,  275,  277,  410,  411,  278,  281,  411,
 /*   220 */   279,  280,  276,  272,  273,  411,  411,  411,  411,  411,
 /*   230 */   411,  305,  411,  411,  411,  411,  411,  411,  306,  411,
 /*   240 */   310,  312,  311,  326,  411,  411,  411,  411,  411,  411,
 /*   250 */   411,  314,  411,  315,  411,  411,  317,  318,  316,  326,
 /*   260 */   411,  411,  411,  411,  320,
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
  "INTEGER",       "NPLACEHOLDER",  "SPLACEHOLDER",  "CAST",        
  "CONVERT",       "USING",         "NULL",          "STRING",      
  "DOUBLE",        "TRUE",          "FALSE",         "COLON",       
  "error",         "program",       "query_language",  "select_statement",
  "insert_statement",  "update_statement",  "delete_statement",  "select_clause",
  "where_clause",  "group_clause",  "having_clause",  "order_clause",
  "select_limit_clause",  "distinct_all",  "column_list",   "associated_name_list",
  "join_list_or_null",  "column_item",   "expr",          "associated_name",
  "join_list",     "join_item",     "join_clause",   "join_type",   
  "aliased_or_qualified_name",  "join_associated_name",  "join_conditions",  "values_list", 
  "field_list",    "value_list",    "value_item",    "field_item",  
  "update_clause",  "limit_clause",  "update_item_list",  "update_item", 
  "qualified_name",  "new_value",     "delete_clause",  "order_list",  
  "order_item",    "group_list",    "group_item",    "integer_or_placeholder",
  "argument_list",  "function_call",  "distinct_or_null",  "argument_list_or_null",
  "argument_item",
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
 /*   5 */ "select_statement ::= select_clause where_clause group_clause having_clause order_clause select_limit_clause",
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
 /*  82 */ "integer_or_placeholder ::= INTEGER",
 /*  83 */ "integer_or_placeholder ::= NPLACEHOLDER",
 /*  84 */ "integer_or_placeholder ::= SPLACEHOLDER",
 /*  85 */ "expr ::= MINUS expr",
 /*  86 */ "expr ::= expr MINUS expr",
 /*  87 */ "expr ::= expr PLUS expr",
 /*  88 */ "expr ::= expr TIMES expr",
 /*  89 */ "expr ::= expr DIVIDE expr",
 /*  90 */ "expr ::= expr MOD expr",
 /*  91 */ "expr ::= expr AND expr",
 /*  92 */ "expr ::= expr OR expr",
 /*  93 */ "expr ::= expr BITWISE_AND expr",
 /*  94 */ "expr ::= expr BITWISE_OR expr",
 /*  95 */ "expr ::= expr BITWISE_XOR expr",
 /*  96 */ "expr ::= expr EQUALS expr",
 /*  97 */ "expr ::= expr NOTEQUALS expr",
 /*  98 */ "expr ::= expr LESS expr",
 /*  99 */ "expr ::= expr GREATER expr",
 /* 100 */ "expr ::= expr GREATEREQUAL expr",
 /* 101 */ "expr ::= expr TS_MATCHES expr",
 /* 102 */ "expr ::= expr TS_OR expr",
 /* 103 */ "expr ::= expr TS_AND expr",
 /* 104 */ "expr ::= expr TS_NEGATE expr",
 /* 105 */ "expr ::= expr TS_CONTAINS_ANOTHER expr",
 /* 106 */ "expr ::= expr TS_CONTAINS_IN expr",
 /* 107 */ "expr ::= expr LESSEQUAL expr",
 /* 108 */ "expr ::= expr LIKE expr",
 /* 109 */ "expr ::= expr NOT LIKE expr",
 /* 110 */ "expr ::= expr ILIKE expr",
 /* 111 */ "expr ::= expr NOT ILIKE expr",
 /* 112 */ "expr ::= expr IN PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 113 */ "expr ::= expr NOT IN PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 114 */ "expr ::= expr AGAINST expr",
 /* 115 */ "expr ::= CAST PARENTHESES_OPEN expr AS IDENTIFIER PARENTHESES_CLOSE",
 /* 116 */ "expr ::= CONVERT PARENTHESES_OPEN expr USING IDENTIFIER PARENTHESES_CLOSE",
 /* 117 */ "expr ::= function_call",
 /* 118 */ "function_call ::= IDENTIFIER PARENTHESES_OPEN distinct_or_null argument_list_or_null PARENTHESES_CLOSE",
 /* 119 */ "distinct_or_null ::= DISTINCT",
 /* 120 */ "distinct_or_null ::=",
 /* 121 */ "argument_list_or_null ::= argument_list",
 /* 122 */ "argument_list_or_null ::=",
 /* 123 */ "argument_list ::= argument_list COMMA argument_item",
 /* 124 */ "argument_list ::= argument_item",
 /* 125 */ "argument_item ::= TIMES",
 /* 126 */ "argument_item ::= expr",
 /* 127 */ "expr ::= expr IS NULL",
 /* 128 */ "expr ::= expr IS NOT NULL",
 /* 129 */ "expr ::= expr BETWEEN expr",
 /* 130 */ "expr ::= NOT expr",
 /* 131 */ "expr ::= BITWISE_NOT expr",
 /* 132 */ "expr ::= PARENTHESES_OPEN expr PARENTHESES_CLOSE",
 /* 133 */ "expr ::= qualified_name",
 /* 134 */ "expr ::= INTEGER",
 /* 135 */ "expr ::= STRING",
 /* 136 */ "expr ::= DOUBLE",
 /* 137 */ "expr ::= NULL",
 /* 138 */ "expr ::= TRUE",
 /* 139 */ "expr ::= FALSE",
 /* 140 */ "expr ::= NPLACEHOLDER",
 /* 141 */ "expr ::= SPLACEHOLDER",
 /* 142 */ "qualified_name ::= IDENTIFIER COLON IDENTIFIER DOT IDENTIFIER",
 /* 143 */ "qualified_name ::= IDENTIFIER COLON IDENTIFIER",
 /* 144 */ "qualified_name ::= IDENTIFIER DOT IDENTIFIER",
 /* 145 */ "qualified_name ::= IDENTIFIER",
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
/* #line 560 "parser.y" */
{
	if ((yypminor->yy0)) {
		if ((yypminor->yy0)->free_flag) {
			efree((yypminor->yy0)->token);
		}
		efree((yypminor->yy0));
	}
}
/* #line 1228 "parser.c" */
      break;
    case 78:
    case 79:
    case 80:
    case 81:
    case 82:
    case 83:
    case 90:
    case 91:
    case 93:
    case 94:
    case 95:
    case 96:
    case 97:
    case 98:
    case 99:
    case 100:
    case 104:
    case 105:
    case 107:
    case 108:
    case 110:
    case 111:
    case 112:
    case 114:
    case 115:
    case 116:
    case 117:
    case 118:
    case 120:
    case 121:
    case 124:
/* #line 573 "parser.y" */
{ zval_ptr_dtor(&(yypminor->yy158)); }
/* #line 1263 "parser.c" */
      break;
    case 84:
    case 85:
    case 86:
    case 87:
    case 88:
    case 89:
    case 101:
    case 102:
    case 109:
    case 122:
    case 123:
/* #line 865 "parser.y" */
{ phalcon_safe_zval_ptr_dtor((yypminor->yy158)); }
/* #line 1278 "parser.c" */
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
  { 77, 1 },
  { 78, 1 },
  { 78, 1 },
  { 78, 1 },
  { 78, 1 },
  { 79, 6 },
  { 83, 6 },
  { 89, 1 },
  { 89, 1 },
  { 89, 0 },
  { 90, 3 },
  { 90, 1 },
  { 93, 1 },
  { 93, 3 },
  { 93, 3 },
  { 93, 2 },
  { 93, 1 },
  { 91, 3 },
  { 91, 1 },
  { 92, 1 },
  { 92, 0 },
  { 96, 2 },
  { 96, 1 },
  { 97, 1 },
  { 98, 4 },
  { 101, 2 },
  { 101, 1 },
  { 101, 0 },
  { 99, 2 },
  { 99, 2 },
  { 99, 3 },
  { 99, 2 },
  { 99, 3 },
  { 99, 2 },
  { 99, 3 },
  { 99, 2 },
  { 99, 1 },
  { 102, 2 },
  { 102, 0 },
  { 80, 5 },
  { 80, 7 },
  { 80, 10 },
  { 103, 3 },
  { 103, 1 },
  { 106, 1 },
  { 104, 3 },
  { 104, 1 },
  { 107, 1 },
  { 81, 3 },
  { 108, 4 },
  { 110, 3 },
  { 110, 1 },
  { 111, 3 },
  { 113, 1 },
  { 82, 3 },
  { 114, 3 },
  { 95, 3 },
  { 95, 2 },
  { 95, 1 },
  { 100, 1 },
  { 84, 2 },
  { 84, 0 },
  { 87, 3 },
  { 87, 0 },
  { 115, 3 },
  { 115, 1 },
  { 116, 1 },
  { 116, 2 },
  { 116, 2 },
  { 85, 3 },
  { 85, 0 },
  { 117, 3 },
  { 117, 1 },
  { 118, 1 },
  { 86, 2 },
  { 86, 0 },
  { 88, 2 },
  { 88, 4 },
  { 88, 4 },
  { 88, 0 },
  { 109, 2 },
  { 109, 0 },
  { 119, 1 },
  { 119, 1 },
  { 119, 1 },
  { 94, 2 },
  { 94, 3 },
  { 94, 3 },
  { 94, 3 },
  { 94, 3 },
  { 94, 3 },
  { 94, 3 },
  { 94, 3 },
  { 94, 3 },
  { 94, 3 },
  { 94, 3 },
  { 94, 3 },
  { 94, 3 },
  { 94, 3 },
  { 94, 3 },
  { 94, 3 },
  { 94, 3 },
  { 94, 3 },
  { 94, 3 },
  { 94, 3 },
  { 94, 3 },
  { 94, 3 },
  { 94, 3 },
  { 94, 3 },
  { 94, 4 },
  { 94, 3 },
  { 94, 4 },
  { 94, 5 },
  { 94, 6 },
  { 94, 3 },
  { 94, 6 },
  { 94, 6 },
  { 94, 1 },
  { 121, 5 },
  { 122, 1 },
  { 122, 0 },
  { 123, 1 },
  { 123, 0 },
  { 120, 3 },
  { 120, 1 },
  { 124, 1 },
  { 124, 1 },
  { 94, 3 },
  { 94, 4 },
  { 94, 3 },
  { 94, 2 },
  { 94, 2 },
  { 94, 3 },
  { 94, 1 },
  { 94, 1 },
  { 94, 1 },
  { 94, 1 },
  { 94, 1 },
  { 94, 1 },
  { 94, 1 },
  { 94, 1 },
  { 94, 1 },
  { 112, 5 },
  { 112, 3 },
  { 112, 3 },
  { 112, 1 },
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
/* #line 569 "parser.y" */
{
	status->ret = yymsp[0].minor.yy158;
}
/* #line 1641 "parser.c" */
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
      case 117:
      case 121:
      case 126:
      case 133:
/* #line 575 "parser.y" */
{
	yygotominor.yy158 = yymsp[0].minor.yy158;
}
/* #line 1666 "parser.c" */
        break;
      case 5:
/* #line 593 "parser.y" */
{
	yygotominor.yy158 = phql_ret_select_statement(yymsp[-5].minor.yy158, yymsp[-4].minor.yy158, yymsp[-1].minor.yy158, yymsp[-3].minor.yy158, yymsp[-2].minor.yy158, yymsp[0].minor.yy158);
}
/* #line 1673 "parser.c" */
        break;
      case 6:
/* #line 599 "parser.y" */
{
	yygotominor.yy158 = phql_ret_select_clause(yymsp[-4].minor.yy158, yymsp[-3].minor.yy158, yymsp[-1].minor.yy158, yymsp[0].minor.yy158);
  yy_destructor(32,&yymsp[-5].minor);
  yy_destructor(33,&yymsp[-2].minor);
}
/* #line 1682 "parser.c" */
        break;
      case 7:
/* #line 605 "parser.y" */
{
	yygotominor.yy158 = phql_ret_distinct_all(1);
  yy_destructor(34,&yymsp[0].minor);
}
/* #line 1690 "parser.c" */
        break;
      case 8:
/* #line 609 "parser.y" */
{
	yygotominor.yy158 = phql_ret_distinct_all(0);
  yy_destructor(35,&yymsp[0].minor);
}
/* #line 1698 "parser.c" */
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
      case 120:
      case 122:
/* #line 613 "parser.y" */
{
	yygotominor.yy158 = NULL;
}
/* #line 1716 "parser.c" */
        break;
      case 10:
      case 17:
      case 42:
      case 45:
      case 50:
      case 64:
      case 71:
      case 123:
/* #line 619 "parser.y" */
{
	yygotominor.yy158 = phql_ret_zval_list(yymsp[-2].minor.yy158, yymsp[0].minor.yy158);
  yy_destructor(31,&yymsp[-1].minor);
}
/* #line 1731 "parser.c" */
        break;
      case 11:
      case 43:
      case 46:
      case 124:
/* #line 623 "parser.y" */
{
	yygotominor.yy158 = phql_ret_zval_list(yymsp[0].minor.yy158, NULL);
}
/* #line 1741 "parser.c" */
        break;
      case 12:
      case 125:
/* #line 629 "parser.y" */
{
	yygotominor.yy158 = phql_ret_column_item(PHQL_T_STARALL, NULL, NULL, NULL);
  yy_destructor(23,&yymsp[0].minor);
}
/* #line 1750 "parser.c" */
        break;
      case 13:
/* #line 633 "parser.y" */
{
	yygotominor.yy158 = phql_ret_column_item(PHQL_T_DOMAINALL, NULL, yymsp[-2].minor.yy0, NULL);
  yy_destructor(37,&yymsp[-1].minor);
  yy_destructor(23,&yymsp[0].minor);
}
/* #line 1759 "parser.c" */
        break;
      case 14:
/* #line 637 "parser.y" */
{
	yygotominor.yy158 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-2].minor.yy158, NULL, yymsp[0].minor.yy0);
  yy_destructor(38,&yymsp[-1].minor);
}
/* #line 1767 "parser.c" */
        break;
      case 15:
/* #line 641 "parser.y" */
{
	yygotominor.yy158 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-1].minor.yy158, NULL, yymsp[0].minor.yy0);
}
/* #line 1774 "parser.c" */
        break;
      case 16:
/* #line 645 "parser.y" */
{
	yygotominor.yy158 = phql_ret_column_item(PHQL_T_EXPR, yymsp[0].minor.yy158, NULL, NULL);
}
/* #line 1781 "parser.c" */
        break;
      case 21:
/* #line 669 "parser.y" */
{
	yygotominor.yy158 = phql_ret_zval_list(yymsp[-1].minor.yy158, yymsp[0].minor.yy158);
}
/* #line 1788 "parser.c" */
        break;
      case 24:
/* #line 686 "parser.y" */
{
	yygotominor.yy158 = phql_ret_join_item(yymsp[-3].minor.yy158, yymsp[-2].minor.yy158, yymsp[-1].minor.yy158, yymsp[0].minor.yy158);
}
/* #line 1795 "parser.c" */
        break;
      case 25:
/* #line 692 "parser.y" */
{
	yygotominor.yy158 = phql_ret_qualified_name(NULL, NULL, yymsp[0].minor.yy0);
  yy_destructor(38,&yymsp[-1].minor);
}
/* #line 1803 "parser.c" */
        break;
      case 26:
      case 47:
      case 145:
/* #line 696 "parser.y" */
{
	yygotominor.yy158 = phql_ret_qualified_name(NULL, NULL, yymsp[0].minor.yy0);
}
/* #line 1812 "parser.c" */
        break;
      case 28:
/* #line 706 "parser.y" */
{
	yygotominor.yy158 = phql_ret_join_type(PHQL_T_INNERJOIN);
  yy_destructor(39,&yymsp[-1].minor);
  yy_destructor(40,&yymsp[0].minor);
}
/* #line 1821 "parser.c" */
        break;
      case 29:
/* #line 710 "parser.y" */
{
	yygotominor.yy158 = phql_ret_join_type(PHQL_T_CROSSJOIN);
  yy_destructor(41,&yymsp[-1].minor);
  yy_destructor(40,&yymsp[0].minor);
}
/* #line 1830 "parser.c" */
        break;
      case 30:
/* #line 714 "parser.y" */
{
	yygotominor.yy158 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  yy_destructor(42,&yymsp[-2].minor);
  yy_destructor(43,&yymsp[-1].minor);
  yy_destructor(40,&yymsp[0].minor);
}
/* #line 1840 "parser.c" */
        break;
      case 31:
/* #line 718 "parser.y" */
{
	yygotominor.yy158 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  yy_destructor(42,&yymsp[-1].minor);
  yy_destructor(40,&yymsp[0].minor);
}
/* #line 1849 "parser.c" */
        break;
      case 32:
/* #line 722 "parser.y" */
{
	yygotominor.yy158 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  yy_destructor(44,&yymsp[-2].minor);
  yy_destructor(43,&yymsp[-1].minor);
  yy_destructor(40,&yymsp[0].minor);
}
/* #line 1859 "parser.c" */
        break;
      case 33:
/* #line 726 "parser.y" */
{
	yygotominor.yy158 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  yy_destructor(44,&yymsp[-1].minor);
  yy_destructor(40,&yymsp[0].minor);
}
/* #line 1868 "parser.c" */
        break;
      case 34:
/* #line 730 "parser.y" */
{
	yygotominor.yy158 = phql_ret_join_type(PHQL_T_FULLJOIN);
  yy_destructor(45,&yymsp[-2].minor);
  yy_destructor(43,&yymsp[-1].minor);
  yy_destructor(40,&yymsp[0].minor);
}
/* #line 1878 "parser.c" */
        break;
      case 35:
/* #line 734 "parser.y" */
{
	yygotominor.yy158 = phql_ret_join_type(PHQL_T_FULLJOIN);
  yy_destructor(45,&yymsp[-1].minor);
  yy_destructor(40,&yymsp[0].minor);
}
/* #line 1887 "parser.c" */
        break;
      case 36:
/* #line 738 "parser.y" */
{
	yygotominor.yy158 = phql_ret_join_type(PHQL_T_INNERJOIN);
  yy_destructor(40,&yymsp[0].minor);
}
/* #line 1895 "parser.c" */
        break;
      case 37:
/* #line 744 "parser.y" */
{
	yygotominor.yy158 = yymsp[0].minor.yy158;
  yy_destructor(46,&yymsp[-1].minor);
}
/* #line 1903 "parser.c" */
        break;
      case 39:
/* #line 755 "parser.y" */
{
	yygotominor.yy158 = phql_ret_insert_statement2(yymsp[-4].minor.yy158, NULL, yymsp[-1].minor.yy158);
  yy_destructor(31,&yymsp[-3].minor);
  yy_destructor(47,&yymsp[-2].minor);
  yy_destructor(48,&yymsp[0].minor);
}
/* #line 1913 "parser.c" */
        break;
      case 40:
/* #line 759 "parser.y" */
{
	yygotominor.yy158 = phql_ret_insert_statement(yymsp[-4].minor.yy158, NULL, yymsp[-1].minor.yy158);
  yy_destructor(49,&yymsp[-6].minor);
  yy_destructor(50,&yymsp[-5].minor);
  yy_destructor(51,&yymsp[-3].minor);
  yy_destructor(47,&yymsp[-2].minor);
  yy_destructor(48,&yymsp[0].minor);
}
/* #line 1925 "parser.c" */
        break;
      case 41:
/* #line 763 "parser.y" */
{
	yygotominor.yy158 = phql_ret_insert_statement(yymsp[-7].minor.yy158, yymsp[-5].minor.yy158, yymsp[-1].minor.yy158);
  yy_destructor(49,&yymsp[-9].minor);
  yy_destructor(50,&yymsp[-8].minor);
  yy_destructor(47,&yymsp[-6].minor);
  yy_destructor(48,&yymsp[-4].minor);
  yy_destructor(51,&yymsp[-3].minor);
  yy_destructor(47,&yymsp[-2].minor);
  yy_destructor(48,&yymsp[0].minor);
}
/* #line 1939 "parser.c" */
        break;
      case 48:
/* #line 801 "parser.y" */
{
	yygotominor.yy158 = phql_ret_update_statement(yymsp[-2].minor.yy158, yymsp[-1].minor.yy158, yymsp[0].minor.yy158);
}
/* #line 1946 "parser.c" */
        break;
      case 49:
/* #line 807 "parser.y" */
{
	yygotominor.yy158 = phql_ret_update_clause(yymsp[-2].minor.yy158, yymsp[0].minor.yy158);
  yy_destructor(52,&yymsp[-3].minor);
  yy_destructor(53,&yymsp[-1].minor);
}
/* #line 1955 "parser.c" */
        break;
      case 52:
/* #line 823 "parser.y" */
{
	yygotominor.yy158 = phql_ret_update_item(yymsp[-2].minor.yy158, yymsp[0].minor.yy158);
  yy_destructor(3,&yymsp[-1].minor);
}
/* #line 1963 "parser.c" */
        break;
      case 54:
/* #line 835 "parser.y" */
{
	yygotominor.yy158 = phql_ret_delete_statement(yymsp[-2].minor.yy158, yymsp[-1].minor.yy158, yymsp[0].minor.yy158);
}
/* #line 1970 "parser.c" */
        break;
      case 55:
/* #line 841 "parser.y" */
{
	yygotominor.yy158 = phql_ret_delete_clause(yymsp[0].minor.yy158);
  yy_destructor(54,&yymsp[-2].minor);
  yy_destructor(33,&yymsp[-1].minor);
}
/* #line 1979 "parser.c" */
        break;
      case 56:
/* #line 847 "parser.y" */
{
	yygotominor.yy158 = phql_ret_assoc_name(yymsp[-2].minor.yy158, yymsp[0].minor.yy0);
  yy_destructor(38,&yymsp[-1].minor);
}
/* #line 1987 "parser.c" */
        break;
      case 57:
/* #line 851 "parser.y" */
{
	yygotominor.yy158 = phql_ret_assoc_name(yymsp[-1].minor.yy158, yymsp[0].minor.yy0);
}
/* #line 1994 "parser.c" */
        break;
      case 58:
/* #line 855 "parser.y" */
{
	yygotominor.yy158 = phql_ret_assoc_name(yymsp[0].minor.yy158, NULL);
}
/* #line 2001 "parser.c" */
        break;
      case 60:
/* #line 867 "parser.y" */
{
	yygotominor.yy158 = yymsp[0].minor.yy158;
  yy_destructor(55,&yymsp[-1].minor);
}
/* #line 2009 "parser.c" */
        break;
      case 62:
/* #line 877 "parser.y" */
{
	yygotominor.yy158 = yymsp[0].minor.yy158;
  yy_destructor(56,&yymsp[-2].minor);
  yy_destructor(57,&yymsp[-1].minor);
}
/* #line 2018 "parser.c" */
        break;
      case 66:
/* #line 897 "parser.y" */
{
	yygotominor.yy158 = phql_ret_order_item(yymsp[0].minor.yy158, 0);
}
/* #line 2025 "parser.c" */
        break;
      case 67:
/* #line 901 "parser.y" */
{
	yygotominor.yy158 = phql_ret_order_item(yymsp[-1].minor.yy158, PHQL_T_ASC);
  yy_destructor(58,&yymsp[0].minor);
}
/* #line 2033 "parser.c" */
        break;
      case 68:
/* #line 905 "parser.y" */
{
	yygotominor.yy158 = phql_ret_order_item(yymsp[-1].minor.yy158, PHQL_T_DESC);
  yy_destructor(59,&yymsp[0].minor);
}
/* #line 2041 "parser.c" */
        break;
      case 69:
/* #line 911 "parser.y" */
{
	yygotominor.yy158 = yymsp[0].minor.yy158;
  yy_destructor(60,&yymsp[-2].minor);
  yy_destructor(57,&yymsp[-1].minor);
}
/* #line 2050 "parser.c" */
        break;
      case 74:
/* #line 937 "parser.y" */
{
	yygotominor.yy158 = yymsp[0].minor.yy158;
  yy_destructor(61,&yymsp[-1].minor);
}
/* #line 2058 "parser.c" */
        break;
      case 76:
      case 80:
/* #line 947 "parser.y" */
{
	yygotominor.yy158 = phql_ret_limit_clause(yymsp[0].minor.yy158, NULL);
  yy_destructor(62,&yymsp[-1].minor);
}
/* #line 2067 "parser.c" */
        break;
      case 77:
/* #line 951 "parser.y" */
{
	yygotominor.yy158 = phql_ret_limit_clause(yymsp[0].minor.yy158, yymsp[-2].minor.yy158);
  yy_destructor(62,&yymsp[-3].minor);
  yy_destructor(31,&yymsp[-1].minor);
}
/* #line 2076 "parser.c" */
        break;
      case 78:
/* #line 955 "parser.y" */
{
	yygotominor.yy158 = phql_ret_limit_clause(yymsp[-2].minor.yy158, yymsp[0].minor.yy158);
  yy_destructor(62,&yymsp[-3].minor);
  yy_destructor(63,&yymsp[-1].minor);
}
/* #line 2085 "parser.c" */
        break;
      case 82:
      case 134:
/* #line 973 "parser.y" */
{
	yygotominor.yy158 = phql_ret_literal_zval(PHQL_T_INTEGER, yymsp[0].minor.yy0);
}
/* #line 2093 "parser.c" */
        break;
      case 83:
      case 140:
/* #line 977 "parser.y" */
{
	yygotominor.yy158 = phql_ret_placeholder_zval(PHQL_T_NPLACEHOLDER, yymsp[0].minor.yy0);
}
/* #line 2101 "parser.c" */
        break;
      case 84:
      case 141:
/* #line 981 "parser.y" */
{
	yygotominor.yy158 = phql_ret_placeholder_zval(PHQL_T_SPLACEHOLDER, yymsp[0].minor.yy0);
}
/* #line 2109 "parser.c" */
        break;
      case 85:
/* #line 987 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_MINUS, NULL, yymsp[0].minor.yy158);
  yy_destructor(26,&yymsp[-1].minor);
}
/* #line 2117 "parser.c" */
        break;
      case 86:
/* #line 991 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_SUB, yymsp[-2].minor.yy158, yymsp[0].minor.yy158);
  yy_destructor(26,&yymsp[-1].minor);
}
/* #line 2125 "parser.c" */
        break;
      case 87:
/* #line 995 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_ADD, yymsp[-2].minor.yy158, yymsp[0].minor.yy158);
  yy_destructor(25,&yymsp[-1].minor);
}
/* #line 2133 "parser.c" */
        break;
      case 88:
/* #line 999 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_MUL, yymsp[-2].minor.yy158, yymsp[0].minor.yy158);
  yy_destructor(23,&yymsp[-1].minor);
}
/* #line 2141 "parser.c" */
        break;
      case 89:
/* #line 1003 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_DIV, yymsp[-2].minor.yy158, yymsp[0].minor.yy158);
  yy_destructor(22,&yymsp[-1].minor);
}
/* #line 2149 "parser.c" */
        break;
      case 90:
/* #line 1007 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_MOD, yymsp[-2].minor.yy158, yymsp[0].minor.yy158);
  yy_destructor(24,&yymsp[-1].minor);
}
/* #line 2157 "parser.c" */
        break;
      case 91:
/* #line 1011 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_AND, yymsp[-2].minor.yy158, yymsp[0].minor.yy158);
  yy_destructor(15,&yymsp[-1].minor);
}
/* #line 2165 "parser.c" */
        break;
      case 92:
/* #line 1015 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_OR, yymsp[-2].minor.yy158, yymsp[0].minor.yy158);
  yy_destructor(16,&yymsp[-1].minor);
}
/* #line 2173 "parser.c" */
        break;
      case 93:
/* #line 1019 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_BITWISE_AND, yymsp[-2].minor.yy158, yymsp[0].minor.yy158);
  yy_destructor(19,&yymsp[-1].minor);
}
/* #line 2181 "parser.c" */
        break;
      case 94:
/* #line 1023 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_BITWISE_OR, yymsp[-2].minor.yy158, yymsp[0].minor.yy158);
  yy_destructor(20,&yymsp[-1].minor);
}
/* #line 2189 "parser.c" */
        break;
      case 95:
/* #line 1027 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_BITWISE_XOR, yymsp[-2].minor.yy158, yymsp[0].minor.yy158);
  yy_destructor(21,&yymsp[-1].minor);
}
/* #line 2197 "parser.c" */
        break;
      case 96:
/* #line 1031 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_EQUALS, yymsp[-2].minor.yy158, yymsp[0].minor.yy158);
  yy_destructor(3,&yymsp[-1].minor);
}
/* #line 2205 "parser.c" */
        break;
      case 97:
/* #line 1035 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_NOTEQUALS, yymsp[-2].minor.yy158, yymsp[0].minor.yy158);
  yy_destructor(4,&yymsp[-1].minor);
}
/* #line 2213 "parser.c" */
        break;
      case 98:
/* #line 1039 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_LESS, yymsp[-2].minor.yy158, yymsp[0].minor.yy158);
  yy_destructor(5,&yymsp[-1].minor);
}
/* #line 2221 "parser.c" */
        break;
      case 99:
/* #line 1043 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_GREATER, yymsp[-2].minor.yy158, yymsp[0].minor.yy158);
  yy_destructor(6,&yymsp[-1].minor);
}
/* #line 2229 "parser.c" */
        break;
      case 100:
/* #line 1047 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_GREATEREQUAL, yymsp[-2].minor.yy158, yymsp[0].minor.yy158);
  yy_destructor(7,&yymsp[-1].minor);
}
/* #line 2237 "parser.c" */
        break;
      case 101:
/* #line 1051 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_TS_MATCHES, yymsp[-2].minor.yy158, yymsp[0].minor.yy158);
  yy_destructor(9,&yymsp[-1].minor);
}
/* #line 2245 "parser.c" */
        break;
      case 102:
/* #line 1055 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_TS_OR, yymsp[-2].minor.yy158, yymsp[0].minor.yy158);
  yy_destructor(10,&yymsp[-1].minor);
}
/* #line 2253 "parser.c" */
        break;
      case 103:
/* #line 1059 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_TS_AND, yymsp[-2].minor.yy158, yymsp[0].minor.yy158);
  yy_destructor(11,&yymsp[-1].minor);
}
/* #line 2261 "parser.c" */
        break;
      case 104:
/* #line 1063 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_TS_NEGATE, yymsp[-2].minor.yy158, yymsp[0].minor.yy158);
  yy_destructor(12,&yymsp[-1].minor);
}
/* #line 2269 "parser.c" */
        break;
      case 105:
/* #line 1067 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_TS_CONTAINS_ANOTHER, yymsp[-2].minor.yy158, yymsp[0].minor.yy158);
  yy_destructor(13,&yymsp[-1].minor);
}
/* #line 2277 "parser.c" */
        break;
      case 106:
/* #line 1071 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_TS_CONTAINS_IN, yymsp[-2].minor.yy158, yymsp[0].minor.yy158);
  yy_destructor(14,&yymsp[-1].minor);
}
/* #line 2285 "parser.c" */
        break;
      case 107:
/* #line 1075 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_LESSEQUAL, yymsp[-2].minor.yy158, yymsp[0].minor.yy158);
  yy_destructor(8,&yymsp[-1].minor);
}
/* #line 2293 "parser.c" */
        break;
      case 108:
/* #line 1079 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_LIKE, yymsp[-2].minor.yy158, yymsp[0].minor.yy158);
  yy_destructor(17,&yymsp[-1].minor);
}
/* #line 2301 "parser.c" */
        break;
      case 109:
/* #line 1083 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_NLIKE, yymsp[-3].minor.yy158, yymsp[0].minor.yy158);
  yy_destructor(29,&yymsp[-2].minor);
  yy_destructor(17,&yymsp[-1].minor);
}
/* #line 2310 "parser.c" */
        break;
      case 110:
/* #line 1087 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_ILIKE, yymsp[-2].minor.yy158, yymsp[0].minor.yy158);
  yy_destructor(18,&yymsp[-1].minor);
}
/* #line 2318 "parser.c" */
        break;
      case 111:
/* #line 1091 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_NILIKE, yymsp[-3].minor.yy158, yymsp[0].minor.yy158);
  yy_destructor(29,&yymsp[-2].minor);
  yy_destructor(18,&yymsp[-1].minor);
}
/* #line 2327 "parser.c" */
        break;
      case 112:
/* #line 1095 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_IN, yymsp[-4].minor.yy158, yymsp[-1].minor.yy158);
  yy_destructor(28,&yymsp[-3].minor);
  yy_destructor(47,&yymsp[-2].minor);
  yy_destructor(48,&yymsp[0].minor);
}
/* #line 2337 "parser.c" */
        break;
      case 113:
/* #line 1099 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_NOTIN, yymsp[-5].minor.yy158, yymsp[-1].minor.yy158);
  yy_destructor(29,&yymsp[-4].minor);
  yy_destructor(28,&yymsp[-3].minor);
  yy_destructor(47,&yymsp[-2].minor);
  yy_destructor(48,&yymsp[0].minor);
}
/* #line 2348 "parser.c" */
        break;
      case 114:
/* #line 1103 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_AGAINST, yymsp[-2].minor.yy158, yymsp[0].minor.yy158);
  yy_destructor(1,&yymsp[-1].minor);
}
/* #line 2356 "parser.c" */
        break;
      case 115:
/* #line 1107 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_CAST, yymsp[-3].minor.yy158, phql_ret_raw_qualified_name(yymsp[-1].minor.yy0, NULL));
  yy_destructor(67,&yymsp[-5].minor);
  yy_destructor(47,&yymsp[-4].minor);
  yy_destructor(38,&yymsp[-2].minor);
  yy_destructor(48,&yymsp[0].minor);
}
/* #line 2367 "parser.c" */
        break;
      case 116:
/* #line 1111 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_CONVERT, yymsp[-3].minor.yy158, phql_ret_raw_qualified_name(yymsp[-1].minor.yy0, NULL));
  yy_destructor(68,&yymsp[-5].minor);
  yy_destructor(47,&yymsp[-4].minor);
  yy_destructor(69,&yymsp[-2].minor);
  yy_destructor(48,&yymsp[0].minor);
}
/* #line 2378 "parser.c" */
        break;
      case 118:
/* #line 1121 "parser.y" */
{
	yygotominor.yy158 = phql_ret_func_call(yymsp[-4].minor.yy0, yymsp[-1].minor.yy158, yymsp[-2].minor.yy158);
  yy_destructor(47,&yymsp[-3].minor);
  yy_destructor(48,&yymsp[0].minor);
}
/* #line 2387 "parser.c" */
        break;
      case 119:
/* #line 1127 "parser.y" */
{
	yygotominor.yy158 = phql_ret_distinct();
  yy_destructor(34,&yymsp[0].minor);
}
/* #line 2395 "parser.c" */
        break;
      case 127:
/* #line 1165 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_ISNULL, yymsp[-2].minor.yy158, NULL);
  yy_destructor(27,&yymsp[-1].minor);
  yy_destructor(70,&yymsp[0].minor);
}
/* #line 2404 "parser.c" */
        break;
      case 128:
/* #line 1169 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_ISNOTNULL, yymsp[-3].minor.yy158, NULL);
  yy_destructor(27,&yymsp[-2].minor);
  yy_destructor(29,&yymsp[-1].minor);
  yy_destructor(70,&yymsp[0].minor);
}
/* #line 2414 "parser.c" */
        break;
      case 129:
/* #line 1173 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_BETWEEN, yymsp[-2].minor.yy158, yymsp[0].minor.yy158);
  yy_destructor(2,&yymsp[-1].minor);
}
/* #line 2422 "parser.c" */
        break;
      case 130:
/* #line 1177 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_NOT, NULL, yymsp[0].minor.yy158);
  yy_destructor(29,&yymsp[-1].minor);
}
/* #line 2430 "parser.c" */
        break;
      case 131:
/* #line 1181 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_BITWISE_NOT, NULL, yymsp[0].minor.yy158);
  yy_destructor(30,&yymsp[-1].minor);
}
/* #line 2438 "parser.c" */
        break;
      case 132:
/* #line 1185 "parser.y" */
{
	yygotominor.yy158 = phql_ret_expr(PHQL_T_ENCLOSED, yymsp[-1].minor.yy158, NULL);
  yy_destructor(47,&yymsp[-2].minor);
  yy_destructor(48,&yymsp[0].minor);
}
/* #line 2447 "parser.c" */
        break;
      case 135:
/* #line 1197 "parser.y" */
{
	yygotominor.yy158 = phql_ret_literal_zval(PHQL_T_STRING, yymsp[0].minor.yy0);
}
/* #line 2454 "parser.c" */
        break;
      case 136:
/* #line 1201 "parser.y" */
{
	yygotominor.yy158 = phql_ret_literal_zval(PHQL_T_DOUBLE, yymsp[0].minor.yy0);
}
/* #line 2461 "parser.c" */
        break;
      case 137:
/* #line 1205 "parser.y" */
{
	yygotominor.yy158 = phql_ret_literal_zval(PHQL_T_NULL, NULL);
  yy_destructor(70,&yymsp[0].minor);
}
/* #line 2469 "parser.c" */
        break;
      case 138:
/* #line 1209 "parser.y" */
{
	yygotominor.yy158 = phql_ret_literal_zval(PHQL_T_TRUE, NULL);
  yy_destructor(73,&yymsp[0].minor);
}
/* #line 2477 "parser.c" */
        break;
      case 139:
/* #line 1213 "parser.y" */
{
	yygotominor.yy158 = phql_ret_literal_zval(PHQL_T_FALSE, NULL);
  yy_destructor(74,&yymsp[0].minor);
}
/* #line 2485 "parser.c" */
        break;
      case 142:
/* #line 1227 "parser.y" */
{
	yygotominor.yy158 = phql_ret_qualified_name(yymsp[-4].minor.yy0, yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(75,&yymsp[-3].minor);
  yy_destructor(37,&yymsp[-1].minor);
}
/* #line 2494 "parser.c" */
        break;
      case 143:
/* #line 1231 "parser.y" */
{
	yygotominor.yy158 = phql_ret_qualified_name(yymsp[-2].minor.yy0, NULL, yymsp[0].minor.yy0);
  yy_destructor(75,&yymsp[-1].minor);
}
/* #line 2502 "parser.c" */
        break;
      case 144:
/* #line 1235 "parser.y" */
{
	yygotominor.yy158 = phql_ret_qualified_name(NULL, yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(37,&yymsp[-1].minor);
}
/* #line 2510 "parser.c" */
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
/* #line 493 "parser.y" */

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

/* #line 2619 "parser.c" */
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
			case PHQL_T_DOT:
				phql_(phql_parser, PHQL_DOT, NULL, parser_status);
				break;
			case PHQL_T_COLON:
				phql_(phql_parser, PHQL_COLON, NULL, parser_status);
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

			case PHQL_T_IDENTIFIER:
				phql_parse_with_token(phql_parser, PHQL_T_IDENTIFIER, PHQL_IDENTIFIER, &token, parser_status);
				break;
			case PHQL_T_NPLACEHOLDER:
				phql_parse_with_token(phql_parser, PHQL_T_NPLACEHOLDER, PHQL_NPLACEHOLDER, &token, parser_status);
				break;
			case PHQL_T_SPLACEHOLDER:
				phql_parse_with_token(phql_parser, PHQL_T_SPLACEHOLDER, PHQL_SPLACEHOLDER, &token, parser_status);
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
						add_assoc_long(parser_status->ret, "id", phalcon_globals_ptr->orm.unique_cache_id++);
					}
				}

				ZVAL_ZVAL(*result, parser_status->ret, 0, 0);
				ZVAL_NULL(parser_status->ret);
				zval_ptr_dtor(&parser_status->ret);

				/**
				 * Store the parsed definition in the cache
				 */
				phalcon_orm_set_prepared_ast(unique_id, *result);

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
