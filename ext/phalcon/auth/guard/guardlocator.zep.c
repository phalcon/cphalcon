
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
#include "kernel/object.h"
#include "kernel/array.h"


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
 * Service locator for Phalcon\Auth guards. Utilizes the container to obtain
 * the service. For Phalcon\Container\Container one can use autowiring; for
 * Phalcon\Di\Di, register the guards in it before resolution.
 *
 * @extends AbstractLocator<Guard>
 */
ZEPHIR_INIT_CLASS(Phalcon_Auth_Guard_GuardLocator)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\Guard, GuardLocator, phalcon, auth_guard_guardlocator, phalcon_support_abstractlocator_ce, phalcon_auth_guard_guardlocator_method_entry, 0);

	return SUCCESS;
}

/**
 * @return class-string<\Throwable>
 */
PHP_METHOD(Phalcon_Auth_Guard_GuardLocator, getExceptionClass)
{

	RETURN_STRING("Phalcon\\Auth\\Exception");
}

/**
 * @return class-string
 */
PHP_METHOD(Phalcon_Auth_Guard_GuardLocator, getInterfaceClass)
{

	RETURN_STRING("Phalcon\\Contracts\\Auth\\Guard\\Guard");
}

/**
 * @return array<string, class-string<Guard>>
 */
PHP_METHOD(Phalcon_Auth_Guard_GuardLocator, getServices)
{

	zephir_create_array(return_value, 2, 0);
	add_assoc_stringl_ex(return_value, SL("session"), SL("Phalcon\\Auth\\Guard\\Session"));
	add_assoc_stringl_ex(return_value, SL("token"), SL("Phalcon\\Auth\\Guard\\Token"));
	return;
}

