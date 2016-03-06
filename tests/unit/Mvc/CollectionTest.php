<?php

namespace Phalcon\Test\Unit\Mvc;

use MongoClient;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Test\Collections\Songs;
use Phalcon\Mvc\Collection\Manager as CollectionManager;

/**
 * \Phalcon\Test\Unit\Mvc\CollectionTest
 * Tests the Phalcon\Mvc\Collection component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Mvc
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class CollectionTest extends UnitTest
{
    /**
     * executed before each test
     */
    protected function _before()
    {
        parent::_before();

        if (!extension_loaded('mongo')) {
            $this->markTestSkipped('Warning: mongo extension is not loaded');
        }

        /** @var \Codeception\Module\Phalcon2 $module */
        $module = $this->getModule('Phalcon2');

        /** @var \Phalcon\Mvc\Application $app */
        $app = $module->getApplication();

        $app->getDI()->setShared('mongo', function() {
            $mongo = new MongoClient();
            return $mongo->selectDB(TEST_DB_MONGO_NAME);
        });

        $app->getDI()->setShared('collectionManager', function() {
            return new CollectionManager();
        });
    }

    public function testShouldCatchExceptionOnUpdateNonExistentDocument()
    {
        $this->specify(
            "Test does not catch Collection Exception on update non existent document",
            function () {
                $song = new Songs();
                $song->artist = 'Cinema Strange';
                $song->name = 'Legs and Tarpaulin';

                $song->update();
            },
            ['throws' => ['Phalcon\Mvc\Collection\Exception', "The document cannot be updated because it doesn't exist"]]
        );
    }
}
