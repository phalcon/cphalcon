
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Forms\Element
 *
 * Interface for Phalcon\Forms\Element classes
 */
ZEPHIR_INIT_CLASS(Phalcon_Forms_ElementInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Forms, ElementInterface, phalcon, forms_elementinterface, phalcon_forms_elementinterface_method_entry);

	return SUCCESS;

}

/**
 * Sets the parent form to the element
 *
 * @param Phalcon\Forms\Form form
 * @return Phalcon\Forms\ElementInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_ElementInterface, setForm);

/**
 * Returns the parent form to the element
 *
 * @return Phalcon\Forms\ElementInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_ElementInterface, getForm);

/**
 * Sets the element's name
 *
 * @param string name
 * @return Phalcon\Forms\ElementInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_ElementInterface, setName);

/**
 * Returns the element's name
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_ElementInterface, getName);

/**
 * Sets the element's filters
 *
 * @param array|string filters
 * @return Phalcon\Forms\ElementInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_ElementInterface, setFilters);

/**
 * Adds a filter to current list of filters
 *
 * @param string filter
 * @return Phalcon\Forms\ElementInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_ElementInterface, addFilter);

/**
 * Returns the element's filters
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_ElementInterface, getFilters);

/**
 * Adds a group of validators
 *
 * @param Phalcon\Validation\ValidatorInterface[]
 * @param boolean merge
 * @return Phalcon\Forms\ElementInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_ElementInterface, addValidators);

/**
 * Adds a validator to the element
 *
 * @param Phalcon\Validation\ValidatorInterface
 * @return Phalcon\Forms\ElementInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_ElementInterface, addValidator);

/**
 * Returns the validators registered for the element
 *
 * @return Phalcon\Validation\ValidatorInterface[]
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_ElementInterface, getValidators);

/**
 * Returns an array of prepared attributes for Phalcon\Tag helpers
 * according to the element's parameters
 *
 * @param array attributes
 * @param boolean useChecked
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_ElementInterface, prepareAttributes);

/**
 * Sets a default attribute for the element
 *
 * @param string attribute
 * @param mixed value
 * @return Phalcon\Forms\ElementInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_ElementInterface, setAttribute);

/**
 * Returns the value of an attribute if present
 *
 * @param string attribute
 * @param mixed defaultValue
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_ElementInterface, getAttribute);

/**
 * Sets default attributes for the element
 *
 * @param array attributes
 * @return Phalcon\Forms\ElementInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_ElementInterface, setAttributes);

/**
 * Returns the default attributes for the element
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_ElementInterface, getAttributes);

/**
 * Sets an option for the element
 *
 * @param string option
 * @param mixed value
 * @return Phalcon\Forms\ElementInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_ElementInterface, setUserOption);

/**
 * Returns the value of an option if present
 *
 * @param string option
 * @param mixed defaultValue
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_ElementInterface, getUserOption);

/**
 * Sets options for the element
 *
 * @param array options
 * @return Phalcon\Forms\ElementInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_ElementInterface, setUserOptions);

/**
 * Returns the options for the element
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_ElementInterface, getUserOptions);

/**
 * Sets the element label
 *
 * @param string label
 * @return Phalcon\Forms\ElementInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_ElementInterface, setLabel);

/**
 * Returns the element's label
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_ElementInterface, getLabel);

/**
 * Generate the HTML to label the element
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_ElementInterface, label);

/**
 * Sets a default value in case the form does not use an entity
 * or there is no value available for the element in _POST
 *
 * @param mixed value
 * @return Phalcon\Forms\ElementInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_ElementInterface, setDefault);

/**
 * Returns the default value assigned to the element
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_ElementInterface, getDefault);

/**
 * Returns the element's value
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_ElementInterface, getValue);

/**
 * Returns the messages that belongs to the element
 * The element needs to be attached to a form
 *
 * @return Phalcon\Validation\Message\Group
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_ElementInterface, getMessages);

/**
 * Checks whether there are messages attached to the element
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_ElementInterface, hasMessages);

/**
 * Sets the validation messages related to the element
 *
 * @param Phalcon\Validation\Message\Group group
 * @return Phalcon\Forms\ElementInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_ElementInterface, setMessages);

/**
 * Appends a message to the internal message list
 *
 * @param Phalcon\Validation\Message message
 * @return Phalcon\Forms\ElementInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_ElementInterface, appendMessage);

/**
 * Clears every element in the form to its default value
 *
 * @return Phalcon\Forms\Element
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_ElementInterface, clear);

/**
 * Renders the element widget
 *
 * @param array attributes
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Forms_ElementInterface, render);

