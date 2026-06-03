
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
 * Service locator for Phalcon\Auth access gates. Utilizes the container to
 * obtain the service. For the Phalcon\Container\Container one can use
 * autowiring. For the Phalcon\Di\Di, one needs to register the gates in it
 * to be used here.
 *
 * @extends AbstractLocator<Access>
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Auth_Access_AccessLocator)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\Access, AccessLocator, phalcon, auth_access_accesslocator, phalcon_support_abstractlocator_ce, phalcon_auth_access_accesslocator_method_entry, 0);

	return SUCCESS;
}

/**
 * @return class-string<\Throwable>
 */
PHP_METHOD(Phalcon_Auth_Access_AccessLocator, getExceptionClass)
{

	RETURN_STRING("Phalcon\\Auth\\Exception");
}

/**
 * @return class-string
 */
PHP_METHOD(Phalcon_Auth_Access_AccessLocator, getInterfaceClass)
{

	RETURN_STRING("Phalcon\\Contracts\\Auth\\Access\\Access");
}

/**
 * @return array<string, class-string<Access>>
 */
PHP_METHOD(Phalcon_Auth_Access_AccessLocator, getServices)
{

	zephir_create_array(return_value, 2, 0);
	add_assoc_stringl_ex(return_value, SL("auth"), SL("Phalcon\\Auth\\Access\\Auth"));
	add_assoc_stringl_ex(return_value, SL("guest"), SL("Phalcon\\Auth\\Access\\Guest"));
	return;
}

