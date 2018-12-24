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

namespace Phalcon\Test\Unit\Cache\Backend\File;

use Phalcon\Cache\Exception;
use Phalcon\Test\Fixtures\Traits\Cache\FileTrait;
use UnitTester;

/**
 * Class DecrementCest
 */
class DecrementCest
{
    use FileTrait;

    /**
     * Tests Phalcon\Cache\Backend\File :: decrement()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cacheBackendFileDecrement(UnitTester $I)
    {
        $I->wantToTest("Cache\Backend\File - decrement()");
        $I->skipTest("Need implementation");
    }

    /**
     * Tests Phalcon\Cache\Backend\File :: decrement() - non numeric
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-12-02
     */
    public function cacheBackendFileDecrementNonNumeric(UnitTester $I)
    {
        $I->wantToTest("Cache\Backend\File - decrement() - exception non numeric");
        $I->expectThrowable(
            new Exception('The cache value is not numeric, therefore could not decrement it'),
            function () {
                $this->cache->save('foo', "a");
                $this->cache->decrement('foo', 1);
            }
        );
    }
}
