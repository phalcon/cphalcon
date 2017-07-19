
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
#include "kernel/array.h"
#include "kernel/operators.h"


/**
 * Reads class constant from string name and returns its value
 */
int zephir_get_class_constant(zval *return_value, zend_class_entry *ce, char *constant_name, unsigned int constant_length TSRMLS_DC) {

	zval **result_ptr;

	if (zend_hash_find(&ce->constants_table, constant_name, constant_length, (void **) &result_ptr) != SUCCESS) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Undefined class constant '%s::%s'", ce->name, constant_name);
		return FAILURE;
	}

	ZVAL_ZVAL(return_value, *result_ptr, 1, 0);
	return SUCCESS;
}

/**
 * Check if class is instance of
 */
int zephir_instance_of(zval *result, const zval *object, const zend_class_entry *ce TSRMLS_DC) {

	if (Z_TYPE_P(object) != IS_OBJECT) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "instanceof expects an object instance");
		ZVAL_FALSE(result);
		return FAILURE;
	}

	ZVAL_BOOL(result, instanceof_function(Z_OBJCE_P(object), ce TSRMLS_CC));
	return SUCCESS;
}

int zephir_instance_of_ev(const zval *object, const zend_class_entry *ce TSRMLS_DC) {

	if (Z_TYPE_P(object) != IS_OBJECT) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "instanceof expects an object instance");
		return 0;
	}

	return instanceof_function(Z_OBJCE_P(object), ce TSRMLS_CC);
}

/**
 * Check if an object is instance of a class
 */
int zephir_is_instance_of(zval *object, const char *class_name, unsigned int class_length TSRMLS_DC) {

	zend_class_entry *ce, *temp_ce;

	if (Z_TYPE_P(object) == IS_OBJECT) {

		ce = Z_OBJCE_P(object);
		if (ce->name_length == class_length) {
		  	if (!zend_binary_strcasecmp(ce->name, ce->name_length, class_name, class_length)) {
                            return 1;
                        }
		}

		temp_ce = zend_fetch_class(class_name, class_length, ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
		if (temp_ce) {
			return instanceof_function(ce, temp_ce TSRMLS_CC);
		}
	}

	return 0;
}

int zephir_zval_is_traversable(zval *object TSRMLS_DC) {

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
 * Returns a class name into a zval result
 */
void zephir_get_class(zval *result, zval *object, int lower TSRMLS_DC) {

	zend_class_entry *ce;

	if (Z_TYPE_P(object) == IS_OBJECT) {

		ce = Z_OBJCE_P(object);
		Z_STRLEN_P(result) = ce->name_length;
		Z_STRVAL_P(result) = (char *) emalloc(ce->name_length + 1);
		memcpy(Z_STRVAL_P(result), ce->name, ce->name_length);
		Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
		Z_TYPE_P(result) = IS_STRING;

		if (lower) {
			zend_str_tolower(Z_STRVAL_P(result), Z_STRLEN_P(result));
		}

	} else {
		ZVAL_NULL(result);
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "zephir_get_class expects an object");
	}
}

/**
 * Returns a class name into a zval result
 */
void zephir_get_class_ns(zval *result, zval *object, int lower TSRMLS_DC) {

	int found = 0;
	zend_class_entry *ce;
	unsigned int i, class_length;
	const char *cursor, *class_name;

	if (Z_TYPE_P(object) != IS_OBJECT) {
		if (Z_TYPE_P(object) != IS_STRING) {
			ZVAL_NULL(result);
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "zephir_get_class_ns expects an object");
			return;
		}
	}

	if (Z_TYPE_P(object) == IS_OBJECT) {
		ce = Z_OBJCE_P(object);
		class_name = ce->name;
		class_length = ce->name_length;
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
		Z_STRLEN_P(result) = class_length - i;
		Z_STRVAL_P(result) = (char *) emalloc(class_length - i + 1);
		memcpy(Z_STRVAL_P(result), class_name + i, class_length - i);
		Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
		Z_TYPE_P(result) = IS_STRING;
	} else {
		ZVAL_STRINGL(result, class_name, class_length, 1);
	}

	if (lower) {
		zend_str_tolower(Z_STRVAL_P(result), Z_STRLEN_P(result));
	}

}

/**
 * Returns a namespace from a class name
 */
void zephir_get_ns_class(zval *result, zval *object, int lower TSRMLS_DC) {

	zend_class_entry *ce;
	int found = 0;
	unsigned int i, j, class_length;
	const char *cursor, *class_name;

	if (Z_TYPE_P(object) != IS_OBJECT) {
		if (Z_TYPE_P(object) != IS_STRING) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "zephir_get_ns_class expects an object");
			ZVAL_NULL(result);
			return;
		}
	}

	if (Z_TYPE_P(object) == IS_OBJECT) {
		ce = Z_OBJCE_P(object);
		class_name = ce->name;
		class_length = ce->name_length;
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
			Z_STRLEN_P(result) = class_length - j - 1;
			Z_STRVAL_P(result) = (char *) emalloc(class_length - j);
			memcpy(Z_STRVAL_P(result), class_name, class_length - j - 1);
			Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
			Z_TYPE_P(result) = IS_STRING;
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
 * Returns the called in class in the current scope
 */
void zephir_get_called_class(zval *return_value TSRMLS_DC) {

	if (EG(called_scope)) {
		RETURN_STRINGL(EG(called_scope)->name, EG(called_scope)->name_length, 1);
	}

	if (!EG(scope))  {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "zephir_get_called_class() called from outside a class");
	}
}

/**
 * Fetches a zend class entry from a zval value
 */
zend_class_entry *zephir_fetch_class(const zval *class_name TSRMLS_DC) {

	if (Z_TYPE_P(class_name) == IS_STRING) {
		return zend_fetch_class(Z_STRVAL_P(class_name), Z_STRLEN_P(class_name), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
	}

	php_error_docref(NULL TSRMLS_CC, E_WARNING, "class name must be a string");
	return zend_fetch_class("stdclass", strlen("stdclass"), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
}

zend_class_entry* zephir_fetch_self_class(TSRMLS_D) {
	return zend_fetch_class(NULL, 0, ZEND_FETCH_CLASS_SELF TSRMLS_CC);
}

zend_class_entry* zephir_fetch_parent_class(TSRMLS_D) {
	return zend_fetch_class(NULL, 0, ZEND_FETCH_CLASS_PARENT TSRMLS_CC);
}

zend_class_entry* zephir_fetch_static_class(TSRMLS_D) {
	return zend_fetch_class(NULL, 0, ZEND_FETCH_CLASS_STATIC TSRMLS_CC);
}

/**
 * Checks if a class exist
 */
int zephir_class_exists(const zval *class_name, int autoload TSRMLS_DC) {

	zend_class_entry **ce;

	if (Z_TYPE_P(class_name) == IS_STRING) {
		if (zend_lookup_class(Z_STRVAL_P(class_name), Z_STRLEN_P(class_name), &ce TSRMLS_CC) == SUCCESS) {
			return ((*ce)->ce_flags & (ZEND_ACC_INTERFACE | (ZEND_ACC_TRAIT - ZEND_ACC_EXPLICIT_ABSTRACT_CLASS))) == 0;
		}
		return 0;
	}

	php_error_docref(NULL TSRMLS_CC, E_WARNING, "class name must be a string");
	return 0;
}

/**
 * Checks if a interface exist
 */
int zephir_interface_exists(const zval *class_name, int autoload TSRMLS_DC) {

	zend_class_entry **ce;

	if (Z_TYPE_P(class_name) == IS_STRING) {
		if (zend_lookup_class(Z_STRVAL_P(class_name), Z_STRLEN_P(class_name), &ce TSRMLS_CC) == SUCCESS) {
			return (((*ce)->ce_flags & ZEND_ACC_INTERFACE) > 0);
		}
		return 0;
	}

	php_error_docref(NULL TSRMLS_CC, E_WARNING, "interface name must be a string");
	return 0;
}

/**
 * Clones an object from obj to destination
 */
int zephir_clone(zval *destination, zval *obj TSRMLS_DC) {

	int status = SUCCESS;
	zend_class_entry *ce;
	zend_object_clone_obj_t clone_call;

	if (Z_TYPE_P(obj) != IS_OBJECT) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "__clone method called on non-object");
		status = FAILURE;
	} else {
		ce = Z_OBJCE_P(obj);
		clone_call =  Z_OBJ_HT_P(obj)->clone_obj;
		if (!clone_call) {
			if (ce) {
				php_error_docref(NULL TSRMLS_CC, E_ERROR, "Trying to clone an uncloneable object of class %s", ce->name);
			} else {
				php_error_docref(NULL TSRMLS_CC, E_ERROR, "Trying to clone an uncloneable object");
			}
			status = FAILURE;
		} else {
			if (!EG(exception)) {
				Z_OBJVAL_P(destination) = clone_call(obj TSRMLS_CC);
				Z_TYPE_P(destination) = IS_OBJECT;
				Z_SET_REFCOUNT_P(destination, 1);
				Z_UNSET_ISREF_P(destination);
				if (EG(exception)) {
					zval_ptr_dtor(&destination);
				}
			}
		}
	}

	return status;
}

/**
 * Checks if property exists on object
 */
int zephir_isset_property_quick(zval *object, const char *property_name, unsigned int property_length, unsigned long hash TSRMLS_DC) {

	if (Z_TYPE_P(object) == IS_OBJECT) {
		if (EXPECTED(zend_hash_quick_exists(&Z_OBJCE_P(object)->properties_info, property_name, property_length, hash))) {
			return 1;
		} else {
			return zend_hash_quick_exists(Z_OBJ_HT_P(object)->get_properties(object TSRMLS_CC), property_name, property_length, hash);
		}
	}

	return 0;
}

/**
 * Checks if property exists on object
 */
int zephir_isset_property(zval *object, const char *property_name, unsigned int property_length TSRMLS_DC) {

	return zephir_isset_property_quick(object, property_name, property_length, zend_inline_hash_func(property_name, property_length) TSRMLS_CC);
}

/**
 * Checks if string property exists on object
 */
int zephir_isset_property_zval(zval *object, const zval *property TSRMLS_DC) {

	unsigned long hash;

	if (Z_TYPE_P(object) == IS_OBJECT) {
		if (Z_TYPE_P(property) == IS_STRING) {

			hash = zend_inline_hash_func(Z_STRVAL_P(property), Z_STRLEN_P(property) + 1);

			if (EXPECTED(zend_hash_quick_exists(&Z_OBJCE_P(object)->properties_info, Z_STRVAL_P(property), Z_STRLEN_P(property) + 1, hash))) {
				return 1;
			} else {
				return zend_hash_quick_exists(Z_OBJ_HT_P(object)->get_properties(object TSRMLS_CC), Z_STRVAL_P(property), Z_STRLEN_P(property) + 1, hash);
			}
		}
	}

	return 0;
}

/*
 * Lookup exact class where a property is defined (precomputed key)
 *
 */
static inline zend_class_entry *zephir_lookup_class_ce_quick(zend_class_entry *ce, const char *property_name, zend_uint property_length, ulong hash TSRMLS_DC) {

	zend_class_entry *original_ce = ce;

	while (ce) {
		if (zend_hash_quick_exists(&ce->properties_info, property_name, property_length + 1, hash)) {
			return ce;
		}
		ce = ce->parent;
	}
	return original_ce;
}

/**
 * Lookup exact class where a property is defined
 *
 */
static inline zend_class_entry *zephir_lookup_class_ce(zend_class_entry *ce, const char *property_name, unsigned int property_length TSRMLS_DC) {

	return zephir_lookup_class_ce_quick(ce, property_name, property_length, zend_inline_hash_func(property_name, property_length + 1) TSRMLS_CC);
}

/**
 * Reads a property from an object
 */
int zephir_read_property(zval **result, zval *object, const char *property_name, zend_uint property_length, int silent TSRMLS_DC) {

	zval *property;
	zend_class_entry *ce, *old_scope;

	if (Z_TYPE_P(object) != IS_OBJECT) {

		if (silent == PH_NOISY) {
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Trying to get property \"%s\" of non-object", property_name);
		}

		ALLOC_INIT_ZVAL(*result);
		ZVAL_NULL(*result);
		return FAILURE;
	}

	ce = Z_OBJCE_P(object);
	if (ce->parent) {
		ce = zephir_lookup_class_ce(ce, property_name, property_length TSRMLS_CC);
	}

	old_scope = EG(scope);
	EG(scope) = ce;

	if (!Z_OBJ_HT_P(object)->read_property) {
		const char *class_name;
		zend_uint class_name_len;

		zend_get_object_classname(object, &class_name, &class_name_len TSRMLS_CC);
		zend_error(E_CORE_ERROR, "Property %s of class %s cannot be read", property_name, class_name);
	}

	MAKE_STD_ZVAL(property);
	ZVAL_STRINGL(property, property_name, property_length, 0);

	*result = Z_OBJ_HT_P(object)->read_property(object, property, silent ? BP_VAR_IS : BP_VAR_R, 0 TSRMLS_CC);

	Z_ADDREF_PP(result);

	if (Z_REFCOUNT_P(property) > 1) {
		ZVAL_STRINGL(property, property_name, property_length, 1);
	} else {
		ZVAL_NULL(property);
	}

	zval_ptr_dtor(&property);

	EG(scope) = old_scope;
	return SUCCESS;
}

zval* zephir_fetch_property_this_quick(zval *object, const char *property_name, zend_uint property_length, ulong key, int silent TSRMLS_DC) {

	zval **zv = NULL;
	zend_object *zobj;
	zend_property_info *property_info;
	zend_class_entry *ce, *old_scope;

	if (EXPECTED(Z_TYPE_P(object) == IS_OBJECT)) {

		ce = Z_OBJCE_P(object);
		if (ce->parent) {
			ce = zephir_lookup_class_ce_quick(ce, property_name, property_length, key TSRMLS_CC);
		}

		old_scope = EG(scope);
		EG(scope) = ce;

		zobj = zend_objects_get_address(object TSRMLS_CC);

		if (zend_hash_quick_find(&ce->properties_info, property_name, property_length + 1, key, (void **) &property_info) == SUCCESS) {
			int flag;
			if (EXPECTED((property_info->flags & ZEND_ACC_STATIC) == 0) && property_info->offset >= 0) {
				if (zobj->properties) {
					zv   = (zval**) zobj->properties_table[property_info->offset];
					flag = (zv == NULL) ? 1 : 0;
				} else {
					zv   = &zobj->properties_table[property_info->offset];
					flag = (*zv == NULL) ? 1 : 0;
				}
			} else if (UNEXPECTED(!zobj->properties)) {
				flag = 1;
			} else if (UNEXPECTED(zend_hash_quick_find(zobj->properties, property_info->name, property_info->name_length+1, property_info->h, (void **) &zv) == FAILURE)) {
				flag = 2;
			} else {
				flag = 0;
			}

			if (UNEXPECTED(flag) && zobj->properties) {
				if (
					(flag == 2 || zend_hash_quick_find(zobj->properties, property_info->name, property_info->name_length+1, property_info->h, (void **) &zv) == FAILURE)
					&& zv && *zv
				) {
					flag = 0;
				}
			}

			if (EXPECTED(!flag)) {
				EG(scope) = old_scope;
				return *zv;
			}
		}

		EG(scope) = old_scope;

	} else {
		if (silent == PH_NOISY) {
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Trying to get property \"%s\" of non-object", property_name);
		}
	}

	return NULL;
}

/**
 * Returns an object's member
 */
int zephir_return_property_quick(zval *return_value, zval **return_value_ptr, zval *object, char *property_name, unsigned int property_length, unsigned long key TSRMLS_DC) {

	zval **zv;
	zend_object *zobj;
	zend_property_info *property_info;
	zend_class_entry *ce, *old_scope;

	if (EXPECTED(Z_TYPE_P(object) == IS_OBJECT)) {

		ce = Z_OBJCE_P(object);
		if (ce->parent) {
			ce = zephir_lookup_class_ce_quick(ce, property_name, property_length, key TSRMLS_CC);
		}

		old_scope = EG(scope);
		EG(scope) = ce;

		zobj = zend_objects_get_address(object TSRMLS_CC);

		if (zend_hash_quick_find(&ce->properties_info, property_name, property_length + 1, key, (void **) &property_info) == SUCCESS) {
			int flag;
			if (EXPECTED((property_info->flags & ZEND_ACC_STATIC) == 0) && property_info->offset >= 0) {
				if (zobj->properties) {
					zv   = (zval**) zobj->properties_table[property_info->offset];
					flag = (zv == NULL) ? 1 : 0;
				} else {
					zv   = &zobj->properties_table[property_info->offset];
					flag = (*zv == NULL) ? 1 : 0;
				}
			} else if (UNEXPECTED(!zobj->properties)) {
				flag = 1;
			} else if (UNEXPECTED(zend_hash_quick_find(zobj->properties, property_info->name, property_info->name_length+1, property_info->h, (void **) &zv) == FAILURE)) {
				flag = 2;
			} else {
				flag = 0;
			}

			if (UNEXPECTED(flag) && zobj->properties) {
				if (
					(flag == 2 || zend_hash_quick_find(zobj->properties, property_info->name, property_info->name_length+1, property_info->h, (void **) &zv) == FAILURE)
					&& zv && *zv
				) {
					flag = 0;
				}
			}

			if (EXPECTED(!flag)) {
				EG(scope) = old_scope;

				if (return_value_ptr) {
					zval_ptr_dtor(return_value_ptr);
					Z_ADDREF_PP(zv);
					*return_value_ptr = *zv;
				}
				else {
					ZVAL_ZVAL(return_value, *zv, 1, 0);
				}

				return SUCCESS;
			}
		}

		EG(scope) = old_scope;

	} else {
		php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Trying to get property \"%s\" of non-object", property_name);
	}

	ZVAL_NULL(return_value);
	return FAILURE;
}

/**
 * Returns an object's member
 */
int zephir_return_property(zval *return_value, zval **return_value_ptr, zval *object, char *property_name, unsigned int property_length TSRMLS_DC) {

	return zephir_return_property_quick(return_value, return_value_ptr, object, property_name, property_length, zend_inline_hash_func(property_name, property_length + 1) TSRMLS_CC);
}

/**
 * Reads a property from an object
 */
int zephir_read_property_zval(zval **result, zval *object, zval *property, int flags TSRMLS_DC) {

	if (UNEXPECTED(Z_TYPE_P(property) != IS_STRING)) {

		if ((flags & PH_NOISY) == PH_NOISY) {
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Cannot access empty property %d", Z_TYPE_P(property));
		}

		*result = ZEPHIR_GLOBAL(global_null);
		Z_ADDREF_P(*result);
		return FAILURE;
	}

	return zephir_read_property(result, object, Z_STRVAL_P(property), Z_STRLEN_P(property), flags TSRMLS_CC);
}

/**
 * Checks whether obj is an object and updates property with long value
 */
int zephir_update_property_long(zval *object, char *property_name, unsigned int property_length, long value TSRMLS_DC) {

	zval *v;

	ALLOC_ZVAL(v);
	Z_UNSET_ISREF_P(v);
	Z_SET_REFCOUNT_P(v, 0);
	ZVAL_LONG(v, value);

	return zephir_update_property_zval(object, property_name, property_length, v TSRMLS_CC);
}

/**
 * Checks whether obj is an object and updates property with string value
 */
int zephir_update_property_string(zval *object, char *property_name, unsigned int property_length, char *str, unsigned int str_length TSRMLS_DC) {

	zval *value;
	int res;

	ALLOC_ZVAL(value);
	Z_UNSET_ISREF_P(value);
	Z_SET_REFCOUNT_P(value, 0);
	ZVAL_STRINGL(value, str, str_length, 1);

	res = zephir_update_property_zval(object, property_name, property_length, value TSRMLS_CC);
	if (res == SUCCESS) {
		return SUCCESS;
	}

	return FAILURE;
}

/**
 * Checks whether obj is an object and updates property with bool value
 */
int zephir_update_property_bool(zval *object, char *property_name, unsigned int property_length, int value TSRMLS_DC) {
	return zephir_update_property_zval(object, property_name, property_length, value ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
}

/**
 * Checks whether obj is an object and updates property with null value
 */
int zephir_update_property_null(zval *object, char *property_name, unsigned int property_length TSRMLS_DC) {
	return zephir_update_property_zval(object, property_name, property_length, ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
}

/**
 * Checks whether obj is an object and updates property with another zval
 */
int zephir_update_property_zval(zval *object, const char *property_name, unsigned int property_length, zval *value TSRMLS_DC){

	zend_class_entry *ce, *old_scope;
	zval *property;

	old_scope = EG(scope);
	if (Z_TYPE_P(object) != IS_OBJECT) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Attempt to assign property of non-object");
		return FAILURE;
	}

	ce = Z_OBJCE_P(object);
	if (ce->parent) {
		ce = zephir_lookup_class_ce(ce, property_name, property_length TSRMLS_CC);
	}

	EG(scope) = ce;

	if (!Z_OBJ_HT_P(object)->write_property) {
		const char *class_name;
		zend_uint class_name_len;

		zend_get_object_classname(object, &class_name, &class_name_len TSRMLS_CC);
		zend_error(E_CORE_ERROR, "Property %s of class %s cannot be updated", property_name, class_name);
	}

	MAKE_STD_ZVAL(property);
	ZVAL_STRINGL(property, property_name, property_length, 0);

	Z_OBJ_HT_P(object)->write_property(object, property, value, 0 TSRMLS_CC);

	if (Z_REFCOUNT_P(property) > 1) {
		ZVAL_STRINGL(property, property_name, property_length, 1);
	} else {
		ZVAL_NULL(property);
	}

	zval_ptr_dtor(&property);

	EG(scope) = old_scope;
	return SUCCESS;
}

/**
 * Updates properties on this_ptr (quick)
 * If a variable is not defined in the class definition, this fallbacks to update_property_zval
 * function ignores magic methods or dynamic properties
 */
int zephir_update_property_this_quick(zval *object, const char *property_name, zend_uint property_length, zval *value, ulong key TSRMLS_DC){

	zend_class_entry *ce, *old_scope;

	if (UNEXPECTED(Z_TYPE_P(object) != IS_OBJECT)) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Attempt to assign property of non-object");
		return FAILURE;
	}

	ce = Z_OBJCE_P(object);
	if (ce->parent) {
		ce = zephir_lookup_class_ce_quick(ce, property_name, property_length, key TSRMLS_CC);
	}

	old_scope = EG(scope);
	EG(scope) = ce;

	{
		zend_object *zobj;
		zval **variable_ptr;
		zend_property_info *property_info;

		zobj = zend_objects_get_address(object TSRMLS_CC);

		if (EXPECTED(zend_hash_quick_find(&ce->properties_info, property_name, property_length + 1, key, (void **) &property_info) == SUCCESS)) {
			assert(property_info != NULL);

			/** This is as zend_std_write_property, but we're not interesed in validate properties visibility */
			if (property_info->offset >= 0 ? (zobj->properties ? ((variable_ptr = (zval**) zobj->properties_table[property_info->offset]) != NULL) : (*(variable_ptr = &zobj->properties_table[property_info->offset]) != NULL)) : (EXPECTED(zobj->properties != NULL) && EXPECTED(zend_hash_quick_find(zobj->properties, property_info->name, property_info->name_length + 1, property_info->h, (void **) &variable_ptr) == SUCCESS))) {

				if (EXPECTED(*variable_ptr != value)) {

					/* if we are assigning reference, we shouldn't move it, but instead assign variable to the same pointer */
					if (PZVAL_IS_REF(*variable_ptr)) {

						zval garbage = **variable_ptr; /* old value should be destroyed */

						/* To check: can't *variable_ptr be some system variable like error_zval here? */
						Z_TYPE_PP(variable_ptr) = Z_TYPE_P(value);
						(*variable_ptr)->value = value->value;
						if (Z_REFCOUNT_P(value) > 0) {
							zval_copy_ctor(*variable_ptr);
						} else {
							efree(value);
						}
						zval_dtor(&garbage);

					} else {
						zval *garbage = *variable_ptr;

						/* if we assign referenced variable, we should separate it */
						Z_ADDREF_P(value);
						if (PZVAL_IS_REF(value)) {
							SEPARATE_ZVAL(&value);
						}
						*variable_ptr = value;
						zval_ptr_dtor(&garbage);
					}
				}

			}
		} else {
			EG(scope) = old_scope;
			return zephir_update_property_zval(object, property_name, property_length, value TSRMLS_CC);
		}
	}

	EG(scope) = old_scope;

	return SUCCESS;
}

/**
 * Updates properties on this_ptr
 * Variables must be defined in the class definition. This function ignores magic methods or dynamic properties
 */
int zephir_update_property_this(zval *object, char *property_name, unsigned int property_length, zval *value TSRMLS_DC) {

	return zephir_update_property_this_quick(object, property_name, property_length, value, zend_inline_hash_func(property_name, property_length + 1) TSRMLS_CC);
}

/**
 * Checks whether obj is an object and updates zval property with another zval
 */
int zephir_update_property_zval_zval(zval *object, zval *property, zval *value TSRMLS_DC) {

	if (Z_TYPE_P(property) != IS_STRING) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Property should be string");
		return FAILURE;
	}

	return zephir_update_property_zval(object, Z_STRVAL_P(property), Z_STRLEN_P(property), value TSRMLS_CC);
}

/**
 * Updates an array property
 */
int zephir_update_property_array(zval *object, const char *property, zend_uint property_length, const zval *index, zval *value TSRMLS_DC) {

	zval *tmp;
	int separated = 0;

	if (Z_TYPE_P(object) == IS_OBJECT) {

		zephir_read_property(&tmp, object, property, property_length, PH_NOISY TSRMLS_CC);

		Z_DELREF_P(tmp);

		/** Separation only when refcount > 1 */
		if (Z_REFCOUNT_P(tmp) > 1) {
			if (!Z_ISREF_P(tmp)) {
				zval *new_zv;
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, tmp);
				tmp = new_zv;
				zval_copy_ctor(new_zv);
				Z_SET_REFCOUNT_P(tmp, 0);
				Z_UNSET_ISREF_P(tmp);
				separated = 1;
			}
		}

		/** Convert the value to array if not is an array */
		if (Z_TYPE_P(tmp) != IS_ARRAY) {
			if (separated) {
				convert_to_array(tmp);
			} else {
				zval *new_zv;
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, tmp);
				tmp = new_zv;
				zval_copy_ctor(new_zv);
				Z_SET_REFCOUNT_P(tmp, 0);
				Z_UNSET_ISREF_P(tmp);
				array_init(tmp);
				separated = 1;
			}
		}

		Z_ADDREF_P(value);

		if (Z_TYPE_P(index) == IS_STRING) {
			zend_symtable_update(Z_ARRVAL_P(tmp), Z_STRVAL_P(index), Z_STRLEN_P(index) + 1, &value, sizeof(zval*), NULL);
		} else if (Z_TYPE_P(index) == IS_LONG) {
			zend_hash_index_update(Z_ARRVAL_P(tmp), Z_LVAL_P(index), &value, sizeof(zval *), NULL);
		} else if (Z_TYPE_P(index) == IS_NULL) {
			zend_hash_next_index_insert(Z_ARRVAL_P(tmp), (void**)&value, sizeof(zval*), NULL);
		}

		if (separated) {
			zephir_update_property_zval(object, property, property_length, tmp TSRMLS_CC);
		}
	}

	return SUCCESS;
}

/**
 * Multiple array-offset update
 */
int zephir_update_property_array_multi(zval *object, const char *property, zend_uint property_length, zval **value TSRMLS_DC, const char *types, int types_length, int types_count, ...) {
	va_list ap;
	zval *tmp_arr;
	int separated = 0;

	if (Z_TYPE_P(object) == IS_OBJECT) {

		zephir_read_property(&tmp_arr, object, property, property_length, PH_NOISY TSRMLS_CC);

		Z_DELREF_P(tmp_arr);

		/** Separation only when refcount > 1 */
		if (Z_REFCOUNT_P(tmp_arr) > 1) {
			if (!Z_ISREF_P(tmp_arr)) {
				zval *new_zv;
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, tmp_arr);
				tmp_arr = new_zv;
				zval_copy_ctor(new_zv);
				Z_SET_REFCOUNT_P(tmp_arr, 0);
				Z_UNSET_ISREF_P(tmp_arr);
				separated = 1;
			}
		}

		/** Convert the value to array if not is an array */
		if (Z_TYPE_P(tmp_arr) != IS_ARRAY) {
			if (separated) {
				convert_to_array(tmp_arr);
			} else {
				zval *new_zv;
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, tmp_arr);
				tmp_arr = new_zv;
				zval_copy_ctor(new_zv);
				Z_SET_REFCOUNT_P(tmp_arr, 0);
				Z_UNSET_ISREF_P(tmp_arr);
				array_init(tmp_arr);
				separated = 1;
			}
		}

		va_start(ap, types_count);
		zephir_array_update_multi_ex(&tmp_arr, value, types, types_length, types_count, ap TSRMLS_CC);
		va_end(ap);

		if (separated) {
			zephir_update_property_zval(object, property, property_length, tmp_arr TSRMLS_CC);
		}
	}

	return SUCCESS;
}

/**
 * Updates an array property using a string index
 */
int zephir_update_property_array_string(zval *object, char *property, unsigned int property_length, char *index, unsigned int index_length, zval *value TSRMLS_DC) {

	zval *tmp;
	int separated = 0;

	if (EXPECTED(Z_TYPE_P(object) == IS_OBJECT)) {

		zephir_read_property(&tmp, object, property, property_length, PH_NOISY_CC);

		Z_DELREF_P(tmp);

		/** Separation only when refcount > 1 */
		if (Z_REFCOUNT_P(tmp) > 1) {
			if (!Z_ISREF_P(tmp)) {
				zval *new_zv;
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, tmp);
				tmp = new_zv;
				zval_copy_ctor(new_zv);
				Z_SET_REFCOUNT_P(tmp, 0);
				Z_UNSET_ISREF_P(tmp);
				separated = 1;
			}
		}

		/** Convert the value to array if not is an array */
		if (Z_TYPE_P(tmp) != IS_ARRAY) {
			if (separated) {
				convert_to_array(tmp);
			} else {
				zval *new_zv;
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, tmp);
				tmp = new_zv;
				zval_copy_ctor(new_zv);
				Z_SET_REFCOUNT_P(tmp, 0);
				Z_UNSET_ISREF_P(tmp);
				array_init(tmp);
				separated = 1;
			}
		}

		Z_ADDREF_P(value);

		zend_hash_update(Z_ARRVAL_P(tmp), index, index_length, &value, sizeof(zval *), NULL);

		if (separated) {
			zephir_update_property_zval(object, property, property_length, tmp TSRMLS_CC);
		}

	}

	return SUCCESS;
}

/**
 * Appends a zval value to an array property
 */
int zephir_update_property_array_append(zval *object, char *property, unsigned int property_length, zval *value TSRMLS_DC) {

	zval *tmp;
	int separated = 0;

	if (Z_TYPE_P(object) != IS_OBJECT) {
		return SUCCESS;
	}

	zephir_read_property(&tmp, object, property, property_length, PH_NOISY_CC);

	Z_DELREF_P(tmp);

	/** Separation only when refcount > 1 */
	if (Z_REFCOUNT_P(tmp) > 1) {
		if (!Z_ISREF_P(tmp)) {
			zval *new_zv;
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, tmp);
			tmp = new_zv;
			zval_copy_ctor(new_zv);
			Z_SET_REFCOUNT_P(tmp, 0);
			Z_UNSET_ISREF_P(tmp);
			separated = 1;
		}
	}

	/** Convert the value to array if not is an array */
	if (Z_TYPE_P(tmp) != IS_ARRAY) {
		if (separated) {
			convert_to_array(tmp);
		} else {
			zval *new_zv;
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, tmp);
			tmp = new_zv;
			zval_copy_ctor(new_zv);
			Z_SET_REFCOUNT_P(tmp, 0);
			Z_UNSET_ISREF_P(tmp);
			array_init(tmp);
			separated = 1;
		}
	}

	Z_ADDREF_P(value);
	add_next_index_zval(tmp, value);

	if (separated) {
		zephir_update_property_zval(object, property, property_length, tmp TSRMLS_CC);
	}

	return SUCCESS;
}

/**
 * Intializes an object property with an empty array
 */
int zephir_update_property_empty_array(zend_class_entry *ce, zval *object, char *property_name, unsigned int property_length TSRMLS_DC) {

	zval *empty_array;
	int res;

	ALLOC_INIT_ZVAL(empty_array);
	array_init(empty_array);

	res = zephir_update_property_zval(object, property_name, property_length, empty_array TSRMLS_CC);
	zval_ptr_dtor(&empty_array);
	return res;
}

int zephir_unset_property(zval* object, const char* name TSRMLS_DC)
{
	if (Z_TYPE_P(object) == IS_OBJECT) {
		zval member;
		zend_class_entry *old_scope;

		INIT_PZVAL(&member);
		ZVAL_STRING(&member, name, 0);
		old_scope = EG(scope);
		EG(scope) = Z_OBJCE_P(object);

		Z_OBJ_HT_P(object)->unset_property(object, &member, 0 TSRMLS_CC);

		EG(scope) = old_scope;

		return SUCCESS;
	}

	return FAILURE;
}

/**
 * Unsets an index in an array property
 */
int zephir_unset_property_array(zval *object, char *property, unsigned int property_length, zval *index TSRMLS_DC) {

	zval *tmp;
	int separated = 0;

	if (Z_TYPE_P(object) == IS_OBJECT) {

		zephir_read_property(&tmp, object, property, property_length, PH_NOISY_CC);
		Z_DELREF_P(tmp);

		/** Separation only when refcount > 1 */
		if (Z_REFCOUNT_P(tmp) > 1) {
			if (!Z_ISREF_P(tmp)) {
				zval *new_zv;
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, tmp);
				tmp = new_zv;
				zval_copy_ctor(new_zv);
				Z_SET_REFCOUNT_P(tmp, 0);
				Z_UNSET_ISREF_P(tmp);
				separated = 1;
			}
		}

		zephir_array_unset(&tmp, index, PH_SEPARATE);

		if (separated) {
			zephir_update_property_zval(object, property, property_length, tmp TSRMLS_CC);
		}
	}

	return SUCCESS;
}

/**
 * Check if a method is implemented on certain object
 */
int zephir_method_exists(const zval *object, const zval *method_name TSRMLS_DC){

	char *lcname = zend_str_tolower_dup(Z_STRVAL_P(method_name), Z_STRLEN_P(method_name));
	int res = zephir_method_exists_ex(object, lcname, Z_STRLEN_P(method_name) + 1 TSRMLS_CC);
	efree(lcname);
	return res;
}

/**
 * Check if method exists on certain object using explicit char param
 *
 * @param object
 * @param method_name
 * @param method_length strlen(method_name)+1
 */
int zephir_method_exists_ex(const zval *object, const char *method_name, unsigned int method_len TSRMLS_DC){

	return zephir_method_quick_exists_ex(object, method_name, method_len, zend_inline_hash_func(method_name, method_len) TSRMLS_CC);
}

/**
 * Check if method exists on certain object using explicit char param
 */
int zephir_method_quick_exists_ex(const zval *object, const char *method_name, unsigned int method_len, unsigned long hash TSRMLS_DC){

	zend_class_entry *ce;

	if (EXPECTED(Z_TYPE_P(object) == IS_OBJECT)) {
		ce = Z_OBJCE_P(object);
	} else {
		if (Z_TYPE_P(object) == IS_STRING) {
			ce = zend_fetch_class(Z_STRVAL_P(object), Z_STRLEN_P(object), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
		} else {
			return FAILURE;
		}
	}

	while (ce) {
		if (zend_hash_quick_exists(&ce->function_table, method_name, method_len, hash)) {
			return SUCCESS;
		}
		ce = ce->parent;
	}

	return FAILURE;
}

zval* zephir_fetch_static_property_ce(zend_class_entry *ce, const char *property, int len TSRMLS_DC) {
	assert(ce != NULL);
	return zend_read_static_property(ce, property, len, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
}

int zephir_read_static_property_ce(zval **result, zend_class_entry *ce, const char *property, int len TSRMLS_DC) {
	zval *tmp;
	tmp = zephir_fetch_static_property_ce(ce, property, len TSRMLS_CC);
	if (tmp) {
		if (!Z_ISREF_P(tmp)) {
			*result = tmp;
			Z_ADDREF_PP(result);
		} else {
			ALLOC_INIT_ZVAL(*result);
			ZVAL_ZVAL(*result, tmp, 1, 0);
		}
		return SUCCESS;
	}
	ALLOC_INIT_ZVAL(*result);
	return FAILURE;
}

static zval **zephir_std_get_static_property(zend_class_entry *ce, const char *property_name, int property_name_len, ulong hash_value, zend_bool silent, zend_property_info **
	property_info TSRMLS_DC)
{
	zend_property_info *temp_property_info;

	if (!hash_value) {
		hash_value = zend_hash_func(property_name, property_name_len + 1);
	}

	if (!property_info || !*property_info) {

		if (UNEXPECTED(zend_hash_quick_find(&ce->properties_info, property_name, property_name_len + 1, hash_value, (void **) &temp_property_info)==FAILURE)) {
			if (!silent) {
				zend_error(E_ERROR, "Access to undeclared static property: %s::$%s", ce->name, property_name);
			}
			return NULL;
		}

		#ifndef ZEPHIR_RELEASE
		/*if (UNEXPECTED(!zend_verify_property_access(temp_property_info, ce TSRMLS_CC))) {
			if (!silent) {
				zend_error(E_ERROR, "Cannot access %s property %s::$%s", zend_visibility_string(temp_property_info->flags), ce->name, property_name);
			}
			return NULL;
		}

		if (UNEXPECTED((temp_property_info->flags & ZEND_ACC_STATIC) == 0)) {
			if (!silent) {
				zend_error(E_ERROR, "Access to undeclared static property: %s::$%s", ce->name, property_name);
			}
			return NULL;
		}*/
		#endif

		zend_update_class_constants(ce TSRMLS_CC);

		if (property_info) {
			*property_info = temp_property_info;
		}

	} else {
		temp_property_info = *property_info;
	}

	if (UNEXPECTED(CE_STATIC_MEMBERS(ce) == NULL) || UNEXPECTED(CE_STATIC_MEMBERS(ce)[temp_property_info->offset] == NULL)) {
		if (!silent) {
			zend_error(E_ERROR, "Access to undeclared static property: %s::$%s", ce->name, property_name);
		}
		return NULL;
	}

	return &CE_STATIC_MEMBERS(ce)[temp_property_info->offset];
}

static int zephir_update_static_property_ex(zend_class_entry *scope, const char *name, int name_length, zval **value, zend_property_info **property_info TSRMLS_DC)
{
	zval **property; zval *tmp, **safe_value;
	zend_zephir_globals_def *zephir_globals_ptr = ZEPHIR_VGLOBAL;
	zend_class_entry *old_scope = EG(scope);

	/**
	 * We have to protect super globals to avoid them make converted to references
	 */
	if (*value == zephir_globals_ptr->global_null) {
		ALLOC_ZVAL(tmp);
		Z_UNSET_ISREF_P(tmp);
		Z_SET_REFCOUNT_P(tmp, 0);
		ZVAL_NULL(tmp);
		safe_value = &tmp;
	} else {
		if (*value == zephir_globals_ptr->global_true) {
			ALLOC_ZVAL(tmp);
			Z_UNSET_ISREF_P(tmp);
			Z_SET_REFCOUNT_P(tmp, 0);
			ZVAL_BOOL(tmp, 1);
			safe_value = &tmp;
		} else {
			if (*value == zephir_globals_ptr->global_false) {
				ALLOC_ZVAL(tmp);
				Z_UNSET_ISREF_P(tmp);
				Z_SET_REFCOUNT_P(tmp, 0);
				ZVAL_BOOL(tmp, 0);
				safe_value = &tmp;
			} else {
				safe_value = value;
			}
		}
	}

	EG(scope) = scope;
	property = zephir_std_get_static_property(scope, name, name_length, zend_inline_hash_func(name, name_length + 1), 0, property_info TSRMLS_CC);
	EG(scope) = old_scope;

	if (!property) {
		return FAILURE;
	} else {
		if (*property != *safe_value) {
			if (PZVAL_IS_REF(*property)) {
				zval_dtor(*property);
				Z_TYPE_PP(property) = Z_TYPE_PP(safe_value);
				(*property)->value = (*safe_value)->value;
				if (Z_REFCOUNT_PP(safe_value) > 0) {
					zval_copy_ctor(*property);
				} else {
					efree(*safe_value);
					*safe_value = NULL;
				}
			} else {
				zval *garbage = *property;

				Z_ADDREF_PP(safe_value);
				if (Z_ISREF_PP(safe_value)) {
					SEPARATE_ZVAL(safe_value);
				}
				*property = *safe_value;
				zval_ptr_dtor(&garbage);
			}
		}
		return SUCCESS;
	}
}

/**
 * Query a static property value from a zend_class_entry
 */
int zephir_read_static_property(zval **result, const char *class_name, unsigned int class_length, char *property_name,
	unsigned int property_length TSRMLS_DC) {
	zend_class_entry **ce;
	if (zend_lookup_class(class_name, class_length, &ce TSRMLS_CC) == SUCCESS) {
		return zephir_read_static_property_ce(result, *ce, property_name, property_length TSRMLS_CC);
	}
	return FAILURE;
}

int zephir_update_static_property_ce(zend_class_entry *ce, const char *name, int len, zval **value TSRMLS_DC) {
	assert(ce != NULL);
	return zephir_update_static_property_ex(ce, name, len, value, NULL TSRMLS_CC);
}

int zephir_update_static_property_ce_cache(zend_class_entry *ce, const char *name, int len, zval **value, zend_property_info **property_info TSRMLS_DC) {
	assert(ce != NULL);
	return zephir_update_static_property_ex(ce, name, len, value, property_info TSRMLS_CC);
}

/*
 * Multiple array-offset update
 */
int zephir_update_static_property_array_multi_ce(zend_class_entry *ce, const char *property, zend_uint property_length, zval **value TSRMLS_DC, const char *types, int types_length, int types_count, ...) {

	va_list ap;
	zval *tmp_arr;
	int separated = 0;

	tmp_arr = zephir_fetch_static_property_ce(ce, property, property_length TSRMLS_CC);
	if (!tmp_arr) {
		ALLOC_INIT_ZVAL(tmp_arr);
		array_init(tmp_arr);
		separated = 1;
	}

	/** Separation only when refcount > 1 */
	if (Z_REFCOUNT_P(tmp_arr) > 1) {
		if (!Z_ISREF_P(tmp_arr)) {
			zval *new_zv;
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, tmp_arr);
			tmp_arr = new_zv;
			zval_copy_ctor(new_zv);
			Z_SET_REFCOUNT_P(tmp_arr, 0);
			Z_UNSET_ISREF_P(tmp_arr);
			separated = 1;
		}
	}

	/** Convert the value to array if not is an array */
	if (Z_TYPE_P(tmp_arr) != IS_ARRAY) {
		if (separated) {
			convert_to_array(tmp_arr);
		} else {
			zval *new_zv;
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, tmp_arr);
			tmp_arr = new_zv;
			zval_copy_ctor(new_zv);
			Z_SET_REFCOUNT_P(tmp_arr, 0);
			Z_UNSET_ISREF_P(tmp_arr);
			array_init(tmp_arr);
			separated = 1;
		}
	}

	va_start(ap, types_count);
	zephir_array_update_multi_ex(&tmp_arr, value, types, types_length, types_count, ap TSRMLS_CC);
	va_end(ap);

	if (separated) {
		zephir_update_static_property_ce(ce, property, property_length, &tmp_arr TSRMLS_CC);
	}

	return SUCCESS;
}

/**
 * Update a static property
 */
int zephir_update_static_property(const char *class_name, unsigned int class_length, char *name, unsigned int name_length, zval **value TSRMLS_DC){
	zend_class_entry **ce;
	if (zend_lookup_class(class_name, class_length, &ce TSRMLS_CC) == SUCCESS) {
		return zephir_update_static_property_ce(*ce, name, name_length, value TSRMLS_CC);
	}
	return FAILURE;
}

int zephir_read_class_property(zval **result, int type, const char *property, int len TSRMLS_DC) {
	zend_class_entry *ce;

	type |= (ZEND_FETCH_CLASS_SILENT | ZEND_FETCH_CLASS_NO_AUTOLOAD);
	type &= ZEND_FETCH_CLASS_MASK;
	ce    = zend_fetch_class(NULL, 0, type TSRMLS_CC);

	if (EXPECTED(ce != NULL)) {
		return zephir_read_static_property_ce(result, ce, property, len TSRMLS_CC);
	}

	return FAILURE;
}

/**
 * Creates a new instance dynamically. Call constructor without parameters
 */
int zephir_create_instance(zval *return_value, const zval *class_name TSRMLS_DC){

	zend_class_entry *ce;

	if (Z_TYPE_P(class_name) != IS_STRING) {
		zephir_throw_exception_string(spl_ce_RuntimeException, SL("Invalid class name") TSRMLS_CC);
		return FAILURE;
	}

	ce = zend_fetch_class(Z_STRVAL_P(class_name), Z_STRLEN_P(class_name), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
	if (!ce) {
		ZVAL_NULL(return_value);
		return FAILURE;
	}

	object_init_ex(return_value, ce);
	if (zephir_has_constructor_ce(ce)) {
		return zephir_call_class_method_aparams(NULL, ce, zephir_fcall_method, return_value, SL("__construct"), NULL, 0, 0, NULL TSRMLS_CC);
	}

	return SUCCESS;
}

/**
 * Creates a new instance dynamically calling constructor with parameters
 */
int zephir_create_instance_params(zval *return_value, const zval *class_name, zval *params TSRMLS_DC){

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

	ce = zend_fetch_class(Z_STRVAL_P(class_name), Z_STRLEN_P(class_name), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
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
			HashPosition pos;
			zval **item;
			int i = 0;

			if (EXPECTED(param_count <= 10)) {
				params_ptr = static_params;
			} else {
				params_arr = emalloc(param_count * sizeof(zval*));
				params_ptr = params_arr;
			}

			for (
				zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(params), &pos);
				zend_hash_get_current_data_ex(Z_ARRVAL_P(params), (void**) &item, &pos) == SUCCESS;
				zend_hash_move_forward_ex(Z_ARRVAL_P(params), &pos), ++i
			) {
				params_ptr[i] = *item;
			}
		} else {
			params_ptr = NULL;
		}

		outcome = zephir_call_class_method_aparams(NULL, ce, zephir_fcall_method, return_value, SL("__construct"), NULL, 0, param_count, params_ptr TSRMLS_CC);

		if (UNEXPECTED(params_arr != NULL)) {
			efree(params_arr);
		}
	}

	return outcome;
}

/**
 * Increments an object property
 */
int zephir_property_incr(zval *object, char *property_name, unsigned int property_length TSRMLS_DC){

	zval *tmp = NULL;
	zend_class_entry *ce;
	int separated = 0;

	if (Z_TYPE_P(object) != IS_OBJECT) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Attempt to assign property of non-object");
		return FAILURE;
	}

	ce = Z_OBJCE_P(object);
	if (ce->parent) {
		ce = zephir_lookup_class_ce(ce, property_name, property_length TSRMLS_CC);
	}

	zephir_read_property(&tmp, object, property_name, property_length, 0 TSRMLS_CC);
	if (tmp) {

		Z_DELREF_P(tmp);

		/** Separation only when refcount > 1 */
		if (Z_REFCOUNT_P(tmp) > 1) {
			if (!Z_ISREF_P(tmp)) {
				zval *new_zv;
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, tmp);
				tmp = new_zv;
				zval_copy_ctor(new_zv);
				Z_SET_REFCOUNT_P(tmp, 0);
				Z_UNSET_ISREF_P(tmp);
				separated = 1;
			}
		}

		zephir_increment(tmp);

		if (separated) {
			zephir_update_property_zval(object, property_name, property_length, tmp TSRMLS_CC);
		}
	}

	return SUCCESS;
}

/**
 * Decrements an object property
 */
int zephir_property_decr(zval *object, char *property_name, unsigned int property_length TSRMLS_DC){

	zval *tmp = NULL;
	zend_class_entry *ce;
	int separated = 0;

	if (Z_TYPE_P(object) != IS_OBJECT) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Attempt to assign property of non-object");
		return FAILURE;
	}

	ce = Z_OBJCE_P(object);
	if (ce->parent) {
		ce = zephir_lookup_class_ce(ce, property_name, property_length TSRMLS_CC);
	}

	zephir_read_property(&tmp, object, property_name, property_length, 0 TSRMLS_CC);
	if (tmp) {

		Z_DELREF_P(tmp);

		/** Separation only when refcount > 1 */
		if (Z_REFCOUNT_P(tmp) > 1) {
			if (!Z_ISREF_P(tmp)) {
				zval *new_zv;
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, tmp);
				tmp = new_zv;
				zval_copy_ctor(new_zv);
				Z_SET_REFCOUNT_P(tmp, 0);
				Z_UNSET_ISREF_P(tmp);
				separated = 1;
			}
		}

		zephir_decrement(tmp);

		if (separated) {
			zephir_update_property_zval(object, property_name, property_length, tmp TSRMLS_CC);
		}
	}

	return SUCCESS;
}

/**
 * Fetches a property using a const char
 */
int zephir_fetch_property(zval **result, zval *object, const char *property_name, zend_uint property_length, int silent TSRMLS_DC) {

	if (zephir_isset_property(object, property_name, property_length + 1 TSRMLS_CC)) {
		zephir_read_property(result, object, property_name, property_length, 0 TSRMLS_CC);
		return 1;
	}

	*result = ZEPHIR_GLOBAL(global_null);
	Z_ADDREF_P(*result);
	return 0;
}

/**
 * Fetches a property using a zval property
 */
int zephir_fetch_property_zval(zval **result, zval *object, zval *property, int silent TSRMLS_DC) {

	if (UNEXPECTED(Z_TYPE_P(property) != IS_STRING)) {
		*result = ZEPHIR_GLOBAL(global_null);
		Z_ADDREF_P(*result);
		return 0;
	}

	if (zephir_isset_property(object, Z_STRVAL_P(property), Z_STRLEN_P(property) + 1 TSRMLS_CC)) {
		zephir_read_property(result, object, Z_STRVAL_P(property), Z_STRLEN_P(property), 0 TSRMLS_CC);
		return 1;
	}

	*result = ZEPHIR_GLOBAL(global_null);
	Z_ADDREF_P(*result);
	return 0;
}

/**
 * Creates a closure
 */
int zephir_create_closure_ex(zval *return_value, zval *this_ptr, zend_class_entry *ce, const char *method_name, zend_uint method_length TSRMLS_DC) {

	zend_function *function_ptr;

	if (zend_hash_find(&ce->function_table, method_name, method_length, (void**) &function_ptr) == FAILURE) {
		ZVAL_NULL(return_value);
		return FAILURE;
	}

	zend_create_closure(return_value, function_ptr, ce, this_ptr TSRMLS_CC);
	return SUCCESS;
}

void zephir_free_object_storage(void *object TSRMLS_DC)
{
	zend_object_std_dtor((zend_object*)object TSRMLS_CC);
	efree(object);
}
