
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
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/require.h"
#include "kernel/hash.h"
#include "kernel/string.h"


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
 */
PHP_METHOD(Phalcon_Cli_Console, __construct) {

	zval *dependencyInjector = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &dependencyInjector);

	if (!dependencyInjector) {
		dependencyInjector = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(dependencyInjector) == IS_OBJECT) {
		zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_arguments"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("_options"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the DependencyInjector container
 */
PHP_METHOD(Phalcon_Cli_Console, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Cli_Console, getDI) {

	

	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Sets the events manager
 */
PHP_METHOD(Phalcon_Cli_Console, setEventsManager) {

	zval *eventsManager;

	zephir_fetch_params(0, 1, 0, &eventsManager);



	zephir_update_property_this(this_ptr, SL("_eventsManager"), eventsManager TSRMLS_CC);

}

/**
 * Returns the internal event manager
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
 */
PHP_METHOD(Phalcon_Cli_Console, registerModules) {

	zval *modules_param = NULL;
	zval *modules = NULL;

	zephir_fetch_params(0, 1, 0, &modules_param);

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
 */
PHP_METHOD(Phalcon_Cli_Console, addModules) {

	zval *modules_param = NULL, *_0, *_1;
	zval *modules = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &modules_param);

	modules = modules_param;


	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_modules"), PH_NOISY_CC);
	zephir_fast_array_merge(_0, &(modules), &(_1) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_modules"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Return the modules registered in the console
 */
PHP_METHOD(Phalcon_Cli_Console, getModules) {

	

	RETURN_MEMBER(this_ptr, "_modules");

}

/**
 * Handle the whole command-line tasks
 */
PHP_METHOD(Phalcon_Cli_Console, handle) {

	zend_bool _5;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *arguments_param = NULL, *dependencyInjector = NULL, *router = NULL, *eventsManager = NULL, *moduleName = NULL, *modules = NULL, *module = NULL, *path = NULL, *className = NULL, *moduleObject = NULL, *dispatcher = NULL, *task = NULL, *_0, *_3 = NULL, *_4 = NULL, *_15 = NULL, *_16 = NULL, *_17, *_1$$4 = NULL, *_2$$4, *_6$$6, *_7$$9 = NULL, *_8$$9, *_9$$11, *_10$$11, *_11$$14, *_12$$14, *_13$$16 = NULL, *_14$$16, *_18$$18 = NULL, *_19$$18, *_20$$20;
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cli_console_exception_ce, "A dependency injection object is required to access internal services", "phalcon/cli/console.zep", 152);
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
	if (zephir_is_true(moduleName)) {
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(_8$$9);
			ZVAL_STRING(_8$$9, "console:beforeStartModule", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_7$$9, eventsManager, "fire", NULL, 0, _8$$9, this_ptr, moduleName);
			zephir_check_temp_parameter(_8$$9);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_7$$9)) {
				RETURN_MM_BOOL(0);
			}
		}
		ZEPHIR_OBS_VAR(modules);
		zephir_read_property_this(&modules, this_ptr, SL("_modules"), PH_NOISY_CC);
		if (!(zephir_array_isset(modules, moduleName))) {
			ZEPHIR_INIT_VAR(_9$$11);
			object_init_ex(_9$$11, phalcon_cli_console_exception_ce);
			ZEPHIR_INIT_VAR(_10$$11);
			ZEPHIR_CONCAT_SVS(_10$$11, "Module '", moduleName, "' isn't registered in the console container");
			ZEPHIR_CALL_METHOD(NULL, _9$$11, "__construct", NULL, 9, _10$$11);
			zephir_check_call_status();
			zephir_throw_exception_debug(_9$$11, "phalcon/cli/console.zep", 185 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_VAR(module);
		zephir_array_fetch(&module, modules, moduleName, PH_NOISY, "phalcon/cli/console.zep", 188 TSRMLS_CC);
		if (Z_TYPE_P(module) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cli_console_exception_ce, "Invalid module definition path", "phalcon/cli/console.zep", 190);
			return;
		}
		ZEPHIR_OBS_VAR(path);
		if (zephir_array_isset_string_fetch(&path, module, SS("path"), 0 TSRMLS_CC)) {
			if (!((zephir_file_exists(path TSRMLS_CC) == SUCCESS))) {
				ZEPHIR_INIT_VAR(_11$$14);
				object_init_ex(_11$$14, phalcon_cli_console_exception_ce);
				ZEPHIR_INIT_VAR(_12$$14);
				ZEPHIR_CONCAT_SVS(_12$$14, "Module definition path '", path, "' doesn't exist");
				ZEPHIR_CALL_METHOD(NULL, _11$$14, "__construct", NULL, 9, _12$$14);
				zephir_check_call_status();
				zephir_throw_exception_debug(_11$$14, "phalcon/cli/console.zep", 195 TSRMLS_CC);
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
			zephir_update_property_this(this_ptr, SL("_moduleObject"), moduleObject TSRMLS_CC);
			ZEPHIR_INIT_VAR(_14$$16);
			ZVAL_STRING(_14$$16, "console:afterStartModule", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_13$$16, eventsManager, "fire", NULL, 0, _14$$16, this_ptr, moduleObject);
			zephir_check_temp_parameter(_14$$16);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_13$$16)) {
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
		ZEPHIR_INIT_VAR(_19$$18);
		ZVAL_STRING(_19$$18, "console:beforeHandleTask", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_18$$18, eventsManager, "fire", NULL, 0, _19$$18, this_ptr, dispatcher);
		zephir_check_temp_parameter(_19$$18);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_18$$18)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_CALL_METHOD(&task, dispatcher, "dispatch", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_20$$20);
		ZVAL_STRING(_20$$20, "console:afterHandleTask", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _20$$20, this_ptr, task);
		zephir_check_temp_parameter(_20$$20);
		zephir_check_call_status();
	}
	RETURN_CCTOR(task);

}

/**
 * Set an specific argument
 */
PHP_METHOD(Phalcon_Cli_Console, setArgument) {

	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_8 = NULL, *_27 = NULL;
	zend_bool str, shift, _0;
	zval *arguments_param = NULL, *str_param = NULL, *shift_param = NULL, *arg = NULL, *pos = NULL, *args = NULL, *opts = NULL, *handleArgs = NULL, **_4, _5$$5 = zval_used_for_init, _6$$5 = zval_used_for_init, *_7$$5 = NULL, _9$$6 = zval_used_for_init, *_10$$7 = NULL, _11$$7 = zval_used_for_init, *_12$$7 = NULL, *_13$$7 = NULL, _14$$7 = zval_used_for_init, _15$$7 = zval_used_for_init, *_16$$7 = NULL, *_17$$8 = NULL, _18$$8 = zval_used_for_init, *_19$$8 = NULL, _20$$9 = zval_used_for_init, _21$$9 = zval_used_for_init, *_22$$9 = NULL, _23$$10 = zval_used_for_init, *_24$$10 = NULL, *_25$$13, *_26$$13 = NULL, *_28$$15 = NULL, *_29$$16 = NULL, *_30$$17;
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
	_0 = shift;
	if (_0) {
		_0 = (zephir_fast_count_int(arguments TSRMLS_CC)) ? 1 : 0;
	}
	if (_0) {
		ZEPHIR_MAKE_REF(arguments);
		ZEPHIR_CALL_FUNCTION(NULL, "array_shift", &_1, 123, arguments);
		ZEPHIR_UNREF(arguments);
		zephir_check_call_status();
	}
	zephir_is_iterable(arguments, &_3, &_2, 0, 0, "phalcon/cli/console.zep", 276);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(arg, _4);
		if (Z_TYPE_P(arg) == IS_STRING) {
			ZEPHIR_SINIT_NVAR(_5$$5);
			ZVAL_STRING(&_5$$5, "--", 0);
			ZEPHIR_SINIT_NVAR(_6$$5);
			ZVAL_LONG(&_6$$5, 2);
			ZEPHIR_CALL_FUNCTION(&_7$$5, "strncmp", &_8, 124, arg, &_5$$5, &_6$$5);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG(_7$$5, 0)) {
				ZEPHIR_SINIT_NVAR(_9$$6);
				ZVAL_STRING(&_9$$6, "=", 0);
				ZEPHIR_INIT_NVAR(pos);
				zephir_fast_strpos(pos, arg, &_9$$6, 0 );
				if (zephir_is_true(pos)) {
					ZEPHIR_INIT_NVAR(_10$$7);
					ZEPHIR_SINIT_NVAR(_11$$7);
					ZVAL_LONG(&_11$$7, (zephir_get_numberval(pos) + 1));
					ZEPHIR_INIT_NVAR(_12$$7);
					zephir_substr(_12$$7, arg, zephir_get_intval(&_11$$7), 0, ZEPHIR_SUBSTR_NO_LENGTH);
					zephir_fast_trim(_10$$7, _12$$7, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_13$$7);
					ZEPHIR_SINIT_NVAR(_14$$7);
					ZVAL_LONG(&_14$$7, 2);
					ZEPHIR_SINIT_NVAR(_15$$7);
					ZVAL_LONG(&_15$$7, (zephir_get_numberval(pos) - 2));
					ZEPHIR_INIT_NVAR(_16$$7);
					zephir_substr(_16$$7, arg, 2 , zephir_get_intval(&_15$$7), 0);
					zephir_fast_trim(_13$$7, _16$$7, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
					zephir_array_update_zval(&opts, _13$$7, &_10$$7, PH_COPY | PH_SEPARATE);
				} else {
					ZEPHIR_INIT_NVAR(_17$$8);
					ZEPHIR_SINIT_NVAR(_18$$8);
					ZVAL_LONG(&_18$$8, 2);
					ZEPHIR_INIT_NVAR(_19$$8);
					zephir_substr(_19$$8, arg, 2 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
					zephir_fast_trim(_17$$8, _19$$8, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
					zephir_array_update_zval(&opts, _17$$8, &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				}
			} else {
				ZEPHIR_SINIT_NVAR(_20$$9);
				ZVAL_STRING(&_20$$9, "-", 0);
				ZEPHIR_SINIT_NVAR(_21$$9);
				ZVAL_LONG(&_21$$9, 1);
				ZEPHIR_CALL_FUNCTION(&_22$$9, "strncmp", &_8, 124, arg, &_20$$9, &_21$$9);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG(_22$$9, 0)) {
					ZEPHIR_SINIT_NVAR(_23$$10);
					ZVAL_LONG(&_23$$10, 1);
					ZEPHIR_INIT_NVAR(_24$$10);
					zephir_substr(_24$$10, arg, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
					zephir_array_update_zval(&opts, _24$$10, &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_append(&args, arg, PH_SEPARATE, "phalcon/cli/console.zep", 268);
				}
			}
		} else {
			zephir_array_append(&args, arg, PH_SEPARATE, "phalcon/cli/console.zep", 272);
		}
	}
	if (str) {
		ZEPHIR_INIT_VAR(_25$$13);
		ZEPHIR_CALL_CE_STATIC(&_26$$13, phalcon_cli_router_route_ce, "getdelimiter", &_27, 125);
		zephir_check_call_status();
		zephir_fast_join(_25$$13, _26$$13, args TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_arguments"), _25$$13 TSRMLS_CC);
	} else {
		if (zephir_fast_count_int(args TSRMLS_CC)) {
			ZEPHIR_MAKE_REF(args);
			ZEPHIR_CALL_FUNCTION(&_28$$15, "array_shift", &_1, 123, args);
			ZEPHIR_UNREF(args);
			zephir_check_call_status();
			zephir_array_update_string(&handleArgs, SL("task"), &_28$$15, PH_COPY | PH_SEPARATE);
		}
		if (zephir_fast_count_int(args TSRMLS_CC)) {
			ZEPHIR_MAKE_REF(args);
			ZEPHIR_CALL_FUNCTION(&_29$$16, "array_shift", &_1, 123, args);
			ZEPHIR_UNREF(args);
			zephir_check_call_status();
			zephir_array_update_string(&handleArgs, SL("action"), &_29$$16, PH_COPY | PH_SEPARATE);
		}
		if (zephir_fast_count_int(args TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_30$$17);
			zephir_fast_array_merge(_30$$17, &(handleArgs), &(args) TSRMLS_CC);
			ZEPHIR_CPY_WRT(handleArgs, _30$$17);
		}
		zephir_update_property_this(this_ptr, SL("_arguments"), handleArgs TSRMLS_CC);
	}
	zephir_update_property_this(this_ptr, SL("_options"), opts TSRMLS_CC);
	RETURN_THIS();

}

