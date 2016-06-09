
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
  |          Eduar Carvajal <eduar@zephir-lang.com>                        |
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>
#include "php_ext.h"

#include <Zend/zend_closures.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/operators.h"

int zephir_instance_of_ev(const zval *object, const zend_class_entry *ce)
{
	if (Z_TYPE_P(object) != IS_OBJECT) {
		php_error_docref(NULL, E_WARNING, "instanceof expects an object instance");
		return 0;
	}

	return instanceof_function(Z_OBJCE_P(object), ce);
}

/**
 * Check if an object is instance of a class
 */
int zephir_is_instance_of(zval *object, const char *class_name, unsigned int class_length)
{
	zend_class_entry *ce, *temp_ce;

	if (Z_TYPE_P(object) == IS_OBJECT) {

		ce = Z_OBJCE_P(object);
		if (ZSTR_LEN(ce->name) == class_length) {
			if (!zend_binary_strcasecmp(ZSTR_VAL(ce->name), ZSTR_LEN(ce->name), class_name, class_length)) {
				return 1;
			}
		}

		temp_ce = zephir_fetch_class_str_ex(class_name, class_length, ZEND_FETCH_CLASS_DEFAULT);
		if (temp_ce) {
			return instanceof_function(ce, temp_ce);
		}
	}

	return 0;
}

int zephir_zval_is_traversable(zval *object)
{
	zend_class_entry *ce;
	zend_uint i;

	if (Z_TYPE_P(object) == IS_OBJECT) {
		ce = Z_OBJCE_P(object);

		if (ce->get_iterator || (ce->parent && ce->parent->get_iterator)) {
			return 1;
		}

		for (i = 0; i < ce->num_interfaces; i++) {
			if (ce->interfaces[i] == zend_ce_aggregate ||
				ce->interfaces[i] == zend_ce_iterator ||
				ce->interfaces[i] == zend_ce_traversable
			) {
				return 1;
			}
		}
	}

	return 0;
}

/**
 * Returns the called in class in the current scope
 */
void zephir_get_called_class(zval *return_value)
{
	if (EG(current_execute_data)->called_scope) {
		zend_string *ret = EG(current_execute_data)->called_scope->name;
		zend_string_addref(ret);
		RETURN_STR(ret);
	}

	if (!EG(scope))  {
		php_error_docref(NULL, E_WARNING, "zephir_get_called_class() called from outside a class");
	}
}

zend_class_entry *zephir_fetch_class_str_ex(const char *class_name, size_t length, int fetch_type)
{
	zend_class_entry *retval;
	zend_string *str = zend_string_init(class_name, length, 0);
	retval = zend_fetch_class(str, fetch_type);
	zend_string_release(str);
	return retval;
}

/**
 * Fetches a zend class entry from a zval value
 */
zend_class_entry *zephir_fetch_class(const zval *class_name)
{
	if (Z_TYPE_P(class_name) == IS_STRING) {
		return zend_fetch_class(Z_STR_P(class_name), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
	}

	php_error_docref(NULL, E_WARNING, "class name must be a string");
	return zephir_fetch_class_str_ex(SL("stdclass"), ZEND_FETCH_CLASS_DEFAULT);
}

/**
 * Returns a class name into a zval result
 */
void zephir_get_class(zval *result, zval *object, int lower)
{
	zend_class_entry *ce;
	zend_string *class_name;

	if (Z_TYPE_P(object) == IS_OBJECT) {

		ce = Z_OBJCE_P(object);
		//zval_ptr_dtor(result);
		class_name = zend_string_init(ZSTR_VAL(ce->name), ZSTR_LEN(ce->name), 0);
		ZVAL_STR(result, class_name);

		if (lower) {
			zend_str_tolower(Z_STRVAL_P(result), Z_STRLEN_P(result));
		}

	} else {
		ZVAL_NULL(result);
		php_error_docref(NULL, E_WARNING, "zephir_get_class expects an object");
	}
}

/**
 * Returns a class name into a zval result
 */
void zephir_get_class_ns(zval *result, zval *object, int lower)
{
	int found = 0;
	zend_class_entry *ce;
	unsigned int i, class_length;
	char *cursor, *class_name;

	if (Z_TYPE_P(object) != IS_OBJECT) {
		if (Z_TYPE_P(object) != IS_STRING) {
			ZVAL_NULL(result);
			php_error_docref(NULL, E_WARNING, "zephir_get_class_ns expects an object");
			return;
		}
	}

	if (Z_TYPE_P(object) == IS_OBJECT) {
		ce = Z_OBJCE_P(object);
		class_name = ZSTR_VAL(ce->name);
		class_length = ZSTR_LEN(ce->name);
	} else {
		class_name = Z_STRVAL_P(object);
		class_length = Z_STRLEN_P(object);
	}

	if (!class_length) {
		ZVAL_NULL(result);
		return;
	}

	i = class_length;
	cursor = (char *) (class_name + class_length - 1);

	while (i > 0) {
		if ((*cursor) == '\\') {
			found = 1;
			break;
		}
		cursor--;
		i--;
	}

	if (found) {
		int cursor_length = class_length - i;
		cursor = (char *) emalloc(cursor_length + 1);
		memcpy(cursor, class_name + i, cursor_length);
		cursor[cursor_length] = 0;
		ZVAL_STRING(result, cursor);
		efree(cursor);
	} else {
		ZVAL_STRINGL(result, class_name, class_length);
	}

	if (lower) {
		zend_str_tolower(Z_STRVAL_P(result), Z_STRLEN_P(result));
	}

}

/**
 * Returns a namespace from a class name
 */
void zephir_get_ns_class(zval *result, zval *object, int lower)
{
	zend_class_entry *ce;
	int found = 0;
	unsigned int i, j, class_length;
	char *cursor, *class_name;

	if (Z_TYPE_P(object) != IS_OBJECT) {
		if (Z_TYPE_P(object) != IS_STRING) {
			php_error_docref(NULL, E_WARNING, "zephir_get_ns_class expects an object");
			ZVAL_NULL(result);
			return;
		}
	}

	if (Z_TYPE_P(object) == IS_OBJECT) {
		ce = Z_OBJCE_P(object);
		class_name = ZSTR_VAL(ce->name);
		class_length = ZSTR_LEN(ce->name);
	} else {
		class_name = Z_STRVAL_P(object);
		class_length = Z_STRLEN_P(object);
	}

	if (!class_length) {
		ZVAL_NULL(result);
		return;
	}

	j = 0;
	i = class_length;
	cursor = (char *) (class_name + class_length - 1);

	while (i > 0) {
		if ((*cursor) == '\\') {
			found = 1;
			break;
		}
		cursor--;
		i--;
		j++;
	}

	if (j > 0) {

		if (found) {
			int cursor_length = class_length - j - 1;
			cursor = (char *) emalloc(cursor_length + 1);
			memcpy(cursor, class_name, cursor_length);
			cursor[cursor_length] = 0;
			ZVAL_STRING(result, cursor);
			efree(cursor);
		} else {
			ZVAL_EMPTY_STRING(result);
		}

		if (lower) {
			zend_str_tolower(Z_STRVAL_P(result), Z_STRLEN_P(result));
		}
	} else {
		ZVAL_NULL(result);
	}

}

/**
 * Checks if a class exist
 */
int zephir_class_exists(const zval *class_name, int autoload)
{
	zend_class_entry *ce;

	if (Z_TYPE_P(class_name) == IS_STRING) {
		if ((ce = zend_lookup_class(Z_STR_P(class_name))) != NULL) {
			return (ce->ce_flags & (ZEND_ACC_INTERFACE | (ZEND_ACC_TRAIT - ZEND_ACC_EXPLICIT_ABSTRACT_CLASS))) == 0;
		}
		return 0;
	}

	php_error_docref(NULL, E_WARNING, "class name must be a string");
	return 0;
}

/**
 * Checks if a interface exist
 */
int zephir_interface_exists(const zval *class_name, int autoload)
{
	zend_class_entry *ce;

	if (Z_TYPE_P(class_name) == IS_STRING) {
		if ((ce = zend_lookup_class(Z_STR_P(class_name))) != NULL) {
			return ((ce->ce_flags & ZEND_ACC_INTERFACE) > 0);
		}
		return 0;
	}

	php_error_docref(NULL TSRMLS_CC, E_WARNING, "interface name must be a string");
	return 0;
}

/**
 * Clones an object from obj to destination
 */
int zephir_clone(zval *destination, zval *obj)
{
	int status = SUCCESS;
	zend_class_entry *ce;
	zend_object_clone_obj_t clone_call;

	if (Z_TYPE_P(obj) != IS_OBJECT) {
		php_error_docref(NULL, E_ERROR, "__clone method called on non-object");
		status = FAILURE;
	} else {
		ce = Z_OBJCE_P(obj);
		clone_call =  Z_OBJ_HT_P(obj)->clone_obj;
		if (!clone_call) {
			if (ce) {
				php_error_docref(NULL, E_ERROR, "Trying to clone an uncloneable object of class %s", ce->name);
			} else {
				php_error_docref(NULL, E_ERROR, "Trying to clone an uncloneable object");
			}
			status = FAILURE;
		} else {
			if (!EG(exception)) {
				//zval_ptr_dtor(destination);
				ZVAL_OBJ(destination, clone_call(obj));
				if (EG(exception)) {
					zval_ptr_dtor(destination);
				}
			}
		}
	}

	return status;
}

/**
 * Checks if property exists on object
 */
int zephir_isset_property(zval *object, const char *property_name, unsigned int property_length)
{
	if (Z_TYPE_P(object) == IS_OBJECT) {
		if (likely(zend_hash_str_exists(&Z_OBJCE_P(object)->properties_info, property_name, property_length))) {
			return 1;
		}
		return zend_hash_str_exists(Z_OBJ_HT_P(object)->get_properties(object), property_name, property_length);
	}

	return 0;
}

/**
 * Checks if string property exists on object
 */
int zephir_isset_property_zval(zval *object, const zval *property)
{
	if (Z_TYPE_P(object) == IS_OBJECT) {
		if (Z_TYPE_P(property) == IS_STRING) {

			if (likely(zend_hash_str_exists(&Z_OBJCE_P(object)->properties_info, Z_STRVAL_P(property), Z_STRLEN_P(property)))) {
				return 1;
			} else {
				return zend_hash_str_exists(Z_OBJ_HT_P(object)->get_properties(object), Z_STRVAL_P(property), Z_STRLEN_P(property));
			}
		}
	}

	return 0;
}

static inline zend_class_entry *zephir_lookup_class_ce(zend_class_entry *ce, const char *property_name, unsigned int property_length)
{
	zend_class_entry *original_ce = ce;
	zend_property_info *info;

	while (ce) {
		if ((info = zend_hash_str_find_ptr(&ce->properties_info, property_name, property_length)) != NULL && (info->flags & ZEND_ACC_SHADOW) != ZEND_ACC_SHADOW)  {
			return ce;
		}
		ce = ce->parent;
	}
	return original_ce;
}


/**
 * Reads a property from an object
 */
int zephir_read_property(zval *result, zval *object, const char *property_name, zend_uint property_length, int flags)
{
	zval property;
	zend_class_entry *ce, *old_scope;
	zval tmp;
	zval *res;

	ZVAL_UNDEF(&tmp);

	if (Z_TYPE_P(object) != IS_OBJECT) {

		if ((flags & PH_NOISY) == PH_NOISY) {
			php_error_docref(NULL, E_NOTICE, "Trying to get property \"%s\" of non-object", property_name);
		}

		ZVAL_NULL(result);
		return FAILURE;
	}

	ce = Z_OBJCE_P(object);
	if (ce->parent) {
		ce = zephir_lookup_class_ce(ce, property_name, property_length);
	}

	old_scope = EG(scope);
	EG(scope) = ce;

	if (!Z_OBJ_HT_P(object)->read_property) {
		const char *class_name;

		class_name = Z_OBJ_P(object) ? ZSTR_VAL(Z_OBJCE_P(object)->name) : "";
		zend_error(E_CORE_ERROR, "Property %s of class %s cannot be read", property_name, class_name);
	}

	ZVAL_STRINGL(&property, property_name, property_length);

	res = Z_OBJ_HT_P(object)->read_property(object, &property, flags ? BP_VAR_IS : BP_VAR_R, NULL, &tmp);
	if ((flags & PH_READONLY) == PH_READONLY) {
		ZVAL_COPY_VALUE(result, res);
	} else {
		ZVAL_COPY(result, res);
	}

	zval_ptr_dtor(&property);

	EG(scope) = old_scope;
	return SUCCESS;
}

/**
 * Fetches a property using a const char
 */
int zephir_fetch_property(zval *result, zval *object, const char *property_name, zend_uint property_length, int silent)
{
	if (zephir_isset_property(object, property_name, property_length)) {
		zephir_read_property(result, object, property_name, property_length, 0);
		return 1;
	}

	//zval_ptr_dtor(result);
	ZVAL_NULL(result);
	return 0;
}

/**
 * Fetches a property using a zval property
 */
int zephir_fetch_property_zval(zval *result, zval *object, zval *property, int silent)
{
	if (unlikely(Z_TYPE_P(property) != IS_STRING)) {
		ZVAL_NULL(result);
		return 0;
	}

	if (zephir_isset_property(object, Z_STRVAL_P(property), Z_STRLEN_P(property))) {
		zephir_read_property(result, object, Z_STRVAL_P(property), Z_STRLEN_P(property), 0);
		return 1;
	}

	ZVAL_NULL(result);
	return 0;
}

int zephir_return_property(zval *return_value, zval *object, char *property_name, unsigned int property_length)
{
	ZVAL_NULL(return_value);
	zephir_read_property(return_value, object, property_name, property_length, 0);
	return SUCCESS;
}

/**
 * Reads a property from an object
 */
int zephir_read_property_zval(zval *result, zval *object, zval *property, int flags)
{
	if (unlikely(Z_TYPE_P(property) != IS_STRING)) {
		if ((flags & PH_NOISY) == PH_NOISY) {
			php_error_docref(NULL, E_NOTICE, "Cannot access empty property %d", Z_TYPE_P(property));
		}

		ZVAL_NULL(result);
		return FAILURE;
	}

	return zephir_read_property(result, object, Z_STRVAL_P(property), Z_STRLEN_P(property), flags);
}

/**
 * Checks whether obj is an object and updates property with another zval
 */
int zephir_update_property_zval(zval *object, const char *property_name, unsigned int property_length, zval *value)
{
	zend_class_entry *ce, *old_scope;
	zval property;

	old_scope = EG(scope);
	if (Z_TYPE_P(object) != IS_OBJECT) {
		php_error_docref(NULL, E_WARNING, "Attempt to assign property of non-object");
		return FAILURE;
	}

	ce = Z_OBJCE_P(object);
	if (ce->parent) {
		ce = zephir_lookup_class_ce(ce, property_name, property_length);
	}

	EG(scope) = ce;

	if (!Z_OBJ_HT_P(object)->write_property) {
		const char *class_name;

		class_name = Z_OBJ_P(object) ? ZSTR_VAL(Z_OBJCE_P(object)->name) : "";
		zend_error(E_CORE_ERROR, "Property %s of class %s cannot be updated", property_name, class_name);
	}

	ZVAL_STRINGL(&property, property_name, property_length);

	/* write_property will add 1 to refcount, so no Z_TRY_ADDREF_P(value); is necessary */
	Z_OBJ_HT_P(object)->write_property(object, &property, value, 0);
	zval_ptr_dtor(&property);

	EG(scope) = old_scope;
	return SUCCESS;
}

/**
 * Checks whether obj is an object and updates zval property with another zval
 */
int zephir_update_property_zval_zval(zval *object, zval *property, zval *value)
{
	if (Z_TYPE_P(property) != IS_STRING) {
		php_error_docref(NULL, E_WARNING, "Property should be string");
		return FAILURE;
	}

	return zephir_update_property_zval(object, Z_STRVAL_P(property), Z_STRLEN_P(property), value);
}

/**
 * Updates an array property
 */
int zephir_update_property_array(zval *object, const char *property, zend_uint property_length, const zval *index, zval *value)
{
	zval tmp;
	int separated = 0;

	if (Z_TYPE_P(object) == IS_OBJECT) {
		zephir_read_property(&tmp, object, property, property_length, PH_NOISY | PH_READONLY);

		/** Separation only when refcount > 1 */
		if (Z_REFCOUNTED(tmp)) {
			if (Z_REFCOUNT(tmp) > 1) {
				if (!Z_ISREF(tmp)) {
					zval new_zv;
					ZVAL_DUP(&new_zv, &tmp);
					ZVAL_COPY_VALUE(&tmp, &new_zv);
					Z_TRY_DELREF(new_zv);
					separated = 1;
				}
			}
		} else {
			separated = 1;
		}

		/** Convert the value to array if not is an array */
		if (Z_TYPE(tmp) != IS_ARRAY) {
			if (separated) {
				convert_to_array(&tmp);
			} else {
				array_init(&tmp);
				separated = 1;
			}
			Z_DELREF(tmp);
		}
		Z_TRY_ADDREF_P(value);

		if (Z_TYPE_P(index) == IS_STRING) {
			zend_symtable_str_update(Z_ARRVAL(tmp), Z_STRVAL_P(index), Z_STRLEN_P(index), value);
		} else if (Z_TYPE_P(index) == IS_LONG) {
			zend_hash_index_update(Z_ARRVAL(tmp), Z_LVAL_P(index), value);
		} else if (Z_TYPE_P(index) == IS_NULL) {
			zend_hash_next_index_insert(Z_ARRVAL(tmp), value);
		}

		if (separated) {
			zephir_update_property_zval(object, property, property_length, &tmp);
		}
	}

	return SUCCESS;
}


/**
 * Appends a zval value to an array property
 */
int zephir_update_property_array_append(zval *object, char *property, unsigned int property_length, zval *value)
{
	zval tmp;
	int separated = 0;

	ZVAL_UNDEF(&tmp);

	if (Z_TYPE_P(object) != IS_OBJECT) {
		return SUCCESS;
	}

	zephir_read_property(&tmp, object, property, property_length, PH_NOISY_CC);

	Z_TRY_DELREF(tmp);

	/** Separation only when refcount > 1 */
	if (Z_REFCOUNTED(tmp)) {
		if (Z_REFCOUNT(tmp) > 1) {
			if (!Z_ISREF(tmp)) {
				zval new_zv;
				ZVAL_DUP(&new_zv, &tmp);
				ZVAL_COPY_VALUE(&tmp, &new_zv);
				Z_TRY_DELREF(new_zv);
				separated = 1;
			}
		}
	} else {
		separated = 1;
	}

	/** Convert the value to array if not is an array */
	if (Z_TYPE(tmp) != IS_ARRAY) {
		if (separated) {
			convert_to_array(&tmp);
		} else {
			array_init(&tmp);
			separated = 1;
		}
		Z_DELREF(tmp);
	}

	Z_TRY_ADDREF_P(value);
	add_next_index_zval(&tmp, value);

	if (separated) {
		zephir_update_property_zval(object, property, property_length, &tmp);
	}

	return SUCCESS;
}

/**
 * Multiple array-offset update
 */
int zephir_update_property_array_multi(zval *object, const char *property, zend_uint property_length, zval *value, const char *types, int types_length, int types_count, ...)
{
	va_list ap;
	zval tmp_arr;
	int separated = 0;

	if (Z_TYPE_P(object) == IS_OBJECT) {
		zephir_read_property(&tmp_arr, object, property, property_length, PH_NOISY | PH_READONLY);

		/** Separation only when refcount > 1 */
		if (Z_REFCOUNTED(tmp_arr)) {
			if (Z_REFCOUNT(tmp_arr) > 1) {
				if (!Z_ISREF(tmp_arr)) {
					zval new_zv;
					ZVAL_DUP(&new_zv, &tmp_arr);
					ZVAL_COPY_VALUE(&tmp_arr, &new_zv);
					Z_TRY_DELREF(new_zv);
					separated = 1;
				}
			}
		} else {
			separated = 1;
		}

		/** Convert the value to array if not is an array */
		if (Z_TYPE(tmp_arr) != IS_ARRAY) {
			if (separated) {
				convert_to_array(&tmp_arr);
			} else {
				array_init(&tmp_arr);
				separated = 1;
			}
			Z_DELREF(tmp_arr);
		}

		va_start(ap, types_count);
		zephir_array_update_multi_ex(&tmp_arr, value, types, types_length, types_count, ap);
		va_end(ap);

		if (separated) {
			zephir_update_property_zval(object, property, property_length, &tmp_arr);
		}
	}

	return SUCCESS;
}

int zephir_unset_property(zval* object, const char* name)
{
	if (Z_TYPE_P(object) == IS_OBJECT) {
		zval member;
		zend_class_entry *old_scope;

		ZVAL_STRING(&member, name);
		old_scope = EG(scope);
		EG(scope) = Z_OBJCE_P(object);

		Z_OBJ_HT_P(object)->unset_property(object, &member, 0);

		EG(scope) = old_scope;

		return SUCCESS;
	}

	return FAILURE;
}

/**
 * Unsets an index in an array property
 */
int zephir_unset_property_array(zval *object, char *property, unsigned int property_length, zval *index)
{
	zval tmp;
	int separated = 0;

	if (Z_TYPE_P(object) == IS_OBJECT) {

		zephir_read_property(&tmp, object, property, property_length, PH_NOISY_CC);
		Z_TRY_DELREF(tmp);

		/** Separation only when refcount > 1 */
		if (Z_REFCOUNTED(tmp) && Z_REFCOUNT(tmp) > 1) {
			if (!Z_ISREF(tmp)) {
				zval new_zv;
				ZVAL_DUP(&new_zv, &tmp);
				ZVAL_COPY_VALUE(&tmp, &new_zv);
				Z_TRY_DELREF(new_zv);
				separated = 1;
			}
		}

		zephir_array_unset(&tmp, index, PH_SEPARATE);

		if (separated) {
			zephir_update_property_zval(object, property, property_length, &tmp);
		}
	}

	return SUCCESS;
}

int zephir_method_exists_ex(const zval *object, const char *method_name, unsigned int method_len)
{
	zend_class_entry *ce;

	if (likely(Z_TYPE_P(object) == IS_OBJECT)) {
		ce = Z_OBJCE_P(object);
	} else {
		if (Z_TYPE_P(object) == IS_STRING) {
			ce = zend_fetch_class(Z_STR_P(object), ZEND_FETCH_CLASS_DEFAULT);
		} else {
			return FAILURE;
		}
	}

	while (ce) {
		if (zend_hash_str_exists(&ce->function_table, method_name, method_len)) {
			return SUCCESS;
		}
		ce = ce->parent;
	}

	return FAILURE;
}

int zephir_method_exists(const zval *object, const zval *method_name)
{
	if (Z_TYPE_P(method_name) != IS_STRING) {
		zend_error(E_WARNING, "method_exists expected a string");
		return 0;
	}
	char *lcname = zend_str_tolower_dup(Z_STRVAL_P(method_name), Z_STRLEN_P(method_name));
	int res = zephir_method_exists_ex(object, lcname, Z_STRLEN_P(method_name));
	efree(lcname);
	return res;
}

int zephir_read_static_property_ce(zval *result, zend_class_entry *ce, const char *property, int len, int flags)
{
	zval *tmp = zend_read_static_property(ce, property, len, (zend_bool) ZEND_FETCH_CLASS_SILENT);

	//zval_ptr_dtor(result);
	ZVAL_NULL(result);
	if (tmp)
	{
		if ((flags & PH_READONLY) == PH_READONLY) {
			ZVAL_COPY_VALUE(result, tmp);
		} else {
			ZVAL_COPY(result, tmp);
		}
		return SUCCESS;
	}
	return FAILURE;
}

static zval *zephir_std_get_static_property(zend_class_entry *ce, const char *property_name, int property_name_len, zend_bool silent, zend_property_info **param_property_info)
{
	zend_property_info *property_info;
	zval *ret;

	if (param_property_info == NULL)
	{
		property_info = zend_hash_str_find_ptr(&ce->properties_info, property_name, property_name_len);
		if (UNEXPECTED(property_info == NULL)) {
			goto undeclared_property;
		}

		/*if (UNEXPECTED(!zend_verify_property_access(property_info, ce))) {
			if (!silent) {
				zend_throw_error(NULL, "Cannot access %s property %s::$%s", zend_visibility_string(property_info->flags), ZSTR_VAL(ce->name), property_name);
			}
			return NULL;
		}*/

		if (UNEXPECTED((property_info->flags & ZEND_ACC_STATIC) == 0)) {
			goto undeclared_property;
		}

		if (UNEXPECTED(!(ce->ce_flags & ZEND_ACC_CONSTANTS_UPDATED))) {
			if (UNEXPECTED(zend_update_class_constants(ce)) != SUCCESS) {
				return NULL;
			}
		}
		ret = CE_STATIC_MEMBERS(ce) + property_info->offset;

		if (param_property_info) {
			*param_property_info = property_info;
		}
	} else {
		property_info = *param_property_info;
	}

	/* check if static properties were destoyed */
	if (UNEXPECTED(CE_STATIC_MEMBERS(ce) == NULL)) {
undeclared_property:
		if (!silent) {
			zend_throw_error(NULL, "Access to undeclared static property: %s::$%s", ZSTR_VAL(ce->name), property_name);
		}
		ret = NULL;
	}

	return ret;
}

static int zephir_update_static_property_ex(zend_class_entry *scope, const char *name, int name_length, zval *value, zend_property_info **property_info)
{
	zval garbage;
	zval *property;
	zend_class_entry *old_scope = EG(scope);

	EG(scope) = scope;
	property = zephir_std_get_static_property(scope, name, name_length, 0, property_info);
	EG(scope) = old_scope;

	if (!property) {
		return FAILURE;
	} else {
		ZVAL_COPY_VALUE(&garbage, property);
		if (Z_ISREF_P(value)) {
			SEPARATE_ZVAL(value);
		}
		ZVAL_COPY(property, value);
		zval_ptr_dtor(&garbage);
		return SUCCESS;
	}
}

int zephir_update_static_property_ce(zend_class_entry *ce, const char *name, int len, zval *value)
{
	assert(ce != NULL);
	return zephir_update_static_property_ex(ce, name, len, value, NULL);
}

/*
 * Multiple array-offset update
 */
int zephir_update_static_property_array_multi_ce(zend_class_entry *ce, const char *property, zend_uint property_length, zval *value, const char *types, int types_length, int types_count, ...)
{
	va_list ap;
	zval tmp_arr;
	int separated = 0;

	ZVAL_UNDEF(&tmp_arr);

	zephir_read_static_property_ce(&tmp_arr, ce, property, property_length, PH_NOISY | PH_READONLY);

	/** Separation only when refcount > 1 */
	if (Z_REFCOUNTED(tmp_arr)) {
		if (Z_REFCOUNT(tmp_arr) > 1) {
			if (!Z_ISREF(tmp_arr)) {
				zval new_zv;
				ZVAL_DUP(&new_zv, &tmp_arr);
				ZVAL_COPY_VALUE(&tmp_arr, &new_zv);
				Z_TRY_DELREF(new_zv);
				separated = 1;
			}
		}
	} else {
		separated = 1;
	}

	/** Convert the value to array if not is an array */
	if (Z_TYPE(tmp_arr) != IS_ARRAY) {
		if (separated) {
			convert_to_array(&tmp_arr);
		} else {
			array_init(&tmp_arr);
			separated = 1;
		}
		Z_DELREF(tmp_arr);
	}

	va_start(ap, types_count);
	SEPARATE_ZVAL_IF_NOT_REF(&tmp_arr);
	zephir_array_update_multi_ex(&tmp_arr, value, types, types_length, types_count, ap);
	va_end(ap);

	if (separated) {
		zephir_update_static_property_ce(ce, property, property_length, &tmp_arr);
	}

	return SUCCESS;
}

/**
 * Increments an object property
 */
int zephir_property_incr_decr(zval *object, char *property_name, unsigned int property_length, unsigned int increment)
{
	zval tmp;
	zend_class_entry *ce;
	int separated = 0;

	ZVAL_UNDEF(&tmp);

	if (Z_TYPE_P(object) != IS_OBJECT) {
		php_error_docref(NULL, E_WARNING, "Attempt to assign property of non-object");
		return FAILURE;
	}

	ce = Z_OBJCE_P(object);
	if (ce->parent) {
		ce = zephir_lookup_class_ce(ce, property_name, property_length);
	}

	zephir_read_property(&tmp, object, property_name, property_length, 0);
	if (Z_TYPE(tmp) > IS_UNDEF) {

		Z_TRY_DELREF(tmp);

		/** Separation only when refcount > 1 */
		if (Z_REFCOUNTED(tmp)) {
			if (Z_REFCOUNT(tmp) > 1) {
				if (!Z_ISREF(tmp)) {
					zval new_zv;
					ZVAL_DUP(&new_zv, &tmp);
					ZVAL_COPY_VALUE(&tmp, &new_zv);
					Z_TRY_DELREF(new_zv);
					separated = 1;
				}
			}
		} else {
			separated = 1;
		}

		if (increment) {
			zephir_increment(&tmp);
		} else {
			zephir_decrement(&tmp);
		}

		if (separated) {
			zephir_update_property_zval(object, property_name, property_length, &tmp);
		}
	}

	return SUCCESS;
}

/* Imported since PHP is so nice to define this in a .c file... */
typedef struct _zend_closure {
	zend_object       std;
	zend_function     func;
	zval              this_ptr;
	zend_class_entry *called_scope;
	void (*orig_internal_handler)(INTERNAL_FUNCTION_PARAMETERS);
} zend_closure;

/**
 * Creates a closure
 */
int zephir_create_closure_ex(zval *return_value, zval *this_ptr, zend_class_entry *ce, const char *method_name, zend_uint method_length)
{
	zend_function *function_ptr;
	zend_closure *closure;

	if ((function_ptr = zend_hash_str_find_ptr(&ce->function_table, method_name, method_length)) == NULL) {
		ZVAL_NULL(return_value);
		return FAILURE;
	}

	zend_create_closure(return_value, function_ptr, ce, ce, this_ptr);
	// Make sure we can use a closure multiple times
	closure = (zend_closure*)Z_OBJ_P(return_value);
	closure->func.internal_function.handler = closure->orig_internal_handler;
	return SUCCESS;
}

/**
 * Creates a new instance dynamically. Call constructor without parameters
 */
int zephir_create_instance(zval *return_value, const zval *class_name)
{
	zend_class_entry *ce;

	if (Z_TYPE_P(class_name) != IS_STRING) {
		zephir_throw_exception_string(spl_ce_RuntimeException, SL("Invalid class name"));
		return FAILURE;
	}

	ce = zend_fetch_class(Z_STR_P(class_name), ZEND_FETCH_CLASS_DEFAULT);
	if (!ce) {
		ZVAL_NULL(return_value);
		return FAILURE;
	}

	object_init_ex(return_value, ce);
	if (zephir_has_constructor_ce(ce)) {
		return zephir_call_class_method_aparams(NULL, ce, zephir_fcall_method, return_value, SL("__construct"), NULL, 0, 0, NULL);
	}

	return SUCCESS;
}

/**
 * Creates a new instance dynamically calling constructor with parameters
 */
int zephir_create_instance_params(zval *return_value, const zval *class_name, const zval *params TSRMLS_DC)
{
	int outcome;
	zend_class_entry *ce;

	if (Z_TYPE_P(class_name) != IS_STRING) {
		zephir_throw_exception_string(spl_ce_RuntimeException, SL("Invalid class name") TSRMLS_CC);
		return FAILURE;
	}

	if (Z_TYPE_P(params) != IS_ARRAY) {
		zephir_throw_exception_string(spl_ce_RuntimeException, SL("Instantiation parameters must be an array") TSRMLS_CC);
		return FAILURE;
	}

	ce = zend_fetch_class(Z_STR_P(class_name), ZEND_FETCH_CLASS_AUTO);
	if (!ce) {
		ZVAL_NULL(return_value);
		return FAILURE;
	}

	object_init_ex(return_value, ce);
	outcome = SUCCESS;

	if (zephir_has_constructor_ce(ce)) {

		int param_count = zend_hash_num_elements(Z_ARRVAL_P(params));
		zval *static_params[10];
		zval **params_ptr, **params_arr = NULL;

		if (param_count > 0) {
			zval *item;
			int i = 0;

			if (likely(param_count) <= 10) {
				params_ptr = static_params;
			} else {
				params_arr = emalloc(param_count * sizeof(zval*));
				params_ptr = params_arr;
			}

			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(params), item) {
				params_ptr[i++] = item;
			} ZEND_HASH_FOREACH_END();

		} else {
			params_ptr = NULL;
		}

		outcome = zephir_call_class_method_aparams(NULL, ce, zephir_fcall_method, return_value, SL("__construct"), NULL, 0, param_count, params_ptr);

		if (unlikely(params_arr != NULL)) {
			efree(params_arr);
		}
	}

	return outcome;
}
