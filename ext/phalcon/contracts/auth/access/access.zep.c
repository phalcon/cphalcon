
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
 * @phpstan-type ForwardTarget array{
 *     controller?: string,
 *     action?: string,
 *     params?: array<int|string, mixed>,
 *     namespace?: string,
 *     task?: string,
 * }&array<string, mixed>
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Auth_Access_Access)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Auth\\Access, Access, phalcon, contracts_auth_access_access, phalcon_contracts_auth_access_access_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Access_Access, allowedIf);
/**
 * @return list<string>
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Access_Access, getExceptActions);
/**
 * @return list<string>
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Access_Access, getOnlyActions);
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Access_Access, isAllowed);
/**
 * @phpstan-return ForwardTarget|null
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Access_Access, redirectTo);
/**
 * @param list<string> $exceptActions
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Access_Access, setExceptActions);
/**
 * @param list<string> $onlyActions
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Access_Access, setOnlyActions);
