
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
<<<<<<< HEAD
  | Copyright (c) 2011-2015 Zephir Team (http://www.zephir-lang.com)       |
=======
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
>>>>>>> master
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@zephir-lang.com so we can send you a copy immediately.      |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@zephir-lang.com>                     |
  |          Eduar Carvajal <eduar@zephir-lang.com>                        |
  +------------------------------------------------------------------------+
*/

<<<<<<< HEAD
#ifndef ZEPHIR_KERNEL_DEBUG_H
#define ZEPHIR_KERNEL_DEBUG_H
=======
#ifndef PHALCON_KERNEL_DEBUG_H
#define PHALCON_KERNEL_DEBUG_H

#include "php_phalcon.h"

#include <stdio.h>

#ifndef PHALCON_RELEASE
>>>>>>> master

#ifndef ZEPHIR_RELEASE

#include <php.h>

#define PHV(v) zephir_vdump(v)
#define PHPR(v) zephir_print_r(v)

typedef struct _zephir_debug_entry {
	struct _zephir_debug_entry *prev;
	struct _zephir_debug_entry *next;
	char *class_name;
	char *method_name;
	int lineno;
<<<<<<< HEAD
} zephir_debug_entry;

int zephir_start_debug();
int zephir_stop_debug();

int zephir_print_r(zval *userval TSRMLS_DC);
int zephir_vdump(zval *uservar TSRMLS_DC);
int zephir_debug_assign(char *name, zval *value TSRMLS_DC);
int zephir_vpdump(const zval **uservar TSRMLS_DC);
int zephir_dump_ce(zend_class_entry *ce TSRMLS_DC);
int zephir_class_debug(zval *val TSRMLS_DC);

int zephir_debug_backtrace_internal();
int zephir_debug_str(char *what, char *message);
int zephir_debug_long(char *what, uint vlong);
int zephir_debug_screen(char *message);

int zephir_step_over(char *message);
int zephir_step_into(char *message);
int zephir_step_out(char *message);

int zephir_step_into_entry(char *class_name, char *method_name, int lineno);
int zephir_step_out_entry();

int zephir_debug_method_call(zval *obj, char *method_name TSRMLS_DC);
int zephir_debug_vdump(char *preffix, zval *value TSRMLS_DC);
int zephir_debug_param(zval *param TSRMLS_DC);
=======
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
>>>>>>> master

int zephir_error_space();
int zephir_debug_space();

#endif
<<<<<<< HEAD
#endif
=======

#endif /* PHALCON_KERNEL_DEBUG_H */
>>>>>>> master
