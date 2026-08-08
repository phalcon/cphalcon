
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Provides the implicit encryption flag and its accessor shared by the HTTP
 * cookie classes.
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Traits_EncryptionAwareTrait)
{
	ZEPHIR_REGISTER_TRAIT(Phalcon\\Http\\Traits, EncryptionAwareTrait, phalcon, http_traits_encryptionawaretrait, phalcon_http_traits_encryptionawaretrait_method_entry);

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_http_traits_encryptionawaretrait_ce, SL("useEncryption"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	return SUCCESS;
}

/**
 * Check if implicit encryption is being used
 */
PHP_METHOD(Phalcon_Http_Traits_EncryptionAwareTrait, isUsingEncryption)
{

	RETURN_MEMBER(getThis(), "useEncryption");
}

