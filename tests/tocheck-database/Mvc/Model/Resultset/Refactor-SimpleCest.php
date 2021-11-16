<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Integration\Mvc\Model\Resultset;

use IntegrationTester;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\People;
use Phalcon\Tests\Models\Robots;

class SimpleCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();

        $I->cleanDir(
            cacheModelsDir()
        );
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    /**
     * Work with Simple Resultset by load data from the file cache.
     *
     * @test
     * @author Phalcon Team <team@phalcon.io>
     * @since  2012-11-20
     */
    public function shouldLoadResultsetFromCache(IntegrationTester $I)
    {
        $I->skipTest('TODO = Check the numbers');

        $cache = $this->getAndSetModelsCacheStream();

        $robots = Robots::find(
            [
                'order' => 'id',
            ]
        );

        $I->assertInstanceOf(Simple::class, $robots);
        $I->assertCount(3, $robots);
        $I->assertEquals(3, $robots->count());

        $cache->set('test-resultset', $robots);

        $I->amInPath(cacheModelsDir());
        $I->seeFileFound('test-resultset');

        $robots = $cache->get('test-resultset');

        $I->assertInstanceOf(Simple::class, $robots);
        $I->assertCount(3, $robots);
        $I->assertEquals(3, $robots->count());

        $cache->delete('test-resultset');

        $I->amInPath(
            cacheModelsDir()
        );

        $I->dontSeeFileFound('test-resultset');
    }

    /**
     * Work with Simple Resultset with binding by load data from the file cache.
     *
     * @test
     * @author Phalcon Team <team@phalcon.io>
     * @since  2012-11-20
     */
    public function shouldLoadResultsetWithBindingFromCache(IntegrationTester $I)
    {
        $cache   = $this->getAndSetModelsCacheStream();
        $manager = $this->getService('modelsManager');

        $initialId = 0;
        $finalId   = 4;

        $robots = Robots::find(
            [
                'conditions' => 'id > :id1: and id < :id2:',
                'bind'       => ['id1' => $initialId, 'id2' => $finalId],
                'order'      => 'id',
            ]
        );

        $I->assertInstanceOf(Simple::class, $robots);
        $I->assertCount(3, $robots);
        $I->assertEquals(3, $robots->count());

        $cache->set('test-resultset', $robots);

        $I->amInPath(cacheModelsDir());
        $I->seeFileFound('test-resultset');

        $robots = $cache->get('test-resultset');

        $I->assertInstanceOf(Simple::class, $robots);
        $I->assertCount(3, $robots);
        $I->assertEquals(3, $robots->count());

        $cache->delete('test-resultset');

        $I->amInPath(
            cacheModelsDir()
        );

        $I->dontSeeFileFound('test-resultset');
    }

    /**
     * Work with Simple Resultset by load data from cache (Libmemcached
     * adapter).
     *
     * @author kjdev
     * @since  2013-07-25
     */
    public function shouldLoadResultsetFromLibmemcached(IntegrationTester $I)
    {
        $cache = $this->getAndSetModelsCacheLibmemcached();

        $cache->clear();

        $key = 'test-resultset-' . mt_rand(0, 9999);

        // Single
        $people = People::findFirst(
            [
                'cache' => [
                    'key' => $key,
                ],
            ]
        );

        $I->assertInstanceOf(
            People::class,
            $people
        );

        $people = $cache->get($key);

        $I->assertInstanceOf(
            People::class,
            $people->getFirst()
        );

        $people = $cache->get($key);

        $I->assertInstanceOf(
            People::class,
            $people->getFirst()
        );

        // Re-get from the cache
        $people = People::findFirst(
            [
                'cache' => [
                    'key' => $key,
                ],
            ]
        );

        $I->assertInstanceOf(
            People::class,
            $people
        );

        $key = 'test-resultset-' . mt_rand(0, 9999);

        // Multiple
        $people = People::find(
            [
                'limit' => 35,
                'cache' => [
                    'key' => $key,
                ],
            ]
        );

        $number = 0;

        foreach ($people as $individual) {
            $I->assertInstanceOf(
                People::class,
                $individual
            );

            $number++;
        }

        $I->assertEquals($number, 35);

        $people = $cache->get($key);
        $I->assertInstanceOf(Simple::class, $people);

        $number = 0;
        foreach ($people as $individual) {
            $I->assertInstanceOf(People::class, $individual);
            $number++;
        }

        $I->assertEquals($number, 35);

        $people = $cache->get($key);
        $I->assertInstanceOf(Simple::class, $people);

        // Re-get the data from the cache
        $people = People::find(
            [
                'limit' => 35,
                'cache' => [
                    'key' => $key,
                ],
            ]
        );

        $number = 0;
        foreach ($people as $individual) {
            $I->assertInstanceOf(People::class, $individual);
            $number++;
        }

        $I->assertEquals($number, 35);
    }
}
