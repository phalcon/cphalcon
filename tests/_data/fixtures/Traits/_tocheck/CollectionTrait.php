<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Traits;

use Codeception\Actor;
use Mongo;
use MongoClient;
use Phalcon\Mvc\Collection\Manager;
use PHPUnit\Framework\SkippedTestError;

trait CollectionTrait
{
    /**
     * Executed before each test
     */
    protected function setupMongo(Actor $I)
    {
        if (!extension_loaded('mongo')) {
            throw new SkippedTestError(
                'Warning: mongo extension is not loaded'
            );
        }

        $I->haveServiceInDi(
            'mongo',
            function () {
                $dsn = sprintf(
                    'mongodb://%s:%s',
                    DATA_MONGODB_HOST,
                    DATA_MONGODB_PORT
                );

                if (class_exists('MongoClient')) {
                    $mongo = new MongoClient($dsn);
                } else {
                    $mongo = new Mongo($dsn);
                }

                return $mongo->selectDB(DATA_MONGODB_NAME);
            },
            true
        );

        $I->addServiceToContainer(
            'collectionManager',
            function () {
                return new Manager();
            },
            true
        );
    }
}
