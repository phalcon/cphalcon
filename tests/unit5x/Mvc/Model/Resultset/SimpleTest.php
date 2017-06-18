<?php

namespace Phalcon\Test\Unit5x\Mvc\Model\Resultset;

use Phalcon\Di;
use Phalcon\Test\Models\Robots;
use Phalcon\Test\Models\People;
use Helper\ResultsetHelperTrait;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Mvc\Model\Resultset\Simple;

/**
 * Phalcon\Test\Unit5x\Mvc\Model\Resultset\SimpleTest
 * Tests the Phalcon\Mvc\Model\Resultset\Simple component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit5x\Mvc\Model\Resultset
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
     * Work with Simple Resultset by load data from cache (Memcache adapter).
     *
     * @test
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2013-01-03
     */
    public function shouldLoadResultsetFromMemcache()
    {
        $this->specify(
            'Unable to test Simple Resultset by using Memcache adapter',
            function () {
                $cache = $this->getMemcacheCache();
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
