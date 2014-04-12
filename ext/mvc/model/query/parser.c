/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is include which follows the "include" declaration
** in the input file. */
#include <stdio.h>
/* #line 39 "parser.y" */


#include "php_phalcon.h"

#include "mvc/model/query/parser.h"
#include "mvc/model/query/scanner.h"
#include "mvc/model/query/phql.h"
#include "mvc/model/exception.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"

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


/* #line 430 "parser.c" */
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
#define YYNOCODE 120
#define YYACTIONTYPE unsigned short int
#define phql_TOKENTYPE phql_parser_token*
typedef union {
  phql_TOKENTYPE yy0;
  zval* yy92;
  int yy239;
} YYMINORTYPE;
#define YYSTACKDEPTH 100
#define phql_ARG_SDECL phql_parser_status *status;
#define phql_ARG_PDECL ,phql_parser_status *status
#define phql_ARG_FETCH phql_parser_status *status = yypParser->status
#define phql_ARG_STORE yypParser->status = status
#define YYNSTATE 249
#define YYNRULE 139
#define YYERRORSYMBOL 70
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
 /*     0 */    72,   78,   50,   52,   54,   56,   58,   60,   40,   42,
 /*    10 */    62,   67,   44,   46,   48,   36,   34,   38,   32,   29,
 /*    20 */    74,   69,   64,  145,   72,   78,   50,   52,   54,   56,
 /*    30 */    58,   60,   40,   42,   62,   67,   44,   46,   48,   36,
 /*    40 */    34,   38,   32,   29,   74,   69,   64,   16,   17,   18,
 /*    50 */   249,   27,   28,  201,  192,  199,  150,   72,   78,   50,
 /*    60 */    52,   54,   56,   58,   60,   40,   42,   62,   67,   44,
 /*    70 */    46,   48,   36,   34,   38,   32,   29,   74,   69,   64,
 /*    80 */    36,   34,   38,   32,   29,   74,   69,   64,   83,    7,
 /*    90 */    72,   78,   50,   52,   54,   56,   58,   60,   40,   42,
 /*   100 */    62,   67,   44,   46,   48,   36,   34,   38,   32,   29,
 /*   110 */    74,   69,   64,   72,   78,   50,   52,   54,   56,   58,
 /*   120 */    60,   40,   42,   62,   67,   44,   46,   48,   36,   34,
 /*   130 */    38,   32,   29,   74,   69,   64,   40,   42,   62,   67,
 /*   140 */    44,   46,   48,   36,   34,   38,   32,   29,   74,   69,
 /*   150 */    64,  327,   89,   74,   69,   64,  158,  108,  156,   72,
 /*   160 */    78,   50,   52,   54,   56,   58,   60,   40,   42,   62,
 /*   170 */    67,   44,   46,   48,   36,   34,   38,   32,   29,   74,
 /*   180 */    69,   64,   50,   52,   54,   56,   58,   60,   40,   42,
 /*   190 */    62,   67,   44,   46,   48,   36,   34,   38,   32,   29,
 /*   200 */    74,   69,   64,  101,  203,  204,   30,   12,  250,  102,
 /*   210 */   104,   65,  128,  138,  101,  153,   93,   30,  324,   99,
 /*   220 */   102,  104,  130,  173,  189,  175,  177,   93,  181,  185,
 /*   230 */   106,  364,  173,  189,  175,  177,   76,  181,  185,  363,
 /*   240 */   172,  106,  170,   14,  110,  116,  117,   80,   86,   26,
 /*   250 */   113,  111,  112,  114,  115,  110,  116,  117,   80,   86,
 /*   260 */    26,  113,  111,  112,  114,  115,  194,  109,   71,   30,
 /*   270 */    23,  135,  102,  104,  251,   19,   92,   75,  109,  195,
 /*   280 */    30,    8,   25,  102,  104,  124,  109,   92,  208,  216,
 /*   290 */    93,  252,   99,  106,   98,   92,  253,   96,  118,   32,
 /*   300 */    29,   74,   69,   64,  106,  136,    9,  110,  116,  117,
 /*   310 */    80,   86,  127,  113,  111,  112,  114,  115,  110,  116,
 /*   320 */   117,   80,   86,  120,  113,  111,  112,  114,  115,   62,
 /*   330 */    67,   44,   46,   48,   36,   34,   38,   32,   29,   74,
 /*   340 */    69,   64,   44,   46,   48,   36,   34,   38,   32,   29,
 /*   350 */    74,   69,   64,   71,  143,  389,    1,    2,    3,    4,
 /*   360 */     5,    6,  162,  163,  164,  235,  242,  238,   10,   71,
 /*   370 */   180,  109,  109,  178,  237,  238,   21,  140,  144,  126,
 /*   380 */    92,   92,  214,  118,   11,  149,  227,  109,  202,  198,
 /*   390 */   254,  210,  243,  124,  215,  132,   92,  152,  147,  118,
 /*   400 */   109,  161,  190,  163,  164,  214,   94,  109,   71,   92,
 /*   410 */   143,   13,   15,  205,  221,  151,   92,  215,  232,  191,
 /*   420 */   246,  193,  198,  109,  155,  241,  109,  214,  109,  134,
 /*   430 */    31,  120,   92,   33,  142,   92,  159,   92,  100,  213,
 /*   440 */   109,   35,   22,  109,  240,  109,   37,  109,  109,   92,
 /*   450 */   154,  109,   92,  165,   92,  155,   92,   92,   39,  109,
 /*   460 */    92,   41,  196,   99,  109,  159,   43,  159,   92,   45,
 /*   470 */   325,   47,   49,   92,   51,   94,  109,   53,  184,  109,
 /*   480 */    20,  182,  326,  133,  109,   92,   64,  109,   92,  109,
 /*   490 */   109,   55,  109,   92,   57,  109,   92,   59,   92,   92,
 /*   500 */   120,   92,   61,  197,   92,   63,   24,   66,   68,  109,
 /*   510 */    73,  188,  109,   79,  186,  109,  125,   70,   92,  212,
 /*   520 */   109,   92,  223,  109,   92,  109,  109,   82,  109,   92,
 /*   530 */    88,  109,   92,  103,   92,   92,  329,   92,  105,  211,
 /*   540 */    92,  107,  218,  129,  169,  109,  137,  217,  109,  146,
 /*   550 */   226,  109,  212,   77,   92,   81,  109,   92,  233,  109,
 /*   560 */    92,  109,  109,  155,  109,   92,  207,  109,   92,  248,
 /*   570 */    92,   92,  222,   92,  155,  159,   92,   84,  159,   85,
 /*   580 */    90,   87,  119,   91,   95,   97,  159,  121,  131,  122,
 /*   590 */   123,  125,  230,  139,  141,  148,  160,  157,  166,  168,
 /*   600 */   167,  171,  174,  277,  176,  278,  179,  279,  280,  281,
 /*   610 */   183,  282,  283,  284,  187,  285,  200,  288,  209,  225,
 /*   620 */   289,  224,  229,  228,  296,  328,  206,  231,  236,  239,
 /*   630 */   219,  244,  220,  245,  302,  247,  260,  234,
};
static YYCODETYPE yy_lookahead[] = {
 /*     0 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    10 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*    20 */    21,   22,   23,   49,    1,    2,    3,    4,    5,    6,
 /*    30 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*    40 */    17,   18,   19,   20,   21,   22,   23,   58,   59,   60,
 /*    50 */     0,   52,   53,   30,   25,   32,   27,    1,    2,    3,
 /*    60 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*    70 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*    80 */    16,   17,   18,   19,   20,   21,   22,   23,   32,   78,
 /*    90 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*   100 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   110 */    21,   22,   23,    1,    2,    3,    4,    5,    6,    7,
 /*   120 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   130 */    18,   19,   20,   21,   22,   23,    9,   10,   11,   12,
 /*   140 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   150 */    23,    0,   63,   21,   22,   23,   30,   45,   32,    1,
 /*   160 */     2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   170 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   180 */    22,   23,    3,    4,    5,    6,    7,    8,    9,   10,
 /*   190 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   200 */    21,   22,   23,   17,   28,   29,   20,   56,    0,   23,
 /*   210 */    24,   11,   12,   54,   17,   25,   30,   20,    0,   25,
 /*   220 */    23,   24,   22,   33,   34,   35,   36,   30,   38,   39,
 /*   230 */    44,   45,   33,   34,   35,   36,   23,   38,   39,   45,
 /*   240 */    30,   44,   32,   25,   58,   59,   60,   61,   62,   88,
 /*   250 */    64,   65,   66,   67,   68,   58,   59,   60,   61,   62,
 /*   260 */    88,   64,   65,   66,   67,   68,   17,  106,   88,   20,
 /*   270 */   109,  110,   23,   24,    0,   57,  115,   64,  106,   30,
 /*   280 */    20,   79,  110,   23,   24,   31,  106,  115,   43,   44,
 /*   290 */    30,    0,   25,   44,  114,  115,    0,  117,  118,   19,
 /*   300 */    20,   21,   22,   23,   44,   55,   80,   58,   59,   60,
 /*   310 */    61,   62,   45,   64,   65,   66,   67,   68,   58,   59,
 /*   320 */    60,   61,   62,   69,   64,   65,   66,   67,   68,   11,
 /*   330 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   340 */    22,   23,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   350 */    21,   22,   23,   88,   88,   71,   72,   73,   74,   75,
 /*   360 */    76,   77,   91,   92,   93,  104,  105,  106,   81,   88,
 /*   370 */    34,  106,  106,   37,  105,  106,   50,  111,  112,  114,
 /*   380 */   115,  115,   88,  118,   82,   84,  102,  106,   87,   88,
 /*   390 */     0,   97,  108,   31,  100,  114,  115,   86,   26,  118,
 /*   400 */   106,   90,   91,   92,   93,   88,   44,  106,   88,  115,
 /*   410 */    88,  113,  113,   41,   97,   85,  115,  100,   46,   89,
 /*   420 */    48,   87,   88,  106,   94,   88,  106,   88,  106,   88,
 /*   430 */    88,   69,  115,   88,  112,  115,  106,  115,  118,  100,
 /*   440 */   106,   88,   51,  106,  107,  106,   88,  106,  106,  115,
 /*   450 */    89,  106,  115,   94,  115,   94,  115,  115,   88,  106,
 /*   460 */   115,   88,   31,   25,  106,  106,   88,  106,  115,   88,
 /*   470 */     0,   88,   88,  115,   88,   44,  106,   88,   34,  106,
 /*   480 */   113,   37,    0,   45,  106,  115,   23,  106,  115,  106,
 /*   490 */   106,   88,  106,  115,   88,  106,  115,   88,  115,  115,
 /*   500 */    69,  115,   88,   17,  115,   88,   25,   88,   88,  106,
 /*   510 */    88,   34,  106,   88,   37,  106,   30,   44,  115,   25,
 /*   520 */   106,  115,   25,  106,  115,  106,  106,   88,  106,  115,
 /*   530 */    88,  106,  115,   88,  115,  115,    0,  115,   88,   45,
 /*   540 */   115,   88,   45,   88,   88,  106,   88,   98,  106,   88,
 /*   550 */   101,  106,   25,   64,  115,   44,  106,  115,   89,  106,
 /*   560 */   115,  106,  106,   94,  106,  115,   94,  106,  115,   89,
 /*   570 */   115,  115,   45,  115,   94,  106,  115,   30,  106,   45,
 /*   580 */    30,   44,   28,   45,  116,   45,  106,   30,   44,   31,
 /*   590 */    30,   30,   56,   51,   25,   83,   30,   30,   95,   40,
 /*   600 */    96,   30,   34,   30,   34,   30,   34,   30,   30,   30,
 /*   610 */    34,   30,   30,   30,   34,   30,   30,    0,   44,   30,
 /*   620 */     0,  101,  103,   78,    0,    0,   42,  113,   25,    3,
 /*   630 */    43,   78,   44,  103,    0,   27,  119,   47,
};
#define YY_SHIFT_USE_DFLT (-27)
static short yy_shift_ofst[] = {
 /*     0 */   372,   50,  208,  274,  291,  296,  -26,  159,  250,  326,
 /*    10 */   151,  390,  -11,  218,  -11,  470,  -27,  -27,  -27,  -11,
 /*    20 */   482,  391,  260,  481,  260,  -27,   -1,  -27,  -27,  260,
 /*    30 */   260,  132,  260,  132,  260,  280,  260,  280,  260,  280,
 /*    40 */   260,  318,  260,  318,  260,   64,  260,   64,  260,   64,
 /*    50 */   260,  127,  260,  127,  260,  127,  260,  127,  260,  127,
 /*    60 */   260,  127,  260,  329,  200,  260,  463,  260,  329,  473,
 /*    70 */   197,  158,  260,  158,  213,  -27,  489,  -27,  260,  179,
 /*    80 */   511,  260,   56,  547,  534,  -27,  537,  260,   89,  550,
 /*    90 */   538,  -27,  -27,  362,  554,  186,  540,  -27,  194,  197,
 /*   100 */   -27,  -27,  260,  463,  260,  463,  260,  112,  -27,  -27,
 /*   110 */   -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,
 /*   120 */   557,  558,  560,  -27,  561,  -27,  267,  -27,  260,  463,
 /*   130 */   544,  197,  438,  -27,  132,  -27,  260,  158,  542,  260,
 /*   140 */   569,  260,  -27,  158,  -27,  260,  158,  176,  249,   29,
 /*   150 */   566,  190,  -27,  566,  -27,  126,  567,  -27,  -27,  -27,
 /*   160 */   254,  199,  -27,  -27,  566,  210,  559,  -27,  260,  158,
 /*   170 */   571,  -27,  -27,  568,  573,  570,  575,  336,  572,  577,
 /*   180 */   578,  444,  576,  579,  581,  477,  580,  582,  583,  585,
 /*   190 */   -27,  -27,  249,  -27,  -27,  431,  486,  -27,   23,  586,
 /*   200 */   -27,  -27,  -27,  -27,  -27,  584,  566,  245,  574,  260,
 /*   210 */   494,  617,  260,  -27,  158,  -27,  589,  497,  587,  588,
 /*   220 */   260,  527,  620,  589,  -27,  -27,  -27,  -26,  536,  624,
 /*   230 */   -11,  625,  566,  590,  566,  603,  566,  -27,  626,  260,
 /*   240 */   -27,  158,  -27,  -26,  536,  634,  608,  566,  -27,
};
#define YY_REDUCE_USE_DFLT (-1)
static short yy_reduce_ofst[] = {
 /*     0 */   284,   -1,   -1,   -1,   -1,   -1,   11,  202,  226,  287,
 /*    10 */   302,   -1,  298,   -1,  299,   -1,   -1,   -1,   -1,  367,
 /*    20 */    -1,   -1,  161,   -1,  172,   -1,   -1,   -1,   -1,  341,
 /*    30 */   342,   -1,  345,   -1,  353,   -1,  358,   -1,  370,   -1,
 /*    40 */   373,   -1,  378,   -1,  381,   -1,  383,   -1,  384,   -1,
 /*    50 */   386,   -1,  389,   -1,  403,   -1,  406,   -1,  409,   -1,
 /*    60 */   414,   -1,  417,   -1,   -1,  419,   -1,  420,   -1,   -1,
 /*    70 */   265,   -1,  422,   -1,   -1,   -1,   -1,   -1,  425,   -1,
 /*    80 */    -1,  439,   -1,   -1,   -1,   -1,   -1,  442,   -1,   -1,
 /*    90 */    -1,   -1,   -1,   -1,  468,  180,   -1,   -1,   -1,  320,
 /*   100 */    -1,   -1,  445,   -1,  450,   -1,  453,   -1,   -1,   -1,
 /*   110 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   120 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  455,   -1,
 /*   130 */    -1,  281,   -1,   -1,   -1,   -1,  458,   -1,   -1,  266,
 /*   140 */    -1,  322,   -1,   -1,   -1,  461,   -1,  512,  301,   -1,
 /*   150 */   330,  311,   -1,  361,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   160 */    -1,  271,   -1,   -1,  359,  503,  504,   -1,  456,   -1,
 /*   170 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   180 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   190 */    -1,   -1,  334,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   200 */    -1,   -1,   -1,   -1,   -1,   -1,  472,   -1,   -1,  294,
 /*   210 */    -1,   -1,  339,   -1,   -1,   -1,  449,   -1,   -1,   -1,
 /*   220 */   317,   -1,   -1,  520,   -1,   -1,   -1,  545,  519,   -1,
 /*   230 */   514,   -1,  469,   -1,  261,   -1,  269,   -1,   -1,  337,
 /*   240 */    -1,   -1,   -1,  553,  530,   -1,   -1,  480,   -1,
};
static YYACTIONTYPE yy_default[] = {
 /*     0 */   388,  388,  388,  388,  388,  388,  309,  318,  323,  311,
 /*    10 */   388,  388,  388,  388,  388,  388,  330,  331,  332,  388,
 /*    20 */   388,  388,  388,  310,  388,  312,  314,  315,  316,  388,
 /*    30 */   388,  333,  388,  335,  388,  336,  388,  337,  388,  338,
 /*    40 */   388,  339,  388,  340,  388,  341,  388,  342,  388,  343,
 /*    50 */   388,  344,  388,  345,  388,  346,  388,  347,  388,  348,
 /*    60 */   388,  349,  388,  350,  388,  388,  351,  388,  352,  388,
 /*    70 */   388,  368,  388,  356,  388,  369,  388,  370,  388,  371,
 /*    80 */   388,  388,  388,  388,  388,  357,  388,  388,  388,  388,
 /*    90 */   388,  358,  359,  387,  362,  388,  388,  360,  388,  388,
 /*   100 */   365,  367,  388,  372,  388,  373,  388,  388,  374,  375,
 /*   110 */   376,  377,  378,  379,  380,  381,  382,  383,  366,  361,
 /*   120 */   388,  385,  388,  384,  388,  386,  388,  354,  388,  353,
 /*   130 */   388,  388,  388,  355,  334,  313,  388,  322,  388,  388,
 /*   140 */   317,  388,  319,  321,  320,  388,  308,  258,  388,  388,
 /*   150 */   388,  269,  255,  388,  266,  306,  388,  304,  305,  307,
 /*   160 */   387,  268,  270,  272,  388,  276,  287,  273,  388,  286,
 /*   170 */   388,  274,  275,  388,  388,  388,  388,  388,  388,  388,
 /*   180 */   388,  388,  388,  388,  388,  388,  388,  388,  388,  388,
 /*   190 */   271,  267,  388,  259,  261,  387,  388,  262,  265,  388,
 /*   200 */   263,  264,  260,  256,  257,  388,  388,  388,  388,  388,
 /*   210 */   388,  388,  388,  290,  292,  291,  388,  388,  388,  388,
 /*   220 */   388,  388,  388,  388,  293,  295,  294,  309,  388,  388,
 /*   230 */   388,  388,  388,  388,  388,  297,  388,  298,  388,  388,
 /*   240 */   300,  301,  299,  309,  388,  388,  388,  388,  303,
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
  "LESSEQUAL",     "AND",           "OR",            "LIKE",        
  "ILIKE",         "BITWISE_AND",   "BITWISE_OR",    "BITWISE_XOR", 
  "DIVIDE",        "TIMES",         "MOD",           "PLUS",        
  "MINUS",         "IS",            "IN",            "NOT",         
  "BITWISE_NOT",   "COMMA",         "SELECT",        "FROM",        
  "DISTINCT",      "ALL",           "IDENTIFIER",    "DOT",         
  "AS",            "INNER",         "JOIN",          "CROSS",       
  "LEFT",          "OUTER",         "RIGHT",         "FULL",        
  "ON",            "INSERT",        "INTO",          "VALUES",      
  "PARENTHESES_OPEN",  "PARENTHESES_CLOSE",  "UPDATE",        "SET",         
  "DELETE",        "WHERE",         "ORDER",         "BY",          
  "ASC",           "DESC",          "GROUP",         "HAVING",      
  "LIMIT",         "OFFSET",        "INTEGER",       "NPLACEHOLDER",
  "SPLACEHOLDER",  "CAST",          "CONVERT",       "USING",       
  "NULL",          "STRING",        "DOUBLE",        "TRUE",        
  "FALSE",         "COLON",         "error",         "program",     
  "query_language",  "select_statement",  "insert_statement",  "update_statement",
  "delete_statement",  "select_clause",  "where_clause",  "group_clause",
  "having_clause",  "order_clause",  "select_limit_clause",  "distinct_all",
  "column_list",   "associated_name_list",  "join_list_or_null",  "column_item", 
  "expr",          "associated_name",  "join_list",     "join_item",   
  "join_clause",   "join_type",     "aliased_or_qualified_name",  "join_associated_name",
  "join_conditions",  "values_list",   "field_list",    "value_list",  
  "value_item",    "field_item",    "update_clause",  "limit_clause",
  "update_item_list",  "update_item",   "qualified_name",  "new_value",   
  "delete_clause",  "order_list",    "order_item",    "group_list",  
  "group_item",    "integer_or_placeholder",  "argument_list",  "function_call",
  "distinct_or_null",  "argument_list_or_null",  "argument_item",
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
 /*  39 */ "insert_statement ::= INSERT INTO aliased_or_qualified_name VALUES PARENTHESES_OPEN values_list PARENTHESES_CLOSE",
 /*  40 */ "insert_statement ::= INSERT INTO aliased_or_qualified_name PARENTHESES_OPEN field_list PARENTHESES_CLOSE VALUES PARENTHESES_OPEN values_list PARENTHESES_CLOSE",
 /*  41 */ "values_list ::= values_list COMMA value_item",
 /*  42 */ "values_list ::= value_item",
 /*  43 */ "value_item ::= expr",
 /*  44 */ "field_list ::= field_list COMMA field_item",
 /*  45 */ "field_list ::= field_item",
 /*  46 */ "field_item ::= IDENTIFIER",
 /*  47 */ "update_statement ::= update_clause where_clause limit_clause",
 /*  48 */ "update_clause ::= UPDATE associated_name SET update_item_list",
 /*  49 */ "update_item_list ::= update_item_list COMMA update_item",
 /*  50 */ "update_item_list ::= update_item",
 /*  51 */ "update_item ::= qualified_name EQUALS new_value",
 /*  52 */ "new_value ::= expr",
 /*  53 */ "delete_statement ::= delete_clause where_clause limit_clause",
 /*  54 */ "delete_clause ::= DELETE FROM associated_name",
 /*  55 */ "associated_name ::= aliased_or_qualified_name AS IDENTIFIER",
 /*  56 */ "associated_name ::= aliased_or_qualified_name IDENTIFIER",
 /*  57 */ "associated_name ::= aliased_or_qualified_name",
 /*  58 */ "aliased_or_qualified_name ::= qualified_name",
 /*  59 */ "where_clause ::= WHERE expr",
 /*  60 */ "where_clause ::=",
 /*  61 */ "order_clause ::= ORDER BY order_list",
 /*  62 */ "order_clause ::=",
 /*  63 */ "order_list ::= order_list COMMA order_item",
 /*  64 */ "order_list ::= order_item",
 /*  65 */ "order_item ::= expr",
 /*  66 */ "order_item ::= expr ASC",
 /*  67 */ "order_item ::= expr DESC",
 /*  68 */ "group_clause ::= GROUP BY group_list",
 /*  69 */ "group_clause ::=",
 /*  70 */ "group_list ::= group_list COMMA group_item",
 /*  71 */ "group_list ::= group_item",
 /*  72 */ "group_item ::= expr",
 /*  73 */ "having_clause ::= HAVING expr",
 /*  74 */ "having_clause ::=",
 /*  75 */ "select_limit_clause ::= LIMIT integer_or_placeholder",
 /*  76 */ "select_limit_clause ::= LIMIT integer_or_placeholder COMMA integer_or_placeholder",
 /*  77 */ "select_limit_clause ::= LIMIT integer_or_placeholder OFFSET integer_or_placeholder",
 /*  78 */ "select_limit_clause ::=",
 /*  79 */ "limit_clause ::= LIMIT integer_or_placeholder",
 /*  80 */ "limit_clause ::=",
 /*  81 */ "integer_or_placeholder ::= INTEGER",
 /*  82 */ "integer_or_placeholder ::= NPLACEHOLDER",
 /*  83 */ "integer_or_placeholder ::= SPLACEHOLDER",
 /*  84 */ "expr ::= MINUS expr",
 /*  85 */ "expr ::= expr MINUS expr",
 /*  86 */ "expr ::= expr PLUS expr",
 /*  87 */ "expr ::= expr TIMES expr",
 /*  88 */ "expr ::= expr DIVIDE expr",
 /*  89 */ "expr ::= expr MOD expr",
 /*  90 */ "expr ::= expr AND expr",
 /*  91 */ "expr ::= expr OR expr",
 /*  92 */ "expr ::= expr BITWISE_AND expr",
 /*  93 */ "expr ::= expr BITWISE_OR expr",
 /*  94 */ "expr ::= expr BITWISE_XOR expr",
 /*  95 */ "expr ::= expr EQUALS expr",
 /*  96 */ "expr ::= expr NOTEQUALS expr",
 /*  97 */ "expr ::= expr LESS expr",
 /*  98 */ "expr ::= expr GREATER expr",
 /*  99 */ "expr ::= expr GREATEREQUAL expr",
 /* 100 */ "expr ::= expr LESSEQUAL expr",
 /* 101 */ "expr ::= expr LIKE expr",
 /* 102 */ "expr ::= expr NOT LIKE expr",
 /* 103 */ "expr ::= expr ILIKE expr",
 /* 104 */ "expr ::= expr NOT ILIKE expr",
 /* 105 */ "expr ::= expr IN PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 106 */ "expr ::= expr NOT IN PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 107 */ "expr ::= expr AGAINST expr",
 /* 108 */ "expr ::= CAST PARENTHESES_OPEN expr AS IDENTIFIER PARENTHESES_CLOSE",
 /* 109 */ "expr ::= CONVERT PARENTHESES_OPEN expr USING IDENTIFIER PARENTHESES_CLOSE",
 /* 110 */ "expr ::= function_call",
 /* 111 */ "function_call ::= IDENTIFIER PARENTHESES_OPEN distinct_or_null argument_list_or_null PARENTHESES_CLOSE",
 /* 112 */ "distinct_or_null ::= DISTINCT",
 /* 113 */ "distinct_or_null ::=",
 /* 114 */ "argument_list_or_null ::= argument_list",
 /* 115 */ "argument_list_or_null ::=",
 /* 116 */ "argument_list ::= argument_list COMMA argument_item",
 /* 117 */ "argument_list ::= argument_item",
 /* 118 */ "argument_item ::= TIMES",
 /* 119 */ "argument_item ::= expr",
 /* 120 */ "expr ::= expr IS NULL",
 /* 121 */ "expr ::= expr IS NOT NULL",
 /* 122 */ "expr ::= expr BETWEEN expr",
 /* 123 */ "expr ::= NOT expr",
 /* 124 */ "expr ::= BITWISE_NOT expr",
 /* 125 */ "expr ::= PARENTHESES_OPEN expr PARENTHESES_CLOSE",
 /* 126 */ "expr ::= qualified_name",
 /* 127 */ "expr ::= INTEGER",
 /* 128 */ "expr ::= STRING",
 /* 129 */ "expr ::= DOUBLE",
 /* 130 */ "expr ::= NULL",
 /* 131 */ "expr ::= TRUE",
 /* 132 */ "expr ::= FALSE",
 /* 133 */ "expr ::= NPLACEHOLDER",
 /* 134 */ "expr ::= SPLACEHOLDER",
 /* 135 */ "qualified_name ::= IDENTIFIER COLON IDENTIFIER DOT IDENTIFIER",
 /* 136 */ "qualified_name ::= IDENTIFIER COLON IDENTIFIER",
 /* 137 */ "qualified_name ::= IDENTIFIER DOT IDENTIFIER",
 /* 138 */ "qualified_name ::= IDENTIFIER",
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
/* #line 528 "parser.y" */
{
	if ((yypminor->yy0)) {
		if ((yypminor->yy0)->free_flag) {
			efree((yypminor->yy0)->token);
		}
		efree((yypminor->yy0));
	}
}
/* #line 1158 "parser.c" */
      break;
    case 72:
    case 73:
    case 74:
    case 75:
    case 76:
    case 77:
    case 84:
    case 85:
    case 87:
    case 88:
    case 89:
    case 90:
    case 91:
    case 92:
    case 93:
    case 94:
    case 98:
    case 99:
    case 101:
    case 102:
    case 104:
    case 105:
    case 106:
    case 108:
    case 109:
    case 110:
    case 111:
    case 112:
    case 114:
    case 115:
    case 118:
/* #line 541 "parser.y" */
{ zval_ptr_dtor(&(yypminor->yy92)); }
/* #line 1193 "parser.c" */
      break;
    case 78:
    case 79:
    case 80:
    case 81:
    case 82:
    case 83:
    case 95:
    case 96:
    case 103:
    case 116:
    case 117:
/* #line 829 "parser.y" */
{ phalcon_safe_zval_ptr_dtor((yypminor->yy92)); }
/* #line 1208 "parser.c" */
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
  { 71, 1 },
  { 72, 1 },
  { 72, 1 },
  { 72, 1 },
  { 72, 1 },
  { 73, 6 },
  { 77, 6 },
  { 83, 1 },
  { 83, 1 },
  { 83, 0 },
  { 84, 3 },
  { 84, 1 },
  { 87, 1 },
  { 87, 3 },
  { 87, 3 },
  { 87, 2 },
  { 87, 1 },
  { 85, 3 },
  { 85, 1 },
  { 86, 1 },
  { 86, 0 },
  { 90, 2 },
  { 90, 1 },
  { 91, 1 },
  { 92, 4 },
  { 95, 2 },
  { 95, 1 },
  { 95, 0 },
  { 93, 2 },
  { 93, 2 },
  { 93, 3 },
  { 93, 2 },
  { 93, 3 },
  { 93, 2 },
  { 93, 3 },
  { 93, 2 },
  { 93, 1 },
  { 96, 2 },
  { 96, 0 },
  { 74, 7 },
  { 74, 10 },
  { 97, 3 },
  { 97, 1 },
  { 100, 1 },
  { 98, 3 },
  { 98, 1 },
  { 101, 1 },
  { 75, 3 },
  { 102, 4 },
  { 104, 3 },
  { 104, 1 },
  { 105, 3 },
  { 107, 1 },
  { 76, 3 },
  { 108, 3 },
  { 89, 3 },
  { 89, 2 },
  { 89, 1 },
  { 94, 1 },
  { 78, 2 },
  { 78, 0 },
  { 81, 3 },
  { 81, 0 },
  { 109, 3 },
  { 109, 1 },
  { 110, 1 },
  { 110, 2 },
  { 110, 2 },
  { 79, 3 },
  { 79, 0 },
  { 111, 3 },
  { 111, 1 },
  { 112, 1 },
  { 80, 2 },
  { 80, 0 },
  { 82, 2 },
  { 82, 4 },
  { 82, 4 },
  { 82, 0 },
  { 103, 2 },
  { 103, 0 },
  { 113, 1 },
  { 113, 1 },
  { 113, 1 },
  { 88, 2 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 4 },
  { 88, 3 },
  { 88, 4 },
  { 88, 5 },
  { 88, 6 },
  { 88, 3 },
  { 88, 6 },
  { 88, 6 },
  { 88, 1 },
  { 115, 5 },
  { 116, 1 },
  { 116, 0 },
  { 117, 1 },
  { 117, 0 },
  { 114, 3 },
  { 114, 1 },
  { 118, 1 },
  { 118, 1 },
  { 88, 3 },
  { 88, 4 },
  { 88, 3 },
  { 88, 2 },
  { 88, 2 },
  { 88, 3 },
  { 88, 1 },
  { 88, 1 },
  { 88, 1 },
  { 88, 1 },
  { 88, 1 },
  { 88, 1 },
  { 88, 1 },
  { 88, 1 },
  { 88, 1 },
  { 106, 5 },
  { 106, 3 },
  { 106, 3 },
  { 106, 1 },
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
/* #line 537 "parser.y" */
{
	status->ret = yymsp[0].minor.yy92;
}
/* #line 1564 "parser.c" */
        break;
      case 1:
      case 2:
      case 3:
      case 4:
      case 18:
      case 19:
      case 22:
      case 23:
      case 43:
      case 50:
      case 52:
      case 58:
      case 64:
      case 71:
      case 72:
      case 110:
      case 114:
      case 119:
      case 126:
/* #line 543 "parser.y" */
{
	yygotominor.yy92 = yymsp[0].minor.yy92;
}
/* #line 1589 "parser.c" */
        break;
      case 5:
/* #line 561 "parser.y" */
{
	yygotominor.yy92 = phql_ret_select_statement(yymsp[-5].minor.yy92, yymsp[-4].minor.yy92, yymsp[-1].minor.yy92, yymsp[-3].minor.yy92, yymsp[-2].minor.yy92, yymsp[0].minor.yy92);
}
/* #line 1596 "parser.c" */
        break;
      case 6:
/* #line 567 "parser.y" */
{
	yygotominor.yy92 = phql_ret_select_clause(yymsp[-4].minor.yy92, yymsp[-3].minor.yy92, yymsp[-1].minor.yy92, yymsp[0].minor.yy92);
  yy_destructor(26,&yymsp[-5].minor);
  yy_destructor(27,&yymsp[-2].minor);
}
/* #line 1605 "parser.c" */
        break;
      case 7:
/* #line 573 "parser.y" */
{
	yygotominor.yy92 = phql_ret_distinct_all(1);
  yy_destructor(28,&yymsp[0].minor);
}
/* #line 1613 "parser.c" */
        break;
      case 8:
/* #line 577 "parser.y" */
{
	yygotominor.yy92 = phql_ret_distinct_all(0);
  yy_destructor(29,&yymsp[0].minor);
}
/* #line 1621 "parser.c" */
        break;
      case 9:
      case 20:
      case 27:
      case 38:
      case 60:
      case 62:
      case 69:
      case 74:
      case 78:
      case 80:
      case 113:
      case 115:
/* #line 581 "parser.y" */
{
	yygotominor.yy92 = NULL;
}
/* #line 1639 "parser.c" */
        break;
      case 10:
      case 17:
      case 41:
      case 44:
      case 49:
      case 63:
      case 70:
      case 116:
/* #line 587 "parser.y" */
{
	yygotominor.yy92 = phql_ret_zval_list(yymsp[-2].minor.yy92, yymsp[0].minor.yy92);
  yy_destructor(25,&yymsp[-1].minor);
}
/* #line 1654 "parser.c" */
        break;
      case 11:
      case 42:
      case 45:
      case 117:
/* #line 591 "parser.y" */
{
	yygotominor.yy92 = phql_ret_zval_list(yymsp[0].minor.yy92, NULL);
}
/* #line 1664 "parser.c" */
        break;
      case 12:
      case 118:
/* #line 597 "parser.y" */
{
	yygotominor.yy92 = phql_ret_column_item(PHQL_T_STARALL, NULL, NULL, NULL);
  yy_destructor(17,&yymsp[0].minor);
}
/* #line 1673 "parser.c" */
        break;
      case 13:
/* #line 601 "parser.y" */
{
	yygotominor.yy92 = phql_ret_column_item(PHQL_T_DOMAINALL, NULL, yymsp[-2].minor.yy0, NULL);
  yy_destructor(31,&yymsp[-1].minor);
  yy_destructor(17,&yymsp[0].minor);
}
/* #line 1682 "parser.c" */
        break;
      case 14:
/* #line 605 "parser.y" */
{
	yygotominor.yy92 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-2].minor.yy92, NULL, yymsp[0].minor.yy0);
  yy_destructor(32,&yymsp[-1].minor);
}
/* #line 1690 "parser.c" */
        break;
      case 15:
/* #line 609 "parser.y" */
{
	yygotominor.yy92 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-1].minor.yy92, NULL, yymsp[0].minor.yy0);
}
/* #line 1697 "parser.c" */
        break;
      case 16:
/* #line 613 "parser.y" */
{
	yygotominor.yy92 = phql_ret_column_item(PHQL_T_EXPR, yymsp[0].minor.yy92, NULL, NULL);
}
/* #line 1704 "parser.c" */
        break;
      case 21:
/* #line 637 "parser.y" */
{
	yygotominor.yy92 = phql_ret_zval_list(yymsp[-1].minor.yy92, yymsp[0].minor.yy92);
}
/* #line 1711 "parser.c" */
        break;
      case 24:
/* #line 654 "parser.y" */
{
	yygotominor.yy92 = phql_ret_join_item(yymsp[-3].minor.yy92, yymsp[-2].minor.yy92, yymsp[-1].minor.yy92, yymsp[0].minor.yy92);
}
/* #line 1718 "parser.c" */
        break;
      case 25:
/* #line 660 "parser.y" */
{
	yygotominor.yy92 = phql_ret_qualified_name(NULL, NULL, yymsp[0].minor.yy0);
  yy_destructor(32,&yymsp[-1].minor);
}
/* #line 1726 "parser.c" */
        break;
      case 26:
      case 46:
      case 138:
/* #line 664 "parser.y" */
{
	yygotominor.yy92 = phql_ret_qualified_name(NULL, NULL, yymsp[0].minor.yy0);
}
/* #line 1735 "parser.c" */
        break;
      case 28:
/* #line 674 "parser.y" */
{
	yygotominor.yy92 = phql_ret_join_type(PHQL_T_INNERJOIN);
  yy_destructor(33,&yymsp[-1].minor);
  yy_destructor(34,&yymsp[0].minor);
}
/* #line 1744 "parser.c" */
        break;
      case 29:
/* #line 678 "parser.y" */
{
	yygotominor.yy92 = phql_ret_join_type(PHQL_T_CROSSJOIN);
  yy_destructor(35,&yymsp[-1].minor);
  yy_destructor(34,&yymsp[0].minor);
}
/* #line 1753 "parser.c" */
        break;
      case 30:
/* #line 682 "parser.y" */
{
	yygotominor.yy92 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  yy_destructor(36,&yymsp[-2].minor);
  yy_destructor(37,&yymsp[-1].minor);
  yy_destructor(34,&yymsp[0].minor);
}
/* #line 1763 "parser.c" */
        break;
      case 31:
/* #line 686 "parser.y" */
{
	yygotominor.yy92 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  yy_destructor(36,&yymsp[-1].minor);
  yy_destructor(34,&yymsp[0].minor);
}
/* #line 1772 "parser.c" */
        break;
      case 32:
/* #line 690 "parser.y" */
{
	yygotominor.yy92 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  yy_destructor(38,&yymsp[-2].minor);
  yy_destructor(37,&yymsp[-1].minor);
  yy_destructor(34,&yymsp[0].minor);
}
/* #line 1782 "parser.c" */
        break;
      case 33:
/* #line 694 "parser.y" */
{
	yygotominor.yy92 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  yy_destructor(38,&yymsp[-1].minor);
  yy_destructor(34,&yymsp[0].minor);
}
/* #line 1791 "parser.c" */
        break;
      case 34:
/* #line 698 "parser.y" */
{
	yygotominor.yy92 = phql_ret_join_type(PHQL_T_FULLJOIN);
  yy_destructor(39,&yymsp[-2].minor);
  yy_destructor(37,&yymsp[-1].minor);
  yy_destructor(34,&yymsp[0].minor);
}
/* #line 1801 "parser.c" */
        break;
      case 35:
/* #line 702 "parser.y" */
{
	yygotominor.yy92 = phql_ret_join_type(PHQL_T_FULLJOIN);
  yy_destructor(39,&yymsp[-1].minor);
  yy_destructor(34,&yymsp[0].minor);
}
/* #line 1810 "parser.c" */
        break;
      case 36:
/* #line 706 "parser.y" */
{
	yygotominor.yy92 = phql_ret_join_type(PHQL_T_INNERJOIN);
  yy_destructor(34,&yymsp[0].minor);
}
/* #line 1818 "parser.c" */
        break;
      case 37:
/* #line 712 "parser.y" */
{
	yygotominor.yy92 = yymsp[0].minor.yy92;
  yy_destructor(40,&yymsp[-1].minor);
}
/* #line 1826 "parser.c" */
        break;
      case 39:
/* #line 723 "parser.y" */
{
	yygotominor.yy92 = phql_ret_insert_statement(yymsp[-4].minor.yy92, NULL, yymsp[-1].minor.yy92);
  yy_destructor(41,&yymsp[-6].minor);
  yy_destructor(42,&yymsp[-5].minor);
  yy_destructor(43,&yymsp[-3].minor);
  yy_destructor(44,&yymsp[-2].minor);
  yy_destructor(45,&yymsp[0].minor);
}
/* #line 1838 "parser.c" */
        break;
      case 40:
/* #line 727 "parser.y" */
{
	yygotominor.yy92 = phql_ret_insert_statement(yymsp[-7].minor.yy92, yymsp[-5].minor.yy92, yymsp[-1].minor.yy92);
  yy_destructor(41,&yymsp[-9].minor);
  yy_destructor(42,&yymsp[-8].minor);
  yy_destructor(44,&yymsp[-6].minor);
  yy_destructor(45,&yymsp[-4].minor);
  yy_destructor(43,&yymsp[-3].minor);
  yy_destructor(44,&yymsp[-2].minor);
  yy_destructor(45,&yymsp[0].minor);
}
/* #line 1852 "parser.c" */
        break;
      case 47:
/* #line 765 "parser.y" */
{
	yygotominor.yy92 = phql_ret_update_statement(yymsp[-2].minor.yy92, yymsp[-1].minor.yy92, yymsp[0].minor.yy92);
}
/* #line 1859 "parser.c" */
        break;
      case 48:
/* #line 771 "parser.y" */
{
	yygotominor.yy92 = phql_ret_update_clause(yymsp[-2].minor.yy92, yymsp[0].minor.yy92);
  yy_destructor(46,&yymsp[-3].minor);
  yy_destructor(47,&yymsp[-1].minor);
}
/* #line 1868 "parser.c" */
        break;
      case 51:
/* #line 787 "parser.y" */
{
	yygotominor.yy92 = phql_ret_update_item(yymsp[-2].minor.yy92, yymsp[0].minor.yy92);
  yy_destructor(3,&yymsp[-1].minor);
}
/* #line 1876 "parser.c" */
        break;
      case 53:
/* #line 799 "parser.y" */
{
	yygotominor.yy92 = phql_ret_delete_statement(yymsp[-2].minor.yy92, yymsp[-1].minor.yy92, yymsp[0].minor.yy92);
}
/* #line 1883 "parser.c" */
        break;
      case 54:
/* #line 805 "parser.y" */
{
	yygotominor.yy92 = phql_ret_delete_clause(yymsp[0].minor.yy92);
  yy_destructor(48,&yymsp[-2].minor);
  yy_destructor(27,&yymsp[-1].minor);
}
/* #line 1892 "parser.c" */
        break;
      case 55:
/* #line 811 "parser.y" */
{
	yygotominor.yy92 = phql_ret_assoc_name(yymsp[-2].minor.yy92, yymsp[0].minor.yy0);
  yy_destructor(32,&yymsp[-1].minor);
}
/* #line 1900 "parser.c" */
        break;
      case 56:
/* #line 815 "parser.y" */
{
	yygotominor.yy92 = phql_ret_assoc_name(yymsp[-1].minor.yy92, yymsp[0].minor.yy0);
}
/* #line 1907 "parser.c" */
        break;
      case 57:
/* #line 819 "parser.y" */
{
	yygotominor.yy92 = phql_ret_assoc_name(yymsp[0].minor.yy92, NULL);
}
/* #line 1914 "parser.c" */
        break;
      case 59:
/* #line 831 "parser.y" */
{
	yygotominor.yy92 = yymsp[0].minor.yy92;
  yy_destructor(49,&yymsp[-1].minor);
}
/* #line 1922 "parser.c" */
        break;
      case 61:
/* #line 841 "parser.y" */
{
	yygotominor.yy92 = yymsp[0].minor.yy92;
  yy_destructor(50,&yymsp[-2].minor);
  yy_destructor(51,&yymsp[-1].minor);
}
/* #line 1931 "parser.c" */
        break;
      case 65:
/* #line 861 "parser.y" */
{
	yygotominor.yy92 = phql_ret_order_item(yymsp[0].minor.yy92, 0);
}
/* #line 1938 "parser.c" */
        break;
      case 66:
/* #line 865 "parser.y" */
{
	yygotominor.yy92 = phql_ret_order_item(yymsp[-1].minor.yy92, PHQL_T_ASC);
  yy_destructor(52,&yymsp[0].minor);
}
/* #line 1946 "parser.c" */
        break;
      case 67:
/* #line 869 "parser.y" */
{
	yygotominor.yy92 = phql_ret_order_item(yymsp[-1].minor.yy92, PHQL_T_DESC);
  yy_destructor(53,&yymsp[0].minor);
}
/* #line 1954 "parser.c" */
        break;
      case 68:
/* #line 875 "parser.y" */
{
	yygotominor.yy92 = yymsp[0].minor.yy92;
  yy_destructor(54,&yymsp[-2].minor);
  yy_destructor(51,&yymsp[-1].minor);
}
/* #line 1963 "parser.c" */
        break;
      case 73:
/* #line 901 "parser.y" */
{
	yygotominor.yy92 = yymsp[0].minor.yy92;
  yy_destructor(55,&yymsp[-1].minor);
}
/* #line 1971 "parser.c" */
        break;
      case 75:
      case 79:
/* #line 911 "parser.y" */
{
	yygotominor.yy92 = phql_ret_limit_clause(yymsp[0].minor.yy92, NULL);
  yy_destructor(56,&yymsp[-1].minor);
}
/* #line 1980 "parser.c" */
        break;
      case 76:
/* #line 915 "parser.y" */
{
	yygotominor.yy92 = phql_ret_limit_clause(yymsp[0].minor.yy92, yymsp[-2].minor.yy92);
  yy_destructor(56,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
/* #line 1989 "parser.c" */
        break;
      case 77:
/* #line 919 "parser.y" */
{
	yygotominor.yy92 = phql_ret_limit_clause(yymsp[-2].minor.yy92, yymsp[0].minor.yy92);
  yy_destructor(56,&yymsp[-3].minor);
  yy_destructor(57,&yymsp[-1].minor);
}
/* #line 1998 "parser.c" */
        break;
      case 81:
      case 127:
/* #line 937 "parser.y" */
{
	yygotominor.yy92 = phql_ret_literal_zval(PHQL_T_INTEGER, yymsp[0].minor.yy0);
}
/* #line 2006 "parser.c" */
        break;
      case 82:
      case 133:
/* #line 941 "parser.y" */
{
	yygotominor.yy92 = phql_ret_placeholder_zval(PHQL_T_NPLACEHOLDER, yymsp[0].minor.yy0);
}
/* #line 2014 "parser.c" */
        break;
      case 83:
      case 134:
/* #line 945 "parser.y" */
{
	yygotominor.yy92 = phql_ret_placeholder_zval(PHQL_T_SPLACEHOLDER, yymsp[0].minor.yy0);
}
/* #line 2022 "parser.c" */
        break;
      case 84:
/* #line 951 "parser.y" */
{
	yygotominor.yy92 = phql_ret_expr(PHQL_T_MINUS, NULL, yymsp[0].minor.yy92);
  yy_destructor(20,&yymsp[-1].minor);
}
/* #line 2030 "parser.c" */
        break;
      case 85:
/* #line 955 "parser.y" */
{
	yygotominor.yy92 = phql_ret_expr(PHQL_T_SUB, yymsp[-2].minor.yy92, yymsp[0].minor.yy92);
  yy_destructor(20,&yymsp[-1].minor);
}
/* #line 2038 "parser.c" */
        break;
      case 86:
/* #line 959 "parser.y" */
{
	yygotominor.yy92 = phql_ret_expr(PHQL_T_ADD, yymsp[-2].minor.yy92, yymsp[0].minor.yy92);
  yy_destructor(19,&yymsp[-1].minor);
}
/* #line 2046 "parser.c" */
        break;
      case 87:
/* #line 963 "parser.y" */
{
	yygotominor.yy92 = phql_ret_expr(PHQL_T_MUL, yymsp[-2].minor.yy92, yymsp[0].minor.yy92);
  yy_destructor(17,&yymsp[-1].minor);
}
/* #line 2054 "parser.c" */
        break;
      case 88:
/* #line 967 "parser.y" */
{
	yygotominor.yy92 = phql_ret_expr(PHQL_T_DIV, yymsp[-2].minor.yy92, yymsp[0].minor.yy92);
  yy_destructor(16,&yymsp[-1].minor);
}
/* #line 2062 "parser.c" */
        break;
      case 89:
/* #line 971 "parser.y" */
{
	yygotominor.yy92 = phql_ret_expr(PHQL_T_MOD, yymsp[-2].minor.yy92, yymsp[0].minor.yy92);
  yy_destructor(18,&yymsp[-1].minor);
}
/* #line 2070 "parser.c" */
        break;
      case 90:
/* #line 975 "parser.y" */
{
	yygotominor.yy92 = phql_ret_expr(PHQL_T_AND, yymsp[-2].minor.yy92, yymsp[0].minor.yy92);
  yy_destructor(9,&yymsp[-1].minor);
}
/* #line 2078 "parser.c" */
        break;
      case 91:
/* #line 979 "parser.y" */
{
	yygotominor.yy92 = phql_ret_expr(PHQL_T_OR, yymsp[-2].minor.yy92, yymsp[0].minor.yy92);
  yy_destructor(10,&yymsp[-1].minor);
}
/* #line 2086 "parser.c" */
        break;
      case 92:
/* #line 983 "parser.y" */
{
	yygotominor.yy92 = phql_ret_expr(PHQL_T_BITWISE_AND, yymsp[-2].minor.yy92, yymsp[0].minor.yy92);
  yy_destructor(13,&yymsp[-1].minor);
}
/* #line 2094 "parser.c" */
        break;
      case 93:
/* #line 987 "parser.y" */
{
	yygotominor.yy92 = phql_ret_expr(PHQL_T_BITWISE_OR, yymsp[-2].minor.yy92, yymsp[0].minor.yy92);
  yy_destructor(14,&yymsp[-1].minor);
}
/* #line 2102 "parser.c" */
        break;
      case 94:
/* #line 991 "parser.y" */
{
	yygotominor.yy92 = phql_ret_expr(PHQL_T_BITWISE_XOR, yymsp[-2].minor.yy92, yymsp[0].minor.yy92);
  yy_destructor(15,&yymsp[-1].minor);
}
/* #line 2110 "parser.c" */
        break;
      case 95:
/* #line 995 "parser.y" */
{
	yygotominor.yy92 = phql_ret_expr(PHQL_T_EQUALS, yymsp[-2].minor.yy92, yymsp[0].minor.yy92);
  yy_destructor(3,&yymsp[-1].minor);
}
/* #line 2118 "parser.c" */
        break;
      case 96:
/* #line 999 "parser.y" */
{
	yygotominor.yy92 = phql_ret_expr(PHQL_T_NOTEQUALS, yymsp[-2].minor.yy92, yymsp[0].minor.yy92);
  yy_destructor(4,&yymsp[-1].minor);
}
/* #line 2126 "parser.c" */
        break;
      case 97:
/* #line 1003 "parser.y" */
{
	yygotominor.yy92 = phql_ret_expr(PHQL_T_LESS, yymsp[-2].minor.yy92, yymsp[0].minor.yy92);
  yy_destructor(5,&yymsp[-1].minor);
}
/* #line 2134 "parser.c" */
        break;
      case 98:
/* #line 1007 "parser.y" */
{
	yygotominor.yy92 = phql_ret_expr(PHQL_T_GREATER, yymsp[-2].minor.yy92, yymsp[0].minor.yy92);
  yy_destructor(6,&yymsp[-1].minor);
}
/* #line 2142 "parser.c" */
        break;
      case 99:
/* #line 1011 "parser.y" */
{
	yygotominor.yy92 = phql_ret_expr(PHQL_T_GREATEREQUAL, yymsp[-2].minor.yy92, yymsp[0].minor.yy92);
  yy_destructor(7,&yymsp[-1].minor);
}
/* #line 2150 "parser.c" */
        break;
      case 100:
/* #line 1015 "parser.y" */
{
	yygotominor.yy92 = phql_ret_expr(PHQL_T_LESSEQUAL, yymsp[-2].minor.yy92, yymsp[0].minor.yy92);
  yy_destructor(8,&yymsp[-1].minor);
}
/* #line 2158 "parser.c" */
        break;
      case 101:
/* #line 1019 "parser.y" */
{
	yygotominor.yy92 = phql_ret_expr(PHQL_T_LIKE, yymsp[-2].minor.yy92, yymsp[0].minor.yy92);
  yy_destructor(11,&yymsp[-1].minor);
}
/* #line 2166 "parser.c" */
        break;
      case 102:
/* #line 1023 "parser.y" */
{
	yygotominor.yy92 = phql_ret_expr(PHQL_T_NLIKE, yymsp[-3].minor.yy92, yymsp[0].minor.yy92);
  yy_destructor(23,&yymsp[-2].minor);
  yy_destructor(11,&yymsp[-1].minor);
}
/* #line 2175 "parser.c" */
        break;
      case 103:
/* #line 1027 "parser.y" */
{
	yygotominor.yy92 = phql_ret_expr(PHQL_T_ILIKE, yymsp[-2].minor.yy92, yymsp[0].minor.yy92);
  yy_destructor(12,&yymsp[-1].minor);
}
/* #line 2183 "parser.c" */
        break;
      case 104:
/* #line 1031 "parser.y" */
{
	yygotominor.yy92 = phql_ret_expr(PHQL_T_NILIKE, yymsp[-3].minor.yy92, yymsp[0].minor.yy92);
  yy_destructor(23,&yymsp[-2].minor);
  yy_destructor(12,&yymsp[-1].minor);
}
/* #line 2192 "parser.c" */
        break;
      case 105:
/* #line 1035 "parser.y" */
{
	yygotominor.yy92 = phql_ret_expr(PHQL_T_IN, yymsp[-4].minor.yy92, yymsp[-1].minor.yy92);
  yy_destructor(22,&yymsp[-3].minor);
  yy_destructor(44,&yymsp[-2].minor);
  yy_destructor(45,&yymsp[0].minor);
}
/* #line 2202 "parser.c" */
        break;
      case 106:
/* #line 1039 "parser.y" */
{
	yygotominor.yy92 = phql_ret_expr(PHQL_T_NOTIN, yymsp[-5].minor.yy92, yymsp[-1].minor.yy92);
  yy_destructor(23,&yymsp[-4].minor);
  yy_destructor(22,&yymsp[-3].minor);
  yy_destructor(44,&yymsp[-2].minor);
  yy_destructor(45,&yymsp[0].minor);
}
/* #line 2213 "parser.c" */
        break;
      case 107:
/* #line 1043 "parser.y" */
{
	yygotominor.yy92 = phql_ret_expr(PHQL_T_AGAINST, yymsp[-2].minor.yy92, yymsp[0].minor.yy92);
  yy_destructor(1,&yymsp[-1].minor);
}
/* #line 2221 "parser.c" */
        break;
      case 108:
/* #line 1047 "parser.y" */
{
	yygotominor.yy92 = phql_ret_expr(PHQL_T_CAST, yymsp[-3].minor.yy92, phql_ret_raw_qualified_name(yymsp[-1].minor.yy0, NULL));
  yy_destructor(61,&yymsp[-5].minor);
  yy_destructor(44,&yymsp[-4].minor);
  yy_destructor(32,&yymsp[-2].minor);
  yy_destructor(45,&yymsp[0].minor);
}
/* #line 2232 "parser.c" */
        break;
      case 109:
/* #line 1051 "parser.y" */
{
	yygotominor.yy92 = phql_ret_expr(PHQL_T_CONVERT, yymsp[-3].minor.yy92, phql_ret_raw_qualified_name(yymsp[-1].minor.yy0, NULL));
  yy_destructor(62,&yymsp[-5].minor);
  yy_destructor(44,&yymsp[-4].minor);
  yy_destructor(63,&yymsp[-2].minor);
  yy_destructor(45,&yymsp[0].minor);
}
/* #line 2243 "parser.c" */
        break;
      case 111:
/* #line 1061 "parser.y" */
{
	yygotominor.yy92 = phql_ret_func_call(yymsp[-4].minor.yy0, yymsp[-1].minor.yy92, yymsp[-2].minor.yy92);
  yy_destructor(44,&yymsp[-3].minor);
  yy_destructor(45,&yymsp[0].minor);
}
/* #line 2252 "parser.c" */
        break;
      case 112:
/* #line 1067 "parser.y" */
{
	yygotominor.yy92 = phql_ret_distinct();
  yy_destructor(28,&yymsp[0].minor);
}
/* #line 2260 "parser.c" */
        break;
      case 120:
/* #line 1105 "parser.y" */
{
	yygotominor.yy92 = phql_ret_expr(PHQL_T_ISNULL, yymsp[-2].minor.yy92, NULL);
  yy_destructor(21,&yymsp[-1].minor);
  yy_destructor(64,&yymsp[0].minor);
}
/* #line 2269 "parser.c" */
        break;
      case 121:
/* #line 1109 "parser.y" */
{
	yygotominor.yy92 = phql_ret_expr(PHQL_T_ISNOTNULL, yymsp[-3].minor.yy92, NULL);
  yy_destructor(21,&yymsp[-2].minor);
  yy_destructor(23,&yymsp[-1].minor);
  yy_destructor(64,&yymsp[0].minor);
}
/* #line 2279 "parser.c" */
        break;
      case 122:
/* #line 1113 "parser.y" */
{
	yygotominor.yy92 = phql_ret_expr(PHQL_T_BETWEEN, yymsp[-2].minor.yy92, yymsp[0].minor.yy92);
  yy_destructor(2,&yymsp[-1].minor);
}
/* #line 2287 "parser.c" */
        break;
      case 123:
/* #line 1117 "parser.y" */
{
	yygotominor.yy92 = phql_ret_expr(PHQL_T_NOT, NULL, yymsp[0].minor.yy92);
  yy_destructor(23,&yymsp[-1].minor);
}
/* #line 2295 "parser.c" */
        break;
      case 124:
/* #line 1121 "parser.y" */
{
	yygotominor.yy92 = phql_ret_expr(PHQL_T_BITWISE_NOT, NULL, yymsp[0].minor.yy92);
  yy_destructor(24,&yymsp[-1].minor);
}
/* #line 2303 "parser.c" */
        break;
      case 125:
/* #line 1125 "parser.y" */
{
	yygotominor.yy92 = phql_ret_expr(PHQL_T_ENCLOSED, yymsp[-1].minor.yy92, NULL);
  yy_destructor(44,&yymsp[-2].minor);
  yy_destructor(45,&yymsp[0].minor);
}
/* #line 2312 "parser.c" */
        break;
      case 128:
/* #line 1137 "parser.y" */
{
	yygotominor.yy92 = phql_ret_literal_zval(PHQL_T_STRING, yymsp[0].minor.yy0);
}
/* #line 2319 "parser.c" */
        break;
      case 129:
/* #line 1141 "parser.y" */
{
	yygotominor.yy92 = phql_ret_literal_zval(PHQL_T_DOUBLE, yymsp[0].minor.yy0);
}
/* #line 2326 "parser.c" */
        break;
      case 130:
/* #line 1145 "parser.y" */
{
	yygotominor.yy92 = phql_ret_literal_zval(PHQL_T_NULL, NULL);
  yy_destructor(64,&yymsp[0].minor);
}
/* #line 2334 "parser.c" */
        break;
      case 131:
/* #line 1149 "parser.y" */
{
	yygotominor.yy92 = phql_ret_literal_zval(PHQL_T_TRUE, NULL);
  yy_destructor(67,&yymsp[0].minor);
}
/* #line 2342 "parser.c" */
        break;
      case 132:
/* #line 1153 "parser.y" */
{
	yygotominor.yy92 = phql_ret_literal_zval(PHQL_T_FALSE, NULL);
  yy_destructor(68,&yymsp[0].minor);
}
/* #line 2350 "parser.c" */
        break;
      case 135:
/* #line 1167 "parser.y" */
{
	yygotominor.yy92 = phql_ret_qualified_name(yymsp[-4].minor.yy0, yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(69,&yymsp[-3].minor);
  yy_destructor(31,&yymsp[-1].minor);
}
/* #line 2359 "parser.c" */
        break;
      case 136:
/* #line 1171 "parser.y" */
{
	yygotominor.yy92 = phql_ret_qualified_name(yymsp[-2].minor.yy0, NULL, yymsp[0].minor.yy0);
  yy_destructor(69,&yymsp[-1].minor);
}
/* #line 2367 "parser.c" */
        break;
      case 137:
/* #line 1175 "parser.y" */
{
	yygotominor.yy92 = phql_ret_qualified_name(NULL, yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(31,&yymsp[-1].minor);
}
/* #line 2375 "parser.c" */
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
/* #line 461 "parser.y" */

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

/* #line 2484 "parser.c" */
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
	int scanner_status, status = SUCCESS, error_length, cache_level;
	phql_scanner_state *state;
	phql_scanner_token token;
	unsigned long phql_key = 0;
	void* phql_parser;
	char *error;
	zval **temp_ast;

	if (!phql) {
		MAKE_STD_ZVAL(*error_msg);
		ZVAL_STRING(*error_msg, "PHQL statement cannot be NULL", 1);
		return FAILURE;
	}

	cache_level = phalcon_globals_ptr->orm.cache_level;
	if (cache_level >= 0) {

		phql_key = zend_inline_hash_func(phql, phql_length + 1);

		if (phalcon_globals_ptr->orm.parser_cache != NULL) {
			if (zend_hash_index_find(phalcon_globals_ptr->orm.parser_cache, phql_key, (void**) &temp_ast) == SUCCESS) {
				ZVAL_ZVAL(*result, *temp_ast, 1, 0);
				Z_SET_REFCOUNT_P(*result, 1);
				return SUCCESS;
			}
		}
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
				if (cache_level >= 0) {

					if (!phalcon_globals_ptr->orm.parser_cache) {
						ALLOC_HASHTABLE(phalcon_globals_ptr->orm.parser_cache);
						zend_hash_init(phalcon_globals_ptr->orm.parser_cache, 0, NULL, ZVAL_PTR_DTOR, 0);
					}

					Z_ADDREF_PP(result);

					zend_hash_index_update(
						phalcon_globals_ptr->orm.parser_cache,
						phql_key,
						result,
						sizeof(zval *),
						NULL
					);
				}

			} else {
				efree(parser_status->ret);
			}
		}
	}

	efree(parser_status);
	efree(state);

	return status;
}
