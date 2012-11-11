
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
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "kernel/main.h"

/**
 * Phalcon\Mvc\Model\QueryInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_QueryInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Mvc\\Model, QueryInterface, mvc_model_queryinterface, phalcon_mvc_model_queryinterface_method_entry);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\Query constructor
 *
 * @param string $phql
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_QueryInterface, __construct);
/**
 * Parses the intermediate code produced by Phalcon\Mvc\Model\Query\Lang generating another
 * intermediate representation that could be executed by Phalcon\Mvc\Model\Query
 *
 * @param Phalcon\Mvc\Model\ManagerInterface $manager
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_QueryInterface, parse);
/**
 * Executes a parsed PHQL statement
 *
 * @param array $placeholders
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_QueryInterface, execute);
