<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Logger\Adapter;

use Phalcon\Logger\Adapter\Firephp;
use UnitTester;

class FirephpCest
{
    /**
     * executed before each test
     */
    public function _before(UnitTester $I)
    {
        $I->checkExtensionIsLoaded('xdebug');
    }

    /**
     * Tests logging by using Firephp
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-28
     */
    public function testLoggerAdapterFirephpCreationDefault(UnitTester $I)
    {
        $logger = new Firephp();
        $logger->getFormatter()->setShowBacktrace(false);
        $logger->info('Some firephp simple test');

        $headers = xdebug_get_headers();

        $expected = 'X-Wf-Protocol-1: http://meta.wildfirehq.org/Protocol/JsonStream/0.2';
        $actual   = $headers;
        $I->assertContains($expected, $actual);
        $expected = 'X-Wf-1-Plugin-1: http://meta.firephp.org/Wildfire/Plugin/FirePHP/Library-FirePHPCore/0.3';
        $actual   = $headers;
        $I->assertContains($expected, $actual);
        $expected = 'X-Wf-Structure-1: http://meta.firephp.org/Wildfire/Structure/FirePHP/FirebugConsole/0.1';
        $actual   = $headers;
        $I->assertContains($expected, $actual);
        $expected = 'X-Wf-1-1-1-1: 55|[{"Type":"INFO","Label":"Some firephp simple test"},""]|';
        $actual   = $headers;
        $I->assertContains($expected, $actual);
    }
}
