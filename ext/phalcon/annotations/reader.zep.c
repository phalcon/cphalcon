
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
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/object.h"
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
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Reader)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Annotations, Reader, phalcon, annotations_reader, phalcon_annotations_reader_method_entry, 0);

	zend_class_implements(phalcon_annotations_reader_ce, 1, phalcon_annotations_readerinterface_ce);
	return SUCCESS;
}

/**
 * Reads annotations from the class docblocks, its methods and/or properties
 */
PHP_METHOD(Phalcon_Annotations_Reader, parse)
{
	zend_bool _11$$10, _20$$18;
	zval annotations;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, line = 0;
	zval className_zv, reflection, comment, arrayKeys, classAnnotations, properties, property, annotationsProperties, propertyAnnotations, methods, method, annotationsMethods, methodAnnotations, constants, constant, anotationsConstants, constantAnnotations, constantReflection, _0$$3, _1$$3, *_2$$5, _4$$7, _5$$7, *_6$$10, _10$$10, _7$$12, _8$$12, _9$$13, _12$$15, _13$$15, _14$$16, *_15$$18, _19$$18, _16$$20, _17$$20, _18$$21, _21$$23, _22$$23, _23$$24;
	zend_string *className = NULL;

	ZVAL_UNDEF(&className_zv);
	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&comment);
	ZVAL_UNDEF(&arrayKeys);
	ZVAL_UNDEF(&classAnnotations);
	ZVAL_UNDEF(&properties);
	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&annotationsProperties);
	ZVAL_UNDEF(&propertyAnnotations);
	ZVAL_UNDEF(&methods);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&annotationsMethods);
	ZVAL_UNDEF(&methodAnnotations);
	ZVAL_UNDEF(&constants);
	ZVAL_UNDEF(&constant);
	ZVAL_UNDEF(&anotationsConstants);
	ZVAL_UNDEF(&constantAnnotations);
	ZVAL_UNDEF(&constantReflection);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_7$$12);
	ZVAL_UNDEF(&_8$$12);
	ZVAL_UNDEF(&_9$$13);
	ZVAL_UNDEF(&_12$$15);
	ZVAL_UNDEF(&_13$$15);
	ZVAL_UNDEF(&_14$$16);
	ZVAL_UNDEF(&_19$$18);
	ZVAL_UNDEF(&_16$$20);
	ZVAL_UNDEF(&_17$$20);
	ZVAL_UNDEF(&_18$$21);
	ZVAL_UNDEF(&_21$$23);
	ZVAL_UNDEF(&_22$$23);
	ZVAL_UNDEF(&_23$$24);
	ZVAL_UNDEF(&annotations);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(className)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&className_zv);
	ZVAL_STR_COPY(&className_zv, className);
	ZEPHIR_INIT_VAR(&annotations);
	array_init(&annotations);
	ZEPHIR_INIT_VAR(&reflection);
	object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionclass")));
	ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 262, &className_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&comment, &reflection, "getdoccomment", NULL, 274);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&comment)) {
		ZEPHIR_INIT_VAR(&classAnnotations);
		ZEPHIR_CALL_METHOD(&_0$$3, &reflection, "getfilename", NULL, 275);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1$$3, &reflection, "getstartline", NULL, 276);
		zephir_check_call_status();
		ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(&classAnnotations, &comment, &_0$$3, &_1$$3);
		zephir_check_call_status();
		if (Z_TYPE_P(&classAnnotations) == IS_ARRAY) {
			zephir_array_update_string(&annotations, SL("class"), &classAnnotations, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_CALL_METHOD(&constants, &reflection, "getconstants", NULL, 277);
	zephir_check_call_status();
	if (zephir_fast_count_int(&constants)) {
		line = 1;
		ZEPHIR_INIT_VAR(&arrayKeys);
		zephir_array_keys(&arrayKeys, &constants);
		ZEPHIR_INIT_VAR(&anotationsConstants);
		array_init(&anotationsConstants);
		zephir_is_iterable(&arrayKeys, 0, "phalcon/Annotations/Reader.zep", 92);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&arrayKeys), _2$$5)
		{
			ZEPHIR_INIT_NVAR(&constant);
			ZVAL_COPY(&constant, _2$$5);
			ZEPHIR_CALL_METHOD(&constantReflection, &reflection, "getreflectionconstant", &_3, 278, &constant);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&comment, &constantReflection, "getdoccomment", NULL, 0);
			zephir_check_call_status();
			if (!ZEPHIR_IS_FALSE_IDENTICAL(&comment)) {
				ZEPHIR_INIT_NVAR(&constantAnnotations);
				ZEPHIR_CALL_METHOD(&_4$$7, &reflection, "getfilename", NULL, 275);
				zephir_check_call_status();
				ZVAL_LONG(&_5$$7, line);
				ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(&constantAnnotations, &comment, &_4$$7, &_5$$7);
				zephir_check_call_status();
				if (Z_TYPE_P(&constantAnnotations) == IS_ARRAY) {
					zephir_array_update_zval(&anotationsConstants, &constant, &constantAnnotations, PH_COPY | PH_SEPARATE);
				}
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&constant);
		if (zephir_fast_count_int(&anotationsConstants)) {
			zephir_array_update_string(&annotations, SL("constants"), &anotationsConstants, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_CALL_METHOD(&properties, &reflection, "getproperties", NULL, 279);
	zephir_check_call_status();
	if (zephir_fast_count_int(&properties)) {
		line = 1;
		ZEPHIR_INIT_VAR(&annotationsProperties);
		array_init(&annotationsProperties);
		zephir_is_iterable(&properties, 0, "phalcon/Annotations/Reader.zep", 130);
		if (Z_TYPE_P(&properties) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&properties), _6$$10)
			{
				ZEPHIR_INIT_NVAR(&property);
				ZVAL_COPY(&property, _6$$10);
				ZEPHIR_CALL_METHOD(&comment, &property, "getdoccomment", NULL, 0);
				zephir_check_call_status();
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&comment)) {
					ZEPHIR_INIT_NVAR(&propertyAnnotations);
					ZEPHIR_CALL_METHOD(&_7$$12, &reflection, "getfilename", NULL, 275);
					zephir_check_call_status();
					ZVAL_LONG(&_8$$12, line);
					ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(&propertyAnnotations, &comment, &_7$$12, &_8$$12);
					zephir_check_call_status();
					if (Z_TYPE_P(&propertyAnnotations) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&_9$$13);
						zephir_read_property(&_9$$13, &property, ZEND_STRL("name"), PH_NOISY_CC);
						zephir_array_update_zval(&annotationsProperties, &_9$$13, &propertyAnnotations, PH_COPY | PH_SEPARATE);
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &properties, "rewind", NULL, 0);
			zephir_check_call_status();
			_11$$10 = 1;
			while (1) {
				if (_11$$10) {
					_11$$10 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &properties, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_10$$10, &properties, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_10$$10)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&property, &properties, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&comment, &property, "getdoccomment", NULL, 0);
					zephir_check_call_status();
					if (!ZEPHIR_IS_FALSE_IDENTICAL(&comment)) {
						ZEPHIR_INIT_NVAR(&propertyAnnotations);
						ZEPHIR_CALL_METHOD(&_12$$15, &reflection, "getfilename", NULL, 275);
						zephir_check_call_status();
						ZVAL_LONG(&_13$$15, line);
						ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(&propertyAnnotations, &comment, &_12$$15, &_13$$15);
						zephir_check_call_status();
						if (Z_TYPE_P(&propertyAnnotations) == IS_ARRAY) {
							ZEPHIR_OBS_NVAR(&_14$$16);
							zephir_read_property(&_14$$16, &property, ZEND_STRL("name"), PH_NOISY_CC);
							zephir_array_update_zval(&annotationsProperties, &_14$$16, &propertyAnnotations, PH_COPY | PH_SEPARATE);
						}
					}
			}
		}
		ZEPHIR_INIT_NVAR(&property);
		if (zephir_fast_count_int(&annotationsProperties)) {
			zephir_array_update_string(&annotations, SL("properties"), &annotationsProperties, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_CALL_METHOD(&methods, &reflection, "getmethods", NULL, 280);
	zephir_check_call_status();
	if (0 == ZEPHIR_IS_EMPTY(&methods)) {
		ZEPHIR_INIT_VAR(&annotationsMethods);
		array_init(&annotationsMethods);
		zephir_is_iterable(&methods, 0, "phalcon/Annotations/Reader.zep", 164);
		if (Z_TYPE_P(&methods) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&methods), _15$$18)
			{
				ZEPHIR_INIT_NVAR(&method);
				ZVAL_COPY(&method, _15$$18);
				ZEPHIR_CALL_METHOD(&comment, &method, "getdoccomment", NULL, 0);
				zephir_check_call_status();
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&comment)) {
					ZEPHIR_INIT_NVAR(&methodAnnotations);
					ZEPHIR_CALL_METHOD(&_16$$20, &method, "getfilename", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_17$$20, &method, "getstartline", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(&methodAnnotations, &comment, &_16$$20, &_17$$20);
					zephir_check_call_status();
					if (Z_TYPE_P(&methodAnnotations) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&_18$$21);
						zephir_read_property(&_18$$21, &method, ZEND_STRL("name"), PH_NOISY_CC);
						zephir_array_update_zval(&annotationsMethods, &_18$$21, &methodAnnotations, PH_COPY | PH_SEPARATE);
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &methods, "rewind", NULL, 0);
			zephir_check_call_status();
			_20$$18 = 1;
			while (1) {
				if (_20$$18) {
					_20$$18 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &methods, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_19$$18, &methods, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_19$$18)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&method, &methods, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&comment, &method, "getdoccomment", NULL, 0);
					zephir_check_call_status();
					if (!ZEPHIR_IS_FALSE_IDENTICAL(&comment)) {
						ZEPHIR_INIT_NVAR(&methodAnnotations);
						ZEPHIR_CALL_METHOD(&_21$$23, &method, "getfilename", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_22$$23, &method, "getstartline", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(&methodAnnotations, &comment, &_21$$23, &_22$$23);
						zephir_check_call_status();
						if (Z_TYPE_P(&methodAnnotations) == IS_ARRAY) {
							ZEPHIR_OBS_NVAR(&_23$$24);
							zephir_read_property(&_23$$24, &method, ZEND_STRL("name"), PH_NOISY_CC);
							zephir_array_update_zval(&annotationsMethods, &_23$$24, &methodAnnotations, PH_COPY | PH_SEPARATE);
						}
					}
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
PHP_METHOD(Phalcon_Annotations_Reader, parseDocBlock)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval docBlock_zv, *file = NULL, file_sub, *line = NULL, line_sub, __$null;
	zend_string *docBlock = NULL;

	ZVAL_UNDEF(&docBlock_zv);
	ZVAL_UNDEF(&file_sub);
	ZVAL_UNDEF(&line_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(docBlock)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(file)
		Z_PARAM_ZVAL_OR_NULL(line)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		file = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		line = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&docBlock_zv);
	ZVAL_STR_COPY(&docBlock_zv, docBlock);
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
	ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(return_value, &docBlock_zv, file, line);
	zephir_check_call_status();
	RETURN_MM();
}

