
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
 * For the full copyright and license information, please view the LICENSE.txt
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
	zend_bool _10, _21, _33;
	zval annotations;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, line = 0;
	zval className_zv, reflection, file, classAttributes, constant, constants, constantAttributes, annotationsConstants, property, properties, propertyAttributes, annotationsProperties, method, methods, methodAttributes, annotationsMethods, methodFile, _0, _1, _2, *_3, _4, *_5, _9, *_14, _15, *_16, _20, *_25, _26, *_27, _32, _6$$5, _7$$5, _8$$6, _11$$7, _12$$7, _13$$8, _17$$10, _18$$10, _19$$11, _22$$12, _23$$12, _24$$13, _28$$15, _29$$15, _30$$15, _31$$17, _34$$18, _35$$18, _36$$18, _37$$20;
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
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&_22$$12);
	ZVAL_UNDEF(&_23$$12);
	ZVAL_UNDEF(&_24$$13);
	ZVAL_UNDEF(&_28$$15);
	ZVAL_UNDEF(&_29$$15);
	ZVAL_UNDEF(&_30$$15);
	ZVAL_UNDEF(&_31$$17);
	ZVAL_UNDEF(&_34$$18);
	ZVAL_UNDEF(&_35$$18);
	ZVAL_UNDEF(&_36$$18);
	ZVAL_UNDEF(&_37$$20);
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
	ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 252, &className_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&file, &reflection, "getfilename", NULL, 367);
	zephir_check_call_status();
	if (Z_TYPE_P(&file) != IS_STRING) {
		ZEPHIR_INIT_NVAR(&file);
		ZVAL_STRING(&file, "eval code");
	}
	ZEPHIR_CALL_METHOD(&_0, &reflection, "getstartline", NULL, 368);
	zephir_check_call_status();
	line = zephir_get_intval(&_0);
	ZEPHIR_CALL_METHOD(&_1, &reflection, "getattributes", NULL, 369);
	zephir_check_call_status();
	ZVAL_LONG(&_2, line);
	ZEPHIR_CALL_METHOD(&classAttributes, this_ptr, "buildnodes", NULL, 0, &_1, &file, &_2);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&classAttributes))) {
		zephir_array_update_string(&annotations, SL("class"), &classAttributes, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_METHOD(&constants, &reflection, "getreflectionconstants", NULL, 370);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&annotationsConstants);
	array_init(&annotationsConstants);
	if (Z_TYPE_P(&constants) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_4);
		zephir_string_to_char_array(&_4, &constants);
		_3 = &_4;
	} else {
		_3 = &constants;
	}
	zephir_is_iterable(_3, 0, "phalcon/Annotations/AttributesReader.zep", 102);
	if (Z_TYPE_P(_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_3), _5)
		{
			ZEPHIR_INIT_NVAR(&constant);
			ZVAL_COPY(&constant, _5);
			ZEPHIR_CALL_METHOD(&_6$$5, &constant, "getattributes", NULL, 0);
			zephir_check_call_status();
			ZVAL_LONG(&_7$$5, 1);
			ZEPHIR_CALL_METHOD(&constantAttributes, this_ptr, "buildnodes", NULL, 0, &_6$$5, &file, &_7$$5);
			zephir_check_call_status();
			if (!(ZEPHIR_IS_EMPTY(&constantAttributes))) {
				ZEPHIR_CALL_METHOD(&_8$$6, &constant, "getname", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_zval(&annotationsConstants, &_8$$6, &constantAttributes, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _3, "rewind", NULL, 0);
		zephir_check_call_status();
		_10 = 1;
		while (1) {
			if (_10) {
				_10 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _3, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_9, _3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_9)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&constant, _3, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_11$$7, &constant, "getattributes", NULL, 0);
				zephir_check_call_status();
				ZVAL_LONG(&_12$$7, 1);
				ZEPHIR_CALL_METHOD(&constantAttributes, this_ptr, "buildnodes", NULL, 0, &_11$$7, &file, &_12$$7);
				zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&constantAttributes))) {
					ZEPHIR_CALL_METHOD(&_13$$8, &constant, "getname", NULL, 0);
					zephir_check_call_status();
					zephir_array_update_zval(&annotationsConstants, &_13$$8, &constantAttributes, PH_COPY | PH_SEPARATE);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&constant);
	if (!(ZEPHIR_IS_EMPTY(&annotationsConstants))) {
		zephir_array_update_string(&annotations, SL("constants"), &annotationsConstants, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_METHOD(&properties, &reflection, "getproperties", NULL, 371);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&annotationsProperties);
	array_init(&annotationsProperties);
	if (Z_TYPE_P(&properties) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_15);
		zephir_string_to_char_array(&_15, &properties);
		_14 = &_15;
	} else {
		_14 = &properties;
	}
	zephir_is_iterable(_14, 0, "phalcon/Annotations/AttributesReader.zep", 124);
	if (Z_TYPE_P(_14) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_14), _16)
		{
			ZEPHIR_INIT_NVAR(&property);
			ZVAL_COPY(&property, _16);
			ZEPHIR_CALL_METHOD(&_17$$10, &property, "getattributes", NULL, 0);
			zephir_check_call_status();
			ZVAL_LONG(&_18$$10, 1);
			ZEPHIR_CALL_METHOD(&propertyAttributes, this_ptr, "buildnodes", NULL, 0, &_17$$10, &file, &_18$$10);
			zephir_check_call_status();
			if (!(ZEPHIR_IS_EMPTY(&propertyAttributes))) {
				ZEPHIR_OBS_NVAR(&_19$$11);
				zephir_read_property_cached(&_19$$11, &property, _zephir_prop_0, 0, PH_NOISY_CC);
				zephir_array_update_zval(&annotationsProperties, &_19$$11, &propertyAttributes, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _14, "rewind", NULL, 0);
		zephir_check_call_status();
		_21 = 1;
		while (1) {
			if (_21) {
				_21 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _14, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_20, _14, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_20)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&property, _14, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_22$$12, &property, "getattributes", NULL, 0);
				zephir_check_call_status();
				ZVAL_LONG(&_23$$12, 1);
				ZEPHIR_CALL_METHOD(&propertyAttributes, this_ptr, "buildnodes", NULL, 0, &_22$$12, &file, &_23$$12);
				zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&propertyAttributes))) {
					ZEPHIR_OBS_NVAR(&_24$$13);
					zephir_read_property_cached(&_24$$13, &property, _zephir_prop_0, 0, PH_NOISY_CC);
					zephir_array_update_zval(&annotationsProperties, &_24$$13, &propertyAttributes, PH_COPY | PH_SEPARATE);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&property);
	if (!(ZEPHIR_IS_EMPTY(&annotationsProperties))) {
		zephir_array_update_string(&annotations, SL("properties"), &annotationsProperties, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_METHOD(&methods, &reflection, "getmethods", NULL, 372);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&annotationsMethods);
	array_init(&annotationsMethods);
	if (Z_TYPE_P(&methods) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_26);
		zephir_string_to_char_array(&_26, &methods);
		_25 = &_26;
	} else {
		_25 = &methods;
	}
	zephir_is_iterable(_25, 0, "phalcon/Annotations/AttributesReader.zep", 152);
	if (Z_TYPE_P(_25) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_25), _27)
		{
			ZEPHIR_INIT_NVAR(&method);
			ZVAL_COPY(&method, _27);
			ZEPHIR_CALL_METHOD(&methodFile, &method, "getfilename", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&methodFile) != IS_STRING) {
				ZEPHIR_INIT_NVAR(&methodFile);
				ZVAL_STRING(&methodFile, "eval code");
			}
			ZEPHIR_CALL_METHOD(&_28$$15, &method, "getattributes", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_29$$15, &method, "getstartline", NULL, 0);
			zephir_check_call_status();
			ZVAL_LONG(&_30$$15, zephir_get_intval(&_29$$15));
			ZEPHIR_CALL_METHOD(&methodAttributes, this_ptr, "buildnodes", NULL, 0, &_28$$15, &methodFile, &_30$$15);
			zephir_check_call_status();
			if (!(ZEPHIR_IS_EMPTY(&methodAttributes))) {
				ZEPHIR_OBS_NVAR(&_31$$17);
				zephir_read_property_cached(&_31$$17, &method, _zephir_prop_0, 0, PH_NOISY_CC);
				zephir_array_update_zval(&annotationsMethods, &_31$$17, &methodAttributes, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _25, "rewind", NULL, 0);
		zephir_check_call_status();
		_33 = 1;
		while (1) {
			if (_33) {
				_33 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _25, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_32, _25, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_32)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&method, _25, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&methodFile, &method, "getfilename", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&methodFile) != IS_STRING) {
					ZEPHIR_INIT_NVAR(&methodFile);
					ZVAL_STRING(&methodFile, "eval code");
				}
				ZEPHIR_CALL_METHOD(&_34$$18, &method, "getattributes", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_35$$18, &method, "getstartline", NULL, 0);
				zephir_check_call_status();
				ZVAL_LONG(&_36$$18, zephir_get_intval(&_35$$18));
				ZEPHIR_CALL_METHOD(&methodAttributes, this_ptr, "buildnodes", NULL, 0, &_34$$18, &methodFile, &_36$$18);
				zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&methodAttributes))) {
					ZEPHIR_OBS_NVAR(&_37$$20);
					zephir_read_property_cached(&_37$$20, &method, _zephir_prop_0, 0, PH_NOISY_CC);
					zephir_array_update_zval(&annotationsMethods, &_37$$20, &methodAttributes, PH_COPY | PH_SEPARATE);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&method);
	if (!(ZEPHIR_IS_EMPTY(&annotationsMethods))) {
		zephir_array_update_string(&annotations, SL("methods"), &annotationsMethods, PH_COPY | PH_SEPARATE);
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
			}
			zephir_array_append(&arguments, &argument, PH_SEPARATE, "phalcon/Annotations/AttributesReader.zep", 188);
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
				}
				zephir_array_append(&arguments, &argument, PH_SEPARATE, "phalcon/Annotations/AttributesReader.zep", 188);
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
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long line, ZEPHIR_LAST_CALL_STATUS;
	zend_string *file = NULL;
	zval *attributes_param = NULL, file_zv, *line_param = NULL, attribute, name, attributeArguments, node, *_0, _6, _1$$3, _3$$3, _2$$4, _4$$5, _8$$6, _10$$6, _11$$6, _9$$7, _12$$8;
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
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_12$$8);
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
	zephir_is_iterable(&attributes, 0, "phalcon/Annotations/AttributesReader.zep", 236);
	if (Z_TYPE_P(&attributes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _0)
		{
			ZEPHIR_INIT_NVAR(&attribute);
			ZVAL_COPY(&attribute, _0);
			ZEPHIR_CALL_METHOD(&name, &attribute, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_1$$3);
			ZVAL_STRING(&_1$$3, "Phalcon\\Annotations\\");
			if (zephir_start_with(&name, &_1$$3, NULL)) {
				ZEPHIR_INIT_NVAR(&_2$$4);
				zephir_get_class_ns(&_2$$4, &name, 0);
				ZEPHIR_CPY_WRT(&name, &_2$$4);
			}
			ZEPHIR_INIT_NVAR(&node);
			zephir_create_array(&node, 4, 0);
			add_assoc_long_ex(&node, SL("type"), 300);
			zephir_array_update_string(&node, SL("name"), &name, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&node, SL("file"), &file_zv, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_LONG(&_3$$3, line);
			zephir_array_update_string(&node, SL("line"), &_3$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&attributeArguments, &attribute, "getarguments", NULL, 0);
			zephir_check_call_status();
			if (!(ZEPHIR_IS_EMPTY(&attributeArguments))) {
				ZEPHIR_CALL_METHOD(&_4$$5, this_ptr, "buildarguments", &_5, 0, &attributeArguments);
				zephir_check_call_status();
				zephir_array_update_string(&node, SL("arguments"), &_4$$5, PH_COPY | PH_SEPARATE);
			}
			zephir_array_append(&nodes, &node, PH_SEPARATE, "phalcon/Annotations/AttributesReader.zep", 233);
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
				ZEPHIR_CALL_METHOD(&name, &attribute, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_8$$6);
				ZVAL_STRING(&_8$$6, "Phalcon\\Annotations\\");
				if (zephir_start_with(&name, &_8$$6, NULL)) {
					ZEPHIR_INIT_NVAR(&_9$$7);
					zephir_get_class_ns(&_9$$7, &name, 0);
					ZEPHIR_CPY_WRT(&name, &_9$$7);
				}
				ZEPHIR_INIT_NVAR(&_10$$6);
				zephir_create_array(&_10$$6, 4, 0);
				add_assoc_long_ex(&_10$$6, SL("type"), 300);
				zephir_array_update_string(&_10$$6, SL("name"), &name, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_10$$6, SL("file"), &file_zv, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_11$$6);
				ZVAL_LONG(&_11$$6, line);
				zephir_array_update_string(&_10$$6, SL("line"), &_11$$6, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&node, &_10$$6);
				ZEPHIR_CALL_METHOD(&attributeArguments, &attribute, "getarguments", NULL, 0);
				zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&attributeArguments))) {
					ZEPHIR_CALL_METHOD(&_12$$8, this_ptr, "buildarguments", &_5, 0, &attributeArguments);
					zephir_check_call_status();
					zephir_array_update_string(&node, SL("arguments"), &_12$$8, PH_COPY | PH_SEPARATE);
				}
				zephir_array_append(&nodes, &node, PH_SEPARATE, "phalcon/Annotations/AttributesReader.zep", 233);
		}
	}
	ZEPHIR_INIT_NVAR(&attribute);
	RETURN_CTOR(&nodes);
}

