
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
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/operators.h"

/**
 * Phalcon\Annotations\Adapter initializer
 */
PHALCON_INIT_CLASS(Phalcon_Annotations_Adapter){

	PHALCON_REGISTER_CLASS(Phalcon\\Annotations, Adapter, annotations_adapter, phalcon_annotations_adapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_annotations_adapter_ce, SL("_annotations"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * x
 *
 * @param string $className
 */
PHP_METHOD(Phalcon_Annotations_Adapter, get){

	zval *class_name, *real_class_name = NULL, *annotations;
	zval *class_annotations = NULL, *reader, *parsed_annotations;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &class_name) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(class_name) == IS_OBJECT) {
		PHALCON_INIT_VAR(real_class_name);
		phalcon_get_class(real_class_name, class_name, 0 TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(real_class_name, class_name);
	}
	
	PHALCON_OBS_VAR(annotations);
	phalcon_read_property(&annotations, this_ptr, SL("_annotations"), PH_NOISY_CC);
	if (Z_TYPE_P(annotations) == IS_ARRAY) { 
		if (phalcon_array_isset(annotations, real_class_name)) {
			PHALCON_OBS_VAR(class_annotations);
			phalcon_array_fetch(&class_annotations, annotations, real_class_name, PH_NOISY_CC);
			RETURN_CCTOR(class_annotations);
		}
	}
	
	PHALCON_INIT_NVAR(class_annotations);
	PHALCON_CALL_METHOD_PARAMS_1(class_annotations, this_ptr, "read", real_class_name);
	if (Z_TYPE_P(class_annotations) == IS_NULL) {
	
		PHALCON_INIT_VAR(reader);
		object_init_ex(reader, phalcon_annotations_reader_ce);
	
		PHALCON_INIT_VAR(parsed_annotations);
		PHALCON_CALL_METHOD_PARAMS_1(parsed_annotations, reader, "parse", real_class_name);
		if (Z_TYPE_P(parsed_annotations) == IS_ARRAY) { 
			PHALCON_INIT_NVAR(class_annotations);
			object_init_ex(class_annotations, phalcon_annotations_reflection_ce);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(class_annotations, "__construct", parsed_annotations);
	
			phalcon_update_property_array(this_ptr, SL("_annotations"), real_class_name, class_annotations TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "write", real_class_name, class_annotations);
		}
	}
	
	
	RETURN_CCTOR(class_annotations);
}

/**
 *
 */
PHP_METHOD(Phalcon_Annotations_Adapter, getMethod){

	zval *class_name, *method_name, *class_annotations;
	zval *methods, *method = NULL, *name = NULL, *is_equal = NULL, *collection;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &class_name, &method_name) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(class_annotations);
	PHALCON_CALL_METHOD_PARAMS_1(class_annotations, this_ptr, "get", class_name);
	if (Z_TYPE_P(class_annotations) == IS_OBJECT) {
	
		PHALCON_INIT_VAR(methods);
		PHALCON_CALL_METHOD(methods, class_annotations, "getmethodannotations");
		if (Z_TYPE_P(methods) == IS_ARRAY) { 
	
			if (!phalcon_is_iterable(methods, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
				return;
			}
	
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_FOREACH_KEY(name, ah0, hp0);
				PHALCON_GET_FOREACH_VALUE(method);
	
				PHALCON_INIT_NVAR(is_equal);
				is_equal_function(is_equal, name, method_name TSRMLS_CC);
				if (PHALCON_IS_TRUE(is_equal)) {
					RETURN_CCTOR(method);
				}
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
		}
	}
	
	PHALCON_INIT_VAR(collection);
	object_init_ex(collection, phalcon_annotations_collection_ce);
	PHALCON_CALL_METHOD_NORETURN(collection, "__construct");
	
	
	RETURN_CTOR(collection);
}

