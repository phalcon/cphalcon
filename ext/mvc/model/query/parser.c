/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is include which follows the "include" declaration
** in the input file. */
#include <stdio.h>
// 38 "parser.lemon"


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


// 414 "parser.c"
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
#define YYNSTATE 266
#define YYNRULE 157
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
 /*     0 */    75,   81,   53,   55,   57,   59,   61,   63,   43,   45,
 /*    10 */    65,   70,   47,   49,   51,   39,   37,   41,   35,   32,
 /*    20 */    77,   72,   72,   67,   67,   75,   81,   53,   55,   57,
 /*    30 */    59,   61,   63,   43,   45,   65,   70,   47,   49,   51,
 /*    40 */    39,   37,   41,   35,   32,   77,   72,  266,   67,   21,
 /*    50 */    30,   31,   23,  218,  206,  216,  204,   75,   81,   53,
 /*    60 */    55,   57,   59,   61,   63,   43,   45,   65,   70,   47,
 /*    70 */    49,   51,   39,   37,   41,   35,   32,   77,   72,  267,
 /*    80 */    67,   35,   32,   77,   72,  158,   67,   86,  160,   75,
 /*    90 */    81,   53,   55,   57,   59,   61,   63,   43,   45,   65,
 /*   100 */    70,   47,   49,   51,   39,   37,   41,   35,   32,   77,
 /*   110 */    72,  268,   67,  243,   75,   81,   53,   55,   57,   59,
 /*   120 */    61,   63,   43,   45,   65,   70,   47,   49,   51,   39,
 /*   130 */    37,   41,   35,   32,   77,   72,  247,   67,   65,   70,
 /*   140 */    47,   49,   51,   39,   37,   41,   35,   32,   77,   72,
 /*   150 */    92,   67,    7,  152,  154,  232,  162,  111,  241,   75,
 /*   160 */    81,   53,   55,   57,   59,   61,   63,   43,   45,   65,
 /*   170 */    70,   47,   49,   51,   39,   37,   41,   35,   32,   77,
 /*   180 */    72,  269,   67,   53,   55,   57,   59,   61,   63,   43,
 /*   190 */    45,   65,   70,   47,   49,   51,   39,   37,   41,   35,
 /*   200 */    32,   77,   72,  102,   67,  270,   33,    9,  168,  103,
 /*   210 */   105,  107,  208,  363,  102,   96,  203,   33,  280,  169,
 /*   220 */   103,  105,  107,  207,  171,  172,   96,   11,  182,  109,
 /*   230 */   121,   39,   37,   41,   35,   32,   77,   72,   13,   67,
 /*   240 */   109,   12,  364,  113,  119,  120,   83,   89,   18,  116,
 /*   250 */   114,  115,  117,  118,  113,  119,  120,   83,   89,  229,
 /*   260 */   116,  114,  115,  117,  118,  211,  273,  225,   33,   17,
 /*   270 */   230,  103,  105,  107,  210,  215,  112,  212,  139,   33,
 /*   280 */    20,  141,  103,  105,  107,   95,   68,  131,   96,  201,
 /*   290 */   365,  109,  112,  184,  185,  187,  189,  133,  193,  197,
 /*   300 */    22,   95,  109,  167,  209,  113,  119,  120,   83,   89,
 /*   310 */   288,  116,  114,  115,  117,  118,  113,  119,  120,   83,
 /*   320 */    89,   10,  116,  114,  115,  117,  118,   43,   45,   65,
 /*   330 */    70,   47,   49,   51,   39,   37,   41,   35,   32,   77,
 /*   340 */    72,   25,   67,   47,   49,   51,   39,   37,   41,   35,
 /*   350 */    32,   77,   72,  271,   67,  424,    1,    2,    3,    4,
 /*   360 */     5,    6,  165,  184,  185,  187,  189,  282,  193,  197,
 /*   370 */    29,    8,   19,  100,  144,  181,  220,  179,   29,  274,
 /*   380 */   275,  248,   73,  263,  242,  176,   74,  112,   27,   99,
 /*   390 */   259,   28,   74,  190,  100,  112,   95,  191,   26,  138,
 /*   400 */    79,  163,   24,  112,   95,   74,  145,  272,   10,  112,
 /*   410 */   130,  129,   95,  122,  289,  174,  178,   98,   95,  122,
 /*   420 */   150,   84,  112,  166,  150,   67,  219,  215,   24,   24,
 /*   430 */   135,   95,  122,  142,   10,   10,   88,  112,   74,   78,
 /*   440 */   229,  112,  147,  151,  112,  202,   95,  149,  236,  203,
 /*   450 */    95,  230,   80,   95,   87,  112,   24,  112,  137,   34,
 /*   460 */   145,  182,   10,   24,   95,  101,   95,   93,  142,   10,
 /*   470 */   229,  257,   14,   15,   16,  112,  112,   77,   72,  100,
 /*   480 */    67,  228,   36,   38,   95,   95,   40,  112,  112,  256,
 /*   490 */    42,  170,  171,  172,   44,  136,   95,   95,   46,  112,
 /*   500 */   112,  127,   90,  112,   48,   50,   52,  112,   95,   95,
 /*   510 */    54,  112,   95,   94,   97,  112,   95,   56,   58,  125,
 /*   520 */    95,  112,  112,  112,   95,   60,  173,  112,   62,   64,
 /*   530 */    95,   95,   95,   66,  112,  112,   95,  124,  182,  123,
 /*   540 */    69,  291,  112,   95,   95,  112,  112,   71,  134,  213,
 /*   550 */   112,   95,   76,   82,   95,   95,  278,  112,   85,   95,
 /*   560 */    91,  276,   97,  104,  112,  106,   95,  333,  108,  112,
 /*   570 */   112,  110,  127,   95,  126,  112,  132,  112,   95,   95,
 /*   580 */   112,  143,  112,  164,   95,  112,   95,  123,  112,   95,
 /*   590 */    24,   95,  342,  112,   95,  177,   10,   95,  112,  283,
 /*   600 */   112,  155,   95,  157,  161,  284,  285,   95,  334,   95,
 /*   610 */   123,   10,  112,  249,  128,  163,   10,  203,  251,  258,
 /*   620 */   254,   95,  245,  265,  214,  222,  194,  203,  198,  182,
 /*   630 */   195,  343,  199,  223,  231,  140,  128,  182,  277,  182,
 /*   640 */   163,  227,  238,  260,  281,  279,  227,  245,  253,  254,
 /*   650 */   146,  148,  153,  286,   10,  156,  287,  226,  233,  159,
 /*   660 */    10,   10,  237,  245,  293,  292,  262,  290,  294,  183,
 /*   670 */   175,  176,  180,  186,  188,  315,  316,  317,  318,  224,
 /*   680 */   319,  320,  192,  321,  325,  326,  245,  196,  322,  200,
 /*   690 */   323,  205,  217,  239,  336,  240,  246,  244,  366,  221,
 /*   700 */   335,  252,  234,  261,  255,  345,  344,  264,  273,  273,
 /*   710 */   273,  273,  235,  273,  273,  273,  250,
};
static YYCODETYPE yy_lookahead[] = {
 /*     0 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    10 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*    20 */    21,   22,   22,   24,   24,    1,    2,    3,    4,    5,
 /*    30 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*    40 */    16,   17,   18,   19,   20,   21,   22,    0,   24,   78,
 /*    50 */    51,   52,   81,   29,   29,   31,   31,    1,    2,    3,
 /*    60 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*    70 */    14,   15,   16,   17,   18,   19,   20,   21,   22,    0,
 /*    80 */    24,   19,   20,   21,   22,   78,   24,   31,   81,    1,
 /*    90 */     2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   100 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   110 */    22,    0,   24,   77,    1,    2,    3,    4,    5,    6,
 /*   120 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   130 */    17,   18,   19,   20,   21,   22,  100,   24,   11,   12,
 /*   140 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   150 */    62,   24,   77,   78,   79,   95,   81,   44,   98,    1,
 /*   160 */     2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   170 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   180 */    22,    0,   24,    3,    4,    5,    6,    7,    8,    9,
 /*   190 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   200 */    20,   21,   22,   17,   24,    0,   20,   81,   83,   23,
 /*   210 */    24,   25,   87,    0,   17,   29,   91,   20,    0,   84,
 /*   220 */    23,   24,   25,   88,   89,   90,   29,  110,  103,   43,
 /*   230 */    44,   16,   17,   18,   19,   20,   21,   22,  110,   24,
 /*   240 */    43,   28,    0,   57,   58,   59,   60,   61,  110,   63,
 /*   250 */    64,   65,   66,   67,   57,   58,   59,   60,   61,   86,
 /*   260 */    63,   64,   65,   66,   67,   17,    0,   94,   20,   56,
 /*   270 */    97,   23,   24,   25,   85,   86,  103,   29,   78,   20,
 /*   280 */    80,   81,   23,   24,   25,  112,   11,   12,   29,   28,
 /*   290 */     0,   43,  103,   32,   33,   34,   35,   22,   37,   38,
 /*   300 */    81,  112,   43,   27,   28,   57,   58,   59,   60,   61,
 /*   310 */     0,   63,   64,   65,   66,   67,   57,   58,   59,   60,
 /*   320 */    61,   55,   63,   64,   65,   66,   67,    9,   10,   11,
 /*   330 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   340 */    22,   50,   24,   13,   14,   15,   16,   17,   18,   19,
 /*   350 */    20,   21,   22,    0,   24,   70,   71,   72,   73,   74,
 /*   360 */    75,   76,   26,   32,   33,   34,   35,    0,   37,   38,
 /*   370 */    86,   78,   79,   28,   81,   29,   40,   31,   86,    0,
 /*   380 */     0,   45,   43,   47,   99,   39,   86,  103,   28,   44,
 /*   390 */   105,  107,   86,   32,   28,  103,  112,   36,  106,  107,
 /*   400 */    24,   48,   49,  103,  112,   86,   53,    0,   55,  103,
 /*   410 */    44,  111,  112,  113,    0,   92,   93,  111,  112,  113,
 /*   420 */    86,   43,  103,   82,   86,   24,   85,   86,   49,   49,
 /*   430 */   111,  112,  113,   54,   55,   55,   44,  103,   86,   63,
 /*   440 */    86,  103,  108,  109,  103,   87,  112,  109,   94,   91,
 /*   450 */   112,   97,   63,  112,   29,  103,   49,  103,   86,   86,
 /*   460 */    53,  103,   55,   49,  112,  113,  112,   29,   54,   55,
 /*   470 */    86,   86,   57,   58,   59,  103,  103,   21,   22,   28,
 /*   480 */    24,   97,   86,   86,  112,  112,   86,  103,  103,  104,
 /*   490 */    86,   88,   89,   90,   86,   44,  112,  112,   86,  103,
 /*   500 */   103,   30,   43,  103,   86,   86,   86,  103,  112,  112,
 /*   510 */    86,  103,  112,   44,   43,  103,  112,   86,   86,   30,
 /*   520 */   112,  103,  103,  103,  112,   86,   91,  103,   86,   86,
 /*   530 */   112,  112,  112,   86,  103,  103,  112,   29,  103,   68,
 /*   540 */    86,    0,  103,  112,  112,  103,  103,   86,   43,   30,
 /*   550 */   103,  112,   86,   86,  112,  112,    0,  103,   86,  112,
 /*   560 */    86,    0,   43,   86,  103,   86,  112,    0,   86,  103,
 /*   570 */   103,   86,   30,  112,   29,  103,   86,  103,  112,  112,
 /*   580 */   103,   86,  103,   86,  112,  103,  112,   68,  103,  112,
 /*   590 */    49,  112,    0,  103,  112,   86,   55,  112,  103,    0,
 /*   600 */   103,   78,  112,   80,   81,    0,    0,  112,    0,  112,
 /*   610 */    68,   55,  103,   87,   29,   48,   55,   91,  101,  102,
 /*   620 */   103,  112,   55,   87,   17,   91,   32,   91,   32,  103,
 /*   630 */    36,    0,   36,   42,   43,   81,   29,  103,    0,  103,
 /*   640 */    48,   28,   28,   77,    0,    0,   28,   55,  102,  103,
 /*   650 */    50,   28,   81,    0,   55,   81,    0,   44,   44,   81,
 /*   660 */    55,   55,   44,   55,    0,    0,  100,    0,    0,   29,
 /*   670 */    93,   39,   29,   32,   32,   29,   29,   29,   29,   43,
 /*   680 */    29,   29,   32,   29,    0,    0,   55,   32,   29,   32,
 /*   690 */    29,   29,   29,   98,    0,   29,  110,  100,    0,   41,
 /*   700 */     0,   28,   42,  100,    3,    0,    0,   27,  114,  114,
 /*   710 */   114,  114,   43,  114,  114,  114,   46,
};
#define YY_SHIFT_USE_DFLT (-2)
static short yy_shift_ofst[] = {
 /*     0 */   336,   47,   79,  111,  181,  205,  353,  407,  266,  218,
 /*    10 */   415,  213,  415,  242,   -2,   -2,   -2,  415,  290,  379,
 /*    20 */   380,  556,  310,  367,  291,  259,  360,  259,   -2,   -1,
 /*    30 */    -2,   -2,  259,  259,  456,  259,  456,  259,   62,  259,
 /*    40 */    62,  259,   62,  259,  127,  259,  127,  259,  215,  259,
 /*    50 */   215,  259,  215,  259,  318,  259,  318,  259,  318,  259,
 /*    60 */   318,  259,  318,  259,  318,  259,  330,  275,  259,  401,
 /*    70 */   259,  330,  339,  197,  158,  259,  158,  376,   -2,  389,
 /*    80 */    -2,  259,  180,  378,  259,   56,  425,  392,   -2,  459,
 /*    90 */   259,   88,  438,  469,   -2,   -2,  471,  186,  345,   -2,
 /*   100 */   197,   -2,   -2,  259,    0,  259,  401,  259,  401,  259,
 /*   110 */   113,   -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,
 /*   120 */    -2,   -2,   -2,  508,  489,  545,   -2,  585,   -2,  366,
 /*   130 */    -2,  259,  401,  505,  197,  451,   -2,  456,   -2,  561,
 /*   140 */   638,  644,  259,  158,  645,  600,  259,  623,  259,   -2,
 /*   150 */   158,   -2,  599,  653,  414,  605,  656,  541,  606,  664,
 /*   160 */   665,  667,  668,  259,  158,  248,  276,  640,  261,  331,
 /*   170 */    -2,   -2,  640,  346,  632,   -2,  259,  158,   -2,  643,
 /*   180 */    -2,   -2,   -2,  542,  646,  641,  647,  642,  648,  361,
 /*   190 */   649,  650,  651,  594,  652,  655,  654,  596,  659,  657,
 /*   200 */   661,  640,   -2,   25,  662,   -2,   -2,   -2,   -2,  248,
 /*   210 */    -2,   -2,  519,  607,   -2,   24,  663,   -2,   -2,   -2,
 /*   220 */   658,  640,  591,  636,  259,  613,  684,  259,   -2,  158,
 /*   230 */    -2,  666,  614,  660,  669,  259,  618,  685,  666,   -2,
 /*   240 */    -2,   -2,  567,  608,  694,  415,  698,  700,  640,  670,
 /*   250 */   640,  673,  640,   -2,  701,  259,   -2,  158,   -2,  592,
 /*   260 */   631,  705,  706,  680,  640,   -2,
};
#define YY_REDUCE_USE_DFLT (-30)
static short yy_reduce_ofst[] = {
 /*     0 */   285,  -30,  -30,  -30,  -30,  -30,   75,  293,  126,  -30,
 /*    10 */   117,  -30,  128,  -30,  -30,  -30,  -30,  138,  -30,  200,
 /*    20 */   -29,  219,  -30,  -30,  -30,  292,  -30,  284,  -30,  -30,
 /*    30 */   -30,  -30,  372,  373,  -30,  396,  -30,  397,  -30,  400,
 /*    40 */   -30,  404,  -30,  408,  -30,  412,  -30,  418,  -30,  419,
 /*    50 */   -30,  420,  -30,  424,  -30,  431,  -30,  432,  -30,  439,
 /*    60 */   -30,  442,  -30,  443,  -30,  447,  -30,  -30,  454,  -30,
 /*    70 */   461,  -30,  -30,  300,  -30,  466,  -30,  -30,  -30,  -30,
 /*    80 */   -30,  467,  -30,  -30,  472,  -30,  -30,  -30,  -30,  -30,
 /*    90 */   474,  -30,  -30,  -30,  -30,  -30,  -30,  306,  -30,  -30,
 /*   100 */   352,  -30,  -30,  477,  -30,  479,  -30,  482,  -30,  485,
 /*   110 */   -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,
 /*   120 */   -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,
 /*   130 */   -30,  490,  -30,  -30,  319,  -30,  -30,  -30,  -30,  554,
 /*   140 */   -30,  -30,  495,  -30,  -30,  -30,  334,  -30,  338,  -30,
 /*   150 */   -30,  -30,  571,  -30,  523,  574,  -30,    7,  578,  -30,
 /*   160 */   -30,  -30,  -30,  497,  -30,  341,  -30,  125,  135,  403,
 /*   170 */   -30,  -30,  435,  323,  577,  -30,  509,  -30,  -30,  -30,
 /*   180 */   -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,
 /*   190 */   -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,
 /*   200 */   -30,  358,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  189,
 /*   210 */   -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,
 /*   220 */   -30,  534,  -30,  -30,  173,  -30,  -30,  384,  -30,  -30,
 /*   230 */   -30,   60,  -30,  -30,  -30,  354,  -30,  -30,  595,  -30,
 /*   240 */   -30,  -30,   36,  597,  -30,  586,  -30,  -30,  526,  -30,
 /*   250 */   517,  -30,  546,  -30,  -30,  385,  -30,  -30,  -30,  566,
 /*   260 */   603,  -30,  -30,  -30,  536,  -30,
};
static YYACTIONTYPE yy_default[] = {
 /*     0 */   423,  423,  423,  423,  423,  423,  423,  423,  423,  423,
 /*    10 */   423,  423,  423,  423,  367,  368,  369,  423,  423,  423,
 /*    20 */   423,  423,  423,  423,  423,  423,  352,  423,  353,  355,
 /*    30 */   356,  357,  423,  423,  370,  423,  372,  423,  373,  423,
 /*    40 */   374,  423,  375,  423,  376,  423,  377,  423,  378,  423,
 /*    50 */   379,  423,  380,  423,  381,  423,  382,  423,  383,  423,
 /*    60 */   384,  423,  385,  423,  386,  423,  387,  423,  423,  388,
 /*    70 */   423,  389,  423,  423,  402,  423,  393,  423,  403,  423,
 /*    80 */   404,  423,  406,  423,  423,  423,  423,  423,  394,  423,
 /*    90 */   423,  423,  423,  423,  395,  396,  422,  423,  423,  397,
 /*   100 */   423,  399,  401,  423,  405,  423,  407,  423,  408,  423,
 /*   110 */   423,  409,  410,  411,  412,  413,  414,  415,  416,  417,
 /*   120 */   418,  398,  400,  423,  420,  423,  419,  423,  421,  423,
 /*   130 */   391,  423,  390,  423,  423,  423,  392,  371,  354,  423,
 /*   140 */   423,  423,  423,  362,  423,  423,  423,  358,  423,  359,
 /*   150 */   361,  360,  423,  423,  423,  423,  423,  423,  423,  423,
 /*   160 */   423,  423,  423,  423,  351,  423,  423,  423,  295,  296,
 /*   170 */   306,  308,  423,  309,  310,  312,  423,  324,  311,  423,
 /*   180 */   313,  314,  350,  422,  423,  423,  423,  423,  423,  423,
 /*   190 */   423,  423,  423,  423,  423,  423,  423,  423,  423,  423,
 /*   200 */   423,  423,  304,  349,  423,  347,  348,  307,  305,  423,
 /*   210 */   297,  299,  422,  423,  300,  303,  423,  301,  302,  298,
 /*   220 */   423,  423,  423,  423,  423,  423,  423,  423,  327,  329,
 /*   230 */   328,  423,  423,  423,  423,  423,  423,  423,  423,  330,
 /*   240 */   332,  331,  423,  423,  423,  423,  423,  423,  423,  423,
 /*   250 */   423,  337,  423,  338,  423,  423,  340,  341,  339,  423,
 /*   260 */   423,  423,  423,  423,  423,  346,
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
  "NOT",           "BITWISE_NOT",   "SELECT",        "FROM",        
  "COMMA",         "IDENTIFIER",    "DOT",           "AS",          
  "JOIN",          "INNER",         "CROSS",         "LEFT",        
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
  "select_clause",  "where_clause",  "order_clause",  "group_clause",
  "having_clause",  "select_limit_clause",  "column_list",   "associated_name_list",
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
 /*   5 */ "select_statement ::= select_clause",
 /*   6 */ "select_statement ::= select_clause where_clause",
 /*   7 */ "select_statement ::= select_clause where_clause order_clause",
 /*   8 */ "select_statement ::= select_clause where_clause group_clause",
 /*   9 */ "select_statement ::= select_clause where_clause group_clause having_clause",
 /*  10 */ "select_statement ::= select_clause where_clause group_clause order_clause",
 /*  11 */ "select_statement ::= select_clause where_clause group_clause order_clause select_limit_clause",
 /*  12 */ "select_statement ::= select_clause where_clause group_clause having_clause order_clause",
 /*  13 */ "select_statement ::= select_clause where_clause select_limit_clause",
 /*  14 */ "select_statement ::= select_clause where_clause order_clause select_limit_clause",
 /*  15 */ "select_statement ::= select_clause where_clause group_clause select_limit_clause",
 /*  16 */ "select_statement ::= select_clause where_clause group_clause having_clause select_limit_clause",
 /*  17 */ "select_statement ::= select_clause order_clause",
 /*  18 */ "select_statement ::= select_clause group_clause order_clause",
 /*  19 */ "select_statement ::= select_clause group_clause having_clause order_clause",
 /*  20 */ "select_statement ::= select_clause order_clause select_limit_clause",
 /*  21 */ "select_statement ::= select_clause group_clause order_clause select_limit_clause",
 /*  22 */ "select_statement ::= select_clause where_clause group_clause having_clause order_clause select_limit_clause",
 /*  23 */ "select_statement ::= select_clause group_clause",
 /*  24 */ "select_statement ::= select_clause group_clause select_limit_clause",
 /*  25 */ "select_statement ::= select_clause group_clause having_clause",
 /*  26 */ "select_statement ::= select_clause group_clause having_clause select_limit_clause",
 /*  27 */ "select_statement ::= select_clause group_clause having_clause order_clause select_limit_clause",
 /*  28 */ "select_statement ::= select_clause select_limit_clause",
 /*  29 */ "select_clause ::= SELECT column_list FROM associated_name_list",
 /*  30 */ "select_clause ::= SELECT column_list FROM associated_name_list join_list",
 /*  31 */ "column_list ::= column_list COMMA column_item",
 /*  32 */ "column_list ::= column_item",
 /*  33 */ "column_item ::= TIMES",
 /*  34 */ "column_item ::= IDENTIFIER DOT TIMES",
 /*  35 */ "column_item ::= expr AS IDENTIFIER",
 /*  36 */ "column_item ::= expr IDENTIFIER",
 /*  37 */ "column_item ::= expr",
 /*  38 */ "associated_name_list ::= associated_name_list COMMA associated_name",
 /*  39 */ "associated_name_list ::= associated_name",
 /*  40 */ "join_list ::= join_list join_item",
 /*  41 */ "join_list ::= join_item",
 /*  42 */ "join_item ::= join_clause",
 /*  43 */ "join_clause ::= join_type aliased_or_qualified_name",
 /*  44 */ "join_clause ::= join_type aliased_or_qualified_name join_associated_name",
 /*  45 */ "join_clause ::= join_type aliased_or_qualified_name join_conditions",
 /*  46 */ "join_clause ::= join_type aliased_or_qualified_name join_associated_name join_conditions",
 /*  47 */ "join_associated_name ::= AS IDENTIFIER",
 /*  48 */ "join_associated_name ::= IDENTIFIER",
 /*  49 */ "join_type ::= JOIN",
 /*  50 */ "join_type ::= INNER JOIN",
 /*  51 */ "join_type ::= CROSS JOIN",
 /*  52 */ "join_type ::= LEFT JOIN",
 /*  53 */ "join_type ::= LEFT OUTER JOIN",
 /*  54 */ "join_type ::= RIGHT JOIN",
 /*  55 */ "join_type ::= RIGHT OUTER JOIN",
 /*  56 */ "join_type ::= FULL JOIN",
 /*  57 */ "join_type ::= FULL OUTER JOIN",
 /*  58 */ "join_conditions ::= ON expr",
 /*  59 */ "insert_statement ::= INSERT INTO aliased_or_qualified_name VALUES PARENTHESES_OPEN values_list PARENTHESES_CLOSE",
 /*  60 */ "insert_statement ::= INSERT INTO aliased_or_qualified_name PARENTHESES_OPEN field_list PARENTHESES_CLOSE VALUES PARENTHESES_OPEN values_list PARENTHESES_CLOSE",
 /*  61 */ "values_list ::= values_list COMMA value_item",
 /*  62 */ "values_list ::= value_item",
 /*  63 */ "value_item ::= expr",
 /*  64 */ "field_list ::= field_list COMMA field_item",
 /*  65 */ "field_list ::= field_item",
 /*  66 */ "field_item ::= IDENTIFIER",
 /*  67 */ "update_statement ::= update_clause",
 /*  68 */ "update_statement ::= update_clause where_clause",
 /*  69 */ "update_statement ::= update_clause limit_clause",
 /*  70 */ "update_statement ::= update_clause where_clause limit_clause",
 /*  71 */ "update_clause ::= UPDATE associated_name SET update_item_list",
 /*  72 */ "update_item_list ::= update_item_list COMMA update_item",
 /*  73 */ "update_item_list ::= update_item",
 /*  74 */ "update_item ::= qualified_name EQUALS new_value",
 /*  75 */ "new_value ::= expr",
 /*  76 */ "delete_statement ::= delete_clause",
 /*  77 */ "delete_statement ::= delete_clause where_clause",
 /*  78 */ "delete_statement ::= delete_clause limit_clause",
 /*  79 */ "delete_statement ::= delete_clause where_clause limit_clause",
 /*  80 */ "delete_clause ::= DELETE FROM associated_name",
 /*  81 */ "associated_name ::= aliased_or_qualified_name AS IDENTIFIER",
 /*  82 */ "associated_name ::= aliased_or_qualified_name IDENTIFIER",
 /*  83 */ "associated_name ::= aliased_or_qualified_name",
 /*  84 */ "aliased_or_qualified_name ::= qualified_name",
 /*  85 */ "where_clause ::= WHERE expr",
 /*  86 */ "order_clause ::= ORDER BY order_list",
 /*  87 */ "order_list ::= order_list COMMA order_item",
 /*  88 */ "order_list ::= order_item",
 /*  89 */ "order_item ::= expr",
 /*  90 */ "order_item ::= expr ASC",
 /*  91 */ "order_item ::= expr DESC",
 /*  92 */ "group_clause ::= GROUP BY group_list",
 /*  93 */ "group_list ::= group_list COMMA group_item",
 /*  94 */ "group_list ::= group_item",
 /*  95 */ "group_item ::= expr",
 /*  96 */ "having_clause ::= HAVING expr",
 /*  97 */ "select_limit_clause ::= LIMIT integer_or_placeholder",
 /*  98 */ "select_limit_clause ::= LIMIT integer_or_placeholder COMMA integer_or_placeholder",
 /*  99 */ "select_limit_clause ::= LIMIT integer_or_placeholder OFFSET integer_or_placeholder",
 /* 100 */ "limit_clause ::= LIMIT integer_or_placeholder",
 /* 101 */ "integer_or_placeholder ::= INTEGER",
 /* 102 */ "integer_or_placeholder ::= NPLACEHOLDER",
 /* 103 */ "integer_or_placeholder ::= SPLACEHOLDER",
 /* 104 */ "expr ::= MINUS expr",
 /* 105 */ "expr ::= expr MINUS expr",
 /* 106 */ "expr ::= expr PLUS expr",
 /* 107 */ "expr ::= expr TIMES expr",
 /* 108 */ "expr ::= expr DIVIDE expr",
 /* 109 */ "expr ::= expr MOD expr",
 /* 110 */ "expr ::= expr AND expr",
 /* 111 */ "expr ::= expr OR expr",
 /* 112 */ "expr ::= expr BITWISE_AND expr",
 /* 113 */ "expr ::= expr BITWISE_OR expr",
 /* 114 */ "expr ::= expr BITWISE_XOR expr",
 /* 115 */ "expr ::= expr EQUALS expr",
 /* 116 */ "expr ::= expr NOTEQUALS expr",
 /* 117 */ "expr ::= expr LESS expr",
 /* 118 */ "expr ::= expr GREATER expr",
 /* 119 */ "expr ::= expr GREATEREQUAL expr",
 /* 120 */ "expr ::= expr LESSEQUAL expr",
 /* 121 */ "expr ::= expr LIKE expr",
 /* 122 */ "expr ::= expr NOT LIKE expr",
 /* 123 */ "expr ::= expr ILIKE expr",
 /* 124 */ "expr ::= expr NOT ILIKE expr",
 /* 125 */ "expr ::= expr IN PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 126 */ "expr ::= expr NOT IN PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 127 */ "expr ::= expr AGAINST expr",
 /* 128 */ "expr ::= CAST PARENTHESES_OPEN expr AS IDENTIFIER PARENTHESES_CLOSE",
 /* 129 */ "expr ::= CONVERT PARENTHESES_OPEN expr USING IDENTIFIER PARENTHESES_CLOSE",
 /* 130 */ "expr ::= function_call",
 /* 131 */ "function_call ::= IDENTIFIER PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 132 */ "function_call ::= IDENTIFIER PARENTHESES_OPEN PARENTHESES_CLOSE",
 /* 133 */ "argument_list ::= argument_list COMMA argument_item",
 /* 134 */ "argument_list ::= argument_item",
 /* 135 */ "argument_item ::= TIMES",
 /* 136 */ "argument_item ::= expr",
 /* 137 */ "expr ::= expr IS NULL",
 /* 138 */ "expr ::= expr IS NOT NULL",
 /* 139 */ "expr ::= DISTINCT expr",
 /* 140 */ "expr ::= expr BETWEEN expr",
 /* 141 */ "expr ::= NOT expr",
 /* 142 */ "expr ::= BITWISE_NOT expr",
 /* 143 */ "expr ::= PARENTHESES_OPEN expr PARENTHESES_CLOSE",
 /* 144 */ "expr ::= qualified_name",
 /* 145 */ "expr ::= INTEGER",
 /* 146 */ "expr ::= STRING",
 /* 147 */ "expr ::= DOUBLE",
 /* 148 */ "expr ::= NULL",
 /* 149 */ "expr ::= TRUE",
 /* 150 */ "expr ::= FALSE",
 /* 151 */ "expr ::= NPLACEHOLDER",
 /* 152 */ "expr ::= SPLACEHOLDER",
 /* 153 */ "qualified_name ::= IDENTIFIER COLON IDENTIFIER DOT IDENTIFIER",
 /* 154 */ "qualified_name ::= IDENTIFIER COLON IDENTIFIER",
 /* 155 */ "qualified_name ::= IDENTIFIER DOT IDENTIFIER",
 /* 156 */ "qualified_name ::= IDENTIFIER",
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
// 511 "parser.lemon"
{
	if ((yypminor->yy0)) {
		if ((yypminor->yy0)->free_flag) {
			efree((yypminor->yy0)->token);
		}
		efree((yypminor->yy0));
	}
}
// 1180 "parser.c"
      break;
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
    case 86:
    case 87:
    case 88:
    case 89:
    case 90:
    case 91:
    case 92:
    case 93:
    case 95:
    case 96:
    case 98:
    case 99:
    case 100:
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
// 524 "parser.lemon"
{ zval_ptr_dtor(&(yypminor->yy48)); }
// 1223 "parser.c"
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
  { 72, 1 },
  { 72, 2 },
  { 72, 3 },
  { 72, 3 },
  { 72, 4 },
  { 72, 4 },
  { 72, 5 },
  { 72, 5 },
  { 72, 3 },
  { 72, 4 },
  { 72, 4 },
  { 72, 5 },
  { 72, 2 },
  { 72, 3 },
  { 72, 4 },
  { 72, 3 },
  { 72, 4 },
  { 72, 6 },
  { 72, 2 },
  { 72, 3 },
  { 72, 3 },
  { 72, 4 },
  { 72, 5 },
  { 72, 2 },
  { 76, 4 },
  { 76, 5 },
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
  { 89, 2 },
  { 89, 3 },
  { 89, 3 },
  { 89, 4 },
  { 92, 2 },
  { 92, 1 },
  { 90, 1 },
  { 90, 2 },
  { 90, 2 },
  { 90, 2 },
  { 90, 3 },
  { 90, 2 },
  { 90, 3 },
  { 90, 2 },
  { 90, 3 },
  { 93, 2 },
  { 73, 7 },
  { 73, 10 },
  { 94, 3 },
  { 94, 1 },
  { 97, 1 },
  { 95, 3 },
  { 95, 1 },
  { 98, 1 },
  { 74, 1 },
  { 74, 2 },
  { 74, 2 },
  { 74, 3 },
  { 99, 4 },
  { 101, 3 },
  { 101, 1 },
  { 102, 3 },
  { 104, 1 },
  { 75, 1 },
  { 75, 2 },
  { 75, 2 },
  { 75, 3 },
  { 105, 3 },
  { 87, 3 },
  { 87, 2 },
  { 87, 1 },
  { 91, 1 },
  { 77, 2 },
  { 78, 3 },
  { 106, 3 },
  { 106, 1 },
  { 107, 1 },
  { 107, 2 },
  { 107, 2 },
  { 79, 3 },
  { 108, 3 },
  { 108, 1 },
  { 109, 1 },
  { 80, 2 },
  { 81, 2 },
  { 81, 4 },
  { 81, 4 },
  { 100, 2 },
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
  **  // <lineno> <grammarfile>
  **     { ... }           // User supplied code
  **  // <lineno> <thisfile>
  **     break;
  */
      case 0:
// 520 "parser.lemon"
{
	status->ret = yymsp[0].minor.yy48;
}
// 1597 "parser.c"
        break;
      case 1:
      case 2:
      case 3:
      case 4:
      case 32:
      case 39:
      case 41:
      case 42:
      case 62:
      case 63:
      case 65:
      case 73:
      case 75:
      case 84:
      case 88:
      case 94:
      case 95:
      case 130:
      case 136:
      case 144:
// 526 "parser.lemon"
{
	yygotominor.yy48 = yymsp[0].minor.yy48;
}
// 1623 "parser.c"
        break;
      case 5:
// 544 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[0].minor.yy48, NULL, NULL, NULL, NULL, NULL);
}
// 1630 "parser.c"
        break;
      case 6:
// 548 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL, NULL, NULL, NULL);
}
// 1637 "parser.c"
        break;
      case 7:
// 552 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL, NULL, NULL);
}
// 1644 "parser.c"
        break;
      case 8:
// 556 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy48, NULL, NULL);
}
// 1651 "parser.c"
        break;
      case 9:
// 560 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, yymsp[-2].minor.yy48, NULL, yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL);
}
// 1658 "parser.c"
        break;
      case 10:
// 564 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, yymsp[-2].minor.yy48, yymsp[0].minor.yy48, yymsp[-1].minor.yy48, NULL, NULL);
}
// 1665 "parser.c"
        break;
      case 11:
// 568 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-4].minor.yy48, yymsp[-3].minor.yy48, yymsp[-1].minor.yy48, yymsp[-2].minor.yy48, NULL, yymsp[0].minor.yy48);
}
// 1672 "parser.c"
        break;
      case 12:
// 572 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-4].minor.yy48, yymsp[-3].minor.yy48, yymsp[0].minor.yy48, yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, NULL);
}
// 1679 "parser.c"
        break;
      case 13:
// 576 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, NULL, NULL, NULL, yymsp[0].minor.yy48);
}
// 1686 "parser.c"
        break;
      case 14:
// 580 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, NULL, NULL, yymsp[0].minor.yy48);
}
// 1693 "parser.c"
        break;
      case 15:
// 584 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, yymsp[-2].minor.yy48, NULL, yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy48);
}
// 1700 "parser.c"
        break;
      case 16:
// 588 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-4].minor.yy48, yymsp[-3].minor.yy48, NULL, yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
}
// 1707 "parser.c"
        break;
      case 17:
// 592 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy48, NULL, NULL, NULL);
}
// 1714 "parser.c"
        break;
      case 18:
// 596 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-2].minor.yy48, NULL, yymsp[0].minor.yy48, yymsp[-1].minor.yy48, NULL, NULL);
}
// 1721 "parser.c"
        break;
      case 19:
// 600 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, NULL, yymsp[0].minor.yy48, yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, NULL);
}
// 1728 "parser.c"
        break;
      case 20:
// 604 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-2].minor.yy48, NULL, yymsp[-1].minor.yy48, NULL, NULL, yymsp[0].minor.yy48);
}
// 1735 "parser.c"
        break;
      case 21:
// 608 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, NULL, yymsp[-1].minor.yy48, yymsp[-2].minor.yy48, NULL, yymsp[0].minor.yy48);
}
// 1742 "parser.c"
        break;
      case 22:
// 612 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-5].minor.yy48, yymsp[-4].minor.yy48, yymsp[-1].minor.yy48, yymsp[-3].minor.yy48, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
}
// 1749 "parser.c"
        break;
      case 23:
// 616 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-1].minor.yy48, NULL, NULL, yymsp[0].minor.yy48, NULL, NULL);
}
// 1756 "parser.c"
        break;
      case 24:
// 620 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-2].minor.yy48, NULL, NULL, yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy48);
}
// 1763 "parser.c"
        break;
      case 25:
// 624 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-2].minor.yy48, NULL, NULL, yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL);
}
// 1770 "parser.c"
        break;
      case 26:
// 628 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, NULL, NULL, yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
}
// 1777 "parser.c"
        break;
      case 27:
// 632 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-4].minor.yy48, NULL, yymsp[-1].minor.yy48, yymsp[-3].minor.yy48, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
}
// 1784 "parser.c"
        break;
      case 28:
// 636 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-1].minor.yy48, NULL, NULL, NULL, NULL, yymsp[0].minor.yy48);
}
// 1791 "parser.c"
        break;
      case 29:
// 642 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_clause(yymsp[-2].minor.yy48, yymsp[0].minor.yy48, NULL);
  yy_destructor(26,&yymsp[-3].minor);
  yy_destructor(27,&yymsp[-1].minor);
}
// 1800 "parser.c"
        break;
      case 30:
// 646 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_clause(yymsp[-3].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(26,&yymsp[-4].minor);
  yy_destructor(27,&yymsp[-2].minor);
}
// 1809 "parser.c"
        break;
      case 31:
      case 38:
      case 61:
      case 64:
      case 72:
      case 87:
      case 93:
      case 133:
// 652 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_zval_list(yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(28,&yymsp[-1].minor);
}
// 1824 "parser.c"
        break;
      case 33:
      case 135:
// 662 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_column_item(PHQL_T_ALL, NULL, NULL, NULL);
  yy_destructor(17,&yymsp[0].minor);
}
// 1833 "parser.c"
        break;
      case 34:
// 666 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_column_item(PHQL_T_DOMAINALL, NULL, yymsp[-2].minor.yy0, NULL);
  yy_destructor(30,&yymsp[-1].minor);
  yy_destructor(17,&yymsp[0].minor);
}
// 1842 "parser.c"
        break;
      case 35:
// 670 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-2].minor.yy48, NULL, yymsp[0].minor.yy0);
  yy_destructor(31,&yymsp[-1].minor);
}
// 1850 "parser.c"
        break;
      case 36:
// 674 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy0);
}
// 1857 "parser.c"
        break;
      case 37:
// 678 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_column_item(PHQL_T_EXPR, yymsp[0].minor.yy48, NULL, NULL);
}
// 1864 "parser.c"
        break;
      case 40:
// 694 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_zval_list(yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
}
// 1871 "parser.c"
        break;
      case 43:
// 711 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_item(yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL, NULL);
}
// 1878 "parser.c"
        break;
      case 44:
// 716 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_item(yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL);
}
// 1885 "parser.c"
        break;
      case 45:
// 721 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_item(yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy48);
}
// 1892 "parser.c"
        break;
      case 46:
// 726 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_item(yymsp[-3].minor.yy48, yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
}
// 1899 "parser.c"
        break;
      case 47:
// 732 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_qualified_name(NULL, NULL, yymsp[0].minor.yy0);
  yy_destructor(31,&yymsp[-1].minor);
}
// 1907 "parser.c"
        break;
      case 48:
      case 66:
      case 156:
// 736 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_qualified_name(NULL, NULL, yymsp[0].minor.yy0);
}
// 1916 "parser.c"
        break;
      case 49:
// 742 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_INNERJOIN);
  yy_destructor(32,&yymsp[0].minor);
}
// 1924 "parser.c"
        break;
      case 50:
// 746 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_INNERJOIN);
  yy_destructor(33,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 1933 "parser.c"
        break;
      case 51:
// 750 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_CROSSJOIN);
  yy_destructor(34,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 1942 "parser.c"
        break;
      case 52:
// 754 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  yy_destructor(35,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 1951 "parser.c"
        break;
      case 53:
// 758 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 1961 "parser.c"
        break;
      case 54:
// 762 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  yy_destructor(37,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 1970 "parser.c"
        break;
      case 55:
// 766 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  yy_destructor(37,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 1980 "parser.c"
        break;
      case 56:
// 770 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_FULLJOIN);
  yy_destructor(38,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 1989 "parser.c"
        break;
      case 57:
// 774 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_FULLJOIN);
  yy_destructor(38,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 1999 "parser.c"
        break;
      case 58:
// 780 "parser.lemon"
{
	yygotominor.yy48 = yymsp[0].minor.yy48;
  yy_destructor(39,&yymsp[-1].minor);
}
// 2007 "parser.c"
        break;
      case 59:
// 787 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_insert_statement(yymsp[-4].minor.yy48, NULL, yymsp[-1].minor.yy48);
  yy_destructor(40,&yymsp[-6].minor);
  yy_destructor(41,&yymsp[-5].minor);
  yy_destructor(42,&yymsp[-3].minor);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2019 "parser.c"
        break;
      case 60:
// 791 "parser.lemon"
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
// 2033 "parser.c"
        break;
      case 67:
// 829 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_update_statement(yymsp[0].minor.yy48, NULL, NULL);
}
// 2040 "parser.c"
        break;
      case 68:
// 833 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_update_statement(yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL);
}
// 2047 "parser.c"
        break;
      case 69:
// 837 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_update_statement(yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy48);
}
// 2054 "parser.c"
        break;
      case 70:
// 841 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_update_statement(yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
}
// 2061 "parser.c"
        break;
      case 71:
// 847 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_update_clause(yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(45,&yymsp[-3].minor);
  yy_destructor(46,&yymsp[-1].minor);
}
// 2070 "parser.c"
        break;
      case 74:
// 863 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_update_item(yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(3,&yymsp[-1].minor);
}
// 2078 "parser.c"
        break;
      case 76:
// 875 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_delete_statement(yymsp[0].minor.yy48, NULL, NULL);
}
// 2085 "parser.c"
        break;
      case 77:
// 879 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_delete_statement(yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL);
}
// 2092 "parser.c"
        break;
      case 78:
// 883 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_delete_statement(yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy48);
}
// 2099 "parser.c"
        break;
      case 79:
// 887 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_delete_statement(yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
}
// 2106 "parser.c"
        break;
      case 80:
// 893 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_delete_clause(yymsp[0].minor.yy48);
  yy_destructor(47,&yymsp[-2].minor);
  yy_destructor(27,&yymsp[-1].minor);
}
// 2115 "parser.c"
        break;
      case 81:
// 899 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_assoc_name(yymsp[-2].minor.yy48, yymsp[0].minor.yy0);
  yy_destructor(31,&yymsp[-1].minor);
}
// 2123 "parser.c"
        break;
      case 82:
// 903 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_assoc_name(yymsp[-1].minor.yy48, yymsp[0].minor.yy0);
}
// 2130 "parser.c"
        break;
      case 83:
// 907 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_assoc_name(yymsp[0].minor.yy48, NULL);
}
// 2137 "parser.c"
        break;
      case 85:
// 919 "parser.lemon"
{
	yygotominor.yy48 = yymsp[0].minor.yy48;
  yy_destructor(48,&yymsp[-1].minor);
}
// 2145 "parser.c"
        break;
      case 86:
// 925 "parser.lemon"
{
	yygotominor.yy48 = yymsp[0].minor.yy48;
  yy_destructor(49,&yymsp[-2].minor);
  yy_destructor(50,&yymsp[-1].minor);
}
// 2154 "parser.c"
        break;
      case 89:
// 941 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_order_item(yymsp[0].minor.yy48, 0);
}
// 2161 "parser.c"
        break;
      case 90:
// 945 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_order_item(yymsp[-1].minor.yy48, PHQL_T_ASC);
  yy_destructor(51,&yymsp[0].minor);
}
// 2169 "parser.c"
        break;
      case 91:
// 949 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_order_item(yymsp[-1].minor.yy48, PHQL_T_DESC);
  yy_destructor(52,&yymsp[0].minor);
}
// 2177 "parser.c"
        break;
      case 92:
// 955 "parser.lemon"
{
	yygotominor.yy48 = yymsp[0].minor.yy48;
  yy_destructor(53,&yymsp[-2].minor);
  yy_destructor(50,&yymsp[-1].minor);
}
// 2186 "parser.c"
        break;
      case 96:
// 977 "parser.lemon"
{
	yygotominor.yy48 = yymsp[0].minor.yy48;
  yy_destructor(54,&yymsp[-1].minor);
}
// 2194 "parser.c"
        break;
      case 97:
      case 100:
// 983 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_limit_clause(yymsp[0].minor.yy48, NULL);
  yy_destructor(55,&yymsp[-1].minor);
}
// 2203 "parser.c"
        break;
      case 98:
// 987 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_limit_clause(yymsp[0].minor.yy48, yymsp[-2].minor.yy48);
  yy_destructor(55,&yymsp[-3].minor);
  yy_destructor(28,&yymsp[-1].minor);
}
// 2212 "parser.c"
        break;
      case 99:
// 991 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_limit_clause(yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(55,&yymsp[-3].minor);
  yy_destructor(56,&yymsp[-1].minor);
}
// 2221 "parser.c"
        break;
      case 101:
      case 145:
// 1001 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_literal_zval(PHQL_T_INTEGER, yymsp[0].minor.yy0);
}
// 2229 "parser.c"
        break;
      case 102:
      case 151:
// 1005 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_placeholder_zval(PHQL_T_NPLACEHOLDER, yymsp[0].minor.yy0);
}
// 2237 "parser.c"
        break;
      case 103:
      case 152:
// 1009 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_placeholder_zval(PHQL_T_SPLACEHOLDER, yymsp[0].minor.yy0);
}
// 2245 "parser.c"
        break;
      case 104:
// 1015 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_MINUS, NULL, yymsp[0].minor.yy48);
  yy_destructor(20,&yymsp[-1].minor);
}
// 2253 "parser.c"
        break;
      case 105:
// 1019 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_SUB, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(20,&yymsp[-1].minor);
}
// 2261 "parser.c"
        break;
      case 106:
// 1023 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_ADD, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(19,&yymsp[-1].minor);
}
// 2269 "parser.c"
        break;
      case 107:
// 1027 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_MUL, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(17,&yymsp[-1].minor);
}
// 2277 "parser.c"
        break;
      case 108:
// 1031 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_DIV, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(16,&yymsp[-1].minor);
}
// 2285 "parser.c"
        break;
      case 109:
// 1035 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_MOD, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(18,&yymsp[-1].minor);
}
// 2293 "parser.c"
        break;
      case 110:
// 1039 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_AND, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(9,&yymsp[-1].minor);
}
// 2301 "parser.c"
        break;
      case 111:
// 1043 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_OR, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(10,&yymsp[-1].minor);
}
// 2309 "parser.c"
        break;
      case 112:
// 1047 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_BITWISE_AND, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(13,&yymsp[-1].minor);
}
// 2317 "parser.c"
        break;
      case 113:
// 1051 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_BITWISE_OR, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(14,&yymsp[-1].minor);
}
// 2325 "parser.c"
        break;
      case 114:
// 1055 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_BITWISE_XOR, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(15,&yymsp[-1].minor);
}
// 2333 "parser.c"
        break;
      case 115:
// 1059 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_EQUALS, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(3,&yymsp[-1].minor);
}
// 2341 "parser.c"
        break;
      case 116:
// 1063 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_NOTEQUALS, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(4,&yymsp[-1].minor);
}
// 2349 "parser.c"
        break;
      case 117:
// 1067 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_LESS, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(5,&yymsp[-1].minor);
}
// 2357 "parser.c"
        break;
      case 118:
// 1071 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_GREATER, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(6,&yymsp[-1].minor);
}
// 2365 "parser.c"
        break;
      case 119:
// 1075 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_GREATEREQUAL, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(7,&yymsp[-1].minor);
}
// 2373 "parser.c"
        break;
      case 120:
// 1079 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_LESSEQUAL, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(8,&yymsp[-1].minor);
}
// 2381 "parser.c"
        break;
      case 121:
// 1083 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_LIKE, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(11,&yymsp[-1].minor);
}
// 2389 "parser.c"
        break;
      case 122:
// 1087 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_NLIKE, yymsp[-3].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(24,&yymsp[-2].minor);
  yy_destructor(11,&yymsp[-1].minor);
}
// 2398 "parser.c"
        break;
      case 123:
// 1091 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_ILIKE, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(12,&yymsp[-1].minor);
}
// 2406 "parser.c"
        break;
      case 124:
// 1095 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_NILIKE, yymsp[-3].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(24,&yymsp[-2].minor);
  yy_destructor(12,&yymsp[-1].minor);
}
// 2415 "parser.c"
        break;
      case 125:
// 1099 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_IN, yymsp[-4].minor.yy48, yymsp[-1].minor.yy48);
  yy_destructor(22,&yymsp[-3].minor);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2425 "parser.c"
        break;
      case 126:
// 1103 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_NOTIN, yymsp[-5].minor.yy48, yymsp[-1].minor.yy48);
  yy_destructor(24,&yymsp[-4].minor);
  yy_destructor(22,&yymsp[-3].minor);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2436 "parser.c"
        break;
      case 127:
// 1107 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_AGAINST, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(1,&yymsp[-1].minor);
}
// 2444 "parser.c"
        break;
      case 128:
// 1111 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_CAST, yymsp[-3].minor.yy48, phql_ret_raw_qualified_name(yymsp[-1].minor.yy0, NULL));
  yy_destructor(60,&yymsp[-5].minor);
  yy_destructor(43,&yymsp[-4].minor);
  yy_destructor(31,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2455 "parser.c"
        break;
      case 129:
// 1115 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_CONVERT, yymsp[-3].minor.yy48, phql_ret_raw_qualified_name(yymsp[-1].minor.yy0, NULL));
  yy_destructor(61,&yymsp[-5].minor);
  yy_destructor(43,&yymsp[-4].minor);
  yy_destructor(62,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2466 "parser.c"
        break;
      case 131:
// 1125 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_func_call(yymsp[-3].minor.yy0, yymsp[-1].minor.yy48);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2475 "parser.c"
        break;
      case 132:
// 1129 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_func_call(yymsp[-2].minor.yy0, NULL);
  yy_destructor(43,&yymsp[-1].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2484 "parser.c"
        break;
      case 134:
// 1139 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_zval_list(yymsp[0].minor.yy48, NULL);
}
// 2491 "parser.c"
        break;
      case 137:
// 1153 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_ISNULL, yymsp[-2].minor.yy48, NULL);
  yy_destructor(21,&yymsp[-1].minor);
  yy_destructor(63,&yymsp[0].minor);
}
// 2500 "parser.c"
        break;
      case 138:
// 1157 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_ISNOTNULL, yymsp[-3].minor.yy48, NULL);
  yy_destructor(21,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
  yy_destructor(63,&yymsp[0].minor);
}
// 2510 "parser.c"
        break;
      case 139:
// 1161 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_DISTINCT, NULL, yymsp[0].minor.yy48);
  yy_destructor(23,&yymsp[-1].minor);
}
// 2518 "parser.c"
        break;
      case 140:
// 1165 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_BETWEEN, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(2,&yymsp[-1].minor);
}
// 2526 "parser.c"
        break;
      case 141:
// 1169 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_NOT, NULL, yymsp[0].minor.yy48);
  yy_destructor(24,&yymsp[-1].minor);
}
// 2534 "parser.c"
        break;
      case 142:
// 1173 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_BITWISE_NOT, NULL, yymsp[0].minor.yy48);
  yy_destructor(25,&yymsp[-1].minor);
}
// 2542 "parser.c"
        break;
      case 143:
// 1177 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_ENCLOSED, yymsp[-1].minor.yy48, NULL);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2551 "parser.c"
        break;
      case 146:
// 1189 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_literal_zval(PHQL_T_STRING, yymsp[0].minor.yy0);
}
// 2558 "parser.c"
        break;
      case 147:
// 1193 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_literal_zval(PHQL_T_DOUBLE, yymsp[0].minor.yy0);
}
// 2565 "parser.c"
        break;
      case 148:
// 1197 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_literal_zval(PHQL_T_NULL, NULL);
  yy_destructor(63,&yymsp[0].minor);
}
// 2573 "parser.c"
        break;
      case 149:
// 1201 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_literal_zval(PHQL_T_TRUE, NULL);
  yy_destructor(66,&yymsp[0].minor);
}
// 2581 "parser.c"
        break;
      case 150:
// 1205 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_literal_zval(PHQL_T_FALSE, NULL);
  yy_destructor(67,&yymsp[0].minor);
}
// 2589 "parser.c"
        break;
      case 153:
// 1219 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_qualified_name(yymsp[-4].minor.yy0, yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(68,&yymsp[-3].minor);
  yy_destructor(30,&yymsp[-1].minor);
}
// 2598 "parser.c"
        break;
      case 154:
// 1223 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_qualified_name(yymsp[-2].minor.yy0, NULL, yymsp[0].minor.yy0);
  yy_destructor(68,&yymsp[-1].minor);
}
// 2606 "parser.c"
        break;
      case 155:
// 1227 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_qualified_name(NULL, yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(30,&yymsp[-1].minor);
}
// 2614 "parser.c"
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
// 444 "parser.lemon"

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

// 2723 "parser.c"
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
