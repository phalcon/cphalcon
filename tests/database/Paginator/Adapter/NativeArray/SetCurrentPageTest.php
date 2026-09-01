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
final class SetCurrentPageTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Paginator\Adapter\NativeArray :: setCurrentPage()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testPaginatorAdapterNativearraySetCurrentPage(): void
    {
        $data = [];
        for ($counter = 0; $counter < 30; $counter++) {
            $data[] = 'banana-' . $counter;
        }
        $paginator = new NativeArray(
            [
                'data'  => $data,
                'limit' => 10,
                'page'  => 1,
            ]
        );

        $paginator->setCurrentPage(2);
        $page = $paginator->paginate();

        $this->assertInstanceOf(Repository::class, $page);

        $this->assertCount(10, $page->items);
        $this->assertEquals(1, $page->previous);
        $this->assertEquals(3, $page->next);
        $this->assertEquals(3, $page->last);
        $this->assertEquals(10, $page->limit);
        $this->assertEquals(2, $page->current);
        $this->assertEquals(30, $page->total_items);
    }
}
