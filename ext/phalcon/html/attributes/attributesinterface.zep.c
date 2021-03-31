
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
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
* Phalcon\Html\Attributes\AttributesInterface
*
* Interface Phalcon\Html\Attributes\AttributesInterface
*/
ZEPHIR_INIT_CLASS(Phalcon_Html_Attributes_AttributesInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Html\\Attributes, AttributesInterface, phalcon, html_attributes_attributesinterface, phalcon_html_attributes_attributesinterface_method_entry);

	return SUCCESS;

}

/**
 * Get Attributes
 */
ZEPHIR_DOC_METHOD(Phalcon_Html_Attributes_AttributesInterface, getAttributes);
/**
 * Set Attributes
 */
ZEPHIR_DOC_METHOD(Phalcon_Html_Attributes_AttributesInterface, setAttributes);
