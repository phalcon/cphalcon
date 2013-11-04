
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

/* Memory Frames */
#ifndef PHALCON_RELEASE
void PHALCON_FASTCALL phalcon_memory_grow_stack(const char *func TSRMLS_DC);
int PHALCON_FASTCALL phalcon_memory_restore_stack(const char *func TSRMLS_DC);

#define PHALCON_MM_GROW() phalcon_memory_grow_stack(__func__ TSRMLS_CC)
#define PHALCON_MM_RESTORE() phalcon_memory_restore_stack(__func__ TSRMLS_CC)

#else
void PHALCON_FASTCALL phalcon_memory_grow_stack(TSRMLS_D);
int PHALCON_FASTCALL phalcon_memory_restore_stack(TSRMLS_D);

#define PHALCON_MM_GROW() phalcon_memory_grow_stack(TSRMLS_C)
#define PHALCON_MM_RESTORE() phalcon_memory_restore_stack(TSRMLS_C)

#endif

extern void PHALCON_FASTCALL phalcon_memory_observe(zval **var TSRMLS_DC);
extern void PHALCON_FASTCALL phalcon_memory_remove(zval **var TSRMLS_DC);
extern void PHALCON_FASTCALL phalcon_memory_alloc(zval **var TSRMLS_DC);
extern void PHALCON_FASTCALL phalcon_memory_alloc_pnull(zval **var TSRMLS_DC);

extern int PHALCON_FASTCALL phalcon_clean_restore_stack(TSRMLS_D);

/* Virtual symbol tables */
extern void phalcon_create_symbol_table(TSRMLS_D);
/*extern void phalcon_restore_symbol_table(TSRMLS_D);*/
extern void phalcon_clean_symbol_tables(TSRMLS_D);

/** Export symbols to active symbol table */
extern int phalcon_set_symbol(zval *key_name, zval *value TSRMLS_DC);
extern int phalcon_set_symbol_str(char *key_name, unsigned int key_length, zval *value TSRMLS_DC);

extern void PHALCON_FASTCALL phalcon_copy_ctor(zval *destiny, zval *origin);

/* Memory macros */
#define PHALCON_ALLOC_ZVAL(z) \
	ALLOC_INIT_ZVAL(z)

#define PHALCON_ALLOC_GHOST_ZVAL(z) \
	do { \
		ALLOC_INIT_ZVAL(z); \
		Z_SET_REFCOUNT_P(z, 0); \
	} while (0)

#define PHALCON_INIT_VAR(z) \
	phalcon_memory_alloc(&z TSRMLS_CC)

#define PHALCON_INIT_NVAR(z)\
	if (z) { \
		if (Z_REFCOUNT_P(z) > 1) { \
			Z_DELREF_P(z); \
			ALLOC_ZVAL(z); \
			Z_SET_REFCOUNT_P(z, 1); \
			Z_UNSET_ISREF_P(z); \
		} else {\
			zval_dtor(z); \
		} \
		ZVAL_NULL(z); \
	} else { \
		phalcon_memory_alloc(&z TSRMLS_CC); \
	}

#define PHALCON_INIT_NVAR_PNULL(z)\
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
		phalcon_memory_alloc_pnull(&z TSRMLS_CC); \
	}

#define PHALCON_CPY_WRT(d, v) \
	if (d) { \
		if (Z_REFCOUNT_P(d) > 0) { \
			zval_ptr_dtor(&d); \
		} \
	} else { \
		phalcon_memory_observe(&d TSRMLS_CC); \
	} \
	Z_ADDREF_P(v); \
	d = v;

#define PHALCON_CPY_WRT_CTOR(d, v) \
	if (d) { \
		if (Z_REFCOUNT_P(d) > 0) { \
			zval_ptr_dtor(&d); \
		} \
	} else { \
		phalcon_memory_observe(&d TSRMLS_CC); \
	} \
	ALLOC_ZVAL(d); \
	*d = *v; \
	zval_copy_ctor(d); \
	Z_SET_REFCOUNT_P(d, 1); \
	Z_UNSET_ISREF_P(d);

/* */
#define PHALCON_OBS_VAR(z) \
	phalcon_memory_observe(&z TSRMLS_CC)

#define PHALCON_OBS_NVAR(z)\
	if (z) { \
		if (Z_REFCOUNT_P(z) > 1) { \
			Z_DELREF_P(z); \
		} else {\
			zval_ptr_dtor(&z); \
			z = NULL; \
		} \
	} else { \
		phalcon_memory_observe(&z TSRMLS_CC); \
	}

#define PHALCON_SEPARATE_ARRAY(a) \
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

#define PHALCON_SEPARATE_PARAM(z) \
	do { \
		zval *orig_ptr = z;\
		phalcon_memory_observe(&z TSRMLS_CC);\
		ALLOC_ZVAL(z);\
		*z = *orig_ptr;\
		zval_copy_ctor(z);\
		Z_SET_REFCOUNT_P(z, 1);\
		Z_UNSET_ISREF_P(z);\
	} while (0)
