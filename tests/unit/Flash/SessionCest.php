<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Flash;

use Codeception\Example;
use Phalcon\Flash\Session;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

class SessionCest
{
    use DiTrait;

    /**
     * @var array
     */
    protected $classes = [
        'success' => 'successMessage',
        'notice'  => 'noticeMessage',
        'warning' => 'warningMessage',
        'error'   => 'errorMessage',
    ];

    public function _before(UnitTester $I)
    {
        $this->newDi();
        $this->setDiService('escaper');
        $this->setDiService('sessionStream');

        if (PHP_SESSION_ACTIVE !== session_status()) {
            session_start();
        }

        if (!isset($_SESSION)) {
            $_SESSION = [];
        }
    }

    public function _after(UnitTester $I)
    {
        session_destroy();
    }


    /**
     * Tests auto escaping
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @issue  https://github.com/phalcon/cphalcon/issues/11448
     * @since        2016-06-15
     *
     * @dataProvider testShouldAutoEscapeHtmlProvider
     */
    public function testShouldAutoEscapeHtml(UnitTester $I, Example $example)
    {
        $function = $example[0];

        $flash = $this->getFlash();


        $flash->setAutoescape(false);

        $message = "<script>alert('This will execute as JavaScript!')</script>";

        $flash->$function($message);

        $I->assertEquals(
            [
                $message,
            ],
            $flash->getMessages($function)
        );


        ob_start();
        $flash->$function(
            "<script>alert('This will execute as JavaScript!')</script>"
        );
        $flash->output();
        $actual = ob_get_contents();
        ob_end_clean();

        $I->assertEquals(
            "<div class=\"{$function}Message\">" .
            "<script>alert('This will execute as JavaScript!')</script></div>" . PHP_EOL,
            $actual
        );


        $flash->setAutoescape(true);

        $message = "<script>alert('This will execute as JavaScript!')</script>";

        $flash->$function($message);

        $I->assertEquals(
            [
                $message,
            ],
            $flash->getMessages($function)
        );


        ob_start();
        $flash->$function(
            "<script>alert('This will execute as JavaScript!')</script>"
        );
        $flash->output();
        $actual = ob_get_contents();
        ob_end_clean();

        $I->assertEquals(
            "<div class=\"{$function}Message\">" .
            "&lt;script&gt;alert(&#039;This will execute as JavaScript!" .
            "&#039;)&lt;/script&gt;</div>" . PHP_EOL,
            $actual
        );
    }

    private function testShouldAutoEscapeHtmlProvider(): array
    {
        return [
            ['error'],
            ['success'],
            ['notice'],
            ['warning'],
        ];
    }

    /**
     * Return flash instance
     */
    protected function getFlash()
    {
        $container = $this->getDi();

        $flash = new Session();
        $flash->setDI($container);
        $flash->setCssClasses($this->classes);

        return $flash;
    }

    /**
     * Test getMessages with specified type and removal
     * activated, only removes the received messages.
     *
     * @author Iván Guillén <zeopix@gmail.com>
     * @since  2015-10-26
     */
    public function testGetMessagesTypeRemoveMessages(UnitTester $I)
    {
        $flash = $this->getFlash();

        $flash->success('sample success');
        $flash->error('sample error');

        $I->assertEquals(
            [
                'sample success',
            ],
            $flash->getMessages('success')
        );

        $I->assertEquals(
            [
                'sample error',
            ],
            $flash->getMessages('error')
        );

        $I->assertEmpty(
            $flash->getMessages()
        );
    }

    /**
     * Tests getMessages in case of non existent type request
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/11941
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-07-03
     */
    public function testGetNonExistentType(UnitTester $I)
    {
        $flash = $this->getFlash();

        $flash->error('sample error');

        $I->assertEquals(
            [],
            $flash->getMessages('success', false)
        );

        $I->assertCount(
            1,
            $flash->getMessages()
        );
    }

    /**
     * Tests clear method
     *
     * @author Iván Guillén <zeopix@gmail.com>
     * @since  2015-10-26
     */
    public function testClearMessagesFormSession(UnitTester $I)
    {
        $flash = $this->getFlash();

        ob_start();
        $flash->output();
        $flash->success('sample message');
        $flash->clear();
        $actual = ob_get_contents();
        ob_end_clean();

        $I->assertEquals(
            '',
            $actual
        );
    }

    /**
     * Test output formatted messages
     *
     * @author       Iván Guillén <zeopix@gmail.com>
     * @since        2015-10-26
     *
     * @dataProvider testMessageFormatProvider
     */
    public function testMessageFormat(UnitTester $I, Example $example)
    {
        $function = $example[0];

        $flash = $this->getFlash();

        $class = sprintf(
            ' class="%s"',
            $this->classes[$function]
        );

        $message = 'sample message';

        $expected = sprintf(
            '<div%s>%s</div>' . PHP_EOL,
            $class,
            $message
        );

        ob_start();
        $flash->$function($message);
        $flash->output();
        $actual = ob_get_contents();
        ob_end_clean();

        $I->assertEquals($expected, $actual);
    }

    private function testMessageFormatProvider(): array
    {
        return [
            ['error'],
            ['success'],
            ['notice'],
        ];
    }

    /**
     * Test custom message
     *
     * @author Phalcon Team <team@phalcon.io>
     * @issue  https://github.com/phalcon/cphalcon/issues/13445
     * @since  2018-10-16
     */
    public function testCustomFormat(UnitTester $I)
    {
        $flash = $this->getFlash();

        $template = '<span class="%cssClass%" aria-label="clickme">%message%</span>';

        $flash->setCustomTemplate($template);

        $message = 'sample message';

        $flash->success($message);

        ob_start();
        $flash->output();
        $actual = ob_get_contents();
        ob_end_clean();

        $I->assertEquals(
            '<span class="successMessage" aria-label="clickme">sample message</span>',
            $actual
        );
    }
}
