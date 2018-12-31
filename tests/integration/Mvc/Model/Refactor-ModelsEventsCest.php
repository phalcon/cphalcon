<?php

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;
use Phalcon\Mvc\Model\Manager as ModelManager;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\GossipRobots;

class ModelsEventsCest
{
    use DiTrait;

    public function testEventsFetch(IntegrationTester $I)
    {
        $trace = [];
        $this->prepareDi($trace);
        $this->setDiMysql();

        $robot        = GossipRobots::findFirst();
        $robot->trace = &$trace;
        $I->assertEquals(
            $trace,
            [
                'afterFetch' => [
                    'Phalcon\Test\Models\GossipRobots' => 1,
                ],
            ]
        );
    }

    /**
     * @param $trace
     */
    private function prepareDI(&$trace)
    {
        $this->setNewFactoryDefault();
        $eventsManager = $this->newEventsManager();
        $eventsManager->attach(
            'model',
            function ($event, $model) use (&$trace) {
                if (!isset($trace[$event->getType()][get_class($model)])) {
                    $trace[$event->getType()][get_class($model)] = 1;
                } else {
                    $trace[$event->getType()][get_class($model)]++;
                }
            }
        );

        $this->container->setShared('eventsManager', $eventsManager);
        $this->container->setShared(
            'modelsManager',
            function () use ($eventsManager) {
                $modelsManager = new ModelManager();
                $modelsManager->setEventsManager($eventsManager);

                return $modelsManager;
            }
        );
    }

    public function testEventsCreate(IntegrationTester $I)
    {
        $trace = [];
        $this->prepareDI($trace);
        $this->setDiMysql();

        $robot           = new GossipRobots();
        $robot->name     = 'Test';
        $robot->year     = 2000;
        $robot->type     = 'Some Type';
        $robot->datetime = '1970/01/01 00:00:00';
        $robot->text     = 'text';
        $robot->trace    = &$trace;
        $robot->save();

        $I->assertEquals(
            $trace,
            [
                'prepareSave'              => [
                    'Phalcon\Test\Models\GossipRobots' => 1,
                ],
                'beforeValidation'         => [
                    'Phalcon\Test\Models\GossipRobots' => 2,
                ],
                'beforeValidationOnCreate' => [
                    'Phalcon\Test\Models\GossipRobots' => 1,
                ],
                'validation'               => [
                    'Phalcon\Test\Models\GossipRobots' => 2,
                ],
                'afterValidationOnCreate'  => [
                    'Phalcon\Test\Models\GossipRobots' => 1,
                ],
                'afterValidation'          => [
                    'Phalcon\Test\Models\GossipRobots' => 2,
                ],
                'beforeSave'               => [
                    'Phalcon\Test\Models\GossipRobots' => 2,
                ],
                'beforeCreate'             => [
                    'Phalcon\Test\Models\GossipRobots' => 1,
                ],
            ]
        );
    }

    public function testEventsUpdate(IntegrationTester $I)
    {
        $trace = [];
        $this->prepareDI($trace);
        $this->setDiMysql();

        $robot        = GossipRobots::findFirst();
        $robot->trace = &$trace;
        $robot->save();

        $I->assertEquals(
            $trace,
            [
                'prepareSave'              => [
                    'Phalcon\Test\Models\GossipRobots' => 1,
                ],
                'beforeValidation'         => [
                    'Phalcon\Test\Models\GossipRobots' => 2,
                ],
                'beforeValidationOnUpdate' => [
                    'Phalcon\Test\Models\GossipRobots' => 2,
                ],
                'validation'               => [
                    'Phalcon\Test\Models\GossipRobots' => 2,
                ],
                'afterValidationOnUpdate'  => [
                    'Phalcon\Test\Models\GossipRobots' => 2,
                ],
                'afterValidation'          => [
                    'Phalcon\Test\Models\GossipRobots' => 2,
                ],
                'beforeSave'               => [
                    'Phalcon\Test\Models\GossipRobots' => 2,
                ],
                'beforeUpdate'             => [
                    'Phalcon\Test\Models\GossipRobots' => 2,
                ],
                'afterUpdate'              => [
                    'Phalcon\Test\Models\GossipRobots' => 2,
                ],
                'afterSave'                => [
                    'Phalcon\Test\Models\GossipRobots' => 2,
                ],
                'afterFetch'               => [
                    'Phalcon\Test\Models\GossipRobots' => 1,
                ],
            ]
        );
    }

    public function testEventsDelete(IntegrationTester $I)
    {
        $trace = [];
        $this->prepareDI($trace);
        $this->setDiMysql();

        $robot        = GossipRobots::findFirst();
        $robot->trace = &$trace;
        $robot->delete();

        $I->assertEquals(
            $trace,
            [
                'afterFetch'   => [
                    'Phalcon\Test\Models\GossipRobots' => 1,
                ],
                'beforeDelete' => [
                    'Phalcon\Test\Models\GossipRobots' => 1,
                ],
            ]
        );
    }
}
