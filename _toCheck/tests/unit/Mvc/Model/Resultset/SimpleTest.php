<?php

namespace Phalcon\Test\Unit\Mvc\Model\Resultset;

use Phalcon\Di;
use Phalcon\Test\Models\Robots;
use Phalcon\Test\Models\People;
use Helper\ResultsetHelperTrait;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Mvc\Model\Resultset\Simple;

/**
 * \Phalcon\Test\Unit\Mvc\Model\Resultset\SimpleTest
 * Tests the Phalcon\Mvc\Model\Resultset\Simple component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Mvc\Model\Resultset
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class SimpleTest extends UnitTest
{
    use ResultsetHelperTrait;

    /**
     * executed before each test
     */
    protected function _before()
    {
        parent::_before();

        $this->setUpEnvironment();
    }

    /**
     * Work with Simple Resultset by load data from the file cache (complete PHQL option).
     *
     * @test
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2012-11-20
     */
    public function shouldLoadResultsetFromCacheByUsingCompletePhql()
    {
        $this->specify(
            'Simple Resultset does not work as expected (complete PHQL option)',
            function () {
                $cache = $this->getFileCache();
                $this->setUpModelsCache($cache);

                $modelsManager = Di::getDefault()->get('modelsManager');

                $robots = $modelsManager->executeQuery('SELECT * FROM ' . Robots::class);

                expect($robots)->isInstanceOf(Simple::class);
                expect($robots)->count(3);
                expect($robots->count())->equals(3);

                $cache->save('test-resultset', $robots);

                $this->tester->amInPath(PATH_CACHE);
                $this->tester->seeFileFound('test-resultset');

                $robots = $cache->get('test-resultset');

                expect($robots)->isInstanceOf(Simple::class);
                expect($robots)->count(3);
                expect($robots->count())->equals(3);

                $this->tester->deleteFile('test-resultset');
            }
        );
    }

    /**
     * Work with Simple Resultset by load data from the file cache (incomplete PHQL option).
     *
     * @test
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2012-12-28
     */
    public function shouldLoadResultsetFromCacheByUsingIncompletePhql()
    {
        $this->specify(
            'Simple Resultset does not work as expected (incomplete PHQL option)',
            function () {
                $cache = $this->getFileCache();
                $this->setUpModelsCache($cache);

                $modelsManager = Di::getDefault()->get('modelsManager');

                $robots = $modelsManager->executeQuery('SELECT id FROM ' . Robots::class);

                expect($robots)->isInstanceOf(Simple::class);
                expect($robots)->count(3);
                expect($robots->count())->equals(3);

                $cache->save('test-resultset', $robots);

                $this->tester->amInPath(PATH_CACHE);
                $this->tester->seeFileFound('test-resultset');

                $robots = $cache->get('test-resultset');

                expect($robots)->isInstanceOf(Simple::class);
                expect($robots)->count(3);
                expect($robots->count())->equals(3);

                $this->tester->deleteFile('test-resultset');
            }
        );
    }

    /**
     * Work with Simple Resultset by load data from the file cache.
     *
     * @test
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2012-11-20
     */
    public function shouldLoadResultsetFromCache()
    {
        $this->specify(
            'Simple Resultset does not work as expected',
            function () {
                $cache = $this->getFileCache();
                $this->setUpModelsCache($cache);

                $robots = Robots::find(['order' => 'id']);

                expect($robots)->isInstanceOf(Simple::class);
                expect($robots)->count(3);
                expect($robots->count())->equals(3);

                $cache->save('test-resultset', $robots);

                $this->tester->amInPath(PATH_CACHE);
                $this->tester->seeFileFound('test-resultset');

                $robots = $cache->get('test-resultset');

                expect($robots)->isInstanceOf(Simple::class);
                expect($robots)->count(3);
                expect($robots->count())->equals(3);

                $this->tester->deleteFile('test-resultset');
            }
        );
    }

    /**
     * Work with Simple Resultset with binding by load data from the file cache.
     *
     * @test
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2012-11-20
     */
    public function shouldLoadResultsetWithBindingFromCache()
    {
        $this->specify(
            'Simple Resultset with binding does not work as expected',
            function () {
                $cache = $this->getFileCache();
                $this->setUpModelsCache($cache);

                $initialId = 0;
                $finalId = 4;

                $robots = Robots::find([
                    'conditions' => 'id > :id1: and id < :id2:',
                    'bind'       => ['id1' => $initialId, 'id2' => $finalId],
                    'order'      => 'id'
                ]);

                expect($robots)->isInstanceOf(Simple::class);
                expect($robots)->count(3);
                expect($robots->count())->equals(3);

                $cache->save('test-resultset', $robots);

                $this->tester->amInPath(PATH_CACHE);
                $this->tester->seeFileFound('test-resultset');

                $robots = $cache->get('test-resultset');

                expect($robots)->isInstanceOf(Simple::class);
                expect($robots)->count(3);
                expect($robots->count())->equals(3);

                $this->tester->deleteFile('test-resultset');
            }
        );
    }

    /**
     * Work with Simple Resultset by load data from cache (Libmemcached adapter).
     *
     * @test
     * @author kjdev
     * @since  2013-07-25
     */
    public function shouldLoadResultsetFromLibmemcached()
    {
        $this->specify(
            'Unable to test Simple Resultset by using Libmemcached adapter',
            function () {
                $cache = $this->getLibmemcachedCache();
                $this->setUpModelsCache($cache);

                $key = 'test-resultset-'.mt_rand(0, 9999);

                // Single
                $people = People::findFirst([
                    'cache' => [
                        'key' => $key
                    ]
                ]);

                expect($people)->isInstanceOf(People::class);

                $people = $cache->get($key);
                expect($people->getFirst())->isInstanceOf(People::class);

                $people = $cache->get($key);
                expect($people->getFirst())->isInstanceOf(People::class);

                // Re-get from the cache
                $people = People::findFirst([
                    'cache' => [
                        'key' => $key
                    ]
                ]);

                expect($people)->isInstanceOf(People::class);

                $key = 'test-resultset-'.mt_rand(0, 9999);

                // Multiple
                $people = People::find([
                    'limit' => 35,
                    'cache' => [
                        'key' => $key
                    ]
                ]);

                $number = 0;
                foreach ($people as $individual) {
                    expect($individual)->isInstanceOf(People::class);
                    $number++;
                }

                expect($number)->equals(35);

                $people = $cache->get($key);
                expect($people)->isInstanceOf(Simple::class);

                $number = 0;
                foreach ($people as $individual) {
                    expect($individual)->isInstanceOf(People::class);
                    $number++;
                }

                expect($number)->equals(35);

                $people = $cache->get($key);
                expect($people)->isInstanceOf(Simple::class);

                // Re-get the data from the cache
                $people = People::find([
                    'limit' => 35,
                    'cache' => [
                        'key' => $key
                    ]
                ]);

                $number = 0;
                foreach ($people as $individual) {
                    expect($individual)->isInstanceOf(People::class);
                    $number++;
                }

                expect($number)->equals(35);
            }
        );
    }
}
