
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
interface ValidatorCompositeInterface
{
    /**
     * Executes the validation
     */
    public function getValidators() -> array;

    /**
     * Executes the validation
     */
    public function validate(<Validation> validation, var field) -> bool;
}
