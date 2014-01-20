
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

#include "php_phalcon.h"

#include <Zend/zend_API.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_execute.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/hash.h"
#include "kernel/exception.h"
#include "kernel/backtrace.h"

#include "kernel/alternative/fcall.h"

#ifndef PHALCON_RELEASE

/**
 * @brief Checks whether @c return_value is suitable for use
 * @param return_value
 */
static void phalcon_check_return_value(zval *return_value)
{
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
		phalcon_print_backtrace();
		abort();
	}
}

#else

static inline void phalcon_check_return_value(zval *return_value) {}

#endif


int phalcon_has_constructor_ce(const zend_class_entry *ce)
{
	while (ce) {
		if (ce->constructor) {
			return 1;
		}

		ce = ce->parent;
	}

	return 0;
}

/**
 * Calls a function/method in the PHP userland
 */
static int phalcon_call_user_function(zval **object_pp, const zend_class_entry *obj_ce, zval *function_name, zval **retval_ptr_ptr, zend_uint param_count, zval *params[] TSRMLS_DC)
{
	zval ***params_ptr, ***params_array = NULL;
	zval **static_params_array[10];
	zval *local_retval_ptr = NULL;
	zend_uint i;
	int status;
	zend_fcall_info fci;
	zend_fcall_info_cache fcic;
	zend_phalcon_globals *phalcon_globals_ptr = PHALCON_VGLOBAL;
	char *name = NULL;
	uint len = 0;

	if (retval_ptr_ptr && *retval_ptr_ptr) {
		zval_ptr_dtor(retval_ptr_ptr);
		*retval_ptr_ptr = NULL;
	}

	phalcon_globals_ptr->recursive_lock++;

	if (unlikely(phalcon_globals_ptr->recursive_lock > 2048)) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Maximum recursion depth exceeded");
		return FAILURE;
	}

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

	if (!obj_ce && object_pp) {
		obj_ce = Z_OBJCE_PP(object_pp);
	}

	fci.size           = sizeof(fci);
	fci.function_table = obj_ce ? (HashTable*)(&obj_ce->function_table) : EG(function_table);
	fci.object_ptr     = object_pp ? *object_pp : NULL;
	fci.function_name  = function_name;
	fci.retval_ptr_ptr = retval_ptr_ptr ? retval_ptr_ptr : &local_retval_ptr;
	fci.param_count    = param_count;
	fci.params         = params_ptr;
	fci.no_separation  = 1;
	fci.symbol_table   = NULL;

	if (Z_TYPE_P(function_name) == IS_STRING) {
		name = Z_STRVAL_P(function_name);
		len  = Z_STRLEN_P(function_name);
	}
	else if (Z_TYPE_P(function_name) == IS_ARRAY && zend_hash_num_elements(Z_ARRVAL_P(function_name)) == 2) {
		zval **v;
		if (zend_hash_index_find(Z_ARRVAL_P(function_name), 1, (void**)&v) == SUCCESS && Z_TYPE_PP(v) == IS_STRING) {
			name = Z_STRVAL_PP(v);
			len  = Z_STRLEN_PP(v);
		}
	}

#ifndef PHALCON_RELEASE
	if (obj_ce && name && is_phalcon_class(obj_ce) && strspn(name, "abcdefghijklmnopqrstuvwxyz0123456789_") != len) {
		fprintf(stderr, "Warning: method name is not lowercased: %s\n", name);
		phalcon_print_backtrace();
	}
#endif

	if (name && zend_hash_find(fci.function_table, name, len+1, (void **) &fcic.function_handler) != FAILURE) {
		fcic.initialized   = 1;
		fcic.calling_scope = (zend_class_entry*)obj_ce;
		fcic.object_ptr    = fci.object_ptr;

		if (object_pp) {
			fcic.called_scope = Z_OBJCE_PP(object_pp);
		}
		else if (obj_ce && !(EG(called_scope) && instanceof_function(EG(called_scope), obj_ce TSRMLS_CC))) {
			fcic.called_scope = (zend_class_entry*)obj_ce;
		}
		else {
			fcic.called_scope = EG(called_scope);
		}
	}
	else {
		fcic.initialized = 0;
	}

	status = PHALCON_ZEND_CALL_FUNCTION_WRAPPER(&fci, &fcic TSRMLS_CC);

	if (unlikely(params_array != NULL)) {
		efree(params_array);
	}

	if (!retval_ptr_ptr) {
		if (local_retval_ptr) {
			zval_ptr_dtor(&local_retval_ptr);
		}
	}

	phalcon_globals_ptr->recursive_lock--;
	return status;
}

int phalcon_call_func_aparams(zval **return_value_ptr, const char *func_name, uint func_length, uint param_count, zval **params TSRMLS_DC)
{
	int status;
	zval *rv = NULL, **rvp = return_value_ptr ? return_value_ptr : &rv;
	zval func = zval_used_for_init;

#ifndef PHALCON_RELEASE
	if (return_value_ptr && *return_value_ptr) {
		fprintf(stderr, "%s: *return_value_ptr must be NULL\n", __func__);
		phalcon_print_backtrace();
		abort();
	}
#endif

	ZVAL_STRINGL(&func, func_name, func_length, 0);
	status = phalcon_call_user_function(NULL, NULL, &func, rvp, param_count, params TSRMLS_CC);

	if (status == FAILURE && !EG(exception)) {
		zend_error(E_ERROR, "Call to undefined function %s()", func_name);
	}
	else if (EG(exception)) {
		status = FAILURE;
		if (return_value_ptr) {
			*return_value_ptr = NULL;
		}
	}

	if (rv) {
		zval_ptr_dtor(&rv);
	}

	return status;
}

int phalcon_call_func_vparams(zval **return_value_ptr, const char *func_name, uint func_length, int param_count, va_list ap TSRMLS_DC)
{
	zval **params_ptr, **params = NULL;
	zval *static_params[10];
	int free_params = 0, i, status;

	if (param_count < 0) {
		params      = va_arg(ap, zval**);
		param_count = -param_count;
		params_ptr  = params;
	}
	else if (param_count > 0 && param_count <= 10) {
		params_ptr = static_params;
		for (i=0; i<param_count; ++i) {
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

	status = phalcon_call_func_aparams(return_value_ptr, func_name, func_length, param_count, params_ptr TSRMLS_CC);

	if (unlikely(free_params)) {
		efree(params);
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
int phalcon_call_func_params(zval **return_value_ptr, const char *func_name, uint func_length TSRMLS_DC, int param_count, ...)
{
	int status;
	va_list ap;

	va_start(ap, param_count);
	status = phalcon_call_func_vparams(return_value_ptr, func_name, func_length, param_count, ap TSRMLS_CC);
	va_end(ap);

	return status;
}

int phalcon_call_method_vparams(zval *return_value, zval **return_value_ptr, zval *object, const char *method_name, uint method_len, ulong method_key TSRMLS_DC, int param_count, va_list ap)
{
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
	}
	else {
		phalcon_check_return_value(return_value);
	}

	if (param_count < 0) {
		params      = va_arg(ap, zval**);
		param_count = -param_count;
		params_ptr  = params;
	}
	else if (param_count > 0 && param_count <= 10) {
		params_ptr = static_params;
		for (i=0; i<param_count; ++i) {
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

	ce           = Z_OBJCE_P(object);
	active_scope = EG(scope);
	EG(scope)    = ce;
	status       = phalcon_alt_call_user_method(ce, &object, (char*)method_name, method_len, return_value, return_value_ptr, param_count, params_ptr, method_key TSRMLS_CC);
	EG(scope)    = active_scope;

	if (unlikely(free_params)) {
		efree(params);
	}

	if (status == FAILURE && !EG(exception)) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined method %s::%s()", ce->name, method_name);
	}
	else if (EG(exception)) {
		status = FAILURE;
	}

	if (!caller_wants_result) {
		zval_ptr_dtor(&return_value);
	}

	return status;
}

/**
 * @brief Calls method @a method_name from @a object which accepts @a param_count arguments @a params
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
int phalcon_call_method_params(zval *return_value, zval **return_value_ptr, zval *object, const char *method_name, uint method_len, ulong method_key TSRMLS_DC, int param_count, ...)
{
	int status;
	va_list ap;

	va_start(ap, param_count);
	status = phalcon_call_method_vparams(return_value, return_value_ptr, object, method_name, method_len, method_key TSRMLS_CC, param_count, ap);
	va_end(ap);

	return status;
}

int phalcon_call_class_method_aparams(zval **return_value_ptr, const zend_class_entry *ce, zval *object, const char *method_name, uint method_len, uint param_count, zval **params TSRMLS_DC)
{
	zval *rv = NULL, **rvp = return_value_ptr ? return_value_ptr : &rv;
	zval fn = zval_used_for_init;
	int status;

#ifndef PHALCON_RELEASE
	if (return_value_ptr && *return_value_ptr) {
		fprintf(stderr, "%s: *return_value_ptr must be NULL\n", __func__);
		phalcon_print_backtrace();
		abort();
	}
#endif

	array_init_size(&fn, 2);
	add_next_index_stringl(&fn, ce->name, ce->name_length, 1);
	add_next_index_stringl(&fn, method_name, method_len, 1);

	status = phalcon_call_user_function(object ? &object : NULL, ce, &fn, rvp, param_count, params TSRMLS_CC);

	if (status == FAILURE && !EG(exception)) {
		zend_error(E_ERROR, "Call to undefined function %s::%s()", ce->name, method_name);
	}
	else if (EG(exception)) {
		status = FAILURE;
		if (return_value_ptr) {
			*return_value_ptr = NULL;
		}
	}

	if (rv) {
		zval_ptr_dtor(&rv);
	}

	zval_dtor(&fn);
	return status;
}

/**
 * Call single static function on a zval which requires parameters
 */
int phalcon_call_class_method_vparams(zval **return_value_ptr, const zend_class_entry *ce, zval *object, const char *method_name, uint method_len, int param_count, va_list ap TSRMLS_DC)
{
	zval **params_ptr, **params = NULL;
	zval *static_params[10];
	int free_params = 0, i, status;

	if (param_count < 0) {
		params      = va_arg(ap, zval**);
		param_count = -param_count;
		params_ptr  = params;
	}
	else if (param_count > 0 && param_count <= 10) {
		params_ptr = static_params;
		for (i=0; i<param_count; ++i) {
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

	status = phalcon_call_class_method_aparams(return_value_ptr, ce, object, method_name, method_len, param_count, params_ptr TSRMLS_CC);

	if (unlikely(free_params)) {
		efree(params);
	}

	return status;
}

int phalcon_call_class_method_params(zval **return_value_ptr, const zend_class_entry *ce, zval *object, const char *method_name, uint method_len TSRMLS_DC, int param_count, ...)
{
	int status;
	va_list ap;

	va_start(ap, param_count);
	status = phalcon_call_class_method_vparams(return_value_ptr, ce, object, method_name, method_len, param_count, ap TSRMLS_CC);
	va_end(ap);

	return status;
}

/**
 * Replaces call_user_func_array avoiding function lookup
 * This function does not return FAILURE if an exception has ocurred
 */
int phalcon_call_user_func_array_noex(zval *return_value, zval *handler, zval *params TSRMLS_DC){

	zval *retval_ptr = NULL;
	zend_fcall_info fci;
	zend_fcall_info_cache fci_cache;
	char *is_callable_error = NULL;
	int status = FAILURE;

	if (params && Z_TYPE_P(params) != IS_ARRAY) {
		ZVAL_NULL(return_value);
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for phalcon_call_user_func_array_noex()");
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

int phalcon_call_function(zend_fcall_info *fci, zend_fcall_info_cache *fci_cache TSRMLS_DC) {

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
			zend_error(E_ERROR, "Corrupted fcall_info provided to phalcon_call_function()");
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
		phalcon_throw_exception_internal(NULL TSRMLS_CC);
	}
	return SUCCESS;
}

#endif
