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

namespace Phalcon\Test\Unit\Flash\Direct\Helper;

use Phalcon\Flash\Direct;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

class FlashBase
{
    use DiTrait;

    private $notImplicit = false;
    private $notHtml     = false;
    private $classes     = null;
    private $default     = [
        'success' => 'successMessage',
        'notice'  => 'noticeMessage',
        'warning' => 'warningMessage',
        'error'   => 'errorMessage',
    ];

    public function _before(UnitTester $I)
    {
        $this->newDi();
        $this->setDiEscaper();
    }

    /**
     * Tests warning (implicit flush)
     *
     * @author Phalcon Team <team@phalconphp.com>
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
     * Private function that tests a string with implicit flush Html
     *
     * @param \UnitTester $I
     * @param string      $function
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    private function stringTest(UnitTester $I, $function)
    {
        $flash    = new Direct($this->classes);
        $class    = $this->getClass($function);
        $template = '<div%s>%s</div>' . PHP_EOL;
        $message  = 'sample message';

        if ($this->notHtml) {
            $flash->setAutomaticHtml(false);
            $expected = $message;
        } else {
            $expected = sprintf($template, $class, $message);
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
     * Private function to get the class of the message depending on
     * the classes set
     *
     * @param $key
     *
     * @return string
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    private function getClass($key)
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
     * @param $flash
     * @param $function
     * @param $message
     *
     * @return string
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    private function getObResponse($flash, $function, $message)
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
     * @author Phalcon Team <team@phalconphp.com>
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
     * @author Phalcon Team <team@phalconphp.com>
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
     * @author Phalcon Team <team@phalconphp.com>
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
     * @author Phalcon Team <team@phalconphp.com>
     * @issue  https://github.com/phalcon/cphalcon/issues/11448
     * @since  2016-06-15
     */
    public function testFlashDirectWithAutoEscaping(UnitTester $I)
    {
        $flash = new Direct($this->classes);

        $flash->setAutomaticHtml(false);
        $flash->setImplicitFlush(false);

        $expected = '&lt;h1&gt;Hello World!&lt;/h1&gt;';
        $actual   = $flash->success("<h1>Hello World!</h1>");
        $I->assertEquals($expected, $actual);

        $flash->setAutoescape(false);

        $expected = '<h1>Hello World!</h1>';
        $actual   = $flash->success("<h1>Hello World!</h1>");
        $I->assertEquals($expected, $actual);
    }

    /**
     * Sets the custom classes for the tests
     *
     * @param $classes
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    protected function setClasses($classes)
    {
        $this->classes = $classes;
    }
}
