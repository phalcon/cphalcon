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

namespace Phalcon\Test\Cli\Cli\Dispatcher;

use CliTester;

/**
 * Class SetOptionsCest
 */
class SetOptionsCest
{
    /**
     * Tests Phalcon\Cli\Dispatcher :: setOptions()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliDispatcherSetOptions(CliTester $I)
    {
        $I->wantToTest('Cli\Dispatcher - setOptions()');
        $I->skipTest('Need implementation');
    }
}
