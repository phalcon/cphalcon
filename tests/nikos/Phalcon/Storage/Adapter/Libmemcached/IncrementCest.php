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

namespace Phalcon\Test\Unit\Storage\Adapter\Libmemcached;

use UnitTester;

class IncrementCest
{
    /**
     * Tests Phalcon\Storage\Adapter\Libmemcached :: increment()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function storageAdapterLibmemcachedIncrement(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Libmemcached - increment()');

        $I->skipTest('Need implementation');
    }
}
