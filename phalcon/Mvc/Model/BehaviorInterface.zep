
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model;

use Phalcon\Mvc\ModelInterface;

/**
 * Phalcon\Mvc\Model\BehaviorInterface
 *
 * Interface for Phalcon\Mvc\Model\Behavior
 */
interface BehaviorInterface
{
    /**
     * Calls a method when it's missing in the model
     */
    public function missingMethod(<ModelInterface> model, string! method, array arguments = []);

    /**
     * This method receives the notifications from the EventsManager
     */
    public function notify(string! type, <ModelInterface> model);
}
