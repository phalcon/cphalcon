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

namespace Phalcon\Test\Integration\Paginator\Adapter\NativeArray;

use IntegrationTester;
use Phalcon\Paginator\Adapter\NativeArray;
use Phalcon\Paginator\Repository;
use Phalcon\Test\Fixtures\Paginator\Store;
use function array_fill;

/**
 * Class GetSetRepositoryCest
 */
class GetSetRepositoryCest
{
    /**
     * Tests Phalcon\Paginator\Adapter\NativeArray :: getRepository()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function paginatorAdapterNativearraySetRepository(IntegrationTester $I)
    {
        $I->wantToTest('Paginator\Adapter\NativeArray - getRepository()');

        $paginator = new NativeArray(
            [
                'data'  => array_fill(0, 30, 'banana'),
                'limit' => 25,
                'page'  => 1,
            ]
        );

        $result = $paginator->paginate();
        $I->assertInstanceOf(Repository::class, $result);
    }

    /**
     * Tests Phalcon\Paginator\Adapter\NativeArray :: setRepository()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function paginatorAdapterNativearrayGetSetRepository(IntegrationTester $I)
    {
        $I->wantToTest('Paginator\Adapter\NativeArray - getRepository()/setRepository()');

        $paginator = new NativeArray(
            [
                'data'  => array_fill(0, 30, 'banana'),
                'limit' => 25,
                'page'  => 1,
            ]
        );

        $repository = new Store();
        $paginator->setRepository($repository);
        $result = $paginator->paginate();
        $I->assertInstanceOf(Store::class, $result);
    }
}
