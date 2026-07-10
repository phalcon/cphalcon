
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Traits\Php;

/**
 * Base64 based wrapper methods
 */
trait Base64Trait
{
    /**
     * Decode a Base64 URL string
     *
     * @param string $input
     *
     * @return string
     */
    protected static function doDecodeUrl(string input) -> string
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

    /**
     * Encode a string in Base64 URL format
     *
     * @param string $input
     *
     * @return string
     */
    protected static function doEncodeUrl(string input) -> string
    {
        return str_replace("=", "", strtr(base64_encode(input), "+/", "-_"));
    }

    /**
     * @param string $input
     * @param bool   $strict
     *
     * @return string|false
     *
     * @link https://php.net/manual/en/function.base64-decode.php
     */
    protected static function phpBase64Decode(string input, bool strict = false)
    {
        return base64_decode(input, strict);
    }

    /**
     * @param string $input
     *
     * @return string
     *
     * @link https://php.net/manual/en/function.base64-encode.php
     */
    protected static function phpBase64Encode(string input) -> string
    {
        return base64_encode(input);
    }
}
