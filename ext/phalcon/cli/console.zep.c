
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/require.h"
#include "kernel/string.h"


/**
 * Phalcon\Cli\Console
 *
 * This component allows to create CLI applications using Phalcon
 */
ZEPHIR_INIT_CLASS(Phalcon_Cli_Console) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cli, Console, phalcon, cli_console, phalcon_application_ce, phalcon_cli_console_method_entry, 0);

	zend_declare_property_null(phalcon_cli_console_ce, SL("_arguments"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_console_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_cli_console_ce->create_object = zephir_init_properties_Phalcon_Cli_Console;
	return SUCCESS;

}

/**
 * Merge modules with the existing ones
 *
 *<code>
 * $application->addModules(
 *     [
 *         "admin" => [
 *             "className" => "Multiple\\Admin\\Module",
 *             "path"      => "../apps/admin/Module.php",
 *         ],
 *     ]
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Cli_Console, addModules) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *modules_param = NULL, *_0;
	zval *modules = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &modules_param);

	modules = modules_param;


	ZEPHIR_INIT_VAR(_0);
	ZVAL_BOOL(_0, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "registermodules", NULL, 0, modules, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Handle the whole command-line tasks
 */
PHP_METHOD(Phalcon_Cli_Console, handle) {

	zend_bool _5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arguments_param = NULL, *dependencyInjector = NULL, *router = NULL, *eventsManager = NULL, *moduleName = NULL, *modules = NULL, *module = NULL, *path = NULL, *className = NULL, *moduleObject = NULL, *dispatcher = NULL, *task = NULL, *_0, *_3 = NULL, *_4 = NULL, *_15 = NULL, *_16 = NULL, *_17, *_1$$4 = NULL, *_2$$4, *_6$$6, *_7$$10 = NULL, *_8$$10, *_9$$12, *_10$$12, *_11$$15, *_12$$15, *_13$$17 = NULL, *_14$$17, *_18$$19 = NULL, *_19$$19, *_20$$21;
	zval *arguments = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arguments_param);

	if (!arguments_param) {
		ZEPHIR_INIT_VAR(arguments);
		array_init(arguments);
	} else {
		zephir_get_arrval(arguments, arguments_param);
	}


	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cli_console_exception_ce, "A dependency injection object is required to access internal services", "phalcon/cli/console.zep", 71);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(eventsManager, _0);
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_2$$4);
		ZVAL_STRING(_2$$4, "console:boot", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1$$4, eventsManager, "fire", NULL, 0, _2$$4, this_ptr);
		zephir_check_temp_parameter(_2$$4);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_1$$4)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "router", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_3, dependencyInjector, "getshared", NULL, 0, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(router, _3);
	_5 = !(zephir_fast_count_int(arguments TSRMLS_CC));
	if (_5) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_arguments"), PH_NOISY_CC);
		_5 = zephir_is_true(_0);
	}
	if (_5) {
		_6$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_arguments"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, router, "handle", NULL, 0, _6$$6);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(NULL, router, "handle", NULL, 0, arguments);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&moduleName, router, "getmodulename", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(moduleName))) {
		ZEPHIR_OBS_NVAR(moduleName);
		zephir_read_property_this(&moduleName, this_ptr, SL("_defaultModule"), PH_NOISY_CC);
	}
	if (zephir_is_true(moduleName)) {
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(_8$$10);
			ZVAL_STRING(_8$$10, "console:beforeStartModule", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_7$$10, eventsManager, "fire", NULL, 0, _8$$10, this_ptr, moduleName);
			zephir_check_temp_parameter(_8$$10);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_7$$10)) {
				RETURN_MM_BOOL(0);
			}
		}
		ZEPHIR_OBS_VAR(modules);
		zephir_read_property_this(&modules, this_ptr, SL("_modules"), PH_NOISY_CC);
		if (!(zephir_array_isset(modules, moduleName))) {
			ZEPHIR_INIT_VAR(_9$$12);
			object_init_ex(_9$$12, phalcon_cli_console_exception_ce);
			ZEPHIR_INIT_VAR(_10$$12);
			ZEPHIR_CONCAT_SVS(_10$$12, "Module '", moduleName, "' isn't registered in the console container");
			ZEPHIR_CALL_METHOD(NULL, _9$$12, "__construct", NULL, 9, _10$$12);
			zephir_check_call_status();
			zephir_throw_exception_debug(_9$$12, "phalcon/cli/console.zep", 111 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_VAR(module);
		zephir_array_fetch(&module, modules, moduleName, PH_NOISY, "phalcon/cli/console.zep", 114 TSRMLS_CC);
		if (Z_TYPE_P(module) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cli_console_exception_ce, "Invalid module definition path", "phalcon/cli/console.zep", 116);
			return;
		}
		ZEPHIR_OBS_VAR(path);
		if (zephir_array_isset_string_fetch(&path, module, SS("path"), 0 TSRMLS_CC)) {
			if (!((zephir_file_exists(path TSRMLS_CC) == SUCCESS))) {
				ZEPHIR_INIT_VAR(_11$$15);
				object_init_ex(_11$$15, phalcon_cli_console_exception_ce);
				ZEPHIR_INIT_VAR(_12$$15);
				ZEPHIR_CONCAT_SVS(_12$$15, "Module definition path '", path, "' doesn't exist");
				ZEPHIR_CALL_METHOD(NULL, _11$$15, "__construct", NULL, 9, _12$$15);
				zephir_check_call_status();
				zephir_throw_exception_debug(_11$$15, "phalcon/cli/console.zep", 121 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (zephir_require_zval(path TSRMLS_CC) == FAILURE) {
				RETURN_MM_NULL();
			}
		}
		ZEPHIR_OBS_VAR(className);
		if (!(zephir_array_isset_string_fetch(&className, module, SS("className"), 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(className);
			ZVAL_STRING(className, "Module", 1);
		}
		ZEPHIR_CALL_METHOD(&moduleObject, dependencyInjector, "get", NULL, 0, className);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, moduleObject, "registerautoloaders", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, moduleObject, "registerservices", NULL, 0, dependencyInjector);
		zephir_check_call_status();
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(_14$$17);
			ZVAL_STRING(_14$$17, "console:afterStartModule", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_13$$17, eventsManager, "fire", NULL, 0, _14$$17, this_ptr, moduleObject);
			zephir_check_temp_parameter(_14$$17);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_13$$17)) {
				RETURN_MM_BOOL(0);
			}
		}
	}
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "dispatcher", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_3, dependencyInjector, "getshared", NULL, 0, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(dispatcher, _3);
	ZEPHIR_CALL_METHOD(&_3, router, "gettaskname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "settaskname", NULL, 0, _3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_15, router, "getactionname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setactionname", NULL, 0, _15);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_16, router, "getparams", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setparams", NULL, 0, _16);
	zephir_check_call_status();
	_17 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setoptions", NULL, 0, _17);
	zephir_check_call_status();
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_19$$19);
		ZVAL_STRING(_19$$19, "console:beforeHandleTask", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_18$$19, eventsManager, "fire", NULL, 0, _19$$19, this_ptr, dispatcher);
		zephir_check_temp_parameter(_19$$19);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_18$$19)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_CALL_METHOD(&task, dispatcher, "dispatch", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_20$$21);
		ZVAL_STRING(_20$$21, "console:afterHandleTask", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _20$$21, this_ptr, task);
		zephir_check_temp_parameter(_20$$21);
		zephir_check_call_status();
	}
	RETURN_CCTOR(task);

}

/**
 * Set an specific argument
 */
PHP_METHOD(Phalcon_Cli_Console, setArgument) {

	HashTable *_2;
	HashPosition _1;
	zephir_fcall_cache_entry *_7 = NULL, *_26 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool str, shift, _0;
	zval *arguments_param = NULL, *str_param = NULL, *shift_param = NULL, *arg = NULL, *pos = NULL, *args = NULL, *opts = NULL, *handleArgs = NULL, **_3, _4$$5 = zval_used_for_init, _5$$5 = zval_used_for_init, *_6$$5 = NULL, _8$$6 = zval_used_for_init, *_9$$7 = NULL, _10$$7 = zval_used_for_init, *_11$$7 = NULL, *_12$$7 = NULL, _13$$7 = zval_used_for_init, _14$$7 = zval_used_for_init, *_15$$7 = NULL, *_16$$8 = NULL, _17$$8 = zval_used_for_init, *_18$$8 = NULL, _19$$9 = zval_used_for_init, _20$$9 = zval_used_for_init, *_21$$9 = NULL, _22$$10 = zval_used_for_init, *_23$$10 = NULL, *_24$$13, *_25$$13 = NULL, *_27$$15 = NULL, *_28$$16 = NULL, *_29$$17;
	zval *arguments = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &arguments_param, &str_param, &shift_param);

	if (!arguments_param) {
		ZEPHIR_INIT_VAR(arguments);
		array_init(arguments);
	} else {
	arguments = arguments_param;
	}
	if (!str_param) {
		str = 1;
	} else {
	if (UNEXPECTED(Z_TYPE_P(str_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'str' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	str = Z_BVAL_P(str_param);
	}
	if (!shift_param) {
		shift = 1;
	} else {
	if (UNEXPECTED(Z_TYPE_P(shift_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'shift' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	shift = Z_BVAL_P(shift_param);
	}


	ZEPHIR_INIT_VAR(args);
	array_init(args);
	ZEPHIR_INIT_VAR(opts);
	array_init(opts);
	ZEPHIR_INIT_VAR(handleArgs);
	array_init(handleArgs);
	_0 = shift;
	if (_0) {
		_0 = ((zephir_fast_count_int(arguments TSRMLS_CC)) ? 1 : 0);
	}
	if (_0) {
		ZEPHIR_MAKE_REF(arguments);
		ZEPHIR_CALL_FUNCTION(NULL, "array_shift", NULL, 19, arguments);
		ZEPHIR_UNREF(arguments);
		zephir_check_call_status();
	}
	zephir_is_iterable(arguments, &_2, &_1, 0, 0, "phalcon/cli/console.zep", 201);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(arg, _3);
		if (Z_TYPE_P(arg) == IS_STRING) {
			ZEPHIR_SINIT_NVAR(_4$$5);
			ZVAL_STRING(&_4$$5, "--", 0);
			ZEPHIR_SINIT_NVAR(_5$$5);
			ZVAL_LONG(&_5$$5, 2);
			ZEPHIR_CALL_FUNCTION(&_6$$5, "strncmp", &_7, 143, arg, &_4$$5, &_5$$5);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG(_6$$5, 0)) {
				ZEPHIR_SINIT_NVAR(_8$$6);
				ZVAL_STRING(&_8$$6, "=", 0);
				ZEPHIR_INIT_NVAR(pos);
				zephir_fast_strpos(pos, arg, &_8$$6, 0 );
				if (zephir_is_true(pos)) {
					ZEPHIR_INIT_NVAR(_9$$7);
					ZEPHIR_SINIT_NVAR(_10$$7);
					ZVAL_LONG(&_10$$7, (zephir_get_numberval(pos) + 1));
					ZEPHIR_INIT_NVAR(_11$$7);
					zephir_substr(_11$$7, arg, zephir_get_intval(&_10$$7), 0, ZEPHIR_SUBSTR_NO_LENGTH);
					zephir_fast_trim(_9$$7, _11$$7, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_12$$7);
					ZEPHIR_SINIT_NVAR(_13$$7);
					ZVAL_LONG(&_13$$7, 2);
					ZEPHIR_SINIT_NVAR(_14$$7);
					ZVAL_LONG(&_14$$7, (zephir_get_numberval(pos) - 2));
					ZEPHIR_INIT_NVAR(_15$$7);
					zephir_substr(_15$$7, arg, 2 , zephir_get_intval(&_14$$7), 0);
					zephir_fast_trim(_12$$7, _15$$7, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
					zephir_array_update_zval(&opts, _12$$7, &_9$$7, PH_COPY | PH_SEPARATE);
				} else {
					ZEPHIR_INIT_NVAR(_16$$8);
					ZEPHIR_SINIT_NVAR(_17$$8);
					ZVAL_LONG(&_17$$8, 2);
					ZEPHIR_INIT_NVAR(_18$$8);
					zephir_substr(_18$$8, arg, 2 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
					zephir_fast_trim(_16$$8, _18$$8, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
					zephir_array_update_zval(&opts, _16$$8, &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				}
			} else {
				ZEPHIR_SINIT_NVAR(_19$$9);
				ZVAL_STRING(&_19$$9, "-", 0);
				ZEPHIR_SINIT_NVAR(_20$$9);
				ZVAL_LONG(&_20$$9, 1);
				ZEPHIR_CALL_FUNCTION(&_21$$9, "strncmp", &_7, 143, arg, &_19$$9, &_20$$9);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG(_21$$9, 0)) {
					ZEPHIR_SINIT_NVAR(_22$$10);
					ZVAL_LONG(&_22$$10, 1);
					ZEPHIR_INIT_NVAR(_23$$10);
					zephir_substr(_23$$10, arg, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
					zephir_array_update_zval(&opts, _23$$10, &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_append(&args, arg, PH_SEPARATE, "phalcon/cli/console.zep", 193);
				}
			}
		} else {
			zephir_array_append(&args, arg, PH_SEPARATE, "phalcon/cli/console.zep", 197);
		}
	}
	if (str) {
		ZEPHIR_INIT_VAR(_24$$13);
		ZEPHIR_CALL_CE_STATIC(&_25$$13, phalcon_cli_router_route_ce, "getdelimiter", &_26, 144);
		zephir_check_call_status();
		zephir_fast_join(_24$$13, _25$$13, args TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_arguments"), _24$$13 TSRMLS_CC);
	} else {
		if (zephir_fast_count_int(args TSRMLS_CC)) {
			ZEPHIR_MAKE_REF(args);
			ZEPHIR_CALL_FUNCTION(&_27$$15, "array_shift", NULL, 19, args);
			ZEPHIR_UNREF(args);
			zephir_check_call_status();
			zephir_array_update_string(&handleArgs, SL("task"), &_27$$15, PH_COPY | PH_SEPARATE);
		}
		if (zephir_fast_count_int(args TSRMLS_CC)) {
			ZEPHIR_MAKE_REF(args);
			ZEPHIR_CALL_FUNCTION(&_28$$16, "array_shift", NULL, 19, args);
			ZEPHIR_UNREF(args);
			zephir_check_call_status();
			zephir_array_update_string(&handleArgs, SL("action"), &_28$$16, PH_COPY | PH_SEPARATE);
		}
		if (zephir_fast_count_int(args TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_29$$17);
			zephir_fast_array_merge(_29$$17, &(handleArgs), &(args) TSRMLS_CC);
			ZEPHIR_CPY_WRT(handleArgs, _29$$17);
		}
		zephir_update_property_this(getThis(), SL("_arguments"), handleArgs TSRMLS_CC);
	}
	zephir_update_property_this(getThis(), SL("_options"), opts TSRMLS_CC);
	RETURN_THIS();

}

zend_object_value zephir_init_properties_Phalcon_Cli_Console(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_2, *_4, *_1$$3, *_3$$4, *_5$$5;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(getThis(), SL("_options"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_modules"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(getThis(), SL("_modules"), _3$$4 TSRMLS_CC);
		}
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_arguments"), PH_NOISY_CC);
		if (Z_TYPE_P(_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(_5$$5);
			array_init(_5$$5);
			zephir_update_property_this(getThis(), SL("_arguments"), _5$$5 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

