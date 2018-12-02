
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
	zend_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_MAIN_LAYOUT"), 5 TSRMLS_CC);

	/**
	 * Render Level: Render to the templates "after"
	 *
	 */
	zend_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_AFTER_TEMPLATE"), 4 TSRMLS_CC);

	/**
	 * Render Level: To the controller layout
	 *
	 */
	zend_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_LAYOUT"), 3 TSRMLS_CC);

	/**
	 * Render Level: To the templates "before"
	 *
	 */
	zend_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_BEFORE_TEMPLATE"), 2 TSRMLS_CC);

	/**
	 * Render Level: To the action view
	 */
	zend_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_ACTION_VIEW"), 1 TSRMLS_CC);

	/**
	 * Render Level: No render any view
	 *
	 */
	zend_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_NO_RENDER"), 0 TSRMLS_CC);

	/**
	 * Cache Mode
	 */
	zend_declare_class_constant_long(phalcon_mvc_view_ce, SL("CACHE_MODE_NONE"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_view_ce, SL("CACHE_MODE_INVERSE"), 1 TSRMLS_CC);

	zend_class_implements(phalcon_mvc_view_ce TSRMLS_CC, 1, phalcon_mvc_viewinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Mvc_View, getRenderLevel) {

	

	RETURN_MEMBER(getThis(), "_renderLevel");

}

PHP_METHOD(Phalcon_Mvc_View, getCurrentRenderLevel) {

	

	RETURN_MEMBER(getThis(), "_currentRenderLevel");

}

/**
 */
PHP_METHOD(Phalcon_Mvc_View, getRegisteredEngines) {

	

	RETURN_MEMBER(getThis(), "_registeredEngines");

}

/**
 * Phalcon\Mvc\View constructor
 */
PHP_METHOD(Phalcon_Mvc_View, __construct) {

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
 * Checks if a path is absolute or not
 */
PHP_METHOD(Phalcon_Mvc_View, _isAbsolutePath) {

	unsigned char _6, _2$$3, _4$$3;
	zend_bool _5, _1$$3, _3$$3;
	zval *path_param = NULL, *_0;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(path, path_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "PHP_OS");
	if (ZEPHIR_IS_STRING(_0, "WINNT")) {
		_1$$3 = zephir_fast_strlen_ev(path) >= 3;
		if (_1$$3) {
			_2$$3 = ZEPHIR_STRING_OFFSET(path, 1);
			_1$$3 = _2$$3 == ':';
		}
		_3$$3 = _1$$3;
		if (_3$$3) {
			_4$$3 = ZEPHIR_STRING_OFFSET(path, 2);
			_3$$3 = _4$$3 == '\\';
		}
		RETURN_MM_BOOL(_3$$3);
	}
	_5 = zephir_fast_strlen_ev(path) >= 1;
	if (_5) {
		_6 = ZEPHIR_STRING_OFFSET(path, 0);
		_5 = _6 == '/';
	}
	RETURN_MM_BOOL(_5);

}

/**
 * Sets the views directory. Depending of your platform,
 * always add a trailing slash or backslash
 */
PHP_METHOD(Phalcon_Mvc_View, setViewsDir) {

	HashTable *_5$$6;
	HashPosition _4$$6;
	zend_bool _0;
	zval *viewsDir = NULL, *position = NULL, *directory = NULL, *directorySeparator = NULL, *newViewsDir = NULL, _1$$4, *_2$$4, *_3$$5, **_6$$6, _7$$7 = zval_used_for_init, *_8$$7 = NULL, *_9$$9 = NULL;

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
	ZEPHIR_INIT_VAR(directorySeparator);
	ZVAL_STRING(directorySeparator, "/", 1);
	if (Z_TYPE_P(viewsDir) == IS_STRING) {
		ZEPHIR_SINIT_VAR(_1$$4);
		ZVAL_LONG(&_1$$4, -1);
		ZEPHIR_INIT_VAR(_2$$4);
		zephir_substr(_2$$4, viewsDir, -1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		if (!ZEPHIR_IS_EQUAL(_2$$4, directorySeparator)) {
			ZEPHIR_INIT_VAR(_3$$5);
			ZEPHIR_CONCAT_VV(_3$$5, viewsDir, directorySeparator);
			ZEPHIR_CPY_WRT(viewsDir, _3$$5);
		}
		zephir_update_property_this(getThis(), SL("_viewsDirs"), viewsDir TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(newViewsDir);
		array_init(newViewsDir);
		zephir_is_iterable(viewsDir, &_5$$6, &_4$$6, 0, 0, "phalcon/mvc/view.zep", 206);
		for (
		  ; zend_hash_get_current_data_ex(_5$$6, (void**) &_6$$6, &_4$$6) == SUCCESS
		  ; zend_hash_move_forward_ex(_5$$6, &_4$$6)
		) {
			ZEPHIR_GET_HMKEY(position, _5$$6, _4$$6);
			ZEPHIR_GET_HVALUE(directory, _6$$6);
			if (Z_TYPE_P(directory) != IS_STRING) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "Views directory item must be a string", "phalcon/mvc/view.zep", 196);
				return;
			}
			ZEPHIR_SINIT_NVAR(_7$$7);
			ZVAL_LONG(&_7$$7, -1);
			ZEPHIR_INIT_NVAR(_8$$7);
			zephir_substr(_8$$7, directory, -1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			if (!ZEPHIR_IS_EQUAL(_8$$7, directorySeparator)) {
				ZEPHIR_INIT_LNVAR(_9$$9);
				ZEPHIR_CONCAT_VV(_9$$9, directory, directorySeparator);
				zephir_array_update_zval(&newViewsDir, position, &_9$$9, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&newViewsDir, position, &directory, PH_COPY | PH_SEPARATE);
			}
		}
		zephir_update_property_this(getThis(), SL("_viewsDirs"), newViewsDir TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Gets views directory
 */
PHP_METHOD(Phalcon_Mvc_View, getViewsDir) {

	

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
	zval *layoutsDir = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &layoutsDir_param);

	zephir_get_strval(layoutsDir, layoutsDir_param);


	zephir_update_property_this(getThis(), SL("_layoutsDir"), layoutsDir TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Gets the current layouts sub-directory
 */
PHP_METHOD(Phalcon_Mvc_View, getLayoutsDir) {

	

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
	zval *partialsDir = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &partialsDir_param);

	zephir_get_strval(partialsDir, partialsDir_param);


	zephir_update_property_this(getThis(), SL("_partialsDir"), partialsDir TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Gets the current partials sub-directory
 */
PHP_METHOD(Phalcon_Mvc_View, getPartialsDir) {

	

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
	zval *basePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &basePath_param);

	zephir_get_strval(basePath, basePath_param);


	zephir_update_property_this(getThis(), SL("_basePath"), basePath TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Gets base path
 */
PHP_METHOD(Phalcon_Mvc_View, getBasePath) {

	

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

	zval *level_param = NULL, *_0;
	zend_long level;

	zephir_fetch_params(0, 1, 0, &level_param);

	level = zephir_get_intval(level_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, level);
	zephir_update_property_this(getThis(), SL("_renderLevel"), _0 TSRMLS_CC);
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

	zval *level;

	zephir_fetch_params(0, 1, 0, &level);



	if (Z_TYPE_P(level) == IS_ARRAY) {
		zephir_update_property_this(getThis(), SL("_disabledLevels"), level TSRMLS_CC);
	} else {
		zephir_update_property_array(this_ptr, SL("_disabledLevels"), level, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
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
	zval *viewPath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &viewPath_param);

	zephir_get_strval(viewPath, viewPath_param);


	zephir_update_property_this(getThis(), SL("_mainView"), viewPath TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the name of the main view
 */
PHP_METHOD(Phalcon_Mvc_View, getMainView) {

	

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
	zval *layout = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &layout_param);

	zephir_get_strval(layout, layout_param);


	zephir_update_property_this(getThis(), SL("_layout"), layout TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the name of the main view
 */
PHP_METHOD(Phalcon_Mvc_View, getLayout) {

	

	RETURN_MEMBER(getThis(), "_layout");

}

/**
 * Sets a template before the controller layout
 */
PHP_METHOD(Phalcon_Mvc_View, setTemplateBefore) {

	zval *_0$$3;
	zval *templateBefore;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &templateBefore);



	if (Z_TYPE_P(templateBefore) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0$$3);
		zephir_create_array(_0$$3, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_0$$3, templateBefore);
		zephir_update_property_this(getThis(), SL("_templatesBefore"), _0$$3 TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_templatesBefore"), templateBefore TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Resets any "template before" layouts
 */
PHP_METHOD(Phalcon_Mvc_View, cleanTemplateBefore) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(getThis(), SL("_templatesBefore"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets a "template after" controller layout
 */
PHP_METHOD(Phalcon_Mvc_View, setTemplateAfter) {

	zval *_0$$3;
	zval *templateAfter;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &templateAfter);



	if (Z_TYPE_P(templateAfter) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0$$3);
		zephir_create_array(_0$$3, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_0$$3, templateAfter);
		zephir_update_property_this(getThis(), SL("_templatesAfter"), _0$$3 TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_templatesAfter"), templateAfter TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Resets any template before layouts
 */
PHP_METHOD(Phalcon_Mvc_View, cleanTemplateAfter) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(getThis(), SL("_templatesAfter"), _0 TSRMLS_CC);
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
PHP_METHOD(Phalcon_Mvc_View, setVars) {

	zend_bool merge;
	zval *params_param = NULL, *merge_param = NULL, *_0$$3, *_1$$3;
	zval *params = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &params_param, &merge_param);

	params = params_param;
	if (!merge_param) {
		merge = 1;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (merge) {
		ZEPHIR_INIT_VAR(_0$$3);
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_viewParams"), PH_NOISY_CC);
		zephir_fast_array_merge(_0$$3, &(_1$$3), &(params) TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_viewParams"), _0$$3 TSRMLS_CC);
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
PHP_METHOD(Phalcon_Mvc_View, setVar) {

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
PHP_METHOD(Phalcon_Mvc_View, getVar) {

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
	if (!(zephir_array_isset_fetch(&value, _0, key, 1 TSRMLS_CC))) {
		RETURN_MM_NULL();
	}
	RETURN_CTOR(value);

}

/**
 * Returns parameters to views
 */
PHP_METHOD(Phalcon_Mvc_View, getParamsToView) {

	

	RETURN_MEMBER(getThis(), "_viewParams");

}

/**
 * Gets the name of the controller rendered
 */
PHP_METHOD(Phalcon_Mvc_View, getControllerName) {

	

	RETURN_MEMBER(getThis(), "_controllerName");

}

/**
 * Gets the name of the action rendered
 */
PHP_METHOD(Phalcon_Mvc_View, getActionName) {

	

	RETURN_MEMBER(getThis(), "_actionName");

}

/**
 * Gets extra parameters of the action rendered
 *
 * @deprecated Will be removed in 4.0.0
 */
PHP_METHOD(Phalcon_Mvc_View, getParams) {

	

	RETURN_MEMBER(getThis(), "_params");

}

/**
 * Starts rendering process enabling the output buffering
 */
PHP_METHOD(Phalcon_Mvc_View, start) {

	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 140);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("_content"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Loads registered template engines, if none is registered it will use Phalcon\Mvc\View\Engine\Php
 */
PHP_METHOD(Phalcon_Mvc_View, _loadTemplateEngines) {

	HashTable *_3$$5;
	HashPosition _2$$5;
	zval *engines = NULL, *dependencyInjector = NULL, *registeredEngines = NULL, *arguments = NULL, *engineService = NULL, *extension = NULL, *_0$$3, *_1$$4, **_4$$5, *_5$$9 = NULL, *_6$$12 = NULL, *_7$$12 = NULL, *_9$$11 = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(engines);
	zephir_read_property_this(&engines, this_ptr, SL("_engines"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(engines)) {
		_0$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(dependencyInjector, _0$$3);
		ZEPHIR_INIT_NVAR(engines);
		array_init(engines);
		ZEPHIR_OBS_VAR(registeredEngines);
		zephir_read_property_this(&registeredEngines, this_ptr, SL("_registeredEngines"), PH_NOISY_CC);
		if (Z_TYPE_P(registeredEngines) != IS_ARRAY) {
			ZEPHIR_INIT_VAR(_1$$4);
			object_init_ex(_1$$4, phalcon_mvc_view_engine_php_ce);
			ZEPHIR_CALL_METHOD(NULL, _1$$4, "__construct", NULL, 401, this_ptr, dependencyInjector);
			zephir_check_call_status();
			zephir_array_update_string(&engines, SL(".phtml"), &_1$$4, PH_COPY | PH_SEPARATE);
		} else {
			if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "A dependency injector container is required to obtain the application services", "phalcon/mvc/view.zep", 542);
				return;
			}
			ZEPHIR_INIT_VAR(arguments);
			zephir_create_array(arguments, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(arguments, this_ptr);
			zephir_array_fast_append(arguments, dependencyInjector);
			zephir_is_iterable(registeredEngines, &_3$$5, &_2$$5, 0, 0, "phalcon/mvc/view.zep", 571);
			for (
			  ; zend_hash_get_current_data_ex(_3$$5, (void**) &_4$$5, &_2$$5) == SUCCESS
			  ; zend_hash_move_forward_ex(_3$$5, &_2$$5)
			) {
				ZEPHIR_GET_HMKEY(extension, _3$$5, _2$$5);
				ZEPHIR_GET_HVALUE(engineService, _4$$5);
				if (Z_TYPE_P(engineService) == IS_OBJECT) {
					if (zephir_instance_of_ev(engineService, zend_ce_closure TSRMLS_CC)) {
						ZEPHIR_INIT_NVAR(_5$$9);
						ZEPHIR_CALL_USER_FUNC_ARRAY(_5$$9, engineService, arguments);
						zephir_check_call_status();
						zephir_array_update_zval(&engines, extension, &_5$$9, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_update_zval(&engines, extension, &engineService, PH_COPY | PH_SEPARATE);
					}
				} else {
					if (Z_TYPE_P(engineService) != IS_STRING) {
						ZEPHIR_INIT_NVAR(_6$$12);
						object_init_ex(_6$$12, phalcon_mvc_view_exception_ce);
						ZEPHIR_INIT_LNVAR(_7$$12);
						ZEPHIR_CONCAT_SV(_7$$12, "Invalid template engine registration for extension: ", extension);
						ZEPHIR_CALL_METHOD(NULL, _6$$12, "__construct", &_8, 9, _7$$12);
						zephir_check_call_status();
						zephir_throw_exception_debug(_6$$12, "phalcon/mvc/view.zep", 565 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(&_9$$11, dependencyInjector, "getshared", &_10, 0, engineService, arguments);
					zephir_check_call_status();
					zephir_array_update_zval(&engines, extension, &_9$$11, PH_COPY | PH_SEPARATE);
				}
			}
		}
		zephir_update_property_this(getThis(), SL("_engines"), engines TSRMLS_CC);
	}
	RETURN_CCTOR(engines);

}

/**
 * Checks whether view exists on registered extensions and render it
 *
 * @param array engines
 * @param string viewPath
 * @param boolean silence
 * @param boolean mustClean
 * @param \Phalcon\Cache\BackendInterface $cache
 */
PHP_METHOD(Phalcon_Mvc_View, _engineRender) {

	zval *_17$$16 = NULL;
	HashTable *_3, *_15$$3;
	HashPosition _2, _14$$3;
	zephir_fcall_cache_entry *_6 = NULL, *_10 = NULL, *_11 = NULL, *_13 = NULL, *_20 = NULL, *_23 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, renderLevel = 0, cacheLevel = 0;
	zend_bool silence, mustClean, notExists = 0;
	zval *viewPath = NULL, *_26$$21;
	zval *engines, *viewPath_param = NULL, *silence_param = NULL, *mustClean_param = NULL, *cache = NULL, *key = NULL, *lifetime = NULL, *viewsDir = NULL, *basePath = NULL, *viewsDirPath = NULL, *viewOptions = NULL, *cacheOptions = NULL, *cachedView = NULL, *viewParams = NULL, *eventsManager = NULL, *extension = NULL, *engine = NULL, *viewEnginePath = NULL, *viewEnginePaths = NULL, *_0, *_1 = NULL, **_4, *_5$$3 = NULL, **_16$$3, *_7$$6 = NULL, *_8$$6 = NULL, *_9$$7 = NULL, *_12$$7 = NULL, *_18$$16 = NULL, *_19$$16 = NULL, *_21$$15 = NULL, *_22$$18 = NULL, *_24$$20, *_25$$21;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &engines, &viewPath_param, &silence_param, &mustClean_param, &cache);

	zephir_get_strval(viewPath, viewPath_param);
	silence = zephir_get_boolval(silence_param);
	mustClean = zephir_get_boolval(mustClean_param);
	if (!cache) {
		cache = ZEPHIR_GLOBAL(global_null);
	}


	notExists = 1;
	ZEPHIR_OBS_VAR(basePath);
	zephir_read_property_this(&basePath, this_ptr, SL("_basePath"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(viewParams);
	zephir_read_property_this(&viewParams, this_ptr, SL("_viewParams"), PH_NOISY_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(eventsManager, _0);
	ZEPHIR_INIT_VAR(viewEnginePaths);
	array_init(viewEnginePaths);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getviewsdirs", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(_1, &_3, &_2, 0, 0, "phalcon/mvc/view.zep", 698);
	for (
	  ; zend_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zend_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(viewsDir, _4);
		ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "_isabsolutepath", &_6, 402, viewPath);
		zephir_check_call_status();
		if (!(zephir_is_true(_5$$3))) {
			ZEPHIR_INIT_NVAR(viewsDirPath);
			ZEPHIR_CONCAT_VVV(viewsDirPath, basePath, viewsDir, viewPath);
		} else {
			ZEPHIR_CPY_WRT(viewsDirPath, viewPath);
		}
		if (Z_TYPE_P(cache) == IS_OBJECT) {
			ZEPHIR_OBS_NVAR(_7$$6);
			zephir_read_property_this(&_7$$6, this_ptr, SL("_renderLevel"), PH_NOISY_CC);
			renderLevel = zephir_get_intval(_7$$6);
			ZEPHIR_OBS_NVAR(_8$$6);
			zephir_read_property_this(&_8$$6, this_ptr, SL("_cacheLevel"), PH_NOISY_CC);
			cacheLevel = zephir_get_intval(_8$$6);
			if (renderLevel >= cacheLevel) {
				ZEPHIR_CALL_METHOD(&_9$$7, cache, "isstarted", &_10, 0);
				zephir_check_call_status();
				if (!(zephir_is_true(_9$$7))) {
					ZEPHIR_INIT_NVAR(key);
					ZVAL_NULL(key);
					ZEPHIR_INIT_NVAR(lifetime);
					ZVAL_NULL(lifetime);
					ZEPHIR_OBS_NVAR(viewOptions);
					zephir_read_property_this(&viewOptions, this_ptr, SL("_options"), PH_NOISY_CC);
					ZEPHIR_OBS_NVAR(cacheOptions);
					if (zephir_array_isset_string_fetch(&cacheOptions, viewOptions, SS("cache"), 0 TSRMLS_CC)) {
						if (Z_TYPE_P(cacheOptions) == IS_ARRAY) {
							ZEPHIR_OBS_NVAR(key);
							zephir_array_isset_string_fetch(&key, cacheOptions, SS("key"), 0 TSRMLS_CC);
							ZEPHIR_OBS_NVAR(lifetime);
							zephir_array_isset_string_fetch(&lifetime, cacheOptions, SS("lifetime"), 0 TSRMLS_CC);
						}
					}
					if (Z_TYPE_P(key) == IS_NULL) {
						ZEPHIR_INIT_NVAR(key);
						zephir_md5(key, viewPath);
					}
					ZEPHIR_CALL_METHOD(&cachedView, cache, "start", &_11, 0, key, lifetime);
					zephir_check_call_status();
					if (Z_TYPE_P(cachedView) != IS_NULL) {
						zephir_update_property_this(getThis(), SL("_content"), cachedView TSRMLS_CC);
						RETURN_MM_NULL();
					}
				}
				ZEPHIR_CALL_METHOD(&_12$$7, cache, "isfresh", &_13, 0);
				zephir_check_call_status();
				if (!(zephir_is_true(_12$$7))) {
					RETURN_MM_NULL();
				}
			}
		}
		zephir_is_iterable(engines, &_15$$3, &_14$$3, 0, 0, "phalcon/mvc/view.zep", 696);
		for (
		  ; zend_hash_get_current_data_ex(_15$$3, (void**) &_16$$3, &_14$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_15$$3, &_14$$3)
		) {
			ZEPHIR_GET_HMKEY(extension, _15$$3, _14$$3);
			ZEPHIR_GET_HVALUE(engine, _16$$3);
			ZEPHIR_INIT_NVAR(viewEnginePath);
			ZEPHIR_CONCAT_VV(viewEnginePath, viewsDirPath, extension);
			if ((zephir_file_exists(viewEnginePath TSRMLS_CC) == SUCCESS)) {
				if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(_17$$16);
					zephir_create_array(_17$$16, 1, 0 TSRMLS_CC);
					zephir_array_fast_append(_17$$16, viewEnginePath);
					zephir_update_property_this(getThis(), SL("_activeRenderPaths"), _17$$16 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_19$$16);
					ZVAL_STRING(_19$$16, "view:beforeRenderView", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_18$$16, eventsManager, "fire", &_20, 0, _19$$16, this_ptr, viewEnginePath);
					zephir_check_temp_parameter(_19$$16);
					zephir_check_call_status();
					if (ZEPHIR_IS_FALSE_IDENTICAL(_18$$16)) {
						continue;
					}
				}
				ZEPHIR_INIT_NVAR(_21$$15);
				if (mustClean) {
					ZVAL_BOOL(_21$$15, 1);
				} else {
					ZVAL_BOOL(_21$$15, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, engine, "render", NULL, 0, viewEnginePath, viewParams, _21$$15);
				zephir_check_call_status();
				notExists = 0;
				if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(_22$$18);
					ZVAL_STRING(_22$$18, "view:afterRenderView", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", &_23, 0, _22$$18, this_ptr);
					zephir_check_temp_parameter(_22$$18);
					zephir_check_call_status();
				}
				break;
			}
			zephir_array_append(&viewEnginePaths, viewEnginePath, PH_SEPARATE, "phalcon/mvc/view.zep", 694);
		}
	}
	if (notExists == 1) {
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			zephir_update_property_this(getThis(), SL("_activeRenderPaths"), viewEnginePaths TSRMLS_CC);
			ZEPHIR_INIT_VAR(_24$$20);
			ZVAL_STRING(_24$$20, "view:notFoundView", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _24$$20, this_ptr, viewEnginePath);
			zephir_check_temp_parameter(_24$$20);
			zephir_check_call_status();
		}
		if (!(silence)) {
			ZEPHIR_INIT_VAR(_25$$21);
			object_init_ex(_25$$21, phalcon_mvc_view_exception_ce);
			ZEPHIR_INIT_VAR(_26$$21);
			ZEPHIR_CONCAT_SVS(_26$$21, "View '", viewPath, "' was not found in any of the views directory");
			ZEPHIR_CALL_METHOD(NULL, _25$$21, "__construct", NULL, 9, _26$$21);
			zephir_check_call_status();
			zephir_throw_exception_debug(_25$$21, "phalcon/mvc/view.zep", 708 TSRMLS_CC);
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
	zval *engines = NULL;

	zephir_fetch_params(0, 1, 0, &engines_param);

	engines = engines_param;


	zephir_update_property_this(getThis(), SL("_registeredEngines"), engines TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Checks whether view exists
 */
PHP_METHOD(Phalcon_Mvc_View, exists) {

	HashTable *_2, *_6$$4;
	HashPosition _1, _5$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *view_param = NULL, *basePath = NULL, *viewsDir = NULL, *engines = NULL, *extension = NULL, *_0 = NULL, **_3, *_4$$4 = NULL, **_7$$4, *_8$$5 = NULL;
	zval *view = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &view_param);

	if (UNEXPECTED(Z_TYPE_P(view_param) != IS_STRING && Z_TYPE_P(view_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'view' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(view_param) == IS_STRING)) {
		zephir_get_strval(view, view_param);
	} else {
		ZEPHIR_INIT_VAR(view);
		ZVAL_EMPTY_STRING(view);
	}


	ZEPHIR_OBS_VAR(basePath);
	zephir_read_property_this(&basePath, this_ptr, SL("_basePath"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(engines);
	zephir_read_property_this(&engines, this_ptr, SL("_registeredEngines"), PH_NOISY_CC);
	if (Z_TYPE_P(engines) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(engines);
		zephir_create_array(engines, 1, 0 TSRMLS_CC);
		add_assoc_stringl_ex(engines, SS(".phtml"), SL("Phalcon\\Mvc\\View\\Engine\\Php"), 1);
		zephir_update_property_this(getThis(), SL("_registeredEngines"), engines TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getviewsdirs", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalcon/mvc/view.zep", 755);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(viewsDir, _3);
		ZEPHIR_INIT_NVAR(_4$$4);
		zephir_is_iterable(engines, &_6$$4, &_5$$4, 0, 0, "phalcon/mvc/view.zep", 753);
		for (
		  ; zend_hash_get_current_data_ex(_6$$4, (void**) &_7$$4, &_5$$4) == SUCCESS
		  ; zend_hash_move_forward_ex(_6$$4, &_5$$4)
		) {
			ZEPHIR_GET_HMKEY(extension, _6$$4, _5$$4);
			ZEPHIR_GET_HVALUE(_4$$4, _7$$4);
			ZEPHIR_INIT_LNVAR(_8$$5);
			ZEPHIR_CONCAT_VVVV(_8$$5, basePath, viewsDir, view, extension);
			if ((zephir_file_exists(_8$$5 TSRMLS_CC) == SUCCESS)) {
				RETURN_MM_BOOL(1);
			}
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Executes render process from dispatching data
 *
 *<code>
 * // Shows recent posts view (app/views/posts/recent.phtml)
 * $view->start()->render("posts", "recent")->finish();
 *</code>
 *
 * @param string controllerName
 * @param string actionName
 * @param array params
 */
PHP_METHOD(Phalcon_Mvc_View, render) {

	HashTable *_15$$20, *_26$$25;
	HashPosition _14$$20, _25$$25;
	zend_bool silence = 0, mustClean = 0, _36$$29;
	zend_long ZEPHIR_LAST_CALL_STATUS, renderLevel = 0;
	zval *controllerName_param = NULL, *actionName_param = NULL, *params = NULL, *layoutsDir = NULL, *layout = NULL, *pickView = NULL, *layoutName = NULL, *engines = NULL, *renderView = NULL, *pickViewAction = NULL, *eventsManager = NULL, *disabledLevels = NULL, *templatesBefore = NULL, *templatesAfter = NULL, *templateBefore = NULL, *templateAfter = NULL, *cache = NULL, *_0, *_3, *_4, *_5, *_8 = NULL, *_9, *_1$$3 = NULL, *_6$$14 = NULL, *_7$$14, *_10$$18, *_11$$18, *_12$$18, *_13$$20, **_16$$20, *_17$$21 = NULL, *_18$$21 = NULL, *_19$$21 = NULL, *_20$$23, *_21$$23, *_22$$23, *_23$$23, *_24$$25, **_27$$25, *_28$$26 = NULL, *_29$$26 = NULL, *_30$$26 = NULL, *_31$$28, *_32$$28, *_33$$28, *_34$$16, *_35$$29 = NULL, *_37$$29 = NULL, *_38$$32;
	zval *controllerName = NULL, *actionName = NULL, *_2$$8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &controllerName_param, &actionName_param, &params);

	if (UNEXPECTED(Z_TYPE_P(controllerName_param) != IS_STRING && Z_TYPE_P(controllerName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'controllerName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(controllerName_param) == IS_STRING)) {
		zephir_get_strval(controllerName, controllerName_param);
	} else {
		ZEPHIR_INIT_VAR(controllerName);
		ZVAL_EMPTY_STRING(controllerName);
	}
	if (UNEXPECTED(Z_TYPE_P(actionName_param) != IS_STRING && Z_TYPE_P(actionName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'actionName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(actionName_param) == IS_STRING)) {
		zephir_get_strval(actionName, actionName_param);
	} else {
		ZEPHIR_INIT_VAR(actionName);
		ZVAL_EMPTY_STRING(actionName);
	}
	if (!params) {
		params = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 0);
	zephir_update_property_this(getThis(), SL("_currentRenderLevel"), _0 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_disabled"), PH_NOISY_CC);
	if (!ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
		ZEPHIR_CALL_FUNCTION(&_1$$3, "ob_get_contents", NULL, 141);
		zephir_check_call_status();
		zephir_update_property_this(getThis(), SL("_content"), _1$$3 TSRMLS_CC);
		RETURN_MM_BOOL(0);
	}
	zephir_update_property_this(getThis(), SL("_controllerName"), controllerName TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_actionName"), actionName TSRMLS_CC);
	if (Z_TYPE_P(params) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setvars", NULL, 0, params);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(layoutsDir);
	zephir_read_property_this(&layoutsDir, this_ptr, SL("_layoutsDir"), PH_NOISY_CC);
	if (!(zephir_is_true(layoutsDir))) {
		ZEPHIR_INIT_NVAR(layoutsDir);
		ZVAL_STRING(layoutsDir, "layouts/", 1);
	}
	ZEPHIR_OBS_VAR(layout);
	zephir_read_property_this(&layout, this_ptr, SL("_layout"), PH_NOISY_CC);
	if (zephir_is_true(layout)) {
		ZEPHIR_CPY_WRT(layoutName, layout);
	} else {
		ZEPHIR_CPY_WRT(layoutName, controllerName);
	}
	ZEPHIR_CALL_METHOD(&engines, this_ptr, "_loadtemplateengines", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(pickView);
	zephir_read_property_this(&pickView, this_ptr, SL("_pickView"), PH_NOISY_CC);
	if (Z_TYPE_P(pickView) == IS_NULL) {
		ZEPHIR_INIT_VAR(_2$$8);
		ZEPHIR_CONCAT_VSV(_2$$8, controllerName, "/", actionName);
		ZEPHIR_CPY_WRT(renderView, _2$$8);
	} else {
		ZEPHIR_OBS_NVAR(renderView);
		zephir_array_fetch_long(&renderView, pickView, 0, PH_NOISY, "phalcon/mvc/view.zep", 831 TSRMLS_CC);
		if (Z_TYPE_P(layoutName) == IS_NULL) {
			ZEPHIR_OBS_VAR(pickViewAction);
			if (zephir_array_isset_long_fetch(&pickViewAction, pickView, 1, 0 TSRMLS_CC)) {
				ZEPHIR_CPY_WRT(layoutName, pickViewAction);
			}
		}
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_cacheLevel"), PH_NOISY_CC);
	if (zephir_is_true(_3)) {
		ZEPHIR_CALL_METHOD(&cache, this_ptr, "getcache", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(cache);
		ZVAL_NULL(cache);
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(eventsManager, _4);
	ZEPHIR_INIT_VAR(_5);
	zephir_create_symbol_table(TSRMLS_C);
	
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_7$$14);
		ZVAL_STRING(_7$$14, "view:beforeRender", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_6$$14, eventsManager, "fire", NULL, 0, _7$$14, this_ptr);
		zephir_check_temp_parameter(_7$$14);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_6$$14)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_CALL_FUNCTION(&_8, "ob_get_contents", NULL, 141);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("_content"), _8 TSRMLS_CC);
	mustClean = 1;
	silence = 1;
	ZEPHIR_OBS_VAR(disabledLevels);
	zephir_read_property_this(&disabledLevels, this_ptr, SL("_disabledLevels"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_9);
	zephir_read_property_this(&_9, this_ptr, SL("_renderLevel"), PH_NOISY_CC);
	renderLevel = zephir_get_intval(_9);
	if (renderLevel) {
		if (renderLevel >= 1) {
			if (!(zephir_array_isset_long(disabledLevels, 1))) {
				ZEPHIR_INIT_ZVAL_NREF(_10$$18);
				ZVAL_LONG(_10$$18, 1);
				zephir_update_property_this(getThis(), SL("_currentRenderLevel"), _10$$18 TSRMLS_CC);
				ZEPHIR_INIT_VAR(_11$$18);
				if (silence) {
					ZVAL_BOOL(_11$$18, 1);
				} else {
					ZVAL_BOOL(_11$$18, 0);
				}
				ZEPHIR_INIT_VAR(_12$$18);
				if (mustClean) {
					ZVAL_BOOL(_12$$18, 1);
				} else {
					ZVAL_BOOL(_12$$18, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_enginerender", NULL, 0, engines, renderView, _11$$18, _12$$18, cache);
				zephir_check_call_status();
			}
		}
		if (renderLevel >= 2) {
			if (!(zephir_array_isset_long(disabledLevels, 2))) {
				ZEPHIR_INIT_ZVAL_NREF(_13$$20);
				ZVAL_LONG(_13$$20, 2);
				zephir_update_property_this(getThis(), SL("_currentRenderLevel"), _13$$20 TSRMLS_CC);
				ZEPHIR_OBS_VAR(templatesBefore);
				zephir_read_property_this(&templatesBefore, this_ptr, SL("_templatesBefore"), PH_NOISY_CC);
				silence = 0;
				zephir_is_iterable(templatesBefore, &_15$$20, &_14$$20, 0, 0, "phalcon/mvc/view.zep", 906);
				for (
				  ; zend_hash_get_current_data_ex(_15$$20, (void**) &_16$$20, &_14$$20) == SUCCESS
				  ; zend_hash_move_forward_ex(_15$$20, &_14$$20)
				) {
					ZEPHIR_GET_HVALUE(templateBefore, _16$$20);
					ZEPHIR_INIT_LNVAR(_17$$21);
					ZEPHIR_CONCAT_VV(_17$$21, layoutsDir, templateBefore);
					ZEPHIR_INIT_NVAR(_18$$21);
					if (silence) {
						ZVAL_BOOL(_18$$21, 1);
					} else {
						ZVAL_BOOL(_18$$21, 0);
					}
					ZEPHIR_INIT_NVAR(_19$$21);
					if (mustClean) {
						ZVAL_BOOL(_19$$21, 1);
					} else {
						ZVAL_BOOL(_19$$21, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "_enginerender", NULL, 0, engines, _17$$21, _18$$21, _19$$21, cache);
					zephir_check_call_status();
				}
				silence = 1;
			}
		}
		if (renderLevel >= 3) {
			if (!(zephir_array_isset_long(disabledLevels, 3))) {
				ZEPHIR_INIT_ZVAL_NREF(_20$$23);
				ZVAL_LONG(_20$$23, 3);
				zephir_update_property_this(getThis(), SL("_currentRenderLevel"), _20$$23 TSRMLS_CC);
				ZEPHIR_INIT_VAR(_21$$23);
				ZEPHIR_CONCAT_VV(_21$$23, layoutsDir, layoutName);
				ZEPHIR_INIT_VAR(_22$$23);
				if (silence) {
					ZVAL_BOOL(_22$$23, 1);
				} else {
					ZVAL_BOOL(_22$$23, 0);
				}
				ZEPHIR_INIT_VAR(_23$$23);
				if (mustClean) {
					ZVAL_BOOL(_23$$23, 1);
				} else {
					ZVAL_BOOL(_23$$23, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_enginerender", NULL, 0, engines, _21$$23, _22$$23, _23$$23, cache);
				zephir_check_call_status();
			}
		}
		if (renderLevel >= 4) {
			if (!(zephir_array_isset_long(disabledLevels, 4))) {
				ZEPHIR_INIT_ZVAL_NREF(_24$$25);
				ZVAL_LONG(_24$$25, 4);
				zephir_update_property_this(getThis(), SL("_currentRenderLevel"), _24$$25 TSRMLS_CC);
				ZEPHIR_OBS_VAR(templatesAfter);
				zephir_read_property_this(&templatesAfter, this_ptr, SL("_templatesAfter"), PH_NOISY_CC);
				silence = 0;
				zephir_is_iterable(templatesAfter, &_26$$25, &_25$$25, 0, 0, "phalcon/mvc/view.zep", 933);
				for (
				  ; zend_hash_get_current_data_ex(_26$$25, (void**) &_27$$25, &_25$$25) == SUCCESS
				  ; zend_hash_move_forward_ex(_26$$25, &_25$$25)
				) {
					ZEPHIR_GET_HVALUE(templateAfter, _27$$25);
					ZEPHIR_INIT_LNVAR(_28$$26);
					ZEPHIR_CONCAT_VV(_28$$26, layoutsDir, templateAfter);
					ZEPHIR_INIT_NVAR(_29$$26);
					if (silence) {
						ZVAL_BOOL(_29$$26, 1);
					} else {
						ZVAL_BOOL(_29$$26, 0);
					}
					ZEPHIR_INIT_NVAR(_30$$26);
					if (mustClean) {
						ZVAL_BOOL(_30$$26, 1);
					} else {
						ZVAL_BOOL(_30$$26, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "_enginerender", NULL, 0, engines, _28$$26, _29$$26, _30$$26, cache);
					zephir_check_call_status();
				}
				silence = 1;
			}
		}
		if (renderLevel >= 5) {
			if (!(zephir_array_isset_long(disabledLevels, 5))) {
				ZEPHIR_INIT_ZVAL_NREF(_31$$28);
				ZVAL_LONG(_31$$28, 5);
				zephir_update_property_this(getThis(), SL("_currentRenderLevel"), _31$$28 TSRMLS_CC);
				_31$$28 = zephir_fetch_nproperty_this(this_ptr, SL("_mainView"), PH_NOISY_CC);
				ZEPHIR_INIT_VAR(_32$$28);
				if (silence) {
					ZVAL_BOOL(_32$$28, 1);
				} else {
					ZVAL_BOOL(_32$$28, 0);
				}
				ZEPHIR_INIT_VAR(_33$$28);
				if (mustClean) {
					ZVAL_BOOL(_33$$28, 1);
				} else {
					ZVAL_BOOL(_33$$28, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_enginerender", NULL, 0, engines, _31$$28, _32$$28, _33$$28, cache);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_ZVAL_NREF(_34$$16);
		ZVAL_LONG(_34$$16, 0);
		zephir_update_property_this(getThis(), SL("_currentRenderLevel"), _34$$16 TSRMLS_CC);
		if (Z_TYPE_P(cache) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(&_35$$29, cache, "isstarted", NULL, 0);
			zephir_check_call_status();
			_36$$29 = zephir_is_true(_35$$29);
			if (_36$$29) {
				ZEPHIR_CALL_METHOD(&_37$$29, cache, "isfresh", NULL, 0);
				zephir_check_call_status();
				_36$$29 = zephir_is_true(_37$$29);
			}
			if (_36$$29) {
				ZEPHIR_CALL_METHOD(NULL, cache, "save", NULL, 0);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(NULL, cache, "stop", NULL, 0);
				zephir_check_call_status();
			}
		}
	}
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_38$$32);
		ZVAL_STRING(_38$$32, "view:afterRender", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _38$$32, this_ptr);
		zephir_check_temp_parameter(_38$$32);
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

	zval *renderView, *pickView = NULL, *layout = NULL, *parts = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &renderView);



	if (Z_TYPE_P(renderView) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(pickView, renderView);
	} else {
		ZEPHIR_INIT_VAR(layout);
		ZVAL_NULL(layout);
		if (zephir_memnstr_str(renderView, SL("/"), "phalcon/mvc/view.zep", 998)) {
			ZEPHIR_INIT_VAR(parts);
			zephir_fast_explode_str(parts, SL("/"), renderView, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_NVAR(layout);
			zephir_array_fetch_long(&layout, parts, 0, PH_NOISY, "phalcon/mvc/view.zep", 999 TSRMLS_CC);
		}
		ZEPHIR_INIT_NVAR(pickView);
		zephir_create_array(pickView, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(pickView, renderView);
		if (Z_TYPE_P(layout) != IS_NULL) {
			zephir_array_append(&pickView, layout, PH_SEPARATE, "phalcon/mvc/view.zep", 1004);
		}
	}
	zephir_update_property_this(getThis(), SL("_pickView"), pickView TSRMLS_CC);
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
	zval *partialPath_param = NULL, *params = NULL;
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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "partial", NULL, 0, partialPath, params);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", NULL, 307);
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
	zval *partialPath_param = NULL, *params = NULL, *viewParams = NULL, *_2 = NULL, *_3, *_4, *_5, *_6, *_0$$3, *_1$$3;
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


	if (Z_TYPE_P(params) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(viewParams);
		zephir_read_property_this(&viewParams, this_ptr, SL("_viewParams"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_0$$3);
		zephir_fast_array_merge(_0$$3, &(viewParams), &(params) TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_viewParams"), _0$$3 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_1$$3);
		zephir_create_symbol_table(TSRMLS_C);
		
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "_loadtemplateengines", NULL, 0);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_partialsDir"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_VV(_4, _3, partialPath);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_BOOL(_5, 0);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_BOOL(_6, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_enginerender", NULL, 0, _2, _4, _5, _6);
	zephir_check_call_status();
	if (Z_TYPE_P(params) == IS_ARRAY) {
		zephir_update_property_this(getThis(), SL("_viewParams"), viewParams TSRMLS_CC);
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
 * @param string controllerName
 * @param string actionName
 * @param array params
 * @param mixed configCallback
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View, getRender) {

	zval *_1$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *controllerName_param = NULL, *actionName_param = NULL, *params = NULL, *configCallback = NULL, *view = NULL, *_0$$4;
	zval *controllerName = NULL, *actionName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &controllerName_param, &actionName_param, &params, &configCallback);

	if (UNEXPECTED(Z_TYPE_P(controllerName_param) != IS_STRING && Z_TYPE_P(controllerName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'controllerName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(controllerName_param) == IS_STRING)) {
		zephir_get_strval(controllerName, controllerName_param);
	} else {
		ZEPHIR_INIT_VAR(controllerName);
		ZVAL_EMPTY_STRING(controllerName);
	}
	if (UNEXPECTED(Z_TYPE_P(actionName_param) != IS_STRING && Z_TYPE_P(actionName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'actionName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(actionName_param) == IS_STRING)) {
		zephir_get_strval(actionName, actionName_param);
	} else {
		ZEPHIR_INIT_VAR(actionName);
		ZVAL_EMPTY_STRING(actionName);
	}
	if (!params) {
		params = ZEPHIR_GLOBAL(global_null);
	}
	if (!configCallback) {
		configCallback = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(view);
	if (zephir_clone(view, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(NULL, view, "reset", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(params) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, view, "setvars", NULL, 0, params);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(configCallback) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_0$$4);
		ZEPHIR_INIT_VAR(_1$$4);
		zephir_create_array(_1$$4, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_1$$4, view);
		ZEPHIR_CALL_USER_FUNC_ARRAY(_0$$4, configCallback, _1$$4);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, view, "start", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, view, "render", NULL, 0, controllerName, actionName);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 142);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(view, "getcontent", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Finishes the render process by stopping the output buffering
 */
PHP_METHOD(Phalcon_Mvc_View, finish) {

	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 142);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Create a Phalcon\Cache based on the internal cache options
 */
PHP_METHOD(Phalcon_Mvc_View, _createCache) {

	zval *dependencyInjector = NULL, *cacheService = NULL, *viewCache = NULL, *viewOptions = NULL, *cacheOptions = NULL, *_0, *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(dependencyInjector, _0);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "A dependency injector container is required to obtain the view cache services", "phalcon/mvc/view.zep", 1183);
		return;
	}
	ZEPHIR_INIT_VAR(cacheService);
	ZVAL_STRING(cacheService, "viewCache", 1);
	ZEPHIR_OBS_VAR(viewOptions);
	zephir_read_property_this(&viewOptions, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(cacheOptions);
	if (zephir_array_isset_string_fetch(&cacheOptions, viewOptions, SS("cache"), 0 TSRMLS_CC)) {
		if (zephir_array_isset_string(cacheOptions, SS("service"))) {
			ZEPHIR_OBS_NVAR(cacheService);
			zephir_array_fetch_string(&cacheService, cacheOptions, SL("service"), PH_NOISY, "phalcon/mvc/view.zep", 1192 TSRMLS_CC);
		}
	}
	ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "getshared", NULL, 0, cacheService);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(viewCache, _1);
	if (Z_TYPE_P(viewCache) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "The injected caching service is invalid", "phalcon/mvc/view.zep", 1201);
		return;
	}
	RETURN_CCTOR(viewCache);

}

/**
 * Check if the component is currently caching the output content
 */
PHP_METHOD(Phalcon_Mvc_View, isCaching) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_cacheLevel"), PH_NOISY_CC);
	RETURN_BOOL(ZEPHIR_GT_LONG(_0, 0));

}

/**
 * Returns the cache instance used to cache
 */
PHP_METHOD(Phalcon_Mvc_View, getCache) {

	zend_bool _1;
	zval *_0, *_2, *_3$$3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_cache"), PH_NOISY_CC);
	_1 = !zephir_is_true(_0);
	if (!(_1)) {
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
PHP_METHOD(Phalcon_Mvc_View, cache) {

	HashTable *_1$$3;
	HashPosition _0$$3;
	zval *options = NULL, *viewOptions = NULL, *cacheOptions = NULL, *key = NULL, *value = NULL, *cacheLevel = NULL, **_2$$3, *_3$$8, *_4$$10, *_5$$11;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options) {
		options = ZEPHIR_GLOBAL(global_true);
	}


	if (Z_TYPE_P(options) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(viewOptions);
		zephir_read_property_this(&viewOptions, this_ptr, SL("_options"), PH_NOISY_CC);
		if (Z_TYPE_P(viewOptions) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(viewOptions);
			array_init(viewOptions);
		}
		ZEPHIR_OBS_VAR(cacheOptions);
		if (!(zephir_array_isset_string_fetch(&cacheOptions, viewOptions, SS("cache"), 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(cacheOptions);
			array_init(cacheOptions);
		}
		zephir_is_iterable(options, &_1$$3, &_0$$3, 0, 0, "phalcon/mvc/view.zep", 1264);
		for (
		  ; zend_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_1$$3, &_0$$3)
		) {
			ZEPHIR_GET_HMKEY(key, _1$$3, _0$$3);
			ZEPHIR_GET_HVALUE(value, _2$$3);
			zephir_array_update_zval(&cacheOptions, key, &value, PH_COPY | PH_SEPARATE);
		}
		if (zephir_array_isset_string_fetch(&cacheLevel, cacheOptions, SS("level"), 1 TSRMLS_CC)) {
			zephir_update_property_this(getThis(), SL("_cacheLevel"), cacheLevel TSRMLS_CC);
		} else {
			ZEPHIR_INIT_ZVAL_NREF(_3$$8);
			ZVAL_LONG(_3$$8, 5);
			zephir_update_property_this(getThis(), SL("_cacheLevel"), _3$$8 TSRMLS_CC);
		}
		zephir_array_update_string(&viewOptions, SL("cache"), &cacheOptions, PH_COPY | PH_SEPARATE);
		zephir_update_property_this(getThis(), SL("_options"), viewOptions TSRMLS_CC);
	} else {
		if (zephir_is_true(options)) {
			ZEPHIR_INIT_ZVAL_NREF(_4$$10);
			ZVAL_LONG(_4$$10, 5);
			zephir_update_property_this(getThis(), SL("_cacheLevel"), _4$$10 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_ZVAL_NREF(_5$$11);
			ZVAL_LONG(_5$$11, 0);
			zephir_update_property_this(getThis(), SL("_cacheLevel"), _5$$11 TSRMLS_CC);
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
	zval *content = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

	zephir_get_strval(content, content_param);


	zephir_update_property_this(getThis(), SL("_content"), content TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns cached output from another view stage
 */
PHP_METHOD(Phalcon_Mvc_View, getContent) {

	

	RETURN_MEMBER(getThis(), "_content");

}

/**
 * Returns the path (or paths) of the views that are currently rendered
 */
PHP_METHOD(Phalcon_Mvc_View, getActiveRenderPath) {

	zval *activeRenderPath = NULL, *_0 = NULL, *_1$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS, viewsDirsCount = 0;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getviewsdirs", NULL, 0);
	zephir_check_call_status();
	viewsDirsCount = zephir_fast_count_int(_0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(activeRenderPath);
	zephir_read_property_this(&activeRenderPath, this_ptr, SL("_activeRenderPaths"), PH_NOISY_CC);
	if (viewsDirsCount == 1) {
		if (Z_TYPE_P(activeRenderPath) == IS_ARRAY) {
			if (zephir_fast_count_int(activeRenderPath TSRMLS_CC)) {
				zephir_array_fetch_long(&_1$$5, activeRenderPath, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/view.zep", 1322 TSRMLS_CC);
				ZEPHIR_CPY_WRT(activeRenderPath, _1$$5);
			}
		}
	}
	if (Z_TYPE_P(activeRenderPath) == IS_NULL) {
		ZEPHIR_INIT_NVAR(activeRenderPath);
		ZVAL_STRING(activeRenderPath, "", 1);
	}
	RETURN_CCTOR(activeRenderPath);

}

/**
 * Disables the auto-rendering process
 */
PHP_METHOD(Phalcon_Mvc_View, disable) {

	

	if (1) {
		zephir_update_property_this(getThis(), SL("_disabled"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_disabled"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THISW();

}

/**
 * Enables the auto-rendering process
 */
PHP_METHOD(Phalcon_Mvc_View, enable) {

	

	if (0) {
		zephir_update_property_this(getThis(), SL("_disabled"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_disabled"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THISW();

}

/**
 * Resets the view component to its factory default values
 */
PHP_METHOD(Phalcon_Mvc_View, reset) {

	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	if (0) {
		zephir_update_property_this(getThis(), SL("_disabled"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_disabled"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	if (0) {
		zephir_update_property_this(getThis(), SL("_engines"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_engines"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	zephir_update_property_this(getThis(), SL("_cache"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 5);
	zephir_update_property_this(getThis(), SL("_renderLevel"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 0);
	zephir_update_property_this(getThis(), SL("_cacheLevel"), _0 TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_content"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(getThis(), SL("_templatesBefore"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	array_init(_2);
	zephir_update_property_this(getThis(), SL("_templatesAfter"), _2 TSRMLS_CC);
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
PHP_METHOD(Phalcon_Mvc_View, __get) {

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
 * Whether automatic rendering is enabled
 */
PHP_METHOD(Phalcon_Mvc_View, isDisabled) {

	

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

	zval *key_param = NULL, *_0;
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
	RETURN_MM_BOOL(zephir_array_isset(_0, key));

}

/**
 * Gets views directories
 */
PHP_METHOD(Phalcon_Mvc_View, getViewsDirs) {

	zval *_0, *_1$$3;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_viewsDirs"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_STRING) {
		zephir_create_array(return_value, 1, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(_1$$3);
		zephir_read_property_this(&_1$$3, this_ptr, SL("_viewsDirs"), PH_NOISY_CC);
		zephir_array_fast_append(return_value, _1$$3);
		RETURN_MM();
	}
	RETURN_MM_MEMBER(getThis(), "_viewsDirs");

}

zend_object_value zephir_init_properties_Phalcon_Mvc_View(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_2, *_4, *_6, *_1$$3, *_3$$4, *_5$$5, *_7$$6;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_templatesAfter"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(getThis(), SL("_templatesAfter"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_templatesBefore"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(getThis(), SL("_templatesBefore"), _3$$4 TSRMLS_CC);
		}
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_viewsDirs"), PH_NOISY_CC);
		if (Z_TYPE_P(_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(_5$$5);
			array_init(_5$$5);
			zephir_update_property_this(getThis(), SL("_viewsDirs"), _5$$5 TSRMLS_CC);
		}
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_viewParams"), PH_NOISY_CC);
		if (Z_TYPE_P(_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(_7$$6);
			array_init(_7$$6);
			zephir_update_property_this(getThis(), SL("_viewParams"), _7$$6 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

