
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
 * Handles a server request and produces a response.
 *
 * An HTTP request handler process an HTTP request in order to produce an
 * HTTP response.
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Server_AbstractRequestHandler)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\Server, AbstractRequestHandler, phalcon, http_server_abstractrequesthandler, phalcon_http_server_abstractrequesthandler_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_class_implements(phalcon_http_server_abstractrequesthandler_ce, 1, zephir_get_internal_ce(SL("psr\\http\\server\\requesthandlerinterface")));
	return SUCCESS;
}

/**
 * Handles a request and produces a response.
 *
 * May call other collaborating code to generate the response.
 */
PHP_METHOD(Phalcon_Http_Server_AbstractRequestHandler, handle)
{
}

