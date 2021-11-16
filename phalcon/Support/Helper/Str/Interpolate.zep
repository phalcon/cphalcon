
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Str;

/**
 * Interpolates context values into the message placeholders. By default, the
 * right and left tokens are `%`
 *
 * @see http://www.php-fig.org/psr/psr-3/ Section 1.2 Message
 */
class Interpolate
{
    /**
     * @param string $message
     * @param array  $context
     */
    public function __invoke(
        string message,
        array context = [],
        string leftToken = "%",
        string rightToken = "%"
    ) -> string {
        var key, value;
        array replace;

        if !empty context {
            let replace = [];

            for key, value in context {
                let replace[leftToken . key . rightToken] = value;
            }

            return strtr(message, replace);
        }

        return message;
    }
}
