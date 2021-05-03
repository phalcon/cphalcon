
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
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
	zval *href_param = NULL, *attributes_param = NULL, overrides, _1, _0$$3;
	zval href;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&href);
	ZVAL_UNDEF(&overrides);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&attributes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(href)
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &href_param, &attributes_param);
	if (!href_param) {
		ZEPHIR_INIT_VAR(&href);
	} else {
		zephir_get_strval(&href, href_param);
	}
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}


	ZEPHIR_INIT_VAR(&overrides);
	array_init(&overrides);
	if (!(ZEPHIR_IS_EMPTY(&href))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 1, 0);
		zephir_array_update_string(&_0$$3, SL("href"), &href, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&overrides, &_0$$3);
	}
	zephir_array_unset_string(&attributes, SL("href"), PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_array_merge(&_1, &overrides, &attributes);
	ZEPHIR_CPY_WRT(&overrides, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "base");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderelement", NULL, 0, &_1, &overrides);
	zephir_check_call_status();
	RETURN_MM();
}

