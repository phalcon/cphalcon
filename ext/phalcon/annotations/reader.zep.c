
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
#include "phalcon/annotations/scanner.h"
#include "phalcon/annotations/annot.h"


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
 */
PHP_METHOD(Phalcon_Annotations_Reader, parse) {

	zend_long ZEPHIR_LAST_CALL_STATUS, line = 0;
	zval *className_param = NULL, annotations, reflection, comment, properties, methods, property, method, classAnnotations, annotationsProperties, propertyAnnotations, annotationsMethods, methodAnnotations, _0$$3, _1$$3, *_2$$5, _3$$7, _4$$7, _5$$8, *_6$$10, _7$$12, _8$$12, _9$$13;
	zval className;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&annotations);
	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&comment);
	ZVAL_UNDEF(&properties);
	ZVAL_UNDEF(&methods);
	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&classAnnotations);
	ZVAL_UNDEF(&annotationsProperties);
	ZVAL_UNDEF(&propertyAnnotations);
	ZVAL_UNDEF(&annotationsMethods);
	ZVAL_UNDEF(&methodAnnotations);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_7$$12);
	ZVAL_UNDEF(&_8$$12);
	ZVAL_UNDEF(&_9$$13);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);

	zephir_get_strval(&className, className_param);


	ZEPHIR_INIT_VAR(&annotations);
	array_init(&annotations);
	ZEPHIR_INIT_VAR(&reflection);
	object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionclass")));
	ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 87, &className);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&comment, &reflection, "getdoccomment", NULL, 88);
	zephir_check_call_status();
	if (Z_TYPE_P(&comment) == IS_STRING) {
		ZEPHIR_INIT_VAR(&classAnnotations);
		ZEPHIR_CALL_METHOD(&_0$$3, &reflection, "getfilename", NULL, 89);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1$$3, &reflection, "getstartline", NULL, 90);
		zephir_check_call_status();
		ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(&classAnnotations, &comment, &_0$$3, &_1$$3 TSRMLS_CC);
		zephir_check_call_status();
		if (Z_TYPE_P(&classAnnotations) == IS_ARRAY) {
			zephir_array_update_string(&annotations, SL("class"), &classAnnotations, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_CALL_METHOD(&properties, &reflection, "getproperties", NULL, 91);
	zephir_check_call_status();
	if (zephir_fast_count_int(&properties TSRMLS_CC)) {
		line = 1;
		ZEPHIR_INIT_VAR(&annotationsProperties);
		array_init(&annotationsProperties);
		zephir_is_iterable(&properties, 0, "phalcon/annotations/reader.zep", 96);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&properties), _2$$5)
		{
			ZEPHIR_INIT_NVAR(&property);
			ZVAL_COPY(&property, _2$$5);
			ZEPHIR_CALL_METHOD(&comment, &property, "getdoccomment", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&comment) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&propertyAnnotations);
				ZEPHIR_CALL_METHOD(&_3$$7, &reflection, "getfilename", NULL, 89);
				zephir_check_call_status();
				ZVAL_LONG(&_4$$7, line);
				ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(&propertyAnnotations, &comment, &_3$$7, &_4$$7 TSRMLS_CC);
				zephir_check_call_status();
				if (Z_TYPE_P(&propertyAnnotations) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&_5$$8);
					zephir_read_property(&_5$$8, &property, SL("name"), PH_NOISY_CC);
					zephir_array_update_zval(&annotationsProperties, &_5$$8, &propertyAnnotations, PH_COPY | PH_SEPARATE);
				}
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&property);
		if (zephir_fast_count_int(&annotationsProperties TSRMLS_CC)) {
			zephir_array_update_string(&annotations, SL("properties"), &annotationsProperties, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_CALL_METHOD(&methods, &reflection, "getmethods", NULL, 92);
	zephir_check_call_status();
	if (zephir_fast_count_int(&methods TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&annotationsMethods);
		array_init(&annotationsMethods);
		zephir_is_iterable(&methods, 0, "phalcon/annotations/reader.zep", 126);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&methods), _6$$10)
		{
			ZEPHIR_INIT_NVAR(&method);
			ZVAL_COPY(&method, _6$$10);
			ZEPHIR_CALL_METHOD(&comment, &method, "getdoccomment", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&comment) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&methodAnnotations);
				ZEPHIR_CALL_METHOD(&_7$$12, &method, "getfilename", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_8$$12, &method, "getstartline", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(&methodAnnotations, &comment, &_7$$12, &_8$$12 TSRMLS_CC);
				zephir_check_call_status();
				if (Z_TYPE_P(&methodAnnotations) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&_9$$13);
					zephir_read_property(&_9$$13, &method, SL("name"), PH_NOISY_CC);
					zephir_array_update_zval(&annotationsMethods, &_9$$13, &methodAnnotations, PH_COPY | PH_SEPARATE);
				}
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&method);
		if (zephir_fast_count_int(&annotationsMethods TSRMLS_CC)) {
			zephir_array_update_string(&annotations, SL("methods"), &annotationsMethods, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(&annotations);

}

/**
 * Parses a raw doc block returning the annotations found
 */
PHP_METHOD(Phalcon_Annotations_Reader, parseDocBlock) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *docBlock_param = NULL, *file = NULL, file_sub, *line = NULL, line_sub, __$null;
	zval docBlock;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&docBlock);
	ZVAL_UNDEF(&file_sub);
	ZVAL_UNDEF(&line_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &docBlock_param, &file, &line);

	zephir_get_strval(&docBlock, docBlock_param);
	if (!file) {
		file = &file_sub;
		ZEPHIR_CPY_WRT(file, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(file);
	}
	if (!line) {
		line = &line_sub;
		line = &__$null;
	}


	if (Z_TYPE_P(file) != IS_STRING) {
		ZEPHIR_INIT_NVAR(file);
		ZVAL_STRING(file, "eval code");
	}
	ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(return_value, &docBlock, file, line TSRMLS_CC);
	zephir_check_call_status();
	RETURN_MM();

}

