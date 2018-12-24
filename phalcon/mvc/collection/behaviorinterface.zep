
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Collection;

use Phalcon\Mvc\CollectionInterface;

/**
 * Phalcon\Mvc\Collection\BehaviorInterface
 *
 * Interface for Phalcon\Mvc\Collection\Behavior
 */
interface BehaviorInterface
{
	/**
	 * This method receives the notifications from the EventsManager
	 */
	public function notify(string! type, <CollectionInterface> collection);

	/**
	 * Calls a method when it's missing in the collection
	 */
	public function missingMethod(<CollectionInterface> collection, string !method, array arguments = []);

}
