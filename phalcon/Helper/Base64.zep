
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */


namespace Phalcon\Helper;

/**
 * Phalcon\Helper\Base64
 *
 * This class offers quick string base64 functions
 */
class Base64
{
    /**
     * Encode a json string in Base64 Url format.
     *
     * @param string $input
     *
     * @return string
     */
    final public static function encodeUrl(string! input) -> string
    {
        return str_replace("=", "", strtr(base64_encode($input), "+/", "-_"));
    }

    /**
     * Decode a Base64 Url string to a json string
     *
     * @param string $input
     *
     * @return string
     */
    final public static function decodeUrl(string! input) -> string
    {
        var data, remainder;

        let remainder = mb_strlen(input) % 4;
        if remainder {
            let input .= str_repeat("=", 4 - remainder);
        }

        let data = base64_decode(strtr(input, "-_", "+/"));
        if (false === data) {
            let data = "";
        }

        return data;
    }
}
