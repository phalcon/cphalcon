
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


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
 * Validate a set of data according to a set of rules
 *
 * @param array|object data
 * @param object entity
 * @return \Phalcon\Validation\Message\Group
 */
ZEPHIR_DOC_METHOD(Phalcon_ValidationInterface, validate);

/**
 * Adds a validator to a field
 */
ZEPHIR_DOC_METHOD(Phalcon_ValidationInterface, add);

/**
 * Alias of `add` method
 */
ZEPHIR_DOC_METHOD(Phalcon_ValidationInterface, rule);

/**
 * Adds the validators to a field
 */
ZEPHIR_DOC_METHOD(Phalcon_ValidationInterface, rules);

/**
 * Adds filters to the field
 *
 * @param string field
 * @param array|string filters
 * @return \Phalcon\Validation
 */
ZEPHIR_DOC_METHOD(Phalcon_ValidationInterface, setFilters);

/**
 * Returns all the filters or a specific one
 *
 * @param string field
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_ValidationInterface, getFilters);

/**
 * Returns the validators added to the validation
 */
ZEPHIR_DOC_METHOD(Phalcon_ValidationInterface, getValidators);

/**
 * Returns the bound entity
 *
 * @return object
 */
ZEPHIR_DOC_METHOD(Phalcon_ValidationInterface, getEntity);

/**
 * Adds default messages to validators
 */
ZEPHIR_DOC_METHOD(Phalcon_ValidationInterface, setDefaultMessages);

/**
 * Get default message for validator type
 *
 * @param string type
 */
ZEPHIR_DOC_METHOD(Phalcon_ValidationInterface, getDefaultMessage);

/**
 * Returns the registered validators
 */
ZEPHIR_DOC_METHOD(Phalcon_ValidationInterface, getMessages);

/**
 * Adds labels for fields
 */
ZEPHIR_DOC_METHOD(Phalcon_ValidationInterface, setLabels);

/**
 * Get label for field
 *
 * @param string field
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_ValidationInterface, getLabel);

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
 * @return \Phalcon\Validation
 */
ZEPHIR_DOC_METHOD(Phalcon_ValidationInterface, bind);

/**
 * Gets the a value to validate in the array/object data source
 *
 * @param string field
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_ValidationInterface, getValue);

