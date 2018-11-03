<?php

namespace Phalcon\Test\Unit\Flash\Direct\Helper;

use Phalcon\Flash\Direct;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Flash\Direct\Helper\FlashBase
 * Tests the \Phalcon\Flash\Direct component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Flash\Direct\Helper
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class FlashBase extends UnitTest
{
    private $notImplicit = false;
    private $notHtml     = false;
    private $classes     = null;
    private $default     = [
        'success' => 'successMessage',
        'notice'  => 'noticeMessage',
        'warning' => 'warningMessage',
        'error'   => 'errorMessage',
    ];

    /**
     * Sets the custom classes for the tests
     *
     * @param $classes
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    protected function setClasses($classes)
    {
        $this->classes = $classes;
    }

    /**
     * Tests error (implicit flush)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testFlashDirectErrorImplicitFlushHtml()
    {
        $this->stringTest('error');
    }

    /**
     * Tests success (implicit flush)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testFlashDirectSuccessImplicitFlushHtml()
    {
        $this->stringTest('success');
    }

    /**
     * Tests notice (implicit flush)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testFlashDirectNoticeImplicitFlushHtml()
    {
        $this->stringTest('notice');
    }

    /**
     * Tests warning (implicit flush)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testFlashDirectWarningImplicitFlushHtml()
    {
        $this->stringTest('warning');
    }

    /**
     * Tests error (no implicit flush)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testFlashDirectErrorNoImplicitFlushHtml()
    {
        $this->notImplicit = true;
        $this->stringTest('error');
        $this->notImplicit = false;
    }

    /**
     * Tests success (no implicit flush)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testFlashDirectSuccessNoImplicitFlushHtml()
    {
        $this->notImplicit = true;
        $this->stringTest('success');
        $this->notImplicit = false;
    }

    /**
     * Tests notice (no implicit flush)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testFlashDirectNoticeNoImplicitFlushHtml()
    {
        $this->notImplicit = true;
        $this->stringTest('notice');
        $this->notImplicit = false;
    }

    /**
     * Tests warning (no implicit flush)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testFlashDirectWarningNoImplicitFlushHtml()
    {
        $this->notImplicit = true;
        $this->stringTest('warning');
        $this->notImplicit = false;
    }

    /**
     * Tests error (implicit flush no html)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testFlashDirectErrorImplicitFlushNoHtml()
    {
        $this->notHtml = true;
        $this->stringTest('error');
        $this->notHtml = false;
    }

    /**
     * Tests success (implicit flush no html)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testFlashDirectSuccessImplicitFlushNoHtml()
    {
        $this->notHtml = true;
        $this->stringTest('success');
        $this->notHtml = false;
    }

    /**
     * Tests notice (implicit flush no html)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testFlashDirectNoticeImplicitFlushNoHtml()
    {
        $this->notHtml = true;
        $this->stringTest('notice');
        $this->notHtml = false;
    }

    /**
     * Tests warning (implicit flush no html)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testFlashDirectWarningImplicitFlushNoHtml()
    {
        $this->notHtml = true;
        $this->stringTest('warning');
        $this->notHtml = false;
    }

    /**
     * Tests error (no implicit flush no html)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testFlashDirectErrorNoImplicitFlushNoHtml()
    {
        $this->notHtml     = true;
        $this->notImplicit = true;
        $this->stringTest('error');
        $this->notHtml     = false;
        $this->notImplicit = false;
    }

    /**
     * Tests success (no implicit flush no html)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testFlashDirectSuccessNoImplicitFlushNoHtml()
    {
        $this->notHtml     = true;
        $this->notImplicit = true;
        $this->stringTest('success');
        $this->notHtml     = false;
        $this->notImplicit = false;
    }

    /**
     * Tests notice (no implicit flush no html)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testFlashDirectNoticeNoImplicitFlushNoHtml()
    {
        $this->notHtml     = true;
        $this->notImplicit = true;
        $this->stringTest('notice');
        $this->notHtml     = false;
        $this->notImplicit = false;
    }

    /**
     * Tests warning (no implicit flush no html)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testFlashDirectWarningNoImplicitFlushNoHtml()
    {
        $this->notHtml     = true;
        $this->notImplicit = true;
        $this->stringTest('warning');
        $this->notHtml     = false;
        $this->notImplicit = false;
    }

    /**
     * Tests auto escaping
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @issue  https://github.com/phalcon/cphalcon/issues/11448
     * @since  2016-06-15
     */
    public function testFlashDirectWithAutoEscaping()
    {
        $flash = new Direct($this->classes);

        $flash->setAutomaticHtml(false);
        $flash->setImplicitFlush(false);

        expect($flash->success("<h1>Hello World!</h1>"))->equals('&lt;h1&gt;Hello World!&lt;/h1&gt;');

        $flash->setAutoescape(false);

        expect($flash->success("<h1>Hello World!</h1>"))->equals('<h1>Hello World!</h1>');
    }

    /**
     * Private function to get the class of the message depending on
     * the classes set
     *
     * @param $key
     *
     * @return string
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    private function getClass($key)
    {
        $template = ' class="%s"';

        if ([] === $this->classes) {
            $class = '';
        } else {
            $classes = (is_null($this->classes)) ?
                        $this->default           :
                        $this->classes;
            $class = sprintf($template, $classes[$key]);
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
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
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
     * Private function that tests a string with implicit flush Html
     *
     * @param $function
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    private function stringTest($function)
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
            $actual   = $flash->$function($message);
        } else {
            $actual = $this->getObResponse($flash, $function, $message);
        }

        expect($actual)->equals($expected);
    }
}
