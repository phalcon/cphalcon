
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Validation;

use Phalcon\Collection;
use Phalcon\Validation;

/**
 * Interface for Phalcon\Validation\AbstractValidator
 */
interface ValidatorInterface
{
    /**
     * Returns an option in the validator's options
     * Returns null if the option hasn't set
     *
     * @return mixed
     */
    public function getOption(string! key, var defaultValue = null) -> var;

    /**
     * Checks if an option is defined
     *
     * @return boolean
     */
    public function hasOption(string! key) -> bool;

    /**
     * Executes the validation
     *
     * @return boolean
     */
    public function validate(<Validation> validation, var field) -> bool;

    /**
    * Get the template message
    *
    * @return string
    * @throw InvalidArgumentException When the field does not exists
    */
    public function getTemplate(string! field) -> string;

    /**
    * Get message templates
    *
    * @return array
    */
    public function getTemplates() -> array;

    /**
    * Clear current template and set new from an array,
    *
    * @return ValidatorInterface
    */
    public function setTemplates(array! templates) -> <ValidatorInterface>;

    /**
    * Set a new template message
    *
    * @return ValidatorInterface
    */
    public function setTemplate(string! template) -> <ValidatorInterface>;
}
