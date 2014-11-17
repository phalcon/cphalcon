
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/require.h"
#include "kernel/hash.h"
#include "kernel/string.h"


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
 |          Rack Lin <racklin@gmail.com>                                  |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Cli\Console
 *
 * This component allows to create CLI applications using Phalcon
 */
ZEPHIR_INIT_CLASS(Phalcon_Cli_Console) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Cli, Console, phalcon, cli_console, phalcon_cli_console_method_entry, 0);

	zend_declare_property_null(phalcon_cli_console_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_console_ce, SL("_eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_console_ce, SL("_modules"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_console_ce, SL("_moduleObject"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_console_ce, SL("_arguments"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_console_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_cli_console_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	zend_class_implements(phalcon_cli_console_ce TSRMLS_CC, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Cli\Console constructor
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Cli_Console, __construct) {

	zend_bool _0;
	zval *dependencyInjector = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &dependencyInjector);

	if (!dependencyInjector) {
		dependencyInjector = ZEPHIR_GLOBAL(global_null);
	}


	_0 = Z_TYPE_P(dependencyInjector) != IS_NULL;
	if (_0) {
		_0 = !zephir_instance_of_ev(dependencyInjector, phalcon_diinterface_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'dependencyInjector' must be an instance of 'Phalcon\\DiInterface'", "", 0);
		return;
	}
	if (Z_TYPE_P(dependencyInjector) == IS_OBJECT) {
		zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("_arguments"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	array_init(_2);
	zephir_update_property_this(this_ptr, SL("_options"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the DependencyInjector container
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Cli_Console, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	if (!(zephir_instance_of_ev(dependencyInjector, phalcon_diinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'dependencyInjector' must be an instance of 'Phalcon\\DiInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Cli_Console, getDI) {


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Sets the events manager
 *
 * @param Phalcon\Events\ManagerInterface eventsManager
 */
PHP_METHOD(Phalcon_Cli_Console, setEventsManager) {

	zval *eventsManager;

	zephir_fetch_params(0, 1, 0, &eventsManager);



	if (!(zephir_instance_of_ev(eventsManager, phalcon_events_managerinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'eventsManager' must be an instance of 'Phalcon\\Events\\ManagerInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("_eventsManager"), eventsManager TSRMLS_CC);

}

/**
 * Returns the internal event manager
 *
 * @return Phalcon\Events\ManagerInterface
 */
PHP_METHOD(Phalcon_Cli_Console, getEventsManager) {


	RETURN_MEMBER(this_ptr, "_eventsManager");

}

/**
 * Register an array of modules present in the console
 *
 *<code>
 *	$application->registerModules(array(
 *		'frontend' => array(
 *			'className' => 'Multiple\Frontend\Module',
 *			'path' => '../apps/frontend/Module.php'
 *		),
 *		'backend' => array(
 *			'className' => 'Multiple\Backend\Module',
 *			'path' => '../apps/backend/Module.php'
 *		)
 *	));
 *</code>
 *
 * @param array modules
 */
PHP_METHOD(Phalcon_Cli_Console, registerModules) {

	zval *modules_param = NULL;
	zval *modules = NULL;

	zephir_fetch_params(0, 1, 0, &modules_param);

	if (unlikely(Z_TYPE_P(modules_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modules' must be an array") TSRMLS_CC);
		RETURN_NULL();
	}

		modules = modules_param;



	zephir_update_property_this(this_ptr, SL("_modules"), modules TSRMLS_CC);

}

/**
 * Merge modules with the existing ones
 *
 *<code>
 *	application->addModules(array(
 *		'admin' => array(
 *			'className' => 'Multiple\Admin\Module',
 *			'path' => '../apps/admin/Module.php'
 *		)
 *	));
 *</code>
 *
 * @param array modules
 */
PHP_METHOD(Phalcon_Cli_Console, addModules) {

	zval *modules_param = NULL, *_0, *_1;
	zval *modules = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &modules_param);

	if (unlikely(Z_TYPE_P(modules_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modules' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		modules = modules_param;



	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_modules"), PH_NOISY_CC);
	zephir_fast_array_merge(_0, &(modules), &(_1) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_modules"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Return the modules registered in the console
 *
 * @return array
 */
PHP_METHOD(Phalcon_Cli_Console, getModules) {


	RETURN_MEMBER(this_ptr, "_modules");

}

/**
 * Handle the whole command-line tasks
 *
 * @param array arguments
 * @return mixed
 */
PHP_METHOD(Phalcon_Cli_Console, handle) {

	zend_bool _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *arguments = NULL, *dependencyInjector, *router = NULL, *eventsManager = NULL, *moduleName = NULL, *modules, *module, *path, *className = NULL, *moduleObject = NULL, *dispatcher = NULL, *task = NULL, *_0, *_1 = NULL, *_2 = NULL, *_4, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_10 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arguments);

	if (!arguments) {
		arguments = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cli_console_exception_ce, "A dependency injection object is required to access internal services", "phalcon/cli/console.zep", 170);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(eventsManager, _0);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "router", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "getshared", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(router, _1);
	_3 = !zephir_is_true(arguments);
	if (_3) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_arguments"), PH_NOISY_CC);
		_3 = zephir_is_true(_0);
	}
	if (_3) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_arguments"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, router, "handle", NULL, _4);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(NULL, router, "handle", NULL, arguments);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&moduleName, router, "getmodulename", NULL);
	zephir_check_call_status();
	if (zephir_is_true(moduleName)) {
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "console:beforeStartModule", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_1, eventsManager, "fire", NULL, _2, this_ptr, moduleName);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_1)) {
				RETURN_MM_BOOL(0);
			}
		}
		ZEPHIR_OBS_VAR(modules);
		zephir_read_property_this(&modules, this_ptr, SL("_modules"), PH_NOISY_CC);
		if (!(zephir_array_isset(modules, moduleName))) {
			ZEPHIR_INIT_VAR(_5);
			object_init_ex(_5, phalcon_cli_console_exception_ce);
			ZEPHIR_INIT_VAR(_6);
			ZEPHIR_CONCAT_SVS(_6, "Module '", moduleName, "' isn't registered in the console container");
			ZEPHIR_CALL_METHOD(NULL, _5, "__construct", NULL, _6);
			zephir_check_call_status();
			zephir_throw_exception_debug(_5, "phalcon/cli/console.zep", 194 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_VAR(module);
		zephir_array_fetch(&module, modules, moduleName, PH_NOISY, "phalcon/cli/console.zep", 197 TSRMLS_CC);
		if (Z_TYPE_P(module) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cli_console_exception_ce, "Invalid module definition path", "phalcon/cli/console.zep", 199);
			return;
		}
		ZEPHIR_OBS_VAR(path);
		if (zephir_array_isset_string_fetch(&path, module, SS("path"), 0 TSRMLS_CC)) {
			if (!((zephir_file_exists(path TSRMLS_CC) == SUCCESS))) {
				ZEPHIR_INIT_LNVAR(_5);
				object_init_ex(_5, phalcon_cli_console_exception_ce);
				ZEPHIR_INIT_LNVAR(_6);
				ZEPHIR_CONCAT_SVS(_6, "Module definition path '", path, "' doesn't exist");
				ZEPHIR_CALL_METHOD(NULL, _5, "__construct", NULL, _6);
				zephir_check_call_status();
				zephir_throw_exception_debug(_5, "phalcon/cli/console.zep", 204 TSRMLS_CC);
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
		ZEPHIR_CALL_METHOD(&moduleObject, dependencyInjector, "get", NULL, className);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, moduleObject, "registerautoloaders", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, moduleObject, "registerservices", NULL, dependencyInjector);
		zephir_check_call_status();
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			zephir_update_property_this(this_ptr, SL("_moduleObject"), moduleObject TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "console:afterStartModule", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_7, eventsManager, "fire", NULL, _2, this_ptr, moduleObject);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_7)) {
				RETURN_MM_BOOL(0);
			}
		}
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "dispatcher", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_7, dependencyInjector, "getshared", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(dispatcher, _7);
	ZEPHIR_CALL_METHOD(&_7, router, "gettaskname", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "settaskname", NULL, _7);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_8, router, "getactionname", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setactionname", NULL, _8);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_9, router, "getparams", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setparams", NULL, _9);
	zephir_check_call_status();
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setoptions", NULL, _4);
	zephir_check_call_status();
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "console:beforeHandleTask", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_10, eventsManager, "fire", NULL, _2, this_ptr, dispatcher);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_10)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_CALL_METHOD(&task, dispatcher, "dispatch", NULL);
	zephir_check_call_status();
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "console:afterHandleTask", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, _2, this_ptr, task);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
	}
	RETURN_CCTOR(task);

}

/**
 * Set an specific argument
 *
 * @param var arguments
 * @param boolean str
 * @param boolean shift
 */
PHP_METHOD(Phalcon_Cli_Console, setArgument) {

	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_8 = NULL, *_11 = NULL, *_15 = NULL;
	zend_bool str, shift, _0;
	zval *arguments = NULL, *str_param = NULL, *shift_param = NULL, *arg = NULL, *pos = NULL, *args, *opts, *handleArgs = NULL, **_4, _5 = zval_used_for_init, _6 = zval_used_for_init, *_7 = NULL, *_9 = NULL, *_10 = NULL, *_12 = NULL, _13 = zval_used_for_init, *_14 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &arguments, &str_param, &shift_param);

	if (!arguments) {
		arguments = ZEPHIR_GLOBAL(global_null);
	}
	if (!str_param) {
		str = 1;
	} else {
	if (unlikely(Z_TYPE_P(str_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'str' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	str = Z_BVAL_P(str_param);
	}
	if (!shift_param) {
		shift = 1;
	} else {
	if (unlikely(Z_TYPE_P(shift_param) != IS_BOOL)) {
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
	if (Z_TYPE_P(arguments) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cli_console_exception_ce, "Arguments must be an array", "phalcon/cli/console.zep", 265);
		return;
	}
	_0 = shift;
	if (_0) {
		_0 = (zephir_fast_count_int(arguments TSRMLS_CC)) ? 1 : 0;
	}
	if (_0) {
		Z_SET_ISREF_P(arguments);
		ZEPHIR_CALL_FUNCTION(NULL, "array_shift", &_1, arguments);
		Z_UNSET_ISREF_P(arguments);
		zephir_check_call_status();
	}
	zephir_is_iterable(arguments, &_3, &_2, 0, 0, "phalcon/cli/console.zep", 293);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(arg, _4);
		if (Z_TYPE_P(arg) == IS_STRING) {
			ZEPHIR_SINIT_NVAR(_5);
			ZVAL_STRING(&_5, "--", 0);
			ZEPHIR_SINIT_NVAR(_6);
			ZVAL_LONG(&_6, 2);
			ZEPHIR_CALL_FUNCTION(&_7, "strncmp", &_8, arg, &_5, &_6);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG(_7, 0)) {
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_STRING(&_5, "=", 0);
				ZEPHIR_INIT_NVAR(pos);
				zephir_fast_strpos(pos, arg, &_5, 0 );
				if (zephir_is_true(pos)) {
					ZEPHIR_INIT_NVAR(_9);
					ZEPHIR_SINIT_NVAR(_6);
					ZVAL_LONG(&_6, (zephir_get_numberval(pos) + 1));
					ZEPHIR_CALL_FUNCTION(&_10, "substr", &_11, arg, &_6);
					zephir_check_call_status();
					zephir_fast_trim(_9, _10, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_12);
					ZEPHIR_SINIT_NVAR(_6);
					ZVAL_LONG(&_6, 2);
					ZEPHIR_SINIT_NVAR(_13);
					ZVAL_LONG(&_13, (zephir_get_numberval(pos) - 2));
					ZEPHIR_CALL_FUNCTION(&_14, "substr", &_11, arg, &_6, &_13);
					zephir_check_call_status();
					zephir_fast_trim(_12, _14, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
					zephir_array_update_zval(&opts, _12, &_9, PH_COPY | PH_SEPARATE);
				} else {
					ZEPHIR_INIT_NVAR(_9);
					ZEPHIR_SINIT_NVAR(_6);
					ZVAL_LONG(&_6, 2);
					ZEPHIR_CALL_FUNCTION(&_10, "substr", &_11, arg, &_6);
					zephir_check_call_status();
					zephir_fast_trim(_9, _10, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
					zephir_array_update_zval(&opts, _9, &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				}
			} else {
				ZEPHIR_SINIT_NVAR(_6);
				ZVAL_STRING(&_6, "-", 0);
				ZEPHIR_SINIT_NVAR(_13);
				ZVAL_LONG(&_13, 1);
				ZEPHIR_CALL_FUNCTION(&_10, "strncmp", &_8, arg, &_6, &_13);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG(_10, 0)) {
					ZEPHIR_SINIT_NVAR(_6);
					ZVAL_LONG(&_6, 1);
					ZEPHIR_CALL_FUNCTION(&_14, "substr", &_11, arg, &_6);
					zephir_check_call_status();
					zephir_array_update_zval(&opts, _14, &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_append(&args, arg, PH_SEPARATE, "phalcon/cli/console.zep", 285);
				}
			}
		} else {
			zephir_array_append(&args, arg, PH_SEPARATE, "phalcon/cli/console.zep", 289);
		}
	}
	if (str) {
		ZEPHIR_INIT_NVAR(_9);
		ZEPHIR_CALL_CE_STATIC(&_7, phalcon_cli_router_route_ce, "getdelimiter", &_15);
		zephir_check_call_status();
		zephir_fast_join(_9, _7, args TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_arguments"), _9 TSRMLS_CC);
	} else {
		if (zephir_fast_count_int(args TSRMLS_CC)) {
			Z_SET_ISREF_P(args);
			ZEPHIR_CALL_FUNCTION(&_10, "array_shift", &_1, args);
			Z_UNSET_ISREF_P(args);
			zephir_check_call_status();
			zephir_array_update_string(&handleArgs, SL("task"), &_10, PH_COPY | PH_SEPARATE);
		}
		if (zephir_fast_count_int(args TSRMLS_CC)) {
			Z_SET_ISREF_P(args);
			ZEPHIR_CALL_FUNCTION(&_7, "array_shift", &_1, args);
			Z_UNSET_ISREF_P(args);
			zephir_check_call_status();
			zephir_array_update_string(&handleArgs, SL("action"), &_7, PH_COPY | PH_SEPARATE);
		}
		if (zephir_fast_count_int(args TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(_12);
			zephir_fast_array_merge(_12, &(handleArgs), &(args) TSRMLS_CC);
			ZEPHIR_CPY_WRT(handleArgs, _12);
		}
		zephir_update_property_this(this_ptr, SL("_arguments"), handleArgs TSRMLS_CC);
	}
	zephir_update_property_this(this_ptr, SL("_options"), opts TSRMLS_CC);
	RETURN_THIS();

}

