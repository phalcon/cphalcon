
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AuraPHP
 * @link    https://github.com/auraphp/Aura.Html
 * @license https://github.com/auraphp/Aura.Html/blob/2.x/LICENSE
 */
/**
 * Class Script
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Script)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper, Script, phalcon, html_helper_script, phalcon_html_helper_abstractseries_ce, phalcon_html_helper_script_method_entry, 0);

	return SUCCESS;
}

/**
 * Add an element to the list
 *
 * @param string $url
 * @param array  $attributes
 *
 * @return $this
 * @throws Exception
 */
PHP_METHOD(Phalcon_Html_Helper_Script, add)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval attributes, _0, _2;
	zval url_zv, *attributes_param = NULL, *position_param = NULL, _1, _3, _4;
	zend_string *url = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_zv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(url)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		attributes_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		position_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&url_zv);
	ZVAL_STR_COPY(&url_zv, url);
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	if (!position_param) {
		position = -1;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "renderFullElement");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 3, 0);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "gettag", NULL, 0);
	zephir_check_call_status();
	zephir_array_fast_append(&_2, &_3);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getattributes", NULL, 0, &url_zv, &attributes);
	zephir_check_call_status();
	zephir_array_fast_append(&_2, &_3);
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "indent", NULL, 0);
	zephir_check_call_status();
	zephir_array_fast_append(&_0, &_3);
	ZVAL_LONG(&_4, position);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "pushorplace", NULL, 0, &_0, &_4);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Begins capturing inline script content via output buffering. Pair
 * with `endInternal()` to close the buffer and append the captured
 * markup as a `<script>...</script>` block in the asset stack.
 */
PHP_METHOD(Phalcon_Html_Helper_Script, beginInternal)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 462);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Closes an inline-script buffer opened by `beginInternal()` and adds
 * the captured content as a `<script>...</script>` entry. Any
 * attributes supplied are placed on the wrapping tag. The script body
 * is treated as raw HTML (it is JavaScript, not user-supplied text).
 *
 * @param array $attributes
 * @param int   $position
 *
 * @return Script
 */
PHP_METHOD(Phalcon_Html_Helper_Script, endInternal)
{
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, *position_param = NULL, __$true, content, _0, _3, _5, _6;
	zval attributes, _2, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &attributes_param, &position_param);
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	if (!position_param) {
		position = -1;
	} else {
		}
	ZEPHIR_CALL_FUNCTION(&_0, "ob_get_clean", NULL, 464);
	zephir_check_call_status();
	zephir_cast_to_string(&_1, &_0);
	ZEPHIR_CPY_WRT(&content, &_1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 3, 0);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "renderFullElement");
	zephir_array_fast_append(&_2, &_3);
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 4, 0);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "gettag", NULL, 0);
	zephir_check_call_status();
	zephir_array_fast_append(&_4, &_5);
	zephir_array_fast_append(&_4, &content);
	zephir_array_fast_append(&_4, &attributes);
	zephir_array_fast_append(&_4, &__$true);
	zephir_array_fast_append(&_2, &_4);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "indent", NULL, 0);
	zephir_check_call_status();
	zephir_array_fast_append(&_2, &_5);
	ZVAL_LONG(&_6, position);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "pushorplace", NULL, 0, &_2, &_6);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Returns the necessary attributes
 *
 * @param string $url
 * @param array  $attributes
 *
 * @return array
 */
PHP_METHOD(Phalcon_Html_Helper_Script, getAttributes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval attributes, required;
	zval url_zv, *attributes_param = NULL;
	zend_string *url = NULL;

	ZVAL_UNDEF(&url_zv);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&required);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(url)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	attributes_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&url_zv);
	ZVAL_STR_COPY(&url_zv, url);
	zephir_get_arrval(&attributes, attributes_param);
	ZEPHIR_INIT_VAR(&required);
	zephir_create_array(&required, 2, 0);
	zephir_array_update_string(&required, SL("src"), &url_zv, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(&required, SL("type"), SL("application/javascript"));
	zephir_array_unset_string(&attributes, SL("src"), PH_SEPARATE);
	zephir_fast_array_merge(return_value, &required, &attributes);
	RETURN_MM();
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Html_Helper_Script, getTag)
{

	RETURN_STRING("script");
}

