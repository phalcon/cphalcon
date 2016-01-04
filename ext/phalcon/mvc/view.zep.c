
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
#include "kernel/hash.h"
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
 * //Setting views directory
 * $view = new \Phalcon\Mvc\View();
 * $view->setViewsDir('app/views/');
 *
 * $view->start();
 * //Shows recent posts view (app/views/posts/recent.phtml)
 * $view->render('posts', 'recent');
 * $view->finish();
 *
 * //Printing views output
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

	zend_declare_property_null(phalcon_mvc_view_ce, SL("_activeRenderPath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_mvc_view_ce, SL("_disabled"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

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

	

	RETURN_MEMBER(this_ptr, "_renderLevel");

}

PHP_METHOD(Phalcon_Mvc_View, getCurrentRenderLevel) {

	

	RETURN_MEMBER(this_ptr, "_currentRenderLevel");

}

/**
 */
PHP_METHOD(Phalcon_Mvc_View, getRegisteredEngines) {

	

	RETURN_MEMBER(this_ptr, "_registeredEngines");

}

/**
 * Phalcon\Mvc\View constructor
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Mvc_View, __construct) {

	zval *options = NULL;

	zephir_fetch_params(0, 0, 1, &options);

	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(options) == IS_ARRAY) {
		zephir_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);
	}

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
		zephir_update_property_this(this_ptr, SL("_viewsDirs"), viewsDir TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(newViewsDir);
		array_init(newViewsDir);
		zephir_is_iterable(viewsDir, &_5$$6, &_4$$6, 0, 0, "phalcon/mvc/view.zep", 206);
		for (
		  ; zephir_hash_get_current_data_ex(_5$$6, (void**) &_6$$6, &_4$$6) == SUCCESS
		  ; zephir_hash_move_forward_ex(_5$$6, &_4$$6)
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
		zephir_update_property_this(this_ptr, SL("_viewsDirs"), newViewsDir TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Gets views directory
 */
PHP_METHOD(Phalcon_Mvc_View, getViewsDir) {

	

	RETURN_MEMBER(this_ptr, "_viewsDirs");

}

/**
 * Sets the layouts sub-directory. Must be a directory under the views directory.
 * Depending of your platform, always add a trailing slash or backslash
 *
 *<code>
 * $view->setLayoutsDir('../common/layouts/');
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_View, setLayoutsDir) {

	zval *layoutsDir_param = NULL;
	zval *layoutsDir = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &layoutsDir_param);

	zephir_get_strval(layoutsDir, layoutsDir_param);


	zephir_update_property_this(this_ptr, SL("_layoutsDir"), layoutsDir TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Gets the current layouts sub-directory
 */
PHP_METHOD(Phalcon_Mvc_View, getLayoutsDir) {

	

	RETURN_MEMBER(this_ptr, "_layoutsDir");

}

/**
 * Sets a partials sub-directory. Must be a directory under the views directory.
 * Depending of your platform, always add a trailing slash or backslash
 *
 *<code>
 * $view->setPartialsDir('../common/partials/');
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_View, setPartialsDir) {

	zval *partialsDir_param = NULL;
	zval *partialsDir = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &partialsDir_param);

	zephir_get_strval(partialsDir, partialsDir_param);


	zephir_update_property_this(this_ptr, SL("_partialsDir"), partialsDir TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Gets the current partials sub-directory
 */
PHP_METHOD(Phalcon_Mvc_View, getPartialsDir) {

	

	RETURN_MEMBER(this_ptr, "_partialsDir");

}

/**
 * Sets base path. Depending of your platform, always add a trailing slash or backslash
 *
 * <code>
 * 	$view->setBasePath(__DIR__ . '/');
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_View, setBasePath) {

	zval *basePath_param = NULL;
	zval *basePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &basePath_param);

	zephir_get_strval(basePath, basePath_param);


	zephir_update_property_this(this_ptr, SL("_basePath"), basePath TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Gets base path
 */
PHP_METHOD(Phalcon_Mvc_View, getBasePath) {

	

	RETURN_MEMBER(this_ptr, "_basePath");

}

/**
 * Sets the render level for the view
 *
 * <code>
 * 	//Render the view related to the controller only
 * 	$this->view->setRenderLevel(View::LEVEL_LAYOUT);
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_View, setRenderLevel) {

	zval *level_param = NULL, *_0;
	int level;

	zephir_fetch_params(0, 1, 0, &level_param);

	level = zephir_get_intval(level_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, level);
	zephir_update_property_this(this_ptr, SL("_renderLevel"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Disables a specific level of rendering
 *
 *<code>
 * //Render all levels except ACTION level
 * $this->view->disableLevel(View::LEVEL_ACTION_VIEW);
 *</code>
 *
 * @param int|array level
 * @return \Phalcon\Mvc\View
 */
PHP_METHOD(Phalcon_Mvc_View, disableLevel) {

	zval *level;

	zephir_fetch_params(0, 1, 0, &level);



	if (Z_TYPE_P(level) == IS_ARRAY) {
		zephir_update_property_this(this_ptr, SL("_disabledLevels"), level TSRMLS_CC);
	} else {
		zephir_update_property_array(this_ptr, SL("_disabledLevels"), level, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	}
	RETURN_THISW();

}

/**
 * Sets default view name. Must be a file without extension in the views directory
 *
 * <code>
 * 	//Renders as main view views-dir/base.phtml
 * 	$this->view->setMainView('base');
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_View, setMainView) {

	zval *viewPath_param = NULL;
	zval *viewPath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &viewPath_param);

	zephir_get_strval(viewPath, viewPath_param);


	zephir_update_property_this(this_ptr, SL("_mainView"), viewPath TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the name of the main view
 */
PHP_METHOD(Phalcon_Mvc_View, getMainView) {

	

	RETURN_MEMBER(this_ptr, "_mainView");

}

/**
 * Change the layout to be used instead of using the name of the latest controller name
 *
 * <code>
 * 	$this->view->setLayout('main');
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_View, setLayout) {

	zval *layout_param = NULL;
	zval *layout = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &layout_param);

	zephir_get_strval(layout, layout_param);


	zephir_update_property_this(this_ptr, SL("_layout"), layout TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the name of the main view
 */
PHP_METHOD(Phalcon_Mvc_View, getLayout) {

	

	RETURN_MEMBER(this_ptr, "_layout");

}

/**
 * Sets a template before the controller layout
 *
 * @param string|array templateBefore
 * @return \Phalcon\Mvc\View
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
		zephir_update_property_this(this_ptr, SL("_templatesBefore"), _0$$3 TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_templatesBefore"), templateBefore TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Resets any "template before" layouts
 */
PHP_METHOD(Phalcon_Mvc_View, cleanTemplateBefore) {

	

	zephir_update_property_this(this_ptr, SL("_templatesBefore"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Sets a "template after" controller layout
 *
 * @param string|array templateAfter
 * @return \Phalcon\Mvc\View
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
		zephir_update_property_this(this_ptr, SL("_templatesAfter"), _0$$3 TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_templatesAfter"), templateAfter TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Resets any template before layouts
 */
PHP_METHOD(Phalcon_Mvc_View, cleanTemplateAfter) {

	

	zephir_update_property_this(this_ptr, SL("_templatesAfter"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Adds parameters to views (alias of setVar)
 *
 *<code>
 *	$this->view->setParamToView('products', $products);
 *</code>
 *
 * @param string key
 * @param mixed value
 * @return \Phalcon\Mvc\View
 */
PHP_METHOD(Phalcon_Mvc_View, setParamToView) {

	zval *key_param = NULL, *value;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
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
 *	$this->view->setVars(array('products' => $products));
 *</code>
 *
 * @param array params
 * @param boolean merge
 * @return \Phalcon\Mvc\View
 */
PHP_METHOD(Phalcon_Mvc_View, setVars) {

	zend_bool merge;
	zval *params_param = NULL, *merge_param = NULL, *viewParams = NULL, *_0$$4;
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
		ZEPHIR_OBS_VAR(viewParams);
		zephir_read_property_this(&viewParams, this_ptr, SL("_viewParams"), PH_NOISY_CC);
		if (Z_TYPE_P(viewParams) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(_0$$4);
			zephir_fast_array_merge(_0$$4, &(viewParams), &(params) TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_viewParams"), _0$$4 TSRMLS_CC);
		} else {
			zephir_update_property_this(this_ptr, SL("_viewParams"), params TSRMLS_CC);
		}
	} else {
		zephir_update_property_this(this_ptr, SL("_viewParams"), params TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Set a single view parameter
 *
 *<code>
 *	$this->view->setVar('products', $products);
 *</code>
 *
 * @param string key
 * @param mixed value
 * @return \Phalcon\Mvc\View
 */
PHP_METHOD(Phalcon_Mvc_View, setVar) {

	zval *key_param = NULL, *value;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
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
 *
 * @param string key
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_View, getVar) {

	zval *key_param = NULL, *params = NULL, *value = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	params = zephir_fetch_nproperty_this(this_ptr, SL("_viewParams"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&value, params, key, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	RETURN_MM_NULL();

}

/**
 * Returns parameters to views
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View, getParamsToView) {

	

	RETURN_MEMBER(this_ptr, "_viewParams");

}

/**
 * Gets the name of the controller rendered
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View, getControllerName) {

	

	RETURN_MEMBER(this_ptr, "_controllerName");

}

/**
 * Gets the name of the action rendered
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View, getActionName) {

	

	RETURN_MEMBER(this_ptr, "_actionName");

}

/**
 * Gets extra parameters of the action rendered
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View, getParams) {

	

	RETURN_MEMBER(this_ptr, "_params");

}

/**
 * Starts rendering process enabling the output buffering
 */
PHP_METHOD(Phalcon_Mvc_View, start) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 117);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_content"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
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
	int ZEPHIR_LAST_CALL_STATUS;

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
			ZEPHIR_CALL_METHOD(NULL, _1$$4, "__construct", NULL, 364, this_ptr, dependencyInjector);
			zephir_check_call_status();
			zephir_array_update_string(&engines, SL(".phtml"), &_1$$4, PH_COPY | PH_SEPARATE);
		} else {
			if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "A dependency injector container is required to obtain the application services", "phalcon/mvc/view.zep", 570);
				return;
			}
			ZEPHIR_INIT_VAR(arguments);
			zephir_create_array(arguments, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(arguments, this_ptr);
			zephir_array_fast_append(arguments, dependencyInjector);
			zephir_is_iterable(registeredEngines, &_3$$5, &_2$$5, 0, 0, "phalcon/mvc/view.zep", 599);
			for (
			  ; zephir_hash_get_current_data_ex(_3$$5, (void**) &_4$$5, &_2$$5) == SUCCESS
			  ; zephir_hash_move_forward_ex(_3$$5, &_2$$5)
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
						zephir_throw_exception_debug(_6$$12, "phalcon/mvc/view.zep", 593 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(&_9$$11, dependencyInjector, "getshared", &_10, 0, engineService, arguments);
					zephir_check_call_status();
					zephir_array_update_zval(&engines, extension, &_9$$11, PH_COPY | PH_SEPARATE);
				}
			}
		}
		zephir_update_property_this(this_ptr, SL("_engines"), engines TSRMLS_CC);
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

	HashTable *_3, *_15$$3;
	HashPosition _2, _14$$3;
	zephir_fcall_cache_entry *_6 = NULL, *_10 = NULL, *_11 = NULL, *_13 = NULL, *_19 = NULL, *_22 = NULL, *_24 = NULL, *_27 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, renderLevel = 0, cacheLevel = 0;
	zend_bool silence, mustClean, notExists = 0;
	zval *viewPath = NULL;
	zval *engines, *viewPath_param = NULL, *silence_param = NULL, *mustClean_param = NULL, *cache = NULL, *key = NULL, *lifetime = NULL, *viewsDir = NULL, *basePath = NULL, *viewsDirPath = NULL, *viewOptions = NULL, *cacheOptions = NULL, *cachedView = NULL, *viewParams = NULL, *eventsManager = NULL, *extension = NULL, *engine = NULL, *viewEnginePath = NULL, *_0, *_1 = NULL, **_4, *_5$$3 = NULL, **_16$$3, *_7$$6 = NULL, *_8$$6 = NULL, *_9$$7 = NULL, *_12$$7 = NULL, *_17$$17 = NULL, *_18$$17 = NULL, *_20$$16 = NULL, *_21$$19 = NULL, *_23$$21 = NULL, *_25$$22 = NULL, *_26$$22 = NULL;

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
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getviewsdirs", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(_1, &_3, &_2, 0, 0, "phalcon/mvc/view.zep", 739);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(viewsDir, _4);
		ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "_isabsolutepath", &_6, 365, viewPath);
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
				if (ZEPHIR_IS_FALSE(_9$$7)) {
					ZEPHIR_INIT_NVAR(key);
					ZVAL_NULL(key);
					ZEPHIR_INIT_NVAR(lifetime);
					ZVAL_NULL(lifetime);
					ZEPHIR_OBS_NVAR(viewOptions);
					zephir_read_property_this(&viewOptions, this_ptr, SL("_options"), PH_NOISY_CC);
					if (Z_TYPE_P(viewOptions) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(cacheOptions);
						if (zephir_array_isset_string_fetch(&cacheOptions, viewOptions, SS("cache"), 0 TSRMLS_CC)) {
							if (Z_TYPE_P(cacheOptions) == IS_ARRAY) {
								ZEPHIR_OBS_NVAR(key);
								zephir_array_isset_string_fetch(&key, cacheOptions, SS("key"), 0 TSRMLS_CC);
								ZEPHIR_OBS_NVAR(lifetime);
								zephir_array_isset_string_fetch(&lifetime, cacheOptions, SS("lifetime"), 0 TSRMLS_CC);
							}
						}
					}
					if (Z_TYPE_P(key) == IS_NULL) {
						ZEPHIR_INIT_NVAR(key);
						zephir_md5(key, viewPath);
					}
					ZEPHIR_CALL_METHOD(&cachedView, cache, "start", &_11, 0, key, lifetime);
					zephir_check_call_status();
					if (Z_TYPE_P(cachedView) != IS_NULL) {
						zephir_update_property_this(this_ptr, SL("_content"), cachedView TSRMLS_CC);
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
		zephir_is_iterable(engines, &_15$$3, &_14$$3, 0, 0, "phalcon/mvc/view.zep", 723);
		for (
		  ; zephir_hash_get_current_data_ex(_15$$3, (void**) &_16$$3, &_14$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_15$$3, &_14$$3)
		) {
			ZEPHIR_GET_HMKEY(extension, _15$$3, _14$$3);
			ZEPHIR_GET_HVALUE(engine, _16$$3);
			ZEPHIR_INIT_NVAR(viewEnginePath);
			ZEPHIR_CONCAT_VV(viewEnginePath, viewsDirPath, extension);
			if ((zephir_file_exists(viewEnginePath TSRMLS_CC) == SUCCESS)) {
				if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
					zephir_update_property_this(this_ptr, SL("_activeRenderPath"), viewEnginePath TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_18$$17);
					ZVAL_STRING(_18$$17, "view:beforeRenderView", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_17$$17, eventsManager, "fire", &_19, 0, _18$$17, this_ptr, viewEnginePath);
					zephir_check_temp_parameter(_18$$17);
					zephir_check_call_status();
					if (ZEPHIR_IS_FALSE_IDENTICAL(_17$$17)) {
						continue;
					}
				}
				ZEPHIR_INIT_NVAR(_20$$16);
				if (mustClean) {
					ZVAL_BOOL(_20$$16, 1);
				} else {
					ZVAL_BOOL(_20$$16, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, engine, "render", NULL, 0, viewEnginePath, viewParams, _20$$16);
				zephir_check_call_status();
				notExists = 0;
				if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(_21$$19);
					ZVAL_STRING(_21$$19, "view:afterRenderView", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", &_22, 0, _21$$19, this_ptr);
					zephir_check_temp_parameter(_21$$19);
					zephir_check_call_status();
				}
				break;
			}
		}
		if (notExists == 0) {
			break;
		}
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			zephir_update_property_this(this_ptr, SL("_activeRenderPath"), viewEnginePath TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_23$$21);
			ZVAL_STRING(_23$$21, "view:notFoundView", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", &_24, 0, _23$$21, this_ptr, viewEnginePath);
			zephir_check_temp_parameter(_23$$21);
			zephir_check_call_status();
		}
		if (!(silence)) {
			ZEPHIR_INIT_NVAR(_25$$22);
			object_init_ex(_25$$22, phalcon_mvc_view_exception_ce);
			ZEPHIR_INIT_LNVAR(_26$$22);
			ZEPHIR_CONCAT_SVS(_26$$22, "View '", viewsDirPath, "' was not found in the views directory");
			ZEPHIR_CALL_METHOD(NULL, _25$$22, "__construct", &_27, 9, _26$$22);
			zephir_check_call_status();
			zephir_throw_exception_debug(_25$$22, "phalcon/mvc/view.zep", 736 TSRMLS_CC);
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
 * $this->view->registerEngines(array(
 *  ".phtml" => "Phalcon\Mvc\View\Engine\Php",
 *  ".volt"  => "Phalcon\Mvc\View\Engine\Volt",
 *  ".mhtml" => "MyCustomEngine"
 * ));
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_View, registerEngines) {

	zval *engines_param = NULL;
	zval *engines = NULL;

	zephir_fetch_params(0, 1, 0, &engines_param);

	engines = engines_param;


	zephir_update_property_this(this_ptr, SL("_registeredEngines"), engines TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Checks whether view exists
 */
PHP_METHOD(Phalcon_Mvc_View, exists) {

	HashTable *_2, *_6$$4;
	HashPosition _1, _5$$4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *view_param = NULL, *basePath = NULL, *viewsDir = NULL, *engines = NULL, *extension = NULL, *_0 = NULL, **_3, *_4$$4 = NULL, **_7$$4, *_8$$5 = NULL;
	zval *view = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &view_param);

	if (unlikely(Z_TYPE_P(view_param) != IS_STRING && Z_TYPE_P(view_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'view' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(view_param) == IS_STRING)) {
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
		zephir_update_property_this(this_ptr, SL("_registeredEngines"), engines TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getviewsdirs", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalcon/mvc/view.zep", 781);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(viewsDir, _3);
		ZEPHIR_INIT_NVAR(_4$$4);
		zephir_is_iterable(engines, &_6$$4, &_5$$4, 0, 0, "phalcon/mvc/view.zep", 779);
		for (
		  ; zephir_hash_get_current_data_ex(_6$$4, (void**) &_7$$4, &_5$$4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_6$$4, &_5$$4)
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
 * //Shows recent posts view (app/views/posts/recent.phtml)
 * $view->start()->render('posts', 'recent')->finish();
 *</code>
 *
 * @param string controllerName
 * @param string actionName
 * @param array params
 */
PHP_METHOD(Phalcon_Mvc_View, render) {

	HashTable *_17$$19, *_28$$25;
	HashPosition _16$$19, _27$$25;
	zend_bool silence = 0, mustClean = 0;
	int ZEPHIR_LAST_CALL_STATUS, renderLevel = 0;
	zephir_fcall_cache_entry *_2 = NULL, *_14 = NULL;
	zval *controllerName_param = NULL, *actionName_param = NULL, *params = NULL, *layoutsDir = NULL, *layout = NULL, *pickView = NULL, *layoutName = NULL, *engines = NULL, *renderView = NULL, *pickViewAction = NULL, *eventsManager = NULL, *disabledLevels = NULL, *templatesBefore = NULL, *templatesAfter = NULL, *templateBefore = NULL, *templateAfter = NULL, *cache = NULL, *_0, *_4, *_5, *_6, *_9 = NULL, *_10, *_1$$3 = NULL, *_7$$12 = NULL, *_8$$12, *_11$$16, *_12$$16, *_13$$16, *_15$$18, **_18$$19, *_19$$20 = NULL, *_20$$20 = NULL, *_21$$20 = NULL, *_22$$22, *_23$$22, *_24$$22, *_25$$22, *_26$$24, **_29$$25, *_30$$26 = NULL, *_31$$26 = NULL, *_32$$26 = NULL, *_33$$28, *_34$$28, *_35$$28, *_36$$14, *_37$$29 = NULL, *_38$$30 = NULL, *_39$$34;
	zval *controllerName = NULL, *actionName = NULL, *_3$$7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &controllerName_param, &actionName_param, &params);

	if (unlikely(Z_TYPE_P(controllerName_param) != IS_STRING && Z_TYPE_P(controllerName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'controllerName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(controllerName_param) == IS_STRING)) {
		zephir_get_strval(controllerName, controllerName_param);
	} else {
		ZEPHIR_INIT_VAR(controllerName);
		ZVAL_EMPTY_STRING(controllerName);
	}
	if (unlikely(Z_TYPE_P(actionName_param) != IS_STRING && Z_TYPE_P(actionName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'actionName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(actionName_param) == IS_STRING)) {
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
	zephir_update_property_this(this_ptr, SL("_currentRenderLevel"), _0 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_disabled"), PH_NOISY_CC);
	if (!ZEPHIR_IS_FALSE(_0)) {
		ZEPHIR_CALL_FUNCTION(&_1$$3, "ob_get_contents", &_2, 118);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_content"), _1$$3 TSRMLS_CC);
		RETURN_MM_BOOL(0);
	}
	zephir_update_property_this(this_ptr, SL("_controllerName"), controllerName TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_actionName"), actionName TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_params"), params TSRMLS_CC);
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
		ZEPHIR_INIT_VAR(_3$$7);
		ZEPHIR_CONCAT_VSV(_3$$7, controllerName, "/", actionName);
		ZEPHIR_CPY_WRT(renderView, _3$$7);
	} else {
		ZEPHIR_OBS_NVAR(renderView);
		zephir_array_fetch_long(&renderView, pickView, 0, PH_NOISY, "phalcon/mvc/view.zep", 854 TSRMLS_CC);
		ZEPHIR_OBS_VAR(pickViewAction);
		if (zephir_array_isset_long_fetch(&pickViewAction, pickView, 1, 0 TSRMLS_CC)) {
			ZEPHIR_CPY_WRT(layoutName, pickViewAction);
		}
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_cacheLevel"), PH_NOISY_CC);
	if (zephir_is_true(_4)) {
		ZEPHIR_CALL_METHOD(&cache, this_ptr, "getcache", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(cache);
		ZVAL_NULL(cache);
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(eventsManager, _5);
	ZEPHIR_INIT_VAR(_6);
	zephir_create_symbol_table(TSRMLS_C);
	
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_8$$12);
		ZVAL_STRING(_8$$12, "view:beforeRender", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_7$$12, eventsManager, "fire", NULL, 0, _8$$12, this_ptr);
		zephir_check_temp_parameter(_8$$12);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_7$$12)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_CALL_FUNCTION(&_9, "ob_get_contents", &_2, 118);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_content"), _9 TSRMLS_CC);
	mustClean = 1;
	silence = 1;
	ZEPHIR_OBS_VAR(disabledLevels);
	zephir_read_property_this(&disabledLevels, this_ptr, SL("_disabledLevels"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_10);
	zephir_read_property_this(&_10, this_ptr, SL("_renderLevel"), PH_NOISY_CC);
	renderLevel = zephir_get_intval(_10);
	if (renderLevel) {
		if (renderLevel >= 1) {
			if (!(zephir_array_isset_long(disabledLevels, 1))) {
				ZEPHIR_INIT_ZVAL_NREF(_11$$16);
				ZVAL_LONG(_11$$16, 1);
				zephir_update_property_this(this_ptr, SL("_currentRenderLevel"), _11$$16 TSRMLS_CC);
				ZEPHIR_INIT_VAR(_12$$16);
				if (silence) {
					ZVAL_BOOL(_12$$16, 1);
				} else {
					ZVAL_BOOL(_12$$16, 0);
				}
				ZEPHIR_INIT_VAR(_13$$16);
				if (mustClean) {
					ZVAL_BOOL(_13$$16, 1);
				} else {
					ZVAL_BOOL(_13$$16, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_enginerender", &_14, 0, engines, renderView, _12$$16, _13$$16, cache);
				zephir_check_call_status();
			}
		}
		if (renderLevel >= 2) {
			if (!(zephir_array_isset_long(disabledLevels, 2))) {
				ZEPHIR_INIT_ZVAL_NREF(_15$$18);
				ZVAL_LONG(_15$$18, 2);
				zephir_update_property_this(this_ptr, SL("_currentRenderLevel"), _15$$18 TSRMLS_CC);
				ZEPHIR_OBS_VAR(templatesBefore);
				zephir_read_property_this(&templatesBefore, this_ptr, SL("_templatesBefore"), PH_NOISY_CC);
				if (Z_TYPE_P(templatesBefore) == IS_ARRAY) {
					silence = 0;
					zephir_is_iterable(templatesBefore, &_17$$19, &_16$$19, 0, 0, "phalcon/mvc/view.zep", 930);
					for (
					  ; zephir_hash_get_current_data_ex(_17$$19, (void**) &_18$$19, &_16$$19) == SUCCESS
					  ; zephir_hash_move_forward_ex(_17$$19, &_16$$19)
					) {
						ZEPHIR_GET_HVALUE(templateBefore, _18$$19);
						ZEPHIR_INIT_LNVAR(_19$$20);
						ZEPHIR_CONCAT_VV(_19$$20, layoutsDir, templateBefore);
						ZEPHIR_INIT_NVAR(_20$$20);
						if (silence) {
							ZVAL_BOOL(_20$$20, 1);
						} else {
							ZVAL_BOOL(_20$$20, 0);
						}
						ZEPHIR_INIT_NVAR(_21$$20);
						if (mustClean) {
							ZVAL_BOOL(_21$$20, 1);
						} else {
							ZVAL_BOOL(_21$$20, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "_enginerender", &_14, 0, engines, _19$$20, _20$$20, _21$$20, cache);
						zephir_check_call_status();
					}
					silence = 1;
				}
			}
		}
		if (renderLevel >= 3) {
			if (!(zephir_array_isset_long(disabledLevels, 3))) {
				ZEPHIR_INIT_ZVAL_NREF(_22$$22);
				ZVAL_LONG(_22$$22, 3);
				zephir_update_property_this(this_ptr, SL("_currentRenderLevel"), _22$$22 TSRMLS_CC);
				ZEPHIR_INIT_VAR(_23$$22);
				ZEPHIR_CONCAT_VV(_23$$22, layoutsDir, layoutName);
				ZEPHIR_INIT_VAR(_24$$22);
				if (silence) {
					ZVAL_BOOL(_24$$22, 1);
				} else {
					ZVAL_BOOL(_24$$22, 0);
				}
				ZEPHIR_INIT_VAR(_25$$22);
				if (mustClean) {
					ZVAL_BOOL(_25$$22, 1);
				} else {
					ZVAL_BOOL(_25$$22, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_enginerender", &_14, 0, engines, _23$$22, _24$$22, _25$$22, cache);
				zephir_check_call_status();
			}
		}
		if (renderLevel >= 4) {
			if (!(zephir_array_isset_long(disabledLevels, 4))) {
				ZEPHIR_INIT_ZVAL_NREF(_26$$24);
				ZVAL_LONG(_26$$24, 4);
				zephir_update_property_this(this_ptr, SL("_currentRenderLevel"), _26$$24 TSRMLS_CC);
				ZEPHIR_OBS_VAR(templatesAfter);
				zephir_read_property_this(&templatesAfter, this_ptr, SL("_templatesAfter"), PH_NOISY_CC);
				if (Z_TYPE_P(templatesAfter) == IS_ARRAY) {
					silence = 0;
					zephir_is_iterable(templatesAfter, &_28$$25, &_27$$25, 0, 0, "phalcon/mvc/view.zep", 961);
					for (
					  ; zephir_hash_get_current_data_ex(_28$$25, (void**) &_29$$25, &_27$$25) == SUCCESS
					  ; zephir_hash_move_forward_ex(_28$$25, &_27$$25)
					) {
						ZEPHIR_GET_HVALUE(templateAfter, _29$$25);
						ZEPHIR_INIT_LNVAR(_30$$26);
						ZEPHIR_CONCAT_VV(_30$$26, layoutsDir, templateAfter);
						ZEPHIR_INIT_NVAR(_31$$26);
						if (silence) {
							ZVAL_BOOL(_31$$26, 1);
						} else {
							ZVAL_BOOL(_31$$26, 0);
						}
						ZEPHIR_INIT_NVAR(_32$$26);
						if (mustClean) {
							ZVAL_BOOL(_32$$26, 1);
						} else {
							ZVAL_BOOL(_32$$26, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "_enginerender", &_14, 0, engines, _30$$26, _31$$26, _32$$26, cache);
						zephir_check_call_status();
					}
					silence = 1;
				}
			}
		}
		if (renderLevel >= 5) {
			if (!(zephir_array_isset_long(disabledLevels, 5))) {
				ZEPHIR_INIT_ZVAL_NREF(_33$$28);
				ZVAL_LONG(_33$$28, 5);
				zephir_update_property_this(this_ptr, SL("_currentRenderLevel"), _33$$28 TSRMLS_CC);
				_33$$28 = zephir_fetch_nproperty_this(this_ptr, SL("_mainView"), PH_NOISY_CC);
				ZEPHIR_INIT_VAR(_34$$28);
				if (silence) {
					ZVAL_BOOL(_34$$28, 1);
				} else {
					ZVAL_BOOL(_34$$28, 0);
				}
				ZEPHIR_INIT_VAR(_35$$28);
				if (mustClean) {
					ZVAL_BOOL(_35$$28, 1);
				} else {
					ZVAL_BOOL(_35$$28, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_enginerender", &_14, 0, engines, _33$$28, _34$$28, _35$$28, cache);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_ZVAL_NREF(_36$$14);
		ZVAL_LONG(_36$$14, 0);
		zephir_update_property_this(this_ptr, SL("_currentRenderLevel"), _36$$14 TSRMLS_CC);
		if (Z_TYPE_P(cache) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(&_37$$29, cache, "isstarted", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_TRUE(_37$$29)) {
				ZEPHIR_CALL_METHOD(&_38$$30, cache, "isfresh", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_TRUE(_38$$30)) {
					ZEPHIR_CALL_METHOD(NULL, cache, "save", NULL, 0);
					zephir_check_call_status();
				} else {
					ZEPHIR_CALL_METHOD(NULL, cache, "stop", NULL, 0);
					zephir_check_call_status();
				}
			} else {
				ZEPHIR_CALL_METHOD(NULL, cache, "stop", NULL, 0);
				zephir_check_call_status();
			}
		}
	}
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_39$$34);
		ZVAL_STRING(_39$$34, "view:afterRender", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _39$$34, this_ptr);
		zephir_check_temp_parameter(_39$$34);
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
 *
 *    public function saveAction()
 *    {
 *
 *         // Do some save stuff...
 *
 *         // Then show the list view
 *         $this->view->pick("products/list");
 *    }
 * }
 * </code>
 *
 * @param string|array renderView
 * @return \Phalcon\Mvc\View
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
		if (zephir_memnstr_str(renderView, SL("/"), "phalcon/mvc/view.zep", 1036)) {
			ZEPHIR_INIT_VAR(parts);
			zephir_fast_explode_str(parts, SL("/"), renderView, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_NVAR(layout);
			zephir_array_fetch_long(&layout, parts, 0, PH_NOISY, "phalcon/mvc/view.zep", 1037 TSRMLS_CC);
		}
		ZEPHIR_INIT_NVAR(pickView);
		zephir_create_array(pickView, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(pickView, renderView);
		if (Z_TYPE_P(layout) != IS_NULL) {
			zephir_array_append(&pickView, layout, PH_SEPARATE, "phalcon/mvc/view.zep", 1042);
		}
	}
	zephir_update_property_this(this_ptr, SL("_pickView"), pickView TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Renders a partial view
 *
 * <code>
 * 	//Retrieve the contents of a partial
 * 	echo $this->getPartial('shared/footer');
 * </code>
 *
 * <code>
 * 	//Retrieve the contents of a partial with arguments
 * 	echo $this->getPartial('shared/footer', array('content' => $html));
 * </code>
 *
 * @param string partialPath
 * @param array params
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View, getPartial) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *partialPath_param = NULL, *params = NULL;
	zval *partialPath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &partialPath_param, &params);

	if (unlikely(Z_TYPE_P(partialPath_param) != IS_STRING && Z_TYPE_P(partialPath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'partialPath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(partialPath_param) == IS_STRING)) {
		zephir_get_strval(partialPath, partialPath_param);
	} else {
		ZEPHIR_INIT_VAR(partialPath);
		ZVAL_EMPTY_STRING(partialPath);
	}
	if (!params) {
		params = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 117);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "partial", NULL, 0, partialPath, params);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", NULL, 282);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Renders a partial view
 *
 * <code>
 * 	//Show a partial inside another view
 * 	$this->partial('shared/footer');
 * </code>
 *
 * <code>
 * 	//Show a partial inside another view with parameters
 * 	$this->partial('shared/footer', array('content' => $html));
 * </code>
 *
 * @param string partialPath
 * @param array params
 */
PHP_METHOD(Phalcon_Mvc_View, partial) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *partialPath_param = NULL, *params = NULL, *viewParams = NULL, *_2 = NULL, *_3, *_4, *_5, *_6, *_0$$4, *_1$$3;
	zval *partialPath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &partialPath_param, &params);

	if (unlikely(Z_TYPE_P(partialPath_param) != IS_STRING && Z_TYPE_P(partialPath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'partialPath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(partialPath_param) == IS_STRING)) {
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
		if (Z_TYPE_P(viewParams) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(_0$$4);
			zephir_fast_array_merge(_0$$4, &(viewParams), &(params) TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_viewParams"), _0$$4 TSRMLS_CC);
		} else {
			zephir_update_property_this(this_ptr, SL("_viewParams"), params TSRMLS_CC);
		}
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
		zephir_update_property_this(this_ptr, SL("_viewParams"), viewParams TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Perform the automatic rendering returning the output as a string
 *
 * <code>
 * 	$template = $this->view->getRender('products', 'show', array('products' => $products));
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
	int ZEPHIR_LAST_CALL_STATUS;
	zval *controllerName_param = NULL, *actionName_param = NULL, *params = NULL, *configCallback = NULL, *view = NULL, *_0$$4;
	zval *controllerName = NULL, *actionName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &controllerName_param, &actionName_param, &params, &configCallback);

	if (unlikely(Z_TYPE_P(controllerName_param) != IS_STRING && Z_TYPE_P(controllerName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'controllerName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(controllerName_param) == IS_STRING)) {
		zephir_get_strval(controllerName, controllerName_param);
	} else {
		ZEPHIR_INIT_VAR(controllerName);
		ZVAL_EMPTY_STRING(controllerName);
	}
	if (unlikely(Z_TYPE_P(actionName_param) != IS_STRING && Z_TYPE_P(actionName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'actionName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(actionName_param) == IS_STRING)) {
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
	ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 119);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(view, "getcontent", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Finishes the render process by stopping the output buffering
 */
PHP_METHOD(Phalcon_Mvc_View, finish) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 119);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Create a Phalcon\Cache based on the internal cache options
 */
PHP_METHOD(Phalcon_Mvc_View, _createCache) {

	zval *dependencyInjector = NULL, *cacheService = NULL, *viewCache = NULL, *viewOptions = NULL, *cacheOptions = NULL, *_0, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(dependencyInjector, _0);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "A dependency injector container is required to obtain the view cache services", "phalcon/mvc/view.zep", 1216);
		return;
	}
	ZEPHIR_INIT_VAR(cacheService);
	ZVAL_STRING(cacheService, "viewCache", 1);
	ZEPHIR_OBS_VAR(viewOptions);
	zephir_read_property_this(&viewOptions, this_ptr, SL("_options"), PH_NOISY_CC);
	if (Z_TYPE_P(viewOptions) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(cacheOptions);
		if (zephir_array_isset_string_fetch(&cacheOptions, viewOptions, SS("cache"), 0 TSRMLS_CC)) {
			if (zephir_array_isset_string(cacheOptions, SS("service"))) {
				ZEPHIR_OBS_NVAR(cacheService);
				zephir_array_fetch_string(&cacheService, cacheOptions, SL("service"), PH_NOISY, "phalcon/mvc/view.zep", 1225 TSRMLS_CC);
			}
		}
	}
	ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "getshared", NULL, 0, cacheService);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(viewCache, _1);
	if (Z_TYPE_P(viewCache) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "The injected caching service is invalid", "phalcon/mvc/view.zep", 1235);
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

	zval *cache = NULL;
	zephir_fcall_cache_entry *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(cache);
	zephir_read_property_this(&cache, this_ptr, SL("_cache"), PH_NOISY_CC);
	if (zephir_is_true(cache)) {
		if (Z_TYPE_P(cache) != IS_OBJECT) {
			ZEPHIR_CALL_METHOD(&cache, this_ptr, "_createcache", &_0, 0);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_cache"), cache TSRMLS_CC);
		}
	} else {
		ZEPHIR_CALL_METHOD(&cache, this_ptr, "_createcache", &_0, 0);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_cache"), cache TSRMLS_CC);
	}
	RETURN_CCTOR(cache);

}

/**
 * Cache the actual view render to certain level
 *
 *<code>
 *  $this->view->cache(array('key' => 'my-key', 'lifetime' => 86400));
 *</code>
 *
 * @param boolean|array options
 * @return \Phalcon\Mvc\View
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
		zephir_is_iterable(options, &_1$$3, &_0$$3, 0, 0, "phalcon/mvc/view.zep", 1303);
		for (
		  ; zephir_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1$$3, &_0$$3)
		) {
			ZEPHIR_GET_HMKEY(key, _1$$3, _0$$3);
			ZEPHIR_GET_HVALUE(value, _2$$3);
			zephir_array_update_zval(&cacheOptions, key, &value, PH_COPY | PH_SEPARATE);
		}
		if (zephir_array_isset_string_fetch(&cacheLevel, cacheOptions, SS("level"), 1 TSRMLS_CC)) {
			zephir_update_property_this(this_ptr, SL("_cacheLevel"), cacheLevel TSRMLS_CC);
		} else {
			ZEPHIR_INIT_ZVAL_NREF(_3$$8);
			ZVAL_LONG(_3$$8, 5);
			zephir_update_property_this(this_ptr, SL("_cacheLevel"), _3$$8 TSRMLS_CC);
		}
		zephir_array_update_string(&viewOptions, SL("cache"), &cacheOptions, PH_COPY | PH_SEPARATE);
		zephir_update_property_this(this_ptr, SL("_options"), viewOptions TSRMLS_CC);
	} else {
		if (zephir_is_true(options)) {
			ZEPHIR_INIT_ZVAL_NREF(_4$$10);
			ZVAL_LONG(_4$$10, 5);
			zephir_update_property_this(this_ptr, SL("_cacheLevel"), _4$$10 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_ZVAL_NREF(_5$$11);
			ZVAL_LONG(_5$$11, 0);
			zephir_update_property_this(this_ptr, SL("_cacheLevel"), _5$$11 TSRMLS_CC);
		}
	}
	RETURN_THIS();

}

/**
 * Externally sets the view content
 *
 *<code>
 *	$this->view->setContent("<h1>hello</h1>");
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_View, setContent) {

	zval *content_param = NULL;
	zval *content = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

	zephir_get_strval(content, content_param);


	zephir_update_property_this(this_ptr, SL("_content"), content TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns cached output from another view stage
 */
PHP_METHOD(Phalcon_Mvc_View, getContent) {

	

	RETURN_MEMBER(this_ptr, "_content");

}

/**
 * Returns the path of the view that is currently rendered
 */
PHP_METHOD(Phalcon_Mvc_View, getActiveRenderPath) {

	

	RETURN_MEMBER(this_ptr, "_activeRenderPath");

}

/**
 * Disables the auto-rendering process
 */
PHP_METHOD(Phalcon_Mvc_View, disable) {

	

	if (1) {
		zephir_update_property_this(this_ptr, SL("_disabled"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_disabled"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THISW();

}

/**
 * Enables the auto-rendering process
 */
PHP_METHOD(Phalcon_Mvc_View, enable) {

	

	if (0) {
		zephir_update_property_this(this_ptr, SL("_disabled"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_disabled"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THISW();

}

/**
 * Resets the view component to its factory default values
 */
PHP_METHOD(Phalcon_Mvc_View, reset) {

	zval *_0;


	if (0) {
		zephir_update_property_this(this_ptr, SL("_disabled"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_disabled"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	if (0) {
		zephir_update_property_this(this_ptr, SL("_engines"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_engines"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	zephir_update_property_this(this_ptr, SL("_cache"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 5);
	zephir_update_property_this(this_ptr, SL("_renderLevel"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 0);
	zephir_update_property_this(this_ptr, SL("_cacheLevel"), _0 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_content"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_templatesBefore"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_templatesAfter"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Magic method to pass variables to the views
 *
 *<code>
 *	$this->view->products = $products;
 *</code>
 *
 * @param string key
 * @param mixed value
 */
PHP_METHOD(Phalcon_Mvc_View, __set) {

	zval *key_param = NULL, *value;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
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
 *	echo $this->view->products;
 *</code>
 *
 * @param string key
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_View, __get) {

	zval *key_param = NULL, *value = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
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

	

	RETURN_MEMBER(this_ptr, "_disabled");

}

/**
 * Magic method to retrieve if a variable is set in the view
 *
 *<code>
 *  echo isset($this->view->products);
 *</code>
 *
 * @param string key
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_View, __isset) {

	zval *key_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
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
	RETURN_MM_MEMBER(this_ptr, "_viewsDirs");

}

