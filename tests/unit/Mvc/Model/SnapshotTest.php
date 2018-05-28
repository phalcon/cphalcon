<?php

namespace Phalcon\Test\Unit\Mvc\Model;

use Helper\ModelTrait;
use Phalcon\Mvc\Model;
use Phalcon\Test\Models\Snapshot\Personas;
use Phalcon\Test\Models\Snapshot\Subscribers;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Test\Models\Snapshot\Robots;
use Phalcon\Test\Models\Snapshot\Requests;
use Phalcon\Test\Models\Snapshot\Robotters;

/**
 * \Phalcon\Test\Unit\Mvc\Model\SnapshotTest
 * Tests the Phalcon\Mvc\Model component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Unit\Mvc\Model
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class SnapshotTest extends UnitTest
{
    use ModelTrait;

    /**
     * Tests dynamic update for identityless models
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @issue  https://github.com/phalcon/cphalcon/issues/13166
     * @since  2017-11-20
     */
    public function shouldSaveSnapshotForIdentitylessModel()
    {
        $this->specify(
            "Snapshot does not work with identityless models on Creation/Save",
            function () {
                $requests = new Requests();

                $requests->method = 'GET';
                $requests->uri = '/api/status';
                $requests->count = 1;

                expect($requests->save())->true();
                expect($requests->getChangedFields())->equals([]);
                expect($requests->getSnapshotData())->notEmpty();
                expect($requests->getSnapshotData())->equals($requests->toArray());

                expect($requests->method)->equals('GET');
                expect($requests->uri)->equals('/api/status');
                expect($requests->count)->equals(1);
            }
        );
    }

    /** @test */
    public function shouldWorkWithSimpleResultset()
    {
        $this->specify(
            "Snapshot does not work with Simple Resultset as expected",
            function () {
                $modelsManager = $this->setUpModelsManager();
                $robots = $modelsManager->executeQuery('SELECT * FROM ' . Robots::class);

                /** @var Robots $robot */
                foreach ($robots as $robot) {
                    $robot->name = 'Some';
                    $robot->year = 1999;
                    expect($robot->hasChanged('name'))->true();
                    expect($robot->hasChanged('year'))->true();
                    expect($robot->hasChanged('type'))->false();
                    expect($robot->hasChanged())->true();
                    expect($robot->getChangedFields())->equals(['name', 'year']);
                }

                $robots = $modelsManager->executeQuery(
                    'SELECT robot.*, parts.* FROM ' . Robots::class . ' robot JOIN ' . Robots::class . ' parts'
                );

                foreach ($robots as $row) {
                    $row->robot->name = 'Some';
                    $row->robot->year = 1999;

                    expect($row->robot->hasChanged('name'))->true();
                    expect($row->robot->hasChanged('year'))->true();
                    expect($row->robot->hasChanged('type'))->false();
                    expect($row->robot->hasChanged())->true();
                    expect($row->robot->getChangedFields())->equals(['name', 'year']);

                    $this->assertTrue($row->parts->hasSnapshotData());
                }
            }
        );
    }

    /** @test */
    public function shouldWorkWithArrayOfModels()
    {
        $this->specify(
            "Normal snapshots don't work",
            function () {
                $snapshots = [
                    1 => [
                        'id' => '1',
                        'name' => 'Robotina',
                        'type' => 'mechanical',
                        'year' => '1972',
                        'datetime' => '1972-01-01 00:00:00',
                        'deleted' => null,
                        'text' => 'text'
                    ],
                    2 => [
                        'id' => '2',
                        'name' => 'Astro Boy',
                        'type' => 'mechanical',
                        'year' => '1952',
                        'datetime' => '1952-01-01 00:00:00',
                        'deleted' => null,
                        'text' => 'text'
                    ],
                    3 => [
                        'id' => '3',
                        'name' => 'Terminator',
                        'type' => 'cyborg',
                        'year' => '2029',
                        'datetime' => '2029-01-01 00:00:00',
                        'deleted' => null,
                        'text' => 'text'
                    ]
                ];

                foreach (Robots::find(['order' => 'id']) as $robot) {
                    expect($robot->hasSnapshotData())->true();
                    expect($snapshots[$robot->id])->equals($robot->getSnapshotData());
                }

                foreach (Robots::find(['order' => 'id']) as $robot) {
                    $robot->name = 'Some';
                    $robot->year = 1999;
                    expect($robot->hasChanged('name'))->true();
                    expect($robot->hasChanged('year'))->true();
                    expect($robot->hasChanged('type'))->false();
                    expect($robot->hasChanged())->true();
                }

                foreach (Robots::find(['order' => 'id']) as $robot) {
                    $robot->year = $robot->year;
                    expect($robot->hasChanged('year'))->false();
                    expect($robot->hasChanged())->false();
                }

                foreach (Robots::find(['order' => 'id']) as $robot) {
                    $robot->name = 'Little';
                    $robot->year = 2005;
                    expect($robot->getChangedFields())->equals(['name', 'year']);
                }
            }
        );
    }

    /** @test */
    public function shouldWorkWithRenamedFileds()
    {
        $this->specify(
            "Renamed snapshots don't work",
            function () {
                $snapshots = [
                    1 => [
                        'code' => '1',
                        'theName' => 'Robotina',
                        'theType' => 'mechanical',
                        'theYear' => '1972',
                        'theDatetime' => '1972-01-01 00:00:00',
                        'theDeleted' => null,
                        'theText' => 'text',
                    ],
                    2 => [
                        'code' => '2',
                        'theName' => 'Astro Boy',
                        'theType' => 'mechanical',
                        'theYear' => '1952',
                        'theDatetime' => '1952-01-01 00:00:00',
                        'theDeleted' => null,
                        'theText' => 'text',
                    ],
                    3 => [
                        'code' => '3',
                        'theName' => 'Terminator',
                        'theType' => 'cyborg',
                        'theYear' => '2029',
                        'theDatetime' => '2029-01-01 00:00:00',
                        'theDeleted' => null,
                        'theText' => 'text',
                    ]
                ];

                foreach (Robotters::find(['order' => 'code']) as $robot) {
                    expect($robot->hasSnapshotData())->true();
                    expect($snapshots[$robot->code])->equals($robot->getSnapshotData());
                }

                foreach (Robotters::find(['order' => 'code']) as $robot) {
                    $robot->theName = 'Some';
                    $robot->theYear = 1999;
                    expect($robot->hasChanged('theName'))->true();
                    expect($robot->hasChanged('theYear'))->true();
                    expect($robot->hasChanged('theType'))->false();
                    expect($robot->hasChanged())->true();
                }

                foreach (Robotters::find(['order' => 'code']) as $robot) {
                    $robot->theYear = $robot->theYear;
                    expect($robot->hasChanged('theYear'))->false();
                    expect($robot->hasChanged())->false();
                }

                foreach (Robotters::find(['order' => 'code']) as $robot) {
                    $robot->theName = 'Little';
                    $robot->theYear = 2005;
                    expect($robot->getChangedFields())->equals(['theName', 'theYear']);
                }
            }
        );
    }

    /**
     * Test snapshots for changes from NULL to Zero
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/12628
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function shouldCorrectDetectChanges()
    {
        $this->specify(
            "Snapshot does not work correctly with changed fields",
            function () {
                $this->setUpModelsManager();
                $robots = Robots::findFirst();

                expect($robots->getChangedFields())->isEmpty();
                expect($robots->deleted)->null();
                expect($robots->hasChanged('deleted'))->false();

                $robots->deleted = 0;

                expect($robots->getChangedFields())->notEmpty();
                expect($robots->deleted)->notNull();
                expect($robots->hasChanged('deleted'))->true();
            }
        );
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
    public function testIssue11007()
    {
        $this->specify(
            'Snapshot is not created/updated when create/update operation was made',
            function () {
                $this->setUpModelsManager();
                $robots = new Robots(
                    [
                        'name'     => 'test',
                        'type'     => 'mechanical',
                        'year'     => 2017,
                        'datetime' => (new \DateTime())->format('Y-m-d'),
                        'text'     => 'asd',
                    ]
                );

                expect($robots->create())->true();
                expect($robots->getSnapshotData())->notEmpty();
                expect($robots->getSnapshotData())->equals($robots->toArray());

                $robots->name = "testabc";
                expect($robots->hasChanged('name'))->true();
                expect($robots->update())->true();
                expect($robots->name)->equals("testabc");
                expect($robots->getSnapshotData())->notEmpty();
                expect($robots->getSnapshotData())->equals($robots->toArray());
                expect($robots->hasChanged('name'))->false();
            }
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
    public function testIssue11007Refresh()
    {
        $this->specify(
            'Snapshot is not updated when refresh operation was made',
            function () {
                $this->setUpModelsManager();
                $robots = new Robots(
                    [
                        'name'     => 'test',
                        'year'     => 2017,
                        'datetime' => (new \DateTime())->format('Y-m-d'),
                        'text'     => 'asd',
                    ]
                );

                expect($robots->create())->true();
                expect($robots->getSnapshotData())->notEmpty();
                expect($robots->getSnapshotData())->equals($robots->toArray());

                expect($robots->refresh())->isInstanceOf(Robots::class);
                expect($robots->type)->equals('mechanical');
                expect($robots->getSnapshotData())->notEmpty();
                expect($robots->getSnapshotData())->equals($robots->toArray());
            }
        );
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-23
     */
    public function testNewInstanceUpdate()
    {
        $this->specify(
            'When updating model from new instance there is some problem',
            function () {
                $this->setUpModelsManager();
                $robots = Robots::findFirst();
                $robots = new Robots($robots->toArray());
                expect($robots->save())->true();
            }
        );
    }

    /**
     * Tests get updated fields new instance exception
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-28
     */
    public function testUpdatedFieldsNewException()
    {
        $this->specify(
            'When getting updated fields from not persistent instance there should be exception',
            function () {
                $robots = new Robots(
                    [
                        'name'     => 'test',
                        'year'     => 2017,
                        'datetime' => (new \DateTime())->format('Y-m-d'),
                        'text'     => 'asd',
                    ]
                );

                $robots->getUpdatedFields();
            },
            [
                'throws' => ['Phalcon\Mvc\Model\Exception', 'The record doesn\'t have a valid data snapshot'],
            ]
        );
    }

    /**
     * Tests get updated fields deleted instance exception
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-28
     */
    public function testUpdatedFieldsDeleteException()
    {
        $this->specify(
            'When getting updated fields from deleted instance there should be exception',
            function () {
                $robots = new Robots(
                    [
                        'name' => 'test',
                        'year' => 2017,
                        'datetime' => (new \DateTime())->format('Y-m-d'),
                        'text' => 'asd',
                    ]
                );

                $robots->create();
                $robots->delete();

                $robots->getUpdatedFields();
            },
            [
                'throws' => [
                    'Phalcon\Mvc\Model\Exception',
                    'Change checking cannot be performed because the object has not been persisted or is deleted',
                ],
            ]
        );
    }

    /**
     * Tests get updated fields
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-28
     */
    public function testUpdatedFields()
    {
        $this->specify(
            'Getting updated fields is not working correctly',
            function () {
                $robots = Robots::findFirst();
                $robots->name = 'changedName';
                expect($robots->getSnapshotData())->notEmpty();
                expect($robots->hasChanged('name'))->true();
                expect($robots->hasUpdated('name'))->false();
                $robots->save();
                expect($robots->getSnapshotData())->notEmpty();
                expect($robots->hasChanged('name'))->false();
                expect($robots->hasUpdated('name'))->true();
            }
        );
    }

    /**
     * Tests get updated fields
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-28
     */
    public function testDisabledSnapshotUpdate()
    {
        $this->specify(
            'Disabling snapshot update is not working',
            function () {
                $robots = Robots::findFirst();
                Model::setup(
                    [
                        'updateSnapshotOnSave' => false,
                    ]
                );
                $robots->name = 'changedName';
                expect($robots->getSnapshotData())->notEmpty();
                expect($robots->hasChanged('name'))->true();
                $robots->save();
                expect($robots->getSnapshotData())->notEmpty();
                expect($robots->hasChanged('name'))->true();
                Model::setup(
                    [
                        'updateSnapshotOnSave' => true,
                    ]
                );
                $robots->name = 'otherName';
                $robots->save();
                expect($robots->getSnapshotData())->notEmpty();
                expect($robots->hasChanged('name'))->false();
            }
        );
    }

    /**
     * When model is refreshed snapshot should be updated
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/12669
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-15
     */
    public function testIssue12669()
    {
        $this->specify(
            'hasChanged method for array argument is not working correctly',
            function () {
                $this->setUpModelsManager();
                $robots = new Robots(
                    [
                        'name'     => 'test',
                        'year'     => 2017,
                        'datetime' => (new \DateTime())->format('Y-m-d'),
                        'text'     => 'asd',
                    ]
                );

                expect($robots->create())->true();
                $robots->name = 'test2';
                expect($robots->hasChanged(['name', 'year']))->equals(true);
                expect($robots->hasChanged(['text', 'year']))->equals(false);
                expect($robots->hasChanged(['name', 'year'], true))->equals(false);
                $robots->year = 2018;
                expect($robots->hasChanged(['name', 'year'], true))->equals(true);
            }
        );
    }

    /**
     * When model is refreshed snapshot should be updated
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/13173
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-12-05
     */
    public function testIssue13173()
    {
        $this->specify(
            'getUpdatesFields method is not working correctly with SoftDelete behavior',
            function () {
                $this->setUpModelsManager();
                $subscriber = new Subscribers();
                $subscriber->email = 'some@some.com';
                $subscriber->status = 'I';

                expect($subscriber->save())->true();
                expect($subscriber->getUpdatedFields())->equals(['email', 'created_at', 'status', 'id']);
                expect($subscriber->delete())->true();
                expect($subscriber->getUpdatedFields())->equals(['status']);
            }
        );
    }

    public function testIssue13202()
    {
        $this->specify(
            "When using dynamic update saving model without changes getUpdatedFields shouldn't return full array",
            function () {
                $this->setUpModelsManager();
                $personas = Personas::findFirst();
                expect($personas->getChangedFields())->equals([]);
                try {
                    $personas->getUpdatedFields();
                } catch (\Exception $e) {
                    expect($e->getMessage())->equals(
                        "Change checking cannot be performed because the object has not been persisted or is deleted"
                    );
                }
                expect($personas->save())->true();
                expect($personas->getUpdatedFields())->equals([]);
            }
        );
    }
}
