
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

#ifndef PHALCON_KERNEL_DEBUG_H
#define PHALCON_KERNEL_DEBUG_H

#include "php_phalcon.h"

#include <stdio.h>

#ifndef PHALCON_RELEASE

#define PHV(v) phalcon_vdump(v)
#define PHPR(v) phalcon_print_r(v)

typedef struct _phalcon_debug_entry {
	struct _phalcon_debug_entry *prev;
	struct _phalcon_debug_entry *next;
	char *class_name;
	char *method_name;
	int lineno;
} phalcon_debug_entry;

int phalcon_start_debug();
int phalcon_stop_debug();

int phalcon_print_r(zval *userval TSRMLS_DC);
int phalcon_vdump(zval *uservar TSRMLS_DC);
int phalcon_debug_assign(char *name, zval *value TSRMLS_DC);
int phalcon_vpdump(const zval **uservar TSRMLS_DC);
int phalcon_dump_ce(zend_class_entry *ce TSRMLS_DC);
int phalcon_class_debug(zval *val TSRMLS_DC);

int phalcon_debug_backtrace_internal();
int phalcon_debug_str(char *what, char *message);
int phalcon_debug_long(char *what, uint vlong);
int phalcon_debug_screen(char *message);

int phalcon_step_over(char *message);
int phalcon_step_into(char *message);
int phalcon_step_out(char *message);

int phalcon_step_into_entry(char *class_name, char *method_name, int lineno);
int phalcon_step_out_entry();

int phalcon_debug_method_call(zval *obj, char *method_name TSRMLS_DC);
int phalcon_debug_vdump(char *preffix, zval *value TSRMLS_DC);
int phalcon_debug_param(zval *param TSRMLS_DC);

int phalcon_error_space();
int phalcon_debug_space();

extern FILE *phalcon_log;
extern int phalcon_debug_trace;
extern phalcon_debug_entry *start;
extern phalcon_debug_entry *active;

#endif

#endif /* PHALCON_KERNEL_DEBUG_H */
