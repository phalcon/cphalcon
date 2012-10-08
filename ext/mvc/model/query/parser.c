/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is include which follows the "include" declaration
** in the input file. */
#include <stdio.h>
#line 35 "parser.lemon"


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "parser.h"
#include "scanner.h"
#include "lang.h"

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
		add_assoc_stringl(ret, "value", T->token, T->token_len, 1);
		efree(T->token);
		efree(T);
	}

	return ret;
}

static zval *phql_ret_placeholder_zval(int type, phql_parser_token *T)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", type);
	add_assoc_stringl(ret, "value", T->token, T->token_len, 1);
	efree(T->token);
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
		add_assoc_stringl(ret, "domain", A->token, A->token_len, 1);
		add_assoc_stringl(ret, "name", B->token, B->token_len, 1);
		efree(B->token);
		efree(B);
	} else {
		add_assoc_stringl(ret, "name", A->token, A->token_len, 1);
	}
	efree(A->token);
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
	array_init(ret);
	add_assoc_zval(ret, "tables", tables);
	add_assoc_zval(ret, "values", values);

	return ret;
}

static zval *phql_ret_update_item(zval *column, zval *expr)
{

	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
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
	array_init(ret);
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

	add_next_index_zval(ret, right_list);

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
		add_assoc_stringl(ret, "column", identifier_column->token, identifier_column->token_len, 1);
		efree(identifier_column->token);
		efree(identifier_column);
	}
	if (alias) {
		add_assoc_stringl(ret, "alias", alias->token, alias->token_len, 1);
		efree(alias->token);
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
		add_assoc_stringl(ret, "alias", alias->token, alias->token_len, 1);
		efree(alias->token);
		efree(alias);
	}

	return ret;

}

static zval *phql_ret_join_item(zval *join, phql_parser_token *alias)
{

	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_zval(ret, "join", join);
	if (alias) {
		add_assoc_stringl(ret, "alias", alias->token, alias->token_len, 1);
		efree(alias->token);
		efree(alias);
	}

	return ret;

}

static zval *phql_ret_join_clause(int type, zval *qualified_name, zval *expr)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);
	add_assoc_long(ret, "type", type);
	add_assoc_zval(ret, "qualifiedName", qualified_name);
	if (expr) {
		add_assoc_zval(ret, "expr", expr);
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
	add_assoc_stringl(ret, "name", name->token, name->token_len, 1);
	efree(name->token);
	efree(name);

	if (arguments) {
		add_assoc_zval(ret, "arguments", arguments);
	}

	return ret;
}


#line 376 "parser.c"
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
#define YYNOCODE 96
#define YYACTIONTYPE unsigned short int
#define phql_TOKENTYPE phql_parser_token*
typedef union {
  phql_TOKENTYPE yy0;
  zval* yy48;
  int yy191;
} YYMINORTYPE;
#define YYSTACKDEPTH 100
#define phql_ARG_SDECL phql_parser_status *status;
#define phql_ARG_PDECL ,phql_parser_status *status
#define phql_ARG_FETCH phql_parser_status *status = yypParser->status
#define phql_ARG_STORE yypParser->status = status
#define YYNSTATE 238
#define YYNRULE 140
#define YYERRORSYMBOL 54
#define YYERRSYMDT yy191
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
 /*     0 */    51,   53,   55,   57,   59,   61,   47,   49,   63,   43,
 /*    10 */    41,   45,   39,   36,   71,   68,   65,    7,  113,  115,
 /*    20 */   192,  123,  190,    9,   51,   53,   55,   57,   59,   61,
 /*    30 */    47,   49,   63,   43,   41,   45,   39,   36,   71,   68,
 /*    40 */    65,   51,   53,   55,   57,   59,   61,   47,   49,   63,
 /*    50 */    43,   41,   45,   39,   36,   71,   68,   65,   85,   90,
 /*    60 */    31,   37,   13,   33,   86,  131,  132,  133,   79,   47,
 /*    70 */    49,   63,   43,   41,   45,   39,   36,   71,   68,   65,
 /*    80 */   203,   85,   88,   83,   37,   91,  199,   86,  247,  204,
 /*    90 */    27,   79,   92,   71,   68,   65,   95,   93,   94,   96,
 /*   100 */    97,   14,   78,  185,   16,   88,   37,  119,  127,   86,
 /*   110 */   121,  193,  189,  186,   26,   92,  238,   91,  110,   95,
 /*   120 */    93,   94,   96,   97,   77,   70,   25,   88,   37,   17,
 /*   130 */    91,   86,  107,  112,   78,   79,   10,   92,   21,   22,
 /*   140 */    76,   95,   93,   94,   96,   97,   75,   78,   84,   88,
 /*   150 */    23,   24,  379,    1,    2,    3,    4,    5,    6,   92,
 /*   160 */   128,  183,   77,   95,   93,   94,   96,   97,   63,   43,
 /*   170 */    41,   45,   39,   36,   71,   68,   65,  243,   82,  216,
 /*   180 */   197,  205,   25,  231,   43,   41,   45,   39,   36,   71,
 /*   190 */    68,   65,  175,   19,   30,   22,  137,  244,  141,  146,
 /*   200 */   149,  129,  159,  169,  137,  182,  141,  146,  149,  177,
 /*   210 */   159,  169,   39,   36,   71,   68,   65,  124,   17,   70,
 /*   220 */   246,   11,  339,  105,   91,   10,   70,  116,  203,  118,
 /*   230 */   122,   91,  126,   91,  210,  245,   77,  204,   17,  261,
 /*   240 */    81,   78,   84,  105,  239,   10,  194,  101,   78,   84,
 /*   250 */    78,  220,  102,  235,   70,  110,  176,   27,  130,   91,
 /*   260 */   177,   17,  181,  132,  133,  184,  189,   34,   10,  203,
 /*   270 */   109,   91,    8,   12,   91,  104,   78,   98,  202,  229,
 /*   280 */    17,  111,  240,   10,   91,   73,   34,   10,   78,   35,
 /*   290 */   103,   78,   38,  228,   91,   91,   15,   91,   40,   66,
 /*   300 */    42,   78,  150,   91,   44,   91,   99,  154,  226,   91,
 /*   310 */   241,   78,   78,   46,   78,  223,  230,   72,   91,   48,
 /*   320 */    78,  263,   78,   50,   91,   52,   78,  160,   91,   20,
 /*   330 */    91,   54,  164,   56,   58,   78,   91,   60,   91,   91,
 /*   340 */   188,   78,   91,   62,   64,   78,   67,   78,   91,   91,
 /*   350 */    29,   91,   87,   78,  307,   78,   78,   91,   89,   78,
 /*   360 */   242,  252,   17,   91,  316,   78,   78,  125,   78,   10,
 /*   370 */   140,  250,   91,  145,   78,   91,  153,  158,   91,  248,
 /*   380 */    78,   91,   91,  163,  255,  168,  174,   28,   91,   78,
 /*   390 */    91,   91,   78,  256,  124,   78,  257,  187,   78,   78,
 /*   400 */    80,  136,   10,  134,  124,   78,  201,   78,   78,  180,
 /*   410 */    80,  178,   10,  206,  212,  201,  215,  217,  308,   10,
 /*   420 */   221,  219,  200,  317,  177,  226,  260,   10,  254,   18,
 /*   430 */   207,  211,   10,  225,  232,  237,   28,   29,  234,  177,
 /*   440 */    32,   10,  249,  253,   10,   69,   65,   74,  100,  251,
 /*   450 */   106,  108,  258,  259,  265,  114,  117,  120,  264,  262,
 /*   460 */   266,   27,  135,  139,  144,  170,   10,  195,  138,  142,
 /*   470 */   147,   10,  152,  143,  155,  148,  151,  156,  161,  166,
 /*   480 */   157,  162,  167,  172,  299,  165,  171,  179,  173,  214,
 /*   490 */   191,  196,  300,  213,  310,  309,  218,  224,  227,  198,
 /*   500 */   209,  208,  319,  233,  318,  236,  237,  237,  222,
};
static YYCODETYPE yy_lookahead[] = {
 /*     0 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    10 */    11,   12,   13,   14,   15,   16,   17,   62,   63,   64,
 /*    20 */    21,   66,   23,   66,    1,    2,    3,    4,    5,    6,
 /*    30 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*    40 */    17,    1,    2,    3,    4,    5,    6,    7,    8,    9,
 /*    50 */    10,   11,   12,   13,   14,   15,   16,   17,   11,   36,
 /*    60 */    63,   14,   65,   66,   17,   73,   74,   75,   21,    7,
 /*    70 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*    80 */    71,   11,   35,   36,   14,   76,   77,   17,    0,   80,
 /*    90 */    21,   21,   45,   15,   16,   17,   49,   50,   51,   52,
 /*   100 */    53,   63,   93,   11,   66,   35,   14,   63,   67,   17,
 /*   110 */    66,   70,   71,   21,   45,   45,    0,   76,   76,   49,
 /*   120 */    50,   51,   52,   53,   20,   71,   76,   35,   14,   41,
 /*   130 */    76,   17,   90,   91,   93,   21,   48,   45,   88,   89,
 /*   140 */    36,   49,   50,   51,   52,   53,   92,   93,   94,   35,
 /*   150 */    43,   44,   55,   56,   57,   58,   59,   60,   61,   45,
 /*   160 */    19,   20,   20,   49,   50,   51,   52,   53,    9,   10,
 /*   170 */    11,   12,   13,   14,   15,   16,   17,    0,   36,   82,
 /*   180 */    34,   35,   76,   86,   10,   11,   12,   13,   14,   15,
 /*   190 */    16,   17,   20,   87,   88,   89,   24,    0,   26,   27,
 /*   200 */    28,   68,   30,   31,   24,   72,   26,   27,   28,   76,
 /*   210 */    30,   31,   13,   14,   15,   16,   17,   40,   41,   71,
 /*   220 */     0,   45,    0,   46,   76,   48,   71,   63,   71,   65,
 /*   230 */    66,   76,   18,   76,   77,    0,   20,   80,   41,    0,
 /*   240 */    92,   93,   94,   46,    0,   48,   32,   92,   93,   94,
 /*   250 */    93,   37,   36,   39,   71,   76,   72,   21,   69,   76,
 /*   260 */    76,   41,   73,   74,   75,   70,   71,   47,   48,   71,
 /*   270 */    91,   76,   63,   64,   76,   66,   93,   94,   80,   71,
 /*   280 */    41,   45,    0,   48,   76,   17,   47,   48,   93,   71,
 /*   290 */    71,   93,   71,   85,   76,   76,   66,   76,   71,    9,
 /*   300 */    71,   93,   24,   76,   71,   76,   16,   29,   76,   76,
 /*   310 */     0,   93,   93,   71,   93,   83,   84,   49,   76,   71,
 /*   320 */    93,    0,   93,   71,   76,   71,   93,   24,   76,   20,
 /*   330 */    76,   71,   29,   71,   71,   93,   76,   71,   76,   76,
 /*   340 */    11,   93,   76,   71,   71,   93,   71,   93,   76,   76,
 /*   350 */    21,   76,   71,   93,    0,   93,   93,   76,   71,   93,
 /*   360 */     0,    0,   41,   76,    0,   93,   93,   71,   93,   48,
 /*   370 */    71,    0,   76,   71,   93,   76,   71,   71,   76,    0,
 /*   380 */    93,   76,   76,   71,    0,   71,   71,   22,   76,   93,
 /*   390 */    76,   76,   93,    0,   40,   93,    0,   22,   93,   93,
 /*   400 */    35,   21,   48,   23,   40,   93,   20,   93,   93,   21,
 /*   410 */    35,   23,   48,   78,   20,   20,   81,   62,    0,   48,
 /*   420 */    72,   66,   36,    0,   76,   76,    0,   48,    0,   42,
 /*   430 */    36,   36,   48,   84,   62,   72,   22,   21,   66,   76,
 /*   440 */    66,   48,    0,    0,   48,   35,   17,   49,   35,    0,
 /*   450 */    42,   20,    0,    0,    0,   66,   66,   66,    0,    0,
 /*   460 */     0,   21,   21,   25,   25,   29,   48,   33,   76,   24,
 /*   470 */    24,   48,   25,   76,   24,   76,   76,   76,   76,   76,
 /*   480 */    25,   25,   25,   76,    0,   24,   24,   21,   25,   21,
 /*   490 */    21,   76,    0,   81,    0,    0,   66,   20,    1,   35,
 /*   500 */    35,   34,    0,   66,    0,   19,   95,   95,   38,
};
#define YY_SHIFT_USE_DFLT (-2)
static short yy_shift_ofst[] = {
 /*     0 */   214,  116,  244,  282,  310,  360,  177,  197,  235,  361,
 /*    10 */   176,  222,  220,   88,  371,  426,  428,  387,   69,  309,
 /*    20 */    69,   -2,  107,   -2,   -2,   -2,   -2,  414,  416,   -2,
 /*    30 */    -2,  379,  442,  443,  114,   40,  114,  114,   78,  114,
 /*    40 */    78,  114,  199,  114,  199,  114,  199,  114,  159,  114,
 /*    50 */   159,  114,   62,  114,   62,  114,   62,  114,   62,  114,
 /*    60 */    62,  114,   62,  114,  174,  290,  114,  429,  410,   70,
 /*    70 */    40,  268,   -2,  398,   -2,  104,   -2,   70,   -2,  365,
 /*    80 */    47,  142,   -2,   -2,   -2,   -2,  114,  429,  114,   23,
 /*    90 */    -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,  413,
 /*   100 */    70,  216,   -2,   78,  449,  408,  236,  431,  236,   -2,
 /*   110 */    -2,   -2,   -2,  384,  452,  239,  393,  453,  321,  396,
 /*   120 */   454,  458,  459,  460,  114,   40,   92,  141,  440,  172,
 /*   130 */   180,   -2,   -2,  380,  441,   -2,   -2,  440,  438,  114,
 /*   140 */    40,  445,  440,  439,  114,   40,  446,  440,   -2,  278,
 /*   150 */   440,  447,  114,   40,  450,  440,  455,  114,   40,  303,
 /*   160 */   440,  456,  114,   40,  461,  440,  457,  114,   40,  436,
 /*   170 */   462,  440,  463,  114,   40,  440,   -2,  388,  466,   -2,
 /*   180 */    -2,   -2,   -2,   92,   -2,   -2,  375,  329,   -2,   -1,
 /*   190 */   469,   -2,   -2,   -2,  434,  440,  146,  464,  114,  386,
 /*   200 */   484,  114,   -2,   40,   -2,  468,  394,  467,  465,  114,
 /*   210 */   395,  492,  468,   -2,   -2,   -2,  354,  418,  494,  495,
 /*   220 */   440,  470,  440,  477,  440,   -2,  497,  114,   -2,   40,
 /*   230 */    -2,  364,  423,  502,  504,  486,  440,   -2,
};
#define YY_REDUCE_USE_DFLT (-46)
static short yy_reduce_ofst[] = {
 /*     0 */    97,  -46,  -46,  -46,  -46,  -46,  -45,  209,  -43,  -46,
 /*    10 */   -46,  -46,   -3,   38,  230,  -46,  -46,  -46,  106,  -46,
 /*    20 */    50,  -46,  -46,  -46,  -46,  -46,  -46,  -46,  -46,  -46,
 /*    30 */   -46,  374,  -46,  -46,  218,  -46,  219,  221,  -46,  227,
 /*    40 */   -46,  229,  -46,  233,  -46,  242,  -46,  248,  -46,  252,
 /*    50 */   -46,  254,  -46,  260,  -46,  262,  -46,  263,  -46,  266,
 /*    60 */   -46,  272,  -46,  273,  -46,  -46,  275,  -46,  -46,   54,
 /*    70 */   -46,  -46,  -46,  -46,  -46,  -46,  -46,  183,  -46,  -46,
 /*    80 */   148,  -46,  -46,  -46,  -46,  -46,  281,  -46,  287,  -46,
 /*    90 */   -46,  -46,  -46,  -46,  -46,  -46,  -46,  -46,  -46,  -46,
 /*   100 */   155,  -46,  -46,  -46,  -46,  -46,   42,  -46,  179,  -46,
 /*   110 */   -46,  -46,  -46,  389,  -46,  164,  390,  -46,   44,  391,
 /*   120 */   -46,  -46,  -46,  -46,  296,  -46,   41,  -46,  133,  189,
 /*   130 */    -8,  -46,  -46,  -46,  -46,  -46,  -46,  392,  -46,  299,
 /*   140 */   -46,  -46,  397,  -46,  302,  -46,  -46,  399,  -46,  -46,
 /*   150 */   400,  -46,  305,  -46,  -46,  401,  -46,  306,  -46,  -46,
 /*   160 */   402,  -46,  312,  -46,  -46,  403,  -46,  314,  -46,  -46,
 /*   170 */   -46,  407,  -46,  315,  -46,  184,  -46,  -46,  -46,  -46,
 /*   180 */   -46,  -46,  -46,  195,  -46,  -46,  -46,  -46,  -46,  -46,
 /*   190 */   -46,  -46,  -46,  -46,  -46,  415,  -46,  -46,    9,  -46,
 /*   200 */   -46,  198,  -46,  -46,  -46,  335,  -46,  -46,  -46,  157,
 /*   210 */   -46,  -46,  412,  -46,  -46,  -46,  355,  430,  -46,  -46,
 /*   220 */   348,  -46,  232,  -46,  349,  -46,  -46,  208,  -46,  -46,
 /*   230 */   -46,  372,  437,  -46,  -46,  -46,  363,  -46,
};
static YYACTIONTYPE yy_default[] = {
 /*     0 */   378,  378,  378,  378,  378,  378,  378,  378,  378,  378,
 /*    10 */   378,  378,  378,  378,  378,  378,  378,  378,  378,  325,
 /*    20 */   378,  326,  328,  329,  330,  331,  332,  377,  378,  376,
 /*    30 */   327,  378,  378,  378,  378,  338,  378,  378,  340,  378,
 /*    40 */   342,  378,  343,  378,  344,  378,  345,  378,  346,  378,
 /*    50 */   347,  378,  348,  378,  349,  378,  350,  378,  351,  378,
 /*    60 */   352,  378,  353,  378,  354,  378,  378,  355,  378,  378,
 /*    70 */   364,  378,  365,  378,  366,  378,  356,  378,  358,  377,
 /*    80 */   378,  378,  359,  360,  362,  363,  378,  367,  378,  378,
 /*    90 */   368,  369,  370,  371,  372,  373,  374,  375,  361,  378,
 /*   100 */   378,  378,  357,  341,  378,  378,  378,  333,  378,  334,
 /*   110 */   336,  337,  335,  378,  378,  378,  378,  378,  378,  378,
 /*   120 */   378,  378,  378,  378,  378,  324,  378,  378,  378,  267,
 /*   130 */   268,  278,  280,  281,  378,  282,  283,  378,  284,  378,
 /*   140 */   285,  378,  378,  286,  378,  287,  378,  378,  288,  378,
 /*   150 */   378,  289,  378,  291,  378,  378,  290,  378,  292,  378,
 /*   160 */   378,  293,  378,  295,  378,  378,  294,  378,  296,  378,
 /*   170 */   378,  378,  297,  378,  298,  378,  276,  323,  378,  321,
 /*   180 */   322,  279,  277,  378,  269,  271,  377,  378,  272,  275,
 /*   190 */   378,  273,  274,  270,  378,  378,  378,  378,  378,  378,
 /*   200 */   378,  378,  301,  303,  302,  378,  378,  378,  378,  378,
 /*   210 */   378,  378,  378,  304,  306,  305,  378,  378,  378,  378,
 /*   220 */   378,  378,  378,  311,  378,  312,  378,  378,  314,  315,
 /*   230 */   313,  378,  378,  378,  378,  378,  378,  320,
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
  "$",             "EQUALS",        "NOTEQUALS",     "LESS",        
  "GREATER",       "GREATEREQUAL",  "LESSEQUAL",     "AND",         
  "OR",            "LIKE",          "DIVIDE",        "TIMES",       
  "MOD",           "PLUS",          "MINUS",         "IS",          
  "IN",            "NOT",           "SELECT",        "FROM",        
  "COMMA",         "IDENTIFIER",    "DOT",           "AS",          
  "JOIN",          "ON",            "INNER",         "CROSS",       
  "LEFT",          "OUTER",         "RIGHT",         "FULL",        
  "INSERT",        "INTO",          "VALUES",        "BRACKET_OPEN",
  "BRACKET_CLOSE",  "UPDATE",        "SET",           "DELETE",      
  "WHERE",         "ORDER",         "BY",            "ASC",         
  "DESC",          "INTEGER",       "GROUP",         "HAVING",      
  "LIMIT",         "NULL",          "STRING",        "DOUBLE",      
  "NPLACEHOLDER",  "SPLACEHOLDER",  "error",         "program",     
  "query_language",  "select_statement",  "insert_statement",  "update_statement",
  "delete_statement",  "select_clause",  "where_clause",  "order_clause",
  "group_clause",  "having_clause",  "limit_clause",  "column_list", 
  "associated_name_list",  "join_list",     "column_item",   "expr",        
  "associated_name",  "join_item",     "join_associated_name",  "join_clause", 
  "qualified_name",  "values_list",   "field_list",    "value_list",  
  "value_item",    "field_item",    "update_clause",  "update_item_list",
  "update_item",   "new_value",     "delete_clause",  "order_list",  
  "order_item",    "order_qualified_or_int",  "group_list",    "group_item",  
  "argument_list",  "function_call",  "argument_item",
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
 /*  11 */ "select_statement ::= select_clause where_clause group_clause order_clause limit_clause",
 /*  12 */ "select_statement ::= select_clause where_clause group_clause having_clause order_clause",
 /*  13 */ "select_statement ::= select_clause where_clause limit_clause",
 /*  14 */ "select_statement ::= select_clause where_clause order_clause limit_clause",
 /*  15 */ "select_statement ::= select_clause where_clause group_clause limit_clause",
 /*  16 */ "select_statement ::= select_clause where_clause group_clause having_clause limit_clause",
 /*  17 */ "select_statement ::= select_clause order_clause",
 /*  18 */ "select_statement ::= select_clause group_clause order_clause",
 /*  19 */ "select_statement ::= select_clause group_clause having_clause order_clause",
 /*  20 */ "select_statement ::= select_clause order_clause limit_clause",
 /*  21 */ "select_statement ::= select_clause group_clause order_clause limit_clause",
 /*  22 */ "select_statement ::= select_clause where_clause group_clause having_clause order_clause limit_clause",
 /*  23 */ "select_statement ::= select_clause group_clause",
 /*  24 */ "select_statement ::= select_clause group_clause limit_clause",
 /*  25 */ "select_statement ::= select_clause group_clause having_clause",
 /*  26 */ "select_statement ::= select_clause group_clause having_clause limit_clause",
 /*  27 */ "select_statement ::= select_clause group_clause having_clause order_clause limit_clause",
 /*  28 */ "select_statement ::= select_clause limit_clause",
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
 /*  42 */ "join_item ::= join_associated_name",
 /*  43 */ "join_associated_name ::= join_clause",
 /*  44 */ "join_associated_name ::= join_clause AS IDENTIFIER",
 /*  45 */ "join_associated_name ::= join_clause IDENTIFIER",
 /*  46 */ "join_clause ::= JOIN qualified_name",
 /*  47 */ "join_clause ::= JOIN qualified_name ON expr",
 /*  48 */ "join_clause ::= INNER JOIN qualified_name",
 /*  49 */ "join_clause ::= INNER JOIN qualified_name ON expr",
 /*  50 */ "join_clause ::= CROSS JOIN qualified_name",
 /*  51 */ "join_clause ::= LEFT JOIN qualified_name",
 /*  52 */ "join_clause ::= LEFT OUTER JOIN qualified_name",
 /*  53 */ "join_clause ::= LEFT JOIN qualified_name ON expr",
 /*  54 */ "join_clause ::= LEFT OUTER JOIN qualified_name ON expr",
 /*  55 */ "join_clause ::= RIGHT JOIN qualified_name",
 /*  56 */ "join_clause ::= RIGHT OUTER JOIN qualified_name",
 /*  57 */ "join_clause ::= RIGHT JOIN qualified_name ON expr",
 /*  58 */ "join_clause ::= RIGHT OUTER JOIN qualified_name ON expr",
 /*  59 */ "join_clause ::= FULL OUTER JOIN qualified_name",
 /*  60 */ "join_clause ::= FULL OUTER JOIN qualified_name ON expr",
 /*  61 */ "insert_statement ::= INSERT INTO qualified_name VALUES BRACKET_OPEN values_list BRACKET_CLOSE",
 /*  62 */ "insert_statement ::= INSERT INTO qualified_name BRACKET_OPEN field_list BRACKET_CLOSE VALUES BRACKET_OPEN values_list BRACKET_CLOSE",
 /*  63 */ "values_list ::= values_list COMMA value_item",
 /*  64 */ "values_list ::= value_item",
 /*  65 */ "value_item ::= expr",
 /*  66 */ "field_list ::= field_list COMMA field_item",
 /*  67 */ "field_list ::= field_item",
 /*  68 */ "field_item ::= IDENTIFIER",
 /*  69 */ "update_statement ::= update_clause",
 /*  70 */ "update_statement ::= update_clause where_clause",
 /*  71 */ "update_statement ::= update_clause limit_clause",
 /*  72 */ "update_statement ::= update_clause where_clause limit_clause",
 /*  73 */ "update_clause ::= UPDATE associated_name SET update_item_list",
 /*  74 */ "update_item_list ::= update_item_list COMMA update_item",
 /*  75 */ "update_item_list ::= update_item",
 /*  76 */ "update_item ::= qualified_name EQUALS new_value",
 /*  77 */ "new_value ::= expr",
 /*  78 */ "delete_statement ::= delete_clause",
 /*  79 */ "delete_statement ::= delete_clause where_clause",
 /*  80 */ "delete_statement ::= delete_clause limit_clause",
 /*  81 */ "delete_statement ::= delete_clause where_clause limit_clause",
 /*  82 */ "delete_clause ::= DELETE FROM associated_name",
 /*  83 */ "associated_name ::= qualified_name AS IDENTIFIER",
 /*  84 */ "associated_name ::= qualified_name IDENTIFIER",
 /*  85 */ "associated_name ::= qualified_name",
 /*  86 */ "where_clause ::= WHERE expr",
 /*  87 */ "order_clause ::= ORDER BY order_list",
 /*  88 */ "order_list ::= order_list COMMA order_item",
 /*  89 */ "order_list ::= order_item",
 /*  90 */ "order_item ::= order_qualified_or_int",
 /*  91 */ "order_item ::= order_qualified_or_int ASC",
 /*  92 */ "order_item ::= order_qualified_or_int DESC",
 /*  93 */ "order_qualified_or_int ::= qualified_name",
 /*  94 */ "order_qualified_or_int ::= INTEGER",
 /*  95 */ "group_clause ::= GROUP BY group_list",
 /*  96 */ "group_list ::= group_list COMMA group_item",
 /*  97 */ "group_list ::= group_item",
 /*  98 */ "group_item ::= qualified_name",
 /*  99 */ "group_item ::= INTEGER",
 /* 100 */ "having_clause ::= HAVING expr",
 /* 101 */ "limit_clause ::= LIMIT INTEGER",
 /* 102 */ "expr ::= MINUS expr",
 /* 103 */ "expr ::= expr MINUS expr",
 /* 104 */ "expr ::= expr PLUS expr",
 /* 105 */ "expr ::= expr TIMES expr",
 /* 106 */ "expr ::= expr DIVIDE expr",
 /* 107 */ "expr ::= expr MOD expr",
 /* 108 */ "expr ::= expr AND expr",
 /* 109 */ "expr ::= expr OR expr",
 /* 110 */ "expr ::= expr EQUALS expr",
 /* 111 */ "expr ::= expr NOTEQUALS expr",
 /* 112 */ "expr ::= expr LESS expr",
 /* 113 */ "expr ::= expr GREATER expr",
 /* 114 */ "expr ::= expr GREATEREQUAL expr",
 /* 115 */ "expr ::= expr LESSEQUAL expr",
 /* 116 */ "expr ::= expr LIKE expr",
 /* 117 */ "expr ::= expr NOT LIKE expr",
 /* 118 */ "expr ::= expr IN BRACKET_OPEN argument_list BRACKET_CLOSE",
 /* 119 */ "expr ::= expr NOT IN BRACKET_OPEN argument_list BRACKET_CLOSE",
 /* 120 */ "expr ::= function_call",
 /* 121 */ "function_call ::= IDENTIFIER BRACKET_OPEN argument_list BRACKET_CLOSE",
 /* 122 */ "function_call ::= IDENTIFIER BRACKET_OPEN BRACKET_CLOSE",
 /* 123 */ "argument_list ::= argument_list COMMA argument_item",
 /* 124 */ "argument_list ::= argument_item",
 /* 125 */ "argument_item ::= TIMES",
 /* 126 */ "argument_item ::= expr",
 /* 127 */ "expr ::= expr IS NULL",
 /* 128 */ "expr ::= expr IS NOT NULL",
 /* 129 */ "expr ::= NOT expr",
 /* 130 */ "expr ::= BRACKET_OPEN expr BRACKET_CLOSE",
 /* 131 */ "expr ::= qualified_name",
 /* 132 */ "expr ::= INTEGER",
 /* 133 */ "expr ::= STRING",
 /* 134 */ "expr ::= DOUBLE",
 /* 135 */ "expr ::= NULL",
 /* 136 */ "expr ::= NPLACEHOLDER",
 /* 137 */ "expr ::= SPLACEHOLDER",
 /* 138 */ "qualified_name ::= IDENTIFIER DOT IDENTIFIER",
 /* 139 */ "qualified_name ::= IDENTIFIER",
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
#line 453 "parser.lemon"
{
	if ((yypminor->yy0)) {
		efree((yypminor->yy0)->token);
		efree((yypminor->yy0));
	}
}
#line 1052 "parser.c"
      break;
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
    case 78:
    case 79:
    case 81:
    case 82:
    case 83:
    case 84:
    case 86:
    case 87:
    case 88:
    case 90:
    case 91:
    case 92:
    case 93:
    case 94:
#line 464 "parser.lemon"
{ zval_ptr_dtor(&(yypminor->yy48)); }
#line 1091 "parser.c"
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
  { 55, 1 },
  { 56, 1 },
  { 56, 1 },
  { 56, 1 },
  { 56, 1 },
  { 57, 1 },
  { 57, 2 },
  { 57, 3 },
  { 57, 3 },
  { 57, 4 },
  { 57, 4 },
  { 57, 5 },
  { 57, 5 },
  { 57, 3 },
  { 57, 4 },
  { 57, 4 },
  { 57, 5 },
  { 57, 2 },
  { 57, 3 },
  { 57, 4 },
  { 57, 3 },
  { 57, 4 },
  { 57, 6 },
  { 57, 2 },
  { 57, 3 },
  { 57, 3 },
  { 57, 4 },
  { 57, 5 },
  { 57, 2 },
  { 61, 4 },
  { 61, 5 },
  { 67, 3 },
  { 67, 1 },
  { 70, 1 },
  { 70, 3 },
  { 70, 3 },
  { 70, 2 },
  { 70, 1 },
  { 68, 3 },
  { 68, 1 },
  { 69, 2 },
  { 69, 1 },
  { 73, 1 },
  { 74, 1 },
  { 74, 3 },
  { 74, 2 },
  { 75, 2 },
  { 75, 4 },
  { 75, 3 },
  { 75, 5 },
  { 75, 3 },
  { 75, 3 },
  { 75, 4 },
  { 75, 5 },
  { 75, 6 },
  { 75, 3 },
  { 75, 4 },
  { 75, 5 },
  { 75, 6 },
  { 75, 4 },
  { 75, 6 },
  { 58, 7 },
  { 58, 10 },
  { 77, 3 },
  { 77, 1 },
  { 80, 1 },
  { 78, 3 },
  { 78, 1 },
  { 81, 1 },
  { 59, 1 },
  { 59, 2 },
  { 59, 2 },
  { 59, 3 },
  { 82, 4 },
  { 83, 3 },
  { 83, 1 },
  { 84, 3 },
  { 85, 1 },
  { 60, 1 },
  { 60, 2 },
  { 60, 2 },
  { 60, 3 },
  { 86, 3 },
  { 72, 3 },
  { 72, 2 },
  { 72, 1 },
  { 62, 2 },
  { 63, 3 },
  { 87, 3 },
  { 87, 1 },
  { 88, 1 },
  { 88, 2 },
  { 88, 2 },
  { 89, 1 },
  { 89, 1 },
  { 64, 3 },
  { 90, 3 },
  { 90, 1 },
  { 91, 1 },
  { 91, 1 },
  { 65, 2 },
  { 66, 2 },
  { 71, 2 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 4 },
  { 71, 5 },
  { 71, 6 },
  { 71, 1 },
  { 93, 4 },
  { 93, 3 },
  { 92, 3 },
  { 92, 1 },
  { 94, 1 },
  { 94, 1 },
  { 71, 3 },
  { 71, 4 },
  { 71, 2 },
  { 71, 3 },
  { 71, 1 },
  { 71, 1 },
  { 71, 1 },
  { 71, 1 },
  { 71, 1 },
  { 71, 1 },
  { 71, 1 },
  { 76, 3 },
  { 76, 1 },
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
  **  #line <lineno> <grammarfile>
  **     { ... }           // User supplied code
  **  #line <lineno> <thisfile>
  **     break;
  */
      case 0:
#line 460 "parser.lemon"
{
	status->ret = yymsp[0].minor.yy48;
}
#line 1448 "parser.c"
        break;
      case 1:
      case 2:
      case 3:
      case 4:
      case 32:
      case 39:
      case 41:
      case 42:
      case 64:
      case 65:
      case 67:
      case 75:
      case 77:
      case 89:
      case 93:
      case 97:
      case 98:
      case 120:
      case 124:
      case 126:
      case 131:
#line 466 "parser.lemon"
{
	yygotominor.yy48 = yymsp[0].minor.yy48;
}
#line 1475 "parser.c"
        break;
      case 5:
#line 484 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[0].minor.yy48, NULL, NULL, NULL, NULL, NULL);
}
#line 1482 "parser.c"
        break;
      case 6:
#line 488 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL, NULL, NULL, NULL);
}
#line 1489 "parser.c"
        break;
      case 7:
#line 492 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL, NULL, NULL);
}
#line 1496 "parser.c"
        break;
      case 8:
#line 496 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy48, NULL, NULL);
}
#line 1503 "parser.c"
        break;
      case 9:
#line 500 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, yymsp[-2].minor.yy48, NULL, yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL);
}
#line 1510 "parser.c"
        break;
      case 10:
#line 504 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, yymsp[-2].minor.yy48, yymsp[0].minor.yy48, yymsp[-1].minor.yy48, NULL, NULL);
}
#line 1517 "parser.c"
        break;
      case 11:
#line 508 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-4].minor.yy48, yymsp[-3].minor.yy48, yymsp[-1].minor.yy48, yymsp[-2].minor.yy48, NULL, yymsp[0].minor.yy48);
}
#line 1524 "parser.c"
        break;
      case 12:
#line 512 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-4].minor.yy48, yymsp[-3].minor.yy48, yymsp[0].minor.yy48, yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, NULL);
}
#line 1531 "parser.c"
        break;
      case 13:
#line 516 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, NULL, NULL, NULL, yymsp[0].minor.yy48);
}
#line 1538 "parser.c"
        break;
      case 14:
#line 520 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, NULL, NULL, yymsp[0].minor.yy48);
}
#line 1545 "parser.c"
        break;
      case 15:
#line 524 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, yymsp[-2].minor.yy48, NULL, yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy48);
}
#line 1552 "parser.c"
        break;
      case 16:
#line 528 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-4].minor.yy48, yymsp[-3].minor.yy48, NULL, yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
}
#line 1559 "parser.c"
        break;
      case 17:
#line 532 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy48, NULL, NULL, NULL);
}
#line 1566 "parser.c"
        break;
      case 18:
#line 536 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-2].minor.yy48, NULL, yymsp[0].minor.yy48, yymsp[-1].minor.yy48, NULL, NULL);
}
#line 1573 "parser.c"
        break;
      case 19:
#line 540 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, NULL, yymsp[0].minor.yy48, yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, NULL);
}
#line 1580 "parser.c"
        break;
      case 20:
#line 544 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-2].minor.yy48, NULL, yymsp[-1].minor.yy48, NULL, NULL, yymsp[0].minor.yy48);
}
#line 1587 "parser.c"
        break;
      case 21:
#line 548 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, NULL, yymsp[-1].minor.yy48, yymsp[-2].minor.yy48, NULL, yymsp[0].minor.yy48);
}
#line 1594 "parser.c"
        break;
      case 22:
#line 552 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-5].minor.yy48, yymsp[-4].minor.yy48, yymsp[-1].minor.yy48, yymsp[-3].minor.yy48, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
}
#line 1601 "parser.c"
        break;
      case 23:
#line 556 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-1].minor.yy48, NULL, NULL, yymsp[0].minor.yy48, NULL, NULL);
}
#line 1608 "parser.c"
        break;
      case 24:
#line 560 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-2].minor.yy48, NULL, NULL, yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy48);
}
#line 1615 "parser.c"
        break;
      case 25:
#line 564 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-2].minor.yy48, NULL, NULL, yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL);
}
#line 1622 "parser.c"
        break;
      case 26:
#line 568 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-3].minor.yy48, NULL, NULL, yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
}
#line 1629 "parser.c"
        break;
      case 27:
#line 572 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-4].minor.yy48, NULL, yymsp[-1].minor.yy48, yymsp[-3].minor.yy48, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
}
#line 1636 "parser.c"
        break;
      case 28:
#line 576 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_statement(yymsp[-1].minor.yy48, NULL, NULL, NULL, NULL, yymsp[0].minor.yy48);
}
#line 1643 "parser.c"
        break;
      case 29:
#line 582 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_clause(yymsp[-2].minor.yy48, yymsp[0].minor.yy48, NULL);
  yy_destructor(18,&yymsp[-3].minor);
  yy_destructor(19,&yymsp[-1].minor);
}
#line 1652 "parser.c"
        break;
      case 30:
#line 586 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_select_clause(yymsp[-3].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(18,&yymsp[-4].minor);
  yy_destructor(19,&yymsp[-2].minor);
}
#line 1661 "parser.c"
        break;
      case 31:
      case 38:
      case 63:
      case 66:
      case 74:
      case 88:
      case 96:
      case 123:
#line 592 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_zval_list(yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(20,&yymsp[-1].minor);
}
#line 1676 "parser.c"
        break;
      case 33:
      case 125:
#line 602 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_column_item(PHQL_T_ALL, NULL, NULL, NULL);
  yy_destructor(11,&yymsp[0].minor);
}
#line 1685 "parser.c"
        break;
      case 34:
#line 606 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_column_item(PHQL_T_DOMAINALL, NULL, yymsp[-2].minor.yy0, NULL);
  yy_destructor(22,&yymsp[-1].minor);
  yy_destructor(11,&yymsp[0].minor);
}
#line 1694 "parser.c"
        break;
      case 35:
#line 610 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-2].minor.yy48, NULL, yymsp[0].minor.yy0);
  yy_destructor(23,&yymsp[-1].minor);
}
#line 1702 "parser.c"
        break;
      case 36:
#line 614 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy0);
}
#line 1709 "parser.c"
        break;
      case 37:
#line 618 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_column_item(PHQL_T_EXPR, yymsp[0].minor.yy48, NULL, NULL);
}
#line 1716 "parser.c"
        break;
      case 40:
#line 634 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_zval_list(yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
}
#line 1723 "parser.c"
        break;
      case 43:
#line 650 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_item(yymsp[0].minor.yy48, NULL);
}
#line 1730 "parser.c"
        break;
      case 44:
#line 654 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_item(yymsp[-2].minor.yy48, yymsp[0].minor.yy0);
  yy_destructor(23,&yymsp[-1].minor);
}
#line 1738 "parser.c"
        break;
      case 45:
#line 658 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_item(yymsp[-1].minor.yy48, yymsp[0].minor.yy0);
}
#line 1745 "parser.c"
        break;
      case 46:
#line 664 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_clause(PHQL_T_INNERJOIN, yymsp[0].minor.yy48, NULL);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1753 "parser.c"
        break;
      case 47:
#line 668 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_clause(PHQL_T_INNERJOIN, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1762 "parser.c"
        break;
      case 48:
#line 672 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_clause(PHQL_T_INNERJOIN, yymsp[0].minor.yy48, NULL);
  yy_destructor(26,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1771 "parser.c"
        break;
      case 49:
#line 676 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_clause(PHQL_T_INNERJOIN, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(26,&yymsp[-4].minor);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1781 "parser.c"
        break;
      case 50:
#line 680 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_clause(PHQL_T_CROSSJOIN, yymsp[0].minor.yy48, NULL);
  yy_destructor(27,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1790 "parser.c"
        break;
      case 51:
#line 684 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_clause(PHQL_T_LEFTJOIN, yymsp[0].minor.yy48, NULL);
  yy_destructor(28,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1799 "parser.c"
        break;
      case 52:
#line 688 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_clause(PHQL_T_LEFTJOIN, yymsp[0].minor.yy48, NULL);
  yy_destructor(28,&yymsp[-3].minor);
  yy_destructor(29,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1809 "parser.c"
        break;
      case 53:
#line 692 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_clause(PHQL_T_LEFTJOIN, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(28,&yymsp[-4].minor);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1819 "parser.c"
        break;
      case 54:
#line 696 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_clause(PHQL_T_LEFTJOIN, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(28,&yymsp[-5].minor);
  yy_destructor(29,&yymsp[-4].minor);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1830 "parser.c"
        break;
      case 55:
#line 700 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_clause(PHQL_T_RIGHTJOIN, yymsp[0].minor.yy48, NULL);
  yy_destructor(30,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1839 "parser.c"
        break;
      case 56:
#line 704 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_clause(PHQL_T_RIGHTJOIN, yymsp[0].minor.yy48, NULL);
  yy_destructor(30,&yymsp[-3].minor);
  yy_destructor(29,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1849 "parser.c"
        break;
      case 57:
#line 708 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_clause(PHQL_T_RIGHTJOIN, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(30,&yymsp[-4].minor);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1859 "parser.c"
        break;
      case 58:
#line 712 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_clause(PHQL_T_RIGHTJOIN, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(30,&yymsp[-5].minor);
  yy_destructor(29,&yymsp[-4].minor);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1870 "parser.c"
        break;
      case 59:
#line 716 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_clause(PHQL_T_FULLOUTER, yymsp[0].minor.yy48, NULL);
  yy_destructor(31,&yymsp[-3].minor);
  yy_destructor(29,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1880 "parser.c"
        break;
      case 60:
#line 720 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_join_clause(PHQL_T_FULLOUTER, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(31,&yymsp[-5].minor);
  yy_destructor(29,&yymsp[-4].minor);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1891 "parser.c"
        break;
      case 61:
#line 727 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_insert_statement(yymsp[-4].minor.yy48, NULL, yymsp[-1].minor.yy48);
  yy_destructor(32,&yymsp[-6].minor);
  yy_destructor(33,&yymsp[-5].minor);
  yy_destructor(34,&yymsp[-3].minor);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
#line 1903 "parser.c"
        break;
      case 62:
#line 731 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_insert_statement(yymsp[-7].minor.yy48, yymsp[-5].minor.yy48, yymsp[-1].minor.yy48);
  yy_destructor(32,&yymsp[-9].minor);
  yy_destructor(33,&yymsp[-8].minor);
  yy_destructor(35,&yymsp[-6].minor);
  yy_destructor(36,&yymsp[-4].minor);
  yy_destructor(34,&yymsp[-3].minor);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
#line 1917 "parser.c"
        break;
      case 68:
      case 139:
#line 761 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_qualified_name(yymsp[0].minor.yy0, NULL);
}
#line 1925 "parser.c"
        break;
      case 69:
#line 769 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_update_statement(yymsp[0].minor.yy48, NULL, NULL);
}
#line 1932 "parser.c"
        break;
      case 70:
#line 773 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_update_statement(yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL);
}
#line 1939 "parser.c"
        break;
      case 71:
#line 777 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_update_statement(yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy48);
}
#line 1946 "parser.c"
        break;
      case 72:
#line 781 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_update_statement(yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
}
#line 1953 "parser.c"
        break;
      case 73:
#line 787 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_update_clause(yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(37,&yymsp[-3].minor);
  yy_destructor(38,&yymsp[-1].minor);
}
#line 1962 "parser.c"
        break;
      case 76:
#line 803 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_update_item(yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(1,&yymsp[-1].minor);
}
#line 1970 "parser.c"
        break;
      case 78:
#line 815 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_delete_statement(yymsp[0].minor.yy48, NULL, NULL);
}
#line 1977 "parser.c"
        break;
      case 79:
#line 819 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_delete_statement(yymsp[-1].minor.yy48, yymsp[0].minor.yy48, NULL);
}
#line 1984 "parser.c"
        break;
      case 80:
#line 823 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_delete_statement(yymsp[-1].minor.yy48, NULL, yymsp[0].minor.yy48);
}
#line 1991 "parser.c"
        break;
      case 81:
#line 827 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_delete_statement(yymsp[-2].minor.yy48, yymsp[-1].minor.yy48, yymsp[0].minor.yy48);
}
#line 1998 "parser.c"
        break;
      case 82:
#line 833 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_delete_clause(yymsp[0].minor.yy48);
  yy_destructor(39,&yymsp[-2].minor);
  yy_destructor(19,&yymsp[-1].minor);
}
#line 2007 "parser.c"
        break;
      case 83:
#line 839 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_assoc_name(yymsp[-2].minor.yy48, yymsp[0].minor.yy0);
  yy_destructor(23,&yymsp[-1].minor);
}
#line 2015 "parser.c"
        break;
      case 84:
#line 843 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_assoc_name(yymsp[-1].minor.yy48, yymsp[0].minor.yy0);
}
#line 2022 "parser.c"
        break;
      case 85:
#line 847 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_assoc_name(yymsp[0].minor.yy48, NULL);
}
#line 2029 "parser.c"
        break;
      case 86:
#line 853 "parser.lemon"
{
	yygotominor.yy48 = yymsp[0].minor.yy48;
  yy_destructor(40,&yymsp[-1].minor);
}
#line 2037 "parser.c"
        break;
      case 87:
#line 859 "parser.lemon"
{
	yygotominor.yy48 = yymsp[0].minor.yy48;
  yy_destructor(41,&yymsp[-2].minor);
  yy_destructor(42,&yymsp[-1].minor);
}
#line 2046 "parser.c"
        break;
      case 90:
#line 875 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_order_item(yymsp[0].minor.yy48, 0);
}
#line 2053 "parser.c"
        break;
      case 91:
#line 879 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_order_item(yymsp[-1].minor.yy48, PHQL_T_ASC);
  yy_destructor(43,&yymsp[0].minor);
}
#line 2061 "parser.c"
        break;
      case 92:
#line 883 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_order_item(yymsp[-1].minor.yy48, PHQL_T_DESC);
  yy_destructor(44,&yymsp[0].minor);
}
#line 2069 "parser.c"
        break;
      case 94:
      case 99:
      case 132:
#line 891 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_literal_zval(PHQL_T_INTEGER, yymsp[0].minor.yy0);
}
#line 2078 "parser.c"
        break;
      case 95:
#line 897 "parser.lemon"
{
	yygotominor.yy48 = yymsp[0].minor.yy48;
  yy_destructor(46,&yymsp[-2].minor);
  yy_destructor(42,&yymsp[-1].minor);
}
#line 2087 "parser.c"
        break;
      case 100:
#line 923 "parser.lemon"
{
	yygotominor.yy48 = yymsp[0].minor.yy48;
  yy_destructor(47,&yymsp[-1].minor);
}
#line 2095 "parser.c"
        break;
      case 101:
#line 929 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_literal_zval(PHQL_T_INTEGER, yymsp[0].minor.yy0);
  yy_destructor(48,&yymsp[-1].minor);
}
#line 2103 "parser.c"
        break;
      case 102:
#line 935 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_MINUS, NULL, yymsp[0].minor.yy48);
  yy_destructor(14,&yymsp[-1].minor);
}
#line 2111 "parser.c"
        break;
      case 103:
#line 939 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_SUB, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(14,&yymsp[-1].minor);
}
#line 2119 "parser.c"
        break;
      case 104:
#line 943 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_ADD, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(13,&yymsp[-1].minor);
}
#line 2127 "parser.c"
        break;
      case 105:
#line 947 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_MUL, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(11,&yymsp[-1].minor);
}
#line 2135 "parser.c"
        break;
      case 106:
#line 951 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_DIV, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(10,&yymsp[-1].minor);
}
#line 2143 "parser.c"
        break;
      case 107:
#line 955 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_MOD, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(12,&yymsp[-1].minor);
}
#line 2151 "parser.c"
        break;
      case 108:
#line 959 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_AND, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(7,&yymsp[-1].minor);
}
#line 2159 "parser.c"
        break;
      case 109:
#line 963 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_OR, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(8,&yymsp[-1].minor);
}
#line 2167 "parser.c"
        break;
      case 110:
#line 967 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_EQUALS, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(1,&yymsp[-1].minor);
}
#line 2175 "parser.c"
        break;
      case 111:
#line 971 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_NOTEQUALS, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(2,&yymsp[-1].minor);
}
#line 2183 "parser.c"
        break;
      case 112:
#line 975 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_LESS, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(3,&yymsp[-1].minor);
}
#line 2191 "parser.c"
        break;
      case 113:
#line 979 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_GREATER, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(4,&yymsp[-1].minor);
}
#line 2199 "parser.c"
        break;
      case 114:
#line 983 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_GREATEREQUAL, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(5,&yymsp[-1].minor);
}
#line 2207 "parser.c"
        break;
      case 115:
#line 987 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_LESSEQUAL, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(6,&yymsp[-1].minor);
}
#line 2215 "parser.c"
        break;
      case 116:
#line 991 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_LIKE, yymsp[-2].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(9,&yymsp[-1].minor);
}
#line 2223 "parser.c"
        break;
      case 117:
#line 995 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_NLIKE, yymsp[-3].minor.yy48, yymsp[0].minor.yy48);
  yy_destructor(17,&yymsp[-2].minor);
  yy_destructor(9,&yymsp[-1].minor);
}
#line 2232 "parser.c"
        break;
      case 118:
#line 999 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_IN, yymsp[-4].minor.yy48, yymsp[-1].minor.yy48);
  yy_destructor(16,&yymsp[-3].minor);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
#line 2242 "parser.c"
        break;
      case 119:
#line 1003 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_NOTIN, yymsp[-5].minor.yy48, yymsp[-1].minor.yy48);
  yy_destructor(17,&yymsp[-4].minor);
  yy_destructor(16,&yymsp[-3].minor);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
#line 2253 "parser.c"
        break;
      case 121:
#line 1013 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_func_call(yymsp[-3].minor.yy0, yymsp[-1].minor.yy48);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
#line 2262 "parser.c"
        break;
      case 122:
#line 1017 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_func_call(yymsp[-2].minor.yy0, NULL);
  yy_destructor(35,&yymsp[-1].minor);
  yy_destructor(36,&yymsp[0].minor);
}
#line 2271 "parser.c"
        break;
      case 127:
#line 1041 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_ISNULL, yymsp[-2].minor.yy48, NULL);
  yy_destructor(15,&yymsp[-1].minor);
  yy_destructor(49,&yymsp[0].minor);
}
#line 2280 "parser.c"
        break;
      case 128:
#line 1045 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_ISNOTNULL, yymsp[-3].minor.yy48, NULL);
  yy_destructor(15,&yymsp[-2].minor);
  yy_destructor(17,&yymsp[-1].minor);
  yy_destructor(49,&yymsp[0].minor);
}
#line 2290 "parser.c"
        break;
      case 129:
#line 1049 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_NOT, NULL, yymsp[0].minor.yy48);
  yy_destructor(17,&yymsp[-1].minor);
}
#line 2298 "parser.c"
        break;
      case 130:
#line 1053 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_expr(PHQL_T_ENCLOSED, yymsp[-1].minor.yy48, NULL);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
#line 2307 "parser.c"
        break;
      case 133:
#line 1065 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_literal_zval(PHQL_T_STRING, yymsp[0].minor.yy0);
}
#line 2314 "parser.c"
        break;
      case 134:
#line 1069 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_literal_zval(PHQL_T_DOUBLE, yymsp[0].minor.yy0);
}
#line 2321 "parser.c"
        break;
      case 135:
#line 1073 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_literal_zval(PHQL_T_NULL, NULL);
  yy_destructor(49,&yymsp[0].minor);
}
#line 2329 "parser.c"
        break;
      case 136:
#line 1077 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_placeholder_zval(PHQL_T_NPLACEHOLDER, yymsp[0].minor.yy0);
}
#line 2336 "parser.c"
        break;
      case 137:
#line 1081 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_placeholder_zval(PHQL_T_SPLACEHOLDER, yymsp[0].minor.yy0);
}
#line 2343 "parser.c"
        break;
      case 138:
#line 1087 "parser.lemon"
{
	yygotominor.yy48 = phql_ret_qualified_name(yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(22,&yymsp[-1].minor);
}
#line 2351 "parser.c"
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
#line 403 "parser.lemon"

	if (status->scanner_state->start) {
		{

			char *token_name = NULL;
			int token_found = 0;
			const phql_token_names *tokens = phql_tokens;
			int active_token = status->scanner_state->active_token;
			int near_length = strlen(status->scanner_state->start);

			if (active_token) {

				do {
					if (tokens->code == active_token) {
						token_name = tokens->name;
						token_found = 1;
						break;
					}
					++tokens;
				} while (tokens[0].code != 0);

			}

			if (!token_name) {
				token_name = estrndup("UNKNOWN", strlen("UNKNOWN"));
				token_found = 0;
			}

			status->syntax_error_len = 64 + strlen(token_name) + near_length;
			status->syntax_error = emalloc(sizeof(char)*status->syntax_error_len);
			if (near_length > 0) {
				sprintf(status->syntax_error, "Syntax error, unexpected token %s, near to %s", token_name, status->scanner_state->start);
			} else {
				sprintf(status->syntax_error, "Syntax error, unexpected token %s, at the end of query", token_name);
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

#line 2443 "parser.c"
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
  { PHQL_T_INTEGER,       "INTEGER" },
  { PHQL_T_DOUBLE,        "DOUBLE" },
  { PHQL_T_STRING,        "STRING" },
  { PHQL_T_IDENTIFIER,    "IDENTIFIER" },
  { PHQL_T_MINUS,         "MINUS"},
  { PHQL_T_ADD,           "+" },
  { PHQL_T_SUB,           "-" },
  { PHQL_T_MUL,           "*" },
  { PHQL_T_DIV,           "/" },
  { PHQL_T_MOD,           "%%" },
  { PHQL_T_AND,           "AND" },
  { PHQL_T_OR,            "OR" },
  { PHQL_T_LIKE,          "LIKE" },
  { PHQL_T_DOT,           "DOT" },
  { PHQL_T_COMMA,         "COMMA" },
  { PHQL_T_EQUALS,        "EQUALS" },
  { PHQL_T_NOTEQUALS,     "NOT EQUALS" },
  { PHQL_T_NOT,           "NOT" },
  { PHQL_T_LESS,          "<" },
  { PHQL_T_LESSEQUAL,     "<=" },
  { PHQL_T_GREATER,       ">" },
  { PHQL_T_GREATEREQUAL,  ">=" },
  { PHQL_T_BRACKET_OPEN,  "(" },
  { PHQL_T_BRACKET_CLOSE, ")" },
  { PHQL_T_NPLACEHOLDER,  "NUMERIC PLACEHOLDER" },
  { PHQL_T_SPLACEHOLDER,  "STRING PLACEHOLDER" },
  { PHQL_T_UPDATE,        "UPDATE" },
  { PHQL_T_SET,           "SET" },
  { PHQL_T_WHERE,         "WHERE" },
  { PHQL_T_DELETE,        "DELETE" },
  { PHQL_T_FROM,          "FROM" },
  { PHQL_T_AS,            "AS" },
  { PHQL_T_INSERT,        "INSERT" },
  { PHQL_T_INTO,          "INTO" },
  { PHQL_T_VALUES,        "VALUES" },
  { PHQL_T_SELECT,        "SELECT" },
  { PHQL_T_ORDER,         "ORDER" },
  { PHQL_T_BY,            "BY" },
  { PHQL_T_LIMIT,         "LIMIT" },
  { PHQL_T_GROUP,         "GROUP" },
  { PHQL_T_HAVING,        "HAVING" },
  { PHQL_T_IN,            "IN" },
  { PHQL_T_ON,            "ON" },
  { PHQL_T_INNER,         "INNER" },
  { PHQL_T_JOIN,          "JOIN" },
  { PHQL_T_LEFT,          "LEFT" },
  { PHQL_T_RIGHT,         "RIGHT" },
  { PHQL_T_IS,            "IS" },
  { PHQL_T_NULL,          "NULL" },
  { PHQL_T_NOTIN,         "NOT IN" },
  { PHQL_T_CROSS,         "CROSS" },
  { PHQL_T_OUTER,         "OUTER" },
  { PHQL_T_FULL,          "FULL" },
  { PHQL_T_ASC,           "ASC" },
  { PHQL_T_DESC,          "DESC" },
  {  0, NULL }
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
	pToken->token = estrndup(token->value, token->len);
	pToken->token_len = token->len;
	phql_(phql_parser, parsercode, pToken, parser_status);
	efree(token->value);
}

int phql_parse_phql(zval *result, zval *phql TSRMLS_DC){

	zval *error_msg;

	ZVAL_NULL(result);

	if(phql_internal_parse_phql(&result, Z_STRVAL_P(phql), &error_msg TSRMLS_CC) == FAILURE){
		phalcon_throw_exception_string(phalcon_mvc_model_exception_ce, Z_STRVAL_P(error_msg), Z_STRLEN_P(error_msg) TSRMLS_CC);
		return FAILURE;
	}

	return SUCCESS;
}

int phql_internal_parse_phql(zval **result, char *phql, zval **error_msg TSRMLS_DC) {

	char *error;
	phql_scanner_state *state;
	phql_scanner_token *token;
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
	token = emalloc(sizeof(phql_scanner_token));

	parser_status->status = PHQL_PARSING_OK;
	parser_status->scanner_state = state;
	parser_status->ret = NULL;

	state->active_token = 0;
	state->start = phql;

	state->end = state->start;

	while(0 <= (scanner_status = phql_get_token(state, token))) {

		state->active_token = token->opcode;

		switch(token->opcode){

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
			case PHQL_T_NOT:
				phql_(phql_parser, PHQL_NOT, NULL, parser_status);
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
				phql_parse_with_token(phql_parser, PHQL_T_INTEGER, PHQL_INTEGER, token, parser_status);
				break;
			case PHQL_T_DOUBLE:
				phql_parse_with_token(phql_parser, PHQL_T_DOUBLE, PHQL_DOUBLE, token, parser_status);
				break;
			case PHQL_T_STRING:
				phql_parse_with_token(phql_parser, PHQL_T_STRING, PHQL_STRING, token, parser_status);
				break;
			case PHQL_T_IDENTIFIER:
				phql_parse_with_token(phql_parser, PHQL_T_IDENTIFIER, PHQL_IDENTIFIER, token, parser_status);
				break;
			case PHQL_T_NPLACEHOLDER:
				phql_parse_with_token(phql_parser, PHQL_T_NPLACEHOLDER, PHQL_NPLACEHOLDER, token, parser_status);
				break;
			case PHQL_T_SPLACEHOLDER:
				phql_parse_with_token(phql_parser, PHQL_T_SPLACEHOLDER, PHQL_SPLACEHOLDER, token, parser_status);
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
			default:
				status = FAILURE;
				error = emalloc(sizeof(char)*32);
				sprintf(error, "scanner: unknown opcode %c", token->opcode);
				PHALCON_ALLOC_ZVAL_MM(*error_msg);
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

	state->active_token = 0;
	state->start = NULL;

	if (status != FAILURE) {
		switch (scanner_status) {
			case PHQL_SCANNER_RETCODE_ERR:
			case PHQL_SCANNER_RETCODE_IMPOSSIBLE:
				PHALCON_ALLOC_ZVAL_MM(*error_msg);
				if (state->start) {
					error = emalloc(sizeof(char)*(48+strlen(state->start)));
					sprintf(error, "Parsing error near to %s (%d)", state->start, status);
					ZVAL_STRING(*error_msg, error, 1);
					efree(error);
				} else {
					ZVAL_STRING(*error_msg, "Parsing error near to EOF", 1);
				}
				status = FAILURE;
				break;
			default:
				phql_(phql_parser, 0, NULL, parser_status);
		}
	}

	if (parser_status->status != PHQL_PARSING_OK) {
		status = FAILURE;
		PHALCON_ALLOC_ZVAL_MM(*error_msg);
		ZVAL_STRING(*error_msg, parser_status->syntax_error, 1);
		efree(parser_status->syntax_error);
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
	efree(token);

	return status;
}