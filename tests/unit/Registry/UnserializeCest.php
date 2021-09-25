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

namespace Phalcon\Tests\Unit\Registry;

use Phalcon\Registry;
use UnitTester;

class UnserializeCest
{
    /**
     * Tests Phalcon\Registry :: unserialize()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function registryUnserialize(UnitTester $I)
    {
        $I->wantToTest('Registry - unserialize()');

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $serialized = serialize($data);

        $registry = new Registry();

        $registry->unserialize($serialized);

        $I->assertEquals(
            $data,
            $registry->toArray()
        );
    }
}
