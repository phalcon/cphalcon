
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

  +------------------------------------------------------------------------+
  | Zend Engine                                                            |
  +------------------------------------------------------------------------+
  | Copyright (c) 1998-2011 Zend Technologies Ltd. (http://www.zend.com)   |
  +------------------------------------------------------------------------+
  | This source file is subject to version 2.00 of the Zend license,       |
  | that is bundled with this package in the file LICENSE, and is          |
  | available through the world-wide-web at the following url:             |
  | http://www.zend.com/license/2_00.txt.                                  |
  | If you did not receive a copy of the Zend license and are unable to    |
  | obtain it through the world-wide-web, please send a note to            |
  | license@zend.com so we can mail you a copy immediately.                |
  +------------------------------------------------------------------------+
  | Authors: Andi Gutmans <andi@zend.com>                                  |
  |          Zeev Suraski <zeev@zend.com>                                  |
  |          Andrei Zmievski <andrei@php.net>                              |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/debug.h"
#include "zend_exceptions.h"

/**
 * Finds the correct scope to execute the function
 */
int phalcon_find_scope(zend_class_entry *ce, char *method_name TSRMLS_DC){

	const zend_function_entry *functions;
	int method_len = strlen(method_name);

	while (ce) {
		if (ce->builtin_functions) {
			functions = ce->builtin_functions;
			while (functions->fname) {
				if (!zend_binary_strcasecmp(functions->fname, strlen(functions->fname), method_name, method_len)) {
					EG(scope) = ce;
					return SUCCESS;
				}
				functions++;
			}
		}
		ce = ce->parent;
	}
	return FAILURE;
}

/**
 * Find function scope on parent classes
 */
int phalcon_find_parent_scope(zend_class_entry *ce, char *active_class, char *method_name TSRMLS_DC){

	const zend_function_entry *functions;
	int method_len = strlen(method_name);
	int active_class_len = strlen(active_class);

	while (ce) {
		//fprintf(stderr, "%s/%s\n", active_class, ce->name);
		if (!zend_binary_strcasecmp(ce->name, strlen(ce->name), active_class, active_class_len)) {
			if (ce->builtin_functions) {
				functions = ce->builtin_functions;
				while (functions->fname) {
					//fprintf(stderr, " %s <> %s\n", functions->fname, method_name);
					if (!zend_binary_strcasecmp(functions->fname, strlen(functions->fname), method_name, method_len)) {
						EG(scope) = ce;
						return SUCCESS;
					}
					functions++;
				}
			}
		}
		ce = ce->parent;
	}
	return FAILURE;
}

/**
 * Call single function which not requires parameters
 */
int phalcon_call_func(zval *return_value, char *func_name, int noreturn TSRMLS_DC){

	zval *fn = NULL;
	int status = FAILURE;

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}

	PHALCON_SET_STRING(fn, func_name, 0);
	status = phalcon_call_user_function(CG(function_table), NULL, fn, return_value, 0, NULL TSRMLS_CC);
	if (status == FAILURE) {
		zend_error_noreturn(E_ERROR, "Call to undefined function %s()", func_name);
		return FAILURE;
	}

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	return status;
}

/**
 * Call single function which requires parameters
 */
int phalcon_call_func_params(zval *return_value, char *func_name, int param_count, zval *params[], int noreturn TSRMLS_DC){

	zval *fn = NULL;
	int status = FAILURE;

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}

	PHALCON_SET_STRING(fn, func_name, 0);
	status = phalcon_call_user_function(CG(function_table), NULL, fn, return_value, param_count, params TSRMLS_CC);
	if (status == FAILURE) {
		zend_error_noreturn(E_ERROR, "Call to undefined function %s()", func_name);
		return FAILURE;
	}

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	return status;
}

/**
 * Call method on an object which not requires parameters
 *
 */
int phalcon_call_method(zval *return_value, zval *object, char *method_name, int check, int noreturn TSRMLS_DC){

	zval *fn = NULL;
	int status = FAILURE;
	zend_class_entry *active_scope = NULL;

	if (check) {
		if (!zend_hash_exists(&Z_OBJCE_P(object)->function_table, method_name, strlen(method_name)+1)) {
			return FAILURE;
		}
	}

	if(!noreturn){
		ALLOC_INIT_ZVAL(return_value);
	}

	PHALCON_SET_STRING(fn, method_name, 0);
	if (Z_TYPE_P(object) == IS_OBJECT) {
		active_scope = EG(scope);
		phalcon_find_scope(Z_OBJCE_P(object), method_name TSRMLS_CC);
		status = call_user_function(&Z_OBJCE_P(object)->function_table, &object, fn, return_value, 0, NULL TSRMLS_CC);
		if (status == FAILURE) {
			zend_error_noreturn(E_ERROR, "Call to undefined method %s()", Z_STRVAL_P(fn));
			return FAILURE;
		}
		EG(scope) = active_scope;
	} else {
		zend_error_noreturn(E_ERROR, "Call to method %s() on a non object", Z_STRVAL_P(fn));
		return FAILURE;
	}

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	return status;
}

/**
 * Call method on an object which requires parameters
 *
 */
int phalcon_call_method_params(zval *return_value, zval *object, char *method_name, int param_count, zval *params[], int check, int noreturn TSRMLS_DC){

	zval *fn = NULL;
	int status = FAILURE;
	zend_class_entry *active_scope = NULL;

	if (check) {
		if (!zend_hash_exists(&Z_OBJCE_P(object)->function_table, method_name, strlen(method_name)+1)) {
			return FAILURE;
		}
	}

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}

	PHALCON_SET_STRING(fn, method_name, 1);
	if (Z_TYPE_P(object) == IS_OBJECT) {
		active_scope = EG(scope);
		phalcon_find_scope(Z_OBJCE_P(object), method_name TSRMLS_CC);
		status = phalcon_call_user_function(&Z_OBJCE_P(object)->function_table, &object, fn, return_value, param_count, params TSRMLS_CC);
		if(status==FAILURE){
			EG(scope) = active_scope;
			zend_error_noreturn(E_ERROR, "Call to undefined method %s() on class %s", Z_STRVAL_P(fn), Z_OBJCE_P(object)->name);
			return FAILURE;
		}
		EG(scope) = active_scope;
	} else {
		zend_error_noreturn(E_ERROR, "Call to method %s() on a non object", Z_STRVAL_P(fn));
		return FAILURE;
	}

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	return status;
}

/**
 * Call parent static function which not requires parameters
 */
int phalcon_call_parent_func(zval *return_value, zval *object, char *active_class, char *method_name, int noreturn TSRMLS_DC){

	int success;
	zend_class_entry *active_scope = NULL;

	if (object) {
		active_scope = EG(scope);
		phalcon_find_parent_scope(Z_OBJCE_P(object), active_class, method_name TSRMLS_CC);
	}

	success = phalcon_call_static_func(return_value, "parent", method_name, noreturn TSRMLS_CC);

	if (object) {
		EG(scope) = active_scope;
	}

	return success;
}

/**
 * Call parent static function which requires parameters
 */
int phalcon_call_parent_func_params(zval *return_value, zval *object, char *active_class, char *method_name, int param_count, zval *params[], int noreturn TSRMLS_DC){

	int success;
	zend_class_entry *active_scope = NULL;

	if (object) {
		active_scope = EG(scope);
		phalcon_find_parent_scope(Z_OBJCE_P(object), active_class, method_name TSRMLS_CC);
	}

	success = phalcon_call_static_func_params(return_value, "parent", method_name, param_count, params, noreturn TSRMLS_CC);
	if (object) {
		EG(scope) = active_scope;
	}

	return success;
}

/**
 * Call self-class static function which not requires parameters
 */
int phalcon_call_self_func(zval *return_value, zval *object, char *method_name, int noreturn TSRMLS_DC){

	int success;
	zend_class_entry *active_scope = NULL;

	if (object) {
		active_scope = EG(scope);
		phalcon_find_scope(Z_OBJCE_P(object), method_name TSRMLS_CC);
	}

	success = phalcon_call_static_func(return_value, "self", method_name, noreturn TSRMLS_CC);

	if (object) {
		EG(scope) = active_scope;
	}

	return success;
}

/**
 * Call self-class static function which requires parameters
 */
int phalcon_call_self_func_params(zval *return_value, zval *object, char *method_name, int param_count, zval *params[], int noreturn TSRMLS_DC){

	int success;
	zend_class_entry *active_scope = NULL;

	if (object) {
		active_scope = EG(scope);
		phalcon_find_scope(Z_OBJCE_P(object), method_name TSRMLS_CC);
	}

	success = phalcon_call_static_func_params(return_value, "self", method_name, param_count, params, noreturn TSRMLS_CC);

	if (object) {
		EG(scope) = active_scope;
	}

	return success;
}

/**
 * Call single static function which not requires parameters
 */
int phalcon_call_static_func(zval *return_value, char *class_name, char *method_name, int noreturn TSRMLS_DC){

	zval *fn;
	int status = FAILURE;

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}

	ALLOC_INIT_ZVAL(fn);
	array_init(fn);
	add_next_index_string(fn, class_name, 0);
	add_next_index_string(fn, method_name, 0);
	status = phalcon_call_user_function(CG(function_table), NULL, fn, return_value, 0, NULL TSRMLS_CC);
	if (status==FAILURE) {
		zend_error_noreturn(E_ERROR, "Call to undefined function %s::%s()", class_name, method_name);
		return FAILURE;
	}

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	return status;
}

/**
 * Call single static function on a zval which not requires parameters
 */
int phalcon_call_static_zval_func(zval *return_value, zval *mixed_name, char *method_name, int noreturn TSRMLS_DC){
	
	zval *fn;
	int status = FAILURE;

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}
	
	ALLOC_INIT_ZVAL(fn);
	array_init(fn);
	add_next_index_zval(fn, mixed_name);
	add_next_index_string(fn, method_name, 0);
	status = phalcon_call_user_function(CG(function_table), NULL, fn, return_value, 0, NULL TSRMLS_CC);
	if (status==FAILURE) {
		if(Z_TYPE_P(mixed_name) == IS_STRING) {
			zend_error_noreturn(E_ERROR, "Call to undefined function %s::%s()", Z_STRVAL_P(mixed_name), method_name);
		} else {
			zend_error_noreturn(E_ERROR, "Call to undefined function %s()", method_name);
		}
		return FAILURE;
	}

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	return status;
}

/**
 * Call single function which requires parameters
 */
int phalcon_call_static_func_params(zval *return_value, char *class_name, char *method_name, int param_count, zval *params[], int noreturn TSRMLS_DC){

	zval *fn;
	int status = FAILURE;

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}

	ALLOC_INIT_ZVAL(fn);
	array_init(fn);
	add_next_index_string(fn, class_name, 0);
	add_next_index_string(fn, method_name, 0);
	status = phalcon_call_user_function(CG(function_table), NULL, fn, return_value, param_count, params TSRMLS_CC);
	if (status==FAILURE) {
		zend_error_noreturn(E_ERROR, "Call to undefined function %s::%s()", class_name, method_name);
		return FAILURE;
	}

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	return status;
}

/**
 * Call single function on zval which requires parameters
 */
int phalcon_call_static_func_zval_params(zval *return_value, zval *mixed_name, char *method_name, int param_count, zval *params[], int noreturn TSRMLS_DC){

	int status = FAILURE;

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}
	
	status = phalcon_call_user_function(CG(function_table), NULL, mixed_name, return_value, param_count, params TSRMLS_CC);
	if (status==FAILURE) {
		if(Z_TYPE_P(mixed_name) == IS_STRING) {
			zend_error_noreturn(E_ERROR, "Call to undefined function %s::%s()", Z_STRVAL_P(mixed_name), method_name);
		} else {
			zend_error_noreturn(E_ERROR, "Call to undefined function %s()", method_name);
		}
		return FAILURE;
	}

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	return status;
}

static inline zend_function *phalcon_check_private_int(zend_function *fbc, zend_class_entry *ce, char *function_name_strval, int function_name_strlen TSRMLS_DC){

	int result;

	if (!ce) {
		return 0;
	}

	/* We may call a private function if:
	 * 1.  The class of our object is the same as the scope, and the private
	 *     function (EX(fbc)) has the same scope.
	 * 2.  One of our parent classes are the same as the scope, and it contains
	 *     a private function with the same name that has the same scope.
	 */
	if (fbc->common.scope == ce && EG(scope) == ce) {
		/* rule #1 checks out ok, allow the function call */
		return fbc;
	}

	/* Check rule #2 */
	ce = ce->parent;
	while (ce) {
		if (PHALCON_DEBUG) {
			fprintf(stderr, "Comparing %s with %s", ce->name, EG(scope)->name);
		}
		if (ce==EG(scope)) {
			result = zend_hash_find(&ce->function_table, function_name_strval, function_name_strlen+1, (void **) &fbc)==SUCCESS
				&& fbc->op_array.fn_flags & ZEND_ACC_PRIVATE
				&& fbc->common.scope == EG(scope);
			if(result){
				return fbc;
			}
			break;
		}
		ce = ce->parent;
	}
	return NULL;
}

int phalcon_check_private(zend_function *fbc, zend_class_entry *ce, char *function_name_strval, int function_name_strlen TSRMLS_DC){
	return phalcon_check_private_int(fbc, ce, function_name_strval, function_name_strlen TSRMLS_CC) != NULL;
}

/**
 * Checks if a class method is callable
 */
int phalcon_is_callable_check_class(const char *name, int name_len, zend_fcall_info_cache *fcc, int *strict_class, char **error TSRMLS_DC){

	int ret = 0;
	zend_class_entry **pce;
	char *lcname = zend_str_tolower_dup(name, name_len);

	*strict_class = 0;
	if (name_len == sizeof("self") - 1 && !memcmp(lcname, "self", sizeof("self") - 1)) {
		if(!EG(scope)){
			if(error){
				*error = estrdup("cannot access self:: when no class scope is active");
			}
		} else {
			fcc->called_scope = EG(called_scope);
			fcc->calling_scope = EG(scope);
			if (!fcc->object_ptr) {
				fcc->object_ptr = EG(This);
			}
			ret = 1;
		}
	} else {
		if (name_len == sizeof("parent") - 1 && !memcmp(lcname, "parent", sizeof("parent") - 1)) {
			if(!EG(scope)){
				if(error){
					*error = estrdup("cannot access parent:: when no class scope is active");
				}
			} else {
				if(!EG(scope)->parent){
					if(error){
						*error = estrdup("cannot access parent:: when current class scope has no parent");
					}
				} else {
					fcc->called_scope = EG(called_scope);
					fcc->calling_scope = EG(scope)->parent;
					if(!fcc->object_ptr){
						fcc->object_ptr = EG(This);
					}
					*strict_class = 1;
					ret = 1;
				}
			}
		} else {
			if (name_len == sizeof("static") - 1 && !memcmp(lcname, "static", sizeof("static") - 1)) {
				if (!EG(called_scope)) {
					if (error) *error = estrdup("cannot access static:: when no class scope is active");
				} else {
					fcc->called_scope = EG(called_scope);
					fcc->calling_scope = EG(called_scope);
					if(!fcc->object_ptr){
						fcc->object_ptr = EG(This);
					}
					*strict_class = 1;
					ret = 1;
				}
			} else {
				if(zend_lookup_class_ex(name, name_len, 1, &pce TSRMLS_CC) == SUCCESS){
					zend_class_entry *scope = EG(active_op_array) ? EG(active_op_array)->scope : NULL;

					fcc->calling_scope = *pce;
					if(scope && !fcc->object_ptr && EG(This) &&
					    instanceof_function(Z_OBJCE_P(EG(This)), scope TSRMLS_CC) &&
					    instanceof_function(scope, fcc->calling_scope TSRMLS_CC)) {
						fcc->object_ptr = EG(This);
						fcc->called_scope = Z_OBJCE_P(fcc->object_ptr);
					} else {
						fcc->called_scope = fcc->object_ptr ? Z_OBJCE_P(fcc->object_ptr) : fcc->calling_scope;
					}
					*strict_class = 1;
					ret = 1;
				} else {
					if (error) {
						phalcon_spprintf(error, 0, "class '%.*s' not found", name_len, name);
					}
				}
			}
		}
	}
	efree(lcname);
	return ret;
}

int phalcon_is_callable_check_func(int check_flags, zval *callable, zend_fcall_info_cache *fcc, int strict_class, char **error TSRMLS_DC){

	zend_class_entry *ce_org = fcc->calling_scope;
	int retval = 0;
	char *mname, *lmname, *colon;
	int clen, mlen, result;
	zend_class_entry *last_scope;
	HashTable *ftable;
	int call_via_handler = 0;
	zend_class_entry *scope;

	if (error) {
		*error = NULL;
	}

	fcc->calling_scope = NULL;
	fcc->function_handler = NULL;

	if(!ce_org){
		/* Skip leading \ */
		if(Z_STRVAL_P(callable)[0] == '\\'){
			mlen = Z_STRLEN_P(callable) - 1;
			mname = Z_STRVAL_P(callable) + 1;
			lmname = zend_str_tolower_dup(Z_STRVAL_P(callable) + 1, mlen);
		} else {
			mlen = Z_STRLEN_P(callable);
			mname = Z_STRVAL_P(callable);
			lmname = zend_str_tolower_dup(Z_STRVAL_P(callable), mlen);
		}
		/* Check if function with given name exists.
		 * This may be a compound name that includes namespace name */
		if (zend_hash_find(EG(function_table), lmname, mlen+1, (void**)&fcc->function_handler) == SUCCESS) {
			efree(lmname);
			return 1;
		}
		efree(lmname);
	}

	/* Split name into class/namespace and method/function names */
	result = (colon = zend_memrchr(Z_STRVAL_P(callable), ':', Z_STRLEN_P(callable))) != NULL && colon > Z_STRVAL_P(callable) && *(colon-1) == ':';
	if(result){
		colon--;
		clen = colon - Z_STRVAL_P(callable);
		mlen = Z_STRLEN_P(callable) - clen - 2;

		if(colon == Z_STRVAL_P(callable)){
			if(error){
				phalcon_spprintf(error, 0, "invalid function name");
			}
			return 0;
		}

		/* This is a compound name.
		 * Try to fetch class and then find static method. */
		last_scope = EG(scope);
		if(ce_org){
			EG(scope) = ce_org;
			if(PHALCON_DEBUG){
				fprintf(stderr, "ScopeAddress=%p\n", EG(scope));
			}
		}

		if(!phalcon_is_callable_check_class(Z_STRVAL_P(callable), clen, fcc, &strict_class, error TSRMLS_CC)){
			EG(scope) = last_scope;
			if(PHALCON_DEBUG){
				fprintf(stderr, "ScopeAddress=%p\n", EG(scope));
			}
			return 0;
		}
		EG(scope) = last_scope;
		if(PHALCON_DEBUG){
			fprintf(stderr, "ScopeAddress=%p\n", last_scope);
		}

		ftable = &fcc->calling_scope->function_table;
		if(ce_org && !instanceof_function(ce_org, fcc->calling_scope TSRMLS_CC)){
			if (error) phalcon_spprintf(error, 0, "class '%s' is not a subclass of '%s'", ce_org->name, fcc->calling_scope->name);
			return 0;
		}
		mname = Z_STRVAL_P(callable) + clen + 2;
	} else {
		if (ce_org) {
			/* Try to fetch find static method of given class. */
			mlen = Z_STRLEN_P(callable);
			mname = Z_STRVAL_P(callable);
			ftable = &ce_org->function_table;
			fcc->calling_scope = ce_org;
		} else {
			/* We already checked for plain function before. */
			if(error && !(check_flags & IS_CALLABLE_CHECK_SILENT)){
				phalcon_spprintf(error, 0, "function '%s' not found or invalid function name", Z_STRVAL_P(callable));
			}
			return 0;
		}
	}

	lmname = zend_str_tolower_dup(mname, mlen);
	//fprintf(stderr, "%s\n", lmname);
	//fprintf(stderr, " => ");

	result = strict_class && fcc->calling_scope && mlen == sizeof(ZEND_CONSTRUCTOR_FUNC_NAME)-1 && !memcmp(lmname, ZEND_CONSTRUCTOR_FUNC_NAME, sizeof(ZEND_CONSTRUCTOR_FUNC_NAME));
	//fprintf(stderr, "%d => ", result);

	if(result){
		fcc->function_handler = fcc->calling_scope->constructor;
		if(fcc->function_handler){
			retval = 1;
		}
	} else {
		result = (zend_hash_find(ftable, lmname, mlen+1, (void**)&fcc->function_handler) == SUCCESS);
		if(result){

			//fprintf(stderr, "%d => ", result);

			retval = 1;
			result = (fcc->function_handler->op_array.fn_flags & ZEND_ACC_CHANGED) && EG(scope) && instanceof_function(fcc->function_handler->common.scope, EG(scope) TSRMLS_CC);
			if(result){
				zend_function *priv_fbc;
				if(zend_hash_find(&EG(scope)->function_table, lmname, mlen+1, (void **) &priv_fbc)==SUCCESS
					&& priv_fbc->common.fn_flags & ZEND_ACC_PRIVATE
					&& priv_fbc->common.scope == EG(scope)) {
					fcc->function_handler = priv_fbc;
				}
			}

			result = (check_flags & IS_CALLABLE_CHECK_NO_ACCESS) == 0 && (fcc->calling_scope && (fcc->calling_scope->__call || fcc->calling_scope->__callstatic));
			//fprintf(stderr, "%d => ", result);

			if(result){
				if(fcc->function_handler->op_array.fn_flags & ZEND_ACC_PRIVATE){
					if(!phalcon_check_private(fcc->function_handler, fcc->object_ptr ? Z_OBJCE_P(fcc->object_ptr) : EG(scope), lmname, mlen TSRMLS_CC)){
						retval = 0;
						fcc->function_handler = NULL;
						goto get_function_via_handler;
					}
				} else {
					if(fcc->function_handler->common.fn_flags & ZEND_ACC_PROTECTED){
						if(!zend_check_protected(fcc->function_handler->common.scope, EG(scope))){
							retval = 0;
							fcc->function_handler = NULL;
							goto get_function_via_handler;
						}
					}
				}
			}
		} else {

			get_function_via_handler:
			if (fcc->object_ptr && fcc->calling_scope == ce_org) {
				if (strict_class && ce_org->__call) {
					fcc->function_handler = emalloc(sizeof(zend_internal_function));
					fcc->function_handler->internal_function.type = ZEND_INTERNAL_FUNCTION;
					fcc->function_handler->internal_function.module = ce_org->module;
					fcc->function_handler->internal_function.handler = zend_std_call_user_call;
					fcc->function_handler->internal_function.arg_info = NULL;
					fcc->function_handler->internal_function.num_args = 0;
					fcc->function_handler->internal_function.scope = ce_org;
					fcc->function_handler->internal_function.fn_flags = ZEND_ACC_CALL_VIA_HANDLER;
					fcc->function_handler->internal_function.function_name = estrndup(mname, mlen);
					fcc->function_handler->internal_function.pass_rest_by_reference = 0;
					fcc->function_handler->internal_function.return_reference = ZEND_RETURN_VALUE;
					call_via_handler = 1;
					retval = 1;
				} else if (Z_OBJ_HT_P(fcc->object_ptr)->get_method) {
					fcc->function_handler = Z_OBJ_HT_P(fcc->object_ptr)->get_method(&fcc->object_ptr, mname, mlen TSRMLS_CC);
					if (fcc->function_handler) {
						if (strict_class &&
						    (!fcc->function_handler->common.scope ||
						     !instanceof_function(ce_org, fcc->function_handler->common.scope TSRMLS_CC))) {
							if ((fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER) != 0) {
								if (fcc->function_handler->type != ZEND_OVERLOADED_FUNCTION) {
									efree(fcc->function_handler->common.function_name);
								}
								efree(fcc->function_handler);
							}
						} else {
							retval = 1;
							call_via_handler = (fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER) != 0;
						}
					}
				}
			} else if (fcc->calling_scope) {
				if (fcc->calling_scope->get_static_method) {
					fcc->function_handler = fcc->calling_scope->get_static_method(fcc->calling_scope, mname, mlen TSRMLS_CC);
				} else {
					fcc->function_handler = zend_std_get_static_method(fcc->calling_scope, mname, mlen TSRMLS_CC);
				}
				if (fcc->function_handler) {
					retval = 1;
					call_via_handler = (fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER) != 0;
					if (call_via_handler && !fcc->object_ptr && EG(This) &&
					    Z_OBJ_HT_P(EG(This))->get_class_entry &&
					    instanceof_function(Z_OBJCE_P(EG(This)), fcc->calling_scope TSRMLS_CC)) {
						fcc->object_ptr = EG(This);
					}
				}
			}
		}
	}

	//fprintf(stderr, "%d\n", retval);

	if(retval){
		if(fcc->calling_scope && !call_via_handler){
			if(!fcc->object_ptr && !(fcc->function_handler->common.fn_flags & ZEND_ACC_STATIC)){
				int severity;
				char *verb;
				if(fcc->function_handler->common.fn_flags & ZEND_ACC_ALLOW_STATIC){
					severity = E_STRICT;
					verb = "should not";
				} else {
					/* An internal function assumes $this is present and won't check that. So PHP would crash by allowing the call. */
					severity = E_ERROR;
					verb = "cannot";
				}
				if((check_flags & IS_CALLABLE_CHECK_IS_STATIC) != 0){
					retval = 0;
				}
				if(EG(This) && instanceof_function(Z_OBJCE_P(EG(This)), fcc->calling_scope TSRMLS_CC)){
					fcc->object_ptr = EG(This);
					if (error) {
						phalcon_spprintf(error, 0, "non-static method %s::%s() %s be called statically, assuming $this from compatible context %s", fcc->calling_scope->name, fcc->function_handler->common.function_name, verb, Z_OBJCE_P(EG(This))->name);
						if (severity == E_ERROR) {
							retval = 0;
						}
					} else if (retval) {
						zend_error(severity, "Non-static method %s::%s() %s be called statically, assuming $this from compatible context %s", fcc->calling_scope->name, fcc->function_handler->common.function_name, verb, Z_OBJCE_P(EG(This))->name);
					}
				} else {
					if(error){
						phalcon_spprintf(error, 0, "non-static method %s::%s() %s be called statically", fcc->calling_scope->name, fcc->function_handler->common.function_name, verb);
						if (severity == E_ERROR) {
							retval = 0;
						}
					} else if (retval) {
						zend_error(severity, "Non-static method %s::%s() %s be called statically", fcc->calling_scope->name, fcc->function_handler->common.function_name, verb);
					}
				}
			}

			if(retval && (check_flags & IS_CALLABLE_CHECK_NO_ACCESS) == 0){
				if(fcc->function_handler->op_array.fn_flags & ZEND_ACC_PRIVATE){
					if(fcc->object_ptr){
						scope = Z_OBJCE_P(fcc->object_ptr);
					} else {
						scope = EG(scope);
					}
					if(!phalcon_check_private(fcc->function_handler, scope, lmname, mlen TSRMLS_CC)){
						if(error){
							if(*error){
								efree(*error);
							}
							phalcon_spprintf(error, 0, "cannot access private method %s::%s() (21)", fcc->calling_scope->name, fcc->function_handler->common.function_name);
						}
						retval = 0;
					}
				} else {
					if((fcc->function_handler->common.fn_flags & ZEND_ACC_PROTECTED)){
						if(!zend_check_protected(fcc->function_handler->common.scope, EG(scope))){
							if(error){
								if(*error){
									efree(*error);
								}
								phalcon_spprintf(error, 0, "cannot access protected method %s::%s() (22)", fcc->calling_scope->name, fcc->function_handler->common.function_name);
							}
							retval = 0;
						}
					}
				}
			}
		}
	} else {
		if(error && !(check_flags & IS_CALLABLE_CHECK_SILENT)){
			if(fcc->calling_scope){
				if (error) phalcon_spprintf(error, 0, "class '%s' does not have a method '%s'", fcc->calling_scope->name, mname);
			} else {
				if (error) phalcon_spprintf(error, 0, "function '%s' does not exist", mname);
			}
		}
	}
	efree(lmname);

	if(fcc->object_ptr){
		fcc->called_scope = Z_OBJCE_P(fcc->object_ptr);
	}
	if(retval){
		fcc->initialized = 1;
	}
	return retval;
}

zend_bool phalcon_is_callable_ex(zval *callable, zval *object_ptr, uint check_flags, char **callable_name, int *callable_name_len, zend_fcall_info_cache *fcc, char **error TSRMLS_DC){
	zend_bool ret;
	int callable_name_len_local;
	zend_fcall_info_cache fcc_local;

	if (callable_name) {
		*callable_name = NULL;
	}

	if (callable_name_len == NULL) {
		callable_name_len = &callable_name_len_local;
	}

	if (fcc == NULL) {
		fcc = &fcc_local;
	}

	if (error) {
		*error = NULL;
	}

	fcc->initialized = 0;
	fcc->calling_scope = NULL;
	fcc->called_scope = NULL;
	fcc->function_handler = NULL;
	fcc->calling_scope = NULL;
	fcc->object_ptr = NULL;

	if (object_ptr && Z_TYPE_P(object_ptr) != IS_OBJECT) {
		object_ptr = NULL;
	}
	if (object_ptr &&
	    (!EG(objects_store).object_buckets ||
	     !EG(objects_store).object_buckets[Z_OBJ_HANDLE_P(object_ptr)].valid)) {
		return 0;
	}

	switch (Z_TYPE_P(callable)) {
		case IS_STRING:

			if(object_ptr){
				fcc->object_ptr = object_ptr;
				fcc->calling_scope = Z_OBJCE_P(object_ptr);
				if(callable_name){
					char *ptr;

					*callable_name_len = fcc->calling_scope->name_length + Z_STRLEN_P(callable) + sizeof("::") - 1;
					ptr = *callable_name = emalloc(*callable_name_len + 1);
					memcpy(ptr, fcc->calling_scope->name, fcc->calling_scope->name_length);
					ptr += fcc->calling_scope->name_length;
					memcpy(ptr, "::", sizeof("::") - 1);
					ptr += sizeof("::") - 1;
					memcpy(ptr, Z_STRVAL_P(callable), Z_STRLEN_P(callable) + 1);
				}
			} else {
				if(callable_name){
					*callable_name = estrndup(Z_STRVAL_P(callable), Z_STRLEN_P(callable));
					*callable_name_len = Z_STRLEN_P(callable);
				}
			}

			if(check_flags & IS_CALLABLE_CHECK_SYNTAX_ONLY){
				fcc->called_scope = fcc->calling_scope;
				return 1;
			}

			ret = phalcon_is_callable_check_func(check_flags, callable, fcc, 0, error TSRMLS_CC);
			if (fcc == &fcc_local &&
			    fcc->function_handler &&
				((fcc->function_handler->type == ZEND_INTERNAL_FUNCTION &&
			      (fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER)) ||
			     fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION_TEMPORARY ||
			     fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION)) {
				if (fcc->function_handler->type != ZEND_OVERLOADED_FUNCTION) {
					efree(fcc->function_handler->common.function_name);
				}
				efree(fcc->function_handler);
			}
			return ret;

		case IS_ARRAY:
			{
				zval **method = NULL;
				zval **obj = NULL;
				int strict_class = 0;

				if (zend_hash_num_elements(Z_ARRVAL_P(callable)) == 2) {
					zend_hash_index_find(Z_ARRVAL_P(callable), 0, (void **) &obj);
					zend_hash_index_find(Z_ARRVAL_P(callable), 1, (void **) &method);
				}
				if (obj && method &&
					(Z_TYPE_PP(obj) == IS_OBJECT ||
					Z_TYPE_PP(obj) == IS_STRING) &&
					Z_TYPE_PP(method) == IS_STRING) {

					if (Z_TYPE_PP(obj) == IS_STRING) {
						if (callable_name) {
							char *ptr;

							*callable_name_len = Z_STRLEN_PP(obj) + Z_STRLEN_PP(method) + sizeof("::") - 1;
							ptr = *callable_name = emalloc(*callable_name_len + 1);
							memcpy(ptr, Z_STRVAL_PP(obj), Z_STRLEN_PP(obj));
							ptr += Z_STRLEN_PP(obj);
							memcpy(ptr, "::", sizeof("::") - 1);
							ptr += sizeof("::") - 1;
							memcpy(ptr, Z_STRVAL_PP(method), Z_STRLEN_PP(method) + 1);
						}

						if (check_flags & IS_CALLABLE_CHECK_SYNTAX_ONLY) {
							return 1;
						}

						if (!phalcon_is_callable_check_class(Z_STRVAL_PP(obj), Z_STRLEN_PP(obj), fcc, &strict_class, error TSRMLS_CC)) {
							return 0;
						}

					} else {
						if (!EG(objects_store).object_buckets ||
						    !EG(objects_store).object_buckets[Z_OBJ_HANDLE_PP(obj)].valid) {
							return 0;
						}

						fcc->calling_scope = Z_OBJCE_PP(obj); /* TBFixed: what if it's overloaded? */

						fcc->object_ptr = *obj;

						if (callable_name) {
							char *ptr;

							*callable_name_len = fcc->calling_scope->name_length + Z_STRLEN_PP(method) + sizeof("::") - 1;
							ptr = *callable_name = emalloc(*callable_name_len + 1);
							memcpy(ptr, fcc->calling_scope->name, fcc->calling_scope->name_length);
							ptr += fcc->calling_scope->name_length;
							memcpy(ptr, "::", sizeof("::") - 1);
							ptr += sizeof("::") - 1;
							memcpy(ptr, Z_STRVAL_PP(method), Z_STRLEN_PP(method) + 1);
						}

						if (check_flags & IS_CALLABLE_CHECK_SYNTAX_ONLY) {
							fcc->called_scope = fcc->calling_scope;
							return 1;
						}
					}

					ret = phalcon_is_callable_check_func(check_flags, *method, fcc, strict_class, error TSRMLS_CC);
					if (fcc == &fcc_local &&
					    fcc->function_handler &&
						((fcc->function_handler->type == ZEND_INTERNAL_FUNCTION &&
					      (fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER)) ||
					     fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION_TEMPORARY ||
					     fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION)) {
						if (fcc->function_handler->type != ZEND_OVERLOADED_FUNCTION) {
							efree(fcc->function_handler->common.function_name);
						}
						efree(fcc->function_handler);
					}
					return ret;

				} else {
					if (zend_hash_num_elements(Z_ARRVAL_P(callable)) == 2) {
						if (!obj || (Z_TYPE_PP(obj) != IS_STRING && Z_TYPE_PP(obj) != IS_OBJECT)) {
							if (error) phalcon_spprintf(error, 0, "first array member is not a valid class name or object");
						} else {
							if (error) phalcon_spprintf(error, 0, "second array member is not a valid method");
						}
					} else {
						if (error) phalcon_spprintf(error, 0, "array must have exactly two members");
					}
					if (callable_name) {
						*callable_name = estrndup("Array", sizeof("Array")-1);
						*callable_name_len = sizeof("Array") - 1;
					}
				}
			}
			return 0;

		case IS_OBJECT:
			if (Z_OBJ_HANDLER_P(callable, get_closure) && Z_OBJ_HANDLER_P(callable, get_closure)(callable, &fcc->calling_scope, &fcc->function_handler, &fcc->object_ptr TSRMLS_CC) == SUCCESS) {
				fcc->called_scope = fcc->calling_scope;
				if (callable_name) {
					zend_class_entry *ce = Z_OBJCE_P(callable); /* TBFixed: what if it's overloaded? */

					*callable_name_len = ce->name_length + sizeof("::__invoke") - 1;
					*callable_name = emalloc(*callable_name_len + 1);
					memcpy(*callable_name, ce->name, ce->name_length);
					memcpy((*callable_name) + ce->name_length, "::__invoke", sizeof("::__invoke"));
				}
				return 1;
			}
			/* break missing intentionally */

		default:
			if (callable_name) {
				zval expr_copy;
				int use_copy;

				zend_make_printable_zval(callable, &expr_copy, &use_copy);
				*callable_name = estrndup(Z_STRVAL(expr_copy), Z_STRLEN(expr_copy));
				*callable_name_len = Z_STRLEN(expr_copy);
				zval_dtor(&expr_copy);
			}
			if (error) phalcon_spprintf(error, 0, "no array or string given");
			return 0;
	}
}

/**
 * zend call_user_function for debugging
 *
 */
int phalcon_call_user_function(HashTable *function_table, zval **object_pp, zval *function_name, zval *retval_ptr, zend_uint param_count, zval *params[] TSRMLS_DC){

	zval ***params_array;
	zend_uint i;
	int ex_retval;
	zval *local_retval_ptr = NULL;

	if(param_count){
		params_array = (zval ***) emalloc(sizeof(zval **)*param_count);
		for(i=0; i<param_count; i++){
			params_array[i] = &params[i];
		}
	} else {
		params_array = NULL;
	}
	ex_retval = phalcon_call_user_function_ex(function_table, object_pp, function_name, &local_retval_ptr, param_count, params_array, 1, NULL TSRMLS_CC);
	if(local_retval_ptr){
		COPY_PZVAL_TO_ZVAL(*retval_ptr, local_retval_ptr);
	} else {
		INIT_ZVAL(*retval_ptr);
	}
	if(params_array){
		efree(params_array);
	}
	return ex_retval;

}

int phalcon_call_user_function_ex(HashTable *function_table, zval **object_pp, zval *function_name, zval **retval_ptr_ptr, zend_uint param_count, zval **params[], int no_separation, HashTable *symbol_table TSRMLS_DC){
	zend_fcall_info fci;

	fci.size = sizeof(fci);
	fci.function_table = function_table;
	fci.object_ptr = object_pp ? *object_pp : NULL;
	fci.function_name = function_name;
	fci.retval_ptr_ptr = retval_ptr_ptr;
	fci.param_count = param_count;
	fci.params = params;
	fci.no_separation = (zend_bool) no_separation;
	fci.symbol_table = symbol_table;

	return zend_call_function(&fci, NULL TSRMLS_CC);
}

#ifndef PHP_WIN32

int phalcon_call_function(zend_fcall_info *fci, zend_fcall_info_cache *fci_cache TSRMLS_DC){

	zend_uint i;
	zval **original_return_value;
	HashTable *calling_symbol_table;
	zend_op_array *original_op_array;
	zend_op **original_opline_ptr;
	zend_class_entry *current_scope;
	zend_class_entry *current_called_scope;
	zend_class_entry *calling_scope = NULL;
	zend_class_entry *called_scope = NULL;
	zval *current_this;
	zend_execute_data execute_data;

	*fci->retval_ptr_ptr = NULL;

	if(!EG(active)){
		fprintf(stderr, "Failure: executor is already inactive\n");
		return FAILURE; /* executor is already inactive */
	}

	if(EG(exception)){
		fprintf(stderr, "Failure: We would result in an instable executor otherwise\n");
		return FAILURE; /* we would result in an instable executor otherwise */
	}

	switch(fci->size){
		case sizeof(zend_fcall_info):
			break; /* nothing to do currently */
		default:
			php_error_docref(NULL TSRMLS_CC, E_ERROR, "Corrupted fcall_info provided to zend_call_function()");
			break;
	}

	/* Initialize execute_data */
	if (EG(current_execute_data)) {
		execute_data = *EG(current_execute_data);
		EX(op_array) = NULL;
		EX(opline) = NULL;
		EX(object) = NULL;
	} else {
		/* This only happens when we're called outside any execute()'s
		 * It shouldn't be strictly necessary to NULL execute_data out,
		 * but it may make bugs easier to spot
		 */
		memset(&execute_data, 0, sizeof(zend_execute_data));
	}

	if (!fci_cache || !fci_cache->initialized) {
		zend_fcall_info_cache fci_cache_local;
		char *callable_name;
		char *error = NULL;

		if (!fci_cache) {
			fci_cache = &fci_cache_local;
		}

		if(!phalcon_is_callable_ex(fci->function_name, fci->object_ptr, 0, &callable_name, NULL, fci_cache, &error TSRMLS_CC)){
			if(error){
				php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid callback %s, %s (1)", callable_name, error);
				efree(error);
			}
			if(callable_name){
				efree(callable_name);
			}
			return FAILURE;
		} else {
			if(error){
				/* Capitalize the first latter of the error message */
				if (error[0] >= 'a' && error[0] <= 'z') {
					error[0] += ('A' - 'a');
				}
				php_error_docref(NULL TSRMLS_CC, E_STRICT, "%s", error);
				efree(error);
			}
		}
		efree(callable_name);
	}

	EX(function_state).function = fci_cache->function_handler;
	calling_scope = fci_cache->calling_scope;
	called_scope = fci_cache->called_scope;
	fci->object_ptr = fci_cache->object_ptr;
	EX(object) = fci->object_ptr;
	if (fci->object_ptr && Z_TYPE_P(fci->object_ptr) == IS_OBJECT && (!EG(objects_store).object_buckets || !EG(objects_store).object_buckets[Z_OBJ_HANDLE_P(fci->object_ptr)].valid)) {
		fprintf(stderr, "Failure: Some crazyness about buckets ¿?\n");
		return FAILURE;
	}

	if (EX(function_state).function->common.fn_flags & (ZEND_ACC_ABSTRACT|ZEND_ACC_DEPRECATED)) {
		if (EX(function_state).function->common.fn_flags & ZEND_ACC_ABSTRACT) {
			zend_error_noreturn(E_ERROR, "Cannot call abstract method %s::%s()", EX(function_state).function->common.scope->name, EX(function_state).function->common.function_name);
		}
		if (EX(function_state).function->common.fn_flags & ZEND_ACC_DEPRECATED) {
 			php_error_docref(NULL TSRMLS_CC, E_DEPRECATED, "Function %s%s%s() is deprecated",
				EX(function_state).function->common.scope ? EX(function_state).function->common.scope->name : "",
				EX(function_state).function->common.scope ? "::" : "",
				EX(function_state).function->common.function_name);
		}
	}

	ZEND_VM_STACK_GROW_IF_NEEDED(fci->param_count + 1);

	for (i=0; i<fci->param_count; i++) {
		zval *param;

		if (EX(function_state).function->type == ZEND_INTERNAL_FUNCTION
			&& (EX(function_state).function->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER) == 0
			&& !ARG_SHOULD_BE_SENT_BY_REF(EX(function_state).function, i + 1)
			&& PZVAL_IS_REF(*fci->params[i])) {
			SEPARATE_ZVAL(fci->params[i]);
		}

		if (ARG_SHOULD_BE_SENT_BY_REF(EX(function_state).function, i + 1)
			&& !PZVAL_IS_REF(*fci->params[i])) {

			if (Z_REFCOUNT_PP(fci->params[i]) > 1) {
				zval *new_zval;

				if (fci->no_separation &&
				    !ARG_MAY_BE_SENT_BY_REF(EX(function_state).function, i + 1)) {
					if(i) {
						/* hack to clean up the stack */
						zend_vm_stack_push_nocheck((void *) (zend_uintptr_t)i TSRMLS_CC);
						zend_vm_stack_clear_multiple(TSRMLS_C);
					}

					php_error_docref(NULL TSRMLS_CC, E_WARNING, "Parameter %d to %s%s%s() expected to be a reference, value given",
						i+1,
						EX(function_state).function->common.scope ? EX(function_state).function->common.scope->name : "",
						EX(function_state).function->common.scope ? "::" : "",
						EX(function_state).function->common.function_name);
					return FAILURE;
				}

				ALLOC_ZVAL(new_zval);
				*new_zval = **fci->params[i];
				zval_copy_ctor(new_zval);
				Z_SET_REFCOUNT_P(new_zval, 1);
				Z_DELREF_PP(fci->params[i]);
				*fci->params[i] = new_zval;
			}
			Z_ADDREF_PP(fci->params[i]);
			Z_SET_ISREF_PP(fci->params[i]);
			param = *fci->params[i];
		} else if (*fci->params[i] != &EG(uninitialized_zval)) {
			Z_ADDREF_PP(fci->params[i]);
			param = *fci->params[i];
		} else {
			ALLOC_ZVAL(param);
			*param = **(fci->params[i]);
			INIT_PZVAL(param);
		}
		zend_vm_stack_push_nocheck(param TSRMLS_CC);
	}

	EX(function_state).arguments = zend_vm_stack_top(TSRMLS_C);
	zend_vm_stack_push_nocheck((void*)(zend_uintptr_t)fci->param_count TSRMLS_CC);

	current_scope = EG(scope);
	EG(scope) = calling_scope;
	if(PHALCON_DEBUG){
		fprintf(stderr, "ScopeAddress=%p\n", EG(scope));
	}

	current_this = EG(This);

	current_called_scope = EG(called_scope);
	if (called_scope) {
		EG(called_scope) = called_scope;
	} else if (EX(function_state).function->type != ZEND_INTERNAL_FUNCTION) {
		EG(called_scope) = NULL;
	}

	if (fci->object_ptr) {
		if ((EX(function_state).function->common.fn_flags & ZEND_ACC_STATIC)) {
			EG(This) = NULL;
		} else {
			EG(This) = fci->object_ptr;

			if (!PZVAL_IS_REF(EG(This))) {
				Z_ADDREF_P(EG(This)); /* For $this pointer */
			} else {
				zval *this_ptr;

				ALLOC_ZVAL(this_ptr);
				*this_ptr = *EG(This);
				INIT_PZVAL(this_ptr);
				zval_copy_ctor(this_ptr);
				EG(This) = this_ptr;
			}
		}
	} else {
		EG(This) = NULL;
	}

	EX(prev_execute_data) = EG(current_execute_data);
	EG(current_execute_data) = &execute_data;

	if (EX(function_state).function->type == ZEND_USER_FUNCTION) {
		calling_symbol_table = EG(active_symbol_table);
		EG(scope) = EX(function_state).function->common.scope;
		if(PHALCON_DEBUG){
			fprintf(stderr, "ScopeAddress=%p\n", EG(scope));
		}
		if(fci->symbol_table){
			EG(active_symbol_table) = fci->symbol_table;
		} else {
			EG(active_symbol_table) = NULL;
		}

		original_return_value = EG(return_value_ptr_ptr);
		original_op_array = EG(active_op_array);
		EG(return_value_ptr_ptr) = fci->retval_ptr_ptr;
		EG(active_op_array) = (zend_op_array *) EX(function_state).function;
		original_opline_ptr = EG(opline_ptr);
		zend_execute(EG(active_op_array) TSRMLS_CC);
		if (!fci->symbol_table && EG(active_symbol_table)) {
			if (EG(symtable_cache_ptr)>=EG(symtable_cache_limit)) {
				zend_hash_destroy(EG(active_symbol_table));
				FREE_HASHTABLE(EG(active_symbol_table));
			} else {
				/* clean before putting into the cache, since clean
				   could call dtors, which could use cached hash */
				zend_hash_clean(EG(active_symbol_table));
				*(++EG(symtable_cache_ptr)) = EG(active_symbol_table);
			}
		}
		EG(active_symbol_table) = calling_symbol_table;
		EG(active_op_array) = original_op_array;
		EG(return_value_ptr_ptr)=original_return_value;
		EG(opline_ptr) = original_opline_ptr;
	} else if (EX(function_state).function->type == ZEND_INTERNAL_FUNCTION) {
		int call_via_handler = (EX(function_state).function->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER) != 0;
		ALLOC_INIT_ZVAL(*fci->retval_ptr_ptr);
		if (EX(function_state).function->common.scope) {
			EG(scope) = EX(function_state).function->common.scope;
			if(PHALCON_DEBUG){
				fprintf(stderr, "ScopeAddress=%p\n", EG(scope));
			}
		}
		((zend_internal_function *) EX(function_state).function)->handler(fci->param_count, *fci->retval_ptr_ptr, fci->retval_ptr_ptr, fci->object_ptr, 1 TSRMLS_CC);
		/*  We shouldn't fix bad extensions here,
			because it can break proper ones (Bug #34045)
		if (!EX(function_state).function->common.return_reference)
		{
			INIT_PZVAL(*fci->retval_ptr_ptr);
		}*/
		if (EG(exception) && fci->retval_ptr_ptr) {
			zval_ptr_dtor(fci->retval_ptr_ptr);
			*fci->retval_ptr_ptr = NULL;
		}

		if (call_via_handler) {
			/* We must re-initialize function again */
			fci_cache->initialized = 0;
		}
	} else { /* ZEND_OVERLOADED_FUNCTION */
		ALLOC_INIT_ZVAL(*fci->retval_ptr_ptr);

		/* Not sure what should be done here if it's a static method */
		if (fci->object_ptr) {
			Z_OBJ_HT_P(fci->object_ptr)->call_method(EX(function_state).function->common.function_name, fci->param_count, *fci->retval_ptr_ptr, fci->retval_ptr_ptr, fci->object_ptr, 1 TSRMLS_CC);
		} else {
			zend_error_noreturn(E_ERROR, "Cannot call overloaded function for non-object");
		}

		if (EX(function_state).function->type == ZEND_OVERLOADED_FUNCTION_TEMPORARY) {
			efree(EX(function_state).function->common.function_name);
		}
		efree(EX(function_state).function);

		if (EG(exception) && fci->retval_ptr_ptr) {
			zval_ptr_dtor(fci->retval_ptr_ptr);
			*fci->retval_ptr_ptr = NULL;
		}
	}
	zend_vm_stack_clear_multiple(TSRMLS_C);

	if (EG(This)) {
		zval_ptr_dtor(&EG(This));
	}
	EG(called_scope) = current_called_scope;
	EG(scope) = current_scope;
	if(PHALCON_DEBUG){
		fprintf(stderr, "ScopeAddress=%p\n", EG(scope));
	}
	EG(This) = current_this;
	EG(current_execute_data) = EX(prev_execute_data);

	if (EG(exception)) {
		zend_throw_exception_internal(NULL TSRMLS_CC);
	}
	return SUCCESS;
}
#endif