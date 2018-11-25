<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Paginator\Adapter;

use UnitTester;

class GetPaginateCest
{
    /**
     * Tests Phalcon\Paginator\Adapter :: getPaginate()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function paginatorAdapterGetPaginate(UnitTester $I)
    {
        $I->wantToTest("Paginator\Adapter - getPaginate()");
        $I->skipTest("Need implementation");
    }
}
