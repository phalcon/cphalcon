/**
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
#include "php_ext.h"

#include <Zend/zend_closures.h>
#include <Zend/zend_string.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"

int zephir_instance_of_ev(zval *object, const zend_class_entry *ce)
{
	zval *z = Z_ISREF_P(object) ? Z_REFVAL_P(object) : object;
	if (Z_TYPE_P(z) != IS_OBJECT) {
		php_error_docref(NULL, E_WARNING, "instanceof expects an object instance");
		return 0;
	}

	return instanceof_function(Z_OBJCE_P(z), ce);
}

/**
 * Check if an object is instance of a class
 */
int zephir_is_instance_of(zval *object, const char *class_name, unsigned int class_length)
{
	zend_class_entry *ce, *temp_ce;
	zval *z = Z_ISREF_P(object) ? Z_REFVAL_P(object) : object;

	if (Z_TYPE_P(z) == IS_OBJECT) {

		ce = Z_OBJCE_P(z);
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
	uint32_t i;
	zval *z = Z_ISREF_P(object) ? Z_REFVAL_P(object) : object;

	if (Z_TYPE_P(z) == IS_OBJECT) {
		ce = Z_OBJCE_P(z);

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
	zend_class_entry *called_scope = zend_get_called_scope(EG(current_execute_data));
	if (called_scope) {
		ZVAL_STR(return_value, zend_string_dup(called_scope->name, 0));
	}

	if (!zend_get_executed_scope())  {
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
zend_class_entry *zephir_fetch_class(zval *class_name)
{
	zval *z = Z_ISREF_P(class_name) ? Z_REFVAL_P(class_name) : class_name;
	if (Z_TYPE_P(z) == IS_STRING) {
		return zend_fetch_class(Z_STR_P(z), ZEND_FETCH_CLASS_DEFAULT);
	}

	php_error_docref(NULL, E_WARNING, "class name must be a string");
	return zend_standard_class_def;
}

/**
 * Returns a class name into a zval result
 */
void zephir_get_class(zval *result, zval *object, int lower)
{
	zend_class_entry *ce;
	zend_string *class_name;
	zval *z = Z_ISREF_P(object) ? Z_REFVAL_P(object) : object;

	if (Z_TYPE_P(z) == IS_OBJECT) {
		ce = Z_OBJCE_P(z);
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
	unsigned int i, class_length;
	char *cursor, *class_name;
	zval *z = Z_ISREF_P(object) ? Z_REFVAL_P(object) : object;

	if (Z_TYPE_P(z) != IS_OBJECT) {
		if (Z_TYPE_P(z) != IS_STRING) {
			ZVAL_NULL(result);
			php_error_docref(NULL, E_WARNING, "zephir_get_class_ns expects an object");
			return;
		}

		class_name   = Z_STRVAL_P(z);
		class_length = Z_STRLEN_P(z);
	}
	else {
		zend_class_entry *ce = Z_OBJCE_P(z);
		class_name   = ZSTR_VAL(ce->name);
		class_length = ZSTR_LEN(ce->name);
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
	int found = 0;
	unsigned int i, j, class_length;
	char *cursor, *class_name;
	zval *z = Z_ISREF_P(object) ? Z_REFVAL_P(object) : object;

	ZVAL_NULL(result);

	if (Z_TYPE_P(z) != IS_OBJECT) {
		if (Z_TYPE_P(z) != IS_STRING) {
			php_error_docref(NULL, E_WARNING, "zephir_get_ns_class expects an object");
			return;
		}

		class_name   = Z_STRVAL_P(z);
		class_length = Z_STRLEN_P(z);
	}
	else {
		zend_class_entry *ce = Z_OBJCE_P(z);
		class_name   = ZSTR_VAL(ce->name);
		class_length = ZSTR_LEN(ce->name);
	}

	if (!class_length) {
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
	}
}

/**
 * Checks if a class exist
 */
int zephir_class_exists(zval *class_name, int autoload)
{
	zend_class_entry *ce;
	zval *z = Z_ISREF_P(class_name) ? Z_REFVAL_P(class_name) : class_name;

	if (Z_TYPE_P(z) == IS_STRING) {
		if ((ce = zend_lookup_class_ex(Z_STR_P(z), NULL, autoload)) != NULL) {
			return (ce->ce_flags & (ZEND_ACC_INTERFACE | (ZEND_ACC_INTERFACE | ZEND_ACC_TRAIT))) == 0;
		}
		return 0;
	}

	php_error_docref(NULL, E_WARNING, "class name must be a string");
	return 0;
}

/**
 * Checks if a interface exist
 */
int zephir_interface_exists(zval *class_name, int autoload)
{
	zend_class_entry *ce;
	zval *z = Z_ISREF_P(class_name) ? Z_REFVAL_P(class_name) : class_name;

	if (Z_TYPE_P(z) == IS_STRING) {
		if ((ce = zend_lookup_class(Z_STR_P(z))) != NULL) {
			return ((ce->ce_flags & ZEND_ACC_INTERFACE) > 0);
		}
		return 0;
	}

	php_error_docref(NULL, E_WARNING, "interface name must be a string");
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
				php_error_docref(NULL, E_ERROR, "Trying to clone an uncloneable object of class %s", ZSTR_VAL(ce->name));
			} else {
				php_error_docref(NULL, E_ERROR, "Trying to clone an uncloneable object");
			}
			status = FAILURE;
		} else {
			if (!EG(exception)) {
#if PHP_VERSION_ID >= 80000
				ZVAL_OBJ(destination, clone_call(Z_OBJ_P(obj)));
#else
				ZVAL_OBJ(destination, clone_call(obj));
#endif
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
		if (EXPECTED(zend_hash_str_exists(&Z_OBJCE_P(object)->properties_info, property_name, property_length))) {
			return 1;
		}

#if PHP_VERSION_ID >= 80000
		return zend_hash_str_exists(
			Z_OBJ_HT_P(object)->get_properties(Z_OBJ_P(object)),
			property_name,
			property_length
		);
#else
		return zend_hash_str_exists(
			Z_OBJ_HT_P(object)->get_properties(object),
			property_name,
			property_length
		);
#endif
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
			if (EXPECTED(zend_hash_str_exists(&Z_OBJCE_P(object)->properties_info, Z_STRVAL_P(property), Z_STRLEN_P(property)))) {
				return 1;
			} else {
#if PHP_VERSION_ID >= 80000
				return zend_hash_str_exists(
					Z_OBJ_HT_P(object)->get_properties(Z_OBJ_P(object)),
					Z_STRVAL_P(property),
					Z_STRLEN_P(property)
				);
#else
				return zend_hash_str_exists(
					Z_OBJ_HT_P(object)->get_properties(object),
					Z_STRVAL_P(property),
					Z_STRLEN_P(property)
				);
#endif
			}
		}
	}

	return 0;
}

/**
 * Lookup for the real owner of the property
 */
static inline zend_class_entry *zephir_lookup_class_ce(
	zend_class_entry *ce,
	const char *property_name,
	unsigned int property_length
) {
	zend_class_entry *original_ce = ce;
	zend_property_info *info;
	zend_class_entry *scope;
	zval member;

	ZVAL_STRINGL(&member, property_name, property_length);

	/* Backup current scope */
	scope = zephir_get_scope(0);

	while (ce) {
		/* Use the scope of the current object */
		zephir_set_scope(ce);

		info = zend_get_property_info(ce, Z_STR(member), 1);
		if (info && info != ZEND_WRONG_PROPERTY_INFO) {
			zval_ptr_dtor(&member);
			/* Restore original scope */
			zephir_set_scope(scope);

			return ce;
		}

		ce = ce->parent;
	}

	zval_ptr_dtor(&member);

	/* Restore original scope */
	zephir_set_scope(scope);

	return original_ce;
}

/**
 * Checks whether obj is an object and reads a property from this object.
 *
 * This function is intended to use in initializer.  Do not use it for a
 * regular property updating.
 */
int zephir_read_property_ex(
	zval *result,
	zval *object,
	const char *property_name,
	uint32_t property_length, int flags
) {
	zend_class_entry *scope;
	int retval;

	if (Z_TYPE_P(object) == IS_OBJECT) {
		zend_class_entry *ce;

		/* Backup current scope */
		scope = zephir_get_scope(0);
		ce = Z_OBJCE_P(object);

		/* Lookup for the real owner of the property */
		if (ce->parent) {
			ce = zephir_lookup_class_ce(ce, property_name, property_length);
		}

		/* Use the scope of the found object */
		zephir_set_scope(ce);
	}
	/* Read the property */
	retval = zephir_read_property(result, object, property_name, property_length, flags);

	if (Z_TYPE_P(object) == IS_OBJECT) {
		/* Restore original scope */
		zephir_set_scope(scope);
	}

	return retval;
}

/**
 * Checks whether obj is an object and reads a property from this object
 */
int zephir_read_property(
	zval *result,
	zval *object,
	const char *property_name,
	uint32_t property_length,
	int flags
) {
	zval property, tmp;
	zval *res;

	ZVAL_UNDEF(&tmp);

	if (Z_TYPE_P(object) != IS_OBJECT) {
		if ((flags & PH_NOISY) == PH_NOISY) {
			php_error_docref(NULL, E_NOTICE, "Trying to get property '%s' of non-object", property_name);
		}

		ZVAL_NULL(result);
		return FAILURE;
	}

	if (!Z_OBJ_HT_P(object)->read_property) {
		zend_error(E_CORE_ERROR, "Property %s of class %s cannot be read", property_name, ZSTR_VAL(Z_OBJCE_P(object)->name));
	}

	ZVAL_STRINGL(&property, property_name, property_length);
#if PHP_VERSION_ID >= 80000
	res = Z_OBJ_HT_P(object)->read_property(Z_OBJ_P(object), Z_STR(property),
											flags ? BP_VAR_IS : BP_VAR_R,
											NULL, &tmp);
#else
	res = Z_OBJ_HT_P(object)->read_property(object, &property,
											flags ? BP_VAR_IS : BP_VAR_R,
											NULL, &tmp);
#endif

	if ((flags & PH_READONLY) == PH_READONLY) {
		ZVAL_COPY_VALUE(result, res);
	} else {
		ZVAL_COPY(result, res);
	}

	zval_ptr_dtor(&property);

	return SUCCESS;
}

/**
 * Fetches a property using a const char
 */
int zephir_fetch_property(zval *result, zval *object, const char *property_name, uint32_t property_length, int silent)
{
	if (zephir_isset_property(object, property_name, property_length)) {
		zephir_read_property(result, object, property_name, property_length, 0);
		return 1;
	}

	ZVAL_NULL(result);
	return 0;
}

/**
 * Fetches a property using a zval property
 */
int zephir_fetch_property_zval(zval *result, zval *object, zval *property, int silent)
{
	if (UNEXPECTED(Z_TYPE_P(property) != IS_STRING)) {
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
	return zephir_read_property(return_value, object, property_name, property_length, 0);
}

/**
 * Reads a property from an object
 */
int zephir_read_property_zval(zval *result, zval *object, zval *property, int flags)
{
	if (UNEXPECTED(Z_TYPE_P(property) != IS_STRING)) {
		if ((flags & PH_NOISY) == PH_NOISY) {
			php_error_docref(NULL, E_NOTICE, "Cannot access empty property %d", Z_TYPE_P(property));
		}

		ZVAL_NULL(result);
		return FAILURE;
	}

	return zephir_read_property(result, object, Z_STRVAL_P(property), Z_STRLEN_P(property), flags);
}

/**
 * Checks whether obj is an object and updates property with another zval.
 *
 * This function is intended to use in initializer.  Do not use it for a
 * regular property updating.
 */
int zephir_update_property_zval_ex(
	zval *object,
	const char *property_name,
	unsigned int property_length,
	zval *value
) {
	zend_class_entry *scope;
	int retval;

	if (Z_TYPE_P(object) == IS_OBJECT) {
		zend_class_entry *ce;

		/* Backup current scope */
		scope = zephir_get_scope(0);
		ce = Z_OBJCE_P(object);

		/* Lookup for the real owner of the property */
		if (ce->parent) {
			ce = zephir_lookup_class_ce(ce, property_name, property_length);
		}

		/* Use the scope of the found object */
		zephir_set_scope(ce);
	}
	/* Update the property */
	retval = zephir_update_property_zval(object, property_name, property_length, value);

	if (Z_TYPE_P(object) == IS_OBJECT) {
		/* Restore original scope */
		zephir_set_scope(scope);
	}

	return retval;
}

/**
 * Checks whether obj is an object and updates property with another zval
 */
int zephir_update_property_zval(
	zval *object,
	const char *property_name,
	unsigned int property_length,
	zval *value
) {
	zval property, sep_value;

	if (Z_TYPE_P(object) != IS_OBJECT) {
		php_error_docref(NULL, E_WARNING, "Attempt to assign property '%s' of non-object", property_name);
		return FAILURE;
	}

	if (!Z_OBJ_HT_P(object)->write_property) {
		zend_error(E_CORE_ERROR, "Property %s of class %s cannot be updated", property_name, ZSTR_VAL(Z_OBJCE_P(object)->name));
	}

	ZVAL_STRINGL(&property, property_name, property_length);
	ZVAL_COPY_VALUE(&sep_value, value);
	if (Z_TYPE(sep_value) == IS_ARRAY) {
		ZVAL_ARR(&sep_value, zend_array_dup(Z_ARR(sep_value)));
		if (EXPECTED(!(GC_FLAGS(Z_ARRVAL(sep_value)) & IS_ARRAY_IMMUTABLE))) {
			if (UNEXPECTED(GC_REFCOUNT(Z_ARR(sep_value)) > 0)) {
				GC_DELREF(Z_ARR(sep_value));
			}
		}
	}

	/* write_property will add 1 to refcount,
	   so no Z_TRY_ADDREF_P(value) is necessary */
#if PHP_VERSION_ID >= 80000
	Z_OBJ_HT_P(object)->write_property(Z_OBJ_P(object), Z_STR(property), &sep_value, 0);
#else
	Z_OBJ_HT_P(object)->write_property(object, &property, &sep_value, 0);
#endif

	zval_ptr_dtor(&property);

	if (UNEXPECTED(EG(exception))) {
		return FAILURE;
	}

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
int zephir_update_property_array(zval *object, const char *property, uint32_t property_length, const zval *index, zval *value)
{
	zval tmp, sep_value;
	int separated = 0;

	if (Z_TYPE_P(object) != IS_OBJECT) {
		return SUCCESS;
	}

	zephir_read_property(&tmp, object, property, property_length, PH_NOISY | PH_READONLY);

	/** Separation only when refcount > 1 */
	if (Z_REFCOUNTED(tmp)) {
		if (Z_REFCOUNT(tmp) > 1) {
			if (!Z_ISREF(tmp)) {
				zval new_zv;
				ZVAL_DUP(&new_zv, &tmp);
				ZVAL_COPY_VALUE(&tmp, &new_zv);
				Z_TRY_DELREF(new_zv);
				Z_ADDREF(tmp);
				separated = 1;
			}
		}
	} else {
		zval new_zv;
		ZVAL_DUP(&new_zv, &tmp);
		ZVAL_COPY_VALUE(&tmp, &new_zv);
		Z_TRY_DELREF(new_zv);
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

		if (Z_REFCOUNTED(tmp)) {
			if (Z_REFCOUNT(tmp) > 1) {
				if (!Z_ISREF(tmp)) {
					Z_DELREF(tmp);
				}
			}
		}
	}

	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZVAL_ARR(&sep_value, zend_array_dup(Z_ARR_P(value)));
	} else {
		ZVAL_COPY(&sep_value, value);
	}

	if (Z_TYPE_P(index) == IS_STRING) {
		zend_symtable_str_update(Z_ARRVAL(tmp), Z_STRVAL_P(index), Z_STRLEN_P(index), &sep_value);
	} else if (Z_TYPE_P(index) == IS_LONG) {
		zend_hash_index_update(Z_ARRVAL(tmp), Z_LVAL_P(index), &sep_value);
	} else if (Z_TYPE_P(index) == IS_NULL) {
		zend_hash_next_index_insert(Z_ARRVAL(tmp), &sep_value);
	}

	if (separated) {
		zephir_update_property_zval(object, property, property_length, &tmp);
		zephir_ptr_dtor(&tmp);
	}

	return SUCCESS;
}

/**
 * Appends a zval value to an array property
 */
int zephir_update_property_array_append(zval *object, char *property, unsigned int property_length, zval *value)
{
	zval tmp, sep_value;
	int separated = 0;

	ZVAL_UNDEF(&tmp);

	if (Z_TYPE_P(object) != IS_OBJECT) {
		return SUCCESS;
	}

	zephir_read_property(&tmp, object, property, property_length, PH_NOISY | PH_READONLY);

	/** Separation only when refcount > 1 */
	if (Z_REFCOUNTED(tmp)) {
		if (Z_REFCOUNT(tmp) > 1) {
			if (!Z_ISREF(tmp)) {
				zval new_zv;
				ZVAL_DUP(&new_zv, &tmp);
				ZVAL_COPY_VALUE(&tmp, &new_zv);
				if (Z_REFCOUNT(tmp) > 1) {
				    Z_TRY_DELREF(new_zv);
				}
				separated = 1;
			}
		}
	} else {
		zval new_zv;
		ZVAL_DUP(&new_zv, &tmp);
		ZVAL_COPY_VALUE(&tmp, &new_zv);
		Z_TRY_DELREF(new_zv);
		separated = 1;

		/**
		 * class A {
		 *     protected foo;
		 *
		 *     public function test() {
		 *         let this->foo[] = 42;
		 *     }
		 * }
		 *
		 * In this case: Z_REFCOUNT(tmp) == 0
		 */
		if (Z_REFCOUNTED(tmp)) {
			if (EXPECTED(Z_REFCOUNT(tmp) == 0)) {
				Z_ADDREF(tmp);
			}
		}
	}

	/** Convert the value to array if not is an array */
	if (Z_TYPE(tmp) != IS_ARRAY) {
		if (separated) {
			convert_to_array(&tmp);
		} else {
			array_init(&tmp);
			separated = 1;
		}

		if (Z_REFCOUNTED(tmp)) {
			if (Z_REFCOUNT(tmp) > 1) {
				if (!Z_ISREF(tmp)) {
					Z_DELREF(tmp);
				}
			}
		}
	}

	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZVAL_ARR(&sep_value, zend_array_dup(Z_ARR_P(value)));
	} else {
		ZVAL_COPY(&sep_value, value);
	}

	add_next_index_zval(&tmp, &sep_value);

	if (separated) {
		zephir_update_property_zval(object, property, property_length, &tmp);
		zephir_ptr_dtor(&tmp);
	}

	return SUCCESS;
}

/**
 * Multiple array-offset update
 */
int zephir_update_property_array_multi(zval *object, const char *property, uint32_t property_length, zval *value, const char *types, int types_length, int types_count, ...)
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
					Z_ADDREF(tmp_arr);
					separated = 1;
				}
			}
		} else {
			zval new_zv;
			ZVAL_DUP(&new_zv, &tmp_arr);
			ZVAL_COPY_VALUE(&tmp_arr, &new_zv);
			Z_TRY_DELREF(new_zv);
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

			if (Z_REFCOUNTED(tmp_arr)) {
				if (Z_REFCOUNT(tmp_arr) > 1) {
					if (!Z_ISREF(tmp_arr)) {
						Z_DELREF(tmp_arr);
					}
				}
			}
		}

		va_start(ap, types_count);
		zephir_array_update_multi_ex(&tmp_arr, value, types, types_length, types_count, ap);
		va_end(ap);

		if (separated) {
			zephir_update_property_zval(object, property, property_length, &tmp_arr);
			zephir_ptr_dtor(&tmp_arr);
		}
	}

	return SUCCESS;
}

int zephir_unset_property(zval* object, const char* name)
{
	if (Z_TYPE_P(object) != IS_OBJECT) {
		return FAILURE;
	}

	zval member;
	zend_class_entry *scope;

	ZVAL_STRING(&member, name);

	/* Backup current scope */
	scope = zephir_get_scope(0);

	/* Use caller's scope */
	zephir_set_scope(Z_OBJCE_P(object));
#if PHP_VERSION_ID >= 80000
	Z_OBJ_HT_P(object)->unset_property(Z_OBJ_P(object), Z_STR(member), 0);
#else
	Z_OBJ_HT_P(object)->unset_property(object, &member, 0);
#endif
	/* Restore original scope */
	zephir_set_scope(scope);

	return SUCCESS;
}

/**
 * Unsets an index in an array property
 *
 * TODO: This only works with zephir_read_property() + zephir_array_unset_string(), which might be incorrect
 */
int zephir_unset_property_array(zval *object, char *property, unsigned int property_length, zval *index)
{
	zval tmp;
	int separated = 0;

	if (Z_TYPE_P(object) == IS_OBJECT) {
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
			zval new_zv;
			ZVAL_DUP(&new_zv, &tmp);
			ZVAL_COPY_VALUE(&tmp, &new_zv);
			Z_TRY_DELREF(new_zv);
			separated = 1;
		}

		zephir_array_unset(&tmp, index, PH_SEPARATE);

		if (separated) {
			zephir_update_property_zval(object, property, property_length, &tmp);
		}
	}

	return SUCCESS;
}

int zephir_method_exists_ex(zval *object, const char *method_name, unsigned int method_len)
{
	zend_class_entry *ce;
	union _zend_function *func = NULL;
	zend_string *method;

	if (EXPECTED(Z_TYPE_P(object) == IS_OBJECT)) {
		ce = Z_OBJCE_P(object);
	} else if (Z_TYPE_P(object) == IS_STRING) {
		ce = zend_fetch_class(Z_STR_P(object), ZEND_FETCH_CLASS_DEFAULT);
	} else {
		return FAILURE;
	}

	if (zend_hash_str_exists(&ce->function_table, method_name, method_len)) {
		return SUCCESS;
	}

	method = zend_string_init(method_name, method_len, 0);
	if (
		   Z_TYPE_P(object) == IS_OBJECT
		&& Z_OBJ_HT_P(object)->get_method
		&& (func = Z_OBJ_HT_P(object)->get_method(&Z_OBJ_P(object), method, NULL))
	) {
		if (func->common.fn_flags & ZEND_ACC_CALL_VIA_TRAMPOLINE) {
			int status = (func->common.scope == zend_ce_closure && zend_string_equals_literal(method, ZEND_INVOKE_FUNC_NAME));

			zend_string_release(method);
			zend_string_release(func->common.function_name);
			zend_free_trampoline(func);
			return status ? SUCCESS : FAILURE;
		}

		zend_string_release(method);
		return SUCCESS;
	}

	zend_string_release(method);
	return FAILURE;
}

int zephir_method_exists(zval *object, const zval *method_name)
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

	ZVAL_NULL(result);
	if (tmp) {
		if ((flags & PH_READONLY) == PH_READONLY) {
			ZVAL_COPY_VALUE(result, tmp);
		} else {
			ZVAL_COPY(result, tmp);
		}

		return SUCCESS;
	}

	return FAILURE;
}

/**
 * TODO: Use directly zend_update_static_property()
 */
int zephir_update_static_property_ce(zend_class_entry *ce, const char *property_name, uint32_t property_length, zval *value)
{
	return zend_update_static_property(ce, property_name, property_length, value);
}

int zephir_add_static_property_ce(zend_class_entry *ce, const char *property_name, uint32_t property_length, zval *value)
{
	zval tmp_value, new_value;
	zephir_read_static_property_ce(&tmp_value, ce, property_name, property_length, PH_NOISY | PH_READONLY);
	zephir_add_function(&new_value, &tmp_value, value);
	return zend_update_static_property(ce, property_name, property_length, &new_value);
}

int zephir_sub_static_property_ce(zend_class_entry *ce, const char *property_name, uint32_t property_length, zval *value)
{
	zval tmp_value, new_value;
	zephir_read_static_property_ce(&tmp_value, ce, property_name, property_length, PH_NOISY | PH_READONLY);
	zephir_sub_function(&new_value, &tmp_value, value);
	return zend_update_static_property(ce, property_name, property_length, &new_value);
}

/*
 * Multiple array-offset update
 */
int zephir_update_static_property_array_multi_ce(
	zend_class_entry *ce,
	const char *property,
	uint32_t property_length,
	zval *value,
	const char *types,
	int types_length,
	int types_count,
	...
) {
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
				Z_ADDREF(tmp_arr);
				separated = 1;
			}
		}
	} else {
		zval new_zv;
		ZVAL_DUP(&new_zv, &tmp_arr);
		ZVAL_COPY_VALUE(&tmp_arr, &new_zv);
		Z_TRY_DELREF(new_zv);
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

		if (Z_REFCOUNTED(tmp_arr)) {
			if (Z_REFCOUNT(tmp_arr) > 1) {
				if (!Z_ISREF(tmp_arr)) {
					Z_DELREF(tmp_arr);
				}
			}
		}
	}

	va_start(ap, types_count);
	SEPARATE_ZVAL_NOREF(&tmp_arr);
	zephir_array_update_multi_ex(&tmp_arr, value, types, types_length, types_count, ap);
	va_end(ap);

	if (separated) {
		zend_update_static_property(ce, property, property_length, &tmp_arr);
	}

	if (Z_REFCOUNTED(tmp_arr)) {
		if (Z_REFCOUNT(tmp_arr) > 1) {
			if (!Z_ISREF(tmp_arr)) {
				Z_DELREF(tmp_arr);
			}
		}
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
			zval new_zv;
			ZVAL_DUP(&new_zv, &tmp);
			ZVAL_COPY_VALUE(&tmp, &new_zv);
			Z_TRY_DELREF(new_zv);
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
	zif_handler       orig_internal_handler;
} zend_closure;

/**
 * Creates a closure
 */
int zephir_create_closure_ex(zval *return_value, zval *this_ptr, zend_class_entry *ce, const char *method_name, uint32_t method_length)
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

	if(UNEXPECTED(object_init_ex(return_value, ce) != SUCCESS)) {
    	return FAILURE;
    }

	if (EXPECTED(Z_OBJ_HT_P(return_value)->get_constructor)) {
		zend_object* obj    = Z_OBJ_P(return_value);
		zend_function* ctor = Z_OBJ_HT_P(return_value)->get_constructor(obj);
		if (ctor) {
			zend_fcall_info fci;
			zend_fcall_info_cache fcc;

			zend_class_entry* ce = Z_OBJCE_P(return_value);

			fci.size             = sizeof(fci);
			fci.object           = obj;
			fci.retval           = 0;
			fci.param_count      = 0;
			fci.params           = 0;
#if PHP_VERSION_ID < 80000
			fci.no_separation = 1;
#else
			fci.named_params = NULL;
#endif

			ZVAL_NULL(&fci.function_name);

			fcc.object           = obj;
			fcc.called_scope     = ce;
			fcc.calling_scope    = ce;
			fcc.function_handler = ctor;

			return zend_fcall_info_call(&fci, &fcc, NULL, NULL);
		}
	}

	return SUCCESS;
}

/**
 * Creates a new instance dynamically calling constructor with parameters
 */
int zephir_create_instance_params(zval *return_value, const zval *class_name, zval *params)
{
	zend_class_entry *ce;

	if (Z_TYPE_P(class_name) != IS_STRING) {
		zephir_throw_exception_string(spl_ce_RuntimeException, SL("Invalid class name"));
		return FAILURE;
	}

	if (Z_TYPE_P(params) != IS_ARRAY) {
		zephir_throw_exception_string(spl_ce_RuntimeException, SL("Instantiation parameters must be an array"));
		return FAILURE;
	}

	ce = zend_fetch_class(Z_STR_P(class_name), ZEND_FETCH_CLASS_AUTO);
	if (!ce) {
		ZVAL_NULL(return_value);
		return FAILURE;
	}

	if(UNEXPECTED(object_init_ex(return_value, ce) != SUCCESS)) {
    	return FAILURE;
    }

	if (EXPECTED(Z_OBJ_HT_P(return_value)->get_constructor)) {
		zend_object* obj    = Z_OBJ_P(return_value);
		zend_function* ctor = Z_OBJ_HT_P(return_value)->get_constructor(obj);
		if (ctor) {
			int status;
			zend_fcall_info fci;
			zend_fcall_info_cache fcc;

			zend_class_entry* ce = Z_OBJCE_P(return_value);

			fci.size             = sizeof(fci);
			fci.object           = obj;
			fci.retval           = 0;
			fci.param_count      = 0;
			fci.params           = 0;
#if PHP_VERSION_ID < 80000
			fci.no_separation = 1;
#else
			fci.named_params = NULL;
#endif
			ZVAL_NULL(&fci.function_name);

			fcc.object           = obj;
			fcc.called_scope     = ce;
			fcc.calling_scope    = ce;
			fcc.function_handler = ctor;

			zend_fcall_info_args_ex(&fci, fcc.function_handler, params);
			status = zend_fcall_info_call(&fci, &fcc, NULL, NULL);
			zend_fcall_info_args_clear(&fci, 1);
			return status;
		}
	}

	return SUCCESS;
}
