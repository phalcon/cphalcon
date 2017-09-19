
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2017 Zephir Team (http://www.zephir-lang.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@zephir-lang.com so we can send you a copy immediately.      |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@zephir-lang.com>                     |
  +------------------------------------------------------------------------+
*/

#include <php.h>
#include "php_ext.h"

#include <Zend/zend_API.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_execute.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/backtrace.h"

#if PHP_VERSION_ID >= 50600

#if ZEND_MODULE_API_NO >= 20141001
void zephir_clean_and_cache_symbol_table(zend_array *symbol_table)
{
	if (EG(symtable_cache_ptr) >= EG(symtable_cache_limit)) {
		zend_array_destroy(symbol_table);
	} else {
		zend_symtable_clean(symbol_table);
		*(++EG(symtable_cache_ptr)) = symbol_table;
	}
}
#else
void zephir_clean_and_cache_symbol_table(HashTable *symbol_table TSRMLS_DC)
{
	if (EG(symtable_cache_ptr) >= EG(symtable_cache_limit)) {
		zend_hash_destroy(symbol_table);
		FREE_HASHTABLE(symbol_table);
	} else {
		zend_hash_clean(symbol_table);
		*(++EG(symtable_cache_ptr)) = symbol_table;
	}
}
#endif

/**
 * Latest version of zend_throw_exception_internal
 */
static void zephir_throw_exception_internal(zval *exception TSRMLS_DC)
{
	if (exception != NULL) {
		zval *previous = EG(exception);
		zend_exception_set_previous(exception, EG(exception) TSRMLS_CC);
		EG(exception) = exception;
		if (previous) {
			return;
		}
	}

	if (!EG(current_execute_data)) {
		if (EG(exception)) {
			zend_exception_error(EG(exception), E_ERROR TSRMLS_CC);
		}
		zend_error(E_ERROR, "Exception thrown without a stack frame");
	}

	if (zend_throw_exception_hook) {
		zend_throw_exception_hook(exception TSRMLS_CC);
	}

	if (EG(current_execute_data)->opline == NULL ||
		(EG(current_execute_data)->opline + 1)->opcode == ZEND_HANDLE_EXCEPTION) {
		/* no need to rethrow the exception */
		return;
	}

	EG(opline_before_exception) = EG(current_execute_data)->opline;
	EG(current_execute_data)->opline = EG(exception_op);
}

int zephir_call_func_aparams_fast(zval **return_value_ptr, zephir_fcall_cache_entry **cache_entry, zend_uint param_count, zval *pparams[] TSRMLS_DC)
{
	zend_uint i;
	zval **original_return_value;
	HashTable *calling_symbol_table;
	zend_op_array *original_op_array;
	zend_op **original_opline_ptr;
	zend_class_entry *current_scope;
	zend_class_entry *current_called_scope;
	zend_class_entry *calling_scope = NULL;
	zend_class_entry *called_scope = NULL;
	zend_execute_data execute_data;
	zval ***params, ***params_array = NULL;
	zval **static_params_array[10];
	zend_class_entry *old_scope = EG(scope);
	zend_function_state *function_state = &EX(function_state);
	zend_function *func;
	zval *rv = NULL, **retval_ptr_ptr = return_value_ptr ? return_value_ptr : &rv;

	if (retval_ptr_ptr && *retval_ptr_ptr) {
		zval_ptr_dtor(retval_ptr_ptr);
		*retval_ptr_ptr = NULL;
	}

	if (param_count) {

		if (UNEXPECTED(param_count > 10)) {
			params_array = (zval***) emalloc(param_count * sizeof(zval**));
			params   = params_array;
			for (i = 0; i < param_count; ++i) {
				params_array[i] = &pparams[i];
			}
		} else {
			params = static_params_array;
			for (i = 0; i < param_count; ++i) {
				static_params_array[i] = &pparams[i];
			}
		}
	} else {
		params = NULL;
	}

	if (!EG(active)) {
		return FAILURE; /* executor is already inactive */
	}

	if (EG(exception)) {
		return FAILURE; /* we would result in an instable executor otherwise */
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

#ifndef ZEPHIR_RELEASE
	function_state->function = (*cache_entry)->f;
	++(*cache_entry)->times;
#else
	function_state->function = *cache_entry;
#endif
	func = function_state->function;

	calling_scope = NULL;
	called_scope = NULL;
	EX(object) = NULL;

	ZEND_VM_STACK_GROW_IF_NEEDED(param_count + 1);

	for (i = 0; i < param_count; i++) {
		zval *param;

		if (ARG_SHOULD_BE_SENT_BY_REF(func, i + 1)) {
			if (!PZVAL_IS_REF(*params[i]) && Z_REFCOUNT_PP(params[i]) > 1) {
				zval *new_zval;

				if (!ARG_MAY_BE_SENT_BY_REF(func, i + 1)) {
					if (i || UNEXPECTED(ZEND_VM_STACK_ELEMETS(EG(argument_stack)) == (EG(argument_stack)->top))) {
						/* hack to clean up the stack */
						zend_vm_stack_push((void *) (zend_uintptr_t)i TSRMLS_CC);
						zend_vm_stack_clear_multiple(0 TSRMLS_CC);
					}

					zend_error(E_WARNING, "Parameter %d to %s%s%s() expected to be a reference, value given",
						i+1,
						func->common.scope ? func->common.scope->name : "",
						func->common.scope ? "::" : "",
						func->common.function_name);
					return FAILURE;
				}

				ALLOC_ZVAL(new_zval);
				*new_zval = **params[i];
				zval_copy_ctor(new_zval);
				Z_SET_REFCOUNT_P(new_zval, 1);
				Z_DELREF_PP(params[i]);
				*params[i] = new_zval;
			}
			Z_ADDREF_PP(params[i]);
			Z_SET_ISREF_PP(params[i]);
			param = *params[i];
		} else if (PZVAL_IS_REF(*params[i]) && (func->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER) == 0 ) {
			ALLOC_ZVAL(param);
			*param = **(params[i]);
			INIT_PZVAL(param);
			zval_copy_ctor(param);
		} else if (*params[i] != &EG(uninitialized_zval)) {
			Z_ADDREF_PP(params[i]);
			param = *params[i];
		} else {
			ALLOC_ZVAL(param);
			*param = **(params[i]);
			INIT_PZVAL(param);
		}
		zend_vm_stack_push(param TSRMLS_CC);
	}

	function_state->arguments = zend_vm_stack_top(TSRMLS_C);
	zend_vm_stack_push((void*)(zend_uintptr_t)param_count TSRMLS_CC);

	current_scope = EG(scope);
	EG(scope) = calling_scope;

	current_called_scope = EG(called_scope);
	if (called_scope) {
		EG(called_scope) = called_scope;
	} else if (func->type != ZEND_INTERNAL_FUNCTION) {
		EG(called_scope) = NULL;
	}

	EX(prev_execute_data) = EG(current_execute_data);
	EG(current_execute_data) = &execute_data;

	if (func->type == ZEND_USER_FUNCTION) {

		calling_symbol_table = EG(active_symbol_table);
		EG(scope) = func->common.scope;
		EG(active_symbol_table) = NULL;

		original_return_value = EG(return_value_ptr_ptr);
		original_op_array = EG(active_op_array);
		EG(return_value_ptr_ptr) = retval_ptr_ptr;
		EG(active_op_array) = (zend_op_array *) function_state->function;
		original_opline_ptr = EG(opline_ptr);

		zend_execute(EG(active_op_array) TSRMLS_CC);

		if (EG(active_symbol_table)) {
			zephir_clean_and_cache_symbol_table(EG(active_symbol_table) TSRMLS_CC);
		}
		EG(active_symbol_table) = calling_symbol_table;
		EG(active_op_array) = original_op_array;
		EG(return_value_ptr_ptr)=original_return_value;
		EG(opline_ptr) = original_opline_ptr;
	} else if (func->type == ZEND_INTERNAL_FUNCTION) {

		ALLOC_INIT_ZVAL(*retval_ptr_ptr);
		if (func->common.scope) {
			EG(scope) = func->common.scope;
		}

		func->internal_function.handler(param_count, *retval_ptr_ptr, retval_ptr_ptr, NULL, 1 TSRMLS_CC);

		if (EG(exception) && retval_ptr_ptr) {
			zval_ptr_dtor(retval_ptr_ptr);
			*retval_ptr_ptr = NULL;
		}

	} else { /* ZEND_OVERLOADED_FUNCTION */
		ALLOC_INIT_ZVAL(*retval_ptr_ptr);

		/* Not sure what should be done here if it's a static method */
		zend_error(E_ERROR, "Cannot call overloaded function for non-object");

		if (func->type == ZEND_OVERLOADED_FUNCTION_TEMPORARY) {
			efree((char*)func->common.function_name);
		}
		efree(function_state->function);

		if (EG(exception) && retval_ptr_ptr) {
			zval_ptr_dtor(retval_ptr_ptr);
			*retval_ptr_ptr = NULL;
		}
	}
	zend_vm_stack_clear_multiple(0 TSRMLS_CC);

	EG(called_scope) = current_called_scope;
	EG(scope) = current_scope;
	EG(current_execute_data) = EX(prev_execute_data);

	if (EG(exception)) {
		zephir_throw_exception_internal(NULL TSRMLS_CC);
	}

	EG(scope) = old_scope;

	if (UNEXPECTED(params_array != NULL)) {
		efree(params_array);
	}

	if (rv) {
		zval_ptr_dtor(&rv);
	}

	return SUCCESS;
}

static int zephir_is_callable_check_class(const char *name, int name_len, zend_fcall_info_cache *fcc, int *strict_class, char **error TSRMLS_DC) /* {{{ */
{
	int ret = 0;
	zend_class_entry **pce;
	char *lcname = zend_str_tolower_dup(name, name_len);

	*strict_class = 0;
	if (name_len == sizeof("self") - 1 &&
		!memcmp(lcname, "self", sizeof("self") - 1)) {
		if (!EG(scope)) {
			if (error) *error = estrdup("cannot access self:: when no class scope is active");
		} else {
			fcc->called_scope = EG(called_scope);
			fcc->calling_scope = EG(scope);
			if (!fcc->object_ptr) {
				fcc->object_ptr = EG(This);
			}
			ret = 1;
		}
	} else if (name_len == sizeof("parent") - 1 &&
			   !memcmp(lcname, "parent", sizeof("parent") - 1)) {
		if (!EG(scope)) {
			if (error) *error = estrdup("cannot access parent:: when no class scope is active");
		} else if (!EG(scope)->parent) {
			if (error) *error = estrdup("cannot access parent:: when current class scope has no parent");
		} else {
			fcc->called_scope = EG(called_scope);
			fcc->calling_scope = EG(scope)->parent;
			if (!fcc->object_ptr) {
				fcc->object_ptr = EG(This);
			}
			*strict_class = 1;
			ret = 1;
		}
	} else if (name_len == sizeof("static") - 1 &&
			   !memcmp(lcname, "static", sizeof("static") - 1)) {
		if (!EG(called_scope)) {
			if (error) *error = estrdup("cannot access static:: when no class scope is active");
		} else {
			fcc->called_scope = EG(called_scope);
			fcc->calling_scope = EG(called_scope);
			if (!fcc->object_ptr) {
				fcc->object_ptr = EG(This);
			}
			*strict_class = 1;
			ret = 1;
		}
	} else if (zend_lookup_class_ex(name, name_len, NULL, 1, &pce TSRMLS_CC) == SUCCESS) {
		zend_class_entry *scope = EG(active_op_array) ? EG(active_op_array)->scope : NULL;

		fcc->calling_scope = *pce;
		if (scope && !fcc->object_ptr && EG(This) &&
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
		if (error) zephir_spprintf(error, 0, "class '%.*s' not found", name_len, name);
	}
	efree(lcname);
	return ret;
}

static int zephir_is_callable_check_func(int check_flags, zval *callable, zend_fcall_info_cache *fcc, int strict_class, char **error TSRMLS_DC) /* {{{ */
{
	zend_class_entry *ce_org = fcc->calling_scope;
	int retval = 0;
	char *mname, *lmname;
	const char *colon;
	int clen, mlen;
	zend_class_entry *last_scope;
	HashTable *ftable;
	int call_via_handler = 0;

	if (error) {
		*error = NULL;
	}

	fcc->calling_scope = NULL;
	fcc->function_handler = NULL;

	if (!ce_org) {
		/* Skip leading \ */
		if (Z_STRVAL_P(callable)[0] == '\\') {
			mlen = Z_STRLEN_P(callable) - 1;
			lmname = zend_str_tolower_dup(Z_STRVAL_P(callable) + 1, mlen);
		} else {
			mlen = Z_STRLEN_P(callable);
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
	if ((colon = zend_memrchr(Z_STRVAL_P(callable), ':', Z_STRLEN_P(callable))) != NULL &&
		colon > Z_STRVAL_P(callable) &&
		*(colon-1) == ':'
	) {
		colon--;
		clen = colon - Z_STRVAL_P(callable);
		mlen = Z_STRLEN_P(callable) - clen - 2;

		if (colon == Z_STRVAL_P(callable)) {
			if (error) zephir_spprintf(error, 0, "invalid function name");
			return 0;
		}

		/* This is a compound name.
		 * Try to fetch class and then find static method. */
		last_scope = EG(scope);
		if (ce_org) {
			EG(scope) = ce_org;
		}

		if (!zephir_is_callable_check_class(Z_STRVAL_P(callable), clen, fcc, &strict_class, error TSRMLS_CC)) {
			EG(scope) = last_scope;
			return 0;
		}
		EG(scope) = last_scope;

		ftable = &fcc->calling_scope->function_table;
		if (ce_org && !instanceof_function(ce_org, fcc->calling_scope TSRMLS_CC)) {
			if (error) zephir_spprintf(error, 0, "class '%s' is not a subclass of '%s'", ce_org->name, fcc->calling_scope->name);
			return 0;
		}
		mname = Z_STRVAL_P(callable) + clen + 2;
	} else if (ce_org) {
		/* Try to fetch find static method of given class. */
		mlen = Z_STRLEN_P(callable);
		mname = Z_STRVAL_P(callable);
		ftable = &ce_org->function_table;
		fcc->calling_scope = ce_org;
	} else {
		/* We already checked for plain function before. */
		if (error && !(check_flags & IS_CALLABLE_CHECK_SILENT)) {
			zephir_spprintf(error, 0, "function '%s' not found or invalid function name", Z_STRVAL_P(callable));
		}
		return 0;
	}

	lmname = zend_str_tolower_dup(mname, mlen);
	if (strict_class &&
		fcc->calling_scope &&
		mlen == sizeof(ZEND_CONSTRUCTOR_FUNC_NAME)-1 &&
		!memcmp(lmname, ZEND_CONSTRUCTOR_FUNC_NAME, sizeof(ZEND_CONSTRUCTOR_FUNC_NAME) - 1)) {
		fcc->function_handler = fcc->calling_scope->constructor;
		if (fcc->function_handler) {
			retval = 1;
		}
	} else if (zend_hash_find(ftable, lmname, mlen+1, (void**)&fcc->function_handler) == SUCCESS) {
		retval = 1;
		if ((fcc->function_handler->op_array.fn_flags & ZEND_ACC_CHANGED) &&
			!strict_class && EG(scope) &&
			instanceof_function(fcc->function_handler->common.scope, EG(scope) TSRMLS_CC)) {
			zend_function *priv_fbc;

			if (zend_hash_find(&EG(scope)->function_table, lmname, mlen+1, (void **) &priv_fbc)==SUCCESS
				&& priv_fbc->common.fn_flags & ZEND_ACC_PRIVATE
				&& priv_fbc->common.scope == EG(scope)) {
				fcc->function_handler = priv_fbc;
			}
		}
	} else {
		if (fcc->object_ptr && fcc->calling_scope == ce_org) {
			if (strict_class && ce_org->__call) {
				fcc->function_handler = emalloc(sizeof(zend_internal_function));
				fcc->function_handler->internal_function.type = ZEND_INTERNAL_FUNCTION;
				fcc->function_handler->internal_function.module = (ce_org->type == ZEND_INTERNAL_CLASS) ? ce_org->info.internal.module : NULL;
				fcc->function_handler->internal_function.handler = zend_std_call_user_call;
				fcc->function_handler->internal_function.arg_info = NULL;
				fcc->function_handler->internal_function.num_args = 0;
				fcc->function_handler->internal_function.scope = ce_org;
				fcc->function_handler->internal_function.fn_flags = ZEND_ACC_CALL_VIA_HANDLER;
				fcc->function_handler->internal_function.function_name = estrndup(mname, mlen);
				call_via_handler = 1;
				retval = 1;
			} else if (Z_OBJ_HT_P(fcc->object_ptr)->get_method) {
				fcc->function_handler = Z_OBJ_HT_P(fcc->object_ptr)->get_method(&fcc->object_ptr, mname, mlen, NULL TSRMLS_CC);
				if (fcc->function_handler) {
					if (strict_class &&
						(!fcc->function_handler->common.scope ||
						 !instanceof_function(ce_org, fcc->function_handler->common.scope TSRMLS_CC))) {
						if ((fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER) != 0) {
							if (fcc->function_handler->type != ZEND_OVERLOADED_FUNCTION) {
								efree((char*)fcc->function_handler->common.function_name);
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
				fcc->function_handler = zend_std_get_static_method(fcc->calling_scope, mname, mlen, NULL TSRMLS_CC);
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

	if (retval) {
		if (fcc->calling_scope && !call_via_handler) {
			if (!fcc->object_ptr && (fcc->function_handler->common.fn_flags & ZEND_ACC_ABSTRACT)) {
				if (error) {
					zephir_spprintf(error, 0, "cannot call abstract method %s::%s()", fcc->calling_scope->name, fcc->function_handler->common.function_name);
					retval = 0;
				} else {
					zend_error(E_ERROR, "Cannot call abstract method %s::%s()", fcc->calling_scope->name, fcc->function_handler->common.function_name);
				}
			} else if (!fcc->object_ptr && !(fcc->function_handler->common.fn_flags & ZEND_ACC_STATIC)) {
				int severity;
				char *verb;
				if (fcc->function_handler->common.fn_flags & ZEND_ACC_ALLOW_STATIC) {
					severity = E_STRICT;
					verb = "should not";
				} else {
					/* An internal function assumes $this is present and won't check that. So PHP would crash by allowing the call. */
					severity = E_ERROR;
					verb = "cannot";
				}
				if ((check_flags & IS_CALLABLE_CHECK_IS_STATIC) != 0) {
					retval = 0;
				}
				if (EG(This) && instanceof_function(Z_OBJCE_P(EG(This)), fcc->calling_scope TSRMLS_CC)) {
					fcc->object_ptr = EG(This);
					if (error) {
						zephir_spprintf(error, 0, "non-static method %s::%s() %s be called statically, assuming $this from compatible context %s", fcc->calling_scope->name, fcc->function_handler->common.function_name, verb, Z_OBJCE_P(EG(This))->name);
						if (severity == E_ERROR) {
							retval = 0;
						}
					} else if (retval) {
						zend_error(severity, "Non-static method %s::%s() %s be called statically, assuming $this from compatible context %s", fcc->calling_scope->name, fcc->function_handler->common.function_name, verb, Z_OBJCE_P(EG(This))->name);
					}
				} else {
					if (error) {
						zephir_spprintf(error, 0, "non-static method %s::%s() %s be called statically", fcc->calling_scope->name, fcc->function_handler->common.function_name, verb);
						if (severity == E_ERROR) {
							retval = 0;
						}
					} else if (retval) {
						zend_error(severity, "Non-static method %s::%s() %s be called statically", fcc->calling_scope->name, fcc->function_handler->common.function_name, verb);
					}
				}
			}
		}
	} else if (error && !(check_flags & IS_CALLABLE_CHECK_SILENT)) {
		if (fcc->calling_scope) {
			if (error) zephir_spprintf(error, 0, "class '%s' does not have a method '%s'", fcc->calling_scope->name, mname);
		} else {
			if (error) zephir_spprintf(error, 0, "function '%s' does not exist", mname);
		}
	}
	efree(lmname);

	if (fcc->object_ptr) {
		fcc->called_scope = Z_OBJCE_P(fcc->object_ptr);
	}
	if (retval) {
		fcc->initialized = 1;
	}
	return retval;
}

static zend_bool zephir_is_callable_ex(zval *callable, zval *object_ptr, uint check_flags, char **callable_name, int *callable_name_len, zend_fcall_info_cache *fcc, char **error TSRMLS_DC) /* {{{ */
{
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
			if (object_ptr) {
				fcc->object_ptr = object_ptr;
				fcc->calling_scope = Z_OBJCE_P(object_ptr);
				if (callable_name) {
					char *ptr;

					*callable_name_len = fcc->calling_scope->name_length + Z_STRLEN_P(callable) + sizeof("::") - 1;
					ptr = *callable_name = emalloc(*callable_name_len + 1);
					memcpy(ptr, fcc->calling_scope->name, fcc->calling_scope->name_length);
					ptr += fcc->calling_scope->name_length;
					memcpy(ptr, "::", sizeof("::") - 1);
					ptr += sizeof("::") - 1;
					memcpy(ptr, Z_STRVAL_P(callable), Z_STRLEN_P(callable) + 1);
				}
			} else if (callable_name) {
				*callable_name = estrndup(Z_STRVAL_P(callable), Z_STRLEN_P(callable));
				*callable_name_len = Z_STRLEN_P(callable);
			}
			if (check_flags & IS_CALLABLE_CHECK_SYNTAX_ONLY) {
				fcc->called_scope = fcc->calling_scope;
				return 1;
			}

			ret = zephir_is_callable_check_func(check_flags, callable, fcc, 0, error TSRMLS_CC);
			if (fcc == &fcc_local &&
				fcc->function_handler &&
				((fcc->function_handler->type == ZEND_INTERNAL_FUNCTION &&
				  (fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER)) ||
				 fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION_TEMPORARY ||
				 fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION)) {
				if (fcc->function_handler->type != ZEND_OVERLOADED_FUNCTION) {
					efree((char*)fcc->function_handler->common.function_name);
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

						if (!zephir_is_callable_check_class(Z_STRVAL_PP(obj), Z_STRLEN_PP(obj), fcc, &strict_class, error TSRMLS_CC)) {
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

					ret = zephir_is_callable_check_func(check_flags, *method, fcc, strict_class, error TSRMLS_CC);
					if (fcc == &fcc_local &&
						fcc->function_handler &&
						((fcc->function_handler->type == ZEND_INTERNAL_FUNCTION &&
						  (fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER)) ||
						 fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION_TEMPORARY ||
						 fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION)) {
						if (fcc->function_handler->type != ZEND_OVERLOADED_FUNCTION) {
							efree((char*)fcc->function_handler->common.function_name);
						}
						efree(fcc->function_handler);
					}
					return ret;

				} else {
					if (zend_hash_num_elements(Z_ARRVAL_P(callable)) == 2) {
						if (!obj || (Z_TYPE_PP(obj) != IS_STRING && Z_TYPE_PP(obj) != IS_OBJECT)) {
							if (error) zephir_spprintf(error, 0, "first array member is not a valid class name or object");
						} else {
							if (error) zephir_spprintf(error, 0, "second array member is not a valid method");
						}
					} else {
						if (error) zephir_spprintf(error, 0, "array must have exactly two members");
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
			if (error) zephir_spprintf(error, 0, "no array or string given");
			return 0;
	}
}

static zend_bool zephir_is_info_dynamic_callable(zephir_fcall_info *info, zend_fcall_info_cache *fcc, zend_class_entry *ce_org, int strict_class TSRMLS_DC)
{
	int call_via_handler = 0, retval = 0;
	char *lcname = zend_str_tolower_dup(info->func_name, info->func_length);

	if (fcc->object_ptr && fcc->calling_scope == ce_org) {
		if (strict_class && ce_org->__call) {
			fcc->function_handler = emalloc(sizeof(zend_internal_function));
			fcc->function_handler->internal_function.type = ZEND_INTERNAL_FUNCTION;
			fcc->function_handler->internal_function.module = (ce_org->type == ZEND_INTERNAL_CLASS) ? ce_org->info.internal.module : NULL;
			fcc->function_handler->internal_function.handler = zend_std_call_user_call;
			fcc->function_handler->internal_function.arg_info = NULL;
			fcc->function_handler->internal_function.num_args = 0;
			fcc->function_handler->internal_function.scope = ce_org;
			fcc->function_handler->internal_function.fn_flags = ZEND_ACC_CALL_VIA_HANDLER;
			fcc->function_handler->internal_function.function_name = estrndup(lcname, info->func_length);
			call_via_handler = 1;
			retval = 1;
		} else if (Z_OBJ_HT_P(fcc->object_ptr)->get_method) {
			fcc->function_handler = Z_OBJ_HT_P(fcc->object_ptr)->get_method(&fcc->object_ptr, lcname, info->func_length, NULL TSRMLS_CC);
			if (fcc->function_handler) {
				if (strict_class &&
					(!fcc->function_handler->common.scope ||
					 !instanceof_function(ce_org, fcc->function_handler->common.scope TSRMLS_CC))) {
					if ((fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER) != 0) {
						if (fcc->function_handler->type != ZEND_OVERLOADED_FUNCTION) {
							efree((char*)fcc->function_handler->common.function_name);
						}
						efree(fcc->function_handler);
					}
				} else {
					call_via_handler = (fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER) != 0;
					retval = 1;
				}
			}
		}
	} else if (fcc->calling_scope) {
		if (fcc->calling_scope->get_static_method) {
			fcc->function_handler = fcc->calling_scope->get_static_method(fcc->calling_scope, lcname, info->func_length TSRMLS_CC);
		} else {
			fcc->function_handler = zend_std_get_static_method(fcc->calling_scope, lcname, info->func_length, NULL TSRMLS_CC);
		}
		if (fcc->function_handler) {
			call_via_handler = (fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER) != 0;
			if (call_via_handler && !fcc->object_ptr && EG(This) &&
				Z_OBJ_HT_P(EG(This))->get_class_entry &&
				instanceof_function(Z_OBJCE_P(EG(This)), fcc->calling_scope TSRMLS_CC)) {
				fcc->object_ptr = EG(This);
			}
			retval = 1;
		}
	}

	efree(lcname);
	return retval;
}

static zend_bool zephir_is_info_callable_ex(zephir_fcall_info *info, zend_fcall_info_cache *fcc TSRMLS_DC)
{
	int retval = 0;
	zend_class_entry *ce_org = fcc->calling_scope;
	zend_fcall_info_cache fcc_local;

	if (fcc == NULL) {
		fcc = &fcc_local;
	}

	fcc->initialized = 0;
	fcc->calling_scope = NULL;
	fcc->called_scope = NULL;
	fcc->function_handler = NULL;
	fcc->object_ptr = NULL;

	switch (info->type) {

		case ZEPHIR_FCALL_TYPE_FUNC:

			if (zend_hash_find(EG(function_table), info->func_name, info->func_length + 1, (void**)&fcc->function_handler) == SUCCESS) {
				if (fcc == &fcc_local &&
					fcc->function_handler &&
					((fcc->function_handler->type == ZEND_INTERNAL_FUNCTION &&
					  (fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER)) ||
					 fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION_TEMPORARY ||
					 fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION)) {
					if (fcc->function_handler->type != ZEND_OVERLOADED_FUNCTION) {
						efree((char*)fcc->function_handler->common.function_name);
					}
					efree(fcc->function_handler);
				}
				fcc->initialized = 1;
				return 1;
			}
			break;

		case ZEPHIR_FCALL_TYPE_ZVAL_METHOD:

			if (!EG(objects_store).object_buckets || !EG(objects_store).object_buckets[Z_OBJ_HANDLE_P(info->object_ptr)].valid) {
				return 0;
			}

			fcc->calling_scope = Z_OBJCE_P(info->object_ptr); /* TBFixed: what if it's overloaded? */
			fcc->called_scope = fcc->calling_scope;
			fcc->object_ptr = info->object_ptr;
			if (!ce_org) {
				ce_org = fcc->calling_scope;
			}

			if (zend_hash_find(&info->ce->function_table, info->func_name, info->func_length + 1, (void**)&fcc->function_handler) == SUCCESS) {
				if (fcc == &fcc_local &&
					fcc->function_handler &&
					((fcc->function_handler->type == ZEND_INTERNAL_FUNCTION &&
					  (fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER)) ||
					 fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION_TEMPORARY ||
					 fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION)) {
					if (fcc->function_handler->type != ZEND_OVERLOADED_FUNCTION) {
						efree((char*)fcc->function_handler->common.function_name);
					}
					efree(fcc->function_handler);
				}
				retval = 1;
			}

			if (!retval) {
				retval = zephir_is_info_dynamic_callable(info, fcc, ce_org, 0 TSRMLS_CC);
			}
			break;

		case ZEPHIR_FCALL_TYPE_CLASS_SELF_METHOD:

			if (!EG(scope)) {
				return 0; // cannot access self:: when no class scope is active
			}

			fcc->called_scope = EG(called_scope);
			fcc->calling_scope = EG(scope);
			if (!fcc->object_ptr) {
				fcc->object_ptr = EG(This);
			}

			if (zend_hash_find(&fcc->calling_scope->function_table, info->func_name, info->func_length + 1, (void**)&fcc->function_handler) == SUCCESS) {
				if (fcc == &fcc_local &&
					fcc->function_handler &&
					((fcc->function_handler->type == ZEND_INTERNAL_FUNCTION &&
					  (fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER)) ||
					 fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION_TEMPORARY ||
					 fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION)) {
					if (fcc->function_handler->type != ZEND_OVERLOADED_FUNCTION) {
						efree((char*)fcc->function_handler->common.function_name);
					}
					efree(fcc->function_handler);
				}
				retval = 1;
			}

			if (!retval) {
				retval = zephir_is_info_dynamic_callable(info, fcc, ce_org, 0 TSRMLS_CC);
			}
			break;

		case ZEPHIR_FCALL_TYPE_CLASS_PARENT_METHOD:

			if (!EG(scope)) {
				return 0; // cannot access parent:: when no class scope is active
			}

			if (!EG(scope)->parent) {
				return 0; // cannot access parent:: when current class scope has no parent
			}

			fcc->called_scope = EG(called_scope);
			fcc->calling_scope = EG(scope)->parent;
			if (!fcc->object_ptr) {
				fcc->object_ptr = EG(This);
			}

			if (zend_hash_find(&fcc->calling_scope->function_table, info->func_name, info->func_length + 1, (void**)&fcc->function_handler) == SUCCESS) {
				if (fcc == &fcc_local &&
					fcc->function_handler &&
					((fcc->function_handler->type == ZEND_INTERNAL_FUNCTION &&
					  (fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER)) ||
					 fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION_TEMPORARY ||
					 fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION)) {
					if (fcc->function_handler->type != ZEND_OVERLOADED_FUNCTION) {
						efree((char*)fcc->function_handler->common.function_name);
					}
					efree(fcc->function_handler);
				}
				retval = 1;
			}

			if (!retval) {
				retval = zephir_is_info_dynamic_callable(info, fcc, ce_org, 1 TSRMLS_CC);
			}
			break;

		case ZEPHIR_FCALL_TYPE_CLASS_STATIC_METHOD:

			if (!EG(called_scope)) {
				return 0; // cannot access static:: when no class scope is active
			}

			fcc->called_scope = EG(called_scope);
			fcc->calling_scope = EG(called_scope);
			if (!fcc->object_ptr) {
				fcc->object_ptr = EG(This);
			}

			if (zend_hash_find(&fcc->calling_scope->function_table, info->func_name, info->func_length + 1, (void**)&fcc->function_handler) == SUCCESS) {
				if (fcc == &fcc_local &&
					fcc->function_handler &&
					((fcc->function_handler->type == ZEND_INTERNAL_FUNCTION &&
					  (fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER)) ||
					 fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION_TEMPORARY ||
					 fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION)) {
					if (fcc->function_handler->type != ZEND_OVERLOADED_FUNCTION) {
						efree((char*)fcc->function_handler->common.function_name);
					}
					efree(fcc->function_handler);
				}
				retval = 1;
			}

			if (!retval) {
				retval = zephir_is_info_dynamic_callable(info, fcc, ce_org, 1 TSRMLS_CC);
			}
			break;

		case ZEPHIR_FCALL_TYPE_CE_METHOD:
			{
				zend_class_entry *scope = EG(active_op_array) ? EG(active_op_array)->scope : NULL;

				fcc->calling_scope = info->ce;
				if (scope && !fcc->object_ptr && EG(This) &&
					instanceof_function(Z_OBJCE_P(EG(This)), scope TSRMLS_CC) &&
					instanceof_function(scope, fcc->calling_scope TSRMLS_CC)) {
					fcc->object_ptr = EG(This);
					fcc->called_scope = Z_OBJCE_P(fcc->object_ptr);
				} else {
					fcc->called_scope = fcc->object_ptr ? Z_OBJCE_P(fcc->object_ptr) : fcc->calling_scope;
				}

				if (zend_hash_find(&fcc->calling_scope->function_table, info->func_name, info->func_length + 1, (void**)&fcc->function_handler) == SUCCESS) {
					if (fcc == &fcc_local &&
						fcc->function_handler &&
						((fcc->function_handler->type == ZEND_INTERNAL_FUNCTION &&
						  (fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER)) ||
						 fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION_TEMPORARY ||
						 fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION)) {
						if (fcc->function_handler->type != ZEND_OVERLOADED_FUNCTION) {
							efree((char*)fcc->function_handler->common.function_name);
						}
						efree(fcc->function_handler);
					}
					retval = 1;
				}

				if (!retval) {
					retval = zephir_is_info_dynamic_callable(info, fcc, ce_org, 1 TSRMLS_CC);
				}
			}
			break;
	}

	if (fcc->object_ptr) {
		fcc->called_scope = Z_OBJCE_P(fcc->object_ptr);
	}
	if (retval) {
		fcc->initialized = 1;
	}

	return retval;
}

int zephir_call_function_opt(zend_fcall_info *fci, zend_fcall_info_cache *fci_cache, zephir_fcall_info *info TSRMLS_DC)
{
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
	zend_fcall_info_cache fci_cache_local;
	zend_uint fn_flags;

	*fci->retval_ptr_ptr = NULL;

	if (!EG(active)) {
		return FAILURE; /* executor is already inactive */
	}

	if (EG(exception)) {
		return FAILURE; /* we would result in an instable executor otherwise */
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
		char *callable_name;
		char *error = NULL;

		if (!fci_cache) {
			fci_cache = &fci_cache_local;
		}

		if (!info) {
			if (!zephir_is_callable_ex(fci->function_name, fci->object_ptr, IS_CALLABLE_CHECK_SILENT, &callable_name, NULL, fci_cache, &error TSRMLS_CC)) {
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
					zend_error(E_STRICT, "%s", error);
					efree(error);
				}
			}
			efree(callable_name);
		} else {
			if (!zephir_is_info_callable_ex(info, fci_cache TSRMLS_CC)) {
				return FAILURE;
			}
		}
	}

#ifndef ZEPHIR_RELEASE
	/*fprintf(stderr, "initialized: %d\n", fci_cache->initialized);
	if (fci_cache->function_handler) {
		if (fci_cache->function_handler->type == ZEND_INTERNAL_FUNCTION) {
			fprintf(stderr, "function handler: %s\n", fci_cache->function_handler->common.function_name);
		} else {
			fprintf(stderr, "function handler: %s\n", "unknown");
		}
	} else {
		fprintf(stderr, "function handler: NONE\n");
	}
	if (fci_cache->calling_scope) {
		fprintf(stderr, "real calling_scope: %s (%p)\n", fci_cache->calling_scope->name, fci_cache->calling_scope);
	} else {
		fprintf(stderr, "real calling_scope: NONE\n");
	}
	if (fci_cache->called_scope) {
		fprintf(stderr, "real called_scope: %s (%p)\n", fci_cache->called_scope->name, fci_cache->called_scope);
	} else {
		fprintf(stderr, "real called_scope: NONE\n");
	}*/
#endif

	EX(function_state).function = fci_cache->function_handler;
	calling_scope = fci_cache->calling_scope;
	called_scope = fci_cache->called_scope;
	fci->object_ptr = fci_cache->object_ptr;
	EX(object) = fci->object_ptr;

	if (fci->object_ptr && Z_TYPE_P(fci->object_ptr) == IS_OBJECT &&
		(!EG(objects_store).object_buckets || !EG(objects_store).object_buckets[Z_OBJ_HANDLE_P(fci->object_ptr)].valid)) {
		return FAILURE;
	}

	fn_flags = EX(function_state).function->common.fn_flags;
	if (fn_flags & (ZEND_ACC_ABSTRACT|ZEND_ACC_DEPRECATED)) {
		if (fn_flags & ZEND_ACC_ABSTRACT) {
			zend_error(E_ERROR, "Cannot call abstract method %s::%s()", EX(function_state).function->common.scope->name, EX(function_state).function->common.function_name);
		}
		if (fn_flags & ZEND_ACC_DEPRECATED) {
			zend_error(E_DEPRECATED, "Function %s%s%s() is deprecated",
				EX(function_state).function->common.scope ? EX(function_state).function->common.scope->name : "",
				EX(function_state).function->common.scope ? "::" : "",
				EX(function_state).function->common.function_name);
		}
	}

	ZEND_VM_STACK_GROW_IF_NEEDED(fci->param_count + 1);

	for (i = 0; i < fci->param_count; i++) {
		zval *param;

		if (ARG_SHOULD_BE_SENT_BY_REF(EX(function_state).function, i + 1)) {
			if (!PZVAL_IS_REF(*fci->params[i]) && Z_REFCOUNT_PP(fci->params[i]) > 1) {
				zval *new_zval;

				if (fci->no_separation &&
					!ARG_MAY_BE_SENT_BY_REF(EX(function_state).function, i + 1)) {
					if (i || UNEXPECTED(ZEND_VM_STACK_ELEMETS(EG(argument_stack)) == (EG(argument_stack)->top))) {
						/* hack to clean up the stack */
						zend_vm_stack_push((void *) (zend_uintptr_t)i TSRMLS_CC);
						zend_vm_stack_clear_multiple(0 TSRMLS_CC);
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
		} else if (PZVAL_IS_REF(*fci->params[i]) &&
				   /* don't separate references for __call */
				   (EX(function_state).function->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER) == 0 ) {
			ALLOC_ZVAL(param);
			*param = **(fci->params[i]);
			INIT_PZVAL(param);
			zval_copy_ctor(param);
		} else if (*fci->params[i] != &EG(uninitialized_zval)) {
			Z_ADDREF_PP(fci->params[i]);
			param = *fci->params[i];
		} else {
			ALLOC_ZVAL(param);
			*param = **(fci->params[i]);
			INIT_PZVAL(param);
		}
		zend_vm_stack_push(param TSRMLS_CC);
	}

	EX(function_state).arguments = zend_vm_stack_top(TSRMLS_C);
	zend_vm_stack_push((void*)(zend_uintptr_t)fci->param_count TSRMLS_CC);

	current_scope = EG(scope);
	EG(scope) = calling_scope;

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

		//if (EG(active_op_array)->fn_flags & ZEND_ACC_GENERATOR) {
		//	*fci->retval_ptr_ptr = zend_generator_create_zval(EG(active_op_array) TSRMLS_CC);
		//} else {
			zend_execute(EG(active_op_array) TSRMLS_CC);
		//}

		if (!fci->symbol_table && EG(active_symbol_table)) {
			zephir_clean_and_cache_symbol_table(EG(active_symbol_table) TSRMLS_CC);
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
		if (EXPECTED(zend_execute_internal == NULL)) {
			/* saves one function call if zend_execute_internal is not used */
			EX(function_state).function->internal_function.handler(fci->param_count, *fci->retval_ptr_ptr, fci->retval_ptr_ptr, fci->object_ptr, 1 TSRMLS_CC);
		} else {
			zend_execute_internal(&execute_data, fci, 1 TSRMLS_CC);
		}
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
			zend_error(E_ERROR, "Cannot call overloaded function for non-object");
		}

		if (EX(function_state).function->type == ZEND_OVERLOADED_FUNCTION_TEMPORARY) {
			efree((char*)EX(function_state).function->common.function_name);
		}
		efree(EX(function_state).function);

		if (EG(exception) && fci->retval_ptr_ptr) {
			zval_ptr_dtor(fci->retval_ptr_ptr);
			*fci->retval_ptr_ptr = NULL;
		}
	}
	zend_vm_stack_clear_multiple(0 TSRMLS_CC);

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
