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

use BadMethodCallException;
use IntegrationTester;
use Phalcon\Paginator\Adapter\NativeArray;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Paginator\Adapter\NativeArray :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function paginatorAdapterNativearrayConstruct(IntegrationTester $I)
    {
        $I->wantToTest('Paginator\Adapter\NativeArray - __construct()');

        $I->expectThrowable(
            new BadMethodCallException('Wrong number of parameters'),
            function () {
                $paginator = new NativeArray();
            }
        );
    }
}
