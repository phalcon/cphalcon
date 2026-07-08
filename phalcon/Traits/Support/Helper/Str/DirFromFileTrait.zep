
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
 * Accepts a file name (without extension) and returns a calculated
 * directory structure with the filename in the end
 */
trait DirFromFileTrait
{
    /**
     * @param string $file
     * @param bool   $filesystemSafe
     *
     * @return string
     */
    protected static function toDirFromFile(string file, bool filesystemSafe = false) -> string
    {
        var name, start;

        let name  = pathinfo(file, PATHINFO_FILENAME);
        let start = mb_substr(name, 0, -2);

        if (filesystemSafe === true && !empty start) {
            let start = str_replace(".", "-", start);
        }

        if (!start) {
            let start = mb_substr(name, 0, 1);
        }

        return implode("/", mb_str_split(start, 2)) . "/";
    }
}
