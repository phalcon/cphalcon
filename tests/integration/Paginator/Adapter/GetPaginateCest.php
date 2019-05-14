<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Paginator\Adapter;

use IntegrationTester;

class GetPaginateCest
{
    /**
     * Tests Phalcon\Paginator\Adapter :: paginate()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function paginatorAdapterPaginate(IntegrationTester $I)
    {
        $I->wantToTest("Paginator\Adapter - paginate()");
        $I->skipTest('Need implementation');
    }
}
