<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Paginator\Adapter\Model;

use UnitTester;

class PaginateCest
{
    /**
     * Tests Phalcon\Paginator\Adapter\Model :: paginate()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function paginatorAdapterModelPaginate(UnitTester $I)
    {
        $I->wantToTest("Paginator\Adapter\Model - paginate()");
        $I->skipTest("Need implementation");
    }
}
