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

use Exception;
use Phalcon\Test\Fixtures\Traits\Cache\FileTrait;
use UnitTester;

class SaveCest
{
    use FileTrait;

    /**
     * Tests Phalcon\Cache\Backend\File :: save()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cacheBackendFileSave(UnitTester $I)
    {
        $I->wantToTest('Cache\Backend\File - save()');
        $I->skipTest('Need implementation');
    }

    /**
     * Tests Phalcon\Cache\Backend\File :: save() - exception negative lifetime
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-12-02
     */
    public function cacheBackendFileSaveNegativeLifetime(UnitTester $I)
    {
        $I->wantToTest("Cache\Backend\File - save() - exception negative lifetime");
        $I->expectThrowable(
            new Exception('A non-numeric value encountered', 2),
            function () {
                $this->cache->save('foo', "a" - 1);
            }
        );
    }
}
