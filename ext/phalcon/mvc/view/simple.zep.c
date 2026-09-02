
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "Zend/zend_closures.h"
#include "kernel/concat.h"
#include "kernel/file.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * This component allows to render views without hierarchical levels
 *
 *```php
 * use Phalcon\Mvc\View\Simple as View;
 *
 * $view = new View();
 *
 * // Render a view
 * echo $view->render(
 *     "templates/my-view",
 *     [
 *         "some" => $param,
 *     ]
 * );
 *
 * // Or with filename with extension
 * echo $view->render(
 *     "templates/my-view.volt",
 *     [
 *         "parameter" => $here,
 *     ]
 * );
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Simple)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\View, Simple, phalcon, mvc_view_simple, phalcon_di_injectable_ce, phalcon_mvc_view_simple_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("activeRenderPath"), ZEND_ACC_PROTECTED);
	/**
	 * @var EngineInterface[]|false
	 */
	zend_declare_property_bool(phalcon_mvc_view_simple_ce, SL("engines"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var ManagerInterface|null
	 */
	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("eventsManager"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("options"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("viewsDir"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_mvc_view_simple_ce, SL("content"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 *
	 * @todo Use a default [] once Zephir supports array trait defaults
	 */
	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("registeredEngines"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 *
	 * @todo Use a default [] once Zephir supports array trait defaults
	 */
	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("viewParams"), ZEND_ACC_PROTECTED);
	phalcon_mvc_view_simple_ce->create_object = zephir_init_properties_Phalcon_Mvc_View_Simple;

	zend_class_implements(phalcon_mvc_view_simple_ce, 1, phalcon_mvc_viewbaseinterface_ce);
	zend_class_implements(phalcon_mvc_view_simple_ce, 1, phalcon_events_eventsawareinterface_ce);
	zend_class_implements(phalcon_mvc_view_simple_ce, 1, phalcon_contracts_view_renderer_ce);
	return SUCCESS;
}

/**
 * Phalcon\Mvc\View\Simple constructor
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL, _0, _1;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("options", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("registeredEngines", 17, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("viewParams", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &options_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1218, &options);
	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1219, &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1220, &_1);
	ZEPHIR_MM_RESTORE();
}

/**
 * Magic method to retrieve a variable passed to the view
 *
 *```php
 * echo $this->view->products;
 *```
 *
 * @return mixed|null
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, __get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval key_zv, value, _0;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("viewParams", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	zephir_memory_observe(&value);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1220, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&value, &_0, &key_zv, 0))) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(&value);
}

/**
 * Magic method to pass variables to the views
 *
 *```php
 * $this->view->products = $products;
 *```
 *
 * @return void
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, __set)
{
	zval key_zv, *value, value_sub;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&value_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(key)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	value = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR(&key_zv, key);
	zephir_update_property_array(this_ptr, SL("viewParams"), &key_zv, value);
}

/**
 * Returns the path of the view that is currently rendered
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getActiveRenderPath)
{

	RETURN_MEMBER_TYPED(getThis(), "activeRenderPath", IS_STRING);
}

/**
 * Returns the internal event manager
 *
 * @return ManagerInterface|null
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getEventsManager)
{

	RETURN_MEMBER(getThis(), "eventsManager");
}

/**
 * Gets views directory
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getViewsDir)
{

	RETURN_MEMBER_TYPED(getThis(), "viewsDir", IS_STRING);
}

/**
 * Renders a partial view
 *
 * ```php
 * // Show a partial inside another view
 * $this->partial("shared/footer");
 * ```
 *
 * ```php
 * // Show a partial inside another view with parameters
 * $this->partial(
 *     "shared/footer",
 *     [
 *         "content" => $html,
 *     ]
 * );
 * ```
 *
 * @return void
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, partial)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval partialPath_zv, *params = NULL, params_sub, __$null, viewParams, mergedParams, _2, _0$$3, _1$$3;
	zend_string *partialPath = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&partialPath_zv);
	ZVAL_UNDEF(&params_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&viewParams);
	ZVAL_UNDEF(&mergedParams);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("viewParams", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("content", 7, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(partialPath)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(params)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		params = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&partialPath_zv);
	ZVAL_STR_COPY(&partialPath_zv, partialPath);
	if (!params) {
		params = &params_sub;
		params = &__$null;
	}
	ZEPHIR_INIT_VAR(&viewParams);
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(params) == IS_ARRAY) {
		zephir_read_property_cached(&_0$$3, this_ptr, _zephir_prop_0, 1220, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&viewParams, &_0$$3);
		ZEPHIR_INIT_VAR(&mergedParams);
		zephir_fast_array_merge(&mergedParams, &viewParams, params);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CREATE_SYMBOL_TABLE();
		
	} else {
		ZEPHIR_CPY_WRT(&mergedParams, params);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "internalrender", NULL, 0, &partialPath_zv, &mergedParams);
	zephir_check_call_status();
	if (Z_TYPE_P(params) == IS_ARRAY) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1220, &viewParams);
	}
	ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_1, 1221, PH_NOISY_CC | PH_READONLY);
	zend_print_zval(&_2, 0);
	ZEPHIR_MM_RESTORE();
}

/**
 * Register templating engines
 *
 *```php
 * $this->view->registerEngines(
 *     [
 *         ".phtml" => \Phalcon\Mvc\View\Engine\Php::class,
 *         ".volt"  => \Phalcon\Mvc\View\Engine\Volt::class,
 *         ".mhtml" => \MyCustomEngine::class,
 *     ]
 * );
 *```
 *
 * @return void
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, registerEngines)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *engines_param = NULL;
	zval engines;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&engines);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("registeredEngines", 17, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(engines, engines_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &engines_param);
	zephir_get_arrval(&engines, engines_param);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1219, &engines);
	ZEPHIR_MM_RESTORE();
}

/**
 * Renders a view
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, render)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval params;
	zval path_zv, *params_param = NULL, mergedParams, viewParams, _0, _1;
	zend_string *path = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_zv);
	ZVAL_UNDEF(&mergedParams);
	ZVAL_UNDEF(&viewParams);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&params);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("viewParams", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(path)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(params, params_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		params_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&path_zv);
	ZVAL_STR_COPY(&path_zv, path);
	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
		zephir_get_arrval(&params, params_param);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CREATE_SYMBOL_TABLE();
	
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 1220, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&viewParams, &_1);
	ZEPHIR_INIT_VAR(&mergedParams);
	zephir_fast_array_merge(&mergedParams, &viewParams, &params);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "internalrender", NULL, 0, &path_zv, &mergedParams);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_MEMBER_TYPED(getThis(), "content", IS_STRING);
}

/**
 * Sets the events manager
 *
 * @return void
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setEventsManager)
{
	zval *eventsManager, eventsManager_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("eventsManager", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(eventsManager, phalcon_events_managerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &eventsManager);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1222, eventsManager);
}

/**
 * Adds parameters to views (alias of setVar)
 *
 *```php
 * $this->view->setParamToView("products", $products);
 *```
 *
 * @return static
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setParamToView)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, *value, value_sub;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&value_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(key)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	value = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "setvar", NULL, 0, &key_zv, value);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Set all the render params
 *
 *```php
 * $this->view->setVars(
 *     [
 *         "products" => $products,
 *     ]
 * );
 *```
 *
 * @return static
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setVars)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool merge;
	zval *params_param = NULL, *merge_param = NULL, _0$$3, _1$$3;
	zval params;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("viewParams", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(params, params_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(merge)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &params_param, &merge_param);
	zephir_get_arrval(&params, params_param);
	if (!merge_param) {
		merge = 1;
	} else {
		}
	if (merge) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 1220, PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_0$$3, &_1$$3, &params);
		ZEPHIR_CPY_WRT(&params, &_0$$3);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1220, &params);
	RETURN_THIS();
}

/**
 * Sets views directory
 *
 * @return void
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setViewsDir)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval viewsDir_zv, _0;
	zend_string *viewsDir = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewsDir_zv);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("viewsDir", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(viewsDir)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&viewsDir_zv);
	ZVAL_STR_COPY(&viewsDir_zv, viewsDir);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "todirseparator", NULL, 0, &viewsDir_zv);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1223, &_0);
	ZEPHIR_MM_RESTORE();
}

/**
 * Loads registered template engines, if none are registered it will use
 * Phalcon\Mvc\View\Engine\Php
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, loadTemplateEngines)
{
	zval _13$$11, _20$$17;
	zend_class_entry *_10$$9, *_19$$15;
	zend_bool _17$$5;
	zend_string *_8$$5;
	zend_ulong _7$$5;
	zval engines, di, registeredEngines, extension, engineService, engineObject, _0, _1$$3, _2$$4, _3$$6, *_4$$5, _5$$5, *_6$$5, _16$$5, _9$$9, _14$$12, _18$$15, _21$$18, _22$$19;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL, *_12 = NULL, *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&engines);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&registeredEngines);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&engineService);
	ZVAL_UNDEF(&engineObject);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_14$$12);
	ZVAL_UNDEF(&_18$$15);
	ZVAL_UNDEF(&_21$$18);
	ZVAL_UNDEF(&_22$$19);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_20$$17);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("engines", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("container", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("registeredEngines", 17, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&engineObject);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1224, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&engines, &_0);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&engines)) {
		zephir_memory_observe(&di);
		zephir_read_property_cached(&di, this_ptr, _zephir_prop_1, 1225, PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(&engines);
		array_init(&engines);
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_2, 1219, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&registeredEngines, &_1$$3);
		if (ZEPHIR_IS_EMPTY(&registeredEngines)) {
			ZEPHIR_INIT_VAR(&_2$$4);
			object_init_ex(&_2$$4, phalcon_mvc_view_engine_php_ce);
			ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 0, this_ptr, &di);
			zephir_check_call_status();
			zephir_array_update_string(&engines, SL(".phtml"), &_2$$4, PH_COPY | PH_SEPARATE);
		} else {
			if (Z_TYPE_P(&di) != IS_OBJECT) {
				ZEPHIR_INIT_VAR(&_3$$6);
				object_init_ex(&_3$$6, phalcon_mvc_view_exceptions_simpleviewservicesunavailable_ce);
				ZEPHIR_CALL_METHOD(NULL, &_3$$6, "__construct", NULL, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_3$$6, "phalcon/Mvc/View/Simple.zep", 375);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(&registeredEngines) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_5$$5);
				zephir_string_to_char_array(&_5$$5, &registeredEngines);
				_4$$5 = &_5$$5;
			} else {
				_4$$5 = &registeredEngines;
			}
			zephir_is_iterable(_4$$5, 0, "phalcon/Mvc/View/Simple.zep", 406);
			if (Z_TYPE_P(_4$$5) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_4$$5), _7$$5, _8$$5, _6$$5)
				{
					ZEPHIR_INIT_NVAR(&extension);
					if (_8$$5 != NULL) { 
						ZVAL_STR_COPY(&extension, _8$$5);
					} else {
						ZVAL_LONG(&extension, _7$$5);
					}
					ZEPHIR_INIT_NVAR(&engineService);
					ZVAL_COPY(&engineService, _6$$5);
					if (Z_TYPE_P(&engineService) == IS_OBJECT) {
						if (zephir_is_instance_of(&engineService, SL("Closure"))) {
							_10$$9 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
							ZEPHIR_CALL_CE_STATIC(&_9$$9, _10$$9, "bind", &_11, 0, &engineService, &di);
							zephir_check_call_status();
							ZEPHIR_CPY_WRT(&engineService, &_9$$9);
							ZEPHIR_CALL_FUNCTION(&engineObject, "call_user_func", &_12, 82, &engineService, this_ptr);
							zephir_check_call_status();
						} else {
							ZEPHIR_CPY_WRT(&engineObject, &engineService);
						}
					} else if (Z_TYPE_P(&engineService) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_13$$11);
						zephir_create_array(&_13$$11, 1, 0);
						zephir_array_fast_append(&_13$$11, this_ptr);
						ZEPHIR_CALL_METHOD(&engineObject, &di, "getshared", NULL, 0, &engineService, &_13$$11);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_NVAR(&_14$$12);
						object_init_ex(&_14$$12, phalcon_mvc_view_exceptions_invalidengineregistration_ce);
						ZEPHIR_CALL_METHOD(NULL, &_14$$12, "__construct", &_15, 0, &extension);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_14$$12, "phalcon/Mvc/View/Simple.zep", 401);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&engines, &extension, &engineObject, PH_COPY | PH_SEPARATE);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _4$$5, "rewind", NULL, 0);
				zephir_check_call_status();
				_17$$5 = 1;
				while (1) {
					if (_17$$5) {
						_17$$5 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _4$$5, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_16$$5, _4$$5, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_16$$5)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&extension, _4$$5, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&engineService, _4$$5, "current", NULL, 0);
					zephir_check_call_status();
						if (Z_TYPE_P(&engineService) == IS_OBJECT) {
							if (zephir_is_instance_of(&engineService, SL("Closure"))) {
								_19$$15 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
								ZEPHIR_CALL_CE_STATIC(&_18$$15, _19$$15, "bind", &_11, 0, &engineService, &di);
								zephir_check_call_status();
								ZEPHIR_CPY_WRT(&engineService, &_18$$15);
								ZEPHIR_CALL_FUNCTION(&engineObject, "call_user_func", &_12, 82, &engineService, this_ptr);
								zephir_check_call_status();
							} else {
								ZEPHIR_CPY_WRT(&engineObject, &engineService);
							}
						} else if (Z_TYPE_P(&engineService) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_20$$17);
							zephir_create_array(&_20$$17, 1, 0);
							zephir_array_fast_append(&_20$$17, this_ptr);
							ZEPHIR_CALL_METHOD(&engineObject, &di, "getshared", NULL, 0, &engineService, &_20$$17);
							zephir_check_call_status();
						} else {
							ZEPHIR_INIT_NVAR(&_21$$18);
							object_init_ex(&_21$$18, phalcon_mvc_view_exceptions_invalidengineregistration_ce);
							ZEPHIR_CALL_METHOD(NULL, &_21$$18, "__construct", &_15, 0, &extension);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_21$$18, "phalcon/Mvc/View/Simple.zep", 401);
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_update_zval(&engines, &extension, &engineObject, PH_COPY | PH_SEPARATE);
				}
			}
			ZEPHIR_INIT_NVAR(&engineService);
			ZEPHIR_INIT_NVAR(&extension);
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1224, &engines);
	} else {
		zephir_read_property_cached(&_22$$19, this_ptr, _zephir_prop_0, 1224, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&engines, &_22$$19);
	}
	RETURN_CCTOR(&engines);
}

/**
 * Tries to render the view with every engine registered in the component
 *
 * @param string path
 * @param array  params
 *
 * @return void
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, internalRender)
{
	zend_string *_16;
	zend_ulong _15;
	zend_bool notExists = 0, mustClean = 0, _32, _10$$6, _22$$8, _37$$15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_19 = NULL, *_27 = NULL, *_30 = NULL, *_42 = NULL, *_45 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *params, params_sub, eventsManager, engines, extension, engine, segment, segments, _0, _3, _4, _5, _6, *_7, _8, *_9, _11, *_12, _13, *_14, _31, _1$$4, _2$$4, _17$$8, _18$$8, _20$$8, _21$$8, _23$$8, _28$$8, _24$$9, _25$$12, _26$$12, _29$$14, _33$$15, _34$$15, _35$$15, _36$$15, _38$$15, _43$$15, _39$$16, _40$$19, _41$$19, _44$$21, _46$$22, _47$$23;
	zval path, viewEnginePath, viewsDirPath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&viewEnginePath);
	ZVAL_UNDEF(&viewsDirPath);
	ZVAL_UNDEF(&params_sub);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&engines);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&engine);
	ZVAL_UNDEF(&segment);
	ZVAL_UNDEF(&segments);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_28$$8);
	ZVAL_UNDEF(&_24$$9);
	ZVAL_UNDEF(&_25$$12);
	ZVAL_UNDEF(&_26$$12);
	ZVAL_UNDEF(&_29$$14);
	ZVAL_UNDEF(&_33$$15);
	ZVAL_UNDEF(&_34$$15);
	ZVAL_UNDEF(&_35$$15);
	ZVAL_UNDEF(&_36$$15);
	ZVAL_UNDEF(&_38$$15);
	ZVAL_UNDEF(&_43$$15);
	ZVAL_UNDEF(&_39$$16);
	ZVAL_UNDEF(&_40$$19);
	ZVAL_UNDEF(&_41$$19);
	ZVAL_UNDEF(&_44$$21);
	ZVAL_UNDEF(&_46$$22);
	ZVAL_UNDEF(&_47$$23);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("eventsManager", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("activeRenderPath", 16, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("viewsDir", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(path_param)
		Z_PARAM_ZVAL(params)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &path_param, &params);
	zephir_get_strval(&path, path_param);
	ZEPHIR_INIT_VAR(&viewEnginePath);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1222, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_0);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1226, &path);
	}
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "view:beforeRender");
		ZEPHIR_CALL_METHOD(&_1$$4, &eventsManager, "fire", NULL, 0, &_2$$4, this_ptr);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_1$$4)) {
			RETURN_MM_NULL();
		}
	}
	notExists = 1;
	mustClean = 1;
	ZEPHIR_INIT_VAR(&segments);
	array_init(&segments);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "\\");
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "/");
	zephir_fast_str_replace(&_4, &_5, &_6, &path);
	zephir_fast_explode_str(&_3, SL("/"), &_4, LONG_MAX);
	if (Z_TYPE_P(&_3) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_8);
		zephir_string_to_char_array(&_8, &_3);
		_7 = &_8;
	} else {
		_7 = &_3;
	}
	zephir_is_iterable(_7, 0, "phalcon/Mvc/View/Simple.zep", 461);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_7), _9)
	{
		ZEPHIR_INIT_NVAR(&segment);
		ZVAL_COPY(&segment, _9);
		_10$$6 = !ZEPHIR_IS_STRING_IDENTICAL(&segment, ".");
		if (_10$$6) {
			_10$$6 = !ZEPHIR_IS_STRING_IDENTICAL(&segment, "..");
		}
		if (_10$$6) {
			zephir_array_append(&segments, &segment, PH_SEPARATE, "phalcon/Mvc/View/Simple.zep", 457);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&segment);
	ZEPHIR_INIT_NVAR(&path);
	zephir_fast_join_str(&path, SL("/"), &segments);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 1223, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_11);
	ZEPHIR_CONCAT_VV(&_11, &_0, &path);
	zephir_get_strval(&viewsDirPath, &_11);
	ZEPHIR_CALL_METHOD(&engines, this_ptr, "loadtemplateengines", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&engines) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_13);
		zephir_string_to_char_array(&_13, &engines);
		_12 = &_13;
	} else {
		_12 = &engines;
	}
	zephir_is_iterable(_12, 0, "phalcon/Mvc/View/Simple.zep", 512);
	if (Z_TYPE_P(_12) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_12), _15, _16, _14)
		{
			ZEPHIR_INIT_NVAR(&extension);
			if (_16 != NULL) { 
				ZVAL_STR_COPY(&extension, _16);
			} else {
				ZVAL_LONG(&extension, _15);
			}
			ZEPHIR_INIT_NVAR(&engine);
			ZVAL_COPY(&engine, _14);
			ZEPHIR_INIT_NVAR(&_18$$8);
			ZEPHIR_CONCAT_VV(&_18$$8, &viewsDirPath, &extension);
			ZEPHIR_CALL_METHOD(&_17$$8, this_ptr, "phpfileexists", &_19, 0, &_18$$8);
			zephir_check_call_status();
			if (zephir_is_true(&_17$$8)) {
				ZEPHIR_INIT_NVAR(&_24$$9);
				ZEPHIR_CONCAT_VV(&_24$$9, &viewsDirPath, &extension);
				zephir_get_strval(&viewEnginePath, &_24$$9);
			} else {
				ZVAL_LONG(&_20$$8, -zephir_fast_strlen_ev(&extension));
				ZEPHIR_INIT_NVAR(&_21$$8);
				zephir_substr(&_21$$8, &viewsDirPath, zephir_get_intval(&_20$$8), 0, ZEPHIR_SUBSTR_NO_LENGTH);
				_22$$8 = ZEPHIR_IS_EQUAL(&_21$$8, &extension);
				if (_22$$8) {
					ZEPHIR_CALL_METHOD(&_23$$8, this_ptr, "phpfileexists", &_19, 0, &viewsDirPath);
					zephir_check_call_status();
					_22$$8 = zephir_is_true(&_23$$8);
				}
				if (_22$$8) {
					ZEPHIR_CPY_WRT(&viewEnginePath, &viewsDirPath);
				} else {
					continue;
				}
			}
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(&_26$$12);
				ZVAL_STRING(&_26$$12, "view:beforeRenderView");
				ZEPHIR_CALL_METHOD(&_25$$12, &eventsManager, "fire", &_27, 0, &_26$$12, this_ptr, &viewEnginePath);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_25$$12)) {
					continue;
				}
			}
			if (mustClean) {
				ZVAL_BOOL(&_28$$8, 1);
			} else {
				ZVAL_BOOL(&_28$$8, 0);
			}
			ZEPHIR_CALL_METHOD(NULL, &engine, "render", NULL, 0, &viewEnginePath, params, &_28$$8);
			zephir_check_call_status();
			notExists = 0;
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(&_29$$14);
				ZVAL_STRING(&_29$$14, "view:afterRenderView");
				ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_30, 0, &_29$$14, this_ptr);
				zephir_check_call_status();
			}
			break;
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _12, "rewind", NULL, 0);
		zephir_check_call_status();
		_32 = 1;
		while (1) {
			if (_32) {
				_32 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _12, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_31, _12, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_31)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&extension, _12, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&engine, _12, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_34$$15);
				ZEPHIR_CONCAT_VV(&_34$$15, &viewsDirPath, &extension);
				ZEPHIR_CALL_METHOD(&_33$$15, this_ptr, "phpfileexists", &_19, 0, &_34$$15);
				zephir_check_call_status();
				if (zephir_is_true(&_33$$15)) {
					ZEPHIR_INIT_NVAR(&_39$$16);
					ZEPHIR_CONCAT_VV(&_39$$16, &viewsDirPath, &extension);
					zephir_get_strval(&viewEnginePath, &_39$$16);
				} else {
					ZVAL_LONG(&_35$$15, -zephir_fast_strlen_ev(&extension));
					ZEPHIR_INIT_NVAR(&_36$$15);
					zephir_substr(&_36$$15, &viewsDirPath, zephir_get_intval(&_35$$15), 0, ZEPHIR_SUBSTR_NO_LENGTH);
					_37$$15 = ZEPHIR_IS_EQUAL(&_36$$15, &extension);
					if (_37$$15) {
						ZEPHIR_CALL_METHOD(&_38$$15, this_ptr, "phpfileexists", &_19, 0, &viewsDirPath);
						zephir_check_call_status();
						_37$$15 = zephir_is_true(&_38$$15);
					}
					if (_37$$15) {
						ZEPHIR_CPY_WRT(&viewEnginePath, &viewsDirPath);
					} else {
						continue;
					}
				}
				if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&_41$$19);
					ZVAL_STRING(&_41$$19, "view:beforeRenderView");
					ZEPHIR_CALL_METHOD(&_40$$19, &eventsManager, "fire", &_42, 0, &_41$$19, this_ptr, &viewEnginePath);
					zephir_check_call_status();
					if (ZEPHIR_IS_FALSE_IDENTICAL(&_40$$19)) {
						continue;
					}
				}
				if (mustClean) {
					ZVAL_BOOL(&_43$$15, 1);
				} else {
					ZVAL_BOOL(&_43$$15, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, &engine, "render", NULL, 0, &viewEnginePath, params, &_43$$15);
				zephir_check_call_status();
				notExists = 0;
				if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&_44$$21);
					ZVAL_STRING(&_44$$21, "view:afterRenderView");
					ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_45, 0, &_44$$21, this_ptr);
					zephir_check_call_status();
				}
				break;
		}
	}
	ZEPHIR_INIT_NVAR(&engine);
	ZEPHIR_INIT_NVAR(&extension);
	if (notExists) {
		ZEPHIR_INIT_VAR(&_46$$22);
		object_init_ex(&_46$$22, phalcon_mvc_view_exceptions_simpleviewnotfound_ce);
		ZEPHIR_CALL_METHOD(NULL, &_46$$22, "__construct", NULL, 0, &viewsDirPath);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_46$$22, "phalcon/Mvc/View/Simple.zep", 513);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_47$$23);
		ZVAL_STRING(&_47$$23, "view:afterRender");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_47$$23, this_ptr);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * @param string $directory
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, toDirSeparator)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval directory_zv, _0, _1;
	zend_string *directory = NULL;

	ZVAL_UNDEF(&directory_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(directory)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&directory_zv);
	ZVAL_STR_COPY(&directory_zv, directory);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/");
	zephir_fast_trim(&_0, &directory_zv, &_1, ZEPHIR_TRIM_RIGHT);
	ZEPHIR_CONCAT_VS(return_value, &_0, "/");
	RETURN_MM();
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
PHP_METHOD(Phalcon_Mvc_View_Simple, phpFclose)
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
PHP_METHOD(Phalcon_Mvc_View_Simple, phpFgetCsv)
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
	ZEPHIR_RETURN_CALL_FUNCTION("fgetcsv", NULL, 161, stream, &_0, &separator_zv, enclosure, escape);
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
PHP_METHOD(Phalcon_Mvc_View_Simple, phpFileExists)
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
PHP_METHOD(Phalcon_Mvc_View_Simple, phpFileGetContents)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long offset, length, ZEPHIR_LAST_CALL_STATUS;
	zend_bool useIncludePath;
	zval filename_zv, *useIncludePath_param = NULL, *context = NULL, context_sub, *offset_param = NULL, *length_param = NULL, __$null, _0$$3, _1$$3, _2, _3, _4;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
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
		ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", NULL, 162, &filename_zv, &_0$$3, context, &_1$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZVAL_BOOL(&_2, (useIncludePath ? 1 : 0));
	ZVAL_LONG(&_3, offset);
	ZVAL_LONG(&_4, length);
	ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", NULL, 162, &filename_zv, &_2, context, &_3, &_4);
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
PHP_METHOD(Phalcon_Mvc_View_Simple, phpFilePutContents)
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
	ZEPHIR_RETURN_CALL_FUNCTION("file_put_contents", NULL, 163, &filename_zv, data, &_0, context);
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
PHP_METHOD(Phalcon_Mvc_View_Simple, phpFopen)
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
	ZEPHIR_RETURN_CALL_FUNCTION("fopen", NULL, 164, &filename_zv, &mode_zv, &_0, context);
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
PHP_METHOD(Phalcon_Mvc_View_Simple, phpFwrite)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	ZEPHIR_RETURN_CALL_FUNCTION("fwrite", NULL, 165, handle, &data_zv, &_0);
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
PHP_METHOD(Phalcon_Mvc_View_Simple, phpIsWritable)
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
 * @param string        $filename
 * @param resource|null $context
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.unlink.php
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, phpUnlink)
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
	ZEPHIR_RETURN_CALL_FUNCTION("unlink", NULL, 167, &filename_zv, context);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns output from another view stage
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getContent)
{

	RETURN_MEMBER_TYPED(getThis(), "content", IS_STRING);
}

/**
 * Returns parameters to views
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getParamsToView)
{
	zval _1;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("viewParams", 10, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1220, PH_NOISY_CC);
	zephir_get_arrval(&_1, &_0);
	RETURN_CTOR(&_1);
}

/**
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getRegisteredEngines)
{
	zval _1;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("registeredEngines", 17, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1219, PH_NOISY_CC);
	zephir_get_arrval(&_1, &_0);
	RETURN_CTOR(&_1);
}

/**
 * Returns a parameter previously set in the view
 *
 * @return mixed|null
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getVar)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval key_zv, value, _0;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("viewParams", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	zephir_memory_observe(&value);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1220, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&value, &_0, &key_zv, 0))) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(&value);
}

/**
 * Externally sets the view content
 *
 *```php
 * $this->view->setContent("<h1>hello</h1>");
 *```
 *
 * @return static
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setContent)
{
	zval content_zv;
	zend_string *content = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("content", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(content)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&content_zv, content);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1221, &content_zv);
	RETURN_THISW();
}

/**
 * Set a single view parameter
 *
 *```php
 * $this->view->setVar("products", $products);
 *```
 *
 * @return static
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setVar)
{
	zval key_zv, *value, value_sub;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&value_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(key)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	value = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR(&key_zv, key);
	zephir_update_property_array(this_ptr, SL("viewParams"), &key_zv, value);
	RETURN_THISW();
}

zend_object *zephir_init_properties_Phalcon_Mvc_View_Simple(zend_class_entry *class_type)
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
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("options"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

