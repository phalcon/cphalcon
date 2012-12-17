
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"

#include "Zend/zend_API.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_execute.h"

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/string.h"

#include "kernel/experimental/fcall.h"

/**
 * NOTE: These functions are marked as EXPERIMENTAL, don't use it in production!
 */

#if PHP_VERSION_ID < 50400

/**
 * Calls a method caching its function handler
 */
inline int phalcon_exp_call_user_method_ex(zend_class_entry *ce, zval **object_pp, zval *method_name, zval **retval_ptr_ptr, zend_uint param_count, zval **params[] TSRMLS_DC)
{

	zend_fcall_info *fci, fci_local;
	int status;
	unsigned int key_length;
	char *key;

	/** Calculate the key-length */
	key_length = ce->name_length + Z_STRLEN_P(method_name) + 1;

	/** Create a unique key */
	key = emalloc(key_length);
	memcpy(key, ce->name, ce->name_length);
	memcpy(key + ce->name_length, Z_STRVAL_P(method_name), Z_STRLEN_P(method_name));
	key[key_length - 1] = '\0';

	fci = &fci_local;
	fci->size = sizeof(fci);
	fci->no_separation = 1;
	fci->symbol_table = NULL;
	fci->function_table = &ce->function_table;
	fci->object_ptr = *object_pp;
	fci->function_name = method_name;
	fci->retval_ptr_ptr = retval_ptr_ptr;
	fci->param_count = param_count;
	fci->params = params;

	status = phalcon_exp_call_method(fci, ce, key, key_length TSRMLS_CC);

	efree(key);

	return status;
}

/**
 * Calls a method caching its function handler
 */
int phalcon_exp_call_user_method(zend_class_entry *ce, zval **object_pp, zval *function_name, zval *retval_ptr, zend_uint param_count, zval *params[] TSRMLS_DC)
{
	zval ***params_array;
	zend_uint i;
	int ex_retval;
	zval *local_retval_ptr = NULL;

	if (param_count) {
		params_array = (zval ***) emalloc(sizeof(zval **)*param_count);
		for (i=0; i<param_count; i++) {
			params_array[i] = &params[i];
		}
	} else {
		params_array = NULL;
	}

	ex_retval = phalcon_exp_call_user_method_ex(ce, object_pp, function_name, &local_retval_ptr, param_count, params_array TSRMLS_CC);
	if (local_retval_ptr) {
		COPY_PZVAL_TO_ZVAL(*retval_ptr, local_retval_ptr);
	} else {
		INIT_ZVAL(*retval_ptr);
	}
	if (params_array) {
		efree(params_array);
	}
	return ex_retval;
}

/**
 * Checks if a method is callable
 */
static int phalcon_exp_is_callable_check_method(zend_class_entry *ce, int check_flags, zval *callable, zend_fcall_info_cache *fcc, char **error TSRMLS_DC) /* {{{ */
{
	int retval = 0;
	int call_via_handler = 0;

	if (error) {
		*error = NULL;
	}

	/* Try to fetch find static method of given class. */
	if (zend_hash_find(&ce->function_table, Z_STRVAL_P(callable), Z_STRLEN_P(callable)+1, (void**) &fcc->function_handler) == SUCCESS) {
		retval = 1;
		if ((fcc->function_handler->op_array.fn_flags & ZEND_ACC_CHANGED) && EG(scope) && instanceof_function(fcc->function_handler->common.scope, EG(scope) TSRMLS_CC)) {
			zend_function *priv_fbc;
			if (zend_hash_find(&EG(scope)->function_table, Z_STRVAL_P(callable), Z_STRLEN_P(callable)+1, (void **) &priv_fbc)==SUCCESS && priv_fbc->common.fn_flags & ZEND_ACC_PRIVATE && priv_fbc->common.scope == EG(scope)) {
				fcc->function_handler = priv_fbc;
			}
		}
		#ifndef PHALCON_RELEASE
		if ((check_flags & IS_CALLABLE_CHECK_NO_ACCESS) == 0 && (fcc->calling_scope && (fcc->calling_scope->__call || fcc->calling_scope->__callstatic))) {
			if (fcc->function_handler->op_array.fn_flags & ZEND_ACC_PRIVATE) {
				if (!zend_check_private(fcc->function_handler, ce, Z_STRVAL_P(callable), Z_STRLEN_P(callable) TSRMLS_CC)) {
					retval = 0;
					fcc->function_handler = NULL;
					goto get_function_via_handler;
				}
			} else {
				if (fcc->function_handler->common.fn_flags & ZEND_ACC_PROTECTED) {
					if (!zend_check_protected(fcc->function_handler->common.scope, EG(scope))) {
						retval = 0;
						fcc->function_handler = NULL;
						goto get_function_via_handler;
					}
				}
			}
		}
		#endif
	} else {
		get_function_via_handler:
		if (Z_OBJ_HT_P(fcc->object_ptr)->get_method) {
			fcc->function_handler = Z_OBJ_HT_P(fcc->object_ptr)->get_method(&fcc->object_ptr, Z_STRVAL_P(callable), Z_STRLEN_P(callable) TSRMLS_CC);
			if (fcc->function_handler) {
				retval = 1;
				call_via_handler = (fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER) != 0;
			}
		}
	}

	if (retval) {
		#ifndef PHALCON_RELEASE
		if (fcc->calling_scope && !call_via_handler) {
			if (!fcc->object_ptr && (fcc->function_handler->common.fn_flags & ZEND_ACC_ABSTRACT)) {
				if (error) {
					phalcon_spprintf(error, 0, "cannot call abstract method %s::%s()", fcc->calling_scope->name, fcc->function_handler->common.function_name);
					retval = 0;
				} else {
					zend_error(E_ERROR, "Cannot call abstract method %s::%s()", fcc->calling_scope->name, fcc->function_handler->common.function_name);
				}
			}
			if (retval && (check_flags & IS_CALLABLE_CHECK_NO_ACCESS) == 0) {
				if (fcc->function_handler->op_array.fn_flags & ZEND_ACC_PRIVATE) {
					if (!zend_check_private(fcc->function_handler, ce, Z_STRVAL_P(callable), Z_STRLEN_P(callable) TSRMLS_CC)) {
						if (error) {
							if (*error) {
								efree(*error);
							}
							phalcon_spprintf(error, 0, "cannot access private method %s::%s()", fcc->calling_scope->name, fcc->function_handler->common.function_name);
						}
						retval = 0;
					}
				} else {
					if ((fcc->function_handler->common.fn_flags & ZEND_ACC_PROTECTED)) {
						if (!zend_check_protected(fcc->function_handler->common.scope, EG(scope))) {
							if (error) {
								if (*error) {
									efree(*error);
								}
								phalcon_spprintf(error, 0, "cannot access protected method %s::%s()", fcc->calling_scope->name, fcc->function_handler->common.function_name);
							}
							retval = 0;
						}
					}
				}
			}
		}
		#endif
	} else {
		if (error && !(check_flags & IS_CALLABLE_CHECK_SILENT)) {
			if (fcc->calling_scope) {
				if (error) phalcon_spprintf(error, 0, "class '%s' does not have a method '%s'", fcc->calling_scope->name, Z_STRVAL_P(callable));
			} else {
				if (error) phalcon_spprintf(error, 0, "function '%s' does not exist", Z_STRVAL_P(callable));
			}
		}
	}

	if (retval) {
		fcc->initialized = 1;
	}
	return retval;
}

/**
 *
 */
inline zend_bool phalcon_exp_is_callable_method_ex(zend_class_entry *ce, zval *callable, zval *object_ptr, uint check_flags, zend_fcall_info_cache *fcc, char **error, int exists TSRMLS_DC) {

	if (error) {
		*error = NULL;
	}

	fcc->called_scope = ce;
	fcc->object_ptr = object_ptr;
	fcc->calling_scope = ce;

	if (!exists) {
		fcc->initialized = 0;
		fcc->function_handler = NULL;
		return phalcon_exp_is_callable_check_method(ce, check_flags, callable, fcc, error TSRMLS_CC);
	} else {
		fcc->initialized = 1;
	}

	return 1;
}

int phalcon_exp_call_method(zend_fcall_info *fci, zend_class_entry *ce, char *key, unsigned int key_length TSRMLS_DC)
{
	zend_uint i, exists = 0, is_phalcon_function = 0;
	zend_class_entry *current_scope;
	zend_class_entry *current_called_scope;
	zend_class_entry *calling_scope = NULL;
	zend_class_entry *called_scope = NULL;
	zval **original_return_value;
	HashTable *calling_symbol_table;
	zend_op_array *original_op_array;
	zend_op **original_opline_ptr;
	zval *current_this;
	zend_execute_data execute_data;
	zend_fcall_info_cache *fci_cache, fci_local;
	zend_function **function_handler;

	fci_cache = &fci_local;

	*fci->retval_ptr_ptr = NULL;

	/* Initialize execute_data */
	execute_data = *EG(current_execute_data);
	EX(op_array) = NULL;
	EX(opline) = NULL;
	EX(object) = NULL;

	/* Check if a fci_cache is already loaded for this method */
	if (PHALCON_GLOBAL(function_cache)) {
		if (zend_hash_find(PHALCON_GLOBAL(function_cache), key, key_length, (void**) &function_handler) == SUCCESS) {
			fci_cache->function_handler = *function_handler;
			exists = 1;
			is_phalcon_function = 1;
		}
	}

	/** Check if it's a Phalcon function */
	if (!is_phalcon_function) {
		is_phalcon_function = ce->type == ZEND_INTERNAL_CLASS && phalcon_start_with_str_str(ce->name, ce->name_length, SL("Phalcon\\"));
	}

	/* The fci_cache doesn't exist, so we check it */
	if (!exists) {

		char *callable_name;
		char *error = NULL;

		if (is_phalcon_function) {
			if (!phalcon_exp_is_callable_method_ex(ce, fci->function_name, fci->object_ptr, IS_CALLABLE_CHECK_SILENT, fci_cache, &error, exists TSRMLS_CC)) {
				if (error) {
					zend_error(E_WARNING, "Invalid callback %s, %s", key, error);
					efree(error);
				}
				return FAILURE;
			} else {
				if (error) {
					zend_error(E_STRICT, "%s", error);
					efree(error);
				}
			}
		} else {

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
					zend_error(E_STRICT, "%s", error);
					efree(error);
				}
			}
			efree(callable_name);

		}

		/* Store the function in the cache only if it is a zend internal function */
		if (is_phalcon_function) {
			if (fci_cache->function_handler->type == ZEND_INTERNAL_FUNCTION) {

				if (!PHALCON_GLOBAL(function_cache)) {
					ALLOC_HASHTABLE(PHALCON_GLOBAL(function_cache));
					zend_hash_init(PHALCON_GLOBAL(function_cache), 0, NULL, NULL, 0);
				}

				zend_hash_update(
					PHALCON_GLOBAL(function_cache),
					key,
					key_length,
					&fci_cache->function_handler,
					sizeof(zend_function *),
					NULL
				);
			}
		}

	} else {
		fci_cache->called_scope = ce;
		fci_cache->object_ptr = fci->object_ptr;
		fci_cache->calling_scope = ce;
		fci_cache->initialized = 1;
	}

	EX(function_state).function = fci_cache->function_handler;
	calling_scope = ce;
	called_scope = ce;
	fci->object_ptr = fci_cache->object_ptr;
	EX(object) = fci->object_ptr;

	if (!is_phalcon_function) {

		if (fci->object_ptr && Z_TYPE_P(fci->object_ptr) == IS_OBJECT && (!EG(objects_store).object_buckets || !EG(objects_store).object_buckets[Z_OBJ_HANDLE_P(fci->object_ptr)].valid)) {
			return FAILURE;
		}

		if (EX(function_state).function->common.fn_flags & (ZEND_ACC_ABSTRACT|ZEND_ACC_DEPRECATED)) {
			if (EX(function_state).function->common.fn_flags & ZEND_ACC_ABSTRACT) {
				zend_error_noreturn(E_ERROR, "Cannot call abstract method %s::%s()", EX(function_state).function->common.scope->name, EX(function_state).function->common.function_name);
			}
			if (EX(function_state).function->common.fn_flags & ZEND_ACC_DEPRECATED) {
				zend_error(E_DEPRECATED, "Function %s%s%s() is deprecated",
					EX(function_state).function->common.scope ? EX(function_state).function->common.scope->name : "",
					EX(function_state).function->common.scope ? "::" : "",
					EX(function_state).function->common.function_name);
			}
		}

	}

	ZEND_VM_STACK_GROW_IF_NEEDED(fci->param_count + 1);

	for (i=0; i<fci->param_count; i++) {
		zval *param;

		if (EX(function_state).function->type == ZEND_INTERNAL_FUNCTION
			&& (EX(function_state).function->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER) == 0
			&& !ARG_SHOULD_BE_SENT_BY_REF(EX(function_state).function, i + 1)
			&& PZVAL_IS_REF(*fci->params[i])) {
			ALLOC_ZVAL(param);
			*param = **(fci->params[i]);
			INIT_PZVAL(param);
			zval_copy_ctor(param);
		} else {
			if (!is_phalcon_function && ARG_SHOULD_BE_SENT_BY_REF(EX(function_state).function, i + 1) && !PZVAL_IS_REF(*fci->params[i])) {

				if (Z_REFCOUNT_PP(fci->params[i]) > 1) {
					zval *new_zval;

					if (fci->no_separation &&
						!ARG_MAY_BE_SENT_BY_REF(EX(function_state).function, i + 1)) {
						if (i || UNEXPECTED(ZEND_VM_STACK_ELEMETS(EG(argument_stack)) == EG(argument_stack)->top)) {
							zend_vm_stack_push_nocheck((void *) (zend_uintptr_t)i TSRMLS_CC);
							zend_vm_stack_clear_multiple(TSRMLS_C);
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
			} else {
				if (*fci->params[i] != &EG(uninitialized_zval)) {
					Z_ADDREF_PP(fci->params[i]);
					param = *fci->params[i];
				} else {
					ALLOC_ZVAL(param);
					*param = **(fci->params[i]);
					INIT_PZVAL(param);
				}
			}
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
	} else if (EX(function_state).function->type != ZEND_INTERNAL_FUNCTION) {
		EG(called_scope) = NULL;
	}

	if (fci->object_ptr) {
		if ((EX(function_state).function->common.fn_flags & ZEND_ACC_STATIC)) {
			EG(This) = NULL;
		} else {
			EG(This) = fci->object_ptr;

			if (!PZVAL_IS_REF(EG(This))) {
				Z_ADDREF_P(EG(This));
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
				zend_hash_clean(EG(active_symbol_table));
				*(++EG(symtable_cache_ptr)) = EG(active_symbol_table);
			}
		}
		EG(active_symbol_table) = calling_symbol_table;
		EG(active_op_array) = original_op_array;
		EG(return_value_ptr_ptr)=original_return_value;
		EG(opline_ptr) = original_opline_ptr;
	} else {
		if (EX(function_state).function->type == ZEND_INTERNAL_FUNCTION) {

			int call_via_handler = (EX(function_state).function->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER) != 0;
			ALLOC_INIT_ZVAL(*fci->retval_ptr_ptr);

			if (EX(function_state).function->common.scope) {
				EG(scope) = EX(function_state).function->common.scope;
			}

			((zend_internal_function *) EX(function_state).function)->handler(fci->param_count, *fci->retval_ptr_ptr, fci->retval_ptr_ptr, fci->object_ptr, 1 TSRMLS_CC);
			if (EG(exception) && fci->retval_ptr_ptr) {
				zval_ptr_dtor(fci->retval_ptr_ptr);
				*fci->retval_ptr_ptr = NULL;
			}

			if (call_via_handler) {
				fci_cache->initialized = 0;
			}
		} else {
			ALLOC_INIT_ZVAL(*fci->retval_ptr_ptr);

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
	}
	zend_vm_stack_clear_multiple(TSRMLS_C);

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