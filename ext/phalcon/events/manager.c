
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
 * Phalcon\Events\Manager
 *
 * Phalcon Events Manager, offers an easy way to intercept and manipulate, if needed,
 * the normal flow of operation. With the EventsManager the developer can create hooks or
 * plugins that will offer monitoring of data, manipulation, conditional execution and much more.
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Events_Manager) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Events, phalcon, Manager, events_manager, NULL, 0);

	zend_declare_property_null(phalcon_events_manager_ce, SL("_events"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_bool(phalcon_events_manager_ce, SL("_collect"), 0, ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_bool(phalcon_events_manager_ce, SL("_enablePriorities"), 0, ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_events_manager_ce, SL("_responses"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

