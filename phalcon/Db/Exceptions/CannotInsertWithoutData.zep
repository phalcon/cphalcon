
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

class CannotInsertWithoutData extends Exception
{
    public function __construct(string table)
    {
        parent::__construct("Unable to insert into " . table . " without data");
    }
}
