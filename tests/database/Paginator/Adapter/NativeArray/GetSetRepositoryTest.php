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

namespace Phalcon\Tests\Database\Paginator\Adapter\NativeArray;

use Phalcon\Paginator\Adapter\NativeArray;
use Phalcon\Paginator\Repository;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Paginator\Store;

use PHPUnit\Framework\Attributes\Group;

use function array_fill;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class GetSetRepositoryTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Paginator\Adapter\NativeArray :: setRepository()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testPaginatorAdapterNativearrayGetSetRepository(): void
    {
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
        $this->assertInstanceOf(Store::class, $result);
    }

    /**
     * Tests Phalcon\Paginator\Adapter\NativeArray :: getRepository()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testPaginatorAdapterNativearraySetRepository(): void
    {
        $paginator = new NativeArray(
            [
                'data'  => array_fill(0, 30, 'banana'),
                'limit' => 25,
                'page'  => 1,
            ]
        );

        $result = $paginator->paginate();
        $this->assertInstanceOf(Repository::class, $result);
    }
}
