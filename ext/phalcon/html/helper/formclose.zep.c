
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Html\Helper\FormClose
 *
 * Creates a form closing tag
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_FormClose) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper, FormClose, phalcon, html_helper_formclose, phalcon_html_helper_abstracthelper_ce, phalcon_html_helper_formclose_method_entry, 0);

	return SUCCESS;

}

/**
 * @var array  attributes Any additional attributes
 */
PHP_METHOD(Phalcon_Html_Helper_FormClose, __invoke) {

	zval *this_ptr = getThis();


	RETURN_STRING("</form>");

}

