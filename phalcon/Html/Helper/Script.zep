
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Helper;

/**
 * Class Script
 */
class Script extends Style
{
    /**
     * Returns the necessary attributes
     *
     * @param string $url
     * @param array  $attributes
     *
     * @return array
     */
    protected function getAttributes(string url, array attributes) -> array
    {
        array required;

        let required = [
            "src"  : url,
            "type" : "application/javascript"
        ];

        unset attributes["src"];

        return array_merge(required, attributes);
    }

    /**
     * @return string
     */
    protected function getTag() -> string
    {
        return "script";
    }
}
