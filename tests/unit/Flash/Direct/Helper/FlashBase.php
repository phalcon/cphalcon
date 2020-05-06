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

namespace Phalcon\Test\Unit\Flash\Direct\Helper;

use Phalcon\Escaper;
use Phalcon\Flash\AbstractFlash;
use Phalcon\Flash\Direct;
use UnitTester;

class FlashBase
{
    private $classes     = [];
    private $notHtml     = false;
    private $notImplicit = false;

    private $default = [
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
    }

    /**
     * Tests warning (implicit flush)
     *
     * @param  UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-04
     */
    public function testFlashDirectImplicitFlushHtml(UnitTester $I)
    {
        $functions = [
            'error',
            'success',
            'notice',
            'warning',
        ];

        foreach ($functions as $function) {
            $this->stringTest($I, $function);
        }
    }

    /**
     * Tests a string with implicit flush Html
     *
     * @param  UnitTester $I
     * @param  string     $function
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-04
     */
    private function stringTest(UnitTester $I, string $function)
    {
        $flash = new Direct(new Escaper());
        $flash->setCssClasses($this->classes);

        $message = 'sample message';

        if ($this->notHtml) {
            $flash->setAutomaticHtml(false);

            $expected = $message;
        } else {
            $expected = sprintf(
                '<div%s>%s</div>' . PHP_EOL,
                $this->getClass($function),
                $message
            );
        }

        if ($this->notImplicit) {
            $flash->setImplicitFlush(false);

            $actual = $flash->$function($message);
        } else {
            $actual = $this->getObResponse($flash, $function, $message);
        }

        $I->assertEquals($expected, $actual);
    }

    /**
     * Private function to get the class of the message depending on the classes
     * set
     *
     * @param  string $key
     * @return string
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-04
     */
    private function getClass(string $key): string
    {
        $template = ' class="%s"';

        if ([] === $this->classes) {
            $class = '';
        } else {
            $classes = (is_null($this->classes)) ?
                $this->default :
                $this->classes;
            $class   = sprintf($template, $classes[$key]);
        }

        return $class;
    }

    /**
     * Private function to start the ob, call the function, get the
     * contents and clean the ob
     *
     * @param  AbstractFlash $flash
     * @param  string        $function
     * @param  string        $message
     * @return string
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-04
     */
    private function getObResponse(AbstractFlash $flash, string $function, string $message): string
    {
        ob_start();
        $flash->$function($message);
        $actual = ob_get_contents();
        ob_end_clean();

        return $actual;
    }

    /**
     * Tests warning (no implicit flush)
     *
     * @param  UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-04
     */
    public function testFlashDirectNoImplicitFlushHtml(UnitTester $I)
    {
        $functions = [
            'error',
            'success',
            'notice',
            'warning',
        ];

        foreach ($functions as $function) {
            $this->notImplicit = true;

            $this->stringTest($I, $function);

            $this->notImplicit = false;
        }
    }

    /**
     * Tests warning (implicit flush no html)
     *
     * @param  UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-04
     */
    public function testFlashDirectImplicitFlushNoHtml(UnitTester $I)
    {
        $functions = [
            'error',
            'success',
            'notice',
            'warning',
        ];

        foreach ($functions as $function) {
            $this->notHtml = true;

            $this->stringTest($I, $function);

            $this->notHtml = false;
        }
    }

    /**
     * Tests error (no implicit flush no html)
     *
     * @param  UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-04
     */
    public function testFlashDirectNoImplicitFlushNoHtml(UnitTester $I)
    {
        $functions = [
            'error',
            'success',
            'notice',
            'warning',
        ];

        foreach ($functions as $function) {
            $this->notHtml     = true;
            $this->notImplicit = true;

            $this->stringTest($I, $function);

            $this->notHtml     = false;
            $this->notImplicit = false;
        }
    }

    /**
     * Tests auto escaping
     *
     * @param  UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @issue  https://github.com/phalcon/cphalcon/issues/11448
     * @since  2016-06-15
     */
    public function testFlashDirectWithAutoEscaping(UnitTester $I)
    {
        $flash = new Direct(new Escaper());
        $flash->setCssClasses($this->classes);

        $flash->setAutomaticHtml(false);
        $flash->setImplicitFlush(false);

        $I->assertEquals(
            '&lt;h1&gt;Hello World!&lt;/h1&gt;',
            $flash->success('<h1>Hello World!</h1>')
        );

        $flash->setAutoescape(false);

        $I->assertEquals(
            '<h1>Hello World!</h1>',
            $flash->success('<h1>Hello World!</h1>')
        );
    }

    /**
     * Sets the custom classes for the tests
     *
     * @param  array $classes
     * @return void
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-04
     */
    protected function setClasses(array $classes): void
    {
        $this->classes = $classes;
    }
}
