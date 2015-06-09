
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"


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
 */
PHP_METHOD(Phalcon_Annotations_Adapter, setReader) {

	zval *reader;

	zephir_fetch_params(0, 1, 0, &reader);



	zephir_update_property_this(this_ptr, SL("_reader"), reader TSRMLS_CC);

}

/**
 * Returns the annotation reader
 */
PHP_METHOD(Phalcon_Annotations_Adapter, getReader) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_reader"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, phalcon_annotations_reader_ce);
		if (zephir_has_constructor(_1 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_update_property_this(this_ptr, SL("_reader"), _1 TSRMLS_CC);
	}
	RETURN_MM_MEMBER(this_ptr, "_reader");

}

/**
 * Parses or retrieves all the annotations found in a class
 *
 * @param string|object className
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
			zephir_array_fetch(&_0, annotations, realClassName, PH_NOISY | PH_READONLY, "phalcon/annotations/adapter.zep", 79 TSRMLS_CC);
			RETURN_CTOR(_0);
		}
	}
	ZEPHIR_CALL_METHOD(&classAnnotations, this_ptr, "read", NULL, 0, realClassName);
	zephir_check_call_status();
	_1 = Z_TYPE_P(classAnnotations) == IS_NULL;
	if (!(_1)) {
		_1 = ZEPHIR_IS_FALSE_IDENTICAL(classAnnotations);
	}
	if (_1) {
		ZEPHIR_CALL_METHOD(&reader, this_ptr, "getreader", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&parsedAnnotations, reader, "parse", NULL, 0, realClassName);
		zephir_check_call_status();
		if (Z_TYPE_P(parsedAnnotations) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(classAnnotations);
			object_init_ex(classAnnotations, phalcon_annotations_reflection_ce);
			ZEPHIR_CALL_METHOD(NULL, classAnnotations, "__construct", NULL, 5, parsedAnnotations);
			zephir_check_call_status();
			zephir_update_property_array(this_ptr, SL("_annotations"), realClassName, classAnnotations TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, realClassName, classAnnotations);
			zephir_check_call_status();
		}
	}
	RETURN_CCTOR(classAnnotations);

}

/**
 * Returns the annotations found in all the class' methods
 */
PHP_METHOD(Phalcon_Annotations_Adapter, getMethods) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, *classAnnotations = NULL;
	zval *className = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);

	zephir_get_strval(className, className_param);


	ZEPHIR_CALL_METHOD(&classAnnotations, this_ptr, "get", NULL, 0, className);
	zephir_check_call_status();
	if (Z_TYPE_P(classAnnotations) == IS_OBJECT) {
		ZEPHIR_RETURN_CALL_METHOD(classAnnotations, "getmethodsannotations", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	array_init(return_value);
	RETURN_MM();

}

/**
 * Returns the annotations found in a specific method
 */
PHP_METHOD(Phalcon_Annotations_Adapter, getMethod) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, *methodName_param = NULL, *classAnnotations = NULL, *methods = NULL, *method;
	zval *className = NULL, *methodName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &className_param, &methodName_param);

	zephir_get_strval(className, className_param);
	zephir_get_strval(methodName, methodName_param);


	ZEPHIR_CALL_METHOD(&classAnnotations, this_ptr, "get", NULL, 0, className);
	zephir_check_call_status();
	if (Z_TYPE_P(classAnnotations) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&methods, classAnnotations, "getmethodsannotations", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(methods) == IS_ARRAY) {
			if (zephir_array_isset_fetch(&method, methods, methodName, 1 TSRMLS_CC)) {
				RETURN_CTOR(method);
			}
		}
	}
	object_init_ex(return_value, phalcon_annotations_collection_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 6);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the annotations found in all the class' methods
 */
PHP_METHOD(Phalcon_Annotations_Adapter, getProperties) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, *classAnnotations = NULL;
	zval *className = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);

	zephir_get_strval(className, className_param);


	ZEPHIR_CALL_METHOD(&classAnnotations, this_ptr, "get", NULL, 0, className);
	zephir_check_call_status();
	if (Z_TYPE_P(classAnnotations) == IS_OBJECT) {
		ZEPHIR_RETURN_CALL_METHOD(classAnnotations, "getpropertiesannotations", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	array_init(return_value);
	RETURN_MM();

}

/**
 * Returns the annotations found in a specific property
 */
PHP_METHOD(Phalcon_Annotations_Adapter, getProperty) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, *propertyName_param = NULL, *classAnnotations = NULL, *properties = NULL, *property;
	zval *className = NULL, *propertyName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &className_param, &propertyName_param);

	zephir_get_strval(className, className_param);
	zephir_get_strval(propertyName, propertyName_param);


	ZEPHIR_CALL_METHOD(&classAnnotations, this_ptr, "get", NULL, 0, className);
	zephir_check_call_status();
	if (Z_TYPE_P(classAnnotations) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&properties, classAnnotations, "getpropertiesannotations", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(properties) == IS_ARRAY) {
			if (zephir_array_isset_fetch(&property, properties, propertyName, 1 TSRMLS_CC)) {
				RETURN_CTOR(property);
			}
		}
	}
	object_init_ex(return_value, phalcon_annotations_collection_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 6);
	zephir_check_call_status();
	RETURN_MM();

}

