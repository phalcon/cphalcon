
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
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Class Date
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Input_Date)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper\\Input, Date, phalcon, html_helper_input_date, phalcon_html_helper_input_abstractinput_ce, NULL, 0);

	zend_declare_property_string(phalcon_html_helper_input_date_ce, SL("type"), "date", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

