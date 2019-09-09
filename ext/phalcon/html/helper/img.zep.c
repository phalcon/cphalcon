
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
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
 * Phalcon\Html\Helper\Img
 *
 * Creates am img tag
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Img) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper, Img, phalcon, html_helper_img, phalcon_html_helper_abstracthelper_ce, phalcon_html_helper_img_method_entry, 0);

	return SUCCESS;

}

/**
 * @param string $src
 * @param array  $attributes Any additional attributes
 *
 * @return string
 * @throws Exception
 */
PHP_METHOD(Phalcon_Html_Helper_Img, __invoke) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zval *src_param = NULL, *attributes_param = NULL, overrides, _0;
	zval src;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&src);
	ZVAL_UNDEF(&overrides);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&attributes);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &src_param, &attributes_param);

	if (UNEXPECTED(Z_TYPE_P(src_param) != IS_STRING && Z_TYPE_P(src_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'src' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(src_param) == IS_STRING)) {
		zephir_get_strval(&src, src_param);
	} else {
		ZEPHIR_INIT_VAR(&src);
		ZVAL_EMPTY_STRING(&src);
	}
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);
	}


	ZEPHIR_INIT_VAR(&overrides);
	zephir_create_array(&overrides, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&overrides, SL("src"), &src, PH_COPY | PH_SEPARATE);
	zephir_array_unset_string(&attributes, SL("src"), PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_array_merge(&_0, &overrides, &attributes TSRMLS_CC);
	ZEPHIR_CPY_WRT(&overrides, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "img");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "selfclose", NULL, 0, &_0, &overrides);
	zephir_check_call_status();
	RETURN_MM();

}

