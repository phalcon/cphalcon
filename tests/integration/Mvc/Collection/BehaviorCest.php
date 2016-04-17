<?php

namespace Phalcon\Test\Integration\Mvc;

use Mongo;
use MongoClient;
use Phalcon\Di;
use IntegrationTester;
use Phalcon\Test\Collections\Subs;
use Phalcon\Mvc\Collection\Manager;

class BehaviorCest
{
    /**
     * Executed before each test
     *
     * @param IntegrationTester $I
     */
    public function _before(IntegrationTester $I)
    {
        if (!extension_loaded('mongo')) {
            throw new \PHPUnit_Framework_SkippedTestError(
                'Warning: mongo extension is not loaded'
            );
        }

        $I->haveServiceInDi('mongo', function() {
            $dsn = sprintf('mongodb://%s:%s', TEST_DB_MONGO_HOST, TEST_DB_MONGO_PORT);

            if (class_exists('MongoClient')) {
                $mongo = new MongoClient($dsn);
            } else {
                $mongo = new Mongo($dsn);
            }

            return $mongo->selectDB(TEST_DB_MONGO_NAME);
        }, true);

        $I->haveServiceInDi('collectionManager', function() {
            return new Manager();
        }, true);
    }

    public function behaviors(IntegrationTester $I)
    {
        $I->wantToTest('using behaviors with collections');

        // Timestampable
        $subscriber = new Subs();
        $subscriber->email = 'some@some.com';
        $subscriber->status = 'I';
        $I->assertTrue($subscriber->save());
        $I->assertEquals(1, preg_match('/[0-9]{4}-[0-9]{2}-[0-9]{2}/', $subscriber->created_at));

        // Soft delete
        $total = Subs::count();
        $subscriber = Subs::findFirst();
        $I->assertTrue($subscriber->delete());
        $I->assertEquals($subscriber->status, 'D');
        $I->assertEquals(Subs::count(), $total);
    }
}
