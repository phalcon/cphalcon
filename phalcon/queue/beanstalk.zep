
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 |          Dmitry Korolev <chameleonweb2012@gmail.com>                   |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Queue;

use Phalcon\Queue\Beanstalk\Job;
use Phalcon\Queue\Beanstalk\Exception;

/**
 * Phalcon\Queue\Beanstalk
 *
 * Class to access the beanstalk queue service.
 * Partially implements the protocol version 1.2
 *
 * <code>
 * use Phalcon\Queue\Beanstalk;
 *
 * $queue = new Beanstalk([
 *     'host'       => '127.0.0.1',
 *     'port'       => 11300,
 *     'persistent' => true,
 * ]);
 * </code>
 *
 * @link http://www.igvita.com/2010/05/20/scalable-work-queues-with-beanstalk/
 */
class Beanstalk
{    
    /**
     * Seconds to wait before putting the job in the ready queue.
     * The job will be in the "delayed" state during this time.
     *
     * @const integer
     */
    const DEFAULT_DELAY = 0;

    /**
     * Jobs with smaller priority values will be scheduled before jobs with larger priorities.
     * The most urgent priority is 0, the least urgent priority is 4294967295.
     *
     * @const integer
     */
    const DEFAULT_PRIORITY = 100;

    /**
     * Time to run - number of seconds to allow a worker to run this job.
     * The minimum ttr is 1.
     *
     * @const integer
     */
    const DEFAULT_TTR = 86400;

    /**
     * Default tube name
     * @const string
     */
    const DEFAULT_TUBE = 'default';

    /**
     * Default connected host
     * @const string
     */
    const DEFAULT_HOST = "127.0.0.1";

    /**
     * Default connected port
     * @const integer
     */
    const DEFAULT_PORT = 11300;

    /**
     * Connection resource
     * 
     * @var resource
     */
     protected _connection;

    /**
     * Keys:
     * host - beanstalkd connect host
     * port - beanstalkd connect port
     * 
     * @var array Description
     */
     protected _parameters;

    /**
     * Phalcon\Queue\Beanstalk
     *
     * @param array options
     */
    public function __construct(var options = null)
    {
        var parameters;

        if typeof options != "array" {
            let parameters = [];
        } else {
            let parameters = options;
        }

        if !isset parameters["host"] {
            let parameters["host"] = self::DEFAULT_HOST;
        }

        if !isset parameters["port"]  {
            let parameters["port"] = self::DEFAULT_PORT;
        }

        let this->_parameters = parameters;
    }

    /**
     * Makes a connection to the Beanstalkd server
     */
    public function connect() -> resource
    {
        var connection, parameters, persistent, $function;

        let connection = this->_connection;
        if typeof connection == "resource" {
            this->disconnect();
        }

        let parameters = this->_parameters;

        /**
         * Check if the connection must be persistent
         */
        if fetch persistent, parameters["persistent"] {
            if persistent {
                let $function = "pfsockopen";
            } else {
                let $function = "fsockopen";
            }
        } else {
            let $function = "fsockopen";
        }

        let connection = {$function}(parameters["host"], parameters["port"], null, null);

        if typeof connection != "resource" {
            throw new Exception("Can't connect to Beanstalk server");
        }

        stream_set_timeout(connection, -1, null);

        let this->_connection = connection;

        return connection;
    }

    /**
     * Puts a job on the queue using specified tube.
     *
     * @param string $data is the job body. This value must be less than max-job-size (default: 2**16).
     * @param array  $options
     * <b>pri</b>(options key name priority) is an integer < 2**32. Jobs with smaller priority values will be 
     * scheduled before jobs with larger priorities. The most urgent priority is 0;
     * the least urgent priority is 4,294,967,295.
     * <br><b>delay</b> is an integer number of seconds to wait before putting the job in
     * the ready queue. The job will be in the "delayed" state during this time.
     * <br><b>ttr</b> -- time to run -- is an integer number of seconds to allow a worker
     * to run this job. This time is counted from the moment a worker reserves 
     * this job. If the worker does not delete, release, or bury the job within
     * <i>ttr</i> seconds, the job will time out and the server will release the
     * job. The minimum ttr is 1. If the client sends 0, the server will
     * silently increase the ttr to 1.
     * @return boolean|integer job id or false
     */
    public function put(var data, var options = null) -> int|boolean
    {
        var priority, delay, ttr, serialized, response, status, length;

        /**
         * Priority is 100 by default
         */
        if !fetch priority, options["priority"] {
            let priority = self::DEFAULT_PRIORITY;
        }

        if !fetch delay, options["delay"] {
            let delay = self::DEFAULT_DELAY;
        }

        if !fetch ttr, options["ttr"] {
            let ttr = self::DEFAULT_TTR;
        }

        /**
         * Data is automatically serialized before be sent to the server
         */
        let serialized = serialize(data);

        /**
         * Create the command
         */
        let length = strlen(serialized);
        this->write("put " . priority . " " . delay . " " . ttr . " " . length);
        this->write(serialized);

        let response = this->readStatus();
        let status = response[0];

        if status != "INSERTED" && status != "BURIED" {
            return false;
        }

        return (int) response[1];
    }

    /**
     * Reserves/locks a ready job from the specified tube.
     * This will return a newly-reserved job. If no job is available to be 
     * reserved, beanstalkd will wait to send a response until one becomes 
     * available. Once a job is reserved for the client, the client has limited 
     * time to run (TTR) the job before the job times out. When the job times 
     * out, the server will put the job back into the ready queue. Both the TTR 
     * and the actual time left can be found in response to the stats-job command.
     * <br>If more than one job is ready, beanstalkd will choose the one with 
     * the smallest priority value. Within each priority, it will choose the one
     * that was received first.
     * <br>A timeout value of 0 will cause the server to immediately return 
     * either a response or TIMED_OUT. A positive value of timeout will limit 
     * the amount of time the client will block on the reserve request until a 
     * job becomes available.
     *
     * @param  integer          $timeout seconds
     * @return boolean|\Phalcon\Queue\Beanstalk\Job
     */
    public function reserve(var timeout = null) -> boolean|<Job>
    {
        var command, response;

        if typeof timeout != "null" {
            let command = "reserve-with-timeout " . timeout;
        } else {
            let command = "reserve";
        }

        this->write(command);

        let response = this->readStatus();
        if response[0] != "RESERVED" {
            return false;
        }

        /**
         * The job is in the first position
         * Next is the job length
         * The body is serialized
         * Create a beanstalk job abstraction
         */
        return new Job(this, response[1], unserialize(this->read(response[2])));
    }

    /**
     * Change the active tube. By default the tube is "default"
     * The use command is for producers. Subsequent put commands will put jobs
     * into the tube specified by this command. If no use command has been
     * issued,jobs will be put into the tube named default.
     * 
     * @param string $tube
     * @return boolean|string
     */
    public function choose(string! tube) -> boolean|string
    {
        var response;

        this->write("use " . tube);

        let response = this->readStatus();
        if response[0] != "USING" {
            return false;
        }

        return response[1];
    }

    /**
     * The watch command adds the named tube to the watch list for the current
     * connection. A reserve command will take a job from any of the tubes in
     * the watch list. For each new connection, the watch list initially
     * consists of one tube, named default.
     * 
     * @param string $tube It specifies a tube to add to the watch list.If the 
     * tube doesn't exist, it will be created.
     * @return boolean|integer is the integer number of tubes currently in the watch list.
     */
    public function watch(string! tube) -> boolean|int
    {
        var response;

        this->write("watch " . tube);

        let response = this->readStatus();
        if response[0] != "WATCHING" {
            return false;
        }

        return (int) response[1];
    }
        
    /**
     * It removes the named tube from the watch list for the current connection.
     * 
     * @param string $tube It specifies a tube to add to the watch list.If the 
     * @return boolean|integer is the integer number of tubes currently in the watch list.
     */
    public function ignore(tube) -> boolean|int
    {
        var response;

        this->write("ignore " . tube);

        let response = this->readStatus();
        if(response[0] != "WATCHING") {
            return false;
        }

        return (int) response[1];
    }

    /**
     * Can delay any new job being reserved for a given time.
     * 
     * @param string $tube is the tube to pause
     * @param integer $delay is an integer number of seconds to wait before
     * reserving any more jobs from the queue
     * @return boolean
     */
    public function pauseTube(tube, delay) -> boolean
    {
        var response;

        this->write("pause-tube " . tube . " " . delay);

        let response = this->readStatus();
        if(response[0] != "PAUSED") {
            return false;
        }

        return true;
    }

    /**
     * The kick command applies only to the currently used tube. It moves jobs
     * into the ready queue. If there are any buried jobs, it will only kick 
     * buried jobs. Otherwise it will kick delayed jobs.
     * 
     * @param integer   $bound  is an integer upper bound on the number of jobs
     * to kick. The server will kick no more than jobs.
     * @return boolean|integer is indicating the number of jobs actually kicked.
     */
    public function kick(bound) -> boolean|int
    {
        var response;

        this->write("kick " . bound);

        let response = this->readStatus();
        if(response[0] != "KICKED") {
            return false;
        }

        return (int) response[1];
    }

    /**
     * Gives statistical information about the system as a whole.
     * Entries described as "cumulative" are reset when the beanstalkd process 
     * starts; they are not stored on disk with the -b flag.
     * 
     * @return boolean|array statistical information.
     * <i>return array:</i><br><br>
     * <b>current-jobs-urgent</b> is the number of ready jobs with priority < 1024.<br>
     * <b>current-jobs-ready</b> is the number of jobs in the ready queue.<br>
     * <b>current-jobs-reserved</b> is the number of jobs reserved by all clients.<br>
     * <b>current-jobs-delayed</b> is the number of delayed jobs.<br>
     * <b>current-jobs-buried</b> is the number of buried jobs.<br>
     * <b>cmd-put</b> is the cumulative number of put commands.<br>
     * <b>cmd-peek</b> is the cumulative number of peek commands.<br>
     * <b>cmd-peek-ready</b> is the cumulative number of peek-ready commands.<br>
     * <b>cmd-peek-delayed</b> is the cumulative number of peek-delayed commands.<br>
     * <b>cmd-peek-buried</b> is the cumulative number of peek-buried commands.<br>
     * <b>cmd-reserve</b> is the cumulative number of reserve commands.<br>
     * <b>cmd-use</b> is the cumulative number of use commands.<br>
     * <b>cmd-watch</b> is the cumulative number of watch commands.<br>
     * <b>cmd-ignore</b> is the cumulative number of ignore commands.<br>
     * <b>cmd-delete</b> is the cumulative number of delete commands.<br>
     * <b>cmd-release</b> is the cumulative number of release commands.<br>
     * <b>cmd-bury</b> is the cumulative number of bury commands.<br>
     * <b>cmd-kick</b> is the cumulative number of kick commands.<br>
     * <b>cmd-stats</b> is the cumulative number of stats commands.<br>
     * <b>cmd-stats-job</b> is the cumulative number of stats-job commands.<br>
     * <b>cmd-stats-tube</b> is the cumulative number of stats-tube commands.<br>
     * <b>cmd-list-tubes</b> is the cumulative number of list-tubes commands.<br>
     * <b>cmd-list-tube-used</b> is the cumulative number of list-tube-used commands.<br>
     * <b>cmd-list-tubes-watched</b> is the cumulative number of list-tubes-watched commands.<br>
     * <b>cmd-pause-tube</b> is the cumulative number of pause-tube commands.<br>
     * <b>job-timeouts</b> is the cumulative count of times a job has timed out.<br>
     * <b>total-jobs</b> is the cumulative count of jobs created.<br>
     * <b>max-job-size</b> is the maximum number of bytes in a job.<br>
     * <b>current-tubes</b> is the number of currently-existing tubes.<br>
     * <b>current-connections</b> is the number of currently open connections.<br>
     * <b>current-producers</b> is the number of open connections that have each issued at least one put command.<br>
     * <b>current-workers</b> is the number of open connections that have each issued at least one reserve command.<br>
     * <b>current-waiting</b> is the number of open connections that have issued a reserve command but not yet received a response.<br>
     * <b>total-connections</b> is the cumulative count of connections.<br>
     * <b>pid</b> is the process id of the server.<br>
     * <b>version</b> is the version string of the server.<br>
     * <b>rusage-utime</b> is the cumulative user CPU time of this process in seconds and microseconds.<br>
     * <b>rusage-stime</b> is the cumulative system CPU time of this process in seconds and microseconds.<br>
     * <b>uptime</b> is the number of seconds since this server process started running.<br>
     * <b>binlog-oldest-index</b> is the index of the oldest binlog file needed to store the current jobs.<br>
     * <b>binlog-current-index</b> is the index of the current binlog file being written to. If binlog is not active this value will be 0.<br>
     * <b>binlog-max-size</b> is the maximum size in bytes a binlog file is allowed to get before a new binlog file is opened.<br>
     * <b>binlog-records-written</b></b> is the cumulative number of records written to the binlog.<br>
     * <b>binlog-records-migrated</b></b> is the cumulative number of records written as part of compaction.<br>
     * <b>id</b></b> is a random id string for this server process, generated when each beanstalkd process starts.<br>
     * <b>hostname</b></b> is the hostname of the machine as determined by uname.<br>
     */
    public function stats() -> boolean|array
    {
        var response;

        this->write("stats");

        let response = this->readYaml();
        if response[0] != "OK" {
            return false;
        }

        return response[2];
    }

    /**
     * Gives statistical information about the specified tube if it exists.
     * @param string $tube Stats will be returned for this tube.
     * @return boolean|array
     * <i>return array:</i><br><br>
     * <b>name</b> is the tube's name.<br>
     * <b>current-jobs-urgent</b> is the number of ready jobs with priority < 1024 in this tube.<br>
     * <b>current-jobs-ready</b> is the number of jobs in the ready queue in this tube.<br>
     * <b>current-jobs-reserved</b> is the number of jobs reserved by all clients in this tube.<br>
     * <b>current-jobs-delayed</b> is the number of delayed jobs in this tube.<br>
     * <b>current-jobs-buried</b> is the number of buried jobs in this tube.<br>
     * <b>total-jobs</b> is the cumulative count of jobs created in this tube in the current beanstalkd process.<br>
     * <b>current-using</b> is the number of open connections that are currently using this tube.<br>
     * <b>current-waiting</b> is the number of open connections that have issued a 
     * reserve command while watching this tube but not yet received a response.<br>
     * <b>current-watching</b> is the number of open connections that are currently watching this tube.<br>
     * <b>pause</b> is the number of seconds the tube has been paused for.<br>
     * <b>cmd-delete</b> is the cumulative number of delete commands for this tube.<br>
     * <b>cmd-pause-tube</b> is the cumulative number of pause-tube commands for this tube.<br>
     * <b>pause-time-left</b> is the number of seconds until the tube is un-paused.<br>
     */
    public function statsTube(string! tube) -> boolean|array
    {
        var response;

        this->write("stats-tube " . tube);

        let response = this->readYaml();
        if response[0] != "OK" {
            return false;
        }

        return response[2];
    }

    /**
     * Returns a list of all existing tubes.
     * 
     * @return boolean|array all tube names
     */
    public function listTubes() -> boolean|array
    {
        var response;

        this->write("list-tubes");

        let response = this->readYaml();
        if response[0] != "OK" {
            return false;
        }

        return response[2];
    }
        
    /**
     * Returns the tube currently being used by the client.
     * 
     * @return boolean|string is the name of the tube being used.
     */
    public function listTubeUsed() -> boolean|string
    {
        var response;

        this->write("list-tube-used");

        let response = this->readStatus();
        if (response[0] != "USING") {
            return false;
        }

        return response[1];
    }

    /**
     * Returns a list tubes currently being watched by the client.
     * 
     * @return boolean|array  watched tube names as a list.
     */
    public function listTubesWatched() -> boolean|array
    {
        var response;

        this->write("list-tubes-watched");

        let response = this->readYaml();
        if(response[0] != "OK") {
            return false;
        }

        return response[2];
    }

    /**
     * Inspect the next ready job.
     * 
     * @return boolean|\Phalcon\Queue\Beanstalk\Job
     */
    public function peekReady() -> boolean|<Job>
    {
        var response;

        this->write("peek-ready");

        let response = this->readStatus();
        if response[0] != "FOUND" {
            return false;
        }

        return new Job(this, response[1], unserialize(this->read(response[2])));
    }

    /**
     * Return the next job in the list of buried jobs.
     * 
     * @return boolean|\Phalcon\Queue\Beanstalk\Job
     */
    public function peekBuried() -> boolean|<Job>
    {
        var response;

        this->write("peek-buried");

        let response = this->readStatus();
        if response[0] != "FOUND" {
            return false;
        }

        return new Job(this, response[1], unserialize(this->read(response[2])));
    }
        
    /**
     * Return the next job in the list of buried jobs.
     * 
     * @return boolean|\Phalcon\Queue\Beanstalk\Job
     */
    public function peekDelayed() -> boolean|<Job>
    {
        var response;

        if (!this->write("peek-delayed")) {
            return false;
        }

        let response = this->readStatus();
        if (response[0] != "FOUND") {
            return false;
        }

        return new Job(this, response[1], unserialize(this->read(response[2])));
    }

    /**
     * return job. 
     *
     * @param  int        $job_id is the job id to kick.
     * @return boolean|\Phalcon\Queue\Beanstalk\Job
     */
    public function jobPeek(job_id) -> boolean|<Job>
    {
        var response;

        this->write("peek " . job_id);

        let response = this->readStatus();

        if (response[0] != "FOUND") {
            return false;
        }

        return new Job(this, response[1], unserialize(this->read(response[2])));
    }

    /**
     * Reads the latest status from the Beanstalkd server
     */
    final public function readStatus() -> array
    {
        var status;
        let status = this->read();
        if status === false {
            return [];
        }
        return explode(" ", status);
    }

    /**
     * Fetch a YAML payload from the Beanstalkd server
     */
    final public function readYaml() -> array
    {
        var response, status, numberOfBytes, data;

        let response = this->readStatus();

        let status = response[0];

        if count(response) > 1 {
            let numberOfBytes = response[1];

            let response = this->read();

            let data = yaml_parse(response);
        } else {
            let numberOfBytes = 0;

            let data = [];
        }

        return [
            status,
            numberOfBytes,
            data
        ];
    }

    /**
     * Reads a packet from the socket. Prior to reading from the socket will
     * check for availability of the connection.
     */
    public function read(int length = 0) -> boolean|string
    {
        var connection, data;

        let connection = this->_connection;
        if typeof connection != "resource" {
            let connection = this->connect();
            if typeof connection != "resource" {
                return false;
            }
        }

        if length {

            if feof(connection) {
                return false;
            }

            let data = rtrim(stream_get_line(connection, length + 2), "\r\n");
            if stream_get_meta_data(connection)["timed_out"] {
                throw new Exception("Connection timed out");
            }
        } else {
            let data = stream_get_line(connection, 16384, "\r\n");
        }
        
        
        self::errorDetection(data);
        
        return data;
    }
    
    /**
     * error detection for response
     */
    protected static function errorDetection(response)
    {
        if response === "UNKNOWN_COMMAND" {
            throw new Exception("UNKNOWN_COMMAND");
        } elseif response === "JOB_TOO_BIG" {
            throw new Exception("JOB_TOO_BIG");
        } elseif response === "BAD_FORMAT" {
            throw new Exception("BAD_FORMAT");
        } elseif response === "OUT_OF_MEMORY" {
            throw new Exception("OUT_OF_MEMORY");
        }
    }

    /**
     * Writes data to the socket. Performs a connection if none is available
     */
    protected function write(string data) -> boolean|int
    {
        var connection, packet;

        let connection = this->_connection;
        if typeof connection != "resource" {
            let connection = this->connect();
            if typeof connection != "resource" {
                return false;
            }
        }

        let packet = data . "\r\n";
        return fwrite(connection, packet, strlen(packet));
    }

    /**
     * Closes the connection to the beanstalk server.
     */
    public function disconnect() -> boolean
    {
        var connection;

        let connection = this->_connection;
        if typeof connection != "resource" {
            return false;
        }

        fclose(connection);
        return true;
    }
        
    /**
     * Simply closes the connection.
     * 
     * @return boolean
     */
    public function quit()
    {
        return (boolean)this->write("quit");
    }
}
