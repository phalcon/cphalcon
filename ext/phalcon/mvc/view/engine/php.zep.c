
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/require.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


/**
 * Phalcon\Mvc\View\Engine\Php
 *
 * Adapter to use PHP itself as templating engine
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine_Php) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\View\\Engine, Php, phalcon, mvc_view_engine_php, phalcon_mvc_view_engine_ce, phalcon_mvc_view_engine_php_method_entry, 0);

	return SUCCESS;

}

/**
 * Renders a view using the template engine
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Php, render) {

	HashTable *_1$$4;
	HashPosition _0$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool mustClean;
	zval *path_param = NULL, *params, *mustClean_param = NULL, *key = NULL, *value = NULL, **_2$$4, *_3$$5 = NULL, *_4$$6, *_5$$6 = NULL;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &path_param, &params, &mustClean_param);

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
	if (!mustClean_param) {
		mustClean = 0;
	} else {
		mustClean = zephir_get_boolval(mustClean_param);
	}


	if (mustClean == 1) {
		ZEPHIR_CALL_FUNCTION(NULL, "ob_clean", NULL, 403);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(params) == IS_ARRAY) {
		zephir_is_iterable(params, &_1$$4, &_0$$4, 0, 0, "phalcon/mvc/view/engine/php.zep", 50);
		for (
		  ; zend_hash_get_current_data_ex(_1$$4, (void**) &_2$$4, &_0$$4) == SUCCESS
		  ; zend_hash_move_forward_ex(_1$$4, &_0$$4)
		) {
			ZEPHIR_GET_HMKEY(key, _1$$4, _0$$4);
			ZEPHIR_GET_HVALUE(value, _2$$4);
			ZEPHIR_CPY_WRT(_3$$5, value);
			if (zephir_set_symbol(key, _3$$5 TSRMLS_CC) == FAILURE) {
				return;
			}
		}
	}
	if (zephir_require_zval(path TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	if (mustClean == 1) {
		_4$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_view"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_5$$6, "ob_get_contents", NULL, 141);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _4$$6, "setcontent", NULL, 0, _5$$6);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

