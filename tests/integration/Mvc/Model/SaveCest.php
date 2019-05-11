<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Employees;
use Phalcon\Test\Models\Robots;
use function is_int;
use function is_string;
use function uniqid;

/**
 * Class SaveCest
 */
class SaveCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();
    }

    /**
     * Tests Phalcon\Mvc\Model :: save()
     *
     * @dataProvider getFunctions
     *
<<<<<<< HEAD
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-04-30
=======
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-10
>>>>>>> [#13002] - Introducing migrations
     */
    public function mvcModelSave(IntegrationTester $I, Example $function)
    {
        $I->wantToTest('Mvc\Model - save()');

<<<<<<< HEAD
        /**
         * New model
         */
        $user = new Models\Users();
        $user->id = 54321;
        $user->name = null;

        $I->assertFalse($user->save());

        $user->name = 'New User';

        $I->assertTrue($user->save());

        /**
         * Saved model
         */
        $user = Models\Users::findFirst(54321);

        $I->assertEquals(
            [
                'id'   => 54321,
                'name' => 'New User',
            ],
            $user->toArray()
        );

        $user->name = 'Existing User';

        $I->assertTrue($user->save());

        /**
         * Modified saved model
         */
        $user = Models\Users::findFirst(54321);

        $I->assertEquals(
            [
                'id'   => 54321,
                'name' => 'Existing User',
            ],
            $user->toArray()
        );

        $user->name = null;

        $I->assertFalse($user->save());

        /**
         * Verify model count
         */
        $I->assertEquals(
            1,
            Models\Users::count(['id = 54321'])
        );

        /**
         * Deleting is necessary because other tests may rely on specific row count
         */
        $I->assertTrue($user->delete());
    }

    /**
     * Tests Phalcon\Mvc\Model :: save() with related records
     *
     * @param IntegrationTester $I
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-04-30
     */
    public function mvcModelSaveWithRelatedRecords(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - save() with related records');

        $robotPart = new Models\RobotsParts();

        $robotPart->robot = new Models\Robots();
        $robotPart->robot->assign([
            'name'     => 'Test Robots',
            'type'     => 'mechanical',
            'year'     => 2019,
            'datetime' => (new \DateTime())->format('Y-m-d'),
            'text'     => 'Test text',
        ]);

        $part = new Models\Parts();
        $part->name = 'Test Parts';

        $robotPart->part = $part;

        $I->assertTrue($robotPart->save());

        $I->assertGreaterThan(
            0,
            $robotPart->robots_id
        );

        $I->assertGreaterThan(
            0,
            $robotPart->parts_id
        );

        $I->assertGreaterThan(
            0,
            $robotPart->robot->id
        );

        $I->assertGreaterThan(
            0,
            $part->id
        );

        $connection = $this->getService('db');

        $I->assertFalse((bool) $connection->isUnderTransaction());

        $I->assertEquals(
            Model::DIRTY_STATE_PERSISTENT,
            $robotPart->getDirtyState()
        );

        $I->assertEquals(
            Model::DIRTY_STATE_PERSISTENT,
            $robotPart->robot->getDirtyState()
        );

        $I->assertEquals(
            Model::DIRTY_STATE_PERSISTENT,
            $part->getDirtyState()
        );

        /**
         * Deleting is necessary because other tests may rely on specific row count
         */
        $I->assertTrue($robotPart->delete());
        $I->assertTrue($robotPart->robot->delete());
        $I->assertTrue($part->delete());
    }

    /**
     * Tests Phalcon\Mvc\Model :: save() after fetching related records
     *
     * @param IntegrationTester $I
     *
     * @see https://github.com/phalcon/cphalcon/issues/13964
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-04-26
     */
    public function mvcModelSaveAfterFetchingRelated(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - save() after fetching related');

        /**
         * @var Models\AlbumORama\Albums $album
         */
        $album = Models\AlbumORama\Albums::findFirst();

        /**
         * @var Models\AlbumORama\Artists $artist
         */
        $artist = $album->artist;

        $I->assertTrue($album->save());

        /**
         * @var \Phalcon\Mvc\Model\Resultset\Simple $songs
         */
        $songs = $album->songs;

        $I->assertTrue($album->save());
    }

    /**
     * Tests Phalcon\Mvc\Model :: save() after using related records getters
     *
     * @param IntegrationTester $I
     *
     * @see https://github.com/phalcon/cphalcon/issues/13964
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-04-26
     */
    public function mvcModelSaveAfterUsingRelatedGetters(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - save() after using related records getters');

        /**
         * @var Models\AlbumORama\Albums $album
         */
        $album = Models\AlbumORama\Albums::findFirst();

        /**
         * @var Models\AlbumORama\Artists $artist
         */
        $artist = $album->getArtist();

        $I->assertTrue($album->save());

        /**
         * @var \Phalcon\Mvc\Model\Resultset\Simple $songs
         */
        $songs = $album->getSongs();

        $I->assertTrue($album->save());
=======
        $method = $function[0];
        $this->$method();

        $first                     = uniqid();
        $last                      = uniqid();
        $employee                  = new Employees();
        $employee->empNameFirst    = $first;
        $employee->empNameLast     = $last;
        $employee->empCreatedDate  = '2019-05-10 00:00:00';
        $employee->empCreatedEmpId = 1;

        $result = $employee->save();
        $I->assertTrue($result);

        $result = $employee->delete();
        $I->assertTrue($result);
>>>>>>> [#13002] - Introducing migrations
    }

    /**
     * Tests Phalcon\Mvc\Model :: save() - cast lastInsertId to int
     *
     * @dataProvider getFunctions
     *
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2019-05-10
     */
    public function mvcModelSaveCastLastInsertId(IntegrationTester $I, Example $function)
    {
        $I->wantToTest('Mvc\Model - save() - cast lastInsertId to int');

        $method = $function[0];
        $this->$method();

        Robots::setup(
            [
                'castLastInsertIdToInt' => true,
            ]
        );

        $first                     = uniqid();
        $last                      = uniqid();
        $employee                  = new Employees();
        $employee->empNameFirst    = $first;
        $employee->empNameLast     = $last;
        $employee->empCreatedDate  = '2019-05-10 00:00:00';
        $employee->empCreatedEmpId = 1;

        $result = $employee->save();
        $I->assertTrue($result);

        $actual = $employee->empId;
        $I->assertTrue(is_int($actual));

        $expected = intval($actual, 10);
        $I->assertEquals($expected, $actual);

        $result = $employee->delete();
        $I->assertTrue($result);

        Robots::setup(
            [
                'castLastInsertIdToInt' => false,
            ]
        );

        $first                     = uniqid();
        $last                      = uniqid();
        $employee                  = new Employees();
        $employee->empNameFirst    = $first;
        $employee->empNameLast     = $last;
        $employee->empCreatedDate  = '2019-05-10 00:00:00';
        $employee->empCreatedEmpId = 1;

        $result = $employee->save();
        $I->assertTrue($result);

        $actual = $employee->empId;
        $I->assertTrue(is_string($actual));

        $expected = (string) $actual;
        $I->assertEquals($expected, $actual);

        $result = $employee->delete();
        $I->assertTrue($result);
    }

    /**
     * @return array
     */
    public function getFunctions(): array
    {
        return [
            ['setDiMysql'],
//            ['setDiPostgresql'],
            ['setDiSqlite'],
        ];
    }
}
