
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

class InvalidModuleDefinitionPath extends Exception
{
    public function __construct()
    {
        parent::__construct("Invalid module definition path");
    }
}
