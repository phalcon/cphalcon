
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
 * Interface for Request methods
 *
 * Implementation of this file has been influenced by PHP FIG
 * @link    https://github.com/php-fig/http-message-util/
 * @license https://github.com/php-fig/http-message-util/blob/master/LICENSE
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Message_RequestMethodInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Http\\Message, RequestMethodInterface, phalcon, http_message_requestmethodinterface, NULL);

	zephir_declare_class_constant_string(phalcon_http_message_requestmethodinterface_ce, SL("METHOD_CONNECT"), "CONNECT");

	zephir_declare_class_constant_string(phalcon_http_message_requestmethodinterface_ce, SL("METHOD_DELETE"), "DELETE");

	zephir_declare_class_constant_string(phalcon_http_message_requestmethodinterface_ce, SL("METHOD_GET"), "GET");

	zephir_declare_class_constant_string(phalcon_http_message_requestmethodinterface_ce, SL("METHOD_HEAD"), "HEAD");

	zephir_declare_class_constant_string(phalcon_http_message_requestmethodinterface_ce, SL("METHOD_OPTIONS"), "OPTIONS");

	zephir_declare_class_constant_string(phalcon_http_message_requestmethodinterface_ce, SL("METHOD_PATCH"), "PATCH");

	zephir_declare_class_constant_string(phalcon_http_message_requestmethodinterface_ce, SL("METHOD_POST"), "POST");

	zephir_declare_class_constant_string(phalcon_http_message_requestmethodinterface_ce, SL("METHOD_PURGE"), "PURGE");

	zephir_declare_class_constant_string(phalcon_http_message_requestmethodinterface_ce, SL("METHOD_PUT"), "PUT");

	zephir_declare_class_constant_string(phalcon_http_message_requestmethodinterface_ce, SL("METHOD_TRACE"), "TRACE");

	return SUCCESS;
}

