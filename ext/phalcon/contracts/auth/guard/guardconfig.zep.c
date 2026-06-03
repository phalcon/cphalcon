
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
 * Authentication guard configuration contract.
 *
 * Per-guard config shape is intentionally guard-specific (e.g. Token exposes
 * getInputKey()/getStorageKey(); Session has no required config today).
 * The contract carries no methods of its own — it only marks the type so
 * AbstractGuard can accept any guard config uniformly.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Auth_Guard_GuardConfig)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Auth\\Guard, GuardConfig, phalcon, contracts_auth_guard_guardconfig, NULL);

	return SUCCESS;
}

