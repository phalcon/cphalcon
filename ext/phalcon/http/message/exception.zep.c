
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
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Http\Message\Exception
 *
 * Exceptions thrown in Phalcon\Http\Message/* will use this class
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Message_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Http\\Message, Exception, phalcon, http_message_exception, phalcon_exception_ce, NULL, 0);

	return SUCCESS;

}

