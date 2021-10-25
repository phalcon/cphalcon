
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Str;

/**
 * Class Prefix
 *
 * @package Phalcon\Support\Str
 */
class Prefix
{
    /**
     * Prefixes the text with the supplied prefix
     *
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
