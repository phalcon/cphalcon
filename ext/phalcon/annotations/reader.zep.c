
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
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Parses docblocks returning an array with the found annotations
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Reader) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Annotations, Reader, phalcon, annotations_reader, phalcon_annotations_reader_method_entry, 0);

	zend_class_implements(phalcon_annotations_reader_ce, 1, phalcon_annotations_readerinterface_ce);
	return SUCCESS;

}

/**
 * Reads annotations from the class docblocks, its methods and/or properties
 */
PHP_METHOD(Phalcon_Annotations_Reader, parse) {

	zval annotations;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, line = 0;
	zval *className_param = NULL, reflection, comment, properties, methods, property, method, classAnnotations, annotationsProperties, propertyAnnotations, annotationsMethods, methodAnnotations, _0$$3, _1$$3, *_2$$5, _3$$5, _4$$7, _5$$7, _6$$8, _7$$10, _8$$10, _9$$11, *_10$$13, _11$$13, _12$$15, _13$$15, _14$$16, _15$$18, _16$$18, _17$$19;
	zval className;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className);
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
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_11$$13);
	ZVAL_UNDEF(&_12$$15);
	ZVAL_UNDEF(&_13$$15);
	ZVAL_UNDEF(&_14$$16);
	ZVAL_UNDEF(&_15$$18);
	ZVAL_UNDEF(&_16$$18);
	ZVAL_UNDEF(&_17$$19);
	ZVAL_UNDEF(&annotations);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);

	zephir_get_strval(&className, className_param);


	ZEPHIR_INIT_VAR(&annotations);
	array_init(&annotations);
	ZEPHIR_INIT_VAR(&reflection);
	object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionclass")));
	ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 153, &className);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&comment, &reflection, "getdoccomment", NULL, 154);
	zephir_check_call_status();
	if (Z_TYPE_P(&comment) == IS_STRING) {
		ZEPHIR_INIT_VAR(&classAnnotations);
		ZEPHIR_CALL_METHOD(&_0$$3, &reflection, "getfilename", NULL, 155);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1$$3, &reflection, "getstartline", NULL, 156);
		zephir_check_call_status();
		ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(&classAnnotations, &comment, &_0$$3, &_1$$3 TSRMLS_CC);
		zephir_check_call_status();
		if (Z_TYPE_P(&classAnnotations) == IS_ARRAY) {
			zephir_array_update_string(&annotations, SL("class"), &classAnnotations, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_CALL_METHOD(&properties, &reflection, "getproperties", NULL, 157);
	zephir_check_call_status();
	if (zephir_fast_count_int(&properties)) {
		line = 1;
		ZEPHIR_INIT_VAR(&annotationsProperties);
		array_init(&annotationsProperties);
		zephir_is_iterable(&properties, 0, "/home/nikos/Work/niden/cphalcon/phalcon/Annotations/Reader.zep", 92);
		if (Z_TYPE_P(&properties) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&properties), _2$$5)
			{
				ZEPHIR_INIT_NVAR(&property);
				ZVAL_COPY(&property, _2$$5);
				ZEPHIR_CALL_METHOD(&comment, &property, "getdoccomment", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&comment) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&propertyAnnotations);
					ZEPHIR_CALL_METHOD(&_4$$7, &reflection, "getfilename", NULL, 155);
					zephir_check_call_status();
					ZVAL_LONG(&_5$$7, line);
					ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(&propertyAnnotations, &comment, &_4$$7, &_5$$7 TSRMLS_CC);
					zephir_check_call_status();
					if (Z_TYPE_P(&propertyAnnotations) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&_6$$8);
						zephir_read_property(&_6$$8, &property, SL("name"), PH_NOISY_CC);
						zephir_array_update_zval(&annotationsProperties, &_6$$8, &propertyAnnotations, PH_COPY | PH_SEPARATE);
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &properties, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_3$$5, &properties, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_3$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&property, &properties, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&comment, &property, "getdoccomment", NULL, 0);
					zephir_check_call_status();
					if (Z_TYPE_P(&comment) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&propertyAnnotations);
						ZEPHIR_CALL_METHOD(&_7$$10, &reflection, "getfilename", NULL, 155);
						zephir_check_call_status();
						ZVAL_LONG(&_8$$10, line);
						ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(&propertyAnnotations, &comment, &_7$$10, &_8$$10 TSRMLS_CC);
						zephir_check_call_status();
						if (Z_TYPE_P(&propertyAnnotations) == IS_ARRAY) {
							ZEPHIR_OBS_NVAR(&_9$$11);
							zephir_read_property(&_9$$11, &property, SL("name"), PH_NOISY_CC);
							zephir_array_update_zval(&annotationsProperties, &_9$$11, &propertyAnnotations, PH_COPY | PH_SEPARATE);
						}
					}
				ZEPHIR_CALL_METHOD(NULL, &properties, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&property);
		if (zephir_fast_count_int(&annotationsProperties)) {
			zephir_array_update_string(&annotations, SL("properties"), &annotationsProperties, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_CALL_METHOD(&methods, &reflection, "getmethods", NULL, 158);
	zephir_check_call_status();
	if (zephir_fast_count_int(&methods)) {
		ZEPHIR_INIT_VAR(&annotationsMethods);
		array_init(&annotationsMethods);
		zephir_is_iterable(&methods, 0, "/home/nikos/Work/niden/cphalcon/phalcon/Annotations/Reader.zep", 127);
		if (Z_TYPE_P(&methods) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&methods), _10$$13)
			{
				ZEPHIR_INIT_NVAR(&method);
				ZVAL_COPY(&method, _10$$13);
				ZEPHIR_CALL_METHOD(&comment, &method, "getdoccomment", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&comment) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&methodAnnotations);
					ZEPHIR_CALL_METHOD(&_12$$15, &method, "getfilename", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_13$$15, &method, "getstartline", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(&methodAnnotations, &comment, &_12$$15, &_13$$15 TSRMLS_CC);
					zephir_check_call_status();
					if (Z_TYPE_P(&methodAnnotations) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&_14$$16);
						zephir_read_property(&_14$$16, &method, SL("name"), PH_NOISY_CC);
						zephir_array_update_zval(&annotationsMethods, &_14$$16, &methodAnnotations, PH_COPY | PH_SEPARATE);
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &methods, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_11$$13, &methods, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_11$$13)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&method, &methods, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&comment, &method, "getdoccomment", NULL, 0);
					zephir_check_call_status();
					if (Z_TYPE_P(&comment) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&methodAnnotations);
						ZEPHIR_CALL_METHOD(&_15$$18, &method, "getfilename", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_16$$18, &method, "getstartline", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(&methodAnnotations, &comment, &_15$$18, &_16$$18 TSRMLS_CC);
						zephir_check_call_status();
						if (Z_TYPE_P(&methodAnnotations) == IS_ARRAY) {
							ZEPHIR_OBS_NVAR(&_17$$19);
							zephir_read_property(&_17$$19, &method, SL("name"), PH_NOISY_CC);
							zephir_array_update_zval(&annotationsMethods, &_17$$19, &methodAnnotations, PH_COPY | PH_SEPARATE);
						}
					}
				ZEPHIR_CALL_METHOD(NULL, &methods, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&method);
		if (zephir_fast_count_int(&annotationsMethods)) {
			zephir_array_update_string(&annotations, SL("methods"), &annotationsMethods, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CTOR(&annotations);

}

/**
 * Parses a raw doc block returning the annotations found
 */
PHP_METHOD(Phalcon_Annotations_Reader, parseDocBlock) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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

