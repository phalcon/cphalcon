
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

#ifdef PHP_WIN32
#include "php_string.h"
#endif

#include "php_phalcon.h"
#include "phalcon.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/operators.h"

/**
 * Reads class constant from string name and returns its value
 */
int phalcon_get_class_constant(zval *return_value, zend_class_entry *ce, char *constant_name, unsigned int constant_length TSRMLS_DC) {

	zval **result_ptr;

	if (phalcon_hash_find(&ce->constants_table, constant_name, constant_length, (void **) &result_ptr) != SUCCESS) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Undefined class constant '%s::%s'", ce->name, constant_name);
		phalcon_memory_restore_stack(TSRMLS_C);
		return FAILURE;
	}

	ZVAL_ZVAL(return_value, *result_ptr, 1, 0);
	return SUCCESS;
}

/**
 * Check if class is instance of
 */
int phalcon_instance_of(zval *result, const zval *object, const zend_class_entry *ce TSRMLS_DC) {

	if (Z_TYPE_P(object) != IS_OBJECT) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "instanceof expects an object instance, constant given");
		phalcon_memory_restore_stack(TSRMLS_C);
		return FAILURE;
	}

	ZVAL_BOOL(result, instanceof_function(Z_OBJCE_P(object), ce TSRMLS_CC));
	return SUCCESS;
}

/**
 * Check if an object is instance of a class
 */
int phalcon_is_instance_of(zval *object, const char *class_name, unsigned int class_length TSRMLS_DC) {

	zend_class_entry *ce;

	if (Z_TYPE_P(object) == IS_OBJECT) {
		ce = Z_OBJCE_P(object);
		if (ce->name_length == class_length) {
			return !zend_binary_strcasecmp(ce->name, ce->name_length, class_name, class_length);
		}
	}

	return 0;
}

/**
 * Returns a class name into a zval result
 */
void phalcon_get_class(zval *result, zval *object, int lower TSRMLS_DC) {

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
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "phalcon_get_class expects an object");
	}
}

/**
 * Returns a class name into a zval result
 */
void phalcon_get_class_ns(zval *result, zval *object, int lower TSRMLS_DC) {

	int found = 0;
	zend_class_entry *ce;
	unsigned int i, class_length;
	const char *cursor, *class_name;

	if (Z_TYPE_P(object) != IS_OBJECT) {
		if (Z_TYPE_P(object) != IS_STRING) {
			ZVAL_NULL(result);
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "phalcon_get_class_ns expects an object");
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
void phalcon_get_ns_class(zval *result, zval *object, int lower TSRMLS_DC) {

	zend_class_entry *ce;
	int found = 0;
	unsigned int i, j, class_length;
	const char *cursor, *class_name;

	if (Z_TYPE_P(object) != IS_OBJECT) {
		if (Z_TYPE_P(object) != IS_STRING) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "phalcon_get_ns_class expects an object");
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
void phalcon_get_called_class(zval *return_value TSRMLS_DC) {

	if (EG(called_scope)) {
		RETURN_STRINGL(EG(called_scope)->name, EG(called_scope)->name_length, 1);
	}

	if (!EG(scope))  {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "phalcon_get_called_class() called from outside a class");
	}

}

/**
 * Fetches a zend class entry from a zval value
 */
zend_class_entry *phalcon_fetch_class(const zval *class_name TSRMLS_DC) {

	if (Z_TYPE_P(class_name) == IS_STRING) {
		return zend_fetch_class(Z_STRVAL_P(class_name), Z_STRLEN_P(class_name), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
	}

	php_error_docref(NULL TSRMLS_CC, E_WARNING, "class name must be a string");
	return zend_fetch_class("stdclass", strlen("stdclass"), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
}

/**
 * Checks if a class exist
 */
int phalcon_class_exists(const zval *class_name TSRMLS_DC) {

	zend_class_entry **ce;

	if (Z_TYPE_P(class_name) == IS_STRING) {
		if (zend_lookup_class(Z_STRVAL_P(class_name), Z_STRLEN_P(class_name), &ce TSRMLS_CC) == SUCCESS) {
#if PHP_VERSION_ID < 50400
			return (((*ce)->ce_flags & ZEND_ACC_INTERFACE) == 0);
#else
			return ((*ce)->ce_flags & (ZEND_ACC_INTERFACE | (ZEND_ACC_TRAIT - ZEND_ACC_EXPLICIT_ABSTRACT_CLASS))) == 0;
#endif
		}
		return 0;
	}

	php_error_docref(NULL TSRMLS_CC, E_WARNING, "class name must be a string");
	return 0;
}

/**
 * Clones an object from obj to destination
 */
int phalcon_clone(zval *destination, zval *obj TSRMLS_DC) {

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

	if (status == FAILURE){
		phalcon_memory_restore_stack(TSRMLS_C);
	}

	return status;
}

/**
 * Checks if property exists on object
 */
int phalcon_isset_property(zval *object, const char *property_name, unsigned int property_length TSRMLS_DC) {

	unsigned long hash;

	hash = zend_inline_hash_func(property_name, property_length);

	if (Z_TYPE_P(object) == IS_OBJECT) {
		if (phalcon_hash_quick_exists(&Z_OBJCE_P(object)->properties_info, property_name, property_length, hash)) {
			return 1;
		} else {
			return phalcon_hash_quick_exists(Z_OBJ_HT_P(object)->get_properties(object TSRMLS_CC), property_name, property_length, hash);
		}
	}

	return 0;
}

/**
 * Checks if property exists on object
 */
int phalcon_isset_property_quick(zval *object, const char *property_name, unsigned int property_length, unsigned long hash TSRMLS_DC) {

	if (Z_TYPE_P(object) == IS_OBJECT) {
		if (likely(phalcon_hash_quick_exists(&Z_OBJCE_P(object)->properties_info, property_name, property_length, hash))) {
			return 1;
		} else {
			return phalcon_hash_quick_exists(Z_OBJ_HT_P(object)->get_properties(object TSRMLS_CC), property_name, property_length, hash);
		}
	}

	return 0;
}

/**
 * Checks if string property exists on object
 */
int phalcon_isset_property_zval(zval *object, const zval *property TSRMLS_DC) {

	unsigned long hash;

	if (Z_TYPE_P(object) == IS_OBJECT) {
		if (Z_TYPE_P(property) == IS_STRING) {

			hash = zend_inline_hash_func(Z_STRVAL_P(property), Z_STRLEN_P(property) + 1);

			if (likely(phalcon_hash_quick_exists(&Z_OBJCE_P(object)->properties_info, Z_STRVAL_P(property), Z_STRLEN_P(property) + 1, hash))) {
				return 1;
			} else {
				return phalcon_hash_quick_exists(Z_OBJ_HT_P(object)->get_properties(object TSRMLS_CC), Z_STRVAL_P(property), Z_STRLEN_P(property) + 1, hash);
			}
		}
	}

	return 0;
}

/**
 * Lookup exact class where a property is defined
 *
 */
static inline zend_class_entry *phalcon_lookup_class_ce(zend_class_entry *ce, char *property_name, unsigned int property_length TSRMLS_DC) {

	zend_class_entry *original_ce;
	unsigned long hash;

	hash = zend_inline_hash_func(property_name, property_length + 1);

	original_ce = ce;
	while (ce) {
		if (phalcon_hash_quick_exists(&ce->properties_info, property_name, property_length + 1, hash)) {
			return ce;
		}
		ce = ce->parent;
	}
	return original_ce;
}

/**
 * Lookup exact class where a property is defined (preallocated key)
 *
 */
static inline zend_class_entry *phalcon_lookup_class_ce_quick(zend_class_entry *ce, char *property_name, unsigned int property_length, unsigned long hash TSRMLS_DC) {

	zend_class_entry *original_ce;

	original_ce = ce;
	while (ce) {
		if (phalcon_hash_quick_exists(&ce->properties_info, property_name, property_length + 1, hash)) {
			return ce;
		}
		ce = ce->parent;
	}
	return original_ce;
}

/**
 * Reads a property from an object
 */
int phalcon_read_property(zval **result, zval *object, char *property_name, unsigned int property_length, int silent TSRMLS_DC) {

	zval *property;
	zend_class_entry *ce;

	if (unlikely(Z_TYPE_P(object) != IS_OBJECT)) {
		if (silent == PH_NOISY) {
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Trying to get property of non-object");
		}

		ALLOC_INIT_ZVAL(*result);
		ZVAL_NULL(*result);
		return FAILURE;
	}

	ce = Z_OBJCE_P(object);
	if (ce->parent) {
		ce = phalcon_lookup_class_ce(ce, property_name, property_length TSRMLS_CC);
	}

	zend_class_entry *old_scope = EG(scope);
	EG(scope) = ce;

	if (!Z_OBJ_HT_P(object)->read_property) {
#if PHP_VERSION_ID < 50400
		char *class_name;
#else
		const char *class_name;
#endif
		zend_uint class_name_len;

		zend_get_object_classname(object, &class_name, &class_name_len TSRMLS_CC);
		zend_error(E_CORE_ERROR, "Property %s of class %s cannot be read", property_name, class_name);
	}

	MAKE_STD_ZVAL(property);
	ZVAL_STRINGL(property, property_name, property_length, 0);

#if PHP_VERSION_ID < 50400
	*result = Z_OBJ_HT_P(object)->read_property(object, property, silent ? BP_VAR_IS : BP_VAR_R TSRMLS_CC);
#else
	*result = Z_OBJ_HT_P(object)->read_property(object, property, silent ? BP_VAR_IS : BP_VAR_R, 0 TSRMLS_CC);
#endif

	Z_ADDREF_PP(result);
	ZVAL_NULL(property);
	zval_ptr_dtor(&property);

	EG(scope) = old_scope;
	return SUCCESS;
}

/**
 * Reads a property from this_ptr
 * Variables must be defined in the class definition. This function ignores magic methods or dynamic properties
 */
int phalcon_read_property_this(zval **result, zval *object, char *property_name, unsigned int property_length, int silent TSRMLS_DC) {

	zval **zv;
	zend_object *zobj;
	zend_property_info *property_info;
	zend_class_entry *ce, *old_scope;

	if (likely(Z_TYPE_P(object) == IS_OBJECT)) {

		ce = Z_OBJCE_P(object);
		if (ce->parent) {
			ce = phalcon_lookup_class_ce(ce, property_name, property_length TSRMLS_CC);
		}

		old_scope = EG(scope);
		EG(scope) = ce;

		zobj = zend_objects_get_address(object TSRMLS_CC);

		if (phalcon_hash_find(&ce->properties_info, property_name, property_length + 1, (void **) &property_info) == SUCCESS) {
			assert(property_info != NULL);

			#if PHP_VERSION_ID < 50400

			if (phalcon_hash_quick_find(zobj->properties, property_info->name, property_info->name_length + 1, property_info->h, (void **) &zv) == SUCCESS) {
				*result = *zv;
				Z_ADDREF_PP(result);
				EG(scope) = old_scope;
				return SUCCESS;
			}

			#else

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
			} else if (UNEXPECTED(phalcon_hash_quick_find(zobj->properties, property_info->name, property_info->name_length+1, property_info->h, (void **) &zv) == FAILURE)) {
				flag = 2;
			} else {
				flag = 0;
			}

			if (unlikely(flag) && zobj->properties) {
				if (
					(flag == 2 || phalcon_hash_quick_find(zobj->properties, property_info->name, property_info->name_length+1, property_info->h, (void **) &zv) == FAILURE)
					&& zv && *zv
				) {
					flag = 0;
				}
			}

			if (likely(!flag)) {
				*result = *zv;
				Z_ADDREF_PP(result);
				EG(scope) = old_scope;
				return SUCCESS;
			}

			#endif

		}

		EG(scope) = old_scope;

	} else {
		if (silent == PH_NOISY) {
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Trying to get property of non-object");
		}
	}

	ALLOC_INIT_ZVAL(*result);
	ZVAL_NULL(*result);

	return FAILURE;
}

/**
 * Reads a property from this_ptr (with pre-calculated key)
 * Variables must be defined in the class definition. This function ignores magic methods or dynamic properties
 */
int phalcon_read_property_this_quick(zval **result, zval *object, char *property_name, unsigned int property_length, unsigned long key, int silent TSRMLS_DC) {

	zval **zv = NULL;
	zend_object *zobj;
	zend_property_info *property_info;
	zend_class_entry *ce, *old_scope;

	if (likely(Z_TYPE_P(object) == IS_OBJECT)) {

		ce = Z_OBJCE_P(object);
		if (ce->parent) {
			ce = phalcon_lookup_class_ce_quick(ce, property_name, property_length, key TSRMLS_CC);
		}

		old_scope = EG(scope);
		EG(scope) = ce;

		zobj = zend_objects_get_address(object TSRMLS_CC);

		if (phalcon_hash_quick_find(&ce->properties_info, property_name, property_length + 1, key, (void **) &property_info) == SUCCESS) {

			#if PHP_VERSION_ID < 50400

			if (phalcon_hash_quick_find(zobj->properties, property_info->name, property_info->name_length + 1, property_info->h, (void **) &zv) == SUCCESS) {
				*result = *zv;
				Z_ADDREF_PP(result);
				EG(scope) = old_scope;
				return SUCCESS;
			}

			#else

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
			} else if (UNEXPECTED(phalcon_hash_quick_find(zobj->properties, property_info->name, property_info->name_length+1, property_info->h, (void **) &zv) == FAILURE)) {
				flag = 2;
			} else {
				flag = 0;
			}

			if (unlikely(flag) && zobj->properties) {
				if (
					(flag == 2 || phalcon_hash_quick_find(zobj->properties, property_info->name, property_info->name_length+1, property_info->h, (void **) &zv) == FAILURE)
					&& zv && *zv
				) {
					flag = 0;
				}
			}

			if (likely(!flag)) {
				*result = *zv;
				Z_ADDREF_PP(result);
				EG(scope) = old_scope;
				return SUCCESS;
			}

			#endif

		}

		EG(scope) = old_scope;

	} else {
		if (silent == PH_NOISY) {
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Trying to get property of non-object");
		}
	}

	ALLOC_INIT_ZVAL(*result);
	ZVAL_NULL(*result);

	return FAILURE;
}

/**
 * Returns an object's member
 */
int phalcon_return_property(zval *return_value, zval *object, char *property_name, unsigned int property_length TSRMLS_DC) {

	zval **zv;
	zend_object *zobj;
	zend_property_info *property_info;
	zend_class_entry *ce, *old_scope;

	if (likely(Z_TYPE_P(object) == IS_OBJECT)) {

		ce = Z_OBJCE_P(object);
		if (ce->parent) {
			ce = phalcon_lookup_class_ce(ce, property_name, property_length TSRMLS_CC);
		}

		old_scope = EG(scope);
		EG(scope) = ce;

		zobj = zend_objects_get_address(object TSRMLS_CC);

		if (phalcon_hash_find(&ce->properties_info, property_name, property_length + 1, (void **) &property_info) == SUCCESS) {

			#if PHP_VERSION_ID < 50400

			if (phalcon_hash_quick_find(zobj->properties, property_info->name, property_info->name_length+1, property_info->h, (void **) &zv) == SUCCESS) {

				EG(scope) = old_scope;

				ZVAL_ZVAL(return_value, *zv, 1, 0);
				return SUCCESS;
			}

			#else

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
			} else if (UNEXPECTED(phalcon_hash_quick_find(zobj->properties, property_info->name, property_info->name_length+1, property_info->h, (void **) &zv) == FAILURE)) {
				flag = 2;
			} else {
				flag = 0;
			}

			if (unlikely(flag) && zobj->properties) {
				if (
					(flag == 2 || phalcon_hash_quick_find(zobj->properties, property_info->name, property_info->name_length+1, property_info->h, (void **) &zv) == FAILURE)
					&& zv && *zv
				) {
					flag = 0;
				}
			}

			if (likely(!flag)) {
				EG(scope) = old_scope;
				ZVAL_ZVAL(return_value, *zv, 1, 0);
				return SUCCESS;
			}

			#endif

		}

		EG(scope) = old_scope;

	} else {
		php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Trying to get property of non-object");
	}

	ZVAL_NULL(return_value);
	return FAILURE;
}

/**
 * Returns an object's member
 */
int phalcon_return_property_quick(zval *return_value, zval *object, char *property_name, unsigned int property_length, unsigned long key TSRMLS_DC) {

	zval **zv;
	zend_object *zobj;
	zend_property_info *property_info;
	zend_class_entry *ce, *old_scope;

	if (likely(Z_TYPE_P(object) == IS_OBJECT)) {

		ce = Z_OBJCE_P(object);
		if (ce->parent) {
			ce = phalcon_lookup_class_ce_quick(ce, property_name, property_length, key TSRMLS_CC);
		}

		old_scope = EG(scope);
		EG(scope) = ce;

		zobj = zend_objects_get_address(object TSRMLS_CC);

		if (phalcon_hash_quick_find(&ce->properties_info, property_name, property_length + 1, key, (void **) &property_info) == SUCCESS) {

			#if PHP_VERSION_ID < 50400

			if (phalcon_hash_quick_find(zobj->properties, property_info->name, property_info->name_length+1, property_info->h, (void **) &zv) == SUCCESS) {

				EG(scope) = old_scope;

				ZVAL_ZVAL(return_value, *zv, 1, 0);
				return SUCCESS;
			}

			#else

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
			} else if (UNEXPECTED(phalcon_hash_quick_find(zobj->properties, property_info->name, property_info->name_length+1, property_info->h, (void **) &zv) == FAILURE)) {
				flag = 2;
			} else {
				flag = 0;
			}

			if (unlikely(flag) && zobj->properties) {
				if (
					(flag == 2 || phalcon_hash_quick_find(zobj->properties, property_info->name, property_info->name_length+1, property_info->h, (void **) &zv) == FAILURE)
					&& zv && *zv
				) {
					flag = 0;
				}
			}

			if (likely(!flag)) {
				EG(scope) = old_scope;
				ZVAL_ZVAL(return_value, *zv, 1, 0);
				return SUCCESS;
			}

			#endif

		}

		EG(scope) = old_scope;

	} else {
		php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Trying to get property of non-object");
	}

	ZVAL_NULL(return_value);
	return FAILURE;
}

/**
 * Reads a property from an object
 */
int phalcon_read_property_zval(zval **result, zval *object, zval *property, int silent TSRMLS_DC) {

	if (unlikely(Z_TYPE_P(property) != IS_STRING)) {

		if (silent == PH_NOISY) {
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Cannot access empty property %d", Z_TYPE_P(property));
		}

		ALLOC_INIT_ZVAL(*result);
		ZVAL_NULL(*result);
		return FAILURE;
	}

	return phalcon_read_property(result, object, Z_STRVAL_P(property), Z_STRLEN_P(property), silent TSRMLS_CC);
}

/**
 * Checks whether obj is an object and updates property with long value
 */
int phalcon_update_property_long(zval *object, char *property_name, unsigned int property_length, long value TSRMLS_DC) {

	zval *v;

	ALLOC_ZVAL(v);
	Z_UNSET_ISREF_P(v);
	Z_SET_REFCOUNT_P(v, 0);
	ZVAL_LONG(v, value);

	return phalcon_update_property_zval(object, property_name, property_length, v TSRMLS_CC);
}

/**
 * Checks whether obj is an object and updates property with string value
 */
int phalcon_update_property_string(zval *object, char *property_name, unsigned int property_length, char *str, unsigned int str_length TSRMLS_DC) {

	zval *value;
	int res;

	ALLOC_ZVAL(value);
	Z_UNSET_ISREF_P(value);
	Z_SET_REFCOUNT_P(value, 0);
	ZVAL_STRINGL(value, str, str_length, 1);

	res = phalcon_update_property_zval(object, property_name, property_length, value TSRMLS_CC);
	if (res == SUCCESS) {
		return SUCCESS;
	}

	Z_ADDREF_P(value);
	zval_ptr_dtor(&value);
	return FAILURE;
}

/**
 * Checks whether obj is an object and updates property with bool value
 */
int phalcon_update_property_bool(zval *object, char *property_name, unsigned int property_length, int value TSRMLS_DC) {

	zval *v;

	ALLOC_ZVAL(v);
	Z_UNSET_ISREF_P(v);
	Z_SET_REFCOUNT_P(v, 0);
	ZVAL_BOOL(v, value ? 1 : 0);

	return phalcon_update_property_zval(object, property_name, property_length, v TSRMLS_CC);
}

/**
 * Checks whether obj is an object and updates property with null value
 */
int phalcon_update_property_null(zval *object, char *property_name, unsigned int property_length TSRMLS_DC) {

	zval *v;

	ALLOC_ZVAL(v);
	Z_UNSET_ISREF_P(v);
	Z_SET_REFCOUNT_P(v, 0);
	ZVAL_NULL(v);

	return phalcon_update_property_zval(object, property_name, property_length, v TSRMLS_CC);
}

/**
 * Checks whether obj is an object and updates property with another zval
 */
int phalcon_update_property_zval(zval *object, char *property_name, unsigned int property_length, zval *value TSRMLS_DC){

	zend_class_entry *ce;
	zval *property;
	zend_class_entry *old_scope = EG(scope);

	if (Z_TYPE_P(object) != IS_OBJECT) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Attempt to assign property of non-object");
		return FAILURE;
	}

	ce = Z_OBJCE_P(object);
	if (ce->parent) {
		ce = phalcon_lookup_class_ce(ce, property_name, property_length TSRMLS_CC);
	}

	EG(scope) = ce;

	if (!Z_OBJ_HT_P(object)->write_property) {
#if PHP_VERSION_ID < 50400
		char *class_name;
#else
		const char *class_name;
#endif
		zend_uint class_name_len;

		zend_get_object_classname(object, &class_name, &class_name_len TSRMLS_CC);
		zend_error(E_CORE_ERROR, "Property %s of class %s cannot be updated", property_name, class_name);
	}

	MAKE_STD_ZVAL(property);
	ZVAL_STRINGL(property, property_name, property_length, 0);

#if PHP_VERSION_ID < 50400
	Z_OBJ_HT_P(object)->write_property(object, property, value TSRMLS_CC);
#else
	Z_OBJ_HT_P(object)->write_property(object, property, value, 0 TSRMLS_CC);
#endif

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
 * Updates properties on this_ptr
 * Variables must be defined in the class definition. This function ignores magic methods or dynamic properties
 */
int phalcon_update_property_this(zval *object, char *property_name, unsigned int property_length, zval *value TSRMLS_DC){

	zend_class_entry *ce, *old_scope;

	if (unlikely(Z_TYPE_P(object) != IS_OBJECT)) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Attempt to assign property of non-object");
		return FAILURE;
	}

	ce = Z_OBJCE_P(object);
	if (ce->parent) {
		ce = phalcon_lookup_class_ce(ce, property_name, property_length TSRMLS_CC);
	}

	old_scope = EG(scope);
	EG(scope) = ce;

	#if PHP_VERSION_ID < 50400

	{
		zval *property;

		if (!Z_OBJ_HT_P(object)->write_property) {
			EG(scope) = old_scope;
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Property %s of class %s cannot be updated", property_name, ce->name);
			return FAILURE;
		}

		MAKE_STD_ZVAL(property);
		ZVAL_STRINGL(property, property_name, property_length, 0);

		Z_OBJ_HT_P(object)->write_property(object, property, value TSRMLS_CC);

		ZVAL_NULL(property);
		zval_ptr_dtor(&property);
	}

	#else

	{
		zend_object *zobj;
		zval **variable_ptr;
		zend_property_info *property_info;

		zobj = zend_objects_get_address(object TSRMLS_CC);

		if (phalcon_hash_find(&ce->properties_info, property_name, property_length + 1, (void **) &property_info) == SUCCESS) {
			assert(property_info != NULL);

			/** This is as zend_std_write_property, but we're not interesed in validate properties visibility */
			if (property_info->offset >= 0 ? (zobj->properties ? ((variable_ptr = (zval**) zobj->properties_table[property_info->offset]) != NULL) : (*(variable_ptr = &zobj->properties_table[property_info->offset]) != NULL)) : (EXPECTED(zobj->properties != NULL) && EXPECTED(phalcon_hash_quick_find(zobj->properties, property_info->name, property_info->name_length + 1, property_info->h, (void **) &variable_ptr) == SUCCESS))) {

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
		}
	}

	#endif

	EG(scope) = old_scope;

	return SUCCESS;
}

/**
 * Updates properties on this_ptr (quick)
 * Variables must be defined in the class definition. This function ignores magic methods or dynamic properties
 */
int phalcon_update_property_this_quick(zval *object, char *property_name, unsigned int property_length, zval *value, unsigned long key TSRMLS_DC){

	zend_class_entry *ce, *old_scope;

	if (unlikely(Z_TYPE_P(object) != IS_OBJECT)) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Attempt to assign property of non-object");
		return FAILURE;
	}

	ce = Z_OBJCE_P(object);
	if (ce->parent) {
		ce = phalcon_lookup_class_ce_quick(ce, property_name, property_length, key TSRMLS_CC);
	}

	old_scope = EG(scope);
	EG(scope) = ce;

	#if PHP_VERSION_ID < 50400

	{
		zval *property;

		if (!Z_OBJ_HT_P(object)->write_property) {
			EG(scope) = old_scope;
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Property %s of class %s cannot be updated", property_name, ce->name);
			return FAILURE;
		}

		MAKE_STD_ZVAL(property);
		ZVAL_STRINGL(property, property_name, property_length, 0);

		Z_OBJ_HT_P(object)->write_property(object, property, value TSRMLS_CC);

		ZVAL_NULL(property);
		zval_ptr_dtor(&property);
	}

	#else

	{
		zend_object *zobj;
		zval **variable_ptr;
		zend_property_info *property_info;

		zobj = zend_objects_get_address(object TSRMLS_CC);

		if (phalcon_hash_quick_find(&ce->properties_info, property_name, property_length + 1, key, (void **) &property_info) == SUCCESS) {
			assert(property_info != NULL);

			/** This is as zend_std_write_property, but we're not interesed in validate properties visibility */
			if (property_info->offset >= 0 ? (zobj->properties ? ((variable_ptr = (zval**) zobj->properties_table[property_info->offset]) != NULL) : (*(variable_ptr = &zobj->properties_table[property_info->offset]) != NULL)) : (EXPECTED(zobj->properties != NULL) && EXPECTED(phalcon_hash_quick_find(zobj->properties, property_info->name, property_info->name_length + 1, property_info->h, (void **) &variable_ptr) == SUCCESS))) {

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
		}
	}

	#endif

	EG(scope) = old_scope;

	return SUCCESS;
}

/**
 * Checks whether obj is an object and updates zval property with another zval
 */
int phalcon_update_property_zval_zval(zval *object, zval *property, zval *value TSRMLS_DC){

	if (Z_TYPE_P(property) != IS_STRING) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Property should be string");
		return FAILURE;
	}

	return phalcon_update_property_zval(object, Z_STRVAL_P(property), Z_STRLEN_P(property), value TSRMLS_CC);
}

/**
 * Updates an array property
 */
int phalcon_update_property_array(zval *object, char *property, unsigned int property_length, zval *index, zval *value TSRMLS_DC) {

	zval *tmp;
	int separated = 0;

	if (likely(Z_TYPE_P(object) == IS_OBJECT)) {

		phalcon_read_property(&tmp, object, property, property_length, PH_NOISY_CC);

		Z_DELREF_P(tmp);

		/** Separation only when refcount > 2 */
		if (Z_REFCOUNT_P(tmp) > 2) {
			zval *new_zv;
			Z_DELREF_P(tmp);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, tmp);
			tmp = new_zv;
			zval_copy_ctor(new_zv);
			separated = 1;
		}

		/** Convert the value to array if not is an array */
		if (Z_TYPE_P(tmp) != IS_ARRAY) {
			if (separated) {
				convert_to_array(tmp);
			} else {
				zval_ptr_dtor(&tmp);
				ALLOC_INIT_ZVAL(tmp);
				array_init(tmp);
				separated = 1;
			}
		}

		Z_ADDREF_P(value);

		if (Z_TYPE_P(index) == IS_STRING) {
			zend_hash_update(Z_ARRVAL_P(tmp), Z_STRVAL_P(index), Z_STRLEN_P(index)+1, &value, sizeof(zval *), NULL);
		} else {
			if (Z_TYPE_P(index) == IS_LONG) {
				zend_hash_index_update(Z_ARRVAL_P(tmp), Z_LVAL_P(index), &value, sizeof(zval *), NULL);
			}
		}

		if (separated) {
			phalcon_update_property_zval(object, property, property_length, tmp TSRMLS_CC);
		}

		zval_ptr_dtor(&tmp);
	}

	return SUCCESS;
}

/**
 * Updates an array property using a string index
 */
int phalcon_update_property_array_string(zval *object, char *property, unsigned int property_length, char *index, unsigned int index_length, zval *value TSRMLS_DC) {

	zval *tmp;
	int separated = 0;

	if (likely(Z_TYPE_P(object) == IS_OBJECT)) {

		phalcon_read_property(&tmp, object, property, property_length, PH_NOISY_CC);

		Z_DELREF_P(tmp);

		/** Separation only when refcount > 2 */
		if (Z_REFCOUNT_P(tmp) > 2) {
			zval *new_zv;
			Z_DELREF_P(tmp);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, tmp);
			tmp = new_zv;
			zval_copy_ctor(new_zv);
			separated = 1;
		}

		/** Convert the value to array if not is an array */
		if (Z_TYPE_P(tmp) != IS_ARRAY) {
			if (separated) {
				convert_to_array(tmp);
			} else {
				zval_ptr_dtor(&tmp);
				ALLOC_INIT_ZVAL(tmp);
				array_init(tmp);
				separated = 1;
			}
		}

		Z_ADDREF_P(value);

		zend_hash_update(Z_ARRVAL_P(tmp), index, index_length, &value, sizeof(zval *), NULL);

		if (separated) {
			phalcon_update_property_zval(object, property, property_length, tmp TSRMLS_CC);
		}

		zval_ptr_dtor(&tmp);
	}

	return SUCCESS;
}

/**
 * Appends a zval value to an array property
 */
int phalcon_update_property_array_append(zval *object, char *property, unsigned int property_length, zval *value TSRMLS_DC) {

	zval *tmp;
	int separated = 0;

	if (Z_TYPE_P(object) != IS_OBJECT) {
		return SUCCESS;
	}

	phalcon_read_property(&tmp, object, property, property_length, PH_NOISY_CC);

	Z_DELREF_P(tmp);

	/** Separation only when refcount > 2 */
	if (Z_REFCOUNT_P(tmp) > 2) {
		zval *new_zv;
		Z_DELREF_P(tmp);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, tmp);
		tmp = new_zv;
		zval_copy_ctor(new_zv);
		separated = 1;
	}

	/** Convert the value to array if not is an array */
	if (Z_TYPE_P(tmp) != IS_ARRAY) {
		if (separated) {
			convert_to_array(tmp);
		} else {
			zval_ptr_dtor(&tmp);
			ALLOC_INIT_ZVAL(tmp);
			array_init(tmp);
			separated = 1;
		}
	}

	Z_ADDREF_P(value);
	add_next_index_zval(tmp, value);

	if (separated) {
		phalcon_update_property_zval(object, property, property_length, tmp TSRMLS_CC);
	}

	zval_ptr_dtor(&tmp);
	return SUCCESS;
}

/**
 * Intializes an object property with an empty array
 */
int phalcon_update_property_empty_array(zend_class_entry *ce, zval *object, char *property_name, unsigned int property_length TSRMLS_DC) {

	zval *empty_array;
	int res;

	ALLOC_INIT_ZVAL(empty_array);
	array_init(empty_array);

	res = phalcon_update_property_zval(object, property_name, property_length, empty_array TSRMLS_CC);
	zval_ptr_dtor(&empty_array);
	return res;
}

/**
 * Unsets an index in an array property
 */
int phalcon_unset_property_array(zval *object, char *property, unsigned int property_length, zval *index TSRMLS_DC) {

	zval *tmp;

	if (Z_TYPE_P(object) == IS_OBJECT) {

		phalcon_read_property(&tmp, object, property, property_length, PH_NOISY_CC);
		Z_DELREF_P(tmp);
		phalcon_array_unset(&tmp, index, 0);

		zval_ptr_dtor(&tmp);
	}

	return SUCCESS;
}

/**
 * Check if a method is implemented on certain object
 */
int phalcon_method_exists(const zval *object, const zval *method_name TSRMLS_DC){

	char *lcname;
	zend_class_entry *ce;
	unsigned long hash;

	if (likely(Z_TYPE_P(object) == IS_OBJECT)) {
		ce = Z_OBJCE_P(object);
	} else {
		if (Z_TYPE_P(object) == IS_STRING) {
			ce = zend_fetch_class(Z_STRVAL_P(object), Z_STRLEN_P(object), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
		} else {
			return FAILURE;
		}
	}

	if (Z_TYPE_P(method_name) != IS_STRING) {
		return FAILURE;
	}

	lcname = zend_str_tolower_dup(Z_STRVAL_P(method_name), Z_STRLEN_P(method_name));
	hash = zend_inline_hash_func(lcname, Z_STRLEN_P(method_name) + 1);

	while (ce) {
		if (phalcon_hash_quick_exists(&ce->function_table, lcname, Z_STRLEN_P(method_name) + 1, hash)) {
			efree(lcname);
			return SUCCESS;
		}
		ce = ce->parent;
	}

	efree(lcname);
	return FAILURE;
}

/**
 * Check if method exists on certain object using explicit char param
 */
int phalcon_method_exists_ex(const zval *object, const char *method_name, unsigned int method_len TSRMLS_DC){

	zend_class_entry *ce;
	unsigned long hash;

	if (likely(Z_TYPE_P(object) == IS_OBJECT)) {
		ce = Z_OBJCE_P(object);
	} else {
		if (Z_TYPE_P(object) == IS_STRING) {
			ce = zend_fetch_class(Z_STRVAL_P(object), Z_STRLEN_P(object), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
		} else {
			return FAILURE;
		}
	}

	hash = zend_inline_hash_func(method_name, method_len);

	while (ce) {
		if (phalcon_hash_quick_exists(&ce->function_table, method_name, method_len, hash)) {
			return SUCCESS;
		}
		ce = ce->parent;
	}

	return FAILURE;
}

/**
 * Check if method exists on certain object using explicit char param
 */
int phalcon_method_quick_exists_ex(const zval *object, const char *method_name, unsigned int method_len, unsigned long hash TSRMLS_DC){

	zend_class_entry *ce;

	if (likely(Z_TYPE_P(object) == IS_OBJECT)) {
		ce = Z_OBJCE_P(object);
	} else {
		if (Z_TYPE_P(object) == IS_STRING) {
			ce = zend_fetch_class(Z_STRVAL_P(object), Z_STRLEN_P(object), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
		} else {
			return FAILURE;
		}
	}

	while (ce) {
		if (phalcon_hash_quick_exists(&ce->function_table, method_name, method_len, hash)) {
			return SUCCESS;
		}
		ce = ce->parent;
	}

	return FAILURE;
}

/**
 * Query a static property value from a zend_class_entry
 */
int phalcon_read_static_property(zval **result, const char *class_name, unsigned int class_length, char *property_name, unsigned int property_length TSRMLS_DC){
	zend_class_entry **ce;
	if (zend_lookup_class(class_name, class_length, &ce TSRMLS_CC) == SUCCESS) {
		*result = zend_read_static_property(*ce, property_name, property_length, PH_FETCH_CLASS_SILENT);
		if (*result) {
			Z_ADDREF_PP(result);
			return SUCCESS;
		}
	}
	return FAILURE;
}

/**
 * Update a static property
 */
int phalcon_update_static_property(const char *class_name, unsigned int class_length, char *name, unsigned int name_length, zval *value TSRMLS_DC){
	zend_class_entry **ce;
	if (zend_lookup_class(class_name, class_length, &ce TSRMLS_CC) == SUCCESS) {
		return zend_update_static_property(*ce, name, name_length, value TSRMLS_CC);
	}
	return FAILURE;
}

/**
 * Update a static property (in NTS)
 */
int phalcon_update_static_property_nts(zend_class_entry *ce, char *name, unsigned int name_length, zval *value TSRMLS_DC){
	return zend_update_static_property(ce, name, name_length, value TSRMLS_CC);
}

/**
 * Creates a new instance dynamically. Call constructor without parameters
 */
int phalcon_create_instance(zval *return_value, const zval *class_name TSRMLS_DC){

	zend_class_entry *ce;

	if (Z_TYPE_P(class_name) != IS_STRING) {
		phalcon_throw_exception_string(phalcon_exception_ce, SL("Invalid class name"), 1 TSRMLS_CC);
		return FAILURE;
	}

	ce = zend_fetch_class(Z_STRVAL_P(class_name), Z_STRLEN_P(class_name), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
	if (!ce) {
		return FAILURE;
	}

	object_init_ex(return_value, ce);
	if (phalcon_has_constructor(return_value TSRMLS_CC)) {
		if (phalcon_call_method_ex(NULL, return_value, SL("__construct"), 0, 0, 1 TSRMLS_CC) == FAILURE) {
			return FAILURE;
		}
	}

	return SUCCESS;
}

/**
 * Creates a new instance dynamically calling constructor with parameters
 */
int phalcon_create_instance_params(zval *return_value, const zval *class_name, zval *params TSRMLS_DC){

	int i;
	zend_class_entry *ce;
	long param_count;
	zval **params_array;
	HashPosition pos;
	HashTable *params_hash;

	if (Z_TYPE_P(class_name) != IS_STRING) {
		phalcon_throw_exception_string(phalcon_exception_ce, SL("Invalid class name"), 1 TSRMLS_CC);
		return FAILURE;
	}

	if (Z_TYPE_P(params) != IS_ARRAY) {
		phalcon_throw_exception_string(phalcon_exception_ce, SL("Instantiation parameters must be an array"), 1 TSRMLS_CC);
		return FAILURE;
	}

	ce = zend_fetch_class(Z_STRVAL_P(class_name), Z_STRLEN_P(class_name), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
	if (!ce) {
		return FAILURE;
	}

	object_init_ex(return_value, ce);

	param_count = zend_hash_num_elements(Z_ARRVAL_P(params));
	if (param_count > 0){

		params_array = emalloc(sizeof(zval *) * param_count);

		params_hash = Z_ARRVAL_P(params);
		zend_hash_internal_pointer_reset_ex(params_hash, &pos);
		for (i = 0; ; zend_hash_move_forward_ex(params_hash, &pos), i++) {
			zval ** item;
			if (zend_hash_get_current_data_ex(params_hash, (void**)&item, &pos) == FAILURE) {
				break;
			}
			params_array[i] = *item;
		}

		if (phalcon_has_constructor(return_value TSRMLS_CC)) {
			if (phalcon_call_method_params(NULL, return_value, SL("__construct"), (zend_uint) param_count, params_array, 0, 0, 1 TSRMLS_CC) == FAILURE) {
				efree(params_array);
				return FAILURE;
			}
		}

		efree(params_array);
	} else {
		if (phalcon_has_constructor(return_value TSRMLS_CC)) {
			if (phalcon_call_method_ex(NULL, return_value, SL("__construct"), 0, 0, 1 TSRMLS_CC) == FAILURE) {
				return FAILURE;
			}
		}
	}

	return SUCCESS;
}

/**
 * Increments an object property
 */
int phalcon_property_incr(zval *object, char *property_name, unsigned int property_length TSRMLS_DC){

	zval *tmp = NULL;
	zend_class_entry *ce;
	int separated = 0;

	if (Z_TYPE_P(object) != IS_OBJECT) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Attempt to assign property of non-object");
		return FAILURE;
	}

	ce = Z_OBJCE_P(object);
	if (ce->parent) {
		ce = phalcon_lookup_class_ce(ce, property_name, property_length TSRMLS_CC);
	}

	phalcon_read_property(&tmp, object, property_name, property_length, 0 TSRMLS_CC);
	if (tmp) {

		Z_DELREF_P(tmp);

		/** Separation only when refcount > 1 */
		if (Z_REFCOUNT_P(tmp) > 1) {
			zval *new_zv;
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, tmp);
			tmp = new_zv;
			zval_copy_ctor(new_zv);
			Z_SET_REFCOUNT_P(tmp, 0);
			separated = 1;
		}

		phalcon_increment(tmp);

		if (separated) {
			phalcon_update_property_zval(object, property_name, property_length, tmp TSRMLS_CC);
		}
	}

	return SUCCESS;
}

/**
 * Decrements an object property
 */
int phalcon_property_decr(zval *object, char *property_name, unsigned int property_length TSRMLS_DC){

	zval *tmp = NULL;
	zend_class_entry *ce;
	int separated = 0;

	if (Z_TYPE_P(object) != IS_OBJECT) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Attempt to assign property of non-object");
		return FAILURE;
	}

	ce = Z_OBJCE_P(object);
	if (ce->parent) {
		ce = phalcon_lookup_class_ce(ce, property_name, property_length TSRMLS_CC);
	}

	phalcon_read_property(&tmp, object, property_name, property_length, 0 TSRMLS_CC);
	if (tmp) {

		Z_DELREF_P(tmp);

		/** Separation only when refcount > 1 */
		if (Z_REFCOUNT_P(tmp) > 1) {
			zval *new_zv;
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, tmp);
			tmp = new_zv;
			zval_copy_ctor(new_zv);
			Z_SET_REFCOUNT_P(tmp, 0);
			separated = 1;
		}

		phalcon_decrement(tmp);

		if (separated) {
			phalcon_update_property_zval(object, property_name, property_length, tmp TSRMLS_CC);
		}
	}

	return SUCCESS;
}
