<?php

namespace Phalcon\Test\Unit\Text;

use Phalcon\Text;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Text\TextHumanizeTest
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
class TextHumanizeTest extends UnitTest
{
    /**
     * Tests the humanize function
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2015-11-09
     */
    public function testUnderscore()
    {
        $this->specify(
            "humanize do not an underscored or dashed phrase human-readable",
            function () {
                expect(Text::humanize('start_a_horse'))->equals('start a horse');
                expect(Text::humanize("five-cats"))->equals('five cats');
                expect(Text::humanize('kittens-are_cats'))->equals('kittens are cats');
                expect(Text::humanize(" \t Awesome-Phalcon \t "))->equals('Awesome Phalcon');
            }
        );
    }
}
