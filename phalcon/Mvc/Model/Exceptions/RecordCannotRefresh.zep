
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\Exceptions;

use Phalcon\Mvc\Model\Exception;

class RecordCannotRefresh extends Exception
{
    public function __construct(string className)
    {
        parent::__construct(
            "The record cannot be refreshed because it does not exist or is deleted in '" . className . "'"
        );
    }
}
