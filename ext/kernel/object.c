
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
#ifdef PHP_WIN32
#include "php_string.h"
#endif
#include "php_phalcon.h"
#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"

/**
 * Reads class constant from string name and returns its value
 */
int phalcon_get_class_constant(zval *return_value, zend_class_entry *ce, char *constant_name, int constant_length TSRMLS_DC){

	zval **result_ptr;

	if (zend_hash_find(&ce->constants_table, constant_name, constant_length+1, (void **) &result_ptr) != SUCCESS) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Undefined class constant '%s::%s'", ce->name, constant_name);
		phalcon_memory_restore_stack(TSRMLS_C);
		return FAILURE;
	} else {
		ZVAL_ZVAL(return_value, *result_ptr, 1, 0);
	}

	return SUCCESS;
}

/**
 * Check if class is instance of
 */
int phalcon_instance_of(zval *result, const zval *object, const zend_class_entry *ce TSRMLS_DC){

	if (Z_TYPE_P(object) != IS_OBJECT) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "instanceof expects an object instance, constant given");
		phalcon_memory_restore_stack(TSRMLS_C);
		return FAILURE;
    } else {
		ZVAL_BOOL(result, instanceof_function(Z_OBJCE_P(object), ce TSRMLS_CC));
    }

    return SUCCESS;
}

int phalcon_is_instance_of(zval *object, char *class_name, int class_length TSRMLS_DC){

	zend_class_entry *ce;

	ce = Z_OBJCE_P(object);
	if (ce->name_length == class_length) {
		return !zend_binary_strcasecmp(ce->name, ce->name_length, class_name, class_length);
	}

	return 0;
}

/**
 * Returns class name into result
 */
void phalcon_get_class(zval *result, zval *object TSRMLS_DC){
	zend_class_entry *ce;
	if (Z_TYPE_P(object) == IS_OBJECT){
		ce = Z_OBJCE_P(object);
		Z_STRLEN_P(result) = ce->name_length;
		Z_STRVAL_P(result) = (char *) emalloc(ce->name_length + 1);
		memcpy(Z_STRVAL_P(result), ce->name, ce->name_length);
		Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
		Z_TYPE_P(result) = IS_STRING;
	} else {
		ZVAL_NULL(result);
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "get_class expects an object");
	}
}

/**
 * Fetches a zend class entry from a zval value
 */
zend_class_entry *phalcon_fetch_class(zval *class_name TSRMLS_DC){
	if (Z_TYPE_P(class_name) == IS_STRING){
		return zend_fetch_class(Z_STRVAL_P(class_name), Z_STRLEN_P(class_name), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
	} else {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "class name must be a string");
		return zend_fetch_class("stdclass", strlen("strlen"), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
	}
}

/**
 * Clones an object from obj to destiny
 */
int phalcon_clone(zval *destiny, zval *obj TSRMLS_DC){

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
			if(!EG(exception)){
				Z_OBJVAL_P(destiny) = clone_call(obj TSRMLS_CC);
				Z_TYPE_P(destiny) = IS_OBJECT;
				Z_SET_REFCOUNT_P(destiny, 1);
				Z_SET_ISREF_P(destiny);
				if(EG(exception)){
					zval_ptr_dtor(&destiny);
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
int phalcon_isset_property(zval *object, char *property_name, int property_length TSRMLS_DC){
	if (Z_TYPE_P(object) == IS_OBJECT) {
		if(zend_hash_exists(&Z_OBJCE_P(object)->properties_info, property_name, property_length+1)){
			return 1;
		} else {
			return zend_hash_exists(Z_OBJ_HT_P(object)->get_properties(object TSRMLS_CC), property_name, property_length+1);
		}
	} else {
		return 0;
	}
}

/**
 * Checks if string property exists on object
 */
int phalcon_isset_property_zval(zval *object, zval *property TSRMLS_DC){
	if (Z_TYPE_P(object) == IS_OBJECT) {
		if (Z_TYPE_P(property) == IS_STRING) {
			if(zend_hash_exists(&Z_OBJCE_P(object)->properties_info, Z_STRVAL_P(property), Z_STRLEN_P(property)+1)){
				return 1;
			} else {
				return zend_hash_exists(Z_OBJ_HT_P(object)->get_properties(object TSRMLS_CC), Z_STRVAL_P(property), Z_STRLEN_P(property)+1);
			}
		} else {
			return 0;
		}
	} else {
		return 0;
	}
}

/**
 * Lookup exact class where a property is defined
 *
 */
zend_class_entry *phalcon_lookup_class_ce(zval *object, char *property_name, int property_length TSRMLS_DC){

	zend_class_entry *ce, *original_ce;

	ce = Z_OBJCE_P(object);
	original_ce = ce;
	while (ce) {
		if (zend_hash_exists(&ce->properties_info, property_name, property_length+1)) {
			return ce;
		}
		ce = ce->parent;
	}
	return original_ce;
}

/**
 * Reads a property from an object
 */
int phalcon_read_property(zval **result, zval *object, char *property_name, int property_length, int silent TSRMLS_DC){

	zval *tmp = NULL;
	zend_class_entry *ce;

	ZVAL_NULL((*result));

	if (Z_TYPE_P(object) == IS_OBJECT) {
		ce = phalcon_lookup_class_ce(object, property_name, property_length TSRMLS_CC);
		tmp = zend_read_property(ce, object, property_name, property_length, 0 TSRMLS_CC);
		Z_ADDREF_P(tmp);
		zval_ptr_dtor(result);
		*result = tmp;
		return SUCCESS;
	} else {
		if (silent == PH_NOISY) {
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Trying to get property of non-object");
		}
	}
	return FAILURE;
}

/**
 * Reads a property from an object
 */
int phalcon_read_property_zval(zval **result, zval *object, zval *property, int silent TSRMLS_DC){

	zval *tmp = NULL;
	zend_class_entry *ce;

	ZVAL_NULL((*result));

	if (Z_TYPE_P(object) == IS_OBJECT) {
		if (Z_TYPE_P(property) == IS_STRING) {
			ce = phalcon_lookup_class_ce(object, Z_STRVAL_P(property), Z_STRLEN_P(property) TSRMLS_CC);
			tmp = zend_read_property(ce, object, Z_STRVAL_P(property), Z_STRLEN_P(property), 0 TSRMLS_CC);
			Z_ADDREF_P(tmp);
			zval_ptr_dtor(result);
			*result = tmp;
		}
	} else {
		if (silent == PH_NOISY) {
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Trying to get property of non-object");
			return FAILURE;
		}
	}
	return SUCCESS;
}

/**
 * Checks whether obj is an object and updates property with long value
 */
int phalcon_update_property_long(zval *obj, char *property_name, int property_length, long value TSRMLS_DC){

	zend_class_entry *ce;

	if (Z_TYPE_P(obj) != IS_OBJECT) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Attempt to assign property of non-object");
		return FAILURE;
	}

	ce = phalcon_lookup_class_ce(obj, property_name, property_length TSRMLS_CC);
	zend_update_property_long(ce, obj, property_name, property_length, value TSRMLS_CC);
	return SUCCESS;
}

/**
 * Checks whether obj is an object and updates property with string value
 */
int phalcon_update_property_string(zval *obj, char *property_name, int property_length, char *value TSRMLS_DC){

	zend_class_entry *ce;

	if (Z_TYPE_P(obj) != IS_OBJECT) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Attempt to assign property of non-object");
		return FAILURE;
	}

	ce = phalcon_lookup_class_ce(obj, property_name, property_length TSRMLS_CC);
	zend_update_property_string(ce, obj, property_name, property_length, value TSRMLS_CC);

	return SUCCESS;
}

/**
 * Checks whether obj is an object and updates property with bool value
 */
int phalcon_update_property_bool(zval *obj, char *property_name, int property_length, int value TSRMLS_DC){

	zend_class_entry *ce;

	if (Z_TYPE_P(obj) != IS_OBJECT) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Attempt to assign property of non-object");
		return FAILURE;
	}

	ce = phalcon_lookup_class_ce(obj, property_name, property_length TSRMLS_CC);
	zend_update_property_bool(ce, obj, property_name, property_length, value TSRMLS_CC);

	return SUCCESS;
}

/**
 * Checks whether obj is an object and updates property with null value
 */
int phalcon_update_property_null(zval *obj, char *property_name, int property_length TSRMLS_DC){

	zend_class_entry *ce;

	if (Z_TYPE_P(obj) != IS_OBJECT) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Attempt to assign property of non-object");
		return FAILURE;
	}

	ce = phalcon_lookup_class_ce(obj, property_name, property_length TSRMLS_CC);
	zend_update_property_null(ce, obj, property_name, property_length TSRMLS_CC);

	return SUCCESS;
}

/**
 * Checks wheter obj is an object and updates property with another zval
 */
int phalcon_update_property_zval(zval *obj, char *property_name, int property_length, zval *value TSRMLS_DC){

	zend_class_entry *ce;

	if (Z_TYPE_P(obj) != IS_OBJECT) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Attempt to assign property of non-object");
		return FAILURE;
	}

	ce = phalcon_lookup_class_ce(obj, property_name, property_length TSRMLS_CC);
	zend_update_property(ce, obj, property_name, property_length, value TSRMLS_CC);

	return SUCCESS;
}

/**
 * Checks wheter obj is an object and updates zval property with another zval
 */
int phalcon_update_property_zval_zval(zval *obj, zval *property, zval *value TSRMLS_DC){

	zend_class_entry *ce;

	if (Z_TYPE_P(obj) != IS_OBJECT) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Attempt to assign property of non-object");
		return FAILURE;
	}

	if (Z_TYPE_P(property) != IS_STRING) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Property should be string");
		return FAILURE;
	}

	ce = phalcon_lookup_class_ce(obj, Z_STRVAL_P(property), Z_STRLEN_P(property) TSRMLS_CC);
	zend_update_property(ce, obj, Z_STRVAL_P(property), Z_STRLEN_P(property), value TSRMLS_CC);

	return SUCCESS;
}

/**
 * Check if method exists on certain object
 */
int phalcon_method_exists(zval *object, zval *method_name TSRMLS_DC){

	char *lcname;
	zend_class_entry *ce;

	if (Z_TYPE_P(object) != IS_OBJECT) {
		return FAILURE;
	}

	if (Z_TYPE_P(method_name) != IS_STRING) {
		return FAILURE;
	}

	ce = Z_OBJCE_P(object);
	lcname = zend_str_tolower_dup(Z_STRVAL_P(method_name), Z_STRLEN_P(method_name));
	while (ce) {
		if (zend_hash_exists(&ce->function_table, lcname, Z_STRLEN_P(method_name)+1)) {
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
int phalcon_method_exists_ex(zval *object, char *method_name, int method_len TSRMLS_DC){

	zend_class_entry *ce;

	if (Z_TYPE_P(object) != IS_OBJECT) {
		return FAILURE;
	}

	ce = Z_OBJCE_P(object);
	while (ce) {
		if (zend_hash_exists(&ce->function_table, method_name, method_len+1)) {
			return SUCCESS;
		}
		ce = ce->parent;
	}

	return FAILURE;
}

/**
 * Query a static property value from a zend_class_entry
 */
int phalcon_read_static_property(zval **result, char *class_name, int class_length, char *property_name, int property_length TSRMLS_DC){
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
int phalcon_update_static_property(char *class_name, int class_length, char *name, int name_length, zval *value TSRMLS_DC){
	zend_class_entry **ce;
	if (zend_lookup_class(class_name, class_length, &ce TSRMLS_CC) == SUCCESS) {
		return zend_update_static_property(*ce, name, name_length, value TSRMLS_CC);
	}
	return FAILURE;
}
