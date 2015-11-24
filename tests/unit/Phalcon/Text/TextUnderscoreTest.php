<?php
/**
 * TextUnderscoreTest.php
 * \Phalcon\Text\TextUnderscoreTest
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

class TextUnderscoreTest extends Helper\TextBase
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
                expect(PhTText::underscore('start a horse'))->equals('start_a_horse');
                expect(PhTText::underscore("five\tcats"))->equals('five_cats');
                expect(PhTText::underscore(' look behind '))->equals('look_behind');
                expect(PhTText::underscore(" \t Awesome \t  \t Phalcon "))->equals('Awesome_Phalcon');
            }
        );
    }
}
