
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Plugin
 *
 * This class can be used to provide user plugins an easy access to services
 * in the application
 */
ZEPHIR_INIT_CLASS(Phalcon_Plugin) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon, Plugin, phalcon, plugin, phalcon_di_injectable_ce, NULL, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

