
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

namespace Phalcon\Queue\Beanstalk;

/**
* Phalcon\Queue\Beanstalk\Job
*
* Represents a job in a beanstalk queue
*/
class Job
{
	protected _id {get};
	
	protected _body {get};
	
	protected _queue;
	
	/**
	* Phalcon\Queue\Beanstalk\Job
	*
	* @param Phalcon\Queue\Beanstalk queue
	* @param string id
	* @param string body
	*/
	public function __construct(queue, id, body)
	{
		let this->_queue = queue;
		let this->_id = id;
		let this->_body = body;
	}
 
	/**
	 * Removes a job from the server entirely
	 *
	 * @return boolean
	 */
	public function delete() -> boolean
	{
 		var queue, response, status;

		let queue = this->_queue;
		queue->write("delete ".this->_id);
 
		let response = queue->readStatus();
		let status = response[0];
 
		if status=="DELETED" {
			return true;
		}
 
		return false;
	}

}