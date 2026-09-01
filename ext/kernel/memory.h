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

#ifndef ZEPHIR_KERNEL_MEMORY_H
#define ZEPHIR_KERNEL_MEMORY_H

#include <php.h>
#include <Zend/zend.h>
#include "php_ext.h"
#include "kernel/globals.h"

/** Memory frame */
typedef struct _zephir_memory_entry {
	size_t pointer;
	size_t capacity;
	zval **addresses;
#ifndef ZEPHIR_RELEASE
	int permanent;
	const char *func;
#endif
} zephir_memory_entry;

/** Virtual Symbol Table */
typedef struct _zephir_symbol_table {
	struct _zephir_memory_entry *scope;
	zend_array *symbol_table;
	struct _zephir_symbol_table *prev;
} zephir_symbol_table;

typedef struct _zephir_method_globals {
	/* Memory */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;
} zephir_method_globals;

/* Memory Frames */
void ZEPHIR_FASTCALL zephir_memory_grow_stack(zephir_method_globals *g, const char *func);
void ZEPHIR_FASTCALL zephir_memory_restore_stack(zephir_method_globals *g, const char *func);

#define ZEPHIR_MM_RESTORE() \
	zephir_memory_restore_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__); \
	pefree(ZEPHIR_METHOD_GLOBALS_PTR, 0); \
	ZEPHIR_METHOD_GLOBALS_PTR = NULL;

void zephir_initialize_memory(zend_zephir_globals_def *zephir_globals_ptr);
void zephir_deinitialize_memory();

void ZEPHIR_FASTCALL zephir_do_memory_observe(zval *var, const zephir_method_globals *g);
#define zephir_memory_observe(var) zephir_do_memory_observe(var, ZEPHIR_METHOD_GLOBALS_PTR);

#define zephir_safe_zval_ptr_dtor(pzval)

void zephir_create_symbol_table(zephir_method_globals *g);

#define ZEPHIR_CREATE_SYMBOL_TABLE() zephir_create_symbol_table(ZEPHIR_METHOD_GLOBALS_PTR);

int zephir_set_symbol(zval *key_name, zval *value);

#define ZEPHIR_INIT_VAR(z) \
	zephir_memory_observe(z); \
	ZVAL_NULL(z);

#define ZEPHIR_INIT_NVAR(z) \
	do { \
		if (Z_TYPE_P(z) == IS_UNDEF) { \
			zephir_memory_observe(z); \
		} else if (Z_REFCOUNTED_P(z) && !Z_ISREF_P(z)) { \
			if (Z_REFCOUNT_P(z) > 1) { \
				Z_DELREF_P(z); \
			} else { \
				zval_dtor(z); \
			} \
		} \
		ZVAL_NULL(z); \
	} while (0)

#define ZEPHIR_CPY_WRT(d, v) \
	Z_TRY_ADDREF_P(v); \
	if (Z_TYPE_P(d) > IS_UNDEF) { \
		if (Z_REFCOUNTED_P(d) && Z_REFCOUNT_P(d) > 0) { \
			zval_ptr_dtor(d); \
		} \
	} else { \
		zephir_memory_observe(d); \
	} \
	ZVAL_COPY_VALUE(d, v);

#define ZEPHIR_CPY_WRT_CTOR(d, v) \
	if (d) { \
		if (Z_REFCOUNTED_P(d) && Z_REFCOUNT_P(d) > 0) { \
			zval_ptr_dtor(d); \
		} \
	} \
	ZVAL_DUP(d, v);

#define ZEPHIR_OBS_COPY_OR_DUP(z, v) \
	if (Z_TYPE_P(z) == IS_UNDEF) { \
		zephir_memory_observe(z); \
	} \
	ZVAL_COPY(z, v);

#define ZEPHIR_HASH_COPY(z, v) \
	if (Z_TYPE_P(z) == IS_ARRAY && Z_TYPE_P(v) == IS_ARRAY) { \
		zend_hash_copy(Z_ARRVAL_P(z), Z_ARRVAL_P(v), (copy_ctor_func_t) zval_add_ref); \
	}

#define ZEPHIR_OBS_NVAR(z) \
	if (Z_TYPE_P(z) != IS_UNDEF) { \
		if (Z_REFCOUNTED_P(z) && Z_REFCOUNT_P(z) > 1) { \
			Z_DELREF_P(z); \
		} else {\
			zval_ptr_dtor(z); \
			ZVAL_NULL(z); \
		} \
	} else { \
		zephir_memory_observe(z); \
	}

/* TODO: this might causes troubles, since we cannot observe here, since we aren't using double pointers
 * figure out away to fix this (if it's an issue, which it isn't if observing isn't necessary)
 */
#define ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(ppzv) \
	do { \
		zval *tmp_ = (ppzv); \
		if (tmp_ != NULL) { \
			if (Z_TYPE_P(tmp_) != IS_UNDEF) { \
				zval_ptr_dtor(tmp_); \
			} else { \
				zephir_memory_observe(tmp_); \
			} \
			ZVAL_NULL(tmp_); \
		} \
	} while (0)

#define ZEPHIR_SEPARATE_PARAM(z) \
	do { \
		zval *orig_ptr = z; \
		SEPARATE_ZVAL(orig_ptr); \
	} while (0)

#endif
