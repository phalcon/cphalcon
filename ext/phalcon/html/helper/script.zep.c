
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
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
 * Class Script
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Script)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper, Script, phalcon, html_helper_script, phalcon_html_helper_style_ce, phalcon_html_helper_script_method_entry, 0);

	return SUCCESS;
}

/**
 * Returns the necessary attributes
 *
 * @param string $href
 * @param array  $attributes
 *
 * @return array
 */
PHP_METHOD(Phalcon_Html_Helper_Script, getAttributes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval attributes, required;
	zval *href_param = NULL, *attributes_param = NULL;
	zval href;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&href);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&required);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(href)
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &href_param, &attributes_param);
	zephir_get_strval(&href, href_param);
	zephir_get_arrval(&attributes, attributes_param);


	ZEPHIR_INIT_VAR(&required);
	zephir_create_array(&required, 2, 0);
	zephir_array_update_string(&required, SL("src"), &href, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(&required, SL("type"), SL("text/javascript"));
	zephir_array_unset_string(&attributes, SL("src"), PH_SEPARATE);
	zephir_fast_array_merge(return_value, &required, &attributes);
	RETURN_MM();
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Html_Helper_Script, getTag)
{
	zval *this_ptr = getThis();



	RETURN_STRING("script");
}

