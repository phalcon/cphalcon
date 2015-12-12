<?php
/**
 * TextHumanizeTest.php
 * \Phalcon\Text\TextHumanizeTest
 *
 * Tests the Phalcon\Text component
 *
 * Phalcon Framework
 *
 * @copyright (c) 2011-2015 Phalcon Team
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

namespace Phalcon\Tests\unit\Phalcon\Text;

use \PhalconTest\Text as PhTText;

class TextHumanizeTest extends Helper\TextBase
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
                expect(PhTText::humanize('start_a_horse'))->equals('start a horse');
                expect(PhTText::humanize("five-cats"))->equals('five cats');
                expect(PhTText::humanize('kittens-are_cats'))->equals('kittens are cats');
                expect(PhTText::humanize(" \t Awesome-Phalcon \t "))->equals('Awesome Phalcon');
            }
        );
    }
}
