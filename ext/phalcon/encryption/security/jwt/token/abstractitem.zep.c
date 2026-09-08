
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

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
 */
/**
 * Abstract helper class for Tokens
 *
 * @phpstan-import-type encryption_jwt_item_data from EncryptionTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Security_JWT_Token_AbstractItem)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Encryption\\Security\\JWT\\Token, AbstractItem, phalcon, encryption_security_jwt_token_abstractitem, phalcon_encryption_security_jwt_token_abstractitem_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @phpstan-var encryption_jwt_item_data
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_encryption_security_jwt_token_abstractitem_ce, SL("data"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	return SUCCESS;
}

PHP_METHOD(Phalcon_Encryption_Security_JWT_Token_AbstractItem, getEncoded)
{
	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("data", 4, 1);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 200, PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("encoded"), PH_NOISY | PH_READONLY, "phalcon/Encryption/Security/JWT/Token/AbstractItem.zep", 29);
	RETURN_CTORW(&_1);
}

