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

static zval *phql_ret_qualified_name(phql_parser_token *A, phql_parser_token *B)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	add_assoc_long(ret, "type", PHQL_T_QUALIFIED);
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

static zval *phql_ret_aliased_name(phql_parser_token *A, phql_parser_token *B)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init_size(ret, 3);
	add_assoc_long(ret, "type", PHQL_T_ALIASED);
	add_assoc_stringl(ret, "ns-alias", A->token, A->token_len, 0);
	add_assoc_stringl(ret, "name", B->token, B->token_len, 0);
	efree(B);
	efree(A);

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

static zval *phql_ret_limit_clause(phql_parser_token *L, phql_parser_token *O)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	add_assoc_stringl(ret, "number", L->token, L->token_len, 0);
	efree(L);

	if (O != NULL) {
		add_assoc_stringl(ret, "offset", O->token, O->token_len, 0);
		efree(O);
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


// 426 "parser.c"
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
#define YYNSTATE 267
#define YYNRULE 156
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
 /*    40 */    36,   34,   38,   32,   29,   74,   69,  267,   64,   18,
 /*    50 */    27,   28,   20,  218,  203,  216,  201,   72,   78,   50,
 /*    60 */    52,   54,   56,   58,   60,   40,   42,   62,   67,   44,
 /*    70 */    46,   48,   36,   34,   38,   32,   29,   74,   69,  268,
 /*    80 */    64,   32,   29,   74,   69,  154,   64,   83,  156,   72,
 /*    90 */    78,   50,   52,   54,   56,   58,   60,   40,   42,   62,
 /*   100 */    67,   44,   46,   48,   36,   34,   38,   32,   29,   74,
 /*   110 */    69,  269,   64,    9,   72,   78,   50,   52,   54,   56,
 /*   120 */    58,   60,   40,   42,   62,   67,   44,   46,   48,   36,
 /*   130 */    34,   38,   32,   29,   74,   69,  270,   64,   44,   46,
 /*   140 */    48,   36,   34,   38,   32,   29,   74,   69,   89,   64,
 /*   150 */    36,   34,   38,   32,   29,   74,   69,  108,   64,   72,
 /*   160 */    78,   50,   52,   54,   56,   58,   60,   40,   42,   62,
 /*   170 */    67,   44,   46,   48,   36,   34,   38,   32,   29,   74,
 /*   180 */    69,  271,   64,   50,   52,   54,   56,   58,   60,   40,
 /*   190 */    42,   62,   67,   44,   46,   48,   36,   34,   38,   32,
 /*   200 */    29,   74,   69,   99,   64,  273,   30,  110,  133,  100,
 /*   210 */   102,  104,  198,  110,   26,   93,  181,  182,  184,  186,
 /*   220 */    99,  190,  194,   30,  281,  109,  100,  102,  104,  106,
 /*   230 */   119,  109,   93,   92,   23,  134,    7,  148,  150,   92,
 /*   240 */   158,  274,  111,   11,   80,   86,  106,  114,  112,  113,
 /*   250 */   115,  116,  117,  118,   21,  110,   71,   76,  141,  111,
 /*   260 */    10,   80,   86,   13,  114,  112,  113,  115,  116,  117,
 /*   270 */   118,  208,  367,  109,   30,  110,   71,  100,  102,  104,
 /*   280 */   125,   92,  120,  209,    8,   16,   30,  140,  121,  100,
 /*   290 */   102,  104,   15,  109,   75,   93,   10,  106,  165,  243,
 /*   300 */    95,   92,  120,  204,  167,  168,  166,  167,  168,  106,
 /*   310 */   111,  232,   80,   86,  241,  114,  112,  113,  115,  116,
 /*   320 */   117,  118,  111,  247,   80,   86,  123,  114,  112,  113,
 /*   330 */   115,  116,  117,  118,   40,   42,   62,   67,   44,   46,
 /*   340 */    48,   36,   34,   38,   32,   29,   74,   69,  368,   64,
 /*   350 */    62,   67,   44,   46,   48,   36,   34,   38,   32,   29,
 /*   360 */    74,   69,   22,   64,  110,   71,  424,    1,    2,    3,
 /*   370 */     4,    5,    6,  161,  170,  174,  162,  110,  146,  219,
 /*   380 */   212,  215,  109,  272,  251,  259,  254,  220,   19,  131,
 /*   390 */    92,  120,  248,  187,  264,  109,  242,  188,  109,   24,
 /*   400 */   143,  147,  260,   92,  110,  229,   92,  110,   71,  181,
 /*   410 */   182,  184,  186,  225,  190,  194,  230,  110,  229,  110,
 /*   420 */    26,  135,  109,   17,  137,  109,  236,  223,  231,  230,
 /*   430 */    92,  159,   21,   92,   98,  109,  141,  109,   10,  110,
 /*   440 */   146,   25,  275,   92,   64,   92,   70,  164,  110,  229,
 /*   450 */   179,   97,  205,  207,  212,  215,  200,  109,  110,  257,
 /*   460 */   228,   74,   69,  145,   64,   92,  109,   96,  178,  289,
 /*   470 */   163,  206,  109,   77,   92,   81,  109,  256,   65,  127,
 /*   480 */    92,  110,   31,  283,   92,  110,   33,  110,   35,  129,
 /*   490 */    84,   21,  110,   37,  110,   39,  138,   10,   85,  109,
 /*   500 */   366,  110,   41,  109,  177,  109,  175,   92,  253,  254,
 /*   510 */   109,   92,  109,   92,  172,   87,  110,   43,   92,  109,
 /*   520 */    92,  110,   45,  110,   47,  110,   49,   92,   12,  279,
 /*   530 */   110,   51,  110,   53,  109,  110,   55,  110,   57,  109,
 /*   540 */   335,  109,   92,  109,  110,   59,   90,   92,  109,   92,
 /*   550 */   109,   92,   91,  109,  121,  109,   92,   14,   92,  110,
 /*   560 */    61,   92,  109,   92,  110,   63,  122,   94,  110,   66,
 /*   570 */    92,  110,   68,  110,   73,  110,   79,  109,  110,   82,
 /*   580 */   110,   88,  109,  191,   10,   92,  109,  192,  159,  109,
 /*   590 */    92,  109,  123,  109,   92,  245,  109,   92,  109,   92,
 /*   600 */   290,   92,  278,  124,   92,  211,   92,  110,  101,  110,
 /*   610 */   103,  110,  105,  110,  107,  276,  277,  122,  110,  128,
 /*   620 */   110,  139,  110,  160,  292,  109,  284,  109,  344,  109,
 /*   630 */   285,  109,  130,   92,  286,   92,  109,   92,  109,   92,
 /*   640 */   109,   97,  110,  173,   92,  179,   92,  199,   92,   21,
 /*   650 */   151,  200,  153,  157,  138,   10,  179,  126,  249,  179,
 /*   660 */   109,  266,  200,  178,   21,  200,  179,  210,   92,  179,
 /*   670 */    10,   10,  169,   21,  178,  222,  159,  178,   97,   10,
 /*   680 */    94,   10,  336,  245,  178,   10,  195,  178,  227,   10,
 /*   690 */   196,  238,  227,  421,  132,  261,  345,  282,  136,  280,
 /*   700 */   144,  142,  149,  287,  226,  123,  152,  233,  237,  288,
 /*   710 */   155,  294,  293,  291,  295,  180,  172,  171,  176,  263,
 /*   720 */   121,  317,  318,  183,  319,  221,  185,  320,  224,  327,
 /*   730 */   321,  322,  189,  328,  323,  324,  193,  245,  213,  197,
 /*   740 */   214,  239,  244,  338,  325,  202,  217,  240,  369,  337,
 /*   750 */   252,  245,  234,  258,  255,  347,  262,  346,  265,  272,
 /*   760 */   272,  272,  235,  272,  272,  272,  272,  250,  272,  272,
 /*   770 */   272,  272,  272,  272,  272,  272,  246,
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
 /*   110 */    22,    0,   24,   81,    1,    2,    3,    4,    5,    6,
 /*   120 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   130 */    17,   18,   19,   20,   21,   22,    0,   24,   13,   14,
 /*   140 */    15,   16,   17,   18,   19,   20,   21,   22,   60,   24,
 /*   150 */    16,   17,   18,   19,   20,   21,   22,   44,   24,    1,
 /*   160 */     2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   170 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   180 */    22,    0,   24,    3,    4,    5,    6,    7,    8,    9,
 /*   190 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   200 */    20,   21,   22,   17,   24,    0,   20,   86,   87,   23,
 /*   210 */    24,   25,   28,   86,   87,   29,   32,   33,   34,   35,
 /*   220 */    17,   37,   38,   20,    0,  104,   23,   24,   25,   43,
 /*   230 */    44,  104,   29,  112,  107,  108,   77,   78,   79,  112,
 /*   240 */    81,    0,   56,   56,   58,   59,   43,   61,   62,   63,
 /*   250 */    64,   65,   66,   67,   49,   86,   87,   24,   53,   56,
 /*   260 */    55,   58,   59,   56,   61,   62,   63,   64,   65,   66,
 /*   270 */    67,   17,    0,  104,   20,   86,   87,   23,   24,   25,
 /*   280 */   111,  112,  113,   29,   78,   79,   20,   81,   30,   23,
 /*   290 */    24,   25,   56,  104,   61,   29,   55,   43,   84,   77,
 /*   300 */   111,  112,  113,   89,   90,   91,   89,   90,   91,   43,
 /*   310 */    56,   96,   58,   59,   99,   61,   62,   63,   64,   65,
 /*   320 */    66,   67,   56,  101,   58,   59,   68,   61,   62,   63,
 /*   330 */    64,   65,   66,   67,    9,   10,   11,   12,   13,   14,
 /*   340 */    15,   16,   17,   18,   19,   20,   21,   22,    0,   24,
 /*   350 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   360 */    21,   22,   50,   24,   86,   87,   70,   71,   72,   73,
 /*   370 */    74,   75,   76,   26,   93,   94,   82,   86,   87,   85,
 /*   380 */    86,   87,  104,    0,  102,  103,  104,   40,   81,  111,
 /*   390 */   112,  113,   45,   32,   47,  104,  100,   36,  104,   28,
 /*   400 */   109,  110,  106,  112,   86,   87,  112,   86,   87,   32,
 /*   410 */    33,   34,   35,   95,   37,   38,   98,   86,   87,   86,
 /*   420 */    87,   78,  104,   80,   81,  104,   95,   42,   43,   98,
 /*   430 */   112,   48,   49,  112,  113,  104,   53,  104,   55,   86,
 /*   440 */    87,  108,    0,  112,   24,  112,   43,   83,   86,   87,
 /*   450 */    86,   28,   88,   85,   86,   87,   92,  104,   86,   87,
 /*   460 */    98,   21,   22,  110,   24,  112,  104,   44,  104,    0,
 /*   470 */    27,   28,  104,   61,  112,   43,  104,  105,   11,   12,
 /*   480 */   112,   86,   87,    0,  112,   86,   87,   86,   87,   22,
 /*   490 */    29,   49,   86,   87,   86,   87,   54,   55,   44,  104,
 /*   500 */     0,   86,   87,  104,   29,  104,   31,  112,  103,  104,
 /*   510 */   104,  112,  104,  112,   39,   43,   86,   87,  112,  104,
 /*   520 */   112,   86,   87,   86,   87,   86,   87,  112,   28,    0,
 /*   530 */    86,   87,   86,   87,  104,   86,   87,   86,   87,  104,
 /*   540 */     0,  104,  112,  104,   86,   87,   29,  112,  104,  112,
 /*   550 */   104,  112,   44,  104,   30,  104,  112,   57,  112,   86,
 /*   560 */    87,  112,  104,  112,   86,   87,   29,   43,   86,   87,
 /*   570 */   112,   86,   87,   86,   87,   86,   87,  104,   86,   87,
 /*   580 */    86,   87,  104,   32,   55,  112,  104,   36,   48,  104,
 /*   590 */   112,  104,   68,  104,  112,   55,  104,  112,  104,  112,
 /*   600 */     0,  112,    0,   29,  112,   17,  112,   86,   87,   86,
 /*   610 */    87,   86,   87,   86,   87,    0,    0,   29,   86,   87,
 /*   620 */    86,   87,   86,   87,    0,  104,    0,  104,    0,  104,
 /*   630 */     0,  104,   43,  112,    0,  112,  104,  112,  104,  112,
 /*   640 */   104,   28,   86,   87,  112,   86,  112,   88,  112,   49,
 /*   650 */    78,   92,   80,   81,   54,   55,   86,   44,   88,   86,
 /*   660 */   104,   88,   92,  104,   49,   92,   86,   30,  112,   86,
 /*   670 */    55,   55,   92,   49,  104,   92,   48,  104,   28,   55,
 /*   680 */    43,   55,    0,   55,  104,   55,   32,  104,   28,   55,
 /*   690 */    36,   28,   28,    3,   44,   77,    0,    0,   81,    0,
 /*   700 */    28,   50,   81,    0,   44,   68,   81,   44,   44,    0,
 /*   710 */    81,    0,    0,    0,    0,   29,   39,   94,   29,  101,
 /*   720 */    30,   29,   29,   32,   29,   41,   32,   29,   43,    0,
 /*   730 */    29,   29,   32,    0,   29,   29,   32,   55,   30,   32,
 /*   740 */    17,   99,  101,    0,   29,   29,   29,   29,    0,    0,
 /*   750 */    28,   55,   42,   29,    3,    0,  101,    0,   27,  114,
 /*   760 */   114,  114,   43,  114,  114,  114,  114,   46,  114,  114,
 /*   770 */   114,  114,  114,  114,  114,  114,   56,
};
#define YY_SHIFT_USE_DFLT (-2)
static short yy_shift_ofst[] = {
 /*     0 */   347,   47,   79,  111,  136,  181,  383,  205,  241,  224,
 /*    10 */   187,  500,  207,  272,  236,  348,  442,  615,  529,  469,
 /*    20 */   483,  312,  266,  371,  266,   -2,   -1,   -2,   -2,  266,
 /*    30 */   266,  440,  266,  440,  266,   62,  266,   62,  266,   62,
 /*    40 */   266,  339,  266,  339,  266,  134,  266,  134,  266,  134,
 /*    50 */   266,  325,  266,  325,  266,  325,  266,  325,  266,  325,
 /*    60 */   266,  325,  266,  125,  467,  266,  420,  266,  125,  403,
 /*    70 */   203,  158,  266,  158,  233,   -2,  412,   -2,  266,  180,
 /*    80 */   432,  266,   56,  461,  454,   -2,  472,  266,   88,  517,
 /*    90 */   508,   -2,   -2,  524,  186,  423,   -2,  203,   -2,   -2,
 /*   100 */   266,    0,  266,  420,  266,  420,  266,  113,   -2,   -2,
 /*   110 */    -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,
 /*   120 */    -2,  537,   -2,  574,   -2,  613,   -2,  266,  420,  589,
 /*   130 */   203,  650,   -2,  440,   -2,  616,  602,  697,  266,  158,
 /*   140 */   699,  651,  266,  672,  266,   -2,  158,   -2,  626,  703,
 /*   150 */   600,  630,  709,  624,  634,  711,  712,  713,  714,  266,
 /*   160 */   158,  254,  443,  686,  184,  377,   -2,   -2,  686,  475,
 /*   170 */   677,   -2,  266,  158,   -2,  689,   -2,   -2,   -2,   -2,
 /*   180 */   258,  692,  691,  693,  694,  695,  361,  698,  700,  701,
 /*   190 */   551,  702,  704,  705,  654,  706,  707,  715,  686,   -2,
 /*   200 */    25,  716,   -2,   -2,   -2,   -2,  254,   -2,   -2,  637,
 /*   210 */   588,   -2,  708,  723,   -2,   24,  717,   -2,   -2,   -2,
 /*   220 */   684,  686,  385,  685,  266,  660,  729,  266,   -2,  158,
 /*   230 */    -2,  718,  663,  710,  719,  266,  664,  733,  718,   -2,
 /*   240 */    -2,   -2,  540,  682,  743,  720,  748,  749,  686,  721,
 /*   250 */   724,  722,  724,   -2,  751,  266,   -2,  158,  690,   -2,
 /*   260 */   628,  696,  755,  757,  731,  686,   -2,
};
#define YY_REDUCE_USE_DFLT (-30)
static short yy_reduce_ofst[] = {
 /*     0 */   296,  -30,  -30,  -30,  -30,  -30,  159,  206,   32,  -30,
 /*    10 */   -30,  -30,  -30,  -30,  -30,  -30,  343,  -29,  307,  -30,
 /*    20 */   -30,  -30,  127,  -30,  333,  -30,  -30,  -30,  -30,  121,
 /*    30 */   395,  -30,  399,  -30,  401,  -30,  406,  -30,  408,  -30,
 /*    40 */   415,  -30,  430,  -30,  435,  -30,  437,  -30,  439,  -30,
 /*    50 */   444,  -30,  446,  -30,  449,  -30,  451,  -30,  458,  -30,
 /*    60 */   473,  -30,  478,  -30,  -30,  482,  -30,  485,  -30,  -30,
 /*    70 */   169,  -30,  487,  -30,  -30,  -30,  -30,  -30,  489,  -30,
 /*    80 */   -30,  492,  -30,  -30,  -30,  -30,  -30,  494,  -30,  -30,
 /*    90 */   -30,  -30,  -30,  -30,  189,  -30,  -30,  321,  -30,  -30,
 /*   100 */   521,  -30,  523,  -30,  525,  -30,  527,  -30,  -30,  -30,
 /*   110 */   -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,
 /*   120 */   -30,  -30,  -30,  -30,  -30,  -30,  -30,  532,  -30,  -30,
 /*   130 */   278,  -30,  -30,  -30,  -30,  617,  -30,  -30,  534,  -30,
 /*   140 */   -30,  -30,  291,  -30,  353,  -30,  -30,  -30,  621,  -30,
 /*   150 */   572,  625,  -30,    7,  629,  -30,  -30,  -30,  -30,  536,
 /*   160 */   -30,  294,  -30,  364,  214,  217,  -30,  -30,  580,  281,
 /*   170 */   623,  -30,  556,  -30,  -30,  -30,  -30,  -30,  -30,  -30,
 /*   180 */   -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,
 /*   190 */   -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  559,  -30,
 /*   200 */   -30,  -30,  -30,  -30,  -30,  -30,  368,  -30,  -30,  -30,
 /*   210 */   -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,
 /*   220 */   -30,  583,  -30,  -30,  318,  -30,  -30,  362,  -30,  -30,
 /*   230 */   -30,  215,  -30,  -30,  -30,  331,  -30,  -30,  642,  -30,
 /*   240 */   -30,  -30,  222,  641,  -30,  -30,  -30,  -30,  570,  -30,
 /*   250 */   282,  -30,  405,  -30,  -30,  372,  -30,  -30,  -30,  -30,
 /*   260 */   618,  655,  -30,  -30,  -30,  573,  -30,
};
static YYACTIONTYPE yy_default[] = {
 /*     0 */   423,  423,  423,  423,  423,  423,  423,  423,  423,  423,
 /*    10 */   423,  423,  423,  423,  423,  423,  423,  423,  423,  423,
 /*    20 */   423,  423,  423,  355,  423,  356,  358,  359,  360,  423,
 /*    30 */   423,  370,  423,  372,  423,  373,  423,  374,  423,  375,
 /*    40 */   423,  376,  423,  377,  423,  378,  423,  379,  423,  380,
 /*    50 */   423,  381,  423,  382,  423,  383,  423,  384,  423,  385,
 /*    60 */   423,  386,  423,  387,  423,  423,  388,  423,  389,  423,
 /*    70 */   423,  402,  423,  393,  423,  403,  423,  404,  423,  406,
 /*    80 */   423,  423,  423,  423,  423,  394,  423,  423,  423,  423,
 /*    90 */   423,  395,  396,  421,  423,  423,  397,  423,  399,  401,
 /*   100 */   423,  405,  423,  407,  423,  408,  423,  423,  409,  410,
 /*   110 */   411,  412,  413,  414,  415,  416,  417,  418,  419,  398,
 /*   120 */   400,  423,  420,  423,  422,  423,  391,  423,  390,  423,
 /*   130 */   423,  423,  392,  371,  357,  423,  423,  423,  423,  365,
 /*   140 */   423,  423,  423,  361,  423,  362,  364,  363,  423,  423,
 /*   150 */   423,  423,  423,  423,  423,  423,  423,  423,  423,  423,
 /*   160 */   354,  423,  423,  423,  296,  297,  308,  310,  423,  311,
 /*   170 */   312,  314,  423,  326,  313,  423,  315,  316,  352,  353,
 /*   180 */   421,  423,  423,  423,  423,  423,  423,  423,  423,  423,
 /*   190 */   423,  423,  423,  423,  423,  423,  423,  423,  423,  306,
 /*   200 */   351,  423,  349,  350,  309,  307,  423,  298,  300,  421,
 /*   210 */   423,  301,  411,  423,  302,  305,  423,  303,  304,  299,
 /*   220 */   423,  423,  423,  423,  423,  423,  423,  423,  329,  331,
 /*   230 */   330,  423,  423,  423,  423,  423,  423,  423,  423,  332,
 /*   240 */   334,  333,  423,  423,  423,  423,  423,  423,  423,  423,
 /*   250 */   423,  339,  423,  340,  423,  423,  342,  343,  423,  341,
 /*   260 */   423,  423,  423,  423,  423,  423,  348,
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
  "INTEGER",       "OFFSET",        "CAST",          "CONVERT",     
  "USING",         "NULL",          "STRING",        "DOUBLE",      
  "TRUE",          "FALSE",         "NPLACEHOLDER",  "SPLACEHOLDER",
  "COLON",         "error",         "program",       "query_language",
  "select_statement",  "insert_statement",  "update_statement",  "delete_statement",
  "select_clause",  "where_clause",  "order_clause",  "group_clause",
  "having_clause",  "select_limit_clause",  "column_list",   "associated_name_list",
  "join_list",     "column_item",   "aliased_name",  "expr",        
  "associated_name",  "join_item",     "join_clause",   "join_type",   
  "aliased_or_qualified_name",  "join_associated_name",  "join_conditions",  "values_list", 
  "field_list",    "value_list",    "value_item",    "field_item",  
  "update_clause",  "limit_clause",  "update_item_list",  "update_item", 
  "qualified_name",  "new_value",     "delete_clause",  "order_list",  
  "order_item",    "group_list",    "group_item",    "argument_list",
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
 /*  35 */ "column_item ::= aliased_name DOT TIMES",
 /*  36 */ "column_item ::= expr AS IDENTIFIER",
 /*  37 */ "column_item ::= expr IDENTIFIER",
 /*  38 */ "column_item ::= expr",
 /*  39 */ "associated_name_list ::= associated_name_list COMMA associated_name",
 /*  40 */ "associated_name_list ::= associated_name",
 /*  41 */ "join_list ::= join_list join_item",
 /*  42 */ "join_list ::= join_item",
 /*  43 */ "join_item ::= join_clause",
 /*  44 */ "join_clause ::= join_type aliased_or_qualified_name",
 /*  45 */ "join_clause ::= join_type aliased_or_qualified_name join_associated_name",
 /*  46 */ "join_clause ::= join_type aliased_or_qualified_name join_conditions",
 /*  47 */ "join_clause ::= join_type aliased_or_qualified_name join_associated_name join_conditions",
 /*  48 */ "join_associated_name ::= AS IDENTIFIER",
 /*  49 */ "join_associated_name ::= IDENTIFIER",
 /*  50 */ "join_type ::= JOIN",
 /*  51 */ "join_type ::= INNER JOIN",
 /*  52 */ "join_type ::= CROSS JOIN",
 /*  53 */ "join_type ::= LEFT JOIN",
 /*  54 */ "join_type ::= LEFT OUTER JOIN",
 /*  55 */ "join_type ::= RIGHT JOIN",
 /*  56 */ "join_type ::= RIGHT OUTER JOIN",
 /*  57 */ "join_type ::= FULL JOIN",
 /*  58 */ "join_type ::= FULL OUTER JOIN",
 /*  59 */ "join_conditions ::= ON expr",
 /*  60 */ "insert_statement ::= INSERT INTO aliased_or_qualified_name VALUES PARENTHESES_OPEN values_list PARENTHESES_CLOSE",
 /*  61 */ "insert_statement ::= INSERT INTO aliased_or_qualified_name PARENTHESES_OPEN field_list PARENTHESES_CLOSE VALUES PARENTHESES_OPEN values_list PARENTHESES_CLOSE",
 /*  62 */ "values_list ::= values_list COMMA value_item",
 /*  63 */ "values_list ::= value_item",
 /*  64 */ "value_item ::= expr",
 /*  65 */ "field_list ::= field_list COMMA field_item",
 /*  66 */ "field_list ::= field_item",
 /*  67 */ "field_item ::= IDENTIFIER",
 /*  68 */ "update_statement ::= update_clause",
 /*  69 */ "update_statement ::= update_clause where_clause",
 /*  70 */ "update_statement ::= update_clause limit_clause",
 /*  71 */ "update_statement ::= update_clause where_clause limit_clause",
 /*  72 */ "update_clause ::= UPDATE associated_name SET update_item_list",
 /*  73 */ "update_item_list ::= update_item_list COMMA update_item",
 /*  74 */ "update_item_list ::= update_item",
 /*  75 */ "update_item ::= qualified_name EQUALS new_value",
 /*  76 */ "new_value ::= expr",
 /*  77 */ "delete_statement ::= delete_clause",
 /*  78 */ "delete_statement ::= delete_clause where_clause",
 /*  79 */ "delete_statement ::= delete_clause limit_clause",
 /*  80 */ "delete_statement ::= delete_clause where_clause limit_clause",
 /*  81 */ "delete_clause ::= DELETE FROM associated_name",
 /*  82 */ "associated_name ::= aliased_or_qualified_name AS IDENTIFIER",
 /*  83 */ "associated_name ::= aliased_or_qualified_name IDENTIFIER",
 /*  84 */ "associated_name ::= aliased_or_qualified_name",
 /*  85 */ "aliased_or_qualified_name ::= qualified_name",
 /*  86 */ "aliased_or_qualified_name ::= aliased_name",
 /*  87 */ "where_clause ::= WHERE expr",
 /*  88 */ "order_clause ::= ORDER BY order_list",
 /*  89 */ "order_list ::= order_list COMMA order_item",
 /*  90 */ "order_list ::= order_item",
 /*  91 */ "order_item ::= expr",
 /*  92 */ "order_item ::= expr ASC",
 /*  93 */ "order_item ::= expr DESC",
 /*  94 */ "group_clause ::= GROUP BY group_list",
 /*  95 */ "group_list ::= group_list COMMA group_item",
 /*  96 */ "group_list ::= group_item",
 /*  97 */ "group_item ::= expr",
 /*  98 */ "having_clause ::= HAVING expr",
 /*  99 */ "select_limit_clause ::= LIMIT INTEGER",
 /* 100 */ "select_limit_clause ::= LIMIT INTEGER COMMA INTEGER",
 /* 101 */ "select_limit_clause ::= LIMIT INTEGER OFFSET INTEGER",
 /* 102 */ "limit_clause ::= LIMIT INTEGER",
 /* 103 */ "expr ::= MINUS expr",
 /* 104 */ "expr ::= expr MINUS expr",
 /* 105 */ "expr ::= expr PLUS expr",
 /* 106 */ "expr ::= expr TIMES expr",
 /* 107 */ "expr ::= expr DIVIDE expr",
 /* 108 */ "expr ::= expr MOD expr",
 /* 109 */ "expr ::= expr AND expr",
 /* 110 */ "expr ::= expr OR expr",
 /* 111 */ "expr ::= expr BITWISE_AND expr",
 /* 112 */ "expr ::= expr BITWISE_OR expr",
 /* 113 */ "expr ::= expr BITWISE_XOR expr",
 /* 114 */ "expr ::= expr EQUALS expr",
 /* 115 */ "expr ::= expr NOTEQUALS expr",
 /* 116 */ "expr ::= expr LESS expr",
 /* 117 */ "expr ::= expr GREATER expr",
 /* 118 */ "expr ::= expr GREATEREQUAL expr",
 /* 119 */ "expr ::= expr LESSEQUAL expr",
 /* 120 */ "expr ::= expr LIKE expr",
 /* 121 */ "expr ::= expr NOT LIKE expr",
 /* 122 */ "expr ::= expr ILIKE expr",
 /* 123 */ "expr ::= expr NOT ILIKE expr",
 /* 124 */ "expr ::= expr IN PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 125 */ "expr ::= expr NOT IN PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 126 */ "expr ::= expr AGAINST expr",
 /* 127 */ "expr ::= CAST PARENTHESES_OPEN expr AS IDENTIFIER PARENTHESES_CLOSE",
 /* 128 */ "expr ::= CONVERT PARENTHESES_OPEN expr USING IDENTIFIER PARENTHESES_CLOSE",
 /* 129 */ "expr ::= function_call",
 /* 130 */ "function_call ::= IDENTIFIER PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 131 */ "function_call ::= IDENTIFIER PARENTHESES_OPEN PARENTHESES_CLOSE",
 /* 132 */ "argument_list ::= argument_list COMMA argument_item",
 /* 133 */ "argument_list ::= argument_item",
 /* 134 */ "argument_item ::= TIMES",
 /* 135 */ "argument_item ::= expr",
 /* 136 */ "expr ::= expr IS NULL",
 /* 137 */ "expr ::= expr IS NOT NULL",
 /* 138 */ "expr ::= DISTINCT expr",
 /* 139 */ "expr ::= expr BETWEEN expr",
 /* 140 */ "expr ::= NOT expr",
 /* 141 */ "expr ::= BITWISE_NOT expr",
 /* 142 */ "expr ::= PARENTHESES_OPEN expr PARENTHESES_CLOSE",
 /* 143 */ "expr ::= qualified_name",
 /* 144 */ "expr ::= aliased_name",
 /* 145 */ "expr ::= INTEGER",
 /* 146 */ "expr ::= STRING",
 /* 147 */ "expr ::= DOUBLE",
 /* 148 */ "expr ::= NULL",
 /* 149 */ "expr ::= TRUE",
 /* 150 */ "expr ::= FALSE",
 /* 151 */ "expr ::= NPLACEHOLDER",
 /* 152 */ "expr ::= SPLACEHOLDER",
 /* 153 */ "qualified_name ::= IDENTIFIER DOT IDENTIFIER",
 /* 154 */ "qualified_name ::= IDENTIFIER",
 /* 155 */ "aliased_name ::= IDENTIFIER COLON IDENTIFIER",
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
// 523 "parser.lemon"
{
	if ((yypminor->yy0)) {
		if ((yypminor->yy0)->free_flag) {
			efree((yypminor->yy0)->token);
		}
		efree((yypminor->yy0));
	}
}
// 1203 "parser.c"
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
    case 94:
    case 96:
    case 97:
    case 99:
    case 100:
    case 101:
    case 102:
    case 103:
    case 104:
    case 106:
    case 107:
    case 108:
    case 109:
    case 110:
    case 111:
    case 112:
    case 113:
// 536 "parser.lemon"
{ zval_ptr_dtor(&(yypminor->yy48)); }
// 1247 "parser.c"
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
  { 85, 3 },
  { 85, 2 },
  { 85, 1 },
  { 83, 3 },
  { 83, 1 },
  { 84, 2 },
  { 84, 1 },
  { 89, 1 },
  { 90, 2 },
  { 90, 3 },
  { 90, 3 },
  { 90, 4 },
  { 93, 2 },
  { 93, 1 },
  { 91, 1 },
  { 91, 2 },
  { 91, 2 },
  { 91, 2 },
  { 91, 3 },
  { 91, 2 },
  { 91, 3 },
  { 91, 2 },
  { 91, 3 },
  { 94, 2 },
  { 73, 7 },
  { 73, 10 },
  { 95, 3 },
  { 95, 1 },
  { 98, 1 },
  { 96, 3 },
  { 96, 1 },
  { 99, 1 },
  { 74, 1 },
  { 74, 2 },
  { 74, 2 },
  { 74, 3 },
  { 100, 4 },
  { 102, 3 },
  { 102, 1 },
  { 103, 3 },
  { 105, 1 },
  { 75, 1 },
  { 75, 2 },
  { 75, 2 },
  { 75, 3 },
  { 106, 3 },
  { 88, 3 },
  { 88, 2 },
  { 88, 1 },
  { 92, 1 },
  { 92, 1 },
  { 77, 2 },
  { 78, 3 },
  { 107, 3 },
  { 107, 1 },
  { 108, 1 },
  { 108, 2 },
  { 108, 2 },
  { 79, 3 },
  { 109, 3 },
  { 109, 1 },
  { 110, 1 },
  { 80, 2 },
  { 81, 2 },
  { 81, 4 },
  { 81, 4 },
  { 101, 2 },
  { 87, 2 },
  { 87, 3 },
  { 87, 3 },
  { 87, 3 },
  { 87, 3 },
  { 87, 3 },
  { 87, 3 },
  { 87, 3 },
  { 87, 3 },
  { 87, 3 },
  { 87, 3 },
  { 87, 3 },
  { 87, 3 },
  { 87, 3 },
  { 87, 3 },
  { 87, 3 },
  { 87, 3 },
  { 87, 3 },
  { 87, 4 },
  { 87, 3 },
  { 87, 4 },
  { 87, 5 },
  { 87, 6 },
  { 87, 3 },
  { 87, 6 },
  { 87, 6 },
  { 87, 1 },
  { 112, 4 },
  { 112, 3 },
  { 111, 3 },
  { 111, 1 },
  { 113, 1 },
  { 113, 1 },
  { 87, 3 },
  { 87, 4 },
  { 87, 2 },
  { 87, 3 },
  { 87, 2 },
  { 87, 2 },
  { 87, 3 },
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
  { 104, 3 },
  { 104, 1 },
  { 86, 3 },
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
// 532 "parser.lemon"
{
	status->ret = yymsp[0].minor.yy48;
}
// 1620 "parser.c"
        break;
      case 1:
      case 2:
      case 3:
      case 4:
      case 32:
      case 40:
      case 42:
      case 43:
      case 63:
      case 64:
      case 66:
      case 74:
      case 76:
      case 85:
      case 86:
      case 90:
      case 96:
      case 97:
      case 129:
      case 135:
      case 143:
      case 144:
// 538 "parser.lemon"
{
	yygotominor.yy48 = yymsp[0].minor.yy48;
}
// 1648 "parser.c"
        break;
      case 5:
// 556 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[0].minor.yy48, NULL, NULL, NULL, NULL, NULL);
}
// 1655 "parser.c"
        break;
      case 6:
// 560 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL, NULL, NULL, NULL);
}
// 1662 "parser.c"
        break;
      case 7:
// 564 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL, NULL, NULL);
}
// 1669 "parser.c"
        break;
      case 8:
// 568 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy48, NULL, NULL);
}
// 1676 "parser.c"
        break;
      case 9:
// 572 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, yymsp[-2].minor.yy48, NULL, yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL);
}
// 1683 "parser.c"
        break;
      case 10:
// 576 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, yymsp[-2].minor.yy48, yymsp[0].minor.yy48, yymsp[-1].minor.yy48, NULL, NULL);
}
// 1690 "parser.c"
        break;
      case 11:
// 580 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-4].minor.yy48, yymsp[-3].minor.yy48, yymsp[-1].minor.yy48, yymsp[-2].minor.yy48, NULL, yymsp[0].minor.yy48);
}
// 1697 "parser.c"
        break;
      case 12:
// 584 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-4].minor.yy48, yymsp[-3].minor.yy48, yymsp[0].minor.yy48, yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, NULL);
}
// 1704 "parser.c"
        break;
      case 13:
// 588 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, NULL, NULL, NULL, yymsp[0].minor.yy48);
}
// 1711 "parser.c"
        break;
      case 14:
// 592 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, NULL, NULL, yymsp[0].minor.yy48);
}
// 1718 "parser.c"
        break;
      case 15:
// 596 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, yymsp[-2].minor.yy48, NULL, yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy48);
}
// 1725 "parser.c"
        break;
      case 16:
// 600 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-4].minor.yy48, yymsp[-3].minor.yy48, NULL, yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
}
// 1732 "parser.c"
        break;
      case 17:
// 604 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy48, NULL, NULL, NULL);
}
// 1739 "parser.c"
        break;
      case 18:
// 608 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-2].minor.yy48, NULL, yymsp[0].minor.yy48, yymsp[-1].minor.yy48, NULL, NULL);
}
// 1746 "parser.c"
        break;
      case 19:
// 612 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, NULL, yymsp[0].minor.yy48, yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, NULL);
}
// 1753 "parser.c"
        break;
      case 20:
// 616 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-2].minor.yy48, NULL, yymsp[-1].minor.yy48, NULL, NULL, yymsp[0].minor.yy48);
}
// 1760 "parser.c"
        break;
      case 21:
// 620 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, NULL, yymsp[-1].minor.yy48, yymsp[-2].minor.yy48, NULL, yymsp[0].minor.yy48);
}
// 1767 "parser.c"
        break;
      case 22:
// 624 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-5].minor.yy48, yymsp[-4].minor.yy48, yymsp[-1].minor.yy48, yymsp[-3].minor.yy48, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
}
// 1774 "parser.c"
        break;
      case 23:
// 628 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-1].minor.yy48, NULL, NULL, yymsp[0].minor.yy48, NULL, NULL);
}
// 1781 "parser.c"
        break;
      case 24:
// 632 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-2].minor.yy48, NULL, NULL, yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy48);
}
// 1788 "parser.c"
        break;
      case 25:
// 636 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-2].minor.yy48, NULL, NULL, yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL);
}
// 1795 "parser.c"
        break;
      case 26:
// 640 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, NULL, NULL, yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
}
// 1802 "parser.c"
        break;
      case 27:
// 644 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-4].minor.yy48, NULL, yymsp[-1].minor.yy48, yymsp[-3].minor.yy48, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
}
// 1809 "parser.c"
        break;
      case 28:
// 648 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-1].minor.yy48, NULL, NULL, NULL, NULL, yymsp[0].minor.yy48);
}
// 1816 "parser.c"
        break;
      case 29:
// 654 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_clause(yymsp[-2].minor.yy48, yymsp[0].minor.yy48, NULL);
  yy_destructor(26,&yymsp[-3].minor);
  yy_destructor(27,&yymsp[-1].minor);
}
// 1825 "parser.c"
        break;
      case 30:
// 658 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_clause(yymsp[-3].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(26,&yymsp[-4].minor);
  yy_destructor(27,&yymsp[-2].minor);
}
// 1834 "parser.c"
        break;
      case 31:
      case 39:
      case 62:
      case 65:
      case 73:
      case 89:
      case 95:
      case 132:
// 664 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_zval_list(yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(28,&yymsp[-1].minor);
}
// 1849 "parser.c"
        break;
      case 33:
      case 134:
// 674 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_column_item(PHQL_T_ALL, NULL, NULL, NULL);
  yy_destructor(17,&yymsp[0].minor);
}
// 1858 "parser.c"
        break;
      case 34:
// 678 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_column_item(PHQL_T_DOMAINALL, NULL, yymsp[-2].minor.yy0, NULL);
  yy_destructor(30,&yymsp[-1].minor);
  yy_destructor(17,&yymsp[0].minor);
}
// 1867 "parser.c"
        break;
      case 35:
// 682 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_column_item(PHQL_T_DOMAINALL, yymsp[-2].minor.yy48, NULL, NULL);
  yy_destructor(30,&yymsp[-1].minor);
  yy_destructor(17,&yymsp[0].minor);
}
// 1876 "parser.c"
        break;
      case 36:
// 686 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-2].minor.yy48, NULL, yymsp[0].minor.yy0);
  yy_destructor(31,&yymsp[-1].minor);
}
// 1884 "parser.c"
        break;
      case 37:
// 690 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy0);
}
// 1891 "parser.c"
        break;
      case 38:
// 694 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_column_item(PHQL_T_EXPR, yymsp[0].minor.yy48, NULL, NULL);
}
// 1898 "parser.c"
        break;
      case 41:
// 710 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_zval_list(yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
}
// 1905 "parser.c"
        break;
      case 44:
// 727 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_item(yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL, NULL);
}
// 1912 "parser.c"
        break;
      case 45:
// 732 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_item(yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL);
}
// 1919 "parser.c"
        break;
      case 46:
// 737 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_item(yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy48);
}
// 1926 "parser.c"
        break;
      case 47:
// 742 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_item(yymsp[-3].minor.yy48, yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
}
// 1933 "parser.c"
        break;
      case 48:
// 748 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_qualified_name(yymsp[0].minor.yy0, NULL);
  yy_destructor(31,&yymsp[-1].minor);
}
// 1941 "parser.c"
        break;
      case 49:
      case 67:
      case 154:
// 752 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_qualified_name(yymsp[0].minor.yy0, NULL);
}
// 1950 "parser.c"
        break;
      case 50:
// 758 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_INNERJOIN);
  yy_destructor(32,&yymsp[0].minor);
}
// 1958 "parser.c"
        break;
      case 51:
// 762 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_INNERJOIN);
  yy_destructor(33,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 1967 "parser.c"
        break;
      case 52:
// 766 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_CROSSJOIN);
  yy_destructor(34,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 1976 "parser.c"
        break;
      case 53:
// 770 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  yy_destructor(35,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 1985 "parser.c"
        break;
      case 54:
// 774 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 1995 "parser.c"
        break;
      case 55:
// 778 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  yy_destructor(37,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 2004 "parser.c"
        break;
      case 56:
// 782 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  yy_destructor(37,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 2014 "parser.c"
        break;
      case 57:
// 786 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_FULLJOIN);
  yy_destructor(38,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 2023 "parser.c"
        break;
      case 58:
// 790 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_FULLJOIN);
  yy_destructor(38,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 2033 "parser.c"
        break;
      case 59:
// 796 "parser.lemon"
{
	yygotominor.yy48 = yymsp[0].minor.yy48;
  yy_destructor(39,&yymsp[-1].minor);
}
// 2041 "parser.c"
        break;
      case 60:
// 803 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_insert_statement(yymsp[-4].minor.yy48, NULL, yymsp[-1].minor.yy48);
  yy_destructor(40,&yymsp[-6].minor);
  yy_destructor(41,&yymsp[-5].minor);
  yy_destructor(42,&yymsp[-3].minor);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2053 "parser.c"
        break;
      case 61:
// 807 "parser.lemon"
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
// 2067 "parser.c"
        break;
      case 68:
// 845 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_update_statement(yymsp[0].minor.yy48, NULL, NULL);
}
// 2074 "parser.c"
        break;
      case 69:
// 849 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_update_statement(yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL);
}
// 2081 "parser.c"
        break;
      case 70:
// 853 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_update_statement(yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy48);
}
// 2088 "parser.c"
        break;
      case 71:
// 857 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_update_statement(yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
}
// 2095 "parser.c"
        break;
      case 72:
// 863 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_update_clause(yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(45,&yymsp[-3].minor);
  yy_destructor(46,&yymsp[-1].minor);
}
// 2104 "parser.c"
        break;
      case 75:
// 879 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_update_item(yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(3,&yymsp[-1].minor);
}
// 2112 "parser.c"
        break;
      case 77:
// 891 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_delete_statement(yymsp[0].minor.yy48, NULL, NULL);
}
// 2119 "parser.c"
        break;
      case 78:
// 895 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_delete_statement(yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL);
}
// 2126 "parser.c"
        break;
      case 79:
// 899 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_delete_statement(yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy48);
}
// 2133 "parser.c"
        break;
      case 80:
// 903 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_delete_statement(yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
}
// 2140 "parser.c"
        break;
      case 81:
// 909 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_delete_clause(yymsp[0].minor.yy48);
  yy_destructor(47,&yymsp[-2].minor);
  yy_destructor(27,&yymsp[-1].minor);
}
// 2149 "parser.c"
        break;
      case 82:
// 915 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_assoc_name(yymsp[-2].minor.yy48, yymsp[0].minor.yy0);
  yy_destructor(31,&yymsp[-1].minor);
}
// 2157 "parser.c"
        break;
      case 83:
// 919 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_assoc_name(yymsp[-1].minor.yy48, yymsp[0].minor.yy0);
}
// 2164 "parser.c"
        break;
      case 84:
// 923 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_assoc_name(yymsp[0].minor.yy48, NULL);
}
// 2171 "parser.c"
        break;
      case 87:
// 939 "parser.lemon"
{
	yygotominor.yy48 = yymsp[0].minor.yy48;
  yy_destructor(48,&yymsp[-1].minor);
}
// 2179 "parser.c"
        break;
      case 88:
// 945 "parser.lemon"
{
	yygotominor.yy48 = yymsp[0].minor.yy48;
  yy_destructor(49,&yymsp[-2].minor);
  yy_destructor(50,&yymsp[-1].minor);
}
// 2188 "parser.c"
        break;
      case 91:
// 961 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_order_item(yymsp[0].minor.yy48, 0);
}
// 2195 "parser.c"
        break;
      case 92:
// 965 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_order_item(yymsp[-1].minor.yy48, PHQL_T_ASC);
  yy_destructor(51,&yymsp[0].minor);
}
// 2203 "parser.c"
        break;
      case 93:
// 969 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_order_item(yymsp[-1].minor.yy48, PHQL_T_DESC);
  yy_destructor(52,&yymsp[0].minor);
}
// 2211 "parser.c"
        break;
      case 94:
// 975 "parser.lemon"
{
	yygotominor.yy48 = yymsp[0].minor.yy48;
  yy_destructor(53,&yymsp[-2].minor);
  yy_destructor(50,&yymsp[-1].minor);
}
// 2220 "parser.c"
        break;
      case 98:
// 997 "parser.lemon"
{
	yygotominor.yy48 = yymsp[0].minor.yy48;
  yy_destructor(54,&yymsp[-1].minor);
}
// 2228 "parser.c"
        break;
      case 99:
      case 102:
// 1003 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_limit_clause(yymsp[0].minor.yy0, NULL);
  yy_destructor(55,&yymsp[-1].minor);
}
// 2237 "parser.c"
        break;
      case 100:
// 1007 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_limit_clause(yymsp[0].minor.yy0, yymsp[-2].minor.yy0);
  yy_destructor(55,&yymsp[-3].minor);
  yy_destructor(28,&yymsp[-1].minor);
}
// 2246 "parser.c"
        break;
      case 101:
// 1011 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_limit_clause(yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(55,&yymsp[-3].minor);
  yy_destructor(57,&yymsp[-1].minor);
}
// 2255 "parser.c"
        break;
      case 103:
// 1023 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_MINUS, NULL, yymsp[0].minor.yy48);
  yy_destructor(20,&yymsp[-1].minor);
}
// 2263 "parser.c"
        break;
      case 104:
// 1027 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_SUB, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(20,&yymsp[-1].minor);
}
// 2271 "parser.c"
        break;
      case 105:
// 1031 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_ADD, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(19,&yymsp[-1].minor);
}
// 2279 "parser.c"
        break;
      case 106:
// 1035 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_MUL, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(17,&yymsp[-1].minor);
}
// 2287 "parser.c"
        break;
      case 107:
// 1039 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_DIV, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(16,&yymsp[-1].minor);
}
// 2295 "parser.c"
        break;
      case 108:
// 1043 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_MOD, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(18,&yymsp[-1].minor);
}
// 2303 "parser.c"
        break;
      case 109:
// 1047 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_AND, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(9,&yymsp[-1].minor);
}
// 2311 "parser.c"
        break;
      case 110:
// 1051 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_OR, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(10,&yymsp[-1].minor);
}
// 2319 "parser.c"
        break;
      case 111:
// 1055 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_BITWISE_AND, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(13,&yymsp[-1].minor);
}
// 2327 "parser.c"
        break;
      case 112:
// 1059 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_BITWISE_OR, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(14,&yymsp[-1].minor);
}
// 2335 "parser.c"
        break;
      case 113:
// 1063 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_BITWISE_XOR, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(15,&yymsp[-1].minor);
}
// 2343 "parser.c"
        break;
      case 114:
// 1067 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_EQUALS, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(3,&yymsp[-1].minor);
}
// 2351 "parser.c"
        break;
      case 115:
// 1071 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_NOTEQUALS, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(4,&yymsp[-1].minor);
}
// 2359 "parser.c"
        break;
      case 116:
// 1075 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_LESS, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(5,&yymsp[-1].minor);
}
// 2367 "parser.c"
        break;
      case 117:
// 1079 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_GREATER, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(6,&yymsp[-1].minor);
}
// 2375 "parser.c"
        break;
      case 118:
// 1083 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_GREATEREQUAL, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(7,&yymsp[-1].minor);
}
// 2383 "parser.c"
        break;
      case 119:
// 1087 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_LESSEQUAL, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(8,&yymsp[-1].minor);
}
// 2391 "parser.c"
        break;
      case 120:
// 1091 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_LIKE, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(11,&yymsp[-1].minor);
}
// 2399 "parser.c"
        break;
      case 121:
// 1095 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_NLIKE, yymsp[-3].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(24,&yymsp[-2].minor);
  yy_destructor(11,&yymsp[-1].minor);
}
// 2408 "parser.c"
        break;
      case 122:
// 1099 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_ILIKE, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(12,&yymsp[-1].minor);
}
// 2416 "parser.c"
        break;
      case 123:
// 1103 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_NILIKE, yymsp[-3].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(24,&yymsp[-2].minor);
  yy_destructor(12,&yymsp[-1].minor);
}
// 2425 "parser.c"
        break;
      case 124:
// 1107 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_IN, yymsp[-4].minor.yy48, yymsp[-1].minor.yy48);
  yy_destructor(22,&yymsp[-3].minor);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2435 "parser.c"
        break;
      case 125:
// 1111 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_NOTIN, yymsp[-5].minor.yy48, yymsp[-1].minor.yy48);
  yy_destructor(24,&yymsp[-4].minor);
  yy_destructor(22,&yymsp[-3].minor);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2446 "parser.c"
        break;
      case 126:
// 1115 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_AGAINST, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(1,&yymsp[-1].minor);
}
// 2454 "parser.c"
        break;
      case 127:
// 1119 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_CAST, yymsp[-3].minor.yy48, phql_ret_raw_qualified_name(yymsp[-1].minor.yy0, NULL));
  yy_destructor(58,&yymsp[-5].minor);
  yy_destructor(43,&yymsp[-4].minor);
  yy_destructor(31,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2465 "parser.c"
        break;
      case 128:
// 1123 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_CONVERT, yymsp[-3].minor.yy48, phql_ret_raw_qualified_name(yymsp[-1].minor.yy0, NULL));
  yy_destructor(59,&yymsp[-5].minor);
  yy_destructor(43,&yymsp[-4].minor);
  yy_destructor(60,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2476 "parser.c"
        break;
      case 130:
// 1133 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_func_call(yymsp[-3].minor.yy0, yymsp[-1].minor.yy48);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2485 "parser.c"
        break;
      case 131:
// 1137 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_func_call(yymsp[-2].minor.yy0, NULL);
  yy_destructor(43,&yymsp[-1].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2494 "parser.c"
        break;
      case 133:
// 1147 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_zval_list(yymsp[0].minor.yy48, NULL);
}
// 2501 "parser.c"
        break;
      case 136:
// 1161 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_ISNULL, yymsp[-2].minor.yy48, NULL);
  yy_destructor(21,&yymsp[-1].minor);
  yy_destructor(61,&yymsp[0].minor);
}
// 2510 "parser.c"
        break;
      case 137:
// 1165 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_ISNOTNULL, yymsp[-3].minor.yy48, NULL);
  yy_destructor(21,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
  yy_destructor(61,&yymsp[0].minor);
}
// 2520 "parser.c"
        break;
      case 138:
// 1169 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_DISTINCT, NULL, yymsp[0].minor.yy48);
  yy_destructor(23,&yymsp[-1].minor);
}
// 2528 "parser.c"
        break;
      case 139:
// 1173 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_BETWEEN, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(2,&yymsp[-1].minor);
}
// 2536 "parser.c"
        break;
      case 140:
// 1177 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_NOT, NULL, yymsp[0].minor.yy48);
  yy_destructor(24,&yymsp[-1].minor);
}
// 2544 "parser.c"
        break;
      case 141:
// 1181 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_BITWISE_NOT, NULL, yymsp[0].minor.yy48);
  yy_destructor(25,&yymsp[-1].minor);
}
// 2552 "parser.c"
        break;
      case 142:
// 1185 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_ENCLOSED, yymsp[-1].minor.yy48, NULL);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2561 "parser.c"
        break;
      case 145:
// 1197 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_literal_zval(PHQL_T_INTEGER, yymsp[0].minor.yy0);
}
// 2568 "parser.c"
        break;
      case 146:
// 1201 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_literal_zval(PHQL_T_STRING, yymsp[0].minor.yy0);
}
// 2575 "parser.c"
        break;
      case 147:
// 1205 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_literal_zval(PHQL_T_DOUBLE, yymsp[0].minor.yy0);
}
// 2582 "parser.c"
        break;
      case 148:
// 1209 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_literal_zval(PHQL_T_NULL, NULL);
  yy_destructor(61,&yymsp[0].minor);
}
// 2590 "parser.c"
        break;
      case 149:
// 1213 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_literal_zval(PHQL_T_TRUE, NULL);
  yy_destructor(64,&yymsp[0].minor);
}
// 2598 "parser.c"
        break;
      case 150:
// 1217 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_literal_zval(PHQL_T_FALSE, NULL);
  yy_destructor(65,&yymsp[0].minor);
}
// 2606 "parser.c"
        break;
      case 151:
// 1221 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_placeholder_zval(PHQL_T_NPLACEHOLDER, yymsp[0].minor.yy0);
}
// 2613 "parser.c"
        break;
      case 152:
// 1225 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_placeholder_zval(PHQL_T_SPLACEHOLDER, yymsp[0].minor.yy0);
}
// 2620 "parser.c"
        break;
      case 153:
// 1231 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_qualified_name(yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(30,&yymsp[-1].minor);
}
// 2628 "parser.c"
        break;
      case 155:
// 1241 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_aliased_name(yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(68,&yymsp[-1].minor);
}
// 2636 "parser.c"
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
// 456 "parser.lemon"

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

// 2745 "parser.c"
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
  { PHQL_T_INTEGER,       SL("INTEGER") },
  { PHQL_T_DOUBLE,        SL("DOUBLE") },
  { PHQL_T_STRING,        SL("STRING") },
  { PHQL_T_IDENTIFIER,    SL("IDENTIFIER") },
  { PHQL_T_MINUS,         SL("MINUS") },
  { PHQL_T_ADD,           SL("+") },
  { PHQL_T_SUB,           SL("-") },
  { PHQL_T_MUL,           SL("*") },
  { PHQL_T_DIV,           SL("/") },
  { PHQL_T_BITWISE_AND,   SL("&") },
  { PHQL_T_BITWISE_OR,    SL("|") },
  { PHQL_T_MOD,           SL("%%") },
  { PHQL_T_AND,           SL("AND") },
  { PHQL_T_OR,            SL("OR") },
  { PHQL_T_LIKE,          SL("LIKE") },
  { PHQL_T_ILIKE,         SL("ILIKE") },
  { PHQL_T_DOT,           SL("DOT") },
  { PHQL_T_COLON,         SL("COLON") },
  { PHQL_T_COMMA,         SL("COMMA") },
  { PHQL_T_EQUALS,        SL("EQUALS") },
  { PHQL_T_NOTEQUALS,     SL("NOT EQUALS") },
  { PHQL_T_NOT,           SL("NOT") },
  { PHQL_T_LESS,          SL("<") },
  { PHQL_T_LESSEQUAL,     SL("<=") },
  { PHQL_T_GREATER,       SL(">") },
  { PHQL_T_GREATEREQUAL,  SL(">=") },
  { PHQL_T_PARENTHESES_OPEN,  SL("(") },
  { PHQL_T_PARENTHESES_CLOSE, SL(")") },
  { PHQL_T_NPLACEHOLDER,  SL("NUMERIC PLACEHOLDER") },
  { PHQL_T_SPLACEHOLDER,  SL("STRING PLACEHOLDER") },
  { PHQL_T_UPDATE,        SL("UPDATE") },
  { PHQL_T_SET,           SL("SET") },
  { PHQL_T_WHERE,         SL("WHERE") },
  { PHQL_T_DELETE,        SL("DELETE") },
  { PHQL_T_FROM,          SL("FROM") },
  { PHQL_T_AS,            SL("AS") },
  { PHQL_T_INSERT,        SL("INSERT") },
  { PHQL_T_INTO,          SL("INTO") },
  { PHQL_T_VALUES,        SL("VALUES") },
  { PHQL_T_SELECT,        SL("SELECT") },
  { PHQL_T_ORDER,         SL("ORDER") },
  { PHQL_T_BY,            SL("BY") },
  { PHQL_T_LIMIT,         SL("LIMIT") },
  { PHQL_T_OFFSET,        SL("OFFSET") },
  { PHQL_T_GROUP,         SL("GROUP") },
  { PHQL_T_HAVING,        SL("HAVING") },
  { PHQL_T_IN,            SL("IN") },
  { PHQL_T_ON,            SL("ON") },
  { PHQL_T_INNER,         SL("INNER") },
  { PHQL_T_JOIN,          SL("JOIN") },
  { PHQL_T_LEFT,          SL("LEFT") },
  { PHQL_T_RIGHT,         SL("RIGHT") },
  { PHQL_T_IS,            SL("IS") },
  { PHQL_T_NULL,          SL("NULL") },
  { PHQL_T_NOTIN,         SL("NOT IN") },
  { PHQL_T_CROSS,         SL("CROSS") },
  { PHQL_T_OUTER,         SL("OUTER") },
  { PHQL_T_FULL,          SL("FULL") },
  { PHQL_T_ASC,           SL("ASC") },
  { PHQL_T_DESC,          SL("DESC") },
  { PHQL_T_BETWEEN,       SL("BETWEEN") },
  { PHQL_T_DISTINCT,      SL("DISTINCT") },
  { PHQL_T_AGAINST,       SL("AGAINST") },
  { PHQL_T_CAST,          SL("CAST") },
  { PHQL_T_CONVERT,       SL("CONVERT") },
  { PHQL_T_USING,         SL("USING") },
  { 0, NULL, 0 }
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
		phalcon_throw_exception_string(phalcon_mvc_model_exception_ce, Z_STRVAL_P(error_msg), Z_STRLEN_P(error_msg), 1 TSRMLS_CC);
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
	unsigned long phql_key;
	void* phql_parser;
	char *error;
	zval **temp_ast;

	if (!phql) {
		PHALCON_INIT_VAR(*error_msg);
		ZVAL_STRING(*error_msg, "PHQL statement cannot be NULL", 1);
		return FAILURE;
	}

	if (phalcon_globals_ptr->orm.cache_level >= 0) {

		phql_key = zend_inline_hash_func(phql, phql_length + 1);

		if (phalcon_globals_ptr->orm.parser_cache != NULL) {
			if (zend_hash_quick_find(phalcon_globals_ptr->orm.parser_cache, phql, phql_length, phql_key, (void**) &temp_ast) == SUCCESS) {
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
				if (phalcon_globals_ptr->orm.cache_level >= 0) {

					if (!phalcon_globals_ptr->orm.parser_cache) {
						ALLOC_HASHTABLE(phalcon_globals_ptr->orm.parser_cache);
						zend_hash_init(phalcon_globals_ptr->orm.parser_cache, 0, NULL, ZVAL_PTR_DTOR, 0);
					}

					Z_ADDREF_PP(result);

					zend_hash_quick_update(
						phalcon_globals_ptr->orm.parser_cache,
						phql,
						phql_length,
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