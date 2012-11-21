
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
 * Phalcon\Mvc\Model\ResultInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_ResultInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Mvc\\Model, ResultInterface, mvc_model_resultinterface, phalcon_mvc_model_resultinterface_method_entry);

	return SUCCESS;
}

/**
 * Forces that a model doesn't need to be checked if exists before store it
 *
 * @param boolean $forceExists
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_ResultInterface, setForceExists);

