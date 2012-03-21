
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

#define PHALCON_MAX_MEMORY_STACK 96

typedef struct _phalcon_memory_entry {
	int pointer;
	zval **addresses[PHALCON_MAX_MEMORY_STACK];
	struct _phalcon_memory_entry *prev;
	struct _phalcon_memory_entry *next;
} phalcon_memory_entry;

extern int phalcon_memory_grow_stack();
extern int phalcon_memory_restore_stack();

extern int phalcon_memory_observe(zval **var);
extern int phalcon_memory_remove(zval **var);

#define PHALCON_MM_GROW() phalcon_memory_grow_stack()
#define PHALCON_MM_RESTORE() phalcon_memory_restore_stack()

/** Memory macros */
#define PHALCON_ALLOC_ZVAL(z) \
	ALLOC_ZVAL(z); INIT_PZVAL(z);

#define PHALCON_INIT_VAR(z)\
	if (z) {\
		if (Z_REFCOUNT_P(z) > 1) {\
			Z_DELREF_P(z);\
			ALLOC_ZVAL(z);\
			Z_SET_REFCOUNT_P(z, 1);\
			Z_UNSET_ISREF_P(z);\
		} else {\
			zval_ptr_dtor(&z);\
			PHALCON_ALLOC_ZVAL(z);\
		}\
	} else {\
		phalcon_memory_observe(&z);\
		PHALCON_ALLOC_ZVAL(z);\
	}

#define PHALCON_INIT_VAR(z)\
	if (z) {\
		if (Z_REFCOUNT_P(z) > 1) {\
			Z_DELREF_P(z);\
			ALLOC_ZVAL(z);\
			Z_SET_REFCOUNT_P(z, 1);\
			Z_UNSET_ISREF_P(z);\
		} else {\
			zval_ptr_dtor(&z);\
			PHALCON_ALLOC_ZVAL(z);\
		}\
	} else {\
		phalcon_memory_observe(&z);\
		PHALCON_ALLOC_ZVAL(z);\
	}

#define PHALCON_ALLOC_ZVAL_MM(z) \
	PHALCON_ALLOC_ZVAL(z); \
	phalcon_memory_observe(&z);

#define PHALCON_CPY_WRT(d, v) \
	if (d) { \
		if (Z_REFCOUNT_P(d) > 0) { \
			zval_ptr_dtor(&d); \
		} \
	} else { \
		phalcon_memory_observe(&d); \
	} \
	Z_ADDREF_P(v); \
	d = v;

#define PHALCON_SEPARATE_ARRAY(a) \
	{\
		if (Z_REFCOUNT_P(a) > 1) {\
			zval *new_zv;\
			Z_DELREF_P(a);\
			ALLOC_ZVAL(new_zv);\
			INIT_PZVAL_COPY(new_zv, a);\
			a = new_zv;\
			zval_copy_ctor(new_zv);\
		}\
	}

#define PHALCON_SEPARATE(z) \
	{\
		zval *orig_ptr = z;\
		if (Z_REFCOUNT_P(orig_ptr) > 1) {\
			Z_DELREF_P(orig_ptr);\
			ALLOC_ZVAL(z);\
			phalcon_memory_observe(&z);\
			*z = *orig_ptr;\
			zval_copy_ctor(z);\
			Z_SET_REFCOUNT_P(z, 1);\
			Z_UNSET_ISREF_P(z);\
		}\
	}

#define PHALCON_SEPARATE_NMO(z) \
	{\
		zval *orig_ptr = z;\
		if (Z_REFCOUNT_P(orig_ptr) > 1) {\
			Z_DELREF_P(orig_ptr);\
			ALLOC_ZVAL(z);\
			*z = *orig_ptr;\
			zval_copy_ctor(z);\
			Z_SET_REFCOUNT_P(z, 1);\
			Z_UNSET_ISREF_P(z);\
		}\
	}

#define PHALCON_SEPARATE_PARAM(z) \
	{\
		zval *orig_ptr = z;\
		if (Z_REFCOUNT_P(orig_ptr) > 1) {\
			ALLOC_ZVAL(z);\
			phalcon_memory_observe(&z);\
			*z = *orig_ptr;\
			zval_copy_ctor(z);\
			Z_SET_REFCOUNT_P(z, 1);\
			Z_UNSET_ISREF_P(z);\
		}\
	}

#define PHALCON_SEPARATE_PARAM_NMO(z) {\
		zval *orig_ptr = z;\
		if (Z_REFCOUNT_P(orig_ptr) > 1) {\
			ALLOC_ZVAL(z);\
			*z = *orig_ptr;\
			zval_copy_ctor(z);\
			Z_SET_REFCOUNT_P(z, 1);\
			Z_UNSET_ISREF_P(z);\
		}\
	}
