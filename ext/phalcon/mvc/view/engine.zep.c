
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
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


/**
 * Phalcon\Mvc\View\Engine
 *
 * All the template engine adapters must inherit this class. This provides
 * basic interfacing between the engine and the Phalcon\Mvc\View component.
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\View, Engine, phalcon, mvc_view_engine, phalcon_di_injectable_ce, phalcon_mvc_view_engine_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_mvc_view_engine_ce, SL("_view"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Mvc\View\Engine constructor
 */
PHP_METHOD(Phalcon_Mvc_View_Engine, __construct) {

	zval *view, view_sub, *dependencyInjector = NULL, dependencyInjector_sub, __$null;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&view_sub);
	ZVAL_UNDEF(&dependencyInjector_sub);
	ZVAL_NULL(&__$null);

	zephir_fetch_params(0, 1, 1, &view, &dependencyInjector);

	if (!dependencyInjector) {
		dependencyInjector = &dependencyInjector_sub;
		dependencyInjector = &__$null;
	}


	zephir_update_property_zval(this_ptr, SL("_view"), view);
	zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), dependencyInjector);

}

/**
 * Returns cached output on another view stage
 */
PHP_METHOD(Phalcon_Mvc_View_Engine, getContent) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_view"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getcontent", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Renders a partial inside another view
 *
 * @param string partialPath
 * @param array params
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine, partial) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *partialPath_param = NULL, *params = NULL, params_sub, __$null, _0;
	zval partialPath;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&partialPath);
	ZVAL_UNDEF(&params_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &partialPath_param, &params);

	if (unlikely(Z_TYPE_P(partialPath_param) != IS_STRING && Z_TYPE_P(partialPath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'partialPath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(partialPath_param) == IS_STRING)) {
		zephir_get_strval(&partialPath, partialPath_param);
	} else {
		ZEPHIR_INIT_VAR(&partialPath);
		ZVAL_EMPTY_STRING(&partialPath);
	}
	if (!params) {
		params = &params_sub;
		params = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("_view"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "partial", NULL, 0, &partialPath, params);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the view component related to the adapter
 */
PHP_METHOD(Phalcon_Mvc_View_Engine, getView) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_view");

}

