
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Zephir Team (http://www.zephir-lang.com)       |
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

#define ZEPHIR_NUM_PREALLOCATED_FRAMES 25

/* Variable Tracking */
void zephir_init_nvar(zval **var TSRMLS_DC);
void zephir_cpy_wrt(zval **dest, zval *var TSRMLS_DC);
void zephir_cpy_wrt_ctor(zval **dest, zval *var TSRMLS_DC);

void zephir_value_dtor(zval *zvalue ZEND_FILE_LINE_DC);
void ZEND_FASTCALL zephir_ptr_dtor(zval **var);
void ZEND_FASTCALL zephir_dtor(zval *var);

/* Memory Frames */
#ifndef ZEPHIR_RELEASE
void ZEPHIR_FASTCALL zephir_memory_grow_stack(const char *func TSRMLS_DC);
int ZEPHIR_FASTCALL zephir_memory_restore_stack(const char *func TSRMLS_DC);

#define ZEPHIR_MM_GROW() zephir_memory_grow_stack(NULL TSRMLS_CC)
#define ZEPHIR_MM_RESTORE() zephir_memory_restore_stack(NULL TSRMLS_CC)

#else
void ZEPHIR_FASTCALL zephir_memory_grow_stack(TSRMLS_D);
int ZEPHIR_FASTCALL zephir_memory_restore_stack(TSRMLS_D);

#define ZEPHIR_MM_GROW() zephir_memory_grow_stack(TSRMLS_C)
#define ZEPHIR_MM_RESTORE() zephir_memory_restore_stack(TSRMLS_C)

#endif

void ZEPHIR_FASTCALL zephir_memory_observe(zval **var TSRMLS_DC);
void ZEPHIR_FASTCALL zephir_memory_remove(zval **var TSRMLS_DC);
void ZEPHIR_FASTCALL zephir_memory_alloc(zval **var TSRMLS_DC);
void ZEPHIR_FASTCALL zephir_memory_alloc_pnull(zval **var TSRMLS_DC);

int ZEPHIR_FASTCALL zephir_clean_restore_stack(TSRMLS_D);

/* Virtual symbol tables */
void zephir_create_symbol_table(TSRMLS_D);
/*void zephir_restore_symbol_table(TSRMLS_D);*/
void zephir_clean_symbol_tables(TSRMLS_D);

/** Export symbols to active symbol table */
int zephir_set_symbol(zval *key_name, zval *value TSRMLS_DC);
int zephir_set_symbol_str(char *key_name, unsigned int key_length, zval *value TSRMLS_DC);

void ZEPHIR_FASTCALL zephir_copy_ctor(zval *destiny, zval *origin);

void zephir_initialize_memory(zend_zephir_globals_def *zephir_globals_ptr TSRMLS_DC);
int zephir_cleanup_fcache(void *pDest TSRMLS_DC, int num_args, va_list args, zend_hash_key *hash_key);
void zephir_deinitialize_memory(TSRMLS_D);

/* Memory macros */
#define ZEPHIR_ALLOC_ZVAL(z) \
	ALLOC_INIT_ZVAL(z)

#define ZEPHIR_SINIT_VAR(z) \
	INIT_PZVAL(&z); \
	ZVAL_NULL(&z);

#define ZEPHIR_SINIT_NVAR(z) Z_SET_REFCOUNT_P(&z, 1)

#define ZEPHIR_INIT_ZVAL_NREF(z) \
	ALLOC_ZVAL(z); \
	Z_SET_REFCOUNT_P(z, 0); \
	Z_UNSET_ISREF_P(z);

#define ZEPHIR_INIT_VAR(z) \
	zephir_memory_alloc(&z TSRMLS_CC)

#define ZEPHIR_INIT_NVAR(z)\
	if (z) { \
		if (!Z_ISREF_P(z)) { \
			if (Z_REFCOUNT_P(z) > 1) { \
				Z_DELREF_P(z); \
				ALLOC_ZVAL(z); \
				Z_SET_REFCOUNT_P(z, 1); \
				Z_UNSET_ISREF_P(z); \
			} else { \
				zephir_dtor(z); \
				Z_SET_REFCOUNT_P(z, 1); \
				Z_UNSET_ISREF_P(z); \
			} \
			ZVAL_NULL(z); \
		} \
	} else { \
		zephir_memory_alloc(&z TSRMLS_CC); \
	}

/**
 * Second allocation, assumes the variable was allocated for the first time in the branch zero
 */
#define ZEPHIR_INIT_BNVAR(z) \
	if (Z_REFCOUNT_P(z) > 1) { \
		zephir_ptr_dtor(&z); \
		ALLOC_ZVAL(z); \
		Z_SET_REFCOUNT_P(z, 1); \
		Z_UNSET_ISREF_P(z); \
		ZVAL_NULL(z); \
	} else {\
		zephir_ptr_dtor(&z); \
		ZEPHIR_ALLOC_ZVAL(z); \
	}

#define ZEPHIR_INIT_NVAR_PNULL(z)\
	if (z) { \
		if (Z_REFCOUNT_P(z) > 1) { \
			Z_DELREF_P(z); \
			if (Z_REFCOUNT_P(z) >= 1) { \
				zval_copy_ctor(z); \
			} \
			ALLOC_ZVAL(z); \
			Z_SET_REFCOUNT_P(z, 1); \
			Z_UNSET_ISREF_P(z); \
		} \
		ZVAL_NULL(z); \
	} else { \
		zephir_memory_alloc_pnull(&z TSRMLS_CC); \
	}

/* only removes the value body of the zval */
#define ZEPHIR_INIT_LNVAR(z)\
	if (z) { \
		if (Z_REFCOUNT_P(z) > 1) { \
			Z_DELREF_P(z); \
			ALLOC_ZVAL(z); \
			Z_SET_REFCOUNT_P(z, 1); \
			Z_UNSET_ISREF_P(z); \
		} else { \
			if (!Z_ISREF_P(z)) { \
				zephir_value_dtor(z ZEND_FILE_LINE_CC); \
			} \
			Z_SET_REFCOUNT_P(z, 1); \
			Z_UNSET_ISREF_P(z); \
		} \
		ZVAL_NULL(z); \
	} else { \
		zephir_memory_alloc(&z TSRMLS_CC); \
	}

#define ZEPHIR_CPY_WRT(d, v) \
	if (d) { \
		if (Z_REFCOUNT_P(d) > 0) { \
			zephir_ptr_dtor(&d); \
		} \
	} else { \
		zephir_memory_observe(&d TSRMLS_CC); \
	} \
	Z_ADDREF_P(v); \
	d = v;

#define ZEPHIR_CPY_WRT_CTOR(d, v) \
	if (d) { \
		if (Z_REFCOUNT_P(d) > 0) { \
			zephir_ptr_dtor(&d); \
		} \
	} else { \
		zephir_memory_observe(&d TSRMLS_CC); \
	} \
	ALLOC_ZVAL(d); \
	*d = *v; \
	zval_copy_ctor(d); \
	Z_SET_REFCOUNT_P(d, 1); \
	Z_UNSET_ISREF_P(d);

#define ZEPHIR_MAKE_REFERENCE(d, v)	\
	if (d) { \
		if (Z_REFCOUNT_P(d) > 0) { \
			zephir_ptr_dtor(&d); \
		} \
	} else { \
		zephir_memory_observe(&d TSRMLS_CC); \
	} \
	ALLOC_ZVAL(d); \
	Z_TYPE_P(d) = Z_TYPE_P(v); \
	d->value = v->value; \
	Z_SET_REFCOUNT_P(d, 1); \
	Z_SET_ISREF_P(d);

/* */
#define ZEPHIR_OBS_VAR(z) \
	zephir_memory_observe(&z TSRMLS_CC)

#define ZEPHIR_OBS_NVAR(z)\
	if (z) { \
		if (Z_REFCOUNT_P(z) > 1) { \
			Z_DELREF_P(z); \
		} else {\
			zephir_ptr_dtor(&z); \
			z = NULL; \
		} \
	} else { \
		zephir_memory_observe(&z TSRMLS_CC); \
	}

#define ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(ppzv) \
	do { \
		zval **tmp_ = (ppzv); \
		if (tmp_ != NULL) { \
			if (*tmp_) { \
				zephir_ptr_dtor(tmp_); \
				*tmp_ = NULL; \
			} \
			else { \
				zephir_memory_observe((ppzv) TSRMLS_CC); \
			} \
		} \
	} while (0)

#define ZEPHIR_OBSERVE_OR_NULLIFY_VAR(z) \
	do { \
		if (z) { \
			zephir_ptr_dtor(&z); \
			z = NULL; \
		} \
		else { \
			zephir_memory_observe(&z TSRMLS_CC); \
		} \
	} while (0)

#define ZEPHIR_SEPARATE_ARRAY(a) \
	{ \
		if (Z_REFCOUNT_P(a) > 1) { \
			zval *new_zv; \
			Z_DELREF_P(a); \
			ALLOC_ZVAL(new_zv); \
			INIT_PZVAL_COPY(new_zv, a); \
			a = new_zv; \
			zval_copy_ctor(new_zv); \
		} \
	}

#define ZEPHIR_SEPARATE(z) SEPARATE_ZVAL(&z)

#define ZEPHIR_SEPARATE_PARAM(z) \
	do { \
		zval *orig_ptr = z;\
		zephir_memory_observe(&z TSRMLS_CC);\
		ALLOC_ZVAL(z);\
		*z = *orig_ptr;\
		zval_copy_ctor(z);\
		Z_SET_REFCOUNT_P(z, 1);\
		Z_UNSET_ISREF_P(z);\
	} while (0)

#define ZEPHIR_SEPARATE_PARAM_NMO(z) { \
		zval *orig_ptr = z; \
		if (Z_REFCOUNT_P(orig_ptr) > 1) { \
			ALLOC_ZVAL(z); \
			*z = *orig_ptr; \
			zval_copy_ctor(z); \
			Z_SET_REFCOUNT_P(z, 1); \
			Z_UNSET_ISREF_P(z); \
		} \
	}

#endif
