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


// 390 "parser.c"
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
#define YYNOCODE 105
#define YYACTIONTYPE unsigned short int
#define phql_TOKENTYPE phql_parser_token*
typedef union {
  phql_TOKENTYPE yy0;
  zval* yy72;
  int yy209;
} YYMINORTYPE;
#define YYSTACKDEPTH 100
#define phql_ARG_SDECL phql_parser_status *status;
#define phql_ARG_PDECL ,phql_parser_status *status
#define phql_ARG_FETCH phql_parser_status *status = yypParser->status
#define phql_ARG_STORE yypParser->status = status
#define YYNSTATE 241
#define YYNRULE 146
#define YYERRORSYMBOL 61
#define YYERRSYMDT yy209
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
 /*     0 */    70,   76,   48,   50,   52,   54,   56,   58,   40,   42,
 /*    10 */    60,   65,   44,   46,   36,   34,   38,   32,   29,   72,
 /*    20 */    67,  248,   62,    9,   70,   76,   48,   50,   52,   54,
 /*    30 */    56,   58,   40,   42,   60,   65,   44,   46,   36,   34,
 /*    40 */    38,   32,   29,   72,   67,  181,   62,  179,   27,   28,
 /*    50 */   193,   67,  191,   62,   70,   76,   48,   50,   52,   54,
 /*    60 */    56,   58,   40,   42,   60,   65,   44,   46,   36,   34,
 /*    70 */    38,   32,   29,   72,   67,   10,   62,   40,   42,   60,
 /*    80 */    65,   44,   46,   36,   34,   38,   32,   29,   72,   67,
 /*    90 */   114,   62,   17,  116,   11,   92,   13,   70,   76,   48,
 /*   100 */    50,   52,   54,   56,   58,   40,   42,   60,   65,   44,
 /*   110 */    46,   36,   34,   38,   32,   29,   72,   67,  241,   62,
 /*   120 */    48,   50,   52,   54,   56,   58,   40,   42,   60,   65,
 /*   130 */    44,   46,   36,   34,   38,   32,   29,   72,   67,   85,
 /*   140 */    62,   18,   30,  146,   20,   86,   88,  182,  148,  149,
 /*   150 */    79,   60,   65,   44,   46,   36,   34,   38,   32,   29,
 /*   160 */    72,   67,  242,   62,   90,  100,  253,   85,  246,  338,
 /*   170 */    30,   15,  112,   86,   88,   94,  243,   93,   79,   97,
 /*   180 */    95,   96,   98,   99,    7,  129,  131,  186,  139,  125,
 /*   190 */    30,  244,   90,   86,   88,   12,   78,  245,  187,   32,
 /*   200 */    29,   72,   67,   94,   62,  122,  128,   97,   95,   96,
 /*   210 */    98,   99,   90,   30,  140,   21,   86,   88,  251,  120,
 /*   220 */    10,   79,   10,   94,   14,  144,  184,   97,   95,   96,
 /*   230 */    98,   99,  125,   72,   67,   90,   62,   44,   46,   36,
 /*   240 */    34,   38,   32,   29,   72,   67,   94,   62,  247,  124,
 /*   250 */    97,   95,   96,   98,   99,  388,    1,    2,    3,    4,
 /*   260 */     5,    6,   36,   34,   38,   32,   29,   72,   67,  176,
 /*   270 */    62,   19,   10,  159,  160,  162,  164,   26,  168,  172,
 /*   280 */     8,   16,   93,  119,  217,  159,  160,  162,  164,  234,
 /*   290 */   168,  172,   22,   69,   74,   21,   23,  113,   93,  120,
 /*   300 */    69,   78,   10,  249,  143,   93,   69,  194,  190,  151,
 /*   310 */   155,   93,  132,   93,  134,  138,  104,   78,  101,  264,
 /*   320 */   147,  148,  149,   81,   78,  101,   68,   73,   24,  110,
 /*   330 */    78,  101,   78,  142,  204,  204,   69,  250,  255,   93,
 /*   340 */    93,   93,  200,  211,   26,  205,  205,  195,  103,   93,
 /*   350 */    21,  258,  223,  308,  238,  127,  117,   10,   78,   78,
 /*   360 */    78,   84,   31,   62,   25,  339,   21,   93,   78,  185,
 /*   370 */   190,   83,  117,   10,  204,   93,  232,   33,   35,   93,
 /*   380 */   126,   93,   93,   93,   21,  203,   78,   82,  198,  206,
 /*   390 */    37,   10,   39,  231,   78,   93,  317,   93,   78,  140,
 /*   400 */    78,   78,   78,   41,   43,   10,  340,  220,   93,   93,
 /*   410 */    45,  123,   47,   49,   78,   93,   78,   93,   93,   51,
 /*   420 */    53,   55,   63,  106,   93,   93,   93,   78,   78,  266,
 /*   430 */    75,  109,  108,   57,   78,   59,   78,   78,   93,  263,
 /*   440 */    93,   61,  140,   78,   78,   78,   93,   64,   66,   71,
 /*   450 */   220,   77,   93,   93,   93,   87,   93,   78,   89,   78,
 /*   460 */    93,   91,  107,   93,  118,   78,   93,   93,  259,   93,
 /*   470 */   145,   78,   78,   78,  183,   78,   21,  102,  178,   78,
 /*   480 */    83,   83,   78,   10,  229,   78,   78,  141,   78,  158,
 /*   490 */    80,  156,   93,  154,  226,  233,  105,  111,   93,  153,
 /*   500 */   135,  260,  165,  137,  169,  173,  166,  188,  170,  174,
 /*   510 */   189,   78,  177,  202,  213,  207,  178,   78,  216,  202,
 /*   520 */    80,  103,   10,  309,  224,  218,  229,  235,  178,  201,
 /*   530 */   208,  318,  240,  257,  115,  212,  178,  228,  252,  256,
 /*   540 */   254,  102,  130,  121,  261,  262,  133,  268,  222,  136,
 /*   550 */   237,  267,  265,  269,  127,   10,  153,  157,  161,  290,
 /*   560 */   150,  291,  199,  152,  292,  163,  167,  197,  293,  294,
 /*   570 */   295,  300,  301,  214,  219,  296,  171,  220,  311,  175,
 /*   580 */   341,  297,  298,  180,  192,  220,  215,  310,  230,  196,
 /*   590 */   227,  236,  320,  319,  239,  252,  252,  252,  209,  252,
 /*   600 */   252,  210,  252,  252,  252,  252,  225,  252,  252,  252,
 /*   610 */   252,  252,  252,  221,
};
static YYCODETYPE yy_lookahead[] = {
 /*     0 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    10 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*    20 */    21,    0,   23,   73,    1,    2,    3,    4,    5,    6,
 /*    30 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*    40 */    17,   18,   19,   20,   21,   27,   23,   29,   49,   50,
 /*    50 */    27,   21,   29,   23,    1,    2,    3,    4,    5,    6,
 /*    60 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*    70 */    17,   18,   19,   20,   21,   54,   23,    9,   10,   11,
 /*    80 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*    90 */    70,   23,   72,   73,   52,   42,   52,    1,    2,    3,
 /*   100 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   110 */    14,   15,   16,   17,   18,   19,   20,   21,    0,   23,
 /*   120 */     3,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   130 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   16,
 /*   140 */    23,   70,   19,   76,   73,   22,   23,   80,   81,   82,
 /*   150 */    27,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   160 */    20,   21,    0,   23,   41,   42,    0,   16,    0,    0,
 /*   170 */    19,   52,   78,   22,   23,   52,    0,   83,   27,   56,
 /*   180 */    57,   58,   59,   60,   69,   70,   71,   16,   73,   83,
 /*   190 */    19,    0,   41,   22,   23,   26,  102,    0,   27,   18,
 /*   200 */    19,   20,   21,   52,   23,   99,  100,   56,   57,   58,
 /*   210 */    59,   60,   41,   19,   46,   47,   22,   23,    0,   51,
 /*   220 */    54,   27,   54,   52,   55,   25,   26,   56,   57,   58,
 /*   230 */    59,   60,   83,   20,   21,   41,   23,   13,   14,   15,
 /*   240 */    16,   17,   18,   19,   20,   21,   52,   23,    0,  100,
 /*   250 */    56,   57,   58,   59,   60,   62,   63,   64,   65,   66,
 /*   260 */    67,   68,   15,   16,   17,   18,   19,   20,   21,   26,
 /*   270 */    23,   73,   54,   30,   31,   32,   33,   78,   35,   36,
 /*   280 */    70,   71,   83,   73,   91,   30,   31,   32,   33,   96,
 /*   290 */    35,   36,   48,   78,   23,   47,   97,   98,   83,   51,
 /*   300 */    78,  102,   54,    0,   74,   83,   78,   77,   78,   84,
 /*   310 */    85,   83,   70,   83,   72,   73,  101,  102,  103,    0,
 /*   320 */    80,   81,   82,  101,  102,  103,   41,   56,   26,  101,
 /*   330 */   102,  103,  102,   24,   78,   78,   78,    0,    0,   83,
 /*   340 */    83,   83,   86,   86,   78,   89,   89,   38,   27,   83,
 /*   350 */    47,    0,   43,    0,   45,   27,   53,   54,  102,  102,
 /*   360 */   102,  103,   78,   23,   98,    0,   47,   83,  102,   77,
 /*   370 */    78,   26,   53,   54,   78,   83,   78,   78,   78,   83,
 /*   380 */    52,   83,   83,   83,   47,   89,  102,   42,   40,   41,
 /*   390 */    78,   54,   78,   95,  102,   83,    0,   83,  102,   46,
 /*   400 */   102,  102,  102,   78,   78,   54,    0,   54,   83,   83,
 /*   410 */    78,   26,   78,   78,  102,   83,  102,   83,   83,   78,
 /*   420 */    78,   78,   11,   12,   83,   83,   83,  102,  102,    0,
 /*   430 */    56,   41,   21,   78,  102,   78,  102,  102,   83,    0,
 /*   440 */    83,   78,   46,  102,  102,  102,   83,   78,   78,   78,
 /*   450 */    54,   78,   83,   83,   83,   78,   83,  102,   78,  102,
 /*   460 */    83,   78,   78,   83,   78,  102,   83,   83,    0,   83,
 /*   470 */    75,  102,  102,  102,   79,  102,   47,   28,   83,  102,
 /*   480 */    26,   26,  102,   54,   83,  102,  102,   78,  102,   27,
 /*   490 */    41,   29,   83,   78,   93,   94,   42,   42,   83,   37,
 /*   500 */    70,    0,   30,   73,   30,   30,   34,   28,   34,   34,
 /*   510 */    16,  102,   79,   26,   26,   87,   83,  102,   90,   26,
 /*   520 */    41,   27,   54,    0,   79,   69,   83,   69,   83,   42,
 /*   530 */    42,    0,   79,    0,   73,   42,   83,   94,    0,    0,
 /*   540 */     0,   28,   73,   48,    0,    0,   73,    0,   92,   73,
 /*   550 */    92,    0,    0,    0,   27,   54,   37,   27,   30,   27,
 /*   560 */    83,   27,   41,   85,   27,   30,   30,   83,   27,   27,
 /*   570 */    27,    0,    0,   90,   92,   27,   30,   54,    0,   30,
 /*   580 */     0,   27,   27,   27,   27,   54,   27,    0,    3,   39,
 /*   590 */    26,   92,    0,    0,   25,  104,  104,  104,   40,  104,
 /*   600 */   104,   41,  104,  104,  104,  104,   44,  104,  104,  104,
 /*   610 */   104,  104,  104,   52,
};
#define YY_SHIFT_USE_DFLT (-2)
static short yy_shift_ofst[] = {
 /*     0 */   309,  118,  162,  176,  191,  197,  168,  248,   21,  338,
 /*    10 */    42,  169,   44,  365,  119,  406,  303,  337,  166,  439,
 /*    20 */   533,  244,  194,  302,  194,   -2,   -1,   -2,   -2,  194,
 /*    30 */   194,  213,  194,  213,  194,  181,  194,  181,  194,  181,
 /*    40 */   194,  140,  194,  140,  194,  247,  194,  247,  194,   68,
 /*    50 */   194,   68,  194,   68,  194,   68,  194,   68,  194,   68,
 /*    60 */   194,  224,  411,  194,  340,  194,  224,  285,  151,   96,
 /*    70 */   194,   96,  271,   -2,  374,   -2,  194,  117,   -2,  449,
 /*    80 */   123,  345,   -2,  151,   -2,   -2,  194,   30,  194,  340,
 /*    90 */   194,   53,   -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,
 /*   100 */    -2,   -2,  321,   -2,  454,   -2,  194,  340,  390,  151,
 /*   110 */   455,   -2,  213,   -2,  218,  538,  539,  194,   96,  540,
 /*   120 */   495,  328,  385,  328,   -2,   -2,   -2,  513,   -2,  351,
 /*   130 */   544,  319,  468,  545,  429,  501,  547,  551,  552,  553,
 /*   140 */   194,   96,  171,  200,  527,  243,  255,   -2,   -2,  527,
 /*   150 */   462,  519,   -2,  194,   96,   -2,  530,   -2,   -2,  532,
 /*   160 */   528,  534,  535,  537,  472,  541,  536,  542,  474,  543,
 /*   170 */   546,  548,  475,  554,  549,  555,  527,   -2,   18,  556,
 /*   180 */    -2,   -2,   -2,   -2,  171,   -2,   -2,  479,  494,   -2,
 /*   190 */    23,  557,   -2,   -2,   -2,  550,  527,  348,  521,  194,
 /*   200 */   487,  571,  194,   -2,   96,   -2,  559,  488,  558,  560,
 /*   210 */   194,  493,  572,  559,   -2,   -2,   -2,  353,  523,  578,
 /*   220 */   561,  580,  587,  527,  562,  527,  564,  527,   -2,  585,
 /*   230 */   194,   -2,   96,   -2,  396,  531,  592,  593,  569,  527,
 /*   240 */    -2,
};
#define YY_REDUCE_USE_DFLT (-51)
static short yy_reduce_ofst[] = {
 /*     0 */   193,  -51,  -51,  -51,  -51,  -51,  115,  210,  -50,  -51,
 /*    10 */   -51,  -51,  -51,  -51,  -51,  -51,   20,   71,  198,  -51,
 /*    20 */   -51,  -51,  199,  -51,  266,  -51,  -51,  -51,  -51,   94,
 /*    30 */   284,  -51,  299,  -51,  300,  -51,  312,  -51,  314,  -51,
 /*    40 */   325,  -51,  326,  -51,  332,  -51,  334,  -51,  335,  -51,
 /*    50 */   341,  -51,  342,  -51,  343,  -51,  355,  -51,  357,  -51,
 /*    60 */   363,  -51,  -51,  369,  -51,  370,  -51,  -51,  215,  -51,
 /*    70 */   371,  -51,  -51,  -51,  -51,  -51,  373,  -51,  -51,  -51,
 /*    80 */   222,  -51,  -51,  258,  -51,  -51,  377,  -51,  380,  -51,
 /*    90 */   383,  -51,  -51,  -51,  -51,  -51,  -51,  -51,  -51,  -51,
 /*   100 */   -51,  -51,  -51,  -51,  -51,  -51,  384,  -51,  -51,  228,
 /*   110 */   -51,  -51,  -51,  -51,  461,  -51,  -51,  386,  -51,  -51,
 /*   120 */   -51,  106,  -51,  149,  -51,  -51,  -51,  -51,  -51,  469,
 /*   130 */   -51,  242,  473,  -51,  430,  476,  -51,  -51,  -51,  -51,
 /*   140 */   409,  -51,  230,  -51,  395,   67,  240,  -51,  -51,  477,
 /*   150 */   225,  478,  -51,  415,  -51,  -51,  -51,  -51,  -51,  -51,
 /*   160 */   -51,  -51,  -51,  -51,  -51,  -51,  -51,  -51,  -51,  -51,
 /*   170 */   -51,  -51,  -51,  -51,  -51,  -51,  433,  -51,  -51,  -51,
 /*   180 */   -51,  -51,  -51,  -51,  292,  -51,  -51,  -51,  -51,  -51,
 /*   190 */   -51,  -51,  -51,  -51,  -51,  -51,  484,  -51,  -51,  256,
 /*   200 */   -51,  -51,  296,  -51,  -51,  -51,  428,  -51,  -51,  -51,
 /*   210 */   257,  -51,  -51,  483,  -51,  -51,  -51,  456,  482,  -51,
 /*   220 */   -51,  -51,  -51,  445,  -51,  401,  -51,  443,  -51,  -51,
 /*   230 */   298,  -51,  -51,  -51,  458,  499,  -51,  -51,  -51,  453,
 /*   240 */   -51,
};
static YYACTIONTYPE yy_default[] = {
 /*     0 */   387,  387,  387,  387,  387,  387,  387,  387,  387,  387,
 /*    10 */   387,  387,  387,  387,  387,  387,  387,  387,  387,  387,
 /*    20 */   387,  387,  387,  326,  387,  327,  329,  330,  331,  387,
 /*    30 */   387,  342,  387,  344,  387,  345,  387,  346,  387,  347,
 /*    40 */   387,  348,  387,  349,  387,  350,  387,  351,  387,  352,
 /*    50 */   387,  353,  387,  354,  387,  355,  387,  356,  387,  357,
 /*    60 */   387,  358,  387,  387,  359,  387,  360,  387,  387,  371,
 /*    70 */   387,  364,  387,  372,  387,  373,  387,  375,  365,  386,
 /*    80 */   387,  387,  366,  387,  368,  370,  387,  374,  387,  376,
 /*    90 */   387,  387,  377,  378,  379,  380,  381,  382,  383,  384,
 /*   100 */   367,  369,  387,  385,  387,  362,  387,  361,  387,  387,
 /*   110 */   387,  363,  343,  328,  387,  387,  387,  387,  337,  387,
 /*   120 */   387,  387,  332,  387,  333,  335,  336,  386,  334,  387,
 /*   130 */   387,  387,  387,  387,  387,  387,  387,  387,  387,  387,
 /*   140 */   387,  325,  387,  387,  387,  270,  271,  281,  283,  387,
 /*   150 */   284,  285,  287,  387,  299,  286,  387,  288,  289,  387,
 /*   160 */   387,  387,  387,  387,  387,  387,  387,  387,  387,  387,
 /*   170 */   387,  387,  387,  387,  387,  387,  387,  279,  324,  387,
 /*   180 */   322,  323,  282,  280,  387,  272,  274,  386,  387,  275,
 /*   190 */   278,  387,  276,  277,  273,  387,  387,  387,  387,  387,
 /*   200 */   387,  387,  387,  302,  304,  303,  387,  387,  387,  387,
 /*   210 */   387,  387,  387,  387,  305,  307,  306,  387,  387,  387,
 /*   220 */   387,  387,  387,  387,  387,  387,  312,  387,  313,  387,
 /*   230 */   387,  315,  316,  314,  387,  387,  387,  387,  387,  387,
 /*   240 */   321,
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
  "ILIKE",         "BITWISE_AND",   "BITWISE_OR",    "DIVIDE",      
  "TIMES",         "MOD",           "PLUS",          "MINUS",       
  "IS",            "IN",            "DISTINCT",      "NOT",         
  "SELECT",        "FROM",          "COMMA",         "IDENTIFIER",  
  "DOT",           "AS",            "JOIN",          "INNER",       
  "CROSS",         "LEFT",          "OUTER",         "RIGHT",       
  "FULL",          "ON",            "INSERT",        "INTO",        
  "VALUES",        "BRACKET_OPEN",  "BRACKET_CLOSE",  "UPDATE",      
  "SET",           "DELETE",        "WHERE",         "ORDER",       
  "BY",            "ASC",           "DESC",          "GROUP",       
  "INTEGER",       "HAVING",        "LIMIT",         "OFFSET",      
  "NULL",          "STRING",        "DOUBLE",        "NPLACEHOLDER",
  "SPLACEHOLDER",  "error",         "program",       "query_language",
  "select_statement",  "insert_statement",  "update_statement",  "delete_statement",
  "select_clause",  "where_clause",  "order_clause",  "group_clause",
  "having_clause",  "select_limit_clause",  "column_list",   "associated_name_list",
  "join_list",     "column_item",   "expr",          "associated_name",
  "join_item",     "join_clause",   "join_type",     "qualified_name",
  "join_associated_name",  "join_conditions",  "values_list",   "field_list",  
  "value_list",    "value_item",    "field_item",    "update_clause",
  "limit_clause",  "update_item_list",  "update_item",   "new_value",   
  "delete_clause",  "order_list",    "order_item",    "group_list",  
  "group_item",    "argument_list",  "function_call",  "argument_item",
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
 /*  43 */ "join_clause ::= join_type qualified_name",
 /*  44 */ "join_clause ::= join_type qualified_name join_associated_name",
 /*  45 */ "join_clause ::= join_type qualified_name join_conditions",
 /*  46 */ "join_clause ::= join_type qualified_name join_associated_name join_conditions",
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
 /*  59 */ "insert_statement ::= INSERT INTO qualified_name VALUES BRACKET_OPEN values_list BRACKET_CLOSE",
 /*  60 */ "insert_statement ::= INSERT INTO qualified_name BRACKET_OPEN field_list BRACKET_CLOSE VALUES BRACKET_OPEN values_list BRACKET_CLOSE",
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
 /*  81 */ "associated_name ::= qualified_name AS IDENTIFIER",
 /*  82 */ "associated_name ::= qualified_name IDENTIFIER",
 /*  83 */ "associated_name ::= qualified_name",
 /*  84 */ "where_clause ::= WHERE expr",
 /*  85 */ "order_clause ::= ORDER BY order_list",
 /*  86 */ "order_list ::= order_list COMMA order_item",
 /*  87 */ "order_list ::= order_item",
 /*  88 */ "order_item ::= expr",
 /*  89 */ "order_item ::= expr ASC",
 /*  90 */ "order_item ::= expr DESC",
 /*  91 */ "group_clause ::= GROUP BY group_list",
 /*  92 */ "group_list ::= group_list COMMA group_item",
 /*  93 */ "group_list ::= group_item",
 /*  94 */ "group_item ::= qualified_name",
 /*  95 */ "group_item ::= INTEGER",
 /*  96 */ "having_clause ::= HAVING expr",
 /*  97 */ "select_limit_clause ::= LIMIT INTEGER",
 /*  98 */ "select_limit_clause ::= LIMIT INTEGER COMMA INTEGER",
 /*  99 */ "select_limit_clause ::= LIMIT INTEGER OFFSET INTEGER",
 /* 100 */ "limit_clause ::= LIMIT INTEGER",
 /* 101 */ "expr ::= MINUS expr",
 /* 102 */ "expr ::= expr MINUS expr",
 /* 103 */ "expr ::= expr PLUS expr",
 /* 104 */ "expr ::= expr TIMES expr",
 /* 105 */ "expr ::= expr DIVIDE expr",
 /* 106 */ "expr ::= expr MOD expr",
 /* 107 */ "expr ::= expr AND expr",
 /* 108 */ "expr ::= expr OR expr",
 /* 109 */ "expr ::= expr BITWISE_AND expr",
 /* 110 */ "expr ::= expr BITWISE_OR expr",
 /* 111 */ "expr ::= expr EQUALS expr",
 /* 112 */ "expr ::= expr NOTEQUALS expr",
 /* 113 */ "expr ::= expr LESS expr",
 /* 114 */ "expr ::= expr GREATER expr",
 /* 115 */ "expr ::= expr GREATEREQUAL expr",
 /* 116 */ "expr ::= expr LESSEQUAL expr",
 /* 117 */ "expr ::= expr LIKE expr",
 /* 118 */ "expr ::= expr NOT LIKE expr",
 /* 119 */ "expr ::= expr ILIKE expr",
 /* 120 */ "expr ::= expr NOT ILIKE expr",
 /* 121 */ "expr ::= expr IN BRACKET_OPEN argument_list BRACKET_CLOSE",
 /* 122 */ "expr ::= expr NOT IN BRACKET_OPEN argument_list BRACKET_CLOSE",
 /* 123 */ "expr ::= expr AGAINST expr",
 /* 124 */ "expr ::= function_call",
 /* 125 */ "function_call ::= IDENTIFIER BRACKET_OPEN argument_list BRACKET_CLOSE",
 /* 126 */ "function_call ::= IDENTIFIER BRACKET_OPEN BRACKET_CLOSE",
 /* 127 */ "argument_list ::= argument_list COMMA argument_item",
 /* 128 */ "argument_list ::= argument_item",
 /* 129 */ "argument_item ::= TIMES",
 /* 130 */ "argument_item ::= expr",
 /* 131 */ "expr ::= expr IS NULL",
 /* 132 */ "expr ::= expr IS NOT NULL",
 /* 133 */ "expr ::= DISTINCT expr",
 /* 134 */ "expr ::= expr BETWEEN expr",
 /* 135 */ "expr ::= NOT expr",
 /* 136 */ "expr ::= BRACKET_OPEN expr BRACKET_CLOSE",
 /* 137 */ "expr ::= qualified_name",
 /* 138 */ "expr ::= INTEGER",
 /* 139 */ "expr ::= STRING",
 /* 140 */ "expr ::= DOUBLE",
 /* 141 */ "expr ::= NULL",
 /* 142 */ "expr ::= NPLACEHOLDER",
 /* 143 */ "expr ::= SPLACEHOLDER",
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
// 487 "parser.lemon"
{
	if ((yypminor->yy0)) {
		if ((yypminor->yy0)->free_flag) {
			efree((yypminor->yy0)->token);
		}
		efree((yypminor->yy0));
	}
}
// 1108 "parser.c"
      break;
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
    case 87:
    case 88:
    case 90:
    case 91:
    case 92:
    case 93:
    case 94:
    case 96:
    case 97:
    case 98:
    case 99:
    case 100:
    case 101:
    case 102:
    case 103:
// 500 "parser.lemon"
{ zval_ptr_dtor(&(yypminor->yy72)); }
// 1150 "parser.c"
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
  { 62, 1 },
  { 63, 1 },
  { 63, 1 },
  { 63, 1 },
  { 63, 1 },
  { 64, 1 },
  { 64, 2 },
  { 64, 3 },
  { 64, 3 },
  { 64, 4 },
  { 64, 4 },
  { 64, 5 },
  { 64, 5 },
  { 64, 3 },
  { 64, 4 },
  { 64, 4 },
  { 64, 5 },
  { 64, 2 },
  { 64, 3 },
  { 64, 4 },
  { 64, 3 },
  { 64, 4 },
  { 64, 6 },
  { 64, 2 },
  { 64, 3 },
  { 64, 3 },
  { 64, 4 },
  { 64, 5 },
  { 64, 2 },
  { 68, 4 },
  { 68, 5 },
  { 74, 3 },
  { 74, 1 },
  { 77, 1 },
  { 77, 3 },
  { 77, 3 },
  { 77, 2 },
  { 77, 1 },
  { 75, 3 },
  { 75, 1 },
  { 76, 2 },
  { 76, 1 },
  { 80, 1 },
  { 81, 2 },
  { 81, 3 },
  { 81, 3 },
  { 81, 4 },
  { 84, 2 },
  { 84, 1 },
  { 82, 1 },
  { 82, 2 },
  { 82, 2 },
  { 82, 2 },
  { 82, 3 },
  { 82, 2 },
  { 82, 3 },
  { 82, 2 },
  { 82, 3 },
  { 85, 2 },
  { 65, 7 },
  { 65, 10 },
  { 86, 3 },
  { 86, 1 },
  { 89, 1 },
  { 87, 3 },
  { 87, 1 },
  { 90, 1 },
  { 66, 1 },
  { 66, 2 },
  { 66, 2 },
  { 66, 3 },
  { 91, 4 },
  { 93, 3 },
  { 93, 1 },
  { 94, 3 },
  { 95, 1 },
  { 67, 1 },
  { 67, 2 },
  { 67, 2 },
  { 67, 3 },
  { 96, 3 },
  { 79, 3 },
  { 79, 2 },
  { 79, 1 },
  { 69, 2 },
  { 70, 3 },
  { 97, 3 },
  { 97, 1 },
  { 98, 1 },
  { 98, 2 },
  { 98, 2 },
  { 71, 3 },
  { 99, 3 },
  { 99, 1 },
  { 100, 1 },
  { 100, 1 },
  { 72, 2 },
  { 73, 2 },
  { 73, 4 },
  { 73, 4 },
  { 92, 2 },
  { 78, 2 },
  { 78, 3 },
  { 78, 3 },
  { 78, 3 },
  { 78, 3 },
  { 78, 3 },
  { 78, 3 },
  { 78, 3 },
  { 78, 3 },
  { 78, 3 },
  { 78, 3 },
  { 78, 3 },
  { 78, 3 },
  { 78, 3 },
  { 78, 3 },
  { 78, 3 },
  { 78, 3 },
  { 78, 4 },
  { 78, 3 },
  { 78, 4 },
  { 78, 5 },
  { 78, 6 },
  { 78, 3 },
  { 78, 1 },
  { 102, 4 },
  { 102, 3 },
  { 101, 3 },
  { 101, 1 },
  { 103, 1 },
  { 103, 1 },
  { 78, 3 },
  { 78, 4 },
  { 78, 2 },
  { 78, 3 },
  { 78, 2 },
  { 78, 3 },
  { 78, 1 },
  { 78, 1 },
  { 78, 1 },
  { 78, 1 },
  { 78, 1 },
  { 78, 1 },
  { 78, 1 },
  { 83, 3 },
  { 83, 1 },
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
// 496 "parser.lemon"
{
	status->ret = yymsp[0].minor.yy72;
}
// 1513 "parser.c"
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
      case 87:
      case 93:
      case 94:
      case 124:
      case 130:
      case 137:
// 502 "parser.lemon"
{
	yygotominor.yy72 = yymsp[0].minor.yy72;
}
// 1538 "parser.c"
        break;
      case 5:
// 520 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_select_statement(yymsp[0].minor.yy72, NULL, NULL, NULL, NULL, NULL);
}
// 1545 "parser.c"
        break;
      case 6:
// 524 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_select_statement(yymsp[-1].minor.yy72, yymsp[0].minor.yy72, NULL, NULL, NULL, NULL);
}
// 1552 "parser.c"
        break;
      case 7:
// 528 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_select_statement(yymsp[-2].minor.yy72, yymsp[-1].minor.yy72, yymsp[0].minor.yy72, NULL, NULL, NULL);
}
// 1559 "parser.c"
        break;
      case 8:
// 532 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_select_statement(yymsp[-2].minor.yy72, yymsp[-1].minor.yy72, NULL, yymsp[0].minor.yy72, NULL, NULL);
}
// 1566 "parser.c"
        break;
      case 9:
// 536 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_select_statement(yymsp[-3].minor.yy72, yymsp[-2].minor.yy72, NULL, yymsp[-1].minor.yy72, yymsp[0].minor.yy72, NULL);
}
// 1573 "parser.c"
        break;
      case 10:
// 540 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_select_statement(yymsp[-3].minor.yy72, yymsp[-2].minor.yy72, yymsp[0].minor.yy72, yymsp[-1].minor.yy72, NULL, NULL);
}
// 1580 "parser.c"
        break;
      case 11:
// 544 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_select_statement(yymsp[-4].minor.yy72, yymsp[-3].minor.yy72, yymsp[-1].minor.yy72, yymsp[-2].minor.yy72, NULL, yymsp[0].minor.yy72);
}
// 1587 "parser.c"
        break;
      case 12:
// 548 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_select_statement(yymsp[-4].minor.yy72, yymsp[-3].minor.yy72, yymsp[0].minor.yy72, yymsp[-2].minor.yy72, yymsp[-1].minor.yy72, NULL);
}
// 1594 "parser.c"
        break;
      case 13:
// 552 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_select_statement(yymsp[-2].minor.yy72, yymsp[-1].minor.yy72, NULL, NULL, NULL, yymsp[0].minor.yy72);
}
// 1601 "parser.c"
        break;
      case 14:
// 556 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_select_statement(yymsp[-3].minor.yy72, yymsp[-2].minor.yy72, yymsp[-1].minor.yy72, NULL, NULL, yymsp[0].minor.yy72);
}
// 1608 "parser.c"
        break;
      case 15:
// 560 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_select_statement(yymsp[-3].minor.yy72, yymsp[-2].minor.yy72, NULL, yymsp[-1].minor.yy72, NULL, yymsp[0].minor.yy72);
}
// 1615 "parser.c"
        break;
      case 16:
// 564 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_select_statement(yymsp[-4].minor.yy72, yymsp[-3].minor.yy72, NULL, yymsp[-2].minor.yy72, yymsp[-1].minor.yy72, yymsp[0].minor.yy72);
}
// 1622 "parser.c"
        break;
      case 17:
// 568 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_select_statement(yymsp[-1].minor.yy72, NULL, yymsp[0].minor.yy72, NULL, NULL, NULL);
}
// 1629 "parser.c"
        break;
      case 18:
// 572 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_select_statement(yymsp[-2].minor.yy72, NULL, yymsp[0].minor.yy72, yymsp[-1].minor.yy72, NULL, NULL);
}
// 1636 "parser.c"
        break;
      case 19:
// 576 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_select_statement(yymsp[-3].minor.yy72, NULL, yymsp[0].minor.yy72, yymsp[-2].minor.yy72, yymsp[-1].minor.yy72, NULL);
}
// 1643 "parser.c"
        break;
      case 20:
// 580 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_select_statement(yymsp[-2].minor.yy72, NULL, yymsp[-1].minor.yy72, NULL, NULL, yymsp[0].minor.yy72);
}
// 1650 "parser.c"
        break;
      case 21:
// 584 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_select_statement(yymsp[-3].minor.yy72, NULL, yymsp[-1].minor.yy72, yymsp[-2].minor.yy72, NULL, yymsp[0].minor.yy72);
}
// 1657 "parser.c"
        break;
      case 22:
// 588 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_select_statement(yymsp[-5].minor.yy72, yymsp[-4].minor.yy72, yymsp[-1].minor.yy72, yymsp[-3].minor.yy72, yymsp[-2].minor.yy72, yymsp[0].minor.yy72);
}
// 1664 "parser.c"
        break;
      case 23:
// 592 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_select_statement(yymsp[-1].minor.yy72, NULL, NULL, yymsp[0].minor.yy72, NULL, NULL);
}
// 1671 "parser.c"
        break;
      case 24:
// 596 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_select_statement(yymsp[-2].minor.yy72, NULL, NULL, yymsp[-1].minor.yy72, NULL, yymsp[0].minor.yy72);
}
// 1678 "parser.c"
        break;
      case 25:
// 600 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_select_statement(yymsp[-2].minor.yy72, NULL, NULL, yymsp[-1].minor.yy72, yymsp[0].minor.yy72, NULL);
}
// 1685 "parser.c"
        break;
      case 26:
// 604 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_select_statement(yymsp[-3].minor.yy72, NULL, NULL, yymsp[-2].minor.yy72, yymsp[-1].minor.yy72, yymsp[0].minor.yy72);
}
// 1692 "parser.c"
        break;
      case 27:
// 608 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_select_statement(yymsp[-4].minor.yy72, NULL, yymsp[-1].minor.yy72, yymsp[-3].minor.yy72, yymsp[-2].minor.yy72, yymsp[0].minor.yy72);
}
// 1699 "parser.c"
        break;
      case 28:
// 612 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_select_statement(yymsp[-1].minor.yy72, NULL, NULL, NULL, NULL, yymsp[0].minor.yy72);
}
// 1706 "parser.c"
        break;
      case 29:
// 618 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_select_clause(yymsp[-2].minor.yy72, yymsp[0].minor.yy72, NULL);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
// 1715 "parser.c"
        break;
      case 30:
// 622 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_select_clause(yymsp[-3].minor.yy72, yymsp[-1].minor.yy72, yymsp[0].minor.yy72);
  yy_destructor(24,&yymsp[-4].minor);
  yy_destructor(25,&yymsp[-2].minor);
}
// 1724 "parser.c"
        break;
      case 31:
      case 38:
      case 61:
      case 64:
      case 72:
      case 86:
      case 92:
      case 127:
// 628 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_zval_list(yymsp[-2].minor.yy72, yymsp[0].minor.yy72);
  yy_destructor(26,&yymsp[-1].minor);
}
// 1739 "parser.c"
        break;
      case 33:
      case 129:
// 638 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_column_item(PHQL_T_ALL, NULL, NULL, NULL);
  yy_destructor(16,&yymsp[0].minor);
}
// 1748 "parser.c"
        break;
      case 34:
// 642 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_column_item(PHQL_T_DOMAINALL, NULL, yymsp[-2].minor.yy0, NULL);
  yy_destructor(28,&yymsp[-1].minor);
  yy_destructor(16,&yymsp[0].minor);
}
// 1757 "parser.c"
        break;
      case 35:
// 646 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-2].minor.yy72, NULL, yymsp[0].minor.yy0);
  yy_destructor(29,&yymsp[-1].minor);
}
// 1765 "parser.c"
        break;
      case 36:
// 650 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-1].minor.yy72, NULL, yymsp[0].minor.yy0);
}
// 1772 "parser.c"
        break;
      case 37:
// 654 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_column_item(PHQL_T_EXPR, yymsp[0].minor.yy72, NULL, NULL);
}
// 1779 "parser.c"
        break;
      case 40:
// 670 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_zval_list(yymsp[-1].minor.yy72, yymsp[0].minor.yy72);
}
// 1786 "parser.c"
        break;
      case 43:
// 687 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_join_item(yymsp[-1].minor.yy72, yymsp[0].minor.yy72, NULL, NULL);
}
// 1793 "parser.c"
        break;
      case 44:
// 692 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_join_item(yymsp[-2].minor.yy72, yymsp[-1].minor.yy72, yymsp[0].minor.yy72, NULL);
}
// 1800 "parser.c"
        break;
      case 45:
// 697 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_join_item(yymsp[-2].minor.yy72, yymsp[-1].minor.yy72, NULL, yymsp[0].minor.yy72);
}
// 1807 "parser.c"
        break;
      case 46:
// 702 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_join_item(yymsp[-3].minor.yy72, yymsp[-2].minor.yy72, yymsp[-1].minor.yy72, yymsp[0].minor.yy72);
}
// 1814 "parser.c"
        break;
      case 47:
// 708 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_qualified_name(yymsp[0].minor.yy0, NULL);
  yy_destructor(29,&yymsp[-1].minor);
}
// 1822 "parser.c"
        break;
      case 48:
      case 66:
      case 145:
// 712 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_qualified_name(yymsp[0].minor.yy0, NULL);
}
// 1831 "parser.c"
        break;
      case 49:
// 718 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_join_type(PHQL_T_INNERJOIN);
  yy_destructor(30,&yymsp[0].minor);
}
// 1839 "parser.c"
        break;
      case 50:
// 722 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_join_type(PHQL_T_INNERJOIN);
  yy_destructor(31,&yymsp[-1].minor);
  yy_destructor(30,&yymsp[0].minor);
}
// 1848 "parser.c"
        break;
      case 51:
// 726 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_join_type(PHQL_T_CROSSJOIN);
  yy_destructor(32,&yymsp[-1].minor);
  yy_destructor(30,&yymsp[0].minor);
}
// 1857 "parser.c"
        break;
      case 52:
// 730 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  yy_destructor(33,&yymsp[-1].minor);
  yy_destructor(30,&yymsp[0].minor);
}
// 1866 "parser.c"
        break;
      case 53:
// 734 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  yy_destructor(33,&yymsp[-2].minor);
  yy_destructor(34,&yymsp[-1].minor);
  yy_destructor(30,&yymsp[0].minor);
}
// 1876 "parser.c"
        break;
      case 54:
// 738 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  yy_destructor(35,&yymsp[-1].minor);
  yy_destructor(30,&yymsp[0].minor);
}
// 1885 "parser.c"
        break;
      case 55:
// 742 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(34,&yymsp[-1].minor);
  yy_destructor(30,&yymsp[0].minor);
}
// 1895 "parser.c"
        break;
      case 56:
// 746 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_join_type(PHQL_T_FULLJOIN);
  yy_destructor(36,&yymsp[-1].minor);
  yy_destructor(30,&yymsp[0].minor);
}
// 1904 "parser.c"
        break;
      case 57:
// 750 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_join_type(PHQL_T_FULLJOIN);
  yy_destructor(36,&yymsp[-2].minor);
  yy_destructor(34,&yymsp[-1].minor);
  yy_destructor(30,&yymsp[0].minor);
}
// 1914 "parser.c"
        break;
      case 58:
// 756 "parser.lemon"
{
	yygotominor.yy72 = yymsp[0].minor.yy72;
  yy_destructor(37,&yymsp[-1].minor);
}
// 1922 "parser.c"
        break;
      case 59:
// 763 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_insert_statement(yymsp[-4].minor.yy72, NULL, yymsp[-1].minor.yy72);
  yy_destructor(38,&yymsp[-6].minor);
  yy_destructor(39,&yymsp[-5].minor);
  yy_destructor(40,&yymsp[-3].minor);
  yy_destructor(41,&yymsp[-2].minor);
  yy_destructor(42,&yymsp[0].minor);
}
// 1934 "parser.c"
        break;
      case 60:
// 767 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_insert_statement(yymsp[-7].minor.yy72, yymsp[-5].minor.yy72, yymsp[-1].minor.yy72);
  yy_destructor(38,&yymsp[-9].minor);
  yy_destructor(39,&yymsp[-8].minor);
  yy_destructor(41,&yymsp[-6].minor);
  yy_destructor(42,&yymsp[-4].minor);
  yy_destructor(40,&yymsp[-3].minor);
  yy_destructor(41,&yymsp[-2].minor);
  yy_destructor(42,&yymsp[0].minor);
}
// 1948 "parser.c"
        break;
      case 67:
// 805 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_update_statement(yymsp[0].minor.yy72, NULL, NULL);
}
// 1955 "parser.c"
        break;
      case 68:
// 809 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_update_statement(yymsp[-1].minor.yy72, yymsp[0].minor.yy72, NULL);
}
// 1962 "parser.c"
        break;
      case 69:
// 813 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_update_statement(yymsp[-1].minor.yy72, NULL, yymsp[0].minor.yy72);
}
// 1969 "parser.c"
        break;
      case 70:
// 817 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_update_statement(yymsp[-2].minor.yy72, yymsp[-1].minor.yy72, yymsp[0].minor.yy72);
}
// 1976 "parser.c"
        break;
      case 71:
// 823 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_update_clause(yymsp[-2].minor.yy72, yymsp[0].minor.yy72);
  yy_destructor(43,&yymsp[-3].minor);
  yy_destructor(44,&yymsp[-1].minor);
}
// 1985 "parser.c"
        break;
      case 74:
// 839 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_update_item(yymsp[-2].minor.yy72, yymsp[0].minor.yy72);
  yy_destructor(3,&yymsp[-1].minor);
}
// 1993 "parser.c"
        break;
      case 76:
// 851 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_delete_statement(yymsp[0].minor.yy72, NULL, NULL);
}
// 2000 "parser.c"
        break;
      case 77:
// 855 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_delete_statement(yymsp[-1].minor.yy72, yymsp[0].minor.yy72, NULL);
}
// 2007 "parser.c"
        break;
      case 78:
// 859 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_delete_statement(yymsp[-1].minor.yy72, NULL, yymsp[0].minor.yy72);
}
// 2014 "parser.c"
        break;
      case 79:
// 863 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_delete_statement(yymsp[-2].minor.yy72, yymsp[-1].minor.yy72, yymsp[0].minor.yy72);
}
// 2021 "parser.c"
        break;
      case 80:
// 869 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_delete_clause(yymsp[0].minor.yy72);
  yy_destructor(45,&yymsp[-2].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
// 2030 "parser.c"
        break;
      case 81:
// 875 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_assoc_name(yymsp[-2].minor.yy72, yymsp[0].minor.yy0);
  yy_destructor(29,&yymsp[-1].minor);
}
// 2038 "parser.c"
        break;
      case 82:
// 879 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_assoc_name(yymsp[-1].minor.yy72, yymsp[0].minor.yy0);
}
// 2045 "parser.c"
        break;
      case 83:
// 883 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_assoc_name(yymsp[0].minor.yy72, NULL);
}
// 2052 "parser.c"
        break;
      case 84:
// 889 "parser.lemon"
{
	yygotominor.yy72 = yymsp[0].minor.yy72;
  yy_destructor(46,&yymsp[-1].minor);
}
// 2060 "parser.c"
        break;
      case 85:
// 895 "parser.lemon"
{
	yygotominor.yy72 = yymsp[0].minor.yy72;
  yy_destructor(47,&yymsp[-2].minor);
  yy_destructor(48,&yymsp[-1].minor);
}
// 2069 "parser.c"
        break;
      case 88:
// 911 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_order_item(yymsp[0].minor.yy72, 0);
}
// 2076 "parser.c"
        break;
      case 89:
// 915 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_order_item(yymsp[-1].minor.yy72, PHQL_T_ASC);
  yy_destructor(49,&yymsp[0].minor);
}
// 2084 "parser.c"
        break;
      case 90:
// 919 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_order_item(yymsp[-1].minor.yy72, PHQL_T_DESC);
  yy_destructor(50,&yymsp[0].minor);
}
// 2092 "parser.c"
        break;
      case 91:
// 925 "parser.lemon"
{
	yygotominor.yy72 = yymsp[0].minor.yy72;
  yy_destructor(51,&yymsp[-2].minor);
  yy_destructor(48,&yymsp[-1].minor);
}
// 2101 "parser.c"
        break;
      case 95:
      case 138:
// 945 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_literal_zval(PHQL_T_INTEGER, yymsp[0].minor.yy0);
}
// 2109 "parser.c"
        break;
      case 96:
// 951 "parser.lemon"
{
	yygotominor.yy72 = yymsp[0].minor.yy72;
  yy_destructor(53,&yymsp[-1].minor);
}
// 2117 "parser.c"
        break;
      case 97:
      case 100:
// 957 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_limit_clause(yymsp[0].minor.yy0, NULL);
  yy_destructor(54,&yymsp[-1].minor);
}
// 2126 "parser.c"
        break;
      case 98:
// 961 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_limit_clause(yymsp[0].minor.yy0, yymsp[-2].minor.yy0);
  yy_destructor(54,&yymsp[-3].minor);
  yy_destructor(26,&yymsp[-1].minor);
}
// 2135 "parser.c"
        break;
      case 99:
// 965 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_limit_clause(yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(54,&yymsp[-3].minor);
  yy_destructor(55,&yymsp[-1].minor);
}
// 2144 "parser.c"
        break;
      case 101:
// 977 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_expr(PHQL_T_MINUS, NULL, yymsp[0].minor.yy72);
  yy_destructor(19,&yymsp[-1].minor);
}
// 2152 "parser.c"
        break;
      case 102:
// 981 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_expr(PHQL_T_SUB, yymsp[-2].minor.yy72, yymsp[0].minor.yy72);
  yy_destructor(19,&yymsp[-1].minor);
}
// 2160 "parser.c"
        break;
      case 103:
// 985 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_expr(PHQL_T_ADD, yymsp[-2].minor.yy72, yymsp[0].minor.yy72);
  yy_destructor(18,&yymsp[-1].minor);
}
// 2168 "parser.c"
        break;
      case 104:
// 989 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_expr(PHQL_T_MUL, yymsp[-2].minor.yy72, yymsp[0].minor.yy72);
  yy_destructor(16,&yymsp[-1].minor);
}
// 2176 "parser.c"
        break;
      case 105:
// 993 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_expr(PHQL_T_DIV, yymsp[-2].minor.yy72, yymsp[0].minor.yy72);
  yy_destructor(15,&yymsp[-1].minor);
}
// 2184 "parser.c"
        break;
      case 106:
// 997 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_expr(PHQL_T_MOD, yymsp[-2].minor.yy72, yymsp[0].minor.yy72);
  yy_destructor(17,&yymsp[-1].minor);
}
// 2192 "parser.c"
        break;
      case 107:
// 1001 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_expr(PHQL_T_AND, yymsp[-2].minor.yy72, yymsp[0].minor.yy72);
  yy_destructor(9,&yymsp[-1].minor);
}
// 2200 "parser.c"
        break;
      case 108:
// 1005 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_expr(PHQL_T_OR, yymsp[-2].minor.yy72, yymsp[0].minor.yy72);
  yy_destructor(10,&yymsp[-1].minor);
}
// 2208 "parser.c"
        break;
      case 109:
// 1009 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_expr(PHQL_T_BITWISE_AND, yymsp[-2].minor.yy72, yymsp[0].minor.yy72);
  yy_destructor(13,&yymsp[-1].minor);
}
// 2216 "parser.c"
        break;
      case 110:
// 1013 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_expr(PHQL_T_BITWISE_OR, yymsp[-2].minor.yy72, yymsp[0].minor.yy72);
  yy_destructor(14,&yymsp[-1].minor);
}
// 2224 "parser.c"
        break;
      case 111:
// 1017 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_expr(PHQL_T_EQUALS, yymsp[-2].minor.yy72, yymsp[0].minor.yy72);
  yy_destructor(3,&yymsp[-1].minor);
}
// 2232 "parser.c"
        break;
      case 112:
// 1021 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_expr(PHQL_T_NOTEQUALS, yymsp[-2].minor.yy72, yymsp[0].minor.yy72);
  yy_destructor(4,&yymsp[-1].minor);
}
// 2240 "parser.c"
        break;
      case 113:
// 1025 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_expr(PHQL_T_LESS, yymsp[-2].minor.yy72, yymsp[0].minor.yy72);
  yy_destructor(5,&yymsp[-1].minor);
}
// 2248 "parser.c"
        break;
      case 114:
// 1029 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_expr(PHQL_T_GREATER, yymsp[-2].minor.yy72, yymsp[0].minor.yy72);
  yy_destructor(6,&yymsp[-1].minor);
}
// 2256 "parser.c"
        break;
      case 115:
// 1033 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_expr(PHQL_T_GREATEREQUAL, yymsp[-2].minor.yy72, yymsp[0].minor.yy72);
  yy_destructor(7,&yymsp[-1].minor);
}
// 2264 "parser.c"
        break;
      case 116:
// 1037 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_expr(PHQL_T_LESSEQUAL, yymsp[-2].minor.yy72, yymsp[0].minor.yy72);
  yy_destructor(8,&yymsp[-1].minor);
}
// 2272 "parser.c"
        break;
      case 117:
// 1041 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_expr(PHQL_T_LIKE, yymsp[-2].minor.yy72, yymsp[0].minor.yy72);
  yy_destructor(11,&yymsp[-1].minor);
}
// 2280 "parser.c"
        break;
      case 118:
// 1045 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_expr(PHQL_T_NLIKE, yymsp[-3].minor.yy72, yymsp[0].minor.yy72);
  yy_destructor(23,&yymsp[-2].minor);
  yy_destructor(11,&yymsp[-1].minor);
}
// 2289 "parser.c"
        break;
      case 119:
// 1049 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_expr(PHQL_T_ILIKE, yymsp[-2].minor.yy72, yymsp[0].minor.yy72);
  yy_destructor(12,&yymsp[-1].minor);
}
// 2297 "parser.c"
        break;
      case 120:
// 1053 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_expr(PHQL_T_NILIKE, yymsp[-3].minor.yy72, yymsp[0].minor.yy72);
  yy_destructor(23,&yymsp[-2].minor);
  yy_destructor(12,&yymsp[-1].minor);
}
// 2306 "parser.c"
        break;
      case 121:
// 1057 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_expr(PHQL_T_IN, yymsp[-4].minor.yy72, yymsp[-1].minor.yy72);
  yy_destructor(21,&yymsp[-3].minor);
  yy_destructor(41,&yymsp[-2].minor);
  yy_destructor(42,&yymsp[0].minor);
}
// 2316 "parser.c"
        break;
      case 122:
// 1061 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_expr(PHQL_T_NOTIN, yymsp[-5].minor.yy72, yymsp[-1].minor.yy72);
  yy_destructor(23,&yymsp[-4].minor);
  yy_destructor(21,&yymsp[-3].minor);
  yy_destructor(41,&yymsp[-2].minor);
  yy_destructor(42,&yymsp[0].minor);
}
// 2327 "parser.c"
        break;
      case 123:
// 1065 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_expr(PHQL_T_AGAINST, yymsp[-2].minor.yy72, yymsp[0].minor.yy72);
  yy_destructor(1,&yymsp[-1].minor);
}
// 2335 "parser.c"
        break;
      case 125:
// 1075 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_func_call(yymsp[-3].minor.yy0, yymsp[-1].minor.yy72);
  yy_destructor(41,&yymsp[-2].minor);
  yy_destructor(42,&yymsp[0].minor);
}
// 2344 "parser.c"
        break;
      case 126:
// 1079 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_func_call(yymsp[-2].minor.yy0, NULL);
  yy_destructor(41,&yymsp[-1].minor);
  yy_destructor(42,&yymsp[0].minor);
}
// 2353 "parser.c"
        break;
      case 128:
// 1089 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_zval_list(yymsp[0].minor.yy72, NULL);
}
// 2360 "parser.c"
        break;
      case 131:
// 1103 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_expr(PHQL_T_ISNULL, yymsp[-2].minor.yy72, NULL);
  yy_destructor(20,&yymsp[-1].minor);
  yy_destructor(56,&yymsp[0].minor);
}
// 2369 "parser.c"
        break;
      case 132:
// 1107 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_expr(PHQL_T_ISNOTNULL, yymsp[-3].minor.yy72, NULL);
  yy_destructor(20,&yymsp[-2].minor);
  yy_destructor(23,&yymsp[-1].minor);
  yy_destructor(56,&yymsp[0].minor);
}
// 2379 "parser.c"
        break;
      case 133:
// 1111 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_expr(PHQL_T_DISTINCT, NULL, yymsp[0].minor.yy72);
  yy_destructor(22,&yymsp[-1].minor);
}
// 2387 "parser.c"
        break;
      case 134:
// 1115 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_expr(PHQL_T_BETWEEN, yymsp[-2].minor.yy72, yymsp[0].minor.yy72);
  yy_destructor(2,&yymsp[-1].minor);
}
// 2395 "parser.c"
        break;
      case 135:
// 1119 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_expr(PHQL_T_NOT, NULL, yymsp[0].minor.yy72);
  yy_destructor(23,&yymsp[-1].minor);
}
// 2403 "parser.c"
        break;
      case 136:
// 1123 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_expr(PHQL_T_ENCLOSED, yymsp[-1].minor.yy72, NULL);
  yy_destructor(41,&yymsp[-2].minor);
  yy_destructor(42,&yymsp[0].minor);
}
// 2412 "parser.c"
        break;
      case 139:
// 1135 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_literal_zval(PHQL_T_STRING, yymsp[0].minor.yy0);
}
// 2419 "parser.c"
        break;
      case 140:
// 1139 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_literal_zval(PHQL_T_DOUBLE, yymsp[0].minor.yy0);
}
// 2426 "parser.c"
        break;
      case 141:
// 1143 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_literal_zval(PHQL_T_NULL, NULL);
  yy_destructor(56,&yymsp[0].minor);
}
// 2434 "parser.c"
        break;
      case 142:
// 1147 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_placeholder_zval(PHQL_T_NPLACEHOLDER, yymsp[0].minor.yy0);
}
// 2441 "parser.c"
        break;
      case 143:
// 1151 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_placeholder_zval(PHQL_T_SPLACEHOLDER, yymsp[0].minor.yy0);
}
// 2448 "parser.c"
        break;
      case 144:
// 1157 "parser.lemon"
{
	yygotominor.yy72 = phql_ret_qualified_name(yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(28,&yymsp[-1].minor);
}
// 2456 "parser.c"
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
// 420 "parser.lemon"

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

			status->syntax_error_len = 64 + status->token->len + token_length + near_length;
			status->syntax_error = emalloc(sizeof(char) * status->syntax_error_len);

			if (near_length > 0) {
				if (status->token->value) {
					snprintf(status->syntax_error, status->syntax_error_len, "Syntax error, unexpected token %s(%s), near to '%s'", token_name, status->token->value, status->scanner_state->start);
				} else {
					snprintf(status->syntax_error, status->syntax_error_len, "Syntax error, unexpected token %s, near to '%s'", token_name, status->scanner_state->start);
				}
			} else {
				if (active_token != PHQL_T_IGNORE) {
					if (status->token->value) {
						snprintf(status->syntax_error, status->syntax_error_len, "Syntax error, unexpected token %s(%s), at the end of query", token_name, status->token->value);
					} else {
						snprintf(status->syntax_error, status->syntax_error_len, "Syntax error, unexpected token %s, at the end of query", token_name);
					}
				} else {
					snprintf(status->syntax_error, status->syntax_error_len, "Syntax error, unexpected EOF, at the end of query");
				}
				status->syntax_error[status->syntax_error_len-1] = '\0';
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

// 2565 "parser.c"
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
  { PHQL_T_COMMA,         SL("COMMA") },
  { PHQL_T_EQUALS,        SL("EQUALS") },
  { PHQL_T_NOTEQUALS,     SL("NOT EQUALS") },
  { PHQL_T_NOT,           SL("NOT") },
  { PHQL_T_LESS,          SL("<") },
  { PHQL_T_LESSEQUAL,     SL("<=") },
  { PHQL_T_GREATER,       SL(">") },
  { PHQL_T_GREATEREQUAL,  SL(">=") },
  { PHQL_T_BRACKET_OPEN,  SL("(") },
  { PHQL_T_BRACKET_CLOSE, SL(")") },
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

	char *error, *error_part;
	unsigned int length;
	phql_scanner_state *state = parser_status->scanner_state;

	PHALCON_INIT_VAR(*error_msg);
	if (state->start) {
		length = 48 + state->start_length;
		error = emalloc(sizeof(char) * length);
		if (state->start_length > 16) {
			error_part = estrndup(state->start, 16);
			snprintf(error, length, "Parsing error before '%s...'", error_part);
			efree(error_part);
		} else {
			snprintf(error, length, "Parsing error before '%s'", state->start);
		}
		error[length - 1] = '\0';
		ZVAL_STRING(*error_msg, error, 1);
	} else {
		error = emalloc(sizeof(char) * 48);
		sprintf(error, "Parsing error near to EOF");
		ZVAL_STRING(*error_msg, error, 1);
	}
	efree(error);
}

/**
 * Executes the internal PHQL parser/tokenizer
 */
int phql_parse_phql(zval *result, zval *phql TSRMLS_DC) {

	zval *error_msg = NULL;

	ZVAL_NULL(result);

	if (phql_internal_parse_phql(&result, Z_STRVAL_P(phql), Z_STRLEN_P(phql), &error_msg TSRMLS_CC) == FAILURE) {
		phalcon_throw_exception_string(phalcon_mvc_model_exception_ce, Z_STRVAL_P(error_msg), Z_STRLEN_P(error_msg) TSRMLS_CC);
		return FAILURE;
	}

	return SUCCESS;
}

/**
 * Executes a PHQL parser/tokenizer
 */
int phql_internal_parse_phql(zval **result, char *phql, unsigned int phql_length, zval **error_msg TSRMLS_DC) {

	char *error;
	phql_scanner_state *state;
	phql_scanner_token token;
	int scanner_status, status = SUCCESS;
	phql_parser_status *parser_status = NULL;
	void* phql_parser;
	zval **temp_ast;

	if (!phql) {
		PHALCON_INIT_VAR(*error_msg);
		ZVAL_STRING(*error_msg, "PHQL statement cannot be NULL", 1);
		return FAILURE;
	}

	if (PHALCON_GLOBAL(orm.parser_cache) != NULL) {
		if (zend_hash_find(PHALCON_GLOBAL(orm.parser_cache), phql, phql_length, (void**) &temp_ast) == SUCCESS) {
			ZVAL_ZVAL(*result, *temp_ast, 1, 0);
			Z_SET_REFCOUNT_P(*result, 1);
			return SUCCESS;
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
			case PHQL_T_AGAINST:
				phql_(phql_parser, PHQL_AGAINST, NULL, parser_status);
				break;
			case PHQL_T_DOT:
				phql_(phql_parser, PHQL_DOT, NULL, parser_status);
				break;
			case PHQL_T_COMMA:
				phql_(phql_parser, PHQL_COMMA, NULL, parser_status);
				break;

			case PHQL_T_BRACKET_OPEN:
				phql_(phql_parser, PHQL_BRACKET_OPEN, NULL, parser_status);
				break;
			case PHQL_T_BRACKET_CLOSE:
				phql_(phql_parser, PHQL_BRACKET_CLOSE, NULL, parser_status);
				break;

			case PHQL_T_INTEGER:
				phql_parse_with_token(phql_parser, PHQL_T_INTEGER, PHQL_INTEGER, &token, parser_status);
				break;
			case PHQL_T_DOUBLE:
				phql_parse_with_token(phql_parser, PHQL_T_DOUBLE, PHQL_DOUBLE, &token, parser_status);
				break;
			case PHQL_T_STRING:
				phql_parse_with_token(phql_parser, PHQL_T_STRING, PHQL_STRING, &token, parser_status);
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
			default:
				parser_status->status = PHQL_PARSING_FAILED;
				error = emalloc(sizeof(char) * 32);
				sprintf(error, "scanner: unknown opcode %c", token.opcode);
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

				ZVAL_ZVAL(*result, parser_status->ret, 0, 0);
				ZVAL_NULL(parser_status->ret);
				zval_ptr_dtor(&parser_status->ret);

				if (!PHALCON_GLOBAL(orm.parser_cache)) {
					ALLOC_HASHTABLE(PHALCON_GLOBAL(orm.parser_cache));
					zend_hash_init(PHALCON_GLOBAL(orm.parser_cache), 0, NULL, ZVAL_PTR_DTOR, 0);
				}

				Z_ADDREF_PP(result);

				zend_hash_update(
					PHALCON_GLOBAL(orm.parser_cache),
					phql,
					phql_length,
					result,
					sizeof(zval *),
					NULL
				);

			} else {
				efree(parser_status->ret);
			}
		}
	}

	efree(parser_status);
	efree(state);

	return status;
}