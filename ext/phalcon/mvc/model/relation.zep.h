
<<<<<<< HEAD:ext/phalcon/mvc/model/relation.zep.h
extern zend_class_entry *phalcon_mvc_model_relation_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Relation);

PHP_METHOD(Phalcon_Mvc_Model_Relation, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Relation, setIntermediateRelation);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getType);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getReferencedModel);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getFields);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getReferencedFields);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getOptions);
PHP_METHOD(Phalcon_Mvc_Model_Relation, isForeignKey);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getForeignKey);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getParams);
PHP_METHOD(Phalcon_Mvc_Model_Relation, isThrough);
PHP_METHOD(Phalcon_Mvc_Model_Relation, isReusable);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getIntermediateFields);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getIntermediateModel);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getIntermediateReferencedFields);
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

#ifndef PHALCON_MVC_MODEL_RELATION_H
#define PHALCON_MVC_MODEL_RELATION_H

#include "php_phalcon.h"
>>>>>>> master:ext/mvc/model/relation.h

extern zend_class_entry *phalcon_mvc_model_relation_ce;

<<<<<<< HEAD:ext/phalcon/mvc/model/relation.zep.h
ZEPHIR_INIT_FUNCS(phalcon_mvc_model_relation_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Relation, __construct, arginfo_phalcon_mvc_model_relation___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Relation, setIntermediateRelation, arginfo_phalcon_mvc_model_relation_setintermediaterelation, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getReferencedModel, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getFields, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getReferencedFields, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, isForeignKey, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getForeignKey, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, isThrough, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, isReusable, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getIntermediateFields, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getIntermediateModel, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getIntermediateReferencedFields, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
=======
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Relation);

#endif /* PHALCON_MVC_MODEL_RELATION_H */
>>>>>>> master:ext/mvc/model/relation.h
