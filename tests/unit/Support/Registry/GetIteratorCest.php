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

namespace Phalcon\Tests\Unit\Support\Registry;

use Phalcon\Support\Registry;
use UnitTester;

class GetIteratorCest
{
    /**
     * Tests Phalcon\Support\Registry :: getIterator()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function registryGetIterator(UnitTester $I)
    {
        $I->wantToTest('Registry - getIterator()');

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $registry = new Registry($data);

        foreach ($registry as $key => $value) {
            $I->assertEquals(
                $data[$key],
                $registry[$key]
            );
        }
    }
}
