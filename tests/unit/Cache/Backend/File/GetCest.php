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
 * Class GetCest
 */
class GetCest
{
    use FileTrait;

    /**
     * Tests Phalcon\Cache\Backend\File :: get()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cacheBackendFileGet(UnitTester $I)
    {
        $I->wantToTest("Cache\Backend\File - get()");
        $I->skipTest("Need implementation");
    }

    /**
     * Tests Phalcon\Cache\Backend\File :: get() - exception negative lifetime
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-12-02
     */
    public function cacheBackendFileGetNegativeLifetime(UnitTester $I)
    {
        $I->wantToTest("Cache\Backend\File - get() - exception negative lifetime");
        $I->expectThrowable(
            new Exception('The lifetime must be at least 1 second'),
            function () {
                $this->cache->save('foo', "1");
                $this->cache->get('foo', -1);
            }
        );
    }

    /**
     * Tests Phalcon\Cache\Backend\File :: get() - non existent
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-12-02
     */
    public function cacheBackendFileGetNonExistent(UnitTester $I)
    {
        $I->wantToTest("Cache\Backend\File - get() - non existent");
        /**
         * Just in case
         */
        if (true === $this->cache->exists('foo')) {
            $this->cache->delete('foo');
        }

        $actual = $this->cache->get('foo');
        $I->assertNull($actual);
    }
}
