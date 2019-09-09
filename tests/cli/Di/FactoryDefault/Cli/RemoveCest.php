<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Cli\Di\FactoryDefault\Cli;

use CliTester;

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
        $I->skipTest('Need implementation');
    }
}
