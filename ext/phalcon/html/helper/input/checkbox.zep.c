
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
 *
 * Implementation of this file has been influenced by AuraPHP
 * @link    https://github.com/auraphp/Aura.Html
 * @license https://github.com/auraphp/Aura.Html/blob/2.x/LICENSE
 */
/**
 * Renders an `<input type="checkbox">`. Behavior (label wrapping, `unchecked`
 * companion, loose-by-default `checked` match) lives in `AbstractChecked`.
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Input_Checkbox)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper\\Input, Checkbox, phalcon, html_helper_input_checkbox, phalcon_html_helper_input_abstractchecked_ce, NULL, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_html_helper_input_checkbox_ce, SL("type"), "checkbox", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

