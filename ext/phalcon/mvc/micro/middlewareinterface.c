
#ifdef HAVE_CONFIG_H
#include "ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

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
 * Phalcon\Mvc\Micro\MiddlewareInterface
 *
 * Allows to implement Phalcon\Mvc\Micro middleware in classes
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Micro_MiddlewareInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Micro, MiddlewareInterface, phalcon, mvc_micro_middlewareinterface, phalcon_mvc_micro_middlewareinterface_method_entry);


	return SUCCESS;

}

/**
 * Calls the middleware
 *
 * @param Phalcon\Mvc\Micro application
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Micro_MiddlewareInterface, call);

