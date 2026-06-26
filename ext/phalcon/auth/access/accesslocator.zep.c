
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
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
 * to be used here (the binary gates also resolve unregistered through Di's
 * class builder).
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
 * Resolve a fresh gate instance from the container.
 *
 * Gates carry per-activation state (the only/except action filters), so
 * resolution must yield a fresh instance: new() on the Container
 * bypasses the instance cache; on the legacy Di, get() builds
 * unregistered classes and non-shared services fresh (register gates
 * non-shared).
 *
 * @return Access
 */
PHP_METHOD(Phalcon_Auth_Access_AccessLocator, newInstance)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, _0, _1, _2;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getservice", NULL, 0, &name_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_auth_internal_containerresolver_ce, "resolvefresh", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	RETURN_CCTOR(&_0);
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

	zephir_create_array(return_value, 3, 0);
	add_assoc_stringl_ex(return_value, SL("acl"), SL("Phalcon\\Auth\\Access\\Acl"));
	add_assoc_stringl_ex(return_value, SL("auth"), SL("Phalcon\\Auth\\Access\\Auth"));
	add_assoc_stringl_ex(return_value, SL("guest"), SL("Phalcon\\Auth\\Access\\Guest"));
	return;
}

