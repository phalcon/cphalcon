
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

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
 * Class Phalcon\Http\Link\Serializer\SerializerInterface
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Link_Serializer_SerializerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Html\\Link\\Serializer, SerializerInterface, phalcon, html_link_serializer_serializerinterface, phalcon_html_link_serializer_serializerinterface_method_entry);

	return SUCCESS;

}

/**
 * Serializer method
 */
ZEPHIR_DOC_METHOD(Phalcon_Html_Link_Serializer_SerializerInterface, serialize);
