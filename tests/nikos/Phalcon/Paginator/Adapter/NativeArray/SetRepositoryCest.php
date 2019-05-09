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

class SetRepositoryCest
{
    /**
     * Tests Phalcon\Paginator\Adapter\NativeArray :: setRepository()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function paginatorAdapterNativeArraySetRepository(UnitTester $I)
    {
        $I->wantToTest('Paginator\Adapter\NativeArray - setRepository()');

        $I->skipTest('Need implementation');
    }
}
