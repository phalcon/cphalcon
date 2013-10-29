<?php
namespace Codeception\Module;

class PhalconDbHelper extends \Codeception\Module {

    protected $config = array('driver' => 'mysql');

    public function _before(\Codeception\TestCase $test)
    {
        $this->di = $this->getModule('PhalconApiHelper')->di;

        // Set Models manager
        $this->di->set('modelsManager', function () {
                return new \Phalcon\Mvc\Model\Manager();
            }
        );

        // Set Models metadata
        $this->di->set('modelsMetadata', function () {
                return new \Phalcon\Mvc\Model\Metadata\Memory();
            }
        );

        // Set the connection to the db (defaults to mysql)
        $this->setDb($this->config['driver']);
    }

    /**
     * Sets the database adapter in the DI container
     *
     * @param string $dbType Sets the database type for the test
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-20
     */
    protected function setDb($dbType)
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
                $params = $config;
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