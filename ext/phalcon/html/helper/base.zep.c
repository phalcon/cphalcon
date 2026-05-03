
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
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
 * Class Base
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Base)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper, Base, phalcon, html_helper_base, phalcon_html_helper_abstracthelper_ce, phalcon_html_helper_base_method_entry, 0);

	return SUCCESS;
}

/**
 * Produce a `<base/>` tag.
 *
 * @param string $href
 * @param array  $attributes
 *
 * @return string
 * @throws Exception
 */
PHP_METHOD(Phalcon_Html_Helper_Base, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zval href_zv, *attributes_param = NULL, _0$$3, _1$$3, _2;
	zend_string *href = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&href_zv);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&attributes);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(href)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		attributes_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (!href) {
		ZEPHIR_INIT_VAR(&href_zv);
	} else {
		ZVAL_STR_COPY(&href_zv, href);
	}
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	if (!(ZEPHIR_IS_EMPTY(&href_zv))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "href");
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "injectattribute", NULL, 0, &_1$$3, &href_zv, &attributes);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&attributes, &_0$$3);
	} else {
		zephir_array_unset_string(&attributes, SL("href"), PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "base");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderelement", NULL, 0, &_2, &attributes);
	zephir_check_call_status();
	RETURN_MM();
}

