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
 * Class SetCest
 *
 * @package Phalcon\Tests\Integration\Session\Bag
 */
class SetCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Bag :: set()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function sessionBagSet(IntegrationTester $I)
    {
        $I->wantToTest('Session\Bag - set()');

        $this->setNewFactoryDefault();
        $this->setDiService('sessionStream');
        $collection = new Bag($this->container->get("session"), 'BagTest');

        $collection->set('three', 'two');
        $expected = 'two';
        $actual   = $collection->get('three');
        $I->assertEquals($expected, $actual);

        $collection->three = 'Phalcon';
        $expected          = 'Phalcon';
        $actual            = $collection->get('three');
        $I->assertEquals($expected, $actual);

        $collection->offsetSet('three', 123);
        $expected = 123;
        $actual   = $collection->get('three');
        $I->assertEquals($expected, $actual);

        $collection['three'] = true;
        $actual              = $collection->get('three');
        $I->assertTrue($actual);
    }
}
