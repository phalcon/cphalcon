
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2016 Zephir Team (http://www.zephir-lang.com)       |
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

#ifndef ZEPHIR_KERNEL_DEBUG_H
#define ZEPHIR_KERNEL_DEBUG_H

#ifndef ZEPHIR_RELEASE

#include <php.h>

void zephir_vdump(zval *var, const char *func);

#define PHV(v) zephir_vdump(zval *var, const char *func)
#define PHPR(v) zephir_print_r(v)

typedef struct _zephir_debug_entry {
	struct _zephir_debug_entry *prev;
	struct _zephir_debug_entry *next;
	char *class_name;
	char *method_name;
	int lineno;
} zephir_debug_entry;

#endif
#endif
