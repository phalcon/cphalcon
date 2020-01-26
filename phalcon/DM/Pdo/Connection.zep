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

namespace Phalcon\DM\Pdo;

use InvalidArgumentException;
use Phalcon\DM\Pdo\Connection\AbstractConnection;
use Phalcon\DM\Pdo\Profiler\Profiler;
use Phalcon\DM\Pdo\Profiler\ProfilerInterface;

/**
 * Provides array quoting, profiling, a new `perform()` method, new `fetch*()`
 * methods
 *
 * @property array             $arguments
 * @property PDO               $pdo
 * @property ProfilerInterface $profiler
 */
class Connection extends AbstractConnection
{
    /**
     * @var array
     */
    protected arguments = [];

    /**
     * Constructor.
     *
     * This overrides the parent so that it can take connection attributes as a
     * constructor parameter, and set them after connection.
     *
     * @param string            $dsn
     * @param string            $username
     * @param string            $password
     * @param array             $options
     * @param array             $queries
     * @param ProfilerInterface $profiler
     */
    public function __construct(
        string dsn,
        string username = null,
        string password = null,
        array options = [],
        array queries = [],
        <ProfilerInterface> profiler = null
    ) {
        var parts;
        array available;

        let parts     = explode(":", dsn),
            available = [
                "mysql"  : true,
                "pgsql"  : true,
                "sqlite" : true,
                "mssql"  : true
            ];

        if !isset available[parts[0]] {
            throw new InvalidArgumentException(
                "Driver not supported [" . parts[0] . "]"
            );
        }


        // if no error mode is specified, use exceptions
        if !isset options[\PDO::ATTR_ERRMODE] {
            let options[\PDO::ATTR_ERRMODE] = \PDO::ERRMODE_EXCEPTION;
        }

        // Arguments store
        let this->arguments = [
            dsn,
            username,
            password,
            options,
            queries
        ];

        // Create a new profiler if none has been passed
        if profiler === null {
            let profiler = new Profiler();
        }
        this->setProfiler(profiler);
    }

    /**
     * The purpose of this method is to hide sensitive data from stack traces.
     *
     * @return array
     */
    public function __debugInfo() -> array
    {
        return [
            "arguments" : [
                this->arguments[0],
                "****",
                "****",
                this->arguments[3],
                this->arguments[4]
            ]
        ];
    }

    /**
     * Connects to the database.
     */
    public function connect() -> void
    {
        var dsn, options, password, query, queries, username;

        if !this->pdo {
            // connect
            this->profiler->start(__FUNCTION__);

            let dsn      = this->arguments[0],
                username = this->arguments[1],
                password = this->arguments[2],
                options  = this->arguments[3],
                queries  = this->arguments[4];

            let this->pdo = new \PDO(dsn, username, password, options);

            this->profiler->finish();

            // connection-time queries
            for query in queries {
                this->exec(query);
            }
        }
    }

    /**
     * Disconnects from the database.
     */
    public function disconnect() -> void
    {
        this->profiler->start(__FUNCTION__);

        let this->pdo = null;

        this->profiler->finish();
    }
}
