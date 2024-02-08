
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

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
 * Interface for the Phalcon\Filter\Validation component
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_ValidationInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Filter\\Validation, ValidationInterface, phalcon, filter_validation_validationinterface, phalcon_filter_validation_validationinterface_method_entry);

	return SUCCESS;
}

/**
 * Adds a validator to a field
 *
 * @param string|array       $field
 * @param ValidatorInterface $validator
 */
ZEPHIR_DOC_METHOD(Phalcon_Filter_Validation_ValidationInterface, add);
/**
 * Appends a message to the messages list
 */
ZEPHIR_DOC_METHOD(Phalcon_Filter_Validation_ValidationInterface, appendMessage);
/**
 * Assigns the data to an entity
 * The entity is used to obtain the validation values
 *
 * @param object entity
 * @param array|object data
 */
ZEPHIR_DOC_METHOD(Phalcon_Filter_Validation_ValidationInterface, bind);
/**
 * Returns the bound entity
 *
 * @return object
 */
ZEPHIR_DOC_METHOD(Phalcon_Filter_Validation_ValidationInterface, getEntity);
/**
 * Returns all the filters or a specific one
 */
ZEPHIR_DOC_METHOD(Phalcon_Filter_Validation_ValidationInterface, getFilters);
/**
 * Get label for field
 */
ZEPHIR_DOC_METHOD(Phalcon_Filter_Validation_ValidationInterface, getLabel);
/**
 * Returns the registered validators
 */
ZEPHIR_DOC_METHOD(Phalcon_Filter_Validation_ValidationInterface, getMessages);
/**
 * Returns the validators added to the validation
 */
ZEPHIR_DOC_METHOD(Phalcon_Filter_Validation_ValidationInterface, getValidators);
/**
 * Gets the a value to validate in the array/object data source
 */
ZEPHIR_DOC_METHOD(Phalcon_Filter_Validation_ValidationInterface, getValue);
/**
 * Alias of `add` method
 *
 * @param string|array       $field
 * @param ValidatorInterface $validator
 */
ZEPHIR_DOC_METHOD(Phalcon_Filter_Validation_ValidationInterface, rule);
/**
 * Adds the validators to a field
 */
ZEPHIR_DOC_METHOD(Phalcon_Filter_Validation_ValidationInterface, rules);
/**
 * Adds filters to the field
 *
 * @param array|string filters
 */
ZEPHIR_DOC_METHOD(Phalcon_Filter_Validation_ValidationInterface, setFilters);
/**
 * Adds labels for fields
 */
ZEPHIR_DOC_METHOD(Phalcon_Filter_Validation_ValidationInterface, setLabels);
/**
 * Validate a set of data according to a set of rules
 *
 * @param array|object data
 * @param object entity
 *
 * @return Messages|false
 */
ZEPHIR_DOC_METHOD(Phalcon_Filter_Validation_ValidationInterface, validate);
