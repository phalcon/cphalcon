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

namespace Phalcon\Tests\Integration\Paginator\PaginatorFactory;

use IntegrationTester;
use Phalcon\Paginator\Adapter\AdapterInterface;
use Phalcon\Paginator\Adapter\NativeArray;
use Phalcon\Paginator\PaginatorFactory;

class NewInstanceCest
{
    /**
     * Tests Phalcon\Paginator\AdapterFactory :: newInstance()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-18
     */
    public function paginatorAdapterFactoryNewInstance(IntegrationTester $I)
    {
        $I->wantToTest('Paginator\AdapterFactory - newInstance()');

        $factory = new PaginatorFactory();

        $adapter = $factory->newInstance('nativeArray');

        $I->assertInstanceOf(
            NativeArray::class,
            $adapter
        );

        $I->assertInstanceOf(
            AdapterInterface::class,
            $adapter
        );
    }
}
