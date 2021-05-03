
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Class Radio
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Input_Radio)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper\\Input, Radio, phalcon, html_helper_input_radio, phalcon_html_helper_input_checkbox_ce, NULL, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_html_helper_input_radio_ce, SL("type"), "radio", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

