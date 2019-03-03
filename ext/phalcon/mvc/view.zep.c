
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
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "Zend/zend_closures.h"
#include "kernel/file.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\View
 *
 * Phalcon\Mvc\View is a class for working with the "view" portion of the model-view-controller pattern.
 * That is, it exists to help keep the view script separate from the model and controller scripts.
 * It provides a system of helpers, output filters, and variable escaping.
 *
 * <code>
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
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_View) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc, View, phalcon, mvc_view, phalcon_di_injectable_ce, phalcon_mvc_view_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_view_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_mvc_view_ce, SL("_basePath"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_mvc_view_ce, SL("_content"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalcon_mvc_view_ce, SL("_renderLevel"), 5, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalcon_mvc_view_ce, SL("_currentRenderLevel"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_ce, SL("_disabledLevels"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_ce, SL("_viewParams"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_ce, SL("_layout"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_mvc_view_ce, SL("_layoutsDir"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_mvc_view_ce, SL("_partialsDir"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_ce, SL("_viewsDirs"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_ce, SL("_templatesBefore"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_ce, SL("_templatesAfter"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_mvc_view_ce, SL("_engines"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_ce, SL("_registeredEngines"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_mvc_view_ce, SL("_mainView"), "index", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_ce, SL("_controllerName"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_ce, SL("_actionName"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_ce, SL("_params"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_ce, SL("_pickView"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_ce, SL("_cache"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalcon_mvc_view_ce, SL("_cacheLevel"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_ce, SL("_activeRenderPaths"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_mvc_view_ce, SL("_disabled"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_mvc_view_ce->create_object = zephir_init_properties_Phalcon_Mvc_View;
	/**
	 * Render Level: To the main layout
	 *
	 */
	zephir_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_MAIN_LAYOUT"), 5);

	/**
	 * Render Level: Render to the templates "after"
	 *
	 */
	zephir_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_AFTER_TEMPLATE"), 4);

	/**
	 * Render Level: To the controller layout
	 *
	 */
	zephir_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_LAYOUT"), 3);

	/**
	 * Render Level: To the templates "before"
	 *
	 */
	zephir_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_BEFORE_TEMPLATE"), 2);

	/**
	 * Render Level: To the action view
	 */
	zephir_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_ACTION_VIEW"), 1);

	/**
	 * Render Level: No render any view
	 *
	 */
	zephir_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_NO_RENDER"), 0);

	/**
	 * Cache Mode
	 */
	zephir_declare_class_constant_long(phalcon_mvc_view_ce, SL("CACHE_MODE_NONE"), 0);

	zephir_declare_class_constant_long(phalcon_mvc_view_ce, SL("CACHE_MODE_INVERSE"), 1);

	zend_class_implements(phalcon_mvc_view_ce TSRMLS_CC, 1, phalcon_mvc_viewinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Mvc_View, getRenderLevel) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_renderLevel");

}

PHP_METHOD(Phalcon_Mvc_View, getCurrentRenderLevel) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_currentRenderLevel");

}

PHP_METHOD(Phalcon_Mvc_View, getRegisteredEngines) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_registeredEngines");

}

/**
 * Phalcon\Mvc\View constructor
 */
PHP_METHOD(Phalcon_Mvc_View, __construct) {

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
 * Checks if a path is absolute or not
 */
PHP_METHOD(Phalcon_Mvc_View, _isAbsolutePath) {

	unsigned char _6, _2$$3, _4$$3;
	zend_bool _5, _1$$3, _3$$3;
	zval *path_param = NULL, _0;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(&path, path_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "PHP_OS");
	if (ZEPHIR_IS_STRING(&_0, "WINNT")) {
		_1$$3 = zephir_fast_strlen_ev(&path) >= 3;
		if (_1$$3) {
			_2$$3 = ZEPHIR_STRING_OFFSET(&path, 1);
			_1$$3 = _2$$3 == ':';
		}
		_3$$3 = _1$$3;
		if (_3$$3) {
			_4$$3 = ZEPHIR_STRING_OFFSET(&path, 2);
			_3$$3 = _4$$3 == '\\';
		}
		RETURN_MM_BOOL(_3$$3);
	}
	_5 = zephir_fast_strlen_ev(&path) >= 1;
	if (_5) {
		_6 = ZEPHIR_STRING_OFFSET(&path, 0);
		_5 = _6 == '/';
	}
	RETURN_MM_BOOL(_5);

}

/**
 * Sets the views directory. Depending of your platform,
 * always add a trailing slash or backslash
 */
PHP_METHOD(Phalcon_Mvc_View, setViewsDir) {

	zend_string *_7$$6;
	zend_ulong _6$$6;
	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *viewsDir = NULL, viewsDir_sub, position, directory, directorySeparator, newViewsDir, _1$$4, _2$$4, _3$$5, *_4$$6, _5$$6, _8$$7, _9$$7, _10$$9, _11$$11, _12$$11, _13$$13;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewsDir_sub);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&directory);
	ZVAL_UNDEF(&directorySeparator);
	ZVAL_UNDEF(&newViewsDir);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_13$$13);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &viewsDir);

	ZEPHIR_SEPARATE_PARAM(viewsDir);


	_0 = Z_TYPE_P(viewsDir) != IS_STRING;
	if (_0) {
		_0 = Z_TYPE_P(viewsDir) != IS_ARRAY;
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "Views directory must be a string or an array", "phalcon/mvc/view.zep", 167);
		return;
	}
	ZEPHIR_INIT_VAR(&directorySeparator);
	ZVAL_STRING(&directorySeparator, "/");
	if (Z_TYPE_P(viewsDir) == IS_STRING) {
		ZVAL_LONG(&_1$$4, -1);
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_substr(&_2$$4, viewsDir, -1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		if (!ZEPHIR_IS_EQUAL(&_2$$4, &directorySeparator)) {
			ZEPHIR_INIT_VAR(&_3$$5);
			ZEPHIR_CONCAT_VV(&_3$$5, viewsDir, &directorySeparator);
			ZEPHIR_CPY_WRT(viewsDir, &_3$$5);
		}
		zephir_update_property_zval(this_ptr, SL("_viewsDirs"), viewsDir);
	} else {
		ZEPHIR_INIT_VAR(&newViewsDir);
		array_init(&newViewsDir);
		zephir_is_iterable(viewsDir, 0, "phalcon/mvc/view.zep", 194);
		if (Z_TYPE_P(viewsDir) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(viewsDir), _6$$6, _7$$6, _4$$6)
			{
				ZEPHIR_INIT_NVAR(&position);
				if (_7$$6 != NULL) { 
					ZVAL_STR_COPY(&position, _7$$6);
				} else {
					ZVAL_LONG(&position, _6$$6);
				}
				ZEPHIR_INIT_NVAR(&directory);
				ZVAL_COPY(&directory, _4$$6);
				if (Z_TYPE_P(&directory) != IS_STRING) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "Views directory item must be a string", "phalcon/mvc/view.zep", 184);
					return;
				}
				ZVAL_LONG(&_8$$7, -1);
				ZEPHIR_INIT_NVAR(&_9$$7);
				zephir_substr(&_9$$7, &directory, -1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
				if (!ZEPHIR_IS_EQUAL(&_9$$7, &directorySeparator)) {
					ZEPHIR_INIT_LNVAR(_10$$9);
					ZEPHIR_CONCAT_VV(&_10$$9, &directory, &directorySeparator);
					zephir_array_update_zval(&newViewsDir, &position, &_10$$9, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_zval(&newViewsDir, &position, &directory, PH_COPY | PH_SEPARATE);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, viewsDir, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_5$$6, viewsDir, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_5$$6)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&position, viewsDir, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&directory, viewsDir, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&directory) != IS_STRING) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "Views directory item must be a string", "phalcon/mvc/view.zep", 184);
						return;
					}
					ZVAL_LONG(&_11$$11, -1);
					ZEPHIR_INIT_NVAR(&_12$$11);
					zephir_substr(&_12$$11, &directory, -1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
					if (!ZEPHIR_IS_EQUAL(&_12$$11, &directorySeparator)) {
						ZEPHIR_INIT_LNVAR(_13$$13);
						ZEPHIR_CONCAT_VV(&_13$$13, &directory, &directorySeparator);
						zephir_array_update_zval(&newViewsDir, &position, &_13$$13, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_update_zval(&newViewsDir, &position, &directory, PH_COPY | PH_SEPARATE);
					}
				ZEPHIR_CALL_METHOD(NULL, viewsDir, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&directory);
		ZEPHIR_INIT_NVAR(&position);
		zephir_update_property_zval(this_ptr, SL("_viewsDirs"), &newViewsDir);
	}
	RETURN_THIS();

}

/**
 * Gets views directory
 */
PHP_METHOD(Phalcon_Mvc_View, getViewsDir) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_viewsDirs");

}

/**
 * Sets the layouts sub-directory. Must be a directory under the views directory.
 * Depending of your platform, always add a trailing slash or backslash
 *
 *<code>
 * $view->setLayoutsDir("../common/layouts/");
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_View, setLayoutsDir) {

	zval *layoutsDir_param = NULL;
	zval layoutsDir;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&layoutsDir);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &layoutsDir_param);

	zephir_get_strval(&layoutsDir, layoutsDir_param);


	zephir_update_property_zval(this_ptr, SL("_layoutsDir"), &layoutsDir);
	RETURN_THIS();

}

/**
 * Gets the current layouts sub-directory
 */
PHP_METHOD(Phalcon_Mvc_View, getLayoutsDir) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_layoutsDir");

}

/**
 * Sets a partials sub-directory. Must be a directory under the views directory.
 * Depending of your platform, always add a trailing slash or backslash
 *
 *<code>
 * $view->setPartialsDir("../common/partials/");
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_View, setPartialsDir) {

	zval *partialsDir_param = NULL;
	zval partialsDir;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&partialsDir);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &partialsDir_param);

	zephir_get_strval(&partialsDir, partialsDir_param);


	zephir_update_property_zval(this_ptr, SL("_partialsDir"), &partialsDir);
	RETURN_THIS();

}

/**
 * Gets the current partials sub-directory
 */
PHP_METHOD(Phalcon_Mvc_View, getPartialsDir) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_partialsDir");

}

/**
 * Sets base path. Depending of your platform, always add a trailing slash or backslash
 *
 * <code>
 * 	$view->setBasePath(__DIR__ . "/");
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_View, setBasePath) {

	zval *basePath_param = NULL;
	zval basePath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&basePath);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &basePath_param);

	zephir_get_strval(&basePath, basePath_param);


	zephir_update_property_zval(this_ptr, SL("_basePath"), &basePath);
	RETURN_THIS();

}

/**
 * Gets base path
 */
PHP_METHOD(Phalcon_Mvc_View, getBasePath) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_basePath");

}

/**
 * Sets the render level for the view
 *
 * <code>
 * // Render the view related to the controller only
 * $this->view->setRenderLevel(
 *     View::LEVEL_LAYOUT
 * );
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_View, setRenderLevel) {

	zval *level_param = NULL, _0;
	zend_long level;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &level_param);

	level = zephir_get_intval(level_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, level);
	zephir_update_property_zval(this_ptr, SL("_renderLevel"), &_0);
	RETURN_THISW();

}

/**
 * Disables a specific level of rendering
 *
 *<code>
 * // Render all levels except ACTION level
 * $this->view->disableLevel(
 *     View::LEVEL_ACTION_VIEW
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_View, disableLevel) {

	zval *level, level_sub, __$true;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&level_sub);
	ZVAL_BOOL(&__$true, 1);

	zephir_fetch_params(0, 1, 0, &level);



	if (Z_TYPE_P(level) == IS_ARRAY) {
		zephir_update_property_zval(this_ptr, SL("_disabledLevels"), level);
	} else {
		zephir_update_property_array(this_ptr, SL("_disabledLevels"), level, &__$true);
	}
	RETURN_THISW();

}

/**
 * Sets default view name. Must be a file without extension in the views directory
 *
 * <code>
 * // Renders as main view views-dir/base.phtml
 * $this->view->setMainView("base");
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_View, setMainView) {

	zval *viewPath_param = NULL;
	zval viewPath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewPath);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &viewPath_param);

	zephir_get_strval(&viewPath, viewPath_param);


	zephir_update_property_zval(this_ptr, SL("_mainView"), &viewPath);
	RETURN_THIS();

}

/**
 * Returns the name of the main view
 */
PHP_METHOD(Phalcon_Mvc_View, getMainView) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_mainView");

}

/**
 * Change the layout to be used instead of using the name of the latest controller name
 *
 * <code>
 * $this->view->setLayout("main");
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_View, setLayout) {

	zval *layout_param = NULL;
	zval layout;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&layout);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &layout_param);

	zephir_get_strval(&layout, layout_param);


	zephir_update_property_zval(this_ptr, SL("_layout"), &layout);
	RETURN_THIS();

}

/**
 * Returns the name of the main view
 */
PHP_METHOD(Phalcon_Mvc_View, getLayout) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_layout");

}

/**
 * Sets a template before the controller layout
 */
PHP_METHOD(Phalcon_Mvc_View, setTemplateBefore) {

	zval _0$$3;
	zval *templateBefore, templateBefore_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&templateBefore_sub);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &templateBefore);



	if (Z_TYPE_P(templateBefore) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_0$$3, templateBefore);
		zephir_update_property_zval(this_ptr, SL("_templatesBefore"), &_0$$3);
	} else {
		zephir_update_property_zval(this_ptr, SL("_templatesBefore"), templateBefore);
	}
	RETURN_THIS();

}

/**
 * Resets any "template before" layouts
 */
PHP_METHOD(Phalcon_Mvc_View, cleanTemplateBefore) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, SL("_templatesBefore"), &_0);
	RETURN_THIS();

}

/**
 * Sets a "template after" controller layout
 */
PHP_METHOD(Phalcon_Mvc_View, setTemplateAfter) {

	zval _0$$3;
	zval *templateAfter, templateAfter_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&templateAfter_sub);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &templateAfter);



	if (Z_TYPE_P(templateAfter) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_0$$3, templateAfter);
		zephir_update_property_zval(this_ptr, SL("_templatesAfter"), &_0$$3);
	} else {
		zephir_update_property_zval(this_ptr, SL("_templatesAfter"), templateAfter);
	}
	RETURN_THIS();

}

/**
 * Resets any template before layouts
 */
PHP_METHOD(Phalcon_Mvc_View, cleanTemplateAfter) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, SL("_templatesAfter"), &_0);
	RETURN_THIS();

}

/**
 * Adds parameters to views (alias of setVar)
 *
 *<code>
 * $this->view->setParamToView("products", $products);
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_View, setParamToView) {

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
PHP_METHOD(Phalcon_Mvc_View, setVars) {

	zend_bool merge;
	zval *params_param = NULL, *merge_param = NULL, _0$$3, _1$$3;
	zval params;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &params_param, &merge_param);

	ZEPHIR_OBS_COPY_OR_DUP(&params, params_param);
	if (!merge_param) {
		merge = 1;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (merge) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_read_property(&_1$$3, this_ptr, SL("_viewParams"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_0$$3, &_1$$3, &params TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_viewParams"), &_0$$3);
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
PHP_METHOD(Phalcon_Mvc_View, setVar) {

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
PHP_METHOD(Phalcon_Mvc_View, getVar) {

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
	if (!(zephir_array_isset_fetch(&value, &_0, &key, 1 TSRMLS_CC))) {
		RETURN_MM_NULL();
	}
	RETURN_CTOR(&value);

}

/**
 * Returns parameters to views
 */
PHP_METHOD(Phalcon_Mvc_View, getParamsToView) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_viewParams");

}

/**
 * Gets the name of the controller rendered
 */
PHP_METHOD(Phalcon_Mvc_View, getControllerName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_controllerName");

}

/**
 * Gets the name of the action rendered
 */
PHP_METHOD(Phalcon_Mvc_View, getActionName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_actionName");

}

/**
 * Starts rendering process enabling the output buffering
 */
PHP_METHOD(Phalcon_Mvc_View, start) {

	zval __$null;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 114);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_content"), &__$null);
	RETURN_THIS();

}

/**
 * Loads registered template engines, if none is registered it will use Phalcon\Mvc\View\Engine\Php
 */
PHP_METHOD(Phalcon_Mvc_View, _loadTemplateEngines) {

	zval _14$$11, _20$$17;
	zend_class_entry *_7$$9, *_16$$15;
	zend_string *_5$$5;
	zend_ulong _4$$5;
	zval engines, di, registeredEngines, engineService, extension, _0$$3, _1$$4, *_2$$5, _3$$5, _6$$9, _10$$12, _11$$12, _13$$11, _15$$15, _17$$18, _18$$18, _19$$17;
	zephir_fcall_cache_entry *_8 = NULL, *_9 = NULL, *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&engines);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&registeredEngines);
	ZVAL_UNDEF(&engineService);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_15$$15);
	ZVAL_UNDEF(&_17$$18);
	ZVAL_UNDEF(&_18$$18);
	ZVAL_UNDEF(&_19$$17);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_20$$17);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&engines);
	zephir_read_property(&engines, this_ptr, SL("_engines"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&engines)) {
		zephir_read_property(&_0$$3, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&di, &_0$$3);
		ZEPHIR_INIT_NVAR(&engines);
		array_init(&engines);
		ZEPHIR_OBS_VAR(&registeredEngines);
		zephir_read_property(&registeredEngines, this_ptr, SL("_registeredEngines"), PH_NOISY_CC);
		if (ZEPHIR_IS_EMPTY(&registeredEngines)) {
			ZEPHIR_INIT_VAR(&_1$$4);
			object_init_ex(&_1$$4, phalcon_mvc_view_engine_php_ce);
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 377, this_ptr, &di);
			zephir_check_call_status();
			zephir_array_update_string(&engines, SL(".phtml"), &_1$$4, PH_COPY | PH_SEPARATE);
		} else {
			if (Z_TYPE_P(&di) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "A dependency injector container is required to obtain the application services", "phalcon/mvc/view.zep", 519);
				return;
			}
			zephir_is_iterable(&registeredEngines, 0, "phalcon/mvc/view.zep", 548);
			if (Z_TYPE_P(&registeredEngines) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&registeredEngines), _4$$5, _5$$5, _2$$5)
				{
					ZEPHIR_INIT_NVAR(&extension);
					if (_5$$5 != NULL) { 
						ZVAL_STR_COPY(&extension, _5$$5);
					} else {
						ZVAL_LONG(&extension, _4$$5);
					}
					ZEPHIR_INIT_NVAR(&engineService);
					ZVAL_COPY(&engineService, _2$$5);
					if (Z_TYPE_P(&engineService) == IS_OBJECT) {
						if (zephir_instance_of_ev(&engineService, zend_ce_closure TSRMLS_CC)) {
							_7$$9 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
							ZEPHIR_CALL_CE_STATIC(&_6$$9, _7$$9, "bind", &_8, 0, &engineService, &di);
							zephir_check_call_status();
							ZEPHIR_CPY_WRT(&engineService, &_6$$9);
							ZEPHIR_CALL_FUNCTION(&_6$$9, "call_user_func", &_9, 287, &engineService, this_ptr);
							zephir_check_call_status();
							zephir_array_update_zval(&engines, &extension, &_6$$9, PH_COPY | PH_SEPARATE);
						} else {
							zephir_array_update_zval(&engines, &extension, &engineService, PH_COPY | PH_SEPARATE);
						}
					} else {
						if (Z_TYPE_P(&engineService) != IS_STRING) {
							ZEPHIR_INIT_NVAR(&_10$$12);
							object_init_ex(&_10$$12, phalcon_mvc_view_exception_ce);
							ZEPHIR_INIT_LNVAR(_11$$12);
							ZEPHIR_CONCAT_SV(&_11$$12, "Invalid template engine registration for extension: ", &extension);
							ZEPHIR_CALL_METHOD(NULL, &_10$$12, "__construct", &_12, 4, &_11$$12);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_10$$12, "phalcon/mvc/view.zep", 542 TSRMLS_CC);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_INIT_NVAR(&_14$$11);
						zephir_create_array(&_14$$11, 1, 0 TSRMLS_CC);
						zephir_array_fast_append(&_14$$11, this_ptr);
						ZEPHIR_CALL_METHOD(&_13$$11, &di, "getshared", NULL, 0, &engineService, &_14$$11);
						zephir_check_call_status();
						zephir_array_update_zval(&engines, &extension, &_13$$11, PH_COPY | PH_SEPARATE);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &registeredEngines, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_3$$5, &registeredEngines, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_3$$5)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&extension, &registeredEngines, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&engineService, &registeredEngines, "current", NULL, 0);
					zephir_check_call_status();
						if (Z_TYPE_P(&engineService) == IS_OBJECT) {
							if (zephir_instance_of_ev(&engineService, zend_ce_closure TSRMLS_CC)) {
								_16$$15 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
								ZEPHIR_CALL_CE_STATIC(&_15$$15, _16$$15, "bind", &_8, 0, &engineService, &di);
								zephir_check_call_status();
								ZEPHIR_CPY_WRT(&engineService, &_15$$15);
								ZEPHIR_CALL_FUNCTION(&_15$$15, "call_user_func", &_9, 287, &engineService, this_ptr);
								zephir_check_call_status();
								zephir_array_update_zval(&engines, &extension, &_15$$15, PH_COPY | PH_SEPARATE);
							} else {
								zephir_array_update_zval(&engines, &extension, &engineService, PH_COPY | PH_SEPARATE);
							}
						} else {
							if (Z_TYPE_P(&engineService) != IS_STRING) {
								ZEPHIR_INIT_NVAR(&_17$$18);
								object_init_ex(&_17$$18, phalcon_mvc_view_exception_ce);
								ZEPHIR_INIT_LNVAR(_18$$18);
								ZEPHIR_CONCAT_SV(&_18$$18, "Invalid template engine registration for extension: ", &extension);
								ZEPHIR_CALL_METHOD(NULL, &_17$$18, "__construct", &_12, 4, &_18$$18);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_17$$18, "phalcon/mvc/view.zep", 542 TSRMLS_CC);
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_INIT_NVAR(&_20$$17);
							zephir_create_array(&_20$$17, 1, 0 TSRMLS_CC);
							zephir_array_fast_append(&_20$$17, this_ptr);
							ZEPHIR_CALL_METHOD(&_19$$17, &di, "getshared", NULL, 0, &engineService, &_20$$17);
							zephir_check_call_status();
							zephir_array_update_zval(&engines, &extension, &_19$$17, PH_COPY | PH_SEPARATE);
						}
					ZEPHIR_CALL_METHOD(NULL, &registeredEngines, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&engineService);
			ZEPHIR_INIT_NVAR(&extension);
		}
		zephir_update_property_zval(this_ptr, SL("_engines"), &engines);
	}
	RETURN_CCTOR(&engines);

}

/**
 * Checks whether view exists on registered extensions and render it
 */
PHP_METHOD(Phalcon_Mvc_View, _engineRender) {

	zend_string *_16$$3, *_42$$24;
	zend_ulong _15$$3, _41$$24;
	zephir_fcall_cache_entry *_5 = NULL, *_9 = NULL, *_10 = NULL, *_12 = NULL, *_20 = NULL, *_23 = NULL, *_27 = NULL, *_30 = NULL, *_35 = NULL, *_36 = NULL, *_38 = NULL, *_46 = NULL, *_49 = NULL, *_53 = NULL, *_56 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, renderLevel = 0, cacheLevel = 0;
	zend_bool silence, mustClean, notExists = 0;
	zval viewPath, _59$$47;
	zval *engines_param = NULL, *viewPath_param = NULL, *silence_param = NULL, *mustClean_param = NULL, *cache = NULL, cache_sub, __$null, key, lifetime, viewsDir, basePath, viewsDirPath, viewOptions, cacheOptions, cachedView, viewParams, eventsManager, extension, engine, viewEnginePath, viewEnginePaths, _0, _1, *_2, _3, _4$$3, *_13$$3, _14$$3, _6$$6, _7$$6, _8$$7, _11$$7, _18$$16, _19$$16, _21$$15, _22$$18, _25$$21, _26$$21, _28$$20, _29$$23, _31$$24, *_39$$24, _40$$24, _32$$27, _33$$27, _34$$28, _37$$28, _44$$37, _45$$37, _47$$36, _48$$39, _51$$42, _52$$42, _54$$41, _55$$44, _57$$46, _58$$47;
	zval engines, _17$$16, _24$$21, _43$$37, _50$$42;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&engines);
	ZVAL_UNDEF(&_17$$16);
	ZVAL_UNDEF(&_24$$21);
	ZVAL_UNDEF(&_43$$37);
	ZVAL_UNDEF(&_50$$42);
	ZVAL_UNDEF(&cache_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&lifetime);
	ZVAL_UNDEF(&viewsDir);
	ZVAL_UNDEF(&basePath);
	ZVAL_UNDEF(&viewsDirPath);
	ZVAL_UNDEF(&viewOptions);
	ZVAL_UNDEF(&cacheOptions);
	ZVAL_UNDEF(&cachedView);
	ZVAL_UNDEF(&viewParams);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&engine);
	ZVAL_UNDEF(&viewEnginePath);
	ZVAL_UNDEF(&viewEnginePaths);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_18$$16);
	ZVAL_UNDEF(&_19$$16);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_22$$18);
	ZVAL_UNDEF(&_25$$21);
	ZVAL_UNDEF(&_26$$21);
	ZVAL_UNDEF(&_28$$20);
	ZVAL_UNDEF(&_29$$23);
	ZVAL_UNDEF(&_31$$24);
	ZVAL_UNDEF(&_40$$24);
	ZVAL_UNDEF(&_32$$27);
	ZVAL_UNDEF(&_33$$27);
	ZVAL_UNDEF(&_34$$28);
	ZVAL_UNDEF(&_37$$28);
	ZVAL_UNDEF(&_44$$37);
	ZVAL_UNDEF(&_45$$37);
	ZVAL_UNDEF(&_47$$36);
	ZVAL_UNDEF(&_48$$39);
	ZVAL_UNDEF(&_51$$42);
	ZVAL_UNDEF(&_52$$42);
	ZVAL_UNDEF(&_54$$41);
	ZVAL_UNDEF(&_55$$44);
	ZVAL_UNDEF(&_57$$46);
	ZVAL_UNDEF(&_58$$47);
	ZVAL_UNDEF(&viewPath);
	ZVAL_UNDEF(&_59$$47);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &engines_param, &viewPath_param, &silence_param, &mustClean_param, &cache);

	zephir_get_arrval(&engines, engines_param);
	zephir_get_strval(&viewPath, viewPath_param);
	silence = zephir_get_boolval(silence_param);
	mustClean = zephir_get_boolval(mustClean_param);
	if (!cache) {
		cache = &cache_sub;
		cache = &__$null;
	}


	notExists = 1;
	ZEPHIR_OBS_VAR(&basePath);
	zephir_read_property(&basePath, this_ptr, SL("_basePath"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&viewParams);
	zephir_read_property(&viewParams, this_ptr, SL("_viewParams"), PH_NOISY_CC);
	zephir_read_property(&_0, this_ptr, SL("_eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_0);
	ZEPHIR_INIT_VAR(&viewEnginePaths);
	array_init(&viewEnginePaths);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getviewsdirs", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&_1, 0, "phalcon/mvc/view.zep", 669);
	if (Z_TYPE_P(&_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1), _2)
		{
			ZEPHIR_INIT_NVAR(&viewsDir);
			ZVAL_COPY(&viewsDir, _2);
			ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "_isabsolutepath", &_5, 378, &viewPath);
			zephir_check_call_status();
			if (!(zephir_is_true(&_4$$3))) {
				ZEPHIR_INIT_NVAR(&viewsDirPath);
				ZEPHIR_CONCAT_VVV(&viewsDirPath, &basePath, &viewsDir, &viewPath);
			} else {
				ZEPHIR_CPY_WRT(&viewsDirPath, &viewPath);
			}
			if (Z_TYPE_P(cache) == IS_OBJECT) {
				ZEPHIR_OBS_NVAR(&_6$$6);
				zephir_read_property(&_6$$6, this_ptr, SL("_renderLevel"), PH_NOISY_CC);
				renderLevel = zephir_get_intval(&_6$$6);
				ZEPHIR_OBS_NVAR(&_7$$6);
				zephir_read_property(&_7$$6, this_ptr, SL("_cacheLevel"), PH_NOISY_CC);
				cacheLevel = zephir_get_intval(&_7$$6);
				if (renderLevel >= cacheLevel) {
					ZEPHIR_CALL_METHOD(&_8$$7, cache, "isstarted", &_9, 0);
					zephir_check_call_status();
					if (!(zephir_is_true(&_8$$7))) {
						ZEPHIR_INIT_NVAR(&key);
						ZVAL_NULL(&key);
						ZEPHIR_INIT_NVAR(&lifetime);
						ZVAL_NULL(&lifetime);
						ZEPHIR_OBS_NVAR(&viewOptions);
						zephir_read_property(&viewOptions, this_ptr, SL("_options"), PH_NOISY_CC);
						ZEPHIR_OBS_NVAR(&cacheOptions);
						if (zephir_array_isset_string_fetch(&cacheOptions, &viewOptions, SL("cache"), 0)) {
							if (Z_TYPE_P(&cacheOptions) == IS_ARRAY) {
								ZEPHIR_OBS_NVAR(&key);
								zephir_array_isset_string_fetch(&key, &cacheOptions, SL("key"), 0);
								ZEPHIR_OBS_NVAR(&lifetime);
								zephir_array_isset_string_fetch(&lifetime, &cacheOptions, SL("lifetime"), 0);
							}
						}
						if (Z_TYPE_P(&key) == IS_NULL) {
							ZEPHIR_INIT_NVAR(&key);
							zephir_md5(&key, &viewPath);
						}
						ZEPHIR_CALL_METHOD(&cachedView, cache, "start", &_10, 0, &key, &lifetime);
						zephir_check_call_status();
						if (Z_TYPE_P(&cachedView) != IS_NULL) {
							zephir_update_property_zval(this_ptr, SL("_content"), &cachedView);
							RETURN_MM_NULL();
						}
					}
					ZEPHIR_CALL_METHOD(&_11$$7, cache, "isfresh", &_12, 0);
					zephir_check_call_status();
					if (!(zephir_is_true(&_11$$7))) {
						RETURN_MM_NULL();
					}
				}
			}
			zephir_is_iterable(&engines, 0, "phalcon/mvc/view.zep", 667);
			if (Z_TYPE_P(&engines) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&engines), _15$$3, _16$$3, _13$$3)
				{
					ZEPHIR_INIT_NVAR(&extension);
					if (_16$$3 != NULL) { 
						ZVAL_STR_COPY(&extension, _16$$3);
					} else {
						ZVAL_LONG(&extension, _15$$3);
					}
					ZEPHIR_INIT_NVAR(&engine);
					ZVAL_COPY(&engine, _13$$3);
					ZEPHIR_INIT_NVAR(&viewEnginePath);
					ZEPHIR_CONCAT_VV(&viewEnginePath, &viewsDirPath, &extension);
					if ((zephir_file_exists(&viewEnginePath TSRMLS_CC) == SUCCESS)) {
						if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
							ZEPHIR_INIT_NVAR(&_17$$16);
							zephir_create_array(&_17$$16, 1, 0 TSRMLS_CC);
							zephir_array_fast_append(&_17$$16, &viewEnginePath);
							zephir_update_property_zval(this_ptr, SL("_activeRenderPaths"), &_17$$16);
							ZEPHIR_INIT_NVAR(&_19$$16);
							ZVAL_STRING(&_19$$16, "view:beforeRenderView");
							ZEPHIR_CALL_METHOD(&_18$$16, &eventsManager, "fire", &_20, 0, &_19$$16, this_ptr, &viewEnginePath);
							zephir_check_call_status();
							if (ZEPHIR_IS_FALSE_IDENTICAL(&_18$$16)) {
								continue;
							}
						}
						if (mustClean) {
							ZVAL_BOOL(&_21$$15, 1);
						} else {
							ZVAL_BOOL(&_21$$15, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, &engine, "render", NULL, 0, &viewEnginePath, &viewParams, &_21$$15);
						zephir_check_call_status();
						notExists = 0;
						if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
							ZEPHIR_INIT_NVAR(&_22$$18);
							ZVAL_STRING(&_22$$18, "view:afterRenderView");
							ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_23, 0, &_22$$18, this_ptr);
							zephir_check_call_status();
						}
						break;
					}
					zephir_array_append(&viewEnginePaths, &viewEnginePath, PH_SEPARATE, "phalcon/mvc/view.zep", 665);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &engines, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_14$$3, &engines, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_14$$3)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&extension, &engines, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&engine, &engines, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&viewEnginePath);
						ZEPHIR_CONCAT_VV(&viewEnginePath, &viewsDirPath, &extension);
						if ((zephir_file_exists(&viewEnginePath TSRMLS_CC) == SUCCESS)) {
							if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
								ZEPHIR_INIT_NVAR(&_24$$21);
								zephir_create_array(&_24$$21, 1, 0 TSRMLS_CC);
								zephir_array_fast_append(&_24$$21, &viewEnginePath);
								zephir_update_property_zval(this_ptr, SL("_activeRenderPaths"), &_24$$21);
								ZEPHIR_INIT_NVAR(&_26$$21);
								ZVAL_STRING(&_26$$21, "view:beforeRenderView");
								ZEPHIR_CALL_METHOD(&_25$$21, &eventsManager, "fire", &_27, 0, &_26$$21, this_ptr, &viewEnginePath);
								zephir_check_call_status();
								if (ZEPHIR_IS_FALSE_IDENTICAL(&_25$$21)) {
									continue;
								}
							}
							if (mustClean) {
								ZVAL_BOOL(&_28$$20, 1);
							} else {
								ZVAL_BOOL(&_28$$20, 0);
							}
							ZEPHIR_CALL_METHOD(NULL, &engine, "render", NULL, 0, &viewEnginePath, &viewParams, &_28$$20);
							zephir_check_call_status();
							notExists = 0;
							if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
								ZEPHIR_INIT_NVAR(&_29$$23);
								ZVAL_STRING(&_29$$23, "view:afterRenderView");
								ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_30, 0, &_29$$23, this_ptr);
								zephir_check_call_status();
							}
							break;
						}
						zephir_array_append(&viewEnginePaths, &viewEnginePath, PH_SEPARATE, "phalcon/mvc/view.zep", 665);
					ZEPHIR_CALL_METHOD(NULL, &engines, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&engine);
			ZEPHIR_INIT_NVAR(&extension);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_1, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &_1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&viewsDir, &_1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_31$$24, this_ptr, "_isabsolutepath", &_5, 378, &viewPath);
				zephir_check_call_status();
				if (!(zephir_is_true(&_31$$24))) {
					ZEPHIR_INIT_NVAR(&viewsDirPath);
					ZEPHIR_CONCAT_VVV(&viewsDirPath, &basePath, &viewsDir, &viewPath);
				} else {
					ZEPHIR_CPY_WRT(&viewsDirPath, &viewPath);
				}
				if (Z_TYPE_P(cache) == IS_OBJECT) {
					ZEPHIR_OBS_NVAR(&_32$$27);
					zephir_read_property(&_32$$27, this_ptr, SL("_renderLevel"), PH_NOISY_CC);
					renderLevel = zephir_get_intval(&_32$$27);
					ZEPHIR_OBS_NVAR(&_33$$27);
					zephir_read_property(&_33$$27, this_ptr, SL("_cacheLevel"), PH_NOISY_CC);
					cacheLevel = zephir_get_intval(&_33$$27);
					if (renderLevel >= cacheLevel) {
						ZEPHIR_CALL_METHOD(&_34$$28, cache, "isstarted", &_35, 0);
						zephir_check_call_status();
						if (!(zephir_is_true(&_34$$28))) {
							ZEPHIR_INIT_NVAR(&key);
							ZVAL_NULL(&key);
							ZEPHIR_INIT_NVAR(&lifetime);
							ZVAL_NULL(&lifetime);
							ZEPHIR_OBS_NVAR(&viewOptions);
							zephir_read_property(&viewOptions, this_ptr, SL("_options"), PH_NOISY_CC);
							ZEPHIR_OBS_NVAR(&cacheOptions);
							if (zephir_array_isset_string_fetch(&cacheOptions, &viewOptions, SL("cache"), 0)) {
								if (Z_TYPE_P(&cacheOptions) == IS_ARRAY) {
									ZEPHIR_OBS_NVAR(&key);
									zephir_array_isset_string_fetch(&key, &cacheOptions, SL("key"), 0);
									ZEPHIR_OBS_NVAR(&lifetime);
									zephir_array_isset_string_fetch(&lifetime, &cacheOptions, SL("lifetime"), 0);
								}
							}
							if (Z_TYPE_P(&key) == IS_NULL) {
								ZEPHIR_INIT_NVAR(&key);
								zephir_md5(&key, &viewPath);
							}
							ZEPHIR_CALL_METHOD(&cachedView, cache, "start", &_36, 0, &key, &lifetime);
							zephir_check_call_status();
							if (Z_TYPE_P(&cachedView) != IS_NULL) {
								zephir_update_property_zval(this_ptr, SL("_content"), &cachedView);
								RETURN_MM_NULL();
							}
						}
						ZEPHIR_CALL_METHOD(&_37$$28, cache, "isfresh", &_38, 0);
						zephir_check_call_status();
						if (!(zephir_is_true(&_37$$28))) {
							RETURN_MM_NULL();
						}
					}
				}
				zephir_is_iterable(&engines, 0, "phalcon/mvc/view.zep", 667);
				if (Z_TYPE_P(&engines) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&engines), _41$$24, _42$$24, _39$$24)
					{
						ZEPHIR_INIT_NVAR(&extension);
						if (_42$$24 != NULL) { 
							ZVAL_STR_COPY(&extension, _42$$24);
						} else {
							ZVAL_LONG(&extension, _41$$24);
						}
						ZEPHIR_INIT_NVAR(&engine);
						ZVAL_COPY(&engine, _39$$24);
						ZEPHIR_INIT_NVAR(&viewEnginePath);
						ZEPHIR_CONCAT_VV(&viewEnginePath, &viewsDirPath, &extension);
						if ((zephir_file_exists(&viewEnginePath TSRMLS_CC) == SUCCESS)) {
							if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
								ZEPHIR_INIT_NVAR(&_43$$37);
								zephir_create_array(&_43$$37, 1, 0 TSRMLS_CC);
								zephir_array_fast_append(&_43$$37, &viewEnginePath);
								zephir_update_property_zval(this_ptr, SL("_activeRenderPaths"), &_43$$37);
								ZEPHIR_INIT_NVAR(&_45$$37);
								ZVAL_STRING(&_45$$37, "view:beforeRenderView");
								ZEPHIR_CALL_METHOD(&_44$$37, &eventsManager, "fire", &_46, 0, &_45$$37, this_ptr, &viewEnginePath);
								zephir_check_call_status();
								if (ZEPHIR_IS_FALSE_IDENTICAL(&_44$$37)) {
									continue;
								}
							}
							if (mustClean) {
								ZVAL_BOOL(&_47$$36, 1);
							} else {
								ZVAL_BOOL(&_47$$36, 0);
							}
							ZEPHIR_CALL_METHOD(NULL, &engine, "render", NULL, 0, &viewEnginePath, &viewParams, &_47$$36);
							zephir_check_call_status();
							notExists = 0;
							if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
								ZEPHIR_INIT_NVAR(&_48$$39);
								ZVAL_STRING(&_48$$39, "view:afterRenderView");
								ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_49, 0, &_48$$39, this_ptr);
								zephir_check_call_status();
							}
							break;
						}
						zephir_array_append(&viewEnginePaths, &viewEnginePath, PH_SEPARATE, "phalcon/mvc/view.zep", 665);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &engines, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_40$$24, &engines, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_40$$24)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&extension, &engines, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&engine, &engines, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&viewEnginePath);
							ZEPHIR_CONCAT_VV(&viewEnginePath, &viewsDirPath, &extension);
							if ((zephir_file_exists(&viewEnginePath TSRMLS_CC) == SUCCESS)) {
								if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
									ZEPHIR_INIT_NVAR(&_50$$42);
									zephir_create_array(&_50$$42, 1, 0 TSRMLS_CC);
									zephir_array_fast_append(&_50$$42, &viewEnginePath);
									zephir_update_property_zval(this_ptr, SL("_activeRenderPaths"), &_50$$42);
									ZEPHIR_INIT_NVAR(&_52$$42);
									ZVAL_STRING(&_52$$42, "view:beforeRenderView");
									ZEPHIR_CALL_METHOD(&_51$$42, &eventsManager, "fire", &_53, 0, &_52$$42, this_ptr, &viewEnginePath);
									zephir_check_call_status();
									if (ZEPHIR_IS_FALSE_IDENTICAL(&_51$$42)) {
										continue;
									}
								}
								if (mustClean) {
									ZVAL_BOOL(&_54$$41, 1);
								} else {
									ZVAL_BOOL(&_54$$41, 0);
								}
								ZEPHIR_CALL_METHOD(NULL, &engine, "render", NULL, 0, &viewEnginePath, &viewParams, &_54$$41);
								zephir_check_call_status();
								notExists = 0;
								if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
									ZEPHIR_INIT_NVAR(&_55$$44);
									ZVAL_STRING(&_55$$44, "view:afterRenderView");
									ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_56, 0, &_55$$44, this_ptr);
									zephir_check_call_status();
								}
								break;
							}
							zephir_array_append(&viewEnginePaths, &viewEnginePath, PH_SEPARATE, "phalcon/mvc/view.zep", 665);
						ZEPHIR_CALL_METHOD(NULL, &engines, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&engine);
				ZEPHIR_INIT_NVAR(&extension);
			ZEPHIR_CALL_METHOD(NULL, &_1, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&viewsDir);
	if (notExists == 1) {
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			zephir_update_property_zval(this_ptr, SL("_activeRenderPaths"), &viewEnginePaths);
			ZEPHIR_INIT_VAR(&_57$$46);
			ZVAL_STRING(&_57$$46, "view:notFoundView");
			ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_57$$46, this_ptr, &viewEnginePath);
			zephir_check_call_status();
		}
		if (!(silence)) {
			ZEPHIR_INIT_VAR(&_58$$47);
			object_init_ex(&_58$$47, phalcon_mvc_view_exception_ce);
			ZEPHIR_INIT_VAR(&_59$$47);
			ZEPHIR_CONCAT_SVS(&_59$$47, "View '", &viewPath, "' was not found in any of the views directory");
			ZEPHIR_CALL_METHOD(NULL, &_58$$47, "__construct", NULL, 4, &_59$$47);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_58$$47, "phalcon/mvc/view.zep", 679 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Register templating engines
 *
 * <code>
 * $this->view->registerEngines(
 *     [
 *         ".phtml" => "Phalcon\\Mvc\\View\\Engine\\Php",
 *         ".volt"  => "Phalcon\\Mvc\\View\\Engine\\Volt",
 *         ".mhtml" => "MyCustomEngine",
 *     ]
 * );
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_View, registerEngines) {

	zval *engines_param = NULL;
	zval engines;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&engines);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &engines_param);

	ZEPHIR_OBS_COPY_OR_DUP(&engines, engines_param);


	zephir_update_property_zval(this_ptr, SL("_registeredEngines"), &engines);
	RETURN_THIS();

}

/**
 * Checks whether view exists
 */
PHP_METHOD(Phalcon_Mvc_View, exists) {

	zend_string *_8$$4, *_15$$9;
	zend_ulong _7$$4, _14$$9;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *view_param = NULL, basePath, viewsDir, engines, extension, _1, *_2, _3, _0$$3, _4$$4, *_5$$4, _6$$4, _9$$5, _10$$7, _11$$9, *_12$$9, _13$$9, _16$$10, _17$$12;
	zval view;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&view);
	ZVAL_UNDEF(&basePath);
	ZVAL_UNDEF(&viewsDir);
	ZVAL_UNDEF(&engines);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_17$$12);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &view_param);

	if (UNEXPECTED(Z_TYPE_P(view_param) != IS_STRING && Z_TYPE_P(view_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'view' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(view_param) == IS_STRING)) {
		zephir_get_strval(&view, view_param);
	} else {
		ZEPHIR_INIT_VAR(&view);
		ZVAL_EMPTY_STRING(&view);
	}


	ZEPHIR_OBS_VAR(&basePath);
	zephir_read_property(&basePath, this_ptr, SL("_basePath"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&engines);
	zephir_read_property(&engines, this_ptr, SL("_registeredEngines"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&engines)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 1, 0 TSRMLS_CC);
		add_assoc_stringl_ex(&_0$$3, SL(".phtml"), SL("Phalcon\\Mvc\\View\\Engine\\Php"));
		ZEPHIR_CPY_WRT(&engines, &_0$$3);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerengines", NULL, 0, &engines);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getviewsdirs", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&_1, 0, "phalcon/mvc/view.zep", 727);
	if (Z_TYPE_P(&_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1), _2)
		{
			ZEPHIR_INIT_NVAR(&viewsDir);
			ZVAL_COPY(&viewsDir, _2);
			ZEPHIR_INIT_NVAR(&_4$$4);
			zephir_is_iterable(&engines, 0, "phalcon/mvc/view.zep", 725);
			if (Z_TYPE_P(&engines) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&engines), _7$$4, _8$$4, _5$$4)
				{
					ZEPHIR_INIT_NVAR(&extension);
					if (_8$$4 != NULL) { 
						ZVAL_STR_COPY(&extension, _8$$4);
					} else {
						ZVAL_LONG(&extension, _7$$4);
					}
					ZEPHIR_INIT_NVAR(&_4$$4);
					ZVAL_COPY(&_4$$4, _5$$4);
					ZEPHIR_INIT_LNVAR(_9$$5);
					ZEPHIR_CONCAT_VVVV(&_9$$5, &basePath, &viewsDir, &view, &extension);
					if ((zephir_file_exists(&_9$$5 TSRMLS_CC) == SUCCESS)) {
						RETURN_MM_BOOL(1);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &engines, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_6$$4, &engines, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_6$$4)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&extension, &engines, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_4$$4, &engines, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_LNVAR(_10$$7);
						ZEPHIR_CONCAT_VVVV(&_10$$7, &basePath, &viewsDir, &view, &extension);
						if ((zephir_file_exists(&_10$$7 TSRMLS_CC) == SUCCESS)) {
							RETURN_MM_BOOL(1);
						}
					ZEPHIR_CALL_METHOD(NULL, &engines, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZEPHIR_INIT_NVAR(&extension);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_1, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &_1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&viewsDir, &_1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_11$$9);
				zephir_is_iterable(&engines, 0, "phalcon/mvc/view.zep", 725);
				if (Z_TYPE_P(&engines) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&engines), _14$$9, _15$$9, _12$$9)
					{
						ZEPHIR_INIT_NVAR(&extension);
						if (_15$$9 != NULL) { 
							ZVAL_STR_COPY(&extension, _15$$9);
						} else {
							ZVAL_LONG(&extension, _14$$9);
						}
						ZEPHIR_INIT_NVAR(&_11$$9);
						ZVAL_COPY(&_11$$9, _12$$9);
						ZEPHIR_INIT_LNVAR(_16$$10);
						ZEPHIR_CONCAT_VVVV(&_16$$10, &basePath, &viewsDir, &view, &extension);
						if ((zephir_file_exists(&_16$$10 TSRMLS_CC) == SUCCESS)) {
							RETURN_MM_BOOL(1);
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &engines, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_13$$9, &engines, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_13$$9)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&extension, &engines, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_11$$9, &engines, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_LNVAR(_17$$12);
							ZEPHIR_CONCAT_VVVV(&_17$$12, &basePath, &viewsDir, &view, &extension);
							if ((zephir_file_exists(&_17$$12 TSRMLS_CC) == SUCCESS)) {
								RETURN_MM_BOOL(1);
							}
						ZEPHIR_CALL_METHOD(NULL, &engines, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&_11$$9);
				ZEPHIR_INIT_NVAR(&extension);
			ZEPHIR_CALL_METHOD(NULL, &_1, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&viewsDir);
	RETURN_MM_BOOL(0);

}

/**
 * Executes render process from dispatching data
 *
 *<code>
 * // Shows recent posts view (app/views/posts/recent.phtml)
 * $view->start()->render("posts", "recent")->finish();
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_View, render) {

	zend_bool silence = 0, mustClean = 0, _38$$31;
	zend_long ZEPHIR_LAST_CALL_STATUS, renderLevel = 0;
	zval params;
	zval *controllerName_param = NULL, *actionName_param = NULL, *params_param = NULL, layoutsDir, layout, pickView, layoutName, engines, renderView, pickViewAction, eventsManager, disabledLevels, templatesBefore, templatesAfter, templateBefore, templateAfter, cache, _0, _3, _4, _5, _8, _9, _1$$3, _6$$14, _7$$14, _10$$18, _11$$18, _12$$20, *_13$$20, _14$$20, _15$$21, _16$$21, _17$$21, _18$$22, _19$$22, _20$$22, _21$$24, _22$$24, _23$$24, _24$$26, *_25$$26, _26$$26, _27$$27, _28$$27, _29$$27, _30$$28, _31$$28, _32$$28, _33$$30, _34$$30, _35$$30, _36$$16, _37$$31, _39$$31, _40$$34;
	zval controllerName, actionName, _2$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&controllerName);
	ZVAL_UNDEF(&actionName);
	ZVAL_UNDEF(&_2$$8);
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
	ZVAL_UNDEF(&cache);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_6$$14);
	ZVAL_UNDEF(&_7$$14);
	ZVAL_UNDEF(&_10$$18);
	ZVAL_UNDEF(&_11$$18);
	ZVAL_UNDEF(&_12$$20);
	ZVAL_UNDEF(&_14$$20);
	ZVAL_UNDEF(&_15$$21);
	ZVAL_UNDEF(&_16$$21);
	ZVAL_UNDEF(&_17$$21);
	ZVAL_UNDEF(&_18$$22);
	ZVAL_UNDEF(&_19$$22);
	ZVAL_UNDEF(&_20$$22);
	ZVAL_UNDEF(&_21$$24);
	ZVAL_UNDEF(&_22$$24);
	ZVAL_UNDEF(&_23$$24);
	ZVAL_UNDEF(&_24$$26);
	ZVAL_UNDEF(&_26$$26);
	ZVAL_UNDEF(&_27$$27);
	ZVAL_UNDEF(&_28$$27);
	ZVAL_UNDEF(&_29$$27);
	ZVAL_UNDEF(&_30$$28);
	ZVAL_UNDEF(&_31$$28);
	ZVAL_UNDEF(&_32$$28);
	ZVAL_UNDEF(&_33$$30);
	ZVAL_UNDEF(&_34$$30);
	ZVAL_UNDEF(&_35$$30);
	ZVAL_UNDEF(&_36$$16);
	ZVAL_UNDEF(&_37$$31);
	ZVAL_UNDEF(&_39$$31);
	ZVAL_UNDEF(&_40$$34);
	ZVAL_UNDEF(&params);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &controllerName_param, &actionName_param, &params_param);

	if (UNEXPECTED(Z_TYPE_P(controllerName_param) != IS_STRING && Z_TYPE_P(controllerName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'controllerName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(controllerName_param) == IS_STRING)) {
		zephir_get_strval(&controllerName, controllerName_param);
	} else {
		ZEPHIR_INIT_VAR(&controllerName);
		ZVAL_EMPTY_STRING(&controllerName);
	}
	if (UNEXPECTED(Z_TYPE_P(actionName_param) != IS_STRING && Z_TYPE_P(actionName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'actionName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(actionName_param) == IS_STRING)) {
		zephir_get_strval(&actionName, actionName_param);
	} else {
		ZEPHIR_INIT_VAR(&actionName);
		ZVAL_EMPTY_STRING(&actionName);
	}
	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
		zephir_get_arrval(&params, params_param);
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval(this_ptr, SL("_currentRenderLevel"), &_0);
	zephir_read_property(&_0, this_ptr, SL("_disabled"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_0)) {
		ZEPHIR_CALL_FUNCTION(&_1$$3, "ob_get_contents", NULL, 115);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_content"), &_1$$3);
		RETURN_MM_BOOL(0);
	}
	zephir_update_property_zval(this_ptr, SL("_controllerName"), &controllerName);
	zephir_update_property_zval(this_ptr, SL("_actionName"), &actionName);
	if (1 == 1) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setvars", NULL, 0, &params);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(&layoutsDir);
	zephir_read_property(&layoutsDir, this_ptr, SL("_layoutsDir"), PH_NOISY_CC);
	if (!(zephir_is_true(&layoutsDir))) {
		ZEPHIR_INIT_NVAR(&layoutsDir);
		ZVAL_STRING(&layoutsDir, "layouts/");
	}
	ZEPHIR_OBS_VAR(&layout);
	zephir_read_property(&layout, this_ptr, SL("_layout"), PH_NOISY_CC);
	if (zephir_is_true(&layout)) {
		ZEPHIR_CPY_WRT(&layoutName, &layout);
	} else {
		ZEPHIR_CPY_WRT(&layoutName, &controllerName);
	}
	ZEPHIR_CALL_METHOD(&engines, this_ptr, "_loadtemplateengines", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&pickView);
	zephir_read_property(&pickView, this_ptr, SL("_pickView"), PH_NOISY_CC);
	if (Z_TYPE_P(&pickView) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_2$$8);
		ZEPHIR_CONCAT_VSV(&_2$$8, &controllerName, "/", &actionName);
		ZEPHIR_CPY_WRT(&renderView, &_2$$8);
	} else {
		ZEPHIR_OBS_NVAR(&renderView);
		zephir_array_fetch_long(&renderView, &pickView, 0, PH_NOISY, "phalcon/mvc/view.zep", 799 TSRMLS_CC);
		if (Z_TYPE_P(&layoutName) == IS_NULL) {
			ZEPHIR_OBS_VAR(&pickViewAction);
			if (zephir_array_isset_long_fetch(&pickViewAction, &pickView, 1, 0 TSRMLS_CC)) {
				ZEPHIR_CPY_WRT(&layoutName, &pickViewAction);
			}
		}
	}
	zephir_read_property(&_3, this_ptr, SL("_cacheLevel"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_3)) {
		ZEPHIR_CALL_METHOD(&cache, this_ptr, "getcache", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&cache);
		ZVAL_NULL(&cache);
	}
	zephir_read_property(&_4, this_ptr, SL("_eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_4);
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_symbol_table(TSRMLS_C);
	
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_7$$14);
		ZVAL_STRING(&_7$$14, "view:beforeRender");
		ZEPHIR_CALL_METHOD(&_6$$14, &eventsManager, "fire", NULL, 0, &_7$$14, this_ptr);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_6$$14)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_CALL_FUNCTION(&_8, "ob_get_contents", NULL, 115);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_content"), &_8);
	mustClean = 1;
	silence = 1;
	ZEPHIR_OBS_VAR(&disabledLevels);
	zephir_read_property(&disabledLevels, this_ptr, SL("_disabledLevels"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&_9);
	zephir_read_property(&_9, this_ptr, SL("_renderLevel"), PH_NOISY_CC);
	renderLevel = zephir_get_intval(&_9);
	if (renderLevel) {
		if (renderLevel >= 1) {
			if (!(zephir_array_isset_long(&disabledLevels, 1))) {
				ZEPHIR_INIT_ZVAL_NREF(_10$$18);
				ZVAL_LONG(&_10$$18, 1);
				zephir_update_property_zval(this_ptr, SL("_currentRenderLevel"), &_10$$18);
				if (silence) {
					ZVAL_BOOL(&_10$$18, 1);
				} else {
					ZVAL_BOOL(&_10$$18, 0);
				}
				if (mustClean) {
					ZVAL_BOOL(&_11$$18, 1);
				} else {
					ZVAL_BOOL(&_11$$18, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_enginerender", NULL, 0, &engines, &renderView, &_10$$18, &_11$$18, &cache);
				zephir_check_call_status();
			}
		}
		if (renderLevel >= 2) {
			if (!(zephir_array_isset_long(&disabledLevels, 2))) {
				ZEPHIR_INIT_ZVAL_NREF(_12$$20);
				ZVAL_LONG(&_12$$20, 2);
				zephir_update_property_zval(this_ptr, SL("_currentRenderLevel"), &_12$$20);
				ZEPHIR_OBS_VAR(&templatesBefore);
				zephir_read_property(&templatesBefore, this_ptr, SL("_templatesBefore"), PH_NOISY_CC);
				silence = 0;
				zephir_is_iterable(&templatesBefore, 0, "phalcon/mvc/view.zep", 875);
				if (Z_TYPE_P(&templatesBefore) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&templatesBefore), _13$$20)
					{
						ZEPHIR_INIT_NVAR(&templateBefore);
						ZVAL_COPY(&templateBefore, _13$$20);
						ZEPHIR_INIT_LNVAR(_15$$21);
						ZEPHIR_CONCAT_VV(&_15$$21, &layoutsDir, &templateBefore);
						if (silence) {
							ZVAL_BOOL(&_16$$21, 1);
						} else {
							ZVAL_BOOL(&_16$$21, 0);
						}
						if (mustClean) {
							ZVAL_BOOL(&_17$$21, 1);
						} else {
							ZVAL_BOOL(&_17$$21, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "_enginerender", NULL, 0, &engines, &_15$$21, &_16$$21, &_17$$21, &cache);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &templatesBefore, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_14$$20, &templatesBefore, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_14$$20)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&templateBefore, &templatesBefore, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_LNVAR(_18$$22);
							ZEPHIR_CONCAT_VV(&_18$$22, &layoutsDir, &templateBefore);
							if (silence) {
								ZVAL_BOOL(&_19$$22, 1);
							} else {
								ZVAL_BOOL(&_19$$22, 0);
							}
							if (mustClean) {
								ZVAL_BOOL(&_20$$22, 1);
							} else {
								ZVAL_BOOL(&_20$$22, 0);
							}
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "_enginerender", NULL, 0, &engines, &_18$$22, &_19$$22, &_20$$22, &cache);
							zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &templatesBefore, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&templateBefore);
				silence = 1;
			}
		}
		if (renderLevel >= 3) {
			if (!(zephir_array_isset_long(&disabledLevels, 3))) {
				ZEPHIR_INIT_ZVAL_NREF(_21$$24);
				ZVAL_LONG(&_21$$24, 3);
				zephir_update_property_zval(this_ptr, SL("_currentRenderLevel"), &_21$$24);
				ZEPHIR_INIT_VAR(&_22$$24);
				ZEPHIR_CONCAT_VV(&_22$$24, &layoutsDir, &layoutName);
				if (silence) {
					ZVAL_BOOL(&_21$$24, 1);
				} else {
					ZVAL_BOOL(&_21$$24, 0);
				}
				if (mustClean) {
					ZVAL_BOOL(&_23$$24, 1);
				} else {
					ZVAL_BOOL(&_23$$24, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_enginerender", NULL, 0, &engines, &_22$$24, &_21$$24, &_23$$24, &cache);
				zephir_check_call_status();
			}
		}
		if (renderLevel >= 4) {
			if (!(zephir_array_isset_long(&disabledLevels, 4))) {
				ZEPHIR_INIT_ZVAL_NREF(_24$$26);
				ZVAL_LONG(&_24$$26, 4);
				zephir_update_property_zval(this_ptr, SL("_currentRenderLevel"), &_24$$26);
				ZEPHIR_OBS_VAR(&templatesAfter);
				zephir_read_property(&templatesAfter, this_ptr, SL("_templatesAfter"), PH_NOISY_CC);
				silence = 0;
				zephir_is_iterable(&templatesAfter, 0, "phalcon/mvc/view.zep", 902);
				if (Z_TYPE_P(&templatesAfter) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&templatesAfter), _25$$26)
					{
						ZEPHIR_INIT_NVAR(&templateAfter);
						ZVAL_COPY(&templateAfter, _25$$26);
						ZEPHIR_INIT_LNVAR(_27$$27);
						ZEPHIR_CONCAT_VV(&_27$$27, &layoutsDir, &templateAfter);
						if (silence) {
							ZVAL_BOOL(&_28$$27, 1);
						} else {
							ZVAL_BOOL(&_28$$27, 0);
						}
						if (mustClean) {
							ZVAL_BOOL(&_29$$27, 1);
						} else {
							ZVAL_BOOL(&_29$$27, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "_enginerender", NULL, 0, &engines, &_27$$27, &_28$$27, &_29$$27, &cache);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &templatesAfter, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_26$$26, &templatesAfter, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_26$$26)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&templateAfter, &templatesAfter, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_LNVAR(_30$$28);
							ZEPHIR_CONCAT_VV(&_30$$28, &layoutsDir, &templateAfter);
							if (silence) {
								ZVAL_BOOL(&_31$$28, 1);
							} else {
								ZVAL_BOOL(&_31$$28, 0);
							}
							if (mustClean) {
								ZVAL_BOOL(&_32$$28, 1);
							} else {
								ZVAL_BOOL(&_32$$28, 0);
							}
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "_enginerender", NULL, 0, &engines, &_30$$28, &_31$$28, &_32$$28, &cache);
							zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &templatesAfter, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&templateAfter);
				silence = 1;
			}
		}
		if (renderLevel >= 5) {
			if (!(zephir_array_isset_long(&disabledLevels, 5))) {
				ZEPHIR_INIT_ZVAL_NREF(_33$$30);
				ZVAL_LONG(&_33$$30, 5);
				zephir_update_property_zval(this_ptr, SL("_currentRenderLevel"), &_33$$30);
				zephir_read_property(&_33$$30, this_ptr, SL("_mainView"), PH_NOISY_CC | PH_READONLY);
				if (silence) {
					ZVAL_BOOL(&_34$$30, 1);
				} else {
					ZVAL_BOOL(&_34$$30, 0);
				}
				if (mustClean) {
					ZVAL_BOOL(&_35$$30, 1);
				} else {
					ZVAL_BOOL(&_35$$30, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_enginerender", NULL, 0, &engines, &_33$$30, &_34$$30, &_35$$30, &cache);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_ZVAL_NREF(_36$$16);
		ZVAL_LONG(&_36$$16, 0);
		zephir_update_property_zval(this_ptr, SL("_currentRenderLevel"), &_36$$16);
		if (Z_TYPE_P(&cache) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(&_37$$31, &cache, "isstarted", NULL, 0);
			zephir_check_call_status();
			_38$$31 = zephir_is_true(&_37$$31);
			if (_38$$31) {
				ZEPHIR_CALL_METHOD(&_39$$31, &cache, "isfresh", NULL, 0);
				zephir_check_call_status();
				_38$$31 = zephir_is_true(&_39$$31);
			}
			if (_38$$31) {
				ZEPHIR_CALL_METHOD(NULL, &cache, "save", NULL, 0);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &cache, "stop", NULL, 0);
				zephir_check_call_status();
			}
		}
	}
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_40$$34);
		ZVAL_STRING(&_40$$34, "view:afterRender");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_40$$34, this_ptr);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Choose a different view to render instead of last-controller/last-action
 *
 * <code>
 * use Phalcon\Mvc\Controller;
 *
 * class ProductsController extends Controller
 * {
 *    public function saveAction()
 *    {
 *         // Do some save stuff...
 *
 *         // Then show the list view
 *         $this->view->pick("products/list");
 *    }
 * }
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_View, pick) {

	zval *renderView, renderView_sub, pickView, layout, parts, _0$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&renderView_sub);
	ZVAL_UNDEF(&pickView);
	ZVAL_UNDEF(&layout);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&_0$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &renderView);



	if (Z_TYPE_P(renderView) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&pickView, renderView);
	} else {
		ZEPHIR_INIT_VAR(&layout);
		ZVAL_NULL(&layout);
		if (zephir_memnstr_str(renderView, SL("/"), "phalcon/mvc/view.zep", 967)) {
			ZEPHIR_INIT_VAR(&parts);
			zephir_fast_explode_str(&parts, SL("/"), renderView, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&layout);
			zephir_array_fetch_long(&layout, &parts, 0, PH_NOISY, "phalcon/mvc/view.zep", 968 TSRMLS_CC);
		}
		ZEPHIR_INIT_VAR(&_0$$4);
		zephir_create_array(&_0$$4, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_0$$4, renderView);
		ZEPHIR_CPY_WRT(&pickView, &_0$$4);
		if (Z_TYPE_P(&layout) != IS_NULL) {
			zephir_array_append(&pickView, &layout, PH_SEPARATE, "phalcon/mvc/view.zep", 973);
		}
	}
	zephir_update_property_zval(this_ptr, SL("_pickView"), &pickView);
	RETURN_THIS();

}

/**
 * Renders a partial view
 *
 * <code>
 * // Retrieve the contents of a partial
 * echo $this->getPartial("shared/footer");
 * </code>
 *
 * <code>
 * // Retrieve the contents of a partial with arguments
 * echo $this->getPartial(
 *     "shared/footer",
 *     [
 *         "content" => $html,
 *     ]
 * );
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_View, getPartial) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *partialPath_param = NULL, *params = NULL, params_sub, __$null;
	zval partialPath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&partialPath);
	ZVAL_UNDEF(&params_sub);
	ZVAL_NULL(&__$null);

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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "partial", NULL, 0, &partialPath, params);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", NULL, 282);
	zephir_check_call_status();
	RETURN_MM();

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
PHP_METHOD(Phalcon_Mvc_View, partial) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *partialPath_param = NULL, *params = NULL, params_sub, __$null, viewParams, _2, _3, _4, _5, _6, _0$$3, _1$$3;
	zval partialPath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&partialPath);
	ZVAL_UNDEF(&params_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&viewParams);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);

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


	if (Z_TYPE_P(params) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&viewParams);
		zephir_read_property(&viewParams, this_ptr, SL("_viewParams"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_fast_array_merge(&_0$$3, &viewParams, params TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_viewParams"), &_0$$3);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_symbol_table(TSRMLS_C);
		
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "_loadtemplateengines", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, SL("_partialsDir"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_3, &partialPath);
	ZVAL_BOOL(&_5, 0);
	ZVAL_BOOL(&_6, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_enginerender", NULL, 0, &_2, &_4, &_5, &_6);
	zephir_check_call_status();
	if (Z_TYPE_P(params) == IS_ARRAY) {
		zephir_update_property_zval(this_ptr, SL("_viewParams"), &viewParams);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Perform the automatic rendering returning the output as a string
 *
 * <code>
 * $template = $this->view->getRender(
 *     "products",
 *     "show",
 *     [
 *         "products" => $products,
 *     ]
 * );
 * </code>
 *
 * @param mixed configCallback
 */
PHP_METHOD(Phalcon_Mvc_View, getRender) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval params, _1$$4;
	zval *controllerName_param = NULL, *actionName_param = NULL, *params_param = NULL, *configCallback = NULL, configCallback_sub, __$null, view, _0$$4;
	zval controllerName, actionName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&controllerName);
	ZVAL_UNDEF(&actionName);
	ZVAL_UNDEF(&configCallback_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&view);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &controllerName_param, &actionName_param, &params_param, &configCallback);

	if (UNEXPECTED(Z_TYPE_P(controllerName_param) != IS_STRING && Z_TYPE_P(controllerName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'controllerName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(controllerName_param) == IS_STRING)) {
		zephir_get_strval(&controllerName, controllerName_param);
	} else {
		ZEPHIR_INIT_VAR(&controllerName);
		ZVAL_EMPTY_STRING(&controllerName);
	}
	if (UNEXPECTED(Z_TYPE_P(actionName_param) != IS_STRING && Z_TYPE_P(actionName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'actionName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(actionName_param) == IS_STRING)) {
		zephir_get_strval(&actionName, actionName_param);
	} else {
		ZEPHIR_INIT_VAR(&actionName);
		ZVAL_EMPTY_STRING(&actionName);
	}
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
	if (zephir_clone(&view, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(NULL, &view, "reset", NULL, 0);
	zephir_check_call_status();
	if (1 == 1) {
		ZEPHIR_CALL_METHOD(NULL, &view, "setvars", NULL, 0, &params);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(configCallback) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_0$$4);
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_create_array(&_1$$4, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_1$$4, &view);
		ZEPHIR_CALL_USER_FUNC_ARRAY(&_0$$4, configCallback, &_1$$4);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, &view, "start", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &view, "render", NULL, 0, &controllerName, &actionName);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 116);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&view, "getcontent", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Finishes the render process by stopping the output buffering
 */
PHP_METHOD(Phalcon_Mvc_View, finish) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 116);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Create a Phalcon\Cache based on the internal cache options
 */
PHP_METHOD(Phalcon_Mvc_View, _createCache) {

	zval dependencyInjector, cacheService, viewCache, viewOptions, cacheOptions, _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&cacheService);
	ZVAL_UNDEF(&viewCache);
	ZVAL_UNDEF(&viewOptions);
	ZVAL_UNDEF(&cacheOptions);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&dependencyInjector, &_0);
	if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "A dependency injector container is required to obtain the view cache services", "phalcon/mvc/view.zep", 1148);
		return;
	}
	ZEPHIR_INIT_VAR(&cacheService);
	ZVAL_STRING(&cacheService, "viewCache");
	ZEPHIR_OBS_VAR(&viewOptions);
	zephir_read_property(&viewOptions, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&cacheOptions);
	if (zephir_array_isset_string_fetch(&cacheOptions, &viewOptions, SL("cache"), 0)) {
		if (zephir_array_isset_string(&cacheOptions, SL("service"))) {
			ZEPHIR_OBS_NVAR(&cacheService);
			zephir_array_fetch_string(&cacheService, &cacheOptions, SL("service"), PH_NOISY, "phalcon/mvc/view.zep", 1157 TSRMLS_CC);
		}
	}
	ZEPHIR_CALL_METHOD(&_1, &dependencyInjector, "getshared", NULL, 0, &cacheService);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&viewCache, &_1);
	if (Z_TYPE_P(&viewCache) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "The injected caching service is invalid", "phalcon/mvc/view.zep", 1166);
		return;
	}
	RETURN_CCTOR(&viewCache);

}

/**
 * Check if the component is currently caching the output content
 */
PHP_METHOD(Phalcon_Mvc_View, isCaching) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("_cacheLevel"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(ZEPHIR_GT_LONG(&_0, 0));

}

/**
 * Returns the cache instance used to cache
 */
PHP_METHOD(Phalcon_Mvc_View, getCache) {

	zend_bool _1;
	zval _0, _2, _3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_cache"), PH_NOISY_CC | PH_READONLY);
	_1 = !zephir_is_true(&_0);
	if (!(_1)) {
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
PHP_METHOD(Phalcon_Mvc_View, cache) {

	zend_string *_3$$3;
	zend_ulong _2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL, options_sub, __$true, viewOptions, cacheOptions, key, value, cacheLevel, *_0$$3, _1$$3, _4$$9, _5$$11, _6$$12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&viewOptions);
	ZVAL_UNDEF(&cacheOptions);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&cacheLevel);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_5$$11);
	ZVAL_UNDEF(&_6$$12);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options) {
		options = &options_sub;
		options = &__$true;
	}


	if (Z_TYPE_P(options) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&viewOptions);
		zephir_read_property(&viewOptions, this_ptr, SL("_options"), PH_NOISY_CC);
		if (Z_TYPE_P(&viewOptions) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(&viewOptions);
			array_init(&viewOptions);
		}
		ZEPHIR_OBS_VAR(&cacheOptions);
		if (!(zephir_array_isset_string_fetch(&cacheOptions, &viewOptions, SL("cache"), 0))) {
			ZEPHIR_INIT_NVAR(&cacheOptions);
			array_init(&cacheOptions);
		}
		zephir_is_iterable(options, 0, "phalcon/mvc/view.zep", 1229);
		if (Z_TYPE_P(options) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(options), _2$$3, _3$$3, _0$$3)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_3$$3 != NULL) { 
					ZVAL_STR_COPY(&key, _3$$3);
				} else {
					ZVAL_LONG(&key, _2$$3);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _0$$3);
				zephir_array_update_zval(&cacheOptions, &key, &value, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, options, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, options, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, options, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, options, "current", NULL, 0);
				zephir_check_call_status();
					zephir_array_update_zval(&cacheOptions, &key, &value, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, options, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		if (zephir_array_isset_string_fetch(&cacheLevel, &cacheOptions, SL("level"), 1)) {
			zephir_update_property_zval(this_ptr, SL("_cacheLevel"), &cacheLevel);
		} else {
			ZEPHIR_INIT_ZVAL_NREF(_4$$9);
			ZVAL_LONG(&_4$$9, 5);
			zephir_update_property_zval(this_ptr, SL("_cacheLevel"), &_4$$9);
		}
		zephir_array_update_string(&viewOptions, SL("cache"), &cacheOptions, PH_COPY | PH_SEPARATE);
		zephir_update_property_zval(this_ptr, SL("_options"), &viewOptions);
	} else {
		if (zephir_is_true(options)) {
			ZEPHIR_INIT_ZVAL_NREF(_5$$11);
			ZVAL_LONG(&_5$$11, 5);
			zephir_update_property_zval(this_ptr, SL("_cacheLevel"), &_5$$11);
		} else {
			ZEPHIR_INIT_ZVAL_NREF(_6$$12);
			ZVAL_LONG(&_6$$12, 0);
			zephir_update_property_zval(this_ptr, SL("_cacheLevel"), &_6$$12);
		}
	}
	RETURN_THIS();

}

/**
 * Externally sets the view content
 *
 *<code>
 * $this->view->setContent("<h1>hello</h1>");
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_View, setContent) {

	zval *content_param = NULL;
	zval content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

	zephir_get_strval(&content, content_param);


	zephir_update_property_zval(this_ptr, SL("_content"), &content);
	RETURN_THIS();

}

/**
 * Returns cached output from another view stage
 */
PHP_METHOD(Phalcon_Mvc_View, getContent) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_content");

}

/**
 * Returns the path (or paths) of the views that are currently rendered
 */
PHP_METHOD(Phalcon_Mvc_View, getActiveRenderPath) {

	zval activeRenderPath, _0, _1$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS, viewsDirsCount = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&activeRenderPath);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$5);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getviewsdirs", NULL, 0);
	zephir_check_call_status();
	viewsDirsCount = zephir_fast_count_int(&_0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&activeRenderPath);
	zephir_read_property(&activeRenderPath, this_ptr, SL("_activeRenderPaths"), PH_NOISY_CC);
	if (viewsDirsCount == 1) {
		if (Z_TYPE_P(&activeRenderPath) == IS_ARRAY) {
			if (zephir_fast_count_int(&activeRenderPath TSRMLS_CC)) {
				zephir_array_fetch_long(&_1$$5, &activeRenderPath, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/view.zep", 1287 TSRMLS_CC);
				ZEPHIR_CPY_WRT(&activeRenderPath, &_1$$5);
			}
		}
	}
	if (Z_TYPE_P(&activeRenderPath) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&activeRenderPath);
		ZVAL_STRING(&activeRenderPath, "");
	}
	RETURN_CCTOR(&activeRenderPath);

}

/**
 * Disables the auto-rendering process
 */
PHP_METHOD(Phalcon_Mvc_View, disable) {

	zval __$true, __$false;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);


	if (1) {
		zephir_update_property_zval(this_ptr, SL("_disabled"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_disabled"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Enables the auto-rendering process
 */
PHP_METHOD(Phalcon_Mvc_View, enable) {

	zval __$true, __$false;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);


	if (0) {
		zephir_update_property_zval(this_ptr, SL("_disabled"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_disabled"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Resets the view component to its factory default values
 */
PHP_METHOD(Phalcon_Mvc_View, reset) {

	zval __$true, __$false, __$null, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	if (0) {
		zephir_update_property_zval(this_ptr, SL("_disabled"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_disabled"), &__$false);
	}
	if (0) {
		zephir_update_property_zval(this_ptr, SL("_engines"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_engines"), &__$false);
	}
	zephir_update_property_zval(this_ptr, SL("_cache"), &__$null);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 5);
	zephir_update_property_zval(this_ptr, SL("_renderLevel"), &_0);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval(this_ptr, SL("_cacheLevel"), &_0);
	zephir_update_property_zval(this_ptr, SL("_content"), &__$null);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval(this_ptr, SL("_templatesBefore"), &_1);
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	zephir_update_property_zval(this_ptr, SL("_templatesAfter"), &_2);
	RETURN_THIS();

}

/**
 * Magic method to pass variables to the views
 *
 *<code>
 * $this->view->products = $products;
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_View, __set) {

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
PHP_METHOD(Phalcon_Mvc_View, __get) {

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
 * Whether automatic rendering is enabled
 */
PHP_METHOD(Phalcon_Mvc_View, isDisabled) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_disabled");

}

/**
 * Magic method to retrieve if a variable is set in the view
 *
 *<code>
 * echo isset($this->view->products);
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_View, __isset) {

	zval *key_param = NULL, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
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
	RETURN_MM_BOOL(zephir_array_isset(&_0, &key));

}

/**
 * Gets views directories
 */
PHP_METHOD(Phalcon_Mvc_View, getViewsDirs) {

	zval _0, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("_viewsDirs"), PH_NOISY_CC);
	if (Z_TYPE_P(&_0) == IS_STRING) {
		zephir_create_array(return_value, 1, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&_1$$3);
		zephir_read_property(&_1$$3, this_ptr, SL("_viewsDirs"), PH_NOISY_CC);
		zephir_array_fast_append(return_value, &_1$$3);
		RETURN_MM();
	}
	RETURN_MM_MEMBER(getThis(), "_viewsDirs");

}

zend_object *zephir_init_properties_Phalcon_Mvc_View(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _6, _8, _10, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7, _11$$8;
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

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_registeredEngines"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("_registeredEngines"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("_templatesAfter"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("_templatesAfter"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("_templatesBefore"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("_templatesBefore"), &_5$$5);
		}
		zephir_read_property(&_6, this_ptr, SL("_viewsDirs"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval(this_ptr, SL("_viewsDirs"), &_7$$6);
		}
		zephir_read_property(&_8, this_ptr, SL("_viewParams"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval(this_ptr, SL("_viewParams"), &_9$$7);
		}
		zephir_read_property(&_10, this_ptr, SL("_options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_10) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_11$$8);
			array_init(&_11$$8);
			zephir_update_property_zval(this_ptr, SL("_options"), &_11$$8);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

