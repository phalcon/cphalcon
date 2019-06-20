
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

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
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Security
 *
 * This component provides a set of functions to improve the security in Phalcon
 * applications
 *
 *<code>
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
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Security) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Security, phalcon, security, phalcon_security_method_entry, 0);

	zend_declare_property_null(phalcon_security_ce, SL("container"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_security_ce, SL("defaultHash"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalcon_security_ce, SL("numberBytes"), 16, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_security_ce, SL("random"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_security_ce, SL("requestToken"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_security_ce, SL("token"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_security_ce, SL("tokenKey"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_security_ce, SL("tokenKeySessionId"), "$PHALCON/CSRF/KEY$", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_security_ce, SL("tokenValueSessionId"), "$PHALCON/CSRF$", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalcon_security_ce, SL("workFactor"), 8, ZEND_ACC_PROTECTED TSRMLS_CC);

	zephir_declare_class_constant_long(phalcon_security_ce, SL("CRYPT_DEFAULT"), 0);

	zephir_declare_class_constant_long(phalcon_security_ce, SL("CRYPT_BLOWFISH"), 4);

	zephir_declare_class_constant_long(phalcon_security_ce, SL("CRYPT_BLOWFISH_A"), 5);

	zephir_declare_class_constant_long(phalcon_security_ce, SL("CRYPT_BLOWFISH_X"), 6);

	zephir_declare_class_constant_long(phalcon_security_ce, SL("CRYPT_BLOWFISH_Y"), 7);

	zephir_declare_class_constant_long(phalcon_security_ce, SL("CRYPT_EXT_DES"), 2);

	zephir_declare_class_constant_long(phalcon_security_ce, SL("CRYPT_MD5"), 3);

	zephir_declare_class_constant_long(phalcon_security_ce, SL("CRYPT_SHA256"), 8);

	zephir_declare_class_constant_long(phalcon_security_ce, SL("CRYPT_SHA512"), 9);

	zephir_declare_class_constant_long(phalcon_security_ce, SL("CRYPT_STD_DES"), 1);

	zend_class_implements(phalcon_security_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Security, setWorkFactor) {

	zval *workFactor, workFactor_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&workFactor_sub);

	zephir_fetch_params(0, 1, 0, &workFactor);



	zephir_update_property_zval(this_ptr, SL("workFactor"), workFactor);
	RETURN_THISW();

}

PHP_METHOD(Phalcon_Security, getWorkFactor) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "workFactor");

}

/**
 * Phalcon\Security constructor
 */
PHP_METHOD(Phalcon_Security, __construct) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_security_random_ce);
	if (zephir_has_constructor(&_0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("random"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks a plain text password and its hash version to check if the
 * password matches
 */
PHP_METHOD(Phalcon_Security, checkHash) {

	unsigned char _4$$4;
	long _3;
	zend_bool _0;
	char ch = 0;
	zend_long maxPassLength, ZEPHIR_LAST_CALL_STATUS, i = 0, sum = 0, cryptedLength = 0, passwordLength = 0;
	zval *password_param = NULL, *passwordHash_param = NULL, *maxPassLength_param = NULL, _1;
	zval password, passwordHash, cryptedHash, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&password);
	ZVAL_UNDEF(&passwordHash);
	ZVAL_UNDEF(&cryptedHash);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1);

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
	ZEPHIR_CALL_FUNCTION(&_1, "crypt", NULL, 507, &password, &passwordHash);
	zephir_check_call_status();
	zephir_get_strval(&_2, &_1);
	ZEPHIR_CPY_WRT(&cryptedHash, &_2);
	cryptedLength = zephir_fast_strlen_ev(&cryptedHash);
	passwordLength = zephir_fast_strlen_ev(&passwordHash);
	zephir_concat_self(&cryptedHash, &passwordHash TSRMLS_CC);
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
PHP_METHOD(Phalcon_Security, checkToken) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_bool destroyIfValid, _9;
	zval *tokenKey = NULL, tokenKey_sub, *tokenValue = NULL, tokenValue_sub, *destroyIfValid_param = NULL, __$null, container, session, request, equals, userToken, knownToken, _0, _5, _6, _1$$3, _2$$3, _4$$3, _7$$4, _8$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tokenKey_sub);
	ZVAL_UNDEF(&tokenValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&equals);
	ZVAL_UNDEF(&userToken);
	ZVAL_UNDEF(&knownToken);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$6);

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


	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_security_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "the 'session' service");
		ZEPHIR_CALL_CE_STATIC(&_2$$3, phalcon_security_exception_ce, "containerservicenotfound", &_3, 0, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 1, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Security.zep", 113 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "session");
	ZEPHIR_CALL_METHOD(&_5, &container, "getshared", NULL, 0, &_6);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&session, &_5);
	if (!(zephir_is_true(tokenKey))) {
		zephir_read_property(&_7$$4, this_ptr, SL("tokenKeySessionId"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(tokenKey, &session, "get", NULL, 0, &_7$$4);
		zephir_check_call_status();
	}
	if (!(zephir_is_true(tokenKey))) {
		RETURN_MM_BOOL(0);
	}
	if (!(zephir_is_true(tokenValue))) {
		ZEPHIR_INIT_VAR(&_8$$6);
		ZVAL_STRING(&_8$$6, "request");
		ZEPHIR_CALL_METHOD(&request, &container, "getshared", NULL, 0, &_8$$6);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_8$$6);
		ZVAL_STRING(&_8$$6, "string");
		ZEPHIR_CALL_METHOD(&userToken, &request, "getpost", NULL, 0, tokenKey, &_8$$6);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&userToken, tokenValue);
	}
	ZEPHIR_CALL_METHOD(&knownToken, this_ptr, "getrequesttoken", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&equals);
	ZEPHIR_INIT_NVAR(&equals);
	ZVAL_BOOL(&equals, zephir_hash_equals(&knownToken, &userToken));
	_9 = zephir_is_true(&equals);
	if (_9) {
		_9 = destroyIfValid;
	}
	if (_9) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "destroytoken", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&equals);

}

/**
 * Computes a HMAC
 */
PHP_METHOD(Phalcon_Security, computeHmac) {

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
	ZEPHIR_CALL_FUNCTION(&hmac, "hash_hmac", NULL, 168, &algo, &data, &key, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(!zephir_is_true(&hmac))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_security_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "Unknown hashing algorithm: %s");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 175, &_2$$3, &algo);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 1, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Security.zep", 174 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&hmac);

}

/**
 * Removes the value of the CSRF token and key from session
 */
PHP_METHOD(Phalcon_Security, destroyToken) {

	zval __$null, container, session, _0, _5, _6, _7, _1$$3, _2$$3, _4$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_security_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "the 'session' service");
		ZEPHIR_CALL_CE_STATIC(&_2$$3, phalcon_security_exception_ce, "containerservicenotfound", &_3, 0, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 1, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Security.zep", 192 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "session");
	ZEPHIR_CALL_METHOD(&_5, &container, "getshared", NULL, 0, &_6);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&session, &_5);
	zephir_read_property(&_0, this_ptr, SL("tokenKeySessionId"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &session, "remove", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_read_property(&_7, this_ptr, SL("tokenValueSessionId"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &session, "remove", NULL, 0, &_7);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("token"), &__$null);
	zephir_update_property_zval(this_ptr, SL("tokenKey"), &__$null);
	zephir_update_property_zval(this_ptr, SL("requestToken"), &__$null);
	RETURN_THIS();

}

/**
 * Returns the default hash
 */
PHP_METHOD(Phalcon_Security, getDefaultHash) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "defaultHash");

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Security, getDI) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "container");

}

/**
 * Returns a secure random number generator instance
 */
PHP_METHOD(Phalcon_Security, getRandom) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "random");

}

/**
 * Returns a number of bytes to be generated by the openssl pseudo random
 * generator
 */
PHP_METHOD(Phalcon_Security, getRandomBytes) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "numberBytes");

}

/**
 * Returns the value of the CSRF token for the current request.
 */
PHP_METHOD(Phalcon_Security, getRequestToken) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("requestToken"), PH_NOISY_CC | PH_READONLY);
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
PHP_METHOD(Phalcon_Security, getSessionToken) {

	zval container, session, _0, _5, _6, _1$$3, _2$$3, _4$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_security_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "the 'session' service");
		ZEPHIR_CALL_CE_STATIC(&_2$$3, phalcon_security_exception_ce, "containerservicenotfound", &_3, 0, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 1, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Security.zep", 264 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "session");
	ZEPHIR_CALL_METHOD(&_5, &container, "getshared", NULL, 0, &_6);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&session, &_5);
	zephir_read_property(&_0, this_ptr, SL("tokenValueSessionId"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&session, "get", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Generate a >22-length pseudo random string to be used as salt for
 * passwords
 */
PHP_METHOD(Phalcon_Security, getSaltBytes) {

	zend_bool _3$$4;
	zval *numberBytes_param = NULL, safeBytes, _0$$3, _1$$4, _2$$4;
	zend_long numberBytes, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&safeBytes);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &numberBytes_param);

	if (!numberBytes_param) {
		numberBytes = 0;
	} else {
		numberBytes = zephir_get_intval(numberBytes_param);
	}


	if (!(numberBytes)) {
		ZEPHIR_OBS_VAR(&_0$$3);
		zephir_read_property(&_0$$3, this_ptr, SL("numberBytes"), PH_NOISY_CC);
		numberBytes = zephir_get_intval(&_0$$3);
	}
	while (1) {
		zephir_read_property(&_1$$4, this_ptr, SL("random"), PH_NOISY_CC | PH_READONLY);
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
PHP_METHOD(Phalcon_Security, getToken) {

	zval container, session, _0, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3, _10$$3, _11$$3, _12$$3, _6$$4, _7$$4, _9$$4;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("token"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "getsessiontoken", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("requestToken"), &_1$$3);
		zephir_read_property(&_2$$3, this_ptr, SL("random"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_4$$3, this_ptr, SL("numberBytes"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_3$$3, &_2$$3, "base64safe", NULL, 0, &_4$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("token"), &_3$$3);
		zephir_read_property(&_5$$3, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&container, &_5$$3);
		if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
			ZEPHIR_INIT_VAR(&_6$$4);
			object_init_ex(&_6$$4, phalcon_security_exception_ce);
			ZEPHIR_INIT_VAR(&_9$$4);
			ZVAL_STRING(&_9$$4, "the 'session' service");
			ZEPHIR_CALL_CE_STATIC(&_7$$4, phalcon_security_exception_ce, "containerservicenotfound", &_8, 0, &_9$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_6$$4, "__construct", NULL, 1, &_7$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_6$$4, "phalcon/Security.zep", 312 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_11$$3);
		ZVAL_STRING(&_11$$3, "session");
		ZEPHIR_CALL_METHOD(&_10$$3, &container, "getshared", NULL, 0, &_11$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&session, &_10$$3);
		zephir_read_property(&_5$$3, this_ptr, SL("tokenValueSessionId"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_12$$3, this_ptr, SL("token"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &session, "set", NULL, 0, &_5$$3, &_12$$3);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(getThis(), "token");

}

/**
 * Generates a pseudo random token key to be used as input's name in a CSRF
 * check
 */
PHP_METHOD(Phalcon_Security, getTokenKey) {

	zval container, session, _0, _1$$3, _6$$3, _7$$3, _8$$3, _9$$3, _10$$3, _11$$3, _2$$4, _3$$4, _5$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("tokenKey"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		zephir_read_property(&_1$$3, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&container, &_1$$3);
		if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
			ZEPHIR_INIT_VAR(&_2$$4);
			object_init_ex(&_2$$4, phalcon_security_exception_ce);
			ZEPHIR_INIT_VAR(&_5$$4);
			ZVAL_STRING(&_5$$4, "the 'session' service");
			ZEPHIR_CALL_CE_STATIC(&_3$$4, phalcon_security_exception_ce, "containerservicenotfound", &_4, 0, &_5$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 1, &_3$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$4, "phalcon/Security.zep", 340 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property(&_1$$3, this_ptr, SL("random"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_7$$3, this_ptr, SL("numberBytes"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_6$$3, &_1$$3, "base64safe", NULL, 0, &_7$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("tokenKey"), &_6$$3);
		ZEPHIR_INIT_VAR(&_9$$3);
		ZVAL_STRING(&_9$$3, "session");
		ZEPHIR_CALL_METHOD(&_8$$3, &container, "getshared", NULL, 0, &_9$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&session, &_8$$3);
		zephir_read_property(&_10$$3, this_ptr, SL("tokenKeySessionId"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_11$$3, this_ptr, SL("tokenKey"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &session, "set", NULL, 0, &_10$$3, &_11$$3);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(getThis(), "tokenKey");

}

/**
 * Creates a password hash using bcrypt with a pseudo random salt
 */
PHP_METHOD(Phalcon_Security, hash) {

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
		zephir_read_property(&_0$$3, this_ptr, SL("workFactor"), PH_NOISY_CC);
		workFactor = zephir_get_intval(&_0$$3);
	}
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, SL("defaultHash"), PH_NOISY_CC);
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
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_security_exception_ce, "Unable to get random bytes for the salt", "phalcon/Security.zep", 422);
				return;
			}
			ZEPHIR_RETURN_CALL_FUNCTION("crypt", NULL, 507, &password, &saltBytes);
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
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_security_exception_ce, "Unable to get random bytes for the salt", "phalcon/Security.zep", 441);
				return;
			}
			ZEPHIR_INIT_VAR(&_6$$15);
			ZEPHIR_CONCAT_SVSVS(&_6$$15, "$", &variant, "$", &saltBytes, "$");
			ZEPHIR_RETURN_CALL_FUNCTION("crypt", NULL, 507, &password, &_6$$15);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZVAL_LONG(&_7$$17, 22);
		ZEPHIR_CALL_METHOD(&saltBytes, this_ptr, "getsaltbytes", NULL, 0, &_7$$17);
		zephir_check_call_status();
		if (UNEXPECTED(Z_TYPE_P(&saltBytes) != IS_STRING)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_security_exception_ce, "Unable to get random bytes for the salt", "phalcon/Security.zep", 470);
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
		ZEPHIR_CALL_FUNCTION(&_9$$17, "sprintf", NULL, 175, &_8$$17, &_7$$17);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_10$$17);
		ZEPHIR_CONCAT_SVSVSVS(&_10$$17, "$2", &variant, "$", &_9$$17, "$", &saltBytes, "$");
		ZEPHIR_RETURN_CALL_FUNCTION("crypt", NULL, 507, &password, &_10$$17);
		zephir_check_call_status();
		RETURN_MM();
	} while(0);

	RETURN_MM_STRING("");

}

/**
 * Checks if a password hash is a valid bcrypt's hash
 */
PHP_METHOD(Phalcon_Security, isLegacyHash) {

	zval *passwordHash_param = NULL;
	zval passwordHash;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&passwordHash);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &passwordHash_param);

	zephir_get_strval(&passwordHash, passwordHash_param);


	RETURN_MM_BOOL(zephir_start_with_str(&passwordHash, SL("$2a$")));

}

/**
 * Sets the default hash
 */
PHP_METHOD(Phalcon_Security, setDefaultHash) {

	zval *defaultHash_param = NULL, _0;
	zend_long defaultHash;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &defaultHash_param);

	defaultHash = zephir_get_intval(defaultHash_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, defaultHash);
	zephir_update_property_zval(this_ptr, SL("defaultHash"), &_0);
	RETURN_THISW();

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Security, setDI) {

	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);

	zephir_fetch_params(0, 1, 0, &container);



	zephir_update_property_zval(this_ptr, SL("container"), container);

}

/**
 * Sets a number of bytes to be generated by the openssl pseudo random
 * generator
 */
PHP_METHOD(Phalcon_Security, setRandomBytes) {

	zval *randomBytes_param = NULL, _0;
	long randomBytes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &randomBytes_param);

	if (UNEXPECTED(Z_TYPE_P(randomBytes_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'randomBytes' must be of the type long") TSRMLS_CC);
		RETURN_NULL();
	}
	randomBytes = Z_LVAL_P(randomBytes_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, randomBytes);
	zephir_update_property_zval(this_ptr, SL("numberBytes"), &_0);
	RETURN_THISW();

}

