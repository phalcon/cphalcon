
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
 * Contract for objects that supply a normalized list of form element
 * definitions. Implementations may source the definitions from a PHP array,
 * a JSON document, a YAML file, or any other format.
 *
 * Each returned definition must be an associative array containing at least:
 *   - 'type' (string)  — element type key (e.g. 'text', 'select', 'checkgroup')
 *   - 'name' (string)  — the HTML name attribute value
 *
 * Optional keys per definition:
 *   - 'label'      (string)          — visible label text
 *   - 'default'    (mixed)           — pre-populated default value
 *   - 'attributes' (array)           — additional HTML attributes
 *   - 'filters'    (array|string)    — filter names applied on bind()
 *   - 'validators' (array)           — ValidatorInterface instances
 *   - 'options'    (array)           — choices for select / checkgroup / radiogroup
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Forms_Schema)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Forms, Schema, phalcon, contracts_forms_schema, phalcon_contracts_forms_schema_method_entry);

	return SUCCESS;
}

/**
 * Returns an ordered list of normalized element definitions.
 *
 * @phpstan-return array<int, array<string, mixed>>
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Forms_Schema, load);
