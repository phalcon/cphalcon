
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/require.h"
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
ZEPHIR_INIT_CLASS(Phalcon_Cli_Console) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cli, Console, phalcon, cli_console, phalcon_application_abstractapplication_ce, phalcon_cli_console_method_entry, 0);

	/**
	 * @var array
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
PHP_METHOD(Phalcon_Cli_Console, handle) {

	zend_bool _9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *arguments_param = NULL, __$false, className, container, dispatcher, eventsManager, module, moduleName, moduleObject, modules, path, router, task, _0, _7, _8, _20, _21, _22, _23, _1$$3, _2$$3, _4$$3, _5$$4, _6$$4, _10$$6, _11$$10, _12$$10, _13$$9, _14$$12, _15$$12, _16$$16, _17$$16, _18$$18, _19$$18, _24$$20, _25$$20, _26$$22;
	zval arguments;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arguments);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&dispatcher);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&moduleName);
	ZVAL_UNDEF(&moduleObject);
	ZVAL_UNDEF(&modules);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&task);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$12);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_16$$16);
	ZVAL_UNDEF(&_17$$16);
	ZVAL_UNDEF(&_18$$18);
	ZVAL_UNDEF(&_19$$18);
	ZVAL_UNDEF(&_24$$20);
	ZVAL_UNDEF(&_25$$20);
	ZVAL_UNDEF(&_26$$22);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arguments_param);

	if (!arguments_param) {
		ZEPHIR_INIT_VAR(&arguments);
		array_init(&arguments);
	} else {
		zephir_get_arrval(&arguments, arguments_param);
	}


	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_cli_console_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "internal services");
		ZEPHIR_CALL_CE_STATIC(&_2$$3, phalcon_cli_console_exception_ce, "containerservicenotfound", &_3, 0, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 8, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Cli/Console.zep", 47);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_0, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_0);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_6$$4);
		ZVAL_STRING(&_6$$4, "console:boot");
		ZEPHIR_CALL_METHOD(&_5$$4, &eventsManager, "fire", NULL, 0, &_6$$4, this_ptr);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_5$$4)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "router");
	ZEPHIR_CALL_METHOD(&_7, &container, "getshared", NULL, 0, &_8);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&router, &_7);
	_9 = !(zephir_fast_count_int(&arguments));
	if (_9) {
		zephir_read_property(&_0, this_ptr, SL("arguments"), PH_NOISY_CC | PH_READONLY);
		_9 = zephir_is_true(&_0);
	}
	if (_9) {
		zephir_read_property(&_10$$6, this_ptr, SL("arguments"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &router, "handle", NULL, 0, &_10$$6);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &router, "handle", NULL, 0, &arguments);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&moduleName, &router, "getmodulename", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&moduleName))) {
		ZEPHIR_OBS_NVAR(&moduleName);
		zephir_read_property(&moduleName, this_ptr, SL("defaultModule"), PH_NOISY_CC);
	}
	if (zephir_is_true(&moduleName)) {
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_12$$10);
			ZVAL_STRING(&_12$$10, "console:beforeStartModule");
			ZEPHIR_CALL_METHOD(&_11$$10, &eventsManager, "fire", NULL, 0, &_12$$10, this_ptr, &moduleName);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_11$$10)) {
				RETURN_MM_BOOL(0);
			}
		}
		zephir_read_property(&_13$$9, this_ptr, SL("modules"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&modules, &_13$$9);
		if (UNEXPECTED(!(zephir_array_isset(&modules, &moduleName)))) {
			ZEPHIR_INIT_VAR(&_14$$12);
			object_init_ex(&_14$$12, phalcon_cli_console_exception_ce);
			ZEPHIR_INIT_VAR(&_15$$12);
			ZEPHIR_CONCAT_SVS(&_15$$12, "Module '", &moduleName, "' isn't registered in the console container");
			ZEPHIR_CALL_METHOD(NULL, &_14$$12, "__construct", NULL, 8, &_15$$12);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_14$$12, "phalcon/Cli/Console.zep", 91);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_VAR(&module);
		zephir_array_fetch(&module, &modules, &moduleName, PH_NOISY, "phalcon/Cli/Console.zep", 94);
		if (UNEXPECTED(Z_TYPE_P(&module) != IS_ARRAY)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cli_console_exception_ce, "Invalid module definition path", "phalcon/Cli/Console.zep", 97);
			return;
		}
		ZEPHIR_OBS_VAR(&className);
		if (!(zephir_array_isset_string_fetch(&className, &module, SL("className"), 0))) {
			ZEPHIR_INIT_NVAR(&className);
			ZVAL_STRING(&className, "Module");
		}
		ZEPHIR_OBS_VAR(&path);
		if (zephir_array_isset_string_fetch(&path, &module, SL("path"), 0)) {
			if (UNEXPECTED(!((zephir_file_exists(&path) == SUCCESS)))) {
				ZEPHIR_INIT_VAR(&_16$$16);
				object_init_ex(&_16$$16, phalcon_cli_console_exception_ce);
				ZEPHIR_INIT_VAR(&_17$$16);
				ZEPHIR_CONCAT_SVS(&_17$$16, "Module definition path '", &path, "' doesn't exist");
				ZEPHIR_CALL_METHOD(NULL, &_16$$16, "__construct", NULL, 8, &_17$$16);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_16$$16, "phalcon/Cli/Console.zep", 108);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!(zephir_class_exists(&className, zephir_is_true(&__$false) ))) {
				if (zephir_require_zval(&path) == FAILURE) {
					RETURN_MM_NULL();
				}
			}
		}
		ZEPHIR_CALL_METHOD(&moduleObject, &container, "get", NULL, 0, &className);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &moduleObject, "registerautoloaders", NULL, 0, &container);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &moduleObject, "registerservices", NULL, 0, &container);
		zephir_check_call_status();
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_19$$18);
			ZVAL_STRING(&_19$$18, "console:afterStartModule");
			ZEPHIR_CALL_METHOD(&_18$$18, &eventsManager, "fire", NULL, 0, &_19$$18, this_ptr, &moduleObject);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_18$$18)) {
				RETURN_MM_BOOL(0);
			}
		}
	}
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "dispatcher");
	ZEPHIR_CALL_METHOD(&_7, &container, "getshared", NULL, 0, &_8);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&dispatcher, &_7);
	ZEPHIR_CALL_METHOD(&_7, &router, "getmodulename", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setmodulename", NULL, 0, &_7);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_20, &router, "gettaskname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "settaskname", NULL, 0, &_20);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_21, &router, "getactionname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setactionname", NULL, 0, &_21);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_22, &router, "getparams", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setparams", NULL, 0, &_22);
	zephir_check_call_status();
	zephir_read_property(&_23, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setoptions", NULL, 0, &_23);
	zephir_check_call_status();
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_25$$20);
		ZVAL_STRING(&_25$$20, "console:beforeHandleTask");
		ZEPHIR_CALL_METHOD(&_24$$20, &eventsManager, "fire", NULL, 0, &_25$$20, this_ptr, &dispatcher);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_24$$20)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_CALL_METHOD(&task, &dispatcher, "dispatch", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_26$$22);
		ZVAL_STRING(&_26$$22, "console:afterHandleTask");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_26$$22, this_ptr, &task);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&task);

}

/**
 * Set an specific argument
 */
PHP_METHOD(Phalcon_Cli_Console, setArgument) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_44 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool str, shift, _0;
	zval *arguments_param = NULL, *str_param = NULL, *shift_param = NULL, __$true, arg, pos, args, opts, handleArgs, *_1, _2, _3$$5, _4$$5, _5$$5, _7$$6, _8$$7, _9$$7, _10$$7, _11$$7, _12$$7, _13$$7, _14$$7, _15$$8, _16$$8, _17$$8, _18$$9, _19$$9, _20$$9, _21$$10, _22$$10, _23$$14, _24$$14, _25$$14, _26$$15, _27$$16, _28$$16, _29$$16, _30$$16, _31$$16, _32$$16, _33$$16, _34$$17, _35$$17, _36$$17, _37$$18, _38$$18, _39$$18, _40$$19, _41$$19, _42$$22, _43$$22, _45$$24, _46$$25, _47$$26;
	zval arguments;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arguments);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&arg);
	ZVAL_UNDEF(&pos);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&opts);
	ZVAL_UNDEF(&handleArgs);
	ZVAL_UNDEF(&_2);
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
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&_23$$14);
	ZVAL_UNDEF(&_24$$14);
	ZVAL_UNDEF(&_25$$14);
	ZVAL_UNDEF(&_26$$15);
	ZVAL_UNDEF(&_27$$16);
	ZVAL_UNDEF(&_28$$16);
	ZVAL_UNDEF(&_29$$16);
	ZVAL_UNDEF(&_30$$16);
	ZVAL_UNDEF(&_31$$16);
	ZVAL_UNDEF(&_32$$16);
	ZVAL_UNDEF(&_33$$16);
	ZVAL_UNDEF(&_34$$17);
	ZVAL_UNDEF(&_35$$17);
	ZVAL_UNDEF(&_36$$17);
	ZVAL_UNDEF(&_37$$18);
	ZVAL_UNDEF(&_38$$18);
	ZVAL_UNDEF(&_39$$18);
	ZVAL_UNDEF(&_40$$19);
	ZVAL_UNDEF(&_41$$19);
	ZVAL_UNDEF(&_42$$22);
	ZVAL_UNDEF(&_43$$22);
	ZVAL_UNDEF(&_45$$24);
	ZVAL_UNDEF(&_46$$25);
	ZVAL_UNDEF(&_47$$26);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &arguments_param, &str_param, &shift_param);

	if (!arguments_param) {
		ZEPHIR_INIT_VAR(&arguments);
		array_init(&arguments);
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
		ZEPHIR_CALL_FUNCTION(NULL, "array_shift", NULL, 24, &arguments);
		ZEPHIR_UNREF(&arguments);
		zephir_check_call_status();
	}
	zephir_is_iterable(&arguments, 0, "phalcon/Cli/Console.zep", 189);
	if (Z_TYPE_P(&arguments) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&arguments), _1)
		{
			ZEPHIR_INIT_NVAR(&arg);
			ZVAL_COPY(&arg, _1);
			if (Z_TYPE_P(&arg) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_3$$5);
				ZVAL_STRING(&_3$$5, "--");
				ZVAL_LONG(&_4$$5, 2);
				ZEPHIR_CALL_FUNCTION(&_5$$5, "strncmp", &_6, 169, &arg, &_3$$5, &_4$$5);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG(&_5$$5, 0)) {
					ZEPHIR_INIT_NVAR(&_7$$6);
					ZVAL_STRING(&_7$$6, "=");
					ZEPHIR_INIT_NVAR(&pos);
					zephir_fast_strpos(&pos, &arg, &_7$$6, 0 );
					if (zephir_is_true(&pos)) {
						ZEPHIR_INIT_NVAR(&_8$$7);
						ZVAL_LONG(&_9$$7, (zephir_get_numberval(&pos) + 1));
						ZEPHIR_INIT_NVAR(&_10$$7);
						zephir_substr(&_10$$7, &arg, zephir_get_intval(&_9$$7), 0, ZEPHIR_SUBSTR_NO_LENGTH);
						zephir_fast_trim(&_8$$7, &_10$$7, NULL , ZEPHIR_TRIM_BOTH);
						ZEPHIR_INIT_NVAR(&_11$$7);
						ZVAL_LONG(&_12$$7, 2);
						ZVAL_LONG(&_13$$7, (zephir_get_numberval(&pos) - 2));
						ZEPHIR_INIT_NVAR(&_14$$7);
						zephir_substr(&_14$$7, &arg, 2 , zephir_get_intval(&_13$$7), 0);
						zephir_fast_trim(&_11$$7, &_14$$7, NULL , ZEPHIR_TRIM_BOTH);
						zephir_array_update_zval(&opts, &_11$$7, &_8$$7, PH_COPY | PH_SEPARATE);
					} else {
						ZEPHIR_INIT_NVAR(&_15$$8);
						ZVAL_LONG(&_16$$8, 2);
						ZEPHIR_INIT_NVAR(&_17$$8);
						zephir_substr(&_17$$8, &arg, 2 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
						zephir_fast_trim(&_15$$8, &_17$$8, NULL , ZEPHIR_TRIM_BOTH);
						zephir_array_update_zval(&opts, &_15$$8, &__$true, PH_COPY | PH_SEPARATE);
					}
				} else {
					ZEPHIR_INIT_NVAR(&_18$$9);
					ZVAL_STRING(&_18$$9, "-");
					ZVAL_LONG(&_19$$9, 1);
					ZEPHIR_CALL_FUNCTION(&_20$$9, "strncmp", &_6, 169, &arg, &_18$$9, &_19$$9);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG(&_20$$9, 0)) {
						ZVAL_LONG(&_21$$10, 1);
						ZEPHIR_INIT_NVAR(&_22$$10);
						zephir_substr(&_22$$10, &arg, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
						zephir_array_update_zval(&opts, &_22$$10, &__$true, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_append(&args, &arg, PH_SEPARATE, "phalcon/Cli/Console.zep", 181);
					}
				}
			} else {
				zephir_array_append(&args, &arg, PH_SEPARATE, "phalcon/Cli/Console.zep", 185);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &arguments, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &arguments, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&arg, &arguments, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&arg) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_23$$14);
					ZVAL_STRING(&_23$$14, "--");
					ZVAL_LONG(&_24$$14, 2);
					ZEPHIR_CALL_FUNCTION(&_25$$14, "strncmp", &_6, 169, &arg, &_23$$14, &_24$$14);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG(&_25$$14, 0)) {
						ZEPHIR_INIT_NVAR(&_26$$15);
						ZVAL_STRING(&_26$$15, "=");
						ZEPHIR_INIT_NVAR(&pos);
						zephir_fast_strpos(&pos, &arg, &_26$$15, 0 );
						if (zephir_is_true(&pos)) {
							ZEPHIR_INIT_NVAR(&_27$$16);
							ZVAL_LONG(&_28$$16, (zephir_get_numberval(&pos) + 1));
							ZEPHIR_INIT_NVAR(&_29$$16);
							zephir_substr(&_29$$16, &arg, zephir_get_intval(&_28$$16), 0, ZEPHIR_SUBSTR_NO_LENGTH);
							zephir_fast_trim(&_27$$16, &_29$$16, NULL , ZEPHIR_TRIM_BOTH);
							ZEPHIR_INIT_NVAR(&_30$$16);
							ZVAL_LONG(&_31$$16, 2);
							ZVAL_LONG(&_32$$16, (zephir_get_numberval(&pos) - 2));
							ZEPHIR_INIT_NVAR(&_33$$16);
							zephir_substr(&_33$$16, &arg, 2 , zephir_get_intval(&_32$$16), 0);
							zephir_fast_trim(&_30$$16, &_33$$16, NULL , ZEPHIR_TRIM_BOTH);
							zephir_array_update_zval(&opts, &_30$$16, &_27$$16, PH_COPY | PH_SEPARATE);
						} else {
							ZEPHIR_INIT_NVAR(&_34$$17);
							ZVAL_LONG(&_35$$17, 2);
							ZEPHIR_INIT_NVAR(&_36$$17);
							zephir_substr(&_36$$17, &arg, 2 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
							zephir_fast_trim(&_34$$17, &_36$$17, NULL , ZEPHIR_TRIM_BOTH);
							zephir_array_update_zval(&opts, &_34$$17, &__$true, PH_COPY | PH_SEPARATE);
						}
					} else {
						ZEPHIR_INIT_NVAR(&_37$$18);
						ZVAL_STRING(&_37$$18, "-");
						ZVAL_LONG(&_38$$18, 1);
						ZEPHIR_CALL_FUNCTION(&_39$$18, "strncmp", &_6, 169, &arg, &_37$$18, &_38$$18);
						zephir_check_call_status();
						if (ZEPHIR_IS_LONG(&_39$$18, 0)) {
							ZVAL_LONG(&_40$$19, 1);
							ZEPHIR_INIT_NVAR(&_41$$19);
							zephir_substr(&_41$$19, &arg, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
							zephir_array_update_zval(&opts, &_41$$19, &__$true, PH_COPY | PH_SEPARATE);
						} else {
							zephir_array_append(&args, &arg, PH_SEPARATE, "phalcon/Cli/Console.zep", 181);
						}
					}
				} else {
					zephir_array_append(&args, &arg, PH_SEPARATE, "phalcon/Cli/Console.zep", 185);
				}
			ZEPHIR_CALL_METHOD(NULL, &arguments, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&arg);
	if (str) {
		ZEPHIR_INIT_VAR(&_42$$22);
		ZEPHIR_CALL_CE_STATIC(&_43$$22, phalcon_cli_router_route_ce, "getdelimiter", &_44, 0);
		zephir_check_call_status();
		zephir_fast_join(&_42$$22, &_43$$22, &args);
		zephir_update_property_zval(this_ptr, SL("arguments"), &_42$$22);
	} else {
		if (zephir_fast_count_int(&args)) {
			ZEPHIR_MAKE_REF(&args);
			ZEPHIR_CALL_FUNCTION(&_45$$24, "array_shift", NULL, 24, &args);
			ZEPHIR_UNREF(&args);
			zephir_check_call_status();
			zephir_array_update_string(&handleArgs, SL("task"), &_45$$24, PH_COPY | PH_SEPARATE);
		}
		if (zephir_fast_count_int(&args)) {
			ZEPHIR_MAKE_REF(&args);
			ZEPHIR_CALL_FUNCTION(&_46$$25, "array_shift", NULL, 24, &args);
			ZEPHIR_UNREF(&args);
			zephir_check_call_status();
			zephir_array_update_string(&handleArgs, SL("action"), &_46$$25, PH_COPY | PH_SEPARATE);
		}
		if (zephir_fast_count_int(&args)) {
			ZEPHIR_INIT_VAR(&_47$$26);
			zephir_fast_array_merge(&_47$$26, &handleArgs, &args);
			ZEPHIR_CPY_WRT(&handleArgs, &_47$$26);
		}
		zephir_update_property_zval(this_ptr, SL("arguments"), &handleArgs);
	}
	zephir_update_property_zval(this_ptr, SL("options"), &opts);
	RETURN_THIS();

}

zend_object *zephir_init_properties_Phalcon_Cli_Console(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _1$$3, _3$$4, _5$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("options"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("modules"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("modules"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("arguments"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("arguments"), &_5$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

