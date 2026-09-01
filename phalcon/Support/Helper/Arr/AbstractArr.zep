
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Arr;

use Phalcon\Traits\Support\Helper\Arr\FilterTrait;

/**
 * @internal
 *
 * @todo Remove in v7. Kept only for backwards compatibility; compose
 * Phalcon\Traits\Support\Helper\Arr\FilterTrait directly instead of extending
 * this.
 */
abstract class AbstractArr
{
    use FilterTrait;
}
