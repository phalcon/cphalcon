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
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
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
