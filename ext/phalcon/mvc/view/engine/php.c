
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
#include "kernel/object.h"
#include "kernel/operators.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Mvc\View\Engine\Php
 *
 * Adapter to use PHP itself as templating engine
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine_Php) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\View\\Engine, Php, phalcon, mvc_view_engine_php, phalcon_mvc_view_engine_ce, phalcon_mvc_view_engine_php_method_entry, 0);

	zend_class_implements(phalcon_mvc_view_engine_php_ce TSRMLS_CC, 1, phalcon_mvc_view_engineinterface_ce);

	return SUCCESS;

}

/**
 * Renders a view using the template engine
 *
 * @param string path
 * @param array params
 * @param boolean mustClean
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Php, render) {

	zend_bool mustClean;
	zval *path_param = NULL, *params, *mustClean_param = NULL, *status, *view, *_0;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &path_param, &params, &mustClean_param);

		zephir_get_strval(path, path_param);
	if (!mustClean_param) {
		mustClean = 0;
	} else {
		mustClean = zephir_get_boolval(mustClean_param);
	}


	if ((mustClean == 1)) {
		zephir_call_func_noret("ob_clean");
	}
	if ((Z_TYPE_P(params) == IS_ARRAY)) {
	}
	ZEPHIR_INIT_VAR(status);
	ZVAL_NULL(status);
	if ((mustClean == 1)) {
		ZEPHIR_OBS_VAR(view);
		zephir_read_property_this(&view, this_ptr, SL("_view"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_0);
		zephir_call_func(_0, "ob_get_contents");
		zephir_call_method_p1_noret(view, "setcontent", _0);
	}
	ZEPHIR_MM_RESTORE();

}

