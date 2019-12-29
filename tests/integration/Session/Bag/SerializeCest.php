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

class SerializeCest
{
    use DiTrait;
    use SessionBagTrait;

    /**
     * Tests Phalcon\Session\Bag :: serialize()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function sessionBagSerialize(IntegrationTester $I)
    {
        $I->wantToTest('Session\Bag - serialize()');

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $collection = new Bag('BagTest');

        $collection->init($data);

        $I->assertEquals(
            serialize($data),
            $collection->serialize()
        );
    }
}
