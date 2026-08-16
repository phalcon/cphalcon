
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/operators.h"


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
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval algo_zv, _0$$3;
	zend_string *algo = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&algo_zv);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&supported);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("algorithm", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(algo)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!algo) {
		algo = zend_string_init(ZEND_STRL("sha512"), 0);
		zephir_memory_observe(&algo_zv);
		ZVAL_STR(&algo_zv, algo);
	} else {
		zephir_memory_observe(&algo_zv);
	ZVAL_STR_COPY(&algo_zv, algo);
	}
	ZEPHIR_INIT_VAR(&supported);
	zephir_create_array(&supported, 3, 0);
	add_assoc_long_ex(&supported, SL("sha512"), 1);
	add_assoc_long_ex(&supported, SL("sha384"), 1);
	add_assoc_long_ex(&supported, SL("sha256"), 1);
	if (!(zephir_array_isset_value(&supported, &algo_zv))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_encryption_security_jwt_exceptions_unsupportedhmacalgorithm_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Encryption/Security/JWT/Signer/Hmac.zep", 42);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 706, &algo_zv);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("algorithm", 9, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 706, PH_NOISY_CC | PH_READONLY);
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
	zephir_memory_observe(&payload_zv);
	ZVAL_STR_COPY(&payload_zv, payload);
	zephir_memory_observe(&passphrase_zv);
	ZVAL_STR_COPY(&passphrase_zv, passphrase);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethash", NULL, 0, &payload_zv, &passphrase_zv);
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
	zephir_memory_observe(&source_zv);
	ZVAL_STR_COPY(&source_zv, source);
	zephir_memory_observe(&payload_zv);
	ZVAL_STR_COPY(&payload_zv, payload);
	zephir_memory_observe(&passphrase_zv);
	ZVAL_STR_COPY(&passphrase_zv, passphrase);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "gethash", NULL, 0, &payload_zv, &passphrase_zv);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "phphashequals", NULL, 0, &source_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
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
	zval payload_zv, passphrase_zv, _0, _1;
	zend_string *payload = NULL, *passphrase = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&payload_zv);
	ZVAL_UNDEF(&passphrase_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(payload)
		Z_PARAM_STR(passphrase)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&payload_zv);
	ZVAL_STR_COPY(&payload_zv, payload);
	zephir_memory_observe(&passphrase_zv);
	ZVAL_STR_COPY(&passphrase_zv, passphrase);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getalgorithm", NULL, 0);
	zephir_check_call_status();
	ZVAL_BOOL(&_1, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "phphashhmac", NULL, 0, &_0, &payload_zv, &passphrase_zv, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $algorithm
 * @param string $data
 * @param bool   $binary
 *
 * @return string
 *
 * @link https://php.net/manual/en/function.hash.php
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Signer_Hmac, phpHash)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool binary;
	zval algorithm_zv, data_zv, *binary_param = NULL, _0;
	zend_string *algorithm = NULL, *data = NULL;

	ZVAL_UNDEF(&algorithm_zv);
	ZVAL_UNDEF(&data_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(algorithm)
		Z_PARAM_STR(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(binary)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		binary_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&algorithm_zv);
	ZVAL_STR_COPY(&algorithm_zv, algorithm);
	zephir_memory_observe(&data_zv);
	ZVAL_STR_COPY(&data_zv, data);
	if (!binary_param) {
		binary = 0;
	} else {
		}
	ZVAL_BOOL(&_0, (binary ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("hash", NULL, 167, &algorithm_zv, &data_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $knownString
 * @param string $userString
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.hash-equals.php
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Signer_Hmac, phpHashEquals)
{
	zval knownString_zv, userString_zv;
	zend_string *knownString = NULL, *userString = NULL;

	ZVAL_UNDEF(&knownString_zv);
	ZVAL_UNDEF(&userString_zv);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(knownString)
		Z_PARAM_STR(userString)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&knownString_zv, knownString);
	ZVAL_STR(&userString_zv, userString);
	RETURN_BOOL(zephir_hash_equals(&knownString_zv, &userString_zv));
}

/**
 * @param string $algorithm
 * @param string $data
 * @param string $key
 * @param bool   $binary
 *
 * @return string
 *
 * @link https://php.net/manual/en/function.hash-hmac.php
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Signer_Hmac, phpHashHmac)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool binary;
	zval algorithm_zv, data_zv, key_zv, *binary_param = NULL, _0;
	zend_string *algorithm = NULL, *data = NULL, *key = NULL;

	ZVAL_UNDEF(&algorithm_zv);
	ZVAL_UNDEF(&data_zv);
	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_STR(algorithm)
		Z_PARAM_STR(data)
		Z_PARAM_STR(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(binary)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 3) {
		binary_param = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&algorithm_zv);
	ZVAL_STR_COPY(&algorithm_zv, algorithm);
	zephir_memory_observe(&data_zv);
	ZVAL_STR_COPY(&data_zv, data);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	if (!binary_param) {
		binary = 0;
	} else {
		}
	ZVAL_BOOL(&_0, (binary ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("hash_hmac", NULL, 168, &algorithm_zv, &data_zv, &key_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

