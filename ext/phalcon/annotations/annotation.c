
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
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


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
* Phalcon\Annotations\Annotation
*
* Represents a single annotation in an annotations collection
*/
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Annotation) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Annotations, Annotation, phalcon, annotations_annotation, phalcon_annotations_annotation_method_entry, 0);

/**
	 * Annotation Name
	 * @var string
	 */
	zend_declare_property_null(phalcon_annotations_annotation_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
	 * Annotation Arguments
	 * @var string
	 */
	zend_declare_property_null(phalcon_annotations_annotation_ce, SL("_arguments"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
	 * Annotation ExprArguments
	 * @var string
	 */
	zend_declare_property_null(phalcon_annotations_annotation_ce, SL("_exprArguments"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Annotations\Annotation constructor
 *
 * @param array reflectionData
 */
PHP_METHOD(Phalcon_Annotations_Annotation, __construct) {

	zend_function *_5 = NULL;
	HashTable *_2;
	HashPosition _1;
	zval *reflectionData, *name, *exprArguments, *argument = NULL, *resolvedArgument = NULL, *arguments = NULL, *_0, **_3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &reflectionData);



	if ((Z_TYPE_P(reflectionData) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_annotations_exception_ce, "Reflection data must be an array");
		return;
	}
	zephir_array_fetch_string(&_0, reflectionData, SL("name"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_name"), _0 TSRMLS_CC);
	if (zephir_array_isset_string_fetch(&exprArguments, reflectionData, SS("arguments"), 1 TSRMLS_CC)) {
		zephir_is_iterable(exprArguments, &_2, &_1, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
			; zend_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HVALUE(argument, _3);
			zephir_array_fetch_string(&_4, argument, SL("expr"), PH_NOISY | PH_READONLY TSRMLS_CC);
			ZEPHIR_INIT_NVAR(resolvedArgument);
			zephir_call_method_p1_cache(resolvedArgument, this_ptr, "getexpression", &_5, _4);
			if (zephir_array_isset_string_fetch(&name, argument, SS("name"), 1 TSRMLS_CC)) {
				ZEPHIR_OBS_NVAR(arguments);
				zephir_array_fetch(&arguments, name, resolvedArgument, PH_NOISY TSRMLS_CC);
			} else {
				ZEPHIR_CPY_WRT(arguments, resolvedArgument);
			}
		}
		zephir_update_property_this(this_ptr, SL("_arguments"), arguments TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_exprArguments"), exprArguments TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the annotation's name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Annotations_Annotation, getName) {


	RETURN_MEMBER(this_ptr, "_name");

}

/**
 * Resolves an annotation expression
 *
 * @param array expr
 * @return mixed
 */
PHP_METHOD(Phalcon_Annotations_Annotation, getExpression) {

	zend_function *_5 = NULL;
	HashTable *_2;
	HashPosition _1;
	zval *expr, *value = NULL, *item = NULL, *resolvedItem = NULL, *arrayValue = NULL, *name, *type, *_0, **_3, *_4, *_6, *_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expr);



	if ((Z_TYPE_P(expr) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_annotations_exception_ce, "The expression is not valid");
		return;
	}
	zephir_array_fetch_string(&type, expr, SL("type"), PH_NOISY | PH_READONLY TSRMLS_CC);
	do {
		if (ZEPHIR_IS_LONG(type, 301) || ZEPHIR_IS_LONG(type, 302) || ZEPHIR_IS_LONG(type, 303) || ZEPHIR_IS_LONG(type, 307)) {
			ZEPHIR_OBS_VAR(value);
			zephir_array_fetch_string(&value, expr, SL("value"), PH_NOISY TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(type, 304)) {
			ZEPHIR_INIT_NVAR(value);
			ZVAL_NULL(value);
			break;
		}
		if (ZEPHIR_IS_LONG(type, 305)) {
			ZEPHIR_INIT_NVAR(value);
			ZVAL_BOOL(value, 0);
			break;
		}
		if (ZEPHIR_IS_LONG(type, 306)) {
			ZEPHIR_INIT_NVAR(value);
			ZVAL_BOOL(value, 1);
			break;
		}
		if (ZEPHIR_IS_LONG(type, 308)) {
			zephir_array_fetch_string(&_0, expr, SL("items"), PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_is_iterable(_0, &_2, &_1, 0, 0);
			for (
				; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
				; zend_hash_move_forward_ex(_2, &_1)
			) {
				ZEPHIR_GET_HVALUE(item, _3);
				zephir_array_fetch_string(&_4, item, SL("expr"), PH_NOISY | PH_READONLY TSRMLS_CC);
				ZEPHIR_INIT_NVAR(resolvedItem);
				zephir_call_method_p1_cache(resolvedItem, this_ptr, "getexpression", &_5, _4);
				if (zephir_array_isset_string_fetch(&name, item, SS("name"), 1 TSRMLS_CC)) {
					ZEPHIR_OBS_NVAR(arrayValue);
					zephir_array_fetch(&arrayValue, name, resolvedItem, PH_NOISY TSRMLS_CC);
				} else {
					zephir_array_append(&arrayValue, resolvedItem, PH_SEPARATE);
				}
			}
			RETURN_CCTOR(arrayValue);
		}
		if (ZEPHIR_IS_LONG(type, 300)) {
			object_init_ex(return_value, phalcon_annotations_annotation_ce);
			zephir_call_method_p1_noret(return_value, "__construct", expr);
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(_6);
		object_init_ex(_6, phalcon_annotations_exception_ce);
		ZEPHIR_INIT_VAR(_7);
		ZEPHIR_CONCAT_SVS(_7, "The expression ", type, " is unknown");
		zephir_call_method_p1_noret(_6, "__construct", _7);
		zephir_throw_exception(_6 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	RETURN_CCTOR(value);

}

/**
 * Returns the expression arguments without resolving
 *
 * @return array
 */
PHP_METHOD(Phalcon_Annotations_Annotation, getExprArguments) {


	RETURN_MEMBER(this_ptr, "_exprArguments");

}

/**
 * Returns the expression arguments
 *
 * @return array
 */
PHP_METHOD(Phalcon_Annotations_Annotation, getArguments) {


	RETURN_MEMBER(this_ptr, "_arguments");

}

/**
 * Returns the number of arguments that the annotation has
 *
 * @return int
 */
PHP_METHOD(Phalcon_Annotations_Annotation, numberArguments) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_arguments"), PH_NOISY_CC);
	RETURN_LONG(zephir_fast_count_int(_0 TSRMLS_CC));

}

/**
 * Returns an argument in a specific position
 *
 * @param int position
 * @return mixed
 */
PHP_METHOD(Phalcon_Annotations_Annotation, getArgument) {

	zval *position_param = NULL, *arguments, *argument;
	int position;

	zephir_fetch_params(0, 1, 0, &position_param);

		position = zephir_get_intval(position_param);


	arguments = zephir_fetch_nproperty_this(this_ptr, SL("_arguments"), PH_NOISY_CC);
	if (zephir_array_isset_long_fetch(&argument, arguments, position, 1 TSRMLS_CC)) {
		RETURN_CTORW(argument);
	}

}

/**
 * Returns an argument in a specific position
 *
 * @param int position
 * @return boolean
 */
PHP_METHOD(Phalcon_Annotations_Annotation, hasArgument) {

	zval *position_param = NULL, *arguments;
	int position;

	zephir_fetch_params(0, 1, 0, &position_param);

		position = zephir_get_intval(position_param);


	arguments = zephir_fetch_nproperty_this(this_ptr, SL("_arguments"), PH_NOISY_CC);
	RETURN_BOOL(zephir_array_isset_long(arguments, position));

}

/**
 * Returns a named argument
 *
 * @param string name
 * @return mixed
 */
PHP_METHOD(Phalcon_Annotations_Annotation, getNamedArgument) {

	zval *name_param = NULL, *arguments, *argument;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

		if (Z_TYPE_P(name_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		}

		name = name_param;


	arguments = zephir_fetch_nproperty_this(this_ptr, SL("_arguments"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&argument, arguments, name, 1 TSRMLS_CC)) {
		RETURN_CTOR(argument);
	}
	ZEPHIR_MM_RESTORE();

}

