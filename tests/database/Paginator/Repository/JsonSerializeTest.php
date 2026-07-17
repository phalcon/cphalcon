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

namespace Phalcon\Tests\Database\Paginator\Repository;

use Phalcon\Paginator\Adapter\NativeArray;
use Phalcon\Paginator\Repository;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class JsonSerializeTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Paginator\Repository :: jsonSerialize()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-10-16
     */
    public function testPaginatorRepositoryJsonSerialize(): void
    {
        $data = [
            'key'  => 'value',
            'key1' => 'value1',
            'key2' => 'value2',
            'key3' => 'value3',
        ];

        $repository = new Repository();
        $repository->setProperties($data);

        $this->assertEquals(
            $data,
            $repository->jsonSerialize()
        );
    }

    /**
     * Tests Phalcon\Paginator\Repository :: jsonSerialize()
     *
     * @since 2019-10-16
     */
    public function testPaginatorRepositoryJsonSerializeWithAdapter(): void
    {
        $data = [
            'key'  => 'value',
            'key1' => 'value1',
            'key2' => 'value2',
            'key3' => 'value3',
        ];

        $expectedData = [
            'items'       => [
                'key'  => 'value',
                'key1' => 'value1',
            ],
            'total_items' => 4,
            'limit'       => 2,
            'first'       => 1,
            'previous'    => 1,
            'current'     => 1,
            'next'        => 2,
            'last'        => 2,
        ];

        $paginator = new NativeArray(
            [
                'data'  => $data,
                'limit' => 2,
                'page'  => 1,
            ]
        );

        $repository = $paginator->paginate();

        $this->assertEquals(
            $expectedData,
            $repository->jsonSerialize()
        );
    }
}
