<?php
/**
 * Unit.php
 * Phalcon_Flash_Direct_Helper_Unit
 *
 * Helper for the \Phalcon\Flash\Direct component
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2012 Phalcon Team
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

namespace Phalcon\Test\Flash\Direct\Helper;

use \Phalcon\Flash\Direct as PhFlash;
use \Phalcon\Test\UnitTestCase as PhTestUnitTestCase;

class Unit extends PhTestUnitTestCase
{

    private $notImplicit = false;
    private $notHtml     = false;
    private $classes     = null;
    private $default     = array(
                                'success' => 'successMessage',
                                'notice'  => 'noticeMessage',
                                'warning' => 'warningMessage',
                                'error'   => 'errorMessage',
                            );

    /**
     * Sets the custom classes for the tests
     * 
     * @param $classes
     * 
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    protected function setClasses($classes)
    {
        $this->classes = $classes;
    }

    /**
     * Tests error (implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testErrorStringImplicitFlushHtml()
    {
        $this->stringTest('error');
    }

    /**
     * Tests success (implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testSuccessStringImplicitFlushHtml()
    {
        $this->stringTest('success');
    }

    /**
     * Tests notice (implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testNoticeStringImplicitFlushHtml()
    {
        $this->stringTest('notice');
    }

    /**
     * Tests warning (implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testWarningStringImplicitFlushHtml()
    {
        $this->stringTest('warning');
    }

    /**
     * Tests error array of messages (implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testErrorArrayImplicitFlushHtml()
    {
        $this->arrayTest('error');
    }

    /**
     * Tests success array of messages (implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testSuccessArrayImplicitFlushHtml()
    {
        $this->arrayTest('success');
    }

    /**
     * Tests notice array of messages (implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testNoticeArrayImplicitFlushHtml()
    {
        $this->arrayTest('notice');
    }

    /**
     * Tests warning array of messages (implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testWarningArrayImplicitFlushHtml()
    {
        $this->arrayTest('warning');
    }

    /**
     * Tests error (no implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testErrorStringNoImplicitFlushHtml()
    {
        $this->notImplicit = true;
        $this->stringTest('error');
        $this->notImplicit = false;
    }

    /**
     * Tests success (no implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testSuccessStringNoImplicitFlushHtml()
    {
        $this->notImplicit = true;
        $this->stringTest('success');
        $this->notImplicit = false;
    }

    /**
     * Tests notice (no implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testNoticeStringNoImplicitFlushHtml()
    {
        $this->notImplicit = true;
        $this->stringTest('notice');
        $this->notImplicit = false;
    }

    /**
     * Tests warning (no implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testWarningStringNoImplicitFlushHtml()
    {
        $this->notImplicit = true;
        $this->stringTest('warning');
        $this->notImplicit = false;
    }

    /**
     * Tests error array of messages (no implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testErrorArrayNoImplicitFlushHtml()
    {
        $this->notImplicit = true;
        $this->arrayTest('error');
        $this->notImplicit = false;
    }

    /**
     * Tests success array of messages (no implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testSuccessArrayNoImplicitFlushHtml()
    {
        $this->notImplicit = true;
        $this->arrayTest('success');
        $this->notImplicit = false;
    }

    /**
     * Tests notice array of messages (no implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testNoticeArrayNoImplicitFlushHtml()
    {
        $this->notImplicit = true;
        $this->arrayTest('notice');
        $this->notImplicit = false;
    }

    /**
     * Tests warning array of messages (no implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testWarningArrayNoImplicitFlushHtml()
    {
        $this->notImplicit = true;
        $this->arrayTest('warning');
        $this->notImplicit = false;
    }

    /**
     * Tests error (implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testErrorStringImplicitFlushNoHtml()
    {
        $this->notHtml = true;
        $this->stringTest('error');
        $this->notHtml = false;
    }

    /**
     * Tests success (implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testSuccessStringImplicitFlushNoHtml()
    {
        $this->notHtml = true;
        $this->stringTest('success');
        $this->notHtml = false;
    }

    /**
     * Tests notice (implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testNoticeStringImplicitFlushNoHtml()
    {
        $this->notHtml = true;
        $this->stringTest('notice');
        $this->notHtml = false;
    }

    /**
     * Tests warning (implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testWarningStringImplicitFlushNoHtml()
    {
        $this->notHtml = true;
        $this->stringTest('warning');
        $this->notHtml = false;
    }

    /**
     * Tests error array of messages (implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testErrorArrayImplicitFlushNoHtml()
    {
        $this->notHtml = true;
        $this->arrayTest('error');
        $this->notHtml = false;
    }

    /**
     * Tests success array of messages (implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testSuccessArrayImplicitFlushNoHtml()
    {
        $this->notHtml = true;
        $this->arrayTest('success');
        $this->notHtml = false;
    }

    /**
     * Tests notice array of messages (implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testNoticeArrayImplicitFlushNoHtml()
    {
        $this->notHtml = true;
        $this->arrayTest('notice');
        $this->notHtml = false;
    }

    /**
     * Tests warning array of messages (implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testWarningArrayImplicitFlushNoHtml()
    {
        $this->notHtml = true;
        $this->arrayTest('warning');
        $this->notHtml = false;
    }

    /**
     * Tests error (no implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testErrorStringNoImplicitFlushNoHtml()
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
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testSuccessStringNoImplicitFlushNoHtml()
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
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testNoticeStringNoImplicitFlushNoHtml()
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
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testWarningStringNoImplicitFlushNoHtml()
    {
        $this->notHtml     = true;
        $this->notImplicit = true;
        $this->stringTest('warning');
        $this->notHtml     = false;
        $this->notImplicit = false;
    }

    /**
     * Tests error array of messages (no implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testErrorArrayNoImplicitFlushNoHtml()
    {
        $this->notHtml     = true;
        $this->notImplicit = true;
        $this->arrayTest('error');
        $this->notHtml     = false;
        $this->notImplicit = false;
    }

    /**
     * Tests success array of messages (no implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testSuccessArrayNoImplicitFlushNoHtml()
    {
        $this->notHtml     = true;
        $this->notImplicit = true;
        $this->arrayTest('success');
        $this->notHtml     = false;
        $this->notImplicit = false;
    }

    /**
     * Tests notice array of messages (no implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testNoticeArrayNoImplicitFlushNoHtml()
    {
        $this->notHtml     = true;
        $this->notImplicit = true;
        $this->arrayTest('notice');
        $this->notHtml     = false;
        $this->notImplicit = false;
    }

    /**
     * Tests warning array of messages (no implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testWarningArrayNoImplicitFlushNoHtml()
    {
        $this->notHtml     = true;
        $this->notImplicit = true;
        $this->arrayTest('warning');
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
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
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
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
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
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    private function stringTest($function)
    {
        $flash    = new PhFlash($this->classes);
        $class    = $this->getClass($function);
        $implicit = '';
        $html     = '';
        $template = '<div%s>%s</div>' . PHP_EOL;
        $message  = 'sample message';

        if ($this->notHtml) {
            $flash->setAutomaticHtml(false);
            $html     = ' no HTML';
            $expected = $message;
        } else {
            $expected = sprintf($template, $class, $message);
        }


        if ($this->notImplicit) {
            $flash->setImplicitFlush(false);
            $implicit = ' no implicit';
            $actual   = $flash->$function($message);
        } else {
            $actual = $this->getObResponse($flash, $function, $message);
        }

        $this->assertEquals(
            $expected,
            $actual,
            "Flash\\Direct {$function} (string){$implicit}{$html} does not produce the correct message"
        );
    }

    /**
     * Private function that tests an array with implicit flush Html
     *
     * @param $function
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    private function arrayTest($function)
    {
        $flash    = new PhFlash($this->classes);
        $class    = $this->getClass($function);
        $implicit = '';
        $html     = '';
        $template = '<div%s>%s</div>' . PHP_EOL;
        $message  = array(
            'sample message 1',
            'sample message 2',
        );

        if ($this->notHtml) {
            $flash->setAutomaticHtml(false);
            $html = ' no HTML';
            $expected = $message[0]
                      . $message[1];
        } else {
            $expected = sprintf($template, $class, $message[0])
                      . sprintf($template, $class, $message[1]);
        }

        if ($this->notImplicit) {
            $flash->setImplicitFlush(false);
            $implicit = ' no implicit';
            $actual   = $flash->$function($message);
        } else {
            $actual = $this->getObResponse($flash, $function, $message);
        }

        $this->assertEquals(
            $expected,
            $actual,
            "Flash\\Direct {$function} (array){$implicit}{$html} does not produce the correct message"
        );
    }
}
