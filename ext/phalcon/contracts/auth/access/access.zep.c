
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
 * Access gates are Specifications: policies that decide whether the current
 * identity may run the given action. The enforcement point passes the
 * identity (the guard) and the request context on every call; gates hold no
 * reference to the auth manager.
 *
 * @phpstan-type ForwardTarget array{
 *     controller?: string,
 *     action?: string,
 *     params?: array<int|string, mixed>,
 *     namespace?: string,
 *     task?: string,
 * }&array<string, mixed>
 * @phpstan-type AccessContext array{
 *     handler?: string,
 *     module?: string,
 *     params?: array<int|string, mixed>,
 * }
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Auth_Access_Access)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Auth\\Access, Access, phalcon, contracts_auth_access_access, phalcon_contracts_auth_access_access_method_entry);

	return SUCCESS;
}

/**
 * @return list<string>
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Access_Access, getExceptActions);
/**
 * @return list<string>
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Access_Access, getOnlyActions);
/**
 * Whether the identity behind the guard may run the action.
 *
 * @phpstan-param AccessContext $context
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Access_Access, isAllowed);
/**
 * @phpstan-return ForwardTarget|null
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Access_Access, redirectTo);
/**
 * Exempts the listed action names from the gate; every other action is
 * checked. See setOnlyActions() for the gate-family divergence note.
 *
 * @param list<string> $exceptActions
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Access_Access, setExceptActions);
/**
 * Restricts the gate to the listed action names.
 *
 * Authoritative semantics: the gate applies only to the listed actions; an
 * action that is not listed passes without a check (and except() is the
 * inverse - the gate applies to every action except those listed).
 *
 * NOTE: the implementations currently diverge. The Acl gate follows the
 * authoritative semantics above, while the binary gates (Auth, Guest)
 * treat `only` as a whitelist - an unlisted action is denied even when the
 * base condition holds. The two gate families will be aligned in the next
 * major version; until then, choose the gate family deliberately, because
 * for an unlisted action they return opposite answers to the same call.
 *
 * @param list<string> $onlyActions
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Access_Access, setOnlyActions);
