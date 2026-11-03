
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/require.h"
#include "Zend/zend_closures.h"
#include "kernel/string.h"
#include "kernel/file.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * This component allows to create CLI applications using Phalcon
 *
 * @phpstan-import-type cli_arguments from CliTypes
 * @phpstan-import-type cli_options from CliTypes
 * @phpstan-import-type cli_parameters from CliTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Cli_Console)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cli, Console, phalcon, cli_console, phalcon_application_abstractapplication_ce, phalcon_cli_console_method_entry, 0);

	/**
	 * @phpstan-var cli_arguments
	 */
	zend_declare_property_null(phalcon_cli_console_ce, SL("arguments"), ZEND_ACC_PROTECTED);
	/**
	 * @phpstan-var cli_options
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_cli_console_ce, SL("options"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	phalcon_cli_console_ce->create_object = zephir_init_properties_Phalcon_Cli_Console;

	return SUCCESS;
}

/**
 * Handle the whole command-line tasks
 *
 * @phpstan-param cli_parameters|null $arguments
 */
PHP_METHOD(Phalcon_Cli_Console, handle)
{
	zend_bool _9, _16$$9, _20$$13, _21$$13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_19 = NULL, *_30 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arguments_param = NULL, __$false, className, dispatcher, module, moduleName, moduleObject, path, router, task, _0, _2, _6, _7, _8, _10, _37, _38, _39, _40, _41, _45, _1$$3, _3$$4, _4$$4, _5$$4, _11$$6, _12$$9, _33$$9, _13$$10, _14$$10, _15$$10, _17$$12, _18$$12, _24$$13, _25$$13, _26$$13, _27$$13, _22$$15, _23$$16, _28$$19, _29$$19, _32$$18, _34$$20, _35$$20, _36$$20, _42$$22, _43$$22, _44$$22, _46$$24, _47$$24;
	zval arguments, _31$$18;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&_31$$18);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&dispatcher);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&moduleName);
	ZVAL_UNDEF(&moduleObject);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&task);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_38);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_40);
	ZVAL_UNDEF(&_41);
	ZVAL_UNDEF(&_45);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_33$$9);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_24$$13);
	ZVAL_UNDEF(&_25$$13);
	ZVAL_UNDEF(&_26$$13);
	ZVAL_UNDEF(&_27$$13);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_23$$16);
	ZVAL_UNDEF(&_28$$19);
	ZVAL_UNDEF(&_29$$19);
	ZVAL_UNDEF(&_32$$18);
	ZVAL_UNDEF(&_34$$20);
	ZVAL_UNDEF(&_35$$20);
	ZVAL_UNDEF(&_36$$20);
	ZVAL_UNDEF(&_42$$22);
	ZVAL_UNDEF(&_43$$22);
	ZVAL_UNDEF(&_44$$22);
	ZVAL_UNDEF(&_46$$24);
	ZVAL_UNDEF(&_47$$24);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("eventsManager", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("arguments", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("defaultModule", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("options", 7, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY_OR_NULL(arguments, arguments_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &arguments_param);
	if (!arguments_param) {
		ZEPHIR_INIT_VAR(&arguments);
	} else {
		zephir_get_arrval(&arguments, arguments_param);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 506, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_cli_console_exceptions_containerrequired_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 455);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Cli/Console.zep", 55);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_1, 507, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_2) != IS_NULL) {
		zephir_read_property_cached(&_3$$4, this_ptr, _zephir_prop_1, 507, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "console:boot");
		ZEPHIR_CALL_METHOD(&_4$$4, &_3$$4, "fire", NULL, 0, &_5$$4, this_ptr);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_4$$4)) {
			RETURN_MM_BOOL(0);
		}
	}
	zephir_read_property_cached(&_6, this_ptr, _zephir_prop_0, 506, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "router");
	ZEPHIR_CALL_METHOD(&_7, &_6, "getShared", NULL, 0, &_8);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&router, &_7);
	_9 = ZEPHIR_IS_EMPTY(&arguments);
	if (_9) {
		zephir_read_property_cached(&_10, this_ptr, _zephir_prop_2, 508, PH_NOISY_CC | PH_READONLY);
		_9 = zephir_is_true(&_10);
	}
	if (_9) {
		zephir_read_property_cached(&_11$$6, this_ptr, _zephir_prop_2, 508, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &router, "handle", NULL, 0, &_11$$6);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &router, "handle", NULL, 0, &arguments);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&moduleName, &router, "getModuleName", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&moduleName))) {
		ZEPHIR_OBS_NVAR(&moduleName);
		zephir_read_property_cached(&moduleName, this_ptr, _zephir_prop_3, 509, PH_NOISY_CC);
	}
	if (zephir_is_true(&moduleName)) {
		zephir_read_property_cached(&_12$$9, this_ptr, _zephir_prop_1, 507, PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_12$$9) != IS_NULL) {
			zephir_read_property_cached(&_13$$10, this_ptr, _zephir_prop_1, 507, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_15$$10);
			ZVAL_STRING(&_15$$10, "console:beforeStartModule");
			ZEPHIR_CALL_METHOD(&_14$$10, &_13$$10, "fire", NULL, 0, &_15$$10, this_ptr, &moduleName);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_14$$10)) {
				RETURN_MM_BOOL(0);
			}
		}
		ZEPHIR_CALL_METHOD(&module, this_ptr, "getModule", NULL, 0, &moduleName);
		zephir_check_call_status();
		_16$$9 = Z_TYPE_P(&module) != IS_ARRAY;
		if (_16$$9) {
			_16$$9 = Z_TYPE_P(&module) != IS_OBJECT;
		}
		if (UNEXPECTED(_16$$9)) {
			ZEPHIR_INIT_VAR(&_17$$12);
			object_init_ex(&_17$$12, phalcon_cli_console_exceptions_invalidmoduledefinition_ce);
			ZEPHIR_INIT_VAR(&_18$$12);
			ZVAL_STRING(&_18$$12, "The module definition must be an array or an object");
			ZEPHIR_CALL_METHOD(NULL, &_17$$12, "__construct", &_19, 456, &moduleName, &_18$$12);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_17$$12, "phalcon/Cli/Console.zep", 104);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(&module) == IS_ARRAY) {
			zephir_memory_observe(&className);
			_20$$13 = zephir_array_isset_string_fetch(&className, &module, SL("className"), 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!(_20$$13)) {
				ZEPHIR_INIT_NVAR(&className);
				ZVAL_STRING(&className, "Module");
			}
			zephir_memory_observe(&path);
			_21$$13 = zephir_array_isset_string_fetch(&path, &module, SL("path"), 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_21$$13) {
				ZEPHIR_CALL_METHOD(&_22$$15, this_ptr, "phpFileExists", NULL, 0, &path);
				zephir_check_call_status();
				if (UNEXPECTED(!zephir_is_true(&_22$$15))) {
					ZEPHIR_INIT_VAR(&_23$$16);
					object_init_ex(&_23$$16, phalcon_cli_console_exceptions_moduledefinitionpathnotfound_ce);
					ZEPHIR_CALL_METHOD(NULL, &_23$$16, "__construct", NULL, 457, &path);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_23$$16, "phalcon/Cli/Console.zep", 124);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(zephir_class_exists(&className, zephir_is_true(&__$false) ))) {
					if (zephir_require_once_zval(&path) == FAILURE) {
						RETURN_MM_NULL();
					}
				}
			}
			zephir_read_property_cached(&_24$$13, this_ptr, _zephir_prop_0, 506, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_25$$13, &_24$$13, "get", NULL, 0, &className);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&moduleObject, &_25$$13);
			zephir_read_property_cached(&_26$$13, this_ptr, _zephir_prop_0, 506, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &moduleObject, "registerAutoloaders", NULL, 0, &_26$$13);
			zephir_check_call_status();
			zephir_read_property_cached(&_27$$13, this_ptr, _zephir_prop_0, 506, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &moduleObject, "registerServices", NULL, 0, &_27$$13);
			zephir_check_call_status();
		} else {
			if (UNEXPECTED(!((zephir_is_instance_of(&module, SL("Closure")))))) {
				ZEPHIR_INIT_VAR(&_28$$19);
				object_init_ex(&_28$$19, phalcon_cli_console_exceptions_invalidmoduledefinition_ce);
				ZEPHIR_INIT_VAR(&_29$$19);
				ZVAL_STRING(&_29$$19, "The module definition object must be a Closure");
				ZEPHIR_CALL_METHOD(NULL, &_28$$19, "__construct", &_30, 456, &moduleName, &_29$$19);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_28$$19, "phalcon/Cli/Console.zep", 148);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_31$$18);
			zephir_create_array(&_31$$18, 1, 0);
			zephir_memory_observe(&_32$$18);
			zephir_read_property_cached(&_32$$18, this_ptr, _zephir_prop_0, 506, PH_NOISY_CC);
			zephir_array_fast_append(&_31$$18, &_32$$18);
			ZEPHIR_INIT_NVAR(&moduleObject);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&moduleObject, &module, &_31$$18);
			zephir_check_call_status();
		}
		zephir_read_property_cached(&_33$$9, this_ptr, _zephir_prop_1, 507, PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_33$$9) != IS_NULL) {
			zephir_read_property_cached(&_34$$20, this_ptr, _zephir_prop_1, 507, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_36$$20);
			ZVAL_STRING(&_36$$20, "console:afterStartModule");
			ZEPHIR_CALL_METHOD(&_35$$20, &_34$$20, "fire", NULL, 0, &_36$$20, this_ptr, &moduleObject);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_35$$20)) {
				RETURN_MM_BOOL(0);
			}
		}
	}
	zephir_read_property_cached(&_37, this_ptr, _zephir_prop_0, 506, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "dispatcher");
	ZEPHIR_CALL_METHOD(&_7, &_37, "getShared", NULL, 0, &_8);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&dispatcher, &_7);
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setModuleName", NULL, 0, &moduleName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, &router, "getTaskName", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setTaskName", NULL, 0, &_7);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_38, &router, "getActionName", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setActionName", NULL, 0, &_38);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_39, &router, "getParameters", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setParams", NULL, 0, &_39);
	zephir_check_call_status();
	zephir_read_property_cached(&_40, this_ptr, _zephir_prop_4, 510, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setOptions", NULL, 0, &_40);
	zephir_check_call_status();
	zephir_read_property_cached(&_41, this_ptr, _zephir_prop_1, 507, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_41) != IS_NULL) {
		zephir_read_property_cached(&_42$$22, this_ptr, _zephir_prop_1, 507, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_44$$22);
		ZVAL_STRING(&_44$$22, "console:beforeHandleTask");
		ZEPHIR_CALL_METHOD(&_43$$22, &_42$$22, "fire", NULL, 0, &_44$$22, this_ptr, &dispatcher);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_43$$22)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_CALL_METHOD(&task, &dispatcher, "dispatch", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_45, this_ptr, _zephir_prop_1, 507, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_45) != IS_NULL) {
		zephir_read_property_cached(&_46$$24, this_ptr, _zephir_prop_1, 507, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_47$$24);
		ZVAL_STRING(&_47$$24, "console:afterHandleTask");
		ZEPHIR_CALL_METHOD(NULL, &_46$$24, "fire", NULL, 0, &_47$$24, this_ptr, &task);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&task);
}

/**
 * Set a specific argument
 *
 * @phpstan-param cli_parameters|null $arguments
 */
PHP_METHOD(Phalcon_Cli_Console, setArgument)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_6 = NULL;
	zend_bool str, shift, _0, _25;
	zval *arguments_param = NULL, *str_param = NULL, *shift_param = NULL, __$true, arg, pos, args, opts, handleArgs, *_2, _24, _3$$5, _4$$5, _5$$5, _7$$6, _8$$7, _9$$7, _10$$7, _11$$7, _12$$7, _13$$7, _14$$7, _15$$7, _16$$8, _17$$8, _18$$8, _19$$9, _20$$9, _21$$9, _22$$10, _23$$10, _26$$14, _27$$14, _28$$14, _29$$15, _30$$16, _31$$16, _32$$16, _33$$16, _34$$16, _35$$16, _36$$16, _37$$16, _38$$17, _39$$17, _40$$17, _41$$18, _42$$18, _43$$18, _44$$19, _45$$19, _46$$22, _47$$22, _48$$24, _49$$25, _50$$26;
	zval arguments;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arguments);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&arg);
	ZVAL_UNDEF(&pos);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&opts);
	ZVAL_UNDEF(&handleArgs);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_26$$14);
	ZVAL_UNDEF(&_27$$14);
	ZVAL_UNDEF(&_28$$14);
	ZVAL_UNDEF(&_29$$15);
	ZVAL_UNDEF(&_30$$16);
	ZVAL_UNDEF(&_31$$16);
	ZVAL_UNDEF(&_32$$16);
	ZVAL_UNDEF(&_33$$16);
	ZVAL_UNDEF(&_34$$16);
	ZVAL_UNDEF(&_35$$16);
	ZVAL_UNDEF(&_36$$16);
	ZVAL_UNDEF(&_37$$16);
	ZVAL_UNDEF(&_38$$17);
	ZVAL_UNDEF(&_39$$17);
	ZVAL_UNDEF(&_40$$17);
	ZVAL_UNDEF(&_41$$18);
	ZVAL_UNDEF(&_42$$18);
	ZVAL_UNDEF(&_43$$18);
	ZVAL_UNDEF(&_44$$19);
	ZVAL_UNDEF(&_45$$19);
	ZVAL_UNDEF(&_46$$22);
	ZVAL_UNDEF(&_47$$22);
	ZVAL_UNDEF(&_48$$24);
	ZVAL_UNDEF(&_49$$25);
	ZVAL_UNDEF(&_50$$26);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("arguments", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("options", 7, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY_OR_NULL(arguments, arguments_param)
		Z_PARAM_BOOL(str)
		Z_PARAM_BOOL(shift)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 3, &arguments_param, &str_param, &shift_param);
	if (!arguments_param) {
		ZEPHIR_INIT_VAR(&arguments);
	} else {
		zephir_get_arrval(&arguments, arguments_param);
	}
	if (!str_param) {
		str = 1;
	} else {
		}
	if (!shift_param) {
		shift = 1;
	} else {
		}
	ZEPHIR_INIT_VAR(&args);
	array_init(&args);
	ZEPHIR_INIT_VAR(&opts);
	array_init(&opts);
	ZEPHIR_INIT_VAR(&handleArgs);
	array_init(&handleArgs);
	_0 = shift;
	if (_0) {
		_0 = !(ZEPHIR_IS_EMPTY(&arguments));
	}
	if (_0) {
		ZEPHIR_MAKE_REF(&arguments);
		ZEPHIR_CALL_FUNCTION(NULL, "array_shift", &_1, 355, &arguments);
		ZEPHIR_UNREF(&arguments);
		zephir_check_call_status();
	}
	zephir_is_iterable(&arguments, 0, "phalcon/Cli/Console.zep", 239);
	if (Z_TYPE_P(&arguments) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&arguments), _2)
		{
			ZEPHIR_INIT_NVAR(&arg);
			ZVAL_COPY(&arg, _2);
			if (Z_TYPE_P(&arg) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_3$$5);
				ZVAL_STRING(&_3$$5, "--");
				ZVAL_LONG(&_4$$5, 2);
				ZEPHIR_CALL_FUNCTION(&_5$$5, "strncmp", &_6, 356, &arg, &_3$$5, &_4$$5);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG(&_5$$5, 0)) {
					ZEPHIR_INIT_NVAR(&_7$$6);
					ZVAL_STRING(&_7$$6, "=");
					ZEPHIR_INIT_NVAR(&pos);
					zephir_fast_strpos(&pos, &arg, &_7$$6, 0 );
					if (zephir_is_true(&pos)) {
						ZEPHIR_INIT_NVAR(&_8$$7);
						ZEPHIR_INIT_NVAR(&_9$$7);
						ZVAL_LONG(&_9$$7, 2);
						ZEPHIR_INIT_NVAR(&_10$$7);
						zephir_sub_function(&_10$$7, &pos, &_9$$7);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZVAL_LONG(&_11$$7, 2);
						ZEPHIR_INIT_NVAR(&_12$$7);
						zephir_substr(&_12$$7, &arg, 2 , zephir_get_intval(&_10$$7), 0);
						zephir_fast_trim(&_8$$7, &_12$$7, NULL , ZEPHIR_TRIM_BOTH);
						ZEPHIR_INIT_NVAR(&_13$$7);
						ZEPHIR_INIT_NVAR(&_9$$7);
						ZVAL_LONG(&_9$$7, 1);
						ZEPHIR_INIT_NVAR(&_14$$7);
						zephir_add_function(&_14$$7, &pos, &_9$$7);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_INIT_NVAR(&_15$$7);
						zephir_substr(&_15$$7, &arg, zephir_get_intval(&_14$$7), 0, ZEPHIR_SUBSTR_NO_LENGTH);
						zephir_fast_trim(&_13$$7, &_15$$7, NULL , ZEPHIR_TRIM_BOTH);
						zephir_array_update_zval(&opts, &_8$$7, &_13$$7, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_INIT_NVAR(&_16$$8);
						ZVAL_LONG(&_17$$8, 2);
						ZEPHIR_INIT_NVAR(&_18$$8);
						zephir_substr(&_18$$8, &arg, 2 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
						zephir_fast_trim(&_16$$8, &_18$$8, NULL , ZEPHIR_TRIM_BOTH);
						zephir_array_update_zval(&opts, &_16$$8, &__$true, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				} else {
					ZEPHIR_INIT_NVAR(&_19$$9);
					ZVAL_STRING(&_19$$9, "-");
					ZVAL_LONG(&_20$$9, 1);
					ZEPHIR_CALL_FUNCTION(&_21$$9, "strncmp", &_6, 356, &arg, &_19$$9, &_20$$9);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG(&_21$$9, 0)) {
						ZVAL_LONG(&_22$$10, 1);
						ZEPHIR_INIT_NVAR(&_23$$10);
						zephir_substr(&_23$$10, &arg, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
						zephir_array_update_zval(&opts, &_23$$10, &__$true, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						zephir_array_append(&args, &arg, PH_SEPARATE, "phalcon/Cli/Console.zep", 231);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				}
			} else {
				zephir_array_append(&args, &arg, PH_SEPARATE, "phalcon/Cli/Console.zep", 235);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &arguments, "rewind", NULL, 0);
		zephir_check_call_status();
		_25 = 1;
		while (1) {
			if (_25) {
				_25 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &arguments, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_24, &arguments, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_24)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&arg, &arguments, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&arg) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_26$$14);
					ZVAL_STRING(&_26$$14, "--");
					ZVAL_LONG(&_27$$14, 2);
					ZEPHIR_CALL_FUNCTION(&_28$$14, "strncmp", &_6, 356, &arg, &_26$$14, &_27$$14);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG(&_28$$14, 0)) {
						ZEPHIR_INIT_NVAR(&_29$$15);
						ZVAL_STRING(&_29$$15, "=");
						ZEPHIR_INIT_NVAR(&pos);
						zephir_fast_strpos(&pos, &arg, &_29$$15, 0 );
						if (zephir_is_true(&pos)) {
							ZEPHIR_INIT_NVAR(&_30$$16);
							ZEPHIR_INIT_NVAR(&_31$$16);
							ZVAL_LONG(&_31$$16, 2);
							ZEPHIR_INIT_NVAR(&_32$$16);
							zephir_sub_function(&_32$$16, &pos, &_31$$16);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZVAL_LONG(&_33$$16, 2);
							ZEPHIR_INIT_NVAR(&_34$$16);
							zephir_substr(&_34$$16, &arg, 2 , zephir_get_intval(&_32$$16), 0);
							zephir_fast_trim(&_30$$16, &_34$$16, NULL , ZEPHIR_TRIM_BOTH);
							ZEPHIR_INIT_NVAR(&_35$$16);
							ZEPHIR_INIT_NVAR(&_31$$16);
							ZVAL_LONG(&_31$$16, 1);
							ZEPHIR_INIT_NVAR(&_36$$16);
							zephir_add_function(&_36$$16, &pos, &_31$$16);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_INIT_NVAR(&_37$$16);
							zephir_substr(&_37$$16, &arg, zephir_get_intval(&_36$$16), 0, ZEPHIR_SUBSTR_NO_LENGTH);
							zephir_fast_trim(&_35$$16, &_37$$16, NULL , ZEPHIR_TRIM_BOTH);
							zephir_array_update_zval(&opts, &_30$$16, &_35$$16, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} else {
							ZEPHIR_INIT_NVAR(&_38$$17);
							ZVAL_LONG(&_39$$17, 2);
							ZEPHIR_INIT_NVAR(&_40$$17);
							zephir_substr(&_40$$17, &arg, 2 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
							zephir_fast_trim(&_38$$17, &_40$$17, NULL , ZEPHIR_TRIM_BOTH);
							zephir_array_update_zval(&opts, &_38$$17, &__$true, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					} else {
						ZEPHIR_INIT_NVAR(&_41$$18);
						ZVAL_STRING(&_41$$18, "-");
						ZVAL_LONG(&_42$$18, 1);
						ZEPHIR_CALL_FUNCTION(&_43$$18, "strncmp", &_6, 356, &arg, &_41$$18, &_42$$18);
						zephir_check_call_status();
						if (ZEPHIR_IS_LONG(&_43$$18, 0)) {
							ZVAL_LONG(&_44$$19, 1);
							ZEPHIR_INIT_NVAR(&_45$$19);
							zephir_substr(&_45$$19, &arg, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
							zephir_array_update_zval(&opts, &_45$$19, &__$true, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} else {
							zephir_array_append(&args, &arg, PH_SEPARATE, "phalcon/Cli/Console.zep", 231);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					}
				} else {
					zephir_array_append(&args, &arg, PH_SEPARATE, "phalcon/Cli/Console.zep", 235);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&arg);
	if (str) {
		ZEPHIR_INIT_VAR(&_46$$22);
		ZEPHIR_CALL_CE_STATIC(&_47$$22, phalcon_cli_router_route_ce, "getDelimiter", NULL, 0);
		zephir_check_call_status();
		zephir_fast_join(&_46$$22, &_47$$22, &args);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 508, &_46$$22);
	} else {
		if (!(ZEPHIR_IS_EMPTY(&args))) {
			ZEPHIR_MAKE_REF(&args);
			ZEPHIR_CALL_FUNCTION(&_48$$24, "array_shift", &_1, 355, &args);
			ZEPHIR_UNREF(&args);
			zephir_check_call_status();
			zephir_array_update_string(&handleArgs, SL("task"), &_48$$24, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		if (!(ZEPHIR_IS_EMPTY(&args))) {
			ZEPHIR_MAKE_REF(&args);
			ZEPHIR_CALL_FUNCTION(&_49$$25, "array_shift", &_1, 355, &args);
			ZEPHIR_UNREF(&args);
			zephir_check_call_status();
			zephir_array_update_string(&handleArgs, SL("action"), &_49$$25, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		if (!(ZEPHIR_IS_EMPTY(&args))) {
			ZEPHIR_INIT_VAR(&_50$$26);
			zephir_fast_array_merge(&_50$$26, &handleArgs, &args);
			ZEPHIR_CPY_WRT(&handleArgs, &_50$$26);
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 508, &handleArgs);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 510, &opts);
	RETURN_THIS();
}

/**
 * Closes an open file pointer
 *
 * @link https://php.net/manual/en/function.fclose.php
 *
 * @param resource $handle
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Cli_Console, phpFclose)
{
	zval *handle, handle_sub;

	ZVAL_UNDEF(&handle_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle);
	RETURN_BOOL(zephir_fclose(handle));
}

/**
 * Gets line from file pointer and parse for CSV fields
 *
 * @param resource $stream
 * @param int      $length
 * @param string   $separator
 * @param string   $enclosure
 * @param string   $escape
 *
 * @return array<array-key, mixed>|false
 *
 * @link https://php.net/manual/en/function.fgetcsv.php
 */
PHP_METHOD(Phalcon_Cli_Console, phpFgetCsv)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_string *separator = NULL;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zval *stream, stream_sub, *length_param = NULL, separator_zv, *enclosure = NULL, enclosure_sub, *escape = NULL, escape_sub, __$null, _0;

	ZVAL_UNDEF(&stream_sub);
	ZVAL_UNDEF(&separator_zv);
	ZVAL_UNDEF(&enclosure_sub);
	ZVAL_UNDEF(&escape_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 5)
		Z_PARAM_ZVAL(stream)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(length)
		Z_PARAM_STR(separator)
		Z_PARAM_ZVAL_OR_NULL(enclosure)
		Z_PARAM_ZVAL_OR_NULL(escape)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	stream = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 1) {
		length_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 3) {
		enclosure = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		escape = ZEND_CALL_ARG(execute_data, 5);
	}
	if (!length_param) {
		length = 0;
	} else {
		}
	if (!separator) {
		separator = zend_string_init(ZEND_STRL(","), 0);
		zephir_memory_observe(&separator_zv);
		ZVAL_STR(&separator_zv, separator);
	} else {
		zephir_memory_observe(&separator_zv);
	ZVAL_STR_COPY(&separator_zv, separator);
	}
	if (!enclosure) {
		enclosure = &enclosure_sub;
		ZEPHIR_CPY_WRT(enclosure, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(enclosure);
	}
	if (!escape) {
		escape = &escape_sub;
		ZEPHIR_CPY_WRT(escape, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(escape);
	}
	if (Z_TYPE_P(enclosure) == IS_NULL) {
		ZEPHIR_INIT_NVAR(enclosure);
		ZVAL_STRING(enclosure, "\"");
	}
	if (Z_TYPE_P(escape) == IS_NULL) {
		ZEPHIR_INIT_NVAR(escape);
		ZVAL_STRING(escape, "\\");
	}
	ZVAL_LONG(&_0, length);
	ZEPHIR_RETURN_CALL_FUNCTION("fgetcsv", NULL, 160, stream, &_0, &separator_zv, enclosure, escape);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $filename
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.file-exists.php
 */
PHP_METHOD(Phalcon_Cli_Console, phpFileExists)
{
	zval filename_zv;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&filename_zv, filename);
	RETURN_BOOL((zephir_file_exists(&filename_zv) == SUCCESS));
}

/**
 * @param string        $filename
 * @param bool          $useIncludePath
 * @param resource|null $context
 * @param int           $offset
 * @param int|null      $length
 *
 * @return false|string
 *
 * @link https://php.net/manual/en/function.file-get-contents.php
 */
PHP_METHOD(Phalcon_Cli_Console, phpFileGetContents)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long offset, length, ZEPHIR_LAST_CALL_STATUS;
	zend_bool useIncludePath;
	zval filename_zv, *useIncludePath_param = NULL, *context = NULL, context_sub, *offset_param = NULL, *length_param = NULL, __$null, _0$$3, _1$$3, _3, _4, _5;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 5)
		Z_PARAM_STR(filename)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(useIncludePath)
		Z_PARAM_ZVAL_OR_NULL(context)
		Z_PARAM_LONG(offset)
		Z_PARAM_LONG_OR_NULL(length, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		useIncludePath_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		context = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		offset_param = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		length_param = ZEND_CALL_ARG(execute_data, 5);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!useIncludePath_param) {
		useIncludePath = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	if (!offset_param) {
		offset = 0;
	} else {
		}
	if (!length_param) {
		length = 0;
	} else {
		}
	if (0 == length) {
		ZVAL_BOOL(&_0$$3, (useIncludePath ? 1 : 0));
		ZVAL_LONG(&_1$$3, offset);
		ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", &_2, 161, &filename_zv, &_0$$3, context, &_1$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZVAL_BOOL(&_3, (useIncludePath ? 1 : 0));
	ZVAL_LONG(&_4, offset);
	ZVAL_LONG(&_5, length);
	ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", &_2, 161, &filename_zv, &_3, context, &_4, &_5);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string   $filename
 * @param mixed    $data
 * @param int      $flags
 * @param resource $context
 *
 * @return false|int
 *
 * @link https://php.net/manual/en/function.file-put-contents.php
 */
PHP_METHOD(Phalcon_Cli_Console, phpFilePutContents)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long flags, ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv, *data, data_sub, *flags_param = NULL, *context = NULL, context_sub, __$null, _0;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(filename)
		Z_PARAM_ZVAL(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(flags)
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	data = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		flags_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		context = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!flags_param) {
		flags = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZVAL_LONG(&_0, flags);
	ZEPHIR_RETURN_CALL_FUNCTION("file_put_contents", NULL, 162, &filename_zv, data, &_0, context);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string        $filename
 * @param string        $mode
 * @param bool          $useIncludePath
 * @param resource|null $context
 *
 * @return resource|false
 *
 * @link https://php.net/manual/en/function.fopen.php
 */
PHP_METHOD(Phalcon_Cli_Console, phpFopen)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool useIncludePath;
	zval filename_zv, mode_zv, *useIncludePath_param = NULL, *context = NULL, context_sub, __$null, _0;
	zend_string *filename = NULL, *mode = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&mode_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(filename)
		Z_PARAM_STR(mode)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(useIncludePath)
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		useIncludePath_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		context = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	zephir_memory_observe(&mode_zv);
	ZVAL_STR_COPY(&mode_zv, mode);
	if (!useIncludePath_param) {
		useIncludePath = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZVAL_BOOL(&_0, (useIncludePath ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("fopen", NULL, 163, &filename_zv, &mode_zv, &_0, context);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Binary-safe file write
 *
 * @link https://php.net/manual/en/function.fwrite.php
 *
 * @param resource $handle
 * @param string   $data
 * @param int|null $length
 *
 * @return false|int
 */
PHP_METHOD(Phalcon_Cli_Console, phpFwrite)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zend_string *data = NULL;
	zval *handle, handle_sub, data_zv, *length_param = NULL, _0;

	ZVAL_UNDEF(&handle_sub);
	ZVAL_UNDEF(&data_zv);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(handle)
		Z_PARAM_STR(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG_OR_NULL(length, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	handle = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		length_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&data_zv);
	ZVAL_STR_COPY(&data_zv, data);
	if (!length_param) {
		length = 0;
	} else {
		}
	if (0 == length) {
		zephir_fwrite(return_value, handle, &data_zv);
		RETURN_MM();
	}
	ZVAL_LONG(&_0, length);
	ZEPHIR_RETURN_CALL_FUNCTION("fwrite", &_1, 164, handle, &data_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Tells whether the filename is a directory
 *
 * @param string $filename
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.is-dir.php
 */
PHP_METHOD(Phalcon_Cli_Console, phpIsDir)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	ZEPHIR_RETURN_CALL_FUNCTION("is_dir", NULL, 165, &filename_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Tells whether the filename is writable
 *
 * @param string $filename
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.is-writable.php
 */
PHP_METHOD(Phalcon_Cli_Console, phpIsWritable)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	ZEPHIR_RETURN_CALL_FUNCTION("is_writable", NULL, 166, &filename_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Makes a directory
 *
 * @param string        $directory
 * @param int           $permissions
 * @param bool          $recursive
 * @param resource|null $context
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.mkdir.php
 */
PHP_METHOD(Phalcon_Cli_Console, phpMkdir)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool recursive;
	zend_long permissions, ZEPHIR_LAST_CALL_STATUS;
	zval directory_zv, *permissions_param = NULL, *recursive_param = NULL, *context = NULL, context_sub, __$null, _0, _1;
	zend_string *directory = NULL;

	ZVAL_UNDEF(&directory_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(directory)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(permissions)
		Z_PARAM_BOOL(recursive)
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		permissions_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		recursive_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		context = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&directory_zv);
	ZVAL_STR_COPY(&directory_zv, directory);
	if (!permissions_param) {
		permissions = 0777;
	} else {
		}
	if (!recursive_param) {
		recursive = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZVAL_LONG(&_0, permissions);
	ZVAL_BOOL(&_1, (recursive ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("mkdir", NULL, 167, &directory_zv, &_0, &_1, context);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string        $filename
 * @param resource|null $context
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.unlink.php
 */
PHP_METHOD(Phalcon_Cli_Console, phpUnlink)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv, *context = NULL, context_sub, __$null;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(filename)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		context = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZEPHIR_RETURN_CALL_FUNCTION("unlink", NULL, 168, &filename_zv, context);
	zephir_check_call_status();
	RETURN_MM();
}

zend_object *zephir_init_properties_Phalcon_Cli_Console(zend_class_entry *class_type)
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
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("arguments"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("arguments"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

