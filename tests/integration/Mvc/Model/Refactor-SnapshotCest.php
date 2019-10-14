<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model;

use DateTime;
use IntegrationTester;
use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Snapshot\Personas;
use Phalcon\Test\Models\Snapshot\Requests;
use Phalcon\Test\Models\Snapshot\Robots;
use Phalcon\Test\Models\Snapshot\Robotters;
use Phalcon\Test\Models\Snapshot\Subscribers;

class SnapshotCest
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
     * Tests dynamic update for identityless models
     *
     * @test
     * @author Phalcon Team <team@phalcon.io>
     * @issue  https://github.com/phalcon/cphalcon/issues/13166
     * @since  2017-11-20
     */
    public function shouldSaveSnapshotForIdentitylessModel(IntegrationTester $I)
    {
        $requests = new Requests();

        $requests->method = 'GET';
        $requests->uri    = '/api/status';
        $requests->count  = 1;

        $I->assertTrue(
            $requests->save()
        );

        $I->assertEquals(
            [],
            $requests->getChangedFields()
        );

        $I->assertNotEmpty(
            $requests->getSnapshotData()
        );

        $I->assertEquals(
            $requests->toArray(),
            $requests->getSnapshotData()
        );

        $I->assertEquals(
            'GET',
            $requests->method
        );
        $I->assertEquals(
            '/api/status',
            $requests->uri
        );
        $I->assertEquals(
            1,
            $requests->count
        );
    }

    /** @test */
    public function shouldWorkWithSimpleResultset(IntegrationTester $I)
    {
        $I->skipTest('TODO = Check test');

        $modelsManager = $this->container->getShared('modelsManager');

        $robots = $modelsManager->executeQuery(
            'SELECT * FROM ' . Robots::class
        );

        /** @var Robots $robot */
        foreach ($robots as $robot) {
            $robot->name = 'Some';
            $robot->year = 1999;

            $I->assertTrue(
                $robot->hasChanged('name')
            );

            $I->assertTrue(
                $robot->hasChanged('year')
            );

            $I->assertFalse(
                $robot->hasChanged('type')
            );

            $I->assertTrue(
                $robot->hasChanged()
            );

            $I->assertEquals(
                [
                    'name',
                    'year',
                ],
                $robot->getChangedFields()
            );
        }

        $robots = $modelsManager->executeQuery(
            'SELECT robot.*, parts.* FROM ' . Robots::class . ' robot JOIN ' . Robots::class . ' parts'
        );

        foreach ($robots as $row) {
            $row->robot->name = 'Some';
            $row->robot->year = 1999;

            $I->assertTrue(
                $row->robot->hasChanged('name')
            );

            $I->assertTrue(
                $row->robot->hasChanged('year')
            );

            $I->assertFalse(
                $row->robot->hasChanged('type')
            );

            $I->assertTrue(
                $row->robot->hasChanged()
            );

            $I->assertEquals(
                [
                    'name',
                    'year',
                ],
                $row->robot->getChangedFields()
            );

            $I->assertTrue(
                $row->parts->hasSnapshotData()
            );
        }
    }

    /** @test */
    public function shouldWorkWithArrayOfModels(IntegrationTester $I)
    {
        $I->skipTest('TODO = Check test');

        $snapshots = [
            1 => [
                'id'       => '1',
                'name'     => 'Robotina',
                'type'     => 'mechanical',
                'year'     => '1972',
                'datetime' => '1972-01-01 00:00:00',
                'deleted'  => null,
                'text'     => 'text',
            ],
            2 => [
                'id'       => '2',
                'name'     => 'Astro Boy',
                'type'     => 'mechanical',
                'year'     => '1952',
                'datetime' => '1952-01-01 00:00:00',
                'deleted'  => null,
                'text'     => 'text',
            ],
            3 => [
                'id'       => '3',
                'name'     => 'Terminator',
                'type'     => 'cyborg',
                'year'     => '2029',
                'datetime' => '2029-01-01 00:00:00',
                'deleted'  => null,
                'text'     => 'text',
            ],
        ];

        foreach (Robots::find(['order' => 'id']) as $robot) {
            $I->assertTrue(
                $robot->hasSnapshotData()
            );

            $I->assertEquals(
                $snapshots[$robot->id],
                $robot->getSnapshotData()
            );
        }

        foreach (Robots::find(['order' => 'id']) as $robot) {
            $robot->name = 'Some';
            $robot->year = 1999;

            $I->assertTrue(
                $robot->hasChanged('name')
            );

            $I->assertTrue(
                $robot->hasChanged('year')
            );

            $I->assertFalse(
                $robot->hasChanged('type')
            );

            $I->assertTrue(
                $robot->hasChanged()
            );
        }

        foreach (Robots::find(['order' => 'id']) as $robot) {
            $robot->year = $robot->year;

            $I->assertFalse(
                $robot->hasChanged('year')
            );

            $I->assertFalse(
                $robot->hasChanged()
            );
        }

        foreach (Robots::find(['order' => 'id']) as $robot) {
            $robot->name = 'Little';
            $robot->year = 2005;

            $I->assertEquals(
                [
                    'name',
                    'year',
                ],
                $robot->getChangedFields()
            );
        }
    }

    /** @test */
    public function shouldWorkWithRenamedFields(IntegrationTester $I)
    {
        $I->skipTest('TODO = Check test');

        $snapshots = [
            1 => [
                'code'        => '1',
                'theName'     => 'Robotina',
                'theType'     => 'mechanical',
                'theYear'     => '1972',
                'theDatetime' => '1972-01-01 00:00:00',
                'theDeleted'  => null,
                'theText'     => 'text',
            ],
            2 => [
                'code'        => '2',
                'theName'     => 'Astro Boy',
                'theType'     => 'mechanical',
                'theYear'     => '1952',
                'theDatetime' => '1952-01-01 00:00:00',
                'theDeleted'  => null,
                'theText'     => 'text',
            ],
            3 => [
                'code'        => '3',
                'theName'     => 'Terminator',
                'theType'     => 'cyborg',
                'theYear'     => '2029',
                'theDatetime' => '2029-01-01 00:00:00',
                'theDeleted'  => null,
                'theText'     => 'text',
            ],
        ];

        foreach (Robotters::find(['order' => 'code']) as $robot) {
            $I->assertTrue(
                $robot->hasSnapshotData()
            );

            $I->assertEquals(
                $robot->getSnapshotData(),
                $snapshots[$robot->code]
            );
        }

        foreach (Robotters::find(['order' => 'code']) as $robot) {
            $robot->theName = 'Some';
            $robot->theYear = 1999;

            $I->assertTrue(
                $robot->hasChanged('theName')
            );

            $I->assertTrue(
                $robot->hasChanged('theYear')
            );

            $I->assertFalse(
                $robot->hasChanged('theType')
            );

            $I->assertTrue(
                $robot->hasChanged()
            );
        }

        foreach (Robotters::find(['order' => 'code']) as $robot) {
            $robot->theYear = $robot->theYear;

            $I->assertFalse(
                $robot->hasChanged('theYear')
            );

            $I->assertFalse(
                $robot->hasChanged()
            );
        }

        foreach (Robotters::find(['order' => 'code']) as $robot) {
            $robot->theName = 'Little';
            $robot->theYear = 2005;

            $I->assertEquals(
                [
                    'theName',
                    'theYear',
                ],
                $robot->getChangedFields()
            );
        }
    }

    /**
     * Test snapshots for changes from NULL to Zero
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/12628
     * @author Phalcon Team <team@phalcon.io>
     * @since  2017-02-26
     */
    public function shouldCorrectDetectChanges(IntegrationTester $I)
    {
        $robots = Robots::findFirst();

        $I->assertEmpty($robots->getChangedFields());
        $I->assertNull($robots->deleted);
        $I->assertFalse($robots->hasChanged('deleted'));

        $robots->deleted = 0;

        $I->assertNotEmpty($robots->getChangedFields());
        $I->assertNotNull($robots->deleted);
        $I->assertTrue($robots->hasChanged('deleted'));
    }

    /**
     * When model is created/updated snapshot should be set/updated
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/11007
     * @issue  https://github.com/phalcon/cphalcon/issues/11818
     * @issue  https://github.com/phalcon/cphalcon/issues/11424
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-03
     */
    public function testIssue11007(IntegrationTester $I)
    {
        $robots = new Robots(
            [
                'name'     => 'test',
                'type'     => 'mechanical',
                'year'     => 2017,
                'datetime' => (new DateTime())->format('Y-m-d'),
                'text'     => 'asd',
            ]
        );

        $I->assertTrue(
            $robots->create()
        );

        $I->assertNotEmpty(
            $robots->getSnapshotData()
        );

        $I->assertEquals(
            $robots->toArray(),
            $robots->getSnapshotData()
        );

        $robots->name = 'testabc';

        $I->assertTrue(
            $robots->hasChanged('name')
        );

        $I->assertTrue(
            $robots->update()
        );

        $I->assertEquals(
            'testabc',
            $robots->name
        );

        $I->assertNotEmpty(
            $robots->getSnapshotData()
        );

        $I->assertEquals(
            $robots->toArray(),
            $robots->getSnapshotData()
        );

        $I->assertFalse(
            $robots->hasChanged('name')
        );
    }

    /**
     * When model is refreshed snapshot should be updated
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/11007
     * @issue  https://github.com/phalcon/cphalcon/issues/11818
     * @issue  https://github.com/phalcon/cphalcon/issues/11424
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-03
     */
    public function testIssue11007Refresh(IntegrationTester $I)
    {
        $robots = new Robots(
            [
                'name'     => 'test',
                'year'     => 2017,
                'datetime' => (new DateTime())->format('Y-m-d'),
                'text'     => 'asd',
            ]
        );

        $I->assertTrue(
            $robots->create()
        );

        $I->assertNotEmpty(
            $robots->getSnapshotData()
        );

        $I->assertEquals(
            $robots->toArray(),
            $robots->getSnapshotData()
        );

        $I->assertInstanceOf(
            Robots::class,
            $robots->refresh()
        );

        $I->assertEquals(
            'mechanical',
            $robots->type
        );

        $I->assertNotEmpty(
            $robots->getSnapshotData()
        );

        $I->assertEquals(
            $robots->toArray(),
            $robots->getSnapshotData()
        );
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-23
     */
    public function testNewInstanceUpdate(IntegrationTester $I)
    {
        $robots = Robots::findFirst();

        $robots = new Robots(
            $robots->toArray()
        );

        $I->assertTrue(
            $robots->save()
        );
    }

    /**
     * Tests get updated fields deleted instance exception
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-28
     */
    public function testUpdatedFieldsDeleteException(IntegrationTester $I)
    {
        $I->expectThrowable(
            new Exception(
                'Change checking cannot be performed because the object has not been persisted or is deleted'
            ),
            function () {
                $robots = new Robots(
                    [
                        'name'     => 'test',
                        'year'     => 2017,
                        'datetime' => (new DateTime())->format('Y-m-d'),
                        'text'     => 'asd',
                    ]
                );

                $robots->create();
                $robots->delete();

                $robots->getUpdatedFields();
            }
        );
    }

    /**
     * Tests get updated fields
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-28
     */
    public function testUpdatedFields(IntegrationTester $I)
    {
        $I->skipTest('TODO = Check test');

        $robots = Robots::findFirst();

        $robots->name = 'changedName';

        $I->assertNotEmpty(
            $robots->getSnapshotData()
        );

        $I->assertTrue(
            $robots->hasChanged('name')
        );

        $I->assertFalse(
            $robots->hasUpdated('name')
        );

        $robots->save();

        $I->assertNotEmpty(
            $robots->getSnapshotData()
        );

        $I->assertFalse(
            $robots->hasChanged('name')
        );

        $I->assertTrue(
            $robots->hasUpdated('name')
        );
    }

    /**
     * Tests get updated fields
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-28
     */
    public function testDisabledSnapshotUpdate(IntegrationTester $I)
    {
        $I->skipTest('TODO = Check test');
        $robots = Robots::findFirst();

        Model::setup(
            [
                'updateSnapshotOnSave' => false,
            ]
        );

        $robots->name = 'changedName';

        $I->assertNotEmpty(
            $robots->getSnapshotData()
        );

        $I->assertTrue(
            $robots->hasChanged('name')
        );

        $robots->save();

        $I->assertNotEmpty(
            $robots->getSnapshotData()
        );

        $I->assertTrue(
            $robots->hasChanged('name')
        );

        Model::setup(
            [
                'updateSnapshotOnSave' => true,
            ]
        );

        $robots->name = 'otherName';

        $robots->save();

        $I->assertNotEmpty(
            $robots->getSnapshotData()
        );

        $I->assertFalse(
            $robots->hasChanged('name')
        );
    }

    /**
     * When model is refreshed snapshot should be updated
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/12669
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-15
     */
    public function testIssue12669(IntegrationTester $I)
    {
        $I->skipTest('TODO = Check test');
        $robots = new Robots(
            [
                'name'     => 'test',
                'year'     => 2017,
                'datetime' => (new DateTime())->format('Y-m-d'),
                'text'     => 'asd',
            ]
        );

        $I->assertTrue(
            $robots->create()
        );

        $robots->name = 'test2';

        $I->assertTrue(
            $robots->hasChanged(
                [
                    'name',
                    'year',
                ]
            )
        );

        $I->assertTrue(
            $robots->hasChanged(
                [
                    'text',
                    'year',
                ]
            )
        );

        $I->assertFalse(
            $robots->hasChanged(
                [
                    'name',
                    'year',
                ],
                true
            )
        );

        $robots->year = 2018;

        $I->assertTrue(
            $robots->hasChanged(
                [
                    'name',
                    'year',
                ],
                true
            )
        );
    }

    /**
     * When model is refreshed snapshot should be updated
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/13173
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-12-05
     */
    public function testIssue13173(IntegrationTester $I)
    {
        $subscriber = new Subscribers();

        $subscriber->email  = 'some@some.com';
        $subscriber->status = 'I';

        $I->assertTrue(
            $subscriber->save()
        );

        $I->assertEquals(
            [
                'email',
                'created_at',
                'status',
                'id',
            ],
            $subscriber->getUpdatedFields()
        );

        $I->assertTrue(
            $subscriber->delete()
        );

        $I->assertEquals(
            [
                'status',
            ],
            $subscriber->getUpdatedFields()
        );
    }

    public function testIssue13202(IntegrationTester $I)
    {
        $personas = Personas::findFirst();

        $I->assertEquals(
            [],
            $personas->getChangedFields()
        );

        try {
            $personas->getUpdatedFields();
        } catch (\Exception $e) {
            $I->assertEquals(
                'Change checking cannot be performed because the object has not been persisted or is deleted',
                $e->getMessage()
            );
        }

        $I->assertTrue(
            $personas->save()
        );

        $I->assertEquals(
            [],
            $personas->getUpdatedFields()
        );
    }
}
