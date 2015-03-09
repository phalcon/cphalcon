
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Queue;

use Phalcon\Queue\Beanstalk\Job;

/**
* Phalcon\Queue\Beanstalk
*
* Class to access the beanstalk queue service.
* Partially implements the protocol version 1.2
*
* @see http://www.igvita.com/2010/05/20/scalable-work-queues-with-beanstalk/
*/
class Beanstalk
{
	protected _connection;

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
			let parameters["host"] = "127.0.0.1";
		}

		if !isset parameters["port"]  {
			let parameters["port"] = 11300;
		}

		let this->_parameters = parameters;
	}

	/**
	 * Makes a connection to the Beanstalkd server
	 *
	 * @return resource
	 */
	public function connect() -> resource
	{
 		var connection, parameters;

		let connection = this->_connection;
		if typeof connection == "resource" {
			this->disconnect();
		}

		let parameters = this->_parameters;

		let connection = fsockopen(parameters["host"], parameters["port"], null, null);
		if typeof connection != "resource" {
			throw new \Phalcon\Exception("Can't connect to Beanstalk server");
		}

		stream_set_timeout(connection, -1, null);

		let this->_connection = connection;

		return connection;
	}

	/**
	 * Inserts jobs into the queue
	 *
	 * @param string data
	 * @param array options
	 */
	public function put(var data, var options = null) -> string|boolean
	{
 		var priority, delay, ttr, serialized, response, status, length;

		/**
		 * Priority is 100 by default
		 */
		if !fetch priority, options["priority"] {
			let priority = "100";
		}

		if !fetch delay, options["delay"] {
			let delay = "0";
		}

		if !fetch ttr, options["ttr"] {
			let ttr = "86400";
		}

		/**
		 * Data is automatically serialized before be sent to the server
		 */
		let serialized = serialize(data);

		/**
		 * Create the command
		 */
		let length = strlen(serialized);
		this->write("put " . priority . " " . delay . " " . ttr ." " . length);
		this->write(serialized);

		let response = this->readStatus();
		let status = response[0];

		if status == "INSERTED" {
			return response[1];
		}

		if status == "BURIED" {
			return response[1];
		}

		return false;
	}

	/**
	 * Reserves a job in the queue
	 *
	 * @return boolean|Phalcon\Queue\Beanstalk\Job
	 */
	public function reserve(timeout = null) -> boolean|<Job>
	{
 		var command, response;

		if typeof timeout != "null" {
			let command = "reserve-with-timeout " . timeout;
		} else {
			let command = "reserve";
		}

		this->write(command);

		let response = this->readStatus();
		if response[0] == "RESERVED" {

			/**
			 * The job is in the first position
			 * Next is the job length
			 * The body is serialized
			 * Create a beanstalk job abstraction
			 */
			return new Job(this, response[1], unserialize(this->read(response[2])));
		}

		return false;
	}

	/**
	 * Change the active tube. By default the tube is "default"
	 *
	 * @param string tube
	 * @return string|boolean
	 */
	public function choose(string! tube) -> boolean|string
	{
 		var response;

		this->write("use " . tube);

		let response = this->readStatus();
		if response[0] == "USING" {
			return response[1];
		}

		return false;
	}

	/**
	 * Change the active tube. By default the tube is "default"
	 *
	 * @param string tube
	 * @return string|boolean
	 */
	public function watch(string! tube) -> boolean|string
	{
 		var response;

		this->write("watch " . tube);

		let response = this->readStatus();
		if response[0] == "WATCHING" {
			return response[1];
		}

		return false;
	}

	/**
	 * Inspect the next ready job.
	 *
	 * @return boolean|Phalcon\Queue\Beanstalk\Job
	 */
	public function peekReady() -> boolean|<Job>
	{
 		var response;

		this->write("peek-ready");

		let response = this->readStatus();
		if response[0] == "FOUND" {
			return new Job(this, response[1], unserialize(this->read(response[2])));
		}

		return false;
	}

	/**
	 * Return the next job in the list of buried jobs
	 *
	 * @return boolean|Phalcon\Queue\Beanstalk\Job
	 */
	public function peekBuried() -> boolean|<Job>
	{
 		var response;

		this->write("peek-buried");

		let response = this->readStatus();
		if response[0] == "FOUND" {
			return new Job(this, response[1], unserialize(this->read(response[2])));
		}

		return false;
	}

	/**
	 * Reads the latest status from the Beanstalkd server
	 *
	 * @return array
	 */
	final public function readStatus() -> array
	{
		return explode(" ", this->read());
	}

	/**
	 * Reads a packet from the socket. Prior to reading from the socket will
	 * check for availability of the connection.
	 *
	 * @param int length Number of bytes to read.
	 * @return string|boolean Data or `false` on error.
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

			let data = fread(connection, length + 2);
			if stream_get_meta_data(connection)["timed_out"] {
				throw new \Phalcon\Exception("Connection timed out");
			}

			return rtrim(data, "\r\n");
		}

		return stream_get_line(connection, 16384, "\r\n");
	}

	/**
	 * Writes data to the socket. Performs a connection if none is available
	 *
	 * @param string data
	 * @return integer|boolean
	 */
	protected function write(data) -> boolean|int
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
	 *
	 * @return boolean
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
}
