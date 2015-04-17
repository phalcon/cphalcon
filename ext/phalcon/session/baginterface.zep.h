
<<<<<<< HEAD:ext/phalcon/session/baginterface.zep.h
=======
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

#ifndef PHALCON_SESSION_BAGINTERFACE_H
#define PHALCON_SESSION_BAGINTERFACE_H

#include "php_phalcon.h"

>>>>>>> master:ext/session/baginterface.h
extern zend_class_entry *phalcon_session_baginterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Session_BagInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_baginterface_set, 0, 0, 2)
	ZEND_ARG_INFO(0, property)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_baginterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_baginterface_has, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_baginterface_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

<<<<<<< HEAD:ext/phalcon/session/baginterface.zep.h
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_baginterface___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_session_baginterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, initialize, NULL)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, destroy, NULL)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, set, arginfo_phalcon_session_baginterface_set)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, get, arginfo_phalcon_session_baginterface_get)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, has, arginfo_phalcon_session_baginterface_has)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, __set, arginfo_phalcon_session_baginterface___set)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, __get, arginfo_phalcon_session_baginterface___get)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, __isset, arginfo_phalcon_session_baginterface___isset)
  PHP_FE_END
};
=======
#endif /* PHALCON_SESSION_BAGINTERFACE_H */
>>>>>>> master:ext/session/baginterface.h
