/**
 * This file is part of the Zephir.
 *
 * (c) Phalcon Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code. If you did not receive
 * a copy of the license it is available through the world-wide-web at the
 * following url: https://docs.zephir-lang.com/en/latest/license
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
