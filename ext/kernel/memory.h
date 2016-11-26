
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
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

#ifndef ZEPHIR_KERNEL_MEMORY_H
#define ZEPHIR_KERNEL_MEMORY_H

#include <php.h>
#include <Zend/zend.h>
#include "php_ext.h"
#include "kernel/globals.h"

#if defined(__x86_64__) || defined(__LP64__) || defined(_LP64) || defined(_WIN64)
	#define ZEPHIR_ENABLE_64BITS 1
#endif

#define ZEPHIR_NUM_PREALLOCATED_FRAMES 25

void zephir_initialize_memory(zend_zephir_globals_def *zephir_globals_ptr);
int zephir_cleanup_fcache(void *pDest, int num_args, va_list args, zend_hash_key *hash_key);
void zephir_deinitialize_memory();

/* Memory Frames */
#ifndef ZEPHIR_RELEASE
void ZEPHIR_FASTCALL zephir_memory_grow_stack(const char *func);
int ZEPHIR_FASTCALL zephir_memory_restore_stack(const char *func);

#define ZEPHIR_MM_GROW() zephir_memory_grow_stack(NULL)
#define ZEPHIR_MM_RESTORE() zephir_memory_restore_stack(NULL)

#else
void ZEPHIR_FASTCALL zephir_memory_grow_stack();
int ZEPHIR_FASTCALL zephir_memory_restore_stack();

#define ZEPHIR_MM_GROW() zephir_memory_grow_stack()
#define ZEPHIR_MM_RESTORE() zephir_memory_restore_stack()

#endif

#define zephir_dtor(x) zval_dtor(x)
#define zephir_ptr_dtor(x) zval_ptr_dtor(x)

void ZEPHIR_FASTCALL zephir_memory_observe(zval *var);
void ZEPHIR_FASTCALL zephir_memory_alloc(zval *var);

int ZEPHIR_FASTCALL zephir_clean_restore_stack(TSRMLS_D);

#define zephir_safe_zval_ptr_dtor(pzval)

void zephir_create_symbol_table(TSRMLS_D);
int zephir_set_symbol(zval *key_name, zval *value TSRMLS_DC);
int zephir_set_symbol_str(char *key_name, unsigned int key_length, zval *value);

#define ZEPHIR_INIT_VAR(z) zephir_memory_alloc(z);

#define ZEPHIR_SINIT_VAR(z) ZVAL_NULL(&z);

#define ZEPHIR_SINIT_NVAR(z) /*Z_SET_REFCOUNT_P(&z, 1)*/

#define ZEPHIR_INIT_ZVAL_NREF(z) \
	ZVAL_UNDEF(&z); \

#define ZEPHIR_INIT_NVAR(z) \
	if (Z_TYPE_P(z) == IS_UNDEF) { \
		zephir_memory_observe(z); \
	} else if (Z_REFCOUNTED_P(z) && !Z_ISREF_P(z)) { \
		if (Z_REFCOUNT_P(z) > 1) { \
			Z_DELREF_P(z); \
		} else { \
			zephir_dtor(z); \
		} \
	} \
	ZVAL_NULL(z); \

/* only removes the value body of the zval */
#define ZEPHIR_INIT_LNVAR(z) ZEPHIR_INIT_NVAR(&z)

#define ZEPHIR_CPY_WRT(d, v) \
	Z_TRY_ADDREF_P(v); \
	if (Z_TYPE_P(d) > IS_UNDEF) { \
		if (Z_REFCOUNTED_P(d) && Z_REFCOUNT_P(d) > 0) { \
			zephir_ptr_dtor(d); \
		} \
	} else { \
		zephir_memory_observe(d); \
	} \
	ZVAL_COPY_VALUE(d, v);

#define ZEPHIR_CPY_WRT_CTOR(d, v) \
	if (d) { \
		if (Z_REFCOUNTED_P(d) && Z_REFCOUNT_P(d) > 0) { \
			zephir_ptr_dtor(d); \
		} \
	} else { \
		/*TODO: as above */ \
	} \
	ZVAL_DUP(d, v);

#define ZEPHIR_OBS_VAR(z) \
	zephir_memory_observe(z)

#define ZEPHIR_OBS_VAR_ONCE(z) \
	if (Z_TYPE_P(z) == IS_UNDEF) { \
		zephir_memory_observe(z); \
	}

#define ZEPHIR_OBS_COPY_OR_DUP(z, v) \
		ZEPHIR_OBS_VAR_ONCE(z); \
		ZVAL_COPY(z, v);

#define ZEPHIR_OBS_NVAR(z) \
	if (Z_TYPE_P(z) != IS_UNDEF) { \
		if (Z_REFCOUNTED_P(z) && Z_REFCOUNT_P(z) > 1) { \
			Z_DELREF_P(z); \
		} else {\
			zephir_ptr_dtor(z); \
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
		zval * restrict tmp_ = (ppzv); \
		if (tmp_ != NULL) { \
			if (Z_TYPE_P(tmp_) != IS_UNDEF) { \
				zephir_ptr_dtor(tmp_); \
				ZVAL_UNDEF(tmp_); \
			} else { \
				zephir_memory_observe(tmp_); \
			} \
		} \
	} while (0)

#define ZEPHIR_SEPARATE(z) SEPARATE_ZVAL(z)

#define ZEPHIR_SEPARATE_PARAM(z) \
	do { \
		zval *orig_ptr = z;\
		ZEPHIR_SEPARATE(orig_ptr); \
		/*zephir_memory_observe(orig_ptr);*/ \
	} while (0)

#endif
