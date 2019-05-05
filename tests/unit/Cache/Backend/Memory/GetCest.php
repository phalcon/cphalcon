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

namespace Phalcon\Test\Unit\Cache\Backend\Memory;

use UnitTester;

class GetCest
{
    /**
     * Tests Phalcon\Cache\Backend\Memory :: get()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cacheBackendMemoryGet(UnitTester $I)
    {
        $I->wantToTest('Cache\Backend\Memory - get()');

        $I->skipTest('Need implementation');
    }
}
