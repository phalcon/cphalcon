
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
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */
/**
 * Interface for models that provide a custom unique key for the reusable
 * records cache in the Model Manager. Implement this interface when the
 * default object-identity based key (unique_key) does not produce stable
 * cache hits across multiple object instances that represent the same
 * database record.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Mvc_Model_Relation_CacheKeyProvider)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Mvc\\Model\\Relation, CacheKeyProvider, phalcon, contracts_mvc_model_relation_cachekeyprovider, phalcon_contracts_mvc_model_relation_cachekeyprovider_method_entry);

	return SUCCESS;
}

/**
 * Returns a string that uniquely identifies this model instance for
 * use as the key in the reusable records cache.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Mvc_Model_Relation_CacheKeyProvider, getUniqueKey);
