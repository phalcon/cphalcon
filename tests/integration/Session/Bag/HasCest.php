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

/**
 * Class HasCest
 *
 * @package Phalcon\Tests\Integration\Session\Bag
 */
class HasCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Bag :: has()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function sessionBagHas(IntegrationTester $I)
    {
        $I->wantToTest('Session\Bag - has()');

        $this->setNewFactoryDefault();
        $this->setDiService('sessionStream');
        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $collection = new Bag($this->container->get("session"), 'BagTest');
        $collection->init($data);

        $actual = $collection->has('three');
        $I->assertTrue($actual);

        $actual = $collection->has('THREE');
        $I->assertTrue($actual);

        $actual = $collection->has(uniqid());
        $I->assertFalse($actual);

        $actual = isset($collection['three']);
        $I->assertTrue($actual);

        $actual = isset($collection[uniqid()]);
        $I->assertFalse($actual);

        $actual = $collection->offsetExists('three');
        $I->assertTrue($actual);

        $actual = $collection->offsetExists(uniqid());
        $I->assertFalse($actual);
    }
}
