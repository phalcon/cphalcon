
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
 * Class Ul
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Ul)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper, Ul, phalcon, html_helper_ul, phalcon_html_helper_ol_ce, phalcon_html_helper_ul_method_entry, 0);

	return SUCCESS;
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Html_Helper_Ul, getTag)
{
	zval *this_ptr = getThis();



	RETURN_STRING("ul");
}

