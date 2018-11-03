<?php

namespace Phalcon\Test\Unit\Text;

use Phalcon\Text;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Text\TextDynamicTest
 * Tests the \Phalcon\Text component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
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
    public function testTextDynamicStringCustomDelimiter()
    {
        $actual = Text::dynamic('(Hi|Hello), my name is a Bob!', '(', ')');
        expect($actual)->notContains('(');
        expect($actual)->notContains(')');

        expect(preg_match('/^(Hi|Hello), my name is a Bob!$/', $actual))->equals(1);
    }

    /**
     * Tests custom separator
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/11215
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-06-27
     */
    public function testTextDynamicStringCustomSeparator()
    {
        $this->specify(
            'Text::dynamic with custom separator does not return expected result',
            function () {
                $actual = Text::dynamic('{Hi=Hello}, my name is a Bob!', '{', '}', '=');

                expect($actual)->notContains('{');
                expect($actual)->notContains('}');
                expect($actual)->notContains('=');

                expect(preg_match('/^(Hi|Hello), my name is a Bob!$/', $actual))->equals(1);

                $actual = Text::dynamic("{Hi'Hello}, my name is a {Rob'Zyxep'Andres}!", '{', '}', "'");

                expect($actual)->notContains('{');
                expect($actual)->notContains('}');
                expect($actual)->notContains("'");

                expect(preg_match('/^(Hi|Hello), my name is a (Rob|Zyxep|Andres)!$/', $actual))->equals(1);

                $actual = Text::dynamic('{Hi/Hello}, my name is a {Stanislav/Nikos}!', '{', '}', '/');

                expect($actual)->notContains('{');
                expect($actual)->notContains('}');
                expect($actual)->notContains('/');

                expect(preg_match('/^(Hi|Hello), my name is a (Stanislav|Nikos)!$/', $actual))->equals(1);
            }
        );
    }
}
