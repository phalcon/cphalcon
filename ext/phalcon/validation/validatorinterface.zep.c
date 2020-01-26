
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

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
/**
 * Interface for Phalcon\Validation\AbstractValidator
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_ValidatorInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Validation, ValidatorInterface, phalcon, validation_validatorinterface, phalcon_validation_validatorinterface_method_entry);

	return SUCCESS;

}

/**
 * Returns an option in the validator's options
 * Returns null if the option hasn't set
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Validation_ValidatorInterface, getOption);

/**
 * Checks if an option is defined
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Validation_ValidatorInterface, hasOption);

/**
 * Executes the validation
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Validation_ValidatorInterface, validate);

/**
 * Get the template message
 *
 * @return string
 * @throw InvalidArgumentException When the field does not exists
 */
ZEPHIR_DOC_METHOD(Phalcon_Validation_ValidatorInterface, getTemplate);

/**
 * Get message templates
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Validation_ValidatorInterface, getTemplates);

/**
 * Clear current template and set new from an array,
 *
 * @return ValidatorInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Validation_ValidatorInterface, setTemplates);

/**
 * Set a new template message
 *
 * @return ValidatorInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Validation_ValidatorInterface, setTemplate);

