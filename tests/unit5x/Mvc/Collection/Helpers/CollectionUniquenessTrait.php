<?php

namespace Phalcon\Test\Unit5x\Mvc\Collection\Helpers;

use DateTime;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Uniqueness;
use UnitTester;

trait CollectionUniquenessTrait
{
    private function testSingleField(UnitTester $I)
    {
        $validation = new Validation();
        $validation->add('type', new Uniqueness());
        $messages = $validation->validate(null, $this->robot);
        $I->assertCount(0, $messages);
        $I->assertTrue($this->robot->save());
        $messages = $validation->validate(null, $this->robot);
        $I->assertCount(0, $messages);
        $messages = $validation->validate(null, $this->anotherRobot);
        $I->assertCount(0, $messages);
        $messages = $validation->validate(null, $this->deletedRobot);
        $I->assertCount(1, $messages);
    }

    private function testSingleFieldConvert(UnitTester $I)
    {
        $validation = new Validation();
        $validation->add('type', new Uniqueness([
            'convert' => function (array $values) {
                $values['type'] = 'hydraulic'; // mechanical -> hydraulic
                return $values;
            }
        ]));
        $messages = $validation->validate(null, $this->deletedRobot);
        $I->assertCount(0, $messages);
    }

    private function testSingleFieldWithNull(UnitTester $I)
    {
        $validation = new Validation();
        $validation->add('deleted', new Uniqueness());
        $messages = $validation->validate(null, $this->robot);
        $I->assertCount(0, $messages);
        $messages = $validation->validate(null, $this->anotherRobot);
        $I->assertCount(1, $messages);
        $messages = $validation->validate(null, $this->deletedRobot);
        $I->assertCount(0, $messages);
    }

    private function testMultipleFields(UnitTester $I)
    {
        $validation = new Validation();
        $validation->add(['name', 'type'], new Uniqueness());
        $messages = $validation->validate(null, $this->robot);
        $I->assertCount(0, $messages);
        $messages = $validation->validate(null, $this->anotherRobot);
        $I->assertCount(0, $messages);
        $messages = $validation->validate(null, $this->deletedRobot);
        $I->assertCount(1, $messages);
    }

    private function testMultipleFieldsConvert(UnitTester $I)
    {
        $validation = new Validation();
        $validation->add(['name', 'type'], new Uniqueness([
            'convert' => function (array $values) {
                $values['type'] = 'hydraulic'; // mechanical -> hydraulic
                return $values;
            }
        ]));
        $messages = $validation->validate(null, $this->deletedRobot);
        $I->assertCount(0, $messages);
    }

    private function testMultipleFieldsWithNull(UnitTester $I)
    {
        $validation = new Validation();
        $validation->add(['type', 'deleted'], new Uniqueness());
        $messages = $validation->validate(null, $this->robot);
        $I->assertCount(0, $messages);
        $messages = $validation->validate(null, $this->anotherRobot);
        $I->assertCount(0, $messages);
        $messages = $validation->validate(null, $this->deletedRobot);
        $I->assertCount(0, $messages);
        $this->deletedRobot->deleted = null;
        $messages = $validation->validate(null, $this->deletedRobot);
        $I->assertCount(1, $messages);
        $this->deletedRobot->deleted = (new DateTime())->format('Y-m-d H:i:s');
    }

    private function testExceptSingleFieldSingleExcept(UnitTester $I)
    {
        $validation = new Validation();
        $validation->add('year', new Uniqueness([
            'except' => 1972,
        ]));
        $messages = $validation->validate(null, $this->robot);
        $I->assertCount(0, $messages);
        $I->assertTrue($this->anotherRobot->save());
        $messages = $validation->validate(null, $this->deletedRobot);
        $I->assertCount(1, $messages);
    }

    private function testExceptSingleFieldMultipleExcept(UnitTester $I)
    {
        $validation = new Validation();
        $validation->add('year', new Uniqueness([
            'except' => [1972, 1952],
        ]));
        $messages = $validation->validate(null, $this->robot);
        $I->assertCount(0, $messages);
        $messages = $validation->validate(null, $this->anotherRobot);
        $I->assertCount(0, $messages);
    }

    private function testExceptMultipleFieldSingleExcept(UnitTester $I)
    {
        $validation = new Validation();
        $validation->add(['type', 'year'], new Uniqueness([
            'except' => [
                'type' => 'hydraulic',
                'year' => 1952,
            ],
        ]));
        $messages = $validation->validate(null, $this->deletedRobot);
        $I->assertCount(0, $messages);
        $this->deletedRobot->type = 'mechanical';
        $this->deletedRobot->year = 1972;
        $messages = $validation->validate(null, $this->deletedRobot);
        $I->assertCount(1, $messages);
        $this->deletedRobot->type = 'hydraulic';
        $this->deletedRobot->year = 1952;
    }

    private function testExceptMultipleFieldMultipleExcept(UnitTester $I)
    {
        $validation = new Validation();
        $validation->add(['year', 'type'], new Uniqueness([
            'except' => [
                'year' => [1942, 1972],
                'type' => ['hydraulic', 'cyborg'],
            ],
        ]));
        $messages = $validation->validate(null, $this->robot);
        $I->assertCount(0, $messages);
        $messages = $validation->validate(null, $this->anotherRobot);
        $I->assertCount(0, $messages);
    }

    private function testConvertArrayReturnsArray(UnitTester $I)
    {
        $validation = new Validation();
        $validation->add('type', new Uniqueness([
            'convert' => function (array $values) {
                ($values);
                return null;
            }
        ]));
        try {
            $validation->validate(null, $this->robot);
            $I->assertTrue(false);
        } catch (\Exception $e) {
            $I->assertTrue(true);
        }
    }
}
