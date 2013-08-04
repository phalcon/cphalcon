
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

#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/operators.h"

/**
 * Phalcon\Annotations\Adapter
 *
 * This is the base class for Phalcon\Annotations adapters
 */


/**
 * Phalcon\Annotations\Adapter initializer
 */
PHALCON_INIT_CLASS(Phalcon_Annotations_Adapter){

	PHALCON_REGISTER_CLASS(Phalcon\\Annotations, Adapter, annotations_adapter, phalcon_annotations_adapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_annotations_adapter_ce, SL("_reader"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_annotations_adapter_ce, SL("_annotations"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Sets the annotations parser
 *
 * @param Phalcon\Annotations\ReaderInterface $reader
 */
PHP_METHOD(Phalcon_Annotations_Adapter, setReader){

	zval *reader;

	phalcon_fetch_params(0, 1, 0, &reader);
	
	if (Z_TYPE_P(reader) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_annotations_exception_ce, "Invalid annotations reader");
		return;
	}
	phalcon_update_property_this(this_ptr, SL("_reader"), reader TSRMLS_CC);
	
}

/**
 * Returns the annotation reader
 *
 * @return Phalcon\Annotations\ReaderInterface
 */
PHP_METHOD(Phalcon_Annotations_Adapter, getReader){

	zval *reader = NULL;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(reader);
	phalcon_read_property_this(&reader, this_ptr, SL("_reader"), PH_NOISY_CC);
	if (Z_TYPE_P(reader) != IS_OBJECT) {
		PHALCON_INIT_NVAR(reader);
		object_init_ex(reader, phalcon_annotations_reader_ce);
		phalcon_update_property_this(this_ptr, SL("_reader"), reader TSRMLS_CC);
	}
	
	RETURN_CCTOR(reader);
}

/**
 * Parses or retrieves all the annotations found in a class
 *
 * @param string|object $className
 * @return Phalcon\Annotations\Reflection
 */
PHP_METHOD(Phalcon_Annotations_Adapter, get){

	zval *class_name, *real_class_name = NULL, *annotations;
	zval *class_annotations = NULL, *reader, *parsed_annotations;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &class_name);
	
	/** 
	 * Get the class name if it's an object
	 */
	if (Z_TYPE_P(class_name) == IS_OBJECT) {
		PHALCON_INIT_VAR(real_class_name);
		phalcon_get_class(real_class_name, class_name, 0 TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(real_class_name, class_name);
	}
	
	PHALCON_OBS_VAR(annotations);
	phalcon_read_property_this(&annotations, this_ptr, SL("_annotations"), PH_NOISY_CC);
	if (Z_TYPE_P(annotations) == IS_ARRAY) { 
		if (phalcon_array_isset(annotations, real_class_name)) {
			PHALCON_OBS_VAR(class_annotations);
			phalcon_array_fetch(&class_annotations, annotations, real_class_name, PH_NOISY);
			RETURN_CCTOR(class_annotations);
		}
	}
	
	/** 
	 * Try to read the annotations from the adapter
	 */
	PHALCON_INIT_NVAR(class_annotations);
	phalcon_call_method_p1(class_annotations, this_ptr, "read", real_class_name);
	if (Z_TYPE_P(class_annotations) == IS_NULL) {
	
		/** 
		 * Get the annotations reader
		 */
		PHALCON_INIT_VAR(reader);
		phalcon_call_method(reader, this_ptr, "getreader");
	
		PHALCON_INIT_VAR(parsed_annotations);
		phalcon_call_method_p1(parsed_annotations, reader, "parse", real_class_name);
	
		/** 
		 * If the reader returns a 
		 */
		if (Z_TYPE_P(parsed_annotations) == IS_ARRAY) { 
			PHALCON_INIT_NVAR(class_annotations);
			object_init_ex(class_annotations, phalcon_annotations_reflection_ce);
			phalcon_call_method_p1_noret(class_annotations, "__construct", parsed_annotations);
	
			phalcon_update_property_array(this_ptr, SL("_annotations"), real_class_name, class_annotations TSRMLS_CC);
			phalcon_call_method_p2_noret(this_ptr, "write", real_class_name, class_annotations);
		}
	}
	
	RETURN_CCTOR(class_annotations);
}

/**
 * Returns the annotations found in all the class' methods
 *
 * @param string $className
 * @return array
 */
PHP_METHOD(Phalcon_Annotations_Adapter, getMethods){

	zval *class_name, *class_annotations;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &class_name);
	
	/** 
	 * Get the full annotations from the class
	 */
	PHALCON_INIT_VAR(class_annotations);
	phalcon_call_method_p1(class_annotations, this_ptr, "get", class_name);
	
	/** 
	 * A valid annotations reflection is an object
	 */
	if (Z_TYPE_P(class_annotations) == IS_OBJECT) {
		phalcon_call_method(return_value, class_annotations, "getmethodsannotations");
		RETURN_MM();
	}
	
	RETURN_MM_EMPTY_ARRAY();
}

/**
 * Returns the annotations found in a specific method
 *
 * @param string $className
 * @param string $methodName
 * @return Phalcon\Annotations\Collection
 */
PHP_METHOD(Phalcon_Annotations_Adapter, getMethod){

	zval *class_name, *method_name, *class_annotations;
	zval *methods, *method = NULL, *name = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &class_name, &method_name);
	
	/** 
	 * Get the full annotations from the class
	 */
	PHALCON_INIT_VAR(class_annotations);
	phalcon_call_method_p1(class_annotations, this_ptr, "get", class_name);
	
	/** 
	 * A valid annotations reflection is an object
	 */
	if (Z_TYPE_P(class_annotations) == IS_OBJECT) {
	
		PHALCON_INIT_VAR(methods);
		phalcon_call_method(methods, class_annotations, "getmethodsannotations");
		if (Z_TYPE_P(methods) == IS_ARRAY) { 
	
			phalcon_is_iterable(methods, &ah0, &hp0, 0, 0);
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_HKEY(name, ah0, hp0);
				PHALCON_GET_HVALUE(method);
	
				if (PHALCON_IS_EQUAL(name, method_name)) {
					RETURN_CCTOR(method);
				}
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
		}
	}
	
	/** 
	 * Returns a collection anyways
	 */
	object_init_ex(return_value, phalcon_annotations_collection_ce);
	phalcon_call_method_noret(return_value, "__construct");
	
	RETURN_MM();
}

/**
 * Returns the annotations found in all the class' methods
 *
 * @param string $className
 * @return array
 */
PHP_METHOD(Phalcon_Annotations_Adapter, getProperties){

	zval *class_name, *class_annotations;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &class_name);
	
	/** 
	 * Get the full annotations from the class
	 */
	PHALCON_INIT_VAR(class_annotations);
	phalcon_call_method_p1(class_annotations, this_ptr, "get", class_name);
	
	/** 
	 * A valid annotations reflection is an object
	 */
	if (Z_TYPE_P(class_annotations) == IS_OBJECT) {
		phalcon_call_method(return_value, class_annotations, "getpropertiesannotations");
		RETURN_MM();
	}
	
	RETURN_MM_EMPTY_ARRAY();
}

/**
 * Returns the annotations found in a specific property
 *
 * @param string $className
 * @param string $propertyName
 * @return Phalcon\Annotations\Collection
 */
PHP_METHOD(Phalcon_Annotations_Adapter, getProperty){

	zval *class_name, *property_name, *class_annotations;
	zval *properties, *property = NULL, *name = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &class_name, &property_name);
	
	/** 
	 * Get the full annotations from the class
	 */
	PHALCON_INIT_VAR(class_annotations);
	phalcon_call_method_p1(class_annotations, this_ptr, "get", class_name);
	
	/** 
	 * A valid annotations reflection is an object
	 */
	if (Z_TYPE_P(class_annotations) == IS_OBJECT) {
	
		PHALCON_INIT_VAR(properties);
		phalcon_call_method(properties, class_annotations, "getpropertiesannotations");
		if (Z_TYPE_P(properties) == IS_ARRAY) { 
	
			phalcon_is_iterable(properties, &ah0, &hp0, 0, 0);
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_HKEY(name, ah0, hp0);
				PHALCON_GET_HVALUE(property);
	
				if (PHALCON_IS_EQUAL(name, property_name)) {
					RETURN_CCTOR(property);
				}
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
		}
	}
	
	/** 
	 * Returns a collection anyways
	 */
	object_init_ex(return_value, phalcon_annotations_collection_ce);
	phalcon_call_method_noret(return_value, "__construct");
	
	RETURN_MM();
}

