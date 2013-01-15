/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is include which follows the "include" declaration
** in the input file. */
#include <stdio.h>
// 37 "parser.lemon"


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
#define YYNOCODE 104
#define YYACTIONTYPE unsigned short int
#define phql_TOKENTYPE phql_parser_token*
typedef union {
  phql_TOKENTYPE yy0;
  zval* yy10;
  int yy207;
} YYMINORTYPE;
#define YYSTACKDEPTH 100
#define phql_ARG_SDECL phql_parser_status *status;
#define phql_ARG_PDECL ,phql_parser_status *status
#define phql_ARG_FETCH phql_parser_status *status = yypParser->status
#define phql_ARG_STORE yypParser->status = status
#define YYNSTATE 237
#define YYNRULE 145
#define YYERRORSYMBOL 59
#define YYERRSYMDT yy207
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
 /*     0 */    83,   59,   61,   63,   65,   67,   69,   51,   53,   71,
 /*    10 */    55,   57,   47,   45,   49,   43,   40,   79,   76,  237,
 /*    20 */    73,    7,  125,  127,  189,  135,  187,    9,   83,   59,
 /*    30 */    61,   63,   65,   67,   69,   51,   53,   71,   55,   57,
 /*    40 */    47,   45,   49,   43,   40,   79,   76,   11,   73,   59,
 /*    50 */    61,   63,   65,   67,   69,   51,   53,   71,   55,   57,
 /*    60 */    47,   45,   49,   43,   40,   79,   76,   99,   73,   83,
 /*    70 */    59,   61,   63,   65,   67,   69,   51,   53,   71,   55,
 /*    80 */    57,   47,   45,   49,   43,   40,   79,   76,   90,   73,
 /*    90 */    51,   53,   71,   55,   57,   47,   45,   49,   43,   40,
 /*   100 */    79,   76,   92,   73,   89,   41,  142,   29,   93,   95,
 /*   110 */   178,  144,  145,   86,   92,   79,   76,   41,   73,  238,
 /*   120 */    93,   95,   25,   26,   31,   86,  172,   97,  107,   31,
 /*   130 */   155,  156,  158,  160,  122,  164,  168,  101,   35,   97,
 /*   140 */    17,   37,  104,  102,  103,  105,  106,  239,   30,  101,
 /*   150 */   138,  119,  124,  123,  104,  102,  103,  105,  106,  182,
 /*   160 */     8,   16,   41,  116,  191,   93,   95,  200,  185,  219,
 /*   170 */   183,  234,  100,   41,  244,  196,   93,   95,  201,   33,
 /*   180 */    18,   86,   29,   20,   97,  155,  156,  158,  160,  240,
 /*   190 */   164,  168,   85,  241,  101,   97,   23,   34,   26,  104,
 /*   200 */   102,  103,  105,  106,  128,  101,  130,  134,  140,  180,
 /*   210 */   104,  102,  103,  105,  106,  242,   71,   55,   57,   47,
 /*   220 */    45,   49,   43,   40,   79,   76,   10,   73,   55,   57,
 /*   230 */    47,   45,   49,   43,   40,   79,   76,   81,   73,  143,
 /*   240 */   144,  145,  383,    1,    2,    3,    4,    5,    6,   47,
 /*   250 */    45,   49,   43,   40,   79,   76,  243,   73,  251,  136,
 /*   260 */    21,   43,   40,   79,   76,  117,   73,   10,   78,  245,
 /*   270 */    80,  213,   78,  100,   78,   13,  230,  100,   78,  100,
 /*   280 */   200,  260,  249,  100,  203,  100,  139,  212,  207,  190,
 /*   290 */   186,  201,  109,   85,  108,  100,   88,   85,  108,   85,
 /*   300 */    91,   21,  113,   85,  108,   85,  117,  336,   10,  246,
 /*   310 */   181,  186,  262,  200,   21,   85,  100,   22,  100,  247,
 /*   320 */    38,   10,  228,   39,  199,  115,   21,  100,  100,  337,
 /*   330 */   100,   12,   38,   10,   10,   15,   85,   42,   85,  227,
 /*   340 */    44,   46,  100,   74,   48,  100,  100,   85,   85,  100,
 /*   350 */    85,   50,  111,   52,   21,  122,  100,   21,  100,  338,
 /*   360 */    14,   10,   85,   54,   10,   85,   85,   56,  100,   85,
 /*   370 */    58,   10,  100,  121,   60,  100,   85,   62,   85,  100,
 /*   380 */    64,   66,  100,  259,   68,  100,  100,   32,   85,  100,
 /*   390 */   161,   70,   85,   72,  162,   85,  100,   90,  100,   85,
 /*   400 */    87,  254,   85,   75,  304,   85,   85,   84,  100,   85,
 /*   410 */    94,  313,  100,  110,   96,  100,   85,   98,   85,  100,
 /*   420 */   255,  137,  100,  141,  150,  256,  100,  179,   85,  100,
 /*   430 */   225,  174,   85,   32,  154,   85,  152,   27,   28,   85,
 /*   440 */   222,  229,   85,   76,  149,   73,   85,  131,  136,   85,
 /*   450 */   133,   90,   19,   10,   24,  136,  216,  147,  151,  214,
 /*   460 */   165,  169,  173,  216,  166,  170,  174,  114,  177,  305,
 /*   470 */   175,  184,   10,  194,  202,  198,  209,   10,  198,  220,
 /*   480 */   231,  314,  218,  174,   87,  236,  225,  253,   33,  174,
 /*   490 */    36,  197,  204,  248,  208,  252,   73,  224,   77,  112,
 /*   500 */    82,  250,  118,  233,  120,  126,  257,  129,  258,  132,
 /*   510 */   264,  263,  261,  265,   31,  153,  286,  149,  146,  287,
 /*   520 */   157,  216,  148,  288,  159,  289,  296,  163,  290,  291,
 /*   530 */   167,  193,  292,  216,  293,  297,  195,  210,  215,  307,
 /*   540 */   294,  176,  171,  188,  211,  339,  306,  221,  223,  226,
 /*   550 */   316,  232,  315,  235,  192,  250,  250,  250,  205,  250,
 /*   560 */   206,  250,  250,  250,  250,  250,  250,  250,  250,  250,
 /*   570 */   250,  217,
};
static YYCODETYPE yy_lookahead[] = {
 /*     0 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    10 */    11,   12,   13,   14,   15,   16,   17,   18,   19,    0,
 /*    20 */    21,   67,   68,   69,   25,   71,   27,   71,    1,    2,
 /*    30 */     3,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*    40 */    13,   14,   15,   16,   17,   18,   19,   49,   21,    2,
 /*    50 */     3,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*    60 */    13,   14,   15,   16,   17,   18,   19,   40,   21,    1,
 /*    70 */     2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*    80 */    12,   13,   14,   15,   16,   17,   18,   19,   24,   21,
 /*    90 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   100 */    18,   19,   14,   21,   40,   17,   74,   81,   20,   21,
 /*   110 */    78,   79,   80,   25,   14,   18,   19,   17,   21,    0,
 /*   120 */    20,   21,   96,   97,   25,   25,   24,   39,   40,   25,
 /*   130 */    28,   29,   30,   31,   81,   33,   34,   49,   68,   39,
 /*   140 */    70,   71,   54,   55,   56,   57,   58,    0,   49,   49,
 /*   150 */    22,   98,   99,   49,   54,   55,   56,   57,   58,   14,
 /*   160 */    68,   69,   17,   71,   36,   20,   21,   76,   14,   41,
 /*   170 */    25,   43,   81,   17,    0,   84,   20,   21,   87,   25,
 /*   180 */    68,   25,   81,   71,   39,   28,   29,   30,   31,    0,
 /*   190 */    33,   34,  101,    0,   49,   39,   95,   96,   97,   54,
 /*   200 */    55,   56,   57,   58,   68,   49,   70,   71,   23,   24,
 /*   210 */    54,   55,   56,   57,   58,    0,   10,   11,   12,   13,
 /*   220 */    14,   15,   16,   17,   18,   19,   52,   21,   11,   12,
 /*   230 */    13,   14,   15,   16,   17,   18,   19,   21,   21,   78,
 /*   240 */    79,   80,   60,   61,   62,   63,   64,   65,   66,   13,
 /*   250 */    14,   15,   16,   17,   18,   19,    0,   21,    0,   44,
 /*   260 */    45,   16,   17,   18,   19,   50,   21,   52,   76,    0,
 /*   270 */    54,   89,   76,   81,   76,   49,   94,   81,   76,   81,
 /*   280 */    76,    0,    0,   81,   85,   81,   72,   88,   84,   75,
 /*   290 */    76,   87,  100,  101,  102,   81,  100,  101,  102,  101,
 /*   300 */   102,   45,  100,  101,  102,  101,   50,    0,   52,    0,
 /*   310 */    75,   76,    0,   76,   45,  101,   81,   46,   81,    0,
 /*   320 */    51,   52,   76,   76,   87,   76,   45,   81,   81,    0,
 /*   330 */    81,   24,   51,   52,   52,   49,  101,   76,  101,   93,
 /*   340 */    76,   76,   81,   10,   76,   81,   81,  101,  101,   81,
 /*   350 */   101,   76,   19,   76,   45,   81,   81,   45,   81,    0,
 /*   360 */    53,   52,  101,   76,   52,  101,  101,   76,   81,  101,
 /*   370 */    76,   52,   81,   99,   76,   81,  101,   76,  101,   81,
 /*   380 */    76,   76,   81,    0,   76,   81,   81,   26,  101,   81,
 /*   390 */    28,   76,  101,   76,   32,  101,   81,   24,   81,  101,
 /*   400 */    39,    0,  101,   76,    0,  101,  101,   76,   81,  101,
 /*   410 */    76,    0,   81,   40,   76,   81,  101,   76,  101,   81,
 /*   420 */     0,   76,   81,   73,   76,    0,   81,   77,  101,   81,
 /*   430 */    81,   81,  101,   26,   25,  101,   27,   47,   48,  101,
 /*   440 */    91,   92,  101,   19,   35,   21,  101,   68,   44,  101,
 /*   450 */    71,   24,   71,   52,   24,   44,   52,   82,   83,   67,
 /*   460 */    28,   28,   77,   52,   32,   32,   81,   40,   25,    0,
 /*   470 */    27,   26,   52,   38,   39,   24,   24,   52,   24,   77,
 /*   480 */    67,    0,   90,   81,   39,   77,   81,    0,   25,   81,
 /*   490 */    71,   40,   40,    0,   40,    0,   21,   92,   39,   39,
 /*   500 */    54,    0,   46,   90,   24,   71,    0,   71,    0,   71,
 /*   510 */     0,    0,    0,    0,   25,   25,   25,   35,   81,   25,
 /*   520 */    28,   52,   83,   25,   28,   25,    0,   28,   25,   25,
 /*   530 */    28,   81,   25,   52,   25,    0,   39,   88,   90,    0,
 /*   540 */    25,   25,   28,   25,   25,    0,    0,   42,   24,    2,
 /*   550 */     0,   90,    0,   23,   37,  103,  103,  103,   38,  103,
 /*   560 */    39,  103,  103,  103,  103,  103,  103,  103,  103,  103,
 /*   570 */   103,   49,
};
#define YY_SHIFT_USE_DFLT (-3)
static short yy_shift_ofst[] = {
 /*     0 */   128,   19,  119,  147,  189,  193,  215,  256,  174,  258,
 /*    10 */    -2,  307,  226,  329,  286,  359,  269,  309,  282,  383,
 /*    20 */   487,  271,   99,  430,   99,   -3,  390,   -3,   -3,   -3,
 /*    30 */    -3,  407,  463,   -3,   -3,  319,  493,  495,  156,   68,
 /*    40 */   156,  156,   97,  156,   97,  156,  245,  156,  245,  156,
 /*    50 */   245,  156,  206,  156,  206,  156,  236,  156,  236,  156,
 /*    60 */    82,  156,   82,  156,   82,  156,   82,  156,   82,  156,
 /*    70 */    82,  156,  217,  333,  156,  475,  459,  100,   68,  216,
 /*    80 */    -3,  446,   -3,  156,   47,   -3,  361,   88,   64,   -3,
 /*    90 */   100,   -3,   -3,  156,  424,  156,  475,  156,   27,   -3,
 /*   100 */    -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,  373,
 /*   110 */    -3,  460,  100,  427,   -3,   97,  501,  456,  104,  480,
 /*   120 */   104,   -3,   -3,   -3,   -3,  401,  506,  281,  420,  508,
 /*   130 */   312,  425,  510,  511,  512,  513,  156,   68,  145,  185,
 /*   140 */   489,  102,  157,   -3,   -3,  489,  409,  482,   -3,  156,
 /*   150 */    68,   -3,  490,   -3,   -3,  491,  492,  494,  496,  498,
 /*   160 */   362,  500,  499,  503,  432,  504,  502,  507,  433,  509,
 /*   170 */   514,  515,  489,   -3,  443,  516,   -3,   -3,   -3,   -3,
 /*   180 */   145,   -3,   -3,  445,  154,   -3,   -1,  518,   -3,   -3,
 /*   190 */    -3,  517,  489,  435,  497,  156,  451,  526,  156,   -3,
 /*   200 */    68,   -3,  519,  452,  520,  521,  156,  454,  535,  519,
 /*   210 */    -3,   -3,   -3,  404,  469,  539,  522,  545,  546,  489,
 /*   220 */   505,  489,  524,  489,   -3,  547,  156,   -3,   68,   -3,
 /*   230 */   411,  481,  550,  552,  530,  489,   -3,
};
#define YY_REDUCE_USE_DFLT (-47)
static short yy_reduce_ofst[] = {
 /*     0 */   182,  -47,  -47,  -47,  -47,  -47,  -46,   92,  -44,  -47,
 /*    10 */   -47,  -47,  -47,  -47,  -47,  -47,   70,  112,  381,  -47,
 /*    20 */   -47,  -47,  101,  -47,   26,  -47,  -47,  -47,  -47,  -47,
 /*    30 */   -47,  -47,  -47,  -47,  -47,  419,  -47,  -47,  247,  -47,
 /*    40 */   249,  261,  -47,  264,  -47,  265,  -47,  268,  -47,  275,
 /*    50 */   -47,  277,  -47,  287,  -47,  291,  -47,  294,  -47,  298,
 /*    60 */   -47,  301,  -47,  304,  -47,  305,  -47,  308,  -47,  315,
 /*    70 */   -47,  317,  -47,  -47,  327,  -47,  -47,  192,  -47,  -47,
 /*    80 */   -47,  -47,  -47,  331,  -47,  -47,  -47,  196,  -47,  -47,
 /*    90 */   198,  -47,  -47,  334,  -47,  338,  -47,  341,  -47,  -47,
 /*   100 */   -47,  -47,  -47,  -47,  -47,  -47,  -47,  -47,  -47,  -47,
 /*   110 */   -47,  -47,  202,  -47,  -47,  -47,  -47,  -47,   53,  -47,
 /*   120 */   274,  -47,  -47,  -47,  -47,  434,  -47,  136,  436,  -47,
 /*   130 */   379,  438,  -47,  -47,  -47,  -47,  345,  -47,  214,  -47,
 /*   140 */   350,   32,  161,  -47,  -47,  437,  375,  439,  -47,  348,
 /*   150 */   -47,  -47,  -47,  -47,  -47,  -47,  -47,  -47,  -47,  -47,
 /*   160 */   -47,  -47,  -47,  -47,  -47,  -47,  -47,  -47,  -47,  -47,
 /*   170 */   -47,  -47,  385,  -47,  -47,  -47,  -47,  -47,  -47,  -47,
 /*   180 */   235,  -47,  -47,  -47,  -47,  -47,  -47,  -47,  -47,  -47,
 /*   190 */   -47,  -47,  450,  -47,  -47,   91,  -47,  -47,  237,  -47,
 /*   200 */   -47,  -47,  199,  -47,  -47,  -47,  204,  -47,  -47,  449,
 /*   210 */   -47,  -47,  -47,  392,  448,  -47,  -47,  -47,  -47,  402,
 /*   220 */   -47,  349,  -47,  405,  -47,  -47,  246,  -47,  -47,  -47,
 /*   230 */   413,  461,  -47,  -47,  -47,  408,  -47,
};
static YYACTIONTYPE yy_default[] = {
 /*     0 */   382,  382,  382,  382,  382,  382,  382,  382,  382,  382,
 /*    10 */   382,  382,  382,  382,  382,  382,  382,  382,  382,  382,
 /*    20 */   382,  382,  382,  322,  382,  323,  325,  326,  327,  328,
 /*    30 */   329,  381,  382,  380,  324,  382,  382,  382,  382,  335,
 /*    40 */   382,  382,  340,  382,  342,  382,  343,  382,  344,  382,
 /*    50 */   345,  382,  346,  382,  347,  382,  348,  382,  349,  382,
 /*    60 */   350,  382,  351,  382,  352,  382,  353,  382,  354,  382,
 /*    70 */   355,  382,  356,  382,  382,  357,  382,  382,  366,  382,
 /*    80 */   367,  382,  368,  382,  370,  360,  381,  382,  382,  361,
 /*    90 */   382,  363,  365,  382,  369,  382,  371,  382,  382,  372,
 /*   100 */   373,  374,  375,  376,  377,  378,  379,  362,  364,  382,
 /*   110 */   358,  382,  382,  382,  359,  341,  382,  382,  382,  330,
 /*   120 */   382,  331,  333,  334,  332,  382,  382,  382,  382,  382,
 /*   130 */   382,  382,  382,  382,  382,  382,  382,  321,  382,  382,
 /*   140 */   382,  266,  267,  277,  279,  382,  280,  281,  283,  382,
 /*   150 */   295,  282,  382,  284,  285,  382,  382,  382,  382,  382,
 /*   160 */   382,  382,  382,  382,  382,  382,  382,  382,  382,  382,
 /*   170 */   382,  382,  382,  275,  320,  382,  318,  319,  278,  276,
 /*   180 */   382,  268,  270,  381,  382,  271,  274,  382,  272,  273,
 /*   190 */   269,  382,  382,  382,  382,  382,  382,  382,  382,  298,
 /*   200 */   300,  299,  382,  382,  382,  382,  382,  382,  382,  382,
 /*   210 */   301,  303,  302,  382,  382,  382,  382,  382,  382,  382,
 /*   220 */   382,  382,  308,  382,  309,  382,  382,  311,  312,  310,
 /*   230 */   382,  382,  382,  382,  382,  382,  317,
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
  "AND",           "OR",            "LIKE",          "BITWISE_AND", 
  "BITWISE_OR",    "DIVIDE",        "TIMES",         "MOD",         
  "PLUS",          "MINUS",         "IS",            "IN",          
  "DISTINCT",      "NOT",           "SELECT",        "FROM",        
  "COMMA",         "IDENTIFIER",    "DOT",           "AS",          
  "JOIN",          "INNER",         "CROSS",         "LEFT",        
  "OUTER",         "RIGHT",         "FULL",          "ON",          
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
  "expr",          "associated_name",  "join_item",     "join_clause", 
  "join_type",     "qualified_name",  "join_associated_name",  "join_conditions",
  "values_list",   "field_list",    "value_list",    "value_item",  
  "field_item",    "update_clause",  "limit_clause",  "update_item_list",
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
 /* 111 */ "expr ::= expr BITWISE_AND expr",
 /* 112 */ "expr ::= expr BITWISE_OR expr",
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
 /* 132 */ "expr ::= DISTINCT expr",
 /* 133 */ "expr ::= expr BETWEEN expr",
 /* 134 */ "expr ::= NOT expr",
 /* 135 */ "expr ::= BRACKET_OPEN expr BRACKET_CLOSE",
 /* 136 */ "expr ::= qualified_name",
 /* 137 */ "expr ::= INTEGER",
 /* 138 */ "expr ::= STRING",
 /* 139 */ "expr ::= DOUBLE",
 /* 140 */ "expr ::= NULL",
 /* 141 */ "expr ::= NPLACEHOLDER",
 /* 142 */ "expr ::= SPLACEHOLDER",
 /* 143 */ "qualified_name ::= IDENTIFIER DOT IDENTIFIER",
 /* 144 */ "qualified_name ::= IDENTIFIER",
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
// 486 "parser.lemon"
{
	if ((yypminor->yy0)) {
		if ((yypminor->yy0)->free_flag) {
			efree((yypminor->yy0)->token);
		}
		efree((yypminor->yy0));
	}
}
// 1094 "parser.c"
      break;
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
    case 82:
    case 83:
    case 85:
    case 86:
    case 88:
    case 89:
    case 90:
    case 91:
    case 92:
    case 94:
    case 95:
    case 96:
    case 98:
    case 99:
    case 100:
    case 101:
    case 102:
// 499 "parser.lemon"
{ zval_ptr_dtor(&(yypminor->yy10)); }
// 1136 "parser.c"
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
  { 60, 1 },
  { 61, 1 },
  { 61, 1 },
  { 61, 1 },
  { 61, 1 },
  { 62, 1 },
  { 62, 2 },
  { 62, 3 },
  { 62, 3 },
  { 62, 4 },
  { 62, 4 },
  { 62, 5 },
  { 62, 5 },
  { 62, 3 },
  { 62, 4 },
  { 62, 4 },
  { 62, 5 },
  { 62, 2 },
  { 62, 3 },
  { 62, 4 },
  { 62, 3 },
  { 62, 4 },
  { 62, 6 },
  { 62, 2 },
  { 62, 3 },
  { 62, 3 },
  { 62, 4 },
  { 62, 5 },
  { 62, 2 },
  { 66, 4 },
  { 66, 5 },
  { 72, 3 },
  { 72, 1 },
  { 75, 1 },
  { 75, 3 },
  { 75, 3 },
  { 75, 2 },
  { 75, 1 },
  { 73, 3 },
  { 73, 1 },
  { 74, 2 },
  { 74, 1 },
  { 78, 1 },
  { 79, 2 },
  { 79, 3 },
  { 79, 3 },
  { 79, 4 },
  { 82, 2 },
  { 82, 1 },
  { 80, 1 },
  { 80, 2 },
  { 80, 2 },
  { 80, 2 },
  { 80, 3 },
  { 80, 2 },
  { 80, 3 },
  { 80, 2 },
  { 80, 3 },
  { 83, 2 },
  { 63, 7 },
  { 63, 10 },
  { 84, 3 },
  { 84, 1 },
  { 87, 1 },
  { 85, 3 },
  { 85, 1 },
  { 88, 1 },
  { 64, 1 },
  { 64, 2 },
  { 64, 2 },
  { 64, 3 },
  { 89, 4 },
  { 91, 3 },
  { 91, 1 },
  { 92, 3 },
  { 93, 1 },
  { 65, 1 },
  { 65, 2 },
  { 65, 2 },
  { 65, 3 },
  { 94, 3 },
  { 77, 3 },
  { 77, 2 },
  { 77, 1 },
  { 67, 2 },
  { 68, 3 },
  { 95, 3 },
  { 95, 1 },
  { 96, 1 },
  { 96, 2 },
  { 96, 2 },
  { 97, 1 },
  { 97, 1 },
  { 69, 3 },
  { 98, 3 },
  { 98, 1 },
  { 99, 1 },
  { 99, 1 },
  { 70, 2 },
  { 71, 2 },
  { 71, 4 },
  { 71, 4 },
  { 90, 2 },
  { 76, 2 },
  { 76, 3 },
  { 76, 3 },
  { 76, 3 },
  { 76, 3 },
  { 76, 3 },
  { 76, 3 },
  { 76, 3 },
  { 76, 3 },
  { 76, 3 },
  { 76, 3 },
  { 76, 3 },
  { 76, 3 },
  { 76, 3 },
  { 76, 3 },
  { 76, 3 },
  { 76, 3 },
  { 76, 4 },
  { 76, 5 },
  { 76, 6 },
  { 76, 1 },
  { 101, 4 },
  { 101, 3 },
  { 100, 3 },
  { 100, 1 },
  { 102, 1 },
  { 102, 1 },
  { 76, 3 },
  { 76, 4 },
  { 76, 2 },
  { 76, 3 },
  { 76, 2 },
  { 76, 3 },
  { 76, 1 },
  { 76, 1 },
  { 76, 1 },
  { 76, 1 },
  { 76, 1 },
  { 76, 1 },
  { 76, 1 },
  { 81, 3 },
  { 81, 1 },
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
// 495 "parser.lemon"
{
	status->ret = yymsp[0].minor.yy10;
}
// 1498 "parser.c"
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
      case 123:
      case 129:
      case 136:
// 501 "parser.lemon"
{
	yygotominor.yy10 = yymsp[0].minor.yy10;
}
// 1524 "parser.c"
        break;
      case 5:
// 519 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_select_statement(yymsp[0].minor.yy10, NULL, NULL, NULL, NULL, NULL);
}
// 1531 "parser.c"
        break;
      case 6:
// 523 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_select_statement(yymsp[-1].minor.yy10, yymsp[0].minor.yy10, NULL, NULL, NULL, NULL);
}
// 1538 "parser.c"
        break;
      case 7:
// 527 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_select_statement(yymsp[-2].minor.yy10, yymsp[-1].minor.yy10, yymsp[0].minor.yy10, NULL, NULL, NULL);
}
// 1545 "parser.c"
        break;
      case 8:
// 531 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_select_statement(yymsp[-2].minor.yy10, yymsp[-1].minor.yy10, NULL, yymsp[0].minor.yy10, NULL, NULL);
}
// 1552 "parser.c"
        break;
      case 9:
// 535 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_select_statement(yymsp[-3].minor.yy10, yymsp[-2].minor.yy10, NULL, yymsp[-1].minor.yy10, yymsp[0].minor.yy10, NULL);
}
// 1559 "parser.c"
        break;
      case 10:
// 539 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_select_statement(yymsp[-3].minor.yy10, yymsp[-2].minor.yy10, yymsp[0].minor.yy10, yymsp[-1].minor.yy10, NULL, NULL);
}
// 1566 "parser.c"
        break;
      case 11:
// 543 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_select_statement(yymsp[-4].minor.yy10, yymsp[-3].minor.yy10, yymsp[-1].minor.yy10, yymsp[-2].minor.yy10, NULL, yymsp[0].minor.yy10);
}
// 1573 "parser.c"
        break;
      case 12:
// 547 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_select_statement(yymsp[-4].minor.yy10, yymsp[-3].minor.yy10, yymsp[0].minor.yy10, yymsp[-2].minor.yy10, yymsp[-1].minor.yy10, NULL);
}
// 1580 "parser.c"
        break;
      case 13:
// 551 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_select_statement(yymsp[-2].minor.yy10, yymsp[-1].minor.yy10, NULL, NULL, NULL, yymsp[0].minor.yy10);
}
// 1587 "parser.c"
        break;
      case 14:
// 555 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_select_statement(yymsp[-3].minor.yy10, yymsp[-2].minor.yy10, yymsp[-1].minor.yy10, NULL, NULL, yymsp[0].minor.yy10);
}
// 1594 "parser.c"
        break;
      case 15:
// 559 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_select_statement(yymsp[-3].minor.yy10, yymsp[-2].minor.yy10, NULL, yymsp[-1].minor.yy10, NULL, yymsp[0].minor.yy10);
}
// 1601 "parser.c"
        break;
      case 16:
// 563 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_select_statement(yymsp[-4].minor.yy10, yymsp[-3].minor.yy10, NULL, yymsp[-2].minor.yy10, yymsp[-1].minor.yy10, yymsp[0].minor.yy10);
}
// 1608 "parser.c"
        break;
      case 17:
// 567 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_select_statement(yymsp[-1].minor.yy10, NULL, yymsp[0].minor.yy10, NULL, NULL, NULL);
}
// 1615 "parser.c"
        break;
      case 18:
// 571 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_select_statement(yymsp[-2].minor.yy10, NULL, yymsp[0].minor.yy10, yymsp[-1].minor.yy10, NULL, NULL);
}
// 1622 "parser.c"
        break;
      case 19:
// 575 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_select_statement(yymsp[-3].minor.yy10, NULL, yymsp[0].minor.yy10, yymsp[-2].minor.yy10, yymsp[-1].minor.yy10, NULL);
}
// 1629 "parser.c"
        break;
      case 20:
// 579 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_select_statement(yymsp[-2].minor.yy10, NULL, yymsp[-1].minor.yy10, NULL, NULL, yymsp[0].minor.yy10);
}
// 1636 "parser.c"
        break;
      case 21:
// 583 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_select_statement(yymsp[-3].minor.yy10, NULL, yymsp[-1].minor.yy10, yymsp[-2].minor.yy10, NULL, yymsp[0].minor.yy10);
}
// 1643 "parser.c"
        break;
      case 22:
// 587 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_select_statement(yymsp[-5].minor.yy10, yymsp[-4].minor.yy10, yymsp[-1].minor.yy10, yymsp[-3].minor.yy10, yymsp[-2].minor.yy10, yymsp[0].minor.yy10);
}
// 1650 "parser.c"
        break;
      case 23:
// 591 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_select_statement(yymsp[-1].minor.yy10, NULL, NULL, yymsp[0].minor.yy10, NULL, NULL);
}
// 1657 "parser.c"
        break;
      case 24:
// 595 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_select_statement(yymsp[-2].minor.yy10, NULL, NULL, yymsp[-1].minor.yy10, NULL, yymsp[0].minor.yy10);
}
// 1664 "parser.c"
        break;
      case 25:
// 599 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_select_statement(yymsp[-2].minor.yy10, NULL, NULL, yymsp[-1].minor.yy10, yymsp[0].minor.yy10, NULL);
}
// 1671 "parser.c"
        break;
      case 26:
// 603 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_select_statement(yymsp[-3].minor.yy10, NULL, NULL, yymsp[-2].minor.yy10, yymsp[-1].minor.yy10, yymsp[0].minor.yy10);
}
// 1678 "parser.c"
        break;
      case 27:
// 607 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_select_statement(yymsp[-4].minor.yy10, NULL, yymsp[-1].minor.yy10, yymsp[-3].minor.yy10, yymsp[-2].minor.yy10, yymsp[0].minor.yy10);
}
// 1685 "parser.c"
        break;
      case 28:
// 611 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_select_statement(yymsp[-1].minor.yy10, NULL, NULL, NULL, NULL, yymsp[0].minor.yy10);
}
// 1692 "parser.c"
        break;
      case 29:
// 617 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_select_clause(yymsp[-2].minor.yy10, yymsp[0].minor.yy10, NULL);
  yy_destructor(22,&yymsp[-3].minor);
  yy_destructor(23,&yymsp[-1].minor);
}
// 1701 "parser.c"
        break;
      case 30:
// 621 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_select_clause(yymsp[-3].minor.yy10, yymsp[-1].minor.yy10, yymsp[0].minor.yy10);
  yy_destructor(22,&yymsp[-4].minor);
  yy_destructor(23,&yymsp[-2].minor);
}
// 1710 "parser.c"
        break;
      case 31:
      case 38:
      case 61:
      case 64:
      case 72:
      case 86:
      case 94:
      case 126:
// 627 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_zval_list(yymsp[-2].minor.yy10, yymsp[0].minor.yy10);
  yy_destructor(24,&yymsp[-1].minor);
}
// 1725 "parser.c"
        break;
      case 33:
      case 128:
// 637 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_column_item(PHQL_T_ALL, NULL, NULL, NULL);
  yy_destructor(14,&yymsp[0].minor);
}
// 1734 "parser.c"
        break;
      case 34:
// 641 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_column_item(PHQL_T_DOMAINALL, NULL, yymsp[-2].minor.yy0, NULL);
  yy_destructor(26,&yymsp[-1].minor);
  yy_destructor(14,&yymsp[0].minor);
}
// 1743 "parser.c"
        break;
      case 35:
// 645 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-2].minor.yy10, NULL, yymsp[0].minor.yy0);
  yy_destructor(27,&yymsp[-1].minor);
}
// 1751 "parser.c"
        break;
      case 36:
// 649 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-1].minor.yy10, NULL, yymsp[0].minor.yy0);
}
// 1758 "parser.c"
        break;
      case 37:
// 653 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_column_item(PHQL_T_EXPR, yymsp[0].minor.yy10, NULL, NULL);
}
// 1765 "parser.c"
        break;
      case 40:
// 669 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_zval_list(yymsp[-1].minor.yy10, yymsp[0].minor.yy10);
}
// 1772 "parser.c"
        break;
      case 43:
// 686 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_join_item(yymsp[-1].minor.yy10, yymsp[0].minor.yy10, NULL, NULL);
}
// 1779 "parser.c"
        break;
      case 44:
// 691 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_join_item(yymsp[-2].minor.yy10, yymsp[-1].minor.yy10, yymsp[0].minor.yy10, NULL);
}
// 1786 "parser.c"
        break;
      case 45:
// 696 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_join_item(yymsp[-2].minor.yy10, yymsp[-1].minor.yy10, NULL, yymsp[0].minor.yy10);
}
// 1793 "parser.c"
        break;
      case 46:
// 701 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_join_item(yymsp[-3].minor.yy10, yymsp[-2].minor.yy10, yymsp[-1].minor.yy10, yymsp[0].minor.yy10);
}
// 1800 "parser.c"
        break;
      case 47:
// 707 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_qualified_name(yymsp[0].minor.yy0, NULL);
  yy_destructor(27,&yymsp[-1].minor);
}
// 1808 "parser.c"
        break;
      case 48:
      case 66:
      case 144:
// 711 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_qualified_name(yymsp[0].minor.yy0, NULL);
}
// 1817 "parser.c"
        break;
      case 49:
// 717 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_join_type(PHQL_T_INNERJOIN);
  yy_destructor(28,&yymsp[0].minor);
}
// 1825 "parser.c"
        break;
      case 50:
// 721 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_join_type(PHQL_T_INNERJOIN);
  yy_destructor(29,&yymsp[-1].minor);
  yy_destructor(28,&yymsp[0].minor);
}
// 1834 "parser.c"
        break;
      case 51:
// 725 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_join_type(PHQL_T_CROSSJOIN);
  yy_destructor(30,&yymsp[-1].minor);
  yy_destructor(28,&yymsp[0].minor);
}
// 1843 "parser.c"
        break;
      case 52:
// 729 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  yy_destructor(31,&yymsp[-1].minor);
  yy_destructor(28,&yymsp[0].minor);
}
// 1852 "parser.c"
        break;
      case 53:
// 733 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  yy_destructor(31,&yymsp[-2].minor);
  yy_destructor(32,&yymsp[-1].minor);
  yy_destructor(28,&yymsp[0].minor);
}
// 1862 "parser.c"
        break;
      case 54:
// 737 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  yy_destructor(33,&yymsp[-1].minor);
  yy_destructor(28,&yymsp[0].minor);
}
// 1871 "parser.c"
        break;
      case 55:
// 741 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  yy_destructor(33,&yymsp[-2].minor);
  yy_destructor(32,&yymsp[-1].minor);
  yy_destructor(28,&yymsp[0].minor);
}
// 1881 "parser.c"
        break;
      case 56:
// 745 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_join_type(PHQL_T_FULLJOIN);
  yy_destructor(34,&yymsp[-1].minor);
  yy_destructor(28,&yymsp[0].minor);
}
// 1890 "parser.c"
        break;
      case 57:
// 749 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_join_type(PHQL_T_FULLJOIN);
  yy_destructor(34,&yymsp[-2].minor);
  yy_destructor(32,&yymsp[-1].minor);
  yy_destructor(28,&yymsp[0].minor);
}
// 1900 "parser.c"
        break;
      case 58:
// 755 "parser.lemon"
{
	yygotominor.yy10 = yymsp[0].minor.yy10;
  yy_destructor(35,&yymsp[-1].minor);
}
// 1908 "parser.c"
        break;
      case 59:
// 762 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_insert_statement(yymsp[-4].minor.yy10, NULL, yymsp[-1].minor.yy10);
  yy_destructor(36,&yymsp[-6].minor);
  yy_destructor(37,&yymsp[-5].minor);
  yy_destructor(38,&yymsp[-3].minor);
  yy_destructor(39,&yymsp[-2].minor);
  yy_destructor(40,&yymsp[0].minor);
}
// 1920 "parser.c"
        break;
      case 60:
// 766 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_insert_statement(yymsp[-7].minor.yy10, yymsp[-5].minor.yy10, yymsp[-1].minor.yy10);
  yy_destructor(36,&yymsp[-9].minor);
  yy_destructor(37,&yymsp[-8].minor);
  yy_destructor(39,&yymsp[-6].minor);
  yy_destructor(40,&yymsp[-4].minor);
  yy_destructor(38,&yymsp[-3].minor);
  yy_destructor(39,&yymsp[-2].minor);
  yy_destructor(40,&yymsp[0].minor);
}
// 1934 "parser.c"
        break;
      case 67:
// 804 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_update_statement(yymsp[0].minor.yy10, NULL, NULL);
}
// 1941 "parser.c"
        break;
      case 68:
// 808 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_update_statement(yymsp[-1].minor.yy10, yymsp[0].minor.yy10, NULL);
}
// 1948 "parser.c"
        break;
      case 69:
// 812 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_update_statement(yymsp[-1].minor.yy10, NULL, yymsp[0].minor.yy10);
}
// 1955 "parser.c"
        break;
      case 70:
// 816 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_update_statement(yymsp[-2].minor.yy10, yymsp[-1].minor.yy10, yymsp[0].minor.yy10);
}
// 1962 "parser.c"
        break;
      case 71:
// 822 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_update_clause(yymsp[-2].minor.yy10, yymsp[0].minor.yy10);
  yy_destructor(41,&yymsp[-3].minor);
  yy_destructor(42,&yymsp[-1].minor);
}
// 1971 "parser.c"
        break;
      case 74:
// 838 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_update_item(yymsp[-2].minor.yy10, yymsp[0].minor.yy10);
  yy_destructor(2,&yymsp[-1].minor);
}
// 1979 "parser.c"
        break;
      case 76:
// 850 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_delete_statement(yymsp[0].minor.yy10, NULL, NULL);
}
// 1986 "parser.c"
        break;
      case 77:
// 854 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_delete_statement(yymsp[-1].minor.yy10, yymsp[0].minor.yy10, NULL);
}
// 1993 "parser.c"
        break;
      case 78:
// 858 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_delete_statement(yymsp[-1].minor.yy10, NULL, yymsp[0].minor.yy10);
}
// 2000 "parser.c"
        break;
      case 79:
// 862 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_delete_statement(yymsp[-2].minor.yy10, yymsp[-1].minor.yy10, yymsp[0].minor.yy10);
}
// 2007 "parser.c"
        break;
      case 80:
// 868 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_delete_clause(yymsp[0].minor.yy10);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(23,&yymsp[-1].minor);
}
// 2016 "parser.c"
        break;
      case 81:
// 874 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_assoc_name(yymsp[-2].minor.yy10, yymsp[0].minor.yy0);
  yy_destructor(27,&yymsp[-1].minor);
}
// 2024 "parser.c"
        break;
      case 82:
// 878 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_assoc_name(yymsp[-1].minor.yy10, yymsp[0].minor.yy0);
}
// 2031 "parser.c"
        break;
      case 83:
// 882 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_assoc_name(yymsp[0].minor.yy10, NULL);
}
// 2038 "parser.c"
        break;
      case 84:
// 888 "parser.lemon"
{
	yygotominor.yy10 = yymsp[0].minor.yy10;
  yy_destructor(44,&yymsp[-1].minor);
}
// 2046 "parser.c"
        break;
      case 85:
// 894 "parser.lemon"
{
	yygotominor.yy10 = yymsp[0].minor.yy10;
  yy_destructor(45,&yymsp[-2].minor);
  yy_destructor(46,&yymsp[-1].minor);
}
// 2055 "parser.c"
        break;
      case 88:
// 910 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_order_item(yymsp[0].minor.yy10, 0);
}
// 2062 "parser.c"
        break;
      case 89:
// 914 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_order_item(yymsp[-1].minor.yy10, PHQL_T_ASC);
  yy_destructor(47,&yymsp[0].minor);
}
// 2070 "parser.c"
        break;
      case 90:
// 918 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_order_item(yymsp[-1].minor.yy10, PHQL_T_DESC);
  yy_destructor(48,&yymsp[0].minor);
}
// 2078 "parser.c"
        break;
      case 92:
      case 97:
      case 137:
// 926 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_literal_zval(PHQL_T_INTEGER, yymsp[0].minor.yy0);
}
// 2087 "parser.c"
        break;
      case 93:
// 932 "parser.lemon"
{
	yygotominor.yy10 = yymsp[0].minor.yy10;
  yy_destructor(50,&yymsp[-2].minor);
  yy_destructor(46,&yymsp[-1].minor);
}
// 2096 "parser.c"
        break;
      case 98:
// 958 "parser.lemon"
{
	yygotominor.yy10 = yymsp[0].minor.yy10;
  yy_destructor(51,&yymsp[-1].minor);
}
// 2104 "parser.c"
        break;
      case 99:
      case 102:
// 964 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_limit_clause(yymsp[0].minor.yy0, NULL);
  yy_destructor(52,&yymsp[-1].minor);
}
// 2113 "parser.c"
        break;
      case 100:
// 968 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_limit_clause(yymsp[0].minor.yy0, yymsp[-2].minor.yy0);
  yy_destructor(52,&yymsp[-3].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
// 2122 "parser.c"
        break;
      case 101:
// 972 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_limit_clause(yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(52,&yymsp[-3].minor);
  yy_destructor(53,&yymsp[-1].minor);
}
// 2131 "parser.c"
        break;
      case 103:
// 984 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_expr(PHQL_T_MINUS, NULL, yymsp[0].minor.yy10);
  yy_destructor(17,&yymsp[-1].minor);
}
// 2139 "parser.c"
        break;
      case 104:
// 988 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_expr(PHQL_T_SUB, yymsp[-2].minor.yy10, yymsp[0].minor.yy10);
  yy_destructor(17,&yymsp[-1].minor);
}
// 2147 "parser.c"
        break;
      case 105:
// 992 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_expr(PHQL_T_ADD, yymsp[-2].minor.yy10, yymsp[0].minor.yy10);
  yy_destructor(16,&yymsp[-1].minor);
}
// 2155 "parser.c"
        break;
      case 106:
// 996 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_expr(PHQL_T_MUL, yymsp[-2].minor.yy10, yymsp[0].minor.yy10);
  yy_destructor(14,&yymsp[-1].minor);
}
// 2163 "parser.c"
        break;
      case 107:
// 1000 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_expr(PHQL_T_DIV, yymsp[-2].minor.yy10, yymsp[0].minor.yy10);
  yy_destructor(13,&yymsp[-1].minor);
}
// 2171 "parser.c"
        break;
      case 108:
// 1004 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_expr(PHQL_T_MOD, yymsp[-2].minor.yy10, yymsp[0].minor.yy10);
  yy_destructor(15,&yymsp[-1].minor);
}
// 2179 "parser.c"
        break;
      case 109:
// 1008 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_expr(PHQL_T_AND, yymsp[-2].minor.yy10, yymsp[0].minor.yy10);
  yy_destructor(8,&yymsp[-1].minor);
}
// 2187 "parser.c"
        break;
      case 110:
// 1012 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_expr(PHQL_T_OR, yymsp[-2].minor.yy10, yymsp[0].minor.yy10);
  yy_destructor(9,&yymsp[-1].minor);
}
// 2195 "parser.c"
        break;
      case 111:
// 1016 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_expr(PHQL_T_BITWISE_AND, yymsp[-2].minor.yy10, yymsp[0].minor.yy10);
  yy_destructor(11,&yymsp[-1].minor);
}
// 2203 "parser.c"
        break;
      case 112:
// 1020 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_expr(PHQL_T_BITWISE_OR, yymsp[-2].minor.yy10, yymsp[0].minor.yy10);
  yy_destructor(12,&yymsp[-1].minor);
}
// 2211 "parser.c"
        break;
      case 113:
// 1024 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_expr(PHQL_T_EQUALS, yymsp[-2].minor.yy10, yymsp[0].minor.yy10);
  yy_destructor(2,&yymsp[-1].minor);
}
// 2219 "parser.c"
        break;
      case 114:
// 1028 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_expr(PHQL_T_NOTEQUALS, yymsp[-2].minor.yy10, yymsp[0].minor.yy10);
  yy_destructor(3,&yymsp[-1].minor);
}
// 2227 "parser.c"
        break;
      case 115:
// 1032 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_expr(PHQL_T_LESS, yymsp[-2].minor.yy10, yymsp[0].minor.yy10);
  yy_destructor(4,&yymsp[-1].minor);
}
// 2235 "parser.c"
        break;
      case 116:
// 1036 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_expr(PHQL_T_GREATER, yymsp[-2].minor.yy10, yymsp[0].minor.yy10);
  yy_destructor(5,&yymsp[-1].minor);
}
// 2243 "parser.c"
        break;
      case 117:
// 1040 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_expr(PHQL_T_GREATEREQUAL, yymsp[-2].minor.yy10, yymsp[0].minor.yy10);
  yy_destructor(6,&yymsp[-1].minor);
}
// 2251 "parser.c"
        break;
      case 118:
// 1044 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_expr(PHQL_T_LESSEQUAL, yymsp[-2].minor.yy10, yymsp[0].minor.yy10);
  yy_destructor(7,&yymsp[-1].minor);
}
// 2259 "parser.c"
        break;
      case 119:
// 1048 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_expr(PHQL_T_LIKE, yymsp[-2].minor.yy10, yymsp[0].minor.yy10);
  yy_destructor(10,&yymsp[-1].minor);
}
// 2267 "parser.c"
        break;
      case 120:
// 1052 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_expr(PHQL_T_NLIKE, yymsp[-3].minor.yy10, yymsp[0].minor.yy10);
  yy_destructor(21,&yymsp[-2].minor);
  yy_destructor(10,&yymsp[-1].minor);
}
// 2276 "parser.c"
        break;
      case 121:
// 1056 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_expr(PHQL_T_IN, yymsp[-4].minor.yy10, yymsp[-1].minor.yy10);
  yy_destructor(19,&yymsp[-3].minor);
  yy_destructor(39,&yymsp[-2].minor);
  yy_destructor(40,&yymsp[0].minor);
}
// 2286 "parser.c"
        break;
      case 122:
// 1060 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_expr(PHQL_T_NOTIN, yymsp[-5].minor.yy10, yymsp[-1].minor.yy10);
  yy_destructor(21,&yymsp[-4].minor);
  yy_destructor(19,&yymsp[-3].minor);
  yy_destructor(39,&yymsp[-2].minor);
  yy_destructor(40,&yymsp[0].minor);
}
// 2297 "parser.c"
        break;
      case 124:
// 1070 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_func_call(yymsp[-3].minor.yy0, yymsp[-1].minor.yy10);
  yy_destructor(39,&yymsp[-2].minor);
  yy_destructor(40,&yymsp[0].minor);
}
// 2306 "parser.c"
        break;
      case 125:
// 1074 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_func_call(yymsp[-2].minor.yy0, NULL);
  yy_destructor(39,&yymsp[-1].minor);
  yy_destructor(40,&yymsp[0].minor);
}
// 2315 "parser.c"
        break;
      case 127:
// 1084 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_zval_list(yymsp[0].minor.yy10, NULL);
}
// 2322 "parser.c"
        break;
      case 130:
// 1098 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_expr(PHQL_T_ISNULL, yymsp[-2].minor.yy10, NULL);
  yy_destructor(18,&yymsp[-1].minor);
  yy_destructor(54,&yymsp[0].minor);
}
// 2331 "parser.c"
        break;
      case 131:
// 1102 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_expr(PHQL_T_ISNOTNULL, yymsp[-3].minor.yy10, NULL);
  yy_destructor(18,&yymsp[-2].minor);
  yy_destructor(21,&yymsp[-1].minor);
  yy_destructor(54,&yymsp[0].minor);
}
// 2341 "parser.c"
        break;
      case 132:
// 1106 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_expr(PHQL_T_DISTINCT, NULL, yymsp[0].minor.yy10);
  yy_destructor(20,&yymsp[-1].minor);
}
// 2349 "parser.c"
        break;
      case 133:
// 1110 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_expr(PHQL_T_BETWEEN, yymsp[-2].minor.yy10, yymsp[0].minor.yy10);
  yy_destructor(1,&yymsp[-1].minor);
}
// 2357 "parser.c"
        break;
      case 134:
// 1114 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_expr(PHQL_T_NOT, NULL, yymsp[0].minor.yy10);
  yy_destructor(21,&yymsp[-1].minor);
}
// 2365 "parser.c"
        break;
      case 135:
// 1118 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_expr(PHQL_T_ENCLOSED, yymsp[-1].minor.yy10, NULL);
  yy_destructor(39,&yymsp[-2].minor);
  yy_destructor(40,&yymsp[0].minor);
}
// 2374 "parser.c"
        break;
      case 138:
// 1130 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_literal_zval(PHQL_T_STRING, yymsp[0].minor.yy0);
}
// 2381 "parser.c"
        break;
      case 139:
// 1134 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_literal_zval(PHQL_T_DOUBLE, yymsp[0].minor.yy0);
}
// 2388 "parser.c"
        break;
      case 140:
// 1138 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_literal_zval(PHQL_T_NULL, NULL);
  yy_destructor(54,&yymsp[0].minor);
}
// 2396 "parser.c"
        break;
      case 141:
// 1142 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_placeholder_zval(PHQL_T_NPLACEHOLDER, yymsp[0].minor.yy0);
}
// 2403 "parser.c"
        break;
      case 142:
// 1146 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_placeholder_zval(PHQL_T_SPLACEHOLDER, yymsp[0].minor.yy0);
}
// 2410 "parser.c"
        break;
      case 143:
// 1152 "parser.lemon"
{
	yygotominor.yy10 = phql_ret_qualified_name(yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(26,&yymsp[-1].minor);
}
// 2418 "parser.c"
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
// 419 "parser.lemon"

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

// 2527 "parser.c"
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
		length = 32 + state->start_length;
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

	if(phql_internal_parse_phql(&result, Z_STRVAL_P(phql), Z_STRLEN_P(phql), &error_msg TSRMLS_CC) == FAILURE){
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

	if (!phql) {
		PHALCON_INIT_VAR(*error_msg);
		ZVAL_STRING(*error_msg, "PHQL statement cannot be NULL", 1);
		return FAILURE;
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

	while(0 <= (scanner_status = phql_get_token(state, &token))) {

		/* Calculate the 'start' length */
		state->start_length = (phql + phql_length - state->start);

		state->active_token = token.opcode;

		/* Parse the token found */
		switch(token.opcode){

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
			case PHQL_T_BITWISE_AND:
				phql_(phql_parser, PHQL_BITWISE_AND, NULL, parser_status);
				break;
			case PHQL_T_BITWISE_OR:
				phql_(phql_parser, PHQL_BITWISE_OR, NULL, parser_status);
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
			} else {
				efree(parser_status->ret);
			}
		}
	}

	efree(parser_status);
	efree(state);

	return status;
}