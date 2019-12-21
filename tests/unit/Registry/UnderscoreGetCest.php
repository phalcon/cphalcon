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

namespace Phalcon\Test\Unit\Registry;

use Phalcon\Registry;
use UnitTester;

class UnderscoreGetCest
{
    /**
     * Unit Tests Phalcon\Registry :: __get()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-25
     */
    public function registryUnderscoreGet(UnitTester $I)
    {
        $I->wantToTest('Registry - __get()');

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $registry = new Registry($data);

        $I->assertEquals(
            'four',
            $registry->three
        );
    }
}
