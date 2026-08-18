
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"


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
 *
 * @phpstan-import-type support_debug_args from SupportTypes
 * @phpstan-import-type support_debug_fragment from SupportTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Debug_Report_BacktraceItem)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Debug\\Report, BacktraceItem, phalcon, support_debug_report_backtraceitem, phalcon_support_debug_report_backtraceitem_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @phpstan-param support_debug_args          $args
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_support_debug_report_backtraceitem_ce, SL("args"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_support_debug_report_backtraceitem_ce, SL("classLink"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_STRING|MAY_BE_NULL, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_support_debug_report_backtraceitem_ce, SL("className"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_STRING|MAY_BE_NULL, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_support_debug_report_backtraceitem_ce, SL("file"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_STRING|MAY_BE_NULL, NULL, 0);
	}

	/**
	 * @phpstan-param support_debug_fragment|null $fragment
	 */
	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_support_debug_report_backtraceitem_ce, SL("fragment"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_ARRAY|MAY_BE_NULL, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_support_debug_report_backtraceitem_ce, SL("functionLink"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_STRING|MAY_BE_NULL, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_support_debug_report_backtraceitem_ce, SL("functionName"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_support_debug_report_backtraceitem_ce, SL("hasArgs"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_BOOL, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_support_debug_report_backtraceitem_ce, SL("line"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_LONG|MAY_BE_NULL, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_support_debug_report_backtraceitem_ce, SL("type"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_STRING|MAY_BE_NULL, NULL, 0);
	}

	return SUCCESS;
}

PHP_METHOD(Phalcon_Support_Debug_Report_BacktraceItem, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long line;
	zval args;
	zend_bool hasArgs;
	zval functionName_zv, type_zv, className_zv, classLink_zv, functionLink_zv, *hasArgs_param = NULL, *args_param = NULL, file_zv, *line_param = NULL, *fragment = NULL, fragment_sub, __$true, __$false, __$null, _0;
	zend_string *functionName = NULL, *type = NULL, *className = NULL, *classLink = NULL, *functionLink = NULL, *file = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&functionName_zv);
	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&className_zv);
	ZVAL_UNDEF(&classLink_zv);
	ZVAL_UNDEF(&functionLink_zv);
	ZVAL_UNDEF(&file_zv);
	ZVAL_UNDEF(&fragment_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&args);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	static zend_string *_zephir_prop_7 = NULL;
	static zend_string *_zephir_prop_8 = NULL;
	static zend_string *_zephir_prop_9 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("functionName", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("type", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("className", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("classLink", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("functionLink", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("hasArgs", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("args", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_7)) {
		_zephir_prop_7 = zend_string_init("file", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_8)) {
		_zephir_prop_8 = zend_string_init("line", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_9)) {
		_zephir_prop_9 = zend_string_init("fragment", 8, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 10)
		Z_PARAM_STR(functionName)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(type)
		Z_PARAM_STR_OR_NULL(className)
		Z_PARAM_STR_OR_NULL(classLink)
		Z_PARAM_STR_OR_NULL(functionLink)
		Z_PARAM_BOOL(hasArgs)
		ZEPHIR_Z_PARAM_ARRAY(args, args_param)
		Z_PARAM_STR_OR_NULL(file)
		Z_PARAM_LONG_OR_NULL(line, is_null_true)
		Z_PARAM_ZVAL_OR_NULL(fragment)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 5) {
		hasArgs_param = ZEND_CALL_ARG(execute_data, 6);
	}
	if (ZEND_NUM_ARGS() > 6) {
		args_param = ZEND_CALL_ARG(execute_data, 7);
	}
	if (ZEND_NUM_ARGS() > 8) {
		line_param = ZEND_CALL_ARG(execute_data, 9);
	}
	if (ZEND_NUM_ARGS() > 9) {
		fragment = ZEND_CALL_ARG(execute_data, 10);
	}
	zephir_memory_observe(&functionName_zv);
	ZVAL_STR_COPY(&functionName_zv, functionName);
	if (!type) {
		ZEPHIR_INIT_VAR(&type_zv);
	} else {
		zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	}
	if (!className) {
		ZEPHIR_INIT_VAR(&className_zv);
	} else {
		zephir_memory_observe(&className_zv);
	ZVAL_STR_COPY(&className_zv, className);
	}
	if (!classLink) {
		ZEPHIR_INIT_VAR(&classLink_zv);
	} else {
		zephir_memory_observe(&classLink_zv);
	ZVAL_STR_COPY(&classLink_zv, classLink);
	}
	if (!functionLink) {
		ZEPHIR_INIT_VAR(&functionLink_zv);
	} else {
		zephir_memory_observe(&functionLink_zv);
	ZVAL_STR_COPY(&functionLink_zv, functionLink);
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
		ZEPHIR_INIT_VAR(&file_zv);
	} else {
		zephir_memory_observe(&file_zv);
	ZVAL_STR_COPY(&file_zv, file);
	}
	if (!line_param) {
		line = 0;
	} else {
		}
	if (!fragment) {
		fragment = &fragment_sub;
		fragment = &__$null;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1355, &functionName_zv);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1356, &type_zv);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1357, &className_zv);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1358, &classLink_zv);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 1359, &functionLink_zv);
	if (hasArgs) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 1360, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 1360, &__$false);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 1361, &args);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 1362, &file_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, line);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_8, 1363, &_0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 1364, fragment);
	ZEPHIR_MM_RESTORE();
}

/**
 * @phpstan-return support_debug_args
 */
PHP_METHOD(Phalcon_Support_Debug_Report_BacktraceItem, getArgs)
{

	RETURN_MEMBER_TYPED(getThis(), "args", IS_ARRAY);
}

PHP_METHOD(Phalcon_Support_Debug_Report_BacktraceItem, getClassLink)
{

	RETURN_MEMBER(getThis(), "classLink");
}

PHP_METHOD(Phalcon_Support_Debug_Report_BacktraceItem, getClassName)
{

	RETURN_MEMBER(getThis(), "className");
}

PHP_METHOD(Phalcon_Support_Debug_Report_BacktraceItem, getFile)
{

	RETURN_MEMBER(getThis(), "file");
}

/**
 * @phpstan-return support_debug_fragment|null
 */
PHP_METHOD(Phalcon_Support_Debug_Report_BacktraceItem, getFragment)
{

	RETURN_MEMBER(getThis(), "fragment");
}

PHP_METHOD(Phalcon_Support_Debug_Report_BacktraceItem, getFunctionLink)
{

	RETURN_MEMBER(getThis(), "functionLink");
}

PHP_METHOD(Phalcon_Support_Debug_Report_BacktraceItem, getFunctionName)
{

	RETURN_MEMBER_TYPED(getThis(), "functionName", IS_STRING);
}

PHP_METHOD(Phalcon_Support_Debug_Report_BacktraceItem, getLine)
{

	RETURN_MEMBER(getThis(), "line");
}

PHP_METHOD(Phalcon_Support_Debug_Report_BacktraceItem, getType)
{

	RETURN_MEMBER(getThis(), "type");
}

PHP_METHOD(Phalcon_Support_Debug_Report_BacktraceItem, hasArgs)
{

	RETURN_MEMBER(getThis(), "hasArgs");
}

