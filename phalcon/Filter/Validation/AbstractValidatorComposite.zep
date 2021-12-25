
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

/**
 * This is a base class for combined fields validators
 */
abstract class AbstractValidatorComposite extends AbstractValidator implements ValidatorCompositeInterface
{
    /**
     * @var array
     */
    protected validators = [] { get };

    /**
     * Executes the validation
     */
    public function validate(<Validation> validation, var field) -> bool
    {
        var validator;

        if unlikely count(this->getValidators()) === 0 {
            throw new Exception(get_class(this) . " does not have any validator added");
        }

        for validator in this->getValidators() {
            if validator->validate(validation, field) === false {
                return false;
            }
        }

        return true;
    }
}
