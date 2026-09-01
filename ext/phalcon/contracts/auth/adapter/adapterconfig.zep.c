
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
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */
/**
 * Authentication adapter configuration contract.
 *
 * Per-adapter config shape is intentionally adapter-specific (e.g. Stream
 * exposes getFile(), Memory exposes getUsers()); the only field shared across
 * all adapters is the optional model class used during user hydration.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Auth_Adapter_AdapterConfig)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Auth\\Adapter, AdapterConfig, phalcon, contracts_auth_adapter_adapterconfig, phalcon_contracts_auth_adapter_adapterconfig_method_entry);

	return SUCCESS;
}

/**
 * Returns the user-model class name to hydrate, if configured.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Adapter_AdapterConfig, getModel);
