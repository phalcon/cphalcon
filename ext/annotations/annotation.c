
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"

/**
 * Phalcon\Annotations\Annotation
 *
 * Represents a single annotation in an annotations collection
 */


/**
 * Phalcon\Annotations\Annotation initializer
 */
PHALCON_INIT_CLASS(Phalcon_Annotations_Annotation){

	PHALCON_REGISTER_CLASS(Phalcon\\Annotations, Annotation, annotations_annotation, phalcon_annotations_annotation_method_entry, 0);

	zend_declare_property_null(phalcon_annotations_annotation_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_annotations_annotation_ce, SL("_arguments"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_annotations_annotation_ce, SL("_exprArguments"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Annotations\Annotation constructor
 *
 * @param array $reflectionData
 */
PHP_METHOD(Phalcon_Annotations_Annotation, __construct){

	zval *reflection_data, *name = NULL, *arguments, *expr_arguments;
	zval *argument = NULL, *expr = NULL, *resolved_argument = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &reflection_data);
	
	if (Z_TYPE_P(reflection_data) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_annotations_exception_ce, "Reflection data must be an array");
		return;
	}
	
	PHALCON_OBS_VAR(name);
	phalcon_array_fetch_string(&name, reflection_data, SL("name"), PH_NOISY_CC);
	phalcon_update_property_this(this_ptr, SL("_name"), name TSRMLS_CC);
	
	/** 
	 * Process annotation arguments
	 */
	if (phalcon_array_isset_string(reflection_data, SS("arguments"))) {
	
		PHALCON_INIT_VAR(arguments);
		array_init(arguments);
	
		PHALCON_OBS_VAR(expr_arguments);
		phalcon_array_fetch_string(&expr_arguments, reflection_data, SL("arguments"), PH_NOISY_CC);
	
		if (!phalcon_is_iterable(expr_arguments, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HVALUE(argument);
	
			PHALCON_OBS_NVAR(expr);
			phalcon_array_fetch_string(&expr, argument, SL("expr"), PH_NOISY_CC);
	
			PHALCON_INIT_NVAR(resolved_argument);
			phalcon_call_method_p1(resolved_argument, this_ptr, "getexpression", expr);
			if (phalcon_array_isset_string(argument, SS("name"))) {
				PHALCON_OBS_NVAR(name);
				phalcon_array_fetch_string(&name, argument, SL("name"), PH_NOISY_CC);
				phalcon_array_update_zval(&arguments, name, &resolved_argument, PH_COPY | PH_SEPARATE TSRMLS_CC);
			} else {
				phalcon_array_append(&arguments, resolved_argument, PH_SEPARATE TSRMLS_CC);
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
		phalcon_update_property_this(this_ptr, SL("_arguments"), arguments TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_exprArguments"), expr_arguments TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the annotation's name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Annotations_Annotation, getName){


	RETURN_MEMBER(this_ptr, "_name");
}

/**
 * Resolves an annotation expression
 *
 * @param array $expr
 * @return mixed
 */
PHP_METHOD(Phalcon_Annotations_Annotation, getExpression){

	zval *expr = NULL, *type, *value = NULL, *array_value, *items, *item = NULL;
	zval *resolved_item = NULL, *name = NULL, *annotation, *exception_message;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &expr);
	
	PHALCON_SEPARATE_PARAM(expr);
	
	if (Z_TYPE_P(expr) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_annotations_exception_ce, "The expression is not valid");
		return;
	}
	
	PHALCON_OBS_VAR(type);
	phalcon_array_fetch_string(&type, expr, SL("type"), PH_NOISY_CC);
	
	switch (phalcon_get_intval(type)) {
	
		case 301:
			PHALCON_OBS_VAR(value);
			phalcon_array_fetch_string(&value, expr, SL("value"), PH_NOISY_CC);
			RETURN_CCTOR(value);
	
		case 302:
			PHALCON_OBS_NVAR(value);
			phalcon_array_fetch_string(&value, expr, SL("value"), PH_NOISY_CC);
			RETURN_CCTOR(value);
	
		case 303:
			PHALCON_OBS_NVAR(value);
			phalcon_array_fetch_string(&value, expr, SL("value"), PH_NOISY_CC);
			RETURN_CCTOR(value);
	
		case 307:
			PHALCON_OBS_NVAR(value);
			phalcon_array_fetch_string(&value, expr, SL("value"), PH_NOISY_CC);
			RETURN_CCTOR(value);
	
		case 304:
			RETURN_MM_NULL();
	
		case 305:
			RETURN_MM_FALSE;
	
		case 306:
			RETURN_MM_TRUE;
	
		case 308:
			PHALCON_INIT_VAR(array_value);
			array_init(array_value);
	
			PHALCON_OBS_VAR(items);
			phalcon_array_fetch_string(&items, expr, SL("items"), PH_NOISY_CC);
	
			if (!phalcon_is_iterable(items, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
				return;
			}
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_HVALUE(item);
	
				PHALCON_OBS_NVAR(expr);
				phalcon_array_fetch_string(&expr, item, SL("expr"), PH_NOISY_CC);
	
				PHALCON_INIT_NVAR(resolved_item);
				phalcon_call_method_p1(resolved_item, this_ptr, "getexpression", expr);
				if (phalcon_array_isset_string(item, SS("name"))) {
					PHALCON_OBS_NVAR(name);
					phalcon_array_fetch_string(&name, item, SL("name"), PH_NOISY_CC);
					phalcon_array_update_zval(&array_value, name, &resolved_item, PH_COPY | PH_SEPARATE TSRMLS_CC);
				} else {
					phalcon_array_append(&array_value, resolved_item, PH_SEPARATE TSRMLS_CC);
				}
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
			RETURN_CTOR(array_value);
	
		case 300:
			PHALCON_INIT_VAR(annotation);
			object_init_ex(annotation, phalcon_annotations_annotation_ce);
			phalcon_call_method_p1_noret(annotation, "__construct", expr);
	
			RETURN_CTOR(annotation);
	
		default:
			PHALCON_INIT_VAR(exception_message);
			PHALCON_CONCAT_SVS(exception_message, "The expression ", type, " is unknown");
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_annotations_exception_ce, exception_message);
			return;
	
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the expression arguments without resolving
 *
 * @return array
 */
PHP_METHOD(Phalcon_Annotations_Annotation, getExprArguments){


	RETURN_MEMBER(this_ptr, "_exprArguments");
}

/**
 * Returns the expression arguments
 *
 * @return array
 */
PHP_METHOD(Phalcon_Annotations_Annotation, getArguments){


	RETURN_MEMBER(this_ptr, "_arguments");
}

/**
 * Returns the number of arguments that the annotation has
 *
 * @return int
 */
PHP_METHOD(Phalcon_Annotations_Annotation, numberArguments){

	zval *arguments, *number;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(arguments);
	phalcon_read_property_this(&arguments, this_ptr, SL("_arguments"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(number);
	phalcon_fast_count(number, arguments TSRMLS_CC);
	RETURN_NCTOR(number);
}

/**
 * Returns an argument in a specific position
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Annotations_Annotation, getArgument){

	zval *position, *arguments, *value;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &position);
	
	PHALCON_OBS_VAR(arguments);
	phalcon_read_property_this(&arguments, this_ptr, SL("_arguments"), PH_NOISY_CC);
	if (phalcon_array_isset(arguments, position)) {
		PHALCON_OBS_VAR(value);
		phalcon_array_fetch(&value, arguments, position, PH_NOISY_CC);
		RETURN_CCTOR(value);
	}
	
	RETURN_MM_NULL();
}

/**
 * Returns an argument in a specific position
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Annotations_Annotation, hasArgument){

	zval *position, *arguments;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &position);
	
	PHALCON_OBS_VAR(arguments);
	phalcon_read_property_this(&arguments, this_ptr, SL("_arguments"), PH_NOISY_CC);
	if (phalcon_array_isset(arguments, position)) {
		RETURN_MM_TRUE;
	}
	
	RETURN_MM_FALSE;
}

/**
 * Returns a named argument
 *
 * @param string $name
 * @return mixed
 */
PHP_METHOD(Phalcon_Annotations_Annotation, getNamedArgument){

	zval *name, *arguments, *value;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &name);
	
	PHALCON_OBS_VAR(arguments);
	phalcon_read_property_this(&arguments, this_ptr, SL("_arguments"), PH_NOISY_CC);
	if (phalcon_array_isset(arguments, name)) {
		PHALCON_OBS_VAR(value);
		phalcon_array_fetch(&value, arguments, name, PH_NOISY_CC);
		RETURN_CCTOR(value);
	}
	
	RETURN_MM_NULL();
}

/**
 * Returns a named argument (deprecated)
 *
 * @param string $name
 * @return mixed
 */
PHP_METHOD(Phalcon_Annotations_Annotation, getNamedParameter){

	zval *name, *arguments, *value;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &name);
	
	PHALCON_OBS_VAR(arguments);
	phalcon_read_property_this(&arguments, this_ptr, SL("_arguments"), PH_NOISY_CC);
	if (phalcon_array_isset(arguments, name)) {
		PHALCON_OBS_VAR(value);
		phalcon_array_fetch(&value, arguments, name, PH_NOISY_CC);
		RETURN_CCTOR(value);
	}
	
	RETURN_MM_NULL();
}

/**
 * Checks if the annotation has a specific named argument
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Annotations_Annotation, hasNamedArgument){

	zval *name, *arguments;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &name);
	
	PHALCON_OBS_VAR(arguments);
	phalcon_read_property_this(&arguments, this_ptr, SL("_arguments"), PH_NOISY_CC);
	if (phalcon_array_isset(arguments, name)) {
		RETURN_MM_TRUE;
	}
	
	RETURN_MM_FALSE;
}

