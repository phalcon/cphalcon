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
#define PPNOCODE 120
#define PPACTIONTYPE unsigned short int
#define phql_TOKENTYPE phql_parser_token*
typedef union {
  phql_TOKENTYPE pp0;
  zval* pp92;
  int pp239;
} PPMINORTYPE;
#define PPSTACKDEPTH 100
#define phql_ARG_SDECL phql_parser_status *status;
#define phql_ARG_PDECL ,phql_parser_status *status
#define phql_ARG_FETCH phql_parser_status *status = pppParser->status
#define phql_ARG_STORE pppParser->status = status
#define PPNSTATE 253
#define PPNRULE 141
#define PPERRORSYMBOL 70
#define PPERRSYMDT pp239
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
 /*     0 */   100,  106,   50,   52,   54,   56,   58,   60,   40,   42,
 /*    10 */    62,   67,   44,   46,   48,   36,   34,   38,   32,   29,
 /*    20 */   102,   69,   64,  207,  100,  106,   50,   52,   54,   56,
 /*    30 */    58,   60,   40,   42,   62,   67,   44,   46,   48,   36,
 /*    40 */    34,   38,   32,   29,  102,   69,   64,   16,   17,   18,
 /*    50 */   253,   27,   28,  180,  171,  178,   74,  100,  106,   50,
 /*    60 */    52,   54,   56,   58,   60,   40,   42,   62,   67,   44,
 /*    70 */    46,   48,   36,   34,   38,   32,   29,  102,   69,   64,
 /*    80 */    36,   34,   38,   32,   29,  102,   69,   64,  111,    7,
 /*    90 */   100,  106,   50,   52,   54,   56,   58,   60,   40,   42,
 /*   100 */    62,   67,   44,   46,   48,   36,   34,   38,   32,   29,
 /*   110 */   102,   69,   64,  100,  106,   50,   52,   54,   56,   58,
 /*   120 */    60,   40,   42,   62,   67,   44,   46,   48,   36,   34,
 /*   130 */    38,   32,   29,  102,   69,   64,   40,   42,   62,   67,
 /*   140 */    44,   46,   48,   36,   34,   38,   32,   29,  102,   69,
 /*   150 */    64,  254,  117,  102,   69,   64,   82,  137,   80,  100,
 /*   160 */   106,   50,   52,   54,   56,   58,   60,   40,   42,   62,
 /*   170 */    67,   44,   46,   48,   36,   34,   38,   32,   29,  102,
 /*   180 */    69,   64,   50,   52,   54,   56,   58,   60,   40,   42,
 /*   190 */    62,   67,   44,   46,   48,   36,   34,   38,   32,   29,
 /*   200 */   102,   69,   64,  130,  182,  183,   30,   65,  188,  131,
 /*   210 */   133,  151,   71,  149,  130,   77,  121,   30,  190,  159,
 /*   220 */   131,  133,  157,  152,  168,  154,  156,  121,  160,  164,
 /*   230 */   135,  152,  168,  154,  156,  333,  160,  164,   92,   93,
 /*   240 */    94,  135,  370,   14,  139,  145,  146,  108,  114,   26,
 /*   250 */   142,  140,  141,  143,  144,  139,  145,  146,  108,  114,
 /*   260 */    26,  142,  140,  141,  143,  144,  173,  138,  124,   30,
 /*   270 */    23,  197,  131,  133,   89,   19,  120,  130,  138,  174,
 /*   280 */    30,  255,   25,  131,  133,  163,  138,  120,  161,  256,
 /*   290 */   121,  234,   89,  135,  127,  120,  257,  125,  147,   32,
 /*   300 */    29,  102,   69,   64,  135,  122,  200,  139,  145,  146,
 /*   310 */   108,  114,   85,  142,  140,  141,  143,  144,  139,  145,
 /*   320 */   146,  108,  114,    8,  142,  140,  141,  143,  144,   30,
 /*   330 */    85,   76,  131,  133,  198,   91,  169,   93,   94,  121,
 /*   340 */    62,   67,   44,   46,   48,   36,   34,   38,   32,   29,
 /*   350 */   102,   69,   64,  135,   44,   46,   48,   36,   34,   38,
 /*   360 */    32,   29,  102,   69,   64,  175,    9,  139,  145,  146,
 /*   370 */   108,  114,  128,  142,  140,  141,  143,  144,  122,  395,
 /*   380 */     1,    2,    3,    4,    5,    6,   21,  186,  205,  194,
 /*   390 */    13,    6,  369,    6,   12,   73,  212,  220,  181,  177,
 /*   400 */   104,  176,  124,   85,  124,   10,  138,   95,   78,  218,
 /*   410 */   231,  202,  206,   79,   90,  120,  247,  138,  214,   83,
 /*   420 */   138,  219,  138,  241,  242,   83,  120,  138,  184,  120,
 /*   430 */   192,  120,  147,  218,  147,   75,  120,   71,  237,  170,
 /*   440 */   124,  103,  225,   79,   79,  219,  172,  177,  205,   11,
 /*   450 */   218,  138,  209,  196,   22,   83,   83,  236,  138,  250,
 /*   460 */   120,  167,  217,  245,  165,  138,  138,  120,  138,   31,
 /*   470 */   129,  138,  204,   33,  120,  120,   35,  120,   64,  128,
 /*   480 */   120,  138,  244,   15,   37,   20,   70,  138,   39,   24,
 /*   490 */   120,  138,  128,   84,  138,   41,  120,   72,   43,  185,
 /*   500 */   120,   45,  138,  120,   87,   47,  138,  221,   81,   49,
 /*   510 */   230,  120,  193,  138,  211,  120,  138,   51,   96,  138,
 /*   520 */    53,   55,  120,  138,   57,  120,   83,  138,  120,   86,
 /*   530 */    88,   59,  120,  227,   61,  138,  120,   63,  138,  138,
 /*   540 */    97,   66,  138,   90,  120,   68,   98,  120,  120,  138,
 /*   550 */   105,  120,  138,  222,  112,  138,   99,  101,  120,  138,
 /*   560 */   107,  120,  110,  138,  120,  239,  246,  242,  120,  109,
 /*   570 */   116,  113,  120,  132,  138,  138,  134,  136,  138,  216,
 /*   580 */   138,  115,  216,  120,  120,  118,  119,  120,  138,  120,
 /*   590 */   189,  138,  199,  148,  138,  138,  252,  120,  208,  226,
 /*   600 */   120,   79,  215,  120,  120,  126,  123,  150,  138,  153,
 /*   610 */   138,  281,  155,   83,  282,  283,  138,  120,  284,  120,
 /*   620 */   158,  162,  285,  286,  166,  120,  287,  288,  289,  179,
 /*   630 */   201,  203,  292,  229,  187,  191,  293,  210,  233,  195,
 /*   640 */   228,  232,  300,  235,  213,  223,  332,  240,  224,  248,
 /*   650 */   243,  249,  238,  306,  251,
};
static PPCODETYPE pp_lookahead[] = {
 /*     0 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    10 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*    20 */    21,   22,   23,   49,    1,    2,    3,    4,    5,    6,
 /*    30 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*    40 */    17,   18,   19,   20,   21,   22,   23,   58,   59,   60,
 /*    50 */     0,   52,   53,   30,   25,   32,   27,    1,    2,    3,
 /*    60 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*    70 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*    80 */    16,   17,   18,   19,   20,   21,   22,   23,   32,   78,
 /*    90 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*   100 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   110 */    21,   22,   23,    1,    2,    3,    4,    5,    6,    7,
 /*   120 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   130 */    18,   19,   20,   21,   22,   23,    9,   10,   11,   12,
 /*   140 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   150 */    23,    0,   63,   21,   22,   23,   30,   45,   32,    1,
 /*   160 */     2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   170 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   180 */    22,   23,    3,    4,    5,    6,    7,    8,    9,   10,
 /*   190 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   200 */    21,   22,   23,   17,   28,   29,   20,   11,   12,   23,
 /*   210 */    24,   30,   26,   32,   17,   25,   30,   20,   22,   34,
 /*   220 */    23,   24,   37,   33,   34,   35,   36,   30,   38,   39,
 /*   230 */    44,   33,   34,   35,   36,    0,   38,   39,   91,   92,
 /*   240 */    93,   44,   45,   25,   58,   59,   60,   61,   62,   88,
 /*   250 */    64,   65,   66,   67,   68,   58,   59,   60,   61,   62,
 /*   260 */    88,   64,   65,   66,   67,   68,   17,  106,   88,   20,
 /*   270 */   109,  110,   23,   24,   31,   57,  115,   17,  106,   30,
 /*   280 */    20,    0,  110,   23,   24,   34,  106,  115,   37,    0,
 /*   290 */    30,   56,   31,   44,  114,  115,    0,  117,  118,   19,
 /*   300 */    20,   21,   22,   23,   44,   44,   54,   58,   59,   60,
 /*   310 */    61,   62,   69,   64,   65,   66,   67,   68,   58,   59,
 /*   320 */    60,   61,   62,   79,   64,   65,   66,   67,   68,   20,
 /*   330 */    69,   86,   23,   24,   55,   90,   91,   92,   93,   30,
 /*   340 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   350 */    21,   22,   23,   44,   13,   14,   15,   16,   17,   18,
 /*   360 */    19,   20,   21,   22,   23,   31,   80,   58,   59,   60,
 /*   370 */    61,   62,   25,   64,   65,   66,   67,   68,   44,   71,
 /*   380 */    72,   73,   74,   75,   76,   77,   50,   73,   88,   73,
 /*   390 */   113,   77,   45,   77,   56,   84,   43,   44,   87,   88,
 /*   400 */    23,   17,   88,   69,   88,   81,  106,   94,   89,   88,
 /*   410 */   102,  111,  112,   94,   30,  115,  108,  106,   97,  106,
 /*   420 */   106,  100,  106,  105,  106,  106,  115,  106,  114,  115,
 /*   430 */   114,  115,  118,   88,  118,   85,  115,   26,   89,   89,
 /*   440 */    88,   64,   97,   94,   94,  100,   87,   88,   88,   82,
 /*   450 */    88,  106,   41,   88,   51,  106,  106,   46,  106,   48,
 /*   460 */   115,   34,  100,   88,   37,  106,  106,  115,  106,   88,
 /*   470 */   118,  106,  112,   88,  115,  115,   88,  115,   23,   25,
 /*   480 */   115,  106,  107,  113,   88,  113,   44,  106,   88,   25,
 /*   490 */   115,  106,   25,   30,  106,   88,  115,   83,   88,   45,
 /*   500 */   115,   88,  106,  115,   31,   88,  106,   98,   30,   88,
 /*   510 */   101,  115,   45,  106,   94,  115,  106,   88,   95,  106,
 /*   520 */    88,   88,  115,  106,   88,  115,  106,  106,  115,   30,
 /*   530 */    30,   88,  115,   25,   88,  106,  115,   88,  106,  106,
 /*   540 */    96,   88,  106,   30,  115,   88,   40,  115,  115,  106,
 /*   550 */    64,  115,  106,   45,   30,  106,   88,   88,  115,  106,
 /*   560 */    88,  115,   88,  106,  115,  104,  105,  106,  115,   44,
 /*   570 */    88,   45,  115,   88,  106,  106,   88,   88,  106,   25,
 /*   580 */   106,   44,   25,  115,  115,   30,   45,  115,  106,  115,
 /*   590 */    88,  106,   88,   28,  106,  106,   89,  115,   88,   45,
 /*   600 */   115,   94,   45,  115,  115,   45,  116,   30,  106,   34,
 /*   610 */   106,   30,   34,  106,   30,   30,  106,  115,   30,  115,
 /*   620 */    34,   34,   30,   30,   34,  115,   30,   30,   30,   30,
 /*   630 */    51,   25,    0,   30,   45,   44,    0,   42,  103,   45,
 /*   640 */   101,   78,    0,  113,   44,   43,    0,   25,   44,   78,
 /*   650 */     3,  103,   47,    0,   27,
};
#define PP_SHIFT_USE_DFLT (-27)
static short pp_shift_ofst[] = {
 /*     0 */   411,   50,  151,  281,  289,  296,  -26,  252,  279,  336,
 /*    10 */   338,  -27,  -11,  218,  -11,  -27,  -27,  -27,  -27,  -11,
 /*    20 */   -27,  403,  309,  464,  309,  -27,   -1,  -27,  -27,  309,
 /*    30 */   309,  132,  309,  132,  309,  280,  309,  280,  309,  280,
 /*    40 */   309,  329,  309,  329,  309,   64,  309,   64,  309,   64,
 /*    50 */   309,  127,  309,  127,  309,  127,  309,  127,  309,  127,
 /*    60 */   309,  127,  309,  341,  196,  309,  455,  309,  341,  442,
 /*    70 */   186,  176,  249,   29,  463,  190,  -27,  463,  -27,  126,
 /*    80 */   478,  -27,  -27,  -27,  243,  499,  473,  500,  -27,  513,
 /*    90 */   -27,  198,  -27,  -27,  463,  181,  506,  -27,  309,  158,
 /*   100 */   309,  158,  377,  -27,  486,  -27,  309,  179,  525,  309,
 /*   110 */    56,  524,  526,  -27,  537,  309,   89,  555,  541,  -27,
 /*   120 */   -27,  261,  565,  197,  158,  560,  -27,  347,  260,  -27,
 /*   130 */   -27,  309,  455,  309,  455,  309,  112,  -27,  -27,  -27,
 /*   140 */   -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  577,
 /*   150 */   -27,  -27,  575,  581,  578,  584,  185,  586,  585,  588,
 /*   160 */   251,  587,  592,  593,  427,  590,  596,  597,  598,  -27,
 /*   170 */   -27,  249,  -27,  -27,  334,  384,  -27,   23,  599,  -27,
 /*   180 */   -27,  -27,  -27,  -27,  454,  -27,  589,  -27,  309,  455,
 /*   190 */   591,  186,  467,  -27,  594,  -27,  132,  -27,  309,  158,
 /*   200 */   579,  309,  606,  309,  -27,  158,  -27,  309,  158,  595,
 /*   210 */   463,  353,  600,  309,  557,  632,  309,  -27,  158,  -27,
 /*   220 */   603,  508,  602,  604,  309,  554,  636,  603,  -27,  -27,
 /*   230 */   -27,  -26,  235,  642,  -11,  646,  463,  605,  463,  622,
 /*   240 */   463,  -27,  647,  309,  -27,  158,  -27,  -26,  235,  653,
 /*   250 */   627,  463,  -27,
};
#define PP_REDUCE_USE_DFLT (-1)
static short pp_reduce_ofst[] = {
 /*     0 */   308,   -1,   -1,   -1,   -1,   -1,   11,  244,  286,  324,
 /*    10 */   367,   -1,  277,   -1,  370,   -1,   -1,   -1,   -1,  372,
 /*    20 */    -1,   -1,  161,   -1,  172,   -1,   -1,   -1,   -1,  365,
 /*    30 */   381,   -1,  385,   -1,  388,   -1,  396,   -1,  400,   -1,
 /*    40 */   407,   -1,  410,   -1,  413,   -1,  417,   -1,  421,   -1,
 /*    50 */   429,   -1,  432,   -1,  433,   -1,  436,   -1,  443,   -1,
 /*    60 */   446,   -1,  449,   -1,   -1,  453,   -1,  457,   -1,   -1,
 /*    70 */   314,  414,  311,   -1,  350,  245,   -1,  319,   -1,   -1,
 /*    80 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*    90 */    -1,  147,   -1,   -1,  313,  423,  444,   -1,  468,   -1,
 /*   100 */   469,   -1,   -1,   -1,   -1,   -1,  472,   -1,   -1,  474,
 /*   110 */    -1,   -1,   -1,   -1,   -1,  482,   -1,   -1,   -1,   -1,
 /*   120 */    -1,   -1,  490,  180,   -1,   -1,   -1,   -1,  352,   -1,
 /*   130 */    -1,  485,   -1,  488,   -1,  489,   -1,   -1,   -1,   -1,
 /*   140 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   150 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   160 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   170 */    -1,  359,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 /*   180 */    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  502,   -1,
 /*   190 */    -1,  316,   -1,   -1,   -1,   -1,   -1,   -1,  504,   -1,
 /*   200 */    -1,  300,   -1,  360,   -1,   -1,   -1,  510,   -1,   -1,
 /*   210 */   420,   -1,   -1,  321,   -1,   -1,  362,   -1,   -1,   -1,
 /*   220 */   409,   -1,   -1,   -1,  345,   -1,   -1,  539,   -1,   -1,
 /*   230 */    -1,  563,  535,   -1,  530,   -1,  349,   -1,  461,   -1,
 /*   240 */   318,   -1,   -1,  375,   -1,   -1,   -1,  571,  548,   -1,
 /*   250 */    -1,  507,   -1,
};
static PPACTIONTYPE pp_default[] = {
 /*     0 */   394,  394,  394,  394,  394,  394,  313,  322,  327,  315,
 /*    10 */   331,  258,  394,  328,  394,  329,  334,  335,  336,  394,
 /*    20 */   330,  394,  394,  314,  394,  316,  318,  319,  320,  394,
 /*    30 */   394,  337,  394,  339,  394,  340,  394,  341,  394,  342,
 /*    40 */   394,  343,  394,  344,  394,  345,  394,  346,  394,  347,
 /*    50 */   394,  348,  394,  349,  394,  350,  394,  351,  394,  352,
 /*    60 */   394,  353,  394,  354,  394,  394,  355,  394,  356,  394,
 /*    70 */   394,  262,  394,  394,  394,  273,  259,  394,  270,  310,
 /*    80 */   394,  308,  309,  311,  393,  394,  391,  394,  390,  394,
 /*    90 */   392,  272,  274,  276,  394,  280,  291,  277,  394,  290,
 /*   100 */   394,  362,  394,  375,  394,  376,  394,  377,  394,  394,
 /*   110 */   394,  394,  394,  363,  394,  394,  394,  394,  394,  364,
 /*   120 */   365,  393,  368,  394,  374,  394,  366,  394,  394,  371,
 /*   130 */   373,  394,  378,  394,  379,  394,  394,  380,  381,  382,
 /*   140 */   383,  384,  385,  386,  387,  388,  389,  372,  367,  394,
 /*   150 */   278,  279,  394,  394,  394,  394,  394,  394,  394,  394,
 /*   160 */   394,  394,  394,  394,  394,  394,  394,  394,  394,  275,
 /*   170 */   271,  394,  263,  265,  393,  394,  266,  269,  394,  267,
 /*   180 */   268,  264,  260,  261,  394,  358,  394,  360,  394,  357,
 /*   190 */   394,  394,  394,  359,  394,  361,  338,  317,  394,  326,
 /*   200 */   394,  394,  321,  394,  323,  325,  324,  394,  312,  394,
 /*   210 */   394,  394,  394,  394,  394,  394,  394,  294,  296,  295,
 /*   220 */   394,  394,  394,  394,  394,  394,  394,  394,  297,  299,
 /*   230 */   298,  313,  394,  394,  394,  394,  394,  394,  394,  301,
 /*   240 */   394,  302,  394,  394,  304,  305,  303,  313,  394,  394,
 /*   250 */   394,  394,  307,
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
  "SPLACEHOLDER",  "CAST",          "CONVERT",       "USING",       
  "NULL",          "STRING",        "DOUBLE",        "TRUE",        
  "FALSE",         "COLON",         "error",         "program",     
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
  "group_item",    "integer_or_placeholder",  "argument_list",  "function_call",
  "distinct_or_null",  "argument_list_or_null",  "argument_item",
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
 /* 107 */ "expr ::= expr IN PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 108 */ "expr ::= expr NOT IN PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 109 */ "expr ::= expr AGAINST expr",
 /* 110 */ "expr ::= CAST PARENTHESES_OPEN expr AS IDENTIFIER PARENTHESES_CLOSE",
 /* 111 */ "expr ::= CONVERT PARENTHESES_OPEN expr USING IDENTIFIER PARENTHESES_CLOSE",
 /* 112 */ "expr ::= function_call",
 /* 113 */ "function_call ::= IDENTIFIER PARENTHESES_OPEN distinct_or_null argument_list_or_null PARENTHESES_CLOSE",
 /* 114 */ "distinct_or_null ::= DISTINCT",
 /* 115 */ "distinct_or_null ::=",
 /* 116 */ "argument_list_or_null ::= argument_list",
 /* 117 */ "argument_list_or_null ::=",
 /* 118 */ "argument_list ::= argument_list COMMA argument_item",
 /* 119 */ "argument_list ::= argument_item",
 /* 120 */ "argument_item ::= TIMES",
 /* 121 */ "argument_item ::= expr",
 /* 122 */ "expr ::= expr IS NULL",
 /* 123 */ "expr ::= expr IS NOT NULL",
 /* 124 */ "expr ::= expr BETWEEN expr",
 /* 125 */ "expr ::= NOT expr",
 /* 126 */ "expr ::= BITWISE_NOT expr",
 /* 127 */ "expr ::= PARENTHESES_OPEN expr PARENTHESES_CLOSE",
 /* 128 */ "expr ::= qualified_name",
 /* 129 */ "expr ::= INTEGER",
 /* 130 */ "expr ::= STRING",
 /* 131 */ "expr ::= DOUBLE",
 /* 132 */ "expr ::= NULL",
 /* 133 */ "expr ::= TRUE",
 /* 134 */ "expr ::= FALSE",
 /* 135 */ "expr ::= NPLACEHOLDER",
 /* 136 */ "expr ::= SPLACEHOLDER",
 /* 137 */ "qualified_name ::= IDENTIFIER COLON IDENTIFIER DOT IDENTIFIER",
 /* 138 */ "qualified_name ::= IDENTIFIER COLON IDENTIFIER",
 /* 139 */ "qualified_name ::= IDENTIFIER DOT IDENTIFIER",
 /* 140 */ "qualified_name ::= IDENTIFIER",
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
// 541 "parser.lemon"
{
	if ((pppminor->pp0)) {
		if ((pppminor->pp0)->free_flag) {
			efree((pppminor->pp0)->token);
		}
		efree((pppminor->pp0));
	}
}
// 1180 "parser.c"
      break;
    case 72:
    case 73:
    case 74:
    case 75:
    case 76:
    case 77:
    case 84:
    case 85:
    case 87:
    case 88:
    case 89:
    case 90:
    case 91:
    case 92:
    case 93:
    case 94:
    case 98:
    case 99:
    case 101:
    case 102:
    case 104:
    case 105:
    case 106:
    case 108:
    case 109:
    case 110:
    case 111:
    case 112:
    case 114:
    case 115:
    case 118:
// 554 "parser.lemon"
{ zval_ptr_dtor(&(pppminor->pp92)); }
// 1215 "parser.c"
      break;
    case 78:
    case 79:
    case 80:
    case 81:
    case 82:
    case 83:
    case 95:
    case 96:
    case 103:
    case 116:
    case 117:
// 842 "parser.lemon"
{ zephir_safe_zval_ptr_dtor((pppminor->pp92)); }
// 1230 "parser.c"
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
  { 71, 1 },
  { 72, 1 },
  { 72, 1 },
  { 72, 1 },
  { 72, 1 },
  { 73, 6 },
  { 77, 6 },
  { 83, 1 },
  { 83, 1 },
  { 83, 0 },
  { 84, 3 },
  { 84, 1 },
  { 87, 1 },
  { 87, 3 },
  { 87, 3 },
  { 87, 2 },
  { 87, 1 },
  { 85, 3 },
  { 85, 1 },
  { 86, 1 },
  { 86, 0 },
  { 90, 2 },
  { 90, 1 },
  { 91, 1 },
  { 92, 4 },
  { 95, 2 },
  { 95, 1 },
  { 95, 0 },
  { 93, 2 },
  { 93, 2 },
  { 93, 3 },
  { 93, 2 },
  { 93, 3 },
  { 93, 2 },
  { 93, 3 },
  { 93, 2 },
  { 93, 1 },
  { 96, 2 },
  { 96, 0 },
  { 74, 7 },
  { 74, 10 },
  { 97, 3 },
  { 97, 1 },
  { 100, 1 },
  { 98, 3 },
  { 98, 1 },
  { 101, 1 },
  { 75, 3 },
  { 102, 4 },
  { 104, 3 },
  { 104, 1 },
  { 105, 3 },
  { 107, 1 },
  { 76, 3 },
  { 108, 3 },
  { 89, 3 },
  { 89, 2 },
  { 89, 1 },
  { 94, 1 },
  { 78, 2 },
  { 78, 0 },
  { 81, 3 },
  { 81, 0 },
  { 109, 3 },
  { 109, 1 },
  { 110, 1 },
  { 110, 2 },
  { 110, 2 },
  { 79, 3 },
  { 79, 0 },
  { 111, 3 },
  { 111, 1 },
  { 112, 1 },
  { 80, 2 },
  { 80, 0 },
  { 82, 2 },
  { 82, 4 },
  { 82, 4 },
  { 82, 0 },
  { 103, 2 },
  { 103, 0 },
  { 113, 1 },
  { 113, 1 },
  { 113, 1 },
  { 88, 2 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 3 },
  { 88, 4 },
  { 88, 3 },
  { 88, 4 },
  { 88, 5 },
  { 88, 6 },
  { 88, 5 },
  { 88, 6 },
  { 88, 3 },
  { 88, 6 },
  { 88, 6 },
  { 88, 1 },
  { 115, 5 },
  { 116, 1 },
  { 116, 0 },
  { 117, 1 },
  { 117, 0 },
  { 114, 3 },
  { 114, 1 },
  { 118, 1 },
  { 118, 1 },
  { 88, 3 },
  { 88, 4 },
  { 88, 3 },
  { 88, 2 },
  { 88, 2 },
  { 88, 3 },
  { 88, 1 },
  { 88, 1 },
  { 88, 1 },
  { 88, 1 },
  { 88, 1 },
  { 88, 1 },
  { 88, 1 },
  { 88, 1 },
  { 88, 1 },
  { 106, 5 },
  { 106, 3 },
  { 106, 3 },
  { 106, 1 },
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
	status->ret = ppmsp[0].minor.pp92;
}
// 1588 "parser.c"
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
      case 112:
      case 116:
      case 121:
      case 128:
// 556 "parser.lemon"
{
	ppgotominor.pp92 = ppmsp[0].minor.pp92;
}
// 1613 "parser.c"
        break;
      case 5:
// 574 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_select_statement(ppmsp[-5].minor.pp92, ppmsp[-4].minor.pp92, ppmsp[-1].minor.pp92, ppmsp[-3].minor.pp92, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
}
// 1620 "parser.c"
        break;
      case 6:
// 580 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_select_clause(ppmsp[-4].minor.pp92, ppmsp[-3].minor.pp92, ppmsp[-1].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(26,&ppmsp[-5].minor);
  pp_destructor(27,&ppmsp[-2].minor);
}
// 1629 "parser.c"
        break;
      case 7:
// 586 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_distinct_all(1);
  pp_destructor(28,&ppmsp[0].minor);
}
// 1637 "parser.c"
        break;
      case 8:
// 590 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_distinct_all(0);
  pp_destructor(29,&ppmsp[0].minor);
}
// 1645 "parser.c"
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
      case 115:
      case 117:
// 594 "parser.lemon"
{
	ppgotominor.pp92 = NULL;
}
// 1663 "parser.c"
        break;
      case 10:
      case 17:
      case 41:
      case 44:
      case 49:
      case 63:
      case 70:
      case 118:
// 600 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_zval_list(ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(25,&ppmsp[-1].minor);
}
// 1678 "parser.c"
        break;
      case 11:
      case 42:
      case 45:
      case 119:
// 604 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_zval_list(ppmsp[0].minor.pp92, NULL);
}
// 1688 "parser.c"
        break;
      case 12:
      case 120:
// 610 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_column_item(PHQL_T_STARALL, NULL, NULL, NULL);
  pp_destructor(17,&ppmsp[0].minor);
}
// 1697 "parser.c"
        break;
      case 13:
// 614 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_column_item(PHQL_T_DOMAINALL, NULL, ppmsp[-2].minor.pp0, NULL);
  pp_destructor(31,&ppmsp[-1].minor);
  pp_destructor(17,&ppmsp[0].minor);
}
// 1706 "parser.c"
        break;
      case 14:
// 618 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_column_item(PHQL_T_EXPR, ppmsp[-2].minor.pp92, NULL, ppmsp[0].minor.pp0);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 1714 "parser.c"
        break;
      case 15:
// 622 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_column_item(PHQL_T_EXPR, ppmsp[-1].minor.pp92, NULL, ppmsp[0].minor.pp0);
}
// 1721 "parser.c"
        break;
      case 16:
// 626 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_column_item(PHQL_T_EXPR, ppmsp[0].minor.pp92, NULL, NULL);
}
// 1728 "parser.c"
        break;
      case 21:
// 650 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_zval_list(ppmsp[-1].minor.pp92, ppmsp[0].minor.pp92);
}
// 1735 "parser.c"
        break;
      case 24:
// 667 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_join_item(ppmsp[-3].minor.pp92, ppmsp[-2].minor.pp92, ppmsp[-1].minor.pp92, ppmsp[0].minor.pp92);
}
// 1742 "parser.c"
        break;
      case 25:
// 673 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_qualified_name(NULL, NULL, ppmsp[0].minor.pp0);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 1750 "parser.c"
        break;
      case 26:
      case 46:
      case 140:
// 677 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_qualified_name(NULL, NULL, ppmsp[0].minor.pp0);
}
// 1759 "parser.c"
        break;
      case 28:
// 687 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_join_type(PHQL_T_INNERJOIN);
  pp_destructor(33,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1768 "parser.c"
        break;
      case 29:
// 691 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_join_type(PHQL_T_CROSSJOIN);
  pp_destructor(35,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1777 "parser.c"
        break;
      case 30:
// 695 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  pp_destructor(36,&ppmsp[-2].minor);
  pp_destructor(37,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1787 "parser.c"
        break;
      case 31:
// 699 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  pp_destructor(36,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1796 "parser.c"
        break;
      case 32:
// 703 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  pp_destructor(38,&ppmsp[-2].minor);
  pp_destructor(37,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1806 "parser.c"
        break;
      case 33:
// 707 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  pp_destructor(38,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1815 "parser.c"
        break;
      case 34:
// 711 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_join_type(PHQL_T_FULLJOIN);
  pp_destructor(39,&ppmsp[-2].minor);
  pp_destructor(37,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1825 "parser.c"
        break;
      case 35:
// 715 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_join_type(PHQL_T_FULLJOIN);
  pp_destructor(39,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1834 "parser.c"
        break;
      case 36:
// 719 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_join_type(PHQL_T_INNERJOIN);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1842 "parser.c"
        break;
      case 37:
// 725 "parser.lemon"
{
	ppgotominor.pp92 = ppmsp[0].minor.pp92;
  pp_destructor(40,&ppmsp[-1].minor);
}
// 1850 "parser.c"
        break;
      case 39:
// 736 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_insert_statement(ppmsp[-4].minor.pp92, NULL, ppmsp[-1].minor.pp92);
  pp_destructor(41,&ppmsp[-6].minor);
  pp_destructor(42,&ppmsp[-5].minor);
  pp_destructor(43,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1862 "parser.c"
        break;
      case 40:
// 740 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_insert_statement(ppmsp[-7].minor.pp92, ppmsp[-5].minor.pp92, ppmsp[-1].minor.pp92);
  pp_destructor(41,&ppmsp[-9].minor);
  pp_destructor(42,&ppmsp[-8].minor);
  pp_destructor(44,&ppmsp[-6].minor);
  pp_destructor(45,&ppmsp[-4].minor);
  pp_destructor(43,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1876 "parser.c"
        break;
      case 47:
// 778 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_update_statement(ppmsp[-2].minor.pp92, ppmsp[-1].minor.pp92, ppmsp[0].minor.pp92);
}
// 1883 "parser.c"
        break;
      case 48:
// 784 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_update_clause(ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(46,&ppmsp[-3].minor);
  pp_destructor(47,&ppmsp[-1].minor);
}
// 1892 "parser.c"
        break;
      case 51:
// 800 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_update_item(ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(3,&ppmsp[-1].minor);
}
// 1900 "parser.c"
        break;
      case 53:
// 812 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_delete_statement(ppmsp[-2].minor.pp92, ppmsp[-1].minor.pp92, ppmsp[0].minor.pp92);
}
// 1907 "parser.c"
        break;
      case 54:
// 818 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_delete_clause(ppmsp[0].minor.pp92);
  pp_destructor(48,&ppmsp[-2].minor);
  pp_destructor(27,&ppmsp[-1].minor);
}
// 1916 "parser.c"
        break;
      case 55:
// 824 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_assoc_name(ppmsp[-2].minor.pp92, ppmsp[0].minor.pp0);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 1924 "parser.c"
        break;
      case 56:
// 828 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_assoc_name(ppmsp[-1].minor.pp92, ppmsp[0].minor.pp0);
}
// 1931 "parser.c"
        break;
      case 57:
// 832 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_assoc_name(ppmsp[0].minor.pp92, NULL);
}
// 1938 "parser.c"
        break;
      case 59:
// 844 "parser.lemon"
{
	ppgotominor.pp92 = ppmsp[0].minor.pp92;
  pp_destructor(49,&ppmsp[-1].minor);
}
// 1946 "parser.c"
        break;
      case 61:
// 854 "parser.lemon"
{
	ppgotominor.pp92 = ppmsp[0].minor.pp92;
  pp_destructor(50,&ppmsp[-2].minor);
  pp_destructor(51,&ppmsp[-1].minor);
}
// 1955 "parser.c"
        break;
      case 65:
// 874 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_order_item(ppmsp[0].minor.pp92, 0);
}
// 1962 "parser.c"
        break;
      case 66:
// 878 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_order_item(ppmsp[-1].minor.pp92, PHQL_T_ASC);
  pp_destructor(52,&ppmsp[0].minor);
}
// 1970 "parser.c"
        break;
      case 67:
// 882 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_order_item(ppmsp[-1].minor.pp92, PHQL_T_DESC);
  pp_destructor(53,&ppmsp[0].minor);
}
// 1978 "parser.c"
        break;
      case 68:
// 888 "parser.lemon"
{
	ppgotominor.pp92 = ppmsp[0].minor.pp92;
  pp_destructor(54,&ppmsp[-2].minor);
  pp_destructor(51,&ppmsp[-1].minor);
}
// 1987 "parser.c"
        break;
      case 73:
// 914 "parser.lemon"
{
	ppgotominor.pp92 = ppmsp[0].minor.pp92;
  pp_destructor(55,&ppmsp[-1].minor);
}
// 1995 "parser.c"
        break;
      case 75:
      case 79:
// 924 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_limit_clause(ppmsp[0].minor.pp92, NULL);
  pp_destructor(56,&ppmsp[-1].minor);
}
// 2004 "parser.c"
        break;
      case 76:
// 928 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_limit_clause(ppmsp[0].minor.pp92, ppmsp[-2].minor.pp92);
  pp_destructor(56,&ppmsp[-3].minor);
  pp_destructor(25,&ppmsp[-1].minor);
}
// 2013 "parser.c"
        break;
      case 77:
// 932 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_limit_clause(ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(56,&ppmsp[-3].minor);
  pp_destructor(57,&ppmsp[-1].minor);
}
// 2022 "parser.c"
        break;
      case 81:
      case 129:
// 950 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_literal_zval(PHQL_T_INTEGER, ppmsp[0].minor.pp0);
}
// 2030 "parser.c"
        break;
      case 82:
      case 135:
// 954 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_placeholder_zval(PHQL_T_NPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 2038 "parser.c"
        break;
      case 83:
      case 136:
// 958 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_placeholder_zval(PHQL_T_SPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 2046 "parser.c"
        break;
      case 84:
// 964 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_MINUS, NULL, ppmsp[0].minor.pp92);
  pp_destructor(20,&ppmsp[-1].minor);
}
// 2054 "parser.c"
        break;
      case 85:
// 968 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_SUB, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(20,&ppmsp[-1].minor);
}
// 2062 "parser.c"
        break;
      case 86:
// 972 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_ADD, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(19,&ppmsp[-1].minor);
}
// 2070 "parser.c"
        break;
      case 87:
// 976 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_MUL, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(17,&ppmsp[-1].minor);
}
// 2078 "parser.c"
        break;
      case 88:
// 980 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_DIV, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(16,&ppmsp[-1].minor);
}
// 2086 "parser.c"
        break;
      case 89:
// 984 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_MOD, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(18,&ppmsp[-1].minor);
}
// 2094 "parser.c"
        break;
      case 90:
// 988 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_AND, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(9,&ppmsp[-1].minor);
}
// 2102 "parser.c"
        break;
      case 91:
// 992 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_OR, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(10,&ppmsp[-1].minor);
}
// 2110 "parser.c"
        break;
      case 92:
// 996 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_BITWISE_AND, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(13,&ppmsp[-1].minor);
}
// 2118 "parser.c"
        break;
      case 93:
// 1000 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_BITWISE_OR, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(14,&ppmsp[-1].minor);
}
// 2126 "parser.c"
        break;
      case 94:
// 1004 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_BITWISE_XOR, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(15,&ppmsp[-1].minor);
}
// 2134 "parser.c"
        break;
      case 95:
// 1008 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_EQUALS, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(3,&ppmsp[-1].minor);
}
// 2142 "parser.c"
        break;
      case 96:
// 1012 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_NOTEQUALS, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(4,&ppmsp[-1].minor);
}
// 2150 "parser.c"
        break;
      case 97:
// 1016 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_LESS, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(5,&ppmsp[-1].minor);
}
// 2158 "parser.c"
        break;
      case 98:
// 1020 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_GREATER, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(6,&ppmsp[-1].minor);
}
// 2166 "parser.c"
        break;
      case 99:
// 1024 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_GREATEREQUAL, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(7,&ppmsp[-1].minor);
}
// 2174 "parser.c"
        break;
      case 100:
// 1028 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_LESSEQUAL, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(8,&ppmsp[-1].minor);
}
// 2182 "parser.c"
        break;
      case 101:
// 1032 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_LIKE, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(11,&ppmsp[-1].minor);
}
// 2190 "parser.c"
        break;
      case 102:
// 1036 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_NLIKE, ppmsp[-3].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(23,&ppmsp[-2].minor);
  pp_destructor(11,&ppmsp[-1].minor);
}
// 2199 "parser.c"
        break;
      case 103:
// 1040 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_ILIKE, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(12,&ppmsp[-1].minor);
}
// 2207 "parser.c"
        break;
      case 104:
// 1044 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_NILIKE, ppmsp[-3].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(23,&ppmsp[-2].minor);
  pp_destructor(12,&ppmsp[-1].minor);
}
// 2216 "parser.c"
        break;
      case 105:
      case 107:
// 1048 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_IN, ppmsp[-4].minor.pp92, ppmsp[-1].minor.pp92);
  pp_destructor(22,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2227 "parser.c"
        break;
      case 106:
      case 108:
// 1052 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_NOTIN, ppmsp[-5].minor.pp92, ppmsp[-1].minor.pp92);
  pp_destructor(23,&ppmsp[-4].minor);
  pp_destructor(22,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2239 "parser.c"
        break;
      case 109:
// 1064 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_AGAINST, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(1,&ppmsp[-1].minor);
}
// 2247 "parser.c"
        break;
      case 110:
// 1068 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_CAST, ppmsp[-3].minor.pp92, phql_ret_raw_qualified_name(ppmsp[-1].minor.pp0, NULL));
  pp_destructor(61,&ppmsp[-5].minor);
  pp_destructor(44,&ppmsp[-4].minor);
  pp_destructor(32,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2258 "parser.c"
        break;
      case 111:
// 1072 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_CONVERT, ppmsp[-3].minor.pp92, phql_ret_raw_qualified_name(ppmsp[-1].minor.pp0, NULL));
  pp_destructor(62,&ppmsp[-5].minor);
  pp_destructor(44,&ppmsp[-4].minor);
  pp_destructor(63,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2269 "parser.c"
        break;
      case 113:
// 1082 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_func_call(ppmsp[-4].minor.pp0, ppmsp[-1].minor.pp92, ppmsp[-2].minor.pp92);
  pp_destructor(44,&ppmsp[-3].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2278 "parser.c"
        break;
      case 114:
// 1088 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_distinct();
  pp_destructor(28,&ppmsp[0].minor);
}
// 2286 "parser.c"
        break;
      case 122:
// 1126 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_ISNULL, ppmsp[-2].minor.pp92, NULL);
  pp_destructor(21,&ppmsp[-1].minor);
  pp_destructor(64,&ppmsp[0].minor);
}
// 2295 "parser.c"
        break;
      case 123:
// 1130 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_ISNOTNULL, ppmsp[-3].minor.pp92, NULL);
  pp_destructor(21,&ppmsp[-2].minor);
  pp_destructor(23,&ppmsp[-1].minor);
  pp_destructor(64,&ppmsp[0].minor);
}
// 2305 "parser.c"
        break;
      case 124:
// 1134 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_BETWEEN, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(2,&ppmsp[-1].minor);
}
// 2313 "parser.c"
        break;
      case 125:
// 1138 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_NOT, NULL, ppmsp[0].minor.pp92);
  pp_destructor(23,&ppmsp[-1].minor);
}
// 2321 "parser.c"
        break;
      case 126:
// 1142 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_BITWISE_NOT, NULL, ppmsp[0].minor.pp92);
  pp_destructor(24,&ppmsp[-1].minor);
}
// 2329 "parser.c"
        break;
      case 127:
// 1146 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_ENCLOSED, ppmsp[-1].minor.pp92, NULL);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2338 "parser.c"
        break;
      case 130:
// 1158 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_literal_zval(PHQL_T_STRING, ppmsp[0].minor.pp0);
}
// 2345 "parser.c"
        break;
      case 131:
// 1162 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_literal_zval(PHQL_T_DOUBLE, ppmsp[0].minor.pp0);
}
// 2352 "parser.c"
        break;
      case 132:
// 1166 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_literal_zval(PHQL_T_NULL, NULL);
  pp_destructor(64,&ppmsp[0].minor);
}
// 2360 "parser.c"
        break;
      case 133:
// 1170 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_literal_zval(PHQL_T_TRUE, NULL);
  pp_destructor(67,&ppmsp[0].minor);
}
// 2368 "parser.c"
        break;
      case 134:
// 1174 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_literal_zval(PHQL_T_FALSE, NULL);
  pp_destructor(68,&ppmsp[0].minor);
}
// 2376 "parser.c"
        break;
      case 137:
// 1188 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_qualified_name(ppmsp[-4].minor.pp0, ppmsp[-2].minor.pp0, ppmsp[0].minor.pp0);
  pp_destructor(69,&ppmsp[-3].minor);
  pp_destructor(31,&ppmsp[-1].minor);
}
// 2385 "parser.c"
        break;
      case 138:
// 1192 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_qualified_name(ppmsp[-2].minor.pp0, NULL, ppmsp[0].minor.pp0);
  pp_destructor(69,&ppmsp[-1].minor);
}
// 2393 "parser.c"
        break;
      case 139:
// 1196 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_qualified_name(NULL, ppmsp[-2].minor.pp0, ppmsp[0].minor.pp0);
  pp_destructor(31,&ppmsp[-1].minor);
}
// 2401 "parser.c"
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
#define TOKEN (ppminor.pp0)
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

// 2510 "parser.c"
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
			case PHQL_T_COLON:
				phql_(phql_parser, PHQL_COLON, NULL, parser_status);
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
			default:
				parser_status->status = PHQL_PARSING_FAILED;
				error_length = sizeof(char) * 32;
				error = emalloc(error_length);
				snprintf(error, error_length, "Scanner: Unknown opcode %c", token.opcode);
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
