
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
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
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
 * Phalcon\Html\Helper\Close
 *
 * Creates a closing tag
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Close) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper, Close, phalcon, html_helper_close, phalcon_html_helper_abstracthelper_ce, phalcon_html_helper_close_method_entry, 0);

	return SUCCESS;

}

/**
 * @param string $tag The tag
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Helper_Close, __invoke) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *tag_param = NULL;
	zval tag;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tag);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &tag_param);

	if (UNEXPECTED(Z_TYPE_P(tag_param) != IS_STRING && Z_TYPE_P(tag_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tag' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tag_param) == IS_STRING)) {
		zephir_get_strval(&tag, tag_param);
	} else {
		ZEPHIR_INIT_VAR(&tag);
		ZVAL_EMPTY_STRING(&tag);
	}


	ZEPHIR_CONCAT_SVS(return_value, "</", &tag, ">");
	RETURN_MM();

}

