
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\DataMapper\Pdo\Exception;

/**
 * A listener cancelled a cancellable "before" event, so the operation did
 * not run. This is a deliberate cancellation, not a database failure. Catch
 * this class to tell the two apart.
 */
class OperationCancelled extends Exception
{
    public function __construct(string eventName)
    {
        parent::__construct(
            "Operation cancelled by a listener of '" . eventName . "'"
        );
    }
}
