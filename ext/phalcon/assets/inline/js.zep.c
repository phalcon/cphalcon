
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
 * Represents an inline JavaScript
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_Inline_Js)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Assets\\Inline, Js, phalcon, assets_inline_js, phalcon_assets_inline_ce, phalcon_assets_inline_js_method_entry, 0);

	return SUCCESS;
}

/**
 * Phalcon\Assets\Inline\Js constructor
 */
PHP_METHOD(Phalcon_Assets_Inline_Js, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zend_bool filter;
	zval *content_param = NULL, *filter_param = NULL, *attributes_param = NULL, _0$$3, _1, _2;
	zval content;

	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&attributes);
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(content)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(filter)
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 2, &content_param, &filter_param, &attributes_param);
	zephir_get_strval(&content, content_param);
	if (!filter_param) {
		filter = 1;
	} else {
		}
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	if (1 == ZEPHIR_IS_EMPTY(&attributes)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 1, 0);
		add_assoc_stringl_ex(&_0$$3, SL("type"), SL("application/javascript"));
		ZEPHIR_CPY_WRT(&attributes, &_0$$3);
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "js");
	if (filter) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_assets_inline_js_ce, getThis(), "__construct", NULL, 0, &_1, &content, &_2, &attributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

