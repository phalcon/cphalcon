
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

#ifndef PHALCON_KERNEL_MEMORY_H
#define PHALCON_KERNEL_MEMORY_H

#include "php_phalcon.h"
#include "kernel/main.h"

void phalcon_initialize_memory(zend_phalcon_globals *phalcon_globals_ptr TSRMLS_DC);
void phalcon_deinitialize_memory(TSRMLS_D);

/* Memory Frames */
#ifndef PHALCON_RELEASE
void phalcon_dump_memory_frame(phalcon_memory_entry *active_memory TSRMLS_DC);
void phalcon_dump_current_frame(TSRMLS_D);
void phalcon_dump_all_frames(TSRMLS_D);

void ZEND_FASTCALL phalcon_memory_grow_stack(const char *func TSRMLS_DC);
int ZEND_FASTCALL phalcon_memory_restore_stack(const char *func TSRMLS_DC);

#define PHALCON_MM_GROW()       phalcon_memory_grow_stack(__func__ TSRMLS_CC)
#define PHALCON_MM_RESTORE()    phalcon_memory_restore_stack(__func__ TSRMLS_CC)

void ZEND_FASTCALL phalcon_memory_observe(zval **var, const char *func TSRMLS_DC) /* PHALCON_ATTR_NONNULL */;
void ZEND_FASTCALL phalcon_memory_alloc(zval **var, const char *func TSRMLS_DC);
void ZEND_FASTCALL phalcon_memory_alloc_pnull(zval **var, const char *func TSRMLS_DC);

#define PHALCON_MEMORY_ALLOC(z) \
	phalcon_memory_alloc((z), __func__ TSRMLS_CC)

#define PHALCON_MEMORY_ALLOC_PNULL(z) \
	phalcon_memory_alloc_pnull((z), __func__ TSRMLS_CC)

#define PHALCON_MEMORY_OBSERVE(z) \
	phalcon_memory_observe((z), __func__ TSRMLS_CC)

#else
void ZEND_FASTCALL phalcon_memory_grow_stack(TSRMLS_D);
int ZEND_FASTCALL phalcon_memory_restore_stack(TSRMLS_D);

#define PHALCON_MM_GROW()       phalcon_memory_grow_stack(TSRMLS_C)
#define PHALCON_MM_RESTORE()    phalcon_memory_restore_stack(TSRMLS_C)

void ZEND_FASTCALL phalcon_memory_observe(zval **var TSRMLS_DC) /* PHALCON_ATTR_NONNULL */;
void ZEND_FASTCALL phalcon_memory_alloc(zval **var TSRMLS_DC);
void ZEND_FASTCALL phalcon_memory_alloc_pnull(zval **var TSRMLS_DC);

#define PHALCON_MEMORY_ALLOC(z) \
	phalcon_memory_alloc((z) TSRMLS_CC)

#define PHALCON_MEMORY_ALLOC_PNULL(z) \
	phalcon_memory_alloc_pnull((z) TSRMLS_CC)

#define PHALCON_MEMORY_OBSERVE(z) \
	phalcon_memory_observe((z) TSRMLS_CC)

#endif

void phalcon_memory_remove(zval **var TSRMLS_DC) PHALCON_ATTR_NONNULL;

int ZEND_FASTCALL phalcon_clean_restore_stack(TSRMLS_D);

/* Virtual symbol tables */
void phalcon_create_symbol_table(TSRMLS_D);
void phalcon_clean_symbol_tables(TSRMLS_D);

/** Export symbols to active symbol table */
int phalcon_set_symbol(zval *key_name, zval *value TSRMLS_DC);
int phalcon_set_symbol_str(char *key_name, unsigned int key_length, zval *value TSRMLS_DC);

void ZEND_FASTCALL phalcon_copy_ctor(zval *destiny, zval *origin) PHALCON_ATTR_NONNULL;

void ZEND_FASTCALL phalcon_ptr_dtor(zval **var);
void ZEND_FASTCALL phalcon_dtor(zval *var);
void phalcon_value_dtor(zval *zvalue ZEND_FILE_LINE_DC);

/**
 * @brief destroys @c pzval if it is not @c NULL
 * @param pzval
 */
static inline void phalcon_safe_zval_ptr_dtor(zval *pzval)
{
	if (pzval) {
		zval_ptr_dtor(&pzval);
	}
}

/* Memory macros */
#define PHALCON_ALLOC_GHOST_ZVAL(z)                   \
	do {                                              \
		MAKE_STD_ZVAL(z);                             \
		Z_SET_REFCOUNT_P(z, 0);                       \
	} while (0)
		
#define PHALCON_ALLOC_ZVAL(z) \
	ALLOC_INIT_ZVAL(z)

#define PHALCON_SINIT_VAR(z) \
	INIT_PZVAL(&z); \
	ZVAL_NULL(&z);

#define PHALCON_SINIT_NVAR(z) Z_SET_REFCOUNT_P(&z, 1)

#define PHALCON_INIT_ZVAL_NREF(z) \
	ALLOC_ZVAL(z); \
	Z_SET_REFCOUNT_P(z, 0); \
	Z_UNSET_ISREF_P(z);

#define PHALCON_INIT_VAR(z) \
	PHALCON_MEMORY_ALLOC(&z)

#define PHALCON_INIT_NVAR(z)                          \
	do {                                              \
		if (z) {                                      \
			if (!Z_ISREF_P(z)) {                      \
				if (Z_REFCOUNT_P(z) > 1) {            \
					Z_DELREF_P(z);                    \
					ALLOC_ZVAL(z);                    \
					Z_SET_REFCOUNT_P(z, 1);           \
					Z_UNSET_ISREF_P(z);               \
				} else {                              \
					phalcon_dtor(z);                   \
					Z_SET_REFCOUNT_P(z, 1);           \
					Z_UNSET_ISREF_P(z);               \
				}                                     \
				ZVAL_NULL(z);                         \
			}                                         \
		} else {                                      \
			PHALCON_MEMORY_ALLOC(&z);                 \
		}                                             \
	} while (0)

/**
 * Second allocation, assumes the variable was allocated for the first time in the branch zero
 */
#define PHALCON_INIT_BNVAR(z) \
	if (Z_REFCOUNT_P(z) > 1) { \
		phalcon_ptr_dtor(&z); \
		ALLOC_ZVAL(z); \
		Z_SET_REFCOUNT_P(z, 1); \
		Z_UNSET_ISREF_P(z); \
		ZVAL_NULL(z); \
	} else {\
		phalcon_ptr_dtor(&z); \
		PHALCON_ALLOC_ZVAL(z); \
	}

#define PHALCON_INIT_NVAR_PNULL(z)\
	do {                                              \
		if (z) {                                      \
			if (Z_REFCOUNT_P(z) > 1) {                \
				Z_DELREF_P(z);                        \
				if (Z_REFCOUNT_P(z) >= 1) {           \
					zval_copy_ctor(z);                \
				}                                     \
				ALLOC_ZVAL(z);                        \
				Z_SET_REFCOUNT_P(z, 1);               \
				Z_UNSET_ISREF_P(z);                   \
			}                                         \
			ZVAL_NULL(z);                             \
		} else {                                      \
			PHALCON_MEMORY_ALLOC_PNULL(&z);           \
		}                                             \
	} while (0)

/* only removes the value body of the zval */
#define PHALCON_INIT_LNVAR(z)\
	if (z) { \
		if (Z_REFCOUNT_P(z) > 1) { \
			Z_DELREF_P(z); \
			ALLOC_ZVAL(z); \
			Z_SET_REFCOUNT_P(z, 1); \
			Z_UNSET_ISREF_P(z); \
		} else { \
			if (!Z_ISREF_P(z)) { \
				phalcon_value_dtor(z ZEND_FILE_LINE_CC); \
			} \
			Z_SET_REFCOUNT_P(z, 1); \
			Z_UNSET_ISREF_P(z); \
		} \
		ZVAL_NULL(z); \
	} else { \
		PHALCON_MEMORY_ALLOC(&z); \
	}

#define PHALCON_CPY_WRT(d, v)                         \
	do {                                              \
		if (d) {                                      \
			if (Z_REFCOUNT_P(d) > 0) {                \
				phalcon_ptr_dtor(&d);                 \
			}                                         \
		}                                             \
		else {                                        \
			PHALCON_MEMORY_OBSERVE(&d);               \
		}                                             \
		Z_ADDREF_P(v);                                \
		d = v;                                        \
	} while (0)

#define PHALCON_CPY_WRT_CTOR(d, v)                    \
	do {                                              \
		if (d) {                                      \
			if (Z_REFCOUNT_P(d) > 0) {                \
				phalcon_ptr_dtor(&d);                 \
			}                                         \
		} else {                                      \
			PHALCON_MEMORY_OBSERVE(&d);               \
		}                                             \
		ALLOC_ZVAL(d);                                \
		*d = *v;                                      \
		zval_copy_ctor(d);                            \
		Z_SET_REFCOUNT_P(d, 1);                       \
		Z_UNSET_ISREF_P(d);                           \
	} while (0)

#define PHALCON_MAKE_REFERENCE(d, v)	\
	if (d) { \
		if (Z_REFCOUNT_P(d) > 0) { \
			phalcon_ptr_dtor(&d); \
		} \
	} else { \
			phalcon_memory_observe(&d TSRMLS_CC); \
	} \
	ALLOC_ZVAL(d); \
	Z_TYPE_P(d) = Z_TYPE_P(v); \
	d->value = v->value; \
	Z_SET_REFCOUNT_P(d, 1); \
	Z_SET_ISREF_P(d);

/* */
#define PHALCON_OBS_VAR(z) \
	PHALCON_MEMORY_OBSERVE(&z)

#define PHALCON_OBS_NVAR(z)                           \
	do {                                              \
		if (z) {                                      \
			if (Z_REFCOUNT_P(z) > 1) {                \
				Z_DELREF_P(z);                        \
			}                                         \
			else {                                    \
				phalcon_ptr_dtor(&z);                    \
				z = NULL;                             \
			}                                         \
		} else {                                      \
			PHALCON_MEMORY_OBSERVE(&z);               \
		}                                             \
	} while (0)

#define PHALCON_OBSERVE_OR_NULLIFY_PPZV(ppzv)              \
	do {                                                   \
		zval **tmp_ = (ppzv);                              \
		if (tmp_ != NULL) {                                \
			if (*tmp_) {                                   \
				phalcon_ptr_dtor(tmp_);                    \
				*tmp_ = NULL;                              \
			} else {                                       \
				PHALCON_MEMORY_OBSERVE((ppzv));            \
			}                                              \
		}                                                  \
	} while (0)

#define PHALCON_OBSERVE_OR_NULLIFY_VAR(z)             \
	do {                                              \
		if (z) {                                      \
			phalcon_ptr_dtor(&z);                     \
			z = NULL;                                 \
		} else {                                      \
			PHALCON_MEMORY_OBSERVE(&z);               \
		}                                             \
	} while (0)


#define PHALCON_SEPARATE_ARRAY(a)                     \
	do {                                              \
		if (Z_REFCOUNT_P(a) > 1) {                    \
			zval *new_zv;                             \
			Z_DELREF_P(a);                            \
			ALLOC_ZVAL(new_zv);                       \
			INIT_PZVAL_COPY(new_zv, a);               \
			a = new_zv;                               \
			zval_copy_ctor(new_zv);                   \
		}                                             \
	} while (0)

#define PHALCON_SEPARATE(z) SEPARATE_ZVAL(&z)
#define PHALCON_SEPARATE_PARAM(z)                     \
	do {                                              \
		zval *orig_ptr = z;                           \
		PHALCON_MEMORY_OBSERVE(&z);                   \
		ALLOC_ZVAL(z);                                \
		*z = *orig_ptr;                               \
		zval_copy_ctor(z);                            \
		Z_SET_REFCOUNT_P(z, 1);                       \
		Z_UNSET_ISREF_P(z);                           \
	} while (0)

#define PHALCON_SEPARATE_PARAM_NMO(z) { \
		zval *orig_ptr = z; \
		if (Z_REFCOUNT_P(orig_ptr) > 1) { \
			ALLOC_ZVAL(z); \
			*z = *orig_ptr; \
			zval_copy_ctor(z); \
			Z_SET_REFCOUNT_P(z, 1); \
			Z_UNSET_ISREF_P(z); \
		} \
	}

static inline int phalcon_maybe_separate_zval(zval** z)
{
	if (Z_REFCOUNT_PP(z) > 1 && !Z_ISREF_PP(z)) {
		zval *new_zv;

		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, *z);
		*z = new_zv;
		zval_copy_ctor(new_zv);

		return 1;
	}

	return 0;
}

#endif /* PHALCON_KERNEL_MEMORY_H */
