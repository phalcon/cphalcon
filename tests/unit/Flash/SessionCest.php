<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Flash;

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
        $this->setDiEscaper();
        $this->setDiSessionFiles();
    }


    /**
     * Tests auto escaping
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @issue  https://github.com/phalcon/cphalcon/issues/11448
     * @since  2016-06-15
     */
    public function testShouldAutoEscapeHtml(UnitTester $I)
    {
        /**
         * @TODO Check the session
         */
        $I->skipTest('TODO: Check the session');
        $examples = [
            'error',
            'success',
            'notice',
            'warning',
        ];
        foreach ($examples as $function) {
            $flash = $this->getFlash();

            $flash->setAutoescape(false);
            $flash->$function("<script>alert('This will execute as JavaScript!')</script>");

            $expected = ["<script>alert('This will execute as JavaScript!')</script>"];
            $actual   = $flash->getMessages($function);
            $I->assertEquals($expected, $actual);

            ob_start();
            $flash->$function("<script>alert('This will execute as JavaScript!')</script>");
            $flash->output();
            $actual = ob_get_contents();
            ob_end_clean();

            $expected = "<div class=\"{$function}Message\">"
                . "<script>alert('This will execute as JavaScript!')</script></div>" . PHP_EOL;
            $I->assertEquals($expected, $actual);

            $flash->setAutoescape(true);
            $flash->$function("<script>alert('This will execute as JavaScript!')</script>");
            $expected = ["<script>alert('This will execute as JavaScript!')</script>"];
            $actual   = $flash->getMessages($function);
            $I->assertEquals($expected, $actual);

            ob_start();
            $flash->$function("<script>alert('This will execute as JavaScript!')</script>");
            $flash->output();
            $actual = ob_get_contents();
            ob_end_clean();

            $expected = "<div class=\"{$function}Message\">&lt;script&gt;alert(&#039;"
                . "This will execute as JavaScript!&#039;)&lt;/script&gt;</div>" . PHP_EOL;
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Return flash instance
     */
    protected function getFlash()
    {
        $container = $this->getDi();
        $flash     = new Session($this->classes);
        $flash->setDI($container);

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
        /**
         * @TODO Check the session
         */
        $I->skipTest('TODO: Check the session');
        $flash = $this->getFlash();

        $flash->success('sample success');
        $flash->error('sample error');

        $expected = ['sample success'];
        $actual   = $flash->getMessages('success');
        $I->assertEquals($expected, $actual);

        $expected = ['sample error'];
        $actual   = $flash->getMessages('error');
        $I->assertEquals($expected, $actual);

        $actual = $flash->getMessages();
        $I->assertEmpty($actual);
    }

    /**
     * Tests getMessages in case of non existent type request
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/11941
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-07-03
     */
    public function testGetNonExistentType(UnitTester $I)
    {
        /**
         * @TODO Check the session
         */
        $I->skipTest('TODO: Check the session');
        $flash = $this->getFlash();
        $flash->error('sample error');

        $expected = [];
        $actual   = $flash->getMessages('success', false);
        $I->assertEquals($expected, $actual);

        $expected = 1;
        $actual   = count($flash->getMessages());
        $I->assertTrue($expected === $actual);
    }

    /**
     * Tests clear method
     *
     * @author Iván Guillén <zeopix@gmail.com>
     * @since  2015-10-26
     */
    public function testClearMessagesFormSession(UnitTester $I)
    {
        /**
         * @TODO Check the session
         */
        $I->skipTest('TODO: Check the session');
        $flash = $this->getFlash();

        ob_start();
        $flash->output();
        $flash->success('sample message');
        $flash->clear();
        $actual = ob_get_contents();
        ob_end_clean();
        $expected = '';

        $I->assertEquals($expected, $actual);
    }

    /**
     * Test output formatted messages
     *
     * @author Iván Guillén <zeopix@gmail.com>
     * @since  2015-10-26
     */
    public function testMessageFormat(UnitTester $I)
    {
        /**
         * @TODO Check the session
         */
        $I->skipTest('TODO: Check the session');
        $examples = [
            'error',
            'success',
            'notice',
        ];

        foreach ($examples as $function) {
            $flash    = $this->getFlash();
            $template = ' class="%s"';
            $class    = sprintf($template, $this->classes[$function]);

            $template = '<div%s>%s</div>' . PHP_EOL;
            $message  = 'sample message';

            $expected = sprintf($template, $class, $message);
            ob_start();
            $flash->$function($message);
            $flash->output();
            $actual = ob_get_contents();
            ob_end_clean();

            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Test custom template getter/setter
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @issue  https://github.com/phalcon/cphalcon/issues/13445
     * @since  2018-10-16
     */
    public function testCustomTemplateGetterSetter(UnitTester $I)
    {
        $flash    = $this->getFlash();
        $template = '<span class="%cssClasses%">%message%</span>';
        $flash->setCustomTemplate($template);

        $expected = $template;
        $actual   = $flash->getCustomTemplate();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Test custom message
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @issue  https://github.com/phalcon/cphalcon/issues/13445
     * @since  2018-10-16
     */
    public function testCustomFormat(UnitTester $I)
    {
        /**
         * @TODO Check the session
         */
        $I->skipTest('TODO: Check the session');
        $flash    = $this->getFlash();
        $template = '<span class="%cssClass%" aria-label="clickme">%message%</span>';
        $flash->setCustomTemplate($template);

        $message  = 'sample message';
        $expected = '<span class="successMessage" aria-label="clickme">sample message</span>';
        ob_start();
        $flash->success($message);
        $flash->output();
        $actual = ob_get_contents();
        ob_end_clean();

        $I->assertEquals($expected, $actual);
    }
}
