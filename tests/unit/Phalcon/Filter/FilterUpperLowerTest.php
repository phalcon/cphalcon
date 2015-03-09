<?php
/**
 * FilterUpperLowerTest.php
 * \Phalcon\Text\FilterUpperLowerTest
 *
 * Tests the Phalcon\Filter component
 *
 * Phalcon Framework
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

namespace Phalcon\Tests\unit\Phalcon\Filter;

class FilterUpperLowerTest extends Helper\FilterBase
{
    /**
     * Tests lower all
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeLowerAll()
    {
        $this->specify(
            "lower all is not correct",
            function () {
                $expected = 'hello';
                $value    = 'HELLO';
                $this->sanitizer('lower', $expected, $value);
            }
        );
    }

    /**
     * Tests lower mixed
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeLowerMixed()
    {
        $this->specify(
            "lower mixed is not correct",
            function () {
                $expected = 'hello';
                $value    = 'HeLlo';
                $this->sanitizer('lower', $expected, $value);
            }
        );
    }

    /**
     * Tests upper all
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeUpperAll()
    {
        $this->specify(
            "upper all is not correct",
            function () {
                $expected = 'HELLO';
                $value    = 'hello';
                $this->sanitizer('upper', $expected, $value);
            }
        );
    }

    /**
     * Tests upper mixed
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeUpperMixed()
    {
        $this->specify(
            "upper mixed is not correct",
            function () {
                $expected = 'HELLO';
                $value    = 'HeLlo';
                $this->sanitizer('upper', $expected, $value);
            }
        );
    }
}
