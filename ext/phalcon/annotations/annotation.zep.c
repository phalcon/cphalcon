
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/hash.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


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
 */
PHP_METHOD(Phalcon_Annotations_Annotation, __construct) {

	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *reflectionData_param = NULL, name, exprArguments, argument, resolvedArgument, arguments, _0, *_1$$3, _2$$4;
	zval reflectionData;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&reflectionData);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&exprArguments);
	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&resolvedArgument);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &reflectionData_param);

	ZEPHIR_OBS_COPY_OR_DUP(&reflectionData, reflectionData_param);


	zephir_array_fetch_string(&_0, &reflectionData, SL("name"), PH_NOISY | PH_READONLY, "phalcon/annotations/annotation.zep", 58 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("_name"), &_0);
	ZEPHIR_OBS_VAR(&exprArguments);
	if (zephir_array_isset_string_fetch(&exprArguments, &reflectionData, SL("arguments"), 0)) {
		ZEPHIR_INIT_VAR(&arguments);
		array_init(&arguments);
		zephir_is_iterable(&exprArguments, 0, "phalcon/annotations/annotation.zep", 73);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&exprArguments), _1$$3)
		{
			ZEPHIR_INIT_NVAR(&argument);
			ZVAL_COPY(&argument, _1$$3);
			zephir_array_fetch_string(&_2$$4, &argument, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/annotations/annotation.zep", 66 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&resolvedArgument, this_ptr, "getexpression", &_3, 0, &_2$$4);
			zephir_check_call_status();
			if (zephir_array_isset_string_fetch(&name, &argument, SL("name"), 1)) {
				zephir_array_update_zval(&arguments, &name, &resolvedArgument, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_append(&arguments, &resolvedArgument, PH_SEPARATE, "phalcon/annotations/annotation.zep", 70);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&argument);
		zephir_update_property_zval(this_ptr, SL("_arguments"), &arguments);
		zephir_update_property_zval(this_ptr, SL("_exprArguments"), &exprArguments);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the annotation's name
 */
PHP_METHOD(Phalcon_Annotations_Annotation, getName) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_name");

}

/**
 * Resolves an annotation expression
 *
 * @param array expr
 * @return mixed
 */
PHP_METHOD(Phalcon_Annotations_Annotation, getExpression) {

	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, value, item, resolvedItem, arrayValue, name, type, _0$$7, *_1$$7, _2$$8, _4$$12, _5$$12;
	zval expr;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&resolvedItem);
	ZVAL_UNDEF(&arrayValue);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_0$$7);
	ZVAL_UNDEF(&_2$$8);
	ZVAL_UNDEF(&_4$$12);
	ZVAL_UNDEF(&_5$$12);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expr_param);

	ZEPHIR_OBS_COPY_OR_DUP(&expr, expr_param);


	ZEPHIR_OBS_VAR(&type);
	zephir_array_fetch_string(&type, &expr, SL("type"), PH_NOISY, "phalcon/annotations/annotation.zep", 96 TSRMLS_CC);
	do {
		if (ZEPHIR_IS_LONG(&type, 301) || ZEPHIR_IS_LONG(&type, 302) || ZEPHIR_IS_LONG(&type, 303) || ZEPHIR_IS_LONG(&type, 307)) {
			ZEPHIR_OBS_VAR(&value);
			zephir_array_fetch_string(&value, &expr, SL("value"), PH_NOISY, "phalcon/annotations/annotation.zep", 103 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(&type, 304)) {
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_NULL(&value);
			break;
		}
		if (ZEPHIR_IS_LONG(&type, 305)) {
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_BOOL(&value, 0);
			break;
		}
		if (ZEPHIR_IS_LONG(&type, 306)) {
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_BOOL(&value, 1);
			break;
		}
		if (ZEPHIR_IS_LONG(&type, 308)) {
			ZEPHIR_INIT_VAR(&arrayValue);
			array_init(&arrayValue);
			zephir_array_fetch_string(&_0$$7, &expr, SL("items"), PH_NOISY | PH_READONLY, "phalcon/annotations/annotation.zep", 120 TSRMLS_CC);
			zephir_is_iterable(&_0$$7, 0, "phalcon/annotations/annotation.zep", 128);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0$$7), _1$$7)
			{
				ZEPHIR_INIT_NVAR(&item);
				ZVAL_COPY(&item, _1$$7);
				zephir_array_fetch_string(&_2$$8, &item, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/annotations/annotation.zep", 121 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&resolvedItem, this_ptr, "getexpression", &_3, 92, &_2$$8);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&name);
				if (zephir_array_isset_string_fetch(&name, &item, SL("name"), 0)) {
					zephir_array_update_zval(&arrayValue, &name, &resolvedItem, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_append(&arrayValue, &resolvedItem, PH_SEPARATE, "phalcon/annotations/annotation.zep", 125);
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&item);
			RETURN_CCTOR(arrayValue);
		}
		if (ZEPHIR_IS_LONG(&type, 300)) {
			object_init_ex(return_value, phalcon_annotations_annotation_ce);
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 93, &expr);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(&_4$$12);
		object_init_ex(&_4$$12, phalcon_annotations_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$12);
		ZEPHIR_CONCAT_SVS(&_5$$12, "The expression ", &type, " is unknown");
		ZEPHIR_CALL_METHOD(NULL, &_4$$12, "__construct", NULL, 9, &_5$$12);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$12, "phalcon/annotations/annotation.zep", 134 TSRMLS_CC);
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

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_exprArguments");

}

/**
 * Returns the expression arguments
 *
 * @return array
 */
PHP_METHOD(Phalcon_Annotations_Annotation, getArguments) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_arguments");

}

/**
 * Returns the number of arguments that the annotation has
 */
PHP_METHOD(Phalcon_Annotations_Annotation, numberArguments) {

	zval _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("_arguments"), PH_NOISY_CC | PH_READONLY);
	RETURN_LONG(zephir_fast_count_int(&_0 TSRMLS_CC));

}

/**
 * Returns an argument in a specific position
 *
 * @param int|string position
 * @return mixed
 */
PHP_METHOD(Phalcon_Annotations_Annotation, getArgument) {

	zval *position, position_sub, argument, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&position_sub);
	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &position);



	zephir_read_property(&_0, this_ptr, SL("_arguments"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&argument, &_0, position, 1 TSRMLS_CC)) {
		RETURN_CTORW(argument);
	}

}

/**
 * Returns an argument in a specific position
 *
 * @param int|string position
 * @return boolean
 */
PHP_METHOD(Phalcon_Annotations_Annotation, hasArgument) {

	zval *position, position_sub, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&position_sub);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &position);



	zephir_read_property(&_0, this_ptr, SL("_arguments"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset(&_0, position));

}

/**
 * Returns a named argument
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Annotations_Annotation, getNamedArgument) {

	zval *name_param = NULL, argument, _0;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_read_property(&_0, this_ptr, SL("_arguments"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&argument, &_0, &name, 1 TSRMLS_CC)) {
		RETURN_CTOR(argument);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a named parameter
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Annotations_Annotation, getNamedParameter) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getnamedargument", NULL, 0, &name);
	zephir_check_call_status();
	RETURN_MM();

}

