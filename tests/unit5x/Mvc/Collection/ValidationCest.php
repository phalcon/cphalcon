<?php

namespace Phalcon\Test\Unit5x\Mvc\Collection;

use DateTime;
use Helper\CollectionTrait;
use Phalcon\Test\Collections\Robots;
use Phalcon\Test\Unit5x\Mvc\Collection\Helpers\CollectionUniquenessTrait;
use Phalcon\Test\Unit5x\Mvc\Collection\Helpers\ValidationBase;
use UnitTester;

/**
 * Phalcon\Test\Unit5x\Mvc\Collection\ValidationCest
 * Tests the Phalcon\Mvc\Collection component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit5x\Mvc\Collection
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ValidationCest extends ValidationBase
{
    /**
     * @var Robots
     */
    private $robot;

    /**
     * @var Robots
     */
    private $anotherRobot;

    /**
     * @var Robots
     */
    private $deletedRobot;

    private $mongo;

    use CollectionTrait;
    use CollectionUniquenessTrait;

    public function mongo(UnitTester $I)
    {
        $I->wantToTest("Collection validation");

        $this->setupMongo($I);
        $this->mongo = $I->grabServiceFromDi('mongo');

        $this->success($I);
        $this->presenceOf($I);
        $this->email($I);
        $this->exclusionIn($I);
        $this->inclusionIn($I);
        $this->uniqueness1($I);
        $this->regex($I);
        $this->tooLong($I);
        $this->tooShort($I);
    }

    public function mongoUniqueness(UnitTester $I)
    {
        $I->wantToTest("Collection Uniqueness validation");

        $this->setupMongo($I);

        $this->robot = new Robots();
        $this->robot->name = 'Robotina';
        $this->robot->type = 'mechanical';
        $this->robot->year = 1972;
        $this->robot->datetime = (new DateTime())->format('Y-m-d H:i:s');
        $this->robot->deleted = null;
        $this->robot->text = 'text';

        $this->anotherRobot = new Robots();
        $this->anotherRobot->name = 'Robotina';
        $this->anotherRobot->type = 'hydraulic';
        $this->anotherRobot->year = 1952;
        $this->anotherRobot->datetime = (new DateTime())->format('Y-m-d H:i:s');
        $this->anotherRobot->deleted = null;
        $this->anotherRobot->text = 'text';

        $this->deletedRobot = new Robots();
        $this->deletedRobot->name = 'Robotina';
        $this->deletedRobot->type = 'mechanical';
        $this->deletedRobot->year = 1952;
        $this->deletedRobot->datetime = (new DateTime())->format('Y-m-d H:i:s');
        $this->deletedRobot->deleted = (new DateTime())->format('Y-m-d H:i:s');
        $this->deletedRobot->text = 'text';

        $this->testSingleField($I);
        $this->testSingleFieldConvert($I);
        $this->testSingleFieldWithNull($I);
        $this->testMultipleFields($I);
        $this->testMultipleFieldsConvert($I);
        $this->testMultipleFieldsWithNull($I);
        $this->testExceptSingleFieldSingleExcept($I);
        $this->testExceptSingleFieldMultipleExcept($I);
        $this->testExceptMultipleFieldSingleExcept($I);
        $this->testExceptMultipleFieldMultipleExcept($I);
        $this->testConvertArrayReturnsArray($I);
    }

    public function __destruct()
    {
        if (extension_loaded('mongo')) {
            $this->mongo->selectCollection('robots')->remove();
            $this->mongo->selectCollection('users')->remove();
            $this->mongo->selectCollection('people')->remove();
        }
    }
}
