
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
	zval annotations;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, line = 0;
	zval *className_param = NULL, reflection, comment, arrayKeys, classAnnotations, properties, property, annotationsProperties, propertyAnnotations, methods, method, annotationsMethods, methodAnnotations, constants, constant, anotationsConstants, constantAnnotations, constantReflection, _0$$3, _1$$3, *_2$$5, _3$$5, _5$$7, _6$$7, _7$$10, _8$$10, *_9$$13, _10$$13, _11$$15, _12$$15, _13$$16, _14$$18, _15$$18, _16$$19, *_17$$21, _18$$21, _19$$23, _20$$23, _21$$24, _22$$26, _23$$26, _24$$27;
	zval className;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className);
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
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_10$$13);
	ZVAL_UNDEF(&_11$$15);
	ZVAL_UNDEF(&_12$$15);
	ZVAL_UNDEF(&_13$$16);
	ZVAL_UNDEF(&_14$$18);
	ZVAL_UNDEF(&_15$$18);
	ZVAL_UNDEF(&_16$$19);
	ZVAL_UNDEF(&_18$$21);
	ZVAL_UNDEF(&_19$$23);
	ZVAL_UNDEF(&_20$$23);
	ZVAL_UNDEF(&_21$$24);
	ZVAL_UNDEF(&_22$$26);
	ZVAL_UNDEF(&_23$$26);
	ZVAL_UNDEF(&_24$$27);
	ZVAL_UNDEF(&annotations);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(className)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);
	zephir_get_strval(&className, className_param);


	ZEPHIR_INIT_VAR(&annotations);
	array_init(&annotations);
	ZEPHIR_INIT_VAR(&reflection);
	object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionclass")));
	ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 152, &className);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&comment, &reflection, "getdoccomment", NULL, 153);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&comment)) {
		ZEPHIR_INIT_VAR(&classAnnotations);
		ZEPHIR_CALL_METHOD(&_0$$3, &reflection, "getfilename", NULL, 154);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1$$3, &reflection, "getstartline", NULL, 155);
		zephir_check_call_status();
		ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(&classAnnotations, &comment, &_0$$3, &_1$$3);
		zephir_check_call_status();
		if (Z_TYPE_P(&classAnnotations) == IS_ARRAY) {
			zephir_array_update_string(&annotations, SL("class"), &classAnnotations, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_CALL_METHOD(&constants, &reflection, "getconstants", NULL, 156);
	zephir_check_call_status();
	if (zephir_fast_count_int(&constants)) {
		line = 1;
		ZEPHIR_INIT_VAR(&arrayKeys);
		zephir_array_keys(&arrayKeys, &constants);
		ZEPHIR_INIT_VAR(&anotationsConstants);
		array_init(&anotationsConstants);
		zephir_is_iterable(&arrayKeys, 0, "phalcon/Annotations/Reader.zep", 92);
		if (Z_TYPE_P(&arrayKeys) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&arrayKeys), _2$$5)
			{
				ZEPHIR_INIT_NVAR(&constant);
				ZVAL_COPY(&constant, _2$$5);
				ZEPHIR_CALL_METHOD(&constantReflection, &reflection, "getreflectionconstant", &_4, 157, &constant);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&comment, &constantReflection, "getdoccomment", NULL, 0);
				zephir_check_call_status();
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&comment)) {
					ZEPHIR_INIT_NVAR(&constantAnnotations);
					ZEPHIR_CALL_METHOD(&_5$$7, &reflection, "getfilename", NULL, 154);
					zephir_check_call_status();
					ZVAL_LONG(&_6$$7, line);
					ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(&constantAnnotations, &comment, &_5$$7, &_6$$7);
					zephir_check_call_status();
					if (Z_TYPE_P(&constantAnnotations) == IS_ARRAY) {
						zephir_array_update_zval(&anotationsConstants, &constant, &constantAnnotations, PH_COPY | PH_SEPARATE);
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &arrayKeys, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_3$$5, &arrayKeys, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_3$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&constant, &arrayKeys, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&constantReflection, &reflection, "getreflectionconstant", &_4, 157, &constant);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&comment, &constantReflection, "getdoccomment", NULL, 0);
					zephir_check_call_status();
					if (!ZEPHIR_IS_FALSE_IDENTICAL(&comment)) {
						ZEPHIR_INIT_NVAR(&constantAnnotations);
						ZEPHIR_CALL_METHOD(&_7$$10, &reflection, "getfilename", NULL, 154);
						zephir_check_call_status();
						ZVAL_LONG(&_8$$10, line);
						ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(&constantAnnotations, &comment, &_7$$10, &_8$$10);
						zephir_check_call_status();
						if (Z_TYPE_P(&constantAnnotations) == IS_ARRAY) {
							zephir_array_update_zval(&anotationsConstants, &constant, &constantAnnotations, PH_COPY | PH_SEPARATE);
						}
					}
				ZEPHIR_CALL_METHOD(NULL, &arrayKeys, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&constant);
		if (zephir_fast_count_int(&anotationsConstants)) {
			zephir_array_update_string(&annotations, SL("constants"), &anotationsConstants, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_CALL_METHOD(&properties, &reflection, "getproperties", NULL, 158);
	zephir_check_call_status();
	if (zephir_fast_count_int(&properties)) {
		line = 1;
		ZEPHIR_INIT_VAR(&annotationsProperties);
		array_init(&annotationsProperties);
		zephir_is_iterable(&properties, 0, "phalcon/Annotations/Reader.zep", 130);
		if (Z_TYPE_P(&properties) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&properties), _9$$13)
			{
				ZEPHIR_INIT_NVAR(&property);
				ZVAL_COPY(&property, _9$$13);
				ZEPHIR_CALL_METHOD(&comment, &property, "getdoccomment", NULL, 0);
				zephir_check_call_status();
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&comment)) {
					ZEPHIR_INIT_NVAR(&propertyAnnotations);
					ZEPHIR_CALL_METHOD(&_11$$15, &reflection, "getfilename", NULL, 154);
					zephir_check_call_status();
					ZVAL_LONG(&_12$$15, line);
					ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(&propertyAnnotations, &comment, &_11$$15, &_12$$15);
					zephir_check_call_status();
					if (Z_TYPE_P(&propertyAnnotations) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&_13$$16);
						zephir_read_property(&_13$$16, &property, ZEND_STRL("name"), PH_NOISY_CC);
						zephir_array_update_zval(&annotationsProperties, &_13$$16, &propertyAnnotations, PH_COPY | PH_SEPARATE);
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &properties, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_10$$13, &properties, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_10$$13)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&property, &properties, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&comment, &property, "getdoccomment", NULL, 0);
					zephir_check_call_status();
					if (!ZEPHIR_IS_FALSE_IDENTICAL(&comment)) {
						ZEPHIR_INIT_NVAR(&propertyAnnotations);
						ZEPHIR_CALL_METHOD(&_14$$18, &reflection, "getfilename", NULL, 154);
						zephir_check_call_status();
						ZVAL_LONG(&_15$$18, line);
						ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(&propertyAnnotations, &comment, &_14$$18, &_15$$18);
						zephir_check_call_status();
						if (Z_TYPE_P(&propertyAnnotations) == IS_ARRAY) {
							ZEPHIR_OBS_NVAR(&_16$$19);
							zephir_read_property(&_16$$19, &property, ZEND_STRL("name"), PH_NOISY_CC);
							zephir_array_update_zval(&annotationsProperties, &_16$$19, &propertyAnnotations, PH_COPY | PH_SEPARATE);
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
	ZEPHIR_CALL_METHOD(&methods, &reflection, "getmethods", NULL, 159);
	zephir_check_call_status();
	if (0 == ZEPHIR_IS_EMPTY(&methods)) {
		ZEPHIR_INIT_VAR(&annotationsMethods);
		array_init(&annotationsMethods);
		zephir_is_iterable(&methods, 0, "phalcon/Annotations/Reader.zep", 164);
		if (Z_TYPE_P(&methods) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&methods), _17$$21)
			{
				ZEPHIR_INIT_NVAR(&method);
				ZVAL_COPY(&method, _17$$21);
				ZEPHIR_CALL_METHOD(&comment, &method, "getdoccomment", NULL, 0);
				zephir_check_call_status();
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&comment)) {
					ZEPHIR_INIT_NVAR(&methodAnnotations);
					ZEPHIR_CALL_METHOD(&_19$$23, &method, "getfilename", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_20$$23, &method, "getstartline", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(&methodAnnotations, &comment, &_19$$23, &_20$$23);
					zephir_check_call_status();
					if (Z_TYPE_P(&methodAnnotations) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&_21$$24);
						zephir_read_property(&_21$$24, &method, ZEND_STRL("name"), PH_NOISY_CC);
						zephir_array_update_zval(&annotationsMethods, &_21$$24, &methodAnnotations, PH_COPY | PH_SEPARATE);
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &methods, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_18$$21, &methods, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_18$$21)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&method, &methods, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&comment, &method, "getdoccomment", NULL, 0);
					zephir_check_call_status();
					if (!ZEPHIR_IS_FALSE_IDENTICAL(&comment)) {
						ZEPHIR_INIT_NVAR(&methodAnnotations);
						ZEPHIR_CALL_METHOD(&_22$$26, &method, "getfilename", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_23$$26, &method, "getstartline", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(&methodAnnotations, &comment, &_22$$26, &_23$$26);
						zephir_check_call_status();
						if (Z_TYPE_P(&methodAnnotations) == IS_ARRAY) {
							ZEPHIR_OBS_NVAR(&_24$$27);
							zephir_read_property(&_24$$27, &method, ZEND_STRL("name"), PH_NOISY_CC);
							zephir_array_update_zval(&annotationsMethods, &_24$$27, &methodAnnotations, PH_COPY | PH_SEPARATE);
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
PHP_METHOD(Phalcon_Annotations_Reader, parseDocBlock)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *docBlock_param = NULL, *file = NULL, file_sub, *line = NULL, line_sub, __$null;
	zval docBlock;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&docBlock);
	ZVAL_UNDEF(&file_sub);
	ZVAL_UNDEF(&line_sub);
	ZVAL_NULL(&__$null);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(docBlock)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(file)
		Z_PARAM_ZVAL_OR_NULL(line)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
	ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(return_value, &docBlock, file, line);
	zephir_check_call_status();
	RETURN_MM();
}

