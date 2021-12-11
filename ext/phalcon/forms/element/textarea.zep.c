
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
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Component TEXTAREA for forms
 */
ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_TextArea)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Forms\\Element, TextArea, phalcon, forms_element_textarea, phalcon_forms_element_abstractelement_ce, NULL, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_forms_element_textarea_ce, SL("method"), "inputTextarea", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

