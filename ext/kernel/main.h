
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

/** Main macros */
#define PH_DEBUG 0

#define PH_NOISY 0
#define PH_SILENT 1

#define PH_NOISY_CC PH_NOISY TSRMLS_CC
#define PH_SILENT_CC PH_SILENT TSRMLS_CC

#define PH_CHECK 1
#define PH_NO_CHECK 0

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
#endif

/** Startup functions */
extern void php_phalcon_init_globals(zend_phalcon_globals *phalcon_globals TSRMLS_DC);

/** Globals functions */
extern int phalcon_init_global(char *global, int global_length TSRMLS_DC);
extern int phalcon_get_global(zval **arr, char *global, int global_length TSRMLS_DC);
extern int phalcon_get_global_by_index(char *global, char *index, zval *result TSRMLS_DC);

extern int phalcon_file_exists(zval *filename TSRMLS_DC);
extern int phalcon_function_exists_ex(char *method_name, uint method_len TSRMLS_DC);

/** Count */
extern void phalcon_fast_count(zval *result, zval *array TSRMLS_DC);

/** Low level filters */
extern int phalcon_filter_alphanum(zval *result, zval *param);
extern int phalcon_filter_identifier(zval *result, zval *param);

/* Utils functions */
extern void phalcon_inherit_not_found(char *class_name, char *inherit_name);
extern int phalcon_valid_foreach(zval *arr TSRMLS_DC);

/** Export symbols to active symbol table */
extern int phalcon_set_symbol(zval *key_name, zval *value TSRMLS_DC);
extern int phalcon_set_symbol_str(char *key_name, int key_length, zval *value TSRMLS_DC);

/** Compatibility with PHP 5.3 */
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
#define PHALCON_READ_SYMBOL(var, auxarr, name) if(EG(active_symbol_table)){\
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
		*(return_value) = *(var); \
		phalcon_copy_ctor(return_value, var); \
		INIT_PZVAL(return_value) \
	} \
	PHALCON_MM_RESTORE(); \
	return;

/**
 * Return zval with always ctor, without restoring the memory stack
 */
#define RETURN_CTORW(var) { \
		*(return_value) = *(var); \
		phalcon_copy_ctor(return_value, var); \
		INIT_PZVAL(return_value) \
	} \
	return;

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

/** Foreach */
#define PHALCON_GET_FOREACH_KEY(var, hash, hash_pointer) \
	hash_type = zend_hash_get_current_key_ex(hash, &hash_index, &hash_index_len, &hash_num, 0, &hash_pointer); \
	if (hash_type == HASH_KEY_IS_STRING) { \
		ZVAL_STRINGL(var, hash_index, hash_index_len-1, 1); \
	} else { \
		if (hash_type == HASH_KEY_IS_LONG) { \
			ZVAL_LONG(var, hash_num); \
		}\
	}

#define PHALCON_GET_FOREACH_VALUE(var) \
	PHALCON_INIT_NVAR(var); \
	ZVAL_ZVAL(var, *hd, 1, 0);

/** class registering */
#define PHALCON_REGISTER_CLASS(ns, classname, name, methods, flags) \
	{ \
		zend_class_entry ce; \
		memset(&ce, 0, sizeof(zend_class_entry)); \
		INIT_NS_CLASS_ENTRY(ce, #ns, #classname, methods); \
		phalcon_ ##name## _ce = zend_register_internal_class(&ce TSRMLS_CC); \
		phalcon_ ##name## _ce->ce_flags |= flags;  \
	}

#define PHALCON_REGISTER_CLASS_EX(ns, class_name, name, parent, methods, flags) \
	{ \
		zend_class_entry ce; \
		memset(&ce, 0, sizeof(zend_class_entry)); \
		INIT_NS_CLASS_ENTRY(ce, #ns, #class_name, methods); \
		phalcon_ ##name## _ce = zend_register_internal_class_ex(&ce, NULL, parent TSRMLS_CC); \
		if(!phalcon_ ##name## _ce){ \
			phalcon_inherit_not_found(parent, ZEND_NS_NAME(#ns, #class_name)); \
			return FAILURE;	\
		}  \
		phalcon_ ##name## _ce->ce_flags |= flags;  \
	}
