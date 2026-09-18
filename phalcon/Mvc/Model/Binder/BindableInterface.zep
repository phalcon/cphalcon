
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\Binder;

/**
 * Interface for bindable classes
 */
interface BindableInterface
{
    /**
     * Return the model name or models names and parameters keys associated with
     * this class
     *
     * @phpstan-return array<array-key, string>|string
     */
    public function getModelName() -> array | string;
}
