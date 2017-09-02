
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
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/fcall.h"
#include "Zend/zend_closures.h"
#include "kernel/file.h"


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

	/**
	 * @var array
	 */
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

/**
 */
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

	zend_string *_6$$6;
	zend_ulong _5$$6;
	zend_bool _0;
	zval *viewsDir = NULL, viewsDir_sub, position, directory, directorySeparator, newViewsDir, _1$$4, _2$$4, _3$$5, *_4$$6, _7$$7, _8$$7, _9$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewsDir_sub);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&directory);
	ZVAL_UNDEF(&directorySeparator);
	ZVAL_UNDEF(&newViewsDir);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &viewsDir);

	ZEPHIR_SEPARATE_PARAM(viewsDir);


	_0 = Z_TYPE_P(viewsDir) != IS_STRING;
	if (_0) {
		_0 = Z_TYPE_P(viewsDir) != IS_ARRAY;
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "Views directory must be a string or an array", "phalcon/mvc/view.zep", 179);
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
		zephir_is_iterable(viewsDir, 0, "phalcon/mvc/view.zep", 206);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(viewsDir), _5$$6, _6$$6, _4$$6)
		{
			ZEPHIR_INIT_NVAR(&position);
			if (_6$$6 != NULL) { 
				ZVAL_STR_COPY(&position, _6$$6);
			} else {
				ZVAL_LONG(&position, _5$$6);
			}
			ZEPHIR_INIT_NVAR(&directory);
			ZVAL_COPY(&directory, _4$$6);
			if (Z_TYPE_P(&directory) != IS_STRING) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "Views directory item must be a string", "phalcon/mvc/view.zep", 196);
				return;
			}
			ZVAL_LONG(&_7$$7, -1);
			ZEPHIR_INIT_NVAR(&_8$$7);
			zephir_substr(&_8$$7, &directory, -1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			if (!ZEPHIR_IS_EQUAL(&_8$$7, &directorySeparator)) {
				ZEPHIR_INIT_LNVAR(_9$$9);
				ZEPHIR_CONCAT_VV(&_9$$9, &directory, &directorySeparator);
				zephir_array_update_zval(&newViewsDir, &position, &_9$$9, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&newViewsDir, &position, &directory, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
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
		zephir_update_property_array(this_ptr, SL("_disabledLevels"), level, &__$true TSRMLS_CC);
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}


	zephir_update_property_array(this_ptr, SL("_viewParams"), &key, value TSRMLS_CC);
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}


	zephir_update_property_array(this_ptr, SL("_viewParams"), &key, value TSRMLS_CC);
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
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
 * Gets extra parameters of the action rendered
 */
PHP_METHOD(Phalcon_Mvc_View, getParams) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_params");

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

	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 125);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_content"), &__$null);
	RETURN_THIS();

}

/**
 * Loads registered template engines, if none is registered it will use Phalcon\Mvc\View\Engine\Php
 */
PHP_METHOD(Phalcon_Mvc_View, _loadTemplateEngines) {

	zend_string *_4$$5;
	zend_ulong _3$$5;
	zval engines, dependencyInjector, registeredEngines, arguments, engineService, extension, _0$$3, _1$$4, *_2$$5, _5$$9, _6$$12, _7$$12, _9$$11;
	zephir_fcall_cache_entry *_8 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&engines);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&registeredEngines);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&engineService);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_6$$12);
	ZVAL_UNDEF(&_7$$12);
	ZVAL_UNDEF(&_9$$11);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&engines);
	zephir_read_property(&engines, this_ptr, SL("_engines"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&engines)) {
		zephir_read_property(&_0$$3, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&dependencyInjector, &_0$$3);
		ZEPHIR_INIT_NVAR(&engines);
		array_init(&engines);
		ZEPHIR_OBS_VAR(&registeredEngines);
		zephir_read_property(&registeredEngines, this_ptr, SL("_registeredEngines"), PH_NOISY_CC);
		if (Z_TYPE_P(&registeredEngines) != IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_1$$4);
			object_init_ex(&_1$$4, phalcon_mvc_view_engine_php_ce);
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 357, this_ptr, &dependencyInjector);
			zephir_check_call_status();
			zephir_array_update_string(&engines, SL(".phtml"), &_1$$4, PH_COPY | PH_SEPARATE);
		} else {
			if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "A dependency injector container is required to obtain the application services", "phalcon/mvc/view.zep", 540);
				return;
			}
			ZEPHIR_INIT_VAR(&arguments);
			zephir_create_array(&arguments, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(&arguments, this_ptr);
			zephir_array_fast_append(&arguments, &dependencyInjector);
			zephir_is_iterable(&registeredEngines, 0, "phalcon/mvc/view.zep", 569);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&registeredEngines), _3$$5, _4$$5, _2$$5)
			{
				ZEPHIR_INIT_NVAR(&extension);
				if (_4$$5 != NULL) { 
					ZVAL_STR_COPY(&extension, _4$$5);
				} else {
					ZVAL_LONG(&extension, _3$$5);
				}
				ZEPHIR_INIT_NVAR(&engineService);
				ZVAL_COPY(&engineService, _2$$5);
				if (Z_TYPE_P(&engineService) == IS_OBJECT) {
					if (zephir_instance_of_ev(&engineService, zend_ce_closure TSRMLS_CC)) {
						ZEPHIR_INIT_NVAR(&_5$$9);
						ZEPHIR_CALL_USER_FUNC_ARRAY(&_5$$9, &engineService, &arguments);
						zephir_check_call_status();
						zephir_array_update_zval(&engines, &extension, &_5$$9, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_update_zval(&engines, &extension, &engineService, PH_COPY | PH_SEPARATE);
					}
				} else {
					if (Z_TYPE_P(&engineService) != IS_STRING) {
						ZEPHIR_INIT_NVAR(&_6$$12);
						object_init_ex(&_6$$12, phalcon_mvc_view_exception_ce);
						ZEPHIR_INIT_LNVAR(_7$$12);
						ZEPHIR_CONCAT_SV(&_7$$12, "Invalid template engine registration for extension: ", &extension);
						ZEPHIR_CALL_METHOD(NULL, &_6$$12, "__construct", &_8, 4, &_7$$12);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_6$$12, "phalcon/mvc/view.zep", 563 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(&_9$$11, &dependencyInjector, "getshared", &_10, 0, &engineService, &arguments);
					zephir_check_call_status();
					zephir_array_update_zval(&engines, &extension, &_9$$11, PH_COPY | PH_SEPARATE);
				}
			} ZEND_HASH_FOREACH_END();
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

	zend_string *_14$$3;
	zend_ulong _13$$3;
	zephir_fcall_cache_entry *_4 = NULL, *_8 = NULL, *_9 = NULL, *_11 = NULL, *_18 = NULL, *_21 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, renderLevel = 0, cacheLevel = 0;
	zend_bool silence, mustClean, notExists = 0;
	zval viewPath, _24$$21;
	zval *engines_param = NULL, *viewPath_param = NULL, *silence_param = NULL, *mustClean_param = NULL, *cache = NULL, cache_sub, __$null, key, lifetime, viewsDir, basePath, viewsDirPath, viewOptions, cacheOptions, cachedView, viewParams, eventsManager, extension, engine, viewEnginePath, viewEnginePaths, _0, _1, *_2, _3$$3, *_12$$3, _5$$6, _6$$6, _7$$7, _10$$7, _16$$16, _17$$16, _19$$15, _20$$18, _22$$20, _23$$21;
	zval engines, _15$$16;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&engines);
	ZVAL_UNDEF(&_15$$16);
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
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_16$$16);
	ZVAL_UNDEF(&_17$$16);
	ZVAL_UNDEF(&_19$$15);
	ZVAL_UNDEF(&_20$$18);
	ZVAL_UNDEF(&_22$$20);
	ZVAL_UNDEF(&_23$$21);
	ZVAL_UNDEF(&viewPath);
	ZVAL_UNDEF(&_24$$21);

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
	zephir_is_iterable(&_1, 0, "phalcon/mvc/view.zep", 690);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1), _2)
	{
		ZEPHIR_INIT_NVAR(&viewsDir);
		ZVAL_COPY(&viewsDir, _2);
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "_isabsolutepath", &_4, 358, &viewPath);
		zephir_check_call_status();
		if (!(zephir_is_true(&_3$$3))) {
			ZEPHIR_INIT_NVAR(&viewsDirPath);
			ZEPHIR_CONCAT_VVV(&viewsDirPath, &basePath, &viewsDir, &viewPath);
		} else {
			ZEPHIR_CPY_WRT(&viewsDirPath, &viewPath);
		}
		if (Z_TYPE_P(cache) == IS_OBJECT) {
			ZEPHIR_OBS_NVAR(&_5$$6);
			zephir_read_property(&_5$$6, this_ptr, SL("_renderLevel"), PH_NOISY_CC);
			renderLevel = zephir_get_intval(&_5$$6);
			ZEPHIR_OBS_NVAR(&_6$$6);
			zephir_read_property(&_6$$6, this_ptr, SL("_cacheLevel"), PH_NOISY_CC);
			cacheLevel = zephir_get_intval(&_6$$6);
			if (renderLevel >= cacheLevel) {
				ZEPHIR_CALL_METHOD(&_7$$7, cache, "isstarted", &_8, 0);
				zephir_check_call_status();
				if (!(zephir_is_true(&_7$$7))) {
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
					ZEPHIR_CALL_METHOD(&cachedView, cache, "start", &_9, 0, &key, &lifetime);
					zephir_check_call_status();
					if (Z_TYPE_P(&cachedView) != IS_NULL) {
						zephir_update_property_zval(this_ptr, SL("_content"), &cachedView);
						RETURN_MM_NULL();
					}
				}
				ZEPHIR_CALL_METHOD(&_10$$7, cache, "isfresh", &_11, 0);
				zephir_check_call_status();
				if (!(zephir_is_true(&_10$$7))) {
					RETURN_MM_NULL();
				}
			}
		}
		zephir_is_iterable(&engines, 0, "phalcon/mvc/view.zep", 688);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&engines), _13$$3, _14$$3, _12$$3)
		{
			ZEPHIR_INIT_NVAR(&extension);
			if (_14$$3 != NULL) { 
				ZVAL_STR_COPY(&extension, _14$$3);
			} else {
				ZVAL_LONG(&extension, _13$$3);
			}
			ZEPHIR_INIT_NVAR(&engine);
			ZVAL_COPY(&engine, _12$$3);
			ZEPHIR_INIT_NVAR(&viewEnginePath);
			ZEPHIR_CONCAT_VV(&viewEnginePath, &viewsDirPath, &extension);
			if ((zephir_file_exists(&viewEnginePath TSRMLS_CC) == SUCCESS)) {
				if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&_15$$16);
					zephir_create_array(&_15$$16, 1, 0 TSRMLS_CC);
					zephir_array_fast_append(&_15$$16, &viewEnginePath);
					zephir_update_property_zval(this_ptr, SL("_activeRenderPaths"), &_15$$16);
					ZEPHIR_INIT_NVAR(&_17$$16);
					ZVAL_STRING(&_17$$16, "view:beforeRenderView");
					ZEPHIR_CALL_METHOD(&_16$$16, &eventsManager, "fire", &_18, 0, &_17$$16, this_ptr, &viewEnginePath);
					zephir_check_call_status();
					if (ZEPHIR_IS_FALSE_IDENTICAL(&_16$$16)) {
						continue;
					}
				}
				if (mustClean) {
					ZVAL_BOOL(&_19$$15, 1);
				} else {
					ZVAL_BOOL(&_19$$15, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, &engine, "render", NULL, 0, &viewEnginePath, &viewParams, &_19$$15);
				zephir_check_call_status();
				notExists = 0;
				if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&_20$$18);
					ZVAL_STRING(&_20$$18, "view:afterRenderView");
					ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_21, 0, &_20$$18, this_ptr);
					zephir_check_call_status();
				}
				break;
			}
			zephir_array_append(&viewEnginePaths, &viewEnginePath, PH_SEPARATE, "phalcon/mvc/view.zep", 686);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&engine);
		ZEPHIR_INIT_NVAR(&extension);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&viewsDir);
	if (notExists == 1) {
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			zephir_update_property_zval(this_ptr, SL("_activeRenderPaths"), &viewEnginePaths);
			ZEPHIR_INIT_VAR(&_22$$20);
			ZVAL_STRING(&_22$$20, "view:notFoundView");
			ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_22$$20, this_ptr, &viewEnginePath);
			zephir_check_call_status();
		}
		if (!(silence)) {
			ZEPHIR_INIT_VAR(&_23$$21);
			object_init_ex(&_23$$21, phalcon_mvc_view_exception_ce);
			ZEPHIR_INIT_VAR(&_24$$21);
			ZEPHIR_CONCAT_SVS(&_24$$21, "View '", &viewPath, "' was not found in any of the views directory");
			ZEPHIR_CALL_METHOD(NULL, &_23$$21, "__construct", NULL, 4, &_24$$21);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_23$$21, "phalcon/mvc/view.zep", 700 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_MM_RESTORE();

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

	zend_string *_5$$4;
	zend_ulong _4$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *view_param = NULL, basePath, viewsDir, engines, extension, _0, *_1, _2$$4, *_3$$4, _6$$5;
	zval view;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&view);
	ZVAL_UNDEF(&basePath);
	ZVAL_UNDEF(&viewsDir);
	ZVAL_UNDEF(&engines);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_6$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &view_param);

	if (UNEXPECTED(Z_TYPE_P(view_param) != IS_STRING && Z_TYPE_P(view_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'view' must be a string") TSRMLS_CC);
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
	if (Z_TYPE_P(&engines) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(&engines);
		zephir_create_array(&engines, 1, 0 TSRMLS_CC);
		add_assoc_stringl_ex(&engines, SL(".phtml"), SL("Phalcon\\Mvc\\View\\Engine\\Php"));
		zephir_update_property_zval(this_ptr, SL("_registeredEngines"), &engines);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getviewsdirs", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/mvc/view.zep", 747);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
	{
		ZEPHIR_INIT_NVAR(&viewsDir);
		ZVAL_COPY(&viewsDir, _1);
		ZEPHIR_INIT_NVAR(&_2$$4);
		zephir_is_iterable(&engines, 0, "phalcon/mvc/view.zep", 745);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&engines), _4$$4, _5$$4, _3$$4)
		{
			ZEPHIR_INIT_NVAR(&extension);
			if (_5$$4 != NULL) { 
				ZVAL_STR_COPY(&extension, _5$$4);
			} else {
				ZVAL_LONG(&extension, _4$$4);
			}
			ZEPHIR_INIT_NVAR(&_2$$4);
			ZVAL_COPY(&_2$$4, _3$$4);
			ZEPHIR_INIT_LNVAR(_6$$5);
			ZEPHIR_CONCAT_VVVV(&_6$$5, &basePath, &viewsDir, &view, &extension);
			if ((zephir_file_exists(&_6$$5 TSRMLS_CC) == SUCCESS)) {
				RETURN_MM_BOOL(1);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&_2$$4);
		ZEPHIR_INIT_NVAR(&extension);
	} ZEND_HASH_FOREACH_END();
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

	zend_bool silence = 0, mustClean = 0, _33$$29;
	zend_long ZEPHIR_LAST_CALL_STATUS, renderLevel = 0;
	zephir_fcall_cache_entry *_2 = NULL, *_14 = NULL;
	zval params;
	zval *controllerName_param = NULL, *actionName_param = NULL, *params_param = NULL, layoutsDir, layout, pickView, layoutName, engines, renderView, pickViewAction, eventsManager, disabledLevels, templatesBefore, templatesAfter, templateBefore, templateAfter, cache, _0, _4, _5, _6, _10, _11, _1$$3, _7$$13, _8$$14, _9$$14, _12$$18, _13$$18, _15$$20, *_16$$20, _17$$21, _18$$21, _19$$21, _20$$23, _21$$23, _22$$23, _23$$25, *_24$$25, _25$$26, _26$$26, _27$$26, _28$$28, _29$$28, _30$$28, _31$$16, _32$$29, _34$$29, _35$$32;
	zval controllerName, actionName, _3$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&controllerName);
	ZVAL_UNDEF(&actionName);
	ZVAL_UNDEF(&_3$$7);
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
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_7$$13);
	ZVAL_UNDEF(&_8$$14);
	ZVAL_UNDEF(&_9$$14);
	ZVAL_UNDEF(&_12$$18);
	ZVAL_UNDEF(&_13$$18);
	ZVAL_UNDEF(&_15$$20);
	ZVAL_UNDEF(&_17$$21);
	ZVAL_UNDEF(&_18$$21);
	ZVAL_UNDEF(&_19$$21);
	ZVAL_UNDEF(&_20$$23);
	ZVAL_UNDEF(&_21$$23);
	ZVAL_UNDEF(&_22$$23);
	ZVAL_UNDEF(&_23$$25);
	ZVAL_UNDEF(&_25$$26);
	ZVAL_UNDEF(&_26$$26);
	ZVAL_UNDEF(&_27$$26);
	ZVAL_UNDEF(&_28$$28);
	ZVAL_UNDEF(&_29$$28);
	ZVAL_UNDEF(&_30$$28);
	ZVAL_UNDEF(&_31$$16);
	ZVAL_UNDEF(&_32$$29);
	ZVAL_UNDEF(&_34$$29);
	ZVAL_UNDEF(&_35$$32);
	ZVAL_UNDEF(&params);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &controllerName_param, &actionName_param, &params_param);

	if (UNEXPECTED(Z_TYPE_P(controllerName_param) != IS_STRING && Z_TYPE_P(controllerName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'controllerName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(controllerName_param) == IS_STRING)) {
		zephir_get_strval(&controllerName, controllerName_param);
	} else {
		ZEPHIR_INIT_VAR(&controllerName);
		ZVAL_EMPTY_STRING(&controllerName);
	}
	if (UNEXPECTED(Z_TYPE_P(actionName_param) != IS_STRING && Z_TYPE_P(actionName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'actionName' must be a string") TSRMLS_CC);
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
		ZEPHIR_CALL_FUNCTION(&_1$$3, "ob_get_contents", &_2, 126);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_content"), &_1$$3);
		RETURN_MM_BOOL(0);
	}
	zephir_update_property_zval(this_ptr, SL("_controllerName"), &controllerName);
	zephir_update_property_zval(this_ptr, SL("_actionName"), &actionName);
	zephir_update_property_zval(this_ptr, SL("_params"), &params);
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
		ZEPHIR_INIT_VAR(&_3$$7);
		ZEPHIR_CONCAT_VSV(&_3$$7, &controllerName, "/", &actionName);
		ZEPHIR_CPY_WRT(&renderView, &_3$$7);
	} else {
		ZEPHIR_OBS_NVAR(&renderView);
		zephir_array_fetch_long(&renderView, &pickView, 0, PH_NOISY, "phalcon/mvc/view.zep", 816 TSRMLS_CC);
		if (Z_TYPE_P(&layoutName) == IS_NULL) {
			ZEPHIR_OBS_VAR(&pickViewAction);
			if (zephir_array_isset_long_fetch(&pickViewAction, &pickView, 1, 0 TSRMLS_CC)) {
				ZEPHIR_CPY_WRT(&layoutName, &pickViewAction);
			}
		}
	}
	zephir_read_property(&_4, this_ptr, SL("_cacheLevel"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_4)) {
		ZEPHIR_CALL_METHOD(&cache, this_ptr, "getcache", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&cache);
		ZVAL_NULL(&cache);
	}
	zephir_read_property(&_5, this_ptr, SL("_eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_5);
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_GET_CONSTANT(&_6, "PHP_MAJOR_VERSION");
	if (ZEPHIR_IS_LONG(&_6, 5)) {
		ZEPHIR_INIT_VAR(&_7$$13);
		zephir_create_symbol_table(TSRMLS_C);
		
	}
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_9$$14);
		ZVAL_STRING(&_9$$14, "view:beforeRender");
		ZEPHIR_CALL_METHOD(&_8$$14, &eventsManager, "fire", NULL, 0, &_9$$14, this_ptr);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_8$$14)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_CALL_FUNCTION(&_10, "ob_get_contents", &_2, 126);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_content"), &_10);
	mustClean = 1;
	silence = 1;
	ZEPHIR_OBS_VAR(&disabledLevels);
	zephir_read_property(&disabledLevels, this_ptr, SL("_disabledLevels"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&_11);
	zephir_read_property(&_11, this_ptr, SL("_renderLevel"), PH_NOISY_CC);
	renderLevel = zephir_get_intval(&_11);
	if (renderLevel) {
		if (renderLevel >= 1) {
			if (!(zephir_array_isset_long(&disabledLevels, 1))) {
				ZEPHIR_INIT_ZVAL_NREF(_12$$18);
				ZVAL_LONG(&_12$$18, 1);
				zephir_update_property_zval(this_ptr, SL("_currentRenderLevel"), &_12$$18);
				if (silence) {
					ZVAL_BOOL(&_12$$18, 1);
				} else {
					ZVAL_BOOL(&_12$$18, 0);
				}
				if (mustClean) {
					ZVAL_BOOL(&_13$$18, 1);
				} else {
					ZVAL_BOOL(&_13$$18, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_enginerender", &_14, 0, &engines, &renderView, &_12$$18, &_13$$18, &cache);
				zephir_check_call_status();
			}
		}
		if (renderLevel >= 2) {
			if (!(zephir_array_isset_long(&disabledLevels, 2))) {
				ZEPHIR_INIT_ZVAL_NREF(_15$$20);
				ZVAL_LONG(&_15$$20, 2);
				zephir_update_property_zval(this_ptr, SL("_currentRenderLevel"), &_15$$20);
				ZEPHIR_OBS_VAR(&templatesBefore);
				zephir_read_property(&templatesBefore, this_ptr, SL("_templatesBefore"), PH_NOISY_CC);
				silence = 0;
				zephir_is_iterable(&templatesBefore, 0, "phalcon/mvc/view.zep", 894);
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&templatesBefore), _16$$20)
				{
					ZEPHIR_INIT_NVAR(&templateBefore);
					ZVAL_COPY(&templateBefore, _16$$20);
					ZEPHIR_INIT_LNVAR(_17$$21);
					ZEPHIR_CONCAT_VV(&_17$$21, &layoutsDir, &templateBefore);
					if (silence) {
						ZVAL_BOOL(&_18$$21, 1);
					} else {
						ZVAL_BOOL(&_18$$21, 0);
					}
					if (mustClean) {
						ZVAL_BOOL(&_19$$21, 1);
					} else {
						ZVAL_BOOL(&_19$$21, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "_enginerender", &_14, 0, &engines, &_17$$21, &_18$$21, &_19$$21, &cache);
					zephir_check_call_status();
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&templateBefore);
				silence = 1;
			}
		}
		if (renderLevel >= 3) {
			if (!(zephir_array_isset_long(&disabledLevels, 3))) {
				ZEPHIR_INIT_ZVAL_NREF(_20$$23);
				ZVAL_LONG(&_20$$23, 3);
				zephir_update_property_zval(this_ptr, SL("_currentRenderLevel"), &_20$$23);
				ZEPHIR_INIT_VAR(&_21$$23);
				ZEPHIR_CONCAT_VV(&_21$$23, &layoutsDir, &layoutName);
				if (silence) {
					ZVAL_BOOL(&_20$$23, 1);
				} else {
					ZVAL_BOOL(&_20$$23, 0);
				}
				if (mustClean) {
					ZVAL_BOOL(&_22$$23, 1);
				} else {
					ZVAL_BOOL(&_22$$23, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_enginerender", &_14, 0, &engines, &_21$$23, &_20$$23, &_22$$23, &cache);
				zephir_check_call_status();
			}
		}
		if (renderLevel >= 4) {
			if (!(zephir_array_isset_long(&disabledLevels, 4))) {
				ZEPHIR_INIT_ZVAL_NREF(_23$$25);
				ZVAL_LONG(&_23$$25, 4);
				zephir_update_property_zval(this_ptr, SL("_currentRenderLevel"), &_23$$25);
				ZEPHIR_OBS_VAR(&templatesAfter);
				zephir_read_property(&templatesAfter, this_ptr, SL("_templatesAfter"), PH_NOISY_CC);
				silence = 0;
				zephir_is_iterable(&templatesAfter, 0, "phalcon/mvc/view.zep", 921);
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&templatesAfter), _24$$25)
				{
					ZEPHIR_INIT_NVAR(&templateAfter);
					ZVAL_COPY(&templateAfter, _24$$25);
					ZEPHIR_INIT_LNVAR(_25$$26);
					ZEPHIR_CONCAT_VV(&_25$$26, &layoutsDir, &templateAfter);
					if (silence) {
						ZVAL_BOOL(&_26$$26, 1);
					} else {
						ZVAL_BOOL(&_26$$26, 0);
					}
					if (mustClean) {
						ZVAL_BOOL(&_27$$26, 1);
					} else {
						ZVAL_BOOL(&_27$$26, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "_enginerender", &_14, 0, &engines, &_25$$26, &_26$$26, &_27$$26, &cache);
					zephir_check_call_status();
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&templateAfter);
				silence = 1;
			}
		}
		if (renderLevel >= 5) {
			if (!(zephir_array_isset_long(&disabledLevels, 5))) {
				ZEPHIR_INIT_ZVAL_NREF(_28$$28);
				ZVAL_LONG(&_28$$28, 5);
				zephir_update_property_zval(this_ptr, SL("_currentRenderLevel"), &_28$$28);
				zephir_read_property(&_28$$28, this_ptr, SL("_mainView"), PH_NOISY_CC | PH_READONLY);
				if (silence) {
					ZVAL_BOOL(&_29$$28, 1);
				} else {
					ZVAL_BOOL(&_29$$28, 0);
				}
				if (mustClean) {
					ZVAL_BOOL(&_30$$28, 1);
				} else {
					ZVAL_BOOL(&_30$$28, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_enginerender", &_14, 0, &engines, &_28$$28, &_29$$28, &_30$$28, &cache);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_ZVAL_NREF(_31$$16);
		ZVAL_LONG(&_31$$16, 0);
		zephir_update_property_zval(this_ptr, SL("_currentRenderLevel"), &_31$$16);
		if (Z_TYPE_P(&cache) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(&_32$$29, &cache, "isstarted", NULL, 0);
			zephir_check_call_status();
			_33$$29 = zephir_is_true(&_32$$29);
			if (_33$$29) {
				ZEPHIR_CALL_METHOD(&_34$$29, &cache, "isfresh", NULL, 0);
				zephir_check_call_status();
				_33$$29 = zephir_is_true(&_34$$29);
			}
			if (_33$$29) {
				ZEPHIR_CALL_METHOD(NULL, &cache, "save", NULL, 0);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &cache, "stop", NULL, 0);
				zephir_check_call_status();
			}
		}
	}
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_35$$32);
		ZVAL_STRING(&_35$$32, "view:afterRender");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_35$$32, this_ptr);
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

	zval *renderView, renderView_sub, pickView, layout, parts;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&renderView_sub);
	ZVAL_UNDEF(&pickView);
	ZVAL_UNDEF(&layout);
	ZVAL_UNDEF(&parts);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &renderView);



	if (Z_TYPE_P(renderView) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&pickView, renderView);
	} else {
		ZEPHIR_INIT_VAR(&layout);
		ZVAL_NULL(&layout);
		if (zephir_memnstr_str(renderView, SL("/"), "phalcon/mvc/view.zep", 986)) {
			ZEPHIR_INIT_VAR(&parts);
			zephir_fast_explode_str(&parts, SL("/"), renderView, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&layout);
			zephir_array_fetch_long(&layout, &parts, 0, PH_NOISY, "phalcon/mvc/view.zep", 987 TSRMLS_CC);
		}
		ZEPHIR_INIT_NVAR(&pickView);
		zephir_create_array(&pickView, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&pickView, renderView);
		if (Z_TYPE_P(&layout) != IS_NULL) {
			zephir_array_append(&pickView, &layout, PH_SEPARATE, "phalcon/mvc/view.zep", 992);
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'partialPath' must be a string") TSRMLS_CC);
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


	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 125);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "partial", NULL, 0, &partialPath, params);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", NULL, 269);
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'partialPath' must be a string") TSRMLS_CC);
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'controllerName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(controllerName_param) == IS_STRING)) {
		zephir_get_strval(&controllerName, controllerName_param);
	} else {
		ZEPHIR_INIT_VAR(&controllerName);
		ZVAL_EMPTY_STRING(&controllerName);
	}
	if (UNEXPECTED(Z_TYPE_P(actionName_param) != IS_STRING && Z_TYPE_P(actionName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'actionName' must be a string") TSRMLS_CC);
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
	ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 127);
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

	ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 127);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "A dependency injector container is required to obtain the view cache services", "phalcon/mvc/view.zep", 1167);
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
			zephir_array_fetch_string(&cacheService, &cacheOptions, SL("service"), PH_NOISY, "phalcon/mvc/view.zep", 1176 TSRMLS_CC);
		}
	}
	ZEPHIR_CALL_METHOD(&_1, &dependencyInjector, "getshared", NULL, 0, &cacheService);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&viewCache, &_1);
	if (Z_TYPE_P(&viewCache) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "The injected caching service is invalid", "phalcon/mvc/view.zep", 1185);
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

	zend_string *_2$$3;
	zend_ulong _1$$3;
	zval *options = NULL, options_sub, __$true, viewOptions, cacheOptions, key, value, cacheLevel, *_0$$3, _3$$8, _4$$10, _5$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&viewOptions);
	ZVAL_UNDEF(&cacheOptions);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&cacheLevel);
	ZVAL_UNDEF(&_3$$8);
	ZVAL_UNDEF(&_4$$10);
	ZVAL_UNDEF(&_5$$11);

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
		zephir_is_iterable(options, 0, "phalcon/mvc/view.zep", 1248);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(options), _1$$3, _2$$3, _0$$3)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_2$$3 != NULL) { 
				ZVAL_STR_COPY(&key, _2$$3);
			} else {
				ZVAL_LONG(&key, _1$$3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0$$3);
			zephir_array_update_zval(&cacheOptions, &key, &value, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		if (zephir_array_isset_string_fetch(&cacheLevel, &cacheOptions, SL("level"), 1)) {
			zephir_update_property_zval(this_ptr, SL("_cacheLevel"), &cacheLevel);
		} else {
			ZEPHIR_INIT_ZVAL_NREF(_3$$8);
			ZVAL_LONG(&_3$$8, 5);
			zephir_update_property_zval(this_ptr, SL("_cacheLevel"), &_3$$8);
		}
		zephir_array_update_string(&viewOptions, SL("cache"), &cacheOptions, PH_COPY | PH_SEPARATE);
		zephir_update_property_zval(this_ptr, SL("_options"), &viewOptions);
	} else {
		if (zephir_is_true(options)) {
			ZEPHIR_INIT_ZVAL_NREF(_4$$10);
			ZVAL_LONG(&_4$$10, 5);
			zephir_update_property_zval(this_ptr, SL("_cacheLevel"), &_4$$10);
		} else {
			ZEPHIR_INIT_ZVAL_NREF(_5$$11);
			ZVAL_LONG(&_5$$11, 0);
			zephir_update_property_zval(this_ptr, SL("_cacheLevel"), &_5$$11);
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
				zephir_array_fetch_long(&_1$$5, &activeRenderPath, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/view.zep", 1306 TSRMLS_CC);
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}


	zephir_update_property_array(this_ptr, SL("_viewParams"), &key, value TSRMLS_CC);
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
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

		zval _0, _2, _4, _6, _1$$3, _3$$4, _5$$5, _7$$6;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_templatesAfter"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("_templatesAfter"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("_templatesBefore"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("_templatesBefore"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("_viewsDirs"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("_viewsDirs"), &_5$$5);
		}
		zephir_read_property(&_6, this_ptr, SL("_viewParams"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval(this_ptr, SL("_viewParams"), &_7$$6);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

