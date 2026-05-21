
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Cli\Console\Exceptions;

use Phalcon\Cli\Console\Exception;

class ModuleDefinitionPathNotFound extends Exception
{
    public function __construct(string path)
    {
        parent::__construct(
            "Module definition path '" . path . "' does not exist"
        );
    }
}
