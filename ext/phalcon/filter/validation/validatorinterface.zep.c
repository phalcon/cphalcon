
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
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Interface for Phalcon\Filter\Validation\AbstractValidator
 *
 * @phpstan-import-type filter_validator_templates from FilterTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_ValidatorInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Filter\\Validation, ValidatorInterface, phalcon, filter_validation_validatorinterface, phalcon_filter_validation_validatorinterface_method_entry);

	return SUCCESS;
}

/**
 * Returns an option in the validator's options
 * Returns null if the option hasn't set
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Filter_Validation_ValidatorInterface, getOption);
/**
 * Get the template message
 */
ZEPHIR_DOC_METHOD(Phalcon_Filter_Validation_ValidatorInterface, getTemplate);
/**
 * Get message templates
 *
 * @phpstan-return filter_validator_templates
 */
ZEPHIR_DOC_METHOD(Phalcon_Filter_Validation_ValidatorInterface, getTemplates);
/**
 * Checks if an option is defined
 */
ZEPHIR_DOC_METHOD(Phalcon_Filter_Validation_ValidatorInterface, hasOption);
/**
 * Set a new template message
 */
ZEPHIR_DOC_METHOD(Phalcon_Filter_Validation_ValidatorInterface, setTemplate);
/**
 * Clear current template and set new from an array,
 *
 * @phpstan-param filter_validator_templates $templates
 */
ZEPHIR_DOC_METHOD(Phalcon_Filter_Validation_ValidatorInterface, setTemplates);
/**
 * Executes the validation
 */
ZEPHIR_DOC_METHOD(Phalcon_Filter_Validation_ValidatorInterface, validate);
