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


#line 362 "parser.c"
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
#define YYNOCODE 93
#define YYACTIONTYPE unsigned short int
#define phql_TOKENTYPE phql_parser_token*
typedef union {
  phql_TOKENTYPE yy0;
  zval* yy112;
  int yy185;
} YYMINORTYPE;
#define YYSTACKDEPTH 100
#define phql_ARG_SDECL phql_parser_status *status;
#define phql_ARG_PDECL ,phql_parser_status *status
#define phql_ARG_FETCH phql_parser_status *status = yypParser->status
#define phql_ARG_STORE yypParser->status = status
#define YYNSTATE 235
#define YYNRULE 137
#define YYERRORSYMBOL 52
#define YYERRSYMDT yy185
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
 /*     0 */    62,   65,   68,   36,   33,   40,   38,   42,   60,   44,
 /*    10 */    46,   48,   50,   52,   54,   56,   58,    7,  110,  112,
 /*    20 */   189,  120,  187,    9,   62,   65,   68,   36,   33,   40,
 /*    30 */    38,   42,   60,   44,   46,   48,   50,   52,   54,   56,
 /*    40 */    58,   62,   65,   68,   36,   33,   40,   38,   42,   60,
 /*    50 */    44,   46,   48,   50,   52,   54,   56,   58,  242,   87,
 /*    60 */    40,   38,   42,   60,   44,   46,   48,   50,   52,   54,
 /*    70 */    56,   58,   83,  235,    8,   12,   34,  101,   82,  125,
 /*    80 */   180,  373,    1,    2,    3,    4,    5,    6,   28,  107,
 /*    90 */    13,   30,   76,   60,   44,   46,   48,   50,   52,   54,
 /*   100 */    56,   58,  104,  109,   10,   67,   85,   80,  213,   83,
 /*   110 */    88,  236,  228,   34,   89,   82,  223,  247,   92,   90,
 /*   120 */    91,   93,   94,  220,  227,   72,   75,   81,  245,   76,
 /*   130 */    44,   46,   48,   50,   52,   54,   56,   58,  113,  237,
 /*   140 */   115,  119,  172,   85,  240,  241,  134,   70,  138,  143,
 /*   150 */   146,   89,  156,  166,   24,   92,   90,   91,   93,   94,
 /*   160 */    83,  181,  186,   10,   34,  304,  182,   88,   48,   50,
 /*   170 */    52,   54,   56,   58,   10,  134,   23,  138,  143,  146,
 /*   180 */   183,  156,  166,   75,  121,   17,   17,  243,  102,  102,
 /*   190 */    10,   10,   67,   69,   85,   14,   83,   88,   16,   67,
 /*   200 */    34,  133,   89,  131,   88,  121,   92,   90,   91,   93,
 /*   210 */    94,   10,   78,   75,   81,  123,   76,  258,  200,   98,
 /*   220 */    75,   81,  124,   88,  196,  190,  186,  201,   17,  191,
 /*   230 */    85,   88,   31,   10,  217,  107,  232,  244,   89,   75,
 /*   240 */    22,  238,   92,   90,   91,   93,   94,   75,  200,  106,
 /*   250 */    67,   24,   21,   88,  207,   88,   22,  201,   17,  239,
 /*   260 */   127,   25,   31,   10,  178,  129,  130,   19,   27,   75,
 /*   270 */   200,   75,   95,  108,   77,   88,  226,   32,   17,  199,
 /*   280 */   100,   88,   88,   10,   35,   88,   15,   37,   39,   88,
 /*   290 */   225,   75,   88,   88,   41,   43,  249,   75,   75,   88,
 /*   300 */    88,   75,   45,   11,   96,   75,   74,   88,   75,   75,
 /*   310 */   313,   63,   47,   49,   51,   75,   75,   88,   88,   88,
 /*   320 */    53,  333,   73,   75,   55,   88,   57,   59,  260,   88,
 /*   330 */   252,   88,   88,   75,   75,   75,  173,   61,   64,   84,
 /*   340 */   174,   75,   88,   88,   88,   75,   86,   75,   75,  122,
 /*   350 */   121,   88,   20,  184,   88,  253,   10,  126,   75,   75,
 /*   360 */    75,  179,  257,  137,  254,  174,   77,   75,   88,   17,
 /*   370 */    75,  128,  129,  130,   10,  142,   10,  150,  155,   74,
 /*   380 */    88,   74,   88,   88,   75,  160,  165,  171,  185,  147,
 /*   390 */    88,   88,   88,  305,  151,   79,   75,   99,   75,   75,
 /*   400 */   116,   10,   26,  118,  157,  198,   75,   75,   75,  161,
 /*   410 */    10,  177,  203,  175,  314,  212,  194,  202,  209,  198,
 /*   420 */   214,  197,  218,  223,  216,  251,  174,   25,  229,   18,
 /*   430 */    26,  222,  231,   29,  204,  208,  234,  246,  250,   10,
 /*   440 */   174,   66,   71,   97,  248,  103,  105,  111,  255,  256,
 /*   450 */   114,  262,  117,  261,  259,  263,   24,  132,  135,  136,
 /*   460 */    10,  167,  192,  139,  144,  140,  141,  149,  145,  152,
 /*   470 */   148,  153,  154,  296,  158,  159,  162,  205,  163,  297,
 /*   480 */   176,  164,  168,  188,  169,  170,  193,  211,  215,  307,
 /*   490 */   210,  306,  195,  224,  221,  230,  206,  316,  315,  233,
 /*   500 */   231,  219,
};
static YYCODETYPE yy_lookahead[] = {
 /*     0 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    10 */    11,   12,   13,   14,   15,   16,   17,   60,   61,   62,
 /*    20 */    21,   64,   23,   64,    1,    2,    3,    4,    5,    6,
 /*    30 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*    40 */    17,    1,    2,    3,    4,    5,    6,    7,    8,    9,
 /*    50 */    10,   11,   12,   13,   14,   15,   16,   17,    0,   36,
 /*    60 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*    70 */    16,   17,    1,    0,   61,   62,    5,   64,    7,   19,
 /*    80 */    20,   53,   54,   55,   56,   57,   58,   59,   61,   74,
 /*    90 */    63,   64,   21,    9,   10,   11,   12,   13,   14,   15,
 /*   100 */    16,   17,   87,   88,   46,   69,   35,   36,   80,    1,
 /*   110 */    74,    0,   84,    5,   43,    7,   74,    0,   47,   48,
 /*   120 */    49,   50,   51,   81,   82,   89,   90,   91,    0,   21,
 /*   130 */    10,   11,   12,   13,   14,   15,   16,   17,   61,    0,
 /*   140 */    63,   64,   20,   35,    0,    0,   24,    1,   26,   27,
 /*   150 */    28,   43,   30,   31,   21,   47,   48,   49,   50,   51,
 /*   160 */     1,   68,   69,   46,    5,    0,    7,   74,   12,   13,
 /*   170 */    14,   15,   16,   17,   46,   24,   43,   26,   27,   28,
 /*   180 */    21,   30,   31,   90,   40,   41,   41,    0,   44,   44,
 /*   190 */    46,   46,   69,   47,   35,   61,    1,   74,   64,   69,
 /*   200 */     5,   21,   43,   23,   74,   40,   47,   48,   49,   50,
 /*   210 */    51,   46,   89,   90,   91,   18,   21,    0,   69,   89,
 /*   220 */    90,   91,   65,   74,   75,   68,   69,   78,   41,   32,
 /*   230 */    35,   74,   45,   46,   37,   74,   39,    0,   43,   90,
 /*   240 */    74,    0,   47,   48,   49,   50,   51,   90,   69,   88,
 /*   250 */    69,   21,   86,   74,   75,   74,   74,   78,   41,    0,
 /*   260 */    67,   22,   45,   46,   71,   72,   73,   85,   86,   90,
 /*   270 */    69,   90,   91,   43,   35,   74,   69,   69,   41,   78,
 /*   280 */    69,   74,   74,   46,   69,   74,   64,   69,   69,   74,
 /*   290 */    83,   90,   74,   74,   69,   69,    0,   90,   90,   74,
 /*   300 */    74,   90,   69,   43,    2,   90,   20,   74,   90,   90,
 /*   310 */     0,    9,   69,   69,   69,   90,   90,   74,   74,   74,
 /*   320 */    69,    0,   36,   90,   69,   74,   69,   69,    0,   74,
 /*   330 */     0,   74,   74,   90,   90,   90,   70,   69,   69,   69,
 /*   340 */    74,   90,   74,   74,   74,   90,   69,   90,   90,   69,
 /*   350 */    40,   74,   20,   22,   74,    0,   46,   66,   90,   90,
 /*   360 */    90,   70,    0,   69,    0,   74,   35,   90,   74,   41,
 /*   370 */    90,   71,   72,   73,   46,   69,   46,   69,   69,   20,
 /*   380 */    74,   20,   74,   74,   90,   69,   69,   69,    7,   24,
 /*   390 */    74,   74,   74,    0,   29,   36,   90,   36,   90,   90,
 /*   400 */    61,   46,   21,   64,   24,   20,   90,   90,   90,   29,
 /*   410 */    46,   21,   76,   23,    0,   79,   34,   35,   20,   20,
 /*   420 */    60,   36,   70,   74,   64,    0,   74,   22,   60,   42,
 /*   430 */    21,   82,   64,   64,   36,   36,   70,    0,    0,   46,
 /*   440 */    74,   35,   47,   35,    0,   42,   20,   64,    0,    0,
 /*   450 */    64,    0,   64,    0,    0,    0,   21,   21,   74,   25,
 /*   460 */    46,   29,   33,   24,   24,   74,   25,   25,   74,   24,
 /*   470 */    74,   74,   25,    0,   74,   25,   24,   34,   74,    0,
 /*   480 */    21,   25,   24,   21,   74,   25,   74,   21,   64,    0,
 /*   490 */    79,    0,   35,   12,   20,   64,   35,    0,    0,   19,
 /*   500 */    92,   38,
};
#define YY_SHIFT_USE_DFLT (-2)
static short yy_shift_ofst[] = {
 /*     0 */   197,   73,  111,  139,  241,  259,  144,  145,   58,  296,
 /*    10 */   260,  321,  187,  237,  117,  362,  425,  387,  133,  332,
 /*    20 */   133,   -2,   -2,   -2,  405,  409,   -2,   -2,  128,  437,
 /*    30 */   438,  195,   40,  195,  195,   54,  195,   54,  195,   84,
 /*    40 */   195,   84,  195,   84,  195,  156,  195,  156,  195,   -2,
 /*    50 */   195,   -2,  195,   -2,  195,   -2,  195,   -2,  195,   -2,
 /*    60 */   195,  120,  302,  195,   40,  406,  108,   40,  146,   -2,
 /*    70 */   395,   -2,  286,   -2,  108,   -2,  239,   71,  359,   -2,
 /*    80 */    -2,   -2,   -2,  195,   40,  195,   23,   -2,   -2,   -2,
 /*    90 */    -2,   -2,   -2,   -2,   -2,   -2,  408,  108,  361,   -2,
 /*   100 */    54,  444,  403,  230,  426,  230,   -2,   -2,   -2,   -2,
 /*   110 */   330,  448,  217,  355,  449,  328,  364,  451,  453,  454,
 /*   120 */   455,  195,   40,  159,   60,  435,  122,  151,   -2,   -2,
 /*   130 */   180,  436,   -2,   -2,  435,  434,  195,   40,  439,  435,
 /*   140 */   441,  195,   40,  440,  435,   -2,  365,  435,  442,  195,
 /*   150 */    40,  445,  435,  447,  195,   40,  380,  435,  450,  195,
 /*   160 */    40,  452,  435,  456,  195,   40,  432,  458,  435,  460,
 /*   170 */   195,   40,  435,   -2,  390,  459,   -2,   -2,   -2,   -2,
 /*   180 */   159,   -2,   -2,  331,  381,   -2,   -1,  462,   -2,   -2,
 /*   190 */    -2,  429,  435,  382,  457,  195,  385,  473,  195,   -2,
 /*   200 */    40,   -2,  466,  398,  443,  461,  195,  399,  479,  466,
 /*   210 */    -2,   -2,   -2,  165,  393,  489,  491,  435,  463,  435,
 /*   220 */   474,  435,   -2,  481,  195,   -2,   40,   -2,  310,  414,
 /*   230 */   497,  498,  480,  435,   -2,
};
#define YY_REDUCE_USE_DFLT (-44)
static short yy_reduce_ofst[] = {
 /*     0 */    28,  -44,  -44,  -44,  -44,  -44,  -43,   13,  -41,  -44,
 /*    10 */   -44,  -44,   27,  134,  222,  -44,  -44,  -44,  182,  -44,
 /*    20 */   166,  -44,  -44,  -44,  -44,  -44,  -44,  -44,  369,  -44,
 /*    30 */   -44,  208,  -44,  211,  215,  -44,  218,  -44,  219,  -44,
 /*    40 */   225,  -44,  226,  -44,  233,  -44,  243,  -44,  244,  -44,
 /*    50 */   245,  -44,  251,  -44,  255,  -44,  257,  -44,  258,  -44,
 /*    60 */   268,  -44,  -44,  269,  -44,  -44,   36,  -44,  -44,  -44,
 /*    70 */   -44,  -44,  -44,  -44,  181,  -44,  -44,  123,  -44,  -44,
 /*    80 */   -44,  -44,  -44,  270,  -44,  277,  -44,  -44,  -44,  -44,
 /*    90 */   -44,  -44,  -44,  -44,  -44,  -44,  -44,  130,  -44,  -44,
 /*   100 */   -44,  -44,  -44,   15,  -44,  161,  -44,  -44,  -44,  -44,
 /*   110 */   383,  -44,   77,  386,  -44,  339,  388,  -44,  -44,  -44,
 /*   120 */   -44,  280,  -44,  157,  -44,  291,  193,  300,  -44,  -44,
 /*   130 */   -44,  -44,  -44,  -44,  384,  -44,  294,  -44,  -44,  391,
 /*   140 */   -44,  306,  -44,  -44,  394,  -44,  -44,  396,  -44,  308,
 /*   150 */   -44,  -44,  397,  -44,  309,  -44,  -44,  400,  -44,  316,
 /*   160 */   -44,  -44,  404,  -44,  317,  -44,  -44,  -44,  410,  -44,
 /*   170 */   318,  -44,  266,  -44,  -44,  -44,  -44,  -44,  -44,  -44,
 /*   180 */    93,  -44,  -44,  -44,  -44,  -44,  -44,  -44,  -44,  -44,
 /*   190 */   -44,  -44,  412,  -44,  -44,  149,  -44,  -44,  201,  -44,
 /*   200 */   -44,  -44,  336,  -44,  -44,  -44,  179,  -44,  -44,  411,
 /*   210 */   -44,  -44,  -44,  360,  424,  -44,  -44,  352,  -44,   42,
 /*   220 */   -44,  349,  -44,  -44,  207,  -44,  -44,  -44,  368,  431,
 /*   230 */   -44,  -44,  -44,  366,  -44,
};
static YYACTIONTYPE yy_default[] = {
 /*     0 */   372,  372,  372,  372,  372,  372,  372,  372,  372,  372,
 /*    10 */   372,  372,  372,  372,  372,  372,  372,  372,  372,  322,
 /*    20 */   372,  323,  325,  326,  371,  372,  370,  324,  372,  372,
 /*    30 */   372,  372,  332,  372,  372,  334,  372,  336,  372,  337,
 /*    40 */   372,  338,  372,  339,  372,  340,  372,  341,  372,  342,
 /*    50 */   372,  343,  372,  344,  372,  345,  372,  346,  372,  347,
 /*    60 */   372,  348,  372,  372,  349,  372,  372,  358,  372,  359,
 /*    70 */   372,  360,  372,  350,  372,  352,  371,  372,  372,  353,
 /*    80 */   354,  356,  357,  372,  361,  372,  372,  362,  363,  364,
 /*    90 */   365,  366,  367,  368,  369,  355,  372,  372,  372,  351,
 /*   100 */   335,  372,  372,  372,  327,  372,  328,  330,  331,  329,
 /*   110 */   372,  372,  372,  372,  372,  372,  372,  372,  372,  372,
 /*   120 */   372,  372,  321,  372,  372,  372,  264,  265,  275,  277,
 /*   130 */   278,  372,  279,  280,  372,  281,  372,  282,  372,  372,
 /*   140 */   283,  372,  284,  372,  372,  285,  372,  372,  286,  372,
 /*   150 */   288,  372,  372,  287,  372,  289,  372,  372,  290,  372,
 /*   160 */   292,  372,  372,  291,  372,  293,  372,  372,  372,  294,
 /*   170 */   372,  295,  372,  273,  320,  372,  318,  319,  276,  274,
 /*   180 */   372,  266,  268,  371,  372,  269,  272,  372,  270,  271,
 /*   190 */   267,  372,  372,  372,  372,  372,  372,  372,  372,  298,
 /*   200 */   300,  299,  372,  372,  372,  372,  372,  372,  372,  372,
 /*   210 */   301,  303,  302,  372,  372,  372,  372,  372,  372,  372,
 /*   220 */   308,  372,  309,  372,  372,  311,  312,  310,  372,  372,
 /*   230 */   372,  372,  372,  372,  317,
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
  "$",             "NOT",           "IN",            "IS",          
  "PLUS",          "MINUS",         "DIVIDE",        "TIMES",       
  "MOD",           "LIKE",          "AND",           "OR",          
  "EQUALS",        "NOTEQUALS",     "LESS",          "GREATER",     
  "GREATEREQUAL",  "LESSEQUAL",     "SELECT",        "FROM",        
  "COMMA",         "IDENTIFIER",    "DOT",           "AS",          
  "JOIN",          "ON",            "INNER",         "CROSS",       
  "LEFT",          "OUTER",         "RIGHT",         "FULL",        
  "INSERT",        "INTO",          "VALUES",        "BRACKET_OPEN",
  "BRACKET_CLOSE",  "UPDATE",        "SET",           "DELETE",      
  "WHERE",         "ORDER",         "BY",            "INTEGER",     
  "GROUP",         "HAVING",        "LIMIT",         "NULL",        
  "STRING",        "DOUBLE",        "NPLACEHOLDER",  "SPLACEHOLDER",
  "error",         "program",       "query_language",  "select_statement",
  "insert_statement",  "update_statement",  "delete_statement",  "select_clause",
  "where_clause",  "order_clause",  "group_clause",  "having_clause",
  "limit_clause",  "column_list",   "associated_name_list",  "join_list",   
  "column_item",   "expr",          "associated_name",  "join_item",   
  "join_associated_name",  "join_clause",   "qualified_name",  "values_list", 
  "field_list",    "value_list",    "value_item",    "field_item",  
  "update_clause",  "update_item_list",  "update_item",   "new_value",   
  "delete_clause",  "order_list",    "order_item",    "group_list",  
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
 /*  90 */ "order_item ::= qualified_name",
 /*  91 */ "order_item ::= INTEGER",
 /*  92 */ "group_clause ::= GROUP BY group_list",
 /*  93 */ "group_list ::= group_list COMMA group_item",
 /*  94 */ "group_list ::= group_item",
 /*  95 */ "group_item ::= qualified_name",
 /*  96 */ "group_item ::= INTEGER",
 /*  97 */ "having_clause ::= HAVING expr",
 /*  98 */ "limit_clause ::= LIMIT INTEGER",
 /*  99 */ "expr ::= MINUS expr",
 /* 100 */ "expr ::= expr MINUS expr",
 /* 101 */ "expr ::= expr PLUS expr",
 /* 102 */ "expr ::= expr TIMES expr",
 /* 103 */ "expr ::= expr DIVIDE expr",
 /* 104 */ "expr ::= expr MOD expr",
 /* 105 */ "expr ::= expr AND expr",
 /* 106 */ "expr ::= expr OR expr",
 /* 107 */ "expr ::= expr EQUALS expr",
 /* 108 */ "expr ::= expr NOTEQUALS expr",
 /* 109 */ "expr ::= expr LESS expr",
 /* 110 */ "expr ::= expr GREATER expr",
 /* 111 */ "expr ::= expr GREATEREQUAL expr",
 /* 112 */ "expr ::= expr LESSEQUAL expr",
 /* 113 */ "expr ::= expr LIKE expr",
 /* 114 */ "expr ::= expr NOT LIKE expr",
 /* 115 */ "expr ::= expr IN BRACKET_OPEN argument_list BRACKET_CLOSE",
 /* 116 */ "expr ::= expr NOT IN BRACKET_OPEN argument_list BRACKET_CLOSE",
 /* 117 */ "expr ::= function_call",
 /* 118 */ "function_call ::= IDENTIFIER BRACKET_OPEN argument_list BRACKET_CLOSE",
 /* 119 */ "function_call ::= IDENTIFIER BRACKET_OPEN BRACKET_CLOSE",
 /* 120 */ "argument_list ::= argument_list COMMA argument_item",
 /* 121 */ "argument_list ::= argument_item",
 /* 122 */ "argument_item ::= TIMES",
 /* 123 */ "argument_item ::= expr",
 /* 124 */ "expr ::= expr IS NULL",
 /* 125 */ "expr ::= expr IS NOT NULL",
 /* 126 */ "expr ::= NOT expr",
 /* 127 */ "expr ::= BRACKET_OPEN expr BRACKET_CLOSE",
 /* 128 */ "expr ::= qualified_name",
 /* 129 */ "expr ::= INTEGER",
 /* 130 */ "expr ::= STRING",
 /* 131 */ "expr ::= DOUBLE",
 /* 132 */ "expr ::= NULL",
 /* 133 */ "expr ::= NPLACEHOLDER",
 /* 134 */ "expr ::= SPLACEHOLDER",
 /* 135 */ "qualified_name ::= IDENTIFIER DOT IDENTIFIER",
 /* 136 */ "qualified_name ::= IDENTIFIER",
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
#line 427 "parser.lemon"
{
	if ((yypminor->yy0)) {
		efree((yypminor->yy0)->token);
		efree((yypminor->yy0));
	}
}
#line 1032 "parser.c"
      break;
    case 54:
    case 55:
    case 56:
    case 57:
    case 58:
    case 59:
    case 60:
    case 61:
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
    case 76:
    case 77:
    case 79:
    case 80:
    case 81:
    case 82:
    case 84:
    case 85:
    case 86:
    case 87:
    case 88:
    case 89:
    case 90:
    case 91:
#line 438 "parser.lemon"
{ zval_ptr_dtor(&(yypminor->yy112)); }
#line 1070 "parser.c"
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
  { 53, 1 },
  { 54, 1 },
  { 54, 1 },
  { 54, 1 },
  { 54, 1 },
  { 55, 1 },
  { 55, 2 },
  { 55, 3 },
  { 55, 3 },
  { 55, 4 },
  { 55, 4 },
  { 55, 5 },
  { 55, 5 },
  { 55, 3 },
  { 55, 4 },
  { 55, 4 },
  { 55, 5 },
  { 55, 2 },
  { 55, 3 },
  { 55, 4 },
  { 55, 3 },
  { 55, 4 },
  { 55, 6 },
  { 55, 2 },
  { 55, 3 },
  { 55, 3 },
  { 55, 4 },
  { 55, 5 },
  { 55, 2 },
  { 59, 4 },
  { 59, 5 },
  { 65, 3 },
  { 65, 1 },
  { 68, 1 },
  { 68, 3 },
  { 68, 3 },
  { 68, 2 },
  { 68, 1 },
  { 66, 3 },
  { 66, 1 },
  { 67, 2 },
  { 67, 1 },
  { 71, 1 },
  { 72, 1 },
  { 72, 3 },
  { 72, 2 },
  { 73, 2 },
  { 73, 4 },
  { 73, 3 },
  { 73, 5 },
  { 73, 3 },
  { 73, 3 },
  { 73, 4 },
  { 73, 5 },
  { 73, 6 },
  { 73, 3 },
  { 73, 4 },
  { 73, 5 },
  { 73, 6 },
  { 73, 4 },
  { 73, 6 },
  { 56, 7 },
  { 56, 10 },
  { 75, 3 },
  { 75, 1 },
  { 78, 1 },
  { 76, 3 },
  { 76, 1 },
  { 79, 1 },
  { 57, 1 },
  { 57, 2 },
  { 57, 2 },
  { 57, 3 },
  { 80, 4 },
  { 81, 3 },
  { 81, 1 },
  { 82, 3 },
  { 83, 1 },
  { 58, 1 },
  { 58, 2 },
  { 58, 2 },
  { 58, 3 },
  { 84, 3 },
  { 70, 3 },
  { 70, 2 },
  { 70, 1 },
  { 60, 2 },
  { 61, 3 },
  { 85, 3 },
  { 85, 1 },
  { 86, 1 },
  { 86, 1 },
  { 62, 3 },
  { 87, 3 },
  { 87, 1 },
  { 88, 1 },
  { 88, 1 },
  { 63, 2 },
  { 64, 2 },
  { 69, 2 },
  { 69, 3 },
  { 69, 3 },
  { 69, 3 },
  { 69, 3 },
  { 69, 3 },
  { 69, 3 },
  { 69, 3 },
  { 69, 3 },
  { 69, 3 },
  { 69, 3 },
  { 69, 3 },
  { 69, 3 },
  { 69, 3 },
  { 69, 3 },
  { 69, 4 },
  { 69, 5 },
  { 69, 6 },
  { 69, 1 },
  { 90, 4 },
  { 90, 3 },
  { 89, 3 },
  { 89, 1 },
  { 91, 1 },
  { 91, 1 },
  { 69, 3 },
  { 69, 4 },
  { 69, 2 },
  { 69, 3 },
  { 69, 1 },
  { 69, 1 },
  { 69, 1 },
  { 69, 1 },
  { 69, 1 },
  { 69, 1 },
  { 69, 1 },
  { 74, 3 },
  { 74, 1 },
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
#line 434 "parser.lemon"
{
	status->ret = yymsp[0].minor.yy112;
}
#line 1424 "parser.c"
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
      case 90:
      case 94:
      case 95:
      case 117:
      case 121:
      case 123:
      case 128:
#line 440 "parser.lemon"
{
	yygotominor.yy112 = yymsp[0].minor.yy112;
}
#line 1451 "parser.c"
        break;
      case 5:
#line 458 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_select_statement(yymsp[0].minor.yy112, NULL, NULL, NULL, NULL, NULL);
}
#line 1458 "parser.c"
        break;
      case 6:
#line 462 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_select_statement(yymsp[-1].minor.yy112, yymsp[0].minor.yy112, NULL, NULL, NULL, NULL);
}
#line 1465 "parser.c"
        break;
      case 7:
#line 466 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_select_statement(yymsp[-2].minor.yy112, yymsp[-1].minor.yy112, yymsp[0].minor.yy112, NULL, NULL, NULL);
}
#line 1472 "parser.c"
        break;
      case 8:
#line 470 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_select_statement(yymsp[-2].minor.yy112, yymsp[-1].minor.yy112, NULL, yymsp[0].minor.yy112, NULL, NULL);
}
#line 1479 "parser.c"
        break;
      case 9:
#line 474 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_select_statement(yymsp[-3].minor.yy112, yymsp[-2].minor.yy112, NULL, yymsp[-1].minor.yy112, yymsp[0].minor.yy112, NULL);
}
#line 1486 "parser.c"
        break;
      case 10:
#line 478 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_select_statement(yymsp[-3].minor.yy112, yymsp[-2].minor.yy112, yymsp[0].minor.yy112, yymsp[-1].minor.yy112, NULL, NULL);
}
#line 1493 "parser.c"
        break;
      case 11:
#line 482 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_select_statement(yymsp[-4].minor.yy112, yymsp[-3].minor.yy112, yymsp[-1].minor.yy112, yymsp[-2].minor.yy112, NULL, yymsp[0].minor.yy112);
}
#line 1500 "parser.c"
        break;
      case 12:
#line 486 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_select_statement(yymsp[-4].minor.yy112, yymsp[-3].minor.yy112, yymsp[0].minor.yy112, yymsp[-2].minor.yy112, yymsp[-1].minor.yy112, NULL);
}
#line 1507 "parser.c"
        break;
      case 13:
#line 490 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_select_statement(yymsp[-2].minor.yy112, yymsp[-1].minor.yy112, NULL, NULL, NULL, yymsp[0].minor.yy112);
}
#line 1514 "parser.c"
        break;
      case 14:
#line 494 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_select_statement(yymsp[-3].minor.yy112, yymsp[-2].minor.yy112, yymsp[-1].minor.yy112, NULL, NULL, yymsp[0].minor.yy112);
}
#line 1521 "parser.c"
        break;
      case 15:
#line 498 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_select_statement(yymsp[-3].minor.yy112, yymsp[-2].minor.yy112, NULL, yymsp[-1].minor.yy112, NULL, yymsp[0].minor.yy112);
}
#line 1528 "parser.c"
        break;
      case 16:
#line 502 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_select_statement(yymsp[-4].minor.yy112, yymsp[-3].minor.yy112, NULL, yymsp[-2].minor.yy112, yymsp[-1].minor.yy112, yymsp[0].minor.yy112);
}
#line 1535 "parser.c"
        break;
      case 17:
#line 506 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_select_statement(yymsp[-1].minor.yy112, NULL, yymsp[0].minor.yy112, NULL, NULL, NULL);
}
#line 1542 "parser.c"
        break;
      case 18:
#line 510 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_select_statement(yymsp[-2].minor.yy112, NULL, yymsp[0].minor.yy112, yymsp[-1].minor.yy112, NULL, NULL);
}
#line 1549 "parser.c"
        break;
      case 19:
#line 514 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_select_statement(yymsp[-3].minor.yy112, NULL, yymsp[0].minor.yy112, yymsp[-2].minor.yy112, yymsp[-1].minor.yy112, NULL);
}
#line 1556 "parser.c"
        break;
      case 20:
#line 518 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_select_statement(yymsp[-2].minor.yy112, NULL, yymsp[-1].minor.yy112, NULL, NULL, yymsp[0].minor.yy112);
}
#line 1563 "parser.c"
        break;
      case 21:
#line 522 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_select_statement(yymsp[-3].minor.yy112, NULL, yymsp[-1].minor.yy112, yymsp[-2].minor.yy112, NULL, yymsp[0].minor.yy112);
}
#line 1570 "parser.c"
        break;
      case 22:
#line 526 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_select_statement(yymsp[-5].minor.yy112, yymsp[-4].minor.yy112, yymsp[-1].minor.yy112, yymsp[-3].minor.yy112, yymsp[-2].minor.yy112, yymsp[0].minor.yy112);
}
#line 1577 "parser.c"
        break;
      case 23:
#line 530 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_select_statement(yymsp[-1].minor.yy112, NULL, NULL, yymsp[0].minor.yy112, NULL, NULL);
}
#line 1584 "parser.c"
        break;
      case 24:
#line 534 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_select_statement(yymsp[-2].minor.yy112, NULL, NULL, yymsp[-1].minor.yy112, NULL, yymsp[0].minor.yy112);
}
#line 1591 "parser.c"
        break;
      case 25:
#line 538 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_select_statement(yymsp[-2].minor.yy112, NULL, NULL, yymsp[-1].minor.yy112, yymsp[0].minor.yy112, NULL);
}
#line 1598 "parser.c"
        break;
      case 26:
#line 542 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_select_statement(yymsp[-3].minor.yy112, NULL, NULL, yymsp[-2].minor.yy112, yymsp[-1].minor.yy112, yymsp[0].minor.yy112);
}
#line 1605 "parser.c"
        break;
      case 27:
#line 546 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_select_statement(yymsp[-4].minor.yy112, NULL, yymsp[-1].minor.yy112, yymsp[-3].minor.yy112, yymsp[-2].minor.yy112, yymsp[0].minor.yy112);
}
#line 1612 "parser.c"
        break;
      case 28:
#line 550 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_select_statement(yymsp[-1].minor.yy112, NULL, NULL, NULL, NULL, yymsp[0].minor.yy112);
}
#line 1619 "parser.c"
        break;
      case 29:
#line 556 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_select_clause(yymsp[-2].minor.yy112, yymsp[0].minor.yy112, NULL);
  yy_destructor(18,&yymsp[-3].minor);
  yy_destructor(19,&yymsp[-1].minor);
}
#line 1628 "parser.c"
        break;
      case 30:
#line 560 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_select_clause(yymsp[-3].minor.yy112, yymsp[-1].minor.yy112, yymsp[0].minor.yy112);
  yy_destructor(18,&yymsp[-4].minor);
  yy_destructor(19,&yymsp[-2].minor);
}
#line 1637 "parser.c"
        break;
      case 31:
      case 38:
      case 63:
      case 66:
      case 74:
      case 88:
      case 93:
      case 120:
#line 566 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_zval_list(yymsp[-2].minor.yy112, yymsp[0].minor.yy112);
  yy_destructor(20,&yymsp[-1].minor);
}
#line 1652 "parser.c"
        break;
      case 33:
      case 122:
#line 576 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_column_item(PHQL_T_ALL, NULL, NULL, NULL);
  yy_destructor(7,&yymsp[0].minor);
}
#line 1661 "parser.c"
        break;
      case 34:
#line 580 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_column_item(PHQL_T_DOMAINALL, NULL, yymsp[-2].minor.yy0, NULL);
  yy_destructor(22,&yymsp[-1].minor);
  yy_destructor(7,&yymsp[0].minor);
}
#line 1670 "parser.c"
        break;
      case 35:
#line 584 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-2].minor.yy112, NULL, yymsp[0].minor.yy0);
  yy_destructor(23,&yymsp[-1].minor);
}
#line 1678 "parser.c"
        break;
      case 36:
#line 588 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-1].minor.yy112, NULL, yymsp[0].minor.yy0);
}
#line 1685 "parser.c"
        break;
      case 37:
#line 592 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_column_item(PHQL_T_EXPR, yymsp[0].minor.yy112, NULL, NULL);
}
#line 1692 "parser.c"
        break;
      case 40:
#line 608 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_zval_list(yymsp[-1].minor.yy112, yymsp[0].minor.yy112);
}
#line 1699 "parser.c"
        break;
      case 43:
#line 624 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_join_item(yymsp[0].minor.yy112, NULL);
}
#line 1706 "parser.c"
        break;
      case 44:
#line 628 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_join_item(yymsp[-2].minor.yy112, yymsp[0].minor.yy0);
  yy_destructor(23,&yymsp[-1].minor);
}
#line 1714 "parser.c"
        break;
      case 45:
#line 632 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_join_item(yymsp[-1].minor.yy112, yymsp[0].minor.yy0);
}
#line 1721 "parser.c"
        break;
      case 46:
#line 638 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_join_clause(PHQL_T_INNERJOIN, yymsp[0].minor.yy112, NULL);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1729 "parser.c"
        break;
      case 47:
#line 642 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_join_clause(PHQL_T_INNERJOIN, yymsp[-2].minor.yy112, yymsp[0].minor.yy112);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1738 "parser.c"
        break;
      case 48:
#line 646 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_join_clause(PHQL_T_INNERJOIN, yymsp[0].minor.yy112, NULL);
  yy_destructor(26,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1747 "parser.c"
        break;
      case 49:
#line 650 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_join_clause(PHQL_T_INNERJOIN, yymsp[-2].minor.yy112, yymsp[0].minor.yy112);
  yy_destructor(26,&yymsp[-4].minor);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1757 "parser.c"
        break;
      case 50:
#line 654 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_join_clause(PHQL_T_CROSSJOIN, yymsp[0].minor.yy112, NULL);
  yy_destructor(27,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1766 "parser.c"
        break;
      case 51:
#line 658 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_join_clause(PHQL_T_LEFTJOIN, yymsp[0].minor.yy112, NULL);
  yy_destructor(28,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1775 "parser.c"
        break;
      case 52:
#line 662 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_join_clause(PHQL_T_LEFTJOIN, yymsp[0].minor.yy112, NULL);
  yy_destructor(28,&yymsp[-3].minor);
  yy_destructor(29,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1785 "parser.c"
        break;
      case 53:
#line 666 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_join_clause(PHQL_T_LEFTJOIN, yymsp[-2].minor.yy112, yymsp[0].minor.yy112);
  yy_destructor(28,&yymsp[-4].minor);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1795 "parser.c"
        break;
      case 54:
#line 670 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_join_clause(PHQL_T_LEFTJOIN, yymsp[-2].minor.yy112, yymsp[0].minor.yy112);
  yy_destructor(28,&yymsp[-5].minor);
  yy_destructor(29,&yymsp[-4].minor);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1806 "parser.c"
        break;
      case 55:
#line 674 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_join_clause(PHQL_T_RIGHTJOIN, yymsp[0].minor.yy112, NULL);
  yy_destructor(30,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1815 "parser.c"
        break;
      case 56:
#line 678 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_join_clause(PHQL_T_RIGHTJOIN, yymsp[0].minor.yy112, NULL);
  yy_destructor(30,&yymsp[-3].minor);
  yy_destructor(29,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1825 "parser.c"
        break;
      case 57:
#line 682 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_join_clause(PHQL_T_RIGHTJOIN, yymsp[-2].minor.yy112, yymsp[0].minor.yy112);
  yy_destructor(30,&yymsp[-4].minor);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1835 "parser.c"
        break;
      case 58:
#line 686 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_join_clause(PHQL_T_RIGHTJOIN, yymsp[-2].minor.yy112, yymsp[0].minor.yy112);
  yy_destructor(30,&yymsp[-5].minor);
  yy_destructor(29,&yymsp[-4].minor);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1846 "parser.c"
        break;
      case 59:
#line 690 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_join_clause(PHQL_T_FULLOUTER, yymsp[0].minor.yy112, NULL);
  yy_destructor(31,&yymsp[-3].minor);
  yy_destructor(29,&yymsp[-2].minor);
  yy_destructor(24,&yymsp[-1].minor);
}
#line 1856 "parser.c"
        break;
      case 60:
#line 694 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_join_clause(PHQL_T_FULLOUTER, yymsp[-2].minor.yy112, yymsp[0].minor.yy112);
  yy_destructor(31,&yymsp[-5].minor);
  yy_destructor(29,&yymsp[-4].minor);
  yy_destructor(24,&yymsp[-3].minor);
  yy_destructor(25,&yymsp[-1].minor);
}
#line 1867 "parser.c"
        break;
      case 61:
#line 701 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_insert_statement(yymsp[-4].minor.yy112, NULL, yymsp[-1].minor.yy112);
  yy_destructor(32,&yymsp[-6].minor);
  yy_destructor(33,&yymsp[-5].minor);
  yy_destructor(34,&yymsp[-3].minor);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
#line 1879 "parser.c"
        break;
      case 62:
#line 705 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_insert_statement(yymsp[-7].minor.yy112, yymsp[-5].minor.yy112, yymsp[-1].minor.yy112);
  yy_destructor(32,&yymsp[-9].minor);
  yy_destructor(33,&yymsp[-8].minor);
  yy_destructor(35,&yymsp[-6].minor);
  yy_destructor(36,&yymsp[-4].minor);
  yy_destructor(34,&yymsp[-3].minor);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
#line 1893 "parser.c"
        break;
      case 68:
      case 136:
#line 735 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_qualified_name(yymsp[0].minor.yy0, NULL);
}
#line 1901 "parser.c"
        break;
      case 69:
#line 743 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_update_statement(yymsp[0].minor.yy112, NULL, NULL);
}
#line 1908 "parser.c"
        break;
      case 70:
#line 747 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_update_statement(yymsp[-1].minor.yy112, yymsp[0].minor.yy112, NULL);
}
#line 1915 "parser.c"
        break;
      case 71:
#line 751 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_update_statement(yymsp[-1].minor.yy112, NULL, yymsp[0].minor.yy112);
}
#line 1922 "parser.c"
        break;
      case 72:
#line 755 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_update_statement(yymsp[-2].minor.yy112, yymsp[-1].minor.yy112, yymsp[0].minor.yy112);
}
#line 1929 "parser.c"
        break;
      case 73:
#line 761 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_update_clause(yymsp[-2].minor.yy112, yymsp[0].minor.yy112);
  yy_destructor(37,&yymsp[-3].minor);
  yy_destructor(38,&yymsp[-1].minor);
}
#line 1938 "parser.c"
        break;
      case 76:
#line 777 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_update_item(yymsp[-2].minor.yy112, yymsp[0].minor.yy112);
  yy_destructor(12,&yymsp[-1].minor);
}
#line 1946 "parser.c"
        break;
      case 78:
#line 789 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_delete_statement(yymsp[0].minor.yy112, NULL, NULL);
}
#line 1953 "parser.c"
        break;
      case 79:
#line 793 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_delete_statement(yymsp[-1].minor.yy112, yymsp[0].minor.yy112, NULL);
}
#line 1960 "parser.c"
        break;
      case 80:
#line 797 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_delete_statement(yymsp[-1].minor.yy112, NULL, yymsp[0].minor.yy112);
}
#line 1967 "parser.c"
        break;
      case 81:
#line 801 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_delete_statement(yymsp[-2].minor.yy112, yymsp[-1].minor.yy112, yymsp[0].minor.yy112);
}
#line 1974 "parser.c"
        break;
      case 82:
#line 807 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_delete_clause(yymsp[0].minor.yy112);
  yy_destructor(39,&yymsp[-2].minor);
  yy_destructor(19,&yymsp[-1].minor);
}
#line 1983 "parser.c"
        break;
      case 83:
#line 813 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_assoc_name(yymsp[-2].minor.yy112, yymsp[0].minor.yy0);
  yy_destructor(23,&yymsp[-1].minor);
}
#line 1991 "parser.c"
        break;
      case 84:
#line 817 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_assoc_name(yymsp[-1].minor.yy112, yymsp[0].minor.yy0);
}
#line 1998 "parser.c"
        break;
      case 85:
#line 821 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_assoc_name(yymsp[0].minor.yy112, NULL);
}
#line 2005 "parser.c"
        break;
      case 86:
#line 827 "parser.lemon"
{
	yygotominor.yy112 = yymsp[0].minor.yy112;
  yy_destructor(40,&yymsp[-1].minor);
}
#line 2013 "parser.c"
        break;
      case 87:
#line 833 "parser.lemon"
{
	yygotominor.yy112 = yymsp[0].minor.yy112;
  yy_destructor(41,&yymsp[-2].minor);
  yy_destructor(42,&yymsp[-1].minor);
}
#line 2022 "parser.c"
        break;
      case 91:
      case 96:
      case 129:
#line 853 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_literal_zval(PHQL_T_INTEGER, yymsp[0].minor.yy0);
}
#line 2031 "parser.c"
        break;
      case 92:
#line 857 "parser.lemon"
{
	yygotominor.yy112 = yymsp[0].minor.yy112;
  yy_destructor(44,&yymsp[-2].minor);
  yy_destructor(42,&yymsp[-1].minor);
}
#line 2040 "parser.c"
        break;
      case 97:
#line 883 "parser.lemon"
{
	yygotominor.yy112 = yymsp[0].minor.yy112;
  yy_destructor(45,&yymsp[-1].minor);
}
#line 2048 "parser.c"
        break;
      case 98:
#line 889 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_literal_zval(PHQL_T_INTEGER, yymsp[0].minor.yy0);
  yy_destructor(46,&yymsp[-1].minor);
}
#line 2056 "parser.c"
        break;
      case 99:
#line 895 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_expr(PHQL_T_MINUS, NULL, yymsp[0].minor.yy112);
  yy_destructor(5,&yymsp[-1].minor);
}
#line 2064 "parser.c"
        break;
      case 100:
#line 899 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_expr(PHQL_T_SUB, yymsp[-2].minor.yy112, yymsp[0].minor.yy112);
  yy_destructor(5,&yymsp[-1].minor);
}
#line 2072 "parser.c"
        break;
      case 101:
#line 903 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_expr(PHQL_T_ADD, yymsp[-2].minor.yy112, yymsp[0].minor.yy112);
  yy_destructor(4,&yymsp[-1].minor);
}
#line 2080 "parser.c"
        break;
      case 102:
#line 907 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_expr(PHQL_T_MUL, yymsp[-2].minor.yy112, yymsp[0].minor.yy112);
  yy_destructor(7,&yymsp[-1].minor);
}
#line 2088 "parser.c"
        break;
      case 103:
#line 911 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_expr(PHQL_T_DIV, yymsp[-2].minor.yy112, yymsp[0].minor.yy112);
  yy_destructor(6,&yymsp[-1].minor);
}
#line 2096 "parser.c"
        break;
      case 104:
#line 915 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_expr(PHQL_T_MOD, yymsp[-2].minor.yy112, yymsp[0].minor.yy112);
  yy_destructor(8,&yymsp[-1].minor);
}
#line 2104 "parser.c"
        break;
      case 105:
#line 919 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_expr(PHQL_T_AND, yymsp[-2].minor.yy112, yymsp[0].minor.yy112);
  yy_destructor(10,&yymsp[-1].minor);
}
#line 2112 "parser.c"
        break;
      case 106:
#line 923 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_expr(PHQL_T_OR, yymsp[-2].minor.yy112, yymsp[0].minor.yy112);
  yy_destructor(11,&yymsp[-1].minor);
}
#line 2120 "parser.c"
        break;
      case 107:
#line 927 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_expr(PHQL_T_EQUALS, yymsp[-2].minor.yy112, yymsp[0].minor.yy112);
  yy_destructor(12,&yymsp[-1].minor);
}
#line 2128 "parser.c"
        break;
      case 108:
#line 931 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_expr(PHQL_T_NOTEQUALS, yymsp[-2].minor.yy112, yymsp[0].minor.yy112);
  yy_destructor(13,&yymsp[-1].minor);
}
#line 2136 "parser.c"
        break;
      case 109:
#line 935 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_expr(PHQL_T_LESS, yymsp[-2].minor.yy112, yymsp[0].minor.yy112);
  yy_destructor(14,&yymsp[-1].minor);
}
#line 2144 "parser.c"
        break;
      case 110:
#line 939 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_expr(PHQL_T_GREATER, yymsp[-2].minor.yy112, yymsp[0].minor.yy112);
  yy_destructor(15,&yymsp[-1].minor);
}
#line 2152 "parser.c"
        break;
      case 111:
#line 943 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_expr(PHQL_T_GREATEREQUAL, yymsp[-2].minor.yy112, yymsp[0].minor.yy112);
  yy_destructor(16,&yymsp[-1].minor);
}
#line 2160 "parser.c"
        break;
      case 112:
#line 947 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_expr(PHQL_T_LESSEQUAL, yymsp[-2].minor.yy112, yymsp[0].minor.yy112);
  yy_destructor(17,&yymsp[-1].minor);
}
#line 2168 "parser.c"
        break;
      case 113:
#line 951 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_expr(PHQL_T_LIKE, yymsp[-2].minor.yy112, yymsp[0].minor.yy112);
  yy_destructor(9,&yymsp[-1].minor);
}
#line 2176 "parser.c"
        break;
      case 114:
#line 955 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_expr(PHQL_T_NLIKE, yymsp[-3].minor.yy112, yymsp[0].minor.yy112);
  yy_destructor(1,&yymsp[-2].minor);
  yy_destructor(9,&yymsp[-1].minor);
}
#line 2185 "parser.c"
        break;
      case 115:
#line 959 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_expr(PHQL_T_IN, yymsp[-4].minor.yy112, yymsp[-1].minor.yy112);
  yy_destructor(2,&yymsp[-3].minor);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
#line 2195 "parser.c"
        break;
      case 116:
#line 963 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_expr(PHQL_T_NOTIN, yymsp[-5].minor.yy112, yymsp[-1].minor.yy112);
  yy_destructor(1,&yymsp[-4].minor);
  yy_destructor(2,&yymsp[-3].minor);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
#line 2206 "parser.c"
        break;
      case 118:
#line 973 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_func_call(yymsp[-3].minor.yy0, yymsp[-1].minor.yy112);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
#line 2215 "parser.c"
        break;
      case 119:
#line 977 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_func_call(yymsp[-2].minor.yy0, NULL);
  yy_destructor(35,&yymsp[-1].minor);
  yy_destructor(36,&yymsp[0].minor);
}
#line 2224 "parser.c"
        break;
      case 124:
#line 1001 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_expr(PHQL_T_ISNULL, yymsp[-2].minor.yy112, NULL);
  yy_destructor(3,&yymsp[-1].minor);
  yy_destructor(47,&yymsp[0].minor);
}
#line 2233 "parser.c"
        break;
      case 125:
#line 1005 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_expr(PHQL_T_ISNOTNULL, yymsp[-3].minor.yy112, NULL);
  yy_destructor(3,&yymsp[-2].minor);
  yy_destructor(1,&yymsp[-1].minor);
  yy_destructor(47,&yymsp[0].minor);
}
#line 2243 "parser.c"
        break;
      case 126:
#line 1009 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_expr(PHQL_T_NOT, NULL, yymsp[0].minor.yy112);
  yy_destructor(1,&yymsp[-1].minor);
}
#line 2251 "parser.c"
        break;
      case 127:
#line 1013 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_expr(PHQL_T_ENCLOSED, yymsp[-1].minor.yy112, NULL);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
#line 2260 "parser.c"
        break;
      case 130:
#line 1025 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_literal_zval(PHQL_T_STRING, yymsp[0].minor.yy0);
}
#line 2267 "parser.c"
        break;
      case 131:
#line 1029 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_literal_zval(PHQL_T_DOUBLE, yymsp[0].minor.yy0);
}
#line 2274 "parser.c"
        break;
      case 132:
#line 1033 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_literal_zval(PHQL_T_NULL, NULL);
  yy_destructor(47,&yymsp[0].minor);
}
#line 2282 "parser.c"
        break;
      case 133:
#line 1037 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_placeholder_zval(PHQL_T_NPLACEHOLDER, yymsp[0].minor.yy0);
}
#line 2289 "parser.c"
        break;
      case 134:
#line 1041 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_placeholder_zval(PHQL_T_SPLACEHOLDER, yymsp[0].minor.yy0);
}
#line 2296 "parser.c"
        break;
      case 135:
#line 1047 "parser.lemon"
{
	yygotominor.yy112 = phql_ret_qualified_name(yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(22,&yymsp[-1].minor);
}
#line 2304 "parser.c"
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
#line 389 "parser.lemon"

	if (status->scanner_state->start) {
		{

			char *token_name;
			const phql_token_names *tokens = phql_tokens;
			int active_token = status->scanner_state->active_token;

			if (active_token) {

				do {
					if (tokens->code == active_token) {
						token_name = tokens->name;
						break;
					}
					++tokens;
				} while (tokens[0].code != 0);

			} else {
				token_name = estrndup("UNKNOWN", strlen("UNKNOWN"));
			}

			status->syntax_error_len = 48 + strlen(token_name) + strlen(status->scanner_state->start);
			status->syntax_error = emalloc(sizeof(char)*status->syntax_error_len);
			sprintf(status->syntax_error, "Syntax error, unexpected token %s, near to %s", token_name, status->scanner_state->start);

			if (!active_token) {
				efree(token_name);
			}
		}
	} else {
		status->syntax_error_len = strlen("Syntax error, unexpected EOF");
		status->syntax_error = estrndup("Syntax error, unexpected EOF", status->syntax_error_len);
	}

	status->status = PHQL_PARSING_FAILED;

#line 2384 "parser.c"
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

	zval *error_msg, *exception;

	if(phql_internal_parse_phql(&result, Z_STRVAL_P(phql), &error_msg TSRMLS_CC) == FAILURE){
		PHALCON_ALLOC_ZVAL_MM(exception);
		object_init_ex(exception, phalcon_mvc_model_exception_ce);
		if (phalcon_call_method_one_param(NULL, exception, "__construct", strlen("__construct"), error_msg, PH_CHECK, 0 TSRMLS_CC) == FAILURE) {
			return FAILURE;
		}
		phalcon_throw_exception(exception TSRMLS_CC);
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

	void* phql_parser = phql_Alloc(phql_wrapper_alloc);

	parser_status = emalloc(sizeof(phql_parser_status));
	state = emalloc(sizeof(phql_scanner_state));
	token = emalloc(sizeof(phql_scanner_token));

	parser_status->status = PHQL_PARSING_OK;
	parser_status->scanner_state = state;

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
			ZVAL_ZVAL(*result, parser_status->ret, 0, 0);
			ZVAL_NULL(parser_status->ret);
			zval_ptr_dtor(&parser_status->ret);
		}
	}

	efree(parser_status);
	efree(state);
	efree(token);

	return status;
}