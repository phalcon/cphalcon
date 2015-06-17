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


// 456 "parser.c"
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
#define PPNOCODE 130
#define PPACTIONTYPE unsigned short int
#define phql_TOKENTYPE phql_parser_token*
typedef union {
  phql_TOKENTYPE pp0;
  zval* pp42;
  int pp259;
} PPMINORTYPE;
#define PPSTACKDEPTH 100
#define phql_ARG_SDECL phql_parser_status *status;
#define phql_ARG_PDECL ,phql_parser_status *status
#define phql_ARG_FETCH phql_parser_status *status = pppParser->status
#define phql_ARG_STORE pppParser->status = status
#define PPNSTATE 271
#define PPNRULE 149
#define PPERRORSYMBOL 77
#define PPERRSYMDT pp259
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
 /*     0 */    99,  105,   53,   55,   57,   59,   61,   63,   43,   45,
 /*    10 */    65,   70,   47,   49,   51,   39,   37,   41,   35,   32,
 /*    20 */   101,   72,   67,   99,  105,   53,   55,   57,   59,   61,
 /*    30 */    63,   43,   45,   65,   70,   47,   49,   51,   39,   37,
 /*    40 */    41,   35,   32,  101,   72,   67,   35,   32,  101,   72,
 /*    50 */    67,   74,  198,  194,  196,   47,   49,   51,   39,   37,
 /*    60 */    41,   35,   32,  101,   72,   67,   89,  133,  189,  164,
 /*    70 */    77,   99,  105,   53,   55,   57,   59,   61,   63,   43,
 /*    80 */    45,   65,   70,   47,   49,   51,   39,   37,   41,   35,
 /*    90 */    32,  101,   72,   67,   99,  105,   53,   55,   57,   59,
 /*   100 */    61,   63,   43,   45,   65,   70,   47,   49,   51,   39,
 /*   110 */    37,   41,   35,   32,  101,   72,   67,  131,  133,   85,
 /*   120 */   164,   83,   30,   31,   99,  105,   53,   55,   57,   59,
 /*   130 */    61,   63,   43,   45,   65,   70,   47,   49,   51,   39,
 /*   140 */    37,   41,   35,   32,  101,   72,   67,   39,   37,   41,
 /*   150 */    35,   32,  101,   72,   67,   68,  206,   94,  125,  170,
 /*   160 */   186,  172,  174,  114,  178,  182,  208,    6,  109,   86,
 /*   170 */    99,  105,   53,   55,   57,   59,   61,   63,   43,   45,
 /*   180 */    65,   70,   47,   49,   51,   39,   37,   41,   35,   32,
 /*   190 */   101,   72,   67,   99,  105,   53,   55,   57,   59,   61,
 /*   200 */    63,   43,   45,   65,   70,   47,   49,   51,   39,   37,
 /*   210 */    41,   35,   32,  101,   72,   67,  257,  264,  260,   19,
 /*   220 */    20,   21,  200,  201,  119,   65,   70,   47,   49,   51,
 /*   230 */    39,   37,   41,   35,   32,  101,   72,   67,  135,   15,
 /*   240 */    99,  105,   53,   55,   57,   59,   61,   63,   43,   45,
 /*   250 */    65,   70,   47,   49,   51,   39,   37,   41,   35,   32,
 /*   260 */   101,   72,   67,   53,   55,   57,   59,   61,   63,   43,
 /*   270 */    45,   65,   70,   47,   49,   51,   39,   37,   41,   35,
 /*   280 */    32,  101,   72,   67,  147,  177,  145,   33,  175,  229,
 /*   290 */   148,  150,  141,   74,   80,  104,  223,  138,  101,   72,
 /*   300 */    67,   86,  170,  186,  172,  174,  396,  178,  182,  147,
 /*   310 */   152,  107,   33,  115,  152,  148,  150,  353,  144,  220,
 /*   320 */   224,  137,  138,  142,  162,  137,  153,  159,  160,  112,
 /*   330 */   116,  122,  181,  128,  193,  179,  107,  397,  156,  154,
 /*   340 */   155,  157,  158,  161,  212,  204,  110,  139,    6,    6,
 /*   350 */     6,  153,  159,  160,  112,  116,  122,  169,  128,  167,
 /*   360 */   141,  141,  108,  156,  154,  155,  157,  158,  161,  191,
 /*   370 */   185,  103,   33,  183,  252,  148,  150,   29,  152,  152,
 /*   380 */   152,  209,  192,   91,   92,   93,  210,  202,  145,  137,
 /*   390 */   137,  137,  162,  162,   23,  152,  107,   33,   26,  215,
 /*   400 */   148,  150,  141,   74,   58,  310,  137,  138,  203,   17,
 /*   410 */   145,  153,  159,  160,  112,  116,  122,   67,  128,  102,
 /*   420 */   152,  107,  152,  156,  154,  155,  157,  158,  161,  239,
 /*   430 */   211,  137,  248,  137,  146,  271,  153,  159,  160,  112,
 /*   440 */   116,  122,   22,  128,  205,  223,  236,  236,  156,  154,
 /*   450 */   155,  157,  158,  161,  147,  232,  243,   33,  237,  237,
 /*   460 */   148,  150,   96,  152,  152,  152,   29,  138,    7,  222,
 /*   470 */   230,  238,   97,   79,  137,  137,  137,   90,  187,   92,
 /*   480 */    93,  107,   33,  117,  152,  148,  150,  165,   28,   69,
 /*   490 */   130,  166,  138,  259,  260,  137,  153,  159,  160,  112,
 /*   500 */   116,  122,   88,  128,   95,  152,  107,  152,  156,  154,
 /*   510 */   155,  157,  158,  161,  270,  139,  137,  197,  137,   82,
 /*   520 */    24,  153,  159,  160,  112,  116,  122,  247,  128,   87,
 /*   530 */    16,   86,  241,  156,  154,  155,  157,  158,  161,  242,
 /*   540 */   263,   89,  307,   43,   45,   65,   70,   47,   49,   51,
 /*   550 */    39,   37,   41,   35,   32,  101,   72,   67,  152,  262,
 /*   560 */   421,    1,    2,    3,    4,    5,    6,   88,   76,  137,
 /*   570 */   236,  199,  195,   54,   78,  311,  120,  246,  188,   66,
 /*   580 */   121,  306,  235,   82,  218,   74,  129,  275,  152,  184,
 /*   590 */   152,  152,  249,  190,  195,   86,  136,  152,  265,  137,
 /*   600 */   227,  137,  137,   98,  152,  254,   52,  268,  137,  106,
 /*   610 */   305,   81,  152,  207,  152,  137,   82,  255,   64,  124,
 /*   620 */   123,  152,   82,  137,  152,  137,  225,  152,   86,  251,
 /*   630 */   143,  152,  137,   56,   86,  137,  152,  152,  137,  318,
 /*   640 */    46,   50,  137,   40,  272,  214,   48,  137,  137,  226,
 /*   650 */    34,  152,  250,  151,  274,  352,  304,  234,  152,  152,
 /*   660 */   253,  152,  137,  152,  152,   60,   36,  152,  152,  137,
 /*   670 */   137,  152,  137,   14,  137,  137,  245,  233,  137,  137,
 /*   680 */   118,  256,  137,  152,  152,  149,  303,   62,  217,   44,
 /*   690 */    38,  180,   42,   71,  137,  137,  240,  100,  152,  258,
 /*   700 */     8,   10,  134,  152,  234,  152,  152,  152,  152,  137,
 /*   710 */   152,  152,  126,   84,  137,  152,  137,  137,  137,  137,
 /*   720 */   152,  137,  137,  261,  244,  127,  137,  302,  301,  273,
 /*   730 */   176,  137,  300,  216,  173,  266,  163,  324,  269,  267,
 /*   740 */   299,  140,   12,  171,  132,  168,   27,    9,   73,   75,
 /*   750 */    13,  111,   18,  221,  219,  228,  113,   11,   25,  213,
 /*   760 */   231,
};
static PPCODETYPE pp_lookahead[] = {
 /*     0 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    10 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*    20 */    21,   22,   23,    1,    2,    3,    4,    5,    6,    7,
 /*    30 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*    40 */    18,   19,   20,   21,   22,   23,   19,   20,   21,   22,
 /*    50 */    23,   26,   30,   17,   32,   13,   14,   15,   16,   17,
 /*    60 */    18,   19,   20,   21,   22,   23,   30,   68,   25,   70,
 /*    70 */    27,    1,    2,    3,    4,    5,    6,    7,    8,    9,
 /*    80 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*    90 */    20,   21,   22,   23,    1,    2,    3,    4,    5,    6,
 /*   100 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   110 */    17,   18,   19,   20,   21,   22,   23,   67,   68,   30,
 /*   120 */    70,   32,   52,   53,    1,    2,    3,    4,    5,    6,
 /*   130 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   140 */    17,   18,   19,   20,   21,   22,   23,   16,   17,   18,
 /*   150 */    19,   20,   21,   22,   23,   11,   12,  102,   65,   33,
 /*   160 */    34,   35,   36,   80,   38,   39,   22,   84,   45,  114,
 /*   170 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*   180 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   190 */    21,   22,   23,    1,    2,    3,    4,    5,    6,    7,
 /*   200 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   210 */    18,   19,   20,   21,   22,   23,  112,  113,  114,   59,
 /*   220 */    60,   61,   28,   29,   32,   11,   12,   13,   14,   15,
 /*   230 */    16,   17,   18,   19,   20,   21,   22,   23,   69,   57,
 /*   240 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*   250 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   260 */    21,   22,   23,    3,    4,    5,    6,    7,    8,    9,
 /*   270 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   280 */    20,   21,   22,   23,   17,   34,   25,   20,   37,  102,
 /*   290 */    23,   24,   96,   26,   25,   71,   96,   30,   21,   22,
 /*   300 */    23,  114,   33,   34,   35,   36,   45,   38,   39,   17,
 /*   310 */   114,   44,   20,   45,  114,   23,   24,    0,  122,  119,
 /*   320 */   120,  125,   30,  127,  128,  125,   59,   60,   61,   62,
 /*   330 */    63,   64,   34,   66,   31,   37,   44,   45,   71,   72,
 /*   340 */    73,   74,   75,   76,   80,   80,   80,   44,   84,   84,
 /*   350 */    84,   59,   60,   61,   62,   63,   64,   30,   66,   32,
 /*   360 */    96,   96,   96,   71,   72,   73,   74,   75,   76,   17,
 /*   370 */    34,   23,   20,   37,   57,   23,   24,   96,  114,  114,
 /*   380 */   114,   44,   30,   99,  100,  101,  122,  122,   25,  125,
 /*   390 */   125,  125,  128,  128,  121,  114,   44,   20,  117,  118,
 /*   400 */    23,   24,   96,   26,   96,    0,  125,   30,   45,   25,
 /*   410 */    25,   59,   60,   61,   62,   63,   64,   23,   66,   71,
 /*   420 */   114,   44,  114,   71,   72,   73,   74,   75,   76,  106,
 /*   430 */    45,  125,  109,  125,  128,    0,   59,   60,   61,   62,
 /*   440 */    63,   64,   58,   66,   45,   96,   96,   96,   71,   72,
 /*   450 */    73,   74,   75,   76,   17,  105,  105,   20,  108,  108,
 /*   460 */    23,   24,  104,  114,  114,  114,   96,   30,   85,  120,
 /*   470 */    43,   44,   40,   94,  125,  125,  125,   98,   99,  100,
 /*   480 */   101,   44,   20,   44,  114,   23,   24,   96,  118,   96,
 /*   490 */   123,  124,   30,  113,  114,  125,   59,   60,   61,   62,
 /*   500 */    63,   64,   31,   66,  103,  114,   44,  114,   71,   72,
 /*   510 */    73,   74,   75,   76,   97,   44,  125,   30,  125,  102,
 /*   520 */    50,   59,   60,   61,   62,   63,   64,   30,   66,   30,
 /*   530 */   121,  114,   43,   71,   72,   73,   74,   75,   76,   44,
 /*   540 */    96,   30,   30,    9,   10,   11,   12,   13,   14,   15,
 /*   550 */    16,   17,   18,   19,   20,   21,   22,   23,  114,  115,
 /*   560 */    78,   79,   80,   81,   82,   83,   84,   31,   92,  125,
 /*   570 */    96,   95,   96,   96,   93,    0,   30,  109,   97,   96,
 /*   580 */    45,   30,  108,  102,   54,   26,   96,    0,  114,   34,
 /*   590 */   114,  114,  110,   95,   96,  114,   96,  114,  116,  125,
 /*   600 */    41,  125,  125,   96,  114,   46,   96,   48,  125,   96,
 /*   610 */    30,   97,  114,   96,  114,  125,  102,   97,   96,   96,
 /*   620 */    44,  114,  102,  125,  114,  125,   49,  114,  114,  111,
 /*   630 */    45,  114,  125,   96,  114,  125,  114,  114,  125,    0,
 /*   640 */    96,   96,  125,   96,    0,   96,   96,  125,  125,   96,
 /*   650 */    96,  114,   85,   96,    0,    0,   30,   25,  114,  114,
 /*   660 */   121,  114,  125,  114,  114,   96,   96,  114,  114,  125,
 /*   670 */   125,  114,  125,   46,  125,  125,   25,   45,  125,  125,
 /*   680 */    96,   47,  125,  114,  114,   96,   30,   96,   96,   96,
 /*   690 */    96,   34,   96,   96,  125,  125,   45,   96,  114,   25,
 /*   700 */    86,   88,   96,  114,   25,  114,  114,  114,  114,  125,
 /*   710 */   114,  114,   30,   30,  125,  114,  125,  125,  125,  125,
 /*   720 */   114,  125,  125,    3,   45,   45,  125,   30,   30,    0,
 /*   730 */    34,  125,   30,   55,   34,   85,   28,    0,   27,  111,
 /*   740 */    30,  126,   90,   34,  124,   30,   25,   87,   44,   91,
 /*   750 */    56,   45,  121,   25,   51,   42,   44,   89,   51,   45,
 /*   760 */    44,
};
#define PP_SHIFT_USE_DFLT (-2)
static short pp_shift_ofst[] = {
 /*     0 */   559,  435,  644,  729,  654,  587,  577,  530,  678,  470,
 /*    10 */   182,  694,   -2,  627,   -2,  160,  384,  160,   -2,   -2,
 /*    20 */    -2,   -2,  160,   -2,  707,  462,  721,  462,   -2,   70,
 /*    30 */    -2,   -2,  462,  462,  277,  462,  277,  462,   27,  462,
 /*    40 */    27,  462,   27,  462,  214,  462,  214,  462,  131,  462,
 /*    50 */   131,  462,  131,  462,  534,  462,  534,  462,  534,  462,
 /*    60 */   534,  462,  534,  462,  534,  462,   42,  144,  462,  394,
 /*    70 */   462,   42,  704,  267,  194,  352,   43,  499,  269,   -2,
 /*    80 */   499,   -2,   89,  683,   -2,   -2,   -2,  536,  511,   -2,
 /*    90 */   126,   -2,   -2,  499,  327,  432,   -2,  462,  239,  462,
 /*   100 */   239,  348,   -2,  224,   -2,  462,  260,  377,  123,   -2,
 /*   110 */   706,   -2,  712,   25,  268,   -2,  439,  462,  192,  546,
 /*   120 */   535,   -2,  576,  462,   93,  682,  680,   -2,  462,   -1,
 /*   130 */    50,   -2,   -2,  462,  169,  462,  239,   -2,  471,  708,
 /*   140 */   292,  239,  585,   -2,  261,  437,   -2,   -2,  462,  394,
 /*   150 */   462,  394,   -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,
 /*   160 */    -2,   -2,   -2,   -2,  462,  239,   -2,  715,   -2,   -2,
 /*   170 */   709,  710,  700,  702,  251,  696,  698,  697,  298,  657,
 /*   180 */   656,  626,  336,  555,  580,  551,  512,   -2,   -2,  352,
 /*   190 */    -2,   -2,  303,   36,   -2,   22,  487,   -2,   -2,   -2,
 /*   200 */    -2,   -2,  363,   -2,  399,   -2,  462,  394,  337,  267,
 /*   210 */   385,   -2,  714,   -2,  277,   -2,  462,  239,  703,  462,
 /*   220 */   728,  462,   -2,  239,   -2,  462,  239,  713,  499,  427,
 /*   230 */   716,  462,  632,  405,  462,   -2,  239,   -2,  497,  651,
 /*   240 */   489,  495,  462,  679,  575,  497,   -2,   -2,   -2,  577,
 /*   250 */   317,  639,  160,  655,  499,  634,  499,  674,  499,   -2,
 /*   260 */   720,  462,   -2,  239,   -2,  577,  317,  737,  711,  499,
 /*   270 */    -2,
};
#define PP_REDUCE_USE_DFLT (-1)
static short pp_reduce_ofst[] = {
 /*     0 */   482,   -1,   -1,   -1,   -1,   -1,  383,  614,  660,  613,
 /*    10 */   668,  652,   -1,   -1,   -1,  409,   -1,  631,   -1,   -1,
 /*    20 */    -1,   -1,  273,   -1,   -1,  281,   -1,  370,   -1,   -1,
 /*    30 */    -1,   -1,  549,  554,   -1,  570,   -1,  594,   -1,  547,
 /*    40 */    -1,  596,   -1,  593,   -1,  544,   -1,  550,   -1,  545,
 /*    50 */    -1,  510,   -1,  477,   -1,  537,   -1,  308,   -1,  569,
 /*    60 */    -1,  591,   -1,  522,   -1,  483,   -1,   -1,  393,   -1,
 /*    70 */   597,   -1,   -1,  265,  658,  476,   -1,  481,  379,   -1,
 /*    80 */   514,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*    90 */   284,   -1,   -1,   55,  401,  358,   -1,  507,   -1,  601,
 /*   100 */    -1,   -1,   -1,   -1,   -1,  513,   -1,  266,   -1,   -1,
 /*   110 */    -1,   -1,   -1,   83,   -1,   -1,   -1,  584,   -1,   -1,
 /*   120 */    -1,   -1,   -1,  523,   -1,   -1,   -1,   -1,  490,  367,
 /*   130 */   620,   -1,   -1,  606,   -1,  500,   -1,   -1,   -1,  615,
 /*   140 */   196,   -1,   -1,   -1,   -1,  306,   -1,   -1,  589,   -1,
 /*   150 */   557,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   160 */    -1,   -1,   -1,   -1,  391,   -1,   -1,   -1,   -1,   -1,
 /*   170 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   180 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  498,
 /*   190 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   200 */    -1,   -1,   -1,   -1,   -1,   -1,  517,   -1,   -1,  264,
 /*   210 */    -1,   -1,   -1,   -1,   -1,   -1,  592,   -1,   -1,  200,
 /*   220 */    -1,  349,   -1,   -1,   -1,  553,   -1,   -1,  187,   -1,
 /*   230 */    -1,  350,   -1,   -1,  474,   -1,   -1,   -1,  323,   -1,
 /*   240 */    -1,   -1,  351,   -1,   -1,  468,   -1,   -1,   -1,  567,
 /*   250 */   518,   -1,  539,   -1,  520,   -1,  104,   -1,  380,   -1,
 /*   260 */    -1,  444,   -1,   -1,   -1,  650,  628,   -1,   -1,  417,
 /*   270 */    -1,
};
static PPACTIONTYPE pp_default[] = {
 /*     0 */   420,  420,  420,  420,  420,  420,  331,  340,  345,  333,
 /*    10 */   351,  347,  276,  420,  346,  420,  348,  420,  349,  354,
 /*    20 */   355,  356,  420,  350,  420,  420,  332,  420,  334,  336,
 /*    30 */   337,  338,  420,  420,  357,  420,  359,  420,  360,  420,
 /*    40 */   361,  420,  362,  420,  363,  420,  364,  420,  365,  420,
 /*    50 */   366,  420,  367,  420,  368,  420,  369,  420,  370,  420,
 /*    60 */   371,  420,  372,  420,  373,  420,  374,  420,  420,  375,
 /*    70 */   420,  376,  420,  420,  280,  420,  420,  420,  291,  277,
 /*    80 */   420,  288,  328,  420,  326,  327,  329,  419,  420,  418,
 /*    90 */   290,  292,  294,  420,  298,  309,  295,  420,  308,  420,
 /*   100 */   384,  420,  402,  420,  403,  420,  404,  420,  420,  407,
 /*   110 */   420,  380,  420,  420,  420,  383,  420,  420,  420,  420,
 /*   120 */   420,  385,  420,  420,  420,  420,  420,  386,  420,  420,
 /*   130 */   420,  387,  388,  420,  420,  420,  390,  392,  419,  395,
 /*   140 */   420,  401,  420,  393,  420,  420,  398,  400,  420,  405,
 /*   150 */   420,  406,  408,  409,  410,  411,  412,  413,  414,  415,
 /*   160 */   416,  417,  399,  394,  420,  391,  389,  420,  296,  297,
 /*   170 */   420,  420,  420,  420,  420,  420,  420,  420,  420,  420,
 /*   180 */   420,  420,  420,  420,  420,  420,  420,  293,  289,  420,
 /*   190 */   281,  283,  419,  420,  284,  287,  420,  285,  286,  282,
 /*   200 */   278,  279,  420,  378,  420,  381,  420,  377,  420,  420,
 /*   210 */   420,  379,  420,  382,  358,  335,  420,  344,  420,  420,
 /*   220 */   339,  420,  341,  343,  342,  420,  330,  420,  420,  420,
 /*   230 */   420,  420,  420,  420,  420,  312,  314,  313,  420,  420,
 /*   240 */   420,  420,  420,  420,  420,  420,  315,  317,  316,  331,
 /*   250 */   420,  420,  420,  420,  420,  420,  420,  319,  420,  320,
 /*   260 */   420,  420,  322,  323,  321,  331,  420,  420,  420,  420,
 /*   270 */   325,
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
  "FOR",           "LIMIT",         "OFFSET",        "INTEGER",     
  "NPLACEHOLDER",  "SPLACEHOLDER",  "EXISTS",        "CAST",        
  "CONVERT",       "USING",         "CASE",          "END",         
  "WHEN",          "THEN",          "ELSE",          "NULL",        
  "STRING",        "DOUBLE",        "TRUE",          "FALSE",       
  "BPLACEHOLDER",  "error",         "program",       "query_language",
  "select_statement",  "insert_statement",  "update_statement",  "delete_statement",
  "select_clause",  "where_clause",  "group_clause",  "having_clause",
  "order_clause",  "select_limit_clause",  "for_update_clause",  "distinct_all",
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
 /*   5 */ "select_statement ::= select_clause where_clause group_clause having_clause order_clause select_limit_clause for_update_clause",
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
 /*  75 */ "for_update_clause ::= FOR UPDATE",
 /*  76 */ "for_update_clause ::=",
 /*  77 */ "select_limit_clause ::= LIMIT integer_or_placeholder",
 /*  78 */ "select_limit_clause ::= LIMIT integer_or_placeholder COMMA integer_or_placeholder",
 /*  79 */ "select_limit_clause ::= LIMIT integer_or_placeholder OFFSET integer_or_placeholder",
 /*  80 */ "select_limit_clause ::=",
 /*  81 */ "limit_clause ::= LIMIT integer_or_placeholder",
 /*  82 */ "limit_clause ::=",
 /*  83 */ "integer_or_placeholder ::= INTEGER",
 /*  84 */ "integer_or_placeholder ::= NPLACEHOLDER",
 /*  85 */ "integer_or_placeholder ::= SPLACEHOLDER",
 /*  86 */ "expr ::= MINUS expr",
 /*  87 */ "expr ::= expr MINUS expr",
 /*  88 */ "expr ::= expr PLUS expr",
 /*  89 */ "expr ::= expr TIMES expr",
 /*  90 */ "expr ::= expr DIVIDE expr",
 /*  91 */ "expr ::= expr MOD expr",
 /*  92 */ "expr ::= expr AND expr",
 /*  93 */ "expr ::= expr OR expr",
 /*  94 */ "expr ::= expr BITWISE_AND expr",
 /*  95 */ "expr ::= expr BITWISE_OR expr",
 /*  96 */ "expr ::= expr BITWISE_XOR expr",
 /*  97 */ "expr ::= expr EQUALS expr",
 /*  98 */ "expr ::= expr NOTEQUALS expr",
 /*  99 */ "expr ::= expr LESS expr",
 /* 100 */ "expr ::= expr GREATER expr",
 /* 101 */ "expr ::= expr GREATEREQUAL expr",
 /* 102 */ "expr ::= expr LESSEQUAL expr",
 /* 103 */ "expr ::= expr LIKE expr",
 /* 104 */ "expr ::= expr NOT LIKE expr",
 /* 105 */ "expr ::= expr ILIKE expr",
 /* 106 */ "expr ::= expr NOT ILIKE expr",
 /* 107 */ "expr ::= expr IN PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 108 */ "expr ::= expr NOT IN PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 109 */ "expr ::= PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 110 */ "expr ::= expr IN PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 111 */ "expr ::= expr NOT IN PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 112 */ "expr ::= EXISTS PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 113 */ "expr ::= expr AGAINST expr",
 /* 114 */ "expr ::= CAST PARENTHESES_OPEN expr AS IDENTIFIER PARENTHESES_CLOSE",
 /* 115 */ "expr ::= CONVERT PARENTHESES_OPEN expr USING IDENTIFIER PARENTHESES_CLOSE",
 /* 116 */ "expr ::= CASE expr when_clauses END",
 /* 117 */ "when_clauses ::= when_clauses when_clause",
 /* 118 */ "when_clauses ::= when_clause",
 /* 119 */ "when_clause ::= WHEN expr THEN expr",
 /* 120 */ "when_clause ::= ELSE expr",
 /* 121 */ "expr ::= function_call",
 /* 122 */ "function_call ::= IDENTIFIER PARENTHESES_OPEN distinct_or_null argument_list_or_null PARENTHESES_CLOSE",
 /* 123 */ "distinct_or_null ::= DISTINCT",
 /* 124 */ "distinct_or_null ::=",
 /* 125 */ "argument_list_or_null ::= argument_list",
 /* 126 */ "argument_list_or_null ::=",
 /* 127 */ "argument_list ::= argument_list COMMA argument_item",
 /* 128 */ "argument_list ::= argument_item",
 /* 129 */ "argument_item ::= TIMES",
 /* 130 */ "argument_item ::= expr",
 /* 131 */ "expr ::= expr IS NULL",
 /* 132 */ "expr ::= expr IS NOT NULL",
 /* 133 */ "expr ::= expr BETWEEN expr",
 /* 134 */ "expr ::= NOT expr",
 /* 135 */ "expr ::= BITWISE_NOT expr",
 /* 136 */ "expr ::= PARENTHESES_OPEN expr PARENTHESES_CLOSE",
 /* 137 */ "expr ::= qualified_name",
 /* 138 */ "expr ::= INTEGER",
 /* 139 */ "expr ::= STRING",
 /* 140 */ "expr ::= DOUBLE",
 /* 141 */ "expr ::= NULL",
 /* 142 */ "expr ::= TRUE",
 /* 143 */ "expr ::= FALSE",
 /* 144 */ "expr ::= NPLACEHOLDER",
 /* 145 */ "expr ::= SPLACEHOLDER",
 /* 146 */ "expr ::= BPLACEHOLDER",
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
// 554 "parser.lemon"
{
	if ((pppminor->pp0)) {
		if ((pppminor->pp0)->free_flag) {
			efree((pppminor->pp0)->token);
		}
		efree((pppminor->pp0));
	}
}
// 1239 "parser.c"
      break;
    case 79:
    case 80:
    case 81:
    case 82:
    case 83:
    case 84:
    case 92:
    case 93:
    case 95:
    case 96:
    case 97:
    case 98:
    case 99:
    case 100:
    case 101:
    case 102:
    case 106:
    case 107:
    case 109:
    case 110:
    case 112:
    case 113:
    case 114:
    case 116:
    case 117:
    case 118:
    case 119:
    case 120:
    case 122:
    case 125:
    case 128:
// 567 "parser.lemon"
{ zval_ptr_dtor(&(pppminor->pp42)); }
// 1274 "parser.c"
      break;
    case 85:
    case 86:
    case 87:
    case 88:
    case 89:
    case 90:
    case 91:
    case 103:
    case 104:
    case 111:
    case 126:
    case 127:
// 855 "parser.lemon"
{ zephir_safe_zval_ptr_dtor((pppminor->pp42)); }
// 1290 "parser.c"
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
  { 80, 7 },
  { 84, 6 },
  { 91, 1 },
  { 91, 1 },
  { 91, 0 },
  { 92, 3 },
  { 92, 1 },
  { 95, 1 },
  { 95, 3 },
  { 95, 3 },
  { 95, 2 },
  { 95, 1 },
  { 93, 3 },
  { 93, 1 },
  { 94, 1 },
  { 94, 0 },
  { 98, 2 },
  { 98, 1 },
  { 99, 1 },
  { 100, 4 },
  { 103, 2 },
  { 103, 1 },
  { 103, 0 },
  { 101, 2 },
  { 101, 2 },
  { 101, 3 },
  { 101, 2 },
  { 101, 3 },
  { 101, 2 },
  { 101, 3 },
  { 101, 2 },
  { 101, 1 },
  { 104, 2 },
  { 104, 0 },
  { 81, 7 },
  { 81, 10 },
  { 105, 3 },
  { 105, 1 },
  { 108, 1 },
  { 106, 3 },
  { 106, 1 },
  { 109, 1 },
  { 82, 3 },
  { 110, 4 },
  { 112, 3 },
  { 112, 1 },
  { 113, 3 },
  { 115, 1 },
  { 83, 3 },
  { 116, 3 },
  { 97, 3 },
  { 97, 2 },
  { 97, 1 },
  { 102, 1 },
  { 85, 2 },
  { 85, 0 },
  { 88, 3 },
  { 88, 0 },
  { 117, 3 },
  { 117, 1 },
  { 118, 1 },
  { 118, 2 },
  { 118, 2 },
  { 86, 3 },
  { 86, 0 },
  { 119, 3 },
  { 119, 1 },
  { 120, 1 },
  { 87, 2 },
  { 87, 0 },
  { 90, 2 },
  { 90, 0 },
  { 89, 2 },
  { 89, 4 },
  { 89, 4 },
  { 89, 0 },
  { 111, 2 },
  { 111, 0 },
  { 121, 1 },
  { 121, 1 },
  { 121, 1 },
  { 96, 2 },
  { 96, 3 },
  { 96, 3 },
  { 96, 3 },
  { 96, 3 },
  { 96, 3 },
  { 96, 3 },
  { 96, 3 },
  { 96, 3 },
  { 96, 3 },
  { 96, 3 },
  { 96, 3 },
  { 96, 3 },
  { 96, 3 },
  { 96, 3 },
  { 96, 3 },
  { 96, 3 },
  { 96, 3 },
  { 96, 4 },
  { 96, 3 },
  { 96, 4 },
  { 96, 5 },
  { 96, 6 },
  { 96, 3 },
  { 96, 5 },
  { 96, 6 },
  { 96, 4 },
  { 96, 3 },
  { 96, 6 },
  { 96, 6 },
  { 96, 4 },
  { 123, 2 },
  { 123, 1 },
  { 124, 4 },
  { 124, 2 },
  { 96, 1 },
  { 125, 5 },
  { 126, 1 },
  { 126, 0 },
  { 127, 1 },
  { 127, 0 },
  { 122, 3 },
  { 122, 1 },
  { 128, 1 },
  { 128, 1 },
  { 96, 3 },
  { 96, 4 },
  { 96, 3 },
  { 96, 2 },
  { 96, 2 },
  { 96, 3 },
  { 96, 1 },
  { 96, 1 },
  { 96, 1 },
  { 96, 1 },
  { 96, 1 },
  { 96, 1 },
  { 96, 1 },
  { 96, 1 },
  { 96, 1 },
  { 96, 1 },
  { 114, 3 },
  { 114, 1 },
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
// 563 "parser.lemon"
{
	status->ret = ppmsp[0].minor.pp42;
}
// 1656 "parser.c"
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
      case 121:
      case 125:
      case 130:
      case 137:
// 569 "parser.lemon"
{
	ppgotominor.pp42 = ppmsp[0].minor.pp42;
}
// 1681 "parser.c"
        break;
      case 5:
// 587 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_select_statement(ppmsp[-6].minor.pp42, ppmsp[-5].minor.pp42, ppmsp[-2].minor.pp42, ppmsp[-4].minor.pp42, ppmsp[-3].minor.pp42, ppmsp[-1].minor.pp42, ppmsp[0].minor.pp42);
}
// 1688 "parser.c"
        break;
      case 6:
// 593 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_select_clause(ppmsp[-4].minor.pp42, ppmsp[-3].minor.pp42, ppmsp[-1].minor.pp42, ppmsp[0].minor.pp42);
  pp_destructor(26,&ppmsp[-5].minor);
  pp_destructor(27,&ppmsp[-2].minor);
}
// 1697 "parser.c"
        break;
      case 7:
// 599 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_distinct_all(1);
  pp_destructor(28,&ppmsp[0].minor);
}
// 1705 "parser.c"
        break;
      case 8:
// 603 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_distinct_all(0);
  pp_destructor(29,&ppmsp[0].minor);
}
// 1713 "parser.c"
        break;
      case 9:
      case 20:
      case 27:
      case 38:
      case 60:
      case 62:
      case 69:
      case 74:
      case 76:
      case 80:
      case 82:
      case 124:
      case 126:
// 607 "parser.lemon"
{
	ppgotominor.pp42 = NULL;
}
// 1732 "parser.c"
        break;
      case 10:
      case 17:
      case 41:
      case 44:
      case 49:
      case 63:
      case 70:
      case 127:
// 613 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_zval_list(ppmsp[-2].minor.pp42, ppmsp[0].minor.pp42);
  pp_destructor(25,&ppmsp[-1].minor);
}
// 1747 "parser.c"
        break;
      case 11:
      case 42:
      case 45:
      case 118:
      case 128:
// 617 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_zval_list(ppmsp[0].minor.pp42, NULL);
}
// 1758 "parser.c"
        break;
      case 12:
      case 129:
// 623 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_column_item(PHQL_T_STARALL, NULL, NULL, NULL);
  pp_destructor(17,&ppmsp[0].minor);
}
// 1767 "parser.c"
        break;
      case 13:
// 627 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_column_item(PHQL_T_DOMAINALL, NULL, ppmsp[-2].minor.pp0, NULL);
  pp_destructor(31,&ppmsp[-1].minor);
  pp_destructor(17,&ppmsp[0].minor);
}
// 1776 "parser.c"
        break;
      case 14:
// 631 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_column_item(PHQL_T_EXPR, ppmsp[-2].minor.pp42, NULL, ppmsp[0].minor.pp0);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 1784 "parser.c"
        break;
      case 15:
// 635 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_column_item(PHQL_T_EXPR, ppmsp[-1].minor.pp42, NULL, ppmsp[0].minor.pp0);
}
// 1791 "parser.c"
        break;
      case 16:
// 639 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_column_item(PHQL_T_EXPR, ppmsp[0].minor.pp42, NULL, NULL);
}
// 1798 "parser.c"
        break;
      case 21:
      case 117:
// 663 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_zval_list(ppmsp[-1].minor.pp42, ppmsp[0].minor.pp42);
}
// 1806 "parser.c"
        break;
      case 24:
// 680 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_join_item(ppmsp[-3].minor.pp42, ppmsp[-2].minor.pp42, ppmsp[-1].minor.pp42, ppmsp[0].minor.pp42);
}
// 1813 "parser.c"
        break;
      case 25:
// 686 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_qualified_name(NULL, NULL, ppmsp[0].minor.pp0);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 1821 "parser.c"
        break;
      case 26:
      case 46:
      case 148:
// 690 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_qualified_name(NULL, NULL, ppmsp[0].minor.pp0);
}
// 1830 "parser.c"
        break;
      case 28:
// 700 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_join_type(PHQL_T_INNERJOIN);
  pp_destructor(33,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1839 "parser.c"
        break;
      case 29:
// 704 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_join_type(PHQL_T_CROSSJOIN);
  pp_destructor(35,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1848 "parser.c"
        break;
      case 30:
// 708 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  pp_destructor(36,&ppmsp[-2].minor);
  pp_destructor(37,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1858 "parser.c"
        break;
      case 31:
// 712 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  pp_destructor(36,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1867 "parser.c"
        break;
      case 32:
// 716 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  pp_destructor(38,&ppmsp[-2].minor);
  pp_destructor(37,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1877 "parser.c"
        break;
      case 33:
// 720 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  pp_destructor(38,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1886 "parser.c"
        break;
      case 34:
// 724 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_join_type(PHQL_T_FULLJOIN);
  pp_destructor(39,&ppmsp[-2].minor);
  pp_destructor(37,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1896 "parser.c"
        break;
      case 35:
// 728 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_join_type(PHQL_T_FULLJOIN);
  pp_destructor(39,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1905 "parser.c"
        break;
      case 36:
// 732 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_join_type(PHQL_T_INNERJOIN);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1913 "parser.c"
        break;
      case 37:
// 738 "parser.lemon"
{
	ppgotominor.pp42 = ppmsp[0].minor.pp42;
  pp_destructor(40,&ppmsp[-1].minor);
}
// 1921 "parser.c"
        break;
      case 39:
// 749 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_insert_statement(ppmsp[-4].minor.pp42, NULL, ppmsp[-1].minor.pp42);
  pp_destructor(41,&ppmsp[-6].minor);
  pp_destructor(42,&ppmsp[-5].minor);
  pp_destructor(43,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1933 "parser.c"
        break;
      case 40:
// 753 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_insert_statement(ppmsp[-7].minor.pp42, ppmsp[-5].minor.pp42, ppmsp[-1].minor.pp42);
  pp_destructor(41,&ppmsp[-9].minor);
  pp_destructor(42,&ppmsp[-8].minor);
  pp_destructor(44,&ppmsp[-6].minor);
  pp_destructor(45,&ppmsp[-4].minor);
  pp_destructor(43,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1947 "parser.c"
        break;
      case 47:
// 791 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_update_statement(ppmsp[-2].minor.pp42, ppmsp[-1].minor.pp42, ppmsp[0].minor.pp42);
}
// 1954 "parser.c"
        break;
      case 48:
// 797 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_update_clause(ppmsp[-2].minor.pp42, ppmsp[0].minor.pp42);
  pp_destructor(46,&ppmsp[-3].minor);
  pp_destructor(47,&ppmsp[-1].minor);
}
// 1963 "parser.c"
        break;
      case 51:
// 813 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_update_item(ppmsp[-2].minor.pp42, ppmsp[0].minor.pp42);
  pp_destructor(3,&ppmsp[-1].minor);
}
// 1971 "parser.c"
        break;
      case 53:
// 825 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_delete_statement(ppmsp[-2].minor.pp42, ppmsp[-1].minor.pp42, ppmsp[0].minor.pp42);
}
// 1978 "parser.c"
        break;
      case 54:
// 831 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_delete_clause(ppmsp[0].minor.pp42);
  pp_destructor(48,&ppmsp[-2].minor);
  pp_destructor(27,&ppmsp[-1].minor);
}
// 1987 "parser.c"
        break;
      case 55:
// 837 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_assoc_name(ppmsp[-2].minor.pp42, ppmsp[0].minor.pp0);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 1995 "parser.c"
        break;
      case 56:
// 841 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_assoc_name(ppmsp[-1].minor.pp42, ppmsp[0].minor.pp0);
}
// 2002 "parser.c"
        break;
      case 57:
// 845 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_assoc_name(ppmsp[0].minor.pp42, NULL);
}
// 2009 "parser.c"
        break;
      case 59:
// 857 "parser.lemon"
{
	ppgotominor.pp42 = ppmsp[0].minor.pp42;
  pp_destructor(49,&ppmsp[-1].minor);
}
// 2017 "parser.c"
        break;
      case 61:
// 867 "parser.lemon"
{
	ppgotominor.pp42 = ppmsp[0].minor.pp42;
  pp_destructor(50,&ppmsp[-2].minor);
  pp_destructor(51,&ppmsp[-1].minor);
}
// 2026 "parser.c"
        break;
      case 65:
// 887 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_order_item(ppmsp[0].minor.pp42, 0);
}
// 2033 "parser.c"
        break;
      case 66:
// 891 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_order_item(ppmsp[-1].minor.pp42, PHQL_T_ASC);
  pp_destructor(52,&ppmsp[0].minor);
}
// 2041 "parser.c"
        break;
      case 67:
// 895 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_order_item(ppmsp[-1].minor.pp42, PHQL_T_DESC);
  pp_destructor(53,&ppmsp[0].minor);
}
// 2049 "parser.c"
        break;
      case 68:
// 901 "parser.lemon"
{
	ppgotominor.pp42 = ppmsp[0].minor.pp42;
  pp_destructor(54,&ppmsp[-2].minor);
  pp_destructor(51,&ppmsp[-1].minor);
}
// 2058 "parser.c"
        break;
      case 73:
// 927 "parser.lemon"
{
	ppgotominor.pp42 = ppmsp[0].minor.pp42;
  pp_destructor(55,&ppmsp[-1].minor);
}
// 2066 "parser.c"
        break;
      case 75:
// 937 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_for_update_clause();
  pp_destructor(56,&ppmsp[-1].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 2075 "parser.c"
        break;
      case 77:
      case 81:
// 947 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_limit_clause(ppmsp[0].minor.pp42, NULL);
  pp_destructor(57,&ppmsp[-1].minor);
}
// 2084 "parser.c"
        break;
      case 78:
// 951 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_limit_clause(ppmsp[0].minor.pp42, ppmsp[-2].minor.pp42);
  pp_destructor(57,&ppmsp[-3].minor);
  pp_destructor(25,&ppmsp[-1].minor);
}
// 2093 "parser.c"
        break;
      case 79:
// 955 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_limit_clause(ppmsp[-2].minor.pp42, ppmsp[0].minor.pp42);
  pp_destructor(57,&ppmsp[-3].minor);
  pp_destructor(58,&ppmsp[-1].minor);
}
// 2102 "parser.c"
        break;
      case 83:
      case 138:
// 973 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_literal_zval(PHQL_T_INTEGER, ppmsp[0].minor.pp0);
}
// 2110 "parser.c"
        break;
      case 84:
      case 144:
// 977 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_placeholder_zval(PHQL_T_NPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 2118 "parser.c"
        break;
      case 85:
      case 145:
// 981 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_placeholder_zval(PHQL_T_SPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 2126 "parser.c"
        break;
      case 86:
// 987 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_MINUS, NULL, ppmsp[0].minor.pp42);
  pp_destructor(20,&ppmsp[-1].minor);
}
// 2134 "parser.c"
        break;
      case 87:
// 991 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_SUB, ppmsp[-2].minor.pp42, ppmsp[0].minor.pp42);
  pp_destructor(20,&ppmsp[-1].minor);
}
// 2142 "parser.c"
        break;
      case 88:
// 995 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_ADD, ppmsp[-2].minor.pp42, ppmsp[0].minor.pp42);
  pp_destructor(19,&ppmsp[-1].minor);
}
// 2150 "parser.c"
        break;
      case 89:
// 999 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_MUL, ppmsp[-2].minor.pp42, ppmsp[0].minor.pp42);
  pp_destructor(17,&ppmsp[-1].minor);
}
// 2158 "parser.c"
        break;
      case 90:
// 1003 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_DIV, ppmsp[-2].minor.pp42, ppmsp[0].minor.pp42);
  pp_destructor(16,&ppmsp[-1].minor);
}
// 2166 "parser.c"
        break;
      case 91:
// 1007 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_MOD, ppmsp[-2].minor.pp42, ppmsp[0].minor.pp42);
  pp_destructor(18,&ppmsp[-1].minor);
}
// 2174 "parser.c"
        break;
      case 92:
// 1011 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_AND, ppmsp[-2].minor.pp42, ppmsp[0].minor.pp42);
  pp_destructor(9,&ppmsp[-1].minor);
}
// 2182 "parser.c"
        break;
      case 93:
// 1015 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_OR, ppmsp[-2].minor.pp42, ppmsp[0].minor.pp42);
  pp_destructor(10,&ppmsp[-1].minor);
}
// 2190 "parser.c"
        break;
      case 94:
// 1019 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_BITWISE_AND, ppmsp[-2].minor.pp42, ppmsp[0].minor.pp42);
  pp_destructor(13,&ppmsp[-1].minor);
}
// 2198 "parser.c"
        break;
      case 95:
// 1023 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_BITWISE_OR, ppmsp[-2].minor.pp42, ppmsp[0].minor.pp42);
  pp_destructor(14,&ppmsp[-1].minor);
}
// 2206 "parser.c"
        break;
      case 96:
// 1027 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_BITWISE_XOR, ppmsp[-2].minor.pp42, ppmsp[0].minor.pp42);
  pp_destructor(15,&ppmsp[-1].minor);
}
// 2214 "parser.c"
        break;
      case 97:
// 1031 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_EQUALS, ppmsp[-2].minor.pp42, ppmsp[0].minor.pp42);
  pp_destructor(3,&ppmsp[-1].minor);
}
// 2222 "parser.c"
        break;
      case 98:
// 1035 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_NOTEQUALS, ppmsp[-2].minor.pp42, ppmsp[0].minor.pp42);
  pp_destructor(4,&ppmsp[-1].minor);
}
// 2230 "parser.c"
        break;
      case 99:
// 1039 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_LESS, ppmsp[-2].minor.pp42, ppmsp[0].minor.pp42);
  pp_destructor(5,&ppmsp[-1].minor);
}
// 2238 "parser.c"
        break;
      case 100:
// 1043 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_GREATER, ppmsp[-2].minor.pp42, ppmsp[0].minor.pp42);
  pp_destructor(6,&ppmsp[-1].minor);
}
// 2246 "parser.c"
        break;
      case 101:
// 1047 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_GREATEREQUAL, ppmsp[-2].minor.pp42, ppmsp[0].minor.pp42);
  pp_destructor(7,&ppmsp[-1].minor);
}
// 2254 "parser.c"
        break;
      case 102:
// 1051 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_LESSEQUAL, ppmsp[-2].minor.pp42, ppmsp[0].minor.pp42);
  pp_destructor(8,&ppmsp[-1].minor);
}
// 2262 "parser.c"
        break;
      case 103:
// 1055 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_LIKE, ppmsp[-2].minor.pp42, ppmsp[0].minor.pp42);
  pp_destructor(11,&ppmsp[-1].minor);
}
// 2270 "parser.c"
        break;
      case 104:
// 1059 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_NLIKE, ppmsp[-3].minor.pp42, ppmsp[0].minor.pp42);
  pp_destructor(23,&ppmsp[-2].minor);
  pp_destructor(11,&ppmsp[-1].minor);
}
// 2279 "parser.c"
        break;
      case 105:
// 1063 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_ILIKE, ppmsp[-2].minor.pp42, ppmsp[0].minor.pp42);
  pp_destructor(12,&ppmsp[-1].minor);
}
// 2287 "parser.c"
        break;
      case 106:
// 1067 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_NILIKE, ppmsp[-3].minor.pp42, ppmsp[0].minor.pp42);
  pp_destructor(23,&ppmsp[-2].minor);
  pp_destructor(12,&ppmsp[-1].minor);
}
// 2296 "parser.c"
        break;
      case 107:
      case 110:
// 1071 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_IN, ppmsp[-4].minor.pp42, ppmsp[-1].minor.pp42);
  pp_destructor(22,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2307 "parser.c"
        break;
      case 108:
      case 111:
// 1075 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_NOTIN, ppmsp[-5].minor.pp42, ppmsp[-1].minor.pp42);
  pp_destructor(23,&ppmsp[-4].minor);
  pp_destructor(22,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2319 "parser.c"
        break;
      case 109:
// 1079 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_SUBQUERY, ppmsp[-1].minor.pp42, NULL);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2328 "parser.c"
        break;
      case 112:
// 1091 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_EXISTS, NULL, ppmsp[-1].minor.pp42);
  pp_destructor(62,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2338 "parser.c"
        break;
      case 113:
// 1095 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_AGAINST, ppmsp[-2].minor.pp42, ppmsp[0].minor.pp42);
  pp_destructor(1,&ppmsp[-1].minor);
}
// 2346 "parser.c"
        break;
      case 114:
// 1099 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_CAST, ppmsp[-3].minor.pp42, phql_ret_raw_qualified_name(ppmsp[-1].minor.pp0, NULL));
  pp_destructor(63,&ppmsp[-5].minor);
  pp_destructor(44,&ppmsp[-4].minor);
  pp_destructor(32,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2357 "parser.c"
        break;
      case 115:
// 1103 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_CONVERT, ppmsp[-3].minor.pp42, phql_ret_raw_qualified_name(ppmsp[-1].minor.pp0, NULL));
  pp_destructor(64,&ppmsp[-5].minor);
  pp_destructor(44,&ppmsp[-4].minor);
  pp_destructor(65,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2368 "parser.c"
        break;
      case 116:
// 1107 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_CASE, ppmsp[-2].minor.pp42, ppmsp[-1].minor.pp42);
  pp_destructor(66,&ppmsp[-3].minor);
  pp_destructor(67,&ppmsp[0].minor);
}
// 2377 "parser.c"
        break;
      case 119:
// 1119 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_WHEN, ppmsp[-2].minor.pp42, ppmsp[0].minor.pp42);
  pp_destructor(68,&ppmsp[-3].minor);
  pp_destructor(69,&ppmsp[-1].minor);
}
// 2386 "parser.c"
        break;
      case 120:
// 1123 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_ELSE, ppmsp[0].minor.pp42, NULL);
  pp_destructor(70,&ppmsp[-1].minor);
}
// 2394 "parser.c"
        break;
      case 122:
// 1133 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_func_call(ppmsp[-4].minor.pp0, ppmsp[-1].minor.pp42, ppmsp[-2].minor.pp42);
  pp_destructor(44,&ppmsp[-3].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2403 "parser.c"
        break;
      case 123:
// 1139 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_distinct();
  pp_destructor(28,&ppmsp[0].minor);
}
// 2411 "parser.c"
        break;
      case 131:
// 1177 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_ISNULL, ppmsp[-2].minor.pp42, NULL);
  pp_destructor(21,&ppmsp[-1].minor);
  pp_destructor(71,&ppmsp[0].minor);
}
// 2420 "parser.c"
        break;
      case 132:
// 1181 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_ISNOTNULL, ppmsp[-3].minor.pp42, NULL);
  pp_destructor(21,&ppmsp[-2].minor);
  pp_destructor(23,&ppmsp[-1].minor);
  pp_destructor(71,&ppmsp[0].minor);
}
// 2430 "parser.c"
        break;
      case 133:
// 1185 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_BETWEEN, ppmsp[-2].minor.pp42, ppmsp[0].minor.pp42);
  pp_destructor(2,&ppmsp[-1].minor);
}
// 2438 "parser.c"
        break;
      case 134:
// 1189 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_NOT, NULL, ppmsp[0].minor.pp42);
  pp_destructor(23,&ppmsp[-1].minor);
}
// 2446 "parser.c"
        break;
      case 135:
// 1193 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_BITWISE_NOT, NULL, ppmsp[0].minor.pp42);
  pp_destructor(24,&ppmsp[-1].minor);
}
// 2454 "parser.c"
        break;
      case 136:
// 1197 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_expr(PHQL_T_ENCLOSED, ppmsp[-1].minor.pp42, NULL);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2463 "parser.c"
        break;
      case 139:
// 1209 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_literal_zval(PHQL_T_STRING, ppmsp[0].minor.pp0);
}
// 2470 "parser.c"
        break;
      case 140:
// 1213 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_literal_zval(PHQL_T_DOUBLE, ppmsp[0].minor.pp0);
}
// 2477 "parser.c"
        break;
      case 141:
// 1217 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_literal_zval(PHQL_T_NULL, NULL);
  pp_destructor(71,&ppmsp[0].minor);
}
// 2485 "parser.c"
        break;
      case 142:
// 1221 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_literal_zval(PHQL_T_TRUE, NULL);
  pp_destructor(74,&ppmsp[0].minor);
}
// 2493 "parser.c"
        break;
      case 143:
// 1225 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_literal_zval(PHQL_T_FALSE, NULL);
  pp_destructor(75,&ppmsp[0].minor);
}
// 2501 "parser.c"
        break;
      case 146:
// 1240 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_placeholder_zval(PHQL_T_BPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 2508 "parser.c"
        break;
      case 147:
// 1246 "parser.lemon"
{
	ppgotominor.pp42 = phql_ret_qualified_name(NULL, ppmsp[-2].minor.pp0, ppmsp[0].minor.pp0);
  pp_destructor(31,&ppmsp[-1].minor);
}
// 2516 "parser.c"
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
// 487 "parser.lemon"

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

// 2625 "parser.c"
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
  { SL("FOR"),           PHQL_T_FOR },
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
