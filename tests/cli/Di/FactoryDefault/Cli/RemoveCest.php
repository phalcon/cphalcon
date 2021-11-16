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

class RemoveCest
{
    /**
     * Tests Phalcon\Di\FactoryDefault\Cli :: remove()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function diFactorydefaultCliRemove(CliTester $I)
    {
        $I->wantToTest('Di\FactoryDefault\Cli - remove()');

        $di = new Di();

        $di->set('escaper', Escaper::class);

        $I->assertTrue(
            $di->has('escaper')
        );

        $di->remove('escaper');

        $I->assertFalse(
            $di->has('escaper')
        );
    }
}
