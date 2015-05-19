
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

#ifndef PHALCON_MVC_MODEL_H
#define PHALCON_MVC_MODEL_H

#include "php_phalcon.h"

#define PHALCON_MODEL_OP_NONE					0
#define PHALCON_MODEL_OP_CREATE					1
#define PHALCON_MODEL_OP_UPDATE					2
#define PHALCON_MODEL_OP_DELETE					3

#define PHALCON_MODEL_DIRTY_STATE_PERSISTEN		0
#define PHALCON_MODEL_DIRTY_STATE_TRANSIENT		1
#define PHALCON_MODEL_DIRTY_STATE_DETACHED		2

extern zend_class_entry *phalcon_mvc_model_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model);

#endif /* PHALCON_MVC_MODEL_H */
