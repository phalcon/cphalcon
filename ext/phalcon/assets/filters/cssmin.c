
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
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"


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
 * Phalcon\Assets\Filters\Cssmin
 *
 * Minify the css - removes comments
 * removes newlines and line feeds keeping
 * removes last semicolon from last property
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_Filters_Cssmin) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Assets\\Filters, Cssmin, phalcon, assets_filters_cssmin, phalcon_assets_filters_cssmin_method_entry, 0);


	return SUCCESS;

}

/**
 * Filters the content using CSSMIN
 *
 * @param string content
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Filters_Cssmin, filter) {

	zval *content_param = NULL;
	zval *content = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

		if (Z_TYPE_P(content_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'content' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		content = content_param;


	zephir_call_func_p1(return_value, "phalcon_cssmin", content);
	RETURN_MM();

}

