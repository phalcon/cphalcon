<?php

namespace Helper;

use Phalcon\Di;
use Phalcon\Db\Adapter\Pdo;
use Phalcon\Mvc\Model\Manager;
use Phalcon\Mvc\Model\MetaData\Memory;
use Phalcon\Mvc\Model\Transaction\Manager as TransactionManager;

/**
 * Helper\ModelTrait
 * Helper class to test Phalcon\Mvc\Model component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Unit\Mvc
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
trait ModelTrait
{
    /**
     * @param Pdo|null $connection
     * @return Manager
     */
    protected function setUpModelsManager(Pdo $connection = null)
    {
        $di = Di::getDefault();
        $connection = $connection ?: $di->getShared('db');

        Di::reset();

        $di = new Di();

        $manager = new Manager();
        $manager->setDI($di);

        $di->setShared('db', $connection);
        $di->setShared('modelsManager', $manager);
        $di->setShared('modelsMetadata', Memory::class);

        Di::setDefault($di);

        return $manager;
    }

    /**
     * @return TransactionManager
     */
    protected function setUpTransactionManager()
    {
        $di = Di::getDefault();
        $db = $di->getShared('db');

        Di::reset();

        $di = new Di();

        $transactionManager = new TransactionManager($di);
        $manager = new Manager();
        $manager->setDI($di);
        $di->setShared('db', $db);
        $di->setShared('transactionManager', $transactionManager);
        $di->setShared('modelsManager', $manager);
        $di->setShared('modelsMetadata', Memory::class);

        Di::setDefault($di);

        return $transactionManager;
    }
}
