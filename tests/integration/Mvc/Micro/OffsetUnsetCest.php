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

namespace Phalcon\Tests\Integration\Mvc\Micro;

use IntegrationTester;
use Phalcon\Di;
use Phalcon\Escaper;
use Phalcon\Mvc\Micro;

class OffsetUnsetCest
{
    /**
     * Tests Phalcon\Mvc\Micro :: offsetUnset()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-22
     */
    public function mvcMicroOffsetUnset(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Micro - offsetUnset()');

        $micro = new Micro();

        $di = new Di();

        $micro->setDi($di);

        $escaper = new Escaper();

        $micro->setService('escaper', $escaper);

        $I->assertTrue(
            $micro->hasService('escaper')
        );

        unset(
            $micro['escaper']
        );

        $I->assertFalse(
            $micro->hasService('escaper')
        );
    }
}
