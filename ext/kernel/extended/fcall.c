
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2016 Zephir Team (http://www.zephir-lang.com)       |
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
#include <Zend/zend_generators.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/backtrace.h"

int zephir_call_func_aparams_fast(zval *return_value_ptr, zephir_fcall_cache_entry **cache_entry, zend_uint param_count, zval *params[])
{
	uint32_t i;
	zend_class_entry *calling_scope = NULL;
	zend_execute_data *call, dummy_execute_data;
	zval retval_local;
	zval *retval_ptr = return_value_ptr ? return_value_ptr : &retval_local;
	zend_class_entry *orig_scope;
	zend_function *func;

	if (return_value_ptr) {
		zval_ptr_dtor(return_value_ptr);
		ZVAL_UNDEF(return_value_ptr);
	} else {
		ZVAL_UNDEF(&retval_local);
	}

	if (!EG(active)) {
		return FAILURE; /* executor is already inactive */
	}

	if (EG(exception)) {
		return FAILURE; /* we would result in an instable executor otherwise */
	}

	orig_scope = EG(scope);

	/* Initialize execute_data */
	if (!EG(current_execute_data)) {
		/* This only happens when we're called outside any execute()'s
		 * It shouldn't be strictly necessary to NULL execute_data out,
		 * but it may make bugs easier to spot
		 */
		memset(&dummy_execute_data, 0, sizeof(zend_execute_data));
		EG(current_execute_data) = &dummy_execute_data;
	} else if (EG(current_execute_data)->func &&
	           ZEND_USER_CODE(EG(current_execute_data)->func->common.type) &&
	           EG(current_execute_data)->opline->opcode != ZEND_DO_FCALL &&
	           EG(current_execute_data)->opline->opcode != ZEND_DO_ICALL &&
	           EG(current_execute_data)->opline->opcode != ZEND_DO_UCALL &&
	           EG(current_execute_data)->opline->opcode != ZEND_DO_FCALL_BY_NAME) {
		/* Insert fake frame in case of include or magic calls */
		dummy_execute_data = *EG(current_execute_data);
		dummy_execute_data.prev_execute_data = EG(current_execute_data);
		dummy_execute_data.call = NULL;
		dummy_execute_data.opline = NULL;
		dummy_execute_data.func = NULL;
		EG(current_execute_data) = &dummy_execute_data;
	}

#ifndef ZEPHIR_RELEASE
	func = (*cache_entry)->f;
	++(*cache_entry)->times;
#else
	func = *cache_entry;
#endif

	calling_scope = NULL;
	call = zend_vm_stack_push_call_frame(ZEND_CALL_TOP_FUNCTION, func, param_count, NULL, NULL);

	for (i = 0; i < param_count; i++) {
		zval *param;
		zval *arg = params[i];

		if (ARG_SHOULD_BE_SENT_BY_REF(func, i + 1)) {
			if (!Z_ISREF_P(arg)) {
				/*if (!ARG_MAY_BE_SENT_BY_REF(func, i + 1)) {
					if (i) {
						// hack to clean up the stack
						ZEND_CALL_NUM_ARGS(call) = i;
						zend_vm_stack_free_args(call);
					}
					zend_vm_stack_free_call_frame(call);

					zend_error(E_WARNING, "Parameter %d to %s%s%s() expected to be a reference, value given",
						i+1,
						func->common.scope ? ZSTR_VAL(func->common.scope->name) : "",
						func->common.scope ? "::" : "",
						ZSTR_VAL(func->common.function_name));
					if (EG(current_execute_data) == &dummy_execute_data) {
						EG(current_execute_data) = dummy_execute_data.prev_execute_data;
					}
					return FAILURE;
				}*/

				ZVAL_NEW_REF(arg, arg);
			}
			Z_ADDREF_P(arg);
		} else {
			if (Z_ISREF_P(arg) &&
			    !(func->common.fn_flags & ZEND_ACC_CALL_VIA_TRAMPOLINE)) {
				/* don't separate references for __call */
				arg = Z_REFVAL_P(arg);
			}
			if (Z_OPT_REFCOUNTED_P(arg)) {
				Z_ADDREF_P(arg);
			}
		}
		param = ZEND_CALL_ARG(call, i+1);
		ZVAL_COPY_VALUE(param, arg);
	}

	EG(scope) = calling_scope;
	Z_OBJ(call->This) = NULL;

	if (func->type == ZEND_USER_FUNCTION) {
		int call_via_handler = (func->common.fn_flags & ZEND_ACC_CALL_VIA_TRAMPOLINE) != 0;
		EG(scope) = func->common.scope;
		call->symbol_table = NULL;
		if (UNEXPECTED(func->op_array.fn_flags & ZEND_ACC_CLOSURE)) {
			ZEND_ASSERT(GC_TYPE((zend_object*)func->op_array.prototype) == IS_OBJECT);
			GC_REFCOUNT((zend_object*)func->op_array.prototype)++;
			ZEND_ADD_CALL_FLAG(call, ZEND_CALL_CLOSURE);
		}
		if (EXPECTED((func->op_array.fn_flags & ZEND_ACC_GENERATOR) == 0)) {
			zend_init_execute_data(call, &func->op_array, retval_ptr);
			zend_execute_ex(call);
		} else {
			zend_generator_create_zval(call, &func->op_array, retval_ptr);
		}
		if (call_via_handler) {
			/* We must re-initialize function again */
			*cache_entry = NULL;
		}
	} else if (func->type == ZEND_INTERNAL_FUNCTION) {
		int call_via_handler = (func->common.fn_flags & ZEND_ACC_CALL_VIA_TRAMPOLINE) != 0;
		if (func->common.scope) {
			EG(scope) = func->common.scope;
		}
		call->prev_execute_data = EG(current_execute_data);
		call->return_value = NULL; /* this is not a constructor call */
		EG(current_execute_data) = call;
		if (EXPECTED(zend_execute_internal == NULL)) {
			/* saves one function call if zend_execute_internal is not used */
			func->internal_function.handler(call, retval_ptr);
		} else {
			zend_execute_internal(call, retval_ptr);
		}
		EG(current_execute_data) = call->prev_execute_data;
		zend_vm_stack_free_args(call);

		/*  We shouldn't fix bad extensions here,
			because it can break proper ones (Bug #34045)
		if (!EX(function_state).function->common.return_reference)
		{
			INIT_PZVAL(f->retval);
		}*/
		if (EG(exception)) {
			zval_ptr_dtor(retval_ptr);
			ZVAL_UNDEF(retval_ptr);
		}

		if (call_via_handler) {
			/* We must re-initialize function again */
			*cache_entry = NULL;
		}
	} else { /* ZEND_OVERLOADED_FUNCTION */
		ZVAL_NULL(retval_ptr);

		zend_throw_error(NULL, "Cannot call overloaded function for non-object");
		zend_vm_stack_free_args(call);

		if (func->type == ZEND_OVERLOADED_FUNCTION_TEMPORARY) {
			zend_string_release(func->common.function_name);
		}
		efree(func);

		if (EG(exception)) {
			zval_ptr_dtor(retval_ptr);
			ZVAL_UNDEF(retval_ptr);
		}
	}

	EG(scope) = orig_scope;
	zend_vm_stack_free_call_frame(call);

	if (EG(current_execute_data) == &dummy_execute_data) {
		EG(current_execute_data) = dummy_execute_data.prev_execute_data;
	}

	if (EG(exception)) {
		zend_throw_exception_internal(NULL);
	}
	return SUCCESS;
}

static int zephir_is_callable_check_class(const char *name, int name_len, zend_fcall_info_cache *fcc, int *strict_class, char **error) /* {{{ */
{
	int ret = 0;
	zend_class_entry *pce;
	char *lcname = zend_str_tolower_dup(name, name_len);

	*strict_class = 0;
	if (name_len == sizeof("self") - 1 &&
		!memcmp(lcname, "self", sizeof("self") - 1)) {
		if (!EG(scope)) {
			if (error) *error = estrdup("cannot access self:: when no class scope is active");
		} else {
			fcc->called_scope = EG(current_execute_data)->called_scope;
			if (!fcc->object) {
				fcc->object = Z_OBJ(EG(current_execute_data)->This);
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
			fcc->called_scope = EG(current_execute_data)->called_scope;
			if (!fcc->object) {
				fcc->object = Z_OBJ(EG(current_execute_data)->This);
			}
			*strict_class = 1;
			ret = 1;
		}
	} else if (name_len == sizeof("static") - 1 &&
			   !memcmp(lcname, "static", sizeof("static") - 1)) {
		if (!EG(current_execute_data)->called_scope) {
			if (error) *error = estrdup("cannot access static:: when no class scope is active");
		} else {
			fcc->called_scope = EG(current_execute_data)->called_scope;
			if (!fcc->object) {
				fcc->object = Z_OBJ(EG(current_execute_data)->This);
			}
			*strict_class = 1;
			ret = 1;
		}
	} else {
		zend_string *class_name;
		class_name = zend_string_init(name, name_len, 0);
		if ((pce = zend_lookup_class_ex(class_name, NULL, 1)) != NULL) {
			zend_class_entry *scope = EG(current_execute_data) ? EG(current_execute_data)->func->common.scope : NULL;
			fcc->calling_scope = pce;
			if (scope && !fcc->object && EG(current_execute_data) && Z_OBJ(EG(current_execute_data)->This) &&
				instanceof_function(Z_OBJCE(EG(current_execute_data)->This), scope TSRMLS_CC) &&
				instanceof_function(scope, fcc->calling_scope TSRMLS_CC)) {
				fcc->object = Z_OBJ(EG(current_execute_data)->This);
				fcc->called_scope = fcc->object->ce;
			} else {
				fcc->called_scope = fcc->object ? fcc->object->ce : fcc->calling_scope;
			}
			*strict_class = 1;
			ret = 1;
		} else {
			if (error) zephir_spprintf(error, 0, "class '%.*s' not found", name_len, name);
		}
		zend_string_free(class_name);
	}
	efree(lcname);
	return ret;
}

static int zephir_is_callable_check_func(int check_flags, zval *callable, zend_fcall_info_cache *fcc, int strict_class, char **error TSRMLS_DC) /* {{{ */
{
	zend_class_entry *ce_org = fcc->calling_scope;
	int retval = 0;
	char *mname, *lmname;
	zend_string *zs_mname;
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
		if (EXPECTED((fcc->function_handler = zend_hash_str_find_ptr(EG(function_table), lmname, mlen)) != NULL)) {
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

	zs_mname = zend_string_init(mname, mlen, 0);
	lmname = zend_str_tolower_dup(mname, mlen);
	if (strict_class &&
		fcc->calling_scope &&
		mlen == sizeof(ZEND_CONSTRUCTOR_FUNC_NAME)-1 &&
		!memcmp(lmname, ZEND_CONSTRUCTOR_FUNC_NAME, sizeof(ZEND_CONSTRUCTOR_FUNC_NAME) - 1)) {
		fcc->function_handler = fcc->calling_scope->constructor;
		if (fcc->function_handler) {
			retval = 1;
		}
	} else if ((fcc->function_handler = zend_hash_str_find_ptr(ftable, lmname, mlen)) != NULL) {
		retval = 1;
		if ((fcc->function_handler->op_array.fn_flags & ZEND_ACC_CHANGED) &&
			!strict_class && EG(scope) &&
			instanceof_function(fcc->function_handler->common.scope, EG(scope) TSRMLS_CC)) {
			zend_function *priv_fbc;

			if ((priv_fbc = zend_hash_str_find_ptr(&EG(scope)->function_table, lmname, mlen)) != NULL
				&& priv_fbc->common.fn_flags & ZEND_ACC_PRIVATE
				&& priv_fbc->common.scope == EG(scope)) {
				fcc->function_handler = priv_fbc;
			}
		}
	} else {
		if (fcc->object && fcc->calling_scope == ce_org) {
			if (strict_class && ce_org->__call) {
				fcc->function_handler = zend_get_call_trampoline_func(ce_org, zs_mname, 0);
				call_via_handler = 1;
				retval = 1;
			} else if (fcc->object->handlers->get_method) {
				fcc->function_handler = fcc->object->handlers->get_method(&fcc->object, zs_mname, NULL);
				if (fcc->function_handler) {
					if (strict_class &&
						(!fcc->function_handler->common.scope ||
						 !instanceof_function(ce_org, fcc->function_handler->common.scope TSRMLS_CC))) {
						if ((fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER) != 0) {
							if (fcc->function_handler->type != ZEND_OVERLOADED_FUNCTION) {
								zend_string_release(fcc->function_handler->common.function_name);
							}
							zend_free_trampoline(fcc->function_handler);
						}
					} else {
						retval = 1;
						call_via_handler = (fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER) != 0;
					}
				}
			}
		} else if (fcc->calling_scope) {
			if (fcc->calling_scope->get_static_method) {
				fcc->function_handler = fcc->calling_scope->get_static_method(fcc->calling_scope, zs_mname);
			} else {
				fcc->function_handler = zend_std_get_static_method(fcc->calling_scope, zs_mname, NULL);
			}
			if (fcc->function_handler) {
				retval = 1;
				call_via_handler = (fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER) != 0;
				if (call_via_handler && !fcc->object && EG(current_execute_data) && Z_OBJ(EG(current_execute_data)->This) &&
				    instanceof_function(Z_OBJCE(EG(current_execute_data)->This), fcc->calling_scope)) {
					fcc->object = Z_OBJ(EG(current_execute_data)->This);
				}
			}
		}
	}

	if (retval) {
		if (fcc->calling_scope && !call_via_handler) {
			if (!fcc->object && (fcc->function_handler->common.fn_flags & ZEND_ACC_ABSTRACT)) {
				if (error) {
					zephir_spprintf(error, 0, "cannot call abstract method %s::%s()", fcc->calling_scope->name, fcc->function_handler->common.function_name);
					retval = 0;
				} else {
					zend_error(E_ERROR, "Cannot call abstract method %s::%s()", fcc->calling_scope->name, fcc->function_handler->common.function_name);
				}
			} else if (!fcc->object && !(fcc->function_handler->common.fn_flags & ZEND_ACC_STATIC)) {
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
	} else if (error && !(check_flags & IS_CALLABLE_CHECK_SILENT)) {
		if (fcc->calling_scope) {
			if (error) zephir_spprintf(error, 0, "class '%s' does not have a method '%s'", fcc->calling_scope->name, mname);
		} else {
			if (error) zephir_spprintf(error, 0, "function '%s' does not exist", mname);
		}
	}
	efree(lmname);

	zend_string_free(zs_mname);
	if (fcc->object) {
		fcc->called_scope = fcc->object->ce;
	}
	if (retval) {
		fcc->initialized = 1;
	}
	return retval;
}

static zend_bool zephir_is_callable_ex(zval *callable, zend_object *object, uint check_flags, char **callable_name, int *callable_name_len, zend_fcall_info_cache *fcc, char **error) /* {{{ */
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
	fcc->object = NULL;

	if (object &&
	    (!EG(objects_store).object_buckets ||
	     !IS_OBJ_VALID(EG(objects_store).object_buckets[object->handle]))) {
		return 0;
	}

	switch (Z_TYPE_P(callable)) {

		case IS_STRING:
			if (object) {
				fcc->object = object;
				fcc->calling_scope = object->ce;
				if (callable_name) {
					char *ptr;

					*callable_name_len = fcc->calling_scope->name->len + Z_STRLEN_P(callable) + sizeof("::") - 1;
					ptr = *callable_name = emalloc(*callable_name_len + 1);
					memcpy(ptr, fcc->calling_scope->name->val, fcc->calling_scope->name->len);
					ptr += fcc->calling_scope->name->len;
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

			ret = zephir_is_callable_check_func(check_flags, callable, fcc, 0, error);
			if (fcc == &fcc_local &&
				fcc->function_handler &&
				((fcc->function_handler->type == ZEND_INTERNAL_FUNCTION &&
				  (fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER)) ||
				 fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION_TEMPORARY ||
				 fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION)) {
				if (fcc->function_handler->type != ZEND_OVERLOADED_FUNCTION) {
					zend_string_release(fcc->function_handler->common.function_name);
				}
				zend_free_trampoline(fcc->function_handler);
			}
			return ret;

		case IS_ARRAY:
			{
				zval *method = NULL;
				zval *obj = NULL;
				int strict_class = 0;
				if (zend_hash_num_elements(Z_ARRVAL_P(callable)) == 2) {
					obj = zend_hash_index_find(Z_ARRVAL_P(callable), 0);
					method = zend_hash_index_find(Z_ARRVAL_P(callable), 1);
				}

				do {
					if (obj == NULL || method == NULL) {
						break;
					}
					ZVAL_DEREF(method);
					if (Z_TYPE_P(method) != IS_STRING) {
						break;
					}

					ZVAL_DEREF(obj);
					if (Z_TYPE_P(obj) == IS_STRING) {
						if (callable_name) {
							char *ptr;

							*callable_name_len = Z_STRLEN_P(obj) + Z_STRLEN_P(method) + sizeof("::") - 1;
							ptr = *callable_name = emalloc(*callable_name_len + 1);
							memcpy(ptr, Z_STRVAL_P(obj), Z_STRLEN_P(obj));
							ptr += Z_STRLEN_P(obj);
							memcpy(ptr, "::", sizeof("::") - 1);
							ptr += sizeof("::") - 1;
							memcpy(ptr, Z_STRVAL_P(method), Z_STRLEN_P(method) + 1);
						}

						if (check_flags & IS_CALLABLE_CHECK_SYNTAX_ONLY) {
							return 1;
						}

						if (!zephir_is_callable_check_class(Z_STRVAL_P(obj), Z_STRLEN_P(obj), fcc, &strict_class, error)) {
							return 0;
						}

					} else {
						if (!EG(objects_store).object_buckets ||
						    !IS_OBJ_VALID(EG(objects_store).object_buckets[Z_OBJ_HANDLE_P(obj)])) {
							return 0;
						}
						fcc->calling_scope = Z_OBJCE_P(obj); /* TBFixed: what if it's overloaded? */
						fcc->object = Z_OBJ_P(obj);

						if (callable_name) {
							char *ptr;

							*callable_name_len = fcc->calling_scope->name->len + Z_STRLEN_P(method) + sizeof("::") - 1;
							ptr = *callable_name = emalloc(*callable_name_len + 1);
							memcpy(ptr, fcc->calling_scope->name->val, fcc->calling_scope->name->len);
							ptr += fcc->calling_scope->name->len;
							memcpy(ptr, "::", sizeof("::") - 1);
							ptr += sizeof("::") - 1;
							memcpy(ptr, Z_STRVAL_P(method), Z_STRLEN_P(method) + 1);
						}

						if (check_flags & IS_CALLABLE_CHECK_SYNTAX_ONLY) {
							fcc->called_scope = fcc->calling_scope;
							return 1;
						}
					}

					ret = zephir_is_callable_check_func(check_flags, method, fcc, strict_class, error);
					if (fcc == &fcc_local &&
						fcc->function_handler &&
						((fcc->function_handler->type == ZEND_INTERNAL_FUNCTION &&
						  (fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER)) ||
						 fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION_TEMPORARY ||
						 fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION)) {
						if (fcc->function_handler->type != ZEND_OVERLOADED_FUNCTION) {
							zend_string_release(fcc->function_handler->common.function_name);
						}
						zend_free_trampoline(fcc->function_handler);
					}
					return ret;

				} while (0);
				if (zend_hash_num_elements(Z_ARRVAL_P(callable)) == 2) {
					if (!obj || (!Z_ISREF_P(obj)?
								(Z_TYPE_P(obj) != IS_STRING && Z_TYPE_P(obj) != IS_OBJECT) :
								(Z_TYPE_P(Z_REFVAL_P(obj)) != IS_STRING && Z_TYPE_P(Z_REFVAL_P(obj)) != IS_OBJECT))) {
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
			return 0;

		case IS_OBJECT:
			if (Z_OBJ_HANDLER_P(callable, get_closure) && Z_OBJ_HANDLER_P(callable, get_closure)(callable, &fcc->calling_scope, &fcc->function_handler, &fcc->object) == SUCCESS) {
				fcc->called_scope = fcc->calling_scope;
				if (callable_name) {
					zend_class_entry *ce = Z_OBJCE_P(callable); /* TBFixed: what if it's overloaded? */

					*callable_name_len = ce->name->len + sizeof("::__invoke") - 1;
					*callable_name = emalloc(*callable_name_len + 1);
					memcpy(*callable_name, ce->name->val, ce->name->len);
					memcpy((*callable_name) + ce->name->len, "::__invoke", sizeof("::__invoke"));
				}
				return 1;
			}
			/* break missing intentionally */

		default:
			if (callable_name) {
				zval expr_copy;
				int use_copy = zend_make_printable_zval(callable, &expr_copy);

				*callable_name = estrndup(Z_STRVAL(expr_copy), Z_STRLEN(expr_copy));
				*callable_name_len = Z_STRLEN(expr_copy);
				if (use_copy) {
					zval_dtor(&expr_copy);
				}
			}
			if (error) zephir_spprintf(error, 0, "no array or string given");
			return 0;
	}
}

static zend_bool zephir_is_info_dynamic_callable(zephir_fcall_info *info, zend_fcall_info_cache *fcc, zend_class_entry *ce_org, int strict_class)
{
	int call_via_handler = 0, retval = 0;
	zend_string *zs_lcname = zend_string_alloc(info->func_length, 0);
	zend_str_tolower_copy(ZSTR_VAL(zs_lcname), info->func_name, info->func_length);

	if (fcc->object && fcc->calling_scope == ce_org) {
		if (strict_class && ce_org->__call) {
			fcc->function_handler = zend_get_call_trampoline_func(ce_org, zs_lcname, 0);
			call_via_handler = 1;
			retval = 1;
		} else if (fcc->object->handlers->get_method) {
			fcc->function_handler = fcc->object->handlers->get_method(&fcc->object, zs_lcname, NULL);
			if (fcc->function_handler) {
				if (strict_class &&
					(!fcc->function_handler->common.scope ||
					 !instanceof_function(ce_org, fcc->function_handler->common.scope TSRMLS_CC))) {
					if ((fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER) != 0) {
						if (fcc->function_handler->type != ZEND_OVERLOADED_FUNCTION) {
							zend_string_release(fcc->function_handler->common.function_name);
						}
						zend_free_trampoline(fcc->function_handler);
					}
				} else {
					call_via_handler = (fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER) != 0;
					retval = 1;
				}
			}
		}
	} else if (fcc->calling_scope) {
		if (fcc->calling_scope->get_static_method) {
			fcc->function_handler = fcc->calling_scope->get_static_method(fcc->calling_scope, zs_lcname);
		} else {
			fcc->function_handler = zend_std_get_static_method(fcc->calling_scope, zs_lcname, NULL);
		}
		if (fcc->function_handler) {
			call_via_handler = (fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER) != 0;
			if (call_via_handler && !fcc->object && EG(current_execute_data) && Z_OBJ(EG(current_execute_data)->This) &&
			    instanceof_function(Z_OBJCE(EG(current_execute_data)->This), fcc->calling_scope)) {
				fcc->object = Z_OBJ(EG(current_execute_data)->This);
			}
			retval = 1;
		}
	}

	zend_string_release(zs_lcname);
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
	fcc->object = NULL;

	switch (info->type) {

		case ZEPHIR_FCALL_TYPE_FUNC:

			if ((fcc->function_handler = zend_hash_str_find_ptr(EG(function_table), info->func_name, info->func_length)) != NULL) {
				if (fcc == &fcc_local &&
					fcc->function_handler &&
					((fcc->function_handler->type == ZEND_INTERNAL_FUNCTION &&
					  (fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER)) ||
					 fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION_TEMPORARY ||
					 fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION)) {
					if (fcc->function_handler->type != ZEND_OVERLOADED_FUNCTION) {
						efree((char*)fcc->function_handler->common.function_name);
					}
					zend_string_release(fcc->function_handler->common.function_name);
				}
				fcc->initialized = 1;
				return 1;
			}
			break;

		case ZEPHIR_FCALL_TYPE_ZVAL_METHOD:
			if (!EG(objects_store).object_buckets || !IS_OBJ_VALID(EG(objects_store).object_buckets[Z_OBJ_HANDLE_P(info->object_ptr)])) {
				return 0;
			}
			fcc->calling_scope = Z_OBJCE_P(info->object_ptr); /* TBFixed: what if it's overloaded? */
			fcc->called_scope = fcc->calling_scope;
			fcc->object = Z_OBJ_P(info->object_ptr);

			if (!ce_org) {
				ce_org = fcc->calling_scope;
			}

			if ((fcc->function_handler = zend_hash_str_find_ptr(&info->ce->function_table, info->func_name, info->func_length + 1)) != NULL) {
				if (fcc == &fcc_local &&
					fcc->function_handler &&
					((fcc->function_handler->type == ZEND_INTERNAL_FUNCTION &&
					  (fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER)) ||
					 fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION_TEMPORARY ||
					 fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION)) {
					if (fcc->function_handler->type != ZEND_OVERLOADED_FUNCTION) {
						zend_string_release(fcc->function_handler->common.function_name);
					}
					zend_free_trampoline(fcc->function_handler);
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

			fcc->called_scope = EG(current_execute_data)->called_scope;
			fcc->calling_scope = EG(scope);
			if (!fcc->object) {
				fcc->object = Z_OBJ(EG(current_execute_data)->This);
			}
			if ((fcc->function_handler = zend_hash_str_find_ptr(&fcc->calling_scope->function_table, info->func_name, info->func_length)) != NULL) {
				if (fcc == &fcc_local &&
					fcc->function_handler &&
					((fcc->function_handler->type == ZEND_INTERNAL_FUNCTION &&
					  (fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER)) ||
					 fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION_TEMPORARY ||
					 fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION)) {
					if (fcc->function_handler->type != ZEND_OVERLOADED_FUNCTION) {
						zend_string_release(fcc->function_handler->common.function_name);
					}
					zend_free_trampoline(fcc->function_handler);
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

			fcc->calling_scope = EG(scope)->parent;
			fcc->called_scope = EG(current_execute_data)->called_scope;
			if (!fcc->object) {
				fcc->object = Z_OBJ(EG(current_execute_data)->This);
			}

			if ((fcc->function_handler = zend_hash_str_find_ptr(&fcc->calling_scope->function_table, info->func_name, info->func_length)) != NULL) {
				if (fcc == &fcc_local &&
					fcc->function_handler &&
					((fcc->function_handler->type == ZEND_INTERNAL_FUNCTION &&
					  (fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER)) ||
					 fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION_TEMPORARY ||
					 fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION)) {
					if (fcc->function_handler->type != ZEND_OVERLOADED_FUNCTION) {
						zend_string_release(fcc->function_handler->common.function_name);
					}
					zend_free_trampoline(fcc->function_handler);
				}
				retval = 1;
			}

			if (!retval) {
				retval = zephir_is_info_dynamic_callable(info, fcc, ce_org, 1 TSRMLS_CC);
			}
			break;

		case ZEPHIR_FCALL_TYPE_CLASS_STATIC_METHOD:

			if (!EG(current_execute_data) || !EG(current_execute_data)->called_scope) {
				return 0; // cannot access static:: when no class scope is active
			}

			fcc->called_scope = EG(current_execute_data)->called_scope;
			if (!fcc->object) {
				fcc->object = Z_OBJ(EG(current_execute_data)->This);
			}
			fcc->calling_scope = fcc->called_scope;

			if ((fcc->function_handler = zend_hash_str_find_ptr(&fcc->calling_scope->function_table, info->func_name, info->func_length)) != NULL) {
				if (fcc == &fcc_local &&
					fcc->function_handler &&
					((fcc->function_handler->type == ZEND_INTERNAL_FUNCTION &&
					  (fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER)) ||
					 fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION_TEMPORARY ||
					 fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION)) {
					if (fcc->function_handler->type != ZEND_OVERLOADED_FUNCTION) {
						zend_string_release(fcc->function_handler->common.function_name);
					}
					zend_free_trampoline(fcc->function_handler);
				}
				retval = 1;
			}

			if (!retval) {
				retval = zephir_is_info_dynamic_callable(info, fcc, ce_org, 1 TSRMLS_CC);
			}
			break;

		case ZEPHIR_FCALL_TYPE_CE_METHOD:
			{
				zend_class_entry *scope = EG(current_execute_data) ? EG(current_execute_data)->func->common.scope : NULL;;

				fcc->calling_scope = info->ce;
				if (scope && !fcc->object && EG(current_execute_data) && Z_OBJ(EG(current_execute_data)->This) &&
		    		instanceof_function(Z_OBJCE(EG(current_execute_data)->This), scope) &&
				    instanceof_function(scope, fcc->calling_scope)) {
					fcc->object = Z_OBJ(EG(current_execute_data)->This);
					fcc->called_scope = Z_OBJCE(EG(current_execute_data)->This);
				} else {
					fcc->called_scope = fcc->object ? fcc->object->ce : fcc->calling_scope;
				}

				if ((fcc->function_handler = zend_hash_str_find_ptr(&fcc->calling_scope->function_table, info->func_name, info->func_length)) != NULL) {
					if (fcc == &fcc_local &&
						fcc->function_handler &&
						((fcc->function_handler->type == ZEND_INTERNAL_FUNCTION &&
						  (fcc->function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER)) ||
						 fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION_TEMPORARY ||
						 fcc->function_handler->type == ZEND_OVERLOADED_FUNCTION)) {
						if (fcc->function_handler->type != ZEND_OVERLOADED_FUNCTION) {
							zend_string_release(fcc->function_handler->common.function_name);
						}
						zend_free_trampoline(fcc->function_handler);
					}
					retval = 1;
				}

				if (!retval) {
					retval = zephir_is_info_dynamic_callable(info, fcc, ce_org, 1 TSRMLS_CC);
				}
			}
			break;
	}

	if (fcc->object) {
		fcc->called_scope = fcc->object->ce;
	}
	if (retval) {
		fcc->initialized = 1;
	}

	return retval;
}

int zephir_call_function_opt(zend_fcall_info *fci, zend_fcall_info_cache *fci_cache, zephir_fcall_info *info, zval *params[])
{
	uint32_t i;
	zend_class_entry *calling_scope = NULL;
	zend_execute_data *call, dummy_execute_data;
	zend_fcall_info_cache fci_cache_local;
	zend_function *func;
	zend_class_entry *orig_scope;

	ZVAL_UNDEF(fci->retval);

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
			zend_error_noreturn(E_CORE_ERROR, "Corrupted fcall_info provided to zend_call_function()");
			break;
	}

	orig_scope = EG(scope);

	/* Initialize execute_data */
	if (!EG(current_execute_data)) {
		/* This only happens when we're called outside any execute()'s
		 * It shouldn't be strictly necessary to NULL execute_data out,
		 * but it may make bugs easier to spot
		 */
		memset(&dummy_execute_data, 0, sizeof(zend_execute_data));
		EG(current_execute_data) = &dummy_execute_data;
	} else if (EG(current_execute_data)->func &&
	           ZEND_USER_CODE(EG(current_execute_data)->func->common.type) &&
	           EG(current_execute_data)->opline->opcode != ZEND_DO_FCALL &&
	           EG(current_execute_data)->opline->opcode != ZEND_DO_ICALL &&
	           EG(current_execute_data)->opline->opcode != ZEND_DO_UCALL &&
	           EG(current_execute_data)->opline->opcode != ZEND_DO_FCALL_BY_NAME) {
		/* Insert fake frame in case of include or magic calls */
		dummy_execute_data = *EG(current_execute_data);
		dummy_execute_data.prev_execute_data = EG(current_execute_data);
		dummy_execute_data.call = NULL;
		dummy_execute_data.opline = NULL;
		dummy_execute_data.func = NULL;
		EG(current_execute_data) = &dummy_execute_data;
	}

	if (!fci_cache || !fci_cache->initialized) {
		char *error = NULL;

		if (!fci_cache) {
			fci_cache = &fci_cache_local;
		}

		if (!info) {
			char *callable_name;
			if (!zephir_is_callable_ex(&fci->function_name, fci->object, IS_CALLABLE_CHECK_SILENT, &callable_name, NULL, fci_cache, &error)) {
				if (error) {
					zend_error(E_WARNING, "Invalid callback %s, %s", callable_name, error);
					efree(error);
				}
				if (callable_name) {
					efree(callable_name);
				}
				if (EG(current_execute_data) == &dummy_execute_data) {
					EG(current_execute_data) = dummy_execute_data.prev_execute_data;
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
			if (!zephir_is_info_callable_ex(info, fci_cache)) {
				return FAILURE;
			}
		}
	}

	func = fci_cache->function_handler;
	call = zend_vm_stack_push_call_frame(ZEND_CALL_TOP_FUNCTION,
		func, fci->param_count, fci_cache->called_scope, fci_cache->object);
	calling_scope = fci_cache->calling_scope;
	fci->object = fci_cache->object;
	if (fci->object &&
	    (!EG(objects_store).object_buckets ||
	     !IS_OBJ_VALID(EG(objects_store).object_buckets[fci->object->handle]))) {
		if (EG(current_execute_data) == &dummy_execute_data) {
			EG(current_execute_data) = dummy_execute_data.prev_execute_data;
		}
		return FAILURE;
	}

	if (func->common.fn_flags & (ZEND_ACC_ABSTRACT|ZEND_ACC_DEPRECATED)) {
		if (func->common.fn_flags & ZEND_ACC_ABSTRACT) {
			zend_throw_error(NULL, "Cannot call abstract method %s::%s()", ZSTR_VAL(func->common.scope->name), ZSTR_VAL(func->common.function_name));
			return FAILURE;
		}
		if (func->common.fn_flags & ZEND_ACC_DEPRECATED) {
 			zend_error(E_DEPRECATED, "Function %s%s%s() is deprecated",
				func->common.scope ? ZSTR_VAL(func->common.scope->name) : "",
				func->common.scope ? "::" : "",
				ZSTR_VAL(func->common.function_name));
		}
	}

	for (i = 0; i < fci->param_count; i++) {
		zval *param;
		zval *arg = params[i];

		if (ARG_SHOULD_BE_SENT_BY_REF(func, i + 1)) {
			if (UNEXPECTED(!Z_ISREF_P(arg))) {
				/*if (fci->no_separation &&
					!ARG_MAY_BE_SENT_BY_REF(func, i + 1)) {
					if (i) {
						// hack to clean up the stack
						ZEND_CALL_NUM_ARGS(call) = i;
						zend_vm_stack_free_args(call);
					}
					zend_vm_stack_free_call_frame(call);

					zend_error(E_WARNING, "Parameter %d to %s%s%s() expected to be a reference, value given",
						i+1,
						func->common.scope ? ZSTR_VAL(func->common.scope->name) : "",
						func->common.scope ? "::" : "",
						ZSTR_VAL(func->common.function_name));
					if (EG(current_execute_data) == &dummy_execute_data) {
						EG(current_execute_data) = dummy_execute_data.prev_execute_data;
					}
					return FAILURE;
				} */

				ZVAL_NEW_REF(arg, arg);
			}
			Z_ADDREF_P(arg);
		} else {
			if (Z_ISREF_P(arg) &&
			    !(func->common.fn_flags & ZEND_ACC_CALL_VIA_TRAMPOLINE)) {
				/* don't separate references for __call */
				arg = Z_REFVAL_P(arg);
			}
			if (Z_OPT_REFCOUNTED_P(arg)) {
				Z_ADDREF_P(arg);
			}
		}
		param = ZEND_CALL_ARG(call, i+1);
		ZVAL_COPY_VALUE(param, arg);
	}

	EG(scope) = calling_scope;
	if (func->common.fn_flags & ZEND_ACC_STATIC) {
		fci->object = NULL;
	}
	Z_OBJ(call->This) = fci->object;

	if (func->type == ZEND_USER_FUNCTION) {
		int call_via_handler = (func->common.fn_flags & ZEND_ACC_CALL_VIA_TRAMPOLINE) != 0;
		EG(scope) = func->common.scope;
#if PHP_VERSION_ID < 70100
		call->symbol_table = fci->symbol_table;
#else
		call->symbol_table = NULL;
#endif
		if (UNEXPECTED(func->op_array.fn_flags & ZEND_ACC_CLOSURE)) {
			ZEND_ASSERT(GC_TYPE((zend_object*)func->op_array.prototype) == IS_OBJECT);
			GC_REFCOUNT((zend_object*)func->op_array.prototype)++;
			ZEND_ADD_CALL_FLAG(call, ZEND_CALL_CLOSURE);
		}
		if (EXPECTED((func->op_array.fn_flags & ZEND_ACC_GENERATOR) == 0)) {
			zend_init_execute_data(call, &func->op_array, fci->retval);
			zend_execute_ex(call);
		} else {
			zend_generator_create_zval(call, &func->op_array, fci->retval);
		}
		if (call_via_handler) {
			/* We must re-initialize function again */
			fci_cache->initialized = 0;
		}
	} else if (func->type == ZEND_INTERNAL_FUNCTION) {
		int call_via_handler = (func->common.fn_flags & ZEND_ACC_CALL_VIA_TRAMPOLINE) != 0;
		ZVAL_NULL(fci->retval);
		if (func->common.scope) {
			EG(scope) = func->common.scope;
		}
		call->prev_execute_data = EG(current_execute_data);
		call->return_value = NULL; /* this is not a constructor call */
		EG(current_execute_data) = call;
		if (EXPECTED(zend_execute_internal == NULL)) {
			/* saves one function call if zend_execute_internal is not used */
			func->internal_function.handler(call, fci->retval);
		} else {
			zend_execute_internal(call, fci->retval);
		}
		EG(current_execute_data) = call->prev_execute_data;
		zend_vm_stack_free_args(call);

		/*  We shouldn't fix bad extensions here,
			because it can break proper ones (Bug #34045)
		if (!EX(function_state).function->common.return_reference)
		{
			INIT_PZVAL(f->retval);
		}*/
		if (EG(exception)) {
			zval_ptr_dtor(fci->retval);
			ZVAL_UNDEF(fci->retval);
		}

		if (call_via_handler) {
			/* We must re-initialize function again */
			fci_cache->initialized = 0;
		}
	} else { /* ZEND_OVERLOADED_FUNCTION */
		ZVAL_NULL(fci->retval);

		/* Not sure what should be done here if it's a static method */
		if (fci->object) {
			call->prev_execute_data = EG(current_execute_data);
			EG(current_execute_data) = call;
			fci->object->handlers->call_method(func->common.function_name, fci->object, call, fci->retval);
			EG(current_execute_data) = call->prev_execute_data;
		} else {
			zend_throw_error(NULL, "Cannot call overloaded function for non-object");
		}

		zend_vm_stack_free_args(call);

		if (func->type == ZEND_OVERLOADED_FUNCTION_TEMPORARY) {
			zend_string_release(func->common.function_name);
		}
		efree(func);

		if (EG(exception)) {
			zval_ptr_dtor(fci->retval);
			ZVAL_UNDEF(fci->retval);
		}
	}

	EG(scope) = orig_scope;
	zend_vm_stack_free_call_frame(call);

	if (EG(current_execute_data) == &dummy_execute_data) {
		EG(current_execute_data) = dummy_execute_data.prev_execute_data;
	}

	if (EG(exception)) {
		zend_throw_exception_internal(NULL);
	}
	return SUCCESS;
}
