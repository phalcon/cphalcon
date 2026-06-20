
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Represents a single resolved frame of an exception backtrace.
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Debug_Report_BacktraceItem)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Debug\\Report, BacktraceItem, phalcon, support_debug_report_backtraceitem, phalcon_support_debug_report_backtraceitem_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_support_debug_report_backtraceitem_ce, SL("args"), ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_support_debug_report_backtraceitem_ce, SL("classLink"), ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_support_debug_report_backtraceitem_ce, SL("className"), ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_support_debug_report_backtraceitem_ce, SL("file"), ZEND_ACC_PROTECTED);
	/**
	 * @var array|null
	 */
	zend_declare_property_null(phalcon_support_debug_report_backtraceitem_ce, SL("fragment"), ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_support_debug_report_backtraceitem_ce, SL("functionLink"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_support_debug_report_backtraceitem_ce, SL("functionName"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_support_debug_report_backtraceitem_ce, SL("hasArgs"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var int|null
	 */
	zend_declare_property_null(phalcon_support_debug_report_backtraceitem_ce, SL("line"), ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_support_debug_report_backtraceitem_ce, SL("type"), ZEND_ACC_PROTECTED);
	phalcon_support_debug_report_backtraceitem_ce->create_object = zephir_init_properties_Phalcon_Support_Debug_Report_BacktraceItem;

	return SUCCESS;
}

/**
 * @param string      $functionName
 * @param string|null $type
 * @param string|null $className
 * @param string|null $classLink
 * @param string|null $functionLink
 * @param bool        $hasArgs
 * @param array       $args
 * @param string|null $file
 * @param int|null    $line
 * @param array|null  $fragment
 */
PHP_METHOD(Phalcon_Support_Debug_Report_BacktraceItem, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval args;
	zend_bool hasArgs;
	zval functionName_zv, *type = NULL, type_sub, *className = NULL, className_sub, *classLink = NULL, classLink_sub, *functionLink = NULL, functionLink_sub, *hasArgs_param = NULL, *args_param = NULL, *file = NULL, file_sub, *line = NULL, line_sub, *fragment = NULL, fragment_sub, __$true, __$false, __$null;
	zend_string *functionName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&functionName_zv);
	ZVAL_UNDEF(&type_sub);
	ZVAL_UNDEF(&className_sub);
	ZVAL_UNDEF(&classLink_sub);
	ZVAL_UNDEF(&functionLink_sub);
	ZVAL_UNDEF(&file_sub);
	ZVAL_UNDEF(&line_sub);
	ZVAL_UNDEF(&fragment_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&args);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 10)
		Z_PARAM_STR(functionName)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(type)
		Z_PARAM_ZVAL_OR_NULL(className)
		Z_PARAM_ZVAL_OR_NULL(classLink)
		Z_PARAM_ZVAL_OR_NULL(functionLink)
		Z_PARAM_BOOL(hasArgs)
		ZEPHIR_Z_PARAM_ARRAY(args, args_param)
		Z_PARAM_ZVAL_OR_NULL(file)
		Z_PARAM_ZVAL_OR_NULL(line)
		Z_PARAM_ZVAL_OR_NULL(fragment)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		type = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		className = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		classLink = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		functionLink = ZEND_CALL_ARG(execute_data, 5);
	}
	if (ZEND_NUM_ARGS() > 5) {
		hasArgs_param = ZEND_CALL_ARG(execute_data, 6);
	}
	if (ZEND_NUM_ARGS() > 6) {
		args_param = ZEND_CALL_ARG(execute_data, 7);
	}
	if (ZEND_NUM_ARGS() > 7) {
		file = ZEND_CALL_ARG(execute_data, 8);
	}
	if (ZEND_NUM_ARGS() > 8) {
		line = ZEND_CALL_ARG(execute_data, 9);
	}
	if (ZEND_NUM_ARGS() > 9) {
		fragment = ZEND_CALL_ARG(execute_data, 10);
	}
	ZVAL_STR(&functionName_zv, functionName);
	if (!type) {
		type = &type_sub;
		type = &__$null;
	}
	if (!className) {
		className = &className_sub;
		className = &__$null;
	}
	if (!classLink) {
		classLink = &classLink_sub;
		classLink = &__$null;
	}
	if (!functionLink) {
		functionLink = &functionLink_sub;
		functionLink = &__$null;
	}
	if (!hasArgs_param) {
		hasArgs = 0;
	} else {
		}
	if (!args_param) {
		ZEPHIR_INIT_VAR(&args);
		array_init(&args);
	} else {
		zephir_get_arrval(&args, args_param);
	}
	if (!file) {
		file = &file_sub;
		file = &__$null;
	}
	if (!line) {
		line = &line_sub;
		line = &__$null;
	}
	if (!fragment) {
		fragment = &fragment_sub;
		fragment = &__$null;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("functionName"), &functionName_zv);
	zephir_update_property_zval(this_ptr, ZEND_STRL("type"), type);
	zephir_update_property_zval(this_ptr, ZEND_STRL("className"), className);
	zephir_update_property_zval(this_ptr, ZEND_STRL("classLink"), classLink);
	zephir_update_property_zval(this_ptr, ZEND_STRL("functionLink"), functionLink);
	if (hasArgs) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("hasArgs"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("hasArgs"), &__$false);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("args"), &args);
	zephir_update_property_zval(this_ptr, ZEND_STRL("file"), file);
	zephir_update_property_zval(this_ptr, ZEND_STRL("line"), line);
	zephir_update_property_zval(this_ptr, ZEND_STRL("fragment"), fragment);
	ZEPHIR_MM_RESTORE();
}

/**
 * @return array
 */
PHP_METHOD(Phalcon_Support_Debug_Report_BacktraceItem, getArgs)
{

	RETURN_MEMBER_TYPED(getThis(), "args", IS_ARRAY);
}

/**
 * @return string|null
 */
PHP_METHOD(Phalcon_Support_Debug_Report_BacktraceItem, getClassLink)
{

	RETURN_MEMBER(getThis(), "classLink");
}

/**
 * @return string|null
 */
PHP_METHOD(Phalcon_Support_Debug_Report_BacktraceItem, getClassName)
{

	RETURN_MEMBER(getThis(), "className");
}

/**
 * @return string|null
 */
PHP_METHOD(Phalcon_Support_Debug_Report_BacktraceItem, getFile)
{

	RETURN_MEMBER(getThis(), "file");
}

/**
 * @return array|null
 */
PHP_METHOD(Phalcon_Support_Debug_Report_BacktraceItem, getFragment)
{

	RETURN_MEMBER(getThis(), "fragment");
}

/**
 * @return string|null
 */
PHP_METHOD(Phalcon_Support_Debug_Report_BacktraceItem, getFunctionLink)
{

	RETURN_MEMBER(getThis(), "functionLink");
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Support_Debug_Report_BacktraceItem, getFunctionName)
{

	RETURN_MEMBER_TYPED(getThis(), "functionName", IS_STRING);
}

/**
 * @return int|null
 */
PHP_METHOD(Phalcon_Support_Debug_Report_BacktraceItem, getLine)
{

	RETURN_MEMBER(getThis(), "line");
}

/**
 * @return string|null
 */
PHP_METHOD(Phalcon_Support_Debug_Report_BacktraceItem, getType)
{

	RETURN_MEMBER(getThis(), "type");
}

/**
 * @return bool
 */
PHP_METHOD(Phalcon_Support_Debug_Report_BacktraceItem, hasArgs)
{

	RETURN_MEMBER(getThis(), "hasArgs");
}

zend_object *zephir_init_properties_Phalcon_Support_Debug_Report_BacktraceItem(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("args"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("args"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

