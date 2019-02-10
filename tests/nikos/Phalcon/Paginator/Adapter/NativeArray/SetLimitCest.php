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

namespace Phalcon\Test\Unit\Paginator\Adapter\NativeArray;

use UnitTester;

/**
 * Class SetLimitCest
 */
class SetLimitCest
{
    /**
     * Tests Phalcon\Paginator\Adapter\NativeArray :: setLimit()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function paginatorAdapterNativeArraySetLimit(UnitTester $I)
    {
        $I->wantToTest('Paginator\Adapter\NativeArray - setLimit()');
        $I->skipTest('Need implementation');
    }
}
