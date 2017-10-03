<?php

namespace Helper\Db\Connection;

/**
 * Helper\Db\Connection\AbstractFactory
 *
 * @package Helper\Db\Connection
 */
abstract class AbstractFactory
{
    /**
     * Creates a database connection
     *
     * @return \Phalcon\Db\Adapter\Pdo
     */
    abstract public function createConnection();
}
