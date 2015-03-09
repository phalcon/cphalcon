
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_StrategyInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Model\\MetaData, StrategyInterface, phalcon, mvc_model_metadata_strategyinterface, phalcon_mvc_model_metadata_strategyinterface_method_entry);

	return SUCCESS;

}

/**
 * The meta-data is obtained by reading the column descriptions from the database information schema
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @param Phalcon\DiInterface dependencyInjector
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaData_StrategyInterface, getMetaData);

/**
 * Read the model's column map, this can't be inferred
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @param Phalcon\DiInterface dependencyInjector
 * @return array
 * @todo Not implemented
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaData_StrategyInterface, getColumnMaps);

