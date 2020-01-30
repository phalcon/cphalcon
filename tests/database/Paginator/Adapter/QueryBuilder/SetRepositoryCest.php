<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Database\Paginator\Adapter\QueryBuilder;

use DatabaseTester;

/**
 * Class SetRepositoryCest
 */
class SetRepositoryCest
{
    /**
     * Tests Phalcon\Paginator\Adapter\QueryBuilder :: setRepository()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function paginatorAdapterQuerybuilderSetRepository(DatabaseTester $I)
    {
        $I->wantToTest('Paginator\Adapter\QueryBuilder - setRepository()');
        $I->skipTest('Need implementation');
    }
}
