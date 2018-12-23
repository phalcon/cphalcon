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

namespace Phalcon\Test\Integration\Paginator\Adapter\NativeArray;

use IntegrationTester;

/**
 * Class SetRepositoryCest
 */
class SetRepositoryCest
{
    /**
     * Tests Phalcon\Paginator\Adapter\NativeArray :: setRepository()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function paginatorAdapterNativearraySetRepository(IntegrationTester $I)
    {
        $I->wantToTest('Paginator\Adapter\NativeArray - setRepository()');
        $I->skipTest('Need implementation');
    }
}
