
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
 * Central registry of the array shapes used across the Forms namespace.
 *
 * @phpstan-type forms_attributes array<array-key, mixed>
 * @phpstan-type forms_data array<string, mixed>
 * @phpstan-type forms_elements array<string, ElementInterface>
 * @phpstan-type forms_elements_indexed list<ElementInterface>
 * @phpstan-type forms_filters array<array-key, array<array-key, mixed>|string>
 * @phpstan-type forms_group_options array<array-key, mixed>
 * @phpstan-type forms_locator_element_factory callable(string, forms_group_options, forms_attributes): ElementInterface
 * @phpstan-type forms_locator_elements array<string, forms_locator_element_factory>
 * @phpstan-type forms_locator_factory callable(object|null): Form
 * @phpstan-type forms_locator_factories array<string, forms_locator_factory>
 * @phpstan-type forms_options array<string, mixed>
 * @phpstan-type forms_schema_definition array{
 *     type: string,
 *     name: string,
 *     label?: string,
 *     default?: mixed,
 *     attributes?: forms_attributes,
 *     filters?: forms_filters|string,
 *     validators?: array<array-key, mixed>,
 *     options?: forms_group_options,
 * }
 * @phpstan-type forms_select_options array<array-key, mixed>
 * @phpstan-type forms_validators list<ValidatorInterface>
 * @phpstan-type forms_whitelist array<array-key, string>
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Forms_FormsTypes)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Forms, FormsTypes, phalcon, contracts_forms_formstypes, NULL);

	return SUCCESS;
}

