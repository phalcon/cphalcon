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

namespace Phalcon\Tests\Integration\Session\Bag;

use IntegrationTester;
use Phalcon\Session\Bag;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Fixtures\Traits\SessionBagTrait;

class GetCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiService('sessionStream');
    }

    /**
     * Tests Phalcon\Session\Bag :: get()
     *
     * @author Phalcon Team <team@phalcon.io>
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
