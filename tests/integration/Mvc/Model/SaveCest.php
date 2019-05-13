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

use Codeception\Example;
use IntegrationTester;
use Phalcon\Mvc\Model;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\AlbumORama\Albums;
use Phalcon\Test\Models\AlbumORama\Artists;
use Phalcon\Test\Models\Parts;
use Phalcon\Test\Models\Prueba;
use Phalcon\Test\Models\Robots;
use Phalcon\Test\Models\RobotsParts;
use Phalcon\Test\Models\Users;
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
    }

    /**
     * Tests Phalcon\Mvc\Model :: save()
     *
     * @dataProvider getFunctions
     *
     * @author       Balázs Németh <https://github.com/zsilbi>
     * @since        2019-04-30
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2019-05-10
     */
    public function mvcModelSave(IntegrationTester $I, Example $function)
    {
        $I->wantToTest('Mvc\Model - save()');
        $this->setDiMysql();

        /**
         * New model
         */
        $user       = new Users();
        $user->id   = 54321;
        $user->name = null;

        $I->assertFalse($user->save());

        $user->name = 'New User';

        $I->assertTrue($user->save());

        /**
         * Saved model
         */
        $user = Users::findFirst(54321);

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
        $user = Users::findFirst(54321);

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
            Users::count(['id = 54321'])
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
        $this->setDiMysql();

        $robotPart = new RobotsParts();

        $robotPart->robot = new Robots();
        $robotPart->robot->assign([
            'name'     => 'Test Robots',
            'type'     => 'mechanical',
            'year'     => 2019,
            'datetime' => (new \DateTime())->format('Y-m-d'),
            'text'     => 'Test text',
        ]);

        $part       = new Parts();
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
     * @see    https://github.com/phalcon/cphalcon/issues/13964
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-04-26
     */
    public function mvcModelSaveAfterFetchingRelated(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - save() after fetching related');
        $this->setDiMysql();

        /**
         * @var Albums $album
         */
        $album = Albums::findFirst();

        /**
         * @var Artists $artist
         */
        $artist = $album->artist;

        $I->assertTrue($album->save());

        /**
         * @var Model\Resultset\Simple $songs
         */
        $songs = $album->songs;

        $I->assertTrue($album->save());
    }

    /**
     * Tests Phalcon\Mvc\Model :: save() after using related records getters
     *
     * @param IntegrationTester $I
     *
     * @see    https://github.com/phalcon/cphalcon/issues/13964
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-04-26
     */
    public function mvcModelSaveAfterUsingRelatedGetters(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - save() after using related records getters');
        $this->setDiMysql();

        /**
         * @var Albums $album
         */
        $album = Albums::findFirst();

        /**
         * @var Artists $artist
         */
        $artist = $album->getArtist();

        $I->assertTrue($album->save());

        /**
         * @var \Model\Resultset\Simple $songs
         */
        $songs = $album->getSongs();

        $I->assertTrue($album->save());
    }

    /**
     * Tests Phalcon\Mvc\Model :: save() - cast lastInsertId to int - default
     *
     * @dataProvider getFunctions
     *
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2019-05-10
     */
    public function mvcModelSaveCastLastInsertIdDefault(IntegrationTester $I, Example $function)
    {
        $I->wantToTest('Mvc\Model - save() - cast lastInsertId to int default');

        $method = $function[0];
        $this->$method();

        Prueba::setup(
            [
                'castLastInsertIdToInt' => false,
            ]
        );

        $name         = uniqid();
        $test         = new Prueba();
        $test->nombre = $name;
        $test->estado = 'A';

        $result = $test->save();
        $I->assertTrue($result);

        $actual = $test->id;
        $I->assertTrue(is_string($actual));

        $expected = intval($actual, 10);
        $I->assertEquals($expected, $actual);

        $result = $test->delete();
        $I->assertTrue($result);
    }

    /**
     * Tests Phalcon\Mvc\Model :: save() - cast lastInsertId to int
     *
     * @dataProvider getFunctions
     *
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2019-05-10
     */
    public function mvcModelSaveCastLastInsertIdInt(IntegrationTester $I, Example $function)
    {
        $I->wantToTest('Mvc\Model - save() - cast lastInsertId to int');

        $method = $function[0];
        $this->$method();

        Prueba::setup(
            [
                'castLastInsertIdToInt' => true,
            ]
        );

        $name         = uniqid();
        $test         = new Prueba();
        $test->nombre = $name;
        $test->estado = 'A';

        $result = $test->save();
        $I->assertTrue($result);

        $actual = $test->id;
        $I->assertTrue(is_int($actual));

        $expected = intval($actual, 10);
        $I->assertEquals($expected, $actual);

        $result = $test->delete();
        $I->assertTrue($result);
    }

    /**
     * Database providers
     *
     * @return array
     */
    private function getFunctions(): array
    {
        return [
            ['setDiMysql'],
            ['setDiPostgresql'],
            ['setDiSqlite'],
        ];
    }
}
