
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
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Class AbstractSigner
 *
 * @property string $algo
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_JWT_Signer_AbstractSigner) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\JWT\\Signer, AbstractSigner, phalcon, http_jwt_signer_abstractsigner, phalcon_http_jwt_signer_abstractsigner_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_http_jwt_signer_abstractsigner_ce, SL("algorithm"), ZEND_ACC_PROTECTED);

	zend_class_implements(phalcon_http_jwt_signer_abstractsigner_ce, 1, phalcon_http_jwt_signer_signerinterface_ce);
	return SUCCESS;

}

/**
 */
PHP_METHOD(Phalcon_Http_JWT_Signer_AbstractSigner, getAlgorithm) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "algorithm");

}

