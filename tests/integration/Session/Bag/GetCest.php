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

use IntegrationTester;
use Phalcon\Session\Bag;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\SessionBagTrait;

/**
 * Class GetCest
 */
class GetCest
{
    use DiTrait;
    use SessionBagTrait;

    /**
     * Tests Phalcon\Session\Bag :: get()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionBagGet(IntegrationTester $I)
    {
        $I->wantToTest('Session\Bag - get()');
        $data       = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];
        $collection = new Bag('BagTest');
        $collection->init($data);

        $expected = 'four';
        $actual   = $collection->get('three');
        $I->assertEquals($expected, $actual);

        $actual = $collection->get('THREE');
        $I->assertEquals($expected, $actual);

        $actual = $collection['three'];
        $I->assertEquals($expected, $actual);

        $actual = $collection->three;
        $I->assertEquals($expected, $actual);

        $actual = $collection->offsetGet('three');
        $I->assertEquals($expected, $actual);
    }
}
