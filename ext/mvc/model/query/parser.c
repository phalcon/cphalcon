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


// 411 "parser.c"
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
#define YYNOCODE 108
#define YYACTIONTYPE unsigned short int
#define phql_TOKENTYPE phql_parser_token*
typedef union {
  phql_TOKENTYPE yy0;
  zval* yy180;
  int yy215;
} YYMINORTYPE;
#define YYSTACKDEPTH 100
#define phql_ARG_SDECL phql_parser_status *status;
#define phql_ARG_PDECL ,phql_parser_status *status
#define phql_ARG_FETCH phql_parser_status *status = yypParser->status
#define phql_ARG_STORE yypParser->status = status
#define YYNSTATE 251
#define YYNRULE 149
#define YYERRORSYMBOL 64
#define YYERRSYMDT yy215
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
 /*    40 */    36,   34,   38,   32,   29,   74,   69,  251,   64,   18,
 /*    50 */    27,   28,   20,  203,  137,  201,    9,   72,   78,   50,
 /*    60 */    52,   54,   56,   58,   60,   40,   42,   62,   67,   44,
 /*    70 */    46,   48,   36,   34,   38,   32,   29,   74,   69,  136,
 /*    80 */    64,   32,   29,   74,   69,  145,   64,   83,  147,   72,
 /*    90 */    78,   50,   52,   54,   56,   58,   60,   40,   42,   62,
 /*   100 */    67,   44,   46,   48,   36,   34,   38,   32,   29,   74,
 /*   110 */    69,   11,   64,   40,   42,   62,   67,   44,   46,   48,
 /*   120 */    36,   34,   38,   32,   29,   74,   69,  124,   64,   17,
 /*   130 */   126,  191,  102,  189,   72,   78,   50,   52,   54,   56,
 /*   140 */    58,   60,   40,   42,   62,   67,   44,   46,   48,   36,
 /*   150 */    34,   38,   32,   29,   74,   69,  252,   64,   50,   52,
 /*   160 */    54,   56,   58,   60,   40,   42,   62,   67,   44,   46,
 /*   170 */    48,   36,   34,   38,   32,   29,   74,   69,   93,   64,
 /*   180 */   112,   30,   26,  258,   94,   96,   98,  103,   93,  253,
 /*   190 */    87,   30,   71,   88,   94,   96,   98,  103,  254,  175,
 /*   200 */    87,   23,  123,  176,  100,  110,   86,  401,    1,    2,
 /*   210 */     3,    4,    5,    6,  100,  104,   86,   92,  255,   80,
 /*   220 */   107,  105,  106,  108,  109,  104,  265,   65,  116,   80,
 /*   230 */   107,  105,  106,  108,  109,   13,  227,  196,  118,   10,
 /*   240 */    30,  244,  156,   94,   96,   98,  192,  158,  159,  197,
 /*   250 */    30,   26,   91,   94,   96,   98,  103,  208,  216,   87,
 /*   260 */   186,   91,  261,  100,  169,  170,  172,  174,   90,  178,
 /*   270 */   182,   25,  179,  100,  104,   86,  180,  115,   80,  107,
 /*   280 */   105,  106,  108,  109,  104,  157,  158,  159,   80,  107,
 /*   290 */   105,  106,  108,  109,   62,   67,   44,   46,   48,   36,
 /*   300 */    34,   38,   32,   29,   74,   69,  256,   64,   44,   46,
 /*   310 */    48,   36,   34,   38,   32,   29,   74,   69,   10,   64,
 /*   320 */    36,   34,   38,   32,   29,   74,   69,  135,   64,  169,
 /*   330 */   170,  172,  174,  153,  178,  182,  204,  200,  349,  154,
 /*   340 */   194,   71,  103,  260,  134,   71,  103,  239,   71,   76,
 /*   350 */   103,  257,  214,  103,  150,   21,  259,  103,  238,  130,
 /*   360 */   210,   86,   10,  215,  114,   86,  111,  274,   89,   86,
 /*   370 */   111,  120,   86,  111,  214,  152,   86,  161,  165,  103,
 /*   380 */     8,   16,  221,  129,   75,  215,    7,  139,  141,  205,
 /*   390 */   149,  348,   21,   15,  233,  350,  248,  135,   86,   10,
 /*   400 */    21,  242,  195,  200,  130,   21,  103,   10,  103,   19,
 /*   410 */   214,  127,   10,  132,  138,  103,   21,  273,  241,   12,
 /*   420 */   183,  213,  127,   10,  184,   86,   22,   86,  122,   74,
 /*   430 */    69,  267,   64,  103,   86,   31,   33,   24,   35,   37,
 /*   440 */   103,  103,   39,  103,  103,   41,   43,  103,   14,   45,
 /*   450 */   103,  103,   86,   47,  103,  168,   49,  166,  103,   86,
 /*   460 */    86,  103,   86,   86,  187,  163,   86,   51,  188,   86,
 /*   470 */    86,   53,  103,   86,   55,   64,  103,   86,   57,  103,
 /*   480 */    86,   59,   61,  103,   63,   66,  103,  103,   68,  103,
 /*   490 */   103,   86,   73,  103,   79,   86,  263,  103,   86,  103,
 /*   500 */   276,  142,   86,  144,  148,   86,   86,  318,   86,   86,
 /*   510 */    82,  327,   86,  268,   95,  103,   86,   97,   86,  103,
 /*   520 */    99,  101,  103,  117,  128,  103,  103,  151,  103,  103,
 /*   530 */    91,  155,  103,  269,   86,  193,  270,  164,   86,  188,
 /*   540 */    77,   86,  103,  239,   86,   86,  121,   86,   86,   21,
 /*   550 */   212,   86,   10,  236,  243,  150,   10,  198,  223,  150,
 /*   560 */   199,   86,  217,  230,  228,  226,  211,  230,  212,   10,
 /*   570 */    88,  319,  113,  234,  218,  245,  328,  188,   70,  250,
 /*   580 */    81,   84,   85,  188,  222,  113,  125,  232,  119,   10,
 /*   590 */   262,  266,   10,  264,  131,  133,  112,  140,  247,  271,
 /*   600 */   143,  272,  146,  278,  277,  275,  279,  137,  163,  160,
 /*   610 */   167,  300,  171,  162,  301,  173,  302,  303,  177,  310,
 /*   620 */   206,  304,  311,  305,  306,  207,  307,  230,  181,  308,
 /*   630 */   185,  190,  230,  321,  224,  351,  202,  229,  225,  320,
 /*   640 */   240,  237,  246,  231,  330,  329,  258,  249,  258,  258,
 /*   650 */   258,  209,  219,  258,  220,  258,  258,  258,  235,
};
static YYCODETYPE yy_lookahead[] = {
 /*     0 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    10 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*    20 */    21,   22,   22,   24,   24,    1,    2,    3,    4,    5,
 /*    30 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*    40 */    16,   17,   18,   19,   20,   21,   22,    0,   24,   73,
 /*    50 */    51,   52,   76,   29,   29,   31,   76,    1,    2,    3,
 /*    60 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*    70 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   54,
 /*    80 */    24,   19,   20,   21,   22,   73,   24,   31,   76,    1,
 /*    90 */     2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   100 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   110 */    22,   54,   24,    9,   10,   11,   12,   13,   14,   15,
 /*   120 */    16,   17,   18,   19,   20,   21,   22,   73,   24,   75,
 /*   130 */    76,   29,   44,   31,    1,    2,    3,    4,    5,    6,
 /*   140 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   150 */    17,   18,   19,   20,   21,   22,    0,   24,    3,    4,
 /*   160 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   170 */    15,   16,   17,   18,   19,   20,   21,   22,   17,   24,
 /*   180 */    30,   20,   81,    0,   23,   24,   25,   86,   17,    0,
 /*   190 */    29,   20,   81,   43,   23,   24,   25,   86,    0,   32,
 /*   200 */    29,  100,  101,   36,   43,   44,  105,   65,   66,   67,
 /*   210 */    68,   69,   70,   71,   43,   54,  105,  106,    0,   58,
 /*   220 */    59,   60,   61,   62,   63,   54,    0,   11,   12,   58,
 /*   230 */    59,   60,   61,   62,   63,   54,   94,   17,   22,   56,
 /*   240 */    20,   99,   79,   23,   24,   25,   83,   84,   85,   29,
 /*   250 */    20,   81,   28,   23,   24,   25,   86,   42,   43,   29,
 /*   260 */    28,   28,    0,   43,   32,   33,   34,   35,   44,   37,
 /*   270 */    38,  101,   32,   43,   54,  105,   36,   44,   58,   59,
 /*   280 */    60,   61,   62,   63,   54,   83,   84,   85,   58,   59,
 /*   290 */    60,   61,   62,   63,   11,   12,   13,   14,   15,   16,
 /*   300 */    17,   18,   19,   20,   21,   22,    0,   24,   13,   14,
 /*   310 */    15,   16,   17,   18,   19,   20,   21,   22,   56,   24,
 /*   320 */    16,   17,   18,   19,   20,   21,   22,   86,   24,   32,
 /*   330 */    33,   34,   35,   77,   37,   38,   80,   81,    0,   27,
 /*   340 */    28,   81,   86,    0,  103,   81,   86,   86,   81,   24,
 /*   350 */    86,    0,   81,   86,   48,   49,    0,   86,   97,   53,
 /*   360 */    89,  105,   56,   92,  104,  105,  106,    0,  104,  105,
 /*   370 */   106,  104,  105,  106,   81,   26,  105,   87,   88,   86,
 /*   380 */    73,   74,   89,   76,   59,   92,   72,   73,   74,   40,
 /*   390 */    76,    0,   49,   54,   45,    0,   47,   86,  105,   56,
 /*   400 */    49,   81,   80,   81,   53,   49,   86,   56,   86,   76,
 /*   410 */    81,   55,   56,  102,  103,   86,   49,    0,   98,   28,
 /*   420 */    32,   92,   55,   56,   36,  105,   50,  105,   81,   21,
 /*   430 */    22,    0,   24,   86,  105,   81,   81,   28,   81,   81,
 /*   440 */    86,   86,   81,   86,   86,   81,   81,   86,   57,   81,
 /*   450 */    86,   86,  105,   81,   86,   29,   81,   31,   86,  105,
 /*   460 */   105,   86,  105,  105,   82,   39,  105,   81,   86,  105,
 /*   470 */   105,   81,   86,  105,   81,   24,   86,  105,   81,   86,
 /*   480 */   105,   81,   81,   86,   81,   81,   86,   86,   81,   86,
 /*   490 */    86,  105,   81,   86,   81,  105,    0,   86,  105,   86,
 /*   500 */     0,   73,  105,   75,   76,  105,  105,    0,  105,  105,
 /*   510 */    81,    0,  105,    0,   81,   86,  105,   81,  105,   86,
 /*   520 */    81,   81,   86,   81,   81,   86,   86,   81,   86,   86,
 /*   530 */    28,   78,   86,    0,  105,   82,    0,   81,  105,   86,
 /*   540 */    59,  105,   86,   86,  105,  105,   44,  105,  105,   49,
 /*   550 */    28,  105,   56,   96,   97,   48,   56,   30,   28,   48,
 /*   560 */    17,  105,   90,   56,   72,   93,   44,   56,   28,   56,
 /*   570 */    43,    0,   29,   82,   44,   72,    0,   86,   43,   82,
 /*   580 */    43,   29,   44,   86,   44,   29,   76,   95,   43,   56,
 /*   590 */     0,    0,   56,    0,   50,   28,   30,   76,   95,    0,
 /*   600 */    76,    0,   76,    0,    0,    0,    0,   29,   39,   86,
 /*   610 */    29,   29,   32,   88,   29,   32,   29,   29,   32,    0,
 /*   620 */    41,   29,    0,   29,   29,   86,   29,   56,   32,   29,
 /*   630 */    32,   29,   56,    0,   93,    0,   29,   95,   29,    0,
 /*   640 */     3,   28,   95,   54,    0,    0,  107,   27,  107,  107,
 /*   650 */   107,   43,   42,  107,   43,  107,  107,  107,   46,
};
#define YY_SHIFT_USE_DFLT (-2)
static short yy_shift_ofst[] = {
 /*     0 */   349,   47,  156,  189,  198,  218,  306,  351,  183,  226,
 /*    10 */    57,  391,  181,  338,  339,  395,  356,  343,  496,  417,
 /*    20 */   431,  376,  230,  409,  230,   -2,   -1,   -2,   -2,  230,
 /*    30 */   230,  408,  230,  408,  230,   62,  230,   62,  230,   62,
 /*    40 */   230,  283,  230,  283,  230,  304,  230,  304,  230,  304,
 /*    50 */   230,  104,  230,  104,  230,  104,  230,  104,  230,  104,
 /*    60 */   230,  104,  230,  295,  216,  230,  451,  230,  295,  535,
 /*    70 */   171,  133,  230,  133,  325,   -2,  481,   -2,  230,  155,
 /*    80 */   537,  230,   56,  552,  538,   -2,   -2,  150,  161,  224,
 /*    90 */    -2,  171,   -2,   -2,  230,    0,  230,  451,  230,  451,
 /*   100 */   230,   88,   -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,
 /*   110 */    -2,   -2,  556,   -2,  233,   -2,  230,  451,  545,  171,
 /*   120 */   502,   -2,  408,   -2,  262,  590,  591,  230,  133,  593,
 /*   130 */   544,   25,  567,   25,   -2,   -2,   -2,  566,   -2,  513,
 /*   140 */   599,  367,  533,  601,  500,  536,  603,  604,  605,  606,
 /*   150 */   230,  133,  220,  312,  578,  232,  297,   -2,   -2,  578,
 /*   160 */   426,  569,   -2,  230,  133,   -2,  581,   -2,   -2,  582,
 /*   170 */   580,  585,  583,  587,  167,  588,  586,  592,  240,  594,
 /*   180 */   596,  595,  388,  597,  598,  600,  578,   -2,  102,  602,
 /*   190 */    -2,   -2,   -2,   -2,  220,   -2,   -2,  527,  543,   -2,
 /*   200 */    24,  607,   -2,   -2,   -2,  579,  578,  215,  608,  230,
 /*   210 */   522,  619,  230,   -2,  133,   -2,  609,  530,  610,  611,
 /*   220 */   230,  540,  622,  609,   -2,   -2,   -2,  507,  571,  633,
 /*   230 */   589,  635,  639,  578,  612,  578,  613,  578,   -2,  637,
 /*   240 */   230,   -2,  133,   -2,  511,  576,  644,  645,  620,  578,
 /*   250 */    -2,
};
#define YY_REDUCE_USE_DFLT (-25)
static short yy_reduce_ofst[] = {
 /*     0 */   142,  -25,  -25,  -25,  -25,  -25,  314,  307,  -20,  -25,
 /*    10 */   -25,  -25,  -25,  -25,  -25,  -25,   54,  -24,  333,  -25,
 /*    20 */   -25,  -25,  101,  -25,  170,  -25,  -25,  -25,  -25,  347,
 /*    30 */   354,  -25,  355,  -25,  357,  -25,  358,  -25,  361,  -25,
 /*    40 */   364,  -25,  365,  -25,  368,  -25,  372,  -25,  375,  -25,
 /*    50 */   386,  -25,  390,  -25,  393,  -25,  397,  -25,  400,  -25,
 /*    60 */   401,  -25,  403,  -25,  -25,  404,  -25,  407,  -25,  -25,
 /*    70 */   260,  -25,  411,  -25,  -25,  -25,  -25,  -25,  413,  -25,
 /*    80 */   -25,  429,  -25,  -25,  -25,  -25,  -25,  -25,  264,  -25,
 /*    90 */   -25,  111,  -25,  -25,  433,  -25,  436,  -25,  439,  -25,
 /*   100 */   440,  -25,  -25,  -25,  -25,  -25,  -25,  -25,  -25,  -25,
 /*   110 */   -25,  -25,  -25,  -25,  -25,  -25,  442,  -25,  -25,  267,
 /*   120 */   -25,  -25,  -25,  -25,  510,  -25,  -25,  443,  -25,  -25,
 /*   130 */   -25,  311,  -25,  241,  -25,  -25,  -25,  -25,  -25,  521,
 /*   140 */   -25,  428,  524,  -25,   12,  526,  -25,  -25,  -25,  -25,
 /*   150 */   446,  -25,  256,  -25,  453,  163,  202,  -25,  -25,  523,
 /*   160 */   290,  525,  -25,  456,  -25,  -25,  -25,  -25,  -25,  -25,
 /*   170 */   -25,  -25,  -25,  -25,  -25,  -25,  -25,  -25,  -25,  -25,
 /*   180 */   -25,  -25,  -25,  -25,  -25,  -25,  382,  -25,  -25,  -25,
 /*   190 */   -25,  -25,  -25,  -25,  322,  -25,  -25,  -25,  -25,  -25,
 /*   200 */   -25,  -25,  -25,  -25,  -25,  -25,  539,  -25,  -25,  271,
 /*   210 */   -25,  -25,  329,  -25,  -25,  -25,  472,  -25,  -25,  -25,
 /*   220 */   293,  -25,  -25,  541,  -25,  -25,  -25,  492,  542,  -25,
 /*   230 */   -25,  -25,  -25,  491,  -25,  457,  -25,  261,  -25,  -25,
 /*   240 */   320,  -25,  -25,  -25,  503,  547,  -25,  -25,  -25,  497,
 /*   250 */   -25,
};
static YYACTIONTYPE yy_default[] = {
 /*     0 */   400,  400,  400,  400,  400,  400,  400,  400,  400,  400,
 /*    10 */   400,  400,  400,  400,  400,  400,  400,  400,  400,  400,
 /*    20 */   400,  400,  400,  336,  400,  337,  339,  340,  341,  400,
 /*    30 */   400,  352,  400,  354,  400,  355,  400,  356,  400,  357,
 /*    40 */   400,  358,  400,  359,  400,  360,  400,  361,  400,  362,
 /*    50 */   400,  363,  400,  364,  400,  365,  400,  366,  400,  367,
 /*    60 */   400,  368,  400,  369,  400,  400,  370,  400,  371,  400,
 /*    70 */   400,  383,  400,  375,  400,  384,  400,  385,  400,  387,
 /*    80 */   400,  400,  400,  400,  400,  376,  377,  399,  400,  400,
 /*    90 */   378,  400,  380,  382,  400,  386,  400,  388,  400,  389,
 /*   100 */   400,  400,  390,  391,  392,  393,  394,  395,  396,  397,
 /*   110 */   379,  381,  400,  398,  400,  373,  400,  372,  400,  400,
 /*   120 */   400,  374,  353,  338,  400,  400,  400,  400,  347,  400,
 /*   130 */   400,  400,  342,  400,  343,  345,  346,  399,  344,  400,
 /*   140 */   400,  400,  400,  400,  400,  400,  400,  400,  400,  400,
 /*   150 */   400,  335,  400,  400,  400,  280,  281,  291,  293,  400,
 /*   160 */   294,  295,  297,  400,  309,  296,  400,  298,  299,  400,
 /*   170 */   400,  400,  400,  400,  400,  400,  400,  400,  400,  400,
 /*   180 */   400,  400,  400,  400,  400,  400,  400,  289,  334,  400,
 /*   190 */   332,  333,  292,  290,  400,  282,  284,  399,  400,  285,
 /*   200 */   288,  400,  286,  287,  283,  400,  400,  400,  400,  400,
 /*   210 */   400,  400,  400,  312,  314,  313,  400,  400,  400,  400,
 /*   220 */   400,  400,  400,  400,  315,  317,  316,  400,  400,  400,
 /*   230 */   400,  400,  400,  400,  400,  400,  322,  400,  323,  400,
 /*   240 */   400,  325,  326,  324,  400,  400,  400,  400,  400,  400,
 /*   250 */   331,
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
  "DESC",          "GROUP",         "INTEGER",       "HAVING",      
  "LIMIT",         "OFFSET",        "CAST",          "NULL",        
  "STRING",        "DOUBLE",        "NPLACEHOLDER",  "SPLACEHOLDER",
  "error",         "program",       "query_language",  "select_statement",
  "insert_statement",  "update_statement",  "delete_statement",  "select_clause",
  "where_clause",  "order_clause",  "group_clause",  "having_clause",
  "select_limit_clause",  "column_list",   "associated_name_list",  "join_list",   
  "column_item",   "expr",          "associated_name",  "join_item",   
  "join_clause",   "join_type",     "qualified_name",  "join_associated_name",
  "join_conditions",  "values_list",   "field_list",    "value_list",  
  "value_item",    "field_item",    "update_clause",  "limit_clause",
  "update_item_list",  "update_item",   "new_value",     "delete_clause",
  "order_list",    "order_item",    "group_list",    "group_item",  
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
 /*  59 */ "insert_statement ::= INSERT INTO qualified_name VALUES PARENTHESES_OPEN values_list PARENTHESES_CLOSE",
 /*  60 */ "insert_statement ::= INSERT INTO qualified_name PARENTHESES_OPEN field_list PARENTHESES_CLOSE VALUES PARENTHESES_OPEN values_list PARENTHESES_CLOSE",
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
 /* 111 */ "expr ::= expr BITWISE_XOR expr",
 /* 112 */ "expr ::= expr EQUALS expr",
 /* 113 */ "expr ::= expr NOTEQUALS expr",
 /* 114 */ "expr ::= expr LESS expr",
 /* 115 */ "expr ::= expr GREATER expr",
 /* 116 */ "expr ::= expr GREATEREQUAL expr",
 /* 117 */ "expr ::= expr LESSEQUAL expr",
 /* 118 */ "expr ::= expr LIKE expr",
 /* 119 */ "expr ::= expr NOT LIKE expr",
 /* 120 */ "expr ::= expr ILIKE expr",
 /* 121 */ "expr ::= expr NOT ILIKE expr",
 /* 122 */ "expr ::= expr IN PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 123 */ "expr ::= expr NOT IN PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 124 */ "expr ::= expr AGAINST expr",
 /* 125 */ "expr ::= CAST PARENTHESES_OPEN expr AS IDENTIFIER PARENTHESES_CLOSE",
 /* 126 */ "expr ::= function_call",
 /* 127 */ "function_call ::= IDENTIFIER PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 128 */ "function_call ::= IDENTIFIER PARENTHESES_OPEN PARENTHESES_CLOSE",
 /* 129 */ "argument_list ::= argument_list COMMA argument_item",
 /* 130 */ "argument_list ::= argument_item",
 /* 131 */ "argument_item ::= TIMES",
 /* 132 */ "argument_item ::= expr",
 /* 133 */ "expr ::= expr IS NULL",
 /* 134 */ "expr ::= expr IS NOT NULL",
 /* 135 */ "expr ::= DISTINCT expr",
 /* 136 */ "expr ::= expr BETWEEN expr",
 /* 137 */ "expr ::= NOT expr",
 /* 138 */ "expr ::= BITWISE_NOT expr",
 /* 139 */ "expr ::= PARENTHESES_OPEN expr PARENTHESES_CLOSE",
 /* 140 */ "expr ::= qualified_name",
 /* 141 */ "expr ::= INTEGER",
 /* 142 */ "expr ::= STRING",
 /* 143 */ "expr ::= DOUBLE",
 /* 144 */ "expr ::= NULL",
 /* 145 */ "expr ::= NPLACEHOLDER",
 /* 146 */ "expr ::= SPLACEHOLDER",
 /* 147 */ "qualified_name ::= IDENTIFIER DOT IDENTIFIER",
 /* 148 */ "qualified_name ::= IDENTIFIER",
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
// 508 "parser.lemon"
{
	if ((yypminor->yy0)) {
		if ((yypminor->yy0)->free_flag) {
			efree((yypminor->yy0)->token);
		}
		efree((yypminor->yy0));
	}
}
// 1147 "parser.c"
      break;
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
    case 86:
    case 87:
    case 88:
    case 90:
    case 91:
    case 93:
    case 94:
    case 95:
    case 96:
    case 97:
    case 99:
    case 100:
    case 101:
    case 102:
    case 103:
    case 104:
    case 105:
    case 106:
// 521 "parser.lemon"
{ zval_ptr_dtor(&(yypminor->yy180)); }
// 1189 "parser.c"
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
  { 65, 1 },
  { 66, 1 },
  { 66, 1 },
  { 66, 1 },
  { 66, 1 },
  { 67, 1 },
  { 67, 2 },
  { 67, 3 },
  { 67, 3 },
  { 67, 4 },
  { 67, 4 },
  { 67, 5 },
  { 67, 5 },
  { 67, 3 },
  { 67, 4 },
  { 67, 4 },
  { 67, 5 },
  { 67, 2 },
  { 67, 3 },
  { 67, 4 },
  { 67, 3 },
  { 67, 4 },
  { 67, 6 },
  { 67, 2 },
  { 67, 3 },
  { 67, 3 },
  { 67, 4 },
  { 67, 5 },
  { 67, 2 },
  { 71, 4 },
  { 71, 5 },
  { 77, 3 },
  { 77, 1 },
  { 80, 1 },
  { 80, 3 },
  { 80, 3 },
  { 80, 2 },
  { 80, 1 },
  { 78, 3 },
  { 78, 1 },
  { 79, 2 },
  { 79, 1 },
  { 83, 1 },
  { 84, 2 },
  { 84, 3 },
  { 84, 3 },
  { 84, 4 },
  { 87, 2 },
  { 87, 1 },
  { 85, 1 },
  { 85, 2 },
  { 85, 2 },
  { 85, 2 },
  { 85, 3 },
  { 85, 2 },
  { 85, 3 },
  { 85, 2 },
  { 85, 3 },
  { 88, 2 },
  { 68, 7 },
  { 68, 10 },
  { 89, 3 },
  { 89, 1 },
  { 92, 1 },
  { 90, 3 },
  { 90, 1 },
  { 93, 1 },
  { 69, 1 },
  { 69, 2 },
  { 69, 2 },
  { 69, 3 },
  { 94, 4 },
  { 96, 3 },
  { 96, 1 },
  { 97, 3 },
  { 98, 1 },
  { 70, 1 },
  { 70, 2 },
  { 70, 2 },
  { 70, 3 },
  { 99, 3 },
  { 82, 3 },
  { 82, 2 },
  { 82, 1 },
  { 72, 2 },
  { 73, 3 },
  { 100, 3 },
  { 100, 1 },
  { 101, 1 },
  { 101, 2 },
  { 101, 2 },
  { 74, 3 },
  { 102, 3 },
  { 102, 1 },
  { 103, 1 },
  { 103, 1 },
  { 75, 2 },
  { 76, 2 },
  { 76, 4 },
  { 76, 4 },
  { 95, 2 },
  { 81, 2 },
  { 81, 3 },
  { 81, 3 },
  { 81, 3 },
  { 81, 3 },
  { 81, 3 },
  { 81, 3 },
  { 81, 3 },
  { 81, 3 },
  { 81, 3 },
  { 81, 3 },
  { 81, 3 },
  { 81, 3 },
  { 81, 3 },
  { 81, 3 },
  { 81, 3 },
  { 81, 3 },
  { 81, 3 },
  { 81, 4 },
  { 81, 3 },
  { 81, 4 },
  { 81, 5 },
  { 81, 6 },
  { 81, 3 },
  { 81, 6 },
  { 81, 1 },
  { 105, 4 },
  { 105, 3 },
  { 104, 3 },
  { 104, 1 },
  { 106, 1 },
  { 106, 1 },
  { 81, 3 },
  { 81, 4 },
  { 81, 2 },
  { 81, 3 },
  { 81, 2 },
  { 81, 2 },
  { 81, 3 },
  { 81, 1 },
  { 81, 1 },
  { 81, 1 },
  { 81, 1 },
  { 81, 1 },
  { 81, 1 },
  { 81, 1 },
  { 86, 3 },
  { 86, 1 },
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
// 517 "parser.lemon"
{
	status->ret = yymsp[0].minor.yy180;
}
// 1555 "parser.c"
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
      case 126:
      case 132:
      case 140:
// 523 "parser.lemon"
{
	yygotominor.yy180 = yymsp[0].minor.yy180;
}
// 1580 "parser.c"
        break;
      case 5:
// 541 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_select_statement(yymsp[0].minor.yy180, NULL, NULL, NULL, NULL, NULL);
}
// 1587 "parser.c"
        break;
      case 6:
// 545 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_select_statement(yymsp[-1].minor.yy180, yymsp[0].minor.yy180, NULL, NULL, NULL, NULL);
}
// 1594 "parser.c"
        break;
      case 7:
// 549 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_select_statement(yymsp[-2].minor.yy180, yymsp[-1].minor.yy180, yymsp[0].minor.yy180, NULL, NULL, NULL);
}
// 1601 "parser.c"
        break;
      case 8:
// 553 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_select_statement(yymsp[-2].minor.yy180, yymsp[-1].minor.yy180, NULL, yymsp[0].minor.yy180, NULL, NULL);
}
// 1608 "parser.c"
        break;
      case 9:
// 557 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_select_statement(yymsp[-3].minor.yy180, yymsp[-2].minor.yy180, NULL, yymsp[-1].minor.yy180, yymsp[0].minor.yy180, NULL);
}
// 1615 "parser.c"
        break;
      case 10:
// 561 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_select_statement(yymsp[-3].minor.yy180, yymsp[-2].minor.yy180, yymsp[0].minor.yy180, yymsp[-1].minor.yy180, NULL, NULL);
}
// 1622 "parser.c"
        break;
      case 11:
// 565 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_select_statement(yymsp[-4].minor.yy180, yymsp[-3].minor.yy180, yymsp[-1].minor.yy180, yymsp[-2].minor.yy180, NULL, yymsp[0].minor.yy180);
}
// 1629 "parser.c"
        break;
      case 12:
// 569 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_select_statement(yymsp[-4].minor.yy180, yymsp[-3].minor.yy180, yymsp[0].minor.yy180, yymsp[-2].minor.yy180, yymsp[-1].minor.yy180, NULL);
}
// 1636 "parser.c"
        break;
      case 13:
// 573 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_select_statement(yymsp[-2].minor.yy180, yymsp[-1].minor.yy180, NULL, NULL, NULL, yymsp[0].minor.yy180);
}
// 1643 "parser.c"
        break;
      case 14:
// 577 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_select_statement(yymsp[-3].minor.yy180, yymsp[-2].minor.yy180, yymsp[-1].minor.yy180, NULL, NULL, yymsp[0].minor.yy180);
}
// 1650 "parser.c"
        break;
      case 15:
// 581 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_select_statement(yymsp[-3].minor.yy180, yymsp[-2].minor.yy180, NULL, yymsp[-1].minor.yy180, NULL, yymsp[0].minor.yy180);
}
// 1657 "parser.c"
        break;
      case 16:
// 585 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_select_statement(yymsp[-4].minor.yy180, yymsp[-3].minor.yy180, NULL, yymsp[-2].minor.yy180, yymsp[-1].minor.yy180, yymsp[0].minor.yy180);
}
// 1664 "parser.c"
        break;
      case 17:
// 589 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_select_statement(yymsp[-1].minor.yy180, NULL, yymsp[0].minor.yy180, NULL, NULL, NULL);
}
// 1671 "parser.c"
        break;
      case 18:
// 593 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_select_statement(yymsp[-2].minor.yy180, NULL, yymsp[0].minor.yy180, yymsp[-1].minor.yy180, NULL, NULL);
}
// 1678 "parser.c"
        break;
      case 19:
// 597 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_select_statement(yymsp[-3].minor.yy180, NULL, yymsp[0].minor.yy180, yymsp[-2].minor.yy180, yymsp[-1].minor.yy180, NULL);
}
// 1685 "parser.c"
        break;
      case 20:
// 601 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_select_statement(yymsp[-2].minor.yy180, NULL, yymsp[-1].minor.yy180, NULL, NULL, yymsp[0].minor.yy180);
}
// 1692 "parser.c"
        break;
      case 21:
// 605 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_select_statement(yymsp[-3].minor.yy180, NULL, yymsp[-1].minor.yy180, yymsp[-2].minor.yy180, NULL, yymsp[0].minor.yy180);
}
// 1699 "parser.c"
        break;
      case 22:
// 609 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_select_statement(yymsp[-5].minor.yy180, yymsp[-4].minor.yy180, yymsp[-1].minor.yy180, yymsp[-3].minor.yy180, yymsp[-2].minor.yy180, yymsp[0].minor.yy180);
}
// 1706 "parser.c"
        break;
      case 23:
// 613 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_select_statement(yymsp[-1].minor.yy180, NULL, NULL, yymsp[0].minor.yy180, NULL, NULL);
}
// 1713 "parser.c"
        break;
      case 24:
// 617 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_select_statement(yymsp[-2].minor.yy180, NULL, NULL, yymsp[-1].minor.yy180, NULL, yymsp[0].minor.yy180);
}
// 1720 "parser.c"
        break;
      case 25:
// 621 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_select_statement(yymsp[-2].minor.yy180, NULL, NULL, yymsp[-1].minor.yy180, yymsp[0].minor.yy180, NULL);
}
// 1727 "parser.c"
        break;
      case 26:
// 625 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_select_statement(yymsp[-3].minor.yy180, NULL, NULL, yymsp[-2].minor.yy180, yymsp[-1].minor.yy180, yymsp[0].minor.yy180);
}
// 1734 "parser.c"
        break;
      case 27:
// 629 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_select_statement(yymsp[-4].minor.yy180, NULL, yymsp[-1].minor.yy180, yymsp[-3].minor.yy180, yymsp[-2].minor.yy180, yymsp[0].minor.yy180);
}
// 1741 "parser.c"
        break;
      case 28:
// 633 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_select_statement(yymsp[-1].minor.yy180, NULL, NULL, NULL, NULL, yymsp[0].minor.yy180);
}
// 1748 "parser.c"
        break;
      case 29:
// 639 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_select_clause(yymsp[-2].minor.yy180, yymsp[0].minor.yy180, NULL);
  yy_destructor(26,&yymsp[-3].minor);
  yy_destructor(27,&yymsp[-1].minor);
}
// 1757 "parser.c"
        break;
      case 30:
// 643 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_select_clause(yymsp[-3].minor.yy180, yymsp[-1].minor.yy180, yymsp[0].minor.yy180);
  yy_destructor(26,&yymsp[-4].minor);
  yy_destructor(27,&yymsp[-2].minor);
}
// 1766 "parser.c"
        break;
      case 31:
      case 38:
      case 61:
      case 64:
      case 72:
      case 86:
      case 92:
      case 129:
// 649 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_zval_list(yymsp[-2].minor.yy180, yymsp[0].minor.yy180);
  yy_destructor(28,&yymsp[-1].minor);
}
// 1781 "parser.c"
        break;
      case 33:
      case 131:
// 659 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_column_item(PHQL_T_ALL, NULL, NULL, NULL);
  yy_destructor(17,&yymsp[0].minor);
}
// 1790 "parser.c"
        break;
      case 34:
// 663 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_column_item(PHQL_T_DOMAINALL, NULL, yymsp[-2].minor.yy0, NULL);
  yy_destructor(30,&yymsp[-1].minor);
  yy_destructor(17,&yymsp[0].minor);
}
// 1799 "parser.c"
        break;
      case 35:
// 667 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-2].minor.yy180, NULL, yymsp[0].minor.yy0);
  yy_destructor(31,&yymsp[-1].minor);
}
// 1807 "parser.c"
        break;
      case 36:
// 671 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-1].minor.yy180, NULL, yymsp[0].minor.yy0);
}
// 1814 "parser.c"
        break;
      case 37:
// 675 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_column_item(PHQL_T_EXPR, yymsp[0].minor.yy180, NULL, NULL);
}
// 1821 "parser.c"
        break;
      case 40:
// 691 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_zval_list(yymsp[-1].minor.yy180, yymsp[0].minor.yy180);
}
// 1828 "parser.c"
        break;
      case 43:
// 708 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_join_item(yymsp[-1].minor.yy180, yymsp[0].minor.yy180, NULL, NULL);
}
// 1835 "parser.c"
        break;
      case 44:
// 713 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_join_item(yymsp[-2].minor.yy180, yymsp[-1].minor.yy180, yymsp[0].minor.yy180, NULL);
}
// 1842 "parser.c"
        break;
      case 45:
// 718 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_join_item(yymsp[-2].minor.yy180, yymsp[-1].minor.yy180, NULL, yymsp[0].minor.yy180);
}
// 1849 "parser.c"
        break;
      case 46:
// 723 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_join_item(yymsp[-3].minor.yy180, yymsp[-2].minor.yy180, yymsp[-1].minor.yy180, yymsp[0].minor.yy180);
}
// 1856 "parser.c"
        break;
      case 47:
// 729 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_qualified_name(yymsp[0].minor.yy0, NULL);
  yy_destructor(31,&yymsp[-1].minor);
}
// 1864 "parser.c"
        break;
      case 48:
      case 66:
      case 148:
// 733 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_qualified_name(yymsp[0].minor.yy0, NULL);
}
// 1873 "parser.c"
        break;
      case 49:
// 739 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_join_type(PHQL_T_INNERJOIN);
  yy_destructor(32,&yymsp[0].minor);
}
// 1881 "parser.c"
        break;
      case 50:
// 743 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_join_type(PHQL_T_INNERJOIN);
  yy_destructor(33,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 1890 "parser.c"
        break;
      case 51:
// 747 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_join_type(PHQL_T_CROSSJOIN);
  yy_destructor(34,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 1899 "parser.c"
        break;
      case 52:
// 751 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  yy_destructor(35,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 1908 "parser.c"
        break;
      case 53:
// 755 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 1918 "parser.c"
        break;
      case 54:
// 759 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  yy_destructor(37,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 1927 "parser.c"
        break;
      case 55:
// 763 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  yy_destructor(37,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 1937 "parser.c"
        break;
      case 56:
// 767 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_join_type(PHQL_T_FULLJOIN);
  yy_destructor(38,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 1946 "parser.c"
        break;
      case 57:
// 771 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_join_type(PHQL_T_FULLJOIN);
  yy_destructor(38,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 1956 "parser.c"
        break;
      case 58:
// 777 "parser.lemon"
{
	yygotominor.yy180 = yymsp[0].minor.yy180;
  yy_destructor(39,&yymsp[-1].minor);
}
// 1964 "parser.c"
        break;
      case 59:
// 784 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_insert_statement(yymsp[-4].minor.yy180, NULL, yymsp[-1].minor.yy180);
  yy_destructor(40,&yymsp[-6].minor);
  yy_destructor(41,&yymsp[-5].minor);
  yy_destructor(42,&yymsp[-3].minor);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 1976 "parser.c"
        break;
      case 60:
// 788 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_insert_statement(yymsp[-7].minor.yy180, yymsp[-5].minor.yy180, yymsp[-1].minor.yy180);
  yy_destructor(40,&yymsp[-9].minor);
  yy_destructor(41,&yymsp[-8].minor);
  yy_destructor(43,&yymsp[-6].minor);
  yy_destructor(44,&yymsp[-4].minor);
  yy_destructor(42,&yymsp[-3].minor);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 1990 "parser.c"
        break;
      case 67:
// 826 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_update_statement(yymsp[0].minor.yy180, NULL, NULL);
}
// 1997 "parser.c"
        break;
      case 68:
// 830 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_update_statement(yymsp[-1].minor.yy180, yymsp[0].minor.yy180, NULL);
}
// 2004 "parser.c"
        break;
      case 69:
// 834 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_update_statement(yymsp[-1].minor.yy180, NULL, yymsp[0].minor.yy180);
}
// 2011 "parser.c"
        break;
      case 70:
// 838 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_update_statement(yymsp[-2].minor.yy180, yymsp[-1].minor.yy180, yymsp[0].minor.yy180);
}
// 2018 "parser.c"
        break;
      case 71:
// 844 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_update_clause(yymsp[-2].minor.yy180, yymsp[0].minor.yy180);
  yy_destructor(45,&yymsp[-3].minor);
  yy_destructor(46,&yymsp[-1].minor);
}
// 2027 "parser.c"
        break;
      case 74:
// 860 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_update_item(yymsp[-2].minor.yy180, yymsp[0].minor.yy180);
  yy_destructor(3,&yymsp[-1].minor);
}
// 2035 "parser.c"
        break;
      case 76:
// 872 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_delete_statement(yymsp[0].minor.yy180, NULL, NULL);
}
// 2042 "parser.c"
        break;
      case 77:
// 876 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_delete_statement(yymsp[-1].minor.yy180, yymsp[0].minor.yy180, NULL);
}
// 2049 "parser.c"
        break;
      case 78:
// 880 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_delete_statement(yymsp[-1].minor.yy180, NULL, yymsp[0].minor.yy180);
}
// 2056 "parser.c"
        break;
      case 79:
// 884 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_delete_statement(yymsp[-2].minor.yy180, yymsp[-1].minor.yy180, yymsp[0].minor.yy180);
}
// 2063 "parser.c"
        break;
      case 80:
// 890 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_delete_clause(yymsp[0].minor.yy180);
  yy_destructor(47,&yymsp[-2].minor);
  yy_destructor(27,&yymsp[-1].minor);
}
// 2072 "parser.c"
        break;
      case 81:
// 896 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_assoc_name(yymsp[-2].minor.yy180, yymsp[0].minor.yy0);
  yy_destructor(31,&yymsp[-1].minor);
}
// 2080 "parser.c"
        break;
      case 82:
// 900 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_assoc_name(yymsp[-1].minor.yy180, yymsp[0].minor.yy0);
}
// 2087 "parser.c"
        break;
      case 83:
// 904 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_assoc_name(yymsp[0].minor.yy180, NULL);
}
// 2094 "parser.c"
        break;
      case 84:
// 910 "parser.lemon"
{
	yygotominor.yy180 = yymsp[0].minor.yy180;
  yy_destructor(48,&yymsp[-1].minor);
}
// 2102 "parser.c"
        break;
      case 85:
// 916 "parser.lemon"
{
	yygotominor.yy180 = yymsp[0].minor.yy180;
  yy_destructor(49,&yymsp[-2].minor);
  yy_destructor(50,&yymsp[-1].minor);
}
// 2111 "parser.c"
        break;
      case 88:
// 932 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_order_item(yymsp[0].minor.yy180, 0);
}
// 2118 "parser.c"
        break;
      case 89:
// 936 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_order_item(yymsp[-1].minor.yy180, PHQL_T_ASC);
  yy_destructor(51,&yymsp[0].minor);
}
// 2126 "parser.c"
        break;
      case 90:
// 940 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_order_item(yymsp[-1].minor.yy180, PHQL_T_DESC);
  yy_destructor(52,&yymsp[0].minor);
}
// 2134 "parser.c"
        break;
      case 91:
// 946 "parser.lemon"
{
	yygotominor.yy180 = yymsp[0].minor.yy180;
  yy_destructor(53,&yymsp[-2].minor);
  yy_destructor(50,&yymsp[-1].minor);
}
// 2143 "parser.c"
        break;
      case 95:
      case 141:
// 966 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_literal_zval(PHQL_T_INTEGER, yymsp[0].minor.yy0);
}
// 2151 "parser.c"
        break;
      case 96:
// 972 "parser.lemon"
{
	yygotominor.yy180 = yymsp[0].minor.yy180;
  yy_destructor(55,&yymsp[-1].minor);
}
// 2159 "parser.c"
        break;
      case 97:
      case 100:
// 978 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_limit_clause(yymsp[0].minor.yy0, NULL);
  yy_destructor(56,&yymsp[-1].minor);
}
// 2168 "parser.c"
        break;
      case 98:
// 982 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_limit_clause(yymsp[0].minor.yy0, yymsp[-2].minor.yy0);
  yy_destructor(56,&yymsp[-3].minor);
  yy_destructor(28,&yymsp[-1].minor);
}
// 2177 "parser.c"
        break;
      case 99:
// 986 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_limit_clause(yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(56,&yymsp[-3].minor);
  yy_destructor(57,&yymsp[-1].minor);
}
// 2186 "parser.c"
        break;
      case 101:
// 998 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_expr(PHQL_T_MINUS, NULL, yymsp[0].minor.yy180);
  yy_destructor(20,&yymsp[-1].minor);
}
// 2194 "parser.c"
        break;
      case 102:
// 1002 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_expr(PHQL_T_SUB, yymsp[-2].minor.yy180, yymsp[0].minor.yy180);
  yy_destructor(20,&yymsp[-1].minor);
}
// 2202 "parser.c"
        break;
      case 103:
// 1006 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_expr(PHQL_T_ADD, yymsp[-2].minor.yy180, yymsp[0].minor.yy180);
  yy_destructor(19,&yymsp[-1].minor);
}
// 2210 "parser.c"
        break;
      case 104:
// 1010 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_expr(PHQL_T_MUL, yymsp[-2].minor.yy180, yymsp[0].minor.yy180);
  yy_destructor(17,&yymsp[-1].minor);
}
// 2218 "parser.c"
        break;
      case 105:
// 1014 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_expr(PHQL_T_DIV, yymsp[-2].minor.yy180, yymsp[0].minor.yy180);
  yy_destructor(16,&yymsp[-1].minor);
}
// 2226 "parser.c"
        break;
      case 106:
// 1018 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_expr(PHQL_T_MOD, yymsp[-2].minor.yy180, yymsp[0].minor.yy180);
  yy_destructor(18,&yymsp[-1].minor);
}
// 2234 "parser.c"
        break;
      case 107:
// 1022 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_expr(PHQL_T_AND, yymsp[-2].minor.yy180, yymsp[0].minor.yy180);
  yy_destructor(9,&yymsp[-1].minor);
}
// 2242 "parser.c"
        break;
      case 108:
// 1026 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_expr(PHQL_T_OR, yymsp[-2].minor.yy180, yymsp[0].minor.yy180);
  yy_destructor(10,&yymsp[-1].minor);
}
// 2250 "parser.c"
        break;
      case 109:
// 1030 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_expr(PHQL_T_BITWISE_AND, yymsp[-2].minor.yy180, yymsp[0].minor.yy180);
  yy_destructor(13,&yymsp[-1].minor);
}
// 2258 "parser.c"
        break;
      case 110:
// 1034 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_expr(PHQL_T_BITWISE_OR, yymsp[-2].minor.yy180, yymsp[0].minor.yy180);
  yy_destructor(14,&yymsp[-1].minor);
}
// 2266 "parser.c"
        break;
      case 111:
// 1038 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_expr(PHQL_T_BITWISE_XOR, yymsp[-2].minor.yy180, yymsp[0].minor.yy180);
  yy_destructor(15,&yymsp[-1].minor);
}
// 2274 "parser.c"
        break;
      case 112:
// 1042 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_expr(PHQL_T_EQUALS, yymsp[-2].minor.yy180, yymsp[0].minor.yy180);
  yy_destructor(3,&yymsp[-1].minor);
}
// 2282 "parser.c"
        break;
      case 113:
// 1046 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_expr(PHQL_T_NOTEQUALS, yymsp[-2].minor.yy180, yymsp[0].minor.yy180);
  yy_destructor(4,&yymsp[-1].minor);
}
// 2290 "parser.c"
        break;
      case 114:
// 1050 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_expr(PHQL_T_LESS, yymsp[-2].minor.yy180, yymsp[0].minor.yy180);
  yy_destructor(5,&yymsp[-1].minor);
}
// 2298 "parser.c"
        break;
      case 115:
// 1054 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_expr(PHQL_T_GREATER, yymsp[-2].minor.yy180, yymsp[0].minor.yy180);
  yy_destructor(6,&yymsp[-1].minor);
}
// 2306 "parser.c"
        break;
      case 116:
// 1058 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_expr(PHQL_T_GREATEREQUAL, yymsp[-2].minor.yy180, yymsp[0].minor.yy180);
  yy_destructor(7,&yymsp[-1].minor);
}
// 2314 "parser.c"
        break;
      case 117:
// 1062 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_expr(PHQL_T_LESSEQUAL, yymsp[-2].minor.yy180, yymsp[0].minor.yy180);
  yy_destructor(8,&yymsp[-1].minor);
}
// 2322 "parser.c"
        break;
      case 118:
// 1066 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_expr(PHQL_T_LIKE, yymsp[-2].minor.yy180, yymsp[0].minor.yy180);
  yy_destructor(11,&yymsp[-1].minor);
}
// 2330 "parser.c"
        break;
      case 119:
// 1070 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_expr(PHQL_T_NLIKE, yymsp[-3].minor.yy180, yymsp[0].minor.yy180);
  yy_destructor(24,&yymsp[-2].minor);
  yy_destructor(11,&yymsp[-1].minor);
}
// 2339 "parser.c"
        break;
      case 120:
// 1074 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_expr(PHQL_T_ILIKE, yymsp[-2].minor.yy180, yymsp[0].minor.yy180);
  yy_destructor(12,&yymsp[-1].minor);
}
// 2347 "parser.c"
        break;
      case 121:
// 1078 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_expr(PHQL_T_NILIKE, yymsp[-3].minor.yy180, yymsp[0].minor.yy180);
  yy_destructor(24,&yymsp[-2].minor);
  yy_destructor(12,&yymsp[-1].minor);
}
// 2356 "parser.c"
        break;
      case 122:
// 1082 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_expr(PHQL_T_IN, yymsp[-4].minor.yy180, yymsp[-1].minor.yy180);
  yy_destructor(22,&yymsp[-3].minor);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2366 "parser.c"
        break;
      case 123:
// 1086 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_expr(PHQL_T_NOTIN, yymsp[-5].minor.yy180, yymsp[-1].minor.yy180);
  yy_destructor(24,&yymsp[-4].minor);
  yy_destructor(22,&yymsp[-3].minor);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2377 "parser.c"
        break;
      case 124:
// 1090 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_expr(PHQL_T_AGAINST, yymsp[-2].minor.yy180, yymsp[0].minor.yy180);
  yy_destructor(1,&yymsp[-1].minor);
}
// 2385 "parser.c"
        break;
      case 125:
// 1094 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_expr(PHQL_T_CAST, yymsp[-3].minor.yy180, phql_ret_raw_qualified_name(yymsp[-1].minor.yy0, NULL));
  yy_destructor(58,&yymsp[-5].minor);
  yy_destructor(43,&yymsp[-4].minor);
  yy_destructor(31,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2396 "parser.c"
        break;
      case 127:
// 1104 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_func_call(yymsp[-3].minor.yy0, yymsp[-1].minor.yy180);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2405 "parser.c"
        break;
      case 128:
// 1108 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_func_call(yymsp[-2].minor.yy0, NULL);
  yy_destructor(43,&yymsp[-1].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2414 "parser.c"
        break;
      case 130:
// 1118 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_zval_list(yymsp[0].minor.yy180, NULL);
}
// 2421 "parser.c"
        break;
      case 133:
// 1132 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_expr(PHQL_T_ISNULL, yymsp[-2].minor.yy180, NULL);
  yy_destructor(21,&yymsp[-1].minor);
  yy_destructor(59,&yymsp[0].minor);
}
// 2430 "parser.c"
        break;
      case 134:
// 1136 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_expr(PHQL_T_ISNOTNULL, yymsp[-3].minor.yy180, NULL);
  yy_destructor(21,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
  yy_destructor(59,&yymsp[0].minor);
}
// 2440 "parser.c"
        break;
      case 135:
// 1140 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_expr(PHQL_T_DISTINCT, NULL, yymsp[0].minor.yy180);
  yy_destructor(23,&yymsp[-1].minor);
}
// 2448 "parser.c"
        break;
      case 136:
// 1144 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_expr(PHQL_T_BETWEEN, yymsp[-2].minor.yy180, yymsp[0].minor.yy180);
  yy_destructor(2,&yymsp[-1].minor);
}
// 2456 "parser.c"
        break;
      case 137:
// 1148 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_expr(PHQL_T_NOT, NULL, yymsp[0].minor.yy180);
  yy_destructor(24,&yymsp[-1].minor);
}
// 2464 "parser.c"
        break;
      case 138:
// 1152 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_expr(PHQL_T_BITWISE_NOT, NULL, yymsp[0].minor.yy180);
  yy_destructor(25,&yymsp[-1].minor);
}
// 2472 "parser.c"
        break;
      case 139:
// 1156 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_expr(PHQL_T_ENCLOSED, yymsp[-1].minor.yy180, NULL);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2481 "parser.c"
        break;
      case 142:
// 1168 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_literal_zval(PHQL_T_STRING, yymsp[0].minor.yy0);
}
// 2488 "parser.c"
        break;
      case 143:
// 1172 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_literal_zval(PHQL_T_DOUBLE, yymsp[0].minor.yy0);
}
// 2495 "parser.c"
        break;
      case 144:
// 1176 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_literal_zval(PHQL_T_NULL, NULL);
  yy_destructor(59,&yymsp[0].minor);
}
// 2503 "parser.c"
        break;
      case 145:
// 1180 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_placeholder_zval(PHQL_T_NPLACEHOLDER, yymsp[0].minor.yy0);
}
// 2510 "parser.c"
        break;
      case 146:
// 1184 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_placeholder_zval(PHQL_T_SPLACEHOLDER, yymsp[0].minor.yy0);
}
// 2517 "parser.c"
        break;
      case 147:
// 1190 "parser.lemon"
{
	yygotominor.yy180 = phql_ret_qualified_name(yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(30,&yymsp[-1].minor);
}
// 2525 "parser.c"
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
// 441 "parser.lemon"

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

// 2634 "parser.c"
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
		ZVAL_STRING(*error_msg, "Parsing error near to EOF", 1);
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
	int scanner_status, status = SUCCESS;
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