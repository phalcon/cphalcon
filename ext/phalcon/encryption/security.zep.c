
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * This component provides a set of functions to improve the security in Phalcon
 * applications
 *
 *```php
 * $login    = $this->request->getPost("login");
 * $password = $this->request->getPost("password");
 *
 * $user = Users::findFirstByLogin($login);
 *
 * if ($user) {
 *     if ($this->security->checkHash($password, $user->password)) {
 *         // The password is valid
 *     }
 * }
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Security)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Encryption, Security, phalcon, encryption_security, phalcon_di_abstractinjectionaware_ce, phalcon_encryption_security_method_entry, 0);

	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_encryption_security_ce, SL("defaultHash"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_encryption_security_ce, SL("numberBytes"), 16, ZEND_ACC_PROTECTED);
	/**
	 * @var Random
	 */
	zend_declare_property_null(phalcon_encryption_security_ce, SL("random"), ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_encryption_security_ce, SL("requestToken"), ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_encryption_security_ce, SL("token"), ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_encryption_security_ce, SL("tokenKey"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_encryption_security_ce, SL("tokenKeySessionId"), "$PHALCON/CSRF/KEY$", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_encryption_security_ce, SL("tokenValueSessionId"), "$PHALCON/CSRF$", ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_encryption_security_ce, SL("workFactor"), 10, ZEND_ACC_PROTECTED);
	/**
	 * @var SessionInterface|null
	 */
	zend_declare_property_null(phalcon_encryption_security_ce, SL("localSession"), ZEND_ACC_PRIVATE);
	/**
	 * @var RequestInterface|null
	 */
	zend_declare_property_null(phalcon_encryption_security_ce, SL("localRequest"), ZEND_ACC_PRIVATE);
	zephir_declare_class_constant_long(phalcon_encryption_security_ce, SL("CRYPT_ARGON2I"), 10);

	zephir_declare_class_constant_long(phalcon_encryption_security_ce, SL("CRYPT_ARGON2ID"), 11);

	zephir_declare_class_constant_long(phalcon_encryption_security_ce, SL("CRYPT_BCRYPT"), 0);

	zephir_declare_class_constant_long(phalcon_encryption_security_ce, SL("CRYPT_DEFAULT"), 0);

	zephir_declare_class_constant_long(phalcon_encryption_security_ce, SL("CRYPT_BLOWFISH"), 4);

	zephir_declare_class_constant_long(phalcon_encryption_security_ce, SL("CRYPT_BLOWFISH_A"), 5);

	zephir_declare_class_constant_long(phalcon_encryption_security_ce, SL("CRYPT_BLOWFISH_X"), 6);

	zephir_declare_class_constant_long(phalcon_encryption_security_ce, SL("CRYPT_BLOWFISH_Y"), 7);

	zephir_declare_class_constant_long(phalcon_encryption_security_ce, SL("CRYPT_EXT_DES"), 2);

	zephir_declare_class_constant_long(phalcon_encryption_security_ce, SL("CRYPT_MD5"), 3);

	zephir_declare_class_constant_long(phalcon_encryption_security_ce, SL("CRYPT_SHA256"), 8);

	zephir_declare_class_constant_long(phalcon_encryption_security_ce, SL("CRYPT_SHA512"), 9);

	zephir_declare_class_constant_long(phalcon_encryption_security_ce, SL("CRYPT_STD_DES"), 1);

	return SUCCESS;
}

/**
 */
PHP_METHOD(Phalcon_Encryption_Security, getWorkFactor)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "workFactor");
}

/**
 * Security constructor.
 *
 * @param SessionInterface|null $session
 * @param RequestInterface|null $request
 */
PHP_METHOD(Phalcon_Encryption_Security, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *session = NULL, session_sub, *request = NULL, request_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&session_sub);
	ZVAL_UNDEF(&request_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(session, phalcon_session_managerinterface_ce)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(request, phalcon_http_requestinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &session, &request);
	if (!session) {
		session = &session_sub;
		session = &__$null;
	}
	if (!request) {
		request = &request_sub;
		request = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_encryption_security_random_ce);
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	zephir_update_property_zval(this_ptr, ZEND_STRL("random"), &_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("localRequest"), request);
	zephir_update_property_zval(this_ptr, ZEND_STRL("localSession"), session);
	ZEPHIR_MM_RESTORE();
}

/**
 * Checks a plain text password and its hash version to check if the
 * password matches
 *
 * @param string $password
 * @param string $passwordHash
 * @param int    $maxPassLength
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Encryption_Security, checkHash)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long maxPassLength, ZEPHIR_LAST_CALL_STATUS;
	zval *password_param = NULL, *passwordHash_param = NULL, *maxPassLength_param = NULL;
	zval password, passwordHash;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&password);
	ZVAL_UNDEF(&passwordHash);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(password)
		Z_PARAM_STR(passwordHash)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(maxPassLength)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &password_param, &passwordHash_param, &maxPassLength_param);
	zephir_get_strval(&password, password_param);
	zephir_get_strval(&passwordHash, passwordHash_param);
	if (!maxPassLength_param) {
		maxPassLength = 0;
	} else {
		maxPassLength = zephir_get_intval(maxPassLength_param);
	}


	_0 = maxPassLength > 0;
	if (_0) {
		_0 = zephir_fast_strlen_ev(&password) > maxPassLength;
	}
	if (_0) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_RETURN_CALL_FUNCTION("password_verify", NULL, 260, &password, &passwordHash);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Check if the CSRF token sent in the request is the same that the current
 * in session
 *
 * @param string|null $tokenKey
 * @param mixed|null  $tokenValue
 * @param bool        $destroyIfValid
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Encryption_Security, checkToken)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool destroyIfValid, _1, _2;
	zval *tokenKey_param = NULL, *tokenValue = NULL, tokenValue_sub, *destroyIfValid_param = NULL, __$null, equals, knownToken, userToken, _0;
	zval tokenKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tokenKey);
	ZVAL_UNDEF(&tokenValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&equals);
	ZVAL_UNDEF(&knownToken);
	ZVAL_UNDEF(&userToken);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(tokenKey)
		Z_PARAM_ZVAL_OR_NULL(tokenValue)
		Z_PARAM_BOOL(destroyIfValid)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &tokenKey_param, &tokenValue, &destroyIfValid_param);
	if (!tokenKey_param) {
		ZEPHIR_INIT_VAR(&tokenKey);
	} else {
		zephir_get_strval(&tokenKey, tokenKey_param);
	}
	if (!tokenValue) {
		tokenValue = &tokenValue_sub;
		tokenValue = &__$null;
	}
	if (!destroyIfValid_param) {
		destroyIfValid = 1;
	} else {
		destroyIfValid = zephir_get_boolval(destroyIfValid_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "processtokenkey", NULL, 261, &tokenKey);
	zephir_check_call_status();
	zephir_get_strval(&tokenKey, &_0);
	if (!(!(ZEPHIR_IS_EMPTY(&tokenKey)))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&userToken, this_ptr, "processusertoken", NULL, 262, &tokenKey, tokenValue);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&knownToken, this_ptr, "getrequesttoken", NULL, 0);
	zephir_check_call_status();
	_1 = Z_TYPE_P(&knownToken) == IS_NULL;
	if (!(_1)) {
		_1 = Z_TYPE_P(&userToken) == IS_NULL;
	}
	if (_1) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&equals);
	ZEPHIR_INIT_NVAR(&equals);
	ZVAL_BOOL(&equals, zephir_hash_equals(&knownToken, &userToken));
	_2 = zephir_is_true(&equals);
	if (_2) {
		_2 = destroyIfValid;
	}
	if (_2) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "destroytoken", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&equals);
}

/**
 * Computes a HMAC
 *
 * @param string $data
 * @param string $key
 * @param string $algo
 * @param bool   $raw
 *
 * @return string
 * @throws Exception
 */
PHP_METHOD(Phalcon_Encryption_Security, computeHmac)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool raw;
	zval *data_param = NULL, *key_param = NULL, *algo_param = NULL, *raw_param = NULL, hmac, _0, _1$$3, _2$$3, _3$$3;
	zval data, key, algo;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&algo);
	ZVAL_UNDEF(&hmac);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_STR(data)
		Z_PARAM_STR(key)
		Z_PARAM_STR(algo)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(raw)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &data_param, &key_param, &algo_param, &raw_param);
	zephir_get_strval(&data, data_param);
	zephir_get_strval(&key, key_param);
	zephir_get_strval(&algo, algo_param);
	if (!raw_param) {
		raw = 0;
	} else {
		raw = zephir_get_boolval(raw_param);
	}


	ZVAL_BOOL(&_0, (raw ? 1 : 0));
	ZEPHIR_CALL_FUNCTION(&hmac, "hash_hmac", NULL, 243, &algo, &data, &key, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(!zephir_is_true(&hmac))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_encryption_security_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "Unknown hashing algorithm: %s");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 140, &_2$$3, &algo);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 31, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Encryption/Security.zep", 219);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&hmac);
}

/**
 * Removes the value of the CSRF token and key from session
 */
PHP_METHOD(Phalcon_Encryption_Security, destroyToken)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$null, session, _0, _1, _2$$3, _3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "session");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "localSession");
	ZEPHIR_CALL_METHOD(&session, this_ptr, "getlocalservice", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	if (UNEXPECTED(zephir_is_true(&session))) {
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("tokenKeySessionId"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &session, "remove", NULL, 0, &_2$$3);
		zephir_check_call_status();
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("tokenValueSessionId"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &session, "remove", NULL, 0, &_3$$3);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("token"), &__$null);
	zephir_update_property_zval(this_ptr, ZEND_STRL("tokenKey"), &__$null);
	zephir_update_property_zval(this_ptr, ZEND_STRL("requestToken"), &__$null);
	RETURN_THIS();
}

/**
 * Returns the default hash
 *
 * @return int
 */
PHP_METHOD(Phalcon_Encryption_Security, getDefaultHash)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "defaultHash");
}

/**
 * Returns information regarding a hash
 *
 * @param string $hash
 *
 * @return array
 */
PHP_METHOD(Phalcon_Encryption_Security, getHashInformation)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *hash_param = NULL;
	zval hash;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&hash);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(hash)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &hash_param);
	zephir_get_strval(&hash, hash_param);


	ZEPHIR_RETURN_CALL_FUNCTION("password_get_info", NULL, 263, &hash);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns a secure random number generator instance
 */
PHP_METHOD(Phalcon_Encryption_Security, getRandom)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "random");
}

/**
 * Returns a number of bytes to be generated by the openssl pseudo random
 * generator
 */
PHP_METHOD(Phalcon_Encryption_Security, getRandomBytes)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "numberBytes");
}

/**
 * Returns the value of the CSRF token for the current request.
 */
PHP_METHOD(Phalcon_Encryption_Security, getRequestToken)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("requestToken"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsessiontoken", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_MEMBER(getThis(), "requestToken");
}

/**
 * Returns the value of the CSRF token in session
 *
 * @return string|null
 */
PHP_METHOD(Phalcon_Encryption_Security, getSessionToken)
{
	zval session, _0, _1, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "session");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "localSession");
	ZEPHIR_CALL_METHOD(&session, this_ptr, "getlocalservice", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	if (UNEXPECTED(zephir_is_true(&session))) {
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("tokenValueSessionId"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_RETURN_CALL_METHOD(&session, "get", NULL, 0, &_2$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_NULL();
}

/**
 * Generate a >22-length pseudo random string to be used as salt for
 * passwords
 *
 * @param int $numberBytes
 *
 * @return string
 * @throws Exception
 */
PHP_METHOD(Phalcon_Encryption_Security, getSaltBytes)
{
	zend_bool _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *numberBytes_param = NULL, safeBytes, _0$$3, _1$$4, _2$$4;
	zend_long numberBytes, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&safeBytes);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(numberBytes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &numberBytes_param);
	if (!numberBytes_param) {
		numberBytes = 0;
	} else {
		numberBytes = zephir_get_intval(numberBytes_param);
	}


	if (!(numberBytes)) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("numberBytes"), PH_NOISY_CC | PH_READONLY);
		numberBytes = zephir_get_numberval(&_0$$3);
	}
	while (1) {
		zephir_read_property(&_1$$4, this_ptr, ZEND_STRL("random"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_2$$4, numberBytes);
		ZEPHIR_CALL_METHOD(&safeBytes, &_1$$4, "base64safe", NULL, 0, &_2$$4);
		zephir_check_call_status();
		_3$$4 = zephir_is_true(&safeBytes);
		if (_3$$4) {
			_3$$4 = zephir_fast_strlen_ev(&safeBytes) >= numberBytes;
		}
		if (_3$$4) {
			break;
		}
	}
	RETURN_CCTOR(&safeBytes);
}

/**
 * Generates a pseudo random token value to be used as input's value in a
 * CSRF check
 *
 * @return string
 * @throws Exception
 */
PHP_METHOD(Phalcon_Encryption_Security, getToken)
{
	zval session, _0, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3, _6$$3, _7$$4, _8$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("token"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "getsessiontoken", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("requestToken"), &_1$$3);
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("random"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("numberBytes"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_3$$3, &_2$$3, "base64safe", NULL, 0, &_4$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("token"), &_3$$3);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "session");
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "localSession");
		ZEPHIR_CALL_METHOD(&session, this_ptr, "getlocalservice", NULL, 0, &_5$$3, &_6$$3);
		zephir_check_call_status();
		if (Z_TYPE_P(&session) != IS_NULL) {
			zephir_read_property(&_7$$4, this_ptr, ZEND_STRL("tokenValueSessionId"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_8$$4, this_ptr, ZEND_STRL("token"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &session, "set", NULL, 0, &_7$$4, &_8$$4);
			zephir_check_call_status();
		}
	}
	RETURN_MM_MEMBER(getThis(), "token");
}

/**
 * Generates a pseudo random token key to be used as input's name in a CSRF
 * check
 *
 * @return string|null
 * @throws Exception
 */
PHP_METHOD(Phalcon_Encryption_Security, getTokenKey)
{
	zval session, _0, _1$$3, _2$$3, _3$$4, _4$$4, _5$$4, _6$$4, _7$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("tokenKey"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "session");
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "localSession");
		ZEPHIR_CALL_METHOD(&session, this_ptr, "getlocalservice", NULL, 0, &_1$$3, &_2$$3);
		zephir_check_call_status();
		if (Z_TYPE_P(&session) != IS_NULL) {
			zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("random"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_5$$4, this_ptr, ZEND_STRL("numberBytes"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_4$$4, &_3$$4, "base64safe", NULL, 0, &_5$$4);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, ZEND_STRL("tokenKey"), &_4$$4);
			zephir_read_property(&_6$$4, this_ptr, ZEND_STRL("tokenKeySessionId"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_7$$4, this_ptr, ZEND_STRL("tokenKey"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &session, "set", NULL, 0, &_6$$4, &_7$$4);
			zephir_check_call_status();
		}
	}
	RETURN_MM_MEMBER(getThis(), "tokenKey");
}

/**
 * Creates a password hash using bcrypt with a pseudo random salt
 *
 * @param string $password
 * @param array  $options
 *
 * @return string
 */
PHP_METHOD(Phalcon_Encryption_Security, hash)
{
	zend_bool legacy = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, bytes = 0;
	zval options;
	zval *password_param = NULL, *options_param = NULL, algorithm, arguments, cost, formatted, prefix, salt, _0, _1, _6, _2$$6, _3$$7, _4$$9, _5$$9;
	zval password;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&password);
	ZVAL_UNDEF(&algorithm);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&cost);
	ZVAL_UNDEF(&formatted);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&salt);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&options);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(password)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &password_param, &options_param);
	zephir_get_strval(&password, password_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_CALL_METHOD(&cost, this_ptr, "processcost", NULL, 264, &options);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "%02s");
	ZEPHIR_CALL_FUNCTION(&formatted, "sprintf", NULL, 140, &_0, &cost);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&prefix);
	ZVAL_STRING(&prefix, "");
	bytes = 22;
	legacy = 1;
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("defaultHash"), PH_NOISY_CC);
	do {
		if (ZEPHIR_IS_LONG(&_1, 3)) {
			ZEPHIR_INIT_NVAR(&prefix);
			ZVAL_STRING(&prefix, "$1$");
			bytes = 12;
			break;
		}
		if (ZEPHIR_IS_LONG(&_1, 8)) {
			ZEPHIR_INIT_NVAR(&prefix);
			ZVAL_STRING(&prefix, "$5$");
			bytes = 16;
			break;
		}
		if (ZEPHIR_IS_LONG(&_1, 9)) {
			ZEPHIR_INIT_NVAR(&prefix);
			ZVAL_STRING(&prefix, "$6$");
			bytes = 16;
			break;
		}
		if (ZEPHIR_IS_LONG(&_1, 5)) {
			ZEPHIR_INIT_VAR(&_2$$6);
			ZVAL_STRING(&_2$$6, "$2a$%s$");
			ZEPHIR_CALL_FUNCTION(&prefix, "sprintf", NULL, 140, &_2$$6, &formatted);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_LONG(&_1, 6)) {
			ZEPHIR_INIT_VAR(&_3$$7);
			ZVAL_STRING(&_3$$7, "$2x$%s$");
			ZEPHIR_CALL_FUNCTION(&prefix, "sprintf", NULL, 140, &_3$$7, &formatted);
			zephir_check_call_status();
			break;
		}
		legacy = 0;
		break;
	} while(0);

	if (UNEXPECTED(legacy)) {
		ZVAL_LONG(&_5$$9, bytes);
		ZEPHIR_CALL_METHOD(&_4$$9, this_ptr, "getsaltbytes", NULL, 0, &_5$$9);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&salt);
		ZEPHIR_CONCAT_VVS(&salt, &prefix, &_4$$9, "$");
		ZEPHIR_RETURN_CALL_FUNCTION("crypt", NULL, 265, &password, &salt);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 1, 0);
	zephir_array_update_string(&_6, SL("cost"), &cost, PH_COPY | PH_SEPARATE);
	ZEPHIR_CPY_WRT(&options, &_6);
	ZEPHIR_CALL_METHOD(&algorithm, this_ptr, "processalgorithm", NULL, 266);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&arguments, this_ptr, "processargonoptions", NULL, 267, &options);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("password_hash", NULL, 268, &password, &algorithm, &arguments);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Checks if a password hash is a valid bcrypt's hash
 *
 * @param string $passwordHash
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Encryption_Security, isLegacyHash)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *passwordHash_param = NULL;
	zval passwordHash;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&passwordHash);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(passwordHash)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &passwordHash_param);
	zephir_get_strval(&passwordHash, passwordHash_param);


	RETURN_MM_BOOL(zephir_start_with_str(&passwordHash, SL("$2a$")));
}

/**
 * Sets the default hash
 *
 * @param int $defaultHash
 *
 * @return Security
 */
PHP_METHOD(Phalcon_Encryption_Security, setDefaultHash)
{
	zval *defaultHash_param = NULL, _0;
	zend_long defaultHash;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(defaultHash)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &defaultHash_param);
	defaultHash = zephir_get_intval(defaultHash_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, defaultHash);
	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultHash"), &_0);
	RETURN_THISW();
}

/**
 * Sets a number of bytes to be generated by the openssl pseudo random
 * generator
 *
 * @param int $randomBytes
 *
 * @return Security
 */
PHP_METHOD(Phalcon_Encryption_Security, setRandomBytes)
{
	zval *randomBytes_param = NULL, _0;
	zend_long randomBytes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(randomBytes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &randomBytes_param);
	if (UNEXPECTED(Z_TYPE_P(randomBytes_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'randomBytes' must be of the type int"));
		RETURN_NULL();
	}
	randomBytes = Z_LVAL_P(randomBytes_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, randomBytes);
	zephir_update_property_zval(this_ptr, ZEND_STRL("numberBytes"), &_0);
	RETURN_THISW();
}

/**
 * Sets the work factor
 *
 * @param int $workFactor
 *
 * @return Security
 */
PHP_METHOD(Phalcon_Encryption_Security, setWorkFactor)
{
	zval *workFactor_param = NULL, _0;
	zend_long workFactor;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(workFactor)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &workFactor_param);
	workFactor = zephir_get_intval(workFactor_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, workFactor);
	zephir_update_property_zval(this_ptr, ZEND_STRL("workFactor"), &_0);
	RETURN_THISW();
}

/**
 * @param string $name
 * @param string $property
 *
 * @return RequestInterface|SessionInterface|null
 */
PHP_METHOD(Phalcon_Encryption_Security, getLocalService)
{
	zend_bool _1, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *property_param = NULL, _0, _2, _4, _5, _8, _6$$3, _7$$3;
	zval name, property;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_STR(property)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &property_param);
	zephir_get_strval(&name, name_param);
	zephir_get_strval(&property, property_param);


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property_zval(&_0, this_ptr, &property, PH_NOISY_CC);
	_1 = Z_TYPE_P(&_0) == IS_NULL;
	if (_1) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
		_1 = Z_TYPE_P(&_2) != IS_NULL;
	}
	_3 = _1;
	if (_3) {
		zephir_read_property(&_4, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_5, &_4, "has", NULL, 0, &name);
		zephir_check_call_status();
		_3 = ZEPHIR_IS_TRUE_IDENTICAL(&_5);
	}
	if (_3) {
		zephir_read_property(&_6$$3, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_7$$3, &_6$$3, "getshared", NULL, 0, &name);
		zephir_check_call_status();
		zephir_update_property_zval_zval(this_ptr, &property, &_7$$3);
	}
	ZEPHIR_OBS_VAR(&_8);
	zephir_read_property_zval(&_8, this_ptr, &property, PH_NOISY_CC);
	RETURN_CCTOR(&_8);
}

/**
 * Checks the algorithm for `password_hash`. If it is argon based, it
 * returns the relevant constant
 *
 * @return string
 */
PHP_METHOD(Phalcon_Encryption_Security, processAlgorithm)
{
	zval algorithm, _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&algorithm);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&algorithm);
	ZVAL_STRING(&algorithm, "2y");
	zephir_read_property(&_0, this_ptr, ZEND_STRL("defaultHash"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("defaultHash"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_LONG_IDENTICAL(&_0, 10)) {
		ZEPHIR_INIT_NVAR(&algorithm);
		ZVAL_STRING(&algorithm, "argon2i");
	} else if (ZEPHIR_IS_LONG_IDENTICAL(&_1, 11)) {
		ZEPHIR_INIT_NVAR(&algorithm);
		ZVAL_STRING(&algorithm, "argon2id");
	}
	RETURN_CCTOR(&algorithm);
}

/**
 * We check if the algorithm is Argon based. If yes, options are set for
 * `password_hash` such as `memory_cost`, `time_cost` and `threads`
 *
 * @param array $options
 *
 * @return array
 */
PHP_METHOD(Phalcon_Encryption_Security, processArgonOptions)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL, value, _0, _2;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);
	zephir_get_arrval(&options, options_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("defaultHash"), PH_NOISY_CC | PH_READONLY);
	_1 = ZEPHIR_IS_LONG_IDENTICAL(&_0, 10);
	if (!(_1)) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("defaultHash"), PH_NOISY_CC | PH_READONLY);
		_1 = ZEPHIR_IS_LONG_IDENTICAL(&_2, 11);
	}
	if (_1) {
		ZEPHIR_OBS_VAR(&value);
		if (!(zephir_array_isset_string_fetch(&value, &options, SL("memory_cost"), 0))) {
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_LONG(&value, 65536);
		}
		zephir_array_update_string(&options, SL("memory_cost"), &value, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&value);
		if (!(zephir_array_isset_string_fetch(&value, &options, SL("time_cost"), 0))) {
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_LONG(&value, 4);
		}
		zephir_array_update_string(&options, SL("time_cost"), &value, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&value);
		if (!(zephir_array_isset_string_fetch(&value, &options, SL("threads"), 0))) {
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_LONG(&value, 1);
		}
		zephir_array_update_string(&options, SL("threads"), &value, PH_COPY | PH_SEPARATE);
	}
	RETURN_CTOR(&options);
}

/**
 * Checks the options array for `cost`. If not defined it is set to 10.
 * It also checks the cost if it is between 4 and 31
 *
 * @param array $options
 *
 * @return int
 */
PHP_METHOD(Phalcon_Encryption_Security, processCost)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL, cost;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&cost);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_OBS_VAR(&cost);
	if (!(zephir_array_isset_string_fetch(&cost, &options, SL("cost"), 0))) {
		ZEPHIR_INIT_NVAR(&cost);
		ZVAL_LONG(&cost, 10);
	}
	if (ZEPHIR_LT_LONG(&cost, 4)) {
		ZEPHIR_INIT_NVAR(&cost);
		ZVAL_LONG(&cost, 4);
	}
	if (ZEPHIR_GT_LONG(&cost, 31)) {
		ZEPHIR_INIT_NVAR(&cost);
		ZVAL_LONG(&cost, 31);
	}
	RETURN_CCTOR(&cost);
}

/**
 * @param string|null $tokenKey
 *
 * @return string|null
 */
PHP_METHOD(Phalcon_Encryption_Security, processTokenKey)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tokenKey_param = NULL, key, session, _0, _1, _3$$3;
	zval tokenKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tokenKey);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(tokenKey)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &tokenKey_param);
	if (!tokenKey_param) {
		ZEPHIR_INIT_VAR(&tokenKey);
	} else {
		zephir_get_strval(&tokenKey, tokenKey_param);
	}


	ZEPHIR_CPY_WRT(&key, &tokenKey);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "session");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "localSession");
	ZEPHIR_CALL_METHOD(&session, this_ptr, "getlocalservice", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	_2 = Z_TYPE_P(&session) != IS_NULL;
	if (_2) {
		_2 = 1 == ZEPHIR_IS_EMPTY(&key);
	}
	if (_2) {
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("tokenKeySessionId"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&key, &session, "get", NULL, 0, &_3$$3);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&key);
}

/**
 * @param string      $tokenKey
 * @param string|null $tokenValue
 *
 * @return string|null
 */
PHP_METHOD(Phalcon_Encryption_Security, processUserToken)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tokenKey_param = NULL, *tokenValue_param = NULL, request, userToken, _0$$3, _1$$3, _2$$4;
	zval tokenKey, tokenValue;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tokenKey);
	ZVAL_UNDEF(&tokenValue);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&userToken);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(tokenKey)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(tokenValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &tokenKey_param, &tokenValue_param);
	zephir_get_strval(&tokenKey, tokenKey_param);
	if (!tokenValue_param) {
		ZEPHIR_INIT_VAR(&tokenValue);
	} else {
		zephir_get_strval(&tokenValue, tokenValue_param);
	}


	ZEPHIR_CPY_WRT(&userToken, &tokenValue);
	if (!(!(ZEPHIR_IS_EMPTY(&tokenValue)))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "request");
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "localRequest");
		ZEPHIR_CALL_METHOD(&request, this_ptr, "getlocalservice", NULL, 0, &_0$$3, &_1$$3);
		zephir_check_call_status();
		if (Z_TYPE_P(&request) != IS_NULL) {
			ZEPHIR_INIT_VAR(&_2$$4);
			ZVAL_STRING(&_2$$4, "string");
			ZEPHIR_CALL_METHOD(&userToken, &request, "getpost", NULL, 0, &tokenKey, &_2$$4);
			zephir_check_call_status();
		}
	}
	RETURN_CCTOR(&userToken);
}

