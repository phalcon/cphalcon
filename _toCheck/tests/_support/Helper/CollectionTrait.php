<?php

namespace Helper;

use Codeception\Actor;
use Mongo;
use MongoClient;
use Phalcon\Mvc\Collection\Manager;
use PHPUnit\Framework\SkippedTestError;

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
        if (!extension_loaded('mongo')) {
            throw new SkippedTestError(
                'Warning: mongo extension is not loaded'
            );
        }

        $I->haveServiceInDi('mongo', function () {
            $dsn = sprintf('mongodb://%s:%s', TEST_DB_MONGO_HOST, TEST_DB_MONGO_PORT);

            if (class_exists('MongoClient')) {
                $mongo = new MongoClient($dsn);
            } else {
                $mongo = new Mongo($dsn);
            }

            return $mongo->selectDB(TEST_DB_MONGO_NAME);
        }, true);

        $I->haveServiceInDi('collectionManager', function () {
            return new Manager();
        }, true);
    }
}
