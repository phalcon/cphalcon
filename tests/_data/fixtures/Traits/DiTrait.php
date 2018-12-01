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

use const PATH_DATA;
use Phalcon\Annotations\Adapter\Memory as AnnotationsMemory;
use Phalcon\Crypt;
use Phalcon\Db\Adapter\Pdo\Mysql;
use Phalcon\Db\Adapter\Pdo\Postgresql;
use Phalcon\Db\Adapter\Pdo\Sqlite;
use Phalcon\Di;
use Phalcon\Escaper;
use Phalcon\Events\Manager as EventsManager;
use Phalcon\Filter;
use Phalcon\Http\Request;
use Phalcon\Http\Response;
use Phalcon\Mvc\Models\Manager as ModelsManager;
use Phalcon\Mvc\Models\Metadata\Memory as MetadataMemory;
use Phalcon\Mvc\Url;
use Phalcon\Mvc\View;
use Phalcon\Mvc\View\Simple;
use Phalcon\Session\Adapter\Files as FilesSession;

trait DiTrait
{
    protected function getDi()
    {
        return Di::getDefault();
    }

    protected function getService(string $name)
    {
        $container = $this->getDi();

        return $container->get($name);
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

    protected function setDiAnnotations()
    {
        $container = Di::getDefault();
        $container->set('annotations', new AnnotationsMemory());
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
        $container->set('escaper', Escaper::class);
    }

    protected function setDiEventsManager()
    {
        $container = Di::getDefault();
        $container->set('eventsManager', EventsManager::class);
    }

    protected function setDiFilter()
    {
        $container = Di::getDefault();
        $container->set('filter', Filter::class);
    }

    protected function setDiModelsManager()
    {
        $container = Di::getDefault();
        $container->set('modelsManager', ModelsManager::class);
    }

    protected function setDiModelsMetadata()
    {
        $container = Di::getDefault();
        $container->set('modelsMetadata', MetadataMemory::class);
    }

    /**
     * Set up db service (mysql)
     */
    protected function setDiMysql()
    {
        $container = Di::getDefault();
        $container->set(
            'db',
            function () {
                $options = [
                    'host'     => DATA_MYSQL_HOST,
                    'username' => DATA_MYSQL_USER,
                    'password' => DATA_MYSQL_PASS,
                    'dbname'   => DATA_MYSQL_NAME,
                    'charset'  => DATA_MYSQL_CHARSET,
                ];

                return new Mysql($options);
            }
        );
    }

    /**
     * Set up db service (Postgresql)
     */
    protected function setDiPostgresql()
    {
        $container = Di::getDefault();
        $container->set(
            'db',
            function () {
                $options = [
                    'host'     => DATA_POSTGRES_HOST,
                    'username' => DATA_POSTGRES_USER,
                    'password' => DATA_POSTGRES_PASS,
                    'dbname'   => DATA_POSTGRES_NAME,
                    'schema'   => DATA_POSTGRES_SCHEMA,
                ];

                return new Postgresql($options);
            }
        );
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
        $container->set('session', FilesSession::class);
    }

    /**
     * Set up db service (Sqlite)
     */
    protected function setDiSqlite()
    {
        $container = Di::getDefault();
        $container->set(
            'db',
            function () {
                $options = [
                    'dbname' => DATA_SQLITE_NAME,
                ];

                return new Sqlite($options);
            }
        );
    }

    protected function setDiUrl()
    {
        $container = Di::getDefault();
        $container->set(
            'url',
            function () {
                $url = new Url();
                $url->setBaseUri('/');

                return $url;
            }
        );
    }

    protected function setDiView()
    {
        $container = Di::getDefault();
        $container->set(
            'view',
            function () {
                $view = new View();
                $view->setViewsDir(PATH_DATA . 'fixtures/views');

                return $view;
            }
        );
    }

    protected function setDiViewSimple()
    {
        $container = Di::getDefault();
        $container->set(
            'viewSimple',
            function () {
                $view = new Simple();
                $view->setViewsDir(PATH_DATA . 'fixtures/views/');

                return $view;
            }
        );
    }
}
