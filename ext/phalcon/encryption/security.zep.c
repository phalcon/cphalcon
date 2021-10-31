
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
	 * @var int|null
	 */
	zend_declare_property_null(phalcon_encryption_security_ce, SL("defaultHash"), ZEND_ACC_PROTECTED);
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
 * Phalcon\Security constructor
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
 */
PHP_METHOD(Phalcon_Encryption_Security, checkHash)
{
	unsigned char _4$$4;
	long _3;
	zend_bool _0;
	char ch = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long maxPassLength, ZEPHIR_LAST_CALL_STATUS, i = 0, sum = 0, cryptedLength = 0, passwordLength = 0;
	zval *password_param = NULL, *passwordHash_param = NULL, *maxPassLength_param = NULL, _1;
	zval password, passwordHash, cryptedHash, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&password);
	ZVAL_UNDEF(&passwordHash);
	ZVAL_UNDEF(&cryptedHash);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1);
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
	ZEPHIR_CALL_FUNCTION(&_1, "crypt", NULL, 238, &password, &passwordHash);
	zephir_check_call_status();
	zephir_cast_to_string(&_2, &_1);
	ZEPHIR_CPY_WRT(&cryptedHash, &_2);
	cryptedLength = zephir_fast_strlen_ev(&cryptedHash);
	passwordLength = zephir_fast_strlen_ev(&passwordHash);
	zephir_concat_self(&cryptedHash, &passwordHash);
	sum = (cryptedLength - passwordLength);
	for (_3 = 0; _3 < Z_STRLEN_P(&passwordHash); _3++) {
		i = _3; 
		ch = ZEPHIR_STRING_OFFSET(&passwordHash, _3);
		_4$$4 = ZEPHIR_STRING_OFFSET(&cryptedHash, i);
		sum = (sum | ((_4$$4 ^ ch)));
	}
	RETURN_MM_BOOL(0 == sum);
}

/**
 * Check if the CSRF token sent in the request is the same that the current
 * in session
 */
PHP_METHOD(Phalcon_Encryption_Security, checkToken)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool destroyIfValid, _0, _3;
	zval *tokenKey = NULL, tokenKey_sub, *tokenValue = NULL, tokenValue_sub, *destroyIfValid_param = NULL, __$null, session, request, equals, userToken, knownToken, _1$$3, _2$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tokenKey_sub);
	ZVAL_UNDEF(&tokenValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&equals);
	ZVAL_UNDEF(&userToken);
	ZVAL_UNDEF(&knownToken);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(tokenKey)
		Z_PARAM_ZVAL_OR_NULL(tokenValue)
		Z_PARAM_BOOL(destroyIfValid)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &tokenKey, &tokenValue, &destroyIfValid_param);
	if (!tokenKey) {
		tokenKey = &tokenKey_sub;
		ZEPHIR_CPY_WRT(tokenKey, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(tokenKey);
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


	ZEPHIR_CALL_METHOD(&session, this_ptr, "getlocalsession", NULL, 239);
	zephir_check_call_status();
	_0 = zephir_is_true(&session);
	if (_0) {
		_0 = !zephir_is_true(tokenKey);
	}
	if (EXPECTED(_0)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("tokenKeySessionId"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(tokenKey, &session, "get", NULL, 0, &_1$$3);
		zephir_check_call_status();
	}
	if (!(zephir_is_true(tokenKey))) {
		RETURN_MM_BOOL(0);
	}
	if (!(zephir_is_true(tokenValue))) {
		ZEPHIR_CALL_METHOD(&request, this_ptr, "getlocalrequest", NULL, 240);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$5);
		ZVAL_STRING(&_2$$5, "string");
		ZEPHIR_CALL_METHOD(&userToken, &request, "getpost", NULL, 0, tokenKey, &_2$$5);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&userToken, tokenValue);
	}
	ZEPHIR_CALL_METHOD(&knownToken, this_ptr, "getrequesttoken", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&knownToken) == IS_NULL) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&equals);
	ZEPHIR_INIT_NVAR(&equals);
	ZVAL_BOOL(&equals, zephir_hash_equals(&knownToken, &userToken));
	_3 = zephir_is_true(&equals);
	if (_3) {
		_3 = destroyIfValid;
	}
	if (_3) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "destroytoken", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&equals);
}

/**
 * Computes a HMAC
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
	ZEPHIR_CALL_FUNCTION(&hmac, "hash_hmac", NULL, 221, &algo, &data, &key, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(!zephir_is_true(&hmac))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_encryption_security_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "Unknown hashing algorithm: %s");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 135, &_2$$3, &algo);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 8, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Encryption/Security.zep", 215);
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
	zval __$null, session, _0$$3, _1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&session, this_ptr, "getlocalsession", NULL, 239);
	zephir_check_call_status();
	if (UNEXPECTED(zephir_is_true(&session))) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("tokenKeySessionId"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &session, "remove", NULL, 0, &_0$$3);
		zephir_check_call_status();
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("tokenValueSessionId"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &session, "remove", NULL, 0, &_1$$3);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("token"), &__$null);
	zephir_update_property_zval(this_ptr, ZEND_STRL("tokenKey"), &__$null);
	zephir_update_property_zval(this_ptr, ZEND_STRL("requestToken"), &__$null);
	RETURN_THIS();
}

/**
 * Returns the default hash
 */
PHP_METHOD(Phalcon_Encryption_Security, getDefaultHash)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "defaultHash");
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
 */
PHP_METHOD(Phalcon_Encryption_Security, getSessionToken)
{
	zval session, _0$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&_0$$3);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&session, this_ptr, "getlocalsession", NULL, 239);
	zephir_check_call_status();
	if (UNEXPECTED(zephir_is_true(&session))) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("tokenValueSessionId"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_RETURN_CALL_METHOD(&session, "get", NULL, 0, &_0$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_NULL();
}

/**
 * Generate a >22-length pseudo random string to be used as salt for
 * passwords
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
		ZEPHIR_OBS_VAR(&_0$$3);
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("numberBytes"), PH_NOISY_CC);
		numberBytes = zephir_get_intval(&_0$$3);
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
 */
PHP_METHOD(Phalcon_Encryption_Security, getToken)
{
	zval session, _0, _1$$3, _2$$3, _3$$3, _4$$3, _5$$4, _6$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);


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
		ZEPHIR_CALL_METHOD(&session, this_ptr, "getlocalsession", NULL, 239);
		zephir_check_call_status();
		if (UNEXPECTED(zephir_is_true(&session))) {
			zephir_read_property(&_5$$4, this_ptr, ZEND_STRL("tokenValueSessionId"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_6$$4, this_ptr, ZEND_STRL("token"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &session, "set", NULL, 0, &_5$$4, &_6$$4);
			zephir_check_call_status();
		}
	}
	RETURN_MM_MEMBER(getThis(), "token");
}

/**
 * Generates a pseudo random token key to be used as input's name in a CSRF
 * check
 */
PHP_METHOD(Phalcon_Encryption_Security, getTokenKey)
{
	zval session, _0, _1$$4, _2$$4, _3$$4, _4$$4, _5$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("tokenKey"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&session, this_ptr, "getlocalsession", NULL, 239);
		zephir_check_call_status();
		if (UNEXPECTED(zephir_is_true(&session))) {
			zephir_read_property(&_1$$4, this_ptr, ZEND_STRL("random"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("numberBytes"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_2$$4, &_1$$4, "base64safe", NULL, 0, &_3$$4);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, ZEND_STRL("tokenKey"), &_2$$4);
			zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("tokenKeySessionId"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_5$$4, this_ptr, ZEND_STRL("tokenKey"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &session, "set", NULL, 0, &_4$$4, &_5$$4);
			zephir_check_call_status();
		}
	}
	RETURN_MM_MEMBER(getThis(), "tokenKey");
}

/**
 * Creates a password hash using bcrypt with a pseudo random salt
 */
PHP_METHOD(Phalcon_Encryption_Security, hash)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long workFactor, ZEPHIR_LAST_CALL_STATUS, hash = 0;
	zval *password_param = NULL, *workFactor_param = NULL, saltBytes, _1, _0$$3, _2$$12, _3$$12, _4$$13, _5$$15, _6$$15, _7$$17, _8$$17, _9$$17, _10$$17;
	zval password, variant;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&password);
	ZVAL_UNDEF(&variant);
	ZVAL_UNDEF(&saltBytes);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$12);
	ZVAL_UNDEF(&_3$$12);
	ZVAL_UNDEF(&_4$$13);
	ZVAL_UNDEF(&_5$$15);
	ZVAL_UNDEF(&_6$$15);
	ZVAL_UNDEF(&_7$$17);
	ZVAL_UNDEF(&_8$$17);
	ZVAL_UNDEF(&_9$$17);
	ZVAL_UNDEF(&_10$$17);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(password)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(workFactor)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &password_param, &workFactor_param);
	zephir_get_strval(&password, password_param);
	if (!workFactor_param) {
		workFactor = 0;
	} else {
		workFactor = zephir_get_intval(workFactor_param);
	}


	if (!(workFactor)) {
		ZEPHIR_OBS_VAR(&_0$$3);
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("workFactor"), PH_NOISY_CC);
		workFactor = zephir_get_intval(&_0$$3);
	}
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("defaultHash"), PH_NOISY_CC);
	hash = zephir_get_intval(&_1);
	do {
		if (hash == 5) {
			ZEPHIR_INIT_VAR(&variant);
			ZVAL_STRING(&variant, "a");
			break;
		}
		if (hash == 6) {
			ZEPHIR_INIT_NVAR(&variant);
			ZVAL_STRING(&variant, "x");
			break;
		}
		if (hash == 7) {
			ZEPHIR_INIT_NVAR(&variant);
			ZVAL_STRING(&variant, "y");
			break;
		}
		if (hash == 3) {
			ZEPHIR_INIT_NVAR(&variant);
			ZVAL_STRING(&variant, "1");
			break;
		}
		if (hash == 8) {
			ZEPHIR_INIT_NVAR(&variant);
			ZVAL_STRING(&variant, "5");
			break;
		}
		if (hash == 9) {
			ZEPHIR_INIT_NVAR(&variant);
			ZVAL_STRING(&variant, "6");
			break;
		}
		ZEPHIR_INIT_NVAR(&variant);
		ZVAL_STRING(&variant, "y");
		break;
	} while(0);

	do {
		if (hash == 1 || hash == 2) {
			if (hash == 2) {
				ZVAL_LONG(&_3$$12, 8);
				ZEPHIR_CALL_METHOD(&_2$$12, this_ptr, "getsaltbytes", NULL, 0, &_3$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&saltBytes);
				ZEPHIR_CONCAT_SV(&saltBytes, "_", &_2$$12);
			} else {
				ZVAL_LONG(&_4$$13, 2);
				ZEPHIR_CALL_METHOD(&saltBytes, this_ptr, "getsaltbytes", NULL, 0, &_4$$13);
				zephir_check_call_status();
			}
			if (UNEXPECTED(Z_TYPE_P(&saltBytes) != IS_STRING)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_encryption_security_exception_ce, "Unable to get random bytes for the salt", "phalcon/Encryption/Security.zep", 433);
				return;
			}
			ZEPHIR_RETURN_CALL_FUNCTION("crypt", NULL, 238, &password, &saltBytes);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (hash == 3 || hash == 8 || hash == 9) {
			ZEPHIR_INIT_VAR(&_5$$15);
			if (hash == 3) {
				ZEPHIR_INIT_NVAR(&_5$$15);
				ZVAL_LONG(&_5$$15, 12);
			} else {
				ZEPHIR_INIT_NVAR(&_5$$15);
				ZVAL_LONG(&_5$$15, 16);
			}
			ZEPHIR_CALL_METHOD(&saltBytes, this_ptr, "getsaltbytes", NULL, 0, &_5$$15);
			zephir_check_call_status();
			if (UNEXPECTED(Z_TYPE_P(&saltBytes) != IS_STRING)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_encryption_security_exception_ce, "Unable to get random bytes for the salt", "phalcon/Encryption/Security.zep", 452);
				return;
			}
			ZEPHIR_INIT_VAR(&_6$$15);
			ZEPHIR_CONCAT_SVSVS(&_6$$15, "$", &variant, "$", &saltBytes, "$");
			ZEPHIR_RETURN_CALL_FUNCTION("crypt", NULL, 238, &password, &_6$$15);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZVAL_LONG(&_7$$17, 22);
		ZEPHIR_CALL_METHOD(&saltBytes, this_ptr, "getsaltbytes", NULL, 0, &_7$$17);
		zephir_check_call_status();
		if (UNEXPECTED(Z_TYPE_P(&saltBytes) != IS_STRING)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_encryption_security_exception_ce, "Unable to get random bytes for the salt", "phalcon/Encryption/Security.zep", 481);
			return;
		}
		if (workFactor < 4) {
			workFactor = 4;
		} else if (workFactor > 31) {
			workFactor = 31;
		}
		ZEPHIR_INIT_VAR(&_8$$17);
		ZVAL_STRING(&_8$$17, "%02s");
		ZVAL_LONG(&_7$$17, workFactor);
		ZEPHIR_CALL_FUNCTION(&_9$$17, "sprintf", NULL, 135, &_8$$17, &_7$$17);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_10$$17);
		ZEPHIR_CONCAT_SVSVSVS(&_10$$17, "$2", &variant, "$", &_9$$17, "$", &saltBytes, "$");
		ZEPHIR_RETURN_CALL_FUNCTION("crypt", NULL, 238, &password, &_10$$17);
		zephir_check_call_status();
		RETURN_MM();
	} while(0);

	RETURN_MM_STRING("");
}

/**
 * Checks if a password hash is a valid bcrypt's hash
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

PHP_METHOD(Phalcon_Encryption_Security, getLocalRequest)
{
	zval container, _0, _1, _6, _7, _2$$4, _3$$4, _5$$4, _8$$5, _9$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("localRequest"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		RETURN_MM_MEMBER(getThis(), "localRequest");
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_1);
	if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, phalcon_encryption_security_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "the 'request' service");
		ZEPHIR_CALL_CE_STATIC(&_3$$4, phalcon_encryption_security_exception_ce, "containerservicenotfound", &_4, 0, &_5$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 8, &_3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$4, "phalcon/Encryption/Security.zep", 550);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "request");
	ZEPHIR_CALL_METHOD(&_6, &container, "has", NULL, 0, &_7);
	zephir_check_call_status();
	if (UNEXPECTED(zephir_is_true(&_6))) {
		ZEPHIR_INIT_VAR(&_9$$5);
		ZVAL_STRING(&_9$$5, "request");
		ZEPHIR_CALL_METHOD(&_8$$5, &container, "getshared", NULL, 0, &_9$$5);
		zephir_check_call_status();
		RETURN_CCTOR(&_8$$5);
	}
	RETURN_MM_NULL();
}

PHP_METHOD(Phalcon_Encryption_Security, getLocalSession)
{
	zval container, _0, _1, _6, _7, _2$$4, _3$$4, _5$$4, _8$$5, _9$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("localSession"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		RETURN_MM_MEMBER(getThis(), "localSession");
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_1);
	if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, phalcon_encryption_security_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "the 'session' service");
		ZEPHIR_CALL_CE_STATIC(&_3$$4, phalcon_encryption_security_exception_ce, "containerservicenotfound", &_4, 0, &_5$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 8, &_3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$4, "phalcon/Encryption/Security.zep", 572);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "session");
	ZEPHIR_CALL_METHOD(&_6, &container, "has", NULL, 0, &_7);
	zephir_check_call_status();
	if (UNEXPECTED(zephir_is_true(&_6))) {
		ZEPHIR_INIT_VAR(&_9$$5);
		ZVAL_STRING(&_9$$5, "session");
		ZEPHIR_CALL_METHOD(&_8$$5, &container, "getshared", NULL, 0, &_9$$5);
		zephir_check_call_status();
		RETURN_CCTOR(&_8$$5);
	}
	RETURN_MM_NULL();
}

