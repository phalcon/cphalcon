
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
	public function __construct(options=null)
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
 
	public function connect()
	{
 		var connection, parameters;

		let connection = this->_connection;
		if is_resource(connection) {
			this->disconnect();
		}
 
		let parameters = this->_parameters;
 
		let connection = fsockopen( parameters["host"], parameters["port"], null, null);
		if !is_resource(connection) {
			throw new Phalcon\Exception("Can't connect to Beanstalk server");
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
	public function put(data, options=null) 
	{
 		var priority, delay, ttr, serialized, serializedLength, command,
 			response, status;

		/**
		* Priority is 100 by default
		*/
		if isset options["priority"] {
			let priority = options["priority"];
		} else {
			let priority = "100";
		}
 
		if isset options["delay"] {
			let delay = options["delay"];
		} else {
			let delay = "0";
		}
 
		if isset options["ttr"] {
			let ttr = options["ttr"];
		} else {
			let ttr = "86400";
		}
 
		/**
		 * Data is automatically serialized before be sent to the server
		 */
		let serialized = serialize(data);
		let serializedLength = strlen(serialized);
 
		/**
		 * Create the command
		 */
		let command = "put ".priority." ".delay;
		let command .= " ".ttr." ".serializedLength;
 
		this->write(command);
		this->write(serialized);
 
		let response = this->readStatus();
		let status = response[0];
 
		if status=="INSERTED" {
			return response[1];
		}
		if status=="BURIED" {
			return response[1];
		}
 
		//throw new Phalcon_Exception(status);
		return false;
	}
 
	/**
	 * Reserves a job in the queue
	 *
	 * @return boolean|Phalcon\Queue\Beanstalk\Job
	 */
	public function reserve(timeout=null) 
	{
 		var command, response, status, jobId, length, serializedBody, body;

		if timeout {
			let command = "reserve-with-timeout ".timeout;
		} else {
			let command = "reserve";
		}
 
		this->write(command);
 
		let response = this->readStatus();
		let status = response[0];
 
		if status=="RESERVED" {
 
			/**
			 * The job is in the first position
			 */
			let jobId = response[1];
 
			/**
			 * Next is the job length
			 */
			let length = response[2];
 
			/**
			 * The body is serialized
			 */
			let serializedBody = this->read(length);
			let body = unserialize(serializedBody);
 
			/**
			 * Create a beanstalk job abstraction
			 */
			return new Phalcon\Queue\Beanstalk\Job(this, jobId, body);
		}
 
		return false;
	}
 
	/**
	 * Change the active tube. By default the tube is "default"
	 *
	 * @param string tube
	 * @return string|boolean
	 */
	public function choose(tube) 
	{
 		var command, response, status;

		let command = "use ".tube; 
		this->write(command); 

		let response = this->readStatus();
 		let status = response[0];
 
		if status=="USING" {
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
	public function watch(tube) 
	{
 		var command, response, status;

		let command = "watch ".tube; 
		this->write(command);
 
		let response = this->readStatus(); 
		let status = response[0];
 
		if status=="WATCH" {
			return response[1];
		}
 
		return false;
	}
 
	/**
	* Inspect the next ready job.
	*
	* @return boolean|Phalcon\Queue\Beanstalk\Job
	*/
	public function peekReady() 
	{
 		var command, response, status, jobId, length, serializedBody, body;

		let command = "peek-ready";
		this->write(command);
 
		let response = this->readStatus();
		let status = response[0];
 
		if status=="FOUND" {
 
			let jobId = response[1]; 
			let length = response[2];
 
			let serializedBody = this->read(length);
			let body = unserialize(serializedBody);
 
			return new Phalcon\Queue\Beanstalk\Job(this, jobId, body);
		}
 
		return false;
	}
 
	/**
	* Reads the latest status from the Beanstalkd server
	*
	* @return array
	*/
	protected function readStatus()
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
	public function read(length=null) 
	{
 		var connection, length, isEof, totalLength, data, meta, timeout,
 			packet;

		let connection = this->_connection;
		if !is_resource(connection) {
			let connection = this->connect();
			if !is_resource(connection) {
				return false;
			}
		}
 
		if length {
 
			let isEof = feof(connection);
			if isEof {
				return false;
			}
 
			let totalLength = length + 2; 
			let data = fread(connection, totalLength);
			let meta = stream_get_meta_data(connection);
 
			let timeout = meta["timed_out"];
			if timeout {
				throw new Phalcon\Exception("Connection timed out");
			}
 
			let packet = rtrim(data, "\r\n");
		} else {
			let packet = stream_get_line(connection, 16384, "\r\n");
		}
 
		return packet;
	}
 
	/**
	* Writes data to the socket. Performs a connection if none is available
	*
	* @param string data
	* @return integer|boolean
	*/
	protected function write(data) 
	{
 		var connection, packet;

		let connection = this->_connection;
		if !is_resource(connection) {
			let connection = this->connect();
			if !is_resource(connection) {
				return false;
			}
		}
 
		let packet = data."\r\n";
		return fwrite(connection, packet, strlen(packet));
	}
 
	/**
	 * Closes the connection to the beanstalk server.
	 *
	 * @return boolean
	 */
	public function disconnect()
	{
		var connection;

		let connection = this->_connection;
		if !is_resource(connection) {
			return false;
		}
 
		fclose(connection);
		return true;
	}
}