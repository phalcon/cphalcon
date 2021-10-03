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

class SetCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiService('sessionStream');
    }

    /**
     * Tests Phalcon\Session\Bag :: set()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function sessionBagSet(IntegrationTester $I)
    {
        $I->wantToTest('Session\Bag - set()');

        $collection = new Bag('BagTest', $this->container);

        $collection->set('three', 'two');

        $expected = 'two';
        $actual   = $collection->get('three');
        $I->assertEquals($expected, $actual);

        $collection->three = 'Phalcon';

        $expected = 'Phalcon';
        $actual   = $collection->get('three');
        $I->assertEquals($expected, $actual);

        $collection->offsetSet('three', 123);

        $expected = 123;
        $actual   = $collection->get('three');
        $I->assertEquals($expected, $actual);

        $collection['three'] = true;

        $actual = $collection->get('three');
        $I->assertTrue($actual);
    }
}
