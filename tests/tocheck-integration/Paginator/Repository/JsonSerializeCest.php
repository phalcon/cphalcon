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

namespace Phalcon\Test\Integration\Paginator\Repository;

use IntegrationTester;
use Phalcon\Paginator\Adapter\NativeArray;
use Phalcon\Paginator\Repository;

class JsonSerializeCest
{
    /**
     * Tests Phalcon\Paginator\Repository :: jsonSerialize()
     *
     * @param IntegrationTester $I
     *
     * @since 2019-10-16
     */
    public function paginatorRepositoryJsonSerialize(IntegrationTester $I)
    {
        $I->wantToTest('Paginator\Repository - jsonSerialize()');

        $data = [
            'key'  => 'value',
            'key1' => 'value1',
            'key2' => 'value2',
            'key3' => 'value3',
        ];

        $repository = new Repository();
        $repository->setProperties($data);

        $I->assertEquals(
            $data,
            $repository->jsonSerialize()
        );
    }

    /**
     * Tests Phalcon\Paginator\Repository :: jsonSerialize()
     *
     * @param IntegrationTester $I
     *
     * @since 2019-10-16
     */
    public function paginatorRepositoryJsonSerializeWithAdapter(IntegrationTester $I)
    {
        $I->wantToTest('Paginator\Repository - jsonSerialize() - with adapter');

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

        $I->assertEquals(
            $expectedData,
            $repository->jsonSerialize()
        );
    }
}
