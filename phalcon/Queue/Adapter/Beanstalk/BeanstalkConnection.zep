
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this component has been inspired by the queue-interop and
 * enqueue projects.
 *
 * @link    https://github.com/queue-interop/queue-interop
 * @license https://github.com/queue-interop/queue-interop/blob/master/LICENSE
 *
 * @link    https://github.com/php-enqueue/enqueue-dev
 * @license https://github.com/php-enqueue/enqueue-dev/blob/master/LICENSE
 */

namespace Phalcon\Queue\Adapter\Beanstalk;

use Phalcon\Queue\Exceptions\Exception;

/**
 * Dependency-free socket client for the Beanstalkd work queue, implementing
 * the subset of the 1.2 protocol the adapter needs (use/watch/ignore, put,
 * reserve-with-timeout, delete/release/bury/touch). Recovered and trimmed
 * from the original Phalcon\Queue\Beanstalk transport.
 */
class BeanstalkConnection
{
    /**
     * Connection resource.
     *
     * @var resource
     */
    protected connection;

    /**
     * @var string
     */
    protected host = "127.0.0.1";

    /**
     * @var bool
     */
    protected persistent = false;

    /**
     * @var int
     */
    protected port = 11300;

    public function __construct(string host = "127.0.0.1", int port = 11300, bool persistent = false)
    {
        let this->host       = host,
            this->port       = port,
            this->persistent = persistent;
    }

    /**
     * Puts a reserved job into the "buried" state.
     */
    public function buryJob(string id, int priority) -> bool
    {
        this->write("bury " . id . " " . priority);

        return this->readStatus()[0] == "BURIED";
    }

    /**
     * Opens the socket connection to the Beanstalkd server.
     */
    public function connect() -> resource
    {
        var connection, errorLevel;

        let connection = this->connection;

        if typeof connection == "resource" {
            this->disconnect();
        }

        /**
         * Suppress the connection warning; the failure is handled by the
         * typeof check below. Zephir has no `@` operator, so error reporting
         * is toggled around the call instead.
         */
        let errorLevel = error_reporting(0);

        if this->persistent {
            let connection = pfsockopen(this->host, this->port, null, null);
        } else {
            let connection = fsockopen(this->host, this->port, null, null);
        }

        error_reporting(errorLevel);

        if typeof connection != "resource" {
            throw new Exception("Can't connect to the Beanstalk server");
        }

        stream_set_timeout(connection, -1, null);

        let this->connection = connection;

        return connection;
    }

    /**
     * Removes a job from the server entirely.
     */
    public function deleteJob(string id) -> bool
    {
        this->write("delete " . id);

        return this->readStatus()[0] == "DELETED";
    }

    /**
     * Closes the connection to the server.
     */
    public function disconnect() -> bool
    {
        var connection;

        let connection = this->connection;

        if typeof connection != "resource" {
            return false;
        }

        fclose(connection);

        let this->connection = null;

        return true;
    }

    /**
     * Removes the named tube from the watch list for the connection.
     */
    public function ignoreTube(string tube) -> bool
    {
        this->write("ignore " . tube);

        return this->readStatus()[0] == "WATCHING";
    }

    /**
     * Puts a job on the queue using the currently used tube. Returns the new
     * job id, or false when the server did not accept it.
     */
    public function put(string data, int priority, int delay, int ttr) -> int | bool
    {
        var response, status;
        int length;

        let length = strlen(data);

        this->write("put " . priority . " " . delay . " " . ttr . " " . length . "\r\n" . data);

        let response = this->readStatus();

        if !isset response[0] {
            return false;
        }

        let status = response[0];

        if status != "INSERTED" && status != "BURIED" {
            return false;
        }

        return (int) response[1];
    }

    /**
     * Reads a packet from the socket. Verifies the connection is available
     * first.
     */
    public function read(int length = 0) -> bool | string
    {
        var connection, data, meta;

        let connection = this->connection;

        if typeof connection != "resource" {
            let connection = this->connect();
        }

        if length {
            if feof(connection) {
                return false;
            }

            let data = rtrim(stream_get_line(connection, length + 2), "\r\n"),
                meta = stream_get_meta_data(connection);

            if meta["timed_out"] {
                throw new Exception("Connection timed out");
            }
        } else {
            let data = stream_get_line(connection, 16384, "\r\n");
        }

        if data === "UNKNOWN_COMMAND" {
            throw new Exception("UNKNOWN_COMMAND");
        }

        if data === "JOB_TOO_BIG" {
            throw new Exception("JOB_TOO_BIG");
        }

        if data === "BAD_FORMAT" {
            throw new Exception("BAD_FORMAT");
        }

        if data === "OUT_OF_MEMORY" {
            throw new Exception("OUT_OF_MEMORY");
        }

        return data;
    }

    /**
     * Reads the latest status line and splits it into tokens.
     */
    public function readStatus() -> array
    {
        var status;

        let status = this->read();

        if status === false {
            return [];
        }

        return explode(" ", status);
    }

    /**
     * Puts a reserved job back into the ready queue.
     */
    public function releaseJob(string id, int priority, int delay) -> bool
    {
        this->write("release " . id . " " . priority . " " . delay);

        return this->readStatus()[0] == "RELEASED";
    }

    /**
     * Reserves a ready job from a watched tube. A null timeout blocks until a
     * job is available; otherwise it blocks up to timeout seconds. Returns
     * [id, body] or null when none is reserved.
     */
    public function reserve(var timeout = null) -> array | null
    {
        var command, response;

        if timeout !== null {
            let command = "reserve-with-timeout " . timeout;
        } else {
            let command = "reserve";
        }

        this->write(command);

        let response = this->readStatus();

        if !isset response[0] || response[0] != "RESERVED" {
            return null;
        }

        return [response[1], this->read((int) response[2])];
    }

    /**
     * Extends the time-to-run of a reserved job.
     */
    public function touchJob(string id) -> bool
    {
        this->write("touch " . id);

        return this->readStatus()[0] == "TOUCHED";
    }

    /**
     * Changes the tube new jobs are put on. By default this is "default".
     */
    public function useTube(string tube) -> bool
    {
        this->write("use " . tube);

        return this->readStatus()[0] == "USING";
    }

    /**
     * Adds the named tube to the watch list for the connection.
     */
    public function watchTube(string tube) -> bool
    {
        this->write("watch " . tube);

        return this->readStatus()[0] == "WATCHING";
    }

    /**
     * Writes data to the socket, connecting first when needed.
     */
    public function write(string data) -> bool | int
    {
        var connection, packet;

        let connection = this->connection;

        if typeof connection != "resource" {
            let connection = this->connect();
        }

        let packet = data . "\r\n";

        return fwrite(connection, packet, strlen(packet));
    }
}
