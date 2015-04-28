
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
#include "kernel/hash.h"
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

	HashTable *_8, *_14;
	HashPosition _7, _13;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL, *_1 = NULL, *_3 = NULL, *_5 = NULL, *_6 = NULL, *_12 = NULL;
	int line, ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, *annotations, *reflection, *comment = NULL, *properties = NULL, *methods = NULL, *property = NULL, *method = NULL, *classAnnotations, *annotationsProperties, *propertyAnnotations = NULL, *annotationsMethods, *methodAnnotations = NULL, *_2 = NULL, *_4 = NULL, **_9, *_10 = NULL, *_11 = NULL, **_15;
	zval *className = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);

	zephir_get_strval(className, className_param);


	ZEPHIR_INIT_VAR(annotations);
	array_init(annotations);
	ZEPHIR_INIT_VAR(reflection);
	object_init_ex(reflection, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, reflection, "__construct", &_0, className);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&comment, reflection, "getdoccomment", &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(comment) == IS_STRING) {
		ZEPHIR_INIT_VAR(classAnnotations);
		ZEPHIR_CALL_METHOD(&_2, reflection, "getfilename", &_3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4, reflection, "getstartline", &_5);
		zephir_check_call_status();
		ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(classAnnotations, comment, _2, _4 TSRMLS_CC);
		zephir_check_call_status();
		if (Z_TYPE_P(classAnnotations) == IS_ARRAY) {
			zephir_array_update_string(&annotations, SL("class"), &classAnnotations, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_CALL_METHOD(&properties, reflection, "getproperties", &_6);
	zephir_check_call_status();
	if (zephir_fast_count_int(properties TSRMLS_CC)) {
		line = 1;
		ZEPHIR_INIT_VAR(annotationsProperties);
		array_init(annotationsProperties);
		zephir_is_iterable(properties, &_8, &_7, 0, 0, "phalcon/annotations/reader.zep", 96);
		for (
		  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
		  ; zephir_hash_move_forward_ex(_8, &_7)
		) {
			ZEPHIR_GET_HVALUE(property, _9);
			ZEPHIR_CALL_METHOD(&comment, property, "getdoccomment", NULL);
			zephir_check_call_status();
			if (Z_TYPE_P(comment) == IS_STRING) {
				ZEPHIR_INIT_NVAR(propertyAnnotations);
				ZEPHIR_CALL_METHOD(&_2, reflection, "getfilename", &_3);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_10);
				ZVAL_LONG(_10, line);
				ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(propertyAnnotations, comment, _2, _10 TSRMLS_CC);
				zephir_check_call_status();
				if (Z_TYPE_P(propertyAnnotations) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(_11);
					zephir_read_property(&_11, property, SL("name"), PH_NOISY_CC);
					zephir_array_update_zval(&annotationsProperties, _11, &propertyAnnotations, PH_COPY | PH_SEPARATE);
				}
			}
		}
		if (zephir_fast_count_int(annotationsProperties TSRMLS_CC)) {
			zephir_array_update_string(&annotations, SL("properties"), &annotationsProperties, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_CALL_METHOD(&methods, reflection, "getmethods", &_12);
	zephir_check_call_status();
	if (zephir_fast_count_int(methods TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(annotationsMethods);
		array_init(annotationsMethods);
		zephir_is_iterable(methods, &_14, &_13, 0, 0, "phalcon/annotations/reader.zep", 126);
		for (
		  ; zephir_hash_get_current_data_ex(_14, (void**) &_15, &_13) == SUCCESS
		  ; zephir_hash_move_forward_ex(_14, &_13)
		) {
			ZEPHIR_GET_HVALUE(method, _15);
			ZEPHIR_CALL_METHOD(&comment, method, "getdoccomment", NULL);
			zephir_check_call_status();
			if (Z_TYPE_P(comment) == IS_STRING) {
				ZEPHIR_INIT_NVAR(methodAnnotations);
				ZEPHIR_CALL_METHOD(&_2, method, "getfilename", NULL);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_4, method, "getstartline", NULL);
				zephir_check_call_status();
				ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(methodAnnotations, comment, _2, _4 TSRMLS_CC);
				zephir_check_call_status();
				if (Z_TYPE_P(methodAnnotations) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(_11);
					zephir_read_property(&_11, method, SL("name"), PH_NOISY_CC);
					zephir_array_update_zval(&annotationsMethods, _11, &methodAnnotations, PH_COPY | PH_SEPARATE);
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

	int ZEPHIR_LAST_CALL_STATUS;
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

