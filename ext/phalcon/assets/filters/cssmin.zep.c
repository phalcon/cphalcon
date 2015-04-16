
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
#include "phalcon/assets/filters/cssminifier.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * Phalcon\Assets\Filters\Cssmin
 *
 * Minify the css - removes comments
 * removes newlines and line feeds keeping
 * removes last semicolon from last property
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_Filters_Cssmin) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Assets\\Filters, Cssmin, phalcon, assets_filters_cssmin, phalcon_assets_filters_cssmin_method_entry, 0);

	zend_class_implements(phalcon_assets_filters_cssmin_ce TSRMLS_CC, 1, phalcon_assets_filterinterface_ce);
	return SUCCESS;

}

/**
 * Filters the content using CSSMIN
 */
PHP_METHOD(Phalcon_Assets_Filters_Cssmin, filter) {

	zval *content_param = NULL;
	zval *content = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

	if (unlikely(Z_TYPE_P(content_param) != IS_STRING && Z_TYPE_P(content_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'content' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(content_param) == IS_STRING)) {
		zephir_get_strval(content, content_param);
	} else {
		ZEPHIR_INIT_VAR(content);
		ZVAL_EMPTY_STRING(content);
	}


	phalcon_cssmin(return_value, content TSRMLS_CC);
	RETURN_MM();

}

