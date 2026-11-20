
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter\Validation\Validator\StringLength;

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\AbstractValidator;
use Phalcon\Traits\Php\InfoTrait;

/**
 * Shared validation for the string length validators. The validator compares
 * the length with its limit in validateLength().
 */
abstract class AbstractStringLength extends AbstractValidator
{
    use InfoTrait;

    /**
     * Executes the validation
     */
    public function validate(<Validation> validation, var field) -> bool
    {
        var length, value;

        let value = validation->getValue(field);
        if this->allowEmpty(field, value) {
            return true;
        }

        if this->rejectNonStringable(validation, field, value) {
            return false;
        }

        // Check if mbstring is available to calculate the correct length
        if this->phpFunctionExists("mb_strlen") {
            let length = mb_strlen((string) value);
        } else {
            let length = strlen((string) value);
        }

        return this->validateLength(validation, field, length);
    }

    /**
     * Compares the length of the value with the limit
     */
    abstract protected function validateLength(
        <Validation> validation,
        var field,
        int length
    ) -> bool;
}
