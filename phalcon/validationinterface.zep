
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon;

use Phalcon\Di\Injectable;
use Phalcon\Messages\MessageInterface;
use Phalcon\Messages\Messages;
use Phalcon\Validation\Exception;
use Phalcon\Validation\ValidatorInterface;

/**
 * Phalcon\ValidationInterface
 *
 * Interface for the Phalcon\Validation component
 */
interface ValidationInterface
{
    /**
     * Adds a validator to a field
     */
    public function add(string field, <ValidatorInterface> validator) -> <ValidationInterface>;

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
     * Get default message for validator type
     */
    public function getDefaultMessage(string! type) -> string;

    /**
     * Returns the bound entity
     *
     * @return object
     */
    public function getEntity() -> object;

    /**
     * Returns all the filters or a specific one
     *
     * @return mixed
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
     */
    public function rule(string field, <ValidatorInterface> validator) -> <ValidationInterface>;

    /**
     * Adds the validators to a field
     */
    public function rules(string! field, array! validators) -> <ValidationInterface>;

    /**
     * Adds default messages to validators
     */
    public function setDefaultMessages(array messages = []) -> array;

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
     */
    public function validate(var data = null, var entity = null) -> <Messages>;
}
