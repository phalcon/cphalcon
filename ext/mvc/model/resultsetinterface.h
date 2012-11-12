
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

extern zend_class_entry *phalcon_mvc_model_resultsetinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_ResultsetInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultsetinterface_setisfresh, 0, 0, 1)
	ZEND_ARG_INFO(0, isFresh)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_resultsetinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, getFirst, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, getLast, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, setIsFresh, arginfo_phalcon_mvc_model_resultsetinterface_setisfresh)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, isFresh, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, getCache, NULL)
	PHP_FE_END
};

