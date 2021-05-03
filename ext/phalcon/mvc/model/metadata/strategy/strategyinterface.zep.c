
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Strategy_StrategyInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Model\\MetaData\\Strategy, StrategyInterface, phalcon, mvc_model_metadata_strategy_strategyinterface, phalcon_mvc_model_metadata_strategy_strategyinterface_method_entry);

	return SUCCESS;
}

/**
 * Read the model's column map, this can't be inferred
 *
 * @todo Not implemented
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaData_Strategy_StrategyInterface, getColumnMaps);
/**
 * The meta-data is obtained by reading the column descriptions from the database information schema
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MetaData_Strategy_StrategyInterface, getMetaData);
