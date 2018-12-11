<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Traits;

use Phalcon\Html\Tag;
use UnitTester;

/**
 * Trait TagSetupTrait
 *
 * @package Phalcon\Test\Fixtures\Traits
 */
trait TagSetupTrait
{
    /**
     * Constructor
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-10-26
     */
    public function _before(UnitTester $I)
    {
        $this->newDi();
        $this->setDiEscaper();
        $this->setDiUrl();
    }

    /**
     * @inheritdoc
     */
    abstract protected function newDi();

    /**
     * @inheritdoc
     */
    abstract protected function setDiEscaper();

    /**
     * @inheritdoc
     */
    abstract protected function setDiUrl();

    /**
     * Runs the test for a Tag::$function with $options
     *
     * @param UnitTester $I
     * @param Tag        $tag
     * @param string     $name
     * @param string     $function
     * @param            $options
     * @param string     $expected
     * @param bool       $xhtml
     * @param string     $set
     */
    protected function testFieldParameter(
        UnitTester $I,
        Tag $tag,
        string $name,
        string $function,
        $options,
        string $expected,
        bool $xhtml = false,
        string $set = ''
    ) {
        if ($xhtml && 'textArea' !== $function) {
            $tag->setDocType(Tag::XHTML10_STRICT);
            $expected .= ' />';
        } else {
            $tag->setDocType(Tag::HTML5);
            $expected .= '>';
        }

        if ($set) {
            $tag->{$set}('x_name', 'x_value');
        }

        $actual = $tag->$function($name, $options);
        $I->assertEquals($expected, $actual);
    }
}
