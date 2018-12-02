<?php

namespace Phalcon\Test\Unit\Mvc;

use DateTime;
use Helper\ModelTrait;
use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Message;
use Phalcon\Test\Models\ModelWithStringField;
use Phalcon\Test\Models\Users;
use Phalcon\Cache\Backend\Apc;
use Phalcon\Test\Models\Robots;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Cache\Frontend\Data;
use Phalcon\Test\Models\Boutique;
use Phalcon\Test\Models\Packages;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Test\Models\Robotters;
use Phalcon\Test\Models\Personers;
use Phalcon\Test\Models\Customers;
use Phalcon\Test\Models\PackageDetails;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Test\Models\BodyParts\Body;
use Phalcon\Test\Models\News\Subscribers;
use Phalcon\Test\Models\AlbumORama\Albums;
use Phalcon\Test\Models\Validation;
use PHPUnit\Framework\SkippedTestError;

/**
 * \Phalcon\Test\Unit\Mvc\ModelTest
 * Tests the Phalcon\Mvc\Model component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Unit\Mvc
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ModelTest extends UnitTest
{
    use ModelTrait;

    public function testCamelCaseRelation()
    {
        $this->specify(
            "CamelCase relation calls should be the same cache",
            function () {
                $modelsManager = $this->setUpModelsManager();

                $modelsManager->registerNamespaceAlias('AlbumORama', 'Phalcon\Test\Models\AlbumORama');
                $album = Albums::findFirst();

                $album->artist->name = 'NotArtist';
                expect($album->artist->name)->equals($album->Artist->name);
            }
        );
    }

    /**
     * Tests find with empty conditions + bind and limit.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/11919
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
     * @issue  https://github.com/phalcon/cphalcon/issues/12035
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
     * @issue  https://github.com/phalcon/cphalcon/issues/11991
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
     * @issue  https://github.com/phalcon/cphalcon/issues/12071
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
     * @issue  https://github.com/phalcon/cphalcon/issues/12170
     * @issue  https://github.com/phalcon/cphalcon/issues/12000
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
            throw new SkippedTestError(
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
                $modelsManager = $this->setUpModelsManager();
                $robot = Robots::findFirst();

                // Single row serialization
                $result = $modelsManager->executeQuery("SELECT id FROM " . Robots::class . " LIMIT 1");

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
                $subscriber = new Subscribers();

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
                $number = Subscribers::count();

                $subscriber = Subscribers::findFirst();

                expect($subscriber->delete())->true();
                expect($subscriber->status)->equals('D');
                expect(Subscribers::count())->equals($number);
            }
        );
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/12507
     */
    public function testFieldDefaultEmptyStringIsNull()
    {
        $this->specify(
            'The field default value is empty string and is determined to be null',
            function () {
                $personers = new Personers([
                    'borgerId'     => 'id-' . time() . rand(1, 99),
                    'slagBorgerId' => 1,
                    'kredit'       => 2.3,
                    'status'       => 'A',
                ]);

                //  test field for create
                $personers->navnes = '';
                $created = $personers->create();

                expect($created)->true();

                //  write something to not null default '' field
                $personers->navnes = 'save something!';

                $saved = $personers->save();
                expect($saved)->true();

                //  test field for update
                $personers->navnes = '';
                $saved = $personers->save();

                expect($saved)->true();

                $personers->delete();
            }
        );
    }


    /**
     * Tests setting code in message from validation messages
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/12645
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-03
     */
    public function testIssue12645()
    {
        $this->specify(
            "Issue #12645 is not fixed",
            function () {
                $robots = new Validation\Robots(
                    [
                        'name'     => 'asd',
                        'type'     => 'mechanical',
                        'year'     => 2017,
                        'datetime' => (new \DateTime())->format('Y-m-d'),
                        'text'     => 'asd',
                    ]
                );
                expect($robots->create())->false();
                /** @var Message $message */
                $message = $robots->getMessages()[0];
                expect($message)->isInstanceOf(Message::class);
                expect($message->getCode())->equals(20);
            }
        );
    }

    /**
     * Tests empty string value on not null
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/12688
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-09
     */
    public function testIssue12688()
    {
        $this->specify(
            'Issue 12688 is happening',
            function () {
                $robots = new Robots();
                $robots->name = '';
                $robots->save(
                    [
                        'datetime' => (new DateTime())->format('Y-m-d'),
                        'text'     => 'text',
                    ]
                );
            }
        );
    }

    /**
     * Tests disabling assign setters
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/12645
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-23
     */
    public function testAssignSettersDisabled()
    {
        $this->specify(
            'Disabling setters in assign is not working',
            function () {
                $robots = new Robots(
                    [
                        'name' => 'test',
                    ]
                );
                expect($robots->wasSetterUsed)->true();
                Model::setup(
                    [
                        'disableAssignSetters' => true,
                    ]
                );
                $robots = new Robots(
                    [
                        'name' => 'test',
                    ]
                );
                expect($robots->wasSetterUsed)->false();
                Model::setup(
                    [
                        'disableAssignSetters' => false,
                    ]
                );
            }
        );
    }

    /**
     * Test check allowEmptyStringValues
     *
     * @author Nikolay Sumrak <nikolassumrak@gmail.com>
     * @since 2017-11-16
     */
    public function testAllowEmptyStringFields()
    {
        $this->specify(
            'Allow empty string value',
            function () {
                Model::setup(
                    [
                        'notNullValidations' => true,
                        'exceptionOnFailedSave' => false,
                    ]
                );

                $model = new ModelWithStringField();
                $model->field = '';
                $model->disallowEmptyStringValue();
                $status = $model->save();
                expect($status)->false();

                $model->allowEmptyStringValue();
                $status = $model->save();
                expect($status)->true();

                Model::setup(
                    [
                        'notNullValidations' => false,
                        'exceptionOnFailedSave' => true,
                    ]
                );
            }
        );
    }

    /**
     * @author Jakob Oberhummer <cphalcon@chilimatic.com>
     * @since 2017-12-18
     */
    public function testUseTransactionWithinFind()
    {
        $this->specify(
            'Transaction is passed as option parameter',
            function () {
                /**
                 * @var $transactionManager \Phalcon\Mvc\Model\Transaction\Manager
                 */
                $transactionManager = $this->setUpTransactionManager();
                $transaction = $transactionManager->getOrCreateTransaction();

                $newSubscriber = new Subscribers();
                $newSubscriber->setTransaction($transaction);
                $newSubscriber->email = 'transaction@example.com';
                $newSubscriber->status = 'I';
                $newSubscriber->save();

                $subscriber = Subscribers::find(
                    [
                        'email = "transaction@example.com"',
                        'transaction' => $transaction
                    ]
                );

                expect(\count($subscriber), 1);
            }
        );
    }

    /**
     * @author Jakob Oberhummer <cphalcon@chilimatic.com>
     * @since 2017-12-18
     */
    public function testUseTransactionWithinFindFirst()
    {
        $this->specify(
            'Transaction is passed as option parameter',
            function () {
                /**
                 * @var $transactionManager \Phalcon\Mvc\Model\Transaction\Manager
                 */
                $transactionManager = $this->setUpTransactionManager();
                $transaction = $transactionManager->getOrCreateTransaction();

                $newSubscriber = new Subscribers();
                $newSubscriber->setTransaction($transaction);
                $newSubscriber->email = 'transaction@example.com';
                $newSubscriber->status = 'I';
                $newSubscriber->save();

                $subscriber = Subscribers::findFirst(
                    [
                        'email = "transaction@example.com"',
                        'transaction' => $transaction
                    ]
                );

                expect(\get_class($subscriber), 'Subscriber');
            }
        );
    }

    /**
     * @author Jakob Oberhummer <cphalcon@chilimatic.com>
     * @since 2017-12-18
     */
    public function testUseTransactionOutsideFind()
    {
        $this->specify(
            'Query outside of the creation transaction',
            function () {
                /**
                 * @var $transactionManager \Phalcon\Mvc\Model\Transaction\Manager
                 */
                $transactionManager = $this->setUpTransactionManager();
                $transaction = $transactionManager->getOrCreateTransaction();

                $newSubscriber = new Subscribers();
                $newSubscriber->setTransaction($transaction);
                $newSubscriber->email = 'transaction@example.com';
                $newSubscriber->status = 'I';
                $newSubscriber->save();

                /**
                 * @var $transactionManager \Phalcon\Mvc\Model\Transaction\Manager
                 */
                $transactionManager = $this->setUpTransactionManager();
                $secondTransaction = $transactionManager->getOrCreateTransaction();

                $subscriber = Subscribers::find(
                    [
                        'email = "transaction@example.com"',
                        'transaction' => $secondTransaction
                    ]
                );

                expect(\count($subscriber), 0);
            }
        );
    }

    /**
     * @author Jakob Oberhummer <cphalcon@chilimatic.com>
     * @since 2017-12-18
     */
    public function testUseTransactionOutsideFindFirst()
    {
        $this->specify(
            'Query outside of the creation transaction',
            function () {
                /**
                 * @var $transactionManager \Phalcon\Mvc\Model\Transaction\Manager
                 */
                $transactionManager = $this->setUpTransactionManager();
                $transaction = $transactionManager->getOrCreateTransaction();

                $newSubscriber = new Subscribers();
                $newSubscriber->setTransaction($transaction);
                $newSubscriber->email = 'transaction@example.com';
                $newSubscriber->status = 'I';
                $newSubscriber->save();

                /**
                 * @var $transactionManager \Phalcon\Mvc\Model\Transaction\Manager
                 */
                $transactionManager = $this->setUpTransactionManager();
                $secondTransaction = $transactionManager->getOrCreateTransaction();

                $subscriber = Subscribers::findFirst(
                    [
                        'email = "transaction@example.com"',
                        'transaction' => $secondTransaction
                    ]
                );

                expect(false, $subscriber);
            }
        );
    }

    /**
     * Tests binding of non-scalar values by casting to string and binding them.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/13058
     * @author Cameron Hall <me@chall.id.au>
     * @since  2018-11-06
     */
    public function testIssue13058()
    {
        $this->specify(
            'Issue 13058 is happening, non-scalar values are not being casted and bound.',
            function () {

                $robots = new Robots();
                $robots->name = '';
                $robots->save(
                    [
                        'datetime' => new \Phalcon\Test\Db\DateTime(),
                        'text'     => 'text',
                    ]
                );
            }
        );
    }
}
