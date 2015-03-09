<?php
/**
 * FlashBase.php
 * \Phalcon\Flash\Direct\Helper\FlashBase
 *
 * Tests the \Phalcon\Tag component
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Tests\unit\Phalcon\Flash\Direct\Helper;

use \PhalconTest\Flash\Direct as PhFlash;

use \Phalcon\Tests\unit\Phalcon\_Helper\TestsBase as TBase;

class FlashBase extends TBase
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

        if ($this->classes === array()) {
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
        $flash    = new PhFlash($this->classes);
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
