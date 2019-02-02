<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model\Resultset;

use IntegrationTester;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\People;
use Phalcon\Test\Models\Robots;
use function cacheFolder;

class SimpleCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();
        $I->cleanDir(cacheFolder());
    }

    /**
     * Work with Simple Resultset by load data from the file cache (complete
     * PHQL option).
     *
     * @test
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2012-11-20
     */
    public function shouldLoadResultsetFromCacheByUsingCompletePhql(IntegrationTester $I)
    {
        $I->skipTest('TODO - Check the counts');
        $cache   = $this->getAndSetModelsCacheFile();
        $manager = $this->getService('modelsManager');

        $robots = $manager->executeQuery('SELECT * FROM ' . Robots::class);

        $I->assertInstanceOf(Simple::class, $robots);
        $I->assertCount(3, $robots);
        $I->assertEquals($robots->count(), 3);

        $cache->save('test-resultset', $robots);

        $I->amInPath(cacheFolder());
        $I->seeFileFound('test-resultset');

        $robots = $cache->get('test-resultset');

        $I->assertInstanceOf(Simple::class, $robots);
        $I->assertCount(3, $robots);
        $I->assertEquals($robots->count(), 3);
        $cache->delete('test-resultset');

        $I->amInPath(cacheFolder());
        $I->dontSeeFileFound('test-resultset');
    }

    /**
     * Work with Simple Resultset by load data from the file cache (incomplete
     * PHQL option).
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2012-12-28
     */
    public function shouldLoadResultsetFromCacheByUsingIncompletePhql(IntegrationTester $I)
    {
        $I->skipTest('TODO = Check the numbers');
        $cache   = $this->getAndSetModelsCacheFile();
        $manager = $this->getService('modelsManager');

        $robots = $manager->executeQuery('SELECT id FROM ' . Robots::class);

        $I->assertInstanceOf(Simple::class, $robots);
        $I->assertCount(3, $robots);
        $I->assertEquals($robots->count(), 3);

        $cache->save('test-resultset', $robots);

        $I->amInPath(cacheFolder());
        $I->seeFileFound('test-resultset');

        $robots = $cache->get('test-resultset');

        $I->assertInstanceOf(Simple::class, $robots);
        $I->assertCount(3, $robots);
        $I->assertEquals($robots->count(), 3);

        $cache->delete('test-resultset');
        $I->amInPath(cacheFolder());
        $I->dontSeeFileFound('test-resultset');
    }

    /**
     * Work with Simple Resultset by load data from the file cache.
     *
     * @test
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2012-11-20
     */
    public function shouldLoadResultsetFromCache(IntegrationTester $I)
    {
        $I->skipTest('TODO = Check the numbers');
        $cache = $this->getAndSetModelsCacheFile();

        $robots = Robots::find(['order' => 'id']);

        $I->assertInstanceOf(Simple::class, $robots);
        $I->assertCount(3, $robots);
        $I->assertEquals($robots->count(), 3);

        $cache->save('test-resultset', $robots);

        $I->amInPath(cacheFolder());
        $I->seeFileFound('test-resultset');

        $robots = $cache->get('test-resultset');

        $I->assertInstanceOf(Simple::class, $robots);
        $I->assertCount(3, $robots);
        $I->assertEquals($robots->count(), 3);

        $cache->delete('test-resultset');
        $I->amInPath(cacheFolder());
        $I->dontSeeFileFound('test-resultset');
    }

    /**
     * Work with Simple Resultset with binding by load data from the file cache.
     *
     * @test
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2012-11-20
     */
    public function shouldLoadResultsetWithBindingFromCache(IntegrationTester $I)
    {
        $cache   = $this->getAndSetModelsCacheFile();
        $manager = $this->getService('modelsManager');

        $initialId = 0;
        $finalId   = 4;

        $robots = Robots::find([
            'conditions' => 'id > :id1: and id < :id2:',
            'bind'       => ['id1' => $initialId, 'id2' => $finalId],
            'order'      => 'id',
        ]);

        $I->assertInstanceOf(Simple::class, $robots);
        $I->assertCount(3, $robots);
        $I->assertEquals($robots->count(), 3);

        $cache->save('test-resultset', $robots);

        $I->amInPath(cacheFolder());
        $I->seeFileFound('test-resultset');

        $robots = $cache->get('test-resultset');

        $I->assertInstanceOf(Simple::class, $robots);
        $I->assertCount(3, $robots);
        $I->assertEquals($robots->count(), 3);

        $cache->delete('test-resultset');
        $I->amInPath(cacheFolder());
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
        $cache = $this->getAndSetModelsCacheFileLibmemcached();

        $key = 'test-resultset-' . mt_rand(0, 9999);
        // Single
        $people = People::findFirst([
            'cache' => [
                'key' => $key,
            ],
        ]);

        $I->assertInstanceOf(People::class, $people);

        $people = $cache->get($key);
        $I->assertInstanceOf(People::class, $people->getFirst());

        $people = $cache->get($key);
        $I->assertInstanceOf(People::class, $people->getFirst());

        // Re-get from the cache
        $people = People::findFirst([
            'cache' => [
                'key' => $key,
            ],
        ]);

        $I->assertInstanceOf(People::class, $people);

        $key = 'test-resultset-' . mt_rand(0, 9999);

        // Multiple
        $people = People::find([
            'limit' => 35,
            'cache' => [
                'key' => $key,
            ],
        ]);

        $number = 0;
        foreach ($people as $individual) {
            $I->assertInstanceOf(People::class, $individual);
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
        $people = People::find([
            'limit' => 35,
            'cache' => [
                'key' => $key,
            ],
        ]);

        $number = 0;
        foreach ($people as $individual) {
            $I->assertInstanceOf(People::class, $individual);
            $number++;
        }

        $I->assertEquals($number, 35);
    }
}
