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

static zval *phql_ret_select_limit_clause(phql_parser_token *L, phql_parser_token *O)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	add_assoc_stringl(ret, "number", L->token, L->token_len, 1);
	efree(L->token);
	efree(L);

	if (O != NULL) {
		add_assoc_stringl(ret, "offset", O->token, O->token_len, 1);
		efree(O->token);
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


#line 396 "parser.c"
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
#define YYNOCODE 98
#define YYACTIONTYPE unsigned short int
#define phql_TOKENTYPE phql_parser_token*
typedef union {
  phql_TOKENTYPE yy0;
  zval* yy66;
  int yy195;
} YYMINORTYPE;
#define YYSTACKDEPTH 100
#define phql_ARG_SDECL phql_parser_status *status;
#define phql_ARG_PDECL ,phql_parser_status *status
#define phql_ARG_FETCH phql_parser_status *status = yypParser->status
#define phql_ARG_STORE yypParser->status = status
#define YYNSTATE 244
#define YYNRULE 143
#define YYERRORSYMBOL 55
#define YYERRSYMDT yy195
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
 /*     0 */    55,   57,   59,   61,   63,   65,   51,   53,   67,   47,
 /*    10 */    45,   49,   43,   40,   75,   72,   69,    7,  117,  119,
 /*    20 */   196,  127,  194,    9,   55,   57,   59,   61,   63,   65,
 /*    30 */    51,   53,   67,   47,   45,   49,   43,   40,   75,   72,
 /*    40 */    69,   55,   57,   59,   61,   63,   65,   51,   53,   67,
 /*    50 */    47,   45,   49,   43,   40,   75,   72,   69,   89,   94,
 /*    60 */    70,   41,    8,   16,   90,  108,  251,  103,   83,   51,
 /*    70 */    53,   67,   47,   45,   49,   43,   40,   75,   72,   69,
 /*    80 */   114,   89,   92,   87,   41,  131,   31,   90,  197,  193,
 /*    90 */   313,   83,   96,  249,   95,  111,  116,   99,   97,   98,
 /*   100 */   100,  101,  207,  189,   29,   92,   41,   95,  203,   90,
 /*   110 */    30,  208,   82,  190,   10,   96,   23,   34,   26,  244,
 /*   120 */    99,   97,   98,  100,  101,   82,  245,   92,   41,   31,
 /*   130 */   128,   90,  133,  128,   21,   83,  186,   96,  223,  109,
 /*   140 */   181,   10,   99,   97,   98,  100,  101,  246,  141,   92,
 /*   150 */   145,  150,  153,  115,  163,  173,   29,   74,   18,   96,
 /*   160 */   250,   20,   95,   77,   99,   97,   98,  100,  101,   25,
 /*   170 */    26,  247,  388,    1,    2,    3,    4,    5,    6,   79,
 /*   180 */    82,   88,   67,   47,   45,   49,   43,   40,   75,   72,
 /*   190 */    69,   43,   40,   75,   72,   69,   76,   74,  154,  220,
 /*   200 */    74,   21,   95,  158,  237,   95,  109,  252,   10,  267,
 /*   210 */    47,   45,   49,   43,   40,   75,   72,   69,  114,   85,
 /*   220 */    82,   88,  105,   82,   88,  179,  135,  136,  137,  141,
 /*   230 */   130,  145,  150,  153,  113,  163,  173,  207,  256,  248,
 /*   240 */    74,  253,   95,  214,  198,   95,  208,  258,   21,  226,
 /*   250 */    21,  241,  188,  193,   38,   10,   38,   10,   95,  345,
 /*   260 */    82,  134,   11,   82,  102,  185,  136,  137,  207,   13,
 /*   270 */   235,   27,   28,   95,  254,   95,   82,  206,   35,   12,
 /*   280 */    17,   37,   21,   39,   81,  234,   10,  107,   95,   10,
 /*   290 */    42,   82,   95,   82,   44,   95,   75,   72,   69,   95,
 /*   300 */    80,  346,   46,  232,   48,   15,   82,   95,   14,   95,
 /*   310 */    82,  229,  236,   82,   50,   52,   54,   82,   56,   95,
 /*   320 */    95,   95,   10,   95,   58,   82,   60,   82,   62,   95,
 /*   330 */    64,   95,  322,   95,  140,   95,  138,   82,   82,   82,
 /*   340 */    66,   82,  269,   68,  184,   95,  182,   82,   95,   82,
 /*   350 */    71,   82,   91,   82,   93,   95,   19,   95,  120,   95,
 /*   360 */   122,  126,  129,   82,  144,  149,   82,   95,   22,   95,
 /*   370 */    95,  157,  128,   82,  261,   82,   95,   82,  262,  162,
 /*   380 */   223,  167,   32,   21,   95,   82,   95,   82,   82,  263,
 /*   390 */    10,  172,  178,   81,   82,   84,   95,   95,  123,  191,
 /*   400 */    81,  125,   82,  164,   82,  132,  187,  205,  168,   86,
 /*   410 */   192,  221,   84,  180,   82,   82,  106,  181,  201,  209,
 /*   420 */    33,  314,   10,  204,  210,  216,   10,  219,  205,  227,
 /*   430 */   232,  238,  225,  181,  323,  347,  243,   10,  266,  231,
 /*   440 */   181,  211,  260,   24,  215,  255,   32,   33,   36,  259,
 /*   450 */    69,   73,  240,   78,  104,  257,  110,  112,  118,  264,
 /*   460 */   121,  265,  124,  271,  270,  268,  272,   31,  139,  223,
 /*   470 */   174,  142,  199,  143,  146,  147,  148,  151,  152,  155,
 /*   480 */   305,  156,  223,  160,  159,  306,  165,  161,  170,  176,
 /*   490 */   200,  212,  166,  169,  218,  171,  175,  183,  195,  177,
 /*   500 */   217,  222,  316,  202,  348,  315,  213,  230,  233,  239,
 /*   510 */   325,  324,  242,  242,  242,  242,  228,  242,  242,  242,
 /*   520 */   224,
};
static YYCODETYPE yy_lookahead[] = {
 /*     0 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    10 */    11,   12,   13,   14,   15,   16,   17,   63,   64,   65,
 /*    20 */    21,   67,   23,   67,    1,    2,    3,    4,    5,    6,
 /*    30 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*    40 */    17,    1,    2,    3,    4,    5,    6,    7,    8,    9,
 /*    50 */    10,   11,   12,   13,   14,   15,   16,   17,   11,   36,
 /*    60 */     9,   14,   64,   65,   17,   67,    0,   16,   21,    7,
 /*    70 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*    80 */    77,   11,   35,   36,   14,   68,   21,   17,   71,   72,
 /*    90 */     0,   21,   45,    0,   77,   92,   93,   50,   51,   52,
 /*   100 */    53,   54,   72,   11,   77,   35,   14,   77,   78,   17,
 /*   110 */    45,   81,   95,   21,   48,   45,   89,   90,   91,    0,
 /*   120 */    50,   51,   52,   53,   54,   95,    0,   35,   14,   21,
 /*   130 */    40,   17,   69,   40,   41,   21,   73,   45,   48,   46,
 /*   140 */    77,   48,   50,   51,   52,   53,   54,    0,   24,   35,
 /*   150 */    26,   27,   28,   45,   30,   31,   77,   72,   64,   45,
 /*   160 */     0,   67,   77,   17,   50,   51,   52,   53,   54,   90,
 /*   170 */    91,    0,   56,   57,   58,   59,   60,   61,   62,   94,
 /*   180 */    95,   96,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   190 */    17,   13,   14,   15,   16,   17,   50,   72,   24,   83,
 /*   200 */    72,   41,   77,   29,   88,   77,   46,    0,   48,    0,
 /*   210 */    10,   11,   12,   13,   14,   15,   16,   17,   77,   94,
 /*   220 */    95,   96,   94,   95,   96,   20,   74,   75,   76,   24,
 /*   230 */    18,   26,   27,   28,   93,   30,   31,   72,    0,    0,
 /*   240 */    72,    0,   77,   78,   32,   77,   81,    0,   41,   37,
 /*   250 */    41,   39,   71,   72,   47,   48,   47,   48,   77,    0,
 /*   260 */    95,   70,   45,   95,   96,   74,   75,   76,   72,   45,
 /*   270 */    72,   43,   44,   77,    0,   77,   95,   81,   64,   20,
 /*   280 */    66,   67,   41,   72,   20,   87,   48,   72,   77,   48,
 /*   290 */    72,   95,   77,   95,   72,   77,   15,   16,   17,   77,
 /*   300 */    36,    0,   72,   77,   72,   45,   95,   77,   49,   77,
 /*   310 */    95,   85,   86,   95,   72,   72,   72,   95,   72,   77,
 /*   320 */    77,   77,   48,   77,   72,   95,   72,   95,   72,   77,
 /*   330 */    72,   77,    0,   77,   21,   77,   23,   95,   95,   95,
 /*   340 */    72,   95,    0,   72,   21,   77,   23,   95,   77,   95,
 /*   350 */    72,   95,   72,   95,   72,   77,   67,   77,   64,   77,
 /*   360 */    66,   67,   72,   95,   72,   72,   95,   77,   42,   77,
 /*   370 */    77,   72,   40,   95,    0,   95,   77,   95,    0,   72,
 /*   380 */    48,   72,   22,   41,   77,   95,   77,   95,   95,    0,
 /*   390 */    48,   72,   72,   20,   95,   35,   77,   77,   64,   22,
 /*   400 */    20,   67,   95,   24,   95,   19,   20,   20,   29,   36,
 /*   410 */    11,   63,   35,   73,   95,   95,   36,   77,   34,   35,
 /*   420 */    21,    0,   48,   36,   79,   20,   48,   82,   20,   73,
 /*   430 */    77,   63,   84,   77,    0,    0,   73,   48,    0,   86,
 /*   440 */    77,   36,    0,   20,   36,    0,   22,   21,   67,    0,
 /*   450 */    17,   35,   84,   50,   35,    0,   42,   20,   67,    0,
 /*   460 */    67,    0,   67,    0,    0,    0,    0,   21,   21,   48,
 /*   470 */    29,   77,   33,   25,   24,   77,   25,   24,   77,   77,
 /*   480 */     0,   25,   48,   77,   24,    0,   77,   25,   77,   77,
 /*   490 */    77,   34,   25,   24,   21,   25,   24,   21,   21,   25,
 /*   500 */    82,   84,    0,   35,    0,    0,   35,   20,    1,   84,
 /*   510 */     0,    0,   19,   97,   97,   97,   38,   97,   97,   97,
 /*   520 */    45,
};
#define YY_SHIFT_USE_DFLT (-2)
static short yy_shift_ofst[] = {
 /*     0 */   212,  119,  126,  147,  171,  239,   93,  160,   66,  247,
 /*    10 */   217,  259,  224,  301,  260,  435,  207,  241,  238,  438,
 /*    20 */   442,  326,   65,  423,   65,   -2,  228,   -2,   -2,   -2,
 /*    30 */    -2,  424,  426,   -2,   -2,  274,  445,  449,  114,   40,
 /*    40 */   114,  114,  281,  114,  281,  114,  178,  114,  178,  114,
 /*    50 */   178,  114,  173,  114,  173,  114,   62,  114,   62,  114,
 /*    60 */    62,  114,   62,  114,   62,  114,   62,  114,  200,   51,
 /*    70 */   114,  433,  416,   70,   40,  146,   -2,  403,   -2,  264,
 /*    80 */    -2,   70,   -2,  360,   47,  373,   -2,   -2,   -2,   -2,
 /*    90 */   114,  433,  114,   23,   -2,   -2,   -2,   -2,   -2,   -2,
 /*   100 */    -2,   -2,   -2,  419,   70,  380,   -2,  281,  455,  414,
 /*   110 */   108,  437,  108,   -2,   -2,   -2,   -2,  374,  459,  209,
 /*   120 */   378,  461,  342,  389,  463,  464,  465,  466,  114,   40,
 /*   130 */    92,  386,  446,  205,  124,   -2,   -2,  313,  447,   -2,
 /*   140 */    -2,  446,  448,  114,   40,  450,  446,  451,  114,   40,
 /*   150 */   453,  446,   -2,  174,  446,  456,  114,   40,  460,  446,
 /*   160 */   462,  114,   40,  379,  446,  467,  114,   40,  469,  446,
 /*   170 */   470,  114,   40,  441,  472,  446,  474,  114,   40,  446,
 /*   180 */    -2,  323,  476,   -2,   -2,   -2,   -2,   92,   -2,   -2,
 /*   190 */   377,  399,   -2,   -1,  477,   -2,   -2,   -2,  439,  446,
 /*   200 */   384,  468,  114,  387,  480,  114,   -2,   40,   -2,  473,
 /*   210 */   405,  457,  471,  114,  408,  485,  473,   -2,   -2,   -2,
 /*   220 */    90,  421,  502,  475,  504,  505,  446,  478,  446,  487,
 /*   230 */   446,   -2,  507,  114,   -2,   40,   -2,  332,  434,  510,
 /*   240 */   511,  493,  446,   -2,
};
#define YY_REDUCE_USE_DFLT (-47)
static short yy_reduce_ofst[] = {
 /*     0 */   116,  -47,  -47,  -47,  -47,  -47,  -46,   -2,  -44,  -47,
 /*    10 */   -47,  -47,  -47,  -47,  -47,  -47,  214,   94,  289,  -47,
 /*    20 */   -47,  -47,   27,  -47,   79,  -47,  -47,  -47,  -47,  -47,
 /*    30 */   -47,  -47,  -47,  -47,  -47,  381,  -47,  -47,  211,  -47,
 /*    40 */   215,  218,  -47,  222,  -47,  230,  -47,  232,  -47,  242,
 /*    50 */   -47,  243,  -47,  244,  -47,  246,  -47,  252,  -47,  254,
 /*    60 */   -47,  256,  -47,  258,  -47,  268,  -47,  271,  -47,  -47,
 /*    70 */   278,  -47,  -47,   85,  -47,  -47,  -47,  -47,  -47,  -47,
 /*    80 */   -47,  168,  -47,  -47,  125,  -47,  -47,  -47,  -47,  -47,
 /*    90 */   280,  -47,  282,  -47,  -47,  -47,  -47,  -47,  -47,  -47,
 /*   100 */   -47,  -47,  -47,  -47,  128,  -47,  -47,  -47,  -47,  -47,
 /*   110 */     3,  -47,  141,  -47,  -47,  -47,  -47,  391,  -47,  294,
 /*   120 */   393,  -47,  334,  395,  -47,  -47,  -47,  -47,  290,  -47,
 /*   130 */    17,  -47,   63,  191,  152,  -47,  -47,  -47,  -47,  -47,
 /*   140 */   -47,  394,  -47,  292,  -47,  -47,  398,  -47,  293,  -47,
 /*   150 */   -47,  401,  -47,  -47,  402,  -47,  299,  -47,  -47,  406,
 /*   160 */   -47,  307,  -47,  -47,  409,  -47,  309,  -47,  -47,  411,
 /*   170 */   -47,  319,  -47,  -47,  -47,  412,  -47,  320,  -47,  340,
 /*   180 */   -47,  -47,  -47,  -47,  -47,  -47,  -47,  181,  -47,  -47,
 /*   190 */   -47,  -47,  -47,  -47,  -47,  -47,  -47,  -47,  -47,  413,
 /*   200 */   -47,  -47,   30,  -47,  -47,  196,  -47,  -47,  -47,  345,
 /*   210 */   -47,  -47,  -47,  165,  -47,  -47,  418,  -47,  -47,  -47,
 /*   220 */   348,  417,  -47,  -47,  -47,  -47,  356,  -47,  226,  -47,
 /*   230 */   353,  -47,  -47,  198,  -47,  -47,  -47,  368,  425,  -47,
 /*   240 */   -47,  -47,  363,  -47,
};
static YYACTIONTYPE yy_default[] = {
 /*     0 */   387,  387,  387,  387,  387,  387,  387,  387,  387,  387,
 /*    10 */   387,  387,  387,  387,  387,  387,  387,  387,  387,  387,
 /*    20 */   387,  387,  387,  331,  387,  332,  334,  335,  336,  337,
 /*    30 */   338,  386,  387,  385,  333,  387,  387,  387,  387,  344,
 /*    40 */   387,  387,  349,  387,  351,  387,  352,  387,  353,  387,
 /*    50 */   354,  387,  355,  387,  356,  387,  357,  387,  358,  387,
 /*    60 */   359,  387,  360,  387,  361,  387,  362,  387,  363,  387,
 /*    70 */   387,  364,  387,  387,  373,  387,  374,  387,  375,  387,
 /*    80 */   365,  387,  367,  386,  387,  387,  368,  369,  371,  372,
 /*    90 */   387,  376,  387,  387,  377,  378,  379,  380,  381,  382,
 /*   100 */   383,  384,  370,  387,  387,  387,  366,  350,  387,  387,
 /*   110 */   387,  339,  387,  340,  342,  343,  341,  387,  387,  387,
 /*   120 */   387,  387,  387,  387,  387,  387,  387,  387,  387,  330,
 /*   130 */   387,  387,  387,  273,  274,  284,  286,  287,  387,  288,
 /*   140 */   289,  387,  290,  387,  291,  387,  387,  292,  387,  293,
 /*   150 */   387,  387,  294,  387,  387,  295,  387,  297,  387,  387,
 /*   160 */   296,  387,  298,  387,  387,  299,  387,  301,  387,  387,
 /*   170 */   300,  387,  302,  387,  387,  387,  303,  387,  304,  387,
 /*   180 */   282,  329,  387,  327,  328,  285,  283,  387,  275,  277,
 /*   190 */   386,  387,  278,  281,  387,  279,  280,  276,  387,  387,
 /*   200 */   387,  387,  387,  387,  387,  387,  307,  309,  308,  387,
 /*   210 */   387,  387,  387,  387,  387,  387,  387,  310,  312,  311,
 /*   220 */   387,  387,  387,  387,  387,  387,  387,  387,  387,  317,
 /*   230 */   387,  318,  387,  387,  320,  321,  319,  387,  387,  387,
 /*   240 */   387,  387,  387,  326,
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
  "$",             "EQUALS",        "NOTEQUALS",     "LESS",        
  "GREATER",       "GREATEREQUAL",  "LESSEQUAL",     "AND",         
  "OR",            "LIKE",          "DIVIDE",        "TIMES",       
  "MOD",           "PLUS",          "MINUS",         "IS",          
  "IN",            "NOT",           "SELECT",        "FROM",        
  "COMMA",         "IDENTIFIER",    "DOT",           "AS",          
  "JOIN",          "ON",            "INNER",         "CROSS",       
  "LEFT",          "OUTER",         "RIGHT",         "FULL",        
  "INSERT",        "INTO",          "VALUES",        "BRACKET_OPEN",
  "BRACKET_CLOSE",  "UPDATE",        "SET",           "DELETE",      
  "WHERE",         "ORDER",         "BY",            "ASC",         
  "DESC",          "INTEGER",       "GROUP",         "HAVING",      
  "LIMIT",         "OFFSET",        "NULL",          "STRING",      
  "DOUBLE",        "NPLACEHOLDER",  "SPLACEHOLDER",  "error",       
  "program",       "query_language",  "select_statement",  "insert_statement",
  "update_statement",  "delete_statement",  "select_clause",  "where_clause",
  "order_clause",  "group_clause",  "having_clause",  "select_limit_clause",
  "column_list",   "associated_name_list",  "join_list",     "column_item", 
  "expr",          "associated_name",  "join_item",     "join_associated_name",
  "join_clause",   "qualified_name",  "values_list",   "field_list",  
  "value_list",    "value_item",    "field_item",    "update_clause",
  "limit_clause",  "update_item_list",  "update_item",   "new_value",   
  "delete_clause",  "order_list",    "order_item",    "order_qualified_or_int",
  "group_list",    "group_item",    "argument_list",  "function_call",
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
 /* 101 */ "select_limit_clause ::= LIMIT INTEGER",
 /* 102 */ "select_limit_clause ::= LIMIT INTEGER COMMA INTEGER",
 /* 103 */ "select_limit_clause ::= LIMIT INTEGER OFFSET INTEGER",
 /* 104 */ "limit_clause ::= LIMIT INTEGER",
 /* 105 */ "expr ::= MINUS expr",
 /* 106 */ "expr ::= expr MINUS expr",
 /* 107 */ "expr ::= expr PLUS expr",
 /* 108 */ "expr ::= expr TIMES expr",
 /* 109 */ "expr ::= expr DIVIDE expr",
 /* 110 */ "expr ::= expr MOD expr",
 /* 111 */ "expr ::= expr AND expr",
 /* 112 */ "expr ::= expr OR expr",
 /* 113 */ "expr ::= expr EQUALS expr",
 /* 114 */ "expr ::= expr NOTEQUALS expr",
 /* 115 */ "expr ::= expr LESS expr",
 /* 116 */ "expr ::= expr GREATER expr",
 /* 117 */ "expr ::= expr GREATEREQUAL expr",
 /* 118 */ "expr ::= expr LESSEQUAL expr",
 /* 119 */ "expr ::= expr LIKE expr",
 /* 120 */ "expr ::= expr NOT LIKE expr",
 /* 121 */ "expr ::= expr IN BRACKET_OPEN argument_list BRACKET_CLOSE",
 /* 122 */ "expr ::= expr NOT IN BRACKET_OPEN argument_list BRACKET_CLOSE",
 /* 123 */ "expr ::= function_call",
 /* 124 */ "function_call ::= IDENTIFIER BRACKET_OPEN argument_list BRACKET_CLOSE",
 /* 125 */ "function_call ::= IDENTIFIER BRACKET_OPEN BRACKET_CLOSE",
 /* 126 */ "argument_list ::= argument_list COMMA argument_item",
 /* 127 */ "argument_list ::= argument_item",
 /* 128 */ "argument_item ::= TIMES",
 /* 129 */ "argument_item ::= expr",
 /* 130 */ "expr ::= expr IS NULL",
 /* 131 */ "expr ::= expr IS NOT NULL",
 /* 132 */ "expr ::= NOT expr",
 /* 133 */ "expr ::= BRACKET_OPEN expr BRACKET_CLOSE",
 /* 134 */ "expr ::= qualified_name",
 /* 135 */ "expr ::= INTEGER",
 /* 136 */ "expr ::= STRING",
 /* 137 */ "expr ::= DOUBLE",
 /* 138 */ "expr ::= NULL",
 /* 139 */ "expr ::= NPLACEHOLDER",
 /* 140 */ "expr ::= SPLACEHOLDER",
 /* 141 */ "qualified_name ::= IDENTIFIER DOT IDENTIFIER",
 /* 142 */ "qualified_name ::= IDENTIFIER",
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
#line 473 "parser.lemon"
{
	if ((yypminor->yy0)) {
		efree((yypminor->yy0)->token);
		efree((yypminor->yy0));
	}
}
#line 1084 "parser.c"
      break;
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
    case 79:
    case 80:
    case 82:
    case 83:
    case 84:
    case 85:
    case 86:
    case 88:
    case 89:
    case 90:
    case 92:
    case 93:
    case 94:
    case 95:
    case 96:
#line 484 "parser.lemon"
{ zval_ptr_dtor(&(yypminor->yy66)); }
#line 1124 "parser.c"
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
  { 56, 1 },
  { 57, 1 },
  { 57, 1 },
  { 57, 1 },
  { 57, 1 },
  { 58, 1 },
  { 58, 2 },
  { 58, 3 },
  { 58, 3 },
  { 58, 4 },
  { 58, 4 },
  { 58, 5 },
  { 58, 5 },
  { 58, 3 },
  { 58, 4 },
  { 58, 4 },
  { 58, 5 },
  { 58, 2 },
  { 58, 3 },
  { 58, 4 },
  { 58, 3 },
  { 58, 4 },
  { 58, 6 },
  { 58, 2 },
  { 58, 3 },
  { 58, 3 },
  { 58, 4 },
  { 58, 5 },
  { 58, 2 },
  { 62, 4 },
  { 62, 5 },
  { 68, 3 },
  { 68, 1 },
  { 71, 1 },
  { 71, 3 },
  { 71, 3 },
  { 71, 2 },
  { 71, 1 },
  { 69, 3 },
  { 69, 1 },
  { 70, 2 },
  { 70, 1 },
  { 74, 1 },
  { 75, 1 },
  { 75, 3 },
  { 75, 2 },
  { 76, 2 },
  { 76, 4 },
  { 76, 3 },
  { 76, 5 },
  { 76, 3 },
  { 76, 3 },
  { 76, 4 },
  { 76, 5 },
  { 76, 6 },
  { 76, 3 },
  { 76, 4 },
  { 76, 5 },
  { 76, 6 },
  { 76, 4 },
  { 76, 6 },
  { 59, 7 },
  { 59, 10 },
  { 78, 3 },
  { 78, 1 },
  { 81, 1 },
  { 79, 3 },
  { 79, 1 },
  { 82, 1 },
  { 60, 1 },
  { 60, 2 },
  { 60, 2 },
  { 60, 3 },
  { 83, 4 },
  { 85, 3 },
  { 85, 1 },
  { 86, 3 },
  { 87, 1 },
  { 61, 1 },
  { 61, 2 },
  { 61, 2 },
  { 61, 3 },
  { 88, 3 },
  { 73, 3 },
  { 73, 2 },
  { 73, 1 },
  { 63, 2 },
  { 64, 3 },
  { 89, 3 },
  { 89, 1 },
  { 90, 1 },
  { 90, 2 },
  { 90, 2 },
  { 91, 1 },
  { 91, 1 },
  { 65, 3 },
  { 92, 3 },
  { 92, 1 },
  { 93, 1 },
  { 93, 1 },
  { 66, 2 },
  { 67, 2 },
  { 67, 4 },
  { 67, 4 },
  { 84, 2 },
  { 72, 2 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 4 },
  { 72, 5 },
  { 72, 6 },
  { 72, 1 },
  { 95, 4 },
  { 95, 3 },
  { 94, 3 },
  { 94, 1 },
  { 96, 1 },
  { 96, 1 },
  { 72, 3 },
  { 72, 4 },
  { 72, 2 },
  { 72, 3 },
  { 72, 1 },
  { 72, 1 },
  { 72, 1 },
  { 72, 1 },
  { 72, 1 },
  { 72, 1 },
  { 72, 1 },
  { 77, 3 },
  { 77, 1 },
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
#line 480 "parser.lemon"
{
	status->ret = yymsp[0].minor.yy66;
}
#line 1484 "parser.c"
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
      case 123:
      case 127:
      case 129:
      case 134:
#line 486 "parser.lemon"
{
	yygotominor.yy66 = yymsp[0].minor.yy66;
}
#line 1511 "parser.c"
        break;
      case 5:
#line 504 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_select_statement(yymsp[0].minor.yy66, NULL, NULL, NULL, NULL, NULL);
}
#line 1518 "parser.c"
        break;
      case 6:
#line 508 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_select_statement(yymsp[-1].minor.yy66, yymsp[0].minor.yy66, NULL, NULL, NULL, NULL);
}
#line 1525 "parser.c"
        break;
      case 7:
#line 512 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_select_statement(yymsp[-2].minor.yy66, yymsp[-1].minor.yy66, yymsp[0].minor.yy66, NULL, NULL, NULL);
}
#line 1532 "parser.c"
        break;
      case 8:
#line 516 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_select_statement(yymsp[-2].minor.yy66, yymsp[-1].minor.yy66, NULL, yymsp[0].minor.yy66, NULL, NULL);
}
#line 1539 "parser.c"
        break;
      case 9:
#line 520 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_select_statement(yymsp[-3].minor.yy66, yymsp[-2].minor.yy66, NULL, yymsp[-1].minor.yy66, yymsp[0].minor.yy66, NULL);
}
#line 1546 "parser.c"
        break;
      case 10:
#line 524 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_select_statement(yymsp[-3].minor.yy66, yymsp[-2].minor.yy66, yymsp[0].minor.yy66, yymsp[-1].minor.yy66, NULL, NULL);
}
#line 1553 "parser.c"
        break;
      case 11:
#line 528 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_select_statement(yymsp[-4].minor.yy66, yymsp[-3].minor.yy66, yymsp[-1].minor.yy66, yymsp[-2].minor.yy66, NULL, yymsp[0].minor.yy66);
}
#line 1560 "parser.c"
        break;
      case 12:
#line 532 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_select_statement(yymsp[-4].minor.yy66, yymsp[-3].minor.yy66, yymsp[0].minor.yy66, yymsp[-2].minor.yy66, yymsp[-1].minor.yy66, NULL);
}
#line 1567 "parser.c"
        break;
      case 13:
#line 536 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_select_statement(yymsp[-2].minor.yy66, yymsp[-1].minor.yy66, NULL, NULL, NULL, yymsp[0].minor.yy66);
}
#line 1574 "parser.c"
        break;
      case 14:
#line 540 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_select_statement(yymsp[-3].minor.yy66, yymsp[-2].minor.yy66, yymsp[-1].minor.yy66, NULL, NULL, yymsp[0].minor.yy66);
}
#line 1581 "parser.c"
        break;
      case 15:
#line 544 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_select_statement(yymsp[-3].minor.yy66, yymsp[-2].minor.yy66, NULL, yymsp[-1].minor.yy66, NULL, yymsp[0].minor.yy66);
}
#line 1588 "parser.c"
        break;
      case 16:
#line 548 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_select_statement(yymsp[-4].minor.yy66, yymsp[-3].minor.yy66, NULL, yymsp[-2].minor.yy66, yymsp[-1].minor.yy66, yymsp[0].minor.yy66);
}
#line 1595 "parser.c"
        break;
      case 17:
#line 552 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_select_statement(yymsp[-1].minor.yy66, NULL, yymsp[0].minor.yy66, NULL, NULL, NULL);
}
#line 1602 "parser.c"
        break;
      case 18:
#line 556 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_select_statement(yymsp[-2].minor.yy66, NULL, yymsp[0].minor.yy66, yymsp[-1].minor.yy66, NULL, NULL);
}
#line 1609 "parser.c"
        break;
      case 19:
#line 560 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_select_statement(yymsp[-3].minor.yy66, NULL, yymsp[0].minor.yy66, yymsp[-2].minor.yy66, yymsp[-1].minor.yy66, NULL);
}
#line 1616 "parser.c"
        break;
      case 20:
#line 564 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_select_statement(yymsp[-2].minor.yy66, NULL, yymsp[-1].minor.yy66, NULL, NULL, yymsp[0].minor.yy66);
}
#line 1623 "parser.c"
        break;
      case 21:
#line 568 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_select_statement(yymsp[-3].minor.yy66, NULL, yymsp[-1].minor.yy66, yymsp[-2].minor.yy66, NULL, yymsp[0].minor.yy66);
}
#line 1630 "parser.c"
        break;
      case 22:
#line 572 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_select_statement(yymsp[-5].minor.yy66, yymsp[-4].minor.yy66, yymsp[-1].minor.yy66, yymsp[-3].minor.yy66, yymsp[-2].minor.yy66, yymsp[0].minor.yy66);
}
#line 1637 "parser.c"
        break;
      case 23:
#line 576 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_select_statement(yymsp[-1].minor.yy66, NULL, NULL, yymsp[0].minor.yy66, NULL, NULL);
}
#line 1644 "parser.c"
        break;
      case 24:
#line 580 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_select_statement(yymsp[-2].minor.yy66, NULL, NULL, yymsp[-1].minor.yy66, NULL, yymsp[0].minor.yy66);
}
#line 1651 "parser.c"
        break;
      case 25:
#line 584 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_select_statement(yymsp[-2].minor.yy66, NULL, NULL, yymsp[-1].minor.yy66, yymsp[0].minor.yy66, NULL);
}
#line 1658 "parser.c"
        break;
      case 26:
#line 588 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_select_statement(yymsp[-3].minor.yy66, NULL, NULL, yymsp[-2].minor.yy66, yymsp[-1].minor.yy66, yymsp[0].minor.yy66);
}
#line 1665 "parser.c"
        break;
      case 27:
#line 592 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_select_statement(yymsp[-4].minor.yy66, NULL, yymsp[-1].minor.yy66, yymsp[-3].minor.yy66, yymsp[-2].minor.yy66, yymsp[0].minor.yy66);
}
#line 1672 "parser.c"
        break;
      case 28:
#line 596 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_select_statement(yymsp[-1].minor.yy66, NULL, NULL, NULL, NULL, yymsp[0].minor.yy66);
}
#line 1679 "parser.c"
        break;
      case 29:
#line 602 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_select_clause(yymsp[-2].minor.yy66, yymsp[0].minor.yy66, NULL);
  yy_destructor(18,&yymsp[-3].minor);
  yy_destructor(19,&yymsp[-1].minor);
}
#line 1688 "parser.c"
        break;
      case 30:
#line 606 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_select_clause(yymsp[-3].minor.yy66, yymsp[-1].minor.yy66, yymsp[0].minor.yy66);
  yy_destructor(18,&yymsp[-4].minor);
  yy_destructor(19,&yymsp[-2].minor);
}
#line 1697 "parser.c"
        break;
      case 31:
      case 38:
      case 63:
      case 66:
      case 74:
      case 88:
      case 96:
      case 126:
#line 612 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_zval_list(yymsp[-2].minor.yy66, yymsp[0].minor.yy66);
  yy_destructor(20,&yymsp[-1].minor);
}
#line 1712 "parser.c"
        break;
      case 33:
      case 128:
#line 622 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_column_item(PHQL_T_ALL, NULL, NULL, NULL);
  yy_destructor(11,&yymsp[0].minor);
}
#line 1721 "parser.c"
        break;
      case 34:
#line 626 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_column_item(PHQL_T_DOMAINALL, NULL, yymsp[-2].minor.yy0, NULL);
  yy_destructor(22,&yymsp[-1].minor);
  yy_destructor(11,&yymsp[0].minor);
}
#line 1730 "parser.c"
        break;
      case 35:
#line 630 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-2].minor.yy66, NULL, yymsp[0].minor.yy0);
  yy_destructor(23,&yymsp[-1].minor);
}
#line 1738 "parser.c"
        break;
      case 36:
#line 634 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-1].minor.yy66, NULL, yymsp[0].minor.yy0);
}
#line 1745 "parser.c"
        break;
      case 37:
#line 638 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_column_item(PHQL_T_EXPR, yymsp[0].minor.yy66, NULL, NULL);
}
#line 1752 "parser.c"
        break;
      case 40:
#line 654 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_zval_list(yymsp[-1].minor.yy66, yymsp[0].minor.yy66);
}
#line 1759 "parser.c"
        break;
      case 43:
#line 670 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_join_item(yymsp[0].minor.yy66, NULL);
}
#line 1766 "parser.c"
        break;
      case 44:
#line 674 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_join_item(yymsp[-2].minor.yy66, yymsp[0].minor.yy0);
  yy_destructor(23,&yymsp[-1].minor);
}
#line 1774 "parser.c"
        break;
      case 45:
#line 678 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_join_item(yymsp[-1].minor.yy66, yymsp[0].minor.yy0);
}
#line 1781 "parser.c"
        break;
      case 46:
#line 684 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_join_clause(PHQL_T_INNERJOIN, yymsp[0].minor.yy66, NULL);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1789 "parser.c"
        break;
      case 47:
#line 688 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_join_clause(PHQL_T_INNERJOIN, yymsp[-2].minor.yy66, yymsp[0].minor.yy66);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1798 "parser.c"
        break;
      case 48:
#line 692 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_join_clause(PHQL_T_INNERJOIN, yymsp[0].minor.yy66, NULL);
  yy_destructor(26,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1807 "parser.c"
        break;
      case 49:
#line 696 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_join_clause(PHQL_T_INNERJOIN, yymsp[-2].minor.yy66, yymsp[0].minor.yy66);
  yy_destructor(26,&yymsp[-4].minor);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1817 "parser.c"
        break;
      case 50:
#line 700 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_join_clause(PHQL_T_CROSSJOIN, yymsp[0].minor.yy66, NULL);
  yy_destructor(27,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1826 "parser.c"
        break;
      case 51:
#line 704 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_join_clause(PHQL_T_LEFTJOIN, yymsp[0].minor.yy66, NULL);
  yy_destructor(28,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1835 "parser.c"
        break;
      case 52:
#line 708 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_join_clause(PHQL_T_LEFTJOIN, yymsp[0].minor.yy66, NULL);
  yy_destructor(28,&yymsp[-3].minor);
  yy_destructor(29,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1845 "parser.c"
        break;
      case 53:
#line 712 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_join_clause(PHQL_T_LEFTJOIN, yymsp[-2].minor.yy66, yymsp[0].minor.yy66);
  yy_destructor(28,&yymsp[-4].minor);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1855 "parser.c"
        break;
      case 54:
#line 716 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_join_clause(PHQL_T_LEFTJOIN, yymsp[-2].minor.yy66, yymsp[0].minor.yy66);
  yy_destructor(28,&yymsp[-5].minor);
  yy_destructor(29,&yymsp[-4].minor);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1866 "parser.c"
        break;
      case 55:
#line 720 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_join_clause(PHQL_T_RIGHTJOIN, yymsp[0].minor.yy66, NULL);
  yy_destructor(30,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1875 "parser.c"
        break;
      case 56:
#line 724 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_join_clause(PHQL_T_RIGHTJOIN, yymsp[0].minor.yy66, NULL);
  yy_destructor(30,&yymsp[-3].minor);
  yy_destructor(29,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1885 "parser.c"
        break;
      case 57:
#line 728 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_join_clause(PHQL_T_RIGHTJOIN, yymsp[-2].minor.yy66, yymsp[0].minor.yy66);
  yy_destructor(30,&yymsp[-4].minor);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1895 "parser.c"
        break;
      case 58:
#line 732 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_join_clause(PHQL_T_RIGHTJOIN, yymsp[-2].minor.yy66, yymsp[0].minor.yy66);
  yy_destructor(30,&yymsp[-5].minor);
  yy_destructor(29,&yymsp[-4].minor);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1906 "parser.c"
        break;
      case 59:
#line 736 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_join_clause(PHQL_T_FULLOUTER, yymsp[0].minor.yy66, NULL);
  yy_destructor(31,&yymsp[-3].minor);
  yy_destructor(29,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1916 "parser.c"
        break;
      case 60:
#line 740 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_join_clause(PHQL_T_FULLOUTER, yymsp[-2].minor.yy66, yymsp[0].minor.yy66);
  yy_destructor(31,&yymsp[-5].minor);
  yy_destructor(29,&yymsp[-4].minor);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1927 "parser.c"
        break;
      case 61:
#line 747 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_insert_statement(yymsp[-4].minor.yy66, NULL, yymsp[-1].minor.yy66);
  yy_destructor(32,&yymsp[-6].minor);
  yy_destructor(33,&yymsp[-5].minor);
  yy_destructor(34,&yymsp[-3].minor);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
#line 1939 "parser.c"
        break;
      case 62:
#line 751 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_insert_statement(yymsp[-7].minor.yy66, yymsp[-5].minor.yy66, yymsp[-1].minor.yy66);
  yy_destructor(32,&yymsp[-9].minor);
  yy_destructor(33,&yymsp[-8].minor);
  yy_destructor(35,&yymsp[-6].minor);
  yy_destructor(36,&yymsp[-4].minor);
  yy_destructor(34,&yymsp[-3].minor);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
#line 1953 "parser.c"
        break;
      case 68:
      case 142:
#line 781 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_qualified_name(yymsp[0].minor.yy0, NULL);
}
#line 1961 "parser.c"
        break;
      case 69:
#line 789 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_update_statement(yymsp[0].minor.yy66, NULL, NULL);
}
#line 1968 "parser.c"
        break;
      case 70:
#line 793 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_update_statement(yymsp[-1].minor.yy66, yymsp[0].minor.yy66, NULL);
}
#line 1975 "parser.c"
        break;
      case 71:
#line 797 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_update_statement(yymsp[-1].minor.yy66, NULL, yymsp[0].minor.yy66);
}
#line 1982 "parser.c"
        break;
      case 72:
#line 801 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_update_statement(yymsp[-2].minor.yy66, yymsp[-1].minor.yy66, yymsp[0].minor.yy66);
}
#line 1989 "parser.c"
        break;
      case 73:
#line 807 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_update_clause(yymsp[-2].minor.yy66, yymsp[0].minor.yy66);
  yy_destructor(37,&yymsp[-3].minor);
  yy_destructor(38,&yymsp[-1].minor);
}
#line 1998 "parser.c"
        break;
      case 76:
#line 823 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_update_item(yymsp[-2].minor.yy66, yymsp[0].minor.yy66);
  yy_destructor(1,&yymsp[-1].minor);
}
#line 2006 "parser.c"
        break;
      case 78:
#line 835 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_delete_statement(yymsp[0].minor.yy66, NULL, NULL);
}
#line 2013 "parser.c"
        break;
      case 79:
#line 839 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_delete_statement(yymsp[-1].minor.yy66, yymsp[0].minor.yy66, NULL);
}
#line 2020 "parser.c"
        break;
      case 80:
#line 843 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_delete_statement(yymsp[-1].minor.yy66, NULL, yymsp[0].minor.yy66);
}
#line 2027 "parser.c"
        break;
      case 81:
#line 847 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_delete_statement(yymsp[-2].minor.yy66, yymsp[-1].minor.yy66, yymsp[0].minor.yy66);
}
#line 2034 "parser.c"
        break;
      case 82:
#line 853 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_delete_clause(yymsp[0].minor.yy66);
  yy_destructor(39,&yymsp[-2].minor);
  yy_destructor(19,&yymsp[-1].minor);
}
#line 2043 "parser.c"
        break;
      case 83:
#line 859 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_assoc_name(yymsp[-2].minor.yy66, yymsp[0].minor.yy0);
  yy_destructor(23,&yymsp[-1].minor);
}
#line 2051 "parser.c"
        break;
      case 84:
#line 863 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_assoc_name(yymsp[-1].minor.yy66, yymsp[0].minor.yy0);
}
#line 2058 "parser.c"
        break;
      case 85:
#line 867 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_assoc_name(yymsp[0].minor.yy66, NULL);
}
#line 2065 "parser.c"
        break;
      case 86:
#line 873 "parser.lemon"
{
	yygotominor.yy66 = yymsp[0].minor.yy66;
  yy_destructor(40,&yymsp[-1].minor);
}
#line 2073 "parser.c"
        break;
      case 87:
#line 879 "parser.lemon"
{
	yygotominor.yy66 = yymsp[0].minor.yy66;
  yy_destructor(41,&yymsp[-2].minor);
  yy_destructor(42,&yymsp[-1].minor);
}
#line 2082 "parser.c"
        break;
      case 90:
#line 895 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_order_item(yymsp[0].minor.yy66, 0);
}
#line 2089 "parser.c"
        break;
      case 91:
#line 899 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_order_item(yymsp[-1].minor.yy66, PHQL_T_ASC);
  yy_destructor(43,&yymsp[0].minor);
}
#line 2097 "parser.c"
        break;
      case 92:
#line 903 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_order_item(yymsp[-1].minor.yy66, PHQL_T_DESC);
  yy_destructor(44,&yymsp[0].minor);
}
#line 2105 "parser.c"
        break;
      case 94:
      case 99:
      case 135:
#line 911 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_literal_zval(PHQL_T_INTEGER, yymsp[0].minor.yy0);
}
#line 2114 "parser.c"
        break;
      case 95:
#line 917 "parser.lemon"
{
	yygotominor.yy66 = yymsp[0].minor.yy66;
  yy_destructor(46,&yymsp[-2].minor);
  yy_destructor(42,&yymsp[-1].minor);
}
#line 2123 "parser.c"
        break;
      case 100:
#line 943 "parser.lemon"
{
	yygotominor.yy66 = yymsp[0].minor.yy66;
  yy_destructor(47,&yymsp[-1].minor);
}
#line 2131 "parser.c"
        break;
      case 101:
#line 949 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_select_limit_clause(yymsp[0].minor.yy0, NULL);
  yy_destructor(48,&yymsp[-1].minor);
}
#line 2139 "parser.c"
        break;
      case 102:
#line 953 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_select_limit_clause(yymsp[0].minor.yy0, yymsp[-2].minor.yy0);
  yy_destructor(48,&yymsp[-3].minor);
  yy_destructor(20,&yymsp[-1].minor);
}
#line 2148 "parser.c"
        break;
      case 103:
#line 957 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_select_limit_clause(yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(48,&yymsp[-3].minor);
  yy_destructor(49,&yymsp[-1].minor);
}
#line 2157 "parser.c"
        break;
      case 104:
#line 963 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_literal_zval(PHQL_T_INTEGER, yymsp[0].minor.yy0);
  yy_destructor(48,&yymsp[-1].minor);
}
#line 2165 "parser.c"
        break;
      case 105:
#line 969 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_expr(PHQL_T_MINUS, NULL, yymsp[0].minor.yy66);
  yy_destructor(14,&yymsp[-1].minor);
}
#line 2173 "parser.c"
        break;
      case 106:
#line 973 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_expr(PHQL_T_SUB, yymsp[-2].minor.yy66, yymsp[0].minor.yy66);
  yy_destructor(14,&yymsp[-1].minor);
}
#line 2181 "parser.c"
        break;
      case 107:
#line 977 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_expr(PHQL_T_ADD, yymsp[-2].minor.yy66, yymsp[0].minor.yy66);
  yy_destructor(13,&yymsp[-1].minor);
}
#line 2189 "parser.c"
        break;
      case 108:
#line 981 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_expr(PHQL_T_MUL, yymsp[-2].minor.yy66, yymsp[0].minor.yy66);
  yy_destructor(11,&yymsp[-1].minor);
}
#line 2197 "parser.c"
        break;
      case 109:
#line 985 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_expr(PHQL_T_DIV, yymsp[-2].minor.yy66, yymsp[0].minor.yy66);
  yy_destructor(10,&yymsp[-1].minor);
}
#line 2205 "parser.c"
        break;
      case 110:
#line 989 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_expr(PHQL_T_MOD, yymsp[-2].minor.yy66, yymsp[0].minor.yy66);
  yy_destructor(12,&yymsp[-1].minor);
}
#line 2213 "parser.c"
        break;
      case 111:
#line 993 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_expr(PHQL_T_AND, yymsp[-2].minor.yy66, yymsp[0].minor.yy66);
  yy_destructor(7,&yymsp[-1].minor);
}
#line 2221 "parser.c"
        break;
      case 112:
#line 997 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_expr(PHQL_T_OR, yymsp[-2].minor.yy66, yymsp[0].minor.yy66);
  yy_destructor(8,&yymsp[-1].minor);
}
#line 2229 "parser.c"
        break;
      case 113:
#line 1001 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_expr(PHQL_T_EQUALS, yymsp[-2].minor.yy66, yymsp[0].minor.yy66);
  yy_destructor(1,&yymsp[-1].minor);
}
#line 2237 "parser.c"
        break;
      case 114:
#line 1005 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_expr(PHQL_T_NOTEQUALS, yymsp[-2].minor.yy66, yymsp[0].minor.yy66);
  yy_destructor(2,&yymsp[-1].minor);
}
#line 2245 "parser.c"
        break;
      case 115:
#line 1009 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_expr(PHQL_T_LESS, yymsp[-2].minor.yy66, yymsp[0].minor.yy66);
  yy_destructor(3,&yymsp[-1].minor);
}
#line 2253 "parser.c"
        break;
      case 116:
#line 1013 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_expr(PHQL_T_GREATER, yymsp[-2].minor.yy66, yymsp[0].minor.yy66);
  yy_destructor(4,&yymsp[-1].minor);
}
#line 2261 "parser.c"
        break;
      case 117:
#line 1017 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_expr(PHQL_T_GREATEREQUAL, yymsp[-2].minor.yy66, yymsp[0].minor.yy66);
  yy_destructor(5,&yymsp[-1].minor);
}
#line 2269 "parser.c"
        break;
      case 118:
#line 1021 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_expr(PHQL_T_LESSEQUAL, yymsp[-2].minor.yy66, yymsp[0].minor.yy66);
  yy_destructor(6,&yymsp[-1].minor);
}
#line 2277 "parser.c"
        break;
      case 119:
#line 1025 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_expr(PHQL_T_LIKE, yymsp[-2].minor.yy66, yymsp[0].minor.yy66);
  yy_destructor(9,&yymsp[-1].minor);
}
#line 2285 "parser.c"
        break;
      case 120:
#line 1029 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_expr(PHQL_T_NLIKE, yymsp[-3].minor.yy66, yymsp[0].minor.yy66);
  yy_destructor(17,&yymsp[-2].minor);
  yy_destructor(9,&yymsp[-1].minor);
}
#line 2294 "parser.c"
        break;
      case 121:
#line 1033 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_expr(PHQL_T_IN, yymsp[-4].minor.yy66, yymsp[-1].minor.yy66);
  yy_destructor(16,&yymsp[-3].minor);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
#line 2304 "parser.c"
        break;
      case 122:
#line 1037 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_expr(PHQL_T_NOTIN, yymsp[-5].minor.yy66, yymsp[-1].minor.yy66);
  yy_destructor(17,&yymsp[-4].minor);
  yy_destructor(16,&yymsp[-3].minor);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
#line 2315 "parser.c"
        break;
      case 124:
#line 1047 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_func_call(yymsp[-3].minor.yy0, yymsp[-1].minor.yy66);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
#line 2324 "parser.c"
        break;
      case 125:
#line 1051 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_func_call(yymsp[-2].minor.yy0, NULL);
  yy_destructor(35,&yymsp[-1].minor);
  yy_destructor(36,&yymsp[0].minor);
}
#line 2333 "parser.c"
        break;
      case 130:
#line 1075 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_expr(PHQL_T_ISNULL, yymsp[-2].minor.yy66, NULL);
  yy_destructor(15,&yymsp[-1].minor);
  yy_destructor(50,&yymsp[0].minor);
}
#line 2342 "parser.c"
        break;
      case 131:
#line 1079 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_expr(PHQL_T_ISNOTNULL, yymsp[-3].minor.yy66, NULL);
  yy_destructor(15,&yymsp[-2].minor);
  yy_destructor(17,&yymsp[-1].minor);
  yy_destructor(50,&yymsp[0].minor);
}
#line 2352 "parser.c"
        break;
      case 132:
#line 1083 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_expr(PHQL_T_NOT, NULL, yymsp[0].minor.yy66);
  yy_destructor(17,&yymsp[-1].minor);
}
#line 2360 "parser.c"
        break;
      case 133:
#line 1087 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_expr(PHQL_T_ENCLOSED, yymsp[-1].minor.yy66, NULL);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
#line 2369 "parser.c"
        break;
      case 136:
#line 1099 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_literal_zval(PHQL_T_STRING, yymsp[0].minor.yy0);
}
#line 2376 "parser.c"
        break;
      case 137:
#line 1103 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_literal_zval(PHQL_T_DOUBLE, yymsp[0].minor.yy0);
}
#line 2383 "parser.c"
        break;
      case 138:
#line 1107 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_literal_zval(PHQL_T_NULL, NULL);
  yy_destructor(50,&yymsp[0].minor);
}
#line 2391 "parser.c"
        break;
      case 139:
#line 1111 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_placeholder_zval(PHQL_T_NPLACEHOLDER, yymsp[0].minor.yy0);
}
#line 2398 "parser.c"
        break;
      case 140:
#line 1115 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_placeholder_zval(PHQL_T_SPLACEHOLDER, yymsp[0].minor.yy0);
}
#line 2405 "parser.c"
        break;
      case 141:
#line 1121 "parser.lemon"
{
	yygotominor.yy66 = phql_ret_qualified_name(yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(22,&yymsp[-1].minor);
}
#line 2413 "parser.c"
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
#line 423 "parser.lemon"

	if (status->scanner_state->start) {
		{

			char *token_name = NULL;
			int token_found = 0;
			const phql_token_names *tokens = phql_tokens;
			int active_token = status->scanner_state->active_token;
			int near_length = strlen(status->scanner_state->start);

			if (active_token) {

				do {
					if (tokens->code == active_token) {
						token_name = tokens->name;
						token_found = 1;
						break;
					}
					++tokens;
				} while (tokens[0].code != 0);

			}

			if (!token_name) {
				token_name = estrndup("UNKNOWN", strlen("UNKNOWN"));
				token_found = 0;
			}

			status->syntax_error_len = 64 + strlen(token_name) + near_length;
			status->syntax_error = emalloc(sizeof(char)*status->syntax_error_len);
			if (near_length > 0) {
				sprintf(status->syntax_error, "Syntax error, unexpected token %s, near to %s", token_name, status->scanner_state->start);
			} else {
				sprintf(status->syntax_error, "Syntax error, unexpected token %s, at the end of query", token_name);
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

#line 2505 "parser.c"
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
  { PHQL_T_OFFSET,        "OFFSET" },
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

/**
 * Executes the internal PHQL parser/tokenizer
 */
int phql_parse_phql(zval *result, zval *phql TSRMLS_DC){

	zval *error_msg = NULL;

	ZVAL_NULL(result);

	if(phql_internal_parse_phql(&result, Z_STRVAL_P(phql), &error_msg TSRMLS_CC) == FAILURE){
		phalcon_throw_exception_string(phalcon_mvc_model_exception_ce, Z_STRVAL_P(error_msg), Z_STRLEN_P(error_msg) TSRMLS_CC);
		return FAILURE;
	}

	return SUCCESS;
}

/**
 * Executes a PHQL parser/tokenizer
 */
int phql_internal_parse_phql(zval **result, char *phql, zval **error_msg TSRMLS_DC) {

	char *error;
	phql_scanner_state *state;
	phql_scanner_token *token;
	int scanner_status, status = SUCCESS;
	phql_parser_status *parser_status = NULL;
	void* phql_parser;

	if (!phql) {
		PHALCON_INIT_VAR(*error_msg);
		ZVAL_STRING(*error_msg, "PHQL statement cannot be NULL", 1);
		return FAILURE;
	}

	phql_parser = phql_Alloc(phql_wrapper_alloc);

	parser_status = emalloc(sizeof(phql_parser_status));
	state = emalloc(sizeof(phql_scanner_state));
	token = emalloc(sizeof(phql_scanner_token));

	parser_status->status = PHQL_PARSING_OK;
	parser_status->scanner_state = state;
	parser_status->ret = NULL;
	parser_status->syntax_error = NULL;

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
			default:
				parser_status->status = PHQL_PARSING_FAILED;
				error = emalloc(sizeof(char)*32);
				sprintf(error, "scanner: unknown opcode %c", token->opcode);
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

	state->active_token = 0;
	state->start = NULL;

	if (status != FAILURE) {
		switch (scanner_status) {
			case PHQL_SCANNER_RETCODE_ERR:
			case PHQL_SCANNER_RETCODE_IMPOSSIBLE:
				if (!*error_msg) {
					PHALCON_INIT_VAR(*error_msg);
					if (state->start) {
						error = emalloc(sizeof(char)*(48+strlen(state->start)));
						sprintf(error, "Parsing error near to %s (%d)", state->start, status);
						ZVAL_STRING(*error_msg, error, 1);
						efree(error);
					} else {
						ZVAL_STRING(*error_msg, "Parsing error near to EOF", 1);
					}
				}
				status = FAILURE;
				break;
			default:
				phql_(phql_parser, 0, NULL, parser_status);
		}
	}

	if (parser_status->status != PHQL_PARSING_OK) {
		status = FAILURE;
		if (parser_status->syntax_error) {
			if (!*error_msg) {
				PHALCON_ALLOC_ZVAL_MM(*error_msg);
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
			} else {
				efree(parser_status->ret);
			}
		}
	}

	efree(parser_status);
	efree(state);
	efree(token);

	return status;
}