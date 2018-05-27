<?php

namespace Phalcon\Test\Unit\Flash;

use Phalcon\Di;
use Phalcon\Escaper;
use Phalcon\Flash\Session;
use Phalcon\Test\Module\UnitTest;
use Codeception\Lib\Connector\Phalcon\MemorySession;

/**
 * \Phalcon\Test\Unit\Flash\SessionTest
 * Tests the Phalcon\Flash\Session component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Flash
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
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

        $di->setShared('session', new MemorySession());
        $di->setShared('escaper', new Escaper());

        $flash->setDI($di);

        return $flash;
    }

    /**
     * Tests auto escaping
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @issue  https://github.com/phalcon/cphalcon/issues/11448
     * @since  2016-06-15
     */
    public function testShouldAutoEscapeHtml()
    {
        $this->specify(
            "The output() method outputs HTML incorrectly",
            function ($function) {
                $flash = $this->getFlash();

                $flash->setAutoescape(false);
                $flash->$function("<script>alert('This will execute as JavaScript!')</script>");
                expect($flash->getMessages($function))
                    ->equals(["<script>alert('This will execute as JavaScript!')</script>"]);

                ob_start();
                $flash->$function("<script>alert('This will execute as JavaScript!')</script>");
                $flash->output();
                $actual = ob_get_contents();
                ob_end_clean();

                expect($actual)
                    ->equals("<div class=\"{$function}Message\"><script>alert('This will execute as JavaScript!')</script></div>" . PHP_EOL);

                $flash->setAutoescape(true);
                $flash->$function("<script>alert('This will execute as JavaScript!')</script>");
                expect($flash->getMessages($function))
                    ->equals(["<script>alert('This will execute as JavaScript!')</script>"]);

                ob_start();
                $flash->$function("<script>alert('This will execute as JavaScript!')</script>");
                $flash->output();
                $actual = ob_get_contents();
                ob_end_clean();

                expect($actual)
                    ->equals("<div class=\"{$function}Message\">&lt;script&gt;alert(&#039;This will execute as JavaScript!&#039;)&lt;/script&gt;</div>" . PHP_EOL);
            },
            [
                'examples' => [
                    ['error'],
                    ['success'],
                    ['notice'],
                    ['warning'],
                ]
            ]
        );
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
     * Tests getMessages in case of non existent type request
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/11941
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-07-03
     */
    public function testGetNonExistentType()
    {
        $this->specify(
            'The getMessages() method does not return an empty array in case of non existent type request',
            function () {
                $flash = $this->getFlash();
                $flash->error('sample error');

                expect($flash->getMessages('success', false))->equals([]);
                verify_that(count($flash->getMessages()) === 1);
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
            },
            [
                'examples' => [
                    'error'   => ['function' => 'error'],
                    'success' => ['function' => 'success'],
                    'notice'  => ['function' => 'notice'],
                ]
            ]
        );
    }
}
