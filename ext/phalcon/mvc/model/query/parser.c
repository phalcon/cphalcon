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
#define PPNSTATE 249
#define PPNRULE 139
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
 /*     0 */    72,   78,   50,   52,   54,   56,   58,   60,   40,   42,
 /*    10 */    62,   67,   44,   46,   48,   36,   34,   38,   32,   29,
 /*    20 */    74,   69,   64,   64,   72,   78,   50,   52,   54,   56,
 /*    30 */    58,   60,   40,   42,   62,   67,   44,   46,   48,   36,
 /*    40 */    34,   38,   32,   29,   74,   69,   64,   74,   69,   64,
 /*    50 */   167,   27,   28,  201,  192,  199,  150,   72,   78,   50,
 /*    60 */    52,   54,   56,   58,   60,   40,   42,   62,   67,   44,
 /*    70 */    46,   48,   36,   34,   38,   32,   29,   74,   69,   64,
 /*    80 */    36,   34,   38,   32,   29,   74,   69,   64,   83,   77,
 /*    90 */    72,   78,   50,   52,   54,   56,   58,   60,   40,   42,
 /*   100 */    62,   67,   44,   46,   48,   36,   34,   38,   32,   29,
 /*   110 */    74,   69,   64,   50,   52,   54,   56,   58,   60,   40,
 /*   120 */    42,   62,   67,   44,   46,   48,   36,   34,   38,   32,
 /*   130 */    29,   74,   69,   64,  108,  168,   72,   78,   50,   52,
 /*   140 */    54,   56,   58,   60,   40,   42,   62,   67,   44,   46,
 /*   150 */    48,   36,   34,   38,   32,   29,   74,   69,   64,   72,
 /*   160 */    78,   50,   52,   54,   56,   58,   60,   40,   42,   62,
 /*   170 */    67,   44,   46,   48,   36,   34,   38,   32,   29,   74,
 /*   180 */    69,   64,  101,  217,  196,   30,  226,   21,  102,  104,
 /*   190 */    16,   17,   18,  101,  153,   93,   30,   94,   89,  102,
 /*   200 */   104,   79,  173,  189,  175,  177,   93,  181,  185,  106,
 /*   210 */   364,  173,  189,  175,  177,  188,  181,  185,  186,  109,
 /*   220 */   106,  324,  120,  110,  116,  117,   80,   86,   92,  113,
 /*   230 */   111,  112,  114,  115,  110,  116,  117,   80,   86,  166,
 /*   240 */   113,  111,  112,  114,  115,  194,   14,   71,   30,   65,
 /*   250 */   128,  102,  104,   32,   29,   74,   69,   64,  195,   30,
 /*   260 */   130,   10,  102,  104,  124,  109,  235,  242,  238,   93,
 /*   270 */   171,   99,  106,   98,   92,  152,   96,  118,   19,  161,
 /*   280 */   190,  163,  164,  106,  237,  238,  110,  116,  117,   80,
 /*   290 */    86,  133,  113,  111,  112,  114,  115,  110,  116,  117,
 /*   300 */    80,   86,  120,  113,  111,  112,  114,  115,   40,   42,
 /*   310 */    62,   67,   44,   46,   48,   36,   34,   38,   32,   29,
 /*   320 */    74,   69,   64,   62,   67,   44,   46,   48,   36,   34,
 /*   330 */    38,   32,   29,   74,   69,   64,   44,   46,   48,   36,
 /*   340 */    34,   38,   32,   29,   74,   69,   64,   26,   76,  124,
 /*   350 */   160,  158,  143,  156,  214,  389,    1,    2,    3,    4,
 /*   360 */     5,    6,   94,  210,   71,  109,  215,  174,   23,  135,
 /*   370 */   109,   81,  109,  207,   92,  140,  144,   71,  176,   92,
 /*   380 */   149,   92,  109,  202,  198,  159,  227,  120,  214,   75,
 /*   390 */   132,   92,  243,  180,  118,  109,  178,  221,  241,  147,
 /*   400 */   215,  329,  109,  126,   92,   26,  109,  118,  165,  151,
 /*   410 */   143,   92,   11,  191,  205,   92,  109,  240,  155,  232,
 /*   420 */   159,  246,   71,  109,  105,   92,  214,   25,  109,   73,
 /*   430 */   159,  254,   92,  179,  142,  193,  198,   92,  213,  277,
 /*   440 */   109,  107,  109,   82,  109,  233,   33,  109,   41,   92,
 /*   450 */   155,   92,  100,   92,  109,  183,   92,  230,   43,  109,
 /*   460 */   278,  109,  159,   92,  109,   35,  109,  279,   92,  146,
 /*   470 */    92,  134,   66,   92,  251,   92,  109,   45,  162,  163,
 /*   480 */   164,  203,  204,  109,   37,   92,   24,  109,   47,  109,
 /*   490 */   109,   59,   92,  327,   49,  109,   92,    9,   92,   92,
 /*   500 */   154,   85,  109,  197,   92,  155,  109,  169,   31,  109,
 /*   510 */    51,   92,  109,  212,  248,   92,  125,  159,   92,  155,
 /*   520 */   172,   92,  170,   63,   68,  109,  109,   53,  109,   39,
 /*   530 */   137,  159,   99,  211,   92,   92,  280,   92,  208,  216,
 /*   540 */    55,  109,  109,   61,  223,  109,  212,  109,  109,   12,
 /*   550 */    92,   92,  127,  103,   92,   57,   92,   92,  109,  129,
 /*   560 */    88,  109,  184,   99,  218,  182,  222,   92,  187,   84,
 /*   570 */    92,  109,  281,  109,  282,   87,  283,  109,  109,  284,
 /*   580 */    92,  285,   92,  363,   90,   91,   92,   92,   13,  119,
 /*   590 */   200,   70,   95,  157,  206,   97,  288,  209,  225,  219,
 /*   600 */    15,  220,  289,  136,  224,  148,  325,  145,  228,  296,
 /*   610 */   231,  229,  328,  252,  234,  236,  131,  250,  239,  253,
 /*   620 */    22,  245,    8,  244,  302,  141,  247,  249,  139,  122,
 /*   630 */   326,  121,  138,  123,  125,  260,   20,    7,
};
static PPCODETYPE pp_lookahead[] = {
 /*     0 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    10 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*    20 */    21,   22,   23,   23,    1,    2,    3,    4,    5,    6,
 /*    30 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*    40 */    17,   18,   19,   20,   21,   22,   23,   21,   22,   23,
 /*    50 */    96,   52,   53,   30,   25,   32,   27,    1,    2,    3,
 /*    60 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*    70 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*    80 */    16,   17,   18,   19,   20,   21,   22,   23,   32,   64,
 /*    90 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*   100 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   110 */    21,   22,   23,    3,    4,    5,    6,    7,    8,    9,
 /*   120 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   130 */    20,   21,   22,   23,   45,   40,    1,    2,    3,    4,
 /*   140 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   150 */    15,   16,   17,   18,   19,   20,   21,   22,   23,    1,
 /*   160 */     2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   170 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   180 */    22,   23,   17,   98,   31,   20,  101,   50,   23,   24,
 /*   190 */    58,   59,   60,   17,   25,   30,   20,   44,   63,   23,
 /*   200 */    24,   88,   33,   34,   35,   36,   30,   38,   39,   44,
 /*   210 */    45,   33,   34,   35,   36,   34,   38,   39,   37,  106,
 /*   220 */    44,    0,   69,   58,   59,   60,   61,   62,  115,   64,
 /*   230 */    65,   66,   67,   68,   58,   59,   60,   61,   62,   95,
 /*   240 */    64,   65,   66,   67,   68,   17,   25,   88,   20,   11,
 /*   250 */    12,   23,   24,   19,   20,   21,   22,   23,   30,   20,
 /*   260 */    22,   81,   23,   24,   31,  106,  104,  105,  106,   30,
 /*   270 */    30,   25,   44,  114,  115,   86,  117,  118,   57,   90,
 /*   280 */    91,   92,   93,   44,  105,  106,   58,   59,   60,   61,
 /*   290 */    62,   45,   64,   65,   66,   67,   68,   58,   59,   60,
 /*   300 */    61,   62,   69,   64,   65,   66,   67,   68,    9,   10,
 /*   310 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   320 */    21,   22,   23,   11,   12,   13,   14,   15,   16,   17,
 /*   330 */    18,   19,   20,   21,   22,   23,   13,   14,   15,   16,
 /*   340 */    17,   18,   19,   20,   21,   22,   23,   88,   23,   31,
 /*   350 */    30,   30,   88,   32,   88,   71,   72,   73,   74,   75,
 /*   360 */    76,   77,   44,   97,   88,  106,  100,   34,  109,  110,
 /*   370 */   106,   44,  106,   94,  115,  111,  112,   88,   34,  115,
 /*   380 */    84,  115,  106,   87,   88,  106,  102,   69,   88,   64,
 /*   390 */   114,  115,  108,   34,  118,  106,   37,   97,   88,   26,
 /*   400 */   100,    0,  106,  114,  115,   88,  106,  118,   94,   85,
 /*   410 */    88,  115,   82,   89,   41,  115,  106,  107,   94,   46,
 /*   420 */   106,   48,   88,  106,   88,  115,   88,  110,  106,   88,
 /*   430 */   106,    0,  115,   34,  112,   87,   88,  115,  100,   30,
 /*   440 */   106,   88,  106,   88,  106,   89,   88,  106,   88,  115,
 /*   450 */    94,  115,  118,  115,  106,   34,  115,   56,   88,  106,
 /*   460 */    30,  106,  106,  115,  106,   88,  106,   30,  115,   88,
 /*   470 */   115,   88,   88,  115,    0,  115,  106,   88,   91,   92,
 /*   480 */    93,   28,   29,  106,   88,  115,   25,  106,   88,  106,
 /*   490 */   106,   88,  115,    0,   88,  106,  115,   80,  115,  115,
 /*   500 */    89,   45,  106,   17,  115,   94,  106,   88,   88,  106,
 /*   510 */    88,  115,  106,   25,   89,  115,   30,  106,  115,   94,
 /*   520 */    30,  115,   32,   88,   88,  106,  106,   88,  106,   88,
 /*   530 */    88,  106,   25,   45,  115,  115,   30,  115,   43,   44,
 /*   540 */    88,  106,  106,   88,   25,  106,   25,  106,  106,   56,
 /*   550 */   115,  115,   45,   88,  115,   88,  115,  115,  106,   88,
 /*   560 */    88,  106,   34,   25,   45,   37,   45,  115,   34,   30,
 /*   570 */   115,  106,   30,  106,   30,   44,   30,  106,  106,   30,
 /*   580 */   115,   30,  115,   45,   30,   45,  115,  115,  113,   28,
 /*   590 */    30,   44,  116,   30,   42,   45,    0,   44,   30,   43,
 /*   600 */   113,   44,    0,   55,  101,   83,    0,   49,   78,    0,
 /*   610 */   113,  103,    0,    0,   47,   25,   44,    0,    3,    0,
 /*   620 */    51,  103,   79,   78,    0,   25,   27,    0,   51,   31,
 /*   630 */     0,   30,   54,   30,   30,  119,  113,   78,
};
#define PP_SHIFT_USE_DFLT (-2)
static short pp_shift_ofst[] = {
 /*     0 */   373,  627,  617,  474,  613,  619,  558,  578,  548,  137,
 /*    10 */   493,  431,  132,  221,  132,  606,   -2,   -2,   -2,  132,
 /*    20 */   630,  569,  239,  461,  239,   -2,   -1,   -2,   -2,  239,
 /*    30 */   239,   26,  239,   26,  239,  234,  239,  234,  239,  234,
 /*    40 */   239,  312,  239,  312,  239,   64,  239,   64,  239,   64,
 /*    50 */   239,  299,  239,  299,  239,  299,  239,  299,  239,  299,
 /*    60 */   239,  299,  239,  323,  238,  239,    0,  239,  323,  547,
 /*    70 */   176,  158,  239,  158,  325,   -2,   25,   -2,  239,  110,
 /*    80 */   327,  239,   56,  539,  456,   -2,  531,  239,  135,  554,
 /*    90 */   540,   -2,   -2,  318,  561,  165,  550,   -2,  538,  176,
 /*   100 */    -2,   -2,  239,    0,  239,    0,  239,   89,   -2,   -2,
 /*   110 */    -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,
 /*   120 */   601,  598,  603,   -2,  604,   -2,  507,   -2,  239,    0,
 /*   130 */   572,  176,  246,   -2,   26,   -2,  239,  158,  577,  239,
 /*   140 */   600,  239,   -2,  158,   -2,  239,  158,  453,  228,   29,
 /*   150 */   320,  169,   -2,  320,   -2,  321,  563,   -2,   -2,   -2,
 /*   160 */   233,  178,   -2,   -2,  320,  490,   95,   -2,  239,  158,
 /*   170 */   240,   -2,   -2,  333,  409,  344,  430,  359,  399,  437,
 /*   180 */   506,  528,  421,  542,  544,  181,  534,  546,  549,  551,
 /*   190 */    -2,   -2,  228,   -2,   -2,  153,  486,   -2,   23,  560,
 /*   200 */    -2,   -2,   -2,   -2,   -2,  552,  320,  495,  553,  239,
 /*   210 */   488,  596,  239,   -2,  158,   -2,  568,  519,  556,  557,
 /*   220 */   239,  521,  602,  568,   -2,   -2,   -2,  558,  401,  609,
 /*   230 */   132,  612,  320,  567,  320,  590,  320,   -2,  615,  239,
 /*   240 */    -2,  158,   -2,  558,  401,  624,  599,  320,   -2,
};
#define PP_REDUCE_USE_DFLT (-47)
static short pp_reduce_ofst[] = {
 /*     0 */   284,  -47,  -47,  -47,  -47,  -47,  559,  543,  417,  180,
 /*    10 */   330,  -47,  475,  -47,  487,  -47,  -47,  -47,  -47,  523,
 /*    20 */   -47,  -47,  259,  -47,  317,  -47,  -47,  -47,  -47,  383,
 /*    30 */   420,  -47,  358,  -47,  377,  -47,  396,  -47,  441,  -47,
 /*    40 */   360,  -47,  370,  -47,  389,  -47,  400,  -47,  406,  -47,
 /*    50 */   422,  -47,  439,  -47,  452,  -47,  467,  -47,  403,  -47,
 /*    60 */   455,  -47,  435,  -47,  -47,  384,  -47,  436,  -47,  -47,
 /*    70 */   289,  -47,  341,  -47,  -47,  -47,  -47,  -47,  113,  -47,
 /*    80 */   -47,  355,  -47,  -47,  -47,  -47,  -47,  472,  -47,  -47,
 /*    90 */   -47,  -47,  -47,  -47,  476,  159,  -47,  -47,  -47,  334,
 /*   100 */   -47,  -47,  465,  -47,  336,  -47,  353,  -47,  -47,  -47,
 /*   110 */   -47,  -47,  -47,  -47,  -47,  -47,  -47,  -47,  -47,  -47,
 /*   120 */   -47,  -47,  -47,  -47,  -47,  -47,  -47,  -47,  471,  -47,
 /*   130 */   -47,  276,  -47,  -47,  -47,  -47,  442,  -47,  -47,  264,
 /*   140 */   -47,  322,  -47,  -47,  -47,  381,  -47,  522,  296,  -47,
 /*   150 */   324,  189,  -47,  411,  -47,  -47,  -47,  -47,  -47,  -47,
 /*   160 */   -47,  387,  -47,  -47,  314,  144,  -46,  -47,  419,  -47,
 /*   170 */   -47,  -47,  -47,  -47,  -47,  -47,  -47,  -47,  -47,  -47,
 /*   180 */   -47,  -47,  -47,  -47,  -47,  -47,  -47,  -47,  -47,  -47,
 /*   190 */   -47,  -47,  348,  -47,  -47,  -47,  -47,  -47,  -47,  -47,
 /*   200 */   -47,  -47,  -47,  -47,  -47,  -47,  279,  -47,  -47,  266,
 /*   210 */   -47,  -47,  338,  -47,  -47,  -47,   85,  -47,  -47,  -47,
 /*   220 */   300,  -47,  -47,  503,  -47,  -47,  -47,  530,  508,  -47,
 /*   230 */   497,  -47,  356,  -47,  162,  -47,  179,  -47,  -47,  310,
 /*   240 */   -47,  -47,  -47,  545,  518,  -47,  -47,  425,  -47,
};
static PPACTIONTYPE pp_default[] = {
 /*     0 */   388,  388,  388,  388,  388,  388,  309,  318,  323,  311,
 /*    10 */   388,  388,  388,  388,  388,  388,  330,  331,  332,  388,
 /*    20 */   388,  388,  388,  310,  388,  312,  314,  315,  316,  388,
 /*    30 */   388,  333,  388,  335,  388,  336,  388,  337,  388,  338,
 /*    40 */   388,  339,  388,  340,  388,  341,  388,  342,  388,  343,
 /*    50 */   388,  344,  388,  345,  388,  346,  388,  347,  388,  348,
 /*    60 */   388,  349,  388,  350,  388,  388,  351,  388,  352,  388,
 /*    70 */   388,  368,  388,  356,  388,  369,  388,  370,  388,  371,
 /*    80 */   388,  388,  388,  388,  388,  357,  388,  388,  388,  388,
 /*    90 */   388,  358,  359,  387,  362,  388,  388,  360,  388,  388,
 /*   100 */   365,  367,  388,  372,  388,  373,  388,  388,  374,  375,
 /*   110 */   376,  377,  378,  379,  380,  381,  382,  383,  366,  361,
 /*   120 */   388,  385,  388,  384,  388,  386,  388,  354,  388,  353,
 /*   130 */   388,  388,  388,  355,  334,  313,  388,  322,  388,  388,
 /*   140 */   317,  388,  319,  321,  320,  388,  308,  258,  388,  388,
 /*   150 */   388,  269,  255,  388,  266,  306,  388,  304,  305,  307,
 /*   160 */   387,  268,  270,  272,  388,  276,  287,  273,  388,  286,
 /*   170 */   388,  274,  275,  388,  388,  388,  388,  388,  388,  388,
 /*   180 */   388,  388,  388,  388,  388,  388,  388,  388,  388,  388,
 /*   190 */   271,  267,  388,  259,  261,  387,  388,  262,  265,  388,
 /*   200 */   263,  264,  260,  256,  257,  388,  388,  388,  388,  388,
 /*   210 */   388,  388,  388,  290,  292,  291,  388,  388,  388,  388,
 /*   220 */   388,  388,  388,  388,  293,  295,  294,  309,  388,  388,
 /*   230 */   388,  388,  388,  388,  388,  297,  388,  298,  388,  388,
 /*   240 */   300,  301,  299,  309,  388,  388,  388,  388,  303,
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
 /* 107 */ "expr ::= expr AGAINST expr",
 /* 108 */ "expr ::= CAST PARENTHESES_OPEN expr AS IDENTIFIER PARENTHESES_CLOSE",
 /* 109 */ "expr ::= CONVERT PARENTHESES_OPEN expr USING IDENTIFIER PARENTHESES_CLOSE",
 /* 110 */ "expr ::= function_call",
 /* 111 */ "function_call ::= IDENTIFIER PARENTHESES_OPEN distinct_or_null argument_list_or_null PARENTHESES_CLOSE",
 /* 112 */ "distinct_or_null ::= DISTINCT",
 /* 113 */ "distinct_or_null ::=",
 /* 114 */ "argument_list_or_null ::= argument_list",
 /* 115 */ "argument_list_or_null ::=",
 /* 116 */ "argument_list ::= argument_list COMMA argument_item",
 /* 117 */ "argument_list ::= argument_item",
 /* 118 */ "argument_item ::= TIMES",
 /* 119 */ "argument_item ::= expr",
 /* 120 */ "expr ::= expr IS NULL",
 /* 121 */ "expr ::= expr IS NOT NULL",
 /* 122 */ "expr ::= expr BETWEEN expr",
 /* 123 */ "expr ::= NOT expr",
 /* 124 */ "expr ::= BITWISE_NOT expr",
 /* 125 */ "expr ::= PARENTHESES_OPEN expr PARENTHESES_CLOSE",
 /* 126 */ "expr ::= qualified_name",
 /* 127 */ "expr ::= INTEGER",
 /* 128 */ "expr ::= STRING",
 /* 129 */ "expr ::= DOUBLE",
 /* 130 */ "expr ::= NULL",
 /* 131 */ "expr ::= TRUE",
 /* 132 */ "expr ::= FALSE",
 /* 133 */ "expr ::= NPLACEHOLDER",
 /* 134 */ "expr ::= SPLACEHOLDER",
 /* 135 */ "qualified_name ::= IDENTIFIER COLON IDENTIFIER DOT IDENTIFIER",
 /* 136 */ "qualified_name ::= IDENTIFIER COLON IDENTIFIER",
 /* 137 */ "qualified_name ::= IDENTIFIER DOT IDENTIFIER",
 /* 138 */ "qualified_name ::= IDENTIFIER",
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
// 1171 "parser.c"
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
// 1206 "parser.c"
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
// 1221 "parser.c"
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
// 1577 "parser.c"
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
      case 110:
      case 114:
      case 119:
      case 126:
// 556 "parser.lemon"
{
	ppgotominor.pp92 = ppmsp[0].minor.pp92;
}
// 1602 "parser.c"
        break;
      case 5:
// 574 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_select_statement(ppmsp[-5].minor.pp92, ppmsp[-4].minor.pp92, ppmsp[-1].minor.pp92, ppmsp[-3].minor.pp92, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
}
// 1609 "parser.c"
        break;
      case 6:
// 580 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_select_clause(ppmsp[-4].minor.pp92, ppmsp[-3].minor.pp92, ppmsp[-1].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(26,&ppmsp[-5].minor);
  pp_destructor(27,&ppmsp[-2].minor);
}
// 1618 "parser.c"
        break;
      case 7:
// 586 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_distinct_all(1);
  pp_destructor(28,&ppmsp[0].minor);
}
// 1626 "parser.c"
        break;
      case 8:
// 590 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_distinct_all(0);
  pp_destructor(29,&ppmsp[0].minor);
}
// 1634 "parser.c"
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
      case 113:
      case 115:
// 594 "parser.lemon"
{
	ppgotominor.pp92 = NULL;
}
// 1652 "parser.c"
        break;
      case 10:
      case 17:
      case 41:
      case 44:
      case 49:
      case 63:
      case 70:
      case 116:
// 600 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_zval_list(ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(25,&ppmsp[-1].minor);
}
// 1667 "parser.c"
        break;
      case 11:
      case 42:
      case 45:
      case 117:
// 604 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_zval_list(ppmsp[0].minor.pp92, NULL);
}
// 1677 "parser.c"
        break;
      case 12:
      case 118:
// 610 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_column_item(PHQL_T_STARALL, NULL, NULL, NULL);
  pp_destructor(17,&ppmsp[0].minor);
}
// 1686 "parser.c"
        break;
      case 13:
// 614 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_column_item(PHQL_T_DOMAINALL, NULL, ppmsp[-2].minor.pp0, NULL);
  pp_destructor(31,&ppmsp[-1].minor);
  pp_destructor(17,&ppmsp[0].minor);
}
// 1695 "parser.c"
        break;
      case 14:
// 618 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_column_item(PHQL_T_EXPR, ppmsp[-2].minor.pp92, NULL, ppmsp[0].minor.pp0);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 1703 "parser.c"
        break;
      case 15:
// 622 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_column_item(PHQL_T_EXPR, ppmsp[-1].minor.pp92, NULL, ppmsp[0].minor.pp0);
}
// 1710 "parser.c"
        break;
      case 16:
// 626 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_column_item(PHQL_T_EXPR, ppmsp[0].minor.pp92, NULL, NULL);
}
// 1717 "parser.c"
        break;
      case 21:
// 650 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_zval_list(ppmsp[-1].minor.pp92, ppmsp[0].minor.pp92);
}
// 1724 "parser.c"
        break;
      case 24:
// 667 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_join_item(ppmsp[-3].minor.pp92, ppmsp[-2].minor.pp92, ppmsp[-1].minor.pp92, ppmsp[0].minor.pp92);
}
// 1731 "parser.c"
        break;
      case 25:
// 673 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_qualified_name(NULL, NULL, ppmsp[0].minor.pp0);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 1739 "parser.c"
        break;
      case 26:
      case 46:
      case 138:
// 677 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_qualified_name(NULL, NULL, ppmsp[0].minor.pp0);
}
// 1748 "parser.c"
        break;
      case 28:
// 687 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_join_type(PHQL_T_INNERJOIN);
  pp_destructor(33,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1757 "parser.c"
        break;
      case 29:
// 691 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_join_type(PHQL_T_CROSSJOIN);
  pp_destructor(35,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1766 "parser.c"
        break;
      case 30:
// 695 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  pp_destructor(36,&ppmsp[-2].minor);
  pp_destructor(37,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1776 "parser.c"
        break;
      case 31:
// 699 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  pp_destructor(36,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1785 "parser.c"
        break;
      case 32:
// 703 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  pp_destructor(38,&ppmsp[-2].minor);
  pp_destructor(37,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1795 "parser.c"
        break;
      case 33:
// 707 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  pp_destructor(38,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1804 "parser.c"
        break;
      case 34:
// 711 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_join_type(PHQL_T_FULLJOIN);
  pp_destructor(39,&ppmsp[-2].minor);
  pp_destructor(37,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1814 "parser.c"
        break;
      case 35:
// 715 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_join_type(PHQL_T_FULLJOIN);
  pp_destructor(39,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1823 "parser.c"
        break;
      case 36:
// 719 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_join_type(PHQL_T_INNERJOIN);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1831 "parser.c"
        break;
      case 37:
// 725 "parser.lemon"
{
	ppgotominor.pp92 = ppmsp[0].minor.pp92;
  pp_destructor(40,&ppmsp[-1].minor);
}
// 1839 "parser.c"
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
// 1851 "parser.c"
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
// 1865 "parser.c"
        break;
      case 47:
// 778 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_update_statement(ppmsp[-2].minor.pp92, ppmsp[-1].minor.pp92, ppmsp[0].minor.pp92);
}
// 1872 "parser.c"
        break;
      case 48:
// 784 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_update_clause(ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(46,&ppmsp[-3].minor);
  pp_destructor(47,&ppmsp[-1].minor);
}
// 1881 "parser.c"
        break;
      case 51:
// 800 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_update_item(ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(3,&ppmsp[-1].minor);
}
// 1889 "parser.c"
        break;
      case 53:
// 812 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_delete_statement(ppmsp[-2].minor.pp92, ppmsp[-1].minor.pp92, ppmsp[0].minor.pp92);
}
// 1896 "parser.c"
        break;
      case 54:
// 818 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_delete_clause(ppmsp[0].minor.pp92);
  pp_destructor(48,&ppmsp[-2].minor);
  pp_destructor(27,&ppmsp[-1].minor);
}
// 1905 "parser.c"
        break;
      case 55:
// 824 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_assoc_name(ppmsp[-2].minor.pp92, ppmsp[0].minor.pp0);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 1913 "parser.c"
        break;
      case 56:
// 828 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_assoc_name(ppmsp[-1].minor.pp92, ppmsp[0].minor.pp0);
}
// 1920 "parser.c"
        break;
      case 57:
// 832 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_assoc_name(ppmsp[0].minor.pp92, NULL);
}
// 1927 "parser.c"
        break;
      case 59:
// 844 "parser.lemon"
{
	ppgotominor.pp92 = ppmsp[0].minor.pp92;
  pp_destructor(49,&ppmsp[-1].minor);
}
// 1935 "parser.c"
        break;
      case 61:
// 854 "parser.lemon"
{
	ppgotominor.pp92 = ppmsp[0].minor.pp92;
  pp_destructor(50,&ppmsp[-2].minor);
  pp_destructor(51,&ppmsp[-1].minor);
}
// 1944 "parser.c"
        break;
      case 65:
// 874 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_order_item(ppmsp[0].minor.pp92, 0);
}
// 1951 "parser.c"
        break;
      case 66:
// 878 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_order_item(ppmsp[-1].minor.pp92, PHQL_T_ASC);
  pp_destructor(52,&ppmsp[0].minor);
}
// 1959 "parser.c"
        break;
      case 67:
// 882 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_order_item(ppmsp[-1].minor.pp92, PHQL_T_DESC);
  pp_destructor(53,&ppmsp[0].minor);
}
// 1967 "parser.c"
        break;
      case 68:
// 888 "parser.lemon"
{
	ppgotominor.pp92 = ppmsp[0].minor.pp92;
  pp_destructor(54,&ppmsp[-2].minor);
  pp_destructor(51,&ppmsp[-1].minor);
}
// 1976 "parser.c"
        break;
      case 73:
// 914 "parser.lemon"
{
	ppgotominor.pp92 = ppmsp[0].minor.pp92;
  pp_destructor(55,&ppmsp[-1].minor);
}
// 1984 "parser.c"
        break;
      case 75:
      case 79:
// 924 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_limit_clause(ppmsp[0].minor.pp92, NULL);
  pp_destructor(56,&ppmsp[-1].minor);
}
// 1993 "parser.c"
        break;
      case 76:
// 928 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_limit_clause(ppmsp[0].minor.pp92, ppmsp[-2].minor.pp92);
  pp_destructor(56,&ppmsp[-3].minor);
  pp_destructor(25,&ppmsp[-1].minor);
}
// 2002 "parser.c"
        break;
      case 77:
// 932 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_limit_clause(ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(56,&ppmsp[-3].minor);
  pp_destructor(57,&ppmsp[-1].minor);
}
// 2011 "parser.c"
        break;
      case 81:
      case 127:
// 950 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_literal_zval(PHQL_T_INTEGER, ppmsp[0].minor.pp0);
}
// 2019 "parser.c"
        break;
      case 82:
      case 133:
// 954 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_placeholder_zval(PHQL_T_NPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 2027 "parser.c"
        break;
      case 83:
      case 134:
// 958 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_placeholder_zval(PHQL_T_SPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 2035 "parser.c"
        break;
      case 84:
// 964 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_MINUS, NULL, ppmsp[0].minor.pp92);
  pp_destructor(20,&ppmsp[-1].minor);
}
// 2043 "parser.c"
        break;
      case 85:
// 968 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_SUB, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(20,&ppmsp[-1].minor);
}
// 2051 "parser.c"
        break;
      case 86:
// 972 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_ADD, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(19,&ppmsp[-1].minor);
}
// 2059 "parser.c"
        break;
      case 87:
// 976 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_MUL, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(17,&ppmsp[-1].minor);
}
// 2067 "parser.c"
        break;
      case 88:
// 980 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_DIV, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(16,&ppmsp[-1].minor);
}
// 2075 "parser.c"
        break;
      case 89:
// 984 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_MOD, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(18,&ppmsp[-1].minor);
}
// 2083 "parser.c"
        break;
      case 90:
// 988 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_AND, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(9,&ppmsp[-1].minor);
}
// 2091 "parser.c"
        break;
      case 91:
// 992 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_OR, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(10,&ppmsp[-1].minor);
}
// 2099 "parser.c"
        break;
      case 92:
// 996 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_BITWISE_AND, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(13,&ppmsp[-1].minor);
}
// 2107 "parser.c"
        break;
      case 93:
// 1000 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_BITWISE_OR, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(14,&ppmsp[-1].minor);
}
// 2115 "parser.c"
        break;
      case 94:
// 1004 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_BITWISE_XOR, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(15,&ppmsp[-1].minor);
}
// 2123 "parser.c"
        break;
      case 95:
// 1008 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_EQUALS, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(3,&ppmsp[-1].minor);
}
// 2131 "parser.c"
        break;
      case 96:
// 1012 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_NOTEQUALS, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(4,&ppmsp[-1].minor);
}
// 2139 "parser.c"
        break;
      case 97:
// 1016 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_LESS, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(5,&ppmsp[-1].minor);
}
// 2147 "parser.c"
        break;
      case 98:
// 1020 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_GREATER, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(6,&ppmsp[-1].minor);
}
// 2155 "parser.c"
        break;
      case 99:
// 1024 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_GREATEREQUAL, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(7,&ppmsp[-1].minor);
}
// 2163 "parser.c"
        break;
      case 100:
// 1028 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_LESSEQUAL, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(8,&ppmsp[-1].minor);
}
// 2171 "parser.c"
        break;
      case 101:
// 1032 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_LIKE, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(11,&ppmsp[-1].minor);
}
// 2179 "parser.c"
        break;
      case 102:
// 1036 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_NLIKE, ppmsp[-3].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(23,&ppmsp[-2].minor);
  pp_destructor(11,&ppmsp[-1].minor);
}
// 2188 "parser.c"
        break;
      case 103:
// 1040 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_ILIKE, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(12,&ppmsp[-1].minor);
}
// 2196 "parser.c"
        break;
      case 104:
// 1044 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_NILIKE, ppmsp[-3].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(23,&ppmsp[-2].minor);
  pp_destructor(12,&ppmsp[-1].minor);
}
// 2205 "parser.c"
        break;
      case 105:
// 1048 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_IN, ppmsp[-4].minor.pp92, ppmsp[-1].minor.pp92);
  pp_destructor(22,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2215 "parser.c"
        break;
      case 106:
// 1052 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_NOTIN, ppmsp[-5].minor.pp92, ppmsp[-1].minor.pp92);
  pp_destructor(23,&ppmsp[-4].minor);
  pp_destructor(22,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2226 "parser.c"
        break;
      case 107:
// 1056 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_AGAINST, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(1,&ppmsp[-1].minor);
}
// 2234 "parser.c"
        break;
      case 108:
// 1060 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_CAST, ppmsp[-3].minor.pp92, phql_ret_raw_qualified_name(ppmsp[-1].minor.pp0, NULL));
  pp_destructor(61,&ppmsp[-5].minor);
  pp_destructor(44,&ppmsp[-4].minor);
  pp_destructor(32,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2245 "parser.c"
        break;
      case 109:
// 1064 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_CONVERT, ppmsp[-3].minor.pp92, phql_ret_raw_qualified_name(ppmsp[-1].minor.pp0, NULL));
  pp_destructor(62,&ppmsp[-5].minor);
  pp_destructor(44,&ppmsp[-4].minor);
  pp_destructor(63,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2256 "parser.c"
        break;
      case 111:
// 1074 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_func_call(ppmsp[-4].minor.pp0, ppmsp[-1].minor.pp92, ppmsp[-2].minor.pp92);
  pp_destructor(44,&ppmsp[-3].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2265 "parser.c"
        break;
      case 112:
// 1080 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_distinct();
  pp_destructor(28,&ppmsp[0].minor);
}
// 2273 "parser.c"
        break;
      case 120:
// 1118 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_ISNULL, ppmsp[-2].minor.pp92, NULL);
  pp_destructor(21,&ppmsp[-1].minor);
  pp_destructor(64,&ppmsp[0].minor);
}
// 2282 "parser.c"
        break;
      case 121:
// 1122 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_ISNOTNULL, ppmsp[-3].minor.pp92, NULL);
  pp_destructor(21,&ppmsp[-2].minor);
  pp_destructor(23,&ppmsp[-1].minor);
  pp_destructor(64,&ppmsp[0].minor);
}
// 2292 "parser.c"
        break;
      case 122:
// 1126 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_BETWEEN, ppmsp[-2].minor.pp92, ppmsp[0].minor.pp92);
  pp_destructor(2,&ppmsp[-1].minor);
}
// 2300 "parser.c"
        break;
      case 123:
// 1130 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_NOT, NULL, ppmsp[0].minor.pp92);
  pp_destructor(23,&ppmsp[-1].minor);
}
// 2308 "parser.c"
        break;
      case 124:
// 1134 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_BITWISE_NOT, NULL, ppmsp[0].minor.pp92);
  pp_destructor(24,&ppmsp[-1].minor);
}
// 2316 "parser.c"
        break;
      case 125:
// 1138 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_expr(PHQL_T_ENCLOSED, ppmsp[-1].minor.pp92, NULL);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2325 "parser.c"
        break;
      case 128:
// 1150 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_literal_zval(PHQL_T_STRING, ppmsp[0].minor.pp0);
}
// 2332 "parser.c"
        break;
      case 129:
// 1154 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_literal_zval(PHQL_T_DOUBLE, ppmsp[0].minor.pp0);
}
// 2339 "parser.c"
        break;
      case 130:
// 1158 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_literal_zval(PHQL_T_NULL, NULL);
  pp_destructor(64,&ppmsp[0].minor);
}
// 2347 "parser.c"
        break;
      case 131:
// 1162 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_literal_zval(PHQL_T_TRUE, NULL);
  pp_destructor(67,&ppmsp[0].minor);
}
// 2355 "parser.c"
        break;
      case 132:
// 1166 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_literal_zval(PHQL_T_FALSE, NULL);
  pp_destructor(68,&ppmsp[0].minor);
}
// 2363 "parser.c"
        break;
      case 135:
// 1180 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_qualified_name(ppmsp[-4].minor.pp0, ppmsp[-2].minor.pp0, ppmsp[0].minor.pp0);
  pp_destructor(69,&ppmsp[-3].minor);
  pp_destructor(31,&ppmsp[-1].minor);
}
// 2372 "parser.c"
        break;
      case 136:
// 1184 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_qualified_name(ppmsp[-2].minor.pp0, NULL, ppmsp[0].minor.pp0);
  pp_destructor(69,&ppmsp[-1].minor);
}
// 2380 "parser.c"
        break;
      case 137:
// 1188 "parser.lemon"
{
	ppgotominor.pp92 = phql_ret_qualified_name(NULL, ppmsp[-2].minor.pp0, ppmsp[0].minor.pp0);
  pp_destructor(31,&ppmsp[-1].minor);
}
// 2388 "parser.c"
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

// 2497 "parser.c"
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
