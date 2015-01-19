
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/hash.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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
/**
 * Phalcon\Annotations\Adapter
 *
 * This is the base class for Phalcon\Annotations adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Adapter) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Annotations, Adapter, phalcon, annotations_adapter, phalcon_annotations_adapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_annotations_adapter_ce, SL("_reader"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_annotations_adapter_ce, SL("_annotations"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Sets the annotations parser
 *
 * @param Phalcon\Annotations\ReaderInterface reader
 */
PHP_METHOD(Phalcon_Annotations_Adapter, setReader) {

	zval *reader;

	zephir_fetch_params(0, 1, 0, &reader);



	if (!(zephir_instance_of_ev(reader, phalcon_annotations_readerinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'reader' must be an instance of 'Phalcon\\Annotations\\ReaderInterface'", "", 0);
		return;
	}
	if (Z_TYPE_P(reader) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_annotations_exception_ce, "Invalid annotations reader", "phalcon/annotations/adapter.zep", 47);
		return;
	}
	zephir_update_property_this(this_ptr, SL("_reader"), reader TSRMLS_CC);

}

/**
 * Returns the annotation reader
 *
 * @return Phalcon\Annotations\ReaderInterface
 */
PHP_METHOD(Phalcon_Annotations_Adapter, getReader) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *reader = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(reader);
	zephir_read_property_this(&reader, this_ptr, SL("_reader"), PH_NOISY_CC);
	if (Z_TYPE_P(reader) != IS_OBJECT) {
		ZEPHIR_INIT_NVAR(reader);
		object_init_ex(reader, phalcon_annotations_reader_ce);
		if (zephir_has_constructor(reader TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, reader, "__construct", NULL);
			zephir_check_call_status();
		}
		zephir_update_property_this(this_ptr, SL("_reader"), reader TSRMLS_CC);
	}
	RETURN_CCTOR(reader);

}

/**
 * Parses or retrieves all the annotations found in a class
 *
 * @param string|object className
 * @return Phalcon\Annotations\Reflection
 */
PHP_METHOD(Phalcon_Annotations_Adapter, get) {

	zend_bool _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *className, *annotations, *classAnnotations = NULL, *parsedAnnotations = NULL, *realClassName = NULL, *reader = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className);



	if (Z_TYPE_P(className) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(realClassName);
		zephir_get_class(realClassName, className, 0 TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(realClassName, className);
	}
	ZEPHIR_OBS_VAR(annotations);
	zephir_read_property_this(&annotations, this_ptr, SL("_annotations"), PH_NOISY_CC);
	if (Z_TYPE_P(annotations) == IS_ARRAY) {
		if (zephir_array_isset(annotations, realClassName)) {
			zephir_array_fetch(&_0, annotations, realClassName, PH_NOISY | PH_READONLY, "phalcon/annotations/adapter.zep", 91 TSRMLS_CC);
			RETURN_CTOR(_0);
		}
	}
	ZEPHIR_CALL_METHOD(&classAnnotations, this_ptr, "read", NULL, realClassName);
	zephir_check_call_status();
	_1 = Z_TYPE_P(classAnnotations) == IS_NULL;
	if (!(_1)) {
		_1 = ZEPHIR_IS_FALSE_IDENTICAL(classAnnotations);
	}
	if (_1) {
		ZEPHIR_CALL_METHOD(&reader, this_ptr, "getreader", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&parsedAnnotations, reader, "parse", NULL, realClassName);
		zephir_check_call_status();
		if (Z_TYPE_P(parsedAnnotations) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(classAnnotations);
			object_init_ex(classAnnotations, phalcon_annotations_reflection_ce);
			ZEPHIR_CALL_METHOD(NULL, classAnnotations, "__construct", NULL, parsedAnnotations);
			zephir_check_call_status();
			zephir_update_property_array(this_ptr, SL("_annotations"), realClassName, classAnnotations TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, realClassName, classAnnotations);
			zephir_check_call_status();
		}
	}
	RETURN_CCTOR(classAnnotations);

}

/**
 * Returns the annotations found in all the class' methods
 *
 * @param string className
 * @return array
 */
PHP_METHOD(Phalcon_Annotations_Adapter, getMethods) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *className, *classAnnotations = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className);



	ZEPHIR_CALL_METHOD(&classAnnotations, this_ptr, "get", NULL, className);
	zephir_check_call_status();
	if (Z_TYPE_P(classAnnotations) == IS_OBJECT) {
		ZEPHIR_RETURN_CALL_METHOD(classAnnotations, "getmethodsannotations", NULL);
		zephir_check_call_status();
		RETURN_MM();
	}
	array_init(return_value);
	RETURN_MM();

}

/**
 * Returns the annotations found in a specific method
 *
 * @param string className
 * @param string methodName
 * @return Phalcon\Annotations\Collection
 */
PHP_METHOD(Phalcon_Annotations_Adapter, getMethod) {

	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, *methodName_param = NULL, *classAnnotations = NULL, *methods = NULL, *name = NULL, *method = NULL, **_2;
	zval *className = NULL, *methodName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &className_param, &methodName_param);

	zephir_get_strval(className, className_param);
	zephir_get_strval(methodName, methodName_param);


	ZEPHIR_CALL_METHOD(&classAnnotations, this_ptr, "get", NULL, className);
	zephir_check_call_status();
	if (Z_TYPE_P(classAnnotations) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&methods, classAnnotations, "getmethodsannotations", NULL);
		zephir_check_call_status();
		if (Z_TYPE_P(methods) == IS_ARRAY) {
			zephir_is_iterable(methods, &_1, &_0, 0, 0, "phalcon/annotations/adapter.zep", 172);
			for (
			  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
			  ; zephir_hash_move_forward_ex(_1, &_0)
			) {
				ZEPHIR_GET_HMKEY(name, _1, _0);
				ZEPHIR_GET_HVALUE(method, _2);
				if (ZEPHIR_IS_EQUAL(name, methodName)) {
					RETURN_CCTOR(method);
				}
			}
		}
	}
	object_init_ex(return_value, phalcon_annotations_collection_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the annotations found in all the class' methods
 *
 * @param string className
 * @return array
 */
PHP_METHOD(Phalcon_Annotations_Adapter, getProperties) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, *classAnnotations = NULL;
	zval *className = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);

	zephir_get_strval(className, className_param);


	ZEPHIR_CALL_METHOD(&classAnnotations, this_ptr, "get", NULL, className);
	zephir_check_call_status();
	if (Z_TYPE_P(classAnnotations) == IS_OBJECT) {
		ZEPHIR_RETURN_CALL_METHOD(classAnnotations, "getpropertiesannotations", NULL);
		zephir_check_call_status();
		RETURN_MM();
	}
	array_init(return_value);
	RETURN_MM();

}

/**
 * Returns the annotations found in a specific property
 *
 * @param string className
 * @param string propertyName
 * @return Phalcon\Annotations\Collection
 */
PHP_METHOD(Phalcon_Annotations_Adapter, getProperty) {

	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, *propertyName_param = NULL, *classAnnotations = NULL, *properties = NULL, *name = NULL, *property = NULL, **_2;
	zval *className = NULL, *propertyName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &className_param, &propertyName_param);

	zephir_get_strval(className, className_param);
	zephir_get_strval(propertyName, propertyName_param);


	ZEPHIR_CALL_METHOD(&classAnnotations, this_ptr, "get", NULL, className);
	zephir_check_call_status();
	if (Z_TYPE_P(classAnnotations) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&properties, classAnnotations, "getpropertiesannotations", NULL);
		zephir_check_call_status();
		if (Z_TYPE_P(properties) == IS_ARRAY) {
			zephir_is_iterable(properties, &_1, &_0, 0, 0, "phalcon/annotations/adapter.zep", 233);
			for (
			  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
			  ; zephir_hash_move_forward_ex(_1, &_0)
			) {
				ZEPHIR_GET_HMKEY(name, _1, _0);
				ZEPHIR_GET_HVALUE(property, _2);
				if (ZEPHIR_IS_EQUAL(name, propertyName)) {
					RETURN_CCTOR(property);
				}
			}
		}
	}
	object_init_ex(return_value, phalcon_annotations_collection_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

