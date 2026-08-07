
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Str;

use Phalcon\Traits\Support\Helper\Str\InterpolateTrait;

/**
 * Interpolates context values into the message placeholders. By default, the
 * right and left tokens are `%`
 *
 * @see https://www.php-fig.org/psr/psr-3/ Section 1.2 Message
 */
class Interpolate
{
    use InterpolateTrait;

    /**
     * @param string[] $context
     */
    public function __invoke(
        string message,
        array context = [],
        string leftToken = "%",
        string rightToken = "%"
    ) -> string {
        return this->toInterpolate(message, context, leftToken, rightToken);
    }
}
