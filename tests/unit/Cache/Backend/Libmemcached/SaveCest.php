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

use Phalcon\Test\Fixtures\Traits\Cache\LibmemcachedTrait;
use UnitTester;

/**
 * Class SaveCest
 */
class SaveCest
{
    use LibmemcachedTrait;

    /**
     * Tests Phalcon\Cache\Backend\Libmemcached :: save()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cacheBackendLibmemcachedSave(UnitTester $I)
    {
        $I->wantToTest('Cache\Backend\Libmemcached - save()');

        $key  = 'data-save';
        $data = [uniqid(), gethostname(), microtime(), get_include_path(), time()];

        $cache = $this->getDataCache();

        $I->dontSeeInLibmemcached($key);
        $cache->save('data-save', $data);

        $I->seeInLibmemcached($key, serialize($data));

        $data = 'sure, nothing interesting';

        $I->dontSeeInLibmemcached('non-existent-key');

        $cache->save('data-save', $data);
        $I->seeInLibmemcached($key, serialize($data));
    }
}
