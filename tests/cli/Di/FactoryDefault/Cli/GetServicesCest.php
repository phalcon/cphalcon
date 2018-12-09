<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Cli\Di\FactoryDefault\Cli;

use CliTester;

class GetServicesCest
{
    /**
     * Tests Phalcon\Di\FactoryDefault\Cli :: getServices()
     *
     * @param CliTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function diFactorydefaultCliGetServices(CliTester $I)
    {
        $I->wantToTest("Di\FactoryDefault\Cli - getServices()");
        $I->skipTest("Need implementation");
    }
}
