
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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
  |          Rack Lin <racklin@gmail.com>                                  |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

/**
 * Phalcon\CLI\Task
 *
 * Every command-line task should extend this class that encapsulates all the task functionality
 *
 * The task can be used to run "tasks" such as migrations, cronjobs, unit-tests, or anything that want.
 * The Task class should at least have a "runAction" method
 *
 *<code>
 *
 *
 *class HelloTask extends \Phalcon\CLI\Task
 *{
 *
 *  //This action will be executed by default
 *  public function runAction()
 *  {
 *
 *  }
 *
 *  public function findAction()
 *  {
 *
 *  }
 *
 *  //This action will be executed when a non existent action is requested
 *  public function notFoundAction()
 *  {
 *
 *  }
 *
 *}
 *
 *</code>
 */

/**
 * Phalcon\CLI\Task constructor
 *
 */
PHP_METHOD(Phalcon_CLI_Task, __construct){


	PHALCON_MM_GROW();
	
	PHALCON_MM_RESTORE();
}

