
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

class MissingSqliteDatabase extends Exception
{
    public function __construct()
    {
        parent::__construct(
            "The database must be specified with either 'dbname' or 'dsn'."
        );
    }
}
