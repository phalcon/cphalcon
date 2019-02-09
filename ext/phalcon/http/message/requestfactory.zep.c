
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
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Message_RequestFactory) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\Message, RequestFactory, phalcon, http_message_requestfactory, phalcon_http_message_requestfactory_method_entry, 0);

	zend_class_implements(phalcon_http_message_requestfactory_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("psr\\http\\message\\requestfactoryinterface")));
	return SUCCESS;

}

/**
 * Create a new request.
 *
 * @param string $method The HTTP method associated with the request.
 * @param UriInterface|string $uri The URI associated with the request.
 */
PHP_METHOD(Phalcon_Http_Message_RequestFactory, createRequest) {

	zval *method_param = NULL, *uri, uri_sub;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&uri_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &uri);

	zephir_get_strval(&method, method_param);



}

