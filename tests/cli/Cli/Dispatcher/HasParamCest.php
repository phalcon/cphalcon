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
use Phalcon\Cli\Dispatcher;

class HasParamCest
{
    /**
     * Tests Phalcon\Cli\Dispatcher :: hasParam()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-02
     */
    public function cliDispatcherHasParam(CliTester $I)
    {
        $I->wantToTest('Cli\Dispatcher - hasParam()');

        $dispatcher = new Dispatcher();

        $dispatcher->setParams(
            [
                'a' => 1,
                'b' => '2',
                'c' => 'three',
            ]
        );

        $I->assertTrue(
            $dispatcher->hasParam('a')
        );

        $I->assertTrue(
            $dispatcher->hasParam('b')
        );

        $I->assertTrue(
            $dispatcher->hasParam('c')
        );

        $I->assertFalse(
            $dispatcher->hasParam('d')
        );
    }
}
