
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Minify the CSS - removes comments removes newlines and line feeds keeping
 * removes last semicolon from last property
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_Filters_Cssmin)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Assets\\Filters, Cssmin, phalcon, assets_filters_cssmin, phalcon_assets_filters_cssmin_method_entry, 0);

	zend_class_implements(phalcon_assets_filters_cssmin_ce, 1, phalcon_assets_filterinterface_ce);
	return SUCCESS;
}

/**
 * Filters the content using CSSMIN
 * NOTE: This functionality is not currently available
 */
PHP_METHOD(Phalcon_Assets_Filters_Cssmin, filter)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *content_param = NULL;
	zval content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(content)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);
	if (UNEXPECTED(Z_TYPE_P(content_param) != IS_STRING && Z_TYPE_P(content_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'content' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(content_param) == IS_STRING)) {
		zephir_get_strval(&content, content_param);
	} else {
		ZEPHIR_INIT_VAR(&content);
	}


	RETURN_CTOR(&content);
}

