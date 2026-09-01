
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

class MysqlOnConflictNotSupported extends Exception
{
    public function __construct()
    {
        parent::__construct(
            "ON CONFLICT upserts are not supported by MySQL; use INSERT ... ON DUPLICATE KEY UPDATE via raw SQL instead"
        );
    }
}
