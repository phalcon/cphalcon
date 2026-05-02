
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
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/fcall.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * HMAC signing class
 */
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Security_JWT_Signer_Hmac)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Encryption\\Security\\JWT\\Signer, Hmac, phalcon, encryption_security_jwt_signer_hmac, phalcon_encryption_security_jwt_signer_abstractsigner_ce, phalcon_encryption_security_jwt_signer_hmac_method_entry, 0);

	return SUCCESS;
}

/**
 * Hmac constructor.
 *
 * @param string $algo
 *
 * @throws UnsupportedAlgorithmException
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Signer_Hmac, __construct)
{
	zval supported;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval algo_zv;
	zend_string *algo = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&algo_zv);
	ZVAL_UNDEF(&supported);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(algo)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!algo) {
		algo = zend_string_init(ZEND_STRL("sha512"), 0);
		ZVAL_STR(&algo_zv, algo);
	} else {
	ZVAL_STR_COPY(&algo_zv, algo);
	}
	ZEPHIR_INIT_VAR(&supported);
	zephir_create_array(&supported, 3, 0);
	add_assoc_long_ex(&supported, SL("sha512"), 1);
	add_assoc_long_ex(&supported, SL("sha384"), 1);
	add_assoc_long_ex(&supported, SL("sha256"), 1);
	if (!(zephir_array_isset(&supported, &algo_zv))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_encryption_security_jwt_exceptions_unsupportedalgorithmexception_ce, "Unsupported HMAC algorithm", "phalcon/Encryption/Security/JWT/Signer/Hmac.zep", 40);
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("algorithm"), &algo_zv);
	ZEPHIR_MM_RESTORE();
}

/**
 * Return the value that is used for the "alg" header
 *
 * @return string
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Signer_Hmac, getAlgHeader)
{
	zval _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("algorithm"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "sha");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "");
	zephir_fast_str_replace(&_0, &_2, &_3, &_1);
	ZEPHIR_CONCAT_SV(return_value, "HS", &_0);
	RETURN_MM();
}

/**
 * Sign a payload using the passphrase
 *
 * @param string $payload
 * @param string $passphrase
 *
 * @return string
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Signer_Hmac, sign)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval payload_zv, passphrase_zv;
	zend_string *payload = NULL, *passphrase = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&payload_zv);
	ZVAL_UNDEF(&passphrase_zv);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(payload)
		Z_PARAM_STR(passphrase)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&payload_zv, payload);
	ZVAL_STR_COPY(&passphrase_zv, passphrase);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethash", NULL, 263, &payload_zv, &passphrase_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Verify a passed source with a payload and passphrase
 *
 * @param string $source
 * @param string $payload
 * @param string $passphrase
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Signer_Hmac, verify)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval source_zv, payload_zv, passphrase_zv, _0;
	zend_string *source = NULL, *payload = NULL, *passphrase = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&source_zv);
	ZVAL_UNDEF(&payload_zv);
	ZVAL_UNDEF(&passphrase_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(source)
		Z_PARAM_STR(payload)
		Z_PARAM_STR(passphrase)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&source_zv, source);
	ZVAL_STR_COPY(&payload_zv, payload);
	ZVAL_STR_COPY(&passphrase_zv, passphrase);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "gethash", NULL, 263, &payload_zv, &passphrase_zv);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_hash_equals(&source_zv, &_0));
}

/**
 * Calculates a hash from the passed parameters
 *
 * @param string $payload
 * @param string $passphrase
 *
 * @return string
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Signer_Hmac, getHash)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval payload_zv, passphrase_zv, __$true, _0;
	zend_string *payload = NULL, *passphrase = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&payload_zv);
	ZVAL_UNDEF(&passphrase_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(payload)
		Z_PARAM_STR(passphrase)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&payload_zv, payload);
	ZVAL_STR_COPY(&passphrase_zv, passphrase);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getalgorithm", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("hash_hmac", NULL, 232, &_0, &payload_zv, &passphrase_zv, &__$true);
	zephir_check_call_status();
	RETURN_MM();
}

