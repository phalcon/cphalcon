
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
#include "kernel/operators.h"
#include "kernel/memory.h"
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
 * Class Close
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Close) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper, Close, phalcon, html_helper_close, phalcon_html_helper_abstracthelper_ce, phalcon_html_helper_close_method_entry, 0);

	return SUCCESS;

}

/**
 * Produce a `</...>` tag.
 *
 * @param string $tag
 * @param bool   $raw
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Helper_Close, __invoke) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool raw;
	zval *tag_param = NULL, *raw_param = NULL, _0;
	zval tag;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tag);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &tag_param, &raw_param);

	zephir_get_strval(&tag, tag_param);
	if (!raw_param) {
		raw = 0;
	} else {
		raw = zephir_get_boolval(raw_param);
	}


	if (raw) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "close", NULL, 0, &tag, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

