
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
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
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

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_registeredEngines");

}

/**
 * Phalcon\Mvc\View\Simple constructor
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, __construct) {

	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	zephir_update_property_zval(this_ptr, SL("_options"), &options);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets views directory. Depending of your platform, always add a trailing slash or backslash
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setViewsDir) {

	zval *viewsDir_param = NULL;
	zval viewsDir;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewsDir);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &viewsDir_param);

	if (UNEXPECTED(Z_TYPE_P(viewsDir_param) != IS_STRING && Z_TYPE_P(viewsDir_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewsDir' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(viewsDir_param) == IS_STRING)) {
		zephir_get_strval(&viewsDir, viewsDir_param);
	} else {
		ZEPHIR_INIT_VAR(&viewsDir);
		ZVAL_EMPTY_STRING(&viewsDir);
	}


	zephir_update_property_zval(this_ptr, SL("_viewsDir"), &viewsDir);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets views directory
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getViewsDir) {

	zval *this_ptr = getThis();


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
	zval engines;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&engines);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &engines_param);

	ZEPHIR_OBS_COPY_OR_DUP(&engines, engines_param);


	zephir_update_property_zval(this_ptr, SL("_registeredEngines"), &engines);
	ZEPHIR_MM_RESTORE();

}

/**
 * Loads registered template engines, if none is registered it will use Phalcon\Mvc\View\Engine\Php
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, _loadTemplateEngines) {

	zval _9$$12, _15$$19;
	zend_class_entry *_6$$9, *_14$$16;
	zend_string *_4$$5;
	zend_ulong _3$$5;
	zval engines, di, registeredEngines, extension, engineService, engineObject, _0$$4, *_1$$5, _2$$5, _5$$9, _10$$13, _11$$13, _13$$16, _16$$20, _17$$20;
	zephir_fcall_cache_entry *_7 = NULL, *_8 = NULL, *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&engines);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&registeredEngines);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&engineService);
	ZVAL_UNDEF(&engineObject);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_10$$13);
	ZVAL_UNDEF(&_11$$13);
	ZVAL_UNDEF(&_13$$16);
	ZVAL_UNDEF(&_16$$20);
	ZVAL_UNDEF(&_17$$20);
	ZVAL_UNDEF(&_9$$12);
	ZVAL_UNDEF(&_15$$19);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&engines);
	zephir_read_property(&engines, this_ptr, SL("_engines"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&engines)) {
		ZEPHIR_OBS_VAR(&di);
		zephir_read_property(&di, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(&engines);
		array_init(&engines);
		ZEPHIR_OBS_VAR(&registeredEngines);
		zephir_read_property(&registeredEngines, this_ptr, SL("_registeredEngines"), PH_NOISY_CC);
		if (Z_TYPE_P(&registeredEngines) != IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_0$$4);
			object_init_ex(&_0$$4, phalcon_mvc_view_engine_php_ce);
			ZEPHIR_CALL_METHOD(NULL, &_0$$4, "__construct", NULL, 377, this_ptr, &di);
			zephir_check_call_status();
			zephir_array_update_string(&engines, SL(".phtml"), &_0$$4, PH_COPY | PH_SEPARATE);
		} else {
			if (Z_TYPE_P(&di) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "A dependency injector container is required to obtain the application services", "phalcon/mvc/view/simple.zep", 148);
				return;
			}
			zephir_is_iterable(&registeredEngines, 0, "phalcon/mvc/view/simple.zep", 176);
			if (Z_TYPE_P(&registeredEngines) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&registeredEngines), _3$$5, _4$$5, _1$$5)
				{
					ZEPHIR_INIT_NVAR(&extension);
					if (_4$$5 != NULL) { 
						ZVAL_STR_COPY(&extension, _4$$5);
					} else {
						ZVAL_LONG(&extension, _3$$5);
					}
					ZEPHIR_INIT_NVAR(&engineService);
					ZVAL_COPY(&engineService, _1$$5);
					if (Z_TYPE_P(&engineService) == IS_OBJECT) {
						if (zephir_instance_of_ev(&engineService, zend_ce_closure TSRMLS_CC)) {
							_6$$9 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
							ZEPHIR_CALL_CE_STATIC(&_5$$9, _6$$9, "bind", &_7, 0, &engineService, &di);
							zephir_check_call_status();
							ZEPHIR_CPY_WRT(&engineService, &_5$$9);
							ZEPHIR_CALL_FUNCTION(&engineObject, "call_user_func", &_8, 287, &engineService, this_ptr);
							zephir_check_call_status();
						} else {
							ZEPHIR_CPY_WRT(&engineObject, &engineService);
						}
					} else {
						if (Z_TYPE_P(&engineService) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_9$$12);
							zephir_create_array(&_9$$12, 1, 0 TSRMLS_CC);
							zephir_array_fast_append(&_9$$12, this_ptr);
							ZEPHIR_CALL_METHOD(&engineObject, &di, "getshared", NULL, 0, &engineService, &_9$$12);
							zephir_check_call_status();
						} else {
							ZEPHIR_INIT_NVAR(&_10$$13);
							object_init_ex(&_10$$13, phalcon_mvc_view_exception_ce);
							ZEPHIR_INIT_LNVAR(_11$$13);
							ZEPHIR_CONCAT_SV(&_11$$13, "Invalid template engine registration for extension: ", &extension);
							ZEPHIR_CALL_METHOD(NULL, &_10$$13, "__construct", &_12, 4, &_11$$13);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_10$$13, "phalcon/mvc/view/simple.zep", 170 TSRMLS_CC);
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					zephir_array_update_zval(&engines, &extension, &engineObject, PH_COPY | PH_SEPARATE);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &registeredEngines, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_2$$5, &registeredEngines, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_2$$5)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&extension, &registeredEngines, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&engineService, &registeredEngines, "current", NULL, 0);
					zephir_check_call_status();
						if (Z_TYPE_P(&engineService) == IS_OBJECT) {
							if (zephir_instance_of_ev(&engineService, zend_ce_closure TSRMLS_CC)) {
								_14$$16 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
								ZEPHIR_CALL_CE_STATIC(&_13$$16, _14$$16, "bind", &_7, 0, &engineService, &di);
								zephir_check_call_status();
								ZEPHIR_CPY_WRT(&engineService, &_13$$16);
								ZEPHIR_CALL_FUNCTION(&engineObject, "call_user_func", &_8, 287, &engineService, this_ptr);
								zephir_check_call_status();
							} else {
								ZEPHIR_CPY_WRT(&engineObject, &engineService);
							}
						} else {
							if (Z_TYPE_P(&engineService) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_15$$19);
								zephir_create_array(&_15$$19, 1, 0 TSRMLS_CC);
								zephir_array_fast_append(&_15$$19, this_ptr);
								ZEPHIR_CALL_METHOD(&engineObject, &di, "getshared", NULL, 0, &engineService, &_15$$19);
								zephir_check_call_status();
							} else {
								ZEPHIR_INIT_NVAR(&_16$$20);
								object_init_ex(&_16$$20, phalcon_mvc_view_exception_ce);
								ZEPHIR_INIT_LNVAR(_17$$20);
								ZEPHIR_CONCAT_SV(&_17$$20, "Invalid template engine registration for extension: ", &extension);
								ZEPHIR_CALL_METHOD(NULL, &_16$$20, "__construct", &_12, 4, &_17$$20);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_16$$20, "phalcon/mvc/view/simple.zep", 170 TSRMLS_CC);
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
						zephir_array_update_zval(&engines, &extension, &engineObject, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &registeredEngines, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&engineService);
			ZEPHIR_INIT_NVAR(&extension);
		}
		zephir_update_property_zval(this_ptr, SL("_engines"), &engines);
	} else {
		ZEPHIR_OBS_NVAR(&engines);
		zephir_read_property(&engines, this_ptr, SL("_engines"), PH_NOISY_CC);
	}
	RETURN_CCTOR(&engines);

}

/**
 * Tries to render the view with every engine registered in the component
 *
 * @param array  params
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, _internalRender) {

	zend_string *_6;
	zend_ulong _5;
	zend_bool notExists = 0, mustClean = 0, _8$$8, _11$$8, _19$$17, _22$$17;
	zephir_fcall_cache_entry *_14 = NULL, *_17 = NULL, *_25 = NULL, *_28 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *params, params_sub, eventsManager, engines, extension, engine, viewEnginePath, viewsDirPath, _2, *_3, _4, _0$$4, _1$$4, _7$$6, _9$$8, _10$$8, _12$$12, _13$$12, _15$$11, _16$$14, _18$$15, _20$$17, _21$$17, _23$$21, _24$$21, _26$$20, _27$$23, _29$$24, _30$$24, _31$$25;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&params_sub);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&engines);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&engine);
	ZVAL_UNDEF(&viewEnginePath);
	ZVAL_UNDEF(&viewsDirPath);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_13$$12);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_16$$14);
	ZVAL_UNDEF(&_18$$15);
	ZVAL_UNDEF(&_20$$17);
	ZVAL_UNDEF(&_21$$17);
	ZVAL_UNDEF(&_23$$21);
	ZVAL_UNDEF(&_24$$21);
	ZVAL_UNDEF(&_26$$20);
	ZVAL_UNDEF(&_27$$23);
	ZVAL_UNDEF(&_29$$24);
	ZVAL_UNDEF(&_30$$24);
	ZVAL_UNDEF(&_31$$25);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &path_param, &params);

	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(&path, path_param);
	} else {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_EMPTY_STRING(&path);
	}


	ZEPHIR_OBS_VAR(&eventsManager);
	zephir_read_property(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		zephir_update_property_zval(this_ptr, SL("_activeRenderPath"), &path);
	}
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZVAL_STRING(&_1$$4, "view:beforeRender");
		ZEPHIR_CALL_METHOD(&_0$$4, &eventsManager, "fire", NULL, 0, &_1$$4, this_ptr);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_0$$4)) {
			RETURN_MM_NULL();
		}
	}
	notExists = 1;
	mustClean = 1;
	zephir_read_property(&_2, this_ptr, SL("_viewsDir"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&viewsDirPath);
	ZEPHIR_CONCAT_VV(&viewsDirPath, &_2, &path);
	ZEPHIR_CALL_METHOD(&engines, this_ptr, "_loadtemplateengines", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&engines, 0, "phalcon/mvc/view/simple.zep", 266);
	if (Z_TYPE_P(&engines) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&engines), _5, _6, _3)
		{
			ZEPHIR_INIT_NVAR(&extension);
			if (_6 != NULL) { 
				ZVAL_STR_COPY(&extension, _6);
			} else {
				ZVAL_LONG(&extension, _5);
			}
			ZEPHIR_INIT_NVAR(&engine);
			ZVAL_COPY(&engine, _3);
			ZEPHIR_INIT_LNVAR(_7$$6);
			ZEPHIR_CONCAT_VV(&_7$$6, &viewsDirPath, &extension);
			if ((zephir_file_exists(&_7$$6 TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_INIT_NVAR(&viewEnginePath);
				ZEPHIR_CONCAT_VV(&viewEnginePath, &viewsDirPath, &extension);
			} else {
				_8$$8 = zephir_is_true(&extension);
				if (_8$$8) {
					ZVAL_LONG(&_9$$8, -zephir_fast_strlen_ev(&extension));
					ZEPHIR_INIT_NVAR(&_10$$8);
					zephir_substr(&_10$$8, &viewsDirPath, zephir_get_intval(&_9$$8), 0, ZEPHIR_SUBSTR_NO_LENGTH);
					_8$$8 = ZEPHIR_IS_EQUAL(&_10$$8, &extension);
				}
				_11$$8 = _8$$8;
				if (_11$$8) {
					_11$$8 = (zephir_file_exists(&viewsDirPath TSRMLS_CC) == SUCCESS);
				}
				if (_11$$8) {
					ZEPHIR_CPY_WRT(&viewEnginePath, &viewsDirPath);
				} else {
					ZEPHIR_INIT_NVAR(&viewEnginePath);
					ZVAL_STRING(&viewEnginePath, "");
				}
			}
			if (zephir_is_true(&viewEnginePath)) {
				if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&_13$$12);
					ZVAL_STRING(&_13$$12, "view:beforeRenderView");
					ZEPHIR_CALL_METHOD(&_12$$12, &eventsManager, "fire", &_14, 0, &_13$$12, this_ptr, &viewEnginePath);
					zephir_check_call_status();
					if (ZEPHIR_IS_FALSE_IDENTICAL(&_12$$12)) {
						continue;
					}
				}
				if (mustClean) {
					ZVAL_BOOL(&_15$$11, 1);
				} else {
					ZVAL_BOOL(&_15$$11, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, &engine, "render", NULL, 0, &viewEnginePath, params, &_15$$11);
				zephir_check_call_status();
				notExists = 0;
				if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&_16$$14);
					ZVAL_STRING(&_16$$14, "view:afterRenderView");
					ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_17, 0, &_16$$14, this_ptr);
					zephir_check_call_status();
				}
				break;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &engines, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_4, &engines, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&extension, &engines, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&engine, &engines, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_18$$15);
				ZEPHIR_CONCAT_VV(&_18$$15, &viewsDirPath, &extension);
				if ((zephir_file_exists(&_18$$15 TSRMLS_CC) == SUCCESS)) {
					ZEPHIR_INIT_NVAR(&viewEnginePath);
					ZEPHIR_CONCAT_VV(&viewEnginePath, &viewsDirPath, &extension);
				} else {
					_19$$17 = zephir_is_true(&extension);
					if (_19$$17) {
						ZVAL_LONG(&_20$$17, -zephir_fast_strlen_ev(&extension));
						ZEPHIR_INIT_NVAR(&_21$$17);
						zephir_substr(&_21$$17, &viewsDirPath, zephir_get_intval(&_20$$17), 0, ZEPHIR_SUBSTR_NO_LENGTH);
						_19$$17 = ZEPHIR_IS_EQUAL(&_21$$17, &extension);
					}
					_22$$17 = _19$$17;
					if (_22$$17) {
						_22$$17 = (zephir_file_exists(&viewsDirPath TSRMLS_CC) == SUCCESS);
					}
					if (_22$$17) {
						ZEPHIR_CPY_WRT(&viewEnginePath, &viewsDirPath);
					} else {
						ZEPHIR_INIT_NVAR(&viewEnginePath);
						ZVAL_STRING(&viewEnginePath, "");
					}
				}
				if (zephir_is_true(&viewEnginePath)) {
					if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(&_24$$21);
						ZVAL_STRING(&_24$$21, "view:beforeRenderView");
						ZEPHIR_CALL_METHOD(&_23$$21, &eventsManager, "fire", &_25, 0, &_24$$21, this_ptr, &viewEnginePath);
						zephir_check_call_status();
						if (ZEPHIR_IS_FALSE_IDENTICAL(&_23$$21)) {
							continue;
						}
					}
					if (mustClean) {
						ZVAL_BOOL(&_26$$20, 1);
					} else {
						ZVAL_BOOL(&_26$$20, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, &engine, "render", NULL, 0, &viewEnginePath, params, &_26$$20);
					zephir_check_call_status();
					notExists = 0;
					if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(&_27$$23);
						ZVAL_STRING(&_27$$23, "view:afterRenderView");
						ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_28, 0, &_27$$23, this_ptr);
						zephir_check_call_status();
					}
					break;
				}
			ZEPHIR_CALL_METHOD(NULL, &engines, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&engine);
	ZEPHIR_INIT_NVAR(&extension);
	if (notExists == 1) {
		ZEPHIR_INIT_VAR(&_29$$24);
		object_init_ex(&_29$$24, phalcon_mvc_view_exception_ce);
		ZEPHIR_INIT_VAR(&_30$$24);
		ZEPHIR_CONCAT_SVS(&_30$$24, "View '", &viewsDirPath, "' was not found in the views directory");
		ZEPHIR_CALL_METHOD(NULL, &_29$$24, "__construct", NULL, 4, &_30$$24);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_29$$24, "phalcon/mvc/view/simple.zep", 267 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_31$$25);
		ZVAL_STRING(&_31$$25, "view:afterRender");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_31$$25, this_ptr);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Renders a view
 *
 * @param  array  params
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, render) {

	zend_bool _3$$12;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *params = NULL, params_sub, __$null, cache, key, lifetime, cacheOptions, content, viewParams, mergedParams, _1, _0$$3, _2$$12, _4$$12;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&params_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&cache);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&lifetime);
	ZVAL_UNDEF(&cacheOptions);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&viewParams);
	ZVAL_UNDEF(&mergedParams);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$12);
	ZVAL_UNDEF(&_4$$12);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &path_param, &params);

	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(&path, path_param);
	} else {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_EMPTY_STRING(&path);
	}
	if (!params) {
		params = &params_sub;
		params = &__$null;
	}


	ZEPHIR_CALL_METHOD(&cache, this_ptr, "getcache", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&cache) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&_0$$3, &cache, "isstarted", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_0$$3)) {
			ZEPHIR_INIT_VAR(&key);
			ZVAL_NULL(&key);
			ZEPHIR_INIT_VAR(&lifetime);
			ZVAL_NULL(&lifetime);
			ZEPHIR_OBS_VAR(&cacheOptions);
			zephir_read_property(&cacheOptions, this_ptr, SL("_cacheOptions"), PH_NOISY_CC);
			if (Z_TYPE_P(&cacheOptions) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&key);
				zephir_array_isset_string_fetch(&key, &cacheOptions, SL("key"), 0);
				ZEPHIR_OBS_NVAR(&lifetime);
				zephir_array_isset_string_fetch(&lifetime, &cacheOptions, SL("lifetime"), 0);
			}
			if (Z_TYPE_P(&key) == IS_NULL) {
				ZEPHIR_INIT_NVAR(&key);
				zephir_md5(&key, &path);
			}
			ZEPHIR_CALL_METHOD(&content, &cache, "start", NULL, 0, &key, &lifetime);
			zephir_check_call_status();
			if (Z_TYPE_P(&content) != IS_NULL) {
				zephir_update_property_zval(this_ptr, SL("_content"), &content);
				RETURN_CCTOR(&content);
			}
		}
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_symbol_table(TSRMLS_C);
	
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 114);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&viewParams);
	zephir_read_property(&viewParams, this_ptr, SL("_viewParams"), PH_NOISY_CC);
	if (Z_TYPE_P(params) == IS_ARRAY) {
		if (Z_TYPE_P(&viewParams) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&mergedParams);
			zephir_fast_array_merge(&mergedParams, &viewParams, params TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(&mergedParams, params);
		}
	} else {
		ZEPHIR_CPY_WRT(&mergedParams, &viewParams);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_internalrender", NULL, 394, &path, &mergedParams);
	zephir_check_call_status();
	if (Z_TYPE_P(&cache) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&_2$$12, &cache, "isstarted", NULL, 0);
		zephir_check_call_status();
		_3$$12 = zephir_is_true(&_2$$12);
		if (_3$$12) {
			ZEPHIR_CALL_METHOD(&_4$$12, &cache, "isfresh", NULL, 0);
			zephir_check_call_status();
			_3$$12 = zephir_is_true(&_4$$12);
		}
		if (_3$$12) {
			ZEPHIR_CALL_METHOD(NULL, &cache, "save", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &cache, "stop", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 116);
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
	zval *partialPath_param = NULL, *params = NULL, params_sub, __$null, viewParams, mergedParams, _1, _0$$3;
	zval partialPath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&partialPath);
	ZVAL_UNDEF(&params_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&viewParams);
	ZVAL_UNDEF(&mergedParams);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &partialPath_param, &params);

	if (UNEXPECTED(Z_TYPE_P(partialPath_param) != IS_STRING && Z_TYPE_P(partialPath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'partialPath' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(partialPath_param) == IS_STRING)) {
		zephir_get_strval(&partialPath, partialPath_param);
	} else {
		ZEPHIR_INIT_VAR(&partialPath);
		ZVAL_EMPTY_STRING(&partialPath);
	}
	if (!params) {
		params = &params_sub;
		params = &__$null;
	}


	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 114);
	zephir_check_call_status();
	if (Z_TYPE_P(params) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&viewParams);
		zephir_read_property(&viewParams, this_ptr, SL("_viewParams"), PH_NOISY_CC);
		if (Z_TYPE_P(&viewParams) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&mergedParams);
			zephir_fast_array_merge(&mergedParams, &viewParams, params TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(&mergedParams, params);
		}
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_symbol_table(TSRMLS_C);
		
	} else {
		ZEPHIR_CPY_WRT(&mergedParams, params);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_internalrender", NULL, 394, &partialPath, &mergedParams);
	zephir_check_call_status();
	if (Z_TYPE_P(params) == IS_ARRAY) {
		zephir_update_property_zval(this_ptr, SL("_viewParams"), &viewParams);
	}
	ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 116);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("_content"), PH_NOISY_CC | PH_READONLY);
	zend_print_zval(&_1, 0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the cache options
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setCacheOptions) {

	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(&options, options_param);


	zephir_update_property_zval(this_ptr, SL("_cacheOptions"), &options);
	RETURN_THIS();

}

/**
 * Returns the cache options
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getCacheOptions) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_cacheOptions");

}

/**
 * Create a Phalcon\Cache based on the internal cache options
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, _createCache) {

	zval dependencyInjector, cacheService, cacheOptions, viewCache, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&cacheService);
	ZVAL_UNDEF(&cacheOptions);
	ZVAL_UNDEF(&viewCache);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&dependencyInjector);
	zephir_read_property(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "A dependency injector container is required to obtain the view cache services", "phalcon/mvc/view/simple.zep", 474);
		return;
	}
	ZEPHIR_INIT_VAR(&cacheService);
	ZVAL_STRING(&cacheService, "viewCache");
	ZEPHIR_OBS_VAR(&cacheOptions);
	zephir_read_property(&cacheOptions, this_ptr, SL("_cacheOptions"), PH_NOISY_CC);
	if (Z_TYPE_P(&cacheOptions) == IS_ARRAY) {
		if (zephir_array_isset_string(&cacheOptions, SL("service"))) {
			ZEPHIR_OBS_NVAR(&cacheService);
			zephir_array_isset_string_fetch(&cacheService, &cacheOptions, SL("service"), 0);
		}
	}
	ZEPHIR_CALL_METHOD(&_0, &dependencyInjector, "getshared", NULL, 0, &cacheService);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&viewCache, &_0);
	if (Z_TYPE_P(&viewCache) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "The injected caching service is invalid", "phalcon/mvc/view/simple.zep", 491);
		return;
	}
	RETURN_CCTOR(&viewCache);

}

/**
 * Returns the cache instance used to cache
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getCache) {

	zend_bool _1;
	zval _0, _2, _3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_cache"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_is_true(&_0);
	if (_1) {
		ZEPHIR_OBS_VAR(&_2);
		zephir_read_property(&_2, this_ptr, SL("_cache"), PH_NOISY_CC);
		_1 = Z_TYPE_P(&_2) != IS_OBJECT;
	}
	if (_1) {
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "_createcache", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_cache"), &_3$$3);
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

	zval *options = NULL, options_sub, __$true, __$false;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 0, 1, &options);

	if (!options) {
		options = &options_sub;
		options = &__$true;
	}


	if (Z_TYPE_P(options) == IS_ARRAY) {
		if (1) {
			zephir_update_property_zval(this_ptr, SL("_cache"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("_cache"), &__$false);
		}
		zephir_update_property_zval(this_ptr, SL("_cacheOptions"), options);
	} else {
		if (zephir_is_true(options)) {
			if (1) {
				zephir_update_property_zval(this_ptr, SL("_cache"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, SL("_cache"), &__$false);
			}
		} else {
			if (0) {
				zephir_update_property_zval(this_ptr, SL("_cache"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, SL("_cache"), &__$false);
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

	zval *key_param = NULL, *value, value_sub;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}


	zephir_update_property_array(this_ptr, SL("_viewParams"), &key, value);
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
	zval *params_param = NULL, *merge_param = NULL, _1, _2$$3, _3$$3;
	zval params;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &params_param, &merge_param);

	ZEPHIR_OBS_COPY_OR_DUP(&params, params_param);
	if (!merge_param) {
		merge = 1;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	_0 = merge;
	if (_0) {
		ZEPHIR_OBS_VAR(&_1);
		zephir_read_property(&_1, this_ptr, SL("_viewParams"), PH_NOISY_CC);
		_0 = Z_TYPE_P(&_1) == IS_ARRAY;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_read_property(&_3$$3, this_ptr, SL("_viewParams"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_2$$3, &_3$$3, &params TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_viewParams"), &_2$$3);
	} else {
		zephir_update_property_zval(this_ptr, SL("_viewParams"), &params);
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

	zval *key_param = NULL, *value, value_sub;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}


	zephir_update_property_array(this_ptr, SL("_viewParams"), &key, value);
	RETURN_THIS();

}

/**
 * Returns a parameter previously set in the view
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getVar) {

	zval *key_param = NULL, value, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}


	zephir_read_property(&_0, this_ptr, SL("_viewParams"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&value, &_0, &key, 1 TSRMLS_CC)) {
		RETURN_CTOR(&value);
	}
	RETURN_MM_NULL();

}

/**
 * Returns parameters to views
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getParamsToView) {

	zval *this_ptr = getThis();


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
	zval content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

	if (UNEXPECTED(Z_TYPE_P(content_param) != IS_STRING && Z_TYPE_P(content_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'content' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(content_param) == IS_STRING)) {
		zephir_get_strval(&content, content_param);
	} else {
		ZEPHIR_INIT_VAR(&content);
		ZVAL_EMPTY_STRING(&content);
	}


	zephir_update_property_zval(this_ptr, SL("_content"), &content);
	RETURN_THIS();

}

/**
 * Returns cached output from another view stage
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getContent) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_content");

}

/**
 * Returns the path of the view that is currently rendered
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getActiveRenderPath) {

	zval *this_ptr = getThis();


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

	zval *key_param = NULL, *value, value_sub;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}


	zephir_update_property_array(this_ptr, SL("_viewParams"), &key, value);
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

	zval *key_param = NULL, value, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}


	zephir_read_property(&_0, this_ptr, SL("_viewParams"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&value, &_0, &key, 1 TSRMLS_CC)) {
		RETURN_CTOR(&value);
	}
	RETURN_MM_NULL();

}

