
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AtlasPHP
 *
 * @link    https://github.com/atlasphp/Atlas.Pdo
 * @license https://github.com/atlasphp/Atlas.Pdo/blob/1.x/LICENSE.md
 */

namespace Phalcon\DataMapper\Pdo\Connection;

use Phalcon\DataMapper\Pdo\Exception\CannotDisconnect;
use Phalcon\DataMapper\Pdo\Profiler\Profiler;
use Phalcon\DataMapper\Pdo\Profiler\ProfilerInterface;

/**
 * Decorates an existing PDO instance with the extended methods.
 */
class Decorated extends AbstractConnection
{
    /**
     *
     * Constructor.
     *
     * This overrides the parent so that it can take an existing PDO instance
     * and decorate it with the extended methods.
     *
     * @param PDO                    $pdo
     * @param ProfilerInterface|null $profiler
     *
     */
    public function __construct(<\PDO> pdo, <ProfilerInterface> profiler = null)
    {
        let this->pdo = pdo;

        if null === profiler {
            let profiler = new Profiler();
        }

        this->setProfiler(profiler);
    }

    /**
     * Connects to the database.
     */
    public function connect() -> void
    {
        // already connected
    }

    /**
     * Disconnects from the database; disallowed with decorated PDO connections.
     *
     * @throws CannotDisconnect
     */
    public function disconnect() -> void
    {
        throw new CannotDisconnect(
            "Cannot disconnect a Decorated connection instance"
        );
    }
}
