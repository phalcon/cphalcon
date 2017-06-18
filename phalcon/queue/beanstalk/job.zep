
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Queue\Beanstalk;

use Phalcon\Queue\Beanstalk;
use Phalcon\Queue\Beanstalk\Exception;

/**
 * Phalcon\Queue\Beanstalk\Job
 *
 * Represents a job in a beanstalk queue
 */
class Job
{
	/**
	 * @var string
	 */
	protected _id { get };

	/**
	 * @var mixed
	 */
	protected _body { get };

	protected _queue;

	/**
	 * Phalcon\Queue\Beanstalk\Job
	 */
	public function __construct(<Beanstalk> queue, string id, var body)
	{
		let this->_queue = queue;
		let this->_id = id;
		let this->_body = body;
	}

	/**
	 * Removes a job from the server entirely
	 */
	public function delete() -> boolean
	{
		var queue;

		let queue = this->_queue;
		queue->write("delete " . this->_id);

		return queue->readStatus()[0] == "DELETED";
	}

	/**
	 * The release command puts a reserved job back into the ready queue (and marks
	 * its state as "ready") to be run by any client. It is normally used when the job
	 * fails because of a transitory error.
	 */
	public function release(int priority = 100, int delay = 0) -> boolean
	{
		var queue;

		let queue = this->_queue;
		queue->write("release " . this->_id . " " . priority . " " . delay);
		return queue->readStatus()[0] == "RELEASED";
	}

	/**
	 * The bury command puts a job into the "buried" state. Buried jobs are put into
	 * a FIFO linked list and will not be touched by the server again until a client
	 * kicks them with the "kick" command.
	 */
	public function bury(int priority = 100) -> boolean
	{
		var queue;

		let queue = this->_queue;
		queue->write("bury " . this->_id . " " . priority);
		return queue->readStatus()[0] == "BURIED";
	}

	/**
	 * The `touch` command allows a worker to request more time to work on a job.
	 * This is useful for jobs that potentially take a long time, but you still
	 * want the benefits of a TTR pulling a job away from an unresponsive worker.
	 * A worker may periodically tell the server that it's still alive and processing
	 * a job (e.g. it may do this on `DEADLINE_SOON`). The command postpones the auto
	 * release of a reserved job until TTR seconds from when the command is issued.
	 */
	public function touch() -> boolean
	{
		var queue;

		let queue = this->_queue;
		queue->write("touch " . this->_id);
		return queue->readStatus()[0] == "TOUCHED";
	}

	/**
	 * Move the job to the ready queue if it is delayed or buried.
	 */
	public function kick() -> boolean
	{
		var queue;

		let queue = this->_queue;
		queue->write("kick-job " . this->_id);
		return queue->readStatus()[0] == "KICKED";
	}

	/**
	 * Gives statistical information about the specified job if it exists.
	 */
	public function stats() -> boolean|array
	{
		var queue, response;

		let queue = this->_queue;
		queue->write("stats-job " . this->_id);

		let response = queue->readYaml();
		if response[0] == "NOT_FOUND" {
			return false;
		}

		return response[2];
	}

	/**
	 * Checks if the job has been modified after unserializing the object
	 */
	public function __wakeup()
	{
		if typeof this->_id != "string" {
			throw new Exception(
				"Unexpected inconsistency in Phalcon\\Queue\\Beanstalk\\Job::__wakeup() - possible break-in attempt!"
			);
		}
	}
}
