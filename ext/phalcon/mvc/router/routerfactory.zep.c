
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
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
 * Phalcon\Mvc\Router\RouterFactory
 *
 * Builds a Router from an array or ConfigInterface and loads routes via
 * Router::loadFromConfig.
 *
 *```php
 * use Phalcon\Mvc\Router\RouterFactory;
 *
 * $router = (new RouterFactory())->load(
 *     [
 *         "defaultRoutes" : false,
 *         "routes" : [
 *             ["method" : "get", "pattern" : "/users", "paths" : "Users::index"]
 *         ]
 *     ]
 * );
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router_RouterFactory)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Router, RouterFactory, phalcon, mvc_router_routerfactory, phalcon_mvc_router_routerfactory_method_entry, 0);

	return SUCCESS;
}

/**
 * Builds a Router from a config array or ConfigInterface and loads routes.
 *
 * @param array|\Phalcon\Config\ConfigInterface config
 *
 * @return RouterInterface
 */
PHP_METHOD(Phalcon_Mvc_Router_RouterFactory, load)
{
	zend_bool defaultRoutes = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config = NULL, config_sub, router, _4, _0$$4, _1$$3, _2$$5, _3$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$6);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(config)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &config);
	ZEPHIR_SEPARATE_PARAM(config);
	if (Z_TYPE_P(config) == IS_OBJECT) {
		if (!(zephir_instance_of_ev(config, phalcon_config_configinterface_ce))) {
			ZEPHIR_INIT_VAR(&_0$$4);
			object_init_ex(&_0$$4, phalcon_mvc_router_exceptions_invalidrouterfactoryconfig_ce);
			ZEPHIR_CALL_METHOD(NULL, &_0$$4, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_0$$4, "phalcon/Mvc/Router/RouterFactory.zep", 52);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(&_1$$3, config, "toarray", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(config, &_1$$3);
	}
	if (Z_TYPE_P(config) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_2$$5);
		object_init_ex(&_2$$5, phalcon_mvc_router_exceptions_invalidrouterfactoryconfig_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$5, "phalcon/Mvc/Router/RouterFactory.zep", 58);
		ZEPHIR_MM_RESTORE();
		return;
	}
	defaultRoutes = 1;
	if (zephir_array_isset_value_string(config, SL("defaultRoutes"))) {
		zephir_memory_observe(&_3$$6);
		zephir_array_fetch_string(&_3$$6, config, SL("defaultRoutes"), PH_NOISY, "phalcon/Mvc/Router/RouterFactory.zep", 63);
		defaultRoutes = zephir_get_boolval(&_3$$6);
	}
	if (defaultRoutes) {
		ZVAL_BOOL(&_4, 1);
	} else {
		ZVAL_BOOL(&_4, 0);
	}
	ZEPHIR_CALL_METHOD(&router, this_ptr, "newinstance", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &router, "loadfromconfig", NULL, 0, config);
	zephir_check_call_status();
	RETURN_CCTOR(&router);
}

/**
 * Returns a bare Router instance.
 *
 * @param bool defaultRoutes
 *
 * @return RouterInterface
 */
PHP_METHOD(Phalcon_Mvc_Router_RouterFactory, newInstance)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *defaultRoutes_param = NULL, _0;
	zend_bool defaultRoutes;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(defaultRoutes)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &defaultRoutes_param);
	if (!defaultRoutes_param) {
		defaultRoutes = 1;
	} else {
		}
	object_init_ex(return_value, phalcon_mvc_router_ce);
	if (defaultRoutes) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

