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

namespace Phalcon\Test\Unit\Session\Adapter\Libmemcached;

use UnitTester;

/**
 * Class WriteCest
 */
class WriteCest
{
    /**
     * Tests Phalcon\Session\Adapter\Libmemcached :: write()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionAdapterLibmemcachedWrite(UnitTester $I)
    {
        $I->wantToTest('Session\Adapter\Libmemcached - write()');
        $I->skipTest('Need implementation');
    }
}
