
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Helper;

use InvalidArgumentException;

/**
 * This class offers a wrapper for JSON methods to serialize and unserialize
 */
class Json
{
    /**
     * Decodes a string using `json_decode` and throws an exception if the
     * JSON data cannot be decoded
     *
     * ```php
     * use Phalcon\Helper\Json;
     *
     * $data = '{"one":"two","0":"three"}';
     *
     * var_dump(Json::decode($data));
     * // [
     * //     'one' => 'two',
     * //     'three'
     * // ];
     * ```
     *
     * @param string $data        JSON data to parse
     * @param bool   $associative When `true`, objects are converted to arrays
     * @param int    $depth       Recursion depth.
     * @param int    $options     Bitmask of JSON decode options.
     *
     * @return mixed
     *
     * @throws \InvalidArgumentException if the JSON cannot be decoded.
     * @link http://www.php.net/manual/en/function.json-decode.php
     */
    final public static function decode(
        string! data,
        bool associative = false,
        int depth = 512,
        int options = 0
    ) -> var
    {
        var decoded;

        let decoded = json_decode(data, associative, depth, options);

        if unlikely JSON_ERROR_NONE !== json_last_error() {
            throw new InvalidArgumentException(
                "json_decode error: " . json_last_error_msg()
            );
        }

        return decoded;
    }

    /**
     * Encodes a string using `json_encode` and throws an exception if the
     * JSON data cannot be encoded
     *
     * ```php
     * use Phalcon\Helper\Json;
     *
     * $data = [
     *     'one' => 'two',
     *     'three'
     * ];
     *
     * echo Json::encode($data);
     * // {"one":"two","0":"three"}
     * ```
     *
     * @param mixed  $data        JSON data to parse
     * @param int    $options     Bitmask of JSON decode options.
     * @param int    $depth       Recursion depth.
     *
     * @return mixed
     *
     * @throws \InvalidArgumentException if the JSON cannot be encoded.
     * @link http://www.php.net/manual/en/function.json-encode.php
     */
    final public static function encode(
        var data,
        int options = 0,
        int depth = 512
    ) -> string
    {
        var encoded;

        let encoded = json_encode(data, options, depth);

        if unlikely JSON_ERROR_NONE !== json_last_error() {
            throw new InvalidArgumentException(
                "json_encode error: " . json_last_error_msg()
            );
        }

        return encoded;
    }
}
