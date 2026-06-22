
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
#include "kernel/file.h"
#include "kernel/require.h"
#include "Zend/zend_closures.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * This component allows to create CLI applications using Phalcon
 */
ZEPHIR_INIT_CLASS(Phalcon_Cli_Console)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cli, Console, phalcon, cli_console, phalcon_application_abstractapplication_ce, phalcon_cli_console_method_entry, 0);

	/**
	 * @var array|string
	 */
	zend_declare_property_null(phalcon_cli_console_ce, SL("arguments"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_cli_console_ce, SL("options"), ZEND_ACC_PROTECTED);
	phalcon_cli_console_ce->create_object = zephir_init_properties_Phalcon_Cli_Console;

	return SUCCESS;
}

/**
 * Handle the whole command-line tasks
 */
PHP_METHOD(Phalcon_Cli_Console, handle)
{
	zend_bool _9, _16$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arguments_param = NULL, __$false, className, dispatcher, module, moduleName, moduleObject, path, router, task, _0, _2, _6, _7, _8, _10, _32, _33, _34, _35, _36, _40, _1$$3, _3$$4, _4$$4, _5$$4, _11$$6, _12$$9, _28$$9, _13$$10, _14$$10, _15$$10, _17$$12, _18$$12, _19$$16, _20$$13, _21$$13, _22$$13, _23$$13, _24$$19, _25$$19, _27$$18, _29$$20, _30$$20, _31$$20, _37$$22, _38$$22, _39$$22, _41$$24, _42$$24;
	zval arguments, _26$$18;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&_26$$18);
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
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_40);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_28$$9);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_19$$16);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_22$$13);
	ZVAL_UNDEF(&_23$$13);
	ZVAL_UNDEF(&_24$$19);
	ZVAL_UNDEF(&_25$$19);
	ZVAL_UNDEF(&_27$$18);
	ZVAL_UNDEF(&_29$$20);
	ZVAL_UNDEF(&_30$$20);
	ZVAL_UNDEF(&_31$$20);
	ZVAL_UNDEF(&_37$$22);
	ZVAL_UNDEF(&_38$$22);
	ZVAL_UNDEF(&_39$$22);
	ZVAL_UNDEF(&_41$$24);
	ZVAL_UNDEF(&_42$$24);
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_cli_console_exceptions_containerrequired_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 363);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Cli/Console.zep", 46);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_2) != IS_NULL) {
		zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "console:boot");
		ZEPHIR_CALL_METHOD(&_4$$4, &_3$$4, "fire", NULL, 0, &_5$$4, this_ptr);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_4$$4)) {
			RETURN_MM_BOOL(0);
		}
	}
	zephir_read_property(&_6, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "router");
	ZEPHIR_CALL_METHOD(&_7, &_6, "getshared", NULL, 0, &_8);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&router, &_7);
	_9 = !(zephir_fast_count_int(&arguments));
	if (_9) {
		zephir_read_property(&_10, this_ptr, ZEND_STRL("arguments"), PH_NOISY_CC | PH_READONLY);
		_9 = zephir_is_true(&_10);
	}
	if (_9) {
		zephir_read_property(&_11$$6, this_ptr, ZEND_STRL("arguments"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &router, "handle", NULL, 0, &_11$$6);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &router, "handle", NULL, 0, &arguments);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&moduleName, &router, "getmodulename", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&moduleName))) {
		ZEPHIR_OBS_NVAR(&moduleName);
		zephir_read_property(&moduleName, this_ptr, ZEND_STRL("defaultModule"), PH_NOISY_CC);
	}
	if (zephir_is_true(&moduleName)) {
		zephir_read_property(&_12$$9, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_12$$9) != IS_NULL) {
			zephir_read_property(&_13$$10, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_15$$10);
			ZVAL_STRING(&_15$$10, "console:beforeStartModule");
			ZEPHIR_CALL_METHOD(&_14$$10, &_13$$10, "fire", NULL, 0, &_15$$10, this_ptr, &moduleName);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_14$$10)) {
				RETURN_MM_BOOL(0);
			}
		}
		ZEPHIR_CALL_METHOD(&module, this_ptr, "getmodule", NULL, 0, &moduleName);
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
			ZEPHIR_CALL_METHOD(NULL, &_17$$12, "__construct", NULL, 364, &moduleName, &_18$$12);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_17$$12, "phalcon/Cli/Console.zep", 95);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(&module) == IS_ARRAY) {
			zephir_memory_observe(&className);
			if (!(zephir_array_isset_string_fetch(&className, &module, SL("className"), 0))) {
				ZEPHIR_INIT_NVAR(&className);
				ZVAL_STRING(&className, "Module");
			}
			zephir_memory_observe(&path);
			if (zephir_array_isset_string_fetch(&path, &module, SL("path"), 0)) {
				if (UNEXPECTED(!((zephir_file_exists(&path) == SUCCESS)))) {
					ZEPHIR_INIT_VAR(&_19$$16);
					object_init_ex(&_19$$16, phalcon_cli_console_exceptions_moduledefinitionpathnotfound_ce);
					ZEPHIR_CALL_METHOD(NULL, &_19$$16, "__construct", NULL, 365, &path);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_19$$16, "phalcon/Cli/Console.zep", 115);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(zephir_class_exists(&className, zephir_is_true(&__$false) ))) {
					if (zephir_require_once_zval(&path) == FAILURE) {
						RETURN_MM_NULL();
					}
				}
			}
			zephir_read_property(&_20$$13, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_21$$13, &_20$$13, "get", NULL, 0, &className);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&moduleObject, &_21$$13);
			zephir_read_property(&_22$$13, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &moduleObject, "registerautoloaders", NULL, 0, &_22$$13);
			zephir_check_call_status();
			zephir_read_property(&_23$$13, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &moduleObject, "registerservices", NULL, 0, &_23$$13);
			zephir_check_call_status();
		} else {
			if (UNEXPECTED(!((zephir_is_instance_of(&module, SL("Closure")))))) {
				ZEPHIR_INIT_VAR(&_24$$19);
				object_init_ex(&_24$$19, phalcon_cli_console_exceptions_invalidmoduledefinition_ce);
				ZEPHIR_INIT_VAR(&_25$$19);
				ZVAL_STRING(&_25$$19, "The module definition object must be a Closure");
				ZEPHIR_CALL_METHOD(NULL, &_24$$19, "__construct", NULL, 364, &moduleName, &_25$$19);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_24$$19, "phalcon/Cli/Console.zep", 139);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_26$$18);
			zephir_create_array(&_26$$18, 1, 0);
			zephir_memory_observe(&_27$$18);
			zephir_read_property(&_27$$18, this_ptr, ZEND_STRL("container"), PH_NOISY_CC);
			zephir_array_fast_append(&_26$$18, &_27$$18);
			ZEPHIR_INIT_NVAR(&moduleObject);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&moduleObject, &module, &_26$$18);
			zephir_check_call_status();
		}
		zephir_read_property(&_28$$9, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_28$$9) != IS_NULL) {
			zephir_read_property(&_29$$20, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_31$$20);
			ZVAL_STRING(&_31$$20, "console:afterStartModule");
			ZEPHIR_CALL_METHOD(&_30$$20, &_29$$20, "fire", NULL, 0, &_31$$20, this_ptr, &moduleObject);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_30$$20)) {
				RETURN_MM_BOOL(0);
			}
		}
	}
	zephir_read_property(&_32, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "dispatcher");
	ZEPHIR_CALL_METHOD(&_7, &_32, "getshared", NULL, 0, &_8);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&dispatcher, &_7);
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setmodulename", NULL, 0, &moduleName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, &router, "gettaskname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "settaskname", NULL, 0, &_7);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_33, &router, "getactionname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setactionname", NULL, 0, &_33);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_34, &router, "getparameters", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setparams", NULL, 0, &_34);
	zephir_check_call_status();
	zephir_read_property(&_35, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setoptions", NULL, 0, &_35);
	zephir_check_call_status();
	zephir_read_property(&_36, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_36) != IS_NULL) {
		zephir_read_property(&_37$$22, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_39$$22);
		ZVAL_STRING(&_39$$22, "console:beforeHandleTask");
		ZEPHIR_CALL_METHOD(&_38$$22, &_37$$22, "fire", NULL, 0, &_39$$22, this_ptr, &dispatcher);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_38$$22)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_CALL_METHOD(&task, &dispatcher, "dispatch", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_40, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_40) != IS_NULL) {
		zephir_read_property(&_41$$24, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_42$$24);
		ZVAL_STRING(&_42$$24, "console:afterHandleTask");
		ZEPHIR_CALL_METHOD(NULL, &_41$$24, "fire", NULL, 0, &_42$$24, this_ptr, &task);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&task);
}

/**
 * Set an specific argument
 */
PHP_METHOD(Phalcon_Cli_Console, setArgument)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool str, shift, _0, _23;
	zval *arguments_param = NULL, *str_param = NULL, *shift_param = NULL, __$true, arg, pos, args, opts, handleArgs, *_1, _22, _2$$5, _3$$5, _4$$5, _6$$6, _7$$7, _8$$7, _9$$7, _10$$7, _11$$7, _12$$7, _13$$7, _14$$8, _15$$8, _16$$8, _17$$9, _18$$9, _19$$9, _20$$10, _21$$10, _24$$14, _25$$14, _26$$14, _27$$15, _28$$16, _29$$16, _30$$16, _31$$16, _32$$16, _33$$16, _34$$16, _35$$17, _36$$17, _37$$17, _38$$18, _39$$18, _40$$18, _41$$19, _42$$19, _43$$22, _44$$22, _45$$24, _46$$25, _47$$26;
	zval arguments;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arguments);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&arg);
	ZVAL_UNDEF(&pos);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&opts);
	ZVAL_UNDEF(&handleArgs);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_24$$14);
	ZVAL_UNDEF(&_25$$14);
	ZVAL_UNDEF(&_26$$14);
	ZVAL_UNDEF(&_27$$15);
	ZVAL_UNDEF(&_28$$16);
	ZVAL_UNDEF(&_29$$16);
	ZVAL_UNDEF(&_30$$16);
	ZVAL_UNDEF(&_31$$16);
	ZVAL_UNDEF(&_32$$16);
	ZVAL_UNDEF(&_33$$16);
	ZVAL_UNDEF(&_34$$16);
	ZVAL_UNDEF(&_35$$17);
	ZVAL_UNDEF(&_36$$17);
	ZVAL_UNDEF(&_37$$17);
	ZVAL_UNDEF(&_38$$18);
	ZVAL_UNDEF(&_39$$18);
	ZVAL_UNDEF(&_40$$18);
	ZVAL_UNDEF(&_41$$19);
	ZVAL_UNDEF(&_42$$19);
	ZVAL_UNDEF(&_43$$22);
	ZVAL_UNDEF(&_44$$22);
	ZVAL_UNDEF(&_45$$24);
	ZVAL_UNDEF(&_46$$25);
	ZVAL_UNDEF(&_47$$26);
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
	ZEPHIR_OBS_COPY_OR_DUP(&arguments, arguments_param);
	}
	if (!str_param) {
		str = 1;
	} else {
	if (UNEXPECTED(Z_TYPE_P(str_param) != IS_TRUE && Z_TYPE_P(str_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'str' must be of the type bool"));
		RETURN_MM_NULL();
	}
	str = (Z_TYPE_P(str_param) == IS_TRUE);
	}
	if (!shift_param) {
		shift = 1;
	} else {
	if (UNEXPECTED(Z_TYPE_P(shift_param) != IS_TRUE && Z_TYPE_P(shift_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'shift' must be of the type bool"));
		RETURN_MM_NULL();
	}
	shift = (Z_TYPE_P(shift_param) == IS_TRUE);
	}
	ZEPHIR_INIT_VAR(&args);
	array_init(&args);
	ZEPHIR_INIT_VAR(&opts);
	array_init(&opts);
	ZEPHIR_INIT_VAR(&handleArgs);
	array_init(&handleArgs);
	_0 = shift;
	if (_0) {
		_0 = ((zephir_fast_count_int(&arguments)) ? 1 : 0);
	}
	if (_0) {
		ZEPHIR_MAKE_REF(&arguments);
		ZEPHIR_CALL_FUNCTION(NULL, "array_shift", NULL, 41, &arguments);
		ZEPHIR_UNREF(&arguments);
		zephir_check_call_status();
	}
	zephir_is_iterable(&arguments, 0, "phalcon/Cli/Console.zep", 225);
	if (Z_TYPE_P(&arguments) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&arguments), _1)
		{
			ZEPHIR_INIT_NVAR(&arg);
			ZVAL_COPY(&arg, _1);
			if (Z_TYPE_P(&arg) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_2$$5);
				ZVAL_STRING(&_2$$5, "--");
				ZVAL_LONG(&_3$$5, 2);
				ZEPHIR_CALL_FUNCTION(&_4$$5, "strncmp", &_5, 366, &arg, &_2$$5, &_3$$5);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG(&_4$$5, 0)) {
					ZEPHIR_INIT_NVAR(&_6$$6);
					ZVAL_STRING(&_6$$6, "=");
					ZEPHIR_INIT_NVAR(&pos);
					zephir_fast_strpos(&pos, &arg, &_6$$6, 0 );
					if (zephir_is_true(&pos)) {
						ZEPHIR_INIT_NVAR(&_7$$7);
						ZVAL_LONG(&_8$$7, (zephir_get_numberval(&pos) + 1));
						ZEPHIR_INIT_NVAR(&_9$$7);
						zephir_substr(&_9$$7, &arg, zephir_get_intval(&_8$$7), 0, ZEPHIR_SUBSTR_NO_LENGTH);
						zephir_fast_trim(&_7$$7, &_9$$7, NULL , ZEPHIR_TRIM_BOTH);
						ZEPHIR_INIT_NVAR(&_10$$7);
						ZVAL_LONG(&_11$$7, 2);
						ZVAL_LONG(&_12$$7, (zephir_get_numberval(&pos) - 2));
						ZEPHIR_INIT_NVAR(&_13$$7);
						zephir_substr(&_13$$7, &arg, 2 , zephir_get_intval(&_12$$7), 0);
						zephir_fast_trim(&_10$$7, &_13$$7, NULL , ZEPHIR_TRIM_BOTH);
						zephir_array_update_zval(&opts, &_10$$7, &_7$$7, PH_COPY | PH_SEPARATE);
					} else {
						ZEPHIR_INIT_NVAR(&_14$$8);
						ZVAL_LONG(&_15$$8, 2);
						ZEPHIR_INIT_NVAR(&_16$$8);
						zephir_substr(&_16$$8, &arg, 2 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
						zephir_fast_trim(&_14$$8, &_16$$8, NULL , ZEPHIR_TRIM_BOTH);
						zephir_array_update_zval(&opts, &_14$$8, &__$true, PH_COPY | PH_SEPARATE);
					}
				} else {
					ZEPHIR_INIT_NVAR(&_17$$9);
					ZVAL_STRING(&_17$$9, "-");
					ZVAL_LONG(&_18$$9, 1);
					ZEPHIR_CALL_FUNCTION(&_19$$9, "strncmp", &_5, 366, &arg, &_17$$9, &_18$$9);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG(&_19$$9, 0)) {
						ZVAL_LONG(&_20$$10, 1);
						ZEPHIR_INIT_NVAR(&_21$$10);
						zephir_substr(&_21$$10, &arg, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
						zephir_array_update_zval(&opts, &_21$$10, &__$true, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_append(&args, &arg, PH_SEPARATE, "phalcon/Cli/Console.zep", 217);
					}
				}
			} else {
				zephir_array_append(&args, &arg, PH_SEPARATE, "phalcon/Cli/Console.zep", 221);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &arguments, "rewind", NULL, 0);
		zephir_check_call_status();
		_23 = 1;
		while (1) {
			if (_23) {
				_23 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &arguments, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_22, &arguments, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_22)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&arg, &arguments, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&arg) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_24$$14);
					ZVAL_STRING(&_24$$14, "--");
					ZVAL_LONG(&_25$$14, 2);
					ZEPHIR_CALL_FUNCTION(&_26$$14, "strncmp", &_5, 366, &arg, &_24$$14, &_25$$14);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG(&_26$$14, 0)) {
						ZEPHIR_INIT_NVAR(&_27$$15);
						ZVAL_STRING(&_27$$15, "=");
						ZEPHIR_INIT_NVAR(&pos);
						zephir_fast_strpos(&pos, &arg, &_27$$15, 0 );
						if (zephir_is_true(&pos)) {
							ZEPHIR_INIT_NVAR(&_28$$16);
							ZVAL_LONG(&_29$$16, (zephir_get_numberval(&pos) + 1));
							ZEPHIR_INIT_NVAR(&_30$$16);
							zephir_substr(&_30$$16, &arg, zephir_get_intval(&_29$$16), 0, ZEPHIR_SUBSTR_NO_LENGTH);
							zephir_fast_trim(&_28$$16, &_30$$16, NULL , ZEPHIR_TRIM_BOTH);
							ZEPHIR_INIT_NVAR(&_31$$16);
							ZVAL_LONG(&_32$$16, 2);
							ZVAL_LONG(&_33$$16, (zephir_get_numberval(&pos) - 2));
							ZEPHIR_INIT_NVAR(&_34$$16);
							zephir_substr(&_34$$16, &arg, 2 , zephir_get_intval(&_33$$16), 0);
							zephir_fast_trim(&_31$$16, &_34$$16, NULL , ZEPHIR_TRIM_BOTH);
							zephir_array_update_zval(&opts, &_31$$16, &_28$$16, PH_COPY | PH_SEPARATE);
						} else {
							ZEPHIR_INIT_NVAR(&_35$$17);
							ZVAL_LONG(&_36$$17, 2);
							ZEPHIR_INIT_NVAR(&_37$$17);
							zephir_substr(&_37$$17, &arg, 2 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
							zephir_fast_trim(&_35$$17, &_37$$17, NULL , ZEPHIR_TRIM_BOTH);
							zephir_array_update_zval(&opts, &_35$$17, &__$true, PH_COPY | PH_SEPARATE);
						}
					} else {
						ZEPHIR_INIT_NVAR(&_38$$18);
						ZVAL_STRING(&_38$$18, "-");
						ZVAL_LONG(&_39$$18, 1);
						ZEPHIR_CALL_FUNCTION(&_40$$18, "strncmp", &_5, 366, &arg, &_38$$18, &_39$$18);
						zephir_check_call_status();
						if (ZEPHIR_IS_LONG(&_40$$18, 0)) {
							ZVAL_LONG(&_41$$19, 1);
							ZEPHIR_INIT_NVAR(&_42$$19);
							zephir_substr(&_42$$19, &arg, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
							zephir_array_update_zval(&opts, &_42$$19, &__$true, PH_COPY | PH_SEPARATE);
						} else {
							zephir_array_append(&args, &arg, PH_SEPARATE, "phalcon/Cli/Console.zep", 217);
						}
					}
				} else {
					zephir_array_append(&args, &arg, PH_SEPARATE, "phalcon/Cli/Console.zep", 221);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&arg);
	if (str) {
		ZEPHIR_INIT_VAR(&_43$$22);
		ZEPHIR_CALL_CE_STATIC(&_44$$22, phalcon_cli_router_route_ce, "getdelimiter", NULL, 0);
		zephir_check_call_status();
		zephir_fast_join(&_43$$22, &_44$$22, &args);
		zephir_update_property_zval(this_ptr, ZEND_STRL("arguments"), &_43$$22);
	} else {
		if (zephir_fast_count_int(&args)) {
			ZEPHIR_MAKE_REF(&args);
			ZEPHIR_CALL_FUNCTION(&_45$$24, "array_shift", NULL, 41, &args);
			ZEPHIR_UNREF(&args);
			zephir_check_call_status();
			zephir_array_update_string(&handleArgs, SL("task"), &_45$$24, PH_COPY | PH_SEPARATE);
		}
		if (zephir_fast_count_int(&args)) {
			ZEPHIR_MAKE_REF(&args);
			ZEPHIR_CALL_FUNCTION(&_46$$25, "array_shift", NULL, 41, &args);
			ZEPHIR_UNREF(&args);
			zephir_check_call_status();
			zephir_array_update_string(&handleArgs, SL("action"), &_46$$25, PH_COPY | PH_SEPARATE);
		}
		if (zephir_fast_count_int(&args)) {
			ZEPHIR_INIT_VAR(&_47$$26);
			zephir_fast_array_merge(&_47$$26, &handleArgs, &args);
			ZEPHIR_CPY_WRT(&handleArgs, &_47$$26);
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("arguments"), &handleArgs);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("options"), &opts);
	RETURN_THIS();
}

zend_object *zephir_init_properties_Phalcon_Cli_Console(zend_class_entry *class_type)
{
		zval _0, _2, _4, _1$$3, _3$$4, _5$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("options"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("modules"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("modules"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("arguments"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("arguments"), &_5$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

