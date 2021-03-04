
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
* Phalcon\Html\Attributes\RenderInterface
*
* Interface Phalcon\Html\Attributes\RenderInterface
*/
ZEPHIR_INIT_CLASS(Phalcon_Html_Attributes_RenderInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Html\\Attributes, RenderInterface, phalcon, html_attributes_renderinterface, phalcon_html_attributes_renderinterface_method_entry);

	return SUCCESS;

}

/**
 * Generate a string represetation
 */
ZEPHIR_DOC_METHOD(Phalcon_Html_Attributes_RenderInterface, render);
