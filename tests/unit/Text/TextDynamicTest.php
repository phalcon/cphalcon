<?php

namespace Phalcon\Test\Unit\Text;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Test\Proxy\Text;

/**
 * \Phalcon\Test\Unit\Text\TextDynamicTest
 * Tests the \Phalcon\Text component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class TextDynamicTest extends UnitTest
{
    /**
     * Tests the dynamic function
     *
     * @author Stanislav Kiryukhin <korsar.zn@gmail.com>
     * @since  2015-07-01
     */
    public function testTextDynamicString()
    {
        $this->specify(
            "dynamic do not return the correct string",
            function () {

                $actual = Text::dynamic('{Hi|Hello}, my name is a Bob!');
                expect($actual)->notContains('{');
                expect($actual)->notContains('}');

                expect(preg_match('/^(Hi|Hello), my name is a Bob!$/', $actual))->equals(1);
            }
        );
    }

    /**
     * Tests the dynamic function
     *
     * @author Stanislav Kiryukhin <korsar.zn@gmail.com>
     * @since  2015-07-01
     */
    public function testTextDynamicStringCustomDelimeter()
    {
        $actual = Text::dynamic('(Hi|Hello), my name is a Bob!', '(', ')');
        expect($actual)->notContains('(');
        expect($actual)->notContains(')');

        expect(preg_match('/^(Hi|Hello), my name is a Bob!$/', $actual))->equals(1);
    }
}
