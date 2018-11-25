<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Mvc\Model\MetaData\Libmemcached;

use UnitTester;

class GetColumnMapCest
{
    /**
     * Tests Phalcon\Mvc\Model\MetaData\Libmemcached :: getColumnMap()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelMetadataLibmemcachedGetColumnMap(UnitTester $I)
    {
        $I->wantToTest("Mvc\Model\MetaData\Libmemcached - getColumnMap()");
        $I->skipTest("Need implementation");
    }
}
