/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is include which follows the "include" declaration
** in the input file. */
#include <stdio.h>
// 39 "parser.lemon"


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
	array_init_size(ret, 2);
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
	array_init_size(ret, 4);

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
	array_init_size(ret, 5);

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

static zval *phql_ret_select_clause(zval *distinct, zval *columns, zval *tables, zval *join_list)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	if (distinct) {
		add_assoc_zval(ret, "distinct", distinct);
	}

	add_assoc_zval(ret, "columns", columns);
	add_assoc_zval(ret, "tables", tables);
	if (join_list) {
		add_assoc_zval(ret, "joins", join_list);
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

static zval *phql_ret_func_call(phql_parser_token *name, zval *arguments, zval *distinct)
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

	if (distinct) {
		add_assoc_zval(ret, "distinct", distinct);
	}

	return ret;
}


// 443 "parser.c"
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
**    PPCODETYPE         is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 terminals
**                       and nonterminals.  "int" is used otherwise.
**    PPNOCODE           is a number of type PPCODETYPE which corresponds
**                       to no legal terminal or nonterminal number.  This
**                       number is used to fill in empty slots of the hash 
**                       table.
**    PPFALLBACK         If defined, this indicates that one or more tokens
**                       have fall-back values which should be used if the
**                       original value of the token will not parse.
**    PPACTIONTYPE       is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 rules and
**                       states combined.  "int" is used otherwise.
**    phql_TOKENTYPE     is the data type used for minor tokens given 
**                       directly to the parser from the tokenizer.
**    PPMINORTYPE        is the data type used for all minor tokens.
**                       This is typically a union of many types, one of
**                       which is phql_TOKENTYPE.  The entry in the union
**                       for base tokens is called "pp0".
**    PPSTACKDEPTH       is the maximum depth of the parser's stack.
**    phql_ARG_SDECL     A static variable declaration for the %extra_argument
**    phql_ARG_PDECL     A parameter declaration for the %extra_argument
**    phql_ARG_STORE     Code to store %extra_argument into pppParser
**    phql_ARG_FETCH     Code to extract %extra_argument from pppParser
**    PPNSTATE           the combined number of states.
**    PPNRULE            the number of rules in the grammar
**    PPERRORSYMBOL      is the code number of the error symbol.  If not
**                       defined, then do no error processing.
*/
#define PPCODETYPE unsigned char
#define PPNOCODE 126
#define PPACTIONTYPE unsigned short int
#define phql_TOKENTYPE phql_parser_token*
typedef union {
  phql_TOKENTYPE pp0;
  zval* pp158;
  int pp251;
} PPMINORTYPE;
#define PPSTACKDEPTH 100
#define phql_ARG_SDECL phql_parser_status *status;
#define phql_ARG_PDECL ,phql_parser_status *status
#define phql_ARG_FETCH phql_parser_status *status = pppParser->status
#define phql_ARG_STORE pppParser->status = status
#define PPNSTATE 265
#define PPNRULE 145
#define PPERRORSYMBOL 74
#define PPERRSYMDT pp251
#define PP_NO_ACTION      (PPNSTATE+PPNRULE+2)
#define PP_ACCEPT_ACTION  (PPNSTATE+PPNRULE+1)
#define PP_ERROR_ACTION   (PPNSTATE+PPNRULE)

/* Next are that tables used to determine what action to take based on the
** current state and lookahead token.  These tables are used to implement
** functions that take a state number and lookahead value and return an
** action integer.  
**
** Suppose the action integer is N.  Then the action is determined as
** follows
**
**   0 <= N < PPNSTATE                  Shift N.  That is, push the lookahead
**                                      token onto the stack and goto state N.
**
**   PPNSTATE <= N < PPNSTATE+PPNRULE   Reduce by rule N-PPNSTATE.
**
**   N == PPNSTATE+PPNRULE              A syntax error has occurred.
**
**   N == PPNSTATE+PPNRULE+1            The parser accepts its input.
**
**   N == PPNSTATE+PPNRULE+2            No such action.  Denotes unused
**                                      slots in the pp_action[] table.
**
** The action table is constructed as a single large table named pp_action[].
** Given state S and lookahead X, the action is computed as
**
**      pp_action[ pp_shift_ofst[S] + X ]
**
** If the index value pp_shift_ofst[S]+X is out of range or if the value
** pp_lookahead[pp_shift_ofst[S]+X] is not equal to X or if pp_shift_ofst[S]
** is equal to PP_SHIFT_USE_DFLT, it means that the action is not in the table
** and that pp_default[S] should be used instead.  
**
** The formula above is for computing the action when the lookahead is
** a terminal symbol.  If the lookahead is a non-terminal (as occurs after
** a reduce action) then the pp_reduce_ofst[] array is used in place of
** the pp_shift_ofst[] array and PP_REDUCE_USE_DFLT is used in place of
** PP_SHIFT_USE_DFLT.
**
** The following are the tables generated in this section:
**
**  pp_action[]        A single table containing all actions.
**  pp_lookahead[]     A table containing the lookahead for each entry in
**                     pp_action.  Used to detect hash collisions.
**  pp_shift_ofst[]    For each state, the offset into pp_action for
**                     shifting terminals.
**  pp_reduce_ofst[]   For each state, the offset into pp_action for
**                     shifting non-terminals after a reduce.
**  pp_default[]       Default action for each state.
*/
static PPACTIONTYPE pp_action[] = {
 /*     0 */    96,  102,   50,   52,   54,   56,   58,   60,   40,   42,
 /*    10 */    62,   67,   44,   46,   48,   36,   34,   38,   32,   29,
 /*    20 */    98,   69,   64,   64,   96,  102,   50,   52,   54,   56,
 /*    30 */    58,   60,   40,   42,   62,   67,   44,   46,   48,   36,
 /*    40 */    34,   38,   32,   29,   98,   69,   64,   98,   69,   64,
 /*    50 */   111,   27,   28,  192,    6,  190,   22,   96,  102,   50,
 /*    60 */    52,   54,   56,   58,   60,   40,   42,   62,   67,   44,
 /*    70 */    46,   48,   36,   34,   38,   32,   29,   98,   69,   64,
 /*    80 */    96,  102,   50,   52,   54,   56,   58,   60,   40,   42,
 /*    90 */    62,   67,   44,   46,   48,   36,   34,   38,   32,   29,
 /*   100 */    98,   69,   64,   40,   42,   62,   67,   44,   46,   48,
 /*   110 */    36,   34,   38,   32,   29,   98,   69,   64,  224,  232,
 /*   120 */   122,   20,   96,  102,   50,   52,   54,   56,   58,   60,
 /*   130 */    40,   42,   62,   67,   44,   46,   48,   36,   34,   38,
 /*   140 */    32,   29,   98,   69,   64,  253,  254,  132,   32,   29,
 /*   150 */    98,   69,   64,  116,  100,   96,  102,   50,   52,   54,
 /*   160 */    56,   58,   60,   40,   42,   62,   67,   44,   46,   48,
 /*   170 */    36,   34,   38,   32,   29,   98,   69,   64,   50,   52,
 /*   180 */    54,   56,   58,   60,   40,   42,   62,   67,   44,   46,
 /*   190 */    48,   36,   34,   38,   32,   29,   98,   69,   64,  106,
 /*   200 */    99,   96,  102,   50,   52,   54,   56,   58,   60,   40,
 /*   210 */    42,   62,   67,   44,   46,   48,   36,   34,   38,   32,
 /*   220 */    29,   98,   69,   64,   96,  102,   50,   52,   54,   56,
 /*   230 */    58,   60,   40,   42,   62,   67,   44,   46,   48,   36,
 /*   240 */    34,   38,   32,   29,   98,   69,   64,  144,   75,   91,
 /*   250 */    30,  345,  182,  145,  147,  187,   71,   79,   21,   76,
 /*   260 */   135,   83,   77,   87,  181,   89,   90,  130,  136,   83,
 /*   270 */   164,  180,  166,  168,  104,  172,  176,  411,    1,    2,
 /*   280 */     3,    4,    5,    6,  127,  160,  138,  217,  150,  156,
 /*   290 */   157,  109,  113,  119,    9,  125,   16,   17,   18,  153,
 /*   300 */   151,  152,  154,  155,  149,  149,  144,  246,  243,   30,
 /*   310 */   214,  218,  145,  147,  259,  134,  134,   31,  143,  135,
 /*   320 */    44,   46,   48,   36,   34,   38,   32,   29,   98,   69,
 /*   330 */    64,  188,   85,  104,  388,  149,   36,   34,   38,   32,
 /*   340 */    29,   98,   69,   64,   86,  136,  134,  150,  156,  157,
 /*   350 */   109,  113,  119,  179,  125,  230,  177,  159,  153,  151,
 /*   360 */   152,  154,  155,  228,  226,  185,  137,  231,   30,   26,
 /*   370 */   257,  145,  147,  149,  164,  180,  166,  168,  186,  172,
 /*   380 */   176,  206,  228,  227,  134,    6,  300,  149,  149,  256,
 /*   390 */    23,  209,  104,  184,  189,  301,  138,   14,  134,  134,
 /*   400 */   198,  107,  238,   86,    6,    6,  150,  156,  157,  109,
 /*   410 */   113,  119,  149,  125,  149,  138,  105,  153,  151,  152,
 /*   420 */   154,  155,  204,  134,  144,  134,  223,   30,  158,   19,
 /*   430 */   145,  147,  138,  149,  149,   65,  200,  135,   83,  171,
 /*   440 */    71,  196,  169,   85,  134,  134,  202,  158,  128,  130,
 /*   450 */   149,  104,  299,  140,   78,  221,  194,  195,  141,   79,
 /*   460 */   248,  134,  262,  139,  158,  150,  156,  157,  109,  113,
 /*   470 */   119,   83,  125,  230,  178,   15,  153,  151,  152,  154,
 /*   480 */   155,  183,  237,   74,  142,  231,   30,  115,   84,  145,
 /*   490 */   147,  149,   71,   26,  230,  233,  135,   73,  242,  191,
 /*   500 */   193,  189,  134,  103,  205,  149,  229,  251,  258,  254,
 /*   510 */   104,  149,  149,   94,  175,   25,  134,  173,   82,  149,
 /*   520 */    80,  149,  134,  134,  150,  156,  157,  109,  113,  119,
 /*   530 */   134,  125,  134,  217,   95,  153,  151,  152,  154,  155,
 /*   540 */   163,  249,  161,   47,  239,   30,   79,   68,  145,  147,
 /*   550 */    93,  149,  149,  211,  266,  135,   92,  216,   83,  268,
 /*   560 */    41,  149,  134,  134,  234,  149,   88,   89,   90,  104,
 /*   570 */   298,  149,  134,  142,  264,  297,  134,   13,  149,   79,
 /*   580 */   199,  269,  134,  150,  156,  157,  109,  113,  119,  134,
 /*   590 */   125,   83,  174,  387,  153,  151,  152,  154,  155,   62,
 /*   600 */    67,   44,   46,   48,   36,   34,   38,   32,   29,   98,
 /*   610 */    69,   64,   49,   81,  208,   97,   35,  203,  121,   66,
 /*   620 */    43,  220,   63,  265,   51,  101,  296,  207,  201,  295,
 /*   630 */   149,  170,  149,  149,  149,  213,  149,  149,  149,  149,
 /*   640 */   149,  134,  149,  134,  134,  134,  149,  134,  134,  134,
 /*   650 */   134,  134,  294,  134,   33,  148,  126,  134,   61,   53,
 /*   660 */   146,  131,   59,  215,  133,  167,  142,  267,  219,  108,
 /*   670 */   293,   11,  149,  149,  149,  222,  149,  149,  149,  149,
 /*   680 */   149,   55,  149,  134,  134,  134,  197,  134,  134,  134,
 /*   690 */   134,  134,  165,  134,   57,   39,   45,   37,  110,  149,
 /*   700 */     7,   71,  112,  225,  304,  114,  162,  212,   72,  241,
 /*   710 */   134,  235,  149,  149,  149,  149,  236,   70,   12,  117,
 /*   720 */   305,  240,  118,  134,  134,  134,  134,    8,   24,  120,
 /*   730 */   244,  312,  245,  344,  247,  250,  252,  123,  210,  255,
 /*   740 */   124,   10,  260,  261,  318,  263,  129,
};
static PPCODETYPE pp_lookahead[] = {
 /*     0 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    10 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*    20 */    21,   22,   23,   23,    1,    2,    3,    4,    5,    6,
 /*    30 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*    40 */    17,   18,   19,   20,   21,   22,   23,   21,   22,   23,
 /*    50 */    77,   52,   53,   30,   81,   32,   51,    1,    2,    3,
 /*    60 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*    70 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*    80 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    90 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   100 */    21,   22,   23,    9,   10,   11,   12,   13,   14,   15,
 /*   110 */    16,   17,   18,   19,   20,   21,   22,   23,   43,   44,
 /*   120 */    64,  117,    1,    2,    3,    4,    5,    6,    7,    8,
 /*   130 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   140 */    19,   20,   21,   22,   23,  109,  110,   68,   19,   20,
 /*   150 */    21,   22,   23,   32,   23,    1,    2,    3,    4,    5,
 /*   160 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   170 */    16,   17,   18,   19,   20,   21,   22,   23,    3,    4,
 /*   180 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   190 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   45,
 /*   200 */    69,    1,    2,    3,    4,    5,    6,    7,    8,    9,
 /*   210 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   220 */    20,   21,   22,   23,    1,    2,    3,    4,    5,    6,
 /*   230 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   240 */    17,   18,   19,   20,   21,   22,   23,   17,   89,   98,
 /*   250 */    20,    0,   93,   23,   24,   31,   26,   98,   50,   90,
 /*   260 */    30,  110,   25,   94,   95,   96,   97,   67,   44,  110,
 /*   270 */    33,   34,   35,   36,   44,   38,   39,   75,   76,   77,
 /*   280 */    78,   79,   80,   81,  119,  120,   92,   92,   58,   59,
 /*   290 */    60,   61,   62,   63,   84,   65,   58,   59,   60,   69,
 /*   300 */    70,   71,   72,   73,  110,  110,   17,   56,  106,   20,
 /*   310 */   115,  116,   23,   24,  112,  121,  121,   92,  124,   30,
 /*   320 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   330 */    23,   17,   31,   44,   45,  110,   16,   17,   18,   19,
 /*   340 */    20,   21,   22,   23,   30,   44,  121,   58,   59,   60,
 /*   350 */    61,   62,   63,   34,   65,   92,   37,   28,   69,   70,
 /*   360 */    71,   72,   73,   25,  101,   17,  122,  104,   20,   92,
 /*   370 */    92,   23,   24,  110,   33,   34,   35,   36,   30,   38,
 /*   380 */    39,   77,   25,   45,  121,   81,   30,  110,  110,  111,
 /*   390 */   113,  114,   44,   91,   92,   30,   92,   25,  121,  121,
 /*   400 */    77,   77,   45,   30,   81,   81,   58,   59,   60,   61,
 /*   410 */    62,   63,  110,   65,  110,   92,   92,   69,   70,   71,
 /*   420 */    72,   73,  118,  121,   17,  121,   98,   20,  124,   57,
 /*   430 */    23,   24,   92,  110,  110,   11,   12,   30,  110,   34,
 /*   440 */    26,  118,   37,   31,  121,  121,   22,  124,   66,   67,
 /*   450 */   110,   44,   30,   45,   93,   41,   28,   29,  118,   98,
 /*   460 */    46,  121,   48,  123,  124,   58,   59,   60,   61,   62,
 /*   470 */    63,  110,   65,   92,   34,  117,   69,   70,   71,   72,
 /*   480 */    73,   25,  101,   27,   25,  104,   20,   92,   30,   23,
 /*   490 */    24,  110,   26,   92,   92,  102,   30,   88,  105,   30,
 /*   500 */    91,   92,  121,   92,   45,  110,  104,  108,  109,  110,
 /*   510 */    44,  110,  110,   40,   34,  114,  121,   37,   30,  110,
 /*   520 */    32,  110,  121,  121,   58,   59,   60,   61,   62,   63,
 /*   530 */   121,   65,  121,   92,   92,   69,   70,   71,   72,   73,
 /*   540 */    30,   93,   32,   92,   25,   20,   98,   92,   23,   24,
 /*   550 */   100,  110,  110,   92,    0,   30,   99,  116,  110,    0,
 /*   560 */    92,  110,  121,  121,   45,  110,   95,   96,   97,   44,
 /*   570 */    30,  110,  121,   25,   93,   30,  121,  117,  110,   98,
 /*   580 */    45,    0,  121,   58,   59,   60,   61,   62,   63,  121,
 /*   590 */    65,  110,   34,   45,   69,   70,   71,   72,   73,   11,
 /*   600 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   610 */    22,   23,   92,   30,   92,   92,   92,   44,   92,   92,
 /*   620 */    92,   92,   92,    0,   92,   69,   30,   45,   92,   30,
 /*   630 */   110,   34,  110,  110,  110,   51,  110,  110,  110,  110,
 /*   640 */   110,  121,  110,  121,  121,  121,  110,  121,  121,  121,
 /*   650 */   121,  121,   30,  121,   92,   92,   92,  121,   92,   92,
 /*   660 */    92,   92,   92,   25,   92,   34,   25,    0,   49,   45,
 /*   670 */    30,   86,  110,  110,  110,   42,  110,  110,  110,  110,
 /*   680 */   110,   92,  110,  121,  121,  121,   45,  121,  121,  121,
 /*   690 */   121,  121,   34,  121,   92,   92,   92,   92,   44,  110,
 /*   700 */    82,   26,   45,   44,    0,   44,   30,   54,   87,   30,
 /*   710 */   121,   43,  110,  110,  110,  110,   44,   44,   56,   30,
 /*   720 */     0,  105,   45,  121,  121,  121,  121,   83,   25,   44,
 /*   730 */    82,    0,  107,    0,  117,   47,   25,   30,   55,    3,
 /*   740 */    45,   85,   82,  107,    0,   27,  120,
};
#define PP_SHIFT_USE_DFLT (-2)
static short pp_shift_ofst[] = {
 /*     0 */   414,  623,  554,  667,  559,  581,  619,  653,  683,  208,
 /*    10 */   662,   -2,  238,  372,  238,   -2,   -2,   -2,   -2,  238,
 /*    20 */    -2,    5,  525,  703,  525,   -2,   -1,   -2,   -2,  525,
 /*    30 */   525,   26,  525,   26,  525,  129,  525,  129,  525,  129,
 /*    40 */   525,  588,  525,  588,  525,  320,  525,  320,  525,  320,
 /*    50 */   525,   94,  525,   94,  525,   94,  525,   94,  525,   94,
 /*    60 */   525,   94,  525,  307,  424,  525,    0,  525,  307,  673,
 /*    70 */   230,  428,  348,  456,  458,  237,   -2,  458,   -2,  488,
 /*    80 */   583,   -2,   -2,   -2,  412,  373,   -2,  341,   -2,   -2,
 /*    90 */   458,  510,  473,   -2,  525,  223,  525,  223,  131,   -2,
 /*   100 */   556,   -2,  525,  175,  466,  154,   -2,  624,   -2,  654,
 /*   110 */   675,  657,   -2,  661,  525,  121,  689,  677,   -2,  685,
 /*   120 */   525,   56,  707,  695,   -2,  525,  200,  382,   -2,   -2,
 /*   130 */   525,   79,  525,  223,   -2,  301,  329,  289,  223,  408,
 /*   140 */    -2,  548,  407,   -2,   -2,  525,    0,  525,    0,   -2,
 /*   150 */    -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,
 /*   160 */    -2,  676,   -2,   -2,  658,  640,  631,  622,  405,  597,
 /*   170 */   599,  596,  480,  558,  545,  540,  319,  440,  422,  356,
 /*   180 */   365,   -2,   -2,  348,   -2,   -2,  224,  314,   -2,   23,
 /*   190 */   469,   -2,   -2,   -2,   -2,   -2,  641,   -2,  535,   -2,
 /*   200 */   525,    0,  573,  230,  459,   -2,  582,   -2,   26,   -2,
 /*   210 */   525,  223,  584,  525,  638,  525,   -2,  223,   -2,  525,
 /*   220 */   223,  633,  458,   75,  659,  525,  338,  704,  525,   -2,
 /*   230 */   223,   -2,  679,  519,  668,  672,  525,  357,  720,  679,
 /*   240 */    -2,   -2,   -2,  619,  251,  731,  238,  733,  458,  688,
 /*   250 */   458,  711,  458,   -2,  736,  525,   -2,  223,   -2,  619,
 /*   260 */   251,  744,  718,  458,   -2,
};
#define PP_REDUCE_USE_DFLT (-28)
static short pp_reduce_ofst[] = {
 /*     0 */   202,  -28,  -28,  -28,  -28,  -28,  618,  644,  210,  656,
 /*    10 */   585,  -28,  460,  -28,  358,  -28,  -28,  -28,  -28,    4,
 /*    20 */   -28,  -28,  277,  -28,  401,  -28,  -28,  -28,  -28,  522,
 /*    30 */   225,  -28,  562,  -28,  524,  -28,  605,  -28,  603,  -28,
 /*    40 */   468,  -28,  528,  -28,  604,  -28,  451,  -28,  520,  -28,
 /*    50 */   532,  -28,  567,  -28,  589,  -28,  602,  -28,  570,  -28,
 /*    60 */   566,  -28,  530,  -28,  -28,  527,  -28,  455,  -28,  -28,
 /*    70 */   323,  621,  409,  -28,  159,  169,  -28,  361,  -28,  -28,
 /*    80 */   -28,  -28,  -28,  -28,  -28,  -28,  -28,  471,  -28,  -28,
 /*    90 */   151,  457,  450,  -28,  442,  -28,  523,  -28,  -28,  -28,
 /*   100 */   -28,  -28,  411,  -28,  324,  -28,  -28,  -28,  -28,  -28,
 /*   110 */   -27,  -28,  -28,  -28,  395,  -28,  -28,  -28,  -28,  -28,
 /*   120 */   526,  -28,  -28,  -28,  -28,  564,  165,  626,  -28,  -28,
 /*   130 */   569,  -28,  572,  -28,  -28,  -28,  244,  340,  -28,  -28,
 /*   140 */   -28,  -28,  194,  -28,  -28,  568,  -28,  563,  -28,  -28,
 /*   150 */   -28,  -28,  -28,  -28,  -28,  -28,  -28,  -28,  -28,  -28,
 /*   160 */   -28,  -28,  -28,  -28,  -28,  -28,  -28,  -28,  -28,  -28,
 /*   170 */   -28,  -28,  -28,  -28,  -28,  -28,  -28,  -28,  -28,  -28,
 /*   180 */   -28,  -28,  -28,  302,  -28,  -28,  -28,  -28,  -28,  -28,
 /*   190 */   -28,  -28,  -28,  -28,  -28,  -28,  -28,  -28,  -28,  -28,
 /*   200 */   536,  -28,  -28,  304,  -28,  -28,  -28,  -28,  -28,  -28,
 /*   210 */   461,  -28,  -28,  195,  -28,  441,  -28,  -28,  -28,  529,
 /*   220 */   -28,  -28,  328,  -28,  -28,  263,  -28,  -28,  402,  -28,
 /*   230 */   -28,  -28,  393,  -28,  -28,  -28,  381,  -28,  -28,  616,
 /*   240 */   -28,  -28,  -28,  648,  625,  -28,  617,  -28,  448,  -28,
 /*   250 */   399,  -28,   36,  -28,  -28,  278,  -28,  -28,  -28,  660,
 /*   260 */   636,  -28,  -28,  481,  -28,
};
static PPACTIONTYPE pp_default[] = {
 /*     0 */   410,  410,  410,  410,  410,  410,  325,  334,  339,  327,
 /*    10 */   343,  270,  410,  340,  410,  341,  346,  347,  348,  410,
 /*    20 */   342,  410,  410,  326,  410,  328,  330,  331,  332,  410,
 /*    30 */   410,  349,  410,  351,  410,  352,  410,  353,  410,  354,
 /*    40 */   410,  355,  410,  356,  410,  357,  410,  358,  410,  359,
 /*    50 */   410,  360,  410,  361,  410,  362,  410,  363,  410,  364,
 /*    60 */   410,  365,  410,  366,  410,  410,  367,  410,  368,  410,
 /*    70 */   410,  274,  410,  410,  410,  285,  271,  410,  282,  322,
 /*    80 */   410,  320,  321,  323,  409,  410,  408,  284,  286,  288,
 /*    90 */   410,  292,  303,  289,  410,  302,  410,  376,  410,  393,
 /*   100 */   410,  394,  410,  395,  410,  410,  398,  410,  372,  410,
 /*   110 */   410,  410,  375,  410,  410,  410,  410,  410,  377,  410,
 /*   120 */   410,  410,  410,  410,  378,  410,  410,  410,  379,  380,
 /*   130 */   410,  410,  410,  382,  383,  409,  386,  410,  392,  410,
 /*   140 */   384,  410,  410,  389,  391,  410,  396,  410,  397,  399,
 /*   150 */   400,  401,  402,  403,  404,  405,  406,  407,  390,  385,
 /*   160 */   381,  410,  290,  291,  410,  410,  410,  410,  410,  410,
 /*   170 */   410,  410,  410,  410,  410,  410,  410,  410,  410,  410,
 /*   180 */   410,  287,  283,  410,  275,  277,  409,  410,  278,  281,
 /*   190 */   410,  279,  280,  276,  272,  273,  410,  370,  410,  373,
 /*   200 */   410,  369,  410,  410,  410,  371,  410,  374,  350,  329,
 /*   210 */   410,  338,  410,  410,  333,  410,  335,  337,  336,  410,
 /*   220 */   324,  410,  410,  410,  410,  410,  410,  410,  410,  306,
 /*   230 */   308,  307,  410,  410,  410,  410,  410,  410,  410,  410,
 /*   240 */   309,  311,  310,  325,  410,  410,  410,  410,  410,  410,
 /*   250 */   410,  313,  410,  314,  410,  410,  316,  317,  315,  325,
 /*   260 */   410,  410,  410,  410,  319,
};
#define PP_SZ_ACTTAB (sizeof(pp_action)/sizeof(pp_action[0]))

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
#ifdef PPFALLBACK
static const PPCODETYPE ppFallback[] = {
};
#endif /* PPFALLBACK */

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
struct ppStackEntry {
  int stateno;       /* The state-number */
  int major;         /* The major token value.  This is the code
                     ** number for the token at this stack level */
  PPMINORTYPE minor; /* The user-supplied minor token value.  This
                     ** is the value of the token  */
};
typedef struct ppStackEntry ppStackEntry;

/* The state of the parser is completely contained in an instance of
** the following structure */
struct ppParser {
  int ppidx;                    /* Index of top element in stack */
  int pperrcnt;                 /* Shifts left before out of the error */
  phql_ARG_SDECL                /* A place to hold %extra_argument */
  ppStackEntry ppstack[PPSTACKDEPTH];  /* The parser's stack */
};
typedef struct ppParser ppParser;

#ifndef NDEBUG
#include <stdio.h>
static FILE *ppTraceFILE = 0;
static char *ppTracePrompt = 0;
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
  ppTraceFILE = TraceFILE;
  ppTracePrompt = zTracePrompt;
  if( ppTraceFILE==0 ) ppTracePrompt = 0;
  else if( ppTracePrompt==0 ) ppTraceFILE = 0;
}
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing shifts, the names of all terminals and nonterminals
** are required.  The following table supplies these names */
static const char *ppTokenName[] = { 
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
  "SPLACEHOLDER",  "EXISTS",        "CAST",          "CONVERT",     
  "USING",         "CASE",          "END",           "WHEN",        
  "THEN",          "NULL",          "STRING",        "DOUBLE",      
  "TRUE",          "FALSE",         "error",         "program",     
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
  "group_item",    "integer_or_placeholder",  "argument_list",  "when_clauses",
  "when_clause",   "function_call",  "distinct_or_null",  "argument_list_or_null",
  "argument_item",
};
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing reduce actions, the names of all rules are required.
*/
static const char *ppRuleName[] = {
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
 /* 107 */ "expr ::= PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 108 */ "expr ::= expr IN PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 109 */ "expr ::= expr NOT IN PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 110 */ "expr ::= EXISTS PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 111 */ "expr ::= expr AGAINST expr",
 /* 112 */ "expr ::= CAST PARENTHESES_OPEN expr AS IDENTIFIER PARENTHESES_CLOSE",
 /* 113 */ "expr ::= CONVERT PARENTHESES_OPEN expr USING IDENTIFIER PARENTHESES_CLOSE",
 /* 114 */ "expr ::= CASE expr when_clauses END",
 /* 115 */ "when_clauses ::= when_clauses when_clause",
 /* 116 */ "when_clauses ::= when_clause",
 /* 117 */ "when_clause ::= WHEN expr THEN expr",
 /* 118 */ "expr ::= function_call",
 /* 119 */ "function_call ::= IDENTIFIER PARENTHESES_OPEN distinct_or_null argument_list_or_null PARENTHESES_CLOSE",
 /* 120 */ "distinct_or_null ::= DISTINCT",
 /* 121 */ "distinct_or_null ::=",
 /* 122 */ "argument_list_or_null ::= argument_list",
 /* 123 */ "argument_list_or_null ::=",
 /* 124 */ "argument_list ::= argument_list COMMA argument_item",
 /* 125 */ "argument_list ::= argument_item",
 /* 126 */ "argument_item ::= TIMES",
 /* 127 */ "argument_item ::= expr",
 /* 128 */ "expr ::= expr IS NULL",
 /* 129 */ "expr ::= expr IS NOT NULL",
 /* 130 */ "expr ::= expr BETWEEN expr",
 /* 131 */ "expr ::= NOT expr",
 /* 132 */ "expr ::= BITWISE_NOT expr",
 /* 133 */ "expr ::= PARENTHESES_OPEN expr PARENTHESES_CLOSE",
 /* 134 */ "expr ::= qualified_name",
 /* 135 */ "expr ::= INTEGER",
 /* 136 */ "expr ::= STRING",
 /* 137 */ "expr ::= DOUBLE",
 /* 138 */ "expr ::= NULL",
 /* 139 */ "expr ::= TRUE",
 /* 140 */ "expr ::= FALSE",
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
  if( tokenType>0 && tokenType<(sizeof(ppTokenName)/sizeof(ppTokenName[0])) ){
    return ppTokenName[tokenType];
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
  ppParser *pParser;
  pParser = (ppParser*)(*mallocProc)( (size_t)sizeof(ppParser) );
  if( pParser ){
    pParser->ppidx = -1;
  }
  return pParser;
}

/* The following function deletes the value associated with a
** symbol.  The symbol can be either a terminal or nonterminal.
** "ppmajor" is the symbol code, and "pppminor" is a pointer to
** the value.
*/
static void pp_destructor(PPCODETYPE ppmajor, PPMINORTYPE *pppminor){
  switch( ppmajor ){
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
    case 70:
    case 71:
    case 72:
    case 73:
// 541 "parser.lemon"
{
	if ((pppminor->pp0)) {
		if ((pppminor->pp0)->free_flag) {
			efree((pppminor->pp0)->token);
		}
		efree((pppminor->pp0));
	}
}
// 1211 "parser.c"
      break;
    case 76:
    case 77:
    case 78:
    case 79:
    case 80:
    case 81:
    case 88:
    case 89:
    case 91:
    case 92:
    case 93:
    case 94:
    case 95:
    case 96:
    case 97:
    case 98:
    case 102:
    case 103:
    case 105:
    case 106:
    case 108:
    case 109:
    case 110:
    case 112:
    case 113:
    case 114:
    case 115:
    case 116:
    case 118:
    case 121:
    case 124:
// 554 "parser.lemon"
{ zval_ptr_dtor(&(pppminor->pp158)); }
// 1246 "parser.c"
      break;
    case 82:
    case 83:
    case 84:
    case 85:
    case 86:
    case 87:
    case 99:
    case 100:
    case 107:
    case 122:
    case 123:
// 842 "parser.lemon"
{ zephir_safe_zval_ptr_dtor((pppminor->pp158)); }
// 1261 "parser.c"
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
static int pp_pop_parser_stack(ppParser *pParser){
  PPCODETYPE ppmajor;
  ppStackEntry *pptos = &pParser->ppstack[pParser->ppidx];

  if( pParser->ppidx<0 ) return 0;
#ifndef NDEBUG
  if( ppTraceFILE && pParser->ppidx>=0 ){
    fprintf(ppTraceFILE,"%sPopping %s\n",
      ppTracePrompt,
      ppTokenName[pptos->major]);
  }
#endif
  ppmajor = pptos->major;
  pp_destructor( ppmajor, &pptos->minor);
  pParser->ppidx--;
  return ppmajor;
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
  ppParser *pParser = (ppParser*)p;
  if( pParser==0 ) return;
  while( pParser->ppidx>=0 ) pp_pop_parser_stack(pParser);
  (*freeProc)((void*)pParser);
}

/*
** Find the appropriate action for a parser given the terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is PPNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return PP_NO_ACTION.
*/
static int pp_find_shift_action(
  ppParser *pParser,        /* The parser */
  int iLookAhead            /* The look-ahead token */
){
  int i;
  int stateno = pParser->ppstack[pParser->ppidx].stateno;
 
  /* if( pParser->ppidx<0 ) return PP_NO_ACTION;  */
  i = pp_shift_ofst[stateno];
  if( i==PP_SHIFT_USE_DFLT ){
    return pp_default[stateno];
  }
  if( iLookAhead==PPNOCODE ){
    return PP_NO_ACTION;
  }
  i += iLookAhead;
  if( i<0 || i>=PP_SZ_ACTTAB || pp_lookahead[i]!=iLookAhead ){
#ifdef PPFALLBACK
    int iFallback;            /* Fallback token */
    if( iLookAhead<sizeof(ppFallback)/sizeof(ppFallback[0])
           && (iFallback = ppFallback[iLookAhead])!=0 ){
#ifndef NDEBUG
      if( ppTraceFILE ){
        fprintf(ppTraceFILE, "%sFALLBACK %s => %s\n",
           ppTracePrompt, ppTokenName[iLookAhead], ppTokenName[iFallback]);
      }
#endif
      return pp_find_shift_action(pParser, iFallback);
    }
#endif
    return pp_default[stateno];
  }else{
    return pp_action[i];
  }
}

/*
** Find the appropriate action for a parser given the non-terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is PPNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return PP_NO_ACTION.
*/
static int pp_find_reduce_action(
  ppParser *pParser,        /* The parser */
  int iLookAhead            /* The look-ahead token */
){
  int i;
  int stateno = pParser->ppstack[pParser->ppidx].stateno;
 
  i = pp_reduce_ofst[stateno];
  if( i==PP_REDUCE_USE_DFLT ){
    return pp_default[stateno];
  }
  if( iLookAhead==PPNOCODE ){
    return PP_NO_ACTION;
  }
  i += iLookAhead;
  if( i<0 || i>=PP_SZ_ACTTAB || pp_lookahead[i]!=iLookAhead ){
    return pp_default[stateno];
  }else{
    return pp_action[i];
  }
}

/*
** Perform a shift action.
*/
static void pp_shift(
  ppParser *pppParser,          /* The parser to be shifted */
  int ppNewState,               /* The new state to shift in */
  int ppMajor,                  /* The major token to shift in */
  PPMINORTYPE *pppMinor         /* Pointer ot the minor token to shift in */
){
  ppStackEntry *pptos;
  pppParser->ppidx++;
  if( pppParser->ppidx>=PPSTACKDEPTH ){
     phql_ARG_FETCH;
     pppParser->ppidx--;
#ifndef NDEBUG
     if( ppTraceFILE ){
       fprintf(ppTraceFILE,"%sStack Overflow!\n",ppTracePrompt);
     }
#endif
     while( pppParser->ppidx>=0 ) pp_pop_parser_stack(pppParser);
     /* Here code is inserted which will execute if the parser
     ** stack every overflows */
     phql_ARG_STORE; /* Suppress warning about unused %extra_argument var */
     return;
  }
  pptos = &pppParser->ppstack[pppParser->ppidx];
  pptos->stateno = ppNewState;
  pptos->major = ppMajor;
  pptos->minor = *pppMinor;
#ifndef NDEBUG
  if( ppTraceFILE && pppParser->ppidx>0 ){
    int i;
    fprintf(ppTraceFILE,"%sShift %d\n",ppTracePrompt,ppNewState);
    fprintf(ppTraceFILE,"%sStack:",ppTracePrompt);
    for(i=1; i<=pppParser->ppidx; i++)
      fprintf(ppTraceFILE," %s",ppTokenName[pppParser->ppstack[i].major]);
    fprintf(ppTraceFILE,"\n");
  }
#endif
}

/* The following table contains information about every rule that
** is used during the reduce.
*/
static struct {
  PPCODETYPE lhs;         /* Symbol on the left-hand side of the rule */
  unsigned char nrhs;     /* Number of right-hand side symbols in the rule */
} ppRuleInfo[] = {
  { 75, 1 },
  { 76, 1 },
  { 76, 1 },
  { 76, 1 },
  { 76, 1 },
  { 77, 6 },
  { 81, 6 },
  { 87, 1 },
  { 87, 1 },
  { 87, 0 },
  { 88, 3 },
  { 88, 1 },
  { 91, 1 },
  { 91, 3 },
  { 91, 3 },
  { 91, 2 },
  { 91, 1 },
  { 89, 3 },
  { 89, 1 },
  { 90, 1 },
  { 90, 0 },
  { 94, 2 },
  { 94, 1 },
  { 95, 1 },
  { 96, 4 },
  { 99, 2 },
  { 99, 1 },
  { 99, 0 },
  { 97, 2 },
  { 97, 2 },
  { 97, 3 },
  { 97, 2 },
  { 97, 3 },
  { 97, 2 },
  { 97, 3 },
  { 97, 2 },
  { 97, 1 },
  { 100, 2 },
  { 100, 0 },
  { 78, 7 },
  { 78, 10 },
  { 101, 3 },
  { 101, 1 },
  { 104, 1 },
  { 102, 3 },
  { 102, 1 },
  { 105, 1 },
  { 79, 3 },
  { 106, 4 },
  { 108, 3 },
  { 108, 1 },
  { 109, 3 },
  { 111, 1 },
  { 80, 3 },
  { 112, 3 },
  { 93, 3 },
  { 93, 2 },
  { 93, 1 },
  { 98, 1 },
  { 82, 2 },
  { 82, 0 },
  { 85, 3 },
  { 85, 0 },
  { 113, 3 },
  { 113, 1 },
  { 114, 1 },
  { 114, 2 },
  { 114, 2 },
  { 83, 3 },
  { 83, 0 },
  { 115, 3 },
  { 115, 1 },
  { 116, 1 },
  { 84, 2 },
  { 84, 0 },
  { 86, 2 },
  { 86, 4 },
  { 86, 4 },
  { 86, 0 },
  { 107, 2 },
  { 107, 0 },
  { 117, 1 },
  { 117, 1 },
  { 117, 1 },
  { 92, 2 },
  { 92, 3 },
  { 92, 3 },
  { 92, 3 },
  { 92, 3 },
  { 92, 3 },
  { 92, 3 },
  { 92, 3 },
  { 92, 3 },
  { 92, 3 },
  { 92, 3 },
  { 92, 3 },
  { 92, 3 },
  { 92, 3 },
  { 92, 3 },
  { 92, 3 },
  { 92, 3 },
  { 92, 3 },
  { 92, 4 },
  { 92, 3 },
  { 92, 4 },
  { 92, 5 },
  { 92, 6 },
  { 92, 3 },
  { 92, 5 },
  { 92, 6 },
  { 92, 4 },
  { 92, 3 },
  { 92, 6 },
  { 92, 6 },
  { 92, 4 },
  { 119, 2 },
  { 119, 1 },
  { 120, 4 },
  { 92, 1 },
  { 121, 5 },
  { 122, 1 },
  { 122, 0 },
  { 123, 1 },
  { 123, 0 },
  { 118, 3 },
  { 118, 1 },
  { 124, 1 },
  { 124, 1 },
  { 92, 3 },
  { 92, 4 },
  { 92, 3 },
  { 92, 2 },
  { 92, 2 },
  { 92, 3 },
  { 92, 1 },
  { 92, 1 },
  { 92, 1 },
  { 92, 1 },
  { 92, 1 },
  { 92, 1 },
  { 92, 1 },
  { 92, 1 },
  { 92, 1 },
  { 110, 3 },
  { 110, 1 },
};

static void pp_accept(ppParser*);  /* Forward Declaration */

/*
** Perform a reduce action and the shift that must immediately
** follow the reduce.
*/
static void pp_reduce(
  ppParser *pppParser,         /* The parser */
  int ppruleno                 /* Number of the rule by which to reduce */
){
  int ppgoto;                     /* The next state */
  int ppact;                      /* The next action */
  PPMINORTYPE ppgotominor;        /* The LHS of the rule reduced */
  ppStackEntry *ppmsp;            /* The top of the parser's stack */
  int ppsize;                     /* Amount to pop the stack */
  phql_ARG_FETCH;
  ppmsp = &pppParser->ppstack[pppParser->ppidx];
#ifndef NDEBUG
  if( ppTraceFILE && ppruleno>=0 
        && ppruleno<sizeof(ppRuleName)/sizeof(ppRuleName[0]) ){
    fprintf(ppTraceFILE, "%sReduce [%s].\n", ppTracePrompt,
      ppRuleName[ppruleno]);
  }
#endif /* NDEBUG */

  switch( ppruleno ){
  /* Beginning here are the reduction cases.  A typical example
  ** follows:
  **   case 0:
  **  // <lineno> <grammarfile>
  **     { ... }           // User supplied code
  **  // <lineno> <thisfile>
  **     break;
  */
      case 0:
// 550 "parser.lemon"
{
	status->ret = ppmsp[0].minor.pp158;
}
// 1623 "parser.c"
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
      case 118:
      case 122:
      case 127:
      case 134:
// 556 "parser.lemon"
{
	ppgotominor.pp158 = ppmsp[0].minor.pp158;
}
// 1648 "parser.c"
        break;
      case 5:
// 574 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_select_statement(ppmsp[-5].minor.pp158, ppmsp[-4].minor.pp158, ppmsp[-1].minor.pp158, ppmsp[-3].minor.pp158, ppmsp[-2].minor.pp158, ppmsp[0].minor.pp158);
}
// 1655 "parser.c"
        break;
      case 6:
// 580 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_select_clause(ppmsp[-4].minor.pp158, ppmsp[-3].minor.pp158, ppmsp[-1].minor.pp158, ppmsp[0].minor.pp158);
  pp_destructor(26,&ppmsp[-5].minor);
  pp_destructor(27,&ppmsp[-2].minor);
}
// 1664 "parser.c"
        break;
      case 7:
// 586 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_distinct_all(1);
  pp_destructor(28,&ppmsp[0].minor);
}
// 1672 "parser.c"
        break;
      case 8:
// 590 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_distinct_all(0);
  pp_destructor(29,&ppmsp[0].minor);
}
// 1680 "parser.c"
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
      case 121:
      case 123:
// 594 "parser.lemon"
{
	ppgotominor.pp158 = NULL;
}
// 1698 "parser.c"
        break;
      case 10:
      case 17:
      case 41:
      case 44:
      case 49:
      case 63:
      case 70:
      case 124:
// 600 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_zval_list(ppmsp[-2].minor.pp158, ppmsp[0].minor.pp158);
  pp_destructor(25,&ppmsp[-1].minor);
}
// 1713 "parser.c"
        break;
      case 11:
      case 42:
      case 45:
      case 116:
      case 125:
// 604 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_zval_list(ppmsp[0].minor.pp158, NULL);
}
// 1724 "parser.c"
        break;
      case 12:
      case 126:
// 610 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_column_item(PHQL_T_STARALL, NULL, NULL, NULL);
  pp_destructor(17,&ppmsp[0].minor);
}
// 1733 "parser.c"
        break;
      case 13:
// 614 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_column_item(PHQL_T_DOMAINALL, NULL, ppmsp[-2].minor.pp0, NULL);
  pp_destructor(31,&ppmsp[-1].minor);
  pp_destructor(17,&ppmsp[0].minor);
}
// 1742 "parser.c"
        break;
      case 14:
// 618 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_column_item(PHQL_T_EXPR, ppmsp[-2].minor.pp158, NULL, ppmsp[0].minor.pp0);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 1750 "parser.c"
        break;
      case 15:
// 622 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_column_item(PHQL_T_EXPR, ppmsp[-1].minor.pp158, NULL, ppmsp[0].minor.pp0);
}
// 1757 "parser.c"
        break;
      case 16:
// 626 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_column_item(PHQL_T_EXPR, ppmsp[0].minor.pp158, NULL, NULL);
}
// 1764 "parser.c"
        break;
      case 21:
      case 115:
// 650 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_zval_list(ppmsp[-1].minor.pp158, ppmsp[0].minor.pp158);
}
// 1772 "parser.c"
        break;
      case 24:
// 667 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_join_item(ppmsp[-3].minor.pp158, ppmsp[-2].minor.pp158, ppmsp[-1].minor.pp158, ppmsp[0].minor.pp158);
}
// 1779 "parser.c"
        break;
      case 25:
// 673 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_qualified_name(NULL, NULL, ppmsp[0].minor.pp0);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 1787 "parser.c"
        break;
      case 26:
      case 46:
      case 144:
// 677 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_qualified_name(NULL, NULL, ppmsp[0].minor.pp0);
}
// 1796 "parser.c"
        break;
      case 28:
// 687 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_join_type(PHQL_T_INNERJOIN);
  pp_destructor(33,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1805 "parser.c"
        break;
      case 29:
// 691 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_join_type(PHQL_T_CROSSJOIN);
  pp_destructor(35,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1814 "parser.c"
        break;
      case 30:
// 695 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  pp_destructor(36,&ppmsp[-2].minor);
  pp_destructor(37,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1824 "parser.c"
        break;
      case 31:
// 699 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  pp_destructor(36,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1833 "parser.c"
        break;
      case 32:
// 703 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  pp_destructor(38,&ppmsp[-2].minor);
  pp_destructor(37,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1843 "parser.c"
        break;
      case 33:
// 707 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  pp_destructor(38,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1852 "parser.c"
        break;
      case 34:
// 711 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_join_type(PHQL_T_FULLJOIN);
  pp_destructor(39,&ppmsp[-2].minor);
  pp_destructor(37,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1862 "parser.c"
        break;
      case 35:
// 715 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_join_type(PHQL_T_FULLJOIN);
  pp_destructor(39,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1871 "parser.c"
        break;
      case 36:
// 719 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_join_type(PHQL_T_INNERJOIN);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1879 "parser.c"
        break;
      case 37:
// 725 "parser.lemon"
{
	ppgotominor.pp158 = ppmsp[0].minor.pp158;
  pp_destructor(40,&ppmsp[-1].minor);
}
// 1887 "parser.c"
        break;
      case 39:
// 736 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_insert_statement(ppmsp[-4].minor.pp158, NULL, ppmsp[-1].minor.pp158);
  pp_destructor(41,&ppmsp[-6].minor);
  pp_destructor(42,&ppmsp[-5].minor);
  pp_destructor(43,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1899 "parser.c"
        break;
      case 40:
// 740 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_insert_statement(ppmsp[-7].minor.pp158, ppmsp[-5].minor.pp158, ppmsp[-1].minor.pp158);
  pp_destructor(41,&ppmsp[-9].minor);
  pp_destructor(42,&ppmsp[-8].minor);
  pp_destructor(44,&ppmsp[-6].minor);
  pp_destructor(45,&ppmsp[-4].minor);
  pp_destructor(43,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1913 "parser.c"
        break;
      case 47:
// 778 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_update_statement(ppmsp[-2].minor.pp158, ppmsp[-1].minor.pp158, ppmsp[0].minor.pp158);
}
// 1920 "parser.c"
        break;
      case 48:
// 784 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_update_clause(ppmsp[-2].minor.pp158, ppmsp[0].minor.pp158);
  pp_destructor(46,&ppmsp[-3].minor);
  pp_destructor(47,&ppmsp[-1].minor);
}
// 1929 "parser.c"
        break;
      case 51:
// 800 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_update_item(ppmsp[-2].minor.pp158, ppmsp[0].minor.pp158);
  pp_destructor(3,&ppmsp[-1].minor);
}
// 1937 "parser.c"
        break;
      case 53:
// 812 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_delete_statement(ppmsp[-2].minor.pp158, ppmsp[-1].minor.pp158, ppmsp[0].minor.pp158);
}
// 1944 "parser.c"
        break;
      case 54:
// 818 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_delete_clause(ppmsp[0].minor.pp158);
  pp_destructor(48,&ppmsp[-2].minor);
  pp_destructor(27,&ppmsp[-1].minor);
}
// 1953 "parser.c"
        break;
      case 55:
// 824 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_assoc_name(ppmsp[-2].minor.pp158, ppmsp[0].minor.pp0);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 1961 "parser.c"
        break;
      case 56:
// 828 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_assoc_name(ppmsp[-1].minor.pp158, ppmsp[0].minor.pp0);
}
// 1968 "parser.c"
        break;
      case 57:
// 832 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_assoc_name(ppmsp[0].minor.pp158, NULL);
}
// 1975 "parser.c"
        break;
      case 59:
// 844 "parser.lemon"
{
	ppgotominor.pp158 = ppmsp[0].minor.pp158;
  pp_destructor(49,&ppmsp[-1].minor);
}
// 1983 "parser.c"
        break;
      case 61:
// 854 "parser.lemon"
{
	ppgotominor.pp158 = ppmsp[0].minor.pp158;
  pp_destructor(50,&ppmsp[-2].minor);
  pp_destructor(51,&ppmsp[-1].minor);
}
// 1992 "parser.c"
        break;
      case 65:
// 874 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_order_item(ppmsp[0].minor.pp158, 0);
}
// 1999 "parser.c"
        break;
      case 66:
// 878 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_order_item(ppmsp[-1].minor.pp158, PHQL_T_ASC);
  pp_destructor(52,&ppmsp[0].minor);
}
// 2007 "parser.c"
        break;
      case 67:
// 882 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_order_item(ppmsp[-1].minor.pp158, PHQL_T_DESC);
  pp_destructor(53,&ppmsp[0].minor);
}
// 2015 "parser.c"
        break;
      case 68:
// 888 "parser.lemon"
{
	ppgotominor.pp158 = ppmsp[0].minor.pp158;
  pp_destructor(54,&ppmsp[-2].minor);
  pp_destructor(51,&ppmsp[-1].minor);
}
// 2024 "parser.c"
        break;
      case 73:
// 914 "parser.lemon"
{
	ppgotominor.pp158 = ppmsp[0].minor.pp158;
  pp_destructor(55,&ppmsp[-1].minor);
}
// 2032 "parser.c"
        break;
      case 75:
      case 79:
// 924 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_limit_clause(ppmsp[0].minor.pp158, NULL);
  pp_destructor(56,&ppmsp[-1].minor);
}
// 2041 "parser.c"
        break;
      case 76:
// 928 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_limit_clause(ppmsp[0].minor.pp158, ppmsp[-2].minor.pp158);
  pp_destructor(56,&ppmsp[-3].minor);
  pp_destructor(25,&ppmsp[-1].minor);
}
// 2050 "parser.c"
        break;
      case 77:
// 932 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_limit_clause(ppmsp[-2].minor.pp158, ppmsp[0].minor.pp158);
  pp_destructor(56,&ppmsp[-3].minor);
  pp_destructor(57,&ppmsp[-1].minor);
}
// 2059 "parser.c"
        break;
      case 81:
      case 135:
// 950 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_literal_zval(PHQL_T_INTEGER, ppmsp[0].minor.pp0);
}
// 2067 "parser.c"
        break;
      case 82:
      case 141:
// 954 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_placeholder_zval(PHQL_T_NPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 2075 "parser.c"
        break;
      case 83:
      case 142:
// 958 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_placeholder_zval(PHQL_T_SPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 2083 "parser.c"
        break;
      case 84:
// 964 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_MINUS, NULL, ppmsp[0].minor.pp158);
  pp_destructor(20,&ppmsp[-1].minor);
}
// 2091 "parser.c"
        break;
      case 85:
// 968 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_SUB, ppmsp[-2].minor.pp158, ppmsp[0].minor.pp158);
  pp_destructor(20,&ppmsp[-1].minor);
}
// 2099 "parser.c"
        break;
      case 86:
// 972 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_ADD, ppmsp[-2].minor.pp158, ppmsp[0].minor.pp158);
  pp_destructor(19,&ppmsp[-1].minor);
}
// 2107 "parser.c"
        break;
      case 87:
// 976 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_MUL, ppmsp[-2].minor.pp158, ppmsp[0].minor.pp158);
  pp_destructor(17,&ppmsp[-1].minor);
}
// 2115 "parser.c"
        break;
      case 88:
// 980 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_DIV, ppmsp[-2].minor.pp158, ppmsp[0].minor.pp158);
  pp_destructor(16,&ppmsp[-1].minor);
}
// 2123 "parser.c"
        break;
      case 89:
// 984 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_MOD, ppmsp[-2].minor.pp158, ppmsp[0].minor.pp158);
  pp_destructor(18,&ppmsp[-1].minor);
}
// 2131 "parser.c"
        break;
      case 90:
// 988 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_AND, ppmsp[-2].minor.pp158, ppmsp[0].minor.pp158);
  pp_destructor(9,&ppmsp[-1].minor);
}
// 2139 "parser.c"
        break;
      case 91:
// 992 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_OR, ppmsp[-2].minor.pp158, ppmsp[0].minor.pp158);
  pp_destructor(10,&ppmsp[-1].minor);
}
// 2147 "parser.c"
        break;
      case 92:
// 996 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_BITWISE_AND, ppmsp[-2].minor.pp158, ppmsp[0].minor.pp158);
  pp_destructor(13,&ppmsp[-1].minor);
}
// 2155 "parser.c"
        break;
      case 93:
// 1000 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_BITWISE_OR, ppmsp[-2].minor.pp158, ppmsp[0].minor.pp158);
  pp_destructor(14,&ppmsp[-1].minor);
}
// 2163 "parser.c"
        break;
      case 94:
// 1004 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_BITWISE_XOR, ppmsp[-2].minor.pp158, ppmsp[0].minor.pp158);
  pp_destructor(15,&ppmsp[-1].minor);
}
// 2171 "parser.c"
        break;
      case 95:
// 1008 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_EQUALS, ppmsp[-2].minor.pp158, ppmsp[0].minor.pp158);
  pp_destructor(3,&ppmsp[-1].minor);
}
// 2179 "parser.c"
        break;
      case 96:
// 1012 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_NOTEQUALS, ppmsp[-2].minor.pp158, ppmsp[0].minor.pp158);
  pp_destructor(4,&ppmsp[-1].minor);
}
// 2187 "parser.c"
        break;
      case 97:
// 1016 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_LESS, ppmsp[-2].minor.pp158, ppmsp[0].minor.pp158);
  pp_destructor(5,&ppmsp[-1].minor);
}
// 2195 "parser.c"
        break;
      case 98:
// 1020 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_GREATER, ppmsp[-2].minor.pp158, ppmsp[0].minor.pp158);
  pp_destructor(6,&ppmsp[-1].minor);
}
// 2203 "parser.c"
        break;
      case 99:
// 1024 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_GREATEREQUAL, ppmsp[-2].minor.pp158, ppmsp[0].minor.pp158);
  pp_destructor(7,&ppmsp[-1].minor);
}
// 2211 "parser.c"
        break;
      case 100:
// 1028 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_LESSEQUAL, ppmsp[-2].minor.pp158, ppmsp[0].minor.pp158);
  pp_destructor(8,&ppmsp[-1].minor);
}
// 2219 "parser.c"
        break;
      case 101:
// 1032 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_LIKE, ppmsp[-2].minor.pp158, ppmsp[0].minor.pp158);
  pp_destructor(11,&ppmsp[-1].minor);
}
// 2227 "parser.c"
        break;
      case 102:
// 1036 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_NLIKE, ppmsp[-3].minor.pp158, ppmsp[0].minor.pp158);
  pp_destructor(23,&ppmsp[-2].minor);
  pp_destructor(11,&ppmsp[-1].minor);
}
// 2236 "parser.c"
        break;
      case 103:
// 1040 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_ILIKE, ppmsp[-2].minor.pp158, ppmsp[0].minor.pp158);
  pp_destructor(12,&ppmsp[-1].minor);
}
// 2244 "parser.c"
        break;
      case 104:
// 1044 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_NILIKE, ppmsp[-3].minor.pp158, ppmsp[0].minor.pp158);
  pp_destructor(23,&ppmsp[-2].minor);
  pp_destructor(12,&ppmsp[-1].minor);
}
// 2253 "parser.c"
        break;
      case 105:
      case 108:
// 1048 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_IN, ppmsp[-4].minor.pp158, ppmsp[-1].minor.pp158);
  pp_destructor(22,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2264 "parser.c"
        break;
      case 106:
      case 109:
// 1052 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_NOTIN, ppmsp[-5].minor.pp158, ppmsp[-1].minor.pp158);
  pp_destructor(23,&ppmsp[-4].minor);
  pp_destructor(22,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2276 "parser.c"
        break;
      case 107:
// 1056 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_SUBQUERY, ppmsp[-1].minor.pp158, NULL);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2285 "parser.c"
        break;
      case 110:
// 1068 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_EXISTS, NULL, ppmsp[-1].minor.pp158);
  pp_destructor(61,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2295 "parser.c"
        break;
      case 111:
// 1072 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_AGAINST, ppmsp[-2].minor.pp158, ppmsp[0].minor.pp158);
  pp_destructor(1,&ppmsp[-1].minor);
}
// 2303 "parser.c"
        break;
      case 112:
// 1076 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_CAST, ppmsp[-3].minor.pp158, phql_ret_raw_qualified_name(ppmsp[-1].minor.pp0, NULL));
  pp_destructor(62,&ppmsp[-5].minor);
  pp_destructor(44,&ppmsp[-4].minor);
  pp_destructor(32,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2314 "parser.c"
        break;
      case 113:
// 1080 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_CONVERT, ppmsp[-3].minor.pp158, phql_ret_raw_qualified_name(ppmsp[-1].minor.pp0, NULL));
  pp_destructor(63,&ppmsp[-5].minor);
  pp_destructor(44,&ppmsp[-4].minor);
  pp_destructor(64,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2325 "parser.c"
        break;
      case 114:
// 1084 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_CASE, ppmsp[-2].minor.pp158, ppmsp[-1].minor.pp158);
  pp_destructor(65,&ppmsp[-3].minor);
  pp_destructor(66,&ppmsp[0].minor);
}
// 2334 "parser.c"
        break;
      case 117:
// 1096 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_WHEN, ppmsp[-2].minor.pp158, ppmsp[0].minor.pp158);
  pp_destructor(67,&ppmsp[-3].minor);
  pp_destructor(68,&ppmsp[-1].minor);
}
// 2343 "parser.c"
        break;
      case 119:
// 1106 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_func_call(ppmsp[-4].minor.pp0, ppmsp[-1].minor.pp158, ppmsp[-2].minor.pp158);
  pp_destructor(44,&ppmsp[-3].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2352 "parser.c"
        break;
      case 120:
// 1112 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_distinct();
  pp_destructor(28,&ppmsp[0].minor);
}
// 2360 "parser.c"
        break;
      case 128:
// 1150 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_ISNULL, ppmsp[-2].minor.pp158, NULL);
  pp_destructor(21,&ppmsp[-1].minor);
  pp_destructor(69,&ppmsp[0].minor);
}
// 2369 "parser.c"
        break;
      case 129:
// 1154 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_ISNOTNULL, ppmsp[-3].minor.pp158, NULL);
  pp_destructor(21,&ppmsp[-2].minor);
  pp_destructor(23,&ppmsp[-1].minor);
  pp_destructor(69,&ppmsp[0].minor);
}
// 2379 "parser.c"
        break;
      case 130:
// 1158 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_BETWEEN, ppmsp[-2].minor.pp158, ppmsp[0].minor.pp158);
  pp_destructor(2,&ppmsp[-1].minor);
}
// 2387 "parser.c"
        break;
      case 131:
// 1162 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_NOT, NULL, ppmsp[0].minor.pp158);
  pp_destructor(23,&ppmsp[-1].minor);
}
// 2395 "parser.c"
        break;
      case 132:
// 1166 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_BITWISE_NOT, NULL, ppmsp[0].minor.pp158);
  pp_destructor(24,&ppmsp[-1].minor);
}
// 2403 "parser.c"
        break;
      case 133:
// 1170 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_expr(PHQL_T_ENCLOSED, ppmsp[-1].minor.pp158, NULL);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2412 "parser.c"
        break;
      case 136:
// 1182 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_literal_zval(PHQL_T_STRING, ppmsp[0].minor.pp0);
}
// 2419 "parser.c"
        break;
      case 137:
// 1186 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_literal_zval(PHQL_T_DOUBLE, ppmsp[0].minor.pp0);
}
// 2426 "parser.c"
        break;
      case 138:
// 1190 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_literal_zval(PHQL_T_NULL, NULL);
  pp_destructor(69,&ppmsp[0].minor);
}
// 2434 "parser.c"
        break;
      case 139:
// 1194 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_literal_zval(PHQL_T_TRUE, NULL);
  pp_destructor(72,&ppmsp[0].minor);
}
// 2442 "parser.c"
        break;
      case 140:
// 1198 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_literal_zval(PHQL_T_FALSE, NULL);
  pp_destructor(73,&ppmsp[0].minor);
}
// 2450 "parser.c"
        break;
      case 143:
// 1212 "parser.lemon"
{
	ppgotominor.pp158 = phql_ret_qualified_name(NULL, ppmsp[-2].minor.pp0, ppmsp[0].minor.pp0);
  pp_destructor(31,&ppmsp[-1].minor);
}
// 2458 "parser.c"
        break;
  };
  ppgoto = ppRuleInfo[ppruleno].lhs;
  ppsize = ppRuleInfo[ppruleno].nrhs;
  pppParser->ppidx -= ppsize;
  ppact = pp_find_reduce_action(pppParser,ppgoto);
  if( ppact < PPNSTATE ){
    pp_shift(pppParser,ppact,ppgoto,&ppgotominor);
  }else if( ppact == PPNSTATE + PPNRULE + 1 ){
    pp_accept(pppParser);
  }
}

/*
** The following code executes when the parse fails
*/
static void pp_parse_failed(
  ppParser *pppParser           /* The parser */
){
  phql_ARG_FETCH;
#ifndef NDEBUG
  if( ppTraceFILE ){
    fprintf(ppTraceFILE,"%sFail!\n",ppTracePrompt);
  }
#endif
  while( pppParser->ppidx>=0 ) pp_pop_parser_stack(pppParser);
  /* Here code is inserted which will be executed whenever the
  ** parser fails */
  phql_ARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following code executes when a syntax error first occurs.
*/
static void pp_syntax_error(
  ppParser *pppParser,           /* The parser */
  int ppmajor,                   /* The major type of the error token */
  PPMINORTYPE ppminor            /* The minor type of the error token */
){
  phql_ARG_FETCH;
#define PPTOKEN (ppminor.pp0)
// 474 "parser.lemon"

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

// 2567 "parser.c"
  phql_ARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following is executed when the parser accepts
*/
static void pp_accept(
  ppParser *pppParser           /* The parser */
){
  phql_ARG_FETCH;
#ifndef NDEBUG
  if( ppTraceFILE ){
    fprintf(ppTraceFILE,"%sAccept!\n",ppTracePrompt);
  }
#endif
  while( pppParser->ppidx>=0 ) pp_pop_parser_stack(pppParser);
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
  void *ppp,                   /* The parser */
  int ppmajor,                 /* The major token code number */
  phql_TOKENTYPE ppminor       /* The value for the token */
  phql_ARG_PDECL               /* Optional %extra_argument parameter */
){
  PPMINORTYPE ppminorunion;
  int ppact;            /* The parser action. */
  int ppendofinput;     /* True if we are at the end of input */
  int pperrorhit = 0;   /* True if ppmajor has invoked an error */
  ppParser *pppParser;  /* The parser */

  /* (re)initialize the parser, if necessary */
  pppParser = (ppParser*)ppp;
  if( pppParser->ppidx<0 ){
    if( ppmajor==0 ) return;
    pppParser->ppidx = 0;
    pppParser->pperrcnt = -1;
    pppParser->ppstack[0].stateno = 0;
    pppParser->ppstack[0].major = 0;
  }
  ppminorunion.pp0 = ppminor;
  ppendofinput = (ppmajor==0);
  phql_ARG_STORE;

#ifndef NDEBUG
  if( ppTraceFILE ){
    fprintf(ppTraceFILE,"%sInput %s\n",ppTracePrompt,ppTokenName[ppmajor]);
  }
#endif

  do{
    ppact = pp_find_shift_action(pppParser,ppmajor);
    if( ppact<PPNSTATE ){
      pp_shift(pppParser,ppact,ppmajor,&ppminorunion);
      pppParser->pperrcnt--;
      if( ppendofinput && pppParser->ppidx>=0 ){
        ppmajor = 0;
      }else{
        ppmajor = PPNOCODE;
      }
    }else if( ppact < PPNSTATE + PPNRULE ){
      pp_reduce(pppParser,ppact-PPNSTATE);
    }else if( ppact == PP_ERROR_ACTION ){
      int ppmx;
#ifndef NDEBUG
      if( ppTraceFILE ){
        fprintf(ppTraceFILE,"%sSyntax Error!\n",ppTracePrompt);
      }
#endif
#ifdef PPERRORSYMBOL
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
      if( pppParser->pperrcnt<0 ){
        pp_syntax_error(pppParser,ppmajor,ppminorunion);
      }
      ppmx = pppParser->ppstack[pppParser->ppidx].major;
      if( ppmx==PPERRORSYMBOL || pperrorhit ){
#ifndef NDEBUG
        if( ppTraceFILE ){
          fprintf(ppTraceFILE,"%sDiscard input token %s\n",
             ppTracePrompt,ppTokenName[ppmajor]);
        }
#endif
        pp_destructor(ppmajor,&ppminorunion);
        ppmajor = PPNOCODE;
      }else{
         while(
          pppParser->ppidx >= 0 &&
          ppmx != PPERRORSYMBOL &&
          (ppact = pp_find_shift_action(pppParser,PPERRORSYMBOL)) >= PPNSTATE
        ){
          pp_pop_parser_stack(pppParser);
        }
        if( pppParser->ppidx < 0 || ppmajor==0 ){
          pp_destructor(ppmajor,&ppminorunion);
          pp_parse_failed(pppParser);
          ppmajor = PPNOCODE;
        }else if( ppmx!=PPERRORSYMBOL ){
          PPMINORTYPE u2;
          u2.PPERRSYMDT = 0;
          pp_shift(pppParser,ppact,PPERRORSYMBOL,&u2);
        }
      }
      pppParser->pperrcnt = 3;
      pperrorhit = 1;
#else  /* PPERRORSYMBOL is not defined */
      /* This is what we do if the grammar does not define ERROR:
      **
      **  * Report an error message, and throw away the input token.
      **
      **  * If the input token is $, then fail the parse.
      **
      ** As before, subsequent error messages are suppressed until
      ** three input tokens have been successfully shifted.
      */
      if( pppParser->pperrcnt<=0 ){
        pp_syntax_error(pppParser,ppmajor,ppminorunion);
      }
      pppParser->pperrcnt = 3;
      pp_destructor(ppmajor,&ppminorunion);
      if( ppendofinput ){
        pp_parse_failed(pppParser);
      }
      ppmajor = PPNOCODE;
#endif
    }else{
      pp_accept(pppParser);
      ppmajor = PPNOCODE;
    }
  }while( ppmajor!=PPNOCODE && pppParser->ppidx>=0 );
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
  { SL("EXISTS"),        PHQL_T_EXISTS },
  { SL("CASE"),          PHQL_T_CASE },
  { SL("WHEN"),          PHQL_T_WHEN },
  { SL("THEN"),          PHQL_T_THEN },
  { NULL, 0, 0 }
};

static void *phql_wrapper_alloc(size_t bytes) {
	return emalloc(bytes);
}

static void phql_wrapper_free(void *pointer) {
	efree(pointer);
}

static void phql_parse_with_token(void* phql_parser, int opcode, int parsercode, phql_scanner_token *token, phql_parser_status *parser_status) {

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
static void phql_scanner_error_msg(phql_parser_status *parser_status, zval **error_msg TSRMLS_DC) {

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
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, Z_STRVAL_P(error_msg));
		return FAILURE;
	}

	return SUCCESS;
}

/**
 * Executes a PHQL parser/tokenizer
 */
int phql_internal_parse_phql(zval **result, char *phql, unsigned int phql_length, zval **error_msg TSRMLS_DC) {

	zend_phalcon_globals *phalcon_globals_ptr = ZEPHIR_VGLOBAL;
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

            case PHQL_T_IDENTIFIER:
    			phql_parse_with_token(phql_parser, PHQL_T_IDENTIFIER, PHQL_IDENTIFIER, &token, parser_status);
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
            case PHQL_T_CASE:
    			phql_(phql_parser, PHQL_CASE, NULL, parser_status);
    			break;
            case PHQL_T_WHEN:
        		phql_(phql_parser, PHQL_WHEN, NULL, parser_status);
        		break;
            case PHQL_T_THEN:
            	phql_(phql_parser, PHQL_THEN, NULL, parser_status);
            	break;
            case PHQL_T_END:
            	phql_(phql_parser, PHQL_END, NULL, parser_status);
            	break;
            //case PHQL_T_ELSE:
            //    phql_(phql_parser, PHQL_ELSE, NULL, parser_status);
            //    break;

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
            case PHQL_T_EXISTS:
    			phql_(phql_parser, PHQL_EXISTS, NULL, parser_status);
    			break;

			default:
				parser_status->status = PHQL_PARSING_FAILED;
				error_length = sizeof(char) * 32;
				error = emalloc(error_length);
				snprintf(error, error_length, "Scanner: Unknown opcode %d", token.opcode);
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
