
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

class SqliteAlterCheckNotSupported extends Exception
{
    public function __construct()
    {
        parent::__construct(
            "Adding a CHECK constraint to an existing table is not supported by SQLite"
        );
    }
}
