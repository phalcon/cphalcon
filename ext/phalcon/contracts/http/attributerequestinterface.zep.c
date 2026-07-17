
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
 * Extends the request contract with the native attribute bag.
 *
 * `getAttributes()` already exists on the concrete `Phalcon\Http\Request`; this
 * interface exposes it as a contract without touching `RequestInterface`
 * (adding a method there would break userland implementers). It lets consumers
 * type against the attribute-bearing request without depending on the concrete.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Http_AttributeRequestInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Http, AttributeRequestInterface, phalcon, contracts_http_attributerequestinterface, phalcon_contracts_http_attributerequestinterface_method_entry);

	zend_class_implements(phalcon_contracts_http_attributerequestinterface_ce, 1, phalcon_http_requestinterface_ce);
	return SUCCESS;
}

/**
 * Returns the request attribute bag.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Http_AttributeRequestInterface, getAttributes);
