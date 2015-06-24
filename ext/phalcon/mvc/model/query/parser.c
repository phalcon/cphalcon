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
#define PPNOCODE 131
#define PPACTIONTYPE unsigned short int
#define phql_TOKENTYPE phql_parser_token*
typedef union {
  phql_TOKENTYPE pp0;
  zval* pp228;
  int pp261;
} PPMINORTYPE;
#define PPSTACKDEPTH 100
#define phql_ARG_SDECL phql_parser_status *status;
#define phql_ARG_PDECL ,phql_parser_status *status
#define phql_ARG_FETCH phql_parser_status *status = pppParser->status
#define phql_ARG_STORE pppParser->status = status
#define PPNSTATE 273
#define PPNRULE 151
#define PPERRORSYMBOL 78
#define PPERRSYMDT pp261
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
 /*     0 */   100,  106,   54,   56,   58,   60,   62,   64,   44,   46,
 /*    10 */    66,   71,   48,   50,   52,   40,   38,   42,   36,   33,
 /*    20 */   102,   73,   68,   36,   33,  102,   73,   68,  115,  200,
 /*    30 */   165,  198,    6,  100,  106,   54,   56,   58,   60,   62,
 /*    40 */    64,   44,   46,   66,   71,   48,   50,   52,   40,   38,
 /*    50 */    42,   36,   33,  102,   73,   68,  100,  106,   54,   56,
 /*    60 */    58,   60,   62,   64,   44,   46,   66,   71,   48,   50,
 /*    70 */    52,   40,   38,   42,   36,   33,  102,   73,   68,   54,
 /*    80 */    56,   58,   60,   62,   64,   44,   46,   66,   71,   48,
 /*    90 */    50,   52,   40,   38,   42,   36,   33,  102,   73,   68,
 /*   100 */    86,  134,   84,  166,  102,   73,   68,   31,   32,  100,
 /*   110 */   106,   54,   56,   58,   60,   62,   64,   44,   46,   66,
 /*   120 */    71,   48,   50,   52,   40,   38,   42,   36,   33,  102,
 /*   130 */    73,   68,  100,  106,   54,   56,   58,   60,   62,   64,
 /*   140 */    44,   46,   66,   71,   48,   50,   52,   40,   38,   42,
 /*   150 */    36,   33,  102,   73,   68,   40,   38,   42,   36,   33,
 /*   160 */   102,   73,   68,  120,  144,  172,  188,  174,  176,   11,
 /*   170 */   180,  184,  132,  134,  126,  166,  100,  106,   54,   56,
 /*   180 */    58,   60,   62,   64,   44,   46,   66,   71,   48,   50,
 /*   190 */    52,   40,   38,   42,   36,   33,  102,   73,   68,   44,
 /*   200 */    46,   66,   71,   48,   50,   52,   40,   38,   42,   36,
 /*   210 */    33,  102,   73,   68,   19,   20,   21,   22,  241,  355,
 /*   220 */   110,  250,  100,  106,   54,   56,   58,   60,   62,   64,
 /*   230 */    44,   46,   66,   71,   48,   50,   52,   40,   38,   42,
 /*   240 */    36,   33,  102,   73,   68,  100,  106,   54,   56,   58,
 /*   250 */    60,   62,   64,   44,   46,   66,   71,   48,   50,   52,
 /*   260 */    40,   38,   42,   36,   33,  102,   73,   68,  148,   68,
 /*   270 */   231,   34,  232,  240,  149,  151,  254,   75,   24,   80,
 /*   280 */   238,  139,   87,   91,  189,   93,   94,  179,   12,  245,
 /*   290 */   177,  136,  239,  148,   81,  108,   34,  236,  153,  149,
 /*   300 */   151,  142,  172,  188,  174,  176,  139,  180,  184,  138,
 /*   310 */   154,  155,  161,  162,  113,  117,  123,  235,  129,  153,
 /*   320 */   108,  400,   17,  158,  156,  157,  159,  160,  163,  119,
 /*   330 */   138,   69,  208,  147,   13,  154,  155,  161,  162,  113,
 /*   340 */   117,  123,  210,  129,  259,  266,  262,  153,  158,  156,
 /*   350 */   157,  159,  160,  163,  148,   23,  183,   34,  138,  181,
 /*   360 */   149,  151,  142,   92,   93,   94,   26,  139,   48,   50,
 /*   370 */    52,   40,   38,   42,   36,   33,  102,   73,   68,  193,
 /*   380 */   153,  108,   34,  247,  275,  149,  151,  228,  145,  265,
 /*   390 */    74,  138,  194,  143,  164,   76,  154,  155,  161,  162,
 /*   400 */   113,  117,  123,  242,  129,  153,  108,  153,  264,  158,
 /*   410 */   156,  157,  159,  160,  163,   82,  138,  171,  138,  169,
 /*   420 */    83,  154,  155,  161,  162,  113,  117,  123,   28,  129,
 /*   430 */   192,  197,   87,   30,  158,  156,  157,  159,  160,  163,
 /*   440 */   219,  236,   34,  261,  262,  149,  151,  238,   75,  153,
 /*   450 */   225,  153,  139,   88,   27,  217,  234,  170,  153,  239,
 /*   460 */   138,  246,  138,  131,  168,  153,  108,   34,  153,  138,
 /*   470 */   149,  151,   72,  222,  226,   47,  138,  139,  173,  138,
 /*   480 */    95,  154,  155,  161,  162,  113,  117,  123,  301,  129,
 /*   490 */   153,  108,   87,  153,  158,  156,  157,  159,  160,  163,
 /*   500 */   272,  138,   89,  196,  138,   83,  154,  155,  161,  162,
 /*   510 */   113,  117,  123,  175,  129,  140,   90,   87,  302,  158,
 /*   520 */   156,  157,  159,  160,  163,  146,   66,   71,   48,   50,
 /*   530 */    52,   40,   38,   42,   36,   33,  102,   73,   68,   77,
 /*   540 */   202,  203,  201,  197,  104,  399,  425,    1,    2,    3,
 /*   550 */     4,    5,    6,  214,   14,  111,  146,    6,  178,    6,
 /*   560 */    75,  153,  187,  206,  195,  185,  146,    6,  303,  142,
 /*   570 */    49,  109,  138,  276,   30,  229,  205,  140,  251,  142,
 /*   580 */   256,   79,  270,   85,  267,  190,  213,  153,  153,  153,
 /*   590 */    83,  209,  153,  103,  225,  212,   29,  153,  138,  138,
 /*   600 */   138,  164,   87,  138,  238,  204,   43,   55,  138,  153,
 /*   610 */   107,  164,  153,  304,  274,  182,  237,  277,  224,   99,
 /*   620 */   138,  305,  153,  138,  153,  153,   51,   59,  153,   45,
 /*   630 */   306,  186,  125,  138,   39,  138,  138,  153,  191,  138,
 /*   640 */    78,   65,   16,  273,  153,  153,   35,  153,  138,  152,
 /*   650 */   153,   63,  153,   61,  307,  138,  138,   89,  138,  153,
 /*   660 */   308,  138,  309,  138,  153,   53,   90,  153,  216,  153,
 /*   670 */   138,  153,   67,   96,  257,  138,  199,  150,  138,   83,
 /*   680 */   138,   98,  138,  153,   97,   41,  153,   70,   18,   57,
 /*   690 */   153,   87,  137,  101,  138,  153,  207,  138,  211,  130,
 /*   700 */   105,  138,  167,  153,  227,  153,  138,  153,  135,   37,
 /*   710 */   153,  153,  215,    7,  138,  221,  138,  153,  138,  223,
 /*   720 */   153,  138,  138,  112,  220,  114,  153,  153,  138,   75,
 /*   730 */   230,  138,  116,  233,  312,    8,  118,  138,  138,  249,
 /*   740 */   243,  121,  244,  313,  122,  218,  124,  248,  252,  320,
 /*   750 */   253,  255,  354,    9,  258,  127,  260,  128,  263,  268,
 /*   760 */    25,  269,  326,  271,  133,   10,  283,  141,  283,  283,
 /*   770 */    15,
};
static PPCODETYPE pp_lookahead[] = {
 /*     0 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    10 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*    20 */    21,   22,   23,   19,   20,   21,   22,   23,   81,   30,
 /*    30 */    28,   32,   85,    1,    2,    3,    4,    5,    6,    7,
 /*    40 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*    50 */    18,   19,   20,   21,   22,   23,    1,    2,    3,    4,
 /*    60 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*    70 */    15,   16,   17,   18,   19,   20,   21,   22,   23,    3,
 /*    80 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*    90 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   100 */    30,   69,   32,   71,   21,   22,   23,   52,   53,    1,
 /*   110 */     2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   120 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   130 */    22,   23,    1,    2,    3,    4,    5,    6,    7,    8,
 /*   140 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   150 */    19,   20,   21,   22,   23,   16,   17,   18,   19,   20,
 /*   160 */    21,   22,   23,   32,   45,   33,   34,   35,   36,   90,
 /*   170 */    38,   39,   68,   69,   66,   71,    1,    2,    3,    4,
 /*   180 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   190 */    15,   16,   17,   18,   19,   20,   21,   22,   23,    9,
 /*   200 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   210 */    20,   21,   22,   23,   59,   60,   61,   62,  107,    0,
 /*   220 */    45,  110,    1,    2,    3,    4,    5,    6,    7,    8,
 /*   230 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   240 */    19,   20,   21,   22,   23,    1,    2,    3,    4,    5,
 /*   250 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   260 */    16,   17,   18,   19,   20,   21,   22,   23,   17,   23,
 /*   270 */   103,   20,   43,   44,   23,   24,   57,   26,  122,   95,
 /*   280 */    97,   30,  115,   99,  100,  101,  102,   34,   91,  106,
 /*   290 */    37,   70,  109,   17,   25,   44,   20,   25,  115,   23,
 /*   300 */    24,   97,   33,   34,   35,   36,   30,   38,   39,  126,
 /*   310 */    59,   60,   61,   62,   63,   64,   65,   45,   67,  115,
 /*   320 */    44,   45,   25,   72,   73,   74,   75,   76,   77,   97,
 /*   330 */   126,   11,   12,  129,   56,   59,   60,   61,   62,   63,
 /*   340 */    64,   65,   22,   67,  113,  114,  115,  115,   72,   73,
 /*   350 */    74,   75,   76,   77,   17,   58,   34,   20,  126,   37,
 /*   360 */    23,   24,   97,  100,  101,  102,   51,   30,   13,   14,
 /*   370 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   17,
 /*   380 */   115,   44,   20,   25,    0,   23,   24,   97,  123,   97,
 /*   390 */    44,  126,   30,  128,  129,   92,   59,   60,   61,   62,
 /*   400 */    63,   64,   65,   45,   67,  115,   44,  115,  116,   72,
 /*   410 */    73,   74,   75,   76,   77,   98,  126,   30,  126,   32,
 /*   420 */   103,   59,   60,   61,   62,   63,   64,   65,   25,   67,
 /*   430 */    96,   97,  115,   97,   72,   73,   74,   75,   76,   77,
 /*   440 */    97,   25,   20,  114,  115,   23,   24,   97,   26,  115,
 /*   450 */    97,  115,   30,   30,  118,  119,  106,   30,  115,  109,
 /*   460 */   126,   45,  126,  124,  125,  115,   44,   20,  115,  126,
 /*   470 */    23,   24,   97,  120,  121,   97,  126,   30,   34,  126,
 /*   480 */   103,   59,   60,   61,   62,   63,   64,   65,   30,   67,
 /*   490 */   115,   44,  115,  115,   72,   73,   74,   75,   76,   77,
 /*   500 */    98,  126,   31,   17,  126,  103,   59,   60,   61,   62,
 /*   510 */    63,   64,   65,   34,   67,   44,   30,  115,   30,   72,
 /*   520 */    73,   74,   75,   76,   77,   25,   11,   12,   13,   14,
 /*   530 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   93,
 /*   540 */    28,   29,   96,   97,   23,   45,   79,   80,   81,   82,
 /*   550 */    83,   84,   85,   81,   46,   81,   25,   85,   34,   85,
 /*   560 */    26,  115,   34,   81,   31,   37,   25,   85,   30,   97,
 /*   570 */    97,   97,  126,    0,   97,   41,   45,   44,  111,   97,
 /*   580 */    46,   94,   48,   30,  117,   98,   45,  115,  115,  115,
 /*   590 */   103,   97,  115,   72,   97,  123,  119,  115,  126,  126,
 /*   600 */   126,  129,  115,  126,   97,  123,   97,   97,  126,  115,
 /*   610 */    97,  129,  115,   30,    0,   34,  109,    0,  121,   97,
 /*   620 */   126,   30,  115,  126,  115,  115,   97,   97,  115,   97,
 /*   630 */    30,   34,   97,  126,   97,  126,  126,  115,   25,  126,
 /*   640 */    27,   97,  122,    0,  115,  115,   97,  115,  126,   97,
 /*   650 */   115,   97,  115,   97,   30,  126,  126,   31,  126,  115,
 /*   660 */    30,  126,   30,  126,  115,   97,   30,  115,   97,  115,
 /*   670 */   126,  115,   97,  104,   98,  126,   30,   97,  126,  103,
 /*   680 */   126,   40,  126,  115,  105,   97,  115,   97,  122,   97,
 /*   690 */   115,  115,   97,   97,  126,  115,   45,  126,   44,   97,
 /*   700 */    72,  126,   97,  115,   49,  115,  126,  115,   97,   97,
 /*   710 */   115,  115,   45,   86,  126,   51,  126,  115,  126,   25,
 /*   720 */   115,  126,  126,   45,   54,   44,  115,  115,  126,   26,
 /*   730 */    42,  126,   45,   44,    0,   87,   44,  126,  126,   30,
 /*   740 */    43,   30,   44,    0,   45,   55,   44,  110,   86,    0,
 /*   750 */   112,  122,    0,   88,   47,   30,   25,   45,    3,   86,
 /*   760 */    50,  112,    0,   27,  125,   89,  130,  127,  130,  130,
 /*   770 */    57,
};
#define PP_SHIFT_USE_DFLT (-2)
static short pp_shift_ofst[] = {
 /*     0 */   534,  643,  614,  384,  573,  617,  655,  670,  690,  710,
 /*    10 */   713,  278,   -2,  508,   -2,  155,  297,  155,   -2,   -2,
 /*    20 */    -2,   -2,   -2,  155,   -2,  315,  447,  403,  447,   -2,
 /*    30 */    55,   -2,   -2,  447,  447,   83,  447,   83,  447,    4,
 /*    40 */   447,    4,  447,    4,  447,  515,  447,  515,  447,  139,
 /*    50 */   447,  139,  447,  139,  447,  190,  447,  190,  447,  190,
 /*    60 */   447,  190,  447,  190,  447,  190,  447,  355,  320,  447,
 /*    70 */   246,  447,  355,  346,  251,  512,  362,  613,  423,  269,
 /*    80 */    -2,  423,   -2,   70,  553,   -2,   -2,   -2,  626,  636,
 /*    90 */    -2,  132,   -2,   -2,  423,  387,  641,   -2,  447,  244,
 /*   100 */   447,  244,  521,   -2,  628,   -2,  447,   76,  422,  175,
 /*   110 */    -2,  678,   -2,  681,  703,  687,   -2,  692,  447,  131,
 /*   120 */   711,  699,   -2,  702,  447,  108,  725,  712,   -2,  447,
 /*   130 */    32,  104,   -2,   -2,  447,  221,  447,  244,   -2,  471,
 /*   140 */     2,  276,  244,  119,   -2,  500,  337,   -2,   -2,  447,
 /*   150 */   246,  447,  246,   -2,   -2,   -2,   -2,   -2,   -2,   -2,
 /*   160 */    -2,   -2,   -2,   -2,   -2,   -2,  447,  244,   -2,  427,
 /*   170 */    -2,   -2,  444,  458,  479,  488,  253,  524,  538,  583,
 /*   180 */   322,  581,  591,  600,  528,  597,  624,  630,  632,   -2,
 /*   190 */    -2,  362,   -2,   -2,  533,  486,   -2,   -1,  646,   -2,
 /*   200 */    -2,   -2,   -2,   -2,  531,   -2,  651,   -2,  447,  246,
 /*   210 */   654,  251,  541,   -2,  667,   -2,   83,   -2,  447,  244,
 /*   220 */   664,  447,  694,  447,   -2,  244,   -2,  447,  244,  688,
 /*   230 */   423,  229,  689,  447,  272,  734,  447,   -2,  244,   -2,
 /*   240 */   709,  358,  697,  698,  447,  416,  743,  709,   -2,   -2,
 /*   250 */    -2,  655,  219,  749,  155,  752,  423,  707,  423,  731,
 /*   260 */   423,   -2,  755,  447,   -2,  244,   -2,  655,  219,  762,
 /*   270 */   736,  423,   -2,
};
#define PP_REDUCE_USE_DFLT (-54)
static short pp_reduce_ofst[] = {
 /*     0 */   467,  -54,  -54,  -54,  -54,  -54,  627,  648,  665,  676,
 /*    10 */    79,  197,  -54,  -54,  -54,  520,  -54,  566,  -54,  -54,
 /*    20 */   -54,  -54,  -54,  156,  -54,  -54,  336,  -54,  477,  -54,
 /*    30 */   -54,  -54,  -54,  571,  549,  -54,  612,  -54,  537,  -54,
 /*    40 */   588,  -54,  509,  -54,  532,  -54,  378,  -54,  473,  -54,
 /*    50 */   529,  -54,  568,  -54,  510,  -54,  592,  -54,  530,  -54,
 /*    60 */   556,  -54,  554,  -54,  544,  -54,  575,  -54,  -54,  590,
 /*    70 */   -54,  375,  -54,  -54,  482,  303,  446,  -54,  487,  184,
 /*    80 */   -54,  317,  -54,  -54,  -54,  -54,  -54,  -54,  -54,  -54,
 /*    90 */   -54,  263,  -54,  -54,  377,  569,  579,  -54,  522,  -54,
 /*   100 */   596,  -54,  -54,  -54,  -54,  -54,  513,  -54,  474,  -54,
 /*   110 */   -54,  -54,  -54,  -54,  -53,  -54,  -54,  -54,  232,  -54,
 /*   120 */   -54,  -54,  -54,  -54,  535,  -54,  -54,  -54,  -54,  602,
 /*   130 */   339,  639,  -54,  -54,  611,  -54,  595,  -54,  -54,  -54,
 /*   140 */   640,  265,  -54,  -54,  -54,  -54,  204,  -54,  -54,  580,
 /*   150 */   -54,  552,  -54,  -54,  -54,  -54,  -54,  -54,  -54,  -54,
 /*   160 */   -54,  -54,  -54,  -54,  -54,  -54,  605,  -54,  -54,  -54,
 /*   170 */   -54,  -54,  -54,  -54,  -54,  -54,  -54,  -54,  -54,  -54,
 /*   180 */   -54,  -54,  -54,  -54,  -54,  -54,  -54,  -54,  -54,  -54,
 /*   190 */   -54,  334,  -54,  -54,  -54,  -54,  -54,  -54,  -54,  -54,
 /*   200 */   -54,  -54,  -54,  -54,  -54,  -54,  -54,  -54,  494,  -54,
 /*   210 */   -54,  472,  -54,  -54,  -54,  -54,  -54,  -54,  343,  -54,
 /*   220 */   -54,  353,  -54,  497,  -54,  -54,  -54,  290,  -54,  -54,
 /*   230 */   167,  -54,  -54,  350,  -54,  -54,  507,  -54,  -54,  -54,
 /*   240 */   111,  -54,  -54,  -54,  183,  -54,  -54,  637,  -54,  -54,
 /*   250 */   -54,  662,  638,  -54,  629,  -54,  576,  -54,  231,  -54,
 /*   260 */   329,  -54,  -54,  292,  -54,  -54,  -54,  673,  649,  -54,
 /*   270 */   -54,  402,  -54,
};
static PPACTIONTYPE pp_default[] = {
 /*     0 */   424,  424,  424,  424,  424,  424,  333,  342,  347,  335,
 /*    10 */   353,  349,  278,  424,  348,  424,  350,  424,  351,  356,
 /*    20 */   357,  358,  359,  424,  352,  424,  424,  334,  424,  336,
 /*    30 */   338,  339,  340,  424,  424,  360,  424,  362,  424,  363,
 /*    40 */   424,  364,  424,  365,  424,  366,  424,  367,  424,  368,
 /*    50 */   424,  369,  424,  370,  424,  371,  424,  372,  424,  373,
 /*    60 */   424,  374,  424,  375,  424,  376,  424,  377,  424,  424,
 /*    70 */   378,  424,  379,  424,  424,  282,  424,  424,  424,  293,
 /*    80 */   279,  424,  290,  330,  424,  328,  329,  331,  423,  424,
 /*    90 */   422,  292,  294,  296,  424,  300,  311,  297,  424,  310,
 /*   100 */   424,  387,  424,  405,  424,  406,  424,  407,  424,  424,
 /*   110 */   410,  424,  383,  424,  424,  424,  386,  424,  424,  424,
 /*   120 */   424,  424,  388,  424,  424,  424,  424,  424,  389,  424,
 /*   130 */   424,  424,  390,  391,  424,  424,  424,  393,  395,  423,
 /*   140 */   398,  424,  404,  424,  396,  424,  424,  401,  403,  424,
 /*   150 */   408,  424,  409,  411,  412,  413,  414,  415,  416,  417,
 /*   160 */   418,  419,  420,  421,  402,  397,  424,  394,  392,  424,
 /*   170 */   298,  299,  424,  424,  424,  424,  424,  424,  424,  424,
 /*   180 */   424,  424,  424,  424,  424,  424,  424,  424,  424,  295,
 /*   190 */   291,  424,  283,  285,  423,  424,  286,  289,  424,  287,
 /*   200 */   288,  284,  280,  281,  424,  381,  424,  384,  424,  380,
 /*   210 */   424,  424,  424,  382,  424,  385,  361,  337,  424,  346,
 /*   220 */   424,  424,  341,  424,  343,  345,  344,  424,  332,  424,
 /*   230 */   424,  424,  424,  424,  424,  424,  424,  314,  316,  315,
 /*   240 */   424,  424,  424,  424,  424,  424,  424,  424,  317,  319,
 /*   250 */   318,  333,  424,  424,  424,  424,  424,  424,  424,  321,
 /*   260 */   424,  322,  424,  424,  324,  325,  323,  333,  424,  424,
 /*   270 */   424,  424,  327,
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
  "HINTEGER",      "NPLACEHOLDER",  "SPLACEHOLDER",  "EXISTS",      
  "CAST",          "CONVERT",       "USING",         "CASE",        
  "END",           "WHEN",          "THEN",          "ELSE",        
  "NULL",          "STRING",        "DOUBLE",        "TRUE",        
  "FALSE",         "BPLACEHOLDER",  "error",         "program",     
  "query_language",  "select_statement",  "insert_statement",  "update_statement",
  "delete_statement",  "select_clause",  "where_clause",  "group_clause",
  "having_clause",  "order_clause",  "select_limit_clause",  "for_update_clause",
  "distinct_all",  "column_list",   "associated_name_list",  "join_list_or_null",
  "column_item",   "expr",          "associated_name",  "join_list",   
  "join_item",     "join_clause",   "join_type",     "aliased_or_qualified_name",
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
 /*  84 */ "integer_or_placeholder ::= HINTEGER",
 /*  85 */ "integer_or_placeholder ::= NPLACEHOLDER",
 /*  86 */ "integer_or_placeholder ::= SPLACEHOLDER",
 /*  87 */ "expr ::= MINUS expr",
 /*  88 */ "expr ::= expr MINUS expr",
 /*  89 */ "expr ::= expr PLUS expr",
 /*  90 */ "expr ::= expr TIMES expr",
 /*  91 */ "expr ::= expr DIVIDE expr",
 /*  92 */ "expr ::= expr MOD expr",
 /*  93 */ "expr ::= expr AND expr",
 /*  94 */ "expr ::= expr OR expr",
 /*  95 */ "expr ::= expr BITWISE_AND expr",
 /*  96 */ "expr ::= expr BITWISE_OR expr",
 /*  97 */ "expr ::= expr BITWISE_XOR expr",
 /*  98 */ "expr ::= expr EQUALS expr",
 /*  99 */ "expr ::= expr NOTEQUALS expr",
 /* 100 */ "expr ::= expr LESS expr",
 /* 101 */ "expr ::= expr GREATER expr",
 /* 102 */ "expr ::= expr GREATEREQUAL expr",
 /* 103 */ "expr ::= expr LESSEQUAL expr",
 /* 104 */ "expr ::= expr LIKE expr",
 /* 105 */ "expr ::= expr NOT LIKE expr",
 /* 106 */ "expr ::= expr ILIKE expr",
 /* 107 */ "expr ::= expr NOT ILIKE expr",
 /* 108 */ "expr ::= expr IN PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 109 */ "expr ::= expr NOT IN PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 110 */ "expr ::= PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 111 */ "expr ::= expr IN PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 112 */ "expr ::= expr NOT IN PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 113 */ "expr ::= EXISTS PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 114 */ "expr ::= expr AGAINST expr",
 /* 115 */ "expr ::= CAST PARENTHESES_OPEN expr AS IDENTIFIER PARENTHESES_CLOSE",
 /* 116 */ "expr ::= CONVERT PARENTHESES_OPEN expr USING IDENTIFIER PARENTHESES_CLOSE",
 /* 117 */ "expr ::= CASE expr when_clauses END",
 /* 118 */ "when_clauses ::= when_clauses when_clause",
 /* 119 */ "when_clauses ::= when_clause",
 /* 120 */ "when_clause ::= WHEN expr THEN expr",
 /* 121 */ "when_clause ::= ELSE expr",
 /* 122 */ "expr ::= function_call",
 /* 123 */ "function_call ::= IDENTIFIER PARENTHESES_OPEN distinct_or_null argument_list_or_null PARENTHESES_CLOSE",
 /* 124 */ "distinct_or_null ::= DISTINCT",
 /* 125 */ "distinct_or_null ::=",
 /* 126 */ "argument_list_or_null ::= argument_list",
 /* 127 */ "argument_list_or_null ::=",
 /* 128 */ "argument_list ::= argument_list COMMA argument_item",
 /* 129 */ "argument_list ::= argument_item",
 /* 130 */ "argument_item ::= TIMES",
 /* 131 */ "argument_item ::= expr",
 /* 132 */ "expr ::= expr IS NULL",
 /* 133 */ "expr ::= expr IS NOT NULL",
 /* 134 */ "expr ::= expr BETWEEN expr",
 /* 135 */ "expr ::= NOT expr",
 /* 136 */ "expr ::= BITWISE_NOT expr",
 /* 137 */ "expr ::= PARENTHESES_OPEN expr PARENTHESES_CLOSE",
 /* 138 */ "expr ::= qualified_name",
 /* 139 */ "expr ::= INTEGER",
 /* 140 */ "expr ::= HINTEGER",
 /* 141 */ "expr ::= STRING",
 /* 142 */ "expr ::= DOUBLE",
 /* 143 */ "expr ::= NULL",
 /* 144 */ "expr ::= TRUE",
 /* 145 */ "expr ::= FALSE",
 /* 146 */ "expr ::= NPLACEHOLDER",
 /* 147 */ "expr ::= SPLACEHOLDER",
 /* 148 */ "expr ::= BPLACEHOLDER",
 /* 149 */ "qualified_name ::= IDENTIFIER DOT IDENTIFIER",
 /* 150 */ "qualified_name ::= IDENTIFIER",
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
// 554 "parser.lemon"
{
	if ((pppminor->pp0)) {
		if ((pppminor->pp0)->free_flag) {
			efree((pppminor->pp0)->token);
		}
		efree((pppminor->pp0));
	}
}
// 1244 "parser.c"
      break;
    case 80:
    case 81:
    case 82:
    case 83:
    case 84:
    case 85:
    case 93:
    case 94:
    case 96:
    case 97:
    case 98:
    case 99:
    case 100:
    case 101:
    case 102:
    case 103:
    case 107:
    case 108:
    case 110:
    case 111:
    case 113:
    case 114:
    case 115:
    case 117:
    case 118:
    case 119:
    case 120:
    case 121:
    case 123:
    case 126:
    case 129:
// 567 "parser.lemon"
{ zval_ptr_dtor(&(pppminor->pp228)); }
// 1279 "parser.c"
      break;
    case 86:
    case 87:
    case 88:
    case 89:
    case 90:
    case 91:
    case 92:
    case 104:
    case 105:
    case 112:
    case 127:
    case 128:
// 855 "parser.lemon"
{ zephir_safe_zval_ptr_dtor((pppminor->pp228)); }
// 1295 "parser.c"
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
  { 79, 1 },
  { 80, 1 },
  { 80, 1 },
  { 80, 1 },
  { 80, 1 },
  { 81, 7 },
  { 85, 6 },
  { 92, 1 },
  { 92, 1 },
  { 92, 0 },
  { 93, 3 },
  { 93, 1 },
  { 96, 1 },
  { 96, 3 },
  { 96, 3 },
  { 96, 2 },
  { 96, 1 },
  { 94, 3 },
  { 94, 1 },
  { 95, 1 },
  { 95, 0 },
  { 99, 2 },
  { 99, 1 },
  { 100, 1 },
  { 101, 4 },
  { 104, 2 },
  { 104, 1 },
  { 104, 0 },
  { 102, 2 },
  { 102, 2 },
  { 102, 3 },
  { 102, 2 },
  { 102, 3 },
  { 102, 2 },
  { 102, 3 },
  { 102, 2 },
  { 102, 1 },
  { 105, 2 },
  { 105, 0 },
  { 82, 7 },
  { 82, 10 },
  { 106, 3 },
  { 106, 1 },
  { 109, 1 },
  { 107, 3 },
  { 107, 1 },
  { 110, 1 },
  { 83, 3 },
  { 111, 4 },
  { 113, 3 },
  { 113, 1 },
  { 114, 3 },
  { 116, 1 },
  { 84, 3 },
  { 117, 3 },
  { 98, 3 },
  { 98, 2 },
  { 98, 1 },
  { 103, 1 },
  { 86, 2 },
  { 86, 0 },
  { 89, 3 },
  { 89, 0 },
  { 118, 3 },
  { 118, 1 },
  { 119, 1 },
  { 119, 2 },
  { 119, 2 },
  { 87, 3 },
  { 87, 0 },
  { 120, 3 },
  { 120, 1 },
  { 121, 1 },
  { 88, 2 },
  { 88, 0 },
  { 91, 2 },
  { 91, 0 },
  { 90, 2 },
  { 90, 4 },
  { 90, 4 },
  { 90, 0 },
  { 112, 2 },
  { 112, 0 },
  { 122, 1 },
  { 122, 1 },
  { 122, 1 },
  { 122, 1 },
  { 97, 2 },
  { 97, 3 },
  { 97, 3 },
  { 97, 3 },
  { 97, 3 },
  { 97, 3 },
  { 97, 3 },
  { 97, 3 },
  { 97, 3 },
  { 97, 3 },
  { 97, 3 },
  { 97, 3 },
  { 97, 3 },
  { 97, 3 },
  { 97, 3 },
  { 97, 3 },
  { 97, 3 },
  { 97, 3 },
  { 97, 4 },
  { 97, 3 },
  { 97, 4 },
  { 97, 5 },
  { 97, 6 },
  { 97, 3 },
  { 97, 5 },
  { 97, 6 },
  { 97, 4 },
  { 97, 3 },
  { 97, 6 },
  { 97, 6 },
  { 97, 4 },
  { 124, 2 },
  { 124, 1 },
  { 125, 4 },
  { 125, 2 },
  { 97, 1 },
  { 126, 5 },
  { 127, 1 },
  { 127, 0 },
  { 128, 1 },
  { 128, 0 },
  { 123, 3 },
  { 123, 1 },
  { 129, 1 },
  { 129, 1 },
  { 97, 3 },
  { 97, 4 },
  { 97, 3 },
  { 97, 2 },
  { 97, 2 },
  { 97, 3 },
  { 97, 1 },
  { 97, 1 },
  { 97, 1 },
  { 97, 1 },
  { 97, 1 },
  { 97, 1 },
  { 97, 1 },
  { 97, 1 },
  { 97, 1 },
  { 97, 1 },
  { 97, 1 },
  { 115, 3 },
  { 115, 1 },
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
	status->ret = ppmsp[0].minor.pp228;
}
// 1663 "parser.c"
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
      case 122:
      case 126:
      case 131:
      case 138:
// 569 "parser.lemon"
{
	ppgotominor.pp228 = ppmsp[0].minor.pp228;
}
// 1688 "parser.c"
        break;
      case 5:
// 587 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_select_statement(ppmsp[-6].minor.pp228, ppmsp[-5].minor.pp228, ppmsp[-2].minor.pp228, ppmsp[-4].minor.pp228, ppmsp[-3].minor.pp228, ppmsp[-1].minor.pp228, ppmsp[0].minor.pp228);
}
// 1695 "parser.c"
        break;
      case 6:
// 593 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_select_clause(ppmsp[-4].minor.pp228, ppmsp[-3].minor.pp228, ppmsp[-1].minor.pp228, ppmsp[0].minor.pp228);
  pp_destructor(26,&ppmsp[-5].minor);
  pp_destructor(27,&ppmsp[-2].minor);
}
// 1704 "parser.c"
        break;
      case 7:
// 599 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_distinct_all(1);
  pp_destructor(28,&ppmsp[0].minor);
}
// 1712 "parser.c"
        break;
      case 8:
// 603 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_distinct_all(0);
  pp_destructor(29,&ppmsp[0].minor);
}
// 1720 "parser.c"
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
      case 125:
      case 127:
// 607 "parser.lemon"
{
	ppgotominor.pp228 = NULL;
}
// 1739 "parser.c"
        break;
      case 10:
      case 17:
      case 41:
      case 44:
      case 49:
      case 63:
      case 70:
      case 128:
// 613 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_zval_list(ppmsp[-2].minor.pp228, ppmsp[0].minor.pp228);
  pp_destructor(25,&ppmsp[-1].minor);
}
// 1754 "parser.c"
        break;
      case 11:
      case 42:
      case 45:
      case 119:
      case 129:
// 617 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_zval_list(ppmsp[0].minor.pp228, NULL);
}
// 1765 "parser.c"
        break;
      case 12:
      case 130:
// 623 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_column_item(PHQL_T_STARALL, NULL, NULL, NULL);
  pp_destructor(17,&ppmsp[0].minor);
}
// 1774 "parser.c"
        break;
      case 13:
// 627 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_column_item(PHQL_T_DOMAINALL, NULL, ppmsp[-2].minor.pp0, NULL);
  pp_destructor(31,&ppmsp[-1].minor);
  pp_destructor(17,&ppmsp[0].minor);
}
// 1783 "parser.c"
        break;
      case 14:
// 631 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_column_item(PHQL_T_EXPR, ppmsp[-2].minor.pp228, NULL, ppmsp[0].minor.pp0);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 1791 "parser.c"
        break;
      case 15:
// 635 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_column_item(PHQL_T_EXPR, ppmsp[-1].minor.pp228, NULL, ppmsp[0].minor.pp0);
}
// 1798 "parser.c"
        break;
      case 16:
// 639 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_column_item(PHQL_T_EXPR, ppmsp[0].minor.pp228, NULL, NULL);
}
// 1805 "parser.c"
        break;
      case 21:
      case 118:
// 663 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_zval_list(ppmsp[-1].minor.pp228, ppmsp[0].minor.pp228);
}
// 1813 "parser.c"
        break;
      case 24:
// 680 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_join_item(ppmsp[-3].minor.pp228, ppmsp[-2].minor.pp228, ppmsp[-1].minor.pp228, ppmsp[0].minor.pp228);
}
// 1820 "parser.c"
        break;
      case 25:
// 686 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_qualified_name(NULL, NULL, ppmsp[0].minor.pp0);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 1828 "parser.c"
        break;
      case 26:
      case 46:
      case 150:
// 690 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_qualified_name(NULL, NULL, ppmsp[0].minor.pp0);
}
// 1837 "parser.c"
        break;
      case 28:
// 700 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_join_type(PHQL_T_INNERJOIN);
  pp_destructor(33,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1846 "parser.c"
        break;
      case 29:
// 704 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_join_type(PHQL_T_CROSSJOIN);
  pp_destructor(35,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1855 "parser.c"
        break;
      case 30:
// 708 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  pp_destructor(36,&ppmsp[-2].minor);
  pp_destructor(37,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1865 "parser.c"
        break;
      case 31:
// 712 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  pp_destructor(36,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1874 "parser.c"
        break;
      case 32:
// 716 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  pp_destructor(38,&ppmsp[-2].minor);
  pp_destructor(37,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1884 "parser.c"
        break;
      case 33:
// 720 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  pp_destructor(38,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1893 "parser.c"
        break;
      case 34:
// 724 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_join_type(PHQL_T_FULLJOIN);
  pp_destructor(39,&ppmsp[-2].minor);
  pp_destructor(37,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1903 "parser.c"
        break;
      case 35:
// 728 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_join_type(PHQL_T_FULLJOIN);
  pp_destructor(39,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1912 "parser.c"
        break;
      case 36:
// 732 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_join_type(PHQL_T_INNERJOIN);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1920 "parser.c"
        break;
      case 37:
// 738 "parser.lemon"
{
	ppgotominor.pp228 = ppmsp[0].minor.pp228;
  pp_destructor(40,&ppmsp[-1].minor);
}
// 1928 "parser.c"
        break;
      case 39:
// 749 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_insert_statement(ppmsp[-4].minor.pp228, NULL, ppmsp[-1].minor.pp228);
  pp_destructor(41,&ppmsp[-6].minor);
  pp_destructor(42,&ppmsp[-5].minor);
  pp_destructor(43,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1940 "parser.c"
        break;
      case 40:
// 753 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_insert_statement(ppmsp[-7].minor.pp228, ppmsp[-5].minor.pp228, ppmsp[-1].minor.pp228);
  pp_destructor(41,&ppmsp[-9].minor);
  pp_destructor(42,&ppmsp[-8].minor);
  pp_destructor(44,&ppmsp[-6].minor);
  pp_destructor(45,&ppmsp[-4].minor);
  pp_destructor(43,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1954 "parser.c"
        break;
      case 47:
// 791 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_update_statement(ppmsp[-2].minor.pp228, ppmsp[-1].minor.pp228, ppmsp[0].minor.pp228);
}
// 1961 "parser.c"
        break;
      case 48:
// 797 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_update_clause(ppmsp[-2].minor.pp228, ppmsp[0].minor.pp228);
  pp_destructor(46,&ppmsp[-3].minor);
  pp_destructor(47,&ppmsp[-1].minor);
}
// 1970 "parser.c"
        break;
      case 51:
// 813 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_update_item(ppmsp[-2].minor.pp228, ppmsp[0].minor.pp228);
  pp_destructor(3,&ppmsp[-1].minor);
}
// 1978 "parser.c"
        break;
      case 53:
// 825 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_delete_statement(ppmsp[-2].minor.pp228, ppmsp[-1].minor.pp228, ppmsp[0].minor.pp228);
}
// 1985 "parser.c"
        break;
      case 54:
// 831 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_delete_clause(ppmsp[0].minor.pp228);
  pp_destructor(48,&ppmsp[-2].minor);
  pp_destructor(27,&ppmsp[-1].minor);
}
// 1994 "parser.c"
        break;
      case 55:
// 837 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_assoc_name(ppmsp[-2].minor.pp228, ppmsp[0].minor.pp0);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 2002 "parser.c"
        break;
      case 56:
// 841 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_assoc_name(ppmsp[-1].minor.pp228, ppmsp[0].minor.pp0);
}
// 2009 "parser.c"
        break;
      case 57:
// 845 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_assoc_name(ppmsp[0].minor.pp228, NULL);
}
// 2016 "parser.c"
        break;
      case 59:
// 857 "parser.lemon"
{
	ppgotominor.pp228 = ppmsp[0].minor.pp228;
  pp_destructor(49,&ppmsp[-1].minor);
}
// 2024 "parser.c"
        break;
      case 61:
// 867 "parser.lemon"
{
	ppgotominor.pp228 = ppmsp[0].minor.pp228;
  pp_destructor(50,&ppmsp[-2].minor);
  pp_destructor(51,&ppmsp[-1].minor);
}
// 2033 "parser.c"
        break;
      case 65:
// 887 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_order_item(ppmsp[0].minor.pp228, 0);
}
// 2040 "parser.c"
        break;
      case 66:
// 891 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_order_item(ppmsp[-1].minor.pp228, PHQL_T_ASC);
  pp_destructor(52,&ppmsp[0].minor);
}
// 2048 "parser.c"
        break;
      case 67:
// 895 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_order_item(ppmsp[-1].minor.pp228, PHQL_T_DESC);
  pp_destructor(53,&ppmsp[0].minor);
}
// 2056 "parser.c"
        break;
      case 68:
// 901 "parser.lemon"
{
	ppgotominor.pp228 = ppmsp[0].minor.pp228;
  pp_destructor(54,&ppmsp[-2].minor);
  pp_destructor(51,&ppmsp[-1].minor);
}
// 2065 "parser.c"
        break;
      case 73:
// 927 "parser.lemon"
{
	ppgotominor.pp228 = ppmsp[0].minor.pp228;
  pp_destructor(55,&ppmsp[-1].minor);
}
// 2073 "parser.c"
        break;
      case 75:
// 937 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_for_update_clause();
  pp_destructor(56,&ppmsp[-1].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 2082 "parser.c"
        break;
      case 77:
      case 81:
// 947 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_limit_clause(ppmsp[0].minor.pp228, NULL);
  pp_destructor(57,&ppmsp[-1].minor);
}
// 2091 "parser.c"
        break;
      case 78:
// 951 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_limit_clause(ppmsp[0].minor.pp228, ppmsp[-2].minor.pp228);
  pp_destructor(57,&ppmsp[-3].minor);
  pp_destructor(25,&ppmsp[-1].minor);
}
// 2100 "parser.c"
        break;
      case 79:
// 955 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_limit_clause(ppmsp[-2].minor.pp228, ppmsp[0].minor.pp228);
  pp_destructor(57,&ppmsp[-3].minor);
  pp_destructor(58,&ppmsp[-1].minor);
}
// 2109 "parser.c"
        break;
      case 83:
      case 139:
// 973 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_literal_zval(PHQL_T_INTEGER, ppmsp[0].minor.pp0);
}
// 2117 "parser.c"
        break;
      case 84:
      case 140:
// 977 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_literal_zval(PHQL_T_HINTEGER, ppmsp[0].minor.pp0);
}
// 2125 "parser.c"
        break;
      case 85:
      case 146:
// 981 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_placeholder_zval(PHQL_T_NPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 2133 "parser.c"
        break;
      case 86:
      case 147:
// 985 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_placeholder_zval(PHQL_T_SPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 2141 "parser.c"
        break;
      case 87:
// 991 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_MINUS, NULL, ppmsp[0].minor.pp228);
  pp_destructor(20,&ppmsp[-1].minor);
}
// 2149 "parser.c"
        break;
      case 88:
// 995 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_SUB, ppmsp[-2].minor.pp228, ppmsp[0].minor.pp228);
  pp_destructor(20,&ppmsp[-1].minor);
}
// 2157 "parser.c"
        break;
      case 89:
// 999 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_ADD, ppmsp[-2].minor.pp228, ppmsp[0].minor.pp228);
  pp_destructor(19,&ppmsp[-1].minor);
}
// 2165 "parser.c"
        break;
      case 90:
// 1003 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_MUL, ppmsp[-2].minor.pp228, ppmsp[0].minor.pp228);
  pp_destructor(17,&ppmsp[-1].minor);
}
// 2173 "parser.c"
        break;
      case 91:
// 1007 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_DIV, ppmsp[-2].minor.pp228, ppmsp[0].minor.pp228);
  pp_destructor(16,&ppmsp[-1].minor);
}
// 2181 "parser.c"
        break;
      case 92:
// 1011 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_MOD, ppmsp[-2].minor.pp228, ppmsp[0].minor.pp228);
  pp_destructor(18,&ppmsp[-1].minor);
}
// 2189 "parser.c"
        break;
      case 93:
// 1015 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_AND, ppmsp[-2].minor.pp228, ppmsp[0].minor.pp228);
  pp_destructor(9,&ppmsp[-1].minor);
}
// 2197 "parser.c"
        break;
      case 94:
// 1019 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_OR, ppmsp[-2].minor.pp228, ppmsp[0].minor.pp228);
  pp_destructor(10,&ppmsp[-1].minor);
}
// 2205 "parser.c"
        break;
      case 95:
// 1023 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_BITWISE_AND, ppmsp[-2].minor.pp228, ppmsp[0].minor.pp228);
  pp_destructor(13,&ppmsp[-1].minor);
}
// 2213 "parser.c"
        break;
      case 96:
// 1027 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_BITWISE_OR, ppmsp[-2].minor.pp228, ppmsp[0].minor.pp228);
  pp_destructor(14,&ppmsp[-1].minor);
}
// 2221 "parser.c"
        break;
      case 97:
// 1031 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_BITWISE_XOR, ppmsp[-2].minor.pp228, ppmsp[0].minor.pp228);
  pp_destructor(15,&ppmsp[-1].minor);
}
// 2229 "parser.c"
        break;
      case 98:
// 1035 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_EQUALS, ppmsp[-2].minor.pp228, ppmsp[0].minor.pp228);
  pp_destructor(3,&ppmsp[-1].minor);
}
// 2237 "parser.c"
        break;
      case 99:
// 1039 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_NOTEQUALS, ppmsp[-2].minor.pp228, ppmsp[0].minor.pp228);
  pp_destructor(4,&ppmsp[-1].minor);
}
// 2245 "parser.c"
        break;
      case 100:
// 1043 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_LESS, ppmsp[-2].minor.pp228, ppmsp[0].minor.pp228);
  pp_destructor(5,&ppmsp[-1].minor);
}
// 2253 "parser.c"
        break;
      case 101:
// 1047 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_GREATER, ppmsp[-2].minor.pp228, ppmsp[0].minor.pp228);
  pp_destructor(6,&ppmsp[-1].minor);
}
// 2261 "parser.c"
        break;
      case 102:
// 1051 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_GREATEREQUAL, ppmsp[-2].minor.pp228, ppmsp[0].minor.pp228);
  pp_destructor(7,&ppmsp[-1].minor);
}
// 2269 "parser.c"
        break;
      case 103:
// 1055 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_LESSEQUAL, ppmsp[-2].minor.pp228, ppmsp[0].minor.pp228);
  pp_destructor(8,&ppmsp[-1].minor);
}
// 2277 "parser.c"
        break;
      case 104:
// 1059 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_LIKE, ppmsp[-2].minor.pp228, ppmsp[0].minor.pp228);
  pp_destructor(11,&ppmsp[-1].minor);
}
// 2285 "parser.c"
        break;
      case 105:
// 1063 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_NLIKE, ppmsp[-3].minor.pp228, ppmsp[0].minor.pp228);
  pp_destructor(23,&ppmsp[-2].minor);
  pp_destructor(11,&ppmsp[-1].minor);
}
// 2294 "parser.c"
        break;
      case 106:
// 1067 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_ILIKE, ppmsp[-2].minor.pp228, ppmsp[0].minor.pp228);
  pp_destructor(12,&ppmsp[-1].minor);
}
// 2302 "parser.c"
        break;
      case 107:
// 1071 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_NILIKE, ppmsp[-3].minor.pp228, ppmsp[0].minor.pp228);
  pp_destructor(23,&ppmsp[-2].minor);
  pp_destructor(12,&ppmsp[-1].minor);
}
// 2311 "parser.c"
        break;
      case 108:
      case 111:
// 1075 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_IN, ppmsp[-4].minor.pp228, ppmsp[-1].minor.pp228);
  pp_destructor(22,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2322 "parser.c"
        break;
      case 109:
      case 112:
// 1079 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_NOTIN, ppmsp[-5].minor.pp228, ppmsp[-1].minor.pp228);
  pp_destructor(23,&ppmsp[-4].minor);
  pp_destructor(22,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2334 "parser.c"
        break;
      case 110:
// 1083 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_SUBQUERY, ppmsp[-1].minor.pp228, NULL);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2343 "parser.c"
        break;
      case 113:
// 1095 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_EXISTS, NULL, ppmsp[-1].minor.pp228);
  pp_destructor(63,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2353 "parser.c"
        break;
      case 114:
// 1099 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_AGAINST, ppmsp[-2].minor.pp228, ppmsp[0].minor.pp228);
  pp_destructor(1,&ppmsp[-1].minor);
}
// 2361 "parser.c"
        break;
      case 115:
// 1103 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_CAST, ppmsp[-3].minor.pp228, phql_ret_raw_qualified_name(ppmsp[-1].minor.pp0, NULL));
  pp_destructor(64,&ppmsp[-5].minor);
  pp_destructor(44,&ppmsp[-4].minor);
  pp_destructor(32,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2372 "parser.c"
        break;
      case 116:
// 1107 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_CONVERT, ppmsp[-3].minor.pp228, phql_ret_raw_qualified_name(ppmsp[-1].minor.pp0, NULL));
  pp_destructor(65,&ppmsp[-5].minor);
  pp_destructor(44,&ppmsp[-4].minor);
  pp_destructor(66,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2383 "parser.c"
        break;
      case 117:
// 1111 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_CASE, ppmsp[-2].minor.pp228, ppmsp[-1].minor.pp228);
  pp_destructor(67,&ppmsp[-3].minor);
  pp_destructor(68,&ppmsp[0].minor);
}
// 2392 "parser.c"
        break;
      case 120:
// 1123 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_WHEN, ppmsp[-2].minor.pp228, ppmsp[0].minor.pp228);
  pp_destructor(69,&ppmsp[-3].minor);
  pp_destructor(70,&ppmsp[-1].minor);
}
// 2401 "parser.c"
        break;
      case 121:
// 1127 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_ELSE, ppmsp[0].minor.pp228, NULL);
  pp_destructor(71,&ppmsp[-1].minor);
}
// 2409 "parser.c"
        break;
      case 123:
// 1137 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_func_call(ppmsp[-4].minor.pp0, ppmsp[-1].minor.pp228, ppmsp[-2].minor.pp228);
  pp_destructor(44,&ppmsp[-3].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2418 "parser.c"
        break;
      case 124:
// 1143 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_distinct();
  pp_destructor(28,&ppmsp[0].minor);
}
// 2426 "parser.c"
        break;
      case 132:
// 1181 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_ISNULL, ppmsp[-2].minor.pp228, NULL);
  pp_destructor(21,&ppmsp[-1].minor);
  pp_destructor(72,&ppmsp[0].minor);
}
// 2435 "parser.c"
        break;
      case 133:
// 1185 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_ISNOTNULL, ppmsp[-3].minor.pp228, NULL);
  pp_destructor(21,&ppmsp[-2].minor);
  pp_destructor(23,&ppmsp[-1].minor);
  pp_destructor(72,&ppmsp[0].minor);
}
// 2445 "parser.c"
        break;
      case 134:
// 1189 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_BETWEEN, ppmsp[-2].minor.pp228, ppmsp[0].minor.pp228);
  pp_destructor(2,&ppmsp[-1].minor);
}
// 2453 "parser.c"
        break;
      case 135:
// 1193 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_NOT, NULL, ppmsp[0].minor.pp228);
  pp_destructor(23,&ppmsp[-1].minor);
}
// 2461 "parser.c"
        break;
      case 136:
// 1197 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_BITWISE_NOT, NULL, ppmsp[0].minor.pp228);
  pp_destructor(24,&ppmsp[-1].minor);
}
// 2469 "parser.c"
        break;
      case 137:
// 1201 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_expr(PHQL_T_ENCLOSED, ppmsp[-1].minor.pp228, NULL);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2478 "parser.c"
        break;
      case 141:
// 1217 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_literal_zval(PHQL_T_STRING, ppmsp[0].minor.pp0);
}
// 2485 "parser.c"
        break;
      case 142:
// 1221 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_literal_zval(PHQL_T_DOUBLE, ppmsp[0].minor.pp0);
}
// 2492 "parser.c"
        break;
      case 143:
// 1225 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_literal_zval(PHQL_T_NULL, NULL);
  pp_destructor(72,&ppmsp[0].minor);
}
// 2500 "parser.c"
        break;
      case 144:
// 1229 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_literal_zval(PHQL_T_TRUE, NULL);
  pp_destructor(75,&ppmsp[0].minor);
}
// 2508 "parser.c"
        break;
      case 145:
// 1233 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_literal_zval(PHQL_T_FALSE, NULL);
  pp_destructor(76,&ppmsp[0].minor);
}
// 2516 "parser.c"
        break;
      case 148:
// 1248 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_placeholder_zval(PHQL_T_BPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 2523 "parser.c"
        break;
      case 149:
// 1254 "parser.lemon"
{
	ppgotominor.pp228 = phql_ret_qualified_name(NULL, ppmsp[-2].minor.pp0, ppmsp[0].minor.pp0);
  pp_destructor(31,&ppmsp[-1].minor);
}
// 2531 "parser.c"
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

// 2640 "parser.c"
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
