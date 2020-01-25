
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2017 Phalcon Team (http://www.zephir-lang.com)       |
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

/** The zval's reference count dump */
#define RC_DUMP(zv)                                                                                                                \
	do {                                                                                                                           \
		char *_n = (strrchr((#zv), '&') ? strrchr((#zv), '&') + 1 : (#zv));                                                        \
		char *_f = (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__);                                               \
		zval *_z = (zv);                                                                                                           \
		if (Z_REFCOUNTED_P(_z)) {                                                                                                  \
			fprintf(stderr, "[DUMP]: %s:%d %s (%p) refcount=%d, type=%d\n", _f, __LINE__, _n, _z, Z_REFCOUNT_P(_z), Z_TYPE_P(_z)); \
		} else {                                                                                                                   \
			fprintf(stderr, "[DUMP]: %s:%d %s (%p) is not reference-counted, type=%d\n", _f, __LINE__, _n, _z, Z_TYPE_P(_z));      \
		}                                                                                                                          \
	} while (0)


#else

#define RC_DUMP(zv)

#endif /* ZEPHIR_RELEASE */
#endif /* ZEPHIR_KERNEL_DEBUG_H */
