
<<<<<<< HEAD:ext/phalcon/mvc/model/relationinterface.zep.h
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

#ifndef PHALCON_MVC_MODEL_RELATIONINTERFACE_H
#define PHALCON_MVC_MODEL_RELATIONINTERFACE_H

#include "php_phalcon.h"

>>>>>>> master:ext/mvc/model/relationinterface.h
extern zend_class_entry *phalcon_mvc_model_relationinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_RelationInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_relationinterface_setintermediaterelation, 0, 0, 3)
	ZEND_ARG_INFO(0, intermediateFields)
	ZEND_ARG_INFO(0, intermediateModel)
	ZEND_ARG_INFO(0, intermediateReferencedFields)
ZEND_END_ARG_INFO()

<<<<<<< HEAD:ext/phalcon/mvc/model/relationinterface.zep.h
ZEPHIR_INIT_FUNCS(phalcon_mvc_model_relationinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, __construct, arginfo_phalcon_mvc_model_relationinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, setIntermediateRelation, arginfo_phalcon_mvc_model_relationinterface_setintermediaterelation)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, isReusable, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getReferencedModel, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getFields, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getReferencedFields, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getOptions, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, isForeignKey, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getForeignKey, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, isThrough, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getIntermediateFields, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getIntermediateModel, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getIntermediateReferencedFields, NULL)
  PHP_FE_END
};
=======
#endif /* PHALCON_MVC_MODEL_RELATIONINTERFACE_H */
>>>>>>> master:ext/mvc/model/relationinterface.h
