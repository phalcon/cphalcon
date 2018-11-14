<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Tag\Helper;

use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Tag;
use UnitTester;

class TagBase
{
    use DiTrait;

    public function _before(UnitTester $I)
    {
        $this->resetDi();
        $this->newDi();
        $this->setDiEscaper();
        $this->setDiUrl();
    }

    /**
     * Runs the test for a Tag::$function with $options
     *
     * @param \UnitTester $I
     * @param string      $function
     * @param mixed       $options
     * @param string      $expected
     * @param boolean     $xhtml
     * @param string      $set
     */
    protected function testFieldParameter(UnitTester $I, $function, $options, $expected, $xhtml, $set = '')
    {
        Tag::resetInput();

        if ($xhtml) {
            Tag::setDocType(Tag::XHTML10_STRICT);
            $expected .= ' />';
        } else {
            Tag::setDocType(Tag::HTML5);
            $expected .= '>';
        }

        if ($set) {
            Tag::displayTo('x_name', 'x_value');
        }

        $actual = Tag::$function($options);

        if ($set) {
            Tag::$set('x_name', '');
        }

        $I->assertEquals($expected, $actual);
    }
}
