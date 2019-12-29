<?php

namespace Phalcon\Test\Integration\Mvc\Model;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Messages\Message;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Deles;
use Phalcon\Test\Models\Parts;
use Phalcon\Test\Models\Robots;
use Phalcon\Test\Models\RobotsParts;
use Phalcon\Test\Models\Robotters;
use Phalcon\Test\Models\RobottersDeles;

class ModelsForeignKeysCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    /**
     * @dataProvider adaptersProvider
     */
    public function executeTestsNormal(IntegrationTester $I, Example $example)
    {
        $diFunction = 'setDi' . $example[0];

        $this->{$diFunction}();

        //Normal foreign keys

        $robotsParts = new RobotsParts();

        $robotsParts->robots_id = 1;
        $robotsParts->parts_id  = 100;

        $I->assertFalse(
            $robotsParts->save()
        );

        $messages = [
            0 => new Message(
                'Value of field "parts_id" does not exist on referenced table',
                'parts_id',
                'ConstraintViolation'
            ),
        ];

        $I->assertEquals(
            $messages,
            $robotsParts->getMessages()
        );

        $robotsParts->robots_id = 100;
        $robotsParts->parts_id  = 1;

        $I->assertFalse(
            $robotsParts->save()
        );

        $messages = [
            0 => new Message(
                'The robot code does not exist',
                'robots_id',
                'ConstraintViolation'
            ),
        ];

        $I->assertEquals(
            $messages,
            $robotsParts->getMessages()
        );


        //Reverse foreign keys

        $robot = Robots::findFirst();

        $I->assertNotFalse($robot);

        $I->assertFalse(
            $robot->delete()
        );

        $messages = [
            0 => new Message(
                'Record is referenced by model Phalcon\Test\Models\RobotsParts',
                'id',
                'ConstraintViolation'
            ),
        ];

        $I->assertEquals(
            $messages,
            $robot->getMessages()
        );

        $part = Parts::findFirst();

        $I->assertNotFalse($part);

        $I->assertFalse(
            $part->delete()
        );

        $messages = [
            0 => new Message(
                'Parts cannot be deleted because is referenced by a Robot',
                'id',
                'ConstraintViolation'
            ),
        ];

        $I->assertEquals(
            $messages,
            $part->getMessages()
        );
    }

    /**
     * @dataProvider adaptersProvider
     */
    public function executeTestsRenamed(IntegrationTester $I, Example $example)
    {
        $diFunction = 'setDi' . $example[0];

        $this->{$diFunction}();

        //Normal foreign keys with column renaming

        $robottersDeles = new RobottersDeles();

        $robottersDeles->robottersCode = 1;
        $robottersDeles->delesCode     = 100;

        $I->assertFalse(
            $robottersDeles->save()
        );

        $messages = [
            0 => new Message(
                'Value of field "delesCode" does not exist on referenced table',
                'delesCode',
                'ConstraintViolation'
            ),
        ];

        $I->assertEquals(
            $messages,
            $robottersDeles->getMessages()
        );

        $robottersDeles->robottersCode = 100;
        $robottersDeles->delesCode     = 1;

        $I->assertFalse(
            $robottersDeles->save()
        );

        $messages = [
            0 => new Message(
                'The robotters code does not exist',
                'robottersCode',
                'ConstraintViolation'
            ),
        ];

        $I->assertEquals(
            $messages,
            $robottersDeles->getMessages()
        );


        //Reverse foreign keys with renaming

        $robotter = Robotters::findFirst();

        $I->assertNotFalse($robotter);

        $I->assertFalse(
            $robotter->delete()
        );

        $messages = [
            0 => new Message(
                'Record is referenced by model Phalcon\Test\Models\RobottersDeles',
                'code',
                'ConstraintViolation'
            ),
        ];

        $I->assertEquals(
            $messages,
            $robotter->getMessages()
        );

        $dele = Deles::findFirst();

        $I->assertNotFalse($dele);

        $I->assertFalse(
            $dele->delete()
        );

        $messages = [
            0 => new Message(
                'Deles cannot be deleted because is referenced by a Robotter',
                'code',
                'ConstraintViolation'
            ),
        ];

        $I->assertEquals(
            $messages,
            $dele->getMessages()
        );
    }

    private function adaptersProvider(): array
    {
        return [
            [
                'Mysql',
            ],
            [
                'Postgresql',
            ],
            [
                'Sqlite',
            ],
        ];
    }
}
