
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */

namespace Phalcon\Auth\Adapter\Config;

use Phalcon\Auth\Adapter\Config\Traits\ModelConfigTrait;
use Phalcon\Contracts\Auth\Adapter\AdapterConfig;

/**
 * @todo Remove in v7. Kept only for backwards compatibility; compose
 * Phalcon\Auth\Adapter\Config\Traits\ModelConfigTrait directly instead of
 * extending this.
 */
abstract class AbstractAdapterConfig implements AdapterConfig
{
    use ModelConfigTrait;

    public function __construct(string model = null)
    {
        let this->model = model;
    }
}
