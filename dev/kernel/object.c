
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
#include "kernel/object.h"

/**
 * Copy on write for not tmp variables to be used as parameters
 */
int phalcon_cpy_wrt_param(zval **param, zval *value){
	if(Z_TYPE_P(value)==IS_OBJECT){
		Z_ADDREF_P(value);
		*param = value;
	} else {
		INIT_PARAM(*param);
		ALLOC_INIT_ZVAL(*param);
		ZVAL_ZVAL(*param, value, 1, 0);
	}
	return SUCCESS;
}

/**
 * Check if class is instance of
 */
int phalcon_instance_of(zval *result, const zval *object, const zend_class_entry *ce TSRMLS_DC){
	if(Z_TYPE_P(object)!=IS_OBJECT){
		zend_error(E_ERROR, "instanceof expects an object instance, constant given");
		return FAILURE;
    } else {
		ZVAL_BOOL(result, instanceof_function(Z_OBJCE_P(object), ce TSRMLS_CC));
    }
    return SUCCESS;
}

/**
 * Check if a class exists
 *
 * @TODO Unfortunately doesn't works
 */
int phalcon_class_exists(zval *return_value, zval *class_name_zval, zval *autoload_zval TSRMLS_DC){

	/*char *class_name;
	int class_name_len;
	zend_class_entry ***ce;
	ulong hash;
	ALLOCA_FLAG(use_heap)

	switch(Z_TYPE_P(class_name_zval)){
		case IS_ARRAY:
		case IS_OBJECT:
		case IS_RESOURCE:
			php_error_docref(NULL TSRMLS_CC, E_ERROR, "Invalid parameter for class_exists");
			return FAILURE;
	}

	if(Z_TYPE_P(class_name_zval)!=IS_STRING){
		convert_to_string(class_name_zval);
	}

	class_name = estrndup(Z_STRVAL_P(class_name_zval), Z_STRLEN_P(class_name_zval));
	class_name_len = strlen(class_name);

	zend_str_tolower(class_name, class_name_len);

	hash = zend_inline_hash_func(class_name, class_name_len);
	if(zend_hash_quick_find(EG(class_table), class_name, class_name_len, hash, (void **) ce) == SUCCESS) {
		free_alloca(class_name, use_heap);
		return SUCCESS;
	}

	free_alloca(class_name, use_heap);*/
	return FAILURE;

}

/**
 * Clones an object from obj to dst
 */
int phalcon_clone(zval **dst, zval *obj TSRMLS_DC){

	zval *destiny;
	zend_class_entry *ce;
	//zend_function *clone;
	zend_object_clone_obj_t clone_call;

	if (Z_TYPE_P(obj) != IS_OBJECT) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "__clone method called on non-object");
		return FAILURE;
	}

	ce = Z_OBJCE_P(obj);
	//clone = ce ? ce->clone : NULL;
	clone_call =  Z_OBJ_HT_P(obj)->clone_obj;
	if (!clone_call) {
		if (ce) {
			php_error_docref(NULL TSRMLS_CC, E_ERROR, "Trying to clone an uncloneable object of class %s", ce->name);
		} else {
			php_error_docref(NULL TSRMLS_CC, E_ERROR, "Trying to clone an uncloneable object");
		}
		return FAILURE;
	}

	if(!EG(exception)){
		ALLOC_ZVAL(destiny);
		Z_OBJVAL_P(destiny) = clone_call(obj TSRMLS_CC);
		Z_TYPE_P(destiny) = IS_OBJECT;
		Z_SET_REFCOUNT_P(destiny, 1);
		Z_SET_ISREF_P(destiny);
		if(EG(exception)){
			zval_ptr_dtor(&destiny);
			destiny = NULL;
		}
	}

	if(destiny){
		*dst = destiny;
	}

	return SUCCESS;
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
 * Reads a property from an object
 */
int phalcon_read_property(zval *result, zval *object, char *property_name, int property_length, int silent TSRMLS_DC){

	zend_class_entry *ce;

	if (Z_TYPE_P(object) == IS_OBJECT) {
		ce = Z_OBJCE_P(object);
		while (ce) {
			if (zend_hash_exists(&ce->properties_info, property_name, property_length+1)) {
				*result = *zend_read_property(ce, object, property_name, property_length, 0 TSRMLS_CC);
				zval_copy_ctor(result);
				return SUCCESS;
			}
			ce = ce->parent;
		}
		*result = *zend_read_property(Z_OBJCE_P(object), object, property_name, property_length, 1 TSRMLS_CC);
	} else {
		ZVAL_NULL(result);
		if (silent == PHALCON_NOISY_FETCH) {
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Trying to get property of non-object");
			return FAILURE;
		}
	}
	return SUCCESS;
}

/**
 * Reads a property from an object
 */
int phalcon_read_property_zval(zval *result, zval *object, zval *property, int silent TSRMLS_DC){
	if (Z_TYPE_P(object) == IS_OBJECT) {
		if (Z_TYPE_P(property) == IS_STRING) {
			*result = *zend_read_property(Z_OBJCE_P(object), object, Z_STRVAL_P(property), Z_STRLEN_P(property), 0 TSRMLS_CC);
			zval_copy_ctor(result);
		} else {
			ZVAL_NULL(result);
		}
	} else {
		ZVAL_NULL(result);
		if (silent==PHALCON_NOISY_FETCH) {
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
	if (Z_TYPE_P(obj) != IS_OBJECT) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Attempt to assign property of non-object");
		return FAILURE;
	} else {
		zend_update_property_long(Z_OBJCE_P(obj), obj, property_name, property_length, value TSRMLS_CC);
	}
	return SUCCESS;
}

/**
 * Checks whether obj is an object and updates property with string value
 */
int phalcon_update_property_string(zval *obj, char *property_name, int property_length, char *value TSRMLS_DC){
	if (Z_TYPE_P(obj) != IS_OBJECT) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Attempt to assign property of non-object");
		return FAILURE;
	} else {
		zend_update_property_string(Z_OBJCE_P(obj), obj, property_name, property_length, value TSRMLS_CC);
	}
	return SUCCESS;
}

/**
 * Checks wheter obj is an object and updates property with another zval
 */
int phalcon_update_property_zval(zval *obj, char *property_name, int property_length, zval *value TSRMLS_DC){
	if (Z_TYPE_P(obj) != IS_OBJECT) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Attempt to assign property of non-object");
		return FAILURE;
	} else {
		Z_ADDREF_P(value);
		zend_update_property(Z_OBJCE_P(obj), obj, property_name, property_length, value TSRMLS_CC);
	}
	return SUCCESS;
}

/**
 * Check if method exists on certain object
 */
int phalcon_method_exists(zval *object, zval *method_name TSRMLS_DC){

	char *lcname;

	if (Z_TYPE_P(object) != IS_OBJECT) {
		return FAILURE;
	}

	if (Z_TYPE_P(method_name) != IS_STRING) {
		return FAILURE;
	}

	lcname = zend_str_tolower_dup(Z_STRVAL_P(method_name), Z_STRLEN_P(method_name));
	if (zend_hash_exists(&Z_OBJCE_P(object)->function_table, lcname, Z_STRLEN_P(method_name)+1)) {
		efree(lcname);
		return SUCCESS;
	}

	return FAILURE;
}
