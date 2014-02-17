
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Zephir Team (http://www.zephir-lang.com)       |
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
#include "ext/standard/php_smart_str.h"

#include "Zend/zend_API.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_execute.h"

#include "kernel/main.h"
#include "kernel/hash.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/string.h"

#include "kernel/alternative/fcall.h"

/**
 * Checks if a method is callable
 */
static int zephir_alt_is_callable_check_method(zend_class_entry *ce, int check_flags, char *method_name, unsigned int method_len, zend_fcall_info_cache *fcc, char **error, unsigned long method_key TSRMLS_DC)
{
	int retval = 0;

	#ifndef ZEPHIR_RELEASE
	int call_via_handler = 0;
	#endif

	if (error) {
		*error = NULL;
	}

	if (!method_key) {
		method_key = zend_inline_hash_func(method_name, method_len + 1);
	}

	/* Try to fetch find static method of given class. */
	if (likely(zephir_hash_quick_find(&ce->function_table, method_name, method_len + 1, method_key, (void**) &fcc->function_handler) == SUCCESS)) {
		retval = 1;
		if ((fcc->function_handler->op_array.fn_flags & ZEND_ACC_CHANGED) && ZEPHIR_EG(scope) && instanceof_function(fcc->function_handler->common.scope, EG(scope) TSRMLS_CC)) {
			zend_function *priv_fbc;
			if (zephir_hash_quick_find(&ZEPHIR_EG(scope)->function_table, method_name, method_len + 1, method_key, (void **) &priv_fbc)==SUCCESS && (priv_fbc->common.fn_flags & ZEND_ACC_PRIVATE) && priv_fbc->common.scope == EG(scope)) {
				fcc->function_handler = priv_fbc;
			}
		}
		#ifndef ZEPHIR_RELEASE
		if ((check_flags & IS_CALLABLE_CHECK_NO_ACCESS) == 0 && (fcc->calling_scope && (fcc->calling_scope->__call || fcc->calling_scope->__callstatic))) {
			if (fcc->function_handler->op_array.fn_flags & ZEND_ACC_PRIVATE) {
				if (!zend_check_private(fcc->function_handler, ce, method_name, method_len TSRMLS_CC)) {
					retval = 0;
					fcc->function_handler = NULL;
					goto get_function_via_handler;
				}
			} else {
				if (fcc->function_handler->common.fn_flags & ZEND_ACC_PROTECTED) {
					if (!zend_check_protected(fcc->function_handler->common.scope, ZEPHIR_EG(scope))) {
						retval = 0;
						fcc->function_handler = NULL;
						goto get_function_via_handler;
					}
				}
			}
		}
		#endif
	} else {
		#ifndef ZEPHIR_RELEASE
		get_function_via_handler:
		if (Z_OBJ_HT_P(fcc->object_ptr)->get_method) {
			#if PHP_VERSION_ID < 50400
			fcc->function_handler = Z_OBJ_HT_P(fcc->object_ptr)->get_method(&fcc->object_ptr, method_name, method_len TSRMLS_CC);
			#else
			fcc->function_handler = Z_OBJ_HT_P(fcc->object_ptr)->get_method(&fcc->object_ptr, method_name, method_len, NULL TSRMLS_CC);
			#endif
			if (fcc->function_handler) {
				retval = 1;
				call_via_handler = (fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER) != 0;
			}
		}
		#endif
	}

	if (retval) {
		#ifndef ZEPHIR_RELEASE
		if (fcc->calling_scope && !call_via_handler) {
			if (!fcc->object_ptr && (fcc->function_handler->common.fn_flags & ZEND_ACC_ABSTRACT)) {
				if (error) {
					zephir_spprintf(error, 0, "cannot call abstract method %s::%s()", fcc->calling_scope->name, fcc->function_handler->common.function_name);
					retval = 0;
				} else {
					zend_error(E_ERROR, "Cannot call abstract method %s::%s()", fcc->calling_scope->name, fcc->function_handler->common.function_name);
				}
			}
			if (retval && (check_flags & IS_CALLABLE_CHECK_NO_ACCESS) == 0) {
				if (fcc->function_handler->op_array.fn_flags & ZEND_ACC_PRIVATE) {
					if (!zend_check_private(fcc->function_handler, ce, method_name, method_len TSRMLS_CC)) {
						if (error) {
							if (*error) {
								efree(*error);
							}
							zephir_spprintf(error, 0, "cannot access private method %s::%s()", fcc->calling_scope->name, fcc->function_handler->common.function_name);
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
								zephir_spprintf(error, 0, "cannot access protected method %s::%s()", fcc->calling_scope->name, fcc->function_handler->common.function_name);
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
				if (error) {
					zephir_spprintf(error, 0, "class '%s' does not have a method '%s'", fcc->calling_scope->name, method_name);
				}
			} else {
				if (error) {
					zephir_spprintf(error, 0, "function '%s' does not exist", method_name);
				}
			}
		}
	}

	if (retval) {
		fcc->initialized = 1;
	}
	return retval;
}

/**
 * Check if a method is callable only if it's not checked before
 */
static inline zend_bool zephir_alt_is_callable_method_ex(zend_class_entry *ce, char *method_name, unsigned int method_len, zval *object_ptr, uint check_flags, zend_fcall_info_cache *fcc, char **error, int exists, unsigned long method_key TSRMLS_DC) {

	if (error) {
		*error = NULL;
	}

	fcc->called_scope = ce;
	fcc->object_ptr = object_ptr;
	fcc->calling_scope = ce;

	if (!exists) {
		fcc->initialized = 0;
		fcc->function_handler = NULL;
		return zephir_alt_is_callable_check_method(ce, check_flags, method_name, method_len, fcc, error, method_key TSRMLS_CC);
	} else {
		fcc->initialized = 1;
	}

	return 1;
}

#if PHP_VERSION_ID < 50400

/**
 * Call a method caching its function pointer address
 */
int zephir_alt_call_method(zend_fcall_info *fci, zend_class_entry *ce, unsigned long hash_key, char *method_name,
  unsigned int method_len, unsigned long method_key, zend_function **prepared_function TSRMLS_DC)
{
	zend_zephir_globals *zephir_globals_ptr = ZEPHIR_VGLOBAL;
	zend_uint i, exists = 0, is_zephir_function = 0;
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
	int allocated = 0;

	fci_cache = &fci_local;

	*fci->retval_ptr_ptr = NULL;

	/* Initialize execute_data */
	execute_data = *EG(current_execute_data);
	EX(op_array) = NULL;
	EX(opline) = NULL;
	EX(object) = NULL;

	/* Check if a fci_cache is already loaded for this method */
	if (!prepared_function || !*prepared_function) {

		if (hash_key > 0 && zephir_globals_ptr->function_cache) {
			if (zend_hash_index_find(zephir_globals_ptr->function_cache, hash_key, (void**) &function_handler) == SUCCESS) {
				fci_cache->function_handler = *function_handler;
				exists = 1;
				is_zephir_function = 1;
			}
		}

		/** Check if it's an internal function */
		if (!is_zephir_function) {
			is_zephir_function = ce->type == ZEND_INTERNAL_CLASS;
		}

		/* The fci_cache doesn't exist, so we check it */
		if (!exists) {

			char *callable_name;
			char *error = NULL;

			if (is_zephir_function) {

				/** Use the optimized version */
				if (!zephir_alt_is_callable_method_ex(ce, method_name, method_len, fci->object_ptr, IS_CALLABLE_CHECK_SILENT, fci_cache, &error, exists, method_key TSRMLS_CC)) {
					if (error) {
						zend_error(E_WARNING, "Invalid callback %s, %s", method_name, error);
						efree(error);
					}
					return FAILURE;
				}

			} else {

				ZEPHIR_ALLOC_ZVAL(fci->function_name);
				ZVAL_STRINGL(fci->function_name, method_name, method_len, 0);

				/** Use the slow function instead */
				if (unlikely(!zend_is_callable_ex(fci->function_name, fci->object_ptr, IS_CALLABLE_CHECK_SILENT, &callable_name, NULL, fci_cache, &error TSRMLS_CC))) {
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
			if (is_zephir_function) {
				if (fci_cache->function_handler->type == ZEND_INTERNAL_FUNCTION) {

					if (!zephir_globals_ptr->function_cache) {
						ALLOC_HASHTABLE(zephir_globals_ptr->function_cache);
						zend_hash_init(zephir_globals_ptr->function_cache, 0, NULL, NULL, 0);
					}

					zend_hash_index_update(
						zephir_globals_ptr->function_cache,
						hash_key,
						&fci_cache->function_handler,
						sizeof(zend_function *),
						NULL
					);
				}
			}

			if (prepared_function) {
				*prepared_function = fci_cache->function_handler;
			}

		} else {
			fci_cache->called_scope = ce;
			fci_cache->object_ptr = fci->object_ptr;
			fci_cache->calling_scope = ce;
			fci_cache->initialized = 1;
		}
	} else {
		fci_cache->called_scope = ce;
		fci_cache->object_ptr = fci->object_ptr;
		fci_cache->calling_scope = ce;
		fci_cache->initialized = 1;
		fci_cache->function_handler = *prepared_function;
		exists = 1;
		is_zephir_function = 1;
	}

	EX(function_state).function = fci_cache->function_handler;
	calling_scope = ce;
	called_scope = ce;
	fci->object_ptr = fci_cache->object_ptr;
	EX(object) = fci->object_ptr;

	if (!is_zephir_function) {

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
		} else {
			if (!is_zephir_function && ARG_SHOULD_BE_SENT_BY_REF(EX(function_state).function, i + 1) && !PZVAL_IS_REF(*fci->params[i])) {

				if (Z_REFCOUNT_PP(fci->params[i]) > 1) {
					zval *new_zval;

					if (fci->no_separation &&
						!ARG_MAY_BE_SENT_BY_REF(EX(function_state).function, i + 1)) {
						if (i || UNEXPECTED(ZEND_VM_STACK_ELEMETS(EG(argument_stack)) == EG(argument_stack)->top)) {

							#if PHP_VERSION_ID < 50500
							zend_vm_stack_push_nocheck((void *) (zend_uintptr_t)i TSRMLS_CC);
							zend_vm_stack_clear_multiple(TSRMLS_C);
							#else
							zend_vm_stack_push((void *) (zend_uintptr_t)i TSRMLS_CC);
							zend_vm_stack_clear_multiple(0 TSRMLS_CC);
							#endif
						}

						zend_error(E_WARNING, "Parameter %d to %s%s%s() expected to be a reference, value given",
							i + 1,
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
		#if PHP_VERSION_ID < 50500
		zend_vm_stack_push_nocheck(param TSRMLS_CC);
		#else
		zend_vm_stack_push(param TSRMLS_CC);
		#endif
	}

	EX(function_state).arguments = zend_vm_stack_top(TSRMLS_C);
	#if PHP_VERSION_ID < 50500
	zend_vm_stack_push_nocheck((void*)(zend_uintptr_t)fci->param_count TSRMLS_CC);
	#else
	zend_vm_stack_push((void*)(zend_uintptr_t)fci->param_count TSRMLS_CC);
	#endif

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
			if (EG(symtable_cache_ptr) >= EG(symtable_cache_limit)) {
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

			//if (!*fci->retval_ptr_ptr) {
				ALLOC_INIT_ZVAL(*fci->retval_ptr_ptr);
				allocated = 1;
			//}

			if (EX(function_state).function->common.scope) {
				EG(scope) = EX(function_state).function->common.scope;
			}

			((zend_internal_function *) EX(function_state).function)->handler(fci->param_count, *fci->retval_ptr_ptr, fci->retval_ptr_ptr, fci->object_ptr, 1 TSRMLS_CC);
			if (EG(exception) && fci->retval_ptr_ptr) {
				if (allocated) {
					zval_ptr_dtor(fci->retval_ptr_ptr);
					*fci->retval_ptr_ptr = NULL;
				}
			}

			if (call_via_handler) {
				fci_cache->initialized = 0;
			}
		} else {

			//if (!*fci->retval_ptr_ptr) {
				ALLOC_INIT_ZVAL(*fci->retval_ptr_ptr);
				allocated = 1;
			//}

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
				if (allocated) {
					zval_ptr_dtor(fci->retval_ptr_ptr);
					*fci->retval_ptr_ptr = NULL;
				}
			}
		}
	}

	#if PHP_VERSION_ID < 50500
	zend_vm_stack_clear_multiple(TSRMLS_C);
	#else
	zend_vm_stack_clear_multiple(0 TSRMLS_CC);
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

#else

/**
 * Call a method caching its function pointer address
 */
int zephir_alt_call_method(zend_fcall_info *fci, zend_class_entry *ce, unsigned long hash_key, char *method_name,
  unsigned int method_len, unsigned long method_key, zend_function **prepared_function TSRMLS_DC)
{
	zend_uint i;
	zend_executor_globals *executor_globals_ptr = ZEPHIR_VEG;
	zend_zephir_globals *zephir_globals_ptr = ZEPHIR_VGLOBAL;
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
	zend_fcall_info_cache *fci_cache, fci_local;
	zend_function **function_handler;
	int exists = 0, is_zephir_function = 0, allocated = 0;

	fci_cache = &fci_local;

	//assert(*fci->retval_ptr_ptr == NULL);
	//*fci->retval_ptr_ptr = NULL;

	/* Initialize execute_data */
	execute_data = *executor_globals_ptr->current_execute_data;
	EX(op_array) = NULL;
	EX(opline) = NULL;
	EX(object) = NULL;

	if (!prepared_function || !*prepared_function) {

		/* Check if a fci_cache is already loaded for this method */
		if (hash_key > 0 && zephir_globals_ptr->function_cache) {
			if (zend_hash_index_find(zephir_globals_ptr->function_cache, hash_key, (void**) &function_handler) == SUCCESS) {
				fci_cache->function_handler = *function_handler;
				exists = 1;
				is_zephir_function = 1;
			}
		}

		/** Check if it's an internal function */
		if (!is_zephir_function) {
			if (ce->type == ZEND_INTERNAL_CLASS) {
				is_zephir_function = 1;
			}
		}

		/* The fci_cache doesn't exist, so we check it */
		if (!exists) {

			char *callable_name;
			char *error = NULL;

			if (is_zephir_function) {

				/** Use the optimized version */
				if (unlikely(!zephir_alt_is_callable_method_ex(ce, method_name, method_len, fci->object_ptr, IS_CALLABLE_CHECK_SILENT, fci_cache, &error, exists, method_key TSRMLS_CC))) {
					if (error) {
						zend_error(E_WARNING, "Invalid callback %s, %s", method_name, error);
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

				ZEPHIR_ALLOC_ZVAL(fci->function_name);
				ZVAL_STRINGL(fci->function_name, method_name, method_len, 0);

				/** Use the slow function instead */
				if (unlikely(!zend_is_callable_ex(fci->function_name, fci->object_ptr, IS_CALLABLE_CHECK_SILENT, &callable_name, NULL, fci_cache, &error TSRMLS_CC))) {
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
			if (is_zephir_function) {
				if (likely(fci_cache->function_handler->type == ZEND_INTERNAL_FUNCTION)) {

					if (!zephir_globals_ptr->function_cache) {
						ALLOC_HASHTABLE(zephir_globals_ptr->function_cache);
						zend_hash_init(zephir_globals_ptr->function_cache, 0, NULL, NULL, 0);
					}

					zend_hash_index_update(
						zephir_globals_ptr->function_cache,
						hash_key,
						&fci_cache->function_handler,
						sizeof(zend_function *),
						NULL
					);
				}
			}

			if (prepared_function) {
				*prepared_function = fci_cache->function_handler;
			}

		} else {
			fci_cache->called_scope = ce;
			fci_cache->object_ptr = fci->object_ptr;
			fci_cache->calling_scope = ce;
			fci_cache->initialized = 1;
		}

	} else {
		fci_cache->called_scope = ce;
		fci_cache->object_ptr = fci->object_ptr;
		fci_cache->calling_scope = ce;
		fci_cache->initialized = 1;
		fci_cache->function_handler = *prepared_function;
		exists = 1;
		is_zephir_function = 1;
	}

	EX(function_state).function = fci_cache->function_handler;
	calling_scope = fci_cache->calling_scope;
	called_scope = fci_cache->called_scope;
	fci->object_ptr = fci_cache->object_ptr;
	EX(object) = fci->object_ptr;

	if (!is_zephir_function) {

		if (fci->object_ptr && Z_TYPE_P(fci->object_ptr) == IS_OBJECT &&
			(!executor_globals_ptr->objects_store.object_buckets || !executor_globals_ptr->objects_store.object_buckets[Z_OBJ_HANDLE_P(fci->object_ptr)].valid)) {
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

	for (i = 0; i < fci->param_count; i++) {
		zval *param;

		if (ARG_SHOULD_BE_SENT_BY_REF(EX(function_state).function, i + 1)) {
			if (!PZVAL_IS_REF(*fci->params[i]) && Z_REFCOUNT_PP(fci->params[i]) > 1) {
				zval *new_zval;

				if (fci->no_separation &&
					!ARG_MAY_BE_SENT_BY_REF(EX(function_state).function, i + 1)) {
					if (i || UNEXPECTED(ZEND_VM_STACK_ELEMETS(executor_globals_ptr->argument_stack) == executor_globals_ptr->argument_stack->top)) {
						/* hack to clean up the stack */
						#if PHP_VERSION_ID < 50500
						zend_vm_stack_push_nocheck((void *) (zend_uintptr_t)i TSRMLS_CC);
						zend_vm_stack_clear_multiple(TSRMLS_C);
						#else
						zend_vm_stack_push((void *) (zend_uintptr_t)i TSRMLS_CC);
						zend_vm_stack_clear_multiple(0 TSRMLS_CC);
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
		} else if (PZVAL_IS_REF(*fci->params[i]) &&
				   /* don't separate references for __call */
				   (EX(function_state).function->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER) == 0 ) {
			ALLOC_ZVAL(param);
			*param = **(fci->params[i]);
			INIT_PZVAL(param);
			zval_copy_ctor(param);
		} else {
			if (*fci->params[i] != &executor_globals_ptr->uninitialized_zval) {
				Z_ADDREF_PP(fci->params[i]);
				param = *fci->params[i];
			} else {
				ALLOC_ZVAL(param);
				*param = **(fci->params[i]);
				INIT_PZVAL(param);
			}
		}
		#if PHP_VERSION_ID < 50500
		zend_vm_stack_push_nocheck(param TSRMLS_CC);
		#else
		zend_vm_stack_push(param TSRMLS_CC);
		#endif
	}

	EX(function_state).arguments = zend_vm_stack_top(TSRMLS_C);
	#if PHP_VERSION_ID < 50500
	zend_vm_stack_push_nocheck((void*)(zend_uintptr_t)fci->param_count TSRMLS_CC);
	#else
	zend_vm_stack_push((void*)(zend_uintptr_t)fci->param_count TSRMLS_CC);
	#endif

	current_scope = executor_globals_ptr->scope;
	executor_globals_ptr->scope = calling_scope;

	current_this = executor_globals_ptr->This;

	current_called_scope = executor_globals_ptr->called_scope;
	if (called_scope) {
		executor_globals_ptr->called_scope = called_scope;
	} else {
		if (EX(function_state).function->type != ZEND_INTERNAL_FUNCTION) {
			executor_globals_ptr->called_scope = NULL;
		}
	}

	if (fci->object_ptr) {
		if ((EX(function_state).function->common.fn_flags & ZEND_ACC_STATIC)) {
			executor_globals_ptr->This = NULL;
		} else {
			executor_globals_ptr->This = fci->object_ptr;

			if (!PZVAL_IS_REF(executor_globals_ptr->This)) {
				Z_ADDREF_P(executor_globals_ptr->This); /* For $this pointer */
			} else {
				zval *this_ptr;

				ALLOC_ZVAL(this_ptr);
				*this_ptr = *executor_globals_ptr->This;
				INIT_PZVAL(this_ptr);
				zval_copy_ctor(this_ptr);
				executor_globals_ptr->This = this_ptr;
			}
		}
	} else {
		executor_globals_ptr->This = NULL;
	}

	EX(prev_execute_data) = executor_globals_ptr->current_execute_data;
	executor_globals_ptr->current_execute_data = &execute_data;

	if (EX(function_state).function->type == ZEND_USER_FUNCTION) {
		calling_symbol_table = executor_globals_ptr->active_symbol_table;
		executor_globals_ptr->scope = EX(function_state).function->common.scope;
		if (fci->symbol_table) {
			executor_globals_ptr->active_symbol_table = fci->symbol_table;
		} else {
			executor_globals_ptr->active_symbol_table = NULL;
		}

		original_return_value = executor_globals_ptr->return_value_ptr_ptr;
		original_op_array = executor_globals_ptr->active_op_array;
		executor_globals_ptr->return_value_ptr_ptr = fci->retval_ptr_ptr;
		executor_globals_ptr->active_op_array = (zend_op_array *) EX(function_state).function;
		original_opline_ptr = executor_globals_ptr->opline_ptr;
		zend_execute(executor_globals_ptr->active_op_array TSRMLS_CC);
		if (!fci->symbol_table && executor_globals_ptr->active_symbol_table) {
			if (executor_globals_ptr->symtable_cache_ptr >= executor_globals_ptr->symtable_cache_limit) {
				zend_hash_destroy(executor_globals_ptr->active_symbol_table);
				FREE_HASHTABLE(executor_globals_ptr->active_symbol_table);
			} else {
				/* clean before putting into the cache, since clean
				   could call dtors, which could use cached hash */
				zend_hash_clean(executor_globals_ptr->active_symbol_table);
				*(++executor_globals_ptr->symtable_cache_ptr) = executor_globals_ptr->active_symbol_table;
			}
		}
		executor_globals_ptr->active_symbol_table = calling_symbol_table;
		executor_globals_ptr->active_op_array = original_op_array;
		executor_globals_ptr->return_value_ptr_ptr = original_return_value;
		executor_globals_ptr->opline_ptr = original_opline_ptr;
	} else {
		if (EX(function_state).function->type == ZEND_INTERNAL_FUNCTION) {
			int call_via_handler = (EX(function_state).function->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER) != 0;

			//if (!*fci->retval_ptr_ptr) {
				ALLOC_INIT_ZVAL(*fci->retval_ptr_ptr);
				allocated = 1;
			//}

			if (EX(function_state).function->common.scope) {
				executor_globals_ptr->scope = EX(function_state).function->common.scope;
			}
			((zend_internal_function *) EX(function_state).function)->handler(fci->param_count, *fci->retval_ptr_ptr, fci->retval_ptr_ptr, fci->object_ptr, 1 TSRMLS_CC);
			/*  We shouldn't fix bad extensions here,
				because it can break proper ones (Bug #34045)
			if (!EX(function_state).function->common.return_reference)
			{
				INIT_PZVAL(*fci->retval_ptr_ptr);
			}*/
			if (executor_globals_ptr->exception && fci->retval_ptr_ptr && *fci->retval_ptr_ptr) {
				if (allocated) {
					zval_ptr_dtor(fci->retval_ptr_ptr);
					*fci->retval_ptr_ptr = NULL;
				}
			}

			if (call_via_handler) {
				/* We must re-initialize function again */
				fci_cache->initialized = 0;
			}
		} else { /* ZEND_OVERLOADED_FUNCTION */

			//if (!*fci->retval_ptr_ptr) {
				ALLOC_INIT_ZVAL(*fci->retval_ptr_ptr);
				allocated = 1;
			//}

			/* Not sure what should be done here if it's a static method */
			if (fci->object_ptr) {
				Z_OBJ_HT_P(fci->object_ptr)->call_method(EX(function_state).function->common.function_name, fci->param_count, *fci->retval_ptr_ptr, fci->retval_ptr_ptr, fci->object_ptr, 1 TSRMLS_CC);
			} else {
				zend_error_noreturn(E_ERROR, "Cannot call overloaded function for non-object");
			}

			if (EX(function_state).function->type == ZEND_OVERLOADED_FUNCTION_TEMPORARY) {
				efree((char*)EX(function_state).function->common.function_name);
			}
			efree(EX(function_state).function);

			if (executor_globals_ptr->exception && fci->retval_ptr_ptr && *fci->retval_ptr_ptr) {
				if (allocated) {
					zval_ptr_dtor(fci->retval_ptr_ptr);
					*fci->retval_ptr_ptr = NULL;
				}
			}
		}
	}
	#if PHP_VERSION_ID < 50500
	zend_vm_stack_clear_multiple(TSRMLS_C);
	#else
	zend_vm_stack_clear_multiple(0 TSRMLS_CC);
	#endif

	if (executor_globals_ptr->This) {
		zval_ptr_dtor(&executor_globals_ptr->This);
	}
	executor_globals_ptr->called_scope = current_called_scope;
	executor_globals_ptr->scope = current_scope;
	executor_globals_ptr->This = current_this;
	executor_globals_ptr->current_execute_data = EX(prev_execute_data);

	if (executor_globals_ptr->exception) {
		zephir_throw_exception_internal(NULL TSRMLS_CC);
	}

	return SUCCESS;
}

#endif

/**
 * Calls a method caching its function handler
 */
int zephir_alt_call_user_method(zend_class_entry *ce, zval **object_pp, char *method_name,
  unsigned int method_len, zval *retval_ptr, zval **retval_ptr_ptr, zend_uint param_count,
  zval *params[], unsigned long method_key, zend_function **prepared_function TSRMLS_DC)
{
	zend_zephir_globals *zephir_globals_ptr = ZEPHIR_VGLOBAL;
	zval ***params_array = NULL;
	zval **static_params_array[5];
	zend_uint i;
	int ex_retval;
	zval *local_retval_ptr = NULL;
	zend_fcall_info fci;
	unsigned long hash_key = 0;

	zephir_globals_ptr->recursive_lock++;

	if (unlikely(zephir_globals_ptr->recursive_lock > 2048)) {
		ex_retval = FAILURE;
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Maximum recursion depth exceeded");
	} else {

		if (param_count) {
			if (param_count > 5) {
				params_array = (zval ***) emalloc(sizeof(zval **)*param_count);
				for (i = 0; i < param_count; i++) {
					params_array[i] = &params[i];
				}
			} else {
				for (i = 0; i < param_count; i++) {
					static_params_array[i] = &params[i];
				}
			}
		}

		/** Create a unique key */
		if (!prepared_function) {
			if (ce->name_length >= 8 && ce->name[7] == '\\') {
				for (i = 7; i < ce->name_length; i++) {
					hash_key = ce->name[i] + (hash_key << 6) + (hash_key << 16) - hash_key;
				}
				hash_key = '$' + (hash_key << 6) + (hash_key << 16) - hash_key;
				for (i = 0; i < method_len; i++) {
					hash_key = method_name[i] + (hash_key << 6) + (hash_key << 16) - hash_key;
				}
			}
		}

		if (retval_ptr_ptr && *retval_ptr_ptr) {
			zval_ptr_dtor(retval_ptr_ptr);
			*retval_ptr_ptr = NULL;
		}

		fci.size = sizeof(fci);
		fci.no_separation = 1;
		fci.symbol_table = NULL;
		fci.function_table = &ce->function_table;
		fci.object_ptr = *object_pp;
		fci.function_name = NULL;
		fci.retval_ptr_ptr = retval_ptr_ptr ? retval_ptr_ptr : &local_retval_ptr;
		/*if (retval_ptr_ptr) {
			fci.retval_ptr_ptr = retval_ptr_ptr;
		} else {
			fci.retval_ptr_ptr = &retval_ptr;
		}*/
		fci.param_count = param_count;
		if (param_count > 5) {
			fci.params = params_array;
		} else{
			fci.params = static_params_array;
		}

		ex_retval = zephir_alt_call_method(&fci, ce, hash_key, method_name, method_len, method_key, prepared_function TSRMLS_CC);

		if (fci.function_name) {
			if (Z_REFCOUNT_P(fci.function_name) == 1) {
				ZVAL_NULL(fci.function_name);
			} else {
				zval_copy_ctor(fci.function_name);
			}
			zval_ptr_dtor(&fci.function_name);
		}
	}

	zephir_globals_ptr->recursive_lock--;

	if (local_retval_ptr) {
		COPY_PZVAL_TO_ZVAL(*retval_ptr, local_retval_ptr);
	} else {
		if (!retval_ptr_ptr) {
			INIT_ZVAL(*retval_ptr);
		}
	}

	if (params_array) {
		efree(params_array);
	}

	return ex_retval;
}
