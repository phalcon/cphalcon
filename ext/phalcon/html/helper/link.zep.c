
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Class Link
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Link) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper, Link, phalcon, html_helper_link, phalcon_html_helper_abstractseries_ce, phalcon_html_helper_link_method_entry, 0);

	return SUCCESS;

}

/**
 * Add an element to the list
 *
 * @param string $rel
 * @param string $href
 *
 * @return Link
 */
PHP_METHOD(Phalcon_Html_Helper_Link, add) {

	zval _0, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *rel_param = NULL, *href_param = NULL, attributes, _1, _3;
	zval rel, href;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rel);
	ZVAL_UNDEF(&href);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(rel)
		Z_PARAM_STR(href)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &rel_param, &href_param);

	zephir_get_strval(&rel, rel_param);
	zephir_get_strval(&href, href_param);


	ZEPHIR_INIT_VAR(&attributes);
	zephir_create_array(&attributes, 2, 0);
	zephir_array_update_string(&attributes, SL("rel"), &rel, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&attributes, SL("href"), &href, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "renderTag");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 3, 0);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "gettag", NULL, 0);
	zephir_check_call_status();
	zephir_array_fast_append(&_2, &_3);
	zephir_array_fast_append(&_2, &attributes);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "/");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "indent", NULL, 0);
	zephir_check_call_status();
	zephir_array_fast_append(&_0, &_3);
	zephir_update_property_array_append(this_ptr, SL("store"), &_0);
	RETURN_THIS();

}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Html_Helper_Link, getTag) {

	zval *this_ptr = getThis();



	RETURN_STRING("link");

}

