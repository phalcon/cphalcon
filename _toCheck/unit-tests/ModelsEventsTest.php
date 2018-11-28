<?php

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file LICENSE.txt.                             |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

use PHPUnit\Framework\TestCase;

class ModelsEventsTest extends TestCase
{

    public function __construct()
    {
        spl_autoload_register([$this, 'modelsAutoloader']);
    }

    public function __destruct()
    {
        spl_autoload_unregister([$this, 'modelsAutoloader']);
    }

    public function modelsAutoloader($className)
    {
        if (file_exists('unit-tests/models/' . $className . '.php')) {
            require 'unit-tests/models/' . $className . '.php';
        }
    }

    public function testEventsFetch()
    {
        require 'unit-tests/config.db.php';
        if (empty($configMysql)) {
            $this->markTestSkipped('Test skipped');
            return;
        }

        $trace = [];

        $this->_prepareDI($trace);

        $robot = GossipRobots::findFirst();

        $robot->trace = &$trace;

        $this->assertEquals($trace, [
            'afterFetch' => [
                'GossipRobots' => 1,
            ],
        ]);

    }

    protected function _prepareDI(&$trace)
    {
        Phalcon\DI::reset();

        $eventsManager = new Phalcon\Events\Manager();

        $eventsManager->attach('model', function ($event, $model) use (&$trace) {
            if (!isset($trace[$event->getType()][get_class($model)])) {
                $trace[$event->getType()][get_class($model)] = 1;
            } else {
                $trace[$event->getType()][get_class($model)]++;
            }
        });

        $di = new Phalcon\DI();

        $di->set('modelsManager', function () use ($eventsManager) {

            $modelsManager = new Phalcon\Mvc\Model\Manager();

            $modelsManager->setEventsManager($eventsManager);

            return $modelsManager;
        }, true);

        $di->set('modelsMetadata', function () {
            return new Phalcon\Mvc\Model\Metadata\Memory();
        }, true);

        $di->set('db', function () {
            require 'unit-tests/config.db.php';
            return new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);
        }, true);
    }

    public function testEventsCreate()
    {
        require 'unit-tests/config.db.php';
        if (empty($configMysql)) {
            $this->markTestSkipped('Test skipped');
            return;
        }

        $trace = [];

        $this->_prepareDI($trace);

        $robot = new GossipRobots();

        $robot->name     = 'Test';
        $robot->year     = 2000;
        $robot->type     = 'Some Type';
        $robot->datetime = '1970/01/01 00:00:00';
        $robot->text     = 'text';

        $robot->trace = &$trace;

        $robot->save();

        $this->assertEquals($trace, [
            'prepareSave'              => [
                'GossipRobots' => 1,
            ],
            'beforeValidation'         => [
                'GossipRobots' => 2,
            ],
            'beforeValidationOnCreate' => [
                'GossipRobots' => 1,
            ],
            'validation'               => [
                'GossipRobots' => 2,
            ],
            'afterValidationOnCreate'  => [
                'GossipRobots' => 1,
            ],
            'afterValidation'          => [
                'GossipRobots' => 2,
            ],
            'beforeSave'               => [
                'GossipRobots' => 2,
            ],
            'beforeCreate'             => [
                'GossipRobots' => 1,
            ],
        ]);

    }

    public function testEventsUpdate()
    {
        require 'unit-tests/config.db.php';
        if (empty($configMysql)) {
            $this->markTestSkipped('Test skipped');
            return;
        }

        $trace = [];

        $this->_prepareDI($trace);

        $robot = GossipRobots::findFirst();

        $robot->trace = &$trace;

        $robot->save();

        $this->assertEquals($trace, [
            'prepareSave'              => [
                'GossipRobots' => 1,
            ],
            'beforeValidation'         => [
                'GossipRobots' => 2,
            ],
            'beforeValidationOnUpdate' => [
                'GossipRobots' => 2,
            ],
            'validation'               => [
                'GossipRobots' => 2,
            ],
            'afterValidationOnUpdate'  => [
                'GossipRobots' => 2,
            ],
            'afterValidation'          => [
                'GossipRobots' => 2,
            ],
            'beforeSave'               => [
                'GossipRobots' => 2,
            ],
            'beforeUpdate'             => [
                'GossipRobots' => 2,
            ],
            'afterUpdate'              => [
                'GossipRobots' => 2,
            ],
            'afterSave'                => [
                'GossipRobots' => 2,
            ],
            'afterFetch'               => [
                'GossipRobots' => 1,
            ],
        ]);

    }

    public function testEventsDelete()
    {
        require 'unit-tests/config.db.php';
        if (empty($configMysql)) {
            $this->markTestSkipped('Test skipped');
            return;
        }

        $trace = [];

        $this->_prepareDI($trace);

        $robot = GossipRobots::findFirst();

        $robot->trace = &$trace;

        $robot->delete();

        $this->assertEquals($trace, [
            'afterFetch'   => [
                'GossipRobots' => 1,
            ],
            'beforeDelete' => [
                'GossipRobots' => 1,
            ],
        ]);

    }

}
