<?php

namespace Phalcon\Test\Integration\Mvc\Model;

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

    public function testForeignKeysMysql(IntegrationTester $I)
    {
        $this->setDiMysql();
        $this->executeTestsNormal($I);
        $this->executeTestsRenamed($I);
    }

    private function executeTestsNormal(IntegrationTester $I)
    {
        //Normal foreign keys
        $robotsParts            = new RobotsParts();
        $robotsParts->robots_id = 1;
        $robotsParts->parts_id  = 100;

        $I->assertFalse($robotsParts->save());

        $messages = [
            0 => Message::__set_state([
                '_type'     => 'ConstraintViolation',
                '_message'  => 'Value of field "parts_id" does not exist on referenced table',
                '_field'    => 'parts_id',
                '_code'     => 0,
                '_metaData' => []
            ]),
        ];

        $I->assertEquals($messages, $robotsParts->getMessages());

        $robotsParts->robots_id = 100;
        $robotsParts->parts_id  = 1;
        $I->assertFalse($robotsParts->save());

        $messages = [
            0 => Message::__set_state([
                '_type'     => 'ConstraintViolation',
                '_message'  => 'The robot code does not exist',
                '_field'    => 'robots_id',
                '_code'     => 0,
                '_metaData' => []
            ]),
        ];

        $I->assertEquals($messages, $robotsParts->getMessages());

        //Reverse foreign keys

        $robot = Robots::findFirst();
        $I->assertNotEquals($robot, false);

        $I->assertFalse($robot->delete());

        $messages = [
            0 => Message::__set_state([
                '_type'     => 'ConstraintViolation',
                '_message'  => 'Record is referenced by model Phalcon\Test\Models\RobotsParts',
                '_field'    => 'id',
                '_code'     => 0,
                '_metaData' => []
            ]),
        ];

        $I->assertEquals($robot->getMessages(), $messages);

        $part = Parts::findFirst();
        $I->assertNotEquals($part, false);

        $I->assertFalse($part->delete());

        $messages = [
            0 => Message::__set_state([
                '_type'     => 'ConstraintViolation',
                '_message'  => 'Parts cannot be deleted because is referenced by a Robot',
                '_field'    => 'id',
                '_code'     => 0,
                '_metaData' => []
            ]),
        ];

        $I->assertEquals($part->getMessages(), $messages);
    }

    private function executeTestsRenamed(IntegrationTester $I)
    {

        //Normal foreign keys with column renaming
        $robottersDeles                = new RobottersDeles();
        $robottersDeles->robottersCode = 1;
        $robottersDeles->delesCode     = 100;
        $I->assertFalse($robottersDeles->save());

        $messages = [
            0 => Message::__set_state([
                '_type'     => 'ConstraintViolation',
                '_message'  => 'Value of field "delesCode" does not exist on referenced table',
                '_field'    => 'delesCode',
                '_code'     => 0,
                '_metaData' => []
            ]),
        ];

        $I->assertEquals($robottersDeles->getMessages(), $messages);

        $robottersDeles->robottersCode = 100;
        $robottersDeles->delesCode     = 1;
        $I->assertFalse($robottersDeles->save());

        $messages = [
            0 => Message::__set_state([
                '_type'     => 'ConstraintViolation',
                '_message'  => 'The robotters code does not exist',
                '_field'    => 'robottersCode',
                '_code'     => 0,
                '_metaData' => []
            ]),
        ];

        $I->assertEquals($robottersDeles->getMessages(), $messages);

        //Reverse foreign keys with renaming
        $robotter = Robotters::findFirst();
        $I->assertNotEquals($robotter, false);

        $I->assertFalse($robotter->delete());

        $messages = [
            0 => Message::__set_state([
                '_type'     => 'ConstraintViolation',
                '_message'  => 'Record is referenced by model Phalcon\Test\Models\RobottersDeles',
                '_field'    => 'code',
                '_code'     => 0,
                '_metaData' => []
            ]),
        ];

        $I->assertEquals($robotter->getMessages(), $messages);

        $dele = Deles::findFirst();
        $I->assertNotEquals($dele, false);

        $I->assertFalse($dele->delete());

        $messages = [
            0 => Message::__set_state([
                '_type'     => 'ConstraintViolation',
                '_message'  => 'Deles cannot be deleted because is referenced by a Robotter',
                '_field'    => 'code',
                '_code'     => 0,
                '_metaData' => []
            ]),
        ];

        $I->assertEquals($dele->getMessages(), $messages);
    }

    public function testForeignKeysPostgresql(IntegrationTester $I)
    {
        $this->setDiPostgresql();
        $this->executeTestsNormal($I);
        $this->executeTestsRenamed($I);
    }

    public function testForeignKeysSqlite(IntegrationTester $I)
    {
        $this->setDiSqlite();
        $this->executeTestsNormal($I);
        $this->executeTestsRenamed($I);
    }
}
