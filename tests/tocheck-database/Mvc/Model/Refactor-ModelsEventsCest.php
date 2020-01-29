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

        $robot = GossipRobots::findFirst();

        $robot->trace = &$trace;

        $I->assertEquals(
            $trace,
            [
                'afterFetch' => [
                    GossipRobots::class => 1,
                ],
            ]
        );
    }

    private function prepareDI(&$trace)
    {
        $this->setNewFactoryDefault();

        $eventsManager = $this->newEventsManager();

        $eventsManager->attach(
            'model',
            function ($event, $model) use (&$trace) {
                $type  = $event->getType();
                $class = get_class($model);

                if (!isset($trace[$type][$class])) {
                    $trace[$type][$class] = 0;
                }

                $trace[$type][$class]++;
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

        $robot = new GossipRobots();

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
                    GossipRobots::class => 1,
                ],
                'beforeValidation'         => [
                    GossipRobots::class => 2,
                ],
                'beforeValidationOnCreate' => [
                    GossipRobots::class => 1,
                ],
                'validation'               => [
                    GossipRobots::class => 2,
                ],
                'afterValidationOnCreate'  => [
                    GossipRobots::class => 1,
                ],
                'afterValidation'          => [
                    GossipRobots::class => 2,
                ],
                'beforeSave'               => [
                    GossipRobots::class => 2,
                ],
                'beforeCreate'             => [
                    GossipRobots::class => 1,
                ],
            ]
        );
    }

    public function testEventsUpdate(IntegrationTester $I)
    {
        $trace = [];

        $this->prepareDI($trace);
        $this->setDiMysql();

        $robot = GossipRobots::findFirst();

        $robot->trace = &$trace;

        $robot->save();

        $I->assertEquals(
            $trace,
            [
                'prepareSave'              => [
                    GossipRobots::class => 1,
                ],
                'beforeValidation'         => [
                    GossipRobots::class => 2,
                ],
                'beforeValidationOnUpdate' => [
                    GossipRobots::class => 2,
                ],
                'validation'               => [
                    GossipRobots::class => 2,
                ],
                'afterValidationOnUpdate'  => [
                    GossipRobots::class => 2,
                ],
                'afterValidation'          => [
                    GossipRobots::class => 2,
                ],
                'beforeSave'               => [
                    GossipRobots::class => 2,
                ],
                'beforeUpdate'             => [
                    GossipRobots::class => 2,
                ],
                'afterUpdate'              => [
                    GossipRobots::class => 2,
                ],
                'afterSave'                => [
                    GossipRobots::class => 2,
                ],
                'afterFetch'               => [
                    GossipRobots::class => 1,
                ],
            ]
        );
    }

    public function testEventsDelete(IntegrationTester $I)
    {
        $trace = [];

        $this->prepareDI($trace);
        $this->setDiMysql();

        $robot = GossipRobots::findFirst();

        $robot->trace = &$trace;

        $robot->delete();

        $I->assertEquals(
            $trace,
            [
                'afterFetch'   => [
                    GossipRobots::class => 1,
                ],
                'beforeDelete' => [
                    GossipRobots::class => 1,
                ],
            ]
        );
    }
}
