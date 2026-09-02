
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
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "Zend/zend_closures.h"
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
 * Phalcon\Mvc\View is a class for working with the "view" portion of the
 * model-view-controller pattern. That is, it exists to help keep the view
 * script separate from the model and controller scripts. It provides a system
 * of helpers, output filters, and variable escaping.
 *
 * ```php
 * use Phalcon\Mvc\View;
 *
 * $view = new View();
 *
 * // Setting views directory
 * $view->setViewsDir("app/views/");
 *
 * $view->start();
 *
 * // Shows recent posts view (app/views/posts/recent.phtml)
 * $view->render("posts", "recent");
 * $view->finish();
 *
 * // Printing views output
 * echo $view->getContent();
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_View)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc, View, phalcon, mvc_view, phalcon_di_injectable_ce, phalcon_mvc_view_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_mvc_view_ce, SL("actionName"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_view_ce, SL("activeRenderPaths"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_mvc_view_ce, SL("basePath"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_mvc_view_ce, SL("controllerName"), ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_mvc_view_ce, SL("currentRenderLevel"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_mvc_view_ce, SL("disabled"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_view_ce, SL("disabledLevels"), ZEND_ACC_PROTECTED);
	/**
	 * @var array|bool
	 */
	zend_declare_property_bool(phalcon_mvc_view_ce, SL("engines"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var ManagerInterface|null
	 */
	zend_declare_property_null(phalcon_mvc_view_ce, SL("eventsManager"), ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_mvc_view_ce, SL("layout"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_mvc_view_ce, SL("layoutsDir"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_mvc_view_ce, SL("mainView"), "index", ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_view_ce, SL("options"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_view_ce, SL("params"), ZEND_ACC_PROTECTED);
	/**
	 * @var array|null
	 */
	zend_declare_property_null(phalcon_mvc_view_ce, SL("pickView"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_mvc_view_ce, SL("partialsDir"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_mvc_view_ce, SL("renderLevel"), 5, ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_view_ce, SL("templatesAfter"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_view_ce, SL("templatesBefore"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_view_ce, SL("viewsDirs"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_mvc_view_ce, SL("content"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 *
	 * @todo Use a default [] once Zephir supports array trait defaults
	 */
	zend_declare_property_null(phalcon_mvc_view_ce, SL("registeredEngines"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 *
	 * @todo Use a default [] once Zephir supports array trait defaults
	 */
	zend_declare_property_null(phalcon_mvc_view_ce, SL("viewParams"), ZEND_ACC_PROTECTED);
	phalcon_mvc_view_ce->create_object = zephir_init_properties_Phalcon_Mvc_View;
	/**
	 * Render Level: To the action view
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_ACTION_VIEW"), 1);

	/**
	 * Render Level: To the templates "before"
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_BEFORE_TEMPLATE"), 2);

	/**
	 * Render Level: To the controller layout
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_LAYOUT"), 3);

	/**
	 * Render Level: To the main layout
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_MAIN_LAYOUT"), 5);

	/**
	 * Render Level: No render any view
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_NO_RENDER"), 0);

	/**
	 * Render Level: Render to the templates "after"
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_AFTER_TEMPLATE"), 4);

	zend_class_implements(phalcon_mvc_view_ce, 1, phalcon_mvc_viewinterface_ce);
	zend_class_implements(phalcon_mvc_view_ce, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\Mvc\View constructor
 */
PHP_METHOD(Phalcon_Mvc_View, __construct)
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1167, &options);
	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1168, &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1169, &_1);
	ZEPHIR_MM_RESTORE();
}

/**
 * Magic method to retrieve a variable passed to the view
 *
 *```php
 * echo $this->view->products;
 *```
 */
PHP_METHOD(Phalcon_Mvc_View, __get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getvar", NULL, 0, &key_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Magic method to retrieve if a variable is set in the view
 *
 *```php
 * echo isset($this->view->products);
 *```
 */
PHP_METHOD(Phalcon_Mvc_View, __isset)
{
	zval key_zv, _0;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("viewParams", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&key_zv, key);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1169, PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset_value(&_0, &key_zv));
}

/**
 * Magic method to pass variables to the views
 *
 *```php
 * $this->view->products = $products;
 *```
 */
PHP_METHOD(Phalcon_Mvc_View, __set)
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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setvar", NULL, 0, &key_zv, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Resets any template before layouts
 */
PHP_METHOD(Phalcon_Mvc_View, cleanTemplateAfter)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("templatesAfter", 14, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1170, &_0);
	RETURN_THIS();
}

/**
 * Resets any "template before" layouts
 */
PHP_METHOD(Phalcon_Mvc_View, cleanTemplateBefore)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("templatesBefore", 15, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1171, &_0);
	RETURN_THIS();
}

/**
 * Disables the auto-rendering process
 */
PHP_METHOD(Phalcon_Mvc_View, disable)
{
	zval __$true, __$false;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("disabled", 8, 1);
	}
	if (1) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1172, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1172, &__$false);
	}
	RETURN_THISW();
}

/**
 * Disables a specific level of rendering
 *
 *```php
 * // Render all levels except ACTION level
 * $this->view->disableLevel(
 *     View::LEVEL_ACTION_VIEW
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_View, disableLevel)
{
	zval *level, level_sub, __$true;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&level_sub);
	ZVAL_BOOL(&__$true, 1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("disabledLevels", 14, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(level)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &level);
	if (Z_TYPE_P(level) == IS_ARRAY) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1173, level);
	} else {
		zephir_update_property_array(this_ptr, SL("disabledLevels"), level, &__$true);
	}
	RETURN_THISW();
}

/**
 * Enables the auto-rendering process
 */
PHP_METHOD(Phalcon_Mvc_View, enable)
{
	zval __$true, __$false;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("disabled", 8, 1);
	}
	if (0) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1172, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1172, &__$false);
	}
	RETURN_THISW();
}

/**
 * Checks whether view exists
 * @deprecated
 */
PHP_METHOD(Phalcon_Mvc_View, exists)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval view_zv;
	zend_string *view = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&view_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(view)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&view_zv);
	ZVAL_STR_COPY(&view_zv, view);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, &view_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Finishes the render process by stopping the output buffering
 */
PHP_METHOD(Phalcon_Mvc_View, finish)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 0);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Gets the name of the action rendered
 */
PHP_METHOD(Phalcon_Mvc_View, getActionName)
{

	RETURN_MEMBER_TYPED(getThis(), "actionName", IS_STRING);
}

/**
 * Returns the path (or paths) of the views that are currently rendered
 */
PHP_METHOD(Phalcon_Mvc_View, getActiveRenderPath)
{
	zval activeRenderPath, _0$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&activeRenderPath);
	ZVAL_UNDEF(&_0$$4);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("activeRenderPaths", 17, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&activeRenderPath);
	zephir_read_property_cached(&activeRenderPath, this_ptr, _zephir_prop_0, 1174, PH_NOISY_CC);
	if (Z_TYPE_P(&activeRenderPath) == IS_ARRAY) {
		if (zephir_fast_count_int(&activeRenderPath) == 1) {
			zephir_array_fetch_long(&_0$$4, &activeRenderPath, 0, PH_NOISY | PH_READONLY, "phalcon/Mvc/View.zep", 346);
			ZEPHIR_CPY_WRT(&activeRenderPath, &_0$$4);
		} else if (ZEPHIR_IS_EMPTY(&activeRenderPath)) {
			ZEPHIR_INIT_NVAR(&activeRenderPath);
			ZVAL_STRING(&activeRenderPath, "");
		}
	}
	if (Z_TYPE_P(&activeRenderPath) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&activeRenderPath);
		ZVAL_STRING(&activeRenderPath, "");
	}
	RETURN_CCTOR(&activeRenderPath);
}

/**
 * Gets base path
 */
PHP_METHOD(Phalcon_Mvc_View, getBasePath)
{

	RETURN_MEMBER_TYPED(getThis(), "basePath", IS_STRING);
}

/**
 * Gets the name of the controller rendered
 */
PHP_METHOD(Phalcon_Mvc_View, getControllerName)
{

	RETURN_MEMBER_TYPED(getThis(), "controllerName", IS_STRING);
}

/**
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_View, getCurrentRenderLevel)
{

	RETURN_MEMBER_TYPED(getThis(), "currentRenderLevel", IS_LONG);
}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Mvc_View, getEventsManager)
{

	RETURN_MEMBER(getThis(), "eventsManager");
}

/**
 * Returns the name of the main view
 */
PHP_METHOD(Phalcon_Mvc_View, getLayout)
{

	RETURN_MEMBER(getThis(), "layout");
}

/**
 * Gets the current layouts sub-directory
 */
PHP_METHOD(Phalcon_Mvc_View, getLayoutsDir)
{

	RETURN_MEMBER_TYPED(getThis(), "layoutsDir", IS_STRING);
}

/**
 * Returns the name of the main view
 */
PHP_METHOD(Phalcon_Mvc_View, getMainView)
{

	RETURN_MEMBER_TYPED(getThis(), "mainView", IS_STRING);
}

/**
 * Renders a partial view
 *
 * ```php
 * // Retrieve the contents of a partial
 * echo $this->getPartial("shared/footer");
 * ```
 *
 * ```php
 * // Retrieve the contents of a partial with arguments
 * echo $this->getPartial(
 *     "shared/footer",
 *     [
 *         "content" => $html,
 *     ]
 * );
 * ```
 */
PHP_METHOD(Phalcon_Mvc_View, getPartial)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval partialPath_zv, *params = NULL, params_sub, __$null;
	zend_string *partialPath = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&partialPath_zv);
	ZVAL_UNDEF(&params_sub);
	ZVAL_NULL(&__$null);
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
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "partial", NULL, 0, &partialPath_zv, params);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets the current partials sub-directory
 */
PHP_METHOD(Phalcon_Mvc_View, getPartialsDir)
{

	RETURN_MEMBER_TYPED(getThis(), "partialsDir", IS_STRING);
}

/**
 * Perform the automatic rendering returning the output as a string
 *
 * ```php
 * $template = $this->view->getRender(
 *     "products",
 *     "show",
 *     [
 *         "products" => $products,
 *     ]
 * );
 * ```
 *
 * @param mixed configCallback
 */
PHP_METHOD(Phalcon_Mvc_View, getRender)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval params, _1$$3;
	zval controllerName_zv, actionName_zv, *params_param = NULL, *configCallback = NULL, configCallback_sub, __$null, view, _0$$3;
	zend_string *controllerName = NULL, *actionName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&controllerName_zv);
	ZVAL_UNDEF(&actionName_zv);
	ZVAL_UNDEF(&configCallback_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&view);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_1$$3);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(controllerName)
		Z_PARAM_STR(actionName)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(params, params_param)
		Z_PARAM_ZVAL_OR_NULL(configCallback)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		params_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		configCallback = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&controllerName_zv);
	ZVAL_STR_COPY(&controllerName_zv, controllerName);
	zephir_memory_observe(&actionName_zv);
	ZVAL_STR_COPY(&actionName_zv, actionName);
	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
		zephir_get_arrval(&params, params_param);
	}
	if (!configCallback) {
		configCallback = &configCallback_sub;
		configCallback = &__$null;
	}
	ZEPHIR_INIT_VAR(&view);
	if (zephir_clone(&view, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(NULL, &view, "reset", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &view, "setvars", NULL, 0, &params);
	zephir_check_call_status();
	if (Z_TYPE_P(configCallback) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 1, 0);
		zephir_array_fast_append(&_1$$3, &view);
		ZEPHIR_CALL_USER_FUNC_ARRAY(&_0$$3, configCallback, &_1$$3);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, &view, "start", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &view, "render", NULL, 0, &controllerName_zv, &actionName_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &view, "finish", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&view, "getcontent", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_View, getRenderLevel)
{

	RETURN_MEMBER_TYPED(getThis(), "renderLevel", IS_LONG);
}

/**
 * Gets views directory
 */
PHP_METHOD(Phalcon_Mvc_View, getViewsDir)
{

	RETURN_MEMBER(getThis(), "viewsDirs");
}

/**
 * Checks whether view exists
 */
PHP_METHOD(Phalcon_Mvc_View, has)
{
	zend_ulong _10$$4, _25$$9;
	zend_bool _20, _16$$4, _30$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval view_zv, basePath, viewsDir, engines, extension, _0, _2, *_3, _4, *_5, _19, _1$$3, *_6$$4, _7$$4, _8$$4, *_9$$4, _15$$4, _12$$5, _13$$5, _17$$7, _18$$7, *_21$$9, _22$$9, _23$$9, *_24$$9, _29$$9, _27$$10, _28$$10, _31$$12, _32$$12;
	zend_string *view = NULL, *_11$$4, *_26$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&view_zv);
	ZVAL_UNDEF(&basePath);
	ZVAL_UNDEF(&viewsDir);
	ZVAL_UNDEF(&engines);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_29$$9);
	ZVAL_UNDEF(&_27$$10);
	ZVAL_UNDEF(&_28$$10);
	ZVAL_UNDEF(&_31$$12);
	ZVAL_UNDEF(&_32$$12);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("basePath", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("registeredEngines", 17, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(view)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&view_zv);
	ZVAL_STR_COPY(&view_zv, view);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1175, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&basePath, &_0);
	zephir_memory_observe(&engines);
	zephir_read_property_cached(&engines, this_ptr, _zephir_prop_1, 1168, PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&engines)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 1, 0);
		add_assoc_stringl_ex(&_1$$3, SL(".phtml"), SL("Phalcon\\Mvc\\View\\Engine\\Php"));
		ZEPHIR_CPY_WRT(&engines, &_1$$3);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerengines", NULL, 0, &engines);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getviewsdirs", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&_2) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_4);
		zephir_string_to_char_array(&_4, &_2);
		_3 = &_4;
	} else {
		_3 = &_2;
	}
	zephir_is_iterable(_3, 0, "phalcon/Mvc/View.zep", 556);
	if (Z_TYPE_P(_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_3), _5)
		{
			ZEPHIR_INIT_NVAR(&viewsDir);
			ZVAL_COPY(&viewsDir, _5);
			if (Z_TYPE_P(&engines) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_7$$4);
				zephir_string_to_char_array(&_7$$4, &engines);
				_6$$4 = &_7$$4;
			} else {
				_6$$4 = &engines;
			}
			ZEPHIR_INIT_NVAR(&_8$$4);
			zephir_is_iterable(_6$$4, 0, "phalcon/Mvc/View.zep", 554);
			if (Z_TYPE_P(_6$$4) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_6$$4), _10$$4, _11$$4, _9$$4)
				{
					ZEPHIR_INIT_NVAR(&extension);
					if (_11$$4 != NULL) { 
						ZVAL_STR_COPY(&extension, _11$$4);
					} else {
						ZVAL_LONG(&extension, _10$$4);
					}
					ZEPHIR_INIT_NVAR(&_8$$4);
					ZVAL_COPY(&_8$$4, _9$$4);
					ZEPHIR_INIT_NVAR(&_13$$5);
					ZEPHIR_CONCAT_VVVV(&_13$$5, &basePath, &viewsDir, &view_zv, &extension);
					ZEPHIR_CALL_METHOD(&_12$$5, this_ptr, "phpfileexists", &_14, 0, &_13$$5);
					zephir_check_call_status();
					if (zephir_is_true(&_12$$5)) {
						RETURN_MM_BOOL(1);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _6$$4, "rewind", NULL, 0);
				zephir_check_call_status();
				_16$$4 = 1;
				while (1) {
					if (_16$$4) {
						_16$$4 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _6$$4, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_15$$4, _6$$4, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_15$$4)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&extension, _6$$4, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_8$$4, _6$$4, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_18$$7);
						ZEPHIR_CONCAT_VVVV(&_18$$7, &basePath, &viewsDir, &view_zv, &extension);
						ZEPHIR_CALL_METHOD(&_17$$7, this_ptr, "phpfileexists", &_14, 0, &_18$$7);
						zephir_check_call_status();
						if (zephir_is_true(&_17$$7)) {
							RETURN_MM_BOOL(1);
						}
				}
			}
			ZEPHIR_INIT_NVAR(&_8$$4);
			ZEPHIR_INIT_NVAR(&extension);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _3, "rewind", NULL, 0);
		zephir_check_call_status();
		_20 = 1;
		while (1) {
			if (_20) {
				_20 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _3, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_19, _3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_19)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&viewsDir, _3, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&engines) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_22$$9);
					zephir_string_to_char_array(&_22$$9, &engines);
					_21$$9 = &_22$$9;
				} else {
					_21$$9 = &engines;
				}
				ZEPHIR_INIT_NVAR(&_23$$9);
				zephir_is_iterable(_21$$9, 0, "phalcon/Mvc/View.zep", 554);
				if (Z_TYPE_P(_21$$9) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_21$$9), _25$$9, _26$$9, _24$$9)
					{
						ZEPHIR_INIT_NVAR(&extension);
						if (_26$$9 != NULL) { 
							ZVAL_STR_COPY(&extension, _26$$9);
						} else {
							ZVAL_LONG(&extension, _25$$9);
						}
						ZEPHIR_INIT_NVAR(&_23$$9);
						ZVAL_COPY(&_23$$9, _24$$9);
						ZEPHIR_INIT_NVAR(&_28$$10);
						ZEPHIR_CONCAT_VVVV(&_28$$10, &basePath, &viewsDir, &view_zv, &extension);
						ZEPHIR_CALL_METHOD(&_27$$10, this_ptr, "phpfileexists", &_14, 0, &_28$$10);
						zephir_check_call_status();
						if (zephir_is_true(&_27$$10)) {
							RETURN_MM_BOOL(1);
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _21$$9, "rewind", NULL, 0);
					zephir_check_call_status();
					_30$$9 = 1;
					while (1) {
						if (_30$$9) {
							_30$$9 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _21$$9, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_29$$9, _21$$9, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_29$$9)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&extension, _21$$9, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_23$$9, _21$$9, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_32$$12);
							ZEPHIR_CONCAT_VVVV(&_32$$12, &basePath, &viewsDir, &view_zv, &extension);
							ZEPHIR_CALL_METHOD(&_31$$12, this_ptr, "phpfileexists", &_14, 0, &_32$$12);
							zephir_check_call_status();
							if (zephir_is_true(&_31$$12)) {
								RETURN_MM_BOOL(1);
							}
					}
				}
				ZEPHIR_INIT_NVAR(&_23$$9);
				ZEPHIR_INIT_NVAR(&extension);
		}
	}
	ZEPHIR_INIT_NVAR(&viewsDir);
	RETURN_MM_BOOL(0);
}

/**
 * Whether automatic rendering is enabled
 */
PHP_METHOD(Phalcon_Mvc_View, isDisabled)
{

	RETURN_MEMBER(getThis(), "disabled");
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
 */
PHP_METHOD(Phalcon_Mvc_View, partial)
{
	zend_bool _10$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *partialPath_param = NULL, *params = NULL, params_sub, __$null, viewParams, segment, segments, _3, _4, _5, _6, *_7, _8, *_9, _11, _12, _13, _14, _15, _0$$3, _1$$3, _2$$3;
	zval partialPath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&partialPath);
	ZVAL_UNDEF(&params_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&viewParams);
	ZVAL_UNDEF(&segment);
	ZVAL_UNDEF(&segments);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("viewParams", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("partialsDir", 11, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(partialPath_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(params)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &partialPath_param, &params);
	zephir_get_strval(&partialPath, partialPath_param);
	if (!params) {
		params = &params_sub;
		params = &__$null;
	}
	ZEPHIR_INIT_VAR(&viewParams);
	if (Z_TYPE_P(params) == IS_ARRAY) {
		zephir_read_property_cached(&_0$$3, this_ptr, _zephir_prop_0, 1169, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&viewParams, &_0$$3);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_fast_array_merge(&_1$$3, &viewParams, params);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1169, &_1$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CREATE_SYMBOL_TABLE();
		
	}
	ZEPHIR_INIT_VAR(&segments);
	array_init(&segments);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "\\");
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "/");
	zephir_fast_str_replace(&_4, &_5, &_6, &partialPath);
	zephir_fast_explode_str(&_3, SL("/"), &_4, LONG_MAX);
	if (Z_TYPE_P(&_3) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_8);
		zephir_string_to_char_array(&_8, &_3);
		_7 = &_8;
	} else {
		_7 = &_3;
	}
	zephir_is_iterable(_7, 0, "phalcon/Mvc/View.zep", 626);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_7), _9)
	{
		ZEPHIR_INIT_NVAR(&segment);
		ZVAL_COPY(&segment, _9);
		_10$$4 = !ZEPHIR_IS_STRING_IDENTICAL(&segment, ".");
		if (_10$$4) {
			_10$$4 = !ZEPHIR_IS_STRING_IDENTICAL(&segment, "..");
		}
		if (_10$$4) {
			zephir_array_append(&segments, &segment, PH_SEPARATE, "phalcon/Mvc/View.zep", 622);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&segment);
	ZEPHIR_INIT_NVAR(&partialPath);
	zephir_fast_join_str(&partialPath, SL("/"), &segments);
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "loadtemplateengines", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_12, this_ptr, _zephir_prop_1, 1176, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_13);
	ZEPHIR_CONCAT_VV(&_13, &_12, &partialPath);
	ZVAL_BOOL(&_14, 0);
	ZVAL_BOOL(&_15, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "enginerender", NULL, 0, &_11, &_13, &_14, &_15);
	zephir_check_call_status();
	if (Z_TYPE_P(params) == IS_ARRAY) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1169, &viewParams);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Choose a different view to render instead of last-controller/last-action
 *
 * ```php
 * use Phalcon\Mvc\Controller;
 *
 * class ProductsController extends Controller
 * {
 *     public function saveAction()
 *     {
 *         // Do some save stuff...
 *
 *         // Then show the list view
 *         $this->view->pick("products/list");
 *     }
 * }
 * ```
 */
PHP_METHOD(Phalcon_Mvc_View, pick)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *renderView, renderView_sub, pickView, layout, parts, _0$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&renderView_sub);
	ZVAL_UNDEF(&pickView);
	ZVAL_UNDEF(&layout);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&_0$$4);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("pickView", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(renderView)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &renderView);
	if (Z_TYPE_P(renderView) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&pickView, renderView);
	} else {
		ZEPHIR_INIT_VAR(&layout);
		ZVAL_NULL(&layout);
		if (zephir_memnstr_str(renderView, SL("/"), "phalcon/Mvc/View.zep", 673)) {
			ZEPHIR_INIT_VAR(&parts);
			zephir_fast_explode_str(&parts, SL("/"), renderView, LONG_MAX);
			ZEPHIR_OBS_NVAR(&layout);
			zephir_array_fetch_long(&layout, &parts, 0, PH_NOISY, "phalcon/Mvc/View.zep", 675);
		}
		ZEPHIR_INIT_VAR(&_0$$4);
		zephir_create_array(&_0$$4, 1, 0);
		zephir_array_fast_append(&_0$$4, renderView);
		ZEPHIR_CPY_WRT(&pickView, &_0$$4);
		if (Z_TYPE_P(&layout) != IS_NULL) {
			zephir_array_append(&pickView, &layout, PH_SEPARATE, "phalcon/Mvc/View.zep", 681);
		}
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1177, &pickView);
	RETURN_THIS();
}

/**
 * Processes the view and templates; Fires events if needed
 */
PHP_METHOD(Phalcon_Mvc_View, processRender)
{
	zval _3$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, renderLevel = 0;
	zend_bool fireEvents, silence = 0, _5, _36, _18$$17, _30$$23;
	zval params;
	zval controllerName_zv, actionName_zv, *params_param = NULL, *fireEvents_param = NULL, layoutsDir, layout, pickView, layoutName, engines, renderView, pickViewAction, eventsManager, disabledLevels, templatesBefore, templatesAfter, templateBefore, templateAfter, _0, _2, _4, _8, _9, _1$$3, _6$$11, _7$$11, _10$$15, _11$$17, *_12$$17, _13$$17, *_14$$17, _17$$17, _15$$18, _16$$18, _19$$19, _20$$19, _21$$21, _22$$21, _23$$23, *_24$$23, _25$$23, *_26$$23, _29$$23, _27$$24, _28$$24, _31$$25, _32$$25, _33$$27, _34$$27, _35$$13, _37$$28;
	zend_string *controllerName = NULL, *actionName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&controllerName_zv);
	ZVAL_UNDEF(&actionName_zv);
	ZVAL_UNDEF(&layoutsDir);
	ZVAL_UNDEF(&layout);
	ZVAL_UNDEF(&pickView);
	ZVAL_UNDEF(&layoutName);
	ZVAL_UNDEF(&engines);
	ZVAL_UNDEF(&renderView);
	ZVAL_UNDEF(&pickViewAction);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&disabledLevels);
	ZVAL_UNDEF(&templatesBefore);
	ZVAL_UNDEF(&templatesAfter);
	ZVAL_UNDEF(&templateBefore);
	ZVAL_UNDEF(&templateAfter);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_6$$11);
	ZVAL_UNDEF(&_7$$11);
	ZVAL_UNDEF(&_10$$15);
	ZVAL_UNDEF(&_11$$17);
	ZVAL_UNDEF(&_13$$17);
	ZVAL_UNDEF(&_17$$17);
	ZVAL_UNDEF(&_15$$18);
	ZVAL_UNDEF(&_16$$18);
	ZVAL_UNDEF(&_19$$19);
	ZVAL_UNDEF(&_20$$19);
	ZVAL_UNDEF(&_21$$21);
	ZVAL_UNDEF(&_22$$21);
	ZVAL_UNDEF(&_23$$23);
	ZVAL_UNDEF(&_25$$23);
	ZVAL_UNDEF(&_29$$23);
	ZVAL_UNDEF(&_27$$24);
	ZVAL_UNDEF(&_28$$24);
	ZVAL_UNDEF(&_31$$25);
	ZVAL_UNDEF(&_32$$25);
	ZVAL_UNDEF(&_33$$27);
	ZVAL_UNDEF(&_34$$27);
	ZVAL_UNDEF(&_35$$13);
	ZVAL_UNDEF(&_37$$28);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_3$$7);
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
	static zend_string *_zephir_prop_10 = NULL;
	static zend_string *_zephir_prop_11 = NULL;
	static zend_string *_zephir_prop_12 = NULL;
	static zend_string *_zephir_prop_13 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("currentRenderLevel", 18, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("disabled", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("content", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("controllerName", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("actionName", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("layoutsDir", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("layout", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_7)) {
		_zephir_prop_7 = zend_string_init("pickView", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_8)) {
		_zephir_prop_8 = zend_string_init("eventsManager", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_9)) {
		_zephir_prop_9 = zend_string_init("disabledLevels", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_10)) {
		_zephir_prop_10 = zend_string_init("renderLevel", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_11)) {
		_zephir_prop_11 = zend_string_init("templatesBefore", 15, 1);
	}
	if (UNEXPECTED(!_zephir_prop_12)) {
		_zephir_prop_12 = zend_string_init("templatesAfter", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_13)) {
		_zephir_prop_13 = zend_string_init("mainView", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(controllerName)
		Z_PARAM_STR(actionName)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(params, params_param)
		Z_PARAM_BOOL(fireEvents)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		params_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		fireEvents_param = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&controllerName_zv);
	ZVAL_STR_COPY(&controllerName_zv, controllerName);
	zephir_memory_observe(&actionName_zv);
	ZVAL_STR_COPY(&actionName_zv, actionName);
	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
		zephir_get_arrval(&params, params_param);
	}
	if (!fireEvents_param) {
		fireEvents = 1;
	} else {
		}
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1178, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1172, PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_0)) {
		ZEPHIR_CALL_FUNCTION(&_1$$3, "ob_get_contents", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1179, &_1$$3);
		RETURN_MM_BOOL(0);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1180, &controllerName_zv);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 1181, &actionName_zv);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setvars", NULL, 0, &params);
	zephir_check_call_status();
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_5, 1182, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&layoutsDir, &_2);
	if (!(zephir_is_true(&layoutsDir))) {
		ZEPHIR_INIT_NVAR(&layoutsDir);
		ZVAL_STRING(&layoutsDir, "layouts/");
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_6, 1183, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&layout, &_2);
	if (zephir_is_true(&layout)) {
		ZEPHIR_CPY_WRT(&layoutName, &layout);
	} else {
		ZEPHIR_CPY_WRT(&layoutName, &controllerName_zv);
	}
	ZEPHIR_CALL_METHOD(&engines, this_ptr, "loadtemplateengines", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_7, 1177, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&pickView, &_2);
	if (Z_TYPE_P(&pickView) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_3$$7);
		ZEPHIR_CONCAT_VSV(&_3$$7, &controllerName_zv, "/", &actionName_zv);
		ZEPHIR_CPY_WRT(&renderView, &_3$$7);
	} else {
		ZEPHIR_OBS_NVAR(&renderView);
		zephir_array_fetch_long(&renderView, &pickView, 0, PH_NOISY, "phalcon/Mvc/View.zep", 760);
		if (Z_TYPE_P(&layoutName) == IS_NULL) {
			zephir_memory_observe(&pickViewAction);
			if (zephir_array_isset_long_fetch(&pickViewAction, &pickView, 1, 0)) {
				ZEPHIR_CPY_WRT(&layoutName, &pickViewAction);
			}
		}
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_8, 1184, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_2);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CREATE_SYMBOL_TABLE();
	
	_5 = fireEvents;
	if (_5) {
		_5 = Z_TYPE_P(&eventsManager) == IS_OBJECT;
	}
	if (_5) {
		ZEPHIR_INIT_VAR(&_7$$11);
		ZVAL_STRING(&_7$$11, "view:beforeRender");
		ZEPHIR_CALL_METHOD(&_6$$11, &eventsManager, "fire", NULL, 0, &_7$$11, this_ptr);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_6$$11)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_CALL_FUNCTION(&_8, "ob_get_contents", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1179, &_8);
	silence = 1;
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_9, 1173, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&disabledLevels, &_2);
	zephir_memory_observe(&_9);
	zephir_read_property_cached(&_9, this_ptr, _zephir_prop_10, 1185, PH_NOISY_CC);
	renderLevel = zephir_get_intval(&_9);
	if (renderLevel) {
		if (renderLevel >= 1) {
			if (!(zephir_array_isset_value_long(&disabledLevels, 1))) {
				ZVAL_UNDEF(&_10$$15);
				ZVAL_LONG(&_10$$15, 1);
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1178, &_10$$15);
				if (silence) {
					ZVAL_BOOL(&_10$$15, 1);
				} else {
					ZVAL_BOOL(&_10$$15, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "enginerender", NULL, 0, &engines, &renderView, &_10$$15);
				zephir_check_call_status();
			}
		}
		if (renderLevel >= 2) {
			if (!(zephir_array_isset_value_long(&disabledLevels, 2))) {
				ZVAL_UNDEF(&_11$$17);
				ZVAL_LONG(&_11$$17, 2);
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1178, &_11$$17);
				zephir_read_property_cached(&_11$$17, this_ptr, _zephir_prop_11, 1171, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CPY_WRT(&templatesBefore, &_11$$17);
				silence = 0;
				if (Z_TYPE_P(&templatesBefore) == IS_STRING) {
					ZEPHIR_INIT_VAR(&_13$$17);
					zephir_string_to_char_array(&_13$$17, &templatesBefore);
					_12$$17 = &_13$$17;
				} else {
					_12$$17 = &templatesBefore;
				}
				zephir_is_iterable(_12$$17, 0, "phalcon/Mvc/View.zep", 836);
				if (Z_TYPE_P(_12$$17) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_12$$17), _14$$17)
					{
						ZEPHIR_INIT_NVAR(&templateBefore);
						ZVAL_COPY(&templateBefore, _14$$17);
						ZEPHIR_INIT_NVAR(&_15$$18);
						ZEPHIR_CONCAT_VV(&_15$$18, &layoutsDir, &templateBefore);
						if (silence) {
							ZVAL_BOOL(&_16$$18, 1);
						} else {
							ZVAL_BOOL(&_16$$18, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "enginerender", NULL, 0, &engines, &_15$$18, &_16$$18);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _12$$17, "rewind", NULL, 0);
					zephir_check_call_status();
					_18$$17 = 1;
					while (1) {
						if (_18$$17) {
							_18$$17 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _12$$17, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_17$$17, _12$$17, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_17$$17)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&templateBefore, _12$$17, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_19$$19);
							ZEPHIR_CONCAT_VV(&_19$$19, &layoutsDir, &templateBefore);
							if (silence) {
								ZVAL_BOOL(&_20$$19, 1);
							} else {
								ZVAL_BOOL(&_20$$19, 0);
							}
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "enginerender", NULL, 0, &engines, &_19$$19, &_20$$19);
							zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&templateBefore);
				silence = 1;
			}
		}
		if (renderLevel >= 3) {
			if (!(zephir_array_isset_value_long(&disabledLevels, 3))) {
				ZVAL_UNDEF(&_21$$21);
				ZVAL_LONG(&_21$$21, 3);
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1178, &_21$$21);
				ZEPHIR_INIT_VAR(&_22$$21);
				ZEPHIR_CONCAT_VV(&_22$$21, &layoutsDir, &layoutName);
				if (silence) {
					ZVAL_BOOL(&_21$$21, 1);
				} else {
					ZVAL_BOOL(&_21$$21, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "enginerender", NULL, 0, &engines, &_22$$21, &_21$$21);
				zephir_check_call_status();
			}
		}
		if (renderLevel >= 4) {
			if (!(zephir_array_isset_value_long(&disabledLevels, 4))) {
				ZVAL_UNDEF(&_23$$23);
				ZVAL_LONG(&_23$$23, 4);
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1178, &_23$$23);
				zephir_read_property_cached(&_23$$23, this_ptr, _zephir_prop_12, 1170, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CPY_WRT(&templatesAfter, &_23$$23);
				silence = 0;
				if (Z_TYPE_P(&templatesAfter) == IS_STRING) {
					ZEPHIR_INIT_VAR(&_25$$23);
					zephir_string_to_char_array(&_25$$23, &templatesAfter);
					_24$$23 = &_25$$23;
				} else {
					_24$$23 = &templatesAfter;
				}
				zephir_is_iterable(_24$$23, 0, "phalcon/Mvc/View.zep", 872);
				if (Z_TYPE_P(_24$$23) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_24$$23), _26$$23)
					{
						ZEPHIR_INIT_NVAR(&templateAfter);
						ZVAL_COPY(&templateAfter, _26$$23);
						ZEPHIR_INIT_NVAR(&_27$$24);
						ZEPHIR_CONCAT_VV(&_27$$24, &layoutsDir, &templateAfter);
						if (silence) {
							ZVAL_BOOL(&_28$$24, 1);
						} else {
							ZVAL_BOOL(&_28$$24, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "enginerender", NULL, 0, &engines, &_27$$24, &_28$$24);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _24$$23, "rewind", NULL, 0);
					zephir_check_call_status();
					_30$$23 = 1;
					while (1) {
						if (_30$$23) {
							_30$$23 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _24$$23, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_29$$23, _24$$23, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_29$$23)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&templateAfter, _24$$23, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_31$$25);
							ZEPHIR_CONCAT_VV(&_31$$25, &layoutsDir, &templateAfter);
							if (silence) {
								ZVAL_BOOL(&_32$$25, 1);
							} else {
								ZVAL_BOOL(&_32$$25, 0);
							}
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "enginerender", NULL, 0, &engines, &_31$$25, &_32$$25);
							zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&templateAfter);
				silence = 1;
			}
		}
		if (renderLevel >= 5) {
			if (!(zephir_array_isset_value_long(&disabledLevels, 5))) {
				ZVAL_UNDEF(&_33$$27);
				ZVAL_LONG(&_33$$27, 5);
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1178, &_33$$27);
				zephir_read_property_cached(&_33$$27, this_ptr, _zephir_prop_13, 1186, PH_NOISY_CC | PH_READONLY);
				if (silence) {
					ZVAL_BOOL(&_34$$27, 1);
				} else {
					ZVAL_BOOL(&_34$$27, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "enginerender", NULL, 0, &engines, &_33$$27, &_34$$27);
				zephir_check_call_status();
			}
		}
		ZVAL_UNDEF(&_35$$13);
		ZVAL_LONG(&_35$$13, 0);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1178, &_35$$13);
	}
	_36 = fireEvents;
	if (_36) {
		_36 = Z_TYPE_P(&eventsManager) == IS_OBJECT;
	}
	if (_36) {
		ZEPHIR_INIT_VAR(&_37$$28);
		ZVAL_STRING(&_37$$28, "view:afterRender");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_37$$28, this_ptr);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(1);
}

/**
 * Register templating engines
 *
 * ```php
 * $this->view->registerEngines(
 *     [
 *         ".phtml" => \Phalcon\Mvc\View\Engine\Php::class,
 *         ".volt"  => \Phalcon\Mvc\View\Engine\Volt::class,
 *         ".mhtml" => \MyCustomEngine::class,
 *     ]
 * );
 * ```
 */
PHP_METHOD(Phalcon_Mvc_View, registerEngines)
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1168, &engines);
	RETURN_THIS();
}

/**
 * Executes render process from dispatching data
 *
 *```php
 * // Shows recent posts view (app/views/posts/recent.phtml)
 * $view->start()->render("posts", "recent")->finish();
 *```
 */
PHP_METHOD(Phalcon_Mvc_View, render)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval params;
	zval controllerName_zv, actionName_zv, *params_param = NULL, result;
	zend_string *controllerName = NULL, *actionName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&controllerName_zv);
	ZVAL_UNDEF(&actionName_zv);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&params);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(controllerName)
		Z_PARAM_STR(actionName)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(params, params_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		params_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&controllerName_zv);
	ZVAL_STR_COPY(&controllerName_zv, controllerName);
	zephir_memory_observe(&actionName_zv);
	ZVAL_STR_COPY(&actionName_zv, actionName);
	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
		zephir_get_arrval(&params, params_param);
	}
	ZEPHIR_CALL_METHOD(&result, this_ptr, "processrender", NULL, 0, &controllerName_zv, &actionName_zv, &params);
	zephir_check_call_status();
	if (!(zephir_is_true(&result))) {
		RETURN_MM_BOOL(0);
	}
	RETURN_THIS();
}

/**
 * Resets the view component to its factory default values
 */
PHP_METHOD(Phalcon_Mvc_View, reset)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, __$false, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("disabled", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("engines", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("renderLevel", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("content", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("templatesBefore", 15, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("templatesAfter", 14, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	if (0) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1172, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1172, &__$false);
	}
	if (0) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1187, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1187, &__$false);
	}
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, 5);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1185, &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "");
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1179, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	array_init(&_1);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 1171, &_1);
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 1170, &_2);
	RETURN_THIS();
}

/**
 * Sets base path. Depending of your platform, always add a trailing slash
 * or backslash
 *
 * ```php
 * $view->setBasePath(__DIR__ . "/");
 * ```
 */
PHP_METHOD(Phalcon_Mvc_View, setBasePath)
{
	zval basePath_zv;
	zend_string *basePath = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&basePath_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("basePath", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(basePath)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&basePath_zv, basePath);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1175, &basePath_zv);
	RETURN_THISW();
}

/**
 * Sets the events manager
 */
PHP_METHOD(Phalcon_Mvc_View, setEventsManager)
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1184, eventsManager);
}

/**
 * Change the layout to be used instead of using the name of the latest
 * controller name
 *
 * ```php
 * $this->view->setLayout("main");
 * ```
 */
PHP_METHOD(Phalcon_Mvc_View, setLayout)
{
	zval layout_zv;
	zend_string *layout = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&layout_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("layout", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(layout)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&layout_zv, layout);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1183, &layout_zv);
	RETURN_THISW();
}

/**
 * Sets the layouts sub-directory. Must be a directory under the views
 * directory. Depending of your platform, always add a trailing slash or
 * backslash
 *
 *```php
 * $view->setLayoutsDir("../common/layouts/");
 *```
 */
PHP_METHOD(Phalcon_Mvc_View, setLayoutsDir)
{
	zval layoutsDir_zv;
	zend_string *layoutsDir = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&layoutsDir_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("layoutsDir", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(layoutsDir)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&layoutsDir_zv, layoutsDir);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1182, &layoutsDir_zv);
	RETURN_THISW();
}

/**
 * Sets default view name. Must be a file without extension in the views
 * directory
 *
 * ```php
 * // Renders as main view views-dir/base.phtml
 * $this->view->setMainView("base");
 * ```
 */
PHP_METHOD(Phalcon_Mvc_View, setMainView)
{
	zval viewPath_zv;
	zend_string *viewPath = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewPath_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("mainView", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(viewPath)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&viewPath_zv, viewPath);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1186, &viewPath_zv);
	RETURN_THISW();
}

/**
 * Adds parameters to views (alias of setVar)
 *
 *```php
 * $this->view->setParamToView("products", $products);
 *```
 */
PHP_METHOD(Phalcon_Mvc_View, setParamToView)
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

/**
 * Sets a partials sub-directory. Must be a directory under the views
 * directory. Depending of your platform, always add a trailing slash or
 * backslash
 *
 *```php
 * $view->setPartialsDir("../common/partials/");
 *```
 */
PHP_METHOD(Phalcon_Mvc_View, setPartialsDir)
{
	zval partialsDir_zv;
	zend_string *partialsDir = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&partialsDir_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("partialsDir", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(partialsDir)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&partialsDir_zv, partialsDir);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1176, &partialsDir_zv);
	RETURN_THISW();
}

/**
 * Sets the render level for the view
 *
 * ```php
 * // Render the view related to the controller only
 * $this->view->setRenderLevel(
 *     View::LEVEL_LAYOUT
 * );
 * ```
 */
PHP_METHOD(Phalcon_Mvc_View, setRenderLevel)
{
	zval *level_param = NULL, _0;
	zend_long level;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("renderLevel", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(level)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &level_param);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, level);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1185, &_0);
	RETURN_THISW();
}

/**
 * Sets a "template after" controller layout
 */
PHP_METHOD(Phalcon_Mvc_View, setTemplateAfter)
{
	zval _0$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *templateAfter, templateAfter_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&templateAfter_sub);
	ZVAL_UNDEF(&_0$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("templatesAfter", 14, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(templateAfter)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &templateAfter);
	if (Z_TYPE_P(templateAfter) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 1, 0);
		zephir_array_fast_append(&_0$$3, templateAfter);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1170, &_0$$3);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1170, templateAfter);
	}
	RETURN_THIS();
}

/**
 * Sets a template before the controller layout
 */
PHP_METHOD(Phalcon_Mvc_View, setTemplateBefore)
{
	zval _0$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *templateBefore, templateBefore_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&templateBefore_sub);
	ZVAL_UNDEF(&_0$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("templatesBefore", 15, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(templateBefore)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &templateBefore);
	if (Z_TYPE_P(templateBefore) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 1, 0);
		zephir_array_fast_append(&_0$$3, templateBefore);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1171, &_0$$3);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1171, templateBefore);
	}
	RETURN_THIS();
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
 */
PHP_METHOD(Phalcon_Mvc_View, setVars)
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
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 1169, PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_0$$3, &_1$$3, &params);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1169, &_0$$3);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1169, &params);
	}
	RETURN_THIS();
}

/**
 * Sets the views directory. Depending of your platform,
 * always add a trailing slash or backslash
 */
PHP_METHOD(Phalcon_Mvc_View, setViewsDir)
{
	zend_string *_7$$5;
	zend_ulong _6$$5;
	zend_bool _0, _12$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *viewsDir, viewsDir_sub, position, directory, newViewsDir, _1$$3, _2$$4, *_3$$5, _4$$5, *_5$$5, _11$$5, _8$$7, _10$$6, _13$$9, _14$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewsDir_sub);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&directory);
	ZVAL_UNDEF(&newViewsDir);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$8);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("viewsDirs", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(viewsDir)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &viewsDir);
	_0 = Z_TYPE_P(viewsDir) != IS_STRING;
	if (_0) {
		_0 = Z_TYPE_P(viewsDir) != IS_ARRAY;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_view_exceptions_invalidviewsdirtype_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/View.zep", 1140);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(viewsDir) == IS_STRING) {
		ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "todirseparator", NULL, 0, viewsDir);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1188, &_2$$4);
	} else {
		ZEPHIR_INIT_VAR(&newViewsDir);
		array_init(&newViewsDir);
		if (Z_TYPE_P(viewsDir) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_4$$5);
			zephir_string_to_char_array(&_4$$5, viewsDir);
			_3$$5 = &_4$$5;
		} else {
			_3$$5 = viewsDir;
		}
		zephir_is_iterable(_3$$5, 0, "phalcon/Mvc/View.zep", 1156);
		if (Z_TYPE_P(_3$$5) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_3$$5), _6$$5, _7$$5, _5$$5)
			{
				ZEPHIR_INIT_NVAR(&position);
				if (_7$$5 != NULL) { 
					ZVAL_STR_COPY(&position, _7$$5);
				} else {
					ZVAL_LONG(&position, _6$$5);
				}
				ZEPHIR_INIT_NVAR(&directory);
				ZVAL_COPY(&directory, _5$$5);
				if (Z_TYPE_P(&directory) != IS_STRING) {
					ZEPHIR_INIT_NVAR(&_8$$7);
					object_init_ex(&_8$$7, phalcon_mvc_view_exceptions_viewsdiritemmustbestring_ce);
					ZEPHIR_CALL_METHOD(NULL, &_8$$7, "__construct", &_9, 0);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_8$$7, "phalcon/Mvc/View.zep", 1150);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&_10$$6, this_ptr, "todirseparator", NULL, 0, &directory);
				zephir_check_call_status();
				zephir_array_update_zval(&newViewsDir, &position, &_10$$6, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _3$$5, "rewind", NULL, 0);
			zephir_check_call_status();
			_12$$5 = 1;
			while (1) {
				if (_12$$5) {
					_12$$5 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _3$$5, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_11$$5, _3$$5, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_11$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&position, _3$$5, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&directory, _3$$5, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&directory) != IS_STRING) {
						ZEPHIR_INIT_NVAR(&_13$$9);
						object_init_ex(&_13$$9, phalcon_mvc_view_exceptions_viewsdiritemmustbestring_ce);
						ZEPHIR_CALL_METHOD(NULL, &_13$$9, "__construct", &_9, 0);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_13$$9, "phalcon/Mvc/View.zep", 1150);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(&_14$$8, this_ptr, "todirseparator", NULL, 0, &directory);
					zephir_check_call_status();
					zephir_array_update_zval(&newViewsDir, &position, &_14$$8, PH_COPY | PH_SEPARATE);
			}
		}
		ZEPHIR_INIT_NVAR(&directory);
		ZEPHIR_INIT_NVAR(&position);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1188, &newViewsDir);
	}
	RETURN_THIS();
}

/**
 * Starts rendering process enabling the output buffering
 */
PHP_METHOD(Phalcon_Mvc_View, start)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("content", 7, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "");
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1179, &_0);
	RETURN_THIS();
}

/**
 * Renders the view and returns it as a string
 */
PHP_METHOD(Phalcon_Mvc_View, toString)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval params;
	zval controllerName_zv, actionName_zv, *params_param = NULL, result, _0;
	zend_string *controllerName = NULL, *actionName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&controllerName_zv);
	ZVAL_UNDEF(&actionName_zv);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&params);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(controllerName)
		Z_PARAM_STR(actionName)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(params, params_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		params_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&controllerName_zv);
	ZVAL_STR_COPY(&controllerName_zv, controllerName);
	zephir_memory_observe(&actionName_zv);
	ZVAL_STR_COPY(&actionName_zv, actionName);
	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
		zephir_get_arrval(&params, params_param);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "start", NULL, 0);
	zephir_check_call_status();
	ZVAL_BOOL(&_0, 0);
	ZEPHIR_CALL_METHOD(&result, this_ptr, "processrender", NULL, 0, &controllerName_zv, &actionName_zv, &params, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "finish", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&result))) {
		RETURN_MM_STRING("");
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getcontent", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Checks whether view exists on registered extensions and render it
 */
PHP_METHOD(Phalcon_Mvc_View, engineRender)
{
	zend_ulong _8$$3, _33$$16;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_11 = NULL, *_15 = NULL, *_18 = NULL, *_25 = NULL, *_28 = NULL, *_39 = NULL, *_42 = NULL, *_49 = NULL, *_52 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool silence, mustClean, _30, _20$$3, _44$$16;
	zend_string *viewPath = NULL, *_9$$3, *_34$$16;
	zval *engines_param = NULL, viewPath_zv, *silence_param = NULL, *mustClean_param = NULL, basePath, engine, eventsManager, extension, viewsDir, viewsDirPath, viewEnginePath, viewEnginePaths, viewParams, _0, _1, *_2, _3, *_4, _29, _5$$3, *_7$$3, _19$$3, _10$$6, _13$$8, _14$$8, _16$$7, _17$$10, _21$$11, _23$$13, _24$$13, _26$$12, _27$$15, _31$$16, *_32$$16, _43$$16, _35$$19, _37$$21, _38$$21, _40$$20, _41$$23, _45$$24, _47$$26, _48$$26, _50$$25, _51$$28, _53$$29, _54$$30;
	zval engines, _12$$8, _22$$13, _36$$21, _46$$26;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&engines);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_22$$13);
	ZVAL_UNDEF(&_36$$21);
	ZVAL_UNDEF(&_46$$26);
	ZVAL_UNDEF(&viewPath_zv);
	ZVAL_UNDEF(&basePath);
	ZVAL_UNDEF(&engine);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&viewsDir);
	ZVAL_UNDEF(&viewsDirPath);
	ZVAL_UNDEF(&viewEnginePath);
	ZVAL_UNDEF(&viewEnginePaths);
	ZVAL_UNDEF(&viewParams);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_19$$3);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_23$$13);
	ZVAL_UNDEF(&_24$$13);
	ZVAL_UNDEF(&_26$$12);
	ZVAL_UNDEF(&_27$$15);
	ZVAL_UNDEF(&_31$$16);
	ZVAL_UNDEF(&_43$$16);
	ZVAL_UNDEF(&_35$$19);
	ZVAL_UNDEF(&_37$$21);
	ZVAL_UNDEF(&_38$$21);
	ZVAL_UNDEF(&_40$$20);
	ZVAL_UNDEF(&_41$$23);
	ZVAL_UNDEF(&_45$$24);
	ZVAL_UNDEF(&_47$$26);
	ZVAL_UNDEF(&_48$$26);
	ZVAL_UNDEF(&_50$$25);
	ZVAL_UNDEF(&_51$$28);
	ZVAL_UNDEF(&_53$$29);
	ZVAL_UNDEF(&_54$$30);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("basePath", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("viewParams", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("eventsManager", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("activeRenderPaths", 17, 1);
	}

	ZEND_PARSE_PARAMETERS_START(3, 4)
		ZEPHIR_Z_PARAM_ARRAY(engines, engines_param)
		Z_PARAM_STR(viewPath)
		Z_PARAM_BOOL(silence)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(mustClean)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	engines_param = ZEND_CALL_ARG(execute_data, 1);
	silence_param = ZEND_CALL_ARG(execute_data, 3);
	if (ZEND_NUM_ARGS() > 3) {
		mustClean_param = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_get_arrval(&engines, engines_param);
	zephir_memory_observe(&viewPath_zv);
	ZVAL_STR_COPY(&viewPath_zv, viewPath);
	if (!mustClean_param) {
		mustClean = 1;
	} else {
		}
	ZEPHIR_INIT_VAR(&viewEnginePath);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1175, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&basePath, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1169, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&viewParams, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 1184, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_0);
	ZEPHIR_INIT_VAR(&viewEnginePaths);
	array_init(&viewEnginePaths);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getviewsdirs", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&_1) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_3);
		zephir_string_to_char_array(&_3, &_1);
		_2 = &_3;
	} else {
		_2 = &_1;
	}
	zephir_is_iterable(_2, 0, "phalcon/Mvc/View.zep", 1262);
	if (Z_TYPE_P(_2) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_2), _4)
		{
			ZEPHIR_INIT_NVAR(&viewsDir);
			ZVAL_COPY(&viewsDir, _4);
			ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "isabsolutepath", &_6, 0, &viewPath_zv);
			zephir_check_call_status();
			if (!(zephir_is_true(&_5$$3))) {
				ZEPHIR_INIT_NVAR(&viewsDirPath);
				ZEPHIR_CONCAT_VVV(&viewsDirPath, &basePath, &viewsDir, &viewPath_zv);
			} else {
				ZEPHIR_CPY_WRT(&viewsDirPath, &viewPath_zv);
			}
			zephir_is_iterable(&engines, 0, "phalcon/Mvc/View.zep", 1257);
			if (Z_TYPE_P(&engines) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&engines), _8$$3, _9$$3, _7$$3)
				{
					ZEPHIR_INIT_NVAR(&extension);
					if (_9$$3 != NULL) { 
						ZVAL_STR_COPY(&extension, _9$$3);
					} else {
						ZVAL_LONG(&extension, _8$$3);
					}
					ZEPHIR_INIT_NVAR(&engine);
					ZVAL_COPY(&engine, _7$$3);
					ZEPHIR_INIT_NVAR(&viewEnginePath);
					ZEPHIR_CONCAT_VV(&viewEnginePath, &viewsDirPath, &extension);
					ZEPHIR_CALL_METHOD(&_10$$6, this_ptr, "phpfileexists", &_11, 0, &viewEnginePath);
					zephir_check_call_status();
					if (zephir_is_true(&_10$$6)) {
						if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
							ZEPHIR_INIT_NVAR(&_12$$8);
							zephir_create_array(&_12$$8, 1, 0);
							zephir_array_fast_append(&_12$$8, &viewEnginePath);
							zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1174, &_12$$8);
							ZEPHIR_INIT_NVAR(&_14$$8);
							ZVAL_STRING(&_14$$8, "view:beforeRenderView");
							ZEPHIR_CALL_METHOD(&_13$$8, &eventsManager, "fire", &_15, 0, &_14$$8, this_ptr, &viewEnginePath);
							zephir_check_call_status();
							if (ZEPHIR_IS_FALSE_IDENTICAL(&_13$$8)) {
								continue;
							}
						}
						if (mustClean) {
							ZVAL_BOOL(&_16$$7, 1);
						} else {
							ZVAL_BOOL(&_16$$7, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, &engine, "render", NULL, 0, &viewEnginePath, &viewParams, &_16$$7);
						zephir_check_call_status();
						if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
							ZEPHIR_INIT_NVAR(&_17$$10);
							ZVAL_STRING(&_17$$10, "view:afterRenderView");
							ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_18, 0, &_17$$10, this_ptr);
							zephir_check_call_status();
						}
						RETURN_MM_NULL();
					}
					zephir_array_append(&viewEnginePaths, &viewEnginePath, PH_SEPARATE, "phalcon/Mvc/View.zep", 1255);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &engines, "rewind", NULL, 0);
				zephir_check_call_status();
				_20$$3 = 1;
				while (1) {
					if (_20$$3) {
						_20$$3 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &engines, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_19$$3, &engines, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_19$$3)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&extension, &engines, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&engine, &engines, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&viewEnginePath);
						ZEPHIR_CONCAT_VV(&viewEnginePath, &viewsDirPath, &extension);
						ZEPHIR_CALL_METHOD(&_21$$11, this_ptr, "phpfileexists", &_11, 0, &viewEnginePath);
						zephir_check_call_status();
						if (zephir_is_true(&_21$$11)) {
							if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
								ZEPHIR_INIT_NVAR(&_22$$13);
								zephir_create_array(&_22$$13, 1, 0);
								zephir_array_fast_append(&_22$$13, &viewEnginePath);
								zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1174, &_22$$13);
								ZEPHIR_INIT_NVAR(&_24$$13);
								ZVAL_STRING(&_24$$13, "view:beforeRenderView");
								ZEPHIR_CALL_METHOD(&_23$$13, &eventsManager, "fire", &_25, 0, &_24$$13, this_ptr, &viewEnginePath);
								zephir_check_call_status();
								if (ZEPHIR_IS_FALSE_IDENTICAL(&_23$$13)) {
									continue;
								}
							}
							if (mustClean) {
								ZVAL_BOOL(&_26$$12, 1);
							} else {
								ZVAL_BOOL(&_26$$12, 0);
							}
							ZEPHIR_CALL_METHOD(NULL, &engine, "render", NULL, 0, &viewEnginePath, &viewParams, &_26$$12);
							zephir_check_call_status();
							if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
								ZEPHIR_INIT_NVAR(&_27$$15);
								ZVAL_STRING(&_27$$15, "view:afterRenderView");
								ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_28, 0, &_27$$15, this_ptr);
								zephir_check_call_status();
							}
							RETURN_MM_NULL();
						}
						zephir_array_append(&viewEnginePaths, &viewEnginePath, PH_SEPARATE, "phalcon/Mvc/View.zep", 1255);
				}
			}
			ZEPHIR_INIT_NVAR(&engine);
			ZEPHIR_INIT_NVAR(&extension);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _2, "rewind", NULL, 0);
		zephir_check_call_status();
		_30 = 1;
		while (1) {
			if (_30) {
				_30 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _2, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_29, _2, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_29)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&viewsDir, _2, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_31$$16, this_ptr, "isabsolutepath", &_6, 0, &viewPath_zv);
				zephir_check_call_status();
				if (!(zephir_is_true(&_31$$16))) {
					ZEPHIR_INIT_NVAR(&viewsDirPath);
					ZEPHIR_CONCAT_VVV(&viewsDirPath, &basePath, &viewsDir, &viewPath_zv);
				} else {
					ZEPHIR_CPY_WRT(&viewsDirPath, &viewPath_zv);
				}
				zephir_is_iterable(&engines, 0, "phalcon/Mvc/View.zep", 1257);
				if (Z_TYPE_P(&engines) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&engines), _33$$16, _34$$16, _32$$16)
					{
						ZEPHIR_INIT_NVAR(&extension);
						if (_34$$16 != NULL) { 
							ZVAL_STR_COPY(&extension, _34$$16);
						} else {
							ZVAL_LONG(&extension, _33$$16);
						}
						ZEPHIR_INIT_NVAR(&engine);
						ZVAL_COPY(&engine, _32$$16);
						ZEPHIR_INIT_NVAR(&viewEnginePath);
						ZEPHIR_CONCAT_VV(&viewEnginePath, &viewsDirPath, &extension);
						ZEPHIR_CALL_METHOD(&_35$$19, this_ptr, "phpfileexists", &_11, 0, &viewEnginePath);
						zephir_check_call_status();
						if (zephir_is_true(&_35$$19)) {
							if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
								ZEPHIR_INIT_NVAR(&_36$$21);
								zephir_create_array(&_36$$21, 1, 0);
								zephir_array_fast_append(&_36$$21, &viewEnginePath);
								zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1174, &_36$$21);
								ZEPHIR_INIT_NVAR(&_38$$21);
								ZVAL_STRING(&_38$$21, "view:beforeRenderView");
								ZEPHIR_CALL_METHOD(&_37$$21, &eventsManager, "fire", &_39, 0, &_38$$21, this_ptr, &viewEnginePath);
								zephir_check_call_status();
								if (ZEPHIR_IS_FALSE_IDENTICAL(&_37$$21)) {
									continue;
								}
							}
							if (mustClean) {
								ZVAL_BOOL(&_40$$20, 1);
							} else {
								ZVAL_BOOL(&_40$$20, 0);
							}
							ZEPHIR_CALL_METHOD(NULL, &engine, "render", NULL, 0, &viewEnginePath, &viewParams, &_40$$20);
							zephir_check_call_status();
							if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
								ZEPHIR_INIT_NVAR(&_41$$23);
								ZVAL_STRING(&_41$$23, "view:afterRenderView");
								ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_42, 0, &_41$$23, this_ptr);
								zephir_check_call_status();
							}
							RETURN_MM_NULL();
						}
						zephir_array_append(&viewEnginePaths, &viewEnginePath, PH_SEPARATE, "phalcon/Mvc/View.zep", 1255);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &engines, "rewind", NULL, 0);
					zephir_check_call_status();
					_44$$16 = 1;
					while (1) {
						if (_44$$16) {
							_44$$16 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &engines, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_43$$16, &engines, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_43$$16)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&extension, &engines, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&engine, &engines, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&viewEnginePath);
							ZEPHIR_CONCAT_VV(&viewEnginePath, &viewsDirPath, &extension);
							ZEPHIR_CALL_METHOD(&_45$$24, this_ptr, "phpfileexists", &_11, 0, &viewEnginePath);
							zephir_check_call_status();
							if (zephir_is_true(&_45$$24)) {
								if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
									ZEPHIR_INIT_NVAR(&_46$$26);
									zephir_create_array(&_46$$26, 1, 0);
									zephir_array_fast_append(&_46$$26, &viewEnginePath);
									zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1174, &_46$$26);
									ZEPHIR_INIT_NVAR(&_48$$26);
									ZVAL_STRING(&_48$$26, "view:beforeRenderView");
									ZEPHIR_CALL_METHOD(&_47$$26, &eventsManager, "fire", &_49, 0, &_48$$26, this_ptr, &viewEnginePath);
									zephir_check_call_status();
									if (ZEPHIR_IS_FALSE_IDENTICAL(&_47$$26)) {
										continue;
									}
								}
								if (mustClean) {
									ZVAL_BOOL(&_50$$25, 1);
								} else {
									ZVAL_BOOL(&_50$$25, 0);
								}
								ZEPHIR_CALL_METHOD(NULL, &engine, "render", NULL, 0, &viewEnginePath, &viewParams, &_50$$25);
								zephir_check_call_status();
								if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
									ZEPHIR_INIT_NVAR(&_51$$28);
									ZVAL_STRING(&_51$$28, "view:afterRenderView");
									ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_52, 0, &_51$$28, this_ptr);
									zephir_check_call_status();
								}
								RETURN_MM_NULL();
							}
							zephir_array_append(&viewEnginePaths, &viewEnginePath, PH_SEPARATE, "phalcon/Mvc/View.zep", 1255);
					}
				}
				ZEPHIR_INIT_NVAR(&engine);
				ZEPHIR_INIT_NVAR(&extension);
		}
	}
	ZEPHIR_INIT_NVAR(&viewsDir);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1174, &viewEnginePaths);
		ZEPHIR_INIT_VAR(&_53$$29);
		ZVAL_STRING(&_53$$29, "view:notFoundView");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_53$$29, this_ptr, &viewEnginePath);
		zephir_check_call_status();
	}
	if (!(silence)) {
		ZEPHIR_INIT_VAR(&_54$$30);
		object_init_ex(&_54$$30, phalcon_mvc_view_exceptions_viewnotfound_ce);
		ZEPHIR_CALL_METHOD(NULL, &_54$$30, "__construct", NULL, 0, &viewPath_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_54$$30, "phalcon/Mvc/View.zep", 1269);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Gets views directories
 */
PHP_METHOD(Phalcon_Mvc_View, getViewsDirs)
{
	zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("viewsDirs", 9, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1188, PH_NOISY_CC);
	if (Z_TYPE_P(&_0) == IS_STRING) {
		zephir_create_array(return_value, 1, 0);
		zephir_memory_observe(&_1$$3);
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 1188, PH_NOISY_CC);
		zephir_array_fast_append(return_value, &_1$$3);
		RETURN_MM();
	}
	RETURN_MM_MEMBER_TYPED(getThis(), "viewsDirs", IS_ARRAY);
}

/**
 * Checks if a path is absolute or not
 */
PHP_METHOD(Phalcon_Mvc_View, isAbsolutePath)
{
	zend_bool _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval path_zv, _0, _5, _2$$3, _3$$3, _4$$3;
	zend_string *path = NULL;

	ZVAL_UNDEF(&path_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(path)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&path_zv);
	ZVAL_STR_COPY(&path_zv, path);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "PHP_OS");
	if (ZEPHIR_IS_STRING_IDENTICAL(&_0, "WINNT")) {
		_1$$3 = zephir_fast_strlen_ev(&path_zv) >= 3;
		if (_1$$3) {
			ZVAL_LONG(&_2$$3, 1);
			ZVAL_LONG(&_3$$3, 2);
			ZEPHIR_INIT_VAR(&_4$$3);
			zephir_substr(&_4$$3, &path_zv, 1 , 2 , 0);
			_1$$3 = ZEPHIR_IS_STRING_IDENTICAL(&_4$$3, ":\\");
		}
		RETURN_MM_BOOL(_1$$3);
	}
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "/");
	ZEPHIR_RETURN_CALL_FUNCTION("str_starts_with", NULL, 0, &path_zv, &_5);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Loads registered template engines, if none is registered it will use
 * Phalcon\Mvc\View\Engine\Php
 */
PHP_METHOD(Phalcon_Mvc_View, loadTemplateEngines)
{
	zval _16$$11, _23$$17;
	zend_class_entry *_10$$9, *_20$$15;
	zend_bool _18$$5;
	zend_string *_8$$5;
	zend_ulong _7$$5;
	zval engines, di, registeredEngines, engineService, extension, _0, _1$$3, _2$$4, _3$$6, *_4$$5, _5$$5, *_6$$5, _17$$5, _9$$9, _13$$12, _15$$11, _19$$15, _21$$18, _22$$17;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL, *_12 = NULL, *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&engines);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&registeredEngines);
	ZVAL_UNDEF(&engineService);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_13$$12);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_19$$15);
	ZVAL_UNDEF(&_21$$18);
	ZVAL_UNDEF(&_22$$17);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_23$$17);
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

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1187, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&engines, &_0);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&engines)) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_1, 1189, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&di, &_1$$3);
		ZEPHIR_INIT_NVAR(&engines);
		array_init(&engines);
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_2, 1168, PH_NOISY_CC | PH_READONLY);
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
				object_init_ex(&_3$$6, phalcon_mvc_view_exceptions_viewservicesunavailable_ce);
				ZEPHIR_CALL_METHOD(NULL, &_3$$6, "__construct", NULL, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_3$$6, "phalcon/Mvc/View.zep", 1323);
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
			zephir_is_iterable(_4$$5, 0, "phalcon/Mvc/View.zep", 1358);
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
							ZEPHIR_CALL_FUNCTION(&_9$$9, "call_user_func", &_12, 82, &engineService, this_ptr);
							zephir_check_call_status();
							zephir_array_update_zval(&engines, &extension, &_9$$9, PH_COPY | PH_SEPARATE);
						} else {
							zephir_array_update_zval(&engines, &extension, &engineService, PH_COPY | PH_SEPARATE);
						}
					} else {
						if (Z_TYPE_P(&engineService) != IS_STRING) {
							ZEPHIR_INIT_NVAR(&_13$$12);
							object_init_ex(&_13$$12, phalcon_mvc_view_exceptions_invalidengineregistration_ce);
							ZEPHIR_CALL_METHOD(NULL, &_13$$12, "__construct", &_14, 0, &extension);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_13$$12, "phalcon/Mvc/View.zep", 1349);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_INIT_NVAR(&_16$$11);
						zephir_create_array(&_16$$11, 1, 0);
						zephir_array_fast_append(&_16$$11, this_ptr);
						ZEPHIR_CALL_METHOD(&_15$$11, &di, "get", NULL, 0, &engineService, &_16$$11);
						zephir_check_call_status();
						zephir_array_update_zval(&engines, &extension, &_15$$11, PH_COPY | PH_SEPARATE);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _4$$5, "rewind", NULL, 0);
				zephir_check_call_status();
				_18$$5 = 1;
				while (1) {
					if (_18$$5) {
						_18$$5 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _4$$5, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_17$$5, _4$$5, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_17$$5)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&extension, _4$$5, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&engineService, _4$$5, "current", NULL, 0);
					zephir_check_call_status();
						if (Z_TYPE_P(&engineService) == IS_OBJECT) {
							if (zephir_is_instance_of(&engineService, SL("Closure"))) {
								_20$$15 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
								ZEPHIR_CALL_CE_STATIC(&_19$$15, _20$$15, "bind", &_11, 0, &engineService, &di);
								zephir_check_call_status();
								ZEPHIR_CPY_WRT(&engineService, &_19$$15);
								ZEPHIR_CALL_FUNCTION(&_19$$15, "call_user_func", &_12, 82, &engineService, this_ptr);
								zephir_check_call_status();
								zephir_array_update_zval(&engines, &extension, &_19$$15, PH_COPY | PH_SEPARATE);
							} else {
								zephir_array_update_zval(&engines, &extension, &engineService, PH_COPY | PH_SEPARATE);
							}
						} else {
							if (Z_TYPE_P(&engineService) != IS_STRING) {
								ZEPHIR_INIT_NVAR(&_21$$18);
								object_init_ex(&_21$$18, phalcon_mvc_view_exceptions_invalidengineregistration_ce);
								ZEPHIR_CALL_METHOD(NULL, &_21$$18, "__construct", &_14, 0, &extension);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_21$$18, "phalcon/Mvc/View.zep", 1349);
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_INIT_NVAR(&_23$$17);
							zephir_create_array(&_23$$17, 1, 0);
							zephir_array_fast_append(&_23$$17, this_ptr);
							ZEPHIR_CALL_METHOD(&_22$$17, &di, "get", NULL, 0, &engineService, &_23$$17);
							zephir_check_call_status();
							zephir_array_update_zval(&engines, &extension, &_22$$17, PH_COPY | PH_SEPARATE);
						}
				}
			}
			ZEPHIR_INIT_NVAR(&engineService);
			ZEPHIR_INIT_NVAR(&extension);
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1187, &engines);
	}
	RETURN_CCTOR(&engines);
}

/**
 * @param string $directory
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View, toDirSeparator)
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
PHP_METHOD(Phalcon_Mvc_View, phpFclose)
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
PHP_METHOD(Phalcon_Mvc_View, phpFgetCsv)
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
PHP_METHOD(Phalcon_Mvc_View, phpFileExists)
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
PHP_METHOD(Phalcon_Mvc_View, phpFileGetContents)
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
PHP_METHOD(Phalcon_Mvc_View, phpFilePutContents)
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
PHP_METHOD(Phalcon_Mvc_View, phpFopen)
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
PHP_METHOD(Phalcon_Mvc_View, phpFwrite)
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
PHP_METHOD(Phalcon_Mvc_View, phpIsWritable)
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
PHP_METHOD(Phalcon_Mvc_View, phpUnlink)
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
PHP_METHOD(Phalcon_Mvc_View, getContent)
{

	RETURN_MEMBER_TYPED(getThis(), "content", IS_STRING);
}

/**
 * Returns parameters to views
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View, getParamsToView)
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1169, PH_NOISY_CC);
	zephir_get_arrval(&_1, &_0);
	RETURN_CTOR(&_1);
}

/**
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View, getRegisteredEngines)
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1168, PH_NOISY_CC);
	zephir_get_arrval(&_1, &_0);
	RETURN_CTOR(&_1);
}

/**
 * Returns a parameter previously set in the view
 *
 * @return mixed|null
 */
PHP_METHOD(Phalcon_Mvc_View, getVar)
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1169, PH_NOISY_CC | PH_READONLY);
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
PHP_METHOD(Phalcon_Mvc_View, setContent)
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1179, &content_zv);
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
PHP_METHOD(Phalcon_Mvc_View, setVar)
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

zend_object *zephir_init_properties_Phalcon_Mvc_View(zend_class_entry *class_type)
{
		zval _0, _2, _4, _6, _8, _10, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7, _11$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$8);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("viewsDirs"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("viewsDirs"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("templatesBefore"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("templatesBefore"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("templatesAfter"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("templatesAfter"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("params"), &_7$$6);
		}
		zephir_read_property_ex(&_8, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("options"), &_9$$7);
		}
		zephir_read_property_ex(&_10, this_ptr, ZEND_STRL("disabledLevels"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_10) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_11$$8);
			array_init(&_11$$8);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("disabledLevels"), &_11$$8);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

