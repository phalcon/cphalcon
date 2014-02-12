
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

#if 0
static inline ulong phalcon_update_hash(const char *arKey, uint nKeyLength, ulong hash)
{
	for (; nKeyLength >= 8; nKeyLength -= 8) {
		hash = ((hash << 5) + hash) + *arKey++;
		hash = ((hash << 5) + hash) + *arKey++;
		hash = ((hash << 5) + hash) + *arKey++;
		hash = ((hash << 5) + hash) + *arKey++;
		hash = ((hash << 5) + hash) + *arKey++;
		hash = ((hash << 5) + hash) + *arKey++;
		hash = ((hash << 5) + hash) + *arKey++;
		hash = ((hash << 5) + hash) + *arKey++;
	}

	switch (nKeyLength) {
		case 7:  hash = ((hash << 5) + hash) + *arKey++;
		/* no break */
		case 6:  hash = ((hash << 5) + hash) + *arKey++;
		/* no break */
		case 5:  hash = ((hash << 5) + hash) + *arKey++;
		/* no break */
		case 4:  hash = ((hash << 5) + hash) + *arKey++;
		/* no break */
		case 3:  hash = ((hash << 5) + hash) + *arKey++;
		/* no break */
		case 2:  hash = ((hash << 5) + hash) + *arKey++;
		/* no break */
		case 1:  hash = ((hash << 5) + hash) + *arKey++;
		/* no break */
		default: break;
	}

	return hash;
}
#endif

static void phalcon_make_fcall_key(char **result, size_t *length, const zend_class_entry *obj_ce, zval *function_name TSRMLS_DC)
{
	const zend_class_entry *scope = obj_ce ? EG(scope) : NULL;
	char *buf = NULL, *c;
	size_t l = 0, len = 0;
	const size_t ppzce_size = sizeof(zend_class_entry**);

	if (Z_TYPE_P(function_name) == IS_STRING) {
		l   = (size_t)(Z_STRLEN_P(function_name)) + 1;
		c   = Z_STRVAL_P(function_name);
		len = 2 * ppzce_size + l;
		buf = ecalloc(1, len);

		memcpy(buf,                  c,       l - 1);
		memcpy(buf + l,              &scope,  ppzce_size);
		memcpy(buf + l + ppzce_size, &obj_ce, ppzce_size);
	}
	else if (Z_TYPE_P(function_name) == IS_ARRAY) {
		zval **method;
		if (
			    zend_hash_num_elements(Z_ARRVAL_P(function_name)) == 2
			 && zend_hash_index_find(Z_ARRVAL_P(function_name), 1, (void**)&method) == SUCCESS
			 && Z_TYPE_PP(method) == IS_STRING
		) {
			l   = (size_t)(Z_STRLEN_PP(method)) + 1;
			c   = Z_STRVAL_PP(method);
			len = 2 * ppzce_size + l;
			buf = ecalloc(1, len);

			memcpy(buf,                  c,       l - 1);
			memcpy(buf + l,              &scope,  ppzce_size);
			memcpy(buf + l + ppzce_size, &obj_ce, ppzce_size);
		}
	}
	else if (Z_TYPE_P(function_name) == IS_OBJECT) {
		if (Z_OBJ_HANDLER_P(function_name, get_closure)) {
			l   = sizeof("__invoke");
			len = 2 * ppzce_size + l;
			buf = ecalloc(1, len);

			memcpy(buf,                  "__invoke",  l - 1);
			memcpy(buf + l,              &scope,      ppzce_size);
			memcpy(buf + l + ppzce_size, &obj_ce,     ppzce_size);
		}
	}

	if (EXPECTED(buf != NULL)) {
		zend_str_tolower(buf, l - 1);
	}

	*result = buf;
	*length = len;
}

/**
 * Calls a function/method in the PHP userland
 */
int phalcon_call_user_function(zval **object_pp, zend_class_entry *obj_ce, phalcon_call_type type, zval *function_name, zval **retval_ptr_ptr, zend_uint param_count, zval *params[] TSRMLS_DC)
{
	zval ***params_ptr, ***params_array = NULL;
	zval **static_params_array[10];
	zval *local_retval_ptr = NULL;
	zend_uint i;
	int status;
	zend_fcall_info fci;
	zend_fcall_info_cache fcic;
	zend_phalcon_globals *phalcon_globals_ptr = PHALCON_VGLOBAL;
	char *fcall_key;
	size_t fcall_key_len;
	zend_bool cached = 0;
	zend_class_entry *old_scope = EG(scope);
	zend_function **func;

	if (retval_ptr_ptr && *retval_ptr_ptr) {
		zval_ptr_dtor(retval_ptr_ptr);
		*retval_ptr_ptr = NULL;
	}

	++phalcon_globals_ptr->recursive_lock;

	if (UNEXPECTED(phalcon_globals_ptr->recursive_lock > 2048)) {
		zend_error(E_ERROR, "Maximum recursion depth exceeded");
		return FAILURE;
	}

	if (param_count) {
		if (UNEXPECTED(param_count > 10)) {
			params_array = (zval***)emalloc(param_count * sizeof(zval**));
			params_ptr   = params_array;
			for (i=0; i<param_count; ++i) {
				params_array[i] = &params[i];
			}
		} else {
			params_ptr = static_params_array;
			for (i=0; i<param_count; ++i) {
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

	phalcon_make_fcall_key(&fcall_key, &fcall_key_len, obj_ce, function_name TSRMLS_CC);

	fci.size           = sizeof(fci);
	fci.function_table = obj_ce ? &obj_ce->function_table : EG(function_table);
	fci.object_ptr     = object_pp ? *object_pp : NULL;
	fci.function_name  = function_name;
	fci.retval_ptr_ptr = retval_ptr_ptr ? retval_ptr_ptr : &local_retval_ptr;
	fci.param_count    = param_count;
	fci.params         = params_ptr;
	fci.no_separation  = 1;
	fci.symbol_table   = NULL;

	if (fcall_key && zend_hash_find(phalcon_globals_ptr->fcache, fcall_key, fcall_key_len, (void**)&func) != FAILURE) {
		cached = 1;

		switch (type) {
			case phalcon_call_parent:
				if (EG(scope) && EG(scope)->parent) {
					fcic.calling_scope = EG(scope)->parent;
					fcic.called_scope  = EG(called_scope);
					fcic.object_ptr    = fci.object_ptr ? fci.object_ptr : EG(This);
					fcic.initialized   = 1;
				}

				break;

			case phalcon_call_self:
				if (EG(scope)) {
					fcic.calling_scope = EG(scope);
					fcic.called_scope  = EG(called_scope);
					fcic.object_ptr    = fci.object_ptr ? fci.object_ptr : EG(This);
					fcic.initialized   = 1;
				}

				break;

			case phalcon_call_static:
				if (EG(called_scope)) {
					fcic.calling_scope = EG(called_scope);
					fcic.called_scope  = EG(called_scope);
					fcic.object_ptr    = fci.object_ptr ? fci.object_ptr : EG(This);
					fcic.initialized   = 1;
				}

				break;

			case phalcon_call_function:
				fcic.calling_scope = NULL;
				fcic.called_scope  = NULL;
				fcic.object_ptr    = NULL;
				fcic.initialized   = 1;
				break;

			case phalcon_call_method:
			default:
				fcic.initialized      = 1;
				fcic.calling_scope    = obj_ce;
				fcic.object_ptr       = fci.object_ptr;
				if (object_pp) {
					fcic.called_scope = Z_OBJCE_PP(object_pp);
				}
				else if (obj_ce && !(EG(called_scope) && instanceof_function(EG(called_scope), obj_ce TSRMLS_CC))) {
					fcic.called_scope = obj_ce;
				}
				else {
					fcic.called_scope = EG(called_scope);
				}

				break;
		}

		fcic.function_handler = *func;
	}
	else {
		fcic.initialized = 0;
		if (obj_ce) {
			EG(scope) = obj_ce;
		}
	}

	status = PHALCON_ZEND_CALL_FUNCTION_WRAPPER(&fci, NULL TSRMLS_CC);

	EG(scope) = old_scope;

	if (EXPECTED(status != FAILURE) && fcall_key && !cached && fcic.initialized) {
		zend_hash_update(phalcon_globals_ptr->fcache, fcall_key, fcall_key_len, &(fcic.function_handler), sizeof(zend_function*), NULL);
	}

	if (fcall_key) {
		efree(fcall_key);
	}

	if (UNEXPECTED(params_array != NULL)) {
		efree(params_array);
	}

	if (!retval_ptr_ptr) {
		if (local_retval_ptr) {
			zval_ptr_dtor(&local_retval_ptr);
		}
	}

	--phalcon_globals_ptr->recursive_lock;
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
	status = phalcon_call_user_function(NULL, NULL, phalcon_call_function, &func, rvp, param_count, params TSRMLS_CC);

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

int phalcon_call_class_method_aparams(zval **return_value_ptr, zend_class_entry *ce, phalcon_call_type type, zval *object, const char *method_name, uint method_len, uint param_count, zval **params TSRMLS_DC)
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
	switch (type) {
		case phalcon_call_parent: add_next_index_stringl(&fn, ZEND_STRL("parent"), 1); break;
		case phalcon_call_self:   add_next_index_stringl(&fn, ZEND_STRL("self"), 1); break;
		case phalcon_call_static: add_next_index_stringl(&fn, ZEND_STRL("static"), 1); break;
		case phalcon_call_method:
		default:
			add_next_index_stringl(&fn, ce->name, ce->name_length, 1);
			break;
	}

	add_next_index_stringl(&fn, method_name, method_len, 1);

	status = phalcon_call_user_function(object ? &object : NULL, ce, type, &fn, rvp, param_count, params TSRMLS_CC);

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
