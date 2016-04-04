<?php
use Phalcon\Test\Models\TestAfterFetchRobots;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Mvc\Model\Resultset\SimpleTest
 * Tests the Phalcon\Mvc\Model\Resultset\Simple component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Unit\Mvc\Model\Resultset
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class SimpleTest extends UnitTest
{
    public function testToArrayAfterFetchRemoveColumns()
    {
        $this->specify(
            "After fetch should be fired on toArray method and should remove columns",
            function () {
                $expectedRobots = [
                    ['datetime'=>new DateTime('1972-01-01 00:00:00')],
                    ['datetime'=>new DateTime('1952-01-01 00:00:00')],
                    ['datetime'=>new DateTime('2029-01-01 00:00:00')]
                ];
                
                $actualRobots = TestAfterFetchRobots::find([
                    'columns'=>['datetime'],
                    'fireAfterFetch'=>true
                ])->toArray(true);
                expect($actualRobots)->equals($expectedRobots);
            }
        );
    }

    public function testToArrayAfterFetch()
    {
        $this->specify(
            "After fetch should be fired on toArray method",
            function () {
                $expectedRobots = [
                    ['datetime'=>new DateTime('1972-01-01 00:00:00'),'text'=>'texttexttext'],
                    ['datetime'=>new DateTime('1952-01-01 00:00:00'),'text'=>'texttexttext'],
                    ['datetime'=>new DateTime('2029-01-01 00:00:00'),'text'=>'texttexttext']
                ];

                $actualRobots = TestAfterFetchRobots::find([
                    'columns'=>['datetime'],
                    'fireAfterFetch'=>true
                ])->toArray();
                expect($actualRobots)->equals($expectedRobots);
            }
        );
    }

    public function testAfterFetch()
    {
        $this->specify(
            "After fetch should be fired on Row",
            function () {
                $expectedRobot = ['datetime'=>new DateTime('1972-01-01 00:00:00'),'text'=>'texttexttext'];

                $actualRobot = TestAfterFetchRobots::findFirst([
                    'conditions'=>'id = 1',
                    'columns'=>['datetime','text'],
                    'fireAfterFetch'=>true
                ])->toArray();
                expect($actualRobot)->equals($expectedRobot);
            }
        );
    }

    public function testAfterFetchRemoveColumns()
    {
        $this->specify(
            "After fetch should return remove columns if there are additional columns on Row",
            function () {
                $expectedRobot = ['datetime'=>new DateTime('1972-01-01 00:00:00')];

                $actualRobot = TestAfterFetchRobots::findFirst([
                    'conditions'=>'id = 1',
                    'columns'=>['datetime'],
                    'fireAfterFetch'=>true
                ])->toArray();
                expect($actualRobot)->equals($expectedRobot);
            }
        );
    }

    public function testAfterFetchFalse()
    {
        $this->specify(
            "After fetch should not be fired when false",
            function () {
                $expectedRobot = ['datetime'=>'1972-01-01 00:00:00'];

                $actualRobot = TestAfterFetchRobots::findFirst([
                    'conditions'=>'id = 1',
                    'columns'=>['datetime'],
                    'fireAfterFetch'=>false
                ])->toArray();
                expect($actualRobot)->equals($expectedRobot);
            }
        );
    }

    public function testToArrayAfterFetchFalse()
    {
        $this->specify(
            "After fetch should not be fired when false on toArray method",
            function () {
                $expectedRobots = [
                    ['datetime'=>'1972-01-01 00:00:00'],
                    ['datetime'=>'1952-01-01 00:00:00'],
                    ['datetime'=>'2029-01-01 00:00:00']
                ];

                $actualRobots = TestAfterFetchRobots::find([
                    'columns'=>['datetime'],
                    'fireAfterFetch'=>false
                ])->toArray();
                expect($actualRobots)->equals($expectedRobots);
            }
        );
    }
}
