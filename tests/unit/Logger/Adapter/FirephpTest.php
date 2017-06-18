<?php

namespace Phalcon\Test\Unit\Logger\Adapter;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Logger\Adapter\Firephp;

/**
 * \Phalcon\Test\Unit\Logger\Adapter\FirephpTest
 * Tests the \Phalcon\Logger\Adapter\Firephp component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Logger\Adapter
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class FirephpTest extends UnitTest
{
    /**
     * executed before each test
     */
    public function _before()
    {
        parent::_before();

        if (!extension_loaded('xdebug')) {
            $this->markTestSkipped('Warning: xdebug extension is not loaded');
        }
    }

    /**
     * Tests logging by using Firephp
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-28
     */
    public function testLoggerAdapterFirephpCreationDefault()
    {
        $this->specify(
            'logging by using Firephp does not work correctly',
            function () {
                $logger = new Firephp();
                $logger->getFormatter()->setShowBacktrace(false);
                $logger->info('Some firephp simple test');

                $headers = xdebug_get_headers();

                expect($headers)->contains('X-Wf-Protocol-1: http://meta.wildfirehq.org/Protocol/JsonStream/0.2');
                expect($headers)->contains('X-Wf-1-Plugin-1: http://meta.firephp.org/Wildfire/Plugin/FirePHP/Library-FirePHPCore/0.3');
                expect($headers)->contains('X-Wf-Structure-1: http://meta.firephp.org/Wildfire/Structure/FirePHP/FirebugConsole/0.1');
                expect($headers)->contains('X-Wf-1-1-1-1: 55|[{"Type":"INFO","Label":"Some firephp simple test"},""]|');
            }
        );
    }
}
