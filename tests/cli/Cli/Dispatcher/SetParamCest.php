<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Cli\Cli\Dispatcher;

use CliTester;
use Phalcon\Cli\Dispatcher;

class SetParamCest
{
    /**
     * Tests Phalcon\Cli\Dispatcher :: setParam()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-02
     */
    public function cliDispatcherSetParam(CliTester $I)
    {
        $I->wantToTest('Cli\Dispatcher - setParam()');

        $dispatcher = new Dispatcher();

        $dispatcher->setParam('a', 1);
        $dispatcher->setParam('b', '2');
        $dispatcher->setParam('c', 'three');

        $I->assertEquals(
            1,
            $dispatcher->getParam('a')
        );

        $I->assertEquals(
            '2',
            $dispatcher->getParam('b')
        );

        $I->assertEquals(
            'three',
            $dispatcher->getParam('c')
        );
    }
}
