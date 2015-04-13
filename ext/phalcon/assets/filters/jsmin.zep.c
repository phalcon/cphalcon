
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
#include "phalcon/assets/filters/jsminifier.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * Phalcon\Assets\Filters\Jsmin
 *
 * Deletes the characters which are insignificant to JavaScript. Comments will be removed. Tabs will be
 * replaced with spaces. Carriage returns will be replaced with linefeeds.
 * Most spaces and linefeeds will be removed.
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_Filters_Jsmin) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Assets\\Filters, Jsmin, phalcon, assets_filters_jsmin, phalcon_assets_filters_jsmin_method_entry, 0);

	zend_class_implements(phalcon_assets_filters_jsmin_ce TSRMLS_CC, 1, phalcon_assets_filterinterface_ce);
	return SUCCESS;

}

/**
 * Filters the content using JSMIN
 */
PHP_METHOD(Phalcon_Assets_Filters_Jsmin, filter) {

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


	phalcon_jsmin(return_value, content TSRMLS_CC);
	RETURN_MM();

}

