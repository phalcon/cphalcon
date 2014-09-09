<?php
/**
 * TagBase.php
 * \Phalcon\Tag
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

namespace Phalcon\Tests\unit\Phalcon\Tag;

use \Phalcon\DI\FactoryDefault as PhDI;
use \Phalcon\Tag as PhTag;

class TagBase
{
    protected $message = "%s does not return proper html element";

    /**
     * Sets the necessary components for tests to run
     */
    public function _before()
    {
        $di = new PhDI();
        PhDI::reset();
        PhTag::setDI($di);
    }

    /**
     * Runs tests with string as a parameter for XHTML or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param string   $function
     * @param \CodeGuy $I
     * @param string   $options
     * @param string   $expected
     * @param boolean  $xhtml
     */
    protected function runBasic($function, \CodeGuy $I, $options, $expected, $xhtml)
    {
        if ($xhtml) {
            PhTag::setDocType(PhTag::XHTML10_STRICT);
        } else {
            PhTag::setDocType(PhTag::HTML5);
        }

        $suffix   = ($xhtml) ? ' />'    : '>';
        $message  = ($xhtml) ? ' XHTML' : '';
        $message  = $function . 'basic' . $message;

        $expected .= $suffix;
        $actual    = PhTag::$function($options);

        $this->runAssertion($function, $I, $expected, $actual, $message);
    }

    /**
     * Runs tests with array as parameters for XHTML or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param string   $function
     * @param \CodeGuy $I
     * @param string   $options
     * @param string   $expected
     * @param boolean  $xhtml
     */
    protected function runWithArrayBasic($function, \CodeGuy $I, $options, $expected, $xhtml)
    {
        if ($xhtml) {
            PhTag::setDoctype(PhTag::XHTML10_STRICT);
        } else {
            PhTag::setDocType(PhTag::HTML5);
        }

        $suffix  = ($xhtml) ? ' />'    : ">";
        $message = ($xhtml) ? ' XHTML' : '';
        $message = $function . ' with array basic' . $message;

        $expected .= $suffix;
        $actual    = PhTag::$function($options);

        $this->runAssertion($function, $I, $expected, $actual, $message);
    }

    /**
     * Runs tests with id in parameters for XHTML or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param string   $function
     * @param \CodeGuy $I
     * @param string   $options
     * @param string   $expected
     * @param boolean  $xhtml
     */
    protected function runWithIdInParameters($function, \CodeGuy $I, $options, $expected, $xhtml)
    {
        if ($xhtml) {
            PhTag::setDoctype(PhTag::XHTML10_STRICT);
        } else {
            PhTag::setDocType(PhTag::HTML5);
        }

        $suffix  = ($xhtml) ? ' />'    : ">";
        $message = ($xhtml) ? ' XHTML' : '';
        $message = $function . ' with id in parameters' . $message;

        $expected .= $suffix;
        $actual    = PhTag::$function($options);

        $this->runAssertion($function, $I, $expected, $actual, $message);
    }

    /**
     * Runs tests with name and no id in parameters for XHTML or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param string   $function
     * @param \CodeGuy $I
     * @param string   $options
     * @param string   $expected
     * @param boolean  $xhtml
     */
    protected function runWithNameAndNotIdInParameters($function, \CodeGuy $I, $options, $expected, $xhtml)
    {
        if ($xhtml) {
            PhTag::setDocType(PhTag::XHTML10_STRICT);
        } else {
            PhTag::setDocType(PhTag::HTML5);
        }

        $suffix  = ($xhtml) ? ' />'    : '>';
        $message = ($xhtml) ? ' XHTML' : '';
        $message = $function . ' with name and not id in parameters' . $message;

        $expected .= $suffix;
        $actual    = PhTag::$function($options);

        $this->runAssertion($function, $I, $expected, $actual, $message);
    }

    /**
     * Runs tests with setDefault for XHTML or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param string   $function
     * @param \CodeGuy $I
     * @param string   $options
     * @param string   $expected
     * @param boolean  $xhtml
     */
    protected function runSetDefault($function, \CodeGuy $I, $options, $expected, $xhtml)
    {
        if ($xhtml) {
            PhTag::setDocType(PhTag::XHTML10_STRICT);
        } else {
            PhTag::setDocType(PhTag::HTML5);
        }

        $suffix  = ($xhtml) ? ' />'    : '>';
        $message = ($xhtml) ? ' XHTML' : '';
        $message = $function . ' with setDefault' . $message;

        $expected .= $suffix;
        PhTag::setDefault('some_field_name', 'some_default_value');
        $actual    = PhTag::$function($options);
        PhTag::setDefault('some_field_name', '');

        $this->runAssertion($function, $I, $expected, $actual, $message);
    }

    /**
     * Runs tests with displayTo for XHTML or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param string   $function
     * @param \CodeGuy $I
     * @param string   $options
     * @param string   $expected
     * @param boolean  $xhtml
     */
    protected function runDisplayTo($function, \CodeGuy $I, $options, $expected, $xhtml)
    {
        if ($xhtml) {
            PhTag::setDocType(PhTag::XHTML10_STRICT);
        } else {
            PhTag::setDocType(PhTag::HTML5);
        }

        $suffix  = ($xhtml) ? ' />'    : '>';
        $message = ($xhtml) ? ' XHTML' : '';
        $message = $function . ' with displayTo' . $message;

        $expected .= $suffix;
        PhTag::displayTo('some_field_name', 'some_default_value');
        $actual    = PhTag::$function($options);
        PhTag::displayTo('some_field_name', '');

        $this->runAssertion($function, $I, $expected, $actual, $message);
    }

    /**
     * Runs the assertEqual assertion
     *
     * @param string   $function
     * @param \CodeGuy $I
     * @param mixed    $expected
     * @param mixed    $actual
     * @param string   $message
     */
    private function runAssertion($function, \CodeGuy $I, $expected, $actual, $message)
    {
        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, $function .' ' . $message)
        );
    }
}
