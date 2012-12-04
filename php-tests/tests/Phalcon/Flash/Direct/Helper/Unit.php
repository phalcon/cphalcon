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
 * @author    Eduar Carvajal <eduar@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@niden.net>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

use \Phalcon\Flash\Direct as Flash;

class Flash_Direct_Helper_Unit extends Phalcon_Test_UnitTestCase
{

    private $_notImplicit = false;
    private $_notHtml     = false;
    private $_classes     = null;
    private $_default     = array(
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
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    protected function setClasses($classes)
    {
        $this->_classes = $classes;
    }

    /**
     * Tests error (implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testErrorStringImplicitFlushHtml()
    {
        $this->_stringTest('error');
    }

    /**
     * Tests success (implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testSuccessStringImplicitFlushHtml()
    {
        $this->_stringTest('success');
    }

    /**
     * Tests notice (implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testNoticeStringImplicitFlushHtml()
    {
        $this->_stringTest('notice');
    }

    /**
     * Tests warning (implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testWarningStringImplicitFlushHtml()
    {
        $this->_stringTest('warning');
    }

    /**
     * Tests error array of messages (implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testErrorArrayImplicitFlushHtml()
    {
        $this->_arrayTest('error');
    }

    /**
     * Tests success array of messages (implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testSuccessArrayImplicitFlushHtml()
    {
        $this->_arrayTest('success');
    }

    /**
     * Tests notice array of messages (implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testNoticeArrayImplicitFlushHtml()
    {
        $this->_arrayTest('notice');
    }

    /**
     * Tests warning array of messages (implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testWarningArrayImplicitFlushHtml()
    {
        $this->_arrayTest('warning');
    }

    /**
     * Tests error (no implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testErrorStringNoImplicitFlushHtml()
    {
        $this->_notImplicit = true;
        $this->_stringTest('error');
        $this->_notImplicit = false;
    }

    /**
     * Tests success (no implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testSuccessStringNoImplicitFlushHtml()
    {
        $this->_notImplicit = true;
        $this->_stringTest('success');
        $this->_notImplicit = false;
    }

    /**
     * Tests notice (no implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testNoticeStringNoImplicitFlushHtml()
    {
        $this->_notImplicit = true;
        $this->_stringTest('notice');
        $this->_notImplicit = false;
    }

    /**
     * Tests warning (no implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testWarningStringNoImplicitFlushHtml()
    {
        $this->_notImplicit = true;
        $this->_stringTest('warning');
        $this->_notImplicit = false;
    }

    /**
     * Tests error array of messages (no implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testErrorArrayNoImplicitFlushHtml()
    {
        $this->_notImplicit = true;
        $this->_arrayTest('error');
        $this->_notImplicit = false;
    }

    /**
     * Tests success array of messages (no implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testSuccessArrayNoImplicitFlushHtml()
    {
        $this->_notImplicit = true;
        $this->_arrayTest('success');
        $this->_notImplicit = false;
    }

    /**
     * Tests notice array of messages (no implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testNoticeArrayNoImplicitFlushHtml()
    {
        $this->_notImplicit = true;
        $this->_arrayTest('notice');
        $this->_notImplicit = false;
    }

    /**
     * Tests warning array of messages (no implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testWarningArrayNoImplicitFlushHtml()
    {
        $this->_notImplicit = true;
        $this->_arrayTest('warning');
        $this->_notImplicit = false;
    }

    /**
     * Tests error (implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testErrorStringImplicitFlushNoHtml()
    {
        $this->_notHtml = true;
        $this->_stringTest('error');
        $this->_notHtml = false;
    }

    /**
     * Tests success (implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testSuccessStringImplicitFlushNoHtml()
    {
        $this->_notHtml = true;
        $this->_stringTest('success');
        $this->_notHtml = false;
    }

    /**
     * Tests notice (implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testNoticeStringImplicitFlushNoHtml()
    {
        $this->_notHtml = true;
        $this->_stringTest('notice');
        $this->_notHtml = false;
    }

    /**
     * Tests warning (implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testWarningStringImplicitFlushNoHtml()
    {
        $this->_notHtml = true;
        $this->_stringTest('warning');
        $this->_notHtml = false;
    }

    /**
     * Tests error array of messages (implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testErrorArrayImplicitFlushNoHtml()
    {
        $this->_notHtml = true;
        $this->_arrayTest('error');
        $this->_notHtml = false;
    }

    /**
     * Tests success array of messages (implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testSuccessArrayImplicitFlushNoHtml()
    {
        $this->_notHtml = true;
        $this->_arrayTest('success');
        $this->_notHtml = false;
    }

    /**
     * Tests notice array of messages (implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testNoticeArrayImplicitFlushNoHtml()
    {
        $this->_notHtml = true;
        $this->_arrayTest('notice');
        $this->_notHtml = false;
    }

    /**
     * Tests warning array of messages (implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testWarningArrayImplicitFlushNoHtml()
    {
        $this->_notHtml = true;
        $this->_arrayTest('warning');
        $this->_notHtml = false;
    }

    /**
     * Tests error (no implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testErrorStringNoImplicitFlushNoHtml()
    {
        $this->_notHtml     = true;
        $this->_notImplicit = true;
        $this->_stringTest('error');
        $this->_notHtml     = false;
        $this->_notImplicit = false;
    }

    /**
     * Tests success (no implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testSuccessStringNoImplicitFlushNoHtml()
    {
        $this->_notHtml     = true;
        $this->_notImplicit = true;
        $this->_stringTest('success');
        $this->_notHtml     = false;
        $this->_notImplicit = false;
    }

    /**
     * Tests notice (no implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testNoticeStringNoImplicitFlushNoHtml()
    {
        $this->_notHtml     = true;
        $this->_notImplicit = true;
        $this->_stringTest('notice');
        $this->_notHtml     = false;
        $this->_notImplicit = false;
    }

    /**
     * Tests warning (no implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testWarningStringNoImplicitFlushNoHtml()
    {
        $this->_notHtml     = true;
        $this->_notImplicit = true;
        $this->_stringTest('warning');
        $this->_notHtml     = false;
        $this->_notImplicit = false;
    }

    /**
     * Tests error array of messages (no implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testErrorArrayNoImplicitFlushNoHtml()
    {
        $this->_notHtml     = true;
        $this->_notImplicit = true;
        $this->_arrayTest('error');
        $this->_notHtml     = false;
        $this->_notImplicit = false;
    }

    /**
     * Tests success array of messages (no implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testSuccessArrayNoImplicitFlushNoHtml()
    {
        $this->_notHtml     = true;
        $this->_notImplicit = true;
        $this->_arrayTest('success');
        $this->_notHtml     = false;
        $this->_notImplicit = false;
    }

    /**
     * Tests notice array of messages (no implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testNoticeArrayNoImplicitFlushNoHtml()
    {
        $this->_notHtml     = true;
        $this->_notImplicit = true;
        $this->_arrayTest('notice');
        $this->_notHtml     = false;
        $this->_notImplicit = false;
    }

    /**
     * Tests warning array of messages (no implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testWarningArrayNoImplicitFlushNoHtml()
    {
        $this->_notHtml     = true;
        $this->_notImplicit = true;
        $this->_arrayTest('warning');
        $this->_notHtml     = false;
        $this->_notImplicit = false;
    }

    /**
     * Private function to get the class of the message depending on
     * the classes set
     *
     * @param $key
     *
     * @return string
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    private function _getClass($key)
    {
        $template = ' class="%s"';

        if ($this->_classes === array())
        {
            $class = '';
        }
        else
        {
            $classes = (is_null($this->_classes)) ?
                        $this->_default           :
                        $this->_classes;
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
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    private function _getObResponse($flash, $function, $message)
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
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    private function _stringTest($function)
    {
        $flash    = new Flash($this->_classes);
        $class    = $this->_getClass($function);
        $implicit = '';
        $html     = '';
        $template = '<div%s>%s</div>' . PHP_EOL;
        $message  = 'sample message';

        if ($this->_notHtml)
        {
            $flash->setAutomaticHtml(false);
            $html     = ' no HTML';
            $expected = $message;
        }
        else
        {
            $expected = sprintf($template, $class, $message);
        }


        if ($this->_notImplicit)
        {
            $flash->setImplicitFlush(false);
            $implicit = ' no implicit';
            $actual   = $flash->$function($message);
        }
        else
        {
            $actual = $this->_getObResponse($flash, $function, $message);
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
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    private function _arrayTest($function)
    {
        $flash    = new Flash($this->_classes);
        $class    = $this->_getClass($function);
        $implicit = '';
        $html     = '';
        $template = '<div%s>%s</div>' . PHP_EOL;
        $message  = array(
            'sample message 1',
            'sample message 2',
        );

        if ($this->_notHtml)
        {
            $flash->setAutomaticHtml(false);
            $html = ' no HTML';
            $expected = $message[0]
                      . $message[1];
        }
        else
        {
            $expected = sprintf($template, $class, $message[0])
                      . sprintf($template, $class, $message[1]);
        }

        if ($this->_notImplicit)
        {
            $flash->setImplicitFlush(false);
            $implicit = ' no implicit';
            $actual   = $flash->$function($message);
        }
        else
        {
            $actual = $this->_getObResponse($flash, $function, $message);
        }

        $this->assertEquals(
            $expected,
            $actual,
            "Flash\\Direct {$function} (array){$implicit}{$html} does not produce the correct message"
        );
    }
}
