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

namespace Phalcon\Test\Integration\Session\Bag;

use IntegrationTester;
use Phalcon\Session\Bag;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\SessionBagTrait;

class HasCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiService('sessionStream');
    }

    /**
     * Tests Phalcon\Session\Bag :: has()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function sessionBagHas(IntegrationTester $I)
    {
        $I->wantToTest('Session\Bag - has()');
        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $collection = new Bag('BagTest');
        $collection->init($data);

        $actual = $collection->has('three');
        $I->assertTrue($actual);

        $actual = $collection->has('THREE');
        $I->assertTrue($actual);

        $actual = $collection->has('unknown');
        $I->assertFalse($actual);

        $actual = isset($collection['three']);
        $I->assertTrue($actual);

        $actual = isset($collection['unknown']);
        $I->assertFalse($actual);

        $actual = $collection->offsetExists('three');
        $I->assertTrue($actual);

        $actual = $collection->offsetExists('unknown');
        $I->assertFalse($actual);
    }
}
