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
#define PPNSTATE 280
#define PPNRULE 157
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
 /*     0 */    92,   98,   55,   57,   59,   61,   63,   65,   45,   47,
 /*    10 */    67,   72,   49,   51,   53,   41,   39,   43,   37,   34,
 /*    20 */    94,   74,   69,   92,   98,   55,   57,   59,   61,   63,
 /*    30 */    65,   45,   47,   67,   72,   49,   51,   53,   41,   39,
 /*    40 */    43,   37,   34,   94,   74,   69,   19,   20,   21,   22,
 /*    50 */    23,  106,   32,   33,   92,   98,   55,   57,   59,   61,
 /*    60 */    63,   65,   45,   47,   67,   72,   49,   51,   53,   41,
 /*    70 */    39,   43,   37,   34,   94,   74,   69,   94,   74,   69,
 /*    80 */    82,   70,  215,  207,   83,  205,  185,   85,  165,   86,
 /*    90 */   163,  193,  217,  126,  196,  160,  234,   92,   98,   55,
 /*   100 */    57,   59,   61,   63,   65,   45,   47,   67,   72,   49,
 /*   110 */    51,   53,   41,   39,   43,   37,   34,   94,   74,   69,
 /*   120 */    92,   98,   55,   57,   59,   61,   63,   65,   45,   47,
 /*   130 */    67,   72,   49,   51,   53,   41,   39,   43,   37,   34,
 /*   140 */    94,   74,   69,   92,   98,   55,   57,   59,   61,   63,
 /*   150 */    65,   45,   47,   67,   72,   49,   51,   53,   41,   39,
 /*   160 */    43,   37,   34,   94,   74,   69,  239,  247,  128,   45,
 /*   170 */    47,   67,   72,   49,   51,   53,   41,   39,   43,   37,
 /*   180 */    34,   94,   74,   69,  266,  273,  269,  118,  102,   92,
 /*   190 */    98,   55,   57,   59,   61,   63,   65,   45,   47,   67,
 /*   200 */    72,   49,   51,   53,   41,   39,   43,   37,   34,   94,
 /*   210 */    74,   69,  438,    1,    2,    3,    4,    5,    6,  198,
 /*   220 */   112,   79,   92,   98,   55,   57,   59,   61,   63,   65,
 /*   230 */    45,   47,   67,   72,   49,   51,   53,   41,   39,   43,
 /*   240 */    37,   34,   94,   74,   69,  140,  107,  258,   35,   96,
 /*   250 */     6,  141,  143,  274,  124,  126,  248,  160,  131,  257,
 /*   260 */    67,   72,   49,   51,   53,   41,   39,   43,   37,   34,
 /*   270 */    94,   74,   69,  100,  413,   49,   51,   53,   41,   39,
 /*   280 */    43,   37,   34,   94,   74,   69,  268,  269,  146,  147,
 /*   290 */   153,  154,  155,  105,  109,  115,  367,  121,   84,   85,
 /*   300 */    95,   86,  150,  148,  149,  151,  152,   55,   57,   59,
 /*   310 */    61,   63,   65,   45,   47,   67,   72,   49,   51,   53,
 /*   320 */    41,   39,   43,   37,   34,   94,   74,   69,  140,    7,
 /*   330 */   254,   35,  134,  183,  141,  143,  181,   76,  191,  245,
 /*   340 */   189,  131,   41,   39,   43,   37,   34,   94,   74,   69,
 /*   350 */   252,  249,  145,  246,  261,  140,  100,  238,   35,  145,
 /*   360 */   137,  141,  143,  130,  179,  135,  156,  177,  131,  166,
 /*   370 */   130,  146,  147,  153,  154,  155,  105,  109,  115,  280,
 /*   380 */   121,   87,  186,  100,  281,  150,  148,  149,  151,  152,
 /*   390 */   192,  213,  221,  166,  282,    6,    6,  243,  146,  147,
 /*   400 */   153,  154,  155,  105,  109,  115,  138,  121,  134,  134,
 /*   410 */   123,  162,  150,  148,  149,  151,  152,  200,  242,  158,
 /*   420 */    35,   78,  283,  141,  143,  208,  204,  212,  145,  145,
 /*   430 */   201,  175,  284,  132,  173,   76,  211,  219,  227,  130,
 /*   440 */   130,  203,  156,  156,    8,  100,  145,  168,  184,  170,
 /*   450 */   172,  236,  176,  180,  159,   17,  263,  130,  277,  245,
 /*   460 */   146,  147,  153,  154,  155,  105,  109,  115,  232,  121,
 /*   470 */   241,  225,  202,  246,  150,  148,  149,  151,  152,  145,
 /*   480 */     9,   35,  209,  210,  141,  143,  132,   76,  145,   24,
 /*   490 */   130,  131,  103,  229,  233,  243,    6,   26,  138,  130,
 /*   500 */   134,   37,   34,   94,   74,   69,  100,   10,   35,  101,
 /*   510 */    15,  141,  143,   13,   11,   14,  253,   12,  131,  220,
 /*   520 */   145,  146,  147,  153,  154,  155,  105,  109,  115,  145,
 /*   530 */   121,  130,   16,  100,  139,  150,  148,  149,  151,  152,
 /*   540 */   130,   27,   18,   29,   25,   69,   77,   31,  146,  147,
 /*   550 */   153,  154,  155,  105,  109,  115,   75,  121,   81,  232,
 /*   560 */   167,  138,  150,  148,  149,  151,  152,  145,   31,   80,
 /*   570 */    28,  224,   88,   90,  197,  199,  204,  272,  130,  145,
 /*   580 */    89,  188,  412,   97,   38,  231,  104,   76,  145,  108,
 /*   590 */   130,  245,   30,  166,   40,  110,  145,  145,  271,  130,
 /*   600 */    42,   36,  113,   44,  145,  244,  216,  130,  130,  223,
 /*   610 */   114,  145,  119,  125,  145,  130,  157,  133,   46,  116,
 /*   620 */   145,  145,  130,  145,  226,  130,  145,   48,   50,  145,
 /*   630 */   235,  130,  130,   52,  130,  120,   54,  130,  145,  158,
 /*   640 */   130,  159,  136,  164,  145,  169,  313,  145,  145,  130,
 /*   650 */   145,   56,   58,  145,   60,  130,  145,   62,  130,  130,
 /*   660 */   171,  130,  314,  174,  130,  315,  111,  130,  187,   64,
 /*   670 */    66,  145,  145,  316,  145,  188,  117,  145,   68,   91,
 /*   680 */   178,  317,  130,  130,   71,  130,  145,  166,  130,  145,
 /*   690 */   145,  122,   73,   93,  161,  318,  145,  130,  145,  145,
 /*   700 */   130,  130,  182,  319,  145,  320,  321,  130,   99,  130,
 /*   710 */   130,  145,  145,  145,  145,  130,  190,  195,  206,  279,
 /*   720 */   144,  127,  130,  130,  130,  130,  188,  264,  145,  142,
 /*   730 */   129,  194,  228,  230,  188,  214,  218,  237,  166,  130,
 /*   740 */   145,  145,  222,  240,  324,  256,  166,  250,  325,  145,
 /*   750 */   145,  130,  130,  255,  251,  259,  260,  332,  366,  262,
 /*   760 */   130,  130,  265,  267,  270,  275,  276,  338,  278,
};
static PPCODETYPE pp_lookahead[] = {
 /*     0 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    10 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*    20 */    21,   22,   23,    1,    2,    3,    4,    5,    6,    7,
 /*    30 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*    40 */    18,   19,   20,   21,   22,   23,   60,   61,   62,   63,
 /*    50 */    64,   45,   53,   54,    1,    2,    3,    4,    5,    6,
 /*    60 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*    70 */    17,   18,   19,   20,   21,   22,   23,   21,   22,   23,
 /*    80 */    97,   11,   12,   30,  101,   32,  103,  104,   30,  106,
 /*    90 */    32,  102,   22,   71,  105,   73,   50,    1,    2,    3,
 /*   100 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   110 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   120 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*   130 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   140 */    21,   22,   23,    1,    2,    3,    4,    5,    6,    7,
 /*   150 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   160 */    18,   19,   20,   21,   22,   23,   44,   45,   72,    9,
 /*   170 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   180 */    20,   21,   22,   23,  117,  118,  119,   68,   46,    1,
 /*   190 */     2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   200 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   210 */    22,   23,   80,   81,   82,   83,   84,   85,   86,   25,
 /*   220 */    32,   27,    1,    2,    3,    4,    5,    6,    7,    8,
 /*   230 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   240 */    19,   20,   21,   22,   23,   17,   82,  115,   20,   23,
 /*   250 */    86,   23,   24,  121,   70,   71,  111,   73,   30,  114,
 /*   260 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   270 */    21,   22,   23,   45,   46,   13,   14,   15,   16,   17,
 /*   280 */    18,   19,   20,   21,   22,   23,  118,  119,   60,   61,
 /*   290 */    62,   63,   64,   65,   66,   67,    0,   69,  103,  104,
 /*   300 */    74,  106,   74,   75,   76,   77,   78,    3,    4,    5,
 /*   310 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   320 */    16,   17,   18,   19,   20,   21,   22,   23,   17,   87,
 /*   330 */    25,   20,   99,   35,   23,   24,   38,   26,   30,   99,
 /*   340 */    32,   30,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   350 */   110,   46,  119,  113,   58,   17,   45,  107,   20,  119,
 /*   360 */   127,   23,   24,  130,   35,  132,  133,   38,   30,  119,
 /*   370 */   130,   60,   61,   62,   63,   64,   65,   66,   67,    0,
 /*   380 */    69,  107,   25,   45,    0,   74,   75,   76,   77,   78,
 /*   390 */    33,   82,   82,  119,    0,   86,   86,   25,   60,   61,
 /*   400 */    62,   63,   64,   65,   66,   67,   25,   69,   99,   99,
 /*   410 */   128,  129,   74,   75,   76,   77,   78,   17,   46,   31,
 /*   420 */    20,   94,    0,   23,   24,   98,   99,   46,  119,  119,
 /*   430 */    30,   35,    0,   45,   38,   26,  127,  127,   55,  130,
 /*   440 */   130,   17,  133,  133,   88,   45,  119,   34,   35,   36,
 /*   450 */    37,   42,   39,   40,   30,   25,   47,  130,   49,   99,
 /*   460 */    60,   61,   62,   63,   64,   65,   66,   67,   99,   69,
 /*   470 */   110,   56,   31,  113,   74,   75,   76,   77,   78,  119,
 /*   480 */    89,   20,   28,   29,   23,   24,   45,   26,  119,   59,
 /*   490 */   130,   30,   82,  124,  125,   25,   86,   51,   25,  130,
 /*   500 */    99,   19,   20,   21,   22,   23,   45,   90,   20,   99,
 /*   510 */    58,   23,   24,   57,   91,   47,   46,   92,   30,   46,
 /*   520 */   119,   60,   61,   62,   63,   64,   65,   66,   67,  119,
 /*   530 */    69,  130,  126,   45,  133,   74,   75,   76,   77,   78,
 /*   540 */   130,   52,  126,   25,  126,   23,   93,   99,   60,   61,
 /*   550 */    62,   63,   64,   65,   66,   67,   45,   69,   96,   99,
 /*   560 */    30,   25,   74,   75,   76,   77,   78,  119,   99,   95,
 /*   570 */   122,  123,  108,   41,  100,   98,   99,   99,  130,  119,
 /*   580 */   109,  107,   46,   74,   99,  125,   46,   26,  119,   46,
 /*   590 */   130,   99,  123,  119,   99,   45,  119,  119,  120,  130,
 /*   600 */    99,   99,   30,   99,  119,  113,   99,  130,  130,   99,
 /*   610 */    46,  119,   30,  129,  119,  130,   28,  131,   99,   45,
 /*   620 */   119,  119,  130,  119,   99,  130,  119,   99,   99,  119,
 /*   630 */    99,  130,  130,   99,  130,   46,   99,  130,  119,   31,
 /*   640 */   130,   30,   46,   30,  119,   35,   30,  119,  119,  130,
 /*   650 */   119,   99,   99,  119,   99,  130,  119,   99,  130,  130,
 /*   660 */    35,  130,   30,   35,  130,   30,   99,  130,  100,   99,
 /*   670 */    99,  119,  119,   30,  119,  107,   99,  119,   99,   99,
 /*   680 */    35,   30,  130,  130,   99,  130,  119,  119,  130,  119,
 /*   690 */   119,   99,   99,   99,   99,   30,  119,  130,  119,  119,
 /*   700 */   130,  130,   35,   30,  119,   30,   30,  130,   99,  130,
 /*   710 */   130,  119,  119,  119,  119,  130,   30,   30,   30,  100,
 /*   720 */    99,   99,  130,  130,  130,  130,  107,  100,  119,   99,
 /*   730 */    99,  105,   52,   25,  107,   46,   45,   43,  119,  130,
 /*   740 */   119,  119,   46,   45,    0,   30,  119,   44,    0,  119,
 /*   750 */   119,  130,  130,  114,   45,   87,  116,    0,    0,  126,
 /*   760 */   130,  130,   48,   25,    3,   87,  116,    0,   27,
};
#define PP_SHIFT_USE_DFLT (-15)
static short pp_shift_ofst[] = {
 /*     0 */   409,  379,  384,  394,  422,  432,   46,  383,  415,  446,
 /*    10 */   452,  456,  -15,  468,  -15,  -14,  430,  -14,  -15,  -15,
 /*    20 */   -15,  -15,  -15,  -15,  -14,  -15,  489,  488,  518,  488,
 /*    30 */   -15,   -1,  -15,  -15,  488,  488,   56,  488,   56,  488,
 /*    40 */   482,  488,  482,  488,  482,  488,  249,  488,  249,  488,
 /*    50 */   326,  488,  326,  488,  326,  488,  160,  488,  160,  488,
 /*    60 */   160,  488,  160,  488,  160,  488,  160,  488,  262,   70,
 /*    70 */   488,  522,  488,  262,  511,  311,  454,  400,  194,  530,
 /*    80 */   357,  413,  -15,  413,  -15,  -15,  530,   58,  532,  -15,
 /*    90 */   488,  221,  488,  221,  226,  -15,  509,  -15,  488,  304,
 /*   100 */   461,  142,  -15,  540,  -15,    6,  561,  543,  -15,  550,
 /*   110 */   488,  188,  572,  564,  -15,  574,  488,  119,  582,  589,
 /*   120 */   -15,  488,   22,  184,  -15,  -15,  488,   96,  488,  221,
 /*   130 */   -15,  388,  588,  228,  221,  596,  -15,  536,  338,  -15,
 /*   140 */   -15,  488,  522,  488,  522,  -15,  -15,  -15,  -15,  -15,
 /*   150 */   -15,  -15,  -15,  -15,  -15,  -15,  -15,  -15,  611,  -15,
 /*   160 */   488,  221,  -15,  613,  -15,  -15,  -15,  608,  610,  616,
 /*   170 */   625,  632,  396,  628,  635,  643,  329,  645,  651,  665,
 /*   180 */   298,  667,  673,  675,  676,  -15,  530,  -15,  308,  686,
 /*   190 */   -15,  -15,  687,  687,  -15,  -15,  -15,  -15,  400,  -15,
 /*   200 */   -15,  441,  424,  -15,   53,  688,  -15,  -15,  -15,  -15,
 /*   210 */   -15,  381,  -15,  689,  -15,  488,  522,  691,  311,  473,
 /*   220 */   -15,  696,  -15,   56,  -15,  488,  221,  680,  488,  708,
 /*   230 */   488,  -15,  221,  -15,  488,  221,  694,  530,  122,  698,
 /*   240 */   488,  372,  744,  488,  -15,  221,  -15,  715,  305,  703,
 /*   250 */   709,  488,  470,  748,  715,  -15,  -15,  -15,   46,  296,
 /*   260 */   757,  -14,  758,  530,  714,  530,  738,  530,  -15,  761,
 /*   270 */   488,  -15,  221,  -15,   46,  296,  767,  741,  530,  -15,
};
#define PP_REDUCE_USE_DFLT (-18)
static short pp_reduce_ofst[] = {
 /*     0 */   132,  -18,  -18,  -18,  -18,  -18,  242,  356,  391,  417,
 /*    10 */   423,  425,  -18,  -18,  -18,  406,  -18,  416,  -18,  -18,
 /*    20 */   -18,  -18,  -18,  -18,  418,  -18,  -18,  448,  -18,  469,
 /*    30 */   -18,  -18,  -18,  -18,  510,  502,  -18,  485,  -18,  495,
 /*    40 */   -18,  501,  -18,  504,  -18,  519,  -18,  528,  -18,  529,
 /*    50 */   -18,  534,  -18,  537,  -18,  552,  -18,  553,  -18,  555,
 /*    60 */   -18,  558,  -18,  570,  -18,  571,  -18,  579,  -18,  -18,
 /*    70 */   585,  -18,  593,  -18,  -18,  309,  453,  327,  -18,  474,
 /*    80 */   462,  -17,  -18,  195,  -18,  -18,  274,  464,  471,  -18,
 /*    90 */   580,  -18,  594,  -18,  -18,  -18,  -18,  -18,  609,  -18,
 /*   100 */   410,  -18,  -18,  -18,  -18,  -18,  164,  -18,  -18,  -18,
 /*   110 */   567,  -18,  -18,  -18,  -18,  -18,  577,  -18,  -18,  -18,
 /*   120 */   -18,  592,  282,  484,  -18,  -18,  622,  -18,  631,  -18,
 /*   130 */   -18,  -18,  486,  233,  -18,  -18,  -18,  -18,  401,  -18,
 /*   140 */   -18,  630,  -18,  621,  -18,  -18,  -18,  -18,  -18,  -18,
 /*   150 */   -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,
 /*   160 */   595,  -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,
 /*   170 */   -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,
 /*   180 */   -18,  -18,  -18,  -18,  -18,  -18,  568,  -18,  -18,  -18,
 /*   190 */   -18,  -18,  -11,  626,  -18,  -18,  -18,  -18,  477,  -18,
 /*   200 */   -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,
 /*   210 */   -18,  -18,  -18,  -18,  -18,  507,  -18,  -18,  310,  -18,
 /*   220 */   -18,  -18,  -18,  -18,  -18,  525,  -18,  -18,  369,  -18,
 /*   230 */   460,  -18,  -18,  -18,  531,  -18,  -18,  250,  -18,  -18,
 /*   240 */   360,  -18,  -18,  492,  -18,  -18,  -18,  145,  -18,  -18,
 /*   250 */   -18,  240,  -18,  -18,  639,  -18,  -18,  -18,  668,  640,
 /*   260 */   -18,  633,  -18,  627,  -18,   67,  -18,  168,  -18,  -18,
 /*   270 */   478,  -18,  -18,  -18,  678,  650,  -18,  -18,  619,  -18,
};
static PPACTIONTYPE pp_default[] = {
 /*     0 */   437,  437,  437,  437,  437,  437,  345,  354,  359,  347,
 /*    10 */   365,  361,  285,  437,  360,  437,  362,  437,  363,  368,
 /*    20 */   369,  370,  371,  372,  437,  364,  437,  437,  346,  437,
 /*    30 */   348,  350,  351,  352,  437,  437,  373,  437,  375,  437,
 /*    40 */   376,  437,  377,  437,  378,  437,  379,  437,  380,  437,
 /*    50 */   381,  437,  382,  437,  383,  437,  384,  437,  385,  437,
 /*    60 */   386,  437,  387,  437,  388,  437,  389,  437,  390,  437,
 /*    70 */   437,  391,  437,  392,  437,  437,  289,  437,  437,  437,
 /*    80 */   302,  300,  286,  299,  303,  305,  437,  312,  323,  309,
 /*    90 */   437,  322,  437,  400,  437,  418,  437,  419,  437,  420,
 /*   100 */   437,  437,  423,  437,  396,  437,  437,  437,  399,  437,
 /*   110 */   437,  437,  437,  437,  401,  437,  437,  437,  437,  437,
 /*   120 */   402,  437,  437,  437,  403,  404,  437,  437,  437,  406,
 /*   130 */   408,  436,  411,  437,  417,  437,  409,  437,  437,  414,
 /*   140 */   416,  437,  421,  437,  422,  424,  425,  426,  427,  428,
 /*   150 */   429,  430,  431,  432,  433,  434,  415,  410,  437,  435,
 /*   160 */   437,  407,  405,  437,  310,  311,  343,  436,  437,  437,
 /*   170 */   437,  437,  437,  437,  437,  437,  437,  437,  437,  437,
 /*   180 */   437,  437,  437,  437,  437,  304,  437,  297,  342,  437,
 /*   190 */   340,  341,  437,  301,  306,  308,  307,  298,  437,  290,
 /*   200 */   292,  436,  437,  293,  296,  437,  294,  295,  291,  287,
 /*   210 */   288,  437,  394,  437,  397,  437,  393,  437,  437,  437,
 /*   220 */   395,  437,  398,  374,  349,  437,  358,  437,  437,  353,
 /*   230 */   437,  355,  357,  356,  437,  344,  437,  437,  437,  437,
 /*   240 */   437,  437,  437,  437,  326,  328,  327,  437,  437,  437,
 /*   250 */   437,  437,  437,  437,  437,  329,  331,  330,  345,  437,
 /*   260 */   437,  437,  437,  437,  437,  437,  333,  437,  334,  437,
 /*   270 */   437,  336,  337,  335,  345,  437,  437,  437,  437,  339,
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
  "BPLACEHOLDER",  "EXISTS",        "CAST",          "CONVERT",     
  "USING",         "CASE",          "END",           "WHEN",        
  "THEN",          "ELSE",          "NULL",          "STRING",      
  "DOUBLE",        "TRUE",          "FALSE",         "error",       
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
 /*  92 */ "integer_or_placeholder ::= BPLACEHOLDER",
 /*  93 */ "expr ::= MINUS expr",
 /*  94 */ "expr ::= expr MINUS expr",
 /*  95 */ "expr ::= expr PLUS expr",
 /*  96 */ "expr ::= expr TIMES expr",
 /*  97 */ "expr ::= expr DIVIDE expr",
 /*  98 */ "expr ::= expr MOD expr",
 /*  99 */ "expr ::= expr AND expr",
 /* 100 */ "expr ::= expr OR expr",
 /* 101 */ "expr ::= expr BITWISE_AND expr",
 /* 102 */ "expr ::= expr BITWISE_OR expr",
 /* 103 */ "expr ::= expr BITWISE_XOR expr",
 /* 104 */ "expr ::= expr EQUALS expr",
 /* 105 */ "expr ::= expr NOTEQUALS expr",
 /* 106 */ "expr ::= expr LESS expr",
 /* 107 */ "expr ::= expr GREATER expr",
 /* 108 */ "expr ::= expr GREATEREQUAL expr",
 /* 109 */ "expr ::= expr LESSEQUAL expr",
 /* 110 */ "expr ::= expr LIKE expr",
 /* 111 */ "expr ::= expr NOT LIKE expr",
 /* 112 */ "expr ::= expr ILIKE expr",
 /* 113 */ "expr ::= expr NOT ILIKE expr",
 /* 114 */ "expr ::= expr IN PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 115 */ "expr ::= expr NOT IN PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 116 */ "expr ::= PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 117 */ "expr ::= expr IN PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 118 */ "expr ::= expr NOT IN PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 119 */ "expr ::= EXISTS PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 120 */ "expr ::= expr AGAINST expr",
 /* 121 */ "expr ::= CAST PARENTHESES_OPEN expr AS IDENTIFIER PARENTHESES_CLOSE",
 /* 122 */ "expr ::= CONVERT PARENTHESES_OPEN expr USING IDENTIFIER PARENTHESES_CLOSE",
 /* 123 */ "expr ::= CASE expr when_clauses END",
 /* 124 */ "when_clauses ::= when_clauses when_clause",
 /* 125 */ "when_clauses ::= when_clause",
 /* 126 */ "when_clause ::= WHEN expr THEN expr",
 /* 127 */ "when_clause ::= ELSE expr",
 /* 128 */ "expr ::= function_call",
 /* 129 */ "function_call ::= IDENTIFIER PARENTHESES_OPEN distinct_or_null argument_list_or_null PARENTHESES_CLOSE",
 /* 130 */ "distinct_or_null ::= DISTINCT",
 /* 131 */ "distinct_or_null ::=",
 /* 132 */ "argument_list_or_null ::= argument_list",
 /* 133 */ "argument_list_or_null ::=",
 /* 134 */ "argument_list ::= argument_list COMMA argument_item",
 /* 135 */ "argument_list ::= argument_item",
 /* 136 */ "argument_item ::= TIMES",
 /* 137 */ "argument_item ::= expr",
 /* 138 */ "expr ::= expr IS NULL",
 /* 139 */ "expr ::= expr IS NOT NULL",
 /* 140 */ "expr ::= expr BETWEEN expr",
 /* 141 */ "expr ::= NOT expr",
 /* 142 */ "expr ::= BITWISE_NOT expr",
 /* 143 */ "expr ::= PARENTHESES_OPEN expr PARENTHESES_CLOSE",
 /* 144 */ "expr ::= qualified_name",
 /* 145 */ "expr ::= INTEGER",
 /* 146 */ "expr ::= HINTEGER",
 /* 147 */ "expr ::= STRING",
 /* 148 */ "expr ::= DOUBLE",
 /* 149 */ "expr ::= NULL",
 /* 150 */ "expr ::= TRUE",
 /* 151 */ "expr ::= FALSE",
 /* 152 */ "expr ::= NPLACEHOLDER",
 /* 153 */ "expr ::= SPLACEHOLDER",
 /* 154 */ "expr ::= BPLACEHOLDER",
 /* 155 */ "qualified_name ::= IDENTIFIER DOT IDENTIFIER",
 /* 156 */ "qualified_name ::= IDENTIFIER",
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
// 1253 "parser.c"
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
// 1290 "parser.c"
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
// 1306 "parser.c"
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
// 1680 "parser.c"
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
      case 128:
      case 132:
      case 137:
      case 144:
// 572 "parser.lemon"
{
	ppgotominor.pp244 = ppmsp[0].minor.pp244;
}
// 1706 "parser.c"
        break;
      case 5:
// 590 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_select_statement(ppmsp[-6].minor.pp244, ppmsp[-5].minor.pp244, ppmsp[-2].minor.pp244, ppmsp[-4].minor.pp244, ppmsp[-3].minor.pp244, ppmsp[-1].minor.pp244, ppmsp[0].minor.pp244);
}
// 1713 "parser.c"
        break;
      case 6:
// 596 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_select_clause(ppmsp[-5].minor.pp244, ppmsp[-4].minor.pp244, ppmsp[-2].minor.pp244, ppmsp[-1].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(26,&ppmsp[-6].minor);
  pp_destructor(27,&ppmsp[-3].minor);
}
// 1722 "parser.c"
        break;
      case 7:
// 602 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_distinct_all(1);
  pp_destructor(28,&ppmsp[0].minor);
}
// 1730 "parser.c"
        break;
      case 8:
// 606 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_distinct_all(0);
  pp_destructor(29,&ppmsp[0].minor);
}
// 1738 "parser.c"
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
      case 131:
      case 133:
// 610 "parser.lemon"
{
	ppgotominor.pp244 = NULL;
}
// 1758 "parser.c"
        break;
      case 10:
      case 17:
      case 46:
      case 49:
      case 54:
      case 68:
      case 75:
      case 134:
// 616 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_zval_list(ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(25,&ppmsp[-1].minor);
}
// 1773 "parser.c"
        break;
      case 11:
      case 47:
      case 50:
      case 125:
      case 135:
// 620 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_zval_list(ppmsp[0].minor.pp244, NULL);
}
// 1784 "parser.c"
        break;
      case 12:
      case 136:
// 626 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_column_item(PHQL_T_STARALL, NULL, NULL, NULL);
  pp_destructor(17,&ppmsp[0].minor);
}
// 1793 "parser.c"
        break;
      case 13:
// 630 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_column_item(PHQL_T_DOMAINALL, NULL, ppmsp[-2].minor.pp0, NULL);
  pp_destructor(31,&ppmsp[-1].minor);
  pp_destructor(17,&ppmsp[0].minor);
}
// 1802 "parser.c"
        break;
      case 14:
// 634 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_column_item(PHQL_T_EXPR, ppmsp[-2].minor.pp244, NULL, ppmsp[0].minor.pp0);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 1810 "parser.c"
        break;
      case 15:
// 638 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_column_item(PHQL_T_EXPR, ppmsp[-1].minor.pp244, NULL, ppmsp[0].minor.pp0);
}
// 1817 "parser.c"
        break;
      case 16:
// 642 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_column_item(PHQL_T_EXPR, ppmsp[0].minor.pp244, NULL, NULL);
}
// 1824 "parser.c"
        break;
      case 21:
// 664 "parser.lemon"
{
	ppgotominor.pp244 = ppmsp[0].minor.pp244;
  pp_destructor(33,&ppmsp[-1].minor);
}
// 1832 "parser.c"
        break;
      case 23:
      case 26:
      case 124:
// 674 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_zval_list(ppmsp[-1].minor.pp244, ppmsp[0].minor.pp244);
}
// 1841 "parser.c"
        break;
      case 28:
      case 31:
      case 51:
      case 156:
// 700 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_qualified_name(NULL, NULL, ppmsp[0].minor.pp0);
}
// 1851 "parser.c"
        break;
      case 29:
// 707 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_join_item(ppmsp[-3].minor.pp244, ppmsp[-2].minor.pp244, ppmsp[-1].minor.pp244, ppmsp[0].minor.pp244);
}
// 1858 "parser.c"
        break;
      case 30:
// 713 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_qualified_name(NULL, NULL, ppmsp[0].minor.pp0);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 1866 "parser.c"
        break;
      case 33:
// 727 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_join_type(PHQL_T_INNERJOIN);
  pp_destructor(34,&ppmsp[-1].minor);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1875 "parser.c"
        break;
      case 34:
// 731 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_join_type(PHQL_T_CROSSJOIN);
  pp_destructor(36,&ppmsp[-1].minor);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1884 "parser.c"
        break;
      case 35:
// 735 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  pp_destructor(37,&ppmsp[-2].minor);
  pp_destructor(38,&ppmsp[-1].minor);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1894 "parser.c"
        break;
      case 36:
// 739 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  pp_destructor(37,&ppmsp[-1].minor);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1903 "parser.c"
        break;
      case 37:
// 743 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  pp_destructor(39,&ppmsp[-2].minor);
  pp_destructor(38,&ppmsp[-1].minor);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1913 "parser.c"
        break;
      case 38:
// 747 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  pp_destructor(39,&ppmsp[-1].minor);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1922 "parser.c"
        break;
      case 39:
// 751 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_join_type(PHQL_T_FULLJOIN);
  pp_destructor(40,&ppmsp[-2].minor);
  pp_destructor(38,&ppmsp[-1].minor);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1932 "parser.c"
        break;
      case 40:
// 755 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_join_type(PHQL_T_FULLJOIN);
  pp_destructor(40,&ppmsp[-1].minor);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1941 "parser.c"
        break;
      case 41:
// 759 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_join_type(PHQL_T_INNERJOIN);
  pp_destructor(35,&ppmsp[0].minor);
}
// 1949 "parser.c"
        break;
      case 42:
// 765 "parser.lemon"
{
	ppgotominor.pp244 = ppmsp[0].minor.pp244;
  pp_destructor(41,&ppmsp[-1].minor);
}
// 1957 "parser.c"
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
// 1969 "parser.c"
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
// 1983 "parser.c"
        break;
      case 52:
// 818 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_update_statement(ppmsp[-2].minor.pp244, ppmsp[-1].minor.pp244, ppmsp[0].minor.pp244);
}
// 1990 "parser.c"
        break;
      case 53:
// 824 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_update_clause(ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(47,&ppmsp[-3].minor);
  pp_destructor(48,&ppmsp[-1].minor);
}
// 1999 "parser.c"
        break;
      case 56:
// 840 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_update_item(ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(3,&ppmsp[-1].minor);
}
// 2007 "parser.c"
        break;
      case 58:
// 852 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_delete_statement(ppmsp[-2].minor.pp244, ppmsp[-1].minor.pp244, ppmsp[0].minor.pp244);
}
// 2014 "parser.c"
        break;
      case 59:
// 858 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_delete_clause(ppmsp[0].minor.pp244);
  pp_destructor(49,&ppmsp[-2].minor);
  pp_destructor(27,&ppmsp[-1].minor);
}
// 2023 "parser.c"
        break;
      case 60:
// 864 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_assoc_name(ppmsp[-2].minor.pp244, ppmsp[0].minor.pp0);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 2031 "parser.c"
        break;
      case 61:
// 868 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_assoc_name(ppmsp[-1].minor.pp244, ppmsp[0].minor.pp0);
}
// 2038 "parser.c"
        break;
      case 62:
// 872 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_assoc_name(ppmsp[0].minor.pp244, NULL);
}
// 2045 "parser.c"
        break;
      case 64:
// 884 "parser.lemon"
{
	ppgotominor.pp244 = ppmsp[0].minor.pp244;
  pp_destructor(50,&ppmsp[-1].minor);
}
// 2053 "parser.c"
        break;
      case 66:
// 894 "parser.lemon"
{
	ppgotominor.pp244 = ppmsp[0].minor.pp244;
  pp_destructor(51,&ppmsp[-2].minor);
  pp_destructor(52,&ppmsp[-1].minor);
}
// 2062 "parser.c"
        break;
      case 70:
// 914 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_order_item(ppmsp[0].minor.pp244, 0);
}
// 2069 "parser.c"
        break;
      case 71:
// 918 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_order_item(ppmsp[-1].minor.pp244, PHQL_T_ASC);
  pp_destructor(53,&ppmsp[0].minor);
}
// 2077 "parser.c"
        break;
      case 72:
// 922 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_order_item(ppmsp[-1].minor.pp244, PHQL_T_DESC);
  pp_destructor(54,&ppmsp[0].minor);
}
// 2085 "parser.c"
        break;
      case 73:
// 928 "parser.lemon"
{
	ppgotominor.pp244 = ppmsp[0].minor.pp244;
  pp_destructor(55,&ppmsp[-2].minor);
  pp_destructor(52,&ppmsp[-1].minor);
}
// 2094 "parser.c"
        break;
      case 78:
// 954 "parser.lemon"
{
	ppgotominor.pp244 = ppmsp[0].minor.pp244;
  pp_destructor(56,&ppmsp[-1].minor);
}
// 2102 "parser.c"
        break;
      case 80:
// 964 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_for_update_clause();
  pp_destructor(57,&ppmsp[-1].minor);
  pp_destructor(47,&ppmsp[0].minor);
}
// 2111 "parser.c"
        break;
      case 82:
      case 86:
// 974 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_limit_clause(ppmsp[0].minor.pp244, NULL);
  pp_destructor(58,&ppmsp[-1].minor);
}
// 2120 "parser.c"
        break;
      case 83:
// 978 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_limit_clause(ppmsp[0].minor.pp244, ppmsp[-2].minor.pp244);
  pp_destructor(58,&ppmsp[-3].minor);
  pp_destructor(25,&ppmsp[-1].minor);
}
// 2129 "parser.c"
        break;
      case 84:
// 982 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_limit_clause(ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(58,&ppmsp[-3].minor);
  pp_destructor(59,&ppmsp[-1].minor);
}
// 2138 "parser.c"
        break;
      case 88:
      case 145:
// 1000 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_literal_zval(PHQL_T_INTEGER, ppmsp[0].minor.pp0);
}
// 2146 "parser.c"
        break;
      case 89:
      case 146:
// 1004 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_literal_zval(PHQL_T_HINTEGER, ppmsp[0].minor.pp0);
}
// 2154 "parser.c"
        break;
      case 90:
      case 152:
// 1008 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_placeholder_zval(PHQL_T_NPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 2162 "parser.c"
        break;
      case 91:
      case 153:
// 1012 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_placeholder_zval(PHQL_T_SPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 2170 "parser.c"
        break;
      case 92:
      case 154:
// 1016 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_placeholder_zval(PHQL_T_BPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 2178 "parser.c"
        break;
      case 93:
// 1022 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_MINUS, NULL, ppmsp[0].minor.pp244);
  pp_destructor(20,&ppmsp[-1].minor);
}
// 2186 "parser.c"
        break;
      case 94:
// 1026 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_SUB, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(20,&ppmsp[-1].minor);
}
// 2194 "parser.c"
        break;
      case 95:
// 1030 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_ADD, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(19,&ppmsp[-1].minor);
}
// 2202 "parser.c"
        break;
      case 96:
// 1034 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_MUL, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(17,&ppmsp[-1].minor);
}
// 2210 "parser.c"
        break;
      case 97:
// 1038 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_DIV, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(16,&ppmsp[-1].minor);
}
// 2218 "parser.c"
        break;
      case 98:
// 1042 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_MOD, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(18,&ppmsp[-1].minor);
}
// 2226 "parser.c"
        break;
      case 99:
// 1046 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_AND, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(9,&ppmsp[-1].minor);
}
// 2234 "parser.c"
        break;
      case 100:
// 1050 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_OR, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(10,&ppmsp[-1].minor);
}
// 2242 "parser.c"
        break;
      case 101:
// 1054 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_BITWISE_AND, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(13,&ppmsp[-1].minor);
}
// 2250 "parser.c"
        break;
      case 102:
// 1058 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_BITWISE_OR, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(14,&ppmsp[-1].minor);
}
// 2258 "parser.c"
        break;
      case 103:
// 1062 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_BITWISE_XOR, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(15,&ppmsp[-1].minor);
}
// 2266 "parser.c"
        break;
      case 104:
// 1066 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_EQUALS, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(3,&ppmsp[-1].minor);
}
// 2274 "parser.c"
        break;
      case 105:
// 1070 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_NOTEQUALS, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(4,&ppmsp[-1].minor);
}
// 2282 "parser.c"
        break;
      case 106:
// 1074 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_LESS, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(5,&ppmsp[-1].minor);
}
// 2290 "parser.c"
        break;
      case 107:
// 1078 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_GREATER, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(6,&ppmsp[-1].minor);
}
// 2298 "parser.c"
        break;
      case 108:
// 1082 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_GREATEREQUAL, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(7,&ppmsp[-1].minor);
}
// 2306 "parser.c"
        break;
      case 109:
// 1086 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_LESSEQUAL, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(8,&ppmsp[-1].minor);
}
// 2314 "parser.c"
        break;
      case 110:
// 1090 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_LIKE, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(11,&ppmsp[-1].minor);
}
// 2322 "parser.c"
        break;
      case 111:
// 1094 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_NLIKE, ppmsp[-3].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(23,&ppmsp[-2].minor);
  pp_destructor(11,&ppmsp[-1].minor);
}
// 2331 "parser.c"
        break;
      case 112:
// 1098 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_ILIKE, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(12,&ppmsp[-1].minor);
}
// 2339 "parser.c"
        break;
      case 113:
// 1102 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_NILIKE, ppmsp[-3].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(23,&ppmsp[-2].minor);
  pp_destructor(12,&ppmsp[-1].minor);
}
// 2348 "parser.c"
        break;
      case 114:
      case 117:
// 1106 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_IN, ppmsp[-4].minor.pp244, ppmsp[-1].minor.pp244);
  pp_destructor(22,&ppmsp[-3].minor);
  pp_destructor(45,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 2359 "parser.c"
        break;
      case 115:
      case 118:
// 1110 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_NOTIN, ppmsp[-5].minor.pp244, ppmsp[-1].minor.pp244);
  pp_destructor(23,&ppmsp[-4].minor);
  pp_destructor(22,&ppmsp[-3].minor);
  pp_destructor(45,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 2371 "parser.c"
        break;
      case 116:
// 1114 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_SUBQUERY, ppmsp[-1].minor.pp244, NULL);
  pp_destructor(45,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 2380 "parser.c"
        break;
      case 119:
// 1126 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_EXISTS, NULL, ppmsp[-1].minor.pp244);
  pp_destructor(65,&ppmsp[-3].minor);
  pp_destructor(45,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 2390 "parser.c"
        break;
      case 120:
// 1130 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_AGAINST, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(1,&ppmsp[-1].minor);
}
// 2398 "parser.c"
        break;
      case 121:
// 1134 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_CAST, ppmsp[-3].minor.pp244, phql_ret_raw_qualified_name(ppmsp[-1].minor.pp0, NULL));
  pp_destructor(66,&ppmsp[-5].minor);
  pp_destructor(45,&ppmsp[-4].minor);
  pp_destructor(32,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 2409 "parser.c"
        break;
      case 122:
// 1138 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_CONVERT, ppmsp[-3].minor.pp244, phql_ret_raw_qualified_name(ppmsp[-1].minor.pp0, NULL));
  pp_destructor(67,&ppmsp[-5].minor);
  pp_destructor(45,&ppmsp[-4].minor);
  pp_destructor(68,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 2420 "parser.c"
        break;
      case 123:
// 1142 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_CASE, ppmsp[-2].minor.pp244, ppmsp[-1].minor.pp244);
  pp_destructor(69,&ppmsp[-3].minor);
  pp_destructor(70,&ppmsp[0].minor);
}
// 2429 "parser.c"
        break;
      case 126:
// 1154 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_WHEN, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(71,&ppmsp[-3].minor);
  pp_destructor(72,&ppmsp[-1].minor);
}
// 2438 "parser.c"
        break;
      case 127:
// 1158 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_ELSE, ppmsp[0].minor.pp244, NULL);
  pp_destructor(73,&ppmsp[-1].minor);
}
// 2446 "parser.c"
        break;
      case 129:
// 1168 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_func_call(ppmsp[-4].minor.pp0, ppmsp[-1].minor.pp244, ppmsp[-2].minor.pp244);
  pp_destructor(45,&ppmsp[-3].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 2455 "parser.c"
        break;
      case 130:
// 1174 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_distinct();
  pp_destructor(28,&ppmsp[0].minor);
}
// 2463 "parser.c"
        break;
      case 138:
// 1212 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_ISNULL, ppmsp[-2].minor.pp244, NULL);
  pp_destructor(21,&ppmsp[-1].minor);
  pp_destructor(74,&ppmsp[0].minor);
}
// 2472 "parser.c"
        break;
      case 139:
// 1216 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_ISNOTNULL, ppmsp[-3].minor.pp244, NULL);
  pp_destructor(21,&ppmsp[-2].minor);
  pp_destructor(23,&ppmsp[-1].minor);
  pp_destructor(74,&ppmsp[0].minor);
}
// 2482 "parser.c"
        break;
      case 140:
// 1220 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_BETWEEN, ppmsp[-2].minor.pp244, ppmsp[0].minor.pp244);
  pp_destructor(2,&ppmsp[-1].minor);
}
// 2490 "parser.c"
        break;
      case 141:
// 1224 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_NOT, NULL, ppmsp[0].minor.pp244);
  pp_destructor(23,&ppmsp[-1].minor);
}
// 2498 "parser.c"
        break;
      case 142:
// 1228 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_BITWISE_NOT, NULL, ppmsp[0].minor.pp244);
  pp_destructor(24,&ppmsp[-1].minor);
}
// 2506 "parser.c"
        break;
      case 143:
// 1232 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_expr(PHQL_T_ENCLOSED, ppmsp[-1].minor.pp244, NULL);
  pp_destructor(45,&ppmsp[-2].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 2515 "parser.c"
        break;
      case 147:
// 1248 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_literal_zval(PHQL_T_STRING, ppmsp[0].minor.pp0);
}
// 2522 "parser.c"
        break;
      case 148:
// 1252 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_literal_zval(PHQL_T_DOUBLE, ppmsp[0].minor.pp0);
}
// 2529 "parser.c"
        break;
      case 149:
// 1256 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_literal_zval(PHQL_T_NULL, NULL);
  pp_destructor(74,&ppmsp[0].minor);
}
// 2537 "parser.c"
        break;
      case 150:
// 1260 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_literal_zval(PHQL_T_TRUE, NULL);
  pp_destructor(77,&ppmsp[0].minor);
}
// 2545 "parser.c"
        break;
      case 151:
// 1264 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_literal_zval(PHQL_T_FALSE, NULL);
  pp_destructor(78,&ppmsp[0].minor);
}
// 2553 "parser.c"
        break;
      case 155:
// 1285 "parser.lemon"
{
	ppgotominor.pp244 = phql_ret_qualified_name(NULL, ppmsp[-2].minor.pp0, ppmsp[0].minor.pp0);
  pp_destructor(31,&ppmsp[-1].minor);
}
// 2561 "parser.c"
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

// 2670 "parser.c"
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
