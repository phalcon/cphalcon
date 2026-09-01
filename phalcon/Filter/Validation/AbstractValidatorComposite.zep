
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter\Validation;

use Phalcon\Filter\Validation\Traits\ValidatorCompositeTrait;

/**
 * This is a base class for combined fields validators
 *
 * @todo Remove in v7. Kept only for backwards compatibility; compose
 * Phalcon\Filter\Validation\Traits\ValidatorCompositeTrait directly (with
 * extends AbstractValidator implements ValidatorCompositeInterface) instead of
 * extending this.
 */
abstract class AbstractValidatorComposite extends AbstractValidator implements ValidatorCompositeInterface
{
    use ValidatorCompositeTrait;
}
