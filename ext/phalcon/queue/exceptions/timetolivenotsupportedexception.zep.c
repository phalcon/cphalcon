
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
 * Thrown when the transport does not support a message time to live.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Exceptions_TimeToLiveNotSupportedException)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Queue\\Exceptions, TimeToLiveNotSupportedException, phalcon, queue_exceptions_timetolivenotsupportedexception, phalcon_queue_exceptions_exception_ce, NULL, 0);

	return SUCCESS;
}

