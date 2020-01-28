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

namespace Phalcon\Test\Unit\Di;

use Phalcon\Crypt;
use Phalcon\Di;
use Phalcon\Escaper;
use UnitTester;

class GetSetDefaultCest
{
    /**
     * Tests Phalcon\Di :: getDefault() / setDefault()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-02
     */
    public function diGetDefault(UnitTester $I)
    {
        $I->wantToTest('Di - getDefault() / setDefault()');

        $di1 = new Di();

        $di1->set('crypt', Crypt::class);

        $di2 = new Di();

        $di2->set('escaper', Escaper::class);

        Di::setDefault($di1);

        $I->assertSame(
            $di1,
            Di::getDefault()
        );

        Di::setDefault($di2);

        $I->assertSame(
            $di2,
            Di::getDefault()
        );
    }
}
