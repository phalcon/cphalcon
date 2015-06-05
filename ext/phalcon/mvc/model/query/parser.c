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
#define PPNOCODE 129
#define PPACTIONTYPE unsigned short int
#define phql_TOKENTYPE phql_parser_token*
typedef union {
  phql_TOKENTYPE pp0;
  zval* pp56;
  int pp257;
} PPMINORTYPE;
#define PPSTACKDEPTH 100
#define phql_ARG_SDECL phql_parser_status *status;
#define phql_ARG_PDECL ,phql_parser_status *status
#define phql_ARG_FETCH phql_parser_status *status = pppParser->status
#define phql_ARG_STORE pppParser->status = status
#define PPNSTATE 269
#define PPNRULE 148
#define PPERRORSYMBOL 77
#define PPERRSYMDT pp257
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
 /*    20 */    98,   69,   64,   96,  102,   50,   52,   54,   56,   58,
 /*    30 */    60,   40,   42,   62,   67,   44,   46,   48,   36,   34,
 /*    40 */    38,   32,   29,   98,   69,   64,   32,   29,   98,   69,
 /*    50 */    64,  187,  196,   74,  194,   44,   46,   48,   36,   34,
 /*    60 */    38,   32,   29,   98,   69,   64,  130,   82,  162,   80,
 /*    70 */    96,  102,   50,   52,   54,   56,   58,   60,   40,   42,
 /*    80 */    62,   67,   44,   46,   48,   36,   34,   38,   32,   29,
 /*    90 */    98,   69,   64,   96,  102,   50,   52,   54,   56,   58,
 /*   100 */    60,   40,   42,   62,   67,   44,   46,   48,   36,   34,
 /*   110 */    38,   32,   29,   98,   69,   64,   98,   69,   64,  127,
 /*   120 */   164,   27,   28,  167,  116,  165,   96,  102,   50,   52,
 /*   130 */    54,   56,   58,   60,   40,   42,   62,   67,   44,   46,
 /*   140 */    48,   36,   34,   38,   32,   29,   98,   69,   64,  229,
 /*   150 */    96,  102,   50,   52,   54,   56,   58,   60,   40,   42,
 /*   160 */    62,   67,   44,   46,   48,   36,   34,   38,   32,   29,
 /*   170 */    98,   69,   64,   40,   42,   62,   67,   44,   46,   48,
 /*   180 */    36,   34,   38,   32,   29,   98,   69,   64,  128,  130,
 /*   190 */   217,  162,  108,  132,  106,   96,  102,   50,   52,   54,
 /*   200 */    56,   58,   60,   40,   42,   62,   67,   44,   46,   48,
 /*   210 */    36,   34,   38,   32,   29,   98,   69,   64,   96,  102,
 /*   220 */    50,   52,   54,   56,   58,   60,   40,   42,   62,   67,
 /*   230 */    44,   46,   48,   36,   34,   38,   32,   29,   98,   69,
 /*   240 */    64,  144,   65,  204,   30,  100,  142,  145,  147,   21,
 /*   250 */    71,   77,  261,  206,  135,   16,   17,   18,  122,  168,
 /*   260 */   184,  170,  172,  111,  176,  180,  392,    6,  104,   73,
 /*   270 */   149,  260,  197,  193,  418,    1,    2,    3,    4,    5,
 /*   280 */     6,  134,  150,  156,  157,  109,  113,  119,  216,  125,
 /*   290 */   175,  149,   99,  173,  153,  151,  152,  154,  155,  158,
 /*   300 */   159,  144,  134,  179,   30,  247,  177,  145,  147,  198,
 /*   310 */   199,  263,  308,  191,  135,   36,   34,   38,   32,   29,
 /*   320 */    98,   69,   64,  255,  262,  258,  136,  223,  104,  393,
 /*   330 */   168,  184,  170,  172,   76,  176,  180,  211,   87,  185,
 /*   340 */    89,   90,  150,  156,  157,  109,  113,  119,  207,  125,
 /*   350 */    88,   89,   90,   64,  153,  151,  152,  154,  155,  158,
 /*   360 */   159,   50,   52,   54,   56,   58,   60,   40,   42,   62,
 /*   370 */    67,   44,   46,   48,   36,   34,   38,   32,   29,   98,
 /*   380 */    69,   64,  189,   26,  183,   30,  269,  181,  145,  147,
 /*   390 */   138,  142,  203,  192,   75,  190,  101,  142,  186,   14,
 /*   400 */   138,  149,  273,   79,   23,  213,   86,  144,  149,  104,
 /*   410 */    30,  201,  134,  145,  147,   83,  141,  209,  149,  134,
 /*   420 */   135,  139,  160,  150,  156,  157,  109,  113,  119,  134,
 /*   430 */   125,   19,  143,   91,  104,  153,  151,  152,  154,  155,
 /*   440 */   158,  159,  227,  202,  117,   83,  245,    6,  150,  156,
 /*   450 */   157,  109,  113,  119,   83,  125,   26,  349,  138,  221,
 /*   460 */   153,  151,  152,  154,  155,  158,  159,  228,  236,   30,
 /*   470 */     9,  232,  145,  147,  149,   71,  149,  149,   25,  135,
 /*   480 */    71,  243,  218,  222,  200,  134,  237,  134,  134,  246,
 /*   490 */   160,  231,   85,  104,   30,  225,  161,  145,  147,  146,
 /*   500 */   252,  238,  266,  118,  135,  136,  239,  150,  156,  157,
 /*   510 */   109,  113,  119,  250,  125,  240,  195,  149,  104,  153,
 /*   520 */   151,  152,  154,  155,  158,  159,  253,  270,  134,  257,
 /*   530 */   258,   79,  150,  156,  157,  109,  113,  119,    8,  125,
 /*   540 */    93,   94,  309,   83,  153,  151,  152,  154,  155,  158,
 /*   550 */   159,   62,   67,   44,   46,   48,   36,   34,   38,   32,
 /*   560 */    29,   98,   69,   64,  107,  210,  137,  244,    6,    6,
 /*   570 */   221,  234,  234,  234,  188,  193,  120,  248,   47,  105,
 /*   580 */   138,  230,  241,  233,  235,  235,   84,   15,  149,  149,
 /*   590 */   149,  149,   92,  149,  220,   55,  149,  149,  149,  134,
 /*   600 */   134,  134,  134,   66,  134,   39,  208,  134,  134,  134,
 /*   610 */   205,  305,  160,  149,  304,  115,  249,   63,  103,  148,
 /*   620 */    61,  149,  123,  149,  134,  251,  214,  303,  149,  316,
 /*   630 */   348,  232,  134,  149,  134,  149,  149,  149,  149,  134,
 /*   640 */   224,   45,   41,  126,  134,  212,  134,  134,  134,  134,
 /*   650 */    43,  242,  124,   86,  302,   31,  254,   51,  149,  149,
 /*   660 */   149,  149,  182,  149,   59,   57,   85,   53,  149,  134,
 /*   670 */   134,  134,  134,  149,  134,  149,  256,   33,  301,  134,
 /*   680 */   121,   35,  149,  149,  134,  149,  134,  268,  178,  215,
 /*   690 */   131,  259,   79,  134,  134,  149,  134,   78,  149,  149,
 /*   700 */   300,  272,   79,   49,   83,  163,  134,  149,  149,  134,
 /*   710 */   134,   95,  299,  133,   83,   97,  140,   68,  134,  134,
 /*   720 */    37,  149,   13,  149,  174,   81,  129,  298,  264,  149,
 /*   730 */    22,  149,  134,  149,  134,  149,  265,  322,  149,  171,
 /*   740 */   134,  267,  134,  297,  134,  169,  134,  271,   11,  134,
 /*   750 */   166,   20,   72,   70,   12,   24,   10,  112,   71,    7,
 /*   760 */   226,  110,  278,  219,  278,  114,
};
static PPCODETYPE pp_lookahead[] = {
 /*     0 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    10 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*    20 */    21,   22,   23,    1,    2,    3,    4,    5,    6,    7,
 /*    30 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*    40 */    18,   19,   20,   21,   22,   23,   19,   20,   21,   22,
 /*    50 */    23,   25,   30,   27,   32,   13,   14,   15,   16,   17,
 /*    60 */    18,   19,   20,   21,   22,   23,   67,   30,   69,   32,
 /*    70 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    80 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*    90 */    21,   22,   23,    1,    2,    3,    4,    5,    6,    7,
 /*   100 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   110 */    18,   19,   20,   21,   22,   23,   21,   22,   23,  122,
 /*   120 */   123,   52,   53,   30,   32,   32,    1,    2,    3,    4,
 /*   130 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   140 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   44,
 /*   150 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*   160 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   170 */    21,   22,   23,    9,   10,   11,   12,   13,   14,   15,
 /*   180 */    16,   17,   18,   19,   20,   21,   22,   23,   66,   67,
 /*   190 */    51,   69,   45,   68,   45,    1,    2,    3,    4,    5,
 /*   200 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   210 */    16,   17,   18,   19,   20,   21,   22,   23,    1,    2,
 /*   220 */     3,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   230 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   240 */    23,   17,   11,   12,   20,   23,   25,   23,   24,   50,
 /*   250 */    26,   25,   95,   22,   30,   58,   59,   60,   64,   33,
 /*   260 */    34,   35,   36,   80,   38,   39,   45,   84,   44,   91,
 /*   270 */   113,  114,   94,   95,   78,   79,   80,   81,   82,   83,
 /*   280 */    84,  124,   58,   59,   60,   61,   62,   63,   54,   65,
 /*   290 */    34,  113,   70,   37,   70,   71,   72,   73,   74,   75,
 /*   300 */    76,   17,  124,   34,   20,  109,   37,   23,   24,   28,
 /*   310 */    29,  115,    0,   31,   30,   16,   17,   18,   19,   20,
 /*   320 */    21,   22,   23,  111,  112,  113,   44,   49,   44,   45,
 /*   330 */    33,   34,   35,   36,   93,   38,   39,   45,   97,   98,
 /*   340 */    99,  100,   58,   59,   60,   61,   62,   63,   44,   65,
 /*   350 */    98,   99,  100,   23,   70,   71,   72,   73,   74,   75,
 /*   360 */    76,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   370 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   380 */    22,   23,   17,   95,   34,   20,    0,   37,   23,   24,
 /*   390 */    95,   25,   45,   17,   92,   30,   70,   25,   96,   25,
 /*   400 */    95,  113,    0,  101,  116,  117,   30,   17,  113,   44,
 /*   410 */    20,   45,  124,   23,   24,  113,  121,   45,  113,  124,
 /*   420 */    30,  126,  127,   58,   59,   60,   61,   62,   63,  124,
 /*   430 */    65,   57,  127,  101,   44,   70,   71,   72,   73,   74,
 /*   440 */    75,   76,  101,   80,   30,  113,   30,   84,   58,   59,
 /*   450 */    60,   61,   62,   63,  113,   65,   95,    0,   95,   95,
 /*   460 */    70,   71,   72,   73,   74,   75,   76,   43,   44,   20,
 /*   470 */    87,   25,   23,   24,  113,   26,  113,  113,  117,   30,
 /*   480 */    26,   25,  118,  119,  121,  124,  105,  124,  124,  108,
 /*   490 */   127,   45,   31,   44,   20,   41,   28,   23,   24,   95,
 /*   500 */    46,   45,   48,   45,   30,   44,   43,   58,   59,   60,
 /*   510 */    61,   62,   63,   56,   65,   44,   30,  113,   44,   70,
 /*   520 */    71,   72,   73,   74,   75,   76,   96,    0,  124,  112,
 /*   530 */   113,  101,   58,   59,   60,   61,   62,   63,   86,   65,
 /*   540 */   103,   40,    0,  113,   70,   71,   72,   73,   74,   75,
 /*   550 */    76,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   560 */    20,   21,   22,   23,   80,   80,  125,  108,   84,   84,
 /*   570 */    95,   95,   95,   95,   94,   95,   44,   85,   95,   95,
 /*   580 */    95,  104,  104,  107,  107,  107,   30,  120,  113,  113,
 /*   590 */   113,  113,  102,  113,  119,   95,  113,  113,  113,  124,
 /*   600 */   124,  124,  124,   95,  124,   95,  121,  124,  124,  124,
 /*   610 */    95,   30,  127,  113,   30,   95,  110,   95,   95,   95,
 /*   620 */    95,  113,   30,  113,  124,  120,   55,   30,  113,    0,
 /*   630 */     0,   25,  124,  113,  124,  113,  113,  113,  113,  124,
 /*   640 */    95,   95,   95,   95,  124,   95,  124,  124,  124,  124,
 /*   650 */    95,   45,   45,   30,   30,   95,   47,   95,  113,  113,
 /*   660 */   113,  113,   34,  113,   95,   95,   31,   95,  113,  124,
 /*   670 */   124,  124,  124,  113,  124,  113,   25,   95,   30,  124,
 /*   680 */    95,   95,  113,  113,  124,  113,  124,   96,   34,   95,
 /*   690 */    95,    3,  101,  124,  124,  113,  124,   96,  113,  113,
 /*   700 */    30,    0,  101,   95,  113,   95,  124,  113,  113,  124,
 /*   710 */   124,   95,   30,   95,  113,   95,   45,   95,  124,  124,
 /*   720 */    95,  113,  120,  113,   34,   30,  123,   30,   85,  113,
 /*   730 */    51,  113,  124,  113,  124,  113,  110,    0,  113,   34,
 /*   740 */   124,   27,  124,   30,  124,   34,  124,    0,   89,  124,
 /*   750 */    30,  120,   90,   44,   56,   25,   88,   45,   26,   85,
 /*   760 */    42,   44,  128,   25,  128,   44,
};
#define PP_SHIFT_USE_DFLT (-2)
static short pp_shift_ofst[] = {
 /*     0 */   454,  386,  527,  747,  701,  402,  278,  234,  571,  199,
 /*    10 */   698,   -2,  197,  374,  197,   -2,   -2,   -2,   -2,  197,
 /*    20 */    -2,  679,  474,  730,  474,   -2,   69,   -2,   -2,  474,
 /*    30 */   474,   95,  474,   95,  474,   27,  474,   27,  474,   27,
 /*    40 */   474,  540,  474,  540,  474,  299,  474,  299,  474,  299,
 /*    50 */   474,  164,  474,  164,  474,  164,  474,  164,  474,  164,
 /*    60 */   474,  164,  474,   42,  231,  474,  330,  474,   42,  709,
 /*    70 */   224,  281,  365,   26,  556,  226,   -2,  556,   -2,   37,
 /*    80 */   695,   -2,   -2,   -2,  635,  623,   -2,  297,   -2,   -2,
 /*    90 */   556,   93,  501,   -2,  474,  217,  474,  217,  222,   -2,
 /*   100 */   326,   -2,  474,  358,  449,  149,   -2,  147,   -2,  717,
 /*   110 */   732,  712,   -2,  721,  474,   92,  414,  458,   -2,  532,
 /*   120 */   474,  194,  592,  607,   -2,  474,   -1,  122,   -2,   -2,
 /*   130 */   474,  125,  474,  217,   -2,  461,  468,  284,  217,  671,
 /*   140 */    -2,  221,  390,   -2,   -2,  474,  330,  474,  330,   -2,
 /*   150 */    -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,
 /*   160 */    -2,   -2,  474,  217,   -2,  720,   -2,   -2,  711,  713,
 /*   170 */   705,  697,  256,  690,  682,  670,  269,  654,  648,  624,
 /*   180 */   350,  628,  597,  584,  581,   -2,   -2,  365,   -2,   -2,
 /*   190 */   282,  376,   -2,   22,  486,   -2,   -2,   -2,   -2,   -2,
 /*   200 */   366,   -2,  347,   -2,  474,  330,  304,  224,  372,   -2,
 /*   210 */   292,   -2,   95,   -2,  474,  217,  139,  474,  738,  474,
 /*   220 */    -2,  217,   -2,  474,  217,  718,  556,  424,  105,  474,
 /*   230 */   446,  312,  474,   -2,  217,   -2,  416,  456,  463,  471,
 /*   240 */   474,  606,  542,  416,   -2,   -2,   -2,  278,  457,  629,
 /*   250 */   197,  630,  556,  609,  556,  651,  556,   -2,  688,  474,
 /*   260 */    -2,  217,   -2,  278,  457,  737,  714,  556,   -2,
};
#define PP_REDUCE_USE_DFLT (-4)
static short pp_reduce_ofst[] = {
 /*     0 */   196,   -4,   -4,   -4,   -4,   -4,  674,  452,  383,  668,
 /*    10 */   659,   -4,  602,   -4,  467,   -4,   -4,   -4,   -4,  631,
 /*    20 */    -4,   -4,  288,   -4,  361,   -4,   -4,   -4,   -4,  550,
 /*    30 */   560,   -4,  582,   -4,  586,   -4,  625,   -4,  510,   -4,
 /*    40 */   547,   -4,  555,   -4,  546,   -4,  483,   -4,  608,   -4,
 /*    50 */   562,   -4,  572,   -4,  500,   -4,  570,   -4,  569,   -4,
 /*    60 */   525,   -4,  522,   -4,   -4,  508,   -4,  622,   -4,   -4,
 /*    70 */   363,  662,  178,   -4,  302,  241,   -4,  601,   -4,   -4,
 /*    80 */    -4,   -4,   -4,   -4,   -4,   -4,   -4,  252,   -4,   -4,
 /*    90 */   332,  490,  437,   -4,  616,   -4,  620,   -4,   -4,   -4,
 /*   100 */    -4,   -4,  523,   -4,  484,   -4,   -4,   -4,   -4,   -4,
 /*   110 */   183,   -4,   -4,   -4,  520,   -4,   -4,   -4,   -4,   -4,
 /*   120 */   585,   -4,   -4,   -4,   -4,  548,   -3,  603,   -4,   -4,
 /*   130 */   595,   -4,  618,   -4,   -4,   -4,  441,  295,   -4,   -4,
 /*   140 */    -4,   -4,  305,   -4,   -4,  404,   -4,  524,   -4,   -4,
 /*   150 */    -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
 /*   160 */    -4,   -4,  610,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
 /*   170 */    -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
 /*   180 */    -4,   -4,   -4,   -4,   -4,   -4,   -4,  480,   -4,   -4,
 /*   190 */    -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
 /*   200 */    -4,   -4,   -4,   -4,  515,   -4,   -4,  485,   -4,   -4,
 /*   210 */    -4,   -4,   -4,   -4,  594,   -4,   -4,  364,   -4,  475,
 /*   220 */    -4,   -4,   -4,  545,   -4,   -4,  341,   -4,   -4,  477,
 /*   230 */    -4,   -4,  476,   -4,   -4,   -4,  381,   -4,   -4,   -4,
 /*   240 */   478,   -4,   -4,  459,   -4,   -4,   -4,  492,  506,   -4,
 /*   250 */   505,   -4,  430,   -4,  212,   -4,  417,   -4,   -4,  157,
 /*   260 */    -4,   -4,   -4,  643,  626,   -4,   -4,  591,   -4,
};
static PPACTIONTYPE pp_default[] = {
 /*     0 */   417,  417,  417,  417,  417,  417,  329,  338,  343,  331,
 /*    10 */   347,  274,  417,  344,  417,  345,  350,  351,  352,  417,
 /*    20 */   346,  417,  417,  330,  417,  332,  334,  335,  336,  417,
 /*    30 */   417,  353,  417,  355,  417,  356,  417,  357,  417,  358,
 /*    40 */   417,  359,  417,  360,  417,  361,  417,  362,  417,  363,
 /*    50 */   417,  364,  417,  365,  417,  366,  417,  367,  417,  368,
 /*    60 */   417,  369,  417,  370,  417,  417,  371,  417,  372,  417,
 /*    70 */   417,  278,  417,  417,  417,  289,  275,  417,  286,  326,
 /*    80 */   417,  324,  325,  327,  416,  417,  415,  288,  290,  292,
 /*    90 */   417,  296,  307,  293,  417,  306,  417,  380,  417,  398,
 /*   100 */   417,  399,  417,  400,  417,  417,  403,  417,  376,  417,
 /*   110 */   417,  417,  379,  417,  417,  417,  417,  417,  381,  417,
 /*   120 */   417,  417,  417,  417,  382,  417,  417,  417,  383,  384,
 /*   130 */   417,  417,  417,  386,  388,  416,  391,  417,  397,  417,
 /*   140 */   389,  417,  417,  394,  396,  417,  401,  417,  402,  404,
 /*   150 */   405,  406,  407,  408,  409,  410,  411,  412,  413,  414,
 /*   160 */   395,  390,  417,  387,  385,  417,  294,  295,  417,  417,
 /*   170 */   417,  417,  417,  417,  417,  417,  417,  417,  417,  417,
 /*   180 */   417,  417,  417,  417,  417,  291,  287,  417,  279,  281,
 /*   190 */   416,  417,  282,  285,  417,  283,  284,  280,  276,  277,
 /*   200 */   417,  374,  417,  377,  417,  373,  417,  417,  417,  375,
 /*   210 */   417,  378,  354,  333,  417,  342,  417,  417,  337,  417,
 /*   220 */   339,  341,  340,  417,  328,  417,  417,  417,  417,  417,
 /*   230 */   417,  417,  417,  310,  312,  311,  417,  417,  417,  417,
 /*   240 */   417,  417,  417,  417,  313,  315,  314,  329,  417,  417,
 /*   250 */   417,  417,  417,  417,  417,  317,  417,  318,  417,  417,
 /*   260 */   320,  321,  319,  329,  417,  417,  417,  417,  323,
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
  "THEN",          "ELSE",          "NULL",          "STRING",      
  "DOUBLE",        "TRUE",          "FALSE",         "NTPLACEHOLDER",
  "STPLACEHOLDER",  "error",         "program",       "query_language",
  "select_statement",  "insert_statement",  "update_statement",  "delete_statement",
  "select_clause",  "where_clause",  "group_clause",  "having_clause",
  "order_clause",  "select_limit_clause",  "distinct_all",  "column_list", 
  "associated_name_list",  "join_list_or_null",  "column_item",   "expr",        
  "associated_name",  "join_list",     "join_item",     "join_clause", 
  "join_type",     "aliased_or_qualified_name",  "join_associated_name",  "join_conditions",
  "values_list",   "field_list",    "value_list",    "value_item",  
  "field_item",    "update_clause",  "limit_clause",  "update_item_list",
  "update_item",   "qualified_name",  "new_value",     "delete_clause",
  "order_list",    "order_item",    "group_list",    "group_item",  
  "integer_or_placeholder",  "argument_list",  "when_clauses",  "when_clause", 
  "function_call",  "distinct_or_null",  "argument_list_or_null",  "argument_item",
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
 /* 118 */ "when_clause ::= ELSE expr",
 /* 119 */ "expr ::= function_call",
 /* 120 */ "function_call ::= IDENTIFIER PARENTHESES_OPEN distinct_or_null argument_list_or_null PARENTHESES_CLOSE",
 /* 121 */ "distinct_or_null ::= DISTINCT",
 /* 122 */ "distinct_or_null ::=",
 /* 123 */ "argument_list_or_null ::= argument_list",
 /* 124 */ "argument_list_or_null ::=",
 /* 125 */ "argument_list ::= argument_list COMMA argument_item",
 /* 126 */ "argument_list ::= argument_item",
 /* 127 */ "argument_item ::= TIMES",
 /* 128 */ "argument_item ::= expr",
 /* 129 */ "expr ::= expr IS NULL",
 /* 130 */ "expr ::= expr IS NOT NULL",
 /* 131 */ "expr ::= expr BETWEEN expr",
 /* 132 */ "expr ::= NOT expr",
 /* 133 */ "expr ::= BITWISE_NOT expr",
 /* 134 */ "expr ::= PARENTHESES_OPEN expr PARENTHESES_CLOSE",
 /* 135 */ "expr ::= qualified_name",
 /* 136 */ "expr ::= INTEGER",
 /* 137 */ "expr ::= STRING",
 /* 138 */ "expr ::= DOUBLE",
 /* 139 */ "expr ::= NULL",
 /* 140 */ "expr ::= TRUE",
 /* 141 */ "expr ::= FALSE",
 /* 142 */ "expr ::= NPLACEHOLDER",
 /* 143 */ "expr ::= SPLACEHOLDER",
 /* 144 */ "expr ::= NTPLACEHOLDER",
 /* 145 */ "expr ::= STPLACEHOLDER",
 /* 146 */ "qualified_name ::= IDENTIFIER DOT IDENTIFIER",
 /* 147 */ "qualified_name ::= IDENTIFIER",
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
    case 74:
    case 75:
    case 76:
// 541 "parser.lemon"
{
	if ((pppminor->pp0)) {
		if ((pppminor->pp0)->free_flag) {
			efree((pppminor->pp0)->token);
		}
		efree((pppminor->pp0));
	}
}
// 1221 "parser.c"
      break;
    case 79:
    case 80:
    case 81:
    case 82:
    case 83:
    case 84:
    case 91:
    case 92:
    case 94:
    case 95:
    case 96:
    case 97:
    case 98:
    case 99:
    case 100:
    case 101:
    case 105:
    case 106:
    case 108:
    case 109:
    case 111:
    case 112:
    case 113:
    case 115:
    case 116:
    case 117:
    case 118:
    case 119:
    case 121:
    case 124:
    case 127:
// 554 "parser.lemon"
{ zval_ptr_dtor(&(pppminor->pp56)); }
// 1256 "parser.c"
      break;
    case 85:
    case 86:
    case 87:
    case 88:
    case 89:
    case 90:
    case 102:
    case 103:
    case 110:
    case 125:
    case 126:
// 842 "parser.lemon"
{ zephir_safe_zval_ptr_dtor((pppminor->pp56)); }
// 1271 "parser.c"
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
  { 78, 1 },
  { 79, 1 },
  { 79, 1 },
  { 79, 1 },
  { 79, 1 },
  { 80, 6 },
  { 84, 6 },
  { 90, 1 },
  { 90, 1 },
  { 90, 0 },
  { 91, 3 },
  { 91, 1 },
  { 94, 1 },
  { 94, 3 },
  { 94, 3 },
  { 94, 2 },
  { 94, 1 },
  { 92, 3 },
  { 92, 1 },
  { 93, 1 },
  { 93, 0 },
  { 97, 2 },
  { 97, 1 },
  { 98, 1 },
  { 99, 4 },
  { 102, 2 },
  { 102, 1 },
  { 102, 0 },
  { 100, 2 },
  { 100, 2 },
  { 100, 3 },
  { 100, 2 },
  { 100, 3 },
  { 100, 2 },
  { 100, 3 },
  { 100, 2 },
  { 100, 1 },
  { 103, 2 },
  { 103, 0 },
  { 81, 7 },
  { 81, 10 },
  { 104, 3 },
  { 104, 1 },
  { 107, 1 },
  { 105, 3 },
  { 105, 1 },
  { 108, 1 },
  { 82, 3 },
  { 109, 4 },
  { 111, 3 },
  { 111, 1 },
  { 112, 3 },
  { 114, 1 },
  { 83, 3 },
  { 115, 3 },
  { 96, 3 },
  { 96, 2 },
  { 96, 1 },
  { 101, 1 },
  { 85, 2 },
  { 85, 0 },
  { 88, 3 },
  { 88, 0 },
  { 116, 3 },
  { 116, 1 },
  { 117, 1 },
  { 117, 2 },
  { 117, 2 },
  { 86, 3 },
  { 86, 0 },
  { 118, 3 },
  { 118, 1 },
  { 119, 1 },
  { 87, 2 },
  { 87, 0 },
  { 89, 2 },
  { 89, 4 },
  { 89, 4 },
  { 89, 0 },
  { 110, 2 },
  { 110, 0 },
  { 120, 1 },
  { 120, 1 },
  { 120, 1 },
  { 95, 2 },
  { 95, 3 },
  { 95, 3 },
  { 95, 3 },
  { 95, 3 },
  { 95, 3 },
  { 95, 3 },
  { 95, 3 },
  { 95, 3 },
  { 95, 3 },
  { 95, 3 },
  { 95, 3 },
  { 95, 3 },
  { 95, 3 },
  { 95, 3 },
  { 95, 3 },
  { 95, 3 },
  { 95, 3 },
  { 95, 4 },
  { 95, 3 },
  { 95, 4 },
  { 95, 5 },
  { 95, 6 },
  { 95, 3 },
  { 95, 5 },
  { 95, 6 },
  { 95, 4 },
  { 95, 3 },
  { 95, 6 },
  { 95, 6 },
  { 95, 4 },
  { 122, 2 },
  { 122, 1 },
  { 123, 4 },
  { 123, 2 },
  { 95, 1 },
  { 124, 5 },
  { 125, 1 },
  { 125, 0 },
  { 126, 1 },
  { 126, 0 },
  { 121, 3 },
  { 121, 1 },
  { 127, 1 },
  { 127, 1 },
  { 95, 3 },
  { 95, 4 },
  { 95, 3 },
  { 95, 2 },
  { 95, 2 },
  { 95, 3 },
  { 95, 1 },
  { 95, 1 },
  { 95, 1 },
  { 95, 1 },
  { 95, 1 },
  { 95, 1 },
  { 95, 1 },
  { 95, 1 },
  { 95, 1 },
  { 95, 1 },
  { 95, 1 },
  { 113, 3 },
  { 113, 1 },
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
	status->ret = ppmsp[0].minor.pp56;
}
// 1636 "parser.c"
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
      case 119:
      case 123:
      case 128:
      case 135:
// 556 "parser.lemon"
{
	ppgotominor.pp56 = ppmsp[0].minor.pp56;
}
// 1661 "parser.c"
        break;
      case 5:
// 574 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_select_statement(ppmsp[-5].minor.pp56, ppmsp[-4].minor.pp56, ppmsp[-1].minor.pp56, ppmsp[-3].minor.pp56, ppmsp[-2].minor.pp56, ppmsp[0].minor.pp56);
}
// 1668 "parser.c"
        break;
      case 6:
// 580 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_select_clause(ppmsp[-4].minor.pp56, ppmsp[-3].minor.pp56, ppmsp[-1].minor.pp56, ppmsp[0].minor.pp56);
  pp_destructor(26,&ppmsp[-5].minor);
  pp_destructor(27,&ppmsp[-2].minor);
}
// 1677 "parser.c"
        break;
      case 7:
// 586 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_distinct_all(1);
  pp_destructor(28,&ppmsp[0].minor);
}
// 1685 "parser.c"
        break;
      case 8:
// 590 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_distinct_all(0);
  pp_destructor(29,&ppmsp[0].minor);
}
// 1693 "parser.c"
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
      case 122:
      case 124:
// 594 "parser.lemon"
{
	ppgotominor.pp56 = NULL;
}
// 1711 "parser.c"
        break;
      case 10:
      case 17:
      case 41:
      case 44:
      case 49:
      case 63:
      case 70:
      case 125:
// 600 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_zval_list(ppmsp[-2].minor.pp56, ppmsp[0].minor.pp56);
  pp_destructor(25,&ppmsp[-1].minor);
}
// 1726 "parser.c"
        break;
      case 11:
      case 42:
      case 45:
      case 116:
      case 126:
// 604 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_zval_list(ppmsp[0].minor.pp56, NULL);
}
// 1737 "parser.c"
        break;
      case 12:
      case 127:
// 610 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_column_item(PHQL_T_STARALL, NULL, NULL, NULL);
  pp_destructor(17,&ppmsp[0].minor);
}
// 1746 "parser.c"
        break;
      case 13:
// 614 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_column_item(PHQL_T_DOMAINALL, NULL, ppmsp[-2].minor.pp0, NULL);
  pp_destructor(31,&ppmsp[-1].minor);
  pp_destructor(17,&ppmsp[0].minor);
}
// 1755 "parser.c"
        break;
      case 14:
// 618 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_column_item(PHQL_T_EXPR, ppmsp[-2].minor.pp56, NULL, ppmsp[0].minor.pp0);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 1763 "parser.c"
        break;
      case 15:
// 622 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_column_item(PHQL_T_EXPR, ppmsp[-1].minor.pp56, NULL, ppmsp[0].minor.pp0);
}
// 1770 "parser.c"
        break;
      case 16:
// 626 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_column_item(PHQL_T_EXPR, ppmsp[0].minor.pp56, NULL, NULL);
}
// 1777 "parser.c"
        break;
      case 21:
      case 115:
// 650 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_zval_list(ppmsp[-1].minor.pp56, ppmsp[0].minor.pp56);
}
// 1785 "parser.c"
        break;
      case 24:
// 667 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_join_item(ppmsp[-3].minor.pp56, ppmsp[-2].minor.pp56, ppmsp[-1].minor.pp56, ppmsp[0].minor.pp56);
}
// 1792 "parser.c"
        break;
      case 25:
// 673 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_qualified_name(NULL, NULL, ppmsp[0].minor.pp0);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 1800 "parser.c"
        break;
      case 26:
      case 46:
      case 147:
// 677 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_qualified_name(NULL, NULL, ppmsp[0].minor.pp0);
}
// 1809 "parser.c"
        break;
      case 28:
// 687 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_join_type(PHQL_T_INNERJOIN);
  pp_destructor(33,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1818 "parser.c"
        break;
      case 29:
// 691 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_join_type(PHQL_T_CROSSJOIN);
  pp_destructor(35,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1827 "parser.c"
        break;
      case 30:
// 695 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  pp_destructor(36,&ppmsp[-2].minor);
  pp_destructor(37,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1837 "parser.c"
        break;
      case 31:
// 699 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  pp_destructor(36,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1846 "parser.c"
        break;
      case 32:
// 703 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  pp_destructor(38,&ppmsp[-2].minor);
  pp_destructor(37,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1856 "parser.c"
        break;
      case 33:
// 707 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  pp_destructor(38,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1865 "parser.c"
        break;
      case 34:
// 711 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_join_type(PHQL_T_FULLJOIN);
  pp_destructor(39,&ppmsp[-2].minor);
  pp_destructor(37,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1875 "parser.c"
        break;
      case 35:
// 715 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_join_type(PHQL_T_FULLJOIN);
  pp_destructor(39,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1884 "parser.c"
        break;
      case 36:
// 719 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_join_type(PHQL_T_INNERJOIN);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1892 "parser.c"
        break;
      case 37:
// 725 "parser.lemon"
{
	ppgotominor.pp56 = ppmsp[0].minor.pp56;
  pp_destructor(40,&ppmsp[-1].minor);
}
// 1900 "parser.c"
        break;
      case 39:
// 736 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_insert_statement(ppmsp[-4].minor.pp56, NULL, ppmsp[-1].minor.pp56);
  pp_destructor(41,&ppmsp[-6].minor);
  pp_destructor(42,&ppmsp[-5].minor);
  pp_destructor(43,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1912 "parser.c"
        break;
      case 40:
// 740 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_insert_statement(ppmsp[-7].minor.pp56, ppmsp[-5].minor.pp56, ppmsp[-1].minor.pp56);
  pp_destructor(41,&ppmsp[-9].minor);
  pp_destructor(42,&ppmsp[-8].minor);
  pp_destructor(44,&ppmsp[-6].minor);
  pp_destructor(45,&ppmsp[-4].minor);
  pp_destructor(43,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1926 "parser.c"
        break;
      case 47:
// 778 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_update_statement(ppmsp[-2].minor.pp56, ppmsp[-1].minor.pp56, ppmsp[0].minor.pp56);
}
// 1933 "parser.c"
        break;
      case 48:
// 784 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_update_clause(ppmsp[-2].minor.pp56, ppmsp[0].minor.pp56);
  pp_destructor(46,&ppmsp[-3].minor);
  pp_destructor(47,&ppmsp[-1].minor);
}
// 1942 "parser.c"
        break;
      case 51:
// 800 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_update_item(ppmsp[-2].minor.pp56, ppmsp[0].minor.pp56);
  pp_destructor(3,&ppmsp[-1].minor);
}
// 1950 "parser.c"
        break;
      case 53:
// 812 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_delete_statement(ppmsp[-2].minor.pp56, ppmsp[-1].minor.pp56, ppmsp[0].minor.pp56);
}
// 1957 "parser.c"
        break;
      case 54:
// 818 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_delete_clause(ppmsp[0].minor.pp56);
  pp_destructor(48,&ppmsp[-2].minor);
  pp_destructor(27,&ppmsp[-1].minor);
}
// 1966 "parser.c"
        break;
      case 55:
// 824 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_assoc_name(ppmsp[-2].minor.pp56, ppmsp[0].minor.pp0);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 1974 "parser.c"
        break;
      case 56:
// 828 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_assoc_name(ppmsp[-1].minor.pp56, ppmsp[0].minor.pp0);
}
// 1981 "parser.c"
        break;
      case 57:
// 832 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_assoc_name(ppmsp[0].minor.pp56, NULL);
}
// 1988 "parser.c"
        break;
      case 59:
// 844 "parser.lemon"
{
	ppgotominor.pp56 = ppmsp[0].minor.pp56;
  pp_destructor(49,&ppmsp[-1].minor);
}
// 1996 "parser.c"
        break;
      case 61:
// 854 "parser.lemon"
{
	ppgotominor.pp56 = ppmsp[0].minor.pp56;
  pp_destructor(50,&ppmsp[-2].minor);
  pp_destructor(51,&ppmsp[-1].minor);
}
// 2005 "parser.c"
        break;
      case 65:
// 874 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_order_item(ppmsp[0].minor.pp56, 0);
}
// 2012 "parser.c"
        break;
      case 66:
// 878 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_order_item(ppmsp[-1].minor.pp56, PHQL_T_ASC);
  pp_destructor(52,&ppmsp[0].minor);
}
// 2020 "parser.c"
        break;
      case 67:
// 882 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_order_item(ppmsp[-1].minor.pp56, PHQL_T_DESC);
  pp_destructor(53,&ppmsp[0].minor);
}
// 2028 "parser.c"
        break;
      case 68:
// 888 "parser.lemon"
{
	ppgotominor.pp56 = ppmsp[0].minor.pp56;
  pp_destructor(54,&ppmsp[-2].minor);
  pp_destructor(51,&ppmsp[-1].minor);
}
// 2037 "parser.c"
        break;
      case 73:
// 914 "parser.lemon"
{
	ppgotominor.pp56 = ppmsp[0].minor.pp56;
  pp_destructor(55,&ppmsp[-1].minor);
}
// 2045 "parser.c"
        break;
      case 75:
      case 79:
// 924 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_limit_clause(ppmsp[0].minor.pp56, NULL);
  pp_destructor(56,&ppmsp[-1].minor);
}
// 2054 "parser.c"
        break;
      case 76:
// 928 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_limit_clause(ppmsp[0].minor.pp56, ppmsp[-2].minor.pp56);
  pp_destructor(56,&ppmsp[-3].minor);
  pp_destructor(25,&ppmsp[-1].minor);
}
// 2063 "parser.c"
        break;
      case 77:
// 932 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_limit_clause(ppmsp[-2].minor.pp56, ppmsp[0].minor.pp56);
  pp_destructor(56,&ppmsp[-3].minor);
  pp_destructor(57,&ppmsp[-1].minor);
}
// 2072 "parser.c"
        break;
      case 81:
      case 136:
// 950 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_literal_zval(PHQL_T_INTEGER, ppmsp[0].minor.pp0);
}
// 2080 "parser.c"
        break;
      case 82:
      case 142:
// 954 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_placeholder_zval(PHQL_T_NPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 2088 "parser.c"
        break;
      case 83:
      case 143:
// 958 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_placeholder_zval(PHQL_T_SPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 2096 "parser.c"
        break;
      case 84:
// 964 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_MINUS, NULL, ppmsp[0].minor.pp56);
  pp_destructor(20,&ppmsp[-1].minor);
}
// 2104 "parser.c"
        break;
      case 85:
// 968 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_SUB, ppmsp[-2].minor.pp56, ppmsp[0].minor.pp56);
  pp_destructor(20,&ppmsp[-1].minor);
}
// 2112 "parser.c"
        break;
      case 86:
// 972 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_ADD, ppmsp[-2].minor.pp56, ppmsp[0].minor.pp56);
  pp_destructor(19,&ppmsp[-1].minor);
}
// 2120 "parser.c"
        break;
      case 87:
// 976 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_MUL, ppmsp[-2].minor.pp56, ppmsp[0].minor.pp56);
  pp_destructor(17,&ppmsp[-1].minor);
}
// 2128 "parser.c"
        break;
      case 88:
// 980 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_DIV, ppmsp[-2].minor.pp56, ppmsp[0].minor.pp56);
  pp_destructor(16,&ppmsp[-1].minor);
}
// 2136 "parser.c"
        break;
      case 89:
// 984 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_MOD, ppmsp[-2].minor.pp56, ppmsp[0].minor.pp56);
  pp_destructor(18,&ppmsp[-1].minor);
}
// 2144 "parser.c"
        break;
      case 90:
// 988 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_AND, ppmsp[-2].minor.pp56, ppmsp[0].minor.pp56);
  pp_destructor(9,&ppmsp[-1].minor);
}
// 2152 "parser.c"
        break;
      case 91:
// 992 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_OR, ppmsp[-2].minor.pp56, ppmsp[0].minor.pp56);
  pp_destructor(10,&ppmsp[-1].minor);
}
// 2160 "parser.c"
        break;
      case 92:
// 996 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_BITWISE_AND, ppmsp[-2].minor.pp56, ppmsp[0].minor.pp56);
  pp_destructor(13,&ppmsp[-1].minor);
}
// 2168 "parser.c"
        break;
      case 93:
// 1000 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_BITWISE_OR, ppmsp[-2].minor.pp56, ppmsp[0].minor.pp56);
  pp_destructor(14,&ppmsp[-1].minor);
}
// 2176 "parser.c"
        break;
      case 94:
// 1004 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_BITWISE_XOR, ppmsp[-2].minor.pp56, ppmsp[0].minor.pp56);
  pp_destructor(15,&ppmsp[-1].minor);
}
// 2184 "parser.c"
        break;
      case 95:
// 1008 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_EQUALS, ppmsp[-2].minor.pp56, ppmsp[0].minor.pp56);
  pp_destructor(3,&ppmsp[-1].minor);
}
// 2192 "parser.c"
        break;
      case 96:
// 1012 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_NOTEQUALS, ppmsp[-2].minor.pp56, ppmsp[0].minor.pp56);
  pp_destructor(4,&ppmsp[-1].minor);
}
// 2200 "parser.c"
        break;
      case 97:
// 1016 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_LESS, ppmsp[-2].minor.pp56, ppmsp[0].minor.pp56);
  pp_destructor(5,&ppmsp[-1].minor);
}
// 2208 "parser.c"
        break;
      case 98:
// 1020 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_GREATER, ppmsp[-2].minor.pp56, ppmsp[0].minor.pp56);
  pp_destructor(6,&ppmsp[-1].minor);
}
// 2216 "parser.c"
        break;
      case 99:
// 1024 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_GREATEREQUAL, ppmsp[-2].minor.pp56, ppmsp[0].minor.pp56);
  pp_destructor(7,&ppmsp[-1].minor);
}
// 2224 "parser.c"
        break;
      case 100:
// 1028 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_LESSEQUAL, ppmsp[-2].minor.pp56, ppmsp[0].minor.pp56);
  pp_destructor(8,&ppmsp[-1].minor);
}
// 2232 "parser.c"
        break;
      case 101:
// 1032 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_LIKE, ppmsp[-2].minor.pp56, ppmsp[0].minor.pp56);
  pp_destructor(11,&ppmsp[-1].minor);
}
// 2240 "parser.c"
        break;
      case 102:
// 1036 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_NLIKE, ppmsp[-3].minor.pp56, ppmsp[0].minor.pp56);
  pp_destructor(23,&ppmsp[-2].minor);
  pp_destructor(11,&ppmsp[-1].minor);
}
// 2249 "parser.c"
        break;
      case 103:
// 1040 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_ILIKE, ppmsp[-2].minor.pp56, ppmsp[0].minor.pp56);
  pp_destructor(12,&ppmsp[-1].minor);
}
// 2257 "parser.c"
        break;
      case 104:
// 1044 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_NILIKE, ppmsp[-3].minor.pp56, ppmsp[0].minor.pp56);
  pp_destructor(23,&ppmsp[-2].minor);
  pp_destructor(12,&ppmsp[-1].minor);
}
// 2266 "parser.c"
        break;
      case 105:
      case 108:
// 1048 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_IN, ppmsp[-4].minor.pp56, ppmsp[-1].minor.pp56);
  pp_destructor(22,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2277 "parser.c"
        break;
      case 106:
      case 109:
// 1052 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_NOTIN, ppmsp[-5].minor.pp56, ppmsp[-1].minor.pp56);
  pp_destructor(23,&ppmsp[-4].minor);
  pp_destructor(22,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2289 "parser.c"
        break;
      case 107:
// 1056 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_SUBQUERY, ppmsp[-1].minor.pp56, NULL);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2298 "parser.c"
        break;
      case 110:
// 1068 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_EXISTS, NULL, ppmsp[-1].minor.pp56);
  pp_destructor(61,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2308 "parser.c"
        break;
      case 111:
// 1072 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_AGAINST, ppmsp[-2].minor.pp56, ppmsp[0].minor.pp56);
  pp_destructor(1,&ppmsp[-1].minor);
}
// 2316 "parser.c"
        break;
      case 112:
// 1076 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_CAST, ppmsp[-3].minor.pp56, phql_ret_raw_qualified_name(ppmsp[-1].minor.pp0, NULL));
  pp_destructor(62,&ppmsp[-5].minor);
  pp_destructor(44,&ppmsp[-4].minor);
  pp_destructor(32,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2327 "parser.c"
        break;
      case 113:
// 1080 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_CONVERT, ppmsp[-3].minor.pp56, phql_ret_raw_qualified_name(ppmsp[-1].minor.pp0, NULL));
  pp_destructor(63,&ppmsp[-5].minor);
  pp_destructor(44,&ppmsp[-4].minor);
  pp_destructor(64,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2338 "parser.c"
        break;
      case 114:
// 1084 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_CASE, ppmsp[-2].minor.pp56, ppmsp[-1].minor.pp56);
  pp_destructor(65,&ppmsp[-3].minor);
  pp_destructor(66,&ppmsp[0].minor);
}
// 2347 "parser.c"
        break;
      case 117:
// 1096 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_WHEN, ppmsp[-2].minor.pp56, ppmsp[0].minor.pp56);
  pp_destructor(67,&ppmsp[-3].minor);
  pp_destructor(68,&ppmsp[-1].minor);
}
// 2356 "parser.c"
        break;
      case 118:
// 1100 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_ELSE, ppmsp[0].minor.pp56, NULL);
  pp_destructor(69,&ppmsp[-1].minor);
}
// 2364 "parser.c"
        break;
      case 120:
// 1110 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_func_call(ppmsp[-4].minor.pp0, ppmsp[-1].minor.pp56, ppmsp[-2].minor.pp56);
  pp_destructor(44,&ppmsp[-3].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2373 "parser.c"
        break;
      case 121:
// 1116 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_distinct();
  pp_destructor(28,&ppmsp[0].minor);
}
// 2381 "parser.c"
        break;
      case 129:
// 1154 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_ISNULL, ppmsp[-2].minor.pp56, NULL);
  pp_destructor(21,&ppmsp[-1].minor);
  pp_destructor(70,&ppmsp[0].minor);
}
// 2390 "parser.c"
        break;
      case 130:
// 1158 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_ISNOTNULL, ppmsp[-3].minor.pp56, NULL);
  pp_destructor(21,&ppmsp[-2].minor);
  pp_destructor(23,&ppmsp[-1].minor);
  pp_destructor(70,&ppmsp[0].minor);
}
// 2400 "parser.c"
        break;
      case 131:
// 1162 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_BETWEEN, ppmsp[-2].minor.pp56, ppmsp[0].minor.pp56);
  pp_destructor(2,&ppmsp[-1].minor);
}
// 2408 "parser.c"
        break;
      case 132:
// 1166 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_NOT, NULL, ppmsp[0].minor.pp56);
  pp_destructor(23,&ppmsp[-1].minor);
}
// 2416 "parser.c"
        break;
      case 133:
// 1170 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_BITWISE_NOT, NULL, ppmsp[0].minor.pp56);
  pp_destructor(24,&ppmsp[-1].minor);
}
// 2424 "parser.c"
        break;
      case 134:
// 1174 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_expr(PHQL_T_ENCLOSED, ppmsp[-1].minor.pp56, NULL);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2433 "parser.c"
        break;
      case 137:
// 1186 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_literal_zval(PHQL_T_STRING, ppmsp[0].minor.pp0);
}
// 2440 "parser.c"
        break;
      case 138:
// 1190 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_literal_zval(PHQL_T_DOUBLE, ppmsp[0].minor.pp0);
}
// 2447 "parser.c"
        break;
      case 139:
// 1194 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_literal_zval(PHQL_T_NULL, NULL);
  pp_destructor(70,&ppmsp[0].minor);
}
// 2455 "parser.c"
        break;
      case 140:
// 1198 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_literal_zval(PHQL_T_TRUE, NULL);
  pp_destructor(73,&ppmsp[0].minor);
}
// 2463 "parser.c"
        break;
      case 141:
// 1202 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_literal_zval(PHQL_T_FALSE, NULL);
  pp_destructor(74,&ppmsp[0].minor);
}
// 2471 "parser.c"
        break;
      case 144:
// 1214 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_placeholder_zval(PHQL_T_NTPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 2478 "parser.c"
        break;
      case 145:
// 1218 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_placeholder_zval(PHQL_T_STPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 2485 "parser.c"
        break;
      case 146:
// 1224 "parser.lemon"
{
	ppgotominor.pp56 = phql_ret_qualified_name(NULL, ppmsp[-2].minor.pp0, ppmsp[0].minor.pp0);
  pp_destructor(31,&ppmsp[-1].minor);
}
// 2493 "parser.c"
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

// 2602 "parser.c"
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
  { SL("ELSE"),          PHQL_T_ELSE },
  { SL("END"),           PHQL_T_END },
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
            case PHQL_T_ELSE:
                phql_(phql_parser, PHQL_ELSE, NULL, parser_status);
                break;

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
            case PHQL_T_NTPLACEHOLDER:
    			phql_parse_with_token(phql_parser, PHQL_T_NTPLACEHOLDER, PHQL_NTPLACEHOLDER, &token, parser_status);
    			break;
    		case PHQL_T_STPLACEHOLDER:
    			phql_parse_with_token(phql_parser, PHQL_T_STPLACEHOLDER, PHQL_STPLACEHOLDER, &token, parser_status);
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
