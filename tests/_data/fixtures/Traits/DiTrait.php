<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Traits;

use Phalcon\Crypt;
use Phalcon\Db\Adapter\Pdo\Mysql;
use Phalcon\Db\Adapter\Pdo\Postgresql;
use Phalcon\Di;
use Phalcon\Escaper;
use Phalcon\Events\Manager;
use Phalcon\Filter;
use Phalcon\Http\Request;
use Phalcon\Http\Response;
use Phalcon\Mvc\Url;
use Phalcon\Session\Adapter\Files as FilesSession;

trait DiTrait
{
    protected function getDi()
    {
        return Di::getDefault();
    }

    protected function newDi()
    {
        Di::reset();
        $container = new Di();
        Di::setDefault($container);
    }

    protected function resetDi()
    {
        Di::reset();
    }

    /**
     * Set up db service (mysql)
     */
    protected function setDbMysql()
    {
        $container = Di::getDefault();
        $container->set(
            'db',
            function () {
                $options = [
                    'host'     => TEST_DB_MYSQL_HOST,
                    'username' => TEST_DB_MYSQL_USER,
                    'password' => TEST_DB_MYSQL_PASSWD,
                    'dbname'   => TEST_DB_MYSQL_NAME,
                    'charset'  => TEST_DB_MYSQL_CHARSET,
                ];

                return new Mysql($options);
            }
        );
    }

    /**
     * Set up db service (Postgresql)
     */
    protected function setDbPostgresql()
    {
        $container = Di::getDefault();
        $container->set(
            'db',
            function () {
                $options = [
                    'host'     => TEST_DB_POSTGRESQL_HOST,
                    'username' => TEST_DB_POSTGRESQL_USER,
                    'password' => TEST_DB_POSTGRESQL_PASSWD,
                    'dbname'   => TEST_DB_POSTGRESQL_NAME,
                    'schema'   => TEST_DB_POSTGRESQL_SCHEMA,
                ];

                return new Postgresql($options);
            }
        );
    }

    protected function setDiCrypt()
    {
        $container = Di::getDefault();
        $container->set(
            'crypt',
            function () {
                $crypt = new Crypt();
                $crypt->setKey('cryptkeycryptkey');

                return $crypt;
            }
        );
    }

    protected function setDiEscaper()
    {
        $container = Di::getDefault();
        $container->setShared('escaper', Escaper::class);
    }

    protected function setDiEventsManager()
    {
        $container = Di::getDefault();
        $container->setShared('eventsManager', Manager::class);
    }

    protected function setDiFilter()
    {
        $container = Di::getDefault();
        $container->setShared('filter', Filter::class);
    }

    protected function setDiResponse()
    {
        $container = Di::getDefault();
        $container->set('response', Response::class);
    }

    protected function setDiRequest()
    {
        $container = Di::getDefault();
        $container->set('request', Request::class);
    }

    protected function setDiSession()
    {
        $container = Di::getDefault();
        $container->setShared('session', FilesSession::class);
    }

    protected function setDiUrl()
    {
        $container = Di::getDefault();
        $container->setShared(
            'url',
            function () {
                $url = new Url();
                $url->setBaseUri('/');

                return $url;
            }
        );
    }
}
