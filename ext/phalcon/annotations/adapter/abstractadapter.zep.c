
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * This is the base class for Phalcon\Annotations adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Adapter_AbstractAdapter) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Annotations\\Adapter, AbstractAdapter, phalcon, annotations_adapter_abstractadapter, phalcon_annotations_adapter_abstractadapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_annotations_adapter_abstractadapter_ce, SL("annotations"), ZEND_ACC_PROTECTED);

	/**
	 * @var Reader
	 */
	zend_declare_property_null(phalcon_annotations_adapter_abstractadapter_ce, SL("reader"), ZEND_ACC_PROTECTED);

	phalcon_annotations_adapter_abstractadapter_ce->create_object = zephir_init_properties_Phalcon_Annotations_Adapter_AbstractAdapter;

	zend_class_implements(phalcon_annotations_adapter_abstractadapter_ce, 1, phalcon_annotations_adapter_adapterinterface_ce);
	return SUCCESS;

}

/**
 * Parses or retrieves all the annotations found in a class
 */
PHP_METHOD(Phalcon_Annotations_Adapter_AbstractAdapter, get) {

	zend_bool _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *className, className_sub, classAnnotations, parsedAnnotations, realClassName, reader, _0, _1$$5, _2$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className_sub);
	ZVAL_UNDEF(&classAnnotations);
	ZVAL_UNDEF(&parsedAnnotations);
	ZVAL_UNDEF(&realClassName);
	ZVAL_UNDEF(&reader);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className);



	if (Z_TYPE_P(className) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&realClassName);
		zephir_get_class(&realClassName, className, 0);
	} else {
		ZEPHIR_CPY_WRT(&realClassName, className);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("annotations"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &realClassName)) {
		zephir_read_property(&_1$$5, this_ptr, ZEND_STRL("annotations"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$5, &_1$$5, &realClassName, PH_NOISY | PH_READONLY, "phalcon/Annotations/Adapter/AbstractAdapter.zep", 51);
		RETURN_CTOR(&_2$$5);
	}
	ZEPHIR_CALL_METHOD(&classAnnotations, this_ptr, "read", NULL, 0, &realClassName);
	zephir_check_call_status();
	_3 = Z_TYPE_P(&classAnnotations) == IS_NULL;
	if (!(_3)) {
		_3 = ZEPHIR_IS_FALSE_IDENTICAL(&classAnnotations);
	}
	if (_3) {
		ZEPHIR_CALL_METHOD(&reader, this_ptr, "getreader", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&parsedAnnotations, &reader, "parse", NULL, 0, &realClassName);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&classAnnotations);
		object_init_ex(&classAnnotations, phalcon_annotations_reflection_ce);
		ZEPHIR_CALL_METHOD(NULL, &classAnnotations, "__construct", NULL, 46, &parsedAnnotations);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("annotations"), &realClassName, &classAnnotations);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &realClassName, &classAnnotations);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&classAnnotations);

}

/**
 * Returns the annotations found in a specific method
 */
PHP_METHOD(Phalcon_Annotations_Adapter_AbstractAdapter, getMethod) {

	zend_string *_3$$3;
	zend_ulong _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, *methodName_param = NULL, classAnnotations, methods, method, methodKey, *_0$$3, _1$$3, _4$$4, _6$$6;
	zval className, methodName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&methodName);
	ZVAL_UNDEF(&classAnnotations);
	ZVAL_UNDEF(&methods);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&methodKey);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &className_param, &methodName_param);

	zephir_get_strval(&className, className_param);
	zephir_get_strval(&methodName, methodName_param);


	ZEPHIR_CALL_METHOD(&classAnnotations, this_ptr, "get", NULL, 0, &className);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&methods, &classAnnotations, "getmethodsannotations", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&methods) == IS_ARRAY) {
		zephir_is_iterable(&methods, 0, "phalcon/Annotations/Adapter/AbstractAdapter.zep", 94);
		if (Z_TYPE_P(&methods) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&methods), _2$$3, _3$$3, _0$$3)
			{
				ZEPHIR_INIT_NVAR(&methodKey);
				if (_3$$3 != NULL) { 
					ZVAL_STR_COPY(&methodKey, _3$$3);
				} else {
					ZVAL_LONG(&methodKey, _2$$3);
				}
				ZEPHIR_INIT_NVAR(&method);
				ZVAL_COPY(&method, _0$$3);
				ZEPHIR_CALL_FUNCTION(&_4$$4, "strcasecmp", &_5, 47, &methodKey, &methodName);
				zephir_check_call_status();
				if (!(zephir_is_true(&_4$$4))) {
					RETURN_CCTOR(&method);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &methods, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, &methods, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&methodKey, &methods, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&method, &methods, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&_6$$6, "strcasecmp", &_5, 47, &methodKey, &methodName);
					zephir_check_call_status();
					if (!(zephir_is_true(&_6$$6))) {
						RETURN_CCTOR(&method);
					}
				ZEPHIR_CALL_METHOD(NULL, &methods, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&method);
		ZEPHIR_INIT_NVAR(&methodKey);
	}
	object_init_ex(return_value, phalcon_annotations_collection_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 48);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the annotations found in all the class' methods
 */
PHP_METHOD(Phalcon_Annotations_Adapter_AbstractAdapter, getMethods) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	ZEPHIR_RETURN_CALL_METHOD(&classAnnotations, "getmethodsannotations", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the annotations found in a specific property
 */
PHP_METHOD(Phalcon_Annotations_Adapter_AbstractAdapter, getProperty) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	ZEPHIR_CALL_METHOD(&properties, &classAnnotations, "getpropertiesannotations", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_array_isset_fetch(&property, &properties, &propertyName, 1))) {
		object_init_ex(return_value, phalcon_annotations_collection_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 48);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CTOR(&property);

}

/**
 * Returns the annotations found in all the class' methods
 */
PHP_METHOD(Phalcon_Annotations_Adapter_AbstractAdapter, getProperties) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	ZEPHIR_RETURN_CALL_METHOD(&classAnnotations, "getpropertiesannotations", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the annotation reader
 */
PHP_METHOD(Phalcon_Annotations_Adapter_AbstractAdapter, getReader) {

	zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("reader"), PH_NOISY_CC);
	if (Z_TYPE_P(&_0) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_annotations_reader_ce);
		if (zephir_has_constructor(&_1$$3)) {
			ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("reader"), &_1$$3);
	}
	RETURN_MM_MEMBER(getThis(), "reader");

}

/**
 * Sets the annotations parser
 */
PHP_METHOD(Phalcon_Annotations_Adapter_AbstractAdapter, setReader) {

	zval *reader, reader_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&reader_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &reader);



	zephir_update_property_zval(this_ptr, ZEND_STRL("reader"), reader);

}

zend_object *zephir_init_properties_Phalcon_Annotations_Adapter_AbstractAdapter(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("annotations"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("annotations"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

