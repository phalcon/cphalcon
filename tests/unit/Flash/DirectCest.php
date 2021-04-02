<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Flash;

use Codeception\Example;
use Phalcon\Flash\Direct;
use Phalcon\Storage\Exception;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

class DirectCest
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

    /**
     * Executed before each test
     *
     * @param  UnitTester $I
     * @return void
     */
    public function _before(UnitTester $I): void
    {
        $this->newDi();

        try {
            $this->setDiService('escaper');
        } catch (Exception $e) {
            $I->fail($e->getMessage());
        }
    }

    /**
     * Tests auto escaping
     *
     * @param  UnitTester $I
     * @param  Example $example
     *
     * @author Phalcon Team <team@phalcon.io>
     * @issue  https://github.com/phalcon/cphalcon/issues/11448
     * @since  2016-06-15
     *
     * @dataProvider testShouldAutoEscapeHtmlProvider
     */
    public function testShouldAutoEscapeHtml(UnitTester $I, Example $example)
    {
        $function = $example[0];

        $flash = $this->getFlash();


        $flash->setAutoescape(false);

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

        $flash = new Direct();
        $flash->setDI($container);
        $flash->setCssClasses($this->classes);

        return $flash;
    }

    /**
     * Test output formatted messages
     *
     * @param  UnitTester $I
     * @param  Example $example
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
     * @param  UnitTester $I
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

        ob_start();
        $flash->success($message);
        $flash->output();
        $actual = ob_get_contents();
        ob_end_clean();

        $I->assertEquals(
            '<span class="successMessage" aria-label="clickme">sample message</span>',
            $actual
        );
    }
}
