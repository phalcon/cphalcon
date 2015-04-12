
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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

namespace Phalcon\Forms;

use Phalcon\Validation\MessageInterface;
use Phalcon\Validation\ValidatorInterface;
use Phalcon\Validation\Message\Group;

/**
 * Phalcon\Forms\Element
 *
 * Interface for Phalcon\Forms\Element classes
 */
interface ElementInterface
{

	/**
	 * Sets the parent form to the element
	 *
	 * @param Phalcon\Forms\Form form
	 * @return Phalcon\Forms\ElementInterface
	 */
	public function setForm(<\Phalcon\Forms\Form> form);

	/**
	 * Returns the parent form to the element
	 *
	 * @return Phalcon\Forms\ElementInterface
	 */
	public function getForm();

	/**
	 * Sets the element's name
	 *
	 * @param string name
	 * @return Phalcon\Forms\ElementInterface
	 */
	public function setName(string name);

	/**
	 * Returns the element's name
	 */
	public function getName() -> string;

	/**
	 * Sets the element's filters
	 *
	 * @param array|string filters
	 * @return Phalcon\Forms\ElementInterface
	 */
	public function setFilters(filters);

	/**
	 * Adds a filter to current list of filters
	 *
	 * @param string filter
	 * @return Phalcon\Forms\ElementInterface
	 */
	public function addFilter(filter);

	/**
	 * Returns the element's filters
	 *
	 * @return mixed
	 */
	public function getFilters();

	/**
	 * Adds a group of validators
	 *
	 * @param Phalcon\Validation\ValidatorInterface[]
	 * @param boolean merge
	 * @return Phalcon\Forms\ElementInterface
	 */
	public function addValidators(array! validators, merge = true);

	/**
	 * Adds a validator to the element
	 *
	 * @param Phalcon\Validation\ValidatorInterface
	 * @return Phalcon\Forms\ElementInterface
	 */
	public function addValidator(<ValidatorInterface> validator);

	/**
	 * Returns the validators registered for the element
	 *
	 * @return Phalcon\Validation\ValidatorInterface[]
	 */
	public function getValidators();

	/**
	 * Returns an array of prepared attributes for Phalcon\Tag helpers
	 * according to the element's parameters
	 *
	 * @param array attributes
	 * @param boolean useChecked
	 * @return array
	 */
	public function prepareAttributes(attributes = null, useChecked = false);

	/**
	 * Sets a default attribute for the element
	 *
	 * @param string attribute
	 * @param mixed value
	 * @return Phalcon\Forms\ElementInterface
	 */
	public function setAttribute(attribute, value);

	/**
	 * Returns the value of an attribute if present
	 *
	 * @param string attribute
	 * @param mixed defaultValue
	 * @return mixed
	 */
	public function getAttribute(attribute, defaultValue = null);

	/**
	 * Sets default attributes for the element
	 *
	 * @param array attributes
	 * @return Phalcon\Forms\ElementInterface
	 */
	public function setAttributes(array! attributes);

	/**
	 * Returns the default attributes for the element
	 */
	public function getAttributes() -> array;

	/**
	 * Sets an option for the element
	 *
	 * @param string option
	 * @param mixed value
	 * @return Phalcon\Forms\ElementInterface
	 */
	public function setUserOption(option, value);

	/**
	 * Returns the value of an option if present
	 *
	 * @param string option
	 * @param mixed defaultValue
	 * @return mixed
	 */
	public function getUserOption(option, defaultValue = null);

	/**
	 * Sets options for the element
	 *
	 * @param array options
	 * @return Phalcon\Forms\ElementInterface
	 */
	public function setUserOptions(options);

	/**
	 * Returns the options for the element
	 *
	 * @return array
	 */
	public function getUserOptions();

	/**
	 * Sets the element label
	 *
	 * @param string label
	 * @return Phalcon\Forms\ElementInterface
	 */
	public function setLabel(label);

	/**
	 * Returns the element's label
	 */
	public function getLabel() -> string;

	/**
	 * Generate the HTML to label the element
	 */
	public function label() -> string;

	/**
	 * Sets a default value in case the form does not use an entity
	 * or there is no value available for the element in _POST
	 *
	 * @param mixed value
	 * @return Phalcon\Forms\ElementInterface
	 */
	public function setDefault(value);

	/**
	 * Returns the default value assigned to the element
	 *
	 * @return mixed
	 */
	public function getDefault();

	/**
	 * Returns the element's value
	 *
	 * @return mixed
	 */
	public function getValue();

	/**
	 * Returns the messages that belongs to the element
	 * The element needs to be attached to a form
	 *
	 * @return Phalcon\Validation\Message\Group
	 */
	public function getMessages();

	/**
	 * Checks whether there are messages attached to the element
	 */
	public function hasMessages() -> boolean;

	/**
	 * Sets the validation messages related to the element
	 *
	 * @param Phalcon\Validation\Message\Group group
	 * @return Phalcon\Forms\ElementInterface
	 */
	public function setMessages(<Group> group);

	/**
	 * Appends a message to the internal message list
	 *
	 * @param Phalcon\Validation\Message message
	 * @return Phalcon\Forms\ElementInterface
	 */
	public function appendMessage(<MessageInterface> message);

	/**
	 * Clears every element in the form to its default value
	 *
	 * @return Phalcon\Forms\Element
	 */
	public function clear();

	/**
	 * Renders the element widget
	 *
	 * @param array attributes
	 * @return string
	 */
	public function render(attributes = null);

}
