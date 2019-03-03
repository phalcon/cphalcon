
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
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
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

	zend_class_implements(phalcon_annotations_adapter_ce TSRMLS_CC, 1, phalcon_annotations_adapterinterface_ce);
	return SUCCESS;

}

/**
 * Sets the annotations parser
 */
PHP_METHOD(Phalcon_Annotations_Adapter, setReader) {

	zval *reader, reader_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&reader_sub);

	zephir_fetch_params(0, 1, 0, &reader);



	zephir_update_property_zval(this_ptr, SL("_reader"), reader);

}

/**
 * Returns the annotation reader
 */
PHP_METHOD(Phalcon_Annotations_Adapter, getReader) {

	zval _0, _1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("_reader"), PH_NOISY_CC);
	if (Z_TYPE_P(&_0) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_annotations_reader_ce);
		if (zephir_has_constructor(&_1$$3 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_update_property_zval(this_ptr, SL("_reader"), &_1$$3);
	}
	RETURN_MM_MEMBER(getThis(), "_reader");

}

/**
 * Parses or retrieves all the annotations found in a class
 *
 * @param string|object className
 */
PHP_METHOD(Phalcon_Annotations_Adapter, get) {

	zend_bool _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *className, className_sub, annotations, classAnnotations, parsedAnnotations, realClassName, reader, _0$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className_sub);
	ZVAL_UNDEF(&annotations);
	ZVAL_UNDEF(&classAnnotations);
	ZVAL_UNDEF(&parsedAnnotations);
	ZVAL_UNDEF(&realClassName);
	ZVAL_UNDEF(&reader);
	ZVAL_UNDEF(&_0$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className);



	if (Z_TYPE_P(className) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&realClassName);
		zephir_get_class(&realClassName, className, 0 TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(&realClassName, className);
	}
	ZEPHIR_OBS_VAR(&annotations);
	zephir_read_property(&annotations, this_ptr, SL("_annotations"), PH_NOISY_CC);
	if (Z_TYPE_P(&annotations) == IS_ARRAY) {
		if (zephir_array_isset(&annotations, &realClassName)) {
			zephir_array_fetch(&_0$$6, &annotations, &realClassName, PH_NOISY | PH_READONLY, "phalcon/annotations/adapter.zep", 72 TSRMLS_CC);
			RETURN_CTOR(&_0$$6);
		}
	}
	ZEPHIR_CALL_METHOD(&classAnnotations, this_ptr, "read", NULL, 0, &realClassName);
	zephir_check_call_status();
	_1 = Z_TYPE_P(&classAnnotations) == IS_NULL;
	if (!(_1)) {
		_1 = ZEPHIR_IS_FALSE_IDENTICAL(&classAnnotations);
	}
	if (_1) {
		ZEPHIR_CALL_METHOD(&reader, this_ptr, "getreader", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&parsedAnnotations, &reader, "parse", NULL, 0, &realClassName);
		zephir_check_call_status();
		if (Z_TYPE_P(&parsedAnnotations) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(&classAnnotations);
			object_init_ex(&classAnnotations, phalcon_annotations_reflection_ce);
			ZEPHIR_CALL_METHOD(NULL, &classAnnotations, "__construct", NULL, 18, &parsedAnnotations);
			zephir_check_call_status();
			zephir_update_property_array(this_ptr, SL("_annotations"), &realClassName, &classAnnotations);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &realClassName, &classAnnotations);
			zephir_check_call_status();
		}
	}
	RETURN_CCTOR(&classAnnotations);

}

/**
 * Returns the annotations found in all the class' methods
 */
PHP_METHOD(Phalcon_Annotations_Adapter, getMethods) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, classAnnotations;
	zval className;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&classAnnotations);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);

	zephir_get_strval(&className, className_param);


	ZEPHIR_CALL_METHOD(&classAnnotations, this_ptr, "get", NULL, 0, &className);
	zephir_check_call_status();
	if (Z_TYPE_P(&classAnnotations) == IS_OBJECT) {
		ZEPHIR_RETURN_CALL_METHOD(&classAnnotations, "getmethodsannotations", NULL, 0);
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

	zend_string *_3$$4;
	zend_ulong _2$$4;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, *methodName_param = NULL, classAnnotations, methods, method, methodKey, *_0$$4, _1$$4, _4$$5, _6$$7;
	zval className, methodName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&methodName);
	ZVAL_UNDEF(&classAnnotations);
	ZVAL_UNDEF(&methods);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&methodKey);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &className_param, &methodName_param);

	zephir_get_strval(&className, className_param);
	zephir_get_strval(&methodName, methodName_param);


	ZEPHIR_CALL_METHOD(&classAnnotations, this_ptr, "get", NULL, 0, &className);
	zephir_check_call_status();
	if (Z_TYPE_P(&classAnnotations) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&methods, &classAnnotations, "getmethodsannotations", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&methods) == IS_ARRAY) {
			zephir_is_iterable(&methods, 0, "phalcon/annotations/adapter.zep", 146);
			if (Z_TYPE_P(&methods) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&methods), _2$$4, _3$$4, _0$$4)
				{
					ZEPHIR_INIT_NVAR(&methodKey);
					if (_3$$4 != NULL) { 
						ZVAL_STR_COPY(&methodKey, _3$$4);
					} else {
						ZVAL_LONG(&methodKey, _2$$4);
					}
					ZEPHIR_INIT_NVAR(&method);
					ZVAL_COPY(&method, _0$$4);
					ZEPHIR_CALL_FUNCTION(&_4$$5, "strcasecmp", &_5, 19, &methodKey, &methodName);
					zephir_check_call_status();
					if (!(zephir_is_true(&_4$$5))) {
						RETURN_CCTOR(&method);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &methods, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_1$$4, &methods, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_1$$4)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&methodKey, &methods, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&method, &methods, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_FUNCTION(&_6$$7, "strcasecmp", &_5, 19, &methodKey, &methodName);
						zephir_check_call_status();
						if (!(zephir_is_true(&_6$$7))) {
							RETURN_CCTOR(&method);
						}
					ZEPHIR_CALL_METHOD(NULL, &methods, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&method);
			ZEPHIR_INIT_NVAR(&methodKey);
		}
	}
	object_init_ex(return_value, phalcon_annotations_collection_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 20);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the annotations found in all the class' methods
 */
PHP_METHOD(Phalcon_Annotations_Adapter, getProperties) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, classAnnotations;
	zval className;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&classAnnotations);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);

	zephir_get_strval(&className, className_param);


	ZEPHIR_CALL_METHOD(&classAnnotations, this_ptr, "get", NULL, 0, &className);
	zephir_check_call_status();
	if (Z_TYPE_P(&classAnnotations) == IS_OBJECT) {
		ZEPHIR_RETURN_CALL_METHOD(&classAnnotations, "getpropertiesannotations", NULL, 0);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, *propertyName_param = NULL, classAnnotations, properties, property;
	zval className, propertyName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&propertyName);
	ZVAL_UNDEF(&classAnnotations);
	ZVAL_UNDEF(&properties);
	ZVAL_UNDEF(&property);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &className_param, &propertyName_param);

	zephir_get_strval(&className, className_param);
	zephir_get_strval(&propertyName, propertyName_param);


	ZEPHIR_CALL_METHOD(&classAnnotations, this_ptr, "get", NULL, 0, &className);
	zephir_check_call_status();
	if (Z_TYPE_P(&classAnnotations) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&properties, &classAnnotations, "getpropertiesannotations", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&properties) == IS_ARRAY) {
			if (zephir_array_isset_fetch(&property, &properties, &propertyName, 1 TSRMLS_CC)) {
				RETURN_CTOR(&property);
			}
		}
	}
	object_init_ex(return_value, phalcon_annotations_collection_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 20);
	zephir_check_call_status();
	RETURN_MM();

}

