<?php
/**
 * TagImageCest.php
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

use \CodeGuy;
use \Phalcon\Tag as PhTag;

class TagImageCest extends TagBase
{
    /**
     * Tests an image tag with a bare minimum of information passed
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testImageBasic(CodeGuy $I)
    {
        $this->imageBasic($I, false);
    }

    /**
     * Tests an image tag with a bare minimum of information passed XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testImageBasicXHTML(CodeGuy $I)
    {
        $this->imageBasic($I, true);
    }

    /**
     * Tests an image tag with an array passed as parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testImageWithArrayBasic(CodeGuy $I)
    {
        $this->imageWithArrayBasic($I, false);
    }

    /**
     * Tests an image tag with an array passed as parameters XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testImageWithArrayBasicXHTML(CodeGuy $I)
    {
        $this->imageWithArrayBasic($I, true);
    }

    /**
     * Tests an image tag with the src attribute passed in as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testImageWithSrcInParameters(CodeGuy $I)
    {
        $this->imageWithSrcInParameters($I, false);
    }

    /**
     * Tests an image tag with the src attribute passed in as a parameter XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testImageWithSrcInParametersXHTML(CodeGuy $I)
    {
        $this->imageWithSrcInParameters($I, true);
    }

    /**
     * PRIVATE METHODS
     */
    /**
     * Runs tests with a bare minimum of information passed for XHTML or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     * @param Boolean $xhtml
     */
    private function imageBasic(CodeGuy $I, $xhtml)
    {
        $options  = 'img/hello.gif';
        $expected = '<img src="/img/hello.gif"';

        $this->runBasic('image', $I, $options, $expected, $xhtml);
    }

    /**
     * Runs tests with an array passed as parameters for XHTML or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     * @param Boolean $xhtml
     */
    private function imageWithArrayBasic(CodeGuy $I, $xhtml)
    {
        $options  = array(
            'img/hello.gif',
            'class' => 'some_class',
        );
        $expected = '<img src="/img/hello.gif" class="some_class"';

        $this->runWithArrayBasic('image', $I, $options, $expected, $xhtml);
    }

    /**
     * Runs tests with the src attribute passed in as a parameter for XHTML or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     * @param Boolean $xhtml
     */
    private function imageWithSrcInParameters(CodeGuy $I, $xhtml)
    {
        $options  = array(
            'img/hello.gif',
            'src'   => 'img/goodbye.gif',
            'class' => 'some_class',
        );
        $expected = '<img src="/img/goodbye.gif" class="some_class"';

        $this->runWithIdInParameters('image', $I, $options, $expected, $xhtml);
    }
}
