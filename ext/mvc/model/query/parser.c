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

static zval *phql_ret_qualified_name(phql_parser_token *A, phql_parser_token *B)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", PHQL_T_QUALIFIED);
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


// 390 "parser.c"
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
#define YYNOCODE 106
#define YYACTIONTYPE unsigned short int
#define phql_TOKENTYPE phql_parser_token*
typedef union {
  phql_TOKENTYPE yy0;
  zval* yy78;
  int yy211;
} YYMINORTYPE;
#define YYSTACKDEPTH 100
#define phql_ARG_SDECL phql_parser_status *status;
#define phql_ARG_PDECL ,phql_parser_status *status
#define phql_ARG_FETCH phql_parser_status *status = yypParser->status
#define phql_ARG_STORE yypParser->status = status
#define YYNSTATE 241
#define YYNRULE 147
#define YYERRORSYMBOL 61
#define YYERRSYMDT yy211
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
 /*     0 */    85,   59,   61,   63,   65,   67,   69,   51,   53,   71,
 /*    10 */    76,   55,   57,   47,   45,   49,   43,   40,   81,   78,
 /*    20 */   241,   73,    7,  129,  131,  193,  139,  191,   85,   59,
 /*    30 */    61,   63,   65,   67,   69,   51,   53,   71,   76,   55,
 /*    40 */    57,   47,   45,   49,   43,   40,   81,   78,  242,   73,
 /*    50 */    51,   53,   71,   76,   55,   57,   47,   45,   49,   43,
 /*    60 */    40,   81,   78,   78,   73,   73,    8,   16,  101,  120,
 /*    70 */   243,   85,   59,   61,   63,   65,   67,   69,   51,   53,
 /*    80 */    71,   76,   55,   57,   47,   45,   49,   43,   40,   81,
 /*    90 */    78,  340,   73,   59,   61,   63,   65,   67,   69,   51,
 /*   100 */    53,   71,   76,   55,   57,   47,   45,   49,   43,   40,
 /*   110 */    81,   78,   94,   73,  244,   41,  146,   12,   95,   97,
 /*   120 */   182,  148,  149,   88,   71,   76,   55,   57,   47,   45,
 /*   130 */    49,   43,   40,   81,   78,   29,   73,   99,  109,  389,
 /*   140 */     1,    2,    3,    4,    5,    6,   14,  103,    9,   23,
 /*   150 */    34,   26,  106,  104,  105,  107,  108,   47,   45,   49,
 /*   160 */    43,   40,   81,   78,   94,   73,  248,   41,  217,  246,
 /*   170 */    95,   97,  176,  234,  245,   88,  159,  160,  162,  164,
 /*   180 */    18,  168,  172,   20,  186,   81,   78,   41,   73,   99,
 /*   190 */    95,   97,  229,  143,  126,  187,  194,  190,   35,  103,
 /*   200 */    17,   37,  102,  228,  106,  104,  105,  107,  108,   99,
 /*   210 */    41,  123,  128,   95,   97,  140,   21,  255,   88,  103,
 /*   220 */    10,  121,   87,   10,  106,  104,  105,  107,  108,   31,
 /*   230 */    29,   32,   99,   55,   57,   47,   45,   49,   43,   40,
 /*   240 */    81,   78,  103,   73,   89,   25,   26,  106,  104,  105,
 /*   250 */   107,  108,   92,   30,   80,  159,  160,  162,  164,  102,
 /*   260 */   168,  172,   43,   40,   81,   78,   80,   73,   91,   11,
 /*   270 */    80,  102,  247,   74,  113,  102,  204,  308,  111,   87,
 /*   280 */   110,  102,  249,  115,  200,  142,  264,  205,   80,  341,
 /*   290 */    90,   87,  110,  102,  117,   87,  110,  204,  250,  195,
 /*   300 */   135,   87,  102,  137,  223,  211,  238,  132,  205,  134,
 /*   310 */   138,  185,  190,   87,   93,  342,  204,  102,  158,   21,
 /*   320 */   156,  102,   87,  140,  121,   39,   10,  203,  153,   21,
 /*   330 */   102,  220,   19,   21,   31,   38,   10,   87,  232,   38,
 /*   340 */    10,   87,  119,  102,   42,   21,   44,  102,  266,  102,
 /*   350 */    87,  102,   10,  218,   46,  231,  145,   48,  127,  102,
 /*   360 */   183,   50,  102,   87,  178,   52,  102,   87,   13,   87,
 /*   370 */   102,   87,   54,   56,   83,   58,  222,  102,  102,   87,
 /*   380 */   102,  253,   87,   60,   62,   15,   87,   64,  102,  102,
 /*   390 */    87,   66,  102,  229,  251,   21,  102,   87,   87,  263,
 /*   400 */    87,   68,   10,  226,  233,   70,  102,   82,   87,   87,
 /*   410 */   102,  317,   87,  257,   72,   75,   87,   77,   86,  102,
 /*   420 */   102,  165,  102,  102,   96,  166,   87,  141,   98,  102,
 /*   430 */    87,  100,  102,  102,  258,   10,  102,   27,   28,   87,
 /*   440 */    87,  114,   87,   87,  126,  154,  102,   92,   10,   87,
 /*   450 */   102,   92,   87,   87,  259,  260,   87,  140,  147,  148,
 /*   460 */   149,   24,  125,  112,  188,  220,   87,  118,  144,  184,
 /*   470 */    87,  151,  155,  189,  169,  173,  177,   89,  170,  174,
 /*   480 */   178,  198,  206,  181,   33,  179,  202,  213,   10,  207,
 /*   490 */   202,  309,  216,  235,  224,  318,  240,   22,  178,   32,
 /*   500 */   178,   33,  201,  208,   36,  252,  212,  256,   10,   10,
 /*   510 */    73,   79,  254,  116,   84,  122,  237,  261,  124,  130,
 /*   520 */   133,  262,  268,  136,  267,  265,  269,   31,  157,  290,
 /*   530 */   153,  150,  300,  161,  163,  291,  152,  292,  293,  167,
 /*   540 */   294,  295,  296,  301,  219,  220,  171,  297,  175,  220,
 /*   550 */   298,  197,  214,  311,  180,  192,  343,  215,  196,  310,
 /*   560 */   230,  236,  227,  320,  319,  239,  254,  254,  254,  254,
 /*   570 */   199,  209,  254,  254,  210,  254,  254,  254,  254,  225,
 /*   580 */   254,  254,  254,  254,  254,  221,
};
static YYCODETYPE yy_lookahead[] = {
 /*     0 */     2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*    10 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*    20 */     0,   23,   69,   70,   71,   27,   73,   29,    2,    3,
 /*    30 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*    40 */    14,   15,   16,   17,   18,   19,   20,   21,    0,   23,
 /*    50 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*    60 */    19,   20,   21,   21,   23,   23,   70,   71,   42,   73,
 /*    70 */     0,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    80 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*    90 */    21,    0,   23,    3,    4,    5,    6,    7,    8,    9,
 /*   100 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   110 */    20,   21,   16,   23,    0,   19,   76,   26,   22,   23,
 /*   120 */    80,   81,   82,   27,   11,   12,   13,   14,   15,   16,
 /*   130 */    17,   18,   19,   20,   21,   83,   23,   41,   42,   62,
 /*   140 */    63,   64,   65,   66,   67,   68,   55,   51,   73,   97,
 /*   150 */    98,   99,   56,   57,   58,   59,   60,   15,   16,   17,
 /*   160 */    18,   19,   20,   21,   16,   23,    0,   19,   91,    0,
 /*   170 */    22,   23,   26,   96,    0,   27,   30,   31,   32,   33,
 /*   180 */    70,   35,   36,   73,   16,   20,   21,   19,   23,   41,
 /*   190 */    22,   23,   83,   74,   83,   27,   77,   78,   70,   51,
 /*   200 */    72,   73,   83,   94,   56,   57,   58,   59,   60,   41,
 /*   210 */    19,  100,  101,   22,   23,   46,   47,    0,   27,   51,
 /*   220 */    54,   52,  103,   54,   56,   57,   58,   59,   60,   27,
 /*   230 */    83,   28,   41,   13,   14,   15,   16,   17,   18,   19,
 /*   240 */    20,   21,   51,   23,   41,   98,   99,   56,   57,   58,
 /*   250 */    59,   60,   26,   51,   78,   30,   31,   32,   33,   83,
 /*   260 */    35,   36,   18,   19,   20,   21,   78,   23,   42,   51,
 /*   270 */    78,   83,    0,   11,   12,   83,   78,    0,  102,  103,
 /*   280 */   104,   83,    0,   21,   86,   24,    0,   89,   78,    0,
 /*   290 */   102,  103,  104,   83,  102,  103,  104,   78,    0,   38,
 /*   300 */    70,  103,   83,   73,   43,   86,   45,   70,   89,   72,
 /*   310 */    73,   77,   78,  103,  104,    0,   78,   83,   27,   47,
 /*   320 */    29,   83,  103,   46,   52,   78,   54,   89,   37,   47,
 /*   330 */    83,   54,   73,   47,   27,   53,   54,  103,   78,   53,
 /*   340 */    54,  103,   78,   83,   78,   47,   78,   83,    0,   83,
 /*   350 */   103,   83,   54,   69,   78,   95,   75,   78,   51,   83,
 /*   360 */    79,   78,   83,  103,   83,   78,   83,  103,   51,  103,
 /*   370 */    83,  103,   78,   78,   23,   78,   92,   83,   83,  103,
 /*   380 */    83,    0,  103,   78,   78,   51,  103,   78,   83,   83,
 /*   390 */   103,   78,   83,   83,    0,   47,   83,  103,  103,    0,
 /*   400 */   103,   78,   54,   93,   94,   78,   83,   56,  103,  103,
 /*   410 */    83,    0,  103,    0,   78,   78,  103,   78,   78,   83,
 /*   420 */    83,   30,   83,   83,   78,   34,  103,   78,   78,   83,
 /*   430 */   103,   78,   83,   83,    0,   54,   83,   49,   50,  103,
 /*   440 */   103,   78,  103,  103,   83,   78,   83,   26,   54,  103,
 /*   450 */    83,   26,  103,  103,    0,    0,  103,   46,   80,   81,
 /*   460 */    82,   26,  101,   42,   28,   54,  103,   42,   25,   26,
 /*   470 */   103,   84,   85,   16,   30,   30,   79,   41,   34,   34,
 /*   480 */    83,   40,   41,   27,   27,   29,   26,   26,   54,   87,
 /*   490 */    26,    0,   90,   69,   79,    0,   79,   48,   83,   28,
 /*   500 */    83,   27,   42,   42,   73,    0,   42,    0,   54,   54,
 /*   510 */    23,   41,    0,   41,   56,   48,   92,    0,   26,   73,
 /*   520 */    73,    0,    0,   73,    0,    0,    0,   27,   27,   27,
 /*   530 */    37,   83,    0,   30,   30,   27,   85,   27,   27,   30,
 /*   540 */    27,   27,   27,    0,   92,   54,   30,   27,   30,   54,
 /*   550 */    27,   83,   90,    0,   27,   27,    0,   27,   39,    0,
 /*   560 */     3,   92,   26,    0,    0,   25,  105,  105,  105,  105,
 /*   570 */    41,   40,  105,  105,   41,  105,  105,  105,  105,   44,
 /*   580 */   105,  105,  105,  105,  105,   51,
};
#define YY_SHIFT_USE_DFLT (-3)
static short yy_shift_ofst[] = {
 /*     0 */   261,   20,   48,   70,  114,  174,  169,  272,  166,  217,
 /*    10 */   218,   91,  317,  289,  334,  315,  282,  298,  381,  399,
 /*    20 */   413,  449,  202,  435,  202,   -3,  388,   -3,   -3,   -3,
 /*    30 */    -3,  471,  474,   -3,   -3,  394,  505,  507,  191,   69,
 /*    40 */   191,  191,  165,  191,  165,  191,  244,  191,  244,  191,
 /*    50 */   244,  191,  113,  191,  113,  191,  142,  191,  142,  191,
 /*    60 */    41,  191,   41,  191,   41,  191,   41,  191,   41,  191,
 /*    70 */    41,  191,  220,  262,  191,  487,  191,  220,  470,  148,
 /*    80 */    69,  351,   -3,  458,   -3,  191,   90,   -3,  203,   96,
 /*    90 */   226,   -3,  148,   -3,   -3,  191,   42,  191,  487,  191,
 /*   100 */    26,   -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,
 /*   110 */    -3,  421,   -3,  191,  487,  472,  148,  425,   -3,  165,
 /*   120 */   512,  467,  307,  492,  307,   -3,   -3,   -3,   -3,  434,
 /*   130 */   517,  286,  454,  521,  348,  455,  522,  524,  525,  526,
 /*   140 */   191,   69,  168,  443,  500,  146,  225,   -3,   -3,  500,
 /*   150 */   291,  493,   -3,  191,   69,   -3,  501,   -3,   -3,  502,
 /*   160 */   503,  508,  504,  510,  391,  511,  509,  513,  444,  514,
 /*   170 */   516,  515,  445,  520,  518,  523,  500,   -3,  456,  527,
 /*   180 */    -3,   -3,   -3,   -3,  168,   -3,   -3,  436,  457,   -3,
 /*   190 */    -2,  528,   -3,   -3,   -3,  519,  500,  441,  529,  191,
 /*   200 */   460,  532,  191,   -3,   69,   -3,  530,  461,  531,  533,
 /*   210 */   191,  464,  543,  530,   -3,   -3,   -3,  277,  491,  553,
 /*   220 */   534,  556,  559,  500,  535,  500,  536,  500,   -3,  557,
 /*   230 */   191,   -3,   69,   -3,  411,  495,  563,  564,  540,  500,
 /*   240 */    -3,
};
#define YY_REDUCE_USE_DFLT (-48)
static short yy_reduce_ofst[] = {
 /*     0 */    77,  -48,  -48,  -48,  -48,  -48,  -47,   -4,   75,  -48,
 /*    10 */   -48,  -48,  -48,  -48,  -48,  -48,  128,  110,  259,  -48,
 /*    20 */   -48,  -48,   52,  -48,  147,  -48,  -48,  -48,  -48,  -48,
 /*    30 */   -48,  -48,  -48,  -48,  -48,  431,  -48,  -48,  247,  -48,
 /*    40 */   264,  266,  -48,  268,  -48,  276,  -48,  279,  -48,  283,
 /*    50 */   -48,  287,  -48,  294,  -48,  295,  -48,  297,  -48,  305,
 /*    60 */   -48,  306,  -48,  309,  -48,  313,  -48,  323,  -48,  327,
 /*    70 */   -48,  336,  -48,  -48,  337,  -48,  339,  -48,  -48,  176,
 /*    80 */   -48,  -48,  -48,  -48,  -48,  340,  -48,  -48,  -48,  188,
 /*    90 */   -48,  -48,  210,  -48,  -48,  346,  -48,  350,  -48,  353,
 /*   100 */   -48,  -48,  -48,  -48,  -48,  -48,  -48,  -48,  -48,  -48,
 /*   110 */   -48,  -48,  -48,  363,  -48,  -48,  192,  -48,  -48,  -48,
 /*   120 */   -48,  -48,  111,  -48,  361,  -48,  -48,  -48,  -48,  446,
 /*   130 */   -48,  237,  447,  -48,  230,  450,  -48,  -48,  -48,  -48,
 /*   140 */   349,  -48,  119,  -48,  281,   40,  378,  -48,  -48,  448,
 /*   150 */   387,  451,  -48,  367,  -48,  -48,  -48,  -48,  -48,  -48,
 /*   160 */   -48,  -48,  -48,  -48,  -48,  -48,  -48,  -48,  -48,  -48,
 /*   170 */   -48,  -48,  -48,  -48,  -48,  -48,  397,  -48,  -48,  -48,
 /*   180 */   -48,  -48,  -48,  -48,  234,  -48,  -48,  -48,  -48,  -48,
 /*   190 */   -48,  -48,  -48,  -48,  -48,  -48,  468,  -48,  -48,  198,
 /*   200 */   -48,  -48,  238,  -48,  -48,  -48,  402,  -48,  -48,  -48,
 /*   210 */   219,  -48,  -48,  462,  -48,  -48,  -48,  284,  452,  -48,
 /*   220 */   -48,  -48,  -48,  415,  -48,  310,  -48,  109,  -48,  -48,
 /*   230 */   260,  -48,  -48,  -48,  424,  469,  -48,  -48,  -48,  417,
 /*   240 */   -48,
};
static YYACTIONTYPE yy_default[] = {
 /*     0 */   388,  388,  388,  388,  388,  388,  388,  388,  388,  388,
 /*    10 */   388,  388,  388,  388,  388,  388,  388,  388,  388,  388,
 /*    20 */   388,  388,  388,  326,  388,  327,  329,  330,  331,  332,
 /*    30 */   333,  387,  388,  386,  328,  388,  388,  388,  388,  339,
 /*    40 */   388,  388,  344,  388,  346,  388,  347,  388,  348,  388,
 /*    50 */   349,  388,  350,  388,  351,  388,  352,  388,  353,  388,
 /*    60 */   354,  388,  355,  388,  356,  388,  357,  388,  358,  388,
 /*    70 */   359,  388,  360,  388,  388,  361,  388,  362,  388,  388,
 /*    80 */   372,  388,  373,  388,  374,  388,  376,  366,  387,  388,
 /*    90 */   388,  367,  388,  369,  371,  388,  375,  388,  377,  388,
 /*   100 */   388,  378,  379,  380,  381,  382,  383,  384,  385,  368,
 /*   110 */   370,  388,  364,  388,  363,  388,  388,  388,  365,  345,
 /*   120 */   388,  388,  388,  334,  388,  335,  337,  338,  336,  388,
 /*   130 */   388,  388,  388,  388,  388,  388,  388,  388,  388,  388,
 /*   140 */   388,  325,  388,  388,  388,  270,  271,  281,  283,  388,
 /*   150 */   284,  285,  287,  388,  299,  286,  388,  288,  289,  388,
 /*   160 */   388,  388,  388,  388,  388,  388,  388,  388,  388,  388,
 /*   170 */   388,  388,  388,  388,  388,  388,  388,  279,  324,  388,
 /*   180 */   322,  323,  282,  280,  388,  272,  274,  387,  388,  275,
 /*   190 */   278,  388,  276,  277,  273,  388,  388,  388,  388,  388,
 /*   200 */   388,  388,  388,  302,  304,  303,  388,  388,  388,  388,
 /*   210 */   388,  388,  388,  388,  305,  307,  306,  388,  388,  388,
 /*   220 */   388,  388,  388,  388,  388,  388,  312,  388,  313,  388,
 /*   230 */   388,  315,  316,  314,  388,  388,  388,  388,  388,  388,
 /*   240 */   321,
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
  "ILIKE",         "BITWISE_AND",   "BITWISE_OR",    "DIVIDE",      
  "TIMES",         "MOD",           "PLUS",          "MINUS",       
  "IS",            "IN",            "DISTINCT",      "NOT",         
  "SELECT",        "FROM",          "COMMA",         "IDENTIFIER",  
  "DOT",           "AS",            "JOIN",          "INNER",       
  "CROSS",         "LEFT",          "OUTER",         "RIGHT",       
  "FULL",          "ON",            "INSERT",        "INTO",        
  "VALUES",        "BRACKET_OPEN",  "BRACKET_CLOSE",  "UPDATE",      
  "SET",           "DELETE",        "WHERE",         "ORDER",       
  "BY",            "ASC",           "DESC",          "INTEGER",     
  "GROUP",         "HAVING",        "LIMIT",         "OFFSET",      
  "NULL",          "STRING",        "DOUBLE",        "NPLACEHOLDER",
  "SPLACEHOLDER",  "error",         "program",       "query_language",
  "select_statement",  "insert_statement",  "update_statement",  "delete_statement",
  "select_clause",  "where_clause",  "order_clause",  "group_clause",
  "having_clause",  "select_limit_clause",  "column_list",   "associated_name_list",
  "join_list",     "column_item",   "expr",          "associated_name",
  "join_item",     "join_clause",   "join_type",     "qualified_name",
  "join_associated_name",  "join_conditions",  "values_list",   "field_list",  
  "value_list",    "value_item",    "field_item",    "update_clause",
  "limit_clause",  "update_item_list",  "update_item",   "new_value",   
  "delete_clause",  "order_list",    "order_item",    "order_qualified_or_int",
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
 /*  43 */ "join_clause ::= join_type qualified_name",
 /*  44 */ "join_clause ::= join_type qualified_name join_associated_name",
 /*  45 */ "join_clause ::= join_type qualified_name join_conditions",
 /*  46 */ "join_clause ::= join_type qualified_name join_associated_name join_conditions",
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
 /*  59 */ "insert_statement ::= INSERT INTO qualified_name VALUES BRACKET_OPEN values_list BRACKET_CLOSE",
 /*  60 */ "insert_statement ::= INSERT INTO qualified_name BRACKET_OPEN field_list BRACKET_CLOSE VALUES BRACKET_OPEN values_list BRACKET_CLOSE",
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
 /*  81 */ "associated_name ::= qualified_name AS IDENTIFIER",
 /*  82 */ "associated_name ::= qualified_name IDENTIFIER",
 /*  83 */ "associated_name ::= qualified_name",
 /*  84 */ "where_clause ::= WHERE expr",
 /*  85 */ "order_clause ::= ORDER BY order_list",
 /*  86 */ "order_list ::= order_list COMMA order_item",
 /*  87 */ "order_list ::= order_item",
 /*  88 */ "order_item ::= order_qualified_or_int",
 /*  89 */ "order_item ::= order_qualified_or_int ASC",
 /*  90 */ "order_item ::= order_qualified_or_int DESC",
 /*  91 */ "order_qualified_or_int ::= qualified_name",
 /*  92 */ "order_qualified_or_int ::= INTEGER",
 /*  93 */ "group_clause ::= GROUP BY group_list",
 /*  94 */ "group_list ::= group_list COMMA group_item",
 /*  95 */ "group_list ::= group_item",
 /*  96 */ "group_item ::= qualified_name",
 /*  97 */ "group_item ::= INTEGER",
 /*  98 */ "having_clause ::= HAVING expr",
 /*  99 */ "select_limit_clause ::= LIMIT INTEGER",
 /* 100 */ "select_limit_clause ::= LIMIT INTEGER COMMA INTEGER",
 /* 101 */ "select_limit_clause ::= LIMIT INTEGER OFFSET INTEGER",
 /* 102 */ "limit_clause ::= LIMIT INTEGER",
 /* 103 */ "expr ::= MINUS expr",
 /* 104 */ "expr ::= expr MINUS expr",
 /* 105 */ "expr ::= expr PLUS expr",
 /* 106 */ "expr ::= expr TIMES expr",
 /* 107 */ "expr ::= expr DIVIDE expr",
 /* 108 */ "expr ::= expr MOD expr",
 /* 109 */ "expr ::= expr AND expr",
 /* 110 */ "expr ::= expr OR expr",
 /* 111 */ "expr ::= expr BITWISE_AND expr",
 /* 112 */ "expr ::= expr BITWISE_OR expr",
 /* 113 */ "expr ::= expr EQUALS expr",
 /* 114 */ "expr ::= expr NOTEQUALS expr",
 /* 115 */ "expr ::= expr LESS expr",
 /* 116 */ "expr ::= expr GREATER expr",
 /* 117 */ "expr ::= expr GREATEREQUAL expr",
 /* 118 */ "expr ::= expr LESSEQUAL expr",
 /* 119 */ "expr ::= expr LIKE expr",
 /* 120 */ "expr ::= expr NOT LIKE expr",
 /* 121 */ "expr ::= expr ILIKE expr",
 /* 122 */ "expr ::= expr NOT ILIKE expr",
 /* 123 */ "expr ::= expr IN BRACKET_OPEN argument_list BRACKET_CLOSE",
 /* 124 */ "expr ::= expr NOT IN BRACKET_OPEN argument_list BRACKET_CLOSE",
 /* 125 */ "expr ::= function_call",
 /* 126 */ "function_call ::= IDENTIFIER BRACKET_OPEN argument_list BRACKET_CLOSE",
 /* 127 */ "function_call ::= IDENTIFIER BRACKET_OPEN BRACKET_CLOSE",
 /* 128 */ "argument_list ::= argument_list COMMA argument_item",
 /* 129 */ "argument_list ::= argument_item",
 /* 130 */ "argument_item ::= TIMES",
 /* 131 */ "argument_item ::= expr",
 /* 132 */ "expr ::= expr IS NULL",
 /* 133 */ "expr ::= expr IS NOT NULL",
 /* 134 */ "expr ::= DISTINCT expr",
 /* 135 */ "expr ::= expr BETWEEN expr",
 /* 136 */ "expr ::= NOT expr",
 /* 137 */ "expr ::= BRACKET_OPEN expr BRACKET_CLOSE",
 /* 138 */ "expr ::= qualified_name",
 /* 139 */ "expr ::= INTEGER",
 /* 140 */ "expr ::= STRING",
 /* 141 */ "expr ::= DOUBLE",
 /* 142 */ "expr ::= NULL",
 /* 143 */ "expr ::= NPLACEHOLDER",
 /* 144 */ "expr ::= SPLACEHOLDER",
 /* 145 */ "qualified_name ::= IDENTIFIER DOT IDENTIFIER",
 /* 146 */ "qualified_name ::= IDENTIFIER",
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
// 487 "parser.lemon"
{
	if ((yypminor->yy0)) {
		if ((yypminor->yy0)->free_flag) {
			efree((yypminor->yy0)->token);
		}
		efree((yypminor->yy0));
	}
}
// 1104 "parser.c"
      break;
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
    case 79:
    case 80:
    case 81:
    case 82:
    case 83:
    case 84:
    case 85:
    case 87:
    case 88:
    case 90:
    case 91:
    case 92:
    case 93:
    case 94:
    case 96:
    case 97:
    case 98:
    case 100:
    case 101:
    case 102:
    case 103:
    case 104:
// 500 "parser.lemon"
{ zval_ptr_dtor(&(yypminor->yy78)); }
// 1146 "parser.c"
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
  { 62, 1 },
  { 63, 1 },
  { 63, 1 },
  { 63, 1 },
  { 63, 1 },
  { 64, 1 },
  { 64, 2 },
  { 64, 3 },
  { 64, 3 },
  { 64, 4 },
  { 64, 4 },
  { 64, 5 },
  { 64, 5 },
  { 64, 3 },
  { 64, 4 },
  { 64, 4 },
  { 64, 5 },
  { 64, 2 },
  { 64, 3 },
  { 64, 4 },
  { 64, 3 },
  { 64, 4 },
  { 64, 6 },
  { 64, 2 },
  { 64, 3 },
  { 64, 3 },
  { 64, 4 },
  { 64, 5 },
  { 64, 2 },
  { 68, 4 },
  { 68, 5 },
  { 74, 3 },
  { 74, 1 },
  { 77, 1 },
  { 77, 3 },
  { 77, 3 },
  { 77, 2 },
  { 77, 1 },
  { 75, 3 },
  { 75, 1 },
  { 76, 2 },
  { 76, 1 },
  { 80, 1 },
  { 81, 2 },
  { 81, 3 },
  { 81, 3 },
  { 81, 4 },
  { 84, 2 },
  { 84, 1 },
  { 82, 1 },
  { 82, 2 },
  { 82, 2 },
  { 82, 2 },
  { 82, 3 },
  { 82, 2 },
  { 82, 3 },
  { 82, 2 },
  { 82, 3 },
  { 85, 2 },
  { 65, 7 },
  { 65, 10 },
  { 86, 3 },
  { 86, 1 },
  { 89, 1 },
  { 87, 3 },
  { 87, 1 },
  { 90, 1 },
  { 66, 1 },
  { 66, 2 },
  { 66, 2 },
  { 66, 3 },
  { 91, 4 },
  { 93, 3 },
  { 93, 1 },
  { 94, 3 },
  { 95, 1 },
  { 67, 1 },
  { 67, 2 },
  { 67, 2 },
  { 67, 3 },
  { 96, 3 },
  { 79, 3 },
  { 79, 2 },
  { 79, 1 },
  { 69, 2 },
  { 70, 3 },
  { 97, 3 },
  { 97, 1 },
  { 98, 1 },
  { 98, 2 },
  { 98, 2 },
  { 99, 1 },
  { 99, 1 },
  { 71, 3 },
  { 100, 3 },
  { 100, 1 },
  { 101, 1 },
  { 101, 1 },
  { 72, 2 },
  { 73, 2 },
  { 73, 4 },
  { 73, 4 },
  { 92, 2 },
  { 78, 2 },
  { 78, 3 },
  { 78, 3 },
  { 78, 3 },
  { 78, 3 },
  { 78, 3 },
  { 78, 3 },
  { 78, 3 },
  { 78, 3 },
  { 78, 3 },
  { 78, 3 },
  { 78, 3 },
  { 78, 3 },
  { 78, 3 },
  { 78, 3 },
  { 78, 3 },
  { 78, 3 },
  { 78, 4 },
  { 78, 3 },
  { 78, 4 },
  { 78, 5 },
  { 78, 6 },
  { 78, 1 },
  { 103, 4 },
  { 103, 3 },
  { 102, 3 },
  { 102, 1 },
  { 104, 1 },
  { 104, 1 },
  { 78, 3 },
  { 78, 4 },
  { 78, 2 },
  { 78, 3 },
  { 78, 2 },
  { 78, 3 },
  { 78, 1 },
  { 78, 1 },
  { 78, 1 },
  { 78, 1 },
  { 78, 1 },
  { 78, 1 },
  { 78, 1 },
  { 83, 3 },
  { 83, 1 },
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
// 496 "parser.lemon"
{
	status->ret = yymsp[0].minor.yy78;
}
// 1510 "parser.c"
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
      case 87:
      case 91:
      case 95:
      case 96:
      case 125:
      case 131:
      case 138:
// 502 "parser.lemon"
{
	yygotominor.yy78 = yymsp[0].minor.yy78;
}
// 1536 "parser.c"
        break;
      case 5:
// 520 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_select_statement(yymsp[0].minor.yy78, NULL, NULL, NULL, NULL, NULL);
}
// 1543 "parser.c"
        break;
      case 6:
// 524 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_select_statement(yymsp[-1].minor.yy78, yymsp[0].minor.yy78, NULL, NULL, NULL, NULL);
}
// 1550 "parser.c"
        break;
      case 7:
// 528 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_select_statement(yymsp[-2].minor.yy78, yymsp[-1].minor.yy78, yymsp[0].minor.yy78, NULL, NULL, NULL);
}
// 1557 "parser.c"
        break;
      case 8:
// 532 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_select_statement(yymsp[-2].minor.yy78, yymsp[-1].minor.yy78, NULL, yymsp[0].minor.yy78, NULL, NULL);
}
// 1564 "parser.c"
        break;
      case 9:
// 536 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_select_statement(yymsp[-3].minor.yy78, yymsp[-2].minor.yy78, NULL, yymsp[-1].minor.yy78, yymsp[0].minor.yy78, NULL);
}
// 1571 "parser.c"
        break;
      case 10:
// 540 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_select_statement(yymsp[-3].minor.yy78, yymsp[-2].minor.yy78, yymsp[0].minor.yy78, yymsp[-1].minor.yy78, NULL, NULL);
}
// 1578 "parser.c"
        break;
      case 11:
// 544 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_select_statement(yymsp[-4].minor.yy78, yymsp[-3].minor.yy78, yymsp[-1].minor.yy78, yymsp[-2].minor.yy78, NULL, yymsp[0].minor.yy78);
}
// 1585 "parser.c"
        break;
      case 12:
// 548 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_select_statement(yymsp[-4].minor.yy78, yymsp[-3].minor.yy78, yymsp[0].minor.yy78, yymsp[-2].minor.yy78, yymsp[-1].minor.yy78, NULL);
}
// 1592 "parser.c"
        break;
      case 13:
// 552 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_select_statement(yymsp[-2].minor.yy78, yymsp[-1].minor.yy78, NULL, NULL, NULL, yymsp[0].minor.yy78);
}
// 1599 "parser.c"
        break;
      case 14:
// 556 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_select_statement(yymsp[-3].minor.yy78, yymsp[-2].minor.yy78, yymsp[-1].minor.yy78, NULL, NULL, yymsp[0].minor.yy78);
}
// 1606 "parser.c"
        break;
      case 15:
// 560 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_select_statement(yymsp[-3].minor.yy78, yymsp[-2].minor.yy78, NULL, yymsp[-1].minor.yy78, NULL, yymsp[0].minor.yy78);
}
// 1613 "parser.c"
        break;
      case 16:
// 564 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_select_statement(yymsp[-4].minor.yy78, yymsp[-3].minor.yy78, NULL, yymsp[-2].minor.yy78, yymsp[-1].minor.yy78, yymsp[0].minor.yy78);
}
// 1620 "parser.c"
        break;
      case 17:
// 568 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_select_statement(yymsp[-1].minor.yy78, NULL, yymsp[0].minor.yy78, NULL, NULL, NULL);
}
// 1627 "parser.c"
        break;
      case 18:
// 572 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_select_statement(yymsp[-2].minor.yy78, NULL, yymsp[0].minor.yy78, yymsp[-1].minor.yy78, NULL, NULL);
}
// 1634 "parser.c"
        break;
      case 19:
// 576 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_select_statement(yymsp[-3].minor.yy78, NULL, yymsp[0].minor.yy78, yymsp[-2].minor.yy78, yymsp[-1].minor.yy78, NULL);
}
// 1641 "parser.c"
        break;
      case 20:
// 580 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_select_statement(yymsp[-2].minor.yy78, NULL, yymsp[-1].minor.yy78, NULL, NULL, yymsp[0].minor.yy78);
}
// 1648 "parser.c"
        break;
      case 21:
// 584 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_select_statement(yymsp[-3].minor.yy78, NULL, yymsp[-1].minor.yy78, yymsp[-2].minor.yy78, NULL, yymsp[0].minor.yy78);
}
// 1655 "parser.c"
        break;
      case 22:
// 588 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_select_statement(yymsp[-5].minor.yy78, yymsp[-4].minor.yy78, yymsp[-1].minor.yy78, yymsp[-3].minor.yy78, yymsp[-2].minor.yy78, yymsp[0].minor.yy78);
}
// 1662 "parser.c"
        break;
      case 23:
// 592 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_select_statement(yymsp[-1].minor.yy78, NULL, NULL, yymsp[0].minor.yy78, NULL, NULL);
}
// 1669 "parser.c"
        break;
      case 24:
// 596 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_select_statement(yymsp[-2].minor.yy78, NULL, NULL, yymsp[-1].minor.yy78, NULL, yymsp[0].minor.yy78);
}
// 1676 "parser.c"
        break;
      case 25:
// 600 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_select_statement(yymsp[-2].minor.yy78, NULL, NULL, yymsp[-1].minor.yy78, yymsp[0].minor.yy78, NULL);
}
// 1683 "parser.c"
        break;
      case 26:
// 604 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_select_statement(yymsp[-3].minor.yy78, NULL, NULL, yymsp[-2].minor.yy78, yymsp[-1].minor.yy78, yymsp[0].minor.yy78);
}
// 1690 "parser.c"
        break;
      case 27:
// 608 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_select_statement(yymsp[-4].minor.yy78, NULL, yymsp[-1].minor.yy78, yymsp[-3].minor.yy78, yymsp[-2].minor.yy78, yymsp[0].minor.yy78);
}
// 1697 "parser.c"
        break;
      case 28:
// 612 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_select_statement(yymsp[-1].minor.yy78, NULL, NULL, NULL, NULL, yymsp[0].minor.yy78);
}
// 1704 "parser.c"
        break;
      case 29:
// 618 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_select_clause(yymsp[-2].minor.yy78, yymsp[0].minor.yy78, NULL);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
// 1713 "parser.c"
        break;
      case 30:
// 622 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_select_clause(yymsp[-3].minor.yy78, yymsp[-1].minor.yy78, yymsp[0].minor.yy78);
  yy_destructor(24,&yymsp[-4].minor);
  yy_destructor(25,&yymsp[-2].minor);
}
// 1722 "parser.c"
        break;
      case 31:
      case 38:
      case 61:
      case 64:
      case 72:
      case 86:
      case 94:
      case 128:
// 628 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_zval_list(yymsp[-2].minor.yy78, yymsp[0].minor.yy78);
  yy_destructor(26,&yymsp[-1].minor);
}
// 1737 "parser.c"
        break;
      case 33:
      case 130:
// 638 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_column_item(PHQL_T_ALL, NULL, NULL, NULL);
  yy_destructor(16,&yymsp[0].minor);
}
// 1746 "parser.c"
        break;
      case 34:
// 642 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_column_item(PHQL_T_DOMAINALL, NULL, yymsp[-2].minor.yy0, NULL);
  yy_destructor(28,&yymsp[-1].minor);
  yy_destructor(16,&yymsp[0].minor);
}
// 1755 "parser.c"
        break;
      case 35:
// 646 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-2].minor.yy78, NULL, yymsp[0].minor.yy0);
  yy_destructor(29,&yymsp[-1].minor);
}
// 1763 "parser.c"
        break;
      case 36:
// 650 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-1].minor.yy78, NULL, yymsp[0].minor.yy0);
}
// 1770 "parser.c"
        break;
      case 37:
// 654 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_column_item(PHQL_T_EXPR, yymsp[0].minor.yy78, NULL, NULL);
}
// 1777 "parser.c"
        break;
      case 40:
// 670 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_zval_list(yymsp[-1].minor.yy78, yymsp[0].minor.yy78);
}
// 1784 "parser.c"
        break;
      case 43:
// 687 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_join_item(yymsp[-1].minor.yy78, yymsp[0].minor.yy78, NULL, NULL);
}
// 1791 "parser.c"
        break;
      case 44:
// 692 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_join_item(yymsp[-2].minor.yy78, yymsp[-1].minor.yy78, yymsp[0].minor.yy78, NULL);
}
// 1798 "parser.c"
        break;
      case 45:
// 697 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_join_item(yymsp[-2].minor.yy78, yymsp[-1].minor.yy78, NULL, yymsp[0].minor.yy78);
}
// 1805 "parser.c"
        break;
      case 46:
// 702 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_join_item(yymsp[-3].minor.yy78, yymsp[-2].minor.yy78, yymsp[-1].minor.yy78, yymsp[0].minor.yy78);
}
// 1812 "parser.c"
        break;
      case 47:
// 708 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_qualified_name(yymsp[0].minor.yy0, NULL);
  yy_destructor(29,&yymsp[-1].minor);
}
// 1820 "parser.c"
        break;
      case 48:
      case 66:
      case 146:
// 712 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_qualified_name(yymsp[0].minor.yy0, NULL);
}
// 1829 "parser.c"
        break;
      case 49:
// 718 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_join_type(PHQL_T_INNERJOIN);
  yy_destructor(30,&yymsp[0].minor);
}
// 1837 "parser.c"
        break;
      case 50:
// 722 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_join_type(PHQL_T_INNERJOIN);
  yy_destructor(31,&yymsp[-1].minor);
  yy_destructor(30,&yymsp[0].minor);
}
// 1846 "parser.c"
        break;
      case 51:
// 726 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_join_type(PHQL_T_CROSSJOIN);
  yy_destructor(32,&yymsp[-1].minor);
  yy_destructor(30,&yymsp[0].minor);
}
// 1855 "parser.c"
        break;
      case 52:
// 730 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  yy_destructor(33,&yymsp[-1].minor);
  yy_destructor(30,&yymsp[0].minor);
}
// 1864 "parser.c"
        break;
      case 53:
// 734 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  yy_destructor(33,&yymsp[-2].minor);
  yy_destructor(34,&yymsp[-1].minor);
  yy_destructor(30,&yymsp[0].minor);
}
// 1874 "parser.c"
        break;
      case 54:
// 738 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  yy_destructor(35,&yymsp[-1].minor);
  yy_destructor(30,&yymsp[0].minor);
}
// 1883 "parser.c"
        break;
      case 55:
// 742 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(34,&yymsp[-1].minor);
  yy_destructor(30,&yymsp[0].minor);
}
// 1893 "parser.c"
        break;
      case 56:
// 746 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_join_type(PHQL_T_FULLJOIN);
  yy_destructor(36,&yymsp[-1].minor);
  yy_destructor(30,&yymsp[0].minor);
}
// 1902 "parser.c"
        break;
      case 57:
// 750 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_join_type(PHQL_T_FULLJOIN);
  yy_destructor(36,&yymsp[-2].minor);
  yy_destructor(34,&yymsp[-1].minor);
  yy_destructor(30,&yymsp[0].minor);
}
// 1912 "parser.c"
        break;
      case 58:
// 756 "parser.lemon"
{
	yygotominor.yy78 = yymsp[0].minor.yy78;
  yy_destructor(37,&yymsp[-1].minor);
}
// 1920 "parser.c"
        break;
      case 59:
// 763 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_insert_statement(yymsp[-4].minor.yy78, NULL, yymsp[-1].minor.yy78);
  yy_destructor(38,&yymsp[-6].minor);
  yy_destructor(39,&yymsp[-5].minor);
  yy_destructor(40,&yymsp[-3].minor);
  yy_destructor(41,&yymsp[-2].minor);
  yy_destructor(42,&yymsp[0].minor);
}
// 1932 "parser.c"
        break;
      case 60:
// 767 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_insert_statement(yymsp[-7].minor.yy78, yymsp[-5].minor.yy78, yymsp[-1].minor.yy78);
  yy_destructor(38,&yymsp[-9].minor);
  yy_destructor(39,&yymsp[-8].minor);
  yy_destructor(41,&yymsp[-6].minor);
  yy_destructor(42,&yymsp[-4].minor);
  yy_destructor(40,&yymsp[-3].minor);
  yy_destructor(41,&yymsp[-2].minor);
  yy_destructor(42,&yymsp[0].minor);
}
// 1946 "parser.c"
        break;
      case 67:
// 805 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_update_statement(yymsp[0].minor.yy78, NULL, NULL);
}
// 1953 "parser.c"
        break;
      case 68:
// 809 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_update_statement(yymsp[-1].minor.yy78, yymsp[0].minor.yy78, NULL);
}
// 1960 "parser.c"
        break;
      case 69:
// 813 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_update_statement(yymsp[-1].minor.yy78, NULL, yymsp[0].minor.yy78);
}
// 1967 "parser.c"
        break;
      case 70:
// 817 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_update_statement(yymsp[-2].minor.yy78, yymsp[-1].minor.yy78, yymsp[0].minor.yy78);
}
// 1974 "parser.c"
        break;
      case 71:
// 823 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_update_clause(yymsp[-2].minor.yy78, yymsp[0].minor.yy78);
  yy_destructor(43,&yymsp[-3].minor);
  yy_destructor(44,&yymsp[-1].minor);
}
// 1983 "parser.c"
        break;
      case 74:
// 839 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_update_item(yymsp[-2].minor.yy78, yymsp[0].minor.yy78);
  yy_destructor(3,&yymsp[-1].minor);
}
// 1991 "parser.c"
        break;
      case 76:
// 851 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_delete_statement(yymsp[0].minor.yy78, NULL, NULL);
}
// 1998 "parser.c"
        break;
      case 77:
// 855 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_delete_statement(yymsp[-1].minor.yy78, yymsp[0].minor.yy78, NULL);
}
// 2005 "parser.c"
        break;
      case 78:
// 859 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_delete_statement(yymsp[-1].minor.yy78, NULL, yymsp[0].minor.yy78);
}
// 2012 "parser.c"
        break;
      case 79:
// 863 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_delete_statement(yymsp[-2].minor.yy78, yymsp[-1].minor.yy78, yymsp[0].minor.yy78);
}
// 2019 "parser.c"
        break;
      case 80:
// 869 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_delete_clause(yymsp[0].minor.yy78);
  yy_destructor(45,&yymsp[-2].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
// 2028 "parser.c"
        break;
      case 81:
// 875 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_assoc_name(yymsp[-2].minor.yy78, yymsp[0].minor.yy0);
  yy_destructor(29,&yymsp[-1].minor);
}
// 2036 "parser.c"
        break;
      case 82:
// 879 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_assoc_name(yymsp[-1].minor.yy78, yymsp[0].minor.yy0);
}
// 2043 "parser.c"
        break;
      case 83:
// 883 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_assoc_name(yymsp[0].minor.yy78, NULL);
}
// 2050 "parser.c"
        break;
      case 84:
// 889 "parser.lemon"
{
	yygotominor.yy78 = yymsp[0].minor.yy78;
  yy_destructor(46,&yymsp[-1].minor);
}
// 2058 "parser.c"
        break;
      case 85:
// 895 "parser.lemon"
{
	yygotominor.yy78 = yymsp[0].minor.yy78;
  yy_destructor(47,&yymsp[-2].minor);
  yy_destructor(48,&yymsp[-1].minor);
}
// 2067 "parser.c"
        break;
      case 88:
// 911 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_order_item(yymsp[0].minor.yy78, 0);
}
// 2074 "parser.c"
        break;
      case 89:
// 915 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_order_item(yymsp[-1].minor.yy78, PHQL_T_ASC);
  yy_destructor(49,&yymsp[0].minor);
}
// 2082 "parser.c"
        break;
      case 90:
// 919 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_order_item(yymsp[-1].minor.yy78, PHQL_T_DESC);
  yy_destructor(50,&yymsp[0].minor);
}
// 2090 "parser.c"
        break;
      case 92:
      case 97:
      case 139:
// 927 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_literal_zval(PHQL_T_INTEGER, yymsp[0].minor.yy0);
}
// 2099 "parser.c"
        break;
      case 93:
// 933 "parser.lemon"
{
	yygotominor.yy78 = yymsp[0].minor.yy78;
  yy_destructor(52,&yymsp[-2].minor);
  yy_destructor(48,&yymsp[-1].minor);
}
// 2108 "parser.c"
        break;
      case 98:
// 959 "parser.lemon"
{
	yygotominor.yy78 = yymsp[0].minor.yy78;
  yy_destructor(53,&yymsp[-1].minor);
}
// 2116 "parser.c"
        break;
      case 99:
      case 102:
// 965 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_limit_clause(yymsp[0].minor.yy0, NULL);
  yy_destructor(54,&yymsp[-1].minor);
}
// 2125 "parser.c"
        break;
      case 100:
// 969 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_limit_clause(yymsp[0].minor.yy0, yymsp[-2].minor.yy0);
  yy_destructor(54,&yymsp[-3].minor);
  yy_destructor(26,&yymsp[-1].minor);
}
// 2134 "parser.c"
        break;
      case 101:
// 973 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_limit_clause(yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(54,&yymsp[-3].minor);
  yy_destructor(55,&yymsp[-1].minor);
}
// 2143 "parser.c"
        break;
      case 103:
// 985 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_expr(PHQL_T_MINUS, NULL, yymsp[0].minor.yy78);
  yy_destructor(19,&yymsp[-1].minor);
}
// 2151 "parser.c"
        break;
      case 104:
// 989 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_expr(PHQL_T_SUB, yymsp[-2].minor.yy78, yymsp[0].minor.yy78);
  yy_destructor(19,&yymsp[-1].minor);
}
// 2159 "parser.c"
        break;
      case 105:
// 993 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_expr(PHQL_T_ADD, yymsp[-2].minor.yy78, yymsp[0].minor.yy78);
  yy_destructor(18,&yymsp[-1].minor);
}
// 2167 "parser.c"
        break;
      case 106:
// 997 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_expr(PHQL_T_MUL, yymsp[-2].minor.yy78, yymsp[0].minor.yy78);
  yy_destructor(16,&yymsp[-1].minor);
}
// 2175 "parser.c"
        break;
      case 107:
// 1001 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_expr(PHQL_T_DIV, yymsp[-2].minor.yy78, yymsp[0].minor.yy78);
  yy_destructor(15,&yymsp[-1].minor);
}
// 2183 "parser.c"
        break;
      case 108:
// 1005 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_expr(PHQL_T_MOD, yymsp[-2].minor.yy78, yymsp[0].minor.yy78);
  yy_destructor(17,&yymsp[-1].minor);
}
// 2191 "parser.c"
        break;
      case 109:
// 1009 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_expr(PHQL_T_AND, yymsp[-2].minor.yy78, yymsp[0].minor.yy78);
  yy_destructor(9,&yymsp[-1].minor);
}
// 2199 "parser.c"
        break;
      case 110:
// 1013 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_expr(PHQL_T_OR, yymsp[-2].minor.yy78, yymsp[0].minor.yy78);
  yy_destructor(10,&yymsp[-1].minor);
}
// 2207 "parser.c"
        break;
      case 111:
// 1017 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_expr(PHQL_T_BITWISE_AND, yymsp[-2].minor.yy78, yymsp[0].minor.yy78);
  yy_destructor(13,&yymsp[-1].minor);
}
// 2215 "parser.c"
        break;
      case 112:
// 1021 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_expr(PHQL_T_BITWISE_OR, yymsp[-2].minor.yy78, yymsp[0].minor.yy78);
  yy_destructor(14,&yymsp[-1].minor);
}
// 2223 "parser.c"
        break;
      case 113:
// 1025 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_expr(PHQL_T_EQUALS, yymsp[-2].minor.yy78, yymsp[0].minor.yy78);
  yy_destructor(3,&yymsp[-1].minor);
}
// 2231 "parser.c"
        break;
      case 114:
// 1029 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_expr(PHQL_T_NOTEQUALS, yymsp[-2].minor.yy78, yymsp[0].minor.yy78);
  yy_destructor(4,&yymsp[-1].minor);
}
// 2239 "parser.c"
        break;
      case 115:
// 1033 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_expr(PHQL_T_LESS, yymsp[-2].minor.yy78, yymsp[0].minor.yy78);
  yy_destructor(5,&yymsp[-1].minor);
}
// 2247 "parser.c"
        break;
      case 116:
// 1037 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_expr(PHQL_T_GREATER, yymsp[-2].minor.yy78, yymsp[0].minor.yy78);
  yy_destructor(6,&yymsp[-1].minor);
}
// 2255 "parser.c"
        break;
      case 117:
// 1041 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_expr(PHQL_T_GREATEREQUAL, yymsp[-2].minor.yy78, yymsp[0].minor.yy78);
  yy_destructor(7,&yymsp[-1].minor);
}
// 2263 "parser.c"
        break;
      case 118:
// 1045 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_expr(PHQL_T_LESSEQUAL, yymsp[-2].minor.yy78, yymsp[0].minor.yy78);
  yy_destructor(8,&yymsp[-1].minor);
}
// 2271 "parser.c"
        break;
      case 119:
// 1049 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_expr(PHQL_T_LIKE, yymsp[-2].minor.yy78, yymsp[0].minor.yy78);
  yy_destructor(11,&yymsp[-1].minor);
}
// 2279 "parser.c"
        break;
      case 120:
// 1053 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_expr(PHQL_T_NLIKE, yymsp[-3].minor.yy78, yymsp[0].minor.yy78);
  yy_destructor(23,&yymsp[-2].minor);
  yy_destructor(11,&yymsp[-1].minor);
}
// 2288 "parser.c"
        break;
      case 121:
// 1057 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_expr(PHQL_T_ILIKE, yymsp[-2].minor.yy78, yymsp[0].minor.yy78);
  yy_destructor(12,&yymsp[-1].minor);
}
// 2296 "parser.c"
        break;
      case 122:
// 1061 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_expr(PHQL_T_NILIKE, yymsp[-3].minor.yy78, yymsp[0].minor.yy78);
  yy_destructor(23,&yymsp[-2].minor);
  yy_destructor(12,&yymsp[-1].minor);
}
// 2305 "parser.c"
        break;
      case 123:
// 1065 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_expr(PHQL_T_IN, yymsp[-4].minor.yy78, yymsp[-1].minor.yy78);
  yy_destructor(21,&yymsp[-3].minor);
  yy_destructor(41,&yymsp[-2].minor);
  yy_destructor(42,&yymsp[0].minor);
}
// 2315 "parser.c"
        break;
      case 124:
// 1069 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_expr(PHQL_T_NOTIN, yymsp[-5].minor.yy78, yymsp[-1].minor.yy78);
  yy_destructor(23,&yymsp[-4].minor);
  yy_destructor(21,&yymsp[-3].minor);
  yy_destructor(41,&yymsp[-2].minor);
  yy_destructor(42,&yymsp[0].minor);
}
// 2326 "parser.c"
        break;
      case 126:
// 1079 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_func_call(yymsp[-3].minor.yy0, yymsp[-1].minor.yy78);
  yy_destructor(41,&yymsp[-2].minor);
  yy_destructor(42,&yymsp[0].minor);
}
// 2335 "parser.c"
        break;
      case 127:
// 1083 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_func_call(yymsp[-2].minor.yy0, NULL);
  yy_destructor(41,&yymsp[-1].minor);
  yy_destructor(42,&yymsp[0].minor);
}
// 2344 "parser.c"
        break;
      case 129:
// 1093 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_zval_list(yymsp[0].minor.yy78, NULL);
}
// 2351 "parser.c"
        break;
      case 132:
// 1107 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_expr(PHQL_T_ISNULL, yymsp[-2].minor.yy78, NULL);
  yy_destructor(20,&yymsp[-1].minor);
  yy_destructor(56,&yymsp[0].minor);
}
// 2360 "parser.c"
        break;
      case 133:
// 1111 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_expr(PHQL_T_ISNOTNULL, yymsp[-3].minor.yy78, NULL);
  yy_destructor(20,&yymsp[-2].minor);
  yy_destructor(23,&yymsp[-1].minor);
  yy_destructor(56,&yymsp[0].minor);
}
// 2370 "parser.c"
        break;
      case 134:
// 1115 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_expr(PHQL_T_DISTINCT, NULL, yymsp[0].minor.yy78);
  yy_destructor(22,&yymsp[-1].minor);
}
// 2378 "parser.c"
        break;
      case 135:
// 1119 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_expr(PHQL_T_BETWEEN, yymsp[-2].minor.yy78, yymsp[0].minor.yy78);
  yy_destructor(2,&yymsp[-1].minor);
}
// 2386 "parser.c"
        break;
      case 136:
// 1123 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_expr(PHQL_T_NOT, NULL, yymsp[0].minor.yy78);
  yy_destructor(23,&yymsp[-1].minor);
}
// 2394 "parser.c"
        break;
      case 137:
// 1127 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_expr(PHQL_T_ENCLOSED, yymsp[-1].minor.yy78, NULL);
  yy_destructor(41,&yymsp[-2].minor);
  yy_destructor(42,&yymsp[0].minor);
}
// 2403 "parser.c"
        break;
      case 140:
// 1139 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_literal_zval(PHQL_T_STRING, yymsp[0].minor.yy0);
}
// 2410 "parser.c"
        break;
      case 141:
// 1143 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_literal_zval(PHQL_T_DOUBLE, yymsp[0].minor.yy0);
}
// 2417 "parser.c"
        break;
      case 142:
// 1147 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_literal_zval(PHQL_T_NULL, NULL);
  yy_destructor(56,&yymsp[0].minor);
}
// 2425 "parser.c"
        break;
      case 143:
// 1151 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_placeholder_zval(PHQL_T_NPLACEHOLDER, yymsp[0].minor.yy0);
}
// 2432 "parser.c"
        break;
      case 144:
// 1155 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_placeholder_zval(PHQL_T_SPLACEHOLDER, yymsp[0].minor.yy0);
}
// 2439 "parser.c"
        break;
      case 145:
// 1161 "parser.lemon"
{
	yygotominor.yy78 = phql_ret_qualified_name(yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(28,&yymsp[-1].minor);
}
// 2447 "parser.c"
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
// 420 "parser.lemon"

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

			status->syntax_error_len = 64 + status->token->len + token_length + near_length;
			status->syntax_error = emalloc(sizeof(char) * status->syntax_error_len);

			if (near_length > 0) {
				if (status->token->value) {
					snprintf(status->syntax_error, status->syntax_error_len, "Syntax error, unexpected token %s(%s), near to '%s'", token_name, status->token->value, status->scanner_state->start);
				} else {
					snprintf(status->syntax_error, status->syntax_error_len, "Syntax error, unexpected token %s, near to '%s'", token_name, status->scanner_state->start);
				}
			} else {
				if (active_token != PHQL_T_IGNORE) {
					if (status->token->value) {
						snprintf(status->syntax_error, status->syntax_error_len, "Syntax error, unexpected token %s(%s), at the end of query", token_name, status->token->value);
					} else {
						snprintf(status->syntax_error, status->syntax_error_len, "Syntax error, unexpected token %s, at the end of query", token_name);
					}
				} else {
					snprintf(status->syntax_error, status->syntax_error_len, "Syntax error, unexpected EOF, at the end of query");
				}
				status->syntax_error[status->syntax_error_len-1] = '\0';
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

// 2556 "parser.c"
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
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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
  { PHQL_T_INTEGER,       SL("INTEGER") },
  { PHQL_T_DOUBLE,        SL("DOUBLE") },
  { PHQL_T_STRING,        SL("STRING") },
  { PHQL_T_IDENTIFIER,    SL("IDENTIFIER") },
  { PHQL_T_MINUS,         SL("MINUS") },
  { PHQL_T_ADD,           SL("+") },
  { PHQL_T_SUB,           SL("-") },
  { PHQL_T_MUL,           SL("*") },
  { PHQL_T_DIV,           SL("/") },
  { PHQL_T_BITWISE_AND,   SL("&") },
  { PHQL_T_BITWISE_OR,    SL("|") },
  { PHQL_T_MOD,           SL("%%") },
  { PHQL_T_AND,           SL("AND") },
  { PHQL_T_OR,            SL("OR") },
  { PHQL_T_LIKE,          SL("LIKE") },
  { PHQL_T_ILIKE,         SL("ILIKE") },
  { PHQL_T_DOT,           SL("DOT") },
  { PHQL_T_COMMA,         SL("COMMA") },
  { PHQL_T_EQUALS,        SL("EQUALS") },
  { PHQL_T_NOTEQUALS,     SL("NOT EQUALS") },
  { PHQL_T_NOT,           SL("NOT") },
  { PHQL_T_LESS,          SL("<") },
  { PHQL_T_LESSEQUAL,     SL("<=") },
  { PHQL_T_GREATER,       SL(">") },
  { PHQL_T_GREATEREQUAL,  SL(">=") },
  { PHQL_T_BRACKET_OPEN,  SL("(") },
  { PHQL_T_BRACKET_CLOSE, SL(")") },
  { PHQL_T_NPLACEHOLDER,  SL("NUMERIC PLACEHOLDER") },
  { PHQL_T_SPLACEHOLDER,  SL("STRING PLACEHOLDER") },
  { PHQL_T_UPDATE,        SL("UPDATE") },
  { PHQL_T_SET,           SL("SET") },
  { PHQL_T_WHERE,         SL("WHERE") },
  { PHQL_T_DELETE,        SL("DELETE") },
  { PHQL_T_FROM,          SL("FROM") },
  { PHQL_T_AS,            SL("AS") },
  { PHQL_T_INSERT,        SL("INSERT") },
  { PHQL_T_INTO,          SL("INTO") },
  { PHQL_T_VALUES,        SL("VALUES") },
  { PHQL_T_SELECT,        SL("SELECT") },
  { PHQL_T_ORDER,         SL("ORDER") },
  { PHQL_T_BY,            SL("BY") },
  { PHQL_T_LIMIT,         SL("LIMIT") },
  { PHQL_T_OFFSET,        SL("OFFSET") },
  { PHQL_T_GROUP,         SL("GROUP") },
  { PHQL_T_HAVING,        SL("HAVING") },
  { PHQL_T_IN,            SL("IN") },
  { PHQL_T_ON,            SL("ON") },
  { PHQL_T_INNER,         SL("INNER") },
  { PHQL_T_JOIN,          SL("JOIN") },
  { PHQL_T_LEFT,          SL("LEFT") },
  { PHQL_T_RIGHT,         SL("RIGHT") },
  { PHQL_T_IS,            SL("IS") },
  { PHQL_T_NULL,          SL("NULL") },
  { PHQL_T_NOTIN,         SL("NOT IN") },
  { PHQL_T_CROSS,         SL("CROSS") },
  { PHQL_T_OUTER,         SL("OUTER") },
  { PHQL_T_FULL,          SL("FULL") },
  { PHQL_T_ASC,           SL("ASC") },
  { PHQL_T_DESC,          SL("DESC") },
  { PHQL_T_BETWEEN,       SL("BETWEEN") },
  { PHQL_T_DISTINCT,      SL("DISTINCT") },
  { PHQL_T_AGAINST,       SL("AGAINST") },
  { 0, NULL, 0 }
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

	char *error, *error_part;
	unsigned int length;
	phql_scanner_state *state = parser_status->scanner_state;

	PHALCON_INIT_VAR(*error_msg);
	if (state->start) {
		length = 48 + state->start_length;
		error = emalloc(sizeof(char) * length);
		if (state->start_length > 16) {
			error_part = estrndup(state->start, 16);
			snprintf(error, length, "Parsing error before '%s...'", error_part);
			efree(error_part);
		} else {
			snprintf(error, length, "Parsing error before '%s'", state->start);
		}
		error[length - 1] = '\0';
		ZVAL_STRING(*error_msg, error, 1);
	} else {
		error = emalloc(sizeof(char) * 48);
		sprintf(error, "Parsing error near to EOF");
		ZVAL_STRING(*error_msg, error, 1);
	}
	efree(error);
}

/**
 * Executes the internal PHQL parser/tokenizer
 */
int phql_parse_phql(zval *result, zval *phql TSRMLS_DC) {

	zval *error_msg = NULL;

	ZVAL_NULL(result);

	if(phql_internal_parse_phql(&result, Z_STRVAL_P(phql), Z_STRLEN_P(phql), &error_msg TSRMLS_CC) == FAILURE){
		phalcon_throw_exception_string(phalcon_mvc_model_exception_ce, Z_STRVAL_P(error_msg), Z_STRLEN_P(error_msg) TSRMLS_CC);
		return FAILURE;
	}

	return SUCCESS;
}

/**
 * Executes a PHQL parser/tokenizer
 */
int phql_internal_parse_phql(zval **result, char *phql, unsigned int phql_length, zval **error_msg TSRMLS_DC) {

	char *error;
	phql_scanner_state *state;
	phql_scanner_token token;
	int scanner_status, status = SUCCESS;
	phql_parser_status *parser_status = NULL;
	void* phql_parser;

	if (!phql) {
		PHALCON_INIT_VAR(*error_msg);
		ZVAL_STRING(*error_msg, "PHQL statement cannot be NULL", 1);
		return FAILURE;
	}

	phql_parser = phql_Alloc(phql_wrapper_alloc);

	parser_status = emalloc(sizeof(phql_parser_status));
	state = emalloc(sizeof(phql_scanner_state));

	parser_status->status = PHQL_PARSING_OK;
	parser_status->scanner_state = state;
	parser_status->ret = NULL;
	parser_status->syntax_error = NULL;
	parser_status->token = &token;

	state->active_token = 0;
	state->start = phql;
	state->start_length = 0;
	state->end = state->start;

	token.value = NULL;
	token.len = 0;

	while(0 <= (scanner_status = phql_get_token(state, &token))) {

		/* Calculate the 'start' length */
		state->start_length = (phql + phql_length - state->start);

		state->active_token = token.opcode;

		/* Parse the token found */
		switch(token.opcode){

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
			case PHQL_T_AGAINST:
				phql_(phql_parser, PHQL_AGAINST, NULL, parser_status);
				break;
			case PHQL_T_DOT:
				phql_(phql_parser, PHQL_DOT, NULL, parser_status);
				break;
			case PHQL_T_COMMA:
				phql_(phql_parser, PHQL_COMMA, NULL, parser_status);
				break;

			case PHQL_T_BRACKET_OPEN:
				phql_(phql_parser, PHQL_BRACKET_OPEN, NULL, parser_status);
				break;
			case PHQL_T_BRACKET_CLOSE:
				phql_(phql_parser, PHQL_BRACKET_CLOSE, NULL, parser_status);
				break;

			case PHQL_T_INTEGER:
				phql_parse_with_token(phql_parser, PHQL_T_INTEGER, PHQL_INTEGER, &token, parser_status);
				break;
			case PHQL_T_DOUBLE:
				phql_parse_with_token(phql_parser, PHQL_T_DOUBLE, PHQL_DOUBLE, &token, parser_status);
				break;
			case PHQL_T_STRING:
				phql_parse_with_token(phql_parser, PHQL_T_STRING, PHQL_STRING, &token, parser_status);
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
			default:
				parser_status->status = PHQL_PARSING_FAILED;
				error = emalloc(sizeof(char) * 32);
				sprintf(error, "scanner: unknown opcode %c", token.opcode);
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
				ZVAL_ZVAL(*result, parser_status->ret, 0, 0);
				ZVAL_NULL(parser_status->ret);
				zval_ptr_dtor(&parser_status->ret);
			} else {
				efree(parser_status->ret);
			}
		}
	}

	efree(parser_status);
	efree(state);

	return status;
}