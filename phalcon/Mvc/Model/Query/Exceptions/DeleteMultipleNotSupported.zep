
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\Query\Exceptions;

use Phalcon\Mvc\Model\Exception;

class DeleteMultipleNotSupported extends Exception
{
    public function __construct()
    {
        parent::__construct(
            "Delete from several models at the same time is still not supported"
        );
    }
}
