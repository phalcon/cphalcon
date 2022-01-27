
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
 * Participant in processing a server request and response.
 *
 * An HTTP middleware component participates in processing an HTTP message:
 * by acting on the request, generating the response, or forwarding the
 * request to a subsequent middleware and possibly acting on its response.
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Server_AbstractMiddleware)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\Server, AbstractMiddleware, phalcon, http_server_abstractmiddleware, phalcon_http_server_abstractmiddleware_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_class_implements(phalcon_http_server_abstractmiddleware_ce, 1, zephir_get_internal_ce(SL("psr\\http\\server\\middlewareinterface")));
	return SUCCESS;
}

/**
 * Process an incoming server request.
 *
 * Processes an incoming server request in order to produce a response.
 * If unable to produce the response itself, it may delegate to the provided
 * request handler to do so.
 */
PHP_METHOD(Phalcon_Http_Server_AbstractMiddleware, process)
{
}

