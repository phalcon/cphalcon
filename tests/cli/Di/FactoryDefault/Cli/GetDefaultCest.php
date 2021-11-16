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

class GetDefaultCest
{
    /**
     * Tests Phalcon\Di\FactoryDefault\Cli :: getDefault()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function diFactorydefaultCliGetDefault(CliTester $I)
    {
        $I->wantToTest('Di\FactoryDefault\Cli - getDefault()');

        // there is a DI container
        $I->assertInstanceOf(Di::class, Di::getDefault());

        $di = Di::getDefault();

        // delete it
        Di::reset();

        $I->assertNull(Di::getDefault());

        // set it again
        Di::setDefault($di);

        $I->assertInstanceOf(Di::class, Di::getDefault());
    }
}
