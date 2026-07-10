
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Str;

use Phalcon\Traits\Support\Helper\Str\EndsWithTrait;
use Phalcon\Traits\Support\Helper\Str\InterpolateTrait;
use Phalcon\Traits\Support\Helper\Str\LowerTrait;
use Phalcon\Traits\Support\Helper\Str\StartsWithTrait;
use Phalcon\Traits\Support\Helper\Str\UpperTrait;

/**
 * Abstract class offering methods to help with the Str namespace.
 *
 * @internal
 *
 * @todo Remove in v7. Kept only for backwards compatibility; compose the
 *       individual Phalcon\Traits\Support\Helper\Str\* traits directly instead
 *       of extending this.
 */
abstract class AbstractStr
{
    use EndsWithTrait;
    use InterpolateTrait;
    use LowerTrait;
    use StartsWithTrait;
    use UpperTrait;
}
