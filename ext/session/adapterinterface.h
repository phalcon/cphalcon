
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

extern zend_class_entry *phalcon_session_adapterinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Session_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapterinterface___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapterinterface_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapterinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapterinterface_set, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapterinterface_has, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapterinterface_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_session_adapterinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, __construct, arginfo_phalcon_session_adapterinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, start, NULL)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, setOptions, arginfo_phalcon_session_adapterinterface_setoptions)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, getOptions, NULL)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, get, arginfo_phalcon_session_adapterinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, set, arginfo_phalcon_session_adapterinterface_set)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, has, arginfo_phalcon_session_adapterinterface_has)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, remove, arginfo_phalcon_session_adapterinterface_remove)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, getId, NULL)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, isStarted, NULL)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, destroy, NULL)
	PHP_FE_END
};

