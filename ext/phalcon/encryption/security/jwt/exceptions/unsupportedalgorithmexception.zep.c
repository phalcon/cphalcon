
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Security_JWT_Exceptions_UnsupportedAlgorithmException)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Encryption\\Security\\JWT\\Exceptions, UnsupportedAlgorithmException, phalcon, encryption_security_jwt_exceptions_unsupportedalgorithmexception, zend_ce_exception, NULL, 0);

	zend_class_implements(phalcon_encryption_security_jwt_exceptions_unsupportedalgorithmexception_ce, 1, zend_ce_throwable);
	return SUCCESS;
}

