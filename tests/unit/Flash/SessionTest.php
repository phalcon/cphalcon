<?php

namespace Phalcon\Test\Unit\Flash;

use Codeception\Lib\Connector\PhalconMemorySession;
use Phalcon\Test\Proxy\Flash\Session;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Di;

/**
 * \Phalcon\Test\Unit\Flash\SessionTest
 * Tests the Phalcon\Flash\Session component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Flash
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class SessionTest extends UnitTest
{
    /**
     * @var array
     */
    protected $classes = [
        'success' => 'successMessage',
        'notice'  => 'noticeMessage',
        'warning' => 'warningMessage',
        'error'   => 'errorMessage',
    ];

    /**
     * Return flash instance
     */
    protected function getFlash()
    {
        $flash = new Session($this->classes);
        $di = new Di();
        $di->setShared('session', new PhalconMemorySession());
        $flash->setDI($di);

        return $flash;
    }

    /**
     * Test getMessages with specified type and removal
     * activated, only removes the received messages.
     *
     * @author Iván Guillén <zeopix@gmail.com>
     * @since  2015-10-26
     */
    public function testGetMessagesTypeRemoveMessages()
    {
        $this->specify(
            "The getMessages() method removes incorrectly after fetching from session",
            function () {
                $flash = $this->getFlash();

                $flash->success('sample success');
                $flash->error('sample error');

                $expectedSuccessMessages = ['sample success'];

                $actualSuccessMessages = $flash->getMessages('success');

                expect($actualSuccessMessages)->equals($expectedSuccessMessages);

                $expectedErrorMessages = ['sample error'];
                $actualErrorMessages = $flash->getMessages('error');

                expect($actualErrorMessages)->equals($expectedErrorMessages);

                verify_not($flash->getMessages());
            }
        );
    }

    /**
     * Tests clear method
     *
     * @author Iván Guillén <zeopix@gmail.com>
     * @since  2015-10-26
     */
    public function testClearMessagesFormSession()
    {
        $this->specify(
            "The clear() method clear messages from session incorrectly",
            function () {
                $flash = $this->getFlash();

                ob_start();
                $flash->output();
                $flash->success('sample message');
                $flash->clear();
                $actual = ob_get_contents();
                ob_end_clean();
                $expected = '';

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Test output formatted messages
     *
     * @author Iván Guillén <zeopix@gmail.com>
     * @since  2015-10-26
     */
    public function testMessageFormat()
    {
        $this->specify(
            "The output() method outputs formatted messages incorrectly",
            function ($function) {
                $flash = $this->getFlash();
                $template = ' class="%s"';
                $class = sprintf($template, $this->classes[$function]);

                $template = '<div%s>%s</div>' . PHP_EOL;
                $message  = 'sample message';

                $expected = sprintf($template, $class, $message);
                ob_start();
                $flash->$function($message);
                $flash->output();
                $actual = ob_get_contents();
                ob_end_clean();

                expect($actual)->equals($expected);
            }, ['examples' => [
                'error'   => ['function' => 'error'],
                'success' => ['function' => 'success'],
                'notice'  => ['function' => 'notice'],
            ]]
        );
    }
}
