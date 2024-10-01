
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

namespace Phalcon\Filter\Validation;

use Phalcon\Di\Injectable;
use Phalcon\Messages\MessageInterface;
use Phalcon\Messages\Messages;

/**
 * Interface for the Phalcon\Filter\Validation component
 */
interface ValidationInterface
{
    /**
     * Adds a validator to a field
     *
     * @param string|array       $field
     * @param ValidatorInterface $validator
     */
    public function add(var field, <ValidatorInterface> validator) -> <ValidationInterface>;

    /**
     * Appends a message to the messages list
     */
    public function appendMessage(<MessageInterface> message) -> <ValidationInterface>;

    /**
     * Assigns the data to an entity
     * The entity is used to obtain the validation values
     *
     * @param object entity
     * @param array|object data
     */
    public function bind(entity, data) -> <ValidationInterface>;

    /**
     * Returns the bound entity
     *
     * @return object
     */
    public function getEntity() -> var;

    /**
     * Returns all the filters or a specific one
     */
    public function getFilters(string field = null) -> var | null;

    /**
     * Get label for field
     */
    public function getLabel(string! field) -> string;

    /**
     * Returns the registered validators
     */
    public function getMessages() -> <Messages>;

    /**
     * Returns the validators added to the validation
     */
    public function getValidators() -> array;

    /**
     * Gets the a value to validate in the array/object data source
     */
    public function getValue(string field) -> var | null;

    /**
     * Alias of `add` method
     *
     * @param string|array       $field
     * @param ValidatorInterface $validator
     */
    public function rule(var field, <ValidatorInterface> validator) -> <ValidationInterface>;

    /**
     * Adds the validators to a field
     */
    public function rules(string! field, array! validators) -> <ValidationInterface>;

    /**
     * Adds filters to the field
     *
     * @param array|string filters
     */
    public function setFilters(string field, filters) -> <ValidationInterface>;

    /**
     * Adds labels for fields
     */
    public function setLabels(array! labels) -> void;

    /**
     * Validate a set of data according to a set of rules
     *
     * @param array|object data
     * @param object entity
     *
     * @return Messages|false
     */
    public function validate(var data = null, var entity = null) -> <Messages> | bool;
}
