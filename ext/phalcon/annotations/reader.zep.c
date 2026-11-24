
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
#include "kernel/string.h"
#include "kernel/object.h"
#include "phalcon/annotations/scanner.h"
#include "phalcon/annotations/annot.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Parses docblocks returning an array with the found annotations
 *
 * @phpstan-import-type annotations_node_list from AnnotationsTypes
 * @phpstan-import-type annotations_reflection_data from AnnotationsTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Reader)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Annotations, Reader, phalcon, annotations_reader, phalcon_annotations_reader_method_entry, 0);

	zend_class_implements(phalcon_annotations_reader_ce, 1, phalcon_annotations_readerinterface_ce);
	return SUCCESS;
}

/**
 * Reads annotations from the class docblocks, its methods and/or properties
 *
 * @phpstan-param class-string $className
 *
 * @phpstan-return annotations_reflection_data
 */
PHP_METHOD(Phalcon_Annotations_Reader, parse)
{
	zend_bool _15$$10, _26$$18;
	zval annotations;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, line = 0;
	zval className_zv, reflection, comment, arrayKeys, classAnnotations, properties, property, annotationsProperties, propertyAnnotations, methods, method, annotationsMethods, methodAnnotations, constants, constant, anotationsConstants, constantAnnotations, constantReflection, _0, _1$$3, _2$$3, *_3$$5, _4$$5, *_5$$5, _6$$7, _7$$7, *_8$$10, _9$$10, *_10$$10, _14$$10, _11$$12, _12$$12, _13$$13, _16$$15, _17$$15, _18$$16, *_19$$18, _20$$18, *_21$$18, _25$$18, _22$$20, _23$$20, _24$$21, _27$$23, _28$$23, _29$$24;
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
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_13$$13);
	ZVAL_UNDEF(&_16$$15);
	ZVAL_UNDEF(&_17$$15);
	ZVAL_UNDEF(&_18$$16);
	ZVAL_UNDEF(&_20$$18);
	ZVAL_UNDEF(&_25$$18);
	ZVAL_UNDEF(&_22$$20);
	ZVAL_UNDEF(&_23$$20);
	ZVAL_UNDEF(&_24$$21);
	ZVAL_UNDEF(&_27$$23);
	ZVAL_UNDEF(&_28$$23);
	ZVAL_UNDEF(&_29$$24);
	ZVAL_UNDEF(&annotations);
	ZEND_TLS zephir_method_cache _zephir_call_cache[28];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("name", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(className)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&className_zv);
	ZVAL_STR_COPY(&className_zv, className);
	ZEPHIR_INIT_VAR(&annotations);
	array_init(&annotations);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zephir_get_internal_ce(SL("reflectionclass")));
	zephir_constructor_start(&_0);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "__construct", &_zephir_call_cache[0], &className_zv);
	zephir_check_call_status();
	zephir_constructor_finish(&_0);
	ZEPHIR_CPY_WRT(&reflection, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_CALL_METHOD_CACHED(&comment, &reflection, "getDocComment", &_zephir_call_cache[1]);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&comment)) {
		ZEPHIR_INIT_VAR(&classAnnotations);
		ZEPHIR_CALL_METHOD_CACHED(&_1$$3, &reflection, "getFileName", &_zephir_call_cache[2]);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_2$$3, &reflection, "getStartLine", &_zephir_call_cache[3]);
		zephir_check_call_status();
		ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(&classAnnotations, &comment, &_1$$3, &_2$$3);
		zephir_check_call_status();
		if (Z_TYPE_P(&classAnnotations) == IS_ARRAY) {
			zephir_array_update_string(&annotations, SL("class"), &classAnnotations, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(&constants, &reflection, "getConstants", &_zephir_call_cache[4]);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&constants))) {
		line = 1;
		ZEPHIR_INIT_VAR(&arrayKeys);
		zephir_array_keys(&arrayKeys, &constants);
		ZEPHIR_INIT_VAR(&anotationsConstants);
		array_init(&anotationsConstants);
		if (Z_TYPE_P(&arrayKeys) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_4$$5);
			zephir_string_to_char_array(&_4$$5, &arrayKeys);
			_3$$5 = &_4$$5;
		} else {
			_3$$5 = &arrayKeys;
		}
		zephir_is_iterable(_3$$5, 0, "phalcon/Annotations/Reader.zep", 100);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_3$$5), _5$$5)
		{
			ZEPHIR_INIT_NVAR(&constant);
			ZVAL_COPY(&constant, _5$$5);
			ZEPHIR_CALL_METHOD_CACHED(&constantReflection, &reflection, "getReflectionConstant", &_zephir_call_cache[5], &constant);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&comment, &constantReflection, "getDocComment", &_zephir_call_cache[6]);
			zephir_check_call_status();
			if (!ZEPHIR_IS_FALSE_IDENTICAL(&comment)) {
				ZEPHIR_INIT_NVAR(&constantAnnotations);
				ZEPHIR_CALL_METHOD_CACHED(&_6$$7, &reflection, "getFileName", &_zephir_call_cache[7]);
				zephir_check_call_status();
				ZVAL_LONG(&_7$$7, line);
				ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(&constantAnnotations, &comment, &_6$$7, &_7$$7);
				zephir_check_call_status();
				if (Z_TYPE_P(&constantAnnotations) == IS_ARRAY) {
					zephir_array_update_zval(&anotationsConstants, &constant, &constantAnnotations, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
		} ZEND_HASH_FOREACH_END();
		if (!(ZEPHIR_IS_EMPTY(&anotationsConstants))) {
			zephir_array_update_string(&annotations, SL("constants"), &anotationsConstants, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(&properties, &reflection, "getProperties", &_zephir_call_cache[8]);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&properties))) {
		line = 1;
		ZEPHIR_INIT_VAR(&annotationsProperties);
		array_init(&annotationsProperties);
		if (Z_TYPE_P(&properties) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_9$$10);
			zephir_string_to_char_array(&_9$$10, &properties);
			_8$$10 = &_9$$10;
		} else {
			_8$$10 = &properties;
		}
		zephir_is_iterable(_8$$10, 0, "phalcon/Annotations/Reader.zep", 138);
		if (Z_TYPE_P(_8$$10) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_8$$10), _10$$10)
			{
				ZEPHIR_INIT_NVAR(&property);
				ZVAL_COPY(&property, _10$$10);
				ZEPHIR_CALL_METHOD_CACHED(&comment, &property, "getDocComment", &_zephir_call_cache[9]);
				zephir_check_call_status();
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&comment)) {
					ZEPHIR_INIT_NVAR(&propertyAnnotations);
					ZEPHIR_CALL_METHOD_CACHED(&_11$$12, &reflection, "getFileName", &_zephir_call_cache[10]);
					zephir_check_call_status();
					ZVAL_LONG(&_12$$12, line);
					ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(&propertyAnnotations, &comment, &_11$$12, &_12$$12);
					zephir_check_call_status();
					if (Z_TYPE_P(&propertyAnnotations) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&_13$$13);
						zephir_read_property_cached(&_13$$13, &property, _zephir_prop_0, 0, PH_NOISY_CC);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_update_zval(&annotationsProperties, &_13$$13, &propertyAnnotations, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _8$$10, "rewind", &_zephir_call_cache[11]);
			zephir_check_call_status();
			_15$$10 = 1;
			while (1) {
				if (_15$$10) {
					_15$$10 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _8$$10, "next", &_zephir_call_cache[12]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_14$$10, _8$$10, "valid", &_zephir_call_cache[13]);
				zephir_check_call_status();
				if (!zend_is_true(&_14$$10)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&property, _8$$10, "current", &_zephir_call_cache[14]);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&comment, &property, "getDocComment", &_zephir_call_cache[15]);
					zephir_check_call_status();
					if (!ZEPHIR_IS_FALSE_IDENTICAL(&comment)) {
						ZEPHIR_INIT_NVAR(&propertyAnnotations);
						ZEPHIR_CALL_METHOD_CACHED(&_16$$15, &reflection, "getFileName", &_zephir_call_cache[16]);
						zephir_check_call_status();
						ZVAL_LONG(&_17$$15, line);
						ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(&propertyAnnotations, &comment, &_16$$15, &_17$$15);
						zephir_check_call_status();
						if (Z_TYPE_P(&propertyAnnotations) == IS_ARRAY) {
							ZEPHIR_OBS_NVAR(&_18$$16);
							zephir_read_property_cached(&_18$$16, &property, _zephir_prop_0, 0, PH_NOISY_CC);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_zval(&annotationsProperties, &_18$$16, &propertyAnnotations, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					}
			}
		}
		if (!(ZEPHIR_IS_EMPTY(&annotationsProperties))) {
			zephir_array_update_string(&annotations, SL("properties"), &annotationsProperties, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(&methods, &reflection, "getMethods", &_zephir_call_cache[17]);
	zephir_check_call_status();
	if (0 == ZEPHIR_IS_EMPTY(&methods)) {
		ZEPHIR_INIT_VAR(&annotationsMethods);
		array_init(&annotationsMethods);
		if (Z_TYPE_P(&methods) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_20$$18);
			zephir_string_to_char_array(&_20$$18, &methods);
			_19$$18 = &_20$$18;
		} else {
			_19$$18 = &methods;
		}
		zephir_is_iterable(_19$$18, 0, "phalcon/Annotations/Reader.zep", 172);
		if (Z_TYPE_P(_19$$18) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_19$$18), _21$$18)
			{
				ZEPHIR_INIT_NVAR(&method);
				ZVAL_COPY(&method, _21$$18);
				ZEPHIR_CALL_METHOD_CACHED(&comment, &method, "getDocComment", &_zephir_call_cache[18]);
				zephir_check_call_status();
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&comment)) {
					ZEPHIR_INIT_NVAR(&methodAnnotations);
					ZEPHIR_CALL_METHOD_CACHED(&_22$$20, &method, "getFileName", &_zephir_call_cache[19]);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_23$$20, &method, "getStartLine", &_zephir_call_cache[20]);
					zephir_check_call_status();
					ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(&methodAnnotations, &comment, &_22$$20, &_23$$20);
					zephir_check_call_status();
					if (Z_TYPE_P(&methodAnnotations) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&_24$$21);
						zephir_read_property_cached(&_24$$21, &method, _zephir_prop_0, 0, PH_NOISY_CC);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_update_zval(&annotationsMethods, &_24$$21, &methodAnnotations, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _19$$18, "rewind", &_zephir_call_cache[21]);
			zephir_check_call_status();
			_26$$18 = 1;
			while (1) {
				if (_26$$18) {
					_26$$18 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _19$$18, "next", &_zephir_call_cache[22]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_25$$18, _19$$18, "valid", &_zephir_call_cache[23]);
				zephir_check_call_status();
				if (!zend_is_true(&_25$$18)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&method, _19$$18, "current", &_zephir_call_cache[24]);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&comment, &method, "getDocComment", &_zephir_call_cache[25]);
					zephir_check_call_status();
					if (!ZEPHIR_IS_FALSE_IDENTICAL(&comment)) {
						ZEPHIR_INIT_NVAR(&methodAnnotations);
						ZEPHIR_CALL_METHOD_CACHED(&_27$$23, &method, "getFileName", &_zephir_call_cache[26]);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD_CACHED(&_28$$23, &method, "getStartLine", &_zephir_call_cache[27]);
						zephir_check_call_status();
						ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(&methodAnnotations, &comment, &_27$$23, &_28$$23);
						zephir_check_call_status();
						if (Z_TYPE_P(&methodAnnotations) == IS_ARRAY) {
							ZEPHIR_OBS_NVAR(&_29$$24);
							zephir_read_property_cached(&_29$$24, &method, _zephir_prop_0, 0, PH_NOISY_CC);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_zval(&annotationsMethods, &_29$$24, &methodAnnotations, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					}
			}
		}
		if (!(ZEPHIR_IS_EMPTY(&annotationsMethods))) {
			zephir_array_update_string(&annotations, SL("methods"), &annotationsMethods, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	RETURN_CTOR(&annotations);
}

/**
 * Parses a raw doc block returning the annotations found
 *
 * @phpstan-param string|null $file
 * @phpstan-param int|null    $line
 *
 * @phpstan-return annotations_node_list|false
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

