
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Class Enum
 *
 * @link https://tools.ietf.org/html/rfc7519
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_JWT_Token_Enum) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\JWT\\Token, Enum, phalcon, http_jwt_token_enum, NULL, 0);

	/**
	 * Headers
	 */
	zephir_declare_class_constant_string(phalcon_http_jwt_token_enum_ce, SL("TYPE"), "typ");

	zephir_declare_class_constant_string(phalcon_http_jwt_token_enum_ce, SL("ALGO"), "alg");

	zephir_declare_class_constant_string(phalcon_http_jwt_token_enum_ce, SL("CONTENT_TYPE"), "cty");

	/**
	 * Claims
	 */
	zephir_declare_class_constant_string(phalcon_http_jwt_token_enum_ce, SL("AUDIENCE"), "aud");

	zephir_declare_class_constant_string(phalcon_http_jwt_token_enum_ce, SL("EXPIRATION_TIME"), "exp");

	zephir_declare_class_constant_string(phalcon_http_jwt_token_enum_ce, SL("ID"), "jti");

	zephir_declare_class_constant_string(phalcon_http_jwt_token_enum_ce, SL("ISSUED_AT"), "iat");

	zephir_declare_class_constant_string(phalcon_http_jwt_token_enum_ce, SL("ISSUER"), "iss");

	zephir_declare_class_constant_string(phalcon_http_jwt_token_enum_ce, SL("NOT_BEFORE"), "nbf");

	zephir_declare_class_constant_string(phalcon_http_jwt_token_enum_ce, SL("SUBJECT"), "sub");

	return SUCCESS;

}

