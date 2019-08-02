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
     * Tests Phalcon\Mvc\Model :: save()
     *
     * @author       Balázs Németh <https://github.com/zsilbi>
     * @since        2019-04-30
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2019-05-10
     */
    public function mvcModelSave(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - save()');

        /**
         * New model
         */
        $user       = new Users();
        $user->id   = 54321;
        $user->name = null;

        $I->assertFalse(
            $user->save()
        );

        $user->name = 'New User';

        $I->assertTrue(
            $user->save()
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
            $user->save()
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
            $user->save()
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
            $user->delete()
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: save() with related records
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-04-30
     */
    public function mvcModelSaveWithRelatedRecords(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - save() with related records');

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
            $robotPart->save()
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
            $robotPart->delete()
        );

        $I->assertTrue(
            $robotPart->robot->delete()
        );

        $I->assertTrue(
            $part->delete()
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: save() after fetching related records
     *
     * @see    https://github.com/phalcon/cphalcon/issues/13964
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-04-26
     */
    public function mvcModelSaveAfterFetchingRelated(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - save() after fetching related');

        /**
         * @var Albums
         */
        $album = Albums::findFirst();

        /**
         * @var Artists
         */
        $artist = $album->artist;

        $I->assertTrue(
            $album->save()
        );

        /**
         * @var Model\Resultset\Simple
         */
        $songs = $album->songs;

        $I->assertTrue(
            $album->save()
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: save() after using related records getters
     *
     * @see    https://github.com/phalcon/cphalcon/issues/13964
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-04-26
     */
    public function mvcModelSaveAfterUsingRelatedGetters(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - save() after using related records getters');

        /**
         * @var Albums
         */
        $album = Albums::findFirst();

        /**
         * @var Artists
         */
        $artist = $album->getArtist();

        $I->assertTrue(
            $album->save()
        );

        /**
         * @var \Model\Resultset\Simple
         */
        $songs = $album->getSongs();

        $I->assertTrue(
            $album->save()
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: save() when default values are not set
     *
     * @see    https://github.com/phalcon/cphalcon/issues/13781
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-05-17
     */
    public function mvcModelSaveAfterWithoutDefaultValues(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - save() when default values are not set');

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
            $robot->save()
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
            $robot->delete()
        );
    }

    public function mvcModelSaveCircularRelation(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model::save() with circular unsaved relations');

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
            $artist->save()
        );

        // Both should have an ID now
        $I->assertNotNull($album->id);
        $I->assertNotNull($artist->id);
    }

    public function mvcModelSaveAfterFetchingRelatedIssue14270(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model::save() after feteching related');

        $part1 = new Parts();
        $part1->name = "Right finger";

        $part2 = new Parts();
        $part2->name = "Right toe";

        $robot = new Robots();
        $robotData = [
            'name'     => 'bob',
            'datetime' => (new \DateTime())->format('Y-m-d'),
            'text'     => 'Test text',
        ];

        $robot->assign($robotData);
        $robot->robotsParts = [$part1, $part2];
        $robot->save();

        $robot = Robots::findFirstByName("bob");

        // Query the parts, for some reason,
        // for example to check if the parts are in the db already...
        $firstParts = $robot->robotsParts;

        $I->assertEquals(
            2,
            count($firstParts)
        );

        $part3 = new Parts();
        $part3->name = "Left finger";

        $part4 = new Parts();
        $part4->name = "Left toe";

        $robot->robotsParts = [$part3, $part4];
        $robot->save();

        $robot = Robots::findFirstByName("bob");

        $allParts = $robot->getRobotsParts();

        $I->assertEquals(
            4,
            count($allParts)
        );
    }
}
