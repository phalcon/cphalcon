<?php

namespace Phalcon\Test\Unit\Text;

use Phalcon\Text;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Text\TextUpperLowerTest
 * Tests the \Phalcon\Text component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http:s//phalconphp.com
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
class TextUnderscoreTest extends UnitTest
{
    /**
     * Tests the uderscore function
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2015-11-09
     */
    public function testUnderscore()
    {
        $this->specify(
            "underscore do not replace spaces",
            function () {
                expect(Text::underscore('start a horse'))->equals('start_a_horse');
                expect(Text::underscore("five\tcats"))->equals('five_cats');
                expect(Text::underscore(' look behind '))->equals('look_behind');
                expect(Text::underscore(" \t Awesome \t  \t Phalcon "))->equals('Awesome_Phalcon');
            }
        );
    }
}
