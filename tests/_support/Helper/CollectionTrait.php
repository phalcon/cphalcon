<?php

namespace Helper;

use Mongo;
use MongoClient;
use Codeception\Actor;
use Phalcon\Mvc\Collection\Manager;
use MongoDB\Driver\Manager as MongoManager;

/**
 * Collection Initializer
 *
 * @package Helper
 */
trait CollectionTrait
{
    /**
     * Executed before each test
     *
     * @param Actor $I
     */
    protected function setupMongo(Actor $I)
    {
        if (!extension_loaded('mongo') && !extension_loaded('mongodb')) {
            throw new \PHPUnit_Framework_SkippedTestError(
                'Warning: mongo extension is not loaded'
            );
        }

        $I->haveServiceInDi('mongo', function() {
            if (class_exists(MongoManager::class)) {
                $mongo = new MongoManager(
                    sprintf('mongodb://%s:%s/%s', TEST_DB_MONGO_HOST, TEST_DB_MONGO_PORT, TEST_DB_MONGO_NAME)
                );
                return $mongo->selectServer();
            }

            $dsn = sprintf('mongodb://%s:%s', TEST_DB_MONGO_HOST, TEST_DB_MONGO_PORT);

            if (class_exists(MongoClient::class)) {
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
