
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2017 Zephir Team (https://www.zephir-lang.com)      |
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
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
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
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/backtrace.h"
#include "kernel/variables.h"

int zephir_has_constructor_ce(const zend_class_entry *ce)
{
	while (ce) {
		if (ce->constructor != NULL) {
			return 1;
		}
		ce = ce->parent;
	}
	return 0;
}

/**
 * Creates a unique key to cache the current method/function call address for the current scope
 */
static int zephir_make_fcall_key(zend_string* s, zephir_call_type type, zend_class_entry *ce, zval *function, const zend_class_entry* called_scope)
{
	const zend_class_entry *calling_scope;
	unsigned char t;

#if PHP_VERSION_ID >= 70100
	calling_scope = zend_get_executed_scope();
#else
	calling_scope = EG(scope);
#endif

	switch (type) {
		case zephir_fcall_parent:
			if (UNEXPECTED(!calling_scope || !calling_scope->parent)) {
				return FAILURE;
			}

			calling_scope = calling_scope->parent;
			break;

		case zephir_fcall_static:
			calling_scope = called_scope;
			if (UNEXPECTED(!calling_scope)) {
				return FAILURE;
			}

			break;

		case zephir_fcall_self:
			/* EG(scope) */
			break;

		case zephir_fcall_function:
			if (Z_TYPE_P(function) == IS_OBJECT) {
				return FAILURE;
			}

			calling_scope = NULL;
			called_scope  = NULL;
			break;

		case zephir_fcall_ce:
			calling_scope = ce;
			called_scope  = ce;
			break;

		case zephir_fcall_method:
			if (Z_TYPE_P(function) == IS_OBJECT) {
				return FAILURE;
			}

			calling_scope = ce;
			called_scope  = ce;
			break;

		default:
			return FAILURE;
	}

	if (called_scope == calling_scope) {
	/* Calls within the same scope, this won't trigger magic methods or failures due to restricted visibility */
		t = 0;
	}
	else if (called_scope && calling_scope && (instanceof_function(called_scope, calling_scope) || instanceof_function(calling_scope, called_scope))) {
	/* Calls within the same chain of inheritance; can call protected methods */
		t = 1;
	}
	else {
	/* Can safely call only public methods */
		t = 2;
	}

	{
		char* cls      = calling_scope ? ZSTR_VAL(calling_scope->name) : "";
		size_t cls_len = calling_scope ? ZSTR_LEN(calling_scope->name) : 0;
		char* mth      = NULL;
		size_t mth_len = 0;
		char* buf;

		if (Z_TYPE_P(function) == IS_STRING) {
			mth     = Z_STRVAL_P(function);
			mth_len = Z_STRLEN_P(function);
		}
		else if (Z_TYPE_P(function) == IS_ARRAY) {
			zval *method;
			HashTable *function_hash = Z_ARRVAL_P(function);
			if (
					function_hash->nNumOfElements == 2
				 && ((method = zend_hash_index_find(function_hash, 1)) != NULL)
				 && Z_TYPE_P(method) == IS_STRING
			) {
				mth     = Z_STRVAL_P(method);
				mth_len = Z_STRLEN_P(method);
			}
		}

		if (cls_len + 1 + mth_len + sizeof(unsigned char) > 255) {
			return FAILURE;
		}

		ZSTR_LEN(s) = cls_len + 1 + mth_len + sizeof(unsigned char);
		buf = ZSTR_VAL(s);
		zend_str_tolower_copy(buf, cls, cls_len + 1);
		zend_str_tolower_copy(buf + cls_len + 1, mth, mth_len);
		buf[cls_len + 1 + mth_len] = t;
		buf[cls_len + 1 + mth_len + sizeof(t)] = '\0';
	}

	ZSTR_H(s) = zend_hash_func(ZSTR_VAL(s), ZSTR_LEN(s));
	return SUCCESS;
}

static void resolve_callable(zval* retval, zephir_call_type type, zend_class_entry *ce, zval *object, zval *function)
{
	if (type == zephir_fcall_function || IS_ARRAY == Z_TYPE_P(function) || IS_OBJECT == Z_TYPE_P(function)) {
		ZVAL_COPY(retval, function);
		return;
	}

	array_init_size(retval, 2);
	zend_hash_real_init(Z_ARRVAL_P(retval), 1);
	ZEND_HASH_FILL_PACKED(Z_ARRVAL_P(retval)) {
		zval q;
		switch (type) {
			case zephir_fcall_parent:
				zend_string_addref(i_parent);
				ZVAL_STR(&q, i_parent);
				ZEND_HASH_FILL_ADD(&q);
				break;

			case zephir_fcall_self:
				zend_string_addref(i_self);
				ZVAL_STR(&q, i_self);
				ZEND_HASH_FILL_ADD(&q);
				break;

			case zephir_fcall_static:
				zend_string_addref(i_static);
				ZVAL_STR(&q, i_static);
				ZEND_HASH_FILL_ADD(&q);
				break;

			case zephir_fcall_ce:
				assert(ce);
				zend_string_addref(ce->name);
				ZVAL_STR(&q, ce->name);
				ZEND_HASH_FILL_ADD(&q);
				break;

			default:
				assert(object);
				Z_TRY_ADDREF_P(object);
				ZEND_HASH_FILL_ADD(object);
				break;
		}

		Z_TRY_ADDREF_P(function);
		ZEND_HASH_FILL_ADD(function);
	} ZEND_HASH_FILL_END();
}

static void populate_fcic(zend_fcall_info_cache* fcic, zephir_call_type type, zend_class_entry* ce, zval *this_ptr, zval *func, zend_class_entry* called_scope)
{
	zend_class_entry* calling_scope;
	fcic->initialized      = 0;
	fcic->function_handler = NULL;

	if (type == zephir_fcall_function && Z_TYPE_P(func) == IS_STRING) {
		fcic->initialized   = 1;
		fcic->called_scope  = NULL;
		fcic->calling_scope = NULL;
		fcic->object        = NULL;
		return;
	}

	fcic->called_scope = called_scope;

#if PHP_VERSION_ID >= 70100
	calling_scope = zend_get_executed_scope();
#else
	calling_scope = EG(scope);
#endif

	fcic->object = this_ptr ? Z_OBJ_P(this_ptr) : NULL;
	switch (type) {
		case zephir_fcall_parent:
			if (UNEXPECTED(!calling_scope || !calling_scope->parent)) {
				return;
			}

			fcic->calling_scope = calling_scope->parent;
			break;

		case zephir_fcall_static:
			fcic->calling_scope = fcic->called_scope;
			if (UNEXPECTED(!calling_scope)) {
				return;
			}

			break;

		case zephir_fcall_self:
			fcic->calling_scope = calling_scope;
			break;

		case zephir_fcall_ce:
			fcic->calling_scope = ce;
			fcic->called_scope  = ce;
			break;

		case zephir_fcall_function:
		case zephir_fcall_method:
			if (Z_TYPE_P(func) == IS_OBJECT) {
				if (Z_OBJ_HANDLER_P(func, get_closure) && Z_OBJ_HANDLER_P(func, get_closure)(func, &fcic->calling_scope, &fcic->function_handler, &fcic->object) == SUCCESS) {
					fcic->called_scope = fcic->calling_scope;
					break;
				}

				return;
			}

			fcic->calling_scope = this_ptr ? Z_OBJCE_P(this_ptr) : NULL;
			fcic->called_scope  = fcic->calling_scope;
			break;

		default:
			return;
	}

	fcic->initialized = 1;
}

/**
 * Calls a function/method in the PHP userland
 */
int zephir_call_user_function(zval *object_pp, zend_class_entry *obj_ce, zephir_call_type type,
	zval *function_name, zval *retval_ptr, zephir_fcall_cache_entry **cache_entry, int cache_slot, zend_uint param_count,
	zval *params[])
{
	zval local_retval_ptr;
	int status;
	zend_fcall_info fci;
	zend_fcall_info_cache fcic;
	zend_zephir_globals_def *zephir_globals_ptr = ZEPHIR_VGLOBAL;
	char fcall_key[sizeof(zend_string) + 256];
	int key_ok = FAILURE;
	zephir_fcall_cache_entry *temp_cache_entry = NULL;
	zval callable;
	int i;
	zend_class_entry* called_scope = zend_get_called_scope(EG(current_execute_data));

	assert(obj_ce || !object_pp);
	ZVAL_UNDEF(&callable);
	ZVAL_UNDEF(&local_retval_ptr);

	if ((!cache_entry || !*cache_entry) && zephir_globals_ptr->cache_enabled) {
		int reload_cache = 1;
		if (cache_slot > 0 && zephir_globals_ptr->scache[cache_slot]) {
			reload_cache = 0;
			temp_cache_entry = zephir_globals_ptr->scache[cache_slot];
			if (cache_entry) {
				*cache_entry = temp_cache_entry;
			}
		}

		if (reload_cache) {
			key_ok = zephir_make_fcall_key((zend_string*)fcall_key, type, (object_pp && type != zephir_fcall_ce ? Z_OBJCE_P(object_pp) : obj_ce), function_name, called_scope);
			if (SUCCESS == key_ok) {
				zend_string* zs  = (zend_string*)fcall_key;
				GC_REFCOUNT(zs)  = 1;
				GC_TYPE_INFO(zs) = IS_STRING;

				temp_cache_entry = zend_hash_find_ptr(zephir_globals_ptr->fcache, zs);
				if (temp_cache_entry) {
					cache_entry = &temp_cache_entry;
				}
			}
		}
	}

	fci.size           = sizeof(fci);
#if PHP_VERSION_ID < 70100
	fci.function_table = obj_ce ? &obj_ce->function_table : EG(function_table);
	fci.symbol_table   = NULL;
#endif
	fci.object         = object_pp ? Z_OBJ_P(object_pp) : NULL;
	fci.retval         = retval_ptr ? retval_ptr : &local_retval_ptr;
	fci.param_count    = param_count;
	fci.params         = NULL;
	fci.no_separation  = 1;

	fcic.initialized = 0;
	if (cache_entry && *cache_entry) {
	/* We have a cache record, initialize scope */
		populate_fcic(&fcic, type, obj_ce, object_pp, function_name, called_scope);
		if (!fcic.function_handler) {
			fcic.function_handler = *cache_entry;
		}

		ZVAL_UNDEF(&fci.function_name);
	}
	else if ((cache_entry && !*cache_entry) || zephir_globals_ptr->cache_enabled) {
	/* The caller is interested in caching OR we have the call cache enabled */
		resolve_callable(&callable, type, (object_pp && type != zephir_fcall_ce ? Z_OBJCE_P(object_pp) : obj_ce), object_pp, function_name);
		zend_is_callable_ex(&callable, fci.object, IS_CALLABLE_CHECK_SILENT, NULL, &fcic, NULL);
	}

	if (!fcic.initialized) {
		resolve_callable(&callable, type, (object_pp && type != zephir_fcall_ce ? Z_OBJCE_P(object_pp) : obj_ce), object_pp, function_name);
		ZVAL_COPY_VALUE(&fci.function_name, &callable);
	}

#ifdef _MSC_VER
	zval *p = emalloc(sizeof(zval) * (fci.param_count + 1));
#else
	zval p[fci.param_count];
#endif
	for (i=0; i<fci.param_count; ++i) {
		ZVAL_COPY_VALUE(&p[i], params[i]);
	}

	fci.params = p;

#if 0
/*
	fcic.initialized = 0;
	if (Z_TYPE(callable) == IS_NULL) {
		resolve_callable(&callable, type, (object_pp && type != zephir_fcall_ce ? Z_OBJCE_P(object_pp) : obj_ce), object_pp, function_name);
	}
*/
	zval tmp;
	zephir_var_export_ex(&tmp, function_name);
	if (obj_ce) {
		fprintf(stderr, "obj_ce: %s\n", ZSTR_VAL(obj_ce->name));
	}
	fprintf(stderr, "> %s called: %p, calling: %p, obj: %p, h: %p, type=%d\n", Z_STRVAL(tmp), fcic.called_scope, fcic.calling_scope, fcic.object, fcic.function_handler, (int)type);
#endif
	status = zend_call_function(&fci, &fcic);
#if 0
	fprintf(stderr, "< called: %p, calling: %p, obj: %p, h: %p\n", fcic.called_scope, fcic.calling_scope, fcic.object, fcic.function_handler);
#endif

#ifdef _MSC_VER
	efree(p);
#endif

	if (Z_TYPE(callable) != IS_UNDEF) {
		zval_ptr_dtor(&callable);
	}

	/* Skip caching IF:
	 * call failed OR there was an exception (to be safe) OR cache key is not defined OR
	 * fcall cache was deinitialized OR we have a slot cache
	 */
	if (EXPECTED(status != FAILURE) && !EG(exception) && SUCCESS == key_ok && fcic.initialized && !temp_cache_entry) {
		zephir_fcall_cache_entry *cache_entry_temp = fcic.function_handler;

		if (cache_entry) {
			*cache_entry = cache_entry_temp;
			if (cache_slot > 0) {
				zephir_globals_ptr->scache[cache_slot] = *cache_entry;
			}
		}

		if (zephir_globals_ptr->cache_enabled) {
			zend_string *zs = (zend_string*)fcall_key;
			zend_hash_str_add_ptr(zephir_globals_ptr->fcache, ZSTR_VAL(zs), ZSTR_LEN(zs), cache_entry_temp);
		}
	}

	if (!retval_ptr) {
		zval_ptr_dtor(&local_retval_ptr);
	}
	else if (FAILURE == status || EG(exception)) {
		ZVAL_NULL(retval_ptr);
	}

	return status;
}

int zephir_call_func_aparams(zval *return_value_ptr, const char *func_name, uint func_length,
	zephir_fcall_cache_entry **cache_entry, int cache_slot,
	uint param_count, zval **params)
{
	int status;
	zval rv, *rvp = return_value_ptr ? return_value_ptr : &rv;

	ZVAL_UNDEF(&rv);

#ifndef ZEPHIR_RELEASE
	if (return_value_ptr != NULL && Z_TYPE_P(return_value_ptr) > IS_NULL) {
		fprintf(stderr, "%s: *return_value_ptr must be NULL\n", __func__);
		zephir_print_backtrace();
		abort();
	}
#endif

	zval f;
	ZVAL_STRINGL(&f, func_name, func_length);
	status = zephir_call_user_function(NULL, NULL, zephir_fcall_function, &f, rvp, cache_entry, cache_slot, param_count, params);
	zval_ptr_dtor(&f);

	if (status == FAILURE && !EG(exception)) {
		zephir_throw_exception_format(spl_ce_RuntimeException, "Call to undefined function %s()", func_name);
	} else if (EG(exception)) {
		status = FAILURE;
	}

	if (!return_value_ptr) {
		zval_ptr_dtor(&rv);
	}

	return status;
}

int zephir_call_zval_func_aparams(zval *return_value_ptr, zval *func_name,
	zephir_fcall_cache_entry **cache_entry, int cache_slot,
	uint param_count, zval **params)
{
	int status;
	zval rv, *rvp = return_value_ptr ? return_value_ptr : &rv;

	ZVAL_UNDEF(&rv);

#ifndef ZEPHIR_RELEASE
	if (return_value_ptr != NULL && Z_TYPE_P(return_value_ptr) > IS_NULL) {
		fprintf(stderr, "%s: *return_value_ptr must be NULL\n", __func__);
		zephir_print_backtrace();
		abort();
	}
#endif

	status = zephir_call_user_function(NULL, NULL, zephir_fcall_function, func_name, rvp, cache_entry, cache_slot, param_count, params);

	if (status == FAILURE && !EG(exception)) {
		zephir_throw_exception_format(spl_ce_RuntimeException, "Call to undefined function %s()", Z_TYPE_P(func_name) ? Z_STRVAL_P(func_name) : "undefined");
	} else if (EG(exception)) {
		status = FAILURE;
	}

	if (!return_value_ptr) {
		zval_ptr_dtor(&rv);
	}

	return status;
}

int zephir_call_class_method_aparams(zval *return_value, zend_class_entry *ce, zephir_call_type type, zval *object,
	const char *method_name, uint method_len,
	zephir_fcall_cache_entry **cache_entry, int cache_slot,
	uint param_count, zval **params)
{
	int status;

#ifndef ZEPHIR_RELEASE
	if (return_value != NULL && Z_TYPE_P(return_value) > IS_NULL) {
		fprintf(stderr, "%s: *return_value must be IS_NULL or IS_UNDEF\n", __func__);
		zephir_print_backtrace();
		abort();
	}
#endif

	if (object && Z_TYPE_P(object) != IS_OBJECT) {
		zephir_throw_exception_format(spl_ce_RuntimeException, "Trying to call method %s on a non-object", method_name);
		if (return_value) {
			ZVAL_NULL(return_value);
		}
		return FAILURE;
	}

	zval method;
	ZVAL_STRINGL(&method, method_name, method_len);
	status = zephir_call_user_function(object, ce, type, &method, return_value, cache_entry, cache_slot, param_count, params);
	zval_ptr_dtor(&method);

	if (status == FAILURE && !EG(exception)) {
		switch (type) {
			case zephir_fcall_parent:
				zephir_throw_exception_format(spl_ce_RuntimeException, "Call to undefined method parent::%s()", method_name);
				break;

			case zephir_fcall_self:
				zephir_throw_exception_format(spl_ce_RuntimeException, "Call to undefined method self::%s()", method_name);
				break;

			case zephir_fcall_static:
				zephir_throw_exception_format(spl_ce_RuntimeException, "Call to undefined method static::%s()", method_name);
				break;

			case zephir_fcall_ce:
			case zephir_fcall_method:
				zephir_throw_exception_format(spl_ce_RuntimeException, "Call to undefined method %s::%s()", ce->name, method_name);
				break;

			default:
				zephir_throw_exception_format(spl_ce_RuntimeException, "Call to undefined method ?::%s()", method_name);
		}
	} else if (EG(exception)) {
		status = FAILURE;
	}

	return status;
}

/**
 * Replaces call_user_func_array avoiding function lookup
 * This function does not return FAILURE if an exception has ocurred
 */
int zephir_call_user_func_array_noex(zval *return_value, zval *handler, zval *params)
{
	zend_fcall_info fci;
	zend_fcall_info_cache fci_cache;
	char *is_callable_error = NULL;
	int status = FAILURE;

	if (params && Z_TYPE_P(params) != IS_ARRAY) {
		ZVAL_NULL(return_value);
		php_error_docref(NULL, E_WARNING, "Invalid arguments supplied for zephir_call_user_func_array_noex()");
		return FAILURE;
	}

	zend_fcall_info_init(handler, 0, &fci, &fci_cache, NULL, &is_callable_error);

	if (is_callable_error) {
		zend_error(E_WARNING, "%s", is_callable_error);
		efree(is_callable_error);
	} else {
		status = SUCCESS;
	}

	if (status == SUCCESS) {
		zend_fcall_info_args(&fci, params);

		fci.retval = return_value;
		zend_call_function(&fci, &fci_cache);

		zend_fcall_info_args_clear(&fci, 1);
	}

	if (EG(exception)) {
		status = SUCCESS;
	}

	return status;
}

/**
 * If a retval_ptr is specified, PHP's implementation of zend_eval_stringl
 * simply prepends a "return " which causes only the first statement to be executed
 */
void zephir_eval_php(zval *str, zval *retval_ptr, char *context)
{
	zval local_retval;
	zend_op_array *new_op_array = NULL;
	uint32_t original_compiler_options;

	ZVAL_UNDEF(&local_retval);

	original_compiler_options = CG(compiler_options);
	CG(compiler_options) = ZEND_COMPILE_DEFAULT_FOR_EVAL;
	new_op_array = zend_compile_string(str, context);
	CG(compiler_options) = original_compiler_options;

	if (new_op_array)
	{
		EG(no_extensions) = 1;
		zend_try {
			zend_execute(new_op_array, &local_retval);
		} zend_catch {
			destroy_op_array(new_op_array);
			efree_size(new_op_array, sizeof(zend_op_array));
			zend_bailout();
		} zend_end_try();
		EG(no_extensions) = 0;

		if (Z_TYPE(local_retval) != IS_UNDEF) {
			if (retval_ptr) {
				ZVAL_COPY_VALUE(retval_ptr, &local_retval);
			} else {
				zval_ptr_dtor(&local_retval);
			}
		} else if (retval_ptr) {
			ZVAL_NULL(retval_ptr);
		}

		destroy_op_array(new_op_array);
		efree_size(new_op_array, sizeof(zend_op_array));
	}
}
