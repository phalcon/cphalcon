
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
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Auth_Guard_BasicAuth)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Auth\\Guard, BasicAuth, phalcon, contracts_auth_guard_basicauth, phalcon_contracts_auth_guard_basicauth_method_entry);

	return SUCCESS;
}

/**
 * Authenticate against HTTP Basic credentials. Returns true on success.
 *
 * @param array<string, mixed> $extraConditions credentials merged on top of
 *                                              the basic-auth pair
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Guard_BasicAuth, basic);
/**
 * Like basic() but does not persist; returns the resolved user on success
 * or false on failure.
 *
 * @param array<string, mixed> $extraConditions
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Guard_BasicAuth, onceBasic);
