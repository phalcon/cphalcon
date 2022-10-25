
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

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
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * All the template engine adapters must inherit this class. This provides
 * basic interfacing between the engine and the Phalcon\Mvc\View component.
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine_AbstractEngine) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\View\\Engine, AbstractEngine, phalcon, mvc_view_engine_abstractengine, phalcon_di_injectable_ce, phalcon_mvc_view_engine_abstractengine_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_mvc_view_engine_abstractengine_ce, SL("view"), ZEND_ACC_PROTECTED);

	zend_class_implements(phalcon_mvc_view_engine_abstractengine_ce, 1, phalcon_mvc_view_engine_engineinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Mvc\View\Engine constructor
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_AbstractEngine, __construct) {

	zval *view, view_sub, *container = NULL, container_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&view_sub);
	ZVAL_UNDEF(&container_sub);
	ZVAL_NULL(&__$null);

	zephir_fetch_params_without_memory_grow(1, 1, &view, &container);

	if (!container) {
		container = &container_sub;
		container = &__$null;
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("view"), view);
	zephir_update_property_zval(this_ptr, ZEND_STRL("container"), container);

}

/**
 * Returns cached output on another view stage
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_AbstractEngine, getContent) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("view"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getcontent", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the view component related to the adapter
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_AbstractEngine, getView) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "view");

}

/**
 * Renders a partial inside another view
 *
 * @param array params
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_AbstractEngine, partial) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *partialPath_param = NULL, *params = NULL, params_sub, __$null, _0;
	zval partialPath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&partialPath);
	ZVAL_UNDEF(&params_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &partialPath_param, &params);

	if (UNEXPECTED(Z_TYPE_P(partialPath_param) != IS_STRING && Z_TYPE_P(partialPath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'partialPath' must be of the type string"));
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


	zephir_read_property(&_0, this_ptr, ZEND_STRL("view"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "partial", NULL, 0, &partialPath, params);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

