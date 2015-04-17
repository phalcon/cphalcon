
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


/**
 * Phalcon\Cli\Task
 *
 * Every command-line task should extend this class that encapsulates all the task functionality
 *
 * A task can be used to run "tasks" such as migrations, cronjobs, unit-tests, or anything that you want.
 * The Task class should at least have a "mainAction" method
 *
 *<code>
 *
 *class HelloTask extends \Phalcon\Cli\Task
 *{
 *
 *  //This action will be executed by default
 *  public function mainAction()
 *  {
 *
 *  }
 *
 *  public function findAction()
 *  {
 *
 *  }
 *
 *}
 *
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Cli_Task) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cli, Task, phalcon, cli_task, phalcon_di_injectable_ce, phalcon_cli_task_method_entry, 0);

	return SUCCESS;

}

/**
 * Phalcon\Cli\Task constructor
 */
PHP_METHOD(Phalcon_Cli_Task, __construct) {



}

