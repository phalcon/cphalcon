
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */
/**
 * Represents a single annotation in an annotations collection
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Annotation)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Annotations, Annotation, phalcon, annotations_annotation, phalcon_annotations_annotation_method_entry, 0);

	/**
	 * Annotation Arguments
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_annotations_annotation_ce, SL("arguments"), ZEND_ACC_PROTECTED);
	/**
	 * Annotation ExprArguments
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_annotations_annotation_ce, SL("exprArguments"), ZEND_ACC_PROTECTED);
	/**
	 * Annotation Name
	 *
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_annotations_annotation_ce, SL("name"), ZEND_ACC_PROTECTED);
	phalcon_annotations_annotation_ce->create_object = zephir_init_properties_Phalcon_Annotations_Annotation;

	return SUCCESS;
}

/**
 * Phalcon\Annotations\Annotation constructor
 */
PHP_METHOD(Phalcon_Annotations_Annotation, __construct)
{
	zend_bool _7$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *reflectionData_param = NULL, name, exprArguments, argument, resolvedArgument, _0$$3, *_1$$4, _2$$4, *_3$$4, _6$$4, _4$$5, _8$$8;
	zval reflectionData, arguments;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&reflectionData);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&exprArguments);
	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&resolvedArgument);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_8$$8);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("name", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("arguments", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("exprArguments", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(reflectionData, reflectionData_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &reflectionData_param);
	zephir_get_arrval(&reflectionData, reflectionData_param);
	zephir_memory_observe(&name);
	if (zephir_array_isset_string_fetch(&name, &reflectionData, SL("name"), 0)) {
		zephir_array_fetch_string(&_0$$3, &reflectionData, SL("name"), PH_NOISY | PH_READONLY, "phalcon/Annotations/Annotation.zep", 50);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 399, &_0$$3);
	}
	zephir_memory_observe(&exprArguments);
	if (zephir_array_isset_string_fetch(&exprArguments, &reflectionData, SL("arguments"), 0)) {
		ZEPHIR_INIT_VAR(&arguments);
		array_init(&arguments);
		if (Z_TYPE_P(&exprArguments) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_2$$4);
			zephir_string_to_char_array(&_2$$4, &exprArguments);
			_1$$4 = &_2$$4;
		} else {
			_1$$4 = &exprArguments;
		}
		zephir_is_iterable(_1$$4, 0, "phalcon/Annotations/Annotation.zep", 71);
		if (Z_TYPE_P(_1$$4) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1$$4), _3$$4)
			{
				ZEPHIR_INIT_NVAR(&argument);
				ZVAL_COPY(&argument, _3$$4);
				zephir_array_fetch_string(&_4$$5, &argument, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/Annotations/Annotation.zep", 62);
				ZEPHIR_CALL_METHOD(&resolvedArgument, this_ptr, "getexpression", &_5, 0, &_4$$5);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&name);
				if (zephir_array_isset_string_fetch(&name, &argument, SL("name"), 0)) {
					zephir_array_update_zval(&arguments, &name, &resolvedArgument, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_append(&arguments, &resolvedArgument, PH_SEPARATE, "phalcon/Annotations/Annotation.zep", 67);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _1$$4, "rewind", NULL, 0);
			zephir_check_call_status();
			_7$$4 = 1;
			while (1) {
				if (_7$$4) {
					_7$$4 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _1$$4, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_6$$4, _1$$4, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_6$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&argument, _1$$4, "current", NULL, 0);
				zephir_check_call_status();
					zephir_array_fetch_string(&_8$$8, &argument, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/Annotations/Annotation.zep", 62);
					ZEPHIR_CALL_METHOD(&resolvedArgument, this_ptr, "getexpression", &_5, 0, &_8$$8);
					zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&name);
					if (zephir_array_isset_string_fetch(&name, &argument, SL("name"), 0)) {
						zephir_array_update_zval(&arguments, &name, &resolvedArgument, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_append(&arguments, &resolvedArgument, PH_SEPARATE, "phalcon/Annotations/Annotation.zep", 67);
					}
			}
		}
		ZEPHIR_INIT_NVAR(&argument);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 400, &arguments);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 401, &exprArguments);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns an argument in a specific position
 */
PHP_METHOD(Phalcon_Annotations_Annotation, getArgument)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *position, position_sub, argument, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&position_sub);
	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("arguments", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(position)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &position);
	zephir_memory_observe(&argument);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 400, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&argument, &_0, position, 0)) {
		RETURN_CCTOR(&argument);
	}
	RETURN_MM_NULL();
}

/**
 * Returns the expression arguments
 */
PHP_METHOD(Phalcon_Annotations_Annotation, getArguments)
{

	RETURN_MEMBER_TYPED(getThis(), "arguments", IS_ARRAY);
}

/**
 * Returns the expression arguments without resolving
 */
PHP_METHOD(Phalcon_Annotations_Annotation, getExprArguments)
{

	RETURN_MEMBER_TYPED(getThis(), "exprArguments", IS_ARRAY);
}

/**
 * Resolves an annotation expression
 */
PHP_METHOD(Phalcon_Annotations_Annotation, getExpression)
{
	zend_bool _7$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, value, item, resolvedItem, arrayValue, name, type, _0$$7, *_1$$7, _2$$7, *_3$$7, _6$$7, _4$$8, _8$$11, _9$$15;
	zval expr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&resolvedItem);
	ZVAL_UNDEF(&arrayValue);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_0$$7);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_9$$15);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(expr, expr_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &expr_param);
	zephir_get_arrval(&expr, expr_param);
	zephir_memory_observe(&type);
	zephir_array_fetch_string(&type, &expr, SL("type"), PH_NOISY, "phalcon/Annotations/Annotation.zep", 113);
	if (ZEPHIR_IS_LONG(&type, 301)) { goto zephir_switch_0_clause_0; }
	if (ZEPHIR_IS_LONG(&type, 302)) { goto zephir_switch_0_clause_1; }
	if (ZEPHIR_IS_LONG(&type, 303)) { goto zephir_switch_0_clause_2; }
	if (ZEPHIR_IS_LONG(&type, 307)) { goto zephir_switch_0_clause_3; }
	if (ZEPHIR_IS_LONG(&type, 304)) { goto zephir_switch_0_clause_4; }
	if (ZEPHIR_IS_LONG(&type, 305)) { goto zephir_switch_0_clause_5; }
	if (ZEPHIR_IS_LONG(&type, 306)) { goto zephir_switch_0_clause_6; }
	if (ZEPHIR_IS_LONG(&type, 308)) { goto zephir_switch_0_clause_7; }
	if (ZEPHIR_IS_LONG(&type, 300)) { goto zephir_switch_0_clause_8; }
	goto zephir_switch_0_clause_9;
	zephir_switch_0_clause_0: ;
	zephir_switch_0_clause_1: ;
	zephir_switch_0_clause_2: ;
	zephir_switch_0_clause_3: ;
		zephir_memory_observe(&value);
		zephir_array_fetch_string(&value, &expr, SL("value"), PH_NOISY, "phalcon/Annotations/Annotation.zep", 120);
		goto zephir_switch_0_end;
	zephir_switch_0_clause_4: ;
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_NULL(&value);
		goto zephir_switch_0_end;
	zephir_switch_0_clause_5: ;
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_BOOL(&value, 0);
		goto zephir_switch_0_end;
	zephir_switch_0_clause_6: ;
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_BOOL(&value, 1);
		goto zephir_switch_0_end;
	zephir_switch_0_clause_7: ;
		ZEPHIR_INIT_VAR(&arrayValue);
		array_init(&arrayValue);
		zephir_array_fetch_string(&_0$$7, &expr, SL("items"), PH_NOISY | PH_READONLY, "phalcon/Annotations/Annotation.zep", 138);
		if (Z_TYPE_P(&_0$$7) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_2$$7);
			zephir_string_to_char_array(&_2$$7, &_0$$7);
			_1$$7 = &_2$$7;
		} else {
			_1$$7 = &_0$$7;
		}
		zephir_is_iterable(_1$$7, 0, "phalcon/Annotations/Annotation.zep", 150);
		if (Z_TYPE_P(_1$$7) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1$$7), _3$$7)
			{
				ZEPHIR_INIT_NVAR(&item);
				ZVAL_COPY(&item, _3$$7);
				zephir_array_fetch_string(&_4$$8, &item, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/Annotations/Annotation.zep", 141);
				ZEPHIR_CALL_METHOD(&resolvedItem, this_ptr, "getexpression", &_5, 361, &_4$$8);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&name);
				if (zephir_array_isset_string_fetch(&name, &item, SL("name"), 0)) {
					zephir_array_update_zval(&arrayValue, &name, &resolvedItem, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_append(&arrayValue, &resolvedItem, PH_SEPARATE, "phalcon/Annotations/Annotation.zep", 146);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _1$$7, "rewind", NULL, 0);
			zephir_check_call_status();
			_7$$7 = 1;
			while (1) {
				if (_7$$7) {
					_7$$7 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _1$$7, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_6$$7, _1$$7, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_6$$7)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&item, _1$$7, "current", NULL, 0);
				zephir_check_call_status();
					zephir_array_fetch_string(&_8$$11, &item, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/Annotations/Annotation.zep", 141);
					ZEPHIR_CALL_METHOD(&resolvedItem, this_ptr, "getexpression", &_5, 361, &_8$$11);
					zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&name);
					if (zephir_array_isset_string_fetch(&name, &item, SL("name"), 0)) {
						zephir_array_update_zval(&arrayValue, &name, &resolvedItem, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_append(&arrayValue, &resolvedItem, PH_SEPARATE, "phalcon/Annotations/Annotation.zep", 146);
					}
			}
		}
		ZEPHIR_INIT_NVAR(&item);
		RETURN_CCTOR(&arrayValue);
	zephir_switch_0_clause_8: ;
		object_init_ex(return_value, phalcon_annotations_annotation_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 362, &expr);
		zephir_check_call_status();
		RETURN_MM();
	zephir_switch_0_clause_9: ;
		ZEPHIR_INIT_VAR(&_9$$15);
		object_init_ex(&_9$$15, phalcon_annotations_exceptions_unknownannotationexpression_ce);
		ZEPHIR_CALL_METHOD(NULL, &_9$$15, "__construct", NULL, 363, &type);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_9$$15, "phalcon/Annotations/Annotation.zep", 156);
		ZEPHIR_MM_RESTORE();
		return;
	zephir_switch_0_end: ;

	RETURN_CCTOR(&value);
}

/**
 * Returns the annotation's name
 */
PHP_METHOD(Phalcon_Annotations_Annotation, getName)
{

	RETURN_MEMBER(getThis(), "name");
}

/**
 * Returns a named argument
 */
PHP_METHOD(Phalcon_Annotations_Annotation, getNamedArgument)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval name_zv, argument, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("arguments", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_memory_observe(&argument);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 400, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&argument, &_0, &name_zv, 0)) {
		RETURN_CCTOR(&argument);
	}
	RETURN_MM_NULL();
}

/**
 * Returns a named parameter
 */
PHP_METHOD(Phalcon_Annotations_Annotation, getNamedParameter)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getnamedargument", NULL, 0, &name_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns an argument in a specific position
 */
PHP_METHOD(Phalcon_Annotations_Annotation, hasArgument)
{
	zval *position, position_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&position_sub);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("arguments", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(position)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &position);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 400, PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset_value(&_0, position));
}

/**
 * Returns the number of arguments that the annotation has
 */
PHP_METHOD(Phalcon_Annotations_Annotation, numberArguments)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("arguments", 9, 1);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 400, PH_NOISY_CC | PH_READONLY);
	RETURN_LONG(zephir_fast_count_int(&_0));
}

zend_object *zephir_init_properties_Phalcon_Annotations_Annotation(zend_class_entry *class_type)
{
		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("exprArguments"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("exprArguments"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("arguments"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("arguments"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

