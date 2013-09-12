
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Zephir Team (http://www.zephir-lang.com)       |
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

#ifndef ZEPHIR_RELEASE

#define PHV(v) zephir_vdump(v)
#define PHPR(v) zephir_print_r(v)

typedef struct _zephir_debug_entry {
	struct _zephir_debug_entry *prev;
	struct _zephir_debug_entry *next;
	char *class_name;
	char *method_name;
	int lineno;
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

int zephir_error_space();
int zephir_debug_space();

#endif
