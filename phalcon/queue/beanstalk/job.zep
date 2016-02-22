
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
	 * @var integer
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
	public function __construct(<Beanstalk> queue, int id, var body)
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
		queue->write(sprintf(Beanstalk::CMD_DELETE_FMT, this->_id));

		return queue->readStatus()[0] == Beanstalk::MSG_DELETED;
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
		queue->write(sprintf(Beanstalk::CMD_RELEASE_FMT, this->_id, priority, delay));
		return queue->readStatus()[0] == Beanstalk::MSG_RELEASED;
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
		queue->write(sprintf(Beanstalk::CMD_BURY_FMT, this->_id, priority));
		return queue->readStatus()[0] == Beanstalk::MSG_BURIED;
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
		queue->write(sprintf(Beanstalk::CMD_TOUCH_FMT, this->_id));
		return queue->readStatus()[0] == Beanstalk::MSG_TOUCHED;
	}

	/**
     * The kick-job command is a variant of kick that operates with a single 
     * job identified by its job id. If the given job id exists and is in a 
     * buried or delayed state, it will be moved to the ready queue of the the 
     * same tube where it currently belongs. 
     *
     * @return boolean
     */
	public function kick() -> boolean
	{
		var queue;

		let queue = this->_queue;
		queue->write(sprintf(Beanstalk::CMD_JOBKICK_FMT, this->_id));
		return queue->readStatus()[0] == Beanstalk::MSG_KICKED;
	}

    /**
     * The stats-job command gives statistical information about the specified 
     * job if it exists.
     * 
     * <i>return array:</i><br><br>
     * <b>id</b> is the job id<br>
     * <b>tube</b> is the name of the tube that contains this job<br>
     * <b>state</b> is ready or delayed or reserved or buried<br>
     * <b>pri</b> is the priority value set by the put, release, or bury commands.<br>
     * <b>age</b> is the time in seconds since the put command that created this job.<br>
     * <b>time-left</b> is the number of seconds left until the server puts this job into the ready queue. This number is only meaningful if the job is reserved or delayed. If the job is reserved and this amount of time elapses before its state changes, it is considered to have timed out.<br>
     * <b>file</b> is the number of the earliest binlog file containing this job. If -b wasn't used, this will be 0.<br>
     * <b>reserves</b> is the number of times this job has been reserved.<br>
     * <b>timeouts</b> is the number of times this job has timed out during a reservation.<br>
     * <b>releases</b> is the number of times a client has released this job from a reservation.<br>
     * <b>buries</b> is the number of times this job has been buried.<br>
     * <b>kicks</b> is the number of times this job has been kicked.<br>
     * 
     * @return boolean | array
     */
	public function stats() -> boolean|array
	{
		var queue, response;

		let queue = this->_queue;
		queue->write(sprintf(Beanstalk::CMD_JOBSTATS_FMT, this->_id));

		let response = queue->readYaml();
		if response[0] == Beanstalk::MSG_NOT_FOUND {
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
			throw new Exception("Unexpected inconsistency in %s - possible break-in attempt!", "Phalcon\\Queue\\Beanstalk\\Job::__wakeup()");
		}
	}
}
