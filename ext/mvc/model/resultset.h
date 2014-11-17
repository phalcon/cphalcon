
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

#ifndef PHALCON_MVC_MODEL_RESULTSET_H
#define PHALCON_MVC_MODEL_RESULTSET_H

#include "php_phalcon.h"

extern zend_class_entry *phalcon_mvc_model_resultset_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Resultset);

#define PHALCON_MVC_MODEL_RESULTSET_TYPE_FULL       0
#define PHALCON_MVC_MODEL_RESULTSET_TYPE_PARTIAL    1

#endif /* PHALCON_MVC_MODEL_RESULTSET_H */
