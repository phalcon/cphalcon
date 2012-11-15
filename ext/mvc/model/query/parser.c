/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is include which follows the "include" declaration
** in the input file. */
#include <stdio.h>
// 35 "parser.lemon"


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
	add_assoc_stringl(ret, "name", name->token, name->token_len, 1);
	efree(name->token);
	efree(name);

	if (arguments) {
		add_assoc_zval(ret, "arguments", arguments);
	}

	return ret;
}


// 398 "parser.c"
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
#define YYNOCODE 100
#define YYACTIONTYPE unsigned short int
#define phql_TOKENTYPE phql_parser_token*
typedef union {
  phql_TOKENTYPE yy0;
  zval* yy90;
  int yy199;
} YYMINORTYPE;
#define YYSTACKDEPTH 100
#define phql_ARG_SDECL phql_parser_status *status;
#define phql_ARG_PDECL ,phql_parser_status *status
#define phql_ARG_FETCH phql_parser_status *status = yypParser->status
#define phql_ARG_STORE yypParser->status = status
#define YYNSTATE 229
#define YYNRULE 141
#define YYERRORSYMBOL 55
#define YYERRSYMDT yy199
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
 /*     0 */    55,   57,   59,   61,   63,   65,   51,   53,   67,   47,
 /*    10 */    45,   49,   43,   40,   75,   72,   69,    7,  117,  119,
 /*    20 */   181,  127,  179,    9,   55,   57,   59,   61,   63,   65,
 /*    30 */    51,   53,   67,   47,   45,   49,   43,   40,   75,   72,
 /*    40 */    69,   55,   57,   59,   61,   63,   65,   51,   53,   67,
 /*    50 */    47,   45,   49,   43,   40,   75,   72,   69,   89,   94,
 /*    60 */    70,   41,    8,   16,   90,  108,   11,  103,   83,   51,
 /*    70 */    53,   67,   47,   45,   49,   43,   40,   75,   72,   69,
 /*    80 */    31,   89,   92,   87,   41,  131,   81,   90,  182,  178,
 /*    90 */   114,   83,   96,  234,   95,  229,   29,   99,   97,   98,
 /*   100 */   100,  101,   80,  174,   30,   92,   41,  111,  116,   90,
 /*   110 */    23,   34,   26,  175,   82,   96,   35,  230,   17,   37,
 /*   120 */    99,   97,   98,  100,  101,   74,  195,   92,   41,  204,
 /*   130 */    95,   90,  133,  128,   21,   83,  171,   96,  231,  109,
 /*   140 */   166,   10,   99,   97,   98,  100,  101,  201,  164,   92,
 /*   150 */    82,  102,  147,  148,  150,  152,  134,  156,  160,   96,
 /*   160 */   170,  136,  137,  196,   99,   97,   98,  100,  101,   75,
 /*   170 */    72,   69,  371,    1,    2,    3,    4,    5,    6,  236,
 /*   180 */   232,  217,   67,   47,   45,   49,   43,   40,   75,   72,
 /*   190 */    69,  214,  221,   47,   45,   49,   43,   40,   75,   72,
 /*   200 */    69,  205,  147,  148,  150,  152,  222,  156,  160,   43,
 /*   210 */    40,   75,   72,   69,   74,   18,  233,   74,   20,   95,
 /*   220 */   235,   74,   95,  237,  243,  192,   95,   10,  173,  178,
 /*   230 */    95,  252,  220,  188,   95,  328,  193,   95,   79,   82,
 /*   240 */    88,   85,   82,   88,  130,  105,   82,   88,  192,  219,
 /*   250 */    82,  238,  241,   95,   82,   12,  199,   82,  183,  193,
 /*   260 */    13,   21,  329,  211,   21,  226,  109,   29,   10,  192,
 /*   270 */    38,   10,   21,   82,   95,  330,   39,  239,   38,   10,
 /*   280 */   191,   95,   25,   26,   14,  107,   42,  251,   27,   28,
 /*   290 */    95,   95,   21,   44,   82,   15,  139,  143,   95,   10,
 /*   300 */    10,   82,   46,  120,   48,  122,  126,   95,   50,   95,
 /*   310 */    82,   82,   52,   95,   54,   56,   58,   95,   82,   95,
 /*   320 */    95,   95,  135,  136,  137,   10,   60,   82,  296,   82,
 /*   330 */    62,   95,  254,   82,  305,   95,   19,   82,   64,   82,
 /*   340 */    82,   82,   66,   95,   68,   71,  146,   95,  144,   95,
 /*   350 */    95,   82,   91,   93,  129,   82,  141,   95,   95,   95,
 /*   360 */    77,  246,   32,   82,  247,   81,  142,   82,  128,   82,
 /*   370 */    82,   95,   81,   21,  128,   84,  208,   82,   82,   82,
 /*   380 */    10,   86,  208,  114,   31,  248,  123,  245,  106,  125,
 /*   390 */    24,   82,  153,   76,  132,  172,  154,  297,  157,  165,
 /*   400 */   161,  113,  158,  166,  162,  169,  177,  167,  115,   10,
 /*   410 */   190,  176,   10,  186,  194,  306,   33,  206,  217,  190,
 /*   420 */   223,  212,   22,  228,   84,  166,  189,  166,   32,  216,
 /*   430 */    33,  240,   36,   10,  244,  200,   69,   73,   78,  104,
 /*   440 */   210,  242,  110,  225,  112,  208,  249,  250,  118,  121,
 /*   450 */   124,  256,  255,  253,  257,  138,   31,  141,  145,  278,
 /*   460 */   149,  279,  184,  208,  280,  140,  151,  187,  155,  281,
 /*   470 */   282,  283,  288,  185,  198,  289,  202,  284,  285,  159,
 /*   480 */   286,  168,  163,  180,  203,  299,  331,  207,  298,  215,
 /*   490 */   209,  218,  308,  224,  307,  197,  227,  242,  242,  242,
 /*   500 */   242,  242,  213,
};
static YYCODETYPE yy_lookahead[] = {
 /*     0 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    10 */    11,   12,   13,   14,   15,   16,   17,   63,   64,   65,
 /*    20 */    21,   67,   23,   67,    1,    2,    3,    4,    5,    6,
 /*    30 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*    40 */    17,    1,    2,    3,    4,    5,    6,    7,    8,    9,
 /*    50 */    10,   11,   12,   13,   14,   15,   16,   17,   11,   36,
 /*    60 */     9,   14,   64,   65,   17,   67,   45,   16,   21,    7,
 /*    70 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*    80 */    21,   11,   35,   36,   14,   68,   20,   17,   71,   72,
 /*    90 */    77,   21,   45,    0,   77,    0,   77,   50,   51,   52,
 /*   100 */    53,   54,   36,   11,   45,   35,   14,   94,   95,   17,
 /*   110 */    91,   92,   93,   21,   97,   45,   64,    0,   66,   67,
 /*   120 */    50,   51,   52,   53,   54,   72,   81,   35,   14,   84,
 /*   130 */    77,   17,   69,   40,   41,   21,   73,   45,    0,   46,
 /*   140 */    77,   48,   50,   51,   52,   53,   54,   20,   20,   35,
 /*   150 */    97,   98,   24,   25,   26,   27,   70,   29,   30,   45,
 /*   160 */    74,   75,   76,   36,   50,   51,   52,   53,   54,   15,
 /*   170 */    16,   17,   56,   57,   58,   59,   60,   61,   62,    0,
 /*   180 */     0,   77,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   190 */    17,   87,   88,   10,   11,   12,   13,   14,   15,   16,
 /*   200 */    17,   85,   24,   25,   26,   27,   90,   29,   30,   13,
 /*   210 */    14,   15,   16,   17,   72,   64,    0,   72,   67,   77,
 /*   220 */     0,   72,   77,    0,    0,   72,   77,   48,   71,   72,
 /*   230 */    77,    0,   72,   80,   77,    0,   83,   77,   96,   97,
 /*   240 */    98,   96,   97,   98,   18,   96,   97,   98,   72,   89,
 /*   250 */    97,    0,    0,   77,   97,   20,   80,   97,   32,   83,
 /*   260 */    45,   41,    0,   37,   41,   39,   46,   77,   48,   72,
 /*   270 */    47,   48,   41,   97,   77,    0,   72,    0,   47,   48,
 /*   280 */    83,   77,   92,   93,   49,   72,   72,    0,   43,   44,
 /*   290 */    77,   77,   41,   72,   97,   45,   78,   79,   77,   48,
 /*   300 */    48,   97,   72,   64,   72,   66,   67,   77,   72,   77,
 /*   310 */    97,   97,   72,   77,   72,   72,   72,   77,   97,   77,
 /*   320 */    77,   77,   74,   75,   76,   48,   72,   97,    0,   97,
 /*   330 */    72,   77,    0,   97,    0,   77,   67,   97,   72,   97,
 /*   340 */    97,   97,   72,   77,   72,   72,   21,   77,   23,   77,
 /*   350 */    77,   97,   72,   72,   72,   97,   31,   77,   77,   77,
 /*   360 */    17,    0,   22,   97,    0,   20,   72,   97,   40,   97,
 /*   370 */    97,   77,   20,   41,   40,   35,   48,   97,   97,   97,
 /*   380 */    48,   36,   48,   77,   21,    0,   64,    0,   36,   67,
 /*   390 */    20,   97,   24,   50,   19,   20,   28,    0,   24,   73,
 /*   400 */    24,   95,   28,   77,   28,   21,   11,   23,   45,   48,
 /*   410 */    20,   22,   48,   34,   35,    0,   21,   63,   77,   20,
 /*   420 */    63,   73,   42,   73,   35,   77,   36,   77,   22,   88,
 /*   430 */    21,    0,   67,   48,    0,   36,   17,   35,   50,   35,
 /*   440 */    86,    0,   42,   86,   20,   48,    0,    0,   67,   67,
 /*   450 */    67,    0,    0,    0,    0,   77,   21,   31,   21,   21,
 /*   460 */    24,   21,   33,   48,   21,   79,   24,   35,   24,   21,
 /*   470 */    21,   21,    0,   77,   35,    0,   84,   21,   21,   24,
 /*   480 */    21,   21,   24,   21,   21,    0,    0,   86,    0,   20,
 /*   490 */    45,    1,    0,   86,    0,   34,   19,   99,   99,   99,
 /*   500 */    99,   99,   38,
};
#define YY_SHIFT_USE_DFLT (-2)
static short yy_shift_ofst[] = {
 /*     0 */   226,   95,  117,  138,  180,  216,   93,  220,  179,  224,
 /*    10 */    21,  235,  215,  262,  250,  275,  223,  251,  252,  287,
 /*    20 */   387,  380,   59,  370,   59,   -2,  245,   -2,   -2,   -2,
 /*    30 */    -2,  406,  409,   -2,   -2,  277,  431,  434,  114,   40,
 /*    40 */   114,  114,  154,  114,  154,  114,  196,  114,  196,  114,
 /*    50 */   196,  114,  173,  114,  173,  114,   62,  114,   62,  114,
 /*    60 */    62,  114,   62,  114,   62,  114,   62,  114,  183,   51,
 /*    70 */   114,  419,  402,   70,   40,  343,   -2,  388,   -2,   66,
 /*    80 */    -2,   70,   -2,  340,   47,  345,   -2,   -2,   -2,   -2,
 /*    90 */   114,  419,  114,   23,   -2,   -2,   -2,   -2,   -2,   -2,
 /*   100 */    -2,   -2,   -2,  404,   70,  352,   -2,  154,  441,  400,
 /*   110 */   363,  424,  363,   -2,   -2,   -2,   -2,  361,  446,  231,
 /*   120 */   364,  447,  332,  385,  451,  452,  453,  454,  114,   40,
 /*   130 */    92,  375,  435,  128,  178,   -2,   -2,  435,  325,  426,
 /*   140 */    -2,  114,   40,   -2,  437,   -2,   -2,  438,  436,  440,
 /*   150 */   442,  443,  368,  448,  444,  449,  374,  450,  455,  456,
 /*   160 */   376,  457,  458,  459,  435,   -2,  384,  460,   -2,   -2,
 /*   170 */    -2,   -2,   92,   -2,   -2,  389,  395,   -2,   -1,  462,
 /*   180 */    -2,   -2,   -2,  429,  435,  379,  432,  114,  390,  472,
 /*   190 */   114,   -2,   40,   -2,  463,  127,  461,  439,  114,  399,
 /*   200 */   475,  463,   -2,   -2,   -2,  328,  397,  485,  445,  486,
 /*   210 */   488,  435,  464,  435,  469,  435,   -2,  490,  114,   -2,
 /*   220 */    40,   -2,  334,  415,  492,  494,  477,  435,   -2,
};
#define YY_REDUCE_USE_DFLT (-47)
static short yy_reduce_ofst[] = {
 /*     0 */   116,  -47,  -47,  -47,  -47,  -47,  -46,   -2,  -44,  -47,
 /*    10 */   -47,  -47,  -47,  -47,  -47,  -47,   52,  151,  269,  -47,
 /*    20 */   -47,  -47,   19,  -47,  190,  -47,  -47,  -47,  -47,  -47,
 /*    30 */   -47,  -47,  -47,  -47,  -47,  365,  -47,  -47,  204,  -47,
 /*    40 */   213,  214,  -47,  221,  -47,  230,  -47,  232,  -47,  236,
 /*    50 */   -47,  240,  -47,  242,  -47,  243,  -47,  244,  -47,  254,
 /*    60 */   -47,  258,  -47,  266,  -47,  270,  -47,  272,  -47,  -47,
 /*    70 */   273,  -47,  -47,  142,  -47,  -47,  -47,  -47,  -47,  -47,
 /*    80 */   -47,   53,  -47,  -47,  145,  -47,  -47,  -47,  -47,  -47,
 /*    90 */   280,  -47,  281,  -47,  -47,  -47,  -47,  -47,  -47,  -47,
 /*   100 */   -47,  -47,  -47,  -47,  149,  -47,  -47,  -47,  -47,  -47,
 /*   110 */    13,  -47,  306,  -47,  -47,  -47,  -47,  381,  -47,  239,
 /*   120 */   382,  -47,  322,  383,  -47,  -47,  -47,  -47,  282,  -47,
 /*   130 */    17,  -47,   63,   86,  248,  -47,  -47,  378,  218,  386,
 /*   140 */   -47,  294,  -47,  -47,  -47,  -47,  -47,  -47,  -47,  -47,
 /*   150 */   -47,  -47,  -47,  -47,  -47,  -47,  -47,  -47,  -47,  -47,
 /*   160 */   -47,  -47,  -47,  -47,  326,  -47,  -47,  -47,  -47,  -47,
 /*   170 */   -47,  -47,  157,  -47,  -47,  -47,  -47,  -47,  -47,  -47,
 /*   180 */   -47,  -47,  -47,  -47,  396,  -47,  -47,  153,  -47,  -47,
 /*   190 */   197,  -47,  -47,  -47,   45,  -47,  -47,  -47,  176,  -47,
 /*   200 */   -47,  392,  -47,  -47,  -47,  354,  401,  -47,  -47,  -47,
 /*   210 */   -47,  348,  -47,  104,  -47,  341,  -47,  -47,  160,  -47,
 /*   220 */   -47,  -47,  357,  407,  -47,  -47,  -47,  350,  -47,
};
static YYACTIONTYPE yy_default[] = {
 /*     0 */   370,  370,  370,  370,  370,  370,  370,  370,  370,  370,
 /*    10 */   370,  370,  370,  370,  370,  370,  370,  370,  370,  370,
 /*    20 */   370,  370,  370,  314,  370,  315,  317,  318,  319,  320,
 /*    30 */   321,  369,  370,  368,  316,  370,  370,  370,  370,  327,
 /*    40 */   370,  370,  332,  370,  334,  370,  335,  370,  336,  370,
 /*    50 */   337,  370,  338,  370,  339,  370,  340,  370,  341,  370,
 /*    60 */   342,  370,  343,  370,  344,  370,  345,  370,  346,  370,
 /*    70 */   370,  347,  370,  370,  356,  370,  357,  370,  358,  370,
 /*    80 */   348,  370,  350,  369,  370,  370,  351,  352,  354,  355,
 /*    90 */   370,  359,  370,  370,  360,  361,  362,  363,  364,  365,
 /*   100 */   366,  367,  353,  370,  370,  370,  349,  333,  370,  370,
 /*   110 */   370,  322,  370,  323,  325,  326,  324,  370,  370,  370,
 /*   120 */   370,  370,  370,  370,  370,  370,  370,  370,  370,  313,
 /*   130 */   370,  370,  370,  258,  259,  269,  271,  370,  272,  273,
 /*   140 */   275,  370,  287,  274,  370,  276,  277,  370,  370,  370,
 /*   150 */   370,  370,  370,  370,  370,  370,  370,  370,  370,  370,
 /*   160 */   370,  370,  370,  370,  370,  267,  312,  370,  310,  311,
 /*   170 */   270,  268,  370,  260,  262,  369,  370,  263,  266,  370,
 /*   180 */   264,  265,  261,  370,  370,  370,  370,  370,  370,  370,
 /*   190 */   370,  290,  292,  291,  370,  370,  370,  370,  370,  370,
 /*   200 */   370,  370,  293,  295,  294,  370,  370,  370,  370,  370,
 /*   210 */   370,  370,  370,  370,  300,  370,  301,  370,  370,  303,
 /*   220 */   304,  302,  370,  370,  370,  370,  370,  370,  309,
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
  "JOIN",          "INNER",         "CROSS",         "LEFT",        
  "OUTER",         "RIGHT",         "FULL",          "ON",          
  "INSERT",        "INTO",          "VALUES",        "BRACKET_OPEN",
  "BRACKET_CLOSE",  "UPDATE",        "SET",           "DELETE",      
  "WHERE",         "ORDER",         "BY",            "ASC",         
  "DESC",          "INTEGER",       "GROUP",         "HAVING",      
  "LIMIT",         "OFFSET",        "NULL",          "STRING",      
  "DOUBLE",        "NPLACEHOLDER",  "SPLACEHOLDER",  "error",       
  "program",       "query_language",  "select_statement",  "insert_statement",
  "update_statement",  "delete_statement",  "select_clause",  "where_clause",
  "order_clause",  "group_clause",  "having_clause",  "select_limit_clause",
  "column_list",   "associated_name_list",  "join_list",     "column_item", 
  "expr",          "associated_name",  "join_item",     "join_clause", 
  "join_type",     "qualified_name",  "join_associated_name",  "join_conditions",
  "values_list",   "field_list",    "value_list",    "value_item",  
  "field_item",    "update_clause",  "limit_clause",  "update_item_list",
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
 /* 111 */ "expr ::= expr EQUALS expr",
 /* 112 */ "expr ::= expr NOTEQUALS expr",
 /* 113 */ "expr ::= expr LESS expr",
 /* 114 */ "expr ::= expr GREATER expr",
 /* 115 */ "expr ::= expr GREATEREQUAL expr",
 /* 116 */ "expr ::= expr LESSEQUAL expr",
 /* 117 */ "expr ::= expr LIKE expr",
 /* 118 */ "expr ::= expr NOT LIKE expr",
 /* 119 */ "expr ::= expr IN BRACKET_OPEN argument_list BRACKET_CLOSE",
 /* 120 */ "expr ::= expr NOT IN BRACKET_OPEN argument_list BRACKET_CLOSE",
 /* 121 */ "expr ::= function_call",
 /* 122 */ "function_call ::= IDENTIFIER BRACKET_OPEN argument_list BRACKET_CLOSE",
 /* 123 */ "function_call ::= IDENTIFIER BRACKET_OPEN BRACKET_CLOSE",
 /* 124 */ "argument_list ::= argument_list COMMA argument_item",
 /* 125 */ "argument_list ::= argument_item",
 /* 126 */ "argument_item ::= TIMES",
 /* 127 */ "argument_item ::= expr",
 /* 128 */ "expr ::= expr IS NULL",
 /* 129 */ "expr ::= expr IS NOT NULL",
 /* 130 */ "expr ::= NOT expr",
 /* 131 */ "expr ::= BRACKET_OPEN expr BRACKET_CLOSE",
 /* 132 */ "expr ::= qualified_name",
 /* 133 */ "expr ::= INTEGER",
 /* 134 */ "expr ::= STRING",
 /* 135 */ "expr ::= DOUBLE",
 /* 136 */ "expr ::= NULL",
 /* 137 */ "expr ::= NPLACEHOLDER",
 /* 138 */ "expr ::= SPLACEHOLDER",
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
// 475 "parser.lemon"
{
	if ((yypminor->yy0)) {
		efree((yypminor->yy0)->token);
		efree((yypminor->yy0));
	}
}
// 1074 "parser.c"
      break;
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
    case 78:
    case 79:
    case 81:
    case 82:
    case 84:
    case 85:
    case 86:
    case 87:
    case 88:
    case 90:
    case 91:
    case 92:
    case 94:
    case 95:
    case 96:
    case 97:
    case 98:
// 486 "parser.lemon"
{ zval_ptr_dtor(&(yypminor->yy90)); }
// 1116 "parser.c"
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
  { 56, 1 },
  { 57, 1 },
  { 57, 1 },
  { 57, 1 },
  { 57, 1 },
  { 58, 1 },
  { 58, 2 },
  { 58, 3 },
  { 58, 3 },
  { 58, 4 },
  { 58, 4 },
  { 58, 5 },
  { 58, 5 },
  { 58, 3 },
  { 58, 4 },
  { 58, 4 },
  { 58, 5 },
  { 58, 2 },
  { 58, 3 },
  { 58, 4 },
  { 58, 3 },
  { 58, 4 },
  { 58, 6 },
  { 58, 2 },
  { 58, 3 },
  { 58, 3 },
  { 58, 4 },
  { 58, 5 },
  { 58, 2 },
  { 62, 4 },
  { 62, 5 },
  { 68, 3 },
  { 68, 1 },
  { 71, 1 },
  { 71, 3 },
  { 71, 3 },
  { 71, 2 },
  { 71, 1 },
  { 69, 3 },
  { 69, 1 },
  { 70, 2 },
  { 70, 1 },
  { 74, 1 },
  { 75, 2 },
  { 75, 3 },
  { 75, 3 },
  { 75, 4 },
  { 78, 2 },
  { 78, 1 },
  { 76, 1 },
  { 76, 2 },
  { 76, 2 },
  { 76, 2 },
  { 76, 3 },
  { 76, 2 },
  { 76, 3 },
  { 76, 2 },
  { 76, 3 },
  { 79, 2 },
  { 59, 7 },
  { 59, 10 },
  { 80, 3 },
  { 80, 1 },
  { 83, 1 },
  { 81, 3 },
  { 81, 1 },
  { 84, 1 },
  { 60, 1 },
  { 60, 2 },
  { 60, 2 },
  { 60, 3 },
  { 85, 4 },
  { 87, 3 },
  { 87, 1 },
  { 88, 3 },
  { 89, 1 },
  { 61, 1 },
  { 61, 2 },
  { 61, 2 },
  { 61, 3 },
  { 90, 3 },
  { 73, 3 },
  { 73, 2 },
  { 73, 1 },
  { 63, 2 },
  { 64, 3 },
  { 91, 3 },
  { 91, 1 },
  { 92, 1 },
  { 92, 2 },
  { 92, 2 },
  { 93, 1 },
  { 93, 1 },
  { 65, 3 },
  { 94, 3 },
  { 94, 1 },
  { 95, 1 },
  { 95, 1 },
  { 66, 2 },
  { 67, 2 },
  { 67, 4 },
  { 67, 4 },
  { 86, 2 },
  { 72, 2 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 3 },
  { 72, 4 },
  { 72, 5 },
  { 72, 6 },
  { 72, 1 },
  { 97, 4 },
  { 97, 3 },
  { 96, 3 },
  { 96, 1 },
  { 98, 1 },
  { 98, 1 },
  { 72, 3 },
  { 72, 4 },
  { 72, 2 },
  { 72, 3 },
  { 72, 1 },
  { 72, 1 },
  { 72, 1 },
  { 72, 1 },
  { 72, 1 },
  { 72, 1 },
  { 72, 1 },
  { 77, 3 },
  { 77, 1 },
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
// 482 "parser.lemon"
{
	status->ret = yymsp[0].minor.yy90;
}
// 1474 "parser.c"
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
      case 121:
      case 125:
      case 127:
      case 132:
// 488 "parser.lemon"
{
	yygotominor.yy90 = yymsp[0].minor.yy90;
}
// 1501 "parser.c"
        break;
      case 5:
// 506 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_select_statement(yymsp[0].minor.yy90, NULL, NULL, NULL, NULL, NULL);
}
// 1508 "parser.c"
        break;
      case 6:
// 510 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_select_statement(yymsp[-1].minor.yy90, yymsp[0].minor.yy90, NULL, NULL, NULL, NULL);
}
// 1515 "parser.c"
        break;
      case 7:
// 514 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_select_statement(yymsp[-2].minor.yy90, yymsp[-1].minor.yy90, yymsp[0].minor.yy90, NULL, NULL, NULL);
}
// 1522 "parser.c"
        break;
      case 8:
// 518 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_select_statement(yymsp[-2].minor.yy90, yymsp[-1].minor.yy90, NULL, yymsp[0].minor.yy90, NULL, NULL);
}
// 1529 "parser.c"
        break;
      case 9:
// 522 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_select_statement(yymsp[-3].minor.yy90, yymsp[-2].minor.yy90, NULL, yymsp[-1].minor.yy90, yymsp[0].minor.yy90, NULL);
}
// 1536 "parser.c"
        break;
      case 10:
// 526 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_select_statement(yymsp[-3].minor.yy90, yymsp[-2].minor.yy90, yymsp[0].minor.yy90, yymsp[-1].minor.yy90, NULL, NULL);
}
// 1543 "parser.c"
        break;
      case 11:
// 530 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_select_statement(yymsp[-4].minor.yy90, yymsp[-3].minor.yy90, yymsp[-1].minor.yy90, yymsp[-2].minor.yy90, NULL, yymsp[0].minor.yy90);
}
// 1550 "parser.c"
        break;
      case 12:
// 534 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_select_statement(yymsp[-4].minor.yy90, yymsp[-3].minor.yy90, yymsp[0].minor.yy90, yymsp[-2].minor.yy90, yymsp[-1].minor.yy90, NULL);
}
// 1557 "parser.c"
        break;
      case 13:
// 538 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_select_statement(yymsp[-2].minor.yy90, yymsp[-1].minor.yy90, NULL, NULL, NULL, yymsp[0].minor.yy90);
}
// 1564 "parser.c"
        break;
      case 14:
// 542 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_select_statement(yymsp[-3].minor.yy90, yymsp[-2].minor.yy90, yymsp[-1].minor.yy90, NULL, NULL, yymsp[0].minor.yy90);
}
// 1571 "parser.c"
        break;
      case 15:
// 546 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_select_statement(yymsp[-3].minor.yy90, yymsp[-2].minor.yy90, NULL, yymsp[-1].minor.yy90, NULL, yymsp[0].minor.yy90);
}
// 1578 "parser.c"
        break;
      case 16:
// 550 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_select_statement(yymsp[-4].minor.yy90, yymsp[-3].minor.yy90, NULL, yymsp[-2].minor.yy90, yymsp[-1].minor.yy90, yymsp[0].minor.yy90);
}
// 1585 "parser.c"
        break;
      case 17:
// 554 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_select_statement(yymsp[-1].minor.yy90, NULL, yymsp[0].minor.yy90, NULL, NULL, NULL);
}
// 1592 "parser.c"
        break;
      case 18:
// 558 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_select_statement(yymsp[-2].minor.yy90, NULL, yymsp[0].minor.yy90, yymsp[-1].minor.yy90, NULL, NULL);
}
// 1599 "parser.c"
        break;
      case 19:
// 562 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_select_statement(yymsp[-3].minor.yy90, NULL, yymsp[0].minor.yy90, yymsp[-2].minor.yy90, yymsp[-1].minor.yy90, NULL);
}
// 1606 "parser.c"
        break;
      case 20:
// 566 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_select_statement(yymsp[-2].minor.yy90, NULL, yymsp[-1].minor.yy90, NULL, NULL, yymsp[0].minor.yy90);
}
// 1613 "parser.c"
        break;
      case 21:
// 570 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_select_statement(yymsp[-3].minor.yy90, NULL, yymsp[-1].minor.yy90, yymsp[-2].minor.yy90, NULL, yymsp[0].minor.yy90);
}
// 1620 "parser.c"
        break;
      case 22:
// 574 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_select_statement(yymsp[-5].minor.yy90, yymsp[-4].minor.yy90, yymsp[-1].minor.yy90, yymsp[-3].minor.yy90, yymsp[-2].minor.yy90, yymsp[0].minor.yy90);
}
// 1627 "parser.c"
        break;
      case 23:
// 578 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_select_statement(yymsp[-1].minor.yy90, NULL, NULL, yymsp[0].minor.yy90, NULL, NULL);
}
// 1634 "parser.c"
        break;
      case 24:
// 582 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_select_statement(yymsp[-2].minor.yy90, NULL, NULL, yymsp[-1].minor.yy90, NULL, yymsp[0].minor.yy90);
}
// 1641 "parser.c"
        break;
      case 25:
// 586 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_select_statement(yymsp[-2].minor.yy90, NULL, NULL, yymsp[-1].minor.yy90, yymsp[0].minor.yy90, NULL);
}
// 1648 "parser.c"
        break;
      case 26:
// 590 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_select_statement(yymsp[-3].minor.yy90, NULL, NULL, yymsp[-2].minor.yy90, yymsp[-1].minor.yy90, yymsp[0].minor.yy90);
}
// 1655 "parser.c"
        break;
      case 27:
// 594 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_select_statement(yymsp[-4].minor.yy90, NULL, yymsp[-1].minor.yy90, yymsp[-3].minor.yy90, yymsp[-2].minor.yy90, yymsp[0].minor.yy90);
}
// 1662 "parser.c"
        break;
      case 28:
// 598 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_select_statement(yymsp[-1].minor.yy90, NULL, NULL, NULL, NULL, yymsp[0].minor.yy90);
}
// 1669 "parser.c"
        break;
      case 29:
// 604 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_select_clause(yymsp[-2].minor.yy90, yymsp[0].minor.yy90, NULL);
  yy_destructor(18,&yymsp[-3].minor);
  yy_destructor(19,&yymsp[-1].minor);
}
// 1678 "parser.c"
        break;
      case 30:
// 608 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_select_clause(yymsp[-3].minor.yy90, yymsp[-1].minor.yy90, yymsp[0].minor.yy90);
  yy_destructor(18,&yymsp[-4].minor);
  yy_destructor(19,&yymsp[-2].minor);
}
// 1687 "parser.c"
        break;
      case 31:
      case 38:
      case 61:
      case 64:
      case 72:
      case 86:
      case 94:
      case 124:
// 614 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_zval_list(yymsp[-2].minor.yy90, yymsp[0].minor.yy90);
  yy_destructor(20,&yymsp[-1].minor);
}
// 1702 "parser.c"
        break;
      case 33:
      case 126:
// 624 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_column_item(PHQL_T_ALL, NULL, NULL, NULL);
  yy_destructor(11,&yymsp[0].minor);
}
// 1711 "parser.c"
        break;
      case 34:
// 628 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_column_item(PHQL_T_DOMAINALL, NULL, yymsp[-2].minor.yy0, NULL);
  yy_destructor(22,&yymsp[-1].minor);
  yy_destructor(11,&yymsp[0].minor);
}
// 1720 "parser.c"
        break;
      case 35:
// 632 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-2].minor.yy90, NULL, yymsp[0].minor.yy0);
  yy_destructor(23,&yymsp[-1].minor);
}
// 1728 "parser.c"
        break;
      case 36:
// 636 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_column_item(PHQL_T_EXPR, yymsp[-1].minor.yy90, NULL, yymsp[0].minor.yy0);
}
// 1735 "parser.c"
        break;
      case 37:
// 640 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_column_item(PHQL_T_EXPR, yymsp[0].minor.yy90, NULL, NULL);
}
// 1742 "parser.c"
        break;
      case 40:
// 656 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_zval_list(yymsp[-1].minor.yy90, yymsp[0].minor.yy90);
}
// 1749 "parser.c"
        break;
      case 43:
// 673 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_join_item(yymsp[-1].minor.yy90, yymsp[0].minor.yy90, NULL, NULL);
}
// 1756 "parser.c"
        break;
      case 44:
// 678 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_join_item(yymsp[-2].minor.yy90, yymsp[-1].minor.yy90, yymsp[0].minor.yy90, NULL);
}
// 1763 "parser.c"
        break;
      case 45:
// 683 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_join_item(yymsp[-2].minor.yy90, yymsp[-1].minor.yy90, NULL, yymsp[0].minor.yy90);
}
// 1770 "parser.c"
        break;
      case 46:
// 688 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_join_item(yymsp[-3].minor.yy90, yymsp[-2].minor.yy90, yymsp[-1].minor.yy90, yymsp[0].minor.yy90);
}
// 1777 "parser.c"
        break;
      case 47:
// 694 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_qualified_name(yymsp[0].minor.yy0, NULL);
  yy_destructor(23,&yymsp[-1].minor);
}
// 1785 "parser.c"
        break;
      case 48:
      case 66:
      case 140:
// 698 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_qualified_name(yymsp[0].minor.yy0, NULL);
}
// 1794 "parser.c"
        break;
      case 49:
// 704 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_join_type(PHQL_T_INNERJOIN);
  yy_destructor(24,&yymsp[0].minor);
}
// 1802 "parser.c"
        break;
      case 50:
// 708 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_join_type(PHQL_T_INNERJOIN);
  yy_destructor(25,&yymsp[-1].minor);
  yy_destructor(24,&yymsp[0].minor);
}
// 1811 "parser.c"
        break;
      case 51:
// 712 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_join_type(PHQL_T_CROSSJOIN);
  yy_destructor(26,&yymsp[-1].minor);
  yy_destructor(24,&yymsp[0].minor);
}
// 1820 "parser.c"
        break;
      case 52:
// 716 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  yy_destructor(27,&yymsp[-1].minor);
  yy_destructor(24,&yymsp[0].minor);
}
// 1829 "parser.c"
        break;
      case 53:
// 720 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_join_type(PHQL_T_LEFTJOIN);
  yy_destructor(27,&yymsp[-2].minor);
  yy_destructor(28,&yymsp[-1].minor);
  yy_destructor(24,&yymsp[0].minor);
}
// 1839 "parser.c"
        break;
      case 54:
// 724 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  yy_destructor(29,&yymsp[-1].minor);
  yy_destructor(24,&yymsp[0].minor);
}
// 1848 "parser.c"
        break;
      case 55:
// 728 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_join_type(PHQL_T_RIGHTJOIN);
  yy_destructor(29,&yymsp[-2].minor);
  yy_destructor(28,&yymsp[-1].minor);
  yy_destructor(24,&yymsp[0].minor);
}
// 1858 "parser.c"
        break;
      case 56:
// 732 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_join_type(PHQL_T_FULLJOIN);
  yy_destructor(30,&yymsp[-1].minor);
  yy_destructor(24,&yymsp[0].minor);
}
// 1867 "parser.c"
        break;
      case 57:
// 736 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_join_type(PHQL_T_FULLJOIN);
  yy_destructor(30,&yymsp[-2].minor);
  yy_destructor(28,&yymsp[-1].minor);
  yy_destructor(24,&yymsp[0].minor);
}
// 1877 "parser.c"
        break;
      case 58:
// 742 "parser.lemon"
{
	yygotominor.yy90 = yymsp[0].minor.yy90;
  yy_destructor(31,&yymsp[-1].minor);
}
// 1885 "parser.c"
        break;
      case 59:
// 749 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_insert_statement(yymsp[-4].minor.yy90, NULL, yymsp[-1].minor.yy90);
  yy_destructor(32,&yymsp[-6].minor);
  yy_destructor(33,&yymsp[-5].minor);
  yy_destructor(34,&yymsp[-3].minor);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
// 1897 "parser.c"
        break;
      case 60:
// 753 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_insert_statement(yymsp[-7].minor.yy90, yymsp[-5].minor.yy90, yymsp[-1].minor.yy90);
  yy_destructor(32,&yymsp[-9].minor);
  yy_destructor(33,&yymsp[-8].minor);
  yy_destructor(35,&yymsp[-6].minor);
  yy_destructor(36,&yymsp[-4].minor);
  yy_destructor(34,&yymsp[-3].minor);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
// 1911 "parser.c"
        break;
      case 67:
// 791 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_update_statement(yymsp[0].minor.yy90, NULL, NULL);
}
// 1918 "parser.c"
        break;
      case 68:
// 795 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_update_statement(yymsp[-1].minor.yy90, yymsp[0].minor.yy90, NULL);
}
// 1925 "parser.c"
        break;
      case 69:
// 799 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_update_statement(yymsp[-1].minor.yy90, NULL, yymsp[0].minor.yy90);
}
// 1932 "parser.c"
        break;
      case 70:
// 803 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_update_statement(yymsp[-2].minor.yy90, yymsp[-1].minor.yy90, yymsp[0].minor.yy90);
}
// 1939 "parser.c"
        break;
      case 71:
// 809 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_update_clause(yymsp[-2].minor.yy90, yymsp[0].minor.yy90);
  yy_destructor(37,&yymsp[-3].minor);
  yy_destructor(38,&yymsp[-1].minor);
}
// 1948 "parser.c"
        break;
      case 74:
// 825 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_update_item(yymsp[-2].minor.yy90, yymsp[0].minor.yy90);
  yy_destructor(1,&yymsp[-1].minor);
}
// 1956 "parser.c"
        break;
      case 76:
// 837 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_delete_statement(yymsp[0].minor.yy90, NULL, NULL);
}
// 1963 "parser.c"
        break;
      case 77:
// 841 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_delete_statement(yymsp[-1].minor.yy90, yymsp[0].minor.yy90, NULL);
}
// 1970 "parser.c"
        break;
      case 78:
// 845 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_delete_statement(yymsp[-1].minor.yy90, NULL, yymsp[0].minor.yy90);
}
// 1977 "parser.c"
        break;
      case 79:
// 849 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_delete_statement(yymsp[-2].minor.yy90, yymsp[-1].minor.yy90, yymsp[0].minor.yy90);
}
// 1984 "parser.c"
        break;
      case 80:
// 855 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_delete_clause(yymsp[0].minor.yy90);
  yy_destructor(39,&yymsp[-2].minor);
  yy_destructor(19,&yymsp[-1].minor);
}
// 1993 "parser.c"
        break;
      case 81:
// 861 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_assoc_name(yymsp[-2].minor.yy90, yymsp[0].minor.yy0);
  yy_destructor(23,&yymsp[-1].minor);
}
// 2001 "parser.c"
        break;
      case 82:
// 865 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_assoc_name(yymsp[-1].minor.yy90, yymsp[0].minor.yy0);
}
// 2008 "parser.c"
        break;
      case 83:
// 869 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_assoc_name(yymsp[0].minor.yy90, NULL);
}
// 2015 "parser.c"
        break;
      case 84:
// 875 "parser.lemon"
{
	yygotominor.yy90 = yymsp[0].minor.yy90;
  yy_destructor(40,&yymsp[-1].minor);
}
// 2023 "parser.c"
        break;
      case 85:
// 881 "parser.lemon"
{
	yygotominor.yy90 = yymsp[0].minor.yy90;
  yy_destructor(41,&yymsp[-2].minor);
  yy_destructor(42,&yymsp[-1].minor);
}
// 2032 "parser.c"
        break;
      case 88:
// 897 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_order_item(yymsp[0].minor.yy90, 0);
}
// 2039 "parser.c"
        break;
      case 89:
// 901 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_order_item(yymsp[-1].minor.yy90, PHQL_T_ASC);
  yy_destructor(43,&yymsp[0].minor);
}
// 2047 "parser.c"
        break;
      case 90:
// 905 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_order_item(yymsp[-1].minor.yy90, PHQL_T_DESC);
  yy_destructor(44,&yymsp[0].minor);
}
// 2055 "parser.c"
        break;
      case 92:
      case 97:
      case 133:
// 913 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_literal_zval(PHQL_T_INTEGER, yymsp[0].minor.yy0);
}
// 2064 "parser.c"
        break;
      case 93:
// 919 "parser.lemon"
{
	yygotominor.yy90 = yymsp[0].minor.yy90;
  yy_destructor(46,&yymsp[-2].minor);
  yy_destructor(42,&yymsp[-1].minor);
}
// 2073 "parser.c"
        break;
      case 98:
// 945 "parser.lemon"
{
	yygotominor.yy90 = yymsp[0].minor.yy90;
  yy_destructor(47,&yymsp[-1].minor);
}
// 2081 "parser.c"
        break;
      case 99:
// 951 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_select_limit_clause(yymsp[0].minor.yy0, NULL);
  yy_destructor(48,&yymsp[-1].minor);
}
// 2089 "parser.c"
        break;
      case 100:
// 955 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_select_limit_clause(yymsp[0].minor.yy0, yymsp[-2].minor.yy0);
  yy_destructor(48,&yymsp[-3].minor);
  yy_destructor(20,&yymsp[-1].minor);
}
// 2098 "parser.c"
        break;
      case 101:
// 959 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_select_limit_clause(yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(48,&yymsp[-3].minor);
  yy_destructor(49,&yymsp[-1].minor);
}
// 2107 "parser.c"
        break;
      case 102:
// 965 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_literal_zval(PHQL_T_INTEGER, yymsp[0].minor.yy0);
  yy_destructor(48,&yymsp[-1].minor);
}
// 2115 "parser.c"
        break;
      case 103:
// 971 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_expr(PHQL_T_MINUS, NULL, yymsp[0].minor.yy90);
  yy_destructor(14,&yymsp[-1].minor);
}
// 2123 "parser.c"
        break;
      case 104:
// 975 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_expr(PHQL_T_SUB, yymsp[-2].minor.yy90, yymsp[0].minor.yy90);
  yy_destructor(14,&yymsp[-1].minor);
}
// 2131 "parser.c"
        break;
      case 105:
// 979 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_expr(PHQL_T_ADD, yymsp[-2].minor.yy90, yymsp[0].minor.yy90);
  yy_destructor(13,&yymsp[-1].minor);
}
// 2139 "parser.c"
        break;
      case 106:
// 983 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_expr(PHQL_T_MUL, yymsp[-2].minor.yy90, yymsp[0].minor.yy90);
  yy_destructor(11,&yymsp[-1].minor);
}
// 2147 "parser.c"
        break;
      case 107:
// 987 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_expr(PHQL_T_DIV, yymsp[-2].minor.yy90, yymsp[0].minor.yy90);
  yy_destructor(10,&yymsp[-1].minor);
}
// 2155 "parser.c"
        break;
      case 108:
// 991 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_expr(PHQL_T_MOD, yymsp[-2].minor.yy90, yymsp[0].minor.yy90);
  yy_destructor(12,&yymsp[-1].minor);
}
// 2163 "parser.c"
        break;
      case 109:
// 995 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_expr(PHQL_T_AND, yymsp[-2].minor.yy90, yymsp[0].minor.yy90);
  yy_destructor(7,&yymsp[-1].minor);
}
// 2171 "parser.c"
        break;
      case 110:
// 999 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_expr(PHQL_T_OR, yymsp[-2].minor.yy90, yymsp[0].minor.yy90);
  yy_destructor(8,&yymsp[-1].minor);
}
// 2179 "parser.c"
        break;
      case 111:
// 1003 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_expr(PHQL_T_EQUALS, yymsp[-2].minor.yy90, yymsp[0].minor.yy90);
  yy_destructor(1,&yymsp[-1].minor);
}
// 2187 "parser.c"
        break;
      case 112:
// 1007 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_expr(PHQL_T_NOTEQUALS, yymsp[-2].minor.yy90, yymsp[0].minor.yy90);
  yy_destructor(2,&yymsp[-1].minor);
}
// 2195 "parser.c"
        break;
      case 113:
// 1011 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_expr(PHQL_T_LESS, yymsp[-2].minor.yy90, yymsp[0].minor.yy90);
  yy_destructor(3,&yymsp[-1].minor);
}
// 2203 "parser.c"
        break;
      case 114:
// 1015 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_expr(PHQL_T_GREATER, yymsp[-2].minor.yy90, yymsp[0].minor.yy90);
  yy_destructor(4,&yymsp[-1].minor);
}
// 2211 "parser.c"
        break;
      case 115:
// 1019 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_expr(PHQL_T_GREATEREQUAL, yymsp[-2].minor.yy90, yymsp[0].minor.yy90);
  yy_destructor(5,&yymsp[-1].minor);
}
// 2219 "parser.c"
        break;
      case 116:
// 1023 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_expr(PHQL_T_LESSEQUAL, yymsp[-2].minor.yy90, yymsp[0].minor.yy90);
  yy_destructor(6,&yymsp[-1].minor);
}
// 2227 "parser.c"
        break;
      case 117:
// 1027 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_expr(PHQL_T_LIKE, yymsp[-2].minor.yy90, yymsp[0].minor.yy90);
  yy_destructor(9,&yymsp[-1].minor);
}
// 2235 "parser.c"
        break;
      case 118:
// 1031 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_expr(PHQL_T_NLIKE, yymsp[-3].minor.yy90, yymsp[0].minor.yy90);
  yy_destructor(17,&yymsp[-2].minor);
  yy_destructor(9,&yymsp[-1].minor);
}
// 2244 "parser.c"
        break;
      case 119:
// 1035 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_expr(PHQL_T_IN, yymsp[-4].minor.yy90, yymsp[-1].minor.yy90);
  yy_destructor(16,&yymsp[-3].minor);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
// 2254 "parser.c"
        break;
      case 120:
// 1039 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_expr(PHQL_T_NOTIN, yymsp[-5].minor.yy90, yymsp[-1].minor.yy90);
  yy_destructor(17,&yymsp[-4].minor);
  yy_destructor(16,&yymsp[-3].minor);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
// 2265 "parser.c"
        break;
      case 122:
// 1049 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_func_call(yymsp[-3].minor.yy0, yymsp[-1].minor.yy90);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
// 2274 "parser.c"
        break;
      case 123:
// 1053 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_func_call(yymsp[-2].minor.yy0, NULL);
  yy_destructor(35,&yymsp[-1].minor);
  yy_destructor(36,&yymsp[0].minor);
}
// 2283 "parser.c"
        break;
      case 128:
// 1077 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_expr(PHQL_T_ISNULL, yymsp[-2].minor.yy90, NULL);
  yy_destructor(15,&yymsp[-1].minor);
  yy_destructor(50,&yymsp[0].minor);
}
// 2292 "parser.c"
        break;
      case 129:
// 1081 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_expr(PHQL_T_ISNOTNULL, yymsp[-3].minor.yy90, NULL);
  yy_destructor(15,&yymsp[-2].minor);
  yy_destructor(17,&yymsp[-1].minor);
  yy_destructor(50,&yymsp[0].minor);
}
// 2302 "parser.c"
        break;
      case 130:
// 1085 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_expr(PHQL_T_NOT, NULL, yymsp[0].minor.yy90);
  yy_destructor(17,&yymsp[-1].minor);
}
// 2310 "parser.c"
        break;
      case 131:
// 1089 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_expr(PHQL_T_ENCLOSED, yymsp[-1].minor.yy90, NULL);
  yy_destructor(35,&yymsp[-2].minor);
  yy_destructor(36,&yymsp[0].minor);
}
// 2319 "parser.c"
        break;
      case 134:
// 1101 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_literal_zval(PHQL_T_STRING, yymsp[0].minor.yy0);
}
// 2326 "parser.c"
        break;
      case 135:
// 1105 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_literal_zval(PHQL_T_DOUBLE, yymsp[0].minor.yy0);
}
// 2333 "parser.c"
        break;
      case 136:
// 1109 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_literal_zval(PHQL_T_NULL, NULL);
  yy_destructor(50,&yymsp[0].minor);
}
// 2341 "parser.c"
        break;
      case 137:
// 1113 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_placeholder_zval(PHQL_T_NPLACEHOLDER, yymsp[0].minor.yy0);
}
// 2348 "parser.c"
        break;
      case 138:
// 1117 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_placeholder_zval(PHQL_T_SPLACEHOLDER, yymsp[0].minor.yy0);
}
// 2355 "parser.c"
        break;
      case 139:
// 1123 "parser.lemon"
{
	yygotominor.yy90 = phql_ret_qualified_name(yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(22,&yymsp[-1].minor);
}
// 2363 "parser.c"
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
// 425 "parser.lemon"

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

// 2455 "parser.c"
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
  { PHQL_T_OFFSET,        "OFFSET" },
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

/**
 * Executes the internal PHQL parser/tokenizer
 */
int phql_parse_phql(zval *result, zval *phql TSRMLS_DC){

	zval *error_msg = NULL;

	ZVAL_NULL(result);

	if(phql_internal_parse_phql(&result, Z_STRVAL_P(phql), &error_msg TSRMLS_CC) == FAILURE){
		phalcon_throw_exception_string(phalcon_mvc_model_exception_ce, Z_STRVAL_P(error_msg), Z_STRLEN_P(error_msg) TSRMLS_CC);
		return FAILURE;
	}

	return SUCCESS;
}

/**
 * Executes a PHQL parser/tokenizer
 */
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
	parser_status->syntax_error = NULL;

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
			default:
				parser_status->status = PHQL_PARSING_FAILED;
				error = emalloc(sizeof(char)*32);
				sprintf(error, "scanner: unknown opcode %c", token->opcode);
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

	state->active_token = 0;
	state->start = NULL;

	if (status != FAILURE) {
		switch (scanner_status) {
			case PHQL_SCANNER_RETCODE_ERR:
			case PHQL_SCANNER_RETCODE_IMPOSSIBLE:
				if (!*error_msg) {
					PHALCON_INIT_VAR(*error_msg);
					if (state->start) {
						error = emalloc(sizeof(char)*(48+strlen(state->start)));
						sprintf(error, "Parsing error near to %s (%d)", state->start, status);
						ZVAL_STRING(*error_msg, error, 1);
						efree(error);
					} else {
						ZVAL_STRING(*error_msg, "Parsing error near to EOF", 1);
					}
				}
				status = FAILURE;
				break;
			default:
				phql_(phql_parser, 0, NULL, parser_status);
		}
	}

	if (parser_status->status != PHQL_PARSING_OK) {
		status = FAILURE;
		if (parser_status->syntax_error) {
			if (!*error_msg) {
				PHALCON_ALLOC_ZVAL_MM(*error_msg);
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
	efree(token);

	return status;
}