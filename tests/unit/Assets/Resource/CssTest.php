<?php

namespace Phalcon\Test\Unit\Assets\Resource;

use Phalcon\Assets\Resource\Css;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Assets\Resource\CssTest
 * Tests the \Phalcon\Assets\Resource\Css component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Asset
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class CssTest extends UnitTest
{
    /**
     * Tests Css getType
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-10
     */
    public function testAssetsResourceCssGetType()
    {
        $this->specify(
            "The resource Css getType is not correct",
            function () {
                $resource = new Css('/css/style.css', false);
                $expected = 'css';
                $actual   = $resource->getType();

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests Css getPath
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-10
     */
    public function testAssetsResourceCssGetPath()
    {
        $this->specify(
            "The resource Css getPath is not correct",
            function () {
                $resource = new Css('/css/style.css', false);
                $expected = '/css/style.css';
                $actual   = $resource->getPath();

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests Css getLocal
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-10
     */
    public function testAssetsResourceCssGetLocal()
    {
        $this->specify(
            "The resource Css getLocal is not correct",
            function () {
                $resource = new Css('/css/style.css', false);
                $actual   = $resource->getLocal();

                expect($actual)->false();
            }
        );
    }
}
