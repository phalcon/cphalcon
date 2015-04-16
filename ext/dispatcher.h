
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
  |          Rack Lin <racklin@gmail.com>                                  |
  +------------------------------------------------------------------------+
*/

#ifndef PHALCON_DISPATCHER_H
#define PHALCON_DISPATCHER_H

#include "php_phalcon.h"

#define PHALCON_EXCEPTION_NO_DI				1
#define PHALCON_EXCEPTION_CYCLIC_ROUTING	2
#define PHALCON_EXCEPTION_HANDLER_NOT_FOUND	4
#define PHALCON_EXCEPTION_INVALID_HANDLER	8
#define PHALCON_EXCEPTION_INVALID_PARAMS	16
#define PHALCON_EXCEPTION_ACTION_NOT_FOUND	32

extern zend_class_entry *phalcon_dispatcher_ce;

PHALCON_INIT_CLASS(Phalcon_Dispatcher);

#endif /* PHALCON_DISPATCHER_H */
