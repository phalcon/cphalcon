
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

#define INIT_PARAM(x) ALLOC_ZVAL(x); INIT_PZVAL(x);

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

/** Logical functions */
extern int phalcon_and_function(zval *result, zval *left, zval *right);

/** Concat functions */
extern int phalcon_concat_right(zval *result, zval *op1, const char *op2 TSRMLS_DC);
extern int phalcon_concat_left(zval *result, const char *op1, zval *op2 TSRMLS_DC);
extern int phalcon_concat_both(zval *result, const char *op1, zval *op2, const char *op3 TSRMLS_DC);
extern int phalcon_concat_vboth(zval *result, zval *op1, const char *op2, zval *op3 TSRMLS_DC);

extern int phalcon_compare_strict_string(zval *op1, char *op2);

extern int phalcon_file_exists(zval *filename TSRMLS_DC);
extern long phalcon_count(const zval *value);

/** Low level filters */
extern int phalcon_filter_alphanum(zval **result, zval *param);

/** Memory macros */
#define PHALCON_ALLOC_ZVAL(z) \
	ALLOC_ZVAL(z); INIT_PZVAL(z);

/** Renew memory allocated on certain pointer doing copy-write if needed */
#define PHALCON_REALLOC_ZVAL(z) \
	if(Z_REFCOUNT_P(z)<=1){\
		FREE_ZVAL(z);\
		PHALCON_ALLOC_ZVAL(z);\
	} else {\
		SEPARATE_ZVAL(&z);\
	}\

/** Copy value on destiny making separation if needed  */
#define PHALCON_INIT_SEPARATE(destiny, value) \
	PHALCON_VAR_INIT(destiny);\
	ZVAL_ZVAL(destiny, value, 1, 0);\
	Z_DELREF_P(value);\
	Z_SET_REFCOUNT_P(destiny, 1);

/** Do/Renew memory allocation for zval used as a result */
#define PHALCON_RESULT_INIT(var) \
	if(!var){\
		PHALCON_ALLOC_ZVAL(var);\
	} else {\
		PHALCON_REALLOC_ZVAL(var);\
	}

/** Do/Renew memory allocation for zval used as a var */
#define PHALCON_VAR_INIT(var) \
	if(!var){\
		PHALCON_ALLOC_ZVAL(var);\
	} else {\
		PHALCON_REALLOC_ZVAL(var);\
	}

/** Do/Renew memory allocation for zval used only if data-type has changed */
#define PHALCON_TYPEVAR_INIT(var, type) \
	if(!var){\
		PHALCON_ALLOC_ZVAL(var);\
	} else {\
		if(Z_REFCOUNT_P(var)>1){\
			SEPARATE_ZVAL(&var);\
		} else {\
			if(Z_TYPE_P(var)!=type){\
				FREE_ZVAL(var);\
				PHALCON_ALLOC_ZVAL(var);\
			}\
		}\
	}

/** Do/Renew memory allocation for zval used only if data-type isn't long */
#define PHALCON_LVAR_INIT(var) PHALCON_TYPEVAR_INIT(var, IS_LONG);

/** Do/Renew memory allocation for zval used only on binary operations (expect data-type will not change) */
#define PHALCON_BRESULT_INIT(var) \
	if(!var){\
		PHALCON_ALLOC_ZVAL(var);\
	} else {\
		if(Z_REFCOUNT_P(var)>1){\
			SEPARATE_ZVAL(&var);\
		}\
	}

/** Do zval assignment doing separation on destiny or value if needed */
#define PHALCON_CPY_WRT(destiny, value) \
	if(!destiny||Z_REFCOUNT_P(value)==1){\
		Z_ADDREF_P(value);\
		destiny = value;\
	} else {\
		PHALCON_INIT_SEPARATE(destiny, value);\
	}

/** Frees memory if is posible */
#define PHALCON_FREE(v) if(v){\
	if(Z_REFCOUNT_P(v)<=1){\
		FREE_ZVAL(v);\
		v = NULL;\
	} else {\
		Z_DELREF_P(v);\
	}\
}

/** Frees and destroys asociated memory */
#define PHALCON_DFREE(v) if(v){\
	if(Z_REFCOUNT_P(v)<=1){\
		zval_ptr_dtor(&v);\
		FREE_ZVAL(v);\
		v = NULL;\
	} else {\
		Z_DELREF_P(v);\
	}\
}

#define PHALCON_DELREF(v) if(v){\
	Z_DELREF_P(v);\
}

/** Control flow macros */
#define FOREACH_KV(var, varcopy, slabel, elabel, arrval, pointer, key, value) \
			if(Z_TYPE_P(var)!=IS_ARRAY){\
               zend_error(E_WARNING, "Invalid argument supplied for foreach()");\
			} else {\
				if(!value){\
					PHALCON_ALLOC_ZVAL(value);\
				} else {\
					PHALCON_REALLOC_ZVAL(value);\
				}\
				PHALCON_ALLOC_ZVAL(varcopy);\
				ZVAL_ZVAL(varcopy, var, 1, 0);\
				Z_SET_REFCOUNT_P(varcopy, 1);\
				arrval = Z_ARRVAL_P(varcopy);\
				zend_hash_internal_pointer_reset_ex(arrval, &pointer);\
				slabel:\
				if(zend_hash_get_current_data_ex(arrval, (void**) &hd, &pointer) != SUCCESS){\
					goto elabel;\
				} else {\
					if(!key){\
						PHALCON_ALLOC_ZVAL(key);\
					} else {\
						PHALCON_REALLOC_ZVAL(key);\
					}\
					htype = zend_hash_get_current_key_ex(arrval, &index, &index_len, &num, 0, &pointer);\
					if(htype==HASH_KEY_IS_STRING){\
						ZVAL_STRING(key, index, 0);\
					} else {\
						if(htype==HASH_KEY_IS_LONG){\
							ZVAL_LONG(key, num);\
						}\
					}\
				}\
				*value = **hd;

#define FOREACH_V(var, varcopy, slabel, elabel, arrval, pointer, value) \
		if(Z_TYPE_P(var)!=IS_ARRAY){\
			zend_error(E_WARNING, "Invalid argument supplied for foreach()");\
		} else {\
			if(!value) PHALCON_ALLOC_ZVAL(value);\
			PHALCON_ALLOC_ZVAL(varcopy);\
			ZVAL_ZVAL(varcopy, var, 1, 0);\
			arrval = Z_ARRVAL_P(varcopy);\
			zend_hash_internal_pointer_reset_ex(arrval, &pointer);\
			slabel:\
			if(zend_hash_get_current_data_ex(arrval, (void**) &hd, &pointer) != SUCCESS){\
				goto elabel;\
			}\
			*value = **hd;

#define END_FOREACH(varcopy, slabel, elabel, arrval, pointer) zend_hash_move_forward_ex(arrval, &pointer);\
		goto slabel;\
		elabel:\
		Z_DELREF_P(varcopy);\
		PHALCON_FREE(varcopy);\
		}


/** Variables */
#define PHALCON_SET_LONG(var, vlong) PHALCON_LVAR_INIT(var); ZVAL_LONG(var, vlong)
#define PHALCON_SET_STRING(var, str, alloc) PHALCON_VAR_INIT(var); ZVAL_STRING(var, str, alloc)
#define PHALCON_SET_STRINGL(var, str, length, alloc) PHALCON_VAR_INIT(var); ZVAL_STRINGL(var, str, length, alloc)
#define PHALCON_SET_DOUBLE(var, vdouble) PHALCON_VAR_INIT(var); ZVAL_DOUBLE(var, vdouble)
#define PHALCON_INIT_NULL(var) PHALCON_VAR_INIT(var); ZVAL_NULL(var)
#define PHALCON_INIT_BOOL(var, bvalue) PHALCON_VAR_INIT(var); ZVAL_BOOL(var, bvalue)
#define PHALCON_INIT_FALSE(var) PHALCON_VAR_INIT(var); ZVAL_BOOL(var, 0)
#define PHALCON_INIT_TRUE(var) PHALCON_VAR_INIT(var); ZVAL_BOOL(var, 1)
#define PHALCON_INIT_ZVAL(var, value) PHALCON_VAR_INIT(var, value);
#define PHALCON_INIT_ARRAY(var) PHALCON_VAR_INIT(var); array_init(var)

/** Function and method params */
#define PHALCON_PARAM_STRING(param, str, cpy) INIT_PARAM(param); ZVAL_STRING(param, str, cpy)
#define PHALCON_PARAM_LONG(param, vlong) INIT_PARAM(param); ZVAL_LONG(param, vlong)
#define PHALCON_PARAM_DOUBLE(param, vdouble) INIT_PARAM(param); ZVAL_DOUBLE(param, vdouble)
#define PHALCON_PARAM_BOOL(var, bvalue) INIT_PARAM(var); ZVAL_BOOL(var, bvalue)
#define PHALCON_PARAM_NULL(var) INIT_PARAM(var); ZVAL_NULL(var)
#define PHALCON_PARAM_ZVAL(param, value) INIT_PARAM(param); ZVAL_ZVAL(param, value, 1, 0)
#define PHALCON_PARAM_CPY(param, value) Z_ADDREF_P(value); param = value;

/** Operators */
#define PHALCON_EQUAL_FUNCTION(result, op1, op2) PHALCON_BRESULT_INIT(result); is_equal_function(result, op1, op2 TSRMLS_CC)
#define PHALCON_NOT_EQUAL_FUNCTION(result, op1, op2) PHALCON_BRESULT_INIT(result); is_not_equal_function(result, op1, op2 TSRMLS_CC)
#define PHALCON_SMALLER_EQUAL_FUNCTION(result, op1, op2) PHALCON_BRESULT_INIT(result); is_smaller_or_equal_function(result, op1, op2 TSRMLS_CC)
#define PHALCON_SMALLER_FUNCTION(result, op1, op2) PHALCON_BRESULT_INIT(result); is_smaller_function(result, op1, op2 TSRMLS_CC)
#define PHALCON_IDENTICAL_FUNCTION(result, op1, op2) PHALCON_BRESULT_INIT(result); is_identical_function(result, op1, op2 TSRMLS_CC)
#define PHALCON_NOT_IDENTICAL_FUNCTION(result, op1, op2) PHALCON_BRESULT_INIT(result); is_not_identical_function(result, op1, op2 TSRMLS_CC)

#define PHALCON_ADD_FUNCTION(result, op1, op2) PHALCON_BRESULT_INIT(result); add_function(result, op1, op2 TSRMLS_CC)
#define PHALCON_SUB_FUNCTION(result, op1, op2) PHALCON_BRESULT_INIT(result); sub_function(result, op1, op2 TSRMLS_CC)
#define PHALCON_MUL_FUNCTION(result, op1, op2) PHALCON_BRESULT_INIT(result); mul_function(result, op1, op2 TSRMLS_CC)
#define PHALCON_DIV_FUNCTION(result, op1, op2) PHALCON_BRESULT_INIT(result); div_function(result, op1, op2 TSRMLS_CC)
#define PHALCON_MOD_FUNCTION(result, op1, op2) PHALCON_BRESULT_INIT(result); mod_function(result, op1, op2 TSRMLS_CC)
#define PHALCON_CONCAT_FUNCTION(result, op1, op2) PHALCON_BRESULT_INIT(result); concat_function(result, op1, op2 TSRMLS_CC)

#define PHALCON_BITWISE_OR_FUNCTION(result, op1, op2) PHALCON_BRESULT_INIT(result); bitwise_or_function(result, op1, op2 TSRMLS_CC)
#define PHALCON_BITWISE_AND_FUNCTION(result, op1, op2) PHALCON_BRESULT_INIT(result); bitwise_and_function(result, op1, op2 TSRMLS_CC)

#define PHALCON_AND_FUNCTION(result, op1, op2) PHALCON_BRESULT_INIT(result); phalcon_and_function(result, op1, op2)
#define PHALCON_OR_FUNCTION(result, op1, op2) PHALCON_BRESULT_INIT(result); ZVAL_BOOL(result, zend_is_true(op1) || zend_is_true(op2))

#define PHALCON_BOOLEAN_NOT_FUNCTION(result, op1) PHALCON_BRESULT_INIT(result); boolean_not_function(result, op1 TSRMLS_CC)

/** Constants */
#define PHALCON_GET_CONSTANT(var, name) PHALCON_VAR_INIT(var); zend_get_constant(name, strlen(name), var TSRMLS_CC)
#define PHALCON_GET_CLASS_CONSTANT(var, class_entry, name) PHALCON_VAR_INIT(var); phalcon_get_class_constant(var, class_entry, name, strlen(name) TSRMLS_CC)

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
