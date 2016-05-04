<?php

namespace Helper;

use Mongo;
use MongoClient;
use Codeception\Actor;
use Phalcon\Mvc\Collection\Manager;

/**
 * Collection Initializer
 *
 * @package Helper
 */
trait Collection
{
    /**
     * Executed before each test
     *
     * @param Actor $I
     */
    protected function setupMongo(Actor $I)
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
}
