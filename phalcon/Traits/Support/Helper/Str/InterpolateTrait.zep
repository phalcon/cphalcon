
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Traits\Support\Helper\Str;

/**
 * Interpolates context values into the message placeholders
 *
 * @see http://www.php-fig.org/psr/psr-3/ Section 1.2 Message
 */
trait InterpolateTrait
{
    /**
     * @param string   $input
     * @param string[] $context
     * @param string   $left
     * @param string   $right
     *
     * @return string
     */
    protected static function toInterpolate(
        string input,
        array context = [],
        string left = "%",
        string right = "%"
    ) -> string {
        var key, value;
        array replace = [];

        if (empty(context)) {
            return input;
        }

        if (false === strpos(input, left)) {
            return input;
        }

        for key, value in context {
            let replace[left . key . right] = value;
        }

        return strtr(input, replace);
    }
}
