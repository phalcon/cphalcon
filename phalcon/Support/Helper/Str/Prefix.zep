
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Str;

/**
 * Prefixes the text with the supplied prefix
 */
class Prefix
{
    /**
     * @param mixed  $text
     * @param string $prefix
     *
     * @return string
     */
    public function __invoke(var text, string prefix) -> string
    {
        return prefix . ((string) text);
    }
}
