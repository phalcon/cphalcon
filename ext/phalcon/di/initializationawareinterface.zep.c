
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

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
 * Interface for components that have `initialize()`
 */
ZEPHIR_INIT_CLASS(Phalcon_Di_InitializationAwareInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Di, InitializationAwareInterface, phalcon, di_initializationawareinterface, phalcon_di_initializationawareinterface_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Phalcon_Di_InitializationAwareInterface, initialize);
