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

static zval *phql_ret_qualified_name(phql_parser_token *A, phql_parser_token *B, phql_parser_token *C)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

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


// 416 "parser.c"
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
#define YYNOCODE 114
#define YYACTIONTYPE unsigned short int
#define phql_TOKENTYPE phql_parser_token*
typedef union {
  phql_TOKENTYPE yy0;
  zval* yy132;
  int yy227;
} YYMINORTYPE;
#define YYSTACKDEPTH 100
#define phql_ARG_SDECL phql_parser_status *status;
#define phql_ARG_PDECL ,phql_parser_status *status
#define phql_ARG_FETCH phql_parser_status *status = yypParser->status
#define phql_ARG_STORE yypParser->status = status
#define YYNSTATE 263
#define YYNRULE 154
#define YYERRORSYMBOL 69
#define YYERRSYMDT yy227
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
 /*    40 */    36,   34,   38,   32,   29,   74,   69,  263,   64,   18,
 /*    50 */    27,   28,   20,  215,  203,  213,  201,   72,   78,   50,
 /*    60 */    52,   54,   56,   58,   60,   40,   42,   62,   67,   44,
 /*    70 */    46,   48,   36,   34,   38,   32,   29,   74,   69,  264,
 /*    80 */    64,   32,   29,   74,   69,  155,   64,   83,  157,   72,
 /*    90 */    78,   50,   52,   54,   56,   58,   60,   40,   42,   62,
 /*   100 */    67,   44,   46,   48,   36,   34,   38,   32,   29,   74,
 /*   110 */    69,  265,   64,  240,   72,   78,   50,   52,   54,   56,
 /*   120 */    58,   60,   40,   42,   62,   67,   44,   46,   48,   36,
 /*   130 */    34,   38,   32,   29,   74,   69,  244,   64,   44,   46,
 /*   140 */    48,   36,   34,   38,   32,   29,   74,   69,   89,   64,
 /*   150 */    36,   34,   38,   32,   29,   74,   69,  108,   64,   72,
 /*   160 */    78,   50,   52,   54,   56,   58,   60,   40,   42,   62,
 /*   170 */    67,   44,   46,   48,   36,   34,   38,   32,   29,   74,
 /*   180 */    69,  266,   64,   50,   52,   54,   56,   58,   60,   40,
 /*   190 */    42,   62,   67,   44,   46,   48,   36,   34,   38,   32,
 /*   200 */    29,   74,   69,   99,   64,  136,   30,   17,  138,  100,
 /*   210 */   102,  104,  198,   65,  128,   93,  181,  182,  184,  186,
 /*   220 */    99,  190,  194,   30,  130,  267,  100,  102,  104,  106,
 /*   230 */   118,  257,   93,  181,  182,  184,  186,    9,  190,  194,
 /*   240 */     8,   16,  110,  141,   80,   86,  106,  113,  111,  112,
 /*   250 */   114,  115,  116,  117,  259,   26,    7,  149,  151,  110,
 /*   260 */   159,   80,   86,  277,  113,  111,  112,  114,  115,  116,
 /*   270 */   117,  208,  109,  162,   30,   23,  135,  100,  102,  104,
 /*   280 */    92,   71,  152,  209,  154,  158,   30,  217,   97,  100,
 /*   290 */   102,  104,  245,  270,  260,   93,  166,  106,  109,  170,
 /*   300 */   204,  168,  169,  361,   96,  126,   92,  119,   11,  106,
 /*   310 */   110,  179,   80,   86,   13,  113,  111,  112,  114,  115,
 /*   320 */   116,  117,  110,   15,   80,   86,  268,  113,  111,  112,
 /*   330 */   114,  115,  116,  117,   40,   42,   62,   67,   44,   46,
 /*   340 */    48,   36,   34,   38,   32,   29,   74,   69,   10,   64,
 /*   350 */    62,   67,   44,   46,   48,   36,   34,   38,   32,   29,
 /*   360 */    74,   69,   76,   64,  362,   71,  418,    1,    2,    3,
 /*   370 */     4,    5,    6,   19,  160,   21,  167,  168,  169,  142,
 /*   380 */   269,   10,  109,  285,  199,   71,  207,  212,  200,   95,
 /*   390 */    92,  119,  271,  164,  206,  239,  147,  226,   22,   75,
 /*   400 */   179,  256,  109,  163,  109,  222,  216,  212,  227,  132,
 /*   410 */    92,  119,   92,  109,  109,  286,  272,  226,  144,  148,
 /*   420 */   226,   92,   92,   26,  109,  233,   71,  229,  227,   21,
 /*   430 */   238,  225,   92,  142,  109,   10,  147,  109,  254,  360,
 /*   440 */   109,   21,   92,  109,   25,   92,  139,   10,   92,  124,
 /*   450 */    97,   92,   98,  109,  165,  109,  253,  279,  205,  146,
 /*   460 */    24,   92,  200,   92,   21,   21,  127,   12,  134,  139,
 /*   470 */    10,   10,   31,   33,  179,   74,   69,   35,   64,  124,
 /*   480 */   171,  175,   37,   39,   41,  109,   70,  120,   43,  109,
 /*   490 */   109,  275,   94,   92,  109,   45,   14,   92,   92,  109,
 /*   500 */   109,  109,   92,   64,   47,  109,   49,   92,   92,   92,
 /*   510 */    51,   53,  109,   92,  246,   55,   57,  120,  200,   77,
 /*   520 */    92,  109,   59,  109,   81,  211,   61,  109,  109,   92,
 /*   530 */   179,   92,  109,  109,   84,   92,   92,  125,   63,  109,
 /*   540 */    92,   92,   66,  109,   97,   68,   10,   92,   73,   79,
 /*   550 */    87,   92,   82,  288,   88,  109,  220,  228,  101,  109,
 /*   560 */   133,  103,  109,   92,  105,  109,  109,   92,  330,  109,
 /*   570 */    92,  109,  210,   92,   92,  109,  107,   92,  109,   92,
 /*   580 */   129,  109,  140,   92,  339,   94,   92,  161,  178,   92,
 /*   590 */   176,  273,  174,  109,  248,  255,  251,  109,  173,  109,
 /*   600 */   280,   92,   21,  281,  109,   92,  282,   92,   10,  109,
 /*   610 */   120,  262,   92,  224,  187,  200,  160,   92,  188,  219,
 /*   620 */   191,  195,  235,  242,  192,  196,  224,  179,  331,  223,
 /*   630 */   340,  179,  160,  250,  251,  122,   85,   90,  230,  242,
 /*   640 */    91,  121,  234,  123,  125,  131,   10,  137,  274,  278,
 /*   650 */   276,  143,  145,  150,  283,   10,  153,  284,   10,  156,
 /*   660 */   290,   10,  289,  287,  291,  180,  173,  172,  177,  312,
 /*   670 */   183,  313,  314,  185,  315,  316,  189,  221,  218,  193,
 /*   680 */   317,  318,  319,  242,  322,  242,  323,  197,  320,  333,
 /*   690 */   202,  236,  363,  332,  214,  237,  342,  241,  231,  249,
 /*   700 */   341,  232,  252,  261,  258,  269,  269,  269,  269,  269,
 /*   710 */   269,  269,  269,  269,  247,  269,  269,  269,  269,  269,
 /*   720 */   269,  269,  269,  243,
};
static YYCODETYPE yy_lookahead[] = {
 /*     0 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    10 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*    20 */    21,   22,   22,   24,   24,    1,    2,    3,    4,    5,
 /*    30 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*    40 */    16,   17,   18,   19,   20,   21,   22,    0,   24,   78,
 /*    50 */    51,   52,   81,   29,   29,   31,   31,    1,    2,    3,
 /*    60 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*    70 */    14,   15,   16,   17,   18,   19,   20,   21,   22,    0,
 /*    80 */    24,   19,   20,   21,   22,   78,   24,   31,   81,    1,
 /*    90 */     2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   100 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   110 */    22,    0,   24,   77,    1,    2,    3,    4,    5,    6,
 /*   120 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   130 */    17,   18,   19,   20,   21,   22,  100,   24,   13,   14,
 /*   140 */    15,   16,   17,   18,   19,   20,   21,   22,   60,   24,
 /*   150 */    16,   17,   18,   19,   20,   21,   22,   44,   24,    1,
 /*   160 */     2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   170 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   180 */    22,    0,   24,    3,    4,    5,    6,    7,    8,    9,
 /*   190 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   200 */    20,   21,   22,   17,   24,   78,   20,   80,   81,   23,
 /*   210 */    24,   25,   28,   11,   12,   29,   32,   33,   34,   35,
 /*   220 */    17,   37,   38,   20,   22,    0,   23,   24,   25,   43,
 /*   230 */    44,   77,   29,   32,   33,   34,   35,   81,   37,   38,
 /*   240 */    78,   79,   56,   81,   58,   59,   43,   61,   62,   63,
 /*   250 */    64,   65,   66,   67,  100,   86,   77,   78,   79,   56,
 /*   260 */    81,   58,   59,    0,   61,   62,   63,   64,   65,   66,
 /*   270 */    67,   17,  103,   26,   20,  106,  107,   23,   24,   25,
 /*   280 */   111,   86,   78,   29,   80,   81,   20,   40,   28,   23,
 /*   290 */    24,   25,   45,    0,   47,   29,   84,   43,  103,   91,
 /*   300 */    88,   89,   90,    0,   44,  110,  111,  112,   56,   43,
 /*   310 */    56,  103,   58,   59,   56,   61,   62,   63,   64,   65,
 /*   320 */    66,   67,   56,   56,   58,   59,    0,   61,   62,   63,
 /*   330 */    64,   65,   66,   67,    9,   10,   11,   12,   13,   14,
 /*   340 */    15,   16,   17,   18,   19,   20,   21,   22,   55,   24,
 /*   350 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*   360 */    21,   22,   24,   24,    0,   86,   70,   71,   72,   73,
 /*   370 */    74,   75,   76,   81,   48,   49,   88,   89,   90,   53,
 /*   380 */     0,   55,  103,    0,   87,   86,   85,   86,   91,  110,
 /*   390 */   111,  112,    0,   27,   28,   99,   86,   86,   50,   61,
 /*   400 */   103,  105,  103,   82,  103,   94,   85,   86,   97,  110,
 /*   410 */   111,  112,  111,  103,  103,    0,    0,   86,  108,  109,
 /*   420 */    86,  111,  111,   86,  103,   94,   86,   95,   97,   49,
 /*   430 */    98,   97,  111,   53,  103,   55,   86,  103,   86,    0,
 /*   440 */   103,   49,  111,  103,  107,  111,   54,   55,  111,   30,
 /*   450 */    28,  111,  112,  103,   83,  103,  104,    0,   87,  109,
 /*   460 */    28,  111,   91,  111,   49,   49,   44,   28,   86,   54,
 /*   470 */    55,   55,   86,   86,  103,   21,   22,   86,   24,   30,
 /*   480 */    92,   93,   86,   86,   86,  103,   43,   68,   86,  103,
 /*   490 */   103,    0,   43,  111,  103,   86,   57,  111,  111,  103,
 /*   500 */   103,  103,  111,   24,   86,  103,   86,  111,  111,  111,
 /*   510 */    86,   86,  103,  111,   87,   86,   86,   68,   91,   61,
 /*   520 */   111,  103,   86,  103,   43,   17,   86,  103,  103,  111,
 /*   530 */   103,  111,  103,  103,   29,  111,  111,   29,   86,  103,
 /*   540 */   111,  111,   86,  103,   28,   86,   55,  111,   86,   86,
 /*   550 */    43,  111,   86,    0,   86,  103,   42,   43,   86,  103,
 /*   560 */    44,   86,  103,  111,   86,  103,  103,  111,    0,  103,
 /*   570 */   111,  103,   30,  111,  111,  103,   86,  111,  103,  111,
 /*   580 */    86,  103,   86,  111,    0,   43,  111,   86,   29,  111,
 /*   590 */    31,    0,   86,  103,  101,  102,  103,  103,   39,  103,
 /*   600 */     0,  111,   49,    0,  103,  111,    0,  111,   55,  103,
 /*   610 */    68,   87,  111,   28,   32,   91,   48,  111,   36,   91,
 /*   620 */    32,   32,   28,   55,   36,   36,   28,  103,    0,   44,
 /*   630 */     0,  103,   48,  102,  103,   30,   44,   29,   44,   55,
 /*   640 */    44,   29,   44,   29,   29,   43,   55,   81,    0,    0,
 /*   650 */     0,   50,   28,   81,    0,   55,   81,    0,   55,   81,
 /*   660 */     0,   55,    0,    0,    0,   29,   39,   93,   29,   29,
 /*   670 */    32,   29,   29,   32,   29,   29,   32,   43,   41,   32,
 /*   680 */    29,   29,   29,   55,    0,   55,    0,   32,   29,    0,
 /*   690 */    29,   98,    0,    0,   29,   29,    0,  100,   42,   28,
 /*   700 */     0,   43,    3,   27,  100,  113,  113,  113,  113,  113,
 /*   710 */   113,  113,  113,  113,   46,  113,  113,  113,  113,  113,
 /*   720 */   113,  113,  113,   56,
};
#define YY_SHIFT_USE_DFLT (-2)
static short yy_shift_ofst[] = {
 /*     0 */   247,   47,   79,  111,  181,  225,  326,  380,  293,  263,
 /*    10 */   252,  439,  258,  303,  267,  364,  392,  416,  491,  383,
 /*    20 */   457,  348,  266,  432,  266,   -2,   -1,   -2,   -2,  266,
 /*    30 */   266,  454,  266,  454,  266,   62,  266,   62,  266,   62,
 /*    40 */   266,  339,  266,  339,  266,  134,  266,  134,  266,  134,
 /*    50 */   266,  325,  266,  325,  266,  325,  266,  325,  266,  325,
 /*    60 */   266,  325,  266,  125,  202,  266,  479,  266,  125,  443,
 /*    70 */   203,  158,  266,  158,  338,   -2,  458,   -2,  266,  180,
 /*    80 */   481,  266,   56,  505,  592,   -2,  507,  266,   88,  608,
 /*    90 */   596,   -2,   -2,  449,  186,  260,   -2,  203,   -2,   -2,
 /*   100 */   266,    0,  266,  479,  266,  479,  266,  113,   -2,   -2,
 /*   110 */    -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,
 /*   120 */   612,  605,  614,   -2,  615,   -2,  422,   -2,  266,  479,
 /*   130 */   602,  203,  516,   -2,  454,   -2,  591,  648,  649,  266,
 /*   140 */   158,  650,  601,  266,  624,  266,   -2,  158,   -2,  600,
 /*   150 */   654,  415,  603,  657,  553,  606,  660,  662,  663,  664,
 /*   160 */   266,  158,  254,  366,  636,  184,  201,   -2,   -2,  636,
 /*   170 */   559,  627,   -2,  266,  158,   -2,  639,   -2,   -2,   -2,
 /*   180 */   419,  640,  638,  642,  641,  643,  582,  645,  644,  646,
 /*   190 */   588,  651,  647,  652,  589,  653,  655,  659,  636,   -2,
 /*   200 */    25,  661,   -2,   -2,   -2,   -2,  254,   -2,   -2,  542,
 /*   210 */   508,   -2,   24,  665,   -2,   -2,   -2,  637,  636,  514,
 /*   220 */   634,  266,  585,  684,  266,   -2,  158,   -2,  666,  594,
 /*   230 */   656,  658,  266,  598,  686,  666,   -2,   -2,   -2,  568,
 /*   240 */   628,  689,  667,  692,  693,  636,  668,  636,  671,  636,
 /*   250 */    -2,  699,  266,   -2,  158,   -2,  584,  630,  696,  700,
 /*   260 */   676,  636,   -2,
};
#define YY_REDUCE_USE_DFLT (-30)
static short yy_reduce_ofst[] = {
 /*     0 */   296,  -30,  -30,  -30,  -30,  -30,  179,  162,  156,  -30,
 /*    10 */   -30,  -30,  -30,  -30,  -30,  -30,  127,  -29,  292,  -30,
 /*    20 */   -30,  -30,  169,  -30,  337,  -30,  -30,  -30,  -30,  382,
 /*    30 */   386,  -30,  387,  -30,  391,  -30,  396,  -30,  397,  -30,
 /*    40 */   398,  -30,  402,  -30,  409,  -30,  418,  -30,  420,  -30,
 /*    50 */   424,  -30,  425,  -30,  429,  -30,  430,  -30,  436,  -30,
 /*    60 */   440,  -30,  452,  -30,  -30,  456,  -30,  459,  -30,  -30,
 /*    70 */   195,  -30,  462,  -30,  -30,  -30,  -30,  -30,  463,  -30,
 /*    80 */   -30,  466,  -30,  -30,  -30,  -30,  -30,  468,  -30,  -30,
 /*    90 */   -30,  -30,  -30,  -30,  279,  -30,  -30,  340,  -30,  -30,
 /*   100 */   472,  -30,  475,  -30,  478,  -30,  490,  -30,  -30,  -30,
 /*   110 */   -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,
 /*   120 */   -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  494,  -30,
 /*   130 */   -30,  299,  -30,  -30,  -30,  -30,  566,  -30,  -30,  496,
 /*   140 */   -30,  -30,  -30,  310,  -30,  350,  -30,  -30,  -30,  572,
 /*   150 */   -30,  204,  575,  -30,    7,  578,  -30,  -30,  -30,  -30,
 /*   160 */   501,  -30,  321,  -30,  371,  212,  288,  -30,  -30,  208,
 /*   170 */   388,  574,  -30,  506,  -30,  -30,  -30,  -30,  -30,  -30,
 /*   180 */   -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,
 /*   190 */   -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  297,  -30,
 /*   200 */   -30,  -30,  -30,  -30,  -30,  -30,  301,  -30,  -30,  -30,
 /*   210 */   -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  528,  -30,
 /*   220 */   -30,  311,  -30,  -30,  334,  -30,  -30,  -30,  332,  -30,
 /*   230 */   -30,  -30,  331,  -30,  -30,  593,  -30,  -30,  -30,   36,
 /*   240 */   597,  -30,  -30,  -30,  -30,  427,  -30,  493,  -30,  531,
 /*   250 */   -30,  -30,  352,  -30,  -30,  -30,  154,  604,  -30,  -30,
 /*   260 */   -30,  524,  -30,
};
static YYACTIONTYPE yy_default[] = {
 /*     0 */   417,  417,  417,  417,  417,  417,  417,  417,  417,  417,
 /*    10 */   417,  417,  417,  417,  417,  417,  417,  417,  417,  417,
 /*    20 */   417,  417,  417,  349,  417,  350,  352,  353,  354,  417,
 /*    30 */   417,  364,  417,  366,  417,  367,  417,  368,  417,  369,
 /*    40 */   417,  370,  417,  371,  417,  372,  417,  373,  417,  374,
 /*    50 */   417,  375,  417,  376,  417,  377,  417,  378,  417,  379,
 /*    60 */   417,  380,  417,  381,  417,  417,  382,  417,  383,  417,
 /*    70 */   417,  396,  417,  387,  417,  397,  417,  398,  417,  400,
 /*    80 */   417,  417,  417,  417,  417,  388,  417,  417,  417,  417,
 /*    90 */   417,  389,  390,  416,  417,  417,  391,  417,  393,  395,
 /*   100 */   417,  399,  417,  401,  417,  402,  417,  417,  403,  404,
 /*   110 */   405,  406,  407,  408,  409,  410,  411,  412,  392,  394,
 /*   120 */   417,  414,  417,  413,  417,  415,  417,  385,  417,  384,
 /*   130 */   417,  417,  417,  386,  365,  351,  417,  417,  417,  417,
 /*   140 */   359,  417,  417,  417,  355,  417,  356,  358,  357,  417,
 /*   150 */   417,  417,  417,  417,  417,  417,  417,  417,  417,  417,
 /*   160 */   417,  348,  417,  417,  417,  292,  293,  303,  305,  417,
 /*   170 */   306,  307,  309,  417,  321,  308,  417,  310,  311,  347,
 /*   180 */   416,  417,  417,  417,  417,  417,  417,  417,  417,  417,
 /*   190 */   417,  417,  417,  417,  417,  417,  417,  417,  417,  301,
 /*   200 */   346,  417,  344,  345,  304,  302,  417,  294,  296,  416,
 /*   210 */   417,  297,  300,  417,  298,  299,  295,  417,  417,  417,
 /*   220 */   417,  417,  417,  417,  417,  324,  326,  325,  417,  417,
 /*   230 */   417,  417,  417,  417,  417,  417,  327,  329,  328,  417,
 /*   240 */   417,  417,  417,  417,  417,  417,  417,  417,  334,  417,
 /*   250 */   335,  417,  417,  337,  338,  336,  417,  417,  417,  417,
 /*   260 */   417,  417,  343,
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
  "DESC",          "GROUP",         "HAVING",        "LIMIT",       
  "INTEGER",       "OFFSET",        "CAST",          "CONVERT",     
  "USING",         "NULL",          "STRING",        "DOUBLE",      
  "TRUE",          "FALSE",         "NPLACEHOLDER",  "SPLACEHOLDER",
  "COLON",         "error",         "program",       "query_language",
  "select_statement",  "insert_statement",  "update_statement",  "delete_statement",
  "select_clause",  "where_clause",  "order_clause",  "group_clause",
  "having_clause",  "select_limit_clause",  "column_list",   "associated_name_list",
  "join_list",     "column_item",   "expr",          "associated_name",
  "join_item",     "join_clause",   "join_type",     "aliased_or_qualified_name",
  "join_associated_name",  "join_conditions",  "values_list",   "field_list",  
  "value_list",    "value_item",    "field_item",    "update_clause",
  "limit_clause",  "update_item_list",  "update_item",   "qualified_name",
  "new_value",     "delete_clause",  "order_list",    "order_item",  
  "group_list",    "group_item",    "argument_list",  "function_call",
  "argument_item",
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
 /*  43 */ "join_clause ::= join_type aliased_or_qualified_name",
 /*  44 */ "join_clause ::= join_type aliased_or_qualified_name join_associated_name",
 /*  45 */ "join_clause ::= join_type aliased_or_qualified_name join_conditions",
 /*  46 */ "join_clause ::= join_type aliased_or_qualified_name join_associated_name join_conditions",
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
 /*  59 */ "insert_statement ::= INSERT INTO aliased_or_qualified_name VALUES PARENTHESES_OPEN values_list PARENTHESES_CLOSE",
 /*  60 */ "insert_statement ::= INSERT INTO aliased_or_qualified_name PARENTHESES_OPEN field_list PARENTHESES_CLOSE VALUES PARENTHESES_OPEN values_list PARENTHESES_CLOSE",
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
 /*  81 */ "associated_name ::= aliased_or_qualified_name AS IDENTIFIER",
 /*  82 */ "associated_name ::= aliased_or_qualified_name IDENTIFIER",
 /*  83 */ "associated_name ::= aliased_or_qualified_name",
 /*  84 */ "aliased_or_qualified_name ::= qualified_name",
 /*  85 */ "where_clause ::= WHERE expr",
 /*  86 */ "order_clause ::= ORDER BY order_list",
 /*  87 */ "order_list ::= order_list COMMA order_item",
 /*  88 */ "order_list ::= order_item",
 /*  89 */ "order_item ::= expr",
 /*  90 */ "order_item ::= expr ASC",
 /*  91 */ "order_item ::= expr DESC",
 /*  92 */ "group_clause ::= GROUP BY group_list",
 /*  93 */ "group_list ::= group_list COMMA group_item",
 /*  94 */ "group_list ::= group_item",
 /*  95 */ "group_item ::= expr",
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
 /* 126 */ "expr ::= CONVERT PARENTHESES_OPEN expr USING IDENTIFIER PARENTHESES_CLOSE",
 /* 127 */ "expr ::= function_call",
 /* 128 */ "function_call ::= IDENTIFIER PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 129 */ "function_call ::= IDENTIFIER PARENTHESES_OPEN PARENTHESES_CLOSE",
 /* 130 */ "argument_list ::= argument_list COMMA argument_item",
 /* 131 */ "argument_list ::= argument_item",
 /* 132 */ "argument_item ::= TIMES",
 /* 133 */ "argument_item ::= expr",
 /* 134 */ "expr ::= expr IS NULL",
 /* 135 */ "expr ::= expr IS NOT NULL",
 /* 136 */ "expr ::= DISTINCT expr",
 /* 137 */ "expr ::= expr BETWEEN expr",
 /* 138 */ "expr ::= NOT expr",
 /* 139 */ "expr ::= BITWISE_NOT expr",
 /* 140 */ "expr ::= PARENTHESES_OPEN expr PARENTHESES_CLOSE",
 /* 141 */ "expr ::= qualified_name",
 /* 142 */ "expr ::= INTEGER",
 /* 143 */ "expr ::= STRING",
 /* 144 */ "expr ::= DOUBLE",
 /* 145 */ "expr ::= NULL",
 /* 146 */ "expr ::= TRUE",
 /* 147 */ "expr ::= FALSE",
 /* 148 */ "expr ::= NPLACEHOLDER",
 /* 149 */ "expr ::= SPLACEHOLDER",
 /* 150 */ "qualified_name ::= IDENTIFIER COLON IDENTIFIER DOT IDENTIFIER",
 /* 151 */ "qualified_name ::= IDENTIFIER COLON IDENTIFIER",
 /* 152 */ "qualified_name ::= IDENTIFIER DOT IDENTIFIER",
 /* 153 */ "qualified_name ::= IDENTIFIER",
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
    case 64:
    case 65:
    case 66:
    case 67:
    case 68:
// 513 "parser.lemon"
{
	if ((yypminor->yy0)) {
		if ((yypminor->yy0)->free_flag) {
			efree((yypminor->yy0)->token);
		}
		efree((yypminor->yy0));
	}
}
// 1181 "parser.c"
      break;
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
    case 89:
    case 90:
    case 91:
    case 92:
    case 93:
    case 95:
    case 96:
    case 98:
    case 99:
    case 100:
    case 101:
    case 102:
    case 103:
    case 105:
    case 106:
    case 107:
    case 108:
    case 109:
    case 110:
    case 111:
    case 112:
// 526 "parser.lemon"
{ zval_ptr_dtor(&(yypminor->yy132)); }
// 1224 "parser.c"
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
  { 70, 1 },
  { 71, 1 },
  { 71, 1 },
  { 71, 1 },
  { 71, 1 },
  { 72, 1 },
  { 72, 2 },
  { 72, 3 },
  { 72, 3 },
  { 72, 4 },
  { 72, 4 },
  { 72, 5 },
  { 72, 5 },
  { 72, 3 },
  { 72, 4 },
  { 72, 4 },
  { 72, 5 },
  { 72, 2 },
  { 72, 3 },
  { 72, 4 },
  { 72, 3 },
  { 72, 4 },
  { 72, 6 },
  { 72, 2 },
  { 72, 3 },
  { 72, 3 },
  { 72, 4 },
  { 72, 5 },
  { 72, 2 },
  { 76, 4 },
  { 76, 5 },
  { 82, 3 },
  { 82, 1 },
  { 85, 1 },
  { 85, 3 },
  { 85, 3 },
  { 85, 2 },
  { 85, 1 },
  { 83, 3 },
  { 83, 1 },
  { 84, 2 },
  { 84, 1 },
  { 88, 1 },
  { 89, 2 },
  { 89, 3 },
  { 89, 3 },
  { 89, 4 },
  { 92, 2 },
  { 92, 1 },
  { 90, 1 },
  { 90, 2 },
  { 90, 2 },
  { 90, 2 },
  { 90, 3 },
  { 90, 2 },
  { 90, 3 },
  { 90, 2 },
  { 90, 3 },
  { 93, 2 },
  { 73, 7 },
  { 73, 10 },
  { 94, 3 },
  { 94, 1 },
  { 97, 1 },
  { 95, 3 },
  { 95, 1 },
  { 98, 1 },
  { 74, 1 },
  { 74, 2 },
  { 74, 2 },
  { 74, 3 },
  { 99, 4 },
  { 101, 3 },
  { 101, 1 },
  { 102, 3 },
  { 104, 1 },
  { 75, 1 },
  { 75, 2 },
  { 75, 2 },
  { 75, 3 },
  { 105, 3 },
  { 87, 3 },
  { 87, 2 },
  { 87, 1 },
  { 91, 1 },
  { 77, 2 },
  { 78, 3 },
  { 106, 3 },
  { 106, 1 },
  { 107, 1 },
  { 107, 2 },
  { 107, 2 },
  { 79, 3 },
  { 108, 3 },
  { 108, 1 },
  { 109, 1 },
  { 80, 2 },
  { 81, 2 },
  { 81, 4 },
  { 81, 4 },
  { 100, 2 },
  { 86, 2 },
  { 86, 3 },
  { 86, 3 },
  { 86, 3 },
  { 86, 3 },
  { 86, 3 },
  { 86, 3 },
  { 86, 3 },
  { 86, 3 },
  { 86, 3 },
  { 86, 3 },
  { 86, 3 },
  { 86, 3 },
  { 86, 3 },
  { 86, 3 },
  { 86, 3 },
  { 86, 3 },
  { 86, 3 },
  { 86, 4 },
  { 86, 3 },
  { 86, 4 },
  { 86, 5 },
  { 86, 6 },
  { 86, 3 },
  { 86, 6 },
  { 86, 6 },
  { 86, 1 },
  { 111, 4 },
  { 111, 3 },
  { 110, 3 },
  { 110, 1 },
  { 112, 1 },
  { 112, 1 },
  { 86, 3 },
  { 86, 4 },
  { 86, 2 },
  { 86, 3 },
  { 86, 2 },
  { 86, 2 },
  { 86, 3 },
  { 86, 1 },
  { 86, 1 },
  { 86, 1 },
  { 86, 1 },
  { 86, 1 },
  { 86, 1 },
  { 86, 1 },
  { 86, 1 },
  { 86, 1 },
  { 103, 5 },
  { 103, 3 },
  { 103, 3 },
  { 103, 1 },
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
// 522 "parser.lemon"
{
	status->ret = yymsp[0].minor.yy132;
}
// 1595 "parser.c"
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
      case 84:
      case 88:
      case 94:
      case 95:
      case 127:
      case 133:
      case 141:
// 528 "parser.lemon"
{
	yygotominor.yy132 = yymsp[0].minor.yy132;
}
// 1621 "parser.c"
        break;
      case 5:
// 546 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_select_statement(yymsp[0].minor.yy132, NULL, NULL, NULL, NULL, NULL);
}
// 1628 "parser.c"
        break;
      case 6:
// 550 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_select_statement(yymsp[-1].minor.yy132, yymsp[0].minor.yy132, NULL, NULL, NULL, NULL);
}
// 1635 "parser.c"
        break;
      case 7:
// 554 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_select_statement(yymsp[-2].minor.yy132, yymsp[-1].minor.yy132, yymsp[0].minor.yy132, NULL, NULL, NULL);
}
// 1642 "parser.c"
        break;
      case 8:
// 558 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_select_statement(yymsp[-2].minor.yy132, yymsp[-1].minor.yy132, NULL, yymsp[0].minor.yy132, NULL, NULL);
}
// 1649 "parser.c"
        break;
      case 9:
// 562 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_select_statement(yymsp[-3].minor.yy132, yymsp[-2].minor.yy132, NULL, yymsp[-1].minor.yy132, yymsp[0].minor.yy132, NULL);
}
// 1656 "parser.c"
        break;
      case 10:
// 566 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_select_statement(yymsp[-3].minor.yy132, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, yymsp[-1].minor.yy132, NULL, NULL);
}
// 1663 "parser.c"
        break;
      case 11:
// 570 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_select_statement(yymsp[-4].minor.yy132, yymsp[-3].minor.yy132, yymsp[-1].minor.yy132, yymsp[-2].minor.yy132, NULL, yymsp[0].minor.yy132);
}
// 1670 "parser.c"
        break;
      case 12:
// 574 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_select_statement(yymsp[-4].minor.yy132, yymsp[-3].minor.yy132, yymsp[0].minor.yy132, yymsp[-2].minor.yy132, yymsp[-1].minor.yy132, NULL);
}
// 1677 "parser.c"
        break;
      case 13:
// 578 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_select_statement(yymsp[-2].minor.yy132, yymsp[-1].minor.yy132, NULL, NULL, NULL, yymsp[0].minor.yy132);
}
// 1684 "parser.c"
        break;
      case 14:
// 582 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_select_statement(yymsp[-3].minor.yy132, yymsp[-2].minor.yy132, yymsp[-1].minor.yy132, NULL, NULL, yymsp[0].minor.yy132);
}
// 1691 "parser.c"
        break;
      case 15:
// 586 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_select_statement(yymsp[-3].minor.yy132, yymsp[-2].minor.yy132, NULL, yymsp[-1].minor.yy132, NULL, yymsp[0].minor.yy132);
}
// 1698 "parser.c"
        break;
      case 16:
// 590 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_select_statement(yymsp[-4].minor.yy132, yymsp[-3].minor.yy132, NULL, yymsp[-2].minor.yy132, yymsp[-1].minor.yy132, yymsp[0].minor.yy132);
}
// 1705 "parser.c"
        break;
      case 17:
// 594 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_select_statement(yymsp[-1].minor.yy132, NULL, yymsp[0].minor.yy132, NULL, NULL, NULL);
}
// 1712 "parser.c"
        break;
      case 18:
// 598 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_select_statement(yymsp[-2].minor.yy132, NULL, yymsp[0].minor.yy132, yymsp[-1].minor.yy132, NULL, NULL);
}
// 1719 "parser.c"
        break;
      case 19:
// 602 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_select_statement(yymsp[-3].minor.yy132, NULL, yymsp[0].minor.yy132, yymsp[-2].minor.yy132, yymsp[-1].minor.yy132, NULL);
}
// 1726 "parser.c"
        break;
      case 20:
// 606 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_select_statement(yymsp[-2].minor.yy132, NULL, yymsp[-1].minor.yy132, NULL, NULL, yymsp[0].minor.yy132);
}
// 1733 "parser.c"
        break;
      case 21:
// 610 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_select_statement(yymsp[-3].minor.yy132, NULL, yymsp[-1].minor.yy132, yymsp[-2].minor.yy132, NULL, yymsp[0].minor.yy132);
}
// 1740 "parser.c"
        break;
      case 22:
// 614 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_select_statement(yymsp[-5].minor.yy132, yymsp[-4].minor.yy132, yymsp[-1].minor.yy132, yymsp[-3].minor.yy132, yymsp[-2].minor.yy132, yymsp[0].minor.yy132);
}
// 1747 "parser.c"
        break;
      case 23:
// 618 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_select_statement(yymsp[-1].minor.yy132, NULL, NULL, yymsp[0].minor.yy132, NULL, NULL);
}
// 1754 "parser.c"
        break;
      case 24:
// 622 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_select_statement(yymsp[-2].minor.yy132, NULL, NULL, yymsp[-1].minor.yy132, NULL, yymsp[0].minor.yy132);
}
// 1761 "parser.c"
        break;
      case 25:
// 626 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_select_statement(yymsp[-2].minor.yy132, NULL, NULL, yymsp[-1].minor.yy132, yymsp[0].minor.yy132, NULL);
}
// 1768 "parser.c"
        break;
      case 26:
// 630 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_select_statement(yymsp[-3].minor.yy132, NULL, NULL, yymsp[-2].minor.yy132, yymsp[-1].minor.yy132, yymsp[0].minor.yy132);
}
// 1775 "parser.c"
        break;
      case 27:
// 634 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_select_statement(yymsp[-4].minor.yy132, NULL, yymsp[-1].minor.yy132, yymsp[-3].minor.yy132, yymsp[-2].minor.yy132, yymsp[0].minor.yy132);
}
// 1782 "parser.c"
        break;
      case 28:
// 638 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_select_statement(yymsp[-1].minor.yy132, NULL, NULL, NULL, NULL, yymsp[0].minor.yy132);
}
// 1789 "parser.c"
        break;
      case 29:
// 644 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_select_clause(yymsp[-2].minor.yy132, yymsp[0].minor.yy132, NULL);
  yy_destructor(26,&yymsp[-3].minor);
  yy_destructor(27,&yymsp[-1].minor);
}
// 1798 "parser.c"
        break;
      case 30:
// 648 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_select_clause(yymsp[-3].minor.yy132, yymsp[-1].minor.yy132, yymsp[0].minor.yy132);
  yy_destructor(26,&yymsp[-4].minor);
  yy_destructor(27,&yymsp[-2].minor);
}
// 1807 "parser.c"
        break;
      case 31:
      case 38:
      case 61:
      case 64:
      case 72:
      case 87:
      case 93:
      case 130:
// 654 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_zval_list(yymsp[-2].minor.yy132, yymsp[0].minor.yy132);
  yy_destructor(28,&yymsp[-1].minor);
}
// 1822 "parser.c"
        break;
      case 33:
      case 132:
// 664 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_column_item(PHQL_T_ALL, NULL, NULL, NULL);
  yy_destructor(17,&yymsp[0].minor);
}
// 1831 "parser.c"
        break;
      case 34:
// 668 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_column_item(PHQL_T_DOMAINALL, NULL, yymsp[-2].minor.yy0, NULL);
  yy_destructor(30,&yymsp[-1].minor);
  yy_destructor(17,&yymsp[0].minor);
}
// 1840 "parser.c"
        break;
      case 35:
// 672 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-2].minor.yy132, NULL, yymsp[0].minor.yy0);
  yy_destructor(31,&yymsp[-1].minor);
}
// 1848 "parser.c"
        break;
      case 36:
// 676 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-1].minor.yy132, NULL, yymsp[0].minor.yy0);
}
// 1855 "parser.c"
        break;
      case 37:
// 680 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_column_item(PHQL_T_EXPR, yymsp[0].minor.yy132, NULL, NULL);
}
// 1862 "parser.c"
        break;
      case 40:
// 696 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_zval_list(yymsp[-1].minor.yy132, yymsp[0].minor.yy132);
}
// 1869 "parser.c"
        break;
      case 43:
// 713 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_join_item(yymsp[-1].minor.yy132, yymsp[0].minor.yy132, NULL, NULL);
}
// 1876 "parser.c"
        break;
      case 44:
// 718 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_join_item(yymsp[-2].minor.yy132, yymsp[-1].minor.yy132, yymsp[0].minor.yy132, NULL);
}
// 1883 "parser.c"
        break;
      case 45:
// 723 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_join_item(yymsp[-2].minor.yy132, yymsp[-1].minor.yy132, NULL, yymsp[0].minor.yy132);
}
// 1890 "parser.c"
        break;
      case 46:
// 728 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_join_item(yymsp[-3].minor.yy132, yymsp[-2].minor.yy132, yymsp[-1].minor.yy132, yymsp[0].minor.yy132);
}
// 1897 "parser.c"
        break;
      case 47:
// 734 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_qualified_name(NULL, NULL, yymsp[0].minor.yy0);
  yy_destructor(31,&yymsp[-1].minor);
}
// 1905 "parser.c"
        break;
      case 48:
      case 66:
      case 153:
// 738 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_qualified_name(NULL, NULL, yymsp[0].minor.yy0);
}
// 1914 "parser.c"
        break;
      case 49:
// 744 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_join_type(PHQL_T_INNERJOIN);
  yy_destructor(32,&yymsp[0].minor);
}
// 1922 "parser.c"
        break;
      case 50:
// 748 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_join_type(PHQL_T_INNERJOIN);
  yy_destructor(33,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 1931 "parser.c"
        break;
      case 51:
// 752 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_join_type(PHQL_T_CROSSJOIN);
  yy_destructor(34,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 1940 "parser.c"
        break;
      case 52:
// 756 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  yy_destructor(35,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 1949 "parser.c"
        break;
      case 53:
// 760 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 1959 "parser.c"
        break;
      case 54:
// 764 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  yy_destructor(37,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 1968 "parser.c"
        break;
      case 55:
// 768 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  yy_destructor(37,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 1978 "parser.c"
        break;
      case 56:
// 772 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_join_type(PHQL_T_FULLJOIN);
  yy_destructor(38,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 1987 "parser.c"
        break;
      case 57:
// 776 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_join_type(PHQL_T_FULLJOIN);
  yy_destructor(38,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 1997 "parser.c"
        break;
      case 58:
// 782 "parser.lemon"
{
	yygotominor.yy132 = yymsp[0].minor.yy132;
  yy_destructor(39,&yymsp[-1].minor);
}
// 2005 "parser.c"
        break;
      case 59:
// 789 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_insert_statement(yymsp[-4].minor.yy132, NULL, yymsp[-1].minor.yy132);
  yy_destructor(40,&yymsp[-6].minor);
  yy_destructor(41,&yymsp[-5].minor);
  yy_destructor(42,&yymsp[-3].minor);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2017 "parser.c"
        break;
      case 60:
// 793 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_insert_statement(yymsp[-7].minor.yy132, yymsp[-5].minor.yy132, yymsp[-1].minor.yy132);
  yy_destructor(40,&yymsp[-9].minor);
  yy_destructor(41,&yymsp[-8].minor);
  yy_destructor(43,&yymsp[-6].minor);
  yy_destructor(44,&yymsp[-4].minor);
  yy_destructor(42,&yymsp[-3].minor);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2031 "parser.c"
        break;
      case 67:
// 831 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_update_statement(yymsp[0].minor.yy132, NULL, NULL);
}
// 2038 "parser.c"
        break;
      case 68:
// 835 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_update_statement(yymsp[-1].minor.yy132, yymsp[0].minor.yy132, NULL);
}
// 2045 "parser.c"
        break;
      case 69:
// 839 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_update_statement(yymsp[-1].minor.yy132, NULL, yymsp[0].minor.yy132);
}
// 2052 "parser.c"
        break;
      case 70:
// 843 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_update_statement(yymsp[-2].minor.yy132, yymsp[-1].minor.yy132, yymsp[0].minor.yy132);
}
// 2059 "parser.c"
        break;
      case 71:
// 849 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_update_clause(yymsp[-2].minor.yy132, yymsp[0].minor.yy132);
  yy_destructor(45,&yymsp[-3].minor);
  yy_destructor(46,&yymsp[-1].minor);
}
// 2068 "parser.c"
        break;
      case 74:
// 865 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_update_item(yymsp[-2].minor.yy132, yymsp[0].minor.yy132);
  yy_destructor(3,&yymsp[-1].minor);
}
// 2076 "parser.c"
        break;
      case 76:
// 877 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_delete_statement(yymsp[0].minor.yy132, NULL, NULL);
}
// 2083 "parser.c"
        break;
      case 77:
// 881 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_delete_statement(yymsp[-1].minor.yy132, yymsp[0].minor.yy132, NULL);
}
// 2090 "parser.c"
        break;
      case 78:
// 885 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_delete_statement(yymsp[-1].minor.yy132, NULL, yymsp[0].minor.yy132);
}
// 2097 "parser.c"
        break;
      case 79:
// 889 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_delete_statement(yymsp[-2].minor.yy132, yymsp[-1].minor.yy132, yymsp[0].minor.yy132);
}
// 2104 "parser.c"
        break;
      case 80:
// 895 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_delete_clause(yymsp[0].minor.yy132);
  yy_destructor(47,&yymsp[-2].minor);
  yy_destructor(27,&yymsp[-1].minor);
}
// 2113 "parser.c"
        break;
      case 81:
// 901 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_assoc_name(yymsp[-2].minor.yy132, yymsp[0].minor.yy0);
  yy_destructor(31,&yymsp[-1].minor);
}
// 2121 "parser.c"
        break;
      case 82:
// 905 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_assoc_name(yymsp[-1].minor.yy132, yymsp[0].minor.yy0);
}
// 2128 "parser.c"
        break;
      case 83:
// 909 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_assoc_name(yymsp[0].minor.yy132, NULL);
}
// 2135 "parser.c"
        break;
      case 85:
// 921 "parser.lemon"
{
	yygotominor.yy132 = yymsp[0].minor.yy132;
  yy_destructor(48,&yymsp[-1].minor);
}
// 2143 "parser.c"
        break;
      case 86:
// 927 "parser.lemon"
{
	yygotominor.yy132 = yymsp[0].minor.yy132;
  yy_destructor(49,&yymsp[-2].minor);
  yy_destructor(50,&yymsp[-1].minor);
}
// 2152 "parser.c"
        break;
      case 89:
// 943 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_order_item(yymsp[0].minor.yy132, 0);
}
// 2159 "parser.c"
        break;
      case 90:
// 947 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_order_item(yymsp[-1].minor.yy132, PHQL_T_ASC);
  yy_destructor(51,&yymsp[0].minor);
}
// 2167 "parser.c"
        break;
      case 91:
// 951 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_order_item(yymsp[-1].minor.yy132, PHQL_T_DESC);
  yy_destructor(52,&yymsp[0].minor);
}
// 2175 "parser.c"
        break;
      case 92:
// 957 "parser.lemon"
{
	yygotominor.yy132 = yymsp[0].minor.yy132;
  yy_destructor(53,&yymsp[-2].minor);
  yy_destructor(50,&yymsp[-1].minor);
}
// 2184 "parser.c"
        break;
      case 96:
// 979 "parser.lemon"
{
	yygotominor.yy132 = yymsp[0].minor.yy132;
  yy_destructor(54,&yymsp[-1].minor);
}
// 2192 "parser.c"
        break;
      case 97:
      case 100:
// 985 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_limit_clause(yymsp[0].minor.yy0, NULL);
  yy_destructor(55,&yymsp[-1].minor);
}
// 2201 "parser.c"
        break;
      case 98:
// 989 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_limit_clause(yymsp[0].minor.yy0, yymsp[-2].minor.yy0);
  yy_destructor(55,&yymsp[-3].minor);
  yy_destructor(28,&yymsp[-1].minor);
}
// 2210 "parser.c"
        break;
      case 99:
// 993 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_limit_clause(yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(55,&yymsp[-3].minor);
  yy_destructor(57,&yymsp[-1].minor);
}
// 2219 "parser.c"
        break;
      case 101:
// 1005 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_expr(PHQL_T_MINUS, NULL, yymsp[0].minor.yy132);
  yy_destructor(20,&yymsp[-1].minor);
}
// 2227 "parser.c"
        break;
      case 102:
// 1009 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_expr(PHQL_T_SUB, yymsp[-2].minor.yy132, yymsp[0].minor.yy132);
  yy_destructor(20,&yymsp[-1].minor);
}
// 2235 "parser.c"
        break;
      case 103:
// 1013 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_expr(PHQL_T_ADD, yymsp[-2].minor.yy132, yymsp[0].minor.yy132);
  yy_destructor(19,&yymsp[-1].minor);
}
// 2243 "parser.c"
        break;
      case 104:
// 1017 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_expr(PHQL_T_MUL, yymsp[-2].minor.yy132, yymsp[0].minor.yy132);
  yy_destructor(17,&yymsp[-1].minor);
}
// 2251 "parser.c"
        break;
      case 105:
// 1021 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_expr(PHQL_T_DIV, yymsp[-2].minor.yy132, yymsp[0].minor.yy132);
  yy_destructor(16,&yymsp[-1].minor);
}
// 2259 "parser.c"
        break;
      case 106:
// 1025 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_expr(PHQL_T_MOD, yymsp[-2].minor.yy132, yymsp[0].minor.yy132);
  yy_destructor(18,&yymsp[-1].minor);
}
// 2267 "parser.c"
        break;
      case 107:
// 1029 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_expr(PHQL_T_AND, yymsp[-2].minor.yy132, yymsp[0].minor.yy132);
  yy_destructor(9,&yymsp[-1].minor);
}
// 2275 "parser.c"
        break;
      case 108:
// 1033 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_expr(PHQL_T_OR, yymsp[-2].minor.yy132, yymsp[0].minor.yy132);
  yy_destructor(10,&yymsp[-1].minor);
}
// 2283 "parser.c"
        break;
      case 109:
// 1037 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_expr(PHQL_T_BITWISE_AND, yymsp[-2].minor.yy132, yymsp[0].minor.yy132);
  yy_destructor(13,&yymsp[-1].minor);
}
// 2291 "parser.c"
        break;
      case 110:
// 1041 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_expr(PHQL_T_BITWISE_OR, yymsp[-2].minor.yy132, yymsp[0].minor.yy132);
  yy_destructor(14,&yymsp[-1].minor);
}
// 2299 "parser.c"
        break;
      case 111:
// 1045 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_expr(PHQL_T_BITWISE_XOR, yymsp[-2].minor.yy132, yymsp[0].minor.yy132);
  yy_destructor(15,&yymsp[-1].minor);
}
// 2307 "parser.c"
        break;
      case 112:
// 1049 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_expr(PHQL_T_EQUALS, yymsp[-2].minor.yy132, yymsp[0].minor.yy132);
  yy_destructor(3,&yymsp[-1].minor);
}
// 2315 "parser.c"
        break;
      case 113:
// 1053 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_expr(PHQL_T_NOTEQUALS, yymsp[-2].minor.yy132, yymsp[0].minor.yy132);
  yy_destructor(4,&yymsp[-1].minor);
}
// 2323 "parser.c"
        break;
      case 114:
// 1057 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_expr(PHQL_T_LESS, yymsp[-2].minor.yy132, yymsp[0].minor.yy132);
  yy_destructor(5,&yymsp[-1].minor);
}
// 2331 "parser.c"
        break;
      case 115:
// 1061 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_expr(PHQL_T_GREATER, yymsp[-2].minor.yy132, yymsp[0].minor.yy132);
  yy_destructor(6,&yymsp[-1].minor);
}
// 2339 "parser.c"
        break;
      case 116:
// 1065 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_expr(PHQL_T_GREATEREQUAL, yymsp[-2].minor.yy132, yymsp[0].minor.yy132);
  yy_destructor(7,&yymsp[-1].minor);
}
// 2347 "parser.c"
        break;
      case 117:
// 1069 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_expr(PHQL_T_LESSEQUAL, yymsp[-2].minor.yy132, yymsp[0].minor.yy132);
  yy_destructor(8,&yymsp[-1].minor);
}
// 2355 "parser.c"
        break;
      case 118:
// 1073 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_expr(PHQL_T_LIKE, yymsp[-2].minor.yy132, yymsp[0].minor.yy132);
  yy_destructor(11,&yymsp[-1].minor);
}
// 2363 "parser.c"
        break;
      case 119:
// 1077 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_expr(PHQL_T_NLIKE, yymsp[-3].minor.yy132, yymsp[0].minor.yy132);
  yy_destructor(24,&yymsp[-2].minor);
  yy_destructor(11,&yymsp[-1].minor);
}
// 2372 "parser.c"
        break;
      case 120:
// 1081 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_expr(PHQL_T_ILIKE, yymsp[-2].minor.yy132, yymsp[0].minor.yy132);
  yy_destructor(12,&yymsp[-1].minor);
}
// 2380 "parser.c"
        break;
      case 121:
// 1085 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_expr(PHQL_T_NILIKE, yymsp[-3].minor.yy132, yymsp[0].minor.yy132);
  yy_destructor(24,&yymsp[-2].minor);
  yy_destructor(12,&yymsp[-1].minor);
}
// 2389 "parser.c"
        break;
      case 122:
// 1089 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_expr(PHQL_T_IN, yymsp[-4].minor.yy132, yymsp[-1].minor.yy132);
  yy_destructor(22,&yymsp[-3].minor);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2399 "parser.c"
        break;
      case 123:
// 1093 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_expr(PHQL_T_NOTIN, yymsp[-5].minor.yy132, yymsp[-1].minor.yy132);
  yy_destructor(24,&yymsp[-4].minor);
  yy_destructor(22,&yymsp[-3].minor);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2410 "parser.c"
        break;
      case 124:
// 1097 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_expr(PHQL_T_AGAINST, yymsp[-2].minor.yy132, yymsp[0].minor.yy132);
  yy_destructor(1,&yymsp[-1].minor);
}
// 2418 "parser.c"
        break;
      case 125:
// 1101 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_expr(PHQL_T_CAST, yymsp[-3].minor.yy132, phql_ret_raw_qualified_name(yymsp[-1].minor.yy0, NULL));
  yy_destructor(58,&yymsp[-5].minor);
  yy_destructor(43,&yymsp[-4].minor);
  yy_destructor(31,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2429 "parser.c"
        break;
      case 126:
// 1105 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_expr(PHQL_T_CONVERT, yymsp[-3].minor.yy132, phql_ret_raw_qualified_name(yymsp[-1].minor.yy0, NULL));
  yy_destructor(59,&yymsp[-5].minor);
  yy_destructor(43,&yymsp[-4].minor);
  yy_destructor(60,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2440 "parser.c"
        break;
      case 128:
// 1115 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_func_call(yymsp[-3].minor.yy0, yymsp[-1].minor.yy132);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2449 "parser.c"
        break;
      case 129:
// 1119 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_func_call(yymsp[-2].minor.yy0, NULL);
  yy_destructor(43,&yymsp[-1].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2458 "parser.c"
        break;
      case 131:
// 1129 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_zval_list(yymsp[0].minor.yy132, NULL);
}
// 2465 "parser.c"
        break;
      case 134:
// 1143 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_expr(PHQL_T_ISNULL, yymsp[-2].minor.yy132, NULL);
  yy_destructor(21,&yymsp[-1].minor);
  yy_destructor(61,&yymsp[0].minor);
}
// 2474 "parser.c"
        break;
      case 135:
// 1147 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_expr(PHQL_T_ISNOTNULL, yymsp[-3].minor.yy132, NULL);
  yy_destructor(21,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
  yy_destructor(61,&yymsp[0].minor);
}
// 2484 "parser.c"
        break;
      case 136:
// 1151 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_expr(PHQL_T_DISTINCT, NULL, yymsp[0].minor.yy132);
  yy_destructor(23,&yymsp[-1].minor);
}
// 2492 "parser.c"
        break;
      case 137:
// 1155 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_expr(PHQL_T_BETWEEN, yymsp[-2].minor.yy132, yymsp[0].minor.yy132);
  yy_destructor(2,&yymsp[-1].minor);
}
// 2500 "parser.c"
        break;
      case 138:
// 1159 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_expr(PHQL_T_NOT, NULL, yymsp[0].minor.yy132);
  yy_destructor(24,&yymsp[-1].minor);
}
// 2508 "parser.c"
        break;
      case 139:
// 1163 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_expr(PHQL_T_BITWISE_NOT, NULL, yymsp[0].minor.yy132);
  yy_destructor(25,&yymsp[-1].minor);
}
// 2516 "parser.c"
        break;
      case 140:
// 1167 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_expr(PHQL_T_ENCLOSED, yymsp[-1].minor.yy132, NULL);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2525 "parser.c"
        break;
      case 142:
// 1175 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_literal_zval(PHQL_T_INTEGER, yymsp[0].minor.yy0);
}
// 2532 "parser.c"
        break;
      case 143:
// 1179 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_literal_zval(PHQL_T_STRING, yymsp[0].minor.yy0);
}
// 2539 "parser.c"
        break;
      case 144:
// 1183 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_literal_zval(PHQL_T_DOUBLE, yymsp[0].minor.yy0);
}
// 2546 "parser.c"
        break;
      case 145:
// 1187 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_literal_zval(PHQL_T_NULL, NULL);
  yy_destructor(61,&yymsp[0].minor);
}
// 2554 "parser.c"
        break;
      case 146:
// 1191 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_literal_zval(PHQL_T_TRUE, NULL);
  yy_destructor(64,&yymsp[0].minor);
}
// 2562 "parser.c"
        break;
      case 147:
// 1195 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_literal_zval(PHQL_T_FALSE, NULL);
  yy_destructor(65,&yymsp[0].minor);
}
// 2570 "parser.c"
        break;
      case 148:
// 1199 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_placeholder_zval(PHQL_T_NPLACEHOLDER, yymsp[0].minor.yy0);
}
// 2577 "parser.c"
        break;
      case 149:
// 1203 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_placeholder_zval(PHQL_T_SPLACEHOLDER, yymsp[0].minor.yy0);
}
// 2584 "parser.c"
        break;
      case 150:
// 1209 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_qualified_name(yymsp[-4].minor.yy0, yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(68,&yymsp[-3].minor);
  yy_destructor(30,&yymsp[-1].minor);
}
// 2593 "parser.c"
        break;
      case 151:
// 1213 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_qualified_name(yymsp[-2].minor.yy0, NULL, yymsp[0].minor.yy0);
  yy_destructor(68,&yymsp[-1].minor);
}
// 2601 "parser.c"
        break;
      case 152:
// 1217 "parser.lemon"
{
	yygotominor.yy132 = phql_ret_qualified_name(NULL, yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(30,&yymsp[-1].minor);
}
// 2609 "parser.c"
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
// 446 "parser.lemon"

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

// 2718 "parser.c"
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
  { NULL, 0, 0 }
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
		if (error_msg != NULL) {
			phalcon_throw_exception_string(phalcon_mvc_model_exception_ce, Z_STRVAL_P(error_msg), Z_STRLEN_P(error_msg), 1 TSRMLS_CC);
		}
		else {
			phalcon_throw_exception_string(phalcon_mvc_model_exception_ce, SL("Error parsing PHQL"), 1 TSRMLS_CC);
		}

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
	int scanner_status, status = SUCCESS, error_length, cache_level;
	phql_scanner_state *state;
	phql_scanner_token token;
	unsigned long phql_key = 0;
	void* phql_parser;
	char *error;
	zval **temp_ast;

	if (!phql) {
		PHALCON_INIT_VAR(*error_msg);
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
			case PHQL_T_TRUE:
				if (parser_status->enable_literals) {
					phql_(phql_parser, PHQL_TRUE, NULL, parser_status);
				} else {
					PHALCON_INIT_VAR(*error_msg);
					ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements", 1);
					parser_status->status = PHQL_PARSING_FAILED;
				}
				break;
			case PHQL_T_FALSE:
				if (parser_status->enable_literals) {
					phql_(phql_parser, PHQL_FALSE, NULL, parser_status);
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
