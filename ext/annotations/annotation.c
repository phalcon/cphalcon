
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "annotations/annotation.h"
#include "annotations/exception.h"
#include "annotations/scanner.h"

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
zend_class_entry *phalcon_annotations_annotation_ce;

PHP_METHOD(Phalcon_Annotations_Annotation, __construct);
PHP_METHOD(Phalcon_Annotations_Annotation, getName);
PHP_METHOD(Phalcon_Annotations_Annotation, getExpression);
PHP_METHOD(Phalcon_Annotations_Annotation, getExprArguments);
PHP_METHOD(Phalcon_Annotations_Annotation, getArguments);
PHP_METHOD(Phalcon_Annotations_Annotation, numberArguments);
PHP_METHOD(Phalcon_Annotations_Annotation, getArgument);
PHP_METHOD(Phalcon_Annotations_Annotation, hasArgument);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_annotation___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, reflectionData)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_annotation_getexpression, 0, 0, 1)
	ZEND_ARG_INFO(0, expr)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_annotation_getargument, 0, 0, 1)
	ZEND_ARG_INFO(0, position)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_annotation_hasargument, 0, 0, 1)
	ZEND_ARG_INFO(0, position)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_annotations_annotation_method_entry[] = {
	PHP_ME(Phalcon_Annotations_Annotation, __construct, arginfo_phalcon_annotations_annotation___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Annotations_Annotation, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Annotation, getExpression, arginfo_phalcon_annotations_annotation_getexpression, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Annotation, getExprArguments, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Annotation, getArguments, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Annotation, numberArguments, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Annotation, getArgument, arginfo_phalcon_annotations_annotation_getargument, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Annotation, hasArgument, arginfo_phalcon_annotations_annotation_hasargument, ZEND_ACC_PUBLIC)
	PHP_MALIAS(Phalcon_Annotations_Annotation, getNamedArgument, getArgument, arginfo_phalcon_annotations_annotation_getargument, ZEND_ACC_PUBLIC)
	PHP_MALIAS(Phalcon_Annotations_Annotation, getNamedParameter, getArgument, arginfo_phalcon_annotations_annotation_getargument, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
	PHP_MALIAS(Phalcon_Annotations_Annotation, hasNamedArgument, hasArgument, arginfo_phalcon_annotations_annotation_hasargument, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

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
	phalcon_array_fetch_string(&name, reflection_data, SL("name"), PH_NOISY);
	phalcon_update_property_this(this_ptr, SL("_name"), name TSRMLS_CC);
	
	/** 
	 * Process annotation arguments
	 */
	if (phalcon_array_isset_string_fetch(&expr_arguments, reflection_data, SS("arguments"))) {
	
		phalcon_is_iterable(expr_arguments, &ah0, &hp0, 0, 0);
	
		PHALCON_INIT_VAR(arguments);
		array_init_size(arguments, zend_hash_num_elements(ah0));

		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
			zval *n;

			PHALCON_GET_HVALUE(argument);
	
			PHALCON_OBS_NVAR(expr);
			phalcon_array_fetch_string(&expr, argument, SL("expr"), PH_NOISY);
	
			PHALCON_CALL_METHOD(&resolved_argument, this_ptr, "getexpression", expr);
			if (phalcon_array_isset_string_fetch(&n, argument, SS("name"))) {
				phalcon_array_update_zval(&arguments, n, resolved_argument, PH_COPY);
			} else {
				phalcon_array_append(&arguments, resolved_argument, 0);
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

	zval *expr = NULL, *type, *items, *item = NULL;
	zval *resolved_item = NULL, *exception_message;
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
	phalcon_array_fetch_string(&type, expr, SL("type"), PH_NOISY);
	
	switch (phalcon_get_intval(type)) {
	
		case PHANNOT_T_INTEGER:
		case PHANNOT_T_DOUBLE:
		case PHANNOT_T_STRING:
		case PHANNOT_T_IDENTIFIER:
			if (return_value_ptr) {
				zval_ptr_dtor(return_value_ptr);
				phalcon_array_fetch_string(return_value_ptr, expr, SL("value"), PH_NOISY);
			}
			else {
				phalcon_array_fetch_string(&return_value, expr, SL("value"), PH_NOISY);
			}
			RETURN_MM();
			/* no break because of implicit return */
	
		case PHANNOT_T_NULL:
			RETURN_MM_NULL();
			/* no break because of implicit return */
	
		case PHANNOT_T_FALSE:
			RETURN_MM_FALSE;
			/* no break because of implicit return */
	
		case PHANNOT_T_TRUE:
			RETURN_MM_TRUE;
			/* no break because of implicit return */
	
		case PHANNOT_T_ARRAY:
			PHALCON_OBS_VAR(items);
			phalcon_array_fetch_string(&items, expr, SL("items"), PH_NOISY);
	
			phalcon_is_iterable(items, &ah0, &hp0, 0, 0);
			array_init_size(return_value, zend_hash_num_elements(ah0));
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
				zval *name;
	
				PHALCON_GET_HVALUE(item);
	
				PHALCON_OBS_NVAR(expr);
				phalcon_array_fetch_string(&expr, item, SL("expr"), PH_NOISY);
	
				PHALCON_CALL_METHOD(&resolved_item, this_ptr, "getexpression", expr);
				if (phalcon_array_isset_string_fetch(&name, item, SS("name"))) {
					phalcon_array_update_zval(&return_value, name, resolved_item, PH_COPY);
				} else {
					phalcon_array_append(&return_value, resolved_item, 0);
				}
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
			RETURN_MM();
			/* no break because of implicit return */
	
		case PHANNOT_T_ANNOTATION:
			object_init_ex(return_value, phalcon_annotations_annotation_ce);
			PHALCON_CALL_METHOD(NULL, return_value, "__construct", expr);
			RETURN_MM();
			/* no break because of implicit return */
	
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

	zval *arguments;

	arguments = phalcon_fetch_nproperty_this(this_ptr, SL("_arguments"), PH_NOISY TSRMLS_CC);
	phalcon_fast_count(return_value, arguments TSRMLS_CC);
}

/**
 * Returns an argument in a specific position
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Annotations_Annotation, getArgument){

	zval *position, *arguments, *tmp;

	phalcon_fetch_params(0, 1, 0, &position);
	
	arguments = phalcon_fetch_nproperty_this(this_ptr, SL("_arguments"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset_fetch(&tmp, arguments, position)) {
		RETURN_ZVAL(tmp, 1, 0);
	}
}

/**
 * Checks if the annotation has a specific argument
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Annotations_Annotation, hasArgument){

	zval *position, *arguments;

	phalcon_fetch_params(0, 1, 0, &position);
	
	arguments = phalcon_fetch_nproperty_this(this_ptr, SL("_arguments"), PH_NOISY TSRMLS_CC);
	RETURN_BOOL(phalcon_array_isset(arguments, position));
}

/**
 * Returns a named argument
 *
 * @param string $name
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_Annotations_Annotation, getNamedArgument);

/**
 * Returns a named argument (deprecated)
 *
 * @deprecated
 * @param string $name
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_Annotations_Annotation, getNamedParameter);

/**
 * Checks if the annotation has a specific named argument
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Annotations_Annotation, hasNamedArgument);
