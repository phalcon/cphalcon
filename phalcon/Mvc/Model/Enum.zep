/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model;

/**
 * Constants for the Model namespace
 */
class Enum
{
    const DIRTY_STATE_DETACHED   = 2;
    const DIRTY_STATE_PERSISTENT = 0;
    const DIRTY_STATE_TRANSIENT  = 1;
    const OP_CREATE              = 1;
    const OP_DELETE              = 3;
    const OP_NONE                = 0;
    const OP_UPDATE              = 2;
    const TRANSACTION_INDEX      = "transaction";
}
