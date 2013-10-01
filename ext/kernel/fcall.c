
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Zephir Team (http://www.zephir-lang.com)       |
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
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"

#include "Zend/zend_API.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_execute.h"

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/hash.h"
#include "kernel/exception.h"
#include "kernel/backtrace.h"

#include "kernel/alternative/fcall.h"

int zephir_has_constructor_ce(zend_class_entry *ce) {

	while (ce) {
		if (ce->constructor) {
			return 1;
		}
		ce = ce->parent;
	}

	return 0;
}

/**
 * Check if an object has a constructor
 */
int zephir_has_constructor(const zval *object TSRMLS_DC){
	return zephir_has_constructor_ce(Z_OBJCE_P(object));
}

/**
 * Calls a function/method in the PHP userland
 */
static int zephir_call_user_function(HashTable *function_table, zval **object_pp, zval *function_name, zval *retval_ptr, zval **retval_ptr_ptr, zend_uint param_count, zval *params[] TSRMLS_DC) {

	zval ***params_array = NULL;
	zval **static_params_array[10];
	zval ***params_ptr;
	zval *local_retval_ptr = NULL;
	zend_uint i;
	int ex_retval;
	zend_fcall_info fci;
	zend_zephir_globals *zephir_globals_ptr = ZEPHIR_VGLOBAL;

	if (retval_ptr_ptr && *retval_ptr_ptr) {
		zval_ptr_dtor(retval_ptr_ptr);
		*retval_ptr_ptr = NULL;
	}

	zephir_globals_ptr->recursive_lock++;

	if (unlikely(zephir_globals_ptr->recursive_lock > 2048)) {
		ex_retval = FAILURE;
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Maximum recursion depth exceeded");
	} else {

		if (param_count) {
			if (unlikely(param_count > 10)) {
				params_array = (zval ***) emalloc(param_count * sizeof(zval**));
				params_ptr   = params_array;
				for (i = 0; i < param_count; i++) {
					params_array[i] = &params[i];
				}
			} else {
				params_ptr = static_params_array;
				for (i = 0; i < param_count; i++) {
					static_params_array[i] = &params[i];
				}
			}
		}
		else {
			params_ptr = NULL;
		}

		fci.size           = sizeof(fci);
		fci.function_table = function_table;
		fci.object_ptr     = object_pp ? *object_pp : NULL;
		fci.function_name  = function_name;
		fci.retval_ptr_ptr = retval_ptr_ptr ? retval_ptr_ptr : &local_retval_ptr;
		fci.param_count    = param_count;
		fci.params         = params_ptr;
		fci.no_separation  = 1;
		fci.symbol_table   = NULL;

		ex_retval = ZEPHIR_ZEND_CALL_FUNCTION_WRAPPER(&fci, NULL TSRMLS_CC);

		if (local_retval_ptr) {
			if (Z_TYPE_P(local_retval_ptr) == IS_NULL) {
				zval_ptr_dtor(&local_retval_ptr);
			}
			else {
				COPY_PZVAL_TO_ZVAL(*retval_ptr, local_retval_ptr);
			}
		}
		else if (!retval_ptr_ptr) {
			INIT_ZVAL(*retval_ptr);
		}

		if (unlikely(params_array != NULL)) {
			efree(params_array);
		}
	}

	zephir_globals_ptr->recursive_lock--;

	return ex_retval;
}


static void zephir_check_return_value(zval *return_value) {
#ifndef ZEPHIR_RELEASE
	int valid_return_value = 1;

	assert(return_value != NULL);

	if (Z_REFCOUNT_P(return_value) > 1) {
		valid_return_value = 0;
		fprintf(stderr, "return_value has %u references, expect crashes!\n", Z_REFCOUNT_P(return_value));
	} else if (Z_TYPE_P(return_value) > IS_BOOL) {
		valid_return_value = 0;
		fprintf(stderr, "return_value is of complex type (%d), expect memory leaks (refcnt=%u)!\n", Z_TYPE_P(return_value), Z_REFCOUNT_P(return_value));
	}

	if (!valid_return_value) {
		zephir_print_backtrace();
		abort();
	}
#endif
}

static int zephir_call_func_vparams(zval *return_value, zval **return_value_ptr, zval *func TSRMLS_DC, int param_count, va_list ap)
{
	zval **params_ptr, **params = NULL;
	zval *static_params[10];
	int free_params = 0, i, status, caller_wants_result = 1;

	if (!return_value) {
		ALLOC_INIT_ZVAL(return_value);
		caller_wants_result = 0;
	} else {
		zephir_check_return_value(return_value);
	}

	if (param_count < 0) {
		params      = va_arg(ap, zval**);
		param_count = -param_count;
		params_ptr  = params;
	} else {
		if (param_count > 0 && param_count <= 10) {
			params_ptr = static_params;
			for (i = 0; i < param_count; ++i) {
				static_params[i] = va_arg(ap, zval*);
			}
		} else {
			if (unlikely(param_count > 10)) {
				free_params = 1;
				params      = (zval**)emalloc(param_count * sizeof(zval*));
				params_ptr  = params;
				for (i = 0; i < param_count; ++i) {
					params[i] = va_arg(ap, zval*);
				}
			} else {
				params_ptr = NULL;
			}
		}
	}


	status = zephir_call_user_function(EG(function_table), NULL, func, return_value, return_value_ptr, param_count, params_ptr TSRMLS_CC);

	if (unlikely(free_params)) {
		efree(params);
	}

	if (status == FAILURE) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function %s()", Z_STRVAL_P(func));
	}
	else if (EG(exception)) {
		status = FAILURE;
	}

	if (!caller_wants_result) {
		zval_ptr_dtor(&return_value);
	}

	return status;
}

int zephir_call_method_vparams(zval *return_value, zval **return_value_ptr, zval *object, char *method_name,
	int method_len, ulong method_key, zend_function **prepared_function TSRMLS_DC, int param_count, va_list ap) {

	int i, status, free_params = -0, caller_wants_result = 1;
	zend_class_entry *ce, *active_scope = NULL;
	zval **params_ptr, **params = NULL;
	zval *static_params[10];

	if (unlikely(Z_TYPE_P(object) != IS_OBJECT)) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to method %s() on a non object", method_name);
		return FAILURE;
	}

	if (!return_value) {
		ALLOC_INIT_ZVAL(return_value);
		caller_wants_result = 0;
	} else {
		zephir_check_return_value(return_value);
	}

	if (param_count < 0) {
		params      = va_arg(ap, zval**);
		param_count = -param_count;
		params_ptr  = params;
	} else if (param_count > 0 && param_count <= 10) {
		params_ptr = static_params;
		for (i = 0; i < param_count; ++i) {
			static_params[i] = va_arg(ap, zval*);
		}
	}
	else if (unlikely(param_count > 10)) {
		free_params = 1;
		params      = (zval**) emalloc(param_count * sizeof(zval*));
		params_ptr  = params;
		for (i = 0; i < param_count; ++i) {
			params[i] = va_arg(ap, zval*);
		}
	}
	else {
		params_ptr = NULL;
	}

	ce           = Z_OBJCE_P(object);
	active_scope = EG(scope);
	EG(scope)    = ce;
	status       = zephir_alt_call_user_method(ce, &object, method_name, method_len, return_value, return_value_ptr, param_count, params_ptr, method_key, prepared_function TSRMLS_CC);
	EG(scope)    = active_scope;

	if (unlikely(free_params)) {
		efree(params);
	}

	if (status == FAILURE) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined method %s::%s()", ce->name, method_name);
		status = FAILURE;
	} else {
		if (EG(exception)) {
			status = FAILURE;
		}
	}

	if (!caller_wants_result) {
		zval_ptr_dtor(&return_value);
	}

	return status;
}

/**
 * Call single static function on a zval which requires parameters
 */
static int zephir_call_static_zval_str_func_vparams(zval *return_value, zval **return_value_ptr, zval *mixed_name, char *method_name, int method_len TSRMLS_DC, int param_count, va_list ap) {

	zval **params_ptr, **params = NULL, *fn, *mn;
	zval *static_params[10];
	int free_params = 0, i, status, caller_wants_result = 1;

	if (!return_value) {
		ALLOC_INIT_ZVAL(return_value);
		caller_wants_result = 0;
	} else {
		zephir_check_return_value(return_value);
	}

	Z_ADDREF_P(mixed_name);

	ALLOC_INIT_ZVAL(fn);
	array_init_size(fn, 2);
	add_next_index_zval(fn, mixed_name);

	ALLOC_INIT_ZVAL(mn);
	ZVAL_STRINGL(mn, method_name, method_len, 0);
	add_next_index_zval(fn, mn);

	if (param_count < 0) {
		params      = va_arg(ap, zval**);
		param_count = -param_count;
		params_ptr  = params;
	} else if (param_count > 0 && param_count <= 10) {
		params_ptr = static_params;
		for (i = 0; i < param_count; ++i) {
			static_params[i] = va_arg(ap, zval*);
		}
	}
	else if (unlikely(param_count > 10)) {
		free_params = 1;
		params      = (zval**)emalloc(param_count * sizeof(zval*));
		params_ptr  = params;
		for (i=0; i<param_count; ++i) {
			params[i] = va_arg(ap, zval*);
		}
	}
	else {
		params_ptr = NULL;
	}

	status = zephir_call_user_function(EG(function_table), NULL, fn, return_value, return_value_ptr, param_count, params_ptr TSRMLS_CC);

	if (unlikely(free_params)) {
		efree(params);
	}

	if (status == FAILURE) {
		if (Z_TYPE_P(mixed_name) == IS_STRING) {
			php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function %s::%s()", Z_STRVAL_P(mixed_name), method_name);
		} else {
			php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function not-callable::%s()", method_name);
		}
	}
	else if (EG(exception)) {
		status = FAILURE;
	}

	if (Z_REFCOUNT_P(mn) > 1) {
		ZVAL_STRINGL(mn, method_name, method_len, 1);
	} else {
		ZVAL_NULL(mn);
	}

	zval_ptr_dtor(&fn);

	if (!caller_wants_result) {
		zval_ptr_dtor(&return_value);
	}

	return status;
}

/**
 * @brief Calls function @a func_name which accepts @a param_count arguments @a params
 * @param[out] Return value; set to @c NULL if the return value is not needed
 * @param func_name Function name
 * @param func_length Length of the function name
 * @param param_count Number of arguments
 * @param params Arguments
 * @return Whether the call succeeded
 * @retval @c SUCCESS
 * @retval @c FAILURE
 */
int zephir_call_func_params(zval *return_value, zval **return_value_ptr, const char *func_name, int func_length TSRMLS_DC, int param_count, ...) {
	zval fn;
	int status;
	va_list ap;

	INIT_ZVAL(fn);
	ZVAL_STRINGL(&fn, func_name, func_length, 0);

	va_start(ap, param_count);
	status = zephir_call_func_vparams(return_value, return_value_ptr, &fn TSRMLS_CC, param_count, ap);
	va_end(ap);

	return status;
}

/**
 * @brief Calls methid @a method_name from @a object which accepts @a param_count arguments @a params
 * @param[out] Return value; set to @c NULL if the return value is not needed
 * @param object Object
 * @param method_name Method name
 * @param method_length Length of the method name
 * @param param_count Number of arguments
 * @param params Arguments
 * @return Whether the call succeeded
 * @retval @c SUCCESS
 * @retval @c FAILURE
 */
int zephir_call_method_params(zval *return_value, zval **return_value_ptr, zval *object, char *method_name, int method_len, ulong method_key TSRMLS_DC, int param_count, ...) {

	int status;
	va_list ap;

	va_start(ap, param_count);
	status = zephir_call_method_vparams(return_value, return_value_ptr, object, method_name, method_len, method_key, NULL TSRMLS_CC, param_count, ap);
	va_end(ap);

	return status;
}

int zephir_call_method_cache_params(zval *return_value, zval **return_value_ptr, zval *object,
	char *method_name, int method_len, ulong method_key, zend_function **prepared_function TSRMLS_DC,
	int param_count, ...) {

	int status;
	va_list ap;

	va_start(ap, param_count);
	status = zephir_call_method_vparams(return_value, return_value_ptr, object, method_name, method_len, method_key, prepared_function TSRMLS_CC, param_count, ap);
	va_end(ap);

	return status;
}

int zephir_call_method_zval_params(zval *return_value, zval **return_value_ptr, zval *object, zval *method TSRMLS_DC, int param_count, ...)
{
	if (likely(Z_TYPE_P(method) == IS_STRING)) {
		va_list ap;
		int status;
		char *m = Z_STRVAL_P(method);

		va_start(ap, param_count);
		status = zephir_call_method_vparams(return_value, return_value_ptr, object, m, Z_STRLEN_P(method), (IS_INTERNED(m) ? INTERNED_HASH(m) : 0), NULL TSRMLS_CC, param_count, ap);
		va_end(ap);

		return status;
	}

	php_error_docref(NULL TSRMLS_CC, E_ERROR, "Method name must be string");
	return FAILURE;
}


/**
 * Call single static function that requires an arbitrary number of parameters
 */
int zephir_call_static_func_params(zval *return_value, zval **return_value_ptr, char *class_name, int class_length, char *method_name, int method_length TSRMLS_DC, int param_count, ...) {

	zval cls;
	va_list ap;
	int status;

	INIT_ZVAL(cls);
	ZVAL_STRINGL(&cls, class_name, class_length, 0);

	va_start(ap, param_count);
	status = zephir_call_static_zval_str_func_vparams(return_value, return_value_ptr, &cls, method_name, method_length TSRMLS_CC, param_count, ap);
	va_end(ap);

	assert(!Z_ISREF_P(&cls));
	assert(Z_REFCOUNT_P(&cls) == 1);
	return status;
}

/**
 * Call parent static function that requires an arbitrary number of parameters
 */
int zephir_call_parent_func_params(zval *return_value, zval **return_value_ptr, zval *object, zend_class_entry *active_class_ce, char *method_name, int method_len TSRMLS_DC, int param_count, ...) {

	zval cls;
	int status;
	zend_class_entry *active_scope;
	va_list ap;

	if (object) {
		active_scope = EG(scope);
		EG(scope)    = active_class_ce;
	}

	INIT_ZVAL(cls);
	ZVAL_STRING(&cls, "parent", 0);

	va_start(ap, param_count);
	status = zephir_call_static_zval_str_func_vparams(return_value, return_value_ptr, &cls, method_name, method_len TSRMLS_CC, param_count, ap);
	va_end(ap);

	if (object) {
		EG(scope) = active_scope;
	}

	return status;
}

/**
 * Call self-class static function which requires parameters
 */
int zephir_call_self_func_params(zval *return_value, zval **return_value_ptr, zval *object, char *method_name, int method_len TSRMLS_DC, int param_count, ...) {

	int status;
	zend_class_entry *active_scope;
	va_list ap;
	zval cls;

	if (object) {
		active_scope = EG(scope);
		EG(scope)    = Z_OBJCE_P(object);
	}

	INIT_ZVAL(cls);
	ZVAL_STRING(&cls, "self", 0);

	va_start(ap, param_count);
	status = zephir_call_static_zval_str_func_vparams(return_value, return_value_ptr, &cls, method_name, method_len TSRMLS_CC, param_count, ap);
	va_end(ap);

	if (object) {
		EG(scope) = active_scope;
	}

	return status;
}

/**
 * Call single static function on a zval which requires parameters
 */
int zephir_call_static_zval_func_params(zval *return_value, zval **return_value_ptr, zval *mixed_name, zval *method TSRMLS_DC, int param_count, ...) {

	if (likely(Z_TYPE_P(method) == IS_STRING)) {
		int status;
		va_list ap;

		va_start(ap, param_count);
		status = zephir_call_static_zval_str_func_vparams(return_value, return_value_ptr, mixed_name, Z_STRVAL_P(method), Z_STRLEN_P(method) TSRMLS_CC, param_count, ap);
		va_end(ap);

		return status;
	}

	php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function not-callable::not-callable()");
	return FAILURE;
}

int zephir_call_static_zval_str_func_params(zval *return_value, zval **return_value_ptr, zval *mixed_name, char *method_name, int method_len TSRMLS_DC, int param_count, ...) {

	int status;
	va_list ap;

	va_start(ap, param_count);
	status = zephir_call_static_zval_str_func_vparams(return_value, return_value_ptr, mixed_name, method_name, method_len TSRMLS_CC, param_count, ap);
	va_end(ap);

	return status;
}


/**
 * Replaces call_user_func_array avoiding function lookup
 */
int zephir_call_user_func_array(zval *return_value, zval *handler, zval *params TSRMLS_DC){

	int status = zephir_call_user_func_array_noex(return_value, handler, params TSRMLS_CC);

	if (EG(exception)) {
		status = FAILURE;
	}

	return status;
}

/**
 * Replaces call_user_func_array avoiding function lookup
 * This function does not return FAILURE if an exception has ocurred
 */
int zephir_call_user_func_array_noex(zval *return_value, zval *handler, zval *params TSRMLS_DC){

	zval *retval_ptr = NULL;
	zend_fcall_info fci;
	zend_fcall_info_cache fci_cache;
	char *is_callable_error = NULL;
	int status = FAILURE;

	if (params && Z_TYPE_P(params) != IS_ARRAY) {
		ZVAL_NULL(return_value);
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for zephir_call_user_func_array_noex()");
		return FAILURE;
	}

	if (zend_fcall_info_init(handler, 0, &fci, &fci_cache, NULL, &is_callable_error TSRMLS_CC) == SUCCESS) {
		if (is_callable_error) {
			zend_error(E_STRICT, "%s", is_callable_error);
			efree(is_callable_error);
		}
		status = SUCCESS;
	} else {
		if (is_callable_error) {
			zend_error(E_WARNING, "%s", is_callable_error);
			efree(is_callable_error);
		} else {
			status = SUCCESS;
		}
	}

	if (status == SUCCESS) {

		zend_fcall_info_args(&fci, params TSRMLS_CC);
		fci.retval_ptr_ptr = &retval_ptr;

		if (zend_call_function(&fci, &fci_cache TSRMLS_CC) == SUCCESS && fci.retval_ptr_ptr && *fci.retval_ptr_ptr) {
			COPY_PZVAL_TO_ZVAL(*return_value, *fci.retval_ptr_ptr);
		}

		if (fci.params) {
			efree(fci.params);
		}
	}

	if (EG(exception)) {
		status = SUCCESS;
	}

	return status;
}

#if PHP_VERSION_ID <= 50309

int zephir_call_function(zend_fcall_info *fci, zend_fcall_info_cache *fci_cache TSRMLS_DC) {

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

	if (!EG(active)) {
		return FAILURE; /* executor is already inactive */
	}

	if (EG(exception)) {
		return FAILURE; /* we would result in an instable executor otherwise */
	}

	switch (fci->size) {
		case sizeof(zend_fcall_info):
			break; /* nothing to do currently */
		default:
			zend_error(E_ERROR, "Corrupted fcall_info provided to zephir_call_function()");
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

		if (!zend_is_callable_ex(fci->function_name, fci->object_ptr, IS_CALLABLE_CHECK_SILENT, &callable_name, NULL, fci_cache, &error TSRMLS_CC)) {
			if (error) {
				zend_error(E_WARNING, "Invalid callback %s, %s", callable_name, error);
				efree(error);
			}
			if (callable_name) {
				efree(callable_name);
			}
			return FAILURE;
		} else {
			if (error) {
				/* Capitalize the first latter of the error message */
				if (error[0] >= 'a' && error[0] <= 'z') {
					error[0] += ('A' - 'a');
				}
				zend_error(E_STRICT, "%s", error);
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
	if (fci->object_ptr && Z_TYPE_P(fci->object_ptr) == IS_OBJECT &&
		(!EG(objects_store).object_buckets || !EG(objects_store).object_buckets[Z_OBJ_HANDLE_P(fci->object_ptr)].valid)) {
		return FAILURE;
	}

	if (EX(function_state).function->common.fn_flags & ZEND_ACC_ABSTRACT) {
		zend_error_noreturn(E_ERROR, "Cannot call abstract method %s::%s()", EX(function_state).function->common.scope->name, EX(function_state).function->common.function_name);
		return FAILURE;
	}

	ZEND_VM_STACK_GROW_IF_NEEDED(fci->param_count + 1);

	for (i = 0; i < fci->param_count; i++) {
		zval *param;

		if (EX(function_state).function->type == ZEND_INTERNAL_FUNCTION
			&& (EX(function_state).function->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER) == 0
			&& !ARG_SHOULD_BE_SENT_BY_REF(EX(function_state).function, i + 1)
			&& PZVAL_IS_REF(*fci->params[i])) {
			ALLOC_ZVAL(param);
			*param = **(fci->params[i]);
			INIT_PZVAL(param);
			zval_copy_ctor(param);
		} else if (ARG_SHOULD_BE_SENT_BY_REF(EX(function_state).function, i + 1)
			&& !PZVAL_IS_REF(*fci->params[i])) {

			if (Z_REFCOUNT_PP(fci->params[i]) > 1) {
				zval *new_zval;

				if (fci->no_separation &&
					!ARG_MAY_BE_SENT_BY_REF(EX(function_state).function, i + 1)) {
					if (i || UNEXPECTED(ZEND_VM_STACK_ELEMETS(EG(argument_stack)) == EG(argument_stack)->top)) {
						/* hack to clean up the stack */
						zend_vm_stack_push_nocheck((void *) (zend_uintptr_t)i TSRMLS_CC);
						#if PHP_VERSION_ID <= 50500
						zend_vm_stack_clear_multiple(TSRMLS_C);
						#else
						zend_vm_stack_clear_multiple(0 TSRMLS_C);
						#endif
					}

					zend_error(E_WARNING, "Parameter %d to %s%s%s() expected to be a reference, value given",
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

	current_this = EG(This);

	current_called_scope = EG(called_scope);
	if (called_scope) {
		EG(called_scope) = called_scope;
	} else {
		if (EX(function_state).function->type != ZEND_INTERNAL_FUNCTION) {
			EG(called_scope) = NULL;
		}
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
		if (fci->symbol_table) {
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
	} else {
		ALLOC_INIT_ZVAL(*fci->retval_ptr_ptr);

		if (fci->object_ptr) {
			Z_OBJ_HT_P(fci->object_ptr)->call_method(EX(function_state).function->common.function_name, fci->param_count, *fci->retval_ptr_ptr, fci->retval_ptr_ptr, fci->object_ptr, 1 TSRMLS_CC);
		} else {
			zend_error_noreturn(E_ERROR, "Cannot call overloaded function for non-object");
			return FAILURE;
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
	#if PHP_VERSION_ID <= 50500
	zend_vm_stack_clear_multiple(TSRMLS_C);
	#else
	zend_vm_stack_clear_multiple(0 TSRMLS_C);
	#endif

	if (EG(This)) {
		zval_ptr_dtor(&EG(This));
	}
	EG(called_scope) = current_called_scope;
	EG(scope) = current_scope;
	EG(This) = current_this;
	EG(current_execute_data) = EX(prev_execute_data);

	if (EG(exception)) {
		zephir_throw_exception_internal(NULL TSRMLS_CC);
	}
	return SUCCESS;
}

#endif
