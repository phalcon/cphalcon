<?php
/**
 * ModelTestCase.php
 * Phalcon_Test_ModelTestCase
 *
 * Model Test Helper
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2012 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Test;
    
use \Phalcon\Mvc\Model\Manager as PhModelManager;
use \Phalcon\Events\Manager as PhEventsManager;
use \Phalcon\Logger\Adapter\File as PhLogger;
use \Phalcon\Db\Adapter\Pdo\Mysql as PhMysql;
use \Phalcon\Session\Adapter\Files as PhSession;
use \Phalcon\Cache\Frontend\Data as PhCacheFront;
use \Phalcon\Cache\Backend\File as PhCacheBack;
use \Phalcon\Mvc\Application as PhApplication;
use \Phalcon\Mvc\Dispatcher as PhDispatcher;
use \Phalcon\Mvc\Url as PhUrl;
use \Phalcon\Mvc\View as PhView;
use \Phalcon\Mvc\View\Engine\Volt as PhVolt;
use \Phalcon\Mvc\Model\Metadata\Memory as PhMetadataMemory;
use \Phalcon\Mvc\Model\Metadata\Files as PhMetadataFiles;
use \Phalcon\Exception as PhException;

abstract class ModelTestCase extends UnitTestCase
{
    /**
     * Sets the test up by loading the DI container and other stuff
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-20
     */
    protected function setUp()
    {
        parent::setUp();

        // Set Models manager
        $this->di->set(
            'modelsManager',
            function () {
                return new PhModelManager();
            }
        );

        // Set Models metadata
        $this->di->set(
            'modelsMetadata',
            function () {
                return new PhMetadataMemory();
            }
        );

        // Set the connection to the db (defaults to mysql)
        $this->setDb();
    }

    /**
     * Sets the database adapter in the DI container
     *
     * @param string $dbType Sets the database type for the test
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-20
     */
    protected function setDb($dbType = 'mysql')
    {
        $config = $this->config;

        if ($this->di->has('db')) {
            $db    = $this->di->get('db');
            $class = '\Phalcon\Db\Adapter\Pdo\\' . ucfirst($dbType);
            if (get_class($db) == $class) {
                return $db;
            }
        }

        // Set the connection to whatever we chose
        $this->di->set(
            'db',
            function () use ($dbType, $config) {
                $params = $config['db'][$dbType];
                $class  = '\Phalcon\Db\Adapter\Pdo\\' . ucfirst($dbType);

                $conn = new $class($params);
                return $conn;
            }
        );
    }

    /**
     * Empties a table in the database.
     *
     * @param $table
     *
     * @return boolean
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-08
     */
    public function emptyTable($table)
    {
        $connection = $this->di->get('db');

        $success = $connection->delete($table);

        return $success;
    }

    /**
     * Populates a table with default data
     *
     * @param      $table
     * @param null $records
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-08
     */
    public function populateTable($table, $records = null)
    {
        // Empty the table first
        $this->emptyTable($table);

        $connection = $this->di->get('db');
        $parts      = explode('_', $table);
        $suffix     = '';

        foreach ($parts as $part) {
            $suffix .= ucfirst($part);
        }

        $class = 'Phalcon\Test\Fixtures\\' . $suffix;

        $data = $class::get($records);

        foreach ($data as $record) {
            $sql = "INSERT INTO {$table} VALUES " . $record;
            $connection->execute($sql);
        }
    }
}