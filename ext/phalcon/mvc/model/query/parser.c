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


// 414 "parser.c"
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
#define YYNOCODE 115
#define YYACTIONTYPE unsigned short int
#define phql_TOKENTYPE phql_parser_token*
typedef union {
  phql_TOKENTYPE yy0;
  zval* yy48;
  int yy229;
} YYMINORTYPE;
#define YYSTACKDEPTH 100
#define phql_ARG_SDECL phql_parser_status *status;
#define phql_ARG_PDECL ,phql_parser_status *status
#define phql_ARG_FETCH phql_parser_status *status = yypParser->status
#define phql_ARG_STORE yypParser->status = status
#define YYNSTATE 269
#define YYNRULE 158
#define YYERRORSYMBOL 69
#define YYERRSYMDT yy229
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
 /*     0 */    75,   81,   53,   55,   57,   59,   61,   63,   43,   45,
 /*    10 */    65,   70,   47,   49,   51,   39,   37,   41,   35,   32,
 /*    20 */    77,   72,   72,   67,   67,   75,   81,   53,   55,   57,
 /*    30 */    59,   61,   63,   43,   45,   65,   70,   47,   49,   51,
 /*    40 */    39,   37,   41,   35,   32,   77,   72,  269,   67,   21,
 /*    50 */    30,   31,   23,  221,  209,  219,  207,   75,   81,   53,
 /*    60 */    55,   57,   59,   61,   63,   43,   45,   65,   70,   47,
 /*    70 */    49,   51,   39,   37,   41,   35,   32,   77,   72,  270,
 /*    80 */    67,    7,  152,  154,  162,  165,  271,   86,  246,   75,
 /*    90 */    81,   53,   55,   57,   59,   61,   63,   43,   45,   65,
 /*   100 */    70,   47,   49,   51,   39,   37,   41,   35,   32,   77,
 /*   110 */    72,  250,   67,  263,   75,   81,   53,   55,   57,   59,
 /*   120 */    61,   63,   43,   45,   65,   70,   47,   49,   51,   39,
 /*   130 */    37,   41,   35,   32,   77,   72,  265,   67,   65,   70,
 /*   140 */    47,   49,   51,   39,   37,   41,   35,   32,   77,   72,
 /*   150 */    92,   67,  276,   35,   32,   77,   72,  111,   67,   75,
 /*   160 */    81,   53,   55,   57,   59,   61,   63,   43,   45,   65,
 /*   170 */    70,   47,   49,   51,   39,   37,   41,   35,   32,   77,
 /*   180 */    72,  272,   67,   53,   55,   57,   59,   61,   63,   43,
 /*   190 */    45,   65,   70,   47,   49,   51,   39,   37,   41,   35,
 /*   200 */    32,   77,   72,  102,   67,  273,   33,   10,  171,  103,
 /*   210 */   105,  107,  211,  367,  102,   96,  206,   33,    9,  172,
 /*   220 */   103,  105,  107,  210,  174,  175,   96,   79,  185,  109,
 /*   230 */   121,   39,   37,   41,   35,   32,   77,   72,  283,   67,
 /*   240 */   109,   12,   11,  113,  119,  120,   83,   89,   13,  116,
 /*   250 */   114,  115,  117,  118,  113,  119,  120,   83,   89,  232,
 /*   260 */   116,  114,  115,  117,  118,  214,   78,  228,   33,   17,
 /*   270 */   233,  103,  105,  107,  213,  218,  112,  215,  139,   33,
 /*   280 */    20,  141,  103,  105,  107,   95,   68,  131,   96,  204,
 /*   290 */   368,  109,  112,  187,  188,  190,  192,  133,  196,  200,
 /*   300 */   158,   95,  109,  160,   18,  113,  119,  120,   83,   89,
 /*   310 */   369,  116,  114,  115,  117,  118,  113,  119,  120,   83,
 /*   320 */    89,  274,  116,  114,  115,  117,  118,   43,   45,   65,
 /*   330 */    70,   47,   49,   51,   39,   37,   41,   35,   32,   77,
 /*   340 */    72,  176,   67,   47,   49,   51,   39,   37,   41,   35,
 /*   350 */    32,   77,   72,  185,   67,  428,    1,    2,    3,    4,
 /*   360 */     5,    6,    8,   19,  291,  144,   14,   15,   16,  166,
 /*   370 */    24,  173,  174,  175,  145,  142,   10,  187,  188,  190,
 /*   380 */   192,   29,  196,  200,  245,   22,   74,  275,  278,   74,
 /*   390 */   262,  155,   74,  157,  161,  285,   77,   72,  112,   67,
 /*   400 */    25,   26,  138,  112,  277,  150,  112,   95,  295,  112,
 /*   410 */    67,  129,   95,  122,   98,   95,  122,  135,   95,  122,
 /*   420 */   169,  232,  112,  222,  218,  168,  293,  147,  151,  239,
 /*   430 */    80,   95,  233,   88,   29,   74,   24,   24,  112,  223,
 /*   440 */   145,  112,   10,   10,  251,  281,  266,   95,  150,   73,
 /*   450 */    95,  112,  112,   24,   84,   28,  232,   24,  142,   10,
 /*   460 */    95,   95,  101,   10,   87,  112,  260,  231,  137,   34,
 /*   470 */    36,  149,  127,  112,   95,   24,   38,  254,  261,  257,
 /*   480 */   142,   10,   95,  112,  259,  112,  112,  112,   40,   42,
 /*   490 */    27,   44,   95,  112,   95,   95,   95,  100,   90,   46,
 /*   500 */    10,   48,   95,   50,   52,  112,  112,   54,  112,   56,
 /*   510 */   123,   58,  279,   99,   95,   95,  112,   95,  112,   60,
 /*   520 */   112,  112,   62,   64,  112,   95,  112,   95,  112,   95,
 /*   530 */    95,  170,  212,   95,   66,   95,  112,   95,   69,  112,
 /*   540 */   112,  230,   71,  177,  181,   95,   76,   93,   95,   95,
 /*   550 */   100,  112,   82,   85,   91,  112,  104,  229,  106,  112,
 /*   560 */    95,  127,  337,  112,   95,  286,  130,   10,   95,  112,
 /*   570 */   112,  112,   95,  112,   97,  112,  108,  346,   95,   95,
 /*   580 */    95,  110,   95,  132,   95,  184,  143,  182,  167,  180,
 /*   590 */   287,  216,  205,  112,  288,  179,  206,  252,  112,  123,
 /*   600 */   112,  206,   95,  112,   97,  112,  112,   95,  185,   95,
 /*   610 */   166,  100,   95,  185,   95,   95,  338,  248,  347,  193,
 /*   620 */    10,  217,  268,  194,  197,  166,  206,  136,  198,  123,
 /*   630 */   201,  225,  248,  128,  202,  226,  234,  235,  185,  241,
 /*   640 */   244,  230,  125,  185,   94,   10,  256,  257,  124,   10,
 /*   650 */   126,  128,  134,  140,  280,  236,  284,  240,  282,  148,
 /*   660 */   146,  153,  289,  156,  290,  159,  297,  296,  294,   24,
 /*   670 */    10,  248,  164,  248,  163,  292,  298,  186,  179,  178,
 /*   680 */   183,  319,  189,  224,  320,  191,  321,  227,  322,  329,
 /*   690 */   323,  237,  195,  330,  324,  199,  340,  242,  325,  326,
 /*   700 */   370,  327,  208,  203,  339,  247,  220,  243,  255,  258,
 /*   710 */   349,  249,  348,  267,  264,  274,  274,  238,  274,  274,
 /*   720 */   274,  274,  274,  274,  274,  253,
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
 /*    80 */    24,   77,   78,   79,   80,   81,    0,   31,   77,    1,
 /*    90 */     2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   100 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   110 */    22,  100,   24,   77,    1,    2,    3,    4,    5,    6,
 /*   120 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   130 */    17,   18,   19,   20,   21,   22,  100,   24,   11,   12,
 /*   140 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   150 */    62,   24,    0,   19,   20,   21,   22,   44,   24,    1,
 /*   160 */     2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   170 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   180 */    22,    0,   24,    3,    4,    5,    6,    7,    8,    9,
 /*   190 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   200 */    20,   21,   22,   17,   24,    0,   20,   55,   83,   23,
 /*   210 */    24,   25,   87,    0,   17,   29,   91,   20,   81,   84,
 /*   220 */    23,   24,   25,   88,   89,   90,   29,   24,  103,   43,
 /*   230 */    44,   16,   17,   18,   19,   20,   21,   22,    0,   24,
 /*   240 */    43,   28,  110,   57,   58,   59,   60,   61,  110,   63,
 /*   250 */    64,   65,   66,   67,   57,   58,   59,   60,   61,   86,
 /*   260 */    63,   64,   65,   66,   67,   17,   63,   94,   20,   56,
 /*   270 */    97,   23,   24,   25,   85,   86,  103,   29,   78,   20,
 /*   280 */    80,   81,   23,   24,   25,  112,   11,   12,   29,   28,
 /*   290 */     0,   43,  103,   32,   33,   34,   35,   22,   37,   38,
 /*   300 */    78,  112,   43,   81,  110,   57,   58,   59,   60,   61,
 /*   310 */     0,   63,   64,   65,   66,   67,   57,   58,   59,   60,
 /*   320 */    61,    0,   63,   64,   65,   66,   67,    9,   10,   11,
 /*   330 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   340 */    22,   91,   24,   13,   14,   15,   16,   17,   18,   19,
 /*   350 */    20,   21,   22,  103,   24,   70,   71,   72,   73,   74,
 /*   360 */    75,   76,   78,   79,    0,   81,   57,   58,   59,   48,
 /*   370 */    49,   88,   89,   90,   53,   54,   55,   32,   33,   34,
 /*   380 */    35,   86,   37,   38,   99,   81,   86,    0,    0,   86,
 /*   390 */   105,   78,   86,   80,   81,    0,   21,   22,  103,   24,
 /*   400 */    50,  106,  107,  103,    0,   86,  103,  112,    0,  103,
 /*   410 */    24,  111,  112,  113,  111,  112,  113,  111,  112,  113,
 /*   420 */    82,   86,  103,   85,   86,   26,    0,  108,  109,   94,
 /*   430 */    63,  112,   97,   44,   86,   86,   49,   49,  103,   40,
 /*   440 */    53,  103,   55,   55,   45,    0,   47,  112,   86,   43,
 /*   450 */   112,  103,  103,   49,   43,  107,   86,   49,   54,   55,
 /*   460 */   112,  112,  113,   55,   29,  103,   86,   97,   86,   86,
 /*   470 */    86,  109,   30,  103,  112,   49,   86,  101,  102,  103,
 /*   480 */    54,   55,  112,  103,  104,  103,  103,  103,   86,   86,
 /*   490 */    28,   86,  112,  103,  112,  112,  112,   28,   43,   86,
 /*   500 */    55,   86,  112,   86,   86,  103,  103,   86,  103,   86,
 /*   510 */    68,   86,    0,   44,  112,  112,  103,  112,  103,   86,
 /*   520 */   103,  103,   86,   86,  103,  112,  103,  112,  103,  112,
 /*   530 */   112,   27,   28,  112,   86,  112,  103,  112,   86,  103,
 /*   540 */   103,   28,   86,   92,   93,  112,   86,   29,  112,  112,
 /*   550 */    28,  103,   86,   86,   86,  103,   86,   44,   86,  103,
 /*   560 */   112,   30,    0,  103,  112,    0,   44,   55,  112,  103,
 /*   570 */   103,  103,  112,  103,   43,  103,   86,    0,  112,  112,
 /*   580 */   112,   86,  112,   86,  112,   29,   86,   31,   86,   86,
 /*   590 */     0,   30,   87,  103,    0,   39,   91,   87,  103,   68,
 /*   600 */   103,   91,  112,  103,   43,  103,  103,  112,  103,  112,
 /*   610 */    48,   28,  112,  103,  112,  112,    0,   55,    0,   32,
 /*   620 */    55,   17,   87,   36,   32,   48,   91,   44,   36,   68,
 /*   630 */    32,   91,   55,   29,   36,   42,   43,   95,  103,   28,
 /*   640 */    98,   28,   30,  103,   44,   55,  102,  103,   29,   55,
 /*   650 */    29,   29,   43,   81,    0,   44,    0,   44,    0,   28,
 /*   660 */    50,   81,    0,   81,    0,   81,    0,    0,    0,   49,
 /*   670 */    55,   55,   81,   55,   78,    0,    0,   29,   39,   93,
 /*   680 */    29,   29,   32,   41,   29,   32,   29,   43,   29,    0,
 /*   690 */    29,   42,   32,    0,   29,   32,    0,   98,   29,   29,
 /*   700 */     0,   29,   29,   32,    0,  100,   29,   29,   28,    3,
 /*   710 */     0,  110,    0,   27,  100,  114,  114,   43,  114,  114,
 /*   720 */   114,  114,  114,  114,  114,   46,
};
#define YY_SHIFT_USE_DFLT (-2)
static short yy_shift_ofst[] = {
 /*     0 */   399,   47,   79,   86,  181,  205,  321,  387,  152,  238,
 /*    10 */   309,  213,  309,  290,   -2,   -2,   -2,  309,  310,  404,
 /*    20 */   388,  445,  364,  395,  350,  259,  462,  259,   -2,   -1,
 /*    30 */    -2,   -2,  259,  259,  375,  259,  375,  259,  134,  259,
 /*    40 */   134,  259,  134,  259,  127,  259,  127,  259,  215,  259,
 /*    50 */   215,  259,  215,  259,  318,  259,  318,  259,  318,  259,
 /*    60 */   318,  259,  318,  259,  318,  259,  330,  275,  259,  386,
 /*    70 */   259,  330,  406,  197,  158,  259,  158,  203,   -2,  367,
 /*    80 */    -2,  259,  180,  411,  259,   56,  435,  389,   -2,  455,
 /*    90 */   259,   88,  518,  600,   -2,   -2,  531,  186,  469,   -2,
 /*   100 */   197,   -2,   -2,  259,    0,  259,  386,  259,  386,  259,
 /*   110 */   113,   -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,
 /*   120 */    -2,   -2,   -2,  619,  612,  621,   -2,  622,   -2,  522,
 /*   130 */    -2,  259,  386,  609,  197,  583,   -2,  375,   -2,  512,
 /*   140 */   654,  656,  259,  158,  658,  610,  259,  631,  259,   -2,
 /*   150 */   158,   -2,  565,  662,  426,  590,  664,  408,  594,  666,
 /*   160 */   667,  668,  620,  615,  675,  676,  259,  158,  248,  504,
 /*   170 */   648,  261,  345,   -2,   -2,  648,  556,  639,   -2,  259,
 /*   180 */   158,   -2,  651,   -2,   -2,   -2,  442,  652,  650,  655,
 /*   190 */   653,  657,  587,  659,  660,  661,  592,  665,  663,  669,
 /*   200 */   598,  670,  671,  672,  648,   -2,   25,  673,   -2,   -2,
 /*   210 */    -2,   -2,  248,   -2,   -2,  561,  604,   -2,   24,  677,
 /*   220 */    -2,   -2,   -2,  642,  648,  593,  644,  259,  513,  689,
 /*   230 */   259,   -2,  158,   -2,  678,  611,  649,  674,  259,  613,
 /*   240 */   693,  678,   -2,   -2,   -2,  562,  616,  696,  309,  700,
 /*   250 */   704,  648,  679,  648,  680,  648,   -2,  706,  259,   -2,
 /*   260 */   158,   -2,  577,  618,  710,  712,  686,  648,   -2,
};
#define YY_REDUCE_USE_DFLT (-30)
static short yy_reduce_ofst[] = {
 /*     0 */   285,  -30,  -30,  -30,  -30,  -30,    4,  284,  137,  -30,
 /*    10 */   132,  -30,  138,  -30,  -30,  -30,  -30,  194,  -30,  200,
 /*    20 */   -29,  304,  -30,  -30,  -30,  295,  -30,  348,  -30,  -30,
 /*    30 */   -30,  -30,  382,  383,  -30,  384,  -30,  390,  -30,  402,
 /*    40 */   -30,  403,  -30,  405,  -30,  413,  -30,  415,  -30,  417,
 /*    50 */   -30,  418,  -30,  421,  -30,  423,  -30,  425,  -30,  433,
 /*    60 */   -30,  436,  -30,  437,  -30,  448,  -30,  -30,  452,  -30,
 /*    70 */   456,  -30,  -30,  300,  -30,  460,  -30,  -30,  -30,  -30,
 /*    80 */   -30,  466,  -30,  -30,  467,  -30,  -30,  -30,  -30,  -30,
 /*    90 */   468,  -30,  -30,  -30,  -30,  -30,  -30,  303,  -30,  -30,
 /*   100 */   349,  -30,  -30,  470,  -30,  472,  -30,  490,  -30,  495,
 /*   110 */   -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,
 /*   120 */   -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,
 /*   130 */   -30,  497,  -30,  -30,  306,  -30,  -30,  -30,  -30,  572,
 /*   140 */   -30,  -30,  500,  -30,  -30,  -30,  319,  -30,  362,  -30,
 /*   150 */   -30,  -30,  580,  -30,  313,  582,  -30,  222,  584,  -30,
 /*   160 */   -30,  -30,  596,  591,  -30,  -30,  502,  -30,  338,  -30,
 /*   170 */   125,  135,  283,  -30,  -30,  250,  451,  586,  -30,  503,
 /*   180 */   -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,
 /*   190 */   -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,
 /*   200 */   -30,  -30,  -30,  -30,  505,  -30,  -30,  -30,  -30,  -30,
 /*   210 */   -30,  -30,  189,  -30,  -30,  -30,  -30,  -30,  -30,  -30,
 /*   220 */   -30,  -30,  -30,  -30,  540,  -30,  -30,  173,  -30,  -30,
 /*   230 */   370,  -30,  -30,  -30,  542,  -30,  -30,  -30,  335,  -30,
 /*   240 */   -30,  599,  -30,  -30,  -30,   11,  605,  -30,  601,  -30,
 /*   250 */   -30,  510,  -30,  376,  -30,  544,  -30,  -30,  380,  -30,
 /*   260 */   -30,  -30,   36,  614,  -30,  -30,  -30,  535,  -30,
};
static YYACTIONTYPE yy_default[] = {
 /*     0 */   427,  427,  427,  427,  427,  427,  427,  427,  427,  427,
 /*    10 */   427,  427,  427,  427,  371,  372,  373,  427,  427,  427,
 /*    20 */   427,  427,  427,  427,  427,  427,  356,  427,  357,  359,
 /*    30 */   360,  361,  427,  427,  374,  427,  376,  427,  377,  427,
 /*    40 */   378,  427,  379,  427,  380,  427,  381,  427,  382,  427,
 /*    50 */   383,  427,  384,  427,  385,  427,  386,  427,  387,  427,
 /*    60 */   388,  427,  389,  427,  390,  427,  391,  427,  427,  392,
 /*    70 */   427,  393,  427,  427,  406,  427,  397,  427,  407,  427,
 /*    80 */   408,  427,  410,  427,  427,  427,  427,  427,  398,  427,
 /*    90 */   427,  427,  427,  427,  399,  400,  426,  427,  427,  401,
 /*   100 */   427,  403,  405,  427,  409,  427,  411,  427,  412,  427,
 /*   110 */   427,  413,  414,  415,  416,  417,  418,  419,  420,  421,
 /*   120 */   422,  402,  404,  427,  424,  427,  423,  427,  425,  427,
 /*   130 */   395,  427,  394,  427,  427,  427,  396,  375,  358,  427,
 /*   140 */   427,  427,  427,  366,  427,  427,  427,  362,  427,  363,
 /*   150 */   365,  364,  427,  427,  427,  427,  427,  427,  427,  427,
 /*   160 */   427,  427,  427,  427,  427,  427,  427,  355,  427,  427,
 /*   170 */   427,  299,  300,  310,  312,  427,  313,  314,  316,  427,
 /*   180 */   328,  315,  427,  317,  318,  354,  426,  427,  427,  427,
 /*   190 */   427,  427,  427,  427,  427,  427,  427,  427,  427,  427,
 /*   200 */   427,  427,  427,  427,  427,  308,  353,  427,  351,  352,
 /*   210 */   311,  309,  427,  301,  303,  426,  427,  304,  307,  427,
 /*   220 */   305,  306,  302,  427,  427,  427,  427,  427,  427,  427,
 /*   230 */   427,  331,  333,  332,  427,  427,  427,  427,  427,  427,
 /*   240 */   427,  427,  334,  336,  335,  427,  427,  427,  427,  427,
 /*   250 */   427,  427,  427,  427,  341,  427,  342,  427,  427,  344,
 /*   260 */   345,  343,  427,  427,  427,  427,  427,  427,  350,
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
  "OFFSET",        "INTEGER",       "NPLACEHOLDER",  "SPLACEHOLDER",
  "CAST",          "CONVERT",       "USING",         "NULL",        
  "STRING",        "DOUBLE",        "TRUE",          "FALSE",       
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
  "group_list",    "group_item",    "integer_or_placeholder",  "argument_list",
  "function_call",  "argument_item",
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
 /*  23 */ "select_statement ::= select_clause having_clause order_clause select_limit_clause",
 /*  24 */ "select_statement ::= select_clause group_clause",
 /*  25 */ "select_statement ::= select_clause group_clause select_limit_clause",
 /*  26 */ "select_statement ::= select_clause group_clause having_clause",
 /*  27 */ "select_statement ::= select_clause group_clause having_clause select_limit_clause",
 /*  28 */ "select_statement ::= select_clause group_clause having_clause order_clause select_limit_clause",
 /*  29 */ "select_statement ::= select_clause select_limit_clause",
 /*  30 */ "select_clause ::= SELECT column_list FROM associated_name_list",
 /*  31 */ "select_clause ::= SELECT column_list FROM associated_name_list join_list",
 /*  32 */ "column_list ::= column_list COMMA column_item",
 /*  33 */ "column_list ::= column_item",
 /*  34 */ "column_item ::= TIMES",
 /*  35 */ "column_item ::= IDENTIFIER DOT TIMES",
 /*  36 */ "column_item ::= expr AS IDENTIFIER",
 /*  37 */ "column_item ::= expr IDENTIFIER",
 /*  38 */ "column_item ::= expr",
 /*  39 */ "associated_name_list ::= associated_name_list COMMA associated_name",
 /*  40 */ "associated_name_list ::= associated_name",
 /*  41 */ "join_list ::= join_list join_item",
 /*  42 */ "join_list ::= join_item",
 /*  43 */ "join_item ::= join_clause",
 /*  44 */ "join_clause ::= join_type aliased_or_qualified_name",
 /*  45 */ "join_clause ::= join_type aliased_or_qualified_name join_associated_name",
 /*  46 */ "join_clause ::= join_type aliased_or_qualified_name join_conditions",
 /*  47 */ "join_clause ::= join_type aliased_or_qualified_name join_associated_name join_conditions",
 /*  48 */ "join_associated_name ::= AS IDENTIFIER",
 /*  49 */ "join_associated_name ::= IDENTIFIER",
 /*  50 */ "join_type ::= JOIN",
 /*  51 */ "join_type ::= INNER JOIN",
 /*  52 */ "join_type ::= CROSS JOIN",
 /*  53 */ "join_type ::= LEFT JOIN",
 /*  54 */ "join_type ::= LEFT OUTER JOIN",
 /*  55 */ "join_type ::= RIGHT JOIN",
 /*  56 */ "join_type ::= RIGHT OUTER JOIN",
 /*  57 */ "join_type ::= FULL JOIN",
 /*  58 */ "join_type ::= FULL OUTER JOIN",
 /*  59 */ "join_conditions ::= ON expr",
 /*  60 */ "insert_statement ::= INSERT INTO aliased_or_qualified_name VALUES PARENTHESES_OPEN values_list PARENTHESES_CLOSE",
 /*  61 */ "insert_statement ::= INSERT INTO aliased_or_qualified_name PARENTHESES_OPEN field_list PARENTHESES_CLOSE VALUES PARENTHESES_OPEN values_list PARENTHESES_CLOSE",
 /*  62 */ "values_list ::= values_list COMMA value_item",
 /*  63 */ "values_list ::= value_item",
 /*  64 */ "value_item ::= expr",
 /*  65 */ "field_list ::= field_list COMMA field_item",
 /*  66 */ "field_list ::= field_item",
 /*  67 */ "field_item ::= IDENTIFIER",
 /*  68 */ "update_statement ::= update_clause",
 /*  69 */ "update_statement ::= update_clause where_clause",
 /*  70 */ "update_statement ::= update_clause limit_clause",
 /*  71 */ "update_statement ::= update_clause where_clause limit_clause",
 /*  72 */ "update_clause ::= UPDATE associated_name SET update_item_list",
 /*  73 */ "update_item_list ::= update_item_list COMMA update_item",
 /*  74 */ "update_item_list ::= update_item",
 /*  75 */ "update_item ::= qualified_name EQUALS new_value",
 /*  76 */ "new_value ::= expr",
 /*  77 */ "delete_statement ::= delete_clause",
 /*  78 */ "delete_statement ::= delete_clause where_clause",
 /*  79 */ "delete_statement ::= delete_clause limit_clause",
 /*  80 */ "delete_statement ::= delete_clause where_clause limit_clause",
 /*  81 */ "delete_clause ::= DELETE FROM associated_name",
 /*  82 */ "associated_name ::= aliased_or_qualified_name AS IDENTIFIER",
 /*  83 */ "associated_name ::= aliased_or_qualified_name IDENTIFIER",
 /*  84 */ "associated_name ::= aliased_or_qualified_name",
 /*  85 */ "aliased_or_qualified_name ::= qualified_name",
 /*  86 */ "where_clause ::= WHERE expr",
 /*  87 */ "order_clause ::= ORDER BY order_list",
 /*  88 */ "order_list ::= order_list COMMA order_item",
 /*  89 */ "order_list ::= order_item",
 /*  90 */ "order_item ::= expr",
 /*  91 */ "order_item ::= expr ASC",
 /*  92 */ "order_item ::= expr DESC",
 /*  93 */ "group_clause ::= GROUP BY group_list",
 /*  94 */ "group_list ::= group_list COMMA group_item",
 /*  95 */ "group_list ::= group_item",
 /*  96 */ "group_item ::= expr",
 /*  97 */ "having_clause ::= HAVING expr",
 /*  98 */ "select_limit_clause ::= LIMIT integer_or_placeholder",
 /*  99 */ "select_limit_clause ::= LIMIT integer_or_placeholder COMMA integer_or_placeholder",
 /* 100 */ "select_limit_clause ::= LIMIT integer_or_placeholder OFFSET integer_or_placeholder",
 /* 101 */ "limit_clause ::= LIMIT integer_or_placeholder",
 /* 102 */ "integer_or_placeholder ::= INTEGER",
 /* 103 */ "integer_or_placeholder ::= NPLACEHOLDER",
 /* 104 */ "integer_or_placeholder ::= SPLACEHOLDER",
 /* 105 */ "expr ::= MINUS expr",
 /* 106 */ "expr ::= expr MINUS expr",
 /* 107 */ "expr ::= expr PLUS expr",
 /* 108 */ "expr ::= expr TIMES expr",
 /* 109 */ "expr ::= expr DIVIDE expr",
 /* 110 */ "expr ::= expr MOD expr",
 /* 111 */ "expr ::= expr AND expr",
 /* 112 */ "expr ::= expr OR expr",
 /* 113 */ "expr ::= expr BITWISE_AND expr",
 /* 114 */ "expr ::= expr BITWISE_OR expr",
 /* 115 */ "expr ::= expr BITWISE_XOR expr",
 /* 116 */ "expr ::= expr EQUALS expr",
 /* 117 */ "expr ::= expr NOTEQUALS expr",
 /* 118 */ "expr ::= expr LESS expr",
 /* 119 */ "expr ::= expr GREATER expr",
 /* 120 */ "expr ::= expr GREATEREQUAL expr",
 /* 121 */ "expr ::= expr LESSEQUAL expr",
 /* 122 */ "expr ::= expr LIKE expr",
 /* 123 */ "expr ::= expr NOT LIKE expr",
 /* 124 */ "expr ::= expr ILIKE expr",
 /* 125 */ "expr ::= expr NOT ILIKE expr",
 /* 126 */ "expr ::= expr IN PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 127 */ "expr ::= expr NOT IN PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 128 */ "expr ::= expr AGAINST expr",
 /* 129 */ "expr ::= CAST PARENTHESES_OPEN expr AS IDENTIFIER PARENTHESES_CLOSE",
 /* 130 */ "expr ::= CONVERT PARENTHESES_OPEN expr USING IDENTIFIER PARENTHESES_CLOSE",
 /* 131 */ "expr ::= function_call",
 /* 132 */ "function_call ::= IDENTIFIER PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 133 */ "function_call ::= IDENTIFIER PARENTHESES_OPEN PARENTHESES_CLOSE",
 /* 134 */ "argument_list ::= argument_list COMMA argument_item",
 /* 135 */ "argument_list ::= argument_item",
 /* 136 */ "argument_item ::= TIMES",
 /* 137 */ "argument_item ::= expr",
 /* 138 */ "expr ::= expr IS NULL",
 /* 139 */ "expr ::= expr IS NOT NULL",
 /* 140 */ "expr ::= DISTINCT expr",
 /* 141 */ "expr ::= expr BETWEEN expr",
 /* 142 */ "expr ::= NOT expr",
 /* 143 */ "expr ::= BITWISE_NOT expr",
 /* 144 */ "expr ::= PARENTHESES_OPEN expr PARENTHESES_CLOSE",
 /* 145 */ "expr ::= qualified_name",
 /* 146 */ "expr ::= INTEGER",
 /* 147 */ "expr ::= STRING",
 /* 148 */ "expr ::= DOUBLE",
 /* 149 */ "expr ::= NULL",
 /* 150 */ "expr ::= TRUE",
 /* 151 */ "expr ::= FALSE",
 /* 152 */ "expr ::= NPLACEHOLDER",
 /* 153 */ "expr ::= SPLACEHOLDER",
 /* 154 */ "qualified_name ::= IDENTIFIER COLON IDENTIFIER DOT IDENTIFIER",
 /* 155 */ "qualified_name ::= IDENTIFIER COLON IDENTIFIER",
 /* 156 */ "qualified_name ::= IDENTIFIER DOT IDENTIFIER",
 /* 157 */ "qualified_name ::= IDENTIFIER",
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
// 511 "parser.lemon"
{
	if ((yypminor->yy0)) {
		if ((yypminor->yy0)->free_flag) {
			efree((yypminor->yy0)->token);
		}
		efree((yypminor->yy0));
	}
}
// 1183 "parser.c"
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
    case 111:
    case 112:
    case 113:
// 524 "parser.lemon"
{ zval_ptr_dtor(&(yypminor->yy48)); }
// 1226 "parser.c"
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
  { 72, 4 },
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
  { 110, 1 },
  { 110, 1 },
  { 110, 1 },
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
  { 112, 4 },
  { 112, 3 },
  { 111, 3 },
  { 111, 1 },
  { 113, 1 },
  { 113, 1 },
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
// 520 "parser.lemon"
{
	status->ret = yymsp[0].minor.yy48;
}
// 1601 "parser.c"
        break;
      case 1:
      case 2:
      case 3:
      case 4:
      case 33:
      case 40:
      case 42:
      case 43:
      case 63:
      case 64:
      case 66:
      case 74:
      case 76:
      case 85:
      case 89:
      case 95:
      case 96:
      case 131:
      case 137:
      case 145:
// 526 "parser.lemon"
{
	yygotominor.yy48 = yymsp[0].minor.yy48;
}
// 1627 "parser.c"
        break;
      case 5:
// 544 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[0].minor.yy48, NULL, NULL, NULL, NULL, NULL);
}
// 1634 "parser.c"
        break;
      case 6:
// 548 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL, NULL, NULL, NULL);
}
// 1641 "parser.c"
        break;
      case 7:
// 552 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL, NULL, NULL);
}
// 1648 "parser.c"
        break;
      case 8:
// 556 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy48, NULL, NULL);
}
// 1655 "parser.c"
        break;
      case 9:
// 560 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, yymsp[-2].minor.yy48, NULL, yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL);
}
// 1662 "parser.c"
        break;
      case 10:
// 564 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, yymsp[-2].minor.yy48, yymsp[0].minor.yy48, yymsp[-1].minor.yy48, NULL, NULL);
}
// 1669 "parser.c"
        break;
      case 11:
// 568 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-4].minor.yy48, yymsp[-3].minor.yy48, yymsp[-1].minor.yy48, yymsp[-2].minor.yy48, NULL, yymsp[0].minor.yy48);
}
// 1676 "parser.c"
        break;
      case 12:
// 572 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-4].minor.yy48, yymsp[-3].minor.yy48, yymsp[0].minor.yy48, yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, NULL);
}
// 1683 "parser.c"
        break;
      case 13:
// 576 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, NULL, NULL, NULL, yymsp[0].minor.yy48);
}
// 1690 "parser.c"
        break;
      case 14:
// 580 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, NULL, NULL, yymsp[0].minor.yy48);
}
// 1697 "parser.c"
        break;
      case 15:
// 584 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, yymsp[-2].minor.yy48, NULL, yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy48);
}
// 1704 "parser.c"
        break;
      case 16:
// 588 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-4].minor.yy48, yymsp[-3].minor.yy48, NULL, yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
}
// 1711 "parser.c"
        break;
      case 17:
// 592 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy48, NULL, NULL, NULL);
}
// 1718 "parser.c"
        break;
      case 18:
// 596 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-2].minor.yy48, NULL, yymsp[0].minor.yy48, yymsp[-1].minor.yy48, NULL, NULL);
}
// 1725 "parser.c"
        break;
      case 19:
// 600 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, NULL, yymsp[0].minor.yy48, yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, NULL);
}
// 1732 "parser.c"
        break;
      case 20:
// 604 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-2].minor.yy48, NULL, yymsp[-1].minor.yy48, NULL, NULL, yymsp[0].minor.yy48);
}
// 1739 "parser.c"
        break;
      case 21:
// 608 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, NULL, yymsp[-1].minor.yy48, yymsp[-2].minor.yy48, NULL, yymsp[0].minor.yy48);
}
// 1746 "parser.c"
        break;
      case 22:
// 612 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-5].minor.yy48, yymsp[-4].minor.yy48, yymsp[-1].minor.yy48, yymsp[-3].minor.yy48, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
}
// 1753 "parser.c"
        break;
      case 23:
// 616 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, NULL, yymsp[-1].minor.yy48, NULL, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
}
// 1760 "parser.c"
        break;
      case 24:
// 620 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-1].minor.yy48, NULL, NULL, yymsp[0].minor.yy48, NULL, NULL);
}
// 1767 "parser.c"
        break;
      case 25:
// 624 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-2].minor.yy48, NULL, NULL, yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy48);
}
// 1774 "parser.c"
        break;
      case 26:
// 628 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-2].minor.yy48, NULL, NULL, yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL);
}
// 1781 "parser.c"
        break;
      case 27:
// 632 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, NULL, NULL, yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
}
// 1788 "parser.c"
        break;
      case 28:
// 636 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-4].minor.yy48, NULL, yymsp[-1].minor.yy48, yymsp[-3].minor.yy48, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
}
// 1795 "parser.c"
        break;
      case 29:
// 640 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-1].minor.yy48, NULL, NULL, NULL, NULL, yymsp[0].minor.yy48);
}
// 1802 "parser.c"
        break;
      case 30:
// 646 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_clause(yymsp[-2].minor.yy48, yymsp[0].minor.yy48, NULL);
  yy_destructor(26,&yymsp[-3].minor);
  yy_destructor(27,&yymsp[-1].minor);
}
// 1811 "parser.c"
        break;
      case 31:
// 650 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_clause(yymsp[-3].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(26,&yymsp[-4].minor);
  yy_destructor(27,&yymsp[-2].minor);
}
// 1820 "parser.c"
        break;
      case 32:
      case 39:
      case 62:
      case 65:
      case 73:
      case 88:
      case 94:
      case 134:
// 656 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_zval_list(yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(28,&yymsp[-1].minor);
}
// 1835 "parser.c"
        break;
      case 34:
      case 136:
// 666 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_column_item(PHQL_T_ALL, NULL, NULL, NULL);
  yy_destructor(17,&yymsp[0].minor);
}
// 1844 "parser.c"
        break;
      case 35:
// 670 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_column_item(PHQL_T_DOMAINALL, NULL, yymsp[-2].minor.yy0, NULL);
  yy_destructor(30,&yymsp[-1].minor);
  yy_destructor(17,&yymsp[0].minor);
}
// 1853 "parser.c"
        break;
      case 36:
// 674 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-2].minor.yy48, NULL, yymsp[0].minor.yy0);
  yy_destructor(31,&yymsp[-1].minor);
}
// 1861 "parser.c"
        break;
      case 37:
// 678 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy0);
}
// 1868 "parser.c"
        break;
      case 38:
// 682 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_column_item(PHQL_T_EXPR, yymsp[0].minor.yy48, NULL, NULL);
}
// 1875 "parser.c"
        break;
      case 41:
// 698 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_zval_list(yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
}
// 1882 "parser.c"
        break;
      case 44:
// 715 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_item(yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL, NULL);
}
// 1889 "parser.c"
        break;
      case 45:
// 720 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_item(yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL);
}
// 1896 "parser.c"
        break;
      case 46:
// 725 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_item(yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy48);
}
// 1903 "parser.c"
        break;
      case 47:
// 730 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_item(yymsp[-3].minor.yy48, yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
}
// 1910 "parser.c"
        break;
      case 48:
// 736 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_qualified_name(NULL, NULL, yymsp[0].minor.yy0);
  yy_destructor(31,&yymsp[-1].minor);
}
// 1918 "parser.c"
        break;
      case 49:
      case 67:
      case 157:
// 740 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_qualified_name(NULL, NULL, yymsp[0].minor.yy0);
}
// 1927 "parser.c"
        break;
      case 50:
// 746 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_INNERJOIN);
  yy_destructor(32,&yymsp[0].minor);
}
// 1935 "parser.c"
        break;
      case 51:
// 750 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_INNERJOIN);
  yy_destructor(33,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 1944 "parser.c"
        break;
      case 52:
// 754 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_CROSSJOIN);
  yy_destructor(34,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 1953 "parser.c"
        break;
      case 53:
// 758 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  yy_destructor(35,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 1962 "parser.c"
        break;
      case 54:
// 762 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 1972 "parser.c"
        break;
      case 55:
// 766 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  yy_destructor(37,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 1981 "parser.c"
        break;
      case 56:
// 770 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  yy_destructor(37,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 1991 "parser.c"
        break;
      case 57:
// 774 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_FULLJOIN);
  yy_destructor(38,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 2000 "parser.c"
        break;
      case 58:
// 778 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_type(PHQL_T_FULLJOIN);
  yy_destructor(38,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[-1].minor);
  yy_destructor(32,&yymsp[0].minor);
}
// 2010 "parser.c"
        break;
      case 59:
// 784 "parser.lemon"
{
	yygotominor.yy48 = yymsp[0].minor.yy48;
  yy_destructor(39,&yymsp[-1].minor);
}
// 2018 "parser.c"
        break;
      case 60:
// 791 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_insert_statement(yymsp[-4].minor.yy48, NULL, yymsp[-1].minor.yy48);
  yy_destructor(40,&yymsp[-6].minor);
  yy_destructor(41,&yymsp[-5].minor);
  yy_destructor(42,&yymsp[-3].minor);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2030 "parser.c"
        break;
      case 61:
// 795 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_insert_statement(yymsp[-7].minor.yy48, yymsp[-5].minor.yy48, yymsp[-1].minor.yy48);
  yy_destructor(40,&yymsp[-9].minor);
  yy_destructor(41,&yymsp[-8].minor);
  yy_destructor(43,&yymsp[-6].minor);
  yy_destructor(44,&yymsp[-4].minor);
  yy_destructor(42,&yymsp[-3].minor);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2044 "parser.c"
        break;
      case 68:
// 833 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_update_statement(yymsp[0].minor.yy48, NULL, NULL);
}
// 2051 "parser.c"
        break;
      case 69:
// 837 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_update_statement(yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL);
}
// 2058 "parser.c"
        break;
      case 70:
// 841 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_update_statement(yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy48);
}
// 2065 "parser.c"
        break;
      case 71:
// 845 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_update_statement(yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
}
// 2072 "parser.c"
        break;
      case 72:
// 851 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_update_clause(yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(45,&yymsp[-3].minor);
  yy_destructor(46,&yymsp[-1].minor);
}
// 2081 "parser.c"
        break;
      case 75:
// 867 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_update_item(yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(3,&yymsp[-1].minor);
}
// 2089 "parser.c"
        break;
      case 77:
// 879 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_delete_statement(yymsp[0].minor.yy48, NULL, NULL);
}
// 2096 "parser.c"
        break;
      case 78:
// 883 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_delete_statement(yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL);
}
// 2103 "parser.c"
        break;
      case 79:
// 887 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_delete_statement(yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy48);
}
// 2110 "parser.c"
        break;
      case 80:
// 891 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_delete_statement(yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
}
// 2117 "parser.c"
        break;
      case 81:
// 897 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_delete_clause(yymsp[0].minor.yy48);
  yy_destructor(47,&yymsp[-2].minor);
  yy_destructor(27,&yymsp[-1].minor);
}
// 2126 "parser.c"
        break;
      case 82:
// 903 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_assoc_name(yymsp[-2].minor.yy48, yymsp[0].minor.yy0);
  yy_destructor(31,&yymsp[-1].minor);
}
// 2134 "parser.c"
        break;
      case 83:
// 907 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_assoc_name(yymsp[-1].minor.yy48, yymsp[0].minor.yy0);
}
// 2141 "parser.c"
        break;
      case 84:
// 911 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_assoc_name(yymsp[0].minor.yy48, NULL);
}
// 2148 "parser.c"
        break;
      case 86:
// 923 "parser.lemon"
{
	yygotominor.yy48 = yymsp[0].minor.yy48;
  yy_destructor(48,&yymsp[-1].minor);
}
// 2156 "parser.c"
        break;
      case 87:
// 929 "parser.lemon"
{
	yygotominor.yy48 = yymsp[0].minor.yy48;
  yy_destructor(49,&yymsp[-2].minor);
  yy_destructor(50,&yymsp[-1].minor);
}
// 2165 "parser.c"
        break;
      case 90:
// 945 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_order_item(yymsp[0].minor.yy48, 0);
}
// 2172 "parser.c"
        break;
      case 91:
// 949 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_order_item(yymsp[-1].minor.yy48, PHQL_T_ASC);
  yy_destructor(51,&yymsp[0].minor);
}
// 2180 "parser.c"
        break;
      case 92:
// 953 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_order_item(yymsp[-1].minor.yy48, PHQL_T_DESC);
  yy_destructor(52,&yymsp[0].minor);
}
// 2188 "parser.c"
        break;
      case 93:
// 959 "parser.lemon"
{
	yygotominor.yy48 = yymsp[0].minor.yy48;
  yy_destructor(53,&yymsp[-2].minor);
  yy_destructor(50,&yymsp[-1].minor);
}
// 2197 "parser.c"
        break;
      case 97:
// 981 "parser.lemon"
{
	yygotominor.yy48 = yymsp[0].minor.yy48;
  yy_destructor(54,&yymsp[-1].minor);
}
// 2205 "parser.c"
        break;
      case 98:
      case 101:
// 987 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_limit_clause(yymsp[0].minor.yy48, NULL);
  yy_destructor(55,&yymsp[-1].minor);
}
// 2214 "parser.c"
        break;
      case 99:
// 991 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_limit_clause(yymsp[0].minor.yy48, yymsp[-2].minor.yy48);
  yy_destructor(55,&yymsp[-3].minor);
  yy_destructor(28,&yymsp[-1].minor);
}
// 2223 "parser.c"
        break;
      case 100:
// 995 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_limit_clause(yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(55,&yymsp[-3].minor);
  yy_destructor(56,&yymsp[-1].minor);
}
// 2232 "parser.c"
        break;
      case 102:
      case 146:
// 1005 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_literal_zval(PHQL_T_INTEGER, yymsp[0].minor.yy0);
}
// 2240 "parser.c"
        break;
      case 103:
      case 152:
// 1009 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_placeholder_zval(PHQL_T_NPLACEHOLDER, yymsp[0].minor.yy0);
}
// 2248 "parser.c"
        break;
      case 104:
      case 153:
// 1013 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_placeholder_zval(PHQL_T_SPLACEHOLDER, yymsp[0].minor.yy0);
}
// 2256 "parser.c"
        break;
      case 105:
// 1019 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_MINUS, NULL, yymsp[0].minor.yy48);
  yy_destructor(20,&yymsp[-1].minor);
}
// 2264 "parser.c"
        break;
      case 106:
// 1023 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_SUB, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(20,&yymsp[-1].minor);
}
// 2272 "parser.c"
        break;
      case 107:
// 1027 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_ADD, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(19,&yymsp[-1].minor);
}
// 2280 "parser.c"
        break;
      case 108:
// 1031 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_MUL, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(17,&yymsp[-1].minor);
}
// 2288 "parser.c"
        break;
      case 109:
// 1035 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_DIV, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(16,&yymsp[-1].minor);
}
// 2296 "parser.c"
        break;
      case 110:
// 1039 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_MOD, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(18,&yymsp[-1].minor);
}
// 2304 "parser.c"
        break;
      case 111:
// 1043 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_AND, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(9,&yymsp[-1].minor);
}
// 2312 "parser.c"
        break;
      case 112:
// 1047 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_OR, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(10,&yymsp[-1].minor);
}
// 2320 "parser.c"
        break;
      case 113:
// 1051 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_BITWISE_AND, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(13,&yymsp[-1].minor);
}
// 2328 "parser.c"
        break;
      case 114:
// 1055 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_BITWISE_OR, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(14,&yymsp[-1].minor);
}
// 2336 "parser.c"
        break;
      case 115:
// 1059 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_BITWISE_XOR, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(15,&yymsp[-1].minor);
}
// 2344 "parser.c"
        break;
      case 116:
// 1063 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_EQUALS, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(3,&yymsp[-1].minor);
}
// 2352 "parser.c"
        break;
      case 117:
// 1067 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_NOTEQUALS, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(4,&yymsp[-1].minor);
}
// 2360 "parser.c"
        break;
      case 118:
// 1071 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_LESS, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(5,&yymsp[-1].minor);
}
// 2368 "parser.c"
        break;
      case 119:
// 1075 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_GREATER, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(6,&yymsp[-1].minor);
}
// 2376 "parser.c"
        break;
      case 120:
// 1079 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_GREATEREQUAL, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(7,&yymsp[-1].minor);
}
// 2384 "parser.c"
        break;
      case 121:
// 1083 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_LESSEQUAL, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(8,&yymsp[-1].minor);
}
// 2392 "parser.c"
        break;
      case 122:
// 1087 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_LIKE, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(11,&yymsp[-1].minor);
}
// 2400 "parser.c"
        break;
      case 123:
// 1091 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_NLIKE, yymsp[-3].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(24,&yymsp[-2].minor);
  yy_destructor(11,&yymsp[-1].minor);
}
// 2409 "parser.c"
        break;
      case 124:
// 1095 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_ILIKE, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(12,&yymsp[-1].minor);
}
// 2417 "parser.c"
        break;
      case 125:
// 1099 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_NILIKE, yymsp[-3].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(24,&yymsp[-2].minor);
  yy_destructor(12,&yymsp[-1].minor);
}
// 2426 "parser.c"
        break;
      case 126:
// 1103 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_IN, yymsp[-4].minor.yy48, yymsp[-1].minor.yy48);
  yy_destructor(22,&yymsp[-3].minor);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2436 "parser.c"
        break;
      case 127:
// 1107 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_NOTIN, yymsp[-5].minor.yy48, yymsp[-1].minor.yy48);
  yy_destructor(24,&yymsp[-4].minor);
  yy_destructor(22,&yymsp[-3].minor);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2447 "parser.c"
        break;
      case 128:
// 1111 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_AGAINST, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(1,&yymsp[-1].minor);
}
// 2455 "parser.c"
        break;
      case 129:
// 1115 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_CAST, yymsp[-3].minor.yy48, phql_ret_raw_qualified_name(yymsp[-1].minor.yy0, NULL));
  yy_destructor(60,&yymsp[-5].minor);
  yy_destructor(43,&yymsp[-4].minor);
  yy_destructor(31,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2466 "parser.c"
        break;
      case 130:
// 1119 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_CONVERT, yymsp[-3].minor.yy48, phql_ret_raw_qualified_name(yymsp[-1].minor.yy0, NULL));
  yy_destructor(61,&yymsp[-5].minor);
  yy_destructor(43,&yymsp[-4].minor);
  yy_destructor(62,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2477 "parser.c"
        break;
      case 132:
// 1129 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_func_call(yymsp[-3].minor.yy0, yymsp[-1].minor.yy48);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2486 "parser.c"
        break;
      case 133:
// 1133 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_func_call(yymsp[-2].minor.yy0, NULL);
  yy_destructor(43,&yymsp[-1].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2495 "parser.c"
        break;
      case 135:
// 1143 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_zval_list(yymsp[0].minor.yy48, NULL);
}
// 2502 "parser.c"
        break;
      case 138:
// 1157 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_ISNULL, yymsp[-2].minor.yy48, NULL);
  yy_destructor(21,&yymsp[-1].minor);
  yy_destructor(63,&yymsp[0].minor);
}
// 2511 "parser.c"
        break;
      case 139:
// 1161 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_ISNOTNULL, yymsp[-3].minor.yy48, NULL);
  yy_destructor(21,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
  yy_destructor(63,&yymsp[0].minor);
}
// 2521 "parser.c"
        break;
      case 140:
// 1165 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_DISTINCT, NULL, yymsp[0].minor.yy48);
  yy_destructor(23,&yymsp[-1].minor);
}
// 2529 "parser.c"
        break;
      case 141:
// 1169 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_BETWEEN, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(2,&yymsp[-1].minor);
}
// 2537 "parser.c"
        break;
      case 142:
// 1173 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_NOT, NULL, yymsp[0].minor.yy48);
  yy_destructor(24,&yymsp[-1].minor);
}
// 2545 "parser.c"
        break;
      case 143:
// 1177 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_BITWISE_NOT, NULL, yymsp[0].minor.yy48);
  yy_destructor(25,&yymsp[-1].minor);
}
// 2553 "parser.c"
        break;
      case 144:
// 1181 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_ENCLOSED, yymsp[-1].minor.yy48, NULL);
  yy_destructor(43,&yymsp[-2].minor);
  yy_destructor(44,&yymsp[0].minor);
}
// 2562 "parser.c"
        break;
      case 147:
// 1193 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_literal_zval(PHQL_T_STRING, yymsp[0].minor.yy0);
}
// 2569 "parser.c"
        break;
      case 148:
// 1197 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_literal_zval(PHQL_T_DOUBLE, yymsp[0].minor.yy0);
}
// 2576 "parser.c"
        break;
      case 149:
// 1201 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_literal_zval(PHQL_T_NULL, NULL);
  yy_destructor(63,&yymsp[0].minor);
}
// 2584 "parser.c"
        break;
      case 150:
// 1205 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_literal_zval(PHQL_T_TRUE, NULL);
  yy_destructor(66,&yymsp[0].minor);
}
// 2592 "parser.c"
        break;
      case 151:
// 1209 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_literal_zval(PHQL_T_FALSE, NULL);
  yy_destructor(67,&yymsp[0].minor);
}
// 2600 "parser.c"
        break;
      case 154:
// 1223 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_qualified_name(yymsp[-4].minor.yy0, yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(68,&yymsp[-3].minor);
  yy_destructor(30,&yymsp[-1].minor);
}
// 2609 "parser.c"
        break;
      case 155:
// 1227 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_qualified_name(yymsp[-2].minor.yy0, NULL, yymsp[0].minor.yy0);
  yy_destructor(68,&yymsp[-1].minor);
}
// 2617 "parser.c"
        break;
      case 156:
// 1231 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_qualified_name(NULL, yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(30,&yymsp[-1].minor);
}
// 2625 "parser.c"
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
// 444 "parser.lemon"

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

// 2734 "parser.c"
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
