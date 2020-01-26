/*
 * This file is part of the Zephir.
 *
 * (c) Phalcon Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code. If you did not receive
 * a copy of the license it is available through the world-wide-web at the
 * following url: https://docs.zephir-lang.com/en/latest/license
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>
#include <php_ext.h>
#include <php_main.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>
#include <ext/spl/spl_exceptions.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/exception.h"


zend_string* i_parent = NULL;
zend_string* i_static = NULL;
zend_string* i_self   = NULL;

int zephir_is_iterable_ex(zval *arr, int duplicate)
{
	if (UNEXPECTED(Z_TYPE_P(arr) == IS_OBJECT && zephir_instance_of_ev(arr, (const zend_class_entry *)zend_ce_iterator))) {
		return 1;
	} else if (UNEXPECTED(Z_TYPE_P(arr) != IS_ARRAY)) {
		return 0;
	}
    //TODO: duplicate
    return 1;
}

/**
 * Parses method parameters with minimum overhead
 */
int zephir_fetch_parameters(int num_args, int required_args, int optional_args, ...)
{
	va_list va;
	int arg_count = ZEND_CALL_NUM_ARGS(EG(current_execute_data));
	zval *arg, **p;
	int i;

	if (num_args < required_args || (num_args > (required_args + optional_args))) {
		zephir_throw_exception_string(spl_ce_BadMethodCallException, SL("Wrong number of parameters"));
		return FAILURE;
	}

	if (num_args > arg_count) {
		zephir_throw_exception_string(spl_ce_BadMethodCallException, SL("Could not obtain parameters for parsing"));
		return FAILURE;
	}

	if (!num_args) {
		return SUCCESS;
	}

	va_start(va, optional_args);

	i = 0;
	while (num_args-- > 0) {
		arg = ZEND_CALL_ARG(EG(current_execute_data), i + 1);
		p = va_arg(va, zval **);
		*p = arg;

		i++;
	}

	va_end(va);

	return SUCCESS;
}

/**
 * Gets the global zval into PG macro
 */
int zephir_get_global(zval *arr, const char *global, unsigned int global_length)
{
	zend_array *symbol_table;
	zend_string *str = zend_string_init(global, global_length, 0);

	if (PG(auto_globals_jit)) {
		zend_is_auto_global(str);
	}

	if (&EG(symbol_table)) {
		zval *gv;

		if ((gv = zend_hash_find_ind(&EG(symbol_table), str)) != NULL) {
			ZVAL_DEREF(gv);
			if (Z_TYPE_P(gv) == IS_ARRAY) {
				if (Z_REFCOUNTED_P(gv) && Z_REFCOUNT_P(gv) <= 1) {
					ZVAL_COPY_VALUE(arr, gv);
				} else {
					ZVAL_DUP(arr, gv);
					zend_hash_update(&EG(symbol_table), str, arr);
				}

				zend_string_release(str);
				return SUCCESS;
			}
		}
	}

	array_init(arr);
	if (!(&EG(symbol_table))) {
		symbol_table = zend_rebuild_symbol_table();
	} else {
		symbol_table = &EG(symbol_table);
	}

	zend_hash_update(symbol_table, str, arr);
	zend_string_release(str);

	return FAILURE;
}

/**
 * Makes fast count on implicit array types
 */
void zephir_fast_count(zval *result, zval *value)
{
	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZVAL_LONG(result, zend_hash_num_elements(Z_ARRVAL_P(value)));
		return;
	}

	if (Z_TYPE_P(value) == IS_OBJECT) {

		zval retval;

		if (Z_OBJ_HT_P(value)->count_elements) {
			ZVAL_LONG(result, 1);
			if (SUCCESS == Z_OBJ_HT(*value)->count_elements(value, &Z_LVAL_P(result))) {
				return;
			}
		}

		if (instanceof_function(Z_OBJCE_P(value), spl_ce_Countable)) {
			zend_call_method_with_0_params(value, NULL, NULL, "count", &retval);
			if (Z_TYPE(retval) != IS_UNDEF) {
				convert_to_long_ex(&retval);
				ZVAL_LONG(result, Z_LVAL(retval));
				zval_ptr_dtor(&retval);
			}
			return;
		}

		ZVAL_LONG(result, 0);
		return;
	}

	if (Z_TYPE_P(value) == IS_NULL) {
		ZVAL_LONG(result, 0);
		return;
	}

	ZVAL_LONG(result, 1);
}

/**
 * Makes fast count on implicit array types without creating a return zval value
 */
int zephir_fast_count_ev(zval *value)
{
	zend_long count = 0;

	if (Z_TYPE_P(value) == IS_ARRAY) {
		return zend_hash_num_elements(Z_ARRVAL_P(value)) > 0;
	}

	if (Z_TYPE_P(value) == IS_OBJECT) {

		zval retval;

		if (Z_OBJ_HT_P(value)->count_elements) {
			Z_OBJ_HT(*value)->count_elements(value, &count);
			return (int) count > 0;
		}

		if (instanceof_function(Z_OBJCE_P(value), spl_ce_Countable)) {
			zend_call_method_with_0_params(value, NULL, NULL, "count", &retval);
			if (Z_TYPE(retval) != IS_UNDEF) {
				convert_to_long_ex(&retval);
				count = Z_LVAL(retval);
				zval_ptr_dtor(&retval);
				return (int) count > 0;
			}
			return 0;
		}

		return 0;
	}

	if (Z_TYPE_P(value) == IS_NULL) {
		return 0;
	}

	return 1;
}

/**
 * Makes fast count on implicit array types without creating a return zval value
 */
int zephir_fast_count_int(zval *value)
{
	zend_long count = 0;

	if (Z_TYPE_P(value) == IS_ARRAY) {
		return zend_hash_num_elements(Z_ARRVAL_P(value));
	}

	if (Z_TYPE_P(value) == IS_OBJECT) {

		zval retval;

		if (Z_OBJ_HT_P(value)->count_elements) {
			Z_OBJ_HT(*value)->count_elements(value, &count);
			return (int) count;
		}

		if (instanceof_function(Z_OBJCE_P(value), spl_ce_Countable)) {
			zend_call_method_with_0_params(value, NULL, NULL, "count", &retval);
			if (Z_TYPE(retval) != IS_UNDEF) {
				convert_to_long_ex(&retval);
				count = Z_LVAL(retval);
				zval_ptr_dtor(&retval);
				return (int) count;
			}
			return 0;
		}

		return 0;
	}

	if (Z_TYPE_P(value) == IS_NULL) {
		return 0;
	}

	return 1;
}

/**
 * Check if a function exists using explicit function length
 *
 * TODO: Deprecated. Will be removed in future
 */
int zephir_function_quick_exists_ex(const char *function_name, size_t function_len)
{
	if (zend_hash_str_exists(CG(function_table), function_name, function_len)) {
		return SUCCESS;
	}

	return FAILURE;
}

/**
 * Check if a function exists
 *
 * @param function_name
 * @return
 */
int zephir_function_exists(const zval *function_name)
{
	if (zend_hash_str_exists(CG(function_table), Z_STRVAL_P(function_name), Z_STRLEN_P(function_name))) {
		return SUCCESS;
	}

	return FAILURE;
}

/**
 * Check if a function exists using explicit function length
 *
 * TODO: Deprecated. Will be removed in future
 * @param function_name
 * @param function_len strlen(function_name) + 1
 */
int zephir_function_exists_ex(const char *function_name, unsigned int function_len)
{
	return zephir_function_quick_exists_ex(function_name, function_len);
}

/**
 * Checks if a zval is callable
 */
int zephir_is_callable(zval *var)
{
	char *error = NULL;
	zend_bool retval;

	retval = zend_is_callable_ex(var, NULL, 0, NULL, NULL, &error);
	if (error) {
		efree(error);
	}

	return (int) retval;
}

/**
 * Checks whether a variable has a scalar type
 */
int zephir_is_scalar(zval *var)
{
	switch (Z_TYPE_P(var)) {
		case IS_TRUE:
		case IS_FALSE:
		case IS_DOUBLE:
		case IS_LONG:
		case IS_STRING:
			return 1;
			break;
	}

	return 0;
}

/**
 * Returns the type of a variable as a string
 */
void zephir_gettype(zval *return_value, zval *arg)
{
	switch (Z_TYPE_P(arg)) {

		case IS_NULL:
			RETVAL_STRING("NULL");
			break;

		case IS_TRUE:
		case IS_FALSE:
			RETVAL_STRING("boolean");
			break;

		case IS_LONG:
			RETVAL_STRING("integer");
			break;

		case IS_DOUBLE:
			RETVAL_STRING("double");
			break;

		case IS_STRING:
			RETVAL_STRING("string");
			break;

		case IS_ARRAY:
			RETVAL_STRING("array");
			break;

		case IS_OBJECT:
			RETVAL_STRING("object");
			break;

		case IS_RESOURCE:
			{
				const char *type_name = zend_rsrc_list_get_rsrc_type(Z_RES_P(arg));

				if (type_name) {
					RETVAL_STRING("resource");
					break;
				}
			}
			/* no break */

		default:
			RETVAL_STRING("unknown type");
	}
}

zend_class_entry* zephir_get_internal_ce(const char *class_name, unsigned int class_name_len)
{
    zend_class_entry* temp_ce;

    if ((temp_ce = zend_hash_str_find_ptr(CG(class_table), class_name, class_name_len)) == NULL) {
        zend_error(E_ERROR, "Class '%s' not found", class_name);
        return NULL;
    }

    return temp_ce;
}

/* Declare constants */
int zephir_declare_class_constant(zend_class_entry *ce, const char *name, size_t name_length, zval *value)
{
#if PHP_VERSION_ID >= 70200
	int ret;
	zend_string *key;

	if (ce->type == ZEND_INTERNAL_CLASS) {
		key = zend_string_init_interned(name, name_length, 1);
	} else {
		key = zend_string_init(name, name_length, 0);
	}

	ret = zend_declare_class_constant_ex(ce, key, value, ZEND_ACC_PUBLIC, NULL);

	if (ce->type != ZEND_INTERNAL_CLASS) {
		zend_string_release(key);
	}

	return ret;
#elif PHP_VERSION_ID >= 70100
	int ret;

	zend_string *key = zend_string_init(name, name_length, ce->type & ZEND_INTERNAL_CLASS);
	ret = zend_declare_class_constant_ex(ce, key, value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(key);
	return ret;
#else
	if (Z_CONSTANT_P(value)) {
		ce->ce_flags &= ~ZEND_ACC_CONSTANTS_UPDATED;
	}
	ZVAL_NEW_PERSISTENT_REF(value, value);
	return zend_hash_str_update(&ce->constants_table, name, name_length, value) ?
		SUCCESS : FAILURE;
#endif
}

int zephir_declare_class_constant_null(zend_class_entry *ce, const char *name, size_t name_length)
{
	zval constant;

	ZVAL_NULL(&constant);
	return zephir_declare_class_constant(ce, name, name_length, &constant);
}

int zephir_declare_class_constant_long(zend_class_entry *ce, const char *name, size_t name_length, zend_long value)
{
	zval constant;

	ZVAL_LONG(&constant, value);
	return zephir_declare_class_constant(ce, name, name_length, &constant);
}

int zephir_declare_class_constant_bool(zend_class_entry *ce, const char *name, size_t name_length, zend_bool value)
{
	zval constant;

	ZVAL_BOOL(&constant, value);
	return zephir_declare_class_constant(ce, name, name_length, &constant);
}

int zephir_declare_class_constant_double(zend_class_entry *ce, const char *name, size_t name_length, double value)
{
	zval constant;

	ZVAL_DOUBLE(&constant, value);
	return zephir_declare_class_constant(ce, name, name_length, &constant);
}

int zephir_declare_class_constant_stringl(zend_class_entry *ce, const char *name, size_t name_length, const char *value, size_t value_length)
{
	zval constant;

	ZVAL_NEW_STR(&constant, zend_string_init(value, value_length, ce->type & ZEND_INTERNAL_CLASS));
	return zephir_declare_class_constant(ce, name, name_length, &constant);
}

int zephir_declare_class_constant_string(zend_class_entry *ce, const char *name, size_t name_length, const char *value)
{
	return zephir_declare_class_constant_stringl(ce, name, name_length, value, strlen(value));
}

/**
 * Check is PHP Version equals to Runtime PHP Version
 */
int zephir_is_php_version(unsigned int id)
{
	int php_major = PHP_MAJOR_VERSION * 10000;
	int php_minor = PHP_MINOR_VERSION * 100;
	int php_release = PHP_RELEASE_VERSION;

	int zep_major = id / 10000;
	int zep_minor = id / 100 - zep_major * 100;
	int zep_release = id - (zep_major * 10000 + zep_minor * 100);

	if (zep_minor == 0)
	{
		php_minor = 0;
	}

	if (zep_release == 0)
	{
		php_release = 0;
	}

	return ((php_major + php_minor + php_release) == id ? 1 : 0);
}

void
zephir_get_args(zval *return_value)
{
	zend_execute_data *ex = EG(current_execute_data);
	uint32_t arg_count    = ZEND_CALL_NUM_ARGS(ex);

	array_init_size(return_value, arg_count);
	if (arg_count) {
		uint32_t first_extra_arg = ex->func->op_array.num_args;
		zval *p    = ZEND_CALL_ARG(ex, 1);
		uint32_t i = 0;

		if (arg_count > first_extra_arg) {
			while (i < first_extra_arg) {
				zval *q = p;

				if (Z_TYPE_P(q) != IS_UNDEF) {
					ZVAL_DEREF(q);
					Z_TRY_ADDREF_P(q);
					zend_hash_next_index_insert_new(Z_ARRVAL_P(return_value), q);
				}

				++p;
				++i;
			}

			p = ZEND_CALL_VAR_NUM(ex, i);
		}

		while (i < arg_count) {
			zval *q = p;

			if (Z_TYPE_P(q) != IS_UNDEF) {
				ZVAL_DEREF(q);
				Z_TRY_ADDREF_P(q);
				zend_hash_next_index_insert_new(Z_ARRVAL_P(return_value), q);
			}

			++p;
			++i;
		}
	}
}

void
zephir_get_arg(zval *return_value, zend_long idx)
{
	zend_execute_data *ex = EG(current_execute_data);
	uint32_t arg_count;
	zval *arg;

	if (UNEXPECTED(idx < 0)) {
		zend_error(E_WARNING, "func_get_arg():  The argument number should be >= 0");
		RETURN_FALSE;
	}

	arg_count = ZEND_CALL_NUM_ARGS(ex);
#if PHP_VERSION_ID >= 70100
	if (zend_forbid_dynamic_call("func_get_arg()") == FAILURE) {
		RETURN_FALSE;
	}
#endif

	if (UNEXPECTED((zend_ulong)idx >= arg_count)) {
		zend_error(E_WARNING, "func_get_arg():  Argument " ZEND_LONG_FMT " not passed to function", idx);
		RETURN_FALSE;
	}

	arg = ZEND_CALL_VAR_NUM(ex, idx);

	if (EXPECTED(!Z_ISUNDEF_P(arg))) {
		ZVAL_DEREF(arg);
		ZVAL_COPY(return_value, arg);
		return;
	}

	RETURN_NULL();
}

void zephir_module_init()
{
	/* Though these strings won't be interned in ZTS,
	 * we still benefit from using zend_string* instead of char*
	 * in hash tables
	 */
	i_parent = zend_new_interned_string(zend_string_init(ZEND_STRL("parent"), 1));
	i_static = zend_new_interned_string(zend_string_init(ZEND_STRL("static"), 1));
	i_self   = zend_new_interned_string(zend_string_init(ZEND_STRL("self"), 1));
}
