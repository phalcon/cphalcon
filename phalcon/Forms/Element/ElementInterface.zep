
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Forms\Element;

use Phalcon\Contracts\Forms\FormsTypes;
use Phalcon\Contracts\Html\HtmlTypes;
use Phalcon\Filter\Validation\ValidatorInterface;
use Phalcon\Forms\Form;
use Phalcon\Messages\MessageInterface;
use Phalcon\Messages\Messages;

/**
 * Interface for Phalcon\Forms\Element classes
 *
 * @phpstan-import-type forms_attributes from FormsTypes
 * @phpstan-import-type forms_filters from FormsTypes
 * @phpstan-import-type forms_options from FormsTypes
 * @phpstan-import-type forms_validators from FormsTypes
 * @phpstan-import-type html_attributes from HtmlTypes
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
     * @phpstan-param array<array-key, mixed> $validators
     */
    public function addValidators(array validators, bool merge = true) -> <ElementInterface>;

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
     *
     * @phpstan-return forms_attributes
     */
    public function getAttributes() -> array;

    /**
     * Returns the default value assigned to the element
     */
    public function getDefault() -> var;

    /**
     * Returns the element's filters
     *
     * @phpstan-return forms_filters
     */
    public function getFilters();

    /**
     * Returns the parent form to the element
     */
    public function getForm() -> <Form>;

    /**
     * Returns the element's label
     */
    public function getLabel() -> string | null;

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
     *
     * @phpstan-return forms_options
     */
    public function getUserOptions() -> array;

    /**
     * Returns the validators registered for the element
     *
     * @phpstan-return forms_validators
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
     *
     * @phpstan-param html_attributes $attributes
     */
    public function render(array attributes = []) -> string;

    /**
     * Sets a default attribute for the element
     */
    public function setAttribute(string attribute, var value) -> <ElementInterface>;

    /**
     * Sets default attributes for the element
     *
     * @phpstan-param forms_attributes $attributes
     */
    public function setAttributes(array attributes) -> <ElementInterface>;

    /**
     * Sets a default value in case the form does not use an entity
     * or there is no value available for the element in _POST
     */
    public function setDefault(var value) -> <ElementInterface>;

    /**
     * Sets the element's filters
     *
     * @phpstan-param forms_filters|string $filters
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
    public function setName(string name) -> <ElementInterface>;

    /**
     * Sets an option for the element
     */
    public function setUserOption(string option, var value) -> <ElementInterface>;

    /**
     * Sets options for the element
     *
     * @phpstan-param forms_options $options
     */
    public function setUserOptions(array options) -> <ElementInterface>;
}
