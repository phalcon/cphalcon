<?php

namespace Phalcon\Test\Unit\Mvc;

use Phalcon\Test\Models\Users;
use Phalcon\Cache\Backend\Apc;
use Phalcon\Test\Models\Robots;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Cache\Frontend\Data;
use Phalcon\Test\Models\Boutique;
use Phalcon\Test\Models\Packages;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Test\Models\Robotters;
use Phalcon\Test\Models\Customers;
use Phalcon\Test\Models\PackageDetails;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Test\Models\BodyParts\Body;
use Phalcon\Test\Models\AlbumORama\Albums;
use Phalcon\Test\Models\Snapshot\Robots as SnapshotRobots;
use Phalcon\Test\Models\Snapshot\Robotters as SnapshotRobotters;
use Phalcon\Test\Models\Snapshot\RobotsParts as SnapshotRobotsParts;

/**
 * \Phalcon\Test\Unit\Mvc\ModelTest
 * Tests the Phalcon\Mvc\Model component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Unit\Mvc
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ModelTest extends UnitTest
{
    /**
     * @var \Phalcon\Mvc\Model\Manager
     */
    private $modelsManager;

    protected function _before()
    {
        parent::_before();
        /** @var \Phalcon\Mvc\Application $app */
        $app = $this->tester->getApplication();
        $this->modelsManager = $app->getDI()->getShared('modelsManager');
    }

    public function testCamelCaseRelation()
    {
        $this->specify(
            "CamelCase relation calls should be the same cache",
            function () {
                $this->modelsManager->registerNamespaceAlias('AlbumORama', 'Phalcon\Test\Models\AlbumORama');
                $album = Albums::findFirst();

                $album->artist->name = 'NotArtist';
                expect($album->artist->name)->equals($album->Artist->name);
            }
        );
    }

    /**
     * Tests find with empty conditions + bind and limit.
     *
     * @issue  11919
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-07-29
     */
    public function testEmptyConditions()
    {
        if (!ini_get('opcache.enable_cli')) {
            $this->markTestSkipped(
                'Warning: opcache.enable_cli must be set to "On"'
            );
        }

        $this->specify(
            'The Model::find with empty conditions + bind and limit return wrong result',
            function () {
                $album = Albums::find([
                    'conditions' => '',
                    'bind'       => [],
                    'limit'      => 10
                ]);

                expect($album)->isInstanceOf(Simple::class);
                expect($album->getFirst())->isInstanceOf(Albums::class);
                expect($album->getFirst()->toArray())->equals([
                    'id' => 1,
                    'artists_id' => 1,
                    'name' => 'Born to Die',
                ]);
            }
        );
    }

    /**
     * Tests Model::hasMany by using multi relation column
     *
     * @issue  12035
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-08-02
     */
    public function testMultiRelationColumn()
    {
        $this->specify(
            'The Model::hasMany by using multi relation column does not work as expected',
            function () {
                $list = Packages::find();
                foreach ($list as $item) {
                    expect($item)->isInstanceOf(Packages::class);
                    expect($item->details)->isInstanceOf(Simple::class);
                    expect($item->details->valid())->true();
                    expect($item->details->count())->greaterOrEquals(2);
                    expect($item->details->getFirst())->isInstanceOf(PackageDetails::class);
                }
            }
        );
    }

    /**
     * Tests reusing Model relation
     *
     * @issue  11991
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-08-03
     */
    public function testReusableRelation()
    {
        $this->specify(
            'Reusing relations does not work correctly',
            function () {
                $customers = Customers::find([
                    'document_id = :did: AND status = :status: AND customer_id <> :did:',
                    'bind' => ['did' => 1, 'status' => 'A']
                ]);

                expect($customers)->isInstanceOf(Simple::class);
                expect(count($customers))->equals(2);

                expect($customers[0]->user)->isInstanceOf(Users::class);
                expect($customers[0]->user)->isInstanceOf(Users::class);
                expect($customers[0]->user)->isInstanceOf(Users::class);

                expect($customers[1]->user)->isInstanceOf(Users::class);
                expect($customers[1]->user)->isInstanceOf(Users::class);
                expect($customers[1]->user)->isInstanceOf(Users::class);

                expect($customers->getFirst())->isInstanceOf(Customers::class);

                expect($customers[1]->user->name)->equals('Nikolaos Dimopoulos');
                expect($customers[1]->user->name)->equals('Nikolaos Dimopoulos');
                expect($customers[1]->user->name)->equals('Nikolaos Dimopoulos');

                expect($customers->getFirst()->user->name)->equals('Nikolaos Dimopoulos');
                expect($customers->getFirst()->user->name)->equals('Nikolaos Dimopoulos');
                expect($customers->getFirst()->user->name)->equals('Nikolaos Dimopoulos');

                expect($customers[0]->user->name)->equals('Nikolaos Dimopoulos');
                expect($customers[0]->user->name)->equals('Nikolaos Dimopoulos');
                expect($customers[0]->user->name)->equals('Nikolaos Dimopoulos');
            }
        );
    }

    /**
     * Tests virtual foreign keys.
     *
     * When having multiple virtual foreign keys, check of the first one should
     * affect the check of the next one.
     *
     * @issue  12071
     * @author Radek Crlik <radekcrlik@gmail.com>
     * @since  2016-08-03
    */
    public function testInvalidVirtualForeignKeys()
    {
        $this->specify(
            'The Model::save with multiple virtual foreign keys and invalid entity',
            function () {
                $body = new Body();

                $body->head_1_id = null;
                $body->head_2_id = 999;

                // PDOException should'n be thrown
                expect($body->save())->equals(false);

                expect($body->getMessages())->count(1);
                expect($body->getMessages()[0]->getMessage())->equals('Second head does not exists');
            }
        );
    }

    /**
     * Tests serializing model while using cache and keeping snapshots
     *
     * The snapshot should be saved while using cache
     *
     * @issue  12170, 12000
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-08-26
     */
    public function testSerializeSnapshotCache()
    {
        if (!extension_loaded('apc')) {
            $this->markTestSkipped(
                'Warning: apc extension is not loaded'
            );
        }

        if (!ini_get('apc.enabled') || (PHP_SAPI === 'cli' && !ini_get('apc.enable_cli'))) {
            $this->markTestSkipped(
                'Warning: apc.enable_cli must be set to "On"'
            );
        }

        if (extension_loaded('apcu') && version_compare(phpversion('apcu'), '5.1.6', '=')) {
            throw new \PHPUnit_Framework_SkippedTestError(
                'Warning: APCu v5.1.6 was broken. See: https://github.com/krakjoe/apcu/issues/203'
            );
        }

        $this->specify(
            'Snapshot data should be saved while saving model to cache',
            function () {
                $cache = new Apc(new Data(['lifetime' => 20]));
                $robot = Robots::findFirst();
                expect($robot)->isInstanceOf(Robots::class);
                expect($robot->getSnapshotData())->notEmpty();
                $cache->save('robot', $robot);
                /** @var Robots $robot */
                $robot = $cache->get('robot');
                expect($robot)->isInstanceOf(Robots::class);
                expect($robot->getSnapshotData())->notEmpty();
                expect($robot->getSnapshotData())->equals($robot->toArray());
                $robot->text = 'abc';
                $cache->save('robot', $robot);
                /** @var Robots $robot */
                $robot = $cache->get('robot');
                expect($robot)->isInstanceOf(Robots::class);
                expect($robot->getSnapshotData())->notEmpty();
                expect($robot->getSnapshotData())->notEquals($robot->toArray());
            }
        );
    }

    public function testGettersAndSetters()
    {
        $this->specify(
            "Model getters and setters don't work",
            function () {
                $robot = Boutique\Robots::findFirst();

                $testText = "executeSetGet Test";
                $robot->assign(["text" => $testText]);

                expect($robot->text)->equals($testText . $robot::SETTER_EPILOGUE);
                expect($robot->text)->equals($robot->getText());

                $testText = "executeSetGet Test 2";
                $robot->text = $testText;

                expect($robot->text)->equals($testText . $robot::SETTER_EPILOGUE);
                expect($robot->text)->equals($robot->getText());

                $robot = new Boutique\Robots();
                $robot->serial = '1234';
            },
            [
                'throws' => [
                    Exception::class,
                    "Property 'serial' does not have a setter."
                ]
            ]
        );
    }

    public function testSerialize()
    {
        $this->specify(
            "Models aren't serialized or unserialized properly",
            function () {
                $robot = Robots::findFirst();

                $serialized = serialize($robot);
                $robot = unserialize($serialized);

                expect($robot->save())->true();
            }
        );
    }

    public function testJsonSerialize()
    {
        $this->specify(
            "Single models aren't JSON serialized or JSON unserialized properly",
            function () {
                // Single model object json serialization
                $robot = Robots::findFirst();
                $json = json_encode($robot);

                expect(is_string($json))->true();
                expect(strlen($json) > 10)->true(); // make sure result is not "{ }"
                expect($robot->toArray())->equals(json_decode($json, true));
            }
        );

        $this->specify(
            "Model resultsets aren't JSON serialized or JSON unserialized properly",
            function () {
                // Result-set serialization
                $robots = Robots::find();

                $json = json_encode($robots);

                expect(is_string($json))->true();
                expect(strlen($json) > 50)->true(); // make sure result is not "{ }"
                expect($robots->toArray())->equals(json_decode($json, true));
            }
        );

        $this->specify(
            "Single row resultsets aren't JSON serialized or JSON unserialized properly",
            function () {
                $robot = Robots::findFirst();

                // Single row serialization
                $result = $this->modelsManager->executeQuery(
                    "SELECT id FROM " . Robots::class . " LIMIT 1"
                );

                expect($result)->isInstanceOf('Phalcon\Mvc\Model\Resultset\Simple');

                foreach ($result as $row) {
                    expect($row)->isInstanceOf('Phalcon\Mvc\Model\Row');
                    expect($row->id)->equals($robot->id);

                    $json = json_encode($row);

                    expect(is_string($json))->true();
                    expect(strlen($json) > 5)->true(); // make sure result is not "{ }"
                    expect($row->toArray())->equals(json_decode($json, true));
                }
            }
        );
    }

    public function testMassAssignmentNormal()
    {
        $this->specify(
            "Models can't properly assign properties",
            function () {
                $robot = new Robots();

                $success = $robot->save(
                    [
                        "type" => "mechanical",
                        "year" => 2018,
                    ]
                );

                expect($success)->false();
                expect($robot->type)->equals("mechanical");
                expect($robot->year)->equals(2018);

                $robot = new Robots();

                $robot->assign(
                    [
                        "type" => "mechanical",
                        "year" => 2018,
                    ]
                );

                expect($robot->type)->equals("mechanical");
                expect($robot->year)->equals(2018);

                // not assigns nonexistent fields
                $robot = new Robots();

                $robot->assign(
                    [
                        "field1" => "mechanical",
                        "field2" => 2018,
                    ]
                );

                expect(empty($robot->field1))->true();
                expect(empty($robot->field2))->true();

                // white list
                $robot = new Robots();

                $robot->assign(
                    [
                        "type" => "mechanical",
                        "year" => 2018,
                    ],
                    null,
                    ["type"]
                );

                expect($robot->type)->equals("mechanical");
                expect(empty($robot->year))->true();

                // white list
                $robot = new Robots();

                $robot->assign(
                    [
                        "typeFromClient" => "mechanical",
                        "yearFromClient" => 2018,
                    ],
                    [
                        "typeFromClient" => "type",
                        "yearFromClient" => "year",
                    ],
                    ["type"]
                );

                expect($robot->type)->equals("mechanical");
                expect(empty($robot->year))->true();
            }
        );
    }

    public function testMassAssignmentRenamed()
    {
        $this->specify(
            "Models can't properly assign properties using a column map",
            function () {
                $robot = new Robotters();

                $success = $robot->save(
                    [
                        "theType" => "mechanical",
                        "theYear" => 2018,
                    ]
                );

                expect($success)->false();
                expect($robot->theType)->equals("mechanical");
                expect($robot->theYear)->equals(2018);

                // assign uses column renaming
                $robot = new Robotters();

                $robot->assign(
                    [
                        "theType" => "mechanical",
                        "theYear" => 2018,
                    ]
                );

                expect($robot->theType)->equals("mechanical");
                expect($robot->theYear)->equals(2018);

                // not assigns nonexistent fields
                $robot = new Robotters();

                $robot->assign(
                    [
                        "field1" => "mechanical",
                        "field2" => 2018,
                    ]
                );

                expect(empty($robot->field1))->true();
                expect(empty($robot->field2))->true();

                // white list
                $robot = new Robotters();
                $robot->assign(
                    [
                        "theType" => "mechanical",
                        "theYear" => 2018
                    ],
                    null,
                    ["theType"]
                );

                expect($robot->theType)->equals("mechanical");
                expect(empty($robot->theYear))->true();

                // white list & custom mapping
                $robot = new Robotters();

                $robot->assign(
                    [
                        "theTypeFromClient" => "mechanical",
                        "theYearFromClient" => 2018
                    ],
                    [
                        "theTypeFromClient" => "theType",
                        "theYearFromClient" => "theYear",
                    ],
                    ["theType"]
                );

                expect($robot->theType)->equals("mechanical");
                expect(empty($robot->theYear))->true();
            }
        );
    }

    public function testFindersNormal()
    {
        $this->specify(
            "Models can't be found properly",
            function () {
                $robot = Robots::findFirstById(1);
                expect($robot)->isInstanceOf(Robots::class);
                expect($robot->id)->equals(1);

                $robot = Robots::findFirstById(2);
                expect($robot)->isInstanceOf(Robots::class);
                expect($robot->id)->equals(2);

                $robots = Robots::findByType('mechanical');
                expect($robots)->count(2);
                expect($robots[0]->id)->equals(1);
                expect(Robots::countByType('mechanical'))->equals(2);
            }
        );
    }

    public function testFindersRenamed()
    {
        $this->specify(
            "Models can't be found properly when using a column map",
            function () {
                $robot = Robotters::findFirstByCode(1);
                expect($robot)->isInstanceOf(Robotters::class);
                expect($robot->code)->equals(1);

                $robot = Robotters::findFirstByCode(2);
                expect($robot)->isInstanceOf(Robotters::class);
                expect($robot->code)->equals(2);

                $robots = Robotters::findByTheType('mechanical');
                expect($robots)->count(2);
                expect($robots[0]->code)->equals(1);
                expect(Robotters::countByTheType('mechanical'))->equals(2);
            }
        );
    }

    public function testBehaviorsTimestampable()
    {
        $this->specify(
            "Timestampable model behavior doesn't work",
            function () {
                $subscriber = new \Phalcon\Test\Models\News\Subscribers();

                $subscriber->email = 'some@some.com';
                $subscriber->status = 'I';

                expect($subscriber->save())->true();
                expect(preg_match('/[0-9]{4}-[0-9]{2}-[0-9]{2}/', $subscriber->created_at))->equals(1);
            }
        );
    }

    public function testBehaviorsSoftDelete()
    {
        $this->specify(
            "Soft Delete model behavior doesn't work",
            function () {
                $number = \Phalcon\Test\Models\News\Subscribers::count();

                $subscriber = \Phalcon\Test\Models\News\Subscribers::findFirst();

                expect($subscriber->delete())->true();
                expect($subscriber->status)->equals('D');
                expect(\Phalcon\Test\Models\News\Subscribers::count())->equals($number);
            }
        );
    }

    public function testSnapshotNormal()
    {
        $this->specify(
            "Normal snapshots don't work",
            function () {
                $snapshots = array(
                    1 => array(
                        'id' => '1',
                        'name' => 'Robotina',
                        'type' => 'mechanical',
                        'year' => '1972',
                        'datetime' => '1972-01-01 00:00:00',
                        'deleted' => null,
                        'text' => 'text'
                    ),
                    2 => array(
                        'id' => '2',
                        'name' => 'Astro Boy',
                        'type' => 'mechanical',
                        'year' => '1952',
                        'datetime' => '1952-01-01 00:00:00',
                        'deleted' => null,
                        'text' => 'text'
                    ),
                    3 => array(
                        'id' => '3',
                        'name' => 'Terminator',
                        'type' => 'cyborg',
                        'year' => '2029',
                        'datetime' => '2029-01-01 00:00:00',
                        'deleted' => null,
                        'text' => 'text'
                    )
                );

                foreach (SnapshotRobots::find(array('order' => 'id')) as $robot) {
                    expect($robot->hasSnapshotData())->true();
                    expect($snapshots[$robot->id])->equals($robot->getSnapshotData());
                }

                foreach (SnapshotRobots::find(array('order' => 'id')) as $robot) {
                    $robot->name = 'Some';
                    $robot->year = 1999;
                    expect($robot->hasChanged('name'))->true();
                    expect($robot->hasChanged('year'))->true();
                    expect($robot->hasChanged('type'))->false();
                    expect($robot->hasChanged())->true();
                }

                foreach (SnapshotRobots::find(array('order' => 'id')) as $robot) {
                    $robot->year = $robot->year;
                    expect($robot->hasChanged('year'))->false();
                    expect($robot->hasChanged())->false();
                }

                foreach (SnapshotRobots::find(array('order' => 'id')) as $robot) {
                    $robot->name = 'Little';
                    $robot->year = 2005;
                    expect($robot->getChangedFields())->equals(array('name', 'year'));
                }
            }
        );
    }

    public function testSnapshotRenamed()
    {
        $this->specify(
            "Renamed snapshots don't work",
            function () {
                $snapshots = array(
                    1 => array(
                        'code' => '1',
                        'theName' => 'Robotina',
                        'theType' => 'mechanical',
                        'theYear' => '1972',
                        'theDatetime' => '1972-01-01 00:00:00',
                        'theDeleted' => null,
                        'theText' => 'text',
                    ),
                    2 => array(
                        'code' => '2',
                        'theName' => 'Astro Boy',
                        'theType' => 'mechanical',
                        'theYear' => '1952',
                        'theDatetime' => '1952-01-01 00:00:00',
                        'theDeleted' => null,
                        'theText' => 'text',
                    ),
                    3 => array(
                        'code' => '3',
                        'theName' => 'Terminator',
                        'theType' => 'cyborg',
                        'theYear' => '2029',
                        'theDatetime' => '2029-01-01 00:00:00',
                        'theDeleted' => null,
                        'theText' => 'text',
                    )
                );

                foreach (SnapshotRobotters::find(array('order' => 'code')) as $robot) {
                    expect($robot->hasSnapshotData())->true();
                    expect($snapshots[$robot->code])->equals($robot->getSnapshotData());
                }

                foreach (SnapshotRobotters::find(array('order' => 'code')) as $robot) {
                    $robot->theName = 'Some';
                    $robot->theYear = 1999;
                    expect($robot->hasChanged('theName'))->true();
                    expect($robot->hasChanged('theYear'))->true();
                    expect($robot->hasChanged('theType'))->false();
                    expect($robot->hasChanged())->true();
                }

                foreach (SnapshotRobotters::find(array('order' => 'code')) as $robot) {
                    $robot->theYear = $robot->theYear;
                    expect($robot->hasChanged('theYear'))->false();
                    expect($robot->hasChanged())->false();
                }

                foreach (SnapshotRobotters::find(array('order' => 'code')) as $robot) {
                    $robot->theName = 'Little';
                    $robot->theYear = 2005;
                    expect($robot->getChangedFields())->equals(array('theName', 'theYear'));
                }
            }
        );
    }

    public function testSnapshotNormalComplex()
    {
        $this->specify(
            "Normal complex snapshots don't work",
            function () {
                $robots = $this->modelsManager->executeQuery(
                    'SELECT * FROM ' . SnapshotRobots::class
                );

                foreach ($robots as $robot) {
                    $robot->name = 'Some';
                    $robot->year = 1999;
                    expect($robot->hasChanged('name'))->true();
                    expect($robot->hasChanged('year'))->true();
                    expect($robot->hasChanged('type'))->false();
                    expect($robot->hasChanged())->true();
                    expect($robot->getChangedFields())->equals(array('name', 'year'));
                }



                $robots = $this->modelsManager->executeQuery(
                    'SELECT robot.*, parts.* FROM ' . SnapshotRobots::class . ' robot JOIN ' . SnapshotRobotsParts::class . ' parts'
                );

                foreach ($robots as $row) {
                    $row->robot->name = 'Some';
                    $row->robot->year = 1999;

                    expect($row->robot->hasChanged('name'))->true();
                    expect($row->robot->hasChanged('year'))->true();
                    expect($row->robot->hasChanged('type'))->false();
                    expect($row->robot->hasChanged())->true();
                    expect($row->robot->getChangedFields())->equals(array('name', 'year'));

                    $this->assertFalse($row->parts->hasSnapshotData());
                }
            }
        );
    }
}
