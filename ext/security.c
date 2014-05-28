
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
#include <ext/standard/base64.h>
#include <ext/standard/php_string.h>
#include <ext/standard/php_crypt.h>
#include <main/spprintf.h>

#if PHP_WIN32
#include <win32/winutil.h>
#else
#include <fcntl.h>
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

#include "interned-strings.h"
#include "internal/arginfo.h"

static const unsigned char ascii64[] = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

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
PHP_METHOD(Phalcon_Security, getDefaultHash);
PHP_METHOD(Phalcon_Security, setDefaultHash);

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

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_setdefaulthash, 0, 0, 1)
	ZEND_ARG_INFO(0, hash)
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
	PHP_ME(Phalcon_Security, getDefaultHash, arginfo_empty, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, setDefaultHash, arginfo_phalcon_security_setdefaulthash, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Security initializer
 */
PHALCON_INIT_CLASS(Phalcon_Security){

	zend_phalcon_globals *g = PHALCON_VGLOBAL;
	HashTable *constants    = EG(zend_constants);

	PHALCON_REGISTER_CLASS(Phalcon, Security, security, phalcon_security_method_entry, 0);

	zend_declare_property_null(phalcon_security_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_security_ce, SL("_workFactor"), 8, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_security_ce, SL("_numberBytes"), 16, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_security_ce, SL("_csrf"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_security_ce, SL("_defaultHash"), PHALCON_SECURITY_CRYPT_DEFAULT, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_security_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);

	zend_declare_class_constant_long(phalcon_security_ce, SL("CRYPT_DEFAULT"),    PHALCON_SECURITY_CRYPT_DEFAULT    TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_security_ce, SL("CRYPT_STD_DES"),    PHALCON_SECURITY_CRYPT_STD_DES    TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_security_ce, SL("CRYPT_EXT_DES"),    PHALCON_SECURITY_CRYPT_EXT_DES    TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_security_ce, SL("CRYPT_MD5"),        PHALCON_SECURITY_CRYPT_MD5        TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_security_ce, SL("CRYPT_BLOWFISH"),   PHALCON_SECURITY_CRYPT_BLOWFISH   TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_security_ce, SL("CRYPT_BLOWFISH_X"), PHALCON_SECURITY_CRYPT_BLOWFISH_X TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_security_ce, SL("CRYPT_BLOWFISH_Y"), PHALCON_SECURITY_CRYPT_BLOWFISH_Y TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_security_ce, SL("CRYPT_SHA256"),     PHALCON_SECURITY_CRYPT_SHA256     TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_security_ce, SL("CRYPT_SHA512"),     PHALCON_SECURITY_CRYPT_SHA512     TSRMLS_CC);

	g->security.crypt_std_des_supported  = zend_hash_quick_exists(constants, SS("CRYPT_STD_DES"),  zend_inline_hash_func(SS("CRYPT_STD_DES")));
	g->security.crypt_ext_des_supported  = zend_hash_quick_exists(constants, SS("CRYPT_EXT_DES"),  zend_inline_hash_func(SS("CRYPT_EXT_DES")));
	g->security.crypt_md5_supported      = zend_hash_quick_exists(constants, SS("CRYPT_MD5"),      zend_inline_hash_func(SS("CRYPT_MD5")));
	g->security.crypt_blowfish_supported = zend_hash_quick_exists(constants, SS("CRYPT_BLOWFISH"), zend_inline_hash_func(SS("CRYPT_BLOWFISH")));
	g->security.crypt_sha256_supported   = zend_hash_quick_exists(constants, SS("CRYPT_SHA256"),   zend_inline_hash_func(SS("CRYPT_SHA256")));
	g->security.crypt_sha512_supported   = zend_hash_quick_exists(constants, SS("CRYPT_SHA512"),   zend_inline_hash_func(SS("CRYPT_SHA512")));

	if (PHP_VERSION_ID >= 50307) {
		g->security.crypt_blowfish_y_supported = g->security.crypt_blowfish_supported;
	}
	else {
		g->security.crypt_blowfish_y_supported = 0;
	}

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

	if (Z_LVAL_PP(random_bytes) < 16) {
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
PHP_METHOD(Phalcon_Security, getSaltBytes)
{
	zval **number_bytes = NULL, **b64 = NULL;
	int i_bytes, encode;
	char *result = NULL;

	phalcon_fetch_params_ex(0, 2, &number_bytes, &b64);
	if (number_bytes) {
		PHALCON_ENSURE_IS_LONG(number_bytes);
		i_bytes = Z_LVAL_PP(number_bytes);
	}
	else {
		zval *n = phalcon_fetch_nproperty_this(this_ptr, SL("_numberBytes"), PH_NOISY TSRMLS_CC);
		i_bytes = (Z_TYPE_P(n) == IS_LONG) ? Z_LVAL_P(n) : phalcon_get_intval(n);
	}

	encode = (!b64 || zend_is_true(*b64)) ? 1 : 0;

#if PHP_WIN32
	{
		result = emalloc(i_bytes + 1);
		result[i_bytes] = 0;
		if (php_win32_get_random_bytes((BYTE*)result, (size_t)i_bytes) == FAILURE) {
			efree(result);
			RETURN_FALSE;
		}
	}
#else
	if (phalcon_function_exists_ex(SS("openssl_random_pseudo_bytes") TSRMLS_CC) == FAILURE) {
		ssize_t read_bytes = 0;
		int fd = open("/dev/urandom", O_RDONLY);
		if (EXPECTED(fd >= 0)) {
			result = emalloc(i_bytes + 1);

			while (read_bytes < i_bytes) {
				ssize_t n = read(fd, result + read_bytes, i_bytes - read_bytes);
				if (n < 0) {
					break;
				}

				read_bytes += n;
			}

			close(fd);
		}

		if (UNEXPECTED(read_bytes != i_bytes)) {
			efree(result);
			RETURN_FALSE;
		}
	}
	else {
		zval *tmp = NULL, *n;

		PHALCON_ALLOC_GHOST_ZVAL(n);
		ZVAL_LONG(n, i_bytes);
		PHALCON_CALL_FUNCTIONW(&tmp, "openssl_random_pseudo_bytes", n);

		if (Z_TYPE_P(tmp) != IS_STRING || Z_STRLEN_P(tmp) < i_bytes) {
			zval_ptr_dtor(&tmp);
			RETURN_FALSE;
		}

		result = Z_STRVAL_P(tmp);
		ZVAL_NULL(tmp);
		zval_ptr_dtor(&tmp);
	}

	result[i_bytes] = 0;
#endif

	if (encode) {
		int encoded_len;
		char *encoded = (char*)php_base64_encode((unsigned char*)result, i_bytes, &encoded_len);
		if (encoded) {
			assert(encoded_len >= i_bytes);
			php_strtr(encoded, encoded_len, "+=", "./", 2);
			encoded[i_bytes] = 0;
			RETVAL_STRINGL(encoded, i_bytes, 0);
		}
		else {
			RETVAL_FALSE;
		}

		efree(result);
	}
	else {
		RETURN_STRINGL(result, i_bytes, 0);
	}
}

/**
 * Creates a password hash using bcrypt with a pseudo random salt
 *
 * @param string $password
 * @param int $workFactor
 * @return string
 */
PHP_METHOD(Phalcon_Security, hash)
{
	zval **password, **work_factor = NULL, *tmp, *n_bytes, *z_salt, *salt_bytes = NULL, *default_hash;
	char variant;
	char *salt;
	int salt_len, i_factor, i_hash;

	PHALCON_MM_GROW();

	phalcon_fetch_params_ex(1, 1, &password, &work_factor);
	PHALCON_ENSURE_IS_STRING(password);

	if (!work_factor || Z_TYPE_PP(work_factor) == IS_NULL) {
		tmp         = phalcon_fetch_nproperty_this(this_ptr, SL("_workFactor"), PH_NOISY TSRMLS_CC);
		work_factor = &tmp;
	}

	i_factor = (Z_TYPE_PP(work_factor) == IS_LONG) ? Z_LVAL_PP(work_factor) : phalcon_get_intval(*work_factor);

	default_hash = phalcon_fetch_nproperty_this(getThis(), SL("_defaultHash"), PH_NOISY TSRMLS_CC);
	i_hash       = (Z_TYPE_P(default_hash) == IS_LONG) ? Z_LVAL_P(default_hash) : phalcon_get_intval(default_hash);

	switch (i_hash) {
		default:
		case PHALCON_SECURITY_CRYPT_DEFAULT:
		case PHALCON_SECURITY_CRYPT_BLOWFISH:
			if (!PHALCON_GLOBAL(security.crypt_blowfish_supported)) RETURN_FALSE;
			variant = 'a';
			break;

		case PHALCON_SECURITY_CRYPT_BLOWFISH_X:
			if (!PHALCON_GLOBAL(security.crypt_blowfish_y_supported)) RETURN_FALSE;
			variant = 'x';
			break;

		case PHALCON_SECURITY_CRYPT_BLOWFISH_Y:
			if (!PHALCON_GLOBAL(security.crypt_blowfish_y_supported)) RETURN_FALSE;
			variant = 'y';
			break;

		case PHALCON_SECURITY_CRYPT_STD_DES:
			if (!PHALCON_GLOBAL(security.crypt_std_des_supported)) RETURN_FALSE;
			break;

		case PHALCON_SECURITY_CRYPT_EXT_DES:
			if (!PHALCON_GLOBAL(security.crypt_ext_des_supported)) RETURN_FALSE;
			break;

		case PHALCON_SECURITY_CRYPT_MD5:
			if (!PHALCON_GLOBAL(security.crypt_md5_supported)) RETURN_FALSE;
			break;

		case PHALCON_SECURITY_CRYPT_SHA256:
			if (!PHALCON_GLOBAL(security.crypt_sha256_supported)) RETURN_FALSE;
			variant = '5';
			break;

		case PHALCON_SECURITY_CRYPT_SHA512:
			if (!PHALCON_GLOBAL(security.crypt_sha512_supported)) RETURN_FALSE;
			variant = '6';
			break;
	}

	switch (i_hash) {
		case PHALCON_SECURITY_CRYPT_DEFAULT:
		case PHALCON_SECURITY_CRYPT_BLOWFISH:
		case PHALCON_SECURITY_CRYPT_BLOWFISH_X:
		case PHALCON_SECURITY_CRYPT_BLOWFISH_Y:
		default: {
		/*
		 * Blowfish hashing with a salt as follows: "$2a$", "$2x$" or "$2y$",
		 * a two digit cost parameter, "$", and 22 characters from the alphabet
		 * "./0-9A-Za-z". Using characters outside of this range in the salt
		 * will cause crypt() to return a zero-length string. The two digit cost
		 * parameter is the base-2 logarithm of the iteration count for the
		 * underlying Blowfish-based hashing algorithm and must be in
		 * range 04-31, values outside this range will cause crypt() to fail.
		 */
			PHALCON_ALLOC_GHOST_ZVAL(n_bytes);
			ZVAL_LONG(n_bytes, 22);
			PHALCON_CALL_METHOD(&salt_bytes, this_ptr, "getsaltbytes", n_bytes);
			if (Z_TYPE_P(salt_bytes) != IS_STRING) {
				zend_throw_exception_ex(phalcon_security_exception_ce, 0 TSRMLS_CC, "Unable to get random bytes for the salt");
				RETURN_MM();
			}

			if (i_factor < 4) {
				i_factor = 4;
			}
			else if (i_factor > 31) {
				i_factor = 31;
			}

			assert(Z_STRLEN_P(salt_bytes) == 22);
			salt_len = spprintf(&salt, 0, "$2%c$%02d$%.22s", variant, i_factor, Z_STRVAL_P(salt_bytes));
			assert(salt_len == 29);
			break;
		}

		case PHALCON_SECURITY_CRYPT_STD_DES: {
		/* Standard DES-based hash with a two character salt from the alphabet "./0-9A-Za-z". */
			PHALCON_ALLOC_GHOST_ZVAL(n_bytes);
			ZVAL_LONG(n_bytes, 2);
			PHALCON_CALL_METHOD(&salt_bytes, this_ptr, "getsaltbytes", n_bytes);
			if (Z_TYPE_P(salt_bytes) != IS_STRING) {
				zend_throw_exception_ex(phalcon_security_exception_ce, 0 TSRMLS_CC, "Unable to get random bytes for the salt");
				RETURN_MM();
			}

			assert(Z_STRLEN_P(salt_bytes) == 2);
			salt     = Z_STRVAL_P(salt_bytes);
			salt_len = Z_STRLEN_P(salt_bytes);
			ZVAL_NULL(salt_bytes);
			break;
		}

		case PHALCON_SECURITY_CRYPT_EXT_DES: {
			char buf[4];
		/*
		 * Extended DES-based hash. The "salt" is a 9-character string
		 * consisting of an underscore followed by 4 bytes of iteration count
		 * and 4 bytes of salt. These are encoded as printable characters,
		 * 6 bits per character, least significant character first.
		 * The values 0 to 63 are encoded as "./0-9A-Za-z".
		 */
			buf[0] = ascii64[i_factor & 0x3F];
			buf[1] = ascii64[(i_factor >> 6)  & 0x3F];
			buf[2] = ascii64[(i_factor >> 12) & 0x3F];
			buf[3] = ascii64[(i_factor >> 18) & 0x3F];

			PHALCON_ALLOC_GHOST_ZVAL(n_bytes);
			ZVAL_LONG(n_bytes, 4);
			PHALCON_CALL_METHOD(&salt_bytes, this_ptr, "getsaltbytes", n_bytes);
			if (Z_TYPE_P(salt_bytes) != IS_STRING) {
				zend_throw_exception_ex(phalcon_security_exception_ce, 0 TSRMLS_CC, "Unable to get random bytes for the salt");
				RETURN_MM();
			}

			assert(Z_STRLEN_P(salt_bytes) == 4);
			salt_len = spprintf(&salt, 0, "_%c%c%c%c%.4s", buf[0], buf[1], buf[2], buf[3], Z_STRVAL_P(salt_bytes));
			assert(salt_len == 9);
			break;
		}

		case PHALCON_SECURITY_CRYPT_MD5: {
		/* MD5 hashing with a twelve character salt starting with $1$ */
			PHALCON_ALLOC_GHOST_ZVAL(n_bytes);
			ZVAL_LONG(n_bytes, 12);
			PHALCON_CALL_METHOD(&salt_bytes, this_ptr, "getsaltbytes", n_bytes);
			if (Z_TYPE_P(salt_bytes) != IS_STRING) {
				zend_throw_exception_ex(phalcon_security_exception_ce, 0 TSRMLS_CC, "Unable to get random bytes for the salt");
				RETURN_MM();
			}

			assert(Z_STRLEN_P(salt_bytes) == 12);
			salt_len = spprintf(&salt, 0, "$1$%.12s", Z_STRVAL_P(salt_bytes));
			assert(salt_len == 15);
			break;
		}

		case PHALCON_SECURITY_CRYPT_SHA256:
		/* SHA-256 hash with a sixteen character salt prefixed with $5$. */
		case PHALCON_SECURITY_CRYPT_SHA512: {
		/*
		 * SHA-512 hash with a sixteen character salt prefixed with $6$.
		 *
		 * If the salt string starts with 'rounds=<N>$', the numeric value of N
		 * is used to indicate how many times the hashing loop should be
		 * executed, much like the cost parameter on Blowfish.
		 * The default number of rounds is 5000, there is a minimum of 1000 and
		 * a maximum of 999,999,999. Any selection of N outside this range
		 * will be truncated to the nearest limit.
		 */
			PHALCON_ALLOC_GHOST_ZVAL(n_bytes);
			ZVAL_LONG(n_bytes, 16);
			PHALCON_CALL_METHOD(&salt_bytes, this_ptr, "getsaltbytes", n_bytes);
			if (Z_TYPE_P(salt_bytes) != IS_STRING) {
				zend_throw_exception_ex(phalcon_security_exception_ce, 0 TSRMLS_CC, "Unable to get random bytes for the salt");
				RETURN_MM();
			}

			assert(Z_STRLEN_P(salt_bytes) == 16);
			if (i_factor) {
				salt_len = spprintf(&salt, 0, "$%c$rounds=%d$%.16s", variant, i_factor, Z_STRVAL_P(salt_bytes));
			}
			else {
				salt_len = spprintf(&salt, 0, "$%c$%.16s", variant, Z_STRVAL_P(salt_bytes));
				assert(salt_len == 19);
			}

			break;
		}
	}

	PHALCON_ALLOC_GHOST_ZVAL(z_salt);
	ZVAL_STRINGL(z_salt, salt, salt_len, 0);

	PHALCON_RETURN_CALL_FUNCTION("crypt", *password, z_salt);
	if (return_value_ptr) {
		return_value = *return_value_ptr;
	}

	if (Z_STRLEN_P(return_value) < 13) {
		zval_dtor(return_value);
		RETURN_MM_FALSE;
	}

	PHALCON_MM_RESTORE();
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
	zval *params[2];
	int check = 0;

	phalcon_fetch_params_ex(2, 1, &password, &password_hash, &max_pass_length);

	PHALCON_ENSURE_IS_STRING(password);
	PHALCON_ENSURE_IS_STRING(password_hash);

	if (max_pass_length) {
		PHALCON_ENSURE_IS_LONG(max_pass_length);
		if (Z_LVAL_PP(max_pass_length) > 0 && Z_STRLEN_PP(password) > Z_LVAL_PP(max_pass_length)) {
			RETURN_FALSE;
		}
	}

	params[0] = *password;
	params[1] = *password_hash;
	RETURN_ON_FAILURE(phalcon_call_func_aparams(&hash, SL("crypt"), 2, params TSRMLS_CC));

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
		RETURN_BOOL(check == 0);
	}

	zval_ptr_dtor(&hash);
	RETURN_FALSE;
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

	zval *number_bytes = NULL, *random_bytes = NULL, *base64bytes;
	zval *safe_bytes, *dependency_injector, *service;
	zval *session = NULL, *key;

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

	PHALCON_CALL_FUNCTION(&random_bytes, "openssl_random_pseudo_bytes", number_bytes);

	PHALCON_INIT_VAR(base64bytes);
	phalcon_base64_encode(base64bytes, random_bytes);

	PHALCON_INIT_VAR(safe_bytes);
	phalcon_filter_alphanum(safe_bytes, base64bytes);

	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_security_exception_ce, "A dependency injection container is required to access the 'session' service");
		return;
	}

	PHALCON_INIT_VAR(service);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_session);

	PHALCON_CALL_METHOD(&session, dependency_injector, "getshared", service);
	PHALCON_VERIFY_INTERFACE(session, phalcon_session_adapterinterface_ce);

	PHALCON_INIT_VAR(key);
	ZVAL_STRING(key, "$PHALCON/CSRF/KEY$", 1);
	PHALCON_CALL_METHOD(NULL, session, "set", key, safe_bytes);

	RETURN_CTOR(safe_bytes);
}

/**
 * Generates a pseudo random token value to be used as input's value in a CSRF check
 *
 * @param int $numberBytes
 * @return string
 */
PHP_METHOD(Phalcon_Security, getToken){

	zval *number_bytes = NULL, *random_bytes = NULL, *token, *dependency_injector;
	zval *service, *session = NULL, *key;

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

	PHALCON_CALL_FUNCTION(&random_bytes, "openssl_random_pseudo_bytes", number_bytes);

	PHALCON_INIT_VAR(token);
	phalcon_md5(token, random_bytes);

	dependency_injector = phalcon_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_security_exception_ce, "A dependency injection container is required to access the 'session' service");
		return;
	}

	PHALCON_ALLOC_GHOST_ZVAL(service);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_session);

	PHALCON_CALL_METHOD(&session, dependency_injector, "getshared", service);
	PHALCON_VERIFY_INTERFACE(session, phalcon_session_adapterinterface_ce);

	PHALCON_ALLOC_GHOST_ZVAL(key);
	ZVAL_STRING(key, "$PHALCON/CSRF$", 1);
	PHALCON_CALL_METHOD(NULL, session, "set", key, token);

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
	zval *service = NULL, *session = NULL, *key = NULL, *request = NULL;
	zval *token = NULL, *session_token = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &token_key, &token_value);

	if (!token_value) {
		token_value = PHALCON_GLOBAL(z_null);
	}

	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_security_exception_ce, "A dependency injection container is required to access the 'session' service");
		return;
	}

	PHALCON_INIT_VAR(service);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_session);

	PHALCON_CALL_METHOD(&session, dependency_injector, "getshared", service);
	PHALCON_VERIFY_INTERFACE(session, phalcon_session_adapterinterface_ce);

	if (!token_key || Z_TYPE_P(token_key) == IS_NULL) {
		PHALCON_INIT_VAR(key);
		ZVAL_STRING(key, "$PHALCON/CSRF/KEY$", 1);

		PHALCON_CALL_METHOD(&token_key, session, "get", key);
	}

	if (Z_TYPE_P(token_value) == IS_NULL) {
		PHALCON_INIT_NVAR(service);
		PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_request);

		PHALCON_CALL_METHOD(&request, dependency_injector, "getshared", service);
		PHALCON_VERIFY_INTERFACE(request, phalcon_http_requestinterface_ce);

		/**
		 * We always check if the value is correct in post
		 */
		PHALCON_CALL_METHOD(&token, request, "getpost", token_key);
	} else {
		PHALCON_CPY_WRT(token, token_value);
	}

	PHALCON_INIT_NVAR(key);
	ZVAL_STRING(key, "$PHALCON/CSRF$", 1);

	PHALCON_CALL_METHOD(&session_token, session, "get", key);

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

	zval *dependency_injector, *service, *session = NULL;
	zval *key;

	PHALCON_MM_GROW();

	dependency_injector = phalcon_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_security_exception_ce, "A dependency injection container is required to access the 'session' service");
		return;
	}

	PHALCON_ALLOC_GHOST_ZVAL(service);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_session);

	PHALCON_CALL_METHOD(&session, dependency_injector, "getshared", service);
	PHALCON_VERIFY_INTERFACE(session, phalcon_session_adapterinterface_ce);

	PHALCON_ALLOC_GHOST_ZVAL(key);
	ZVAL_STRING(key, "$PHALCON/CSRF$", 1);

	PHALCON_RETURN_CALL_METHOD(session, "get", key);

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

	phalcon_fetch_params_ex(3, 1, &data, &key, &algo, &raw);

	if (!raw) {
		raw = &(PHALCON_GLOBAL(z_false));
	}

	PHALCON_RETURN_CALL_FUNCTIONW("hash_hmac", *algo, *data, *key, *raw);
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
		zval *algo, *tmp = NULL, *K1 = NULL, *K2 = NULL, *computed_salt, *result;
		int i_hash_len, block_count, i, j, k;
		int salt_len = Z_STRLEN_PP(salt);
		char *s;
		div_t d;

		PHALCON_MM_GROW();

		PHALCON_INIT_VAR(algo);
		ZVAL_STRING(algo, s_hash, 1);

		PHALCON_CALL_FUNCTION(&tmp, "hash", algo, PHALCON_GLOBAL(z_null), PHALCON_GLOBAL(z_true));
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

		for (i = 1; i <= block_count; ++i) {

			s[salt_len+0] = (unsigned char)(i >> 24);
			s[salt_len+1] = (unsigned char)(i >> 16);
			s[salt_len+2] = (unsigned char)(i >> 8);
			s[salt_len+3] = (unsigned char)(i);

			PHALCON_CALL_FUNCTION(&K1, "hash_hmac", algo, computed_salt, *password, PHALCON_GLOBAL(z_true));
            if (Z_TYPE_P(K1) != IS_STRING) {
                RETURN_MM_FALSE;
            }

			PHALCON_CPY_WRT_CTOR(K2, K1);

			for (j = 1; j < i_iterations; ++j) {
				char *k1, *k2;

				PHALCON_CALL_FUNCTION(&tmp, "hash_hmac", algo, K1, *password, PHALCON_GLOBAL(z_true));
                if (Z_TYPE_P(tmp) != IS_STRING) {
                    RETURN_MM_FALSE;
                }

				PHALCON_CPY_WRT(K1, tmp);

				k1 = Z_STRVAL_P(K1);
				k2 = Z_STRVAL_P(K2);
				for (k = 0; k < Z_STRLEN_P(K2); ++k) {
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

		for (i = 0; i < ops->block_size; ++i) {
			K2[i] = K1[i] ^ 0x5C;
			K1[i] = K1[i] ^ 0x36;
		}

		digest_length = (i_size) ? i_size : ops->digest_size;
		loops         = ceil((float)digest_length / (float)ops->digest_size);

		result        = safe_emalloc(loops, ops->digest_size, 1);
		computed_salt = safe_emalloc(salt_len, 1, 4);
		memcpy(computed_salt, Z_STRVAL_PP(salt), salt_len);

		for (i = 1; i <= loops; ++i) {
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

			for (j = 1; j < i_iterations; ++j) {
				ops->hash_init(context);
				ops->hash_update(context, K1, ops->block_size);
				ops->hash_update(context, digest, ops->digest_size);
				ops->hash_final(digest, context);

				ops->hash_init(context);
				ops->hash_update(context, K2, ops->block_size);
				ops->hash_update(context, digest, ops->digest_size);
				ops->hash_final(digest, context);

				for (k = 0; k < ops->digest_size; ++k) {
					temp[k] ^= digest[k];
				}
			}

			memcpy(result + (i-1) * ops->digest_size, temp, ops->digest_size);
		}

		memset(K1, 0, 2 * ops->block_size);
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

		{
			zval *params[] = { algo, *password, *salt, iter, len, PHALCON_GLOBAL(z_true) };
			if (FAILURE == phalcon_return_call_function(return_value, return_value_ptr, SL("hash_pbkdf2"), 6, params TSRMLS_CC)) {
				;
			}
		}

		zval_ptr_dtor(&algo);
		zval_ptr_dtor(&iter);
		zval_ptr_dtor(&len);
	}
#else
	ZEND_MN(Phalcon_Security_pbkdf2)(INTERNAL_FUNCTION_PARAM_PASSTHRU);
#endif
}

/**
 * Sets the default hash
 */
PHP_METHOD(Phalcon_Security, setDefaultHash)
{
	zval **default_hash;

	phalcon_fetch_params_ex(1, 0, &default_hash);
	PHALCON_ENSURE_IS_LONG(default_hash);

	phalcon_update_property_this(getThis(), SL("_defaultHash"), *default_hash TSRMLS_CC);
}

/**
 * Returns the default hash
 */
PHP_METHOD(Phalcon_Security, getDefaultHash)
{
	RETURN_MEMBER(getThis(), "_defaultHash");
}
