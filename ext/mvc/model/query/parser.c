/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is include which follows the "include" declaration
** in the input file. */
#include <stdio.h>
// 36 "parser.lemon"


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
	array_init_size(ret, 2);
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

static zval *phql_ret_limit_clause(phql_parser_token *L, phql_parser_token *O)
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
	add_assoc_stringl(ret, "name", name->token, name->token_len, 1);
	efree(name->token);
	efree(name);

	if (arguments) {
		add_assoc_zval(ret, "arguments", arguments);
	}

	return ret;
}


// 400 "parser.c"
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
#define YYNOCODE 102
#define YYACTIONTYPE unsigned short int
#define phql_TOKENTYPE phql_parser_token*
typedef union {
  phql_TOKENTYPE yy0;
  zval* yy42;
  int yy203;
} YYMINORTYPE;
#define YYSTACKDEPTH 100
#define phql_ARG_SDECL phql_parser_status *status;
#define phql_ARG_PDECL ,phql_parser_status *status
#define phql_ARG_FETCH phql_parser_status *status = yypParser->status
#define phql_ARG_STORE yypParser->status = status
#define YYNSTATE 233
#define YYNRULE 143
#define YYERRORSYMBOL 57
#define YYERRSYMDT yy203
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
 /*     0 */    79,   55,   57,   59,   61,   63,   65,   51,   53,   67,
 /*    10 */    47,   45,   49,   43,   40,   75,   72,  233,   69,    7,
 /*    20 */   121,  123,  185,  131,  183,  118,   79,   55,   57,   59,
 /*    30 */    61,   63,   65,   51,   53,   67,   47,   45,   49,   43,
 /*    40 */    40,   75,   72,  117,   69,    9,   79,   55,   57,   59,
 /*    50 */    61,   63,   65,   51,   53,   67,   47,   45,   49,   43,
 /*    60 */    40,   75,   72,   95,   69,   55,   57,   59,   61,   63,
 /*    70 */    65,   51,   53,   67,   47,   45,   49,   43,   40,   75,
 /*    80 */    72,   88,   69,   11,   41,  138,   29,   89,   91,  174,
 /*    90 */   140,  141,   82,   88,    8,   16,   41,  112,   77,   89,
 /*   100 */    91,   25,   26,  234,   82,  168,   93,  103,  235,  151,
 /*   110 */   152,  154,  156,   32,  160,  164,   97,  332,   93,   27,
 /*   120 */    28,  100,   98,   99,  101,  102,   83,   35,   97,   17,
 /*   130 */    37,   76,  134,  100,   98,   99,  101,  102,  178,   12,
 /*   140 */    72,   41,   69,   29,   89,   91,  187,   75,   72,  179,
 /*   150 */    69,  215,   41,  230,   70,   89,   91,   23,   34,   26,
 /*   160 */    82,  107,   31,   93,  151,  152,  154,  156,   14,  160,
 /*   170 */   164,   74,   18,   97,   93,   20,   96,  236,  100,   98,
 /*   180 */    99,  101,  102,  237,   97,  124,   30,  126,  130,  100,
 /*   190 */    98,   99,  101,  102,  239,  105,   81,  104,   51,   53,
 /*   200 */    67,   47,   45,   49,   43,   40,   75,   72,   13,   69,
 /*   210 */   238,  377,    1,    2,    3,    4,    5,    6,   67,   47,
 /*   220 */    45,   49,   43,   40,   75,   72,  247,   69,   47,   45,
 /*   230 */    49,   43,   40,   75,   72,  333,   69,   21,   74,  118,
 /*   240 */   209,   19,  113,   96,   10,  226,   43,   40,   75,   72,
 /*   250 */   241,   69,  132,   21,   74,  256,  115,  120,  113,   96,
 /*   260 */    10,  180,   84,   81,  104,  127,  135,   15,  129,  186,
 /*   270 */   182,  139,  140,  141,   83,   96,  196,  196,  109,   81,
 /*   280 */   104,   96,   96,  334,  192,  203,   74,  197,  197,  224,
 /*   290 */    22,   96,  196,   21,   96,   81,  242,   96,   21,   38,
 /*   300 */    10,   81,   81,  195,   38,   10,  223,  177,  182,  255,
 /*   310 */    31,   81,   87,   96,   81,   39,   24,   81,  111,   42,
 /*   320 */    96,  249,   44,   96,   96,   46,   48,   96,  137,   86,
 /*   330 */    96,   96,  175,   81,  119,   32,  170,   50,  221,   21,
 /*   340 */    81,   33,   96,   81,   81,   85,   10,   81,  218,  225,
 /*   350 */    81,   81,   52,   54,   56,   58,   60,   96,   96,   96,
 /*   360 */    96,   96,   81,   62,   64,  244,   66,   68,   96,   96,
 /*   370 */   258,   96,   96,  240,  150,   36,  148,   81,   81,   81,
 /*   380 */    81,   81,   71,  245,  145,  300,  309,   96,   81,   81,
 /*   390 */    80,   81,   81,   90,   92,   96,  243,   94,   96,   96,
 /*   400 */   133,  146,   96,  250,  251,   96,   96,   81,  252,  136,
 /*   410 */   176,  143,  147,   21,   86,   81,   86,  157,   81,   81,
 /*   420 */    10,  158,   81,   10,  194,   81,   81,  132,  132,  173,
 /*   430 */   106,  171,  110,   10,  181,  212,  212,  161,  165,  169,
 /*   440 */   193,  162,  166,  170,  199,   33,   10,  208,  205,  190,
 /*   450 */   198,  194,  210,   10,   10,  301,  216,  221,   10,  310,
 /*   460 */   170,  248,  227,   69,  200,  232,   78,  204,  220,  170,
 /*   470 */    73,  108,  246,  116,  114,  214,  122,  253,  125,  254,
 /*   480 */   260,  259,  257,  261,  128,  229,   31,  145,  149,  142,
 /*   490 */   282,  283,  153,  284,  285,  155,  189,  144,  286,  159,
 /*   500 */   163,  287,  167,  292,  293,  212,  206,  288,  289,  212,
 /*   510 */   290,  172,  184,  211,  207,  303,  335,  302,  219,  228,
 /*   520 */   222,  188,  312,  311,  246,  246,  231,  191,  201,  246,
 /*   530 */   202,  246,  246,  246,  246,  217,  246,  246,  246,  246,
 /*   540 */   246,  213,
};
static YYCODETYPE yy_lookahead[] = {
 /*     0 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    10 */    11,   12,   13,   14,   15,   16,   17,    0,   19,   65,
 /*    20 */    66,   67,   23,   69,   25,   79,    1,    2,    3,    4,
 /*    30 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*    40 */    15,   16,   17,   97,   19,   69,    1,    2,    3,    4,
 /*    50 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*    60 */    15,   16,   17,   38,   19,    2,    3,    4,    5,    6,
 /*    70 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*    80 */    17,   12,   19,   47,   15,   72,   79,   18,   19,   76,
 /*    90 */    77,   78,   23,   12,   66,   67,   15,   69,   19,   18,
 /*   100 */    19,   94,   95,    0,   23,   22,   37,   38,    0,   26,
 /*   110 */    27,   28,   29,   24,   31,   32,   47,    0,   37,   45,
 /*   120 */    46,   52,   53,   54,   55,   56,   37,   66,   47,   68,
 /*   130 */    69,   52,   20,   52,   53,   54,   55,   56,   12,   22,
 /*   140 */    17,   15,   19,   79,   18,   19,   34,   16,   17,   23,
 /*   150 */    19,   39,   15,   41,   10,   18,   19,   93,   94,   95,
 /*   160 */    23,   17,   23,   37,   26,   27,   28,   29,   51,   31,
 /*   170 */    32,   74,   66,   47,   37,   69,   79,    0,   52,   53,
 /*   180 */    54,   55,   56,    0,   47,   66,   47,   68,   69,   52,
 /*   190 */    53,   54,   55,   56,    0,   98,   99,  100,    8,    9,
 /*   200 */    10,   11,   12,   13,   14,   15,   16,   17,   47,   19,
 /*   210 */     0,   58,   59,   60,   61,   62,   63,   64,   10,   11,
 /*   220 */    12,   13,   14,   15,   16,   17,    0,   19,   11,   12,
 /*   230 */    13,   14,   15,   16,   17,    0,   19,   43,   74,   79,
 /*   240 */    87,   69,   48,   79,   50,   92,   14,   15,   16,   17,
 /*   250 */     0,   19,   42,   43,   74,    0,   96,   97,   48,   79,
 /*   260 */    50,   24,   98,   99,  100,   66,   70,   47,   69,   73,
 /*   270 */    74,   76,   77,   78,   37,   79,   74,   74,   98,   99,
 /*   280 */   100,   79,   79,    0,   82,   82,   74,   85,   85,   74,
 /*   290 */    44,   79,   74,   43,   79,   99,    0,   79,   43,   49,
 /*   300 */    50,   99,   99,   85,   49,   50,   91,   73,   74,    0,
 /*   310 */    23,   99,  100,   79,   99,   74,   22,   99,   74,   74,
 /*   320 */    79,    0,   74,   79,   79,   74,   74,   79,   71,   22,
 /*   330 */    79,   79,   75,   99,   47,   24,   79,   74,   79,   43,
 /*   340 */    99,   23,   79,   99,   99,   38,   50,   99,   89,   90,
 /*   350 */    99,   99,   74,   74,   74,   74,   74,   79,   79,   79,
 /*   360 */    79,   79,   99,   74,   74,    0,   74,   74,   79,   79,
 /*   370 */     0,   79,   79,    0,   23,   69,   25,   99,   99,   99,
 /*   380 */    99,   99,   74,    0,   33,    0,    0,   79,   99,   99,
 /*   390 */    74,   99,   99,   74,   74,   79,    0,   74,   79,   79,
 /*   400 */    74,   74,   79,    0,    0,   79,   79,   99,    0,   21,
 /*   410 */    22,   80,   81,   43,   22,   99,   22,   26,   99,   99,
 /*   420 */    50,   30,   99,   50,   22,   99,   99,   42,   42,   23,
 /*   430 */    38,   25,   38,   50,   12,   50,   50,   26,   26,   75,
 /*   440 */    38,   30,   30,   79,   83,   23,   50,   86,   22,   36,
 /*   450 */    37,   22,   65,   50,   50,    0,   75,   79,   50,    0,
 /*   460 */    79,    0,   65,   19,   38,   75,   52,   38,   90,   79,
 /*   470 */    37,   37,    0,   22,   44,   88,   69,    0,   69,    0,
 /*   480 */     0,    0,    0,    0,   69,   88,   23,   33,   23,   79,
 /*   490 */    23,   23,   26,   23,   23,   26,   79,   81,   23,   26,
 /*   500 */    26,   23,   26,    0,    0,   50,   86,   23,   23,   50,
 /*   510 */    23,   23,   23,   88,   23,    0,    0,    0,   22,   88,
 /*   520 */     2,   35,    0,    0,  101,  101,   21,   37,   36,  101,
 /*   530 */    37,  101,  101,  101,  101,   40,  101,  101,  101,  101,
 /*   540 */   101,   47,
};
#define YY_SHIFT_USE_DFLT (-2)
static short yy_shift_ofst[] = {
 /*     0 */   112,   17,  103,  108,  177,  183,  210,  194,  373,  226,
 /*    10 */    36,  117,  161,  235,  220,  283,  250,  296,  383,  309,
 /*    20 */   321,  246,  139,  294,  139,   -2,   74,   -2,   -2,   -2,
 /*    30 */    -2,  311,  318,   -2,   -2,  396,  365,  461,  137,   45,
 /*    40 */   137,  137,  131,  137,  131,  137,  232,  137,  232,  137,
 /*    50 */   232,  137,  208,  137,  208,  137,  190,  137,  190,  137,
 /*    60 */   190,  137,  190,  137,  190,  137,  190,  137,  217,  144,
 /*    70 */   137,  444,  433,   81,   45,   79,   -2,  414,   -2,  137,
 /*    80 */    63,   -2,   89,   69,  307,   -2,   81,   -2,   -2,  137,
 /*    90 */   123,  137,  444,  137,   25,   -2,   -2,   -2,   -2,   -2,
 /*   100 */    -2,   -2,   -2,   -2,   -2,  392,   -2,  434,   81,  394,
 /*   110 */    -2,  131,  472,  430,  287,  451,  287,   -2,   -2,   -2,
 /*   120 */    -2,  403,  477,  255,  404,  479,  370,  408,  480,  481,
 /*   130 */   482,  483,  137,   45,  126,  388,  463,   83,  138,   -2,
 /*   140 */    -2,  463,  351,  454,   -2,  137,   45,   -2,  465,   -2,
 /*   150 */    -2,  467,  466,  468,  469,  470,  391,  471,  473,  475,
 /*   160 */   411,  478,  474,  484,  412,  485,  476,  487,  463,   -2,
 /*   170 */   406,  488,   -2,   -2,   -2,   -2,  126,   -2,   -2,  237,
 /*   180 */   422,   -2,   -1,  489,   -2,   -2,   -2,  486,  463,  413,
 /*   190 */   490,  137,  402,  503,  137,   -2,   45,   -2,  491,  426,
 /*   200 */   492,  493,  137,  429,  504,  491,   -2,   -2,   -2,  385,
 /*   210 */   455,  515,  494,  516,  517,  463,  495,  463,  496,  463,
 /*   220 */    -2,  518,  137,   -2,   45,   -2,  386,  459,  522,  523,
 /*   230 */   505,  463,   -2,
};
#define YY_REDUCE_USE_DFLT (-55)
static short yy_reduce_ofst[] = {
 /*     0 */   153,  -55,  -55,  -55,  -55,  -55,  -46,   28,  -24,  -55,
 /*    10 */   -55,  -55,  -55,  -55,  -55,  -55,   61,  106,  172,  -55,
 /*    20 */   -55,  -55,   64,  -55,    7,  -55,  -55,  -55,  -55,  -55,
 /*    30 */   -55,  -55,  -55,  -55,  -55,  306,  -55,  -55,  241,  -55,
 /*    40 */   244,  245,  -55,  248,  -55,  251,  -55,  252,  -55,  263,
 /*    50 */   -55,  278,  -55,  279,  -55,  280,  -55,  281,  -55,  282,
 /*    60 */   -55,  289,  -55,  290,  -55,  292,  -55,  293,  -55,  -55,
 /*    70 */   308,  -55,  -55,   97,  -55,  -55,  -55,  -55,  -55,  316,
 /*    80 */   -55,  -55,  -55,  164,  -55,  -55,  212,  -55,  -55,  319,
 /*    90 */   -55,  320,  -55,  323,  -55,  -55,  -55,  -55,  -55,  -55,
 /*   100 */   -55,  -55,  -55,  -55,  -55,  -55,  -55,  -55,  180,  -55,
 /*   110 */   -55,  -55,  -55,  -55,  160,  -55,  -54,  -55,  -55,  -55,
 /*   120 */   -55,  407,  -55,  119,  409,  -55,  199,  415,  -55,  -55,
 /*   130 */   -55,  -55,  326,  -55,  196,  -55,  257,   13,  195,  -55,
 /*   140 */   -55,  410,  331,  416,  -55,  327,  -55,  -55,  -55,  -55,
 /*   150 */   -55,  -55,  -55,  -55,  -55,  -55,  -55,  -55,  -55,  -55,
 /*   160 */   -55,  -55,  -55,  -55,  -55,  -55,  -55,  -55,  364,  -55,
 /*   170 */   -55,  -55,  -55,  -55,  -55,  -55,  234,  -55,  -55,  -55,
 /*   180 */   -55,  -55,  -55,  -55,  -55,  -55,  -55,  -55,  417,  -55,
 /*   190 */   -55,  202,  -55,  -55,  218,  -55,  -55,  -55,  361,  -55,
 /*   200 */   -55,  -55,  203,  -55,  -55,  420,  -55,  -55,  -55,  387,
 /*   210 */   425,  -55,  -55,  -55,  -55,  381,  -55,  259,  -55,  378,
 /*   220 */   -55,  -55,  215,  -55,  -55,  -55,  397,  431,  -55,  -55,
 /*   230 */   -55,  390,  -55,
};
static YYACTIONTYPE yy_default[] = {
 /*     0 */   376,  376,  376,  376,  376,  376,  376,  376,  376,  376,
 /*    10 */   376,  376,  376,  376,  376,  376,  376,  376,  376,  376,
 /*    20 */   376,  376,  376,  318,  376,  319,  321,  322,  323,  324,
 /*    30 */   325,  375,  376,  374,  320,  376,  376,  376,  376,  331,
 /*    40 */   376,  376,  336,  376,  338,  376,  339,  376,  340,  376,
 /*    50 */   341,  376,  342,  376,  343,  376,  344,  376,  345,  376,
 /*    60 */   346,  376,  347,  376,  348,  376,  349,  376,  350,  376,
 /*    70 */   376,  351,  376,  376,  360,  376,  361,  376,  362,  376,
 /*    80 */   364,  354,  375,  376,  376,  355,  376,  357,  359,  376,
 /*    90 */   363,  376,  365,  376,  376,  366,  367,  368,  369,  370,
 /*   100 */   371,  372,  373,  356,  358,  376,  352,  376,  376,  376,
 /*   110 */   353,  337,  376,  376,  376,  326,  376,  327,  329,  330,
 /*   120 */   328,  376,  376,  376,  376,  376,  376,  376,  376,  376,
 /*   130 */   376,  376,  376,  317,  376,  376,  376,  262,  263,  273,
 /*   140 */   275,  376,  276,  277,  279,  376,  291,  278,  376,  280,
 /*   150 */   281,  376,  376,  376,  376,  376,  376,  376,  376,  376,
 /*   160 */   376,  376,  376,  376,  376,  376,  376,  376,  376,  271,
 /*   170 */   316,  376,  314,  315,  274,  272,  376,  264,  266,  375,
 /*   180 */   376,  267,  270,  376,  268,  269,  265,  376,  376,  376,
 /*   190 */   376,  376,  376,  376,  376,  294,  296,  295,  376,  376,
 /*   200 */   376,  376,  376,  376,  376,  376,  297,  299,  298,  376,
 /*   210 */   376,  376,  376,  376,  376,  376,  376,  376,  304,  376,
 /*   220 */   305,  376,  376,  307,  308,  306,  376,  376,  376,  376,
 /*   230 */   376,  376,  313,
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
  "$",             "BETWEEN",       "EQUALS",        "NOTEQUALS",   
  "LESS",          "GREATER",       "GREATEREQUAL",  "LESSEQUAL",   
  "AND",           "OR",            "LIKE",          "DIVIDE",      
  "TIMES",         "MOD",           "PLUS",          "MINUS",       
  "IS",            "IN",            "DISTINCT",      "NOT",         
  "SELECT",        "FROM",          "COMMA",         "IDENTIFIER",  
  "DOT",           "AS",            "JOIN",          "INNER",       
  "CROSS",         "LEFT",          "OUTER",         "RIGHT",       
  "FULL",          "ON",            "INSERT",        "INTO",        
  "VALUES",        "BRACKET_OPEN",  "BRACKET_CLOSE",  "UPDATE",      
  "SET",           "DELETE",        "WHERE",         "ORDER",       
  "BY",            "ASC",           "DESC",          "INTEGER",     
  "GROUP",         "HAVING",        "LIMIT",         "OFFSET",      
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
 /*  88 */ "order_item ::= order_qualified_or_int",
 /*  89 */ "order_item ::= order_qualified_or_int ASC",
 /*  90 */ "order_item ::= order_qualified_or_int DESC",
 /*  91 */ "order_qualified_or_int ::= qualified_name",
 /*  92 */ "order_qualified_or_int ::= INTEGER",
 /*  93 */ "group_clause ::= GROUP BY group_list",
 /*  94 */ "group_list ::= group_list COMMA group_item",
 /*  95 */ "group_list ::= group_item",
 /*  96 */ "group_item ::= qualified_name",
 /*  97 */ "group_item ::= INTEGER",
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
 /* 111 */ "expr ::= expr EQUALS expr",
 /* 112 */ "expr ::= expr NOTEQUALS expr",
 /* 113 */ "expr ::= expr LESS expr",
 /* 114 */ "expr ::= expr GREATER expr",
 /* 115 */ "expr ::= expr GREATEREQUAL expr",
 /* 116 */ "expr ::= expr LESSEQUAL expr",
 /* 117 */ "expr ::= expr LIKE expr",
 /* 118 */ "expr ::= expr NOT LIKE expr",
 /* 119 */ "expr ::= expr IN BRACKET_OPEN argument_list BRACKET_CLOSE",
 /* 120 */ "expr ::= expr NOT IN BRACKET_OPEN argument_list BRACKET_CLOSE",
 /* 121 */ "expr ::= function_call",
 /* 122 */ "function_call ::= IDENTIFIER BRACKET_OPEN argument_list BRACKET_CLOSE",
 /* 123 */ "function_call ::= IDENTIFIER BRACKET_OPEN BRACKET_CLOSE",
 /* 124 */ "argument_list ::= argument_list COMMA argument_item",
 /* 125 */ "argument_list ::= argument_item",
 /* 126 */ "argument_item ::= TIMES",
 /* 127 */ "argument_item ::= expr",
 /* 128 */ "expr ::= expr IS NULL",
 /* 129 */ "expr ::= expr IS NOT NULL",
 /* 130 */ "expr ::= DISTINCT expr",
 /* 131 */ "expr ::= expr BETWEEN expr",
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
    case 55:
    case 56:
// 478 "parser.lemon"
{
	if ((yypminor->yy0)) {
		efree((yypminor->yy0)->token);
		efree((yypminor->yy0));
	}
}
// 1092 "parser.c"
      break;
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
    case 83:
    case 84:
    case 86:
    case 87:
    case 88:
    case 89:
    case 90:
    case 92:
    case 93:
    case 94:
    case 96:
    case 97:
    case 98:
    case 99:
    case 100:
// 489 "parser.lemon"
{ zval_ptr_dtor(&(yypminor->yy42)); }
// 1134 "parser.c"
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
  { 58, 1 },
  { 59, 1 },
  { 59, 1 },
  { 59, 1 },
  { 59, 1 },
  { 60, 1 },
  { 60, 2 },
  { 60, 3 },
  { 60, 3 },
  { 60, 4 },
  { 60, 4 },
  { 60, 5 },
  { 60, 5 },
  { 60, 3 },
  { 60, 4 },
  { 60, 4 },
  { 60, 5 },
  { 60, 2 },
  { 60, 3 },
  { 60, 4 },
  { 60, 3 },
  { 60, 4 },
  { 60, 6 },
  { 60, 2 },
  { 60, 3 },
  { 60, 3 },
  { 60, 4 },
  { 60, 5 },
  { 60, 2 },
  { 64, 4 },
  { 64, 5 },
  { 70, 3 },
  { 70, 1 },
  { 73, 1 },
  { 73, 3 },
  { 73, 3 },
  { 73, 2 },
  { 73, 1 },
  { 71, 3 },
  { 71, 1 },
  { 72, 2 },
  { 72, 1 },
  { 76, 1 },
  { 77, 2 },
  { 77, 3 },
  { 77, 3 },
  { 77, 4 },
  { 80, 2 },
  { 80, 1 },
  { 78, 1 },
  { 78, 2 },
  { 78, 2 },
  { 78, 2 },
  { 78, 3 },
  { 78, 2 },
  { 78, 3 },
  { 78, 2 },
  { 78, 3 },
  { 81, 2 },
  { 61, 7 },
  { 61, 10 },
  { 82, 3 },
  { 82, 1 },
  { 85, 1 },
  { 83, 3 },
  { 83, 1 },
  { 86, 1 },
  { 62, 1 },
  { 62, 2 },
  { 62, 2 },
  { 62, 3 },
  { 87, 4 },
  { 89, 3 },
  { 89, 1 },
  { 90, 3 },
  { 91, 1 },
  { 63, 1 },
  { 63, 2 },
  { 63, 2 },
  { 63, 3 },
  { 92, 3 },
  { 75, 3 },
  { 75, 2 },
  { 75, 1 },
  { 65, 2 },
  { 66, 3 },
  { 93, 3 },
  { 93, 1 },
  { 94, 1 },
  { 94, 2 },
  { 94, 2 },
  { 95, 1 },
  { 95, 1 },
  { 67, 3 },
  { 96, 3 },
  { 96, 1 },
  { 97, 1 },
  { 97, 1 },
  { 68, 2 },
  { 69, 2 },
  { 69, 4 },
  { 69, 4 },
  { 88, 2 },
  { 74, 2 },
  { 74, 3 },
  { 74, 3 },
  { 74, 3 },
  { 74, 3 },
  { 74, 3 },
  { 74, 3 },
  { 74, 3 },
  { 74, 3 },
  { 74, 3 },
  { 74, 3 },
  { 74, 3 },
  { 74, 3 },
  { 74, 3 },
  { 74, 3 },
  { 74, 4 },
  { 74, 5 },
  { 74, 6 },
  { 74, 1 },
  { 99, 4 },
  { 99, 3 },
  { 98, 3 },
  { 98, 1 },
  { 100, 1 },
  { 100, 1 },
  { 74, 3 },
  { 74, 4 },
  { 74, 2 },
  { 74, 3 },
  { 74, 2 },
  { 74, 3 },
  { 74, 1 },
  { 74, 1 },
  { 74, 1 },
  { 74, 1 },
  { 74, 1 },
  { 74, 1 },
  { 74, 1 },
  { 79, 3 },
  { 79, 1 },
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
// 485 "parser.lemon"
{
	status->ret = yymsp[0].minor.yy42;
}
// 1494 "parser.c"
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
      case 91:
      case 95:
      case 96:
      case 121:
      case 127:
      case 134:
// 491 "parser.lemon"
{
	yygotominor.yy42 = yymsp[0].minor.yy42;
}
// 1520 "parser.c"
        break;
      case 5:
// 509 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_select_statement(yymsp[0].minor.yy42, NULL, NULL, NULL, NULL, NULL);
}
// 1527 "parser.c"
        break;
      case 6:
// 513 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_select_statement(yymsp[-1].minor.yy42, yymsp[0].minor.yy42, NULL, NULL, NULL, NULL);
}
// 1534 "parser.c"
        break;
      case 7:
// 517 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_select_statement(yymsp[-2].minor.yy42, yymsp[-1].minor.yy42, yymsp[0].minor.yy42, NULL, NULL, NULL);
}
// 1541 "parser.c"
        break;
      case 8:
// 521 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_select_statement(yymsp[-2].minor.yy42, yymsp[-1].minor.yy42, NULL, yymsp[0].minor.yy42, NULL, NULL);
}
// 1548 "parser.c"
        break;
      case 9:
// 525 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_select_statement(yymsp[-3].minor.yy42, yymsp[-2].minor.yy42, NULL, yymsp[-1].minor.yy42, yymsp[0].minor.yy42, NULL);
}
// 1555 "parser.c"
        break;
      case 10:
// 529 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_select_statement(yymsp[-3].minor.yy42, yymsp[-2].minor.yy42, yymsp[0].minor.yy42, yymsp[-1].minor.yy42, NULL, NULL);
}
// 1562 "parser.c"
        break;
      case 11:
// 533 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_select_statement(yymsp[-4].minor.yy42, yymsp[-3].minor.yy42, yymsp[-1].minor.yy42, yymsp[-2].minor.yy42, NULL, yymsp[0].minor.yy42);
}
// 1569 "parser.c"
        break;
      case 12:
// 537 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_select_statement(yymsp[-4].minor.yy42, yymsp[-3].minor.yy42, yymsp[0].minor.yy42, yymsp[-2].minor.yy42, yymsp[-1].minor.yy42, NULL);
}
// 1576 "parser.c"
        break;
      case 13:
// 541 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_select_statement(yymsp[-2].minor.yy42, yymsp[-1].minor.yy42, NULL, NULL, NULL, yymsp[0].minor.yy42);
}
// 1583 "parser.c"
        break;
      case 14:
// 545 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_select_statement(yymsp[-3].minor.yy42, yymsp[-2].minor.yy42, yymsp[-1].minor.yy42, NULL, NULL, yymsp[0].minor.yy42);
}
// 1590 "parser.c"
        break;
      case 15:
// 549 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_select_statement(yymsp[-3].minor.yy42, yymsp[-2].minor.yy42, NULL, yymsp[-1].minor.yy42, NULL, yymsp[0].minor.yy42);
}
// 1597 "parser.c"
        break;
      case 16:
// 553 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_select_statement(yymsp[-4].minor.yy42, yymsp[-3].minor.yy42, NULL, yymsp[-2].minor.yy42, yymsp[-1].minor.yy42, yymsp[0].minor.yy42);
}
// 1604 "parser.c"
        break;
      case 17:
// 557 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_select_statement(yymsp[-1].minor.yy42, NULL, yymsp[0].minor.yy42, NULL, NULL, NULL);
}
// 1611 "parser.c"
        break;
      case 18:
// 561 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_select_statement(yymsp[-2].minor.yy42, NULL, yymsp[0].minor.yy42, yymsp[-1].minor.yy42, NULL, NULL);
}
// 1618 "parser.c"
        break;
      case 19:
// 565 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_select_statement(yymsp[-3].minor.yy42, NULL, yymsp[0].minor.yy42, yymsp[-2].minor.yy42, yymsp[-1].minor.yy42, NULL);
}
// 1625 "parser.c"
        break;
      case 20:
// 569 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_select_statement(yymsp[-2].minor.yy42, NULL, yymsp[-1].minor.yy42, NULL, NULL, yymsp[0].minor.yy42);
}
// 1632 "parser.c"
        break;
      case 21:
// 573 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_select_statement(yymsp[-3].minor.yy42, NULL, yymsp[-1].minor.yy42, yymsp[-2].minor.yy42, NULL, yymsp[0].minor.yy42);
}
// 1639 "parser.c"
        break;
      case 22:
// 577 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_select_statement(yymsp[-5].minor.yy42, yymsp[-4].minor.yy42, yymsp[-1].minor.yy42, yymsp[-3].minor.yy42, yymsp[-2].minor.yy42, yymsp[0].minor.yy42);
}
// 1646 "parser.c"
        break;
      case 23:
// 581 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_select_statement(yymsp[-1].minor.yy42, NULL, NULL, yymsp[0].minor.yy42, NULL, NULL);
}
// 1653 "parser.c"
        break;
      case 24:
// 585 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_select_statement(yymsp[-2].minor.yy42, NULL, NULL, yymsp[-1].minor.yy42, NULL, yymsp[0].minor.yy42);
}
// 1660 "parser.c"
        break;
      case 25:
// 589 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_select_statement(yymsp[-2].minor.yy42, NULL, NULL, yymsp[-1].minor.yy42, yymsp[0].minor.yy42, NULL);
}
// 1667 "parser.c"
        break;
      case 26:
// 593 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_select_statement(yymsp[-3].minor.yy42, NULL, NULL, yymsp[-2].minor.yy42, yymsp[-1].minor.yy42, yymsp[0].minor.yy42);
}
// 1674 "parser.c"
        break;
      case 27:
// 597 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_select_statement(yymsp[-4].minor.yy42, NULL, yymsp[-1].minor.yy42, yymsp[-3].minor.yy42, yymsp[-2].minor.yy42, yymsp[0].minor.yy42);
}
// 1681 "parser.c"
        break;
      case 28:
// 601 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_select_statement(yymsp[-1].minor.yy42, NULL, NULL, NULL, NULL, yymsp[0].minor.yy42);
}
// 1688 "parser.c"
        break;
      case 29:
// 607 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_select_clause(yymsp[-2].minor.yy42, yymsp[0].minor.yy42, NULL);
  yy_destructor(20,&yymsp[-3].minor);
  yy_destructor(21,&yymsp[-1].minor);
}
// 1697 "parser.c"
        break;
      case 30:
// 611 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_select_clause(yymsp[-3].minor.yy42, yymsp[-1].minor.yy42, yymsp[0].minor.yy42);
  yy_destructor(20,&yymsp[-4].minor);
  yy_destructor(21,&yymsp[-2].minor);
}
// 1706 "parser.c"
        break;
      case 31:
      case 38:
      case 61:
      case 64:
      case 72:
      case 86:
      case 94:
      case 124:
// 617 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_zval_list(yymsp[-2].minor.yy42, yymsp[0].minor.yy42);
  yy_destructor(22,&yymsp[-1].minor);
}
// 1721 "parser.c"
        break;
      case 33:
      case 126:
// 627 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_column_item(PHQL_T_ALL, NULL, NULL, NULL);
  yy_destructor(12,&yymsp[0].minor);
}
// 1730 "parser.c"
        break;
      case 34:
// 631 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_column_item(PHQL_T_DOMAINALL, NULL, yymsp[-2].minor.yy0, NULL);
  yy_destructor(24,&yymsp[-1].minor);
  yy_destructor(12,&yymsp[0].minor);
}
// 1739 "parser.c"
        break;
      case 35:
// 635 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-2].minor.yy42, NULL, yymsp[0].minor.yy0);
  yy_destructor(25,&yymsp[-1].minor);
}
// 1747 "parser.c"
        break;
      case 36:
// 639 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-1].minor.yy42, NULL, yymsp[0].minor.yy0);
}
// 1754 "parser.c"
        break;
      case 37:
// 643 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_column_item(PHQL_T_EXPR, yymsp[0].minor.yy42, NULL, NULL);
}
// 1761 "parser.c"
        break;
      case 40:
// 659 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_zval_list(yymsp[-1].minor.yy42, yymsp[0].minor.yy42);
}
// 1768 "parser.c"
        break;
      case 43:
// 676 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_join_item(yymsp[-1].minor.yy42, yymsp[0].minor.yy42, NULL, NULL);
}
// 1775 "parser.c"
        break;
      case 44:
// 681 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_join_item(yymsp[-2].minor.yy42, yymsp[-1].minor.yy42, yymsp[0].minor.yy42, NULL);
}
// 1782 "parser.c"
        break;
      case 45:
// 686 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_join_item(yymsp[-2].minor.yy42, yymsp[-1].minor.yy42, NULL, yymsp[0].minor.yy42);
}
// 1789 "parser.c"
        break;
      case 46:
// 691 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_join_item(yymsp[-3].minor.yy42, yymsp[-2].minor.yy42, yymsp[-1].minor.yy42, yymsp[0].minor.yy42);
}
// 1796 "parser.c"
        break;
      case 47:
// 697 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_qualified_name(yymsp[0].minor.yy0, NULL);
  yy_destructor(25,&yymsp[-1].minor);
}
// 1804 "parser.c"
        break;
      case 48:
      case 66:
      case 142:
// 701 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_qualified_name(yymsp[0].minor.yy0, NULL);
}
// 1813 "parser.c"
        break;
      case 49:
// 707 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_join_type(PHQL_T_INNERJOIN);
  yy_destructor(26,&yymsp[0].minor);
}
// 1821 "parser.c"
        break;
      case 50:
// 711 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_join_type(PHQL_T_INNERJOIN);
  yy_destructor(27,&yymsp[-1].minor);
  yy_destructor(26,&yymsp[0].minor);
}
// 1830 "parser.c"
        break;
      case 51:
// 715 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_join_type(PHQL_T_CROSSJOIN);
  yy_destructor(28,&yymsp[-1].minor);
  yy_destructor(26,&yymsp[0].minor);
}
// 1839 "parser.c"
        break;
      case 52:
// 719 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  yy_destructor(29,&yymsp[-1].minor);
  yy_destructor(26,&yymsp[0].minor);
}
// 1848 "parser.c"
        break;
      case 53:
// 723 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  yy_destructor(29,&yymsp[-2].minor);
  yy_destructor(30,&yymsp[-1].minor);
  yy_destructor(26,&yymsp[0].minor);
}
// 1858 "parser.c"
        break;
      case 54:
// 727 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  yy_destructor(31,&yymsp[-1].minor);
  yy_destructor(26,&yymsp[0].minor);
}
// 1867 "parser.c"
        break;
      case 55:
// 731 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  yy_destructor(31,&yymsp[-2].minor);
  yy_destructor(30,&yymsp[-1].minor);
  yy_destructor(26,&yymsp[0].minor);
}
// 1877 "parser.c"
        break;
      case 56:
// 735 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_join_type(PHQL_T_FULLJOIN);
  yy_destructor(32,&yymsp[-1].minor);
  yy_destructor(26,&yymsp[0].minor);
}
// 1886 "parser.c"
        break;
      case 57:
// 739 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_join_type(PHQL_T_FULLJOIN);
  yy_destructor(32,&yymsp[-2].minor);
  yy_destructor(30,&yymsp[-1].minor);
  yy_destructor(26,&yymsp[0].minor);
}
// 1896 "parser.c"
        break;
      case 58:
// 745 "parser.lemon"
{
	yygotominor.yy42 = yymsp[0].minor.yy42;
  yy_destructor(33,&yymsp[-1].minor);
}
// 1904 "parser.c"
        break;
      case 59:
// 752 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_insert_statement(yymsp[-4].minor.yy42, NULL, yymsp[-1].minor.yy42);
  yy_destructor(34,&yymsp[-6].minor);
  yy_destructor(35,&yymsp[-5].minor);
  yy_destructor(36,&yymsp[-3].minor);
  yy_destructor(37,&yymsp[-2].minor);
  yy_destructor(38,&yymsp[0].minor);
}
// 1916 "parser.c"
        break;
      case 60:
// 756 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_insert_statement(yymsp[-7].minor.yy42, yymsp[-5].minor.yy42, yymsp[-1].minor.yy42);
  yy_destructor(34,&yymsp[-9].minor);
  yy_destructor(35,&yymsp[-8].minor);
  yy_destructor(37,&yymsp[-6].minor);
  yy_destructor(38,&yymsp[-4].minor);
  yy_destructor(36,&yymsp[-3].minor);
  yy_destructor(37,&yymsp[-2].minor);
  yy_destructor(38,&yymsp[0].minor);
}
// 1930 "parser.c"
        break;
      case 67:
// 794 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_update_statement(yymsp[0].minor.yy42, NULL, NULL);
}
// 1937 "parser.c"
        break;
      case 68:
// 798 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_update_statement(yymsp[-1].minor.yy42, yymsp[0].minor.yy42, NULL);
}
// 1944 "parser.c"
        break;
      case 69:
// 802 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_update_statement(yymsp[-1].minor.yy42, NULL, yymsp[0].minor.yy42);
}
// 1951 "parser.c"
        break;
      case 70:
// 806 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_update_statement(yymsp[-2].minor.yy42, yymsp[-1].minor.yy42, yymsp[0].minor.yy42);
}
// 1958 "parser.c"
        break;
      case 71:
// 812 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_update_clause(yymsp[-2].minor.yy42, yymsp[0].minor.yy42);
  yy_destructor(39,&yymsp[-3].minor);
  yy_destructor(40,&yymsp[-1].minor);
}
// 1967 "parser.c"
        break;
      case 74:
// 828 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_update_item(yymsp[-2].minor.yy42, yymsp[0].minor.yy42);
  yy_destructor(2,&yymsp[-1].minor);
}
// 1975 "parser.c"
        break;
      case 76:
// 840 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_delete_statement(yymsp[0].minor.yy42, NULL, NULL);
}
// 1982 "parser.c"
        break;
      case 77:
// 844 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_delete_statement(yymsp[-1].minor.yy42, yymsp[0].minor.yy42, NULL);
}
// 1989 "parser.c"
        break;
      case 78:
// 848 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_delete_statement(yymsp[-1].minor.yy42, NULL, yymsp[0].minor.yy42);
}
// 1996 "parser.c"
        break;
      case 79:
// 852 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_delete_statement(yymsp[-2].minor.yy42, yymsp[-1].minor.yy42, yymsp[0].minor.yy42);
}
// 2003 "parser.c"
        break;
      case 80:
// 858 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_delete_clause(yymsp[0].minor.yy42);
  yy_destructor(41,&yymsp[-2].minor);
  yy_destructor(21,&yymsp[-1].minor);
}
// 2012 "parser.c"
        break;
      case 81:
// 864 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_assoc_name(yymsp[-2].minor.yy42, yymsp[0].minor.yy0);
  yy_destructor(25,&yymsp[-1].minor);
}
// 2020 "parser.c"
        break;
      case 82:
// 868 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_assoc_name(yymsp[-1].minor.yy42, yymsp[0].minor.yy0);
}
// 2027 "parser.c"
        break;
      case 83:
// 872 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_assoc_name(yymsp[0].minor.yy42, NULL);
}
// 2034 "parser.c"
        break;
      case 84:
// 878 "parser.lemon"
{
	yygotominor.yy42 = yymsp[0].minor.yy42;
  yy_destructor(42,&yymsp[-1].minor);
}
// 2042 "parser.c"
        break;
      case 85:
// 884 "parser.lemon"
{
	yygotominor.yy42 = yymsp[0].minor.yy42;
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[-1].minor);
}
// 2051 "parser.c"
        break;
      case 88:
// 900 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_order_item(yymsp[0].minor.yy42, 0);
}
// 2058 "parser.c"
        break;
      case 89:
// 904 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_order_item(yymsp[-1].minor.yy42, PHQL_T_ASC);
  yy_destructor(45,&yymsp[0].minor);
}
// 2066 "parser.c"
        break;
      case 90:
// 908 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_order_item(yymsp[-1].minor.yy42, PHQL_T_DESC);
  yy_destructor(46,&yymsp[0].minor);
}
// 2074 "parser.c"
        break;
      case 92:
      case 97:
      case 135:
// 916 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_literal_zval(PHQL_T_INTEGER, yymsp[0].minor.yy0);
}
// 2083 "parser.c"
        break;
      case 93:
// 922 "parser.lemon"
{
	yygotominor.yy42 = yymsp[0].minor.yy42;
  yy_destructor(48,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[-1].minor);
}
// 2092 "parser.c"
        break;
      case 98:
// 948 "parser.lemon"
{
	yygotominor.yy42 = yymsp[0].minor.yy42;
  yy_destructor(49,&yymsp[-1].minor);
}
// 2100 "parser.c"
        break;
      case 99:
      case 102:
// 954 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_limit_clause(yymsp[0].minor.yy0, NULL);
  yy_destructor(50,&yymsp[-1].minor);
}
// 2109 "parser.c"
        break;
      case 100:
// 958 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_limit_clause(yymsp[0].minor.yy0, yymsp[-2].minor.yy0);
  yy_destructor(50,&yymsp[-3].minor);
  yy_destructor(22,&yymsp[-1].minor);
}
// 2118 "parser.c"
        break;
      case 101:
// 962 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_limit_clause(yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(50,&yymsp[-3].minor);
  yy_destructor(51,&yymsp[-1].minor);
}
// 2127 "parser.c"
        break;
      case 103:
// 974 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_expr(PHQL_T_MINUS, NULL, yymsp[0].minor.yy42);
  yy_destructor(15,&yymsp[-1].minor);
}
// 2135 "parser.c"
        break;
      case 104:
// 978 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_expr(PHQL_T_SUB, yymsp[-2].minor.yy42, yymsp[0].minor.yy42);
  yy_destructor(15,&yymsp[-1].minor);
}
// 2143 "parser.c"
        break;
      case 105:
// 982 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_expr(PHQL_T_ADD, yymsp[-2].minor.yy42, yymsp[0].minor.yy42);
  yy_destructor(14,&yymsp[-1].minor);
}
// 2151 "parser.c"
        break;
      case 106:
// 986 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_expr(PHQL_T_MUL, yymsp[-2].minor.yy42, yymsp[0].minor.yy42);
  yy_destructor(12,&yymsp[-1].minor);
}
// 2159 "parser.c"
        break;
      case 107:
// 990 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_expr(PHQL_T_DIV, yymsp[-2].minor.yy42, yymsp[0].minor.yy42);
  yy_destructor(11,&yymsp[-1].minor);
}
// 2167 "parser.c"
        break;
      case 108:
// 994 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_expr(PHQL_T_MOD, yymsp[-2].minor.yy42, yymsp[0].minor.yy42);
  yy_destructor(13,&yymsp[-1].minor);
}
// 2175 "parser.c"
        break;
      case 109:
// 998 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_expr(PHQL_T_AND, yymsp[-2].minor.yy42, yymsp[0].minor.yy42);
  yy_destructor(8,&yymsp[-1].minor);
}
// 2183 "parser.c"
        break;
      case 110:
// 1002 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_expr(PHQL_T_OR, yymsp[-2].minor.yy42, yymsp[0].minor.yy42);
  yy_destructor(9,&yymsp[-1].minor);
}
// 2191 "parser.c"
        break;
      case 111:
// 1006 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_expr(PHQL_T_EQUALS, yymsp[-2].minor.yy42, yymsp[0].minor.yy42);
  yy_destructor(2,&yymsp[-1].minor);
}
// 2199 "parser.c"
        break;
      case 112:
// 1010 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_expr(PHQL_T_NOTEQUALS, yymsp[-2].minor.yy42, yymsp[0].minor.yy42);
  yy_destructor(3,&yymsp[-1].minor);
}
// 2207 "parser.c"
        break;
      case 113:
// 1014 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_expr(PHQL_T_LESS, yymsp[-2].minor.yy42, yymsp[0].minor.yy42);
  yy_destructor(4,&yymsp[-1].minor);
}
// 2215 "parser.c"
        break;
      case 114:
// 1018 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_expr(PHQL_T_GREATER, yymsp[-2].minor.yy42, yymsp[0].minor.yy42);
  yy_destructor(5,&yymsp[-1].minor);
}
// 2223 "parser.c"
        break;
      case 115:
// 1022 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_expr(PHQL_T_GREATEREQUAL, yymsp[-2].minor.yy42, yymsp[0].minor.yy42);
  yy_destructor(6,&yymsp[-1].minor);
}
// 2231 "parser.c"
        break;
      case 116:
// 1026 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_expr(PHQL_T_LESSEQUAL, yymsp[-2].minor.yy42, yymsp[0].minor.yy42);
  yy_destructor(7,&yymsp[-1].minor);
}
// 2239 "parser.c"
        break;
      case 117:
// 1030 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_expr(PHQL_T_LIKE, yymsp[-2].minor.yy42, yymsp[0].minor.yy42);
  yy_destructor(10,&yymsp[-1].minor);
}
// 2247 "parser.c"
        break;
      case 118:
// 1034 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_expr(PHQL_T_NLIKE, yymsp[-3].minor.yy42, yymsp[0].minor.yy42);
  yy_destructor(19,&yymsp[-2].minor);
  yy_destructor(10,&yymsp[-1].minor);
}
// 2256 "parser.c"
        break;
      case 119:
// 1038 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_expr(PHQL_T_IN, yymsp[-4].minor.yy42, yymsp[-1].minor.yy42);
  yy_destructor(17,&yymsp[-3].minor);
  yy_destructor(37,&yymsp[-2].minor);
  yy_destructor(38,&yymsp[0].minor);
}
// 2266 "parser.c"
        break;
      case 120:
// 1042 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_expr(PHQL_T_NOTIN, yymsp[-5].minor.yy42, yymsp[-1].minor.yy42);
  yy_destructor(19,&yymsp[-4].minor);
  yy_destructor(17,&yymsp[-3].minor);
  yy_destructor(37,&yymsp[-2].minor);
  yy_destructor(38,&yymsp[0].minor);
}
// 2277 "parser.c"
        break;
      case 122:
// 1052 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_func_call(yymsp[-3].minor.yy0, yymsp[-1].minor.yy42);
  yy_destructor(37,&yymsp[-2].minor);
  yy_destructor(38,&yymsp[0].minor);
}
// 2286 "parser.c"
        break;
      case 123:
// 1056 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_func_call(yymsp[-2].minor.yy0, NULL);
  yy_destructor(37,&yymsp[-1].minor);
  yy_destructor(38,&yymsp[0].minor);
}
// 2295 "parser.c"
        break;
      case 125:
// 1066 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_zval_list(yymsp[0].minor.yy42, NULL);
}
// 2302 "parser.c"
        break;
      case 128:
// 1080 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_expr(PHQL_T_ISNULL, yymsp[-2].minor.yy42, NULL);
  yy_destructor(16,&yymsp[-1].minor);
  yy_destructor(52,&yymsp[0].minor);
}
// 2311 "parser.c"
        break;
      case 129:
// 1084 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_expr(PHQL_T_ISNOTNULL, yymsp[-3].minor.yy42, NULL);
  yy_destructor(16,&yymsp[-2].minor);
  yy_destructor(19,&yymsp[-1].minor);
  yy_destructor(52,&yymsp[0].minor);
}
// 2321 "parser.c"
        break;
      case 130:
// 1088 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_expr(PHQL_T_DISTINCT, NULL, yymsp[0].minor.yy42);
  yy_destructor(18,&yymsp[-1].minor);
}
// 2329 "parser.c"
        break;
      case 131:
// 1092 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_expr(PHQL_T_BETWEEN, yymsp[-2].minor.yy42, yymsp[0].minor.yy42);
  yy_destructor(1,&yymsp[-1].minor);
}
// 2337 "parser.c"
        break;
      case 132:
// 1096 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_expr(PHQL_T_NOT, NULL, yymsp[0].minor.yy42);
  yy_destructor(19,&yymsp[-1].minor);
}
// 2345 "parser.c"
        break;
      case 133:
// 1100 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_expr(PHQL_T_ENCLOSED, yymsp[-1].minor.yy42, NULL);
  yy_destructor(37,&yymsp[-2].minor);
  yy_destructor(38,&yymsp[0].minor);
}
// 2354 "parser.c"
        break;
      case 136:
// 1112 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_literal_zval(PHQL_T_STRING, yymsp[0].minor.yy0);
}
// 2361 "parser.c"
        break;
      case 137:
// 1116 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_literal_zval(PHQL_T_DOUBLE, yymsp[0].minor.yy0);
}
// 2368 "parser.c"
        break;
      case 138:
// 1120 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_literal_zval(PHQL_T_NULL, NULL);
  yy_destructor(52,&yymsp[0].minor);
}
// 2376 "parser.c"
        break;
      case 139:
// 1124 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_placeholder_zval(PHQL_T_NPLACEHOLDER, yymsp[0].minor.yy0);
}
// 2383 "parser.c"
        break;
      case 140:
// 1128 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_placeholder_zval(PHQL_T_SPLACEHOLDER, yymsp[0].minor.yy0);
}
// 2390 "parser.c"
        break;
      case 141:
// 1134 "parser.lemon"
{
	yygotominor.yy42 = phql_ret_qualified_name(yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(24,&yymsp[-1].minor);
}
// 2398 "parser.c"
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
// 428 "parser.lemon"

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

// 2490 "parser.c"
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
  { PHQL_T_BETWEEN,       "BETWEEN" },
  { PHQL_T_DISTINCT,      "DISTINCT" },
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
 * Creates an error message when it's triggered by the scanner
 */
static void phql_scanner_error_msg(phql_parser_status *parser_status, zval **error_msg TSRMLS_DC){

	char *error, *error_part;
	phql_scanner_state *state = parser_status->scanner_state;

	PHALCON_INIT_VAR(*error_msg);
	if (state->start) {
		error = emalloc(sizeof(char) * 64 + strlen(state->start));
		if (strlen(state->start) > 16) {
			error_part = estrndup(state->start, 16);
			sprintf(error, "Parsing error before '%s...'", error_part);
			efree(error_part);
		} else {
			sprintf(error, "Parsing error before '%s'", state->start);
		}
		ZVAL_STRING(*error_msg, error, 1);
	} else {
		error = emalloc(sizeof(char) * 32);
		sprintf(error, "Parsing error near to EOF");
		ZVAL_STRING(*error_msg, error, 1);
	}
	efree(error);
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
			case PHQL_T_BETWEEN:
				phql_(phql_parser, PHQL_BETWEEN, NULL, parser_status);
				break;
			case PHQL_T_DISTINCT:
				phql_(phql_parser, PHQL_DISTINCT, NULL, parser_status);
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