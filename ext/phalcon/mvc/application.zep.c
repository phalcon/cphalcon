
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
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/file.h"
#include "kernel/require.h"
#include "Zend/zend_closures.h"


/**
 * Phalcon\Mvc\Application
 *
 * This component encapsulates all the complex operations behind instantiating every component
 * needed and integrating it with the rest to allow the MVC pattern to operate as desired.
 *
 *<code>
 *
 * class Application extends \Phalcon\Mvc\Application
 * {
 *
 *		/**
 *		 * Register the services here to make them general or register
 *		 * in the ModuleDefinition to make them module-specific
 *		 *\/
 *		protected function _registerServices()
 *		{
 *
 *		}
 *
 *		/**
 *		 * This method registers all the modules in the application
 *		 *\/
 *		public function main()
 *		{
 *			$this->registerModules(array(
 *				'frontend' => array(
 *					'className' => 'Multiple\Frontend\Module',
 *					'path' => '../apps/frontend/Module.php'
 *				),
 *				'backend' => array(
 *					'className' => 'Multiple\Backend\Module',
 *					'path' => '../apps/backend/Module.php'
 *				)
 *			));
 *		}
 *	}
 *
 *	$application = new Application();
 *	$application->main();
 *
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Application) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc, Application, phalcon, mvc_application, phalcon_di_injectable_ce, phalcon_mvc_application_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_application_ce, SL("_defaultModule"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_application_ce, SL("_modules"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_mvc_application_ce, SL("_implicitView"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Mvc\Application
 */
PHP_METHOD(Phalcon_Mvc_Application, __construct) {

	zval *dependencyInjector = NULL;

	zephir_fetch_params(0, 0, 1, &dependencyInjector);

	if (!dependencyInjector) {
		dependencyInjector = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(dependencyInjector) == IS_OBJECT) {
		zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	}

}

/**
 * By default. The view is implicitly buffering all the output
 * You can full disable the view component using this method
 */
PHP_METHOD(Phalcon_Mvc_Application, useImplicitView) {

	zval *implicitView_param = NULL;
	zend_bool implicitView;

	zephir_fetch_params(0, 1, 0, &implicitView_param);

	implicitView = zephir_get_boolval(implicitView_param);


	if (implicitView) {
		zephir_update_property_this(this_ptr, SL("_implicitView"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_implicitView"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THISW();

}

/**
 * Register an array of modules present in the application
 *
 *<code>
 *	$this->registerModules(array(
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
PHP_METHOD(Phalcon_Mvc_Application, registerModules) {

	zend_bool merge;
	zval *modules_param = NULL, *merge_param = NULL, *registeredModules = NULL, *_0$$5;
	zval *modules = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &modules_param, &merge_param);

	zephir_get_arrval(modules, modules_param);
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (merge == 0) {
		zephir_update_property_this(this_ptr, SL("_modules"), modules TSRMLS_CC);
	} else {
		ZEPHIR_OBS_VAR(registeredModules);
		zephir_read_property_this(&registeredModules, this_ptr, SL("_modules"), PH_NOISY_CC);
		if (Z_TYPE_P(registeredModules) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(_0$$5);
			zephir_fast_array_merge(_0$$5, &(registeredModules), &(modules) TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_modules"), _0$$5 TSRMLS_CC);
		} else {
			zephir_update_property_this(this_ptr, SL("_modules"), modules TSRMLS_CC);
		}
	}
	RETURN_THIS();

}

/**
 * Return the modules registered in the application
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Application, getModules) {

	

	RETURN_MEMBER(this_ptr, "_modules");

}

/**
 * Gets the module definition registered in the application via module name
 *
 * @param string name
 * @return array|object
 */
PHP_METHOD(Phalcon_Mvc_Application, getModule) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *module = NULL, *_0, *_1$$3;
	zval *name = NULL, *_2$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_OBS_VAR(module);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modules"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&module, _0, name, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, phalcon_mvc_application_exception_ce);
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_CONCAT_SVS(_2$$3, "Module '", name, "' isn't registered in the application container");
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 9, _2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "phalcon/mvc/application.zep", 159 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(module);

}

/**
 * Sets the module name to be used if the router doesn't return a valid module
 */
PHP_METHOD(Phalcon_Mvc_Application, setDefaultModule) {

	zval *defaultModule_param = NULL;
	zval *defaultModule = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &defaultModule_param);

	if (unlikely(Z_TYPE_P(defaultModule_param) != IS_STRING && Z_TYPE_P(defaultModule_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'defaultModule' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(defaultModule_param) == IS_STRING)) {
		zephir_get_strval(defaultModule, defaultModule_param);
	} else {
		ZEPHIR_INIT_VAR(defaultModule);
		ZVAL_EMPTY_STRING(defaultModule);
	}


	zephir_update_property_this(this_ptr, SL("_defaultModule"), defaultModule TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the default module name
 */
PHP_METHOD(Phalcon_Mvc_Application, getDefaultModule) {

	

	RETURN_MEMBER(this_ptr, "_defaultModule");

}

/**
 * Handles a MVC request
 *
 * @param string uri
 * @return \Phalcon\Http\ResponseInterface|boolean
 */
PHP_METHOD(Phalcon_Mvc_Application, handle) {

	zval *_11$$18;
	zend_bool returnedResponse = 0, _21, _7$$7;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *uri = NULL, *dependencyInjector = NULL, *eventsManager = NULL, *router = NULL, *dispatcher = NULL, *response = NULL, *view = NULL, *module = NULL, *moduleObject = NULL, *moduleName = NULL, *className = NULL, *path = NULL, *implicitView = NULL, *controller = NULL, *possibleResponse = NULL, *renderStatus = NULL, *_0, *_3 = NULL, *_4 = NULL, *_15 = NULL, *_16 = NULL, *_17 = NULL, *_18 = NULL, *_1$$4 = NULL, *_2$$4, *_5$$8 = NULL, *_6$$8, *_8$$16, *_9$$16, *_10$$11 = NULL, *_12$$20, *_13$$21 = NULL, *_14$$21, *_19$$23 = NULL, *_20$$23, *_22$$25 = NULL, *_23$$25, *_24$$29, *_25$$33, *_26$$34 = NULL, *_27$$34 = NULL, *_28$$34 = NULL, *_29$$36 = NULL, *_30$$36, *_31$$37 = NULL, *_32$$39;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri);

	if (!uri) {
		uri = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_application_exception_ce, "A dependency injection object is required to access internal services", "phalcon/mvc/application.zep", 196);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(eventsManager, _0);
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_2$$4);
		ZVAL_STRING(_2$$4, "application:boot", ZEPHIR_TEMP_PARAM_COPY);
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
	ZEPHIR_CALL_METHOD(NULL, router, "handle", NULL, 0, uri);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&moduleName, router, "getmodulename", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(moduleName))) {
		ZEPHIR_OBS_NVAR(moduleName);
		zephir_read_property_this(&moduleName, this_ptr, SL("_defaultModule"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(moduleObject);
	ZVAL_NULL(moduleObject);
	if (zephir_is_true(moduleName)) {
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(_6$$8);
			ZVAL_STRING(_6$$8, "application:beforeStartModule", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_5$$8, eventsManager, "fire", NULL, 0, _6$$8, this_ptr, moduleName);
			zephir_check_temp_parameter(_6$$8);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_5$$8)) {
				RETURN_MM_BOOL(0);
			}
		}
		ZEPHIR_CALL_METHOD(&module, this_ptr, "getmodule", NULL, 0, moduleName);
		zephir_check_call_status();
		_7$$7 = Z_TYPE_P(module) != IS_ARRAY;
		if (_7$$7) {
			_7$$7 = Z_TYPE_P(module) != IS_OBJECT;
		}
		if (_7$$7) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_application_exception_ce, "Invalid module definition", "phalcon/mvc/application.zep", 247);
			return;
		}
		if (Z_TYPE_P(module) == IS_ARRAY) {
			ZEPHIR_OBS_VAR(className);
			if (!(zephir_array_isset_string_fetch(&className, module, SS("className"), 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(className);
				ZVAL_STRING(className, "Module", 1);
			}
			ZEPHIR_OBS_VAR(path);
			if (zephir_array_isset_string_fetch(&path, module, SS("path"), 0 TSRMLS_CC)) {
				if (!(zephir_class_exists(className, zephir_is_true(ZEPHIR_GLOBAL(global_false))  TSRMLS_CC))) {
					if ((zephir_file_exists(path TSRMLS_CC) == SUCCESS)) {
						if (zephir_require_zval(path TSRMLS_CC) == FAILURE) {
							RETURN_MM_NULL();
						}
					} else {
						ZEPHIR_INIT_VAR(_8$$16);
						object_init_ex(_8$$16, phalcon_mvc_application_exception_ce);
						ZEPHIR_INIT_VAR(_9$$16);
						ZEPHIR_CONCAT_SVS(_9$$16, "Module definition path '", path, "' doesn't exist");
						ZEPHIR_CALL_METHOD(NULL, _8$$16, "__construct", NULL, 9, _9$$16);
						zephir_check_call_status();
						zephir_throw_exception_debug(_8$$16, "phalcon/mvc/application.zep", 270 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
			ZEPHIR_CALL_METHOD(&_10$$11, dependencyInjector, "get", NULL, 0, className);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(moduleObject, _10$$11);
			ZEPHIR_CALL_METHOD(NULL, moduleObject, "registerautoloaders", NULL, 0, dependencyInjector);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, moduleObject, "registerservices", NULL, 0, dependencyInjector);
			zephir_check_call_status();
		} else {
			if (zephir_instance_of_ev(module, zend_ce_closure TSRMLS_CC)) {
				ZEPHIR_INIT_VAR(_11$$18);
				zephir_create_array(_11$$18, 1, 0 TSRMLS_CC);
				zephir_array_fast_append(_11$$18, dependencyInjector);
				ZEPHIR_INIT_NVAR(moduleObject);
				ZEPHIR_CALL_USER_FUNC_ARRAY(moduleObject, module, _11$$18);
				zephir_check_call_status();
			} else {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_application_exception_ce, "Invalid module definition", "phalcon/mvc/application.zep", 291);
				return;
			}
		}
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(_12$$20);
			ZVAL_STRING(_12$$20, "application:afterStartModule", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _12$$20, this_ptr, moduleObject);
			zephir_check_temp_parameter(_12$$20);
			zephir_check_call_status();
		}
	}
	ZEPHIR_OBS_VAR(implicitView);
	zephir_read_property_this(&implicitView, this_ptr, SL("_implicitView"), PH_NOISY_CC);
	if (ZEPHIR_IS_TRUE_IDENTICAL(implicitView)) {
		ZEPHIR_INIT_VAR(_14$$21);
		ZVAL_STRING(_14$$21, "view", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_13$$21, dependencyInjector, "getshared", NULL, 0, _14$$21);
		zephir_check_temp_parameter(_14$$21);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(view, _13$$21);
	}
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "dispatcher", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_3, dependencyInjector, "getshared", NULL, 0, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(dispatcher, _3);
	ZEPHIR_CALL_METHOD(&_3, router, "getmodulename", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setmodulename", NULL, 0, _3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_15, router, "getnamespacename", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setnamespacename", NULL, 0, _15);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_16, router, "getcontrollername", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setcontrollername", NULL, 0, _16);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_17, router, "getactionname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setactionname", NULL, 0, _17);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_18, router, "getparams", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setparams", NULL, 0, _18);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(implicitView)) {
		ZEPHIR_CALL_METHOD(NULL, view, "start", NULL, 0);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_20$$23);
		ZVAL_STRING(_20$$23, "application:beforeHandleRequest", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_19$$23, eventsManager, "fire", NULL, 0, _20$$23, this_ptr, dispatcher);
		zephir_check_temp_parameter(_20$$23);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_19$$23)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_CALL_METHOD(&controller, dispatcher, "dispatch", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&possibleResponse, dispatcher, "getreturnedvalue", NULL, 0);
	zephir_check_call_status();
	_21 = Z_TYPE_P(possibleResponse) == IS_BOOL;
	if (_21) {
		_21 = ZEPHIR_IS_FALSE(possibleResponse);
	}
	if (_21) {
		ZEPHIR_INIT_VAR(_23$$25);
		ZVAL_STRING(_23$$25, "response", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_22$$25, dependencyInjector, "getshared", NULL, 0, _23$$25);
		zephir_check_temp_parameter(_23$$25);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(response, _22$$25);
	} else {
		if (Z_TYPE_P(possibleResponse) == IS_OBJECT) {
			returnedResponse = zephir_instance_of_ev(possibleResponse, phalcon_http_responseinterface_ce TSRMLS_CC);
		} else {
			returnedResponse = 0;
		}
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(_24$$29);
			ZVAL_STRING(_24$$29, "application:afterHandleRequest", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _24$$29, this_ptr, controller);
			zephir_check_temp_parameter(_24$$29);
			zephir_check_call_status();
		}
		if (returnedResponse == 0) {
			if (ZEPHIR_IS_TRUE_IDENTICAL(implicitView)) {
				if (Z_TYPE_P(controller) == IS_OBJECT) {
					ZEPHIR_INIT_VAR(renderStatus);
					ZVAL_BOOL(renderStatus, 1);
					if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
						ZEPHIR_INIT_VAR(_25$$33);
						ZVAL_STRING(_25$$33, "application:viewRender", ZEPHIR_TEMP_PARAM_COPY);
						ZEPHIR_CALL_METHOD(&renderStatus, eventsManager, "fire", NULL, 0, _25$$33, this_ptr, view);
						zephir_check_temp_parameter(_25$$33);
						zephir_check_call_status();
					}
					if (!ZEPHIR_IS_FALSE_IDENTICAL(renderStatus)) {
						ZEPHIR_CALL_METHOD(&_26$$34, dispatcher, "getcontrollername", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_27$$34, dispatcher, "getactionname", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_28$$34, dispatcher, "getparams", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, view, "render", NULL, 0, _26$$34, _27$$34, _28$$34);
						zephir_check_call_status();
					}
				}
			}
		}
		if (ZEPHIR_IS_TRUE_IDENTICAL(implicitView)) {
			ZEPHIR_CALL_METHOD(NULL, view, "finish", NULL, 0);
			zephir_check_call_status();
		}
		if (returnedResponse == 0) {
			ZEPHIR_INIT_VAR(_30$$36);
			ZVAL_STRING(_30$$36, "response", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_29$$36, dependencyInjector, "getshared", NULL, 0, _30$$36);
			zephir_check_temp_parameter(_30$$36);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(response, _29$$36);
			if (ZEPHIR_IS_TRUE_IDENTICAL(implicitView)) {
				ZEPHIR_CALL_METHOD(&_31$$37, view, "getcontent", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, response, "setcontent", NULL, 0, _31$$37);
				zephir_check_call_status();
			}
		} else {
			ZEPHIR_CPY_WRT(response, possibleResponse);
		}
	}
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_32$$39);
		ZVAL_STRING(_32$$39, "application:beforeSendResponse", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _32$$39, this_ptr, response);
		zephir_check_temp_parameter(_32$$39);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, response, "sendheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, response, "sendcookies", NULL, 0);
	zephir_check_call_status();
	RETURN_CCTOR(response);

}

