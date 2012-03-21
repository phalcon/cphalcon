
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
#define PHALCON_DEBUG 0

#define PHALCON_NOISY_FETCH 0
#define PHALCON_SILENT_FETCH 1
#define PHALCON_WRITE_FETCH 2

#define PHALCON_CALL_CHECK 1
#define PHALCON_CALL_DEFAULT 0

#define PHALCON_METHOD_CTOR 1
#define PHALCON_METHOD_NORMAL 0

#define PHALCON_INVOKE_THIS 1
#define PHALCON_INVOKE_OTHER 0

#if defined(HAVE_SPL) && ((PHP_MAJOR_VERSION > 5) || (PHP_MAJOR_VERSION == 5 && PHP_MINOR_VERSION >= 1))
extern ZEND_API zend_class_entry *zend_ce_iterator;
extern ZEND_API zend_class_entry *zend_ce_arrayaccess;
extern PHPAPI zend_class_entry *spl_ce_RuntimeException;
extern PHPAPI zend_class_entry *spl_ce_Countable;
extern PHPAPI zend_class_entry *spl_ce_SeekableIterator;
#endif

/** Globals functions */
extern int phalcon_init_global(char *global TSRMLS_DC);
extern int phalcon_get_global(zval *arr, char *global, int global_type TSRMLS_DC);
extern int phalcon_get_global_by_index(char *global, char *index, zval *result TSRMLS_DC);

extern int phalcon_get_class_constant(zval *return_value, zend_class_entry *ce, char *constant_name, int constant_length TSRMLS_DC);

/** Add functions */
extern int phalcon_add_function(zval *result, zval *op1, zval *op2 TSRMLS_DC);

/** Logical functions */
extern int phalcon_and_function(zval *result, zval *left, zval *right);

/** Concat functions */
extern int phalcon_concat_right(zval *result, zval *op1, const char *op2, int op2_length TSRMLS_DC);
extern int phalcon_concat_left(zval *result, const char *op1, int op1_length, zval *op2 TSRMLS_DC);
extern int phalcon_concat_both(zval *result, const char *op1, int op1_length, zval *op2, const char *op3, int op3_length TSRMLS_DC);
extern int phalcon_concat_vboth(zval *result, zval *op1, const char *op2, int op2_length, zval *op3 TSRMLS_DC);

extern int phalcon_compare_strict_string(zval *op1, char *op2, int op2_length);
extern int phalcon_is_smaller_strict_long(zval *op1, long op2);
extern int phalcon_is_smaller_or_equal_strict_long(zval *op1, long op2);

extern int phalcon_file_exists(zval *filename TSRMLS_DC);
extern long phalcon_count(const zval *value);

/** Low level filters */
extern int phalcon_filter_alphanum(zval *result, zval *param);

/** Operators */
#define PHALCON_COMPARE_STRING(op1, op2) phalcon_compare_strict_string(op1, op2, strlen(op2))
#define PHALCON_CONCAT_RIGHT(result, op1, op2) phalcon_concat_right(result, op1, op2, strlen(op2) TSRMLS_CC)
#define PHALCON_CONCAT_LEFT(result, op1, op2) phalcon_concat_left(result, op1, strlen(op1), op2 TSRMLS_CC)
#define PHALCON_CONCAT_BOTH(result, op1, op2, op3) phalcon_concat_both(result, op1, strlen(op1), op2, op3, strlen(op3) TSRMLS_CC)
#define PHALCON_CONCAT_VBOTH(result, op1, op2, op3) phalcon_concat_vboth(result, op1, op2, strlen(op2), op3 TSRMLS_CC)

/** Constants */
#define PHALCON_GET_CONSTANT(var, name) PHALCON_VAR_INIT(var); zend_get_constant(name, strlen(name), var TSRMLS_CC)
#define PHALCON_GET_CLASS_CONSTANT(var, class_entry, name) PHALCON_VAR_INIT(var); phalcon_get_class_constant(var, class_entry, name, strlen(name) TSRMLS_CC)

/** Compatibility with 5.3 */
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

#ifndef PHP_FE_END
 #define PHP_FE_END { NULL, NULL, NULL, 0, 0 }
#endif

/** Symbols */
#define PHALCON_READ_SYMBOL(var, auxarr, name) if(EG(active_symbol_table)){\
			if(zend_hash_find(EG(active_symbol_table), name, sizeof(name), (void **)  &auxarr)==SUCCESS){\
				var = *auxarr;\
			} else {\
				ZVAL_NULL(var);\
			}\
		} else {\
			ZVAL_NULL(var);\
		}

/** Globals */
#define PHALCON_GET_GLOBAL(varr, nglobal, glovar)	phalcon_init_global(nglobal TSRMLS_CC);\
		if(&EG(symbol_table)){\
			if(zend_hash_find(&EG(symbol_table), nglobal, sizeof(nglobal), (void **) &glovar)==SUCCESS){\
				if(Z_TYPE_PP(glovar)==IS_ARRAY){\
					varr = *glovar;\
				} else {\
					PHALCON_INIT_ARRAY(varr);\
				}\
			}\
		} else {\
			PHALCON_INIT_ARRAY(varr);\
		}

#define PHALCON_RETURN_CHECK_CTOR(var) {\
		zend_uchar is_ref = Z_ISREF_P(return_value);\
		zend_uint refcount = Z_REFCOUNT_P(return_value);\
		*(return_value) = *(var);\
		if (Z_TYPE_P(var) > IS_BOOL) {\
			zval_copy_ctor(return_value);\
		}\
		Z_SET_ISREF_TO_P(return_value, is_ref);\
		Z_SET_REFCOUNT_P(return_value, refcount);\
	}\
	PHALCON_MM_RESTORE();\
	return;

#define PHALCON_RETURN_CTOR(var) {\
		zend_uchar is_ref = Z_ISREF_P(return_value);\
		zend_uint refcount = Z_REFCOUNT_P(return_value);\
		*(return_value) = *(var);\
		zval_copy_ctor(return_value);\
		Z_SET_ISREF_TO_P(return_value, is_ref);\
		Z_SET_REFCOUNT_P(return_value, refcount);\
	}\
	PHALCON_MM_RESTORE();\
	return;

#define PHALCON_RETURN_DZVAL(var) {\
		zend_uchar is_ref = Z_ISREF_P(return_value);\
		zend_uint refcount = Z_REFCOUNT_P(return_value);\
		*(return_value) = *(var);\
		zval_copy_ctor(return_value);\
		Z_SET_ISREF_TO_P(return_value, is_ref);\
		Z_SET_REFCOUNT_P(return_value, refcount);\
		PHALCON_MM_RESTORE();\
	}\
	return;

#define PHALCON_RETURN_NCTOR(var) {\
		zend_uchar is_ref = Z_ISREF_P(return_value);\
		zend_uint refcount = Z_REFCOUNT_P(return_value);\
		*(return_value) = *(var);\
		Z_SET_ISREF_TO_P(return_value, is_ref);\
		Z_SET_REFCOUNT_P(return_value, refcount);\
	}\
	PHALCON_MM_RESTORE();\
	return;

