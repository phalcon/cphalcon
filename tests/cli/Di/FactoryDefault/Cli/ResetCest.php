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

namespace Phalcon\Test\Cli\Di\FactoryDefault\Cli;

use CliTester;

class ResetCest
{
    /**
     * Tests Phalcon\Di\FactoryDefault\Cli :: reset()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function diFactorydefaultCliReset(CliTester $I)
    {
        $I->wantToTest('Di\FactoryDefault\Cli - reset()');
        $I->skipTest('Need implementation');
    }
}
