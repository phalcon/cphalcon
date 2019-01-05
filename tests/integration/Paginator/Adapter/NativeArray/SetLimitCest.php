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
use Phalcon\Paginator\Adapter\NativeArray;

/**
 * Class SetLimitCest
 */
class SetLimitCest
{
    /**
     * Tests Phalcon\Paginator\Adapter\NativeArray :: setLimit()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function paginatorAdapterNativearraySetLimit(IntegrationTester $I)
    {
        $I->wantToTest('Paginator\Adapter\NativeArray - setLimit()');
        $paginator = new NativeArray(
            [
                'data'  => array_fill(0, 30, 'banana'),
                'limit' => 25,
                'page'  => 1,
            ]
        );

        $expected = 25;
        $actual   = $paginator->getLimit();
        $I->assertEquals($expected, $actual);

        $paginator->setLimit(10);

        $expected = 10;
        $actual   = $paginator->getLimit();
        $I->assertEquals($expected, $actual);
    }
}
