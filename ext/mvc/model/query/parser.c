/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is include which follows the "include" declaration
** in the input file. */
#include <stdio.h>
/* #line 39 "parser.y" */


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "parser.h"
#include "scanner.h"
#include "phql.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"

static zval *phql_ret_literal_zval(int type, phql_parser_token *T)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", type);
	if (T) {
		add_assoc_stringl(ret, "value", T->token, T->token_len, 0);
		efree(T);
	}

	return ret;
}

static zval *phql_ret_placeholder_zval(int type, phql_parser_token *T)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 2);
	add_assoc_long(ret, "type", type);
	add_assoc_stringl(ret, "value", T->token, T->token_len, 0);
	efree(T);

	return ret;
}

static zval *phql_ret_qualified_name(phql_parser_token *A, phql_parser_token *B, phql_parser_token *C)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	add_assoc_long(ret, "type", PHQL_T_QUALIFIED);

	if (A != NULL) {
		add_assoc_stringl(ret, "ns-alias", A->token, A->token_len, 0);
		efree(A);
	}

	if (B != NULL) {
		add_assoc_stringl(ret, "domain", B->token, B->token_len, 0);
		efree(B);
	}

	add_assoc_stringl(ret, "name", C->token, C->token_len, 0);
	efree(C);

	return ret;
}

static zval *phql_ret_raw_qualified_name(phql_parser_token *A, phql_parser_token *B)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	add_assoc_long(ret, "type", PHQL_T_RAW_QUALIFIED);
	if (B != NULL) {
		add_assoc_stringl(ret, "domain", A->token, A->token_len, 0);
		add_assoc_stringl(ret, "name", B->token, B->token_len, 0);
		efree(B);
	} else {
		add_assoc_stringl(ret, "name", A->token, A->token_len, 0);
	}
	efree(A);

	return ret;
}

static zval *phql_ret_select_statement(zval *S, zval *W, zval *O, zval *G, zval *H, zval *L)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	add_assoc_long(ret, "type", PHQL_T_SELECT);
	add_assoc_zval(ret, "select", S);

	if (W != NULL) {
		add_assoc_zval(ret, "where", W);
	}
	if (O != NULL) {
		add_assoc_zval(ret, "orderBy", O);
	}
	if (G != NULL) {
		add_assoc_zval(ret, "groupBy", G);
	}
	if (H != NULL) {
		add_assoc_zval(ret, "having", H);
	}
	if (L != NULL) {
		add_assoc_zval(ret, "limit", L);
	}

	return ret;
}

static zval *phql_ret_select_clause(zval *columns, zval *tables, zval *join_list)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_zval(ret, "columns", columns);
	add_assoc_zval(ret, "tables", tables);
	if (join_list) {
		add_assoc_zval(ret, "joins", join_list);
	}

	return ret;
}

static zval *phql_ret_order_item(zval *column, int sort){

	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_zval(ret, "column", column);
	if (sort != 0 ) {
		add_assoc_long(ret, "sort", sort);
	}

	return ret;
}

static zval *phql_ret_limit_clause(zval *L, zval *O)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 2);

	add_assoc_zval(ret, "number", L);

	if (O != NULL) {
		add_assoc_zval(ret, "offset", O);
	}

	return ret;
}

static zval *phql_ret_insert_statement(zval *Q, zval *F, zval *V)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	add_assoc_long(ret, "type", PHQL_T_INSERT);
	add_assoc_zval(ret, "qualifiedName", Q);
	if (F != NULL) {
		add_assoc_zval(ret, "fields", F);
	}
	add_assoc_zval(ret, "values", V);

	return ret;
}

static zval *phql_ret_update_statement(zval *U, zval *W, zval *L)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	add_assoc_long(ret, "type", PHQL_T_UPDATE);
	add_assoc_zval(ret, "update", U);
	if (W != NULL) {
		add_assoc_zval(ret, "where", W);
	}
	if (L != NULL) {
		add_assoc_zval(ret, "limit", L);
	}

	return ret;
}

static zval *phql_ret_update_clause(zval *tables, zval *values)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 2);
	add_assoc_zval(ret, "tables", tables);
	add_assoc_zval(ret, "values", values);

	return ret;
}

static zval *phql_ret_update_item(zval *column, zval *expr)
{

	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 2);
	add_assoc_zval(ret, "column", column);
	add_assoc_zval(ret, "expr", expr);

	return ret;
}

static zval *phql_ret_delete_statement(zval *D, zval *W, zval *L)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	add_assoc_long(ret, "type", PHQL_T_DELETE);
	add_assoc_zval(ret, "delete", D);
	if (W != NULL) {
		add_assoc_zval(ret, "where", W);
	}
	if (L != NULL) {
		add_assoc_zval(ret, "limit", L);
	}

	return ret;
}

static zval *phql_ret_delete_clause(zval *tables)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 1);
	add_assoc_zval(ret, "tables", tables);

	return ret;
}

static zval *phql_ret_zval_list(zval *list_left, zval *right_list)
{

	zval *ret;
	HashPosition pos;
	HashTable *list;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	list = Z_ARRVAL_P(list_left);
	if (zend_hash_index_exists(list, 0)) {
		zend_hash_internal_pointer_reset_ex(list, &pos);
		for (;; zend_hash_move_forward_ex(list, &pos)) {

			zval ** item;

			if (zend_hash_get_current_data_ex(list, (void**)&item, &pos) == FAILURE) {
				break;
			}

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
	array_init(ret);
	add_assoc_long(ret, "type", type);
	if (column) {
		add_assoc_zval(ret, "column", column);
	}
	if (identifier_column) {
		add_assoc_stringl(ret, "column", identifier_column->token, identifier_column->token_len, 0);
		efree(identifier_column);
	}
	if (alias) {
		add_assoc_stringl(ret, "alias", alias->token, alias->token_len, 0);
		efree(alias);
	}

	return ret;
}

static zval *phql_ret_assoc_name(zval *qualified_name, phql_parser_token *alias)
{

	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_zval(ret, "qualifiedName", qualified_name);
	if (alias) {
		add_assoc_stringl(ret, "alias", alias->token, alias->token_len, 0);
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
	array_init(ret);
	add_assoc_zval(ret, "type", type);

	if (qualified) {
		add_assoc_zval(ret, "qualified", qualified);
	}

	if (alias) {
		add_assoc_zval(ret, "alias", alias);
	}

	if (conditions) {
		add_assoc_zval(ret, "conditions", conditions);
	}

	return ret;

}

static zval *phql_ret_expr(int type, zval *left, zval *right)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", type);
	if (left) {
		add_assoc_zval(ret, "left", left);
	}
	if (right) {
		add_assoc_zval(ret, "right", right);
	}

	return ret;
}

static zval *phql_ret_func_call(phql_parser_token *name, zval *arguments)
{

	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", PHQL_T_FCALL);
	add_assoc_stringl(ret, "name", name->token, name->token_len, 0);
	efree(name);

	if (arguments) {
		add_assoc_zval(ret, "arguments", arguments);
	}

	return ret;
}


/* #line 414 "parser.c" */
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
#define YYNOCODE 115
#define YYACTIONTYPE unsigned short int
#define phql_TOKENTYPE phql_parser_token*
typedef union {
  phql_TOKENTYPE yy0;
  zval* yy48;
  int yy229;
} YYMINORTYPE;
#define YYSTACKDEPTH 100
#define phql_ARG_SDECL phql_parser_status *status;
#define phql_ARG_PDECL ,phql_parser_status *status
#define phql_ARG_FETCH phql_parser_status *status = yypParser->status
#define phql_ARG_STORE yypParser->status = status
#define YYNSTATE 245
#define YYNRULE 133
#define YYERRORSYMBOL 69
#define YYERRSYMDT yy229
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
 /*    20 */    74,   69,   69,   64,   64,   72,   78,   50,   52,   54,
 /*    30 */    56,   58,   60,   40,   42,   62,   67,   44,   46,   48,
 /*    40 */    36,   34,   38,   32,   29,   74,   69,  190,   64,  149,
 /*    50 */    27,   28,  162,  199,  160,  197,  145,   72,   78,   50,
 /*    60 */    52,   54,   56,   58,   60,   40,   42,   62,   67,   44,
 /*    70 */    46,   48,   36,   34,   38,   32,   29,   74,   69,  245,
 /*    80 */    64,   32,   29,   74,   69,  172,   64,   83,  170,   72,
 /*    90 */    78,   50,   52,   54,   56,   58,   60,   40,   42,   62,
 /*   100 */    67,   44,   46,   48,   36,   34,   38,   32,   29,   74,
 /*   110 */    69,  187,   64,  185,   72,   78,   50,   52,   54,   56,
 /*   120 */    58,   60,   40,   42,   62,   67,   44,   46,   48,   36,
 /*   130 */    34,   38,   32,   29,   74,   69,  246,   64,   62,   67,
 /*   140 */    44,   46,   48,   36,   34,   38,   32,   29,   74,   69,
 /*   150 */    89,   64,   16,   17,   18,   74,   69,  108,   64,   72,
 /*   160 */    78,   50,   52,   54,   56,   58,   60,   40,   42,   62,
 /*   170 */    67,   44,   46,   48,   36,   34,   38,   32,   29,   74,
 /*   180 */    69,  247,   64,   50,   52,   54,   56,   58,   60,   40,
 /*   190 */    42,   62,   67,   44,   46,   48,   36,   34,   38,   32,
 /*   200 */    29,   74,   69,   99,   64,  147,   30,  155,  150,  100,
 /*   210 */   102,  104,  189,  248,   99,   93,  184,   30,  201,  163,
 /*   220 */   100,  102,  104,  228,   97,  242,   93,  249,  163,  106,
 /*   230 */   118,   36,   34,   38,   32,   29,   74,   69,    7,   64,
 /*   240 */   106,   76,   96,  110,  116,  117,   80,   86,  138,  113,
 /*   250 */   111,  112,  114,  115,  110,  116,  117,   80,   86,  210,
 /*   260 */   113,  111,  112,  114,  115,  192,  319,  206,   30,    8,
 /*   270 */   211,  100,  102,  104,  191,  196,  109,  193,  176,   30,
 /*   280 */    75,  174,  100,  102,  104,   92,   97,  182,   93,   65,
 /*   290 */   128,  106,  109,  165,  181,  167,  169,  136,  173,  177,
 /*   300 */   130,   92,  106,  124,  127,  110,  116,  117,   80,   86,
 /*   310 */     9,  113,  111,  112,  114,  115,  110,  116,  117,   80,
 /*   320 */    86,   12,  113,  111,  112,  114,  115,   40,   42,   62,
 /*   330 */    67,   44,   46,   48,   36,   34,   38,   32,   29,   74,
 /*   340 */    69,  120,   64,   44,   46,   48,   36,   34,   38,   32,
 /*   350 */    29,   74,   69,   21,   64,  379,    1,    2,    3,    4,
 /*   360 */     5,    6,  134,  165,  181,  167,  169,  151,  173,  177,
 /*   370 */   143,  188,  153,  154,   26,  231,  238,  234,  148,  109,
 /*   380 */    71,  200,  196,   10,  223,   71,   97,  109,   92,   11,
 /*   390 */   239,  109,   71,  142,   23,  135,   92,  109,  143,  109,
 /*   400 */    92,  316,  109,  124,  133,  126,   92,  119,   92,  109,
 /*   410 */    95,   92,  119,   26,  210,  109,   94,  132,   92,  119,
 /*   420 */   140,  144,  217,  250,   92,  211,   71,   14,   22,  237,
 /*   430 */   109,  109,   31,  210,   25,  180,   13,   33,  178,   92,
 /*   440 */    92,  120,  208,  109,  209,   35,  109,  236,   37,  109,
 /*   450 */   109,   39,   92,   98,  109,   92,   41,   19,   92,   92,
 /*   460 */   207,   43,  109,   92,  195,  109,   45,   47,  109,   49,
 /*   470 */   317,   92,   51,  109,   92,  194,  125,   92,  109,   53,
 /*   480 */    55,   15,   92,  109,  109,   57,  109,   92,   94,  109,
 /*   490 */   318,  203,   92,   92,   20,   92,  109,  109,   92,   59,
 /*   500 */    61,   63,  109,  163,   66,   92,   92,   68,  152,  153,
 /*   510 */   154,   92,   73,  120,   79,   24,  109,  109,  109,   82,
 /*   520 */    88,  109,  204,  212,  109,   92,   92,   92,  321,  109,
 /*   530 */    92,  109,  101,   92,  103,  105,  109,  109,   92,  107,
 /*   540 */    92,   64,  129,  233,  234,   92,   92,   70,   77,  109,
 /*   550 */   137,  109,  109,  146,  159,   81,  109,  219,   92,  109,
 /*   560 */    92,   92,  183,   84,  208,   92,  184,  109,   92,  213,
 /*   570 */   109,  109,  222,  229,   85,  214,   92,  184,  163,   92,
 /*   580 */    92,  244,  218,  226,   87,  184,   90,   91,  121,  163,
 /*   590 */   122,  123,  125,  131,  139,  141,  164,  163,  156,  161,
 /*   600 */   158,  157,  269,  270,  166,  168,  271,  272,  171,  175,
 /*   610 */   273,  274,  179,  275,  276,  277,  186,  198,  280,  221,
 /*   620 */   281,  202,  220,  224,  288,  225,  205,  320,  227,  232,
 /*   630 */   240,  215,  235,  241,  216,  294,  243,  249,  230,
};
static YYCODETYPE yy_lookahead[] = {
 /*     0 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    10 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*    20 */    21,   22,   22,   24,   24,    1,    2,    3,    4,    5,
 /*    30 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*    40 */    16,   17,   18,   19,   20,   21,   22,   26,   24,   28,
 /*    50 */    51,   52,   29,   29,   31,   31,   48,    1,    2,    3,
 /*    60 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*    70 */    14,   15,   16,   17,   18,   19,   20,   21,   22,    0,
 /*    80 */    24,   19,   20,   21,   22,   33,   24,   31,   36,    1,
 /*    90 */     2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   100 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   110 */    22,   29,   24,   31,    1,    2,    3,    4,    5,    6,
 /*   120 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   130 */    17,   18,   19,   20,   21,   22,    0,   24,   11,   12,
 /*   140 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   150 */    62,   24,   57,   58,   59,   21,   22,   44,   24,    1,
 /*   160 */     2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   170 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   180 */    22,    0,   24,    3,    4,    5,    6,    7,    8,    9,
 /*   190 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   200 */    20,   21,   22,   17,   24,   27,   20,   91,   83,   23,
 /*   210 */    24,   25,   87,    0,   17,   29,   91,   20,   40,  103,
 /*   220 */    23,   24,   25,   45,   26,   47,   29,    0,  103,   43,
 /*   230 */    44,   16,   17,   18,   19,   20,   21,   22,   77,   24,
 /*   240 */    43,   24,   44,   57,   58,   59,   60,   61,   53,   63,
 /*   250 */    64,   65,   66,   67,   57,   58,   59,   60,   61,   86,
 /*   260 */    63,   64,   65,   66,   67,   17,    0,   94,   20,   78,
 /*   270 */    97,   23,   24,   25,   85,   86,  103,   29,   33,   20,
 /*   280 */    63,   36,   23,   24,   25,  112,   26,   26,   29,   11,
 /*   290 */    12,   43,  103,   32,   33,   34,   35,   54,   37,   38,
 /*   300 */    22,  112,   43,   30,   44,   57,   58,   59,   60,   61,
 /*   310 */    79,   63,   64,   65,   66,   67,   57,   58,   59,   60,
 /*   320 */    61,   55,   63,   64,   65,   66,   67,    9,   10,   11,
 /*   330 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   340 */    22,   68,   24,   13,   14,   15,   16,   17,   18,   19,
 /*   350 */    20,   21,   22,   49,   24,   70,   71,   72,   73,   74,
 /*   360 */    75,   76,   86,   32,   33,   34,   35,   84,   37,   38,
 /*   370 */    86,   88,   89,   90,   86,  101,  102,  103,   82,  103,
 /*   380 */    86,   85,   86,   80,   99,   86,   26,  103,  112,   81,
 /*   390 */   105,  103,   86,  109,  106,  107,  112,  103,   86,  103,
 /*   400 */   112,    0,  103,   30,   44,  111,  112,  113,  112,  103,
 /*   410 */   111,  112,  113,   86,   86,  103,   43,  111,  112,  113,
 /*   420 */   108,  109,   94,    0,  112,   97,   86,   26,   50,   86,
 /*   430 */   103,  103,   86,   86,  107,   33,  110,   86,   36,  112,
 /*   440 */   112,   68,   26,  103,   97,   86,  103,  104,   86,  103,
 /*   450 */   103,   86,  112,  113,  103,  112,   86,   56,  112,  112,
 /*   460 */    44,   86,  103,  112,   17,  103,   86,   86,  103,   86,
 /*   470 */     0,  112,   86,  103,  112,   30,   29,  112,  103,   86,
 /*   480 */    86,  110,  112,  103,  103,   86,  103,  112,   43,  103,
 /*   490 */     0,   91,  112,  112,  110,  112,  103,  103,  112,   86,
 /*   500 */    86,   86,  103,  103,   86,  112,  112,   86,   88,   89,
 /*   510 */    90,  112,   86,   68,   86,   26,  103,  103,  103,   86,
 /*   520 */    86,  103,   42,   43,  103,  112,  112,  112,    0,  103,
 /*   530 */   112,  103,   86,  112,   86,   86,  103,  103,  112,   86,
 /*   540 */   112,   24,   86,  102,  103,  112,  112,   43,   63,  103,
 /*   550 */    86,  103,  103,   86,   86,   43,  103,   26,  112,  103,
 /*   560 */   112,  112,   87,   29,   26,  112,   91,  103,  112,   95,
 /*   570 */   103,  103,   98,   87,   44,   44,  112,   91,  103,  112,
 /*   580 */   112,   87,   44,   55,   43,   91,   29,   44,   29,  103,
 /*   590 */    30,   29,   29,   43,   50,   26,   29,  103,   92,   29,
 /*   600 */    39,   93,   29,   29,   33,   33,   29,   29,   33,   33,
 /*   610 */    29,   29,   33,   29,   29,   29,   29,   29,    0,   29,
 /*   620 */     0,   41,   98,   77,    0,  100,   43,    0,  110,   26,
 /*   630 */    77,   42,    3,  100,   43,    0,   28,  114,   46,
};
#define YY_SHIFT_USE_DFLT (-2)
static short yy_shift_ofst[] = {
 /*     0 */   178,   79,  136,  181,  213,  227,    8,  195,  243,  304,
 /*    10 */   266,  423,   95,  401,   95,  470,   -2,   -2,   -2,   95,
 /*    20 */   490,  378,  259,  489,  259,   -2,   -1,   -2,   -2,  259,
 /*    30 */   259,  134,  259,  134,  259,   62,  259,   62,  259,   62,
 /*    40 */   259,  127,  259,  127,  259,  215,  259,  215,  259,  215,
 /*    50 */   259,  318,  259,  318,  259,  318,  259,  318,  259,  318,
 /*    60 */   259,  318,  259,  330,  278,  259,  517,  259,  330,  504,
 /*    70 */   197,  158,  259,  158,  217,   -2,  485,   -2,  259,  180,
 /*    80 */   512,  259,   56,  534,  530,   -2,  541,  259,   88,  557,
 /*    90 */   543,   -2,   -2,  373,  186,  198,   -2,  197,   -2,   -2,
 /*   100 */   259,    0,  259,  517,  259,  517,  259,  113,   -2,   -2,
 /*   110 */    -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,
 /*   120 */   559,  560,  562,   -2,  563,   -2,  260,   -2,  259,  517,
 /*   130 */   550,  197,  360,   -2,  134,   -2,  259,  158,  544,  259,
 /*   140 */   569,  259,   -2,  158,   -2,  259,  158,  248,   21,  567,
 /*   150 */   261,  331,   -2,   -2,  567,   23,  561,   -2,  259,  158,
 /*   160 */   570,   -2,   -2,   -2,  273,  571,  573,  572,  574,   52,
 /*   170 */   575,  577,  578,  245,  576,  581,  582,  402,  579,  584,
 /*   180 */   585,  586,  567,   -2,   82,  587,   -2,   -2,   -2,   -2,
 /*   190 */   248,   -2,   -2,  445,  447,   -2,   24,  588,   -2,   -2,
 /*   200 */    -2,  580,  567,  480,  583,  259,  416,  618,  259,   -2,
 /*   210 */   158,   -2,  590,  531,  589,  591,  259,  538,  620,  590,
 /*   220 */    -2,   -2,   -2,    8,  528,  624,   95,  627,  567,  592,
 /*   230 */   567,  603,  567,   -2,  629,  259,   -2,  158,   -2,    8,
 /*   240 */   528,  635,  608,  567,   -2,
};
#define YY_REDUCE_USE_DFLT (-1)
static short yy_reduce_ofst[] = {
 /*     0 */   285,   -1,   -1,   -1,   -1,   -1,  161,  191,  231,  303,
 /*    10 */   308,   -1,  326,   -1,  371,   -1,   -1,   -1,   -1,  384,
 /*    20 */    -1,   -1,  288,   -1,  327,   -1,   -1,   -1,   -1,  276,
 /*    30 */   346,   -1,  351,   -1,  359,   -1,  362,   -1,  365,   -1,
 /*    40 */   370,   -1,  375,   -1,  380,   -1,  381,   -1,  383,   -1,
 /*    50 */   386,   -1,  393,   -1,  394,   -1,  399,   -1,  413,   -1,
 /*    60 */   414,   -1,  415,   -1,   -1,  418,   -1,  421,   -1,   -1,
 /*    70 */   294,   -1,  426,   -1,   -1,   -1,   -1,   -1,  428,   -1,
 /*    80 */    -1,  433,   -1,   -1,   -1,   -1,   -1,  434,   -1,   -1,
 /*    90 */    -1,   -1,   -1,   -1,  299,   -1,   -1,  340,   -1,   -1,
 /*   100 */   446,   -1,  448,   -1,  449,   -1,  453,   -1,   -1,   -1,
 /*   110 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   120 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  456,   -1,
 /*   130 */    -1,  306,   -1,   -1,   -1,   -1,  464,   -1,   -1,  312,
 /*   140 */    -1,  284,   -1,   -1,   -1,  467,   -1,  296,   -1,  125,
 /*   150 */   283,  420,   -1,   -1,  116,  506,  508,   -1,  468,   -1,
 /*   160 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   170 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   180 */    -1,   -1,  475,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   190 */   189,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   200 */    -1,   -1,  400,   -1,   -1,  173,   -1,   -1,  347,   -1,
 /*   210 */    -1,   -1,  474,   -1,   -1,   -1,  328,   -1,   -1,  524,
 /*   220 */    -1,   -1,   -1,  546,  525,   -1,  518,   -1,  486,   -1,
 /*   230 */   274,   -1,  441,   -1,   -1,  343,   -1,   -1,   -1,  553,
 /*   240 */   533,   -1,   -1,  494,   -1,
};
static YYACTIONTYPE yy_default[] = {
 /*     0 */   378,  378,  378,  378,  378,  378,  301,  310,  315,  303,
 /*    10 */   378,  378,  378,  378,  378,  378,  322,  323,  324,  378,
 /*    20 */   378,  378,  378,  302,  378,  304,  306,  307,  308,  378,
 /*    30 */   378,  325,  378,  327,  378,  328,  378,  329,  378,  330,
 /*    40 */   378,  331,  378,  332,  378,  333,  378,  334,  378,  335,
 /*    50 */   378,  336,  378,  337,  378,  338,  378,  339,  378,  340,
 /*    60 */   378,  341,  378,  342,  378,  378,  343,  378,  344,  378,
 /*    70 */   378,  357,  378,  348,  378,  358,  378,  359,  378,  361,
 /*    80 */   378,  378,  378,  378,  378,  349,  378,  378,  378,  378,
 /*    90 */   378,  350,  351,  377,  378,  378,  352,  378,  354,  356,
 /*   100 */   378,  360,  378,  362,  378,  363,  378,  378,  364,  365,
 /*   110 */   366,  367,  368,  369,  370,  371,  372,  373,  353,  355,
 /*   120 */   378,  375,  378,  374,  378,  376,  378,  346,  378,  345,
 /*   130 */   378,  378,  378,  347,  326,  305,  378,  314,  378,  378,
 /*   140 */   309,  378,  311,  313,  312,  378,  300,  378,  378,  378,
 /*   150 */   252,  251,  262,  264,  378,  268,  279,  265,  378,  278,
 /*   160 */   378,  266,  267,  299,  377,  378,  378,  378,  378,  378,
 /*   170 */   378,  378,  378,  378,  378,  378,  378,  378,  378,  378,
 /*   180 */   378,  378,  378,  260,  298,  378,  296,  297,  263,  261,
 /*   190 */   378,  253,  255,  377,  378,  256,  259,  378,  257,  258,
 /*   200 */   254,  378,  378,  378,  378,  378,  378,  378,  378,  282,
 /*   210 */   284,  283,  378,  378,  378,  378,  378,  378,  378,  378,
 /*   220 */   285,  287,  286,  301,  378,  378,  378,  378,  378,  378,
 /*   230 */   378,  289,  378,  290,  378,  378,  292,  293,  291,  301,
 /*   240 */   378,  378,  378,  378,  295,
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
  "MINUS",         "IS",            "IN",            "DISTINCT",    
  "NOT",           "BITWISE_NOT",   "COMMA",         "SELECT",      
  "FROM",          "IDENTIFIER",    "DOT",           "AS",          
  "INNER",         "JOIN",          "CROSS",         "LEFT",        
  "OUTER",         "RIGHT",         "FULL",          "ON",          
  "INSERT",        "INTO",          "VALUES",        "PARENTHESES_OPEN",
  "PARENTHESES_CLOSE",  "UPDATE",        "SET",           "DELETE",      
  "WHERE",         "ORDER",         "BY",            "ASC",         
  "DESC",          "GROUP",         "HAVING",        "LIMIT",       
  "OFFSET",        "INTEGER",       "NPLACEHOLDER",  "SPLACEHOLDER",
  "CAST",          "CONVERT",       "USING",         "NULL",        
  "STRING",        "DOUBLE",        "TRUE",          "FALSE",       
  "COLON",         "error",         "program",       "query_language",
  "select_statement",  "insert_statement",  "update_statement",  "delete_statement",
  "select_clause",  "where_clause",  "group_clause",  "having_clause",
  "order_clause",  "select_limit_clause",  "column_list",   "associated_name_list",
  "join_list",     "column_item",   "expr",          "associated_name",
  "join_item",     "join_clause",   "join_type",     "aliased_or_qualified_name",
  "join_associated_name",  "join_conditions",  "values_list",   "field_list",  
  "value_list",    "value_item",    "field_item",    "update_clause",
  "limit_clause",  "update_item_list",  "update_item",   "qualified_name",
  "new_value",     "delete_clause",  "order_list",    "order_item",  
  "group_list",    "group_item",    "integer_or_placeholder",  "argument_list",
  "function_call",  "argument_item",
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
 /*   6 */ "select_clause ::= SELECT column_list FROM associated_name_list join_list",
 /*   7 */ "select_clause ::= SELECT column_list FROM associated_name_list",
 /*   8 */ "column_list ::= column_list COMMA column_item",
 /*   9 */ "column_list ::= column_item",
 /*  10 */ "column_item ::= TIMES",
 /*  11 */ "column_item ::= IDENTIFIER DOT TIMES",
 /*  12 */ "column_item ::= expr AS IDENTIFIER",
 /*  13 */ "column_item ::= expr IDENTIFIER",
 /*  14 */ "column_item ::= expr",
 /*  15 */ "associated_name_list ::= associated_name_list COMMA associated_name",
 /*  16 */ "associated_name_list ::= associated_name",
 /*  17 */ "join_list ::= join_list join_item",
 /*  18 */ "join_list ::= join_item",
 /*  19 */ "join_item ::= join_clause",
 /*  20 */ "join_clause ::= join_type aliased_or_qualified_name join_associated_name join_conditions",
 /*  21 */ "join_associated_name ::= AS IDENTIFIER",
 /*  22 */ "join_associated_name ::= IDENTIFIER",
 /*  23 */ "join_associated_name ::=",
 /*  24 */ "join_type ::= INNER JOIN",
 /*  25 */ "join_type ::= CROSS JOIN",
 /*  26 */ "join_type ::= LEFT OUTER JOIN",
 /*  27 */ "join_type ::= LEFT JOIN",
 /*  28 */ "join_type ::= RIGHT OUTER JOIN",
 /*  29 */ "join_type ::= RIGHT JOIN",
 /*  30 */ "join_type ::= FULL OUTER JOIN",
 /*  31 */ "join_type ::= FULL JOIN",
 /*  32 */ "join_type ::= JOIN",
 /*  33 */ "join_conditions ::= ON expr",
 /*  34 */ "join_conditions ::=",
 /*  35 */ "insert_statement ::= INSERT INTO aliased_or_qualified_name VALUES PARENTHESES_OPEN values_list PARENTHESES_CLOSE",
 /*  36 */ "insert_statement ::= INSERT INTO aliased_or_qualified_name PARENTHESES_OPEN field_list PARENTHESES_CLOSE VALUES PARENTHESES_OPEN values_list PARENTHESES_CLOSE",
 /*  37 */ "values_list ::= values_list COMMA value_item",
 /*  38 */ "values_list ::= value_item",
 /*  39 */ "value_item ::= expr",
 /*  40 */ "field_list ::= field_list COMMA field_item",
 /*  41 */ "field_list ::= field_item",
 /*  42 */ "field_item ::= IDENTIFIER",
 /*  43 */ "update_statement ::= update_clause where_clause limit_clause",
 /*  44 */ "update_clause ::= UPDATE associated_name SET update_item_list",
 /*  45 */ "update_item_list ::= update_item_list COMMA update_item",
 /*  46 */ "update_item_list ::= update_item",
 /*  47 */ "update_item ::= qualified_name EQUALS new_value",
 /*  48 */ "new_value ::= expr",
 /*  49 */ "delete_statement ::= delete_clause where_clause limit_clause",
 /*  50 */ "delete_clause ::= DELETE FROM associated_name",
 /*  51 */ "associated_name ::= aliased_or_qualified_name AS IDENTIFIER",
 /*  52 */ "associated_name ::= aliased_or_qualified_name IDENTIFIER",
 /*  53 */ "associated_name ::= aliased_or_qualified_name",
 /*  54 */ "aliased_or_qualified_name ::= qualified_name",
 /*  55 */ "where_clause ::= WHERE expr",
 /*  56 */ "where_clause ::=",
 /*  57 */ "order_clause ::= ORDER BY order_list",
 /*  58 */ "order_clause ::=",
 /*  59 */ "order_list ::= order_list COMMA order_item",
 /*  60 */ "order_list ::= order_item",
 /*  61 */ "order_item ::= expr",
 /*  62 */ "order_item ::= expr ASC",
 /*  63 */ "order_item ::= expr DESC",
 /*  64 */ "group_clause ::= GROUP BY group_list",
 /*  65 */ "group_clause ::=",
 /*  66 */ "group_list ::= group_list COMMA group_item",
 /*  67 */ "group_list ::= group_item",
 /*  68 */ "group_item ::= expr",
 /*  69 */ "having_clause ::= HAVING expr",
 /*  70 */ "having_clause ::=",
 /*  71 */ "select_limit_clause ::= LIMIT integer_or_placeholder",
 /*  72 */ "select_limit_clause ::= LIMIT integer_or_placeholder COMMA integer_or_placeholder",
 /*  73 */ "select_limit_clause ::= LIMIT integer_or_placeholder OFFSET integer_or_placeholder",
 /*  74 */ "select_limit_clause ::=",
 /*  75 */ "limit_clause ::= LIMIT integer_or_placeholder",
 /*  76 */ "limit_clause ::=",
 /*  77 */ "integer_or_placeholder ::= INTEGER",
 /*  78 */ "integer_or_placeholder ::= NPLACEHOLDER",
 /*  79 */ "integer_or_placeholder ::= SPLACEHOLDER",
 /*  80 */ "expr ::= MINUS expr",
 /*  81 */ "expr ::= expr MINUS expr",
 /*  82 */ "expr ::= expr PLUS expr",
 /*  83 */ "expr ::= expr TIMES expr",
 /*  84 */ "expr ::= expr DIVIDE expr",
 /*  85 */ "expr ::= expr MOD expr",
 /*  86 */ "expr ::= expr AND expr",
 /*  87 */ "expr ::= expr OR expr",
 /*  88 */ "expr ::= expr BITWISE_AND expr",
 /*  89 */ "expr ::= expr BITWISE_OR expr",
 /*  90 */ "expr ::= expr BITWISE_XOR expr",
 /*  91 */ "expr ::= expr EQUALS expr",
 /*  92 */ "expr ::= expr NOTEQUALS expr",
 /*  93 */ "expr ::= expr LESS expr",
 /*  94 */ "expr ::= expr GREATER expr",
 /*  95 */ "expr ::= expr GREATEREQUAL expr",
 /*  96 */ "expr ::= expr LESSEQUAL expr",
 /*  97 */ "expr ::= expr LIKE expr",
 /*  98 */ "expr ::= expr NOT LIKE expr",
 /*  99 */ "expr ::= expr ILIKE expr",
 /* 100 */ "expr ::= expr NOT ILIKE expr",
 /* 101 */ "expr ::= expr IN PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 102 */ "expr ::= expr NOT IN PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 103 */ "expr ::= expr AGAINST expr",
 /* 104 */ "expr ::= CAST PARENTHESES_OPEN expr AS IDENTIFIER PARENTHESES_CLOSE",
 /* 105 */ "expr ::= CONVERT PARENTHESES_OPEN expr USING IDENTIFIER PARENTHESES_CLOSE",
 /* 106 */ "expr ::= function_call",
 /* 107 */ "function_call ::= IDENTIFIER PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 108 */ "function_call ::= IDENTIFIER PARENTHESES_OPEN PARENTHESES_CLOSE",
 /* 109 */ "argument_list ::= argument_list COMMA argument_item",
 /* 110 */ "argument_list ::= argument_item",
 /* 111 */ "argument_item ::= TIMES",
 /* 112 */ "argument_item ::= expr",
 /* 113 */ "expr ::= expr IS NULL",
 /* 114 */ "expr ::= expr IS NOT NULL",
 /* 115 */ "expr ::= DISTINCT expr",
 /* 116 */ "expr ::= expr BETWEEN expr",
 /* 117 */ "expr ::= NOT expr",
 /* 118 */ "expr ::= BITWISE_NOT expr",
 /* 119 */ "expr ::= PARENTHESES_OPEN expr PARENTHESES_CLOSE",
 /* 120 */ "expr ::= qualified_name",
 /* 121 */ "expr ::= INTEGER",
 /* 122 */ "expr ::= STRING",
 /* 123 */ "expr ::= DOUBLE",
 /* 124 */ "expr ::= NULL",
 /* 125 */ "expr ::= TRUE",
 /* 126 */ "expr ::= FALSE",
 /* 127 */ "expr ::= NPLACEHOLDER",
 /* 128 */ "expr ::= SPLACEHOLDER",
 /* 129 */ "qualified_name ::= IDENTIFIER COLON IDENTIFIER DOT IDENTIFIER",
 /* 130 */ "qualified_name ::= IDENTIFIER COLON IDENTIFIER",
 /* 131 */ "qualified_name ::= IDENTIFIER DOT IDENTIFIER",
 /* 132 */ "qualified_name ::= IDENTIFIER",
};
#endif /* NDEBUG */

/*
** This function returns the symbolic name associated with a token
** value.
*/
const char *phql_TokenName(int tokenType){
#ifndef NDEBUG
  if( tokenType>0 && tokenType<(sizeof(yyTokenName)/sizeof(yyTokenName[0])) ){
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
/* #line 512 "parser.y" */
{
	if ((yypminor->yy0)) {
		if ((yypminor->yy0)->free_flag) {
			efree((yypminor->yy0)->token);
		}
		efree((yypminor->yy0));
	}
}
/* #line 1134 "parser.c" */
      break;
    case 71:
    case 72:
    case 73:
    case 74:
    case 75:
    case 76:
    case 82:
    case 83:
    case 84:
    case 85:
    case 86:
    case 87:
    case 88:
    case 89:
    case 90:
    case 91:
    case 95:
    case 96:
    case 98:
    case 99:
    case 101:
    case 102:
    case 103:
    case 105:
    case 106:
    case 107:
    case 108:
    case 109:
    case 111:
    case 112:
    case 113:
/* #line 525 "parser.y" */
{ zval_ptr_dtor(&(yypminor->yy48)); }
/* #line 1169 "parser.c" */
      break;
    case 77:
    case 78:
    case 79:
    case 80:
    case 81:
    case 92:
    case 93:
    case 100:
/* #line 795 "parser.y" */
{ phalcon_safe_zval_ptr_dtor((yypminor->yy48)); }
/* #line 1181 "parser.c" */
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
  if( i<0 || i>=YY_SZ_ACTTAB || yy_lookahead[i]!=iLookAhead ){
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
  if( i<0 || i>=YY_SZ_ACTTAB || yy_lookahead[i]!=iLookAhead ){
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
  { 70, 1 },
  { 71, 1 },
  { 71, 1 },
  { 71, 1 },
  { 71, 1 },
  { 72, 6 },
  { 76, 5 },
  { 76, 4 },
  { 82, 3 },
  { 82, 1 },
  { 85, 1 },
  { 85, 3 },
  { 85, 3 },
  { 85, 2 },
  { 85, 1 },
  { 83, 3 },
  { 83, 1 },
  { 84, 2 },
  { 84, 1 },
  { 88, 1 },
  { 89, 4 },
  { 92, 2 },
  { 92, 1 },
  { 92, 0 },
  { 90, 2 },
  { 90, 2 },
  { 90, 3 },
  { 90, 2 },
  { 90, 3 },
  { 90, 2 },
  { 90, 3 },
  { 90, 2 },
  { 90, 1 },
  { 93, 2 },
  { 93, 0 },
  { 73, 7 },
  { 73, 10 },
  { 94, 3 },
  { 94, 1 },
  { 97, 1 },
  { 95, 3 },
  { 95, 1 },
  { 98, 1 },
  { 74, 3 },
  { 99, 4 },
  { 101, 3 },
  { 101, 1 },
  { 102, 3 },
  { 104, 1 },
  { 75, 3 },
  { 105, 3 },
  { 87, 3 },
  { 87, 2 },
  { 87, 1 },
  { 91, 1 },
  { 77, 2 },
  { 77, 0 },
  { 80, 3 },
  { 80, 0 },
  { 106, 3 },
  { 106, 1 },
  { 107, 1 },
  { 107, 2 },
  { 107, 2 },
  { 78, 3 },
  { 78, 0 },
  { 108, 3 },
  { 108, 1 },
  { 109, 1 },
  { 79, 2 },
  { 79, 0 },
  { 81, 2 },
  { 81, 4 },
  { 81, 4 },
  { 81, 0 },
  { 100, 2 },
  { 100, 0 },
  { 110, 1 },
  { 110, 1 },
  { 110, 1 },
  { 86, 2 },
  { 86, 3 },
  { 86, 3 },
  { 86, 3 },
  { 86, 3 },
  { 86, 3 },
  { 86, 3 },
  { 86, 3 },
  { 86, 3 },
  { 86, 3 },
  { 86, 3 },
  { 86, 3 },
  { 86, 3 },
  { 86, 3 },
  { 86, 3 },
  { 86, 3 },
  { 86, 3 },
  { 86, 3 },
  { 86, 4 },
  { 86, 3 },
  { 86, 4 },
  { 86, 5 },
  { 86, 6 },
  { 86, 3 },
  { 86, 6 },
  { 86, 6 },
  { 86, 1 },
  { 112, 4 },
  { 112, 3 },
  { 111, 3 },
  { 111, 1 },
  { 113, 1 },
  { 113, 1 },
  { 86, 3 },
  { 86, 4 },
  { 86, 2 },
  { 86, 3 },
  { 86, 2 },
  { 86, 2 },
  { 86, 3 },
  { 86, 1 },
  { 86, 1 },
  { 86, 1 },
  { 86, 1 },
  { 86, 1 },
  { 86, 1 },
  { 86, 1 },
  { 86, 1 },
  { 86, 1 },
  { 103, 5 },
  { 103, 3 },
  { 103, 3 },
  { 103, 1 },
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
        && yyruleno<sizeof(yyRuleName)/sizeof(yyRuleName[0]) ){
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
/* #line 521 "parser.y" */
{
	status->ret = yymsp[0].minor.yy48;
}
/* #line 1531 "parser.c" */
        break;
      case 1:
      case 2:
      case 3:
      case 4:
      case 9:
      case 16:
      case 18:
      case 19:
      case 38:
      case 39:
      case 41:
      case 46:
      case 48:
      case 54:
      case 60:
      case 67:
      case 68:
      case 106:
      case 112:
      case 120:
/* #line 527 "parser.y" */
{
	yygotominor.yy48 = yymsp[0].minor.yy48;
}
/* #line 1557 "parser.c" */
        break;
      case 5:
/* #line 545 "parser.y" */
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-5].minor.yy48, yymsp[-4].minor.yy48, yymsp[-1].minor.yy48, yymsp[-3].minor.yy48, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
}
/* #line 1564 "parser.c" */
        break;
      case 6:
/* #line 551 "parser.y" */
{
	yygotominor.yy48 = phql_ret_select_clause(yymsp[-3].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(27,&yymsp[-4].minor);
  yy_destructor(28,&yymsp[-2].minor);
}
/* #line 1573 "parser.c" */
        break;
      case 7:
/* #line 555 "parser.y" */
{
	yygotominor.yy48 = phql_ret_select_clause(yymsp[-2].minor.yy48, yymsp[0].minor.yy48, NULL);
  yy_destructor(27,&yymsp[-3].minor);
  yy_destructor(28,&yymsp[-1].minor);
}
/* #line 1582 "parser.c" */
        break;
      case 8:
      case 15:
      case 37:
      case 40:
      case 45:
      case 59:
      case 66:
      case 109:
/* #line 561 "parser.y" */
{
	yygotominor.yy48 = phql_ret_zval_list(yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(26,&yymsp[-1].minor);
}
/* #line 1597 "parser.c" */
        break;
      case 10:
      case 111:
/* #line 571 "parser.y" */
{
	yygotominor.yy48 = phql_ret_column_item(PHQL_T_ALL, NULL, NULL, NULL);
  yy_destructor(17,&yymsp[0].minor);
}
/* #line 1606 "parser.c" */
        break;
      case 11:
/* #line 575 "parser.y" */
{
	yygotominor.yy48 = phql_ret_column_item(PHQL_T_DOMAINALL, NULL, yymsp[-2].minor.yy0, NULL);
  yy_destructor(30,&yymsp[-1].minor);
  yy_destructor(17,&yymsp[0].minor);
}
/* #line 1615 "parser.c" */
        break;
      case 12:
/* #line 579 "parser.y" */
{
	yygotominor.yy48 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-2].minor.yy48, NULL, yymsp[0].minor.yy0);
  yy_destructor(31,&yymsp[-1].minor);
}
/* #line 1623 "parser.c" */
        break;
      case 13:
/* #line 583 "parser.y" */
{
	yygotominor.yy48 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy0);
}
/* #line 1630 "parser.c" */
        break;
      case 14:
/* #line 587 "parser.y" */
{
	yygotominor.yy48 = phql_ret_column_item(PHQL_T_EXPR, yymsp[0].minor.yy48, NULL, NULL);
}
/* #line 1637 "parser.c" */
        break;
      case 17:
/* #line 603 "parser.y" */
{
	yygotominor.yy48 = phql_ret_zval_list(yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
}
/* #line 1644 "parser.c" */
        break;
      case 20:
/* #line 620 "parser.y" */
{
	yygotominor.yy48 = phql_ret_join_item(yymsp[-3].minor.yy48, yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
}
/* #line 1651 "parser.c" */
        break;
      case 21:
/* #line 626 "parser.y" */
{
	yygotominor.yy48 = phql_ret_qualified_name(NULL, NULL, yymsp[0].minor.yy0);
  yy_destructor(31,&yymsp[-1].minor);
}
/* #line 1659 "parser.c" */
        break;
      case 22:
      case 42:
      case 132:
/* #line 630 "parser.y" */
{
	yygotominor.yy48 = phql_ret_qualified_name(NULL, NULL, yymsp[0].minor.yy0);
}
/* #line 1668 "parser.c" */
        break;
      case 23:
      case 34:
      case 56:
      case 58:
      case 65:
      case 70:
      case 74:
      case 76:
/* #line 634 "parser.y" */
{
	yygotominor.yy48 = NULL;
}
/* #line 1682 "parser.c" */
        break;
      case 24:
/* #line 640 "parser.y" */
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_INNERJOIN);
  yy_destructor(32,&yymsp[-1].minor);
  yy_destructor(33,&yymsp[0].minor);
}
/* #line 1691 "parser.c" */
        break;
      case 25:
/* #line 644 "parser.y" */
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_CROSSJOIN);
  yy_destructor(34,&yymsp[-1].minor);
  yy_destructor(33,&yymsp[0].minor);
}
/* #line 1700 "parser.c" */
        break;
      case 26:
/* #line 648 "parser.y" */
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[-1].minor);
  yy_destructor(33,&yymsp[0].minor);
}
/* #line 1710 "parser.c" */
        break;
      case 27:
/* #line 652 "parser.y" */
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  yy_destructor(35,&yymsp[-1].minor);
  yy_destructor(33,&yymsp[0].minor);
}
/* #line 1719 "parser.c" */
        break;
      case 28:
/* #line 656 "parser.y" */
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  yy_destructor(37,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[-1].minor);
  yy_destructor(33,&yymsp[0].minor);
}
/* #line 1729 "parser.c" */
        break;
      case 29:
/* #line 660 "parser.y" */
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  yy_destructor(37,&yymsp[-1].minor);
  yy_destructor(33,&yymsp[0].minor);
}
/* #line 1738 "parser.c" */
        break;
      case 30:
/* #line 664 "parser.y" */
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_FULLJOIN);
  yy_destructor(38,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[-1].minor);
  yy_destructor(33,&yymsp[0].minor);
}
/* #line 1748 "parser.c" */
        break;
      case 31:
/* #line 668 "parser.y" */
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_FULLJOIN);
  yy_destructor(38,&yymsp[-1].minor);
  yy_destructor(33,&yymsp[0].minor);
}
/* #line 1757 "parser.c" */
        break;
      case 32:
/* #line 672 "parser.y" */
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_INNERJOIN);
  yy_destructor(33,&yymsp[0].minor);
}
/* #line 1765 "parser.c" */
        break;
      case 33:
/* #line 678 "parser.y" */
{
	yygotominor.yy48 = yymsp[0].minor.yy48;
  yy_destructor(39,&yymsp[-1].minor);
}
/* #line 1773 "parser.c" */
        break;
      case 35:
/* #line 689 "parser.y" */
{
	yygotominor.yy48 = phql_ret_insert_statement(yymsp[-4].minor.yy48, NULL, yymsp[-1].minor.yy48);
  yy_destructor(40,&yymsp[-6].minor);
  yy_destructor(41,&yymsp[-5].minor);
  yy_destructor(42,&yymsp[-3].minor);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
/* #line 1785 "parser.c" */
        break;
      case 36:
/* #line 693 "parser.y" */
{
	yygotominor.yy48 = phql_ret_insert_statement(yymsp[-7].minor.yy48, yymsp[-5].minor.yy48, yymsp[-1].minor.yy48);
  yy_destructor(40,&yymsp[-9].minor);
  yy_destructor(41,&yymsp[-8].minor);
  yy_destructor(43,&yymsp[-6].minor);
  yy_destructor(44,&yymsp[-4].minor);
  yy_destructor(42,&yymsp[-3].minor);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
/* #line 1799 "parser.c" */
        break;
      case 43:
/* #line 731 "parser.y" */
{
	yygotominor.yy48 = phql_ret_update_statement(yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
}
/* #line 1806 "parser.c" */
        break;
      case 44:
/* #line 737 "parser.y" */
{
	yygotominor.yy48 = phql_ret_update_clause(yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(45,&yymsp[-3].minor);
  yy_destructor(46,&yymsp[-1].minor);
}
/* #line 1815 "parser.c" */
        break;
      case 47:
/* #line 753 "parser.y" */
{
	yygotominor.yy48 = phql_ret_update_item(yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(3,&yymsp[-1].minor);
}
/* #line 1823 "parser.c" */
        break;
      case 49:
/* #line 765 "parser.y" */
{
	yygotominor.yy48 = phql_ret_delete_statement(yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
}
/* #line 1830 "parser.c" */
        break;
      case 50:
/* #line 771 "parser.y" */
{
	yygotominor.yy48 = phql_ret_delete_clause(yymsp[0].minor.yy48);
  yy_destructor(47,&yymsp[-2].minor);
  yy_destructor(28,&yymsp[-1].minor);
}
/* #line 1839 "parser.c" */
        break;
      case 51:
/* #line 777 "parser.y" */
{
	yygotominor.yy48 = phql_ret_assoc_name(yymsp[-2].minor.yy48, yymsp[0].minor.yy0);
  yy_destructor(31,&yymsp[-1].minor);
}
/* #line 1847 "parser.c" */
        break;
      case 52:
/* #line 781 "parser.y" */
{
	yygotominor.yy48 = phql_ret_assoc_name(yymsp[-1].minor.yy48, yymsp[0].minor.yy0);
}
/* #line 1854 "parser.c" */
        break;
      case 53:
/* #line 785 "parser.y" */
{
	yygotominor.yy48 = phql_ret_assoc_name(yymsp[0].minor.yy48, NULL);
}
/* #line 1861 "parser.c" */
        break;
      case 55:
/* #line 797 "parser.y" */
{
	yygotominor.yy48 = yymsp[0].minor.yy48;
  yy_destructor(48,&yymsp[-1].minor);
}
/* #line 1869 "parser.c" */
        break;
      case 57:
/* #line 807 "parser.y" */
{
	yygotominor.yy48 = yymsp[0].minor.yy48;
  yy_destructor(49,&yymsp[-2].minor);
  yy_destructor(50,&yymsp[-1].minor);
}
/* #line 1878 "parser.c" */
        break;
      case 61:
/* #line 827 "parser.y" */
{
	yygotominor.yy48 = phql_ret_order_item(yymsp[0].minor.yy48, 0);
}
/* #line 1885 "parser.c" */
        break;
      case 62:
/* #line 831 "parser.y" */
{
	yygotominor.yy48 = phql_ret_order_item(yymsp[-1].minor.yy48, PHQL_T_ASC);
  yy_destructor(51,&yymsp[0].minor);
}
/* #line 1893 "parser.c" */
        break;
      case 63:
/* #line 835 "parser.y" */
{
	yygotominor.yy48 = phql_ret_order_item(yymsp[-1].minor.yy48, PHQL_T_DESC);
  yy_destructor(52,&yymsp[0].minor);
}
/* #line 1901 "parser.c" */
        break;
      case 64:
/* #line 841 "parser.y" */
{
	yygotominor.yy48 = yymsp[0].minor.yy48;
  yy_destructor(53,&yymsp[-2].minor);
  yy_destructor(50,&yymsp[-1].minor);
}
/* #line 1910 "parser.c" */
        break;
      case 69:
/* #line 867 "parser.y" */
{
	yygotominor.yy48 = yymsp[0].minor.yy48;
  yy_destructor(54,&yymsp[-1].minor);
}
/* #line 1918 "parser.c" */
        break;
      case 71:
      case 75:
/* #line 877 "parser.y" */
{
	yygotominor.yy48 = phql_ret_limit_clause(yymsp[0].minor.yy48, NULL);
  yy_destructor(55,&yymsp[-1].minor);
}
/* #line 1927 "parser.c" */
        break;
      case 72:
/* #line 881 "parser.y" */
{
	yygotominor.yy48 = phql_ret_limit_clause(yymsp[0].minor.yy48, yymsp[-2].minor.yy48);
  yy_destructor(55,&yymsp[-3].minor);
  yy_destructor(26,&yymsp[-1].minor);
}
/* #line 1936 "parser.c" */
        break;
      case 73:
/* #line 885 "parser.y" */
{
	yygotominor.yy48 = phql_ret_limit_clause(yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(55,&yymsp[-3].minor);
  yy_destructor(56,&yymsp[-1].minor);
}
/* #line 1945 "parser.c" */
        break;
      case 77:
      case 121:
/* #line 903 "parser.y" */
{
	yygotominor.yy48 = phql_ret_literal_zval(PHQL_T_INTEGER, yymsp[0].minor.yy0);
}
/* #line 1953 "parser.c" */
        break;
      case 78:
      case 127:
/* #line 907 "parser.y" */
{
	yygotominor.yy48 = phql_ret_placeholder_zval(PHQL_T_NPLACEHOLDER, yymsp[0].minor.yy0);
}
/* #line 1961 "parser.c" */
        break;
      case 79:
      case 128:
/* #line 911 "parser.y" */
{
	yygotominor.yy48 = phql_ret_placeholder_zval(PHQL_T_SPLACEHOLDER, yymsp[0].minor.yy0);
}
/* #line 1969 "parser.c" */
        break;
      case 80:
/* #line 917 "parser.y" */
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_MINUS, NULL, yymsp[0].minor.yy48);
  yy_destructor(20,&yymsp[-1].minor);
}
/* #line 1977 "parser.c" */
        break;
      case 81:
/* #line 921 "parser.y" */
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_SUB, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(20,&yymsp[-1].minor);
}
/* #line 1985 "parser.c" */
        break;
      case 82:
/* #line 925 "parser.y" */
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_ADD, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(19,&yymsp[-1].minor);
}
/* #line 1993 "parser.c" */
        break;
      case 83:
/* #line 929 "parser.y" */
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_MUL, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(17,&yymsp[-1].minor);
}
/* #line 2001 "parser.c" */
        break;
      case 84:
/* #line 933 "parser.y" */
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_DIV, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(16,&yymsp[-1].minor);
}
/* #line 2009 "parser.c" */
        break;
      case 85:
/* #line 937 "parser.y" */
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_MOD, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(18,&yymsp[-1].minor);
}
/* #line 2017 "parser.c" */
        break;
      case 86:
/* #line 941 "parser.y" */
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_AND, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(9,&yymsp[-1].minor);
}
/* #line 2025 "parser.c" */
        break;
      case 87:
/* #line 945 "parser.y" */
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_OR, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(10,&yymsp[-1].minor);
}
/* #line 2033 "parser.c" */
        break;
      case 88:
/* #line 949 "parser.y" */
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_BITWISE_AND, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(13,&yymsp[-1].minor);
}
/* #line 2041 "parser.c" */
        break;
      case 89:
/* #line 953 "parser.y" */
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_BITWISE_OR, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(14,&yymsp[-1].minor);
}
/* #line 2049 "parser.c" */
        break;
      case 90:
/* #line 957 "parser.y" */
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_BITWISE_XOR, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(15,&yymsp[-1].minor);
}
/* #line 2057 "parser.c" */
        break;
      case 91:
/* #line 961 "parser.y" */
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_EQUALS, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(3,&yymsp[-1].minor);
}
/* #line 2065 "parser.c" */
        break;
      case 92:
/* #line 965 "parser.y" */
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_NOTEQUALS, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(4,&yymsp[-1].minor);
}
/* #line 2073 "parser.c" */
        break;
      case 93:
/* #line 969 "parser.y" */
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_LESS, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(5,&yymsp[-1].minor);
}
/* #line 2081 "parser.c" */
        break;
      case 94:
/* #line 973 "parser.y" */
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_GREATER, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(6,&yymsp[-1].minor);
}
/* #line 2089 "parser.c" */
        break;
      case 95:
/* #line 977 "parser.y" */
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_GREATEREQUAL, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(7,&yymsp[-1].minor);
}
/* #line 2097 "parser.c" */
        break;
      case 96:
/* #line 981 "parser.y" */
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_LESSEQUAL, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(8,&yymsp[-1].minor);
}
/* #line 2105 "parser.c" */
        break;
      case 97:
/* #line 985 "parser.y" */
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_LIKE, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(11,&yymsp[-1].minor);
}
/* #line 2113 "parser.c" */
        break;
      case 98:
/* #line 989 "parser.y" */
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_NLIKE, yymsp[-3].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(24,&yymsp[-2].minor);
  yy_destructor(11,&yymsp[-1].minor);
}
/* #line 2122 "parser.c" */
        break;
      case 99:
/* #line 993 "parser.y" */
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_ILIKE, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(12,&yymsp[-1].minor);
}
/* #line 2130 "parser.c" */
        break;
      case 100:
/* #line 997 "parser.y" */
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_NILIKE, yymsp[-3].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(24,&yymsp[-2].minor);
  yy_destructor(12,&yymsp[-1].minor);
}
/* #line 2139 "parser.c" */
        break;
      case 101:
/* #line 1001 "parser.y" */
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_IN, yymsp[-4].minor.yy48, yymsp[-1].minor.yy48);
  yy_destructor(22,&yymsp[-3].minor);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
/* #line 2149 "parser.c" */
        break;
      case 102:
/* #line 1005 "parser.y" */
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_NOTIN, yymsp[-5].minor.yy48, yymsp[-1].minor.yy48);
  yy_destructor(24,&yymsp[-4].minor);
  yy_destructor(22,&yymsp[-3].minor);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
/* #line 2160 "parser.c" */
        break;
      case 103:
/* #line 1009 "parser.y" */
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_AGAINST, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(1,&yymsp[-1].minor);
}
/* #line 2168 "parser.c" */
        break;
      case 104:
/* #line 1013 "parser.y" */
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_CAST, yymsp[-3].minor.yy48, phql_ret_raw_qualified_name(yymsp[-1].minor.yy0, NULL));
  yy_destructor(60,&yymsp[-5].minor);
  yy_destructor(43,&yymsp[-4].minor);
  yy_destructor(31,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
/* #line 2179 "parser.c" */
        break;
      case 105:
/* #line 1017 "parser.y" */
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_CONVERT, yymsp[-3].minor.yy48, phql_ret_raw_qualified_name(yymsp[-1].minor.yy0, NULL));
  yy_destructor(61,&yymsp[-5].minor);
  yy_destructor(43,&yymsp[-4].minor);
  yy_destructor(62,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
/* #line 2190 "parser.c" */
        break;
      case 107:
/* #line 1027 "parser.y" */
{
	yygotominor.yy48 = phql_ret_func_call(yymsp[-3].minor.yy0, yymsp[-1].minor.yy48);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
/* #line 2199 "parser.c" */
        break;
      case 108:
/* #line 1031 "parser.y" */
{
	yygotominor.yy48 = phql_ret_func_call(yymsp[-2].minor.yy0, NULL);
  yy_destructor(43,&yymsp[-1].minor);
  yy_destructor(44,&yymsp[0].minor);
}
/* #line 2208 "parser.c" */
        break;
      case 110:
/* #line 1041 "parser.y" */
{
	yygotominor.yy48 = phql_ret_zval_list(yymsp[0].minor.yy48, NULL);
}
/* #line 2215 "parser.c" */
        break;
      case 113:
/* #line 1055 "parser.y" */
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_ISNULL, yymsp[-2].minor.yy48, NULL);
  yy_destructor(21,&yymsp[-1].minor);
  yy_destructor(63,&yymsp[0].minor);
}
/* #line 2224 "parser.c" */
        break;
      case 114:
/* #line 1059 "parser.y" */
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_ISNOTNULL, yymsp[-3].minor.yy48, NULL);
  yy_destructor(21,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
  yy_destructor(63,&yymsp[0].minor);
}
/* #line 2234 "parser.c" */
        break;
      case 115:
/* #line 1063 "parser.y" */
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_DISTINCT, NULL, yymsp[0].minor.yy48);
  yy_destructor(23,&yymsp[-1].minor);
}
/* #line 2242 "parser.c" */
        break;
      case 116:
/* #line 1067 "parser.y" */
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_BETWEEN, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(2,&yymsp[-1].minor);
}
/* #line 2250 "parser.c" */
        break;
      case 117:
/* #line 1071 "parser.y" */
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_NOT, NULL, yymsp[0].minor.yy48);
  yy_destructor(24,&yymsp[-1].minor);
}
/* #line 2258 "parser.c" */
        break;
      case 118:
/* #line 1075 "parser.y" */
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_BITWISE_NOT, NULL, yymsp[0].minor.yy48);
  yy_destructor(25,&yymsp[-1].minor);
}
/* #line 2266 "parser.c" */
        break;
      case 119:
/* #line 1079 "parser.y" */
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_ENCLOSED, yymsp[-1].minor.yy48, NULL);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
/* #line 2275 "parser.c" */
        break;
      case 122:
/* #line 1091 "parser.y" */
{
	yygotominor.yy48 = phql_ret_literal_zval(PHQL_T_STRING, yymsp[0].minor.yy0);
}
/* #line 2282 "parser.c" */
        break;
      case 123:
/* #line 1095 "parser.y" */
{
	yygotominor.yy48 = phql_ret_literal_zval(PHQL_T_DOUBLE, yymsp[0].minor.yy0);
}
/* #line 2289 "parser.c" */
        break;
      case 124:
/* #line 1099 "parser.y" */
{
	yygotominor.yy48 = phql_ret_literal_zval(PHQL_T_NULL, NULL);
  yy_destructor(63,&yymsp[0].minor);
}
/* #line 2297 "parser.c" */
        break;
      case 125:
/* #line 1103 "parser.y" */
{
	yygotominor.yy48 = phql_ret_literal_zval(PHQL_T_TRUE, NULL);
  yy_destructor(66,&yymsp[0].minor);
}
/* #line 2305 "parser.c" */
        break;
      case 126:
/* #line 1107 "parser.y" */
{
	yygotominor.yy48 = phql_ret_literal_zval(PHQL_T_FALSE, NULL);
  yy_destructor(67,&yymsp[0].minor);
}
/* #line 2313 "parser.c" */
        break;
      case 129:
/* #line 1121 "parser.y" */
{
	yygotominor.yy48 = phql_ret_qualified_name(yymsp[-4].minor.yy0, yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(68,&yymsp[-3].minor);
  yy_destructor(30,&yymsp[-1].minor);
}
/* #line 2322 "parser.c" */
        break;
      case 130:
/* #line 1125 "parser.y" */
{
	yygotominor.yy48 = phql_ret_qualified_name(yymsp[-2].minor.yy0, NULL, yymsp[0].minor.yy0);
  yy_destructor(68,&yymsp[-1].minor);
}
/* #line 2330 "parser.c" */
        break;
      case 131:
/* #line 1129 "parser.y" */
{
	yygotominor.yy48 = phql_ret_qualified_name(NULL, yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(30,&yymsp[-1].minor);
}
/* #line 2338 "parser.c" */
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
/* #line 445 "parser.y" */

	if (status->scanner_state->start_length) {
		{

			char *token_name = NULL;
			int token_found = 0;
			unsigned int token_length;
			const phql_token_names *tokens = phql_tokens;
			int active_token = status->scanner_state->active_token;
			int near_length = status->scanner_state->start_length;

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

/* #line 2447 "parser.c" */
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

	PHALCON_INIT_VAR(*error_msg);
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
		PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, Z_STRVAL_P(error_msg));
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
		PHALCON_INIT_VAR(*error_msg);
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
					PHALCON_INIT_VAR(*error_msg);
					ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements", 1);
					parser_status->status = PHQL_PARSING_FAILED;
				}
				break;
			case PHQL_T_DOUBLE:
				if (parser_status->enable_literals) {
					phql_parse_with_token(phql_parser, PHQL_T_DOUBLE, PHQL_DOUBLE, &token, parser_status);
				} else {
					PHALCON_INIT_VAR(*error_msg);
					ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements", 1);
					parser_status->status = PHQL_PARSING_FAILED;
				}
				break;
			case PHQL_T_STRING:
				if (parser_status->enable_literals) {
					phql_parse_with_token(phql_parser, PHQL_T_STRING, PHQL_STRING, &token, parser_status);
				} else {
					PHALCON_INIT_VAR(*error_msg);
					ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements", 1);
					parser_status->status = PHQL_PARSING_FAILED;
				}
				break;
			case PHQL_T_TRUE:
				if (parser_status->enable_literals) {
					phql_(phql_parser, PHQL_TRUE, NULL, parser_status);
				} else {
					PHALCON_INIT_VAR(*error_msg);
					ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements", 1);
					parser_status->status = PHQL_PARSING_FAILED;
				}
				break;
			case PHQL_T_FALSE:
				if (parser_status->enable_literals) {
					phql_(phql_parser, PHQL_FALSE, NULL, parser_status);
				} else {
					PHALCON_INIT_VAR(*error_msg);
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
				PHALCON_INIT_VAR(*error_msg);
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
				PHALCON_INIT_VAR(*error_msg);
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
