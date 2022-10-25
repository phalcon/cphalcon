
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Every command-line task should extend this class that encapsulates all the
 * task functionality
 *
 * A task can be used to run "tasks" such as migrations, cronjobs, unit-tests,
 * or anything that you want. The Task class should at least have a "mainAction"
 * method.
 *
 *```php
 * class HelloTask extends \Phalcon\Cli\Task
 * {
 *     // This action will be executed by default
 *     public function mainAction()
 *     {
 *
 *     }
 *
 *     public function findAction()
 *     {
 *
 *     }
 * }
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Cli_Task) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cli, Task, phalcon, cli_task, phalcon_di_injectable_ce, phalcon_cli_task_method_entry, 0);

	zend_declare_property_null(phalcon_cli_task_ce, SL("eventsManager"), ZEND_ACC_PROTECTED);

	zend_class_implements(phalcon_cli_task_ce, 1, phalcon_cli_taskinterface_ce);
	zend_class_implements(phalcon_cli_task_ce, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Cli\Task constructor
 */
PHP_METHOD(Phalcon_Cli_Task, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("onconstruct")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "onconstruct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Cli_Task, getEventsManager) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "eventsManager");

}

/**
 * Sets the events manager
 */
PHP_METHOD(Phalcon_Cli_Task, setEventsManager) {

	zval *eventsManager, eventsManager_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &eventsManager);



	zephir_update_property_zval(this_ptr, ZEND_STRL("eventsManager"), eventsManager);

}

