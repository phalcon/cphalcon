
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
 *
 * Based on the Action Domain Responder pattern
 * @link    https://pmjones.io/adr/
 */
/**
 * Generic exception for the ADR component, and the base for every typed ADR
 * exception.
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Exceptions_Exception)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\ADR\\Exceptions, Exception, phalcon, adr_exceptions_exception, zend_ce_exception, NULL, 0);

	zend_class_implements(phalcon_adr_exceptions_exception_ce, 1, phalcon_adr_exceptions_adrthrowable_ce);
	return SUCCESS;
}

