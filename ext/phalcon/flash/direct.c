
#ifdef HAVE_CONFIG_H
#include "ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"


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
 * Phalcon\Flash\Direct
 *
 * This is a variant of the Phalcon\Flash that inmediately outputs any message passed to it
 */
ZEPHIR_INIT_CLASS(Phalcon_Flash_Direct) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Flash, Direct, phalcon, flash_direct, phalcon_flash_ce, phalcon_flash_direct_method_entry, 0);


	return SUCCESS;

}

/**
 * Outputs a message
 *
 * @param  string type
 * @param  string message
 * @return string
 */
PHP_METHOD(Phalcon_Flash_Direct, message) {

	zval *type, *message;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type, &message);



	zephir_call_method_p2(return_value, this_ptr, "outputmessage", type, message);
	RETURN_MM();

}

