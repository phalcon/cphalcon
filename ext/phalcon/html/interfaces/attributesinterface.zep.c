
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

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
* Phalcon\Html\Interfaces\AttributesInterface
*
* Interface Phalcon\Html\Interfaces\AttributesInterface
*/
ZEPHIR_INIT_CLASS(Phalcon_Html_Interfaces_AttributesInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Html\\Interfaces, AttributesInterface, phalcon, html_interfaces_attributesinterface, phalcon_html_interfaces_attributesinterface_method_entry);

	return SUCCESS;

}

/**
 * Get Attributes
 */
ZEPHIR_DOC_METHOD(Phalcon_Html_Interfaces_AttributesInterface, getAttributes);

/**
 * Set Attributes
 */
ZEPHIR_DOC_METHOD(Phalcon_Html_Interfaces_AttributesInterface, setAttributes);

