/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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
namespace Phalcon\Session\Adapter;

use Phalcon\Session\Adapter;
use Phalcon\Session\AdapterInterface;
use Phalcon\Session\Exception;

/**
 * Phalcon\Session\Adapter\Mongo
 *
 * This adapter store sessions in Mongo
 *
 *<code>
 * $session = new \Phalcon\Session\Adapter\Mongo(array(
 *    'collection' => $mongo->test->session_data
 * ));
 *
 * $session->start();
 *
 * $session->set('var', 'some-value');
 *
 * echo $session->get('var');
 *
 *</code>
 */
class Mongo extends Adapter implements AdapterInterface
{
    /**
     * Current session data
     *
     * @var string
     */
    protected _data;

    /**
     * Class constructor.
     *
     * @param  array     $options
     * @throws Exception
     */
    public function __construct(array options = [])
    {
        if !isset options["collection"] {
			throw new Exception("The parameter 'collection' is required");
		}

        session_set_save_handler(
			[this, "open"],
			[this, "close"],
			[this, "read"],
			[this, "write"],
			[this, "destroy"],
			[this, "gc"]
		);

        parent::__construct(options);
    }

    public function open(savePath, name) -> boolean
    {
        return true;
    }

    public function close() -> boolean
    {
    	return true;
    }

    public function read(sessionId)
    {
        var sessionData;

        let sessionData = this->getCollection()->findOne(["_id" : sessionId]);
        if !isset sessionData["data"] {
        	return null;
        }

        let this->_data = sessionData["data"];
        return sessionData["data"];
    }

    public function write(sessionId, sessionData) -> boolean
    {
        if this->_data === sessionData {
        	return true;
        }

        let sessionData = [
            "_id" : sessionId,
            "modified" : new \MongoDate(),
            "data" : sessionData
        ];

        this->getCollection()->save(sessionData);

        return true;
    }

    public function destroy(sessionId = null)
    {
        var remove;

        if sessionId === null {
        	let sessionId = session_id();
        }

        let this->_data = null;

        let remove = this->getCollection()->remove(["_id" : sessionId]);

        return (bool)remove["ok"];
    }

    public function gc(maxlifetime)
    {
        var minAge, minAgeMongo, query, remove;

        let minAge = new \DateTime();
        minAge->sub(new \DateInterval("PT" . maxlifetime . "S"));
        let minAgeMongo = new \MongoDate(minAge->getTimestamp());

        let query = ["modified" : ["$lte" : minAgeMongo]];
        let remove = this->getCollection()->remove(query);

        return (bool)remove["ok"];
    }

    protected function getCollection()
    {
        var options;

        let options = this->getOptions();
        return options["collection"];
    }
}