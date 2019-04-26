<?php

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;
use Phalcon\Cache\Backend\File;
use Phalcon\Cache\Frontend\Data;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Robots;
use function cacheFolder;

class ModelsResultsetCacheCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $I->cleanDir(cacheFolder());
    }

    public function testCacheDefaultDIMysql(IntegrationTester $I)
    {
        $this->setDiMysql();
        $this->testCacheDefaultDI($I);
    }

    private function testCacheDefaultDI(IntegrationTester $I)
    {
        $I->skipTest('TODO = Check the numbers');
        $this->container->set(
            'modelsCache',
            function () {
                $frontCache = new Data();
                return new File(
                    $frontCache,
                    [
                        'cacheDir' => cacheFolder(),
                    ]
                );
            },
            true
        );

        //Find
        $robots = Robots::find([
            'cache' => ['key' => 'some'],
            'order' => 'id',
        ]);
        $I->assertCount(3, $robots);
        /**
         * @todo Check the isFresh()
         */
//        $I->assertTrue($robots->isFresh());

        $robots = Robots::find([
            'cache' => ['key' => 'some'],
            'order' => 'id',
        ]);
        $I->assertCount(3, $robots);
        /**
         * @todo Check the isFresh()
         */
//        $I->assertFalse($robots->isFresh());

        //TODO: I really can't understand why postgresql fails on inserting a simple record
        //The error is "Object not in prerequisite state: 7 ERROR:
        //currval of sequence "robots_id_seq" is not yet defined in this session"
        //Is the ORM working with postgresql, is the database structure incorrect or
        //I'm using the wrong code?
        //Skip this test until someone can shed some light on this
        if (!$this->container->get("db") instanceof Phalcon\Db\Adapter\Pdo\Postgresql) {
            //Aggregate functions like sum, count, etc
            $robotscount = Robots::count([
                'cache' => ['key' => 'some-count'],
            ]);
            $I->assertEquals($robotscount, 3);

            //Create a temporary robot to test if the count is cached or fresh
            $newrobot           = new Robots();
            $newrobot->name     = "Not cached robot";
            $newrobot->type     = "notcached";
            $newrobot->year     = 2014;
            $newrobot->datetime = '2015-03-05 04:16:17';
            $newrobot->text     = 'Not cached robot';
            $newrobot->create();

            $robotscount = Robots::count([
                'cache' => ['key' => 'some-count'],
            ]);
            $I->assertEquals($robotscount, 3);

            //Delete the temp robot
            Robots::findFirst("type = 'notcached'")->delete();
        }
    }

    public function testCacheDefaultDIPostgresql(IntegrationTester $I)
    {
        $this->setDiPostgresql();
        $this->testCacheDefaultDI($I);
    }

    public function testCacheDefaultDISqlite(IntegrationTester $I)
    {
        $this->setDiSqlite();
        /**
         * @todo Check Sqlite - tests lock up
         */
//        $this->testCacheDefaultDI($I);
    }

    public function testCacheDefaultDIBindingsMysql(IntegrationTester $I)
    {
        $this->setDiMysql();
        $this->testCacheDefaultDIBindings($I);
    }

    private function testCacheDefaultDIBindings(IntegrationTester $I)
    {
        $this->container->set(
            'modelsCache',
            function () {
                $frontCache = new Data();
                return new File(
                    $frontCache,
                    [
                        'cacheDir' => cacheFolder(),
                    ]
                );
            },
            true
        );

        $robots = Robots::find([
            'cache'      => ['key' => 'some'],
            'conditions' => 'id > :id1: and id < :id2:',
            'bind'       => ['id1' => 0, 'id2' => 4],
            'order'      => 'id',
        ]);
        $I->assertCount(3, $robots);
        /**
         * @todo Check isFresh()
         */
//        $I->assertTrue($robots->isFresh());

        $robots = Robots::find([
            'cache'      => ['key' => 'some'],
            'conditions' => 'id > :id1: and id < :id2:',
            'bind'       => ['id1' => 0, 'id2' => 4],
            'order'      => 'id',
        ]);
        $I->assertCount(3, $robots);
        $I->assertFalse($robots->isFresh());
    }

    public function testCacheDefaultDIBindingsPostgresql(IntegrationTester $I)
    {
        $this->setDiPostgresql();
        $this->testCacheDefaultDIBindings($I);
    }

    public function testCacheDefaultDIBindingsSqlite(IntegrationTester $I)
    {
        $this->setDiSqlite();
        $this->testCacheDefaultDIBindings($I);
    }

    public function testCacheOtherServiceMysql(IntegrationTester $I)
    {
        $this->setDiMysql();
        $this->testCacheOtherService($I);
    }

    private function testCacheOtherService(IntegrationTester $I)
    {
        $I->skipTest('TODO = Check the numbers');
        $this->container->set(
            'otherCache',
            function () {
                $frontCache = new Data();
                return new File(
                    $frontCache,
                    [
                        'cacheDir' => cacheFolder(),
                    ]
                );
            },
            true
        );

        $robots = Robots::find([
            'cache' => [
                'key'      => 'other-some',
                'lifetime' => 60,
                'service'  => 'otherCache',
            ],
            'order' => 'id',
        ]);
        $I->assertCount(3, $robots);
        /**
         * @todo Check isFresh()
         */
//        $I->assertTrue($robots->isFresh());

        $robots = Robots::find([
            'cache' => [
                'key'      => 'other-some',
                'lifetime' => 60,
                'service'  => 'otherCache',
            ],
            'order' => 'id',
        ]);
        $I->assertCount(3, $robots);
        $I->assertFalse($robots->isFresh());

        $I->assertEquals($robots->getCache()->getLastKey(), 'other-some');

        $I->assertEquals($robots->getCache()->queryKeys(), [
            0 => 'other-some',
        ]);
    }

    public function testCacheOtherServicePostgresql(IntegrationTester $I)
    {
        $this->setDiPostgresql();
        $this->testCacheOtherService($I);
    }

    public function testCacheOtherServiceSqlite(IntegrationTester $I)
    {
        $this->setDiSqlite();
        $this->testCacheOtherService($I);
    }
}
