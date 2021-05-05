
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
 * Interface for Phalcon\Forms\Element classes
 */
ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_ElementInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Forms\\Element, ElementInterface, phalcon, forms_element_elementinterface, phalcon_forms_element_elementinterface_method_entry);

	return SUCCESS;
}

/**
 * Adds a filter to current list of filters
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_Element_ElementInterface, addFilter);
/**
 * Adds a validator to the element
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_Element_ElementInterface, addValidator);
/**
 * Adds a group of validators
 *
 * @param \Phalcon\Validation\ValidatorInterface[] validators
 * @param bool merge
 *
 * @return ElementInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_Element_ElementInterface, addValidators);
/**
 * Appends a message to the internal message list
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_Element_ElementInterface, appendMessage);
/**
 * Clears every element in the form to its default value
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_Element_ElementInterface, clear);
/**
 * Returns the value of an attribute if present
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_Element_ElementInterface, getAttribute);
/**
 * Returns the default attributes for the element
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_Element_ElementInterface, getAttributes);
/**
 * Returns the default value assigned to the element
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_Element_ElementInterface, getDefault);
/**
 * Returns the element's filters
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_Element_ElementInterface, getFilters);
/**
 * Returns the parent form to the element
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_Element_ElementInterface, getForm);
/**
 * Returns the element's label
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_Element_ElementInterface, getLabel);
/**
 * Returns the messages that belongs to the element
 * The element needs to be attached to a form
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_Element_ElementInterface, getMessages);
/**
 * Returns the element's name
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_Element_ElementInterface, getName);
/**
 * Returns the value of an option if present
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_Element_ElementInterface, getUserOption);
/**
 * Returns the options for the element
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_Element_ElementInterface, getUserOptions);
/**
 * Returns the validators registered for the element
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_Element_ElementInterface, getValidators);
/**
 * Returns the element's value
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_Element_ElementInterface, getValue);
/**
 * Checks whether there are messages attached to the element
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_Element_ElementInterface, hasMessages);
/**
 * Generate the HTML to label the element
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_Element_ElementInterface, label);
/**
 * Returns an array of prepared attributes for Phalcon\Tag helpers
 * according to the element's parameters
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_Element_ElementInterface, prepareAttributes);
/**
 * Renders the element widget
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_Element_ElementInterface, render);
/**
 * Sets a default attribute for the element
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_Element_ElementInterface, setAttribute);
/**
 * Sets default attributes for the element
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_Element_ElementInterface, setAttributes);
/**
 * Sets a default value in case the form does not use an entity
 * or there is no value available for the element in _POST
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_Element_ElementInterface, setDefault);
/**
 * Sets the element's filters
 *
 * @param array|string filters
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_Element_ElementInterface, setFilters);
/**
 * Sets the parent form to the element
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_Element_ElementInterface, setForm);
/**
 * Sets the element label
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_Element_ElementInterface, setLabel);
/**
 * Sets the validation messages related to the element
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_Element_ElementInterface, setMessages);
/**
 * Sets the element's name
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_Element_ElementInterface, setName);
/**
 * Sets an option for the element
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_Element_ElementInterface, setUserOption);
/**
 * Sets options for the element
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_Element_ElementInterface, setUserOptions);
