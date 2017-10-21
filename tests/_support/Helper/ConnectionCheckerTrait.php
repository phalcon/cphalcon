<?php

namespace Helper;

use Phalcon\Db\Adapter;
use Phalcon\Di;

/**
 * Connection checker
 *
 * @package Helper
 */
trait ConnectionCheckerTrait
{
    /**
     * @param \Phalcon\Db\Adapter $old_conn
     */
    protected function checkConnection(Adapter $old_conn)
    {
        /** @var \Phalcon\Di\FactoryDefault $di */
        $di = Di::getDefault();

        try {
            $di->getShared('db');
        } catch (\PDOException $e) {
            $di->setShared('db', $old_conn);
            throw new \PHPUnit_Framework_SkippedTestError("Unable to connect to the database: " . $e->getMessage());
        }
    }
}
