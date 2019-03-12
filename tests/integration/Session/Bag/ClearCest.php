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

namespace Phalcon\Test\Integration\Session\Bag;

use Phalcon\Session\Bag;
use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\SessionBagTrait;

/**
 * Class ClearCest
 */
class ClearCest
{
    use DiTrait;
    use SessionBagTrait;

    /**
     * Tests Phalcon\Session\Bag :: clear()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionBagClear(IntegrationTester $I)
    {
        $I->wantToTest('Session\Bag - clear()');
        $data       = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];
        $collection = new Bag('BagTest');
        $collection->init($data);

        $expected = $data;
        $actual   = $collection->toArray();
        $I->assertEquals($expected, $actual);

        $collection->clear();
        $expected = 0;
        $actual   = $collection->count();
        $I->assertEquals($expected, $actual);
    }
}
