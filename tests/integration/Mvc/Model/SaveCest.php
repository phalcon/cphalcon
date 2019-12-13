<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;
use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\MetaData;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Test\Fixtures\Migrations\SourcesMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\AlbumORama\Albums;
use Phalcon\Test\Models\AlbumORama\Artists;
use Phalcon\Test\Models\Invoices;
use Phalcon\Test\Models\InvoicesSchema;
use Phalcon\Test\Models\Parts;
use Phalcon\Test\Models\Robots;
use Phalcon\Test\Models\RobotsParts;
use Phalcon\Test\Models\Sources;
use Phalcon\Test\Models\TinyIntTest;
use Phalcon\Test\Models\Users;

use function uniqid;

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
     * @author       Phalcon Team <team@phalcon.io>
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

    /**
     * Tests Phalcon\Mvc\Model :: save() with circular unsaved relations
     */
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
        $album->artist  = $artist;
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

    /**
     * Tests Phalcon\Mvc\Model :: save() after fetching related using magic
     * getter
     *
     * @see    https://github.com/phalcon/cphalcon/issues/14270
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-08-02
     */
    public function mvcModelSaveAfterFetchingRelatedWithMagicGetter(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model::save() after fetching related using magic getter');

        $artist = new Artists(
            [
                'name' => 'Mr Robot',
            ]
        );

        $album1 = new Albums(
            [
                'name' => 'Feedback',
            ]
        );
        $album2 = new Albums(
            [
                'name' => 'Syntax Error',
            ]
        );

        // Assign relationship in both directions on unsaved models
        $artist->albums = [$album1, $album2];

        $I->assertTrue(
            $artist->save()
        );

        $artist = Artists::findFirstByName("Mr Robot");

        // Query the parts, for some reason,
        // for example to check if the parts are in the db already...
        $firstAlbums = $artist->albums;

        $I->assertEquals(
            2,
            count($firstAlbums)
        );

        $album3         = new Albums(
            [
                'name' => 'Feedback 2',
            ]
        );
        $album4         = new Albums(
            [
                'name' => 'Syntax Error 2',
            ]
        );
        $artist->albums = [$album3, $album4];
        $artist->save();

        $artist = Artists::findFirstByName("Mr Robot");

        $allAlbums = $artist->getRelated('albums');

        $I->assertEquals(
            4,
            count($allAlbums)
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: save() with a tinyint(1)
     *
     * @see    https://github.com/phalcon/cphalcon/issues/14355
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-08-02
     */
    public function mvcModelSaveWithTinyInt(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model::save() with a tinyint(1)');

        $referenceModel       = new TinyIntTest();
        $referenceModel->test = 0;

        $I->assertTrue(
            $referenceModel->save()
        );
        $id = $referenceModel->id;
        $I->assertNotNull(
            $id
        );

        $storedModel = TinyIntTest::findFirstById($id);
        $I->assertEquals(
            '0',
            $storedModel->test
        );
    }

    /**
     * Tests Phalcon\Mvc\Model\ :: save() with schema
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-11-16
     */
    public function mvcModelSaveWithSchema(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - save() with a schema');

        /**
         * Setup the table
         */
        (new InvoicesMigration())($this->container->get('db'));

        $model = new Invoices();

        $model->inv_cst_id      = 1;
        $model->inv_status_flag = 1;
        $model->inv_title       = uniqid();
        $model->inv_total       = 100;
        $model->inv_created_at  = date('Y-m-d H:i:s');

        $result = $model->save();
        $I->assertNotFalse($result);


        $model = new InvoicesSchema();

        $model->inv_cst_id      = 1;
        $model->inv_status_flag = 1;
        $model->inv_title       = uniqid();
        $model->inv_total       = 100;
        $model->inv_created_at  = date('Y-m-d H:i:s');

        $result = $model->save();
        $I->assertNotFalse($result);
    }

    /**
     * Tests Phalcon\Mvc\Model\ :: save() with property source
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-11-16
     */
    public function mvcModelSaveWithPropertySource(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - save() with property source');

        /**
         * Setup the table
         */
        (new SourcesMigration())($this->container->get('db'));

        $model = Sources::findFirst(
            [
                'conditions' => 'id = :id:',
                'bind'       => [
                    'id' => 1,
                ],
            ]
        );

        $I->assertInstanceOf(Sources::class, $model);
        $I->assertEquals(1, $model->id);
        $I->assertEquals('co_sources', $model->getSource());

        $model->username = 'vader';
        $result          = $model->save();

        $I->assertCount(0, $model->getMessages());
        $I->assertNotFalse($result);
    }
}
