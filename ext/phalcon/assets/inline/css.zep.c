
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"


/**
 * Phalcon\Assets\Inline\Css
 *
 * Represents inline CSS
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_Inline_Css) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Assets\\Inline, Css, phalcon, assets_inline_css, phalcon_assets_inline_ce, phalcon_assets_inline_css_method_entry, 0);

	return SUCCESS;

}

/**
 * Phalcon\Assets\Inline\Css
 *
 * @param string content
 * @param boolean filter
 * @param array attributes
 */
PHP_METHOD(Phalcon_Assets_Inline_Css, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zend_bool filter;
	zval *content_param = NULL, *filter_param = NULL, *attributes = NULL, *_1;
	zval *content = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &content_param, &filter_param, &attributes);

	zephir_get_strval(content, content_param);
	if (!filter_param) {
		filter = 1;
	} else {
		filter = zephir_get_boolval(filter_param);
	}
	if (!attributes) {
		ZEPHIR_CPY_WRT(attributes, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(attributes);
	}


	if (Z_TYPE_P(attributes) == IS_NULL) {
		ZEPHIR_INIT_NVAR(attributes);
		zephir_create_array(attributes, 1, 0 TSRMLS_CC);
		add_assoc_stringl_ex(attributes, SS("type"), SL("text/css"), 1);
	}
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "css", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_PARENT(NULL, phalcon_assets_inline_css_ce, this_ptr, "__construct", &_0, 26, _1, content, (filter ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)), attributes);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

