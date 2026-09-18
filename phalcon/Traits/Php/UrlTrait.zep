
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
 * URL based wrapper methods
 *
 * @phpstan-type traits_parse_url array{
 *       scheme?: string,
 *       host?: string,
 *       port?: int<0, 65535>,
 *       user?: string,
 *       pass?: string,
 *       path?: string,
 *       query?: string,
 *       fragment?: string
 *  }
 */
trait UrlTrait
{
    /**
     * @param string $url
     * @param int    $component
     *
     * @return bool|int|string|traits_parse_url|null
     *
     * @link https://php.net/manual/en/function.parse-url.php
     */
    protected static function phpParseUrl(string url, int component = -1)
    {
        return parse_url(url, component);
    }

    /**
     * @param string $input
     *
     * @return string
     *
     * @link https://php.net/manual/en/function.rawurldecode.php
     */
    protected static function phpRawUrlDecode(string input) -> string
    {
        return rawurldecode(input);
    }

    /**
     * @param string $input
     *
     * @return string
     *
     * @link https://php.net/manual/en/function.rawurlencode.php
     */
    protected static function phpRawUrlEncode(string input) -> string
    {
        return rawurlencode(input);
    }
}
