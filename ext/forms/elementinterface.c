
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#include "forms/elementinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_forms_elementinterface_ce;

static const zend_function_entry phalcon_forms_elementinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setForm, arginfo_phalcon_forms_elementinterface_setform)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getForm, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setName, arginfo_phalcon_forms_elementinterface_setname)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setFilters, arginfo_phalcon_forms_elementinterface_setfilters)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, addFilter, arginfo_phalcon_forms_elementinterface_addfilter)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getFilters, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, addValidators, arginfo_phalcon_forms_elementinterface_addvalidators)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, addValidator, arginfo_phalcon_forms_elementinterface_addvalidator)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getValidators, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, prepareAttributes, arginfo_phalcon_forms_elementinterface_prepareattributes)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setAttribute, arginfo_phalcon_forms_elementinterface_setattribute)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getAttribute, arginfo_phalcon_forms_elementinterface_getattribute)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setAttributes, arginfo_phalcon_forms_elementinterface_setattributes)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getAttributes, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setUserOption, arginfo_phalcon_forms_elementinterface_setuseroption)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getUserOption, arginfo_phalcon_forms_elementinterface_getuseroption)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setUserOptions, arginfo_phalcon_forms_elementinterface_setuseroptions)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getUserOptions, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setLabel, arginfo_phalcon_forms_elementinterface_setlabel)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getLabel, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, label, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setDefault, arginfo_phalcon_forms_elementinterface_setdefault)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getDefault, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getValue, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getMessages, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, hasMessages, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setMessages, arginfo_phalcon_forms_elementinterface_setmessages)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, appendMessage, arginfo_phalcon_forms_elementinterface_appendmessage)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, clear, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, render, arginfo_phalcon_forms_elementinterface_render)
	PHP_FE_END
};

/**
 * Phalcon\Forms\ElementInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Forms_ElementInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Forms, ElementInterface, forms_elementinterface, phalcon_forms_elementinterface_method_entry);

	return SUCCESS;
}

/**
 * Sets the parent form to the element
 *
 * @param Phalcon\Forms\Form $form
 * @return Phalcon\Forms\ElementInterface
 */
PHALCON_DOC_METHOD(Phalcon_Forms_ElementInterface, setForm);

/**
 * Returns the parent form to the element
 *
 * @return Phalcon\Forms\ElementInterface
 */
PHALCON_DOC_METHOD(Phalcon_Forms_ElementInterface, getForm);

/**
 * Sets the element's name
 *
 * @param string $name
 * @return Phalcon\Forms\ElementInterface
 */
PHALCON_DOC_METHOD(Phalcon_Forms_ElementInterface, setName);

/**
 * Returns the element's name
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Forms_ElementInterface, getName);

/**
 * Sets the element's filters
 *
 * @param array|string $filters
 * @return Phalcon\Forms\ElementInterface
 */
PHALCON_DOC_METHOD(Phalcon_Forms_ElementInterface, setFilters);

/**
 * Adds a filter to current list of filters
 *
 * @param string $filter
 * @return Phalcon\Forms\ElementInterface
 */
PHALCON_DOC_METHOD(Phalcon_Forms_ElementInterface, addFilter);

/**
 * Returns the element's filters
 *
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_Forms_ElementInterface, getFilters);

/**
 * Adds a group of validators
 *
 * @param Phalcon\Validation\ValidatorInterface[]
 * @return Phalcon\Forms\ElementInterface
 */
PHALCON_DOC_METHOD(Phalcon_Forms_ElementInterface, addValidators);

/**
 * Adds a validator to the element
 *
 * @param Phalcon\Validation\ValidatorInterface
 * @return Phalcon\Forms\ElementInterface
 */
PHALCON_DOC_METHOD(Phalcon_Forms_ElementInterface, addValidator);

/**
 * Returns the validators registered for the element
 *
 * @return Phalcon\Validation\ValidatorInterface[]
 */
PHALCON_DOC_METHOD(Phalcon_Forms_ElementInterface, getValidators);

/**
 * Returns an array of prepared attributes for Phalcon\Tag helpers
 * according to the element's parameters
 *
 * @param array $attributes
 * @param boolean $useChecked
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Forms_ElementInterface, prepareAttributes);

/**
 * Sets a default attribute for the element
 *
 * @param string $attribute
 * @param mixed $value
 * @return Phalcon\Forms\ElementInterface
 */
PHALCON_DOC_METHOD(Phalcon_Forms_ElementInterface, setAttribute);

/**
 * Returns the value of an attribute if present
 *
 * @param string $attribute
 * @param mixed $defaultValue
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_Forms_ElementInterface, getAttribute);

/**
 * Sets default attributes for the element
 *
 * @param array $attributes
 * @return Phalcon\Forms\ElementInterface
 */
PHALCON_DOC_METHOD(Phalcon_Forms_ElementInterface, setAttributes);

/**
 * Returns the default attributes for the element
 *
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Forms_ElementInterface, getAttributes);

/**
 * Sets an option for the element
 *
 * @param string $option
 * @param mixed $value
 * @return Phalcon\Forms\ElementInterface
 */
PHALCON_DOC_METHOD(Phalcon_Forms_ElementInterface, setUserOption);

/**
 * Returns the value of an option if present
 *
 * @param string $option
 * @param mixed $defaultValue
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_Forms_ElementInterface, getUserOption);

/**
 * Sets options for the element
 *
 * @param array $options
 * @return Phalcon\Forms\ElementInterface
 */
PHALCON_DOC_METHOD(Phalcon_Forms_ElementInterface, setUserOptions);

/**
 * Returns the options for the element
 *
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Forms_ElementInterface, getUserOptions);

/**
 * Sets the element label
 *
 * @param string $label
 * @return Phalcon\Forms\ElementInterface
 */
PHALCON_DOC_METHOD(Phalcon_Forms_ElementInterface, setLabel);

/**
 * Returns the element's label
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Forms_ElementInterface, getLabel);

/**
 * Generate the HTML to label the element
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Forms_ElementInterface, label);

/**
 * Sets a default value in case the form does not use an entity
 * or there is no value available for the element in $_POST
 *
 * @param mixed $value
 * @return Phalcon\Forms\ElementInterface
 */
PHALCON_DOC_METHOD(Phalcon_Forms_ElementInterface, setDefault);

/**
 * Returns the default value assigned to the element
 *
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_Forms_ElementInterface, getDefault);

/**
 * Returns the element's value
 *
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_Forms_ElementInterface, getValue);

/**
 * Returns the messages that belongs to the element
 * The element needs to be attached to a form
 *
 * @return Phalcon\Validation\Message\Group
 */
PHALCON_DOC_METHOD(Phalcon_Forms_ElementInterface, getMessages);

/**
 * Checks whether there are messages attached to the element
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Forms_ElementInterface, hasMessages);

/**
 * Sets the validation messages related to the element
 *
 * @param Phalcon\Validation\Message\Group $group
 * @return Phalcon\Forms\ElementInterface
 */
PHALCON_DOC_METHOD(Phalcon_Forms_ElementInterface, setMessages);

/**
 * Appends a message to the internal message list
 *
 * @param Phalcon\Validation\Message $message
 * @return Phalcon\Forms\ElementInterface
 */
PHALCON_DOC_METHOD(Phalcon_Forms_ElementInterface, appendMessage);

/**
 * Clears every element in the form to its default value
 *
 * @return Phalcon\Forms\Element
 */
PHALCON_DOC_METHOD(Phalcon_Forms_ElementInterface, clear);

/**
 * Renders the element widget
 *
 * @param array $attributes
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Forms_ElementInterface, render);

