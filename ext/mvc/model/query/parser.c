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

static zval *phql_ret_select_limit_clause(phql_parser_token *L, phql_parser_token *O)
{
	zval *ret;

	MAKE_STD_ZVAL(ret);
	array_init(ret);

	add_assoc_stringl(ret, "number", L->token, L->token_len, 1);
	efree(L->token);
	efree(L);

	if (O != NULL) {
		add_assoc_stringl(ret, "offset", O->token, O->token_len, 1);
		efree(O->token);
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


#line 396 "parser.c"
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
#define YYNOCODE 97
#define YYACTIONTYPE unsigned short int
#define phql_TOKENTYPE phql_parser_token*
typedef union {
  phql_TOKENTYPE yy0;
  zval* yy120;
  int yy193;
} YYMINORTYPE;
#define YYSTACKDEPTH 100
#define phql_ARG_SDECL phql_parser_status *status;
#define phql_ARG_PDECL ,phql_parser_status *status
#define phql_ARG_FETCH phql_parser_status *status = yypParser->status
#define phql_ARG_STORE yypParser->status = status
#define YYNSTATE 242
#define YYNRULE 142
#define YYERRORSYMBOL 54
#define YYERRSYMDT yy193
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
 /*     0 */    53,   55,   57,   59,   61,   63,   49,   51,   65,   45,
 /*    10 */    43,   47,   41,   38,   73,   70,   67,    7,  115,  117,
 /*    20 */   194,  125,  192,    9,   53,   55,   57,   59,   61,   63,
 /*    30 */    49,   51,   65,   45,   43,   47,   41,   38,   73,   70,
 /*    40 */    67,   53,   55,   57,   59,   61,   63,   49,   51,   65,
 /*    50 */    45,   43,   47,   41,   38,   73,   70,   67,   87,   92,
 /*    60 */   251,   39,   72,   33,   88,   15,   35,   93,   81,   49,
 /*    70 */    51,   65,   45,   43,   47,   41,   38,   73,   70,   67,
 /*    80 */   242,   87,   90,   85,   39,   80,  100,   88,   72,   25,
 /*    90 */    26,   81,   94,   93,  130,  185,   97,   95,   96,   98,
 /*   100 */    99,   19,   72,  187,   27,   90,   39,   93,   10,   88,
 /*   110 */    77,   80,   86,  188,  112,   94,   21,   32,   24,   97,
 /*   120 */    95,   96,   98,   99,   83,   80,   86,   90,   39,  109,
 /*   130 */   114,   88,  199,  207,  132,   81,  243,   94,  183,  134,
 /*   140 */   135,   97,   95,   96,   98,   99,   75,    8,   14,   90,
 /*   150 */   106,  244,  385,    1,    2,    3,    4,    5,    6,   94,
 /*   160 */    73,   70,   67,   97,   95,   96,   98,   99,   65,   45,
 /*   170 */    43,   47,   41,   38,   73,   70,   67,  247,   74,  218,
 /*   180 */   118,   27,  120,  124,  235,   45,   43,   47,   41,   38,
 /*   190 */    73,   70,   67,  177,   23,   24,  245,  139,  131,  143,
 /*   200 */   148,  151,  184,  161,  171,   16,  179,  121,   18,  139,
 /*   210 */   123,  143,  148,  151,   72,  161,  171,  126,   19,   93,
 /*   220 */   249,  246,  256,  107,  230,   10,   41,   38,   73,   70,
 /*   230 */    67,  129,  248,  229,  195,  191,  103,   80,   86,  205,
 /*   240 */    93,  205,  128,  250,   93,  201,   93,  212,  206,  343,
 /*   250 */   206,  265,  127,  133,  134,  135,  196,   93,   80,  186,
 /*   260 */   191,  224,   80,  239,   80,   93,  112,  344,   10,   12,
 /*   270 */   254,  233,  205,   19,   17,   80,   93,   93,  107,   29,
 /*   280 */    10,  204,  111,   80,   19,   11,  232,  267,   37,   68,
 /*   290 */    36,   10,   19,   93,   80,   80,  101,  105,   36,   10,
 /*   300 */    40,   42,   93,   28,   44,   93,   93,   46,   48,   93,
 /*   310 */    50,   80,   93,   93,  311,   93,   52,   54,   10,  264,
 /*   320 */    80,   93,   93,   80,   80,  178,  258,   80,   19,  179,
 /*   330 */    80,   80,   56,   80,  320,   10,   58,   93,  230,   80,
 /*   340 */    80,   93,  252,   60,   62,   64,  227,  234,   93,   93,
 /*   350 */    93,  259,   66,   69,  126,   80,   89,   93,   93,   80,
 /*   360 */    91,   93,  221,   13,  142,   93,   80,   80,   80,   93,
 /*   370 */    20,   30,  147,  155,  126,   80,   80,   93,   93,   80,
 /*   380 */   160,  165,  221,   80,  170,   93,   93,   80,  176,   93,
 /*   390 */    10,  260,   30,   93,   79,   80,   80,   79,   79,   10,
 /*   400 */    29,  261,  189,   80,   80,   82,  138,   80,  136,  190,
 /*   410 */    78,   80,  152,   84,  104,   82,  162,  156,  182,   31,
 /*   420 */   180,  166,  203,  208,  113,  214,  217,  203,  312,  219,
 /*   430 */   225,  236,  321,  241,  179,   22,  253,  179,  202,   10,
 /*   440 */    31,  209,   34,  213,  257,   71,   67,  102,   76,   10,
 /*   450 */   223,  255,  238,  108,  110,  116,  262,  263,  269,  119,
 /*   460 */   122,  268,  266,  270,   29,  141,  137,  146,  172,  181,
 /*   470 */   144,  140,  145,  149,  197,  154,  221,  157,  167,  150,
 /*   480 */   221,  303,  153,  173,  158,  159,  304,  200,  193,  163,
 /*   490 */   164,  169,  168,  174,  175,  216,  198,  220,  210,  215,
 /*   500 */   314,  345,  313,  211,  228,  231,  237,  323,  322,  226,
 /*   510 */   240,  240,  240,  240,  240,  222,
};
static YYCODETYPE yy_lookahead[] = {
 /*     0 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    10 */    11,   12,   13,   14,   15,   16,   17,   62,   63,   64,
 /*    20 */    21,   66,   23,   66,    1,    2,    3,    4,    5,    6,
 /*    30 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*    40 */    17,    1,    2,    3,    4,    5,    6,    7,    8,    9,
 /*    50 */    10,   11,   12,   13,   14,   15,   16,   17,   11,   36,
 /*    60 */     0,   14,   71,   63,   17,   65,   66,   76,   21,    7,
 /*    70 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*    80 */     0,   11,   35,   36,   14,   94,   95,   17,   71,   43,
 /*    90 */    44,   21,   45,   76,   19,   20,   49,   50,   51,   52,
 /*   100 */    53,   41,   71,   11,   76,   35,   14,   76,   48,   17,
 /*   110 */    93,   94,   95,   21,   76,   45,   88,   89,   90,   49,
 /*   120 */    50,   51,   52,   53,   93,   94,   95,   35,   14,   91,
 /*   130 */    92,   17,   34,   35,   69,   21,    0,   45,   73,   74,
 /*   140 */    75,   49,   50,   51,   52,   53,   17,   63,   64,   35,
 /*   150 */    66,    0,   55,   56,   57,   58,   59,   60,   61,   45,
 /*   160 */    15,   16,   17,   49,   50,   51,   52,   53,    9,   10,
 /*   170 */    11,   12,   13,   14,   15,   16,   17,    0,   49,   82,
 /*   180 */    63,   76,   65,   66,   87,   10,   11,   12,   13,   14,
 /*   190 */    15,   16,   17,   20,   89,   90,    0,   24,   68,   26,
 /*   200 */    27,   28,   72,   30,   31,   63,   76,   63,   66,   24,
 /*   210 */    66,   26,   27,   28,   71,   30,   31,   40,   41,   76,
 /*   220 */     0,    0,    0,   46,   76,   48,   13,   14,   15,   16,
 /*   230 */    17,   67,    0,   85,   70,   71,   93,   94,   95,   71,
 /*   240 */    76,   71,   18,    0,   76,   77,   76,   77,   80,    0,
 /*   250 */    80,    0,   71,   73,   74,   75,   32,   76,   94,   70,
 /*   260 */    71,   37,   94,   39,   94,   76,   76,    0,   48,   20,
 /*   270 */     0,   71,   71,   41,   66,   94,   76,   76,   46,   21,
 /*   280 */    48,   80,   92,   94,   41,   45,   86,    0,   71,    9,
 /*   290 */    47,   48,   41,   76,   94,   94,   16,   71,   47,   48,
 /*   300 */    71,   71,   76,   45,   71,   76,   76,   71,   71,   76,
 /*   310 */    71,   94,   76,   76,    0,   76,   71,   71,   48,    0,
 /*   320 */    94,   76,   76,   94,   94,   72,    0,   94,   41,   76,
 /*   330 */    94,   94,   71,   94,    0,   48,   71,   76,   76,   94,
 /*   340 */    94,   76,    0,   71,   71,   71,   84,   85,   76,   76,
 /*   350 */    76,    0,   71,   71,   40,   94,   71,   76,   76,   94,
 /*   360 */    71,   76,   48,   45,   71,   76,   94,   94,   94,   76,
 /*   370 */    42,   22,   71,   71,   40,   94,   94,   76,   76,   94,
 /*   380 */    71,   71,   48,   94,   71,   76,   76,   94,   71,   76,
 /*   390 */    48,    0,   22,   76,   20,   94,   94,   20,   20,   48,
 /*   400 */    21,    0,   22,   94,   94,   35,   21,   94,   23,   11,
 /*   410 */    36,   94,   24,   36,   36,   35,   24,   29,   21,   21,
 /*   420 */    23,   29,   20,   78,   45,   20,   81,   20,    0,   62,
 /*   430 */    72,   62,    0,   72,   76,   20,    0,   76,   36,   48,
 /*   440 */    21,   36,   66,   36,    0,   35,   17,   35,   49,   48,
 /*   450 */    83,    0,   83,   42,   20,   66,    0,    0,    0,   66,
 /*   460 */    66,    0,    0,    0,   21,   25,   21,   25,   29,   21,
 /*   470 */    24,   76,   76,   24,   33,   25,   48,   24,   24,   76,
 /*   480 */    48,    0,   76,   24,   76,   25,    0,   35,   21,   76,
 /*   490 */    25,   25,   76,   76,   25,   21,   76,   83,   34,   81,
 /*   500 */     0,    0,    0,   35,   20,    1,   83,    0,    0,   38,
 /*   510 */    19,   96,   96,   96,   96,   45,
};
#define YY_SHIFT_USE_DFLT (-2)
static short yy_shift_ofst[] = {
 /*     0 */   224,   80,  136,  151,  196,  221,  177,  232,  220,  222,
 /*    10 */   240,  249,  318,  267,  243,   60,  270,  319,  326,  328,
 /*    20 */   258,  415,  258,   -2,   46,   -2,   -2,   -2,   -2,  349,
 /*    30 */   419,   -2,   -2,  342,  436,  444,  114,   40,  114,  114,
 /*    40 */   145,  114,  145,  114,  213,  114,  213,  114,  213,  114,
 /*    50 */   159,  114,  159,  114,   62,  114,   62,  114,   62,  114,
 /*    60 */    62,  114,   62,  114,   62,  114,  175,  280,  114,  429,
 /*    70 */   410,   70,   40,  129,   -2,  399,   -2,  374,   -2,   70,
 /*    80 */    -2,  370,   47,  377,   -2,   -2,   -2,   -2,  114,  429,
 /*    90 */   114,   23,   -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,
 /*   100 */    -2,  412,   70,  378,   -2,  145,  451,  411,  379,  434,
 /*   110 */   379,   -2,   -2,   -2,   -2,  351,  456,  251,  391,  457,
 /*   120 */   287,  401,  458,  461,  462,  463,  114,   40,   92,   75,
 /*   130 */   443,  173,  185,   -2,   -2,  385,  445,   -2,   -2,  443,
 /*   140 */   440,  114,   40,  446,  443,  442,  114,   40,  449,  443,
 /*   150 */    -2,  388,  443,  450,  114,   40,  453,  443,  460,  114,
 /*   160 */    40,  392,  443,  465,  114,   40,  454,  443,  466,  114,
 /*   170 */    40,  439,  459,  443,  469,  114,   40,  443,   -2,  397,
 /*   180 */   448,   -2,   -2,   -2,   -2,   92,   -2,   -2,  380,  398,
 /*   190 */    -2,   -1,  467,   -2,   -2,   -2,  441,  443,   98,  452,
 /*   200 */   114,  402,  481,  114,   -2,   40,   -2,  474,  405,  464,
 /*   210 */   468,  114,  407,  486,  474,   -2,   -2,   -2,  314,  428,
 /*   220 */   500,  470,  501,  502,  443,  471,  443,  484,  443,   -2,
 /*   230 */   504,  114,   -2,   40,   -2,  334,  432,  507,  508,  491,
 /*   240 */   443,   -2,
};
#define YY_REDUCE_USE_DFLT (-46)
static short yy_reduce_ofst[] = {
 /*     0 */    97,  -46,  -46,  -46,  -46,  -46,  -45,   84,  -43,  -46,
 /*    10 */   -46,  -46,  -46,  -46,    0,  142,  208,  -46,  -46,  -46,
 /*    20 */    28,  -46,  105,  -46,  -46,  -46,  -46,  -46,  -46,  -46,
 /*    30 */   -46,  -46,  -46,  376,  -46,  -46,  217,  -46,  226,  229,
 /*    40 */   -46,  230,  -46,  233,  -46,  236,  -46,  237,  -46,  239,
 /*    50 */   -46,  245,  -46,  246,  -46,  261,  -46,  265,  -46,  272,
 /*    60 */   -46,  273,  -46,  274,  -46,  281,  -46,  -46,  282,  -46,
 /*    70 */   -46,   17,  -46,  -46,  -46,  -46,  -46,  -46,  -46,   -9,
 /*    80 */   -46,  -46,   31,  -46,  -46,  -46,  -46,  -46,  285,  -46,
 /*    90 */   289,  -46,  -46,  -46,  -46,  -46,  -46,  -46,  -46,  -46,
 /*   100 */   -46,  -46,  143,  -46,  -46,  -46,  -46,  -46,   38,  -46,
 /*   110 */   190,  -46,  -46,  -46,  -46,  389,  -46,  117,  393,  -46,
 /*   120 */   144,  394,  -46,  -46,  -46,  -46,  181,  -46,  164,  -46,
 /*   130 */   130,   65,  180,  -46,  -46,  -46,  -46,  -46,  -46,  395,
 /*   140 */   -46,  293,  -46,  -46,  396,  -46,  301,  -46,  -46,  403,
 /*   150 */   -46,  -46,  406,  -46,  302,  -46,  -46,  408,  -46,  309,
 /*   160 */   -46,  -46,  413,  -46,  310,  -46,  -46,  416,  -46,  313,
 /*   170 */   -46,  -46,  -46,  417,  -46,  317,  -46,  253,  -46,  -46,
 /*   180 */   -46,  -46,  -46,  -46,  -46,  189,  -46,  -46,  -46,  -46,
 /*   190 */   -46,  -46,  -46,  -46,  -46,  -46,  -46,  420,  -46,  -46,
 /*   200 */   168,  -46,  -46,  201,  -46,  -46,  -46,  345,  -46,  -46,
 /*   210 */   -46,  170,  -46,  -46,  418,  -46,  -46,  -46,  367,  414,
 /*   220 */   -46,  -46,  -46,  -46,  358,  -46,  262,  -46,  148,  -46,
 /*   230 */   -46,  200,  -46,  -46,  -46,  369,  423,  -46,  -46,  -46,
 /*   240 */   361,  -46,
};
static YYACTIONTYPE yy_default[] = {
 /*     0 */   384,  384,  384,  384,  384,  384,  384,  384,  384,  384,
 /*    10 */   384,  384,  384,  384,  384,  384,  384,  384,  384,  384,
 /*    20 */   384,  329,  384,  330,  332,  333,  334,  335,  336,  383,
 /*    30 */   384,  382,  331,  384,  384,  384,  384,  342,  384,  384,
 /*    40 */   346,  384,  348,  384,  349,  384,  350,  384,  351,  384,
 /*    50 */   352,  384,  353,  384,  354,  384,  355,  384,  356,  384,
 /*    60 */   357,  384,  358,  384,  359,  384,  360,  384,  384,  361,
 /*    70 */   384,  384,  370,  384,  371,  384,  372,  384,  362,  384,
 /*    80 */   364,  383,  384,  384,  365,  366,  368,  369,  384,  373,
 /*    90 */   384,  384,  374,  375,  376,  377,  378,  379,  380,  381,
 /*   100 */   367,  384,  384,  384,  363,  347,  384,  384,  384,  337,
 /*   110 */   384,  338,  340,  341,  339,  384,  384,  384,  384,  384,
 /*   120 */   384,  384,  384,  384,  384,  384,  384,  328,  384,  384,
 /*   130 */   384,  271,  272,  282,  284,  285,  384,  286,  287,  384,
 /*   140 */   288,  384,  289,  384,  384,  290,  384,  291,  384,  384,
 /*   150 */   292,  384,  384,  293,  384,  295,  384,  384,  294,  384,
 /*   160 */   296,  384,  384,  297,  384,  299,  384,  384,  298,  384,
 /*   170 */   300,  384,  384,  384,  301,  384,  302,  384,  280,  327,
 /*   180 */   384,  325,  326,  283,  281,  384,  273,  275,  383,  384,
 /*   190 */   276,  279,  384,  277,  278,  274,  384,  384,  384,  384,
 /*   200 */   384,  384,  384,  384,  305,  307,  306,  384,  384,  384,
 /*   210 */   384,  384,  384,  384,  384,  308,  310,  309,  384,  384,
 /*   220 */   384,  384,  384,  384,  384,  384,  384,  315,  384,  316,
 /*   230 */   384,  384,  318,  319,  317,  384,  384,  384,  384,  384,
 /*   240 */   384,  324,
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
  "group_clause",  "having_clause",  "select_limit_clause",  "column_list", 
  "associated_name_list",  "join_list",     "column_item",   "expr",        
  "associated_name",  "join_item",     "join_associated_name",  "join_clause", 
  "qualified_name",  "values_list",   "field_list",    "value_list",  
  "value_item",    "field_item",    "update_clause",  "limit_clause",
  "update_item_list",  "update_item",   "new_value",     "delete_clause",
  "order_list",    "order_item",    "order_qualified_or_int",  "group_list",  
  "group_item",    "argument_list",  "function_call",  "argument_item",
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
 /* 101 */ "select_limit_clause ::= LIMIT INTEGER",
 /* 102 */ "select_limit_clause ::= LIMIT INTEGER COMMA INTEGER",
 /* 103 */ "limit_clause ::= LIMIT INTEGER",
 /* 104 */ "expr ::= MINUS expr",
 /* 105 */ "expr ::= expr MINUS expr",
 /* 106 */ "expr ::= expr PLUS expr",
 /* 107 */ "expr ::= expr TIMES expr",
 /* 108 */ "expr ::= expr DIVIDE expr",
 /* 109 */ "expr ::= expr MOD expr",
 /* 110 */ "expr ::= expr AND expr",
 /* 111 */ "expr ::= expr OR expr",
 /* 112 */ "expr ::= expr EQUALS expr",
 /* 113 */ "expr ::= expr NOTEQUALS expr",
 /* 114 */ "expr ::= expr LESS expr",
 /* 115 */ "expr ::= expr GREATER expr",
 /* 116 */ "expr ::= expr GREATEREQUAL expr",
 /* 117 */ "expr ::= expr LESSEQUAL expr",
 /* 118 */ "expr ::= expr LIKE expr",
 /* 119 */ "expr ::= expr NOT LIKE expr",
 /* 120 */ "expr ::= expr IN BRACKET_OPEN argument_list BRACKET_CLOSE",
 /* 121 */ "expr ::= expr NOT IN BRACKET_OPEN argument_list BRACKET_CLOSE",
 /* 122 */ "expr ::= function_call",
 /* 123 */ "function_call ::= IDENTIFIER BRACKET_OPEN argument_list BRACKET_CLOSE",
 /* 124 */ "function_call ::= IDENTIFIER BRACKET_OPEN BRACKET_CLOSE",
 /* 125 */ "argument_list ::= argument_list COMMA argument_item",
 /* 126 */ "argument_list ::= argument_item",
 /* 127 */ "argument_item ::= TIMES",
 /* 128 */ "argument_item ::= expr",
 /* 129 */ "expr ::= expr IS NULL",
 /* 130 */ "expr ::= expr IS NOT NULL",
 /* 131 */ "expr ::= NOT expr",
 /* 132 */ "expr ::= BRACKET_OPEN expr BRACKET_CLOSE",
 /* 133 */ "expr ::= qualified_name",
 /* 134 */ "expr ::= INTEGER",
 /* 135 */ "expr ::= STRING",
 /* 136 */ "expr ::= DOUBLE",
 /* 137 */ "expr ::= NULL",
 /* 138 */ "expr ::= NPLACEHOLDER",
 /* 139 */ "expr ::= SPLACEHOLDER",
 /* 140 */ "qualified_name ::= IDENTIFIER DOT IDENTIFIER",
 /* 141 */ "qualified_name ::= IDENTIFIER",
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
#line 473 "parser.lemon"
{
	if ((yypminor->yy0)) {
		efree((yypminor->yy0)->token);
		efree((yypminor->yy0));
	}
}
#line 1079 "parser.c"
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
    case 85:
    case 87:
    case 88:
    case 89:
    case 91:
    case 92:
    case 93:
    case 94:
    case 95:
#line 484 "parser.lemon"
{ zval_ptr_dtor(&(yypminor->yy120)); }
#line 1119 "parser.c"
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
  { 84, 3 },
  { 84, 1 },
  { 85, 3 },
  { 86, 1 },
  { 60, 1 },
  { 60, 2 },
  { 60, 2 },
  { 60, 3 },
  { 87, 3 },
  { 72, 3 },
  { 72, 2 },
  { 72, 1 },
  { 62, 2 },
  { 63, 3 },
  { 88, 3 },
  { 88, 1 },
  { 89, 1 },
  { 89, 2 },
  { 89, 2 },
  { 90, 1 },
  { 90, 1 },
  { 64, 3 },
  { 91, 3 },
  { 91, 1 },
  { 92, 1 },
  { 92, 1 },
  { 65, 2 },
  { 66, 2 },
  { 66, 4 },
  { 83, 2 },
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
  { 94, 4 },
  { 94, 3 },
  { 93, 3 },
  { 93, 1 },
  { 95, 1 },
  { 95, 1 },
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
#line 480 "parser.lemon"
{
	status->ret = yymsp[0].minor.yy120;
}
#line 1478 "parser.c"
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
      case 122:
      case 126:
      case 128:
      case 133:
#line 486 "parser.lemon"
{
	yygotominor.yy120 = yymsp[0].minor.yy120;
}
#line 1505 "parser.c"
        break;
      case 5:
#line 504 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_select_statement(yymsp[0].minor.yy120, NULL, NULL, NULL, NULL, NULL);
}
#line 1512 "parser.c"
        break;
      case 6:
#line 508 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_select_statement(yymsp[-1].minor.yy120, yymsp[0].minor.yy120, NULL, NULL, NULL, NULL);
}
#line 1519 "parser.c"
        break;
      case 7:
#line 512 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_select_statement(yymsp[-2].minor.yy120, yymsp[-1].minor.yy120, yymsp[0].minor.yy120, NULL, NULL, NULL);
}
#line 1526 "parser.c"
        break;
      case 8:
#line 516 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_select_statement(yymsp[-2].minor.yy120, yymsp[-1].minor.yy120, NULL, yymsp[0].minor.yy120, NULL, NULL);
}
#line 1533 "parser.c"
        break;
      case 9:
#line 520 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_select_statement(yymsp[-3].minor.yy120, yymsp[-2].minor.yy120, NULL, yymsp[-1].minor.yy120, yymsp[0].minor.yy120, NULL);
}
#line 1540 "parser.c"
        break;
      case 10:
#line 524 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_select_statement(yymsp[-3].minor.yy120, yymsp[-2].minor.yy120, yymsp[0].minor.yy120, yymsp[-1].minor.yy120, NULL, NULL);
}
#line 1547 "parser.c"
        break;
      case 11:
#line 528 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_select_statement(yymsp[-4].minor.yy120, yymsp[-3].minor.yy120, yymsp[-1].minor.yy120, yymsp[-2].minor.yy120, NULL, yymsp[0].minor.yy120);
}
#line 1554 "parser.c"
        break;
      case 12:
#line 532 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_select_statement(yymsp[-4].minor.yy120, yymsp[-3].minor.yy120, yymsp[0].minor.yy120, yymsp[-2].minor.yy120, yymsp[-1].minor.yy120, NULL);
}
#line 1561 "parser.c"
        break;
      case 13:
#line 536 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_select_statement(yymsp[-2].minor.yy120, yymsp[-1].minor.yy120, NULL, NULL, NULL, yymsp[0].minor.yy120);
}
#line 1568 "parser.c"
        break;
      case 14:
#line 540 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_select_statement(yymsp[-3].minor.yy120, yymsp[-2].minor.yy120, yymsp[-1].minor.yy120, NULL, NULL, yymsp[0].minor.yy120);
}
#line 1575 "parser.c"
        break;
      case 15:
#line 544 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_select_statement(yymsp[-3].minor.yy120, yymsp[-2].minor.yy120, NULL, yymsp[-1].minor.yy120, NULL, yymsp[0].minor.yy120);
}
#line 1582 "parser.c"
        break;
      case 16:
#line 548 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_select_statement(yymsp[-4].minor.yy120, yymsp[-3].minor.yy120, NULL, yymsp[-2].minor.yy120, yymsp[-1].minor.yy120, yymsp[0].minor.yy120);
}
#line 1589 "parser.c"
        break;
      case 17:
#line 552 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_select_statement(yymsp[-1].minor.yy120, NULL, yymsp[0].minor.yy120, NULL, NULL, NULL);
}
#line 1596 "parser.c"
        break;
      case 18:
#line 556 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_select_statement(yymsp[-2].minor.yy120, NULL, yymsp[0].minor.yy120, yymsp[-1].minor.yy120, NULL, NULL);
}
#line 1603 "parser.c"
        break;
      case 19:
#line 560 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_select_statement(yymsp[-3].minor.yy120, NULL, yymsp[0].minor.yy120, yymsp[-2].minor.yy120, yymsp[-1].minor.yy120, NULL);
}
#line 1610 "parser.c"
        break;
      case 20:
#line 564 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_select_statement(yymsp[-2].minor.yy120, NULL, yymsp[-1].minor.yy120, NULL, NULL, yymsp[0].minor.yy120);
}
#line 1617 "parser.c"
        break;
      case 21:
#line 568 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_select_statement(yymsp[-3].minor.yy120, NULL, yymsp[-1].minor.yy120, yymsp[-2].minor.yy120, NULL, yymsp[0].minor.yy120);
}
#line 1624 "parser.c"
        break;
      case 22:
#line 572 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_select_statement(yymsp[-5].minor.yy120, yymsp[-4].minor.yy120, yymsp[-1].minor.yy120, yymsp[-3].minor.yy120, yymsp[-2].minor.yy120, yymsp[0].minor.yy120);
}
#line 1631 "parser.c"
        break;
      case 23:
#line 576 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_select_statement(yymsp[-1].minor.yy120, NULL, NULL, yymsp[0].minor.yy120, NULL, NULL);
}
#line 1638 "parser.c"
        break;
      case 24:
#line 580 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_select_statement(yymsp[-2].minor.yy120, NULL, NULL, yymsp[-1].minor.yy120, NULL, yymsp[0].minor.yy120);
}
#line 1645 "parser.c"
        break;
      case 25:
#line 584 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_select_statement(yymsp[-2].minor.yy120, NULL, NULL, yymsp[-1].minor.yy120, yymsp[0].minor.yy120, NULL);
}
#line 1652 "parser.c"
        break;
      case 26:
#line 588 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_select_statement(yymsp[-3].minor.yy120, NULL, NULL, yymsp[-2].minor.yy120, yymsp[-1].minor.yy120, yymsp[0].minor.yy120);
}
#line 1659 "parser.c"
        break;
      case 27:
#line 592 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_select_statement(yymsp[-4].minor.yy120, NULL, yymsp[-1].minor.yy120, yymsp[-3].minor.yy120, yymsp[-2].minor.yy120, yymsp[0].minor.yy120);
}
#line 1666 "parser.c"
        break;
      case 28:
#line 596 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_select_statement(yymsp[-1].minor.yy120, NULL, NULL, NULL, NULL, yymsp[0].minor.yy120);
}
#line 1673 "parser.c"
        break;
      case 29:
#line 602 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_select_clause(yymsp[-2].minor.yy120, yymsp[0].minor.yy120, NULL);
  yy_destructor(18,&yymsp[-3].minor);
  yy_destructor(19,&yymsp[-1].minor);
}
#line 1682 "parser.c"
        break;
      case 30:
#line 606 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_select_clause(yymsp[-3].minor.yy120, yymsp[-1].minor.yy120, yymsp[0].minor.yy120);
  yy_destructor(18,&yymsp[-4].minor);
  yy_destructor(19,&yymsp[-2].minor);
}
#line 1691 "parser.c"
        break;
      case 31:
      case 38:
      case 63:
      case 66:
      case 74:
      case 88:
      case 96:
      case 125:
#line 612 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_zval_list(yymsp[-2].minor.yy120, yymsp[0].minor.yy120);
  yy_destructor(20,&yymsp[-1].minor);
}
#line 1706 "parser.c"
        break;
      case 33:
      case 127:
#line 622 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_column_item(PHQL_T_ALL, NULL, NULL, NULL);
  yy_destructor(11,&yymsp[0].minor);
}
#line 1715 "parser.c"
        break;
      case 34:
#line 626 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_column_item(PHQL_T_DOMAINALL, NULL, yymsp[-2].minor.yy0, NULL);
  yy_destructor(22,&yymsp[-1].minor);
  yy_destructor(11,&yymsp[0].minor);
}
#line 1724 "parser.c"
        break;
      case 35:
#line 630 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-2].minor.yy120, NULL, yymsp[0].minor.yy0);
  yy_destructor(23,&yymsp[-1].minor);
}
#line 1732 "parser.c"
        break;
      case 36:
#line 634 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-1].minor.yy120, NULL, yymsp[0].minor.yy0);
}
#line 1739 "parser.c"
        break;
      case 37:
#line 638 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_column_item(PHQL_T_EXPR, yymsp[0].minor.yy120, NULL, NULL);
}
#line 1746 "parser.c"
        break;
      case 40:
#line 654 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_zval_list(yymsp[-1].minor.yy120, yymsp[0].minor.yy120);
}
#line 1753 "parser.c"
        break;
      case 43:
#line 670 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_join_item(yymsp[0].minor.yy120, NULL);
}
#line 1760 "parser.c"
        break;
      case 44:
#line 674 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_join_item(yymsp[-2].minor.yy120, yymsp[0].minor.yy0);
  yy_destructor(23,&yymsp[-1].minor);
}
#line 1768 "parser.c"
        break;
      case 45:
#line 678 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_join_item(yymsp[-1].minor.yy120, yymsp[0].minor.yy0);
}
#line 1775 "parser.c"
        break;
      case 46:
#line 684 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_join_clause(PHQL_T_INNERJOIN, yymsp[0].minor.yy120, NULL);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1783 "parser.c"
        break;
      case 47:
#line 688 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_join_clause(PHQL_T_INNERJOIN, yymsp[-2].minor.yy120, yymsp[0].minor.yy120);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1792 "parser.c"
        break;
      case 48:
#line 692 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_join_clause(PHQL_T_INNERJOIN, yymsp[0].minor.yy120, NULL);
  yy_destructor(26,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1801 "parser.c"
        break;
      case 49:
#line 696 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_join_clause(PHQL_T_INNERJOIN, yymsp[-2].minor.yy120, yymsp[0].minor.yy120);
  yy_destructor(26,&yymsp[-4].minor);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1811 "parser.c"
        break;
      case 50:
#line 700 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_join_clause(PHQL_T_CROSSJOIN, yymsp[0].minor.yy120, NULL);
  yy_destructor(27,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1820 "parser.c"
        break;
      case 51:
#line 704 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_join_clause(PHQL_T_LEFTJOIN, yymsp[0].minor.yy120, NULL);
  yy_destructor(28,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1829 "parser.c"
        break;
      case 52:
#line 708 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_join_clause(PHQL_T_LEFTJOIN, yymsp[0].minor.yy120, NULL);
  yy_destructor(28,&yymsp[-3].minor);
  yy_destructor(29,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1839 "parser.c"
        break;
      case 53:
#line 712 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_join_clause(PHQL_T_LEFTJOIN, yymsp[-2].minor.yy120, yymsp[0].minor.yy120);
  yy_destructor(28,&yymsp[-4].minor);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1849 "parser.c"
        break;
      case 54:
#line 716 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_join_clause(PHQL_T_LEFTJOIN, yymsp[-2].minor.yy120, yymsp[0].minor.yy120);
  yy_destructor(28,&yymsp[-5].minor);
  yy_destructor(29,&yymsp[-4].minor);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1860 "parser.c"
        break;
      case 55:
#line 720 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_join_clause(PHQL_T_RIGHTJOIN, yymsp[0].minor.yy120, NULL);
  yy_destructor(30,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1869 "parser.c"
        break;
      case 56:
#line 724 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_join_clause(PHQL_T_RIGHTJOIN, yymsp[0].minor.yy120, NULL);
  yy_destructor(30,&yymsp[-3].minor);
  yy_destructor(29,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1879 "parser.c"
        break;
      case 57:
#line 728 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_join_clause(PHQL_T_RIGHTJOIN, yymsp[-2].minor.yy120, yymsp[0].minor.yy120);
  yy_destructor(30,&yymsp[-4].minor);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1889 "parser.c"
        break;
      case 58:
#line 732 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_join_clause(PHQL_T_RIGHTJOIN, yymsp[-2].minor.yy120, yymsp[0].minor.yy120);
  yy_destructor(30,&yymsp[-5].minor);
  yy_destructor(29,&yymsp[-4].minor);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1900 "parser.c"
        break;
      case 59:
#line 736 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_join_clause(PHQL_T_FULLOUTER, yymsp[0].minor.yy120, NULL);
  yy_destructor(31,&yymsp[-3].minor);
  yy_destructor(29,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1910 "parser.c"
        break;
      case 60:
#line 740 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_join_clause(PHQL_T_FULLOUTER, yymsp[-2].minor.yy120, yymsp[0].minor.yy120);
  yy_destructor(31,&yymsp[-5].minor);
  yy_destructor(29,&yymsp[-4].minor);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1921 "parser.c"
        break;
      case 61:
#line 747 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_insert_statement(yymsp[-4].minor.yy120, NULL, yymsp[-1].minor.yy120);
  yy_destructor(32,&yymsp[-6].minor);
  yy_destructor(33,&yymsp[-5].minor);
  yy_destructor(34,&yymsp[-3].minor);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
#line 1933 "parser.c"
        break;
      case 62:
#line 751 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_insert_statement(yymsp[-7].minor.yy120, yymsp[-5].minor.yy120, yymsp[-1].minor.yy120);
  yy_destructor(32,&yymsp[-9].minor);
  yy_destructor(33,&yymsp[-8].minor);
  yy_destructor(35,&yymsp[-6].minor);
  yy_destructor(36,&yymsp[-4].minor);
  yy_destructor(34,&yymsp[-3].minor);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
#line 1947 "parser.c"
        break;
      case 68:
      case 141:
#line 781 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_qualified_name(yymsp[0].minor.yy0, NULL);
}
#line 1955 "parser.c"
        break;
      case 69:
#line 789 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_update_statement(yymsp[0].minor.yy120, NULL, NULL);
}
#line 1962 "parser.c"
        break;
      case 70:
#line 793 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_update_statement(yymsp[-1].minor.yy120, yymsp[0].minor.yy120, NULL);
}
#line 1969 "parser.c"
        break;
      case 71:
#line 797 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_update_statement(yymsp[-1].minor.yy120, NULL, yymsp[0].minor.yy120);
}
#line 1976 "parser.c"
        break;
      case 72:
#line 801 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_update_statement(yymsp[-2].minor.yy120, yymsp[-1].minor.yy120, yymsp[0].minor.yy120);
}
#line 1983 "parser.c"
        break;
      case 73:
#line 807 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_update_clause(yymsp[-2].minor.yy120, yymsp[0].minor.yy120);
  yy_destructor(37,&yymsp[-3].minor);
  yy_destructor(38,&yymsp[-1].minor);
}
#line 1992 "parser.c"
        break;
      case 76:
#line 823 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_update_item(yymsp[-2].minor.yy120, yymsp[0].minor.yy120);
  yy_destructor(1,&yymsp[-1].minor);
}
#line 2000 "parser.c"
        break;
      case 78:
#line 835 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_delete_statement(yymsp[0].minor.yy120, NULL, NULL);
}
#line 2007 "parser.c"
        break;
      case 79:
#line 839 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_delete_statement(yymsp[-1].minor.yy120, yymsp[0].minor.yy120, NULL);
}
#line 2014 "parser.c"
        break;
      case 80:
#line 843 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_delete_statement(yymsp[-1].minor.yy120, NULL, yymsp[0].minor.yy120);
}
#line 2021 "parser.c"
        break;
      case 81:
#line 847 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_delete_statement(yymsp[-2].minor.yy120, yymsp[-1].minor.yy120, yymsp[0].minor.yy120);
}
#line 2028 "parser.c"
        break;
      case 82:
#line 853 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_delete_clause(yymsp[0].minor.yy120);
  yy_destructor(39,&yymsp[-2].minor);
  yy_destructor(19,&yymsp[-1].minor);
}
#line 2037 "parser.c"
        break;
      case 83:
#line 859 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_assoc_name(yymsp[-2].minor.yy120, yymsp[0].minor.yy0);
  yy_destructor(23,&yymsp[-1].minor);
}
#line 2045 "parser.c"
        break;
      case 84:
#line 863 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_assoc_name(yymsp[-1].minor.yy120, yymsp[0].minor.yy0);
}
#line 2052 "parser.c"
        break;
      case 85:
#line 867 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_assoc_name(yymsp[0].minor.yy120, NULL);
}
#line 2059 "parser.c"
        break;
      case 86:
#line 873 "parser.lemon"
{
	yygotominor.yy120 = yymsp[0].minor.yy120;
  yy_destructor(40,&yymsp[-1].minor);
}
#line 2067 "parser.c"
        break;
      case 87:
#line 879 "parser.lemon"
{
	yygotominor.yy120 = yymsp[0].minor.yy120;
  yy_destructor(41,&yymsp[-2].minor);
  yy_destructor(42,&yymsp[-1].minor);
}
#line 2076 "parser.c"
        break;
      case 90:
#line 895 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_order_item(yymsp[0].minor.yy120, 0);
}
#line 2083 "parser.c"
        break;
      case 91:
#line 899 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_order_item(yymsp[-1].minor.yy120, PHQL_T_ASC);
  yy_destructor(43,&yymsp[0].minor);
}
#line 2091 "parser.c"
        break;
      case 92:
#line 903 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_order_item(yymsp[-1].minor.yy120, PHQL_T_DESC);
  yy_destructor(44,&yymsp[0].minor);
}
#line 2099 "parser.c"
        break;
      case 94:
      case 99:
      case 134:
#line 911 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_literal_zval(PHQL_T_INTEGER, yymsp[0].minor.yy0);
}
#line 2108 "parser.c"
        break;
      case 95:
#line 917 "parser.lemon"
{
	yygotominor.yy120 = yymsp[0].minor.yy120;
  yy_destructor(46,&yymsp[-2].minor);
  yy_destructor(42,&yymsp[-1].minor);
}
#line 2117 "parser.c"
        break;
      case 100:
#line 943 "parser.lemon"
{
	yygotominor.yy120 = yymsp[0].minor.yy120;
  yy_destructor(47,&yymsp[-1].minor);
}
#line 2125 "parser.c"
        break;
      case 101:
#line 949 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_select_limit_clause(yymsp[0].minor.yy0, NULL);
  yy_destructor(48,&yymsp[-1].minor);
}
#line 2133 "parser.c"
        break;
      case 102:
#line 953 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_select_limit_clause(yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(48,&yymsp[-3].minor);
  yy_destructor(20,&yymsp[-1].minor);
}
#line 2142 "parser.c"
        break;
      case 103:
#line 959 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_literal_zval(PHQL_T_INTEGER, yymsp[0].minor.yy0);
  yy_destructor(48,&yymsp[-1].minor);
}
#line 2150 "parser.c"
        break;
      case 104:
#line 965 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_expr(PHQL_T_MINUS, NULL, yymsp[0].minor.yy120);
  yy_destructor(14,&yymsp[-1].minor);
}
#line 2158 "parser.c"
        break;
      case 105:
#line 969 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_expr(PHQL_T_SUB, yymsp[-2].minor.yy120, yymsp[0].minor.yy120);
  yy_destructor(14,&yymsp[-1].minor);
}
#line 2166 "parser.c"
        break;
      case 106:
#line 973 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_expr(PHQL_T_ADD, yymsp[-2].minor.yy120, yymsp[0].minor.yy120);
  yy_destructor(13,&yymsp[-1].minor);
}
#line 2174 "parser.c"
        break;
      case 107:
#line 977 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_expr(PHQL_T_MUL, yymsp[-2].minor.yy120, yymsp[0].minor.yy120);
  yy_destructor(11,&yymsp[-1].minor);
}
#line 2182 "parser.c"
        break;
      case 108:
#line 981 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_expr(PHQL_T_DIV, yymsp[-2].minor.yy120, yymsp[0].minor.yy120);
  yy_destructor(10,&yymsp[-1].minor);
}
#line 2190 "parser.c"
        break;
      case 109:
#line 985 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_expr(PHQL_T_MOD, yymsp[-2].minor.yy120, yymsp[0].minor.yy120);
  yy_destructor(12,&yymsp[-1].minor);
}
#line 2198 "parser.c"
        break;
      case 110:
#line 989 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_expr(PHQL_T_AND, yymsp[-2].minor.yy120, yymsp[0].minor.yy120);
  yy_destructor(7,&yymsp[-1].minor);
}
#line 2206 "parser.c"
        break;
      case 111:
#line 993 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_expr(PHQL_T_OR, yymsp[-2].minor.yy120, yymsp[0].minor.yy120);
  yy_destructor(8,&yymsp[-1].minor);
}
#line 2214 "parser.c"
        break;
      case 112:
#line 997 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_expr(PHQL_T_EQUALS, yymsp[-2].minor.yy120, yymsp[0].minor.yy120);
  yy_destructor(1,&yymsp[-1].minor);
}
#line 2222 "parser.c"
        break;
      case 113:
#line 1001 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_expr(PHQL_T_NOTEQUALS, yymsp[-2].minor.yy120, yymsp[0].minor.yy120);
  yy_destructor(2,&yymsp[-1].minor);
}
#line 2230 "parser.c"
        break;
      case 114:
#line 1005 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_expr(PHQL_T_LESS, yymsp[-2].minor.yy120, yymsp[0].minor.yy120);
  yy_destructor(3,&yymsp[-1].minor);
}
#line 2238 "parser.c"
        break;
      case 115:
#line 1009 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_expr(PHQL_T_GREATER, yymsp[-2].minor.yy120, yymsp[0].minor.yy120);
  yy_destructor(4,&yymsp[-1].minor);
}
#line 2246 "parser.c"
        break;
      case 116:
#line 1013 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_expr(PHQL_T_GREATEREQUAL, yymsp[-2].minor.yy120, yymsp[0].minor.yy120);
  yy_destructor(5,&yymsp[-1].minor);
}
#line 2254 "parser.c"
        break;
      case 117:
#line 1017 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_expr(PHQL_T_LESSEQUAL, yymsp[-2].minor.yy120, yymsp[0].minor.yy120);
  yy_destructor(6,&yymsp[-1].minor);
}
#line 2262 "parser.c"
        break;
      case 118:
#line 1021 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_expr(PHQL_T_LIKE, yymsp[-2].minor.yy120, yymsp[0].minor.yy120);
  yy_destructor(9,&yymsp[-1].minor);
}
#line 2270 "parser.c"
        break;
      case 119:
#line 1025 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_expr(PHQL_T_NLIKE, yymsp[-3].minor.yy120, yymsp[0].minor.yy120);
  yy_destructor(17,&yymsp[-2].minor);
  yy_destructor(9,&yymsp[-1].minor);
}
#line 2279 "parser.c"
        break;
      case 120:
#line 1029 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_expr(PHQL_T_IN, yymsp[-4].minor.yy120, yymsp[-1].minor.yy120);
  yy_destructor(16,&yymsp[-3].minor);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
#line 2289 "parser.c"
        break;
      case 121:
#line 1033 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_expr(PHQL_T_NOTIN, yymsp[-5].minor.yy120, yymsp[-1].minor.yy120);
  yy_destructor(17,&yymsp[-4].minor);
  yy_destructor(16,&yymsp[-3].minor);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
#line 2300 "parser.c"
        break;
      case 123:
#line 1043 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_func_call(yymsp[-3].minor.yy0, yymsp[-1].minor.yy120);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
#line 2309 "parser.c"
        break;
      case 124:
#line 1047 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_func_call(yymsp[-2].minor.yy0, NULL);
  yy_destructor(35,&yymsp[-1].minor);
  yy_destructor(36,&yymsp[0].minor);
}
#line 2318 "parser.c"
        break;
      case 129:
#line 1071 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_expr(PHQL_T_ISNULL, yymsp[-2].minor.yy120, NULL);
  yy_destructor(15,&yymsp[-1].minor);
  yy_destructor(49,&yymsp[0].minor);
}
#line 2327 "parser.c"
        break;
      case 130:
#line 1075 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_expr(PHQL_T_ISNOTNULL, yymsp[-3].minor.yy120, NULL);
  yy_destructor(15,&yymsp[-2].minor);
  yy_destructor(17,&yymsp[-1].minor);
  yy_destructor(49,&yymsp[0].minor);
}
#line 2337 "parser.c"
        break;
      case 131:
#line 1079 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_expr(PHQL_T_NOT, NULL, yymsp[0].minor.yy120);
  yy_destructor(17,&yymsp[-1].minor);
}
#line 2345 "parser.c"
        break;
      case 132:
#line 1083 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_expr(PHQL_T_ENCLOSED, yymsp[-1].minor.yy120, NULL);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
#line 2354 "parser.c"
        break;
      case 135:
#line 1095 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_literal_zval(PHQL_T_STRING, yymsp[0].minor.yy0);
}
#line 2361 "parser.c"
        break;
      case 136:
#line 1099 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_literal_zval(PHQL_T_DOUBLE, yymsp[0].minor.yy0);
}
#line 2368 "parser.c"
        break;
      case 137:
#line 1103 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_literal_zval(PHQL_T_NULL, NULL);
  yy_destructor(49,&yymsp[0].minor);
}
#line 2376 "parser.c"
        break;
      case 138:
#line 1107 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_placeholder_zval(PHQL_T_NPLACEHOLDER, yymsp[0].minor.yy0);
}
#line 2383 "parser.c"
        break;
      case 139:
#line 1111 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_placeholder_zval(PHQL_T_SPLACEHOLDER, yymsp[0].minor.yy0);
}
#line 2390 "parser.c"
        break;
      case 140:
#line 1117 "parser.lemon"
{
	yygotominor.yy120 = phql_ret_qualified_name(yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(22,&yymsp[-1].minor);
}
#line 2398 "parser.c"
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
#line 423 "parser.lemon"

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

#line 2490 "parser.c"
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