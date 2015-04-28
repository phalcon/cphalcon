
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

#ifndef PHALCON_MVC_VIEW_ENGINE_VOLT_SCANNER_H
#define PHALCON_MVC_VIEW_ENGINE_VOLT_SCANNER_H

#include "php_phalcon.h"

#define PHVOLT_RAW_BUFFER_SIZE 256

#define PHVOLT_SCANNER_RETCODE_EOF -1
#define PHVOLT_SCANNER_RETCODE_ERR -2
#define PHVOLT_SCANNER_RETCODE_IMPOSSIBLE -3

/** Modes */
#define PHVOLT_MODE_RAW 0
#define PHVOLT_MODE_CODE 1
#define PHVOLT_MODE_COMMENT 2

#define PHVOLT_T_IGNORE 257

/* Literals & Identifiers */
#define PHVOLT_T_INTEGER 258
#define PHVOLT_T_DOUBLE 259
#define PHVOLT_T_STRING 260
#define PHVOLT_T_NULL 261
#define PHVOLT_T_FALSE 262
#define PHVOLT_T_TRUE 263
#define PHVOLT_T_IDENTIFIER 265

/* Operators */
#define PHVOLT_T_ADD '+'
#define PHVOLT_T_SUB '-'
#define PHVOLT_T_MUL '*'
#define PHVOLT_T_DIV '/'
#define PHVOLT_T_MOD '%'
#define PHVOLT_T_AND 266
#define PHVOLT_T_OR 267
#define PHVOLT_T_CONCAT '~'
#define PHVOLT_T_PIPE '|'

#define PHVOLT_T_DOT '.'
#define PHVOLT_T_COMMA 269

#define PHVOLT_T_NOT '!'
#define PHVOLT_T_LESS '<'
#define PHVOLT_T_LESSEQUAL 270
#define PHVOLT_T_GREATER '>'
#define PHVOLT_T_GREATEREQUAL 271
#define PHVOLT_T_EQUALS 272
#define PHVOLT_T_NOTEQUALS 273
#define PHVOLT_T_IDENTICAL 274
#define PHVOLT_T_NOTIDENTICAL 275
#define PHVOLT_T_RANGE 276
#define PHVOLT_T_ASSIGN '='
#define PHVOLT_T_COLON 277
#define PHVOLT_T_QUESTION '?'
#define PHVOLT_T_POW 278
#define PHVOLT_T_INCR 279
#define PHVOLT_T_DECR 280
#define PHVOLT_T_ADD_ASSIGN 281
#define PHVOLT_T_SUB_ASSIGN 282
#define PHVOLT_T_MUL_ASSIGN 283
#define PHVOLT_T_DIV_ASSIGN 284

#define PHVOLT_T_PARENTHESES_OPEN '('
#define PHVOLT_T_PARENTHESES_CLOSE ')'
#define PHVOLT_T_SBRACKET_OPEN '['
#define PHVOLT_T_SBRACKET_CLOSE ']'
#define PHVOLT_T_CBRACKET_OPEN '{'
#define PHVOLT_T_CBRACKET_CLOSE '}'

/** Reserved words */
#define PHVOLT_T_IF 300
#define PHVOLT_T_ELSE 301
#define PHVOLT_T_ELSEIF 302
#define PHVOLT_T_ENDIF 303
#define PHVOLT_T_FOR 304
#define PHVOLT_T_ENDFOR 305
#define PHVOLT_T_SET 306
#define PHVOLT_T_BLOCK 307
#define PHVOLT_T_ENDBLOCK 308
#define PHVOLT_T_IN 309
#define PHVOLT_T_EXTENDS 310
#define PHVOLT_T_IS 311
#define PHVOLT_T_DEFINED 312
#define PHVOLT_T_INCLUDE 313
#define PHVOLT_T_CACHE 314
#define PHVOLT_T_ENDCACHE 315
#define PHVOLT_T_DO 316
#define PHVOLT_T_AUTOESCAPE 317
#define PHVOLT_T_ENDAUTOESCAPE 318
#define PHVOLT_T_CONTINUE 319
#define PHVOLT_T_BREAK 320
#define PHVOLT_T_ELSEFOR 321
#define PHVOLT_T_MACRO 322
#define PHVOLT_T_ENDMACRO 323
#define PHVOLT_T_WITH 324
#define PHVOLT_T_CALL 325
#define PHVOLT_T_ENDCALL 326
#define PHVOLT_T_RETURN 327

/** Delimiters */
#define PHVOLT_T_OPEN_DELIMITER  330
#define PHVOLT_T_CLOSE_DELIMITER  331
#define PHVOLT_T_OPEN_EDELIMITER  332
#define PHVOLT_T_CLOSE_EDELIMITER  333

/** Special Tokens */
#define PHVOLT_T_FCALL 350
#define PHVOLT_T_EXPR 354
#define PHVOLT_T_QUALIFIED 355
#define PHVOLT_T_ENCLOSED 356
#define PHVOLT_T_RAW_FRAGMENT 357
#define PHVOLT_T_EMPTY_STATEMENT 358
#define PHVOLT_T_ECHO 359
#define PHVOLT_T_ARRAY 360
#define PHVOLT_T_ARRAYACCESS 361
#define PHVOLT_T_NOT_ISSET 362
#define PHVOLT_T_ISSET 363
#define PHVOLT_T_RESOLVED_EXPR 364
#define PHVOLT_T_SLICE 365
#define PHVOLT_T_TERNARY 366
#define PHVOLT_T_NOT_IN 367

#define PHVOLT_T_MINUS 368
#define PHVOLT_T_PLUS 369

#define PHVOLT_T_EMPTY 380
#define PHVOLT_T_EVEN 381
#define PHVOLT_T_ODD 382
#define PHVOLT_T_NUMERIC 383
#define PHVOLT_T_SCALAR 384
#define PHVOLT_T_ITERABLE 385

#define PHVOLT_T_ISEMPTY 386
#define PHVOLT_T_ISEVEN 387
#define PHVOLT_T_ISODD 388
#define PHVOLT_T_ISNUMERIC 389
#define PHVOLT_T_ISSCALAR 390
#define PHVOLT_T_ISITERABLE 391

#define PHVOLT_T_NOT_ISEMPTY 392
#define PHVOLT_T_NOT_ISEVEN 393
#define PHVOLT_T_NOT_ISODD 394
#define PHVOLT_T_NOT_ISNUMERIC 395
#define PHVOLT_T_NOT_ISSCALAR 396
#define PHVOLT_T_NOT_ISITERABLE 397

/* List of tokens and their names */
typedef struct _phvolt_token_names {
	char *name;
	int len;
	unsigned int code;
} phvolt_token_names;

/* Active token state */
typedef struct _phvolt_scanner_state {
	int active_token;
	int mode;
	char* start;
	char* end;
	unsigned int start_length;
	unsigned int active_line;
	zval *active_file;
	unsigned int statement_position;
	unsigned int extends_mode;
	unsigned int block_level;
	unsigned int macro_level;
	char *raw_buffer;
	unsigned int raw_buffer_cursor;
	unsigned int raw_buffer_size;
	unsigned int old_if_level;
	unsigned int if_level;
	unsigned int for_level;
	int whitespace_control;
} phvolt_scanner_state;

/* Extra information tokens */
typedef struct _phvolt_scanner_token {
	int opcode;
	int len;
	char *value;
} phvolt_scanner_token;

int phvolt_get_token(phvolt_scanner_state *s, phvolt_scanner_token *token);

extern const phvolt_token_names phvolt_tokens[];

#endif  /* PHALCON_MVC_VIEW_ENGINE_VOLT_SCANNER_H */

