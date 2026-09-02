
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter\Validation\Traits;

use Phalcon\Contracts\Filter\FilterTypes;

/**
 * Shared validator collection state and combined validation for composite
 * validators.
 *
 * @phpstan-import-type filter_validators from FilterTypes
 */
trait ValidatorCompositeTrait
{
    /**
     * @var array
     *
     * @todo Use a default [] once Zephir supports array trait defaults
     */
    protected validators = null;

    /**
     * @phpstan-return filter_validators
     */
    public function getValidators() -> array
    {
        return (array) this->validators;
    }

    /**
     * Executes the validation
     */
    public function validate(<\Phalcon\Filter\Validation> validation, var field) -> bool
    {
        var validator;

        if unlikely empty this->getValidators() {
            throw new \Phalcon\Filter\Validation\Exceptions\NoValidatorsInComposite(
                get_class(this)
            );
        }

        for validator in this->getValidators() {
            if validator->validate(validation, field) === false {
                return false;
            }
        }

        return true;
    }
}
