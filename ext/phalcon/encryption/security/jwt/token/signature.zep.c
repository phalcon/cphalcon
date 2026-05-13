
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
#include "kernel/memory.h"
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
 * Signature class containing the encoded data and the hash.
 */
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Security_JWT_Token_Signature)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Encryption\\Security\\JWT\\Token, Signature, phalcon, encryption_security_jwt_token_signature, phalcon_encryption_security_jwt_token_abstractitem_ce, phalcon_encryption_security_jwt_token_signature_method_entry, 0);

	return SUCCESS;
}

/**
 * Signature constructor.
 *
 * @param string $hash
 * @param string $encoded
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Token_Signature, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval hash_zv, encoded_zv, _0, _1;
	zend_string *hash = NULL, *encoded = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&hash_zv);
	ZVAL_UNDEF(&encoded_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(hash)
		Z_PARAM_STR(encoded)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!hash) {
		hash = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&hash_zv);
		ZVAL_STR(&hash_zv, hash);
	} else {
	zephir_memory_observe(&hash_zv);
	ZVAL_STR_COPY(&hash_zv, hash);
	}
	if (!encoded) {
		encoded = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&encoded_zv);
		ZVAL_STR(&encoded_zv, encoded);
	} else {
	zephir_memory_observe(&encoded_zv);
	ZVAL_STR_COPY(&encoded_zv, encoded);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "encoded");
	zephir_update_property_array(this_ptr, SL("data"), &_0, &encoded_zv);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "hash");
	zephir_update_property_array(this_ptr, SL("data"), &_1, &hash_zv);
	ZEPHIR_MM_RESTORE();
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Token_Signature, getHash)
{
	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("hash"), PH_NOISY | PH_READONLY, "phalcon/Encryption/Security/JWT/Token/Signature.zep", 35);
	RETURN_CTORW(&_1);
}

