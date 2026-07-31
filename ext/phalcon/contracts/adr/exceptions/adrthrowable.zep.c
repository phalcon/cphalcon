
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
 *
 * Based on the Action Domain Responder pattern
 * @link    https://pmjones.io/adr/
 */
/**
 * Base throwable contract for the ADR component. Every ADR exception implements
 * it, so callers can catch all ADR errors with a single type.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_ADR_Exceptions_ADRThrowable)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\ADR\\Exceptions, ADRThrowable, phalcon, contracts_adr_exceptions_adrthrowable, NULL);

	zend_class_implements(phalcon_contracts_adr_exceptions_adrthrowable_ce, 1, zend_ce_throwable);
	return SUCCESS;
}

