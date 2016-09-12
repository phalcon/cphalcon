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
trait CollectionTrait
{
    /**
     * Executed before each test
     *
     * @param Actor $I
     */
    protected function setupMongo(Actor $I)
    {
        if (!extension_loaded('mongodb')) {
            throw new \PHPUnit_Framework_SkippedTestError(
                'Warning: mongo extension is not loaded'
            );
        }

        $I->haveServiceInDi('mongo', function() {
            $dsn = sprintf('mongodb://%s:%s', TEST_DB_MONGO_HOST, TEST_DB_MONGO_PORT);
            return new \MongoDB\Driver\Manager($dsn);
        }, true);

        $I->haveServiceInDi('collectionManager', function() {
            $manger = new Manager();
            $manger->setDatabaseName(TEST_DB_MONGO_NAME);

            return $manger;
        }, true);
    }
}
