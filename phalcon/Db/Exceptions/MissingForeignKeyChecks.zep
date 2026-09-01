
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Db\Exceptions;

use Phalcon\Db\Exception;

class MissingForeignKeyChecks extends Exception
{
    public function __construct()
    {
        parent::__construct("DATABASE PARAMETER 'FOREIGN_KEY_CHECKS' HAS TO BE 1");
    }
}
