
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Forms\Element;

use Phalcon\Forms\Form;
use Phalcon\Messages\MessageInterface;
use Phalcon\Messages\Messages;
use Phalcon\Filter\Validation\ValidatorInterface;

/**
 * Interface for Phalcon\Forms\Element classes
 */
interface ElementInterface
{
    /**
     * Adds a filter to current list of filters
     */
    public function addFilter(string filter) -> <ElementInterface>;

    /**
     * Adds a validator to the element
     */
    public function addValidator(<ValidatorInterface> validator) -> <ElementInterface>;

    /**
     * Adds a group of validators
     *
     * @param \Phalcon\Filter\Validation\ValidatorInterface[] validators
     * @param bool merge
     *
     * @return ElementInterface
     */
    public function addValidators(array! validators, bool merge = true) -> <ElementInterface>;

    /**
     * Appends a message to the internal message list
     */
    public function appendMessage(<MessageInterface> message) -> <ElementInterface>;

    /**
     * Clears every element in the form to its default value
     */
    public function clear() -> <ElementInterface>;

    /**
     * Returns the value of an attribute if present
     */
    public function getAttribute(string attribute, var defaultValue = null) -> var;

    /**
     * Returns the default attributes for the element
     */
    public function getAttributes() -> array;

    /**
     * Returns the default value assigned to the element
     */
    public function getDefault() -> var;

    /**
     * Returns the element's filters
     *
     * @return mixed
     */
    public function getFilters();

    /**
     * Returns the parent form to the element
     */
    public function getForm() -> <Form>;

    /**
     * Returns the element's label
     */
    public function getLabel() -> string;

    /**
     * Returns the messages that belongs to the element
     * The element needs to be attached to a form
     */
    public function getMessages() -> <Messages>;

    /**
     * Returns the element's name
     */
    public function getName() -> string;

    /**
     * Returns the value of an option if present
     */
    public function getUserOption(string option, var defaultValue = null) -> var;

    /**
     * Returns the options for the element
     */
    public function getUserOptions() -> array;

    /**
     * Returns the validators registered for the element
     */
    public function getValidators() -> <ValidatorInterface[]>;

    /**
     * Returns the element's value
     */
    public function getValue() -> var;

    /**
     * Checks whether there are messages attached to the element
     */
    public function hasMessages() -> bool;

    /**
     * Generate the HTML to label the element
     */
    public function label() -> string;

    /**
     * Renders the element widget
     */
    public function render(array attributes = []) -> string;

    /**
     * Sets a default attribute for the element
     */
    public function setAttribute(string attribute, var value) -> <ElementInterface>;

    /**
     * Sets default attributes for the element
     */
    public function setAttributes(array! attributes) -> <ElementInterface>;

    /**
     * Sets a default value in case the form does not use an entity
     * or there is no value available for the element in _POST
     */
    public function setDefault(var value) -> <ElementInterface>;

    /**
     * Sets the element's filters
     *
     * @param array|string filters
     */
    public function setFilters(filters) -> <ElementInterface>;

    /**
     * Sets the parent form to the element
     */
    public function setForm(<Form> form) -> <ElementInterface>;

    /**
     * Sets the element label
     */
    public function setLabel(string label) -> <ElementInterface>;

    /**
     * Sets the validation messages related to the element
     */
    public function setMessages(<Messages> messages) -> <ElementInterface>;

    /**
     * Sets the element's name
     */
    public function setName(string! name) -> <ElementInterface>;

    /**
     * Sets an option for the element
     */
    public function setUserOption(string option, var value) -> <ElementInterface>;

    /**
     * Sets options for the element
     */
    public function setUserOptions(array options) -> <ElementInterface>;
}
