
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter\Validation;

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Exceptions\NoValidatorsInComposite;

/**
 * This is a base class for combined fields validators
 */
abstract class AbstractValidatorComposite extends AbstractValidator implements ValidatorCompositeInterface
{
    /**
     * @var array
     */
    protected validators = [];

    /**
     * @return array
     */
    public function getValidators() -> array
    {
        return this->validators;
    }

    /**
     * Executes the validation
     */
    public function validate(<Validation> validation, var field) -> bool
    {
        var validator;

        if unlikely count(this->getValidators()) === 0 {
            throw new NoValidatorsInComposite(get_class(this));
        }

        for validator in this->getValidators() {
            if validator->validate(validation, field) === false {
                return false;
            }
        }

        return true;
    }
}
