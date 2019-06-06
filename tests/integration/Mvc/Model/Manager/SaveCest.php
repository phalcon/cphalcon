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

namespace Phalcon\Test\Integration\Mvc\Model\Manager;

use IntegrationTester;
use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\MetaData;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\AlbumORama\Albums;
use Phalcon\Test\Models\AlbumORama\Artists;
use Phalcon\Test\Models\Parts;
use Phalcon\Test\Models\Robots;
use Phalcon\Test\Models\RobotsParts;
use Phalcon\Test\Models\Users;

class SaveCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    /**
     * Tests Phalcon\Mvc\Model\Manager :: save()
     *
     * @author       Balázs Németh <https://github.com/zsilbi>
     * @since        2019-04-30
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2019-05-10
     */
    public function mvcModelManagerSave(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Manager - save()');

        $modelsManager = $this->container['modelsManager'];

        /**
         * New model
         */
        $user = new Users();

        $user->id   = 54321;
        $user->name = null;

        $I->assertFalse(
            $modelsManager->save($user)
        );

        $user->name = 'New User';

        $I->assertTrue(
            $modelsManager->save($user)
        );

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

        $I->assertTrue(
            $modelsManager->save($user)
        );

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

        $I->assertFalse(
            $modelsManager->save($user)
        );

        /**
         * Verify model count
         */
        $I->assertEquals(
            1,
            Users::count(
                [
                    'id = 54321',
                ]
            )
        );

        /**
         * Deleting is necessary because other tests may rely on specific row count
         */
        $I->assertTrue(
            $modelsManager->delete($user)
        );
    }

    /**
     * Tests Phalcon\Mvc\Model\Manager :: save() with related records
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-04-30
     */
    public function mvcModelManagerSaveWithRelatedRecords(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Manager - save() with related records');

        $modelsManager = $this->container['modelsManager'];

        $robotPart = new RobotsParts();

        $robotPart->robot = new Robots();

        $robotPart->robot->assign(
            [
                'name'     => 'Test Robots',
                'type'     => 'mechanical',
                'year'     => 2019,
                'datetime' => (new \DateTime())->format('Y-m-d'),
                'text'     => 'Test text',
            ]
        );

        $part = new Parts();

        $part->name = 'Test Parts';

        $robotPart->part = $part;

        $I->assertTrue(
            $modelsManager->save($robotPart)
        );

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

        $I->assertFalse(
            $connection->isUnderTransaction()
        );

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
        $I->assertTrue(
            $modelsManager->delete($robotPart)
        );

        $I->assertTrue(
            $modelsManager->delete($robotPart->robot)
        );

        $I->assertTrue(
            $modelsManager->delete($part)
        );
    }

    /**
     * Tests Phalcon\Mvc\Model\Manager :: save() after fetching related records
     *
     * @see    https://github.com/phalcon/cphalcon/issues/13964
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-04-26
     */
    public function mvcModelManagerSaveAfterFetchingRelated(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Manager - save() after fetching related');

        $modelsManager = $this->container['modelsManager'];

        /**
         * @var Albums
         */
        $album = Albums::findFirst();

        /**
         * @var Artists
         */
        $artist = $album->artist;

        $I->assertTrue(
            $modelsManager->save($album)
        );

        /**
         * @var Model\Resultset\Simple
         */
        $songs = $album->songs;

        $I->assertTrue(
            $modelsManager->save($album)
        );
    }

    /**
     * Tests Phalcon\Mvc\Model\Manager :: save() after using related records getters
     *
     * @see    https://github.com/phalcon/cphalcon/issues/13964
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-04-26
     */
    public function mvcModelManagerSaveAfterUsingRelatedGetters(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Manager - save() after using related records getters');

        $modelsManager = $this->container['modelsManager'];

        /**
         * @var Albums
         */
        $album = Albums::findFirst();

        /**
         * @var Artists
         */
        $artist = $album->getArtist();

        $I->assertTrue(
            $modelsManager->save($album)
        );

        /**
         * @var \Model\Resultset\Simple
         */
        $songs = $album->getSongs();

        $I->assertTrue(
            $modelsManager->save($album)
        );
    }

    /**
     * Tests Phalcon\Mvc\Model\Manager :: save() when default values are not set
     *
     * @see    https://github.com/phalcon/cphalcon/issues/13781
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-05-17
     */
    public function mvcModelManagerSaveAfterWithoutDefaultValues(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Manager - save() when default values are not set');

        $modelsManager = $this->container['modelsManager'];

        $robot = new Robots();

        /**
         * Default values are not set:
         *  'year' => 1900,
         *  'type' => "mechanical"
         */
        $robotData = [
            'name'     => 'Default Robot',
            'datetime' => (new \DateTime())->format('Y-m-d'),
            'text'     => 'Test text',
        ];

        $robot->assign($robotData);

        $I->assertTrue(
            $modelsManager->save($robot)
        );

        /**
         * @var MetaData
         */
        $metaData = $robot->getModelsMetaData();

        /**
         * @var array
         */
        $defaultValues = $metaData->getDefaultValues($robot);

        foreach ($defaultValues as $attribute => $value) {
            $I->assertEquals(
                $value,
                $robot->{$attribute}
            );
        }

        /**
         * Cleanup
         */
        $I->assertTrue(
            $modelsManager->delete($robot)
        );
    }

    public function mvcModelManagerSaveCircularRelation(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Manager::save() with circular unsaved relations');

        $modelsManager = $this->container['modelsManager'];

        $album = new Albums(
            [
                'name' => 'Loopback',
            ]
        );

        $artist = new Artists(
            [
                'name' => 'Evil Robot',
            ]
        );

        // Assign relationship in both directions on unsaved models
        $album->artist = $artist;
        $artist->albums = [
            $album,
        ];

        // Save should handle the circular relation without issue
        $I->assertTrue(
            $modelsManager->save($artist)
        );

        // Both should have an ID now
        $I->assertNotNull($album->id);
        $I->assertNotNull($artist->id);
    }
}
