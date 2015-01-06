
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "annotations/exception.h"
#include "annotations/../exception.h"
#include "kernel/main.h"


/**
 * Phalcon\Annotations\Exception
 *
 * Exceptions thrown in Phalcon\Annotations will use this class
 */
zend_class_entry *phalcon_annotations_exception_ce;

/**
 * Phalcon\Annotations\Exception initializer
 */
PHALCON_INIT_CLASS(Phalcon_Annotations_Exception){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Annotations, Exception, annotations_exception, phalcon_exception_ce, NULL, 0);

	return SUCCESS;
}
