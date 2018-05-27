
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

	HashTable *_3$$5, *_9$$10;
	HashPosition _2$$5, _8$$10;
	zend_long ZEPHIR_LAST_CALL_STATUS, line = 0;
	zval *className_param = NULL, *annotations = NULL, *reflection = NULL, *comment = NULL, *properties = NULL, *methods = NULL, *property = NULL, *method = NULL, *classAnnotations = NULL, *annotationsProperties = NULL, *propertyAnnotations = NULL, *annotationsMethods = NULL, *methodAnnotations = NULL, *_0$$3 = NULL, *_1$$3 = NULL, **_4$$5, *_5$$7 = NULL, *_6$$7 = NULL, *_7$$8 = NULL, **_10$$10, *_11$$12 = NULL, *_12$$12 = NULL, *_13$$13 = NULL;
	zval *className = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);

	zephir_get_strval(className, className_param);


	ZEPHIR_INIT_VAR(annotations);
	array_init(annotations);
	ZEPHIR_INIT_VAR(reflection);
	object_init_ex(reflection, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, reflection, "__construct", NULL, 98, className);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&comment, reflection, "getdoccomment", NULL, 99);
	zephir_check_call_status();
	if (Z_TYPE_P(comment) == IS_STRING) {
		ZEPHIR_INIT_VAR(classAnnotations);
		ZEPHIR_CALL_METHOD(&_0$$3, reflection, "getfilename", NULL, 100);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1$$3, reflection, "getstartline", NULL, 101);
		zephir_check_call_status();
		ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(classAnnotations, comment, _0$$3, _1$$3 TSRMLS_CC);
		zephir_check_call_status();
		if (Z_TYPE_P(classAnnotations) == IS_ARRAY) {
			zephir_array_update_string(&annotations, SL("class"), &classAnnotations, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_CALL_METHOD(&properties, reflection, "getproperties", NULL, 102);
	zephir_check_call_status();
	if (zephir_fast_count_int(properties TSRMLS_CC)) {
		line = 1;
		ZEPHIR_INIT_VAR(annotationsProperties);
		array_init(annotationsProperties);
		zephir_is_iterable(properties, &_3$$5, &_2$$5, 0, 0, "phalcon/annotations/reader.zep", 96);
		for (
		  ; zend_hash_get_current_data_ex(_3$$5, (void**) &_4$$5, &_2$$5) == SUCCESS
		  ; zend_hash_move_forward_ex(_3$$5, &_2$$5)
		) {
			ZEPHIR_GET_HVALUE(property, _4$$5);
			ZEPHIR_CALL_METHOD(&comment, property, "getdoccomment", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(comment) == IS_STRING) {
				ZEPHIR_INIT_NVAR(propertyAnnotations);
				ZEPHIR_CALL_METHOD(&_5$$7, reflection, "getfilename", NULL, 100);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_6$$7);
				ZVAL_LONG(_6$$7, line);
				ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(propertyAnnotations, comment, _5$$7, _6$$7 TSRMLS_CC);
				zephir_check_call_status();
				if (Z_TYPE_P(propertyAnnotations) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(_7$$8);
					zephir_read_property(&_7$$8, property, SL("name"), PH_NOISY_CC);
					zephir_array_update_zval(&annotationsProperties, _7$$8, &propertyAnnotations, PH_COPY | PH_SEPARATE);
				}
			}
		}
		if (zephir_fast_count_int(annotationsProperties TSRMLS_CC)) {
			zephir_array_update_string(&annotations, SL("properties"), &annotationsProperties, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_CALL_METHOD(&methods, reflection, "getmethods", NULL, 103);
	zephir_check_call_status();
	if (zephir_fast_count_int(methods TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(annotationsMethods);
		array_init(annotationsMethods);
		zephir_is_iterable(methods, &_9$$10, &_8$$10, 0, 0, "phalcon/annotations/reader.zep", 126);
		for (
		  ; zend_hash_get_current_data_ex(_9$$10, (void**) &_10$$10, &_8$$10) == SUCCESS
		  ; zend_hash_move_forward_ex(_9$$10, &_8$$10)
		) {
			ZEPHIR_GET_HVALUE(method, _10$$10);
			ZEPHIR_CALL_METHOD(&comment, method, "getdoccomment", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(comment) == IS_STRING) {
				ZEPHIR_INIT_NVAR(methodAnnotations);
				ZEPHIR_CALL_METHOD(&_11$$12, method, "getfilename", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_12$$12, method, "getstartline", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(methodAnnotations, comment, _11$$12, _12$$12 TSRMLS_CC);
				zephir_check_call_status();
				if (Z_TYPE_P(methodAnnotations) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(_13$$13);
					zephir_read_property(&_13$$13, method, SL("name"), PH_NOISY_CC);
					zephir_array_update_zval(&annotationsMethods, _13$$13, &methodAnnotations, PH_COPY | PH_SEPARATE);
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
 */
PHP_METHOD(Phalcon_Annotations_Reader, parseDocBlock) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *docBlock_param = NULL, *file = NULL, *line = NULL;
	zval *docBlock = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &docBlock_param, &file, &line);

	zephir_get_strval(docBlock, docBlock_param);
	if (!file) {
		ZEPHIR_CPY_WRT(file, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(file);
	}
	if (!line) {
		line = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(file) != IS_STRING) {
		ZEPHIR_INIT_NVAR(file);
		ZVAL_STRING(file, "eval code", 1);
	}
	ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(return_value, docBlock, file, line TSRMLS_CC);
	zephir_check_call_status();
	RETURN_MM();

}

