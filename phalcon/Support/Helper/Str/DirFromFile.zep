
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Str;

use Phalcon\Traits\Support\Helper\Str\DirFromFileTrait;

/**
 * Accepts a file name (without extension) and returns a calculated
 * directory structure with the filename in the end
 */
class DirFromFile
{
    use DirFromFileTrait;

    public function __invoke(string file) -> string
    {
        return this->toDirFromFile(file);
    }
}
