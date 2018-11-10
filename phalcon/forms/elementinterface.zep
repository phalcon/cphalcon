
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
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

use Phalcon\Forms\Form;
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
	 */
	public function setForm(<Form> form) -> <ElementInterface>;

	/**
	 * Returns the parent form to the element
	 */
	public function getForm() -> <Form>;

	/**
	 * Sets the element's name
	 */
	public function setName(string! name) -> <ElementInterface>;

	/**
	 * Returns the element's name
	 */
	public function getName() -> string;

	/**
	 * Sets the element's filters
	 *
	 * @param array|string filters
	 * @return \Phalcon\Forms\ElementInterface
	 */
	public function setFilters(filters) -> <ElementInterface>;

	/**
	 * Adds a filter to current list of filters
	 */
	public function addFilter(string filter) -> <ElementInterface>;

	/**
	 * Returns the element's filters
	 *
	 * @return mixed
	 */
	public function getFilters();

	/**
	 * Adds a group of validators
	 *
	 * @param \Phalcon\Validation\ValidatorInterface[]
	 * @param boolean merge
	 * @return \Phalcon\Forms\ElementInterface
	 */
	public function addValidators(array! validators, boolean merge = true) -> <ElementInterface>;

	/**
	 * Adds a validator to the element
	 */
	public function addValidator(<ValidatorInterface> validator) -> <ElementInterface>;

	/**
	 * Returns the validators registered for the element
	 */
	public function getValidators() -> <ValidatorInterface[]>;

	/**
	 * Returns an array of prepared attributes for Phalcon\Tag helpers
	 * according to the element's parameters
	 */
	public function prepareAttributes(array attributes = null, boolean useChecked = false) -> array;

	/**
	 * Sets a default attribute for the element
	 *
	 * @param string attribute
	 * @param mixed value
	 * @return \Phalcon\Forms\ElementInterface
	 */
	public function setAttribute(string attribute, value) -> <ElementInterface>;

	/**
	 * Returns the value of an attribute if present
	 *
	 * @param string attribute
	 * @param mixed defaultValue
	 * @return mixed
	 */
	public function getAttribute(string attribute, defaultValue = null);

	/**
	 * Sets default attributes for the element
	 */
	public function setAttributes(array! attributes) -> <ElementInterface>;

	/**
	 * Returns the default attributes for the element
	 */
	public function getAttributes() -> array;

	/**
	 * Sets an option for the element
	 *
	 * @param string option
	 * @param mixed value
	 * @return \Phalcon\Forms\ElementInterface
	 */
	public function setUserOption(string option, value) -> <ElementInterface>;

	/**
	 * Returns the value of an option if present
	 *
	 * @param string option
	 * @param mixed defaultValue
	 * @return mixed
	 */
	public function getUserOption(string option, defaultValue = null);

	/**
	 * Sets options for the element
	 */
	public function setUserOptions(array options) -> <ElementInterface>;

	/**
	 * Returns the options for the element
	 */
	public function getUserOptions() -> array;

	/**
	 * Sets the element label
	 */
	public function setLabel(string label) -> <ElementInterface>;

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
	 * @return \Phalcon\Forms\ElementInterface
	 */
	public function setDefault(value) -> <ElementInterface>;

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
	 * @return \Phalcon\Validation\Message\Group
	 */
	public function getMessages();

	/**
	 * Checks whether there are messages attached to the element
	 */
	public function hasMessages() -> boolean;

	/**
	 * Sets the validation messages related to the element
	 */
	public function setMessages(<Group> group) -> <ElementInterface>;

	/**
	 * Appends a message to the internal message list
	 */
	public function appendMessage(<MessageInterface> message) -> <ElementInterface>;

	/**
	 * Clears every element in the form to its default value
	 */
	public function clear() -> <ElementInterface>;

	/**
	 * Renders the element widget
	 *
	 * @param array attributes
	 */
	public function render(attributes = null) -> string;

}
