
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_test.h"
#include "test.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
ZEPHIR_INIT_CLASS(Phalcon_Security) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Security, phalcon, security, NULL, 0);

	zend_declare_property_null(phalcon_security_ce, SL("_dependencyInjector"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_long(phalcon_security_ce, SL("_workFactor"), 8, ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_long(phalcon_security_ce, SL("_numberBytes"), 16, ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_security_ce, SL("_csrf"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

