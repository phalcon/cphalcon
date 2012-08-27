/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is include which follows the "include" declaration
** in the input file. */
#include <stdio.h>
#line 35 "parser.lemon"


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "parser.h"
#include "scanner.h"
#include "lang.h"

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
		add_assoc_stringl(ret, "value", T->token, T->token_len, 1);
		efree(T->token);
		efree(T);
	}

	return ret;
}

static zval *phql_ret_placeholder_zval(int type, phql_parser_token *T)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", type);
	add_assoc_stringl(ret, "value", T->token, T->token_len, 1);
	efree(T->token);
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
		add_assoc_stringl(ret, "domain", A->token, A->token_len, 1);
		add_assoc_stringl(ret, "name", B->token, B->token_len, 1);
		efree(B->token);
		efree(B);
	} else {
		add_assoc_stringl(ret, "name", A->token, A->token_len, 1);
	}
	efree(A->token);
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
	array_init(ret);
	add_assoc_zval(ret, "tables", tables);
	add_assoc_zval(ret, "values", values);

	return ret;
}

static zval *phql_ret_update_item(zval *column, zval *expr)
{

	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
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
	array_init(ret);
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

	add_next_index_zval(ret, right_list);

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
		add_assoc_stringl(ret, "column", identifier_column->token, identifier_column->token_len, 1);
		efree(identifier_column->token);
		efree(identifier_column);
	}
	if (alias) {
		add_assoc_stringl(ret, "alias", alias->token, alias->token_len, 1);
		efree(alias->token);
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
		add_assoc_stringl(ret, "alias", alias->token, alias->token_len, 1);
		efree(alias->token);
		efree(alias);
	}

	return ret;

}

static zval *phql_ret_join_item(zval *join, phql_parser_token *alias)
{

	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_zval(ret, "join", join);
	if (alias) {
		add_assoc_stringl(ret, "alias", alias->token, alias->token_len, 1);
		efree(alias->token);
		efree(alias);
	}

	return ret;

}

static zval *phql_ret_join_clause(int type, zval *qualified_name, zval *expr)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", type);
	add_assoc_zval(ret, "qualifiedName", qualified_name);
	if (expr) {
		add_assoc_zval(ret, "expr", expr);
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
	add_assoc_stringl(ret, "name", name->token, name->token_len, 1);
	efree(name->token);
	efree(name);

	if (arguments) {
		add_assoc_zval(ret, "arguments", arguments);
	}

	return ret;
}


#line 377 "parser.c"
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
#define YYNOCODE 96
#define YYACTIONTYPE unsigned short int
#define phql_TOKENTYPE phql_parser_token*
typedef union {
  phql_TOKENTYPE yy0;
  zval* yy48;
  int yy191;
} YYMINORTYPE;
#define YYSTACKDEPTH 100
#define phql_ARG_SDECL phql_parser_status *status;
#define phql_ARG_PDECL ,phql_parser_status *status
#define phql_ARG_FETCH phql_parser_status *status = yypParser->status
#define phql_ARG_STORE yypParser->status = status
#define YYNSTATE 238
#define YYNRULE 140
#define YYERRORSYMBOL 54
#define YYERRSYMDT yy191
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
 /*     0 */    65,   68,   71,   39,   36,   43,   41,   45,   63,   47,
 /*    10 */    49,   51,   53,   55,   57,   59,   61,    7,  113,  115,
 /*    20 */   192,  123,  190,    9,   65,   68,   71,   39,   36,   43,
 /*    30 */    41,   45,   63,   47,   49,   51,   53,   55,   57,   59,
 /*    40 */    61,   65,   68,   71,   39,   36,   43,   41,   45,   63,
 /*    50 */    47,   49,   51,   53,   55,   57,   59,   61,  238,   90,
 /*    60 */    43,   41,   45,   63,   47,   49,   51,   53,   55,   57,
 /*    70 */    59,   61,   86,   77,   70,  239,   37,  240,   85,   91,
 /*    80 */   241,  379,    1,    2,    3,    4,    5,    6,   70,   76,
 /*    90 */    25,   28,   79,   91,   86,   75,   78,   84,   37,  242,
 /*   100 */    85,   19,   30,   22,   80,  252,   88,   83,  216,   81,
 /*   110 */    78,   84,  231,  130,   79,  245,   92,  181,  132,  133,
 /*   120 */    95,   93,   94,   96,   97,  129,   70,   25,   88,  182,
 /*   130 */    86,   91,  203,  177,   37,   11,  185,   91,   92,   21,
 /*   140 */    22,  202,   95,   93,   94,   96,   97,  101,   78,   84,
 /*   150 */   186,  175,   86,   27,   78,  137,   37,  141,  146,  149,
 /*   160 */   339,  159,  169,   10,   88,   51,   53,   55,   57,   59,
 /*   170 */    61,   27,   79,   31,   92,   13,   33,   26,   95,   93,
 /*   180 */    94,   96,   97,  243,  110,   14,   88,  137,   16,  141,
 /*   190 */   146,  149,  150,  159,  169,  111,   92,  154,  107,  112,
 /*   200 */    95,   93,   94,   96,   97,   15,   63,   47,   49,   51,
 /*   210 */    53,   55,   57,   59,   61,   47,   49,   51,   53,   55,
 /*   220 */    57,   59,   61,  124,   17,  244,  128,  183,  203,  105,
 /*   230 */   110,   10,  127,   91,  199,  193,  189,  204,  203,  246,
 /*   240 */   126,   91,  261,   91,  210,  109,   70,  204,   35,  260,
 /*   250 */    78,   91,  103,   91,  194,  247,  254,   91,   78,  220,
 /*   260 */    78,  235,   23,   24,    8,   12,   17,  104,   78,   98,
 /*   270 */    78,  105,   18,   10,   78,  131,  132,  133,  184,  189,
 /*   280 */    17,  176,   29,   17,   91,  177,   34,   10,  229,   34,
 /*   290 */    10,  250,   38,   91,   40,   42,   17,   91,   99,   91,
 /*   300 */    91,   78,  228,   10,   44,   66,   46,   48,   50,   91,
 /*   310 */    78,   91,   91,   91,   78,   52,   78,   78,   54,   56,
 /*   320 */    91,  263,   58,   91,   91,  248,   78,   91,   78,   78,
 /*   330 */    78,   60,  116,   62,  118,  122,   91,   78,   91,   10,
 /*   340 */    78,   78,   64,   67,   78,   87,   89,   91,   91,  140,
 /*   350 */    91,   91,  125,   78,   91,   78,  145,   91,  153,  307,
 /*   360 */   316,   91,   17,   91,   78,   78,   73,   78,   78,   10,
 /*   370 */    77,   78,  158,   10,   78,  255,  163,   91,   78,  168,
 /*   380 */    78,   91,  174,  226,   91,  256,   82,   91,  257,   77,
 /*   390 */   223,  230,  119,  187,   78,  121,   28,  160,   78,  124,
 /*   400 */   124,   78,  164,  188,   78,  102,   80,   10,   10,  308,
 /*   410 */   136,  180,  134,  178,   72,  197,  205,   29,  201,  206,
 /*   420 */   226,  212,  215,   10,  201,  217,  221,  317,  225,  219,
 /*   430 */   177,   20,   32,   10,  200,  249,   10,  207,  232,  237,
 /*   440 */   211,  253,  234,  177,   74,   69,  251,  100,  106,  108,
 /*   450 */   114,  258,  117,  259,  265,  264,  262,   10,  120,  266,
 /*   460 */    27,  135,  139,  138,  195,  170,  142,  143,  144,  147,
 /*   470 */   148,  299,  152,  151,  155,   10,  156,  157,  161,  166,
 /*   480 */   300,  172,  162,  167,  165,  171,  214,  173,  179,  191,
 /*   490 */   196,  218,  310,  309,  213,  224,  227,  319,  198,  209,
 /*   500 */   208,  318,  236,  237,  233,  237,  237,  222,
};
static YYCODETYPE yy_lookahead[] = {
 /*     0 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    10 */    11,   12,   13,   14,   15,   16,   17,   62,   63,   64,
 /*    20 */    21,   66,   23,   66,    1,    2,    3,    4,    5,    6,
 /*    30 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*    40 */    17,    1,    2,    3,    4,    5,    6,    7,    8,    9,
 /*    50 */    10,   11,   12,   13,   14,   15,   16,   17,    0,   36,
 /*    60 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*    70 */    16,   17,    1,   20,   71,    0,    5,    0,    7,   76,
 /*    80 */     0,   55,   56,   57,   58,   59,   60,   61,   71,   36,
 /*    90 */    76,   22,   21,   76,    1,   92,   93,   94,    5,    0,
 /*   100 */     7,   87,   88,   89,   35,    0,   35,   36,   82,   92,
 /*   110 */    93,   94,   86,   69,   21,    0,   45,   73,   74,   75,
 /*   120 */    49,   50,   51,   52,   53,   68,   71,   76,   35,   72,
 /*   130 */     1,   76,   71,   76,    5,   45,    7,   76,   45,   88,
 /*   140 */    89,   80,   49,   50,   51,   52,   53,   92,   93,   94,
 /*   150 */    21,   20,    1,   21,   93,   24,    5,   26,   27,   28,
 /*   160 */     0,   30,   31,   48,   35,   12,   13,   14,   15,   16,
 /*   170 */    17,   21,   21,   63,   45,   65,   66,   45,   49,   50,
 /*   180 */    51,   52,   53,    0,   76,   63,   35,   24,   66,   26,
 /*   190 */    27,   28,   24,   30,   31,   45,   45,   29,   90,   91,
 /*   200 */    49,   50,   51,   52,   53,   66,    9,   10,   11,   12,
 /*   210 */    13,   14,   15,   16,   17,   10,   11,   12,   13,   14,
 /*   220 */    15,   16,   17,   40,   41,    0,   19,   20,   71,   46,
 /*   230 */    76,   48,   67,   76,   77,   70,   71,   80,   71,    0,
 /*   240 */    18,   76,    0,   76,   77,   91,   71,   80,   71,    0,
 /*   250 */    93,   76,   71,   76,   32,    0,    0,   76,   93,   37,
 /*   260 */    93,   39,   43,   44,   63,   64,   41,   66,   93,   94,
 /*   270 */    93,   46,   42,   48,   93,   73,   74,   75,   70,   71,
 /*   280 */    41,   72,   21,   41,   76,   76,   47,   48,   71,   47,
 /*   290 */    48,    0,   71,   76,   71,   71,   41,   76,    2,   76,
 /*   300 */    76,   93,   85,   48,   71,    9,   71,   71,   71,   76,
 /*   310 */    93,   76,   76,   76,   93,   71,   93,   93,   71,   71,
 /*   320 */    76,    0,   71,   76,   76,    0,   93,   76,   93,   93,
 /*   330 */    93,   71,   63,   71,   65,   66,   76,   93,   76,   48,
 /*   340 */    93,   93,   71,   71,   93,   71,   71,   76,   76,   71,
 /*   350 */    76,   76,   71,   93,   76,   93,   71,   76,   71,    0,
 /*   360 */     0,   76,   41,   76,   93,   93,    1,   93,   93,   48,
 /*   370 */    20,   93,   71,   48,   93,    0,   71,   76,   93,   71,
 /*   380 */    93,   76,   71,   76,   76,    0,   36,   76,    0,   20,
 /*   390 */    83,   84,   63,   22,   93,   66,   22,   24,   93,   40,
 /*   400 */    40,   93,   29,    7,   93,   36,   35,   48,   48,    0,
 /*   410 */    21,   21,   23,   23,   49,   34,   35,   21,   20,   78,
 /*   420 */    76,   20,   81,   48,   20,   62,   72,    0,   84,   66,
 /*   430 */    76,   20,   66,   48,   36,    0,   48,   36,   62,   72,
 /*   440 */    36,    0,   66,   76,   49,   35,    0,   35,   42,   20,
 /*   450 */    66,    0,   66,    0,    0,    0,    0,   48,   66,    0,
 /*   460 */    21,   21,   25,   76,   33,   29,   24,   76,   25,   24,
 /*   470 */    76,    0,   25,   76,   24,   48,   76,   25,   76,   76,
 /*   480 */     0,   76,   25,   25,   24,   24,   21,   25,   21,   21,
 /*   490 */    76,   66,    0,    0,   81,   20,   12,    0,   35,   35,
 /*   500 */    34,    0,   19,   95,   66,   95,   95,   38,
};
#define YY_SHIFT_USE_DFLT (-2)
static short yy_shift_ofst[] = {
 /*     0 */   222,   58,   75,   77,   80,   99,  183,  225,  115,  105,
 /*    10 */    90,  160,  239,  255,  291,  249,  256,  230,  132,  411,
 /*    20 */   132,   -2,  219,   -2,   -2,   -2,   -2,  374,  261,   -2,
 /*    30 */    -2,  325,  435,  441,  151,   40,  151,  151,   54,  151,
 /*    40 */    54,  151,  197,  151,  197,  151,  197,  151,  153,  151,
 /*    50 */   153,  151,   -2,  151,   -2,  151,   -2,  151,   -2,  151,
 /*    60 */    -2,  151,   -2,  151,  205,  296,  151,   40,  410,   93,
 /*    70 */    40,  365,   -2,  395,   -2,   53,   -2,   93,   -2,   69,
 /*    80 */    71,  350,   -2,   -2,   -2,   -2,  151,   40,  151,   23,
 /*    90 */    -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,  412,
 /*   100 */    93,  369,   -2,   54,  446,  406,  150,  429,  150,   -2,
 /*   110 */    -2,   -2,   -2,  375,  451,  242,  385,  453,  321,  388,
 /*   120 */   454,  455,  456,  459,  151,   40,  129,  207,  439,  131,
 /*   130 */   163,   -2,   -2,  389,  440,   -2,   -2,  439,  437,  151,
 /*   140 */    40,  442,  439,  443,  151,   40,  445,  439,   -2,  168,
 /*   150 */   439,  447,  151,   40,  450,  439,  452,  151,   40,  373,
 /*   160 */   439,  457,  151,   40,  460,  439,  458,  151,   40,  436,
 /*   170 */   461,  439,  462,  151,   40,  439,   -2,  390,  467,   -2,
 /*   180 */    -2,   -2,   -2,  129,   -2,   -2,  371,  396,   -2,   -1,
 /*   190 */   468,   -2,   -2,   -2,  431,  439,  381,  463,  151,  398,
 /*   200 */   471,  151,   -2,   40,   -2,  465,  401,  466,  464,  151,
 /*   210 */   404,  480,  465,   -2,   -2,   -2,  359,  409,  492,  493,
 /*   220 */   439,  469,  439,  475,  439,   -2,  484,  151,   -2,   40,
 /*   230 */    -2,  360,  427,  497,  501,  483,  439,   -2,
};
#define YY_REDUCE_USE_DFLT (-46)
static short yy_reduce_ofst[] = {
 /*     0 */    26,  -46,  -46,  -46,  -46,  -46,  -45,  201,  -43,  -46,
 /*    10 */   -46,  -46,  110,  122,  139,  -46,  -46,  -46,   14,  -46,
 /*    20 */    51,  -46,  -46,  -46,  -46,  -46,  -46,  -46,  -46,  -46,
 /*    30 */   -46,  366,  -46,  -46,  177,  -46,  181,  221,  -46,  223,
 /*    40 */   -46,  224,  -46,  233,  -46,  235,  -46,  236,  -46,  237,
 /*    50 */   -46,  244,  -46,  247,  -46,  248,  -46,  251,  -46,  260,
 /*    60 */   -46,  262,  -46,  271,  -46,  -46,  272,  -46,  -46,    3,
 /*    70 */   -46,  -46,  -46,  -46,  -46,  -46,  -46,  175,  -46,  -46,
 /*    80 */    17,  -46,  -46,  -46,  -46,  -46,  274,  -46,  275,  -46,
 /*    90 */   -46,  -46,  -46,  -46,  -46,  -46,  -46,  -46,  -46,  -46,
 /*   100 */    55,  -46,  -46,  -46,  -46,  -46,  108,  -46,  154,  -46,
 /*   110 */   -46,  -46,  -46,  384,  -46,  269,  386,  -46,  329,  392,
 /*   120 */   -46,  -46,  -46,  -46,  281,  -46,  165,  -46,   57,   44,
 /*   130 */   202,  -46,  -46,  -46,  -46,  -46,  -46,  387,  -46,  278,
 /*   140 */   -46,  -46,  391,  -46,  285,  -46,  -46,  394,  -46,  -46,
 /*   150 */   397,  -46,  287,  -46,  -46,  400,  -46,  301,  -46,  -46,
 /*   160 */   402,  -46,  305,  -46,  -46,  403,  -46,  308,  -46,  -46,
 /*   170 */   -46,  405,  -46,  311,  -46,  209,  -46,  -46,  -46,  -46,
 /*   180 */   -46,  -46,  -46,  208,  -46,  -46,  -46,  -46,  -46,  -46,
 /*   190 */   -46,  -46,  -46,  -46,  -46,  414,  -46,  -46,  157,  -46,
 /*   200 */   -46,   61,  -46,  -46,  -46,  341,  -46,  -46,  -46,  167,
 /*   210 */   -46,  -46,  413,  -46,  -46,  -46,  363,  425,  -46,  -46,
 /*   220 */   354,  -46,  307,  -46,  344,  -46,  -46,  217,  -46,  -46,
 /*   230 */   -46,  376,  438,  -46,  -46,  -46,  367,  -46,
};
static YYACTIONTYPE yy_default[] = {
 /*     0 */   378,  378,  378,  378,  378,  378,  378,  378,  378,  378,
 /*    10 */   378,  378,  378,  378,  378,  378,  378,  378,  378,  325,
 /*    20 */   378,  326,  328,  329,  330,  331,  332,  377,  378,  376,
 /*    30 */   327,  378,  378,  378,  378,  338,  378,  378,  340,  378,
 /*    40 */   342,  378,  343,  378,  344,  378,  345,  378,  346,  378,
 /*    50 */   347,  378,  348,  378,  349,  378,  350,  378,  351,  378,
 /*    60 */   352,  378,  353,  378,  354,  378,  378,  355,  378,  378,
 /*    70 */   364,  378,  365,  378,  366,  378,  356,  378,  358,  377,
 /*    80 */   378,  378,  359,  360,  362,  363,  378,  367,  378,  378,
 /*    90 */   368,  369,  370,  371,  372,  373,  374,  375,  361,  378,
 /*   100 */   378,  378,  357,  341,  378,  378,  378,  333,  378,  334,
 /*   110 */   336,  337,  335,  378,  378,  378,  378,  378,  378,  378,
 /*   120 */   378,  378,  378,  378,  378,  324,  378,  378,  378,  267,
 /*   130 */   268,  278,  280,  281,  378,  282,  283,  378,  284,  378,
 /*   140 */   285,  378,  378,  286,  378,  287,  378,  378,  288,  378,
 /*   150 */   378,  289,  378,  291,  378,  378,  290,  378,  292,  378,
 /*   160 */   378,  293,  378,  295,  378,  378,  294,  378,  296,  378,
 /*   170 */   378,  378,  297,  378,  298,  378,  276,  323,  378,  321,
 /*   180 */   322,  279,  277,  378,  269,  271,  377,  378,  272,  275,
 /*   190 */   378,  273,  274,  270,  378,  378,  378,  378,  378,  378,
 /*   200 */   378,  378,  301,  303,  302,  378,  378,  378,  378,  378,
 /*   210 */   378,  378,  378,  304,  306,  305,  378,  378,  378,  378,
 /*   220 */   378,  378,  378,  311,  378,  312,  378,  378,  314,  315,
 /*   230 */   313,  378,  378,  378,  378,  378,  378,  320,
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
  "$",             "NOT",           "IN",            "IS",          
  "PLUS",          "MINUS",         "DIVIDE",        "TIMES",       
  "MOD",           "LIKE",          "AND",           "OR",          
  "EQUALS",        "NOTEQUALS",     "LESS",          "GREATER",     
  "GREATEREQUAL",  "LESSEQUAL",     "SELECT",        "FROM",        
  "COMMA",         "IDENTIFIER",    "DOT",           "AS",          
  "JOIN",          "ON",            "INNER",         "CROSS",       
  "LEFT",          "OUTER",         "RIGHT",         "FULL",        
  "INSERT",        "INTO",          "VALUES",        "BRACKET_OPEN",
  "BRACKET_CLOSE",  "UPDATE",        "SET",           "DELETE",      
  "WHERE",         "ORDER",         "BY",            "ASC",         
  "DESC",          "INTEGER",       "GROUP",         "HAVING",      
  "LIMIT",         "NULL",          "STRING",        "DOUBLE",      
  "NPLACEHOLDER",  "SPLACEHOLDER",  "error",         "program",     
  "query_language",  "select_statement",  "insert_statement",  "update_statement",
  "delete_statement",  "select_clause",  "where_clause",  "order_clause",
  "group_clause",  "having_clause",  "limit_clause",  "column_list", 
  "associated_name_list",  "join_list",     "column_item",   "expr",        
  "associated_name",  "join_item",     "join_associated_name",  "join_clause", 
  "qualified_name",  "values_list",   "field_list",    "value_list",  
  "value_item",    "field_item",    "update_clause",  "update_item_list",
  "update_item",   "new_value",     "delete_clause",  "order_list",  
  "order_item",    "order_qualified_or_int",  "group_list",    "group_item",  
  "argument_list",  "function_call",  "argument_item",
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
 /*  11 */ "select_statement ::= select_clause where_clause group_clause order_clause limit_clause",
 /*  12 */ "select_statement ::= select_clause where_clause group_clause having_clause order_clause",
 /*  13 */ "select_statement ::= select_clause where_clause limit_clause",
 /*  14 */ "select_statement ::= select_clause where_clause order_clause limit_clause",
 /*  15 */ "select_statement ::= select_clause where_clause group_clause limit_clause",
 /*  16 */ "select_statement ::= select_clause where_clause group_clause having_clause limit_clause",
 /*  17 */ "select_statement ::= select_clause order_clause",
 /*  18 */ "select_statement ::= select_clause group_clause order_clause",
 /*  19 */ "select_statement ::= select_clause group_clause having_clause order_clause",
 /*  20 */ "select_statement ::= select_clause order_clause limit_clause",
 /*  21 */ "select_statement ::= select_clause group_clause order_clause limit_clause",
 /*  22 */ "select_statement ::= select_clause where_clause group_clause having_clause order_clause limit_clause",
 /*  23 */ "select_statement ::= select_clause group_clause",
 /*  24 */ "select_statement ::= select_clause group_clause limit_clause",
 /*  25 */ "select_statement ::= select_clause group_clause having_clause",
 /*  26 */ "select_statement ::= select_clause group_clause having_clause limit_clause",
 /*  27 */ "select_statement ::= select_clause group_clause having_clause order_clause limit_clause",
 /*  28 */ "select_statement ::= select_clause limit_clause",
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
 /*  42 */ "join_item ::= join_associated_name",
 /*  43 */ "join_associated_name ::= join_clause",
 /*  44 */ "join_associated_name ::= join_clause AS IDENTIFIER",
 /*  45 */ "join_associated_name ::= join_clause IDENTIFIER",
 /*  46 */ "join_clause ::= JOIN qualified_name",
 /*  47 */ "join_clause ::= JOIN qualified_name ON expr",
 /*  48 */ "join_clause ::= INNER JOIN qualified_name",
 /*  49 */ "join_clause ::= INNER JOIN qualified_name ON expr",
 /*  50 */ "join_clause ::= CROSS JOIN qualified_name",
 /*  51 */ "join_clause ::= LEFT JOIN qualified_name",
 /*  52 */ "join_clause ::= LEFT OUTER JOIN qualified_name",
 /*  53 */ "join_clause ::= LEFT JOIN qualified_name ON expr",
 /*  54 */ "join_clause ::= LEFT OUTER JOIN qualified_name ON expr",
 /*  55 */ "join_clause ::= RIGHT JOIN qualified_name",
 /*  56 */ "join_clause ::= RIGHT OUTER JOIN qualified_name",
 /*  57 */ "join_clause ::= RIGHT JOIN qualified_name ON expr",
 /*  58 */ "join_clause ::= RIGHT OUTER JOIN qualified_name ON expr",
 /*  59 */ "join_clause ::= FULL OUTER JOIN qualified_name",
 /*  60 */ "join_clause ::= FULL OUTER JOIN qualified_name ON expr",
 /*  61 */ "insert_statement ::= INSERT INTO qualified_name VALUES BRACKET_OPEN values_list BRACKET_CLOSE",
 /*  62 */ "insert_statement ::= INSERT INTO qualified_name BRACKET_OPEN field_list BRACKET_CLOSE VALUES BRACKET_OPEN values_list BRACKET_CLOSE",
 /*  63 */ "values_list ::= values_list COMMA value_item",
 /*  64 */ "values_list ::= value_item",
 /*  65 */ "value_item ::= expr",
 /*  66 */ "field_list ::= field_list COMMA field_item",
 /*  67 */ "field_list ::= field_item",
 /*  68 */ "field_item ::= IDENTIFIER",
 /*  69 */ "update_statement ::= update_clause",
 /*  70 */ "update_statement ::= update_clause where_clause",
 /*  71 */ "update_statement ::= update_clause limit_clause",
 /*  72 */ "update_statement ::= update_clause where_clause limit_clause",
 /*  73 */ "update_clause ::= UPDATE associated_name SET update_item_list",
 /*  74 */ "update_item_list ::= update_item_list COMMA update_item",
 /*  75 */ "update_item_list ::= update_item",
 /*  76 */ "update_item ::= qualified_name EQUALS new_value",
 /*  77 */ "new_value ::= expr",
 /*  78 */ "delete_statement ::= delete_clause",
 /*  79 */ "delete_statement ::= delete_clause where_clause",
 /*  80 */ "delete_statement ::= delete_clause limit_clause",
 /*  81 */ "delete_statement ::= delete_clause where_clause limit_clause",
 /*  82 */ "delete_clause ::= DELETE FROM associated_name",
 /*  83 */ "associated_name ::= qualified_name AS IDENTIFIER",
 /*  84 */ "associated_name ::= qualified_name IDENTIFIER",
 /*  85 */ "associated_name ::= qualified_name",
 /*  86 */ "where_clause ::= WHERE expr",
 /*  87 */ "order_clause ::= ORDER BY order_list",
 /*  88 */ "order_list ::= order_list COMMA order_item",
 /*  89 */ "order_list ::= order_item",
 /*  90 */ "order_item ::= order_qualified_or_int",
 /*  91 */ "order_item ::= order_qualified_or_int ASC",
 /*  92 */ "order_item ::= order_qualified_or_int DESC",
 /*  93 */ "order_qualified_or_int ::= qualified_name",
 /*  94 */ "order_qualified_or_int ::= INTEGER",
 /*  95 */ "group_clause ::= GROUP BY group_list",
 /*  96 */ "group_list ::= group_list COMMA group_item",
 /*  97 */ "group_list ::= group_item",
 /*  98 */ "group_item ::= qualified_name",
 /*  99 */ "group_item ::= INTEGER",
 /* 100 */ "having_clause ::= HAVING expr",
 /* 101 */ "limit_clause ::= LIMIT INTEGER",
 /* 102 */ "expr ::= MINUS expr",
 /* 103 */ "expr ::= expr MINUS expr",
 /* 104 */ "expr ::= expr PLUS expr",
 /* 105 */ "expr ::= expr TIMES expr",
 /* 106 */ "expr ::= expr DIVIDE expr",
 /* 107 */ "expr ::= expr MOD expr",
 /* 108 */ "expr ::= expr AND expr",
 /* 109 */ "expr ::= expr OR expr",
 /* 110 */ "expr ::= expr EQUALS expr",
 /* 111 */ "expr ::= expr NOTEQUALS expr",
 /* 112 */ "expr ::= expr LESS expr",
 /* 113 */ "expr ::= expr GREATER expr",
 /* 114 */ "expr ::= expr GREATEREQUAL expr",
 /* 115 */ "expr ::= expr LESSEQUAL expr",
 /* 116 */ "expr ::= expr LIKE expr",
 /* 117 */ "expr ::= expr NOT LIKE expr",
 /* 118 */ "expr ::= expr IN BRACKET_OPEN argument_list BRACKET_CLOSE",
 /* 119 */ "expr ::= expr NOT IN BRACKET_OPEN argument_list BRACKET_CLOSE",
 /* 120 */ "expr ::= function_call",
 /* 121 */ "function_call ::= IDENTIFIER BRACKET_OPEN argument_list BRACKET_CLOSE",
 /* 122 */ "function_call ::= IDENTIFIER BRACKET_OPEN BRACKET_CLOSE",
 /* 123 */ "argument_list ::= argument_list COMMA argument_item",
 /* 124 */ "argument_list ::= argument_item",
 /* 125 */ "argument_item ::= TIMES",
 /* 126 */ "argument_item ::= expr",
 /* 127 */ "expr ::= expr IS NULL",
 /* 128 */ "expr ::= expr IS NOT NULL",
 /* 129 */ "expr ::= NOT expr",
 /* 130 */ "expr ::= BRACKET_OPEN expr BRACKET_CLOSE",
 /* 131 */ "expr ::= qualified_name",
 /* 132 */ "expr ::= INTEGER",
 /* 133 */ "expr ::= STRING",
 /* 134 */ "expr ::= DOUBLE",
 /* 135 */ "expr ::= NULL",
 /* 136 */ "expr ::= NPLACEHOLDER",
 /* 137 */ "expr ::= SPLACEHOLDER",
 /* 138 */ "qualified_name ::= IDENTIFIER DOT IDENTIFIER",
 /* 139 */ "qualified_name ::= IDENTIFIER",
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
#line 447 "parser.lemon"
{
	if ((yypminor->yy0)) {
		efree((yypminor->yy0)->token);
		efree((yypminor->yy0));
	}
}
#line 1053 "parser.c"
      break;
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
    case 78:
    case 79:
    case 81:
    case 82:
    case 83:
    case 84:
    case 86:
    case 87:
    case 88:
    case 90:
    case 91:
    case 92:
    case 93:
    case 94:
#line 458 "parser.lemon"
{ zval_ptr_dtor(&(yypminor->yy48)); }
#line 1092 "parser.c"
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
  { 55, 1 },
  { 56, 1 },
  { 56, 1 },
  { 56, 1 },
  { 56, 1 },
  { 57, 1 },
  { 57, 2 },
  { 57, 3 },
  { 57, 3 },
  { 57, 4 },
  { 57, 4 },
  { 57, 5 },
  { 57, 5 },
  { 57, 3 },
  { 57, 4 },
  { 57, 4 },
  { 57, 5 },
  { 57, 2 },
  { 57, 3 },
  { 57, 4 },
  { 57, 3 },
  { 57, 4 },
  { 57, 6 },
  { 57, 2 },
  { 57, 3 },
  { 57, 3 },
  { 57, 4 },
  { 57, 5 },
  { 57, 2 },
  { 61, 4 },
  { 61, 5 },
  { 67, 3 },
  { 67, 1 },
  { 70, 1 },
  { 70, 3 },
  { 70, 3 },
  { 70, 2 },
  { 70, 1 },
  { 68, 3 },
  { 68, 1 },
  { 69, 2 },
  { 69, 1 },
  { 73, 1 },
  { 74, 1 },
  { 74, 3 },
  { 74, 2 },
  { 75, 2 },
  { 75, 4 },
  { 75, 3 },
  { 75, 5 },
  { 75, 3 },
  { 75, 3 },
  { 75, 4 },
  { 75, 5 },
  { 75, 6 },
  { 75, 3 },
  { 75, 4 },
  { 75, 5 },
  { 75, 6 },
  { 75, 4 },
  { 75, 6 },
  { 58, 7 },
  { 58, 10 },
  { 77, 3 },
  { 77, 1 },
  { 80, 1 },
  { 78, 3 },
  { 78, 1 },
  { 81, 1 },
  { 59, 1 },
  { 59, 2 },
  { 59, 2 },
  { 59, 3 },
  { 82, 4 },
  { 83, 3 },
  { 83, 1 },
  { 84, 3 },
  { 85, 1 },
  { 60, 1 },
  { 60, 2 },
  { 60, 2 },
  { 60, 3 },
  { 86, 3 },
  { 72, 3 },
  { 72, 2 },
  { 72, 1 },
  { 62, 2 },
  { 63, 3 },
  { 87, 3 },
  { 87, 1 },
  { 88, 1 },
  { 88, 2 },
  { 88, 2 },
  { 89, 1 },
  { 89, 1 },
  { 64, 3 },
  { 90, 3 },
  { 90, 1 },
  { 91, 1 },
  { 91, 1 },
  { 65, 2 },
  { 66, 2 },
  { 71, 2 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 4 },
  { 71, 5 },
  { 71, 6 },
  { 71, 1 },
  { 93, 4 },
  { 93, 3 },
  { 92, 3 },
  { 92, 1 },
  { 94, 1 },
  { 94, 1 },
  { 71, 3 },
  { 71, 4 },
  { 71, 2 },
  { 71, 3 },
  { 71, 1 },
  { 71, 1 },
  { 71, 1 },
  { 71, 1 },
  { 71, 1 },
  { 71, 1 },
  { 71, 1 },
  { 76, 3 },
  { 76, 1 },
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
#line 454 "parser.lemon"
{
	status->ret = yymsp[0].minor.yy48;
}
#line 1449 "parser.c"
        break;
      case 1:
      case 2:
      case 3:
      case 4:
      case 32:
      case 39:
      case 41:
      case 42:
      case 64:
      case 65:
      case 67:
      case 75:
      case 77:
      case 89:
      case 93:
      case 97:
      case 98:
      case 120:
      case 124:
      case 126:
      case 131:
#line 460 "parser.lemon"
{
	yygotominor.yy48 = yymsp[0].minor.yy48;
}
#line 1476 "parser.c"
        break;
      case 5:
#line 478 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[0].minor.yy48, NULL, NULL, NULL, NULL, NULL);
}
#line 1483 "parser.c"
        break;
      case 6:
#line 482 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL, NULL, NULL, NULL);
}
#line 1490 "parser.c"
        break;
      case 7:
#line 486 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL, NULL, NULL);
}
#line 1497 "parser.c"
        break;
      case 8:
#line 490 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy48, NULL, NULL);
}
#line 1504 "parser.c"
        break;
      case 9:
#line 494 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, yymsp[-2].minor.yy48, NULL, yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL);
}
#line 1511 "parser.c"
        break;
      case 10:
#line 498 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, yymsp[-2].minor.yy48, yymsp[0].minor.yy48, yymsp[-1].minor.yy48, NULL, NULL);
}
#line 1518 "parser.c"
        break;
      case 11:
#line 502 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-4].minor.yy48, yymsp[-3].minor.yy48, yymsp[-1].minor.yy48, yymsp[-2].minor.yy48, NULL, yymsp[0].minor.yy48);
}
#line 1525 "parser.c"
        break;
      case 12:
#line 506 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-4].minor.yy48, yymsp[-3].minor.yy48, yymsp[0].minor.yy48, yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, NULL);
}
#line 1532 "parser.c"
        break;
      case 13:
#line 510 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, NULL, NULL, NULL, yymsp[0].minor.yy48);
}
#line 1539 "parser.c"
        break;
      case 14:
#line 514 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, NULL, NULL, yymsp[0].minor.yy48);
}
#line 1546 "parser.c"
        break;
      case 15:
#line 518 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, yymsp[-2].minor.yy48, NULL, yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy48);
}
#line 1553 "parser.c"
        break;
      case 16:
#line 522 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-4].minor.yy48, yymsp[-3].minor.yy48, NULL, yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
}
#line 1560 "parser.c"
        break;
      case 17:
#line 526 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy48, NULL, NULL, NULL);
}
#line 1567 "parser.c"
        break;
      case 18:
#line 530 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-2].minor.yy48, NULL, yymsp[0].minor.yy48, yymsp[-1].minor.yy48, NULL, NULL);
}
#line 1574 "parser.c"
        break;
      case 19:
#line 534 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, NULL, yymsp[0].minor.yy48, yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, NULL);
}
#line 1581 "parser.c"
        break;
      case 20:
#line 538 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-2].minor.yy48, NULL, yymsp[-1].minor.yy48, NULL, NULL, yymsp[0].minor.yy48);
}
#line 1588 "parser.c"
        break;
      case 21:
#line 542 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, NULL, yymsp[-1].minor.yy48, yymsp[-2].minor.yy48, NULL, yymsp[0].minor.yy48);
}
#line 1595 "parser.c"
        break;
      case 22:
#line 546 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-5].minor.yy48, yymsp[-4].minor.yy48, yymsp[-1].minor.yy48, yymsp[-3].minor.yy48, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
}
#line 1602 "parser.c"
        break;
      case 23:
#line 550 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-1].minor.yy48, NULL, NULL, yymsp[0].minor.yy48, NULL, NULL);
}
#line 1609 "parser.c"
        break;
      case 24:
#line 554 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-2].minor.yy48, NULL, NULL, yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy48);
}
#line 1616 "parser.c"
        break;
      case 25:
#line 558 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-2].minor.yy48, NULL, NULL, yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL);
}
#line 1623 "parser.c"
        break;
      case 26:
#line 562 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, NULL, NULL, yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
}
#line 1630 "parser.c"
        break;
      case 27:
#line 566 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-4].minor.yy48, NULL, yymsp[-1].minor.yy48, yymsp[-3].minor.yy48, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
}
#line 1637 "parser.c"
        break;
      case 28:
#line 570 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-1].minor.yy48, NULL, NULL, NULL, NULL, yymsp[0].minor.yy48);
}
#line 1644 "parser.c"
        break;
      case 29:
#line 576 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_clause(yymsp[-2].minor.yy48, yymsp[0].minor.yy48, NULL);
  yy_destructor(18,&yymsp[-3].minor);
  yy_destructor(19,&yymsp[-1].minor);
}
#line 1653 "parser.c"
        break;
      case 30:
#line 580 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_clause(yymsp[-3].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(18,&yymsp[-4].minor);
  yy_destructor(19,&yymsp[-2].minor);
}
#line 1662 "parser.c"
        break;
      case 31:
      case 38:
      case 63:
      case 66:
      case 74:
      case 88:
      case 96:
      case 123:
#line 586 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_zval_list(yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(20,&yymsp[-1].minor);
}
#line 1677 "parser.c"
        break;
      case 33:
      case 125:
#line 596 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_column_item(PHQL_T_ALL, NULL, NULL, NULL);
  yy_destructor(7,&yymsp[0].minor);
}
#line 1686 "parser.c"
        break;
      case 34:
#line 600 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_column_item(PHQL_T_DOMAINALL, NULL, yymsp[-2].minor.yy0, NULL);
  yy_destructor(22,&yymsp[-1].minor);
  yy_destructor(7,&yymsp[0].minor);
}
#line 1695 "parser.c"
        break;
      case 35:
#line 604 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-2].minor.yy48, NULL, yymsp[0].minor.yy0);
  yy_destructor(23,&yymsp[-1].minor);
}
#line 1703 "parser.c"
        break;
      case 36:
#line 608 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy0);
}
#line 1710 "parser.c"
        break;
      case 37:
#line 612 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_column_item(PHQL_T_EXPR, yymsp[0].minor.yy48, NULL, NULL);
}
#line 1717 "parser.c"
        break;
      case 40:
#line 628 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_zval_list(yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
}
#line 1724 "parser.c"
        break;
      case 43:
#line 644 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_item(yymsp[0].minor.yy48, NULL);
}
#line 1731 "parser.c"
        break;
      case 44:
#line 648 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_item(yymsp[-2].minor.yy48, yymsp[0].minor.yy0);
  yy_destructor(23,&yymsp[-1].minor);
}
#line 1739 "parser.c"
        break;
      case 45:
#line 652 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_item(yymsp[-1].minor.yy48, yymsp[0].minor.yy0);
}
#line 1746 "parser.c"
        break;
      case 46:
#line 658 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_clause(PHQL_T_INNERJOIN, yymsp[0].minor.yy48, NULL);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1754 "parser.c"
        break;
      case 47:
#line 662 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_clause(PHQL_T_INNERJOIN, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1763 "parser.c"
        break;
      case 48:
#line 666 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_clause(PHQL_T_INNERJOIN, yymsp[0].minor.yy48, NULL);
  yy_destructor(26,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1772 "parser.c"
        break;
      case 49:
#line 670 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_clause(PHQL_T_INNERJOIN, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(26,&yymsp[-4].minor);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1782 "parser.c"
        break;
      case 50:
#line 674 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_clause(PHQL_T_CROSSJOIN, yymsp[0].minor.yy48, NULL);
  yy_destructor(27,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1791 "parser.c"
        break;
      case 51:
#line 678 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_clause(PHQL_T_LEFTJOIN, yymsp[0].minor.yy48, NULL);
  yy_destructor(28,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1800 "parser.c"
        break;
      case 52:
#line 682 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_clause(PHQL_T_LEFTJOIN, yymsp[0].minor.yy48, NULL);
  yy_destructor(28,&yymsp[-3].minor);
  yy_destructor(29,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1810 "parser.c"
        break;
      case 53:
#line 686 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_clause(PHQL_T_LEFTJOIN, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(28,&yymsp[-4].minor);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1820 "parser.c"
        break;
      case 54:
#line 690 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_clause(PHQL_T_LEFTJOIN, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(28,&yymsp[-5].minor);
  yy_destructor(29,&yymsp[-4].minor);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1831 "parser.c"
        break;
      case 55:
#line 694 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_clause(PHQL_T_RIGHTJOIN, yymsp[0].minor.yy48, NULL);
  yy_destructor(30,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1840 "parser.c"
        break;
      case 56:
#line 698 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_clause(PHQL_T_RIGHTJOIN, yymsp[0].minor.yy48, NULL);
  yy_destructor(30,&yymsp[-3].minor);
  yy_destructor(29,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1850 "parser.c"
        break;
      case 57:
#line 702 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_clause(PHQL_T_RIGHTJOIN, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(30,&yymsp[-4].minor);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1860 "parser.c"
        break;
      case 58:
#line 706 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_clause(PHQL_T_RIGHTJOIN, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(30,&yymsp[-5].minor);
  yy_destructor(29,&yymsp[-4].minor);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1871 "parser.c"
        break;
      case 59:
#line 710 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_clause(PHQL_T_FULLOUTER, yymsp[0].minor.yy48, NULL);
  yy_destructor(31,&yymsp[-3].minor);
  yy_destructor(29,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1881 "parser.c"
        break;
      case 60:
#line 714 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_clause(PHQL_T_FULLOUTER, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(31,&yymsp[-5].minor);
  yy_destructor(29,&yymsp[-4].minor);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1892 "parser.c"
        break;
      case 61:
#line 721 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_insert_statement(yymsp[-4].minor.yy48, NULL, yymsp[-1].minor.yy48);
  yy_destructor(32,&yymsp[-6].minor);
  yy_destructor(33,&yymsp[-5].minor);
  yy_destructor(34,&yymsp[-3].minor);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
#line 1904 "parser.c"
        break;
      case 62:
#line 725 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_insert_statement(yymsp[-7].minor.yy48, yymsp[-5].minor.yy48, yymsp[-1].minor.yy48);
  yy_destructor(32,&yymsp[-9].minor);
  yy_destructor(33,&yymsp[-8].minor);
  yy_destructor(35,&yymsp[-6].minor);
  yy_destructor(36,&yymsp[-4].minor);
  yy_destructor(34,&yymsp[-3].minor);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
#line 1918 "parser.c"
        break;
      case 68:
      case 139:
#line 755 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_qualified_name(yymsp[0].minor.yy0, NULL);
}
#line 1926 "parser.c"
        break;
      case 69:
#line 763 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_update_statement(yymsp[0].minor.yy48, NULL, NULL);
}
#line 1933 "parser.c"
        break;
      case 70:
#line 767 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_update_statement(yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL);
}
#line 1940 "parser.c"
        break;
      case 71:
#line 771 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_update_statement(yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy48);
}
#line 1947 "parser.c"
        break;
      case 72:
#line 775 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_update_statement(yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
}
#line 1954 "parser.c"
        break;
      case 73:
#line 781 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_update_clause(yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(37,&yymsp[-3].minor);
  yy_destructor(38,&yymsp[-1].minor);
}
#line 1963 "parser.c"
        break;
      case 76:
#line 797 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_update_item(yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(12,&yymsp[-1].minor);
}
#line 1971 "parser.c"
        break;
      case 78:
#line 809 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_delete_statement(yymsp[0].minor.yy48, NULL, NULL);
}
#line 1978 "parser.c"
        break;
      case 79:
#line 813 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_delete_statement(yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL);
}
#line 1985 "parser.c"
        break;
      case 80:
#line 817 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_delete_statement(yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy48);
}
#line 1992 "parser.c"
        break;
      case 81:
#line 821 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_delete_statement(yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
}
#line 1999 "parser.c"
        break;
      case 82:
#line 827 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_delete_clause(yymsp[0].minor.yy48);
  yy_destructor(39,&yymsp[-2].minor);
  yy_destructor(19,&yymsp[-1].minor);
}
#line 2008 "parser.c"
        break;
      case 83:
#line 833 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_assoc_name(yymsp[-2].minor.yy48, yymsp[0].minor.yy0);
  yy_destructor(23,&yymsp[-1].minor);
}
#line 2016 "parser.c"
        break;
      case 84:
#line 837 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_assoc_name(yymsp[-1].minor.yy48, yymsp[0].minor.yy0);
}
#line 2023 "parser.c"
        break;
      case 85:
#line 841 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_assoc_name(yymsp[0].minor.yy48, NULL);
}
#line 2030 "parser.c"
        break;
      case 86:
#line 847 "parser.lemon"
{
	yygotominor.yy48 = yymsp[0].minor.yy48;
  yy_destructor(40,&yymsp[-1].minor);
}
#line 2038 "parser.c"
        break;
      case 87:
#line 853 "parser.lemon"
{
	yygotominor.yy48 = yymsp[0].minor.yy48;
  yy_destructor(41,&yymsp[-2].minor);
  yy_destructor(42,&yymsp[-1].minor);
}
#line 2047 "parser.c"
        break;
      case 90:
#line 869 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_order_item(yymsp[0].minor.yy48, 0);
}
#line 2054 "parser.c"
        break;
      case 91:
#line 873 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_order_item(yymsp[-1].minor.yy48, PHQL_T_ASC);
  yy_destructor(43,&yymsp[0].minor);
}
#line 2062 "parser.c"
        break;
      case 92:
#line 877 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_order_item(yymsp[-1].minor.yy48, PHQL_T_DESC);
  yy_destructor(44,&yymsp[0].minor);
}
#line 2070 "parser.c"
        break;
      case 94:
      case 99:
      case 132:
#line 885 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_literal_zval(PHQL_T_INTEGER, yymsp[0].minor.yy0);
}
#line 2079 "parser.c"
        break;
      case 95:
#line 891 "parser.lemon"
{
	yygotominor.yy48 = yymsp[0].minor.yy48;
  yy_destructor(46,&yymsp[-2].minor);
  yy_destructor(42,&yymsp[-1].minor);
}
#line 2088 "parser.c"
        break;
      case 100:
#line 917 "parser.lemon"
{
	yygotominor.yy48 = yymsp[0].minor.yy48;
  yy_destructor(47,&yymsp[-1].minor);
}
#line 2096 "parser.c"
        break;
      case 101:
#line 923 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_literal_zval(PHQL_T_INTEGER, yymsp[0].minor.yy0);
  yy_destructor(48,&yymsp[-1].minor);
}
#line 2104 "parser.c"
        break;
      case 102:
#line 929 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_MINUS, NULL, yymsp[0].minor.yy48);
  yy_destructor(5,&yymsp[-1].minor);
}
#line 2112 "parser.c"
        break;
      case 103:
#line 933 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_SUB, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(5,&yymsp[-1].minor);
}
#line 2120 "parser.c"
        break;
      case 104:
#line 937 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_ADD, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(4,&yymsp[-1].minor);
}
#line 2128 "parser.c"
        break;
      case 105:
#line 941 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_MUL, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(7,&yymsp[-1].minor);
}
#line 2136 "parser.c"
        break;
      case 106:
#line 945 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_DIV, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(6,&yymsp[-1].minor);
}
#line 2144 "parser.c"
        break;
      case 107:
#line 949 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_MOD, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(8,&yymsp[-1].minor);
}
#line 2152 "parser.c"
        break;
      case 108:
#line 953 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_AND, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(10,&yymsp[-1].minor);
}
#line 2160 "parser.c"
        break;
      case 109:
#line 957 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_OR, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(11,&yymsp[-1].minor);
}
#line 2168 "parser.c"
        break;
      case 110:
#line 961 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_EQUALS, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(12,&yymsp[-1].minor);
}
#line 2176 "parser.c"
        break;
      case 111:
#line 965 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_NOTEQUALS, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(13,&yymsp[-1].minor);
}
#line 2184 "parser.c"
        break;
      case 112:
#line 969 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_LESS, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(14,&yymsp[-1].minor);
}
#line 2192 "parser.c"
        break;
      case 113:
#line 973 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_GREATER, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(15,&yymsp[-1].minor);
}
#line 2200 "parser.c"
        break;
      case 114:
#line 977 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_GREATEREQUAL, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(16,&yymsp[-1].minor);
}
#line 2208 "parser.c"
        break;
      case 115:
#line 981 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_LESSEQUAL, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(17,&yymsp[-1].minor);
}
#line 2216 "parser.c"
        break;
      case 116:
#line 985 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_LIKE, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(9,&yymsp[-1].minor);
}
#line 2224 "parser.c"
        break;
      case 117:
#line 989 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_NLIKE, yymsp[-3].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(1,&yymsp[-2].minor);
  yy_destructor(9,&yymsp[-1].minor);
}
#line 2233 "parser.c"
        break;
      case 118:
#line 993 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_IN, yymsp[-4].minor.yy48, yymsp[-1].minor.yy48);
  yy_destructor(2,&yymsp[-3].minor);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
#line 2243 "parser.c"
        break;
      case 119:
#line 997 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_NOTIN, yymsp[-5].minor.yy48, yymsp[-1].minor.yy48);
  yy_destructor(1,&yymsp[-4].minor);
  yy_destructor(2,&yymsp[-3].minor);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
#line 2254 "parser.c"
        break;
      case 121:
#line 1007 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_func_call(yymsp[-3].minor.yy0, yymsp[-1].minor.yy48);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
#line 2263 "parser.c"
        break;
      case 122:
#line 1011 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_func_call(yymsp[-2].minor.yy0, NULL);
  yy_destructor(35,&yymsp[-1].minor);
  yy_destructor(36,&yymsp[0].minor);
}
#line 2272 "parser.c"
        break;
      case 127:
#line 1035 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_ISNULL, yymsp[-2].minor.yy48, NULL);
  yy_destructor(3,&yymsp[-1].minor);
  yy_destructor(49,&yymsp[0].minor);
}
#line 2281 "parser.c"
        break;
      case 128:
#line 1039 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_ISNOTNULL, yymsp[-3].minor.yy48, NULL);
  yy_destructor(3,&yymsp[-2].minor);
  yy_destructor(1,&yymsp[-1].minor);
  yy_destructor(49,&yymsp[0].minor);
}
#line 2291 "parser.c"
        break;
      case 129:
#line 1043 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_NOT, NULL, yymsp[0].minor.yy48);
  yy_destructor(1,&yymsp[-1].minor);
}
#line 2299 "parser.c"
        break;
      case 130:
#line 1047 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_ENCLOSED, yymsp[-1].minor.yy48, NULL);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
#line 2308 "parser.c"
        break;
      case 133:
#line 1059 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_literal_zval(PHQL_T_STRING, yymsp[0].minor.yy0);
}
#line 2315 "parser.c"
        break;
      case 134:
#line 1063 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_literal_zval(PHQL_T_DOUBLE, yymsp[0].minor.yy0);
}
#line 2322 "parser.c"
        break;
      case 135:
#line 1067 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_literal_zval(PHQL_T_NULL, NULL);
  yy_destructor(49,&yymsp[0].minor);
}
#line 2330 "parser.c"
        break;
      case 136:
#line 1071 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_placeholder_zval(PHQL_T_NPLACEHOLDER, yymsp[0].minor.yy0);
}
#line 2337 "parser.c"
        break;
      case 137:
#line 1075 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_placeholder_zval(PHQL_T_SPLACEHOLDER, yymsp[0].minor.yy0);
}
#line 2344 "parser.c"
        break;
      case 138:
#line 1081 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_qualified_name(yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(22,&yymsp[-1].minor);
}
#line 2352 "parser.c"
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
#line 404 "parser.lemon"

	if (status->scanner_state->start) {
		{

			char *token_name;
			const phql_token_names *tokens = phql_tokens;
			int active_token = status->scanner_state->active_token;
			int near_length = strlen(status->scanner_state->start);

			if (active_token) {

				do {
					if (tokens->code == active_token) {
						token_name = tokens->name;
						break;
					}
					++tokens;
				} while (tokens[0].code != 0);

			} else {
				token_name = estrndup("UNKNOWN", strlen("UNKNOWN"));
			}

			status->syntax_error_len = 64 + strlen(token_name) + near_length;
			status->syntax_error = emalloc(sizeof(char)*status->syntax_error_len);
			if (near_length > 0) {
				sprintf(status->syntax_error, "Syntax error, unexpected token %s, near to %s", token_name, status->scanner_state->start);
			} else {
				sprintf(status->syntax_error, "Syntax error, unexpected token %s, at the end of query", token_name);
			}

			if (!active_token) {
				efree(token_name);
			}
		}
	} else {
		status->syntax_error_len = strlen("Syntax error, unexpected EOF");
		status->syntax_error = estrndup("Syntax error, unexpected EOF", status->syntax_error_len);
	}

	status->status = PHQL_PARSING_FAILED;

#line 2437 "parser.c"
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
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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
  { PHQL_T_INTEGER,       "INTEGER" },
  { PHQL_T_DOUBLE,        "DOUBLE" },
  { PHQL_T_STRING,        "STRING" },
  { PHQL_T_IDENTIFIER,    "IDENTIFIER" },
  { PHQL_T_MINUS,         "MINUS"},
  { PHQL_T_ADD,           "+" },
  { PHQL_T_SUB,           "-" },
  { PHQL_T_MUL,           "*" },
  { PHQL_T_DIV,           "/" },
  { PHQL_T_MOD,           "%%" },
  { PHQL_T_AND,           "AND" },
  { PHQL_T_OR,            "OR" },
  { PHQL_T_LIKE,          "LIKE" },
  { PHQL_T_DOT,           "DOT" },
  { PHQL_T_COMMA,         "COMMA" },
  { PHQL_T_EQUALS,        "EQUALS" },
  { PHQL_T_NOTEQUALS,     "NOT EQUALS" },
  { PHQL_T_NOT,           "NOT" },
  { PHQL_T_LESS,          "<" },
  { PHQL_T_LESSEQUAL,     "<=" },
  { PHQL_T_GREATER,       ">" },
  { PHQL_T_GREATEREQUAL,  ">=" },
  { PHQL_T_BRACKET_OPEN,  "(" },
  { PHQL_T_BRACKET_CLOSE, ")" },
  { PHQL_T_NPLACEHOLDER,  "NUMERIC PLACEHOLDER" },
  { PHQL_T_SPLACEHOLDER,  "STRING PLACEHOLDER" },
  { PHQL_T_UPDATE,        "UPDATE" },
  { PHQL_T_SET,           "SET" },
  { PHQL_T_WHERE,         "WHERE" },
  { PHQL_T_DELETE,        "DELETE" },
  { PHQL_T_FROM,          "FROM" },
  { PHQL_T_AS,            "AS" },
  { PHQL_T_INSERT,        "INSERT" },
  { PHQL_T_INTO,          "INTO" },
  { PHQL_T_VALUES,        "VALUES" },
  { PHQL_T_SELECT,        "SELECT" },
  { PHQL_T_ORDER,         "ORDER" },
  { PHQL_T_BY,            "BY" },
  { PHQL_T_LIMIT,         "LIMIT" },
  { PHQL_T_GROUP,         "GROUP" },
  { PHQL_T_HAVING,        "HAVING" },
  { PHQL_T_IN,            "IN" },
  { PHQL_T_ON,            "ON" },
  { PHQL_T_INNER,         "INNER" },
  { PHQL_T_JOIN,          "JOIN" },
  { PHQL_T_LEFT,          "LEFT" },
  { PHQL_T_RIGHT,         "RIGHT" },
  { PHQL_T_IS,            "IS" },
  { PHQL_T_NULL,          "NULL" },
  { PHQL_T_NOTIN,         "NOT IN" },
  { PHQL_T_CROSS,         "CROSS" },
  { PHQL_T_OUTER,         "OUTER" },
  { PHQL_T_FULL,          "FULL" },
  { PHQL_T_ASC,           "ASC" },
  { PHQL_T_DESC,          "DESC" },
  {  0, NULL }
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
	pToken->token = estrndup(token->value, token->len);
	pToken->token_len = token->len;
	phql_(phql_parser, parsercode, pToken, parser_status);
	efree(token->value);
}

int phql_parse_phql(zval *result, zval *phql TSRMLS_DC){

	zval *error_msg;

	ZVAL_NULL(result);

	if(phql_internal_parse_phql(&result, Z_STRVAL_P(phql), &error_msg TSRMLS_CC) == FAILURE){
		phalcon_throw_exception_string(phalcon_mvc_model_exception_ce, Z_STRVAL_P(error_msg), Z_STRLEN_P(error_msg) TSRMLS_CC);
		return FAILURE;
	}

	return SUCCESS;
}

int phql_internal_parse_phql(zval **result, char *phql, zval **error_msg TSRMLS_DC) {

	char *error;
	phql_scanner_state *state;
	phql_scanner_token *token;
	int scanner_status, status = SUCCESS;
	phql_parser_status *parser_status = NULL;

	void* phql_parser = phql_Alloc(phql_wrapper_alloc);

	parser_status = emalloc(sizeof(phql_parser_status));
	state = emalloc(sizeof(phql_scanner_state));
	token = emalloc(sizeof(phql_scanner_token));

	if (!phql) {
		ZVAL_STRING(*error_msg, "PHQL statement cannot be NULL", 1);
		return FAILURE;
	}

	parser_status->status = PHQL_PARSING_OK;
	parser_status->scanner_state = state;

	state->active_token = 0;
	state->start = phql;

	state->end = state->start;

	while(0 <= (scanner_status = phql_get_token(state, token))) {

		state->active_token = token->opcode;

		switch(token->opcode){

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
			case PHQL_T_NOT:
				phql_(phql_parser, PHQL_NOT, NULL, parser_status);
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
				phql_parse_with_token(phql_parser, PHQL_T_INTEGER, PHQL_INTEGER, token, parser_status);
				break;
			case PHQL_T_DOUBLE:
				phql_parse_with_token(phql_parser, PHQL_T_DOUBLE, PHQL_DOUBLE, token, parser_status);
				break;
			case PHQL_T_STRING:
				phql_parse_with_token(phql_parser, PHQL_T_STRING, PHQL_STRING, token, parser_status);
				break;
			case PHQL_T_IDENTIFIER:
				phql_parse_with_token(phql_parser, PHQL_T_IDENTIFIER, PHQL_IDENTIFIER, token, parser_status);
				break;
			case PHQL_T_NPLACEHOLDER:
				phql_parse_with_token(phql_parser, PHQL_T_NPLACEHOLDER, PHQL_NPLACEHOLDER, token, parser_status);
				break;
			case PHQL_T_SPLACEHOLDER:
				phql_parse_with_token(phql_parser, PHQL_T_SPLACEHOLDER, PHQL_SPLACEHOLDER, token, parser_status);
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
			default:
				status = FAILURE;
				error = emalloc(sizeof(char)*32);
				sprintf(error, "scanner: unknown opcode %c", token->opcode);
				PHALCON_ALLOC_ZVAL_MM(*error_msg);
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

	state->active_token = 0;
	state->start = NULL;

	if (status != FAILURE) {
		switch (scanner_status) {
			case PHQL_SCANNER_RETCODE_ERR:
			case PHQL_SCANNER_RETCODE_IMPOSSIBLE:
				PHALCON_ALLOC_ZVAL_MM(*error_msg);
				if (state->start) {
					error = emalloc(sizeof(char)*(48+strlen(state->start)));
					sprintf(error, "Parsing error near to %s (%d)", state->start, status);
					ZVAL_STRING(*error_msg, error, 1);
					efree(error);
				} else {
					ZVAL_STRING(*error_msg, "Parsing error near to EOF", 1);
				}
				status = FAILURE;
				break;
			default:
				phql_(phql_parser, 0, NULL, parser_status);
		}
	}

	if (parser_status->status != PHQL_PARSING_OK) {
		status = FAILURE;
		PHALCON_ALLOC_ZVAL_MM(*error_msg);
		ZVAL_STRING(*error_msg, parser_status->syntax_error, 1);
		efree(parser_status->syntax_error);
	}

	phql_Free(phql_parser, phql_wrapper_free);

	if (status != FAILURE) {
		if (parser_status->status == PHQL_PARSING_OK) {
			ZVAL_ZVAL(*result, parser_status->ret, 0, 0);
			ZVAL_NULL(parser_status->ret);
			zval_ptr_dtor(&parser_status->ret);
		}
	}

	efree(parser_status);
	efree(state);
	efree(token);

	return status;
}