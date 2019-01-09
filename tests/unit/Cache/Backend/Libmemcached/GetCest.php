<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Cache\Backend\Libmemcached;

use Phalcon\Cache\Frontend\None;
use Phalcon\Test\Fixtures\Traits\Cache\LibmemcachedTrait;
use UnitTester;

/**
 * Class GetCest
 */
class GetCest
{
    use LibmemcachedTrait;

    /**
     * Tests Phalcon\Cache\Backend\Libmemcached :: get()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cacheBackendLibmemcachedGet(UnitTester $I)
    {
        $I->wantToTest('Cache\Backend\Libmemcached - get()');

        $key  = 'data-get';
        $data = [uniqid(), gethostname(), microtime(), get_include_path(), time()];

        $cache = $this->getDataCache();

        $I->haveInLibmemcached($key, serialize($data));
        $I->assertEquals($data, $cache->get('data-get'));

        $I->assertNull($cache->get('non-existent-key'));

        $data = 'sure, nothing interesting';

        $I->haveInLibmemcached($key, serialize($data));
        $I->assertEquals($data, $cache->get('data-get'));

        $I->assertNull($cache->get('non-existent-key-2'));
    }

    /**
     * If an empty value is stored, it is returned instead of null always
     *
     * @param UnitTester $I
     *
     * @issue https://github.com/phalcon/cphalcon/issue/13947
     *
     * @author Cameron Hall <me@chall.id.au>
     * @since  2018-01-05
     */
    public function cacheBackendLibmemcachedGetEmptyValuesInsteadOfNull(UnitTester $I)
    {
        $I->wantToTest('Cache\Backend\Libmemcached - get() - return empty value vs null [#13497]');
        $cache = $this->getCache(new None());

        $cache->save('empty.array', []);
        $I->assertEquals([], $cache->get('empty.array'));

        $cache->save('empty.int', 0);
        $I->assertEquals(0, $cache->get('empty.int'));

        $cache->save('empty.string', '');
        $I->assertEquals('', $cache->get('empty.string'));

        $cache->save('empty.bool', false);
        $I->assertFalse($cache->get('empty.bool'));

        $I->assertNull($cache->get('valuethatdoesnotexist'));

        $cache->save('empty.null', null);
        $I->assertNull($cache->get('null'));
    }

    /**
     * Return the same result irrespective of number of requests
     *
     * @param UnitTester $I
     *
     * @issue https://github.com/phalcon/cphalcon/issue/13092
     *
     * @author Cameron Hall <me@chall.id.au>
     * @since  2018-01-05
     */
    public function cacheBackendLibmemcachedGetSameValueRegardlessOfTheNumberOfRequests(UnitTester $I)
    {
        $I->wantTo('Cache\Backend\Libmemcached - get() - Same data regardless of the number of requests');

        $key  = 'libmemcached-data-get-test';
        $data = 'this is a test';

        $cache = $this->getDataCache();

        $I->haveInLibmemcached($key, serialize($data));

        $I->assertEquals($data, $cache->get($key));
        $I->assertEquals($data, $cache->get($key));
        $I->assertEquals($data, $cache->get($key));
        $I->assertEquals($data, $cache->get($key));
        $I->assertEquals($data, $cache->get($key));
        $I->assertEquals($data, $cache->get($key));
        $I->assertEquals($data, $cache->get($key));
        $I->assertEquals($data, $cache->get($key));
        $I->assertEquals($data, $cache->get($key));
        $I->assertEquals($data, $cache->get($key));
    }
}
