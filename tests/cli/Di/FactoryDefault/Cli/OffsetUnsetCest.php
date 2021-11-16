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

namespace Phalcon\Tests\Cli\Di\FactoryDefault\Cli;

use CliTester;
use Phalcon\Di\FactoryDefault\Cli as Di;
use Phalcon\Html\Escaper;

class OffsetUnsetCest
{
    /**
     * Tests Phalcon\Di\FactoryDefault\Cli :: offsetUnset()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function diFactorydefaultCliOffsetUnset(CliTester $I)
    {
        $I->wantToTest('Di\FactoryDefault\Cli - offsetUnset()');

        $di = new Di();

        $escaper = new Escaper();

        $di->set('escaper', $escaper);

        $I->assertTrue(
            $di->has('escaper')
        );

        unset(
            $di['escaper']
        );

        $I->assertFalse(
            $di->has('escaper')
        );
    }
}
