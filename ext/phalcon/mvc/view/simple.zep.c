
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "Zend/zend_closures.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/string.h"


/**
 * Phalcon\Mvc\View\Simple
 *
 * This component allows to render views without hierarchical levels
 *
 *<code>
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
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Simple) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\View, Simple, phalcon, mvc_view_simple, phalcon_di_injectable_ce, phalcon_mvc_view_simple_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("_viewsDir"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("_partialsDir"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("_viewParams"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var \Phalcon\Mvc\View\EngineInterface[]|false
	 */
	zend_declare_property_bool(phalcon_mvc_view_simple_ce, SL("_engines"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array|null
	 */
	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("_registeredEngines"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("_activeRenderPath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("_content"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_mvc_view_simple_ce, SL("_cache"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("_cacheOptions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_view_simple_ce TSRMLS_CC, 1, phalcon_mvc_viewbaseinterface_ce);
	return SUCCESS;

}

/**
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getRegisteredEngines) {

	

	RETURN_MEMBER(getThis(), "_registeredEngines");

}

/**
 * Phalcon\Mvc\View\Simple constructor
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, __construct) {

	zval *options_param = NULL;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	zephir_update_property_this(getThis(), SL("_options"), options TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets views directory. Depending of your platform, always add a trailing slash or backslash
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setViewsDir) {

	zval *viewsDir_param = NULL;
	zval *viewsDir = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &viewsDir_param);

	if (UNEXPECTED(Z_TYPE_P(viewsDir_param) != IS_STRING && Z_TYPE_P(viewsDir_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewsDir' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(viewsDir_param) == IS_STRING)) {
		zephir_get_strval(viewsDir, viewsDir_param);
	} else {
		ZEPHIR_INIT_VAR(viewsDir);
		ZVAL_EMPTY_STRING(viewsDir);
	}


	zephir_update_property_this(getThis(), SL("_viewsDir"), viewsDir TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets views directory
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getViewsDir) {

	

	RETURN_MEMBER(getThis(), "_viewsDir");

}

/**
 * Register templating engines
 *
 *<code>
 * $this->view->registerEngines(
 *     [
 *         ".phtml" => "Phalcon\\Mvc\\View\\Engine\\Php",
 *         ".volt"  => "Phalcon\\Mvc\\View\\Engine\\Volt",
 *         ".mhtml" => "MyCustomEngine",
 *     ]
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, registerEngines) {

	zval *engines_param = NULL;
	zval *engines = NULL;

	zephir_fetch_params(0, 1, 0, &engines_param);

	engines = engines_param;


	zephir_update_property_this(getThis(), SL("_registeredEngines"), engines TSRMLS_CC);

}

/**
 * Loads registered template engines, if none is registered it will use Phalcon\Mvc\View\Engine\Php
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, _loadTemplateEngines) {

	HashTable *_2$$5;
	HashPosition _1$$5;
	zval *engines = NULL, *dependencyInjector = NULL, *registeredEngines = NULL, *arguments = NULL, *extension = NULL, *engineService = NULL, *engineObject = NULL, *_0$$4, **_3$$5, *_5$$13 = NULL, *_6$$13 = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(engines);
	zephir_read_property_this(&engines, this_ptr, SL("_engines"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(engines)) {
		ZEPHIR_OBS_VAR(dependencyInjector);
		zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(engines);
		array_init(engines);
		ZEPHIR_OBS_VAR(registeredEngines);
		zephir_read_property_this(&registeredEngines, this_ptr, SL("_registeredEngines"), PH_NOISY_CC);
		if (Z_TYPE_P(registeredEngines) != IS_ARRAY) {
			ZEPHIR_INIT_VAR(_0$$4);
			object_init_ex(_0$$4, phalcon_mvc_view_engine_php_ce);
			ZEPHIR_CALL_METHOD(NULL, _0$$4, "__construct", NULL, 401, this_ptr, dependencyInjector);
			zephir_check_call_status();
			zephir_array_update_string(&engines, SL(".phtml"), &_0$$4, PH_COPY | PH_SEPARATE);
		} else {
			if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "A dependency injector container is required to obtain the application services", "phalcon/mvc/view/simple.zep", 159);
				return;
			}
			ZEPHIR_INIT_VAR(arguments);
			zephir_create_array(arguments, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(arguments, this_ptr);
			zephir_array_fast_append(arguments, dependencyInjector);
			zephir_is_iterable(registeredEngines, &_2$$5, &_1$$5, 0, 0, "phalcon/mvc/view/simple.zep", 191);
			for (
			  ; zend_hash_get_current_data_ex(_2$$5, (void**) &_3$$5, &_1$$5) == SUCCESS
			  ; zend_hash_move_forward_ex(_2$$5, &_1$$5)
			) {
				ZEPHIR_GET_HMKEY(extension, _2$$5, _1$$5);
				ZEPHIR_GET_HVALUE(engineService, _3$$5);
				if (Z_TYPE_P(engineService) == IS_OBJECT) {
					if (zephir_instance_of_ev(engineService, zend_ce_closure TSRMLS_CC)) {
						ZEPHIR_INIT_NVAR(engineObject);
						ZEPHIR_CALL_USER_FUNC_ARRAY(engineObject, engineService, arguments);
						zephir_check_call_status();
					} else {
						ZEPHIR_CPY_WRT(engineObject, engineService);
					}
				} else {
					if (Z_TYPE_P(engineService) == IS_STRING) {
						ZEPHIR_CALL_METHOD(&engineObject, dependencyInjector, "getshared", &_4, 0, engineService, arguments);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_NVAR(_5$$13);
						object_init_ex(_5$$13, phalcon_mvc_view_exception_ce);
						ZEPHIR_INIT_LNVAR(_6$$13);
						ZEPHIR_CONCAT_SV(_6$$13, "Invalid template engine registration for extension: ", extension);
						ZEPHIR_CALL_METHOD(NULL, _5$$13, "__construct", &_7, 9, _6$$13);
						zephir_check_call_status();
						zephir_throw_exception_debug(_5$$13, "phalcon/mvc/view/simple.zep", 185 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				zephir_array_update_zval(&engines, extension, &engineObject, PH_COPY | PH_SEPARATE);
			}
		}
		zephir_update_property_this(getThis(), SL("_engines"), engines TSRMLS_CC);
	} else {
		ZEPHIR_OBS_NVAR(engines);
		zephir_read_property_this(&engines, this_ptr, SL("_engines"), PH_NOISY_CC);
	}
	RETURN_CCTOR(engines);

}

/**
 * Tries to render the view with every engine registered in the component
 *
 * @param string path
 * @param array  params
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, _internalRender) {

	HashTable *_4;
	HashPosition _3;
	zend_bool notExists = 0, mustClean = 0, _7$$8, _10$$8;
	zephir_fcall_cache_entry *_13 = NULL, *_16 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *params, *eventsManager = NULL, *engines = NULL, *extension = NULL, *engine = NULL, *viewEnginePath = NULL, *viewsDirPath = NULL, *_2, **_5, *_0$$4 = NULL, *_1$$4, *_6$$6 = NULL, _8$$8 = zval_used_for_init, *_9$$8 = NULL, *_11$$12 = NULL, *_12$$12 = NULL, *_14$$11 = NULL, *_15$$14 = NULL, *_17$$15, *_18$$15, *_19$$16;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &path_param, &params);

	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(path, path_param);
	} else {
		ZEPHIR_INIT_VAR(path);
		ZVAL_EMPTY_STRING(path);
	}


	ZEPHIR_OBS_VAR(eventsManager);
	zephir_read_property_this(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		zephir_update_property_this(getThis(), SL("_activeRenderPath"), path TSRMLS_CC);
	}
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_1$$4);
		ZVAL_STRING(_1$$4, "view:beforeRender", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_0$$4, eventsManager, "fire", NULL, 0, _1$$4, this_ptr);
		zephir_check_temp_parameter(_1$$4);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_0$$4)) {
			RETURN_MM_NULL();
		}
	}
	notExists = 1;
	mustClean = 1;
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_viewsDir"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(viewsDirPath);
	ZEPHIR_CONCAT_VV(viewsDirPath, _2, path);
	ZEPHIR_CALL_METHOD(&engines, this_ptr, "_loadtemplateengines", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(engines, &_4, &_3, 0, 0, "phalcon/mvc/view/simple.zep", 282);
	for (
	  ; zend_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zend_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HMKEY(extension, _4, _3);
		ZEPHIR_GET_HVALUE(engine, _5);
		ZEPHIR_INIT_LNVAR(_6$$6);
		ZEPHIR_CONCAT_VV(_6$$6, viewsDirPath, extension);
		if ((zephir_file_exists(_6$$6 TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_INIT_NVAR(viewEnginePath);
			ZEPHIR_CONCAT_VV(viewEnginePath, viewsDirPath, extension);
		} else {
			_7$$8 = zephir_is_true(extension);
			if (_7$$8) {
				ZEPHIR_SINIT_NVAR(_8$$8);
				ZVAL_LONG(&_8$$8, -zephir_fast_strlen_ev(extension));
				ZEPHIR_INIT_NVAR(_9$$8);
				zephir_substr(_9$$8, viewsDirPath, zephir_get_intval(&_8$$8), 0, ZEPHIR_SUBSTR_NO_LENGTH);
				_7$$8 = ZEPHIR_IS_EQUAL(_9$$8, extension);
			}
			_10$$8 = _7$$8;
			if (_10$$8) {
				_10$$8 = (zephir_file_exists(viewsDirPath TSRMLS_CC) == SUCCESS);
			}
			if (_10$$8) {
				ZEPHIR_CPY_WRT(viewEnginePath, viewsDirPath);
			} else {
				ZEPHIR_INIT_NVAR(viewEnginePath);
				ZVAL_STRING(viewEnginePath, "", 1);
			}
		}
		if (zephir_is_true(viewEnginePath)) {
			if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(_12$$12);
				ZVAL_STRING(_12$$12, "view:beforeRenderView", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_11$$12, eventsManager, "fire", &_13, 0, _12$$12, this_ptr, viewEnginePath);
				zephir_check_temp_parameter(_12$$12);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(_11$$12)) {
					continue;
				}
			}
			ZEPHIR_INIT_NVAR(_14$$11);
			if (mustClean) {
				ZVAL_BOOL(_14$$11, 1);
			} else {
				ZVAL_BOOL(_14$$11, 0);
			}
			ZEPHIR_CALL_METHOD(NULL, engine, "render", NULL, 0, viewEnginePath, params, _14$$11);
			zephir_check_call_status();
			notExists = 0;
			if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(_15$$14);
				ZVAL_STRING(_15$$14, "view:afterRenderView", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", &_16, 0, _15$$14, this_ptr);
				zephir_check_temp_parameter(_15$$14);
				zephir_check_call_status();
			}
			break;
		}
	}
	if (notExists == 1) {
		ZEPHIR_INIT_VAR(_17$$15);
		object_init_ex(_17$$15, phalcon_mvc_view_exception_ce);
		ZEPHIR_INIT_VAR(_18$$15);
		ZEPHIR_CONCAT_SVS(_18$$15, "View '", viewsDirPath, "' was not found in the views directory");
		ZEPHIR_CALL_METHOD(NULL, _17$$15, "__construct", NULL, 9, _18$$15);
		zephir_check_call_status();
		zephir_throw_exception_debug(_17$$15, "phalcon/mvc/view/simple.zep", 283 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_19$$16);
		ZVAL_STRING(_19$$16, "view:afterRender", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _19$$16, this_ptr);
		zephir_check_temp_parameter(_19$$16);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Renders a view
 *
 * @param  string path
 * @param  array  params
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, render) {

	zend_bool _3$$12;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *params = NULL, *cache = NULL, *key = NULL, *lifetime = NULL, *cacheOptions = NULL, *content = NULL, *viewParams = NULL, *mergedParams = NULL, *_1, *_0$$3 = NULL, *_2$$12 = NULL, *_4$$12 = NULL;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &path_param, &params);

	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(path, path_param);
	} else {
		ZEPHIR_INIT_VAR(path);
		ZVAL_EMPTY_STRING(path);
	}
	if (!params) {
		params = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&cache, this_ptr, "getcache", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(cache) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&_0$$3, cache, "isstarted", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_0$$3)) {
			ZEPHIR_INIT_VAR(key);
			ZVAL_NULL(key);
			ZEPHIR_INIT_VAR(lifetime);
			ZVAL_NULL(lifetime);
			ZEPHIR_OBS_VAR(cacheOptions);
			zephir_read_property_this(&cacheOptions, this_ptr, SL("_cacheOptions"), PH_NOISY_CC);
			if (Z_TYPE_P(cacheOptions) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(key);
				zephir_array_isset_string_fetch(&key, cacheOptions, SS("key"), 0 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(lifetime);
				zephir_array_isset_string_fetch(&lifetime, cacheOptions, SS("lifetime"), 0 TSRMLS_CC);
			}
			if (Z_TYPE_P(key) == IS_NULL) {
				ZEPHIR_INIT_NVAR(key);
				zephir_md5(key, path);
			}
			ZEPHIR_CALL_METHOD(&content, cache, "start", NULL, 0, key, lifetime);
			zephir_check_call_status();
			if (Z_TYPE_P(content) != IS_NULL) {
				zephir_update_property_this(getThis(), SL("_content"), content TSRMLS_CC);
				RETURN_CCTOR(content);
			}
		}
	}
	ZEPHIR_INIT_VAR(_1);
	zephir_create_symbol_table(TSRMLS_C);
	
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 140);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(viewParams);
	zephir_read_property_this(&viewParams, this_ptr, SL("_viewParams"), PH_NOISY_CC);
	if (Z_TYPE_P(params) == IS_ARRAY) {
		if (Z_TYPE_P(viewParams) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(mergedParams);
			zephir_fast_array_merge(mergedParams, &(viewParams), &(params) TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(mergedParams, params);
		}
	} else {
		ZEPHIR_CPY_WRT(mergedParams, viewParams);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_internalrender", NULL, 420, path, mergedParams);
	zephir_check_call_status();
	if (Z_TYPE_P(cache) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&_2$$12, cache, "isstarted", NULL, 0);
		zephir_check_call_status();
		_3$$12 = zephir_is_true(_2$$12);
		if (_3$$12) {
			ZEPHIR_CALL_METHOD(&_4$$12, cache, "isfresh", NULL, 0);
			zephir_check_call_status();
			_3$$12 = zephir_is_true(_4$$12);
		}
		if (_3$$12) {
			ZEPHIR_CALL_METHOD(NULL, cache, "save", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(NULL, cache, "stop", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 142);
	zephir_check_call_status();
	RETURN_MM_MEMBER(getThis(), "_content");

}

/**
 * Renders a partial view
 *
 * <code>
 * // Show a partial inside another view
 * $this->partial("shared/footer");
 * </code>
 *
 * <code>
 * // Show a partial inside another view with parameters
 * $this->partial(
 *     "shared/footer",
 *     [
 *         "content" => $html,
 *     ]
 * );
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, partial) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *partialPath_param = NULL, *params = NULL, *viewParams = NULL, *mergedParams = NULL, *_1, *_0$$3;
	zval *partialPath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &partialPath_param, &params);

	if (UNEXPECTED(Z_TYPE_P(partialPath_param) != IS_STRING && Z_TYPE_P(partialPath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'partialPath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(partialPath_param) == IS_STRING)) {
		zephir_get_strval(partialPath, partialPath_param);
	} else {
		ZEPHIR_INIT_VAR(partialPath);
		ZVAL_EMPTY_STRING(partialPath);
	}
	if (!params) {
		params = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 140);
	zephir_check_call_status();
	if (Z_TYPE_P(params) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(viewParams);
		zephir_read_property_this(&viewParams, this_ptr, SL("_viewParams"), PH_NOISY_CC);
		if (Z_TYPE_P(viewParams) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(mergedParams);
			zephir_fast_array_merge(mergedParams, &(viewParams), &(params) TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(mergedParams, params);
		}
		ZEPHIR_INIT_VAR(_0$$3);
		zephir_create_symbol_table(TSRMLS_C);
		
	} else {
		ZEPHIR_CPY_WRT(mergedParams, params);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_internalrender", NULL, 420, partialPath, mergedParams);
	zephir_check_call_status();
	if (Z_TYPE_P(params) == IS_ARRAY) {
		zephir_update_property_this(getThis(), SL("_viewParams"), viewParams TSRMLS_CC);
	}
	ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 142);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_content"), PH_NOISY_CC);
	zend_print_zval(_1, 0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the cache options
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setCacheOptions) {

	zval *options_param = NULL;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(options, options_param);


	zephir_update_property_this(getThis(), SL("_cacheOptions"), options TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the cache options
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getCacheOptions) {

	

	RETURN_MEMBER(getThis(), "_cacheOptions");

}

/**
 * Create a Phalcon\Cache based on the internal cache options
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, _createCache) {

	zval *dependencyInjector = NULL, *cacheService = NULL, *cacheOptions = NULL, *viewCache = NULL, *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "A dependency injector container is required to obtain the view cache services", "phalcon/mvc/view/simple.zep", 493);
		return;
	}
	ZEPHIR_INIT_VAR(cacheService);
	ZVAL_STRING(cacheService, "viewCache", 1);
	ZEPHIR_OBS_VAR(cacheOptions);
	zephir_read_property_this(&cacheOptions, this_ptr, SL("_cacheOptions"), PH_NOISY_CC);
	if (Z_TYPE_P(cacheOptions) == IS_ARRAY) {
		if (zephir_array_isset_string(cacheOptions, SS("service"))) {
			ZEPHIR_OBS_NVAR(cacheService);
			zephir_array_isset_string_fetch(&cacheService, cacheOptions, SS("service"), 0 TSRMLS_CC);
		}
	}
	ZEPHIR_CALL_METHOD(&_0, dependencyInjector, "getshared", NULL, 0, cacheService);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(viewCache, _0);
	if (Z_TYPE_P(viewCache) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "The injected caching service is invalid", "phalcon/mvc/view/simple.zep", 510);
		return;
	}
	RETURN_CCTOR(viewCache);

}

/**
 * Returns the cache instance used to cache
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getCache) {

	zend_bool _1;
	zval *_0, *_2, *_3$$3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_cache"), PH_NOISY_CC);
	_1 = zephir_is_true(_0);
	if (_1) {
		ZEPHIR_OBS_VAR(_2);
		zephir_read_property_this(&_2, this_ptr, SL("_cache"), PH_NOISY_CC);
		_1 = Z_TYPE_P(_2) != IS_OBJECT;
	}
	if (_1) {
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "_createcache", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_this(getThis(), SL("_cache"), _3$$3 TSRMLS_CC);
	}
	RETURN_MM_MEMBER(getThis(), "_cache");

}

/**
 * Cache the actual view render to certain level
 *
 *<code>
 * $this->view->cache(
 *     [
 *         "key"      => "my-key",
 *         "lifetime" => 86400,
 *     ]
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, cache) {

	zval *options = NULL;

	zephir_fetch_params(0, 0, 1, &options);

	if (!options) {
		options = ZEPHIR_GLOBAL(global_true);
	}


	if (Z_TYPE_P(options) == IS_ARRAY) {
		if (1) {
			zephir_update_property_this(getThis(), SL("_cache"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(getThis(), SL("_cache"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
		zephir_update_property_this(getThis(), SL("_cacheOptions"), options TSRMLS_CC);
	} else {
		if (zephir_is_true(options)) {
			if (1) {
				zephir_update_property_this(getThis(), SL("_cache"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
			} else {
				zephir_update_property_this(getThis(), SL("_cache"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
			}
		} else {
			if (0) {
				zephir_update_property_this(getThis(), SL("_cache"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
			} else {
				zephir_update_property_this(getThis(), SL("_cache"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
			}
		}
	}
	RETURN_THISW();

}

/**
 * Adds parameters to views (alias of setVar)
 *
 *<code>
 * $this->view->setParamToView("products", $products);
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setParamToView) {

	zval *key_param = NULL, *value;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	zephir_update_property_array(this_ptr, SL("_viewParams"), key, value TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Set all the render params
 *
 *<code>
 * $this->view->setVars(
 *     [
 *         "products" => $products,
 *     ]
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setVars) {

	zend_bool merge, _0;
	zval *params_param = NULL, *merge_param = NULL, *_1, *_2$$3, *_3$$3;
	zval *params = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &params_param, &merge_param);

	params = params_param;
	if (!merge_param) {
		merge = 1;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	_0 = merge;
	if (_0) {
		ZEPHIR_OBS_VAR(_1);
		zephir_read_property_this(&_1, this_ptr, SL("_viewParams"), PH_NOISY_CC);
		_0 = Z_TYPE_P(_1) == IS_ARRAY;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(_2$$3);
		_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_viewParams"), PH_NOISY_CC);
		zephir_fast_array_merge(_2$$3, &(_3$$3), &(params) TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_viewParams"), _2$$3 TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_viewParams"), params TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Set a single view parameter
 *
 *<code>
 * $this->view->setVar("products", $products);
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setVar) {

	zval *key_param = NULL, *value;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	zephir_update_property_array(this_ptr, SL("_viewParams"), key, value TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns a parameter previously set in the view
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getVar) {

	zval *key_param = NULL, *value = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_viewParams"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&value, _0, key, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	RETURN_MM_NULL();

}

/**
 * Returns parameters to views
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getParamsToView) {

	

	RETURN_MEMBER(getThis(), "_viewParams");

}

/**
 * Externally sets the view content
 *
 *<code>
 * $this->view->setContent("<h1>hello</h1>");
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setContent) {

	zval *content_param = NULL;
	zval *content = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

	if (UNEXPECTED(Z_TYPE_P(content_param) != IS_STRING && Z_TYPE_P(content_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'content' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(content_param) == IS_STRING)) {
		zephir_get_strval(content, content_param);
	} else {
		ZEPHIR_INIT_VAR(content);
		ZVAL_EMPTY_STRING(content);
	}


	zephir_update_property_this(getThis(), SL("_content"), content TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns cached output from another view stage
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getContent) {

	

	RETURN_MEMBER(getThis(), "_content");

}

/**
 * Returns the path of the view that is currently rendered
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getActiveRenderPath) {

	

	RETURN_MEMBER(getThis(), "_activeRenderPath");

}

/**
 * Magic method to pass variables to the views
 *
 *<code>
 * $this->view->products = $products;
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, __set) {

	zval *key_param = NULL, *value;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	zephir_update_property_array(this_ptr, SL("_viewParams"), key, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Magic method to retrieve a variable passed to the view
 *
 *<code>
 * echo $this->view->products;
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, __get) {

	zval *key_param = NULL, *value = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_viewParams"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&value, _0, key, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	RETURN_MM_NULL();

}

