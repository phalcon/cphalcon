
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"


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
/**
 * Phalcon\Annotations\Reader
 *
 * Parses docblocks returning an array with the found annotations
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Reader) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Annotations, Reader, phalcon, annotations_reader, phalcon_annotations_reader_method_entry, 0);

	zend_class_implements(phalcon_annotations_reader_ce TSRMLS_CC, 1, phalcon_annotations_readerinterface_ce);

	return SUCCESS;

}

/**
 * Reads annotations from the class dockblocks, its methods and/or properties
 *
 * @param string className
 * @return array
 */
PHP_METHOD(Phalcon_Annotations_Reader, parse) {

	HashTable *_4, *_8;
	HashPosition _3, _7;
	zend_class_entry *_0;
	int line;
	zval *className_param = NULL, *annotations, *reflection, *comment = NULL, *properties, *methods, *property = NULL, *method = NULL, *classAnnotations, *annotationsProperties, *propertyAnnotations = NULL, *annotationsMethods, *methodAnnotations = NULL, *_1 = NULL, *_2 = NULL, **_5, *_6 = NULL, **_9;
	zval *className = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);

		zephir_get_strval(className, className_param);


	ZEPHIR_INIT_VAR(annotations);
	array_init(annotations);
	ZEPHIR_INIT_VAR(reflection);
	_0 = zend_fetch_class(SL("ReflectionClass"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(reflection, _0);
	zephir_call_method_p1_noret(reflection, "__construct", className);
	ZEPHIR_INIT_VAR(comment);
	zephir_call_method(comment, reflection, "getdoccomment");
	if ((Z_TYPE_P(comment) == IS_STRING)) {
		ZEPHIR_INIT_VAR(_1);
		zephir_call_method(_1, reflection, "getfilename");
		ZEPHIR_INIT_VAR(_2);
		zephir_call_method(_2, reflection, "getstartline");
		ZEPHIR_INIT_VAR(classAnnotations);
		zephir_call_func_p3(classAnnotations, "phannot_parse_annotations", comment, _1, _2);
		if ((Z_TYPE_P(classAnnotations) == IS_ARRAY)) {
			zephir_array_update_string(&annotations, SL("class"), &classAnnotations, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_VAR(properties);
	zephir_call_method(properties, reflection, "getproperties");
	if (zephir_fast_count_int(properties TSRMLS_CC)) {
		line = 1;
		ZEPHIR_INIT_VAR(annotationsProperties);
		array_init(annotationsProperties);
		zephir_is_iterable(properties, &_4, &_3, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
			; zend_hash_move_forward_ex(_4, &_3)
		) {
			ZEPHIR_GET_HVALUE(property, _5);
			ZEPHIR_INIT_NVAR(comment);
			zephir_call_method(comment, property, "getdoccomment");
			if ((Z_TYPE_P(comment) == IS_STRING)) {
				ZEPHIR_INIT_NVAR(_1);
				zephir_call_method(_1, reflection, "getfilename");
				ZEPHIR_INIT_NVAR(_2);
				ZVAL_LONG(_2, line);
				ZEPHIR_INIT_NVAR(propertyAnnotations);
				zephir_call_func_p3(propertyAnnotations, "phannot_parse_annotations", comment, _1, _2);
				if ((Z_TYPE_P(propertyAnnotations) == IS_ARRAY)) {
					ZEPHIR_OBS_NVAR(_6);
					zephir_read_property(&_6, property, SL("name"), PH_NOISY_CC);
					zephir_array_update_zval(&annotationsProperties, _6, &propertyAnnotations, PH_COPY | PH_SEPARATE);
				}
			}
		}
		if (zephir_fast_count_int(annotationsProperties TSRMLS_CC)) {
			zephir_array_update_string(&annotations, SL("properties"), &annotationsProperties, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_VAR(methods);
	zephir_call_method(methods, reflection, "getmethods");
	if (zephir_fast_count_int(methods TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(annotationsMethods);
		array_init(annotationsMethods);
		zephir_is_iterable(methods, &_8, &_7, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
			; zend_hash_move_forward_ex(_8, &_7)
		) {
			ZEPHIR_GET_HVALUE(method, _9);
			ZEPHIR_INIT_NVAR(comment);
			zephir_call_method(comment, method, "getdoccomment");
			if ((Z_TYPE_P(comment) == IS_STRING)) {
				ZEPHIR_INIT_NVAR(_1);
				zephir_call_method(_1, method, "getfilename");
				ZEPHIR_INIT_NVAR(_2);
				zephir_call_method(_2, method, "getstartline");
				ZEPHIR_INIT_NVAR(methodAnnotations);
				zephir_call_func_p3(methodAnnotations, "phannot_parse_annotations", comment, _1, _2);
				if ((Z_TYPE_P(methodAnnotations) == IS_ARRAY)) {
					ZEPHIR_OBS_NVAR(_6);
					zephir_read_property(&_6, method, SL("name"), PH_NOISY_CC);
					zephir_array_update_zval(&annotationsMethods, _6, &methodAnnotations, PH_COPY | PH_SEPARATE);
				}
			}
		}
		if (zephir_fast_count_int(annotationsMethods TSRMLS_CC)) {
			zephir_array_update_string(&annotations, SL("methods"), &annotationsMethods, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(annotations);

}

/**
 * Parses a raw doc block returning the annotations found
 *
 * @param string docBlock
 * @return array
 */
PHP_METHOD(Phalcon_Annotations_Reader, parseDocBlock) {

	zval *docBlock_param = NULL, *file = NULL, *line = NULL;
	zval *docBlock = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &docBlock_param, &file, &line);

		zephir_get_strval(docBlock, docBlock_param);
	if (!file) {
		ZEPHIR_CPY_WRT(file, ZEPHIR_GLOBAL(global_null));
	}
	ZEPHIR_SEPARATE_PARAM(file);
	if (!line) {
		ZEPHIR_CPY_WRT(line, ZEPHIR_GLOBAL(global_null));
	}


	if ((Z_TYPE_P(file) != IS_STRING)) {
		ZEPHIR_INIT_NVAR(file);
		ZVAL_STRING(file, "eval code", 1);
	}
	zephir_call_func_p3(return_value, "phannot_parse_annotations", docBlock, file, line);
	RETURN_MM();

}

