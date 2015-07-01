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

static zval *phql_ret_select_statement(zval *S, zval *W, zval *O, zval *G, zval *H, zval *L, zval *F)
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
	if (F != NULL) {
		add_assoc_zval(ret, "forUpdate", F);
	}

	return ret;
}

static zval *phql_ret_select_clause(zval *distinct, zval *columns, zval *tables, zval *with_list, zval *join_list)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	if (distinct) {
		add_assoc_zval(ret, "distinct", distinct);
	}

	add_assoc_zval(ret, "columns", columns);
	add_assoc_zval(ret, "tables", tables);

	if (with_list) {
		add_assoc_zval(ret, "with", with_list);
	}

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

static zval *phql_ret_for_update_clause()
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	ZVAL_BOOL(ret, 1);

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


// 459 "parser.c"
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
#define PPNOCODE 135
#define PPACTIONTYPE unsigned short int
#define phql_TOKENTYPE phql_parser_token*
typedef union {
  phql_TOKENTYPE pp0;
  zval* pp244;
  int pp269;
} PPMINORTYPE;
#define PPSTACKDEPTH 100
#define phql_ARG_SDECL phql_parser_status *status;
#define phql_ARG_PDECL ,phql_parser_status *status
#define phql_ARG_FETCH phql_parser_status *status = pppParser->status
#define phql_ARG_STORE pppParser->status = status
#define PPNSTATE 279
#define PPNRULE 156
#define PPERRORSYMBOL 79
#define PPERRSYMDT pp269
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
 /*     0 */    91,   97,   54,   56,   58,   60,   62,   64,   44,   46,
 /*    10 */    66,   71,   48,   50,   52,   40,   38,   42,   36,   33,
 /*    20 */    93,   73,   68,   36,   33,   93,   73,   68,  197,  206,
 /*    30 */    78,  204,   75,   91,   97,   54,   56,   58,   60,   62,
 /*    40 */    64,   44,   46,   66,   71,   48,   50,   52,   40,   38,
 /*    50 */    42,   36,   33,   93,   73,   68,   91,   97,   54,   56,
 /*    60 */    58,   60,   62,   64,   44,   46,   66,   71,   48,   50,
 /*    70 */    52,   40,   38,   42,   36,   33,   93,   73,   68,   91,
 /*    80 */    97,   54,   56,   58,   60,   62,   64,   44,   46,   66,
 /*    90 */    71,   48,   50,   52,   40,   38,   42,   36,   33,   93,
 /*   100 */    73,   68,  125,  279,  159,   93,   73,   68,   31,   32,
 /*   110 */    91,   97,   54,   56,   58,   60,   62,   64,   44,   46,
 /*   120 */    66,   71,   48,   50,   52,   40,   38,   42,   36,   33,
 /*   130 */    93,   73,   68,   48,   50,   52,   40,   38,   42,   36,
 /*   140 */    33,   93,   73,   68,  280,  117,   40,   38,   42,   36,
 /*   150 */    33,   93,   73,   68,  190,  101,  188,   91,   97,   54,
 /*   160 */    56,   58,   60,   62,   64,   44,   46,   66,   71,   48,
 /*   170 */    50,   52,   40,   38,   42,   36,   33,   93,   73,   68,
 /*   180 */    91,   97,   54,   56,   58,   60,   62,   64,   44,   46,
 /*   190 */    66,   71,   48,   50,   52,   40,   38,   42,   36,   33,
 /*   200 */    93,   73,   68,  167,  183,  169,  171,  137,  175,  179,
 /*   210 */   281,  111,   44,   46,   66,   71,   48,   50,   52,   40,
 /*   220 */    38,   42,   36,   33,   93,   73,   68,  127,  410,   91,
 /*   230 */    97,   54,   56,   58,   60,   62,   64,   44,   46,   66,
 /*   240 */    71,   48,   50,   52,   40,   38,   42,   36,   33,   93,
 /*   250 */    73,   68,  139,  133,  137,   34,   95,  244,  140,  142,
 /*   260 */    81,   75,  238,  246,   82,  130,  184,   84,  240,   85,
 /*   270 */   185,  245,  202,  144,  282,  211,  139,  144,  191,   34,
 /*   280 */    99,  136,  140,  142,  129,  158,  134,  155,  129,  130,
 /*   290 */    19,   20,   21,   22,  242,  145,  146,  152,  153,  104,
 /*   300 */   108,  114,   79,  120,   99,  411,   94,  196,  149,  147,
 /*   310 */   148,  150,  151,  154,  187,  241,  283,   69,  214,  145,
 /*   320 */   146,  152,  153,  104,  108,  114,  165,  120,  216,  265,
 /*   330 */   272,  268,  149,  147,  148,  150,  151,  154,   54,   56,
 /*   340 */    58,   60,   62,   64,   44,   46,   66,   71,   48,   50,
 /*   350 */    52,   40,   38,   42,   36,   33,   93,   73,   68,   34,
 /*   360 */   186,  133,  140,  142,  233,   75,  278,  187,  201,  130,
 /*   370 */   122,  161,  102,  187,  123,  125,    6,  159,  226,  165,
 /*   380 */   199,  144,  131,   34,   99,  165,  140,  142,    7,  100,
 /*   390 */   198,  203,  129,  200,  247,  138,  366,  256,   86,  145,
 /*   400 */   146,  152,  153,  104,  108,  114,    8,  120,   99,  144,
 /*   410 */   165,  144,  149,  147,  148,  150,  151,  154,   83,   84,
 /*   420 */   129,   85,  129,  145,  146,  152,  153,  104,  108,  114,
 /*   430 */   212,  120,  244,   30,    6,  224,  149,  147,  148,  150,
 /*   440 */   151,  154,  139,  251,  253,   34,  245,  133,  140,  142,
 /*   450 */    10,  231,  144,  144,  260,  130,   27,  223,  164,  192,
 /*   460 */   162,  263,  195,  129,  129,  248,    9,  144,  187,   34,
 /*   470 */    99,  144,  140,  142,   25,  210,  228,  232,  129,  130,
 /*   480 */   165,  155,  129,   11,  137,  145,  146,  152,  153,  104,
 /*   490 */   108,  114,  182,  120,   99,  180,  267,  268,  149,  147,
 /*   500 */   148,  150,  151,  154,  178,  219,  237,  176,   15,  145,
 /*   510 */   146,  152,  153,  104,  108,  114,  174,  120,  165,  172,
 /*   520 */   208,  209,  149,  147,  148,  150,  151,  154,  271,   66,
 /*   530 */    71,   48,   50,   52,   40,   38,   42,   36,   33,   93,
 /*   540 */    73,   68,   77,  244,   13,   30,  207,  203,  144,  270,
 /*   550 */   436,    1,    2,    3,    4,    5,    6,  243,  220,  129,
 /*   560 */    12,   75,    6,  144,   17,  144,   14,  144,  106,   29,
 /*   570 */   231,   16,    6,   35,  129,  133,  129,  235,  129,   57,
 /*   580 */    18,   24,  262,   28,  276,  257,   26,  222,   59,   74,
 /*   590 */   144,  273,   68,  144,  234,  144,  230,  157,   23,  144,
 /*   600 */    61,  129,   63,  218,  129,   76,  129,  144,  144,  155,
 /*   610 */   129,  131,   49,  166,  144,   43,   80,   87,  129,  129,
 /*   620 */   144,   96,  144,   89,   41,  129,   88,   51,   39,   53,
 /*   630 */    45,  129,  144,  129,  105,  144,   37,  225,  112,  103,
 /*   640 */   118,  109,   55,  129,  144,   65,  129,  144,  144,  144,
 /*   650 */   144,   67,   70,  107,  110,  129,  144,  144,  129,  129,
 /*   660 */   129,  129,  144,  113,  115,  144,  119,  129,  129,   72,
 /*   670 */   116,  144,  144,  129,  144,  121,  129,   90,  160,   92,
 /*   680 */   124,  242,  129,  129,  143,  129,  156,  126,  132,  144,
 /*   690 */   144,   98,  135,  141,  128,  144,   47,  144,  144,  144,
 /*   700 */   129,  129,  252,  215,  144,  158,  129,  144,  129,  129,
 /*   710 */   129,  144,  163,  144,  144,  129,  144,  157,  129,  168,
 /*   720 */   312,  193,  129,  144,  129,  129,  170,  129,  313,  173,
 /*   730 */   314,  315,  177,  316,  129,  317,  318,  181,  319,  320,
 /*   740 */   189,  194,  205,  229,  227,  213,  323,  255,  324,  217,
 /*   750 */   254,  258,  331,  221,  259,  261,  236,  365,  266,  239,
 /*   760 */   249,  269,  337,  264,  250,  274,  275,  277,
};
static PPCODETYPE pp_lookahead[] = {
 /*     0 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    10 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*    20 */    21,   22,   23,   19,   20,   21,   22,   23,   25,   30,
 /*    30 */    27,   32,   26,    1,    2,    3,    4,    5,    6,    7,
 /*    40 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*    50 */    18,   19,   20,   21,   22,   23,    1,    2,    3,    4,
 /*    60 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*    70 */    15,   16,   17,   18,   19,   20,   21,   22,   23,    1,
 /*    80 */     2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*    90 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   100 */    22,   23,   70,    0,   72,   21,   22,   23,   53,   54,
 /*   110 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*   120 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   130 */    21,   22,   23,   13,   14,   15,   16,   17,   18,   19,
 /*   140 */    20,   21,   22,   23,    0,   67,   16,   17,   18,   19,
 /*   150 */    20,   21,   22,   23,   30,   46,   32,    1,    2,    3,
 /*   160 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   170 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   180 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*   190 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   200 */    21,   22,   23,   34,   35,   36,   37,   25,   39,   40,
 /*   210 */     0,   32,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   220 */    17,   18,   19,   20,   21,   22,   23,   71,   46,    1,
 /*   230 */     2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   240 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   250 */    22,   23,   17,   99,   25,   20,   23,   99,   23,   24,
 /*   260 */    97,   26,   44,   45,  101,   30,  103,  104,  110,  106,
 /*   270 */    25,  113,   17,  119,    0,   46,   17,  119,   33,   20,
 /*   280 */    45,  127,   23,   24,  130,   30,  132,  133,  130,   30,
 /*   290 */    60,   61,   62,   63,   25,   60,   61,   62,   63,   64,
 /*   300 */    65,   66,   95,   68,   45,   46,   73,  100,   73,   74,
 /*   310 */    75,   76,   77,   78,  107,   46,    0,   11,   12,   60,
 /*   320 */    61,   62,   63,   64,   65,   66,  119,   68,   22,  117,
 /*   330 */   118,  119,   73,   74,   75,   76,   77,   78,    3,    4,
 /*   340 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   350 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   20,
 /*   360 */   100,   99,   23,   24,   50,   26,  100,  107,   31,   30,
 /*   370 */   128,  129,   82,  107,   69,   70,   86,   72,   55,  119,
 /*   380 */    17,  119,   45,   20,   45,  119,   23,   24,   87,   99,
 /*   390 */    98,   99,  130,   30,  111,  133,    0,  114,  107,   60,
 /*   400 */    61,   62,   63,   64,   65,   66,   88,   68,   45,  119,
 /*   410 */   119,  119,   73,   74,   75,   76,   77,   78,  103,  104,
 /*   420 */   130,  106,  130,   60,   61,   62,   63,   64,   65,   66,
 /*   430 */    82,   68,   99,   99,   86,   56,   73,   74,   75,   76,
 /*   440 */    77,   78,   17,  110,   25,   20,  113,   99,   23,   24,
 /*   450 */    90,   99,  119,  119,   58,   30,  122,  123,   30,  102,
 /*   460 */    32,  100,  105,  130,  130,   46,   89,  119,  107,   20,
 /*   470 */    45,  119,   23,   24,   51,  127,  124,  125,  130,   30,
 /*   480 */   119,  133,  130,   91,   25,   60,   61,   62,   63,   64,
 /*   490 */    65,   66,   35,   68,   45,   38,  118,  119,   73,   74,
 /*   500 */    75,   76,   77,   78,   35,   46,  107,   38,   58,   60,
 /*   510 */    61,   62,   63,   64,   65,   66,   35,   68,  119,   38,
 /*   520 */    28,   29,   73,   74,   75,   76,   77,   78,   99,   11,
 /*   530 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   540 */    22,   23,   94,   99,   57,   99,   98,   99,  119,  120,
 /*   550 */    80,   81,   82,   83,   84,   85,   86,  113,   82,  130,
 /*   560 */    92,   26,   86,  119,   25,  119,   47,  119,   82,  123,
 /*   570 */    99,  126,   86,   99,  130,   99,  130,   42,  130,   99,
 /*   580 */   126,  126,   47,   25,   49,  115,   52,   99,   99,   45,
 /*   590 */   119,  121,   23,  119,   99,  119,  125,   31,   59,  119,
 /*   600 */    99,  130,   99,  127,  130,   93,  130,  119,  119,  133,
 /*   610 */   130,   45,   99,   30,  119,   99,   96,  108,  130,  130,
 /*   620 */   119,   73,  119,   41,   99,  130,  109,   99,   99,   99,
 /*   630 */    99,  130,  119,  130,   45,  119,   99,   99,   30,   46,
 /*   640 */    30,   45,   99,  130,  119,   99,  130,  119,  119,  119,
 /*   650 */   119,   99,   99,   46,   99,  130,  119,  119,  130,  130,
 /*   660 */   130,  130,  119,   46,   45,  119,   46,  130,  130,   99,
 /*   670 */    99,  119,  119,  130,  119,   99,  130,   99,   99,   99,
 /*   680 */   129,   25,  130,  130,   99,  130,   28,   99,  131,  119,
 /*   690 */   119,   99,   46,   99,   99,  119,   99,  119,  119,  119,
 /*   700 */   130,  130,   46,   99,  119,   30,  130,  119,  130,  130,
 /*   710 */   130,  119,   30,  119,  119,  130,  119,   31,  130,   35,
 /*   720 */    30,  105,  130,  119,  130,  130,   35,  130,   30,   35,
 /*   730 */    30,   30,   35,   30,  130,   30,   30,   35,   30,   30,
 /*   740 */    30,   30,   30,   25,   52,   46,    0,   30,    0,   45,
 /*   750 */   114,   87,    0,   46,  116,  126,   43,    0,   25,   45,
 /*   760 */    44,    3,    0,   48,   45,   87,  116,   27,
};
#define PP_SHIFT_USE_DFLT (-2)
static short pp_shift_ofst[] = {
 /*     0 */   535,  103,  144,  210,  274,  316,  314,  323,  379,  423,
 /*    10 */   450,  487,   -2,  519,   -2,  230,  539,  230,   -2,   -2,
 /*    20 */    -2,   -2,   -2,  230,   -2,  534,  449,  558,  449,   -2,
 /*    30 */    55,   -2,   -2,  449,  449,   84,  449,   84,  449,    4,
 /*    40 */   449,    4,  449,    4,  449,  518,  449,  518,  449,  130,
 /*    50 */   449,  130,  449,  130,  449,  203,  449,  203,  449,  203,
 /*    60 */   449,  203,  449,  203,  449,  203,  449,  120,  306,  449,
 /*    70 */   569,  449,  120,  544,  235,  492,  363,    3,  583,  245,
 /*    80 */   169,   -2,  169,   -2,   -2,  583,  428,  582,   -2,  449,
 /*    90 */   228,  449,  228,  233,   -2,  548,   -2,  449,  335,  339,
 /*   100 */   109,   -2,  593,   -2,  589,    6,  607,   -2,  596,  449,
 /*   110 */   179,  608,  617,   -2,  619,  449,   78,  610,  620,   -2,
 /*   120 */   449,   32,  305,   -2,   -2,  449,  156,  449,  228,   -2,
 /*   130 */   566,  658,  259,  228,  646,   -2,  182,  425,   -2,   -2,
 /*   140 */   449,  569,  449,  569,   -2,   -2,   -2,   -2,   -2,   -2,
 /*   150 */    -2,   -2,   -2,   -2,   -2,   -2,   -2,  675,   -2,  449,
 /*   160 */   228,   -2,  682,   -2,   -2,   -2,  686,  684,  690,  691,
 /*   170 */   698,  481,  694,  700,  701,  469,  697,  703,  705,  457,
 /*   180 */   702,  706,  708,  709,   -2,  583,   -2,  124,  710,   -2,
 /*   190 */    -2,  711,  711,   -2,   -2,   -2,   -2,  363,   -2,   -2,
 /*   200 */   337,  255,   -2,   -1,  712,   -2,   -2,   -2,   -2,   -2,
 /*   210 */   229,   -2,  699,   -2,  449,  569,  704,  235,  459,   -2,
 /*   220 */   707,   -2,   84,   -2,  449,  228,  692,  449,  718,  449,
 /*   230 */    -2,  228,   -2,  449,  228,  713,  583,  218,  714,  449,
 /*   240 */   269,  746,  449,   -2,  228,   -2,  717,  419,  716,  719,
 /*   250 */   449,  656,  748,  717,   -2,   -2,   -2,  314,  396,  752,
 /*   260 */   230,  757,  583,  715,  583,  733,  583,   -2,  758,  449,
 /*   270 */    -2,  228,   -2,  314,  396,  762,  740,  583,   -2,
};
#define PP_REDUCE_USE_DFLT (-1)
static short pp_reduce_ofst[] = {
 /*     0 */   470,   -1,   -1,   -1,   -1,   -1,  301,  318,  377,  360,
 /*    10 */   392,  468,   -1,   -1,   -1,  445,   -1,  454,   -1,   -1,
 /*    20 */    -1,   -1,   -1,  455,   -1,   -1,  334,   -1,  446,   -1,
 /*    30 */    -1,   -1,   -1,  488,  474,   -1,  537,   -1,  529,   -1,
 /*    40 */   525,   -1,  516,   -1,  531,   -1,  597,   -1,  513,   -1,
 /*    50 */   528,   -1,  530,   -1,  543,   -1,  480,   -1,  489,   -1,
 /*    60 */   501,   -1,  503,   -1,  546,   -1,  552,   -1,   -1,  553,
 /*    70 */    -1,  570,   -1,   -1,  348,  512,  448,   -1,  207,  520,
 /*    80 */   163,   -1,  315,   -1,   -1,  291,  509,  517,   -1,  578,
 /*    90 */    -1,  580,   -1,   -1,   -1,   -1,   -1,  592,   -1,  290,
 /*   100 */    -1,   -1,   -1,   -1,   -1,  486,   -1,   -1,   -1,  555,
 /*   110 */    -1,   -1,   -1,   -1,   -1,  571,   -1,   -1,   -1,   -1,
 /*   120 */   576,  242,  551,   -1,   -1,  588,   -1,  595,   -1,   -1,
 /*   130 */    -1,  557,  154,   -1,   -1,   -1,   -1,  262,   -1,   -1,
 /*   140 */   594,   -1,  585,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   150 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  579,
 /*   160 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   170 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   180 */    -1,   -1,   -1,   -1,   -1,  260,   -1,   -1,   -1,   -1,
 /*   190 */    -1,  357,  616,   -1,   -1,   -1,   -1,  292,   -1,   -1,
 /*   200 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   210 */    -1,   -1,   -1,   -1,  604,   -1,   -1,  476,   -1,   -1,
 /*   220 */    -1,   -1,   -1,   -1,  538,   -1,   -1,  352,   -1,  471,
 /*   230 */    -1,   -1,   -1,  495,   -1,   -1,  399,   -1,   -1,  158,
 /*   240 */    -1,   -1,  444,   -1,   -1,   -1,  283,   -1,   -1,   -1,
 /*   250 */   333,   -1,   -1,  636,   -1,   -1,   -1,  664,  638,   -1,
 /*   260 */   629,   -1,  361,   -1,  212,   -1,  378,   -1,   -1,  429,
 /*   270 */    -1,   -1,   -1,  678,  650,   -1,   -1,  266,   -1,
};
static PPACTIONTYPE pp_default[] = {
 /*     0 */   435,  435,  435,  435,  435,  435,  344,  353,  358,  346,
 /*    10 */   364,  360,  284,  435,  359,  435,  361,  435,  362,  367,
 /*    20 */   368,  369,  370,  435,  363,  435,  435,  345,  435,  347,
 /*    30 */   349,  350,  351,  435,  435,  371,  435,  373,  435,  374,
 /*    40 */   435,  375,  435,  376,  435,  377,  435,  378,  435,  379,
 /*    50 */   435,  380,  435,  381,  435,  382,  435,  383,  435,  384,
 /*    60 */   435,  385,  435,  386,  435,  387,  435,  388,  435,  435,
 /*    70 */   389,  435,  390,  435,  435,  288,  435,  435,  435,  301,
 /*    80 */   299,  285,  298,  302,  304,  435,  311,  322,  308,  435,
 /*    90 */   321,  435,  398,  435,  416,  435,  417,  435,  418,  435,
 /*   100 */   435,  421,  435,  394,  435,  435,  435,  397,  435,  435,
 /*   110 */   435,  435,  435,  399,  435,  435,  435,  435,  435,  400,
 /*   120 */   435,  435,  435,  401,  402,  435,  435,  435,  404,  406,
 /*   130 */   434,  409,  435,  415,  435,  407,  435,  435,  412,  414,
 /*   140 */   435,  419,  435,  420,  422,  423,  424,  425,  426,  427,
 /*   150 */   428,  429,  430,  431,  432,  413,  408,  435,  433,  435,
 /*   160 */   405,  403,  435,  309,  310,  342,  434,  435,  435,  435,
 /*   170 */   435,  435,  435,  435,  435,  435,  435,  435,  435,  435,
 /*   180 */   435,  435,  435,  435,  303,  435,  296,  341,  435,  339,
 /*   190 */   340,  435,  300,  305,  307,  306,  297,  435,  289,  291,
 /*   200 */   434,  435,  292,  295,  435,  293,  294,  290,  286,  287,
 /*   210 */   435,  392,  435,  395,  435,  391,  435,  435,  435,  393,
 /*   220 */   435,  396,  372,  348,  435,  357,  435,  435,  352,  435,
 /*   230 */   354,  356,  355,  435,  343,  435,  435,  435,  435,  435,
 /*   240 */   435,  435,  435,  325,  327,  326,  435,  435,  435,  435,
 /*   250 */   435,  435,  435,  435,  328,  330,  329,  344,  435,  435,
 /*   260 */   435,  435,  435,  435,  435,  332,  435,  333,  435,  435,
 /*   270 */   335,  336,  334,  344,  435,  435,  435,  435,  338,
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
  "AS",            "WITH",          "INNER",         "JOIN",        
  "CROSS",         "LEFT",          "OUTER",         "RIGHT",       
  "FULL",          "ON",            "INSERT",        "INTO",        
  "VALUES",        "PARENTHESES_OPEN",  "PARENTHESES_CLOSE",  "UPDATE",      
  "SET",           "DELETE",        "WHERE",         "ORDER",       
  "BY",            "ASC",           "DESC",          "GROUP",       
  "HAVING",        "FOR",           "LIMIT",         "OFFSET",      
  "INTEGER",       "HINTEGER",      "NPLACEHOLDER",  "SPLACEHOLDER",
  "EXISTS",        "CAST",          "CONVERT",       "USING",       
  "CASE",          "END",           "WHEN",          "THEN",        
  "ELSE",          "NULL",          "STRING",        "DOUBLE",      
  "TRUE",          "FALSE",         "BPLACEHOLDER",  "error",       
  "program",       "query_language",  "select_statement",  "insert_statement",
  "update_statement",  "delete_statement",  "select_clause",  "where_clause",
  "group_clause",  "having_clause",  "order_clause",  "select_limit_clause",
  "for_update_clause",  "distinct_all",  "column_list",   "associated_name_list",
  "with_list_or_null",  "join_list_or_null",  "column_item",   "expr",        
  "associated_name",  "join_list",     "with_list",     "join_item",   
  "join_clause",   "with_item",     "join_type",     "aliased_or_qualified_name",
  "join_associated_name",  "join_conditions",  "values_list",   "field_list",  
  "value_list",    "value_item",    "field_item",    "update_clause",
  "limit_clause",  "update_item_list",  "update_item",   "qualified_name",
  "new_value",     "delete_clause",  "order_list",    "order_item",  
  "group_list",    "group_item",    "integer_or_placeholder",  "argument_list",
  "when_clauses",  "when_clause",   "function_call",  "distinct_or_null",
  "argument_list_or_null",  "argument_item",
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
 /*   5 */ "select_statement ::= select_clause where_clause group_clause having_clause order_clause select_limit_clause for_update_clause",
 /*   6 */ "select_clause ::= SELECT distinct_all column_list FROM associated_name_list with_list_or_null join_list_or_null",
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
 /*  21 */ "with_list_or_null ::= WITH with_list",
 /*  22 */ "with_list_or_null ::=",
 /*  23 */ "join_list ::= join_list join_item",
 /*  24 */ "join_list ::= join_item",
 /*  25 */ "join_item ::= join_clause",
 /*  26 */ "with_list ::= with_list with_item",
 /*  27 */ "with_list ::= with_item",
 /*  28 */ "with_item ::= IDENTIFIER",
 /*  29 */ "join_clause ::= join_type aliased_or_qualified_name join_associated_name join_conditions",
 /*  30 */ "join_associated_name ::= AS IDENTIFIER",
 /*  31 */ "join_associated_name ::= IDENTIFIER",
 /*  32 */ "join_associated_name ::=",
 /*  33 */ "join_type ::= INNER JOIN",
 /*  34 */ "join_type ::= CROSS JOIN",
 /*  35 */ "join_type ::= LEFT OUTER JOIN",
 /*  36 */ "join_type ::= LEFT JOIN",
 /*  37 */ "join_type ::= RIGHT OUTER JOIN",
 /*  38 */ "join_type ::= RIGHT JOIN",
 /*  39 */ "join_type ::= FULL OUTER JOIN",
 /*  40 */ "join_type ::= FULL JOIN",
 /*  41 */ "join_type ::= JOIN",
 /*  42 */ "join_conditions ::= ON expr",
 /*  43 */ "join_conditions ::=",
 /*  44 */ "insert_statement ::= INSERT INTO aliased_or_qualified_name VALUES PARENTHESES_OPEN values_list PARENTHESES_CLOSE",
 /*  45 */ "insert_statement ::= INSERT INTO aliased_or_qualified_name PARENTHESES_OPEN field_list PARENTHESES_CLOSE VALUES PARENTHESES_OPEN values_list PARENTHESES_CLOSE",
 /*  46 */ "values_list ::= values_list COMMA value_item",
 /*  47 */ "values_list ::= value_item",
 /*  48 */ "value_item ::= expr",
 /*  49 */ "field_list ::= field_list COMMA field_item",
 /*  50 */ "field_list ::= field_item",
 /*  51 */ "field_item ::= IDENTIFIER",
 /*  52 */ "update_statement ::= update_clause where_clause limit_clause",
 /*  53 */ "update_clause ::= UPDATE associated_name SET update_item_list",
 /*  54 */ "update_item_list ::= update_item_list COMMA update_item",
 /*  55 */ "update_item_list ::= update_item",
 /*  56 */ "update_item ::= qualified_name EQUALS new_value",
 /*  57 */ "new_value ::= expr",
 /*  58 */ "delete_statement ::= delete_clause where_clause limit_clause",
 /*  59 */ "delete_clause ::= DELETE FROM associated_name",
 /*  60 */ "associated_name ::= aliased_or_qualified_name AS IDENTIFIER",
 /*  61 */ "associated_name ::= aliased_or_qualified_name IDENTIFIER",
 /*  62 */ "associated_name ::= aliased_or_qualified_name",
 /*  63 */ "aliased_or_qualified_name ::= qualified_name",
 /*  64 */ "where_clause ::= WHERE expr",
 /*  65 */ "where_clause ::=",
 /*  66 */ "order_clause ::= ORDER BY order_list",
 /*  67 */ "order_clause ::=",
 /*  68 */ "order_list ::= order_list COMMA order_item",
 /*  69 */ "order_list ::= order_item",
 /*  70 */ "order_item ::= expr",
 /*  71 */ "order_item ::= expr ASC",
 /*  72 */ "order_item ::= expr DESC",
 /*  73 */ "group_clause ::= GROUP BY group_list",
 /*  74 */ "group_clause ::=",
 /*  75 */ "group_list ::= group_list COMMA group_item",
 /*  76 */ "group_list ::= group_item",
 /*  77 */ "group_item ::= expr",
 /*  78 */ "having_clause ::= HAVING expr",
 /*  79 */ "having_clause ::=",
 /*  80 */ "for_update_clause ::= FOR UPDATE",
 /*  81 */ "for_update_clause ::=",
 /*  82 */ "select_limit_clause ::= LIMIT integer_or_placeholder",
 /*  83 */ "select_limit_clause ::= LIMIT integer_or_placeholder COMMA integer_or_placeholder",
 /*  84 */ "select_limit_clause ::= LIMIT integer_or_placeholder OFFSET integer_or_placeholder",
 /*  85 */ "select_limit_clause ::=",
 /*  86 */ "limit_clause ::= LIMIT integer_or_placeholder",
 /*  87 */ "limit_clause ::=",
 /*  88 */ "integer_or_placeholder ::= INTEGER",
 /*  89 */ "integer_or_placeholder ::= HINTEGER",
 /*  90 */ "integer_or_placeholder ::= NPLACEHOLDER",
 /*  91 */ "integer_or_placeholder ::= SPLACEHOLDER",
 /*  92 */ "expr ::= MINUS expr",
 /*  93 */ "expr ::= expr MINUS expr",
 /*  94 */ "expr ::= expr PLUS expr",
 /*  95 */ "expr ::= expr TIMES expr",
 /*  96 */ "expr ::= expr DIVIDE expr",
 /*  97 */ "expr ::= expr MOD expr",
 /*  98 */ "expr ::= expr AND expr",
 /*  99 */ "expr ::= expr OR expr",
 /* 100 */ "expr ::= expr BITWISE_AND expr",
 /* 101 */ "expr ::= expr BITWISE_OR expr",
 /* 102 */ "expr ::= expr BITWISE_XOR expr",
 /* 103 */ "expr ::= expr EQUALS expr",
 /* 104 */ "expr ::= expr NOTEQUALS expr",
 /* 105 */ "expr ::= expr LESS expr",
 /* 106 */ "expr ::= expr GREATER expr",
 /* 107 */ "expr ::= expr GREATEREQUAL expr",
 /* 108 */ "expr ::= expr LESSEQUAL expr",
 /* 109 */ "expr ::= expr LIKE expr",
 /* 110 */ "expr ::= expr NOT LIKE expr",
 /* 111 */ "expr ::= expr ILIKE expr",
 /* 112 */ "expr ::= expr NOT ILIKE expr",
 /* 113 */ "expr ::= expr IN PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 114 */ "expr ::= expr NOT IN PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 115 */ "expr ::= PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 116 */ "expr ::= expr IN PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 117 */ "expr ::= expr NOT IN PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 118 */ "expr ::= EXISTS PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 119 */ "expr ::= expr AGAINST expr",
 /* 120 */ "expr ::= CAST PARENTHESES_OPEN expr AS IDENTIFIER PARENTHESES_CLOSE",
 /* 121 */ "expr ::= CONVERT PARENTHESES_OPEN expr USING IDENTIFIER PARENTHESES_CLOSE",
 /* 122 */ "expr ::= CASE expr when_clauses END",
 /* 123 */ "when_clauses ::= when_clauses when_clause",
 /* 124 */ "when_clauses ::= when_clause",
 /* 125 */ "when_clause ::= WHEN expr THEN expr",
 /* 126 */ "when_clause ::= ELSE expr",
 /* 127 */ "expr ::= function_call",
 /* 128 */ "function_call ::= IDENTIFIER PARENTHESES_OPEN distinct_or_null argument_list_or_null PARENTHESES_CLOSE",
 /* 129 */ "distinct_or_null ::= DISTINCT",
 /* 130 */ "distinct_or_null ::=",
 /* 131 */ "argument_list_or_null ::= argument_list",
 /* 132 */ "argument_list_or_null ::=",
 /* 133 */ "argument_list ::= argument_list COMMA argument_item",
 /* 134 */ "argument_list ::= argument_item",
 /* 135 */ "argument_item ::= TIMES",
 /* 136 */ "argument_item ::= expr",
 /* 137 */ "expr ::= expr IS NULL",
 /* 138 */ "expr ::= expr IS NOT NULL",
 /* 139 */ "expr ::= expr BETWEEN expr",
 /* 140 */ "expr ::= NOT expr",
 /* 141 */ "expr ::= BITWISE_NOT expr",
 /* 142 */ "expr ::= PARENTHESES_OPEN expr PARENTHESES_CLOSE",
 /* 143 */ "expr ::= qualified_name",
 /* 144 */ "expr ::= INTEGER",
 /* 145 */ "expr ::= HINTEGER",
 /* 146 */ "expr ::= STRING",
 /* 147 */ "expr ::= DOUBLE",
 /* 148 */ "expr ::= NULL",
 /* 149 */ "expr ::= TRUE",
 /* 150 */ "expr ::= FALSE",
 /* 151 */ "expr ::= NPLACEHOLDER",
 /* 152 */ "expr ::= SPLACEHOLDER",
 /* 153 */ "expr ::= BPLACEHOLDER",
 /* 154 */ "qualified_name ::= IDENTIFIER DOT IDENTIFIER",
 /* 155 */ "qualified_name ::= IDENTIFIER",
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
    case 77:
    case 78:
// 557 "parser.lemon"
{
	if ((pppminor->pp0)) {
		if ((pppminor->pp0)->free_flag) {
			efree((pppminor->pp0)->token);
		}
		efree((pppminor->pp0));
	}
}
// 1252 "parser.c"
      break;
    case 81:
    case 82:
    case 83:
    case 84:
    case 85:
    case 86:
    case 94:
    case 95:
    case 98:
    case 99:
    case 100:
    case 101:
    case 102:
    case 103:
    case 104:
    case 105:
    case 106:
    case 107:
    case 111:
    case 112:
    case 114:
    case 115:
    case 117:
    case 118:
    case 119:
    case 121:
    case 122:
    case 123:
    case 124:
    case 125:
    case 127:
    case 130:
    case 133:
// 570 "parser.lemon"
{ zval_ptr_dtor(&(pppminor->pp244)); }
// 1289 "parser.c"
      break;
    case 87:
    case 88:
    case 89:
    case 90:
    case 91:
    case 92:
    case 93:
    case 108:
    case 109:
    case 116:
    case 131:
    case 132:
// 882 "parser.lemon"
{ zephir_safe_zval_ptr_dtor((pppminor->pp244)); }
// 1305 "parser.c"
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
  { 80, 1 },
  { 81, 1 },
  { 81, 1 },
  { 81, 1 },
  { 81, 1 },
  { 82, 7 },
  { 86, 7 },
  { 93, 1 },
  { 93, 1 },
  { 93, 0 },
  { 94, 3 },
  { 94, 1 },
  { 98, 1 },
  { 98, 3 },
  { 98, 3 },
  { 98, 2 },
  { 98, 1 },
  { 95, 3 },
  { 95, 1 },
  { 97, 1 },
  { 97, 0 },
  { 96, 2 },
  { 96, 0 },
  { 101, 2 },
  { 101, 1 },
  { 103, 1 },
  { 102, 2 },
  { 102, 1 },
  { 105, 1 },
  { 104, 4 },
  { 108, 2 },
  { 108, 1 },
  { 108, 0 },
  { 106, 2 },
  { 106, 2 },
  { 106, 3 },
  { 106, 2 },
  { 106, 3 },
  { 106, 2 },
  { 106, 3 },
  { 106, 2 },
  { 106, 1 },
  { 109, 2 },
  { 109, 0 },
  { 83, 7 },
  { 83, 10 },
  { 110, 3 },
  { 110, 1 },
  { 113, 1 },
  { 111, 3 },
  { 111, 1 },
  { 114, 1 },
  { 84, 3 },
  { 115, 4 },
  { 117, 3 },
  { 117, 1 },
  { 118, 3 },
  { 120, 1 },
  { 85, 3 },
  { 121, 3 },
  { 100, 3 },
  { 100, 2 },
  { 100, 1 },
  { 107, 1 },
  { 87, 2 },
  { 87, 0 },
  { 90, 3 },
  { 90, 0 },
  { 122, 3 },
  { 122, 1 },
  { 123, 1 },
  { 123, 2 },
  { 123, 2 },
  { 88, 3 },
  { 88, 0 },
  { 124, 3 },
  { 124, 1 },
  { 125, 1 },
  { 89, 2 },
  { 89, 0 },
  { 92, 2 },
  { 92, 0 },
  { 91, 2 },
  { 91, 4 },
  { 91, 4 },
  { 91, 0 },
  { 116, 2 },
  { 116, 0 },
  { 126, 1 },
  { 126, 1 },
  { 126, 1 },
  { 126, 1 },
  { 99, 2 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 3 },
  { 99, 4 },
  { 99, 3 },
  { 99, 4 },
  { 99, 5 },
  { 99, 6 },
  { 99, 3 },
  { 99, 5 },
  { 99, 6 },
  { 99, 4 },
  { 99, 3 },
  { 99, 6 },
  { 99, 6 },
  { 99, 4 },
  { 128, 2 },
  { 128, 1 },
  { 129, 4 },
  { 129, 2 },
  { 99, 1 },
  { 130, 5 },
  { 131, 1 },
  { 131, 0 },
  { 132, 1 },
  { 132, 0 },
  { 127, 3 },
  { 127, 1 },
  { 133, 1 },
  { 133, 1 },
  { 99, 3 },
  { 99, 4 },
  { 99, 3 },
  { 99, 2 },
  { 99, 2 },
  { 99, 3 },
  { 99, 1 },
  { 99, 1 },
  { 99, 1 },
  { 99, 1 },
  { 99, 1 },
  { 99, 1 },
  { 99, 1 },
  { 99, 1 },
  { 99, 1 },
  { 99, 1 },
  { 99, 1 },
  { 119, 3 },
  { 119, 1 },
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
// 566 "parser.lemon"
{
	status->ret = ppmsp[0].minor.pp244;
}
// 1678 "parser.c"
        break;
      case 1:
      case 2:
      case 3:
      case 4:
      case 18:
      case 19:
      case 24:
      case 25:
      case 27:
      case 48:
      case 55:
      case 57:
      case 63:
      case 69:
      case 76:
      case 77:
      case 127:
      case 131:
      case 136:
      case 143:
// 572 "parser.lemon"
{
	ppgotominor.pp244 = ppmsp[0].minor.pp244;
}
// 1704 "parser.c"
        break;
      case 5:
// 590 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_select_statement(ppmsp[-6].minor.pp244, ppmsp[-5].minor.pp244, ppmsp[-2].minor.pp244, ppmsp[-4].minor.pp244, ppmsp[-3].minor.pp244, ppmsp[-1].minor.pp244, ppmsp[0].minor.pp244);
}
// 1711 "parser.c"
        break;
      case 6:
// 596 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_select_clause(ppmsp[-5].minor.pp244, ppmsp[-4].minor.pp244, ppmsp[-2].minor.pp244, ppmsp[-1].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(26,&ppmsp[-6].minor);
  pp_destructor(27,&ppmsp[-3].minor);
}
// 1720 "parser.c"
        break;
      case 7:
// 602 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_distinct_all(1);
  pp_destructor(28,&ppmsp[0].minor);
}
// 1728 "parser.c"
        break;
      case 8:
// 606 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_distinct_all(0);
  pp_destructor(29,&ppmsp[0].minor);
}
// 1736 "parser.c"
        break;
      case 9:
      case 20:
      case 22:
      case 32:
      case 43:
      case 65:
      case 67:
      case 74:
      case 79:
      case 81:
      case 85:
      case 87:
      case 130:
      case 132:
// 610 "parser.lemon"
{
	ppgotominor.pp244 = NULL;
}
// 1756 "parser.c"
        break;
      case 10:
      case 17:
      case 46:
      case 49:
      case 54:
      case 68:
      case 75:
      case 133:
// 616 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_zval_list(ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(25,&ppmsp[-1].minor);
}
// 1771 "parser.c"
        break;
      case 11:
      case 47:
      case 50:
      case 124:
      case 134:
// 620 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_zval_list(ppmsp[0].minor.pp244, NULL);
}
// 1782 "parser.c"
        break;
      case 12:
      case 135:
// 626 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_column_item(PHQL_T_STARALL, NULL, NULL, NULL);
  pp_destructor(17,&ppmsp[0].minor);
}
// 1791 "parser.c"
        break;
      case 13:
// 630 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_column_item(PHQL_T_DOMAINALL, NULL, ppmsp[-2].minor.pp0, NULL);
  pp_destructor(31,&ppmsp[-1].minor);
  pp_destructor(17,&ppmsp[0].minor);
}
// 1800 "parser.c"
        break;
      case 14:
// 634 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_column_item(PHQL_T_EXPR, ppmsp[-2].minor.pp244, NULL, ppmsp[0].minor.pp0);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 1808 "parser.c"
        break;
      case 15:
// 638 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_column_item(PHQL_T_EXPR, ppmsp[-1].minor.pp244, NULL, ppmsp[0].minor.pp0);
}
// 1815 "parser.c"
        break;
      case 16:
// 642 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_column_item(PHQL_T_EXPR, ppmsp[0].minor.pp244, NULL, NULL);
}
// 1822 "parser.c"
        break;
      case 21:
// 664 "parser.lemon"
{
	ppgotominor.pp244 = ppmsp[0].minor.pp244;
  pp_destructor(33,&ppmsp[-1].minor);
}
// 1830 "parser.c"
        break;
      case 23:
      case 26:
      case 123:
// 674 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_zval_list(ppmsp[-1].minor.pp244, ppmsp[0].minor.pp244);
}
// 1839 "parser.c"
        break;
      case 28:
      case 31:
      case 51:
      case 155:
// 700 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_qualified_name(NULL, NULL, ppmsp[0].minor.pp0);
}
// 1849 "parser.c"
        break;
      case 29:
// 707 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_join_item(ppmsp[-3].minor.pp244, ppmsp[-2].minor.pp244, ppmsp[-1].minor.pp244, ppmsp[0].minor.pp244);
}
// 1856 "parser.c"
        break;
      case 30:
// 713 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_qualified_name(NULL, NULL, ppmsp[0].minor.pp0);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 1864 "parser.c"
        break;
      case 33:
// 727 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_join_type(PHQL_T_INNERJOIN);
  pp_destructor(34,&ppmsp[-1].minor);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1873 "parser.c"
        break;
      case 34:
// 731 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_join_type(PHQL_T_CROSSJOIN);
  pp_destructor(36,&ppmsp[-1].minor);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1882 "parser.c"
        break;
      case 35:
// 735 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  pp_destructor(37,&ppmsp[-2].minor);
  pp_destructor(38,&ppmsp[-1].minor);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1892 "parser.c"
        break;
      case 36:
// 739 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  pp_destructor(37,&ppmsp[-1].minor);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1901 "parser.c"
        break;
      case 37:
// 743 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  pp_destructor(39,&ppmsp[-2].minor);
  pp_destructor(38,&ppmsp[-1].minor);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1911 "parser.c"
        break;
      case 38:
// 747 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  pp_destructor(39,&ppmsp[-1].minor);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1920 "parser.c"
        break;
      case 39:
// 751 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_join_type(PHQL_T_FULLJOIN);
  pp_destructor(40,&ppmsp[-2].minor);
  pp_destructor(38,&ppmsp[-1].minor);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1930 "parser.c"
        break;
      case 40:
// 755 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_join_type(PHQL_T_FULLJOIN);
  pp_destructor(40,&ppmsp[-1].minor);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1939 "parser.c"
        break;
      case 41:
// 759 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_join_type(PHQL_T_INNERJOIN);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1947 "parser.c"
        break;
      case 42:
// 765 "parser.lemon"
{
	ppgotominor.pp244 = ppmsp[0].minor.pp244;
  pp_destructor(41,&ppmsp[-1].minor);
}
// 1955 "parser.c"
        break;
      case 44:
// 776 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_insert_statement(ppmsp[-4].minor.pp244, NULL, ppmsp[-1].minor.pp244);
  pp_destructor(42,&ppmsp[-6].minor);
  pp_destructor(43,&ppmsp[-5].minor);
  pp_destructor(44,&ppmsp[-3].minor);
  pp_destructor(45,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 1967 "parser.c"
        break;
      case 45:
// 780 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_insert_statement(ppmsp[-7].minor.pp244, ppmsp[-5].minor.pp244, ppmsp[-1].minor.pp244);
  pp_destructor(42,&ppmsp[-9].minor);
  pp_destructor(43,&ppmsp[-8].minor);
  pp_destructor(45,&ppmsp[-6].minor);
  pp_destructor(46,&ppmsp[-4].minor);
  pp_destructor(44,&ppmsp[-3].minor);
  pp_destructor(45,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 1981 "parser.c"
        break;
      case 52:
// 818 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_update_statement(ppmsp[-2].minor.pp244, ppmsp[-1].minor.pp244, ppmsp[0].minor.pp244);
}
// 1988 "parser.c"
        break;
      case 53:
// 824 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_update_clause(ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(47,&ppmsp[-3].minor);
  pp_destructor(48,&ppmsp[-1].minor);
}
// 1997 "parser.c"
        break;
      case 56:
// 840 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_update_item(ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(3,&ppmsp[-1].minor);
}
// 2005 "parser.c"
        break;
      case 58:
// 852 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_delete_statement(ppmsp[-2].minor.pp244, ppmsp[-1].minor.pp244, ppmsp[0].minor.pp244);
}
// 2012 "parser.c"
        break;
      case 59:
// 858 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_delete_clause(ppmsp[0].minor.pp244);
  pp_destructor(49,&ppmsp[-2].minor);
  pp_destructor(27,&ppmsp[-1].minor);
}
// 2021 "parser.c"
        break;
      case 60:
// 864 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_assoc_name(ppmsp[-2].minor.pp244, ppmsp[0].minor.pp0);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 2029 "parser.c"
        break;
      case 61:
// 868 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_assoc_name(ppmsp[-1].minor.pp244, ppmsp[0].minor.pp0);
}
// 2036 "parser.c"
        break;
      case 62:
// 872 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_assoc_name(ppmsp[0].minor.pp244, NULL);
}
// 2043 "parser.c"
        break;
      case 64:
// 884 "parser.lemon"
{
	ppgotominor.pp244 = ppmsp[0].minor.pp244;
  pp_destructor(50,&ppmsp[-1].minor);
}
// 2051 "parser.c"
        break;
      case 66:
// 894 "parser.lemon"
{
	ppgotominor.pp244 = ppmsp[0].minor.pp244;
  pp_destructor(51,&ppmsp[-2].minor);
  pp_destructor(52,&ppmsp[-1].minor);
}
// 2060 "parser.c"
        break;
      case 70:
// 914 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_order_item(ppmsp[0].minor.pp244, 0);
}
// 2067 "parser.c"
        break;
      case 71:
// 918 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_order_item(ppmsp[-1].minor.pp244, PHQL_T_ASC);
  pp_destructor(53,&ppmsp[0].minor);
}
// 2075 "parser.c"
        break;
      case 72:
// 922 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_order_item(ppmsp[-1].minor.pp244, PHQL_T_DESC);
  pp_destructor(54,&ppmsp[0].minor);
}
// 2083 "parser.c"
        break;
      case 73:
// 928 "parser.lemon"
{
	ppgotominor.pp244 = ppmsp[0].minor.pp244;
  pp_destructor(55,&ppmsp[-2].minor);
  pp_destructor(52,&ppmsp[-1].minor);
}
// 2092 "parser.c"
        break;
      case 78:
// 954 "parser.lemon"
{
	ppgotominor.pp244 = ppmsp[0].minor.pp244;
  pp_destructor(56,&ppmsp[-1].minor);
}
// 2100 "parser.c"
        break;
      case 80:
// 964 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_for_update_clause();
  pp_destructor(57,&ppmsp[-1].minor);
  pp_destructor(47,&ppmsp[0].minor);
}
// 2109 "parser.c"
        break;
      case 82:
      case 86:
// 974 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_limit_clause(ppmsp[0].minor.pp244, NULL);
  pp_destructor(58,&ppmsp[-1].minor);
}
// 2118 "parser.c"
        break;
      case 83:
// 978 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_limit_clause(ppmsp[0].minor.pp244, ppmsp[-2].minor.pp244);
  pp_destructor(58,&ppmsp[-3].minor);
  pp_destructor(25,&ppmsp[-1].minor);
}
// 2127 "parser.c"
        break;
      case 84:
// 982 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_limit_clause(ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(58,&ppmsp[-3].minor);
  pp_destructor(59,&ppmsp[-1].minor);
}
// 2136 "parser.c"
        break;
      case 88:
      case 144:
// 1000 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_literal_zval(PHQL_T_INTEGER, ppmsp[0].minor.pp0);
}
// 2144 "parser.c"
        break;
      case 89:
      case 145:
// 1004 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_literal_zval(PHQL_T_HINTEGER, ppmsp[0].minor.pp0);
}
// 2152 "parser.c"
        break;
      case 90:
      case 151:
// 1008 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_placeholder_zval(PHQL_T_NPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 2160 "parser.c"
        break;
      case 91:
      case 152:
// 1012 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_placeholder_zval(PHQL_T_SPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 2168 "parser.c"
        break;
      case 92:
// 1018 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_MINUS, NULL, ppmsp[0].minor.pp244);
  pp_destructor(20,&ppmsp[-1].minor);
}
// 2176 "parser.c"
        break;
      case 93:
// 1022 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_SUB, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(20,&ppmsp[-1].minor);
}
// 2184 "parser.c"
        break;
      case 94:
// 1026 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_ADD, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(19,&ppmsp[-1].minor);
}
// 2192 "parser.c"
        break;
      case 95:
// 1030 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_MUL, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(17,&ppmsp[-1].minor);
}
// 2200 "parser.c"
        break;
      case 96:
// 1034 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_DIV, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(16,&ppmsp[-1].minor);
}
// 2208 "parser.c"
        break;
      case 97:
// 1038 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_MOD, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(18,&ppmsp[-1].minor);
}
// 2216 "parser.c"
        break;
      case 98:
// 1042 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_AND, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(9,&ppmsp[-1].minor);
}
// 2224 "parser.c"
        break;
      case 99:
// 1046 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_OR, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(10,&ppmsp[-1].minor);
}
// 2232 "parser.c"
        break;
      case 100:
// 1050 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_BITWISE_AND, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(13,&ppmsp[-1].minor);
}
// 2240 "parser.c"
        break;
      case 101:
// 1054 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_BITWISE_OR, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(14,&ppmsp[-1].minor);
}
// 2248 "parser.c"
        break;
      case 102:
// 1058 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_BITWISE_XOR, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(15,&ppmsp[-1].minor);
}
// 2256 "parser.c"
        break;
      case 103:
// 1062 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_EQUALS, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(3,&ppmsp[-1].minor);
}
// 2264 "parser.c"
        break;
      case 104:
// 1066 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_NOTEQUALS, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(4,&ppmsp[-1].minor);
}
// 2272 "parser.c"
        break;
      case 105:
// 1070 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_LESS, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(5,&ppmsp[-1].minor);
}
// 2280 "parser.c"
        break;
      case 106:
// 1074 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_GREATER, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(6,&ppmsp[-1].minor);
}
// 2288 "parser.c"
        break;
      case 107:
// 1078 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_GREATEREQUAL, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(7,&ppmsp[-1].minor);
}
// 2296 "parser.c"
        break;
      case 108:
// 1082 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_LESSEQUAL, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(8,&ppmsp[-1].minor);
}
// 2304 "parser.c"
        break;
      case 109:
// 1086 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_LIKE, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(11,&ppmsp[-1].minor);
}
// 2312 "parser.c"
        break;
      case 110:
// 1090 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_NLIKE, ppmsp[-3].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(23,&ppmsp[-2].minor);
  pp_destructor(11,&ppmsp[-1].minor);
}
// 2321 "parser.c"
        break;
      case 111:
// 1094 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_ILIKE, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(12,&ppmsp[-1].minor);
}
// 2329 "parser.c"
        break;
      case 112:
// 1098 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_NILIKE, ppmsp[-3].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(23,&ppmsp[-2].minor);
  pp_destructor(12,&ppmsp[-1].minor);
}
// 2338 "parser.c"
        break;
      case 113:
      case 116:
// 1102 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_IN, ppmsp[-4].minor.pp244, ppmsp[-1].minor.pp244);
  pp_destructor(22,&ppmsp[-3].minor);
  pp_destructor(45,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 2349 "parser.c"
        break;
      case 114:
      case 117:
// 1106 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_NOTIN, ppmsp[-5].minor.pp244, ppmsp[-1].minor.pp244);
  pp_destructor(23,&ppmsp[-4].minor);
  pp_destructor(22,&ppmsp[-3].minor);
  pp_destructor(45,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 2361 "parser.c"
        break;
      case 115:
// 1110 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_SUBQUERY, ppmsp[-1].minor.pp244, NULL);
  pp_destructor(45,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 2370 "parser.c"
        break;
      case 118:
// 1122 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_EXISTS, NULL, ppmsp[-1].minor.pp244);
  pp_destructor(64,&ppmsp[-3].minor);
  pp_destructor(45,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 2380 "parser.c"
        break;
      case 119:
// 1126 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_AGAINST, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(1,&ppmsp[-1].minor);
}
// 2388 "parser.c"
        break;
      case 120:
// 1130 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_CAST, ppmsp[-3].minor.pp244, phql_ret_raw_qualified_name(ppmsp[-1].minor.pp0, NULL));
  pp_destructor(65,&ppmsp[-5].minor);
  pp_destructor(45,&ppmsp[-4].minor);
  pp_destructor(32,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 2399 "parser.c"
        break;
      case 121:
// 1134 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_CONVERT, ppmsp[-3].minor.pp244, phql_ret_raw_qualified_name(ppmsp[-1].minor.pp0, NULL));
  pp_destructor(66,&ppmsp[-5].minor);
  pp_destructor(45,&ppmsp[-4].minor);
  pp_destructor(67,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 2410 "parser.c"
        break;
      case 122:
// 1138 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_CASE, ppmsp[-2].minor.pp244, ppmsp[-1].minor.pp244);
  pp_destructor(68,&ppmsp[-3].minor);
  pp_destructor(69,&ppmsp[0].minor);
}
// 2419 "parser.c"
        break;
      case 125:
// 1150 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_WHEN, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(70,&ppmsp[-3].minor);
  pp_destructor(71,&ppmsp[-1].minor);
}
// 2428 "parser.c"
        break;
      case 126:
// 1154 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_ELSE, ppmsp[0].minor.pp244, NULL);
  pp_destructor(72,&ppmsp[-1].minor);
}
// 2436 "parser.c"
        break;
      case 128:
// 1164 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_func_call(ppmsp[-4].minor.pp0, ppmsp[-1].minor.pp244, ppmsp[-2].minor.pp244);
  pp_destructor(45,&ppmsp[-3].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 2445 "parser.c"
        break;
      case 129:
// 1170 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_distinct();
  pp_destructor(28,&ppmsp[0].minor);
}
// 2453 "parser.c"
        break;
      case 137:
// 1208 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_ISNULL, ppmsp[-2].minor.pp244, NULL);
  pp_destructor(21,&ppmsp[-1].minor);
  pp_destructor(73,&ppmsp[0].minor);
}
// 2462 "parser.c"
        break;
      case 138:
// 1212 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_ISNOTNULL, ppmsp[-3].minor.pp244, NULL);
  pp_destructor(21,&ppmsp[-2].minor);
  pp_destructor(23,&ppmsp[-1].minor);
  pp_destructor(73,&ppmsp[0].minor);
}
// 2472 "parser.c"
        break;
      case 139:
// 1216 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_BETWEEN, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(2,&ppmsp[-1].minor);
}
// 2480 "parser.c"
        break;
      case 140:
// 1220 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_NOT, NULL, ppmsp[0].minor.pp244);
  pp_destructor(23,&ppmsp[-1].minor);
}
// 2488 "parser.c"
        break;
      case 141:
// 1224 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_BITWISE_NOT, NULL, ppmsp[0].minor.pp244);
  pp_destructor(24,&ppmsp[-1].minor);
}
// 2496 "parser.c"
        break;
      case 142:
// 1228 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_ENCLOSED, ppmsp[-1].minor.pp244, NULL);
  pp_destructor(45,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 2505 "parser.c"
        break;
      case 146:
// 1244 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_literal_zval(PHQL_T_STRING, ppmsp[0].minor.pp0);
}
// 2512 "parser.c"
        break;
      case 147:
// 1248 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_literal_zval(PHQL_T_DOUBLE, ppmsp[0].minor.pp0);
}
// 2519 "parser.c"
        break;
      case 148:
// 1252 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_literal_zval(PHQL_T_NULL, NULL);
  pp_destructor(73,&ppmsp[0].minor);
}
// 2527 "parser.c"
        break;
      case 149:
// 1256 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_literal_zval(PHQL_T_TRUE, NULL);
  pp_destructor(76,&ppmsp[0].minor);
}
// 2535 "parser.c"
        break;
      case 150:
// 1260 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_literal_zval(PHQL_T_FALSE, NULL);
  pp_destructor(77,&ppmsp[0].minor);
}
// 2543 "parser.c"
        break;
      case 153:
// 1275 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_placeholder_zval(PHQL_T_BPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 2550 "parser.c"
        break;
      case 154:
// 1281 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_qualified_name(NULL, ppmsp[-2].minor.pp0, ppmsp[0].minor.pp0);
  pp_destructor(31,&ppmsp[-1].minor);
}
// 2558 "parser.c"
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
// 490 "parser.lemon"

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

// 2667 "parser.c"
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
  | Phalcon Framework													  |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)	   |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled	 |
  | with this package in the file docs/LICENSE.txt.						|
  |																		|
  | If you did not receive a copy of the license and are unable to		 |
  | obtain it through the world-wide-web, please send an email			 |
  | to license@phalconphp.com so we can send you a copy immediately.	   |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>					  |
  |		  Eduar Carvajal <eduar@phalconphp.com>						 |
  +------------------------------------------------------------------------+
*/

const phql_token_names phql_tokens[] =
{
  { SL("INTEGER"),			   PHQL_T_INTEGER },
  { SL("DOUBLE"),			   PHQL_T_DOUBLE },
  { SL("STRING"),			   PHQL_T_STRING },
  { SL("IDENTIFIER"),		   PHQL_T_IDENTIFIER },
  { SL("HEXAINTEGER"),		   PHQL_T_HINTEGER },
  { SL("MINUS"),			   PHQL_T_MINUS },
  { SL("+"),				   PHQL_T_ADD },
  { SL("-"),				   PHQL_T_SUB },
  { SL("*"),				   PHQL_T_MUL },
  { SL("/"),				   PHQL_T_DIV },
  { SL("&"),				   PHQL_T_BITWISE_AND },
  { SL("|"),				   PHQL_T_BITWISE_OR },
  { SL("%%"),				   PHQL_T_MOD },
  { SL("AND"),				   PHQL_T_AND },
  { SL("OR"),				   PHQL_T_OR },
  { SL("LIKE"),				   PHQL_T_LIKE },
  { SL("ILIKE"),			   PHQL_T_ILIKE },
  { SL("DOT"),				   PHQL_T_DOT },
  { SL("COLON"),			   PHQL_T_COLON },
  { SL("COMMA"),			   PHQL_T_COMMA },
  { SL("EQUALS"),			   PHQL_T_EQUALS },
  { SL("NOT EQUALS"),		   PHQL_T_NOTEQUALS },
  { SL("NOT"),				   PHQL_T_NOT },
  { SL("<"),				   PHQL_T_LESS },
  { SL("<="),				   PHQL_T_LESSEQUAL },
  { SL(">"),				   PHQL_T_GREATER },
  { SL(">="),				   PHQL_T_GREATEREQUAL },
  { SL("("),				   PHQL_T_PARENTHESES_OPEN },
  { SL(")"),				   PHQL_T_PARENTHESES_CLOSE },
  { SL("NUMERIC PLACEHOLDER"), PHQL_T_NPLACEHOLDER },
  { SL("STRING PLACEHOLDER"),  PHQL_T_SPLACEHOLDER },
  { SL("UPDATE"),			   PHQL_T_UPDATE },
  { SL("SET"),				   PHQL_T_SET },
  { SL("WHERE"),			   PHQL_T_WHERE },
  { SL("DELETE"),			   PHQL_T_DELETE },
  { SL("FROM"),				   PHQL_T_FROM },
  { SL("AS"),				   PHQL_T_AS },
  { SL("INSERT"),			   PHQL_T_INSERT },
  { SL("INTO"),				   PHQL_T_INTO },
  { SL("VALUES"),			   PHQL_T_VALUES },
  { SL("SELECT"),			   PHQL_T_SELECT },
  { SL("ORDER"),			   PHQL_T_ORDER },
  { SL("BY"),			       PHQL_T_BY },
  { SL("LIMIT"),		       PHQL_T_LIMIT },
  { SL("OFFSET"),		       PHQL_T_OFFSET },
  { SL("GROUP"),		       PHQL_T_GROUP },
  { SL("HAVING"),		       PHQL_T_HAVING },
  { SL("IN"),			       PHQL_T_IN },
  { SL("ON"),			       PHQL_T_ON },
  { SL("INNER"),		       PHQL_T_INNER },
  { SL("JOIN"),		           PHQL_T_JOIN },
  { SL("LEFT"),		           PHQL_T_LEFT },
  { SL("RIGHT"),		       PHQL_T_RIGHT },
  { SL("IS"),			       PHQL_T_IS },
  { SL("NULL"),		           PHQL_T_NULL },
  { SL("NOT IN"),		       PHQL_T_NOTIN },
  { SL("CROSS"),		       PHQL_T_CROSS },
  { SL("OUTER"),		       PHQL_T_OUTER },
  { SL("FULL"),		           PHQL_T_FULL },
  { SL("ASC"),		           PHQL_T_ASC },
  { SL("DESC"),		           PHQL_T_DESC },
  { SL("BETWEEN"),	           PHQL_T_BETWEEN },
  { SL("DISTINCT"),	           PHQL_T_DISTINCT },
  { SL("AGAINST"),	           PHQL_T_AGAINST },
  { SL("CAST"),		           PHQL_T_CAST },
  { SL("CONVERT"),	           PHQL_T_CONVERT },
  { SL("USING"),		       PHQL_T_USING },
  { SL("ALL"),		           PHQL_T_ALL },
  { SL("EXISTS"),		       PHQL_T_EXISTS },
  { SL("CASE"),		           PHQL_T_CASE },
  { SL("WHEN"),		           PHQL_T_WHEN },
  { SL("THEN"),		           PHQL_T_THEN },
  { SL("ELSE"),		           PHQL_T_ELSE },
  { SL("END"),		           PHQL_T_END },
  { SL("FOR"),		           PHQL_T_FOR },
  { SL("WITH"),		           PHQL_T_WITH },
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
			case PHQL_T_FOR:
				phql_(phql_parser, PHQL_FOR, NULL, parser_status);
				break;
            case PHQL_T_WITH:
    			phql_(phql_parser, PHQL_WITH, NULL, parser_status);
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
			case PHQL_T_HINTEGER:
				if (parser_status->enable_literals) {
					phql_parse_with_token(phql_parser, PHQL_T_HINTEGER, PHQL_HINTEGER, &token, parser_status);
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
			case PHQL_T_BPLACEHOLDER:
				phql_parse_with_token(phql_parser, PHQL_T_BPLACEHOLDER, PHQL_BPLACEHOLDER, &token, parser_status);
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
