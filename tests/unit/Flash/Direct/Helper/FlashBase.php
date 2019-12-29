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
use Phalcon\Flash\Direct;
use UnitTester;

class FlashBase
{
    private $classes     = null;
    private $notHtml     = false;
    private $notImplicit = false;

    private $default = [
        'success' => 'successMessage',
        'notice'  => 'noticeMessage',
        'warning' => 'warningMessage',
        'error'   => 'errorMessage',
    ];

    public function _before(UnitTester $I)
    {
    }

    /**
     * Tests warning (implicit flush)
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-04
     */
    private function getClass($key): string
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-04
     */
    private function getObResponse($flash, $function, $message): string
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-04
     */
    protected function setClasses($classes)
    {
        $this->classes = $classes;
    }
}
