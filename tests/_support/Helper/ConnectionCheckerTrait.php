<?php

/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Helper;

use Phalcon\Db\Adapter;
use Phalcon\Di;
use PHPUnit\Framework\SkippedTestError;

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
            throw new SkippedTestError("Unable to connect to the database: " . $e->getMessage());
        }
    }
}
