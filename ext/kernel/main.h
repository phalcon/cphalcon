
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

/** Main macros */
#define PH_DEBUG 0

#define PH_NOISY 0
#define PH_SILENT 1

#define PH_NOISY_CC PH_NOISY TSRMLS_CC
#define PH_SILENT_CC PH_SILENT TSRMLS_CC

#define PH_SEPARATE 256
#define PH_COPY 1024
#define PH_CTOR 4096

#define PH_FETCH_CLASS_SILENT (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC

#define SL(str) ZEND_STRL(str)
#define SS(str) ZEND_STRS(str)

/** SPL dependencies */
#if defined(HAVE_SPL) && ((PHP_MAJOR_VERSION > 5) || (PHP_MAJOR_VERSION == 5 && PHP_MINOR_VERSION >= 1))
extern ZEND_API zend_class_entry *zend_ce_iterator;
extern ZEND_API zend_class_entry *zend_ce_arrayaccess;
extern ZEND_API zend_class_entry *zend_ce_serializable;
extern PHPAPI zend_class_entry *spl_ce_RuntimeException;
extern PHPAPI zend_class_entry *spl_ce_Countable;
extern PHPAPI zend_class_entry *spl_ce_SeekableIterator;
extern PHPAPI zend_class_entry *spl_ce_BadMethodCallException;
#endif

/* Startup functions */
extern void php_phalcon_init_globals(zend_phalcon_globals *phalcon_globals TSRMLS_DC);
extern zend_class_entry *phalcon_register_internal_interface_ex(zend_class_entry *orig_class_entry, char *parent_name TSRMLS_DC);

/* Globals functions */
extern int phalcon_init_global(char *global, unsigned int global_length TSRMLS_DC);
extern int phalcon_get_global(zval **arr, const char *global, unsigned int global_length TSRMLS_DC);

extern int phalcon_is_callable(zval *var TSRMLS_DC);
extern int phalcon_function_exists(const zval *function_name TSRMLS_DC);
extern int phalcon_function_exists_ex(const char *func_name, unsigned int func_len TSRMLS_DC);
extern int phalcon_function_quick_exists_ex(const char *func_name, unsigned int func_len, unsigned long key TSRMLS_DC);

/* Count */
extern void phalcon_fast_count(zval *result, zval *array TSRMLS_DC);
extern int phalcon_fast_count_ev(zval *array TSRMLS_DC);

/* Utils functions */
extern void phalcon_inherit_not_found(const char *class_name, const char *inherit_name);
extern int phalcon_is_iterable_ex(zval *arr, HashTable **arr_hash, HashPosition *hash_position, int duplicate, int reverse TSRMLS_DC);

/* Fetch Parameters */
extern int phalcon_fetch_parameters(int grow_stack, int num_args TSRMLS_DC, int required_args, int optional_args, ...);

/* Compatibility with PHP 5.3 */
#ifndef ZVAL_COPY_VALUE
 #define ZVAL_COPY_VALUE(z, v)\
  (z)->value = (v)->value;\
  Z_TYPE_P(z) = Z_TYPE_P(v);
#endif

#ifndef INIT_PZVAL_COPY
 #define INIT_PZVAL_COPY(z, v) ZVAL_COPY_VALUE(z, v);\
  Z_SET_REFCOUNT_P(z, 1);\
  Z_UNSET_ISREF_P(z);
#endif

/** Symbols */
#define PHALCON_READ_SYMBOL(var, auxarr, name) if (EG(active_symbol_table)){ \
	if (zend_hash_find(EG(active_symbol_table), name, sizeof(name), (void **)  &auxarr) == SUCCESS) { \
			var = *auxarr; \
		} else { \
			ZVAL_NULL(var); \
		} \
	} else { \
		ZVAL_NULL(var); \
	}

/**
 * Return zval checking if it's needed to ctor
 */
#define RETURN_CCTOR(var) { \
		*(return_value) = *(var); \
		if (Z_TYPE_P(var) > IS_BOOL) { \
			phalcon_copy_ctor(return_value, var); \
		} \
		INIT_PZVAL(return_value) \
	} \
	PHALCON_MM_RESTORE(); \
	return;

/**
 * Return zval checking if it's needed to ctor, without restoring the memory stack
 */
#define RETURN_CCTORW(var) { \
		*(return_value) = *(var); \
		if (Z_TYPE_P(var) > IS_BOOL) { \
			phalcon_copy_ctor(return_value, var); \
		} \
		INIT_PZVAL(return_value) \
	} \
	return;

/**
 * Return zval with always ctor
 */
#define RETURN_CTOR(var) { \
		RETVAL_ZVAL(var, 1, 0); \
	} \
	PHALCON_MM_RESTORE(); \
	return;

/**
 * Return zval with always ctor, without restoring the memory stack
 */
#define RETURN_CTORW(var) { \
		RETVAL_ZVAL(var, 1, 0); \
	} \
	return;

/**
 * Return this pointer
 */
#define RETURN_THIS() { \
		RETVAL_ZVAL(this_ptr, 1, 0); \
	} \
	PHALCON_MM_RESTORE(); \
	return;

/**
 * Return zval with always ctor, without restoring the memory stack
 */
#define RETURN_THISW() \
	RETURN_ZVAL(this_ptr, 1, 0);

/**
 * Returns variables without ctor
 */
#define RETURN_NCTOR(var) { \
		*(return_value) = *(var); \
		INIT_PZVAL(return_value) \
	} \
	PHALCON_MM_RESTORE(); \
	return;

/**
 * Returns variables without ctor, without restoring the memory stack
 */
#define RETURN_NCTORW(var) { \
		*(return_value) = *(var); \
		INIT_PZVAL(return_value) \
	} \
	return;

/**
 * Check for ctor on the same return_value
 */
#define RETURN_SCTOR() \
	if (Z_TYPE_P(return_value) > IS_BOOL) { \
		zval_copy_ctor(return_value); \
	} \
	PHALCON_MM_RESTORE(); \
	return;

/**
 * Check for ctor on the same return_value, without restoring the memory stack
 */
#define RETURN_SCTORW() \
	if (Z_TYPE_P(return_value) > IS_BOOL) { \
		zval_copy_ctor(return_value); \
	} \
	return;

/**
 * Returns a zval in an object member
 */
#define RETURN_MEMBER(object, member_name) \
	phalcon_return_property_quick(return_value, object, SL(member_name), zend_inline_hash_func(SS(member_name)) TSRMLS_CC); \
	return;

/**
 * Returns a zval in an object member (quick)
 */
#define RETURN_MEMBER_QUICK(object, member_name, key) \
 	phalcon_return_property_quick(return_value, object, SL(member_name), key TSRMLS_CC); \
	return;

/** Return without change return_value */
#define RETURN_MM() PHALCON_MM_RESTORE(); return;

/** Return null restoring memory frame */
#define RETURN_MM_NULL() PHALCON_MM_RESTORE(); RETURN_NULL();

/** Return bool restoring memory frame */
#define RETURN_MM_FALSE PHALCON_MM_RESTORE(); RETURN_FALSE;
#define RETURN_MM_TRUE PHALCON_MM_RESTORE(); RETURN_TRUE;

/** Return string restoring memory frame */
#define RETURN_MM_STRING(str, copy) PHALCON_MM_RESTORE(); RETURN_STRING(str, copy);
#define RETURN_MM_EMPTY_STRING() PHALCON_MM_RESTORE(); RETURN_EMPTY_STRING();

/** Return empty array */
#define RETURN_EMPTY_ARRAY() array_init(return_value); return;
#define RETURN_MM_EMPTY_ARRAY() PHALCON_MM_RESTORE(); RETURN_EMPTY_ARRAY();

#ifndef IS_INTERNED
#define IS_INTERNED(key) 0
#endif

/** Get the current hash key without copying the hash key */
#define PHALCON_GET_HKEY(var, hash, hash_position) \
	phalcon_get_current_key(&var, hash, &hash_position TSRMLS_CC);

/** Get current hash key copying the hash_value if needed */
#define PHALCON_GET_HMKEY(var, hash, hash_pointer) \
	{\
		int hash_type; \
		char *hash_index; \
		uint hash_index_len; \
		ulong hash_num; \
		 \
		PHALCON_INIT_NVAR(var); \
		hash_type = zend_hash_get_current_key_ex(hash, &hash_index, &hash_index_len, &hash_num, 0, &hash_pointer); \
		if (hash_type == HASH_KEY_IS_STRING) { \
			if (IS_INTERNED(hash_index)) { \
				ZVAL_STRINGL(var, hash_index, hash_index_len - 1, 0); \
			} else { \
				ZVAL_STRINGL(var, hash_index, hash_index_len - 1, 1); \
			} \
		} else { \
			if (hash_type == HASH_KEY_IS_LONG) { \
				ZVAL_LONG(var, hash_num); \
			}\
		}\
	}

/** Foreach */
#define PHALCON_GET_FOREACH_KEY(var, hash, hash_pointer) PHALCON_GET_HMKEY(var, hash, hash_pointer)

/** Check if an array is iterable or not */
#define phalcon_is_iterable(var, array_hash, hash_pointer, duplicate, reverse) if (!phalcon_is_iterable_ex(var, array_hash, hash_pointer, duplicate, reverse TSRMLS_CC)) { return; }

#define PHALCON_GET_FOREACH_VALUE(var) \
	PHALCON_OBSERVE_VAR(var); \
	var = *hd; \
	Z_ADDREF_P(var);

#define PHALCON_GET_HVALUE(var) \
	PHALCON_OBSERVE_VAR(var); \
	var = *hd; \
	Z_ADDREF_P(var);

/** class/interface registering */
#define PHALCON_REGISTER_CLASS(ns, class_name, name, methods, flags) \
	{ \
		zend_class_entry ce; \
		memset(&ce, 0, sizeof(zend_class_entry)); \
		INIT_NS_CLASS_ENTRY(ce, #ns, #class_name, methods); \
		phalcon_ ##name## _ce = zend_register_internal_class(&ce TSRMLS_CC); \
		phalcon_ ##name## _ce->ce_flags |= flags;  \
	}

#define PHALCON_REGISTER_CLASS_EX(ns, class_name, name, parent, methods, flags) \
	{ \
		zend_class_entry ce; \
		memset(&ce, 0, sizeof(zend_class_entry)); \
		INIT_NS_CLASS_ENTRY(ce, #ns, #class_name, methods); \
		phalcon_ ##name## _ce = zend_register_internal_class_ex(&ce, NULL, parent TSRMLS_CC); \
		if (!phalcon_ ##name## _ce) { \
			phalcon_inherit_not_found(parent, ZEND_NS_NAME(#ns, #class_name)); \
			return FAILURE;	\
		}  \
		phalcon_ ##name## _ce->ce_flags |= flags;  \
	}

#define PHALCON_REGISTER_INTERFACE(ns, classname, name, methods) \
	{ \
		zend_class_entry ce; \
		memset(&ce, 0, sizeof(zend_class_entry)); \
		INIT_NS_CLASS_ENTRY(ce, #ns, #classname, methods); \
		phalcon_ ##name## _ce = zend_register_internal_interface(&ce TSRMLS_CC); \
	}

#define PHALCON_REGISTER_INTERFACE_EX(ns, classname, name, parent, methods) \
	{ \
		zend_class_entry ce; \
		memset(&ce, 0, sizeof(zend_class_entry)); \
		INIT_NS_CLASS_ENTRY(ce, #ns, #classname, methods); \
		phalcon_ ##name## _ce = phalcon_register_internal_interface_ex(&ce, parent TSRMLS_CC); \
		if (!phalcon_ ##name## _ce) { \
			fprintf(stderr, "Can't register interface with parent: %s", parent); \
			return FAILURE;	\
		}  \
	}

/** Method declaration for API generation */
#define PHALCON_DOC_METHOD(class_name, method)

/** Low overhead parse/fetch parameters */
#define phalcon_fetch_params(memory_grow, required_params, optional_params, ...) \
	if (phalcon_fetch_parameters(memory_grow, ZEND_NUM_ARGS() TSRMLS_CC, required_params, optional_params, __VA_ARGS__) == FAILURE) { \
		if (memory_grow) { \
			RETURN_MM_NULL(); \
		} else { \
			RETURN_NULL(); \
		} \
	}

