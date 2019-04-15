
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\ValidationInterface
 *
 * Interface for the Phalcon\Validation component
 */
ZEPHIR_INIT_CLASS(Phalcon_ValidationInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon, ValidationInterface, phalcon, validationinterface, phalcon_validationinterface_method_entry);

	return SUCCESS;

}

/**
 * Adds a validator to a field
 */
ZEPHIR_DOC_METHOD(Phalcon_ValidationInterface, add);

/**
 * Appends a message to the messages list
 */
ZEPHIR_DOC_METHOD(Phalcon_ValidationInterface, appendMessage);

/**
 * Assigns the data to an entity
 * The entity is used to obtain the validation values
 *
 * @param object entity
 * @param array|object data
 */
ZEPHIR_DOC_METHOD(Phalcon_ValidationInterface, bind);

/**
 * Get default message for validator type
 */
ZEPHIR_DOC_METHOD(Phalcon_ValidationInterface, getDefaultMessage);

/**
 * Returns the bound entity
 *
 * @return object
 */
ZEPHIR_DOC_METHOD(Phalcon_ValidationInterface, getEntity);

/**
 * Returns all the filters or a specific one
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_ValidationInterface, getFilters);

/**
 * Get label for field
 */
ZEPHIR_DOC_METHOD(Phalcon_ValidationInterface, getLabel);

/**
 * Returns the registered validators
 */
ZEPHIR_DOC_METHOD(Phalcon_ValidationInterface, getMessages);

/**
 * Returns the validators added to the validation
 */
ZEPHIR_DOC_METHOD(Phalcon_ValidationInterface, getValidators);

/**
 * Gets the a value to validate in the array/object data source
 */
ZEPHIR_DOC_METHOD(Phalcon_ValidationInterface, getValue);

/**
 * Alias of `add` method
 */
ZEPHIR_DOC_METHOD(Phalcon_ValidationInterface, rule);

/**
 * Adds the validators to a field
 */
ZEPHIR_DOC_METHOD(Phalcon_ValidationInterface, rules);

/**
 * Adds default messages to validators
 */
ZEPHIR_DOC_METHOD(Phalcon_ValidationInterface, setDefaultMessages);

/**
 * Adds filters to the field
 *
 * @param array|string filters
 */
ZEPHIR_DOC_METHOD(Phalcon_ValidationInterface, setFilters);

/**
 * Adds labels for fields
 */
ZEPHIR_DOC_METHOD(Phalcon_ValidationInterface, setLabels);

/**
 * Validate a set of data according to a set of rules
 *
 * @param array|object data
 * @param object entity
 */
ZEPHIR_DOC_METHOD(Phalcon_ValidationInterface, validate);

