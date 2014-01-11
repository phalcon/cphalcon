
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#include "security.h"
#include "security/exception.h"
#include "diinterface.h"
#include "di/injectionawareinterface.h"
#include "http/requestinterface.h"
#include "session/adapterinterface.h"

#include <stdlib.h>

#ifdef PHALCON_USE_PHP_HASH
#include <ext/hash/php_hash.h>
#endif

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/filter.h"
#include "kernel/concat.h"

/**
 * Phalcon\Security
 *
 * This component provides a set of functions to improve the security in Phalcon applications
 *
 *<code>
 *	$login = $this->request->getPost('login');
 *	$password = $this->request->getPost('password');
 *
 *	$user = Users::findFirstByLogin($login);
 *	if ($user) {
 *		if ($this->security->checkHash($password, $user->password)) {
 *			//The password is valid
 *		}
 *	}
 *</code>
 */
zend_class_entry *phalcon_security_ce;

PHP_METHOD(Phalcon_Security, setDI);
PHP_METHOD(Phalcon_Security, getDI);
PHP_METHOD(Phalcon_Security, setRandomBytes);
PHP_METHOD(Phalcon_Security, getRandomBytes);
PHP_METHOD(Phalcon_Security, setWorkFactor);
PHP_METHOD(Phalcon_Security, getWorkFactor);
PHP_METHOD(Phalcon_Security, getSaltBytes);
PHP_METHOD(Phalcon_Security, hash);
PHP_METHOD(Phalcon_Security, checkHash);
PHP_METHOD(Phalcon_Security, isLegacyHash);
PHP_METHOD(Phalcon_Security, getTokenKey);
PHP_METHOD(Phalcon_Security, getToken);
PHP_METHOD(Phalcon_Security, checkToken);
PHP_METHOD(Phalcon_Security, getSessionToken);
PHP_METHOD(Phalcon_Security, computeHmac);
PHP_METHOD(Phalcon_Security, deriveKey);
PHP_METHOD(Phalcon_Security, pbkdf2);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_setrandombytes, 0, 0, 1)
	ZEND_ARG_INFO(0, randomBytes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_setworkfactor, 0, 0, 1)
	ZEND_ARG_INFO(0, workFactor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_hash, 0, 0, 1)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_INFO(0, workFactor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_checkhash, 0, 0, 2)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_INFO(0, passwordHash)
	ZEND_ARG_INFO(0, maxPasswordLength)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_islegacyhash, 0, 0, 1)
	ZEND_ARG_INFO(0, passwordHash)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_gettokenkey, 0, 0, 0)
	ZEND_ARG_INFO(0, numberBytes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_gettoken, 0, 0, 0)
	ZEND_ARG_INFO(0, numberBytes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_checktoken, 0, 0, 0)
	ZEND_ARG_INFO(0, tokenKey)
	ZEND_ARG_INFO(0, tokenValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_computehmac, 0, 0, 3)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, algo)
	ZEND_ARG_INFO(0, raw)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_derivekey, 0, 0, 2)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_INFO(0, salt)
	ZEND_ARG_INFO(0, hash)
	ZEND_ARG_INFO(0, iterations)
	ZEND_ARG_INFO(0, size)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_security_method_entry[] = {
	PHP_ME(Phalcon_Security, setDI, arginfo_phalcon_security_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, setRandomBytes, arginfo_phalcon_security_setrandombytes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getRandomBytes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, setWorkFactor, arginfo_phalcon_security_setworkfactor, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getWorkFactor, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getSaltBytes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, hash, arginfo_phalcon_security_hash, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, checkHash, arginfo_phalcon_security_checkhash, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, isLegacyHash, arginfo_phalcon_security_islegacyhash, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getTokenKey, arginfo_phalcon_security_gettokenkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getToken, arginfo_phalcon_security_gettoken, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, checkToken, arginfo_phalcon_security_checktoken, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getSessionToken, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, computeHmac, arginfo_phalcon_security_computehmac, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Security, deriveKey, arginfo_phalcon_security_derivekey, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Security, pbkdf2, arginfo_phalcon_security_derivekey, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_FE_END
};

/**
 * Phalcon\Security initializer
 */
PHALCON_INIT_CLASS(Phalcon_Security){

	PHALCON_REGISTER_CLASS(Phalcon, Security, security, phalcon_security_method_entry, 0);

	zend_declare_property_null(phalcon_security_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_security_ce, SL("_workFactor"), 8, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_security_ce, SL("_numberBytes"), 16, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_security_ce, SL("_csrf"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_security_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);

	return SUCCESS;
}

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Security, setDI){

	zval *dependency_injector;

	phalcon_fetch_params(0, 1, 0, &dependency_injector);
	PHALCON_VERIFY_INTERFACE_EX(dependency_injector, phalcon_diinterface_ce, phalcon_security_exception_ce, 0);
	phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Security, getDI){


	RETURN_MEMBER(this_ptr, "_dependencyInjector");
}

/**
 * Sets a number of bytes to be generated by the openssl pseudo random generator
 *
 * @param string $randomBytes
 */
PHP_METHOD(Phalcon_Security, setRandomBytes){

	zval **random_bytes;

	phalcon_fetch_params_ex(1, 0, &random_bytes);

	PHALCON_ENSURE_IS_LONG(random_bytes);

	if (PHALCON_LT_LONG(*random_bytes, 16)) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_security_exception_ce, "At least 16 bytes are needed to produce a correct salt");
		return;
	}
	
	phalcon_update_property_this(this_ptr, SL("_numberBytes"), *random_bytes TSRMLS_CC);
}

/**
 * Returns a number of bytes to be generated by the openssl pseudo random generator
 *
 * @return string
 */
PHP_METHOD(Phalcon_Security, getRandomBytes){


	RETURN_MEMBER(this_ptr, "_numberBytes");
}

/**
 * Sets the default working factor for bcrypts password's salts
 *
 * @param int $workFactor
 */
PHP_METHOD(Phalcon_Security, setWorkFactor){

	zval **work_factor;

	phalcon_fetch_params_ex(1, 0, &work_factor);
	
	PHALCON_ENSURE_IS_LONG(work_factor);
	phalcon_update_property_this(this_ptr, SL("_workFactor"), *work_factor TSRMLS_CC);
}

/**
 * Returns the default working factor for bcrypts password's salts
 *
 * @return int
 */
PHP_METHOD(Phalcon_Security, getWorkFactor){


	RETURN_MEMBER(this_ptr, "_workFactor");
}

/**
 * Generate a >22-length pseudo random string to be used as salt for passwords
 *
 * @return string
 */
PHP_METHOD(Phalcon_Security, getSaltBytes){

	zval *number_bytes, *random_bytes = NULL, *base64bytes = NULL;
	zval *safe_bytes = NULL, *bytes_length = NULL;

	PHALCON_MM_GROW();

	if (phalcon_function_exists_ex(SS("openssl_random_pseudo_bytes") TSRMLS_CC) == FAILURE) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_security_exception_ce, "Openssl extension must be loaded");
		return;
	}
	
	PHALCON_OBS_VAR(number_bytes);
	phalcon_read_property_this(&number_bytes, this_ptr, SL("_numberBytes"), PH_NOISY_CC);
	
	while (1) {
	
		PHALCON_INIT_NVAR(random_bytes);
		phalcon_call_func_p1(random_bytes, "openssl_random_pseudo_bytes", number_bytes);
	
		PHALCON_INIT_NVAR(base64bytes);
		phalcon_base64_encode(base64bytes, random_bytes);
	
		PHALCON_INIT_NVAR(safe_bytes);
		phalcon_filter_alphanum(safe_bytes, base64bytes);
		if (!zend_is_true(safe_bytes)) {
			continue;
		}
	
		PHALCON_INIT_NVAR(bytes_length);
		phalcon_fast_strlen(bytes_length, safe_bytes);
		if (PHALCON_LT_LONG(bytes_length, 22)) {
			continue;
		}
	
		break;
	}
	
	RETURN_CTOR(safe_bytes);
}

/**
 * Creates a password hash using bcrypt with a pseudo random salt
 *
 * @param string $password
 * @param int $workFactor
 * @return string
 */
PHP_METHOD(Phalcon_Security, hash){

	zval *password, *work_factor = NULL, *format, *factor;
	zval *salt_bytes, *salt;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &password, &work_factor);
	
	if (!work_factor || Z_TYPE_P(work_factor) == IS_NULL) {
		work_factor = phalcon_fetch_nproperty_this(this_ptr, SL("_workFactor"), PH_NOISY_CC);
	}
	
	PHALCON_INIT_VAR(format);
	ZVAL_STRING(format, "%02s", 1);
	
	PHALCON_INIT_VAR(factor);
	phalcon_call_func_p2(factor, "sprintf", format, work_factor);
	
	PHALCON_INIT_VAR(salt_bytes);
	phalcon_call_method(salt_bytes, this_ptr, "getsaltbytes");
	
	PHALCON_INIT_VAR(salt);
	PHALCON_CONCAT_SVSV(salt, "$2a$", factor, "$", salt_bytes);
	phalcon_call_func_p2(return_value, "crypt", password, salt);
	RETURN_MM();
}

/**
 * Checks a plain text password and its hash version to check if the password matches
 *
 * @param string $password
 * @param string $passwordHash
 * @param int $maxPasswordLength
 * @return boolean
 */
PHP_METHOD(Phalcon_Security, checkHash){

	zval **password, **password_hash, **max_pass_length = NULL, *hash = NULL;
	int check = 0;

	phalcon_fetch_params_ex(2, 1, &password, &password_hash, &max_pass_length);
	
	PHALCON_ENSURE_IS_STRING(password);

	if (max_pass_length) {
		PHALCON_ENSURE_IS_LONG(max_pass_length);

		if (Z_LVAL_PP(max_pass_length) > 0 && Z_STRLEN_PP(password) > Z_LVAL_PP(max_pass_length)) {
			RETURN_FALSE;
		}
	}

	phalcon_call_func_params(hash, &hash, SL("crypt") TSRMLS_CC, 2, *password, *password_hash);
	if (UNEXPECTED(EG(exception) != NULL)) {
		RETURN_NULL();
	}

	if (UNEXPECTED(Z_TYPE_P(hash) != IS_STRING)) {
		convert_to_string(hash);
	}

	if (Z_STRLEN_P(hash) == Z_STRLEN_PP(password_hash)) {
		int n    = Z_STRLEN_P(hash);
		char *h1 = Z_STRVAL_P(hash);
		char *h2 = Z_STRVAL_PP(password_hash);

		while (n) {
			check |= ((unsigned int)*h1) ^ ((unsigned int)*h2);
			++h1;
			++h2;
			--n;
		}

		zval_ptr_dtor(&hash);
	}

	RETURN_BOOL(check == 0);
}

/**
 * Checks if a password hash is a valid bcrypt's hash
 *
 * @param string $password
 * @param string $passwordHash
 * @return boolean
 */
PHP_METHOD(Phalcon_Security, isLegacyHash){

	zval *password_hash;

	phalcon_fetch_params(0, 1, 0, &password_hash);
	
	if (phalcon_start_with_str(password_hash, SL("$2a$"))) {
		RETURN_TRUE;
	}
	RETURN_FALSE;
}

/**
 * Generates a pseudo random token key to be used as input's name in a CSRF check
 *
 * @param int $numberBytes
 * @return string
 */
PHP_METHOD(Phalcon_Security, getTokenKey){

	zval *number_bytes = NULL, *random_bytes, *base64bytes;
	zval *safe_bytes, *dependency_injector, *service;
	zval *session, *key;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &number_bytes);
	
	if (!number_bytes) {
		PHALCON_INIT_VAR(number_bytes);
		ZVAL_LONG(number_bytes, 12);
	}
	
	if (phalcon_function_exists_ex(SS("openssl_random_pseudo_bytes") TSRMLS_CC) == FAILURE) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_security_exception_ce, "Openssl extension must be loaded");
		return;
	}
	
	PHALCON_INIT_VAR(random_bytes);
	phalcon_call_func_p1(random_bytes, "openssl_random_pseudo_bytes", number_bytes);
	
	PHALCON_INIT_VAR(base64bytes);
	phalcon_base64_encode(base64bytes, random_bytes);
	
	PHALCON_INIT_VAR(safe_bytes);
	phalcon_filter_alphanum(safe_bytes, base64bytes);
	
	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_security_exception_ce, "A dependency injection container is required to access the 'session' service");
		return;
	}
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "session", 1);
	
	PHALCON_INIT_VAR(session);
	phalcon_call_method_p1(session, dependency_injector, "getshared", service);
	PHALCON_VERIFY_INTERFACE(session, phalcon_session_adapterinterface_ce);
	
	PHALCON_INIT_VAR(key);
	ZVAL_STRING(key, "$PHALCON/CSRF/KEY$", 1);
	phalcon_call_method_p2_noret(session, "set", key, safe_bytes);
	
	RETURN_CTOR(safe_bytes);
}

/**
 * Generates a pseudo random token value to be used as input's value in a CSRF check
 *
 * @param int $numberBytes
 * @return string
 */
PHP_METHOD(Phalcon_Security, getToken){

	zval *number_bytes = NULL, *random_bytes, *token, *dependency_injector;
	zval *service, *session, *key;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &number_bytes);
	
	if (!number_bytes) {
		PHALCON_INIT_VAR(number_bytes);
		ZVAL_LONG(number_bytes, 12);
	}
	
	if (phalcon_function_exists_ex(SS("openssl_random_pseudo_bytes") TSRMLS_CC) == FAILURE) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_security_exception_ce, "Openssl extension must be loaded");
		return;
	}
	
	PHALCON_INIT_VAR(random_bytes);
	phalcon_call_func_p1(random_bytes, "openssl_random_pseudo_bytes", number_bytes);
	
	PHALCON_INIT_VAR(token);
	phalcon_md5(token, random_bytes);
	
	dependency_injector = phalcon_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_security_exception_ce, "A dependency injection container is required to access the 'session' service");
		return;
	}
	
	PHALCON_ALLOC_GHOST_ZVAL(service);
	ZVAL_STRING(service, "session", 1);
	
	PHALCON_INIT_VAR(session);
	phalcon_call_method_p1(session, dependency_injector, "getshared", service);
	PHALCON_VERIFY_INTERFACE(session, phalcon_session_adapterinterface_ce);
	
	PHALCON_ALLOC_GHOST_ZVAL(key);
	ZVAL_STRING(key, "$PHALCON/CSRF$", 1);
	phalcon_call_method_p2_noret(session, "set", key, token);
	
	RETURN_CTOR(token);
}

/**
 * Check if the CSRF token sent in the request is the same that the current in session
 *
 * @param string $tokenKey
 * @param string $tokenValue
 * @return boolean
 */
PHP_METHOD(Phalcon_Security, checkToken){

	zval *token_key = NULL, *token_value = NULL, *dependency_injector;
	zval *service = NULL, *session, *key = NULL, *request, *token = NULL, *session_token;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &token_key, &token_value);
	
	if (!token_value) {
		token_value = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_security_exception_ce, "A dependency injection container is required to access the 'session' service");
		return;
	}
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "session", 1);
	
	PHALCON_INIT_VAR(session);
	phalcon_call_method_p1(session, dependency_injector, "getshared", service);
	PHALCON_VERIFY_INTERFACE(session, phalcon_session_adapterinterface_ce);

	if (!token_key || Z_TYPE_P(token_key) == IS_NULL) {
		PHALCON_INIT_VAR(key);
		ZVAL_STRING(key, "$PHALCON/CSRF/KEY$", 1);
	
		PHALCON_INIT_VAR(token_key);
		phalcon_call_method_p1(token_key, session, "get", key);
	}
	
	if (Z_TYPE_P(token_value) == IS_NULL) {
		PHALCON_INIT_NVAR(service);
		ZVAL_STRING(service, "request", 1);
	
		PHALCON_INIT_VAR(request);
		phalcon_call_method_p1(request, dependency_injector, "getshared", service);
		PHALCON_VERIFY_INTERFACE(request, phalcon_http_requestinterface_ce);
	
		/** 
		 * We always check if the value is correct in post
		 */
		PHALCON_INIT_VAR(token);
		phalcon_call_method_p1(token, request, "getpost", token_key);
	} else {
		PHALCON_CPY_WRT(token, token_value);
	}
	
	PHALCON_INIT_NVAR(key);
	ZVAL_STRING(key, "$PHALCON/CSRF$", 1);
	
	PHALCON_INIT_VAR(session_token);
	phalcon_call_method_p1(session_token, session, "get", key);
	
	/** 
	 * The value is the same?
	 */
	is_equal_function(return_value, token, session_token TSRMLS_CC);
	
	RETURN_MM();
}

/**
 * Returns the value of the CSRF token in session
 *
 * @return string
 */
PHP_METHOD(Phalcon_Security, getSessionToken){

	zval *dependency_injector, *service, *session;
	zval *key;

	PHALCON_MM_GROW();

	dependency_injector = phalcon_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_security_exception_ce, "A dependency injection container is required to access the 'session' service");
		return;
	}
	
	PHALCON_ALLOC_GHOST_ZVAL(service);
	ZVAL_STRING(service, "session", 1);
	
	PHALCON_INIT_VAR(session);
	phalcon_call_method_p1(session, dependency_injector, "getshared", service);
	PHALCON_VERIFY_INTERFACE(session, phalcon_session_adapterinterface_ce);
	
	PHALCON_ALLOC_GHOST_ZVAL(key);
	ZVAL_STRING(key, "$PHALCON/CSRF$", 1);
	
	phalcon_return_call_method_p1(session, "get", key);
	
	PHALCON_MM_RESTORE();
}

/**
 * string \Phalcon\Security::computeHmac(string $data, string $key, string $algo, bool $raw = false)
 *
 *
 */
PHP_METHOD(Phalcon_Security, computeHmac)
{
	zval **data, **key, **algo, **raw = NULL;
#ifdef PHALCON_USE_PHP_HASH
	const php_hash_ops *ops;
	void *context;
	unsigned char *block, *digest;
	int i;
#endif

	phalcon_fetch_params_ex(3, 1, &data, &key, &algo, &raw);

	if (!raw) {
		raw = &(PHALCON_GLOBAL(z_false));
	}

#ifdef PHALCON_USE_PHP_HASH
	PHALCON_ENSURE_IS_STRING(data);
	PHALCON_ENSURE_IS_STRING(key);
	PHALCON_ENSURE_IS_STRING(algo);

	ops = php_hash_fetch_ops(Z_STRVAL_PP(algo), Z_STRLEN_PP(algo));
	if (!ops) {
		zend_throw_exception_ex(phalcon_security_exception_ce, 0 TSRMLS_CC, "Unknown hashing algorithm: %s", Z_STRVAL_PP(algo));
		return;
	}

	/* Allocate all memory we need in one chunk */
	context = ecalloc(1, ops->context_size + ops->block_size);
	block   = (unsigned char*)context + ops->context_size;
	digest  = ecalloc(1, ops->digest_size + 1);
	ops->hash_init(context);

	if (Z_STRLEN_PP(key) > ops->block_size) {
		/* Reduce the key */
		ops->hash_update(context, (unsigned char*)(Z_STRVAL_PP(key)), Z_STRLEN_PP(key));
		ops->hash_final(block, context);
		/* Reinitialize the context */
		ops->hash_init(context);
	}
	else {
		memcpy(block, Z_STRVAL_PP(key), Z_STRLEN_PP(key));
	}

	for (i=0; i<ops->block_size; ++i) {
		block[i] ^= 0x36;
	}

	ops->hash_update(context, block, ops->block_size);
	ops->hash_update(context, (unsigned char*)(Z_STRVAL_PP(data)), Z_STRLEN_PP(data));
	ops->hash_final(digest, context);

	for(i=0; i < ops->block_size; i++) {
		block[i] ^= 0x6A;
	}

	ops->hash_init(context);
	ops->hash_update(context, block, ops->block_size);
	ops->hash_update(context, digest, ops->digest_size);
	ops->hash_final(digest, context);

	memset(block, 0, ops->block_size);
	efree(context);

	if (!zend_is_true(*raw)) {
		char *hex_digest = safe_emalloc(ops->digest_size, 2, 1);

		php_hash_bin2hex(hex_digest, digest, ops->digest_size);
		efree(digest);
		hex_digest[2 * ops->digest_size] = 0;

		RETURN_STRINGL(hex_digest, 2 * ops->digest_size, 0);
	}

	RETURN_STRINGL((char*)digest, ops->digest_size, 0);
#else
	phalcon_call_func_params(return_value, return_value_ptr, SL("hash_hmac") TSRMLS_CC, 4, *algo, *data, *key, *raw);
	if (unlikely(EG(exception) != NULL) && return_value_ptr) {
		ALLOC_INIT_ZVAL(*return_value_ptr);
	}
#endif
}

/**
 * @internal
 * @brief This method is used only for internal tests, use Phalcon\Security::deriveKey() instead
 */
PHP_METHOD(Phalcon_Security, pbkdf2)
{
	zval **password, **salt, **hash = NULL, **iterations = NULL, **size = NULL;
	char* s_hash;
	int i_iterations = 0, i_size = 0;

	phalcon_fetch_params_ex(2, 3, &password, &salt, &hash, &iterations, &size);

	PHALCON_ENSURE_IS_STRING(password);
	PHALCON_ENSURE_IS_STRING(salt);

	if (Z_STRLEN_PP(salt) > INT_MAX - 4) {
		zend_throw_exception_ex(phalcon_security_exception_ce, 0 TSRMLS_CC, "Salt is too long: %d", Z_STRLEN_PP(salt));
		return;
	}

	s_hash = (!hash || Z_TYPE_PP(hash) != IS_STRING) ? "sha512" : Z_STRVAL_PP(hash);

	if (iterations) {
		PHALCON_ENSURE_IS_LONG(iterations);
		i_iterations = Z_LVAL_PP(iterations);
	}

	if (i_iterations <= 0) {
		i_iterations = 5000;
	}

	if (size) {
		PHALCON_ENSURE_IS_LONG(size);
		i_size = Z_LVAL_PP(size);
	}

	if (i_size < 0) {
		i_size = 0;
	}

	{
		zval *algo, *tmp, *K1 = NULL, *K2 = NULL, *computed_salt, *result;
		int i_hash_len, block_count, i, j, k;
		int salt_len = Z_STRLEN_PP(salt);
		char *s;
		div_t d;

		PHALCON_MM_GROW();

		PHALCON_INIT_VAR(algo);
		ZVAL_STRING(algo, s_hash, 1);

		PHALCON_OBS_VAR(tmp);
		phalcon_call_func_p3_ex(tmp, &tmp, "hash", algo, PHALCON_GLOBAL(z_null), PHALCON_GLOBAL(z_true));
		if (PHALCON_IS_FALSE(tmp) || Z_TYPE_P(tmp) != IS_STRING) {
			RETURN_MM_FALSE;
		}

		i_hash_len = Z_STRLEN_P(tmp);
		if (!i_size) {
			i_size = i_hash_len;
		}

		PHALCON_INIT_VAR(computed_salt);
		s = safe_emalloc(salt_len, 1, 5);
		s[salt_len + 4] = 0;
		memcpy(s, Z_STRVAL_PP(salt), salt_len);
		ZVAL_STRINGL(computed_salt, s, salt_len + 4, 0);

		PHALCON_INIT_VAR(result);

		d           = div(i_size, i_hash_len);
		block_count = d.quot + (d.rem ? 1 : 0);

		for (i=1; i<=block_count; ++i) {
			s[salt_len+0] = (unsigned char)(i >> 24);
			s[salt_len+1] = (unsigned char)(i >> 16);
			s[salt_len+2] = (unsigned char)(i >> 8);
			s[salt_len+3] = (unsigned char)(i);

			PHALCON_INIT_NVAR(K1);
			phalcon_call_func_p4(K1, "hash_hmac", algo, computed_salt, *password, PHALCON_GLOBAL(z_true));
			PHALCON_CPY_WRT_CTOR(K2, K1);

			for (j=1; j<i_iterations; ++j) {
				char *k1, *k2;

				PHALCON_INIT_NVAR(tmp);
				phalcon_call_func_p4(tmp, "hash_hmac", algo, K1, *password, PHALCON_GLOBAL(z_true));
				PHALCON_CPY_WRT(K1, tmp);

				k1 = Z_STRVAL_P(K1);
				k2 = Z_STRVAL_P(K2);
				for (k=0; k<Z_STRLEN_P(K2); ++k) {
					k2[k] ^= k1[k];
				}
			}

			phalcon_concat_self(&result, K2 TSRMLS_CC);
		}

		if (i_size == i_hash_len) {
			RETVAL_STRINGL(Z_STRVAL_P(result), Z_STRLEN_P(result), 0);
			ZVAL_NULL(result);
		}
		else {
			phalcon_substr(return_value, result, 0, i_size);
		}

		PHALCON_MM_RESTORE();
	}
}

/**
 * Derives a key from the given password (PBKDF2).
 *
 * @param string $password Source password
 * @param string $salt The salt to use for the derivation; this value should be generated randomly.
 * @param string $hash Hash function (SHA-512 by default)
 * @param int $iterations The number of internal iterations to perform for the derivation, by default 5000
 * @param int $size The length of the output string. If 0 is passed (the default), the entire output of the supplied hash algorithm is used
 * @return string The derived key
 */
PHP_METHOD(Phalcon_Security, deriveKey)
{
	zval **password, **salt, **hash = NULL, **iterations = NULL, **size = NULL;
	char* s_hash;
	int i_iterations = 0, i_size = 0;

	phalcon_fetch_params_ex(2, 3, &password, &salt, &hash, &iterations, &size);

	PHALCON_ENSURE_IS_STRING(password);
	PHALCON_ENSURE_IS_STRING(salt);

	if (Z_STRLEN_PP(salt) > INT_MAX - 4) {
		zend_throw_exception_ex(phalcon_security_exception_ce, 0 TSRMLS_CC, "Salt is too long: %d", Z_STRLEN_PP(salt));
		return;
	}

	s_hash = (!hash || Z_TYPE_PP(hash) != IS_STRING) ? "sha512" : Z_STRVAL_PP(hash);

	if (iterations) {
		PHALCON_ENSURE_IS_LONG(iterations);
		i_iterations = Z_LVAL_PP(iterations);
	}

	if (i_iterations <= 0) {
		i_iterations = 5000;
	}

	if (size) {
		PHALCON_ENSURE_IS_LONG(size);
		i_size = Z_LVAL_PP(size);
	}

	if (i_size < 0) {
		i_size = 0;
	}


#if defined(PHALCON_USE_PHP_HASH)
	{
		const php_hash_ops *ops = php_hash_fetch_ops(s_hash, hash ? (size_t)(Z_STRLEN_PP(hash)) : strlen(s_hash));
		void *context;
		unsigned char *K1, *K2, *digest, *temp, *result, *computed_salt;
		long int i, j, loops, digest_length;
		int salt_len = Z_STRLEN_PP(salt);
		int pass_len = Z_STRLEN_PP(password);
		int k;

		if (!ops) {
			zend_throw_exception_ex(phalcon_security_exception_ce, 0 TSRMLS_CC, "Unknown hashing algorithm: %s", s_hash);
			return;
		}

		context = emalloc(ops->context_size);
		ops->hash_init(context);

		K1     = emalloc(2 * ops->block_size + 2 * ops->digest_size);
		K2     = K1 + ops->block_size;
		digest = K2 + ops->block_size;
		temp   = digest + ops->digest_size;

		/* Set up keys that will be used for all HMAC rounds */
		memset(K1, 0, ops->block_size);
		if (pass_len > ops->block_size) {
			ops->hash_init(context);
			ops->hash_update(context, (unsigned char*)Z_STRVAL_PP(password), pass_len);
			ops->hash_final(K1, context);
		}
		else {
			memcpy(K1, Z_STRVAL_PP(password), pass_len);
		}

		for (i=0; i<ops->block_size; ++i) {
			K2[i] = K1[i] ^ 0x5C;
			K1[i] = K1[i] ^ 0x36;
		}

		digest_length = (i_size) ? i_size : ops->digest_size;
		loops         = ceil((float)digest_length / (float)ops->digest_size);

		result        = safe_emalloc(loops, ops->digest_size, 1);
		computed_salt = safe_emalloc(salt_len, 1, 4);
		memcpy(computed_salt, Z_STRVAL_PP(salt), salt_len);

		for (i=1; i<=loops; ++i) {
			computed_salt[salt_len+0] = (unsigned char)(i >> 24);
			computed_salt[salt_len+1] = (unsigned char)(i >> 16);
			computed_salt[salt_len+2] = (unsigned char)(i >> 8);
			computed_salt[salt_len+3] = (unsigned char)(i);

			ops->hash_init(context);
			ops->hash_update(context, K1, ops->block_size);
			ops->hash_update(context, computed_salt, (long int)(salt_len) + 4);
			ops->hash_final(digest, context);

			ops->hash_init(context);
			ops->hash_update(context, K2, ops->block_size);
			ops->hash_update(context, digest, ops->digest_size);
			ops->hash_final(digest, context);

			memcpy(temp, digest, ops->digest_size);

			for (j=1; j<i_iterations; ++j) {
				ops->hash_init(context);
				ops->hash_update(context, K1, ops->block_size);
				ops->hash_update(context, digest, ops->digest_size);
				ops->hash_final(digest, context);

				ops->hash_init(context);
				ops->hash_update(context, K2, ops->block_size);
				ops->hash_update(context, digest, ops->digest_size);
				ops->hash_final(digest, context);

				for (k=0; k<ops->digest_size; ++k) {
					temp[k] ^= digest[k];
				}
			}

			memcpy(result + (i-1)*ops->digest_size, temp, ops->digest_size);
		}

		memset(K1, 0, 2*ops->block_size);
		memset(computed_salt, 0, salt_len + 4);
		efree(K1);
		efree(computed_salt);
		efree(context);

		if (digest_length != ops->digest_size) {
			char *retval = safe_emalloc(i_size, 1, 1);
			memcpy(retval, result, i_size);
			retval[i_size] = 0;
			efree(result);
			RETVAL_STRINGL(retval, i_size, 0);
		}
		else {
			result[digest_length] = 0;
			RETVAL_STRINGL((char*)result, digest_length, 0);
		}
	}
#elif PHP_VERSION_ID >= 50000
	{
		zval *algo, *iter, *len;

		MAKE_STD_ZVAL(algo);
		ZVAL_STRING(algo, s_hash, 1);

		MAKE_STD_ZVAL(iter);
		ZVAL_LONG(iter, i_iterations);

		MAKE_STD_ZVAL(len);
		ZVAL_LONG(len, i_size);

		phalcon_call_func_params(
			return_value, return_value_ptr, SL("hash_pbkdf2") TSRMLS_CC, 6,
			algo, *password, *salt, iter, len, PHALCON_GLOBAL(z_true)
		);

		if (UNEXPECTED(EG(exception) && return_value_ptr)) {
			ALLOC_INIT_ZVAL(*return_value_ptr);
		}

		zval_ptr_dtor(&algo);
		zval_ptr_dtor(&iter);
		zval_ptr_dtor(&len);
	}
#else
	ZEND_MN(Phalcon_Security_pbkdf2)(INTERNAL_FUNCTION_PARAM_PASSTHRU);
#endif
}
