
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Auth\Adapter\Config\Traits;

/**
 * Shared model-name state and accessor for auth adapter configurations.
 */
trait ModelConfigTrait
{
    protected ?string model = null;

    public function getModel() -> string | null
    {
        return this->model;
    }
}
