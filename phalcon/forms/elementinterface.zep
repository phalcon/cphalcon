
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Forms;

use Phalcon\Forms\Form;
use Phalcon\Messages\MessageInterface;
use Phalcon\Messages\Messages;
use Phalcon\Validation\ValidatorInterface;

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
	 */
	public function addValidators(array! validators, bool merge = true) -> <ElementInterface>;

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
	public function prepareAttributes(array attributes = null, bool useChecked = false) -> array;

	/**
	 * Sets a default attribute for the element
	 */
	public function setAttribute(string attribute, var value) -> <ElementInterface>;

	/**
	 * Returns the value of an attribute if present
	 */
	public function getAttribute(string attribute, var defaultValue = null) -> var;

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
	 */
	public function setUserOption(string option, var value) -> <ElementInterface>;

	/**
	 * Returns the value of an option if present
	 */
	public function getUserOption(string option, var defaultValue = null) -> var;

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
	 */
	public function setDefault(var value) -> <ElementInterface>;

	/**
	 * Returns the default value assigned to the element
	 */
	public function getDefault() -> var;

	/**
	 * Returns the element's value
	 */
	public function getValue() -> var;

	/**
	 * Returns the messages that belongs to the element
	 * The element needs to be attached to a form
	 */
	public function getMessages() -> <Messages>;

	/**
	 * Checks whether there are messages attached to the element
	 */
	public function hasMessages() -> bool;

	/**
	 * Sets the validation messages related to the element
	 */
	public function setMessages(<Messages> messages) -> <ElementInterface>;

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
	 */
	public function render(array attributes = []) -> string;

}
