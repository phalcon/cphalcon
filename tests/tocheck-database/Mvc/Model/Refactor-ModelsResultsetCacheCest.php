<?php

namespace Phalcon\Tests\Integration\Mvc\Model;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Cache\Backend\File;
use Phalcon\Cache\Frontend\Data;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Robots;

use function cacheDir;

class ModelsResultsetCacheCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();

        $I->cleanDir(
            cacheDir()
        );
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    /**
     * @dataProvider adaptersProvider
     */
    public function testCacheDefaultDI(IntegrationTester $I, Example $example)
    {
        $diFunction = 'setDi' . $example[0];

        $this->{$diFunction}();

        if ($example[0] === 'Sqlite') {
            $I->skipTest('TODO Check Sqlite - tests lock up');
        }

        $I->skipTest('TODO = Check the numbers');

        $this->container->set(
            'modelsCache',
            function () {
                $frontCache = new Data();

                return new File(
                    $frontCache,
                    [
                        'storageDir' => cacheDir(),
                    ]
                );
            },
            true
        );

        //Find
        $robots = Robots::find(
            [
                'cache' => ['key' => 'some'],
                'order' => 'id',
            ]
        );
        $I->assertCount(3, $robots);

        /**
         * @todo Check the isFresh()
         */
//        $I->assertTrue($robots->isFresh());

        $robots = Robots::find(
            [
                'cache' => ['key' => 'some'],
                'order' => 'id',
            ]
        );

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
        if (!$this->container->get('db') instanceof Phalcon\Db\Adapter\Pdo\Postgresql) {
            //Aggregate functions like sum, count, etc
            $robotscount = Robots::count(
                [
                    'cache' => [
                        'key' => 'some-count',
                    ],
                ]
            );
            $I->assertEquals($robotscount, 3);

            //Create a temporary robot to test if the count is cached or fresh
            $newrobot = new Robots();

            $newrobot->name     = 'Not cached robot';
            $newrobot->type     = 'notcached';
            $newrobot->year     = 2014;
            $newrobot->datetime = '2015-03-05 04:16:17';
            $newrobot->text     = 'Not cached robot';

            $newrobot->create();

            $robotscount = Robots::count(
                [
                    'cache' => [
                        'key' => 'some-count',
                    ],
                ]
            );

            $I->assertEquals($robotscount, 3);

            //Delete the temp robot
            Robots::findFirst("type = 'notcached'")->delete();
        }
    }

    /**
     * @dataProvider adaptersProvider
     */
    public function testCacheDefaultDIBindings(IntegrationTester $I, Example $example)
    {
        $diFunction = 'setDi' . $example[0];

        $this->{$diFunction}();

        $this->getAndSetModelsCacheStream();

        $robots = Robots::find(
            [
                'cache'      => ['key' => 'some'],
                'conditions' => 'id > :id1: and id < :id2:',
                'bind'       => ['id1' => 0, 'id2' => 4],
                'order'      => 'id',
            ]
        );

        $I->assertCount(3, $robots);

        /**
         * @todo Check isFresh()
         */
//        $I->assertTrue($robots->isFresh());

        $robots = Robots::find(
            [
                'cache'      => ['key' => 'some'],
                'conditions' => 'id > :id1: and id < :id2:',
                'bind'       => ['id1' => 0, 'id2' => 4],
                'order'      => 'id',
            ]
        );

        $I->assertCount(3, $robots);

        $I->assertFalse(
            $robots->isFresh()
        );
    }

    /**
     * @dataProvider adaptersProvider
     */
    public function testCacheOtherService(IntegrationTester $I, Example $example)
    {
        $diFunction = 'setDi' . $example[0];

        $this->{$diFunction}();

        $I->skipTest('TODO = Check the numbers');

        $this->container->set(
            'otherCache',
            function () {
                $frontCache = new Data();

                return new File(
                    $frontCache,
                    [
                        'storageDir' => cacheDir(),
                    ]
                );
            },
            true
        );

        $robots = Robots::find(
            [
                'cache' => [
                    'key'      => 'other-some',
                    'lifetime' => 60,
                    'service'  => 'otherCache',
                ],
                'order' => 'id',
            ]
        );

        $I->assertCount(3, $robots);

        /**
         * @todo Check isFresh()
         */
        // $I->assertTrue(
        //     $robots->isFresh()
        // );

        $robots = Robots::find(
            [
                'cache' => [
                    'key'      => 'other-some',
                    'lifetime' => 60,
                    'service'  => 'otherCache',
                ],
                'order' => 'id',
            ]
        );

        $I->assertCount(3, $robots);

        $I->assertFalse(
            $robots->isFresh()
        );

        $I->assertEquals(
            'other-some',
            $robots->getCache()->getLastKey()
        );

        $I->assertEquals(
            [
                0 => 'other-some',
            ],
            $robots->getCache()->queryKeys()
        );
    }

    private function adaptersProvider(): array
    {
        return [
            [
                'Mysql',
            ],
            [
                'Postgresql',
            ],
            [
                'Sqlite',
            ],
        ];
    }
}
