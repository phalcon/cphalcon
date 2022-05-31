
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\File;

/**
 * Gets the filename from a given path, Same as PHP's `basename()` but has
 * non-ASCII support. PHP's `basename()` does not properly support streams or
 * filenames beginning with a non-US-ASCII character.
 */
class Basename
{
    /**
     * @see https://bugs.php.net/bug.php?id=37738
     *
     * @param string      $uri
     * @param string|null $suffix
     *
     * @return string
     */
    public function __invoke(
        string uri,
        string suffix = null
    ) -> string {
        var fileName, matches;

        let uri      = rtrim(uri, DIRECTORY_SEPARATOR),
            fileName = preg_match(
                "@[^" . preg_quote(DIRECTORY_SEPARATOR, "@") . "]+$@",
                uri,
                matches
            ) ? matches[0] : "";

        if (true !== empty(suffix)) {
            let fileName = preg_replace(
                "@" . preg_quote(suffix, "@") . "$@",
                "",
                fileName
            );
        }

        return fileName;
    }
}
