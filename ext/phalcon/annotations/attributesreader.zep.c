
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Parses PHP attributes returning an array with the found annotations
 *
 * The array has the same shape as the one of Phalcon\Annotations\Reader, so
 * the adapters, Reflection, Collection and Annotation do not know which
 * reader made it.
 *
 * PHP resolves the value of an attribute argument, so there is no parse tree
 * to walk. Each value goes in a node of the type Annotation::T_RESOLVED,
 * which Annotation::getExpression() gives back without a change.
 *
 * @phpstan-import-type annotations_arguments from AnnotationsTypes
 * @phpstan-import-type annotations_node_list from AnnotationsTypes
 * @phpstan-import-type annotations_reflection_data from AnnotationsTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_AttributesReader)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Annotations, AttributesReader, phalcon, annotations_attributesreader, phalcon_annotations_attributesreader_method_entry, 0);

	/**
	 * An attribute of this namespace gets the short name, so that `#[Column]`
	 * and `@Column` give the same name. Every other attribute keeps the full
	 * class name, so that an attribute of another library cannot take the
	 * place of a Phalcon one.
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_annotations_attributesreader_ce, SL("PHALCON_NAMESPACE"), "Phalcon\\Annotations\\");

	zend_class_implements(phalcon_annotations_attributesreader_ce, 1, phalcon_annotations_readerinterface_ce);
	return SUCCESS;
}

/**
 * Reads attributes from the class, its constants, properties and methods
 *
 * @phpstan-param class-string $className
 *
 * @phpstan-return annotations_reflection_data
 */
PHP_METHOD(Phalcon_Annotations_AttributesReader, parse)
{
	zend_bool _11, _22, _34;
	zval annotations;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, line = 0;
	zval className_zv, reflection, file, classAttributes, constant, constants, constantAttributes, annotationsConstants, property, properties, propertyAttributes, annotationsProperties, method, methods, methodAttributes, annotationsMethods, methodFile, _0, _1, _2, *_4, _5, *_6, _10, *_15, _16, *_17, _21, *_26, _27, *_28, _33, _7$$5, _8$$5, _9$$6, _12$$7, _13$$7, _14$$8, _18$$10, _19$$10, _20$$11, _23$$12, _24$$12, _25$$13, _29$$15, _30$$15, _31$$15, _32$$17, _35$$18, _36$$18, _37$$18, _38$$20;
	zend_string *className = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className_zv);
	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&classAttributes);
	ZVAL_UNDEF(&constant);
	ZVAL_UNDEF(&constants);
	ZVAL_UNDEF(&constantAttributes);
	ZVAL_UNDEF(&annotationsConstants);
	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&properties);
	ZVAL_UNDEF(&propertyAttributes);
	ZVAL_UNDEF(&annotationsProperties);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&methods);
	ZVAL_UNDEF(&methodAttributes);
	ZVAL_UNDEF(&annotationsMethods);
	ZVAL_UNDEF(&methodFile);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_23$$12);
	ZVAL_UNDEF(&_24$$12);
	ZVAL_UNDEF(&_25$$13);
	ZVAL_UNDEF(&_29$$15);
	ZVAL_UNDEF(&_30$$15);
	ZVAL_UNDEF(&_31$$15);
	ZVAL_UNDEF(&_32$$17);
	ZVAL_UNDEF(&_35$$18);
	ZVAL_UNDEF(&_36$$18);
	ZVAL_UNDEF(&_37$$18);
	ZVAL_UNDEF(&_38$$20);
	ZVAL_UNDEF(&annotations);
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
	ZEPHIR_INIT_VAR(&reflection);
	object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionclass")));
	ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 253, &className_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&file, &reflection, "getFileName", NULL, 365);
	zephir_check_call_status();
	if (Z_TYPE_P(&file) != IS_STRING) {
		ZEPHIR_INIT_NVAR(&file);
		ZVAL_STRING(&file, "eval code");
	}
	ZEPHIR_CALL_METHOD(&_0, &reflection, "getStartLine", NULL, 366);
	zephir_check_call_status();
	line = zephir_get_intval(&_0);
	ZEPHIR_CALL_METHOD(&_1, &reflection, "getAttributes", NULL, 367);
	zephir_check_call_status();
	ZVAL_LONG(&_2, line);
	ZEPHIR_CALL_METHOD(&classAttributes, this_ptr, "buildNodes", &_3, 0, &_1, &file, &_2);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&classAttributes))) {
		zephir_array_update_string(&annotations, SL("class"), &classAttributes, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_METHOD(&constants, &reflection, "getReflectionConstants", NULL, 368);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&annotationsConstants);
	array_init(&annotationsConstants);
	if (Z_TYPE_P(&constants) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_5);
		zephir_string_to_char_array(&_5, &constants);
		_4 = &_5;
	} else {
		_4 = &constants;
	}
	zephir_is_iterable(_4, 0, "phalcon/Annotations/AttributesReader.zep", 102);
	if (Z_TYPE_P(_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_4), _6)
		{
			ZEPHIR_INIT_NVAR(&constant);
			ZVAL_COPY(&constant, _6);
			ZEPHIR_CALL_METHOD(&_7$$5, &constant, "getAttributes", NULL, 0);
			zephir_check_call_status();
			ZVAL_LONG(&_8$$5, 1);
			ZEPHIR_CALL_METHOD(&constantAttributes, this_ptr, "buildNodes", &_3, 0, &_7$$5, &file, &_8$$5);
			zephir_check_call_status();
			if (!(ZEPHIR_IS_EMPTY(&constantAttributes))) {
				ZEPHIR_CALL_METHOD(&_9$$6, &constant, "getName", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_zval(&annotationsConstants, &_9$$6, &constantAttributes, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _4, "rewind", NULL, 0);
		zephir_check_call_status();
		_11 = 1;
		while (1) {
			if (_11) {
				_11 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _4, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_10, _4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_10)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&constant, _4, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_12$$7, &constant, "getAttributes", NULL, 0);
				zephir_check_call_status();
				ZVAL_LONG(&_13$$7, 1);
				ZEPHIR_CALL_METHOD(&constantAttributes, this_ptr, "buildNodes", &_3, 0, &_12$$7, &file, &_13$$7);
				zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&constantAttributes))) {
					ZEPHIR_CALL_METHOD(&_14$$8, &constant, "getName", NULL, 0);
					zephir_check_call_status();
					zephir_array_update_zval(&annotationsConstants, &_14$$8, &constantAttributes, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&constant);
	if (!(ZEPHIR_IS_EMPTY(&annotationsConstants))) {
		zephir_array_update_string(&annotations, SL("constants"), &annotationsConstants, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_METHOD(&properties, &reflection, "getProperties", NULL, 369);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&annotationsProperties);
	array_init(&annotationsProperties);
	if (Z_TYPE_P(&properties) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_16);
		zephir_string_to_char_array(&_16, &properties);
		_15 = &_16;
	} else {
		_15 = &properties;
	}
	zephir_is_iterable(_15, 0, "phalcon/Annotations/AttributesReader.zep", 124);
	if (Z_TYPE_P(_15) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_15), _17)
		{
			ZEPHIR_INIT_NVAR(&property);
			ZVAL_COPY(&property, _17);
			ZEPHIR_CALL_METHOD(&_18$$10, &property, "getAttributes", NULL, 0);
			zephir_check_call_status();
			ZVAL_LONG(&_19$$10, 1);
			ZEPHIR_CALL_METHOD(&propertyAttributes, this_ptr, "buildNodes", &_3, 0, &_18$$10, &file, &_19$$10);
			zephir_check_call_status();
			if (!(ZEPHIR_IS_EMPTY(&propertyAttributes))) {
				ZEPHIR_OBS_NVAR(&_20$$11);
				zephir_read_property_cached(&_20$$11, &property, _zephir_prop_0, 0, PH_NOISY_CC);
				zephir_array_update_zval(&annotationsProperties, &_20$$11, &propertyAttributes, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _15, "rewind", NULL, 0);
		zephir_check_call_status();
		_22 = 1;
		while (1) {
			if (_22) {
				_22 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _15, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_21, _15, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_21)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&property, _15, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_23$$12, &property, "getAttributes", NULL, 0);
				zephir_check_call_status();
				ZVAL_LONG(&_24$$12, 1);
				ZEPHIR_CALL_METHOD(&propertyAttributes, this_ptr, "buildNodes", &_3, 0, &_23$$12, &file, &_24$$12);
				zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&propertyAttributes))) {
					ZEPHIR_OBS_NVAR(&_25$$13);
					zephir_read_property_cached(&_25$$13, &property, _zephir_prop_0, 0, PH_NOISY_CC);
					zephir_array_update_zval(&annotationsProperties, &_25$$13, &propertyAttributes, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&property);
	if (!(ZEPHIR_IS_EMPTY(&annotationsProperties))) {
		zephir_array_update_string(&annotations, SL("properties"), &annotationsProperties, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_METHOD(&methods, &reflection, "getMethods", NULL, 370);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&annotationsMethods);
	array_init(&annotationsMethods);
	if (Z_TYPE_P(&methods) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_27);
		zephir_string_to_char_array(&_27, &methods);
		_26 = &_27;
	} else {
		_26 = &methods;
	}
	zephir_is_iterable(_26, 0, "phalcon/Annotations/AttributesReader.zep", 152);
	if (Z_TYPE_P(_26) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_26), _28)
		{
			ZEPHIR_INIT_NVAR(&method);
			ZVAL_COPY(&method, _28);
			ZEPHIR_CALL_METHOD(&methodFile, &method, "getFileName", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&methodFile) != IS_STRING) {
				ZEPHIR_INIT_NVAR(&methodFile);
				ZVAL_STRING(&methodFile, "eval code");
			}
			ZEPHIR_CALL_METHOD(&_29$$15, &method, "getAttributes", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_30$$15, &method, "getStartLine", NULL, 0);
			zephir_check_call_status();
			ZVAL_LONG(&_31$$15, zephir_get_intval(&_30$$15));
			ZEPHIR_CALL_METHOD(&methodAttributes, this_ptr, "buildNodes", &_3, 0, &_29$$15, &methodFile, &_31$$15);
			zephir_check_call_status();
			if (!(ZEPHIR_IS_EMPTY(&methodAttributes))) {
				ZEPHIR_OBS_NVAR(&_32$$17);
				zephir_read_property_cached(&_32$$17, &method, _zephir_prop_0, 0, PH_NOISY_CC);
				zephir_array_update_zval(&annotationsMethods, &_32$$17, &methodAttributes, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _26, "rewind", NULL, 0);
		zephir_check_call_status();
		_34 = 1;
		while (1) {
			if (_34) {
				_34 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _26, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_33, _26, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_33)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&method, _26, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&methodFile, &method, "getFileName", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&methodFile) != IS_STRING) {
					ZEPHIR_INIT_NVAR(&methodFile);
					ZVAL_STRING(&methodFile, "eval code");
				}
				ZEPHIR_CALL_METHOD(&_35$$18, &method, "getAttributes", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_36$$18, &method, "getStartLine", NULL, 0);
				zephir_check_call_status();
				ZVAL_LONG(&_37$$18, zephir_get_intval(&_36$$18));
				ZEPHIR_CALL_METHOD(&methodAttributes, this_ptr, "buildNodes", &_3, 0, &_35$$18, &methodFile, &_37$$18);
				zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&methodAttributes))) {
					ZEPHIR_OBS_NVAR(&_38$$20);
					zephir_read_property_cached(&_38$$20, &method, _zephir_prop_0, 0, PH_NOISY_CC);
					zephir_array_update_zval(&annotationsMethods, &_38$$20, &methodAttributes, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&method);
	if (!(ZEPHIR_IS_EMPTY(&annotationsMethods))) {
		zephir_array_update_string(&annotations, SL("methods"), &annotationsMethods, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CTOR(&annotations);
}

/**
 * Makes the argument list of one attribute. PHP resolved the values
 * already, so each one goes in a node that Annotation::getExpression()
 * gives back without a change. An integer key is a positional argument
 * and a string key is a named one.
 *
 * @phpstan-param array<array-key, mixed> $attributeArguments
 *
 * @phpstan-return annotations_arguments
 */
PHP_METHOD(Phalcon_Annotations_AttributesReader, buildArguments)
{
	zend_bool _5;
	zend_string *_2;
	zend_ulong _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributeArguments_param = NULL, key, value, argument, *_0, _4, _6$$5;
	zval attributeArguments, arguments, _3$$3, _7$$5;

	ZVAL_UNDEF(&attributeArguments);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6$$5);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(attributeArguments, attributeArguments_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &attributeArguments_param);
	zephir_get_arrval(&attributeArguments, attributeArguments_param);
	ZEPHIR_INIT_VAR(&arguments);
	array_init(&arguments);
	zephir_is_iterable(&attributeArguments, 0, "phalcon/Annotations/AttributesReader.zep", 191);
	if (Z_TYPE_P(&attributeArguments) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&attributeArguments), _1, _2, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_2 != NULL) { 
				ZVAL_STR_COPY(&key, _2);
			} else {
				ZVAL_LONG(&key, _1);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			ZEPHIR_INIT_NVAR(&argument);
			zephir_create_array(&argument, 1, 0);
			ZEPHIR_INIT_NVAR(&_3$$3);
			zephir_create_array(&_3$$3, 2, 0);
			add_assoc_long_ex(&_3$$3, SL("type"), 1000);
			zephir_array_update_string(&_3$$3, SL("value"), &value, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&argument, SL("expr"), &_3$$3, PH_COPY | PH_SEPARATE);
			if (Z_TYPE_P(&key) == IS_STRING) {
				zephir_array_update_string(&argument, SL("name"), &key, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			zephir_array_append(&arguments, &argument, PH_SEPARATE, "phalcon/Annotations/AttributesReader.zep", 188);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &attributeArguments, "rewind", NULL, 0);
		zephir_check_call_status();
		_5 = 1;
		while (1) {
			if (_5) {
				_5 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &attributeArguments, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_4, &attributeArguments, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &attributeArguments, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &attributeArguments, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_6$$5);
				zephir_create_array(&_6$$5, 1, 0);
				ZEPHIR_INIT_NVAR(&_7$$5);
				zephir_create_array(&_7$$5, 2, 0);
				add_assoc_long_ex(&_7$$5, SL("type"), 1000);
				zephir_array_update_string(&_7$$5, SL("value"), &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_6$$5, SL("expr"), &_7$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&argument, &_6$$5);
				if (Z_TYPE_P(&key) == IS_STRING) {
					zephir_array_update_string(&argument, SL("name"), &key, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				zephir_array_append(&arguments, &argument, PH_SEPARATE, "phalcon/Annotations/AttributesReader.zep", 188);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CTOR(&arguments);
}

/**
 * Makes the node list of one target from its attributes
 *
 * @phpstan-param array<array-key, \ReflectionAttribute<object>> $attributes
 *
 * @phpstan-return annotations_node_list
 */
PHP_METHOD(Phalcon_Annotations_AttributesReader, buildNodes)
{
	zend_bool _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_5 = NULL;
	zend_long line, ZEPHIR_LAST_CALL_STATUS;
	zend_string *file = NULL;
	zval *attributes_param = NULL, file_zv, *line_param = NULL, attribute, name, attributeArguments, node, *_0, _6, _1$$3, _3$$3, _4$$4, _8$$5, _9$$5, _10$$5, _11$$6;
	zval attributes, nodes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&nodes);
	ZVAL_UNDEF(&file_zv);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&attributeArguments);
	ZVAL_UNDEF(&node);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$6);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
		Z_PARAM_STR(file)
		Z_PARAM_LONG(line)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	attributes_param = ZEND_CALL_ARG(execute_data, 1);
	line_param = ZEND_CALL_ARG(execute_data, 3);
	zephir_get_arrval(&attributes, attributes_param);
	zephir_memory_observe(&file_zv);
	ZVAL_STR_COPY(&file_zv, file);
	ZEPHIR_INIT_VAR(&nodes);
	array_init(&nodes);
	zephir_is_iterable(&attributes, 0, "phalcon/Annotations/AttributesReader.zep", 232);
	if (Z_TYPE_P(&attributes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _0)
		{
			ZEPHIR_INIT_NVAR(&attribute);
			ZVAL_COPY(&attribute, _0);
			ZEPHIR_CALL_METHOD(&_1$$3, &attribute, "getName", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&name, this_ptr, "resolveName", &_2, 0, &_1$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&node);
			zephir_create_array(&node, 4, 0);
			add_assoc_long_ex(&node, SL("type"), 300);
			zephir_array_update_string(&node, SL("name"), &name, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&node, SL("file"), &file_zv, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_LONG(&_3$$3, line);
			zephir_array_update_string(&node, SL("line"), &_3$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&attributeArguments, &attribute, "getArguments", NULL, 0);
			zephir_check_call_status();
			if (!(ZEPHIR_IS_EMPTY(&attributeArguments))) {
				ZEPHIR_CALL_METHOD(&_4$$4, this_ptr, "buildArguments", &_5, 0, &attributeArguments);
				zephir_check_call_status();
				zephir_array_update_string(&node, SL("arguments"), &_4$$4, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			zephir_array_append(&nodes, &node, PH_SEPARATE, "phalcon/Annotations/AttributesReader.zep", 229);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_6, &attributes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&attribute, &attributes, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_8$$5, &attribute, "getName", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&name, this_ptr, "resolveName", &_2, 0, &_8$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_9$$5);
				zephir_create_array(&_9$$5, 4, 0);
				add_assoc_long_ex(&_9$$5, SL("type"), 300);
				zephir_array_update_string(&_9$$5, SL("name"), &name, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_9$$5, SL("file"), &file_zv, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_10$$5);
				ZVAL_LONG(&_10$$5, line);
				zephir_array_update_string(&_9$$5, SL("line"), &_10$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&node, &_9$$5);
				ZEPHIR_CALL_METHOD(&attributeArguments, &attribute, "getArguments", NULL, 0);
				zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&attributeArguments))) {
					ZEPHIR_CALL_METHOD(&_11$$6, this_ptr, "buildArguments", &_5, 0, &attributeArguments);
					zephir_check_call_status();
					zephir_array_update_string(&node, SL("arguments"), &_11$$6, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				zephir_array_append(&nodes, &node, PH_SEPARATE, "phalcon/Annotations/AttributesReader.zep", 229);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&attribute);
	RETURN_CTOR(&nodes);
}

/**
 * Gives the name that the collection matches on.
 *
 * An attribute of the Phalcon\Annotations namespace gets the short name,
 * so that `#[Column]` and `@Column` give the same name. Every other
 * attribute keeps the full class name, so that an attribute of another
 * library cannot take the place of a Phalcon one.
 *
 * Extend this reader and override this method to give the same short
 * name to the attributes of your own namespace.
 */
PHP_METHOD(Phalcon_Annotations_AttributesReader, resolveName)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval name_zv, _0;
	zend_string *name = NULL;

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Phalcon\\Annotations\\");
	if (zephir_start_with(&name_zv, &_0, NULL)) {
		zephir_get_class_ns(return_value, &name_zv, 0);
		RETURN_MM();
	}
	RETURN_MM_STR(zend_string_copy(name));
}

