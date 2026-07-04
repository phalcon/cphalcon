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
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class PaginateTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Paginator\Adapter\NativeArray :: paginate()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testPaginatorAdapterNativearrayPaginate(): void
    {
        $paginator = new NativeArray(
            [
                'data'  => array_fill(0, 30, 'banana'),
                'limit' => 25,
                'page'  => 1,
            ]
        );

        $page = $paginator->paginate();

        $this->assertInstanceOf(
            Repository::class,
            $page
        );

        $this->assertCount(25, $page->getItems());
        $this->assertEquals(1, $page->getPrevious());
        $this->assertEquals(2, $page->getNext());
        $this->assertEquals(2, $page->getLast());
        $this->assertEquals(25, $page->getLimit());
        $this->assertEquals(1, $page->getCurrent());
    }
}
