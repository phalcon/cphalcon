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
 * Class SetCest
 */
class SetCest
{
    use DiTrait;
    use SessionBagTrait;

    /**
     * Tests Phalcon\Session\Bag :: set()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionBagSet(IntegrationTester $I)
    {
        $I->wantToTest('Session\Bag - set()');
        $collection = new Bag('BagTest');

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
