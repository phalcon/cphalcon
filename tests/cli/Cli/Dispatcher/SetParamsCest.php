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

class SetParamsCest
{
    /**
     * Tests Phalcon\Cli\Dispatcher :: setParams()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-02
     */
    public function cliDispatcherSetParams(CliTester $I)
    {
        $I->wantToTest('Cli\Dispatcher - setParams()');

        $dispatcher = new Dispatcher();

        $params = [
            'a' => 1,
            'b' => '2',
            'c' => 'three',
        ];

        $dispatcher->setParams($params);

        $I->assertEquals(
            $params,
            $dispatcher->getParams()
        );
    }
}
