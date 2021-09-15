
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
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
 * Represents an inlined CSS
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_Inline_Css)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Assets\\Inline, Css, phalcon, assets_inline_css, phalcon_assets_inline_ce, phalcon_assets_inline_css_method_entry, 0);

	return SUCCESS;
}

/**
 * Phalcon\Assets\Inline\Css constructor
 */
PHP_METHOD(Phalcon_Assets_Inline_Css, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_bool filter;
	zval *content_param = NULL, *filter_param = NULL, *attributes = NULL, attributes_sub, __$null, _0$$3, _2, _3;
	zval content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&attributes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(content)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(filter)
		Z_PARAM_ZVAL(attributes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &content_param, &filter_param, &attributes);
	zephir_get_strval(&content, content_param);
	if (!filter_param) {
		filter = 1;
	} else {
		filter = zephir_get_boolval(filter_param);
	}
	if (!attributes) {
		attributes = &attributes_sub;
		ZEPHIR_CPY_WRT(attributes, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(attributes);
	}


	if (Z_TYPE_P(attributes) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 1, 0);
		add_assoc_stringl_ex(&_0$$3, SL("type"), SL("text/css"));
		ZEPHIR_CPY_WRT(attributes, &_0$$3);
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "css");
	if (filter) {
		ZVAL_BOOL(&_3, 1);
	} else {
		ZVAL_BOOL(&_3, 0);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_assets_inline_css_ce, getThis(), "__construct", &_1, 0, &_2, &content, &_3, attributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

