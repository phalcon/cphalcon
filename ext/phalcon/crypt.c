
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
 * Phalcon\Crypt
 *
 * Provides encryption facilities to phalcon applications
 *
 *<code>
 *	$crypt = new Phalcon\Crypt();
 *
 *	$key = 'le password';
 *	$text = 'This is a secret text';
 *
 *	$encrypted = $crypt->encrypt($text, $key);
 *
 *	echo $crypt->decrypt($encrypted, $key);
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Crypt) {

	ZEPHIR_REGISTER_CLASS(Phalcon, phalcon, Crypt, crypt, NULL, 0);


	return SUCCESS;

}

